fn main() {
    let sys = simulink_rs::Sys::new(Some("AsmPreshapeFilter"));
    sys.compile().generate_module();
}
