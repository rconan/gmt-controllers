%
% load_m2fsm_data.m
%
% Load variables to compile M2FSM controller
% 
% Feb, 2025: Resuming FSM-based model for NS e2e simulations

% Flag to save/update test data file
update_test_dt = true; %false; %
% Flag to save/update controller data file
update_calib_dt = false; %true; %
% Flag to compile M2-FSM model codes at the end of data loading process
auto_compile = false;

% Controller sampling period
Ts = 1/1e3;

% 2nd-order underdamped function
sndUDampF = @(fc,damp) zpk([],...
    [-fc*2*pi*(damp + 1i*sqrt(1-damp^2)),...
    -fc*2*pi*(damp - 1i*sqrt(1-damp^2))], (fc*2*pi)^2);


%% FSM PZT controller models
%%
m2pzt = get_fsm_pzt_controller(Ts);

[A_oa_pzt, B_oa_pzt, C_oa_pzt, D_oa_pzt, ~] = ssdata(balreal(minreal(m2pzt{1}.SSdtHfb(1,1))));
[A_oa_pec, B_oa_pec, C_oa_pec, D_oa_pec, ~] = ssdata(balreal(minreal(m2pzt{1}.SSdtHfb(3,3))));
[A_S7_pzt, B_S7_pzt, C_S7_pzt, D_S7_pzt, ~] = ssdata(balreal(minreal(m2pzt{7}.SSdtHfb(1,1))));

%% Load structural model
%%
% The structural model is required to compute:
% - 

ModelFolder = fullfile("/home/rromano/Workspace/gmt-data",...
    "20230612_1451_zen_30_M1_202110_FSM_202305_Mount_202305_concreteODC");

FileName = "static_reduction_model.mat";

if(exist(fullfile(ModelFolder,FileName),'file'))
    fprintf('Loading model file %s\n from folder \n%s\n', FileName, ModelFolder);
    try
        load(fullfile(ModelFolder,FileName),'gainMatrixMountControlled',...
            'inputTable','outputTable');
        gainMatrix = gainMatrixMountControlled;
    catch
        load(fullfile(ModelFolder,FileName),'gainMatrix',...
            'inputTable','outputTable');
    end
else
    error('No static model file is available in the specified folder.');
end

%% M2 Positioner subsystem parameters
%%

% M2 pos act force inputs indices
in1 = inputTable{'MC_M2_SmHex_F',"indices"}{1}(1:2:end);	%macrocell side
in2 = inputTable{'MC_M2_SmHex_F',"indices"}{1}(2:2:end);	%mirror segment side
% M2 POS displacement indices
out1 = outputTable{'MC_M2_SmHex_D',"indices"}{1}(1:2:end);	%macrocell side
out2 = outputTable{'MC_M2_SmHex_D',"indices"}{1}(2:2:end);	%mirror seg side
% M2 RBM output indices
out3 = outputTable{'MC_M2_lcl_6D',"indices"}{1};             %M2 RBM (local CS)


% M2 POS decoupling matrix MC_M2_lcl_6D -> MC_M2_SmHex_D
dcG1 = gainMatrix(out3,in1)-gainMatrix(out3,in2);
dcG2 = gainMatrix(out1,in1)-gainMatrix(out1,in2)...
    -gainMatrix(out2,in1)+gainMatrix(out2,in2);
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
    fprintf('* Updating M2P nominal stiffness value: \n%.4g(N/m) -> %.4g(N/m) *\n',...
        k2p_stiff0,k2p_stiff);
else
    k2p_stiff = k2p_stiff0;
end

% M2POS feedback controller: I + Roll-off filter
fc = 2;     %[Hz] Crossover frequency

kc = 2*pi * fc *k2p_stiff;
% Remark: controller gain not incorporated to the TF
fbH = tf(1,[1 0]) * sndUDampF(10,0.5);
m2p_Cfb_d = c2d(tf(fbH), Ts, 'foh');


%% Load simulink model
%%
ModelFName = 'm2fsm_2_rust';
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

% File with calibration matrices
if(update_calib_dt)
    save('../calib_dt/m2fsm_ctrl_dt.mat',...
        'Km2pS1_dec','Km2pS2_dec','Km2pS3_dec','Km2pS4_dec',...
        'Km2pS5_dec','Km2pS6_dec','Km2pS7_dec', 'k2p_stiff'); %#ok<*UNRCH> 
end

