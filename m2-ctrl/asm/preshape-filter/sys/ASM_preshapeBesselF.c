/*
 * File: ASM_preshapeBesselF.c
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

#include "ASM_preshapeBesselF.h"
#include "ASM_preshapeBesselF_private.h"

/* Model step function */
void ASM_preshapeBesselF_step(RT_MODEL_ASM_preshapeBesselF_T *const
  ASM_preshapeBesselF_M, ExtU_ASM_preshapeBesselF_T *ASM_preshapeBesselF_U,
  ExtY_ASM_preshapeBesselF_T *ASM_preshapeBesselF_Y)
{
  DW_ASM_preshapeBesselF_T *ASM_preshapeBesselF_DW =
    ASM_preshapeBesselF_M->dwork;

  /* local block i/o variables */
  real_T rtb_SSflag_d[3];

  /* DiscreteStateSpace: '<S1>/SS flag_d' incorporates:
   *  Inport: '<Root>/AO_cmd'
   */
  {
    rtb_SSflag_d[0] = (ASM_preshapeBesselF_P.SSflag_d_C[0])*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[3];
    rtb_SSflag_d[0] += (ASM_preshapeBesselF_P.SSflag_d_D[0])*
      ASM_preshapeBesselF_U->AO_cmd;
    rtb_SSflag_d[1] = (ASM_preshapeBesselF_P.SSflag_d_C[1])*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[2];
    rtb_SSflag_d[1] += (ASM_preshapeBesselF_P.SSflag_d_D[1])*
      ASM_preshapeBesselF_U->AO_cmd;
    rtb_SSflag_d[2] = (ASM_preshapeBesselF_P.SSflag_d_C[2])*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[1];
    rtb_SSflag_d[2] += (ASM_preshapeBesselF_P.SSflag_d_D[2])*
      ASM_preshapeBesselF_U->AO_cmd;
  }

  /* Outport: '<Root>/cmd_f_ddot' */
  ASM_preshapeBesselF_Y->cmd_f_ddot = rtb_SSflag_d[2];

  /* Outport: '<Root>/cmd_f_dot' */
  ASM_preshapeBesselF_Y->cmd_f_dot = rtb_SSflag_d[1];

  /* Outport: '<Root>/cmd_f' */
  ASM_preshapeBesselF_Y->cmd_f = rtb_SSflag_d[0];

  /* Update for DiscreteStateSpace: '<S1>/SS flag_d' incorporates:
   *  Inport: '<Root>/AO_cmd'
   */
  {
    real_T xnew[4];
    xnew[0] = (ASM_preshapeBesselF_P.SSflag_d_A[0])*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[0]
      + (ASM_preshapeBesselF_P.SSflag_d_A[1])*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[1]
      + (ASM_preshapeBesselF_P.SSflag_d_A[2])*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[2]
      + (ASM_preshapeBesselF_P.SSflag_d_A[3])*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[3];
    xnew[0] += (ASM_preshapeBesselF_P.SSflag_d_B[0])*
      ASM_preshapeBesselF_U->AO_cmd;
    xnew[1] = (ASM_preshapeBesselF_P.SSflag_d_A[4])*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[0]
      + (ASM_preshapeBesselF_P.SSflag_d_A[5])*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[1]
      + (ASM_preshapeBesselF_P.SSflag_d_A[6])*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[2]
      + (ASM_preshapeBesselF_P.SSflag_d_A[7])*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[3];
    xnew[1] += (ASM_preshapeBesselF_P.SSflag_d_B[1])*
      ASM_preshapeBesselF_U->AO_cmd;
    xnew[2] = (ASM_preshapeBesselF_P.SSflag_d_A[8])*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[0]
      + (ASM_preshapeBesselF_P.SSflag_d_A[9])*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[1]
      + (ASM_preshapeBesselF_P.SSflag_d_A[10])*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[2]
      + (ASM_preshapeBesselF_P.SSflag_d_A[11])*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[3];
    xnew[2] += (ASM_preshapeBesselF_P.SSflag_d_B[2])*
      ASM_preshapeBesselF_U->AO_cmd;
    xnew[3] = (ASM_preshapeBesselF_P.SSflag_d_A[12])*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[0]
      + (ASM_preshapeBesselF_P.SSflag_d_A[13])*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[1]
      + (ASM_preshapeBesselF_P.SSflag_d_A[14])*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[2]
      + (ASM_preshapeBesselF_P.SSflag_d_A[15])*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[3];
    xnew[3] += (ASM_preshapeBesselF_P.SSflag_d_B[3])*
      ASM_preshapeBesselF_U->AO_cmd;
    (void) memcpy(&ASM_preshapeBesselF_DW->SSflag_d_DSTATE[0], xnew,
                  sizeof(real_T)*4);
  }
}

/* Model initialize function */
void ASM_preshapeBesselF_initialize(RT_MODEL_ASM_preshapeBesselF_T *const
  ASM_preshapeBesselF_M, ExtU_ASM_preshapeBesselF_T *ASM_preshapeBesselF_U,
  ExtY_ASM_preshapeBesselF_T *ASM_preshapeBesselF_Y)
{
  DW_ASM_preshapeBesselF_T *ASM_preshapeBesselF_DW =
    ASM_preshapeBesselF_M->dwork;

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)ASM_preshapeBesselF_DW, 0,
                sizeof(DW_ASM_preshapeBesselF_T));

  /* external inputs */
  ASM_preshapeBesselF_U->AO_cmd = 0.0;

  /* external outputs */
  (void) memset((void *)ASM_preshapeBesselF_Y, 0,
                sizeof(ExtY_ASM_preshapeBesselF_T));

  /* InitializeConditions for DiscreteStateSpace: '<S1>/SS flag_d' incorporates:
   *  Inport: '<Root>/AO_cmd'
   */
  ASM_preshapeBesselF_DW->SSflag_d_DSTATE[0] =
    ASM_preshapeBesselF_P.SSflag_d_InitialCondition;
  ASM_preshapeBesselF_DW->SSflag_d_DSTATE[1] =
    ASM_preshapeBesselF_P.SSflag_d_InitialCondition;
  ASM_preshapeBesselF_DW->SSflag_d_DSTATE[2] =
    ASM_preshapeBesselF_P.SSflag_d_InitialCondition;
  ASM_preshapeBesselF_DW->SSflag_d_DSTATE[3] =
    ASM_preshapeBesselF_P.SSflag_d_InitialCondition;
}

/* Model terminate function */
void ASM_preshapeBesselF_terminate(RT_MODEL_ASM_preshapeBesselF_T *const
  ASM_preshapeBesselF_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(ASM_preshapeBesselF_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
