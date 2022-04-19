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

/*
**
** Copyright 2008, The Android Open Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#define LOG_TAG "af_assist_flow_custom"

#include <string.h>
#include <cutils/log.h>
#include "af_assist_flow_custom.h"

#include "kd_imgsensor.h"
#include "kd_imgsensor_define.h"

#define CAM_AF_LOG(fmt, arg...)    ALOGD(LOG_TAG " " fmt, ##arg)

MBOOL is_AI_MDLA_enable(pd_CheckAIMDLAInfo condition_info)
{
    MBOOL ret = MTRUE;

    if (condition_info.frame_rate.target == 0)
    {
        condition_info.frame_rate.target = 300;
    }

    if (condition_info.iso.target == 0)
    {
        condition_info.iso.target = 3200;
    }

    if ((condition_info.iso.value <= condition_info.iso.target) && (condition_info.enableAIMDLA == 0))
    {
        ret = MFALSE;
    }
    else
    {
        if (condition_info.frame_rate.value >= condition_info.frame_rate.target)
        {
            if (condition_info.execution_count & 1)
            {
                ret = MTRUE;
            }
            else
            {
                ret = MFALSE;
            }
        }
        else
        {
            ret = MTRUE;
        }
    }

    /* use adb command to enable AI_MDLA */
    if (condition_info.enableAIMDLA)
    {
        CAM_AF_LOG("[%s] enable AIMDLA", __FUNCTION__);
    }

    return ret;
}

typedef struct
{
    MINT32 sensor_id;
    MINT32 sensor_mode;
    MINT32 vc_feature;
    MINT32 hwpipe;
    MINT32 *pdp_tuning;
} PD_SUPPORT_HWPIPE;


MINT32 imx766_preview_ne_pix_1[32] =
{
    0,           /*  0 : mqe_en */
    0,           /*  1 : mqe_mode */
    1,           /*  2 : mobc_en */
    0,           /*  3 : mobc_offst0 */
    0,           /*  4 : mobc_offst1 */
    0,           /*  5 : mobc_offst2 */
    0,           /*  6 : mobc_offst3 */
    512,         /*  7 : mobc_gain0 */
    512,         /*  8 : mobc_gain1 */
    512,         /*  9 : mobc_gain2 */
    512,         /* 10 : mobc_gain3 */
    0x10,        /* 11 : sgg_pgn */
    0x2819100A,  /* 12 : sgg_gmrc_1 */
    0x00A16640,  /* 13 : sgg_gmrc_2 */
    2,           /* 14 : mbn_pow */
    0,           /* 15 : mbn_dir */
    920,         /* 16 : cpi_th */
    2,           /* 17 : cpi_pow */
    0,           /* 18 : cpi_dir */
};

MINT32 imx766_preview_ne_pix_2[32] =
{
    0,           /*  0 : mqe_en */
    0,           /*  1 : mqe_mode */
    1,           /*  2 : mobc_en */
    0,           /*  3 : mobc_offst0 */
    0,           /*  4 : mobc_offst1 */
    0,           /*  5 : mobc_offst2 */
    0,           /*  6 : mobc_offst3 */
    512,         /*  7 : mobc_gain0 */
    512,         /*  8 : mobc_gain1 */
    512,         /*  9 : mobc_gain2 */
    512,         /* 10 : mobc_gain3 */
    0x10,        /* 11 : sgg_pgn */
    0x2819100A,  /* 12 : sgg_gmrc_1 */
    0x00A16640,  /* 13 : sgg_gmrc_2 */
    2,           /* 14 : mbn_pow */
    1,           /* 15 : mbn_dir */
    920,         /* 16 : cpi_th */
    2,           /* 17 : cpi_pow */
    1,           /* 18 : cpi_dir */
};

#define PD_SUPPORT_HWPIPE_LIST 32

static PD_SUPPORT_HWPIPE pd_support_hwpipe[PD_SUPPORT_HWPIPE_LIST] =
{
    // {0x0766/*IMX766_SENSOR_ID*/, MSDK_SCENARIO_ID_CAMERA_PREVIEW,      VC_PDAF_STATS_NE_PIX_1, PD_USE_PDP, imx766_preview_ne_pix_1},
    // {0x0766/*IMX766_SENSOR_ID*/, MSDK_SCENARIO_ID_CAMERA_PREVIEW,      VC_PDAF_STATS_NE_PIX_2, PD_USE_PDP, imx766_preview_ne_pix_2},
    // {0x0766/*IMX766_SENSOR_ID*/, MSDK_SCENARIO_ID_VIDEO_PREVIEW,       VC_PDAF_STATS_NE_PIX_2, PD_USE_PDP, imx766_preview_ne_pix_2},
};

MBOOL is_PDP_support(MINT32 sensor_id, MINT32 sensor_mode)
{
    MBOOL ret = MFALSE;

    for (MINT32 i = 0; i < PD_SUPPORT_HWPIPE_LIST; i++)
    {
        if (sensor_id == pd_support_hwpipe[i].sensor_id &&
            sensor_mode == pd_support_hwpipe[i].sensor_mode &&
            PD_USE_PDP == pd_support_hwpipe[i].hwpipe)
        {
            ret = MTRUE;
            break;
        }

        if (pd_support_hwpipe[i].sensor_id == 0)
            break;
    }

    CAM_AF_LOG("[%s] sensor id(0x%x), sensor mode(%d), ret(%d)", __FUNCTION__, sensor_id, sensor_mode, ret);

    return ret;
}

MINT32 query_PD_hwpipe(MINT32 sensor_id, MINT32 sensor_mode, MINT32 vc_feature, MINT32 vc_datetype, MINT32 *o_pdp_tuning)
{
    MINT32 hwpipe = PD_NOT_DEFINED;

    for (MINT32 i = 0; i < PD_SUPPORT_HWPIPE_LIST; i++)
    {
        if (sensor_id == pd_support_hwpipe[i].sensor_id &&
            sensor_mode == pd_support_hwpipe[i].sensor_mode &&
            vc_feature == pd_support_hwpipe[i].vc_feature &&
            vc_datetype == 0x2B)
        {
            hwpipe = pd_support_hwpipe[i].hwpipe;
            if (o_pdp_tuning)
                memcpy(o_pdp_tuning, pd_support_hwpipe[i].pdp_tuning, sizeof(MINT32) * 32);
            break;
        }

        if (pd_support_hwpipe[i].sensor_id == 0)
            break;
    }

    CAM_AF_LOG("[%s] sensor id(0x%x), sensor mode(%d), vc_feature(%d), vc_datetype(0x%x), hwpipe(%d)",
                __FUNCTION__, sensor_id, sensor_mode, vc_feature, vc_datetype, hwpipe);

    return hwpipe;
}