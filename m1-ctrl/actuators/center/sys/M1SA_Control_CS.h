/*
 * File: M1SA_Control_CS.h
 *
 * Code generated for Simulink model 'M1SA_Control_CS'.
 *
 * Model version                  : 9.6
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Apr 14 14:01:52 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_M1SA_Control_CS_h_
#define RTW_HEADER_M1SA_Control_CS_h_
#ifndef M1SA_Control_CS_COMMON_INCLUDES_
#define M1SA_Control_CS_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* M1SA_Control_CS_COMMON_INCLUDES_ */

#include "M1SA_Control_CS_types.h"
#include <string.h>
#include "rt_defines.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Fxcontroller_DSTATE[3];       /* '<S2>/Fx controller' */
  real_T Fycontroller_DSTATE[3];       /* '<S2>/Fy controller' */
  real_T Fzcontroller_DSTATE[3];       /* '<S2>/Fz controller' */
  real_T Mxcontroller_DSTATE[3];       /* '<S2>/Mx controller' */
  real_T Mycontroller_DSTATE[3];       /* '<S2>/My controller' */
  real_T Mzcontroller_DSTATE[3];       /* '<S2>/Mz controller' */
  real_T CS_SA_dyn_states[306];        /* '<S1>/CS_SA_dyn' */
} DW_M1SA_Control_CS_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: m1sys{7}.Kbal
   * Referenced by: '<S1>/CS_Kbal'
   */
  real_T CS_Kbal_Gain[1836];
} ConstP_M1SA_Control_CS_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T LC_FxyzMxyz_CG[6];            /* '<Root>/LC_FxyzMxyz_CG' */
  real_T SA_offsetF_cmd[306];          /* '<Root>/SA_offsetF_cmd' */
} ExtU_M1SA_Control_CS_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Res_Act_F[306];               /* '<Root>/Res_Act_F' */
} ExtY_M1SA_Control_CS_T;

/* Real-time Model Data Structure */
struct tag_RTM_M1SA_Control_CS_T {
  DW_M1SA_Control_CS_T *dwork;
};

/* Constant parameters (default storage) */
extern const ConstP_M1SA_Control_CS_T M1SA_Control_CS_ConstP;

/* Model entry point functions */
extern void M1SA_Control_CS_initialize(RT_MODEL_M1SA_Control_CS_T *const
  M1SA_Control_CS_M);
extern void M1SA_Control_CS_step(RT_MODEL_M1SA_Control_CS_T *const
  M1SA_Control_CS_M, ExtU_M1SA_Control_CS_T *M1SA_Control_CS_U,
  ExtY_M1SA_Control_CS_T *M1SA_Control_CS_Y);
extern void M1SA_Control_CS_terminate(RT_MODEL_M1SA_Control_CS_T *const
  M1SA_Control_CS_M);

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
 * hilite_system('M1DCS_2_rust/M1SA_Control_CS')    - opens subsystem M1DCS_2_rust/M1SA_Control_CS
 * hilite_system('M1DCS_2_rust/M1SA_Control_CS/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'M1DCS_2_rust'
 * '<S1>'   : 'M1DCS_2_rust/M1SA_Control_CS'
 * '<S2>'   : 'M1DCS_2_rust/M1SA_Control_CS/CS_ofl_SSdtC'
 */
#endif                                 /* RTW_HEADER_M1SA_Control_CS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
