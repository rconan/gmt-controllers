%
% load_M1DCS_data.m
%
% Load variables to compile M1 controller
% 
% Apr, 2023: Simulink settings in an external file (Matlab 2022b)
% Jan, 2023: Segment-wise implementation
% Apr, 2022: Split decoupling matrices

% Flag to compile M1 control model codes at the end of data loading process
auto_compile = false;
% Flag to save/update test data file
update_test_dt = false;%true; %
% Flag to save/update controller data file
update_calib_dt = false;%true; %

%%
load('controls_5pt1g1K_z30_llTT_oad.mat','m1sys','fem');

% m1sys variable content (seg = {1,...,7}):
%
% m1sys{seg}.HPstiff: Hardpoint stiffness
% m1sys{seg}.LC2CG: HP: F&M convertion matrix
% m1sys{seg}.ofl.SSdtC{ich}: M1 outer force loop controller
% m1sys{seg}.HPdtf: M1 HP length closed-loop dynamics
% m1sys{seg}.Kbal: Load balancing
% m1sys{seg}.Kred: Matrix to remove lateral force entries for Single SA
% m1sys{seg}.m1BM2F: matrix to map BM into SA forces


%% Calibration-dependent matrices
%%

% LC to CG force transformation
OA_LC2CG = zeros(6);
for i_ = 1:6
    OA_LC2CG = OA_LC2CG + (1/6) * m1sys{i_}.LC2CG;
end
% Test if average LC2CG matrix is acceptable
for i_ = 1:6
    assert(norm(OA_LC2CG-m1sys{i_}.LC2CG)/norm(OA_LC2CG) < 0.001) ;
end
CS_LC2CG = m1sys{7}.LC2CG;


% The script used to compute the controller parameters
% (build_5ptYX_ctrl_interf.m) ensures that the HP stiffness saved as
% m1sys{iS}.HPstiff is the same for any iS={1,...,7}.
m1_HPk = m1sys{1}.HPstiff;

% M1 RBM to HP length convertion
S1_M1RBM2HP = m1sys{1}.M1RBM2HP;
S2_M1RBM2HP = m1sys{2}.M1RBM2HP;
S3_M1RBM2HP = m1sys{3}.M1RBM2HP;
S4_M1RBM2HP = m1sys{4}.M1RBM2HP;
S5_M1RBM2HP = m1sys{5}.M1RBM2HP;
S6_M1RBM2HP = m1sys{6}.M1RBM2HP;
S7_M1RBM2HP = m1sys{7}.M1RBM2HP;

if update_calib_dt
save('../calib_dt/m1_ctrl_dt.mat',...
    'OA_LC2CG', 'CS_LC2CG', ...
    'm1_HPk',...
    'S1_M1RBM2HP', 'S2_M1RBM2HP', 'S3_M1RBM2HP', 'S4_M1RBM2HP',...
    'S5_M1RBM2HP', 'S6_M1RBM2HP', 'S7_M1RBM2HP');
end


%% Controller&Filter parameters
% Support actuator dynamics (same for all segments)
SA_dynNum = m1sys{1}.SAdyn.num{1};
SA_dynDen = m1sys{1}.SAdyn.den{1};

OA_ofl_SSdtC = m1sys{1}.ofl.SSdtC;
CS_ofl_SSdtC = m1sys{7}.ofl.SSdtC;


%% Load simulink model
ModelFName = 'M1DCS_2_rust';
open(sprintf('%s.slx',ModelFName));

% build_subsys = 'M1_SA';
build_subsys = 'HP_dyn';

hplc_label = sprintf('%s/M1_HP_loadcells', ModelFName);
hp_RBMtoD_label = sprintf('%s/M1RBM_to_HP_relD', ModelFName);
hp_dyn_label = sprintf('%s/M1_HP_Dynamics', ModelFName);
hp_stiff_label = sprintf('%s/HPk', ModelFName);
m1SA_C_CS_label = sprintf('%s/M1SA_Control_CS' ,ModelFName);
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

switch build_subsys
    case 'M1_SA'
        n_bm = 27; %size(m1sys{2}.m1BM2F,2);
        % Solver sampling period
        deltaT = m1sys{1}.ofl.Ts;
        set_param(hplc_label,'Commented','on');
        set_param(hp_RBMtoD_label,'Commented','on');
        set_param(hp_dyn_label,'Commented','on');
        set_param(hp_stiff_label,'Commented','on');
        set_param(m1SA_C_OA_label,'Commented','off');
        set_param(m1SA_C_CS_label,'Commented','off');
        % Test data
        for i1 = 1:numel(m1sys{1}.ofl.SSdtC)
            OActrl(i1,i1) = m1sys{1}.ofl.SSdtC{i1}; %#ok<*SAGROW>
            CSctrl(i1,i1) = m1sys{7}.ofl.SSdtC{i1};
        end
        OAsys = m1sys{1}.SAdyn*m1sys{1}.Kbal*OActrl;
        CSsys = m1sys{7}.SAdyn*m1sys{7}.Kbal*CSctrl;
        [OAact_imp_y,OAact_imp_t] = impulse(OAsys);
        [CSact_imp_y,CSact_imp_t] = impulse(CSsys);

        if (update_test_dt && ~exist('m1_act_impulse_test','var'))
            save m1_act_impulse_test OAact_imp_t OAact_imp_y CSact_imp_t CSact_imp_y
        else
            warning('Update test data feature is disabled!')
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
        % Solver sampling period
        deltaT = m1sys{1}.HPdtf.Ts;
        %% M1 Command pre-processor (CCP)
        %%

        % Command pre-processor (CPP) settings
        delta_sim = deltaT;
        
        Tcmd = 10*delta_sim;                      % Command update period
        k_cmd = floor(Tcmd/delta_sim);            % Used in the Sample_generator block

        % Bessel filter to limit acc derivative (jerk)
        bessel_num = [9.50565136e-07, 3.80226054e-06, 5.70339082e-06, 3.80226054e-06, 9.50565138e-07];
        bessel_den = [ 1., -3.80206663, 5.42365878, -3.4403268, 0.81874986];
        bessel_f_disc = d2d(tf(bessel_num, bessel_den, 0.01), delta_sim);

        % Bessel filter state-space realization
        [A_f, B_f, C_f, D_f] = ssdata(balreal(bessel_f_disc));
        [xf, ~] = step(ss(A_f, B_f, eye(4), zeros(4,1), delta_sim),10);        
        x0_f = 0*xf(end,:);     % Bessel filter IC set to zero
        % Group delay compensation constants
        t_gd = 0*0.5;
        t_gd_v = 0*t_gd;

        % Velocity and acceleration limits -- Symmetric bounds, i.e.: vmin = -vmax
        v_max = 50e-6;      % [m/s]
        a_max = 250e-6;     % [m/s^2]

        n_in = 6;
        % Initial position and velocity state
        x0 = 0; % For now, one is unable to set a different IC for each HP length.
        v0 = 0;

        %%
        set_param(hplc_label,'Commented','off');
        set_param(hp_RBMtoD_label,'Commented','off');
        set_param(hp_dyn_label,'Commented','off');
        set_param(hp_stiff_label,'Commented','off');
        set_param(m1SA_C_OA_label,'Commented','on');
        set_param(m1SA_C_CS_label,'Commented','on');
        
        % Test data
        [hp_dyn_step_y,hp_dyn_step_t] = step(m1sys{1}.HPdtf);
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
%     load('controls_5pt3a_rr.mat','m1sys','fem');
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


