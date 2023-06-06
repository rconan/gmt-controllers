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
        let mat = MatFile::load("mnt_fbC_step_test.mat").unwrap();
        let mnt_fbC_step_t: Vec<f64> = mat.var("mnt_fbC_step_t").unwrap();
        let mnt_fbC_step_y: Vec<f64> = mat.var("mnt_fbC_step_y").unwrap();

        let mut ctrl = MountController::new();
        ctrl.inputs.Mount_SP.iter_mut().for_each(|x| *x = 1f64);
        let mut y = vec![];
        for _ in &mnt_fbC_step_t {
            ctrl.step();
            y.extend_from_slice(ctrl.outputs.Mount_cmd.as_slice());
        }

        // dbg!(&y);
        let y0_channels = mnt_fbC_step_y.chunks(mnt_fbC_step_t.len());
        let y0: Vec<_> = y0_channels
            .clone()
            .take(1)
            .flat_map(|x| x.iter())
            .zip(y0_channels.clone().skip(1).take(1).flat_map(|x| x.iter()))
            .zip(y0_channels.skip(2).take(1).flat_map(|x| x.iter()))
            .flat_map(|((a, b), c)| vec![a, b, c])
            .collect();
        // dbg!(&y0);

        let y_err = (y
            .iter()
            .zip(y0.iter())
            .map(|(y, y0)| *y - *y0)
            .map(|x| x * x)
            .sum::<f64>()
            / y.len() as f64)
            .sqrt();
        assert!(dbg!(y_err) < 1e-4);
    }
}
