/*
 * File: ASM_PIplusD_Fd.c
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

/* Model step function */
void ASM_PIplusD_Fd_step(RT_MODEL_ASM_PIplusD_Fd_T *const ASM_PIplusD_Fd_M,
  ExtU_ASM_PIplusD_Fd_T *ASM_PIplusD_Fd_U, ExtY_ASM_PIplusD_Fd_T
  *ASM_PIplusD_Fd_Y)
{
  DW_ASM_PIplusD_Fd_T *ASM_PIplusD_Fd_DW = ASM_PIplusD_Fd_M->dwork;
  real_T ASMPIcontroller_tmp;
  real_T rtb_Numericaldifferentiation;
  real_T rtb_Sum1;

  /* DiscreteTransferFcn: '<S1>/ASM PI controller' incorporates:
   *  Inport: '<Root>/asm_FB'
   *  Inport: '<Root>/asm_SP'
   *  Sum: '<S1>/Sum1'
   */
  ASMPIcontroller_tmp = ((ASM_PIplusD_Fd_U->asm_SP - ASM_PIplusD_Fd_U->asm_FB) -
    ASM_PIplusD_Fd_P.ASMPIcontroller_DenCoef[1] *
    ASM_PIplusD_Fd_DW->ASMPIcontroller_states) /
    ASM_PIplusD_Fd_P.ASMPIcontroller_DenCoef[0];

  /* DiscreteTransferFcn: '<S1>/Numerical differentiation' incorporates:
   *  Inport: '<Root>/asm_FB'
   */
  rtb_Sum1 = (ASM_PIplusD_Fd_U->asm_FB -
              ASM_PIplusD_Fd_P.Numericaldifferentiation_DenCoef[1] *
              ASM_PIplusD_Fd_DW->Numericaldifferentiation_states) /
    ASM_PIplusD_Fd_P.Numericaldifferentiation_DenCoef[0];
  rtb_Numericaldifferentiation =
    ASM_PIplusD_Fd_P.Numericaldifferentiation_NumCoef[0] * rtb_Sum1 +
    ASM_PIplusD_Fd_P.Numericaldifferentiation_NumCoef[1] *
    ASM_PIplusD_Fd_DW->Numericaldifferentiation_states;

  /* Outport: '<Root>/asm_U' incorporates:
   *  DiscreteTransferFcn: '<S1>/ASM PI controller'
   *  Gain: '<S1>/Kd'
   *  Inport: '<Root>/asm_FF'
   *  Sum: '<S1>/Sum3'
   *  Sum: '<S1>/Sum4'
   */
  ASM_PIplusD_Fd_Y->asm_U = ((ASM_PIplusD_Fd_P.ASMPIcontroller_NumCoef[0] *
    ASMPIcontroller_tmp + ASM_PIplusD_Fd_P.ASMPIcontroller_NumCoef[1] *
    ASM_PIplusD_Fd_DW->ASMPIcontroller_states) - ASM_PIplusD_Fd_P.Kd_Gain *
    rtb_Numericaldifferentiation) + ASM_PIplusD_Fd_U->asm_FF;

  /* Outport: '<Root>/asm_Fd' incorporates:
   *  Gain: '<S1>/-Kfdamp'
   */
  ASM_PIplusD_Fd_Y->asm_Fd = ASM_PIplusD_Fd_P.Kfdamp_Gain *
    rtb_Numericaldifferentiation;

  /* Update for DiscreteTransferFcn: '<S1>/ASM PI controller' */
  ASM_PIplusD_Fd_DW->ASMPIcontroller_states = ASMPIcontroller_tmp;

  /* Update for DiscreteTransferFcn: '<S1>/Numerical differentiation' */
  ASM_PIplusD_Fd_DW->Numericaldifferentiation_states = rtb_Sum1;
}

/* Model initialize function */
void ASM_PIplusD_Fd_initialize(RT_MODEL_ASM_PIplusD_Fd_T *const ASM_PIplusD_Fd_M,
  ExtU_ASM_PIplusD_Fd_T *ASM_PIplusD_Fd_U, ExtY_ASM_PIplusD_Fd_T
  *ASM_PIplusD_Fd_Y)
{
  DW_ASM_PIplusD_Fd_T *ASM_PIplusD_Fd_DW = ASM_PIplusD_Fd_M->dwork;

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)ASM_PIplusD_Fd_DW, 0,
                sizeof(DW_ASM_PIplusD_Fd_T));

  /* external inputs */
  (void)memset(ASM_PIplusD_Fd_U, 0, sizeof(ExtU_ASM_PIplusD_Fd_T));

  /* external outputs */
  (void) memset((void *)ASM_PIplusD_Fd_Y, 0,
                sizeof(ExtY_ASM_PIplusD_Fd_T));

  /* InitializeConditions for DiscreteTransferFcn: '<S1>/ASM PI controller' */
  ASM_PIplusD_Fd_DW->ASMPIcontroller_states =
    ASM_PIplusD_Fd_P.ASMPIcontroller_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<S1>/Numerical differentiation' */
  ASM_PIplusD_Fd_DW->Numericaldifferentiation_states =
    ASM_PIplusD_Fd_P.Numericaldifferentiation_InitialStates;
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
