/*
 * File: C_ngao.c
 *
 * Code generated for Simulink model 'C_ngao'.
 *
 * Model version                  : 5.56
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Mar 17 19:17:33 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "C_ngao.h"
#include "C_ngao_private.h"

/* Model step function */
void C_ngao_step(RT_MODEL_C_ngao_T *const C_ngao_M, ExtU_C_ngao_T *C_ngao_U,
                 ExtY_C_ngao_T *C_ngao_Y)
{
  DW_C_ngao_T *C_ngao_DW = C_ngao_M->dwork;
  real_T NGAOTemporalController_tmp;

  /* DiscreteTransferFcn: '<S1>/NGAO Temporal Controller' incorporates:
   *  Inport: '<Root>/Delta_m'
   */
  NGAOTemporalController_tmp = (C_ngao_U->Delta_m - C_ngao_P.Cngao_d_den[1] *
    C_ngao_DW->NGAOTemporalController_states[0]) - C_ngao_P.Cngao_d_den[2] *
    C_ngao_DW->NGAOTemporalController_states[1];

  /* Outport: '<Root>/m' incorporates:
   *  DiscreteTransferFcn: '<S1>/NGAO Temporal Controller'
   */
  C_ngao_Y->m = (C_ngao_P.Cngao_d_num[0] * NGAOTemporalController_tmp +
                 C_ngao_P.Cngao_d_num[1] *
                 C_ngao_DW->NGAOTemporalController_states[0]) +
    C_ngao_P.Cngao_d_num[2] * C_ngao_DW->NGAOTemporalController_states[1];

  /* Update for DiscreteTransferFcn: '<S1>/NGAO Temporal Controller' */
  C_ngao_DW->NGAOTemporalController_states[1] =
    C_ngao_DW->NGAOTemporalController_states[0];
  C_ngao_DW->NGAOTemporalController_states[0] = NGAOTemporalController_tmp;
}

/* Model initialize function */
void C_ngao_initialize(RT_MODEL_C_ngao_T *const C_ngao_M, ExtU_C_ngao_T
  *C_ngao_U, ExtY_C_ngao_T *C_ngao_Y)
{
  DW_C_ngao_T *C_ngao_DW = C_ngao_M->dwork;

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)C_ngao_DW, 0,
                sizeof(DW_C_ngao_T));

  /* external inputs */
  C_ngao_U->Delta_m = 0.0;

  /* external outputs */
  C_ngao_Y->m = 0.0;

  /* InitializeConditions for DiscreteTransferFcn: '<S1>/NGAO Temporal Controller' */
  C_ngao_DW->NGAOTemporalController_states[0] =
    C_ngao_P.NGAOTemporalController_InitialStates;
  C_ngao_DW->NGAOTemporalController_states[1] =
    C_ngao_P.NGAOTemporalController_InitialStates;
}

/* Model terminate function */
void C_ngao_terminate(RT_MODEL_C_ngao_T *const C_ngao_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(C_ngao_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
