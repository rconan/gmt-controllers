/*
 * File: M1LocalControl.c
 *
 * Code generated for Simulink model 'M1LocalControl'.
 *
 * Model version                  : 1.642
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Thu Jun  4 20:11:46 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M1LocalControl.h"
#include "M1LocalControl_private.h"

/* Block signals (default storage) */
B_M1LocalControl_T M1LocalControl_B;

/* Block states (default storage) */
DW_M1LocalControl_T M1LocalControl_DW;

/* External inputs (root inport signals with default storage) */
ExtU_M1LocalControl_T M1LocalControl_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_M1LocalControl_T M1LocalControl_Y;

/* Real-time model */
RT_MODEL_M1LocalControl_T M1LocalControl_M_;
RT_MODEL_M1LocalControl_T *const M1LocalControl_M = &M1LocalControl_M_;
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
  (M1LocalControl_M->Timing.TaskCounters.TID[1])++;
  if ((M1LocalControl_M->Timing.TaskCounters.TID[1]) > 19) {/* Sample time: [0.01s, 0.0s] */
    M1LocalControl_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void M1LocalControl_step(void)
{
  /* local block i/o variables */
  real_T rtb_DiscreteSS;
  real_T rtb_DiscreteSS_a;
  real_T rtb_DiscreteSS_d;
  real_T rtb_DiscreteSS_j;
  real_T rtb_DiscreteSS_j0;
  real_T rtb_DiscreteSS_dv;
  real_T rtb_DiscreteSS_n;
  real_T rtb_DiscreteSS_j5;
  real_T rtb_DiscreteSS_nl;
  real_T rtb_DiscreteSS_k;
  real_T rtb_DiscreteSS_an;
  real_T rtb_DiscreteSS_jp;
  real_T rtb_DiscreteSS_l;
  real_T rtb_DiscreteSS_jn;
  real_T rtb_DiscreteSS_i;
  real_T rtb_DiscreteSS_b;
  real_T rtb_DiscreteSS_dl;
  real_T rtb_DiscreteSS_m;
  real_T rtb_DiscreteSS_ms;
  real_T rtb_DiscreteSS_e;
  real_T rtb_DiscreteSS_f;
  real_T rtb_DiscreteSS_c;
  real_T rtb_DiscreteSS_g;
  real_T rtb_DiscreteSS_jx;
  real_T rtb_DiscreteSS_h;
  real_T rtb_DiscreteSS_ai;
  real_T rtb_DiscreteSS_b3;
  real_T rtb_DiscreteSS_fh;
  real_T rtb_DiscreteSS_in;
  real_T rtb_DiscreteSS_p;
  real_T rtb_DiscreteSS_o;
  real_T rtb_DiscreteSS_bf;
  real_T rtb_DiscreteSS_kb;
  real_T rtb_DiscreteSS_j4;
  real_T rtb_DiscreteSS_ae;
  real_T rtb_DiscreteSS_cg;
  real_T rtb_DiscreteSS_ne;
  real_T rtb_DiscreteSS_dh;
  real_T rtb_DiscreteSS_d1;
  real_T rtb_DiscreteSS_l5;
  real_T rtb_DiscreteSS_ob;
  real_T rtb_DiscreteSS_nu;
  real_T rtb_LC2CG1[6];
  real_T rtb_ForcebalanceS1[335];
  real_T rtb_ForcebalanceS2[335];
  real_T rtb_ForcebalanceS3[335];
  real_T rtb_ForcebalanceS4[335];
  real_T rtb_ForcebalanceS5[335];
  real_T rtb_ForcebalanceS6[335];
  int32_T i;
  int32_T i_0;
  real_T tmp[306];

  /* RateTransition: '<S165>/RTout' */
  if (M1LocalControl_M->Timing.TaskCounters.TID[1] == 0) {
    M1LocalControl_B.RTout = M1LocalControl_DW.RTout_Buffer0;

    /* RateTransition: '<S166>/RTout' */
    M1LocalControl_B.RTout_j = M1LocalControl_DW.RTout_Buffer0_a;

    /* RateTransition: '<S167>/RTout' */
    M1LocalControl_B.RTout_n = M1LocalControl_DW.RTout_Buffer0_h;

    /* RateTransition: '<S168>/RTout' */
    M1LocalControl_B.RTout_a = M1LocalControl_DW.RTout_Buffer0_e;

    /* RateTransition: '<S169>/RTout' */
    M1LocalControl_B.RTout_c = M1LocalControl_DW.RTout_Buffer0_g;

    /* RateTransition: '<S170>/RTout' */
    M1LocalControl_B.RTout_c0 = M1LocalControl_DW.RTout_Buffer0_j;
  }

  /* End of RateTransition: '<S165>/RTout' */

  /* SignalConversion: '<S1>/TmpSignal ConversionAtForce balance S1Inport1' */
  rtb_LC2CG1[0] = M1LocalControl_B.RTout;
  rtb_LC2CG1[1] = M1LocalControl_B.RTout_j;
  rtb_LC2CG1[2] = M1LocalControl_B.RTout_n;
  rtb_LC2CG1[3] = M1LocalControl_B.RTout_a;
  rtb_LC2CG1[4] = M1LocalControl_B.RTout_c;
  rtb_LC2CG1[5] = M1LocalControl_B.RTout_c0;

  /* Gain: '<S1>/Force balance S1' */
  for (i = 0; i < 335; i++) {
    rtb_ForcebalanceS1[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_ForcebalanceS1[i] += M1LocalControl_ConstP.pooled2[335 * i_0 + i] *
        rtb_LC2CG1[i_0];
    }
  }

  /* End of Gain: '<S1>/Force balance S1' */

  /* RateTransition: '<S171>/RTout' */
  if (M1LocalControl_M->Timing.TaskCounters.TID[1] == 0) {
    M1LocalControl_B.RTout_d = M1LocalControl_DW.RTout_Buffer0_p;

    /* RateTransition: '<S172>/RTout' */
    M1LocalControl_B.RTout_ju = M1LocalControl_DW.RTout_Buffer0_hy;

    /* RateTransition: '<S173>/RTout' */
    M1LocalControl_B.RTout_k = M1LocalControl_DW.RTout_Buffer0_f;

    /* RateTransition: '<S174>/RTout' */
    M1LocalControl_B.RTout_c2 = M1LocalControl_DW.RTout_Buffer0_o;

    /* RateTransition: '<S175>/RTout' */
    M1LocalControl_B.RTout_e = M1LocalControl_DW.RTout_Buffer0_e5;

    /* RateTransition: '<S176>/RTout' */
    M1LocalControl_B.RTout_i = M1LocalControl_DW.RTout_Buffer0_d;
  }

  /* End of RateTransition: '<S171>/RTout' */

  /* SignalConversion: '<S1>/TmpSignal ConversionAtForce balance S2Inport1' */
  rtb_LC2CG1[0] = M1LocalControl_B.RTout_d;
  rtb_LC2CG1[1] = M1LocalControl_B.RTout_ju;
  rtb_LC2CG1[2] = M1LocalControl_B.RTout_k;
  rtb_LC2CG1[3] = M1LocalControl_B.RTout_c2;
  rtb_LC2CG1[4] = M1LocalControl_B.RTout_e;
  rtb_LC2CG1[5] = M1LocalControl_B.RTout_i;

  /* Gain: '<S1>/Force balance S2' */
  for (i = 0; i < 335; i++) {
    rtb_ForcebalanceS2[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_ForcebalanceS2[i] += M1LocalControl_ConstP.pooled2[335 * i_0 + i] *
        rtb_LC2CG1[i_0];
    }
  }

  /* End of Gain: '<S1>/Force balance S2' */

  /* RateTransition: '<S177>/RTout' */
  if (M1LocalControl_M->Timing.TaskCounters.TID[1] == 0) {
    M1LocalControl_B.RTout_p = M1LocalControl_DW.RTout_Buffer0_n;

    /* RateTransition: '<S178>/RTout' */
    M1LocalControl_B.RTout_i4 = M1LocalControl_DW.RTout_Buffer0_pk;

    /* RateTransition: '<S179>/RTout' */
    M1LocalControl_B.RTout_g = M1LocalControl_DW.RTout_Buffer0_p0;

    /* RateTransition: '<S180>/RTout' */
    M1LocalControl_B.RTout_ei = M1LocalControl_DW.RTout_Buffer0_ji;

    /* RateTransition: '<S181>/RTout' */
    M1LocalControl_B.RTout_l = M1LocalControl_DW.RTout_Buffer0_b;

    /* RateTransition: '<S182>/RTout' */
    M1LocalControl_B.RTout_ln = M1LocalControl_DW.RTout_Buffer0_j1;
  }

  /* End of RateTransition: '<S177>/RTout' */

  /* SignalConversion: '<S1>/TmpSignal ConversionAtForce balance S3Inport1' */
  rtb_LC2CG1[0] = M1LocalControl_B.RTout_p;
  rtb_LC2CG1[1] = M1LocalControl_B.RTout_i4;
  rtb_LC2CG1[2] = M1LocalControl_B.RTout_g;
  rtb_LC2CG1[3] = M1LocalControl_B.RTout_ei;
  rtb_LC2CG1[4] = M1LocalControl_B.RTout_l;
  rtb_LC2CG1[5] = M1LocalControl_B.RTout_ln;

  /* Gain: '<S1>/Force balance S3' */
  for (i = 0; i < 335; i++) {
    rtb_ForcebalanceS3[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_ForcebalanceS3[i] += M1LocalControl_ConstP.pooled2[335 * i_0 + i] *
        rtb_LC2CG1[i_0];
    }
  }

  /* End of Gain: '<S1>/Force balance S3' */

  /* RateTransition: '<S183>/RTout' */
  if (M1LocalControl_M->Timing.TaskCounters.TID[1] == 0) {
    M1LocalControl_B.RTout_cp = M1LocalControl_DW.RTout_Buffer0_oa;

    /* RateTransition: '<S184>/RTout' */
    M1LocalControl_B.RTout_p2 = M1LocalControl_DW.RTout_Buffer0_o5;

    /* RateTransition: '<S185>/RTout' */
    M1LocalControl_B.RTout_k0 = M1LocalControl_DW.RTout_Buffer0_pd;

    /* RateTransition: '<S186>/RTout' */
    M1LocalControl_B.RTout_cq = M1LocalControl_DW.RTout_Buffer0_c;

    /* RateTransition: '<S187>/RTout' */
    M1LocalControl_B.RTout_dk = M1LocalControl_DW.RTout_Buffer0_er;

    /* RateTransition: '<S188>/RTout' */
    M1LocalControl_B.RTout_l5 = M1LocalControl_DW.RTout_Buffer0_l;
  }

  /* End of RateTransition: '<S183>/RTout' */

  /* SignalConversion: '<S1>/TmpSignal ConversionAtForce balance S4Inport1' */
  rtb_LC2CG1[0] = M1LocalControl_B.RTout_cp;
  rtb_LC2CG1[1] = M1LocalControl_B.RTout_p2;
  rtb_LC2CG1[2] = M1LocalControl_B.RTout_k0;
  rtb_LC2CG1[3] = M1LocalControl_B.RTout_cq;
  rtb_LC2CG1[4] = M1LocalControl_B.RTout_dk;
  rtb_LC2CG1[5] = M1LocalControl_B.RTout_l5;

  /* Gain: '<S1>/Force balance S4' */
  for (i = 0; i < 335; i++) {
    rtb_ForcebalanceS4[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_ForcebalanceS4[i] += M1LocalControl_ConstP.pooled2[335 * i_0 + i] *
        rtb_LC2CG1[i_0];
    }
  }

  /* End of Gain: '<S1>/Force balance S4' */

  /* RateTransition: '<S189>/RTout' */
  if (M1LocalControl_M->Timing.TaskCounters.TID[1] == 0) {
    M1LocalControl_B.RTout_er = M1LocalControl_DW.RTout_Buffer0_jt;

    /* RateTransition: '<S190>/RTout' */
    M1LocalControl_B.RTout_b = M1LocalControl_DW.RTout_Buffer0_cw;

    /* RateTransition: '<S191>/RTout' */
    M1LocalControl_B.RTout_po = M1LocalControl_DW.RTout_Buffer0_o1;

    /* RateTransition: '<S192>/RTout' */
    M1LocalControl_B.RTout_eu = M1LocalControl_DW.RTout_Buffer0_cf;

    /* RateTransition: '<S193>/RTout' */
    M1LocalControl_B.RTout_m = M1LocalControl_DW.RTout_Buffer0_i;

    /* RateTransition: '<S194>/RTout' */
    M1LocalControl_B.RTout_f = M1LocalControl_DW.RTout_Buffer0_lx;
  }

  /* End of RateTransition: '<S189>/RTout' */

  /* SignalConversion: '<S1>/TmpSignal ConversionAtForce balance S5Inport1' */
  rtb_LC2CG1[0] = M1LocalControl_B.RTout_er;
  rtb_LC2CG1[1] = M1LocalControl_B.RTout_b;
  rtb_LC2CG1[2] = M1LocalControl_B.RTout_po;
  rtb_LC2CG1[3] = M1LocalControl_B.RTout_eu;
  rtb_LC2CG1[4] = M1LocalControl_B.RTout_m;
  rtb_LC2CG1[5] = M1LocalControl_B.RTout_f;

  /* Gain: '<S1>/Force balance S5' */
  for (i = 0; i < 335; i++) {
    rtb_ForcebalanceS5[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_ForcebalanceS5[i] += M1LocalControl_ConstP.pooled2[335 * i_0 + i] *
        rtb_LC2CG1[i_0];
    }
  }

  /* End of Gain: '<S1>/Force balance S5' */

  /* RateTransition: '<S195>/RTout' */
  if (M1LocalControl_M->Timing.TaskCounters.TID[1] == 0) {
    M1LocalControl_B.RTout_k1 = M1LocalControl_DW.RTout_Buffer0_ju;

    /* RateTransition: '<S196>/RTout' */
    M1LocalControl_B.RTout_jt = M1LocalControl_DW.RTout_Buffer0_d3;

    /* RateTransition: '<S197>/RTout' */
    M1LocalControl_B.RTout_bw = M1LocalControl_DW.RTout_Buffer0_om;

    /* RateTransition: '<S198>/RTout' */
    M1LocalControl_B.RTout_mw = M1LocalControl_DW.RTout_Buffer0_lf;

    /* RateTransition: '<S199>/RTout' */
    M1LocalControl_B.RTout_e4 = M1LocalControl_DW.RTout_Buffer0_ea;

    /* RateTransition: '<S200>/RTout' */
    M1LocalControl_B.RTout_fo = M1LocalControl_DW.RTout_Buffer0_hm;
  }

  /* End of RateTransition: '<S195>/RTout' */

  /* SignalConversion: '<S1>/TmpSignal ConversionAtForce balance S6Inport1' */
  rtb_LC2CG1[0] = M1LocalControl_B.RTout_k1;
  rtb_LC2CG1[1] = M1LocalControl_B.RTout_jt;
  rtb_LC2CG1[2] = M1LocalControl_B.RTout_bw;
  rtb_LC2CG1[3] = M1LocalControl_B.RTout_mw;
  rtb_LC2CG1[4] = M1LocalControl_B.RTout_e4;
  rtb_LC2CG1[5] = M1LocalControl_B.RTout_fo;

  /* Gain: '<S1>/Force balance S6' */
  for (i = 0; i < 335; i++) {
    rtb_ForcebalanceS6[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_ForcebalanceS6[i] += M1LocalControl_ConstP.pooled2[335 * i_0 + i] *
        rtb_LC2CG1[i_0];
    }
  }

  /* End of Gain: '<S1>/Force balance S6' */

  /* RateTransition: '<S201>/RTout' */
  if (M1LocalControl_M->Timing.TaskCounters.TID[1] == 0) {
    M1LocalControl_B.RTout_ez = M1LocalControl_DW.RTout_Buffer0_c5;

    /* RateTransition: '<S202>/RTout' */
    M1LocalControl_B.RTout_ix = M1LocalControl_DW.RTout_Buffer0_lo;

    /* RateTransition: '<S203>/RTout' */
    M1LocalControl_B.RTout_do = M1LocalControl_DW.RTout_Buffer0_im;

    /* RateTransition: '<S204>/RTout' */
    M1LocalControl_B.RTout_nt = M1LocalControl_DW.RTout_Buffer0_d2;

    /* RateTransition: '<S205>/RTout' */
    M1LocalControl_B.RTout_is = M1LocalControl_DW.RTout_Buffer0_m;

    /* RateTransition: '<S206>/RTout' */
    M1LocalControl_B.RTout_fi = M1LocalControl_DW.RTout_Buffer0_k;
  }

  /* End of RateTransition: '<S201>/RTout' */

  /* SignalConversion: '<S1>/TmpSignal ConversionAtForce balance S7Inport1' */
  rtb_LC2CG1[0] = M1LocalControl_B.RTout_ez;
  rtb_LC2CG1[1] = M1LocalControl_B.RTout_ix;
  rtb_LC2CG1[2] = M1LocalControl_B.RTout_do;
  rtb_LC2CG1[3] = M1LocalControl_B.RTout_nt;
  rtb_LC2CG1[4] = M1LocalControl_B.RTout_is;
  rtb_LC2CG1[5] = M1LocalControl_B.RTout_fi;

  /* Gain: '<S1>/Force balance S7' incorporates:
   *  Outport: '<Root>/M1_ACT_F'
   */
  for (i = 0; i < 306; i++) {
    tmp[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp[i] += M1LocalControl_ConstP.ForcebalanceS7_Gain[306 * i_0 + i] *
        rtb_LC2CG1[i_0];
    }
  }

  /* End of Gain: '<S1>/Force balance S7' */

  /* Outport: '<Root>/M1_ACT_F' */
  for (i = 0; i < 335; i++) {
    M1LocalControl_Y.M1_ACT_F[i] = rtb_ForcebalanceS1[i];
    M1LocalControl_Y.M1_ACT_F[i + 335] = rtb_ForcebalanceS2[i];
    M1LocalControl_Y.M1_ACT_F[i + 670] = rtb_ForcebalanceS3[i];
    M1LocalControl_Y.M1_ACT_F[i + 1005] = rtb_ForcebalanceS4[i];
    M1LocalControl_Y.M1_ACT_F[i + 1340] = rtb_ForcebalanceS5[i];
    M1LocalControl_Y.M1_ACT_F[i + 1675] = rtb_ForcebalanceS6[i];
  }

  memcpy(&M1LocalControl_Y.M1_ACT_F[2010], &tmp[0], 306U * sizeof(real_T));

  /* Gain: '<S1>/LC2CG1' incorporates:
   *  Inport: '<Root>/HP_LC'
   */
  for (i = 0; i < 6; i++) {
    rtb_LC2CG1[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_LC2CG1[i] += M1LocalControl_ConstP.LC2CG1_Gain[6 * i_0 + i] *
        M1LocalControl_U.HP_LC[i_0];
    }
  }

  /* End of Gain: '<S1>/LC2CG1' */

  /* RateTransition: '<S165>/RTin' */
  if (M1LocalControl_M->Timing.TaskCounters.TID[1] == 0) {
    M1LocalControl_B.RTin = rtb_LC2CG1[0];

    /* RateTransition: '<S166>/RTin' */
    M1LocalControl_B.RTin_a = rtb_LC2CG1[1];

    /* RateTransition: '<S167>/RTin' */
    M1LocalControl_B.RTin_a2 = rtb_LC2CG1[2];

    /* RateTransition: '<S168>/RTin' */
    M1LocalControl_B.RTin_d = rtb_LC2CG1[3];

    /* RateTransition: '<S169>/RTin' */
    M1LocalControl_B.RTin_m = rtb_LC2CG1[4];

    /* RateTransition: '<S170>/RTin' */
    M1LocalControl_B.RTin_p = rtb_LC2CG1[5];

    /* DiscreteStateSpace: '<S170>/Discrete SS' */
    {
      rtb_DiscreteSS = (-20.532898991147984)*
        M1LocalControl_DW.DiscreteSS_DSTATE[0]
        + (6.3249300064723526)*M1LocalControl_DW.DiscreteSS_DSTATE[1]
        + (86.744569931449419)*M1LocalControl_DW.DiscreteSS_DSTATE[2];
      rtb_DiscreteSS += 0.0015211586426962251*M1LocalControl_B.RTin_p;
    }

    /* DiscreteStateSpace: '<S169>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = M1LocalControl_ConstP.pooled9;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_e[0];
        real_T *y0 = &rtb_DiscreteSS_a;
        int_T numNonZero = 4;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_a += 0.00082474837761773779*M1LocalControl_B.RTin_m;
    }

    /* DiscreteStateSpace: '<S168>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = M1LocalControl_ConstP.pooled9;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_ew[0];
        real_T *y0 = &rtb_DiscreteSS_d;
        int_T numNonZero = 4;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_d += 0.00082474837761773779*M1LocalControl_B.RTin_d;
    }

    /* DiscreteStateSpace: '<S167>/Discrete SS' */
    {
      rtb_DiscreteSS_j = (11.530556837169614)*
        M1LocalControl_DW.DiscreteSS_DSTATE_g[0]
        + (-10.851053072456448)*M1LocalControl_DW.DiscreteSS_DSTATE_g[1]
        + (86.744569931449419)*M1LocalControl_DW.DiscreteSS_DSTATE_g[2];
      rtb_DiscreteSS_j += 0.0019900414871214739*M1LocalControl_B.RTin_a2;
    }

    /* DiscreteStateSpace: '<S166>/Discrete SS' */
    {
      rtb_DiscreteSS_j0 = (6.5598720805159942)*
        M1LocalControl_DW.DiscreteSS_DSTATE_f[0]
        + (-5.94467376914989)*M1LocalControl_DW.DiscreteSS_DSTATE_f[1]
        + (52.046741958869653)*M1LocalControl_DW.DiscreteSS_DSTATE_f[2];
      rtb_DiscreteSS_j0 += 0.0014174769968961914*M1LocalControl_B.RTin_a;
    }

    /* DiscreteStateSpace: '<S165>/Discrete SS' */
    {
      rtb_DiscreteSS_dv = (6.5598720805159942)*
        M1LocalControl_DW.DiscreteSS_DSTATE_i[0]
        + (-5.94467376914989)*M1LocalControl_DW.DiscreteSS_DSTATE_i[1]
        + (52.046741958869653)*M1LocalControl_DW.DiscreteSS_DSTATE_i[2];
      rtb_DiscreteSS_dv += 0.0014174769968961914*M1LocalControl_B.RTin;
    }
  }

  /* End of RateTransition: '<S165>/RTin' */

  /* Gain: '<S1>/LC2CG2' incorporates:
   *  Inport: '<Root>/HP_LC'
   */
  for (i = 0; i < 6; i++) {
    rtb_LC2CG1[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_LC2CG1[i] += M1LocalControl_ConstP.LC2CG2_Gain[6 * i_0 + i] *
        M1LocalControl_U.HP_LC[6 + i_0];
    }
  }

  /* End of Gain: '<S1>/LC2CG2' */

  /* RateTransition: '<S171>/RTin' */
  if (M1LocalControl_M->Timing.TaskCounters.TID[1] == 0) {
    M1LocalControl_B.RTin_h = rtb_LC2CG1[0];

    /* RateTransition: '<S172>/RTin' */
    M1LocalControl_B.RTin_o = rtb_LC2CG1[1];

    /* RateTransition: '<S173>/RTin' */
    M1LocalControl_B.RTin_k = rtb_LC2CG1[2];

    /* RateTransition: '<S174>/RTin' */
    M1LocalControl_B.RTin_b = rtb_LC2CG1[3];

    /* RateTransition: '<S175>/RTin' */
    M1LocalControl_B.RTin_f = rtb_LC2CG1[4];

    /* RateTransition: '<S176>/RTin' */
    M1LocalControl_B.RTin_n = rtb_LC2CG1[5];

    /* DiscreteStateSpace: '<S176>/Discrete SS' */
    {
      rtb_DiscreteSS_n = (-20.532898991147984)*
        M1LocalControl_DW.DiscreteSS_DSTATE_o[0]
        + (6.3249300064723526)*M1LocalControl_DW.DiscreteSS_DSTATE_o[1]
        + (86.744569931449419)*M1LocalControl_DW.DiscreteSS_DSTATE_o[2];
      rtb_DiscreteSS_n += 0.0015211586426962251*M1LocalControl_B.RTin_n;
    }

    /* DiscreteStateSpace: '<S175>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = M1LocalControl_ConstP.pooled9;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_p[0];
        real_T *y0 = &rtb_DiscreteSS_j5;
        int_T numNonZero = 4;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_j5 += 0.00082474837761773779*M1LocalControl_B.RTin_f;
    }

    /* DiscreteStateSpace: '<S174>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = M1LocalControl_ConstP.pooled9;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_b[0];
        real_T *y0 = &rtb_DiscreteSS_nl;
        int_T numNonZero = 4;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_nl += 0.00082474837761773779*M1LocalControl_B.RTin_b;
    }

    /* DiscreteStateSpace: '<S173>/Discrete SS' */
    {
      rtb_DiscreteSS_k = (11.530556837169614)*
        M1LocalControl_DW.DiscreteSS_DSTATE_d[0]
        + (-10.851053072456448)*M1LocalControl_DW.DiscreteSS_DSTATE_d[1]
        + (86.744569931449419)*M1LocalControl_DW.DiscreteSS_DSTATE_d[2];
      rtb_DiscreteSS_k += 0.0019900414871214739*M1LocalControl_B.RTin_k;
    }

    /* DiscreteStateSpace: '<S172>/Discrete SS' */
    {
      rtb_DiscreteSS_an = (6.5598720805159942)*
        M1LocalControl_DW.DiscreteSS_DSTATE_h[0]
        + (-5.94467376914989)*M1LocalControl_DW.DiscreteSS_DSTATE_h[1]
        + (52.046741958869653)*M1LocalControl_DW.DiscreteSS_DSTATE_h[2];
      rtb_DiscreteSS_an += 0.0014174769968961914*M1LocalControl_B.RTin_o;
    }

    /* DiscreteStateSpace: '<S171>/Discrete SS' */
    {
      rtb_DiscreteSS_jp = (6.5598720805159942)*
        M1LocalControl_DW.DiscreteSS_DSTATE_k[0]
        + (-5.94467376914989)*M1LocalControl_DW.DiscreteSS_DSTATE_k[1]
        + (52.046741958869653)*M1LocalControl_DW.DiscreteSS_DSTATE_k[2];
      rtb_DiscreteSS_jp += 0.0014174769968961914*M1LocalControl_B.RTin_h;
    }
  }

  /* End of RateTransition: '<S171>/RTin' */

  /* Gain: '<S1>/LC2CG3' incorporates:
   *  Inport: '<Root>/HP_LC'
   */
  for (i = 0; i < 6; i++) {
    rtb_LC2CG1[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_LC2CG1[i] += M1LocalControl_ConstP.LC2CG3_Gain[6 * i_0 + i] *
        M1LocalControl_U.HP_LC[12 + i_0];
    }
  }

  /* End of Gain: '<S1>/LC2CG3' */

  /* RateTransition: '<S177>/RTin' */
  if (M1LocalControl_M->Timing.TaskCounters.TID[1] == 0) {
    M1LocalControl_B.RTin_pz = rtb_LC2CG1[0];

    /* RateTransition: '<S178>/RTin' */
    M1LocalControl_B.RTin_ng = rtb_LC2CG1[1];

    /* RateTransition: '<S179>/RTin' */
    M1LocalControl_B.RTin_c = rtb_LC2CG1[2];

    /* RateTransition: '<S180>/RTin' */
    M1LocalControl_B.RTin_d4 = rtb_LC2CG1[3];

    /* RateTransition: '<S181>/RTin' */
    M1LocalControl_B.RTin_l = rtb_LC2CG1[4];

    /* RateTransition: '<S182>/RTin' */
    M1LocalControl_B.RTin_cz = rtb_LC2CG1[5];

    /* DiscreteStateSpace: '<S182>/Discrete SS' */
    {
      rtb_DiscreteSS_l = (-20.532898991147984)*
        M1LocalControl_DW.DiscreteSS_DSTATE_os[0]
        + (6.3249300064723526)*M1LocalControl_DW.DiscreteSS_DSTATE_os[1]
        + (86.744569931449419)*M1LocalControl_DW.DiscreteSS_DSTATE_os[2];
      rtb_DiscreteSS_l += 0.0015211586426962251*M1LocalControl_B.RTin_cz;
    }

    /* DiscreteStateSpace: '<S181>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = M1LocalControl_ConstP.pooled9;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_kx[0];
        real_T *y0 = &rtb_DiscreteSS_jn;
        int_T numNonZero = 4;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_jn += 0.00082474837761773779*M1LocalControl_B.RTin_l;
    }

    /* DiscreteStateSpace: '<S180>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = M1LocalControl_ConstP.pooled9;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_gb[0];
        real_T *y0 = &rtb_DiscreteSS_i;
        int_T numNonZero = 4;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_i += 0.00082474837761773779*M1LocalControl_B.RTin_d4;
    }

    /* DiscreteStateSpace: '<S179>/Discrete SS' */
    {
      rtb_DiscreteSS_b = (11.530556837169614)*
        M1LocalControl_DW.DiscreteSS_DSTATE_osf[0]
        + (-10.851053072456448)*M1LocalControl_DW.DiscreteSS_DSTATE_osf[1]
        + (86.744569931449419)*M1LocalControl_DW.DiscreteSS_DSTATE_osf[2];
      rtb_DiscreteSS_b += 0.0019900414871214739*M1LocalControl_B.RTin_c;
    }

    /* DiscreteStateSpace: '<S178>/Discrete SS' */
    {
      rtb_DiscreteSS_dl = (6.5598720805159942)*
        M1LocalControl_DW.DiscreteSS_DSTATE_c[0]
        + (-5.94467376914989)*M1LocalControl_DW.DiscreteSS_DSTATE_c[1]
        + (52.046741958869653)*M1LocalControl_DW.DiscreteSS_DSTATE_c[2];
      rtb_DiscreteSS_dl += 0.0014174769968961914*M1LocalControl_B.RTin_ng;
    }

    /* DiscreteStateSpace: '<S177>/Discrete SS' */
    {
      rtb_DiscreteSS_m = (6.5598720805159942)*
        M1LocalControl_DW.DiscreteSS_DSTATE_l[0]
        + (-5.94467376914989)*M1LocalControl_DW.DiscreteSS_DSTATE_l[1]
        + (52.046741958869653)*M1LocalControl_DW.DiscreteSS_DSTATE_l[2];
      rtb_DiscreteSS_m += 0.0014174769968961914*M1LocalControl_B.RTin_pz;
    }
  }

  /* End of RateTransition: '<S177>/RTin' */

  /* Gain: '<S1>/LC2CG4' incorporates:
   *  Inport: '<Root>/HP_LC'
   */
  for (i = 0; i < 6; i++) {
    rtb_LC2CG1[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_LC2CG1[i] += M1LocalControl_ConstP.LC2CG4_Gain[6 * i_0 + i] *
        M1LocalControl_U.HP_LC[18 + i_0];
    }
  }

  /* End of Gain: '<S1>/LC2CG4' */

  /* RateTransition: '<S183>/RTin' */
  if (M1LocalControl_M->Timing.TaskCounters.TID[1] == 0) {
    M1LocalControl_B.RTin_b5 = rtb_LC2CG1[0];

    /* RateTransition: '<S184>/RTin' */
    M1LocalControl_B.RTin_p5 = rtb_LC2CG1[1];

    /* RateTransition: '<S185>/RTin' */
    M1LocalControl_B.RTin_e = rtb_LC2CG1[2];

    /* RateTransition: '<S186>/RTin' */
    M1LocalControl_B.RTin_al = rtb_LC2CG1[3];

    /* RateTransition: '<S187>/RTin' */
    M1LocalControl_B.RTin_ag = rtb_LC2CG1[4];

    /* RateTransition: '<S188>/RTin' */
    M1LocalControl_B.RTin_md = rtb_LC2CG1[5];

    /* DiscreteStateSpace: '<S188>/Discrete SS' */
    {
      rtb_DiscreteSS_ms = (-20.532898991147984)*
        M1LocalControl_DW.DiscreteSS_DSTATE_j[0]
        + (6.3249300064723526)*M1LocalControl_DW.DiscreteSS_DSTATE_j[1]
        + (86.744569931449419)*M1LocalControl_DW.DiscreteSS_DSTATE_j[2];
      rtb_DiscreteSS_ms += 0.0015211586426962251*M1LocalControl_B.RTin_md;
    }

    /* DiscreteStateSpace: '<S187>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = M1LocalControl_ConstP.pooled9;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_fz[0];
        real_T *y0 = &rtb_DiscreteSS_e;
        int_T numNonZero = 4;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_e += 0.00082474837761773779*M1LocalControl_B.RTin_ag;
    }

    /* DiscreteStateSpace: '<S186>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = M1LocalControl_ConstP.pooled9;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_jk[0];
        real_T *y0 = &rtb_DiscreteSS_f;
        int_T numNonZero = 4;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_f += 0.00082474837761773779*M1LocalControl_B.RTin_al;
    }

    /* DiscreteStateSpace: '<S185>/Discrete SS' */
    {
      rtb_DiscreteSS_c = (11.530556837169614)*
        M1LocalControl_DW.DiscreteSS_DSTATE_a[0]
        + (-10.851053072456448)*M1LocalControl_DW.DiscreteSS_DSTATE_a[1]
        + (86.744569931449419)*M1LocalControl_DW.DiscreteSS_DSTATE_a[2];
      rtb_DiscreteSS_c += 0.0019900414871214739*M1LocalControl_B.RTin_e;
    }

    /* DiscreteStateSpace: '<S184>/Discrete SS' */
    {
      rtb_DiscreteSS_g = (6.5598720805159942)*
        M1LocalControl_DW.DiscreteSS_DSTATE_ot[0]
        + (-5.94467376914989)*M1LocalControl_DW.DiscreteSS_DSTATE_ot[1]
        + (52.046741958869653)*M1LocalControl_DW.DiscreteSS_DSTATE_ot[2];
      rtb_DiscreteSS_g += 0.0014174769968961914*M1LocalControl_B.RTin_p5;
    }

    /* DiscreteStateSpace: '<S183>/Discrete SS' */
    {
      rtb_DiscreteSS_jx = (6.5598720805159942)*
        M1LocalControl_DW.DiscreteSS_DSTATE_dk[0]
        + (-5.94467376914989)*M1LocalControl_DW.DiscreteSS_DSTATE_dk[1]
        + (52.046741958869653)*M1LocalControl_DW.DiscreteSS_DSTATE_dk[2];
      rtb_DiscreteSS_jx += 0.0014174769968961914*M1LocalControl_B.RTin_b5;
    }
  }

  /* End of RateTransition: '<S183>/RTin' */

  /* Gain: '<S1>/LC2CG5' incorporates:
   *  Inport: '<Root>/HP_LC'
   */
  for (i = 0; i < 6; i++) {
    rtb_LC2CG1[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_LC2CG1[i] += M1LocalControl_ConstP.LC2CG5_Gain[6 * i_0 + i] *
        M1LocalControl_U.HP_LC[24 + i_0];
    }
  }

  /* End of Gain: '<S1>/LC2CG5' */

  /* RateTransition: '<S189>/RTin' */
  if (M1LocalControl_M->Timing.TaskCounters.TID[1] == 0) {
    M1LocalControl_B.RTin_i = rtb_LC2CG1[0];

    /* RateTransition: '<S190>/RTin' */
    M1LocalControl_B.RTin_ih = rtb_LC2CG1[1];

    /* RateTransition: '<S191>/RTin' */
    M1LocalControl_B.RTin_a3 = rtb_LC2CG1[2];

    /* RateTransition: '<S192>/RTin' */
    M1LocalControl_B.RTin_oz = rtb_LC2CG1[3];

    /* RateTransition: '<S193>/RTin' */
    M1LocalControl_B.RTin_n4 = rtb_LC2CG1[4];

    /* RateTransition: '<S194>/RTin' */
    M1LocalControl_B.RTin_iq = rtb_LC2CG1[5];

    /* DiscreteStateSpace: '<S194>/Discrete SS' */
    {
      rtb_DiscreteSS_h = (-20.532898991147984)*
        M1LocalControl_DW.DiscreteSS_DSTATE_j0[0]
        + (6.3249300064723526)*M1LocalControl_DW.DiscreteSS_DSTATE_j0[1]
        + (86.744569931449419)*M1LocalControl_DW.DiscreteSS_DSTATE_j0[2];
      rtb_DiscreteSS_h += 0.0015211586426962251*M1LocalControl_B.RTin_iq;
    }

    /* DiscreteStateSpace: '<S193>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = M1LocalControl_ConstP.pooled9;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_aj[0];
        real_T *y0 = &rtb_DiscreteSS_ai;
        int_T numNonZero = 4;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_ai += 0.00082474837761773779*M1LocalControl_B.RTin_n4;
    }

    /* DiscreteStateSpace: '<S192>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = M1LocalControl_ConstP.pooled9;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_kr[0];
        real_T *y0 = &rtb_DiscreteSS_b3;
        int_T numNonZero = 4;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_b3 += 0.00082474837761773779*M1LocalControl_B.RTin_oz;
    }

    /* DiscreteStateSpace: '<S191>/Discrete SS' */
    {
      rtb_DiscreteSS_fh = (11.530556837169614)*
        M1LocalControl_DW.DiscreteSS_DSTATE_m[0]
        + (-10.851053072456448)*M1LocalControl_DW.DiscreteSS_DSTATE_m[1]
        + (86.744569931449419)*M1LocalControl_DW.DiscreteSS_DSTATE_m[2];
      rtb_DiscreteSS_fh += 0.0019900414871214739*M1LocalControl_B.RTin_a3;
    }

    /* DiscreteStateSpace: '<S190>/Discrete SS' */
    {
      rtb_DiscreteSS_in = (6.5598720805159942)*
        M1LocalControl_DW.DiscreteSS_DSTATE_om[0]
        + (-5.94467376914989)*M1LocalControl_DW.DiscreteSS_DSTATE_om[1]
        + (52.046741958869653)*M1LocalControl_DW.DiscreteSS_DSTATE_om[2];
      rtb_DiscreteSS_in += 0.0014174769968961914*M1LocalControl_B.RTin_ih;
    }

    /* DiscreteStateSpace: '<S189>/Discrete SS' */
    {
      rtb_DiscreteSS_p = (6.5598720805159942)*
        M1LocalControl_DW.DiscreteSS_DSTATE_mz[0]
        + (-5.94467376914989)*M1LocalControl_DW.DiscreteSS_DSTATE_mz[1]
        + (52.046741958869653)*M1LocalControl_DW.DiscreteSS_DSTATE_mz[2];
      rtb_DiscreteSS_p += 0.0014174769968961914*M1LocalControl_B.RTin_i;
    }
  }

  /* End of RateTransition: '<S189>/RTin' */

  /* Gain: '<S1>/LC2CG6' incorporates:
   *  Inport: '<Root>/HP_LC'
   */
  for (i = 0; i < 6; i++) {
    rtb_LC2CG1[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_LC2CG1[i] += M1LocalControl_ConstP.LC2CG6_Gain[6 * i_0 + i] *
        M1LocalControl_U.HP_LC[30 + i_0];
    }
  }

  /* End of Gain: '<S1>/LC2CG6' */

  /* RateTransition: '<S195>/RTin' */
  if (M1LocalControl_M->Timing.TaskCounters.TID[1] == 0) {
    M1LocalControl_B.RTin_alc = rtb_LC2CG1[0];

    /* RateTransition: '<S196>/RTin' */
    M1LocalControl_B.RTin_cv = rtb_LC2CG1[1];

    /* RateTransition: '<S197>/RTin' */
    M1LocalControl_B.RTin_er = rtb_LC2CG1[2];

    /* RateTransition: '<S198>/RTin' */
    M1LocalControl_B.RTin_hv = rtb_LC2CG1[3];

    /* RateTransition: '<S199>/RTin' */
    M1LocalControl_B.RTin_j = rtb_LC2CG1[4];

    /* RateTransition: '<S200>/RTin' */
    M1LocalControl_B.RTin_cvw = rtb_LC2CG1[5];

    /* DiscreteStateSpace: '<S200>/Discrete SS' */
    {
      rtb_DiscreteSS_o = (-20.532898991147984)*
        M1LocalControl_DW.DiscreteSS_DSTATE_bl[0]
        + (6.3249300064723526)*M1LocalControl_DW.DiscreteSS_DSTATE_bl[1]
        + (86.744569931449419)*M1LocalControl_DW.DiscreteSS_DSTATE_bl[2];
      rtb_DiscreteSS_o += 0.0015211586426962251*M1LocalControl_B.RTin_cvw;
    }

    /* DiscreteStateSpace: '<S199>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = M1LocalControl_ConstP.pooled9;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_l5[0];
        real_T *y0 = &rtb_DiscreteSS_bf;
        int_T numNonZero = 4;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_bf += 0.00082474837761773779*M1LocalControl_B.RTin_j;
    }

    /* DiscreteStateSpace: '<S198>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = M1LocalControl_ConstP.pooled9;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_ka[0];
        real_T *y0 = &rtb_DiscreteSS_kb;
        int_T numNonZero = 4;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_kb += 0.00082474837761773779*M1LocalControl_B.RTin_hv;
    }

    /* DiscreteStateSpace: '<S197>/Discrete SS' */
    {
      rtb_DiscreteSS_j4 = (11.530556837169614)*
        M1LocalControl_DW.DiscreteSS_DSTATE_pa[0]
        + (-10.851053072456448)*M1LocalControl_DW.DiscreteSS_DSTATE_pa[1]
        + (86.744569931449419)*M1LocalControl_DW.DiscreteSS_DSTATE_pa[2];
      rtb_DiscreteSS_j4 += 0.0019900414871214739*M1LocalControl_B.RTin_er;
    }

    /* DiscreteStateSpace: '<S196>/Discrete SS' */
    {
      rtb_DiscreteSS_ae = (6.5598720805159942)*
        M1LocalControl_DW.DiscreteSS_DSTATE_d0[0]
        + (-5.94467376914989)*M1LocalControl_DW.DiscreteSS_DSTATE_d0[1]
        + (52.046741958869653)*M1LocalControl_DW.DiscreteSS_DSTATE_d0[2];
      rtb_DiscreteSS_ae += 0.0014174769968961914*M1LocalControl_B.RTin_cv;
    }

    /* DiscreteStateSpace: '<S195>/Discrete SS' */
    {
      rtb_DiscreteSS_cg = (6.5598720805159942)*
        M1LocalControl_DW.DiscreteSS_DSTATE_bv[0]
        + (-5.94467376914989)*M1LocalControl_DW.DiscreteSS_DSTATE_bv[1]
        + (52.046741958869653)*M1LocalControl_DW.DiscreteSS_DSTATE_bv[2];
      rtb_DiscreteSS_cg += 0.0014174769968961914*M1LocalControl_B.RTin_alc;
    }
  }

  /* End of RateTransition: '<S195>/RTin' */

  /* Gain: '<S1>/LC2CG7' incorporates:
   *  Inport: '<Root>/HP_LC'
   */
  for (i = 0; i < 6; i++) {
    rtb_LC2CG1[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_LC2CG1[i] += M1LocalControl_ConstP.LC2CG7_Gain[6 * i_0 + i] *
        M1LocalControl_U.HP_LC[36 + i_0];
    }
  }

  /* End of Gain: '<S1>/LC2CG7' */

  /* RateTransition: '<S201>/RTin' */
  if (M1LocalControl_M->Timing.TaskCounters.TID[1] == 0) {
    M1LocalControl_B.RTin_p5o = rtb_LC2CG1[0];

    /* RateTransition: '<S202>/RTin' */
    M1LocalControl_B.RTin_iy = rtb_LC2CG1[1];

    /* RateTransition: '<S203>/RTin' */
    M1LocalControl_B.RTin_dy = rtb_LC2CG1[2];

    /* RateTransition: '<S204>/RTin' */
    M1LocalControl_B.RTin_fv = rtb_LC2CG1[3];

    /* RateTransition: '<S205>/RTin' */
    M1LocalControl_B.RTin_d4v = rtb_LC2CG1[4];

    /* RateTransition: '<S206>/RTin' */
    M1LocalControl_B.RTin_nn = rtb_LC2CG1[5];

    /* DiscreteStateSpace: '<S206>/Discrete SS' */
    {
      rtb_DiscreteSS_ne = (-20.532898991147984)*
        M1LocalControl_DW.DiscreteSS_DSTATE_bc[0]
        + (6.3249300064723526)*M1LocalControl_DW.DiscreteSS_DSTATE_bc[1]
        + (86.744569931449419)*M1LocalControl_DW.DiscreteSS_DSTATE_bc[2];
      rtb_DiscreteSS_ne += 0.0015211586426962251*M1LocalControl_B.RTin_nn;
    }

    /* DiscreteStateSpace: '<S205>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = M1LocalControl_ConstP.pooled9;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_eu[0];
        real_T *y0 = &rtb_DiscreteSS_dh;
        int_T numNonZero = 4;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_dh += 0.00082474837761773779*M1LocalControl_B.RTin_d4v;
    }

    /* DiscreteStateSpace: '<S204>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = M1LocalControl_ConstP.pooled9;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_pam[0];
        real_T *y0 = &rtb_DiscreteSS_d1;
        int_T numNonZero = 4;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_d1 += 0.00082474837761773779*M1LocalControl_B.RTin_fv;
    }

    /* DiscreteStateSpace: '<S203>/Discrete SS' */
    {
      rtb_DiscreteSS_l5 = (11.530556837169614)*
        M1LocalControl_DW.DiscreteSS_DSTATE_my[0]
        + (-10.851053072456448)*M1LocalControl_DW.DiscreteSS_DSTATE_my[1]
        + (86.744569931449419)*M1LocalControl_DW.DiscreteSS_DSTATE_my[2];
      rtb_DiscreteSS_l5 += 0.0019900414871214739*M1LocalControl_B.RTin_dy;
    }

    /* DiscreteStateSpace: '<S202>/Discrete SS' */
    {
      rtb_DiscreteSS_ob = (6.5598720805159942)*
        M1LocalControl_DW.DiscreteSS_DSTATE_p3[0]
        + (-5.94467376914989)*M1LocalControl_DW.DiscreteSS_DSTATE_p3[1]
        + (52.046741958869653)*M1LocalControl_DW.DiscreteSS_DSTATE_p3[2];
      rtb_DiscreteSS_ob += 0.0014174769968961914*M1LocalControl_B.RTin_iy;
    }

    /* DiscreteStateSpace: '<S201>/Discrete SS' */
    {
      rtb_DiscreteSS_nu = (6.5598720805159942)*
        M1LocalControl_DW.DiscreteSS_DSTATE_cc[0]
        + (-5.94467376914989)*M1LocalControl_DW.DiscreteSS_DSTATE_cc[1]
        + (52.046741958869653)*M1LocalControl_DW.DiscreteSS_DSTATE_cc[2];
      rtb_DiscreteSS_nu += 0.0014174769968961914*M1LocalControl_B.RTin_p5o;
    }

    /* Update for RateTransition: '<S165>/RTout' */
    M1LocalControl_DW.RTout_Buffer0 = rtb_DiscreteSS_dv;

    /* Update for RateTransition: '<S166>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_a = rtb_DiscreteSS_j0;

    /* Update for RateTransition: '<S167>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_h = rtb_DiscreteSS_j;

    /* Update for RateTransition: '<S168>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_e = rtb_DiscreteSS_d;

    /* Update for RateTransition: '<S169>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_g = rtb_DiscreteSS_a;

    /* Update for RateTransition: '<S170>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_j = rtb_DiscreteSS;

    /* Update for RateTransition: '<S171>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_p = rtb_DiscreteSS_jp;

    /* Update for RateTransition: '<S172>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_hy = rtb_DiscreteSS_an;

    /* Update for RateTransition: '<S173>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_f = rtb_DiscreteSS_k;

    /* Update for RateTransition: '<S174>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_o = rtb_DiscreteSS_nl;

    /* Update for RateTransition: '<S175>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_e5 = rtb_DiscreteSS_j5;

    /* Update for RateTransition: '<S176>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_d = rtb_DiscreteSS_n;

    /* Update for RateTransition: '<S177>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_n = rtb_DiscreteSS_m;

    /* Update for RateTransition: '<S178>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_pk = rtb_DiscreteSS_dl;

    /* Update for RateTransition: '<S179>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_p0 = rtb_DiscreteSS_b;

    /* Update for RateTransition: '<S180>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_ji = rtb_DiscreteSS_i;

    /* Update for RateTransition: '<S181>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_b = rtb_DiscreteSS_jn;

    /* Update for RateTransition: '<S182>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_j1 = rtb_DiscreteSS_l;

    /* Update for RateTransition: '<S183>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_oa = rtb_DiscreteSS_jx;

    /* Update for RateTransition: '<S184>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_o5 = rtb_DiscreteSS_g;

    /* Update for RateTransition: '<S185>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_pd = rtb_DiscreteSS_c;

    /* Update for RateTransition: '<S186>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_c = rtb_DiscreteSS_f;

    /* Update for RateTransition: '<S187>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_er = rtb_DiscreteSS_e;

    /* Update for RateTransition: '<S188>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_l = rtb_DiscreteSS_ms;

    /* Update for RateTransition: '<S189>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_jt = rtb_DiscreteSS_p;

    /* Update for RateTransition: '<S190>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_cw = rtb_DiscreteSS_in;

    /* Update for RateTransition: '<S191>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_o1 = rtb_DiscreteSS_fh;

    /* Update for RateTransition: '<S192>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_cf = rtb_DiscreteSS_b3;

    /* Update for RateTransition: '<S193>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_i = rtb_DiscreteSS_ai;

    /* Update for RateTransition: '<S194>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_lx = rtb_DiscreteSS_h;

    /* Update for RateTransition: '<S195>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_ju = rtb_DiscreteSS_cg;

    /* Update for RateTransition: '<S196>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_d3 = rtb_DiscreteSS_ae;

    /* Update for RateTransition: '<S197>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_om = rtb_DiscreteSS_j4;

    /* Update for RateTransition: '<S198>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_lf = rtb_DiscreteSS_kb;

    /* Update for RateTransition: '<S199>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_ea = rtb_DiscreteSS_bf;

    /* Update for RateTransition: '<S200>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_hm = rtb_DiscreteSS_o;

    /* Update for RateTransition: '<S201>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_c5 = rtb_DiscreteSS_nu;

    /* Update for RateTransition: '<S202>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_lo = rtb_DiscreteSS_ob;

    /* Update for RateTransition: '<S203>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_im = rtb_DiscreteSS_l5;

    /* Update for RateTransition: '<S204>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_d2 = rtb_DiscreteSS_d1;

    /* Update for RateTransition: '<S205>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_m = rtb_DiscreteSS_dh;

    /* Update for RateTransition: '<S206>/RTout' */
    M1LocalControl_DW.RTout_Buffer0_k = rtb_DiscreteSS_ne;

    /* Update for DiscreteStateSpace: '<S170>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled3;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (0.00080217248609749253)*M1LocalControl_B.RTin_p;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled3[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (-0.0007935651812812657)*M1LocalControl_B.RTin_p;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE[2]
        + (0.00079868522354425953)*M1LocalControl_DW.DiscreteSS_DSTATE[3]
        + (0.00031513591651403917)*M1LocalControl_DW.DiscreteSS_DSTATE[4];
      xnew[2] += (0.00037256892997387123)*M1LocalControl_B.RTin_p;
      xnew[3] = (0.427588706680582)*M1LocalControl_DW.DiscreteSS_DSTATE[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_p;
      xnew[4] = (-0.45478460318547953)*M1LocalControl_DW.DiscreteSS_DSTATE[3]
        + (0.427588706680582)*M1LocalControl_DW.DiscreteSS_DSTATE[4];
      xnew[4] += (0.49826118651613027)*M1LocalControl_B.RTin_p;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S169>/Discrete SS' */
    {
      real_T xnew[7];

      {
        static const int_T colAidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled7;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_e[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 6;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.000517714600691018)*M1LocalControl_B.RTin_m;

      {
        static const int_T colAidxRow1[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA7 = &M1LocalControl_ConstP.pooled7[7];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_e[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 6;
        *pxnew1 = (*pA7++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA7++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00071345139832845164)*M1LocalControl_B.RTin_m;

      {
        static const int_T colAidxRow2[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA14 = &M1LocalControl_ConstP.pooled7[14];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_e[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 6;
        *pxnew2 = (*pA14++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA14++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-1.9329056606291852E-5)*M1LocalControl_B.RTin_m;

      {
        static const int_T colAidxRow3[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA21 = &M1LocalControl_ConstP.pooled7[21];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_e[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 6;
        *pxnew3 = (*pA21++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA21++) * xd[*pAidx++];
        }
      }

      xnew[3] += (7.6488391911800637E-5)*M1LocalControl_B.RTin_m;
      xnew[4] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_e[4]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_e[5]
        + (0.00031513591651403906)*M1LocalControl_DW.DiscreteSS_DSTATE_e[6];
      xnew[4] += (0.00037256892997387117)*M1LocalControl_B.RTin_m;
      xnew[5] = (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_e[5]
        + (0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_e[6];
      xnew[5] += (0.46569801273939748)*M1LocalControl_B.RTin_m;
      xnew[6] = (-0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_e[5]
        + (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_e[6];
      xnew[6] += (0.49826118651613027)*M1LocalControl_B.RTin_m;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_e[0], xnew,
                    sizeof(real_T)*7);
    }

    /* Update for DiscreteStateSpace: '<S168>/Discrete SS' */
    {
      real_T xnew[7];

      {
        static const int_T colAidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled7;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_ew[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 6;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.000517714600691018)*M1LocalControl_B.RTin_d;

      {
        static const int_T colAidxRow1[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA7 = &M1LocalControl_ConstP.pooled7[7];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_ew[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 6;
        *pxnew1 = (*pA7++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA7++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00071345139832845164)*M1LocalControl_B.RTin_d;

      {
        static const int_T colAidxRow2[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA14 = &M1LocalControl_ConstP.pooled7[14];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_ew[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 6;
        *pxnew2 = (*pA14++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA14++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-1.9329056606291852E-5)*M1LocalControl_B.RTin_d;

      {
        static const int_T colAidxRow3[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA21 = &M1LocalControl_ConstP.pooled7[21];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_ew[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 6;
        *pxnew3 = (*pA21++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA21++) * xd[*pAidx++];
        }
      }

      xnew[3] += (7.6488391911800637E-5)*M1LocalControl_B.RTin_d;
      xnew[4] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_ew[4]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_ew[5]
        + (0.00031513591651403906)*M1LocalControl_DW.DiscreteSS_DSTATE_ew[6];
      xnew[4] += (0.00037256892997387117)*M1LocalControl_B.RTin_d;
      xnew[5] = (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_ew[5]
        + (0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_ew[6];
      xnew[5] += (0.46569801273939748)*M1LocalControl_B.RTin_d;
      xnew[6] = (-0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_ew[5]
        + (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_ew[6];
      xnew[6] += (0.49826118651613027)*M1LocalControl_B.RTin_d;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_ew[0], xnew,
                    sizeof(real_T)*7);
    }

    /* Update for DiscreteStateSpace: '<S167>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled11;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_g[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00035271728688504068)*M1LocalControl_B.RTin_a2;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled11[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_g[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.001123352198272132)*M1LocalControl_B.RTin_a2;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_g[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_g[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_g[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_a2;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_g[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_g[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_a2;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_g[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_g[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_a2;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_g[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S166>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled15;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_f[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00047976148603314905)*M1LocalControl_B.RTin_a;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled15[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_f[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00074314489924450606)*M1LocalControl_B.RTin_a;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_f[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_f[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_f[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_a;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_f[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_f[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_a;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_f[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_f[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_a;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_f[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S165>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled15;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_i[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00047976148603314905)*M1LocalControl_B.RTin;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled15[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_i[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00074314489924450606)*M1LocalControl_B.RTin;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_i[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_i[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_i[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_i[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_i[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_i[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_i[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_i[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S176>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled3;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_o[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (0.00080217248609749253)*M1LocalControl_B.RTin_n;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled3[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_o[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (-0.0007935651812812657)*M1LocalControl_B.RTin_n;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_o[2]
        + (0.00079868522354425953)*M1LocalControl_DW.DiscreteSS_DSTATE_o[3]
        + (0.00031513591651403917)*M1LocalControl_DW.DiscreteSS_DSTATE_o[4];
      xnew[2] += (0.00037256892997387123)*M1LocalControl_B.RTin_n;
      xnew[3] = (0.427588706680582)*M1LocalControl_DW.DiscreteSS_DSTATE_o[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_o[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_n;
      xnew[4] = (-0.45478460318547953)*M1LocalControl_DW.DiscreteSS_DSTATE_o[3]
        + (0.427588706680582)*M1LocalControl_DW.DiscreteSS_DSTATE_o[4];
      xnew[4] += (0.49826118651613027)*M1LocalControl_B.RTin_n;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_o[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S175>/Discrete SS' */
    {
      real_T xnew[7];

      {
        static const int_T colAidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled7;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_p[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 6;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.000517714600691018)*M1LocalControl_B.RTin_f;

      {
        static const int_T colAidxRow1[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA7 = &M1LocalControl_ConstP.pooled7[7];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_p[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 6;
        *pxnew1 = (*pA7++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA7++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00071345139832845164)*M1LocalControl_B.RTin_f;

      {
        static const int_T colAidxRow2[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA14 = &M1LocalControl_ConstP.pooled7[14];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_p[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 6;
        *pxnew2 = (*pA14++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA14++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-1.9329056606291852E-5)*M1LocalControl_B.RTin_f;

      {
        static const int_T colAidxRow3[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA21 = &M1LocalControl_ConstP.pooled7[21];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_p[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 6;
        *pxnew3 = (*pA21++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA21++) * xd[*pAidx++];
        }
      }

      xnew[3] += (7.6488391911800637E-5)*M1LocalControl_B.RTin_f;
      xnew[4] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_p[4]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_p[5]
        + (0.00031513591651403906)*M1LocalControl_DW.DiscreteSS_DSTATE_p[6];
      xnew[4] += (0.00037256892997387117)*M1LocalControl_B.RTin_f;
      xnew[5] = (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_p[5]
        + (0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_p[6];
      xnew[5] += (0.46569801273939748)*M1LocalControl_B.RTin_f;
      xnew[6] = (-0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_p[5]
        + (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_p[6];
      xnew[6] += (0.49826118651613027)*M1LocalControl_B.RTin_f;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_p[0], xnew,
                    sizeof(real_T)*7);
    }

    /* Update for DiscreteStateSpace: '<S174>/Discrete SS' */
    {
      real_T xnew[7];

      {
        static const int_T colAidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled7;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_b[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 6;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.000517714600691018)*M1LocalControl_B.RTin_b;

      {
        static const int_T colAidxRow1[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA7 = &M1LocalControl_ConstP.pooled7[7];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_b[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 6;
        *pxnew1 = (*pA7++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA7++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00071345139832845164)*M1LocalControl_B.RTin_b;

      {
        static const int_T colAidxRow2[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA14 = &M1LocalControl_ConstP.pooled7[14];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_b[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 6;
        *pxnew2 = (*pA14++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA14++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-1.9329056606291852E-5)*M1LocalControl_B.RTin_b;

      {
        static const int_T colAidxRow3[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA21 = &M1LocalControl_ConstP.pooled7[21];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_b[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 6;
        *pxnew3 = (*pA21++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA21++) * xd[*pAidx++];
        }
      }

      xnew[3] += (7.6488391911800637E-5)*M1LocalControl_B.RTin_b;
      xnew[4] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_b[4]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_b[5]
        + (0.00031513591651403906)*M1LocalControl_DW.DiscreteSS_DSTATE_b[6];
      xnew[4] += (0.00037256892997387117)*M1LocalControl_B.RTin_b;
      xnew[5] = (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_b[5]
        + (0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_b[6];
      xnew[5] += (0.46569801273939748)*M1LocalControl_B.RTin_b;
      xnew[6] = (-0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_b[5]
        + (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_b[6];
      xnew[6] += (0.49826118651613027)*M1LocalControl_B.RTin_b;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_b[0], xnew,
                    sizeof(real_T)*7);
    }

    /* Update for DiscreteStateSpace: '<S173>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled11;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_d[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00035271728688504068)*M1LocalControl_B.RTin_k;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled11[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_d[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.001123352198272132)*M1LocalControl_B.RTin_k;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_d[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_d[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_d[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_k;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_d[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_d[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_k;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_d[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_d[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_k;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_d[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S172>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled15;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_h[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00047976148603314905)*M1LocalControl_B.RTin_o;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled15[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_h[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00074314489924450606)*M1LocalControl_B.RTin_o;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_h[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_h[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_h[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_o;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_h[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_h[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_o;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_h[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_h[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_o;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_h[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S171>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled15;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_k[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00047976148603314905)*M1LocalControl_B.RTin_h;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled15[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_k[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00074314489924450606)*M1LocalControl_B.RTin_h;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_k[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_k[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_k[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_h;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_k[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_k[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_h;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_k[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_k[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_h;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_k[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S182>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled3;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_os[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (0.00080217248609749253)*M1LocalControl_B.RTin_cz;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled3[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_os[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (-0.0007935651812812657)*M1LocalControl_B.RTin_cz;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_os[2]
        + (0.00079868522354425953)*M1LocalControl_DW.DiscreteSS_DSTATE_os[3]
        + (0.00031513591651403917)*M1LocalControl_DW.DiscreteSS_DSTATE_os[4];
      xnew[2] += (0.00037256892997387123)*M1LocalControl_B.RTin_cz;
      xnew[3] = (0.427588706680582)*M1LocalControl_DW.DiscreteSS_DSTATE_os[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_os[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_cz;
      xnew[4] = (-0.45478460318547953)*M1LocalControl_DW.DiscreteSS_DSTATE_os[3]
        + (0.427588706680582)*M1LocalControl_DW.DiscreteSS_DSTATE_os[4];
      xnew[4] += (0.49826118651613027)*M1LocalControl_B.RTin_cz;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_os[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S181>/Discrete SS' */
    {
      real_T xnew[7];

      {
        static const int_T colAidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled7;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_kx[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 6;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.000517714600691018)*M1LocalControl_B.RTin_l;

      {
        static const int_T colAidxRow1[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA7 = &M1LocalControl_ConstP.pooled7[7];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_kx[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 6;
        *pxnew1 = (*pA7++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA7++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00071345139832845164)*M1LocalControl_B.RTin_l;

      {
        static const int_T colAidxRow2[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA14 = &M1LocalControl_ConstP.pooled7[14];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_kx[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 6;
        *pxnew2 = (*pA14++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA14++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-1.9329056606291852E-5)*M1LocalControl_B.RTin_l;

      {
        static const int_T colAidxRow3[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA21 = &M1LocalControl_ConstP.pooled7[21];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_kx[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 6;
        *pxnew3 = (*pA21++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA21++) * xd[*pAidx++];
        }
      }

      xnew[3] += (7.6488391911800637E-5)*M1LocalControl_B.RTin_l;
      xnew[4] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_kx[4]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_kx[5]
        + (0.00031513591651403906)*M1LocalControl_DW.DiscreteSS_DSTATE_kx[6];
      xnew[4] += (0.00037256892997387117)*M1LocalControl_B.RTin_l;
      xnew[5] = (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_kx[5]
        + (0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_kx[6];
      xnew[5] += (0.46569801273939748)*M1LocalControl_B.RTin_l;
      xnew[6] = (-0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_kx[5]
        + (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_kx[6];
      xnew[6] += (0.49826118651613027)*M1LocalControl_B.RTin_l;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_kx[0], xnew,
                    sizeof(real_T)*7);
    }

    /* Update for DiscreteStateSpace: '<S180>/Discrete SS' */
    {
      real_T xnew[7];

      {
        static const int_T colAidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled7;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_gb[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 6;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.000517714600691018)*M1LocalControl_B.RTin_d4;

      {
        static const int_T colAidxRow1[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA7 = &M1LocalControl_ConstP.pooled7[7];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_gb[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 6;
        *pxnew1 = (*pA7++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA7++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00071345139832845164)*M1LocalControl_B.RTin_d4;

      {
        static const int_T colAidxRow2[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA14 = &M1LocalControl_ConstP.pooled7[14];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_gb[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 6;
        *pxnew2 = (*pA14++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA14++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-1.9329056606291852E-5)*M1LocalControl_B.RTin_d4;

      {
        static const int_T colAidxRow3[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA21 = &M1LocalControl_ConstP.pooled7[21];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_gb[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 6;
        *pxnew3 = (*pA21++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA21++) * xd[*pAidx++];
        }
      }

      xnew[3] += (7.6488391911800637E-5)*M1LocalControl_B.RTin_d4;
      xnew[4] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_gb[4]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_gb[5]
        + (0.00031513591651403906)*M1LocalControl_DW.DiscreteSS_DSTATE_gb[6];
      xnew[4] += (0.00037256892997387117)*M1LocalControl_B.RTin_d4;
      xnew[5] = (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_gb[5]
        + (0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_gb[6];
      xnew[5] += (0.46569801273939748)*M1LocalControl_B.RTin_d4;
      xnew[6] = (-0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_gb[5]
        + (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_gb[6];
      xnew[6] += (0.49826118651613027)*M1LocalControl_B.RTin_d4;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_gb[0], xnew,
                    sizeof(real_T)*7);
    }

    /* Update for DiscreteStateSpace: '<S179>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled11;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_osf[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00035271728688504068)*M1LocalControl_B.RTin_c;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled11[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_osf[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.001123352198272132)*M1LocalControl_B.RTin_c;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_osf[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_osf[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_osf[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_c;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_osf[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_osf[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_c;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_osf[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_osf[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_c;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_osf[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S178>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled15;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_c[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00047976148603314905)*M1LocalControl_B.RTin_ng;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled15[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_c[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00074314489924450606)*M1LocalControl_B.RTin_ng;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_c[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_c[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_c[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_ng;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_c[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_c[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_ng;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_c[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_c[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_ng;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_c[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S177>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled15;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00047976148603314905)*M1LocalControl_B.RTin_pz;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled15[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00074314489924450606)*M1LocalControl_B.RTin_pz;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_l[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_l[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_l[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_pz;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_l[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_l[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_pz;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_l[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_l[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_pz;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_l[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S188>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled3;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_j[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (0.00080217248609749253)*M1LocalControl_B.RTin_md;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled3[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_j[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (-0.0007935651812812657)*M1LocalControl_B.RTin_md;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_j[2]
        + (0.00079868522354425953)*M1LocalControl_DW.DiscreteSS_DSTATE_j[3]
        + (0.00031513591651403917)*M1LocalControl_DW.DiscreteSS_DSTATE_j[4];
      xnew[2] += (0.00037256892997387123)*M1LocalControl_B.RTin_md;
      xnew[3] = (0.427588706680582)*M1LocalControl_DW.DiscreteSS_DSTATE_j[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_j[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_md;
      xnew[4] = (-0.45478460318547953)*M1LocalControl_DW.DiscreteSS_DSTATE_j[3]
        + (0.427588706680582)*M1LocalControl_DW.DiscreteSS_DSTATE_j[4];
      xnew[4] += (0.49826118651613027)*M1LocalControl_B.RTin_md;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_j[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S187>/Discrete SS' */
    {
      real_T xnew[7];

      {
        static const int_T colAidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled7;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_fz[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 6;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.000517714600691018)*M1LocalControl_B.RTin_ag;

      {
        static const int_T colAidxRow1[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA7 = &M1LocalControl_ConstP.pooled7[7];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_fz[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 6;
        *pxnew1 = (*pA7++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA7++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00071345139832845164)*M1LocalControl_B.RTin_ag;

      {
        static const int_T colAidxRow2[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA14 = &M1LocalControl_ConstP.pooled7[14];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_fz[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 6;
        *pxnew2 = (*pA14++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA14++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-1.9329056606291852E-5)*M1LocalControl_B.RTin_ag;

      {
        static const int_T colAidxRow3[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA21 = &M1LocalControl_ConstP.pooled7[21];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_fz[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 6;
        *pxnew3 = (*pA21++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA21++) * xd[*pAidx++];
        }
      }

      xnew[3] += (7.6488391911800637E-5)*M1LocalControl_B.RTin_ag;
      xnew[4] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_fz[4]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_fz[5]
        + (0.00031513591651403906)*M1LocalControl_DW.DiscreteSS_DSTATE_fz[6];
      xnew[4] += (0.00037256892997387117)*M1LocalControl_B.RTin_ag;
      xnew[5] = (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_fz[5]
        + (0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_fz[6];
      xnew[5] += (0.46569801273939748)*M1LocalControl_B.RTin_ag;
      xnew[6] = (-0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_fz[5]
        + (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_fz[6];
      xnew[6] += (0.49826118651613027)*M1LocalControl_B.RTin_ag;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_fz[0], xnew,
                    sizeof(real_T)*7);
    }

    /* Update for DiscreteStateSpace: '<S186>/Discrete SS' */
    {
      real_T xnew[7];

      {
        static const int_T colAidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled7;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_jk[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 6;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.000517714600691018)*M1LocalControl_B.RTin_al;

      {
        static const int_T colAidxRow1[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA7 = &M1LocalControl_ConstP.pooled7[7];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_jk[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 6;
        *pxnew1 = (*pA7++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA7++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00071345139832845164)*M1LocalControl_B.RTin_al;

      {
        static const int_T colAidxRow2[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA14 = &M1LocalControl_ConstP.pooled7[14];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_jk[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 6;
        *pxnew2 = (*pA14++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA14++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-1.9329056606291852E-5)*M1LocalControl_B.RTin_al;

      {
        static const int_T colAidxRow3[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA21 = &M1LocalControl_ConstP.pooled7[21];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_jk[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 6;
        *pxnew3 = (*pA21++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA21++) * xd[*pAidx++];
        }
      }

      xnew[3] += (7.6488391911800637E-5)*M1LocalControl_B.RTin_al;
      xnew[4] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_jk[4]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_jk[5]
        + (0.00031513591651403906)*M1LocalControl_DW.DiscreteSS_DSTATE_jk[6];
      xnew[4] += (0.00037256892997387117)*M1LocalControl_B.RTin_al;
      xnew[5] = (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_jk[5]
        + (0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_jk[6];
      xnew[5] += (0.46569801273939748)*M1LocalControl_B.RTin_al;
      xnew[6] = (-0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_jk[5]
        + (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_jk[6];
      xnew[6] += (0.49826118651613027)*M1LocalControl_B.RTin_al;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_jk[0], xnew,
                    sizeof(real_T)*7);
    }

    /* Update for DiscreteStateSpace: '<S185>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled11;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_a[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00035271728688504068)*M1LocalControl_B.RTin_e;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled11[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_a[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.001123352198272132)*M1LocalControl_B.RTin_e;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_a[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_a[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_a[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_e;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_a[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_a[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_e;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_a[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_a[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_e;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_a[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S184>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled15;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_ot[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00047976148603314905)*M1LocalControl_B.RTin_p5;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled15[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_ot[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00074314489924450606)*M1LocalControl_B.RTin_p5;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_ot[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_ot[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_ot[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_p5;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_ot[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_ot[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_p5;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_ot[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_ot[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_p5;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_ot[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S183>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled15;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_dk[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00047976148603314905)*M1LocalControl_B.RTin_b5;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled15[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_dk[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00074314489924450606)*M1LocalControl_B.RTin_b5;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_dk[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_dk[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_dk[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_b5;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_dk[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_dk[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_b5;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_dk[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_dk[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_b5;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_dk[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S194>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled3;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_j0[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (0.00080217248609749253)*M1LocalControl_B.RTin_iq;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled3[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_j0[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (-0.0007935651812812657)*M1LocalControl_B.RTin_iq;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_j0[2]
        + (0.00079868522354425953)*M1LocalControl_DW.DiscreteSS_DSTATE_j0[3]
        + (0.00031513591651403917)*M1LocalControl_DW.DiscreteSS_DSTATE_j0[4];
      xnew[2] += (0.00037256892997387123)*M1LocalControl_B.RTin_iq;
      xnew[3] = (0.427588706680582)*M1LocalControl_DW.DiscreteSS_DSTATE_j0[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_j0[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_iq;
      xnew[4] = (-0.45478460318547953)*M1LocalControl_DW.DiscreteSS_DSTATE_j0[3]
        + (0.427588706680582)*M1LocalControl_DW.DiscreteSS_DSTATE_j0[4];
      xnew[4] += (0.49826118651613027)*M1LocalControl_B.RTin_iq;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_j0[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S193>/Discrete SS' */
    {
      real_T xnew[7];

      {
        static const int_T colAidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled7;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_aj[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 6;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.000517714600691018)*M1LocalControl_B.RTin_n4;

      {
        static const int_T colAidxRow1[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA7 = &M1LocalControl_ConstP.pooled7[7];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_aj[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 6;
        *pxnew1 = (*pA7++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA7++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00071345139832845164)*M1LocalControl_B.RTin_n4;

      {
        static const int_T colAidxRow2[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA14 = &M1LocalControl_ConstP.pooled7[14];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_aj[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 6;
        *pxnew2 = (*pA14++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA14++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-1.9329056606291852E-5)*M1LocalControl_B.RTin_n4;

      {
        static const int_T colAidxRow3[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA21 = &M1LocalControl_ConstP.pooled7[21];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_aj[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 6;
        *pxnew3 = (*pA21++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA21++) * xd[*pAidx++];
        }
      }

      xnew[3] += (7.6488391911800637E-5)*M1LocalControl_B.RTin_n4;
      xnew[4] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_aj[4]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_aj[5]
        + (0.00031513591651403906)*M1LocalControl_DW.DiscreteSS_DSTATE_aj[6];
      xnew[4] += (0.00037256892997387117)*M1LocalControl_B.RTin_n4;
      xnew[5] = (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_aj[5]
        + (0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_aj[6];
      xnew[5] += (0.46569801273939748)*M1LocalControl_B.RTin_n4;
      xnew[6] = (-0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_aj[5]
        + (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_aj[6];
      xnew[6] += (0.49826118651613027)*M1LocalControl_B.RTin_n4;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_aj[0], xnew,
                    sizeof(real_T)*7);
    }

    /* Update for DiscreteStateSpace: '<S192>/Discrete SS' */
    {
      real_T xnew[7];

      {
        static const int_T colAidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled7;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_kr[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 6;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.000517714600691018)*M1LocalControl_B.RTin_oz;

      {
        static const int_T colAidxRow1[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA7 = &M1LocalControl_ConstP.pooled7[7];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_kr[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 6;
        *pxnew1 = (*pA7++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA7++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00071345139832845164)*M1LocalControl_B.RTin_oz;

      {
        static const int_T colAidxRow2[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA14 = &M1LocalControl_ConstP.pooled7[14];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_kr[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 6;
        *pxnew2 = (*pA14++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA14++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-1.9329056606291852E-5)*M1LocalControl_B.RTin_oz;

      {
        static const int_T colAidxRow3[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA21 = &M1LocalControl_ConstP.pooled7[21];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_kr[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 6;
        *pxnew3 = (*pA21++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA21++) * xd[*pAidx++];
        }
      }

      xnew[3] += (7.6488391911800637E-5)*M1LocalControl_B.RTin_oz;
      xnew[4] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_kr[4]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_kr[5]
        + (0.00031513591651403906)*M1LocalControl_DW.DiscreteSS_DSTATE_kr[6];
      xnew[4] += (0.00037256892997387117)*M1LocalControl_B.RTin_oz;
      xnew[5] = (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_kr[5]
        + (0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_kr[6];
      xnew[5] += (0.46569801273939748)*M1LocalControl_B.RTin_oz;
      xnew[6] = (-0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_kr[5]
        + (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_kr[6];
      xnew[6] += (0.49826118651613027)*M1LocalControl_B.RTin_oz;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_kr[0], xnew,
                    sizeof(real_T)*7);
    }

    /* Update for DiscreteStateSpace: '<S191>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled11;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_m[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00035271728688504068)*M1LocalControl_B.RTin_a3;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled11[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_m[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.001123352198272132)*M1LocalControl_B.RTin_a3;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_m[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_m[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_m[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_a3;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_m[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_m[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_a3;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_m[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_m[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_a3;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_m[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S190>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled15;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_om[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00047976148603314905)*M1LocalControl_B.RTin_ih;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled15[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_om[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00074314489924450606)*M1LocalControl_B.RTin_ih;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_om[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_om[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_om[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_ih;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_om[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_om[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_ih;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_om[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_om[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_ih;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_om[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S189>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled15;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_mz[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00047976148603314905)*M1LocalControl_B.RTin_i;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled15[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_mz[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00074314489924450606)*M1LocalControl_B.RTin_i;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_mz[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_mz[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_mz[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_i;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_mz[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_mz[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_i;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_mz[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_mz[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_i;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_mz[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S200>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled3;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_bl[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (0.00080217248609749253)*M1LocalControl_B.RTin_cvw;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled3[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_bl[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (-0.0007935651812812657)*M1LocalControl_B.RTin_cvw;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_bl[2]
        + (0.00079868522354425953)*M1LocalControl_DW.DiscreteSS_DSTATE_bl[3]
        + (0.00031513591651403917)*M1LocalControl_DW.DiscreteSS_DSTATE_bl[4];
      xnew[2] += (0.00037256892997387123)*M1LocalControl_B.RTin_cvw;
      xnew[3] = (0.427588706680582)*M1LocalControl_DW.DiscreteSS_DSTATE_bl[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_bl[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_cvw;
      xnew[4] = (-0.45478460318547953)*M1LocalControl_DW.DiscreteSS_DSTATE_bl[3]
        + (0.427588706680582)*M1LocalControl_DW.DiscreteSS_DSTATE_bl[4];
      xnew[4] += (0.49826118651613027)*M1LocalControl_B.RTin_cvw;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_bl[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S199>/Discrete SS' */
    {
      real_T xnew[7];

      {
        static const int_T colAidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled7;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_l5[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 6;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.000517714600691018)*M1LocalControl_B.RTin_j;

      {
        static const int_T colAidxRow1[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA7 = &M1LocalControl_ConstP.pooled7[7];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_l5[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 6;
        *pxnew1 = (*pA7++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA7++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00071345139832845164)*M1LocalControl_B.RTin_j;

      {
        static const int_T colAidxRow2[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA14 = &M1LocalControl_ConstP.pooled7[14];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_l5[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 6;
        *pxnew2 = (*pA14++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA14++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-1.9329056606291852E-5)*M1LocalControl_B.RTin_j;

      {
        static const int_T colAidxRow3[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA21 = &M1LocalControl_ConstP.pooled7[21];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_l5[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 6;
        *pxnew3 = (*pA21++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA21++) * xd[*pAidx++];
        }
      }

      xnew[3] += (7.6488391911800637E-5)*M1LocalControl_B.RTin_j;
      xnew[4] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_l5[4]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_l5[5]
        + (0.00031513591651403906)*M1LocalControl_DW.DiscreteSS_DSTATE_l5[6];
      xnew[4] += (0.00037256892997387117)*M1LocalControl_B.RTin_j;
      xnew[5] = (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_l5[5]
        + (0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_l5[6];
      xnew[5] += (0.46569801273939748)*M1LocalControl_B.RTin_j;
      xnew[6] = (-0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_l5[5]
        + (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_l5[6];
      xnew[6] += (0.49826118651613027)*M1LocalControl_B.RTin_j;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_l5[0], xnew,
                    sizeof(real_T)*7);
    }

    /* Update for DiscreteStateSpace: '<S198>/Discrete SS' */
    {
      real_T xnew[7];

      {
        static const int_T colAidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled7;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_ka[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 6;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.000517714600691018)*M1LocalControl_B.RTin_hv;

      {
        static const int_T colAidxRow1[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA7 = &M1LocalControl_ConstP.pooled7[7];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_ka[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 6;
        *pxnew1 = (*pA7++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA7++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00071345139832845164)*M1LocalControl_B.RTin_hv;

      {
        static const int_T colAidxRow2[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA14 = &M1LocalControl_ConstP.pooled7[14];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_ka[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 6;
        *pxnew2 = (*pA14++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA14++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-1.9329056606291852E-5)*M1LocalControl_B.RTin_hv;

      {
        static const int_T colAidxRow3[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA21 = &M1LocalControl_ConstP.pooled7[21];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_ka[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 6;
        *pxnew3 = (*pA21++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA21++) * xd[*pAidx++];
        }
      }

      xnew[3] += (7.6488391911800637E-5)*M1LocalControl_B.RTin_hv;
      xnew[4] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_ka[4]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_ka[5]
        + (0.00031513591651403906)*M1LocalControl_DW.DiscreteSS_DSTATE_ka[6];
      xnew[4] += (0.00037256892997387117)*M1LocalControl_B.RTin_hv;
      xnew[5] = (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_ka[5]
        + (0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_ka[6];
      xnew[5] += (0.46569801273939748)*M1LocalControl_B.RTin_hv;
      xnew[6] = (-0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_ka[5]
        + (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_ka[6];
      xnew[6] += (0.49826118651613027)*M1LocalControl_B.RTin_hv;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_ka[0], xnew,
                    sizeof(real_T)*7);
    }

    /* Update for DiscreteStateSpace: '<S197>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled11;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_pa[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00035271728688504068)*M1LocalControl_B.RTin_er;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled11[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_pa[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.001123352198272132)*M1LocalControl_B.RTin_er;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_pa[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_pa[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_pa[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_er;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_pa[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_pa[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_er;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_pa[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_pa[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_er;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_pa[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S196>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled15;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_d0[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00047976148603314905)*M1LocalControl_B.RTin_cv;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled15[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_d0[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00074314489924450606)*M1LocalControl_B.RTin_cv;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_d0[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_d0[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_d0[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_cv;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_d0[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_d0[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_cv;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_d0[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_d0[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_cv;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_d0[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S195>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled15;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_bv[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00047976148603314905)*M1LocalControl_B.RTin_alc;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled15[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_bv[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00074314489924450606)*M1LocalControl_B.RTin_alc;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_bv[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_bv[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_bv[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_alc;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_bv[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_bv[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_alc;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_bv[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_bv[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_alc;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_bv[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S206>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled3;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_bc[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (0.00080217248609749253)*M1LocalControl_B.RTin_nn;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled3[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_bc[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (-0.0007935651812812657)*M1LocalControl_B.RTin_nn;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_bc[2]
        + (0.00079868522354425953)*M1LocalControl_DW.DiscreteSS_DSTATE_bc[3]
        + (0.00031513591651403917)*M1LocalControl_DW.DiscreteSS_DSTATE_bc[4];
      xnew[2] += (0.00037256892997387123)*M1LocalControl_B.RTin_nn;
      xnew[3] = (0.427588706680582)*M1LocalControl_DW.DiscreteSS_DSTATE_bc[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_bc[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_nn;
      xnew[4] = (-0.45478460318547953)*M1LocalControl_DW.DiscreteSS_DSTATE_bc[3]
        + (0.427588706680582)*M1LocalControl_DW.DiscreteSS_DSTATE_bc[4];
      xnew[4] += (0.49826118651613027)*M1LocalControl_B.RTin_nn;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_bc[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S205>/Discrete SS' */
    {
      real_T xnew[7];

      {
        static const int_T colAidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled7;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_eu[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 6;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.000517714600691018)*M1LocalControl_B.RTin_d4v;

      {
        static const int_T colAidxRow1[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA7 = &M1LocalControl_ConstP.pooled7[7];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_eu[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 6;
        *pxnew1 = (*pA7++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA7++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00071345139832845164)*M1LocalControl_B.RTin_d4v;

      {
        static const int_T colAidxRow2[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA14 = &M1LocalControl_ConstP.pooled7[14];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_eu[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 6;
        *pxnew2 = (*pA14++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA14++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-1.9329056606291852E-5)*M1LocalControl_B.RTin_d4v;

      {
        static const int_T colAidxRow3[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA21 = &M1LocalControl_ConstP.pooled7[21];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_eu[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 6;
        *pxnew3 = (*pA21++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA21++) * xd[*pAidx++];
        }
      }

      xnew[3] += (7.6488391911800637E-5)*M1LocalControl_B.RTin_d4v;
      xnew[4] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_eu[4]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_eu[5]
        + (0.00031513591651403906)*M1LocalControl_DW.DiscreteSS_DSTATE_eu[6];
      xnew[4] += (0.00037256892997387117)*M1LocalControl_B.RTin_d4v;
      xnew[5] = (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_eu[5]
        + (0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_eu[6];
      xnew[5] += (0.46569801273939748)*M1LocalControl_B.RTin_d4v;
      xnew[6] = (-0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_eu[5]
        + (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_eu[6];
      xnew[6] += (0.49826118651613027)*M1LocalControl_B.RTin_d4v;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_eu[0], xnew,
                    sizeof(real_T)*7);
    }

    /* Update for DiscreteStateSpace: '<S204>/Discrete SS' */
    {
      real_T xnew[7];

      {
        static const int_T colAidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled7;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_pam[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 6;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.000517714600691018)*M1LocalControl_B.RTin_fv;

      {
        static const int_T colAidxRow1[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA7 = &M1LocalControl_ConstP.pooled7[7];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_pam[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 6;
        *pxnew1 = (*pA7++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA7++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00071345139832845164)*M1LocalControl_B.RTin_fv;

      {
        static const int_T colAidxRow2[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA14 = &M1LocalControl_ConstP.pooled7[14];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_pam[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 6;
        *pxnew2 = (*pA14++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA14++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-1.9329056606291852E-5)*M1LocalControl_B.RTin_fv;

      {
        static const int_T colAidxRow3[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA21 = &M1LocalControl_ConstP.pooled7[21];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_pam[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 6;
        *pxnew3 = (*pA21++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA21++) * xd[*pAidx++];
        }
      }

      xnew[3] += (7.6488391911800637E-5)*M1LocalControl_B.RTin_fv;
      xnew[4] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_pam[4]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_pam[5]
        + (0.00031513591651403906)*M1LocalControl_DW.DiscreteSS_DSTATE_pam[6];
      xnew[4] += (0.00037256892997387117)*M1LocalControl_B.RTin_fv;
      xnew[5] = (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_pam[5]
        + (0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_pam[6];
      xnew[5] += (0.46569801273939748)*M1LocalControl_B.RTin_fv;
      xnew[6] = (-0.45478460318547936)*M1LocalControl_DW.DiscreteSS_DSTATE_pam[5]
        + (0.42758870668058196)*M1LocalControl_DW.DiscreteSS_DSTATE_pam[6];
      xnew[6] += (0.49826118651613027)*M1LocalControl_B.RTin_fv;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_pam[0], xnew,
                    sizeof(real_T)*7);
    }

    /* Update for DiscreteStateSpace: '<S203>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled11;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_my[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00035271728688504068)*M1LocalControl_B.RTin_dy;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled11[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_my[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.001123352198272132)*M1LocalControl_B.RTin_dy;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_my[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_my[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_my[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_dy;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_my[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_my[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_dy;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_my[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_my[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_dy;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_my[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S202>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled15;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_p3[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00047976148603314905)*M1LocalControl_B.RTin_iy;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled15[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_p3[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00074314489924450606)*M1LocalControl_B.RTin_iy;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_p3[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_p3[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_p3[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_iy;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_p3[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_p3[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_iy;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_p3[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_p3[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_iy;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_p3[0], xnew,
                    sizeof(real_T)*5);
    }

    /* Update for DiscreteStateSpace: '<S201>/Discrete SS' */
    {
      real_T xnew[5];

      {
        static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = M1LocalControl_ConstP.pooled15;
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_cc[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 4;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      xnew[0] += (-0.00047976148603314905)*M1LocalControl_B.RTin_p5o;

      {
        static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA5 = &M1LocalControl_ConstP.pooled15[5];
        const real_T *xd = &M1LocalControl_DW.DiscreteSS_DSTATE_cc[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 4;
        *pxnew1 = (*pA5++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA5++) * xd[*pAidx++];
        }
      }

      xnew[1] += (0.00074314489924450606)*M1LocalControl_B.RTin_p5o;
      xnew[2] = (1.0)*M1LocalControl_DW.DiscreteSS_DSTATE_cc[2]
        + (0.00079868522354425943)*M1LocalControl_DW.DiscreteSS_DSTATE_cc[3]
        + (0.00031513591651403911)*M1LocalControl_DW.DiscreteSS_DSTATE_cc[4];
      xnew[2] += (0.00037256892997387112)*M1LocalControl_B.RTin_p5o;
      xnew[3] = (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_cc[3]
        + (0.45478460318547947)*M1LocalControl_DW.DiscreteSS_DSTATE_cc[4];
      xnew[3] += (0.46569801273939759)*M1LocalControl_B.RTin_p5o;
      xnew[4] = (-0.45478460318547931)*M1LocalControl_DW.DiscreteSS_DSTATE_cc[3]
        + (0.42758870668058213)*M1LocalControl_DW.DiscreteSS_DSTATE_cc[4];
      xnew[4] += (0.49826118651613055)*M1LocalControl_B.RTin_p5o;
      (void) memcpy(&M1LocalControl_DW.DiscreteSS_DSTATE_cc[0], xnew,
                    sizeof(real_T)*5);
    }
  }

  /* End of RateTransition: '<S201>/RTin' */
  rate_scheduler();
}

/* Model initialize function */
void M1LocalControl_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)M1LocalControl_M, 0,
                sizeof(RT_MODEL_M1LocalControl_T));

  /* block I/O */
  (void) memset(((void *) &M1LocalControl_B), 0,
                sizeof(B_M1LocalControl_T));

  /* states (dwork) */
  (void) memset((void *)&M1LocalControl_DW, 0,
                sizeof(DW_M1LocalControl_T));

  /* external inputs */
  (void)memset((void *)&M1LocalControl_U, 0, sizeof(ExtU_M1LocalControl_T));

  /* external outputs */
  (void) memset(&M1LocalControl_Y.M1_ACT_F[0], 0,
                2316U*sizeof(real_T));
}

/* Model terminate function */
void M1LocalControl_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
