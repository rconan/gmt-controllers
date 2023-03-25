/*
 * File: M2P_act_Cfb.c
 *
 * Code generated for Simulink model 'M2P_act_Cfb'.
 *
 * Model version                  : 5.53
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Feb 28 13:57:41 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M2P_act_Cfb.h"
#include "M2P_act_Cfb_private.h"

/* Model step function */
void M2P_act_Cfb_step(RT_MODEL_M2P_act_Cfb_T *const M2P_act_Cfb_M,
                      ExtU_M2P_act_Cfb_T *M2P_act_Cfb_U, ExtY_M2P_act_Cfb_T
                      *M2P_act_Cfb_Y)
{
  DW_M2P_act_Cfb_T *M2P_act_Cfb_DW = M2P_act_Cfb_M->dwork;
  real_T M2P_I_rolloffF_tmp;

  /* DiscreteTransferFcn: '<S1>/M2P_I_rolloffF' incorporates:
   *  Gain: '<S1>/k2p_stiff'
   *  Gain: '<S1>/m2p_om_c'
   *  Inport: '<Root>/M2pAct_E'
   */
  M2P_I_rolloffF_tmp = (((6.2831853071795862 * M2P_act_Cfb_P.fc *
    (M2P_act_Cfb_P.k2p_stiff * M2P_act_Cfb_U->M2pAct_E) -
    M2P_act_Cfb_P.M2P_I_rolloffF_DenCoef[1] *
    M2P_act_Cfb_DW->M2P_I_rolloffF_states[0]) -
    M2P_act_Cfb_P.M2P_I_rolloffF_DenCoef[2] *
    M2P_act_Cfb_DW->M2P_I_rolloffF_states[1]) -
                        M2P_act_Cfb_P.M2P_I_rolloffF_DenCoef[3] *
                        M2P_act_Cfb_DW->M2P_I_rolloffF_states[2]) /
    M2P_act_Cfb_P.M2P_I_rolloffF_DenCoef[0];

  /* Outport: '<Root>/M2pAct_U' incorporates:
   *  DiscreteTransferFcn: '<S1>/M2P_I_rolloffF'
   */
  M2P_act_Cfb_Y->M2pAct_U = ((M2P_act_Cfb_P.M2P_I_rolloffF_NumCoef[0] *
    M2P_I_rolloffF_tmp + M2P_act_Cfb_P.M2P_I_rolloffF_NumCoef[1] *
    M2P_act_Cfb_DW->M2P_I_rolloffF_states[0]) +
    M2P_act_Cfb_P.M2P_I_rolloffF_NumCoef[2] *
    M2P_act_Cfb_DW->M2P_I_rolloffF_states[1]) +
    M2P_act_Cfb_P.M2P_I_rolloffF_NumCoef[3] *
    M2P_act_Cfb_DW->M2P_I_rolloffF_states[2];

  /* Update for DiscreteTransferFcn: '<S1>/M2P_I_rolloffF' */
  M2P_act_Cfb_DW->M2P_I_rolloffF_states[2] =
    M2P_act_Cfb_DW->M2P_I_rolloffF_states[1];
  M2P_act_Cfb_DW->M2P_I_rolloffF_states[1] =
    M2P_act_Cfb_DW->M2P_I_rolloffF_states[0];
  M2P_act_Cfb_DW->M2P_I_rolloffF_states[0] = M2P_I_rolloffF_tmp;
}

/* Model initialize function */
void M2P_act_Cfb_initialize(RT_MODEL_M2P_act_Cfb_T *const M2P_act_Cfb_M,
  ExtU_M2P_act_Cfb_T *M2P_act_Cfb_U, ExtY_M2P_act_Cfb_T *M2P_act_Cfb_Y)
{
  DW_M2P_act_Cfb_T *M2P_act_Cfb_DW = M2P_act_Cfb_M->dwork;

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)M2P_act_Cfb_DW, 0,
                sizeof(DW_M2P_act_Cfb_T));

  /* external inputs */
  M2P_act_Cfb_U->M2pAct_E = 0.0;

  /* external outputs */
  M2P_act_Cfb_Y->M2pAct_U = 0.0;

  /* InitializeConditions for DiscreteTransferFcn: '<S1>/M2P_I_rolloffF' */
  M2P_act_Cfb_DW->M2P_I_rolloffF_states[0] =
    M2P_act_Cfb_P.M2P_I_rolloffF_InitialStates;
  M2P_act_Cfb_DW->M2P_I_rolloffF_states[1] =
    M2P_act_Cfb_P.M2P_I_rolloffF_InitialStates;
  M2P_act_Cfb_DW->M2P_I_rolloffF_states[2] =
    M2P_act_Cfb_P.M2P_I_rolloffF_InitialStates;
}

/* Model terminate function */
void M2P_act_Cfb_terminate(RT_MODEL_M2P_act_Cfb_T *const M2P_act_Cfb_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(M2P_act_Cfb_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
