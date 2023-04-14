/*
 * File: ASM_PIplusD_Fd.c
 *
 * Code generated for Simulink model 'ASM_PIplusD_Fd'.
 *
 * Model version                  : 9.4
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Apr 14 16:10:20 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#include "ASM_PIplusD_Fd.h"
#include "rtwtypes.h"

/* Model step function */
void ASM_PIplusD_Fd_step(RT_MODEL_ASM_PIplusD_Fd_T *const ASM_PIplusD_Fd_M,
  ExtU_ASM_PIplusD_Fd_T *ASM_PIplusD_Fd_U, ExtY_ASM_PIplusD_Fd_T
  *ASM_PIplusD_Fd_Y)
{
  DW_ASM_PIplusD_Fd_T *ASM_PIplusD_Fd_DW = ASM_PIplusD_Fd_M->dwork;
  real_T denAccum;
  real_T denAccum_0;
  real_T rtb_Numericaldifferentiation;

  /* DiscreteTransferFcn: '<S1>/ASM PI controller' incorporates:
   *  Sum: '<S1>/Sum1'
   */
  denAccum = (ASM_PIplusD_Fd_U->asm_SP - ASM_PIplusD_Fd_U->asm_FB) -
    (-ASM_PIplusD_Fd_DW->ASMPIcontroller_states);

  /* DiscreteTransferFcn: '<S1>/Numerical differentiation' */
  denAccum_0 = ASM_PIplusD_Fd_U->asm_FB - -0.043213918263772258 *
    ASM_PIplusD_Fd_DW->Numericaldifferentiation_states;
  rtb_Numericaldifferentiation = 7654.28865388982 * denAccum_0 +
    -7654.2886538898265 * ASM_PIplusD_Fd_DW->Numericaldifferentiation_states;

  /* Outport: '<Root>/asm_U' incorporates:
   *  DiscreteTransferFcn: '<S1>/ASM PI controller'
   *  Gain: '<S1>/Kd'
   *  Sum: '<S1>/Sum3'
   *  Sum: '<S1>/Sum4'
   */
  ASM_PIplusD_Fd_Y->asm_U = ((70031.25 * denAccum + -69968.750000000015 *
    ASM_PIplusD_Fd_DW->ASMPIcontroller_states) - 24.5 *
    rtb_Numericaldifferentiation) + ASM_PIplusD_Fd_U->asm_FF;

  /* Outport: '<Root>/asm_Fd' incorporates:
   *  Gain: '<S1>/-Kfdamp'
   */
  ASM_PIplusD_Fd_Y->asm_Fd = -9.1 * rtb_Numericaldifferentiation;

  /* Update for DiscreteTransferFcn: '<S1>/ASM PI controller' */
  ASM_PIplusD_Fd_DW->ASMPIcontroller_states = denAccum;

  /* Update for DiscreteTransferFcn: '<S1>/Numerical differentiation' */
  ASM_PIplusD_Fd_DW->Numericaldifferentiation_states = denAccum_0;
}

/* Model initialize function */
void ASM_PIplusD_Fd_initialize(RT_MODEL_ASM_PIplusD_Fd_T *const ASM_PIplusD_Fd_M)
{
  /* (no initialization code required) */
  UNUSED_PARAMETER(ASM_PIplusD_Fd_M);
}

/* Model terminate function */
void ASM_PIplusD_Fd_terminate(RT_MODEL_ASM_PIplusD_Fd_T *const ASM_PIplusD_Fd_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(ASM_PIplusD_Fd_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
