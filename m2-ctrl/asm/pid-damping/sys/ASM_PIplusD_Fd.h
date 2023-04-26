/*
 * File: ASM_PIplusD_Fd.h
 *
 * Code generated for Simulink model 'ASM_PIplusD_Fd'.
 *
 * Model version                  : 9.5
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Apr 26 17:28:28 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#ifndef RTW_HEADER_ASM_PIplusD_Fd_h_
#define RTW_HEADER_ASM_PIplusD_Fd_h_
#ifndef ASM_PIplusD_Fd_COMMON_INCLUDES_
#define ASM_PIplusD_Fd_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ASM_PIplusD_Fd_COMMON_INCLUDES_ */

#include "ASM_PIplusD_Fd_types.h"
#include "rt_defines.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T ASMPIcontroller_states;       /* '<S1>/ASM PI controller' */
  real_T Numericaldifferentiation_states;/* '<S1>/Numerical differentiation' */
} DW_ASM_PIplusD_Fd_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T asm_SP;                       /* '<Root>/asm_SP' */
  real_T asm_FB;                       /* '<Root>/asm_FB' */
  real_T asm_FF;                       /* '<Root>/asm_FF' */
} ExtU_ASM_PIplusD_Fd_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T asm_U;                        /* '<Root>/asm_U' */
  real_T asm_Fd;                       /* '<Root>/asm_Fd' */
} ExtY_ASM_PIplusD_Fd_T;

/* Real-time Model Data Structure */
struct tag_RTM_ASM_PIplusD_Fd_T {
  DW_ASM_PIplusD_Fd_T *dwork;
};

/* Model entry point functions */
extern void ASM_PIplusD_Fd_initialize(RT_MODEL_ASM_PIplusD_Fd_T *const
  ASM_PIplusD_Fd_M);
extern void ASM_PIplusD_Fd_step(RT_MODEL_ASM_PIplusD_Fd_T *const
  ASM_PIplusD_Fd_M, ExtU_ASM_PIplusD_Fd_T *ASM_PIplusD_Fd_U,
  ExtY_ASM_PIplusD_Fd_T *ASM_PIplusD_Fd_Y);
extern void ASM_PIplusD_Fd_terminate(RT_MODEL_ASM_PIplusD_Fd_T *const
  ASM_PIplusD_Fd_M);

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
 * hilite_system('m2asm_2_rust/ASM_PIplusD_Fd')    - opens subsystem m2asm_2_rust/ASM_PIplusD_Fd
 * hilite_system('m2asm_2_rust/ASM_PIplusD_Fd/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'm2asm_2_rust'
 * '<S1>'   : 'm2asm_2_rust/ASM_PIplusD_Fd'
 */
#endif                                 /* RTW_HEADER_ASM_PIplusD_Fd_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
