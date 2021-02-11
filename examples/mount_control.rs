use gmt_controllers::mount::*;
use dos::Pairing;

fn main() {
    let mut drive = drives::Controller::new();
    let mut control = controller::Controller::new();
    control.next();
    control.cmd.pair(&mut drive.cmd);
    control.oss_gir_drive[0] = 1.;
    /*
    control
        .take(30)
        .enumerate()
        .for_each(|(k, _)| println!("#{:.2}: Y: {:#?}", k, control.cmd));*/
}
