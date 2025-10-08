%
% load_M1DCS_data.m
%
% Load variables to compile M1 controller
% 
% Sep-2025: Outer force loop controller update (design employed in the test
% cell experiment). Calibration matrices based on new structural model IOs.
% Apr-2023: Simulink settings in an external file (Matlab 2022b)
% Jan-2023: Segment-wise implementation
% Apr-2022: Split decoupling matrices

clearvars
% Flag to compile M1 control model codes at the end of data loading process
auto_compile = false;
% Flag to save/update test data file
update_test_dt = true; %false;%true; %
% Flag to save/update controller data file
update_calib_dt = true;%false;%


%% Load M1 system data
%%
SAdataFolder = [];
load(fullfile(SAdataFolder,'SupportActuatorArrayConfig.mat'),...
    'OA_Kbal','OA_Kred','CS_Kbal','CS_Kred');

% load('controls_5pt1g1K_z30_llTT_oad.mat','m1sys','fem');
% m1sys variable content (seg = {1,...,7}):
%
% m1sys{seg}.HPstiff: Hardpoint stiffness
% m1sys{seg}.M1RBM2HP: M1 RBM to HP length transformation <- redefined here
% m1sys{seg}.LC2CG: HP: F&M convertion matrix <- M_HP recomputed here
% m1sys{seg}.ofl.SSdtC{ich}: M1 outer force loop controller <- redefined here
% m1sys{seg}.HPdtf: M1 HP length closed-loop dynamics
% m1sys{seg}.Kbal: Load balancing
% m1sys{seg}.Kred: Matrix to remove lateral force entries for Single SA
% m1sys{seg}.m1BM2F: matrix to map BM into SA forces


%% Load model static gain file
%%

% ===>>> User shall check file path and name
if ismac(), mFolder = im.lfFolder;
else, mFolder = '/home/rromano/mnt';
end

tel_model_label = "20250516_1420_zen_30_M1_202110_FSM_202305_Mount_202305_pier_202411_M1_actDamping";
FileFolder = fullfile(mFolder, tel_model_label);

if(~exist('inputTable','var') || 0)
    try
        staticSolFile = fullfile(FileFolder,"static_reduction_model.mat");
        try
            load(staticSolFile,...
                'gainMatrixMountControlled','inputTable','outputTable');
            gainMatrix = gainMatrixMountControlled;
        catch
            load(staticSolFile,'gainMatrix');
        end
    catch
        load_static_model = 0;
        warning('Unable to load static gain matrix\n')
    end
end


%% Calibration-dependent matrices
%%

% HP-LC to CG force transformation
M_HP_OA = zeros(6);
M_HP_seg = cell(6,1);
for i_ = 1:7    % Loop over all segments
    % HP LC output indices
    ind_HP_F = outputTable{'OSS_Hardpoint_force',"indices"}{1}((i_-1)*6+(1:6));
    % M1 SA force input indices
    ind_act_F = inputTable{sprintf('M1_actuators_segment_%d',i_),"indices"}{1};

    % Static gain matrix from M1 SA force to HP LC measurement output
    G2_bar = gainMatrix(ind_HP_F,ind_act_F);
    
    if(i_ < 7)
        M_HP_seg{i_} = eye(6)/(G2_bar*OA_Kbal);
        M_HP_OA = M_HP_OA + (1/6)*M_HP_seg{i_};
    else, M_HP_CS = eye(6)/(G2_bar*CS_Kbal);
    end
end

% Test if average M_HP matrix is acceptable for OA
for i_ = 1:6    % Loop over outer-axis segments
    assert(norm(M_HP_OA-M_HP_seg{i_})/norm(M_HP_OA) < 0.001) ;
end


% HP equivalent stiffness
ind_cell = find(kron(ones(7,1),[ones(6,1);zeros(6,1)]));
ind_face = find(kron(ones(7,1),[zeros(6,1);ones(6,1)]));

inHP_F_ind = inputTable{'OSS_Harpoint_delta_F','indices'}{1};
outHP_Da = outputTable{'OSS_Hardpoint_D',"indices"}{1}(ind_cell);   % cell side
outHP_Db = outputTable{'OSS_Hardpoint_D',"indices"}{1}(ind_face);   % face side

HPstiffvec = 1./diag(...
        gainMatrix(outHP_Db,inHP_F_ind)-gainMatrix(outHP_Da,inHP_F_ind));
fprintf('HP stiffness:%.3g +/-%.2g [N/um]\n',...
    1e-6*mean(HPstiffvec),3e-6*std(HPstiffvec));
