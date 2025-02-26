fn main() {
    let sys = simulink_rs::Sys::new(Some("FsmPiezo7"));
    sys.compile().generate_module();
}
