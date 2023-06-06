fn main() {
    let sys = simulink_rs::Sys::new(Some("MountDriver"));
    sys.compile().generate_module();
}
