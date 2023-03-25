/*
 * File: ASM_preshapeBesselF.h
 *
 * Code generated for Simulink model 'ASM_preshapeBesselF'.
 *
 * Model version                  : 5.39
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed Feb 22 12:27:12 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ASM_preshapeBesselF_h_
#define RTW_HEADER_ASM_preshapeBesselF_h_
#include <string.h>
#ifndef ASM_preshapeBesselF_COMMON_INCLUDES_
#define ASM_preshapeBesselF_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                /* ASM_preshapeBesselF_COMMON_INCLUDES_ */

#include "ASM_preshapeBesselF_types.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T SSflag_d_DSTATE[4];           /* '<S1>/SS flag_d' */
} DW_ASM_preshapeBesselF_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T AO_cmd;                       /* '<Root>/AO_cmd' */
} ExtU_ASM_preshapeBesselF_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T cmd_f_ddot;                   /* '<Root>/cmd_f_ddot' */
  real_T cmd_f_dot;                    /* '<Root>/cmd_f_dot' */
  real_T cmd_f;                        /* '<Root>/cmd_f' */
} ExtY_ASM_preshapeBesselF_T;

/* Parameters (default storage) */
struct P_ASM_preshapeBesselF_T_ {
  real_T SSflag_d_A[16];               /* Computed Parameter: SSflag_d_A
                                        * Referenced by: '<S1>/SS flag_d'
                                        */
  real_T SSflag_d_B[4];                /* Computed Parameter: SSflag_d_B
                                        * Referenced by: '<S1>/SS flag_d'
                                        */
  real_T SSflag_d_C[3];                /* Computed Parameter: SSflag_d_C
                                        * Referenced by: '<S1>/SS flag_d'
                                        */
  real_T SSflag_d_D[3];                /* Computed Parameter: SSflag_d_D
                                        * Referenced by: '<S1>/SS flag_d'
                                        */
  real_T SSflag_d_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S1>/SS flag_d'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ASM_preshapeBesselF_T {
  DW_ASM_preshapeBesselF_T *dwork;
};

/* Block parameters (default storage) */
extern P_ASM_preshapeBesselF_T ASM_preshapeBesselF_P;

/* Model entry point functions */
extern void ASM_preshapeBesselF_initialize(RT_MODEL_ASM_preshapeBesselF_T *const
  ASM_preshapeBesselF_M, ExtU_ASM_preshapeBesselF_T *ASM_preshapeBesselF_U,
  ExtY_ASM_preshapeBesselF_T *ASM_preshapeBesselF_Y);
extern void ASM_preshapeBesselF_step(RT_MODEL_ASM_preshapeBesselF_T *const
  ASM_preshapeBesselF_M, ExtU_ASM_preshapeBesselF_T *ASM_preshapeBesselF_U,
  ExtY_ASM_preshapeBesselF_T *ASM_preshapeBesselF_Y);
extern void ASM_preshapeBesselF_terminate(RT_MODEL_ASM_preshapeBesselF_T *const
  ASM_preshapeBesselF_M);

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
 * hilite_system('m2asm_2_rust/ASM_preshapeBesselF')    - opens subsystem m2asm_2_rust/ASM_preshapeBesselF
 * hilite_system('m2asm_2_rust/ASM_preshapeBesselF/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'm2asm_2_rust'
 * '<S1>'   : 'm2asm_2_rust/ASM_preshapeBesselF'
 */
#endif                                 /* RTW_HEADER_ASM_preshapeBesselF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
