/*
 * File: Mount_Control.h
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

#ifndef RTW_HEADER_Mount_Control_h_
#define RTW_HEADER_Mount_Control_h_
#ifndef Mount_Control_COMMON_INCLUDES_
#define Mount_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Mount_Control_COMMON_INCLUDES_ */

#include "Mount_Control_types.h"
#include <string.h>
#include "rt_defines.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T AZFFcontroller_DSTATE[2];     /* '<S1>/AZ FF controller' */
  real_T ELFFcontroller_DSTATE[2];     /* '<S1>/EL FF controller' */
  real_T GIRFFcontroller_DSTATE[2];    /* '<S1>/GIR FF controller' */
  real_T AZFBcontroller_DSTATE[13];    /* '<S1>/AZ FB controller' */
  real_T ELFBcontroller_DSTATE[11];    /* '<S1>/EL FB controller' */
  real_T GIRFBcontroller_DSTATE[7];    /* '<S1>/GIR FB controller' */
} DW_Mount_Control_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: blkdiag(1/4*ones(1,4),1/6*ones(1,6),1/4*ones(1,4))
   * Referenced by: '<S1>/Drv_Pos_avg'
   */
  real_T Drv_Pos_avg_Gain[42];

  /* Computed Parameter: AZFBcontroller_A
   * Referenced by: '<S1>/AZ FB controller'
   */
  real_T AZFBcontroller_A[145];

  /* Computed Parameter: AZFBcontroller_C
   * Referenced by: '<S1>/AZ FB controller'
   */
  real_T AZFBcontroller_C[13];

  /* Computed Parameter: ELFBcontroller_A
   * Referenced by: '<S1>/EL FB controller'
   */
  real_T ELFBcontroller_A[101];

  /* Computed Parameter: ELFBcontroller_C
   * Referenced by: '<S1>/EL FB controller'
   */
  real_T ELFBcontroller_C[11];

  /* Computed Parameter: GIRFBcontroller_A
   * Referenced by: '<S1>/GIR FB controller'
   */
  real_T GIRFBcontroller_A[37];

  /* Computed Parameter: GIRFBcontroller_C
   * Referenced by: '<S1>/GIR FB controller'
   */
  real_T GIRFBcontroller_C[7];
} ConstP_Mount_Control_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Mount_SP[3];                  /* '<Root>/Mount_SP' */
  real_T Mount_FB[14];                 /* '<Root>/Mount_FB' */
} ExtU_Mount_Control_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Mount_cmd[3];                 /* '<Root>/Mount_cmd' */
} ExtY_Mount_Control_T;

/* Real-time Model Data Structure */
struct tag_RTM_Mount_Control_T {
  DW_Mount_Control_T *dwork;
};

/* Constant parameters (default storage) */
extern const ConstP_Mount_Control_T Mount_Control_ConstP;

/* Model entry point functions */
extern void Mount_Control_initialize(RT_MODEL_Mount_Control_T *const
  Mount_Control_M);
extern void Mount_Control_step(RT_MODEL_Mount_Control_T *const Mount_Control_M,
  ExtU_Mount_Control_T *Mount_Control_U, ExtY_Mount_Control_T *Mount_Control_Y);
extern void Mount_Control_terminate(RT_MODEL_Mount_Control_T *const
  Mount_Control_M);

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
 * hilite_system('mount_2_rust/Mount_Control')    - opens subsystem mount_2_rust/Mount_Control
 * hilite_system('mount_2_rust/Mount_Control/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'mount_2_rust'
 * '<S1>'   : 'mount_2_rust/Mount_Control'
 */
#endif                                 /* RTW_HEADER_Mount_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
