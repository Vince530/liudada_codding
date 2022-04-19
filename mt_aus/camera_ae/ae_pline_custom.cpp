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

#include "ae_pline_custom.h"
#include <string.h>
#include <utils/Errors.h>
#include <cutils/log.h>
#include <fcntl.h>
#include <cutils/properties.h>
#include <stdlib.h>


#define LOG_TAG "ae_pline_custom"
#define CustomModifyFourCell
#define CustomModifyGetExpo 1

void getAEManualPline(const ManualPlineParam& manualPlineParam, eAETableID& a_AEManualPreTableID, eAETableID& a_AEManualCapTableID)
{
    if ((manualPlineParam.MinFps == LIB3A_AE_FRAMERATE_MODE_30FPS) && (manualPlineParam.MaxFps == LIB3A_AE_FRAMERATE_MODE_30FPS)){ // fix 15 fps
        a_AEManualPreTableID = AETABLE_SCENE_INDEX22;
        a_AEManualCapTableID = AETABLE_SCENE_INDEX22;
    } else if ((manualPlineParam.MinFps == LIB3A_AE_FRAMERATE_MODE_15FPS) && (manualPlineParam.MaxFps == LIB3A_AE_FRAMERATE_MODE_15FPS)){ // fix 30 fps
        a_AEManualPreTableID = AETABLE_SCENE_INDEX14;
        a_AEManualCapTableID = AETABLE_SCENE_INDEX14;
    } else if ((manualPlineParam.MinFps == 240) && (manualPlineParam.MaxFps == 240)){ // fix 24 fps
        a_AEManualPreTableID = AETABLE_SCENE_INDEX4;
        a_AEManualCapTableID = AETABLE_SCENE_INDEX4;
    } else if (manualPlineParam.SensorMode == 2){ // sensor mode: video
        a_AEManualPreTableID = AETABLE_VIDEO1_AUTO;
        a_AEManualCapTableID = AETABLE_VIDEO1_AUTO;
    } else if (manualPlineParam.SceneMode == LIB3A_AE_SCENE_SNOW){ // scene mode: snow
        a_AEManualPreTableID = AETABLE_VIDEO_NIGHT;
        a_AEManualCapTableID = AETABLE_VIDEO_NIGHT;
    } else if (manualPlineParam.ISOSpeed == 150){ // ISO speed: 150
        a_AEManualPreTableID = AETABLE_CAPTURE_ISO100;
        a_AEManualCapTableID = AETABLE_CAPTURE_ISO100;
    }
    else {
        ALOGD("[%s] no manual pline matching, MinFps/MaxFps/SensorMode/SceneMode/ISOSpeed: %d/%d/%d/%d/%d\n", __FUNCTION__,
              manualPlineParam.MinFps, manualPlineParam.MaxFps, manualPlineParam.SensorMode, manualPlineParam.SceneMode, manualPlineParam.ISOSpeed);
        return;
    }
    ALOGD("[%s] a_AEManualPreTableID/a_AEManualCapTableID:%d/%d, MinFps/MaxFps/SensorMode/SceneMode/ISOSpeed: %d/%d/%d/%d/%d\n", __FUNCTION__, a_AEManualPreTableID, a_AEManualCapTableID,
          manualPlineParam.MinFps, manualPlineParam.MaxFps, manualPlineParam.SensorMode, manualPlineParam.SceneMode, manualPlineParam.ISOSpeed);
}

