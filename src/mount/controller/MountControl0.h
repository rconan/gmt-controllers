#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
/*
 * File: MountControl0.h
 *
 * Code generated for Simulink model 'MountControl0'.
 *
 * Model version                  : 1.596
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Thu Apr 23 20:42:27 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MountControl0_h_
#define RTW_HEADER_MountControl0_h_
#include <string.h>
#ifndef MountControl0_COMMON_INCLUDES_
# define MountControl0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* MountControl0_COMMON_INCLUDES_ */

#include "MountControl0_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T RTout;                        /* '<S3>/RTout' */
  real_T RTout_g;                      /* '<S2>/RTout' */
  real_T RTout_j;                      /* '<S5>/RTout' */
  real_T RTout_k;                      /* '<S4>/RTout' */
  real_T RTout_m;                      /* '<S6>/RTout' */
  real_T RTin;                         /* '<S2>/RTin' */
  real_T RTin_k;                       /* '<S3>/RTin' */
  real_T RTin_g;                       /* '<S4>/RTin' */
  real_T RTin_o;                       /* '<S5>/RTin' */
  real_T RTin_b;                       /* '<S6>/RTin' */
} B_MountControl0_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteSS_DSTATE[7];         /* '<S2>/Discrete SS' */
  real_T DiscreteSS_DSTATE_i[7];       /* '<S3>/Discrete SS' */
  real_T DiscreteSS_DSTATE_l[11];      /* '<S4>/Discrete SS' */
  real_T DiscreteSS_DSTATE_b[11];      /* '<S5>/Discrete SS' */
  real_T DiscreteSS_DSTATE_m[6];       /* '<S6>/Discrete SS' */
  real_T RTout_Buffer0;                /* '<S3>/RTout' */
  real_T RTout_Buffer0_b;              /* '<S2>/RTout' */
  real_T RTout_Buffer0_k;              /* '<S5>/RTout' */
  real_T RTout_Buffer0_m;              /* '<S4>/RTout' */
  real_T RTout_Buffer0_bt;             /* '<S6>/RTout' */
} DW_MountControl0_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [-ones(1,4) ones(1,4)]/4/mount.az.driveRadius
   * Referenced by: '<S1>/AZ average and  m2rad conv+'
   */
  real_T AZaverageandm2radconv_Gain[8];

  /* Computed Parameter: DiscreteSS_A
   * Referenced by: '<S2>/Discrete SS'
   */
  real_T DiscreteSS_A[37];

  /* Computed Parameter: DiscreteSS_C
   * Referenced by: '<S2>/Discrete SS'
   */
  real_T DiscreteSS_C[7];

  /* Computed Parameter: DiscreteSS_A_l
   * Referenced by: '<S3>/Discrete SS'
   */
  real_T DiscreteSS_A_l[49];

  /* Computed Parameter: DiscreteSS_C_a
   * Referenced by: '<S3>/Discrete SS'
   */
  real_T DiscreteSS_C_a[7];

  /* Expression: [-ones(1,4) ones(1,4)]/4/mount.el.driveRadius
   * Referenced by: '<S1>/EL average and  m2rad conv+'
   */
  real_T ELaverageandm2radconv_Gain[8];

  /* Computed Parameter: DiscreteSS_A_k
   * Referenced by: '<S4>/Discrete SS'
   */
  real_T DiscreteSS_A_k[101];

  /* Computed Parameter: DiscreteSS_C_o
   * Referenced by: '<S4>/Discrete SS'
   */
  real_T DiscreteSS_C_o[11];

  /* Computed Parameter: DiscreteSS_A_o
   * Referenced by: '<S5>/Discrete SS'
   */
  real_T DiscreteSS_A_o[121];

  /* Computed Parameter: DiscreteSS_C_at
   * Referenced by: '<S5>/Discrete SS'
   */
  real_T DiscreteSS_C_at[11];

  /* Computed Parameter: DiscreteSS_A_e
   * Referenced by: '<S6>/Discrete SS'
   */
  real_T DiscreteSS_A_e[26];

  /* Computed Parameter: DiscreteSS_C_or
   * Referenced by: '<S6>/Discrete SS'
   */
  real_T DiscreteSS_C_or[6];
} ConstP_MountControl0_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Mount_SP[3];                  /* '<Root>/Mount_SP' */
  real_T Mount_FB[20];                 /* '<Root>/Mount_FB' */
} ExtU_MountControl0_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Mount_cmd[3];                 /* '<Root>/Mount_cmd' */
} ExtY_MountControl0_T;

/* Real-time Model Data Structure */
struct tag_RTM_MountControl0_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_MountControl0_T MountControl0_B;

/* Block states (default storage) */
extern DW_MountControl0_T MountControl0_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_MountControl0_T MountControl0_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_MountControl0_T MountControl0_Y;

/* Constant parameters (default storage) */
extern const ConstP_MountControl0_T MountControl0_ConstP;

/* Model entry point functions */
extern void MountControl0_initialize(void);
extern void MountControl0_step(void);
extern void MountControl0_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MountControl0_T *const MountControl0_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/az_ff_en' : Eliminated nontunable gain of 1
 * Block '<S1>/el_ff_en' : Eliminated nontunable gain of 1
 * Block '<S1>/mount_en' : Eliminated nontunable gain of 1
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
 * hilite_system('ims_Build5pt0a_woM1surf_2018a/MountControl')    - opens subsystem ims_Build5pt0a_woM1surf_2018a/MountControl
 * hilite_system('ims_Build5pt0a_woM1surf_2018a/MountControl/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ims_Build5pt0a_woM1surf_2018a'
 * '<S1>'   : 'ims_Build5pt0a_woM1surf_2018a/MountControl'
 * '<S2>'   : 'ims_Build5pt0a_woM1surf_2018a/MountControl/AZ FB controller'
 * '<S3>'   : 'ims_Build5pt0a_woM1surf_2018a/MountControl/AZ FF controller'
 * '<S4>'   : 'ims_Build5pt0a_woM1surf_2018a/MountControl/EL FB controller'
 * '<S5>'   : 'ims_Build5pt0a_woM1surf_2018a/MountControl/EL FF controller'
 * '<S6>'   : 'ims_Build5pt0a_woM1surf_2018a/MountControl/GIR FB controller'
 */
#endif                                 /* RTW_HEADER_MountControl0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
