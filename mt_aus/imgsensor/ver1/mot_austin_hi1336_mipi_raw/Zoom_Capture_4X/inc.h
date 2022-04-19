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
#ifndef _ZOOM_CAPTURE_4X_H
#define _ZOOM_CAPTURE_4X_H

#include "camera_custom_nvram.h"

#include "camera_custom_isp_nvram.h"

#define M_CONC(A, B) M_CONC_(A, B)
#define M_CONC_(A, B) A##_##B

#define DM_ISP_YUV_BASE                                              M_CONC(TARGET_SENSOR, DM_0351)
#define YNR_ISP_YUV_BASE                                             M_CONC(TARGET_SENSOR, YNR_0611)
#define YNR_LCE_LINK_ISP_YUV_BASE                                    M_CONC(TARGET_SENSOR, YNR_LCE_LINK_0286)
#define YNR_FD_ISP_YUV_BASE                                          M_CONC(TARGET_SENSOR, YNR_FD_0286)
#define CNR_CNR_ISP_YUV_BASE                                         M_CONC(TARGET_SENSOR, CNR_CNR_0507)
#define EE_ISP_YUV_BASE                                              M_CONC(TARGET_SENSOR, EE_0546)
#define NR3D_ISP_YUV_BASE                                            M_CONC(TARGET_SENSOR, NR3D_0858)
#define HFG_ISP_YUV_BASE                                             M_CONC(TARGET_SENSOR, HFG_0273)
#define AKS_ISP_YUV_BASE                                             M_CONC(TARGET_SENSOR, AKS_0338)
#define AD_NR_ISP_YUV_BASE                                           M_CONC(TARGET_SENSOR, AD_NR_0273)
#define DM_ISP_MFNR_BASE                                             M_CONC(TARGET_SENSOR, DM_0364)
#define YNR_ISP_MFNR_BASE                                            M_CONC(TARGET_SENSOR, YNR_0637)
#define CNR_CNR_ISP_MFNR_BASE                                        M_CONC(TARGET_SENSOR, CNR_CNR_0520)
#define EE_ISP_MFNR_BASE                                             M_CONC(TARGET_SENSOR, EE_0572)
#define LDNR_ISP_MFNR_BASE                                           M_CONC(TARGET_SENSOR, LDNR_0312)
#define CNR_CCR_ISP_MFNR_BASE                                        M_CONC(TARGET_SENSOR, CNR_CCR_0078)
#define CNR_ABF_ISP_MFNR_BASE                                        M_CONC(TARGET_SENSOR, CNR_ABF_0078)
#define MFNR_THRES_ISP_MFNR_BASE                                     M_CONC(TARGET_SENSOR, MFNR_THRES_0004)
#define MFNR_ISP_MFNR_BASE                                           M_CONC(TARGET_SENSOR, MFNR_0052)
#define BSS_ISP_MFNR_BASE                                            M_CONC(TARGET_SENSOR, BSS_0052)
#define AKS_ISP_MFNR_BASE                                            M_CONC(TARGET_SENSOR, AKS_0351)
#define SW_MSF_ISP_MFNR_BASE                                         M_CONC(TARGET_SENSOR, SW_MSF_0052)
#define MSYUV_ISP_MFNR_BASE                                          M_CONC(TARGET_SENSOR, MSYUV_0286)
#define OMC_ISP_MFNR_BASE                                            M_CONC(TARGET_SENSOR, OMC_0052)
#define YNR_ISP_MSNR_BASE                                            M_CONC(TARGET_SENSOR, YNR_0624)
#define EE_ISP_MSNR_BASE                                             M_CONC(TARGET_SENSOR, EE_0559)
#define MSYUV_ISP_MSNR_BASE                                          M_CONC(TARGET_SENSOR, MSYUV_0273)
#define MSNR_THRES_ISP_MSNR_BASE                                     M_CONC(TARGET_SENSOR, MSNR_THRES_0007)

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

#endif