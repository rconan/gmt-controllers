use simulink_rs::{Parameter, Sys};

fn main() {
    let sys = Sys::builder()
        .name("HardpointsPreprocessor")
        .parameter(Parameter::new("k_cmd", "u32"))
        .build();
    sys.compile().generate_module();
}
