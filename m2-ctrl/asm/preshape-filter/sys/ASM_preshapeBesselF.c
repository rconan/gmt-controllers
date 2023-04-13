/*
 * File: ASM_preshapeBesselF.c
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

#include "ASM_preshapeBesselF.h"
#include "rtwtypes.h"

/* Model step function */
void ASM_preshapeBesselF_step(RT_MODEL_ASM_preshapeBesselF_T *const
  ASM_preshapeBesselF_M, real_T ASM_preshapeBesselF_U_AO_cmd, real_T
  *ASM_preshapeBesselF_Y_cmd_f_ddot, real_T *ASM_preshapeBesselF_Y_cmd_f_dot,
  real_T *ASM_preshapeBesselF_Y_cmd_f)
{
  DW_ASM_preshapeBesselF_T *ASM_preshapeBesselF_DW =
    ASM_preshapeBesselF_M->dwork;

  /* local block i/o variables */
  real_T rtb_SSflag_d[3];

  /* DiscreteStateSpace: '<S1>/SS flag_d' incorporates:
   *  Inport: '<Root>/AO_cmd'
   */
  {
    rtb_SSflag_d[0] = (64.854543862967589)*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[3];
    rtb_SSflag_d[0] += (0.02967202116338219)*ASM_preshapeBesselF_U_AO_cmd;
    rtb_SSflag_d[1] = (531288.42332543049)*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[2];
    rtb_SSflag_d[1] += (966.12498421264081)*ASM_preshapeBesselF_U_AO_cmd;
    rtb_SSflag_d[2] = (8.7046295277638531E+9)*
      ASM_preshapeBesselF_DW->SSflag_d_DSTATE[1];
    rtb_SSflag_d[2] += (2.193858624795932E+7)*ASM_preshapeBesselF_U_AO_cmd;
  }

  /* Outport: '<Root>/cmd_f_ddot' */
  *ASM_preshapeBesselF_Y_cmd_f_ddot = rtb_SSflag_d[2];

  /* Outport: '<Root>/cmd_f_dot' */
  *ASM_preshapeBesselF_Y_cmd_f_dot = rtb_SSflag_d[1];

  /* Outport: '<Root>/cmd_f' */
  *ASM_preshapeBesselF_Y_cmd_f = rtb_SSflag_d[0];

  /* Update for DiscreteStateSpace: '<S1>/SS flag_d' incorporates:
   *  Inport: '<Root>/AO_cmd'
   */
  {
    real_T xnew[4];
    xnew[0] = (-0.19681414194734359)*ASM_preshapeBesselF_DW->SSflag_d_DSTATE[0]
      + (-0.14259315154461696)*ASM_preshapeBesselF_DW->SSflag_d_DSTATE[1]
      + (0.040453300816057164)*ASM_preshapeBesselF_DW->SSflag_d_DSTATE[2]
      + (0.051638401896805804)*ASM_preshapeBesselF_DW->SSflag_d_DSTATE[3];
    xnew[0] += (-0.0020947948356031219)*ASM_preshapeBesselF_U_AO_cmd;
    xnew[1] = (-0.20383199230440782)*ASM_preshapeBesselF_DW->SSflag_d_DSTATE[0]
      + (-0.46542752046735508)*ASM_preshapeBesselF_DW->SSflag_d_DSTATE[1]
      + (-0.60377138667380037)*ASM_preshapeBesselF_DW->SSflag_d_DSTATE[2]
      + (-0.23003467850294718)*ASM_preshapeBesselF_DW->SSflag_d_DSTATE[3];
    xnew[1] += (-0.0015261217100169221)*ASM_preshapeBesselF_U_AO_cmd;
    xnew[2] = (0.45400733849259595)*ASM_preshapeBesselF_DW->SSflag_d_DSTATE[0]
      + (0.4963828463732019)*ASM_preshapeBesselF_DW->SSflag_d_DSTATE[1]
      + (0.24417632653651067)*ASM_preshapeBesselF_DW->SSflag_d_DSTATE[2]
      + (-0.33475625988707469)*ASM_preshapeBesselF_DW->SSflag_d_DSTATE[3];
    xnew[2] += (0.005278256919681569)*ASM_preshapeBesselF_U_AO_cmd;
    xnew[3] = (0.33034540614518554)*ASM_preshapeBesselF_DW->SSflag_d_DSTATE[0]
      + (0.5488368113362464)*ASM_preshapeBesselF_DW->SSflag_d_DSTATE[1]
      + (0.7645142910481324)*ASM_preshapeBesselF_DW->SSflag_d_DSTATE[2]
      + (0.87923437697342)*ASM_preshapeBesselF_DW->SSflag_d_DSTATE[3];
    xnew[3] += (0.0048663990653113253)*ASM_preshapeBesselF_U_AO_cmd;
    (void) memcpy(&ASM_preshapeBesselF_DW->SSflag_d_DSTATE[0], xnew,
                  sizeof(real_T)*4);
  }
}

/* Model initialize function */
void ASM_preshapeBesselF_initialize(RT_MODEL_ASM_preshapeBesselF_T *const
  ASM_preshapeBesselF_M)
{
  /* (no initialization code required) */
  UNUSED_PARAMETER(ASM_preshapeBesselF_M);
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
