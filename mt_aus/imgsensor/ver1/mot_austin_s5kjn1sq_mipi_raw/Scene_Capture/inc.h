/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2021. All rights reserved.
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
#ifndef _SCENE_CAPTURE_H
#define _SCENE_CAPTURE_H

#include "camera_custom_nvram.h"

#include "camera_custom_isp_nvram.h"

#define M_CONC(A, B) M_CONC_(A, B)
#define M_CONC_(A, B) A##_##B

#define AE_AE_BASE                                                   M_CONC(TARGET_SENSOR, AE_0000)
#define AF_AF_BASE                                                   M_CONC(TARGET_SENSOR, AF_0000)
#define AWB_AWB_BASE                                                 M_CONC(TARGET_SENSOR, AWB_0000)
#define Flash_AE_Flash_AE_BASE                                       M_CONC(TARGET_SENSOR, Flash_AE_0000)
#define Flash_AWB_Flash_AWB_BASE                                     M_CONC(TARGET_SENSOR, Flash_AWB_0000)
#define Flash_Calibration_Flash_Calibration_BASE                     M_CONC(TARGET_SENSOR, Flash_Calibration_0000)
#define LCE_TONE_BASE                                                M_CONC(TARGET_SENSOR, LCE_0000)
#define GMA_TONE_BASE                                                M_CONC(TARGET_SENSOR, GMA_0000)
#define DCE_TONE_BASE                                                M_CONC(TARGET_SENSOR, DCE_0000)
#define LTM_TONE_BASE                                                M_CONC(TARGET_SENSOR, LTM_0000)
#define HLR_TONE_BASE                                                M_CONC(TARGET_SENSOR, HLR_0000)
#define GMA_R3_TONE_BASE                                             M_CONC(TARGET_SENSOR, GMA_R3_0000)
#define DM_ISP_YUV_BASE                                              M_CONC(TARGET_SENSOR, DM_0000)
#define YNR_ISP_YUV_BASE                                             M_CONC(TARGET_SENSOR, YNR_0000)
#define YNR_LCE_LINK_ISP_YUV_BASE                                    M_CONC(TARGET_SENSOR, YNR_LCE_LINK_0000)
#define YNR_FD_ISP_YUV_BASE                                          M_CONC(TARGET_SENSOR, YNR_FD_0000)
#define CNR_CNR_ISP_YUV_BASE                                         M_CONC(TARGET_SENSOR, CNR_CNR_0000)
#define EE_ISP_YUV_BASE                                              M_CONC(TARGET_SENSOR, EE_0000)
#define NR3D_ISP_YUV_BASE                                            M_CONC(TARGET_SENSOR, NR3D_0000)
#define HFG_ISP_YUV_BASE                                             M_CONC(TARGET_SENSOR, HFG_0000)
#define AKS_ISP_YUV_BASE                                             M_CONC(TARGET_SENSOR, AKS_0000)
#define AD_NR_ISP_YUV_BASE                                           M_CONC(TARGET_SENSOR, AD_NR_0000)
#define DM_ISP_MFNR_BASE                                             M_CONC(TARGET_SENSOR, DM_0013)
#define YNR_ISP_MFNR_BASE                                            M_CONC(TARGET_SENSOR, YNR_0026)
#define CNR_CNR_ISP_MFNR_BASE                                        M_CONC(TARGET_SENSOR, CNR_CNR_0013)
#define EE_ISP_MFNR_BASE                                             M_CONC(TARGET_SENSOR, EE_0026)
#define LDNR_ISP_MFNR_BASE                                           M_CONC(TARGET_SENSOR, LDNR_0013)
#define CNR_CCR_ISP_MFNR_BASE                                        M_CONC(TARGET_SENSOR, CNR_CCR_0013)
#define CNR_ABF_ISP_MFNR_BASE                                        M_CONC(TARGET_SENSOR, CNR_ABF_0013)
#define MFNR_THRES_ISP_MFNR_BASE                                     M_CONC(TARGET_SENSOR, MFNR_THRES_0000)
#define MFNR_ISP_MFNR_BASE                                           M_CONC(TARGET_SENSOR, MFNR_0000)
#define BSS_ISP_MFNR_BASE                                            M_CONC(TARGET_SENSOR, BSS_0000)
#define AKS_ISP_MFNR_BASE                                            M_CONC(TARGET_SENSOR, AKS_0013)
#define SW_MSF_ISP_MFNR_BASE                                         M_CONC(TARGET_SENSOR, SW_MSF_0000)
#define MSYUV_ISP_MFNR_BASE                                          M_CONC(TARGET_SENSOR, MSYUV_0013)
#define OMC_ISP_MFNR_BASE                                            M_CONC(TARGET_SENSOR, OMC_0000)
#define DM_ISP_AIISP_BASE                                            M_CONC(TARGET_SENSOR, DM_0026)
#define YNR_ISP_AIISP_BASE                                           M_CONC(TARGET_SENSOR, YNR_0052)
#define YNR_LCE_LINK_ISP_AIISP_BASE                                  M_CONC(TARGET_SENSOR, YNR_LCE_LINK_0013)
#define YNR_FD_ISP_AIISP_BASE                                        M_CONC(TARGET_SENSOR, YNR_FD_0013)
#define CNR_CNR_ISP_AIISP_BASE                                       M_CONC(TARGET_SENSOR, CNR_CNR_0039)
#define EE_ISP_AIISP_BASE                                            M_CONC(TARGET_SENSOR, EE_0039)
#define BPC_BPC_ISP_AIISP_BASE                                       M_CONC(TARGET_SENSOR, BPC_BPC_0013)
#define BPC_CT_ISP_AIISP_BASE                                        M_CONC(TARGET_SENSOR, BPC_CT_0013)
#define BPC_PDC_ISP_AIISP_BASE                                       M_CONC(TARGET_SENSOR, BPC_PDC_0013)
#define LDNR_ISP_AIISP_BASE                                          M_CONC(TARGET_SENSOR, LDNR_0026)
#define AKS_ISP_AIISP_BASE                                           M_CONC(TARGET_SENSOR, AKS_0026)
#define MSYUV_ISP_AIISP_BASE                                         M_CONC(TARGET_SENSOR, MSYUV_0026)
#define AIISP_EV_ISP_AIISP_BASE                                      M_CONC(TARGET_SENSOR, AIISP_EV_0000)
#define AIISP_ISO_FEFM_ISP_AIISP_BASE                                M_CONC(TARGET_SENSOR, AIISP_ISO_FEFM_0000)
#define AIISP_ISO_SWME_ISP_AIISP_BASE                                M_CONC(TARGET_SENSOR, AIISP_ISO_SWME_0000)
#define AIISP_ISO_APU_Part1_ISP_AIISP_BASE                           M_CONC(TARGET_SENSOR, AIISP_ISO_APU_Part1_0000)
#define AIISP_ISO_APU_Part2_ISP_AIISP_BASE                           M_CONC(TARGET_SENSOR, AIISP_ISO_APU_Part2_0000)
#define AIISP_ISO_APU_Part3_ISP_AIISP_BASE                           M_CONC(TARGET_SENSOR, AIISP_ISO_APU_Part3_0000)
#define AIISP_ISO_PostSW_ISP_AIISP_BASE                              M_CONC(TARGET_SENSOR, AIISP_ISO_PostSW_0000)
#define AIISP_ISO_DRC_ISP_AIISP_BASE                                 M_CONC(TARGET_SENSOR, AIISP_ISO_DRC_0000)
#define YNR_ISP_MSNR_BASE                                            M_CONC(TARGET_SENSOR, YNR_0013)
#define EE_ISP_MSNR_BASE                                             M_CONC(TARGET_SENSOR, EE_0013)
#define MSYUV_ISP_MSNR_BASE                                          M_CONC(TARGET_SENSOR, MSYUV_0000)
#define MSNR_THRES_ISP_MSNR_BASE                                     M_CONC(TARGET_SENSOR, MSNR_THRES_0000)
#define OBC_ISP_RAW_BASE                                             M_CONC(TARGET_SENSOR, OBC_0000)
#define BPC_BPC_ISP_RAW_BASE                                         M_CONC(TARGET_SENSOR, BPC_BPC_0000)
#define BPC_CT_ISP_RAW_BASE                                          M_CONC(TARGET_SENSOR, BPC_CT_0000)
#define BPC_PDC_ISP_RAW_BASE                                         M_CONC(TARGET_SENSOR, BPC_PDC_0000)
#define LDNR_ISP_RAW_BASE                                            M_CONC(TARGET_SENSOR, LDNR_0000)
#define FRZ_ISP_RAW_BASE                                             M_CONC(TARGET_SENSOR, FRZ_0000)
#define RRZ_ISP_RAW_BASE                                             M_CONC(TARGET_SENSOR, RRZ_0000)
#define BPC_BPC_R3_ISP_RAW_BASE                                      M_CONC(TARGET_SENSOR, BPC_BPC_R3_0000)
#define BPC_CT_R3_ISP_RAW_BASE                                       M_CONC(TARGET_SENSOR, BPC_CT_R3_0000)
#define BPC_PDC_R3_ISP_RAW_BASE                                      M_CONC(TARGET_SENSOR, BPC_PDC_R3_0000)
#define OBC_R2_ISP_RAW_BASE                                          M_CONC(TARGET_SENSOR, OBC_R2_0000)
#define BPC_BPC_R2_ISP_RAW_BASE                                      M_CONC(TARGET_SENSOR, BPC_BPC_R2_0000)
#define OBC_R3_ISP_RAW_BASE                                          M_CONC(TARGET_SENSOR, OBC_R3_0000)
#define BPC_CT_R2_ISP_RAW_BASE                                       M_CONC(TARGET_SENSOR, BPC_CT_R2_0000)
#define BPC_PDC_R2_ISP_RAW_BASE                                      M_CONC(TARGET_SENSOR, BPC_PDC_R2_0000)
#define CNR_CCR_ISP_Other_BASE                                       M_CONC(TARGET_SENSOR, CNR_CCR_0000)
#define CNR_ABF_ISP_Other_BASE                                       M_CONC(TARGET_SENSOR, CNR_ABF_0000)
#define FUS_ISP_Other_BASE                                           M_CONC(TARGET_SENSOR, FUS_0000)
#define ZFUS_ISP_Other_BASE                                          M_CONC(TARGET_SENSOR, ZFUS_0000)
#define CA_LTM_CA_LTM_BASE                                           M_CONC(TARGET_SENSOR, CA_LTM_0000)
#define CCM_CCM_BASE                                                 M_CONC(TARGET_SENSOR, CCM_0000)
#define CCM_R3_CCM_BASE                                              M_CONC(TARGET_SENSOR, CCM_R3_0000)
#define COLOR_PARAM_COLOR_BASE                                       M_CONC(TARGET_SENSOR, COLOR_PARAM_0000)
#define COLOR_COLOR_BASE                                             M_CONC(TARGET_SENSOR, COLOR_0000)
#define ClearZoom_ClearZoom_BASE                                     M_CONC(TARGET_SENSOR, ClearZoom_0000)
#define YNR_TBL_ISP_YNR_TBL_BASE                                     M_CONC(TARGET_SENSOR, YNR_TBL_0000)
#define AIISP_LV_Pre_ISP_AIISP_LV_BASE                               M_CONC(TARGET_SENSOR, AIISP_LV_Pre_0000)
#define AIAWB_MA_AIAWB_MA_BASE                                       M_CONC(TARGET_SENSOR, AIAWB_MA_0000)
#define AIAWB_SA_AIAWB_SA_BASE                                       M_CONC(TARGET_SENSOR, AIAWB_SA_0000)
#define P1GGM_P1GGM_BASE                                             M_CONC(TARGET_SENSOR, P1GGM_0000)