m1_HPk = mean(HPstiffvec);


% M1 RBM to HP length convertion
for i_ = 1:7    % Loop over all segments
    seg_ind = (i_-1)*6+(1:6);
    rbm_out_ind = outputTable{'OSS_M1_lcl',"indices"}{1}(seg_ind);
    hplen_in_ind = inputTable{'OSS_Hardpoint_extension',"indices"}{1}(seg_ind);
    eval(sprintf('S%d_M1RBM2HP = eye(6)/gainMatrix(rbm_out_ind,hplen_in_ind);',i_));
end

% Save calibration data matrices
if update_calib_dt
save('../calib_dt/m1_ctrl_dt.mat',...
    'M_HP_OA', 'M_HP_CS', ...
    'm1_HPk',...
    'S1_M1RBM2HP', 'S2_M1RBM2HP', 'S3_M1RBM2HP', 'S4_M1RBM2HP',...
    'S5_M1RBM2HP', 'S6_M1RBM2HP', 'S7_M1RBM2HP');
end


%% Controller & Actuator dynamics 
%%
% M1 control system sampled at 100Hz
T_ofl = 0.01;   % [s]

% Support actuator dynamics (same for all segments)
H_p_cyl = 0.2/1 *tf([1 1*2*pi],[1 0.2*2*pi]) * tf(10*2*pi,[1 10*2*pi]);
H_p_cyl_DT = c2d(H_p_cyl, T_ofl, 'foh');  
SA_dynNum = H_p_cyl_DT.num{1};
SA_dynDen = H_p_cyl_DT.den{1};

% OFL controller: PI+Lead-lag (SPIE2024-)
fPI = tf([0.1 5],[1 0]);
flead = tf([1 0.1*2*pi],[1 0.3*2*pi]);
flag = tf([1 15*2*pi],[1 5*2*pi]);
fbH = balreal(ss(fPI * flead * flag));

ofl_SSdtC = c2d(fbH, T_ofl, 'foh');
OA_ofl_SSdtC = ofl_SSdtC;
CS_ofl_SSdtC = ofl_SSdtC;

% Hardpoint dynamics
HDIm = 8.9e-4;      %[Kg m^2] Electric Motor Moment of Inertia
Pv = tf(1,[HDIm 0]);    % Velocity inner loop TF
HPKw2Lin = 1e-3/(161*(2*pi));   %[m/rads] Motor shaft to Linear speed
Pp = tf(HPKw2Lin, [1 0]);   % Position plant (roller screw)

% Controller gains to match test-cell data
kpp_ = 3.1583e+07;
kpi_ = 6.5797e+06;
kvp_ = 0.0307562;
kvi_ = 0.0153781;
Cv_ = tf([kvp_, kvi_],[1 0]);
Hv_ = minreal(Pv*Cv_/(1+Pv*Cv_));
HPdyn = c2d(feedback(tf([kpp_, kpi_],[1 0])*Hv_*Pp,1), 1e-3,'foh');

if(false)
    G_CT = fbH;
    hbode = bodeoptions;
    hbode.FreqUnits = 'Hz';
    hbode.XLabel.FontSize = 11;
    hbode.YLabel.FontSize = 11;
    hbode.Ylabel.String{1} = 'Mag';
    figure(7000)
    G_DT = c2d(G_CT, T_ofl, 'foh');
    G_DT2 = c2d(G_CT, T_ofl, 'Tustin');
    bode(G_CT, G_DT, G_DT2, hbode);
    grid on;
    xlim([0.05, 0.5/ofl.Ts])
    set(gcf,'Position',[600   567   1.6*304*3/2   420*0.95]);
    legend('CT','FOH','Tustin','Location','northwest'); legend box off;
end


%% Load simulink model
%%
ModelFName = 'M1DCS_2_rust';
open(sprintf('%s.slx',ModelFName));

% build_subsys = 'M1_SA';
build_subsys = 'HP_dyn';

hplc_label = sprintf('%s/M1_HP_loadcells', ModelFName);
hp_RBMtoD_label = sprintf('%s/M1RBM_to_HP_relD', ModelFName);
hp_dyn_label = sprintf('%s/M1_HP_Dynamics', ModelFName);
m1SA_C_CS_label = sprintf('%s/M1SA_Control_CS', ModelFName);
m1SA_C_OA_label = sprintf('%s/M1SA_Control_OA', ModelFName);

