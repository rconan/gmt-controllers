/*
 * File: Mount_Drv_FDR2023.c
 *
 * Code generated for Simulink model 'Mount_Drv_FDR2023'.
 *
 * Model version                  : 9.78
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Apr  1 12:53:27 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#include "Mount_Drv_FDR2023.h"
#include "rtwtypes.h"
#include "Mount_Drv_FDR2023_private.h"
#include <math.h>
#include <string.h>
#include <float.h>

real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[], uint32_T
                   maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

/*
 * Output and update for enable system:
 *    '<S9>/gs'
 *    '<S12>/gs'
 *    '<S15>/gs'
 */
void Mount_Drv_FDR2023_gs(real_T rtu_Enable, real_T rtu_v, real_T *rty_gsv,
  real_T rtp_vs, real_T rtp_Ts, real_T rtp_Tc, real_T rtp_sigma0)
{
  /* Outputs for Enabled SubSystem: '<S9>/gs' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  if (rtu_Enable > 0.0) {
    real_T rtb_Gain_j;

    /* Gain: '<S11>/Gain' */
    rtb_Gain_j = 1.0 / rtp_vs * rtu_v;

    /* Product: '<S11>/Divide' incorporates:
     *  Constant: '<S11>/gs'
     *  Math: '<S11>/Math Function'
     *  Math: '<S11>/Math Function1'
     *  UnaryMinus: '<S11>/Unary Minus'
     *
     * About '<S11>/Math Function':
     *  Operator: exp
     *
     * About '<S11>/Math Function1':
     *  Operator: magnitude^2
     */
    *rty_gsv = (rtp_Ts - rtp_Tc) / rtp_sigma0 * exp(-(rtb_Gain_j * rtb_Gain_j));
  }

  /* End of Outputs for SubSystem: '<S9>/gs' */
}

/*
 * Output and update for enable system:
 *    '<S2>/AZ DT Lugre Fr mode'
 *    '<S2>/EL DT Lugre Fr model'
 */
void Mount_Drv_FDR20_AZDTLugreFrmode(real_T rtu_Enable, real_T rtu_v, real_T
  *rty_Tfr, real_T rtp_vs, real_T rtp_Ts, real_T rtp_Tc, real_T rtp_sigma0,
  real_T rtp_iIsSig01Active, real_T rtp_sigma1, real_T rtp_sigmav,
  DW_AZDTLugreFrmode_Mount_Drv__T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S2>/AZ DT Lugre Fr mode' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* Outputs for Enabled SubSystem: '<S6>/v2z' incorporates:
     *  EnablePort: '<S10>/Enable'
     */
    /* Outputs for Enabled SubSystem: '<S6>/g(v)' incorporates:
     *  EnablePort: '<S9>/Enable'
     */
    /* Constant: '<S6>/Constant' */
    if (rtp_iIsSig01Active > 0.0) {
      /* Outputs for Enabled SubSystem: '<S9>/gs' */
      /* Constant: '<S9>/Constant' */
      Mount_Drv_FDR2023_gs(0.0, rtu_v, &localDW->Divide, rtp_vs, rtp_Ts, rtp_Tc,
                           rtp_sigma0);

      /* End of Outputs for SubSystem: '<S9>/gs' */

      /* Sum: '<S9>/Sum' incorporates:
       *  Constant: '<S9>/gc'
       */
      localDW->Sum_i = rtp_Tc / rtp_sigma0 + localDW->Divide;

      /* Sum: '<S10>/Sum' incorporates:
       *  Abs: '<S10>/Abs'
       *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
       *  Product: '<S10>/Divide'
       */
      localDW->Sum = rtu_v - fabs(rtu_v) / localDW->Sum_i *
        localDW->DiscreteTimeIntegrator_DSTATE;
    }

    /* End of Constant: '<S6>/Constant' */
    /* End of Outputs for SubSystem: '<S6>/g(v)' */
    /* End of Outputs for SubSystem: '<S6>/v2z' */

    /* Sum: '<S6>/Sum' incorporates:
     *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
     *  Gain: '<S6>/sigma_0'
     *  Gain: '<S6>/sigma_1'
     *  Gain: '<S6>/sigma_v'
     */
    *rty_Tfr = (rtp_sigma1 * localDW->Sum + rtp_sigma0 *
                localDW->DiscreteTimeIntegrator_DSTATE) + rtp_sigmav * rtu_v;

    /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_DSTATE += 0.000125 * localDW->Sum;
  }

  /* End of Outputs for SubSystem: '<S2>/AZ DT Lugre Fr mode' */
}

/*
 * Output and update for iterator system:
 *    '<S18>/For Each Subsystem'
 *    '<S19>/For Each Subsystem'
 */
void Mount_Drv_FDR2_ForEachSubsystem(int32_T NumIters, const real_T rtu_In1[8],
  real_T rty_Out1[8])
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T i;

  /* Outputs for Iterator SubSystem: '<S18>/For Each Subsystem' incorporates:
   *  ForEach: '<S22>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    real_T rtb_Out1_CoreSubsysCanOut_k;

    /* Sum: '<S22>/Sum of Elements2' */
    rtb_Out1_CoreSubsysCanOut_k = -0.0;
    for (i = 0; i < 6; i++) {
      /* Sum: '<S22>/Sum of Elements2' incorporates:
       *  ForEachSliceSelector generated from: '<S22>/In1'
       *  Sin: '<S22>/EMF  Spatial Pattern (N//A)'
       */
      rtb_Out1_CoreSubsysCanOut_k += sin(Mount_Drv_FDR2023_ConstP.pooled6[i] *
        rtu_In1[ForEach_itr] + Mount_Drv_FDR2023_ConstP.pooled7[i]) *
        Mount_Drv_FDR2023_ConstP.pooled5[i];
    }

    /* ForEachSliceAssignment generated from: '<S22>/Out1' */
    rty_Out1[ForEach_itr] = rtb_Out1_CoreSubsysCanOut_k;
  }

  /* End of Outputs for SubSystem: '<S18>/For Each Subsystem' */
}

