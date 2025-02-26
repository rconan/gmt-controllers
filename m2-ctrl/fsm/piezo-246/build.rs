fn main() {
    let sys = simulink_rs::Sys::new(Some("FsmPiezo246"));
    sys.compile().generate_module();
}
