/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
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
TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/

#define LOG_TAG "isp_tuning_custom"

#ifndef ENABLE_MY_LOG
    #define ENABLE_MY_LOG       (1)
#endif

#include <aaa_types.h>
#include <aaa_log.h>
#include <camera_custom_nvram.h>
#include <isp_tuning_cam_info.h>
#include <isp_tuning_custom.h>
#include <isp_tuning_custom_swnr.h>
#include <isp_tuning_custom_instance.h>
#include <isp_mgr.h>
#include <stdlib.h>                     // For atoi()
#include <stdio.h>
#include <cutils/properties.h>  // For property_get().
#include "camera_custom_3dnr.h"
//#include <MTKGma.h>
//#include <MTKLce.h>
#include "n3d_sync2a_tuning_param.h"
#include <math.h>
#include <mutex>
std::mutex sensorID_mutex;

#define CEIL(a)   ( (a-(int)a) == 0 ? (int)a : (int)(a+1))

#define FLOOR(a)  ( (int)a)

#ifndef LOG2
#define LOG2(x)       ((MDOUBLE)log(x)/log(2))
#endif


using namespace NSIspTuning;


#define TUNING_FOR_AIS  0
#define AIS_INTERPOLATION   0

static float AIS_NORMAL_CFA_RATIO[4] = {0.10f, 1.00f, 0.50f, 0.50f}; //0=ais, 1=normal, for stage1-4 respectively
static float AIS_NORMAL_YNR_RATIO[4] = {0.10f, 1.00f, 0.50f, 0.50f}; //0=ais, 1=normal, for stage1-4 respectively
static float AIS_NORMAL_CNR_RATIO[4] = {0.20f, 1.00f, 0.20f, 0.20f}; //0=ais, 1=normal, for stage1-4 respectively
static float AIS_NORMAL_EE_RATIO[4]  = {0.10f, 1.00f, 0.50f, 0.50f}; //0=ais, 1=normal, for stage1-4 respectively

#define IS_AIS          (rCamInfo.rAEInfo.u4OrgRealISOValue != rCamInfo.rAEInfo.u4RealISOValue)

#define FINE_TUNE_SUPPORT_NUM 2

static ISP_FEATURE_TOP_CTL isp_profile_on_off_table = {
    //00, E_TOP_UNKNOWN
    (F_OBC_EN(1)    |F_BPC_EN(1)    |F_CT_EN(1)    |F_PDC_EN(1)   |F_DGN_EN(1)    |F_WB_EN(1)
    |F_HLR_EN(1)    |F_LTM_EN(1)    |F_SLK_EN(1)   |F_DM_EN(1)    |F_LDNR_EN(1)   |F_FLC_EN(1)
    |F_CCM_EN(1)    |F_GGM_EN(1)    |F_YNR_EN(1)   |F_LCE_EN(1)   |F_DCE_EN(1)    |F_LSC_EN(1)
    |F_EE_EN(1)     |F_CNR_EN(1)    |F_CCR_EN(1)   |F_ABF_EN(1)   |F_BOK_EN(1)    |F_COLOR_EN(1)
    |F_MIX_EN(0)    |F_MFB_EN(1)    |F_YNR_LINK_EN(1) |F_AKS_EN(1)),

    //01, Preview EIS_Preview
    (F_OBC_EN(1)    |F_BPC_EN(1)    |F_CT_EN(1)    |F_PDC_EN(1)   |F_DGN_EN(1)    |F_WB_EN(1)
    |F_HLR_EN(1)    |F_LTM_EN(1)    |F_SLK_EN(1)   |F_DM_EN(1)    |F_LDNR_EN(1)   |F_FLC_EN(1)
    |F_CCM_EN(1)    |F_GGM_EN(1)    |F_YNR_EN(1)   |F_LCE_EN(1)   |F_DCE_EN(1)    |F_LSC_EN(1)
    |F_EE_EN(1)     |F_CNR_EN(1)    |F_CCR_EN(1)   |F_ABF_EN(1)   |F_BOK_EN(0)    |F_COLOR_EN(1)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(1) | F_AKS_EN(1)),

    //02, Video EIS_Video
    (F_OBC_EN(1)    |F_BPC_EN(1)    |F_CT_EN(1)    |F_PDC_EN(1)   |F_DGN_EN(1)    |F_WB_EN(1)
    |F_HLR_EN(1)    |F_LTM_EN(1)    |F_SLK_EN(1)   |F_DM_EN(1)    |F_LDNR_EN(1)   |F_FLC_EN(1)
    |F_CCM_EN(1)    |F_GGM_EN(1)    |F_YNR_EN(1)   |F_LCE_EN(1)   |F_DCE_EN(1)    |F_LSC_EN(1)
    |F_EE_EN(1)     |F_CNR_EN(1)    |F_CCR_EN(1)   |F_ABF_EN(1)   |F_BOK_EN(0)    |F_COLOR_EN(1)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(1) | F_AKS_EN(1)),

    //03, ms2HDR_Preview ms2HDR_Video (SE)
    (F_OBC_EN(0)    |F_BPC_EN(1)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(0)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(0)    |F_GGM_EN(0)    |F_YNR_EN(0)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(0)
    |F_EE_EN(0)     |F_CNR_EN(0)    |F_CCR_EN(0)   |F_ABF_EN(0)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) | F_AKS_EN(0)),

    //04, ms2HDR_Preview ms2HDR_Video (NE)
    (F_OBC_EN(1)    |F_BPC_EN(1)    |F_CT_EN(1)    |F_PDC_EN(1)   |F_DGN_EN(1)    |F_WB_EN(1)
    |F_HLR_EN(1)    |F_LTM_EN(1)    |F_SLK_EN(1)   |F_DM_EN(1)    |F_LDNR_EN(1)   |F_FLC_EN(1)
    |F_CCM_EN(1)    |F_GGM_EN(1)    |F_YNR_EN(1)   |F_LCE_EN(1)   |F_DCE_EN(1)    |F_LSC_EN(1)
    |F_EE_EN(1)     |F_CNR_EN(1)    |F_CCR_EN(1)   |F_ABF_EN(1)   |F_BOK_EN(0)    |F_COLOR_EN(1)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(1) | F_AKS_EN(1) | F_FUS_EN(1)),

    //05, E2EHDR_Preview
    (F_OBC_EN(1)    |F_BPC_EN(1)    |F_CT_EN(1)    |F_PDC_EN(1)   |F_DGN_EN(1)    |F_WB_EN(1)
    |F_HLR_EN(1)    |F_LTM_EN(1)    |F_SLK_EN(1)   |F_DM_EN(1)    |F_LDNR_EN(1)   |F_FLC_EN(1)
    |F_CCM_EN(1)    |F_GGM_EN(1)    |F_YNR_EN(1)   |F_LCE_EN(1)   |F_DCE_EN(1)    |F_LSC_EN(1)
    |F_EE_EN(1)     |F_CNR_EN(1)    |F_CCR_EN(1)   |F_ABF_EN(1)   |F_BOK_EN(0)    |F_COLOR_EN(1)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(1) | F_AKS_EN(1)),

    //06, E2EHDR_Video
    (F_OBC_EN(1)    |F_BPC_EN(1)    |F_CT_EN(1)    |F_PDC_EN(1)   |F_DGN_EN(1)    |F_WB_EN(1)
    |F_HLR_EN(1)    |F_LTM_EN(1)    |F_SLK_EN(1)   |F_DM_EN(1)    |F_LDNR_EN(1)   |F_FLC_EN(1)
    |F_CCM_EN(1)    |F_GGM_EN(1)    |F_YNR_EN(1)   |F_LCE_EN(1)   |F_DCE_EN(1)    |F_LSC_EN(1)
    |F_EE_EN(1)     |F_CNR_EN(1)    |F_CCR_EN(1)   |F_ABF_EN(1)   |F_BOK_EN(0)    |F_COLOR_EN(1)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(1) | F_AKS_EN(1)),

    //07, Capture
    (F_OBC_EN(1)    |F_BPC_EN(1)    |F_CT_EN(1)    |F_PDC_EN(1)   |F_DGN_EN(1)    |F_WB_EN(1)
    |F_HLR_EN(1)    |F_LTM_EN(1)    |F_SLK_EN(1)   |F_DM_EN(1)    |F_LDNR_EN(1)   |F_FLC_EN(1)
    |F_CCM_EN(1)    |F_GGM_EN(1)    |F_YNR_EN(1)   |F_LCE_EN(1)   |F_DCE_EN(0)    |F_LSC_EN(1)
    |F_EE_EN(1)     |F_CNR_EN(1)    |F_CCR_EN(1)   |F_ABF_EN(1)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(1) | F_AKS_EN(1)),
    //08, Capture_DCE
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(0)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(0)    |F_GGM_EN(0)    |F_YNR_EN(0)   |F_LCE_EN(0)   |F_DCE_EN(1)    |F_LSC_EN(1)
    |F_EE_EN(0)     |F_CNR_EN(0)    |F_CCR_EN(0)   |F_ABF_EN(0)   |F_BOK_EN(0)    |F_COLOR_EN(1)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) | F_AKS_EN(0)),
    //09, VSDOF_PV_Main VSDOF_Video_Main
    (F_OBC_EN(1)    |F_BPC_EN(1)    |F_CT_EN(1)    |F_PDC_EN(1)   |F_DGN_EN(1)    |F_WB_EN(1)
    |F_HLR_EN(1)    |F_LTM_EN(1)    |F_SLK_EN(1)   |F_DM_EN(1)    |F_LDNR_EN(1)   |F_FLC_EN(1)
    |F_CCM_EN(1)    |F_GGM_EN(1)    |F_YNR_EN(1)   |F_LCE_EN(1)   |F_DCE_EN(1)    |F_LSC_EN(1)
    |F_EE_EN(1)     |F_CNR_EN(1)    |F_CCR_EN(1)   |F_ABF_EN(1)   |F_BOK_EN(0)    |F_COLOR_EN(1)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) | F_AKS_EN(1)),

    //10, VSDOF_PV_Aux VSDOF_Video_Aux
    (F_OBC_EN(1)    |F_BPC_EN(1)    |F_CT_EN(1)    |F_PDC_EN(1)   |F_DGN_EN(1)    |F_WB_EN(1)
    |F_HLR_EN(1)    |F_LTM_EN(1)    |F_SLK_EN(1)   |F_DM_EN(1)    |F_LDNR_EN(1)   |F_FLC_EN(1)
    |F_CCM_EN(1)    |F_GGM_EN(1)    |F_YNR_EN(1)   |F_LCE_EN(1)   |F_DCE_EN(1)    |F_LSC_EN(1)
    |F_EE_EN(1)     |F_CNR_EN(1)    |F_CCR_EN(1)   |F_ABF_EN(1)   |F_BOK_EN(0)    |F_COLOR_EN(1)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) | F_AKS_EN(1)),
    //11,  VSDOF_BOK
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(0)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(0)    |F_GGM_EN(0)    |F_YNR_EN(0)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(0)
    |F_EE_EN(0)     |F_CNR_EN(0)    |F_CCR_EN(0)   |F_ABF_EN(0)   |F_BOK_EN(1)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) | F_AKS_EN(0) ),

    //12,  MFNR_BFBLD
    (F_OBC_EN(1)    |F_BPC_EN(1)    |F_CT_EN(1)    |F_PDC_EN(1)   |F_DGN_EN(1)    |F_WB_EN(1)
    |F_HLR_EN(1)    |F_LTM_EN(1)    |F_SLK_EN(1)   |F_DM_EN(1)    |F_LDNR_EN(1)   |F_FLC_EN(1)
    |F_CCM_EN(1)    |F_GGM_EN(1)    |F_YNR_EN(1)   |F_LCE_EN(1)   |F_DCE_EN(0)    |F_LSC_EN(1)
    |F_EE_EN(0)     |F_CNR_EN(1)    |F_CCR_EN(0)   |F_ABF_EN(0)   |F_BOK_EN(0)    |F_COLOR_EN(0)

    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(1) |F_AKS_EN(0)),
    //13,  MFNR_AFBLD
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(1)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(0)    |F_GGM_EN(0)    |F_YNR_EN(1)   |F_LCE_EN(0)   |F_DCE_EN(1)    |F_LSC_EN(1)
    |F_EE_EN(1)     |F_CNR_EN(1)    |F_CCR_EN(1)   |F_ABF_EN(1)   |F_BOK_EN(0)    |F_COLOR_EN(1)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) |F_AKS_EN(1)),

    //14,  MFNR_MSF_0
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(1)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(0)    |F_GGM_EN(0)    |F_YNR_EN(1)   |F_LCE_EN(0)   |F_DCE_EN(1)    |F_LSC_EN(1)
    |F_EE_EN(1)     |F_CNR_EN(1)    |F_CCR_EN(1)   |F_ABF_EN(1)   |F_BOK_EN(0)    |F_COLOR_EN(1)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) |F_AKS_EN(1)),

    //15,  MFNR_MSF_1~5
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(1)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(0)    |F_GGM_EN(0)    |F_YNR_EN(1)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(1)
    |F_EE_EN(1)     |F_CNR_EN(1)    |F_CCR_EN(0)   |F_ABF_EN(0)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) |F_AKS_EN(0)),

    //16,  DSDN_MSF_0
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(1)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(0)    |F_GGM_EN(1)    |F_YNR_EN(1)   |F_LCE_EN(1)   |F_DCE_EN(1)    |F_LSC_EN(1)
    |F_EE_EN(1)     |F_CNR_EN(1)    |F_CCR_EN(1)   |F_ABF_EN(1)   |F_BOK_EN(0)    |F_COLOR_EN(1)
    |F_MIX_EN(0)    |F_MFB_EN(1)    |F_YNR_LINK_EN(1) |F_AKS_EN(1)),

    //17, DSDN_MSF_1~4
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(1)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(0)    |F_GGM_EN(0)    |F_YNR_EN(1)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(1)
    |F_EE_EN(1)     |F_CNR_EN(0)    |F_CCR_EN(0)   |F_ABF_EN(0)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(1)    |F_YNR_LINK_EN(0) |F_AKS_EN(0)),

    //18, Capture_Before_Blend
    (F_OBC_EN(1)    |F_BPC_EN(1)    |F_CT_EN(1)    |F_PDC_EN(1)   |F_DGN_EN(1)    |F_WB_EN(1)
    |F_HLR_EN(1)    |F_LTM_EN(1)    |F_SLK_EN(1)   |F_DM_EN(1)    |F_LDNR_EN(1)   |F_FLC_EN(1)
    |F_CCM_EN(1)    |F_GGM_EN(1)    |F_YNR_EN(0)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(1)
    |F_EE_EN(0)     |F_CNR_EN(0)    |F_CCR_EN(0)   |F_ABF_EN(0)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) | F_AKS_EN(0)),

    //19, Capture_MSF_0 AIISP_Capture_MSF_0
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(1)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(0)    |F_GGM_EN(1)    |F_YNR_EN(1)   |F_LCE_EN(1)   |F_DCE_EN(0)    |F_LSC_EN(1)
    |F_EE_EN(1)     |F_CNR_EN(1)    |F_CCR_EN(1)   |F_ABF_EN(1)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(1) |F_AKS_EN(1)),

    //20,  Capture_MSF_1~6 AIISP_Capture_MSF_1~6
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(1)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(0)    |F_GGM_EN(0)    |F_YNR_EN(1)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(1)
    |F_EE_EN(1)     |F_CNR_EN(0)    |F_CCR_EN(0)   |F_ABF_EN(0)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) |F_AKS_EN(0)),

    //21,  AIISP_MainYUV
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(0)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(1)    |F_GGM_EN(1)    |F_YNR_EN(1)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(0)
    |F_EE_EN(0)     |F_CNR_EN(0)    |F_CCR_EN(0)   |F_ABF_EN(0)   |F_BOK_EN(0)    |F_COLOR_EN(1)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) | F_AKS_EN(0)),


    //22, AIISP_Capture_Before_Blend_12b_NNOut
    (F_OBC_EN(1)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(1)    |F_WB_EN(1)
    |F_HLR_EN(1)    |F_LTM_EN(1)    |F_SLK_EN(1)   |F_DM_EN(1)    |F_LDNR_EN(1)   |F_FLC_EN(1)
    |F_CCM_EN(1)    |F_GGM_EN(1)    |F_YNR_EN(0)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(1)
    |F_EE_EN(0)     |F_CNR_EN(0)    |F_CCR_EN(0)   |F_ABF_EN(0)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) | F_AKS_EN(0)),


    //23,  AIISP_Capture_Before_Blend_16b_DRCOut
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(1)    |F_SLK_EN(1)   |F_DM_EN(1)    |F_LDNR_EN(1)   |F_FLC_EN(1)
    |F_CCM_EN(1)    |F_GGM_EN(1)    |F_YNR_EN(0)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(0)
    |F_EE_EN(0)     |F_CNR_EN(0)    |F_CCR_EN(0)   |F_ABF_EN(0)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) | F_AKS_EN(0)),

    //24,  AIISP_DRC
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(1)    |F_WB_EN(1)
    |F_HLR_EN(1)    |F_LTM_EN(0)    |F_SLK_EN(0)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(0)    |F_GGM_EN(0)    |F_YNR_EN(0)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(1)
    |F_EE_EN(0)     |F_CNR_EN(0)    |F_CCR_EN(0)   |F_ABF_EN(0)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) | F_AKS_EN(0) ),

    //25  EIspProfile_Capture_MSF_YUV_0
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(1)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(0)    |F_GGM_EN(1)    |F_YNR_EN(1)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(0)
    |F_EE_EN(1)     |F_CNR_EN(1)    |F_CCR_EN(1)   |F_ABF_EN(1)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) |F_AKS_EN(1)),

    //26  VSDOF_FE_Main
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(0)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(1)    |F_GGM_EN(1)    |F_YNR_EN(0)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(0)
    |F_EE_EN(0)     |F_CNR_EN(0)    |F_CCR_EN(0)   |F_ABF_EN(0)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) | F_AKS_EN(0)),

    //27 VSDOF_FE_Aux
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(0)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(0)    |F_GGM_EN(1)    |F_YNR_EN(0)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(0)
    |F_EE_EN(0)     |F_CNR_EN(0)    |F_CCR_EN(0)   |F_ABF_EN(0)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) | F_AKS_EN(0)),

    //28  VSDOF_FM
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(0)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(0)    |F_GGM_EN(0)    |F_YNR_EN(0)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(0)
    |F_EE_EN(0)     |F_CNR_EN(0)    |F_CCR_EN(0)   |F_ABF_EN(0)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) | F_AKS_EN(0)),

    //29, AIISP_HDR_Capture_MSF_0
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(1)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(0)    |F_GGM_EN(1)    |F_YNR_EN(1)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(1)
    |F_EE_EN(1)     |F_CNR_EN(1)    |F_CCR_EN(1)   |F_ABF_EN(1)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(1) |F_AKS_EN(1)),

    //30, AIISP_MainBPC
    (F_OBC_EN(0)    |F_BPC_EN(1)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(0)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(0)    |F_GGM_EN(0)    |F_YNR_EN(0)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(0)
    |F_EE_EN(0)     |F_CNR_EN(0)    |F_CCR_EN(0)   |F_ABF_EN(0)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) |F_AKS_EN(0)),

    //31, DSDN_P2NR
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(1)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(0)    |F_GGM_EN(0)    |F_YNR_EN(1)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(0)
    |F_EE_EN(0)     |F_CNR_EN(1)    |F_CCR_EN(0)   |F_ABF_EN(0)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) |F_AKS_EN(0)),

    //32, AIISP_Capture_Before_Blend_16b_NNOut
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(1)    |F_WB_EN(1)
    |F_HLR_EN(1)    |F_LTM_EN(1)    |F_SLK_EN(1)   |F_DM_EN(1)    |F_LDNR_EN(1)   |F_FLC_EN(1)
    |F_CCM_EN(1)    |F_GGM_EN(1)    |F_YNR_EN(0)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(1)
    |F_EE_EN(0)     |F_CNR_EN(0)    |F_CCR_EN(0)   |F_ABF_EN(0)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) | F_AKS_EN(0)),
    //33,  Capture_MSF_1
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(1)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(0)    |F_GGM_EN(0)    |F_YNR_EN(1)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(1)
    |F_EE_EN(1)     |F_CNR_EN(0)    |F_CCR_EN(1)   |F_ABF_EN(0)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) |F_AKS_EN(0)),
    //34, DSDN_MSF1
    (F_OBC_EN(0)    |F_BPC_EN(0)    |F_CT_EN(0)    |F_PDC_EN(0)   |F_DGN_EN(0)    |F_WB_EN(0)
    |F_HLR_EN(0)    |F_LTM_EN(0)    |F_SLK_EN(1)   |F_DM_EN(0)    |F_LDNR_EN(0)   |F_FLC_EN(0)
    |F_CCM_EN(0)    |F_GGM_EN(0)    |F_YNR_EN(1)   |F_LCE_EN(0)   |F_DCE_EN(0)    |F_LSC_EN(1)
    |F_EE_EN(1)     |F_CNR_EN(0)    |F_CCR_EN(1)   |F_ABF_EN(0)   |F_BOK_EN(0)    |F_COLOR_EN(0)
    |F_MIX_EN(0)    |F_MFB_EN(0)    |F_YNR_LINK_EN(0) |F_AKS_EN(0)),
};

typedef std::array<eISP_FEATURE_TOP_CONTROL_GOLDEN, EIspProfile_NUM> TOP_ENABLE_INDEX_FROM_ISPPROFILE;

static TOP_ENABLE_INDEX_FROM_ISPPROFILE isp_profile_2_top_ctl_indx = []() {
    TOP_ENABLE_INDEX_FROM_ISPPROFILE tbl = {};
    tbl[EIspProfile_Preview]                          = E_TOP_Preview;
    tbl[EIspProfile_Video]                            = E_TOP_Video;
    tbl[EIspProfile_Capture]                          = E_TOP_Capture;
    tbl[EIspProfile_Capture_DCE]                      = E_TOP_Capture_DCE;
    tbl[EIspProfile_MFNR_Before_Blend]                = E_TOP_MFNR_BFBLD;
    tbl[EIspProfile_MFNR_After_Blend]                 = E_TOP_MFNR_AFBLD;
    tbl[EIspProfile_MFNR_MSF_0]                       = E_TOP_MFNR_MSF_0;
    tbl[EIspProfile_MFNR_MSF_1]                       = E_TOP_MFNR_MSF_1_5;
    tbl[EIspProfile_MFNR_MSF_2]                       = E_TOP_MFNR_MSF_1_5;
    tbl[EIspProfile_MFNR_MSF_3]                       = E_TOP_MFNR_MSF_1_5;
    tbl[EIspProfile_MFNR_MSF_4]                       = E_TOP_MFNR_MSF_1_5;
    tbl[EIspProfile_MFNR_MSF_5]                       = E_TOP_MFNR_MSF_1_5;
    tbl[EIspProfile_Capture_Before_Blend]             = E_TOP_Capture_Before_Blend;
    tbl[EIspProfile_Capture_MSF_0]                    = E_TOP_Capture_MSF_0;
    tbl[EIspProfile_Capture_MSF_1]                    = E_TOP_Capture_MSF_1;
    tbl[EIspProfile_Capture_MSF_2]                    = E_TOP_Capture_MSF_1_6;
    tbl[EIspProfile_Capture_MSF_3]                    = E_TOP_Capture_MSF_1_6;
    tbl[EIspProfile_Capture_MSF_4]                    = E_TOP_Capture_MSF_1_6;
    tbl[EIspProfile_Capture_MSF_5]                    = E_TOP_Capture_MSF_1_6;
    tbl[EIspProfile_Capture_MSF_6]                    = E_TOP_Capture_MSF_1_6;
    tbl[EIspProfile_Capture_MSF_YUV_0]                = E_TOP_Capture_MSF_YUV_0;
    tbl[EIspProfile_DSDN_MSF_0]                       = E_TOP_DSDN_MSF_0;
    tbl[EIspProfile_DSDN_MSF_1]                       = E_TOP_DSDN_MSF_1;
    tbl[EIspProfile_DSDN_MSF_2]                       = E_TOP_DSDN_MSF_1_4;
    tbl[EIspProfile_DSDN_MSF_3]                       = E_TOP_DSDN_MSF_1_4;
    tbl[EIspProfile_DSDN_MSF_4]                       = E_TOP_DSDN_MSF_1_4;
    tbl[EIspProfile_VSDOF_PV_Main]                    = E_TOP_VSDOF_PV_Main;
    tbl[EIspProfile_VSDOF_PV_Main_toW]                = E_TOP_VSDOF_PV_Main;
    tbl[EIspProfile_VSDOF_Video_Main]                 = E_TOP_VSDOF_PV_Main;
    tbl[EIspProfile_VSDOF_Video_Main_toW]             = E_TOP_VSDOF_PV_Main;
    tbl[EIspProfile_VSDOF_PV_Aux]                     = E_TOP_VSDOF_PV_Aux;
    tbl[EIspProfile_VSDOF_Video_Aux]                  = E_TOP_VSDOF_PV_Aux;
    tbl[EIspProfile_VSDOF_FE_Main]                    = E_TOP_VSDOF_FE_Main;
    tbl[EIspProfile_VSDOF_FE_Aux]                     = E_TOP_VSDOF_FE_Aux;
    tbl[EIspProfile_VSDOF_FM]                         = E_TOP_VSDOF_FM;
    tbl[EIspProfile_VSDOF_BOK]                        = E_TOP_VSDOF_BOK;
    tbl[EIspProfile_zHDR_Capture]                     = E_TOP_Capture;
    tbl[EIspProfile_zHDR_Capture_DCE]                 = E_TOP_Capture_DCE;
    tbl[EIspProfile_mHDR_Capture]                     = E_TOP_Capture;
    tbl[EIspProfile_mHDR_Capture_DCE]                 = E_TOP_Capture_DCE;
    tbl[EIspProfile_Auto_zHDR_Capture]                = E_TOP_Capture;
    tbl[EIspProfile_Auto_zHDR_Capture_DCE]            = E_TOP_Capture_DCE;
    tbl[EIspProfile_Auto_mHDR_Capture]                = E_TOP_Capture;
    tbl[EIspProfile_Auto_mHDR_Capture_DCE]            = E_TOP_Capture_DCE;
    tbl[EIspProfile_mHDR_Preview]                     = E_TOP_ms2HDR_Preview_NE;
    tbl[EIspProfile_ms2HDR_Preview]                   = E_TOP_E2EHDR_Preview;
    tbl[EIspProfile_stg2HDR_Preview]                  = E_TOP_E2EHDR_Preview;
    tbl[EIspProfile_stg3HDR_Preview]                  = E_TOP_E2EHDR_Preview;
    tbl[EIspProfile_fc2HDR_Preview]                   = E_TOP_E2EHDR_Preview;
    tbl[EIspProfile_fc3HDR_Preview]                   = E_TOP_E2EHDR_Preview;
    tbl[EIspProfile_fmtfc2HDR_Preview]                = E_TOP_E2EHDR_Preview;
    tbl[EIspProfile_fmtfc3HDR_Preview]                = E_TOP_E2EHDR_Preview;
    tbl[EIspProfile_mHDR_Video]                       = E_TOP_E2EHDR_Video;
    tbl[EIspProfile_ms2HDR_Video]                     = E_TOP_E2EHDR_Video;
    tbl[EIspProfile_stg2HDR_Video]                    = E_TOP_E2EHDR_Video;
    tbl[EIspProfile_stg3HDR_Video]                    = E_TOP_E2EHDR_Video;
    tbl[EIspProfile_fc2HDR_Video]                     = E_TOP_E2EHDR_Video;
    tbl[EIspProfile_fc3HDR_Video]                     = E_TOP_E2EHDR_Video;
    tbl[EIspProfile_fmtfc2HDR_Video]                  = E_TOP_E2EHDR_Video;
    tbl[EIspProfile_fmtfc3HDR_Video]                  = E_TOP_E2EHDR_Video;
    tbl[EIspProfile_E2EHDR_Preview]                   = E_TOP_E2EHDR_Preview;
    tbl[EIspProfile_E2EHDR_Video]                     = E_TOP_E2EHDR_Preview;
    tbl[EIspProfile_mHDR_E2EHDR_Preview]              = E_TOP_E2EHDR_Preview;
    tbl[EIspProfile_ms2HDR_E2EHDR_Preview]            = E_TOP_E2EHDR_Preview;
    tbl[EIspProfile_stg2HDR_E2EHDR_Preview]           = E_TOP_E2EHDR_Preview;
    tbl[EIspProfile_stg3HDR_E2EHDR_Preview]           = E_TOP_E2EHDR_Preview;
    tbl[EIspProfile_fc2HDR_E2EHDR_Preview]            = E_TOP_E2EHDR_Preview;
    tbl[EIspProfile_fc3HDR_E2EHDR_Preview]            = E_TOP_E2EHDR_Preview;
    tbl[EIspProfile_fmtfc2HDR_E2EHDR_Preview]         = E_TOP_E2EHDR_Preview;
    tbl[EIspProfile_fmtfc3HDR_E2EHDR_Preview]         = E_TOP_E2EHDR_Preview;
    tbl[EIspProfile_mHDR_E2EHDR_Video]                = E_TOP_E2EHDR_Video;
    tbl[EIspProfile_ms2HDR_E2EHDR_Video]              = E_TOP_E2EHDR_Video;
    tbl[EIspProfile_stg2HDR_E2EHDR_Video]             = E_TOP_E2EHDR_Video;
    tbl[EIspProfile_stg3HDR_E2EHDR_Video]             = E_TOP_E2EHDR_Video;
    tbl[EIspProfile_fc2HDR_E2EHDR_Video]              = E_TOP_E2EHDR_Video;
    tbl[EIspProfile_fc3HDR_E2EHDR_Video]              = E_TOP_E2EHDR_Video;
    tbl[EIspProfile_fmtfc2HDR_E2EHDR_Video]           = E_TOP_E2EHDR_Video;
    tbl[EIspProfile_fmtfc3HDR_E2EHDR_Video]           = E_TOP_E2EHDR_Video;
    tbl[EIspProfile_EIS_Preview]                      = E_TOP_Preview;
    tbl[EIspProfile_EIS_Video]                        = E_TOP_Video;
    tbl[EIspProfile_AIISP_MainYUV]                    = E_TOP_AIISP_MainYUV;
    tbl[EIspProfile_AIISP_MainBPC]                    = E_TOP_AIISP_MainBPC;
    tbl[EIspProfile_AIISP_Capture_MSF_0]              = E_TOP_Capture_MSF_0;
    tbl[EIspProfile_AIISP_Capture_MSF_1]              = E_TOP_Capture_MSF_1;
    tbl[EIspProfile_AIISP_Capture_MSF_2]              = E_TOP_Capture_MSF_1_6;
    tbl[EIspProfile_AIISP_Capture_MSF_3]              = E_TOP_Capture_MSF_1_6;
    tbl[EIspProfile_AIISP_Capture_MSF_4]              = E_TOP_Capture_MSF_1_6;
    tbl[EIspProfile_AIISP_Capture_MSF_5]              = E_TOP_Capture_MSF_1_6;
    tbl[EIspProfile_AIISP_Capture_MSF_6]              = E_TOP_Capture_MSF_1_6;
    tbl[EIspProfile_AINR_Preview_MSF_0]               = E_TOP_DSDN_MSF_0;
    tbl[EIspProfile_AINR_Preview_MSF_1]               = E_TOP_DSDN_MSF_1;
    tbl[EIspProfile_AINR_Preview_MSF_2]               = E_TOP_DSDN_MSF_1_4;
    tbl[EIspProfile_AINR_Preview_MSF_3]               = E_TOP_DSDN_MSF_1_4;
    tbl[EIspProfile_AINR_Preview_MSF_4]               = E_TOP_DSDN_MSF_1_4;
    tbl[EIspProfile_AINR_Video_MSF_0]                 = E_TOP_DSDN_MSF_0;
    tbl[EIspProfile_AINR_Video_MSF_1]                 = E_TOP_DSDN_MSF_1;
    tbl[EIspProfile_AINR_Video_MSF_2]                 = E_TOP_DSDN_MSF_1_4;
    tbl[EIspProfile_AINR_Video_MSF_3]                 = E_TOP_DSDN_MSF_1_4;
    tbl[EIspProfile_AINR_Video_MSF_4]                 = E_TOP_DSDN_MSF_1_4;
    tbl[EIspProfile_AIISP_NR_Capture_Before_Blend_16b_DRCOut] = E_TOP_AIISP_Capture_Before_Blend_16b_DRCOut;
    tbl[EIspProfile_AIISP_NR_Capture_Before_Blend_12b_NNOut] = E_TOP_AIISP_Capture_Before_Blend_12b_NNOut;
    tbl[EIspProfile_AIISP_NR_Capture_Before_Blend_16b_NNOut] = E_TOP_AIISP_Capture_Before_Blend_16b_NNOut;
    tbl[EIspProfile_AIISP_DRC]                        = E_TOP_AIISP_DRC;
    tbl[EIspProfile_P1_YUV_FD]                        = E_TOP_Preview;
    tbl[EIspProfile_SWHDR_RAW_DOMAIN]                 = E_TOP_Preview;
    tbl[EIspProfile_SWHDR_YUV_DOMAIN]                 = E_TOP_Preview;
    tbl[EIspProfile_YUV_Reprocess]                    = E_TOP_Preview;
    tbl[EIspProfile_AIISP_HDR_Capture_DCE]            = E_TOP_Capture_DCE;
    tbl[EIspProfile_AIISP_HDR_MainYUV]                = E_TOP_AIISP_MainYUV;
    tbl[EIspProfile_AIISP_HDR_MainBPC]                = E_TOP_AIISP_MainBPC;
    tbl[EIspProfile_AIISP_HDR_Capture_MSF_0]          = E_TOP_AIISP_HDR_Capture_MSF_0;
    tbl[EIspProfile_AIISP_HDR_Capture_MSF_1]          = E_TOP_Capture_MSF_1;
    tbl[EIspProfile_AIISP_HDR_Capture_MSF_2]          = E_TOP_Capture_MSF_1_6;
    tbl[EIspProfile_AIISP_HDR_Capture_MSF_3]          = E_TOP_Capture_MSF_1_6;
    tbl[EIspProfile_AIISP_HDR_Capture_MSF_4]          = E_TOP_Capture_MSF_1_6;
    tbl[EIspProfile_AIISP_HDR_Capture_MSF_5]          = E_TOP_Capture_MSF_1_6;
    tbl[EIspProfile_AIISP_HDR_Capture_MSF_6]          = E_TOP_Capture_MSF_1_6;
    tbl[EIspProfile_AIISP_HDR_Capture_Before_Blend_16b_DRCOut] = E_TOP_AIISP_Capture_Before_Blend_16b_DRCOut;
    tbl[EIspProfile_AIISP_HDR_Capture_Before_Blend_12b_NNOut] = E_TOP_AIISP_Capture_Before_Blend_12b_NNOut;
    tbl[EIspProfile_AIISP_HDR_Capture_Before_Blend_16b_NNOut] = E_TOP_AIISP_Capture_Before_Blend_16b_NNOut;
    tbl[EIspProfile_AIISP_HDR_DRC]                    = E_TOP_AIISP_DRC;
    tbl[EIspProfile_DSDN_P2NR]                        = E_TOP_DSDN_P2NR;
    tbl[EIspProfile_Thumbnail]                        = E_TOP_Preview;
    return tbl;
}();

