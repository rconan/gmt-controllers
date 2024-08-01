/*
 * File: m1hp_cpp.h
 *
 * Code generated for Simulink model 'm1hp_cpp'.
 *
 * Model version                  : 9.18
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Aug  1 09:58:43 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: Passed (8), Warnings (2), Error (0)
 */

#ifndef RTW_HEADER_m1hp_cpp_h_
#define RTW_HEADER_m1hp_cpp_h_
#ifndef m1hp_cpp_COMMON_INCLUDES_
#define m1hp_cpp_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#endif                                 /* m1hp_cpp_COMMON_INCLUDES_ */

#include "m1hp_cpp_types.h"
#include "rt_defines.h"
#include "zero_crossing_types.h"

/* Block signals and states (default storage) for system '<S1>/CPP with multi-axis coordination' */
typedef struct {
  real_T acc_merge;                    /* '<S2>/acc_merge' */
} DW_CoreSubsys_m1hp_cpp_T;

/* Block signals and states (default storage) for system '<S1>/Motion equations' */
typedef struct {
  real_T DiscreteTimeIntegrator;       /* '<S5>/Discrete-Time Integrator' */
  real_T x0_in;                        /* '<S23>/x0_in' */
  real_T v0_in;                        /* '<S23>/v0_in' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S5>/Discrete-Time Integrator' */
  real_T DelayInput1_DSTATE;           /* '<S22>/Delay Input1' */
  real_T TmpLatchAtTriggeredSubsystemInp;/* synthesized block */
  real_T TmpLatchAtTriggeredSubsystemI_e;/* synthesized block */
} DW_CoreSubsys_m1hp_cpp_f_T;

/* Zero-crossing (trigger) state for system '<S1>/Motion equations' */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE_c;/* '<S5>/Triggered Subsystem' */
} ZCE_CoreSubsys_m1hp_cpp_f_T;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_CoreSubsys_m1hp_cpp_f_T CoreSubsys_p[6];/* '<S1>/Motion equations' */
  DW_CoreSubsys_m1hp_cpp_T CoreSubsys[6];
                                   /* '<S1>/CPP with multi-axis coordination' */
  real_T Add[6];                       /* '<S7>/Add' */
  real_T Sub[6];                       /* '<S7>/Sub' */
  real_T ImpAsg_InsertedFor_a_l_at_inpor[6];/* '<S26>/MATLAB Function' */
  real_T TmpLatchAtTriggeredSubsystemInp[6];/* synthesized block */
  real_T TmpLatchAtTriggeredSubsystemI_e[6];/* synthesized block */
  uint32_T IndexVector;                /* '<S7>/Index Vector' */
  uint32_T IndexVector1;               /* '<S7>/Index Vector1' */
  uint32_T IndexVector2;               /* '<S7>/Index Vector2' */
  uint32_T Dk_merge;                   /* '<S3>/Dk_merge' */
  uint32_T UnitDelay_DSTATE;           /* '<S6>/Unit Delay' */
  uint32_T ResettableDelay_DSTATE;     /* '<S6>/Resettable Delay' */
  boolean_T Compare[6];                /* '<S27>/Compare' */
} DW_m1hp_cpp_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState ResettableDelay_Reset_ZCE;/* '<S6>/Resettable Delay' */
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S1>/Triggered Subsystem' */
  ZCE_CoreSubsys_m1hp_cpp_f_T CoreSubsys_p[6];/* '<S1>/Motion equations' */
} PrevZCX_m1hp_cpp_T;

/* Invariant block signals (default storage) */
typedef struct {
  const int16_T Width1;                /* '<S25>/Width1' */
} ConstB_m1hp_cpp_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T x_target[6];                  /* '<Root>/x_target' */
  real_T v_target[6];                  /* '<Root>/v_target' */
} ExtU_m1hp_cpp_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T pos_d[6];                     /* '<Root>/pos_d' */
  real_T vel_d[6];                     /* '<Root>/vel_d' */
  real_T acc_d[6];                     /* '<Root>/acc_d' */
} ExtY_m1hp_cpp_T;

/* Parameters for system: '<S2>/If Action Subsystem4' */
struct P_IfActionSubsystem4_m1hp_cpp_T_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S12>/Constant'
                                        */
};

/* Parameters for system: '<S1>/CPP with multi-axis coordination' */
struct P_CoreSubsys_m1hp_cpp_T_ {
  real_T Gain2_Gain;                   /* Expression: delta_sim
                                        * Referenced by: '<S9>/Gain2'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 2
                                        * Referenced by: '<S9>/Gain3'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T acc_merge_InitialOutput;      /* Expression: 0
                                        * Referenced by: '<S2>/acc_merge'
                                        */
  uint32_T Constant_Value_l;           /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S8>/Constant'
                                        */
  P_IfActionSubsystem4_m1hp_cpp_T IfActionSubsystem6;/* '<S2>/If Action Subsystem6' */
  P_IfActionSubsystem4_m1hp_cpp_T IfActionSubsystem5;/* '<S2>/If Action Subsystem5' */
  P_IfActionSubsystem4_m1hp_cpp_T IfActionSubsystem4;/* '<S2>/If Action Subsystem4' */
};

/* Parameters for system: '<S1>/Motion equations' */
struct P_CoreSubsys_m1hp_cpp_g_T_ {
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S22>/Delay Input1'
                                        */
  uint32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S21>/Constant'
                                       */
  real_T x0_Y0;                        /* Computed Parameter: x0_Y0
                                        * Referenced by: '<S23>/x0'
                                        */
  real_T v0_Y0;                        /* Expression: [v0]
                                        * Referenced by: '<S23>/v0'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S5>/Discrete-Time Integrator'
                            */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T TmpLatchAtTriggeredSubsystemInp;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpLatchAtTriggeredSubsystemI_j;/* Expression: 0
                                          * Referenced by:
                                          */
  uint32_T Gain1_Gain;                 /* Expression: delta_sim
                                        * Referenced by: '<S5>/Gain1'
                                        */
};

