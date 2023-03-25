/*
 * File: C_ngao.h
 *
 * Code generated for Simulink model 'C_ngao'.
 *
 * Model version                  : 5.56
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Mar 17 19:17:33 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_C_ngao_h_
#define RTW_HEADER_C_ngao_h_
#include <string.h>
#ifndef C_ngao_COMMON_INCLUDES_
#define C_ngao_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* C_ngao_COMMON_INCLUDES_ */

#include "C_ngao_types.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T NGAOTemporalController_states[2];/* '<S1>/NGAO Temporal Controller' */
} DW_C_ngao_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Delta_m;                      /* '<Root>/Delta_m' */
} ExtU_C_ngao_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T m;                            /* '<Root>/m' */
} ExtY_C_ngao_T;

/* Parameters (default storage) */
struct P_C_ngao_T_ {
  real_T Cngao_d_den[3];               /* Variable: Cngao_d_den
                                        * Referenced by: '<S1>/NGAO Temporal Controller'
                                        */
  real_T Cngao_d_num[3];               /* Variable: Cngao_d_num
                                        * Referenced by: '<S1>/NGAO Temporal Controller'
                                        */
  real_T NGAOTemporalController_InitialStates;/* Expression: 0
                                               * Referenced by: '<S1>/NGAO Temporal Controller'
                                               */
};

/* Real-time Model Data Structure */
struct tag_RTM_C_ngao_T {
  DW_C_ngao_T *dwork;
};

/* Block parameters (default storage) */
extern P_C_ngao_T C_ngao_P;

/* Model entry point functions */
extern void C_ngao_initialize(RT_MODEL_C_ngao_T *const C_ngao_M, ExtU_C_ngao_T
  *C_ngao_U, ExtY_C_ngao_T *C_ngao_Y);
extern void C_ngao_step(RT_MODEL_C_ngao_T *const C_ngao_M, ExtU_C_ngao_T
  *C_ngao_U, ExtY_C_ngao_T *C_ngao_Y);
extern void C_ngao_terminate(RT_MODEL_C_ngao_T *const C_ngao_M);

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
 * hilite_system('ao_2_rust/C_ngao')    - opens subsystem ao_2_rust/C_ngao
 * hilite_system('ao_2_rust/C_ngao/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ao_2_rust'
 * '<S1>'   : 'ao_2_rust/C_ngao'
 */
#endif                                 /* RTW_HEADER_C_ngao_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
