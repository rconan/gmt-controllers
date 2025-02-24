fn main() {
    let sys = simulink_rs::Sys::new(Some("FsmPositionner"));
    sys.compile().generate_module();
}
