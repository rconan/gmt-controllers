/*
 * File: Mount_Drv_FDR2023.h
 *
 * Code generated for Simulink model 'Mount_Drv_FDR2023'.
 *
 * Model version                  : 9.56
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Jun  2 18:11:08 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#ifndef RTW_HEADER_Mount_Drv_FDR2023_h_
#define RTW_HEADER_Mount_Drv_FDR2023_h_
#ifndef Mount_Drv_FDR2023_COMMON_INCLUDES_
#define Mount_Drv_FDR2023_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Mount_Drv_FDR2023_COMMON_INCLUDES_ */

#include "Mount_Drv_FDR2023_types.h"
#include "rt_defines.h"

/* Block signals and states (default storage) for system '<S2>/AZ DT Lugre Fr mode' */
typedef struct {
  real_T Sum;                          /* '<S10>/Sum' */
  real_T Sum_i;                        /* '<S9>/Sum' */
  real_T Divide;                       /* '<S11>/Divide' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S6>/Discrete-Time Integrator' */
} DW_AZDTLugreFrmode_Mount_Drv__T;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_AZDTLugreFrmode_Mount_Drv__T ELDTLugreFrmodel;/* '<S2>/EL DT Lugre Fr model' */
  DW_AZDTLugreFrmode_Mount_Drv__T AZDTLugreFrmode;/* '<S2>/AZ DT Lugre Fr mode' */
  real_T UD_DSTATE[3];                 /* '<S3>/UD' */
  real_T DRVdelay_DSTATE[12];          /* '<S1>/DRV delay' */
  real_T DRV_dyn_states[3];            /* '<S1>/DRV_dyn' */
  real_T Sum2;                         /* '<S20>/Sum2' */
  real_T Sum2_m;                       /* '<S19>/Sum2' */
  real_T Sum2_i;                       /* '<S18>/Sum2' */
  real_T Sum;                          /* '<S8>/Sum' */
  real_T Divide;                       /* '<S17>/Divide' */
  real_T Sum_i;                        /* '<S7>/Sum' */
  real_T Sum_d;                        /* '<S6>/Sum' */
  real_T UnitDelay2_DSTATE;            /* '<S20>/Unit Delay2' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S8>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_states;   /* '<S8>/Discrete Transfer Fcn' */
  uint32_T CircBufIdx;                 /* '<S1>/DRV delay' */
} DW_Mount_Drv_FDR2023_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: oParasitic.oEmf.SpAmp_NPerA)
   * Referenced by:
   *   '<S22>/EMF  Spatial Pattern (N//A)'
   *   '<S24>/EMF  Spatial Pattern (N//A)'
   */
  real_T pooled5[6];

  /* Pooled Parameter (Expression: oParasitic.oEmf.SpFreq_mmInv*2*pi)
   * Referenced by:
   *   '<S22>/EMF  Spatial Pattern (N//A)'
   *   '<S24>/EMF  Spatial Pattern (N//A)'
   */
  real_T pooled6[6];

  /* Pooled Parameter (Expression: oParasitic.oEmf.SpPhase_rad)
   * Referenced by:
   *   '<S22>/EMF  Spatial Pattern (N//A)'
   *   '<S24>/EMF  Spatial Pattern (N//A)'
   */
  real_T pooled7[6];

  /* Expression: oParasitic.PhaseShifts_mm'
   * Referenced by: '<S18>/Bias'
   */
  real_T Bias_Bias[8];

  /* Expression: blkdiag(1/4*ones(1,4),1/6*ones(1,6),1/4*ones(1,4))
   * Referenced by: '<S1>/Drv_Pos_avg'
   */
  real_T Drv_Pos_avg_Gain[42];

  /* Expression: oToothContact.oInterp.TorqueRate
   * Referenced by: '<S30>/1-D Lookup Table'
   */
  real_T uDLookupTable_tableData[521];

  /* Expression: oToothContact.oInterp.Pos
   * Referenced by: '<S30>/1-D Lookup Table'
   */
  real_T uDLookupTable_bp01Data[521];

  /* Expression: oToothContact.oInterp.TorqueRate
   * Referenced by: '<S29>/1-D Lookup Table'
   */
  real_T uDLookupTable_tableData_c[261];

  /* Expression: oToothContact.oInterp.Pos
   * Referenced by: '<S29>/1-D Lookup Table'
   */
  real_T uDLookupTable_bp01Data_p[261];

  /* Expression: blkdiag(1/8*ones(8,1),1/4*ones(4,1),1/4*ones(4,1))
   * Referenced by: '<S1>/Split_Drv_To'
   */
  real_T Split_Drv_To_Gain[48];
} ConstP_Mount_Drv_FDR2023_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Mount_cmd[3];                 /* '<Root>/Mount_cmd' */
  real_T Mount_drv_Po[14];             /* '<Root>/Mount_drv_Po' */
} ExtU_Mount_Drv_FDR2023_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Mount_T[16];                  /* '<Root>/Mount_T' */
  real_T ToothCAxialFo;                /* '<Root>/ToothCAxialFo' */
} ExtY_Mount_Drv_FDR2023_T;

/* Real-time Model Data Structure */
struct tag_RTM_Mount_Drv_FDR2023_T {
  DW_Mount_Drv_FDR2023_T *dwork;
};

