/*
 * File: Mount_Drv_FDR2023_private.h
 *
 * Code generated for Simulink model 'Mount_Drv_FDR2023'.
 *
 * Model version                  : 9.78
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Apr  1 12:53:27 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#ifndef RTW_HEADER_Mount_Drv_FDR2023_private_h_
#define RTW_HEADER_Mount_Drv_FDR2023_private_h_
#include "rtwtypes.h"
#include "Mount_Drv_FDR2023.h"
#include "Mount_Drv_FDR2023_types.h"

extern real_T rt_roundd(real_T u);
extern real_T rt_remd(real_T u0, real_T u1);
extern real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void Mount_Drv_FDR2023_gs(real_T rtu_Enable, real_T rtu_v, real_T
  *rty_gsv, real_T rtp_vs, real_T rtp_Ts, real_T rtp_Tc, real_T rtp_sigma0);
extern void Mount_Drv_FDR20_AZDTLugreFrmode(real_T rtu_Enable, real_T rtu_v,
  real_T *rty_Tfr, real_T rtp_vs, real_T rtp_Ts, real_T rtp_Tc, real_T
  rtp_sigma0, real_T rtp_iIsSig01Active, real_T rtp_sigma1, real_T rtp_sigmav,
  DW_AZDTLugreFrmode_Mount_Drv__T *localDW);
extern void Mount_Drv_FDR2_ForEachSubsystem(int32_T NumIters, const real_T
  rtu_In1[8], real_T rty_Out1[8]);
extern void Mount_Drv_FDR_ForEachSubsystem1(int32_T NumIters, const real_T
  rtu_In1[8], real_T rty_Out1[8]);

#endif                             /* RTW_HEADER_Mount_Drv_FDR2023_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
