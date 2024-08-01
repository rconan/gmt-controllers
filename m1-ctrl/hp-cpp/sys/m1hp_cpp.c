/*
 * File: m1hp_cpp.c
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
#include "rtwtypes.h"
#include "m1hp_cpp_private.h"
#include <math.h>
#include "zero_crossing_types.h"

/*
 * System initialize for action system:
 *    '<S2>/If Action Subsystem4'
 *    '<S2>/If Action Subsystem5'
 *    '<S2>/If Action Subsystem6'
 */
void m1hp_cp_IfActionSubsystem4_Init(real_T *rty_ac0)
{
  *rty_ac0 = 0.0;
}

/*
 * Output and update for action system:
 *    '<S2>/If Action Subsystem4'
 *    '<S2>/If Action Subsystem5'
 *    '<S2>/If Action Subsystem6'
 */
void m1hp_cpp_IfActionSubsystem4(real_T *rty_ac0,
  P_IfActionSubsystem4_m1hp_cpp_T *localP)
{
  /* SignalConversion generated from: '<S12>/ac0' incorporates:
   *  Constant: '<S12>/Constant'
   */
  *rty_ac0 = localP->Constant_Value;
}

/* Model step function */
void m1hp_cpp_step(RT_MODEL_m1hp_cpp_T *const m1hp_cpp_M, ExtU_m1hp_cpp_T
                   *m1hp_cpp_U, ExtY_m1hp_cpp_T *m1hp_cpp_Y)
{
  DW_m1hp_cpp_T *m1hp_cpp_DW = m1hp_cpp_M->dwork;
  PrevZCX_m1hp_cpp_T *m1hp_cpp_PrevZCX = m1hp_cpp_M->prevZCSigState;
  real_T rtb_TmpLatchAtTriggeredSubsys_j[6];
  real_T rtb_TmpLatchAtTriggeredSubsyste[6];
  real_T Dv;
  real_T Dx;
  real_T rtb_Gain1_m;
  real_T rtb_t_d_k;
  int32_T i;
  uint32_T rtb_ImpAsg_InsertedFor_t_a_at_i[6];
  uint32_T rtb_ImpAsg_InsertedFor_t_a_c_at[6];
  uint32_T rtb_ImpAsg_InsertedFor_t_a_d_at[6];
  uint32_T rtb_Add_o;
  int16_T rtb_Switch1;
  int16_T s25_iter;
  boolean_T rtb_Compare;

  /* Memory generated from: '<S1>/Triggered Subsystem' */
  for (i = 0; i < 6; i++) {
    rtb_TmpLatchAtTriggeredSubsyste[i] =
      m1hp_cpp_DW->TmpLatchAtTriggeredSubsystemInp[i];
  }

  /* End of Memory generated from: '<S1>/Triggered Subsystem' */

  /* RelationalOperator: '<S24>/Compare' incorporates:
   *  Constant: '<S24>/Constant'
   *  UnitDelay: '<S6>/Unit Delay'
   */
  rtb_Compare = (m1hp_cpp_DW->UnitDelay_DSTATE == m1hp_cpp_P.k_cmd);

  /* Delay: '<S6>/Resettable Delay' */
  if (rtb_Compare && (m1hp_cpp_PrevZCX->ResettableDelay_Reset_ZCE != POS_ZCSIG))
  {
    m1hp_cpp_DW->ResettableDelay_DSTATE =
      m1hp_cpp_P.ResettableDelay_InitialConditio;
  }

  m1hp_cpp_PrevZCX->ResettableDelay_Reset_ZCE = rtb_Compare;

  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S4>/Constant'
   *  Delay: '<S6>/Resettable Delay'
   */
  rtb_Compare = (m1hp_cpp_DW->ResettableDelay_DSTATE ==
                 m1hp_cpp_P.Constant_Value_g);

  /* Memory generated from: '<S1>/Triggered Subsystem' */
  for (i = 0; i < 6; i++) {
    rtb_TmpLatchAtTriggeredSubsys_j[i] =
      m1hp_cpp_DW->TmpLatchAtTriggeredSubsystemI_e[i];
  }

  /* End of Memory generated from: '<S1>/Triggered Subsystem' */

  /* Outputs for Triggered SubSystem: '<S1>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S7>/Trigger'
   */
  if (rtb_Compare && (m1hp_cpp_PrevZCX->TriggeredSubsystem_Trig_ZCE != POS_ZCSIG))
  {
    int16_T Memory1_PreviousInput;
    int16_T tmp;
    for (i = 0; i < 6; i++) {
      /* Sum: '<S7>/Add' */
      m1hp_cpp_DW->Add[i] = m1hp_cpp_U->x_target[i] -
        rtb_TmpLatchAtTriggeredSubsyste[i];
    }

    /* Outputs for Iterator SubSystem: '<S7>/Multi-axis demand' incorporates:
     *  ForEach: '<S26>/For Each'
     */
    for (i = 0; i < 6; i++) {
      real_T rtb_TmpLatchAtTriggeredSubsys_a;
      real_T t_a;
      real_T v_l;

      /* ForEachSliceSelector generated from: '<S26>/v0' */
      rtb_TmpLatchAtTriggeredSubsys_a = rtb_TmpLatchAtTriggeredSubsys_j[i];

      /* MATLAB Function: '<S26>/MATLAB Function' incorporates:
       *  Constant: '<S26>/Constant'
       *  Constant: '<S26>/Constant1'
       *  ForEachSliceSelector generated from: '<S26>/v1'
       *  ForEachSliceSelector generated from: '<S26>/x0'
       *  ForEachSliceSelector generated from: '<S26>/x1'
       */
      Dv = m1hp_cpp_U->v_target[i] - rtb_TmpLatchAtTriggeredSubsys_a;
      Dx = m1hp_cpp_U->x_target[i] - rtb_TmpLatchAtTriggeredSubsyste[i];
      rtb_Gain1_m = m1hp_cpp_P.a_max;
      v_l = m1hp_cpp_P.v_max;
      if (Dx < 0.0) {
        rtb_Gain1_m = -m1hp_cpp_P.a_max;
        v_l = -m1hp_cpp_P.v_max;
      }

      rtb_t_d_k = sqrt(Dv * Dv * 0.5 + Dx * rtb_Gain1_m) * fabs(1.0 /
        rtb_Gain1_m);
      t_a = Dv / rtb_Gain1_m + rtb_t_d_k;
      if (t_a < 0.0) {
        t_a = 0.0;
        printf("=> t_a=%g, t_d=%g, a_l=%g, D_v=%g\n", 0.0, rtb_t_d_k,
               rtb_Gain1_m, Dv);
        fflush(stdout);
      }

      if (fabs(rtb_Gain1_m * t_a + rtb_TmpLatchAtTriggeredSubsys_a) > fabs(v_l))
      {
        t_a = 1.0 / rtb_Gain1_m * (v_l - rtb_TmpLatchAtTriggeredSubsys_a);
        rtb_TmpLatchAtTriggeredSubsys_a = v_l - m1hp_cpp_U->v_target[i];
        rtb_t_d_k = 1.0 / rtb_Gain1_m * rtb_TmpLatchAtTriggeredSubsys_a;
        Dv = (((Dv * t_a + Dx) - rtb_TmpLatchAtTriggeredSubsys_a * rtb_t_d_k) +
              (rtb_t_d_k * rtb_t_d_k - t_a * t_a) * (0.5 * rtb_Gain1_m)) /
          rtb_TmpLatchAtTriggeredSubsys_a;
      } else {
        Dv = 0.0;
      }

      /* Gain: '<S26>/Gain1' incorporates:
       *  MATLAB Function: '<S26>/MATLAB Function'
       */
      Dx = m1hp_cpp_P.CoreSubsys_pn.Gain1_Gain * t_a;
      t_a = fabs(Dx);
      if (t_a < 4.503599627370496E+15) {
        if (t_a >= 0.5) {
          Dx = floor(Dx + 0.5);
        } else {
          Dx = 0.0;
        }
      }

      /* Gain: '<S26>/Gain2' */
      Dv *= m1hp_cpp_P.CoreSubsys_pn.Gain2_Gain;
      t_a = fabs(Dv);
      if (t_a < 4.503599627370496E+15) {
        if (t_a >= 0.5) {
          Dv = floor(Dv + 0.5);
        } else {
          Dv = 0.0;
        }
      }

      /* Sum: '<S26>/Add' incorporates:
       *  Gain: '<S26>/Gain1'
       *  Gain: '<S26>/Gain2'
       */
      rtb_Add_o = (uint32_T)Dx + (uint32_T)Dv;

      /* Gain: '<S26>/Gain3' incorporates:
       *  MATLAB Function: '<S26>/MATLAB Function'
       */
      Dv = m1hp_cpp_P.CoreSubsys_pn.Gain3_Gain * rtb_t_d_k;
      t_a = fabs(Dv);
      if (t_a < 4.503599627370496E+15) {
        if (t_a >= 0.5) {
          Dv = floor(Dv + 0.5);
        } else {
          Dv = 0.0;
        }
      }

      /* ForEachSliceAssignment generated from: '<S26>/t_a_d' incorporates:
       *  Gain: '<S26>/Gain3'
       *  Sum: '<S26>/Add_acd'
       */
      rtb_ImpAsg_InsertedFor_t_a_d_at[i] = rtb_Add_o + (uint32_T)Dv;

      /* ForEachSliceAssignment generated from: '<S26>/t_a_c' */
      rtb_ImpAsg_InsertedFor_t_a_c_at[i] = rtb_Add_o;

      /* ForEachSliceAssignment generated from: '<S26>/t_a' incorporates:
       *  Gain: '<S26>/Gain1'
       */
      rtb_ImpAsg_InsertedFor_t_a_at_i[i] = (uint32_T)Dx;

      /* ForEachSliceAssignment generated from: '<S26>/a_l' incorporates:
       *  MATLAB Function: '<S26>/MATLAB Function'
       */
      m1hp_cpp_DW->ImpAsg_InsertedFor_a_l_at_inpor[i] = rtb_Gain1_m;
    }

    /* End of Outputs for SubSystem: '<S7>/Multi-axis demand' */

    /* Outputs for Iterator SubSystem: '<S7>/Detect max t_seg' incorporates:
     *  ForIterator: '<S25>/For Iterator'
     */
    /* InitializeConditions for Memory: '<S25>/Memory1' */
    Memory1_PreviousInput = m1hp_cpp_P.Memory1_InitialCondition;
    tmp = m1hp_cpp_ConstB.Width1;
    if (m1hp_cpp_ConstB.Width1 < 0) {
      tmp = 0;
    }

    for (s25_iter = 0; s25_iter < tmp; s25_iter++) {
      /* MinMax: '<S25>/MinMax' */
      rtb_Add_o = rtb_ImpAsg_InsertedFor_t_a_d_at[0];
      for (i = 0; i < 5; i++) {
        uint32_T u1;
        u1 = rtb_ImpAsg_InsertedFor_t_a_d_at[i + 1];
        if (rtb_Add_o < u1) {
          rtb_Add_o = u1;
        }
      }

      for (i = 0; i < 6; i++) {
        /* RelationalOperator: '<S27>/Compare' incorporates:
         *  Constant: '<S27>/Constant'
         *  MinMax: '<S25>/MinMax'
         *  Sum: '<S25>/Subtract'
         */
        m1hp_cpp_DW->Compare[i] = ((int32_T)rtb_ImpAsg_InsertedFor_t_a_d_at[i] -
          (int32_T)rtb_Add_o == m1hp_cpp_P.Constant_Value);
      }

      /* Sum: '<S25>/Add' */
      rtb_Switch1 = (int16_T)(m1hp_cpp_ConstB.Width1 - s25_iter);

      /* Switch: '<S25>/Switch1' incorporates:
       *  Memory: '<S25>/Memory1'
       *  Selector: '<S25>/Selector1'
       */
      if (!m1hp_cpp_DW->Compare[rtb_Switch1 - 1]) {
        rtb_Switch1 = Memory1_PreviousInput;
      }

      /* End of Switch: '<S25>/Switch1' */

      /* Update for Memory: '<S25>/Memory1' */
      Memory1_PreviousInput = rtb_Switch1;
    }

    /* End of Outputs for SubSystem: '<S7>/Detect max t_seg' */

    /* MultiPortSwitch: '<S7>/Index Vector' */
    m1hp_cpp_DW->IndexVector = rtb_ImpAsg_InsertedFor_t_a_d_at[rtb_Switch1 - 1];

    /* MultiPortSwitch: '<S7>/Index Vector1' incorporates:
     *  MultiPortSwitch: '<S7>/Index Vector'
     */
    m1hp_cpp_DW->IndexVector1 = rtb_ImpAsg_InsertedFor_t_a_c_at[rtb_Switch1 - 1];

    /* MultiPortSwitch: '<S7>/Index Vector2' incorporates:
     *  MultiPortSwitch: '<S7>/Index Vector'
     */
    m1hp_cpp_DW->IndexVector2 = rtb_ImpAsg_InsertedFor_t_a_at_i[rtb_Switch1 - 1];
    for (i = 0; i < 6; i++) {
      /* Sum: '<S7>/Sub' */
      m1hp_cpp_DW->Sub[i] = m1hp_cpp_U->v_target[i] -
        rtb_TmpLatchAtTriggeredSubsys_j[i];
    }
  }

  m1hp_cpp_PrevZCX->TriggeredSubsystem_Trig_ZCE = rtb_Compare;

  /* End of Outputs for SubSystem: '<S1>/Triggered Subsystem' */

  /* Outputs for Iterator SubSystem: '<S1>/CPP with multi-axis coordination' incorporates:
   *  ForEach: '<S2>/For Each'
   */
  for (i = 0; i < 6; i++) {
    boolean_T tmp_0;

    /* RelationalOperator: '<S8>/Compare' incorporates:
     *  Constant: '<S8>/Constant'
     */
    rtb_Compare = (m1hp_cpp_DW->IndexVector >
                   m1hp_cpp_P.CoreSubsys.Constant_Value_l);

    /* If: '<S2>/If1' incorporates:
     *  ForEachSliceSelector generated from: '<S2>/max_bool'
     */
    tmp_0 = !m1hp_cpp_DW->Compare[i];
    if (tmp_0 && rtb_Compare) {
      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S9>/Action Port'
       */
      /* Gain: '<S9>/Gain2' incorporates:
       *  SignalConversion generated from: '<S9>/Gain2'
       */
      Dv = m1hp_cpp_P.CoreSubsys.Gain2_Gain * (real_T)m1hp_cpp_DW->IndexVector2;
      Dx = m1hp_cpp_P.CoreSubsys.Gain2_Gain * (real_T)m1hp_cpp_DW->IndexVector1;
      rtb_t_d_k = m1hp_cpp_P.CoreSubsys.Gain2_Gain * (real_T)
        m1hp_cpp_DW->IndexVector;

      /* Sum: '<S9>/Add' incorporates:
       *  Sum: '<S9>/Subtract'
       */
      rtb_Gain1_m = (Dx - Dv) + rtb_t_d_k;

      /* Sum: '<S9>/Subtract1' */
      rtb_t_d_k -= Dx;

      /* Gain: '<S9>/Gain3' incorporates:
       *  ForEachSliceSelector generated from: '<S2>/Dv'
       *  ForEachSliceSelector generated from: '<S2>/Dx'
       *  Gain: '<S9>/Gain'
       *  Gain: '<S9>/Gain1'
       *  Product: '<S9>/Divide'
       *  Product: '<S9>/Divide1'
       *  Product: '<S9>/Product'
       *  Product: '<S9>/Product1'
       *  Product: '<S9>/Product2'
       *  Product: '<S9>/Product3'
       *  Sum: '<S9>/Add1'
       *  Sum: '<S9>/Add2'
       *  Sum: '<S9>/Add3'
       */
      Dx = ((m1hp_cpp_P.CoreSubsys.Gain_Gain * rtb_t_d_k + Dx) *
            m1hp_cpp_DW->Sub[i] + m1hp_cpp_DW->Add[i]) / (Dv * rtb_Gain1_m) *
        m1hp_cpp_P.CoreSubsys.Gain3_Gain;
      rtb_Gain1_m = ((0.0 - m1hp_cpp_DW->Add[i]) - m1hp_cpp_DW->Sub[i] * Dv *
                     m1hp_cpp_P.CoreSubsys.Gain1_Gain) / (rtb_Gain1_m *
        rtb_t_d_k) * m1hp_cpp_P.CoreSubsys.Gain3_Gain;

      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem1' */
    } else if (tmp_0 && (!rtb_Compare)) {
      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      /* SignalConversion generated from: '<S11>/a_a_d' incorporates:
       *  Constant: '<S11>/Constant'
       */
      Dx = m1hp_cpp_P.CoreSubsys.Constant_Value;
      rtb_Gain1_m = m1hp_cpp_P.CoreSubsys.Constant_Value;

      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem3' */
    } else {
      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      /* SignalConversion generated from: '<S10>/a_a_d' incorporates:
       *  ForEachSliceSelector generated from: '<S2>/acc_l'
       *  UnaryMinus: '<S10>/Unary Minus'
       */
      Dx = m1hp_cpp_DW->ImpAsg_InsertedFor_a_l_at_inpor[i];
      rtb_Gain1_m = -m1hp_cpp_DW->ImpAsg_InsertedFor_a_l_at_inpor[i];

      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem2' */
    }

    /* End of If: '<S2>/If1' */

    /* If: '<S2>/If2' incorporates:
     *  Delay: '<S6>/Resettable Delay'
     */
    if (m1hp_cpp_DW->ResettableDelay_DSTATE == 0U) {
      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S12>/Action Port'
       */
      m1hp_cpp_IfActionSubsystem4(&m1hp_cpp_DW->CoreSubsys[i].acc_merge,
        &m1hp_cpp_P.CoreSubsys.IfActionSubsystem4);

      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem4' */
    } else if (m1hp_cpp_DW->ResettableDelay_DSTATE <= m1hp_cpp_DW->IndexVector2)
    {
      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem_1' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* Merge: '<S2>/acc_merge' incorporates:
       *  SignalConversion generated from: '<S15>/a_l'
       */
      m1hp_cpp_DW->CoreSubsys[i].acc_merge = Dx;

      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem_1' */
    } else if ((m1hp_cpp_DW->ResettableDelay_DSTATE > m1hp_cpp_DW->IndexVector2)
               && (m1hp_cpp_DW->ResettableDelay_DSTATE <=
                   m1hp_cpp_DW->IndexVector1)) {
      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      m1hp_cpp_IfActionSubsystem4(&m1hp_cpp_DW->CoreSubsys[i].acc_merge,
        &m1hp_cpp_P.CoreSubsys.IfActionSubsystem5);

      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem5' */
    } else if ((m1hp_cpp_DW->ResettableDelay_DSTATE > m1hp_cpp_DW->IndexVector1)
               && (m1hp_cpp_DW->ResettableDelay_DSTATE <=
                   m1hp_cpp_DW->IndexVector)) {
      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem__1' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      /* Merge: '<S2>/acc_merge' incorporates:
       *  SignalConversion generated from: '<S16>/a_l'
       */
      m1hp_cpp_DW->CoreSubsys[i].acc_merge = rtb_Gain1_m;

      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem__1' */
    } else if (m1hp_cpp_DW->ResettableDelay_DSTATE > m1hp_cpp_DW->IndexVector) {
      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      m1hp_cpp_IfActionSubsystem4(&m1hp_cpp_DW->CoreSubsys[i].acc_merge,
        &m1hp_cpp_P.CoreSubsys.IfActionSubsystem6);

      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem6' */
    }

    /* End of If: '<S2>/If2' */

    /* ForEachSliceAssignment generated from: '<S2>/multi_ax_acc_d' */
    rtb_TmpLatchAtTriggeredSubsyste[i] = m1hp_cpp_DW->CoreSubsys[i].acc_merge;
  }

  /* End of Outputs for SubSystem: '<S1>/CPP with multi-axis coordination' */

  /* Outputs for Atomic SubSystem: '<S1>/CPP with multi-axis coordination1' */
  /* If: '<S3>/If2' incorporates:
   *  Delay: '<S6>/Resettable Delay'
   */
  if ((m1hp_cpp_DW->ResettableDelay_DSTATE == 0U) ||
      (m1hp_cpp_DW->ResettableDelay_DSTATE <= m1hp_cpp_DW->IndexVector2)) {
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* Merge: '<S3>/Dk_merge' incorporates:
     *  Constant: '<S17>/Constant1'
     *  SignalConversion generated from: '<S17>/Dk'
     */
    m1hp_cpp_DW->Dk_merge = m1hp_cpp_P.Constant1_Value;

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */
  } else if ((m1hp_cpp_DW->ResettableDelay_DSTATE > m1hp_cpp_DW->IndexVector2) &&
             (m1hp_cpp_DW->ResettableDelay_DSTATE <= m1hp_cpp_DW->IndexVector1))
  {
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    /* Merge: '<S3>/Dk_merge' incorporates:
     *  SignalConversion generated from: '<S18>/t_a'
     */
    m1hp_cpp_DW->Dk_merge = m1hp_cpp_DW->IndexVector2;

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem1' */
  } else if ((m1hp_cpp_DW->ResettableDelay_DSTATE > m1hp_cpp_DW->IndexVector1) &&
             (m1hp_cpp_DW->ResettableDelay_DSTATE <= m1hp_cpp_DW->IndexVector))
  {
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem__1' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    /* Merge: '<S3>/Dk_merge' incorporates:
     *  SignalConversion generated from: '<S20>/t_ac'
     */
    m1hp_cpp_DW->Dk_merge = m1hp_cpp_DW->IndexVector1;

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem__1' */
  } else if (m1hp_cpp_DW->ResettableDelay_DSTATE > m1hp_cpp_DW->IndexVector) {
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* Merge: '<S3>/Dk_merge' incorporates:
     *  SignalConversion generated from: '<S19>/t_acd'
     */
    m1hp_cpp_DW->Dk_merge = m1hp_cpp_DW->IndexVector;

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem6' */
  }

  /* End of If: '<S3>/If2' */
  /* End of Outputs for SubSystem: '<S1>/CPP with multi-axis coordination1' */

  /* Sum: '<S6>/Add' incorporates:
   *  Constant: '<S6>/Constant'
   *  Delay: '<S6>/Resettable Delay'
   */
  rtb_Add_o = m1hp_cpp_P.Constant_Value_m + m1hp_cpp_DW->ResettableDelay_DSTATE;

  /* Update for UnitDelay: '<S6>/Unit Delay' */
  m1hp_cpp_DW->UnitDelay_DSTATE = rtb_Add_o;

  /* Outputs for Iterator SubSystem: '<S1>/Motion equations' incorporates:
   *  ForEach: '<S5>/For Each'
   */
  for (i = 0; i < 6; i++) {
    /* ForEachSliceSelector generated from: '<S5>/acc_d' */
    rtb_t_d_k = rtb_TmpLatchAtTriggeredSubsyste[i];

    /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
    m1hp_cpp_DW->CoreSubsys_p[i].DiscreteTimeIntegrator =
      m1hp_cpp_P.CoreSubsys_p.DiscreteTimeIntegrator_gainval * rtb_t_d_k +
      m1hp_cpp_DW->CoreSubsys_p[i].DiscreteTimeIntegrator_DSTATE;

    /* Gain: '<S5>/Gain1' incorporates:
     *  Delay: '<S6>/Resettable Delay'
     *  Sum: '<S5>/Subtract1'
     */
    rtb_Gain1_m = (real_T)m1hp_cpp_P.CoreSubsys_p.Gain1_Gain *
      4.5474735088646412E-13 * (real_T)(m1hp_cpp_DW->ResettableDelay_DSTATE -
      m1hp_cpp_DW->Dk_merge);

    /* Logic: '<S5>/Logical Operator' incorporates:
     *  Constant: '<S21>/Constant'
     *  Delay: '<S6>/Resettable Delay'
     *  RelationalOperator: '<S21>/Compare'
     *  RelationalOperator: '<S22>/FixPt Relational Operator'
     *  UnitDelay: '<S22>/Delay Input1'
     *
     * Block description for '<S22>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_Compare = ((rtb_t_d_k != m1hp_cpp_DW->CoreSubsys_p[i].DelayInput1_DSTATE)
                   || (m1hp_cpp_DW->ResettableDelay_DSTATE ==
                       m1hp_cpp_P.CoreSubsys_p.CompareToConstant_const));

    /* Outputs for Triggered SubSystem: '<S5>/Triggered Subsystem' incorporates:
     *  TriggerPort: '<S23>/Trigger'
     */
    if (rtb_Compare && (m1hp_cpp_PrevZCX->CoreSubsys_p[i].
                        TriggeredSubsystem_Trig_ZCE_c != POS_ZCSIG)) {
      /* SignalConversion generated from: '<S23>/x0_in' incorporates:
       *  Memory generated from: '<S5>/Triggered Subsystem'
       */
      m1hp_cpp_DW->CoreSubsys_p[i].x0_in = m1hp_cpp_DW->CoreSubsys_p[i].
        TmpLatchAtTriggeredSubsystemInp;

      /* SignalConversion generated from: '<S23>/v0_in' incorporates:
       *  Memory generated from: '<S5>/Triggered Subsystem'
       */
      m1hp_cpp_DW->CoreSubsys_p[i].v0_in = m1hp_cpp_DW->CoreSubsys_p[i].
        TmpLatchAtTriggeredSubsystemI_e;
    }

    m1hp_cpp_PrevZCX->CoreSubsys_p[i].TriggeredSubsystem_Trig_ZCE_c =
      rtb_Compare;

    /* End of Outputs for SubSystem: '<S5>/Triggered Subsystem' */

    /* Sum: '<S5>/Add' incorporates:
     *  Gain: '<S5>/Gain'
     *  Math: '<S5>/Math Function'
     *  Product: '<S5>/Product'
     *  Product: '<S5>/Product1'
     *
     * About '<S5>/Math Function':
     *  Operator: magnitude^2
     */
    rtb_Gain1_m = (m1hp_cpp_P.CoreSubsys_p.Gain_Gain * rtb_t_d_k * (rtb_Gain1_m *
      rtb_Gain1_m) + rtb_Gain1_m * m1hp_cpp_DW->CoreSubsys_p[i].v0_in) +
      m1hp_cpp_DW->CoreSubsys_p[i].x0_in;

    /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
    m1hp_cpp_DW->CoreSubsys_p[i].DiscreteTimeIntegrator_DSTATE =
      m1hp_cpp_DW->CoreSubsys_p[i].DiscreteTimeIntegrator;

    /* Update for Memory generated from: '<S5>/Triggered Subsystem' */
    m1hp_cpp_DW->CoreSubsys_p[i].TmpLatchAtTriggeredSubsystemInp = rtb_Gain1_m;

    /* Update for Memory generated from: '<S5>/Triggered Subsystem' */
    m1hp_cpp_DW->CoreSubsys_p[i].TmpLatchAtTriggeredSubsystemI_e =
      m1hp_cpp_DW->CoreSubsys_p[i].DiscreteTimeIntegrator;

    /* Update for UnitDelay: '<S22>/Delay Input1'
     *
     * Block description for '<S22>/Delay Input1':
     *
     *  Store in Global RAM
     */
    m1hp_cpp_DW->CoreSubsys_p[i].DelayInput1_DSTATE = rtb_t_d_k;

    /* Outport: '<Root>/pos_d' incorporates:
     *  ForEachSliceAssignment generated from: '<S5>/pos_d_vec'
     */
    m1hp_cpp_Y->pos_d[i] = rtb_Gain1_m;

    /* Outport: '<Root>/vel_d' incorporates:
     *  ForEachSliceAssignment generated from: '<S5>/vel_d_vec'
     */
    m1hp_cpp_Y->vel_d[i] = m1hp_cpp_DW->CoreSubsys_p[i].DiscreteTimeIntegrator;

    /* Outport: '<Root>/acc_d' */
    m1hp_cpp_Y->acc_d[i] = rtb_t_d_k;

    /* Update for Memory generated from: '<S1>/Triggered Subsystem' incorporates:
     *  ForEachSliceAssignment generated from: '<S5>/pos_d_vec'
     */
    m1hp_cpp_DW->TmpLatchAtTriggeredSubsystemInp[i] = rtb_Gain1_m;

    /* Update for Memory generated from: '<S1>/Triggered Subsystem' incorporates:
     *  ForEachSliceAssignment generated from: '<S5>/vel_d_vec'
     */
    m1hp_cpp_DW->TmpLatchAtTriggeredSubsystemI_e[i] = m1hp_cpp_DW->
      CoreSubsys_p[i].DiscreteTimeIntegrator;
  }

  /* End of Outputs for SubSystem: '<S1>/Motion equations' */

  /* Update for Delay: '<S6>/Resettable Delay' */
  m1hp_cpp_DW->ResettableDelay_DSTATE = rtb_Add_o;
}