%% Test/verification step data
%%
% % Columns of preshapeBessel_step_y: [cmd_f, dot_cmd_f, ddot_cmd_f]
% [preshapeBessel_step_y,preshapeBessel_step_t] = step(flag_d);
% G_fb_fd = [-Cpi_d-st.asm.Kd*Hpd_d;-st.asm.Kfd*Hpd_d];
% % Columns of asm_fb_imp_y:
% [asm_fb_imp_y, asm_fb_imp_t] = impulse(G_fb_fd);
% % M2POS FB controller impulse test data
% [m2pact_fb_imp_y, m2pact_fb_imp_t] = impulse(kc*m2p_Cfb_d);
% if (update_test_dt || ~exist('m2asm_tests','var'))
%     save('m2asm_tests','preshapeBessel_step_y','preshapeBessel_step_t',...
%         'asm_fb_imp_y','asm_fb_imp_t',...
%         'm2pact_fb_imp_y','m2pact_fb_imp_t');
% end


%% Build FSM-based M2 models
%%

currentFolder = pwd;
% Simulink configuration settings file folder
cd('../../../');
try
    cs = config_slx2022b(ModelFName);
    cs_name = cs.get_param('Name');
    fprintf('Simulink model configuration (%s) set successfully!\n',...
        cs_name);
catch ME
    warning('Unable to set model confgurations!');
    cd(currentFolder);
    rethrow(ME);
end
% Return to the M2-FSM Simulink files folder
cd(currentFolder);

pzt_Cfb_S1_3_5_label = sprintf('%s/pzt_Cfb_S1_3_5', ModelFName);
pzt_Cfb_S2_4_6_label = sprintf('%s/pzt_Cfb_S2_4_6', ModelFName);
pzt_Cfb_S7_label = sprintf('%s/pzt_Cfb_S7', ModelFName);
m2p_Cfb_label = sprintf('%s/M2P_act_Cfb', ModelFName);

if auto_compile
    slbuild(pzt_Cfb_S1_3_5_label);
    slbuild(pzt_Cfb_S2_4_6_label);
    slbuild(pzt_Cfb_S7_label);
    slbuild(m2p_Cfb_label);
else
    warning('The code for models was not built! ');
    warning(strcat('Use slbuild(pzt_Cfb_S1_3_5_label), ',...
        'slbuild(pzt_Cfb_S2_4_6_label), slbuild(pzt_Cfb_S7_label),',...
        'and slbuild(m2p_Cfb_label) to compile M2-ASM model codes.'));
end



%% Auxiliar functions
%%
% Function to get FSM/PZT controller parameters
function m2pzt = get_fsm_pzt_controller(Ts)

% Extra function protoypes
% S-notch filter prototype. Tuning parameters: zn, zd, fd, fw
snotch = @(zn,zd,fd,fn) tf((fd/fn)^2*[1 2*zn*(2*pi*fn) (2*pi*fn)^2],...
    [1 2*zd*(2*pi*fd) (2*pi*fd)^2]);

% Structure to store M1 data
m2pzt = cell(7,1);

% PZT actuator gain [N/m]
kpzt = 18.9e6;

% Segment loop
for iseg = 1:7
    % Filters
    if(iseg == 7)   % On-axis segment
        pztF1a = balreal(ss(snotch(0.04,0.6,93,93)));
        pztF1b = pztF1a;
        pztF2a = 1;
        pztF2b = pztF2a;
    else             % Off-axis segments
        pztF1a = balreal(ss(snotch(0.05,0.5,83,86)));
        pztF2a = 1;%balreal(ss(snotch(0.08,0.2,140,140)));
        %
        pztF1b = balreal(ss(snotch(0.25,0.4,53,60)));
        pztF2b = balreal(ss(snotch(0.04,0.28,122,125)));
    end

    % Controller parameters
    frolloff = 40;  % Roll-off filter frequency [Hz]
    k_I_pzt = 0.92*16.8* 2*pi;	% PZT integral controller (OAD design)
    Hrolloff = tf(1,[1/(frolloff*2*pi) 1]); %1;

    pzt_F = c2d(Hrolloff*pztF1a*pztF2a, Ts, 'foh');
    pzt_F_edgeS = c2d(Hrolloff*pztF1b*pztF2b, Ts,'foh');

    % FSM controller SS model
    Hfb_dt = kpzt * c2d(tf(k_I_pzt,[1 0]), Ts, 'impulse');

    m2pzt{iseg}.SSdtHfb(1,1) = balreal(ss(Hfb_dt)*pzt_F);
    if(mod(iseg,2))
        m2pzt{iseg}.SSdtHfb(2,2) = m2pzt{iseg}.SSdtHfb(1,1);
        m2pzt{iseg}.SSdtHfb(3,3) = balreal(ss(Hfb_dt)*pzt_F_edgeS);
    else
        m2pzt{iseg}.SSdtHfb(2,2) = balreal(ss(Hfb_dt)*pzt_F_edgeS);
        m2pzt{iseg}.SSdtHfb(3,3) = m2pzt{iseg}.SSdtHfb(1,1);
    end

end
end

%[eof]
