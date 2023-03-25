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
        let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("simulink_models")
            .join("m2asm_tests.mat");
        let mat = MatFile::load(path.to_str().unwrap()).unwrap();
        let preshape_bessel_step_t: Vec<f64> = mat.var("preshapeBessel_step_t").unwrap();
        let preshape_bessel_step_y: Vec<f64> = mat.var("preshapeBessel_step_y").unwrap();

        let n = preshape_bessel_step_t.len();

        let mut ctrl = AsmPreshapeFilter::new();
        ctrl.inputs.AO_cmd = 1f64;
        let mut y = vec![];
        for _ in &preshape_bessel_step_t {
            ctrl.step();
            y.push(ctrl.outputs.cmd_f);
            y.push(ctrl.outputs.cmd_f_dot);
            y.push(ctrl.outputs.cmd_f_ddot);
        }

        let y_err = (preshape_bessel_step_y
            .chunks(n)
            .take(1)
            .zip(preshape_bessel_step_y.chunks(n).skip(1).take(1))
            .zip(preshape_bessel_step_y.chunks(n).skip(2).take(1))
            .flat_map(|((x, dx), ddx)| {
                x.iter()
                    .zip(dx)
                    .zip(ddx)
                    .flat_map(|((x, dx), ddx)| vec![*x, *dx, *ddx])
            })
            .zip(&y)
            .map(|(sim_y, y)| sim_y - y)
            .map(|x| x * x)
            .sum::<f64>()
            / ((3 * n) as f64))
            .sqrt();
        assert!(dbg!(y_err) < 1e-8);
    }
}