static ISP_FEATURE_TOP_CTL ispTopCtl = []() {
    ISP_FEATURE_TOP_CTL ctl = {};
    for (int i = 0; i < EIspProfile_NUM; ++i) {
        const eISP_FEATURE_TOP_CONTROL_GOLDEN idx = isp_profile_2_top_ctl_indx[i];
        if (idx == E_TOP_UNKNOWN)
          MY_LOG("[ISP_FEATURE_TOP_CTL] warning!! profile(%d) top control is E_TOP_UNKNOWN", i);
        ctl[i] = isp_profile_on_off_table[idx];
    }
    return ctl;
}();


MVOID*
IspTuningCustom::
get_feature_control(MUINT32 eSensorDev) const
{
    return &ispTopCtl;
}

/*====================ISO Control====================*/

static ISP_MODULE_ISO_CONFIG_T isp_profile_iso_table[E_ISOStrategy_Num] = {

    //00 E_ISOStrategy_Normal
    {
    .ISO_FRZ_R1 = E_ISO_TYPE_00,
    .ISO_BPC_BPC_R1 = E_ISO_TYPE_00,
    .ISO_BPC_BPC_R2 = E_ISO_TYPE_00,
    .ISO_BPC_BPC_R3 = E_ISO_TYPE_00,
    .ISO_BPC_CT_R1  = E_ISO_TYPE_00,
    .ISO_BPC_CT_R2  = E_ISO_TYPE_00,
    .ISO_BPC_CT_R3  = E_ISO_TYPE_00,
    .ISO_BPC_PDC_R1 = E_ISO_TYPE_00,
    .ISO_BPC_PDC_R2 = E_ISO_TYPE_00,
    .ISO_BPC_PDC_R3 = E_ISO_TYPE_00,
    .ISO_OBC_R1 = E_ISO_TYPE_00,
    .ISO_OBC_R2 = E_ISO_TYPE_00,
    .ISO_OBC_R3 = E_ISO_TYPE_00,
    .ISO_FUS_R1 = E_ISO_TYPE_00,
    .ISO_DGN_R1 = E_ISO_TYPE_00,
    .ISO_LSC_R1 = E_ISO_TYPE_00,
    .ISO_WB_R1  = E_ISO_TYPE_00,
    .ISO_HLR_R1 = E_ISO_TYPE_00,
    .ISO_LTM_R1 = E_ISO_TYPE_00,
    .ISO_RRZ_R1 = E_ISO_TYPE_00,
    .ISO_DM_R1  = E_ISO_TYPE_00,
    .ISO_FLC_R1 = E_ISO_TYPE_00,
    .ISO_CCM_R1 = E_ISO_TYPE_00,
    .ISO_CCM_R2 = E_ISO_TYPE_00,
    .ISO_CCM_R3 = E_ISO_TYPE_00,
    .ISO_GGM_R1 = E_ISO_TYPE_00,
    .ISO_GGM_R2 = E_ISO_TYPE_00,
    .ISO_GGM_R3 = E_ISO_TYPE_00,
     //P2
    .ISO_BPC_BPC_D1 = E_ISO_TYPE_01,
    .ISO_BPC_CT_D1  = E_ISO_TYPE_01,
    .ISO_BPC_PDC_D1 = E_ISO_TYPE_01,
    .ISO_OBC_D1 = E_ISO_TYPE_01,
    .ISO_DGN_D1 = E_ISO_TYPE_01,
    .ISO_LSC_D1 = E_ISO_TYPE_01,
    .ISO_WB_D1  = E_ISO_TYPE_01,
    .ISO_HLR_D1 = E_ISO_TYPE_01,
    .ISO_LTM_D1 = E_ISO_TYPE_01,
    .ISO_DM_D1  = E_ISO_TYPE_01,
    .ISO_LDNR_D1 = E_ISO_TYPE_01,
    .ISO_FLC_D1 = E_ISO_TYPE_01,
    .ISO_CCM_D1 = E_ISO_TYPE_01,
    .ISO_CCM_D2 = E_ISO_TYPE_01,
    .ISO_GGM_D1 = E_ISO_TYPE_01,
    .ISO_GGM_D2 = E_ISO_TYPE_01,
    .ISO_NDG_D1 = E_ISO_TYPE_01,
    .ISO_YNR_D1 = E_ISO_TYPE_01,
    .ISO_IGGM_D1 = E_ISO_TYPE_01,
    .ISO_GGM_D3 = E_ISO_TYPE_01,
    .ISO_DCE_D1 = E_ISO_TYPE_01,
    .ISO_EE_D1  = E_ISO_TYPE_01,
    .ISO_AKS_D1 = E_ISO_TYPE_01,
    .ISO_NDG_D2 = E_ISO_TYPE_01,
    .ISO_CNR_D1 = E_ISO_TYPE_01,
    .ISO_CCR_D1 = E_ISO_TYPE_01,
    .ISO_BOK_D1 = E_ISO_TYPE_01,
    .ISO_ABF_D1 = E_ISO_TYPE_01,
    .ISO_COLOR_D1 = E_ISO_TYPE_01,
    .ISO_NR3D_D1 = E_ISO_TYPE_01,
    .ISO_MFB_D1 = E_ISO_TYPE_01
    },

    //01 E_ISOStrategy_mStream
    {
    .ISO_FRZ_R1 = E_ISO_TYPE_01,
    .ISO_BPC_BPC_R1 = E_ISO_TYPE_01,
    .ISO_BPC_BPC_R2 = E_ISO_TYPE_02,
    .ISO_BPC_BPC_R3 = E_ISO_TYPE_00,
    .ISO_BPC_CT_R1  = E_ISO_TYPE_01,
    .ISO_BPC_CT_R2  = E_ISO_TYPE_00,
    .ISO_BPC_CT_R3  = E_ISO_TYPE_00,
    .ISO_BPC_PDC_R1 = E_ISO_TYPE_01,
    .ISO_BPC_PDC_R2 = E_ISO_TYPE_00,
    .ISO_BPC_PDC_R3 = E_ISO_TYPE_00,
    .ISO_OBC_R1 = E_ISO_TYPE_01,
    .ISO_OBC_R2 = E_ISO_TYPE_00,
    .ISO_OBC_R3 = E_ISO_TYPE_00,
    .ISO_FUS_R1 = E_ISO_TYPE_00,
    .ISO_DGN_R1 = E_ISO_TYPE_00,
    .ISO_LSC_R1 = E_ISO_TYPE_00,
    .ISO_WB_R1  = E_ISO_TYPE_00,
    .ISO_HLR_R1 = E_ISO_TYPE_00,
    .ISO_LTM_R1 = E_ISO_TYPE_00,
    .ISO_RRZ_R1 = E_ISO_TYPE_00,
    .ISO_DM_R1  = E_ISO_TYPE_00,
    .ISO_FLC_R1 = E_ISO_TYPE_00,
    .ISO_CCM_R1 = E_ISO_TYPE_00,
    .ISO_CCM_R2 = E_ISO_TYPE_00,
    .ISO_CCM_R3 = E_ISO_TYPE_00,
    .ISO_GGM_R1 = E_ISO_TYPE_00,
    .ISO_GGM_R2 = E_ISO_TYPE_00,
    .ISO_GGM_R3 = E_ISO_TYPE_00,
     //P2
    .ISO_BPC_BPC_D1 = E_ISO_TYPE_00,
    .ISO_BPC_CT_D1  = E_ISO_TYPE_00,
    .ISO_BPC_PDC_D1 = E_ISO_TYPE_00,
    .ISO_OBC_D1 = E_ISO_TYPE_00,
    .ISO_DGN_D1 = E_ISO_TYPE_00,
    .ISO_LSC_D1 = E_ISO_TYPE_00,
    .ISO_WB_D1  = E_ISO_TYPE_00,
    .ISO_HLR_D1 = E_ISO_TYPE_00,
    .ISO_LTM_D1 = E_ISO_TYPE_00,
    .ISO_DM_D1  = E_ISO_TYPE_00,
    .ISO_LDNR_D1 = E_ISO_TYPE_00,
    .ISO_FLC_D1 = E_ISO_TYPE_00,
    .ISO_CCM_D1 = E_ISO_TYPE_00,
    .ISO_CCM_D2 = E_ISO_TYPE_00,
    .ISO_GGM_D1 = E_ISO_TYPE_00,
    .ISO_GGM_D2 = E_ISO_TYPE_00,
    .ISO_NDG_D1 = E_ISO_TYPE_00,
    .ISO_YNR_D1 = E_ISO_TYPE_00,
    .ISO_IGGM_D1 = E_ISO_TYPE_00,
    .ISO_GGM_D3 = E_ISO_TYPE_00,
    .ISO_DCE_D1 = E_ISO_TYPE_00,
    .ISO_EE_D1  = E_ISO_TYPE_00,
    .ISO_AKS_D1 = E_ISO_TYPE_00,
    .ISO_NDG_D2 = E_ISO_TYPE_00,
    .ISO_CNR_D1 = E_ISO_TYPE_00,
    .ISO_CCR_D1 = E_ISO_TYPE_00,
    .ISO_BOK_D1 = E_ISO_TYPE_00,
    .ISO_ABF_D1 = E_ISO_TYPE_00,
    .ISO_COLOR_D1 = E_ISO_TYPE_00,
    .ISO_NR3D_D1 = E_ISO_TYPE_00,
    .ISO_MFB_D1 = E_ISO_TYPE_00
    },

    //02 E_ISOStrategy_Stagger2
    {
    .ISO_FRZ_R1 = E_ISO_TYPE_00,
    .ISO_BPC_BPC_R1 = E_ISO_TYPE_00,
    .ISO_BPC_BPC_R2 = E_ISO_TYPE_01,
    .ISO_BPC_BPC_R3 = E_ISO_TYPE_00,
    .ISO_BPC_CT_R1  = E_ISO_TYPE_00,
    .ISO_BPC_CT_R2  = E_ISO_TYPE_01,
    .ISO_BPC_CT_R3  = E_ISO_TYPE_00,
    .ISO_BPC_PDC_R1 = E_ISO_TYPE_00,
    .ISO_BPC_PDC_R2 = E_ISO_TYPE_01,
    .ISO_BPC_PDC_R3 = E_ISO_TYPE_00,
    .ISO_OBC_R1 = E_ISO_TYPE_00,
    .ISO_OBC_R2 = E_ISO_TYPE_01,
    .ISO_OBC_R3 = E_ISO_TYPE_00,
    .ISO_FUS_R1 = E_ISO_TYPE_00,
    .ISO_DGN_R1 = E_ISO_TYPE_00,
    .ISO_LSC_R1 = E_ISO_TYPE_00,
    .ISO_WB_R1  = E_ISO_TYPE_00,
    .ISO_HLR_R1 = E_ISO_TYPE_00,
    .ISO_LTM_R1 = E_ISO_TYPE_00,
    .ISO_RRZ_R1 = E_ISO_TYPE_00,
    .ISO_DM_R1  = E_ISO_TYPE_00,
    .ISO_FLC_R1 = E_ISO_TYPE_00,
    .ISO_CCM_R1 = E_ISO_TYPE_00,
    .ISO_CCM_R2 = E_ISO_TYPE_00,
    .ISO_CCM_R3 = E_ISO_TYPE_00,
    .ISO_GGM_R1 = E_ISO_TYPE_00,
    .ISO_GGM_R2 = E_ISO_TYPE_00,
    .ISO_GGM_R3 = E_ISO_TYPE_00,
     //P2
    .ISO_BPC_BPC_D1 = E_ISO_TYPE_00,
    .ISO_BPC_CT_D1  = E_ISO_TYPE_00,
    .ISO_BPC_PDC_D1 = E_ISO_TYPE_00,
    .ISO_OBC_D1 = E_ISO_TYPE_00,
    .ISO_DGN_D1 = E_ISO_TYPE_00,
    .ISO_LSC_D1 = E_ISO_TYPE_00,
    .ISO_WB_D1  = E_ISO_TYPE_00,
    .ISO_HLR_D1 = E_ISO_TYPE_00,
    .ISO_LTM_D1 = E_ISO_TYPE_00,
    .ISO_DM_D1  = E_ISO_TYPE_00,
    .ISO_LDNR_D1 = E_ISO_TYPE_00,
    .ISO_FLC_D1 = E_ISO_TYPE_00,
    .ISO_CCM_D1 = E_ISO_TYPE_00,
    .ISO_CCM_D2 = E_ISO_TYPE_00,
    .ISO_GGM_D1 = E_ISO_TYPE_00,
    .ISO_GGM_D2 = E_ISO_TYPE_00,
    .ISO_NDG_D1 = E_ISO_TYPE_00,
    .ISO_YNR_D1 = E_ISO_TYPE_00,
    .ISO_IGGM_D1 = E_ISO_TYPE_00,
    .ISO_GGM_D3 = E_ISO_TYPE_00,
    .ISO_DCE_D1 = E_ISO_TYPE_00,
    .ISO_EE_D1  = E_ISO_TYPE_00,
    .ISO_AKS_D1 = E_ISO_TYPE_00,
    .ISO_NDG_D2 = E_ISO_TYPE_00,
    .ISO_CNR_D1 = E_ISO_TYPE_00,
    .ISO_CCR_D1 = E_ISO_TYPE_00,
    .ISO_BOK_D1 = E_ISO_TYPE_00,
    .ISO_ABF_D1 = E_ISO_TYPE_00,
    .ISO_COLOR_D1 = E_ISO_TYPE_00,
    .ISO_NR3D_D1 = E_ISO_TYPE_00,
    .ISO_MFB_D1 = E_ISO_TYPE_00
    },

    //03 E_ISOStrategy_Stagger3
    {
    .ISO_FRZ_R1 = E_ISO_TYPE_01,
    .ISO_BPC_BPC_R1 = E_ISO_TYPE_01,
    .ISO_BPC_BPC_R2 = E_ISO_TYPE_02,
    .ISO_BPC_BPC_R3 = E_ISO_TYPE_00,
    .ISO_BPC_CT_R1  = E_ISO_TYPE_01,
    .ISO_BPC_CT_R2  = E_ISO_TYPE_02,
    .ISO_BPC_CT_R3  = E_ISO_TYPE_00,
    .ISO_BPC_PDC_R1 = E_ISO_TYPE_01,
    .ISO_BPC_PDC_R2 = E_ISO_TYPE_02,
    .ISO_BPC_PDC_R3 = E_ISO_TYPE_00,
    .ISO_OBC_R1 = E_ISO_TYPE_01,
    .ISO_OBC_R2 = E_ISO_TYPE_02,
    .ISO_OBC_R3 = E_ISO_TYPE_00,
    .ISO_FUS_R1 = E_ISO_TYPE_00,
    .ISO_DGN_R1 = E_ISO_TYPE_00,
    .ISO_LSC_R1 = E_ISO_TYPE_00,
    .ISO_WB_R1  = E_ISO_TYPE_00,
    .ISO_HLR_R1 = E_ISO_TYPE_00,
    .ISO_LTM_R1 = E_ISO_TYPE_00,
    .ISO_RRZ_R1 = E_ISO_TYPE_00,
    .ISO_DM_R1  = E_ISO_TYPE_00,
    .ISO_FLC_R1 = E_ISO_TYPE_00,
    .ISO_CCM_R1 = E_ISO_TYPE_00,
    .ISO_CCM_R2 = E_ISO_TYPE_00,
    .ISO_CCM_R3 = E_ISO_TYPE_00,
    .ISO_GGM_R1 = E_ISO_TYPE_00,
    .ISO_GGM_R2 = E_ISO_TYPE_00,
    .ISO_GGM_R3 = E_ISO_TYPE_00,
     //P2
    .ISO_BPC_BPC_D1 = E_ISO_TYPE_00,
    .ISO_BPC_CT_D1  = E_ISO_TYPE_00,
    .ISO_BPC_PDC_D1 = E_ISO_TYPE_00,
    .ISO_OBC_D1 = E_ISO_TYPE_00,
    .ISO_DGN_D1 = E_ISO_TYPE_00,
    .ISO_LSC_D1 = E_ISO_TYPE_00,
    .ISO_WB_D1  = E_ISO_TYPE_00,
    .ISO_HLR_D1 = E_ISO_TYPE_00,
    .ISO_LTM_D1 = E_ISO_TYPE_00,
    .ISO_DM_D1  = E_ISO_TYPE_00,
    .ISO_LDNR_D1 = E_ISO_TYPE_00,
    .ISO_FLC_D1 = E_ISO_TYPE_00,
    .ISO_CCM_D1 = E_ISO_TYPE_00,
    .ISO_CCM_D2 = E_ISO_TYPE_00,
    .ISO_GGM_D1 = E_ISO_TYPE_00,
    .ISO_GGM_D2 = E_ISO_TYPE_00,
    .ISO_NDG_D1 = E_ISO_TYPE_00,
    .ISO_YNR_D1 = E_ISO_TYPE_00,
    .ISO_IGGM_D1 = E_ISO_TYPE_00,
    .ISO_GGM_D3 = E_ISO_TYPE_00,
    .ISO_DCE_D1 = E_ISO_TYPE_00,
    .ISO_EE_D1  = E_ISO_TYPE_00,
    .ISO_AKS_D1 = E_ISO_TYPE_00,
    .ISO_NDG_D2 = E_ISO_TYPE_00,
    .ISO_CNR_D1 = E_ISO_TYPE_00,
    .ISO_CCR_D1 = E_ISO_TYPE_00,
    .ISO_BOK_D1 = E_ISO_TYPE_00,
    .ISO_ABF_D1 = E_ISO_TYPE_00,
    .ISO_COLOR_D1 = E_ISO_TYPE_00,
    .ISO_NR3D_D1 = E_ISO_TYPE_00,
    .ISO_MFB_D1 = E_ISO_TYPE_00
    },

    //04 E_ISOStrategy_Reserved
    {
    .ISO_FRZ_R1 = E_ISO_TYPE_00,
    .ISO_BPC_BPC_R1 = E_ISO_TYPE_00,
    .ISO_BPC_BPC_R2 = E_ISO_TYPE_00,
    .ISO_BPC_BPC_R3 = E_ISO_TYPE_00,
    .ISO_BPC_CT_R1  = E_ISO_TYPE_00,
    .ISO_BPC_CT_R2  = E_ISO_TYPE_00,
    .ISO_BPC_CT_R3  = E_ISO_TYPE_00,
    .ISO_BPC_PDC_R1 = E_ISO_TYPE_00,
    .ISO_BPC_PDC_R2 = E_ISO_TYPE_00,
    .ISO_BPC_PDC_R3 = E_ISO_TYPE_00,
    .ISO_OBC_R1 = E_ISO_TYPE_00,
    .ISO_OBC_R2 = E_ISO_TYPE_00,
    .ISO_OBC_R3 = E_ISO_TYPE_00,
    .ISO_FUS_R1 = E_ISO_TYPE_00,
    .ISO_DGN_R1 = E_ISO_TYPE_00,
    .ISO_LSC_R1 = E_ISO_TYPE_00,
    .ISO_WB_R1  = E_ISO_TYPE_00,
    .ISO_HLR_R1 = E_ISO_TYPE_00,
    .ISO_LTM_R1 = E_ISO_TYPE_00,
    .ISO_RRZ_R1 = E_ISO_TYPE_00,
    .ISO_DM_R1  = E_ISO_TYPE_00,
    .ISO_FLC_R1 = E_ISO_TYPE_00,
    .ISO_CCM_R1 = E_ISO_TYPE_00,
    .ISO_CCM_R2 = E_ISO_TYPE_00,
    .ISO_CCM_R3 = E_ISO_TYPE_00,
    .ISO_GGM_R1 = E_ISO_TYPE_00,
    .ISO_GGM_R2 = E_ISO_TYPE_00,
    .ISO_GGM_R3 = E_ISO_TYPE_00,
     //P2
    .ISO_BPC_BPC_D1 = E_ISO_TYPE_01,
    .ISO_BPC_CT_D1  = E_ISO_TYPE_01,
    .ISO_BPC_PDC_D1 = E_ISO_TYPE_01,
    .ISO_OBC_D1 = E_ISO_TYPE_01,
    .ISO_DGN_D1 = E_ISO_TYPE_01,
    .ISO_LSC_D1 = E_ISO_TYPE_01,
    .ISO_WB_D1  = E_ISO_TYPE_01,
    .ISO_HLR_D1 = E_ISO_TYPE_01,
    .ISO_LTM_D1 = E_ISO_TYPE_01,
    .ISO_DM_D1  = E_ISO_TYPE_01,
    .ISO_LDNR_D1 = E_ISO_TYPE_01,
    .ISO_FLC_D1 = E_ISO_TYPE_01,
    .ISO_CCM_D1 = E_ISO_TYPE_01,
    .ISO_CCM_D2 = E_ISO_TYPE_01,
    .ISO_GGM_D1 = E_ISO_TYPE_01,
    .ISO_GGM_D2 = E_ISO_TYPE_01,
    .ISO_NDG_D1 = E_ISO_TYPE_01,
    .ISO_YNR_D1 = E_ISO_TYPE_01,
    .ISO_IGGM_D1 = E_ISO_TYPE_01,
    .ISO_GGM_D3 = E_ISO_TYPE_01,
    .ISO_DCE_D1 = E_ISO_TYPE_01,
    .ISO_EE_D1  = E_ISO_TYPE_01,
    .ISO_AKS_D1 = E_ISO_TYPE_01,
    .ISO_NDG_D2 = E_ISO_TYPE_01,
    .ISO_CNR_D1 = E_ISO_TYPE_01,
    .ISO_CCR_D1 = E_ISO_TYPE_01,
    .ISO_BOK_D1 = E_ISO_TYPE_01,
    .ISO_ABF_D1 = E_ISO_TYPE_01,
    .ISO_COLOR_D1 = E_ISO_TYPE_01,
    .ISO_NR3D_D1 = E_ISO_TYPE_01,
    .ISO_MFB_D1 = E_ISO_TYPE_01
    }
};


