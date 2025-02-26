fn main() {
    let sys = simulink_rs::Sys::new(Some("FsmPiezoS1_3_5"));
    sys.compile().generate_module();
}