/*
 * Output and update for iterator system:
 *    '<S18>/For Each Subsystem1'
 *    '<S19>/For Each Subsystem1'
 */
void Mount_Drv_FDR_ForEachSubsystem1(int32_T NumIters, const real_T rtu_In1[8],
  real_T rty_Out1[8])
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;

  /* Outputs for Iterator SubSystem: '<S18>/For Each Subsystem1' incorporates:
   *  ForEach: '<S23>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    /* ForEachSliceAssignment generated from: '<S23>/Out1' incorporates:
     *  ForEachSliceSelector generated from: '<S23>/In1'
     *  Sin: '<S23>/Cogging  Spatial Pattern (N)'
     *  Sum: '<S23>/Sum of Elements2'
     */
    rty_Out1[ForEach_itr] = (sin(0.033300882128051809 * rtu_In1[ForEach_itr] +
      0.8799) * 0.4854 + sin(0.067230082786821563 * rtu_In1[ForEach_itr] -
      1.9742) * 5.4809) + sin(0.13446016557364313 * rtu_In1[ForEach_itr] +
      2.2989) * 1.7897;
  }

  /* End of Outputs for SubSystem: '<S18>/For Each Subsystem1' */
}

real_T rt_roundd(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_remd(real_T u0, real_T u1)
{
  real_T y;
  if ((u1 != 0.0) && (u1 != trunc(u1))) {
    real_T q;
    q = fabs(u0 / u1);
    if (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q) {
      y = 0.0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }

  return y;
}

/* Model step function */
void Mount_Drv_FDR2023_step(RT_MODEL_Mount_Drv_FDR2023_T *const
  Mount_Drv_FDR2023_M, ExtU_Mount_Drv_FDR2023_T *Mount_Drv_FDR2023_U,
  ExtY_Mount_Drv_FDR2023_T *Mount_Drv_FDR2023_Y)
{
  DW_Mount_Drv_FDR2023_T *Mount_Drv_FDR2023_DW = Mount_Drv_FDR2023_M->dwork;

  /* local block i/o variables */
  real_T rtb_ImpAsg_InsertedFor_Out1__ke[4];
  real_T rtb_ImpAsg_InsertedFor_Out1_ke3[4];
  real_T rtb_ImpAsg_InsertedFor_Out_ke3s[8];
  real_T rtb_ImpAsg_InsertedFor_Ou_ke3sc[8];
  real_T rtb_Bias[8];
  real_T rtb_VectorConcatenate_b[8];
  real_T rtb_ImpAsg_InsertedFor_Out1_a_d[4];
  real_T rtb_ImpAsg_InsertedFor_Out1_at_[4];
  real_T rtb_VectorConcatenate_m[4];
  real_T rtb_Diff[3];
  real_T rtb_Drv_Pos_avg[3];
  real_T rtb_TSamp[3];
  real_T rtb_CoggingSpatialPatternN[2];
  real_T DiscreteTransferFcn_tmp;
  real_T rtb_Sum1_cj;
  real_T rtb_Sum1_e;
  real_T rtb_Sum1_hs;
  real_T rtb_Sum1_o;
  real_T rtb_Sum1_pw;
  real_T rtb_iIsSig01Active;
  int32_T i;
  int32_T i_0;
  int32_T i_1;
  for (i = 0; i < 3; i++) {
    /* Gain: '<S1>/Drv_Pos_avg' */
    rtb_Drv_Pos_avg[i] = 0.0;
    i_1 = 0;
    for (i_0 = 0; i_0 < 14; i_0++) {
      rtb_Drv_Pos_avg[i] += Mount_Drv_FDR2023_ConstP.Drv_Pos_avg_Gain[i_1 + i] *
        Mount_Drv_FDR2023_U->Mount_drv_Po[i_0];
      i_1 += 3;
    }

    /* SampleTimeMath: '<S3>/TSamp' incorporates:
     *  Gain: '<S1>/Drv_Pos_avg'
     *
     * About '<S3>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    DiscreteTransferFcn_tmp = rtb_Drv_Pos_avg[i] * 8000.0;

    /* Sum: '<S3>/Diff' incorporates:
     *  Gain: '<S1>/Drv_Pos_avg'
     *  UnitDelay: '<S3>/UD'
     *
     * Block description for '<S3>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S3>/UD':
     *
     *  Store in Global RAM
     */
    rtb_Diff[i] = DiscreteTransferFcn_tmp - Mount_Drv_FDR2023_DW->UD_DSTATE[i];

    /* SampleTimeMath: '<S3>/TSamp' incorporates:
     *  Gain: '<S1>/Drv_Pos_avg'
     *
     * About '<S3>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp[i] = DiscreteTransferFcn_tmp;
  }

  /* Outputs for Enabled SubSystem: '<S2>/AZ DT Lugre Fr mode' */
  /* Constant: '<S2>/Constant' */
  Mount_Drv_FDR20_AZDTLugreFrmode(1.0, rtb_Diff[0], &Mount_Drv_FDR2023_DW->Sum_d,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 203113.71617142862,
    &Mount_Drv_FDR2023_DW->AZDTLugreFrmode);

  /* End of Outputs for SubSystem: '<S2>/AZ DT Lugre Fr mode' */

  /* Outputs for Enabled SubSystem: '<S2>/EL DT Lugre Fr model' */
  /* Constant: '<S2>/Constant1' */
  Mount_Drv_FDR20_AZDTLugreFrmode(1.0, rtb_Diff[1], &Mount_Drv_FDR2023_DW->Sum_i,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 215619.25285978024,
    &Mount_Drv_FDR2023_DW->ELDTLugreFrmodel);

  /* End of Outputs for SubSystem: '<S2>/EL DT Lugre Fr model' */

  /* Outputs for Enabled SubSystem: '<S2>/GIR DT Lugre Fr model' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S15>/gs' */
  /* Constant: '<S15>/Constant' incorporates:
   *  Gain: '<S8>/iIsSig01Active'
   */
  Mount_Drv_FDR2023_gs(0.0, rtb_Diff[2], &Mount_Drv_FDR2023_DW->Divide,
                       0.00012396694214876033, 21309.20352, 17757.6696,
                       2.34256E+9);

  /* End of Outputs for SubSystem: '<S15>/gs' */

  /* Sum: '<S16>/Sum' incorporates:
   *  Abs: '<S16>/Abs'
   *  Constant: '<S15>/gc'
   *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
   *  Gain: '<S8>/iIsSig01Active'
   *  Product: '<S16>/Divide'
   *  Sum: '<S15>/Sum'
   */
  rtb_iIsSig01Active = rtb_Diff[2] - fabs(rtb_Diff[2]) /
    (Mount_Drv_FDR2023_DW->Divide + 7.5804545454545461E-6) *
    Mount_Drv_FDR2023_DW->DiscreteTimeIntegrator_DSTATE;

  /* DiscreteTransferFcn: '<S8>/Discrete Transfer Fcn' */
  DiscreteTransferFcn_tmp = (rtb_iIsSig01Active - -126.32395447351627 *
    Mount_Drv_FDR2023_DW->DiscreteTransferFcn_states) / 128.32395447351627;

  /* Sum: '<S8>/Sum' incorporates:
   *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
   *  DiscreteTransferFcn: '<S8>/Discrete Transfer Fcn'
   *  Gain: '<S8>/sigma_0'
   *  Gain: '<S8>/sigma_1'
   *  Gain: '<S8>/sigma_v'
   */
  Mount_Drv_FDR2023_DW->Sum = ((DiscreteTransferFcn_tmp +
    Mount_Drv_FDR2023_DW->DiscreteTransferFcn_states) * 3.8634489257387631E+7 +
    2.34256E+9 * Mount_Drv_FDR2023_DW->DiscreteTimeIntegrator_DSTATE) + 4450.864
    * rtb_Diff[2];

  /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
  Mount_Drv_FDR2023_DW->DiscreteTimeIntegrator_DSTATE += 0.000125 *
    rtb_iIsSig01Active;

  /* Update for DiscreteTransferFcn: '<S8>/Discrete Transfer Fcn' */
  Mount_Drv_FDR2023_DW->DiscreteTransferFcn_states = DiscreteTransferFcn_tmp;

  /* End of Outputs for SubSystem: '<S2>/GIR DT Lugre Fr model' */

  /* Delay: '<S1>/DRV delay' */
  i_1 = (int32_T)Mount_Drv_FDR2023_DW->CircBufIdx * 3;

  /* DiscreteTransferFcn: '<S1>/DRV_dyn' incorporates:
   *  Delay: '<S1>/DRV delay'
   *  Quantizer: '<S1>/DRV_quant'
   */
  DiscreteTransferFcn_tmp = rt_roundd(Mount_Drv_FDR2023_DW->DRVdelay_DSTATE[i_1]
    / 24.4140625) * 24.4140625 - -0.88235294117647056 *
    Mount_Drv_FDR2023_DW->DRV_dyn_states[0];
  rtb_Sum1_o = 0.058823529411764705 * DiscreteTransferFcn_tmp +
    0.058823529411764705 * Mount_Drv_FDR2023_DW->DRV_dyn_states[0];

  /* Saturate: '<S1>/AZ_drv_sat' incorporates:
   *  DiscreteTransferFcn: '<S1>/DRV_dyn'
   *  Quantizer: '<S1>/DRV_quant'
   */
  if (rtb_Sum1_o > 800000.0) {
    rtb_Sum1_o = 800000.0;
  } else if (rtb_Sum1_o < -800000.0) {
    rtb_Sum1_o = -800000.0;
  }

  /* DiscreteTransferFcn: '<S1>/DRV_dyn' incorporates:
   *  Delay: '<S1>/DRV delay'
   *  Quantizer: '<S1>/DRV_quant'
   */
  rtb_Sum1_pw = rt_roundd(Mount_Drv_FDR2023_DW->DRVdelay_DSTATE[i_1 + 1] /
    12.20703125) * 12.20703125 - -0.88235294117647056 *
    Mount_Drv_FDR2023_DW->DRV_dyn_states[1];
  rtb_Sum1_e = 0.058823529411764705 * rtb_Sum1_pw + 0.058823529411764705 *
    Mount_Drv_FDR2023_DW->DRV_dyn_states[1];

  /* Saturate: '<S1>/AZ_drv_sat' incorporates:
   *  DiscreteTransferFcn: '<S1>/DRV_dyn'
   *  Quantizer: '<S1>/DRV_quant'
   */
  if (rtb_Sum1_e > 400000.0) {
    rtb_Sum1_e = 400000.0;
  } else if (rtb_Sum1_e < -400000.0) {
    rtb_Sum1_e = -400000.0;
  }

  /* DiscreteTransferFcn: '<S1>/DRV_dyn' incorporates:
   *  Delay: '<S1>/DRV delay'
   *  Quantizer: '<S1>/DRV_quant'
   */
  rtb_Sum1_cj = rt_roundd(Mount_Drv_FDR2023_DW->DRVdelay_DSTATE[i_1 + 2] /
    5.7330322265625) * 5.7330322265625 - -0.88235294117647056 *
    Mount_Drv_FDR2023_DW->DRV_dyn_states[2];
  rtb_Sum1_hs = 0.058823529411764705 * rtb_Sum1_cj + 0.058823529411764705 *
    Mount_Drv_FDR2023_DW->DRV_dyn_states[2];

  /* Saturate: '<S1>/AZ_drv_sat' incorporates:
   *  DiscreteTransferFcn: '<S1>/DRV_dyn'
   *  Quantizer: '<S1>/DRV_quant'
   */
  if (rtb_Sum1_hs > 175740.0) {
    rtb_Sum1_hs = 175740.0;
  } else if (rtb_Sum1_hs < -175740.0) {
    rtb_Sum1_hs = -175740.0;
  }

  /* Update for DiscreteTransferFcn: '<S1>/DRV_dyn' */
  Mount_Drv_FDR2023_DW->DRV_dyn_states[2] = rtb_Sum1_cj;

  /* Outputs for Enabled SubSystem: '<S4>/Parasitic AZ' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  /* Gain: '<S18>/deg2mm' incorporates:
   *  Gain: '<S21>/Gain'
   */
  rtb_Sum1_cj = 57.295779513082323 * rtb_Drv_Pos_avg[0] * 163.51989761934874;

  /* Bias: '<S18>/Bias' */
  for (i = 0; i < 8; i++) {
    rtb_Bias[i] = rtb_Sum1_cj + Mount_Drv_FDR2023_ConstP.Bias_Bias[i];
  }

  /* End of Bias: '<S18>/Bias' */

  /* SignalConversion generated from: '<S18>/Vector Concatenate' */
  memcpy(&rtb_VectorConcatenate_b[0], &rtb_Bias[0], sizeof(real_T) << 3U);

  /* Outputs for Iterator SubSystem: '<S18>/For Each Subsystem' */
  Mount_Drv_FDR2_ForEachSubsystem(8, rtb_VectorConcatenate_b,
    rtb_ImpAsg_InsertedFor_Ou_ke3sc);

  /* End of Outputs for SubSystem: '<S18>/For Each Subsystem' */

  /* Gain: '<S18>/1//Kt' incorporates:
   *  Abs: '<S18>/Abs'
   *  Gain: '<S18>/1//N_segm'
   */
  rtb_iIsSig01Active = 0.125 * fabs(rtb_Sum1_o) * 0.00047014574518100609;

  /* Product: '<S18>/Divide' */
  for (i = 0; i < 8; i++) {
    rtb_Bias[i] = rtb_iIsSig01Active * rtb_ImpAsg_InsertedFor_Ou_ke3sc[i];
  }

  /* End of Product: '<S18>/Divide' */

  /* Outputs for Iterator SubSystem: '<S18>/For Each Subsystem1' */
  Mount_Drv_FDR_ForEachSubsystem1(8, rtb_VectorConcatenate_b,
    rtb_ImpAsg_InsertedFor_Out_ke3s);

  /* End of Outputs for SubSystem: '<S18>/For Each Subsystem1' */

  /* Sum: '<S18>/Sum of Elements1' incorporates:
   *  Sum: '<S18>/Sum of Elements'
   *  Sum: '<S19>/Sum of Elements'
   *  Sum: '<S19>/Sum of Elements1'
   *  Sum: '<S20>/Sum of Elements'
   *  Sum: '<S20>/Sum of Elements1'
   *  Sum: '<S26>/Sum of Elements2'
   *  Sum: '<S27>/Sum of Elements2'
   *  Sum: '<S29>/Sum of Elements'
   *  Sum: '<S30>/Sum of Elements'
   */
  rtb_Sum1_cj = -0.0;
  for (i_1 = 0; i_1 < 8; i_1++) {
    rtb_Sum1_cj += rtb_ImpAsg_InsertedFor_Out_ke3s[i_1];
  }

  /* Gain: '<S18>/R ' */
  rtb_iIsSig01Active = 9.369 * rtb_Sum1_cj;

  /* Sum: '<S18>/Sum of Elements' incorporates:
   *  Sum: '<S18>/Sum of Elements1'
   *  Sum: '<S19>/Sum of Elements'
   *  Sum: '<S19>/Sum of Elements1'
   *  Sum: '<S20>/Sum of Elements'
   *  Sum: '<S20>/Sum of Elements1'
   *  Sum: '<S26>/Sum of Elements2'
   *  Sum: '<S27>/Sum of Elements2'
   *  Sum: '<S29>/Sum of Elements'
   *  Sum: '<S30>/Sum of Elements'
   */
  rtb_Sum1_cj = -0.0;
  for (i_1 = 0; i_1 < 8; i_1++) {
    rtb_Sum1_cj += rtb_Bias[i_1];
  }

  real_T rtb_SumofElements1;

  /* Sum: '<S18>/Sum2' incorporates:
   *  Gain: '<S18>/R'
   */
  Mount_Drv_FDR2023_DW->Sum2_i = 9.369 * rtb_Sum1_cj + rtb_iIsSig01Active;

  /* End of Outputs for SubSystem: '<S4>/Parasitic AZ' */

  /* Outputs for Enabled SubSystem: '<S4>/Parasitic EL' incorporates:
   *  EnablePort: '<S19>/Enable'
   */
  /* Gain: '<S19>/deg2mm' incorporates:
   *  Gain: '<S21>/Gain'
   */
  rtb_Sum1_cj = 57.295779513082323 * rtb_Drv_Pos_avg[1] * 180.76375062905271;

  /* SignalConversion generated from: '<S19>/Vector Concatenate' incorporates:
   *  Bias: '<S19>/Bias'
   */
  rtb_VectorConcatenate_m[0] = rtb_Sum1_cj;

  /* SignalConversion generated from: '<S19>/Vector Concatenate' incorporates:
   *  Bias: '<S19>/Bias'
   */
  rtb_VectorConcatenate_m[1] = rtb_Sum1_cj + 24.3;

  /* SignalConversion generated from: '<S19>/Vector Concatenate' incorporates:
   *  Bias: '<S19>/Bias'
   */
  rtb_VectorConcatenate_m[2] = rtb_Sum1_cj;

  /* SignalConversion generated from: '<S19>/Vector Concatenate' incorporates:
   *  Bias: '<S19>/Bias'
   */
  rtb_VectorConcatenate_m[3] = rtb_Sum1_cj + 24.3;

  /* Outputs for Iterator SubSystem: '<S19>/For Each Subsystem' */
  Mount_Drv_FDR2_ForEachSubsystem(4, rtb_VectorConcatenate_m,
    rtb_ImpAsg_InsertedFor_Out1_ke3);

  /* End of Outputs for SubSystem: '<S19>/For Each Subsystem' */

  /* Gain: '<S19>/1//Kt' incorporates:
   *  Abs: '<S19>/Abs'
   *  Gain: '<S19>/1//N_segm'
   */
  rtb_Sum1_cj = 0.25 * fabs(rtb_Sum1_e) * 0.00047014574518100609;

  /* Outputs for Iterator SubSystem: '<S19>/For Each Subsystem1' */
  Mount_Drv_FDR_ForEachSubsystem1(4, rtb_VectorConcatenate_m,
    rtb_ImpAsg_InsertedFor_Out1__ke);

  /* End of Outputs for SubSystem: '<S19>/For Each Subsystem1' */

  /* Sum: '<S19>/Sum2' incorporates:
   *  Gain: '<S19>/R'
   *  Gain: '<S19>/R '
   *  Product: '<S19>/Divide'
   *  Sum: '<S19>/Sum of Elements'
   *  Sum: '<S19>/Sum of Elements1'
   */
  Mount_Drv_FDR2023_DW->Sum2_m = (((rtb_Sum1_cj *
    rtb_ImpAsg_InsertedFor_Out1_ke3[0] + rtb_Sum1_cj *
    rtb_ImpAsg_InsertedFor_Out1_ke3[1]) + rtb_Sum1_cj *
    rtb_ImpAsg_InsertedFor_Out1_ke3[2]) + rtb_Sum1_cj *
    rtb_ImpAsg_InsertedFor_Out1_ke3[3]) * 10.357 +
    (((rtb_ImpAsg_InsertedFor_Out1__ke[0] + rtb_ImpAsg_InsertedFor_Out1__ke[1])
      + rtb_ImpAsg_InsertedFor_Out1__ke[2]) + rtb_ImpAsg_InsertedFor_Out1__ke[3])
    * 10.357;

  /* End of Outputs for SubSystem: '<S4>/Parasitic EL' */

  /* Outputs for Enabled SubSystem: '<S4>/Parasitic GIR' incorporates:
   *  EnablePort: '<S20>/Enable'
   */
  /* Gain: '<S20>/ratio' incorporates:
   *  Gain: '<S21>/Gain'
   */
  rtb_Sum1_cj = 57.295779513082323 * rtb_Drv_Pos_avg[2] * 20.0;

  /* SignalConversion generated from: '<S20>/Vector Concatenate' incorporates:
   *  Bias: '<S20>/Bias'
   */
  rtb_VectorConcatenate_m[0] = rtb_Sum1_cj;

  /* SignalConversion generated from: '<S20>/Vector Concatenate' incorporates:
   *  Bias: '<S20>/Bias'
   */
  rtb_VectorConcatenate_m[1] = rtb_Sum1_cj + 0.95;

  /* SignalConversion generated from: '<S20>/Vector Concatenate' incorporates:
   *  Bias: '<S20>/Bias'
   */
  rtb_VectorConcatenate_m[2] = rtb_Sum1_cj;

  /* SignalConversion generated from: '<S20>/Vector Concatenate' incorporates:
   *  Bias: '<S20>/Bias'
   */
  rtb_VectorConcatenate_m[3] = rtb_Sum1_cj + 0.95;

  /* Gain: '<S20>/1//Kt' incorporates:
   *  Abs: '<S20>/Abs'
   *  Constant: '<S20>/PretentionTotal'
   *  Gain: '<S20>/1//N_segm'
   *  Gain: '<S20>/1//ratio   '
   *  Sum: '<S20>/Sum1'
   *  UnitDelay: '<S20>/Unit Delay2'
   */
  rtb_Sum1_cj = (fabs(Mount_Drv_FDR2023_DW->UnitDelay2_DSTATE) + 12120.0) * 0.25
    * 0.05 * 0.0097854060454238556;

  /* Outputs for Iterator SubSystem: '<S20>/For Each Subsystem' incorporates:
   *  ForEach: '<S26>/For Each'
   */
  /* ForEachSliceAssignment generated from: '<S26>/Out1' incorporates:
   *  ForEachSliceSelector generated from: '<S26>/In1'
   *  Sin: '<S26>/(N//A)'
   *  Sum: '<S26>/Sum of Elements2'
   */
  rtb_ImpAsg_InsertedFor_Out1_a_d[0] = (sin(0.83126541613985927 *
    rtb_VectorConcatenate_m[0] + 2.4103) * 0.2285 + sin(1.6625308322797185 *
    rtb_VectorConcatenate_m[0] + 0.0983) * 1.3459) + sin(2.494424566950296 *
    rtb_VectorConcatenate_m[0] - 0.1834) * 0.1234;

  /* End of Outputs for SubSystem: '<S20>/For Each Subsystem' */

  /* Product: '<S20>/Divide' */
  rtb_ImpAsg_InsertedFor_Out1_a_d[0] *= rtb_Sum1_cj;

  /* Outputs for Iterator SubSystem: '<S20>/For Each Subsystem' incorporates:
   *  ForEach: '<S26>/For Each'
   */
  /* ForEachSliceAssignment generated from: '<S26>/Out1' incorporates:
   *  ForEachSliceSelector generated from: '<S26>/In1'
   *  Sin: '<S26>/(N//A)'
   *  Sum: '<S26>/Sum of Elements2'
   */
  rtb_ImpAsg_InsertedFor_Out1_a_d[1] = (sin(0.83126541613985927 *
    rtb_VectorConcatenate_m[1] + 2.4103) * 0.2285 + sin(1.6625308322797185 *
    rtb_VectorConcatenate_m[1] + 0.0983) * 1.3459) + sin(2.494424566950296 *
    rtb_VectorConcatenate_m[1] - 0.1834) * 0.1234;

  /* End of Outputs for SubSystem: '<S20>/For Each Subsystem' */

  /* Product: '<S20>/Divide' */
  rtb_ImpAsg_InsertedFor_Out1_a_d[1] *= rtb_Sum1_cj;

  /* Outputs for Iterator SubSystem: '<S20>/For Each Subsystem' incorporates:
   *  ForEach: '<S26>/For Each'
   */
  /* ForEachSliceAssignment generated from: '<S26>/Out1' incorporates:
   *  ForEachSliceSelector generated from: '<S26>/In1'
   *  Sin: '<S26>/(N//A)'
   *  Sum: '<S26>/Sum of Elements2'
   */
  rtb_ImpAsg_InsertedFor_Out1_a_d[2] = (sin(0.83126541613985927 *
    rtb_VectorConcatenate_m[2] + 2.4103) * 0.2285 + sin(1.6625308322797185 *
    rtb_VectorConcatenate_m[2] + 0.0983) * 1.3459) + sin(2.494424566950296 *
    rtb_VectorConcatenate_m[2] - 0.1834) * 0.1234;

  /* End of Outputs for SubSystem: '<S20>/For Each Subsystem' */

  /* Product: '<S20>/Divide' */
  rtb_ImpAsg_InsertedFor_Out1_a_d[2] *= rtb_Sum1_cj;

  /* Outputs for Iterator SubSystem: '<S20>/For Each Subsystem' incorporates:
   *  ForEach: '<S26>/For Each'
   */
  /* ForEachSliceAssignment generated from: '<S26>/Out1' incorporates:
   *  ForEachSliceSelector generated from: '<S26>/In1'
   *  Sin: '<S26>/(N//A)'
   *  Sum: '<S26>/Sum of Elements2'
   */
  rtb_ImpAsg_InsertedFor_Out1_a_d[3] = (sin(0.83126541613985927 *
    rtb_VectorConcatenate_m[3] + 2.4103) * 0.2285 + sin(1.6625308322797185 *
    rtb_VectorConcatenate_m[3] + 0.0983) * 1.3459) + sin(2.494424566950296 *
    rtb_VectorConcatenate_m[3] - 0.1834) * 0.1234;

  /* End of Outputs for SubSystem: '<S20>/For Each Subsystem' */

  /* Product: '<S20>/Divide' */
  rtb_ImpAsg_InsertedFor_Out1_a_d[3] *= rtb_Sum1_cj;

  /* Outputs for Iterator SubSystem: '<S20>/For Each Subsystem1' incorporates:
   *  ForEach: '<S27>/For Each'
   */
  /* Sin: '<S27>/Cogging  Spatial Pattern (N)' incorporates:
   *  ForEachSliceSelector generated from: '<S27>/In1'
   */
  rtb_CoggingSpatialPatternN[0] = sin(1.105840614063607 *
    rtb_VectorConcatenate_m[0] + 1.1997) * 0.0053;
  rtb_CoggingSpatialPatternN[1] = sin(2.494424566950296 *
    rtb_VectorConcatenate_m[0] - 1.5093) * 0.0481;

  /* Sum: '<S27>/Sum of Elements2' */
  rtb_iIsSig01Active = rtb_CoggingSpatialPatternN[0] +
    rtb_CoggingSpatialPatternN[1];

  /* ForEachSliceAssignment generated from: '<S27>/Out1' */
  rtb_ImpAsg_InsertedFor_Out1_at_[0] = rtb_iIsSig01Active;

  /* Sin: '<S27>/Cogging  Spatial Pattern (N)' incorporates:
   *  ForEachSliceSelector generated from: '<S27>/In1'
   */
  rtb_CoggingSpatialPatternN[0] = sin(1.105840614063607 *
    rtb_VectorConcatenate_m[1] + 1.1997) * 0.0053;
  rtb_CoggingSpatialPatternN[1] = sin(2.494424566950296 *
    rtb_VectorConcatenate_m[1] - 1.5093) * 0.0481;

  /* Sum: '<S27>/Sum of Elements2' */
  rtb_iIsSig01Active = rtb_CoggingSpatialPatternN[0] +
    rtb_CoggingSpatialPatternN[1];

  /* ForEachSliceAssignment generated from: '<S27>/Out1' */
  rtb_ImpAsg_InsertedFor_Out1_at_[1] = rtb_iIsSig01Active;

  /* Sin: '<S27>/Cogging  Spatial Pattern (N)' incorporates:
   *  ForEachSliceSelector generated from: '<S27>/In1'
   */
  rtb_CoggingSpatialPatternN[0] = sin(1.105840614063607 *
    rtb_VectorConcatenate_m[2] + 1.1997) * 0.0053;
  rtb_CoggingSpatialPatternN[1] = sin(2.494424566950296 *
    rtb_VectorConcatenate_m[2] - 1.5093) * 0.0481;

  /* Sum: '<S27>/Sum of Elements2' */
  rtb_iIsSig01Active = rtb_CoggingSpatialPatternN[0] +
    rtb_CoggingSpatialPatternN[1];

  /* ForEachSliceAssignment generated from: '<S27>/Out1' */
  rtb_ImpAsg_InsertedFor_Out1_at_[2] = rtb_iIsSig01Active;

  /* Sin: '<S27>/Cogging  Spatial Pattern (N)' incorporates:
   *  ForEachSliceSelector generated from: '<S27>/In1'
   */
  rtb_CoggingSpatialPatternN[0] = sin(1.105840614063607 *
    rtb_VectorConcatenate_m[3] + 1.1997) * 0.0053;
  rtb_CoggingSpatialPatternN[1] = sin(2.494424566950296 *
    rtb_VectorConcatenate_m[3] - 1.5093) * 0.0481;

  /* Sum: '<S27>/Sum of Elements2' */
  rtb_iIsSig01Active = rtb_CoggingSpatialPatternN[0] +
    rtb_CoggingSpatialPatternN[1];

  /* ForEachSliceAssignment generated from: '<S27>/Out1' */
  rtb_ImpAsg_InsertedFor_Out1_at_[3] = rtb_iIsSig01Active;

  /* End of Outputs for SubSystem: '<S20>/For Each Subsystem1' */

  /* Sum: '<S20>/Sum2' incorporates:
   *  Gain: '<S20>/ratio '
   *  Gain: '<S20>/ratio  '
   *  Sum: '<S20>/Sum of Elements'
   *  Sum: '<S20>/Sum of Elements1'
   */
  Mount_Drv_FDR2023_DW->Sum2 = (((rtb_ImpAsg_InsertedFor_Out1_a_d[0] +
    rtb_ImpAsg_InsertedFor_Out1_a_d[1]) + rtb_ImpAsg_InsertedFor_Out1_a_d[2]) +
    rtb_ImpAsg_InsertedFor_Out1_a_d[3]) * 20.0 +
    (((rtb_ImpAsg_InsertedFor_Out1_at_[0] + rtb_ImpAsg_InsertedFor_Out1_at_[1])
      + rtb_ImpAsg_InsertedFor_Out1_at_[2]) + rtb_ImpAsg_InsertedFor_Out1_at_[3])
    * 20.0;

  /* Update for UnitDelay: '<S20>/Unit Delay2' */
  Mount_Drv_FDR2023_DW->UnitDelay2_DSTATE = rtb_Sum1_hs;

  /* End of Outputs for SubSystem: '<S4>/Parasitic GIR' */

  /* Gain: '<S30>/Gain' incorporates:
   *  Abs: '<S30>/Abs'
   *  Constant: '<S30>/PretensionTotal'
   *  Gain: '<S29>/Gain'
   *  Sum: '<S30>/Sum1'
   */
  rtb_iIsSig01Active = (fabs(rtb_Sum1_hs) + 12120.0) * 0.25;

  /* Gain: '<S28>/Gain' */
  rtb_SumofElements1 = 57.295779513082323 * rtb_Drv_Pos_avg[2];

  /* Product: '<S30>/Product1' incorporates:
   *  Constant: '<S30>/Max Position'
   *  Gain: '<S30>/Gain'
   *  Lookup_n-D: '<S30>/1-D Lookup Table'
   *  Math: '<S30>/Rem'
   *  Sum: '<S30>/Sum2'
   */
  rtb_Sum1_cj = look1_binlx(rt_remd(rtb_SumofElements1, 0.76595698841698845),
    Mount_Drv_FDR2023_ConstP.uDLookupTable_bp01Data,
    Mount_Drv_FDR2023_ConstP.uDLookupTable_tableData, 520U) * rtb_iIsSig01Active;

  /* Product: '<S29>/Product1' incorporates:
   *  Constant: '<S29>/Max Position'
   *  Lookup_n-D: '<S29>/1-D Lookup Table'
   *  Math: '<S29>/Rem'
   *  Sum: '<S30>/Sum2'
   */
  rtb_iIsSig01Active *= look1_binlx(rt_remd(rtb_SumofElements1,
    0.382978992248062), Mount_Drv_FDR2023_ConstP.uDLookupTable_bp01Data_p,
    Mount_Drv_FDR2023_ConstP.uDLookupTable_tableData_c, 260U);

  /* Sum: '<S5>/Sum1' incorporates:
   *  Product: '<S29>/Product1'
   *  Product: '<S30>/Product1'
   *  Sum: '<S29>/Sum of Elements'
   *  Sum: '<S30>/Sum of Elements'
   */
  rtb_Sum1_cj = (((rtb_iIsSig01Active + rtb_iIsSig01Active) + rtb_iIsSig01Active)
                 + rtb_iIsSig01Active) + (((rtb_Sum1_cj + rtb_Sum1_cj) +
    rtb_Sum1_cj) + rtb_Sum1_cj);

  /* Sum: '<S1>/Sum' */
  rtb_Sum1_o += Mount_Drv_FDR2023_DW->Sum2_i - Mount_Drv_FDR2023_DW->Sum_d;
  rtb_Sum1_e += Mount_Drv_FDR2023_DW->Sum2_m - Mount_Drv_FDR2023_DW->Sum_i;
  rtb_Sum1_hs += (Mount_Drv_FDR2023_DW->Sum2 - Mount_Drv_FDR2023_DW->Sum) +
    rtb_Sum1_cj;

  /* Outport: '<Root>/Mount_T' incorporates:
   *  Gain: '<S1>/Split_Drv_To'
   */
  for (i_1 = 0; i_1 < 16; i_1++) {
    Mount_Drv_FDR2023_Y->Mount_T[i_1] = 0.0;
    Mount_Drv_FDR2023_Y->Mount_T[i_1] +=
      Mount_Drv_FDR2023_ConstP.Split_Drv_To_Gain[i_1] * rtb_Sum1_o;
    Mount_Drv_FDR2023_Y->Mount_T[i_1] +=
      Mount_Drv_FDR2023_ConstP.Split_Drv_To_Gain[i_1 + 16] * rtb_Sum1_e;
    Mount_Drv_FDR2023_Y->Mount_T[i_1] +=
      Mount_Drv_FDR2023_ConstP.Split_Drv_To_Gain[i_1 + 32] * rtb_Sum1_hs;
  }

  /* End of Outport: '<Root>/Mount_T' */

  /* Outport: '<Root>/ToothCAxialFo' incorporates:
   *  Gain: '<S5>/factAxial'
   */
  Mount_Drv_FDR2023_Y->ToothCAxialFo = 0.070376984126984135 * rtb_Sum1_cj;

  /* Update for UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  Mount_Drv_FDR2023_DW->UD_DSTATE[0] = rtb_TSamp[0];

  /* Update for Delay: '<S1>/DRV delay' */
  Mount_Drv_FDR2023_DW->DRVdelay_DSTATE[(int32_T)
    Mount_Drv_FDR2023_DW->CircBufIdx * 3] = Mount_Drv_FDR2023_U->Mount_cmd[0];

  /* Update for DiscreteTransferFcn: '<S1>/DRV_dyn' */
  Mount_Drv_FDR2023_DW->DRV_dyn_states[0] = DiscreteTransferFcn_tmp;

  /* Update for UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  Mount_Drv_FDR2023_DW->UD_DSTATE[1] = rtb_TSamp[1];

  /* Update for Delay: '<S1>/DRV delay' */
  Mount_Drv_FDR2023_DW->DRVdelay_DSTATE[(int32_T)
    Mount_Drv_FDR2023_DW->CircBufIdx * 3 + 1] = Mount_Drv_FDR2023_U->Mount_cmd[1];

  /* Update for DiscreteTransferFcn: '<S1>/DRV_dyn' */
  Mount_Drv_FDR2023_DW->DRV_dyn_states[1] = rtb_Sum1_pw;

  /* Update for UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  Mount_Drv_FDR2023_DW->UD_DSTATE[2] = rtb_TSamp[2];

  /* Update for Delay: '<S1>/DRV delay' */
  Mount_Drv_FDR2023_DW->DRVdelay_DSTATE[(int32_T)
    Mount_Drv_FDR2023_DW->CircBufIdx * 3 + 2] = Mount_Drv_FDR2023_U->Mount_cmd[2];
  if (Mount_Drv_FDR2023_DW->CircBufIdx < 31U) {
    Mount_Drv_FDR2023_DW->CircBufIdx++;
  } else {
    Mount_Drv_FDR2023_DW->CircBufIdx = 0U;
  }
}

/* Model initialize function */
void Mount_Drv_FDR2023_initialize(RT_MODEL_Mount_Drv_FDR2023_T *const
  Mount_Drv_FDR2023_M)
{
  /* (no initialization code required) */
  UNUSED_PARAMETER(Mount_Drv_FDR2023_M);
}

/* Model terminate function */
void Mount_Drv_FDR2023_terminate(RT_MODEL_Mount_Drv_FDR2023_T *const
  Mount_Drv_FDR2023_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(Mount_Drv_FDR2023_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
