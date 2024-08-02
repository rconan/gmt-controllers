/*
 * File: m1hp_cpp.c
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

#include "m1hp_cpp.h"
#include "rtwtypes.h"
#include "m1hp_cpp_private.h"
#include <math.h>
#include "zero_crossing_types.h"

/*
 * System initialize for action system:
 *    '<S3>/If Action Subsystem4'
 *    '<S3>/If Action Subsystem5'
 *    '<S3>/If Action Subsystem6'
 */
void m1hp_cp_IfActionSubsystem4_Init(real_T *rty_ac0)
{
  *rty_ac0 = 0.0;
}

/*
 * Output and update for action system:
 *    '<S3>/If Action Subsystem4'
 *    '<S3>/If Action Subsystem5'
 *    '<S3>/If Action Subsystem6'
 */
void m1hp_cpp_IfActionSubsystem4(real_T *rty_ac0)
{
  /* SignalConversion generated from: '<S14>/ac0' incorporates:
   *  Constant: '<S14>/Constant'
   */
  *rty_ac0 = 0.0;
}

/* Model step function */
void m1hp_cpp_step(RT_MODEL_m1hp_cpp_T *const m1hp_cpp_M, ExtU_m1hp_cpp_T
                   *m1hp_cpp_U, ExtY_m1hp_cpp_T *m1hp_cpp_Y)
{
  DW_m1hp_cpp_T *m1hp_cpp_DW = m1hp_cpp_M->dwork;
  PrevZCX_m1hp_cpp_T *m1hp_cpp_PrevZCX = m1hp_cpp_M->prevZCSigState;

  /* local block i/o variables */
  real_T rtb_ImpSel_InsertedFor_acc_vec_;
  real_T rtb_vel_f_vec_CoreSubsysCanOut;
  real_T rtb_pos_f_vec_CoreSubsysCanOut;
  real_T rtb_acc_f_vec_CoreSubsysCanOut;
  real_T rtb_Add1_i;
  real_T rtb_Add2;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_n;
  int32_T ForEach_itr_p;
  int32_T ForEach_itr_o;
  real_T rtb_ImpAsg_InsertedFor_acc_f_ve[6];
  real_T rtb_ImpAsg_InsertedFor_pos_d_ve[6];
  real_T rtb_ImpAsg_InsertedFor_pos_f_ve[6];
  real_T rtb_ImpAsg_InsertedFor_vel_d_ve[6];
  real_T rtb_ImpAsg_InsertedFor_vel_f_ve[6];
  real_T rtb_Gain1_m;
  real_T rtb_Gain2_o_idx_0;
  real_T rtb_Gain2_o_idx_2;
  real_T rtb_Merge_idx_0;
  int32_T i;
  int32_T i_0;
  uint32_T rtb_ImpAsg_InsertedFor_t_a_at_i[6];
  uint32_T rtb_ImpAsg_InsertedFor_t_a_c_at[6];
  uint32_T rtb_ImpAsg_InsertedFor_t_a_d_at[6];
  int16_T rtb_Switch1;
  boolean_T rtb_Compare;

  /* RelationalOperator: '<S26>/Compare' incorporates:
   *  Constant: '<S26>/Constant'
   *  UnitDelay: '<S7>/Unit Delay'
   */
  rtb_Compare = (m1hp_cpp_DW->UnitDelay_DSTATE == k_cmd);

  /* Delay: '<S7>/Resettable Delay' */
  if (rtb_Compare && (m1hp_cpp_PrevZCX->ResettableDelay_Reset_ZCE != POS_ZCSIG))
  {
    m1hp_cpp_DW->ResettableDelay_DSTATE = 0U;
  }

  m1hp_cpp_PrevZCX->ResettableDelay_Reset_ZCE = rtb_Compare;

  /* RelationalOperator: '<S5>/Compare' incorporates:
   *  Constant: '<S5>/Constant'
   *  Delay: '<S7>/Resettable Delay'
   */
  rtb_Compare = (m1hp_cpp_DW->ResettableDelay_DSTATE == 0U);

  /* Outputs for Triggered SubSystem: '<S1>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S8>/Trigger'
   */
  if (rtb_Compare && (m1hp_cpp_PrevZCX->TriggeredSubsystem_Trig_ZCE != POS_ZCSIG))
  {
    uint32_T rtb_Add_p;
    int16_T Memory1_PreviousInput;
    for (i = 0; i < 6; i++) {
      /* Sum: '<S8>/Add' incorporates:
       *  Memory generated from: '<S1>/Triggered Subsystem'
       */
      m1hp_cpp_DW->Add[i] = m1hp_cpp_U->x_target[i] -
        m1hp_cpp_DW->TmpLatchAtTriggeredSubsystemInp[i];
    }

    /* Outputs for Iterator SubSystem: '<S8>/Multi-axis demand' incorporates:
     *  ForEach: '<S28>/For Each'
     */
    for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
      real_T t_a;
      real_T v_l;

      /* MATLAB Function: '<S28>/MATLAB Function' incorporates:
       *  Constant: '<S28>/Const_a_max'
       *  Constant: '<S28>/Const_v_max'
       *  ForEachSliceSelector generated from: '<S28>/v0'
       *  ForEachSliceSelector generated from: '<S28>/v1'
       *  ForEachSliceSelector generated from: '<S28>/x0'
       *  ForEachSliceSelector generated from: '<S28>/x1'
       *  Memory generated from: '<S1>/Triggered Subsystem'
       * */
      rtb_Gain2_o_idx_0 = m1hp_cpp_U->v_target[ForEach_itr] -
        m1hp_cpp_DW->TmpLatchAtTriggeredSubsystemI_e[ForEach_itr];
      rtb_Merge_idx_0 = m1hp_cpp_U->x_target[ForEach_itr] -
        m1hp_cpp_DW->TmpLatchAtTriggeredSubsystemInp[ForEach_itr];
      rtb_Gain1_m = 0.00025;
      v_l = 5.0E-5;
      if (rtb_Merge_idx_0 < 0.0) {
        rtb_Gain1_m = -0.00025;
        v_l = -5.0E-5;
      }

      rtb_Gain2_o_idx_2 = sqrt(rtb_Gain2_o_idx_0 * rtb_Gain2_o_idx_0 * 0.5 +
        rtb_Merge_idx_0 * rtb_Gain1_m) * fabs(1.0 / rtb_Gain1_m);
      t_a = rtb_Gain2_o_idx_0 / rtb_Gain1_m + rtb_Gain2_o_idx_2;
      if (t_a < 0.0) {
        t_a = 0.0;
        printf("=> t_a=%g, t_d=%g, a_l=%g, D_v=%g\n", 0.0, rtb_Gain2_o_idx_2,
               rtb_Gain1_m, rtb_Gain2_o_idx_0);
        fflush(stdout);
      }

      if (fabs(rtb_Gain1_m * t_a + m1hp_cpp_DW->
               TmpLatchAtTriggeredSubsystemI_e[ForEach_itr]) > fabs(v_l)) {
        t_a = 1.0 / rtb_Gain1_m * (v_l -
          m1hp_cpp_DW->TmpLatchAtTriggeredSubsystemI_e[ForEach_itr]);
        v_l -= m1hp_cpp_U->v_target[ForEach_itr];
        rtb_Gain2_o_idx_2 = 1.0 / rtb_Gain1_m * v_l;
        rtb_Gain2_o_idx_0 = (((rtb_Gain2_o_idx_0 * t_a + rtb_Merge_idx_0) - v_l *
                              rtb_Gain2_o_idx_2) + (rtb_Gain2_o_idx_2 *
          rtb_Gain2_o_idx_2 - t_a * t_a) * (0.5 * rtb_Gain1_m)) / v_l;
      } else {
        rtb_Gain2_o_idx_0 = 0.0;
      }

      /* Gain: '<S28>/Gain1' incorporates:
       *  MATLAB Function: '<S28>/MATLAB Function'
       */
      rtb_Merge_idx_0 = 1000.0 * t_a;
      t_a = fabs(rtb_Merge_idx_0);
      if (t_a < 4.503599627370496E+15) {
        if (t_a >= 0.5) {
          rtb_Merge_idx_0 = floor(rtb_Merge_idx_0 + 0.5);
        } else {
          rtb_Merge_idx_0 = 0.0;
        }
      }

      /* Gain: '<S28>/Gain2' */
      rtb_Gain2_o_idx_0 *= 1000.0;
      t_a = fabs(rtb_Gain2_o_idx_0);
      if (t_a < 4.503599627370496E+15) {
        if (t_a >= 0.5) {
          rtb_Gain2_o_idx_0 = floor(rtb_Gain2_o_idx_0 + 0.5);
        } else {
          rtb_Gain2_o_idx_0 = 0.0;
        }
      }

      /* Sum: '<S28>/Add' incorporates:
       *  Gain: '<S28>/Gain1'
       *  Gain: '<S28>/Gain2'
       */
      rtb_Add_p = (uint32_T)rtb_Merge_idx_0 + (uint32_T)rtb_Gain2_o_idx_0;

      /* Gain: '<S28>/Gain3' incorporates:
       *  MATLAB Function: '<S28>/MATLAB Function'
       */
      rtb_Gain2_o_idx_0 = 1000.0 * rtb_Gain2_o_idx_2;
      t_a = fabs(rtb_Gain2_o_idx_0);
      if (t_a < 4.503599627370496E+15) {
        if (t_a >= 0.5) {
          rtb_Gain2_o_idx_0 = floor(rtb_Gain2_o_idx_0 + 0.5);
        } else {
          rtb_Gain2_o_idx_0 = 0.0;
        }
      }

      /* ForEachSliceAssignment generated from: '<S28>/t_a_d' incorporates:
       *  Gain: '<S28>/Gain3'
       *  Sum: '<S28>/Add_acd'
       */
      rtb_ImpAsg_InsertedFor_t_a_d_at[ForEach_itr] = rtb_Add_p + (uint32_T)
        rtb_Gain2_o_idx_0;

      /* ForEachSliceAssignment generated from: '<S28>/t_a_c' */
      rtb_ImpAsg_InsertedFor_t_a_c_at[ForEach_itr] = rtb_Add_p;

      /* ForEachSliceAssignment generated from: '<S28>/t_a' incorporates:
       *  Gain: '<S28>/Gain1'
       */
      rtb_ImpAsg_InsertedFor_t_a_at_i[ForEach_itr] = (uint32_T)rtb_Merge_idx_0;

      /* ForEachSliceAssignment generated from: '<S28>/a_l' incorporates:
       *  MATLAB Function: '<S28>/MATLAB Function'
       */
      m1hp_cpp_DW->ImpAsg_InsertedFor_a_l_at_inpor[ForEach_itr] = rtb_Gain1_m;
    }

    /* End of Outputs for SubSystem: '<S8>/Multi-axis demand' */

    /* Outputs for Iterator SubSystem: '<S8>/Detect max t_seg' incorporates:
     *  ForIterator: '<S27>/For Iterator'
     */
    /* InitializeConditions for Memory: '<S27>/Memory1' */
    Memory1_PreviousInput = 1;
    for (i = 0; i < 6; i++) {
      /* MinMax: '<S27>/MinMax' */
      rtb_Add_p = rtb_ImpAsg_InsertedFor_t_a_d_at[0];
      for (i_0 = 0; i_0 < 5; i_0++) {
        uint32_T u1;
        u1 = rtb_ImpAsg_InsertedFor_t_a_d_at[i_0 + 1];
        if (rtb_Add_p < u1) {
          rtb_Add_p = u1;
        }
      }

      for (i_0 = 0; i_0 < 6; i_0++) {
        /* RelationalOperator: '<S29>/Compare' incorporates:
         *  Constant: '<S29>/Constant'
         *  MinMax: '<S27>/MinMax'
         *  Sum: '<S27>/Subtract'
         */
        m1hp_cpp_DW->Compare[i_0] = ((int32_T)
          rtb_ImpAsg_InsertedFor_t_a_d_at[i_0] - (int32_T)rtb_Add_p == 0);
      }

      /* Sum: '<S27>/Add' incorporates:
       *  Sum: '<S8>/Sub'
       */
      rtb_Switch1 = (int16_T)(6 - i);

      /* Switch: '<S27>/Switch1' incorporates:
       *  Memory: '<S27>/Memory1'
       *  Selector: '<S27>/Selector1'
       *  Sum: '<S27>/Add'
       *  Sum: '<S8>/Sub'
       */
      if (!m1hp_cpp_DW->Compare[(int16_T)(6 - i) - 1]) {
        rtb_Switch1 = Memory1_PreviousInput;
      }

      /* End of Switch: '<S27>/Switch1' */

      /* Update for Memory: '<S27>/Memory1' */
      Memory1_PreviousInput = rtb_Switch1;

      /* Sum: '<S8>/Sub' incorporates:
       *  Memory generated from: '<S1>/Triggered Subsystem'
       */
      m1hp_cpp_DW->Sub[i] = m1hp_cpp_U->v_target[i] -
        m1hp_cpp_DW->TmpLatchAtTriggeredSubsystemI_e[i];
    }

    /* End of Outputs for SubSystem: '<S8>/Detect max t_seg' */

    /* MultiPortSwitch: '<S8>/Index Vector' */
    m1hp_cpp_DW->IndexVector = rtb_ImpAsg_InsertedFor_t_a_d_at[rtb_Switch1 - 1];

    /* MultiPortSwitch: '<S8>/Index Vector1' incorporates:
     *  MultiPortSwitch: '<S8>/Index Vector'
     */
    m1hp_cpp_DW->IndexVector1 = rtb_ImpAsg_InsertedFor_t_a_c_at[rtb_Switch1 - 1];

    /* MultiPortSwitch: '<S8>/Index Vector2' incorporates:
     *  MultiPortSwitch: '<S8>/Index Vector'
     */
    m1hp_cpp_DW->IndexVector2 = rtb_ImpAsg_InsertedFor_t_a_at_i[rtb_Switch1 - 1];
  }

  m1hp_cpp_PrevZCX->TriggeredSubsystem_Trig_ZCE = rtb_Compare;

  /* End of Outputs for SubSystem: '<S1>/Triggered Subsystem' */

  /* Outputs for Iterator SubSystem: '<S1>/CPP with multi-axis coordination' incorporates:
   *  ForEach: '<S3>/For Each'
   */
  for (ForEach_itr_p = 0; ForEach_itr_p < 6; ForEach_itr_p++) {
    boolean_T tmp;

    /* RelationalOperator: '<S10>/Compare' incorporates:
     *  Constant: '<S10>/Constant'
     */
    rtb_Compare = (m1hp_cpp_DW->IndexVector > 0U);

    /* If: '<S3>/If1' incorporates:
     *  ForEachSliceSelector generated from: '<S3>/max_bool'
     */
    tmp = !m1hp_cpp_DW->Compare[ForEach_itr_p];
    if (tmp && rtb_Compare) {
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      /* Gain: '<S11>/Gain2' incorporates:
       *  SignalConversion generated from: '<S11>/Gain2'
       */
      rtb_Gain2_o_idx_0 = 0.001 * (real_T)m1hp_cpp_DW->IndexVector2;
      rtb_Merge_idx_0 = 0.001 * (real_T)m1hp_cpp_DW->IndexVector1;
      rtb_Gain2_o_idx_2 = 0.001 * (real_T)m1hp_cpp_DW->IndexVector;

      /* Sum: '<S11>/Add' incorporates:
       *  Sum: '<S11>/Subtract'
       */
      rtb_Gain1_m = (rtb_Merge_idx_0 - rtb_Gain2_o_idx_0) + rtb_Gain2_o_idx_2;

      /* Sum: '<S11>/Subtract1' */
      rtb_Gain2_o_idx_2 -= rtb_Merge_idx_0;

      /* Gain: '<S11>/Gain3' incorporates:
       *  ForEachSliceSelector generated from: '<S3>/Dv'
       *  ForEachSliceSelector generated from: '<S3>/Dx'
       *  Gain: '<S11>/Gain'
       *  Gain: '<S11>/Gain1'
       *  Product: '<S11>/Divide'
       *  Product: '<S11>/Divide1'
       *  Product: '<S11>/Product'
       *  Product: '<S11>/Product1'
       *  Product: '<S11>/Product2'
       *  Product: '<S11>/Product3'
       *  Sum: '<S11>/Add1'
       *  Sum: '<S11>/Add2'
       *  Sum: '<S11>/Add3'
       */
      rtb_Merge_idx_0 = ((0.5 * rtb_Gain2_o_idx_2 + rtb_Merge_idx_0) *
                         m1hp_cpp_DW->Sub[ForEach_itr_p] + m1hp_cpp_DW->
                         Add[ForEach_itr_p]) / (rtb_Gain2_o_idx_0 * rtb_Gain1_m)
        * 2.0;
      rtb_Gain1_m = ((0.0 - m1hp_cpp_DW->Add[ForEach_itr_p]) - m1hp_cpp_DW->
                     Sub[ForEach_itr_p] * rtb_Gain2_o_idx_0 * 0.5) /
        (rtb_Gain1_m * rtb_Gain2_o_idx_2) * 2.0;

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem1' */
    } else if (tmp && (!rtb_Compare)) {
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      /* SignalConversion generated from: '<S13>/a_a_d' incorporates:
       *  Constant: '<S13>/Constant'
       */
      rtb_Merge_idx_0 = 0.0;
      rtb_Gain1_m = 0.0;

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem3' */
    } else {
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S12>/Action Port'
       */
      /* SignalConversion generated from: '<S12>/a_a_d' incorporates:
       *  ForEachSliceSelector generated from: '<S3>/acc_l'
       *  UnaryMinus: '<S12>/Unary Minus'
       */
      rtb_Merge_idx_0 = m1hp_cpp_DW->
        ImpAsg_InsertedFor_a_l_at_inpor[ForEach_itr_p];
      rtb_Gain1_m = -m1hp_cpp_DW->ImpAsg_InsertedFor_a_l_at_inpor[ForEach_itr_p];

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem2' */
    }

    /* End of If: '<S3>/If1' */

    /* If: '<S3>/If2' incorporates:
     *  Delay: '<S7>/Resettable Delay'
     */
    if (m1hp_cpp_DW->ResettableDelay_DSTATE == 0U) {
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      m1hp_cpp_IfActionSubsystem4(&m1hp_cpp_DW->CoreSubsys_p[ForEach_itr_p].
        acc_merge);

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem4' */
    } else if (m1hp_cpp_DW->ResettableDelay_DSTATE <= m1hp_cpp_DW->IndexVector2)
    {
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem_1' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      /* Merge: '<S3>/acc_merge' incorporates:
       *  SignalConversion generated from: '<S17>/a_l'
       */
      m1hp_cpp_DW->CoreSubsys_p[ForEach_itr_p].acc_merge = rtb_Merge_idx_0;

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem_1' */
    } else if ((m1hp_cpp_DW->ResettableDelay_DSTATE > m1hp_cpp_DW->IndexVector2)
               && (m1hp_cpp_DW->ResettableDelay_DSTATE <=
                   m1hp_cpp_DW->IndexVector1)) {
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      m1hp_cpp_IfActionSubsystem4(&m1hp_cpp_DW->CoreSubsys_p[ForEach_itr_p].
        acc_merge);

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem5' */
    } else if ((m1hp_cpp_DW->ResettableDelay_DSTATE > m1hp_cpp_DW->IndexVector1)
               && (m1hp_cpp_DW->ResettableDelay_DSTATE <=
                   m1hp_cpp_DW->IndexVector)) {
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem__1' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      /* Merge: '<S3>/acc_merge' incorporates:
       *  SignalConversion generated from: '<S18>/a_l'
       */
      m1hp_cpp_DW->CoreSubsys_p[ForEach_itr_p].acc_merge = rtb_Gain1_m;

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem__1' */
    } else if (m1hp_cpp_DW->ResettableDelay_DSTATE > m1hp_cpp_DW->IndexVector) {
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      m1hp_cpp_IfActionSubsystem4(&m1hp_cpp_DW->CoreSubsys_p[ForEach_itr_p].
        acc_merge);

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem6' */
    }

    /* End of If: '<S3>/If2' */

    /* ForEachSliceAssignment generated from: '<S3>/multi_ax_acc_d' */
    m1hp_cpp_DW->ImpAsg_InsertedFor_multi_ax_acc[ForEach_itr_p] =
      m1hp_cpp_DW->CoreSubsys_p[ForEach_itr_p].acc_merge;
  }

  /* End of Outputs for SubSystem: '<S1>/CPP with multi-axis coordination' */

  /* Outputs for Atomic SubSystem: '<S1>/CPP with multi-axis coordination1' */
  /* If: '<S4>/If2' incorporates:
   *  Delay: '<S7>/Resettable Delay'
   */
  if ((m1hp_cpp_DW->ResettableDelay_DSTATE == 0U) ||
      (m1hp_cpp_DW->ResettableDelay_DSTATE <= m1hp_cpp_DW->IndexVector2)) {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* Merge: '<S4>/Dk_merge' incorporates:
     *  Constant: '<S19>/Constant1'
     *  SignalConversion generated from: '<S19>/Dk'
     */
    m1hp_cpp_DW->Dk_merge = 0U;

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */
  } else if ((m1hp_cpp_DW->ResettableDelay_DSTATE > m1hp_cpp_DW->IndexVector2) &&
             (m1hp_cpp_DW->ResettableDelay_DSTATE <= m1hp_cpp_DW->IndexVector1))
  {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    /* Merge: '<S4>/Dk_merge' incorporates:
     *  SignalConversion generated from: '<S20>/t_a'
     */
    m1hp_cpp_DW->Dk_merge = m1hp_cpp_DW->IndexVector2;

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem1' */
  } else if ((m1hp_cpp_DW->ResettableDelay_DSTATE > m1hp_cpp_DW->IndexVector1) &&
             (m1hp_cpp_DW->ResettableDelay_DSTATE <= m1hp_cpp_DW->IndexVector))
  {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem__1' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    /* Merge: '<S4>/Dk_merge' incorporates:
     *  SignalConversion generated from: '<S22>/t_ac'
     */
    m1hp_cpp_DW->Dk_merge = m1hp_cpp_DW->IndexVector1;

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem__1' */
  } else if (m1hp_cpp_DW->ResettableDelay_DSTATE > m1hp_cpp_DW->IndexVector) {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    /* Merge: '<S4>/Dk_merge' incorporates:
     *  SignalConversion generated from: '<S21>/t_acd'
     */
    m1hp_cpp_DW->Dk_merge = m1hp_cpp_DW->IndexVector;

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem6' */
  }

  /* End of If: '<S4>/If2' */
  /* End of Outputs for SubSystem: '<S1>/CPP with multi-axis coordination1' */

  /* Outputs for Iterator SubSystem: '<S1>/Motion equations' incorporates:
   *  ForEach: '<S6>/For Each'
   */
  for (ForEach_itr_n = 0; ForEach_itr_n < 6; ForEach_itr_n++) {
    /* DiscreteIntegrator: '<S6>/Discrete-Time Integrator' incorporates:
     *  ForEachSliceSelector generated from: '<S6>/acc_d'
     */
    m1hp_cpp_DW->CoreSubsys_pn[ForEach_itr_n].DiscreteTimeIntegrator = 0.001 *
      m1hp_cpp_DW->ImpAsg_InsertedFor_multi_ax_acc[ForEach_itr_n] +
      m1hp_cpp_DW->CoreSubsys_pn[ForEach_itr_n].DiscreteTimeIntegrator_DSTATE;

    /* Gain: '<S6>/Gain1' incorporates:
     *  Delay: '<S7>/Resettable Delay'
     *  Sum: '<S6>/Subtract1'
     */
    rtb_Gain1_m = (real_T)(m1hp_cpp_DW->ResettableDelay_DSTATE -
      m1hp_cpp_DW->Dk_merge) * 0.0010000000002037268;

    /* Logic: '<S6>/Logical Operator' incorporates:
     *  Constant: '<S23>/Constant'
     *  Delay: '<S7>/Resettable Delay'
     *  ForEachSliceSelector generated from: '<S6>/acc_d'
     *  RelationalOperator: '<S23>/Compare'
     *  RelationalOperator: '<S24>/FixPt Relational Operator'
     *  UnitDelay: '<S24>/Delay Input1'
     *
     * Block description for '<S24>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_Compare = ((m1hp_cpp_DW->ImpAsg_InsertedFor_multi_ax_acc[ForEach_itr_n]
                    != m1hp_cpp_DW->CoreSubsys_pn[ForEach_itr_n].
                    DelayInput1_DSTATE) || (m1hp_cpp_DW->ResettableDelay_DSTATE ==
      0U));

    /* Outputs for Triggered SubSystem: '<S6>/Triggered Subsystem' incorporates:
     *  TriggerPort: '<S25>/Trigger'
     */
    if (rtb_Compare && (m1hp_cpp_PrevZCX->CoreSubsys_pn[ForEach_itr_n].
                        TriggeredSubsystem_Trig_ZCE_c != POS_ZCSIG)) {
      /* SignalConversion generated from: '<S25>/x0_in' incorporates:
       *  Memory generated from: '<S6>/Triggered Subsystem'
       */
      m1hp_cpp_DW->CoreSubsys_pn[ForEach_itr_n].x0_in =
        m1hp_cpp_DW->CoreSubsys_pn[ForEach_itr_n].
        TmpLatchAtTriggeredSubsystemInp;

      /* SignalConversion generated from: '<S25>/v0_in' incorporates:
       *  Memory generated from: '<S6>/Triggered Subsystem'
       */
      m1hp_cpp_DW->CoreSubsys_pn[ForEach_itr_n].v0_in =
        m1hp_cpp_DW->CoreSubsys_pn[ForEach_itr_n].
        TmpLatchAtTriggeredSubsystemI_e;
    }

    m1hp_cpp_PrevZCX->CoreSubsys_pn[ForEach_itr_n].TriggeredSubsystem_Trig_ZCE_c
      = rtb_Compare;

    /* End of Outputs for SubSystem: '<S6>/Triggered Subsystem' */

    /* Sum: '<S6>/Add' incorporates:
     *  ForEachSliceSelector generated from: '<S6>/acc_d'
     *  Gain: '<S6>/Gain'
     *  Math: '<S6>/Math Function'
     *  Product: '<S6>/Product'
     *  Product: '<S6>/Product1'
     *
     * About '<S6>/Math Function':
     *  Operator: magnitude^2
     */
    rtb_Gain1_m = (0.5 * m1hp_cpp_DW->
                   ImpAsg_InsertedFor_multi_ax_acc[ForEach_itr_n] * (rtb_Gain1_m
      * rtb_Gain1_m) + rtb_Gain1_m * m1hp_cpp_DW->CoreSubsys_pn[ForEach_itr_n].
                   v0_in) + m1hp_cpp_DW->CoreSubsys_pn[ForEach_itr_n].x0_in;

    /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
    m1hp_cpp_DW->CoreSubsys_pn[ForEach_itr_n].DiscreteTimeIntegrator_DSTATE =
      m1hp_cpp_DW->CoreSubsys_pn[ForEach_itr_n].DiscreteTimeIntegrator;

    /* Update for Memory generated from: '<S6>/Triggered Subsystem' */
    m1hp_cpp_DW->CoreSubsys_pn[ForEach_itr_n].TmpLatchAtTriggeredSubsystemInp =
      rtb_Gain1_m;

    /* Update for Memory generated from: '<S6>/Triggered Subsystem' */
    m1hp_cpp_DW->CoreSubsys_pn[ForEach_itr_n].TmpLatchAtTriggeredSubsystemI_e =
      m1hp_cpp_DW->CoreSubsys_pn[ForEach_itr_n].DiscreteTimeIntegrator;

    /* Update for UnitDelay: '<S24>/Delay Input1' incorporates:
     *  ForEachSliceSelector generated from: '<S6>/acc_d'
     *
     * Block description for '<S24>/Delay Input1':
     *
     *  Store in Global RAM
     */
    m1hp_cpp_DW->CoreSubsys_pn[ForEach_itr_n].DelayInput1_DSTATE =
      m1hp_cpp_DW->ImpAsg_InsertedFor_multi_ax_acc[ForEach_itr_n];

    /* ForEachSliceAssignment generated from: '<S6>/pos_d_vec' */
    rtb_ImpAsg_InsertedFor_pos_d_ve[ForEach_itr_n] = rtb_Gain1_m;

    /* ForEachSliceAssignment generated from: '<S6>/vel_d_vec' */
    rtb_ImpAsg_InsertedFor_vel_d_ve[ForEach_itr_n] = m1hp_cpp_DW->
      CoreSubsys_pn[ForEach_itr_n].DiscreteTimeIntegrator;
  }

  /* End of Outputs for SubSystem: '<S1>/Motion equations' */

  /* Outputs for Iterator SubSystem: '<S1>/Bessel filter' incorporates:
   *  ForEach: '<S2>/For Each'
   */
  for (ForEach_itr_o = 0; ForEach_itr_o < 6; ForEach_itr_o++) {
    /* ForEachSliceSelector generated from: '<S2>/acc_vec' */
    rtb_ImpSel_InsertedFor_acc_vec_ =
      m1hp_cpp_DW->ImpAsg_InsertedFor_multi_ax_acc[ForEach_itr_o];

    /* DiscreteStateSpace: '<S9>/Bessel filter Acc' */
    {
      rtb_acc_f_vec_CoreSubsysCanOut = (0.03244777426700398)*
        m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].BesselfilterAcc_DSTATE[0]
        + (-0.041870031249146511)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterAcc_DSTATE[1]
        + (-0.028713548427511344)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterAcc_DSTATE[2]
        + (0.011133012176218511)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterAcc_DSTATE[3];
      rtb_acc_f_vec_CoreSubsysCanOut += 9.5056513600000106E-7*
        rtb_ImpSel_InsertedFor_acc_vec_;
    }

    /* Sum: '<S9>/Add1' incorporates:
     *  ForEachSliceSelector generated from: '<S2>/pos_vec'
     */
    rtb_Add1_i = rtb_ImpAsg_InsertedFor_pos_d_ve[ForEach_itr_o];

    /* DiscreteStateSpace: '<S9>/Bessel filter Pos' */
    {
      rtb_pos_f_vec_CoreSubsysCanOut = (0.03244777426700398)*
        m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].BesselfilterPos_DSTATE[0]
        + (-0.041870031249146511)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterPos_DSTATE[1]
        + (-0.028713548427511344)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterPos_DSTATE[2]
        + (0.011133012176218511)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterPos_DSTATE[3];
      rtb_pos_f_vec_CoreSubsysCanOut += 9.5056513600000106E-7*rtb_Add1_i;
    }

    /* Sum: '<S9>/Add2' incorporates:
     *  ForEachSliceSelector generated from: '<S2>/vel_vec'
     */
    rtb_Add2 = rtb_ImpAsg_InsertedFor_vel_d_ve[ForEach_itr_o];

    /* DiscreteStateSpace: '<S9>/Bessel filter Vel' */
    {
      rtb_vel_f_vec_CoreSubsysCanOut = (0.03244777426700398)*
        m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].BesselfilterVel_DSTATE[0]
        + (-0.041870031249146511)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterVel_DSTATE[1]
        + (-0.028713548427511344)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterVel_DSTATE[2]
        + (0.011133012176218511)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterVel_DSTATE[3];
      rtb_vel_f_vec_CoreSubsysCanOut += 9.5056513600000106E-7*rtb_Add2;
    }

    /* Update for DiscreteStateSpace: '<S9>/Bessel filter Acc' */
    {
      real_T xnew[4];
      xnew[0] = (0.99929981431203641)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterAcc_DSTATE[0]
        + (0.0031042747865349662)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterAcc_DSTATE[1]
        + (0.0011272265388925784)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterAcc_DSTATE[2]
        + (-0.00048171513831302137)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterAcc_DSTATE[3];
      xnew[0] += (0.032447774267003127)*rtb_ImpSel_InsertedFor_acc_vec_;
      xnew[1] = (-0.0031042747865343)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterAcc_DSTATE[0]
        + (0.99721849747464386)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterAcc_DSTATE[1]
        + (-0.0048617293379392135)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterAcc_DSTATE[2]
        + (0.0014442780771489749)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterAcc_DSTATE[3];
      xnew[1] += (0.041870031249145408)*rtb_ImpSel_InsertedFor_acc_vec_;
      xnew[2] = (0.0011272265388921621)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterAcc_DSTATE[0]
        + (0.0048617293379379367)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterAcc_DSTATE[1]
        + (0.99393549261937664)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterAcc_DSTATE[2]
        + (0.0051618924477805084)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterAcc_DSTATE[3];
      xnew[2] += (-0.028713548427510987)*rtb_ImpSel_InsertedFor_acc_vec_;
      xnew[3] = (0.00048171513831271606)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterAcc_DSTATE[0]
        + (0.0014442780771486141)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterAcc_DSTATE[1]
        + (-0.0051618924477798978)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterAcc_DSTATE[2]
        + (0.98956855323730686)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterAcc_DSTATE[3];
      xnew[3] += (-0.011133012176218924)*rtb_ImpSel_InsertedFor_acc_vec_;
      (void) memcpy(&m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
                    BesselfilterAcc_DSTATE[0], xnew,
                    sizeof(real_T)*4);
    }

    /* Update for DiscreteStateSpace: '<S9>/Bessel filter Pos' */
    {
      real_T xnew[4];
      xnew[0] = (0.99929981431203641)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterPos_DSTATE[0]
        + (0.0031042747865349662)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterPos_DSTATE[1]
        + (0.0011272265388925784)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterPos_DSTATE[2]
        + (-0.00048171513831302137)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterPos_DSTATE[3];
      xnew[0] += (0.032447774267003127)*rtb_Add1_i;
      xnew[1] = (-0.0031042747865343)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterPos_DSTATE[0]
        + (0.99721849747464386)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterPos_DSTATE[1]
        + (-0.0048617293379392135)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterPos_DSTATE[2]
        + (0.0014442780771489749)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterPos_DSTATE[3];
      xnew[1] += (0.041870031249145408)*rtb_Add1_i;
      xnew[2] = (0.0011272265388921621)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterPos_DSTATE[0]
        + (0.0048617293379379367)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterPos_DSTATE[1]
        + (0.99393549261937664)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterPos_DSTATE[2]
        + (0.0051618924477805084)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterPos_DSTATE[3];
      xnew[2] += (-0.028713548427510987)*rtb_Add1_i;
      xnew[3] = (0.00048171513831271606)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterPos_DSTATE[0]
        + (0.0014442780771486141)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterPos_DSTATE[1]
        + (-0.0051618924477798978)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterPos_DSTATE[2]
        + (0.98956855323730686)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterPos_DSTATE[3];
      xnew[3] += (-0.011133012176218924)*rtb_Add1_i;
      (void) memcpy(&m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
                    BesselfilterPos_DSTATE[0], xnew,
                    sizeof(real_T)*4);
    }

    /* Update for DiscreteStateSpace: '<S9>/Bessel filter Vel' */
    {
      real_T xnew[4];
      xnew[0] = (0.99929981431203641)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterVel_DSTATE[0]
        + (0.0031042747865349662)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterVel_DSTATE[1]
        + (0.0011272265388925784)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterVel_DSTATE[2]
        + (-0.00048171513831302137)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterVel_DSTATE[3];
      xnew[0] += (0.032447774267003127)*rtb_Add2;
      xnew[1] = (-0.0031042747865343)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterVel_DSTATE[0]
        + (0.99721849747464386)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterVel_DSTATE[1]
        + (-0.0048617293379392135)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterVel_DSTATE[2]
        + (0.0014442780771489749)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterVel_DSTATE[3];
      xnew[1] += (0.041870031249145408)*rtb_Add2;
      xnew[2] = (0.0011272265388921621)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterVel_DSTATE[0]
        + (0.0048617293379379367)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterVel_DSTATE[1]
        + (0.99393549261937664)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterVel_DSTATE[2]
        + (0.0051618924477805084)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterVel_DSTATE[3];
      xnew[2] += (-0.028713548427510987)*rtb_Add2;
      xnew[3] = (0.00048171513831271606)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterVel_DSTATE[0]
        + (0.0014442780771486141)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterVel_DSTATE[1]
        + (-0.0051618924477798978)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterVel_DSTATE[2]
        + (0.98956855323730686)*m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
        BesselfilterVel_DSTATE[3];
      xnew[3] += (-0.011133012176218924)*rtb_Add2;
      (void) memcpy(&m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].
                    BesselfilterVel_DSTATE[0], xnew,
                    sizeof(real_T)*4);
    }

    /* ForEachSliceAssignment generated from: '<S2>/vel_f_vec' */
    rtb_ImpAsg_InsertedFor_vel_f_ve[ForEach_itr_o] =
      rtb_vel_f_vec_CoreSubsysCanOut;

    /* ForEachSliceAssignment generated from: '<S2>/pos_f_vec' */
    rtb_ImpAsg_InsertedFor_pos_f_ve[ForEach_itr_o] =
      rtb_pos_f_vec_CoreSubsysCanOut;

    /* ForEachSliceAssignment generated from: '<S2>/acc_f_vec' */
    rtb_ImpAsg_InsertedFor_acc_f_ve[ForEach_itr_o] =
      rtb_acc_f_vec_CoreSubsysCanOut;
  }

  /* End of Outputs for SubSystem: '<S1>/Bessel filter' */

  /* Update for UnitDelay: '<S7>/Unit Delay' incorporates:
   *  Constant: '<S7>/Constant'
   *  Delay: '<S7>/Resettable Delay'
   *  Sum: '<S7>/Add'
   */
  m1hp_cpp_DW->UnitDelay_DSTATE = m1hp_cpp_DW->ResettableDelay_DSTATE + 1U;

  /* Update for Delay: '<S7>/Resettable Delay' incorporates:
   *  Constant: '<S7>/Constant'
   *  Sum: '<S7>/Add'
   */
  m1hp_cpp_DW->ResettableDelay_DSTATE++;
  for (i = 0; i < 6; i++) {
    /* Outport: '<Root>/pos_d' */
    m1hp_cpp_Y->pos_d[i] = rtb_ImpAsg_InsertedFor_pos_f_ve[i];

    /* Outport: '<Root>/vel_d' incorporates:
     *  Outport: '<Root>/pos_d'
     */
    m1hp_cpp_Y->vel_d[i] = rtb_ImpAsg_InsertedFor_vel_f_ve[i];

    /* Outport: '<Root>/acc_d' incorporates:
     *  Outport: '<Root>/pos_d'
     */
    m1hp_cpp_Y->acc_d[i] = rtb_ImpAsg_InsertedFor_acc_f_ve[i];

    /* Update for Memory generated from: '<S1>/Triggered Subsystem' incorporates:
     *  Outport: '<Root>/pos_d'
     */
    m1hp_cpp_DW->TmpLatchAtTriggeredSubsystemInp[i] =
      rtb_ImpAsg_InsertedFor_pos_d_ve[i];

    /* Update for Memory generated from: '<S1>/Triggered Subsystem' incorporates:
     *  Outport: '<Root>/pos_d'
     */
    m1hp_cpp_DW->TmpLatchAtTriggeredSubsystemI_e[i] =
      rtb_ImpAsg_InsertedFor_vel_d_ve[i];
  }
}