extern const AE_NVRAM_T                                              AE_AE_BASE[1];
extern const NVRAM_LENS_DATA_PARA_STRUCT                             AF_AF_BASE[1];
extern const AWB_NVRAM_T                                             AWB_AWB_BASE[1];
extern const FLASH_AE_NVRAM_T                                        Flash_AE_Flash_AE_BASE[1];
extern const FLASH_AWB_NVRAM_T                                       Flash_AWB_Flash_AWB_BASE[1];
extern const FLASH_CALIBRATION_NVRAM_T                               Flash_Calibration_Flash_Calibration_BASE[1];
extern const ISP_NVRAM_LCE_TUNING_PARAM_T                            LCE_TONE_BASE[1];
extern const ISP_NVRAM_GMA_STRUCT_T                                  GMA_TONE_BASE[1];
extern const ISP_NVRAM_DCE_TUNING_PARAM_T                            DCE_TONE_BASE[1];
extern const ISP_NVRAM_LTM_TUNING_PARAM_T                            LTM_TONE_BASE[1];
extern const ISP_NVRAM_HLR_TUNING_PARAM_T                            HLR_TONE_BASE[1];
extern const ISP_NVRAM_GMA_STRUCT_T                                  GMA_R3_TONE_BASE[1];
extern const ISP_NVRAM_DM_T                                          DM_ISP_YUV_BASE[13];
extern const ISP_NVRAM_YNR_T                                         YNR_ISP_YUV_BASE[13];
extern const ISP_NVRAM_YNR_LCE_LINK_T                                YNR_LCE_LINK_ISP_YUV_BASE[13];
extern const ISP_NVRAM_YNR_FD_T                                      YNR_FD_ISP_YUV_BASE[13];
extern const ISP_NVRAM_CNR_CNR_T                                     CNR_CNR_ISP_YUV_BASE[13];
extern const ISP_NVRAM_EE_T                                          EE_ISP_YUV_BASE[13];
extern const ISP_NVRAM_NR3D_T                                        NR3D_ISP_YUV_BASE[13];
extern const FEATURE_NVRAM_HFG_T                                     HFG_ISP_YUV_BASE[13];
extern const ISP_NVRAM_AKS_T                                         AKS_ISP_YUV_BASE[13];
extern const FEATURE_NVRAM_AD_NR_T                                   AD_NR_ISP_YUV_BASE[13];
extern const ISP_NVRAM_DM_T                                          DM_ISP_MFNR_BASE[13];
extern const ISP_NVRAM_YNR_T                                         YNR_ISP_MFNR_BASE[26];
extern const ISP_NVRAM_CNR_CNR_T                                     CNR_CNR_ISP_MFNR_BASE[26];
extern const ISP_NVRAM_EE_T                                          EE_ISP_MFNR_BASE[13];
extern const ISP_NVRAM_LDNR_T                                        LDNR_ISP_MFNR_BASE[13];
extern const ISP_NVRAM_CNR_CCR_T                                     CNR_CCR_ISP_MFNR_BASE[13];
extern const ISP_NVRAM_CNR_ABF_T                                     CNR_ABF_ISP_MFNR_BASE[13];
extern const NVRAM_CAMERA_FEATURE_MFNR_THRES_STRUCT                  MFNR_THRES_ISP_MFNR_BASE[1];
extern const NVRAM_CAMERA_FEATURE_MFLL_STRUCT                        MFNR_ISP_MFNR_BASE[13];
extern const FEATURE_NVRAM_BSS_T                                     BSS_ISP_MFNR_BASE[13];
extern const ISP_NVRAM_AKS_T                                         AKS_ISP_MFNR_BASE[13];
extern const FEATURE_NVRAM_SW_MSF_T                                  SW_MSF_ISP_MFNR_BASE[13];
extern const FEATURE_NVRAM_MSYUV_T                                   MSYUV_ISP_MFNR_BASE[13];
extern const ISP_NVRAM_OMC_T                                         OMC_ISP_MFNR_BASE[13];
extern const ISP_NVRAM_DM_T                                          DM_ISP_AIISP_BASE[13];
extern const ISP_NVRAM_YNR_T                                         YNR_ISP_AIISP_BASE[26];
extern const ISP_NVRAM_YNR_LCE_LINK_T                                YNR_LCE_LINK_ISP_AIISP_BASE[13];
extern const ISP_NVRAM_YNR_FD_T                                      YNR_FD_ISP_AIISP_BASE[13];
extern const ISP_NVRAM_CNR_CNR_T                                     CNR_CNR_ISP_AIISP_BASE[13];
extern const ISP_NVRAM_EE_T                                          EE_ISP_AIISP_BASE[13];
extern const ISP_NVRAM_BPC_BPC_T                                     BPC_BPC_ISP_AIISP_BASE[13];
extern const ISP_NVRAM_BPC_CT_T                                      BPC_CT_ISP_AIISP_BASE[13];
extern const ISP_NVRAM_BPC_PDC_T                                     BPC_PDC_ISP_AIISP_BASE[13];
extern const ISP_NVRAM_LDNR_T                                        LDNR_ISP_AIISP_BASE[13];
extern const ISP_NVRAM_AKS_T                                         AKS_ISP_AIISP_BASE[13];
extern const FEATURE_NVRAM_MSYUV_T                                   MSYUV_ISP_AIISP_BASE[13];
extern const FEATURE_NVRAM_AIISP_EV_T                                AIISP_EV_ISP_AIISP_BASE[1];
extern const FEATURE_NVRAM_AIISP_ISO_FEFM_T                          AIISP_ISO_FEFM_ISP_AIISP_BASE[13];
extern const FEATURE_NVRAM_AIISP_ISO_SWME_T                          AIISP_ISO_SWME_ISP_AIISP_BASE[13];
extern const FEATURE_NVRAM_AIISP_ISO_APU_Part1_T                     AIISP_ISO_APU_Part1_ISP_AIISP_BASE[13];
extern const FEATURE_NVRAM_AIISP_ISO_APU_Part2_T                     AIISP_ISO_APU_Part2_ISP_AIISP_BASE[13];
extern const FEATURE_NVRAM_AIISP_ISO_APU_Part3_T                     AIISP_ISO_APU_Part3_ISP_AIISP_BASE[13];
extern const FEATURE_NVRAM_AIISP_ISO_PostSW_T                        AIISP_ISO_PostSW_ISP_AIISP_BASE[13];
extern const FEATURE_NVRAM_AIISP_ISO_DRC_T                           AIISP_ISO_DRC_ISP_AIISP_BASE[13];
extern const ISP_NVRAM_YNR_T                                         YNR_ISP_MSNR_BASE[13];
extern const ISP_NVRAM_EE_T                                          EE_ISP_MSNR_BASE[13];
extern const FEATURE_NVRAM_MSYUV_T                                   MSYUV_ISP_MSNR_BASE[13];
extern const NVRAM_CAMERA_FEATURE_MSNR_THRES_STRUCT                  MSNR_THRES_ISP_MSNR_BASE[1];
extern const ISP_NVRAM_OBC_T                                         OBC_ISP_RAW_BASE[13];
extern const ISP_NVRAM_BPC_BPC_T                                     BPC_BPC_ISP_RAW_BASE[13];
extern const ISP_NVRAM_BPC_CT_T                                      BPC_CT_ISP_RAW_BASE[13];
extern const ISP_NVRAM_BPC_PDC_T                                     BPC_PDC_ISP_RAW_BASE[13];
extern const ISP_NVRAM_LDNR_T                                        LDNR_ISP_RAW_BASE[13];
extern const ISP_NVRAM_FRZ_T                                         FRZ_ISP_RAW_BASE[13];
extern const ISP_NVRAM_RRZ_T                                         RRZ_ISP_RAW_BASE[13];
extern const ISP_NVRAM_BPC_BPC_T                                     BPC_BPC_R3_ISP_RAW_BASE[13];
extern const ISP_NVRAM_BPC_CT_T                                      BPC_CT_R3_ISP_RAW_BASE[13];
extern const ISP_NVRAM_BPC_PDC_T                                     BPC_PDC_R3_ISP_RAW_BASE[13];
extern const ISP_NVRAM_OBC_T                                         OBC_R2_ISP_RAW_BASE[13];
extern const ISP_NVRAM_BPC_BPC_T                                     BPC_BPC_R2_ISP_RAW_BASE[13];
extern const ISP_NVRAM_OBC_T                                         OBC_R3_ISP_RAW_BASE[13];
extern const ISP_NVRAM_BPC_CT_T                                      BPC_CT_R2_ISP_RAW_BASE[13];
extern const ISP_NVRAM_BPC_PDC_T                                     BPC_PDC_R2_ISP_RAW_BASE[13];
extern const ISP_NVRAM_CNR_CCR_T                                     CNR_CCR_ISP_Other_BASE[13];
extern const ISP_NVRAM_CNR_ABF_T                                     CNR_ABF_ISP_Other_BASE[13];
extern const ISP_NVRAM_FUS_T                                         FUS_ISP_Other_BASE[13];
extern const ISP_NVRAM_ZFUS_T                                        ZFUS_ISP_Other_BASE[13];
extern const FEATURE_NVRAM_CA_LTM_T                                  CA_LTM_CA_LTM_BASE[1];
extern const ISP_NVRAM_MULTI_CCM_STRUCT                              CCM_CCM_BASE[6];
extern const ISP_NVRAM_MULTI_CCM_STRUCT                              CCM_R3_CCM_BASE[6];
extern const ISP_NVRAM_COLOR_PARAM_T                                 COLOR_PARAM_COLOR_BASE[1];
extern const ISP_NVRAM_SCOLOR_PARAM_T                                COLOR_COLOR_BASE[60];
extern const ISP_NVRAM_CLEARZOOM_T                                   ClearZoom_ClearZoom_BASE[1];
extern const ISP_NVRAM_YNR_LUT_T                                     YNR_TBL_ISP_YNR_TBL_BASE[13];
extern const FEATURE_NVRAM_AIISP_LV_Pre_T                            AIISP_LV_Pre_ISP_AIISP_LV_BASE[6];
extern const AIAWB_MA_NVRAM_T                                        AIAWB_MA_AIAWB_MA_BASE[1];
extern const AIAWB_SA_NVRAM_T                                        AIAWB_SA_AIAWB_SA_BASE[1];
extern const P1GGM_NVRAM_T                                           P1GGM_P1GGM_BASE[1];

#endif