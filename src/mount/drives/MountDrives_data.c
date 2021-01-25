/*
 * File: MountDrives_data.c
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

#include "MountDrives.h"
#include "MountDrives_private.h"

/* Constant parameters (default storage) */
const ConstP_MountDrives_T MountDrives_ConstP = {
  /* Mask Parameter: AZDTLugreFrmodel_rtw_collapsed_sub_expr_0
   * Referenced by: '<S1>/AZ DT Lugre Fr model'
   */
  {
    460275.0,
    698962.5,
    0.0002105263157894737,
    698962.5,
    0.0,
    0.29087690695550239,
    0.0,
    1.0,
    1.0
  },

  /* Mask Parameter: ELDTLugreFrmodel_rtw_collapsed_sub_expr_6
   * Referenced by: '<S1>/EL DT Lugre Fr model'
   */
  {
    507150.0,
    592278.75,
    0.00019047619047619048,
    592278.75,
    0.0,
    2.2103268988997984,
    0.0,
    1.0,
    1.0
  },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S1>/AZ enc avg + m2rad'
   *   '<S1>/AZ vel avg and m//s=>rad//s'
   *   '<S1>/convert to Az drive forces'
   */
  { -0.026335194353734329, -0.026335194353734329, -0.026335194353734329,
    -0.026335194353734329, 0.026335194353734329, 0.026335194353734329,
    0.026335194353734329, 0.026335194353734329 },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S1>/EL enc avg + m2rad'
   *   '<S1>/EL vel avg and m//s=>rad//s'
   *   '<S1>/convert to El drive forces'
   */
  { -0.024131274131274132, -0.024131274131274132, -0.024131274131274132,
    -0.024131274131274132, 0.024131274131274132, 0.024131274131274132,
    0.024131274131274132, 0.024131274131274132 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
