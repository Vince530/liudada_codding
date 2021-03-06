/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2019. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
 *     TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#include "camera_custom_nvram.h"
#include "camera_custom_isp_nvram.h"

#include "inc.h"

#define NVRAM_AWB_TUNING_PARAM_NUM 9181001

#define AWB_BASE                                                     AWB_AWB_BASE

const AWB_NVRAM_T AWB_BASE[1] = {
    AWB_NVRAM_START
    {
        // AWB calibration data
        {
            {
    /******************************************************************************/
    //Feature name:
    //AWB unit and golden module calibration gain for high(DNP), middle(TL84) and color
    //low(ALight) color temperature
    //variable name: rUnitGain
    //default value: {512, 512, 512}
    //unit: 512 = 1x
    //data range : 0 ~ 4095
    //note: gain = {0, 0 ,0} means this unit not doing calibration for DNP
    /******************************************************************************/
                // rUnitGain for High color temperature (DNP)
                {
                       0, // UnitGain_R
                       0, // UnitGain_G
                       0  // UnitGain_B
                },
                // rGoldenGain for High color temperature (DNP)
                {
                       0, // GoldenGain_R
                       0, // GoldenGain_G
                       0  // GoldenGain_B
                },
                // rUnitGain for middle color temperature (TL84)
                {
                       0, // UnitGain_R
                       0, // UnitGain_G
                       0  // UnitGain_B
                },
                // rGoldenGain for middle color temperature (TL84)
                {
                       0, // GoldenGain_R
                       0, // GoldenGain_G
                       0  // GoldenGain_B
                },
                // rUnitGain for low color temperature (ALight)
                {
                       0, // UnitGain_R
                       0, // UnitGain_G
                       0  // UnitGain_B
                },
                // rGoldenGain for low color temperature (ALight)
                {
                       0, // GoldenGain_R
                       0, // GoldenGain_G
                       0  // GoldenGain_B
                },
    /******************************************************************************/
    //Feature name:
    //AWB unit gain for tuning sample only for debug use
    //variable name: rTuningUnitGain
    //default value: {512, 512, 512}
    //unit: 512 = 1x
    //data range : 0 ~ 4095
    //note: gain = {0, 0 ,0} means no tuning sample unit gain
    /******************************************************************************/
                // rTuningUnitGain (Tuning sample unit gain: 1.0 = 512)
                {
                       0, // TuningUnitGain_R
                       0, // TuningUnitGain_G
                       0  // TuningUnitGain_B
                },
    /******************************************************************************/
    //Feature name:
    //AWB golden sample calibration gain for D65
    //variable name: rD65Gain
    //default value: {512, 512, 512}
    //unit: 512 = 1x
    //data range : 0 ~ 4095
    /******************************************************************************/
                // rD65Gain (D65 WB gain: 1.0 = 512)
                {
                    1193, // D65Gain_R
                     512, // D65Gain_G
                     852  // D65Gain_B
                },
    /******************************************************************************/
    //Feature name:
    //AWB unit and golden module Bayer value for high(DNP), middle(TL84) and
    //low(ALight) color temperature
    //variable name: rUnitValue, rGoldenValue
    //default value: {128, 128, 128, 128}
    //data range : 1 ~ 255
    //note: rValue = {0, 0 ,0, 0} means this unit not doing calibration for DNP
    /******************************************************************************/
                // rUnitValue for DNP
                {
                      0, // UnitValue_R
                      0, // UnitValue_Gr
                      0, // UnitValue_Gb
                      0  // UnitValue_B
                },
                // rGoldenValue for DNP
                {
                      0, // GoldenValue_R
                      0, // GoldenValue_Gr
                      0, // GoldenValue_Gb
                      0  // GoldenValue_B
                },
                // rUnitValueM for TL84
                {
                      0, // UnitValue_R
                      0, // UnitValue_Gr
                      0, // UnitValue_Gb
                      0  // UnitValue_B
                },
                // rGoldenValueM for TL84
                {
                      0, // UnitValue_R
                      0, // UnitValue_Gr
                      0, // UnitValue_Gb
                      0  // UnitValue_B
                },
                // rUnitValueL for Alight
                {
                      0, // UnitValue_R
                      0, // UnitValue_Gr
                      0, // UnitValue_Gb
                      0  // UnitValue_B
                },
                // rGoldenValueL for Alight
                {
                      0, // GoldenValue_R
                      0, // GoldenValue_Gr
                      0, // GoldenValue_Gb
                      0  // GoldenValue_B
                }
            },
    /******************************************************************************/
    //Feature name:
    //AWB average white point distribution in X-Y domin under different light sources as
    //strobe, horizon, A (tungsten), TL84, CWF, DNP, D65 and DF (daylight fluorescnet)
    //variable name: rOriginalXY
    //default value: N/A
    //note: These settings are calibrated result, please do not need to modify them
    /******************************************************************************/
            // Original XY coordinate of AWB light source
            {
                // STROBE
                {
                       0, // OriX_STROBE
                       0  // OriY_STROBE
                },
                // HORIZON
                {
                    -499, // OriX_HORIZON
                    -514  // OriY_HORIZON
                },
                // A
                {
                    -336, // OriX_A
                    -530  // OriY_A
                },
                // TL84
                {
                    -151, // OriX_TL84
                    -597  // OriY_TL84
                },
                // CWF
                {
                    -121, // OriX_CWF
                    -659  // OriY_CWF
                },
                // DNP
                {
                      41, // OriX_DNP
                    -473  // OriY_DNP
                },
                // D65
                {
                     124, // OriX_D65
                    -501  // OriY_D65
                },
                // DF
                {
                       0, // OriX_DF
                       0  // OriY_DF
                },
            },
    /******************************************************************************/
    //Feature name:
    //AWB average white point distribution in rotated X-Y domain from original X-Y domain
    //in order to let the light source distribution in x-axis parallel direction
    //variable name: rRotatedXY
    //default value: N/A
    //note: These settings are calibrated result, please do not need to modify them
    /******************************************************************************/
            // Rotated XY coordinate of AWB light source
            {
                // STROBE
                {
                       0, // RotX_STROBE
                       0  // RotY_STROBE
                },
                // HORIZON
                {
                    -501, // RotX_HORIZON
                    -512  // RotY_HORIZON
                },
                // A
                {
                    -338, // RotX_A
                    -529  // RotY_A
                },
                // TL84
                {
                    -153, // RotX_TL84
                    -596  // RotY_TL84
                },
                // CWF
                {
                    -124, // RotX_CWF
                    -659  // RotY_CWF
                },
                // DNP
                {
                      39, // RotX_DNP
                    -473  // RotY_DNP
                },
                // D65
                {
                     122, // RotX_D65
                    -501  // RotY_D65
                },
                // DF
                {
                     111, // RotX_DF
                    -640  // RotY_DF
                },
            },
    /******************************************************************************/
    //Feature name:
    //AWB pre-calibrated gain based on the calibrated average white point distribution
    //for different light sources. It is treated as a default gain for corresponding light source
    //variable name: rLightAWBGain
    //default value: N/A
    //note: These settings are calibrated result, please do not need to modify them
    /******************************************************************************/
            // AWB gain of AWB light source
            {
                // STROBE
                {
                     512, // AWBGAIN_STROBE_R
                     512, // AWBGAIN_STROBE_G
                     512  // AWBGAIN_STROBE_B
                },
                // HORIZON
                {
                     522, // AWBGAIN_HORIZON_R
                     512, // AWBGAIN_HORIZON_G
                    2019  // AWBGAIN_HORIZON_B
                },
                // A
                {
                     666, // AWBGAIN_A_R
                     512, // AWBGAIN_A_G
                    1653  // AWBGAIN_A_B
                },
                // TL84
                {
                     936, // AWBGAIN_TL84_R
                     512, // AWBGAIN_TL84_G
                    1408  // AWBGAIN_TL84_B
                },
                // CWF
                {
                    1061, // AWBGAIN_CWF_R
                     512, // AWBGAIN_CWF_G
                    1472  // AWBGAIN_CWF_B
                },
                // DNP
                {
                    1026, // AWBGAIN_DNP_R
                     512, // AWBGAIN_DNP_G
                     919  // AWBGAIN_DNP_B
                },
                // D65
                {
                    1193, // AWBGAIN_D65_R
                     512, // AWBGAIN_D65_G
                     852  // AWBGAIN_D65_B
                },
                // DF
                {
                     512, // AWBGAIN_DF_R
                     512, // AWBGAIN_DF_G
                     512  // AWBGAIN_DF_B
                },
            },
    /******************************************************************************/
    //Feature name:
    //Rotation angle information for the rotated X-Y domain from original X-Y domain
    //variable name: RotationAngle
    //degree of rotation from original X-Y domain to rotated X-Y domain
    //data range: -180 ~ 180 (degree)
    //default value: N/A
    //variable name: Cos
    //value of cosine (RotationAngle) normalized by 256
    //data range: -256 ~ 256
    //default value: N/A
    //variable name: Sin
    //value of sine (RotationAngle) normalized by 255
    //data range: -256 ~ 256
    //defatul value: N/A
    //note: These settings are calibrated result, please do not need to modify them
    /******************************************************************************/
            // Rotation matrix parameter
            {
                  0, // RotationAngle
                256, // Cos
                  1  // Sin
            },
    /******************************************************************************/
    //Feature name:
    //Linear regression of distrubution of D65, TL84 and A(after compensated with D65 white balance gain)
    //on log(R/G)-log(B/G) domain into a linear line pass through the origin.
    //The mathematical equation can be represented by y = (SlopeNumerator) / (SlopeDenominator) * x,
    //where x is log(R/G) and y is log(B/G)
    //variable name: SlopeNumerator
    //numerator value of the slope of above equation
    //data range: N/A
    //default value: N/A
    //variable name: SlopeDenominator
    //denominator value for the slope of above equation
    //data range: N/A
    //default value: N/A
    //note: These settings are based on calibration, please do not need to modify them
    /******************************************************************************/
            // Daylight locus parameter
            {
                -123, // SlopeNumerator
                 128  // SlopeDenominator
            },
    /******************************************************************************/
    //Feature name:
    //Predefined white balance gain for different LV condition.
    //rSpatial_L gain is used for low LV condition.
    //rSpatial_H gain is used for high LV condition.
    //rTemporal gain is used for extra low LV or nonreliable condition.
    //variable name: i4R, i4G, i4B
    //default value: {512, 512, 512}
    /******************************************************************************/
            // Predictor gain
            {
                // Spatial_L
                {
                    1192, // i4R
                     512, // i4G
                     852  // i4B
                },
                // Spatial_H
                {
                    1026, // i4R
                     512, // i4G
                     919  // i4B
                },
                // Temporal
                {
                     890, // i4R
                     512, // i4G
                    1033  // i4B
                },
                // Spatial_CWFDF_L
                {
                    1048, // i4R
                     512, // i4G
                     800  // i4B
                },
                // Spatial_CWFDF_H
                {
                     943, // i4R
                     512, // i4G
                     845  // i4B
                }
            },
    /******************************************************************************/
    //Feature name:
    //A quadrangular window used to define the white point distrubution under strobe light,
    //tungsten, warm fluorescent, fluorescent, CWF, daylight, shade and daylight fluorescent
    //in rotated X-Y domain for auto white balance white point collection 
    //variable name: i4RightBound, i4LeftBound, i4UpperBound, i4LowerBound
    //defines the right boundary in x-axis, left boundary in x-axis, upper boundary in
    //y-axis and lower boundary in y-axis
    //default value: N/A
    //note: The value is calibrated by the strobe light in the lab, it can be fine tuned
    //to cover all the possible white point distrubution
    /******************************************************************************/
            // AWB light area
            {
                // STROBE
                {
                       0, // STROBE RightBound
                       0, // STROBE LeftBound
                       0, // STROBE UpperBound
                       0  // STROBE LowerBound
                },
                // TUNGSTEN
                {
                    -227, // TUNGSTEN RightBound
                    -775, // TUNGSTEN LeftBound
                    -437, // TUNGSTEN UpperBound
                    -562  // TUNGSTEN LowerBound
                },
                // WARM FLUORESCENT
                {
                    -227, // WARM FLUORESCENT RightBound
                    -901, // WARM FLUORESCENT LeftBound
                    -562, // WARM FLUORESCENT UpperBound
                    -749  // WARM FLUORESCENT LowerBound
                },
                // FLUORESCENT
                {
                     -23, // FLUORESCENT RightBound
                    -227, // FLUORESCENT LeftBound
                    -421, // FLUORESCENT UpperBound
                    -628  // FLUORESCENT LowerBound
                },
                // CWF
                {
                     -21, // CWF RightBound
                    -227, // CWF LeftBound
                    -628, // CWF UpperBound
                    -739  // CWF LowerBound
                },
                // DAYLIGHT
                {
                     152, // DAYLIGHT RightBound
                     -23, // DAYLIGHT LeftBound
                    -421, // DAYLIGHT UpperBound
                    -628  // DAYLIGHT LowerBound
                },
                // SHADE
                {
                     288, // SHADE RightBound
                     152, // SHADE LeftBound
                    -421, // SHADE UpperBound
                    -564  // SHADE LowerBound
                },
                // DF
                {
                     152, // DF RightBound
                     -21, // DF LeftBound
                    -628, // DF UpperBound
                    -739  // DF LowerBound
                },
            },
    /******************************************************************************/
    //Feature name:
    //A quadrangular window used to define the point collection reference area used in
    //preset white blance for reference area, daylight, cloudy daylight, shade, twilight,
    //fluorescent, warm fluorescent, incandescent and gray world. The white point inside will
    //be calculated as white point.
    //variable name: i4RightBound, i4LeftBound, i4UpperBound, i4LowerBound
    //defines the right boundary in x-axis, left boundary in x-axis, upper boundary in
    //y-axis and lower boundary in y-axis
    //default value: N/A
    /******************************************************************************/
            // PWB Reference area
            {
                     288, // PRefRightBound
                    -901, // PRefLeftBound
                    -396, // PRefUpperBound
                    -749  // PRefLowerBound
            },
            // PWB light area
            {
                // DAYLIGHT
                {
                     177, // DAYLIGHT RightBound
                     -23, // DAYLIGHT LeftBound
                    -421, // DAYLIGHT UpperBound
                    -628  // DAYLIGHT LowerBound
                },
                // CLOUDY_D
                {
                     277, // CLOUDY_D RightBound
                     102, // CLOUDY_D LeftBound
                    -421, // CLOUDY_D UpperBound
                    -628  // CLOUDY_D LowerBound
                },
                // SHADE
                {
                     377, // SHADE RightBound
                     102, // SHADE LeftBound
                    -421, // SHADE UpperBound
                    -628  // SHADE LowerBound
                },
                // TWILIGHT
                {
                     -23, // TWILIGHT RightBound
                    -183, // TWILIGHT LeftBound
                    -421, // TWILIGHT UpperBound
                    -628  // TWILIGHT LowerBound
                },
                // FLUORESCENT
                {
                     172, // FLUORESCENT RightBound
                    -253, // FLUORESCENT LeftBound
                    -451, // FLUORESCENT UpperBound
                    -709  // FLUORESCENT LowerBound
                },
                // WARM FLUORESCENT
                {
                    -238, // WARM FLUORESCENT RightBound
                    -438, // WARM FLUORESCENT LeftBound
                    -451, // WARM FLUORESCENT UpperBound
                    -709  // WARM FLUORESCENT LowerBound
                },
                // INCANDESCENT
                {
                    -238, // INCANDESCENT RightBound
                    -438, // INCANDESCENT LeftBound
                    -421, // INCANDESCENT UpperBound
                    -628  // INCANDESCENT LowerBound
                },
                // GRAY_WORLD
                {
                    5000, // GRAY_WORLD RightBound
                    -5000, // GRAY_WORLD LeftBound
                    5000, // GRAY_WORLD UpperBound
                    -5000  // GRAY_WORLD LowerBound
                },
            },
    /******************************************************************************/
    //Feature name:
    //Defaulte preset white balance gain for daylight, cloudy daylight, shade, twilight,
    //fluorescent, warm fluorescent, incandescent and grey world.
    //variable name: i4R, i4G, i4B for R gain, G gain and B gain
    //default value: N/A
    //data range : 0 ~ 4095
    //unit: 512 = 1x
    /******************************************************************************/
            // PWB default gain
            {
                // DAYLIGHT
                {
                    1159, // PWB_DAYLIGHT_R
                     512, // PWB_DAYLIGHT_G
                     935  // PWB_DAYLIGHT_B
                },
                // CLOUDY_D
                {
                    1348, // PWB_CLOUDY_D_R
                     512, // PWB_CLOUDY_D_G
                     803  // PWB_CLOUDY_D_B
                },
                // SHADE
                {
                    1442, // PWB_SHADE_R
                     512, // PWB_SHADE_G
                     750  // PWB_SHADE_B
                },
                // TWILIGHT
                {
                     909, // PWB_TWILIGHT_R
                     512, // PWB_TWILIGHT_G
                    1195  // PWB_TWILIGHT_B
                },
                // FLUORESCENT
                {
                    1066, // PWB_FLUORESCENT_R
                     512, // PWB_FLUORESCENT_G
                    1183  // PWB_FLUORESCENT_B
                },
                // WARM FLUORESCENT
                {
                     714, // PWB_WARM FLUORESCENT_R
                     512, // PWB_WARM FLUORESCENT_G
                    1772  // PWB_WARM FLUORESCENT_B
                },
                // INCANDESCENT
                {
                     662, // PWB_INCANDESCENT_R
                     512, // PWB_INCANDESCENT_G
                    1644  // PWB_INCANDESCENT_B
                },
                // GRAY_WORLD
                {
                     512, // PWB_GRAY_WORLD_R
                     512, // PWB_GRAY_WORLD_G
                     512  // PWB_GRAY_WORLD_B
                },
            },
            // CCT estimation
            {
    /******************************************************************************/
    //Feature name:
    //Color temperature estimation for the light source
    //variable name: CCT0, CCT1, CCT2, CCT3 and CCT4
    //color temperature for Horizon, A, TL84, DNP and D65 correspondingly
    //default value: N/A
    /******************************************************************************/
                // CCT
                {
                    2300,  // CCT0
                    2850,  // CCT1
                    3750,  // CCT2
                    5100,  // CCT3
                    6500   // CCT4
                },
    /******************************************************************************/
    //Feature name:
    //The Xr (rotated X) of the light source in color temeperature estimation
    //variable name: RotatedXCoordinate0, RotatedXCoordinate1, RotatedXCoordinate2,
    //RotatedXCoordinate3 and RotatedXCoordinate4
    //color temperature for Horizon, A, TL84, DNP and D65 correspondingly
    //default value: N/A
    /******************************************************************************/
                // Rotated X coordinate
                {
                    -623,  // RotatedXCoordinate0
                    -460,  // RotatedXCoordinate1
                    -275,  // RotatedXCoordinate2
                     -83,  // RotatedXCoordinate3
                       0   // RotatedXCoordinate4
                },
            },
    /******************************************************************************/
    //Feature name:
    //Porperty of color transform matrix
    //Uint color tranform  matrix = {1024, 0, 0, 0, 1024, 0, 0, 0, 1024}
    //default value: 0
    //data range: 0 and 1
    //0 means disable color transform and 1 means enable color transform
    //variable name: i4RWBCof
    //default value: N/A
    //transform 3x3 color matrix
    //variable name: i4RWBCofInv
    //default value: N/A
    //inverse transform 3x3 color matrix
    /******************************************************************************/
            // None Bayer Sensor
            {
                0,  // enable
                { 1024,    0,    0,    0, 1024,    0,    0,    0, 1024}, // color transfer matrix
                { 1024,    0,    0,    0, 1024,    0,    0,    0, 1024}, // inverse color transfer matrix
            },
    /******************************************************************************/
    //Feature name:
    //AWB Linear AAO statistics to replace block with error count
    //variable name: enable
    //default value: 1
    //variable name: i4ErrCntThr
    //default value: 0
    /******************************************************************************/
            // Linear AAO parameter
            {
                0, //enable
                40  //i4ErrCntThr
            },
        },
        // Algorithm Tuning Paramter
        {
    /******************************************************************************/
    //Feature name:
    //A set of gain applied after wb algorithm calculation output gain based on light source
    //and LV. It is used to optimize and fine tune for preference
    //variable name: {i4R, i4G, i4B} gain table from LV0 to LV18 for each light source
    //(Strobe, Tungsten, Warm Fluorescent, Fluorescent, CWF, Daylight, Daylight Fluorescent, Shade)
    //default value: {512, 512, 512}
    //unit: 512 = 1x
    /******************************************************************************/
            // Preference gain for each light source
            {
                { // STROBE
                    //    LV-4             LV-3            LV-2             LV-1              LV0              LV1              LV2              LV3              LV4              LV5            LV6            LV7
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                    //    LV8              LV9              LV10             LV11             LV12             LV13             LV14             LV15             LV16             LV17           LV18
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                },
                { // TUNGSTEN
                //    LV-4             LV-3            LV-2             LV-1              LV0              LV1              LV2              LV3              LV4              LV5            LV6            LV7
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 510}, {512, 512, 510}, {512, 512, 510}, {512, 512, 510}, {512, 512, 512}, {512, 512, 510}, {512, 512, 510}, {512, 512, 510}, {512, 512, 510},
                    //    LV8              LV9              LV10             LV11             LV12             LV13             LV14             LV15             LV16             LV17           LV18
                    {512, 512, 510}, {512, 512, 510}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                },
                { // WARM FLUORESCENT
                    //    LV-4             LV-3            LV-2             LV-1              LV0              LV1              LV2              LV3              LV4              LV5            LV6            LV7
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 510}, {512, 512, 510}, {512, 512, 510}, {512, 512, 510}, {512, 512, 510}, {512, 512, 510}, {512, 512, 512}, {512, 512, 510},
                    //    LV8              LV9              LV10             LV11             LV12             LV13             LV14             LV15             LV16             LV17           LV18
                    {512, 512, 510}, {512, 512, 510}, {512, 512, 510}, {512, 512, 510}, {512, 512, 510}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                },
                { // FLUORESCENT
                    //    LV-4             LV-3            LV-2             LV-1              LV0              LV1              LV2              LV3              LV4              LV5            LV6            LV7
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {514, 512, 510}, {514, 512, 510}, {514, 512, 510}, {514, 512, 510}, {512, 512, 512}, {512, 512, 510}, {512, 512, 510}, {512, 512, 510}, {512, 512, 510},
                    //    LV8              LV9              LV10             LV11             LV12             LV13             LV14             LV15             LV16             LV17           LV18
                    {512, 512, 510}, {512, 512, 510}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                },
                { // CWF
                    //    LV-4             LV-3            LV-2             LV-1              LV0              LV1              LV2              LV3              LV4              LV5            LV6            LV7
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 510}, {512, 512, 512},
                    //    LV8              LV9              LV10             LV11             LV12             LV13             LV14             LV15             LV16             LV17           LV18
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                },
                { // DAYLIGHT
                    //    LV-4             LV-3            LV-2             LV-1              LV0              LV1              LV2              LV3              LV4              LV5            LV6            LV7
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                    //    LV8              LV9              LV10             LV11             LV12             LV13             LV14             LV15             LV16             LV17           LV18
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 514}, {512, 512, 516}, {512, 512, 516}, {512, 512, 516}, {512, 512, 512}, {512, 512, 512}
                },
                { // SHADE
                    //    LV-4             LV-3            LV-2             LV-1              LV0              LV1              LV2              LV3              LV4              LV5            LV6            LV7
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                    //    LV8              LV9              LV10             LV11             LV12             LV13             LV14             LV15             LV16             LV17           LV18
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                },
                { // DF
                    //    LV-4             LV-3            LV-2             LV-1              LV0              LV1              LV2              LV3              LV4              LV5            LV6            LV7
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                    //    LV8              LV9              LV10             LV11             LV12             LV13             LV14             LV15             LV16             LV17           LV18
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                },
            },
    /******************************************************************************/
    //Feature name:
    //A set of LV threshold for spatial gain determination for each illuminant light
    //source including no neutral light
    //variable name: rNonReliable
    //default value: N/A
    //data range: 0 ~ 180
    //LV low threshold and high threshold for spatial gain determination in no reliable
    //light source environment
    //variable name: rLightSrc
    //default value: N/A
    //data range: 0 ~ 180
    //LV low threshold and high threshold for spatial gain determination for each light source,
    //including Strobe, Tungsten, Warm Fluorescent, Fluorescent, CWF, Daylight, Shade and Daylight Fluorescent
    //  y = interploate(x, x1, x2, y1, y2), where x1 and x2 are the low LV and high LV threshold.
    // y1 and y2 are the spatial predictor gain DaylightLocus_L and DaylightLocus_H correspondingly.
    //  y = y2, if x >= x2
    //  y = y1, if x < x1
    //  y = (x - x1) / (x2 - x1) * (y2 - y1), if x1 <= x < x2
    /******************************************************************************/
            // AWB LV threshold for spatial predictor
            {
                { 115, 155}, // NonReliable
                { // Reliable
                    {  80, 135}, // STROBE
                    { 110, 140}, // TUNGSTEN
                    { 110, 140}, // WARM FLUORESCENT
                    { 110, 140}, // FLUORESCENT
                    { 110, 140}, // CWF
                    {  80, 125}, // DAYLIGHT
                    {  80, 135}, // SHADE
                    {  80, 135}, // DF
                 },
            },
    /******************************************************************************/
    //Feature name:
    //Neutral parent block number threshold (ratio)for CWF/DF temporal enqueue
    //variable name: i4Neutral_ParentBlk_Thr
    //default value: N/A
    //data range: 0 ~ 432
    //One condition for current frame be enqueued to temporal
    //when neutral parent block number > i4Neutral_ParentBlk_Thr
    //varaiable name: i4CWFDF_LUTThr
    //default value: N/A
    //Look-up table of neutral block threahold ratio based on LV for CWF and DF light source.
    //The other conditions for current frame be enqueued is
    //(1) neutral parent block[CWF] < neutral parent block number * i4CWFDF_LUTThr(LV)
    //(2) neutral parent block[DF] < neutral parent block number * i4CWFDF_LUTThr(LV)
    /******************************************************************************/
            // AWB number threshold for temporal predictor
            {
                65,  // i4Neutral_ParentBlk_Thr
                //LV 0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18
                {  100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  50,  25,   2,   2,   2,   2,   2,   2,   2}  // i4CWFDF_LUTThr
            },
    /******************************************************************************/
    //Feature name:
    //Parent block threshold for reliable mode and noise reduction
    //variable name: i4NonNeutral and  i4NRThr[AWB_LIGHT_NUM]
    //default value: N/A
    //data range: 0 ~ 100 for each element in the table
    //These look-up table defines threahold ratio based on LV for no neutral light and all
    //light source. When the neutral block of these light source is below threshold,
    //it is not accumulated for statistics
    //Ex. Neutral block number[CWF] >= Parent block number * i4NRThr[CWF][LV]
    /******************************************************************************/
            // Reliable parent block threshold
            {
                //LV 0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18
                {    6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,  10,  10,  10,  10,  10,  10,  10,  10},
                // Noise Reduction
                {
                    //LV 0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18
                    {    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0},  // STROBE
                    {    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0},  // TUNGSTEN
                    {    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0},  // WARM FLUORESCENT
                    {    0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // FLUORESCENT
                    {    0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // CWF
                    {    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2,   2,   2,   2,   2,   2,   2,   2},  // DAYLIGHT
                    {    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0},  // SHADE
                    {    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // DF
                },
            },
            // AWB feature detection
            {
    /******************************************************************************/
    //Feature name:
    //Property description for sunset feature and daylight locus estimation for daylight
    //and also parameters used to define possible shade area (sunset area) inside daylight window
    //variable name: enable
    //default value: 1
    //data range: 0 and 1
    //0 means disable sunset feature detection
    //1 means enable sunset feature detection
    //variable name: i4LVThr_L
    //default value: N/A
    //data range: 0 ~ 180
    //variable name: i4LVThr_H
    //default value: N/A
    //data range: 0 ~ 180
    //variable name: i4SunsetCountThr
    //default value: N/A
    //data range: 0 ~ 432
    //variable name: i4SunsetCountRatio_L
    //default value: N/A
    //data range: 0~256 (unit: 256, 256 means 100 precent)
    //variable name: i4SunsetCountRatio_H
    //default value: N/A
    //data range: 0~256 (unit: 256, 256 means 100 precent)
    //variable name: i4Sunset_BoundXr_Thr
    //shade area right bound in Xr direction. left bound is the same as daylight window left bound
    //default value: N/A
    //variable name: i4Sunset_BoundYr_Thr
    //shade area upper bound in Yr direction. lower bound is the same ad daylight winodw lower bound
    //default value: N/A
    //(1)sunset feature detection condition is ((a) && (b) && (c))
    //   (a) light source is daylight
    //   (b) enable = 1
    //   (c) Current LV > i4LVThr_L
    //(2)sunset compensation for new daylight locus gain prediction in daylight when sunset feature exists
    //   Condition for new daylight locus gain prediction is ((a) && (b) && (c))
    //   (a) Current LV > i4LVThr_L
    //   (b) parent block number > i4SunsetCountThr
    //   (c) Sunset count > parent block number * i4SunsetCountRatio_L
    //(3)new daylight locus gain calculation
    //   i4SunsetCount_L_Thr = parent block number * i4SunsetCountRatio_L / 256
    //   i4SunsetCount_H_Thr = parent block number * i4SunsetCountRatio_H / 256
    //   Temp gain = interpolate(sunset count, i4SunsetCount_L_Thr, i4SunsetCount_H_Thr,
    //    daylight locus gain of current LV, sunset target gain)
    //   Sunset compensated daylight locus gain  = interpolate( current LV, i4LVThr_L,
    //    i4LVThr_H, daylight locus gain of current LV, Temp gain)
    //  y = interploate(x, x1, x2, y1, y2), where
    //  y = y2, if x >= x2
    //  y = y1, if x < x1
    //  y = (x - x1) / (x2 - x1) * (y2 - y1), if x1 <= x < x2
    /******************************************************************************/
                // Sunset Prop
                {
                      1, // enable
                    120, // i4LVThr_L
                    130, // i4LVThr_H
                     10, // i4SunsetCountThr
                      0, // i4SunsetCountRatio_L
                    256, // i4SunsetCountRatio_H
                    {
                          38, // i4Sunset_BoundXr_Thr
                        -515, // i4Sunset_BoundYr_Thr
                    },
                },
    /******************************************************************************/
    //Feature name:
    //Property description for CWF / F feature and the daylight locus probability estimation
    //for CWF / F parameters used to define possible shade area (soil area) inside CWF / F window
    //variable name: enable
    //default value: 1
    //data range: 0 and 1
    //0 means disable shade CWF / F feature detection
    //1 means enable shade CWF / F feature detection
    //variable name: i4Method
    //default value: 1
    //data range: 0 and 1
    //0 means to calculate the probability by distance
    //1 means to calculate the probability by vertex
    //variable name: i4LVThr_L
    //default value: N/A
    //data range: 0 ~ 180
    //variable name: i4LVThr_H
    //default value: N/A
    //data range: 0 ~ 180
    //variable name: i4DaylightProb
    //default value: N/A
    //data range: 0~256 (unit: 256, 256 means 100 precent)
    //variable name: Area X
    //shade area left bound in Xr direction. right bound is the same as window left bound
    //default value: N/A
    //variable name: Area Y
    //shade area left bound in Yr direction. right bound is the same as window left bound
    //default value: N/A
    //variable name: Vertex X
    //soil area vertex Xr position
    //default value: N/A
    //variable name: Vertex Y
    //soil area vertex Yr position
    //default value: N/A
    //(1)shade CWF feature detection condition is ((a) && (b) && (c))
    //   (a) light source is daylight
    //   (b) enable = 1
    //   (c) Current LV > i4LVThr_L
    //(2)new daylight locus probability calculatio
    //   Temp probability = interpolate(shade F count, 0, parenet block number of F,
    //   daylight locus probability of CWF / F, shade CWF / F probability)
    //   New daylight locus probability  = interpolate( current LV, i4LVThr_L, i4LVThr_H,
    //   daylight locus probability of fluorescent, Temp probability)
    //  y = interploate(x, x1, x2, y1, y2), where
    //  y = y2, if x >= x2
    //  y = y1, if x < x1
    //  y = (x - x1) / (x2 - x1) * (y2 - y1), if x1 <= x < x2
    /******************************************************************************/
                // SubWindow F Detection
                {
                      0, // enable
                      1, // i4Method
                     50, // i4LVThr_L
                     90, // i4LVThr_H
                    128, // i4DaylightProb
                    {
                        -225, // Area X
                        -601, // Area Y
                    },
                    {
                        -123, // Vertex X
                        -615, // Vertex Y
                    },
                },
                // SubWindow CWF Detection
                {
                      1, // enable
                      1, // i4Method
                     70, // i4LVThr_L
                     100, // i4LVThr_H
                    192, // i4DaylightProb
                    {
                        -70, // Area X
                        -645, // Area Y
                    },
                    {
                         -2, // Vertex X
                        -695, // Vertex Y
                    },
                },
    /******************************************************************************/
    //Feature name:
    //Property description for extra color detection.
    //variable name: enable
    //default value: 1
    //data range: 0 and 1
    //0 means disable extra color feature detection
    //1 means enable extra color feature detection
    //variable name: i4ModeWeight
    //Weighting for [0] blending specified gain, [1] P2 reduction and
    //[2] daylight locus probability reduction.
    //data range: 0 ~ 256, unit: 256 = 1x
    //variable name: i4ConfThr
    //The extra color confidence level frame number threshold
    //default value: 16
    //variable name: i4SelLightSrc
    //The extra color compensated light source
    //default value: 0
    //variable name: i4LvRange
    //The LV range for blending weight for difference LV to keep in weighting high and reverse
    //If the LV range is 0, means weighting keeps high and not reverse
    //default value: 0
    //data range: 0 ~ 255
    //variable name: gain
    //default value: N/A , unit: 512 = 1x
    //The blending gain for extra color detected
    //variable name: i4RightBound, i4LeftBound, i4UpperBound, i4LowerBound
    //The XrYr window for extra color detection
    //default value: N/A
    //variable name: rGlevel
    //The average G level for extra color detection
    //default value: N/A
    //variable name: rLv
    //default value: N/A
    //data range: 0 ~ 180
    //Blending weight for different LV
    //variable name: rCount
    //default value: N/A
    //data range: 0 ~ 432
    //Start to compensate when detected count > rCount.i4ThrL
    //Fully compensated when detected count > rCount.i4ThrH
    //variable name: rWeighting
    //default value: N/A
    //data range: 0 ~ 100
    //Blending weight for different LV
    /******************************************************************************/
                // Extra color Compensation
                {
                    // Extra Color 0
                    {
                        0, // enable
                        { 0, 0, 0}, // i4ModeWeight
                        16, // i4ConfThr
                        {0, 0, 0, 0, 0, 0, 0, 0}, // i4SelLightSrc : Strobe T WF F CWF D Shade DF
                        20, // i4LvRange
                        0, // i4GainCompWeight (64 base, can be larger than 64 and can be negative)
                        // Extra Color AWB gain
                        {
                            1193, // GainR
                             512, // GainG
                             852, // GainB
                        },
                        // Extra Color area
                        {
                              32, // i4RightBound
                            -275, // i4LeftBound
                            -739, // i4UpperBound
                            -839, // i4LowerBound
                        },
                        {   0, 255}, // rGlevel
                        {  60, 100}, // rLv
                        {  30, 200}, // rCount
                        {   0,  20}, // rWeighting
                    },
                    // Extra Color 1
                    {
                        0, // enable
                        { 0, 0, 0}, // i4ModeWeight
                        16, // i4ConfThr
                        {0, 0, 0, 0, 0, 0, 0, 0}, // i4SelLightSrc : Strobe T WF F CWF D Shade DF
                        20, // i4LvRange
                        0, // i4GainCompWeight (64 base, can be larger than 64 and can be negative)
                        // Extra Color AWB gain
                        {
                            1193, // GainR
                             512, // GainG
                             852, // GainB
                        },
                        // Extra Color area
                        {
                               0, // i4RightBound
                               0, // i4LeftBound
                               0, // i4UpperBound
                               0, // i4LowerBound
                        },
                        {   0, 255}, // rGlevel
                        {  60, 100}, // rLv
                        {  30, 200}, // rCount
                        {   0,  20}, // rWeighting
                    },
                    // Extra Color 2
                    {
                        0, // enable
                        { 0, 0, 0}, // i4ModeWeight
                        16, // i4ConfThr
                        {0, 0, 0, 0, 0, 0, 0, 0}, // i4SelLightSrc : Strobe T WF F CWF D Shade DF
                        20, // i4LvRange
                        0, // i4GainCompWeight (64 base, can be larger than 64 and can be negative)
                        // Extra Color AWB gain
                        {
                            1193, // GainR
                             512, // GainG
                             852, // GainB
                        },
                        // Extra Color area
                        {
                               0, // i4RightBound
                               0, // i4LeftBound
                               0, // i4UpperBound
                               0, // i4LowerBound
                        },
                        {   0, 255}, // rGlevel
                        {  60, 100}, // rLv
                        {  30, 200}, // rCount
                        {   0,  20}, // rWeighting
                    },
                    // Extra Color 3
                    {
                        0, // enable
                        { 0, 0, 0}, // i4ModeWeight
                        16, // i4ConfThr
                        {0, 0, 0, 0, 0, 0, 0, 0}, // i4SelLightSrc : Strobe T WF F CWF D Shade DF
                        20, // i4LvRange
                        0, // i4GainCompWeight (64 base, can be larger than 64 and can be negative)
                        // Extra Color AWB gain
                        {
                            1193, // GainR
                             512, // GainG
                             852, // GainB
                        },
                        // Extra Color area
                        {
                               0, // i4RightBound
                               0, // i4LeftBound
                               0, // i4UpperBound
                               0, // i4LowerBound
                        },
                        {   0, 255}, // rGlevel
                        {  60, 100}, // rLv
                        {  30, 200}, // rCount
                        {   0,  20}, // rWeighting
                    },
                    // Extra Color 4
                    {
                        0, // enable
                        { 0, 0, 0}, // i4ModeWeight
                        16, // i4ConfThr
                        {0, 0, 0, 0, 0, 0, 0, 0}, // i4SelLightSrc : Strobe T WF F CWF D Shade DF
                        20, // i4LvRange
                        0, // i4GainCompWeight (64 base, can be larger than 64 and can be negative)
                        // Extra Color AWB gain
                        {
                            1193, // GainR
                             512, // GainG
                             852, // GainB
                        },
                        // Extra Color area
                        {
                               0, // i4RightBound
                               0, // i4LeftBound
                               0, // i4UpperBound
                               0, // i4LowerBound
                        },
                        {   0, 255}, // rGlevel
                        {  60, 100}, // rLv
                        {  30, 200}, // rCount
                        {   0,  20}, // rWeighting
                    },
                    // Extra Color 5
                    {
                        0, // enable
                        { 0, 0, 0}, // i4ModeWeight
                        16, // i4ConfThr
                        {0, 0, 0, 0, 0, 0, 0, 0}, // i4SelLightSrc : Strobe T WF F CWF D Shade DF
                        20, // i4LvRange
                        0, // i4GainCompWeight (64 base, can be larger than 64 and can be negative)
                        // Extra Color AWB gain
                        {
                            1193, // GainR
                             512, // GainG
                             852, // GainB
                        },
                        // Extra Color area
                        {
                               0, // i4RightBound
                               0, // i4LeftBound
                               0, // i4UpperBound
                               0, // i4LowerBound
                        },
                        {   0, 255}, // rGlevel
                        {  60, 100}, // rLv
                        {  30, 200}, // rCount
                        {   0,  20}, // rWeighting
                    },
                    // Extra Color 6
                    {
                        0, // enable
                        { 0, 0, 0}, // i4ModeWeight
                        16, // i4ConfThr
                        {0, 0, 0, 0, 0, 0, 0, 0}, // i4SelLightSrc : Strobe T WF F CWF D Shade DF
                        20, // i4LvRange
                        0, // i4GainCompWeight (64 base, can be larger than 64 and can be negative)
                        // Extra Color AWB gain
                        {
                            1193, // GainR
                             512, // GainG
                             852, // GainB
                        },
                        // Extra Color area
                        {
                               0, // i4RightBound
                               0, // i4LeftBound
                               0, // i4UpperBound
                               0, // i4LowerBound
                        },
                        {   0, 255}, // rGlevel
                        {  60, 100}, // rLv
                        {  30, 200}, // rCount
                        {   0,  20}, // rWeighting
                    },
                    // Extra Color 7
                    {
                        0, // enable
                        { 0, 0, 0}, // i4ModeWeight
                        16, // i4ConfThr
                        {0, 0, 0, 0, 0, 0, 0, 0}, // i4SelLightSrc : Strobe T WF F CWF D Shade DF
                        20, // i4LvRange
                        0, // i4GainCompWeight (64 base, can be larger than 64 and can be negative)
                        // Extra Color AWB gain
                        {
                            1193, // GainR
                             512, // GainG
                             852, // GainB
                        },
                        // Extra Color area
                        {
                               0, // i4RightBound
                               0, // i4LeftBound
                               0, // i4UpperBound
                               0, // i4LowerBound
                        },
                        {   0, 255}, // rGlevel
                        {  60, 100}, // rLv
                        {  30, 200}, // rCount
                        {   0,  20}, // rWeighting
                    },
                    // Extra Color 8
                    {
                        0, // enable
                        { 0, 0, 0}, // i4ModeWeight
                        16, // i4ConfThr
                        {0, 0, 0, 0, 0, 0, 0, 0}, // i4SelLightSrc : Strobe T WF F CWF D Shade DF
                        20, // i4LvRange
                        0, // i4GainCompWeight (64 base, can be larger than 64 and can be negative)
                        // Extra Color AWB gain
                        {
                            1193, // GainR
                             512, // GainG
                             852, // GainB
                        },
                        // Extra Color area
                        {
                               0, // i4RightBound
                               0, // i4LeftBound
                               0, // i4UpperBound
                               0, // i4LowerBound
                        },
                        {   0, 255}, // rGlevel
                        {  60, 100}, // rLv
                        {  30, 200}, // rCount
                        {   0,  20}, // rWeighting
                    },
                    // Extra Color 9
                    {
                        0, // enable
                        { 0, 0, 0}, // i4ModeWeight
                        16, // i4ConfThr
                        {0, 0, 0, 0, 0, 0, 0, 0}, // i4SelLightSrc : Strobe T WF F CWF D Shade DF
                        20, // i4LvRange
                        0, // i4GainCompWeight (64 base, can be larger than 64 and can be negative)
                        // Extra Color AWB gain
                        {
                            1193, // GainR
                             512, // GainG
                             852, // GainB
                        },
                        // Extra Color area
                        {
                               0, // i4RightBound
                               0, // i4LeftBound
                               0, // i4UpperBound
                               0, // i4LowerBound
                        },
                        {   0, 255}, // rGlevel
                        {  60, 100}, // rLv
                        {  30, 200}, // rCount
                        {   0,  20}, // rWeighting
                    },
                    // Extra Color 10
                    {
                        0, // enable
                        { 0, 0, 0}, // i4ModeWeight
                        16, // i4ConfThr
                        {0, 0, 0, 0, 0, 0, 0, 0}, // i4SelLightSrc : Strobe T WF F CWF D Shade DF
                        20, // i4LvRange
                        0, // i4GainCompWeight (64 base, can be larger than 64 and can be negative)
                        // Extra Color AWB gain
                        {
                            1193, // GainR
                             512, // GainG
                             852, // GainB
                        },
                        // Extra Color area
                        {
                               0, // i4RightBound
                               0, // i4LeftBound
                               0, // i4UpperBound
                               0, // i4LowerBound
                        },
                        {   0, 255}, // rGlevel
                        {  60, 100}, // rLv
                        {  30, 200}, // rCount
                        {   0,  20}, // rWeighting
                    },
                    // Extra Color 11
                    {
                        0, // enable
                        { 0, 0, 0}, // i4ModeWeight
                        16, // i4ConfThr
                        {0, 0, 0, 0, 0, 0, 0, 0}, // i4SelLightSrc : Strobe T WF F CWF D Shade DF
                        20, // i4LvRange
                        0, // i4GainCompWeight (64 base, can be larger than 64 and can be negative)
                        // Extra Color AWB gain
                        {
                            1193, // GainR
                             512, // GainG
                             852, // GainB
                        },
                        // Extra Color area
                        {
                               0, // i4RightBound
                               0, // i4LeftBound
                               0, // i4UpperBound
                               0, // i4LowerBound
                        },
                        {   0, 255}, // rGlevel
                        {  60, 100}, // rLv
                        {  30, 200}, // rCount
                        {   0,  20}, // rWeighting
                    },
                    // Extra Color 12
                    {
                        0, // enable
                        { 0, 0, 0}, // i4ModeWeight
                        16, // i4ConfThr
                        {0, 0, 0, 0, 0, 0, 0, 0}, // i4SelLightSrc : Strobe T WF F CWF D Shade DF
                        20, // i4LvRange
                        0, // i4GainCompWeight (64 base, can be larger than 64 and can be negative)
                        // Extra Color AWB gain
                        {
                            1193, // GainR
                             512, // GainG
                             852, // GainB
                        },
                        // Extra Color area
                        {
                               0, // i4RightBound
                               0, // i4LeftBound
                               0, // i4UpperBound
                               0, // i4LowerBound
                        },
                        {   0, 255}, // rGlevel
                        {  60, 100}, // rLv
                        {  30, 200}, // rCount
                        {   0,  20}, // rWeighting
                    },
                    // Extra Color 13
                    {
                        0, // enable
                        { 0, 0, 0}, // i4ModeWeight
                        16, // i4ConfThr
                        {0, 0, 0, 0, 0, 0, 0, 0}, // i4SelLightSrc : Strobe T WF F CWF D Shade DF
                        20, // i4LvRange
                        0, // i4GainCompWeight (64 base, can be larger than 64 and can be negative)
                        // Extra Color AWB gain
                        {
                            1193, // GainR
                             512, // GainG
                             852, // GainB
                        },
                        // Extra Color area
                        {
                               0, // i4RightBound
                               0, // i4LeftBound
                               0, // i4UpperBound
                               0, // i4LowerBound
                        },
                        {   0, 255}, // rGlevel
                        {  60, 100}, // rLv
                        {  30, 200}, // rCount
                        {   0,  20}, // rWeighting
                    },
                    // Extra Color 14
                    {
                        0, // enable
                        { 0, 0, 0}, // i4ModeWeight
                        16, // i4ConfThr
                        {0, 0, 0, 0, 0, 0, 0, 0}, // i4SelLightSrc : Strobe T WF F CWF D Shade DF
                        20, // i4LvRange
                        0, // i4GainCompWeight (64 base, can be larger than 64 and can be negative)
                        // Extra Color AWB gain
                        {
                            1193, // GainR
                             512, // GainG
                             852, // GainB
                        },
                        // Extra Color area
                        {
                               0, // i4RightBound
                               0, // i4LeftBound
                               0, // i4UpperBound
                               0, // i4LowerBound
                        },
                        {   0, 255}, // rGlevel
                        {  60, 100}, // rLv
                        {  30, 200}, // rCount
                        {   0,  20}, // rWeighting
                    },
                    // Extra Color 15
                    {
                        0, // enable
                        { 0, 0, 0}, // i4ModeWeight
                        16, // i4ConfThr
                        {0, 0, 0, 0, 0, 0, 0, 0}, // i4SelLightSrc : Strobe T WF F CWF D Shade DF
                        20, // i4LvRange
                        0, // i4GainCompWeight (64 base, can be larger than 64 and can be negative)
                        // Extra Color AWB gain
                        {
                            1193, // GainR
                             512, // GainG
                             852, // GainB
                        },
                        // Extra Color area
                        {
                               0, // i4RightBound
                               0, // i4LeftBound
                               0, // i4UpperBound
                               0, // i4LowerBound
                        },
                        {   0, 255}, // rGlevel
                        {  60, 100}, // rLv
                        {  30, 200}, // rCount
                        {   0,  20}, // rWeighting
                    },
                },
    /******************************************************************************/
    //Feature name:
    //Property description for exclude color detection.
    //variable name: i4Weight (Base is 32)
    //default value: 0
    //data range: 0 ~ 32
    //0 meansno exclude color from statistics
    //1 ~ 32 means exclude color by i4Weight/32 from statistics, 32 is totally excluded
    //variable name: i4GlevelRange
    //default value: 10
    //exclude smoothly in Glevel 
    //variable name: i4LvRange
    //default value: 10
    //exclude smoothly in LV 
    //variable name: i4RightBound, i4LeftBound, i4UpperBound, i4LowerBound
    //The XrYr window for exclude color detection
    //default value: N/A
    //variable name: rGlevel
    //The average G level for exclude color detection
    //default value: N/A
    //variable name: rLv
    //default value: N/A
    //data range: 0 ~ 180
    /******************************************************************************/
                // Exclude color (Remove from statistics from neutral color)
                {
                    // Exclude Color 0
                         {
                             16, // i4Weight, base is 8
                             10, // i4GlevelRange, base is 8
                             10, // i4LvRange, base is 8
                             // Exclude Color area
                             {
                                    -197, // i4RightBound
                                    -405, // i4LeftBound
                                    -563, // i4UpperBound
                                    -703, // i4LowerBound
                             },
                             {   0, 255}, // rGlevel
                             {  70, 100}, // rLv
                         },
                         // Exclude Color 1
                         {
                             20, // i4Weight, base is 8
                             10, // i4GlevelRange, base is 8
                             10, // i4LvRange, base is 8
                             // Exclude Color area
                             {
                                    -199, // i4RightBound
                                    -303, // i4LeftBound
                                    -412, // i4UpperBound
                                    -502, // i4LowerBound
                             },
                             {   30, 80}, // rGlevel
                             {  60, 80}, // rLv
                         },
                         // Exclude Color 2
                         {
                             32, // i4Weight, base is 8
                             10, // i4GlevelRange, base is 8
                             10, // i4LvRange, base is 8
                             // Exclude Color area
                             {
                                    -54, // i4RightBound
                                    -133, // i4LeftBound
                                    -648, // i4UpperBound
                                    -694, // i4LowerBound
                             },
                             {   30, 70}, // rGlevel
                             {  5, 20}, // rLv
                         },
                         // Exclude Color 3
                         {
                             32, // i4Weight, base is 8
                             10, // i4GlevelRange, base is 8
                             10, // i4LvRange, base is 8
                             // Exclude Color area
                             {
                                    -146, // i4RightBound
                                    -279, // i4LeftBound
                                    -580, // i4UpperBound
                                    -658, // i4LowerBound
                             },
                             {   30, 255}, // rGlevel
                             {  90, 110}, // rLv
                         },
                         // Exclude Color 4
                         {
                             26, // i4Weight, base is 8
                             10, // i4GlevelRange, base is 8
                             10, // i4LvRange, base is 8
                             // Exclude Color area
                             {
                                    519, // i4RightBound
                                    247, // i4LeftBound
                                    -436, // i4UpperBound
                                    -554, // i4LowerBound
                             },
                             {   0, 255}, // rGlevel
                             {  50, 70}, // rLv
                         },
                         // Exclude Color 5
                         {
                             0, // i4Weight, base is 8
                             10, // i4GlevelRange, base is 8
                             10, // i4LvRange, base is 8
                             // Exclude Color area
                             {
                                    0, // i4RightBound
                                    0, // i4LeftBound
                                    0, // i4UpperBound
                                    0, // i4LowerBound
                             },
                             {   0, 255}, // rGlevel
                             {  60, 100}, // rLv
                         },
                         // Exclude Color 6
                         {
                             0, // i4Weight, base is 8
                             10, // i4GlevelRange, base is 8
                             10, // i4LvRange, base is 8
                             // Exclude Color area
                             {
                                    0, // i4RightBound
                                    0, // i4LeftBound
                                    0, // i4UpperBound
                                    0, // i4LowerBound
                             },
                             {   0, 255}, // rGlevel
                             {  60, 100}, // rLv
                         },

                    // Exclude Color 7
                    {
                        0, // i4Weight, base is 32
                        10, // i4GlevelRange
                        10, // i4LvRange
                        // Exclude Color area
                        {
                               0, // i4RightBound
                               0, // i4LeftBound
                               0, // i4UpperBound
                               0, // i4LowerBound
                        },
                        {   0, 255}, // rGlevel
                        {  60, 100}, // rLv
                    },
                },
    /******************************************************************************/
    //Feature name:
    //Property description for sky color detection.
    //variable name: enable
    //default value: 1
    //data range: 0 and 1
    //0 means disable sky color feature detection
    //1 means enable sky color feature detection
    //variable name: i4ConfThr
    //The extra color confidence level frame number threshold
    //default value: 16
    //variable name: i4LvRange
    //The LV range for blending weight for difference LV to keep in weighting high and reverse
    //If the LV range is 0, means weighting keeps high and not reverse
    //default value: 0
    //variable name: rSkyGain
    //2-D LUT, XrIndex and gain(R) & gain(B)
    //default value:
    //variable name: rGlevel
    //The average G level for extra color detection
    //default value: N/A
    //variable name: rLv
    //default value: N/A
    //data range: 0 ~ 180
    //Blending weight for different LV
    //variable name: rCount
    //default value: N/A
    //data range: 0 ~ 432
    //Start to compensate when detected count > rCount.i4ThrL
    //Fully compensated when detected count > rCount.i4ThrH
    //variable name: rWeighting 
    //default value: N/A
    //data range: 0 ~ 100
    //Blending weight for different LV
    /******************************************************************************/
                // Sky color Compensation
                {
                    0, // enable
                    16, // i4ConfThr
                    10, // i4LvRange
                    {
                        //XrIndex  SkyGain(R) SkyGain(B)
                        {   0, {1092,   837}},
                        {  20, {1058,   920}},
                        {  50, {1048,  1087}},
                        { 100, { 999,  1170}}
                    },
                    // Sky Color area
                    {
                         237, // i4RightBound
                          61, // i4LeftBound
                        -441, // i4UpperBound
                        -548, // i4LowerBound
                    },
                    {  45, 255}, // rGlevel
                    {  70, 140}, // rLv
                    {  40, 140}, // rCount
                    {   0,  40}, // rWeighting
                },
            },
    /******************************************************************************/
    //Feature name:
    //non-neutral probability for spatial and temporal weighting look-up table
    //variable name: i4Slope, i4XrOffsetThr
    //Reduce temporal predictor according to Temporal predictor Xr, Neutral Xr, and i4Slope, i4XrOffsetThr for partial reliable
    //ProbEqv = Prob * (100 - (abs(temporal.i4x - neutral.i4x) - i4XrOffsetThr) * i4Slope / 256)
    //variable name: i4LUT
    //default value: N/A
    //data range: 0 ~ 100
    //The look-up table defines the weighting to use spatial temporal gain
    /******************************************************************************/
            // Non-neutral probability for spatial and temporal weighting look-up table
            {
                 20, //i4Slope
                 200, //i4XrOffsetThr
                //LV 0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18
                {    0,  33,  66,  85,  85,  85,  85,  85,  85,  85,  85,  70,  30,  20,  10,   0,   0,   0,   0}
            },
    /******************************************************************************/
    //Feature name:
    //Look-up table according to current LV for each light source to determine the percentage of statistic gain usage
    //variable name: i4LUT
    //default value: N/A
    //data range: 0 ~ 100
    //Ex. EQ gain of A = (i4LUT[A][LV] * statistics gain of A + (100 - i4LUT[A][LV]) * spatial gain) / 100
    /******************************************************************************/
            // AWB daylight locus probability (Statistic Weighting) look-up table (Max: 100; Min: 0)
            {
                //LV -4   -3   -2   -1   0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18
                {{ 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  50,  25,   0,   0,   0,   0}}, // STROBE
                {{  95,  95,  50,  80,  95,  95, 100, 100,  95,  95,  95,  95,  95,  95, 100, 100, 100,  70,  70,  70,   0,   0,   0}}, // TUNGSTEN
                {{  95,  95,  95,  95,  95, 100, 100,  95,  95, 100, 100,  95,  95,  90, 100,  75,  50,  25,  25,  25,   0,   0,   0}}, // WARM FLUORESCENT
                {{  30,  30,  50,  80, 100, 100, 100, 100,  95,  95, 100,  90,  90,  90,  85,  75,  70,  75,  75,  70,   25,  0,   0}}, // FLUORESCENT
                {{  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  95,  95,  90,  60,  40,  40,  30,  30,  30,   0,   0,   0}}, // CWF
                {{ 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  80,  75,  75,  60,  30,  30,  20}}, // DAYLIGHT
                {{ 100, 100, 100, 100, 100, 100, 100, 100, 100,  80,  80, 100, 100, 100, 100, 100,  75,  50,  25,   0,   0,   0,   0}}, // SHADE
                {{  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  66,  50,  55,  30,  30,  30,  30,   0,   0,   0}}, // DF
            },
    /******************************************************************************/
    //Feature name:
    //Light source probability (P1) look-up table according to current LV for each light source
    //variable name: i4LUT
    //default value: N/A
    //data range: 0 ~ 100
    //Final probability P = P0 * P1 * P2, where P0 is paraent block number percentage,
    //P2 value is look-up by GMOffset in tungsten, WF, Shade
    /******************************************************************************/
            // AWB Light source probability (P1) look-up table (Max: 100; Min: 0)
            {
                //LV -4   -3   -2   -1   0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18
                {{ 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100}}, // STROBE
                {{  50,  50,  50,  50,  50,  50,  70,  70,  70,  80,  80,  80,  80,  80,  70,  70,  60,  30,   1,   1,   1,   1,   1}}, // TUNGSTEN
                {{  50,  50,  50,  50,  50,  50,  70,  70,  50,  80,  80, 100, 100,  80,  80,  80,  60,  30,   1,   1,   1,   1,   1}}, // WARM FLUORESCENT
                {{  90,  90,  90,  90,  90,  70,  70,  70,  90,  90,  95,  80,  80,  80,  95,  95,  80,  80,  80,  60,   1,   1,   1}}, // FLUORESCENT
                {{  80,  80,  80,  80,  80,  80,  80,  80,  80,  80,  80,  80,  80,  80,  90,  90,  66,  30,  30,   1,   1,   1,   1}}, // CWF
                {{  30,  30,  30,  30,  30,  40,  70,  70,  70,  80,  80,  80,  90,  95,  95, 100, 100, 100,  80,  80,  80,  80,  80}}, // DAYLIGHT
                {{  30,  30,  30,  30,  30,  45,  70,  80,  80,  80,  70,  80,  90,  90,  90,  90,  90,  60,  60,  30,   1,   1,   1}}, // SHADE
                {{  30,  30,  30,  30,  30,  45,  70,  80,  80,  80,  90,  90,  90,  90,  90,  90,  60,  30,   1,   1,   1,   1,   1}}, // DF
            },

    /******************************************************************************/
    //Feature name:
    //AWB convergence behavior control
    //variable name: i4Speed
    //the higher the value, the faster the convergence speed
    //default value: 50
    //data range: 0 ~ 100
    //variable name: i4StableThr
    //A stable threshold to control AWB to converge or not.When
    //((currentRgain - targetRgain)^2 + (currentBgain - targetBgain)^2) is larger than the i4StableThr,
    //AWB will converge and not converge if smaller than i4StableThr.
    //default value: 225
    //variable name: i4ToTargetEnable
    //default value: 1
    //data range: 0 and 1, 0 means might not coverge to target gain and 1 means always converge to target gain in preview
    /******************************************************************************/
            // AWB convergence parameter
            {
                 10, // i4Speed: Convergence speed: (0 ~ 100)
                225, // i4StableThr: Stable threshold ((currentRgain - targetRgain)^2 + (currentBgain - targetBgain)^2), WB gain format: 4.9
                  1  // i4ToTargetEnable: Preview converge to target enable.
            },
    /******************************************************************************/
    //Feature name:
    //Preference color is used control WB convergence degree for Tungsten, WF and Shade
    /******************************************************************************/
            // Preference color
            {
    /******************************************************************************/
    //Feature name:
    //Preference color is used control WB convergence degree for Tungsten, WF and Shade
    //variable name: Offset threshold
    //do full compensation when current distance from the origin to the white point(log(R/G),
    //log(B/G)) is under Offset threshold , and do partial compensation when
    //the distance is above Offset threshold
    //default value: N/A
    //data range: 0 ~ 10000
    /******************************************************************************/
                //Offset threshold
                {
                    6700, // T
                    6300, // WF
                    2000  // Shade
                },
    /******************************************************************************/
    //Feature name:
    //LV thrshold for daylight locus partial comensation new offset calculation
    //variable name: rOffsetRatioLv
    //default value: N/A
    //Daylight locus target offset = interpolate(current LV, i4ThrL, i4ThrH, Daylight
    //locus temp offset*(ratio look-up in i4LUT for daylight locus offset partial compensation),
    //Daylight locus temp offset)
    //  y = interploate(x, x1, x2, y1, y2), where
    //  y = y2, if x >= x2
    //  y = y1, if x < x1
    //  y = (x - x1) / (x2 - x1) * (y2 - y1), if x1 <= x < x2
    //data range: 0 ~ 10000
    /******************************************************************************/
                //Offset ratio LV
                {
                    {  50,  85}, // TUNGSTEN
                    {  50,  85}, // WARM FLUORESCENT
                    {  70, 100}, // SHADE
                },
    /******************************************************************************/
    //Feature name:
    //Use daylight locus new offset (0~10000) as index to get daylight locus target offset ratio (0~100)
    //variable name: i4LUT
    //default value: N/A
    //data range: 0 ~ 100
    //New offset = Current offset (distance of current white point - threshold defined
    //for corresponding illuminant light source) * interpolation in i4LUT by current offset.
    /******************************************************************************/
                //AWB daylight locus target Offset ratio LUT
                {
                    { // TUNGSTEN
                        { //  0  500 1000 1500 2000 2500 3000 3500 4000 4500 5000 5500 6000 6500 7000 7500 8000 8500 9000 9500 10000
                                 60,  80,  82,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  85,  84,  100,  100, 100
                            },
                    },
                    { // WARM FLUORESCENT
                        { //  0  500 1000 1500 2000 2500 3000 3500 4000 4500 5000 5500 6000 6500 7000 7500 8000 8500 9000 9500 10000
                            50, 50, 80, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100
                        },
                    },
                    { // SHADE
                        { //  0  500 1000 1500 2000 2500 3000 3500 4000 4500 5000 5500 6000 6500 7000 7500 8000 8500 9000 9500 10000
                             50,  50,  50,  50,  50,  75,  90, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100
                        },
                    },
                },
    /******************************************************************************/
    //Feature name:
    //New target offset remapping LUT table. It is used to adjust white balance partial
    //compensation degree when the white point distance in log(R/G)-log(B/G) domain is larger than
    //threshold (i4OffsetThr) for tungsten, warm fluorescent and shade
    //variable name: i4LUTSize, LUT table dimension size
    //variable name: i4LUTIn: Look-up table input of daylight locus offset
    //variable name: iLUTOut: Loop-up table output of daylight locus offset
    /******************************************************************************/
                //Daylight locus offset LUTs
                {
                    { // TUNGSTEN
                        {   0,  500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000},
                        {   0,  350,  800, 1222, 1800, 2000, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778, 5000}
                    },
                    { // WARM FLUORESCENT
                        {   0,  500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000},
                        {   0,  350,  700, 1000, 1444, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778, 5000}
                    },
                    { // SHADE
                        {   0,  500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000},
                        {   0,  500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}
                    },
                },
    /******************************************************************************/
    //Feature name:
    //Green and Magenta offset remapping look-up table for partial compensation offset
    //for tungsten, warm fluorescent and shade
    //variable name: i4OffsetMode
    //default value: N/A
    //data range: 0 and 1
    //0 means not to disable offset remapping
    //1 means to enable offset remapping
    //variable name: i4LutM
    //default value: N/A
    //data range: 0 ~ 10000
    //Magenta offset remaping look-up table
    //variable name: i4LUTG
    //default value: N/A
    //data range: 0 ~ 10000
    //Green offset remaping look-up table
    /******************************************************************************/
                //AWB Green/Magenta offset threshold
                {
                    { // TUNGSTEN
                        1, //i4OffsetMode : 0 disabe 1 enable. Increase offset when GM offset is large than threshold
                        { // LUT: use daylight locus offset (0~10000) as index to get magenta offset threshold
                          //  0   500  1000  1500  2000  2500  3000  3500  4000  4500  5000  5500  6000  6500  7000  7500  8000  8500  9000  9500  10000
                                400,  400,  400,  400,  400,  400,  400,  400,  400,  400,  400,  400,  400,  400,  400,  400,  400,  300,  300,  300,  300
                            },
                        { // LUT: use daylight locus offset (0~10000) as index to get green offset threshold
                          //  0   500  1000  1500  2000  2500  3000  3500  4000  4500  5000  5500  6000  6500  7000  7500  8000  8500  9000  9500  10000
                           2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000
                        },
                    },
                    { // WARM FLUORESCENT
                        1, //i4OffsetMode : 0 disabe 1 enable. Increase offset when GM offset is large than threshold
                        { // LUT: use daylight locus offset (0~10000) as index to get magenta offset threshold
                          //  0   500  1000  1500  2000  2500  3000  3500  4000  4500  5000  5500  6000  6500  7000  7500  8000  8500  9000  9500  10000
                           1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500
                        },
                        { // LUT: use daylight locus offset (0~10000) as index to get green offset threshold
                          //  0   500  1000  1500  2000  2500  3000  3500  4000  4500  5000  5500  6000  6500  7000  7500  8000  8500  9000  9500  10000
                          1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 800, 800, 800, 800
                        },
                    },
                    { // SHADE
                        1, //i4OffsetMode : 0 disabe 1 enable. Increase offset when GM offset is large than threshold
                        { // LUT: use daylight locus offset (0~10000) as index to get magenta offset threshold
                          //  0   500  1000  1500  2000  2500  3000  3500  4000  4500  5000  5500  6000  6500  7000  7500  8000  8500  9000  9500  10000
                          200,  200,  200,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100
                        },
                        { // LUT: use daylight locus offset (0~10000) as index to get green offset threshold
                          //  0   500  1000  1500  2000  2500  3000  3500  4000  4500  5000  5500  6000  6500  7000  7500  8000  8500  9000  9500  10000
                            100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100
                        },
                    },
                },
    /******************************************************************************/
    //Feature name:
    //Light source probability (P2) look-up table according to green or magenta offset
    //of corresponding light source white point for tungsten, warm fluorescent and shade
    //variable name: i4LutM
    //default value: N/A
    //data range: 0 ~ 256 (256 is 100 percent)
    //variable name: i4LutG
    //default value: N/A
    //data range: 0 ~ 256 (256 is 100 percent)
    //When the corresponding white point in log(R/G)-log(B/G) domain is above the
    //daylight locus line, use i4LUTM else use i4LUTG for look-up table.
    //Final probability P = P0 * P1 * P2, where P0 is parent block number percentage,
    //P1 is look-up table accordint to LV for each light source
    /******************************************************************************/
                // AWB light source weight LUT
                {
                    { // Tungsten
                        { // LUT: use magenta offset (0~1000) as index to get tungsten weight (x/256)
                          // 0   100  200  300  400  500  600  700  800  900 1000
                            256, 256, 256, 128, 128, 256, 256, 128,  64,  32,  16
                        },
                        { // LUT: use green offset (0~1000) as index to get tungsten weight (x/256)
                          //  0  100  200  300  400  500  600  700  800  900 1000
                            256, 256, 256, 128, 128, 256, 256, 128,  64,  32,  16
                        },
                    },
                    { // Warm Fluorescent
                        { // LUT: use magenta offset (0~1000) as index to get tungsten weight (x/256)
                          //  0  200  400  600  800 1000 1200 1400 1600 1800 2000
                            256, 256, 256, 256, 256, 192, 192, 192,  96,  128,  256
                        },
                        { // LUT: use green offset (0~1000) as index to get tungsten weight (x/256)
                          //  0  200  400  600  800 1000 1200 1400 1600 1800 2000
                            256, 256, 256, 256, 256, 192, 192, 192,  96,  128,  256
                        },
                    },
                    { // Shade
                        { // LUT: use magenta offset (0~1000) as index to get tungsten weight (x/256)
                          //  0  100  200  300  400  500  600  700  800  900 1000
                            256, 256, 256, 256, 192, 128,  128,  192,  128,  16,  16
                        },
                        { // LUT: use green offset (0~1000) as index to get tungsten weight (x/256)
                          //  0  100  200  300  400  500  600  700  800  900 1000
                            256, 256, 256, 256, 192, 128,  64,  32,  32,  16,  16
                        },
                    },
                },
    /******************************************************************************/
    //Feature name:
    //Light source preference gain according to LUT of daylight locust offset and green or
    //magenta offset of corresponding light source white point for tungsten, warm fluorescent and shade
    //variable name: rDlOffsetGain
    //default value: N/A
    //variable name: rMOffsetGain
    //default value: N/A
    //variable name: rGOffsetGain
    //default value: N/A
    /******************************************************************************/
                // AWB light source preference gain LUT
                {
                    { // TUNGSTEN
                        { // LUT: use ratio offset as index
                            {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512},
                            {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512},
                        },
                        { // LUT: use (magenta offset - thld) as index
                          //  0  100  200  300  400  500  600  700  800  900 1000 
                            {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}
                        },
                        { // LUT: use (green offset - thld) as index
                          //  0  100  200  300  400  500  600  700  800  900 1000 
                            {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}
                        },
                    },
                    { // WARM FLUORESCENT
                        { // LUT: use ratio offset as index
                            {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512},
                            {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512},
                        },
                        { // LUT: use (magenta offset - thld) as index
                          //  0  100  200  300  400  500  600  700  800  900 1000 
                            {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}
                        },
                        { // LUT: use (green offset - thld) as index
                          //  0  100  200  300  400  500  600  700  800  900 1000 
                            {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}
                        },
                    },
                    { // SHADE
                        { // LUT: use ratio offset as index
                            {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 506}, {512, 512}, {512, 512}, {512, 512}, {512, 512},
                            {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512},
                        },
                        { // LUT: use (magenta offset - thld) as index
                          //  0  100  200  300  400  500  600  700  800  900 1000 
                            {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}
                        },
                        { // LUT: use (green offset - thld) as index
                          //  0  100  200  300  400  500  600  700  800  900 1000 
                            {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}, {512, 512}
                        },
                    },
                },
            },
            // AWB advance function
            {
                //AWB Refinement
                {
    /******************************************************************************/
    //Feature name:
    //Property for low light stability
    //variable name: i4CbMinThr
    //default value: N/A
    //data range: 0 ~ 25
    //The minimum value for valid statistic block
    /******************************************************************************/
                    2,    //i4CbMinThr
    /******************************************************************************/
    //Feature name:
    //Modes of spatial gain for each light source, non-reliable and temporal initial mode
    //variable name: i4GeneralMode
    //default value: N/A
    //data range: 0 ~ 2
    //Each light source
    //variable name: i4NonReliableMode
    //default value: N/A
    //data range: 0 ~ 2
    //variable name: i4TempInitMode
    //default value: N/A
    //data range: 0 ~ 2
    //Mode 0 : LV > ThrH use rSpatial_H gain
    //         ThrL < LV < ThrH use interpolated gain from rSpatial_L and rSpatial_H.
    //         LV < ThrL use rSpatial_L gain
    //Mode 0 : LV > ThrH use rSpatial_H gain
    //         ThrL < LV < ThrH use interpolated gain from rSpatial_L and rSpatial_H.
    //         LV < ThrL use rTemporal_General gain
    //Mode 2 : LV > ThrH use spatial gain H
    //         ThrL < LV < ThrH use interpolated gain from rSpatial_L and rSpatial_H.
    //         TempLv < LV < ThrL use rSpatial_L gain
    //         LV < TempLv use interpolated gain from rSpatial_L and rTemporal_General.
    //variable name: i4ThrTemp
    //default value: N/A
    //data range: 0 ~ 180
    //This value is used when non-reliable and temporal initial mode using mode 2
    //variable name: i4TempLv
    //default value: N/A
    //data range: 0 ~ 180
    //These value are used normal mode using mode 2
    /****************************************************************************/
                    // Spatial gain
                    {
                         2, // General Mode
                         2, // Non-Reliable Mode
                         2, // Temporal Init Mode
                       // Non-reliable LV threshold
                        20, //i4ThrTemp
                       // Reliable LV threshold
                       {
                            20, // STROBE
                            20, // TUNGSTEN
                            20, // WARM FLUORESCENT
                            20, // FLUORESCENT
                            20, // CWF
                            20, // DAYLIGHT
                            20, // SHADE
                            20, // DF
                       }
                    },
    /******************************************************************************/
    //Feature name:
    //Property of P0 stability
    //variable name: enable
    //default value: N/A
    //data range: 0 ~ 1
    //0 means disable P0 stabilized function
    //1 means enable P0 stabilized function
    //variable name: i4PbRatio
    //default value: N/A
    //data range: 0 ~ 100
    //variable name: i4Range
    //default value: N/A
    //data range: 0 ~ 32
    //variable name: i4Clip
    //default value: N/A
    //data range: 0 ~ 10
    /****************************************************************************/
                    // P0 Stability
                    {
                         1, //enable
                        20, //i4PbRatio
                        32, //i4Range
                         2  //i4Clip
                    },
    /******************************************************************************/
    //Feature name:
    //P2 is effective only for high LV, enough neutral parent block and 
    //P0 is in resonable range
    //variable name: enable
    //default value: N/A
    //data range: 0 ~ 1
    //0 means disable P2 stabilized function
    //1 means enable P2 stabilized function
    //variable name: i4PbRatio
    //default value: N/A
    //data range: 0 ~ 100
    //The P2 is effective when valid neutral block larger than this value
    //variable name: i4LvThr
    //default value: N/A
    //The P2 is effective when LV is larger than this value
    //data range: 0 ~ 180
    //variable name: i4P0Thr1
    //default value: N/A
    //data range: 0 ~ 150
    //variable name: i4P0Thr2
    //default value: N/A
    //data range: 0 ~ 150
    //The P2 is fully effective when P0 > i4P0Thr1. The P2 is not effective if P0 > i4P0Thr2
    //The P2 is partial effective when i4P0Thr2 > P0 > i4P0Thr1.
    /****************************************************************************/
                    // P2 Stability
                    {
                         1, //enable
                        20, //i4PbRatio
                        20, //i4LvThr
                       100, //i4P0Thr1
                       100  //i4P0Thr2
                    },
    /******************************************************************************/
    //Feature name:
    //Property of Preference Color stability
    //variable name: enable
    //default value: N/A
    //data range: 0 ~ 1
    //0 means disable preference color stability function
    //1 means enable preference color stability function
    //variable name: rOffsetSmooth
    //default value: N/A
    //data range: 0 ~ 1024
    //These value are used for smooth transient region to preserver preference color.
    /****************************************************************************/
                    // Preference Color Stability
                    {
                         1,    //enable
                        {
                           512, //T
                           512, //WF
                           512  //Shade
                        }
                    },
                },
    /******************************************************************************/
    //Feature name:
    //Property of statistic gain constraint for each light source
    //variable name: i4Mode
    //default value: N/A
    //data range: 0 ~ 1 
    //variable name: i4GlevelRange
    //used to do smooth project weight instead of cut-off 
    //project weight is interpolate from 0 to i4ProjWeight for rGlevel.i4ThrL - i4GlevelRange to i4GlevelRange 
    //project weight is i4ProjWeight for rGlevel.i4ThrL to rGlevle.i4ThrH 
    //project weight is interpolate from i4ProjWeight to 0 for rGlevel.i4ThrH to rGlevel.i4ThrH + i4GlevelRange 
    //project weight is  0 for else 
    //default value: 10
    //data range: 0 ~ 20 (recommended)
    //0 means disable statistic gain constraint
    //1 means enable statistic gain constraint on avergage
    //2 means enable statistic gain constraint on each parent block
    //variable name: rLv
    //default value: N/A
    //data range: 0 ~ 180
    //The statistic limit effect will be reduced from i4ThrH and disable when Lv lower than i4ThrL
    //variable name: i4LimitY
    //default value: N/A
    //These value define the reasonable distance from daylight locus.The values of Tusteng, Fluorescent, Daylight
    //and shade are the upper boundary. The values of Warm Fluorescent, CWF and DF are the lower boundary
    //variable name: i4WeightReduce
    //default value: N/A
    //data range: 0 ~ 16
    //If the statistic location is far away from daylight locus. It will reduce the statistic gain weighting
    //variable name: i4ProjWeight
    //default value: N/A
    //data range: 0 ~ 16
    //The statistic will project to the statistic limit boundary according to projection weighting
    //variable name: rGlevel
    //default value: [0,255]
    //data range: 0 ~ 255
    //PB G average value inside the range be projected
    /******************************************************************************/
                // rStatLimit
                {
                    2,    // i4Mode
                    10,    // i4GelveRange
                    {  10,  30}, // rLv
                    { // i4LimitY[AWB_LIGHT_NUM]
                         0,  // STROBE
                        42,  // TUNGSTEN
                       226,  // WARM FLUORESCENT
                        60,  // FLUORESCENT
                       176,  // CWF
                        60,  // DAYLIGHT
                        90,  // SHADE
                       176,  // DF
                    },
                    { // i4WeightReduce[AWB_LIGHT_NUM]
                        0,  // STROBE
                        8,  // TUNGSTEN
                        8,  // WARM FLUORESCENT
                        8,  // FLUORESCENT
                        8,  // CWF
                        8,  // DAYLIGHT
                        8,  // SHADE
                        8,  // DF
                    },
                    { // i4ProjWeight[AWB_LIGHT_NUM]
                        0,  // STROBE
                       16,  // TUNGSTEN
                       16,  // WARM FLUORESCENT
                       16,  // FLUORESCENT
                       16,  // CWF
                       16,  // DAYLIGHT
                       16,  // SHADE
                       16,  // DF
                    },
                    { // G level
                        {   0,    0},  // STROBE
                        {   0,  255},  // TUNGSTEN
                        {   0,  255},  // WARM FLUORESCENT
                        {   0,  255},  // FLUORESCENT
                        {   0,  255},  // CWF
                        {   0,  255},  // DAYLIGHT
                        {   0,  255},  // SHADE
                        {   0,  255},  // DF
                    },
                },
    /******************************************************************************/
    //Feature name:
    //Common setting for face preferece and face assisted awb algorithm
    /******************************************************************************/
                // Face Common
                {
    /******************************************************************************/
    //Feature name:
    //Face AWB basic control & basic statistic tuning
    //variable name: i4StatAvoidFaceArea
    //default value: 0
    //unit: N/A
    //data range: 0 and 1
    //0 means normal AWB statistic
    //1 means normal AWB statistic will exclude face area
    //variable name: i4FaceWinRatio
    //default value: 100
    //unit: percentage
    //data range: 50 ~ 400
    //This parameter can change the original FD window size
    //variable name: central_weight
    //default value: 1
    //unit: N/A
    //data range: 0 ~
    //This parameter can enhance FD window central weighting, the formula is
    //(Original FD info + Central FD info * weighting) / (weighting + 1)
    //variable name: rStatisticNR
    // (a)enable is used for enable NR process
    //    unit: N/A
    //    data range: 0 and 1
    // (b)i4DiffThr is used to judge the child block belongs to face or not
    //    e.g One child block {R/G, B/G}, and the central face area is {R'/G', B'/G'}
    //    If |R/G - R'/G'| + |B/G - B'/G'| > i4DiffThr, this child block doesn't belong to face
    //    And face statistic will skip this child block
    //    unit: 1000
    //    data range: 0 ~
    //Do NR process when statistic face area data
    //variable name: rFD_RGB_Bound
    //default value: {1, 254}
    //unit: N/A
    //data range: 0 ~ 255
    //If face R or G or B is lower than Low Bound, or higher than High bound,
    //this face will be ignored for using
    /******************************************************************************/
                      1,    //i4StatAvoidFaceArea
                    100,    //i4FaceWinRatio  50~400
                      1,    //central_weight
                      2,    //landmark_weight
                    // rStatisticNR
                    {
                          2,    //i4Mode
                        // rLumaNR
                        {
                              4,    //i4Factor
                        },
                        // rChromaNR
                        {
                            191,    //i4DiffThr
                            // rLandmarkCVThr
                            {
                                 30,    //i4ThrL
                                100,    //i4ThrH
                            },
                            // rLandmarkProb
                            {
                                  0,    //i4ThrL
                                 80,    //i4ThrH
                            },
                            // rDistVarThr
                            {
                                 50,    //i4Low
                                100,    //i4Mid
                                150,    //i4High
                            },
                            // rFeatureCVProb
                            {
                                100,    //i4Low
                                 50,    //i4Mid
                                  0,    //i4High
                            },
                        },
                    },
                    // rFD_RGB_Bound
                    {
                          1,    //u4LowBound
                        254     //u4HiBound
                    },
    /******************************************************************************/
    //Feature name:
    //Face awb temporal smooth mechanism
    //variable name: rTempoSmooth
    // (a)i4Speed is control the temporal IIR step. If it sets to 10, the temporal
    //    smooth will separate the target distance into 10 steps and forward 1 step
    //     unit: N/A
    //    data range: 0 ~ 100
    // (b)i4MinStep is minimum AWB gain step. If one step, which is calculated by
    //    i4Speed, is smaller than i4MinStep, then AWB gain will choose to forward
    //    1 i4MinStep
    //    unit: percentage
    //    data range: 0 ~
    // (c)i4ProbReduceStep is used for face gone. If face gone or disappear, the
    //     face probability will start to reduce by i4ProbReduceStep
    //     unit: percentage
    //     data range: 0 ~
    //variable name: rSceneChange used when face gone.
    // (a)i4LVChangeTh is used when face gone or disappear, and the LV changes
    //    more than this threshold in 1 frame, then directly make face awb
    //    probability to 0
    //    unit: 10 = 1x
    //    data range: 0 ~ 180
    // (b)i4AWBGainChangeTh is also used when face gone or disappear, and the AWB
    //    gain changes more than this threshold in 1 frame, then directly make face
    //    awb probability to 0
    //    unit: 10 = N/A
    //    data range: 0 ~
    //    AWB changes distance = (previous normal AWB R gain - current AWB R gain)^2 +
    //                              (previous normal AWB B gain - current AWB B gain)^2
    /******************************************************************************/
                    // rTempoSmooth
                    {
                        10,    //i4Speed: Converge Speed 1~100
                         2,    //i4MinStep: Minimum converge step
                         1     //i4ProbReduceStep: If face gone, the face prob reduce step 1~100
                    },
                    // rSceneChange
                    {
                           30,   //i4LVChangeTh
                        20000    //i4AWBGainChangeTh
                    },
                },
    /******************************************************************************/
    //Feature name:
    //Face Preference AWB refer face information for AWB modification, and at the same time,
    //AWB also can help skin tone to approach the preference a little
    /******************************************************************************/
                // Face Preference AWB
                {
    /******************************************************************************/
    //Feature name:
    //Face Pref Compensation Enable Flag
    //variable name: enable
    //default value: 0
    //unit: N/A
    //data range: 0 and 1
    //0 means disable face Pref
    //1 means enable face Pref
    //Feature name:
    //Face Pref preference skin tone target
    //variable name: i4SatTargetEn
    //unit: N/A
    //data range: 0 and 1
    //Enable Saturation Target for face Pref saturation control
    //variable name: rRefTarget
    //default value: calibrated from calibration library
    //unit: 1000 = 1x
    //data range: 0 ~ 60000
    //These parameter is the preference skin tone of face hue and saturation, which is after
    //applying AWB gain
    //There are 3 sets of reference target for hi, mid, low color temperature
    //i4TempoWeight is used for temporal smooth switch ref target, the formula is
    //  (Current Ref target + Temporal Ref target * Tempoweight) / (Tempoweight + 1)
    //  unit: N/A
    //  data range: 1 ~
    //variable name: rSceneJudge
    // (a)lv_low & lv_hi are LV threshold used for mid & Hi CT ref target
    //      interpolation
    //      (when LV is higher, the hi CT probabilirt is higher)
    //      unit: 10 = 1x
    //      data range: 0 ~ 180
    // (b)i4FaceRB_Low & i4FaceRB_Hi are face processed raw R/B threshold,
    //     which are used for mid & low CT ref target interpolation
    //     (when face R/B is higher, the low CT probability is higher)
    //      unit: 1000 = 1x
    //      data range: 0 ~
    /******************************************************************************/
                    1,    //enable
                    1,    //i4SatTargetEn
                    // i4RefTarget
                    {
                        32,    //i4RefHS_GThr Low
                        64,    //i4RefHS_GThr Mid
                        96,    //i4RefHS_GThr Hi
                        // RefHS_Low       RefHS_Mid       RefHS_High
                        {
                            {{   0,    0}, {   0,    0}, {   0,    0}},  // STROBE
                            {{18000, 40000}, {18000, 40000}, {18000, 40000}},  // TUNGSTEN
                            {{18000, 40000}, {18000, 40000}, {18000, 40000}},  // WARM FLUORESCENT
                            {{15000, 35000}, {15000, 35000}, {15000, 35000}},  // FLUORESCENT
                            {{15000, 35000}, {15000, 35000}, {15000, 35000}},  // CWF
                            {{15000, 35000}, {15000, 35000}, {15000, 35000}},  // DAYLIGHT
                            {{15000, 30000}, {15000, 30000}, {15000, 30000}},  // SHADE
                            {{15000, 35000}, {15000, 35000}, {15000, 35000}},  // DF
                        },
                        7,    //i4TempoWeight
                    },
                    // rSceneJudge
                    {
                          90,    //lv_low for Indoor & Outdoor dynamic
                         120,    //lv_hi for Indoor & Outdoor dynamic
                        -183,    //face_raw_xr_r_hm for Indoor Hi CT & Mid CT dynamic, Unit = 1000
                        -233,    //face_raw_xr_l_hm for Indoor Hi CT & Mid CT dynamic, Unit = 1000
                        -391,    //face_raw_xr_r_ml for Indoor Mid CT & Low CT dynamic, Unit = 1000
                        -491,    //face_raw_xr_l_ml for Indoor Mid CT & Low CT dynamic, Unit = 1000
                        -446,    //face_raw_yr_u for Indoor Greenish CT dynamic, Unit = 1000
                        -496     //face_raw_yr_d for Indoor Greenish CT dynamic, Unit = 1000
                    },
    /******************************************************************************/
    //Feature name:
    //When face hue & sat is close to target, face Pref strength will be reduced
    //variable name: rConvergeCtrl
    // (a)enable use to enable target converge control mechanism
    //    default value: 1
    //unit: N/A
    //data range: 0 and 1
    //    0 means although current face hue or sat is same with ref target, algo will still
    //    force generating new awb gain
    //    1 means if current face hue is close to ref target hue, the ratio will be reduced
    // (b)i4HueTOL target hue converge tolerance
    //    default value: 1000
    //    unit: 1000
    //    data range: 0 ~ 60000
    // (c)i4SatTOL target sat converge tolerance
    //    default value: 5000
    //    unit: 1000
    //    data range: 0 ~ 100000
    // (d)i4RestrictRatioTOL restrcit ratio converge tolerance
    //    default value: 500
    //    unit: 1000
    //    data range: 0 ~ 60000
    //variable name: rOversat
    // (a)rLV use LV to interpolate from lv_low to lv_hi to get Probability
    //    from i4OverSatProb_Low to i4OverSatProb_Hi
    //    unit: LV 10 = 1x, Prob = percentage
    //    data range: LV = 0 ~ 180, Prob = 0 ~ 100
    // (b)rHiCT use Hi CT Prob to interpolate from i4CT_P_Low to i4CT_P_Hi to
    //    get Probability from i4OverSatProb_Low to i4OverSatProb_Hi
    //    unit:  percentage
    //    data range: CT_P = 0 ~ 100, Prob = 0 ~ 100
    // (c)rMidCT use Mid CT Prob to interpolate from i4CT_P_Low to i4CT_P_Hi to
    //    get Probability from i4OverSatProb_Low to i4OverSatProb_Hi
    //    unit:  percentage
    //    data range: CT_P = 0 ~ 100, Prob = 0 ~ 100
    // (d)rLowCT use Hi CT Prob to interpolate from i4CT_P_Low to i4CT_P_Hi to
    //    get Probability from i4OverSatProb_Low to i4OverSatProb_Hi
    //    unit:  percentage
    //    data range: CT_P = 0 ~ 100, Prob = 0 ~ 100
    //Above parameters will choose the maximum for oversat probability. When
    //oversat probability is higher, the face Pref gain will be more bluish,
    //otherwise it will be more yellowish.
    //variable name: rUndersat
    // (a)stat_hi when face sat is lower than this threshold, undersat mechanism will start work
    //    and reduce oversat prob
    //    unit: N/A
    //    data range: 0 ~ 100000
    // (b)stat_low when face sat is lower than this threshold, undersat mechanism will be strongest
    //    unit: N/A
    //    data range: 0 ~ 100000
    // (c)new_restrict when face enter undersat condition, it also force increasing restrict ratio
    //    to this NewRestrict
    //    unit:  0.1%
    //    data range: 0 ~ 1000
    // (d)lv_low only when LV > lv_low - i4LVTOL and LV < lv_hi + i4LVTOL, the undersat mechanism will work
    //    unit:  LV 10 = 1x,
    //    data range: 0 ~ 180
    // (e)lv_hi as descibed in (d)
    //    unit:  LV 10 = 1x,
    //    data range: 0 ~ 180
    // (f)i4LVTOL oas descibed in (d)
    //    unit:  LV 10 = 1x,
    //    data range: 0 ~ 180
    //variable name: i4GainRatioRestrictLUT
    //Unit: 0.1%
    //data range: 0 ~ 1000
    //This LV LUT will restrict face awb gain can only change the normal awb gain
    //in specific percentage range. If this restrict percentage is higher, the
    //face awb effect will be more aggressive, but cause normal awb seriously
    //color bias and more non-smooth. If this restrict percentage is lower,
    //the face awb effect will be reduced, but more smoothly.
    //Face pref gain = Original AWB gain * Restrict Gain Ratio
    /******************************************************************************/
                    // rConvergeCtrl
                    {
                           1,    //enable
                        {1000, 4000},    //rTOL e.g If target hue = 19, so the range will be 18~20 (19-1 ~ 19+1)
                        { 250,  500}     //rRestrictRatio_TOL e.g If restric ratio = 50 means 5%, the hue restrict ratio tol will be 5*500 = 2500
                    },
                    // rOversat
                    {
                        // rLV
                        {
                              0,    //lv_low
                              0,    //lv_hi
                              0,    //i4OverSatProb_Low
                              0     //i4OverSatProb_Hi
                        },
                        // rHiCT
                        {
                              0,    //i4CT_P_Low
                              0,    //i4CT_P_Hi
                              0,    //i4OverSatProb_Low
                              0     //i4OverSatProb_Low
                        },
                        // rMidCT
                        {
                              0,    //i4CT_P_Low
                              0,    //i4CT_P_Hi
                              0,    //i4OverSatProb_Low
                              0     //i4OverSatProb_Hi
                        },
                        // rLowCT
                        {
                              0,    //i4CT_P_Low
                              0,    //i4CT_P_Hi
                              0,    //i4OverSatProb_Low
                              0     //i4OverSatProb_Hi
                        }
                    },
                    // rUndersat
                    {
                            0,    //stat_hi
                            0,    //stat_low
                           75,    //new_restrict
                           25,    //LVLow
                           95,    //LVHi
                           10     //LVRange
                    },
                    // i4GainRatioRestrictLUT
                    //LV-4  -3  -2  -1  0  1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18
                    {  0,  0,  0,  0, 10, 20, 25, 30, 30, 30, 40, 40, 40, 40, 40, 40, 40, 40, 30, 30, 20, 10, 10},
    /******************************************************************************/
    //Feature name:
    //A set of gain applied after face awb algorithm calculation output gain based
    //on LV, just like normal awb preference gain LUT. It is used to optimize and
    //fine tune, but if it is set too aggressive might cause face Pref not smooth.
    //variable name: {i4R, i4G, i4B} gain table from LV0 to LV18.
    //default value: {512, 512, 512}
    //unit: 512 = 1x
    //data range: 0 ~ 4096
    /******************************************************************************/
                    // pref_gain
                    {
                      //    LV0             LV1             LV2             LV3             LV4             LV5             LV6             LV7             LV8             LV9
                      {512, 512, 512},{512, 512, 512},{512, 512, 517},{517, 512, 512},{512, 512, 512},{512, 512, 512},{512, 512, 512},{512, 512, 512},{512, 512, 512},{512, 512, 512},
                      //     LV10            LV11            LV12            LV13            LV14            LV15            LV16            LV17            LV18
                      {512, 512, 512},{512, 512, 512},{512, 512, 512},{512, 512, 512},{512, 512, 500},{512, 517, 514},{512, 512, 512},{512, 512, 512},{512, 512, 512},
                    },
    /******************************************************************************/
    //Feature name:
    //Get face probability
    // (a)rProb0 is refering face size compare to 120x90. If face size ratio
    //    is higher, the face prob0 must be higher. It uses face size ratio to
    //    interpolate from i4FaceSizeRatioLow to i4FaceSizeRatioHi to get
    //    Probability0 from i4Prob0_Min to i4Prob0_Max.
    //    unit: size ratio = percentage*1000, Prob0 = percentage
    //    data range: size ratio 0 ~ 100000, Prob0 0 ~ 100
    // (b)rProb1 is a LV LUT in 3 kinds of CT for face probability1.
    //    unit: percentage
    //    data range: 0 ~ 100
    // (c)rProb2 is refering face processed raw R/G information. If the R/G
    //    is out of range, the face prob2 must be reduced. It uses face processed
    //    raw to interpolate from i4FaceRG_Low to (i4FaceRG_Low - i4FaceRG_TOL)
    //    or interpolate from i4FaceRG_Hi to (i4FaceRG_Hi + i4FaceRG_TOL)
    //    to get probability2 from i4Prob2_Max to i4Prob2_Min.
    //    unit: R/G 1000 = 1x, Prob = percentage
    //    data range: R/G N/A, Prob 0 ~ 100
    // (d)rProb3 is totally same with rProb2, just change to refer
    //    face processed raw B/G information.
    // (e)rProb4 is totally same with rProb2, just change to refer
    //    face processed raw G information.
    //Face probability = face Prob0 * face Prob1 * face Prob2 * face Prob3 * face Prob4
    //Face pref target gain = ((original AWB gain * (1 - face Probability)) +
    //                        (face pref gain * face Probability)) / 100
    /******************************************************************************/
                    // rProb0
                    {
                        3900,    //i4FaceSizeRatioLow
                        6100,    //i4FaceSizeRatioHi
                           0,    //i4Prob0_Min
                         100     //i4Prob0_Max
                    },
                    // rProb1
                    {
                        {
                            //LV 0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18
                            {   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0}, // STROBE
                            {  50,  75, 100, 100, 100, 100, 100, 100, 100, 90, 100, 100, 100, 100, 100, 100,  80,  60,  40}, // TUNGSTEN
                            {  50,  75, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  80,  60,  40}, // WARM FLUORESCENT
                            {  50,  75, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  80,  60,  40}, // FLUORESCENT
                            {  50,  75, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  80,  60,  40}, // CWF
                            {  50,  75, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  80,  60,  40}, // DAYLIGHT
                            {  50,  75, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  80,  60,  40}, // SHADE
                            {  50,  75, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  80,  60,  40}, // DF
                        }
                    },
                    // rProb2
                    {
                         650,    //i4FaceRG_Low Unit=1000
                        1200,    //i4FaceRG_Hi Unit=1000
                         500,    //i4FaceRG_Range Unit=1000
                           0,    //i4Prob2_Min
                         100     //i4Prob2_Max
                    },
                    // rProb3
                    {
                         250,    //i4FaceBG_Low Unit=1000
                         800,    //i4FaceBG_Hi Unit=1000
                         500,    //i4FaceBG_Range Unit=1000
                           0,    //i4Prob3_Min
                         100     //i4Prob3_Max
                    },
                    // rProb4
                    {
                           0,    //i4FaceG_Low Unit=1000
                           0,    //i4FaceG_Hi Unit=1000
                           0,    //i4FaceG_Range Unit=1000
                         100,    //i4Prob4_Min
                         100     //i4Prob4_Max
                    },
    /******************************************************************************/
    //Feature name: rSpatial
    //Face spatial compensation when face size is small and neutral parent block
    //number is very few.
    // (a)rP0 is refering face size compare to 120x90. If face size ratio
    //    is higher, the spatial prob0 will be lower. It uses face size ratio to
    //    interpolate from i4FaceSizeRatioHi to i4FaceSizeRatioLow to get
    //    Probability0 from i4Prob0_Min to i4Prob0_Max.
    //    unit: size ratio = percentage*1000, Prob0 = percentage
    //    data range: size ratio 0 ~ 100000, Prob0 0 ~ 100
    // (b)rP1 is refering whole image neutral parent block number, except
    //    face area. If neutral parent block num is higher, the spatial prob1 will
    //    be lower. It uses neutral parent block number to interpolate from
    //    i4NeutralParentBlkNum_Hi to i4NeutralParentBlkNum_Low to get Probability1
    //    from i4Prob1_Min to i4Prob1_Max.
    //    unit: neutral parent block num = N/A, Prob1 = percentage
    //    data range: neutral parent block num 0 ~ 120*90, Prob1 0 ~ 100
    // (c)lv_low & lv_hi are used for awb spatial gain caculation. It is
    //    interpolated from i4LV_Low to i4LV_LHi to get face awb spatial gain from
    //     DaylightLocus_L to DaylightLocus_H.
    //    unit: 10 = 1x
    //    data range: 0 ~ 180
    //Face spatial probability = spatial Prob0 * spatial Prob1
    //Face pref target gain = ((face pref target gain * (1 - face spatial probability)) +
    //                        (face pref spatial gain * face spatial Probability)) / 100
    /******************************************************************************/
                    // rSpatial
                    {
                        // rP0
                        {
                            3900,    //i4FaceSizeRatioHi  Unit=1000
                             500,    //i4FaceSizeRatioLow Unit=1000
                               0,    //i4Prob0_Min
                               0     //i4Prob0_Max
                        },
                        // rP1
                        {
                              75,    //i4NeutralParentBlkNum_Hi
                              15,    //i4NeutralParentBlkNum_Low
                               0,    //i4Prob1_Min
                               0     //i4Prob1_Max
                        },
                         70,    //lv_low
                        110     //lv_hi
                     },
    /******************************************************************************/
    //Feature name:
    //variable name: portrait used when face gone.
    // (a)enable is used to enable portrait mechanism if the DL is also enalbe
    //    unit: N/A
    //    data range: 0 and 1
    // (b)i4NoPortraitTh is used for judge portrait is exist or not
    //    If portrait already exists, the portrait value only need to bigger than this thr,
    //    then portrait will be considerd still exist
    //    unit: N/A
    //    data range: N/A
    // (c)i4IsPortraitTh is used for judge portrait is exist or not
    //    If portrait appear in this frame, the portrait value need to bigger than this thr,
    //    then portrait will be considerd exist
    //    unit: N/A
    //    data range: N/A
    // (d)i4FrameDelay is used for delay reduceing face prob
    //    If FrameDelay is 3, which means that every 3 frame will reduce face prob one time
    //    unit: N/A
    //    data range: 0 ~
    //variable name: rGender used to change ref target when there is female in image.
    // (a)enable is used to enable gender mechanism if the DL is also enalbe
    //    unit: N/A
    //    data range: 0 and 1
    // (b)i4TargetHueOFS is the target hue offset for female exist in image
    //    unit: N/A
    //    data range: -60000 ~ 60000
    // (c)i4TargetSatOFS is the target sat offset for female exist in image
    //    unit: N/A
    //    data range: -100000 ~ 100000
    // (d)i4OversatProbRatio forcing change oversat prob when female exist in image
    //    unit: N/A
    //    data range: 0 ~ 100000
    /******************************************************************************/
                    // portrait
                    {
                            0,   //enable
                        -3000,   //i4NoPortraitTh
                            0,   //i4IsPortraitTh
                            3    //i4FrameDelay
                    },
                    // rGender
                    {
                            0,   //enable
                        {-2000,-2000},   //rTargetOFS
                         1200    //i4OversatProbRatio
                    }
                },
    /******************************************************************************/
    //Feature name:
    //Face Assisted AWB refer face information to assist normal AWB prediction.
    //Especially for confusing scene with face
    /******************************************************************************/
                // Face Assisted AWB
                {
    /******************************************************************************/
    //Feature name:
    //Face Assisted AWB Algorithm Basic Control
    //variable name: enable
    //  default value: 0
    //  unit: N/A
    //  data range: 0 and 1
    //  0 means disable face assisted AWB
    //  1 means enable face assisted AWB
    //variable name: tol
    //  description: tolerance range for every light source
    //  default value: 0
    //  unit: XrYr domain unit
    //  data range: 0 ~
    //variable name: rRefTarget
    //  description: user predefined setting of reference target
    //               support three difference value of ref. target position for more flexible use
    //  default value: default setting could calibration by color patch of color chart
    //  unit: XrYr domain unit
    //  data range: 0 ~
    //variable name: pref_gain
    //  description: preference gain(Rgain, Bgain) for face predictor gain by light source
    //  default value: {512, 512}
    //  unit: 1X = 512
    //variable name: rProb0
    //  description: face assisted probability by face-size ratio
    //  unit: size ratio = percentage*1000, Prob0 = percentage
    //  data range: size ratio 0 ~ 100000, Prob0 0 ~ 100
    //variable name: rProb1
    //  description: face assisted probability by environment brightness LV for each light source
    //  unit: percentage
    //  data range: 0 ~ 100
    //variable name: rProb2
    //  description: face assisted probability by Y-bias offset from face reference target
    //  unit: reduce retio
    //  data range: 1X = 256
    //variable name: rProb3
    //  description: face assisted probability by temporal information
    //               if face is detected and stable, probability will increase with time
    //    i4StableConfLow/Hi
    //      unit: frame number
    //      data range: 0 ~
    //    i4ProbMin/i4ProbMax
    //      unit: percentage
    //      data range: 0 ~ 100
    //variable name: rProb4
    //  description: face assisted probability by valid face-color ratio if statistic-NR is enable
    //    i4FaceColorRationLow/Hi
    //      unit: ratio by 1X = 1000
    //      data range: 0 ~ 1000
    //    i4ProbMin/i4ProbMax
    //      unit: percentage
    //      data range: 0 ~ 100
    //variable name: rCompSetting
    //  description: compensation ratio by face assisted algorithm
    //variable name: rStableSetting
    //  description: Stable setting for temporal smooth of face-assisted algo.
    //  i4TempoWeight - weighting factor for blending current FaceXY with previous frame,
    //  i4DelayFrm - weighting factor for blending current FaceXY with previous frame, unit: frame number
    /******************************************************************************/
                    1,    //enable
                    { //tol
                        32,    //STROBE
                        36,    //HORIZON
                        36,    //A
                        32,    //TL84
                        30,    //CWF
                        28,    //DNP
                        24,    //D65
                        24,    //DF
                    },
                    //rRefTarget - Reference Target Setting
                    {
                          1,    //i4Mode
                        100,    //i4WeightCoef_a
                        100,    //i4WeightCoef_b
                        // i4RefTargetThr
                        {
                             32,    //ThrLow
                             64,    //ThrMid
                             96,    //ThrHigh
                        },
                        // i4RefTargetThr
                        {
                            // Ref_Low       Ref_Mid       Ref_High
                            {{4095, 4095}, {4095, 4095}, {4095, 4095}},  // STROBE
                            {{-675, -313}, {-675, -313}, {-675, -343}},  // HORIZON
                            {{-552, -348}, {-552, -348}, {-552, -348}},  // A
                            {{-365, -466}, {-365, -466}, {-365, -466}},  // TL84
                            {{-328, -567}, {-328, -567}, {-328, -567}},  // CWF
                            {{-277, -406}, {-277, -406}, {-277, -406}},  // DNP
                            {{-141, -369}, {-141, -369}, {-141, -369}},  // D65
                            {{ -65, -529}, {-65, -529},  { -65, -529}},  // DF
                        },
                    },
                    //pref_gain for Predictor Gain
                    {
                        { 512,  512}, // STROBE
                        { 512,  512}, // HORIZON
                        { 512,  512}, // A
                        { 512,  512}, // TL84
                        { 512,  512}, // CWF
                        { 512,  512}, // DNP
                        { 512,  512}, // D65
                        { 512,  512}, // DF
                    },
                    //rProb0 - Face Size
                    {
                        3200,  // i4FaceSizeRatioLow
                        6000,  // i4FaceSizeRatioHi
                           0,  // i4ProbMin
                         100,  // i4ProbMax
                    },
                    //rProb1 - LV
                    {
                        { //Non-neutral P1 table for spatial and temporal weighting look-up table
                            //LV 0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18
                            {  20,  50,  75, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  80,  60,  40,  20}, // NonNeutral
                        },
                        {
                            //LV 0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18
                            {   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1}, // STROBE
                            {  50,  75, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  80,  60,  40}, // TUNGSTEN
                            {  50,  75, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  80,  60,  40}, // WARM FLUORESCENT
                            {  50,  75, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  80,  60,  40}, // FLUORESCENT
                            {  50,  75, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  80,  60,  40}, // CWF
                            {  50,  75, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  80,  60,  40}, // DAYLIGHT
                            {  50,  75, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  80,  60,  40}, // SHADE
                            {  50,  75, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  80,  60,  40}, // DF
                        }
                    },
                    //rProb2
                    {
                        { //High-CT
                          //   0    25   50   75  100  125  150  175  200  225  250
                            { 256, 256, 256, 256, 256, 240, 212, 164, 112,  64,  16 }, // Magenta
                            { 256, 256, 256, 256, 256, 240, 212, 164, 112,  64,  16 }, // Green
                        },
                        { //Mid-CT
                          //   0    25   50   75  100  125  150  175  200  225  250
                            { 256, 256, 256, 256, 256, 240, 212, 164, 112,  64,  16 }, // Magenta
                            { 256, 256, 256, 256, 256, 240, 212, 164, 112,  64,  16 }, // Green
                        },
                        { //Low-CT
                          //   0    25   50   75  100  125  150  175  200  225  250
                            { 256, 256, 256, 240, 220, 180, 128,  80,  40,  16,   4 }, // Magenta
                            { 256, 256, 256, 256, 256, 240, 212, 164, 112,  64,  16 }, // Green
                        }
                    },
                    //rProb3
                    {
                           5,  // i4StableConfLow
                          40,  // i4StableConfHi
                           0,  // i4ProbMin
                         100,  // i4ProbMax
                    },
                    //rProb4
                    {
                         200,  // i4FaceColorRatioLow
                         800,  // i4FaceColorRatioHi
                           0,  // i4ProbMin
                         100,  // i4ProbMax
                    },
                    //rCompSetting
                    {
                        //rConfThr
                        {
                              0,  // i4ThrL
                            100,  // i4ThrH
                        },
                        //rDistanceThr
                        {
                             50,  // i4Low
                            180,  // i4Mid
                            300,  // i4High
                        },
                        //rCompRatio
                        {
                              10,  // i4Low
                             20,  // i4Mid
                             20,  // i4High
                        },
                    },
                    // rStableSetting
                    {
                          7,  // i4TempoWeight
                          8,  // i4DelayFrm
                    },
                    // rAdvSetting
                    {
                          1,  // i4DistType for distance calculation, 0: Using EqvXY, 1: Using CurrXY
                          0,  // i4Resv02
                          0,  // i4Resv03
                          0,  // i4Resv04
                          0,  // i4Resv05
                          0,  // i4Resv06
                    }
                },
                // Smooth Statistic
                {
                    1,    //enable
                    {0, 27, 27, 27, 27, 27, 27, 27},  //i4StatWinShrinkOffset
                    0,    //Reserved1
                    0,    //Reserved2
                    0,    //Reserved3
                    0,    //Reserved4
                    0,    //Reserved5
                },
                // Panel Damping Prevention
                {
    /******************************************************************************/
    //Feature name:
    //Panel damping causes color abnormal prevention mechanism
    //variable name: enable
    //default value: 0
    //unit: N/A
    //data range: 0 and 1
    //0 means disable Panel damping mechanism
    //1 means enable Panel damping mechanism
    //variable name: rP0
    // (a)i4PBRatioH & i4PBRatioL is Neutral PB threshold for P0 calculating
    //     When neutral PB is smaller than TotalPBNum*i4PBRatioH, P0 will begin to increase
    //     When neutral PB is smaller than TotalPBNum*i4PBRatioL, P0 will be 100
    //      unit: percent
    //      data range: 0 ~ 100
    // (b)i4ErrCntRatioL & i4ErrCntRatioH is the error count threshold for reducing P0
    //     When error count is over than 120*90*i4ErrCntRatioL, P0 will begin to decrease
    //     When error count is over than 120*90*i4ErrCntRatioH, P0 be 0
    //      unit: percent
    //      data range: 0 ~ 100
    // (c)i4RefineP1L & i4RefineP1H is P1 threshold for increasing P0
    //     When P1 is over than i4RefineP1L, P0 will begin to increase
    //     When P1 is over than i4RefineP1H, P0 be 100
    //      unit: N/A
    //      data range: 0 ~ 100
    //variable name: rScene
    // (a)lv is LV threshold that panel luma won't over this value
    //      unit: 10 = 1x
    //      data range: 0 ~ 180
    // (b)rTrigger is the condition that it will trigger this mechanism
    //     Y value must over than i4YDiffTh, and R gain diff ratio must higher than
    //     i4RgainDiffRatioTh
    //      unit: N/A
    //      data range: i4YDiffTh => 0 ~ 255, i4RgainDiffRatioTh => 0 ~
    // (c)i4TrackingYDiffTh is used for that when panel damping has been detected (Tracking mode),
    //     Y value must over than i4TrackingYDiffTh
    //      unit: N/A
    //      data range: 0 ~ 255
    //variable name: strength
    // (a)i4XYDiffLow & i4XYDiffHi are thresholds that refine this mechanism strength
    //     from Max1 to Max2
    //     When Frm XY diff from D65 is over than i4XYDiffLow, strength will begin increase from Max1
    //     When Frm XY diff from D65 is over than i4XYDiffHi, strength will be Max2
    //      unit: N/A
    //      data range: 0 ~
    // (b)gain is the strength to hybrid original AWB gain & Frm WB gain (limit the Prob)
    //      unit: percent
    //      data range: 0 ~ 100
    // (c)rSpeed is the strength to increase AWB converge speed (limit the Prob)
    //      unit: percent
    //      data range: 0 ~ 100
    /******************************************************************************/
                      0,    //enable
                    // rP0
                    {
                         50,    //i4PBRatioH
                         25,    //i4PBRatioL
                         70,    //i4ErrCntRatioL
                         80,    //i4ErrCntRatioH
                         75,    //i4RefineP1L
                         90,    //i4RefineP1H
                    },
                    // rScene
                    {
                         70,    //lv
                        // rTrigger
                        {
                             30,    //i4YDiffTh
                             20,    //i4RgainDiffRatioTh
                        },
                         20,    //i4TrackingYDiffTh
                    },
                    // strength
                    {
                         500,    //i4XYDiffLow
                         750,    //i4XYDiffHi
                        // gain
                        {
                             50,    //i4Max1
                             75,    //i4Max2
                        },
                        // rSpeed
                        {
                             50,    //i4Max1
                             75,    //i4Max2
                        },
                    },
                    // rSatRatioCtrl
                    {
                          0,    //i4Ratio1
                          0,    //i4Ratio2
                          0,    //i4ProbLow
                          0,    //i4ProbHi
                    },
                    // rRsv
                    {
                          0,    //Reserved1
                          0,    //Reserved2
                          0,    //Reserved3
                          0,    //Reserved4
                          0,    //Reserved5
                          0,    //Reserved6
                          0,    //Reserved7
                    },
                },
            },
    /******************************************************************************/
    //Feature name:
    //AWB chip dependent parameter
    //variable name: i4AWBGainOutputScaleUnit
    //It is used for AWB output gain normailization, please do not modify it.
    //default value: 512
    //unit: 512 = 1x
    //variable name: i4AWBGainOutputUpperLimit
    //Maximum AWB gain is ~16x, it is hardware limitation. Please do not modify it.
    //default value: 8191
    //unit: 512 = 1x
    //variable name: i4RotationMatrixUnit
    //AWB rotation matrix unit. Please do not modify it.
    //default value: 256
    //unit: 256 = 1x
    /******************************************************************************/
            // Chip dependent parameter
            {
                 512, // i4AWBGainOutputScaleUnit: 1.0x = 512
                 8191, // i4AWBGainOutputUpperLimit: format 4.9 (11 bit)
                 256  // i4RotationMatrixUnit: 1.0x = 256
            },
    /******************************************************************************/
    //Feature name:
    //Statistic data weighting function.
    //
    //variable name: i4Mode
    //default value: 1
    //data range: 0 to 3
    //0 means disable weighting function
    //1 means enable : Weight = 1+((SumR+SumG+SumB)/ChildBlkNum)/2^(i4ScalingFactor)
    //2 means enable : Weighting LUT. Weight = i4WeightLut(i4GammaLut((SumR+SumG+SumB)/ChildBlkNum))
    //                 For different color temperature : Low:T,WF; Middle:F,CWF; High:D65,DF,Shade
    //3 means enable : Weighting LUT. Weight = i4WeightLut(i4GammaLut((SumR+SumG+SumB)/ChildBlkNum))
    //                 For different LV : Low; Middle; High
    //varaiable name: i4ScalingFactor
    //default value: 6
    //data range: 6~10
    //6 means Wieght will be 1~12
    //7 means Weight will be 1~6
    //8 means Weight will be 1~3
    //9 means Weight will be 1~2
    //9 means Weight will be 1~2
    //10 means Weight will be 1
    //varaiable name: i4GammaLut[17]
    //data range: 0 to 256
    //varaiable name: i4WeightLut[3][17]
    //data range: 1 to 15
    /******************************************************************************/
            // Parent block weight parameter
            {
                3, // i4Mode : 0:Disable 1:Linear weighting 2:Weighting LUT
                8, // i4ScalingFactor: [6] 1~12, [7] 1~6, [8] 1~3, [9] 1~2, [>=10]: 1
                { 20,  70, 120}, // i4LvThld[3]
                // i4GammaLut[17]
                {0, 64, 90, 111, 128, 143, 156, 169, 181, 192, 202, 212, 221, 230, 239, 247, 256},
                // i4WeightLut[3][17] : Low, Middle, High
                {
                    {1, 2, 9, 10, 10, 10, 10, 9, 9, 9, 8, 8, 7, 7, 7, 6, 6},
                    {2, 5, 9, 10, 10, 10, 10, 9, 9, 9, 8, 8, 7, 7, 7, 6, 6},
                    {2, 5, 9, 10, 10, 10, 10, 9, 9, 9, 8, 8, 7, 7, 7, 6, 6},
                 },
                0, // i4NonneutralPBMode : 0:use non-neutral PB sum 1: use all PB sum
            },
    /******************************************************************************/
    //Feature name:
    //AWB behavior control for one-shot capture for dark environment
    //variable name: bSmoothEnable
    //default value: 0
    //data range: 0 and 1, 0 means false and 1 means true
    //MFALSE means disable smooth one-shot AWB for dark environment: use preview AWB gain directly
    //MTRUE means enable smooth one-shot AWB for dark environment: take weighted average of one-shot AWB gain and
    //preview AWB gain based on scene LV
    //variable name: i4LVThrL
    //take preview AWB gain only when scene LV <= i4LVThrL
    //default value: N/A
    //data range: 0 ~ 180
    //variable name: i4LVThrH
    //take one-shot AWB gain only when scene LV >= i4LVThrH
    //default value: N/A
    //data range: 0 ~ 180
    //It perform interpolation when i4LVThrH > LV > i4LVThrL
    /******************************************************************************/
            // One-shot AWB parameter
            {
                0, // bSmoothEnable
                10, // i4LVThrL
                50  // i4LVThrH
            },
    /******************************************************************************/
    //Feature name:
    //MWB window size in Xr Yr domain to control the white point window size
    //variable name: i4WindowSizeX
    //default value: 32
    //variable name: i4WindowSizeY
    //default value: 32
    /******************************************************************************/
            // MWB parameter
            {
                32, //i4WindowSizeX
                32  //i4WindowSizeY
            },
    /******************************************************************************/
    //Feature name:
    //HDR function
    //variable name: i4VammaEn
    //Enable Vgamma in HDR mode 
    //default value: 0
    /******************************************************************************/
            // HDR parameter
            {
                0, //i4VgammaEn
            },
    /******************************************************************************/
    //Feature name:
    //Misc function
    //variable name: i4CctGainSel
    //Estimate CCT according to AWB gain. 0: AWB gain 1: AWB full gain 2: AWB gain without preference
    //default value: 0
    //variable name: i4StrobePbReduceX
    //Reduce parent block window X size during strobe
    //default value: 0
    //variable name: i4StrobePbReduceY
    //Reduce parent block window Y size during strobe
    //default value: 0
    /******************************************************************************/
            // Misc parameter
            {
                2, //i4CctGainSel
                0, //i4StrobePbReduceX
                0  //i4StrobePbReduceY
            },
    /******************************************************************************/
    //Feature name:
    //AWB tuning basic information
    //variable name: i4ProjCode
    //default value: N/A
    //representation of chip code
    //variable name: mode1
    //default value: N/A
    //variable name: i4Data
    //default value: N/A
    /******************************************************************************/
            // AWB tuning information
            {
                 0, // i4ProjCode
                 0, // i4Model
                 2103101000, // i4Date
                 204310010, // i4Res0
                 0, // i4Res1
                 0, // i4Res2
                 0, // i4Res3
                 0, // i4Res4
            }
        },
    },
};
