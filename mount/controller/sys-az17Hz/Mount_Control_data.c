/*
 * File: Mount_Control_data.c
 *
 * Code generated for Simulink model 'Mount_Control'.
 *
 * Model version                  : 9.57
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jun  6 15:34:15 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#include "Mount_Control.h"

/* Constant parameters (default storage) */
const ConstP_Mount_Control_T Mount_Control_ConstP = {
  /* Expression: blkdiag(1/4*ones(1,4),1/6*ones(1,6),1/4*ones(1,4))
   * Referenced by: '<S1>/Drv_Pos_avg'
   */
  { 0.25, 0.0, 0.0, 0.25, 0.0, 0.0, 0.25, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0,
    0.16666666666666666, 0.0, 0.0, 0.16666666666666666, 0.0, 0.0,
    0.16666666666666666, 0.0, 0.0, 0.16666666666666666, 0.0, 0.0,
    0.16666666666666666, 0.0, 0.0, 0.16666666666666666, 0.0, 0.0, 0.0, 0.25, 0.0,
    0.0, 0.25, 0.0, 0.0, 0.25, 0.0, 0.0, 0.25 },

  /* Computed Parameter: AZFBcontroller_A
   * Referenced by: '<S1>/AZ FB controller'
   */
  { 1.0000000000000002, 0.68798907507551388, -0.566420158503052,
    -0.1556715189805267, -0.022098300868146088, 0.064222328516543609,
    -0.002451668047936915, 0.015441783230564887, -0.019891076822187603,
    0.56642015850309724, 0.028905084630432731, 0.311136155527609,
    0.036169485252089989, -0.11921949160223735, 0.0046772377671537354,
    -0.027936137571800357, 0.036463924593529207, 0.15567151898050605,
    0.31113615552761964, 0.77682640839316264, -0.25213233810007091,
    0.0818382728532781, -0.0014953232238066655, 0.026173227636866914,
    -0.027828567022993467, -0.022098300868143628, -0.036169485252086922,
    0.2521323381000683, 0.95610582151302037, 0.045655812025168593,
    -0.002099394811438466, 0.0079001699667807235, -0.011329890078879967,
    -0.064222328516535351, -0.11921949160224088, 0.081838272853279478,
    -0.045655812025167351, 0.93336374586498039, -0.13885529284152037,
    -0.0426349881948922, 0.022791934818365112, -0.0024516680479331658,
    -0.0046772377671488122, 0.0014953232238028857, -0.0020993948114376758,
    0.13885529284152334, 0.989960845575675, -0.0037534266871958044,
    0.0033371657340179328, 0.0154417832305623, 0.027936137571799208,
    -0.026173227636867875, 0.00790016996678025, 0.042634988194892837,
    -0.0037534266871969745, 0.987443290499344, 0.097226026169634466,
    0.019891076822185737, 0.036463924593530449, -0.027828567022993227,
    0.01132989007888013, 0.0227919348183637, -0.0033371657340203276,
    -0.097226026169634272, 0.98011327805556592 },

  /* Computed Parameter: AZFBcontroller_C
   * Referenced by: '<S1>/AZ FB controller'
   */
  { -1987.5342910666045, -144726.67159109403, -254031.77036636398,
    106507.34103701002, -24412.769492981453, -22584.721511478703,
    1869.7081539497158, -61.057466209866107, 4156.7449678231787 },

  /* Computed Parameter: ELFBcontroller_A
   * Referenced by: '<S1>/EL FB controller'
   */
  { 1.0, 0.65496918541435867, -0.60074950581241271, 0.13468738925063448,
    0.040821429497078073, -0.025372034031179644, -0.0075488245697775827,
    -0.012376316165354093, 0.0065926614588878623, -0.023930602524424093,
    -0.013750059825748225, -0.0026862512302864242, -0.0057634188930479188,
    0.60074950581240982, 0.081119943645124093, -0.4072369041837362,
    -0.05357094061503951, 0.055802598173376294, 0.011455842038014872,
    0.020953028895133813, -0.0129891384486882, 0.042299890776905325,
    0.028994816531085588, 0.0051692820789191463, 0.010703940742989236,
    -0.13468738925063642, -0.40723690418373476, 0.56163576779800273,
    -0.29910849902440934, 0.064110866352819429, 0.037949580844117814,
    0.05189715314304981, -0.020634535625646048, 0.091954912151505669,
    0.035607203331308325, 0.0085678773647251179, 0.019734205042678334,
    0.040821429497080383, 0.053570940615036949, 0.29910849902440656,
    0.889227987574227, 0.15185438841226961, 0.0095778719661372379,
    0.02399587064370267, -0.020500443419291827, 0.051202098869228781,
    0.048941101404242411, 0.0069726468051134671, 0.013354580033805954,
    0.025372034031180064, 0.055802598173375316, 0.064110866352817666,
    -0.15185438841226997, 0.94856715803054592, -0.13380619192940008,
    -0.0685033206198716, 0.013180873405420705, -0.08656428114074402,
    -0.0084258480396454082, -0.004599776436226422, -0.012353575606637137,
    -0.007548824569776554, -0.011455842038015265, -0.03794958084411882,
    0.0095778719661355916, 0.1338061919294, 0.98588593225412213,
    -0.012707538317002906, 0.012567166756875373, -0.023211738131960653,
    -0.027023290354756351, -0.0028963377189311452, -0.0051780636619747078,
    -0.012376316165353569, -0.020953028895133417, -0.051897153143050462,
    0.023995870643702257, 0.068503320619871841, -0.012707538317002777,
    0.98343520015813246, 0.0456849445982356, -0.033704284996745444,
    -0.0726080568908291, -0.0049354903301892152, -0.0074992982115931152,
    -0.0065926614588874321, -0.01298913844869151, -0.020634535625651554,
    0.020500443419293204, 0.013180873405424592, -0.012567166756876922,
    -0.045684944598237257, 0.97958005464415421, 0.18239633750775136,
    -0.026255328526819052, 0.00068633358440620173, 0.0037500549253366195,
    -0.023930602524424312, -0.04229989077690581, -0.091954912151505461,
    0.051202098869227712, 0.086564281140744853, -0.023211738131960591,
    -0.033704284996745715, -0.18239633750775425, 0.86516809169509468,
    -0.36437621459928343, -0.011173392615441369, -0.013641528018767612,
    0.013750059825750111, 0.028994816531084544, 0.0356072033313056,
    -0.048941101404242043, -0.0084258480396440516, 0.027023290354757756,
    0.072608056890829359, -0.026255328526808536, 0.36437621459928504,
    0.88949504187353923, -0.011055880308045607, -0.03159397296366373,
    0.0026862512302849237, 0.0051692820789200136, 0.0085678773647255083,
    -0.0069726468051145712, -0.0045997764362252225, 0.002896337718931951,
    0.0049354903301907366, 0.00068633358440695069, 0.011173392615441459,
    -0.011055880308043609, 0.99534714876920738, -0.062784971825117442,
    -0.0057634188930488451, -0.010703940742991025, -0.019734205042678171,
    0.013354580033804575, 0.012353575606636996, -0.0051780636619755405,
    -0.0074992982115924534, -0.0037500549253367543, -0.013641528018766252,
    0.031593972963663841, 0.06278497182511783, 0.97995053094494577 },

  /* Computed Parameter: ELFBcontroller_C
   * Referenced by: '<S1>/EL FB controller'
   */
  { -11339.118049356122, 158958.407864214, 207613.02018133955,
    94563.612178621363, -13922.840975504578, -8312.8434290332189,
    1398.109600464406, 614.70518367987825, 1081.3507908089377,
    -213.98780147377011, -3742.8506721860358, -355.1089257425192,
    -463.1830445973319 },

  /* Computed Parameter: GIRFBcontroller_A
   * Referenced by: '<S1>/GIR FB controller'
   */
  { 1.0, 0.72275751252276, 0.57588065182005521, 0.10905347694037149,
    0.023196681481862158, -0.067778038308505373, -0.0019953453507656205,
    -0.5758806518200672, 0.2093553848114888, 0.37076601528712183,
    0.029709899848121887, -0.13815185534905192, -0.0019670608258781641,
    -0.10905347694036371, 0.37076601528712716, 0.69611392392210369,
    -0.20742055881452448, 0.12066800276111805, 0.0072506107711204359,
    0.023196681481860437, -0.029709899848123271, 0.20742055881452565,
    0.969378396962444, 0.03421938175511835, -0.00024647898174099542,
    0.067778038308502556, -0.13815185534905286, 0.12066800276111758,
    -0.034219381755118863, 0.81152904838496953, -0.43410968297494318,
    -0.0019953453507651764, 0.0019670608258781294, -0.007250610771120658,
    -0.00024647898174110644, 0.43410968297494357, 0.89035433181012935 },

  /* Computed Parameter: GIRFBcontroller_C
   * Referenced by: '<S1>/GIR FB controller'
   */
  { -652.242698370315, 17028.864555103337, -31350.698316730435,
    22397.605203121435, -4262.3175327026283, -3887.2197360677746,
    1086.8945536880692 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */