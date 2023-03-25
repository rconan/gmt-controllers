fn main() {
    let sys = simulink_rs::Sys::new(Some("HardpointsDynamics"));
    sys.compile().generate_module();
}
