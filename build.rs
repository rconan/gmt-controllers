use cc;

fn main() {
    cc::Build::new()
        .file("src/mount/controller/MountControl0.c")
        .file("src/mount/controller/MountControl0_data.c")
        .file("src/mount/controller/ert_main.c")
        .compile("mount_controller");
    cc::Build::new()
        .file("src/mount/drives/MountDrives.c")
        .file("src/mount/drives/MountDrives_data.c")
        .file("src/mount/drives/ert_main.c")
        .compile("mount_drives");
}
