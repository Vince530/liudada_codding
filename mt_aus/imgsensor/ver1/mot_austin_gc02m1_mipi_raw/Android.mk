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




################################################################################
#
################################################################################

LOCAL_PATH := $(call my-dir)

# Use project imgsensor first
ifeq ($(wildcard $(MTK_PATH_CUSTOM)/hal/imgsensor),)

#function definition
define all-c-cpp-under
$(patsubst ./%,%, \
$(shell cd $(LOCAL_PATH) ; \
find -L $(1) -maxdepth 1 \( -name "*.c" -or -name "*.cpp" \) -and -not -name ".*") \
)
endef

define current_module_name
$(shell basename $(LOCAL_PATH))
endef

define find-all-sub-module
$(shell cd $(LOCAL_PATH) ; \
    find ./*/ -name Android.mk)
endef

################################################################################
#
################################################################################
include $(CLEAR_VARS)


##read Module ID from folder
LOCAL_MODULE_INDEX=$(wordlist 6,4,$(subst _, ,$(call current_module_name)))
#set default moduleID
ifeq ($(LOCAL_MODULE_INDEX),)
LOCAL_MODULE_INDEX=0
endif

LOCAL_CFLAGS += -DMODULE_INDEX=$(LOCAL_MODULE_INDEX)

#get module name
LOCAL_MODULE_NAME=$(call current_module_name)
$(info LOCAL_MODULE_NAME=$(LOCAL_MODULE_NAME), LOCAL_MODULE_ID=$(LOCAL_MODULE_INDEX))

LOCAL_CFLAGS += -DTARGET_SENSOR=$(subst _,,$(LOCAL_MODULE_NAME))

all_sub_modules := $(patsubst ./%/Android.mk,%,$(call find-all-sub-module))
LOCAL_filter += $(patsubst %,%/$(subst _,,$(LOCAL_MODULE_NAME))_%, $(all_sub_modules))
LOCAL_filter += AE_Tuning_Para/%
LOCAL_filter += camera_indexmgr_api.cpp
LOCAL_filter += camera_camsv_custom_decode.cpp
LOCAL_filter += camera_AE_custom_transform.cpp


#find all cpp and make code
cppall_t := $(call all-cpp-files-under)
LOCAL_cppall_t := $(call all-cpp-files-under)
LOCAL_cppall := $(filter-out $(LOCAL_filter), $(LOCAL_cppall_t))

#-----------------------------------------------------------
LOCAL_SRC_FILES += $(LOCAL_cppall)
#-----------------------------------------------------------

LOCAL_HEADER_LIBRARIES += libcameracustom_headers
LOCAL_HEADER_LIBRARIES += libmtkcam_headers
LOCAL_HEADER_LIBRARIES += libutils_headers

#-----------------------------------------------------------
LOCAL_SHARED_LIBRARIES += liblog libcutils
LOCAL_SHARED_LIBRARIES += $(patsubst %, libCamera_$(subst _,,$(LOCAL_MODULE_NAME))_%, $(all_sub_modules))

#-----------------------------------------------------------
LOCAL_CFLAGS += $(MTKCAM_CFLAGS)
LOCAL_CFLAGS += -DMTK_CAM_NEW_NVRAM_SUPPORT=1

#-----------------------------------------------------------

LOCAL_MODULE := $(LOCAL_MODULE_NAME)_tuning
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
#-----------------------------------------------------------

# flicker picker start
ifeq ($(FLICKER_PICKER_RUN),1)
ifeq ($(filter $(LOCAL_MODULE_NAME),$(IGNORE_SENSOR)),)
$(info [Flicker] start auto-gen for $(LOCAL_MODULE_NAME))
include $(FLICKER_PICKER_MAIN)
else
$(info [Flicker] ignore auto-gen for $(LOCAL_MODULE_NAME))
endif
endif
# flicker picker end

include $(MTK_SHARED_LIBRARY)

################################################################################
#
################################################################################

include $(CLEAR_VARS)

LOCAL_CFLAGS += -DMODULE_INDEX=$(LOCAL_MODULE_INDEX)
LOCAL_CFLAGS += -DMTK_CAM_NEW_NVRAM_SUPPORT=1

LOCAL_SRC_FILES += camera_indexmgr_api.cpp
LOCAL_SRC_FILES += camera_camsv_custom_decode.cpp
LOCAL_SRC_FILES += camera_AE_custom_transform.cpp

#-----------------------------------------------------------

LOCAL_HEADER_LIBRARIES += libmtkcam_headers
LOCAL_HEADER_LIBRARIES += libcameracustom_headers

#-----------------------------------------------------------
LOCAL_STATIC_LIBRARIES += lib3a.ccu.headers
LOCAL_HEADER_LIBRARIES += libutils_headers
LOCAL_SHARED_LIBRARIES += liblog libcutils

LOCAL_MODULE := $(LOCAL_MODULE_NAME)_IdxMgr
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk

include $(MTK_SHARED_LIBRARY)

################################################################################
#
################################################################################

include $(CLEAR_VARS)
include $(call all-makefiles-under,$(LOCAL_PATH))
endif