/* Model initialize function */
void m1hp_cpp_initialize(RT_MODEL_m1hp_cpp_T *const m1hp_cpp_M)
{
  DW_m1hp_cpp_T *m1hp_cpp_DW = m1hp_cpp_M->dwork;
  PrevZCX_m1hp_cpp_T *m1hp_cpp_PrevZCX = m1hp_cpp_M->prevZCSigState;

  {
    /* local scratch DWork variables */
    int32_T ForEach_itr_n;
    int32_T ForEach_itr_p;
    int32_T ForEach_itr_o;
    m1hp_cpp_PrevZCX->ResettableDelay_Reset_ZCE = POS_ZCSIG;

    /* SystemInitialize for Triggered SubSystem: '<S1>/Triggered Subsystem' */
    m1hp_cpp_PrevZCX->TriggeredSubsystem_Trig_ZCE = ZERO_ZCSIG;

    /* End of SystemInitialize for SubSystem: '<S1>/Triggered Subsystem' */
    /* SystemInitialize for Iterator SubSystem: '<S1>/CPP with multi-axis coordination' */
    for (ForEach_itr_p = 0; ForEach_itr_p < 6; ForEach_itr_p++) {
      /* SystemInitialize for Iterator SubSystem: '<S1>/CPP with multi-axis coordination' */
      /* SystemInitialize for IfAction SubSystem: '<S3>/If Action Subsystem4' */
      m1hp_cp_IfActionSubsystem4_Init(&m1hp_cpp_DW->CoreSubsys_p[ForEach_itr_p].
        acc_merge);

      /* End of SystemInitialize for SubSystem: '<S3>/If Action Subsystem4' */

      /* SystemInitialize for IfAction SubSystem: '<S3>/If Action Subsystem5' */
      m1hp_cp_IfActionSubsystem4_Init(&m1hp_cpp_DW->CoreSubsys_p[ForEach_itr_p].
        acc_merge);

      /* End of SystemInitialize for SubSystem: '<S3>/If Action Subsystem5' */

      /* SystemInitialize for IfAction SubSystem: '<S3>/If Action Subsystem6' */
      m1hp_cp_IfActionSubsystem4_Init(&m1hp_cpp_DW->CoreSubsys_p[ForEach_itr_p].
        acc_merge);

      /* End of SystemInitialize for SubSystem: '<S3>/If Action Subsystem6' */
      /* End of SystemInitialize for SubSystem: '<S1>/CPP with multi-axis coordination' */
    }

    /* End of SystemInitialize for SubSystem: '<S1>/CPP with multi-axis coordination' */
    /* SystemInitialize for Iterator SubSystem: '<S1>/Motion equations' */
    for (ForEach_itr_n = 0; ForEach_itr_n < 6; ForEach_itr_n++) {
      m1hp_cpp_PrevZCX->CoreSubsys_pn[ForEach_itr_n].
        TriggeredSubsystem_Trig_ZCE_c = POS_ZCSIG;
    }

    /* End of SystemInitialize for SubSystem: '<S1>/Motion equations' */

    /* SystemInitialize for Iterator SubSystem: '<S1>/Bessel filter' */
    for (ForEach_itr_o = 0; ForEach_itr_o < 6; ForEach_itr_o++) {
      /* InitializeConditions for DiscreteStateSpace: '<S9>/Bessel filter Acc' */
      m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].BesselfilterAcc_DSTATE[0] =
        (22.445597347965286);
      m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].BesselfilterAcc_DSTATE[1] =
        (-4.1265427674370088);
      m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].BesselfilterAcc_DSTATE[2] =
        (-3.0842114695425646);
      m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].BesselfilterAcc_DSTATE[3] =
        (0.92411577345206064);

      /* InitializeConditions for DiscreteStateSpace: '<S9>/Bessel filter Pos' */
      m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].BesselfilterPos_DSTATE[0] =
        (22.445597347965286);
      m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].BesselfilterPos_DSTATE[1] =
        (-4.1265427674370088);
      m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].BesselfilterPos_DSTATE[2] =
        (-3.0842114695425646);
      m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].BesselfilterPos_DSTATE[3] =
        (0.92411577345206064);

      /* InitializeConditions for DiscreteStateSpace: '<S9>/Bessel filter Vel' */
      m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].BesselfilterVel_DSTATE[0] =
        (22.445597347965286);
      m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].BesselfilterVel_DSTATE[1] =
        (-4.1265427674370088);
      m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].BesselfilterVel_DSTATE[2] =
        (-3.0842114695425646);
      m1hp_cpp_DW->CoreSubsys[ForEach_itr_o].BesselfilterVel_DSTATE[3] =
        (0.92411577345206064);
    }

    /* End of SystemInitialize for SubSystem: '<S1>/Bessel filter' */
  }
}

/* Model terminate function */
void m1hp_cpp_terminate(RT_MODEL_m1hp_cpp_T *const m1hp_cpp_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(m1hp_cpp_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
