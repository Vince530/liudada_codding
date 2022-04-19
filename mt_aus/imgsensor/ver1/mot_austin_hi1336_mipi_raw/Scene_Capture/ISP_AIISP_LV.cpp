/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2019. All rights reserved.
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

/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
 *     TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#include "camera_custom_nvram.h"
#include "camera_custom_isp_nvram.h"

#include "inc.h"

#define AIISP_LV_Pre_BASE                                            AIISP_LV_Pre_ISP_AIISP_LV_BASE

const FEATURE_NVRAM_AIISP_LV_Pre_T AIISP_LV_Pre_BASE[6] = {
    // IDX_0
    {
            .swme_enable={.bits ={.AIISP_SWME_Enable=0}},
            .swme_sse_enable={.bits ={.AIISP_SWME_SSE_Enable=0}},
            .swme_reg00={.bits ={.AIISP_SWME_Reg00=0}},
            .swme_reg01={.bits ={.AIISP_SWME_Reg01=0}},
            .swme_reg02={.bits ={.AIISP_SWME_Reg02=0}},
            .swme_reg03={.bits ={.AIISP_SWME_Reg03=0}},
            .swme_reg04={.bits ={.AIISP_SWME_Reg04=0}},
            .swme_reg05={.bits ={.AIISP_SWME_Reg05=0}},
            .swme_reg06={.bits ={.AIISP_SWME_Reg06=0}},
            .swme_reg07={.bits ={.AIISP_SWME_Reg07=0}},
            .swme_reg08={.bits ={.AIISP_SWME_Reg08=0}},
            .swme_reg09={.bits ={.AIISP_SWME_Reg09=0}},
            .swme_reg10={.bits ={.AIISP_SWME_Reg10=0}},
            .swme_reg11={.bits ={.AIISP_SWME_Reg11=0}},
            .swme_reg12={.bits ={.AIISP_SWME_Reg12=0}},
            .swme_reg13={.bits ={.AIISP_SWME_Reg13=0}},
            .swme_reg14={.bits ={.AIISP_SWME_Reg14=0}},
            .swme_reg15={.bits ={.AIISP_SWME_Reg15=0}},
            .iso_atms_pre_idx={.bits ={.AIISP_ISO_ATMs_Pre_Idx=17}},
            .iso_atms_apu_idx={.bits ={.AIISP_ISO_ATMs_APU_Idx=16}},
            .iso_atms_post_idx={.bits ={.AIISP_ISO_ATMs_Post_Idx=16}},
            .iso_jpeg_idx={.bits ={.AIISP_ISO_JPEG_Idx=16}},
            .se_facefallback_ratio={.bits ={.AIISP_SE_FaceFallBack_Ratio=10000}},
            .ne_facefallback_ratio={.bits ={.AIISP_NE_FaceFallBack_Ratio=10000}},
            .le_facefallback_ratio={.bits ={.AIISP_LE_FaceFallBack_Ratio=10000}},
    },
    // IDX_1
    {
            .swme_enable={.bits ={.AIISP_SWME_Enable=0}},
            .swme_sse_enable={.bits ={.AIISP_SWME_SSE_Enable=0}},
            .swme_reg00={.bits ={.AIISP_SWME_Reg00=0}},
            .swme_reg01={.bits ={.AIISP_SWME_Reg01=0}},
            .swme_reg02={.bits ={.AIISP_SWME_Reg02=0}},
            .swme_reg03={.bits ={.AIISP_SWME_Reg03=0}},
            .swme_reg04={.bits ={.AIISP_SWME_Reg04=0}},
            .swme_reg05={.bits ={.AIISP_SWME_Reg05=0}},
            .swme_reg06={.bits ={.AIISP_SWME_Reg06=0}},
            .swme_reg07={.bits ={.AIISP_SWME_Reg07=0}},
            .swme_reg08={.bits ={.AIISP_SWME_Reg08=0}},
            .swme_reg09={.bits ={.AIISP_SWME_Reg09=0}},
            .swme_reg10={.bits ={.AIISP_SWME_Reg10=0}},
            .swme_reg11={.bits ={.AIISP_SWME_Reg11=0}},
            .swme_reg12={.bits ={.AIISP_SWME_Reg12=0}},
            .swme_reg13={.bits ={.AIISP_SWME_Reg13=0}},
            .swme_reg14={.bits ={.AIISP_SWME_Reg14=0}},
            .swme_reg15={.bits ={.AIISP_SWME_Reg15=0}},
            .iso_atms_pre_idx={.bits ={.AIISP_ISO_ATMs_Pre_Idx=17}},
            .iso_atms_apu_idx={.bits ={.AIISP_ISO_ATMs_APU_Idx=16}},
            .iso_atms_post_idx={.bits ={.AIISP_ISO_ATMs_Post_Idx=16}},
            .iso_jpeg_idx={.bits ={.AIISP_ISO_JPEG_Idx=16}},
            .se_facefallback_ratio={.bits ={.AIISP_SE_FaceFallBack_Ratio=10000}},
            .ne_facefallback_ratio={.bits ={.AIISP_NE_FaceFallBack_Ratio=10000}},
            .le_facefallback_ratio={.bits ={.AIISP_LE_FaceFallBack_Ratio=10000}},
    },
    // IDX_2
    {
            .swme_enable={.bits ={.AIISP_SWME_Enable=0}},
            .swme_sse_enable={.bits ={.AIISP_SWME_SSE_Enable=0}},
            .swme_reg00={.bits ={.AIISP_SWME_Reg00=0}},
            .swme_reg01={.bits ={.AIISP_SWME_Reg01=0}},
            .swme_reg02={.bits ={.AIISP_SWME_Reg02=0}},
            .swme_reg03={.bits ={.AIISP_SWME_Reg03=0}},
            .swme_reg04={.bits ={.AIISP_SWME_Reg04=0}},
            .swme_reg05={.bits ={.AIISP_SWME_Reg05=0}},
            .swme_reg06={.bits ={.AIISP_SWME_Reg06=0}},
            .swme_reg07={.bits ={.AIISP_SWME_Reg07=0}},
            .swme_reg08={.bits ={.AIISP_SWME_Reg08=0}},
            .swme_reg09={.bits ={.AIISP_SWME_Reg09=0}},
            .swme_reg10={.bits ={.AIISP_SWME_Reg10=0}},
            .swme_reg11={.bits ={.AIISP_SWME_Reg11=0}},
            .swme_reg12={.bits ={.AIISP_SWME_Reg12=0}},
            .swme_reg13={.bits ={.AIISP_SWME_Reg13=0}},
            .swme_reg14={.bits ={.AIISP_SWME_Reg14=0}},
            .swme_reg15={.bits ={.AIISP_SWME_Reg15=0}},
            .iso_atms_pre_idx={.bits ={.AIISP_ISO_ATMs_Pre_Idx=17}},
            .iso_atms_apu_idx={.bits ={.AIISP_ISO_ATMs_APU_Idx=16}},
            .iso_atms_post_idx={.bits ={.AIISP_ISO_ATMs_Post_Idx=16}},
            .iso_jpeg_idx={.bits ={.AIISP_ISO_JPEG_Idx=16}},
            .se_facefallback_ratio={.bits ={.AIISP_SE_FaceFallBack_Ratio=10000}},
            .ne_facefallback_ratio={.bits ={.AIISP_NE_FaceFallBack_Ratio=10000}},
            .le_facefallback_ratio={.bits ={.AIISP_LE_FaceFallBack_Ratio=10000}},
    },
    // IDX_3
    {
            .swme_enable={.bits ={.AIISP_SWME_Enable=0}},
            .swme_sse_enable={.bits ={.AIISP_SWME_SSE_Enable=0}},
            .swme_reg00={.bits ={.AIISP_SWME_Reg00=0}},
            .swme_reg01={.bits ={.AIISP_SWME_Reg01=0}},
            .swme_reg02={.bits ={.AIISP_SWME_Reg02=0}},
            .swme_reg03={.bits ={.AIISP_SWME_Reg03=0}},
            .swme_reg04={.bits ={.AIISP_SWME_Reg04=0}},
            .swme_reg05={.bits ={.AIISP_SWME_Reg05=0}},
            .swme_reg06={.bits ={.AIISP_SWME_Reg06=0}},
            .swme_reg07={.bits ={.AIISP_SWME_Reg07=0}},
            .swme_reg08={.bits ={.AIISP_SWME_Reg08=0}},
            .swme_reg09={.bits ={.AIISP_SWME_Reg09=0}},
            .swme_reg10={.bits ={.AIISP_SWME_Reg10=0}},
            .swme_reg11={.bits ={.AIISP_SWME_Reg11=0}},
            .swme_reg12={.bits ={.AIISP_SWME_Reg12=0}},
            .swme_reg13={.bits ={.AIISP_SWME_Reg13=0}},
            .swme_reg14={.bits ={.AIISP_SWME_Reg14=0}},
            .swme_reg15={.bits ={.AIISP_SWME_Reg15=0}},
            .iso_atms_pre_idx={.bits ={.AIISP_ISO_ATMs_Pre_Idx=17}},
            .iso_atms_apu_idx={.bits ={.AIISP_ISO_ATMs_APU_Idx=16}},
            .iso_atms_post_idx={.bits ={.AIISP_ISO_ATMs_Post_Idx=16}},
            .iso_jpeg_idx={.bits ={.AIISP_ISO_JPEG_Idx=16}},
            .se_facefallback_ratio={.bits ={.AIISP_SE_FaceFallBack_Ratio=10000}},
            .ne_facefallback_ratio={.bits ={.AIISP_NE_FaceFallBack_Ratio=10000}},
            .le_facefallback_ratio={.bits ={.AIISP_LE_FaceFallBack_Ratio=10000}},
    },
    // IDX_4
    {
            .swme_enable={.bits ={.AIISP_SWME_Enable=0}},
            .swme_sse_enable={.bits ={.AIISP_SWME_SSE_Enable=0}},
            .swme_reg00={.bits ={.AIISP_SWME_Reg00=0}},
            .swme_reg01={.bits ={.AIISP_SWME_Reg01=0}},
            .swme_reg02={.bits ={.AIISP_SWME_Reg02=0}},
            .swme_reg03={.bits ={.AIISP_SWME_Reg03=0}},
            .swme_reg04={.bits ={.AIISP_SWME_Reg04=0}},
            .swme_reg05={.bits ={.AIISP_SWME_Reg05=0}},
            .swme_reg06={.bits ={.AIISP_SWME_Reg06=0}},
            .swme_reg07={.bits ={.AIISP_SWME_Reg07=0}},
            .swme_reg08={.bits ={.AIISP_SWME_Reg08=0}},
            .swme_reg09={.bits ={.AIISP_SWME_Reg09=0}},
            .swme_reg10={.bits ={.AIISP_SWME_Reg10=0}},
            .swme_reg11={.bits ={.AIISP_SWME_Reg11=0}},
            .swme_reg12={.bits ={.AIISP_SWME_Reg12=0}},
            .swme_reg13={.bits ={.AIISP_SWME_Reg13=0}},
            .swme_reg14={.bits ={.AIISP_SWME_Reg14=0}},
            .swme_reg15={.bits ={.AIISP_SWME_Reg15=0}},
            .iso_atms_pre_idx={.bits ={.AIISP_ISO_ATMs_Pre_Idx=17}},
            .iso_atms_apu_idx={.bits ={.AIISP_ISO_ATMs_APU_Idx=16}},
            .iso_atms_post_idx={.bits ={.AIISP_ISO_ATMs_Post_Idx=16}},
            .iso_jpeg_idx={.bits ={.AIISP_ISO_JPEG_Idx=16}},
            .se_facefallback_ratio={.bits ={.AIISP_SE_FaceFallBack_Ratio=10000}},
            .ne_facefallback_ratio={.bits ={.AIISP_NE_FaceFallBack_Ratio=10000}},
            .le_facefallback_ratio={.bits ={.AIISP_LE_FaceFallBack_Ratio=10000}},
    },
    // IDX_5
    {
            .swme_enable={.bits ={.AIISP_SWME_Enable=0}},
            .swme_sse_enable={.bits ={.AIISP_SWME_SSE_Enable=0}},
            .swme_reg00={.bits ={.AIISP_SWME_Reg00=0}},
            .swme_reg01={.bits ={.AIISP_SWME_Reg01=0}},
            .swme_reg02={.bits ={.AIISP_SWME_Reg02=0}},
            .swme_reg03={.bits ={.AIISP_SWME_Reg03=0}},
            .swme_reg04={.bits ={.AIISP_SWME_Reg04=0}},
            .swme_reg05={.bits ={.AIISP_SWME_Reg05=0}},
            .swme_reg06={.bits ={.AIISP_SWME_Reg06=0}},
            .swme_reg07={.bits ={.AIISP_SWME_Reg07=0}},
            .swme_reg08={.bits ={.AIISP_SWME_Reg08=0}},
            .swme_reg09={.bits ={.AIISP_SWME_Reg09=0}},
            .swme_reg10={.bits ={.AIISP_SWME_Reg10=0}},
            .swme_reg11={.bits ={.AIISP_SWME_Reg11=0}},
            .swme_reg12={.bits ={.AIISP_SWME_Reg12=0}},
            .swme_reg13={.bits ={.AIISP_SWME_Reg13=0}},
            .swme_reg14={.bits ={.AIISP_SWME_Reg14=0}},
            .swme_reg15={.bits ={.AIISP_SWME_Reg15=0}},
            .iso_atms_pre_idx={.bits ={.AIISP_ISO_ATMs_Pre_Idx=17}},
            .iso_atms_apu_idx={.bits ={.AIISP_ISO_ATMs_APU_Idx=16}},
            .iso_atms_post_idx={.bits ={.AIISP_ISO_ATMs_Post_Idx=16}},
            .iso_jpeg_idx={.bits ={.AIISP_ISO_JPEG_Idx=16}},
            .se_facefallback_ratio={.bits ={.AIISP_SE_FaceFallBack_Ratio=10000}},
            .ne_facefallback_ratio={.bits ={.AIISP_NE_FaceFallBack_Ratio=10000}},
            .le_facefallback_ratio={.bits ={.AIISP_LE_FaceFallBack_Ratio=10000}},
    },
};
