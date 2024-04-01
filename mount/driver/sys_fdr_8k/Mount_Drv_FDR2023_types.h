/*
 * File: Mount_Drv_FDR2023_types.h
 *
 * Code generated for Simulink model 'Mount_Drv_FDR2023'.
 *
 * Model version                  : 9.78
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Apr  1 12:53:27 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#ifndef RTW_HEADER_Mount_Drv_FDR2023_types_h_
#define RTW_HEADER_Mount_Drv_FDR2023_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_nCCRV1WYsk4qHftu9RVOGH_
#define DEFINED_TYPEDEF_FOR_struct_nCCRV1WYsk4qHftu9RVOGH_

typedef struct {
  real_T Pos[261];
  real_T TorqueRate[261];
} struct_nCCRV1WYsk4qHftu9RVOGH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_duUQaQNHHqhv4wG70LBFjE_
#define DEFINED_TYPEDEF_FOR_struct_duUQaQNHHqhv4wG70LBFjE_

typedef struct {
  struct_nCCRV1WYsk4qHftu9RVOGH oInterp;
  real_T maxPos;
  real_T factAxial;
  real_T PhaseShift_deg[4];
} struct_duUQaQNHHqhv4wG70LBFjE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_zMKSlyEOulYf7sVCIoXNRD_
#define DEFINED_TYPEDEF_FOR_struct_zMKSlyEOulYf7sVCIoXNRD_

typedef struct {
  real_T Pos[521];
  real_T TorqueRate[521];
} struct_zMKSlyEOulYf7sVCIoXNRD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ukHSzDyaJtu8G4Ivne33HB_
#define DEFINED_TYPEDEF_FOR_struct_ukHSzDyaJtu8G4Ivne33HB_

typedef struct {
  struct_zMKSlyEOulYf7sVCIoXNRD oInterp;
  real_T maxPos;
  real_T factAxial;
  real_T PhaseShift_deg[4];
} struct_ukHSzDyaJtu8G4Ivne33HB;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_Mount_Drv_FDR2023_T RT_MODEL_Mount_Drv_FDR2023_T;

#endif                               /* RTW_HEADER_Mount_Drv_FDR2023_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
