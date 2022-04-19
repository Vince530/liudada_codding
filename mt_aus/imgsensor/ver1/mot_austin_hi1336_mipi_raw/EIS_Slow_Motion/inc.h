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
#ifndef _EIS_SLOW_MOTION_H
#define _EIS_SLOW_MOTION_H

#include "camera_custom_nvram.h"

#include "camera_custom_isp_nvram.h"

#define M_CONC(A, B) M_CONC_(A, B)
#define M_CONC_(A, B) A##_##B

#define DM_ISP_YUV_BASE                                              M_CONC(TARGET_SENSOR, DM_0494)
#define YNR_ISP_YUV_BASE                                             M_CONC(TARGET_SENSOR, YNR_0858)
#define YNR_LCE_LINK_ISP_YUV_BASE                                    M_CONC(TARGET_SENSOR, YNR_LCE_LINK_0403)
#define YNR_FD_ISP_YUV_BASE                                          M_CONC(TARGET_SENSOR, YNR_FD_0403)
#define CNR_CNR_ISP_YUV_BASE                                         M_CONC(TARGET_SENSOR, CNR_CNR_0702)
#define EE_ISP_YUV_BASE                                              M_CONC(TARGET_SENSOR, EE_0767)
#define NR3D_ISP_YUV_BASE                                            M_CONC(TARGET_SENSOR, NR3D_1105)
#define HFG_ISP_YUV_BASE                                             M_CONC(TARGET_SENSOR, HFG_0390)
#define AKS_ISP_YUV_BASE                                             M_CONC(TARGET_SENSOR, AKS_0481)
#define AD_NR_ISP_YUV_BASE                                           M_CONC(TARGET_SENSOR, AD_NR_0390)
#define YNR_ISP_DSDN_BASE                                            M_CONC(TARGET_SENSOR, YNR_0871)
#define CNR_CNR_ISP_DSDN_BASE                                        M_CONC(TARGET_SENSOR, CNR_CNR_0715)
#define EE_ISP_DSDN_BASE                                             M_CONC(TARGET_SENSOR, EE_0780)
#define NR3D_ISP_DSDN_BASE                                           M_CONC(TARGET_SENSOR, NR3D_1118)
#define DSDN_ISP_DSDN_BASE                                           M_CONC(TARGET_SENSOR, DSDN_0143)
#define MSYUV_ISP_DSDN_BASE                                          M_CONC(TARGET_SENSOR, MSYUV_0377)
#define OBC_ISP_RAW_BASE                                             M_CONC(TARGET_SENSOR, OBC_0286)
#define BPC_BPC_ISP_RAW_BASE                                         M_CONC(TARGET_SENSOR, BPC_BPC_0299)
#define BPC_CT_ISP_RAW_BASE                                          M_CONC(TARGET_SENSOR, BPC_CT_0299)
#define BPC_PDC_ISP_RAW_BASE                                         M_CONC(TARGET_SENSOR, BPC_PDC_0299)
#define LDNR_ISP_RAW_BASE                                            M_CONC(TARGET_SENSOR, LDNR_0377)
#define FRZ_ISP_RAW_BASE                                             M_CONC(TARGET_SENSOR, FRZ_0286)
#define RRZ_ISP_RAW_BASE                                             M_CONC(TARGET_SENSOR, RRZ_0286)
#define BPC_BPC_R3_ISP_RAW_BASE                                      M_CONC(TARGET_SENSOR, BPC_BPC_R3_0286)
#define BPC_CT_R3_ISP_RAW_BASE                                       M_CONC(TARGET_SENSOR, BPC_CT_R3_0286)
#define BPC_PDC_R3_ISP_RAW_BASE                                      M_CONC(TARGET_SENSOR, BPC_PDC_R3_0286)
#define OBC_R2_ISP_RAW_BASE                                          M_CONC(TARGET_SENSOR, OBC_R2_0286)
#define BPC_BPC_R2_ISP_RAW_BASE                                      M_CONC(TARGET_SENSOR, BPC_BPC_R2_0286)
#define OBC_R3_ISP_RAW_BASE                                          M_CONC(TARGET_SENSOR, OBC_R3_0286)
#define BPC_CT_R2_ISP_RAW_BASE                                       M_CONC(TARGET_SENSOR, BPC_CT_R2_0286)
#define BPC_PDC_R2_ISP_RAW_BASE                                      M_CONC(TARGET_SENSOR, BPC_PDC_R2_0286)

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
extern const ISP_NVRAM_YNR_T                                         YNR_ISP_DSDN_BASE[13];
extern const ISP_NVRAM_CNR_CNR_T                                     CNR_CNR_ISP_DSDN_BASE[13];
extern const ISP_NVRAM_EE_T                                          EE_ISP_DSDN_BASE[13];
extern const ISP_NVRAM_NR3D_T                                        NR3D_ISP_DSDN_BASE[65];
extern const FEATURE_NVRAM_DSDN_T                                    DSDN_ISP_DSDN_BASE[13];
extern const FEATURE_NVRAM_MSYUV_T                                   MSYUV_ISP_DSDN_BASE[13];
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

#endif