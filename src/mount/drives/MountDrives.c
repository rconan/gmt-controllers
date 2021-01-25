/*
 * File: MountDrives.c
 *
 * Code generated for Simulink model 'MountDrives'.
 *
 * Model version                  : 1.596
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Thu Apr 23 20:42:43 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MountDrives.h"
#include "MountDrives_private.h"

/* Block signals (default storage) */
B_MountDrives_T MountDrives_B;

/* Block states (default storage) */
DW_MountDrives_T MountDrives_DW;

/* External inputs (root inport signals with default storage) */
ExtU_MountDrives_T MountDrives_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_MountDrives_T MountDrives_Y;

/* Real-time model */
RT_MODEL_MountDrives_T MountDrives_M_;
RT_MODEL_MountDrives_T *const MountDrives_M = &MountDrives_M_;

/*
 * Output and update for enable system:
 *    '<S1>/AZ DT Lugre Fr model'
 *    '<S1>/EL DT Lugre Fr model'
 */
void MountDrives_AZDTLugreFrmodel(real_T rtu_Enable, real_T rtu_vel, real_T
  *rty_FrTorque, B_AZDTLugreFrmodel_MountDrives_T *localB,
  DW_AZDTLugreFrmodel_MountDrives_T *localDW, const
  struct_kxIwWES1orY88dAgmfLm1E *rtp_frParStruct)
{
  real_T rtb_iIsSig01Active;

  /* Outputs for Enabled SubSystem: '<S1>/AZ DT Lugre Fr model' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* Gain: '<S2>/iIsSig01Active' */
    rtb_iIsSig01Active = rtp_frParStruct->iIsSig01Active * rtu_vel;

    /* Sum: '<S10>/Sum' incorporates:
     *  Abs: '<S10>/Abs'
     *  Constant: '<S9>/gc'
     *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
     *  Product: '<S10>/Divide'
     *  Sum: '<S9>/Sum'
     */
    rtb_iIsSig01Active -= fabs(rtb_iIsSig01Active) / (rtp_frParStruct->Tc /
      rtp_frParStruct->sigm0 + localB->Divide) *
      localDW->DiscreteTimeIntegrator_DSTATE;

    /* Sum: '<S2>/Sum' incorporates:
     *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
     *  Gain: '<S2>/sigma_0'
     *  Gain: '<S2>/sigma_1'
     *  Gain: '<S2>/sigma_v'
     */
    *rty_FrTorque = (rtp_frParStruct->sigm1 * rtb_iIsSig01Active +
                     rtp_frParStruct->sigm0 *
                     localDW->DiscreteTimeIntegrator_DSTATE) +
      rtp_frParStruct->sigmv * rtu_vel;

    /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_DSTATE += 0.0005 * rtb_iIsSig01Active;
  }

  /* End of Outputs for SubSystem: '<S1>/AZ DT Lugre Fr model' */
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void MountDrives_step(void)
{
  real_T denAccum;
  real_T rtb_TSamp[20];
  real_T rtb_ELencavgm2rad;
  real_T rtb_Sum_l;
  int32_T i;
  real_T rtb_EL_drv_sat_0;
  real_T tmp;
  real_T rtb_TSamp_e;
  for (i = 0; i < 20; i++) {
    /* SampleTimeMath: '<S4>/TSamp' incorporates:
     *  Inport: '<Root>/Mount_pos'
     *
     * About '<S4>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp_e = MountDrives_U.Mount_pos[i] * 2000.0;

    /* Sum: '<S4>/Diff' incorporates:
     *  UnitDelay: '<S4>/UD'
     *
     * Block description for '<S4>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S4>/UD':
     *
     *  Store in Global RAM
     */
    MountDrives_DW.UD_DSTATE[i] = rtb_TSamp_e - MountDrives_DW.UD_DSTATE[i];

    /* SampleTimeMath: '<S4>/TSamp'
     *
     * About '<S4>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp[i] = rtb_TSamp_e;
  }

  /* DiscreteTransferFcn: '<S1>/AZ_TFd' incorporates:
   *  Delay: '<S1>/AZ_delay'
   *  Quantizer: '<S1>/AZ_drv_qt'
   */
  rtb_TSamp_e = rt_roundd_snf
    (MountDrives_DW.AZ_delay_DSTATE[MountDrives_DW.CircBufIdx] / 14.6484375) *
    14.6484375 - -0.6 * MountDrives_DW.AZ_TFd_states;
  rtb_ELencavgm2rad = 0.2 * rtb_TSamp_e + 0.2 * MountDrives_DW.AZ_TFd_states;

  /* Saturate: '<S1>/AZ_drv_sat' incorporates:
   *  DiscreteTransferFcn: '<S1>/AZ_TFd'
   */
  if (rtb_ELencavgm2rad > 480000.0) {
    rtb_ELencavgm2rad = 480000.0;
  } else {
    if (rtb_ELencavgm2rad < -480000.0) {
      rtb_ELencavgm2rad = -480000.0;
    }
  }

  /* End of Saturate: '<S1>/AZ_drv_sat' */

  /* Gain: '<S1>/AZ enc avg + m2rad' */
  rtb_EL_drv_sat_0 = 0.0;

  /* Gain: '<S1>/AZ vel avg and m//s=>rad//s' */
  tmp = 0.0;
  for (i = 0; i < 8; i++) {
    /* Gain: '<S1>/AZ enc avg + m2rad' incorporates:
     *  Inport: '<Root>/Mount_pos'
     */
    rtb_EL_drv_sat_0 += MountDrives_ConstP.pooled6[i] *
      MountDrives_U.Mount_pos[i];

    /* Gain: '<S1>/AZ vel avg and m//s=>rad//s' */
    tmp += MountDrives_ConstP.pooled6[i] * MountDrives_DW.UD_DSTATE[i];
  }

  /* Outputs for Enabled SubSystem: '<S1>/AZ DT Lugre Fr model' */

  /* Constant: '<S1>/Constant' incorporates:
   *  Gain: '<S1>/AZ vel avg and m//s=>rad//s'
   */
  MountDrives_AZDTLugreFrmodel(1.0, tmp, &MountDrives_B.Sum_g,
    &MountDrives_B.AZDTLugreFrmodel, &MountDrives_DW.AZDTLugreFrmodel,
    &MountDrives_ConstP.AZDTLugreFrmodel_rtw_collapsed_sub_expr_0);

  /* End of Outputs for SubSystem: '<S1>/AZ DT Lugre Fr model' */

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S3>/CogAmp'
   *  Constant: '<S3>/CogSpatFreq'
   *  Constant: '<S3>/RippleAmpFactor'
   *  Constant: '<S3>/RippleSpatFreq'
   *  Gain: '<S1>/AZ enc avg + m2rad'
   *  Product: '<S3>/Product1'
   *  Product: '<S3>/Product2'
   *  Product: '<S3>/Product3'
   *  Product: '<S3>/Product4'
   *  Sum: '<S3>/Sum'
   *  Trigonometry: '<S3>/Trigonometric Function'
   *  Trigonometry: '<S3>/Trigonometric Function1'
   */
  rtb_Sum_l = ((rtb_ELencavgm2rad * 0.015 * sin(rtb_EL_drv_sat_0 * 5400.0) + sin
                (rtb_EL_drv_sat_0 * 1800.0) * 1414.0) + rtb_ELencavgm2rad) +
    MountDrives_B.Sum_g;

  /* DiscreteTransferFcn: '<S1>/EL_TFd' incorporates:
   *  Delay: '<S1>/EL_delay'
   *  Quantizer: '<S1>/EL_drv_qt'
   */
  denAccum = rt_roundd_snf
    (MountDrives_DW.EL_delay_DSTATE[MountDrives_DW.CircBufIdx_i] /
     10.833740234375) * 10.833740234375 - -0.6 * MountDrives_DW.EL_TFd_states;
  rtb_EL_drv_sat_0 = 0.2 * denAccum + 0.2 * MountDrives_DW.EL_TFd_states;

  /* Saturate: '<S1>/EL_drv_sat' incorporates:
   *  DiscreteTransferFcn: '<S1>/EL_TFd'
   */
  if (rtb_EL_drv_sat_0 > 355000.0) {
    rtb_EL_drv_sat_0 = 355000.0;
  } else {
    if (rtb_EL_drv_sat_0 < -355000.0) {
      rtb_EL_drv_sat_0 = -355000.0;
    }
  }

  /* End of Saturate: '<S1>/EL_drv_sat' */

  /* Gain: '<S1>/EL enc avg + m2rad' */
  rtb_ELencavgm2rad = 0.0;

  /* Gain: '<S1>/EL vel avg and m//s=>rad//s' */
  tmp = 0.0;
  for (i = 0; i < 8; i++) {
    /* Gain: '<S1>/EL enc avg + m2rad' incorporates:
     *  Inport: '<Root>/Mount_pos'
     */
    rtb_ELencavgm2rad += MountDrives_U.Mount_pos[8 + i] *
      MountDrives_ConstP.pooled9[i];

    /* Gain: '<S1>/EL vel avg and m//s=>rad//s' */
    tmp += MountDrives_DW.UD_DSTATE[8 + i] * MountDrives_ConstP.pooled9[i];
  }

  /* Outputs for Enabled SubSystem: '<S1>/EL DT Lugre Fr model' */

  /* Constant: '<S1>/Constant1' incorporates:
   *  Gain: '<S1>/EL vel avg and m//s=>rad//s'
   */
  MountDrives_AZDTLugreFrmodel(1.0, tmp, &MountDrives_B.Sum,
    &MountDrives_B.ELDTLugreFrmodel, &MountDrives_DW.ELDTLugreFrmodel,
    &MountDrives_ConstP.ELDTLugreFrmodel_rtw_collapsed_sub_expr_6);

  /* End of Outputs for SubSystem: '<S1>/EL DT Lugre Fr model' */

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S6>/CogAmp'
   *  Constant: '<S6>/CogSpatFreq'
   *  Constant: '<S6>/RippleAmpFactor'
   *  Constant: '<S6>/RippleSpatFreq'
   *  Gain: '<S1>/EL enc avg + m2rad'
   *  Product: '<S6>/Product1'
   *  Product: '<S6>/Product2'
   *  Product: '<S6>/Product3'
   *  Product: '<S6>/Product4'
   *  Sum: '<S6>/Sum'
   *  Trigonometry: '<S6>/Trigonometric Function'
   *  Trigonometry: '<S6>/Trigonometric Function1'
   */
  rtb_ELencavgm2rad = ((rtb_EL_drv_sat_0 * 0.015 * sin(rtb_ELencavgm2rad *
    5820.0) + sin(rtb_ELencavgm2rad * 1940.0) * 1414.0) + rtb_EL_drv_sat_0) +
    MountDrives_B.Sum;

  /* Outport: '<Root>/Mount_F' incorporates:
   *  Gain: '<S1>/convert to Az drive forces'
   *  Gain: '<S1>/convert to El drive forces'
   *  Gain: '<S1>/convert to GIR drive forces'
   *  Inport: '<Root>/Mount_cmd'
   */
  for (i = 0; i < 8; i++) {
    MountDrives_Y.Mount_F[i] = MountDrives_ConstP.pooled6[i] * rtb_Sum_l;
    MountDrives_Y.Mount_F[i + 8] = MountDrives_ConstP.pooled9[i] *
      rtb_ELencavgm2rad;
  }

  MountDrives_Y.Mount_F[16] = -0.5 * MountDrives_U.Mount_cmd[2];
  MountDrives_Y.Mount_F[17] = -0.5 * MountDrives_U.Mount_cmd[2];
  MountDrives_Y.Mount_F[18] = 0.5 * MountDrives_U.Mount_cmd[2];
  MountDrives_Y.Mount_F[19] = 0.5 * MountDrives_U.Mount_cmd[2];

  /* End of Outport: '<Root>/Mount_F' */

  /* Update for UnitDelay: '<S4>/UD'
   *
   * Block description for '<S4>/UD':
   *
   *  Store in Global RAM
   */
  memcpy(&MountDrives_DW.UD_DSTATE[0], &rtb_TSamp[0], 20U * sizeof(real_T));

  /* Update for Delay: '<S1>/AZ_delay' incorporates:
   *  Inport: '<Root>/Mount_cmd'
   */
  MountDrives_DW.AZ_delay_DSTATE[MountDrives_DW.CircBufIdx] =
    MountDrives_U.Mount_cmd[0];
  if (MountDrives_DW.CircBufIdx < 13U) {
    MountDrives_DW.CircBufIdx++;
  } else {
    MountDrives_DW.CircBufIdx = 0U;
  }

  /* End of Update for Delay: '<S1>/AZ_delay' */

  /* Update for DiscreteTransferFcn: '<S1>/AZ_TFd' */
  MountDrives_DW.AZ_TFd_states = rtb_TSamp_e;

  /* Update for Delay: '<S1>/EL_delay' incorporates:
   *  Inport: '<Root>/Mount_cmd'
   */
  MountDrives_DW.EL_delay_DSTATE[MountDrives_DW.CircBufIdx_i] =
    MountDrives_U.Mount_cmd[1];
  if (MountDrives_DW.CircBufIdx_i < 13U) {
    MountDrives_DW.CircBufIdx_i++;
  } else {
    MountDrives_DW.CircBufIdx_i = 0U;
  }

  /* End of Update for Delay: '<S1>/EL_delay' */

  /* Update for DiscreteTransferFcn: '<S1>/EL_TFd' */
  MountDrives_DW.EL_TFd_states = denAccum;
}

/* Model initialize function */
void MountDrives_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(MountDrives_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &MountDrives_B), 0,
                sizeof(B_MountDrives_T));

  /* states (dwork) */
  (void) memset((void *)&MountDrives_DW, 0,
                sizeof(DW_MountDrives_T));

  /* external inputs */
  (void)memset((void *)&MountDrives_U, 0, sizeof(ExtU_MountDrives_T));

  /* external outputs */
  (void) memset(&MountDrives_Y.Mount_F[0], 0,
                20U*sizeof(real_T));

  /* InitializeConditions for Delay: '<S1>/AZ_delay' */
  MountDrives_DW.CircBufIdx = 0U;

  /* InitializeConditions for Delay: '<S1>/EL_delay' */
  MountDrives_DW.CircBufIdx_i = 0U;
}

/* Model terminate function */
void MountDrives_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
