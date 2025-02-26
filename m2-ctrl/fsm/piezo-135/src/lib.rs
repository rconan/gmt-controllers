#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(improper_ctypes)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

include!(concat!(env!("OUT_DIR"), "/controller.rs"));

#[cfg(test)]
mod tests {
    use std::f64::EPSILON;

    use super::*;
    use matio_rs::MatFile;

    #[test]
    fn impulse() {
        let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("simulink-models")
            .join("m2fsm_tests.mat");
        let mat = MatFile::load(path.to_str().unwrap()).unwrap();
        let pzt_135_Cfb_imp_t: Vec<f64> = mat.var("pzt_135_Cfb_imp_t").unwrap();
        let pzt_135_Cfb_imp_y: Vec<f64> = mat.var("pzt_135_Cfb_imp_y").unwrap();

        let n = pzt_135_Cfb_imp_t.len();

        let sim_y: Vec<_> = pzt_135_Cfb_imp_y.chunks(n).take(1).flatten().collect();
        dbg!(&sim_y[..10]);

        let mut ctrl = FsmPiezo135::new();
        let mut y = vec![];
        for i in 0..n {
            ctrl.inputs
                .pzt_error
                .iter_mut()
                .take(1)
                .for_each(|e| *e = if i == 0 { 1000f64 } else { 0f64 });
            ctrl.step();
            y.push(ctrl.outputs.pzt_control[0]);
        }
        dbg!(&y[..10]);

        let n = sim_y.len();
        let y_err = (sim_y
            .into_iter()
            .zip(&y)
            .map(|(sim_y, y)| 1. - y / sim_y)
            .map(|x| x * x)
            .sum::<f64>()
            / (n as f64))
            .sqrt();
        assert!(dbg!(y_err) < EPSILON * 1e3);
    }
}