void getAEManualPline(const EAEManualPline_T& e_AEManualPline, eAETableID& a_AEManualPreTableID, eAETableID& a_AEManualCapTableID)
{
    char value[PROPERTY_VALUE_MAX] = {'\0'};
    switch(e_AEManualPline) {
        case EAEManualPline_EISRecord1:
            a_AEManualPreTableID = AETABLE_SCENE_INDEX9;
            a_AEManualCapTableID = AETABLE_SCENE_INDEX9;
            break;
        case EAEManualPline_EISRecord2:
            a_AEManualPreTableID = AETABLE_SCENE_INDEX8;
            a_AEManualCapTableID = AETABLE_SCENE_INDEX8;
            break;
        case EAEManualPline_SM120FPS:
            a_AEManualPreTableID = AETABLE_HIGH_FPS_120;
            a_AEManualCapTableID = AETABLE_HIGH_FPS_120;
            break;
        case EAEManualPline_SM240FPS:
            a_AEManualPreTableID = AETABLE_HIGH_FPS_240;
            a_AEManualCapTableID = AETABLE_HIGH_FPS_240;
            break;
        case EAEManualPline_SM480FPS:
            a_AEManualPreTableID = AETABLE_HIGH_FPS_480;
            a_AEManualCapTableID = AETABLE_HIGH_FPS_480;
            break;
        case EAEManualPline_AIS1Capture:
        case EAEManualPline_AIS2Capture:
            a_AEManualPreTableID = AETABLE_SCENE_INDEX14;
            a_AEManualCapTableID = AETABLE_SCENE_INDEX14;
            break;
        case EAEManualPline_MFHRCapture:
            a_AEManualPreTableID = AETABLE_SCENE_INDEX19;
            a_AEManualCapTableID = AETABLE_SCENE_INDEX19;
            break;
        case EAEManualPline_BMDNCapture:
            a_AEManualPreTableID = AETABLE_SCENE_INDEX20;
            a_AEManualCapTableID = AETABLE_SCENE_INDEX20;
            break;
        case EAEManualPline_ShtterISOPriority:
            a_AEManualPreTableID = AETABLE_SCENE_INDEX16;
            a_AEManualCapTableID = AETABLE_SCENE_INDEX16;
            break;
        case EAEManualPline_MStreamVhdr:
        case EAEManualPline_StaggerVhdr:
            a_AEManualPreTableID = AETABLE_VIDEO_VHDR;
            a_AEManualCapTableID = AETABLE_VIDEO_VHDR;
            break;
        case EAEManualPline_Vhdr60FPS:
            a_AEManualPreTableID = AETABLE_VIDEO_VHDR;
            a_AEManualCapTableID = AETABLE_VIDEO_VHDR;
            break;
        case EAEManualPline_Video:
            a_AEManualPreTableID = AETABLE_VIDEO_AUTO;
            a_AEManualCapTableID = AETABLE_VIDEO_AUTO;
            break;
        case EAEManualPline_Video60FPS:
            a_AEManualPreTableID = AETABLE_VIDEO_VHDR;
            a_AEManualCapTableID = AETABLE_VIDEO_VHDR;
            break;
        case EAEManualPline_ADBCtrol:
            property_get("vendor.debug.ae_pline.preview", value, "0");
            a_AEManualPreTableID = static_cast<eAETableID>(atoi(value));
            property_get("vendor.debug.ae_pline.capture", value, "0");
            a_AEManualCapTableID = static_cast<eAETableID>(atoi(value));
            ALOGD( "[%s()] ADB assigns P-lineID manually: %d/%d \n", __FUNCTION__, a_AEManualPreTableID, a_AEManualCapTableID);
            return;
        case EAEManualPline_Custom6:
            a_AEManualPreTableID = AETABLE_RPEVIEW_AUTO;
            a_AEManualCapTableID = AETABLE_RPEVIEW_AUTO;
            break;
        case EAEManualPline_Custom7:
            a_AEManualPreTableID = AETABLE_RPEVIEW_AUTO;
            a_AEManualCapTableID = AETABLE_RPEVIEW_AUTO;
            break;
        case EAEManualPline_Custom8:
            a_AEManualPreTableID = AETABLE_RPEVIEW_AUTO;
            a_AEManualCapTableID = AETABLE_RPEVIEW_AUTO;
            break;
        case EAEManualPline_Custom9:
            a_AEManualPreTableID = AETABLE_RPEVIEW_AUTO;
            a_AEManualCapTableID = AETABLE_RPEVIEW_AUTO;
            break;
        case EAEManualPline_Custom10:
            a_AEManualPreTableID = AETABLE_RPEVIEW_AUTO;
            a_AEManualCapTableID = AETABLE_RPEVIEW_AUTO;
            break;
        case EAEManualPline_Custom11:
            a_AEManualPreTableID = AETABLE_RPEVIEW_AUTO;
            a_AEManualCapTableID = AETABLE_RPEVIEW_AUTO;
            break;
        case EAEManualPline_Custom12:
            a_AEManualPreTableID = AETABLE_RPEVIEW_AUTO;
            a_AEManualCapTableID = AETABLE_RPEVIEW_AUTO;
            break;
        case EAEManualPline_Custom13:
            a_AEManualPreTableID = AETABLE_RPEVIEW_AUTO;
            a_AEManualCapTableID = AETABLE_RPEVIEW_AUTO;
            break;
        case EAEManualPline_Custom14:
            a_AEManualPreTableID = AETABLE_RPEVIEW_AUTO;
            a_AEManualCapTableID = AETABLE_RPEVIEW_AUTO;
            break;
        case EAEManualPline_Custom15:
            a_AEManualPreTableID = AETABLE_RPEVIEW_AUTO;
            a_AEManualCapTableID = AETABLE_RPEVIEW_AUTO;
            break;
        case EAEManualPline_Default:
        default:
            ALOGD("[%s] The EAEManualPline_T enum value is default or incorrect:%d\n", __FUNCTION__, e_AEManualPline);
            return;
    }
    ALOGD("[%s] e_AEManualPline:%d, a_AEManualPreTableID/a_AEManualCapTableID:%d/%d\n", __FUNCTION__, e_AEManualPline, a_AEManualPreTableID, a_AEManualCapTableID);
}

