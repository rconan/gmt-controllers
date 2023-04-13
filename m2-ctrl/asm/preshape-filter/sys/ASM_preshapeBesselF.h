/*
 * File: ASM_preshapeBesselF.h
 *
 * Code generated for Simulink model 'ASM_preshapeBesselF'.
 *
 * Model version                  : 9.4
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Apr 13 10:34:30 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#ifndef RTW_HEADER_ASM_preshapeBesselF_h_
#define RTW_HEADER_ASM_preshapeBesselF_h_
#ifndef ASM_preshapeBesselF_COMMON_INCLUDES_
#define ASM_preshapeBesselF_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                /* ASM_preshapeBesselF_COMMON_INCLUDES_ */

#include "ASM_preshapeBesselF_types.h"
#include <string.h>
#include "rt_defines.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T SSflag_d_DSTATE[4];           /* '<S1>/SS flag_d' */
} DW_ASM_preshapeBesselF_T;

/* Real-time Model Data Structure */
struct tag_RTM_ASM_preshapeBesselF_T {
  DW_ASM_preshapeBesselF_T *dwork;
};

/* Model entry point functions */
extern void ASM_preshapeBesselF_initialize(RT_MODEL_ASM_preshapeBesselF_T *const
  ASM_preshapeBesselF_M);
extern void ASM_preshapeBesselF_step(RT_MODEL_ASM_preshapeBesselF_T *const
  ASM_preshapeBesselF_M, real_T ASM_preshapeBesselF_U_AO_cmd, real_T
  *ASM_preshapeBesselF_Y_cmd_f_ddot, real_T *ASM_preshapeBesselF_Y_cmd_f_dot,
  real_T *ASM_preshapeBesselF_Y_cmd_f);
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
