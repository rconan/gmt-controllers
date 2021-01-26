use crate::{build_controller, build_inputs, build_outputs, import_simulink};

import_simulink!(MountControl0, U : (Mount_SP,3,Mount_FB,20), Y : (Mount_cmd,3));
build_inputs!(
    SP,
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
build_outputs!(CMD, 3);
build_controller!(MountControl0,
                  U : (Mount_FB -> (OssAzDrive,oss_az_drive),
                       Mount_FB -> (OssElDrive,oss_el_drive),
                       Mount_FB -> (OssGirDrive,oss_gir_drive)),
                  Y : (Mount_cmd -> (CMD,cmd))
);
