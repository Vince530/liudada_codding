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
#ifndef _FLASH_CAPTURE_H
#define _FLASH_CAPTURE_H

#include "camera_custom_nvram.h"

#include "camera_custom_isp_nvram.h"

#define M_CONC(A, B) M_CONC_(A, B)
#define M_CONC_(A, B) A##_##B

#define LCE_TONE_BASE                                                M_CONC(TARGET_SENSOR, LCE_0004)
#define GMA_TONE_BASE                                                M_CONC(TARGET_SENSOR, GMA_0004)
#define DCE_TONE_BASE                                                M_CONC(TARGET_SENSOR, DCE_0004)
#define LTM_TONE_BASE                                                M_CONC(TARGET_SENSOR, LTM_0004)
#define HLR_TONE_BASE                                                M_CONC(TARGET_SENSOR, HLR_0004)
#define GMA_R3_TONE_BASE                                             M_CONC(TARGET_SENSOR, GMA_R3_0004)
#define DM_ISP_YUV_BASE                                              M_CONC(TARGET_SENSOR, DM_0286)
#define YNR_ISP_YUV_BASE                                             M_CONC(TARGET_SENSOR, YNR_0507)
#define YNR_LCE_LINK_ISP_YUV_BASE                                    M_CONC(TARGET_SENSOR, YNR_LCE_LINK_0260)
#define YNR_FD_ISP_YUV_BASE                                          M_CONC(TARGET_SENSOR, YNR_FD_0260)
#define CNR_CNR_ISP_YUV_BASE                                         M_CONC(TARGET_SENSOR, CNR_CNR_0429)
#define EE_ISP_YUV_BASE                                              M_CONC(TARGET_SENSOR, EE_0468)
#define NR3D_ISP_YUV_BASE                                            M_CONC(TARGET_SENSOR, NR3D_0832)
#define HFG_ISP_YUV_BASE                                             M_CONC(TARGET_SENSOR, HFG_0247)
#define AKS_ISP_YUV_BASE                                             M_CONC(TARGET_SENSOR, AKS_0286)
#define AD_NR_ISP_YUV_BASE                                           M_CONC(TARGET_SENSOR, AD_NR_0247)
#define DM_ISP_MFNR_BASE                                             M_CONC(TARGET_SENSOR, DM_0299)
#define YNR_ISP_MFNR_BASE                                            M_CONC(TARGET_SENSOR, YNR_0533)
#define CNR_CNR_ISP_MFNR_BASE                                        M_CONC(TARGET_SENSOR, CNR_CNR_0442)
#define EE_ISP_MFNR_BASE                                             M_CONC(TARGET_SENSOR, EE_0494)
#define LDNR_ISP_MFNR_BASE                                           M_CONC(TARGET_SENSOR, LDNR_0286)
#define CNR_CCR_ISP_MFNR_BASE                                        M_CONC(TARGET_SENSOR, CNR_CCR_0052)
#define CNR_ABF_ISP_MFNR_BASE                                        M_CONC(TARGET_SENSOR, CNR_ABF_0052)
#define MFNR_THRES_ISP_MFNR_BASE                                     M_CONC(TARGET_SENSOR, MFNR_THRES_0002)
#define MFNR_ISP_MFNR_BASE                                           M_CONC(TARGET_SENSOR, MFNR_0026)
#define BSS_ISP_MFNR_BASE                                            M_CONC(TARGET_SENSOR, BSS_0026)
#define AKS_ISP_MFNR_BASE                                            M_CONC(TARGET_SENSOR, AKS_0299)
#define SW_MSF_ISP_MFNR_BASE                                         M_CONC(TARGET_SENSOR, SW_MSF_0026)
#define MSYUV_ISP_MFNR_BASE                                          M_CONC(TARGET_SENSOR, MSYUV_0234)
#define OMC_ISP_MFNR_BASE                                            M_CONC(TARGET_SENSOR, OMC_0026)
#define YNR_ISP_MSNR_BASE                                            M_CONC(TARGET_SENSOR, YNR_0520)
#define EE_ISP_MSNR_BASE                                             M_CONC(TARGET_SENSOR, EE_0481)
#define MSYUV_ISP_MSNR_BASE                                          M_CONC(TARGET_SENSOR, MSYUV_0221)
#define MSNR_THRES_ISP_MSNR_BASE                                     M_CONC(TARGET_SENSOR, MSNR_THRES_0005)
#define OBC_ISP_RAW_BASE                                             M_CONC(TARGET_SENSOR, OBC_0234)
#define BPC_BPC_ISP_RAW_BASE                                         M_CONC(TARGET_SENSOR, BPC_BPC_0247)
#define BPC_CT_ISP_RAW_BASE                                          M_CONC(TARGET_SENSOR, BPC_CT_0247)
#define BPC_PDC_ISP_RAW_BASE                                         M_CONC(TARGET_SENSOR, BPC_PDC_0247)
#define LDNR_ISP_RAW_BASE                                            M_CONC(TARGET_SENSOR, LDNR_0273)
#define FRZ_ISP_RAW_BASE                                             M_CONC(TARGET_SENSOR, FRZ_0234)
#define RRZ_ISP_RAW_BASE                                             M_CONC(TARGET_SENSOR, RRZ_0234)
#define BPC_BPC_R3_ISP_RAW_BASE                                      M_CONC(TARGET_SENSOR, BPC_BPC_R3_0234)
#define BPC_CT_R3_ISP_RAW_BASE                                       M_CONC(TARGET_SENSOR, BPC_CT_R3_0234)
#define BPC_PDC_R3_ISP_RAW_BASE                                      M_CONC(TARGET_SENSOR, BPC_PDC_R3_0234)
#define OBC_R2_ISP_RAW_BASE                                          M_CONC(TARGET_SENSOR, OBC_R2_0234)
#define BPC_BPC_R2_ISP_RAW_BASE                                      M_CONC(TARGET_SENSOR, BPC_BPC_R2_0234)
#define OBC_R3_ISP_RAW_BASE                                          M_CONC(TARGET_SENSOR, OBC_R3_0234)
#define BPC_CT_R2_ISP_RAW_BASE                                       M_CONC(TARGET_SENSOR, BPC_CT_R2_0234)
#define BPC_PDC_R2_ISP_RAW_BASE                                      M_CONC(TARGET_SENSOR, BPC_PDC_R2_0234)
#define CA_LTM_CA_LTM_BASE                                           M_CONC(TARGET_SENSOR, CA_LTM_0014)
#define CCM_CCM_BASE                                                 M_CONC(TARGET_SENSOR, CCM_0012)
#define CCM_R3_CCM_BASE                                              M_CONC(TARGET_SENSOR, CCM_R3_0012)
#define COLOR_PARAM_COLOR_BASE                                       M_CONC(TARGET_SENSOR, COLOR_PARAM_0002)
#define COLOR_COLOR_BASE                                             M_CONC(TARGET_SENSOR, COLOR_0120)

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
extern const FEATURE_NVRAM_CA_LTM_T                                  CA_LTM_CA_LTM_BASE[1];
extern const ISP_NVRAM_MULTI_CCM_STRUCT                              CCM_CCM_BASE[6];
extern const ISP_NVRAM_MULTI_CCM_STRUCT                              CCM_R3_CCM_BASE[6];
extern const ISP_NVRAM_COLOR_PARAM_T                                 COLOR_PARAM_COLOR_BASE[1];
extern const ISP_NVRAM_SCOLOR_PARAM_T                                COLOR_COLOR_BASE[60];

#endif