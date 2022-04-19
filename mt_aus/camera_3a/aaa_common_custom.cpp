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

#define LOG_TAG "aaa_common_custom.cpp"
#include <cutils/log.h>
#include <cstdlib>
#include <cmath>

#include "camera_custom_types.h"
#include "aaa_common_custom.h"
#include "aaa_log.h"

/********************************************************************************************
 * DO NOT CHANGE!!!DO NOT CHANGE!!!DO NOT CHANGE!!!DO NOT CHANGE!!!DO NOT CHANGE!!!
 *******************************************************************************************/
#define ON       MTRUE
#define OFF      MFALSE


/********************************************************************************************
 ********************************************************************************************
 ****************************** Customize 3A options below **********************************
 ********************************************************************************************
 *******************************************************************************************/

/********************************************************************************************
 * LOCK_AE_DURING_CAF:
 * [ON]: Lock AE when doing CAF(conti' AF)
 * [OFF]: AE can work when doing CAF
 *******************************************************************************************/
#define LOCK_AE_DURING_CAF                  ON

/********************************************************************************************
 * ENABLE_VIDEO_DYNAMIC_FRAME_RATE:
 * [ON] : Enable the video dynamic frame rate
 * [OFF] : Disable the video dynamic frame rate.
 *******************************************************************************************/
#define ENABLE_VIDEO_DYNAMIC_FRAME_RATE ON

/********************************************************************************************
 * ENABLE_FLASH_DURING_TOUCH:
 * [ON] : Enable FlashTask during touch.
 * [OFF] : Disable FlashTask during touch.
 *******************************************************************************************/
 #ifdef MOT_3A_FIX
#define ENABLE_FLASH_DURING_TOUCH OFF
#else
#define ENABLE_FLASH_DURING_TOUCH ON
#endif

/********************************************************************************************
 * SYNC3A_AESTABLE_MAGIC:
 *******************************************************************************************/
#define SYNC3A_AESTABLE_MAGIC 15

/********************************************************************************************
 * SKIP_PRECAP_FLASH_FRAME_COUNT:
 * The count for skip flash calculation
 *******************************************************************************************/
#define SKIP_PRECAP_FLASH_FRAME_COUNT 12

/********************************************************************************************
 * SENSOR_S5K3L6_LONG_EXP_THRES:
 *******************************************************************************************/
#define SENSOR_LONG_EXP_THRES 668437000 // S5K3L6 THRES

/********************************************************************************************
 * IS_SPECIAL_LONG_EXP_ON:
 * g_bIsSpecialLongExpOn:
 * [ON] : Enable Special LongExp flow.
 * [OFF] : Disable Special LongExp flow.
 * g_i4IsSpecialLongExpEffectiveFrame:
 * [0] : sensor not implement
 * [1] : N+1 Effective frame
 * [2] : N+2 Effective frame
 *******************************************************************************************/
static MBOOL g_bIsSpecialLongExpOn = MFALSE;
static MINT32 g_i4IsSpecialLongExpEffectiveFrame = 0;

MBOOL CUST_LOCK_AE_DURING_CAF(void)
{
    return LOCK_AE_DURING_CAF;
}

MBOOL CUST_ENABLE_VIDEO_DYNAMIC_FRAME_RATE(void)
{
    return ENABLE_VIDEO_DYNAMIC_FRAME_RATE;
}

MBOOL CUST_ENABLE_FLASH_DURING_TOUCH(void)
{
    return ENABLE_FLASH_DURING_TOUCH;
}

std::vector<int> getShortExpFrame(void)
{
    std::vector<int> ExpFrame = {1, 1, 1, -1}; // 0: Skipped frame, 1: Short Exposure frame, the fourth is to prevent segmentation fault

    return ExpFrame;
}

MUINT32 CUST_GET_SYNC3A_AESTABLE_MAGIC(void)
{
    return SYNC3A_AESTABLE_MAGIC;
}

MINT32 CUST_GET_SKIP_PRECAP_FLASH_FRAME_COUNT(void)
{
    return SKIP_PRECAP_FLASH_FRAME_COUNT;
}

void cust_initSpecialLongExpOnOff(const MINT32 &i4AEEffectiveFrame)
{
    g_bIsSpecialLongExpOn = 0;
    g_i4IsSpecialLongExpEffectiveFrame = i4AEEffectiveFrame;
    ALOGI("[%s] g_bIsSpecialLongExpOn(%d) AEEffectiveFrame(%d)", __FUNCTION__, g_bIsSpecialLongExpOn, g_i4IsSpecialLongExpEffectiveFrame);
}

void cust_setSpecialLongExpOnOff(const MINT64 &i8ExposureTime)
{
    MINT64 i8LongExpThres = 0;
    switch(g_i4IsSpecialLongExpEffectiveFrame){
        case 1:
            i8LongExpThres = static_cast<MINT64>(SENSOR_LONG_EXP_THRES);
            break;
        case 2:
        case 0:
        default:
            return;
    }
    MBOOL bIsLongExpOn = (i8ExposureTime > i8LongExpThres) ? 1: 0;
    AAA_LOGI_IF(g_bIsSpecialLongExpOn != bIsLongExpOn, "[%s] AEEffectiveFrame(%d), i8ExposureTime(%ld), i8LongExpThres(%ld), Long Exposure OnOff(%d)", __FUNCTION__, g_i4IsSpecialLongExpEffectiveFrame, i8ExposureTime, i8LongExpThres, g_bIsSpecialLongExpOn);
    if(g_bIsSpecialLongExpOn != bIsLongExpOn)
    {
        g_bIsSpecialLongExpOn = bIsLongExpOn;
    }
}

MBOOL cust_getIsSpecialLongExpOn()
{
    return g_bIsSpecialLongExpOn;
}

MBOOL CUST_LENS_COVER_COUNT(MINT32 i4LvMaster, MINT32 i4LvSlave)
{
    static MINT32 consecutive = 0;

    if (std::abs(i4LvMaster - i4LvSlave) > 50)   consecutive++;
    else    consecutive = 0;

    return consecutive > 2;
}