MVOID*
IspTuningCustom::
get_feature_ISO_Table(MUINT32 eSensorDev) const
{
    return &isp_profile_iso_table;
}

MVOID
IspTuningCustom::
calculate_ISP_ISO(RAWIspCamInfo& rCamInfo, MINT32 i4SubsampleIdex)
{

    if(rCamInfo.i4FUS_Effective_Num < 2){
        rCamInfo.eISP_Strategy = E_ISOStrategy_Normal;
    }
    else{
        switch (rCamInfo.EHWHDRMode)
        {
            case NSIspTuning::EHWHDRType_Stagger3:
                if (rCamInfo.i4FUS_Effective_Num == 2){
                    rCamInfo.eISP_Strategy = E_ISOStrategy_Stagger2;
                }
                else{
                    rCamInfo.eISP_Strategy = E_ISOStrategy_Stagger3;
                }
                break;
            case NSIspTuning::EHWHDRType_Stagger2:
                rCamInfo.eISP_Strategy = E_ISOStrategy_Stagger2;
                break;
            case NSIspTuning::EHWHDRType_mStream:
                rCamInfo.eISP_Strategy = E_ISOStrategy_mStream;
                break;
            default:
                rCamInfo.eISP_Strategy = E_ISOStrategy_Normal;
                break;
        }
    }
    switch (rCamInfo.eISP_Strategy)
    {
        case E_ISOStrategy_Normal:
            rCamInfo.ISP_ISO[E_ISO_TYPE_00] = rCamInfo.rAEInfo.u4P1RealISOValue;
            rCamInfo.ISP_ISO[E_ISO_TYPE_01] = rCamInfo.rAEInfo.u4P2RealISOValue;
            rCamInfo.ISP_ISO[E_ISO_TYPE_02] = 0;
            rCamInfo.ISP_ISO[E_ISO_TYPE_03] = 0;
            rCamInfo.ISP_ISO[E_ISO_TYPE_04] = 0;
            rCamInfo.ISP_ISO[E_ISO_TYPE_05] = 0;
            break;
        case E_ISOStrategy_mStream:
/*
            //if SE, do we have ratio at this time?
            rCamInfo.ISP_ISO[E_ISO_TYPE_00] = 0
            //only for R1
            rCamInfo.ISP_ISO[E_ISO_TYPE_01] = rCamInfo.rAEInfo.u4SE_Real_ISO * rCamInfo.rAEInfo.i4LESE_Ratio;
            rCamInfo.ISP_ISO[E_ISO_TYPE_02] = 0;
            rCamInfo.ISP_ISO[E_ISO_TYPE_03] = 0;
            rCamInfo.ISP_ISO[E_ISO_TYPE_04] = 0;
            rCamInfo.ISP_ISO[E_ISO_TYPE_05] = 0;
*/
            //R2, HDR_ISO (after FUS)
            rCamInfo.ISP_ISO[E_ISO_TYPE_00] = (rCamInfo.rAEInfo.u4SE_Real_ISO * rCamInfo.rAEInfo.i4LESE_Ratio+50)/100;
            //R1
            rCamInfo.ISP_ISO[E_ISO_TYPE_01] = rCamInfo.rAEInfo.u4LE_Real_ISO;
            //Only for BPC_R2
            rCamInfo.ISP_ISO[E_ISO_TYPE_02] = rCamInfo.rAEInfo.i4LESE_Ratio;
            rCamInfo.ISP_ISO[E_ISO_TYPE_03] = 0;
            rCamInfo.ISP_ISO[E_ISO_TYPE_04] = 0;
            rCamInfo.ISP_ISO[E_ISO_TYPE_05] = 0;
            break;
        case E_ISOStrategy_Stagger2:
            //R1, HDR_ISO (after FUS)
            rCamInfo.ISP_ISO[E_ISO_TYPE_00] = (rCamInfo.rAEInfo.u4SE_Real_ISO * rCamInfo.rAEInfo.i4LESE_Ratio+50)/100;
            //R2
            rCamInfo.ISP_ISO[E_ISO_TYPE_01] = rCamInfo.rAEInfo.u4LE_Real_ISO;
            rCamInfo.ISP_ISO[E_ISO_TYPE_03] = 0;
            rCamInfo.ISP_ISO[E_ISO_TYPE_04] = 0;
            rCamInfo.ISP_ISO[E_ISO_TYPE_05] = 0;
            break;
        case E_ISOStrategy_Stagger3:
            //R3, HDR_ISO (after FUS)
            rCamInfo.ISP_ISO[E_ISO_TYPE_00] = (rCamInfo.rAEInfo.u4ME_Real_ISO * rCamInfo.rAEInfo.i4LEME_Ratio+50)/100;
            //R1
            rCamInfo.ISP_ISO[E_ISO_TYPE_01] = (rCamInfo.rAEInfo.u4SE_Real_ISO * rCamInfo.rAEInfo.i4LESE_Ratio+50)/100;
            //R2
            rCamInfo.ISP_ISO[E_ISO_TYPE_02] = rCamInfo.rAEInfo.u4LE_Real_ISO;
            rCamInfo.ISP_ISO[E_ISO_TYPE_03] = 0;
            rCamInfo.ISP_ISO[E_ISO_TYPE_04] = 0;
            rCamInfo.ISP_ISO[E_ISO_TYPE_05] = 0;
            break;
        default:
            MY_LOG("Unexpected ISO Strategy %d", rCamInfo.eISP_Strategy);
    }

/*
MUINT32 u4LE_Real_ISO;
MUINT32 u4ME_Real_ISO;
MUINT32 u4SE_Real_ISO;
MUINT32 u4VSE_Real_ISO;
// hdr ratio
MINT32 i4LESE_Ratio;  //NESE
MINT32 i4LEME_Ratio;  //NEME
MINT32 i4MESE_Ratio;
MINT32 i4SEVSE_Ratio;
*/

}

