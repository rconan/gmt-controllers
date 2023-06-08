use std::env;

fn main() {
    let sys = if let Ok(_) = env::var("MOUNT_FDR_AZ17HZ") {
        println!("cargo:warning=compiling ODC mount control with 17Hz notch filter");
        simulink_rs::Sys::builder()
            .name("MountController")
            .folder("sys-az17Hz")
            .build()
    } else {
        println!("cargo:warning=compiling vanilla ODC mount control");
        simulink_rs::Sys::new(Some("MountController"))
    };
    sys.compile().generate_module();
    println!("cargo:rerun-if-env-changed=MOUNT_FDR_AZ17HZ")
}
