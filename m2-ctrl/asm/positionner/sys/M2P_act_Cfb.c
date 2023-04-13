/*
 * File: M2P_act_Cfb.c
 *
 * Code generated for Simulink model 'M2P_act_Cfb'.
 *
 * Model version                  : 9.4
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Apr 13 11:04:05 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#include "M2P_act_Cfb.h"
#include "rtwtypes.h"

/* Model step function */
void M2P_act_Cfb_step(RT_MODEL_M2P_act_Cfb_T *const M2P_act_Cfb_M, real_T
                      M2P_act_Cfb_U_M2pAct_E, real_T *M2P_act_Cfb_Y_M2pAct_U)
{
  DW_M2P_act_Cfb_T *M2P_act_Cfb_DW = M2P_act_Cfb_M->dwork;
  real_T M2P_I_rolloffF_tmp;

  /* DiscreteTransferFcn: '<S1>/M2P_I_rolloffF' incorporates:
   *  Gain: '<S1>/k2p_stiff'
   *  Gain: '<S1>/m2p_om_c'
   *  Inport: '<Root>/M2pAct_E'
   */
  M2P_I_rolloffF_tmp = ((1.479910125477238E+8 * M2P_act_Cfb_U_M2pAct_E *
    12.566370614359172 - -2.9921153371845048 *
    M2P_act_Cfb_DW->M2P_I_rolloffF_states[0]) - 2.9842921174770662 *
                        M2P_act_Cfb_DW->M2P_I_rolloffF_states[1]) -
    -0.99217678029256162 * M2P_act_Cfb_DW->M2P_I_rolloffF_states[2];

  /* Outport: '<Root>/M2pAct_U' incorporates:
   *  DiscreteTransferFcn: '<S1>/M2P_I_rolloffF'
   */
  *M2P_act_Cfb_Y_M2pAct_U = ((3.2077152625295559E-10 * M2P_I_rolloffF_tmp +
    3.5229414952692262E-9 * M2P_act_Cfb_DW->M2P_I_rolloffF_states[0]) +
    3.5174120042123771E-9 * M2P_act_Cfb_DW->M2P_I_rolloffF_states[1]) +
    3.192634813656456E-10 * M2P_act_Cfb_DW->M2P_I_rolloffF_states[2];

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
