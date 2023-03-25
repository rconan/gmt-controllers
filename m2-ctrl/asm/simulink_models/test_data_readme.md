# Description of the test data variables

## Test data file: `m2asm_tests.mat`

`preshapeBessel_step_y` is a three column step response of the ASM pre-shape filter based on the 4th-order Bessel filter. The step response columns are the filtered AO command (`cmd_f`), its first (`cmd_f_dot`), and second (`cmd_f_ddot`) derivatives. The response time vector is `preshapeBessel_step_t`.

The first column of `asm_fb_imp_y` is the response of the ASM feedback controller (PI+D structure) to an impulse of magnitude 8000 (i.e., `1/Ts`) applied to the input `asm_FB`, while the other inputs are set to zero. The second column is the fluid damping force response to the same impulse excitation.The response time vector is `asm_fb_imp_t`.

The column vector `m2pact_fb_imp_y` is the impulse response of the M2 positioner actuator feedback controller. One should know that the impulse magnitude is `1/Ts`, i.e., 8000. The response time vector is `m2pact_fb_imp_t`.
