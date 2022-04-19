# Copyright Statement:
#
# This software/firmware and related documentation ("MediaTek Software") are
# protected under relevant copyright laws. The information contained herein
# is confidential and proprietary to MediaTek Inc. and/or its licensors.
# Without the prior written permission of MediaTek inc. and/or its licensors,
# any reproduction, modification, use or disclosure of MediaTek Software,
# and information contained herein, in whole or in part, shall be strictly prohibited.

# MediaTek Inc. (C) 2010. All rights reserved.
#
# BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
# THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
# RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
# AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
# NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
# SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
# SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
# THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
# THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
# CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
# SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
# STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
# CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
# AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
# OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
# MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
# The following software/firmware and/or related documentation ("MediaTek Software")
# have been modified by MediaTek Inc. All revisions are subject to any receiver's
# applicable license agreements with MediaTek Inc.

# Use project first
ifeq ($(wildcard $(MTK_PATH_CUSTOM)/hal/camera_awb),)

################################################################################
#
################################################################################

LOCAL_PATH := $(call my-dir)

################################################################################
#
################################################################################
include $(CLEAR_VARS)

#-----------------------------------------------------------
LOCAL_SRC_FILES += \
  awb_tuning_custom.cpp \
  awb_tuning_custom_imx338.cpp \
  awb_tuning_custom_main.cpp \
  awb_tuning_custom_main2.cpp \
  awb_tuning_custom_sub.cpp \
  awb_tuning_custom_sub2.cpp \
  flashawb_tuning_custom.cpp \
  sensor_awb.cpp \
  awb_common_custom.cpp
 
LOCAL_HEADER_LIBRARIES += libutils_headers libhardware_headers libcutils_headers libcamera.customawb_headers

LOCAL_SHARED_LIBRARIES += liblog
LOCAL_SHARED_LIBRARIES += libcutils
LOCAL_SHARED_LIBRARIES += libutils
#--------------------------------------------------------------------------
LOCAL_SHARED_LIBRARIES += lib3a.awb.core
#-----------------------------------------------------------
LOCAL_CFLAGS +=

LOCAL_MODULE := libcamera.customawb
LOCAL_MODULE_OWNER := mtk
LOCAL_PROPRIETARY_MODULE := true

#-----------------------------------------------------------
include $(MTK_SHARED_LIBRARY)

################################################################################
#       libcamera.customawb_headers
################################################################################
include $(CLEAR_VARS)

#-----------------------------------------------------------

LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/include
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_COMMON)/hal/inc/camera_feature
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_COMMON)/hal/inc
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/include
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/include/mtkcam
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/aaa/source/$(MTKCAM_AAA_PLATFORM)/isp_mgr
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/aaa/include
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/aaa
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/isp_tuning/$(MTK_CAM_SW_VERSION)
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/mtkcam
LOCAL_EXPORT_C_INCLUDE_DIRS += \
  $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc \
  $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/isp_tuning \
  $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/aaa \
  $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/camera/inc \
  $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/imgsensor_src \
  $(TOP)/$(MTK_PATH_COMMON)/hal/imgsensor_src

#-----------------------------------------------------------
LOCAL_MODULE := libcamera.customawb_headers
LOCAL_MODULE_OWNER := mtk
include $(BUILD_HEADER_LIBRARY)

################################################################################
#
################################################################################
#include $(CLEAR_VARS)
#include $(call all-makefiles-under,$(LOCAL_PATH))

endif
