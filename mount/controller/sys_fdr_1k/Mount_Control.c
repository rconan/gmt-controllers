/*
 * File: Mount_Control.c
 *
 * Code generated for Simulink model 'Mount_Control'.
 *
 * Model version                  : 9.53
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Jun  2 13:39:09 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#include "Mount_Control.h"
#include "rtwtypes.h"

/* Model step function */
void Mount_Control_step(RT_MODEL_Mount_Control_T *const Mount_Control_M,
  ExtU_Mount_Control_T *Mount_Control_U, ExtY_Mount_Control_T *Mount_Control_Y)
{
  DW_Mount_Control_T *Mount_Control_DW = Mount_Control_M->dwork;

  /* local block i/o variables */
  real_T rtb_Sum1;
  real_T rtb_Sum;
  real_T rtb_Sum4;
  real_T rtb_AZFFcontroller;
  real_T rtb_ELFFcontroller;
  real_T rtb_GIRFFcontroller;
  real_T rtb_AZFBcontroller;
  real_T rtb_ELFBcontroller;
  real_T rtb_GIRFBcontroller;
  real_T rtb_Sum2[3];
  int32_T i;
  int32_T i_0;

  /* Gain: '<S1>/Drv_Pos_avg' */
  for (i = 0; i < 3; i++) {
    int32_T tmp;
    rtb_Sum2[i] = 0.0;
    tmp = 0;
    for (i_0 = 0; i_0 < 14; i_0++) {
      rtb_Sum2[i] += Mount_Control_ConstP.Drv_Pos_avg_Gain[tmp + i] *
        Mount_Control_U->Mount_FB[i_0];
      tmp += 3;
    }
  }

  /* End of Gain: '<S1>/Drv_Pos_avg' */

  /* DiscreteStateSpace: '<S1>/AZ FF controller' */
  {
    rtb_AZFFcontroller = 0.0;
  }

  /* DiscreteStateSpace: '<S1>/EL FF controller' */
  {
    rtb_ELFFcontroller = 0.0;
  }

  /* DiscreteStateSpace: '<S1>/GIR FF controller' */
  {
    rtb_GIRFFcontroller = 0.0;
  }

  /* Sum: '<S1>/Sum1' */
  rtb_Sum1 = Mount_Control_U->Mount_SP[0] - rtb_Sum2[0];

  /* DiscreteStateSpace: '<S1>/AZ FB controller' */
  {
    {
      static const int_T colCidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = Mount_Control_ConstP.AZFBcontroller_C;
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *y0 = &rtb_AZFBcontroller;
      int_T numNonZero = 6;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_AZFBcontroller += 8.60525757895686E+10*rtb_Sum1;
  }

  /* Sum: '<S1>/Sum' */
  rtb_Sum = Mount_Control_U->Mount_SP[1] - rtb_Sum2[1];

  /* DiscreteStateSpace: '<S1>/EL FB controller' */
  {
    {
      static const int_T colCidxRow0[13] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = Mount_Control_ConstP.ELFBcontroller_C;
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *y0 = &rtb_ELFBcontroller;
      int_T numNonZero = 12;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_ELFBcontroller += 6.0245076917050056E+10*rtb_Sum;
  }

  /* Sum: '<S1>/Sum4' */
  rtb_Sum4 = Mount_Control_U->Mount_SP[2] - rtb_Sum2[2];

  /* DiscreteStateSpace: '<S1>/GIR FB controller' */
  {
    {
      static const int_T colCidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = Mount_Control_ConstP.GIRFBcontroller_C;
      const real_T *xd = &Mount_Control_DW->GIRFBcontroller_DSTATE[0];
      real_T *y0 = &rtb_GIRFBcontroller;
      int_T numNonZero = 6;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_GIRFBcontroller += 1.523590268296159E+9*rtb_Sum4;
  }

  /* Outport: '<Root>/Mount_cmd' incorporates:
   *  Sum: '<S1>/Sum2'
   */
  Mount_Control_Y->Mount_cmd[0] = rtb_AZFFcontroller + rtb_AZFBcontroller;
  Mount_Control_Y->Mount_cmd[1] = rtb_ELFFcontroller + rtb_ELFBcontroller;
  Mount_Control_Y->Mount_cmd[2] = rtb_GIRFFcontroller + rtb_GIRFBcontroller;

  /* Update for DiscreteStateSpace: '<S1>/AZ FB controller' */
  {
    real_T xnew[7];
    xnew[0] = (0.99999999999999978)*Mount_Control_DW->AZFBcontroller_DSTATE[0];
    xnew[0] += (-9571.8516486174049)*rtb_Sum1;

    {
      static const int_T colAidxRow1[6] = { 1, 2, 3, 4, 5, 6 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA1 = &Mount_Control_ConstP.AZFBcontroller_A[1];
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 5;
      *pxnew1 = (*pA1++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA1++) * xd[*pAidx++];
      }
    }

    xnew[1] += (140463.338547439)*rtb_Sum1;

    {
      static const int_T colAidxRow2[6] = { 1, 2, 3, 4, 5, 6 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA7 = &Mount_Control_ConstP.AZFBcontroller_A[7];
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 5;
      *pxnew2 = (*pA7++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA7++) * xd[*pAidx++];
      }
    }

    xnew[2] += (255831.97878329802)*rtb_Sum1;

    {
      static const int_T colAidxRow3[6] = { 1, 2, 3, 4, 5, 6 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA13 = &Mount_Control_ConstP.AZFBcontroller_A[13];
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 5;
      *pxnew3 = (*pA13++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA13++) * xd[*pAidx++];
      }
    }

    xnew[3] += (-110648.8811233452)*rtb_Sum1;

    {
      static const int_T colAidxRow4[6] = { 1, 2, 3, 4, 5, 6 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA19 = &Mount_Control_ConstP.AZFBcontroller_A[19];
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 5;
      *pxnew4 = (*pA19++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA19++) * xd[*pAidx++];
      }
    }

    xnew[4] += (23985.455482685655)*rtb_Sum1;

    {
      static const int_T colAidxRow5[6] = { 1, 2, 3, 4, 5, 6 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA25 = &Mount_Control_ConstP.AZFBcontroller_A[25];
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 5;
      *pxnew5 = (*pA25++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA25++) * xd[*pAidx++];
      }
    }

    xnew[5] += (-2383.416200805339)*rtb_Sum1;

    {
      static const int_T colAidxRow6[6] = { 1, 2, 3, 4, 5, 6 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA31 = &Mount_Control_ConstP.AZFBcontroller_A[31];
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 5;
      *pxnew6 = (*pA31++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA31++) * xd[*pAidx++];
      }
    }

    xnew[6] += (-19954.601912281483)*rtb_Sum1;
    (void) memcpy(&Mount_Control_DW->AZFBcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*7);
  }

  /* Update for DiscreteStateSpace: '<S1>/EL FB controller' */
  {
    real_T xnew[13];
    xnew[0] = (1.0)*Mount_Control_DW->ELFBcontroller_DSTATE[0];
    xnew[0] += (-2805.2133562445142)*rtb_Sum;

    {
      static const int_T colAidxRow1[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA1 = &Mount_Control_ConstP.ELFBcontroller_A[1];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 11;
      *pxnew1 = (*pA1++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA1++) * xd[*pAidx++];
      }
    }

    xnew[1] += (-158958.40786421276)*rtb_Sum;

    {
      static const int_T colAidxRow2[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA13 = &Mount_Control_ConstP.ELFBcontroller_A[13];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 11;
      *pxnew2 = (*pA13++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA13++) * xd[*pAidx++];
      }
    }

    xnew[2] += (207613.02018134037)*rtb_Sum;

    {
      static const int_T colAidxRow3[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA25 = &Mount_Control_ConstP.ELFBcontroller_A[25];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 11;
      *pxnew3 = (*pA25++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA25++) * xd[*pAidx++];
      }
    }

    xnew[3] += (94563.612178621683)*rtb_Sum;

    {
      static const int_T colAidxRow4[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA37 = &Mount_Control_ConstP.ELFBcontroller_A[37];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 11;
      *pxnew4 = (*pA37++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA37++) * xd[*pAidx++];
      }
    }

    xnew[4] += (13922.84097550447)*rtb_Sum;

    {
      static const int_T colAidxRow5[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA49 = &Mount_Control_ConstP.ELFBcontroller_A[49];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 11;
      *pxnew5 = (*pA49++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA49++) * xd[*pAidx++];
      }
    }

    xnew[5] += (-8312.8434290333444)*rtb_Sum;

    {
      static const int_T colAidxRow6[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA61 = &Mount_Control_ConstP.ELFBcontroller_A[61];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 11;
      *pxnew6 = (*pA61++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA61++) * xd[*pAidx++];
      }
    }

    xnew[6] += (-1398.1096004645078)*rtb_Sum;

    {
      static const int_T colAidxRow7[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow7[0];
      const real_T *pA73 = &Mount_Control_ConstP.ELFBcontroller_A[73];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 11;
      *pxnew7 = (*pA73++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew7 += (*pA73++) * xd[*pAidx++];
      }
    }

    xnew[7] += (-614.70518368033117)*rtb_Sum;

    {
      static const int_T colAidxRow8[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow8[0];
      const real_T *pA85 = &Mount_Control_ConstP.ELFBcontroller_A[85];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 11;
      *pxnew8 = (*pA85++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew8 += (*pA85++) * xd[*pAidx++];
      }
    }

    xnew[8] += (1081.3507908088654)*rtb_Sum;

    {
      static const int_T colAidxRow9[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow9[0];
      const real_T *pA97 = &Mount_Control_ConstP.ELFBcontroller_A[97];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew9 = &xnew[9];
      int_T numNonZero = 11;
      *pxnew9 = (*pA97++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew9 += (*pA97++) * xd[*pAidx++];
      }
    }

    xnew[9] += (213.9878014735566)*rtb_Sum;

    {
      static const int_T colAidxRow10[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow10[0];
      const real_T *pA109 = &Mount_Control_ConstP.ELFBcontroller_A[109];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew10 = &xnew[10];
      int_T numNonZero = 11;
      *pxnew10 = (*pA109++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew10 += (*pA109++) * xd[*pAidx++];
      }
    }

    xnew[10] += (-3742.8506721853337)*rtb_Sum;

    {
      static const int_T colAidxRow11[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow11[0];
      const real_T *pA121 = &Mount_Control_ConstP.ELFBcontroller_A[121];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew11 = &xnew[11];
      int_T numNonZero = 11;
      *pxnew11 = (*pA121++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew11 += (*pA121++) * xd[*pAidx++];
      }
    }

    xnew[11] += (-355.10892574239165)*rtb_Sum;

    {
      static const int_T colAidxRow12[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow12[0];
      const real_T *pA133 = &Mount_Control_ConstP.ELFBcontroller_A[133];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew12 = &xnew[12];
      int_T numNonZero = 11;
      *pxnew12 = (*pA133++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew12 += (*pA133++) * xd[*pAidx++];
      }
    }

    xnew[12] += (463.18304459776414)*rtb_Sum;
    (void) memcpy(&Mount_Control_DW->ELFBcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*13);
  }

  /* Update for DiscreteStateSpace: '<S1>/GIR FB controller' */
  {
    real_T xnew[7];
    xnew[0] = (1.0)*Mount_Control_DW->GIRFBcontroller_DSTATE[0];
    xnew[0] += (-1189.4121570919501)*rtb_Sum4;

    {
      static const int_T colAidxRow1[6] = { 1, 2, 3, 4, 5, 6 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA1 = &Mount_Control_ConstP.GIRFBcontroller_A[1];
      const real_T *xd = &Mount_Control_DW->GIRFBcontroller_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 5;
      *pxnew1 = (*pA1++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA1++) * xd[*pAidx++];
      }
    }

    xnew[1] += (-17028.864555104064)*rtb_Sum4;

    {
      static const int_T colAidxRow2[6] = { 1, 2, 3, 4, 5, 6 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA7 = &Mount_Control_ConstP.GIRFBcontroller_A[7];
      const real_T *xd = &Mount_Control_DW->GIRFBcontroller_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 5;
      *pxnew2 = (*pA7++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA7++) * xd[*pAidx++];
      }
    }

    xnew[2] += (-31350.698316730148)*rtb_Sum4;

    {
      static const int_T colAidxRow3[6] = { 1, 2, 3, 4, 5, 6 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA13 = &Mount_Control_ConstP.GIRFBcontroller_A[13];
      const real_T *xd = &Mount_Control_DW->GIRFBcontroller_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 5;
      *pxnew3 = (*pA13++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA13++) * xd[*pAidx++];
      }
    }

    xnew[3] += (22397.605203121362)*rtb_Sum4;

    {
      static const int_T colAidxRow4[6] = { 1, 2, 3, 4, 5, 6 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA19 = &Mount_Control_ConstP.GIRFBcontroller_A[19];
      const real_T *xd = &Mount_Control_DW->GIRFBcontroller_DSTATE[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 5;
      *pxnew4 = (*pA19++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA19++) * xd[*pAidx++];
      }
    }

    xnew[4] += (4262.3175327026147)*rtb_Sum4;

    {
      static const int_T colAidxRow5[6] = { 1, 2, 3, 4, 5, 6 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA25 = &Mount_Control_ConstP.GIRFBcontroller_A[25];
      const real_T *xd = &Mount_Control_DW->GIRFBcontroller_DSTATE[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 5;
      *pxnew5 = (*pA25++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA25++) * xd[*pAidx++];
      }
    }

    xnew[5] += (-3887.2197360677828)*rtb_Sum4;

    {
      static const int_T colAidxRow6[6] = { 1, 2, 3, 4, 5, 6 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA31 = &Mount_Control_ConstP.GIRFBcontroller_A[31];
      const real_T *xd = &Mount_Control_DW->GIRFBcontroller_DSTATE[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 5;
      *pxnew6 = (*pA31++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA31++) * xd[*pAidx++];
      }
    }

    xnew[6] += (-1086.8945536880574)*rtb_Sum4;
    (void) memcpy(&Mount_Control_DW->GIRFBcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*7);
  }
}

/* Model initialize function */
void Mount_Control_initialize(RT_MODEL_Mount_Control_T *const Mount_Control_M)
{
  /* (no initialization code required) */
  UNUSED_PARAMETER(Mount_Control_M);
}

/* Model terminate function */
void Mount_Control_terminate(RT_MODEL_Mount_Control_T *const Mount_Control_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(Mount_Control_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
