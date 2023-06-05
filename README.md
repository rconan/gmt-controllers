# Giant Magellan Telescope control systems model codes

The repository contains Rust code for several GMT subsystems that make up end-to-end simulation models. These codes were generated through a compilation process, using Simulink models that were translated into C language. The files are organized into subfolders, with each subfolder dedicated to a specific subsystem. The current version of the repository includes the control model for two subsystems: M1 and M2. The Simulink model files for each subsystem can be found in the "simulink-models" folder within the respective subsystem folder. Further information about the available models is provided below.

## Mount control system

The mount control system codes are available in the "mount" folder. Two actors compose the mount control system code. The first is the controller block considering the feedback (PID and notch filters) and feedforward paths. The latter is not used in the FDR 2023 version (v20.11). The second is the driver model. The FDR 2023 mount driver model implements the actuator behavior (processing delay, quantization, current loop dynamics, and torque saturation) and the driver disturbances (parasitic, friction, and GIR tooth contact perturbation torques).

## Primary mirror control system

The M1 control system codes can be found in the "m1-ctrl" folder. These codes include transfer functions for the support actuator (SA) feedback controller and closed-loop dynamics of the hardpoint (HP) motions, which were compiled from high-level Simulink models.

The SA feedback controller models have parameters that depend on the structural model. The "calib_dt" folder contains a data file with the computed parameters, assuming the 20220610_1023_MT_mount_zen_30_m1HFN_FSM_ model.

## Secondary mirror control system

The M2 control system codes can be found in the "m2-ctrl" folder.
