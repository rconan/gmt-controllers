fn main() {
    let sys = simulink_rs::Sys::new(Some("AsmPositionner"));
    sys.compile().generate_module();
}