void getAEManualCapPline(const EAEManualPline_T& e_AEManualPline, eAETableID& a_AEManualTableID)
{
    switch(e_AEManualPline) {
        case EAEManualPline_AIS1Capture:
        case EAEManualPline_AIS2Capture:
            a_AEManualTableID = AETABLE_SCENE_INDEX14;
            break;
        case EAEManualPline_MFHRCapture:
            a_AEManualTableID = AETABLE_SCENE_INDEX19;
            break;
        case EAEManualPline_BMDNCapture:
            a_AEManualTableID = AETABLE_SCENE_INDEX20;
            break;
        case EAEManualPline_MStreamVhdr:
        case EAEManualPline_StaggerVhdr:
            a_AEManualTableID = AETABLE_VIDEO_VHDR;
            break;
        case EAEManualPline_Vhdr60FPS:
            a_AEManualTableID = AETABLE_SCENE_INDEX17;
            break;
        case EAEManualPline_Default:
        default:
            ALOGD("[%s] The EAEManualPline_T enum value is default or incorrect:%d\n", __FUNCTION__, e_AEManualPline);
            return;
    }
    ALOGD("[%s] e_AEManualPline:%d, a_AEManualTableID:%d\n", __FUNCTION__, e_AEManualPline, a_AEManualTableID);
}

