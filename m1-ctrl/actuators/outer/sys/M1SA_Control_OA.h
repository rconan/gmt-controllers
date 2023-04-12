/*
 * File: M1SA_Control_OA.h
 *
 * Code generated for Simulink model 'M1SA_Control_OA'.
 *
 * Model version                  : 9.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Apr 10 12:12:33 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#ifndef RTW_HEADER_M1SA_Control_OA_h_
#define RTW_HEADER_M1SA_Control_OA_h_
#ifndef M1SA_Control_OA_COMMON_INCLUDES_
#define M1SA_Control_OA_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* M1SA_Control_OA_COMMON_INCLUDES_ */

#include "M1SA_Control_OA_types.h"
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
  real_T OA_SA_dyn_states[335];        /* '<S1>/OA_SA_dyn' */
} DW_M1SA_Control_OA_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: m1sys{1}.Kbal
   * Referenced by: '<S1>/OAseg_Kbal'
   */
  real_T OAseg_Kbal_Gain[2010];
} ConstP_M1SA_Control_OA_T;

/* Real-time Model Data Structure */
struct tag_RTM_M1SA_Control_OA_T {
  DW_M1SA_Control_OA_T *dwork;
};

/* Constant parameters (default storage) */
extern const ConstP_M1SA_Control_OA_T M1SA_Control_OA_ConstP;

/* Model entry point functions */
extern void M1SA_Control_OA_initialize(RT_MODEL_M1SA_Control_OA_T *const
  M1SA_Control_OA_M);
extern void M1SA_Control_OA_step(RT_MODEL_M1SA_Control_OA_T *const
  M1SA_Control_OA_M, real_T M1SA_Control_OA_U_LC_FxyzMxyz_CG[6], real_T
  M1SA_Control_OA_U_SA_offsetF_cmd[335], real_T M1SA_Control_OA_Y_Res_Act_F[335]);
extern void M1SA_Control_OA_terminate(RT_MODEL_M1SA_Control_OA_T *const
  M1SA_Control_OA_M);

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
 * hilite_system('M1DCS_2_rust/M1SA_Control_OA')    - opens subsystem M1DCS_2_rust/M1SA_Control_OA
 * hilite_system('M1DCS_2_rust/M1SA_Control_OA/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'M1DCS_2_rust'
 * '<S1>'   : 'M1DCS_2_rust/M1SA_Control_OA'
 * '<S2>'   : 'M1DCS_2_rust/M1SA_Control_OA/OA_ofl_SSdtC'
 */
#endif                                 /* RTW_HEADER_M1SA_Control_OA_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
