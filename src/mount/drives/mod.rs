use crate::{build_controller, build_inputs, build_outputs, Simulink};

/// Simulink external input (U)
#[repr(C)]
#[allow(non_snake_case)]
#[derive(Debug)]
struct ExtU_MountDrives_T {
    Mount_cmd: [f64; 3],
    Mount_pos: [f64; 20],
}
/// Simulink external output (Y)
#[repr(C)]
#[allow(non_snake_case)]
#[derive(Debug)]
struct ExtY_MountDrives_T {
    Mount_F: [f64; 20],
}

extern "C" {
    fn MountDrives_initialize();
    fn MountDrives_step();
    fn MountDrives_terminate();
    static mut MountDrives_U: ExtU_MountDrives_T;
    static mut MountDrives_Y: ExtY_MountDrives_T;
}

use std::ops::{Index, IndexMut};
build_inputs!(
    CMD,
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
build_outputs!(OssAzDrive, 20, 0, OssElDrive, 20, 8, OssGirDrive, 20, 16);
build_controller!(MountDrives,
                  U : (Mount_cmd -> (CMD,cmd) ,
                       Mount_pos -> (OssAzDrive,oss_az_drive_d),
                       Mount_pos -> (OssElDrive,oss_el_drive_d),
                       Mount_pos -> (OssGirDrive,oss_gir_drive_d)),
                  Y : (Mount_F -> (OssAzDrive,oss_az_drive_f),
                       Mount_F -> (OssElDrive,oss_el_drive_f),
                       Mount_F -> (OssGirDrive,oss_gir_drive_f))
);
/*
/// Controller inputs U
#[derive(Debug)]
pub enum U<'a> {
    CMD(&'a mut [f64; 3]),
    OssAzDrive(&'a mut [f64; 20]),
    OssElDrive(&'a mut [f64; 20]),
    OssGirDrive(&'a mut [f64; 20]),
}
impl<'a> Index<usize> for U<'a> {
    type Output = f64;
    fn index(&self, index: usize) -> &Self::Output {
        match self {
            U::CMD(data) => &data[index],
            U::OssAzDrive(data) => &data[index],
            U::OssElDrive(data) => &data[index + 8],
            U::OssGirDrive(data) => &data[index + 16],
        }
    }
}
impl<'a> IndexMut<usize> for U<'a> {
    fn index_mut(&mut self, index: usize) -> &mut Self::Output {
        match self {
            U::CMD(data) => &mut data[index],
            U::OssAzDrive(data) => &mut data[index],
            U::OssElDrive(data) => &mut data[index + 8],
            U::OssGirDrive(data) => &mut data[index + 16],
        }
    }
}
/// Controller outputs Y
#[derive(Debug)]
pub enum Y<'a> {
    OssAzDrive(&'a mut [f64; 20]),
    OssElDrive(&'a mut [f64; 20]),
    OssGirDrive(&'a mut [f64; 20]),
}
impl<'a> Index<usize> for Y<'a> {
    type Output = f64;
    fn index(&self, index: usize) -> &Self::Output {
        match self {
            Y::OssAzDrive(data) => &data[index],
            Y::OssElDrive(data) => &data[index + 8],
            Y::OssGirDrive(data) => &data[index + 16],
        }
    }
}

/// Controller
pub struct Controller<'a> {
    pub cmd: U<'a>,
    pub oss_az_drive_d: U<'a>,
    pub oss_el_drive_d: U<'a>,
    pub oss_gir_drive_d: U<'a>,
    pub oss_az_drive_f: Y<'a>,
    pub oss_el_drive_f: Y<'a>,
    pub oss_gir_drive_f: Y<'a>,

}
impl<'a> Controller<'a> {
    /// Creates a new controller
    pub fn new() -> Self {
        let mut this = unsafe {
            Self {
                cmd: U::CMD(&mut MountDrives_U.Mount_cmd),
                oss_az_drive_d: U::OssAzDrive(&mut MountDrives_U.Mount_pos),
                oss_el_drive_d: U::OssElDrive(&mut MountDrives_U.Mount_pos),
                oss_gir_drive_d: U::OssGirDrive(&mut MountDrives_U.Mount_pos),
                oss_az_drive_f: Y::OssAzDrive(&mut MountDrives_Y.Mount_F),
                oss_el_drive_f: Y::OssElDrive(&mut MountDrives_Y.Mount_F),
                oss_gir_drive_f: Y::OssGirDrive(&mut MountDrives_Y.Mount_F),

            }
        };
        this.initialize();
        this
    }
}
impl<'a> Simulink for Controller<'a> {
    fn initialize(&mut self) {
        unsafe {
            MountDrives_initialize();
        }
    }
    fn step(&self) {
        unsafe {
            MountDrives_step();
        }
    }
    fn terminate(&self) {
        unsafe {
            MountDrives_terminate();
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
