use std::env;

fn main() {
    if env::var("DOCS_RS").is_ok() {
        println!("cargo:warning=DOCS_RS is set, using mount model: `MOUNT_FDR_1kHz`");
        env::set_var("MOUNT_MODEL", "MOUNT_FDR_1kHz");
    }
    let model_folder = match env::var("MOUNT_MODEL") {
        Ok(val) => match val.as_str() {
            "MOUNT_PDR_8kHz" => "sys_pdr_za30_8k",
            "MOUNT_FDR_1kHz" => "sys_fdr_1k",
            "MOUNT_FDR_8kHz" => "sys_fdr_8k",
            "MOUNT_FDR_1kHz-az17Hz" => "sys_fdr_1k-az17Hz",
            value => panic!("expected one of the following `MOUNT_MODEL`: `MOUNT_PDR_8kHz`, `MOUNT_FDR_1kHz` or `MOUNT_FDR_1kHz-az17Hz`, found {value}"),
        },
        Err(e) => panic!(r"
`MOUNT_MODEL` env var is not set,
`MOUNT_MODEL` should be set to either `MOUNT_PDR_8kHz`, `MOUNT_FDR_1kHz`, `MOUNT_FDR_8kHz` or `MOUNT_FDR_1kHz-az17Hz`,
caused by {e}"),    };

    println!(
        "cargo:warning= Mount controller model folder: {}",
        model_folder
    );

    let sys = simulink_rs::Sys::builder()
        .name("MountController")
        .folder(model_folder)
        .build();

    sys.compile().generate_module();

    println!("cargo:rerun-if-env-changed=MOUNT_MODEL");
}
