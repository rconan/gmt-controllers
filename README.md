# Giant Magellan Telescope control systems

## Primary mirror control system

This repository provides Rust code for the GMT primary mirror (M1) controller model for end-to-end simulations.

The transfer function of the support actuator (SA) feedback controller and those representing the closed-loop dynamics of the hardpoint (HP) motions are compiled from high-level (Matlab/Simulink) model files. Those files are available in the `m1-simulink-models` folder.

The model has some structural model-dependent parameters. The folder `calib_dt` has a data file with those parameters computed assuming the model `20220610_1023_MT_mount_zen_30_m1HFN_FSM_`.

# Secondary mirror control system
