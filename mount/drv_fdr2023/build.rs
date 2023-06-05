fn main() {
    let sys = simulink_rs::Sys::new(Some("MountDrv"));
    sys.compile().generate_module();
}
