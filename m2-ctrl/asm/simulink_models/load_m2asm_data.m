%
% load_m2asm_data.m
%
% Load variables to compile M2ASM controller
% 
% Fev, 2023: Segment-wise implementation

% Flag to save/update test data file
update_test_dt = true; %false;
% Flag to save/update controller data file
update_calib_dt = true; %false;
% Controller sampling period
Ts = 1/8e3;

% 2nd-order underdamped function
sndUDampF = @(fc,damp) zpk([],...
    [-fc*2*pi*(damp + 1i*sqrt(1-damp^2)),...
    -fc*2*pi*(damp - 1i*sqrt(1-damp^2))], (fc*2*pi)^2);


%% Load structural model
%%
% The structural model is required to compute:
% - The ASM stiffness matrix

% ModelFolder = fullfile(im.lfFolder,"20210611_1336_MT_mount_v202104_ASM_full_epsilon");
ModelFolder = fullfile(im.lfFolder,"20230131_1605_zen_30_M1_202110_ASM_202208_Mount_202111");

FileName = "modal_state_space_model_2ndOrder.mat";
% FileName = "modal_state_space_model_2ndOrder_300Hz.mat";
    load(fullfile(ModelFolder,FileName),'inputs2ModalF','modalDisp2Outputs',...
        'eigenfrequencies','proportionalDampingVec','inputTable','outputTable');

fprintf('Loading model file %s\n from folder \n%s\n', FileName, ModelFolder);

StatFName = "static_reduction_model.mat";
if(exist(fullfile(ModelFolder,StatFName),'file'))
    try
        load(fullfile(ModelFolder,StatFName),'gainMatrixMountControlled');
        gainMatrix = gainMatrixMountControlled;
    catch
        load(fullfile(ModelFolder,StatFName),'gainMatrix');
    end
    no_static_gain = 0;
else
    warning('No static model file is available in the specified folder.');
    no_static_gain = 1;
end

%% Load variable (st) with the ASM controller parameters
%%

% File with controller and interface parameters
fprintf('Loading the controller TFs using getcontrol_asm()\n');
asm_script_folder = '/Users/rromano/Workspace/GMT-IMS/controllers';
addpath(asm_script_folder)
st = getcontrol_asm();
rmpath(asm_script_folder)


%% ASM inner loop controller preshape filter
%%
if(1)
    % Discretization settings
    c2d_opts = c2dOptions('Method','foh');

    % Set to 1 to use original pre shape filter (fc=2200Hz)
    if(true)
        fpre = st.asm.fpre;
    else
        fpre_bw = 2200; % [Hz] prefilter break frequency
        dd = [1.00000000 3.12393994 4.39155033 3.20108587 1.00000000]; % for wc=1
        dd = dd.*(2*pi*fpre_bw).^(0:4); % for wc=2*pi*fpre_bw
        nn = [0 0 0 0 dd(end)]; % for unity dc gain
        fpre = tf(nn,dd);
    end
    % FF contributions
    [a,b,c]=ssdata(fpre);
    flag=ss(a,b,[c;c*a;c*(a^2)],[0;c*b;c*a*b]); % [1;s;s^2]*fpre
    % Discrete-time FF controller TFs - 4th-order Bessel approx
    flag_d = c2d(flag,Ts,c2d_opts);
else
    % ASM Shaping filter - AdOptica' implementation
    sm.tSF = 1/2200; %#ok<*UNRCH>
    sm.d1SF = 60/sm.tSF^3;
    sm.d2SF = -180/sm.tSF^4;
    sm.d3SF = 120/sm.tSF^5;
    sm.TCmd = st.ngao.T;
end


%% ASM inner loop feedbaack (PI+D) controller TFs
%%

% ASM inner loop controller discretization method
c2d_opts = c2dOptions('Method','foh');

% PI compensator
Cpi_d = c2d(st.asm.fpi,Ts,c2d_opts);
% Numerical differentiation
Hpd_d = c2d(st.asm.fpd,Ts,c2d_opts);


%% ASM feedforward (FF) modal controller parameters
%%
% Loop over the segments to:
% 1) Create modal transformation matrix
XiFS = cell(7,1);
% 2) Compute ASM modal stiffness matrices
VC_modal_stiff = cell(7,1);

