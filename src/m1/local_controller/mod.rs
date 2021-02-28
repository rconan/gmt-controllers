use crate::{build_controller, build_inputs, build_outputs, import_simulink};

import_simulink!(M1LocalControl, U : (M1_HP_LC,42), Y : (M1_ACT_F,2316));
build_inputs!(M1HpLc, 42);
build_outputs!(
    M1RelFS1, 2316, 335, 0, M1RelFS2, 2316, 335, 335, M1RelFS3, 2316, 335, 670, M1RelFS4, 2316,
    335, 1005, M1RelFS5, 2316, 335, 1340, M1RelFS6, 2316, 335, 1675, M1RelFS7, 2316, 306, 2010
);
build_controller!(M1LocalControl,
                  U : (M1_HP_LC -> (M1HpLc,m1_hp_lc)),
                  Y : (M1_ACT_F -> (M1RelFS1,m1_rel_f_s1),
                       M1_ACT_F -> (M1RelFS2,m1_rel_f_s2),
                       M1_ACT_F -> (M1RelFS3,m1_rel_f_s3),
                       M1_ACT_F -> (M1RelFS4,m1_rel_f_s4),
                       M1_ACT_F -> (M1RelFS5,m1_rel_f_s5),
                       M1_ACT_F -> (M1RelFS6,m1_rel_f_s6),
                       M1_ACT_F -> (M1RelFS7,m1_rel_f_s7))
);
