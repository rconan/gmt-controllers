use gmt_controllers::mount;

fn main() {
    let mut mount = mount::Controller::new();
    mount.oss_gir_drive[0] = 1.;
    mount
        .take(30)
        .enumerate()
        .for_each(|(k, _)| println!("#{:.2}: Y: {:#?}", k, mount.cmd));
}
