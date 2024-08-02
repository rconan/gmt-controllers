/*
 * File: ert_main.c
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

#include <stddef.h>
#include <stdio.h>            /* This example main program uses printf/fflush */
#include "m1hp_cpp.h"                  /* Model header file */

static RT_MODEL_m1hp_cpp_T m1hp_cpp_M_;
static RT_MODEL_m1hp_cpp_T *const m1hp_cpp_MPtr = &m1hp_cpp_M_;/* Real-time model */
static DW_m1hp_cpp_T m1hp_cpp_DW;      /* Observable states */
static PrevZCX_m1hp_cpp_T m1hp_cpp_PrevZCX;/* Triggered events */
static ExtU_m1hp_cpp_T m1hp_cpp_U;     /* External inputs */
static ExtY_m1hp_cpp_T m1hp_cpp_Y;     /* External outputs */

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(RT_MODEL_m1hp_cpp_T *const m1hp_cpp_M);
void rt_OneStep(RT_MODEL_m1hp_cpp_T *const m1hp_cpp_M)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  m1hp_cpp_step(m1hp_cpp_M, &m1hp_cpp_U, &m1hp_cpp_Y);

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example main function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific. This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  RT_MODEL_m1hp_cpp_T *const m1hp_cpp_M = m1hp_cpp_MPtr;

  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Pack model data into RTM */
  m1hp_cpp_M->dwork = &m1hp_cpp_DW;
  m1hp_cpp_M->prevZCSigState = &m1hp_cpp_PrevZCX;

  /* Initialize model */
  m1hp_cpp_initialize(m1hp_cpp_M);

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.001 seconds (base rate of the model) here.
   * The call syntax for rt_OneStep is
   *
   *  rt_OneStep(m1hp_cpp_M);
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (1) {
    /*  Perform application tasks here */
  }

  /* The option 'Remove error status field in real-time model data structure'
   * is selected, therefore the following code does not need to execute.
   */

  /* Terminate model */
  m1hp_cpp_terminate(m1hp_cpp_M);
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
