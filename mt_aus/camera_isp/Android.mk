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
ifeq ($(wildcard $(MTK_PATH_CUSTOM)/hal/camera_isp),)
################################################################################
#
################################################################################

LOCAL_PATH := $(call my-dir)

################################################################################
#
################################################################################
include $(CLEAR_VARS)

-include $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/aaa/aaa.mk
-include $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/drv/driver.mk

#-----------------------------------------------------------

#-----------------------------------------------------------
LOCAL_SRC_FILES += \
  $(MTK_CAM_SW_VERSION)/isp_tuning_custom.cpp \
  shading_tuning_custom.cpp \
  isp_tuning_effect.cpp \
  isp_tuning_user.cpp \
  camera_custom_msdk.cpp

#-----------------------------------------------------------
# New Nvram Architecture
LOCAL_CFLAGS += -DMTK_CAM_NEW_NVRAM_SUPPORT=1
LOCAL_CFLAGS += -DPLATFORM_$(TARGET_BOARD_PLATFORM)
#-----------------------------------------------------------
LOCAL_SHARED_LIBRARIES += liblog
LOCAL_SHARED_LIBRARIES += libaedv
LOCAL_SHARED_LIBRARIES += libutils
LOCAL_SHARED_LIBRARIES += libcutils
LOCAL_SHARED_LIBRARIES += lib3a.flash
LOCAL_SHARED_LIBRARIES += lib3a.awb.core
LOCAL_SHARED_LIBRARIES += lib3a.af.core
LOCAL_SHARED_LIBRARIES += lib3a.af.assist
LOCAL_SHARED_LIBRARIES += libcameracustom.lens
LOCAL_SHARED_LIBRARIES += libcameracustom.camera.3a
LOCAL_SHARED_LIBRARIES += libcameracustom
#LOCAL_WHOLE_STATIC_LIBRARIES += libcameracustom.imgsensor.core

LOCAL_HEADER_LIBRARIES += libutils_headers libhardware_headers libcutils_headers libcameracustom.camera.isp_headers
LOCAL_HEADER_LIBRARIES += libcam_isp_6s_p1common_headers
ifneq (,$(filter $(strip $(MTKCAM_DRV_PLATFORM)), isp_6s_v1))
LOCAL_HEADER_LIBRARIES += libcam_isp_6s_p1drv_v1_headers
else ifneq (,$(filter $(strip $(MTKCAM_DRV_PLATFORM)), isp_6s_v2))
LOCAL_HEADER_LIBRARIES += libcam_isp_6s_p1drv_v2_headers
else
LOCAL_HEADER_LIBRARIES += libcam_isp_6s_p1drv_v3_headers
endif

#-----------------------------------------------------------
LOCAL_MODULE := libcameracustom.camera.isp
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk

include $(MTK_SHARED_LIBRARY)

################################################################################
#       libcameracustom.camera.isp_headers
################################################################################
include $(CLEAR_VARS)

PLATFORM := $(MTK_PLATFORM_DIR)
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM)/hal/inc \
                    $(TOP)/$(MTK_PATH_CUSTOM)/hal/inc/isp_tuning \
                    $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/isp_tuning \
                    $(TOP)/$(MTK_PATH_CUSTOM)/hal/inc/aaa \
                    $(TOP)/$(MTK_PATH_CUSTOM)/hal/camera/inc \

LOCAL_EXPORT_C_INCLUDE_DIRS += $(MTK_PATH_SOURCE)/custom
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/aaa
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/isp_tuning/$(MTK_CAM_SW_VERSION)
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/lomo
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/lomo_jni
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/mtkcam
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/imgsensor/$(MTK_CAM_SW_VERSION)
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_COMMON)/kernel/imgsensor/inc
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_COMMON)/hal/inc/camera_feature
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_COMMON)/hal/inc
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/include
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/include/mtkcam
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/aaa/source/$(MTKCAM_AAA_PLATFORM)/isp_mgr
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/aaa/include
LOCAL_EXPORT_C_INCLUDE_DIRS += $(MTK_PATH_CUSTOM_PLATFORM)/hal/inc

LOCAL_EXPORT_C_INCLUDE_DIRS += $(MTKCAM_DRV_INCLUDE)

LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam3/include
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/common/include/metadata/
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/common/include/
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/include/mtkcam/def
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/include/algorithm/$(PLATFORM)
LOCAL_EXPORT_C_INCLUDE_DIRS += $(MTKCAM_INCLUDE_ALGO_PLATFORM)
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/system/media/camera/include
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/common/include/
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/libcamera_3a/libawb_core_lib/$(TARGET_BOARD_PLATFORM)/include

LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/external/aee/binary/inc
LOCAL_EXPORT_C_INCLUDE_DIRS += $(MTKCAM_C_INCLUDES)
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/include
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/common/include
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM)/hal/inc/aaa
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM)/hal/inc/camera_feature
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM)/hal/camera
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_COMMON)/kernel/imgsensor/inc
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM)/kernel/eeprom/inc
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM)/kernel/cam_cal/inc
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/kernel/eeprom/inc
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/kernel/cam_cal/inc
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM)/hal/inc
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/isp_tuning
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/aaa
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/$(MTK_CAM_SW_VERSION)
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/aaa/$(MTK_CAM_SW_VERSION)
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/imgsensor \
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/libcamera_3a/libawb_core_lib/$(TARGET_BOARD_PLATFORM)/include
LOCAL_EXPORT_C_INCLUDE_DIRS += $(LOCAL_PATH)/src

#-----------------------------------------------------------
LOCAL_MODULE := libcameracustom.camera.isp_headers
LOCAL_MODULE_OWNER := mtk
include $(BUILD_HEADER_LIBRARY)

endif

################################################################################
#
################################################################################
include $(CLEAR_VARS)

include $(call all-makefiles-under,$(LOCAL_PATH))
