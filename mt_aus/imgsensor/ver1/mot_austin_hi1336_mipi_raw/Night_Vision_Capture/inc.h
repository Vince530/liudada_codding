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
#ifndef _NIGHT_VISION_CAPTURE_H
#define _NIGHT_VISION_CAPTURE_H

#include "camera_custom_nvram.h"

#include "camera_custom_isp_nvram.h"

#define M_CONC(A, B) M_CONC_(A, B)
#define M_CONC_(A, B) A##_##B

#define AE_AE_BASE                                                   M_CONC(TARGET_SENSOR, AE_0005)
#define LCE_TONE_BASE                                                M_CONC(TARGET_SENSOR, LCE_0005)
#define GMA_TONE_BASE                                                M_CONC(TARGET_SENSOR, GMA_0005)
#define DCE_TONE_BASE                                                M_CONC(TARGET_SENSOR, DCE_0005)
#define LTM_TONE_BASE                                                M_CONC(TARGET_SENSOR, LTM_0005)
#define HLR_TONE_BASE                                                M_CONC(TARGET_SENSOR, HLR_0005)
#define GMA_R3_TONE_BASE                                             M_CONC(TARGET_SENSOR, GMA_R3_0005)
#define DM_ISP_YUV_BASE                                              M_CONC(TARGET_SENSOR, DM_0455)
#define YNR_ISP_YUV_BASE                                             M_CONC(TARGET_SENSOR, YNR_0780)
#define YNR_LCE_LINK_ISP_YUV_BASE                                    M_CONC(TARGET_SENSOR, YNR_LCE_LINK_0364)
#define YNR_FD_ISP_YUV_BASE                                          M_CONC(TARGET_SENSOR, YNR_FD_0364)
#define CNR_CNR_ISP_YUV_BASE                                         M_CONC(TARGET_SENSOR, CNR_CNR_0637)
#define EE_ISP_YUV_BASE                                              M_CONC(TARGET_SENSOR, EE_0689)
#define NR3D_ISP_YUV_BASE                                            M_CONC(TARGET_SENSOR, NR3D_0936)
#define HFG_ISP_YUV_BASE                                             M_CONC(TARGET_SENSOR, HFG_0351)
#define AKS_ISP_YUV_BASE                                             M_CONC(TARGET_SENSOR, AKS_0442)
#define AD_NR_ISP_YUV_BASE                                           M_CONC(TARGET_SENSOR, AD_NR_0351)
#define YNR_ISP_MSNR_BASE                                            M_CONC(TARGET_SENSOR, YNR_0793)
#define EE_ISP_MSNR_BASE                                             M_CONC(TARGET_SENSOR, EE_0702)
#define MSYUV_ISP_MSNR_BASE                                          M_CONC(TARGET_SENSOR, MSYUV_0338)
#define MSNR_THRES_ISP_MSNR_BASE                                     M_CONC(TARGET_SENSOR, MSNR_THRES_0010)
#define CA_LTM_CA_LTM_BASE                                           M_CONC(TARGET_SENSOR, CA_LTM_0015)

extern const AE_NVRAM_T                                              AE_AE_BASE[1];
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
extern const ISP_NVRAM_YNR_T                                         YNR_ISP_MSNR_BASE[13];
extern const ISP_NVRAM_EE_T                                          EE_ISP_MSNR_BASE[13];
extern const FEATURE_NVRAM_MSYUV_T                                   MSYUV_ISP_MSNR_BASE[13];
extern const NVRAM_CAMERA_FEATURE_MSNR_THRES_STRUCT                  MSNR_THRES_ISP_MSNR_BASE[1];
extern const FEATURE_NVRAM_CA_LTM_T                                  CA_LTM_CA_LTM_BASE[1];

#endif