MVOID
IspTuningCustom::
get_feature_scalibity(std::unordered_map<std::string, MBOOL> &moduleList)
{
    moduleList["OBC"] = MTRUE;
    moduleList["RRZ"] = MTRUE;
    moduleList["FRZ"] = MTRUE;
    moduleList["BPC"] = MTRUE;
    moduleList["CT"]  = MTRUE;
    moduleList["PDC"] = MTRUE;
    moduleList["DGN"] = MTRUE;
    moduleList["LSC"] = MTRUE;
    moduleList["WB"]  = MTRUE;
    moduleList["LTMS"] = MTRUE;
    moduleList["LTM"] = MTRUE;
    moduleList["HLR"] = MTRUE;
    moduleList["SLK"] = MTRUE;
    moduleList["DM"]  = MTRUE;
    moduleList["FLC"] = MTRUE;
    moduleList["CCM"] = MTRUE;
    moduleList["LCES"]= MTRUE;
    moduleList["GGM"] = MTRUE;
    moduleList["G2C"] = MTRUE;
    moduleList["YNRS"]= MTRUE;
    moduleList["FUS"]= MTRUE;

    moduleList["LDNR"]= MTRUE;
    moduleList["LCE"] = MTRUE;
    moduleList["G2CX"]= MTRUE;
    moduleList["YNR"] = MTRUE;
    moduleList["YNR_FACE"] = MTRUE;
    moduleList["YNR_LCE"] = MTRUE;
    moduleList["DCES"]= MTRUE;
    moduleList["DCE"] = MTRUE;
    moduleList["EE"]  = MTRUE;
    moduleList["CNR"] = MTRUE;
    moduleList["CCR"] = MTRUE;
    moduleList["ABF"] = MTRUE;
    moduleList["BOK"] = MTRUE;
    moduleList["NDG"] = MTRUE;
    moduleList["COLOR"] = MTRUE;
    moduleList["AKS"] = MTRUE;
    moduleList["NR3D"]= MTRUE;
    moduleList["MIX"] = MTRUE;
    moduleList["LPCNR"] = MTRUE;
    moduleList["MSYUV"] = MTRUE;
    moduleList["MFB"] = MTRUE;
    moduleList["OMC"] = MTRUE;

}

MUINT32 get_normal_SWNR_ENC_enable_ISO_threshold()
{
#define NORMAL_SWNR_ENC_ENABLE_ISO_THRESHOLD (800) // enable if ISO >= THRESHOLD
    return NORMAL_SWNR_ENC_ENABLE_ISO_THRESHOLD;
}

MUINT32 get_MFB_SWNR_ENC_enable_ISO_threshold()
{
#define MFB_SWNR_ENC_ENABLE_ISO_THRESHOLD (800) // enable if ISO >= THRESHOLD
    return MFB_SWNR_ENC_ENABLE_ISO_THRESHOLD;
}


