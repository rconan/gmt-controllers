/*
 * File: M2P_act_Cfb.h
 *
 * Code generated for Simulink model 'M2P_act_Cfb'.
 *
 * Model version                  : 5.53
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Feb 28 13:57:41 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_M2P_act_Cfb_h_
#define RTW_HEADER_M2P_act_Cfb_h_
#include <string.h>
#ifndef M2P_act_Cfb_COMMON_INCLUDES_
#define M2P_act_Cfb_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* M2P_act_Cfb_COMMON_INCLUDES_ */

#include "M2P_act_Cfb_types.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T M2P_I_rolloffF_states[3];     /* '<S1>/M2P_I_rolloffF' */
} DW_M2P_act_Cfb_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T M2pAct_E;                     /* '<Root>/M2pAct_E' */
} ExtU_M2P_act_Cfb_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T M2pAct_U;                     /* '<Root>/M2pAct_U' */
} ExtY_M2P_act_Cfb_T;

/* Parameters (default storage) */
struct P_M2P_act_Cfb_T_ {
  real_T fc;                           /* Variable: fc
                                        * Referenced by: '<S1>/m2p_om_c'
                                        */
  real_T k2p_stiff;                    /* Variable: k2p_stiff
                                        * Referenced by: '<S1>/k2p_stiff'
                                        */
  real_T M2P_I_rolloffF_NumCoef[4];    /* Expression: m2p_Cfb_d.num{1}
                                        * Referenced by: '<S1>/M2P_I_rolloffF'
                                        */
  real_T M2P_I_rolloffF_DenCoef[4];    /* Expression: m2p_Cfb_d.den{1}
                                        * Referenced by: '<S1>/M2P_I_rolloffF'
                                        */
  real_T M2P_I_rolloffF_InitialStates; /* Expression: 0
                                        * Referenced by: '<S1>/M2P_I_rolloffF'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_M2P_act_Cfb_T {
  DW_M2P_act_Cfb_T *dwork;
};

/* Block parameters (default storage) */
extern P_M2P_act_Cfb_T M2P_act_Cfb_P;

/* Model entry point functions */
extern void M2P_act_Cfb_initialize(RT_MODEL_M2P_act_Cfb_T *const M2P_act_Cfb_M,
  ExtU_M2P_act_Cfb_T *M2P_act_Cfb_U, ExtY_M2P_act_Cfb_T *M2P_act_Cfb_Y);
extern void M2P_act_Cfb_step(RT_MODEL_M2P_act_Cfb_T *const M2P_act_Cfb_M,
  ExtU_M2P_act_Cfb_T *M2P_act_Cfb_U, ExtY_M2P_act_Cfb_T *M2P_act_Cfb_Y);
extern void M2P_act_Cfb_terminate(RT_MODEL_M2P_act_Cfb_T *const M2P_act_Cfb_M);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('m2asm_2_rust/M2P_act_Cfb')    - opens subsystem m2asm_2_rust/M2P_act_Cfb
 * hilite_system('m2asm_2_rust/M2P_act_Cfb/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'm2asm_2_rust'
 * '<S1>'   : 'm2asm_2_rust/M2P_act_Cfb'
 */
#endif                                 /* RTW_HEADER_M2P_act_Cfb_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
