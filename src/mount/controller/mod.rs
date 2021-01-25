use crate::{build_controller, build_inputs, build_outputs, Simulink};

/// Simulink external input (U)
#[repr(C)]
#[allow(non_snake_case)]
#[derive(Debug)]
struct ExtU_MountControl0_T {
    Mount_SP: [f64; 3],
    Mount_FB: [f64; 20],
}
/// Simulink external output (Y)
#[repr(C)]
#[allow(non_snake_case)]
#[derive(Debug)]
struct ExtY_MountControl0_T {
    Mount_cmd: [f64; 3],
}

extern "C" {
    fn MountControl0_initialize();
    fn MountControl0_step();
    fn MountControl0_terminate();
    static mut MountControl0_U: ExtU_MountControl0_T;
    static mut MountControl0_Y: ExtY_MountControl0_T;
}

use std::ops::{Index, IndexMut};
build_inputs!(
    SP,
    3,
    0,
    OssAzDrive,
    20,
    0,
    OssElDrive,
    20,
    8,
    OssGirDrive,
    20,
    16
);
build_outputs!(CMD, 3);
build_controller!(MountControl0,
                  U : (Mount_FB -> (OssAzDrive,oss_az_drive),
                       Mount_FB -> (OssElDrive,oss_el_drive),
                       Mount_FB -> (OssGirDrive,oss_gir_drive)),
                  Y : (Mount_cmd -> (CMD,cmd))
);
/*
/// Controller inputs U
#[derive(Debug)]
pub enum U<'a> {
    SP(&'a mut [f64; 3]),
    OssAzDrive(&'a mut [f64; 20]),
    OssElDrive(&'a mut [f64; 20]),
    OssGirDrive(&'a mut [f64; 20]),
}
impl<'a> Index<usize> for U<'a> {
    type Output = f64;
    fn index(&self, index: usize) -> &Self::Output {
        match self {
            U::SP(data) => &data[index],
            U::OssAzDrive(data) => &data[index],
            U::OssElDrive(data) => &data[index + 8],
            U::OssGirDrive(data) => &data[index + 16],
        }
    }
}
impl<'a> IndexMut<usize> for U<'a> {
    fn index_mut(&mut self, index: usize) -> &mut Self::Output {
        match self {
            U::SP(data) => &mut data[index],
            U::OssAzDrive(data) => &mut data[index],
            U::OssElDrive(data) => &mut data[index + 8],
            U::OssGirDrive(data) => &mut data[index + 16],
        }
    }
}
/// Controller outputs Y
#[derive(Debug)]
pub enum Y<'a> {
    CMD(&'a [f64; 3]),
}
impl<'a> Index<usize> for Y<'a> {
    type Output = f64;
    fn index(&self, index: usize) -> &Self::Output {
        match self {
            Y::CMD(data) => &data[index],
        }
    }
}

/// Controller
pub struct Controller<'a> {
    pub oss_az_drive: U<'a>,
    pub oss_el_drive: U<'a>,
    pub oss_gir_drive: U<'a>,
    pub cmd: Y<'a>,
}
impl<'a> Controller<'a> {
    /// Creates a new controller
    pub fn new() -> Self {
        let mut this = unsafe {
            Self {
                oss_az_drive: U::OssAzDrive(&mut MountControl0_U.Mount_FB),
                oss_el_drive: U::OssElDrive(&mut MountControl0_U.Mount_FB),
                oss_gir_drive: U::OssGirDrive(&mut MountControl0_U.Mount_FB),
                cmd: Y::CMD(&mut MountControl0_Y.Mount_cmd),
            }
        };
        this.initialize();
        this
    }
}
impl<'a> Simulink for Controller<'a> {
    fn initialize(&mut self) {
        unsafe {
            MountControl0_initialize();
        }
    }
    fn step(&self) {
        unsafe {
            MountControl0_step();
        }
    }
    fn terminate(&self) {
        unsafe {
            MountControl0_terminate();
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
