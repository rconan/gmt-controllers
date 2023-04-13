# Giant Magellan Telescope control systems model codes

This repository provides Rust code for some GMT subsystems composing end-to-end simulation models. Those codes are generated from a compilation process (to C language) using Simulink models. The files are organized in different subfolders, each one dedicated to a particular subsystem. The current version has the control model of two subsystems: M1 and M2. The Simulink model files are available in the `simulink-models` folder of the respective subsystem. More details on the models available are described below.

(__Text under review__)

## Primary mirror control system

The codes for the M1 control system are available in the `m1-ctrl` folder.

The transfer function of the support actuator (SA) feedback controller and those representing the closed-loop dynamics of the hardpoint (HP) motions are compiled from high-level (Matlab/Simulink) model files.

The SA feedback controller models have some structural model-dependent parameters. The folder `calib_dt` has a data file with those parameters computed assuming the model `20220610_1023_MT_mount_zen_30_m1HFN_FSM_`.

## Secondary mirror control system

The codes for the M2 control system are available in the `m2-ctrl` folder.
