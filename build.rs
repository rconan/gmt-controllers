use cc;

fn main() {
    cc::Build::new()
        .file("src/mount/controller/MountControl0.c")
        .file("src/mount/controller/MountControl0_data.c")
        .file("src/mount/controller/ert_main.c")
        .compile("mount_controller");
}
