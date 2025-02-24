/*
 * File: m1hp_cpp.h
 *
 * Code generated for Simulink model 'm1hp_cpp'.
 *
 * Model version                  : 9.24
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Aug  2 14:52:37 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: Passed (9), Warning (1), Error (0)
 */

#ifndef RTW_HEADER_m1hp_cpp_h_
#define RTW_HEADER_m1hp_cpp_h_
#ifndef m1hp_cpp_COMMON_INCLUDES_
#define m1hp_cpp_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#endif /* m1hp_cpp_COMMON_INCLUDES_ */

#include "m1hp_cpp_types.h"
#include <string.h>
#include "rt_defines.h"
#include "zero_crossing_types.h"

/* Block signals and states (default storage) for system '<S1>/Bessel filter' */
typedef struct
{
  real_T BesselfilterAcc_DSTATE[4]; /* '<S9>/Bessel filter Acc' */
  real_T BesselfilterPos_DSTATE[4]; /* '<S9>/Bessel filter Pos' */
  real_T BesselfilterVel_DSTATE[4]; /* '<S9>/Bessel filter Vel' */
} DW_CoreSubsys_m1hp_cpp_T;

/* Block signals and states (default storage) for system '<S1>/CPP with multi-axis coordination' */
typedef struct
{
  real_T acc_merge; /* '<S3>/acc_merge' */
} DW_CoreSubsys_m1hp_cpp_f_T;

/* Block signals and states (default storage) for system '<S1>/Motion equations' */
typedef struct
{
  real_T DiscreteTimeIntegrator;          /* '<S6>/Discrete-Time Integrator' */
  real_T x0_in;                           /* '<S25>/x0_in' */
  real_T v0_in;                           /* '<S25>/v0_in' */
  real_T DiscreteTimeIntegrator_DSTATE;   /* '<S6>/Discrete-Time Integrator' */
  real_T DelayInput1_DSTATE;              /* '<S24>/Delay Input1' */
  real_T TmpLatchAtTriggeredSubsystemInp; /* synthesized block */
  real_T TmpLatchAtTriggeredSubsystemI_e; /* synthesized block */
} DW_CoreSubsys_m1hp_cpp_fw_T;

/* Zero-crossing (trigger) state for system '<S1>/Motion equations' */
typedef struct
{
  ZCSigState TriggeredSubsystem_Trig_ZCE_c; /* '<S6>/Triggered Subsystem' */
} ZCE_CoreSubsys_m1hp_cpp_fe_T;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct
{
  DW_CoreSubsys_m1hp_cpp_fw_T CoreSubsys_pn[6]; /* '<S1>/Motion equations' */
  DW_CoreSubsys_m1hp_cpp_f_T CoreSubsys_p[6];
  /* '<S1>/CPP with multi-axis coordination' */
  DW_CoreSubsys_m1hp_cpp_T CoreSubsys[6];    /* '<S1>/Bessel filter' */
  real_T Add[6];                             /* '<S8>/Add' */
  real_T Sub[6];                             /* '<S8>/Sub' */
  real_T ImpAsg_InsertedFor_a_l_at_inpor[6]; /* '<S28>/MATLAB Function' */
  real_T ImpAsg_InsertedFor_multi_ax_acc[6]; /* '<S3>/acc_merge' */
  real_T TmpLatchAtTriggeredSubsystemInp[6]; /* synthesized block */
  real_T TmpLatchAtTriggeredSubsystemI_e[6]; /* synthesized block */
  uint32_T IndexVector;                      /* '<S8>/Index Vector' */
  uint32_T IndexVector1;                     /* '<S8>/Index Vector1' */
  uint32_T IndexVector2;                     /* '<S8>/Index Vector2' */
  uint32_T Dk_merge;                         /* '<S4>/Dk_merge' */
  uint32_T UnitDelay_DSTATE;                 /* '<S7>/Unit Delay' */
  uint32_T ResettableDelay_DSTATE;           /* '<S7>/Resettable Delay' */
  boolean_T Compare[6];                      /* '<S29>/Compare' */
} DW_m1hp_cpp_T;

/* Zero-crossing (trigger) state */
typedef struct
{
  ZCSigState ResettableDelay_Reset_ZCE;          /* '<S7>/Resettable Delay' */
  ZCSigState TriggeredSubsystem_Trig_ZCE;        /* '<S1>/Triggered Subsystem' */
  ZCE_CoreSubsys_m1hp_cpp_fe_T CoreSubsys_pn[6]; /* '<S1>/Motion equations' */
} PrevZCX_m1hp_cpp_T;

/* External inputs (root inport signals with default storage) */
typedef struct
{
  real_T x_target[6]; /* '<Root>/x_target' */
  real_T v_target[6]; /* '<Root>/v_target' */
} ExtU_m1hp_cpp_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct
{
  real_T pos_d[6]; /* '<Root>/pos_d' */
  real_T vel_d[6]; /* '<Root>/vel_d' */
  real_T acc_d[6]; /* '<Root>/acc_d' */
} ExtY_m1hp_cpp_T;

/* Real-time Model Data Structure */
struct tag_RTM_m1hp_cpp_T
{
  PrevZCX_m1hp_cpp_T *prevZCSigState;
  DW_m1hp_cpp_T *dwork;
};

/* Model entry point functions */
extern void m1hp_cpp_initialize(RT_MODEL_m1hp_cpp_T *const m1hp_cpp_M);
extern void m1hp_cpp_step(RT_MODEL_m1hp_cpp_T *const m1hp_cpp_M, ExtU_m1hp_cpp_T *m1hp_cpp_U, ExtY_m1hp_cpp_T *m1hp_cpp_Y);
extern void m1hp_cpp_terminate(RT_MODEL_m1hp_cpp_T *const m1hp_cpp_M);

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
 * hilite_system('M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp')    - opens subsystem M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp
 * hilite_system('M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'M1DCS_2_rust/M1_HP_Dynamics'
 * '<S1>'   : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp'
 * '<S2>'   : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Bessel filter'
 * '<S3>'   : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination'
 * '<S4>'   : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination1'
 * '<S5>'   : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Compare To Zero'
 * '<S6>'   : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Motion equations'
 * '<S7>'   : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Sample_generator'
 * '<S8>'   : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Triggered Subsystem'
 * '<S9>'   : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Bessel filter/Jerk-limitation'
 * '<S10>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination/Compare To Zero'
 * '<S11>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination/If Action Subsystem1'
 * '<S12>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination/If Action Subsystem2'
 * '<S13>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination/If Action Subsystem3'
 * '<S14>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination/If Action Subsystem4'
 * '<S15>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination/If Action Subsystem5'
 * '<S16>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination/If Action Subsystem6'
 * '<S17>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination/If Action Subsystem_1'
 * '<S18>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination/If Action Subsystem__1'
 * '<S19>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination1/If Action Subsystem'
 * '<S20>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination1/If Action Subsystem1'
 * '<S21>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination1/If Action Subsystem6'
 * '<S22>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination1/If Action Subsystem__1'
 * '<S23>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Motion equations/Compare To Constant'
 * '<S24>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Motion equations/Detect Change'
 * '<S25>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Motion equations/Triggered Subsystem'
 * '<S26>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Sample_generator/Compare To Constant'
 * '<S27>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Triggered Subsystem/Detect max t_seg'
 * '<S28>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Triggered Subsystem/Multi-axis demand'
 * '<S29>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Triggered Subsystem/Detect max t_seg/Compare To Zero'
 * '<S30>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Triggered Subsystem/Multi-axis demand/MATLAB Function'
 */
#endif /* RTW_HEADER_m1hp_cpp_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
