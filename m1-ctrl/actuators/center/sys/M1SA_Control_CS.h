/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: M1SA_Control_CS.h
 *
 * Code generated for Simulink model 'M1SA_Control_CS'.
 *
 * Model version                  : 9.26
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Sep 25 16:24:14 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
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
  real_T CS_SSdtC_Fx_DSTATE[3];        /* '<S2>/CS_SSdtC_Fx' */
  real_T CS_SSdtC_Fy_DSTATE[3];        /* '<S2>/CS_SSdtC_Fy' */
  real_T CS_SSdtC_Fz_DSTATE[3];        /* '<S2>/CS_SSdtC_Fz' */
  real_T CS_SSdtC_Mx_DSTATE[3];        /* '<S2>/CS_SSdtC_Mx' */
  real_T CS_SSdtC_My_DSTATE[3];        /* '<S2>/CS_SSdtC_My' */
  real_T CS_SSdtC_Mz_DSTATE[3];        /* '<S2>/CS_SSdtC_Mz' */
  real_T CS_SA_dyn_states[612];        /* '<S1>/CS_SA_dyn' */
} DW_M1SA_Control_CS_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: CS_Kbal
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
 * '<S2>'   : 'M1DCS_2_rust/M1SA_Control_CS/SSdtC_x6'
 */
#endif                                 /* RTW_HEADER_M1SA_Control_CS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
