/*
 * File: m1hp_cpp_private.h
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

#ifndef RTW_HEADER_m1hp_cpp_private_h_
#define RTW_HEADER_m1hp_cpp_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "m1hp_cpp_types.h"
#include "m1hp_cpp.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong/long check: insufficient preprocessor integer range. */

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

/* Imported (extern) block parameters */
extern uint32_T k_cmd;                 /* Variable: k_cmd
                                        * Referenced by: '<S26>/Constant'
                                        */
extern void m1hp_cp_IfActionSubsystem4_Init(real_T *rty_ac0);
extern void m1hp_cpp_IfActionSubsystem4(real_T *rty_ac0);

#endif                                 /* RTW_HEADER_m1hp_cpp_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