for iseg = 1:7
    in_label = sprintf('MC_M2_S%d_VC_delta_F',iseg);
    % Take coordinates of the ASM FS nodes
    % (not necessarily the same in all segments)
    nDim = inputTable(in_label,1).size;
    xFS = zeros(nDim,1); yFS = zeros(nDim,1);
    
    for ii = 1:nDim
        props = inputTable(in_label,:).properties{1}{ii};
        xFS(ii) = props.location(2,1); yFS(ii) = props.location(2,2);
    end
    
    % Check for location differences between segments
    node_tol = 1e-3;    % Tolerance to accommodate mesh inaccuracies
    if(iseg>1 && (any( abs(xyFS_ - complex(xFS,yFS)) > node_tol )))
        fprintf('FS node coordinates of S%d and S%d are different!\n',iseg,iseg-1);
    end
    
    
    % Modal transformation matrix
    pmax = 10;  % 66 modes
    [XiFS{iseg},~,~,n_Zmodes] = utils.zernike(complex(xFS,yFS),pmax);
    if iseg==1, fprintf('Number of vector basis vectors:%d \n',n_Zmodes);
    end
    
    % VC IO indexes
    in_ = inputTable{sprintf('MC_M2_S%d_VC_delta_F',iseg),"indices"}{1}(:);
    out_ = outputTable{sprintf('MC_M2_S%d_VC_delta_D',iseg),"indices"}{1}(:);
    
    % Compute the VC modal stiffness matrix    
    if(no_static_gain)
        DCg = XiFS{iseg}' * modalDisp2Outputs(out_,4:end) *...
            diag(1./((2*pi*eigenfrequencies(4:end)).^2)) *...
            inputs2ModalF(4:end,in_) * XiFS{iseg};
    else
        DCg = XiFS{iseg}' * gainMatrix(out_,in_) * XiFS{iseg};
    end
    VC_modal_stiff{iseg} = eye(n_Zmodes) / DCg;
    
    % Save coordinates to check for differences between segments
    xyFS_ = complex(xFS,yFS);
end

% Update Ks with ASM modal stiffness
Ks = VC_modal_stiff;


%% M2 Positioner parameters
%%

% M2 pos act force inputs indices
in1 = inputTable{'MC_M2_SmHex_F',"indices"}{1}(1:2:end);	%macrocell side
in2 = inputTable{'MC_M2_SmHex_F',"indices"}{1}(2:2:end);	%mirror segment side
% M2 POS displacement indices
out1 = outputTable{'MC_M2_SmHex_D',"indices"}{1}(1:2:end);	%macrocell side
out2 = outputTable{'MC_M2_SmHex_D',"indices"}{1}(2:2:end);	%mirror seg side
% M2 RB output indices
out3 = outputTable{'MC_M2_RB_6D',"indices"}{1};             %M2 RB RBM (local CS)

if(no_static_gain)    
    % Static gain from MC_M2_SmHex_F to M2_RB_RBM
    dcG1 = -modalDisp2Outputs(out3,4:end) *...
        diag(1./((2*pi*eigenfrequencies(4:end)).^2))*...
        (inputs2ModalF(4:end,in1)-inputs2ModalF(4:end,in2));
    % Static gain from MC_M2_SmHex_F to MC_M2_SmHex_D
    dcG2 = -...
        (modalDisp2Outputs(out1,4:end)-modalDisp2Outputs(out2,4:end))*...
        diag(1./((2*pi*eigenfrequencies(4:end)).^2))*...
        (inputs2ModalF(4:end,in1)-inputs2ModalF(4:end,in2));
else
    dcG1 = gainMatrix(out3,in1)-gainMatrix(out3,in2);
    dcG2 = gainMatrix(out1,in1)-gainMatrix(out1,in2)...
        -gainMatrix(out2,in1)+gainMatrix(out2,in2);
end

% M2 POS decoupling matrix M2_RB_RBM -> MC_M2_SmHex_D
Km2p_dec = dcG1\dcG2;

% Check eventual coupling
if(1)   % Some coupling checks
    figure(444)
    imagesc(Km2p_dec)
    ylabel('MC\_M2\_SmHex\_D'); xlabel('M2\_RBM');
    colorbar
end

% M2P Controller output to f=differential force transformation
to_diff_m2p_F = kron(eye(6),[1;-1]);

