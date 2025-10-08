/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HP_dyn_dTF.c
 *
 * Code generated for Simulink model 'HP_dyn_dTF'.
 *
 * Model version                  : 9.28
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Oct  8 16:48:05 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#include "HP_dyn_dTF.h"
#include "rtwtypes.h"

/* Model step function */
void HP_dyn_dTF_step(RT_MODEL_HP_dyn_dTF_T *const HP_dyn_dTF_M,
                     ExtU_HP_dyn_dTF_T *HP_dyn_dTF_U, ExtY_HP_dyn_dTF_T
                     *HP_dyn_dTF_Y)
{
  DW_HP_dyn_dTF_T *HP_dyn_dTF_DW = HP_dyn_dTF_M->dwork;
  int32_T k;
  for (k = 0; k < 6; k++) {
    real_T denAccum;
    real_T denAccum_tmp;
    real_T denAccum_tmp_0;
    real_T denAccum_tmp_tmp;
    int32_T memOffset_tmp;

    /* DiscreteTransferFcn: '<S1>/HP_dyn_dTF' */
    memOffset_tmp = k << 2;
    denAccum_tmp = HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset_tmp + 1];
    denAccum_tmp_tmp = HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset_tmp + 2];
    denAccum_tmp_0 = HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset_tmp + 3];
    denAccum = (((HP_dyn_dTF_U->In1[k] - -3.964955008043662 *
                  HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset_tmp]) -
                 denAccum_tmp * 5.8959435313772541) - denAccum_tmp_tmp *
                -3.8970212872913796) - denAccum_tmp_0 * 0.96603276406824379;

    /* Outport: '<Root>/Out1' incorporates:
     *  DiscreteTransferFcn: '<S1>/HP_dyn_dTF'
     */
    HP_dyn_dTF_Y->Out1[k] = (((0.00017829945783371016 * denAccum +
      0.0003506925601551916 * HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset_tmp]) +
      denAccum_tmp * -0.0010603492385917923) + denAccum_tmp_tmp *
      0.00035617429752613622) + denAccum_tmp_0 * 0.00017518303353315513;

    /* Update for DiscreteTransferFcn: '<S1>/HP_dyn_dTF' */
    HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset_tmp + 3] = denAccum_tmp_tmp;
    HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset_tmp + 2] =
      HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset_tmp + 1];
    HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset_tmp + 1] =
      HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset_tmp];
    HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset_tmp] = denAccum;
  }
}

/* Model initialize function */
void HP_dyn_dTF_initialize(RT_MODEL_HP_dyn_dTF_T *const HP_dyn_dTF_M)
{
  /* (no initialization code required) */
  UNUSED_PARAMETER(HP_dyn_dTF_M);
}

/* Model terminate function */
void HP_dyn_dTF_terminate(RT_MODEL_HP_dyn_dTF_T *const HP_dyn_dTF_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(HP_dyn_dTF_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
