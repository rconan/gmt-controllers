/*
 * File: MountDrives_private.h
 *
 * Code generated for Simulink model 'MountDrives'.
 *
 * Model version                  : 1.596
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Thu Apr 23 20:42:43 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MountDrives_private_h_
#define RTW_HEADER_MountDrives_private_h_
#include "rtwtypes.h"
#include "MountDrives.h"

extern real_T rt_roundd_snf(real_T u);
extern void MountDrives_AZDTLugreFrmodel(real_T rtu_Enable, real_T rtu_vel,
  real_T *rty_FrTorque, B_AZDTLugreFrmodel_MountDrives_T *localB,
  DW_AZDTLugreFrmodel_MountDrives_T *localDW, const
  struct_kxIwWES1orY88dAgmfLm1E *rtp_frParStruct);

#endif                                 /* RTW_HEADER_MountDrives_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
