/*
 * File: MountControl0.c
 *
 * Code generated for Simulink model 'MountControl0'.
 *
 * Model version                  : 1.596
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Thu Apr 23 20:42:27 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MountControl0.h"
#include "MountControl0_private.h"

/* Block signals (default storage) */
B_MountControl0_T MountControl0_B;

/* Block states (default storage) */
DW_MountControl0_T MountControl0_DW;

/* External inputs (root inport signals with default storage) */
ExtU_MountControl0_T MountControl0_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_MountControl0_T MountControl0_Y;

/* Real-time model */
RT_MODEL_MountControl0_T MountControl0_M_;
RT_MODEL_MountControl0_T *const MountControl0_M = &MountControl0_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (MountControl0_M->Timing.TaskCounters.TID[1])++;
  if ((MountControl0_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.005s, 0.0s] */
    MountControl0_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void MountControl0_step(void)
{
  /* local block i/o variables */
  real_T rtb_DiscreteSS;
  real_T rtb_DiscreteSS_p;
  real_T rtb_DiscreteSS_n;
  real_T rtb_DiscreteSS_np;
  real_T rtb_DiscreteSS_pk;
  real_T rtb_Sum1;
  real_T rtb_Sum;
  int32_T i;

  /* RateTransition: '<S3>/RTout' incorporates:
   *  RateTransition: '<S5>/RTout'
   */
  if (MountControl0_M->Timing.TaskCounters.TID[1] == 0) {
    MountControl0_B.RTout = MountControl0_DW.RTout_Buffer0;

    /* RateTransition: '<S2>/RTout' */
    MountControl0_B.RTout_g = MountControl0_DW.RTout_Buffer0_b;
    MountControl0_B.RTout_j = MountControl0_DW.RTout_Buffer0_k;

    /* RateTransition: '<S4>/RTout' */
    MountControl0_B.RTout_k = MountControl0_DW.RTout_Buffer0_m;
  }

  /* End of RateTransition: '<S3>/RTout' */

  /* Sum: '<S1>/Sum2' */
  rtb_Sum = MountControl0_B.RTout + MountControl0_B.RTout_g;

  /* Sum: '<S1>/Sum3' */
  rtb_Sum1 = MountControl0_B.RTout_j + MountControl0_B.RTout_k;

  /* RateTransition: '<S6>/RTout' */
  if (MountControl0_M->Timing.TaskCounters.TID[1] == 0) {
    MountControl0_B.RTout_m = MountControl0_DW.RTout_Buffer0_bt;
  }

  /* End of RateTransition: '<S6>/RTout' */

  /* Outport: '<Root>/Mount_cmd' */
  MountControl0_Y.Mount_cmd[0] = rtb_Sum;
  MountControl0_Y.Mount_cmd[1] = rtb_Sum1;
  MountControl0_Y.Mount_cmd[2] = MountControl0_B.RTout_m;

  /* Gain: '<S1>/AZ average and  m2rad conv+' incorporates:
   *  Inport: '<Root>/Mount_FB'
   */
  rtb_Sum1 = 0.0;
  for (i = 0; i < 8; i++) {
    rtb_Sum1 += MountControl0_ConstP.AZaverageandm2radconv_Gain[i] *
      MountControl0_U.Mount_FB[i];
  }

  /* End of Gain: '<S1>/AZ average and  m2rad conv+' */

  /* Sum: '<S1>/Sum1' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  rtb_Sum1 = MountControl0_U.Mount_SP[0] - rtb_Sum1;

  /* RateTransition: '<S2>/RTin' */
  if (MountControl0_M->Timing.TaskCounters.TID[1] == 0) {
    MountControl0_B.RTin = rtb_Sum1;

    /* DiscreteStateSpace: '<S2>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = MountControl0_ConstP.DiscreteSS_C;
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE[0];
        real_T *y0 = &rtb_DiscreteSS;
        int_T numNonZero = 6;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS += 3.5004008275957672E+10*MountControl0_B.RTin;
    }

    /* RateTransition: '<S3>/RTin' incorporates:
     *  Inport: '<Root>/Mount_SP'
     */
    MountControl0_B.RTin_k = MountControl0_U.Mount_SP[0];

    /* DiscreteStateSpace: '<S3>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = MountControl0_ConstP.DiscreteSS_C_a;
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_i[0];
        real_T *y0 = &rtb_DiscreteSS_p;
        int_T numNonZero = 6;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_p += 7.7692486966092892E+9*MountControl0_B.RTin_k;
    }
  }

  /* End of RateTransition: '<S2>/RTin' */

  /* Gain: '<S1>/EL average and  m2rad conv+' incorporates:
   *  Inport: '<Root>/Mount_FB'
   */
  rtb_Sum = 0.0;
  for (i = 0; i < 8; i++) {
    rtb_Sum += MountControl0_U.Mount_FB[8 + i] *
      MountControl0_ConstP.ELaverageandm2radconv_Gain[i];
  }

  /* End of Gain: '<S1>/EL average and  m2rad conv+' */

  /* Sum: '<S1>/Sum' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  rtb_Sum = MountControl0_U.Mount_SP[1] - rtb_Sum;

  /* RateTransition: '<S4>/RTin' */
  if (MountControl0_M->Timing.TaskCounters.TID[1] == 0) {
    MountControl0_B.RTin_g = rtb_Sum;

    /* DiscreteStateSpace: '<S4>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = MountControl0_ConstP.DiscreteSS_C_o;
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_l[0];
        real_T *y0 = &rtb_DiscreteSS_n;
        int_T numNonZero = 10;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_n += 8.146974429926474E+10*MountControl0_B.RTin_g;
    }

    /* RateTransition: '<S5>/RTin' incorporates:
     *  Inport: '<Root>/Mount_SP'
     */
    MountControl0_B.RTin_o = MountControl0_U.Mount_SP[1];

    /* DiscreteStateSpace: '<S5>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = MountControl0_ConstP.DiscreteSS_C_at;
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_b[0];
        real_T *y0 = &rtb_DiscreteSS_np;
        int_T numNonZero = 10;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_np += 1.88650016576193E+10*MountControl0_B.RTin_o;
    }
  }

  /* End of RateTransition: '<S4>/RTin' */

  /* Gain: '<S1>/GIR average and  m2rad conv+' incorporates:
   *  Inport: '<Root>/Mount_FB'
   */
  rtb_Sum = ((-0.5 * MountControl0_U.Mount_FB[16] + -0.5 *
              MountControl0_U.Mount_FB[17]) + 0.5 * MountControl0_U.Mount_FB[18])
    + 0.5 * MountControl0_U.Mount_FB[19];

  /* Sum: '<S1>/Sum4' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  rtb_Sum = MountControl0_U.Mount_SP[2] - rtb_Sum;

  /* RateTransition: '<S6>/RTin' */
  if (MountControl0_M->Timing.TaskCounters.TID[1] == 0) {
    MountControl0_B.RTin_b = rtb_Sum;

    /* DiscreteStateSpace: '<S6>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[6] = { 0, 1, 2, 3, 4, 5 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = MountControl0_ConstP.DiscreteSS_C_or;
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_m[0];
        real_T *y0 = &rtb_DiscreteSS_pk;
        int_T numNonZero = 5;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_pk += 1.5140084698864941E+7*MountControl0_B.RTin_b;
    }

    /* Update for RateTransition: '<S3>/RTout' */
    MountControl0_DW.RTout_Buffer0 = rtb_DiscreteSS_p;

    /* Update for RateTransition: '<S2>/RTout' */
    MountControl0_DW.RTout_Buffer0_b = rtb_DiscreteSS;

    /* Update for RateTransition: '<S5>/RTout' */
    MountControl0_DW.RTout_Buffer0_k = rtb_DiscreteSS_np;

    /* Update for RateTransition: '<S4>/RTout' */
    MountControl0_DW.RTout_Buffer0_m = rtb_DiscreteSS_n;

    /* Update for RateTransition: '<S6>/RTout' */
    MountControl0_DW.RTout_Buffer0_bt = rtb_DiscreteSS_pk;

    /* Update for DiscreteStateSpace: '<S2>/Discrete SS' */
    {
      real_T xnew[7];
      xnew[0] = (1.0)*MountControl0_DW.DiscreteSS_DSTATE[0];
      xnew[0] += (-1448.9458359030259)*MountControl0_B.RTin;

      {
        static const int_T colAidxRow1[6] = { 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA1 = &MountControl0_ConstP.DiscreteSS_A[1];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 5;
        *pxnew1 = (*pA1++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA1++) * xd[*pAidx++];
        }
      }

      xnew[1] += (7453.6920660095793)*MountControl0_B.RTin;

      {
        static const int_T colAidxRow2[6] = { 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA7 = &MountControl0_ConstP.DiscreteSS_A[7];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 5;
        *pxnew2 = (*pA7++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA7++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-3409.4375942330362)*MountControl0_B.RTin;

      {
        static const int_T colAidxRow3[6] = { 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA13 = &MountControl0_ConstP.DiscreteSS_A[13];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 5;
        *pxnew3 = (*pA13++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA13++) * xd[*pAidx++];
        }
      }

      xnew[3] += (-7042.4954235993655)*MountControl0_B.RTin;

      {
        static const int_T colAidxRow4[6] = { 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow4[0];
        const real_T *pA19 = &MountControl0_ConstP.DiscreteSS_A[19];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew4 = &xnew[4];
        int_T numNonZero = 5;
        *pxnew4 = (*pA19++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew4 += (*pA19++) * xd[*pAidx++];
        }
      }

      xnew[4] += (4800.0957208140353)*MountControl0_B.RTin;

      {
        static const int_T colAidxRow5[6] = { 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow5[0];
        const real_T *pA25 = &MountControl0_ConstP.DiscreteSS_A[25];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew5 = &xnew[5];
        int_T numNonZero = 5;
        *pxnew5 = (*pA25++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew5 += (*pA25++) * xd[*pAidx++];
        }
      }

      xnew[5] += (95.790713267106355)*MountControl0_B.RTin;

      {
        static const int_T colAidxRow6[6] = { 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow6[0];
        const real_T *pA31 = &MountControl0_ConstP.DiscreteSS_A[31];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew6 = &xnew[6];
        int_T numNonZero = 5;
        *pxnew6 = (*pA31++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew6 += (*pA31++) * xd[*pAidx++];
        }
      }

      xnew[6] += (-125.87669992778123)*MountControl0_B.RTin;
      (void) memcpy(&MountControl0_DW.DiscreteSS_DSTATE[0], xnew,
                    sizeof(real_T)*7);
    }

    /* Update for DiscreteStateSpace: '<S3>/Discrete SS' */
    {
      real_T xnew[7];

      {
        static const int_T colAidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = MountControl0_ConstP.DiscreteSS_A_l;
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_i[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 6;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (743.60791516489712)*MountControl0_B.RTin_k;

      {
        static const int_T colAidxRow1[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA7 = &MountControl0_ConstP.DiscreteSS_A_l[7];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_i[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 6;
        *pxnew1 = (*pA7++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA7++) * xd[*pAidx++];
        }
      }

      xnew[1] += (3266.325437102827)*MountControl0_B.RTin_k;

      {
        static const int_T colAidxRow2[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA14 = &MountControl0_ConstP.DiscreteSS_A_l[14];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_i[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 6;
        *pxnew2 = (*pA14++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA14++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-2195.6273958172515)*MountControl0_B.RTin_k;

      {
        static const int_T colAidxRow3[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA21 = &MountControl0_ConstP.DiscreteSS_A_l[21];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_i[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 6;
        *pxnew3 = (*pA21++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA21++) * xd[*pAidx++];
        }
      }

      xnew[3] += (5827.890031621856)*MountControl0_B.RTin_k;

      {
        static const int_T colAidxRow4[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow4[0];
        const real_T *pA28 = &MountControl0_ConstP.DiscreteSS_A_l[28];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_i[0];
        real_T *pxnew4 = &xnew[4];
        int_T numNonZero = 6;
        *pxnew4 = (*pA28++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew4 += (*pA28++) * xd[*pAidx++];
        }
      }

      xnew[4] += (-1414.2138919967751)*MountControl0_B.RTin_k;

      {
        static const int_T colAidxRow5[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow5[0];
        const real_T *pA35 = &MountControl0_ConstP.DiscreteSS_A_l[35];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_i[0];
        real_T *pxnew5 = &xnew[5];
        int_T numNonZero = 6;
        *pxnew5 = (*pA35++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew5 += (*pA35++) * xd[*pAidx++];
        }
      }

      xnew[5] += (-621.931106668746)*MountControl0_B.RTin_k;

      {
        static const int_T colAidxRow6[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow6[0];
        const real_T *pA42 = &MountControl0_ConstP.DiscreteSS_A_l[42];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_i[0];
        real_T *pxnew6 = &xnew[6];
        int_T numNonZero = 6;
        *pxnew6 = (*pA42++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew6 += (*pA42++) * xd[*pAidx++];
        }
      }

      xnew[6] += (-802.78365186681219)*MountControl0_B.RTin_k;
      (void) memcpy(&MountControl0_DW.DiscreteSS_DSTATE_i[0], xnew,
                    sizeof(real_T)*7);
    }

    /* Update for DiscreteStateSpace: '<S4>/Discrete SS' */
    {
      real_T xnew[11];
      xnew[0] = (1.0)*MountControl0_DW.DiscreteSS_DSTATE_l[0];
      xnew[0] += (4385.3000160775064)*MountControl0_B.RTin_g;

      {
        static const int_T colAidxRow1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA1 = &MountControl0_ConstP.DiscreteSS_A_k[1];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 9;
        *pxnew1 = (*pA1++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA1++) * xd[*pAidx++];
        }
      }

      xnew[1] += (11821.168441942262)*MountControl0_B.RTin_g;

      {
        static const int_T colAidxRow2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA11 = &MountControl0_ConstP.DiscreteSS_A_k[11];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 9;
        *pxnew2 = (*pA11++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA11++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-4344.5924568655282)*MountControl0_B.RTin_g;

      {
        static const int_T colAidxRow3[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA21 = &MountControl0_ConstP.DiscreteSS_A_k[21];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 9;
        *pxnew3 = (*pA21++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA21++) * xd[*pAidx++];
        }
      }

      xnew[3] += (-2773.3977161647322)*MountControl0_B.RTin_g;

      {
        static const int_T colAidxRow4[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow4[0];
        const real_T *pA31 = &MountControl0_ConstP.DiscreteSS_A_k[31];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew4 = &xnew[4];
        int_T numNonZero = 9;
        *pxnew4 = (*pA31++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew4 += (*pA31++) * xd[*pAidx++];
        }
      }

      xnew[4] += (-1222.8728733102596)*MountControl0_B.RTin_g;

      {
        static const int_T colAidxRow5[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow5[0];
        const real_T *pA41 = &MountControl0_ConstP.DiscreteSS_A_k[41];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew5 = &xnew[5];
        int_T numNonZero = 9;
        *pxnew5 = (*pA41++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew5 += (*pA41++) * xd[*pAidx++];
        }
      }

      xnew[5] += (-154.65642967149245)*MountControl0_B.RTin_g;

      {
        static const int_T colAidxRow6[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow6[0];
        const real_T *pA51 = &MountControl0_ConstP.DiscreteSS_A_k[51];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew6 = &xnew[6];
        int_T numNonZero = 9;
        *pxnew6 = (*pA51++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew6 += (*pA51++) * xd[*pAidx++];
        }
      }

      xnew[6] += (72.349158625892414)*MountControl0_B.RTin_g;

      {
        static const int_T colAidxRow7[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow7[0];
        const real_T *pA61 = &MountControl0_ConstP.DiscreteSS_A_k[61];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew7 = &xnew[7];
        int_T numNonZero = 9;
        *pxnew7 = (*pA61++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew7 += (*pA61++) * xd[*pAidx++];
        }
      }

      xnew[7] += (-32.694522795104945)*MountControl0_B.RTin_g;

      {
        static const int_T colAidxRow8[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow8[0];
        const real_T *pA71 = &MountControl0_ConstP.DiscreteSS_A_k[71];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew8 = &xnew[8];
        int_T numNonZero = 9;
        *pxnew8 = (*pA71++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew8 += (*pA71++) * xd[*pAidx++];
        }
      }

      xnew[8] += (-153.12886621321161)*MountControl0_B.RTin_g;

      {
        static const int_T colAidxRow9[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow9[0];
        const real_T *pA81 = &MountControl0_ConstP.DiscreteSS_A_k[81];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew9 = &xnew[9];
        int_T numNonZero = 9;
        *pxnew9 = (*pA81++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew9 += (*pA81++) * xd[*pAidx++];
        }
      }

      xnew[9] += (35.544619343921667)*MountControl0_B.RTin_g;

      {
        static const int_T colAidxRow10[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow10[0];
        const real_T *pA91 = &MountControl0_ConstP.DiscreteSS_A_k[91];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew10 = &xnew[10];
        int_T numNonZero = 9;
        *pxnew10 = (*pA91++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew10 += (*pA91++) * xd[*pAidx++];
        }
      }

      xnew[10] += (-24.445510442572832)*MountControl0_B.RTin_g;
      (void) memcpy(&MountControl0_DW.DiscreteSS_DSTATE_l[0], xnew,
                    sizeof(real_T)*11);
    }

    /* Update for DiscreteStateSpace: '<S5>/Discrete SS' */
    {
      real_T xnew[11];

      {
        static const int_T colAidxRow0[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = MountControl0_ConstP.DiscreteSS_A_o;
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_b[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 10;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-3399.35351005672)*MountControl0_B.RTin_o;

      {
        static const int_T colAidxRow1[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA11 = &MountControl0_ConstP.DiscreteSS_A_o[11];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_b[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 10;
        *pxnew1 = (*pA11++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA11++) * xd[*pAidx++];
        }
      }

      xnew[1] += (-9337.8257251957912)*MountControl0_B.RTin_o;

      {
        static const int_T colAidxRow2[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA22 = &MountControl0_ConstP.DiscreteSS_A_o[22];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_b[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 10;
        *pxnew2 = (*pA22++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA22++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-3225.7138653120433)*MountControl0_B.RTin_o;

      {
        static const int_T colAidxRow3[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA33 = &MountControl0_ConstP.DiscreteSS_A_o[33];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_b[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 10;
        *pxnew3 = (*pA33++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA33++) * xd[*pAidx++];
        }
      }

      xnew[3] += (-2141.0064377117155)*MountControl0_B.RTin_o;

      {
        static const int_T colAidxRow4[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow4[0];
        const real_T *pA44 = &MountControl0_ConstP.DiscreteSS_A_o[44];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_b[0];
        real_T *pxnew4 = &xnew[4];
        int_T numNonZero = 10;
        *pxnew4 = (*pA44++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew4 += (*pA44++) * xd[*pAidx++];
        }
      }

      xnew[4] += (1108.8817409770386)*MountControl0_B.RTin_o;

      {
        static const int_T colAidxRow5[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow5[0];
        const real_T *pA55 = &MountControl0_ConstP.DiscreteSS_A_o[55];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_b[0];
        real_T *pxnew5 = &xnew[5];
        int_T numNonZero = 10;
        *pxnew5 = (*pA55++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew5 += (*pA55++) * xd[*pAidx++];
        }
      }

      xnew[5] += (111.52370215489263)*MountControl0_B.RTin_o;

      {
        static const int_T colAidxRow6[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow6[0];
        const real_T *pA66 = &MountControl0_ConstP.DiscreteSS_A_o[66];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_b[0];
        real_T *pxnew6 = &xnew[6];
        int_T numNonZero = 10;
        *pxnew6 = (*pA66++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew6 += (*pA66++) * xd[*pAidx++];
        }
      }

      xnew[6] += (-339.39248969520503)*MountControl0_B.RTin_o;

      {
        static const int_T colAidxRow7[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow7[0];
        const real_T *pA77 = &MountControl0_ConstP.DiscreteSS_A_o[77];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_b[0];
        real_T *pxnew7 = &xnew[7];
        int_T numNonZero = 10;
        *pxnew7 = (*pA77++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew7 += (*pA77++) * xd[*pAidx++];
        }
      }

      xnew[7] += (14.859456098822511)*MountControl0_B.RTin_o;

      {
        static const int_T colAidxRow8[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow8[0];
        const real_T *pA88 = &MountControl0_ConstP.DiscreteSS_A_o[88];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_b[0];
        real_T *pxnew8 = &xnew[8];
        int_T numNonZero = 10;
        *pxnew8 = (*pA88++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew8 += (*pA88++) * xd[*pAidx++];
        }
      }

      xnew[8] += (-207.16357472205937)*MountControl0_B.RTin_o;

      {
        static const int_T colAidxRow9[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow9[0];
        const real_T *pA99 = &MountControl0_ConstP.DiscreteSS_A_o[99];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_b[0];
        real_T *pxnew9 = &xnew[9];
        int_T numNonZero = 10;
        *pxnew9 = (*pA99++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew9 += (*pA99++) * xd[*pAidx++];
        }
      }

      xnew[9] += (27.010489037516926)*MountControl0_B.RTin_o;

      {
        static const int_T colAidxRow10[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow10[0];
        const real_T *pA110 = &MountControl0_ConstP.DiscreteSS_A_o[110];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_b[0];
        real_T *pxnew10 = &xnew[10];
        int_T numNonZero = 10;
        *pxnew10 = (*pA110++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew10 += (*pA110++) * xd[*pAidx++];
        }
      }

      xnew[10] += (-169.6898803021864)*MountControl0_B.RTin_o;
      (void) memcpy(&MountControl0_DW.DiscreteSS_DSTATE_b[0], xnew,
                    sizeof(real_T)*11);
    }

    /* Update for DiscreteStateSpace: '<S6>/Discrete SS' */
    {
      real_T xnew[6];
      xnew[0] = (1.0)*MountControl0_DW.DiscreteSS_DSTATE_m[0];
      xnew[0] += (11.702857142857145)*MountControl0_B.RTin_b;

      {
        static const int_T colAidxRow1[5] = { 1, 2, 3, 4, 5 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA1 = &MountControl0_ConstP.DiscreteSS_A_e[1];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_m[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA1++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA1++) * xd[*pAidx++];
        }
      }

      xnew[1] += (198.46492446842657)*MountControl0_B.RTin_b;

      {
        static const int_T colAidxRow2[5] = { 1, 2, 3, 4, 5 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA6 = &MountControl0_ConstP.DiscreteSS_A_e[6];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_m[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 4;
        *pxnew2 = (*pA6++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA6++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-59.3790064787465)*MountControl0_B.RTin_b;

      {
        static const int_T colAidxRow3[5] = { 1, 2, 3, 4, 5 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA11 = &MountControl0_ConstP.DiscreteSS_A_e[11];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_m[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 4;
        *pxnew3 = (*pA11++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA11++) * xd[*pAidx++];
        }
      }

      xnew[3] += (-46.424300104828035)*MountControl0_B.RTin_b;

      {
        static const int_T colAidxRow4[5] = { 1, 2, 3, 4, 5 };

        const int_T *pAidx = &colAidxRow4[0];
        const real_T *pA16 = &MountControl0_ConstP.DiscreteSS_A_e[16];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_m[0];
        real_T *pxnew4 = &xnew[4];
        int_T numNonZero = 4;
        *pxnew4 = (*pA16++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew4 += (*pA16++) * xd[*pAidx++];
        }
      }

      xnew[4] += (18.523611109021029)*MountControl0_B.RTin_b;

      {
        static const int_T colAidxRow5[5] = { 1, 2, 3, 4, 5 };

        const int_T *pAidx = &colAidxRow5[0];
        const real_T *pA21 = &MountControl0_ConstP.DiscreteSS_A_e[21];
        const real_T *xd = &MountControl0_DW.DiscreteSS_DSTATE_m[0];
        real_T *pxnew5 = &xnew[5];
        int_T numNonZero = 4;
        *pxnew5 = (*pA21++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew5 += (*pA21++) * xd[*pAidx++];
        }
      }

      xnew[5] += (-27.3348398980258)*MountControl0_B.RTin_b;
      (void) memcpy(&MountControl0_DW.DiscreteSS_DSTATE_m[0], xnew,
                    sizeof(real_T)*6);
    }
  }

  /* End of RateTransition: '<S6>/RTin' */
  rate_scheduler();
}

/* Model initialize function */
void MountControl0_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)MountControl0_M, 0,
                sizeof(RT_MODEL_MountControl0_T));

  /* block I/O */
  (void) memset(((void *) &MountControl0_B), 0,
                sizeof(B_MountControl0_T));

  /* states (dwork) */
  (void) memset((void *)&MountControl0_DW, 0,
                sizeof(DW_MountControl0_T));

  /* external inputs */
  (void)memset((void *)&MountControl0_U, 0, sizeof(ExtU_MountControl0_T));

  /* external outputs */
  (void) memset(&MountControl0_Y.Mount_cmd[0], 0,
                3U*sizeof(real_T));
}

/* Model terminate function */
void MountControl0_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