MVOID
IspTuningCustom::
refine_CamInfo(RAWIspCamInfo& rCamInfo)
{
    (void)rCamInfo;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_OBC(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_OBC_T& rOBC)
{
    (void)rCamInfo;
    (void)rOBC;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_BPC(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_BPC_BPC_T& rBPC)
{
    (void)rCamInfo;
    (void)rBPC;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_CT(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_BPC_CT_T& rCT)
{
    (void)rCamInfo;
    (void)rCT;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_PDC(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_BPC_PDC_T& rPDC)
{
    (void)rCamInfo;
    (void)rPDC;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_DM(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_DM_T& rDM)
{
    (void)rCamInfo;
    (void)rDM;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_FLC(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_FLC_T& rFLC)
{
    (void)rCamInfo;
    (void)rFLC;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_CCM(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_CCM_T& rCCM)
{
    switch (SubModuleIndex)
    {
        case ISP_MGR_CCM::ECCM_D1:
            if(rCamInfo.rMapping_Info.eIspProfile == EIspProfile_N3D_Capture_Depth_toW)
            {
                if( !m_CCM_DualPara_valid ){
                    const strSyncAEInitInfo* pSyncAEInitInfo = getSyncAEInitInfo();
                    ::memcpy(m_CCM_DualPara, pSyncAEInitInfo->RGB2YCoef_main, sizeof(MUINT32)*3);
                    m_CCM_DualPara_valid = MTRUE;
                }
                RGB2WMatrix( m_CCM_DualPara, rCamInfo.rAWBInfo.rCurrentAWBGain, rCCM);
            }
            break;
        case ISP_MGR_CCM::ECCM_D2:
            {
                if(rCamInfo.rMapping_Info.eIspProfile == EIspProfile_VSDOF_PV_Main_toW )
                {
                    if( !m_CCM_DualPara_valid ){
                        const strSyncAEInitInfo* pSyncAEInitInfo = getSyncAEInitInfo();
                        ::memcpy(m_CCM_DualPara, pSyncAEInitInfo->RGB2YCoef_main, sizeof(MUINT32)*3);
                        m_CCM_DualPara_valid = MTRUE;
                    }
                    RGB2WMatrix( m_CCM_DualPara, rCamInfo.rAWBInfo.rCurrentAWBGain, rCCM);
                }

                if((rCamInfo.rMapping_Info.eIspProfile == EIspProfile_VSDOF_PV_Main) ||
                   (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_VSDOF_PV_Aux))
                {
                    ISP_NVRAM_CCM_T rCCMIn = {0};
                    ::memcpy(&rCCMIn, &rCCM, sizeof(ISP_NVRAM_CCM_T));
                    RGB2YLinear(rCCMIn, rCCM);
                }
            }
            break;
        default:
            break;
    }
}


MVOID
IspTuningCustom::
RGB2WMatrix(const MUINT32 L[], const AWB_GAIN_T& PGN, ISP_NVRAM_CCM_T& W)
{
    const int accuracy = 11;
    int mul = 1 << accuracy;
    float fL[3];
    int iL[3];
    fL[0] = (float)L[0] / 10000;
    fL[1] = (float)L[1] / 10000;
    fL[2] = (float)L[2] / 10000;
    // For PGN 1x = 512
    fL[0] = fL[0] * 512 / (float)PGN.i4R;
    fL[1] = fL[1] * 512 / (float)PGN.i4G;
    fL[2] = fL[2] * 512 / (float)PGN.i4B;
    iL[0] = (unsigned int)(fL[0] * mul);
    iL[1] = (unsigned int)(fL[1] * mul);
    iL[2] = (unsigned int)(fL[2] * mul);
    W.cnv_1.bits.CCM_CNV_00 = iL[0];
    W.cnv_1.bits.CCM_CNV_01 = iL[1];
    W.cnv_2.bits.CCM_CNV_02 = iL[2];
    W.cnv_3.bits.CCM_CNV_10 = iL[0];
    W.cnv_3.bits.CCM_CNV_11 = iL[1];
    W.cnv_4.bits.CCM_CNV_12 = iL[2];
    W.cnv_5.bits.CCM_CNV_20 = iL[0];
    W.cnv_5.bits.CCM_CNV_21 = iL[1];
    W.cnv_6.bits.CCM_CNV_22 = iL[2];
}


MVOID
IspTuningCustom::
RGB2YLinear(const ISP_NVRAM_CCM_T& inW, ISP_NVRAM_CCM_T& outW)
{
    const int accuracy = 11;

    float fL[3];
    int iL[3];

    // transform to signed value
    int transW[9];
    transW[0] = inW.cnv_1.bits.CCM_CNV_00 > 4095 ? (int)inW.cnv_1.bits.CCM_CNV_00 - 8192 : inW.cnv_1.bits.CCM_CNV_00;
    transW[1] = inW.cnv_1.bits.CCM_CNV_01 > 4095 ? (int)inW.cnv_1.bits.CCM_CNV_01 - 8192 : inW.cnv_1.bits.CCM_CNV_01;
    transW[2] = inW.cnv_2.bits.CCM_CNV_02 > 4095 ? (int)inW.cnv_2.bits.CCM_CNV_02 - 8192 : inW.cnv_2.bits.CCM_CNV_02;
    transW[3] = inW.cnv_3.bits.CCM_CNV_10 > 4095 ? (int)inW.cnv_3.bits.CCM_CNV_10 - 8192 : inW.cnv_3.bits.CCM_CNV_10;
    transW[4] = inW.cnv_3.bits.CCM_CNV_11 > 4095 ? (int)inW.cnv_3.bits.CCM_CNV_11 - 8192 : inW.cnv_3.bits.CCM_CNV_11;
    transW[5] = inW.cnv_4.bits.CCM_CNV_12 > 4095 ? (int)inW.cnv_4.bits.CCM_CNV_12 - 8192 : inW.cnv_4.bits.CCM_CNV_12;
    transW[6] = inW.cnv_5.bits.CCM_CNV_20 > 4095 ? (int)inW.cnv_5.bits.CCM_CNV_20 - 8192 : inW.cnv_5.bits.CCM_CNV_20;
    transW[7] = inW.cnv_5.bits.CCM_CNV_21 > 4095 ? (int)inW.cnv_5.bits.CCM_CNV_21 - 8192 : inW.cnv_5.bits.CCM_CNV_21;
    transW[8] = inW.cnv_6.bits.CCM_CNV_22 > 4095 ? (int)inW.cnv_6.bits.CCM_CNV_22 - 8192 : inW.cnv_6.bits.CCM_CNV_22;

    // Note the accuarcy is increased from 9 to 11, the coefficient is sum to 4
    fL[0] = 1.196f * transW[0] + 2.348f * transW[3] + 0.456f * transW[6];
    fL[1] = 1.196f * transW[1] + 2.348f * transW[4] + 0.456f * transW[7];
    fL[2] = 1.196f * transW[2] + 2.348f * transW[5] + 0.456f * transW[8];

    iL[0] = fL[0] >= 0 ? int(fL[0] + 0.5f) : -int(-fL[0] + 0.5f);
    iL[1] = fL[1] >= 0 ? int(fL[1] + 0.5f) : -int(-fL[1] + 0.5f);
    iL[2] = fL[2] >= 0 ? int(fL[2] + 0.5f) : -int(-fL[2] + 0.5f);

    // transform to unsigned value
    iL[0] = iL[0] >= 0 ? (iL[0] > 4095 ? 4095 : iL[0]) : (iL[0] < -4096 ? 4096 : iL[0]+8192);
    iL[1] = iL[1] >= 0 ? (iL[1] > 4095 ? 4095 : iL[1]) : (iL[1] < -4096 ? 4096 : iL[1]+8192);
    iL[2] = iL[2] >= 0 ? (iL[2] > 4095 ? 4095 : iL[2]) : (iL[2] < -4096 ? 4096 : iL[2]+8192);

    outW.cnv_1.bits.CCM_CNV_00 = iL[0];
    outW.cnv_1.bits.CCM_CNV_01 = iL[1];
    outW.cnv_2.bits.CCM_CNV_02 = iL[2];
    outW.cnv_3.bits.CCM_CNV_10 = iL[0];
    outW.cnv_3.bits.CCM_CNV_11 = iL[1];
    outW.cnv_4.bits.CCM_CNV_12 = iL[2];
    outW.cnv_5.bits.CCM_CNV_20 = iL[0];
    outW.cnv_5.bits.CCM_CNV_21 = iL[1];
    outW.cnv_6.bits.CCM_CNV_22 = iL[2];
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_GGM(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_GGM_T& rGGM)
{
    (void)rCamInfo;
    (void)rGGM;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_YNRS(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_YNRS_T& rYNRS)
{
    (void)rCamInfo;
    (void)rYNRS;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_YNR(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_YNR_T& rYNR)
{
    (void)rCamInfo;
    (void)rYNR;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_LDNR(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_LDNR_T& rLDNR)
{
    (void)rCamInfo;
    (void)rLDNR;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_LCE(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_LCE_T& rLCE)
{
    (void)rCamInfo;
    (void)rLCE;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_DCE(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_DCE_T& rDCE)
{
    (void)rCamInfo;
    (void)rDCE;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_EE(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_EE_T& rEE)
{
    (void)rCamInfo;
    (void)rEE;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_CNR(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_CNR_CNR_T& rCNR)
{
    (void)rCamInfo;
    (void)rCNR;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_CCR(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_CNR_CCR_T& rCCR)
{
    (void)rCamInfo;
    (void)rCCR;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_ABF(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_CNR_ABF_T& rABF)
{
    (void)rCamInfo;
    (void)rABF;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_COLOR(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_COLOR_T& rCOLOR)
{
    (void)rCamInfo;
    (void)rCOLOR;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_MIX(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_MIX_T& rMIX)
{
    (void)rCamInfo;
    (void)rMIX;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_MFB(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_MFB_T& rMFB)
{
    (void)rCamInfo;
    (void)rMFB;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_NR3D(MUINT8 SubModuleIndex, RAWIspCamInfo const& rCamInfo, ISP_NVRAM_NR3D_T& rNR3D)
{
    (void)rCamInfo;
    (void)rNR3D;

    switch (SubModuleIndex)
    {
        default:
            break;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MVOID
IspTuningCustom::
refine_LSC(RAWIspCamInfo const& rCamInfo, MUINT32& u4Rto)
{
    (void)rCamInfo;
    (void)u4Rto;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MBOOL
IspTuningCustom::
is_to_invoke_capture_in_color(RAWIspCamInfo const& rCamInfo)
{
    if (// normal capture
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Capture ||\
        rCamInfo.rMapping_Info.eIspProfile == Comm_EIspProfile_Capture_DCE || \
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Capture_Capture_ZOOM1 || \
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Capture_Capture_ZOOM2 || \
        // flash capture
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Flash_Capture ||\
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Flash_Capture_ZOOM1 || \
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Flash_Capture_ZOOM2 || \

        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Bokeh ||\
        // HDR
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Capture || \
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Capture_DCE ||\
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Capture_DSDN ||\

        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_mHDR_Capture || \
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_mHDR_Capture_DCE ||\
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_mHDR_Capture_DSDN ||\

        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_mHDR_Capture ||\
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_mHDR_Capture_DCE ||\

        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_zHDR_Capture ||\
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_zHDR_Capture_DCE ||\
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_zHDR_Capture_DSDN ||\

        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Capture_MFNR_After_Blend ||\

        // N3D
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_N3D_Capture ||\
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_N3D_Capture_Full ||\
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_N3D_Capture_Depth ||\
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_N3D_Capture_Depth_toW ||\
        // MFNR
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_MFNR_After_Blend || \
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_MFNR_After_ZOOM1 || \
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_MFNR_After_ZOOM2 || \

        // HDR Flash Capture
        //rCamInfo.eIspProfile == EIspProfile_zHDR_Flash_Capture

        // AIHDR
        rCamInfo.rMapping_Info.eIspProfile == EIspProfile_AIISP_HDR_Capture_DCE
        )
    {
        return MTRUE;
    }
    else
    {
        return MFALSE;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
IspTuningCustom::
is_to_invoke_isp_interpolation(RAWIspCamInfo const& rCamInfo)
{
    (void)rCamInfo;

    return MTRUE;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MBOOL
IspTuningCustom::
is_HDRTuning(RAWIspCamInfo const& rCamInfo){

    if((rCamInfo.rMapping_Info.eIspProfile == EIspProfile_iHDR_Preview)                     ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Preview)                     ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_mHDR_Preview)                     ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_iHDR_Video)                       ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Video)                       ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_mHDR_Video)                       ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_iHDR_Preview_VSS)                 ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Preview_VSS)                 ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_mHDR_Preview_VSS)                 ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_iHDR_Video_VSS)                   ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Video_VSS)                   ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_mHDR_Video_VSS)                   ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Capture)                     ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_mHDR_Capture)                     ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_iHDR_Preview)                ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_zHDR_Preview)                ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_mHDR_Preview)                ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_iHDR_Video)                  ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_zHDR_Video)                  ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_mHDR_Video)                  ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_iHDR_Preview_VSS)            ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_zHDR_Preview_VSS)            ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_mHDR_Preview_VSS)            ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_iHDR_Video_VSS)              ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_zHDR_Video_VSS)              ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_mHDR_Video_VSS)              ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_zHDR_Capture)                ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Capture_MFNR_Before_Blend)   ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Capture_MFNR_Single)         ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Capture_MFNR_MFB)            ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Capture_MFNR_After_Blend)    ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_EIS_iHDR_Preview)                 ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_EIS_zHDR_Preview)                 ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_EIS_mHDR_Preview)                 ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_EIS_iHDR_Video)                   ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_EIS_zHDR_Video)                   ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_EIS_mHDR_Video)                   ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_EIS_Auto_iHDR_Preview)            ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_EIS_Auto_zHDR_Preview)            ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_EIS_Auto_mHDR_Preview)            ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_EIS_Auto_iHDR_Video)              ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_EIS_Auto_zHDR_Video)              ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_EIS_Auto_mHDR_Video)){
       //(rCamInfo.eIspProfile == EIspProfile_zHDR_Flash_Capture)){
       return MTRUE;
    }

    return MFALSE;

}
MBOOL
IspTuningCustom::
is_ZHDRTuning(RAWIspCamInfo const& rCamInfo){
       if ((rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Preview)                 ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Video)                       ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Preview_VSS)                 ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Video_VSS)                   ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Preview)                     ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Video)                       ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Preview_VSS)                 ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Video_VSS)                   ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Video_VSS)                   ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Capture)                     ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_zHDR_Preview)                ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_zHDR_Video)                  ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_zHDR_Preview_VSS)            ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_zHDR_Video_VSS)              ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_Auto_zHDR_Capture)                ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Capture_MFNR_Before_Blend)   ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Capture_MFNR_Single)         ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Capture_MFNR_MFB)            ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_zHDR_Capture_MFNR_After_Blend)    ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_EIS_zHDR_Preview)                 ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_EIS_zHDR_Video)                   ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_EIS_Auto_zHDR_Preview)            ||
       (rCamInfo.rMapping_Info.eIspProfile == EIspProfile_EIS_Auto_zHDR_Video)){
       return MTRUE;
       }
    return MFALSE;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*******************************************************************************
*
* eIdx_Shading_CCT_old:
*   [in] the previous color temperature index
*           eIDX_Shading_CCT_ALight
*           eIDX_Shading_CCT_CWF
*           eIDX_Shading_CCT_D65
*
* i4CCT:
*   [in] the current color temperature from 3A.
*
*
* return:
*   [out] the current color temperature index
*           eIDX_Shading_CCT_ALight
*           eIDX_Shading_CCT_CWF
*           eIDX_Shading_CCT_D65
*
*******************************************************************************/
EIndex_Shading_CCT_T
IspTuningCustom::
evaluate_Shading_CCT_index  (
        LSC_INPUT_INFO_T const& rLSCInfo
)   const
{
    MUINT32 EN_LSC_LOG_TSF_RUN = (1<<6);
    MUINT32 m_u4LogEn = property_get_int32("vendor.debug.lsc_mgr.log", 0);
    MBOOL fgLogEn = (m_u4LogEn & EN_LSC_LOG_TSF_RUN) ? MTRUE : MFALSE;

    MINT32 i4CCT = rLSCInfo.i4AWBCCT;

    EIndex_Shading_CCT_T eIdx_Shading_CCT_new = (EIndex_Shading_CCT_T)rLSCInfo.u4ShadingCCT;

//    -----------------|----|----|--------------|----|----|------------------
//                   THH2  TH2  THL2                   THH1  TH1  THL1

    MINT32 const THL1 = 3257;
    MINT32 const THH1 = 3484;
    MINT32 const TH1 = (THL1+THH1)/2; //(THL1 +THH1)/2
    MINT32 const THL2 = 4673;
    MINT32 const THH2 = 5155;
    MINT32 const TH2 = (THL2+THH2)/2;//(THL2 +THH2)/2

    switch  ((EIndex_Shading_CCT_T)rLSCInfo.u4ShadingCCT)
    {
    case eIDX_Shading_CCT_ALight:
        if  ( i4CCT < THH1 )
        {
            eIdx_Shading_CCT_new = eIDX_Shading_CCT_ALight;
        }
        else if ( i4CCT <  TH2)
        {
            eIdx_Shading_CCT_new = eIDX_Shading_CCT_CWF;
        }
        else
        {
            eIdx_Shading_CCT_new = eIDX_Shading_CCT_D65;
        }
        break;
    case eIDX_Shading_CCT_CWF:
        if  ( i4CCT < THL1 )
        {
            eIdx_Shading_CCT_new = eIDX_Shading_CCT_ALight;
        }
        else if ( i4CCT < THH2 )
        {
            eIdx_Shading_CCT_new = eIDX_Shading_CCT_CWF;
        }
        else
        {
            eIdx_Shading_CCT_new = eIDX_Shading_CCT_D65;
        }
        break;
    case eIDX_Shading_CCT_D65:
        if  ( i4CCT < TH1 )
        {
            eIdx_Shading_CCT_new = eIDX_Shading_CCT_ALight;
        }
        else if ( i4CCT < THL2 )
        {
            eIdx_Shading_CCT_new = eIDX_Shading_CCT_CWF;
        }
        else
        {
            eIdx_Shading_CCT_new = eIDX_Shading_CCT_D65;
        }
        break;
    default:
        break;
    }

    if  ( (EIndex_Shading_CCT_T)rLSCInfo.u4ShadingCCT != eIdx_Shading_CCT_new )
    {
        MY_LOG_IF(fgLogEn,
            "[-evaluate_Shading_CCT_index] Shading CCT Idx(old,new)=(%d,%d), i4CCT = %d\n"
            , (EIndex_Shading_CCT_T)rLSCInfo.u4ShadingCCT, eIdx_Shading_CCT_new,i4CCT
        );
    }

    return  eIdx_Shading_CCT_new;
}

