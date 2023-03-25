//! # M1 hardpoints controller
//!
//! The control system implements the transfer function that models
//! the hardpoints dynamic behavior.
//!
//! This is imported from a Simulink model converted into C code.

#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(improper_ctypes)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

include!(concat!(env!("OUT_DIR"), "/controller.rs"));

#[cfg(test)]
mod tests {
    use super::*;
    use matio_rs::MatFile;
    #[test]
    fn step() {
        let mat = MatFile::load("hp_dyn_step_test.mat").unwrap();
        let hp_dyn_step_t: Vec<f64> = mat.var("hp_dyn_step_t").unwrap();
        let hp_dyn_step_y: Vec<f64> = mat.var("hp_dyn_step_y").unwrap();

        let mut ctrl = HardpointsDynamics::new();
        ctrl.inputs.In1.iter_mut().for_each(|x| *x = 1f64);
        let mut y = vec![];
        for _ in &hp_dyn_step_t {
            ctrl.step();
            y.extend_from_slice(ctrl.outputs.Out1.as_slice());
        }

        // dbg!(&y[y.len() - 6..]);

        let y_err = (y
            .chunks(6)
            .take(6 * 5)
            .zip(&hp_dyn_step_y)
            .map(|(y, y0)| y.iter().map(|y| *y - *y0).map(|x| x * x).sum::<f64>())
            .sum::<f64>()
            / y.len() as f64)
            .sqrt();
        dbg!(y_err);
    }
}
