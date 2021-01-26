use crate::{build_controller, build_inputs, build_outputs, import_simulink};

import_simulink!(M1HPLoadCells, U : (M1_HP_D,84,M1_HP_cmd,42), Y : (M1_HP_LC,42));
build_inputs!(M1HpD, 84, M1HpCmd, 42);
build_outputs!(M1HpLc, 42);
build_controller!(M1HPLoadCells,
                  U : (M1_HP_D -> (M1HpD,m1_hp_d),
                       M1_HP_cmd -> (M1HpCmd,m1_hp_cmd) ),
                  Y : (M1_HP_LC -> (M1HpLc,m1_hp_lc))
);
