%
% load_mount_data.m
%
% Load variables to mount drives and controller
% 
% - CHANGELOG -
% May, 2023: FDR2023 version
% Feb, 2024: Including models of the PDR2021 version
%

deltaT = 1/8e3;     % [s] Main sampling period
FEM_Ts = deltaT;

%
% Notch filter realization
% function filter = notchF(fc,F,delta)
notchF = @(fc,F,delta) tf([1, 4*pi*fc/(F*delta), 4*(pi*fc)^2],...
    [1, 4*pi*fc/F, 4*(pi*fc)^2]);
% INPUTS
% fc: notched frequency in Hz
% F: sharpness factor (higher F leads to narrower rejection band)
% delta: notch depth in dB
%

%% Script options
%%
% Flag to compile M1 control model codes at the end of data loading process
auto_compile = false;
% Flag to save/update test data file
update_test_dt = false;%true; %
% % Flag to save/update controller data file
% update_calib_dt = false;%true; %

%% ODC model settings
%%

% oTest.sZa: elevation zenith angle (ZA) as string e.g. '00','30','60'
oTest.sZa = '30'; %'00' or '60'
% oTest.sVer: FEM version as string e.g. '19'
oTest.sVer = '19';%'20';%
% oTest.sSubVer: FEM subversion as string e.g. '1'
oTest.sSubVer = '1'; %'11'; %'2'; %
% oTest.sDamping: now '02' means 2% structural dumping
oTest.sDamping ='02';
% oTest.bUseReducedModel: [true|false] if true: a reduced model is used
%  which was created by the balred method
oTest.bUseReducedModel = true;


%%

%/Users/rromano/Workspace/mnt-odc/fdr2023/MatlabFilesE2E_2023-05-10/base
% Folder with ODC End-to-end functions
odc_file_folder = '/Users/rromano/Workspace/mnt-odc';

switch strcat(oTest.sVer,'.',oTest.sSubVer)
    case '19.1', odc_main_folder = "pdr2021 - E2E_Matlab_Model";
    case '20.2', odc_main_folder = "2022-06-09_ODC Dynamic Wind Simulations_Simulink & Matlab files";
    case '20.11', odc_main_folder = "fdr2023/MatlabFilesE2E_2023-05-10"; 
    otherwise, error('ODC end-to-end model version not available!');
end

odc_base_util_folder = fullfile(odc_file_folder,odc_main_folder,'base/util');
odc_base_conf_folder = fullfile(odc_file_folder,odc_main_folder,'base/conf');
addpath(odc_base_util_folder,odc_base_conf_folder);
fprintf('\nIncluding folder\n %s\ninto MatLab path.\n', odc_main_folder);
fprintf('Getting model parameters ...\n');

if (str2double(oTest.sVer)+0.01*str2double(oTest.sSubVer) < 20.11)
    % ODC Simulink model used (located in ../base)
    oTest.sRoot = 'rootw';
    o = fun_confBase(oTest.sRoot, oTest.sZa, oTest.sVer, oTest.sSubVer, oTest.sDamping,...
        0, oTest.bUseReducedModel);
    ctrl_filename = fullfile('/Users/rromano/Workspace/gmt-ims',...
        sprintf('controls_5pt1g%dK_z%s_llTT_oad.mat',...
        ceil(1/deltaT/1e3), oTest.sZa));
    fprintf('Loading mount controller and driver model parameters from\n%s\n',ctrl_filename);
    load(ctrl_filename,'mount');
    if(auto_compile), auto_compile = false; end %#ok<*UNRCH> 
else
    % ODC Simulink model used (located in ../base)
    oTest.sRoot = 'root';
    % oTest.sHbsConf: name of HBS configuration: e.g. 'HbTp19'
    oTest.sHbsConf = 'HaTp19'; %'HbTp19'
    % oTest.sViscFrCase: one of 3 cases w.r.t. viscosity: ['ViscFrLow', 'ViscFrMedium', 'ViscFrHigh']  see fun_mueByTempAzEl
    oTest.sViscFrCase = 'ViscFrLow'; %lowest viscosity=>lowest damping
    % oTest.sModelDirIn: directory relative to ../ss_model/ where the state space models are located
    % returns structure [o] with all configuration parameters
    oTest.sModelDirIn = 'v20.11/n100HzR800';
    o = fun_confBase(oTest);
end

% Remove folders from Matlab path
fprintf('\nRemoving folders\n%s\n%s\nfrom MatLab path.\n\n',...
    odc_base_util_folder, odc_base_conf_folder);
rmpath(odc_base_util_folder,odc_base_conf_folder);


%% Mount (FB & FF) controller discretization
%%

c2d_opt = c2dOptions('method','tustin');
mnt_TF_Ts = FEM_Ts;

% AZ
aznotchF17 = notchF(16.9, 3.5, 1.8);
mount.az.SSdtHfb = balreal(c2d(ss(aznotchF17*o.az.c.Hp), mnt_TF_Ts, c2d_opt));    % FB
mount.az.SSdtHff = balreal(c2d(ss(o.az.c.Hff), mnt_TF_Ts, c2d_opt));   % FF
% EL
mount.el.SSdtHfb = balreal(c2d(ss(o.el.c.Hp), mnt_TF_Ts, c2d_opt));    % FB
mount.el.SSdtHff = balreal(c2d(ss(o.el.c.Hff), mnt_TF_Ts, c2d_opt));   % FF
% GIR
mount.gir.SSdtHfb = balreal(c2d(ss(o.gir.c.Hp), mnt_TF_Ts, c2d_opt));    % FB
mount.gir.SSdtHff = balreal(c2d(ss(o.gir.c.Hff), mnt_TF_Ts, c2d_opt));   % FF

%% Mount driver model parameters
%%

mount.delay = 4.0e-3;     % [s] DRV delay: 4ms (GMT25-ANA-40000-0007-2.0 - Pg26)
drv_delay = ceil(mount.delay/FEM_Ts);
fprintf('Driver delay set to %d sampling periods (Ts=%gms).\n',drv_delay,1e3*FEM_Ts);
if(rem(mount.delay,FEM_Ts))
    warning('Driver delay is not a multiple of the sampling period!')
end

% Current loop dynamics tranfer function
Hdrive_d = c2d(o.Hdrive(1,1), FEM_Ts, 'tustin');



%% Load simulink model
ModelFName = 'mount_2_rust';
open(sprintf('%s.slx',ModelFName));

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



%% Compiled block test data 
%%

% Test data
clear mnt_fbC_step_y mnt_fbC_step_t
[mnt_fbC_step_y(:,1), mnt_fbC_step_t] = step(mount.az.SSdtHfb,0.15);
[mnt_fbC_step_y(:,2), ~] = step(mount.el.SSdtHfb,mnt_fbC_step_t);
[mnt_fbC_step_y(:,3), ~] = step(mount.gir.SSdtHfb,mnt_fbC_step_t);

if (update_test_dt || ~exist('mnt_fbC_step_test','var'))
    save mnt_fbC_step_test mnt_fbC_step_y mnt_fbC_step_t
else
    warning('Update test data feature is disabled!')
end

%% Compile model subsystems
%%

mnt_ctrl_name = sprintf("%s/Mount_Control",ModelFName);
mnt_drv_name = sprintf("%s/Mount_Drv_FDR2023",ModelFName);

if auto_compile
    slbuild(mnt_ctrl_name);
    slbuild(mnt_drv_name);
else
    warning("The code for the mount controller and driver were not built!");
    warning("Use slbuild('%s') and "+...
        "slbuild('%s') to compile the mount models.", mnt_ctrl_name, mnt_drv_name);
end

