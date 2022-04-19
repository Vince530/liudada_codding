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

#include "camera_custom_types.h"
#include "camera_custom_nvram.h"
#include <aaa_types.h>
#include "awb_tuning_custom.h"
#include <cutils/log.h>

using namespace NSIspTuning;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// AWB Param Mapping Table by Scenario, Sensor ID, Module ID and Lens ID
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
AWB_CUST_PARAM_T const& getAWBModuleParamData(CAM_SCENARIO_T eCamScenario, MINT32 i4SensorDevID, MINT32 i4ModuleID, MINT32 i4LensID)
{
    ALOGD("[%s] CamScenario:%d SensorID:0x%0X ModuleID:0x%0X LensID:0x%0X\n", __FUNCTION__, eCamScenario, i4SensorDevID, i4ModuleID, i4LensID);
    //TBD add scenario ID, module ID and Lens ID check    
    switch(i4SensorDevID) {        
        case IMX338_SENSOR_ID:
            switch(eCamScenario) {
                default:
                case CAM_SCENARIO_PREVIEW:
                    return getCustomAWBParamData<IMX338_SENSOR_ID, CAMERA_MODULE_ID, CAMERA_LENS_ID, CAM_SCENARIO_PREVIEW>();
                case CAM_SCENARIO_VIDEO:
                    return getCustomAWBParamData<IMX338_SENSOR_ID, CAMERA_MODULE_ID, CAMERA_LENS_ID, CAM_SCENARIO_VIDEO>();
                case CAM_SCENARIO_CAPTURE:
                    return getCustomAWBParamData<IMX338_SENSOR_ID, CAMERA_MODULE_ID, CAMERA_LENS_ID, CAM_SCENARIO_CAPTURE>();
                case CAM_SCENARIO_CUSTOM1:
                    return getCustomAWBParamData<IMX338_SENSOR_ID, CAMERA_MODULE_ID, CAMERA_LENS_ID, CAM_SCENARIO_CUSTOM1>();
                case CAM_SCENARIO_CUSTOM2:
                    return getCustomAWBParamData<IMX338_SENSOR_ID, CAMERA_MODULE_ID, CAMERA_LENS_ID, CAM_SCENARIO_CUSTOM2>();
                case CAM_SCENARIO_CUSTOM3:
                    return getCustomAWBParamData<IMX338_SENSOR_ID, CAMERA_MODULE_ID, CAMERA_LENS_ID, CAM_SCENARIO_CUSTOM3>();
                case CAM_SCENARIO_CUSTOM4:
                    return getCustomAWBParamData<IMX338_SENSOR_ID, CAMERA_MODULE_ID, CAMERA_LENS_ID, CAM_SCENARIO_CUSTOM4>();
            }
        default:
            ALOGD("[%s] No mapping Custom AWB Param, Using IMX398 default\n", __FUNCTION__);
            return getCustomAWBParamData<IMX338_SENSOR_ID, CAMERA_MODULE_ID, CAMERA_LENS_ID, CAM_SCENARIO_PREVIEW>();
    }
}

