#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(improper_ctypes)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

include!(concat!(env!("OUT_DIR"), "/controller.rs"));

#[cfg(test)]
mod tests {
    use super::*;
    use matio_rs::{MatFile, MatIO, MayBeInto};

    #[derive(Debug, Default, MatIO)]
    struct MountDriverTest {
        time: Vec<f64>,
        mount_drv_po: Vec<f64>,
        mount_cmd: Vec<f64>,
        mount_t: Vec<f64>,
    }

    #[test]
    fn data_based() {
        let mat_file = MatFile::load("mount_driver_test.mat").unwrap();
        let mat = mat_file.read("mount_driver").unwrap();
        let time = mat.field("time").unwrap();
        let mount_drv_po = mat.field("mount_drv_po").unwrap();
        let mount_cmd = mat.field("mount_cmd").unwrap();
        let mount_t = mat.field("mount_t").unwrap();
        let n = time.len();
        dbg!(n);

        let mut ctrl = MountDriver::new();
        ctrl.inputs.Mount_cmd.iter_mut().for_each(|x| *x = 1f64);
        let mut y = vec![];
        let mut e: f64 = 0.0;
        for ((&mount_drv_po, &mount_cmd), &mount_t) in mount_drv_po
            .iter()
            .zip(mount_cmd.iter())
            .zip(mount_t.iter())
        {
            let data: Vec<f64> = MayBeInto::maybe_into(mount_cmd).unwrap();
            ctrl.inputs
                .Mount_cmd
                .iter_mut()
                .zip(&data)
                .for_each(|(x, &data)| *x = data);
            let data: Vec<f64> = MayBeInto::maybe_into(mount_drv_po).unwrap();
            ctrl.inputs
                .Mount_drv_Po
                .iter_mut()
                .zip(&data)
                .for_each(|(x, &data)| *x = data);
            ctrl.step();
            let data: Vec<f64> = MayBeInto::maybe_into(mount_t).unwrap();
            e += data
                .iter()
                .zip(ctrl.outputs.Mount_T.as_slice())
                .map(|(x, y)| x - y)
                .map(|x| x * x)
                .sum::<f64>();
            y.extend_from_slice(ctrl.outputs.Mount_T.as_slice());
        }
        e = (e / n as f64).sqrt();
        assert!(dbg!(e) < 1e-13);

        MatFile::save("mount_drive_y.mat")
            .unwrap()
            .array("y", &y, vec![(y.len() / n) as u64, n as u64])
            .unwrap();
    }
}
