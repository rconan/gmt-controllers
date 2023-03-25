#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(improper_ctypes)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

include!(concat!(env!("OUT_DIR"), "/controller.rs"));

#[cfg(test)]
mod tests {
    use std::time::Instant;

    use super::*;
    use matio_rs::MatFile;

    #[test]
    fn impulse() {
        let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("simulink_models")
            .join("ao_tests.mat");
        let mat = MatFile::load(path.to_str().unwrap()).unwrap();
        let ngao_imp_t: Vec<f64> = mat.var("Cngao_imp_t").unwrap();
        let ngao_imp_y: Vec<f64> = mat.var("Cngao_imp_y").unwrap();

        let n = ngao_imp_t.len();

        let now = Instant::now();
        let mut ctrl = NgaoTemporalCtrl::new();
        let mut y = vec![];
        for i in 0..n {
            ctrl.inputs.Delta_m = if i == 0 { 4000f64 } else { 0f64 };
            ctrl.step();
            y.push(ctrl.outputs.m);
        }
        println!("Elapsed time: {}nanos", now.elapsed().as_nanos());
        dbg!(&y[..10]);

        let y_err = (ngao_imp_y
            .into_iter()
            .zip(&y)
            .map(|(sim_y, y)| sim_y - *y)
            .map(|x| x * x)
            .sum::<f64>()
            / n as f64)
            .sqrt();
        assert!(dbg!(y_err) < 1e-6);
    }
}
