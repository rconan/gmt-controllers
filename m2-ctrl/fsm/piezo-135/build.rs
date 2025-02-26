fn main() {
    let sys = simulink_rs::Sys::new(Some("FsmPiezo135"));
    sys.compile().generate_module();
}
