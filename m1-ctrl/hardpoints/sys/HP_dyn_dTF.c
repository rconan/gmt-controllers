/*
 * File: HP_dyn_dTF.c
 *
 * Code generated for Simulink model 'HP_dyn_dTF'.
 *
 * Model version                  : 9.2
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Apr 12 14:39:19 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#include "HP_dyn_dTF.h"
#include "rtwtypes.h"

/* Model step function */
void HP_dyn_dTF_step(RT_MODEL_HP_dyn_dTF_T *const HP_dyn_dTF_M, real_T
                     HP_dyn_dTF_U_In1[6], real_T HP_dyn_dTF_Y_Out1[6])
{
  DW_HP_dyn_dTF_T *HP_dyn_dTF_DW = HP_dyn_dTF_M->dwork;
  int32_T k;
  for (k = 0; k < 6; k++) {
    real_T denAccum;
    real_T denAccum_tmp;
    real_T denAccum_tmp_0;
    real_T denAccum_tmp_tmp;
    int32_T memOffset_tmp;

    /* DiscreteTransferFcn: '<S1>/HP_dyn_dTF' incorporates:
     *  Inport: '<Root>/In1'
     */
    memOffset_tmp = k << 2;
    denAccum_tmp = HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset_tmp + 1];
    denAccum_tmp_tmp = HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset_tmp + 2];
    denAccum_tmp_0 = HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset_tmp + 3];
    denAccum = (((HP_dyn_dTF_U_In1[k] - -3.9324030529437657 *
                  HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset_tmp]) -
                 denAccum_tmp * 5.7980159366164923) - denAccum_tmp_tmp *
                -3.7988189837355097) - denAccum_tmp_0 * 0.93320610759369726;

    /* Outport: '<Root>/Out1' incorporates:
     *  DiscreteTransferFcn: '<S1>/HP_dyn_dTF'
     */
    HP_dyn_dTF_Y_Out1[k] = (((0.00010538306295552853 * denAccum +
      9.3078381572247558E-7 * HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset_tmp]) +
      denAccum_tmp * -0.00020983345936705571) + denAccum_tmp_tmp *
      -9.27018359164759E-7) + denAccum_tmp_0 * 0.00010445416186808491;

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
