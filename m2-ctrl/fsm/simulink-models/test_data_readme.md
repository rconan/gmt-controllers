# Description of the test data variables

## Test data file: `m2fsm_tests.mat`

`pzt_135_Cfb_imp_y` is the pulse response of the FSM-PZT feedback controller for segments 1, 3, and 5. The response matrix has dimension Nx3x3, where N is the number of time instants. The corresponding time stamp vector is `pzt_135_Cfb_imp_y`. Notice that the pulse area is assumed unitary and has length Ts, where Ts is the sample time. Therefore, the pulse height is 1/Ts.

`pzt_135_Cfb_imp_y` and `pzt_135_Cfb_imp_y` are the analogous for even segments (S2-S4-S6) and S7, respectively.

The column vector `m2pact_fb_imp_y` is the impulse response of the M2 positioner actuator feedback controller. One should know that the impulse magnitude is `1/Ts`, i.e., 1000. The response time vector is `m2pact_fb_imp_t`.
