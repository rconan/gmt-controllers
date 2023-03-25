/*
 * File: HP_dyn_dTF.c
 *
 * Code generated for Simulink model 'HP_dyn_dTF'.
 *
 * Model version                  : 5.28
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Jan 24 16:35:10 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HP_dyn_dTF.h"
#include "HP_dyn_dTF_private.h"

/* Model step function */
void HP_dyn_dTF_step(RT_MODEL_HP_dyn_dTF_T *const HP_dyn_dTF_M,
                     ExtU_HP_dyn_dTF_T *HP_dyn_dTF_U, ExtY_HP_dyn_dTF_T
                     *HP_dyn_dTF_Y)
{
  DW_HP_dyn_dTF_T *HP_dyn_dTF_DW = HP_dyn_dTF_M->dwork;
  real_T HP_dyn_dTF_tmp[6];
  real_T denAccum;
  int32_T k;
  int32_T memOffset;
  for (k = 0; k < 6; k++) {
    /* DiscreteTransferFcn: '<S1>/HP_dyn_dTF' incorporates:
     *  Inport: '<Root>/In1'
     */
    memOffset = k << 2;
    denAccum = (((HP_dyn_dTF_U->In1[k] - -3.9324030529437657 *
                  HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset]) -
                 HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset + 1] *
                 5.7980159366164923) - HP_dyn_dTF_DW->
                HP_dyn_dTF_states[memOffset + 2] * -3.7988189837355097) -
      HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset + 3] * 0.93320610759369726;
    HP_dyn_dTF_tmp[k] = denAccum;
    denAccum *= 0.00010538306295552853;
    denAccum += 9.3078381572247558E-7 * HP_dyn_dTF_DW->
      HP_dyn_dTF_states[memOffset];
    denAccum += HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset + 1] *
      -0.00020983345936705571;
    denAccum += HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset + 2] *
      -9.27018359164759E-7;

    /* Outport: '<Root>/Out1' incorporates:
     *  DiscreteTransferFcn: '<S1>/HP_dyn_dTF'
     */
    HP_dyn_dTF_Y->Out1[k] = HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset + 3] *
      0.00010445416186808491 + denAccum;
  }

  /* Update for DiscreteTransferFcn: '<S1>/HP_dyn_dTF' */
  for (k = 0; k < 6; k++) {
    memOffset = k << 2;
    HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset + 3] =
      HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset + 2];
    HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset + 2] =
      HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset + 1];
    HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset + 1] =
      HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset];
    HP_dyn_dTF_DW->HP_dyn_dTF_states[memOffset] = HP_dyn_dTF_tmp[k];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/HP_dyn_dTF' */
}

/* Model initialize function */
void HP_dyn_dTF_initialize(RT_MODEL_HP_dyn_dTF_T *const HP_dyn_dTF_M,
  ExtU_HP_dyn_dTF_T *HP_dyn_dTF_U, ExtY_HP_dyn_dTF_T *HP_dyn_dTF_Y)
{
  DW_HP_dyn_dTF_T *HP_dyn_dTF_DW = HP_dyn_dTF_M->dwork;

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)HP_dyn_dTF_DW, 0,
                sizeof(DW_HP_dyn_dTF_T));

  /* external inputs */
  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      HP_dyn_dTF_U->In1[i] = 0.0;
    }
  }

  /* external outputs */
  (void) memset(&HP_dyn_dTF_Y->Out1[0], 0,
                6U*sizeof(real_T));
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
