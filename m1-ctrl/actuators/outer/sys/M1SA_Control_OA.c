/*
 * File: M1SA_Control_OA.c
 *
 * Code generated for Simulink model 'M1SA_Control_OA'.
 *
 * Model version                  : 9.6
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Apr 14 13:59:52 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "M1SA_Control_OA.h"
#include <string.h>
#include "rtwtypes.h"

/* Model step function */
void M1SA_Control_OA_step(RT_MODEL_M1SA_Control_OA_T *const M1SA_Control_OA_M,
  ExtU_M1SA_Control_OA_T *M1SA_Control_OA_U, ExtY_M1SA_Control_OA_T
  *M1SA_Control_OA_Y)
{
  DW_M1SA_Control_OA_T *M1SA_Control_OA_DW = M1SA_Control_OA_M->dwork;

  /* local block i/o variables */
  real_T rtb_Fxcontroller;
  real_T rtb_Fycontroller;
  real_T rtb_Fzcontroller;
  real_T rtb_Mxcontroller;
  real_T rtb_Mycontroller;
  real_T rtb_Mzcontroller;
  real_T OA_SA_dyn_tmp[335];
  real_T rtb_OA_SA_dyn[335];
  real_T tmp[6];
  int32_T i;
  int32_T i_0;

  /* DiscreteStateSpace: '<S2>/Fx controller' */
  {
    rtb_Fxcontroller = (-6.8610656930319749)*
      M1SA_Control_OA_DW->Fxcontroller_DSTATE[0]
      + (8.7455483888425327)*M1SA_Control_OA_DW->Fxcontroller_DSTATE[1]
      + (1.8)*M1SA_Control_OA_DW->Fxcontroller_DSTATE[2];
    rtb_Fxcontroller += 0.024370329855613257*M1SA_Control_OA_U->LC_FxyzMxyz_CG[0];
  }

  /* DiscreteStateSpace: '<S2>/Fy controller' */
  {
    rtb_Fycontroller = (-6.8610656930319749)*
      M1SA_Control_OA_DW->Fycontroller_DSTATE[0]
      + (8.7455483888425327)*M1SA_Control_OA_DW->Fycontroller_DSTATE[1]
      + (1.8)*M1SA_Control_OA_DW->Fycontroller_DSTATE[2];
    rtb_Fycontroller += 0.024370329855613257*M1SA_Control_OA_U->LC_FxyzMxyz_CG[1];
  }

  /* DiscreteStateSpace: '<S2>/Fz controller' */
  {
    rtb_Fzcontroller = (-11.022867857707155)*
      M1SA_Control_OA_DW->Fzcontroller_DSTATE[0]
      + (14.667973716577512)*M1SA_Control_OA_DW->Fzcontroller_DSTATE[1]
      + (2.4)*M1SA_Control_OA_DW->Fzcontroller_DSTATE[2];
    rtb_Fzcontroller += 0.025354461628138772*M1SA_Control_OA_U->LC_FxyzMxyz_CG[2];
  }

  /* DiscreteStateSpace: '<S2>/Mx controller' */
  {
    rtb_Mxcontroller = (-10.04307867717106)*
      M1SA_Control_OA_DW->Mxcontroller_DSTATE[0]
      + (10.41998468921483)*M1SA_Control_OA_DW->Mxcontroller_DSTATE[1]
      + (2.0)*M1SA_Control_OA_DW->Mxcontroller_DSTATE[2];
    rtb_Mxcontroller += 0.024505707216075836*M1SA_Control_OA_U->LC_FxyzMxyz_CG[3];
  }

  /* DiscreteStateSpace: '<S2>/My controller' */
  {
    rtb_Mycontroller = (-10.04307867717106)*
      M1SA_Control_OA_DW->Mycontroller_DSTATE[0]
      + (10.41998468921483)*M1SA_Control_OA_DW->Mycontroller_DSTATE[1]
      + (2.0)*M1SA_Control_OA_DW->Mycontroller_DSTATE[2];
    rtb_Mycontroller += 0.024505707216075836*M1SA_Control_OA_U->LC_FxyzMxyz_CG[4];
  }

  /* DiscreteStateSpace: '<S2>/Mz controller' */
  {
    rtb_Mzcontroller = (-9.4551745922133)*
      M1SA_Control_OA_DW->Mzcontroller_DSTATE[0]
      + (11.4653232391471)*M1SA_Control_OA_DW->Mzcontroller_DSTATE[1]
      + (2.0)*M1SA_Control_OA_DW->Mzcontroller_DSTATE[2];
    rtb_Mzcontroller += 0.022969235998287648*M1SA_Control_OA_U->LC_FxyzMxyz_CG[5];
  }

  /* SignalConversion generated from: '<S1>/OAseg_Kbal' */
  tmp[0] = rtb_Fxcontroller;
  tmp[1] = rtb_Fycontroller;
  tmp[2] = rtb_Fzcontroller;
  tmp[3] = rtb_Mxcontroller;
  tmp[4] = rtb_Mycontroller;
  tmp[5] = rtb_Mzcontroller;
  for (i = 0; i < 335; i++) {
    int32_T tmp_0;

    /* Gain: '<S1>/OAseg_Kbal' */
    rtb_OA_SA_dyn[i] = 0.0;
    tmp_0 = 0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_OA_SA_dyn[i] += M1SA_Control_OA_ConstP.OAseg_Kbal_Gain[tmp_0 + i] *
        tmp[i_0];
      tmp_0 += 335;
    }

    real_T denAccum;

    /* DiscreteTransferFcn: '<S1>/OA_SA_dyn' incorporates:
     *  Gain: '<S1>/OAseg_Kbal'
     *  Sum: '<S1>/Add'
     */
    denAccum = (rtb_OA_SA_dyn[i] + M1SA_Control_OA_U->SA_offsetF_cmd[i]) -
      -0.53348809109110329 * M1SA_Control_OA_DW->OA_SA_dyn_states[i];
    rtb_OA_SA_dyn[i] = 0.25752323685913081 * denAccum + 0.20898867204976596 *
      M1SA_Control_OA_DW->OA_SA_dyn_states[i];

    /* Outport: '<Root>/Res_Act_F' incorporates:
     *  Gain: '<S1>/OAseg_Kbal'
     */
    M1SA_Control_OA_Y->Res_Act_F[i] = rtb_OA_SA_dyn[i];

    /* DiscreteTransferFcn: '<S1>/OA_SA_dyn' incorporates:
     *  Gain: '<S1>/OAseg_Kbal'
     */
    OA_SA_dyn_tmp[i] = denAccum;
  }

  /* Update for DiscreteStateSpace: '<S2>/Fx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.569006949265765)*M1SA_Control_OA_DW->Fxcontroller_DSTATE[0]
      + (-0.010082811221333178)*M1SA_Control_OA_DW->Fxcontroller_DSTATE[1]
      + (0.10624490391424918)*M1SA_Control_OA_DW->Fxcontroller_DSTATE[2];
    xnew[0] += (0.0041005206649182965)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[0];
    xnew[1] = (0.69153586838988734)*M1SA_Control_OA_DW->Fxcontroller_DSTATE[0]
      + (0.40200245095801357)*M1SA_Control_OA_DW->Fxcontroller_DSTATE[1]
      + (-0.053834780381561032)*M1SA_Control_OA_DW->Fxcontroller_DSTATE[2];
    xnew[1] += (-0.0018292791104672012)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[0];
    xnew[2] = (1.0)*M1SA_Control_OA_DW->Fxcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[0];
    (void) memcpy(&M1SA_Control_OA_DW->Fxcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Fy controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.569006949265765)*M1SA_Control_OA_DW->Fycontroller_DSTATE[0]
      + (-0.010082811221333178)*M1SA_Control_OA_DW->Fycontroller_DSTATE[1]
      + (0.10624490391424918)*M1SA_Control_OA_DW->Fycontroller_DSTATE[2];
    xnew[0] += (0.0041005206649182965)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[1];
    xnew[1] = (0.69153586838988734)*M1SA_Control_OA_DW->Fycontroller_DSTATE[0]
      + (0.40200245095801357)*M1SA_Control_OA_DW->Fycontroller_DSTATE[1]
      + (-0.053834780381561032)*M1SA_Control_OA_DW->Fycontroller_DSTATE[2];
    xnew[1] += (-0.0018292791104672012)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[1];
    xnew[2] = (1.0)*M1SA_Control_OA_DW->Fycontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[1];
    (void) memcpy(&M1SA_Control_OA_DW->Fycontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Fz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.3222450105115563)*M1SA_Control_OA_DW->Fzcontroller_DSTATE[0]
      + (-0.013311547842537916)*M1SA_Control_OA_DW->Fzcontroller_DSTATE[1]
      + (0.13664330677325981)*M1SA_Control_OA_DW->Fzcontroller_DSTATE[2];
    xnew[0] += (0.005170012950170496)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[2];
    xnew[1] = (0.66124884843011622)*M1SA_Control_OA_DW->Fzcontroller_DSTATE[0]
      + (0.13460444259831861)*M1SA_Control_OA_DW->Fzcontroller_DSTATE[1]
      + (-0.0021677560864410178)*M1SA_Control_OA_DW->Fzcontroller_DSTATE[2];
    xnew[1] += (6.2680779829775045E-5)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[2];
    xnew[2] = (1.0)*M1SA_Control_OA_DW->Fzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[2];
    (void) memcpy(&M1SA_Control_OA_DW->Fzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Mx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.29778010884776307)*M1SA_Control_OA_DW->Mxcontroller_DSTATE[0]
      + (0.71505921377142712)*M1SA_Control_OA_DW->Mxcontroller_DSTATE[1]
      + (-0.0021601236457374955)*M1SA_Control_OA_DW->Mxcontroller_DSTATE[2];
    xnew[0] += (-0.0002611760862334543)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[3];
    xnew[1] = (-0.00024258661738509193)*M1SA_Control_OA_DW->Mxcontroller_DSTATE
      [0]
      + (0.27143897782429549)*M1SA_Control_OA_DW->Mxcontroller_DSTATE[1]
      + (-0.11649383326807114)*M1SA_Control_OA_DW->Mxcontroller_DSTATE[2];
    xnew[1] += (-0.0043992827840101858)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[3];
    xnew[2] = (1.0)*M1SA_Control_OA_DW->Mxcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[3];
    (void) memcpy(&M1SA_Control_OA_DW->Mxcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/My controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.29778010884776307)*M1SA_Control_OA_DW->Mycontroller_DSTATE[0]
      + (0.71505921377142712)*M1SA_Control_OA_DW->Mycontroller_DSTATE[1]
      + (-0.0021601236457374955)*M1SA_Control_OA_DW->Mycontroller_DSTATE[2];
    xnew[0] += (-0.0002611760862334543)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[4];
    xnew[1] = (-0.00024258661738509193)*M1SA_Control_OA_DW->Mycontroller_DSTATE
      [0]
      + (0.27143897782429549)*M1SA_Control_OA_DW->Mycontroller_DSTATE[1]
      + (-0.11649383326807114)*M1SA_Control_OA_DW->Mycontroller_DSTATE[2];
    xnew[1] += (-0.0043992827840101858)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[4];
    xnew[2] = (1.0)*M1SA_Control_OA_DW->Mycontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[4];
    (void) memcpy(&M1SA_Control_OA_DW->Mycontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Mz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.38195738947508884)*M1SA_Control_OA_DW->Mzcontroller_DSTATE[0]
      + (0.72039580968966876)*M1SA_Control_OA_DW->Mzcontroller_DSTATE[1]
      + (-0.0047245815737020904)*M1SA_Control_OA_DW->Mzcontroller_DSTATE[2];
    xnew[0] += (-0.0003904936834638426)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[5];
    xnew[1] = (-0.0066509471364728252)*M1SA_Control_OA_DW->Mzcontroller_DSTATE[0]
      + (0.24351874678335261)*M1SA_Control_OA_DW->Mzcontroller_DSTATE[1]
      + (-0.12438032071830714)*M1SA_Control_OA_DW->Mzcontroller_DSTATE[2];
    xnew[1] += (-0.0046882022587151594)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[5];
    xnew[2] = (1.0)*M1SA_Control_OA_DW->Mzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[5];
    (void) memcpy(&M1SA_Control_OA_DW->Mzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteTransferFcn: '<S1>/OA_SA_dyn' */
  memcpy(&M1SA_Control_OA_DW->OA_SA_dyn_states[0], &OA_SA_dyn_tmp[0], 335U *
         sizeof(real_T));
}

/* Model initialize function */
void M1SA_Control_OA_initialize(RT_MODEL_M1SA_Control_OA_T *const
  M1SA_Control_OA_M)
{
  /* (no initialization code required) */
  UNUSED_PARAMETER(M1SA_Control_OA_M);
}

/* Model terminate function */
void M1SA_Control_OA_terminate(RT_MODEL_M1SA_Control_OA_T *const
  M1SA_Control_OA_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(M1SA_Control_OA_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