void profileSensorModeMapping(MINT32 (&iso)[10], MINT32 (&rto)[10],
    MUINT32 profile, MUINT32 sensorID, MUINT32 mode, MUINT32 en_vra)
{
#define ASSIGN_VALUE(array, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9) \
{ \
    int tmp[10] = { v0, v1, v2, v3, v4, v5, v6, v7, v8, v9 };\
    for( int i = 0; i < 10; i++ ) \
        array[i] = tmp[i]; \
}

    if (profile == EIspProfile_AIISP_DRC ||
        profile == EIspProfile_AIISP_HDR_DRC) {
        // detect AI HDR mode and use customize RA mapping table
        MY_LOG("[%s] AI_HDR_RA is AI_HDR profile", __FUNCTION__);
        ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 4800, 16000);
        ASSIGN_VALUE(rto, 16, 16, 16, 15, 14, 13, 13, 13, 13, 5);
    } else if (profile == EIspProfile_ms2HDR_Preview  ||
               profile == EIspProfile_stg2HDR_Preview ||
               profile == EIspProfile_stg3HDR_Preview ||
               profile == EIspProfile_ms2HDR_Video    ||
               profile == EIspProfile_stg2HDR_Video   ||
               profile == EIspProfile_stg3HDR_Video
      ) { // VHDR_on RA custom
        MY_LOG("[%s] Current shading RA is based on VHDR table, sensorID(%x)",
            __FUNCTION__, sensorID);
        switch (sensorID) {
        case 0x3841: { // rear cam
            ASSIGN_VALUE(iso, 100, 400, 800, 1200, 1600, 2000, 2400, 4000, 7000, 16000);
            ASSIGN_VALUE(rto,  32,  32,  30,   27,   24,   21,   19,   14,   12,     9);
            break;
        }
        default:
            ASSIGN_VALUE(iso, 100, 400, 800, 1200, 1600, 2000, 2400, 4000, 7000, 16000);
            ASSIGN_VALUE(rto,  32,  32,  30,   27,   24,   21,   19,   14,   12,     9);
            break;
        }
    } else if (en_vra) { // if vra is on, use a unified iso-ra mapping
        ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
        ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
    } else {
        switch (sensorID) {
        case 0x0001: {
            switch (mode) {
            case ESensorMode_Preview: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Capture: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Video: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom3: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom4: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom5: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            default:
                break;
            }
        }
        case 0x0002: {
            switch (mode) {
            case ESensorMode_Preview: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Capture: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Video: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom3: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom4: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom5: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            default:
                break;
            }
        }
        case 0x0003: {
            switch (mode) {
            case ESensorMode_Preview: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Capture: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Video: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom3: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom4: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom5: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            default:
                break;
            }
        }
        case 0x0004: {
            switch (mode) {
            case ESensorMode_Preview: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Capture: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Video: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom3: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom4: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom5: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            default:
                break;
            }
        }
        case 0x0005: {
            switch (mode) {
            case ESensorMode_Preview: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Capture: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Video: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom3: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom4: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom5: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            default:
                break;
            }
        }
        case 0x0006: {
            switch (mode) {
            case ESensorMode_Preview: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Capture: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Video: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom3: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom4: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom5: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            default:
                break;
            }
        }
        case 0x0007: {
            switch (mode) {
            case ESensorMode_Preview: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Capture: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Video: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom3: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom4: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom5: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            default:
                break;
            }
        }
        case 0x0008: {
            switch (mode) {
            case ESensorMode_Preview: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Capture: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Video: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom3: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom4: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom5: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            default:
                break;
            }
        }
        case 0x0009: {
            switch (mode) {
            case ESensorMode_Preview: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Capture: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Video: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom3: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom4: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom5: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            default:
                break;
            }
        }
        case 0x0010: {
            switch (mode) {
            case ESensorMode_Preview: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Capture: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Video: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_SlimVideo2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom1: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom2: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom3: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom4: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            case ESensorMode_Custom5: {
                ASSIGN_VALUE(iso, 100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200);
                ASSIGN_VALUE(rto, 32, 32, 32, 30, 28, 26, 24, 22, 20, 18);
                break;
            }
            default:
                break;
            }
        }
        default:
            break;
        }
    }
    return;
}

static MINT32 ratioMapping(
    MINT32 i4Iso, const MINT32 *iso_tbl_nvram, const MINT32 *rto_tbl_nvram, MINT32 i4Scenario,
    MUINT32 profile, MUINT32 sensorID, MUINT32 mode, MUINT32 en_vra)
{
#define LERP(x, lo_x, lo_y, hi_x, hi_y)\
    (((hi_x) - (x))*(lo_y) + ((x) - (lo_x))*(hi_y)) / ((hi_x) - (lo_x))

    MUINT32 EN_LSC_LOG_TSF_RUN = (1<<6);
    MUINT32 m_u4LogEn = property_get_int32("vendor.debug.lsc_mgr.log", 0);
    MBOOL fgLogEn = (m_u4LogEn & EN_LSC_LOG_TSF_RUN) ? MTRUE : MFALSE;

    // default
    MINT32 iso[10] = {100, 200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200};
    MINT32 rto[10] = {32, 32, 32, 30, 28, 26, 24, 22, 20, 18};

    if (iso_tbl_nvram != NULL && rto_tbl_nvram != NULL) {
        for(int i = 0; i < 10; i++) {iso[i] = iso_tbl_nvram[i]; rto[i] = rto_tbl_nvram[i];}
    }

    MINT32 i = 0;
    MINT32 i4Rto = 32;

    MUINT32 nvramRaEn = property_get_int32("vendor.debug.lsc_mgr.nvram_ra_en", 0);
    if (false == nvramRaEn) {
        profileSensorModeMapping(iso, rto, profile, sensorID, mode, en_vra);
    }

    MY_LOG_IF(fgLogEn, "[%s] iso tbl {%d, %d, %d, %d, %d, %d, %d, %d, %d, %d}\n"
            , __FUNCTION__
            , iso[0], iso[1], iso[2], iso[3], iso[4], iso[5], iso[6], iso[7], iso[8], iso[9]
        );

    MY_LOG_IF(fgLogEn, "[%s] rto tbl {%d, %d, %d, %d, %d, %d, %d, %d, %d, %d}\n"
            , __FUNCTION__
            , rto[0], rto[1], rto[2], rto[3], rto[4], rto[5], rto[6], rto[7], rto[8], rto[9]
        );

    if (i4Iso < iso[0])
    {
        i4Rto = rto[0];
    }
    else if (i4Iso >= iso[9])
    {
        i4Rto = rto[9];
    }
    else
    {
        for (i = 1; i < 9; i++) // i = 9 (max) when all other i4Iso >= iso[i]
        {
            if (i4Iso < iso[i])
                break;
        }
        i4Rto = LERP(i4Iso, iso[i-1], rto[i-1], iso[i], rto[i]);
    }
    return i4Rto;
}


static MINT32 ratioMappingByEV(MINT32 i4Rto, float i4EV, MUINT32 u4SensorId)
{
#define LERP(x, lo_x, lo_y, hi_x, hi_y)\
    (((hi_x) - (x))*(lo_y) + ((x) - (lo_x))*(hi_y)) / ((hi_x) - (lo_x))

#define mappingTableSize (10)
    float adTBL_EV[mappingTableSize];
    float fTBL_RA[mappingTableSize];

    static const float adTBL_EV_default[mappingTableSize] =
        { -8,  -7,  -6,  -5,   -4,   -2,   -1,    0,    1,  2};
    static const float fTBL_RA_default[mappingTableSize] =
        {  0,   0,   0,   0,    0,  0.2,  0.35,  0.5,   0.8, 1};

    switch(u4SensorId)
    {
        case 0x8d1:
        default:
            memcpy(adTBL_EV, adTBL_EV_default, sizeof(float)*mappingTableSize);
            memcpy(fTBL_RA,  fTBL_RA_default,  sizeof(float) *mappingTableSize);
            break;
    }

    MINT32 i = 0;
    float final_fTBL_RA = 1;

    if (i4EV < adTBL_EV[0])
    {
        final_fTBL_RA = fTBL_RA[0];
    }
    else if (i4EV >= adTBL_EV[9])
    {
        final_fTBL_RA = fTBL_RA[9];
    }
    else
    {
        for (i = 1; i < mappingTableSize - 1; i++) // i = max index when all other i4EV >= adTBL_EV[i]
        {
            if (i4EV < adTBL_EV[i])
                break;
        }
        final_fTBL_RA = LERP((float)i4EV, (float)adTBL_EV[i-1], (float)fTBL_RA[i-1], (float)adTBL_EV[i], (float)fTBL_RA[i]);
    }

    return (((float)(i4Rto))*final_fTBL_RA);
}


//char output_log[256];
//per index is 0.1 EV
MUINT32 power_2_lshift20_positive[46]=
{1048576, 1123836, 1204498, 1290948, 1383604, 1482910, 1589344, 1703417, 1825677, 1956712, 2097152, 2247672, 2408995, 2581897, 2767209, 2965821, 3178688, 3406833, 3651354, 3913424, 4194304, 4495344, 4817990, 5163794, 5534417, 5931642, 6357376, 6813667, 7302707, 7826848, 8388608, 8990687, 9635980, 10327588, 11068835, 11863283, 12714752, 13627334, 14605415, 15653696, 16777216, 17981375, 19271960, 20655176, 22137669, 23726566};
MUINT32  power_2_lshift20_negative[46]=
{1048576, 978356, 912838, 851708, 794672, 741455, 691802, 645474, 602249, 561918, 524288, 489178, 456419, 425854, 397336, 370728, 345901, 322737, 301124, 280959, 262144, 244589, 228210, 212927, 198668, 185364, 172951, 161369, 150562, 140479, 131072, 122295, 114105, 106464, 99334, 92682, 86475, 80684, 75281, 70240, 65536, 61147, 57052, 53232, 49667, 46341};

MVOID
IspTuningCustom::
RA_init(MBOOL RA_init_en){

    if (RA_init_en){
        total_RA_num_frames_ = 0;
        //for(int i=0; i<10; i++){
        //    RA_Buffer_[i]  = 16;
        //}
        MY_LOG_IF(1,"[%s]RA init.\n", __FUNCTION__);
    }

}

MVOID
IspTuningCustom::
ISO_init(MBOOL ISO_init_en){

    if (ISO_init_en){
        total_ISO_num_frames_ = 0;
        //for(int i=0; i<10; i++){
        //    ISO_Buffer_[i]  = 100;
        //}
        MY_LOG_IF(1,"[%s]Iso init.\n", __FUNCTION__);
    }

}

MINT32
IspTuningCustom::
iso_smooth(const MINT32 iso, const MINT32 IsoSmooth_frame, MBOOL iso_en) {

    int idx = total_ISO_num_frames_ % IsoSmooth_frame;
    int avgISO = 0;

    if (idx < 0 || idx > 9) {
        MY_LOG_IF(1,"idx error!\n");
        return iso;
    } else {
		ISO_Buffer_[idx] = iso;
	}

    if (!iso_en || total_ISO_num_frames_ == 0) {
        avgISO = iso;
        MY_LOG_IF(1,"[%s][ISO smooth disabled][ISO idx(%d)]iso = %d.\n", __FUNCTION__, total_ISO_num_frames_, avgISO);
    } else {
        //ISO smooth
        int n_frames;
        n_frames = ((total_ISO_num_frames_+1) < IsoSmooth_frame) ? (total_ISO_num_frames_+1) : (IsoSmooth_frame);

        int buf_idx;
        for (int k = 0; k < n_frames; k++) {
            buf_idx = idx - k;
            buf_idx = (buf_idx < 0 ) ? (buf_idx + n_frames) : buf_idx;
            avgISO += ISO_Buffer_[buf_idx];
        }
        avgISO /= n_frames;

        MY_LOG_IF(1,"[%s][ISO smooth enabled][ISO idx(%d)]avgISO = %d.\n", __FUNCTION__, total_ISO_num_frames_, avgISO);

    }

    total_ISO_num_frames_++;
    return avgISO;
}