void decideAEManualPline(const ManualPlineDecisionSetting& setting, EAEManualPline_T& AEManualPline, MBOOL& needCheckAEPline){

    /* decide manual P-line by related setting */
    /*
    priority of decision (tentative):
    1. slow motion 
    2. target modes
    3. EIS
    4. shutter/iso priority
    5. custom sensor mode
    */
    EAEManualPline_T oldAEManualPline = AEManualPline;

    AEManualPline = EAEManualPline_Default;

    /************ ************/
    if(setting.sensorMode >= 10){
        switch(setting.sensorMode){
            case 10:
                AEManualPline = EAEManualPline_Custom6;
                break;
            case 11:
                AEManualPline = EAEManualPline_Custom7;
                break;
            case 12:
                AEManualPline = EAEManualPline_Custom8;
                break;
            case 13:
                AEManualPline = EAEManualPline_Custom9;
                break;
            case 14:
                AEManualPline = EAEManualPline_Custom10;
                break;
            case 15:
                AEManualPline = EAEManualPline_Custom11;
                break;
            case 16:
                AEManualPline = EAEManualPline_Custom12;
                break;
            case 17:
                AEManualPline = EAEManualPline_Custom13;
                break;
            case 18:
                AEManualPline = EAEManualPline_Custom14;
                break;
            case 19:
                AEManualPline = EAEManualPline_Custom15;
                break;
            default:
                ALOGD("[%s] E_AE_UNSUPPORT_SENSOR_MODE: %d\n", __FUNCTION__, setting.sensorMode);
                break;
        }
    }
    /************ ************/
        // ALOGD("[%s] EIS\n", __FUNCTION__);
    switch(setting.enEISRecording){
            case 1:
                AEManualPline = EAEManualPline_EISRecord1;
                break;
            case 2:
                AEManualPline = EAEManualPline_EISRecord2;
                break;
    }
    /************ ************/
    if(setting.AETargetMode==AE_MODE_NORMAL){
        if(setting.validExpNum == 1) // stagger reconfig to real one exp
            AEManualPline = EAEManualPline_Video;
        else if(setting.minFps==setting.maxFps && setting.maxFps==LIB3A_AE_FRAMERATE_MODE_60FPS)
            AEManualPline = EAEManualPline_Video60FPS;
    }else if(setting.AETargetMode==AE_MODE_MSTREAM_VHDR_RTO1X_TARGET){
        if((setting.APPMode == LIB3A_AE_APP_MODE_VIDEO_PREVIEW) || (setting.APPMode == LIB3A_AE_APP_MODE_VIDEO_RECORD))
                     AEManualPline = EAEManualPline_Video; // target mode == AE_MODE_MSTREAM_VHDR_RTO1X_TARGET, APPMode == video
    }else if(setting.AETargetMode==AE_MODE_MSTREAM_VHDR_TARGET){
        AEManualPline = EAEManualPline_MStreamVhdr;
    }else if(setting.AETargetMode==AE_MODE_STAGGER_2EXP_TARGET){
        // todo pline mapping, include ISO reconfig
        if (setting.validExpNum == 1)
        {
            // ISO reconfig
            AEManualPline = EAEManualPline_Video;
        }
        else // m_i4ValidExpNum == 2
        {
            // stagger normal 2-Exp mode
            AEManualPline = EAEManualPline_StaggerVhdr;
        }
    }else if(setting.AETargetMode == AE_MODE_STAGGER_3EXP_TARGET){ // stagger 3-Exp mode
        // todo pline mapping, include ISO reconfig
        if (setting.validExpNum == 1)
        {
            // ISO reconfig 1-Exp
            AEManualPline = EAEManualPline_Video;
        }
        else if(setting.validExpNum == 2)
        {
            // ISO reconfig 2-Exp
            AEManualPline = EAEManualPline_StaggerVhdr;
        }
        else // m_i4ValidExpNum == 3
        {
            // stagger normal 3-Exp mode
            AEManualPline = EAEManualPline_StaggerVhdr;
        }
    }
    /************ ************/
    if(setting.enSlowMotionBuffMode){
        // ALOGD("[%s] slow motion buffer mode\n", __FUNCTION__);
        switch(setting.slowMotionSubsamples){
            case 4:
                AEManualPline = EAEManualPline_SM120FPS;
                break;
            case 8:
                AEManualPline = EAEManualPline_SM240FPS;
                break;
            case 16:
                AEManualPline = EAEManualPline_SM480FPS;
                break;
            default:
                AEManualPline = EAEManualPline_Default;
                break;
        }
    }
    /************ ************/
    if(setting.shutterISOPriorityMode || setting.internalISOPriorityMode){
        // ALOGD("[%s] shutter/ISO priority\n", __FUNCTION__);
        AEManualPline = EAEManualPline_ShtterISOPriority;
    }
    /************ ************/
    if (AEManualPline != oldAEManualPline){
      needCheckAEPline = MTRUE;
      ALOGD("[%s -] AE manual Pline: %d -> %d\n", __FUNCTION__, oldAEManualPline, AEManualPline);
    }
}
