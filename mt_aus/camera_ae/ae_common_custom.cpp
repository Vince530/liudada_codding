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

#define LOG_TAG "AE_COMMON_CUSTOM"
#include <cutils/log.h>
#include <cstdlib>
#include <cmath>

#include "camera_custom_types.h"
#include <aaa/tuning/ae_flow_custom.h>
/********************************************************************************************
 * DO NOT CHANGE!!!DO NOT CHANGE!!!DO NOT CHANGE!!!DO NOT CHANGE!!!DO NOT CHANGE!!!
 *******************************************************************************************/
#define ON       MTRUE
#define OFF      MFALSE

#ifndef ABS
    #define ABS(x)   (((x) > 0) ? (x) : (-1*(x)))
#endif
/********************************************************************************************
 * ENABLE_TOUCH_AE:
 * [ON] : Enable the touch AE
 * [OFF] : Disable the touch AE.
 *******************************************************************************************/
#define ENABLE_TOUCH_AE                     ON

/********************************************************************************************
 * ENABLE_FACE_AE:
 * [ON] : Enable the touch AE
 * [OFF] : Disable the touch AE.
 *******************************************************************************************/
#define ENABLE_FACE_AE                      ON

MBOOL CUST_ENABLE_TOUCH_AE(void)
{
    return ENABLE_TOUCH_AE;
}
MBOOL CUST_ENABLE_FACE_AE(void)
{
    return ENABLE_FACE_AE;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//===  TouchAE
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL CUST_CalcBVChange(AE_PERFRAME_INFO_T& rAEPerframeInfo,MFLOAT fChangeThl)
{
    static MINT32  nPreBVvalue=0;
    if (ABS(rAEPerframeInfo.rAEISPInfo.i4BVvalue_x10 - nPreBVvalue) > fChangeThl * 100.0) {
        ALOGD( "[%s()] BVvalue:%d PreBVvalue:%d fChangeThl:%f Change/Thres:%d/%d \n", __FUNCTION__ , rAEPerframeInfo.rAEISPInfo.i4BVvalue_x10, nPreBVvalue, fChangeThl, ABS(rAEPerframeInfo.rAEISPInfo.i4BVvalue_x10 - nPreBVvalue), fChangeThl * 100);
        return MTRUE;
    }
    nPreBVvalue = rAEPerframeInfo.rAEISPInfo.i4BVvalue_x10;
    return MFALSE;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//===
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++