/* Parameters for system: '<S7>/Multi-axis demand' */
struct P_CoreSubsys_m1hp_cpp_gm_T_ {
  real_T Gain1_Gain;                   /* Expression: 1/delta_sim
                                        * Referenced by: '<S26>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/delta_sim
                                        * Referenced by: '<S26>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/delta_sim
                                        * Referenced by: '<S26>/Gain3'
                                        */
};

/* Parameters (default storage) */
struct P_m1hp_cpp_T_ {
  real_T a_max;                        /* Variable: a_max
                                        * Referenced by: '<S26>/Constant'
                                        */
  real_T v0;                           /* Variable: v0
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T v_max;                        /* Variable: v_max
                                        * Referenced by: '<S26>/Constant1'
                                        */
  uint32_T k_cmd;                      /* Variable: k_cmd
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T a_l_Y0;                       /* Computed Parameter: a_l_Y0
                                        * Referenced by: '<S7>/a_l'
                                        */
  real_T Dx_Y0;                        /* Computed Parameter: Dx_Y0
                                        * Referenced by: '<S7>/Dx'
                                        */
  real_T Dv_Y0;                        /* Computed Parameter: Dv_Y0
                                        * Referenced by: '<S7>/Dv'
                                        */
  real_T TmpLatchAtTriggeredSubsystemInp;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpLatchAtTriggeredSubsystemI_j;/* Expression: 0
                                          * Referenced by:
                                          */
  int32_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S27>/Constant'
                                        */
  uint32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S17>/Constant1'
                                        */
  uint32_T Dk_merge_InitialOutput; /* Computed Parameter: Dk_merge_InitialOutput
                                    * Referenced by: '<S3>/Dk_merge'
                                    */
  uint32_T k_a_ac_acd_Y0;              /* Computed Parameter: k_a_ac_acd_Y0
                                        * Referenced by: '<S7>/k_a_ac_acd'
                                        */
  uint32_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S4>/Constant'
                                        */
  uint32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S6>/Unit Delay'
                                */
  uint32_T ResettableDelay_InitialConditio;
                          /* Computed Parameter: ResettableDelay_InitialConditio
                           * Referenced by: '<S6>/Resettable Delay'
                           */
  uint32_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S6>/Constant'
                                        */
  int16_T max_idx_Y0;                  /* Computed Parameter: max_idx_Y0
                                        * Referenced by: '<S25>/max_idx'
                                        */
  int16_T Memory1_InitialCondition;    /* Expression: int16(1)
                                        * Referenced by: '<S25>/Memory1'
                                        */
  boolean_T max_bool_Y0;               /* Computed Parameter: max_bool_Y0
                                        * Referenced by: '<S25>/max_bool'
                                        */
  P_CoreSubsys_m1hp_cpp_gm_T CoreSubsys_pn;/* '<S7>/Multi-axis demand' */
  P_CoreSubsys_m1hp_cpp_g_T CoreSubsys_p;/* '<S1>/Motion equations' */
  P_CoreSubsys_m1hp_cpp_T CoreSubsys;
                                   /* '<S1>/CPP with multi-axis coordination' */
};

/* Real-time Model Data Structure */
struct tag_RTM_m1hp_cpp_T {
  PrevZCX_m1hp_cpp_T *prevZCSigState;
  DW_m1hp_cpp_T *dwork;
};

/* Block parameters (default storage) */
extern P_m1hp_cpp_T m1hp_cpp_P;
extern const ConstB_m1hp_cpp_T m1hp_cpp_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void m1hp_cpp_initialize(RT_MODEL_m1hp_cpp_T *const m1hp_cpp_M);
extern void m1hp_cpp_step(RT_MODEL_m1hp_cpp_T *const m1hp_cpp_M, ExtU_m1hp_cpp_T
  *m1hp_cpp_U, ExtY_m1hp_cpp_T *m1hp_cpp_Y);
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
 * '<S2>'   : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination'
 * '<S3>'   : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination1'
 * '<S4>'   : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Compare To Zero'
 * '<S5>'   : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Motion equations'
 * '<S6>'   : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Sample_generator'
 * '<S7>'   : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Triggered Subsystem'
 * '<S8>'   : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination/Compare To Zero'
 * '<S9>'   : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination/If Action Subsystem1'
 * '<S10>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination/If Action Subsystem2'
 * '<S11>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination/If Action Subsystem3'
 * '<S12>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination/If Action Subsystem4'
 * '<S13>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination/If Action Subsystem5'
 * '<S14>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination/If Action Subsystem6'
 * '<S15>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination/If Action Subsystem_1'
 * '<S16>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination/If Action Subsystem__1'
 * '<S17>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination1/If Action Subsystem'
 * '<S18>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination1/If Action Subsystem1'
 * '<S19>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination1/If Action Subsystem6'
 * '<S20>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/CPP with multi-axis coordination1/If Action Subsystem__1'
 * '<S21>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Motion equations/Compare To Constant'
 * '<S22>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Motion equations/Detect Change'
 * '<S23>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Motion equations/Triggered Subsystem'
 * '<S24>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Sample_generator/Compare To Constant'
 * '<S25>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Triggered Subsystem/Detect max t_seg'
 * '<S26>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Triggered Subsystem/Multi-axis demand'
 * '<S27>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Triggered Subsystem/Detect max t_seg/Compare To Zero'
 * '<S28>'  : 'M1DCS_2_rust/M1_HP_Dynamics/m1hp_cpp/Triggered Subsystem/Multi-axis demand/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_m1hp_cpp_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
