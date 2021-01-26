use crate::{build_controller, build_inputs, build_outputs, import_simulink};

import_simulink!(MountDrives, U : (Mount_cmd,3,Mount_pos,20), Y : (Mount_F,20));
build_inputs!(
    CMD,
    3,
    0,
    OssAzDrive,
    20,
    0,
    OssElDrive,
    20,
    8,
    OssGirDrive,
    20,
    16
);
build_outputs!(OssAzDrive, 20, 0, OssElDrive, 20, 8, OssGirDrive, 20, 16);
build_controller!(MountDrives,
                  U : (Mount_cmd -> (CMD,cmd) ,
                       Mount_pos -> (OssAzDrive,oss_az_drive_d),
                       Mount_pos -> (OssElDrive,oss_el_drive_d),
                       Mount_pos -> (OssGirDrive,oss_gir_drive_d)),
                  Y : (Mount_F -> (OssAzDrive,oss_az_drive_f),
                       Mount_F -> (OssElDrive,oss_el_drive_f),
                       Mount_F -> (OssGirDrive,oss_gir_drive_f))
);
