/*
 * File: ASM_PIplusD_Fd.c
 *
 * Code generated for Simulink model 'ASM_PIplusD_Fd'.
 *
 * Model version                  : 9.5
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Apr 26 17:28:28 2023
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
  denAccum_0 = ASM_PIplusD_Fd_U->asm_FB - 0.22203094070331456 *
    ASM_PIplusD_Fd_DW->Numericaldifferentiation_states;
  rtb_Numericaldifferentiation = 9776.247525626517 * denAccum_0 +
    -9776.247525626517 * ASM_PIplusD_Fd_DW->Numericaldifferentiation_states;

  /* Outport: '<Root>/asm_U' incorporates:
   *  DiscreteTransferFcn: '<S1>/ASM PI controller'
   *  Gain: '<S1>/Kd'
   *  Sum: '<S1>/Sum3'
   *  Sum: '<S1>/Sum4'
   */
  ASM_PIplusD_Fd_Y->asm_U = ((70031.25 * denAccum + -69968.75 *
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
