/*
 * File: m1hp_cpp_data.c
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

#include "m1hp_cpp.h"

/* Invariant block signals (default storage) */
const ConstB_m1hp_cpp_T m1hp_cpp_ConstB = {
  6                                    /* '<S25>/Width1' */
};

/* Block parameters (default storage) */
P_m1hp_cpp_T m1hp_cpp_P = {
  /* Variable: a_max
   * Referenced by: '<S26>/Constant'
   */
  0.00025,

  /* Variable: v0
   * Referenced by: '<S5>/Constant'
   */
  0.0,

  /* Variable: v_max
   * Referenced by: '<S26>/Constant1'
   */
  5.0E-5,

  /* Variable: k_cmd
   * Referenced by: '<S24>/Constant'
   */
  10U,

  /* Computed Parameter: a_l_Y0
   * Referenced by: '<S7>/a_l'
   */
  0.0,

  /* Computed Parameter: Dx_Y0
   * Referenced by: '<S7>/Dx'
   */
  0.0,

  /* Computed Parameter: Dv_Y0
   * Referenced by: '<S7>/Dv'
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S27>/Constant'
   */
  0,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S17>/Constant1'
   */
  0U,

  /* Computed Parameter: Dk_merge_InitialOutput
   * Referenced by: '<S3>/Dk_merge'
   */
  0U,

  /* Computed Parameter: k_a_ac_acd_Y0
   * Referenced by: '<S7>/k_a_ac_acd'
   */
  0U,

  /* Computed Parameter: Constant_Value_g
   * Referenced by: '<S4>/Constant'
   */
  0U,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S6>/Unit Delay'
   */
  0U,

  /* Computed Parameter: ResettableDelay_InitialConditio
   * Referenced by: '<S6>/Resettable Delay'
   */
  0U,

  /* Computed Parameter: Constant_Value_m
   * Referenced by: '<S6>/Constant'
   */
  1U,

  /* Computed Parameter: max_idx_Y0
   * Referenced by: '<S25>/max_idx'
   */
  0,

  /* Expression: int16(1)
   * Referenced by: '<S25>/Memory1'
   */
  1,

  /* Computed Parameter: max_bool_Y0
   * Referenced by: '<S25>/max_bool'
   */
  false,

  /* Start of '<S26>/CoreSubsys' */
  {
    /* Expression: 1/delta_sim
     * Referenced by: '<S26>/Gain1'
     */
    1000.0,

    /* Expression: 1/delta_sim
     * Referenced by: '<S26>/Gain2'
     */
    1000.0,

    /* Expression: 1/delta_sim
     * Referenced by: '<S26>/Gain3'
     */
    1000.0
  }
  ,

  /* End of '<S26>/CoreSubsys' */

  /* Start of '<S5>/CoreSubsys' */
  {
    /* Mask Parameter: DetectChange_vinit
     * Referenced by: '<S22>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S21>/Constant'
     */
    0U,

    /* Computed Parameter: x0_Y0
     * Referenced by: '<S23>/x0'
     */
    0.0,

    /* Expression: [v0]
     * Referenced by: '<S23>/v0'
     */
    0.0,

    /* Computed Parameter: DiscreteTimeIntegrator_gainval
     * Referenced by: '<S5>/Discrete-Time Integrator'
     */
    0.001,

    /* Expression: 0.5
     * Referenced by: '<S5>/Gain'
     */
    0.5,

    /* Expression: 0
     * Referenced by:
     */
    0.0,

    /* Expression: 0
     * Referenced by:
     */
    0.0,

    /* Expression: delta_sim
     * Referenced by: '<S5>/Gain1'
     */
    2199023256U
  }
  ,

  /* End of '<S5>/CoreSubsys' */

  /* Start of '<S2>/CoreSubsys' */
  {
    /* Expression: delta_sim
     * Referenced by: '<S9>/Gain2'
     */
    0.001,

    /* Expression: 0.5
     * Referenced by: '<S9>/Gain'
     */
    0.5,

    /* Expression: 0.5
     * Referenced by: '<S9>/Gain1'
     */
    0.5,

    /* Expression: 2
     * Referenced by: '<S9>/Gain3'
     */
    2.0,

    /* Expression: 0
     * Referenced by: '<S11>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S2>/acc_merge'
     */
    0.0,

    /* Computed Parameter: Constant_Value_l
     * Referenced by: '<S8>/Constant'
     */
    0U,

    /* Start of '<S2>/If Action Subsystem6' */
    {
      /* Expression: 0
       * Referenced by: '<S14>/Constant'
       */
      0.0
    }
    ,

    /* End of '<S2>/If Action Subsystem6' */

    /* Start of '<S2>/If Action Subsystem5' */
    {
      /* Expression: 0
       * Referenced by: '<S13>/Constant'
       */
      0.0
    }
    ,

    /* End of '<S2>/If Action Subsystem5' */

    /* Start of '<S2>/If Action Subsystem4' */
    {
      /* Expression: 0
       * Referenced by: '<S12>/Constant'
       */
      0.0
    }
    /* End of '<S2>/If Action Subsystem4' */
  }
  /* End of '<S2>/CoreSubsys' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