% Nominal M2P striffness
k2p_stiff0 = 122e6;
% M2P ACT striffnesses
k2p_stiff_vec = 1./diag(dcG2);
k2p_stiff = mean(k2p_stiff_vec);
if(any(std(k2p_stiff_vec)./k2p_stiff_vec > 1e-3))
    warning('The M2P ACT stiffness variability is unusually high!');
end

if(abs(k2p_stiff-k2p_stiff0)/k2p_stiff0 > 0.01)
    warning('Avg M2P stiffness unusually different from the nominal value.');
    fprintf('* Updating M2P stiffness value: \n%.4g(N/m) -> %.4g(N/m) *\n',...
        k2p_stiff0,k2p_stiff);
else
    k2p_stiff = k2p_stiff0;
end

%%
% M2POS feedback controller: I + Roll-off filter
fc = 2;     %[Hz] Crossover frequency

kc = 2*pi * fc *k2p_stiff;
% Remark: controller gain not incorporated to the TF
fbH = tf(1,[1 0]) * sndUDampF(10,0.5);
m2p_Cfb_d = c2d(tf(fbH), Ts, 'foh');


%% Load simulink model
%%
ModelFName = 'm2asm_2_rust';
open(sprintf('%s.slx',ModelFName));
deltaT = Ts;    % Fixed-step solver sampling period


%% Calibration-dependent matrices
%%

% M2P decoupling matrix for each segment
Km2pS1_dec = Km2p_dec(1:6,1:6);
Km2pS2_dec = Km2p_dec((1:6)+6,(1:6)+6);
Km2pS3_dec = Km2p_dec((1:6)+12,(1:6)+12);
Km2pS4_dec = Km2p_dec((1:6)+18,(1:6)+18);
Km2pS5_dec = Km2p_dec((1:6)+24,(1:6)+24);
Km2pS6_dec = Km2p_dec((1:6)+30,(1:6)+30);
Km2pS7_dec = Km2p_dec((1:6)+36,(1:6)+36);

% Zernike modal shape matrices
V_S1 = XiFS{1}; V_S2 = XiFS{2}; V_S3 = XiFS{3}; V_S4 = XiFS{4};
V_S5 = XiFS{5}; V_S6 = XiFS{6}; V_S7 = XiFS{7};
% Static feedforward term
KsS1_66 = Ks{1}; KsS2_66 = Ks{2}; KsS3_66 = Ks{3};
KsS4_66 = Ks{4}; KsS5_66 = Ks{5}; KsS6_66 = Ks{6}; KsS7_66 = Ks{7};
% Dynamic feedforward terms
Km = st.asm.Km; Kb = st.asm.Kb;
% File with calibration matrices
if(update_calib_dt)
    save('../calib_dt/m2asm_ctrl_dt.mat', 'Km', 'Kb',...
        'KsS1_66', 'KsS2_66', 'KsS3_66', 'KsS4_66',...
        'KsS5_66', 'KsS6_66', 'KsS7_66',...
        'V_S1','V_S2','V_S3','V_S4','V_S5','V_S6','V_S7',...
        'Km2pS1_dec','Km2pS2_dec','Km2pS3_dec','Km2pS4_dec',...
        'Km2pS5_dec','Km2pS6_dec','Km2pS7_dec', 'k2p_stiff');
end

%% Test/verification step data
%%
% Columns of preshapeBessel_step_y: [cmd_f, dot_cmd_f, ddot_cmd_f]
[preshapeBessel_step_y,preshapeBessel_step_t] = step(flag_d);
G_fb_fd = [-Cpi_d-st.asm.Kd*Hpd_d;-st.asm.Kfd*Hpd_d];
% Columns of asm_fb_imp_y:
[asm_fb_imp_y, asm_fb_imp_t] = impulse(G_fb_fd);
% M2POS FB controller impulse test data
[m2pact_fb_imp_y, m2pact_fb_imp_t] = impulse(kc*m2p_Cfb_d);
if (update_test_dt && ~exist('m2asm_tests','var'))
    save('m2asm_tests','preshapeBessel_step_y','preshapeBessel_step_t',...
        'asm_fb_imp_y','asm_fb_imp_t',...
        'm2pact_fb_imp_y','m2pact_fb_imp_t');
end


%[eof]
