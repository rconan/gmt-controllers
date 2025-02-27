/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pzt_Cfb_S7.c
 *
 * Code generated for Simulink model 'pzt_Cfb_S7'.
 *
 * Model version                  : 9.15
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Feb 27 16:21:54 2025
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
    rtb_fsm_Cfb_act2 = (1792.4160535515714)*pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[0]
      + (1282.6182631360693)*pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[1]
      + (-445.20254803033822)*pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[2]
      + (-134.91895164674793)*pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[3];
    rtb_fsm_Cfb_act2 += 173159.13265436474*pzt_Cfb_S7_U->pzt_error[1];
  }

  /* DiscreteStateSpace: '<S1>/fsm_Cfb_act3' */
  {
    rtb_fsm_Cfb_act3 = (1792.4160535515714)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[0]
      + (1282.6182631360693)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[1]
      + (-445.20254803033822)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[2]
      + (-134.91895164674793)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[3];
    rtb_fsm_Cfb_act3 += 173159.13265436474*pzt_Cfb_S7_U->pzt_error[2];
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
    real_T xnew[4];
    xnew[0] = (1.0)*pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[0];
    xnew[0] += (1023.9999999999994)*pzt_Cfb_S7_U->pzt_error[1];
    xnew[1] = (0.831984231596302)*pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[1]
      + (0.13773951362369624)*pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[2]
      + (0.033248462288313227)*pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[3];
    xnew[1] += (-1282.6182631360693)*pzt_Cfb_S7_U->pzt_error[1];
    xnew[2] = (-0.13773951362369627)*pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[1]
      + (0.63982700974886286)*pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[2]
      + (-0.30757002934736644)*pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[3];
    xnew[2] += (-445.20254803033816)*pzt_Cfb_S7_U->pzt_error[1];
    xnew[3] = (0.033248462288313095)*pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[1]
      + (0.30757002934736666)*pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[2]
      + (0.56336617061009242)*pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[3];
    xnew[3] += (134.91895164674804)*pzt_Cfb_S7_U->pzt_error[1];
    (void) memcpy(&pzt_Cfb_S7_DW->fsm_Cfb_act2_DSTATE[0], xnew,
                  sizeof(real_T)*4);
  }

  /* Update for DiscreteStateSpace: '<S1>/fsm_Cfb_act3' */
  {
    real_T xnew[4];
    xnew[0] = (1.0)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[0];
    xnew[0] += (1023.9999999999994)*pzt_Cfb_S7_U->pzt_error[2];
    xnew[1] = (0.831984231596302)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[1]
      + (0.13773951362369624)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[2]
      + (0.033248462288313227)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[3];
    xnew[1] += (-1282.6182631360693)*pzt_Cfb_S7_U->pzt_error[2];
    xnew[2] = (-0.13773951362369627)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[1]
      + (0.63982700974886286)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[2]
      + (-0.30757002934736644)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[3];
    xnew[2] += (-445.20254803033816)*pzt_Cfb_S7_U->pzt_error[2];
    xnew[3] = (0.033248462288313095)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[1]
      + (0.30757002934736666)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[2]
      + (0.56336617061009242)*pzt_Cfb_S7_DW->fsm_Cfb_act3_DSTATE[3];
    xnew[3] += (134.91895164674804)*pzt_Cfb_S7_U->pzt_error[2];
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
