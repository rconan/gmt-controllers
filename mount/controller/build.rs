fn main() {
    let sys = simulink_rs::Sys::new(Some("MountController"));
    sys.compile().generate_module();
}
