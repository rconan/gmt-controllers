/*
 * File: M2P_act_Cfb_data.c
 *
 * Code generated for Simulink model 'M2P_act_Cfb'.
 *
 * Model version                  : 5.53
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Feb 28 13:57:41 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M2P_act_Cfb.h"
#include "M2P_act_Cfb_private.h"

/* Block parameters (default storage) */
P_M2P_act_Cfb_T M2P_act_Cfb_P = {
  /* Variable: fc
   * Referenced by: '<S1>/m2p_om_c'
   */
  2.0,

  /* Variable: k2p_stiff
   * Referenced by: '<S1>/k2p_stiff'
   */
  1.479910125477238E+8,

  /* Expression: m2p_Cfb_d.num{1}
   * Referenced by: '<S1>/M2P_I_rolloffF'
   */
  { 3.2077152625734725E-10, 3.5229414953104777E-9, 3.5174120040656063E-9,
    3.1926348146687933E-10 },

  /* Expression: m2p_Cfb_d.den{1}
   * Referenced by: '<S1>/M2P_I_rolloffF'
   */
  { 1.0, -2.9921153371845048, 2.9842921174770662, -0.99217678029256162 },

  /* Expression: 0
   * Referenced by: '<S1>/M2P_I_rolloffF'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
