# Giant Magellan Telescope control systems models and codes

This repository provides Rust code for some GMT subsystems composing end-to-end simulation models. Those codes are generated from a compilation process (to C language) using Simulink models.

(__Text under review__)

## Primary mirror control system

The codes for the M1 control system are available in the `m1-ctrl` folder.

The transfer function of the support actuator (SA) feedback controller and those representing the closed-loop dynamics of the hardpoint (HP) motions are compiled from high-level (Matlab/Simulink) model files. Those files are available in the `m1-simulink-models` folder.

The model has some structural model-dependent parameters. The folder `calib_dt` has a data file with those parameters computed assuming the model `20220610_1023_MT_mount_zen_30_m1HFN_FSM_`.

## Secondary mirror control system

The codes for the M2 control system are available in the `m2-ctrl` folder.
