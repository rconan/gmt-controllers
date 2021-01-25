#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
/*
 * File: MountDrives.h
 *
 * Code generated for Simulink model 'MountDrives'.
 *
 * Model version                  : 1.596
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Thu Apr 23 20:42:43 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MountDrives_h_
#define RTW_HEADER_MountDrives_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef MountDrives_COMMON_INCLUDES_
# define MountDrives_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* MountDrives_COMMON_INCLUDES_ */

#include "MountDrives_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S1>/AZ DT Lugre Fr model' */
typedef struct {
  real_T Divide;                       /* '<S11>/Divide' */
} B_AZDTLugreFrmodel_MountDrives_T;

/* Block states (default storage) for system '<S1>/AZ DT Lugre Fr model' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S2>/Discrete-Time Integrator' */
} DW_AZDTLugreFrmodel_MountDrives_T;

/* Block signals (default storage) */
typedef struct {
  real_T Sum;                          /* '<S5>/Sum' */
  real_T Sum_g;                        /* '<S2>/Sum' */
  B_AZDTLugreFrmodel_MountDrives_T ELDTLugreFrmodel;/* '<S1>/EL DT Lugre Fr model' */
  B_AZDTLugreFrmodel_MountDrives_T AZDTLugreFrmodel;/* '<S1>/AZ DT Lugre Fr model' */
} B_MountDrives_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE[20];                /* '<S4>/UD' */
  real_T AZ_delay_DSTATE[14];          /* '<S1>/AZ_delay' */
  real_T AZ_TFd_states;                /* '<S1>/AZ_TFd' */
  real_T EL_delay_DSTATE[14];          /* '<S1>/EL_delay' */
  real_T EL_TFd_states;                /* '<S1>/EL_TFd' */
  uint32_T CircBufIdx;                 /* '<S1>/AZ_delay' */
  uint32_T CircBufIdx_i;               /* '<S1>/EL_delay' */
  DW_AZDTLugreFrmodel_MountDrives_T ELDTLugreFrmodel;/* '<S1>/EL DT Lugre Fr model' */
  DW_AZDTLugreFrmodel_MountDrives_T AZDTLugreFrmodel;/* '<S1>/AZ DT Lugre Fr model' */
} DW_MountDrives_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Mask Parameter: AZDTLugreFrmodel_rtw_collapsed_sub_expr_0
   * Referenced by: '<S1>/AZ DT Lugre Fr model'
   */
  struct_kxIwWES1orY88dAgmfLm1E AZDTLugreFrmodel_rtw_collapsed_sub_expr_0;

  /* Mask Parameter: ELDTLugreFrmodel_rtw_collapsed_sub_expr_6
   * Referenced by: '<S1>/EL DT Lugre Fr model'
   */
  struct_kxIwWES1orY88dAgmfLm1E ELDTLugreFrmodel_rtw_collapsed_sub_expr_6;

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S1>/AZ enc avg + m2rad'
   *   '<S1>/AZ vel avg and m//s=>rad//s'
   *   '<S1>/convert to Az drive forces'
   */
  real_T pooled6[8];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S1>/EL enc avg + m2rad'
   *   '<S1>/EL vel avg and m//s=>rad//s'
   *   '<S1>/convert to El drive forces'
   */
  real_T pooled9[8];
} ConstP_MountDrives_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Mount_cmd[3];                 /* '<Root>/Mount_cmd' */
  real_T Mount_pos[20];                /* '<Root>/Mount_pos' */
} ExtU_MountDrives_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Mount_F[20];                  /* '<Root>/Mount_F' */
} ExtY_MountDrives_T;

/* Real-time Model Data Structure */
struct tag_RTM_MountDrives_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_MountDrives_T MountDrives_B;

/* Block states (default storage) */
extern DW_MountDrives_T MountDrives_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_MountDrives_T MountDrives_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_MountDrives_T MountDrives_Y;

/* Constant parameters (default storage) */
extern const ConstP_MountDrives_T MountDrives_ConstP;

/* Model entry point functions */
extern void MountDrives_initialize(void);
extern void MountDrives_step(void);
extern void MountDrives_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MountDrives_T *const MountDrives_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
 * Block '<S1>/GIR vel avg and m//s=>rad//s' : Unused code path elimination
 */

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
 * hilite_system('ims_Build5pt0a_woM1surf_2018a/MountDrives')    - opens subsystem ims_Build5pt0a_woM1surf_2018a/MountDrives
 * hilite_system('ims_Build5pt0a_woM1surf_2018a/MountDrives/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ims_Build5pt0a_woM1surf_2018a'
 * '<S1>'   : 'ims_Build5pt0a_woM1surf_2018a/MountDrives'
 * '<S2>'   : 'ims_Build5pt0a_woM1surf_2018a/MountDrives/AZ DT Lugre Fr model'
 * '<S3>'   : 'ims_Build5pt0a_woM1surf_2018a/MountDrives/AZ_Parasitic_Torque'
 * '<S4>'   : 'ims_Build5pt0a_woM1surf_2018a/MountDrives/Discrete Derivative'
 * '<S5>'   : 'ims_Build5pt0a_woM1surf_2018a/MountDrives/EL DT Lugre Fr model'
 * '<S6>'   : 'ims_Build5pt0a_woM1surf_2018a/MountDrives/EL_Parasitic_Torque'
 * '<S7>'   : 'ims_Build5pt0a_woM1surf_2018a/MountDrives/MTM Fr Az'
 * '<S8>'   : 'ims_Build5pt0a_woM1surf_2018a/MountDrives/MTM Fr El'
 * '<S9>'   : 'ims_Build5pt0a_woM1surf_2018a/MountDrives/AZ DT Lugre Fr model/g(v)'
 * '<S10>'  : 'ims_Build5pt0a_woM1surf_2018a/MountDrives/AZ DT Lugre Fr model/v2z'
 * '<S11>'  : 'ims_Build5pt0a_woM1surf_2018a/MountDrives/AZ DT Lugre Fr model/g(v)/gs'
 * '<S12>'  : 'ims_Build5pt0a_woM1surf_2018a/MountDrives/EL DT Lugre Fr model/g(v)'
 * '<S13>'  : 'ims_Build5pt0a_woM1surf_2018a/MountDrives/EL DT Lugre Fr model/v2z'
 * '<S14>'  : 'ims_Build5pt0a_woM1surf_2018a/MountDrives/EL DT Lugre Fr model/g(v)/gs'
 * '<S15>'  : 'ims_Build5pt0a_woM1surf_2018a/MountDrives/MTM Fr Az/g(v)'
 * '<S16>'  : 'ims_Build5pt0a_woM1surf_2018a/MountDrives/MTM Fr Az/v2z'
 * '<S17>'  : 'ims_Build5pt0a_woM1surf_2018a/MountDrives/MTM Fr Az/g(v)/gs'
 * '<S18>'  : 'ims_Build5pt0a_woM1surf_2018a/MountDrives/MTM Fr El/g(v)'
 * '<S19>'  : 'ims_Build5pt0a_woM1surf_2018a/MountDrives/MTM Fr El/v2z'
 * '<S20>'  : 'ims_Build5pt0a_woM1surf_2018a/MountDrives/MTM Fr El/g(v)/gs'
 */
#endif                                 /* RTW_HEADER_MountDrives_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
