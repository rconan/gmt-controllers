use crate::{build_inputs, build_outputs, build_controller, Simulink};

/// Simulink external input (U)
#[repr(C)]
#[allow(non_snake_case)]
#[derive(Debug)]
struct ExtU_M1LocalControl_T {
    M1_HP_LC: [f64; 42],
}
/// Simulink external output (Y)
#[repr(C)]
#[allow(non_snake_case)]
#[derive(Debug)]
struct ExtY_M1LocalControl_T {
    M1_ACT_F: [f64; 2316],
}

extern "C" {
    fn M1LocalControl_initialize();
    fn M1LocalControl_step();
    fn M1LocalControl_terminate();
    static mut M1LocalControl_U: ExtU_M1LocalControl_T;
    static mut M1LocalControl_Y: ExtY_M1LocalControl_T;
}

use std::ops::{Index, IndexMut};
build_inputs!(M1HpLc, 42);
build_outputs!(
    M1RelFS1, 2316, 0, M1RelFS2, 2316, 335, M1RelFS3, 2316, 670, M1RelFS4, 2316, 1005, M1RelFS5,
    2316, 1340, M1RelFS6, 2316, 1675, M1RelFS7, 2316, 2010
);
build_controller!(M1LocalControl,
                  U : (M1_HP_LC -> (M1HpLc,m1_hp_lc)),
                  Y : (M1_ACT_F -> (M1RelFS1,m1_rel_f_s1),
                       M1_ACT_F -> (M1RelFS2,m1_rel_f_s2),
                       M1_ACT_F -> (M1RelFS3,m1_rel_f_s3),
                       M1_ACT_F -> (M1RelFS4,m1_rel_f_s4),
                       M1_ACT_F -> (M1RelFS5,m1_rel_f_s5),
                       M1_ACT_F -> (M1RelFS6,m1_rel_f_s6),
                       M1_ACT_F -> (M1RelFS7,m1_rel_f_s7))
);

/*
/// Controller
pub struct Controller<'a> {
    pub m1_hp_lc: U<'a>,
    pub m1_rel_lf_s1: Y<'a>,
    pub m1_rel_lf_s2: Y<'a>,
    pub m1_rel_lf_s3: Y<'a>,
    pub m1_rel_lf_s4: Y<'a>,
    pub m1_rel_lf_s5: Y<'a>,
    pub m1_rel_lf_s6: Y<'a>,
    pub m1_rel_lf_s7: Y<'a>,
}
impl<'a> Controller<'a> {
    /// Creates a new controller
    pub fn new() -> Self {
        let mut this = unsafe {
            Self {
                m1_hp_lc: U::M1HpLc(&mut M1LocalControl_U.M1_HP_LC),
                m1_rel_f_s1: Y::M1RelFS1(&mut M1LocalControl_Y.M1_ACT_F),
                m1_rel_f_s2: Y::M1RelFS2(&mut M1LocalControl_Y.M1_ACT_F),
                m1_rel_f_s3: Y::M1RelFS3(&mut M1LocalControl_Y.M1_ACT_F),
                m1_rel_f_s4: Y::M1RelFS4(&mut M1LocalControl_Y.M1_ACT_F),
                m1_rel_f_s5: Y::M1RelFS5(&mut M1LocalControl_Y.M1_ACT_F),
                m1_rel_f_s6: Y::M1RelFS6(&mut M1LocalControl_Y.M1_ACT_F),
                m1_rel_f_s7: Y::M1RelFS7(&mut M1LocalControl_Y.M1_ACT_F),
            }
        };
        this.initialize();
        this
    }
}
impl<'a> Simulink for Controller<'a> {
    fn initialize(&mut self) {
        unsafe {
            M1LocalControl_initialize();
        }
    }
    fn step(&self) {
        unsafe {
            M1LocalControl_step();
        }
    }
    fn terminate(&self) {
        unsafe {
            M1LocalControl_terminate();
        }
    }
}
impl<'a> Drop for Controller<'a> {
    fn drop(&mut self) {
        self.terminate()
    }
}
impl<'a> Iterator for &Controller<'a> {
    type Item = ();
    fn next(&mut self) -> Option<Self::Item> {
        self.step();
        Some(())
    }
}
*/
