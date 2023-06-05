fn main() {
    let sys = simulink_rs::Sys::new(Some("MountFfPid"));
    sys.compile().generate_module();
}
