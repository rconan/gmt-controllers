fn main() {
    let sys = simulink_rs::Sys::new(Some("CenterActuatorsController"));
    sys.compile().generate_module();
}
