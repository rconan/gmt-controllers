fn main() {
    let sys = simulink_rs::Sys::new(Some("AsmPidDamping"));
    sys.compile().generate_module();
}
