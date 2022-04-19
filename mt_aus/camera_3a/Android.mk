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

ifeq ($(wildcard $(MTK_PATH_CUSTOM)/hal/camera_3a),)
################################################################################
#
################################################################################

LOCAL_PATH := $(call my-dir)
##############################################
include $(CLEAR_VARS)
#------------------------------------------
ifeq ($(wildcard $(MTK_PATH_CUSTOM)/hal/camera_3a),)
LOCAL_EXPORT_C_INCLUDE_DIRS += $(LOCAL_INTERMEDIATES)
endif
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/aaa
#------------------------------------------
LOCAL_MODULE := headerlib_202007021431224
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk
#------------------------------------------
include $(BUILD_HEADER_LIBRARY)
##############################################

################################################################################
#
################################################################################
include $(CLEAR_VARS)

-include $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/aaa/aaa.mk
-include $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/drv/driver.mk

#-----------------------------------------------------------
#$(call config-custom-folder,hal:hal)

#-----------------------------------------------------------
LOCAL_SRC_FILES += \
  aaa_common_custom.cpp \
  camera_custom_if.cpp \
  camera_custom_if_yuv.cpp \
  aaa_yuv_tuning_custom.cpp \
  n3d_sync2a_tuning_param.cpp 

#-------------------------------------------------------------------------------
# If sensor list contains IMX377, set ISO support mode to 12800 to main camera
#-------------------------------------------------------------------------------
ifneq (,$(findstring imx377_mipi_raw,$(CUSTOM_HAL_IMGSENSOR)))
LOCAL_CFLAGS += -DISO_TOP_SUPPORT_MODE_main=2
endif

# for Stereo Feature
ifeq ($(MTK_CAM_STEREO_CAMERA_SUPPORT),yes)
LOCAL_CFLAGS += -DCAM3_STEREO_FEATURE_EN=1
endif

#-----------------------------------------------------------
# New Nvram Architecture
LOCAL_CFLAGS += -DMTK_CAM_NEW_NVRAM_SUPPORT=1
#-----------------------------------------------------------
LOCAL_SHARED_LIBRARIES += liblog
LOCAL_SHARED_LIBRARIES += libcam.hal3a.log
LOCAL_SHARED_LIBRARIES += lib3a.flash
LOCAL_SHARED_LIBRARIES += lib3a.awb.core
LOCAL_SHARED_LIBRARIES += lib3a.af.core
LOCAL_SHARED_LIBRARIES += lib3a.af.assist
LOCAL_SHARED_LIBRARIES += lib3a.lce
LOCAL_SHARED_LIBRARIES += lib3a.gma
LOCAL_SHARED_LIBRARIES += lib3a.dce
#For AE
LOCAL_SHARED_LIBRARIES += lib3a.ae
LOCAL_SHARED_LIBRARIES += lib3a.ae.core
LOCAL_WHOLE_STATIC_LIBRARIES +=
LOCAL_HEADER_LIBRARIES += libutils_headers libhardware_headers libcutils_headers libcameracustom.camera.3a_headers
#-----------------------------------------------------------
#------------------------------------------
LOCAL_HEADER_LIBRARIES += headerlib_202007021431224
#------------------------------------------
LOCAL_MODULE := libcameracustom.camera.3a
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk
#-----------------------------------------------------------
LOCAL_INTERMEDIATES         := $(call local-intermediates-dir)
LOCAL_INTERMEDIATES_TEMPLATE_HEADER := $(LOCAL_INTERMEDIATES)/all_headers.h
ATMs_TEMPLATE_HEADER := $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/imgsensor/ver1/Default

FILES := $(shell find $(ATMs_TEMPLATE_HEADER) -name "*.h" -maxdepth 1 | sed -r 's/^.+\///')

$(shell mkdir -p $(LOCAL_INTERMEDIATES))
$(shell for i in $(FILES);do rm -f $(LOCAL_INTERMEDIATES)/template_"$$i";done)
$(LOCAL_INTERMEDIATES_TEMPLATE_HEADER):\
	$(shell for i in $(FILES);do sed 's/%04d/template/g; s/@region_start/ /g; s/@region_end/ /g' $(ATMs_TEMPLATE_HEADER)/"$$i"| tee $(LOCAL_INTERMEDIATES)/template_"$$i";done)

