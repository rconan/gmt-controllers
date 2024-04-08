use std::env;

fn main() {
    if env::var("DOCS_RS").is_ok() {
        println!("cargo:warning=DOCS_RS is set, using mount model: `MOUNT_FDR_1kHz`");
        env::set_var("MOUNT_MODEL", "MOUNT_FDR_1kHz");
    }
    let model_folder = match env::var("MOUNT_MODEL") {
        Ok(val) => match val.as_str() {
            "MOUNT_PDR_8kHz" => "sys_pdr_8k-linear",
            "MOUNT_FDR_1kHz" | "MOUNT_FDR_1kHz-az17Hz"=> "sys_fdr_1k",
            "MOUNT_FDR_8kHz" => "sys_fdr_8k",
            value => panic!("expected one of the following `MOUNT_MODEL`: `MOUNT_PDR_8kHz`, `MOUNT_FDR_1kHz`, `MOUNT_FDR_1kHz-az17Hz` or `MOUNT_FDR_8kHz`, found {value}"),
        },
        Err(e) => panic!(r"
`MOUNT_MODEL` env var is not set,
`MOUNT_MODEL` should be set to either `MOUNT_PDR_8kHz`, `MOUNT_FDR_1kHz`, `MOUNT_FDR_1kHz-az17Hz` or `MOUNT_FDR_8kHz`,
caused by {e}"),
    };

    println!("cargo:warning= Mount drives model folder: {}", model_folder);

    let sys = simulink_rs::Sys::builder()
        .name("MountDriver")
        .folder(model_folder)
        .build();

    sys.compile().generate_module();

    println!("cargo:rerun-if-env-changed=MOUNT_MODEL");
}
