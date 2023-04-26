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
    fn impulse() {
        let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("simulink-models")
            .join("m2asm_tests.mat");
        let mat = MatFile::load(path.to_str().unwrap()).unwrap();
        let asm_fb_t: Vec<f64> = mat.var("asm_fb_imp_t").unwrap();
        let asm_fb_y: Vec<f64> = mat.var("asm_fb_imp_y").unwrap();

        let n = asm_fb_t.len();

        let sim_y: Vec<_> = asm_fb_y
            .chunks(n)
            .take(1)
            .zip(asm_fb_y.chunks(n).skip(1).take(1))
            .flat_map(|(x, dx)| x.iter().zip(dx).flat_map(|(x, dx)| vec![*x, *dx]))
            .collect();
        dbg!(&sim_y[..10]);

        let mut ctrl = AsmPidDamping::new();
        let mut y = vec![];
        for i in 0..n {
            ctrl.inputs.asm_FB = if i == 0 { 8000f64 } else { 0f64 };
            ctrl.step();
            y.push(ctrl.outputs.asm_U);
            y.push(ctrl.outputs.asm_Fd);
        }
        dbg!(&y[..10]);

        let y_err = (asm_fb_y
            .chunks(n)
            .take(1)
            .zip(asm_fb_y.chunks(n).skip(1).take(1))
            .flat_map(|(x, dx)| x.iter().zip(dx).flat_map(|(x, dx)| vec![*x, *dx]))
            .zip(&y)
            .map(|(sim_y, y)| sim_y - y)
            .map(|x| x * x)
            .sum::<f64>()
            / ((3 * n) as f64))
            .sqrt();
        assert!(dbg!(y_err) < 1e-6);
    }
}
