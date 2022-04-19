const ISP_NVRAM_LCE_TUNING_PARAM_T imx519mipiraw_LCE_%04d = {
    .rAutoLCEParam = {
        .rLCEBasic = {

            {  30,  50,  80, 120 },  // base strength LV (base10)
            { 230, 250, 315, 315 },  // dark strength base ratio
            { 400, 400, 475, 475 },  // bright strength base ratio

           //  LV0    LV1    LV2    LV3    LV4    LV5    LV6    LV7    LV8    LV9   LV10   LV11   LV12   LV13   LV14   LV15   LV16   LV17   LV18
            { 1450,  1600,  1650,  1700,  2100,  2100,  2100,  2100,  2100,  2100,  2100,  2150,  2150,  2150,  2150,  2150,  2150,  2150,  2150 }, // LVTarget
            {  200,   240,   350,   430,   450,   450,   450,   450,   450,   512,   512,   512,   512,   512,   512,   512,   512,   512,   512 }, // MaxLceGain
            { 2100,  2200,  2300,  2400,  2500,  2600,  2600,  2600,  2600,  2600,  2600,  2600,  2600,  2600,  2600,  2600,  2600,  2600,  2600 }  // MaxFinalTarget
        },

        .rLCEStats = {
            20,     //HistCCLB
            1600,   //HistCCUB
            500,    //GCEratio
            1000,   //i4TCPLB
            20000,  //I4TCPUB
            0,      //Reserve
            20,     //i4DetailRangeRatio --> base 1000
            64,     //i4CenSlopeMin

            600,    //DR_Low_Y_Ratio
            800,    //DR_High_Y_Ratio
            1,      //DR_CompEnable
            800,    //DR_Comp_Y_High_Ratio
            2000,   //DR_Diff_Maximum
            1000,   //DR_Diff_Minimum
            500,    //DR_Flat_Ratio_High_Bound

            1,      //multi-slope enable
            32,     //SlopePoint0
            64,     //SlopePoint1
            128,    //SlopePoint2
            256,    //SlopePoint3
            512,    //SlopePoint4
            51,     //SlopeLow (256 base)

            1536,  //SlopeHigh0 (256 base)
            1536,  //SlopeHigh1
            1536,  //SlopeHigh2
            1280,  //SlopeHigh3
            1024,  //SlopeHigh4

            500,  //dr base
            1,    //lcesho enable
            0,    //lcesho mode (0: 8dir, 1: 4dir)

            0,   //reserve0
            0,   //reserve1
            0,   //reserve2
            0,   //reserve3
            0,   //reserve4
            0,   //reserve5
            0,   //reserve6
            0,   //reserve7

        },

        .rLCELUTs = {//i4LCETbl

            {//  /*                                                Dark    Strength                                               */
             //   LV0   LV1   LV2   LV3   LV4   LV5   LV6   LV7   LV8   LV9   LV10  LV11  LV12  LV13  LV14  LV15  LV16  LV17  LV18
                { 200,  256,  256,  256,  256,  256,  256,  256,  256,  256,  320,  320,  320,  320,  320,  320,  320,  320,  320 },   //  0 DR index
                { 256,  256,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384 },   //  1
                { 384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384 },   //  2
                { 448,  448,  448,  448,  448,  448,  448,  448,  448,  448,  448,  448,  448,  448,  448,  448,  448,  448,  448 },   //  3
                { 448,  448,  448,  448,  448,  448,  448,  448,  448,  448,  512,  512,  512,  512,  512,  512,  512,  512,  512 },   //  4
                { 448,  448,  448,  448,  448,  448,  448,  448,  448,  448,  512,  512,  512,  512,  512,  512,  512,  512,  512 },   //  5
                { 448,  448,  448,  448,  448,  448,  448,  448,  448,  448,  512,  512,  512,  512,  512,  512,  512,  512,  512 },   //  6
                { 448,  448,  448,  448,  448,  448,  448,  448,  448,  448,  512,  512,  512,  512,  512,  512,  512,  512,  512 },   //  7
                { 512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  576,  512,  512,  512,  512,  512,  512,  512,  512 },   //  8
                { 512,  512,  512,  512,  512,  512,  512,  576,  576,  576,  576,  512,  512,  512,  512,  512,  512,  512,  512 },   //  9
                { 512,  512,  512,  512,  512,  512,  512,  576,  576,  576,  576,  512,  512,  512,  512,  512,  512,  512,  512 }    // 10
            },

            {//  /*                                                Bright    Strength                                               */
             //   LV0   LV1   LV2   LV3   LV4   LV5   LV6   LV7   LV8   LV9   LV10  LV11  LV12  LV13  LV14  LV15  LV16  LV17  LV18
                { 128,  128,  128,  128,  128,  128,  128,  128,  128,  128,  128,  128,  128,  128,  128,  128,  128,  128,  128 },   //  0 DR index
                { 256,  256,  256,  256,  256,  256,  256,  256,  256,  256,  256,  256,  256,  256,  256,  256,  256,  256,  256 },   //  1
                { 384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384,  384 },   //  2
                { 512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512 },   //  3
                { 512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512 },   //  4
                { 512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512 },   //  5
                { 512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512 },   //  6
                { 512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512 },   //  7
                { 512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512 },   //  8
                { 512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512 },   //  9
                { 512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512,  512 }    // 10
            },

            { //i4CenSlopeEnhance
              //  0   1   2   3   4   5   6   7   8   9   10   11
                  0,  3,  5, 10, 12, 16, 12, 10,  5,  3,   0,   0
            }

        },

        .rLCEPara = {
            5,    // FlatAreaPercentage
            400,  // FlatRatioTH
            0,    // dark sky protection enable
            300,  // dark sky percentage
            1700, // dark y low bound
            2000, // dark y high bound
            30,   // dark sky lv low bound
            60,   // dark sky lv high bound
            0,   //reserve
            0,   //reserve
            0,   //reserve
            0,   //reserve
            0,   //reserve
            0,   //reserve
            0,   //reserve
            0,   //reserve
            0,   //reserve
            0,   //reserve

            //{//  LV0    LV1    LV2    LV3    LV4    LV5    LV6    LV7    LV8    LV9   LV10   LV11   LV12   LV13   LV14   LV15   LV16   LV17   LV18
                {   50,    50,    50,    50,    50,    50,    60,    60,    70,    90,   100,   110,   110,   110,   110,   110,   120,   130,   140 }, // 0 LVBriRatio
                {  170,   140,   140,   387,   387,   387,   485,   542,   542,   679,   679,   679,   679,   679,   679,   679,   679,   679,   679 }, // 1 LVBriLimit
                {  141,   141,   141,   141,   141,   141,   141,   141,   141,   141,   141,   141,   141,   141,   141,   141,   141,   141,   141 }, // 2 FlatLumaLoBound
                {  679,   679,   679,   679,   679,   679,   679,   679,   679,   679,   679,   679,   679,   679,   679,   679,   679,   679,   679 }, // 3 FlatLumaHiBound
                {    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0 }, // 4 i4LCEParaTbl0
                {    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0 }, // 5 i4LCEParaTbl1
                {    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0 }, // 6 i4LCEParaTbl2
                {    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0 } // 7 i4LCEParaTbl3
            //}
        },

        .rFaceLCE = {    //i4FaceLCEPara
            1,    //LCE_FD_Enable
            128,  //LoBoundGainRatio
            128,  //HiBoundGainRatio
            1600, //DarkFaceLimit
            3000, //FrontLightTH_L
            3360, //FrontLightTH_H
            1,    //face multi-slope enable // Face SlopeCtrl Enable
            1536, //SlopeHigh0      -> 6*256 normal max
            1536, //SlopeHigh1
            1536, //SlopeHigh2
            1280, //SlopeHigh3
            1024, //SlopeHigh4
            102,  //SlopeLow        -> 0.4*256 normal min
            512,  //FaceSlopeHigh   -> 2.0*256 face max
            205,  //FaceSlopeLow    -> 0.8*256 face min
            500,  //FaceSlopIntpRat -> 1000 based slope intp ratio
            800,  //Dark face range
            71,   //FDWidthCropRat
            70,   //FDHeightCropRat
             0,   //reserve0
             0,   //reserve1
             0,   //reserve2
             0,   //reserve3
             0,   //reserve4
             0,   //reserve5
             0,   //reserve6
             0,   //reserve7
             0,   //reserve8
             0,   //reserve9
                  //LV0  LV2   LV4   LV6   LV8   LV10  LV12  LV14  LV16   LV0  LV2   LV4   LV6   LV8   LV10  LV12  LV14  LV16  rsv
            {        0,    0,    0,    0,    0,    0,    0,    0,    0,  105,  105,  105,  105,  105,  105,  105,  105,  105,    0 },   //  i4LCEfaceTbl0  // Bright blend ratio, 1000 based // BrightTH by LV
            {        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },   //  i4LCEfaceTbl1  // Dark linear ratio, 1000 based
                  //LV0  LV1   LV2   LV3   LV4   LV5   LV6   LV7   LV8   LV9  LV10  LV11  LV12  LV13  LV14  LV15  LV16  LV17  LV18
            {        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },   //  i4LCEfaceTbl2  // Gain Diff Low
            {        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },   //  i4LCEfaceTbl3  // Gain Diff High
            {        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },   //  i4LCEfaceTbl4  // Blend Low
            {        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },   //  i4LCEfaceTbl5  // Blend High
            {        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },   //  i4LCEfaceTbl6  // Face DR Low
            {        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },   //  i4LCEfaceTbl7  // Face DR High
            {        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },   //  i4LCEfaceTbl8  // Slope Adjust Low
            {        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },   //  i4LCEfaceTbl9  // Slope Adjust High
            {        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },   //  i4LCEfaceTbl10 // Face Bright Low
            {        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },   //  i4LCEfaceTbl11 // Face Bright High
            {        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },   //  i4LCEfaceTbl12 // Slope Strength Low
            {        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },   //  i4LCEfaceTbl13 // Slope Strength High
            {        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },   //  i4LCEfaceTbl14
            {        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },   //  i4LCEfaceTbl15

            {     //i4CenSlopeEnhance
                  //  0   1   2   3   4   5   6   7   8   9   10   11
                      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,   0,   0
            },
            1,    //bFaceLCESmoothLinkEnable
            0,    //u4RobustFaceSlowSpeedCnt
            20,   //i4RobustFaceSmoothSpeed
            10,   //i4RobustFaceSmoothSlowSpeed
            5,    //i4RobustTargetUpdateFrame
            3,    //u4FaceLCEStableMaxCnt
            0,    //i4FaceLCEInStableThd
            0,    //i4FaceLCEOutStableThd
            0,    //reserve
            0,    //reserve
            0,    //reserve
            0     //reserve
        },

        .rMultiCamSync = {
            0,        // enableSync
            10,       // zoomBase, 1x = 10, 5x = 50, 0.6x = 6
            {         //syncWin[4][4] Record Tele in Wide Window position, and Wide in UltraWide window position.
                { 0, 0, 0, 0},{ 0, 0, 0, 0},{ 0, 0, 0, 0},{ 0, 0, 0, 0}
            },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} //reserve[10]
        },

        .rLCECustom = {  // rLCECustom
            1,   // calculate lce current gain enable (for 3rd party HDR)
            128, // max_lce_gain_ratio
            30,  //max pline threshold
            0,   //reserve
            0,   //reserve
            0,   //reserve
            0,   //reserve
            0,   //reserve
            0,   //reserve
            0,   //reserve
            0,   //reserve
            0,   //reserve
            0,   //reserve
            0,   //reserve

         // rsv   rsv   rsv   rsv   rsv   rsv   rsv   rsv   rsv   rsv   rsv   rsv   rsv   rsv   rsv   rsv   rsv   rsv   rsv
            { 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },   //  i4ReserveTbl0
            { 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },   //  i4ReserveTbl1
            { 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },   //  i4ReserveTbl2
            { 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },   //  i4ReserveTbl3
        },

        .rLCESmooth = {  // rLCESmooth
            1,        // bSmoothEnable
            70,       // i4LCEPosSpeed
            10,       // i4LCENegSpeed
            10,       // i4LCECrosPosSpeed
            10,       // i4LCECrosNegSpeed
            10,       //i4LCESpeed4AEStable
            10,       //minimum ev step
            0,        //reserve0
            0,        //reserve1
            0,        //reserve2
            0,        //reserve3
            0,        //reserve4
            0,        //reserve5
            0,        //reserve6
            0,        //reserve7
            0,        //reserve8
            0,        //reserve9
            0,        //reserve10
            0,        //reserve11
            0,        //reserve12
            0,        //reserve13
            0         //reserve14
            }
        }
};