% MATLAB function for configuration set
currentFolder = pwd;
% Simulink configuration settings file folder
cd('../../');
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
% Return to the m1-ctrl/simulink-models Simulink files folder
cd(currentFolder);
% Comment HP load cell model --- obsolete
set_param(hplc_label,'Commented','on');

switch build_subsys
    case 'M1_SA'
        n_bm = 27; %size(m1sys{2}.m1BM2F,2);
        deltaT = OA_ofl_SSdtC.Ts;   % Solver sampling period

        set_param(hp_RBMtoD_label,'Commented','on');
        set_param(hp_dyn_label,'Commented','on');
        set_param(m1SA_C_OA_label,'Commented','off');
        set_param(m1SA_C_CS_label,'Commented','off');
        
        % Test data
        OAsys = H_p_cyl_DT * OA_Kbal * (eye(6)*OA_ofl_SSdtC);
        CSsys = H_p_cyl_DT * CS_Kbal * (eye(6)*CS_ofl_SSdtC);
        [OAact_imp_y,OAact_imp_t] = impulse(OAsys);
        [CSact_imp_y,CSact_imp_t] = impulse(CSsys);

        if (update_test_dt && ~exist('m1_act_impulse_test','var'))
            save m1_act_impulse_test OAact_imp_t OAact_imp_y CSact_imp_t CSact_imp_y
        else
            warning("Update test data feature is disabled!")
        end

        if auto_compile
            slbuild(m1SA_C_OA_label); %#ok<*UNRCH> 
            slbuild(m1SA_C_CS_label);
        else
            warning('The codes for models %s and %s were not built!',...
                m1SA_C_OA_label, m1SA_C_CS_label);
            warning('Use %s and %s to compile the models.',...
                "slbuild(m1SA_C_OA_label)","slbuild(m1SA_C_CS_label)");
        end
        
    case 'HP_dyn'
        deltaT = HPdyn.Ts; % Solver sampling period

        set_param(hp_RBMtoD_label,'Commented','off');
        set_param(hp_dyn_label,'Commented','off');
        set_param(m1SA_C_OA_label,'Commented','on');
        set_param(m1SA_C_CS_label,'Commented','on');
        
        % Test data
        [hp_dyn_step_y,hp_dyn_step_t] = step(HPdyn);
        if (update_test_dt && ~exist('hp_dyn_step_test','var'))
            save hp_dyn_step_test hp_dyn_step_t hp_dyn_step_y
        else
            warning('Update test data feature is disabled!')
        end

        if auto_compile, slbuild(hp_dyn_label+"/HP_dyn_dTF");
        else
            warning('The code for model %s was not built!',hp_dyn_label);
            warning('Use slbuild(hp_dyn_label+"/HP_dyn_dTF") to compile the model.');
        end
end



%% Older version
%%
%%%
% if 0
%     % Dimension of the M1 bending modes command vector
%     n_bm = 27; %#ok<UNRCH>
%     
%     load('controls_5pt3a_rr.mat','m1sys');
%     % m1sys{seg}.HPstiff: Hardpoint stiffness
%     % m1sys{seg}.LC2CG: HP: F&M convertion matrix
%     % m1sys{seg}.ofl.SSdtC{ich}: M1 outer force loop controller
%     
%     % BM-2-F convertion
%     SAdataFolder = '/Users/rromano/Workspace/Build4';
%     load(fullfile(SAdataFolder,'SupportActuatorArrayConfig.mat'),...
%         'OA_Kbal','OA_Kred','CS_Kbal','CS_Kred');
%     
%     StructModelFolder = fullfile(im.lfFolder,"20210802_0755_MT_mount_v202104_FSM");
%     % OA
%     filename = fullfile(StructModelFolder,'m1s1_Af.mat');
%     load(filename,'afprime');
%     [~,S,V] = svd(afprime,0);
%     % BM to forces convertion matrix (3*n_a)
%     m1BM2Fxyz = kron(eye(size(afprime,2)),[0;0;1]) * V(:,1:n_bm)*...
%         diag(1./diag(S(1:n_bm,1:n_bm)));
%     m1BM2F_OA = OA_Kred*m1BM2Fxyz;
%     
%     filename = fullfile(StructModelFolder,'m1s7_Af.mat');
%     load(filename,'afprime');
%     [~,S,V] = svd(afprime,0);
%     % BM to forces convertion matrix (3*n_a)
%     m1BM2Fxyz = kron(eye(size(afprime,2)),[0;0;1]) * V(:,1:n_bm)*...
%         diag(1./diag(S(1:n_bm,1:n_bm)));
%     m1BM2F_CS = CS_Kred*m1BM2Fxyz;
% 
% end


