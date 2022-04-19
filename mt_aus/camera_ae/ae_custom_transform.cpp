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

#include <string.h>
#include <cutils/log.h>
#include "ae_param.h"
#include "ae_custom_transform.h"

#define LOG_TAG "ae_custom_transform"

VOID transShutterPriority(MUINT32 u4Shutter, const VOID* const pNVRAMData, VOID* const pData)
{
    AE_NVRAM_T* pAENVRAMData = (AE_NVRAM_T*)pNVRAMData;
    strAERealSetting* pRealSetting = (strAERealSetting*)pData;
    // to do for shutter priority customization
    ALOGD("[%s +] exposure setting: %d/%d/%d, iso: %d", __FUNCTION__, pRealSetting->EvSetting.u4Eposuretime, pRealSetting->EvSetting.u4AfeGain, pRealSetting->EvSetting.u4IspGain, pRealSetting->u4ISO);
    pRealSetting->EvSetting.u4Eposuretime = u4Shutter; // temp for test
    ALOGD("[%s -] exposure setting: %d/%d/%d, iso: %d", __FUNCTION__, pRealSetting->EvSetting.u4Eposuretime, pRealSetting->EvSetting.u4AfeGain, pRealSetting->EvSetting.u4IspGain, pRealSetting->u4ISO);
}

VOID transISOPriority(MUINT32 u4ISO, const VOID* const pNVRAMData, VOID* const pData)
{
    AE_NVRAM_T* pAENVRAMData = (AE_NVRAM_T*)pNVRAMData;
    strAERealSetting* pRealSetting = (strAERealSetting*)pData;
    // to do for ISO priority customization
    ALOGD("[%s +] exposure setting: %d/%d/%d, iso: %d", __FUNCTION__, pRealSetting->EvSetting.u4Eposuretime, pRealSetting->EvSetting.u4AfeGain, pRealSetting->EvSetting.u4IspGain, pRealSetting->u4ISO);
    pRealSetting->u4ISO = u4ISO; // temp for test
    ALOGD("[%s -] exposure setting: %d/%d/%d, iso: %d", __FUNCTION__, pRealSetting->EvSetting.u4Eposuretime, pRealSetting->EvSetting.u4AfeGain, pRealSetting->EvSetting.u4IspGain, pRealSetting->u4ISO);
}

VOID transSuperNightShot(AE_CUST_Super_Night_Param_T* a_AeCustParam, const VOID* const pNVRAMData, VOID* const pData)
{
    AE_NVRAM_T* pAENVRAMData = (AE_NVRAM_T*)pNVRAMData;
    strAERealSetting* pRealSetting = (strAERealSetting*)pData;
    // to do for super night shot customization
    ALOGD("[%s +] exposure setting: %d/%d/%d, iso: %d", __FUNCTION__, pRealSetting->EvSetting.u4Eposuretime, pRealSetting->EvSetting.u4AfeGain, pRealSetting->EvSetting.u4IspGain, pRealSetting->u4ISO);
    pRealSetting->u4ISO = 1200; // temp for test
    ALOGD("[%s -] exposure setting: %d/%d/%d, iso: %d", __FUNCTION__, pRealSetting->EvSetting.u4Eposuretime, pRealSetting->EvSetting.u4AfeGain, pRealSetting->EvSetting.u4IspGain, pRealSetting->u4ISO);
}

VOID transCustomAESetting(VOID* const pCustomAESettingData)
{
    Custom_AE_Setting_Param_T* pCustomAESettingParam = (Custom_AE_Setting_Param_T *) pCustomAESettingData;
    AE_NVRAM_T* pAENVRAM = (AE_NVRAM_T *) pCustomAESettingParam->pNVRAMData;
    strAERealSetting* pAERealSetting = (strAERealSetting *) pCustomAESettingParam->pRealSetting;
    ALOGD("[%s()] u4CustomAESettingMode:%d finer_ev_idx_base:%d init_ae_idx:%d\n", __FUNCTION__, pCustomAESettingParam->u4CustomAESettingMode, pAENVRAM->flow.params.finer_ev_idx_base, pAENVRAM->flow.params.init_ae_idx);
    ALOGD("[%s +] Exp/Afe/Isp/ISO:%d/%d/%d/%d\n", __FUNCTION__, pAERealSetting->EvSetting.u4Eposuretime, pAERealSetting->EvSetting.u4AfeGain, pAERealSetting->EvSetting.u4IspGain, pAERealSetting->u4ISO);

    // to do for Custom AE Setting transformation
    // temp for test
    pAERealSetting->EvSetting.u4Eposuretime = 30000;
    pAERealSetting->EvSetting.u4AfeGain = 8192;
    pAERealSetting->EvSetting.u4IspGain = 4096;
    pAERealSetting->u4ISO = 800;

    ALOGD("[%s -] Exp/Afe/Isp/ISO:%d/%d/%d/%d\n", __FUNCTION__, pAERealSetting->EvSetting.u4Eposuretime, pAERealSetting->EvSetting.u4AfeGain, pAERealSetting->EvSetting.u4IspGain, pAERealSetting->u4ISO);
}