/* Model initialize function */
void m1hp_cpp_initialize(RT_MODEL_m1hp_cpp_T *const m1hp_cpp_M)
{
  DW_m1hp_cpp_T *m1hp_cpp_DW = m1hp_cpp_M->dwork;
  PrevZCX_m1hp_cpp_T *m1hp_cpp_PrevZCX = m1hp_cpp_M->prevZCSigState;

  {
    int32_T i;
    m1hp_cpp_PrevZCX->ResettableDelay_Reset_ZCE = POS_ZCSIG;

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay' */
    m1hp_cpp_DW->UnitDelay_DSTATE = m1hp_cpp_P.UnitDelay_InitialCondition;

    /* InitializeConditions for Delay: '<S6>/Resettable Delay' */
    m1hp_cpp_DW->ResettableDelay_DSTATE =
      m1hp_cpp_P.ResettableDelay_InitialConditio;

    /* SystemInitialize for Triggered SubSystem: '<S1>/Triggered Subsystem' */
    /* SystemInitialize for MultiPortSwitch: '<S7>/Index Vector2' incorporates:
     *  Outport: '<S7>/k_a_ac_acd'
     */
    m1hp_cpp_DW->IndexVector2 = m1hp_cpp_P.k_a_ac_acd_Y0;

    /* SystemInitialize for MultiPortSwitch: '<S7>/Index Vector1' incorporates:
     *  Outport: '<S7>/k_a_ac_acd'
     */
    m1hp_cpp_DW->IndexVector1 = m1hp_cpp_P.k_a_ac_acd_Y0;

    /* SystemInitialize for MultiPortSwitch: '<S7>/Index Vector' incorporates:
     *  Outport: '<S7>/k_a_ac_acd'
     */
    m1hp_cpp_DW->IndexVector = m1hp_cpp_P.k_a_ac_acd_Y0;

    /* SystemInitialize for Iterator SubSystem: '<S7>/Detect max t_seg' */
    for (i = 0; i < 6; i++) {
      /* InitializeConditions for Memory generated from: '<S1>/Triggered Subsystem' */
      m1hp_cpp_DW->TmpLatchAtTriggeredSubsystemInp[i] =
        m1hp_cpp_P.TmpLatchAtTriggeredSubsystemInp;

      /* InitializeConditions for Memory generated from: '<S1>/Triggered Subsystem' */
      m1hp_cpp_DW->TmpLatchAtTriggeredSubsystemI_e[i] =
        m1hp_cpp_P.TmpLatchAtTriggeredSubsystemI_j;

      /* SystemInitialize for RelationalOperator: '<S27>/Compare' incorporates:
       *  Memory generated from: '<S1>/Triggered Subsystem'
       *  Outport: '<S25>/max_bool'
       */
      m1hp_cpp_DW->Compare[i] = m1hp_cpp_P.max_bool_Y0;

      /* SystemInitialize for ForEachSliceAssignment generated from: '<S26>/a_l' incorporates:
       *  Memory generated from: '<S1>/Triggered Subsystem'
       *  Outport: '<S7>/a_l'
       */
      m1hp_cpp_DW->ImpAsg_InsertedFor_a_l_at_inpor[i] = m1hp_cpp_P.a_l_Y0;

      /* SystemInitialize for Sum: '<S7>/Add' incorporates:
       *  Memory generated from: '<S1>/Triggered Subsystem'
       *  Outport: '<S7>/Dx'
       */
      m1hp_cpp_DW->Add[i] = m1hp_cpp_P.Dx_Y0;

      /* SystemInitialize for Sum: '<S7>/Sub' incorporates:
       *  Memory generated from: '<S1>/Triggered Subsystem'
       *  Outport: '<S7>/Dv'
       */
      m1hp_cpp_DW->Sub[i] = m1hp_cpp_P.Dv_Y0;
    }

    /* End of SystemInitialize for SubSystem: '<S7>/Detect max t_seg' */
    m1hp_cpp_PrevZCX->TriggeredSubsystem_Trig_ZCE = ZERO_ZCSIG;

    /* End of SystemInitialize for SubSystem: '<S1>/Triggered Subsystem' */

    /* SystemInitialize for Iterator SubSystem: '<S1>/CPP with multi-axis coordination' */
    for (i = 0; i < 6; i++) {
      /* SystemInitialize for Merge: '<S2>/acc_merge' */
      m1hp_cpp_DW->CoreSubsys[i].acc_merge = 0.0;

      /* SystemInitialize for IfAction SubSystem: '<S2>/If Action Subsystem4' */
      m1hp_cp_IfActionSubsystem4_Init(&m1hp_cpp_DW->CoreSubsys[i].acc_merge);

      /* End of SystemInitialize for SubSystem: '<S2>/If Action Subsystem4' */

      /* SystemInitialize for IfAction SubSystem: '<S2>/If Action Subsystem5' */
      m1hp_cp_IfActionSubsystem4_Init(&m1hp_cpp_DW->CoreSubsys[i].acc_merge);

      /* End of SystemInitialize for SubSystem: '<S2>/If Action Subsystem5' */

      /* SystemInitialize for IfAction SubSystem: '<S2>/If Action Subsystem6' */
      m1hp_cp_IfActionSubsystem4_Init(&m1hp_cpp_DW->CoreSubsys[i].acc_merge);

      /* End of SystemInitialize for SubSystem: '<S2>/If Action Subsystem6' */

      /* SystemInitialize for Merge: '<S2>/acc_merge' */
      m1hp_cpp_DW->CoreSubsys[i].acc_merge =
        m1hp_cpp_P.CoreSubsys.acc_merge_InitialOutput;
    }

    /* End of SystemInitialize for SubSystem: '<S1>/CPP with multi-axis coordination' */

    /* SystemInitialize for Atomic SubSystem: '<S1>/CPP with multi-axis coordination1' */
    /* SystemInitialize for Merge: '<S3>/Dk_merge' */
    m1hp_cpp_DW->Dk_merge = m1hp_cpp_P.Dk_merge_InitialOutput;

    /* End of SystemInitialize for SubSystem: '<S1>/CPP with multi-axis coordination1' */

    /* SystemInitialize for Iterator SubSystem: '<S1>/Motion equations' */
    for (i = 0; i < 6; i++) {
      /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S5>/Constant'
       */
      m1hp_cpp_DW->CoreSubsys_p[i].DiscreteTimeIntegrator_DSTATE = m1hp_cpp_P.v0;

      /* InitializeConditions for Memory generated from: '<S5>/Triggered Subsystem' */
      m1hp_cpp_DW->CoreSubsys_p[i].TmpLatchAtTriggeredSubsystemInp =
        m1hp_cpp_P.CoreSubsys_p.TmpLatchAtTriggeredSubsystemInp;

      /* InitializeConditions for Memory generated from: '<S5>/Triggered Subsystem' */
      m1hp_cpp_DW->CoreSubsys_p[i].TmpLatchAtTriggeredSubsystemI_e =
        m1hp_cpp_P.CoreSubsys_p.TmpLatchAtTriggeredSubsystemI_j;

      /* InitializeConditions for UnitDelay: '<S22>/Delay Input1'
       *
       * Block description for '<S22>/Delay Input1':
       *
       *  Store in Global RAM
       */
      m1hp_cpp_DW->CoreSubsys_p[i].DelayInput1_DSTATE =
        m1hp_cpp_P.CoreSubsys_p.DetectChange_vinit;

      /* SystemInitialize for Triggered SubSystem: '<S5>/Triggered Subsystem' */
      /* SystemInitialize for SignalConversion generated from: '<S23>/x0_in' incorporates:
       *  Outport: '<S23>/x0'
       */
      m1hp_cpp_DW->CoreSubsys_p[i].x0_in = m1hp_cpp_P.CoreSubsys_p.x0_Y0;

      /* SystemInitialize for SignalConversion generated from: '<S23>/v0_in' incorporates:
       *  Outport: '<S23>/v0'
       */
      m1hp_cpp_DW->CoreSubsys_p[i].v0_in = m1hp_cpp_P.CoreSubsys_p.v0_Y0;

      /* End of SystemInitialize for SubSystem: '<S5>/Triggered Subsystem' */
      m1hp_cpp_PrevZCX->CoreSubsys_p[i].TriggeredSubsystem_Trig_ZCE_c =
        POS_ZCSIG;
    }

    /* End of SystemInitialize for SubSystem: '<S1>/Motion equations' */
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
