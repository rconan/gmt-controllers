/*
 * File: Mount_Drv_PDR2021L.h
 *
 * Code generated for Simulink model 'Mount_Drv_PDR2021L'.
 *
 * Model version                  : 9.75
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Mar  7 14:22:00 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#ifndef RTW_HEADER_Mount_Drv_PDR2021L_h_
#define RTW_HEADER_Mount_Drv_PDR2021L_h_
#ifndef Mount_Drv_PDR2021L_COMMON_INCLUDES_
#define Mount_Drv_PDR2021L_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Mount_Drv_PDR2021L_COMMON_INCLUDES_ */

#include "Mount_Drv_PDR2021L_types.h"
#include "rt_defines.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T AZ_delay_DSTATE[32];          /* '<S1>/AZ_delay' */
  real_T EL_delay_DSTATE[32];          /* '<S1>/EL_delay' */
  real_T GIR_delay_DSTATE[32];         /* '<S1>/GIR_delay' */
  real_T AZ_TFd_states;                /* '<S1>/AZ_TFd' */
  real_T EL_TFd_states;                /* '<S1>/EL_TFd' */
  real_T GIR_TFd_states;               /* '<S1>/GIR_TFd' */
  uint32_T CircBufIdx;                 /* '<S1>/AZ_delay' */
  uint32_T CircBufIdx_a;               /* '<S1>/EL_delay' */
  uint32_T CircBufIdx_i;               /* '<S1>/GIR_delay' */
} DW_Mount_Drv_PDR2021L_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: blkdiag(1/12*ones(12,1),1/4*ones(4,1),1/4*ones(4,1))
   * Referenced by: '<S1>/Split_Drv_To'
   */
  real_T Split_Drv_To_Gain[60];
} ConstP_Mount_Drv_PDR2021L_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Mount_cmd[3];                 /* '<Root>/Mount_cmd' */
  real_T Mount_drv_Po;                 /* '<Root>/Mount_drv_Po' */
} ExtU_Mount_Drv_PDR2021L_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Mount_T[20];                  /* '<Root>/Mount_T' */
} ExtY_Mount_Drv_PDR2021L_T;

/* Real-time Model Data Structure */
struct tag_RTM_Mount_Drv_PDR2021L_T {
  DW_Mount_Drv_PDR2021L_T *dwork;
};

/* Constant parameters (default storage) */
extern const ConstP_Mount_Drv_PDR2021L_T Mount_Drv_PDR2021L_ConstP;

/* Model entry point functions */
extern void Mount_Drv_PDR2021L_initialize(RT_MODEL_Mount_Drv_PDR2021L_T *const
  Mount_Drv_PDR2021L_M);
extern void Mount_Drv_PDR2021L_step(RT_MODEL_Mount_Drv_PDR2021L_T *const
  Mount_Drv_PDR2021L_M, ExtU_Mount_Drv_PDR2021L_T *Mount_Drv_PDR2021L_U,
  ExtY_Mount_Drv_PDR2021L_T *Mount_Drv_PDR2021L_Y);
extern void Mount_Drv_PDR2021L_terminate(RT_MODEL_Mount_Drv_PDR2021L_T *const
  Mount_Drv_PDR2021L_M);

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
 * hilite_system('mount_2_rust/Mount_Drv_PDR2021L')    - opens subsystem mount_2_rust/Mount_Drv_PDR2021L
 * hilite_system('mount_2_rust/Mount_Drv_PDR2021L/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'mount_2_rust'
 * '<S1>'   : 'mount_2_rust/Mount_Drv_PDR2021L'
 */
#endif                                 /* RTW_HEADER_Mount_Drv_PDR2021L_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
