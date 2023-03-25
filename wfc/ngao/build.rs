fn main() {
    let sys = simulink_rs::Sys::new(Some("NgaoTemporalCtrl"));
    sys.compile().generate_module();
}
