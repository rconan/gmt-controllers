/*
 * File: M1SA_Control_CS.c
 *
 * Code generated for Simulink model 'M1SA_Control_CS'.
 *
 * Model version                  : 5.28
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Jan 24 16:48:50 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M1SA_Control_CS.h"
#include "M1SA_Control_CS_private.h"

/* Model step function */
void M1SA_Control_CS_step(RT_MODEL_M1SA_Control_CS_T *const M1SA_Control_CS_M,
  ExtU_M1SA_Control_CS_T *M1SA_Control_CS_U, ExtY_M1SA_Control_CS_T
  *M1SA_Control_CS_Y)
{
  DW_M1SA_Control_CS_T *M1SA_Control_CS_DW = M1SA_Control_CS_M->dwork;

  /* local block i/o variables */
  real_T rtb_Fxcontroller;
  real_T rtb_Fycontroller;
  real_T rtb_Fzcontroller;
  real_T rtb_Mxcontroller;
  real_T rtb_Mycontroller;
  real_T rtb_Mzcontroller;
  real_T CS_SA_dyn_tmp[306];
  real_T rtb_CS_SA_dyn[306];
  real_T tmp[6];
  real_T denAccum;
  int32_T i;
  int32_T i_0;
  int32_T tmp_0;

  /* DiscreteStateSpace: '<S2>/Fx controller' incorporates:
   *  Inport: '<Root>/LC_FxyzMxyz_CG'
   */
  {
    rtb_Fxcontroller = (-6.8610656930319749)*
      M1SA_Control_CS_DW->Fxcontroller_DSTATE[0]
      + (8.7455483888425327)*M1SA_Control_CS_DW->Fxcontroller_DSTATE[1]
      + (1.8)*M1SA_Control_CS_DW->Fxcontroller_DSTATE[2];
    rtb_Fxcontroller += 0.024370329855613257*M1SA_Control_CS_U->LC_FxyzMxyz_CG[0];
  }

  /* DiscreteStateSpace: '<S2>/Fy controller' incorporates:
   *  Inport: '<Root>/LC_FxyzMxyz_CG'
   */
  {
    rtb_Fycontroller = (-6.8610656930319749)*
      M1SA_Control_CS_DW->Fycontroller_DSTATE[0]
      + (8.7455483888425327)*M1SA_Control_CS_DW->Fycontroller_DSTATE[1]
      + (1.8)*M1SA_Control_CS_DW->Fycontroller_DSTATE[2];
    rtb_Fycontroller += 0.024370329855613257*M1SA_Control_CS_U->LC_FxyzMxyz_CG[1];
  }

  /* DiscreteStateSpace: '<S2>/Fz controller' incorporates:
   *  Inport: '<Root>/LC_FxyzMxyz_CG'
   */
  {
    rtb_Fzcontroller = (-11.624022612778809)*
      M1SA_Control_CS_DW->Fzcontroller_DSTATE[0]
      + (13.310955668383137)*M1SA_Control_CS_DW->Fzcontroller_DSTATE[1]
      + (2.4)*M1SA_Control_CS_DW->Fzcontroller_DSTATE[2];
    rtb_Fzcontroller += 0.026005628588130471*M1SA_Control_CS_U->LC_FxyzMxyz_CG[2];
  }

  /* DiscreteStateSpace: '<S2>/Mx controller' incorporates:
   *  Inport: '<Root>/LC_FxyzMxyz_CG'
   */
  {
    rtb_Mxcontroller = (10.799355933329354)*
      M1SA_Control_CS_DW->Mxcontroller_DSTATE[0]
      + (-10.162942348382657)*M1SA_Control_CS_DW->Mxcontroller_DSTATE[1]
      + (2.0)*M1SA_Control_CS_DW->Mxcontroller_DSTATE[2];
    rtb_Mxcontroller += 0.024170972941162164*M1SA_Control_CS_U->LC_FxyzMxyz_CG[3];
  }

  /* DiscreteStateSpace: '<S2>/My controller' incorporates:
   *  Inport: '<Root>/LC_FxyzMxyz_CG'
   */
  {
    rtb_Mycontroller = (10.799355933329354)*
      M1SA_Control_CS_DW->Mycontroller_DSTATE[0]
      + (-10.162942348382657)*M1SA_Control_CS_DW->Mycontroller_DSTATE[1]
      + (2.0)*M1SA_Control_CS_DW->Mycontroller_DSTATE[2];
    rtb_Mycontroller += 0.024170972941162164*M1SA_Control_CS_U->LC_FxyzMxyz_CG[4];
  }

  /* DiscreteStateSpace: '<S2>/Mz controller' incorporates:
   *  Inport: '<Root>/LC_FxyzMxyz_CG'
   */
  {
    rtb_Mzcontroller = (-9.8843504316129263)*
      M1SA_Control_CS_DW->Mzcontroller_DSTATE[0]
      + (11.363212843833221)*M1SA_Control_CS_DW->Mzcontroller_DSTATE[1]
      + (2.0)*M1SA_Control_CS_DW->Mzcontroller_DSTATE[2];
    rtb_Mzcontroller += 0.022749965907501887*M1SA_Control_CS_U->LC_FxyzMxyz_CG[5];
  }

  /* SignalConversion generated from: '<S1>/CS_Kbal' */
  tmp[0] = rtb_Fxcontroller;
  tmp[1] = rtb_Fycontroller;
  tmp[2] = rtb_Fzcontroller;
  tmp[3] = rtb_Mxcontroller;
  tmp[4] = rtb_Mycontroller;
  tmp[5] = rtb_Mzcontroller;
  for (i = 0; i < 306; i++) {
    /* Gain: '<S1>/CS_Kbal' */
    rtb_CS_SA_dyn[i] = 0.0;
    tmp_0 = 0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_CS_SA_dyn[i] += M1SA_Control_CS_ConstP.CS_Kbal_Gain[tmp_0 + i] *
        tmp[i_0];
      tmp_0 += 306;
    }

    /* DiscreteTransferFcn: '<S1>/CS_SA_dyn' incorporates:
     *  Gain: '<S1>/CS_Kbal'
     *  Inport: '<Root>/SA_offsetF_cmd'
     *  Sum: '<S1>/Add'
     */
    denAccum = (rtb_CS_SA_dyn[i] + M1SA_Control_CS_U->SA_offsetF_cmd[i]) -
      -0.53348809109110329 * M1SA_Control_CS_DW->CS_SA_dyn_states[i];
    CS_SA_dyn_tmp[i] = denAccum;
    denAccum *= 0.25752323685913081;
    rtb_CS_SA_dyn[i] = 0.20898867204976596 *
      M1SA_Control_CS_DW->CS_SA_dyn_states[i] + denAccum;

    /* Outport: '<Root>/Res_Act_F' incorporates:
     *  Gain: '<S1>/CS_Kbal'
     */
    M1SA_Control_CS_Y->Res_Act_F[i] = rtb_CS_SA_dyn[i];
  }

  /* Update for DiscreteStateSpace: '<S2>/Fx controller' incorporates:
   *  Inport: '<Root>/LC_FxyzMxyz_CG'
   */
  {
    real_T xnew[3];
    xnew[0] = (0.569006949265765)*M1SA_Control_CS_DW->Fxcontroller_DSTATE[0]
      + (-0.010082811221333178)*M1SA_Control_CS_DW->Fxcontroller_DSTATE[1]
      + (0.10624490391424918)*M1SA_Control_CS_DW->Fxcontroller_DSTATE[2];
    xnew[0] += (0.0041005206649182965)*M1SA_Control_CS_U->LC_FxyzMxyz_CG[0];
    xnew[1] = (0.69153586838988734)*M1SA_Control_CS_DW->Fxcontroller_DSTATE[0]
      + (0.40200245095801357)*M1SA_Control_CS_DW->Fxcontroller_DSTATE[1]
      + (-0.053834780381561032)*M1SA_Control_CS_DW->Fxcontroller_DSTATE[2];
    xnew[1] += (-0.0018292791104672012)*M1SA_Control_CS_U->LC_FxyzMxyz_CG[0];
    xnew[2] = (1.0)*M1SA_Control_CS_DW->Fxcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*M1SA_Control_CS_U->LC_FxyzMxyz_CG[0];
    (void) memcpy(&M1SA_Control_CS_DW->Fxcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Fy controller' incorporates:
   *  Inport: '<Root>/LC_FxyzMxyz_CG'
   */
  {
    real_T xnew[3];
    xnew[0] = (0.569006949265765)*M1SA_Control_CS_DW->Fycontroller_DSTATE[0]
      + (-0.010082811221333178)*M1SA_Control_CS_DW->Fycontroller_DSTATE[1]
      + (0.10624490391424918)*M1SA_Control_CS_DW->Fycontroller_DSTATE[2];
    xnew[0] += (0.0041005206649182965)*M1SA_Control_CS_U->LC_FxyzMxyz_CG[1];
    xnew[1] = (0.69153586838988734)*M1SA_Control_CS_DW->Fycontroller_DSTATE[0]
      + (0.40200245095801357)*M1SA_Control_CS_DW->Fycontroller_DSTATE[1]
      + (-0.053834780381561032)*M1SA_Control_CS_DW->Fycontroller_DSTATE[2];
    xnew[1] += (-0.0018292791104672012)*M1SA_Control_CS_U->LC_FxyzMxyz_CG[1];
    xnew[2] = (1.0)*M1SA_Control_CS_DW->Fycontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*M1SA_Control_CS_U->LC_FxyzMxyz_CG[1];
    (void) memcpy(&M1SA_Control_CS_DW->Fycontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Fz controller' incorporates:
   *  Inport: '<Root>/LC_FxyzMxyz_CG'
   */
  {
    real_T xnew[3];
    xnew[0] = (0.30106701605566388)*M1SA_Control_CS_DW->Fzcontroller_DSTATE[0]
      + (-0.0031724351959647483)*M1SA_Control_CS_DW->Fzcontroller_DSTATE[1]
      + (0.13638180429146246)*M1SA_Control_CS_DW->Fzcontroller_DSTATE[2];
    xnew[0] += (0.0051578505311074812)*M1SA_Control_CS_U->LC_FxyzMxyz_CG[2];
    xnew[1] = (0.69313056645168991)*M1SA_Control_CS_DW->Fzcontroller_DSTATE[0]
      + (0.20728190413675973)*M1SA_Control_CS_DW->Fzcontroller_DSTATE[1]
      + (-0.00017021067138704422)*M1SA_Control_CS_DW->Fzcontroller_DSTATE[2];
    xnew[1] += (0.00017169440437669837)*M1SA_Control_CS_U->LC_FxyzMxyz_CG[2];
    xnew[2] = (1.0)*M1SA_Control_CS_DW->Fzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*M1SA_Control_CS_U->LC_FxyzMxyz_CG[2];
    (void) memcpy(&M1SA_Control_CS_DW->Fzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Mx controller' incorporates:
   *  Inport: '<Root>/LC_FxyzMxyz_CG'
   */
  {
    real_T xnew[3];
    xnew[0] = (0.24588323456423145)*M1SA_Control_CS_DW->Mxcontroller_DSTATE[0]
      + (0.70467842450269291)*M1SA_Control_CS_DW->Mxcontroller_DSTATE[1]
      + (0.00081808803127935586)*M1SA_Control_CS_DW->Mxcontroller_DSTATE[2];
    xnew[0] += (0.0001958178153803155)*M1SA_Control_CS_U->LC_FxyzMxyz_CG[3];
    xnew[1] = (-0.00064951930680839346)*M1SA_Control_CS_DW->Mxcontroller_DSTATE
      [0]
      + (0.28867118809350589)*M1SA_Control_CS_DW->Mxcontroller_DSTATE[1]
      + (0.11653922223015478)*M1SA_Control_CS_DW->Mxcontroller_DSTATE[2];
    xnew[1] += (0.0044051041445438335)*M1SA_Control_CS_U->LC_FxyzMxyz_CG[3];
    xnew[2] = (1.0)*M1SA_Control_CS_DW->Mxcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*M1SA_Control_CS_U->LC_FxyzMxyz_CG[3];
    (void) memcpy(&M1SA_Control_CS_DW->Mxcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/My controller' incorporates:
   *  Inport: '<Root>/LC_FxyzMxyz_CG'
   */
  {
    real_T xnew[3];
    xnew[0] = (0.24588323456423145)*M1SA_Control_CS_DW->Mycontroller_DSTATE[0]
      + (0.70467842450269291)*M1SA_Control_CS_DW->Mycontroller_DSTATE[1]
      + (0.00081808803127935586)*M1SA_Control_CS_DW->Mycontroller_DSTATE[2];
    xnew[0] += (0.0001958178153803155)*M1SA_Control_CS_U->LC_FxyzMxyz_CG[4];
    xnew[1] = (-0.00064951930680839346)*M1SA_Control_CS_DW->Mycontroller_DSTATE
      [0]
      + (0.28867118809350589)*M1SA_Control_CS_DW->Mycontroller_DSTATE[1]
      + (0.11653922223015478)*M1SA_Control_CS_DW->Mycontroller_DSTATE[2];
    xnew[1] += (0.0044051041445438335)*M1SA_Control_CS_U->LC_FxyzMxyz_CG[4];
    xnew[2] = (1.0)*M1SA_Control_CS_DW->Mycontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*M1SA_Control_CS_U->LC_FxyzMxyz_CG[4];
    (void) memcpy(&M1SA_Control_CS_DW->Mycontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Mz controller' incorporates:
   *  Inport: '<Root>/LC_FxyzMxyz_CG'
   */
  {
    real_T xnew[3];
    xnew[0] = (0.35318690302308442)*M1SA_Control_CS_DW->Mzcontroller_DSTATE[0]
      + (0.72011465131225016)*M1SA_Control_CS_DW->Mzcontroller_DSTATE[1]
      + (-0.0038868874920811995)*M1SA_Control_CS_DW->Mzcontroller_DSTATE[2];
    xnew[0] += (-0.00035257232440118766)*M1SA_Control_CS_U->LC_FxyzMxyz_CG[5];
    xnew[1] = (-0.0034885015967498082)*M1SA_Control_CS_DW->Mzcontroller_DSTATE[0]
      + (0.25294477393664205)*M1SA_Control_CS_DW->Mzcontroller_DSTATE[1]
      + (-0.12437198598757732)*M1SA_Control_CS_DW->Mzcontroller_DSTATE[2];
    xnew[1] += (-0.004691124684434827)*M1SA_Control_CS_U->LC_FxyzMxyz_CG[5];
    xnew[2] = (1.0)*M1SA_Control_CS_DW->Mzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*M1SA_Control_CS_U->LC_FxyzMxyz_CG[5];
    (void) memcpy(&M1SA_Control_CS_DW->Mzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteTransferFcn: '<S1>/CS_SA_dyn' */
  memcpy(&M1SA_Control_CS_DW->CS_SA_dyn_states[0], &CS_SA_dyn_tmp[0], 306U *
         sizeof(real_T));
}

/* Model initialize function */
void M1SA_Control_CS_initialize(RT_MODEL_M1SA_Control_CS_T *const
  M1SA_Control_CS_M, ExtU_M1SA_Control_CS_T *M1SA_Control_CS_U,
  ExtY_M1SA_Control_CS_T *M1SA_Control_CS_Y)
{
  DW_M1SA_Control_CS_T *M1SA_Control_CS_DW = M1SA_Control_CS_M->dwork;

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)M1SA_Control_CS_DW, 0,
                sizeof(DW_M1SA_Control_CS_T));

  /* external inputs */
  (void)memset(M1SA_Control_CS_U, 0, sizeof(ExtU_M1SA_Control_CS_T));

  /* external outputs */
  (void) memset(&M1SA_Control_CS_Y->Res_Act_F[0], 0,
                306U*sizeof(real_T));
}

/* Model terminate function */
void M1SA_Control_CS_terminate(RT_MODEL_M1SA_Control_CS_T *const
  M1SA_Control_CS_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(M1SA_Control_CS_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
