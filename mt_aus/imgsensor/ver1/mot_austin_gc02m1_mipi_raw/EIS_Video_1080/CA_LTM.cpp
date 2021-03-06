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

#define CA_LTM_BASE                                                  CA_LTM_CA_LTM_BASE

const FEATURE_NVRAM_CA_LTM_T CA_LTM_BASE[1] = {
    // IDX_0
    {
        .ISO = {3, 600, 2300, 4000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        .LV = {3, 2, 6, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        .CA_LTM_ALLTUNINGREG ={
            {   //00
                .CA_LTM_INITUNINGRE  = { //ISO600,LV2
                    .ca_ltm_s_lower = 0x18,
                    .ca_ltm_s_upper = 0x23,
                    .ca_ltm_y_lower = 0x46,
                    .ca_ltm_y_upper = 0x88,
                    .ca_ltm_h_lower = 0x55,
                    .ca_ltm_h_upper = 0x5C,
    
                    .ca_ltm_max_hist_mode               = 1,
                    .ca_ltm_bitplus_contour_range_th    = 0x2,
                    .ca_ltm_bitplus_contour_range_slope = 0x40,
                    .ca_ltm_bitplus_diff_count_th       = 0x3,
                    .ca_ltm_bitplus_diff_count_slope    = 0x2A,
                    .ca_ltm_bitplus_pxl_diff_th         = 0x0,
                    .ca_ltm_bitplus_pxl_diff_slope      = 0x40,
    
                    .ca_ltm_pxl_diff_th_for_flat_pxl    = 0x0,
                    .ca_ltm_pxl_diff_slope_for_flat_pxl = 0x20,
    
                    .ca_ltm_pxl_diff_th                 = 0x0,
                    .ca_ltm_pxl_diff_slope              = 0x10,
    
                    .ca_ltm_s_lower2 = 0x8,
                    .ca_ltm_s_upper2 = 0x14,
                    .ca_ltm_y_lower2 = 0x46,
                    .ca_ltm_y_upper2 = 0xB0,
                    .ca_ltm_h_lower2 = 0x7D,
                    .ca_ltm_h_upper2 = 0x91,
    
                    .ca_ltm_s_lower3 = 0x18,
                    .ca_ltm_s_upper3 = 0x23,
                    .ca_ltm_y_lower3 = 0x46,
                    .ca_ltm_y_upper3 = 0x88,
                    .ca_ltm_h_lower3 = 0x55,
                    .ca_ltm_h_upper3 = 0x5C,
    
                    .ca_ltm_h_slope = 4,
                    .ca_ltm_s_slope = 4,
                    .ca_ltm_y_slope = 4,
                    .ca_ltm_h_slope2 = 4,
                    .ca_ltm_s_slope2 = 4,
                    .ca_ltm_y_slope2 = 4,
                    .ca_ltm_h_slope3 = 4,
                    .ca_ltm_s_slope3 = 4,
                    .ca_ltm_y_slope3 = 4,
    
                    .bilateral_flt_en = 1,
                    .bilateral_impulse_noise_en = 1,
                    .bilateral_range_flt_slope = 1,
                    .dre_bilateral_blending_wgt = 2,
                    .dre_bilateral_blending_en = 1,
                    .dre_bilateral_detect_en = 1,
                    .have_bilateral_filter = 1,
                },
    
                .CA_LTM_TUNINGREG = {
                    .ca_ltm_fw_en           = 1,
                    .ca_ltm_curve_en        = 1,
                    .ca_ltm_gain_flt_en     = 0,
                    .ca_ltm_iir_force_range = 1,
    
                    // Histogram FIR Weight
                    .bADLWeight1 = 0x14,
                    .bADLWeight2 = 0x2C,
                    .bADLWeight3 = 0x00,
    
                    // BS Basic Param
                    .bBSDCGain = 0x10,
                    .bBSACGain = 0x80,
                    .bBSLevel  = 0x0,
    
                    // Mid Param
                    .bMIDDCGain = 0x04,
                    .bMIDACGain = 0x06,
    
                    // WS Basic Param
                    .bWSDCGain = 0x10,
                    .bWSACGain = 0x80,
                    .bWSLevel  = 0x0,
    
                    // Spike Fallback Protection
                    .ca_ltm_dync_spike_wgt_min = 0x0,
                    .ca_ltm_dync_spike_wgt_max = 0x0,
                    .ca_ltm_dync_spike_th      = 0x90,
                    .ca_ltm_dync_spike_slope   = 0x40,
                    .bSpikeBlendmethod      = 0x2,
    
                    // Skin processing
                    .bSkinWgtSlope    = 0x80,
                    .bSkinBlendmethod = 0x2,
    
                    // Temporal Filtering
                    .ca_ltm_dync_flt_coef_min      = 0x8,
                    .ca_ltm_dync_flt_coef_max      = 0x20,
                    .ca_ltm_dync_flt_ovr_pxl_th    = 0x4,
                    .ca_ltm_dync_flt_ovr_pxl_slope = 0x32,
    
                    // Low Level Protection
                    .LLPValue = 0x0,
                    .LLPRatio = 0x0,
    
                    // APL Compensation
                    .APLCompRatioLow  = 0xC8,
                    .APLCompRatioHigh = 0xC8,
    
                    // Local Wgt1
                    .FltConfSlope = 0x2EE,
                    .FltConfTh    = 0xC8,
    
                    // Local Wgt2
                    .BlkHistCountRatio = 0x3,
                    .BinIdxDiffSlope   = 0xE0,
                    .BinIdxDiffTh      = 0x0,
                    .BinIdxDiffWgtOft  = 0x20,
                    .APLTh             = 0x10,
                    .APLSlope          = 0x80,
                    .APLWgtOft         = 0x100,
    
                    // Global APL Adjustment
                    .APL2Th     = 0x10,
                    .APL2Slope  = 0x80,
                    .APL2WgtOft = 0x100,
                    .APL2WgtMax = 0x100,
    
                    // Block Spatial Filtering
                    .BlkSpaFltEn   = 1,
                    .BlkSpaFltType = 0x0,
    
                    // for Tuning Tool Only
                    .LoadBlkCurveEn = 0,
                    .SaveBlkCurveEn = 0,
    
                    // Grass Protection
                    .bGreenWgtSlope = 0x25,
                    .dre_dync_compact_wgt_min = 0x0,
                    .dre_dync_compact_wgt_max = 0xFF,
                    .dre_dync_compact_th = 0x80,
                    .dre_dync_compact_slope = 0x20,
                    .bCompactBlendmethod = 0x2,
                    .dre_dync_compact_LowBoundBin = 0x5,
                    .dre_dync_compact_HighBoundBin = 0x7,
                    .dre_dync_compact_BinMinWeight = 0x100,
                    .dre_dync_compact_BinMaxWeight = 0x280,
                },
    
                .CA_LTM_ADAPTTUNINGREG = {
                    .Enabled = 1,
                    .Strength = 255,
                    .AdaptiveMethod = 0,
                    .AdaptiveType = 0,
                    .CustomParametersSearchMode = 0,
                },
            },
            {   //01
                .CA_LTM_INITUNINGRE  = { //ISO2300,LV2
                    .ca_ltm_s_lower = 0x18,
                    .ca_ltm_s_upper = 0x23,
                    .ca_ltm_y_lower = 0x46,
                    .ca_ltm_y_upper = 0x88,
                    .ca_ltm_h_lower = 0x55,
                    .ca_ltm_h_upper = 0x5C,
    
                    .ca_ltm_max_hist_mode               = 1,
                    .ca_ltm_bitplus_contour_range_th    = 0x2,
                    .ca_ltm_bitplus_contour_range_slope = 0x40,
                    .ca_ltm_bitplus_diff_count_th       = 0x3,
                    .ca_ltm_bitplus_diff_count_slope    = 0x2A,
                    .ca_ltm_bitplus_pxl_diff_th         = 0x0,
                    .ca_ltm_bitplus_pxl_diff_slope      = 0x40,
    
                    .ca_ltm_pxl_diff_th_for_flat_pxl    = 0x0,
                    .ca_ltm_pxl_diff_slope_for_flat_pxl = 0x20,
    
                    .ca_ltm_pxl_diff_th                 = 0x0,
                    .ca_ltm_pxl_diff_slope              = 0x10,
    
                    .ca_ltm_s_lower2 = 0x8,
                    .ca_ltm_s_upper2 = 0x14,
                    .ca_ltm_y_lower2 = 0x46,
                    .ca_ltm_y_upper2 = 0xB0,
                    .ca_ltm_h_lower2 = 0x7D,
                    .ca_ltm_h_upper2 = 0x91,
    
                    .ca_ltm_s_lower3 = 0x18,
                    .ca_ltm_s_upper3 = 0x23,
                    .ca_ltm_y_lower3 = 0x46,
                    .ca_ltm_y_upper3 = 0x88,
                    .ca_ltm_h_lower3 = 0x55,
                    .ca_ltm_h_upper3 = 0x5C,
    
                    .ca_ltm_h_slope = 4,
                    .ca_ltm_s_slope = 4,
                    .ca_ltm_y_slope = 4,
                    .ca_ltm_h_slope2 = 4,
                    .ca_ltm_s_slope2 = 4,
                    .ca_ltm_y_slope2 = 4,
                    .ca_ltm_h_slope3 = 4,
                    .ca_ltm_s_slope3 = 4,
                    .ca_ltm_y_slope3 = 4,
    
                    .bilateral_flt_en = 1,
                    .bilateral_impulse_noise_en = 1,
                    .bilateral_range_flt_slope = 1,
                    .dre_bilateral_blending_wgt = 2,
                    .dre_bilateral_blending_en = 1,
                    .dre_bilateral_detect_en = 1,
                    .have_bilateral_filter = 1,
                },
    
                .CA_LTM_TUNINGREG = {
                    .ca_ltm_fw_en           = 1,
                    .ca_ltm_curve_en        = 1,
                    .ca_ltm_gain_flt_en     = 0,
                    .ca_ltm_iir_force_range = 1,
    
                    // Histogram FIR Weight
                    .bADLWeight1 = 0x14,
                    .bADLWeight2 = 0x2C,
                    .bADLWeight3 = 0x00,
    
                    // BS Basic Param
                    .bBSDCGain = 0x10,
                    .bBSACGain = 0x80,
                    .bBSLevel  = 0x0,
    
                    // Mid Param
                    .bMIDDCGain = 0x04,
                    .bMIDACGain = 0x06,
    
                    // WS Basic Param
                    .bWSDCGain = 0x10,
                    .bWSACGain = 0x80,
                    .bWSLevel  = 0x0,
    
                    // Spike Fallback Protection
                    .ca_ltm_dync_spike_wgt_min = 0x0,
                    .ca_ltm_dync_spike_wgt_max = 0x0,
                    .ca_ltm_dync_spike_th      = 0x90,
                    .ca_ltm_dync_spike_slope   = 0x40,
                    .bSpikeBlendmethod      = 0x2,
    
                    // Skin processing
                    .bSkinWgtSlope    = 0x80,
                    .bSkinBlendmethod = 0x2,
    
                    // Temporal Filtering
                    .ca_ltm_dync_flt_coef_min      = 0x8,
                    .ca_ltm_dync_flt_coef_max      = 0x20,
                    .ca_ltm_dync_flt_ovr_pxl_th    = 0x4,
                    .ca_ltm_dync_flt_ovr_pxl_slope = 0x32,
    
                    // Low Level Protection
                    .LLPValue = 0x0,
                    .LLPRatio = 0x0,
    
                    // APL Compensation
                    .APLCompRatioLow  = 0xC8,
                    .APLCompRatioHigh = 0xC8,
    
                    // Local Wgt1
                    .FltConfSlope = 0x2EE,
                    .FltConfTh    = 0xC8,
    
                    // Local Wgt2
                    .BlkHistCountRatio = 0x3,
                    .BinIdxDiffSlope   = 0xE0,
                    .BinIdxDiffTh      = 0x0,
                    .BinIdxDiffWgtOft  = 0x20,
                    .APLTh             = 0x10,
                    .APLSlope          = 0x80,
                    .APLWgtOft         = 0x100,
    
                    // Global APL Adjustment
                    .APL2Th     = 0x10,
                    .APL2Slope  = 0x80,
                    .APL2WgtOft = 0x100,
                    .APL2WgtMax = 0x100,
    
                    // Block Spatial Filtering
                    .BlkSpaFltEn   = 1,
                    .BlkSpaFltType = 0x0,
    
                    // for Tuning Tool Only
                    .LoadBlkCurveEn = 0,
                    .SaveBlkCurveEn = 0,
    
                    // Grass Protection
                    .bGreenWgtSlope = 0x25,
                    .dre_dync_compact_wgt_min = 0x0,
                    .dre_dync_compact_wgt_max = 0xFF,
                    .dre_dync_compact_th = 0x80,
                    .dre_dync_compact_slope = 0x20,
                    .bCompactBlendmethod = 0x2,
                    .dre_dync_compact_LowBoundBin = 0x5,
                    .dre_dync_compact_HighBoundBin = 0x7,
                    .dre_dync_compact_BinMinWeight = 0x100,
                    .dre_dync_compact_BinMaxWeight = 0x280,
                },
    
                .CA_LTM_ADAPTTUNINGREG = {
                    .Enabled = 1,
                    .Strength = 255,
                    .AdaptiveMethod = 0,
                    .AdaptiveType = 0,
                    .CustomParametersSearchMode = 0,
                },
            },
            {   //02
                .CA_LTM_INITUNINGRE  = { //ISO4000,LV2
                    .ca_ltm_s_lower = 0x18,
                    .ca_ltm_s_upper = 0x23,
                    .ca_ltm_y_lower = 0x46,
                    .ca_ltm_y_upper = 0x88,
                    .ca_ltm_h_lower = 0x55,
                    .ca_ltm_h_upper = 0x5C,
    
                    .ca_ltm_max_hist_mode               = 1,
                    .ca_ltm_bitplus_contour_range_th    = 0x2,
                    .ca_ltm_bitplus_contour_range_slope = 0x40,
                    .ca_ltm_bitplus_diff_count_th       = 0x3,
                    .ca_ltm_bitplus_diff_count_slope    = 0x2A,
                    .ca_ltm_bitplus_pxl_diff_th         = 0x0,
                    .ca_ltm_bitplus_pxl_diff_slope      = 0x40,
    
                    .ca_ltm_pxl_diff_th_for_flat_pxl    = 0x0,
                    .ca_ltm_pxl_diff_slope_for_flat_pxl = 0x20,
    
                    .ca_ltm_pxl_diff_th                 = 0x0,
                    .ca_ltm_pxl_diff_slope              = 0x10,
    
                    .ca_ltm_s_lower2 = 0x8,
                    .ca_ltm_s_upper2 = 0x14,
                    .ca_ltm_y_lower2 = 0x46,
                    .ca_ltm_y_upper2 = 0xB0,
                    .ca_ltm_h_lower2 = 0x7D,
                    .ca_ltm_h_upper2 = 0x91,
    
                    .ca_ltm_s_lower3 = 0x18,
                    .ca_ltm_s_upper3 = 0x23,
                    .ca_ltm_y_lower3 = 0x46,
                    .ca_ltm_y_upper3 = 0x88,
                    .ca_ltm_h_lower3 = 0x55,
                    .ca_ltm_h_upper3 = 0x5C,
    
                    .ca_ltm_h_slope = 4,
                    .ca_ltm_s_slope = 4,
                    .ca_ltm_y_slope = 4,
                    .ca_ltm_h_slope2 = 4,
                    .ca_ltm_s_slope2 = 4,
                    .ca_ltm_y_slope2 = 4,
                    .ca_ltm_h_slope3 = 4,
                    .ca_ltm_s_slope3 = 4,
                    .ca_ltm_y_slope3 = 4,
    
                    .bilateral_flt_en = 1,
                    .bilateral_impulse_noise_en = 1,
                    .bilateral_range_flt_slope = 1,
                    .dre_bilateral_blending_wgt = 2,
                    .dre_bilateral_blending_en = 1,
                    .dre_bilateral_detect_en = 1,
                    .have_bilateral_filter = 1,
                },
    
                .CA_LTM_TUNINGREG = {
                    .ca_ltm_fw_en           = 1,
                    .ca_ltm_curve_en        = 1,
                    .ca_ltm_gain_flt_en     = 0,
                    .ca_ltm_iir_force_range = 1,
    
                    // Histogram FIR Weight
                    .bADLWeight1 = 0x14,
                    .bADLWeight2 = 0x2C,
                    .bADLWeight3 = 0x00,
    
                    // BS Basic Param
                    .bBSDCGain = 0x10,
                    .bBSACGain = 0x80,
                    .bBSLevel  = 0x0,
    
                    // Mid Param
                    .bMIDDCGain = 0x04,
                    .bMIDACGain = 0x0,
    
                    // WS Basic Param
                    .bWSDCGain = 0x10,
                    .bWSACGain = 0x80,
                    .bWSLevel  = 0x0,
    
                    // Spike Fallback Protection
                    .ca_ltm_dync_spike_wgt_min = 0x0,
                    .ca_ltm_dync_spike_wgt_max = 0x0,
                    .ca_ltm_dync_spike_th      = 0x90,
                    .ca_ltm_dync_spike_slope   = 0x40,
                    .bSpikeBlendmethod      = 0x2,
    
                    // Skin processing
                    .bSkinWgtSlope    = 0x80,
                    .bSkinBlendmethod = 0x2,
    
                    // Temporal Filtering
                    .ca_ltm_dync_flt_coef_min      = 0x8,
                    .ca_ltm_dync_flt_coef_max      = 0x20,
                    .ca_ltm_dync_flt_ovr_pxl_th    = 0x4,
                    .ca_ltm_dync_flt_ovr_pxl_slope = 0x32,
    
                    // Low Level Protection
                    .LLPValue = 0x0,
                    .LLPRatio = 0x0,
    
                    // APL Compensation
                    .APLCompRatioLow  = 0xC8,
                    .APLCompRatioHigh = 0xC8,
    
                    // Local Wgt1
                    .FltConfSlope = 0x2EE,
                    .FltConfTh    = 0xC8,
    
                    // Local Wgt2
                    .BlkHistCountRatio = 0x3,
                    .BinIdxDiffSlope   = 0xE0,
                    .BinIdxDiffTh      = 0x0,
                    .BinIdxDiffWgtOft  = 0x20,
                    .APLTh             = 0x10,
                    .APLSlope          = 0x80,
                    .APLWgtOft         = 0x100,
    
                    // Global APL Adjustment
                    .APL2Th     = 0x10,
                    .APL2Slope  = 0x80,
                    .APL2WgtOft = 0x100,
                    .APL2WgtMax = 0x100,
    
                    // Block Spatial Filtering
                    .BlkSpaFltEn   = 1,
                    .BlkSpaFltType = 0x0,
    
                    // for Tuning Tool Only
                    .LoadBlkCurveEn = 0,
                    .SaveBlkCurveEn = 0,
    
                    // Grass Protection
                    .bGreenWgtSlope = 0x25,
                    .dre_dync_compact_wgt_min = 0x0,
                    .dre_dync_compact_wgt_max = 0xFF,
                    .dre_dync_compact_th = 0x80,
                    .dre_dync_compact_slope = 0x20,
                    .bCompactBlendmethod = 0x2,
                    .dre_dync_compact_LowBoundBin = 0x5,
                    .dre_dync_compact_HighBoundBin = 0x7,
                    .dre_dync_compact_BinMinWeight = 0x100,
                    .dre_dync_compact_BinMaxWeight = 0x280,
                },
    
                .CA_LTM_ADAPTTUNINGREG = {
                    .Enabled = 1,
                    .Strength = 255,
                    .AdaptiveMethod = 0,
                    .AdaptiveType = 0,
                    .CustomParametersSearchMode = 0,
                },
            },
            {   //03
                .CA_LTM_INITUNINGRE  = { //ISO600,LV6
                    .ca_ltm_s_lower = 0x18,
                    .ca_ltm_s_upper = 0x23,
                    .ca_ltm_y_lower = 0x46,
                    .ca_ltm_y_upper = 0x88,
                    .ca_ltm_h_lower = 0x55,
                    .ca_ltm_h_upper = 0x5C,
    
                    .ca_ltm_max_hist_mode               = 1,
                    .ca_ltm_bitplus_contour_range_th    = 0x2,
                    .ca_ltm_bitplus_contour_range_slope = 0x40,
                    .ca_ltm_bitplus_diff_count_th       = 0x3,
                    .ca_ltm_bitplus_diff_count_slope    = 0x2A,
                    .ca_ltm_bitplus_pxl_diff_th         = 0x0,
                    .ca_ltm_bitplus_pxl_diff_slope      = 0x40,
    
                    .ca_ltm_pxl_diff_th_for_flat_pxl    = 0x0,
                    .ca_ltm_pxl_diff_slope_for_flat_pxl = 0x20,
    
                    .ca_ltm_pxl_diff_th                 = 0x0,
                    .ca_ltm_pxl_diff_slope              = 0x10,
    
                    .ca_ltm_s_lower2 = 0x8,
                    .ca_ltm_s_upper2 = 0x14,
                    .ca_ltm_y_lower2 = 0x46,
                    .ca_ltm_y_upper2 = 0xB0,
                    .ca_ltm_h_lower2 = 0x7D,
                    .ca_ltm_h_upper2 = 0x91,
    
                    .ca_ltm_s_lower3 = 0x18,
                    .ca_ltm_s_upper3 = 0x23,
                    .ca_ltm_y_lower3 = 0x46,
                    .ca_ltm_y_upper3 = 0x88,
                    .ca_ltm_h_lower3 = 0x55,
                    .ca_ltm_h_upper3 = 0x5C,
    
                    .ca_ltm_h_slope = 4,
                    .ca_ltm_s_slope = 4,
                    .ca_ltm_y_slope = 4,
                    .ca_ltm_h_slope2 = 4,
                    .ca_ltm_s_slope2 = 4,
                    .ca_ltm_y_slope2 = 4,
                    .ca_ltm_h_slope3 = 4,
                    .ca_ltm_s_slope3 = 4,
                    .ca_ltm_y_slope3 = 4,
    
                    .bilateral_flt_en = 1,
                    .bilateral_impulse_noise_en = 1,
                    .bilateral_range_flt_slope = 1,
                    .dre_bilateral_blending_wgt = 2,
                    .dre_bilateral_blending_en = 1,
                    .dre_bilateral_detect_en = 1,
                    .have_bilateral_filter = 1,
                },
    
                .CA_LTM_TUNINGREG = {
                    .ca_ltm_fw_en           = 1,
                    .ca_ltm_curve_en        = 1,
                    .ca_ltm_gain_flt_en     = 0,
                    .ca_ltm_iir_force_range = 1,
    
                    // Histogram FIR Weight
                    .bADLWeight1 = 0x14,
                    .bADLWeight2 = 0x2C,
                    .bADLWeight3 = 0x00,
    
                    // BS Basic Param
                    .bBSDCGain = 0x10,
                    .bBSACGain = 0x80,
                    .bBSLevel  = 0x0,
    
                    // Mid Param
                    .bMIDDCGain = 0x04,
                    .bMIDACGain = 0x06,
    
                    // WS Basic Param
                    .bWSDCGain = 0x10,
                    .bWSACGain = 0x80,
                    .bWSLevel  = 0x0,
    
                    // Spike Fallback Protection
                    .ca_ltm_dync_spike_wgt_min = 0x0,
                    .ca_ltm_dync_spike_wgt_max = 0x0,
                    .ca_ltm_dync_spike_th      = 0x90,
                    .ca_ltm_dync_spike_slope   = 0x40,
                    .bSpikeBlendmethod      = 0x2,
    
                    // Skin processing
                    .bSkinWgtSlope    = 0x80,
                    .bSkinBlendmethod = 0x2,
    
                    // Temporal Filtering
                    .ca_ltm_dync_flt_coef_min      = 0x8,
                    .ca_ltm_dync_flt_coef_max      = 0x20,
                    .ca_ltm_dync_flt_ovr_pxl_th    = 0x4,
                    .ca_ltm_dync_flt_ovr_pxl_slope = 0x32,
    
                    // Low Level Protection
                    .LLPValue = 0x0,
                    .LLPRatio = 0x0,
    
                    // APL Compensation
                    .APLCompRatioLow  = 0xC8,
                    .APLCompRatioHigh = 0xC8,
    
                    // Local Wgt1
                    .FltConfSlope = 0x2EE,
                    .FltConfTh    = 0xC8,
    
                    // Local Wgt2
                    .BlkHistCountRatio = 0x3,
                    .BinIdxDiffSlope   = 0xE0,
                    .BinIdxDiffTh      = 0x0,
                    .BinIdxDiffWgtOft  = 0x20,
                    .APLTh             = 0x10,
                    .APLSlope          = 0x80,
                    .APLWgtOft         = 0x100,
    
                    // Global APL Adjustment
                    .APL2Th     = 0x10,
                    .APL2Slope  = 0x80,
                    .APL2WgtOft = 0x100,
                    .APL2WgtMax = 0x100,
    
                    // Block Spatial Filtering
                    .BlkSpaFltEn   = 1,
                    .BlkSpaFltType = 0x0,
    
                    // for Tuning Tool Only
                    .LoadBlkCurveEn = 0,
                    .SaveBlkCurveEn = 0,
    
                    // Grass Protection
                    .bGreenWgtSlope = 0x25,
                    .dre_dync_compact_wgt_min = 0x0,
                    .dre_dync_compact_wgt_max = 0xFF,
                    .dre_dync_compact_th = 0x80,
                    .dre_dync_compact_slope = 0x20,
                    .bCompactBlendmethod = 0x2,
                    .dre_dync_compact_LowBoundBin = 0x5,
                    .dre_dync_compact_HighBoundBin = 0x7,
                    .dre_dync_compact_BinMinWeight = 0x100,
                    .dre_dync_compact_BinMaxWeight = 0x280,
                },
    
                .CA_LTM_ADAPTTUNINGREG = {
                    .Enabled = 1,
                    .Strength = 255,
                    .AdaptiveMethod = 0,
                    .AdaptiveType = 0,
                    .CustomParametersSearchMode = 0,
                },
            },
            {   //04
                .CA_LTM_INITUNINGRE  = { //ISO2300,LV6
                    .ca_ltm_s_lower = 0x18,
                    .ca_ltm_s_upper = 0x23,
                    .ca_ltm_y_lower = 0x46,
                    .ca_ltm_y_upper = 0x88,
                    .ca_ltm_h_lower = 0x55,
                    .ca_ltm_h_upper = 0x5C,
    
                    .ca_ltm_max_hist_mode               = 1,
                    .ca_ltm_bitplus_contour_range_th    = 0x2,
                    .ca_ltm_bitplus_contour_range_slope = 0x40,
                    .ca_ltm_bitplus_diff_count_th       = 0x3,
                    .ca_ltm_bitplus_diff_count_slope    = 0x2A,
                    .ca_ltm_bitplus_pxl_diff_th         = 0x0,
                    .ca_ltm_bitplus_pxl_diff_slope      = 0x40,
    
                    .ca_ltm_pxl_diff_th_for_flat_pxl    = 0x0,
                    .ca_ltm_pxl_diff_slope_for_flat_pxl = 0x20,
    
                    .ca_ltm_pxl_diff_th                 = 0x0,
                    .ca_ltm_pxl_diff_slope              = 0x10,
    
                    .ca_ltm_s_lower2 = 0x8,
                    .ca_ltm_s_upper2 = 0x14,
                    .ca_ltm_y_lower2 = 0x46,
                    .ca_ltm_y_upper2 = 0xB0,
                    .ca_ltm_h_lower2 = 0x7D,
                    .ca_ltm_h_upper2 = 0x91,
    
                    .ca_ltm_s_lower3 = 0x18,
                    .ca_ltm_s_upper3 = 0x23,
                    .ca_ltm_y_lower3 = 0x46,
                    .ca_ltm_y_upper3 = 0x88,
                    .ca_ltm_h_lower3 = 0x55,
                    .ca_ltm_h_upper3 = 0x5C,
    
                    .ca_ltm_h_slope = 4,
                    .ca_ltm_s_slope = 4,
                    .ca_ltm_y_slope = 4,
                    .ca_ltm_h_slope2 = 4,
                    .ca_ltm_s_slope2 = 4,
                    .ca_ltm_y_slope2 = 4,
                    .ca_ltm_h_slope3 = 4,
                    .ca_ltm_s_slope3 = 4,
                    .ca_ltm_y_slope3 = 4,
    
                    .bilateral_flt_en = 1,
                    .bilateral_impulse_noise_en = 1,
                    .bilateral_range_flt_slope = 1,
                    .dre_bilateral_blending_wgt = 2,
                    .dre_bilateral_blending_en = 1,
                    .dre_bilateral_detect_en = 1,
                    .have_bilateral_filter = 1,
                },
    
                .CA_LTM_TUNINGREG = {
                    .ca_ltm_fw_en           = 1,
                    .ca_ltm_curve_en        = 1,
                    .ca_ltm_gain_flt_en     = 0,
                    .ca_ltm_iir_force_range = 1,
    
                    // Histogram FIR Weight
                    .bADLWeight1 = 0x14,
                    .bADLWeight2 = 0x2C,
                    .bADLWeight3 = 0x00,
    
                    // BS Basic Param
                    .bBSDCGain = 0x10,
                    .bBSACGain = 0x80,
                    .bBSLevel  = 0x0,
    
                    // Mid Param
                    .bMIDDCGain = 0x04,
                    .bMIDACGain = 0x06,
    
                    // WS Basic Param
                    .bWSDCGain = 0x10,
                    .bWSACGain = 0x80,
                    .bWSLevel  = 0x0,
    
                    // Spike Fallback Protection
                    .ca_ltm_dync_spike_wgt_min = 0x0,
                    .ca_ltm_dync_spike_wgt_max = 0x0,
                    .ca_ltm_dync_spike_th      = 0x90,
                    .ca_ltm_dync_spike_slope   = 0x40,
                    .bSpikeBlendmethod      = 0x2,
    
                    // Skin processing
                    .bSkinWgtSlope    = 0x80,
                    .bSkinBlendmethod = 0x2,
    
                    // Temporal Filtering
                    .ca_ltm_dync_flt_coef_min      = 0x8,
                    .ca_ltm_dync_flt_coef_max      = 0x20,
                    .ca_ltm_dync_flt_ovr_pxl_th    = 0x4,
                    .ca_ltm_dync_flt_ovr_pxl_slope = 0x32,
    
                    // Low Level Protection
                    .LLPValue = 0x0,
                    .LLPRatio = 0x0,
    
                    // APL Compensation
                    .APLCompRatioLow  = 0xC8,
                    .APLCompRatioHigh = 0xC8,
    
                    // Local Wgt1
                    .FltConfSlope = 0x2EE,
                    .FltConfTh    = 0xC8,
    
                    // Local Wgt2
                    .BlkHistCountRatio = 0x3,
                    .BinIdxDiffSlope   = 0xE0,
                    .BinIdxDiffTh      = 0x0,
                    .BinIdxDiffWgtOft  = 0x20,
                    .APLTh             = 0x10,
                    .APLSlope          = 0x80,
                    .APLWgtOft         = 0x100,
    
                    // Global APL Adjustment
                    .APL2Th     = 0x10,
                    .APL2Slope  = 0x80,
                    .APL2WgtOft = 0x100,
                    .APL2WgtMax = 0x100,
    
                    // Block Spatial Filtering
                    .BlkSpaFltEn   = 1,
                    .BlkSpaFltType = 0x0,
    
                    // for Tuning Tool Only
                    .LoadBlkCurveEn = 0,
                    .SaveBlkCurveEn = 0,
    
                    // Grass Protection
                    .bGreenWgtSlope = 0x25,
                    .dre_dync_compact_wgt_min = 0x0,
                    .dre_dync_compact_wgt_max = 0xFF,
                    .dre_dync_compact_th = 0x80,
                    .dre_dync_compact_slope = 0x20,
                    .bCompactBlendmethod = 0x2,
                    .dre_dync_compact_LowBoundBin = 0x5,
                    .dre_dync_compact_HighBoundBin = 0x7,
                    .dre_dync_compact_BinMinWeight = 0x100,
                    .dre_dync_compact_BinMaxWeight = 0x280,
                },
    
                .CA_LTM_ADAPTTUNINGREG = {
                    .Enabled = 1,
                    .Strength = 255,
                    .AdaptiveMethod = 0,
                    .AdaptiveType = 0,
                    .CustomParametersSearchMode = 0,
                },
            },
            {   //05
                .CA_LTM_INITUNINGRE  = { //ISO4000,LV6
                    .ca_ltm_s_lower = 0x18,
                    .ca_ltm_s_upper = 0x23,
                    .ca_ltm_y_lower = 0x46,
                    .ca_ltm_y_upper = 0x88,
                    .ca_ltm_h_lower = 0x55,
                    .ca_ltm_h_upper = 0x5C,
    
                    .ca_ltm_max_hist_mode               = 1,
                    .ca_ltm_bitplus_contour_range_th    = 0x2,
                    .ca_ltm_bitplus_contour_range_slope = 0x40,
                    .ca_ltm_bitplus_diff_count_th       = 0x3,
                    .ca_ltm_bitplus_diff_count_slope    = 0x2A,
                    .ca_ltm_bitplus_pxl_diff_th         = 0x0,
                    .ca_ltm_bitplus_pxl_diff_slope      = 0x40,
    
                    .ca_ltm_pxl_diff_th_for_flat_pxl    = 0x0,
                    .ca_ltm_pxl_diff_slope_for_flat_pxl = 0x20,
    
                    .ca_ltm_pxl_diff_th                 = 0x0,
                    .ca_ltm_pxl_diff_slope              = 0x10,
    
                    .ca_ltm_s_lower2 = 0x8,
                    .ca_ltm_s_upper2 = 0x14,
                    .ca_ltm_y_lower2 = 0x46,
                    .ca_ltm_y_upper2 = 0xB0,
                    .ca_ltm_h_lower2 = 0x7D,
                    .ca_ltm_h_upper2 = 0x91,
    
                    .ca_ltm_s_lower3 = 0x18,
                    .ca_ltm_s_upper3 = 0x23,
                    .ca_ltm_y_lower3 = 0x46,
                    .ca_ltm_y_upper3 = 0x88,
                    .ca_ltm_h_lower3 = 0x55,
                    .ca_ltm_h_upper3 = 0x5C,
    
                    .ca_ltm_h_slope = 4,
                    .ca_ltm_s_slope = 4,
                    .ca_ltm_y_slope = 4,
                    .ca_ltm_h_slope2 = 4,
                    .ca_ltm_s_slope2 = 4,
                    .ca_ltm_y_slope2 = 4,
                    .ca_ltm_h_slope3 = 4,
                    .ca_ltm_s_slope3 = 4,
                    .ca_ltm_y_slope3 = 4,
    
                    .bilateral_flt_en = 1,
                    .bilateral_impulse_noise_en = 1,
                    .bilateral_range_flt_slope = 1,
                    .dre_bilateral_blending_wgt = 2,
                    .dre_bilateral_blending_en = 1,
                    .dre_bilateral_detect_en = 1,
                    .have_bilateral_filter = 1,
                },
    
                .CA_LTM_TUNINGREG = {
                    .ca_ltm_fw_en           = 1,
                    .ca_ltm_curve_en        = 1,
                    .ca_ltm_gain_flt_en     = 0,
                    .ca_ltm_iir_force_range = 1,
    
                    // Histogram FIR Weight
                    .bADLWeight1 = 0x14,
                    .bADLWeight2 = 0x2C,
                    .bADLWeight3 = 0x00,
    
                    // BS Basic Param
                    .bBSDCGain = 0x10,
                    .bBSACGain = 0x80,
                    .bBSLevel  = 0x0,
    
                    // Mid Param
                    .bMIDDCGain = 0x04,
                    .bMIDACGain = 0x0,
    
                    // WS Basic Param
                    .bWSDCGain = 0x10,
                    .bWSACGain = 0x80,
                    .bWSLevel  = 0x0,
    
                    // Spike Fallback Protection
                    .ca_ltm_dync_spike_wgt_min = 0x0,
                    .ca_ltm_dync_spike_wgt_max = 0x0,
                    .ca_ltm_dync_spike_th      = 0x90,
                    .ca_ltm_dync_spike_slope   = 0x40,
                    .bSpikeBlendmethod      = 0x2,
    
                    // Skin processing
                    .bSkinWgtSlope    = 0x80,
                    .bSkinBlendmethod = 0x2,
    
                    // Temporal Filtering
                    .ca_ltm_dync_flt_coef_min      = 0x8,
                    .ca_ltm_dync_flt_coef_max      = 0x20,
                    .ca_ltm_dync_flt_ovr_pxl_th    = 0x4,
                    .ca_ltm_dync_flt_ovr_pxl_slope = 0x32,
    
                    // Low Level Protection
                    .LLPValue = 0x0,
                    .LLPRatio = 0x0,
    
                    // APL Compensation
                    .APLCompRatioLow  = 0xC8,
                    .APLCompRatioHigh = 0xC8,
    
                    // Local Wgt1
                    .FltConfSlope = 0x2EE,
                    .FltConfTh    = 0xC8,
    
                    // Local Wgt2
                    .BlkHistCountRatio = 0x3,
                    .BinIdxDiffSlope   = 0xE0,
                    .BinIdxDiffTh      = 0x0,
                    .BinIdxDiffWgtOft  = 0x20,
                    .APLTh             = 0x10,
                    .APLSlope          = 0x80,
                    .APLWgtOft         = 0x100,
    
                    // Global APL Adjustment
                    .APL2Th     = 0x10,
                    .APL2Slope  = 0x80,
                    .APL2WgtOft = 0x100,
                    .APL2WgtMax = 0x100,
    
                    // Block Spatial Filtering
                    .BlkSpaFltEn   = 1,
                    .BlkSpaFltType = 0x0,
    
                    // for Tuning Tool Only
                    .LoadBlkCurveEn = 0,
                    .SaveBlkCurveEn = 0,
    
                    // Grass Protection
                    .bGreenWgtSlope = 0x25,
                    .dre_dync_compact_wgt_min = 0x0,
                    .dre_dync_compact_wgt_max = 0xFF,
                    .dre_dync_compact_th = 0x80,
                    .dre_dync_compact_slope = 0x20,
                    .bCompactBlendmethod = 0x2,
                    .dre_dync_compact_LowBoundBin = 0x5,
                    .dre_dync_compact_HighBoundBin = 0x7,
                    .dre_dync_compact_BinMinWeight = 0x100,
                    .dre_dync_compact_BinMaxWeight = 0x280,
                },
    
                .CA_LTM_ADAPTTUNINGREG = {
                    .Enabled = 1,
                    .Strength = 255,
                    .AdaptiveMethod = 0,
                    .AdaptiveType = 0,
                    .CustomParametersSearchMode = 0,
                },
            },
            {   //06
                .CA_LTM_INITUNINGRE  = { //ISO600,LV11
                    .ca_ltm_s_lower = 0x18,
                    .ca_ltm_s_upper = 0x23,
                    .ca_ltm_y_lower = 0x46,
                    .ca_ltm_y_upper = 0x88,
                    .ca_ltm_h_lower = 0x55,
                    .ca_ltm_h_upper = 0x5C,
    
                    .ca_ltm_max_hist_mode               = 1,
                    .ca_ltm_bitplus_contour_range_th    = 0x2,
                    .ca_ltm_bitplus_contour_range_slope = 0x40,
                    .ca_ltm_bitplus_diff_count_th       = 0x3,
                    .ca_ltm_bitplus_diff_count_slope    = 0x2A,
                    .ca_ltm_bitplus_pxl_diff_th         = 0x0,
                    .ca_ltm_bitplus_pxl_diff_slope      = 0x40,
    
                    .ca_ltm_pxl_diff_th_for_flat_pxl    = 0x0,
                    .ca_ltm_pxl_diff_slope_for_flat_pxl = 0x20,
    
                    .ca_ltm_pxl_diff_th                 = 0x0,
                    .ca_ltm_pxl_diff_slope              = 0x10,
    
                    .ca_ltm_s_lower2 = 0x8,
                    .ca_ltm_s_upper2 = 0x14,
                    .ca_ltm_y_lower2 = 0x46,
                    .ca_ltm_y_upper2 = 0xB0,
                    .ca_ltm_h_lower2 = 0x7D,
                    .ca_ltm_h_upper2 = 0x91,
    
                    .ca_ltm_s_lower3 = 0x18,
                    .ca_ltm_s_upper3 = 0x23,
                    .ca_ltm_y_lower3 = 0x46,
                    .ca_ltm_y_upper3 = 0x88,
                    .ca_ltm_h_lower3 = 0x55,
                    .ca_ltm_h_upper3 = 0x5C,
    
                    .ca_ltm_h_slope = 4,
                    .ca_ltm_s_slope = 4,
                    .ca_ltm_y_slope = 4,
                    .ca_ltm_h_slope2 = 4,
                    .ca_ltm_s_slope2 = 4,
                    .ca_ltm_y_slope2 = 4,
                    .ca_ltm_h_slope3 = 4,
                    .ca_ltm_s_slope3 = 4,
                    .ca_ltm_y_slope3 = 4,
    
                    .bilateral_flt_en = 1,
                    .bilateral_impulse_noise_en = 1,
                    .bilateral_range_flt_slope = 1,
                    .dre_bilateral_blending_wgt = 2,
                    .dre_bilateral_blending_en = 1,
                    .dre_bilateral_detect_en = 1,
                    .have_bilateral_filter = 1,
                },
    
                .CA_LTM_TUNINGREG = {
                    .ca_ltm_fw_en           = 1,
                    .ca_ltm_curve_en        = 1,
                    .ca_ltm_gain_flt_en     = 0,
                    .ca_ltm_iir_force_range = 1,
    
                    // Histogram FIR Weight
                    .bADLWeight1 = 0x14,
                    .bADLWeight2 = 0x2C,
                    .bADLWeight3 = 0x00,
    
                    // BS Basic Param
                    .bBSDCGain = 0x10,
                    .bBSACGain = 0x80,
                    .bBSLevel  = 0x0,
    
                    // Mid Param
                    .bMIDDCGain = 0x04,
                    .bMIDACGain = 0x06,
    
                    // WS Basic Param
                    .bWSDCGain = 0x10,
                    .bWSACGain = 0x80,
                    .bWSLevel  = 0x0,
    
                    // Spike Fallback Protection
                    .ca_ltm_dync_spike_wgt_min = 0x0,
                    .ca_ltm_dync_spike_wgt_max = 0x0,
                    .ca_ltm_dync_spike_th      = 0x90,
                    .ca_ltm_dync_spike_slope   = 0x40,
                    .bSpikeBlendmethod      = 0x2,
    
                    // Skin processing
                    .bSkinWgtSlope    = 0x80,
                    .bSkinBlendmethod = 0x2,
    
                    // Temporal Filtering
                    .ca_ltm_dync_flt_coef_min      = 0x8,
                    .ca_ltm_dync_flt_coef_max      = 0x20,
                    .ca_ltm_dync_flt_ovr_pxl_th    = 0x4,
                    .ca_ltm_dync_flt_ovr_pxl_slope = 0x32,
    
                    // Low Level Protection
                    .LLPValue = 0x0,
                    .LLPRatio = 0x0,
    
                    // APL Compensation
                    .APLCompRatioLow  = 0xC8,
                    .APLCompRatioHigh = 0xC8,
    
                    // Local Wgt1
                    .FltConfSlope = 0x2EE,
                    .FltConfTh    = 0xC8,
    
                    // Local Wgt2
                    .BlkHistCountRatio = 0x3,
                    .BinIdxDiffSlope   = 0xE0,
                    .BinIdxDiffTh      = 0x0,
                    .BinIdxDiffWgtOft  = 0x20,
                    .APLTh             = 0x10,
                    .APLSlope          = 0x80,
                    .APLWgtOft         = 0x100,
    
                    // Global APL Adjustment
                    .APL2Th     = 0x10,
                    .APL2Slope  = 0x80,
                    .APL2WgtOft = 0x100,
                    .APL2WgtMax = 0x100,
    
                    // Block Spatial Filtering
                    .BlkSpaFltEn   = 1,
                    .BlkSpaFltType = 0x0,
    
                    // for Tuning Tool Only
                    .LoadBlkCurveEn = 0,
                    .SaveBlkCurveEn = 0,
    
                    // Grass Protection
                    .bGreenWgtSlope = 0x25,
                    .dre_dync_compact_wgt_min = 0x0,
                    .dre_dync_compact_wgt_max = 0xFF,
                    .dre_dync_compact_th = 0x80,
                    .dre_dync_compact_slope = 0x20,
                    .bCompactBlendmethod = 0x2,
                    .dre_dync_compact_LowBoundBin = 0x5,
                    .dre_dync_compact_HighBoundBin = 0x7,
                    .dre_dync_compact_BinMinWeight = 0x100,
                    .dre_dync_compact_BinMaxWeight = 0x280,
                },
    
                .CA_LTM_ADAPTTUNINGREG = {
                    .Enabled = 1,
                    .Strength = 255,
                    .AdaptiveMethod = 0,
                    .AdaptiveType = 0,
                    .CustomParametersSearchMode = 0,
                },
            },
            {   //07
                .CA_LTM_INITUNINGRE  = { //ISO2300,LV11
                    .ca_ltm_s_lower = 0x18,
                    .ca_ltm_s_upper = 0x23,
                    .ca_ltm_y_lower = 0x46,
                    .ca_ltm_y_upper = 0x88,
                    .ca_ltm_h_lower = 0x55,
                    .ca_ltm_h_upper = 0x5C,
    
                    .ca_ltm_max_hist_mode               = 1,
                    .ca_ltm_bitplus_contour_range_th    = 0x2,
                    .ca_ltm_bitplus_contour_range_slope = 0x40,
                    .ca_ltm_bitplus_diff_count_th       = 0x3,
                    .ca_ltm_bitplus_diff_count_slope    = 0x2A,
                    .ca_ltm_bitplus_pxl_diff_th         = 0x0,
                    .ca_ltm_bitplus_pxl_diff_slope      = 0x40,
    
                    .ca_ltm_pxl_diff_th_for_flat_pxl    = 0x0,
                    .ca_ltm_pxl_diff_slope_for_flat_pxl = 0x20,
    
                    .ca_ltm_pxl_diff_th                 = 0x0,
                    .ca_ltm_pxl_diff_slope              = 0x10,
    
                    .ca_ltm_s_lower2 = 0x8,
                    .ca_ltm_s_upper2 = 0x14,
                    .ca_ltm_y_lower2 = 0x46,
                    .ca_ltm_y_upper2 = 0xB0,
                    .ca_ltm_h_lower2 = 0x7D,
                    .ca_ltm_h_upper2 = 0x91,
    
                    .ca_ltm_s_lower3 = 0x18,
                    .ca_ltm_s_upper3 = 0x23,
                    .ca_ltm_y_lower3 = 0x46,
                    .ca_ltm_y_upper3 = 0x88,
                    .ca_ltm_h_lower3 = 0x55,
                    .ca_ltm_h_upper3 = 0x5C,
    
                    .ca_ltm_h_slope = 4,
                    .ca_ltm_s_slope = 4,
                    .ca_ltm_y_slope = 4,
                    .ca_ltm_h_slope2 = 4,
                    .ca_ltm_s_slope2 = 4,
                    .ca_ltm_y_slope2 = 4,
                    .ca_ltm_h_slope3 = 4,
                    .ca_ltm_s_slope3 = 4,
                    .ca_ltm_y_slope3 = 4,
    
                    .bilateral_flt_en = 1,
                    .bilateral_impulse_noise_en = 1,
                    .bilateral_range_flt_slope = 1,
                    .dre_bilateral_blending_wgt = 2,
                    .dre_bilateral_blending_en = 1,
                    .dre_bilateral_detect_en = 1,
                    .have_bilateral_filter = 1,
                },
    
                .CA_LTM_TUNINGREG = {
                    .ca_ltm_fw_en           = 1,
                    .ca_ltm_curve_en        = 1,
                    .ca_ltm_gain_flt_en     = 0,
                    .ca_ltm_iir_force_range = 1,
    
                    // Histogram FIR Weight
                    .bADLWeight1 = 0x14,
                    .bADLWeight2 = 0x2C,
                    .bADLWeight3 = 0x00,
    
                    // BS Basic Param
                    .bBSDCGain = 0x10,
                    .bBSACGain = 0x80,
                    .bBSLevel  = 0x0,
    
                    // Mid Param
                    .bMIDDCGain = 0x04,
                    .bMIDACGain = 0x06,
    
                    // WS Basic Param
                    .bWSDCGain = 0x10,
                    .bWSACGain = 0x80,
                    .bWSLevel  = 0x0,
    
                    // Spike Fallback Protection
                    .ca_ltm_dync_spike_wgt_min = 0x0,
                    .ca_ltm_dync_spike_wgt_max = 0x0,
                    .ca_ltm_dync_spike_th      = 0x90,
                    .ca_ltm_dync_spike_slope   = 0x40,
                    .bSpikeBlendmethod      = 0x2,
    
                    // Skin processing
                    .bSkinWgtSlope    = 0x80,
                    .bSkinBlendmethod = 0x2,
    
                    // Temporal Filtering
                    .ca_ltm_dync_flt_coef_min      = 0x8,
                    .ca_ltm_dync_flt_coef_max      = 0x20,
                    .ca_ltm_dync_flt_ovr_pxl_th    = 0x4,
                    .ca_ltm_dync_flt_ovr_pxl_slope = 0x32,
    
                    // Low Level Protection
                    .LLPValue = 0x0,
                    .LLPRatio = 0x0,
    
                    // APL Compensation
                    .APLCompRatioLow  = 0xC8,
                    .APLCompRatioHigh = 0xC8,
    
                    // Local Wgt1
                    .FltConfSlope = 0x2EE,
                    .FltConfTh    = 0xC8,
    
                    // Local Wgt2
                    .BlkHistCountRatio = 0x3,
                    .BinIdxDiffSlope   = 0xE0,
                    .BinIdxDiffTh      = 0x0,
                    .BinIdxDiffWgtOft  = 0x20,
                    .APLTh             = 0x10,
                    .APLSlope          = 0x80,
                    .APLWgtOft         = 0x100,
    
                    // Global APL Adjustment
                    .APL2Th     = 0x10,
                    .APL2Slope  = 0x80,
                    .APL2WgtOft = 0x100,
                    .APL2WgtMax = 0x100,
    
                    // Block Spatial Filtering
                    .BlkSpaFltEn   = 1,
                    .BlkSpaFltType = 0x0,
    
                    // for Tuning Tool Only
                    .LoadBlkCurveEn = 0,
                    .SaveBlkCurveEn = 0,
    
                    // Grass Protection
                    .bGreenWgtSlope = 0x25,
                    .dre_dync_compact_wgt_min = 0x0,
                    .dre_dync_compact_wgt_max = 0xFF,
                    .dre_dync_compact_th = 0x80,
                    .dre_dync_compact_slope = 0x20,
                    .bCompactBlendmethod = 0x2,
                    .dre_dync_compact_LowBoundBin = 0x5,
                    .dre_dync_compact_HighBoundBin = 0x7,
                    .dre_dync_compact_BinMinWeight = 0x100,
                    .dre_dync_compact_BinMaxWeight = 0x280,
                },
    
                .CA_LTM_ADAPTTUNINGREG = {
                    .Enabled = 1,
                    .Strength = 255,
                    .AdaptiveMethod = 0,
                    .AdaptiveType = 0,
                    .CustomParametersSearchMode = 0,
                },
            },
            {   //08
                .CA_LTM_INITUNINGRE  = { //ISO4000,LV11
                    .ca_ltm_s_lower = 0x18,
                    .ca_ltm_s_upper = 0x23,
                    .ca_ltm_y_lower = 0x46,
                    .ca_ltm_y_upper = 0x88,
                    .ca_ltm_h_lower = 0x55,
                    .ca_ltm_h_upper = 0x5C,
    
                    .ca_ltm_max_hist_mode               = 1,
                    .ca_ltm_bitplus_contour_range_th    = 0x2,
                    .ca_ltm_bitplus_contour_range_slope = 0x40,
                    .ca_ltm_bitplus_diff_count_th       = 0x3,
                    .ca_ltm_bitplus_diff_count_slope    = 0x2A,
                    .ca_ltm_bitplus_pxl_diff_th         = 0x0,
                    .ca_ltm_bitplus_pxl_diff_slope      = 0x40,
    
                    .ca_ltm_pxl_diff_th_for_flat_pxl    = 0x0,
                    .ca_ltm_pxl_diff_slope_for_flat_pxl = 0x20,
    
                    .ca_ltm_pxl_diff_th                 = 0x0,
                    .ca_ltm_pxl_diff_slope              = 0x10,
    
                    .ca_ltm_s_lower2 = 0x8,
                    .ca_ltm_s_upper2 = 0x14,
                    .ca_ltm_y_lower2 = 0x46,
                    .ca_ltm_y_upper2 = 0xB0,
                    .ca_ltm_h_lower2 = 0x7D,
                    .ca_ltm_h_upper2 = 0x91,
    
                    .ca_ltm_s_lower3 = 0x18,
                    .ca_ltm_s_upper3 = 0x23,
                    .ca_ltm_y_lower3 = 0x46,
                    .ca_ltm_y_upper3 = 0x88,
                    .ca_ltm_h_lower3 = 0x55,
                    .ca_ltm_h_upper3 = 0x5C,
    
                    .ca_ltm_h_slope = 4,
                    .ca_ltm_s_slope = 4,
                    .ca_ltm_y_slope = 4,
                    .ca_ltm_h_slope2 = 4,
                    .ca_ltm_s_slope2 = 4,
                    .ca_ltm_y_slope2 = 4,
                    .ca_ltm_h_slope3 = 4,
                    .ca_ltm_s_slope3 = 4,
                    .ca_ltm_y_slope3 = 4,
    
                    .bilateral_flt_en = 1,
                    .bilateral_impulse_noise_en = 1,
                    .bilateral_range_flt_slope = 1,
                    .dre_bilateral_blending_wgt = 2,
                    .dre_bilateral_blending_en = 1,
                    .dre_bilateral_detect_en = 1,
                    .have_bilateral_filter = 1,
                },
    
                .CA_LTM_TUNINGREG = {
                    .ca_ltm_fw_en           = 1,
                    .ca_ltm_curve_en        = 1,
                    .ca_ltm_gain_flt_en     = 0,
                    .ca_ltm_iir_force_range = 1,
    
                    // Histogram FIR Weight
                    .bADLWeight1 = 0x14,
                    .bADLWeight2 = 0x2C,
                    .bADLWeight3 = 0x00,
    
                    // BS Basic Param
                    .bBSDCGain = 0x10,
                    .bBSACGain = 0x80,
                    .bBSLevel  = 0x0,
    
                    // Mid Param
                    .bMIDDCGain = 0x04,
                    .bMIDACGain = 0x0,
    
                    // WS Basic Param
                    .bWSDCGain = 0x10,
                    .bWSACGain = 0x80,
                    .bWSLevel  = 0x0,
    
                    // Spike Fallback Protection
                    .ca_ltm_dync_spike_wgt_min = 0x0,
                    .ca_ltm_dync_spike_wgt_max = 0x0,
                    .ca_ltm_dync_spike_th      = 0x90,
                    .ca_ltm_dync_spike_slope   = 0x40,
                    .bSpikeBlendmethod      = 0x2,
    
                    // Skin processing
                    .bSkinWgtSlope    = 0x80,
                    .bSkinBlendmethod = 0x2,
    
                    // Temporal Filtering
                    .ca_ltm_dync_flt_coef_min      = 0x8,
                    .ca_ltm_dync_flt_coef_max      = 0x20,
                    .ca_ltm_dync_flt_ovr_pxl_th    = 0x4,
                    .ca_ltm_dync_flt_ovr_pxl_slope = 0x32,
    
                    // Low Level Protection
                    .LLPValue = 0x0,
                    .LLPRatio = 0x0,
    
                    // APL Compensation
                    .APLCompRatioLow  = 0xC8,
                    .APLCompRatioHigh = 0xC8,
    
                    // Local Wgt1
                    .FltConfSlope = 0x2EE,
                    .FltConfTh    = 0xC8,
    
                    // Local Wgt2
                    .BlkHistCountRatio = 0x3,
                    .BinIdxDiffSlope   = 0xE0,
                    .BinIdxDiffTh      = 0x0,
                    .BinIdxDiffWgtOft  = 0x20,
                    .APLTh             = 0x10,
                    .APLSlope          = 0x80,
                    .APLWgtOft         = 0x100,
    
                    // Global APL Adjustment
                    .APL2Th     = 0x10,
                    .APL2Slope  = 0x80,
                    .APL2WgtOft = 0x100,
                    .APL2WgtMax = 0x100,
    
                    // Block Spatial Filtering
                    .BlkSpaFltEn   = 1,
                    .BlkSpaFltType = 0x0,
    
                    // for Tuning Tool Only
                    .LoadBlkCurveEn = 0,
                    .SaveBlkCurveEn = 0,
    
                    // Grass Protection
                    .bGreenWgtSlope = 0x25,
                    .dre_dync_compact_wgt_min = 0x0,
                    .dre_dync_compact_wgt_max = 0xFF,
                    .dre_dync_compact_th = 0x80,
                    .dre_dync_compact_slope = 0x20,
                    .bCompactBlendmethod = 0x2,
                    .dre_dync_compact_LowBoundBin = 0x5,
                    .dre_dync_compact_HighBoundBin = 0x7,
                    .dre_dync_compact_BinMinWeight = 0x100,
                    .dre_dync_compact_BinMaxWeight = 0x280,
                },
    
                .CA_LTM_ADAPTTUNINGREG = {
                    .Enabled = 1,
                    .Strength = 255,
                    .AdaptiveMethod = 0,
                    .AdaptiveType = 0,
                    .CustomParametersSearchMode = 0,
                },
            },
            {   //09
                .CA_LTM_INITUNINGRE  = {
                    .ca_ltm_s_lower = 0x18,
                    .ca_ltm_s_upper = 0x23,
                    .ca_ltm_y_lower = 0x46,
                    .ca_ltm_y_upper = 0x88,
                    .ca_ltm_h_lower = 0x55,
                    .ca_ltm_h_upper = 0x5C,
    
                    .ca_ltm_max_hist_mode               = 1,
                    .ca_ltm_bitplus_contour_range_th    = 0x2,
                    .ca_ltm_bitplus_contour_range_slope = 0x40,
                    .ca_ltm_bitplus_diff_count_th       = 0x3,
                    .ca_ltm_bitplus_diff_count_slope    = 0x2A,
                    .ca_ltm_bitplus_pxl_diff_th         = 0x0,
                    .ca_ltm_bitplus_pxl_diff_slope      = 0x40,
    
                    .ca_ltm_pxl_diff_th_for_flat_pxl    = 0x0,
                    .ca_ltm_pxl_diff_slope_for_flat_pxl = 0x20,
    
                    .ca_ltm_pxl_diff_th                 = 0x0,
                    .ca_ltm_pxl_diff_slope              = 0x10,
    
                    .ca_ltm_s_lower2 = 0x8,
                    .ca_ltm_s_upper2 = 0x14,
                    .ca_ltm_y_lower2 = 0x46,
                    .ca_ltm_y_upper2 = 0xB0,
                    .ca_ltm_h_lower2 = 0x7D,
                    .ca_ltm_h_upper2 = 0x91,
    
                    .ca_ltm_s_lower3 = 0x18,
                    .ca_ltm_s_upper3 = 0x23,
                    .ca_ltm_y_lower3 = 0x46,
                    .ca_ltm_y_upper3 = 0x88,
                    .ca_ltm_h_lower3 = 0x55,
                    .ca_ltm_h_upper3 = 0x5C,
    
                    .ca_ltm_h_slope = 4,
                    .ca_ltm_s_slope = 4,
                    .ca_ltm_y_slope = 4,
                    .ca_ltm_h_slope2 = 4,
                    .ca_ltm_s_slope2 = 4,
                    .ca_ltm_y_slope2 = 4,
                    .ca_ltm_h_slope3 = 4,
                    .ca_ltm_s_slope3 = 4,
                    .ca_ltm_y_slope3 = 4,
    
                    .bilateral_flt_en = 1,
                    .bilateral_impulse_noise_en = 1,
                    .bilateral_range_flt_slope = 1,
                    .dre_bilateral_blending_wgt = 2,
                    .dre_bilateral_blending_en = 1,
                    .dre_bilateral_detect_en = 1,
                    .have_bilateral_filter = 1,
                },
    
                .CA_LTM_TUNINGREG = {
                    .ca_ltm_fw_en           = 1,
                    .ca_ltm_curve_en        = 1,
                    .ca_ltm_gain_flt_en     = 0,
                    .ca_ltm_iir_force_range = 1,
    
                    // Histogram FIR Weight
                    .bADLWeight1 = 0x14,
                    .bADLWeight2 = 0x2C,
                    .bADLWeight3 = 0x00,
    
                    // BS Basic Param
                    .bBSDCGain = 0x10,
                    .bBSACGain = 0x80,
                    .bBSLevel  = 0x0,
    
                    // Mid Param
                    .bMIDDCGain = 0x04,
                    .bMIDACGain = 0x20,
    
                    // WS Basic Param
                    .bWSDCGain = 0x10,
                    .bWSACGain = 0x80,
                    .bWSLevel  = 0x0,
    
                    // Spike Fallback Protection
                    .ca_ltm_dync_spike_wgt_min = 0x0,
                    .ca_ltm_dync_spike_wgt_max = 0xFF,
                    .ca_ltm_dync_spike_th      = 0x90,
                    .ca_ltm_dync_spike_slope   = 0x40,
                    .bSpikeBlendmethod      = 0x2,
    
                    // Skin processing
                    .bSkinWgtSlope    = 0xFF,
                    .bSkinBlendmethod = 0x2,
    
                    // Temporal Filtering
                    .ca_ltm_dync_flt_coef_min      = 0x8,
                    .ca_ltm_dync_flt_coef_max      = 0x20,
                    .ca_ltm_dync_flt_ovr_pxl_th    = 0x4,
                    .ca_ltm_dync_flt_ovr_pxl_slope = 0x32,
    
                    // Low Level Protection
                    .LLPValue = 0x0,
                    .LLPRatio = 0x0,
    
                    // APL Compensation
                    .APLCompRatioLow  = 0xC8,
                    .APLCompRatioHigh = 0xC8,
    
                    // Local Wgt1
                    .FltConfSlope = 0x12C,
                    .FltConfTh    = 0x0,
    
                    // Local Wgt2
                    .BlkHistCountRatio = 0x3,
                    .BinIdxDiffSlope   = 0xE0,
                    .BinIdxDiffTh      = 0x0,
                    .BinIdxDiffWgtOft  = 0x20,
                    .APLTh             = 0x10,
                    .APLSlope          = 0x80,
                    .APLWgtOft         = 0x100,
    
                    // Global APL Adjustment
                    .APL2Th     = 0x10,
                    .APL2Slope  = 0x80,
                    .APL2WgtOft = 0x100,
                    .APL2WgtMax = 0x100,
    
                    // Block Spatial Filtering
                    .BlkSpaFltEn   = 1,
                    .BlkSpaFltType = 0x0,
    
                    // for Tuning Tool Only
                    .LoadBlkCurveEn = 0,
                    .SaveBlkCurveEn = 0,
    
                    // Grass Protection
                    .bGreenWgtSlope = 0x25,
                    .dre_dync_compact_wgt_min = 0x0,
                    .dre_dync_compact_wgt_max = 0xFF,
                    .dre_dync_compact_th = 0x80,
                    .dre_dync_compact_slope = 0x20,
                    .bCompactBlendmethod = 0x2,
                    .dre_dync_compact_LowBoundBin = 0x5,
                    .dre_dync_compact_HighBoundBin = 0x7,
                    .dre_dync_compact_BinMinWeight = 0x100,
                    .dre_dync_compact_BinMaxWeight = 0x280,
                },
    
                .CA_LTM_ADAPTTUNINGREG = {
                    .Enabled = 1,
                    .Strength = 255,
                    .AdaptiveMethod = 0,
                    .AdaptiveType = 0,
                    .CustomParametersSearchMode = 0,
                },
            },
            {   //10
                .CA_LTM_INITUNINGRE  = {
                    .ca_ltm_s_lower = 0x18,
                    .ca_ltm_s_upper = 0x23,
                    .ca_ltm_y_lower = 0x46,
                    .ca_ltm_y_upper = 0x88,
                    .ca_ltm_h_lower = 0x55,
                    .ca_ltm_h_upper = 0x5C,
    
                    .ca_ltm_max_hist_mode               = 1,
                    .ca_ltm_bitplus_contour_range_th    = 0x2,
                    .ca_ltm_bitplus_contour_range_slope = 0x40,
                    .ca_ltm_bitplus_diff_count_th       = 0x3,
                    .ca_ltm_bitplus_diff_count_slope    = 0x2A,
                    .ca_ltm_bitplus_pxl_diff_th         = 0x0,
                    .ca_ltm_bitplus_pxl_diff_slope      = 0x40,
    
                    .ca_ltm_pxl_diff_th_for_flat_pxl    = 0x0,
                    .ca_ltm_pxl_diff_slope_for_flat_pxl = 0x20,
    
                    .ca_ltm_pxl_diff_th                 = 0x0,
                    .ca_ltm_pxl_diff_slope              = 0x10,
    
                    .ca_ltm_s_lower2 = 0x8,
                    .ca_ltm_s_upper2 = 0x14,
                    .ca_ltm_y_lower2 = 0x46,
                    .ca_ltm_y_upper2 = 0xB0,
                    .ca_ltm_h_lower2 = 0x7D,
                    .ca_ltm_h_upper2 = 0x91,
    
                    .ca_ltm_s_lower3 = 0x18,
                    .ca_ltm_s_upper3 = 0x23,
                    .ca_ltm_y_lower3 = 0x46,
                    .ca_ltm_y_upper3 = 0x88,
                    .ca_ltm_h_lower3 = 0x55,
                    .ca_ltm_h_upper3 = 0x5C,
    
                    .ca_ltm_h_slope = 4,
                    .ca_ltm_s_slope = 4,
                    .ca_ltm_y_slope = 4,
                    .ca_ltm_h_slope2 = 4,
                    .ca_ltm_s_slope2 = 4,
                    .ca_ltm_y_slope2 = 4,
                    .ca_ltm_h_slope3 = 4,
                    .ca_ltm_s_slope3 = 4,
                    .ca_ltm_y_slope3 = 4,
    
                    .bilateral_flt_en = 1,
                    .bilateral_impulse_noise_en = 1,
                    .bilateral_range_flt_slope = 1,
                    .dre_bilateral_blending_wgt = 2,
                    .dre_bilateral_blending_en = 1,
                    .dre_bilateral_detect_en = 1,
                    .have_bilateral_filter = 1,
                },
    
                .CA_LTM_TUNINGREG = {
                    .ca_ltm_fw_en           = 1,
                    .ca_ltm_curve_en        = 1,
                    .ca_ltm_gain_flt_en     = 0,
                    .ca_ltm_iir_force_range = 1,
    
                    // Histogram FIR Weight
                    .bADLWeight1 = 0x14,
                    .bADLWeight2 = 0x2C,
                    .bADLWeight3 = 0x00,
    
                    // BS Basic Param
                    .bBSDCGain = 0x10,
                    .bBSACGain = 0x80,
                    .bBSLevel  = 0x0,
    
                    // Mid Param
                    .bMIDDCGain = 0x04,
                    .bMIDACGain = 0x20,
    
                    // WS Basic Param
                    .bWSDCGain = 0x10,
                    .bWSACGain = 0x80,
                    .bWSLevel  = 0x0,
    
                    // Spike Fallback Protection
                    .ca_ltm_dync_spike_wgt_min = 0x0,
                    .ca_ltm_dync_spike_wgt_max = 0xFF,
                    .ca_ltm_dync_spike_th      = 0x90,
                    .ca_ltm_dync_spike_slope   = 0x40,
                    .bSpikeBlendmethod      = 0x2,
    
                    // Skin processing
                    .bSkinWgtSlope    = 0xFF,
                    .bSkinBlendmethod = 0x2,
    
                    // Temporal Filtering
                    .ca_ltm_dync_flt_coef_min      = 0x8,
                    .ca_ltm_dync_flt_coef_max      = 0x20,
                    .ca_ltm_dync_flt_ovr_pxl_th    = 0x4,
                    .ca_ltm_dync_flt_ovr_pxl_slope = 0x32,
    
                    // Low Level Protection
                    .LLPValue = 0x0,
                    .LLPRatio = 0x0,
    
                    // APL Compensation
                    .APLCompRatioLow  = 0xC8,
                    .APLCompRatioHigh = 0xC8,
    
                    // Local Wgt1
                    .FltConfSlope = 0x12C,
                    .FltConfTh    = 0x0,
    
                    // Local Wgt2
                    .BlkHistCountRatio = 0x3,
                    .BinIdxDiffSlope   = 0xE0,
                    .BinIdxDiffTh      = 0x0,
                    .BinIdxDiffWgtOft  = 0x20,
                    .APLTh             = 0x10,
                    .APLSlope          = 0x80,
                    .APLWgtOft         = 0x100,
    
                    // Global APL Adjustment
                    .APL2Th     = 0x10,
                    .APL2Slope  = 0x80,
                    .APL2WgtOft = 0x100,
                    .APL2WgtMax = 0x100,
    
                    // Block Spatial Filtering
                    .BlkSpaFltEn   = 1,
                    .BlkSpaFltType = 0x0,
    
                    // for Tuning Tool Only
                    .LoadBlkCurveEn = 0,
                    .SaveBlkCurveEn = 0,
    
                    // Grass Protection
                    .bGreenWgtSlope = 0x25,
                    .dre_dync_compact_wgt_min = 0x0,
                    .dre_dync_compact_wgt_max = 0xFF,
                    .dre_dync_compact_th = 0x80,
                    .dre_dync_compact_slope = 0x20,
                    .bCompactBlendmethod = 0x2,
                    .dre_dync_compact_LowBoundBin = 0x5,
                    .dre_dync_compact_HighBoundBin = 0x7,
                    .dre_dync_compact_BinMinWeight = 0x100,
                    .dre_dync_compact_BinMaxWeight = 0x280,
                },
    
                .CA_LTM_ADAPTTUNINGREG = {
                    .Enabled = 1,
                    .Strength = 255,
                    .AdaptiveMethod = 0,
                    .AdaptiveType = 0,
                    .CustomParametersSearchMode = 0,
                },
            },
            {   //11
                .CA_LTM_INITUNINGRE  = {
                    .ca_ltm_s_lower = 0x18,
                    .ca_ltm_s_upper = 0x23,
                    .ca_ltm_y_lower = 0x46,
                    .ca_ltm_y_upper = 0x88,
                    .ca_ltm_h_lower = 0x55,
                    .ca_ltm_h_upper = 0x5C,
    
                    .ca_ltm_max_hist_mode               = 1,
                    .ca_ltm_bitplus_contour_range_th    = 0x2,
                    .ca_ltm_bitplus_contour_range_slope = 0x40,
                    .ca_ltm_bitplus_diff_count_th       = 0x3,
                    .ca_ltm_bitplus_diff_count_slope    = 0x2A,
                    .ca_ltm_bitplus_pxl_diff_th         = 0x0,
                    .ca_ltm_bitplus_pxl_diff_slope      = 0x40,
    
                    .ca_ltm_pxl_diff_th_for_flat_pxl    = 0x0,
                    .ca_ltm_pxl_diff_slope_for_flat_pxl = 0x20,
    
                    .ca_ltm_pxl_diff_th                 = 0x0,
                    .ca_ltm_pxl_diff_slope              = 0x10,
    
                    .ca_ltm_s_lower2 = 0x8,
                    .ca_ltm_s_upper2 = 0x14,
                    .ca_ltm_y_lower2 = 0x46,
                    .ca_ltm_y_upper2 = 0xB0,
                    .ca_ltm_h_lower2 = 0x7D,
                    .ca_ltm_h_upper2 = 0x91,
    
                    .ca_ltm_s_lower3 = 0x18,
                    .ca_ltm_s_upper3 = 0x23,
                    .ca_ltm_y_lower3 = 0x46,
                    .ca_ltm_y_upper3 = 0x88,
                    .ca_ltm_h_lower3 = 0x55,
                    .ca_ltm_h_upper3 = 0x5C,
    
                    .ca_ltm_h_slope = 4,
                    .ca_ltm_s_slope = 4,
                    .ca_ltm_y_slope = 4,
                    .ca_ltm_h_slope2 = 4,
                    .ca_ltm_s_slope2 = 4,
                    .ca_ltm_y_slope2 = 4,
                    .ca_ltm_h_slope3 = 4,
                    .ca_ltm_s_slope3 = 4,
                    .ca_ltm_y_slope3 = 4,
    
                    .bilateral_flt_en = 1,
                    .bilateral_impulse_noise_en = 1,
                    .bilateral_range_flt_slope = 1,
                    .dre_bilateral_blending_wgt = 2,
                    .dre_bilateral_blending_en = 1,
                    .dre_bilateral_detect_en = 1,
                    .have_bilateral_filter = 1,
                },
    
                .CA_LTM_TUNINGREG = {
                    .ca_ltm_fw_en           = 1,
                    .ca_ltm_curve_en        = 1,
                    .ca_ltm_gain_flt_en     = 0,
                    .ca_ltm_iir_force_range = 1,
    
                    // Histogram FIR Weight
                    .bADLWeight1 = 0x14,
                    .bADLWeight2 = 0x2C,
                    .bADLWeight3 = 0x00,
    
                    // BS Basic Param
                    .bBSDCGain = 0x10,
                    .bBSACGain = 0x80,
                    .bBSLevel  = 0x0,
    
                    // Mid Param
                    .bMIDDCGain = 0x04,
                    .bMIDACGain = 0x20,
    
                    // WS Basic Param
                    .bWSDCGain = 0x10,
                    .bWSACGain = 0x80,
                    .bWSLevel  = 0x0,
    
                    // Spike Fallback Protection
                    .ca_ltm_dync_spike_wgt_min = 0x0,
                    .ca_ltm_dync_spike_wgt_max = 0xFF,
                    .ca_ltm_dync_spike_th      = 0x90,
                    .ca_ltm_dync_spike_slope   = 0x40,
                    .bSpikeBlendmethod      = 0x2,
    
                    // Skin processing
                    .bSkinWgtSlope    = 0xFF,
                    .bSkinBlendmethod = 0x2,
    
                    // Temporal Filtering
                    .ca_ltm_dync_flt_coef_min      = 0x8,
                    .ca_ltm_dync_flt_coef_max      = 0x20,
                    .ca_ltm_dync_flt_ovr_pxl_th    = 0x4,
                    .ca_ltm_dync_flt_ovr_pxl_slope = 0x32,
    
                    // Low Level Protection
                    .LLPValue = 0x0,
                    .LLPRatio = 0x0,
    
                    // APL Compensation
                    .APLCompRatioLow  = 0xC8,
                    .APLCompRatioHigh = 0xC8,
    
                    // Local Wgt1
                    .FltConfSlope = 0x12C,
                    .FltConfTh    = 0x0,
    
                    // Local Wgt2
                    .BlkHistCountRatio = 0x3,
                    .BinIdxDiffSlope   = 0xE0,
                    .BinIdxDiffTh      = 0x0,
                    .BinIdxDiffWgtOft  = 0x20,
                    .APLTh             = 0x10,
                    .APLSlope          = 0x80,
                    .APLWgtOft         = 0x100,
    
                    // Global APL Adjustment
                    .APL2Th     = 0x10,
                    .APL2Slope  = 0x80,
                    .APL2WgtOft = 0x100,
                    .APL2WgtMax = 0x100,
    
                    // Block Spatial Filtering
                    .BlkSpaFltEn   = 1,
                    .BlkSpaFltType = 0x0,
    
                    // for Tuning Tool Only
                    .LoadBlkCurveEn = 0,
                    .SaveBlkCurveEn = 0,
    
                    // Grass Protection
                    .bGreenWgtSlope = 0x25,
                    .dre_dync_compact_wgt_min = 0x0,
                    .dre_dync_compact_wgt_max = 0xFF,
                    .dre_dync_compact_th = 0x80,
                    .dre_dync_compact_slope = 0x20,
                    .bCompactBlendmethod = 0x2,
                    .dre_dync_compact_LowBoundBin = 0x5,
                    .dre_dync_compact_HighBoundBin = 0x7,
                    .dre_dync_compact_BinMinWeight = 0x100,
                    .dre_dync_compact_BinMaxWeight = 0x280,
                },
    
                .CA_LTM_ADAPTTUNINGREG = {
                    .Enabled = 1,
                    .Strength = 255,
                    .AdaptiveMethod = 0,
                    .AdaptiveType = 0,
                    .CustomParametersSearchMode = 0,
                },
            },
            {   //12
                .CA_LTM_INITUNINGRE  = {
                    .ca_ltm_s_lower = 0x18,
                    .ca_ltm_s_upper = 0x23,
                    .ca_ltm_y_lower = 0x46,
                    .ca_ltm_y_upper = 0x88,
                    .ca_ltm_h_lower = 0x55,
                    .ca_ltm_h_upper = 0x5C,
    
                    .ca_ltm_max_hist_mode               = 1,
                    .ca_ltm_bitplus_contour_range_th    = 0x2,
                    .ca_ltm_bitplus_contour_range_slope = 0x40,
                    .ca_ltm_bitplus_diff_count_th       = 0x3,
                    .ca_ltm_bitplus_diff_count_slope    = 0x2A,
                    .ca_ltm_bitplus_pxl_diff_th         = 0x0,
                    .ca_ltm_bitplus_pxl_diff_slope      = 0x40,
    
                    .ca_ltm_pxl_diff_th_for_flat_pxl    = 0x0,
                    .ca_ltm_pxl_diff_slope_for_flat_pxl = 0x20,
    
                    .ca_ltm_pxl_diff_th                 = 0x0,
                    .ca_ltm_pxl_diff_slope              = 0x10,
    
                    .ca_ltm_s_lower2 = 0x8,
                    .ca_ltm_s_upper2 = 0x14,
                    .ca_ltm_y_lower2 = 0x46,
                    .ca_ltm_y_upper2 = 0xB0,
                    .ca_ltm_h_lower2 = 0x7D,
                    .ca_ltm_h_upper2 = 0x91,
    
                    .ca_ltm_s_lower3 = 0x18,
                    .ca_ltm_s_upper3 = 0x23,
                    .ca_ltm_y_lower3 = 0x46,
                    .ca_ltm_y_upper3 = 0x88,
                    .ca_ltm_h_lower3 = 0x55,
                    .ca_ltm_h_upper3 = 0x5C,
    
                    .ca_ltm_h_slope = 4,
                    .ca_ltm_s_slope = 4,
                    .ca_ltm_y_slope = 4,
                    .ca_ltm_h_slope2 = 4,
                    .ca_ltm_s_slope2 = 4,
                    .ca_ltm_y_slope2 = 4,
                    .ca_ltm_h_slope3 = 4,
                    .ca_ltm_s_slope3 = 4,
                    .ca_ltm_y_slope3 = 4,
    
                    .bilateral_flt_en = 1,
                    .bilateral_impulse_noise_en = 1,
                    .bilateral_range_flt_slope = 1,
                    .dre_bilateral_blending_wgt = 2,
                    .dre_bilateral_blending_en = 1,
                    .dre_bilateral_detect_en = 1,
                    .have_bilateral_filter = 1,
                },
    
                .CA_LTM_TUNINGREG = {
                    .ca_ltm_fw_en           = 1,
                    .ca_ltm_curve_en        = 1,
                    .ca_ltm_gain_flt_en     = 0,
                    .ca_ltm_iir_force_range = 1,
    
                    // Histogram FIR Weight
                    .bADLWeight1 = 0x14,
                    .bADLWeight2 = 0x2C,
                    .bADLWeight3 = 0x00,
    
                    // BS Basic Param
                    .bBSDCGain = 0x10,
                    .bBSACGain = 0x80,
                    .bBSLevel  = 0x0,
    
                    // Mid Param
                    .bMIDDCGain = 0x04,
                    .bMIDACGain = 0x20,
    
                    // WS Basic Param
                    .bWSDCGain = 0x10,
                    .bWSACGain = 0x80,
                    .bWSLevel  = 0x0,
    
                    // Spike Fallback Protection
                    .ca_ltm_dync_spike_wgt_min = 0x0,
                    .ca_ltm_dync_spike_wgt_max = 0xFF,
                    .ca_ltm_dync_spike_th      = 0x90,
                    .ca_ltm_dync_spike_slope   = 0x40,
                    .bSpikeBlendmethod      = 0x2,
    
                    // Skin processing
                    .bSkinWgtSlope    = 0xFF,
                    .bSkinBlendmethod = 0x2,
    
                    // Temporal Filtering
                    .ca_ltm_dync_flt_coef_min      = 0x8,
                    .ca_ltm_dync_flt_coef_max      = 0x20,
                    .ca_ltm_dync_flt_ovr_pxl_th    = 0x4,
                    .ca_ltm_dync_flt_ovr_pxl_slope = 0x32,
    
                    // Low Level Protection
                    .LLPValue = 0x0,
                    .LLPRatio = 0x0,
    
                    // APL Compensation
                    .APLCompRatioLow  = 0xC8,
                    .APLCompRatioHigh = 0xC8,
    
                    // Local Wgt1
                    .FltConfSlope = 0x12C,
                    .FltConfTh    = 0x0,
    
                    // Local Wgt2
                    .BlkHistCountRatio = 0x3,
                    .BinIdxDiffSlope   = 0xE0,
                    .BinIdxDiffTh      = 0x0,
                    .BinIdxDiffWgtOft  = 0x20,
                    .APLTh             = 0x10,
                    .APLSlope          = 0x80,
                    .APLWgtOft         = 0x100,
    
                    // Global APL Adjustment
                    .APL2Th     = 0x10,
                    .APL2Slope  = 0x80,
                    .APL2WgtOft = 0x100,
                    .APL2WgtMax = 0x100,
    
                    // Block Spatial Filtering
                    .BlkSpaFltEn   = 1,
                    .BlkSpaFltType = 0x0,
    
                    // for Tuning Tool Only
                    .LoadBlkCurveEn = 0,
                    .SaveBlkCurveEn = 0,
    
                    // Grass Protection
                    .bGreenWgtSlope = 0x25,
                    .dre_dync_compact_wgt_min = 0x0,
                    .dre_dync_compact_wgt_max = 0xFF,
                    .dre_dync_compact_th = 0x80,
                    .dre_dync_compact_slope = 0x20,
                    .bCompactBlendmethod = 0x2,
                    .dre_dync_compact_LowBoundBin = 0x5,
                    .dre_dync_compact_HighBoundBin = 0x7,
                    .dre_dync_compact_BinMinWeight = 0x100,
                    .dre_dync_compact_BinMaxWeight = 0x280,
                },
    
                .CA_LTM_ADAPTTUNINGREG = {
                    .Enabled = 1,
                    .Strength = 255,
                    .AdaptiveMethod = 0,
                    .AdaptiveType = 0,
                    .CustomParametersSearchMode = 0,
                },
            },
            {   //13
                .CA_LTM_INITUNINGRE  = {
                    .ca_ltm_s_lower = 0x18,
                    .ca_ltm_s_upper = 0x23,
                    .ca_ltm_y_lower = 0x46,
                    .ca_ltm_y_upper = 0x88,
                    .ca_ltm_h_lower = 0x55,
                    .ca_ltm_h_upper = 0x5C,
    
                    .ca_ltm_max_hist_mode               = 1,
                    .ca_ltm_bitplus_contour_range_th    = 0x2,
                    .ca_ltm_bitplus_contour_range_slope = 0x40,
                    .ca_ltm_bitplus_diff_count_th       = 0x3,
                    .ca_ltm_bitplus_diff_count_slope    = 0x2A,
                    .ca_ltm_bitplus_pxl_diff_th         = 0x0,
                    .ca_ltm_bitplus_pxl_diff_slope      = 0x40,
    
                    .ca_ltm_pxl_diff_th_for_flat_pxl    = 0x0,
                    .ca_ltm_pxl_diff_slope_for_flat_pxl = 0x20,
    
                    .ca_ltm_pxl_diff_th                 = 0x0,
                    .ca_ltm_pxl_diff_slope              = 0x10,
    
                    .ca_ltm_s_lower2 = 0x8,
                    .ca_ltm_s_upper2 = 0x14,
                    .ca_ltm_y_lower2 = 0x46,
                    .ca_ltm_y_upper2 = 0xB0,
                    .ca_ltm_h_lower2 = 0x7D,
                    .ca_ltm_h_upper2 = 0x91,
    
                    .ca_ltm_s_lower3 = 0x18,
                    .ca_ltm_s_upper3 = 0x23,
                    .ca_ltm_y_lower3 = 0x46,
                    .ca_ltm_y_upper3 = 0x88,
                    .ca_ltm_h_lower3 = 0x55,
                    .ca_ltm_h_upper3 = 0x5C,
    
                    .ca_ltm_h_slope = 4,
                    .ca_ltm_s_slope = 4,
                    .ca_ltm_y_slope = 4,
                    .ca_ltm_h_slope2 = 4,
                    .ca_ltm_s_slope2 = 4,
                    .ca_ltm_y_slope2 = 4,
                    .ca_ltm_h_slope3 = 4,
                    .ca_ltm_s_slope3 = 4,
                    .ca_ltm_y_slope3 = 4,
    
                    .bilateral_flt_en = 1,
                    .bilateral_impulse_noise_en = 1,
                    .bilateral_range_flt_slope = 1,
                    .dre_bilateral_blending_wgt = 2,
                    .dre_bilateral_blending_en = 1,
                    .dre_bilateral_detect_en = 1,
                    .have_bilateral_filter = 1,
                },
    
                .CA_LTM_TUNINGREG = {
                    .ca_ltm_fw_en           = 1,
                    .ca_ltm_curve_en        = 1,
                    .ca_ltm_gain_flt_en     = 0,
                    .ca_ltm_iir_force_range = 1,
    
                    // Histogram FIR Weight
                    .bADLWeight1 = 0x14,
                    .bADLWeight2 = 0x2C,
                    .bADLWeight3 = 0x00,
    
                    // BS Basic Param
                    .bBSDCGain = 0x10,
                    .bBSACGain = 0x80,
                    .bBSLevel  = 0x0,
    
                    // Mid Param
                    .bMIDDCGain = 0x04,
                    .bMIDACGain = 0x20,
    
                    // WS Basic Param
                    .bWSDCGain = 0x10,
                    .bWSACGain = 0x80,
                    .bWSLevel  = 0x0,
    
                    // Spike Fallback Protection
                    .ca_ltm_dync_spike_wgt_min = 0x0,
                    .ca_ltm_dync_spike_wgt_max = 0xFF,
                    .ca_ltm_dync_spike_th      = 0x90,
                    .ca_ltm_dync_spike_slope   = 0x40,
                    .bSpikeBlendmethod      = 0x2,
    
                    // Skin processing
                    .bSkinWgtSlope    = 0xFF,
                    .bSkinBlendmethod = 0x2,
    
                    // Temporal Filtering
                    .ca_ltm_dync_flt_coef_min      = 0x8,
                    .ca_ltm_dync_flt_coef_max      = 0x20,
                    .ca_ltm_dync_flt_ovr_pxl_th    = 0x4,
                    .ca_ltm_dync_flt_ovr_pxl_slope = 0x32,
    
                    // Low Level Protection
                    .LLPValue = 0x0,
                    .LLPRatio = 0x0,
    
                    // APL Compensation
                    .APLCompRatioLow  = 0xC8,
                    .APLCompRatioHigh = 0xC8,
    
                    // Local Wgt1
                    .FltConfSlope = 0x12C,
                    .FltConfTh    = 0x0,
    
                    // Local Wgt2
                    .BlkHistCountRatio = 0x3,
                    .BinIdxDiffSlope   = 0xE0,
                    .BinIdxDiffTh      = 0x0,
                    .BinIdxDiffWgtOft  = 0x20,
                    .APLTh             = 0x10,
                    .APLSlope          = 0x80,
                    .APLWgtOft         = 0x100,
    
                    // Global APL Adjustment
                    .APL2Th     = 0x10,
                    .APL2Slope  = 0x80,
                    .APL2WgtOft = 0x100,
                    .APL2WgtMax = 0x100,
    
                    // Block Spatial Filtering
                    .BlkSpaFltEn   = 1,
                    .BlkSpaFltType = 0x0,
    
                    // for Tuning Tool Only
                    .LoadBlkCurveEn = 0,
                    .SaveBlkCurveEn = 0,
    
                    // Grass Protection
                    .bGreenWgtSlope = 0x25,
                    .dre_dync_compact_wgt_min = 0x0,
                    .dre_dync_compact_wgt_max = 0xFF,
                    .dre_dync_compact_th = 0x80,
                    .dre_dync_compact_slope = 0x20,
                    .bCompactBlendmethod = 0x2,
                    .dre_dync_compact_LowBoundBin = 0x5,
                    .dre_dync_compact_HighBoundBin = 0x7,
                    .dre_dync_compact_BinMinWeight = 0x100,
                    .dre_dync_compact_BinMaxWeight = 0x280,
                },
    
                .CA_LTM_ADAPTTUNINGREG = {
                    .Enabled = 1,
                    .Strength = 255,
                    .AdaptiveMethod = 0,
                    .AdaptiveType = 0,
                    .CustomParametersSearchMode = 0,
                },
            },
            {   //14
                .CA_LTM_INITUNINGRE  = {
                    .ca_ltm_s_lower = 0x18,
                    .ca_ltm_s_upper = 0x23,
                    .ca_ltm_y_lower = 0x46,
                    .ca_ltm_y_upper = 0x88,
                    .ca_ltm_h_lower = 0x55,
                    .ca_ltm_h_upper = 0x5C,
    
                    .ca_ltm_max_hist_mode               = 1,
                    .ca_ltm_bitplus_contour_range_th    = 0x2,
                    .ca_ltm_bitplus_contour_range_slope = 0x40,
                    .ca_ltm_bitplus_diff_count_th       = 0x3,
                    .ca_ltm_bitplus_diff_count_slope    = 0x2A,
                    .ca_ltm_bitplus_pxl_diff_th         = 0x0,
                    .ca_ltm_bitplus_pxl_diff_slope      = 0x40,
    
                    .ca_ltm_pxl_diff_th_for_flat_pxl    = 0x0,
                    .ca_ltm_pxl_diff_slope_for_flat_pxl = 0x20,
    
                    .ca_ltm_pxl_diff_th                 = 0x0,
                    .ca_ltm_pxl_diff_slope              = 0x10,
    
                    .ca_ltm_s_lower2 = 0x8,
                    .ca_ltm_s_upper2 = 0x14,
                    .ca_ltm_y_lower2 = 0x46,
                    .ca_ltm_y_upper2 = 0xB0,
                    .ca_ltm_h_lower2 = 0x7D,
                    .ca_ltm_h_upper2 = 0x91,
    
                    .ca_ltm_s_lower3 = 0x18,
                    .ca_ltm_s_upper3 = 0x23,
                    .ca_ltm_y_lower3 = 0x46,
                    .ca_ltm_y_upper3 = 0x88,
                    .ca_ltm_h_lower3 = 0x55,
                    .ca_ltm_h_upper3 = 0x5C,
    
                    .ca_ltm_h_slope = 4,
                    .ca_ltm_s_slope = 4,
                    .ca_ltm_y_slope = 4,
                    .ca_ltm_h_slope2 = 4,
                    .ca_ltm_s_slope2 = 4,
                    .ca_ltm_y_slope2 = 4,
                    .ca_ltm_h_slope3 = 4,
                    .ca_ltm_s_slope3 = 4,
                    .ca_ltm_y_slope3 = 4,
    
                    .bilateral_flt_en = 1,
                    .bilateral_impulse_noise_en = 1,
                    .bilateral_range_flt_slope = 1,
                    .dre_bilateral_blending_wgt = 2,
                    .dre_bilateral_blending_en = 1,
                    .dre_bilateral_detect_en = 1,
                    .have_bilateral_filter = 1,
                },
    
                .CA_LTM_TUNINGREG = {
                    .ca_ltm_fw_en           = 1,
                    .ca_ltm_curve_en        = 1,
                    .ca_ltm_gain_flt_en     = 0,
                    .ca_ltm_iir_force_range = 1,
    
                    // Histogram FIR Weight
                    .bADLWeight1 = 0x14,
                    .bADLWeight2 = 0x2C,
                    .bADLWeight3 = 0x00,
    
                    // BS Basic Param
                    .bBSDCGain = 0x10,
                    .bBSACGain = 0x80,
                    .bBSLevel  = 0x0,
    
                    // Mid Param
                    .bMIDDCGain = 0x04,
                    .bMIDACGain = 0x20,
    
                    // WS Basic Param
                    .bWSDCGain = 0x10,
                    .bWSACGain = 0x80,
                    .bWSLevel  = 0x0,
    
                    // Spike Fallback Protection
                    .ca_ltm_dync_spike_wgt_min = 0x0,
                    .ca_ltm_dync_spike_wgt_max = 0xFF,
                    .ca_ltm_dync_spike_th      = 0x90,
                    .ca_ltm_dync_spike_slope   = 0x40,
                    .bSpikeBlendmethod      = 0x2,
    
                    // Skin processing
                    .bSkinWgtSlope    = 0xFF,
                    .bSkinBlendmethod = 0x2,
    
                    // Temporal Filtering
                    .ca_ltm_dync_flt_coef_min      = 0x8,
                    .ca_ltm_dync_flt_coef_max      = 0x20,
                    .ca_ltm_dync_flt_ovr_pxl_th    = 0x4,
                    .ca_ltm_dync_flt_ovr_pxl_slope = 0x32,
    
                    // Low Level Protection
                    .LLPValue = 0x0,
                    .LLPRatio = 0x0,
    
                    // APL Compensation
                    .APLCompRatioLow  = 0xC8,
                    .APLCompRatioHigh = 0xC8,
    
                    // Local Wgt1
                    .FltConfSlope = 0x12C,
                    .FltConfTh    = 0x0,
    
                    // Local Wgt2
                    .BlkHistCountRatio = 0x3,
                    .BinIdxDiffSlope   = 0xE0,
                    .BinIdxDiffTh      = 0x0,
                    .BinIdxDiffWgtOft  = 0x20,
                    .APLTh             = 0x10,
                    .APLSlope          = 0x80,
                    .APLWgtOft         = 0x100,
    
                    // Global APL Adjustment
                    .APL2Th     = 0x10,
                    .APL2Slope  = 0x80,
                    .APL2WgtOft = 0x100,
                    .APL2WgtMax = 0x100,
    
                    // Block Spatial Filtering
                    .BlkSpaFltEn   = 1,
                    .BlkSpaFltType = 0x0,
    
                    // for Tuning Tool Only
                    .LoadBlkCurveEn = 0,
                    .SaveBlkCurveEn = 0,
    
                    // Grass Protection
                    .bGreenWgtSlope = 0x25,
                    .dre_dync_compact_wgt_min = 0x0,
                    .dre_dync_compact_wgt_max = 0xFF,
                    .dre_dync_compact_th = 0x80,
                    .dre_dync_compact_slope = 0x20,
                    .bCompactBlendmethod = 0x2,
                    .dre_dync_compact_LowBoundBin = 0x5,
                    .dre_dync_compact_HighBoundBin = 0x7,
                    .dre_dync_compact_BinMinWeight = 0x100,
                    .dre_dync_compact_BinMaxWeight = 0x280,
                },
    
                .CA_LTM_ADAPTTUNINGREG = {
                    .Enabled = 1,
                    .Strength = 255,
                    .AdaptiveMethod = 0,
                    .AdaptiveType = 0,
                    .CustomParametersSearchMode = 0,
                },
            },
        }
    },
};
