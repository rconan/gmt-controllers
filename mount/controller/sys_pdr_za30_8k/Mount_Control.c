/*
 * File: Mount_Control.c
 *
 * Code generated for Simulink model 'Mount_Control'.
 *
 * Model version                  : 9.69
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Mar  5 12:47:14 2024
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
    rtb_AZFFcontroller = (8103.5143425974875)*
      Mount_Control_DW->AZFFcontroller_DSTATE[0]
      + (-1387.2556937094623)*Mount_Control_DW->AZFFcontroller_DSTATE[1];
    rtb_AZFFcontroller += 2.0305792822648411E+10*Mount_Control_U->Mount_SP[0];
  }

  /* DiscreteStateSpace: '<S1>/EL FF controller' */
  {
    rtb_ELFFcontroller = (7154.1152008238405)*
      Mount_Control_DW->ELFFcontroller_DSTATE[0]
      + (-1224.7262886456629)*Mount_Control_DW->ELFFcontroller_DSTATE[1];
    rtb_ELFFcontroller += 1.5826504259161795E+10*Mount_Control_U->Mount_SP[1];
  }

  /* DiscreteStateSpace: '<S1>/GIR FF controller' */
  {
    rtb_GIRFFcontroller = (1018.675545438779)*
      Mount_Control_DW->GIRFFcontroller_DSTATE[0]
      + (-174.38896146873162)*Mount_Control_DW->GIRFFcontroller_DSTATE[1];
    rtb_GIRFFcontroller += 3.208816643579008E+8*Mount_Control_U->Mount_SP[2];
  }

  /* Sum: '<S1>/Sum1' */
  rtb_Sum1 = Mount_Control_U->Mount_SP[0] - rtb_Sum2[0];

  /* DiscreteStateSpace: '<S1>/AZ FB controller' */
  {
    {
      static const int_T colCidxRow0[13] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = Mount_Control_ConstP.AZFBcontroller_C;
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *y0 = &rtb_AZFBcontroller;
      int_T numNonZero = 12;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_AZFBcontroller += 1.7986731983131817E+10*rtb_Sum1;
  }

  /* Sum: '<S1>/Sum' */
  rtb_Sum = Mount_Control_U->Mount_SP[1] - rtb_Sum2[1];

  /* DiscreteStateSpace: '<S1>/EL FB controller' */
  {
    {
      static const int_T colCidxRow0[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = Mount_Control_ConstP.ELFBcontroller_C;
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *y0 = &rtb_ELFBcontroller;
      int_T numNonZero = 10;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_ELFBcontroller += 1.4040490908794756E+10*rtb_Sum;
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

    rtb_GIRFBcontroller += 1.04362368731537E+9*rtb_Sum4;
  }

  /* Outport: '<Root>/Mount_cmd' incorporates:
   *  Sum: '<S1>/Sum2'
   */
  Mount_Control_Y->Mount_cmd[0] = rtb_AZFFcontroller + rtb_AZFBcontroller;
  Mount_Control_Y->Mount_cmd[1] = rtb_ELFFcontroller + rtb_ELFBcontroller;
  Mount_Control_Y->Mount_cmd[2] = rtb_GIRFFcontroller + rtb_GIRFBcontroller;

  /* Update for DiscreteStateSpace: '<S1>/AZ FF controller' */
  {
    real_T xnew[2];
    xnew[0] = (0.997321458333785)*Mount_Control_DW->AZFFcontroller_DSTATE[0]
      + (0.00110897807178445)*Mount_Control_DW->AZFFcontroller_DSTATE[1];
    xnew[0] += (-8103.5143425975)*Mount_Control_U->Mount_SP[0];
    xnew[1] = (-0.0011089780717845055)*Mount_Control_DW->AZFFcontroller_DSTATE[0]
      + (0.99953941447735373)*Mount_Control_DW->AZFFcontroller_DSTATE[1];
    xnew[1] += (-1387.2556937094473)*Mount_Control_U->Mount_SP[0];
    (void) memcpy(&Mount_Control_DW->AZFFcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S1>/EL FF controller' */
  {
    real_T xnew[2];
    xnew[0] = (0.99732145833378527)*Mount_Control_DW->ELFFcontroller_DSTATE[0]
      + (0.0011089780717837838)*Mount_Control_DW->ELFFcontroller_DSTATE[1];
    xnew[0] += (-7154.1152008238514)*Mount_Control_U->Mount_SP[1];
    xnew[1] = (-0.0011089780717841724)*Mount_Control_DW->ELFFcontroller_DSTATE[0]
      + (0.99953941447735417)*Mount_Control_DW->ELFFcontroller_DSTATE[1];
    xnew[1] += (-1224.7262886456469)*Mount_Control_U->Mount_SP[1];
    (void) memcpy(&Mount_Control_DW->ELFFcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S1>/GIR FF controller' */
  {
    real_T xnew[2];
    xnew[0] = (0.99732145833378483)*Mount_Control_DW->GIRFFcontroller_DSTATE[0]
      + (0.0011089780717834508)*Mount_Control_DW->GIRFFcontroller_DSTATE[1];
    xnew[0] += (-1018.6755454387803)*Mount_Control_U->Mount_SP[2];
    xnew[1] = (-0.001108978071784561)*Mount_Control_DW->GIRFFcontroller_DSTATE[0]
      + (0.99953941447735384)*Mount_Control_DW->GIRFFcontroller_DSTATE[1];
    xnew[1] += (-174.3889614687283)*Mount_Control_U->Mount_SP[2];
    (void) memcpy(&Mount_Control_DW->GIRFFcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S1>/AZ FB controller' */
  {
    real_T xnew[13];
    xnew[0] = (1.0000000000000002)*Mount_Control_DW->AZFBcontroller_DSTATE[0];
    xnew[0] += (-24527.964942106846)*rtb_Sum1;

    {
      static const int_T colAidxRow1[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA1 = &Mount_Control_ConstP.AZFBcontroller_A[1];
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 11;
      *pxnew1 = (*pA1++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA1++) * xd[*pAidx++];
      }
    }

    xnew[1] += (-13157.946788685138)*rtb_Sum1;

    {
      static const int_T colAidxRow2[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA13 = &Mount_Control_ConstP.AZFBcontroller_A[13];
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 11;
      *pxnew2 = (*pA13++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA13++) * xd[*pAidx++];
      }
    }

    xnew[2] += (-171650.05216677205)*rtb_Sum1;

    {
      static const int_T colAidxRow3[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA25 = &Mount_Control_ConstP.AZFBcontroller_A[25];
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 11;
      *pxnew3 = (*pA25++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA25++) * xd[*pAidx++];
      }
    }

    xnew[3] += (-1642.806256641886)*rtb_Sum1;

    {
      static const int_T colAidxRow4[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA37 = &Mount_Control_ConstP.AZFBcontroller_A[37];
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 11;
      *pxnew4 = (*pA37++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA37++) * xd[*pAidx++];
      }
    }

    xnew[4] += (-50539.20810504839)*rtb_Sum1;

    {
      static const int_T colAidxRow5[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA49 = &Mount_Control_ConstP.AZFBcontroller_A[49];
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 11;
      *pxnew5 = (*pA49++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA49++) * xd[*pAidx++];
      }
    }

    xnew[5] += (15135.459073086164)*rtb_Sum1;

    {
      static const int_T colAidxRow6[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA61 = &Mount_Control_ConstP.AZFBcontroller_A[61];
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 11;
      *pxnew6 = (*pA61++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA61++) * xd[*pAidx++];
      }
    }

    xnew[6] += (-1611.0675075056583)*rtb_Sum1;

    {
      static const int_T colAidxRow7[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow7[0];
      const real_T *pA73 = &Mount_Control_ConstP.AZFBcontroller_A[73];
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 11;
      *pxnew7 = (*pA73++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew7 += (*pA73++) * xd[*pAidx++];
      }
    }

    xnew[7] += (20026.271751698583)*rtb_Sum1;

    {
      static const int_T colAidxRow8[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow8[0];
      const real_T *pA85 = &Mount_Control_ConstP.AZFBcontroller_A[85];
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 11;
      *pxnew8 = (*pA85++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew8 += (*pA85++) * xd[*pAidx++];
      }
    }

    xnew[8] += (1905.2005922021012)*rtb_Sum1;

    {
      static const int_T colAidxRow9[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow9[0];
      const real_T *pA97 = &Mount_Control_ConstP.AZFBcontroller_A[97];
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *pxnew9 = &xnew[9];
      int_T numNonZero = 11;
      *pxnew9 = (*pA97++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew9 += (*pA97++) * xd[*pAidx++];
      }
    }

    xnew[9] += (1935.8543093031294)*rtb_Sum1;

    {
      static const int_T colAidxRow10[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow10[0];
      const real_T *pA109 = &Mount_Control_ConstP.AZFBcontroller_A[109];
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *pxnew10 = &xnew[10];
      int_T numNonZero = 11;
      *pxnew10 = (*pA109++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew10 += (*pA109++) * xd[*pAidx++];
      }
    }

    xnew[10] += (-3275.25979090888)*rtb_Sum1;

    {
      static const int_T colAidxRow11[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow11[0];
      const real_T *pA121 = &Mount_Control_ConstP.AZFBcontroller_A[121];
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *pxnew11 = &xnew[11];
      int_T numNonZero = 11;
      *pxnew11 = (*pA121++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew11 += (*pA121++) * xd[*pAidx++];
      }
    }

    xnew[11] += (-1723.9953179358367)*rtb_Sum1;

    {
      static const int_T colAidxRow12[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow12[0];
      const real_T *pA133 = &Mount_Control_ConstP.AZFBcontroller_A[133];
      const real_T *xd = &Mount_Control_DW->AZFBcontroller_DSTATE[0];
      real_T *pxnew12 = &xnew[12];
      int_T numNonZero = 11;
      *pxnew12 = (*pA133++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew12 += (*pA133++) * xd[*pAidx++];
      }
    }

    xnew[12] += (-1369.9109365047245)*rtb_Sum1;
    (void) memcpy(&Mount_Control_DW->AZFBcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*13);
  }

  /* Update for DiscreteStateSpace: '<S1>/EL FB controller' */
  {
    real_T xnew[11];
    xnew[0] = (1.0)*Mount_Control_DW->ELFBcontroller_DSTATE[0];
    xnew[0] += (9625.9961426189711)*rtb_Sum;

    {
      static const int_T colAidxRow1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA1 = &Mount_Control_ConstP.ELFBcontroller_A[1];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 9;
      *pxnew1 = (*pA1++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA1++) * xd[*pAidx++];
      }
    }

    xnew[1] += (-153194.88374649585)*rtb_Sum;

    {
      static const int_T colAidxRow2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA11 = &Mount_Control_ConstP.ELFBcontroller_A[11];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 9;
      *pxnew2 = (*pA11++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA11++) * xd[*pAidx++];
      }
    }

    xnew[2] += (-7447.8647390701381)*rtb_Sum;

    {
      static const int_T colAidxRow3[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA21 = &Mount_Control_ConstP.ELFBcontroller_A[21];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 9;
      *pxnew3 = (*pA21++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA21++) * xd[*pAidx++];
      }
    }

    xnew[3] += (603.62104837576919)*rtb_Sum;

    {
      static const int_T colAidxRow4[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA31 = &Mount_Control_ConstP.ELFBcontroller_A[31];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 9;
      *pxnew4 = (*pA31++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA31++) * xd[*pAidx++];
      }
    }

    xnew[4] += (40769.675101755383)*rtb_Sum;

    {
      static const int_T colAidxRow5[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA41 = &Mount_Control_ConstP.ELFBcontroller_A[41];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 9;
      *pxnew5 = (*pA41++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA41++) * xd[*pAidx++];
      }
    }

    xnew[5] += (15851.069567687991)*rtb_Sum;

    {
      static const int_T colAidxRow6[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA51 = &Mount_Control_ConstP.ELFBcontroller_A[51];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 9;
      *pxnew6 = (*pA51++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA51++) * xd[*pAidx++];
      }
    }

    xnew[6] += (-1704.8705722868133)*rtb_Sum;

    {
      static const int_T colAidxRow7[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow7[0];
      const real_T *pA61 = &Mount_Control_ConstP.ELFBcontroller_A[61];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 9;
      *pxnew7 = (*pA61++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew7 += (*pA61++) * xd[*pAidx++];
      }
    }

    xnew[7] += (-2897.0075848277293)*rtb_Sum;

    {
      static const int_T colAidxRow8[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow8[0];
      const real_T *pA71 = &Mount_Control_ConstP.ELFBcontroller_A[71];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 9;
      *pxnew8 = (*pA71++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew8 += (*pA71++) * xd[*pAidx++];
      }
    }

    xnew[8] += (1062.0655176418757)*rtb_Sum;

    {
      static const int_T colAidxRow9[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow9[0];
      const real_T *pA81 = &Mount_Control_ConstP.ELFBcontroller_A[81];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew9 = &xnew[9];
      int_T numNonZero = 9;
      *pxnew9 = (*pA81++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew9 += (*pA81++) * xd[*pAidx++];
      }
    }

    xnew[9] += (725.28949446436945)*rtb_Sum;

    {
      static const int_T colAidxRow10[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow10[0];
      const real_T *pA91 = &Mount_Control_ConstP.ELFBcontroller_A[91];
      const real_T *xd = &Mount_Control_DW->ELFBcontroller_DSTATE[0];
      real_T *pxnew10 = &xnew[10];
      int_T numNonZero = 9;
      *pxnew10 = (*pA91++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew10 += (*pA91++) * xd[*pAidx++];
      }
    }

    xnew[10] += (-600.35408238680725)*rtb_Sum;
    (void) memcpy(&Mount_Control_DW->ELFBcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*11);
  }

  /* Update for DiscreteStateSpace: '<S1>/GIR FB controller' */
  {
    real_T xnew[7];
    xnew[0] = (1.0000000000000002)*Mount_Control_DW->GIRFBcontroller_DSTATE[0];
    xnew[0] += (-3557.7490662444957)*rtb_Sum4;

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

    xnew[1] += (-2291.4940612160181)*rtb_Sum4;

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

    xnew[2] += (-43538.598839272549)*rtb_Sum4;

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

    xnew[3] += (5567.3040370212511)*rtb_Sum4;

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

    xnew[4] += (1391.2365145342856)*rtb_Sum4;

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

    xnew[5] += (-24.553562834406584)*rtb_Sum4;

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

    xnew[6] += (502.57124374499676)*rtb_Sum4;
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