MINT32
IspTuningCustom::
RA_smooth(const MINT32 RASmooth_frame, const MINT32 rto_tmp, const MINT32 RA_incremental_step, MBOOL RA_smooth_en){

    //record current iso in ISO buffer
    int idx = total_RA_num_frames_ % RASmooth_frame;;
    int prev_rto = 16; //init prev_rto
    int Rto = 16; //init Rto

    if (total_RA_num_frames_ == 0 || RA_smooth_en == 0) {
        Rto = rto_tmp;
        MY_LOG_IF(1,"[%s][RA smooth disabled]rto for iso(%d)\n", __FUNCTION__, rto_tmp, prev_rto, Rto);
    }
    else {

        //Obtain previous RA and ISO
        int prev_frame = idx - 1;
        if (prev_frame < 0) prev_frame = RASmooth_frame - 1;
        prev_rto = RA_Buffer_[prev_frame];

        if (prev_rto > 32) {
            prev_rto = 32;
        }
        else if (prev_rto < 0) {
            prev_rto = 0;
        }

        //incremental smoothed
        if (RA_incremental_step != 0) {

            if (rto_tmp == prev_rto) {
                Rto = rto_tmp;
            }
            else if (rto_tmp > prev_rto) {
                Rto = prev_rto +
                    ((RA_incremental_step < (rto_tmp - prev_rto)) ? RA_incremental_step : (rto_tmp - prev_rto));
            }
            else if (rto_tmp < prev_rto) {
                Rto = prev_rto -
                    ((RA_incremental_step < (prev_rto - rto_tmp)) ? RA_incremental_step : (prev_rto - rto_tmp));
            }
        }
        else {
            Rto = rto_tmp;
        }
        MY_LOG_IF(1,"[%s][RA smooth][frm idx(%d)] rto for iso(%d), prev_rto(%d),RA_incremental_step(%d), smoothed ratio(%d)\n",
                    __FUNCTION__, total_RA_num_frames_, rto_tmp, prev_rto, RA_incremental_step, Rto);

    }

    //add RA into RA buffer
    RA_Buffer_[idx] = Rto;
    total_RA_num_frames_++;

    return Rto;
}

MINT32
IspTuningCustom::
evaluate_Shading_Ratio  (
        LSC_INPUT_INFO_T const& rLSCInfo,
        MBOOL isSuperNightMode,
        MINT32 pParam
)
{
    /*
        Sample code for evaluate shading ratio.
        The shading ratio is an integer ranging from 0(0%) to 32(100%).
        All informations can be obtained via rCamInfo.
        The following sample code shows a shading ratio evaluated by ISO value with temporal smoothness.
    */

    MUINT32 EN_LSC_LOG_TSF_RUN = (1<<6);
    MUINT32 m_u4LogEn = property_get_int32("vendor.debug.lsc_mgr.log", 0);
    MBOOL fgLogEn = (m_u4LogEn & EN_LSC_LOG_TSF_RUN) ? MTRUE : MFALSE;

    const std::lock_guard<std::mutex> lock(sensorID_mutex);
    MUINT32 sensorid = getSensorID();
    MY_LOG_IF(fgLogEn,
        "[%s] lscHwType(%d), eIspProfile(%d), sensorid(%d), eSensorMode(%d)"
        "eApp(%d)",
        __FUNCTION__, rLSCInfo.lscHwType, rLSCInfo.IspProfile, sensorid,
        rLSCInfo.SensorMode, rLSCInfo.eApp);

    MINT32 Avg_Frm_Cnt = 5;
    MINT32 i4Rto = 16; //32;
    MINT32 i4Iso = rLSCInfo.u4RealISOValue;
    MINT32 i4Scenario = pParam;
    MINT32 prev_iso = 100, prev_rto = 16, rto_tmp = 16; //initialization
    int *p_global_Ra = ISO_Buffer_;
    int RA_smooth_frame = 10;

    // to prevent total frames overflow
    if (total_RA_num_frames_ >= 65535) {
        total_RA_num_frames_ = 0;
        MY_LOG_IF(fgLogEn,"[%s][total_RA_num_frames_>= 65535]Set total_RA_num_frames_(%d)", __FUNCTION__,total_RA_num_frames_);
    }
    if (total_ISO_num_frames_>= 65535) {
        total_ISO_num_frames_ = 0;
        MY_LOG_IF(fgLogEn,"[%s][total_ISO_num_frames_>= 65535]Set total_ISO_num_frames_(%d)", __FUNCTION__,total_ISO_num_frames_);
    }
    if (total_RA_num_frames_ < 0) {
        total_RA_num_frames_ = 0;
        MY_LOG_IF(fgLogEn,"[%s][total_RA_num_frames_<= 0]Set total_RA_num_frames_(%d)", __FUNCTION__,total_RA_num_frames_);
    }
    if (total_ISO_num_frames_ < 0) {
        total_ISO_num_frames_ = 0;
        MY_LOG_IF(fgLogEn,"[%s][total_ISO_num_frames_<= 0]Set total_ISO_num_frames_(%d)", __FUNCTION__,total_ISO_num_frames_);
    }

    bool isSensorOrModeSwitch =
        (sensorid != preSensorId) || (rLSCInfo.SensorMode != preSensorMode);
    bool isHwTypeSwitch = (rLSCInfo.lscHwType != preLscHwType);
    bool isPass2 = (rLSCInfo.lscHwType == LSC_HW_P2);
    bool isInit = (isSensorOrModeSwitch || isHwTypeSwitch || isPass2);
    bool isAIshutter = false; // (rLSCInfo.eApp == Comm_EApp_MTK_AI_SHUTTER);
    bool isFlashCapture = (rLSCInfo.isFlash == 1 && isPass2);
    MY_LOG_IF(true,
        "[%s] sensorid(%d), preSensorId(%d), rLSCInfo.SensorMode(%d), "
        "preSensorMode(%d), isSensorOrModeSwitch(%d), preLscHwType(%d), "
        "isHwTypeSwitch(%d), "
        "isPass2(%d), isInit(%d), i4Scenario(%d), eApp(%d), isAIshutter(%d), "
        "isFlashCapture(%d)",
        __FUNCTION__, sensorid, preSensorId, rLSCInfo.SensorMode,
        preSensorMode, isSensorOrModeSwitch, preLscHwType, isHwTypeSwitch,
        isPass2, isInit, i4Scenario, rLSCInfo.eApp, isAIshutter, isFlashCapture
    );

    preSensorId = sensorid;
    preSensorMode = rLSCInfo.SensorMode;
    preLscHwType = rLSCInfo.lscHwType;

    //static MINT32 ratioMapping(
    //MINT32 i4Iso, const MINT32 *iso_tbl_nvram, const MINT32 *rto_tbl_nvram, MINT32 i4Scenario,
    //MUINT32 profile, MUINT32 sensorID, MUINT32 mode, MUINT32 en_vra)

    // Get RA
    if (isFlashCapture) {
        //for flash mode, no smooth is applied
        if (sensorid == 0x0000) { // target cam
            i4Rto = ratioMapping(i4Iso, rLSCInfo.isoTbl, rLSCInfo.rtoTbl, i4Scenario,
                                 rLSCInfo.IspProfile, sensorid, rLSCInfo.SensorMode, rLSCInfo.enVRA);
            MY_LOG("[%s][Flash capture] iso(%d), force ratio(%d)", __FUNCTION__, i4Iso, i4Rto);
        } else {
            i4Rto = 32;
            MY_LOG("[%s][Flash capture] iso(%d), ratio(%d)", __FUNCTION__, i4Iso, i4Rto);
        }
    } else if(isSuperNightMode) {
        i4Rto = ratioMapping(i4Iso, rLSCInfo.isoTbl, rLSCInfo.rtoTbl, i4Scenario,
                             rLSCInfo.IspProfile, sensorid, rLSCInfo.SensorMode, rLSCInfo.enVRA);
        //for super night mode, ratio mapping is independent
        float ae_EV_Value = ((float)(rLSCInfo.i4AEComp)/(10.0));
        MY_LOG("[%s] ev in AE info is %.2f", __FUNCTION__, ae_EV_Value);
        i4Rto = ratioMappingByEV(i4Rto, ae_EV_Value, getSensorID());
        MY_LOG_IF(isSuperNightMode,"[%s][Super Night Mode]ratioMappingByEV iso(%d), ratio(%d)", __FUNCTION__,i4Iso, i4Rto);
    } else if (isPass2 && isAIshutter) {
        int idx = total_RA_num_frames_ % RA_smooth_frame;
        //Obtain previous RA and ISO
        int prev_frame = idx - 1;
        if (prev_frame < 0) prev_frame = RA_smooth_frame - 1;
        MY_LOG_IF(true, "[%s] idx(%d), prev_frame(%d), "
            "total_RA_num_frames_(%d), RA_smooth_frame(%d), "
            "RA_Buffer_[prev_frame](%d)",
            __FUNCTION__, idx, prev_frame,
            total_RA_num_frames_, RA_smooth_frame,
            RA_Buffer_[prev_frame]
        );
        return RA_Buffer_[prev_frame];
    } else {
        MINT32 RA_incremental_step_default = 2;
        if (rLSCInfo.enVRA) RA_incremental_step_default = 1;

        MINT32 RA_incremental_step =
               ::property_get_int32("debug.lsc_mgr.ratio.incre_step", RA_incremental_step_default);
        if (RA_incremental_step < 0) {
            RA_incremental_step = 0;
            MY_LOG_IF(fgLogEn, "[%s][ver20210623]RA_incremental_step<0. Set RA_incremental_step = 0\n", __FUNCTION__);
        } else if (RA_incremental_step > 32) {
            RA_incremental_step = 32;
            MY_LOG_IF(fgLogEn, "[%s][ver20210623]RA_incremental_step>32. Set RA_incremental_step = 32\n", __FUNCTION__);
        } else {
            MY_LOG_IF(fgLogEn, "[%s][ver20210623] set RA_incremental_step = %d\n", __FUNCTION__, RA_incremental_step);
        }
        ISO_init(isInit);
        RA_init(isInit);
        MINT32 avg_iso = iso_smooth(i4Iso, Avg_Frm_Cnt, MTRUE);
        MINT32 rto_tmp =
            ratioMapping(avg_iso, rLSCInfo.isoTbl, rLSCInfo.rtoTbl, i4Scenario,
                         rLSCInfo.IspProfile, sensorid, rLSCInfo.SensorMode, rLSCInfo.enVRA);
        i4Rto = RA_smooth(RA_smooth_frame, rto_tmp, RA_incremental_step, MTRUE);
    }

    return i4Rto;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/* Second parameter "feature" is ONLY used for MTKCam m-stream HDR mode mapping, (TODO: let other features can use)
 * For customization, please ignore this parameter and remove related section.
 */
MINT32
IspTuningCustom::
map_AppName_to_MappingInfo(const char* pAppname, const MINT32 feature){

    char AppName[512] = {'\0'};
    property_get("vendor.debug.appcontrol.name", AppName, "MTKCam"); //replace property here

    if (strcmp (AppName,"MTKCam") == 0)  //use adb command value if not equal to default value, else use parameter pAppname
        snprintf(AppName, sizeof(AppName), "%s", pAppname);

    if(strstr(AppName, "Facebook")){
        return EApp_Facebook;
    } else if (strstr(AppName, "Line")){
        return EApp_Line;
    } else if (strstr(AppName, "QQ")){
        return EApp_QQ;
    } else if (strstr(AppName, "Wechat")){
        return EApp_Wechat;
    } else if (strstr(AppName, "Skype")){
        return EApp_Skype;
    } else if (strstr(AppName, "Normal")){
        return EApp_Normal;
    } else if (strstr(AppName, "Professional")){
        return EApp_Professional;
    } else if (strstr(AppName, "FaceBeauty")){
        return EApp_FaceBeauty;
    } else if (strstr(AppName, "HDR")){
        return EApp_HDR;
    } else if (strstr(AppName, "Panorama")){
        return EApp_Panorama;
    } else if (strstr(AppName, "Video")){
        return EApp_Video;
    } else if (strstr(AppName, "3rd_party")){
        return EApp_3rd_party;
    }
    else{
        //+++++++++++ when pAppname is set as default("MTKCam"), check m-stream HDR on/off mode. If mode is on, set "HDR" to App.
        if (strstr(pAppname, "MTKCam") && (feature & MTK_HDR_FEATURE_HDR_HAL_MODE_MSTREAM_CAPTURE_PREVIEW) )
            return EApp_HDR;
        //+++++++++++ For customization, please remove this section.
        else
            return EApp_MTKCam;
    }
/*
    typedef enum
    {
        EApp_MTKCam,
        EApp_Facebook,
        EApp_Line,
        EApp_QQ,
        EApp_Wechat,
        EApp_Skype,
        EApp_Normal,
        EApp_Professional,
        EApp_FaceBeauty,
        EApp_HDR,
        EApp_Panorama,
        EApp_Video,
        EApp_3rd_party,
        EApp_NUM,
    } EApp_T;
*/
}



MINT32
IspTuningCustom::
map_Target_Size_to_MappingInfo(MUINT32 width, MUINT32 height, const char *pUserString){
   return ESize_SIZE_00;
}

MVOID
IspTuningCustom::
set_nvram_value(const NVRAM_CAMERA_ISP_PARAM_STRUCT* pIspParam) {
    memcpy(&m_Zoom_Env, &(pIspParam->ISPRegs.Zoom_Env), sizeof(ISP_NVRAM_ZOOM_INTERVAL_T));
}

MINT32
IspTuningCustom::
map_zoom_value_to_index(MINT32 i4ZoomRatio_x100){
    MUINT16 length = m_Zoom_Env.u2Length;

    if (length != 0){
        for(int i=0; i < length; i++){
            if(i4ZoomRatio_x100 <= m_Zoom_Env.IDX_Partition[i])
                return static_cast<EZoom_T>(i);
        }
        return static_cast<EZoom_T>(length-1);  //max
    } else
        return static_cast<EZoom_T>(0);

}


