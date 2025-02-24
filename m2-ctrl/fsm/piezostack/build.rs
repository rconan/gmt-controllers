fn main() {
    let sys = simulink_rs::Sys::new(Some("FsmPiezoStack"));
    sys.compile().generate_module();
}
