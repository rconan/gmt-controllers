fn main() {
    let sys = simulink_rs::Sys::new(Some("OuterActuatorsController"));
    sys.compile().generate_module();
}
