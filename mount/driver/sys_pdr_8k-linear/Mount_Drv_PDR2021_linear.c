/*
 * File: Mount_Drv_PDR2021_linear.c
 *
 * Code generated for Simulink model 'Mount_Drv_PDR2021_linear'.
 *
 * Model version                  : 9.71
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Mar  5 12:50:54 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#include "Mount_Drv_PDR2021_linear.h"
#include "rtwtypes.h"

/* Model step function */
void Mount_Drv_PDR2021_linear_step(RT_MODEL_Mount_Drv_PDR2021_li_T *const
  Mount_Drv_PDR2021_linear_M, ExtU_Mount_Drv_PDR2021_linear_T
  *Mount_Drv_PDR2021_linear_U, ExtY_Mount_Drv_PDR2021_linear_T
  *Mount_Drv_PDR2021_linear_Y)
{
  DW_Mount_Drv_PDR2021_linear_T *Mount_Drv_PDR2021_linear_DW =
    Mount_Drv_PDR2021_linear_M->dwork;
  real_T AZ_TFd_tmp;
  real_T EL_TFd_tmp;
  real_T GIR_TFd_tmp;
  real_T rtb_AZ_TFd;
  real_T rtb_EL_TFd;
  real_T rtb_GIR_TFd;
  int32_T i;

  /* DiscreteTransferFcn: '<S1>/AZ_TFd' incorporates:
   *  Delay: '<S1>/AZ_delay'
   */
  AZ_TFd_tmp = Mount_Drv_PDR2021_linear_DW->
    AZ_delay_DSTATE[Mount_Drv_PDR2021_linear_DW->CircBufIdx] -
    -0.88235294117647056 * Mount_Drv_PDR2021_linear_DW->AZ_TFd_states;
  rtb_AZ_TFd = 0.058823529411764705 * AZ_TFd_tmp + 0.058823529411764705 *
    Mount_Drv_PDR2021_linear_DW->AZ_TFd_states;

  /* DiscreteTransferFcn: '<S1>/EL_TFd' incorporates:
   *  Delay: '<S1>/EL_delay'
   */
  EL_TFd_tmp = Mount_Drv_PDR2021_linear_DW->
    EL_delay_DSTATE[Mount_Drv_PDR2021_linear_DW->CircBufIdx_a] -
    -0.88235294117647056 * Mount_Drv_PDR2021_linear_DW->EL_TFd_states;
  rtb_EL_TFd = 0.058823529411764705 * EL_TFd_tmp + 0.058823529411764705 *
    Mount_Drv_PDR2021_linear_DW->EL_TFd_states;

  /* DiscreteTransferFcn: '<S1>/GIR_TFd' incorporates:
   *  Delay: '<S1>/GIR_delay'
   */
  GIR_TFd_tmp = Mount_Drv_PDR2021_linear_DW->
    GIR_delay_DSTATE[Mount_Drv_PDR2021_linear_DW->CircBufIdx_i] -
    -0.88235294117647056 * Mount_Drv_PDR2021_linear_DW->GIR_TFd_states;
  rtb_GIR_TFd = 0.058823529411764705 * GIR_TFd_tmp + 0.058823529411764705 *
    Mount_Drv_PDR2021_linear_DW->GIR_TFd_states;

  /* Outport: '<Root>/Mount_T' incorporates:
   *  Gain: '<S1>/Split_Drv_To'
   *  SignalConversion generated from: '<S1>/Split_Drv_To'
   */
  for (i = 0; i < 20; i++) {
    Mount_Drv_PDR2021_linear_Y->Mount_T[i] = 0.0;
    Mount_Drv_PDR2021_linear_Y->Mount_T[i] +=
      Mount_Drv_PDR2021_linear_ConstP.Split_Drv_To_Gain[i] * rtb_AZ_TFd;
    Mount_Drv_PDR2021_linear_Y->Mount_T[i] +=
      Mount_Drv_PDR2021_linear_ConstP.Split_Drv_To_Gain[i + 20] * rtb_EL_TFd;
    Mount_Drv_PDR2021_linear_Y->Mount_T[i] +=
      Mount_Drv_PDR2021_linear_ConstP.Split_Drv_To_Gain[i + 40] * rtb_GIR_TFd;
  }

  /* End of Outport: '<Root>/Mount_T' */

  /* Update for Delay: '<S1>/AZ_delay' */
  Mount_Drv_PDR2021_linear_DW->AZ_delay_DSTATE
    [Mount_Drv_PDR2021_linear_DW->CircBufIdx] =
    Mount_Drv_PDR2021_linear_U->Mount_cmd[0];
  if (Mount_Drv_PDR2021_linear_DW->CircBufIdx < 31U) {
    Mount_Drv_PDR2021_linear_DW->CircBufIdx++;
  } else {
    Mount_Drv_PDR2021_linear_DW->CircBufIdx = 0U;
  }

  /* End of Update for Delay: '<S1>/AZ_delay' */

  /* Update for DiscreteTransferFcn: '<S1>/AZ_TFd' */
  Mount_Drv_PDR2021_linear_DW->AZ_TFd_states = AZ_TFd_tmp;

  /* Update for Delay: '<S1>/EL_delay' */
  Mount_Drv_PDR2021_linear_DW->EL_delay_DSTATE
    [Mount_Drv_PDR2021_linear_DW->CircBufIdx_a] =
    Mount_Drv_PDR2021_linear_U->Mount_cmd[1];
  if (Mount_Drv_PDR2021_linear_DW->CircBufIdx_a < 31U) {
    Mount_Drv_PDR2021_linear_DW->CircBufIdx_a++;
  } else {
    Mount_Drv_PDR2021_linear_DW->CircBufIdx_a = 0U;
  }

  /* End of Update for Delay: '<S1>/EL_delay' */

  /* Update for DiscreteTransferFcn: '<S1>/EL_TFd' */
  Mount_Drv_PDR2021_linear_DW->EL_TFd_states = EL_TFd_tmp;

  /* Update for Delay: '<S1>/GIR_delay' */
  Mount_Drv_PDR2021_linear_DW->GIR_delay_DSTATE
    [Mount_Drv_PDR2021_linear_DW->CircBufIdx_i] =
    Mount_Drv_PDR2021_linear_U->Mount_cmd[2];
  if (Mount_Drv_PDR2021_linear_DW->CircBufIdx_i < 31U) {
    Mount_Drv_PDR2021_linear_DW->CircBufIdx_i++;
  } else {
    Mount_Drv_PDR2021_linear_DW->CircBufIdx_i = 0U;
  }

  /* End of Update for Delay: '<S1>/GIR_delay' */

  /* Update for DiscreteTransferFcn: '<S1>/GIR_TFd' */
  Mount_Drv_PDR2021_linear_DW->GIR_TFd_states = GIR_TFd_tmp;
}

/* Model initialize function */
void Mount_Drv_PDR2021_linear_initialize(RT_MODEL_Mount_Drv_PDR2021_li_T *const
  Mount_Drv_PDR2021_linear_M)
{
  /* (no initialization code required) */
  UNUSED_PARAMETER(Mount_Drv_PDR2021_linear_M);
}

/* Model terminate function */
void Mount_Drv_PDR2021_linear_terminate(RT_MODEL_Mount_Drv_PDR2021_li_T *const
  Mount_Drv_PDR2021_linear_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(Mount_Drv_PDR2021_linear_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
