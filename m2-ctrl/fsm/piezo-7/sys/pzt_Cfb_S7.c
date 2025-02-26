/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pzt_Cfb_S7.c
 *
 * Code generated for Simulink model 'pzt_Cfb_S7'.
 *
 * Model version                  : 9.12
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Feb 26 14:46:24 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#include "pzt_Cfb_S7.h"
#include "rtwtypes.h"

/* Model step function */
void pzt_Cfb_S7_step(RT_MODEL_pzt_Cfb_S7_T *const pzt_Cfb_S7_M,
                     ExtU_pzt_Cfb_S7_T *pzt_Cfb_S7_U, ExtY_pzt_Cfb_S7_T
                     *pzt_Cfb_S7_Y)
{
  DW_pzt_Cfb_S7_T *pzt_Cfb_S7_DW = pzt_Cfb_S7_M->dwork;

  /* local block i/o variables */
  real_T rtb_fsm_Cfb_act1;
  real_T rtb_fsm_Cfb_act2;
  real_T rtb_fsm_Cfb_act3;

  /* DiscreteStateSpace: '<S1>/fsm_Cfb_act1' */
  {
    rtb_fsm_Cfb_act1 = (1792.4160535515714)*pzt_Cfb_S7_DW->fsm_Cfb_act1_DSTATE[0]
      + (1282.6182631360693)*pzt_Cfb_S7_DW->fsm_Cfb_act1_DSTATE[1]
      + (-445.20254803033822)*pzt_Cfb_S7_DW->fsm_Cfb_act1_DSTATE[2]
      + (-134.91895164674793)*pzt_Cfb_S7_DW->fsm_Cfb_act1_DSTATE[3];
    rtb_fsm_Cfb_act1 += 173159.13265436474*pzt_Cfb_S7_U->pzt_error[0];
  }

  /* DiscreteStateSpace: '<S1>/fsm_Cfb_act2' */
  {
    {
      static const int_T colCidxRow0[6] = { 0, 1, 2, 3, 4, 5 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = pzt_Cfb_S7_ConstP.fsm_Cfb_act2_C;
      const real_T *xd = &pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[0];
      real_T *y0 = &rtb_fsm_Cfb_act2;
      int_T numNonZero = 5;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_fsm_Cfb_act2 += 137876.56582902896*pzt_Cfb_S7_U->pzt_error[1];
  }

  /* DiscreteStateSpace: '<S1>/fsm_Cfb_act3' */
  {
    rtb_fsm_Cfb_act3 = (1792.4160535515714)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[0]
      + (1270.1957308562396)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[1]
      + (437.16703540404296)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[2]
      + (-155.0503525936175)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[3];
    rtb_fsm_Cfb_act3 += 170864.20553097979*pzt_Cfb_S7_U->pzt_error[2];
  }

  /* Outport: '<Root>/pzt_control' */
  pzt_Cfb_S7_Y->pzt_control[0] = rtb_fsm_Cfb_act1;
  pzt_Cfb_S7_Y->pzt_control[1] = rtb_fsm_Cfb_act2;
  pzt_Cfb_S7_Y->pzt_control[2] = rtb_fsm_Cfb_act3;

  /* Update for DiscreteStateSpace: '<S1>/fsm_Cfb_act1' */
  {
    real_T xnew[4];
    xnew[0] = (1.0)*pzt_Cfb_S7_DW->fsm_Cfb_act1_DSTATE[0];
    xnew[0] += (1023.9999999999994)*pzt_Cfb_S7_U->pzt_error[0];
    xnew[1] = (0.831984231596302)*pzt_Cfb_S7_DW->fsm_Cfb_act1_DSTATE[1]
      + (0.13773951362369624)*pzt_Cfb_S7_DW->fsm_Cfb_act1_DSTATE[2]
      + (0.033248462288313227)*pzt_Cfb_S7_DW->fsm_Cfb_act1_DSTATE[3];
    xnew[1] += (-1282.6182631360693)*pzt_Cfb_S7_U->pzt_error[0];
    xnew[2] = (-0.13773951362369627)*pzt_Cfb_S7_DW->fsm_Cfb_act1_DSTATE[1]
      + (0.63982700974886286)*pzt_Cfb_S7_DW->fsm_Cfb_act1_DSTATE[2]
      + (-0.30757002934736644)*pzt_Cfb_S7_DW->fsm_Cfb_act1_DSTATE[3];
    xnew[2] += (-445.20254803033816)*pzt_Cfb_S7_U->pzt_error[0];
    xnew[3] = (0.033248462288313095)*pzt_Cfb_S7_DW->fsm_Cfb_act1_DSTATE[1]
      + (0.30757002934736666)*pzt_Cfb_S7_DW->fsm_Cfb_act1_DSTATE[2]
      + (0.56336617061009242)*pzt_Cfb_S7_DW->fsm_Cfb_act1_DSTATE[3];
    xnew[3] += (134.91895164674804)*pzt_Cfb_S7_U->pzt_error[0];
    (void) memcpy(&pzt_Cfb_S7_DW->fsm_Cfb_act1_DSTATE[0], xnew,
                  sizeof(real_T)*4);
  }

  /* Update for DiscreteStateSpace: '<S1>/fsm_Cfb_act2' */
  {
    real_T xnew[6];
    xnew[0] = (1.0)*pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[0];
    xnew[0] += (1024.0)*pzt_Cfb_S7_U->pzt_error[1];

    {
      static const int_T colAidxRow1[5] = { 1, 2, 3, 4, 5 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA1 = &pzt_Cfb_S7_ConstP.fsm_Cfb_act2_A[1];
      const real_T *xd = &pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 4;
      *pxnew1 = (*pA1++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA1++) * xd[*pAidx++];
      }
    }

    xnew[1] += (1285.6060021703443)*pzt_Cfb_S7_U->pzt_error[1];

    {
      static const int_T colAidxRow2[5] = { 1, 2, 3, 4, 5 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA6 = &pzt_Cfb_S7_ConstP.fsm_Cfb_act2_A[6];
      const real_T *xd = &pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 4;
      *pxnew2 = (*pA6++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA6++) * xd[*pAidx++];
      }
    }

    xnew[2] += (367.758393374801)*pzt_Cfb_S7_U->pzt_error[1];

    {
      static const int_T colAidxRow3[5] = { 1, 2, 3, 4, 5 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA11 = &pzt_Cfb_S7_ConstP.fsm_Cfb_act2_A[11];
      const real_T *xd = &pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 4;
      *pxnew3 = (*pA11++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA11++) * xd[*pAidx++];
      }
    }

    xnew[3] += (-96.142478538355547)*pzt_Cfb_S7_U->pzt_error[1];

    {
      static const int_T colAidxRow4[5] = { 1, 2, 3, 4, 5 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA16 = &pzt_Cfb_S7_ConstP.fsm_Cfb_act2_A[16];
      const real_T *xd = &pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 4;
      *pxnew4 = (*pA16++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA16++) * xd[*pAidx++];
      }
    }

    xnew[4] += (-149.11383683399873)*pzt_Cfb_S7_U->pzt_error[1];

    {
      static const int_T colAidxRow5[5] = { 1, 2, 3, 4, 5 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA21 = &pzt_Cfb_S7_ConstP.fsm_Cfb_act2_A[21];
      const real_T *xd = &pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 4;
      *pxnew5 = (*pA21++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA21++) * xd[*pAidx++];
      }
    }

    xnew[5] += (-76.492081338907354)*pzt_Cfb_S7_U->pzt_error[1];
    (void) memcpy(&pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[0], xnew,
                  sizeof(real_T)*6);
  }

  /* Update for DiscreteStateSpace: '<S1>/fsm_Cfb_act3' */
  {
    real_T xnew[4];
    xnew[0] = (1.0)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[0];
    xnew[0] += (1023.9999999999998)*pzt_Cfb_S7_U->pzt_error[2];
    xnew[1] = (0.829812522473124)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[1]
      + (-0.14089998548737523)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[2]
      + (0.03847419517820172)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[3];
    xnew[1] += (-1270.19573085624)*pzt_Cfb_S7_U->pzt_error[2];
    xnew[2] = (0.14089998548737523)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[1]
      + (0.68660055043878432)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[2]
      + (0.31860430284095093)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[3];
    xnew[2] += (437.16703540404296)*pzt_Cfb_S7_U->pzt_error[2];
    xnew[3] = (0.0384741951782018)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[1]
      + (-0.31860430284095093)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[2]
      + (0.64779442780487573)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[3];
    xnew[3] += (155.05035259361762)*pzt_Cfb_S7_U->pzt_error[2];
    (void) memcpy(&pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[0], xnew,
                  sizeof(real_T)*4);
  }
}

/* Model initialize function */
void pzt_Cfb_S7_initialize(RT_MODEL_pzt_Cfb_S7_T *const pzt_Cfb_S7_M)
{
  /* (no initialization code required) */
  UNUSED_PARAMETER(pzt_Cfb_S7_M);
}

/* Model terminate function */
void pzt_Cfb_S7_terminate(RT_MODEL_pzt_Cfb_S7_T *const pzt_Cfb_S7_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(pzt_Cfb_S7_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
