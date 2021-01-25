use crate::{build_controller, build_inputs, build_outputs, Simulink};

/// Simulink external input (U)
#[repr(C)]
#[allow(non_snake_case)]
#[derive(Debug)]
struct ExtU_M1HPLoadCells_T {
    M1_HP_D: [f64; 84],
    M1_HP_cmd: [f64; 42],
}
/// Simulink external output (Y)
#[repr(C)]
#[allow(non_snake_case)]
#[derive(Debug)]
struct ExtY_M1HPLoadCells_T {
    M1_HP_LC: [f64; 42],
}

extern "C" {
    fn M1HPLoadCells_initialize();
    fn M1HPLoadCells_step();
    fn M1HPLoadCells_terminate();
    static mut M1HPLoadCells_U: ExtU_M1HPLoadCells_T;
    static mut M1HPLoadCells_Y: ExtY_M1HPLoadCells_T;
}

use std::ops::{Index, IndexMut};
build_inputs!(M1HpD, 84, M1HpCmd, 42);
build_outputs!(M1HpLc, 42);
build_controller!(M1HPLoadCells,
                  U : (M1_HP_D -> (M1HpD,m1_hp_d), M1_HP_cmd -> (M1HpCmd,m1_hp_cmd) ),
                  Y : (M1_HP_LC -> (M1HpLc,m1_hp_lc))
);

/*
/// Controller
pub struct Controller<'a> {
    pub m1_hp_d: U<'a>,
    pub m1_hp_cmd: U<'a>,
    pub m1_hp_lc: Y<'a>,
}
impl<'a> Controller<'a> {
    /// Creates a new controller
    pub fn new() -> Self {
        let mut this = unsafe {
            Self {
                m1_hp_d: U::M1HpD(&mut M1HPLoadCells_U.M1_HP_D),
                m1_hp_cmd: U::M1HpCmd(&mut M1HPLoadCells_U.M1_HP_cmd),
                m1_hp_lc: Y::M1HpLc(&mut M1HPLoadCells_Y.M1_HP_LC),
            }
        };
        this.initialize();
        this
    }
}
impl<'a> Simulink for Controller<'a> {
    fn initialize(&mut self) {
        unsafe {
            M1HPLoadCells_initialize();
        }
    }
    fn step(&self) {
        unsafe {
            M1HPLoadCells_step();
        }
    }
    fn terminate(&self) {
        unsafe {
            M1HPLoadCells_terminate();
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
