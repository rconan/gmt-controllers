/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pzt_Cfb_S1_3_5.h
 *
 * Code generated for Simulink model 'pzt_Cfb_S1_3_5'.
 *
 * Model version                  : 9.12
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Feb 26 14:45:30 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#ifndef RTW_HEADER_pzt_Cfb_S1_3_5_h_
#define RTW_HEADER_pzt_Cfb_S1_3_5_h_
#ifndef pzt_Cfb_S1_3_5_COMMON_INCLUDES_
#define pzt_Cfb_S1_3_5_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* pzt_Cfb_S1_3_5_COMMON_INCLUDES_ */

#include "pzt_Cfb_S1_3_5_types.h"
#include <string.h>
#include "rt_defines.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T fsm_Cfb_inner1_DSTATE[4];     /* '<S1>/fsm_Cfb_inner1' */
  real_T fsm_Cfb_inner2_DSTATE[4];     /* '<S1>/fsm_Cfb_inner2' */
  real_T fsm_Cfb_edge_DSTATE[6];       /* '<S1>/fsm_Cfb_edge' */
} DW_pzt_Cfb_S1_3_5_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: fsm_Cfb_edge_A
   * Referenced by: '<S1>/fsm_Cfb_edge'
   */
  real_T fsm_Cfb_edge_A[26];

  /* Computed Parameter: fsm_Cfb_edge_C
   * Referenced by: '<S1>/fsm_Cfb_edge'
   */
  real_T fsm_Cfb_edge_C[6];
} ConstP_pzt_Cfb_S1_3_5_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T pzt_error[3];                 /* '<Root>/pzt_error' */
} ExtU_pzt_Cfb_S1_3_5_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T pzt_control[3];               /* '<Root>/pzt_control' */
} ExtY_pzt_Cfb_S1_3_5_T;

/* Real-time Model Data Structure */
struct tag_RTM_pzt_Cfb_S1_3_5_T {
  DW_pzt_Cfb_S1_3_5_T *dwork;
};

/* Constant parameters (default storage) */
extern const ConstP_pzt_Cfb_S1_3_5_T pzt_Cfb_S1_3_5_ConstP;

/* Model entry point functions */
extern void pzt_Cfb_S1_3_5_initialize(RT_MODEL_pzt_Cfb_S1_3_5_T *const
  pzt_Cfb_S1_3_5_M);
extern void pzt_Cfb_S1_3_5_step(RT_MODEL_pzt_Cfb_S1_3_5_T *const
  pzt_Cfb_S1_3_5_M, ExtU_pzt_Cfb_S1_3_5_T *pzt_Cfb_S1_3_5_U,
  ExtY_pzt_Cfb_S1_3_5_T *pzt_Cfb_S1_3_5_Y);
extern void pzt_Cfb_S1_3_5_terminate(RT_MODEL_pzt_Cfb_S1_3_5_T *const
  pzt_Cfb_S1_3_5_M);

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
 * hilite_system('m2fsm_2_rust/pzt_Cfb_S1_3_5')    - opens subsystem m2fsm_2_rust/pzt_Cfb_S1_3_5
 * hilite_system('m2fsm_2_rust/pzt_Cfb_S1_3_5/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'm2fsm_2_rust'
 * '<S1>'   : 'm2fsm_2_rust/pzt_Cfb_S1_3_5'
 */
#endif                                 /* RTW_HEADER_pzt_Cfb_S1_3_5_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
