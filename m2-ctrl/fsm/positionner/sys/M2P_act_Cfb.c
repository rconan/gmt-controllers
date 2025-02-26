/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: M2P_act_Cfb.c
 *
 * Code generated for Simulink model 'M2P_act_Cfb'.
 *
 * Model version                  : 9.14
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Feb 26 17:05:55 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#include "M2P_act_Cfb.h"
#include "rtwtypes.h"

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
   */
  M2P_I_rolloffF_tmp = ((1.2448304389848548E+8 * M2P_act_Cfb_U->M2pAct_E *
    12.566370614359172 - -2.9352762520681424 *
    M2P_act_Cfb_DW->M2P_I_rolloffF_states[0]) - 2.8743776194924351 *
                        M2P_act_Cfb_DW->M2P_I_rolloffF_states[1]) -
    -0.9391013674242924 * M2P_act_Cfb_DW->M2P_I_rolloffF_states[2];

  /* Outport: '<Root>/M2pAct_U' incorporates:
   *  DiscreteTransferFcn: '<S1>/M2P_I_rolloffF'
   */
  M2P_act_Cfb_Y->M2pAct_U = ((1.624265143448743E-7 * M2P_I_rolloffF_tmp +
    1.7641525439989183E-6 * M2P_act_Cfb_DW->M2P_I_rolloffF_states[0]) +
    1.7421192960996023E-6 * M2P_act_Cfb_DW->M2P_I_rolloffF_states[1]) +
    1.5641700170671574E-7 * M2P_act_Cfb_DW->M2P_I_rolloffF_states[2];

  /* Update for DiscreteTransferFcn: '<S1>/M2P_I_rolloffF' */
  M2P_act_Cfb_DW->M2P_I_rolloffF_states[2] =
    M2P_act_Cfb_DW->M2P_I_rolloffF_states[1];
  M2P_act_Cfb_DW->M2P_I_rolloffF_states[1] =
    M2P_act_Cfb_DW->M2P_I_rolloffF_states[0];
  M2P_act_Cfb_DW->M2P_I_rolloffF_states[0] = M2P_I_rolloffF_tmp;
}

/* Model initialize function */
void M2P_act_Cfb_initialize(RT_MODEL_M2P_act_Cfb_T *const M2P_act_Cfb_M)
{
  /* (no initialization code required) */
  UNUSED_PARAMETER(M2P_act_Cfb_M);
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
