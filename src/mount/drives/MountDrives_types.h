/*
 * File: MountDrives_types.h
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

#ifndef RTW_HEADER_MountDrives_types_h_
#define RTW_HEADER_MountDrives_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_kxIwWES1orY88dAgmfLm1E_
#define DEFINED_TYPEDEF_FOR_struct_kxIwWES1orY88dAgmfLm1E_

typedef struct {
  real_T sigmv;
  real_T Tc;
  real_T vs;
  real_T Ts;
  real_T sigm0;
  real_T zfr;
  real_T sigm1;
  real_T iIsSig01Active;
  real_T iIsActive;
} struct_kxIwWES1orY88dAgmfLm1E;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Io4x7ySdlOLKH9IQzqvteF_
#define DEFINED_TYPEDEF_FOR_struct_Io4x7ySdlOLKH9IQzqvteF_

typedef struct {
  real_T sfr;
  real_T amp;
} struct_Io4x7ySdlOLKH9IQzqvteF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_xNUiBaTweEDVaLcXKH5F9_
#define DEFINED_TYPEDEF_FOR_struct_xNUiBaTweEDVaLcXKH5F9_

typedef struct {
  real_T sfr;
  real_T ampFact;
} struct_xNUiBaTweEDVaLcXKH5F9;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_JgSJuDCEIHPaBH2xw0DhqC_
#define DEFINED_TYPEDEF_FOR_struct_JgSJuDCEIHPaBH2xw0DhqC_

typedef struct {
  struct_Io4x7ySdlOLKH9IQzqvteF oCog;
  struct_xNUiBaTweEDVaLcXKH5F9 oRip;
} struct_JgSJuDCEIHPaBH2xw0DhqC;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_MountDrives_T RT_MODEL_MountDrives_T;

#endif                                 /* RTW_HEADER_MountDrives_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
