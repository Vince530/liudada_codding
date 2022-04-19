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

#define CNR_CCR_BASE                                                 CNR_CCR_ISP_Other_BASE
#define CNR_ABF_BASE                                                 CNR_ABF_ISP_Other_BASE
#define FUS_BASE                                                     FUS_ISP_Other_BASE
#define ZFUS_BASE                                                    ZFUS_ISP_Other_BASE

const ISP_NVRAM_CNR_CCR_T CNR_CCR_BASE[13] = {
    // IDX_0
    {
        .con       ={.bits ={.CNR_CCR_EN=0, .CNR_CCR_SL2_LINK=1, .CNR_CCR_SL2_MODE=0, .rsv_4=0, .CNR_CCR_OR_MODE=0, .rsv_6=0, .CNR_CCR_UV_GAIN_MODE=1, .rsv_9=0, .CNR_CCR_UV_GAIN2=0, .rsv_23=0, .CNR_CCR_Y_CPX3=255}},
        .ylut      ={.bits ={.CNR_CCR_Y_CPX1=32, .CNR_CCR_Y_CPX2=96, .CNR_CCR_Y_SP1=24, .rsv_23=0, .CNR_CCR_Y_CPY1=16, .rsv_31=0}},
        .uvlut     ={.bits ={.CNR_CCR_UV_X1=5, .CNR_CCR_UV_X2=37, .CNR_CCR_UV_X3=255, .CNR_CCR_UV_GAIN1=64, .rsv_31=0}},
        .ylut2     ={.bits ={.CNR_CCR_Y_SP0=16, .rsv_7=0, .CNR_CCR_Y_SP2=0, .rsv_15=0, .CNR_CCR_Y_CPY0=0, .rsv_23=0, .CNR_CCR_Y_CPY2=64, .rsv_31=0}},
        .sat_ctrl  ={.bits ={.CNR_CCR_MODE=1, .rsv_1=0, .CNR_CCR_CEN_U=0, .rsv_10=0, .CNR_CCR_CEN_V=0, .rsv_18=0}},
        .uvlut_sp  ={.bits ={.CNR_CCR_UV_GAIN_SP1=64, .rsv_10=0, .CNR_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
        .hue1      ={.bits ={.CNR_CCR_HUE_X1=0, .rsv_9=0, .CNR_CCR_HUE_X2=16, .rsv_25=0}},
        .hue2      ={.bits ={.CNR_CCR_HUE_X3=270, .rsv_9=0, .CNR_CCR_HUE_X4=286, .rsv_25=0}},
        .hue3      ={.bits ={.CNR_CCR_HUE_SP1=128, .CNR_CCR_HUE_SP2=127, .CNR_CCR_HUE_GAIN1=64, .rsv_23=0, .CNR_CCR_HUE_GAIN2=0, .rsv_31=0}},
        .l4lut1    ={.bits ={.CNR_CCR_SL2_X1=64, .CNR_CCR_SL2_X2=128, .CNR_CCR_SL2_X3=192, .rsv_24=0}},
        .l4lut2    ={.bits ={.CNR_CCR_SL2_GAIN0=8, .rsv_6=0, .CNR_CCR_SL2_GAIN1=10, .rsv_14=0, .CNR_CCR_SL2_GAIN2=12, .rsv_22=0, .CNR_CCR_SL2_GAIN3=16, .rsv_30=0}},
        .l4lut3    ={.bits ={.CNR_CCR_SL2_SP0=1, .rsv_6=0, .CNR_CCR_SL2_SP1=1, .rsv_14=0, .CNR_CCR_SL2_SP2=2, .rsv_22=0, .CNR_CCR_SL2_SP3=2, .rsv_30=0}},
    },
    // IDX_1
    {
        .con       ={.bits ={.CNR_CCR_EN=0, .CNR_CCR_SL2_LINK=1, .CNR_CCR_SL2_MODE=0, .rsv_4=0, .CNR_CCR_OR_MODE=0, .rsv_6=0, .CNR_CCR_UV_GAIN_MODE=1, .rsv_9=0, .CNR_CCR_UV_GAIN2=0, .rsv_23=0, .CNR_CCR_Y_CPX3=255}},
        .ylut      ={.bits ={.CNR_CCR_Y_CPX1=32, .CNR_CCR_Y_CPX2=96, .CNR_CCR_Y_SP1=24, .rsv_23=0, .CNR_CCR_Y_CPY1=16, .rsv_31=0}},
        .uvlut     ={.bits ={.CNR_CCR_UV_X1=5, .CNR_CCR_UV_X2=37, .CNR_CCR_UV_X3=255, .CNR_CCR_UV_GAIN1=64, .rsv_31=0}},
        .ylut2     ={.bits ={.CNR_CCR_Y_SP0=16, .rsv_7=0, .CNR_CCR_Y_SP2=0, .rsv_15=0, .CNR_CCR_Y_CPY0=0, .rsv_23=0, .CNR_CCR_Y_CPY2=64, .rsv_31=0}},
        .sat_ctrl  ={.bits ={.CNR_CCR_MODE=1, .rsv_1=0, .CNR_CCR_CEN_U=0, .rsv_10=0, .CNR_CCR_CEN_V=0, .rsv_18=0}},
        .uvlut_sp  ={.bits ={.CNR_CCR_UV_GAIN_SP1=64, .rsv_10=0, .CNR_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
        .hue1      ={.bits ={.CNR_CCR_HUE_X1=0, .rsv_9=0, .CNR_CCR_HUE_X2=16, .rsv_25=0}},
        .hue2      ={.bits ={.CNR_CCR_HUE_X3=270, .rsv_9=0, .CNR_CCR_HUE_X4=286, .rsv_25=0}},
        .hue3      ={.bits ={.CNR_CCR_HUE_SP1=128, .CNR_CCR_HUE_SP2=127, .CNR_CCR_HUE_GAIN1=64, .rsv_23=0, .CNR_CCR_HUE_GAIN2=0, .rsv_31=0}},
        .l4lut1    ={.bits ={.CNR_CCR_SL2_X1=64, .CNR_CCR_SL2_X2=128, .CNR_CCR_SL2_X3=192, .rsv_24=0}},
        .l4lut2    ={.bits ={.CNR_CCR_SL2_GAIN0=8, .rsv_6=0, .CNR_CCR_SL2_GAIN1=10, .rsv_14=0, .CNR_CCR_SL2_GAIN2=12, .rsv_22=0, .CNR_CCR_SL2_GAIN3=16, .rsv_30=0}},
        .l4lut3    ={.bits ={.CNR_CCR_SL2_SP0=1, .rsv_6=0, .CNR_CCR_SL2_SP1=1, .rsv_14=0, .CNR_CCR_SL2_SP2=2, .rsv_22=0, .CNR_CCR_SL2_SP3=2, .rsv_30=0}},
    },
    // IDX_2
    {
        .con       ={.bits ={.CNR_CCR_EN=0, .CNR_CCR_SL2_LINK=1, .CNR_CCR_SL2_MODE=0, .rsv_4=0, .CNR_CCR_OR_MODE=0, .rsv_6=0, .CNR_CCR_UV_GAIN_MODE=1, .rsv_9=0, .CNR_CCR_UV_GAIN2=0, .rsv_23=0, .CNR_CCR_Y_CPX3=255}},
        .ylut      ={.bits ={.CNR_CCR_Y_CPX1=32, .CNR_CCR_Y_CPX2=96, .CNR_CCR_Y_SP1=24, .rsv_23=0, .CNR_CCR_Y_CPY1=16, .rsv_31=0}},
        .uvlut     ={.bits ={.CNR_CCR_UV_X1=5, .CNR_CCR_UV_X2=37, .CNR_CCR_UV_X3=255, .CNR_CCR_UV_GAIN1=64, .rsv_31=0}},
        .ylut2     ={.bits ={.CNR_CCR_Y_SP0=16, .rsv_7=0, .CNR_CCR_Y_SP2=0, .rsv_15=0, .CNR_CCR_Y_CPY0=0, .rsv_23=0, .CNR_CCR_Y_CPY2=64, .rsv_31=0}},
        .sat_ctrl  ={.bits ={.CNR_CCR_MODE=1, .rsv_1=0, .CNR_CCR_CEN_U=0, .rsv_10=0, .CNR_CCR_CEN_V=0, .rsv_18=0}},
        .uvlut_sp  ={.bits ={.CNR_CCR_UV_GAIN_SP1=64, .rsv_10=0, .CNR_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
        .hue1      ={.bits ={.CNR_CCR_HUE_X1=0, .rsv_9=0, .CNR_CCR_HUE_X2=16, .rsv_25=0}},
        .hue2      ={.bits ={.CNR_CCR_HUE_X3=270, .rsv_9=0, .CNR_CCR_HUE_X4=286, .rsv_25=0}},
        .hue3      ={.bits ={.CNR_CCR_HUE_SP1=128, .CNR_CCR_HUE_SP2=127, .CNR_CCR_HUE_GAIN1=64, .rsv_23=0, .CNR_CCR_HUE_GAIN2=0, .rsv_31=0}},
        .l4lut1    ={.bits ={.CNR_CCR_SL2_X1=64, .CNR_CCR_SL2_X2=128, .CNR_CCR_SL2_X3=192, .rsv_24=0}},
        .l4lut2    ={.bits ={.CNR_CCR_SL2_GAIN0=8, .rsv_6=0, .CNR_CCR_SL2_GAIN1=10, .rsv_14=0, .CNR_CCR_SL2_GAIN2=12, .rsv_22=0, .CNR_CCR_SL2_GAIN3=16, .rsv_30=0}},
        .l4lut3    ={.bits ={.CNR_CCR_SL2_SP0=1, .rsv_6=0, .CNR_CCR_SL2_SP1=1, .rsv_14=0, .CNR_CCR_SL2_SP2=2, .rsv_22=0, .CNR_CCR_SL2_SP3=2, .rsv_30=0}},
    },
    // IDX_3
    {
        .con       ={.bits ={.CNR_CCR_EN=0, .CNR_CCR_SL2_LINK=1, .CNR_CCR_SL2_MODE=0, .rsv_4=0, .CNR_CCR_OR_MODE=0, .rsv_6=0, .CNR_CCR_UV_GAIN_MODE=1, .rsv_9=0, .CNR_CCR_UV_GAIN2=0, .rsv_23=0, .CNR_CCR_Y_CPX3=255}},
        .ylut      ={.bits ={.CNR_CCR_Y_CPX1=32, .CNR_CCR_Y_CPX2=96, .CNR_CCR_Y_SP1=24, .rsv_23=0, .CNR_CCR_Y_CPY1=16, .rsv_31=0}},
        .uvlut     ={.bits ={.CNR_CCR_UV_X1=5, .CNR_CCR_UV_X2=37, .CNR_CCR_UV_X3=255, .CNR_CCR_UV_GAIN1=64, .rsv_31=0}},
        .ylut2     ={.bits ={.CNR_CCR_Y_SP0=16, .rsv_7=0, .CNR_CCR_Y_SP2=0, .rsv_15=0, .CNR_CCR_Y_CPY0=0, .rsv_23=0, .CNR_CCR_Y_CPY2=64, .rsv_31=0}},
        .sat_ctrl  ={.bits ={.CNR_CCR_MODE=1, .rsv_1=0, .CNR_CCR_CEN_U=0, .rsv_10=0, .CNR_CCR_CEN_V=0, .rsv_18=0}},
        .uvlut_sp  ={.bits ={.CNR_CCR_UV_GAIN_SP1=64, .rsv_10=0, .CNR_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
        .hue1      ={.bits ={.CNR_CCR_HUE_X1=0, .rsv_9=0, .CNR_CCR_HUE_X2=16, .rsv_25=0}},
        .hue2      ={.bits ={.CNR_CCR_HUE_X3=270, .rsv_9=0, .CNR_CCR_HUE_X4=286, .rsv_25=0}},
        .hue3      ={.bits ={.CNR_CCR_HUE_SP1=128, .CNR_CCR_HUE_SP2=127, .CNR_CCR_HUE_GAIN1=64, .rsv_23=0, .CNR_CCR_HUE_GAIN2=0, .rsv_31=0}},
        .l4lut1    ={.bits ={.CNR_CCR_SL2_X1=64, .CNR_CCR_SL2_X2=128, .CNR_CCR_SL2_X3=192, .rsv_24=0}},
        .l4lut2    ={.bits ={.CNR_CCR_SL2_GAIN0=8, .rsv_6=0, .CNR_CCR_SL2_GAIN1=10, .rsv_14=0, .CNR_CCR_SL2_GAIN2=12, .rsv_22=0, .CNR_CCR_SL2_GAIN3=16, .rsv_30=0}},
        .l4lut3    ={.bits ={.CNR_CCR_SL2_SP0=1, .rsv_6=0, .CNR_CCR_SL2_SP1=1, .rsv_14=0, .CNR_CCR_SL2_SP2=2, .rsv_22=0, .CNR_CCR_SL2_SP3=2, .rsv_30=0}},
    },
    // IDX_4
    {
        .con       ={.bits ={.CNR_CCR_EN=0, .CNR_CCR_SL2_LINK=1, .CNR_CCR_SL2_MODE=0, .rsv_4=0, .CNR_CCR_OR_MODE=0, .rsv_6=0, .CNR_CCR_UV_GAIN_MODE=1, .rsv_9=0, .CNR_CCR_UV_GAIN2=0, .rsv_23=0, .CNR_CCR_Y_CPX3=255}},
        .ylut      ={.bits ={.CNR_CCR_Y_CPX1=32, .CNR_CCR_Y_CPX2=96, .CNR_CCR_Y_SP1=24, .rsv_23=0, .CNR_CCR_Y_CPY1=16, .rsv_31=0}},
        .uvlut     ={.bits ={.CNR_CCR_UV_X1=5, .CNR_CCR_UV_X2=37, .CNR_CCR_UV_X3=255, .CNR_CCR_UV_GAIN1=64, .rsv_31=0}},
        .ylut2     ={.bits ={.CNR_CCR_Y_SP0=16, .rsv_7=0, .CNR_CCR_Y_SP2=0, .rsv_15=0, .CNR_CCR_Y_CPY0=0, .rsv_23=0, .CNR_CCR_Y_CPY2=64, .rsv_31=0}},
        .sat_ctrl  ={.bits ={.CNR_CCR_MODE=1, .rsv_1=0, .CNR_CCR_CEN_U=0, .rsv_10=0, .CNR_CCR_CEN_V=0, .rsv_18=0}},
        .uvlut_sp  ={.bits ={.CNR_CCR_UV_GAIN_SP1=64, .rsv_10=0, .CNR_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
        .hue1      ={.bits ={.CNR_CCR_HUE_X1=0, .rsv_9=0, .CNR_CCR_HUE_X2=16, .rsv_25=0}},
        .hue2      ={.bits ={.CNR_CCR_HUE_X3=270, .rsv_9=0, .CNR_CCR_HUE_X4=286, .rsv_25=0}},
        .hue3      ={.bits ={.CNR_CCR_HUE_SP1=128, .CNR_CCR_HUE_SP2=127, .CNR_CCR_HUE_GAIN1=64, .rsv_23=0, .CNR_CCR_HUE_GAIN2=0, .rsv_31=0}},
        .l4lut1    ={.bits ={.CNR_CCR_SL2_X1=64, .CNR_CCR_SL2_X2=128, .CNR_CCR_SL2_X3=192, .rsv_24=0}},
        .l4lut2    ={.bits ={.CNR_CCR_SL2_GAIN0=8, .rsv_6=0, .CNR_CCR_SL2_GAIN1=10, .rsv_14=0, .CNR_CCR_SL2_GAIN2=12, .rsv_22=0, .CNR_CCR_SL2_GAIN3=16, .rsv_30=0}},
        .l4lut3    ={.bits ={.CNR_CCR_SL2_SP0=1, .rsv_6=0, .CNR_CCR_SL2_SP1=1, .rsv_14=0, .CNR_CCR_SL2_SP2=2, .rsv_22=0, .CNR_CCR_SL2_SP3=2, .rsv_30=0}},
    },
    // IDX_5
    {
        .con       ={.bits ={.CNR_CCR_EN=0, .CNR_CCR_SL2_LINK=1, .CNR_CCR_SL2_MODE=0, .rsv_4=0, .CNR_CCR_OR_MODE=0, .rsv_6=0, .CNR_CCR_UV_GAIN_MODE=1, .rsv_9=0, .CNR_CCR_UV_GAIN2=0, .rsv_23=0, .CNR_CCR_Y_CPX3=255}},
        .ylut      ={.bits ={.CNR_CCR_Y_CPX1=32, .CNR_CCR_Y_CPX2=96, .CNR_CCR_Y_SP1=24, .rsv_23=0, .CNR_CCR_Y_CPY1=16, .rsv_31=0}},
        .uvlut     ={.bits ={.CNR_CCR_UV_X1=5, .CNR_CCR_UV_X2=37, .CNR_CCR_UV_X3=255, .CNR_CCR_UV_GAIN1=64, .rsv_31=0}},
        .ylut2     ={.bits ={.CNR_CCR_Y_SP0=16, .rsv_7=0, .CNR_CCR_Y_SP2=0, .rsv_15=0, .CNR_CCR_Y_CPY0=0, .rsv_23=0, .CNR_CCR_Y_CPY2=64, .rsv_31=0}},
        .sat_ctrl  ={.bits ={.CNR_CCR_MODE=1, .rsv_1=0, .CNR_CCR_CEN_U=0, .rsv_10=0, .CNR_CCR_CEN_V=0, .rsv_18=0}},
        .uvlut_sp  ={.bits ={.CNR_CCR_UV_GAIN_SP1=64, .rsv_10=0, .CNR_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
        .hue1      ={.bits ={.CNR_CCR_HUE_X1=0, .rsv_9=0, .CNR_CCR_HUE_X2=16, .rsv_25=0}},
        .hue2      ={.bits ={.CNR_CCR_HUE_X3=270, .rsv_9=0, .CNR_CCR_HUE_X4=286, .rsv_25=0}},
        .hue3      ={.bits ={.CNR_CCR_HUE_SP1=128, .CNR_CCR_HUE_SP2=127, .CNR_CCR_HUE_GAIN1=64, .rsv_23=0, .CNR_CCR_HUE_GAIN2=0, .rsv_31=0}},
        .l4lut1    ={.bits ={.CNR_CCR_SL2_X1=64, .CNR_CCR_SL2_X2=128, .CNR_CCR_SL2_X3=192, .rsv_24=0}},
        .l4lut2    ={.bits ={.CNR_CCR_SL2_GAIN0=8, .rsv_6=0, .CNR_CCR_SL2_GAIN1=10, .rsv_14=0, .CNR_CCR_SL2_GAIN2=12, .rsv_22=0, .CNR_CCR_SL2_GAIN3=16, .rsv_30=0}},
        .l4lut3    ={.bits ={.CNR_CCR_SL2_SP0=1, .rsv_6=0, .CNR_CCR_SL2_SP1=1, .rsv_14=0, .CNR_CCR_SL2_SP2=2, .rsv_22=0, .CNR_CCR_SL2_SP3=2, .rsv_30=0}},
    },
    // IDX_6
    {
        .con       ={.bits ={.CNR_CCR_EN=0, .CNR_CCR_SL2_LINK=1, .CNR_CCR_SL2_MODE=0, .rsv_4=0, .CNR_CCR_OR_MODE=0, .rsv_6=0, .CNR_CCR_UV_GAIN_MODE=1, .rsv_9=0, .CNR_CCR_UV_GAIN2=0, .rsv_23=0, .CNR_CCR_Y_CPX3=255}},
        .ylut      ={.bits ={.CNR_CCR_Y_CPX1=32, .CNR_CCR_Y_CPX2=96, .CNR_CCR_Y_SP1=24, .rsv_23=0, .CNR_CCR_Y_CPY1=16, .rsv_31=0}},
        .uvlut     ={.bits ={.CNR_CCR_UV_X1=5, .CNR_CCR_UV_X2=37, .CNR_CCR_UV_X3=255, .CNR_CCR_UV_GAIN1=64, .rsv_31=0}},
        .ylut2     ={.bits ={.CNR_CCR_Y_SP0=16, .rsv_7=0, .CNR_CCR_Y_SP2=0, .rsv_15=0, .CNR_CCR_Y_CPY0=0, .rsv_23=0, .CNR_CCR_Y_CPY2=64, .rsv_31=0}},
        .sat_ctrl  ={.bits ={.CNR_CCR_MODE=1, .rsv_1=0, .CNR_CCR_CEN_U=0, .rsv_10=0, .CNR_CCR_CEN_V=0, .rsv_18=0}},
        .uvlut_sp  ={.bits ={.CNR_CCR_UV_GAIN_SP1=64, .rsv_10=0, .CNR_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
        .hue1      ={.bits ={.CNR_CCR_HUE_X1=0, .rsv_9=0, .CNR_CCR_HUE_X2=16, .rsv_25=0}},
        .hue2      ={.bits ={.CNR_CCR_HUE_X3=270, .rsv_9=0, .CNR_CCR_HUE_X4=286, .rsv_25=0}},
        .hue3      ={.bits ={.CNR_CCR_HUE_SP1=128, .CNR_CCR_HUE_SP2=127, .CNR_CCR_HUE_GAIN1=64, .rsv_23=0, .CNR_CCR_HUE_GAIN2=0, .rsv_31=0}},
        .l4lut1    ={.bits ={.CNR_CCR_SL2_X1=64, .CNR_CCR_SL2_X2=128, .CNR_CCR_SL2_X3=192, .rsv_24=0}},
        .l4lut2    ={.bits ={.CNR_CCR_SL2_GAIN0=8, .rsv_6=0, .CNR_CCR_SL2_GAIN1=10, .rsv_14=0, .CNR_CCR_SL2_GAIN2=12, .rsv_22=0, .CNR_CCR_SL2_GAIN3=16, .rsv_30=0}},
        .l4lut3    ={.bits ={.CNR_CCR_SL2_SP0=1, .rsv_6=0, .CNR_CCR_SL2_SP1=1, .rsv_14=0, .CNR_CCR_SL2_SP2=2, .rsv_22=0, .CNR_CCR_SL2_SP3=2, .rsv_30=0}},
    },
    // IDX_7
    {
        .con       ={.bits ={.CNR_CCR_EN=0, .CNR_CCR_SL2_LINK=1, .CNR_CCR_SL2_MODE=0, .rsv_4=0, .CNR_CCR_OR_MODE=0, .rsv_6=0, .CNR_CCR_UV_GAIN_MODE=1, .rsv_9=0, .CNR_CCR_UV_GAIN2=0, .rsv_23=0, .CNR_CCR_Y_CPX3=255}},
        .ylut      ={.bits ={.CNR_CCR_Y_CPX1=32, .CNR_CCR_Y_CPX2=96, .CNR_CCR_Y_SP1=24, .rsv_23=0, .CNR_CCR_Y_CPY1=16, .rsv_31=0}},
        .uvlut     ={.bits ={.CNR_CCR_UV_X1=5, .CNR_CCR_UV_X2=37, .CNR_CCR_UV_X3=255, .CNR_CCR_UV_GAIN1=64, .rsv_31=0}},
        .ylut2     ={.bits ={.CNR_CCR_Y_SP0=16, .rsv_7=0, .CNR_CCR_Y_SP2=0, .rsv_15=0, .CNR_CCR_Y_CPY0=0, .rsv_23=0, .CNR_CCR_Y_CPY2=64, .rsv_31=0}},
        .sat_ctrl  ={.bits ={.CNR_CCR_MODE=1, .rsv_1=0, .CNR_CCR_CEN_U=0, .rsv_10=0, .CNR_CCR_CEN_V=0, .rsv_18=0}},
        .uvlut_sp  ={.bits ={.CNR_CCR_UV_GAIN_SP1=64, .rsv_10=0, .CNR_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
        .hue1      ={.bits ={.CNR_CCR_HUE_X1=0, .rsv_9=0, .CNR_CCR_HUE_X2=16, .rsv_25=0}},
        .hue2      ={.bits ={.CNR_CCR_HUE_X3=270, .rsv_9=0, .CNR_CCR_HUE_X4=286, .rsv_25=0}},
        .hue3      ={.bits ={.CNR_CCR_HUE_SP1=128, .CNR_CCR_HUE_SP2=127, .CNR_CCR_HUE_GAIN1=64, .rsv_23=0, .CNR_CCR_HUE_GAIN2=0, .rsv_31=0}},
        .l4lut1    ={.bits ={.CNR_CCR_SL2_X1=64, .CNR_CCR_SL2_X2=128, .CNR_CCR_SL2_X3=192, .rsv_24=0}},
        .l4lut2    ={.bits ={.CNR_CCR_SL2_GAIN0=8, .rsv_6=0, .CNR_CCR_SL2_GAIN1=10, .rsv_14=0, .CNR_CCR_SL2_GAIN2=12, .rsv_22=0, .CNR_CCR_SL2_GAIN3=16, .rsv_30=0}},
        .l4lut3    ={.bits ={.CNR_CCR_SL2_SP0=1, .rsv_6=0, .CNR_CCR_SL2_SP1=1, .rsv_14=0, .CNR_CCR_SL2_SP2=2, .rsv_22=0, .CNR_CCR_SL2_SP3=2, .rsv_30=0}},
    },
    // IDX_8
    {
        .con       ={.bits ={.CNR_CCR_EN=0, .CNR_CCR_SL2_LINK=1, .CNR_CCR_SL2_MODE=0, .rsv_4=0, .CNR_CCR_OR_MODE=0, .rsv_6=0, .CNR_CCR_UV_GAIN_MODE=1, .rsv_9=0, .CNR_CCR_UV_GAIN2=0, .rsv_23=0, .CNR_CCR_Y_CPX3=255}},
        .ylut      ={.bits ={.CNR_CCR_Y_CPX1=32, .CNR_CCR_Y_CPX2=96, .CNR_CCR_Y_SP1=24, .rsv_23=0, .CNR_CCR_Y_CPY1=16, .rsv_31=0}},
        .uvlut     ={.bits ={.CNR_CCR_UV_X1=5, .CNR_CCR_UV_X2=37, .CNR_CCR_UV_X3=255, .CNR_CCR_UV_GAIN1=64, .rsv_31=0}},
        .ylut2     ={.bits ={.CNR_CCR_Y_SP0=16, .rsv_7=0, .CNR_CCR_Y_SP2=0, .rsv_15=0, .CNR_CCR_Y_CPY0=0, .rsv_23=0, .CNR_CCR_Y_CPY2=64, .rsv_31=0}},
        .sat_ctrl  ={.bits ={.CNR_CCR_MODE=1, .rsv_1=0, .CNR_CCR_CEN_U=0, .rsv_10=0, .CNR_CCR_CEN_V=0, .rsv_18=0}},
        .uvlut_sp  ={.bits ={.CNR_CCR_UV_GAIN_SP1=64, .rsv_10=0, .CNR_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
        .hue1      ={.bits ={.CNR_CCR_HUE_X1=0, .rsv_9=0, .CNR_CCR_HUE_X2=16, .rsv_25=0}},
        .hue2      ={.bits ={.CNR_CCR_HUE_X3=270, .rsv_9=0, .CNR_CCR_HUE_X4=286, .rsv_25=0}},
        .hue3      ={.bits ={.CNR_CCR_HUE_SP1=128, .CNR_CCR_HUE_SP2=127, .CNR_CCR_HUE_GAIN1=64, .rsv_23=0, .CNR_CCR_HUE_GAIN2=0, .rsv_31=0}},
        .l4lut1    ={.bits ={.CNR_CCR_SL2_X1=64, .CNR_CCR_SL2_X2=128, .CNR_CCR_SL2_X3=192, .rsv_24=0}},
        .l4lut2    ={.bits ={.CNR_CCR_SL2_GAIN0=8, .rsv_6=0, .CNR_CCR_SL2_GAIN1=10, .rsv_14=0, .CNR_CCR_SL2_GAIN2=12, .rsv_22=0, .CNR_CCR_SL2_GAIN3=16, .rsv_30=0}},
        .l4lut3    ={.bits ={.CNR_CCR_SL2_SP0=1, .rsv_6=0, .CNR_CCR_SL2_SP1=1, .rsv_14=0, .CNR_CCR_SL2_SP2=2, .rsv_22=0, .CNR_CCR_SL2_SP3=2, .rsv_30=0}},
    },
    // IDX_9
    {
        .con       ={.bits ={.CNR_CCR_EN=0, .CNR_CCR_SL2_LINK=1, .CNR_CCR_SL2_MODE=0, .rsv_4=0, .CNR_CCR_OR_MODE=0, .rsv_6=0, .CNR_CCR_UV_GAIN_MODE=1, .rsv_9=0, .CNR_CCR_UV_GAIN2=0, .rsv_23=0, .CNR_CCR_Y_CPX3=255}},
        .ylut      ={.bits ={.CNR_CCR_Y_CPX1=32, .CNR_CCR_Y_CPX2=96, .CNR_CCR_Y_SP1=24, .rsv_23=0, .CNR_CCR_Y_CPY1=16, .rsv_31=0}},
        .uvlut     ={.bits ={.CNR_CCR_UV_X1=5, .CNR_CCR_UV_X2=37, .CNR_CCR_UV_X3=255, .CNR_CCR_UV_GAIN1=64, .rsv_31=0}},
        .ylut2     ={.bits ={.CNR_CCR_Y_SP0=16, .rsv_7=0, .CNR_CCR_Y_SP2=0, .rsv_15=0, .CNR_CCR_Y_CPY0=0, .rsv_23=0, .CNR_CCR_Y_CPY2=64, .rsv_31=0}},
        .sat_ctrl  ={.bits ={.CNR_CCR_MODE=1, .rsv_1=0, .CNR_CCR_CEN_U=0, .rsv_10=0, .CNR_CCR_CEN_V=0, .rsv_18=0}},
        .uvlut_sp  ={.bits ={.CNR_CCR_UV_GAIN_SP1=64, .rsv_10=0, .CNR_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
        .hue1      ={.bits ={.CNR_CCR_HUE_X1=0, .rsv_9=0, .CNR_CCR_HUE_X2=16, .rsv_25=0}},
        .hue2      ={.bits ={.CNR_CCR_HUE_X3=270, .rsv_9=0, .CNR_CCR_HUE_X4=286, .rsv_25=0}},
        .hue3      ={.bits ={.CNR_CCR_HUE_SP1=128, .CNR_CCR_HUE_SP2=127, .CNR_CCR_HUE_GAIN1=64, .rsv_23=0, .CNR_CCR_HUE_GAIN2=0, .rsv_31=0}},
        .l4lut1    ={.bits ={.CNR_CCR_SL2_X1=64, .CNR_CCR_SL2_X2=128, .CNR_CCR_SL2_X3=192, .rsv_24=0}},
        .l4lut2    ={.bits ={.CNR_CCR_SL2_GAIN0=8, .rsv_6=0, .CNR_CCR_SL2_GAIN1=10, .rsv_14=0, .CNR_CCR_SL2_GAIN2=12, .rsv_22=0, .CNR_CCR_SL2_GAIN3=16, .rsv_30=0}},
        .l4lut3    ={.bits ={.CNR_CCR_SL2_SP0=1, .rsv_6=0, .CNR_CCR_SL2_SP1=1, .rsv_14=0, .CNR_CCR_SL2_SP2=2, .rsv_22=0, .CNR_CCR_SL2_SP3=2, .rsv_30=0}},
    },
    // IDX_10
    {
        .con       ={.bits ={.CNR_CCR_EN=0, .CNR_CCR_SL2_LINK=1, .CNR_CCR_SL2_MODE=0, .rsv_4=0, .CNR_CCR_OR_MODE=0, .rsv_6=0, .CNR_CCR_UV_GAIN_MODE=1, .rsv_9=0, .CNR_CCR_UV_GAIN2=0, .rsv_23=0, .CNR_CCR_Y_CPX3=255}},
        .ylut      ={.bits ={.CNR_CCR_Y_CPX1=32, .CNR_CCR_Y_CPX2=96, .CNR_CCR_Y_SP1=24, .rsv_23=0, .CNR_CCR_Y_CPY1=16, .rsv_31=0}},
        .uvlut     ={.bits ={.CNR_CCR_UV_X1=5, .CNR_CCR_UV_X2=37, .CNR_CCR_UV_X3=255, .CNR_CCR_UV_GAIN1=64, .rsv_31=0}},
        .ylut2     ={.bits ={.CNR_CCR_Y_SP0=16, .rsv_7=0, .CNR_CCR_Y_SP2=0, .rsv_15=0, .CNR_CCR_Y_CPY0=0, .rsv_23=0, .CNR_CCR_Y_CPY2=64, .rsv_31=0}},
        .sat_ctrl  ={.bits ={.CNR_CCR_MODE=1, .rsv_1=0, .CNR_CCR_CEN_U=0, .rsv_10=0, .CNR_CCR_CEN_V=0, .rsv_18=0}},
        .uvlut_sp  ={.bits ={.CNR_CCR_UV_GAIN_SP1=64, .rsv_10=0, .CNR_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
        .hue1      ={.bits ={.CNR_CCR_HUE_X1=0, .rsv_9=0, .CNR_CCR_HUE_X2=16, .rsv_25=0}},
        .hue2      ={.bits ={.CNR_CCR_HUE_X3=270, .rsv_9=0, .CNR_CCR_HUE_X4=286, .rsv_25=0}},
        .hue3      ={.bits ={.CNR_CCR_HUE_SP1=128, .CNR_CCR_HUE_SP2=127, .CNR_CCR_HUE_GAIN1=64, .rsv_23=0, .CNR_CCR_HUE_GAIN2=0, .rsv_31=0}},
        .l4lut1    ={.bits ={.CNR_CCR_SL2_X1=64, .CNR_CCR_SL2_X2=128, .CNR_CCR_SL2_X3=192, .rsv_24=0}},
        .l4lut2    ={.bits ={.CNR_CCR_SL2_GAIN0=8, .rsv_6=0, .CNR_CCR_SL2_GAIN1=10, .rsv_14=0, .CNR_CCR_SL2_GAIN2=12, .rsv_22=0, .CNR_CCR_SL2_GAIN3=16, .rsv_30=0}},
        .l4lut3    ={.bits ={.CNR_CCR_SL2_SP0=1, .rsv_6=0, .CNR_CCR_SL2_SP1=1, .rsv_14=0, .CNR_CCR_SL2_SP2=2, .rsv_22=0, .CNR_CCR_SL2_SP3=2, .rsv_30=0}},
    },
    // IDX_11
    {
        .con       ={.bits ={.CNR_CCR_EN=0, .CNR_CCR_SL2_LINK=1, .CNR_CCR_SL2_MODE=0, .rsv_4=0, .CNR_CCR_OR_MODE=0, .rsv_6=0, .CNR_CCR_UV_GAIN_MODE=1, .rsv_9=0, .CNR_CCR_UV_GAIN2=0, .rsv_23=0, .CNR_CCR_Y_CPX3=255}},
        .ylut      ={.bits ={.CNR_CCR_Y_CPX1=32, .CNR_CCR_Y_CPX2=96, .CNR_CCR_Y_SP1=24, .rsv_23=0, .CNR_CCR_Y_CPY1=16, .rsv_31=0}},
        .uvlut     ={.bits ={.CNR_CCR_UV_X1=5, .CNR_CCR_UV_X2=37, .CNR_CCR_UV_X3=255, .CNR_CCR_UV_GAIN1=64, .rsv_31=0}},
        .ylut2     ={.bits ={.CNR_CCR_Y_SP0=16, .rsv_7=0, .CNR_CCR_Y_SP2=0, .rsv_15=0, .CNR_CCR_Y_CPY0=0, .rsv_23=0, .CNR_CCR_Y_CPY2=64, .rsv_31=0}},
        .sat_ctrl  ={.bits ={.CNR_CCR_MODE=1, .rsv_1=0, .CNR_CCR_CEN_U=0, .rsv_10=0, .CNR_CCR_CEN_V=0, .rsv_18=0}},
        .uvlut_sp  ={.bits ={.CNR_CCR_UV_GAIN_SP1=64, .rsv_10=0, .CNR_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
        .hue1      ={.bits ={.CNR_CCR_HUE_X1=0, .rsv_9=0, .CNR_CCR_HUE_X2=16, .rsv_25=0}},
        .hue2      ={.bits ={.CNR_CCR_HUE_X3=270, .rsv_9=0, .CNR_CCR_HUE_X4=286, .rsv_25=0}},
        .hue3      ={.bits ={.CNR_CCR_HUE_SP1=128, .CNR_CCR_HUE_SP2=127, .CNR_CCR_HUE_GAIN1=64, .rsv_23=0, .CNR_CCR_HUE_GAIN2=0, .rsv_31=0}},
        .l4lut1    ={.bits ={.CNR_CCR_SL2_X1=64, .CNR_CCR_SL2_X2=128, .CNR_CCR_SL2_X3=192, .rsv_24=0}},
        .l4lut2    ={.bits ={.CNR_CCR_SL2_GAIN0=8, .rsv_6=0, .CNR_CCR_SL2_GAIN1=10, .rsv_14=0, .CNR_CCR_SL2_GAIN2=12, .rsv_22=0, .CNR_CCR_SL2_GAIN3=16, .rsv_30=0}},
        .l4lut3    ={.bits ={.CNR_CCR_SL2_SP0=1, .rsv_6=0, .CNR_CCR_SL2_SP1=1, .rsv_14=0, .CNR_CCR_SL2_SP2=2, .rsv_22=0, .CNR_CCR_SL2_SP3=2, .rsv_30=0}},
    },
    // IDX_12
    {
        .con       ={.bits ={.CNR_CCR_EN=0, .CNR_CCR_SL2_LINK=1, .CNR_CCR_SL2_MODE=0, .rsv_4=0, .CNR_CCR_OR_MODE=0, .rsv_6=0, .CNR_CCR_UV_GAIN_MODE=1, .rsv_9=0, .CNR_CCR_UV_GAIN2=0, .rsv_23=0, .CNR_CCR_Y_CPX3=255}},
        .ylut      ={.bits ={.CNR_CCR_Y_CPX1=32, .CNR_CCR_Y_CPX2=96, .CNR_CCR_Y_SP1=24, .rsv_23=0, .CNR_CCR_Y_CPY1=16, .rsv_31=0}},
        .uvlut     ={.bits ={.CNR_CCR_UV_X1=5, .CNR_CCR_UV_X2=37, .CNR_CCR_UV_X3=255, .CNR_CCR_UV_GAIN1=64, .rsv_31=0}},
        .ylut2     ={.bits ={.CNR_CCR_Y_SP0=16, .rsv_7=0, .CNR_CCR_Y_SP2=0, .rsv_15=0, .CNR_CCR_Y_CPY0=0, .rsv_23=0, .CNR_CCR_Y_CPY2=64, .rsv_31=0}},
        .sat_ctrl  ={.bits ={.CNR_CCR_MODE=1, .rsv_1=0, .CNR_CCR_CEN_U=0, .rsv_10=0, .CNR_CCR_CEN_V=0, .rsv_18=0}},
        .uvlut_sp  ={.bits ={.CNR_CCR_UV_GAIN_SP1=64, .rsv_10=0, .CNR_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
        .hue1      ={.bits ={.CNR_CCR_HUE_X1=0, .rsv_9=0, .CNR_CCR_HUE_X2=16, .rsv_25=0}},
        .hue2      ={.bits ={.CNR_CCR_HUE_X3=270, .rsv_9=0, .CNR_CCR_HUE_X4=286, .rsv_25=0}},
        .hue3      ={.bits ={.CNR_CCR_HUE_SP1=128, .CNR_CCR_HUE_SP2=127, .CNR_CCR_HUE_GAIN1=64, .rsv_23=0, .CNR_CCR_HUE_GAIN2=0, .rsv_31=0}},
        .l4lut1    ={.bits ={.CNR_CCR_SL2_X1=64, .CNR_CCR_SL2_X2=128, .CNR_CCR_SL2_X3=192, .rsv_24=0}},
        .l4lut2    ={.bits ={.CNR_CCR_SL2_GAIN0=8, .rsv_6=0, .CNR_CCR_SL2_GAIN1=10, .rsv_14=0, .CNR_CCR_SL2_GAIN2=12, .rsv_22=0, .CNR_CCR_SL2_GAIN3=16, .rsv_30=0}},
        .l4lut3    ={.bits ={.CNR_CCR_SL2_SP0=1, .rsv_6=0, .CNR_CCR_SL2_SP1=1, .rsv_14=0, .CNR_CCR_SL2_SP2=2, .rsv_22=0, .CNR_CCR_SL2_SP3=2, .rsv_30=0}},
    },
};
const ISP_NVRAM_CNR_ABF_T CNR_ABF_BASE[13] = {
    // IDX_0
    {
        .con1      ={.bits ={.CNR_ABF_EN=0, .rsv_1=0, .CNR_ABF_BIL_IDX=2, .CNR_ABF_NSR_IDX=1, .rsv_12=0}},
        .con2      ={.bits ={.CNR_ABF_BF_U_OFST=20, .rsv_6=0}},
        .rcon      ={.bits ={.CNR_ABF_R1=190, .rsv_9=0, .CNR_ABF_R2=322, .rsv_25=0}},
        .ylut      ={.bits ={.CNR_ABF_Y0=0, .CNR_ABF_Y1=1, .CNR_ABF_Y2=150, .CNR_ABF_Y3=186}},
        .cxlut     ={.bits ={.CNR_ABF_CX0=126, .CNR_ABF_CX1=138, .CNR_ABF_CX2=198, .CNR_ABF_CX3=210}},
        .cylut     ={.bits ={.CNR_ABF_CY0=132, .CNR_ABF_CY1=140, .CNR_ABF_CY2=184, .CNR_ABF_CY3=205}},
        .ysp       ={.bits ={.CNR_ABF_Y_SP0=511, .rsv_10=0, .CNR_ABF_Y_SP1=1010, .rsv_26=0}},
        .cxsp      ={.bits ={.CNR_ABF_CX_SP0=56, .rsv_10=0, .CNR_ABF_CX_SP1=988, .rsv_26=0}},
        .cysp      ={.bits ={.CNR_ABF_CY_SP0=64, .rsv_10=0, .CNR_ABF_CY_SP1=1000, .rsv_26=0}},
        .clp       ={.bits ={.CNR_ABF_STHRE_R=250, .CNR_ABF_STHRE_G=250, .CNR_ABF_STHRE_B=250, .rsv_24=0}},
    },
    // IDX_1
    {
        .con1      ={.bits ={.CNR_ABF_EN=0, .rsv_1=0, .CNR_ABF_BIL_IDX=2, .CNR_ABF_NSR_IDX=1, .rsv_12=0}},
        .con2      ={.bits ={.CNR_ABF_BF_U_OFST=20, .rsv_6=0}},
        .rcon      ={.bits ={.CNR_ABF_R1=190, .rsv_9=0, .CNR_ABF_R2=322, .rsv_25=0}},
        .ylut      ={.bits ={.CNR_ABF_Y0=0, .CNR_ABF_Y1=1, .CNR_ABF_Y2=150, .CNR_ABF_Y3=186}},
        .cxlut     ={.bits ={.CNR_ABF_CX0=126, .CNR_ABF_CX1=138, .CNR_ABF_CX2=198, .CNR_ABF_CX3=210}},
        .cylut     ={.bits ={.CNR_ABF_CY0=132, .CNR_ABF_CY1=140, .CNR_ABF_CY2=184, .CNR_ABF_CY3=205}},
        .ysp       ={.bits ={.CNR_ABF_Y_SP0=511, .rsv_10=0, .CNR_ABF_Y_SP1=1010, .rsv_26=0}},
        .cxsp      ={.bits ={.CNR_ABF_CX_SP0=56, .rsv_10=0, .CNR_ABF_CX_SP1=988, .rsv_26=0}},
        .cysp      ={.bits ={.CNR_ABF_CY_SP0=64, .rsv_10=0, .CNR_ABF_CY_SP1=1000, .rsv_26=0}},
        .clp       ={.bits ={.CNR_ABF_STHRE_R=250, .CNR_ABF_STHRE_G=250, .CNR_ABF_STHRE_B=250, .rsv_24=0}},
    },
    // IDX_2
    {
        .con1      ={.bits ={.CNR_ABF_EN=0, .rsv_1=0, .CNR_ABF_BIL_IDX=2, .CNR_ABF_NSR_IDX=1, .rsv_12=0}},
        .con2      ={.bits ={.CNR_ABF_BF_U_OFST=20, .rsv_6=0}},
        .rcon      ={.bits ={.CNR_ABF_R1=190, .rsv_9=0, .CNR_ABF_R2=322, .rsv_25=0}},
        .ylut      ={.bits ={.CNR_ABF_Y0=0, .CNR_ABF_Y1=1, .CNR_ABF_Y2=150, .CNR_ABF_Y3=186}},
        .cxlut     ={.bits ={.CNR_ABF_CX0=126, .CNR_ABF_CX1=138, .CNR_ABF_CX2=198, .CNR_ABF_CX3=210}},
        .cylut     ={.bits ={.CNR_ABF_CY0=132, .CNR_ABF_CY1=140, .CNR_ABF_CY2=184, .CNR_ABF_CY3=205}},
        .ysp       ={.bits ={.CNR_ABF_Y_SP0=511, .rsv_10=0, .CNR_ABF_Y_SP1=1010, .rsv_26=0}},
        .cxsp      ={.bits ={.CNR_ABF_CX_SP0=56, .rsv_10=0, .CNR_ABF_CX_SP1=988, .rsv_26=0}},
        .cysp      ={.bits ={.CNR_ABF_CY_SP0=64, .rsv_10=0, .CNR_ABF_CY_SP1=1000, .rsv_26=0}},
        .clp       ={.bits ={.CNR_ABF_STHRE_R=250, .CNR_ABF_STHRE_G=250, .CNR_ABF_STHRE_B=250, .rsv_24=0}},
    },
    // IDX_3
    {
        .con1      ={.bits ={.CNR_ABF_EN=0, .rsv_1=0, .CNR_ABF_BIL_IDX=2, .CNR_ABF_NSR_IDX=1, .rsv_12=0}},
        .con2      ={.bits ={.CNR_ABF_BF_U_OFST=20, .rsv_6=0}},
        .rcon      ={.bits ={.CNR_ABF_R1=190, .rsv_9=0, .CNR_ABF_R2=322, .rsv_25=0}},
        .ylut      ={.bits ={.CNR_ABF_Y0=0, .CNR_ABF_Y1=1, .CNR_ABF_Y2=150, .CNR_ABF_Y3=186}},
        .cxlut     ={.bits ={.CNR_ABF_CX0=126, .CNR_ABF_CX1=138, .CNR_ABF_CX2=198, .CNR_ABF_CX3=210}},
        .cylut     ={.bits ={.CNR_ABF_CY0=132, .CNR_ABF_CY1=140, .CNR_ABF_CY2=184, .CNR_ABF_CY3=205}},
        .ysp       ={.bits ={.CNR_ABF_Y_SP0=511, .rsv_10=0, .CNR_ABF_Y_SP1=1010, .rsv_26=0}},
        .cxsp      ={.bits ={.CNR_ABF_CX_SP0=56, .rsv_10=0, .CNR_ABF_CX_SP1=988, .rsv_26=0}},
        .cysp      ={.bits ={.CNR_ABF_CY_SP0=64, .rsv_10=0, .CNR_ABF_CY_SP1=1000, .rsv_26=0}},
        .clp       ={.bits ={.CNR_ABF_STHRE_R=250, .CNR_ABF_STHRE_G=250, .CNR_ABF_STHRE_B=250, .rsv_24=0}},
    },
    // IDX_4
    {
        .con1      ={.bits ={.CNR_ABF_EN=0, .rsv_1=0, .CNR_ABF_BIL_IDX=2, .CNR_ABF_NSR_IDX=1, .rsv_12=0}},
        .con2      ={.bits ={.CNR_ABF_BF_U_OFST=20, .rsv_6=0}},
        .rcon      ={.bits ={.CNR_ABF_R1=190, .rsv_9=0, .CNR_ABF_R2=322, .rsv_25=0}},
        .ylut      ={.bits ={.CNR_ABF_Y0=0, .CNR_ABF_Y1=1, .CNR_ABF_Y2=150, .CNR_ABF_Y3=186}},
        .cxlut     ={.bits ={.CNR_ABF_CX0=126, .CNR_ABF_CX1=138, .CNR_ABF_CX2=198, .CNR_ABF_CX3=210}},
        .cylut     ={.bits ={.CNR_ABF_CY0=132, .CNR_ABF_CY1=140, .CNR_ABF_CY2=184, .CNR_ABF_CY3=205}},
        .ysp       ={.bits ={.CNR_ABF_Y_SP0=511, .rsv_10=0, .CNR_ABF_Y_SP1=1010, .rsv_26=0}},
        .cxsp      ={.bits ={.CNR_ABF_CX_SP0=56, .rsv_10=0, .CNR_ABF_CX_SP1=988, .rsv_26=0}},
        .cysp      ={.bits ={.CNR_ABF_CY_SP0=64, .rsv_10=0, .CNR_ABF_CY_SP1=1000, .rsv_26=0}},
        .clp       ={.bits ={.CNR_ABF_STHRE_R=250, .CNR_ABF_STHRE_G=250, .CNR_ABF_STHRE_B=250, .rsv_24=0}},
    },
    // IDX_5
    {
        .con1      ={.bits ={.CNR_ABF_EN=0, .rsv_1=0, .CNR_ABF_BIL_IDX=2, .CNR_ABF_NSR_IDX=1, .rsv_12=0}},
        .con2      ={.bits ={.CNR_ABF_BF_U_OFST=20, .rsv_6=0}},
        .rcon      ={.bits ={.CNR_ABF_R1=190, .rsv_9=0, .CNR_ABF_R2=322, .rsv_25=0}},
        .ylut      ={.bits ={.CNR_ABF_Y0=0, .CNR_ABF_Y1=1, .CNR_ABF_Y2=150, .CNR_ABF_Y3=186}},
        .cxlut     ={.bits ={.CNR_ABF_CX0=126, .CNR_ABF_CX1=138, .CNR_ABF_CX2=198, .CNR_ABF_CX3=210}},
        .cylut     ={.bits ={.CNR_ABF_CY0=132, .CNR_ABF_CY1=140, .CNR_ABF_CY2=184, .CNR_ABF_CY3=205}},
        .ysp       ={.bits ={.CNR_ABF_Y_SP0=511, .rsv_10=0, .CNR_ABF_Y_SP1=1010, .rsv_26=0}},
        .cxsp      ={.bits ={.CNR_ABF_CX_SP0=56, .rsv_10=0, .CNR_ABF_CX_SP1=988, .rsv_26=0}},
        .cysp      ={.bits ={.CNR_ABF_CY_SP0=64, .rsv_10=0, .CNR_ABF_CY_SP1=1000, .rsv_26=0}},
        .clp       ={.bits ={.CNR_ABF_STHRE_R=250, .CNR_ABF_STHRE_G=250, .CNR_ABF_STHRE_B=250, .rsv_24=0}},
    },
    // IDX_6
    {
        .con1      ={.bits ={.CNR_ABF_EN=0, .rsv_1=0, .CNR_ABF_BIL_IDX=2, .CNR_ABF_NSR_IDX=1, .rsv_12=0}},
        .con2      ={.bits ={.CNR_ABF_BF_U_OFST=20, .rsv_6=0}},
        .rcon      ={.bits ={.CNR_ABF_R1=190, .rsv_9=0, .CNR_ABF_R2=322, .rsv_25=0}},
        .ylut      ={.bits ={.CNR_ABF_Y0=0, .CNR_ABF_Y1=1, .CNR_ABF_Y2=150, .CNR_ABF_Y3=186}},
        .cxlut     ={.bits ={.CNR_ABF_CX0=126, .CNR_ABF_CX1=138, .CNR_ABF_CX2=198, .CNR_ABF_CX3=210}},
        .cylut     ={.bits ={.CNR_ABF_CY0=132, .CNR_ABF_CY1=140, .CNR_ABF_CY2=184, .CNR_ABF_CY3=205}},
        .ysp       ={.bits ={.CNR_ABF_Y_SP0=511, .rsv_10=0, .CNR_ABF_Y_SP1=1010, .rsv_26=0}},
        .cxsp      ={.bits ={.CNR_ABF_CX_SP0=56, .rsv_10=0, .CNR_ABF_CX_SP1=988, .rsv_26=0}},
        .cysp      ={.bits ={.CNR_ABF_CY_SP0=64, .rsv_10=0, .CNR_ABF_CY_SP1=1000, .rsv_26=0}},
        .clp       ={.bits ={.CNR_ABF_STHRE_R=250, .CNR_ABF_STHRE_G=250, .CNR_ABF_STHRE_B=250, .rsv_24=0}},
    },
    // IDX_7
    {
        .con1      ={.bits ={.CNR_ABF_EN=0, .rsv_1=0, .CNR_ABF_BIL_IDX=2, .CNR_ABF_NSR_IDX=1, .rsv_12=0}},
        .con2      ={.bits ={.CNR_ABF_BF_U_OFST=20, .rsv_6=0}},
        .rcon      ={.bits ={.CNR_ABF_R1=190, .rsv_9=0, .CNR_ABF_R2=322, .rsv_25=0}},
        .ylut      ={.bits ={.CNR_ABF_Y0=0, .CNR_ABF_Y1=1, .CNR_ABF_Y2=150, .CNR_ABF_Y3=186}},
        .cxlut     ={.bits ={.CNR_ABF_CX0=126, .CNR_ABF_CX1=138, .CNR_ABF_CX2=198, .CNR_ABF_CX3=210}},
        .cylut     ={.bits ={.CNR_ABF_CY0=132, .CNR_ABF_CY1=140, .CNR_ABF_CY2=184, .CNR_ABF_CY3=205}},
        .ysp       ={.bits ={.CNR_ABF_Y_SP0=511, .rsv_10=0, .CNR_ABF_Y_SP1=1010, .rsv_26=0}},
        .cxsp      ={.bits ={.CNR_ABF_CX_SP0=56, .rsv_10=0, .CNR_ABF_CX_SP1=988, .rsv_26=0}},
        .cysp      ={.bits ={.CNR_ABF_CY_SP0=64, .rsv_10=0, .CNR_ABF_CY_SP1=1000, .rsv_26=0}},
        .clp       ={.bits ={.CNR_ABF_STHRE_R=250, .CNR_ABF_STHRE_G=250, .CNR_ABF_STHRE_B=250, .rsv_24=0}},
    },
    // IDX_8
    {
        .con1      ={.bits ={.CNR_ABF_EN=0, .rsv_1=0, .CNR_ABF_BIL_IDX=2, .CNR_ABF_NSR_IDX=1, .rsv_12=0}},
        .con2      ={.bits ={.CNR_ABF_BF_U_OFST=20, .rsv_6=0}},
        .rcon      ={.bits ={.CNR_ABF_R1=190, .rsv_9=0, .CNR_ABF_R2=322, .rsv_25=0}},
        .ylut      ={.bits ={.CNR_ABF_Y0=0, .CNR_ABF_Y1=1, .CNR_ABF_Y2=150, .CNR_ABF_Y3=186}},
        .cxlut     ={.bits ={.CNR_ABF_CX0=126, .CNR_ABF_CX1=138, .CNR_ABF_CX2=198, .CNR_ABF_CX3=210}},
        .cylut     ={.bits ={.CNR_ABF_CY0=132, .CNR_ABF_CY1=140, .CNR_ABF_CY2=184, .CNR_ABF_CY3=205}},
        .ysp       ={.bits ={.CNR_ABF_Y_SP0=511, .rsv_10=0, .CNR_ABF_Y_SP1=1010, .rsv_26=0}},
        .cxsp      ={.bits ={.CNR_ABF_CX_SP0=56, .rsv_10=0, .CNR_ABF_CX_SP1=988, .rsv_26=0}},
        .cysp      ={.bits ={.CNR_ABF_CY_SP0=64, .rsv_10=0, .CNR_ABF_CY_SP1=1000, .rsv_26=0}},
        .clp       ={.bits ={.CNR_ABF_STHRE_R=250, .CNR_ABF_STHRE_G=250, .CNR_ABF_STHRE_B=250, .rsv_24=0}},
    },
    // IDX_9
    {
        .con1      ={.bits ={.CNR_ABF_EN=0, .rsv_1=0, .CNR_ABF_BIL_IDX=2, .CNR_ABF_NSR_IDX=1, .rsv_12=0}},
        .con2      ={.bits ={.CNR_ABF_BF_U_OFST=20, .rsv_6=0}},
        .rcon      ={.bits ={.CNR_ABF_R1=190, .rsv_9=0, .CNR_ABF_R2=322, .rsv_25=0}},
        .ylut      ={.bits ={.CNR_ABF_Y0=0, .CNR_ABF_Y1=1, .CNR_ABF_Y2=150, .CNR_ABF_Y3=186}},
        .cxlut     ={.bits ={.CNR_ABF_CX0=126, .CNR_ABF_CX1=138, .CNR_ABF_CX2=198, .CNR_ABF_CX3=210}},
        .cylut     ={.bits ={.CNR_ABF_CY0=132, .CNR_ABF_CY1=140, .CNR_ABF_CY2=184, .CNR_ABF_CY3=205}},
        .ysp       ={.bits ={.CNR_ABF_Y_SP0=511, .rsv_10=0, .CNR_ABF_Y_SP1=1010, .rsv_26=0}},
        .cxsp      ={.bits ={.CNR_ABF_CX_SP0=56, .rsv_10=0, .CNR_ABF_CX_SP1=988, .rsv_26=0}},
        .cysp      ={.bits ={.CNR_ABF_CY_SP0=64, .rsv_10=0, .CNR_ABF_CY_SP1=1000, .rsv_26=0}},
        .clp       ={.bits ={.CNR_ABF_STHRE_R=250, .CNR_ABF_STHRE_G=250, .CNR_ABF_STHRE_B=250, .rsv_24=0}},
    },
    // IDX_10
    {
        .con1      ={.bits ={.CNR_ABF_EN=0, .rsv_1=0, .CNR_ABF_BIL_IDX=2, .CNR_ABF_NSR_IDX=1, .rsv_12=0}},
        .con2      ={.bits ={.CNR_ABF_BF_U_OFST=20, .rsv_6=0}},
        .rcon      ={.bits ={.CNR_ABF_R1=190, .rsv_9=0, .CNR_ABF_R2=322, .rsv_25=0}},
        .ylut      ={.bits ={.CNR_ABF_Y0=0, .CNR_ABF_Y1=1, .CNR_ABF_Y2=150, .CNR_ABF_Y3=186}},
        .cxlut     ={.bits ={.CNR_ABF_CX0=126, .CNR_ABF_CX1=138, .CNR_ABF_CX2=198, .CNR_ABF_CX3=210}},
        .cylut     ={.bits ={.CNR_ABF_CY0=132, .CNR_ABF_CY1=140, .CNR_ABF_CY2=184, .CNR_ABF_CY3=205}},
        .ysp       ={.bits ={.CNR_ABF_Y_SP0=511, .rsv_10=0, .CNR_ABF_Y_SP1=1010, .rsv_26=0}},
        .cxsp      ={.bits ={.CNR_ABF_CX_SP0=56, .rsv_10=0, .CNR_ABF_CX_SP1=988, .rsv_26=0}},
        .cysp      ={.bits ={.CNR_ABF_CY_SP0=64, .rsv_10=0, .CNR_ABF_CY_SP1=1000, .rsv_26=0}},
        .clp       ={.bits ={.CNR_ABF_STHRE_R=250, .CNR_ABF_STHRE_G=250, .CNR_ABF_STHRE_B=250, .rsv_24=0}},
    },
    // IDX_11
    {
        .con1      ={.bits ={.CNR_ABF_EN=0, .rsv_1=0, .CNR_ABF_BIL_IDX=2, .CNR_ABF_NSR_IDX=1, .rsv_12=0}},
        .con2      ={.bits ={.CNR_ABF_BF_U_OFST=20, .rsv_6=0}},
        .rcon      ={.bits ={.CNR_ABF_R1=190, .rsv_9=0, .CNR_ABF_R2=322, .rsv_25=0}},
        .ylut      ={.bits ={.CNR_ABF_Y0=0, .CNR_ABF_Y1=1, .CNR_ABF_Y2=150, .CNR_ABF_Y3=186}},
        .cxlut     ={.bits ={.CNR_ABF_CX0=126, .CNR_ABF_CX1=138, .CNR_ABF_CX2=198, .CNR_ABF_CX3=210}},
        .cylut     ={.bits ={.CNR_ABF_CY0=132, .CNR_ABF_CY1=140, .CNR_ABF_CY2=184, .CNR_ABF_CY3=205}},
        .ysp       ={.bits ={.CNR_ABF_Y_SP0=511, .rsv_10=0, .CNR_ABF_Y_SP1=1010, .rsv_26=0}},
        .cxsp      ={.bits ={.CNR_ABF_CX_SP0=56, .rsv_10=0, .CNR_ABF_CX_SP1=988, .rsv_26=0}},
        .cysp      ={.bits ={.CNR_ABF_CY_SP0=64, .rsv_10=0, .CNR_ABF_CY_SP1=1000, .rsv_26=0}},
        .clp       ={.bits ={.CNR_ABF_STHRE_R=250, .CNR_ABF_STHRE_G=250, .CNR_ABF_STHRE_B=250, .rsv_24=0}},
    },
    // IDX_12
    {
        .con1      ={.bits ={.CNR_ABF_EN=0, .rsv_1=0, .CNR_ABF_BIL_IDX=2, .CNR_ABF_NSR_IDX=1, .rsv_12=0}},
        .con2      ={.bits ={.CNR_ABF_BF_U_OFST=20, .rsv_6=0}},
        .rcon      ={.bits ={.CNR_ABF_R1=190, .rsv_9=0, .CNR_ABF_R2=322, .rsv_25=0}},
        .ylut      ={.bits ={.CNR_ABF_Y0=0, .CNR_ABF_Y1=1, .CNR_ABF_Y2=150, .CNR_ABF_Y3=186}},
        .cxlut     ={.bits ={.CNR_ABF_CX0=126, .CNR_ABF_CX1=138, .CNR_ABF_CX2=198, .CNR_ABF_CX3=210}},
        .cylut     ={.bits ={.CNR_ABF_CY0=132, .CNR_ABF_CY1=140, .CNR_ABF_CY2=184, .CNR_ABF_CY3=205}},
        .ysp       ={.bits ={.CNR_ABF_Y_SP0=511, .rsv_10=0, .CNR_ABF_Y_SP1=1010, .rsv_26=0}},
        .cxsp      ={.bits ={.CNR_ABF_CX_SP0=56, .rsv_10=0, .CNR_ABF_CX_SP1=988, .rsv_26=0}},
        .cysp      ={.bits ={.CNR_ABF_CY_SP0=64, .rsv_10=0, .CNR_ABF_CY_SP1=1000, .rsv_26=0}},
        .clp       ={.bits ={.CNR_ABF_STHRE_R=250, .CNR_ABF_STHRE_G=250, .CNR_ABF_STHRE_B=250, .rsv_24=0}},
    },
};
const ISP_NVRAM_FUS_T FUS_BASE[13] = {
    // IDX_0
    {
        .tune_1    ={.bits ={.FUS_MOSE_RATIO_0=7, .FUS_MOSE_RATIO_1=7, .FUS_MOSE_RATIO_2=7, .rsv_12=0, .FUS_ALIGN_LP_TH_0=0, .rsv_19=0, .FUS_ALIGN_LP_TH_1=0, .rsv_23=0, .FUS_ALIGN_LP_TH_2=0, .rsv_27=0, .FUS_ALIGN_LP_TH_3=0, .rsv_31=0}},
        .tune_2    ={.bits ={.FUS_OSC_TH=4080, .FUS_OSC_COUNT=16, .rsv_17=0, .FUS_MO_EN=1, .rsv_19=0, .FUS_MO_TH=2, .FUS_OSC_BLDWD=8, .FUS_MO_BLDWD=9}},
    },
    // IDX_1
    {
        .tune_1    ={.bits ={.FUS_MOSE_RATIO_0=7, .FUS_MOSE_RATIO_1=7, .FUS_MOSE_RATIO_2=7, .rsv_12=0, .FUS_ALIGN_LP_TH_0=0, .rsv_19=0, .FUS_ALIGN_LP_TH_1=0, .rsv_23=0, .FUS_ALIGN_LP_TH_2=0, .rsv_27=0, .FUS_ALIGN_LP_TH_3=0, .rsv_31=0}},
        .tune_2    ={.bits ={.FUS_OSC_TH=4080, .FUS_OSC_COUNT=16, .rsv_17=0, .FUS_MO_EN=1, .rsv_19=0, .FUS_MO_TH=2, .FUS_OSC_BLDWD=8, .FUS_MO_BLDWD=9}},
    },
    // IDX_2
    {
        .tune_1    ={.bits ={.FUS_MOSE_RATIO_0=7, .FUS_MOSE_RATIO_1=7, .FUS_MOSE_RATIO_2=7, .rsv_12=0, .FUS_ALIGN_LP_TH_0=0, .rsv_19=0, .FUS_ALIGN_LP_TH_1=0, .rsv_23=0, .FUS_ALIGN_LP_TH_2=0, .rsv_27=0, .FUS_ALIGN_LP_TH_3=0, .rsv_31=0}},
        .tune_2    ={.bits ={.FUS_OSC_TH=4080, .FUS_OSC_COUNT=16, .rsv_17=0, .FUS_MO_EN=1, .rsv_19=0, .FUS_MO_TH=2, .FUS_OSC_BLDWD=8, .FUS_MO_BLDWD=9}},
    },
    // IDX_3
    {
        .tune_1    ={.bits ={.FUS_MOSE_RATIO_0=7, .FUS_MOSE_RATIO_1=7, .FUS_MOSE_RATIO_2=7, .rsv_12=0, .FUS_ALIGN_LP_TH_0=0, .rsv_19=0, .FUS_ALIGN_LP_TH_1=0, .rsv_23=0, .FUS_ALIGN_LP_TH_2=0, .rsv_27=0, .FUS_ALIGN_LP_TH_3=0, .rsv_31=0}},
        .tune_2    ={.bits ={.FUS_OSC_TH=4080, .FUS_OSC_COUNT=16, .rsv_17=0, .FUS_MO_EN=1, .rsv_19=0, .FUS_MO_TH=2, .FUS_OSC_BLDWD=8, .FUS_MO_BLDWD=9}},
    },
    // IDX_4
    {
        .tune_1    ={.bits ={.FUS_MOSE_RATIO_0=7, .FUS_MOSE_RATIO_1=7, .FUS_MOSE_RATIO_2=7, .rsv_12=0, .FUS_ALIGN_LP_TH_0=0, .rsv_19=0, .FUS_ALIGN_LP_TH_1=0, .rsv_23=0, .FUS_ALIGN_LP_TH_2=0, .rsv_27=0, .FUS_ALIGN_LP_TH_3=0, .rsv_31=0}},
        .tune_2    ={.bits ={.FUS_OSC_TH=4080, .FUS_OSC_COUNT=16, .rsv_17=0, .FUS_MO_EN=1, .rsv_19=0, .FUS_MO_TH=2, .FUS_OSC_BLDWD=8, .FUS_MO_BLDWD=9}},
    },
    // IDX_5
    {
        .tune_1    ={.bits ={.FUS_MOSE_RATIO_0=7, .FUS_MOSE_RATIO_1=7, .FUS_MOSE_RATIO_2=7, .rsv_12=0, .FUS_ALIGN_LP_TH_0=0, .rsv_19=0, .FUS_ALIGN_LP_TH_1=0, .rsv_23=0, .FUS_ALIGN_LP_TH_2=0, .rsv_27=0, .FUS_ALIGN_LP_TH_3=0, .rsv_31=0}},
        .tune_2    ={.bits ={.FUS_OSC_TH=4080, .FUS_OSC_COUNT=16, .rsv_17=0, .FUS_MO_EN=1, .rsv_19=0, .FUS_MO_TH=2, .FUS_OSC_BLDWD=8, .FUS_MO_BLDWD=9}},
    },
    // IDX_6
    {
        .tune_1    ={.bits ={.FUS_MOSE_RATIO_0=7, .FUS_MOSE_RATIO_1=7, .FUS_MOSE_RATIO_2=7, .rsv_12=0, .FUS_ALIGN_LP_TH_0=0, .rsv_19=0, .FUS_ALIGN_LP_TH_1=0, .rsv_23=0, .FUS_ALIGN_LP_TH_2=0, .rsv_27=0, .FUS_ALIGN_LP_TH_3=0, .rsv_31=0}},
        .tune_2    ={.bits ={.FUS_OSC_TH=4080, .FUS_OSC_COUNT=16, .rsv_17=0, .FUS_MO_EN=1, .rsv_19=0, .FUS_MO_TH=2, .FUS_OSC_BLDWD=8, .FUS_MO_BLDWD=9}},
    },
    // IDX_7
    {
        .tune_1    ={.bits ={.FUS_MOSE_RATIO_0=7, .FUS_MOSE_RATIO_1=7, .FUS_MOSE_RATIO_2=7, .rsv_12=0, .FUS_ALIGN_LP_TH_0=0, .rsv_19=0, .FUS_ALIGN_LP_TH_1=0, .rsv_23=0, .FUS_ALIGN_LP_TH_2=0, .rsv_27=0, .FUS_ALIGN_LP_TH_3=0, .rsv_31=0}},
        .tune_2    ={.bits ={.FUS_OSC_TH=4080, .FUS_OSC_COUNT=16, .rsv_17=0, .FUS_MO_EN=1, .rsv_19=0, .FUS_MO_TH=2, .FUS_OSC_BLDWD=8, .FUS_MO_BLDWD=9}},
    },
    // IDX_8
    {
        .tune_1    ={.bits ={.FUS_MOSE_RATIO_0=7, .FUS_MOSE_RATIO_1=7, .FUS_MOSE_RATIO_2=7, .rsv_12=0, .FUS_ALIGN_LP_TH_0=0, .rsv_19=0, .FUS_ALIGN_LP_TH_1=0, .rsv_23=0, .FUS_ALIGN_LP_TH_2=0, .rsv_27=0, .FUS_ALIGN_LP_TH_3=0, .rsv_31=0}},
        .tune_2    ={.bits ={.FUS_OSC_TH=4080, .FUS_OSC_COUNT=16, .rsv_17=0, .FUS_MO_EN=1, .rsv_19=0, .FUS_MO_TH=2, .FUS_OSC_BLDWD=8, .FUS_MO_BLDWD=9}},
    },
    // IDX_9
    {
        .tune_1    ={.bits ={.FUS_MOSE_RATIO_0=7, .FUS_MOSE_RATIO_1=7, .FUS_MOSE_RATIO_2=7, .rsv_12=0, .FUS_ALIGN_LP_TH_0=0, .rsv_19=0, .FUS_ALIGN_LP_TH_1=0, .rsv_23=0, .FUS_ALIGN_LP_TH_2=0, .rsv_27=0, .FUS_ALIGN_LP_TH_3=0, .rsv_31=0}},
        .tune_2    ={.bits ={.FUS_OSC_TH=4080, .FUS_OSC_COUNT=16, .rsv_17=0, .FUS_MO_EN=1, .rsv_19=0, .FUS_MO_TH=2, .FUS_OSC_BLDWD=8, .FUS_MO_BLDWD=9}},
    },
    // IDX_10
    {
        .tune_1    ={.bits ={.FUS_MOSE_RATIO_0=7, .FUS_MOSE_RATIO_1=7, .FUS_MOSE_RATIO_2=7, .rsv_12=0, .FUS_ALIGN_LP_TH_0=0, .rsv_19=0, .FUS_ALIGN_LP_TH_1=0, .rsv_23=0, .FUS_ALIGN_LP_TH_2=0, .rsv_27=0, .FUS_ALIGN_LP_TH_3=0, .rsv_31=0}},
        .tune_2    ={.bits ={.FUS_OSC_TH=4080, .FUS_OSC_COUNT=16, .rsv_17=0, .FUS_MO_EN=1, .rsv_19=0, .FUS_MO_TH=2, .FUS_OSC_BLDWD=8, .FUS_MO_BLDWD=9}},
    },
    // IDX_11
    {
        .tune_1    ={.bits ={.FUS_MOSE_RATIO_0=7, .FUS_MOSE_RATIO_1=7, .FUS_MOSE_RATIO_2=7, .rsv_12=0, .FUS_ALIGN_LP_TH_0=0, .rsv_19=0, .FUS_ALIGN_LP_TH_1=0, .rsv_23=0, .FUS_ALIGN_LP_TH_2=0, .rsv_27=0, .FUS_ALIGN_LP_TH_3=0, .rsv_31=0}},
        .tune_2    ={.bits ={.FUS_OSC_TH=4080, .FUS_OSC_COUNT=16, .rsv_17=0, .FUS_MO_EN=1, .rsv_19=0, .FUS_MO_TH=2, .FUS_OSC_BLDWD=8, .FUS_MO_BLDWD=9}},
    },
    // IDX_12
    {
        .tune_1    ={.bits ={.FUS_MOSE_RATIO_0=7, .FUS_MOSE_RATIO_1=7, .FUS_MOSE_RATIO_2=7, .rsv_12=0, .FUS_ALIGN_LP_TH_0=0, .rsv_19=0, .FUS_ALIGN_LP_TH_1=0, .rsv_23=0, .FUS_ALIGN_LP_TH_2=0, .rsv_27=0, .FUS_ALIGN_LP_TH_3=0, .rsv_31=0}},
        .tune_2    ={.bits ={.FUS_OSC_TH=4080, .FUS_OSC_COUNT=16, .rsv_17=0, .FUS_MO_EN=1, .rsv_19=0, .FUS_MO_TH=2, .FUS_OSC_BLDWD=8, .FUS_MO_BLDWD=9}},
    },
};
const ISP_NVRAM_ZFUS_T ZFUS_BASE[13] = {
    // IDX_0
    {
        .ma        ={.bits ={.ZFUS_MASE_BLDWD=8, .ZFUS_OSBLD_WD=4, .ZFUS_SEYOS_LEFAC=8, .rsv_13=0, .ZFUS_SENOS_LEFAC=8, .ZFUS_DIFF_LB=0}},
        .mc        ={.bits ={.ZFUS_MO_EN=1, .rsv_1=0, .ZFUS_MOBLD_FT=4, .rsv_7=0, .ZFUS_MOTH_RATIO=2, .rsv_13=0, .ZFUS_MOSE_TH=512, .ZFUS_MOSE_BLDWD=1}},
        .osc       ={.bits ={.ZFUS_OSC_TH=4080, .ZFUS_SEDIR_SL=4, .rsv_15=0, .ZFUS_SEBLD_WD=1, .ZFUS_LEBLD_WD=1, .rsv_24=0}},
        .tune      ={.bits ={.ZFUS_PS_BLUR=1, .ZFUS_OSC_REPEN=1, .ZFUS_SOFT_TH_EN=0, .ZFUS_LE_LOWPA_EN=0, .ZFUS_SE_LOWPA_EN=0, .ZFUS_PSSEC_ONLY=0, .ZFUS_OSCLE_ONLY=0, .ZFUS_MOLE_DIREN=1, .ZFUS_MOSE_DIREN=1, .ZFUS_MO_2DBLD_EN=1, .rsv_10=0, .ZFUS_PS_TH=1024, .rsv_24=0}},
    },
    // IDX_1
    {
        .ma        ={.bits ={.ZFUS_MASE_BLDWD=8, .ZFUS_OSBLD_WD=4, .ZFUS_SEYOS_LEFAC=8, .rsv_13=0, .ZFUS_SENOS_LEFAC=8, .ZFUS_DIFF_LB=0}},
        .mc        ={.bits ={.ZFUS_MO_EN=1, .rsv_1=0, .ZFUS_MOBLD_FT=4, .rsv_7=0, .ZFUS_MOTH_RATIO=2, .rsv_13=0, .ZFUS_MOSE_TH=512, .ZFUS_MOSE_BLDWD=1}},
        .osc       ={.bits ={.ZFUS_OSC_TH=4080, .ZFUS_SEDIR_SL=4, .rsv_15=0, .ZFUS_SEBLD_WD=1, .ZFUS_LEBLD_WD=1, .rsv_24=0}},
        .tune      ={.bits ={.ZFUS_PS_BLUR=1, .ZFUS_OSC_REPEN=1, .ZFUS_SOFT_TH_EN=0, .ZFUS_LE_LOWPA_EN=0, .ZFUS_SE_LOWPA_EN=0, .ZFUS_PSSEC_ONLY=0, .ZFUS_OSCLE_ONLY=0, .ZFUS_MOLE_DIREN=1, .ZFUS_MOSE_DIREN=1, .ZFUS_MO_2DBLD_EN=1, .rsv_10=0, .ZFUS_PS_TH=1024, .rsv_24=0}},
    },
    // IDX_2
    {
        .ma        ={.bits ={.ZFUS_MASE_BLDWD=8, .ZFUS_OSBLD_WD=4, .ZFUS_SEYOS_LEFAC=8, .rsv_13=0, .ZFUS_SENOS_LEFAC=8, .ZFUS_DIFF_LB=0}},
        .mc        ={.bits ={.ZFUS_MO_EN=1, .rsv_1=0, .ZFUS_MOBLD_FT=4, .rsv_7=0, .ZFUS_MOTH_RATIO=2, .rsv_13=0, .ZFUS_MOSE_TH=512, .ZFUS_MOSE_BLDWD=1}},
        .osc       ={.bits ={.ZFUS_OSC_TH=4080, .ZFUS_SEDIR_SL=4, .rsv_15=0, .ZFUS_SEBLD_WD=1, .ZFUS_LEBLD_WD=1, .rsv_24=0}},
        .tune      ={.bits ={.ZFUS_PS_BLUR=1, .ZFUS_OSC_REPEN=1, .ZFUS_SOFT_TH_EN=0, .ZFUS_LE_LOWPA_EN=0, .ZFUS_SE_LOWPA_EN=0, .ZFUS_PSSEC_ONLY=0, .ZFUS_OSCLE_ONLY=0, .ZFUS_MOLE_DIREN=1, .ZFUS_MOSE_DIREN=1, .ZFUS_MO_2DBLD_EN=1, .rsv_10=0, .ZFUS_PS_TH=1024, .rsv_24=0}},
    },
    // IDX_3
    {
        .ma        ={.bits ={.ZFUS_MASE_BLDWD=8, .ZFUS_OSBLD_WD=4, .ZFUS_SEYOS_LEFAC=8, .rsv_13=0, .ZFUS_SENOS_LEFAC=8, .ZFUS_DIFF_LB=0}},
        .mc        ={.bits ={.ZFUS_MO_EN=1, .rsv_1=0, .ZFUS_MOBLD_FT=4, .rsv_7=0, .ZFUS_MOTH_RATIO=2, .rsv_13=0, .ZFUS_MOSE_TH=512, .ZFUS_MOSE_BLDWD=1}},
        .osc       ={.bits ={.ZFUS_OSC_TH=4080, .ZFUS_SEDIR_SL=4, .rsv_15=0, .ZFUS_SEBLD_WD=1, .ZFUS_LEBLD_WD=1, .rsv_24=0}},
        .tune      ={.bits ={.ZFUS_PS_BLUR=1, .ZFUS_OSC_REPEN=1, .ZFUS_SOFT_TH_EN=0, .ZFUS_LE_LOWPA_EN=0, .ZFUS_SE_LOWPA_EN=0, .ZFUS_PSSEC_ONLY=0, .ZFUS_OSCLE_ONLY=0, .ZFUS_MOLE_DIREN=1, .ZFUS_MOSE_DIREN=1, .ZFUS_MO_2DBLD_EN=1, .rsv_10=0, .ZFUS_PS_TH=1024, .rsv_24=0}},
    },
    // IDX_4
    {
        .ma        ={.bits ={.ZFUS_MASE_BLDWD=8, .ZFUS_OSBLD_WD=4, .ZFUS_SEYOS_LEFAC=8, .rsv_13=0, .ZFUS_SENOS_LEFAC=8, .ZFUS_DIFF_LB=0}},
        .mc        ={.bits ={.ZFUS_MO_EN=1, .rsv_1=0, .ZFUS_MOBLD_FT=4, .rsv_7=0, .ZFUS_MOTH_RATIO=2, .rsv_13=0, .ZFUS_MOSE_TH=512, .ZFUS_MOSE_BLDWD=1}},
        .osc       ={.bits ={.ZFUS_OSC_TH=4080, .ZFUS_SEDIR_SL=4, .rsv_15=0, .ZFUS_SEBLD_WD=1, .ZFUS_LEBLD_WD=1, .rsv_24=0}},
        .tune      ={.bits ={.ZFUS_PS_BLUR=1, .ZFUS_OSC_REPEN=1, .ZFUS_SOFT_TH_EN=0, .ZFUS_LE_LOWPA_EN=0, .ZFUS_SE_LOWPA_EN=0, .ZFUS_PSSEC_ONLY=0, .ZFUS_OSCLE_ONLY=0, .ZFUS_MOLE_DIREN=1, .ZFUS_MOSE_DIREN=1, .ZFUS_MO_2DBLD_EN=1, .rsv_10=0, .ZFUS_PS_TH=1024, .rsv_24=0}},
    },
    // IDX_5
    {
        .ma        ={.bits ={.ZFUS_MASE_BLDWD=8, .ZFUS_OSBLD_WD=4, .ZFUS_SEYOS_LEFAC=8, .rsv_13=0, .ZFUS_SENOS_LEFAC=8, .ZFUS_DIFF_LB=0}},
        .mc        ={.bits ={.ZFUS_MO_EN=1, .rsv_1=0, .ZFUS_MOBLD_FT=4, .rsv_7=0, .ZFUS_MOTH_RATIO=2, .rsv_13=0, .ZFUS_MOSE_TH=512, .ZFUS_MOSE_BLDWD=1}},
        .osc       ={.bits ={.ZFUS_OSC_TH=4080, .ZFUS_SEDIR_SL=4, .rsv_15=0, .ZFUS_SEBLD_WD=1, .ZFUS_LEBLD_WD=1, .rsv_24=0}},
        .tune      ={.bits ={.ZFUS_PS_BLUR=1, .ZFUS_OSC_REPEN=1, .ZFUS_SOFT_TH_EN=0, .ZFUS_LE_LOWPA_EN=0, .ZFUS_SE_LOWPA_EN=0, .ZFUS_PSSEC_ONLY=0, .ZFUS_OSCLE_ONLY=0, .ZFUS_MOLE_DIREN=1, .ZFUS_MOSE_DIREN=1, .ZFUS_MO_2DBLD_EN=1, .rsv_10=0, .ZFUS_PS_TH=1024, .rsv_24=0}},
    },
    // IDX_6
    {
        .ma        ={.bits ={.ZFUS_MASE_BLDWD=8, .ZFUS_OSBLD_WD=4, .ZFUS_SEYOS_LEFAC=8, .rsv_13=0, .ZFUS_SENOS_LEFAC=8, .ZFUS_DIFF_LB=0}},
        .mc        ={.bits ={.ZFUS_MO_EN=1, .rsv_1=0, .ZFUS_MOBLD_FT=4, .rsv_7=0, .ZFUS_MOTH_RATIO=2, .rsv_13=0, .ZFUS_MOSE_TH=512, .ZFUS_MOSE_BLDWD=1}},
        .osc       ={.bits ={.ZFUS_OSC_TH=4080, .ZFUS_SEDIR_SL=4, .rsv_15=0, .ZFUS_SEBLD_WD=1, .ZFUS_LEBLD_WD=1, .rsv_24=0}},
        .tune      ={.bits ={.ZFUS_PS_BLUR=1, .ZFUS_OSC_REPEN=1, .ZFUS_SOFT_TH_EN=0, .ZFUS_LE_LOWPA_EN=0, .ZFUS_SE_LOWPA_EN=0, .ZFUS_PSSEC_ONLY=0, .ZFUS_OSCLE_ONLY=0, .ZFUS_MOLE_DIREN=1, .ZFUS_MOSE_DIREN=1, .ZFUS_MO_2DBLD_EN=1, .rsv_10=0, .ZFUS_PS_TH=1024, .rsv_24=0}},
    },
    // IDX_7
    {
        .ma        ={.bits ={.ZFUS_MASE_BLDWD=8, .ZFUS_OSBLD_WD=4, .ZFUS_SEYOS_LEFAC=8, .rsv_13=0, .ZFUS_SENOS_LEFAC=8, .ZFUS_DIFF_LB=0}},
        .mc        ={.bits ={.ZFUS_MO_EN=1, .rsv_1=0, .ZFUS_MOBLD_FT=4, .rsv_7=0, .ZFUS_MOTH_RATIO=2, .rsv_13=0, .ZFUS_MOSE_TH=512, .ZFUS_MOSE_BLDWD=1}},
        .osc       ={.bits ={.ZFUS_OSC_TH=4080, .ZFUS_SEDIR_SL=4, .rsv_15=0, .ZFUS_SEBLD_WD=1, .ZFUS_LEBLD_WD=1, .rsv_24=0}},
        .tune      ={.bits ={.ZFUS_PS_BLUR=1, .ZFUS_OSC_REPEN=1, .ZFUS_SOFT_TH_EN=0, .ZFUS_LE_LOWPA_EN=0, .ZFUS_SE_LOWPA_EN=0, .ZFUS_PSSEC_ONLY=0, .ZFUS_OSCLE_ONLY=0, .ZFUS_MOLE_DIREN=1, .ZFUS_MOSE_DIREN=1, .ZFUS_MO_2DBLD_EN=1, .rsv_10=0, .ZFUS_PS_TH=1024, .rsv_24=0}},
    },
    // IDX_8
    {
        .ma        ={.bits ={.ZFUS_MASE_BLDWD=8, .ZFUS_OSBLD_WD=4, .ZFUS_SEYOS_LEFAC=8, .rsv_13=0, .ZFUS_SENOS_LEFAC=8, .ZFUS_DIFF_LB=0}},
        .mc        ={.bits ={.ZFUS_MO_EN=1, .rsv_1=0, .ZFUS_MOBLD_FT=4, .rsv_7=0, .ZFUS_MOTH_RATIO=2, .rsv_13=0, .ZFUS_MOSE_TH=512, .ZFUS_MOSE_BLDWD=1}},
        .osc       ={.bits ={.ZFUS_OSC_TH=4080, .ZFUS_SEDIR_SL=4, .rsv_15=0, .ZFUS_SEBLD_WD=1, .ZFUS_LEBLD_WD=1, .rsv_24=0}},
        .tune      ={.bits ={.ZFUS_PS_BLUR=1, .ZFUS_OSC_REPEN=1, .ZFUS_SOFT_TH_EN=0, .ZFUS_LE_LOWPA_EN=0, .ZFUS_SE_LOWPA_EN=0, .ZFUS_PSSEC_ONLY=0, .ZFUS_OSCLE_ONLY=0, .ZFUS_MOLE_DIREN=1, .ZFUS_MOSE_DIREN=1, .ZFUS_MO_2DBLD_EN=1, .rsv_10=0, .ZFUS_PS_TH=1024, .rsv_24=0}},
    },
    // IDX_9
    {
        .ma        ={.bits ={.ZFUS_MASE_BLDWD=8, .ZFUS_OSBLD_WD=4, .ZFUS_SEYOS_LEFAC=8, .rsv_13=0, .ZFUS_SENOS_LEFAC=8, .ZFUS_DIFF_LB=0}},
        .mc        ={.bits ={.ZFUS_MO_EN=1, .rsv_1=0, .ZFUS_MOBLD_FT=4, .rsv_7=0, .ZFUS_MOTH_RATIO=2, .rsv_13=0, .ZFUS_MOSE_TH=512, .ZFUS_MOSE_BLDWD=1}},
        .osc       ={.bits ={.ZFUS_OSC_TH=4080, .ZFUS_SEDIR_SL=4, .rsv_15=0, .ZFUS_SEBLD_WD=1, .ZFUS_LEBLD_WD=1, .rsv_24=0}},
        .tune      ={.bits ={.ZFUS_PS_BLUR=1, .ZFUS_OSC_REPEN=1, .ZFUS_SOFT_TH_EN=0, .ZFUS_LE_LOWPA_EN=0, .ZFUS_SE_LOWPA_EN=0, .ZFUS_PSSEC_ONLY=0, .ZFUS_OSCLE_ONLY=0, .ZFUS_MOLE_DIREN=1, .ZFUS_MOSE_DIREN=1, .ZFUS_MO_2DBLD_EN=1, .rsv_10=0, .ZFUS_PS_TH=1024, .rsv_24=0}},
    },
    // IDX_10
    {
        .ma        ={.bits ={.ZFUS_MASE_BLDWD=8, .ZFUS_OSBLD_WD=4, .ZFUS_SEYOS_LEFAC=8, .rsv_13=0, .ZFUS_SENOS_LEFAC=8, .ZFUS_DIFF_LB=0}},
        .mc        ={.bits ={.ZFUS_MO_EN=1, .rsv_1=0, .ZFUS_MOBLD_FT=4, .rsv_7=0, .ZFUS_MOTH_RATIO=2, .rsv_13=0, .ZFUS_MOSE_TH=512, .ZFUS_MOSE_BLDWD=1}},
        .osc       ={.bits ={.ZFUS_OSC_TH=4080, .ZFUS_SEDIR_SL=4, .rsv_15=0, .ZFUS_SEBLD_WD=1, .ZFUS_LEBLD_WD=1, .rsv_24=0}},
        .tune      ={.bits ={.ZFUS_PS_BLUR=1, .ZFUS_OSC_REPEN=1, .ZFUS_SOFT_TH_EN=0, .ZFUS_LE_LOWPA_EN=0, .ZFUS_SE_LOWPA_EN=0, .ZFUS_PSSEC_ONLY=0, .ZFUS_OSCLE_ONLY=0, .ZFUS_MOLE_DIREN=1, .ZFUS_MOSE_DIREN=1, .ZFUS_MO_2DBLD_EN=1, .rsv_10=0, .ZFUS_PS_TH=1024, .rsv_24=0}},
    },
    // IDX_11
    {
        .ma        ={.bits ={.ZFUS_MASE_BLDWD=8, .ZFUS_OSBLD_WD=4, .ZFUS_SEYOS_LEFAC=8, .rsv_13=0, .ZFUS_SENOS_LEFAC=8, .ZFUS_DIFF_LB=0}},
        .mc        ={.bits ={.ZFUS_MO_EN=1, .rsv_1=0, .ZFUS_MOBLD_FT=4, .rsv_7=0, .ZFUS_MOTH_RATIO=2, .rsv_13=0, .ZFUS_MOSE_TH=512, .ZFUS_MOSE_BLDWD=1}},
        .osc       ={.bits ={.ZFUS_OSC_TH=4080, .ZFUS_SEDIR_SL=4, .rsv_15=0, .ZFUS_SEBLD_WD=1, .ZFUS_LEBLD_WD=1, .rsv_24=0}},
        .tune      ={.bits ={.ZFUS_PS_BLUR=1, .ZFUS_OSC_REPEN=1, .ZFUS_SOFT_TH_EN=0, .ZFUS_LE_LOWPA_EN=0, .ZFUS_SE_LOWPA_EN=0, .ZFUS_PSSEC_ONLY=0, .ZFUS_OSCLE_ONLY=0, .ZFUS_MOLE_DIREN=1, .ZFUS_MOSE_DIREN=1, .ZFUS_MO_2DBLD_EN=1, .rsv_10=0, .ZFUS_PS_TH=1024, .rsv_24=0}},
    },
    // IDX_12
    {
        .ma        ={.bits ={.ZFUS_MASE_BLDWD=8, .ZFUS_OSBLD_WD=4, .ZFUS_SEYOS_LEFAC=8, .rsv_13=0, .ZFUS_SENOS_LEFAC=8, .ZFUS_DIFF_LB=0}},
        .mc        ={.bits ={.ZFUS_MO_EN=1, .rsv_1=0, .ZFUS_MOBLD_FT=4, .rsv_7=0, .ZFUS_MOTH_RATIO=2, .rsv_13=0, .ZFUS_MOSE_TH=512, .ZFUS_MOSE_BLDWD=1}},
        .osc       ={.bits ={.ZFUS_OSC_TH=4080, .ZFUS_SEDIR_SL=4, .rsv_15=0, .ZFUS_SEBLD_WD=1, .ZFUS_LEBLD_WD=1, .rsv_24=0}},
        .tune      ={.bits ={.ZFUS_PS_BLUR=1, .ZFUS_OSC_REPEN=1, .ZFUS_SOFT_TH_EN=0, .ZFUS_LE_LOWPA_EN=0, .ZFUS_SE_LOWPA_EN=0, .ZFUS_PSSEC_ONLY=0, .ZFUS_OSCLE_ONLY=0, .ZFUS_MOLE_DIREN=1, .ZFUS_MOSE_DIREN=1, .ZFUS_MO_2DBLD_EN=1, .rsv_10=0, .ZFUS_PS_TH=1024, .rsv_24=0}},
    },
};
