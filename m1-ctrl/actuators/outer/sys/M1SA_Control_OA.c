/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: M1SA_Control_OA.c
 *
 * Code generated for Simulink model 'M1SA_Control_OA'.
 *
 * Model version                  : 9.26
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Sep 25 16:23:54 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#include "M1SA_Control_OA.h"
#include "rtwtypes.h"

/* Model step function */
void M1SA_Control_OA_step(RT_MODEL_M1SA_Control_OA_T *const M1SA_Control_OA_M,
  ExtU_M1SA_Control_OA_T *M1SA_Control_OA_U, ExtY_M1SA_Control_OA_T
  *M1SA_Control_OA_Y)
{
  DW_M1SA_Control_OA_T *M1SA_Control_OA_DW = M1SA_Control_OA_M->dwork;

  /* local block i/o variables */
  real_T rtb_OA_SSdtC_Fx;
  real_T rtb_OA_SSdtC_Fy;
  real_T rtb_OA_SSdtC_Fz;
  real_T rtb_OA_SSdtC_Mx;
  real_T rtb_OA_SSdtC_My;
  real_T rtb_OA_SSdtC_Mz;
  real_T OA_SA_dyn_tmp[335];
  real_T rtb_OA_SA_dyn[335];
  real_T tmp[6];
  int32_T i;
  int32_T memOffset;

  /* DiscreteStateSpace: '<S2>/OA_SSdtC_Fx' */
  {
    rtb_OA_SSdtC_Fx = (0.28914856643816489)*
      M1SA_Control_OA_DW->OA_SSdtC_Fx_DSTATE[0]
      + (3.0386672509746151)*M1SA_Control_OA_DW->OA_SSdtC_Fx_DSTATE[1]
      + (-1.7538463618885254)*M1SA_Control_OA_DW->OA_SSdtC_Fx_DSTATE[2];
    rtb_OA_SSdtC_Fx += 0.15735299938861008*M1SA_Control_OA_U->LC_FxyzMxyz_CG[0];
  }

  /* DiscreteStateSpace: '<S2>/OA_SSdtC_Fy' */
  {
    rtb_OA_SSdtC_Fy = (0.28914856643816489)*
      M1SA_Control_OA_DW->OA_SSdtC_Fy_DSTATE[0]
      + (3.0386672509746151)*M1SA_Control_OA_DW->OA_SSdtC_Fy_DSTATE[1]
      + (-1.7538463618885254)*M1SA_Control_OA_DW->OA_SSdtC_Fy_DSTATE[2];
    rtb_OA_SSdtC_Fy += 0.15735299938861008*M1SA_Control_OA_U->LC_FxyzMxyz_CG[1];
  }

  /* DiscreteStateSpace: '<S2>/OA_SSdtC_Fz' */
  {
    rtb_OA_SSdtC_Fz = (0.28914856643816489)*
      M1SA_Control_OA_DW->OA_SSdtC_Fz_DSTATE[0]
      + (3.0386672509746151)*M1SA_Control_OA_DW->OA_SSdtC_Fz_DSTATE[1]
      + (-1.7538463618885254)*M1SA_Control_OA_DW->OA_SSdtC_Fz_DSTATE[2];
    rtb_OA_SSdtC_Fz += 0.15735299938861008*M1SA_Control_OA_U->LC_FxyzMxyz_CG[2];
  }

  /* DiscreteStateSpace: '<S2>/OA_SSdtC_Mx' */
  {
    rtb_OA_SSdtC_Mx = (0.28914856643816489)*
      M1SA_Control_OA_DW->OA_SSdtC_Mx_DSTATE[0]
      + (3.0386672509746151)*M1SA_Control_OA_DW->OA_SSdtC_Mx_DSTATE[1]
      + (-1.7538463618885254)*M1SA_Control_OA_DW->OA_SSdtC_Mx_DSTATE[2];
    rtb_OA_SSdtC_Mx += 0.15735299938861008*M1SA_Control_OA_U->LC_FxyzMxyz_CG[3];
  }

  /* DiscreteStateSpace: '<S2>/OA_SSdtC_My' */
  {
    rtb_OA_SSdtC_My = (0.28914856643816489)*
      M1SA_Control_OA_DW->OA_SSdtC_My_DSTATE[0]
      + (3.0386672509746151)*M1SA_Control_OA_DW->OA_SSdtC_My_DSTATE[1]
      + (-1.7538463618885254)*M1SA_Control_OA_DW->OA_SSdtC_My_DSTATE[2];
    rtb_OA_SSdtC_My += 0.15735299938861008*M1SA_Control_OA_U->LC_FxyzMxyz_CG[4];
  }

  /* DiscreteStateSpace: '<S2>/OA_SSdtC_Mz' */
  {
    rtb_OA_SSdtC_Mz = (0.28914856643816489)*
      M1SA_Control_OA_DW->OA_SSdtC_Mz_DSTATE[0]
      + (3.0386672509746151)*M1SA_Control_OA_DW->OA_SSdtC_Mz_DSTATE[1]
      + (-1.7538463618885254)*M1SA_Control_OA_DW->OA_SSdtC_Mz_DSTATE[2];
    rtb_OA_SSdtC_Mz += 0.15735299938861008*M1SA_Control_OA_U->LC_FxyzMxyz_CG[5];
  }

  /* SignalConversion generated from: '<S1>/OAseg_Kbal' */
  tmp[0] = rtb_OA_SSdtC_Fx;
  tmp[1] = rtb_OA_SSdtC_Fy;
  tmp[2] = rtb_OA_SSdtC_Fz;
  tmp[3] = rtb_OA_SSdtC_Mx;
  tmp[4] = rtb_OA_SSdtC_My;
  tmp[5] = rtb_OA_SSdtC_Mz;
  for (i = 0; i < 335; i++) {
    /* Gain: '<S1>/OAseg_Kbal' */
    rtb_OA_SA_dyn[i] = 0.0;
    for (memOffset = 0; memOffset < 6; memOffset++) {
      rtb_OA_SA_dyn[i] += M1SA_Control_OA_ConstP.OAseg_Kbal_Gain[335 * memOffset
        + i] * tmp[memOffset];
    }

    real_T denAccum;
    real_T denAccum_tmp;

    /* End of Gain: '<S1>/OAseg_Kbal' */

    /* DiscreteTransferFcn: '<S1>/OA_SA_dyn' incorporates:
     *  Sum: '<S1>/Add'
     */
    memOffset = i << 1;
    denAccum_tmp = M1SA_Control_OA_DW->OA_SA_dyn_states[memOffset + 1];
    denAccum = ((rtb_OA_SA_dyn[i] + M1SA_Control_OA_U->SA_offsetF_cmd[i]) -
                -1.5210003476147593 * M1SA_Control_OA_DW->
                OA_SA_dyn_states[memOffset]) - denAccum_tmp *
      0.52682602866187322;
    rtb_OA_SA_dyn[i] = (0.052407899699140649 * denAccum + -0.0059623805782654761
                        * M1SA_Control_OA_DW->OA_SA_dyn_states[memOffset]) +
      denAccum_tmp * -0.040619838073761294;

    /* Outport: '<Root>/Res_Act_F' */
    M1SA_Control_OA_Y->Res_Act_F[i] = rtb_OA_SA_dyn[i];

    /* DiscreteTransferFcn: '<S1>/OA_SA_dyn' */
    OA_SA_dyn_tmp[i] = denAccum;
  }

  /* Update for DiscreteStateSpace: '<S2>/OA_SSdtC_Fx' */
  {
    real_T xnew[3];
    xnew[0] = (1.0)*M1SA_Control_OA_DW->OA_SSdtC_Fx_DSTATE[0];
    xnew[0] += (0.17292148674958968)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[0];
    xnew[1] = (0.98253054836325338)*M1SA_Control_OA_DW->OA_SSdtC_Fx_DSTATE[1]
      + (0.017419862423114434)*M1SA_Control_OA_DW->OA_SSdtC_Fx_DSTATE[2];
    xnew[1] += (0.030154057276625131)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[0];
    xnew[2] = (-0.017419862423114451)*M1SA_Control_OA_DW->OA_SSdtC_Fx_DSTATE[1]
      + (0.72919912865743608)*M1SA_Control_OA_DW->OA_SSdtC_Fx_DSTATE[2];
    xnew[2] += (0.012378564806963714)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[0];
    (void) memcpy(&M1SA_Control_OA_DW->OA_SSdtC_Fx_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/OA_SSdtC_Fy' */
  {
    real_T xnew[3];
    xnew[0] = (1.0)*M1SA_Control_OA_DW->OA_SSdtC_Fy_DSTATE[0];
    xnew[0] += (0.17292148674958968)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[1];
    xnew[1] = (0.98253054836325338)*M1SA_Control_OA_DW->OA_SSdtC_Fy_DSTATE[1]
      + (0.017419862423114434)*M1SA_Control_OA_DW->OA_SSdtC_Fy_DSTATE[2];
    xnew[1] += (0.030154057276625131)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[1];
    xnew[2] = (-0.017419862423114451)*M1SA_Control_OA_DW->OA_SSdtC_Fy_DSTATE[1]
      + (0.72919912865743608)*M1SA_Control_OA_DW->OA_SSdtC_Fy_DSTATE[2];
    xnew[2] += (0.012378564806963714)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[1];
    (void) memcpy(&M1SA_Control_OA_DW->OA_SSdtC_Fy_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/OA_SSdtC_Fz' */
  {
    real_T xnew[3];
    xnew[0] = (1.0)*M1SA_Control_OA_DW->OA_SSdtC_Fz_DSTATE[0];
    xnew[0] += (0.17292148674958968)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[2];
    xnew[1] = (0.98253054836325338)*M1SA_Control_OA_DW->OA_SSdtC_Fz_DSTATE[1]
      + (0.017419862423114434)*M1SA_Control_OA_DW->OA_SSdtC_Fz_DSTATE[2];
    xnew[1] += (0.030154057276625131)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[2];
    xnew[2] = (-0.017419862423114451)*M1SA_Control_OA_DW->OA_SSdtC_Fz_DSTATE[1]
      + (0.72919912865743608)*M1SA_Control_OA_DW->OA_SSdtC_Fz_DSTATE[2];
    xnew[2] += (0.012378564806963714)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[2];
    (void) memcpy(&M1SA_Control_OA_DW->OA_SSdtC_Fz_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/OA_SSdtC_Mx' */
  {
    real_T xnew[3];
    xnew[0] = (1.0)*M1SA_Control_OA_DW->OA_SSdtC_Mx_DSTATE[0];
    xnew[0] += (0.17292148674958968)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[3];
    xnew[1] = (0.98253054836325338)*M1SA_Control_OA_DW->OA_SSdtC_Mx_DSTATE[1]
      + (0.017419862423114434)*M1SA_Control_OA_DW->OA_SSdtC_Mx_DSTATE[2];
    xnew[1] += (0.030154057276625131)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[3];
    xnew[2] = (-0.017419862423114451)*M1SA_Control_OA_DW->OA_SSdtC_Mx_DSTATE[1]
      + (0.72919912865743608)*M1SA_Control_OA_DW->OA_SSdtC_Mx_DSTATE[2];
    xnew[2] += (0.012378564806963714)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[3];
    (void) memcpy(&M1SA_Control_OA_DW->OA_SSdtC_Mx_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/OA_SSdtC_My' */
  {
    real_T xnew[3];
    xnew[0] = (1.0)*M1SA_Control_OA_DW->OA_SSdtC_My_DSTATE[0];
    xnew[0] += (0.17292148674958968)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[4];
    xnew[1] = (0.98253054836325338)*M1SA_Control_OA_DW->OA_SSdtC_My_DSTATE[1]
      + (0.017419862423114434)*M1SA_Control_OA_DW->OA_SSdtC_My_DSTATE[2];
    xnew[1] += (0.030154057276625131)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[4];
    xnew[2] = (-0.017419862423114451)*M1SA_Control_OA_DW->OA_SSdtC_My_DSTATE[1]
      + (0.72919912865743608)*M1SA_Control_OA_DW->OA_SSdtC_My_DSTATE[2];
    xnew[2] += (0.012378564806963714)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[4];
    (void) memcpy(&M1SA_Control_OA_DW->OA_SSdtC_My_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/OA_SSdtC_Mz' */
  {
    real_T xnew[3];
    xnew[0] = (1.0)*M1SA_Control_OA_DW->OA_SSdtC_Mz_DSTATE[0];
    xnew[0] += (0.17292148674958968)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[5];
    xnew[1] = (0.98253054836325338)*M1SA_Control_OA_DW->OA_SSdtC_Mz_DSTATE[1]
      + (0.017419862423114434)*M1SA_Control_OA_DW->OA_SSdtC_Mz_DSTATE[2];
    xnew[1] += (0.030154057276625131)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[5];
    xnew[2] = (-0.017419862423114451)*M1SA_Control_OA_DW->OA_SSdtC_Mz_DSTATE[1]
      + (0.72919912865743608)*M1SA_Control_OA_DW->OA_SSdtC_Mz_DSTATE[2];
    xnew[2] += (0.012378564806963714)*M1SA_Control_OA_U->LC_FxyzMxyz_CG[5];
    (void) memcpy(&M1SA_Control_OA_DW->OA_SSdtC_Mz_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteTransferFcn: '<S1>/OA_SA_dyn' */
  for (i = 0; i < 335; i++) {
    memOffset = i << 1;
    M1SA_Control_OA_DW->OA_SA_dyn_states[memOffset - -1] =
      M1SA_Control_OA_DW->OA_SA_dyn_states[memOffset];
    M1SA_Control_OA_DW->OA_SA_dyn_states[memOffset] = OA_SA_dyn_tmp[i];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/OA_SA_dyn' */
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
