/*
 * File: ASM_PIplusD_Fd_data.c
 *
 * Code generated for Simulink model 'ASM_PIplusD_Fd'.
 *
 * Model version                  : 5.43
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed Feb 22 17:47:07 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ASM_PIplusD_Fd.h"
#include "ASM_PIplusD_Fd_private.h"

/* Block parameters (default storage) */
P_ASM_PIplusD_Fd_T ASM_PIplusD_Fd_P = {
  /* Expression: Cpi_d.num{1}
   * Referenced by: '<S1>/ASM PI controller'
   */
  { 70031.25, -69968.75 },

  /* Expression: Cpi_d.den{1}
   * Referenced by: '<S1>/ASM PI controller'
   */
  { 1.0, -1.0 },

  /* Expression: 0
   * Referenced by: '<S1>/ASM PI controller'
   */
  0.0,

  /* Expression: Hpd_d.num{1}
   * Referenced by: '<S1>/Numerical differentiation'
   */
  { 7654.28865388982, -7654.2886538898238 },

  /* Expression: Hpd_d.den{1}
   * Referenced by: '<S1>/Numerical differentiation'
   */
  { 1.0, -0.043213918263772258 },

  /* Expression: 0
   * Referenced by: '<S1>/Numerical differentiation'
   */
  0.0,

  /* Expression: st.asm.Kd
   * Referenced by: '<S1>/Kd'
   */
  24.5,

  /* Expression: -st.asm.Kfd
   * Referenced by: '<S1>/-Kfdamp'
   */
  -9.1
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