/* Constant parameters (default storage) */
extern const ConstP_Mount_Drv_FDR2023_T Mount_Drv_FDR2023_ConstP;

/* Model entry point functions */
extern void Mount_Drv_FDR2023_initialize(RT_MODEL_Mount_Drv_FDR2023_T *const
  Mount_Drv_FDR2023_M);
extern void Mount_Drv_FDR2023_step(RT_MODEL_Mount_Drv_FDR2023_T *const
  Mount_Drv_FDR2023_M, ExtU_Mount_Drv_FDR2023_T *Mount_Drv_FDR2023_U,
  ExtY_Mount_Drv_FDR2023_T *Mount_Drv_FDR2023_Y);
extern void Mount_Drv_FDR2023_terminate(RT_MODEL_Mount_Drv_FDR2023_T *const
  Mount_Drv_FDR2023_M);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
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
 * hilite_system('mount_2_rust/Mount_Drv_FDR2023')    - opens subsystem mount_2_rust/Mount_Drv_FDR2023
 * hilite_system('mount_2_rust/Mount_Drv_FDR2023/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'mount_2_rust'
 * '<S1>'   : 'mount_2_rust/Mount_Drv_FDR2023'
 * '<S2>'   : 'mount_2_rust/Mount_Drv_FDR2023/DRV Friction'
 * '<S3>'   : 'mount_2_rust/Mount_Drv_FDR2023/Discrete Derivative'
 * '<S4>'   : 'mount_2_rust/Mount_Drv_FDR2023/Parasitic torque model'
 * '<S5>'   : 'mount_2_rust/Mount_Drv_FDR2023/ToothContact Torques'
 * '<S6>'   : 'mount_2_rust/Mount_Drv_FDR2023/DRV Friction/AZ DT Lugre Fr mode'
 * '<S7>'   : 'mount_2_rust/Mount_Drv_FDR2023/DRV Friction/EL DT Lugre Fr model'
 * '<S8>'   : 'mount_2_rust/Mount_Drv_FDR2023/DRV Friction/GIR DT Lugre Fr model'
 * '<S9>'   : 'mount_2_rust/Mount_Drv_FDR2023/DRV Friction/AZ DT Lugre Fr mode/g(v)'
 * '<S10>'  : 'mount_2_rust/Mount_Drv_FDR2023/DRV Friction/AZ DT Lugre Fr mode/v2z'
 * '<S11>'  : 'mount_2_rust/Mount_Drv_FDR2023/DRV Friction/AZ DT Lugre Fr mode/g(v)/gs'
 * '<S12>'  : 'mount_2_rust/Mount_Drv_FDR2023/DRV Friction/EL DT Lugre Fr model/g(v)'
 * '<S13>'  : 'mount_2_rust/Mount_Drv_FDR2023/DRV Friction/EL DT Lugre Fr model/v2z'
 * '<S14>'  : 'mount_2_rust/Mount_Drv_FDR2023/DRV Friction/EL DT Lugre Fr model/g(v)/gs'
 * '<S15>'  : 'mount_2_rust/Mount_Drv_FDR2023/DRV Friction/GIR DT Lugre Fr model/g(v)'
 * '<S16>'  : 'mount_2_rust/Mount_Drv_FDR2023/DRV Friction/GIR DT Lugre Fr model/v2z'
 * '<S17>'  : 'mount_2_rust/Mount_Drv_FDR2023/DRV Friction/GIR DT Lugre Fr model/g(v)/gs'
 * '<S18>'  : 'mount_2_rust/Mount_Drv_FDR2023/Parasitic torque model/Parasitic AZ'
 * '<S19>'  : 'mount_2_rust/Mount_Drv_FDR2023/Parasitic torque model/Parasitic EL'
 * '<S20>'  : 'mount_2_rust/Mount_Drv_FDR2023/Parasitic torque model/Parasitic GIR'
 * '<S21>'  : 'mount_2_rust/Mount_Drv_FDR2023/Parasitic torque model/Radians to Degrees'
 * '<S22>'  : 'mount_2_rust/Mount_Drv_FDR2023/Parasitic torque model/Parasitic AZ/For Each Subsystem'
 * '<S23>'  : 'mount_2_rust/Mount_Drv_FDR2023/Parasitic torque model/Parasitic AZ/For Each Subsystem1'
 * '<S24>'  : 'mount_2_rust/Mount_Drv_FDR2023/Parasitic torque model/Parasitic EL/For Each Subsystem'
 * '<S25>'  : 'mount_2_rust/Mount_Drv_FDR2023/Parasitic torque model/Parasitic EL/For Each Subsystem1'
 * '<S26>'  : 'mount_2_rust/Mount_Drv_FDR2023/Parasitic torque model/Parasitic GIR/For Each Subsystem'
 * '<S27>'  : 'mount_2_rust/Mount_Drv_FDR2023/Parasitic torque model/Parasitic GIR/For Each Subsystem1'
 * '<S28>'  : 'mount_2_rust/Mount_Drv_FDR2023/ToothContact Torques/Radians to Degrees'
 * '<S29>'  : 'mount_2_rust/Mount_Drv_FDR2023/ToothContact Torques/ToothContact GIR (Norm)'
 * '<S30>'  : 'mount_2_rust/Mount_Drv_FDR2023/ToothContact Torques/ToothContact GIR (Peak)'
 */
#endif                                 /* RTW_HEADER_Mount_Drv_FDR2023_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