$(shell rm -f $(LOCAL_INTERMEDIATES_TEMPLATE_HEADER))
$(LOCAL_INTERMEDIATES_TEMPLATE_HEADER):\
	$(shell for i in $(FILES);do echo "#include <"template_$$i">" >>$(LOCAL_INTERMEDIATES_TEMPLATE_HEADER);done)

LOCAL_GENERATED_SOURCES += $(LOCAL_INTERMEDIATES_TEMPLATE_HEADER)
#-----------------------------------------------------------
include $(MTK_SHARED_LIBRARY)

################################################################################
#       libcameracustom.camera.3a_headers
################################################################################
include $(CLEAR_VARS)

#-----------------------------------------------------------
PLATFORM := $(MTK_PLATFORM_DIR)
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM)/hal/inc \
                    $(TOP)/$(MTK_PATH_CUSTOM)/hal/inc/isp_tuning \
                    $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/isp_tuning \
                    $(TOP)/$(MTK_PATH_CUSTOM)/hal/inc/aaa \
                    $(TOP)/$(MTK_PATH_CUSTOM)/hal/camera/inc \
                    $(TOP)/$(MTK_PATH_SOURCE)/hardware/libcamera_3a/libccu_lib/lib3a.ccu.headers/$(PLATFORM)/include \

#
LOCAL_EXPORT_C_INCLUDE_DIRS += $(MTK_PATH_SOURCE)/custom
LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_CUSTOM_PLATFORM)/hal/inc/aaa
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

LOCAL_EXPORT_C_INCLUDE_DIRS += $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/drv/include/$(PLATFORM)/drv
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

#-----------------------------------------------------------
#------------------------------------------
LOCAL_HEADER_LIBRARIES += headerlib_202007021431224
#------------------------------------------
LOCAL_MODULE := libcameracustom.camera.3a_headers
LOCAL_MODULE_OWNER := mtk
include $(BUILD_HEADER_LIBRARY)


################################################################################
#
################################################################################
#include $(CLEAR_VARS)
#include $(call all-makefiles-under,$(LOCAL_PATH))

endif

################################################################################
#
################################################################################
include $(CLEAR_VARS)

#-----------------------------------------------------------
LOCAL_SRC_FILES += aaa_log.cpp

#-----------------------------------------------------------

#-----------------------------------------------------------
# MTKCAM_LOG_LEVEL_DEFAULT for compile-time loglevel control
MTKCAM_LOG_LEVEL_DEFAULT   := 4
LOG_EXCEPTION_LIST :=
ifneq ($(filter $(TARGET_BOARD_PLATFORM),$(LOG_EXCEPTION_LIST)),$(TARGET_BOARD_PLATFORM))
ifeq ($(TARGET_BUILD_VARIANT), user)
    MTKCAM_LOG_LEVEL_DEFAULT   := 2
else ifeq ($(TARGET_BUILD_VARIANT), userdebug)
# for user debug load & MTKCAM_USER_DBG_LOG_OFF (depends on special customer's request)
# change default log level to ALOGI
ifeq ($(MTK_CAM_USER_DBG_LOG_OFF), yes)
    MTKCAM_LOG_LEVEL_DEFAULT   := 2
else
    MTKCAM_LOG_LEVEL_DEFAULT   := 3
endif
endif
endif
LOCAL_CFLAGS += -DMTKCAM_LOG_LEVEL_DEFAULT=$(MTKCAM_LOG_LEVEL_DEFAULT)

#-----------------------------------------------------------
LOCAL_SHARED_LIBRARIES += liblog
LOCAL_SHARED_LIBRARIES += libutils
LOCAL_SHARED_LIBRARIES += libcutils
#LOCAL_STATIC_LIBRARIES += libc
#
LOCAL_WHOLE_STATIC_LIBRARIES +=

LOCAL_HEADER_LIBRARIES += libutils_headers
#-----------------------------------------------------------
#------------------------------------------
LOCAL_HEADER_LIBRARIES += headerlib_202007021431224
#------------------------------------------
LOCAL_MODULE := libcam.hal3a.log
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk
#-----------------------------------------------------------
include $(MTK_SHARED_LIBRARY)

include $(call all-makefiles-under,$(LOCAL_PATH))
