/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2021. All rights reserved.
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

#define DM_BASE                                                      DM_ISP_P1_YUV_BASE

const ISP_NVRAM_DM_T DM_BASE[13] = {
    // IDX_0
    {
        .intp_crs  ={.bits ={.DM_CDG_SL=4, .DM_CDG_OFST=20, .DM_CDG_RAT=16, .DM_CD_KNL=0, .rsv_18=0, .DM_BIN_EO_SEL=0, .DM_BIN_MODE=0, .DM_BYP=0, .DM_MN_MODE=0}},
        .intp_nat  ={.bits ={.DM_HL_OFST=0, .DM_L0_SL=6, .DM_L0_OFST=0, .DM_CD_SLL=3, .DM_CD_SLC=0, .rsv_30=0}},
        .intp_aug  ={.bits ={.DM_DN_OFST=0, .DM_L2_SL=6, .DM_L2_OFST=0, .DM_L1_SL=6, .DM_L1_OFST=0}},
        .luma_lut1 ={.bits ={.DM_LM_Y2=256, .DM_LM_Y1=384, .DM_LM_Y0=511, .rsv_27=0}},
        .luma_lut2 ={.bits ={.DM_LM_Y5=32, .DM_LM_Y4=64, .DM_LM_Y3=128, .rsv_27=0}},
        .sl_ctl    ={.bits ={.DM_SL_EN=0, .DM_SL_HR=16, .DM_SL_Y2=255, .DM_SL_Y1=255, .rsv_22=0}},
        .hftd_ctl  ={.bits ={.DM_CORE_TH1=0, .DM_HD_GN2=0, .DM_HD_GN1=16, .DM_HT_GN2=16, .DM_HT_GN1=16, .rsv_28=0}},
        .nr_str    ={.bits ={.DM_N2_STR=0, .DM_N1_STR=0, .DM_N0_STR=0, .DM_XTK_SL=5, .DM_XTK_OFST=32, .DM_XTK_RAT=16}},
        .nr_act    ={.bits ={.DM_NGR=0, .DM_NSL=5, .DM_N2_OFST=0, .DM_N1_OFST=0, .DM_N0_OFST=0}},
        .hf_str    ={.bits ={.DM_CORE_TH2=0, .DM_HI_RAT=0, .DM_H3_GN=16, .DM_H2_GN=21, .DM_H1_GN=26, .DM_HA_STR=0}},
        .hf_act1   ={.bits ={.DM_H2_UPB=220, .DM_H2_LWB=52, .DM_H1_UPB=80, .DM_H1_LWB=20}},
        .hf_act2   ={.bits ={.DM_HSLL=5, .DM_HSLR=5, .DM_H3_UPB=255, .DM_H3_LWB=52, .rsv_24=0}},
        .clip      ={.bits ={.DM_CLIP_TH=100, .DM_UN_TH=32, .DM_OV_TH=223, .rsv_24=0}},
        .p1_act    ={.bits ={.DM_P1_UPB=85, .DM_P1_LWB=85, .rsv_16=0}},
        .lr_rat    ={.bits ={.DM_LR_RAT=15, .rsv_4=0}},
        .hftd_ctl2 ={.bits ={.DM_HD_GN3=16, .DM_HFRB_GN=16, .rsv_12=0}},
        .est_ctl   ={.bits ={.DM_P2_CLIP=0, .DM_P1_BLD=0, .rsv_6=0}},
        .int_ctl   ={.bits ={.DM_INT_LTH=3, .DM_INT_CDTH=5, .rsv_8=0}},
        .ee        ={.bits ={.DM_HPOS_GN=16, .DM_HNEG_GN=16, .rsv_10=0}},
        .lmt       ={.bits ={.DM_LMT_UPB=148, .DM_LMT_LWB=120, .DM_LMT_EN=0, .rsv_17=0}},
        .rccc      ={.bits ={.DM_RCDM_SL=192, .DM_RCCC_EN=0, .rsv_14=0}},
    },
    // IDX_1
    {
        .intp_crs  ={.bits ={.DM_CDG_SL=4, .DM_CDG_OFST=20, .DM_CDG_RAT=16, .DM_CD_KNL=0, .rsv_18=0, .DM_BIN_EO_SEL=0, .DM_BIN_MODE=0, .DM_BYP=0, .DM_MN_MODE=0}},
        .intp_nat  ={.bits ={.DM_HL_OFST=0, .DM_L0_SL=6, .DM_L0_OFST=0, .DM_CD_SLL=3, .DM_CD_SLC=0, .rsv_30=0}},
        .intp_aug  ={.bits ={.DM_DN_OFST=0, .DM_L2_SL=6, .DM_L2_OFST=0, .DM_L1_SL=6, .DM_L1_OFST=0}},
        .luma_lut1 ={.bits ={.DM_LM_Y2=256, .DM_LM_Y1=384, .DM_LM_Y0=511, .rsv_27=0}},
        .luma_lut2 ={.bits ={.DM_LM_Y5=32, .DM_LM_Y4=64, .DM_LM_Y3=128, .rsv_27=0}},
        .sl_ctl    ={.bits ={.DM_SL_EN=0, .DM_SL_HR=16, .DM_SL_Y2=255, .DM_SL_Y1=255, .rsv_22=0}},
        .hftd_ctl  ={.bits ={.DM_CORE_TH1=0, .DM_HD_GN2=0, .DM_HD_GN1=16, .DM_HT_GN2=16, .DM_HT_GN1=16, .rsv_28=0}},
        .nr_str    ={.bits ={.DM_N2_STR=0, .DM_N1_STR=0, .DM_N0_STR=0, .DM_XTK_SL=5, .DM_XTK_OFST=32, .DM_XTK_RAT=16}},
        .nr_act    ={.bits ={.DM_NGR=0, .DM_NSL=5, .DM_N2_OFST=0, .DM_N1_OFST=0, .DM_N0_OFST=0}},
        .hf_str    ={.bits ={.DM_CORE_TH2=0, .DM_HI_RAT=0, .DM_H3_GN=16, .DM_H2_GN=21, .DM_H1_GN=26, .DM_HA_STR=0}},
        .hf_act1   ={.bits ={.DM_H2_UPB=220, .DM_H2_LWB=52, .DM_H1_UPB=80, .DM_H1_LWB=20}},
        .hf_act2   ={.bits ={.DM_HSLL=5, .DM_HSLR=5, .DM_H3_UPB=255, .DM_H3_LWB=52, .rsv_24=0}},
        .clip      ={.bits ={.DM_CLIP_TH=100, .DM_UN_TH=32, .DM_OV_TH=223, .rsv_24=0}},
        .p1_act    ={.bits ={.DM_P1_UPB=85, .DM_P1_LWB=85, .rsv_16=0}},
        .lr_rat    ={.bits ={.DM_LR_RAT=15, .rsv_4=0}},
        .hftd_ctl2 ={.bits ={.DM_HD_GN3=16, .DM_HFRB_GN=16, .rsv_12=0}},
        .est_ctl   ={.bits ={.DM_P2_CLIP=0, .DM_P1_BLD=0, .rsv_6=0}},
        .int_ctl   ={.bits ={.DM_INT_LTH=3, .DM_INT_CDTH=5, .rsv_8=0}},
        .ee        ={.bits ={.DM_HPOS_GN=16, .DM_HNEG_GN=16, .rsv_10=0}},
        .lmt       ={.bits ={.DM_LMT_UPB=148, .DM_LMT_LWB=120, .DM_LMT_EN=0, .rsv_17=0}},
        .rccc      ={.bits ={.DM_RCDM_SL=192, .DM_RCCC_EN=0, .rsv_14=0}},
    },
    // IDX_2
    {
        .intp_crs  ={.bits ={.DM_CDG_SL=4, .DM_CDG_OFST=20, .DM_CDG_RAT=16, .DM_CD_KNL=0, .rsv_18=0, .DM_BIN_EO_SEL=0, .DM_BIN_MODE=0, .DM_BYP=0, .DM_MN_MODE=0}},
        .intp_nat  ={.bits ={.DM_HL_OFST=0, .DM_L0_SL=6, .DM_L0_OFST=0, .DM_CD_SLL=3, .DM_CD_SLC=0, .rsv_30=0}},
        .intp_aug  ={.bits ={.DM_DN_OFST=0, .DM_L2_SL=6, .DM_L2_OFST=0, .DM_L1_SL=6, .DM_L1_OFST=0}},
        .luma_lut1 ={.bits ={.DM_LM_Y2=256, .DM_LM_Y1=384, .DM_LM_Y0=511, .rsv_27=0}},
        .luma_lut2 ={.bits ={.DM_LM_Y5=32, .DM_LM_Y4=64, .DM_LM_Y3=128, .rsv_27=0}},
        .sl_ctl    ={.bits ={.DM_SL_EN=0, .DM_SL_HR=16, .DM_SL_Y2=255, .DM_SL_Y1=255, .rsv_22=0}},
        .hftd_ctl  ={.bits ={.DM_CORE_TH1=0, .DM_HD_GN2=0, .DM_HD_GN1=16, .DM_HT_GN2=16, .DM_HT_GN1=16, .rsv_28=0}},
        .nr_str    ={.bits ={.DM_N2_STR=0, .DM_N1_STR=0, .DM_N0_STR=0, .DM_XTK_SL=5, .DM_XTK_OFST=32, .DM_XTK_RAT=16}},
        .nr_act    ={.bits ={.DM_NGR=0, .DM_NSL=5, .DM_N2_OFST=0, .DM_N1_OFST=0, .DM_N0_OFST=0}},
        .hf_str    ={.bits ={.DM_CORE_TH2=0, .DM_HI_RAT=0, .DM_H3_GN=16, .DM_H2_GN=21, .DM_H1_GN=26, .DM_HA_STR=0}},
        .hf_act1   ={.bits ={.DM_H2_UPB=220, .DM_H2_LWB=52, .DM_H1_UPB=80, .DM_H1_LWB=20}},
        .hf_act2   ={.bits ={.DM_HSLL=5, .DM_HSLR=5, .DM_H3_UPB=255, .DM_H3_LWB=52, .rsv_24=0}},
        .clip      ={.bits ={.DM_CLIP_TH=100, .DM_UN_TH=32, .DM_OV_TH=223, .rsv_24=0}},
        .p1_act    ={.bits ={.DM_P1_UPB=85, .DM_P1_LWB=85, .rsv_16=0}},
        .lr_rat    ={.bits ={.DM_LR_RAT=15, .rsv_4=0}},
        .hftd_ctl2 ={.bits ={.DM_HD_GN3=16, .DM_HFRB_GN=16, .rsv_12=0}},
        .est_ctl   ={.bits ={.DM_P2_CLIP=0, .DM_P1_BLD=0, .rsv_6=0}},
        .int_ctl   ={.bits ={.DM_INT_LTH=3, .DM_INT_CDTH=5, .rsv_8=0}},
        .ee        ={.bits ={.DM_HPOS_GN=16, .DM_HNEG_GN=16, .rsv_10=0}},
        .lmt       ={.bits ={.DM_LMT_UPB=148, .DM_LMT_LWB=120, .DM_LMT_EN=0, .rsv_17=0}},
        .rccc      ={.bits ={.DM_RCDM_SL=192, .DM_RCCC_EN=0, .rsv_14=0}},
    },
    // IDX_3
    {
        .intp_crs  ={.bits ={.DM_CDG_SL=4, .DM_CDG_OFST=20, .DM_CDG_RAT=16, .DM_CD_KNL=0, .rsv_18=0, .DM_BIN_EO_SEL=0, .DM_BIN_MODE=0, .DM_BYP=0, .DM_MN_MODE=0}},
        .intp_nat  ={.bits ={.DM_HL_OFST=0, .DM_L0_SL=6, .DM_L0_OFST=0, .DM_CD_SLL=3, .DM_CD_SLC=0, .rsv_30=0}},
        .intp_aug  ={.bits ={.DM_DN_OFST=0, .DM_L2_SL=6, .DM_L2_OFST=0, .DM_L1_SL=6, .DM_L1_OFST=0}},
        .luma_lut1 ={.bits ={.DM_LM_Y2=256, .DM_LM_Y1=384, .DM_LM_Y0=511, .rsv_27=0}},
        .luma_lut2 ={.bits ={.DM_LM_Y5=32, .DM_LM_Y4=64, .DM_LM_Y3=128, .rsv_27=0}},
        .sl_ctl    ={.bits ={.DM_SL_EN=0, .DM_SL_HR=16, .DM_SL_Y2=255, .DM_SL_Y1=255, .rsv_22=0}},
        .hftd_ctl  ={.bits ={.DM_CORE_TH1=0, .DM_HD_GN2=0, .DM_HD_GN1=16, .DM_HT_GN2=16, .DM_HT_GN1=16, .rsv_28=0}},
        .nr_str    ={.bits ={.DM_N2_STR=0, .DM_N1_STR=0, .DM_N0_STR=0, .DM_XTK_SL=5, .DM_XTK_OFST=32, .DM_XTK_RAT=16}},
        .nr_act    ={.bits ={.DM_NGR=0, .DM_NSL=5, .DM_N2_OFST=0, .DM_N1_OFST=0, .DM_N0_OFST=0}},
        .hf_str    ={.bits ={.DM_CORE_TH2=0, .DM_HI_RAT=0, .DM_H3_GN=16, .DM_H2_GN=21, .DM_H1_GN=26, .DM_HA_STR=0}},
        .hf_act1   ={.bits ={.DM_H2_UPB=220, .DM_H2_LWB=52, .DM_H1_UPB=80, .DM_H1_LWB=20}},
        .hf_act2   ={.bits ={.DM_HSLL=5, .DM_HSLR=5, .DM_H3_UPB=255, .DM_H3_LWB=52, .rsv_24=0}},
        .clip      ={.bits ={.DM_CLIP_TH=100, .DM_UN_TH=32, .DM_OV_TH=223, .rsv_24=0}},
        .p1_act    ={.bits ={.DM_P1_UPB=85, .DM_P1_LWB=85, .rsv_16=0}},
        .lr_rat    ={.bits ={.DM_LR_RAT=15, .rsv_4=0}},
        .hftd_ctl2 ={.bits ={.DM_HD_GN3=16, .DM_HFRB_GN=16, .rsv_12=0}},
        .est_ctl   ={.bits ={.DM_P2_CLIP=0, .DM_P1_BLD=0, .rsv_6=0}},
        .int_ctl   ={.bits ={.DM_INT_LTH=3, .DM_INT_CDTH=5, .rsv_8=0}},
        .ee        ={.bits ={.DM_HPOS_GN=16, .DM_HNEG_GN=16, .rsv_10=0}},
        .lmt       ={.bits ={.DM_LMT_UPB=148, .DM_LMT_LWB=120, .DM_LMT_EN=0, .rsv_17=0}},
        .rccc      ={.bits ={.DM_RCDM_SL=192, .DM_RCCC_EN=0, .rsv_14=0}},
    },
    // IDX_4
    {
        .intp_crs  ={.bits ={.DM_CDG_SL=4, .DM_CDG_OFST=20, .DM_CDG_RAT=16, .DM_CD_KNL=0, .rsv_18=0, .DM_BIN_EO_SEL=0, .DM_BIN_MODE=0, .DM_BYP=0, .DM_MN_MODE=0}},
        .intp_nat  ={.bits ={.DM_HL_OFST=0, .DM_L0_SL=6, .DM_L0_OFST=0, .DM_CD_SLL=3, .DM_CD_SLC=0, .rsv_30=0}},
        .intp_aug  ={.bits ={.DM_DN_OFST=0, .DM_L2_SL=6, .DM_L2_OFST=0, .DM_L1_SL=6, .DM_L1_OFST=0}},
        .luma_lut1 ={.bits ={.DM_LM_Y2=256, .DM_LM_Y1=384, .DM_LM_Y0=511, .rsv_27=0}},
        .luma_lut2 ={.bits ={.DM_LM_Y5=32, .DM_LM_Y4=64, .DM_LM_Y3=128, .rsv_27=0}},
        .sl_ctl    ={.bits ={.DM_SL_EN=0, .DM_SL_HR=16, .DM_SL_Y2=255, .DM_SL_Y1=255, .rsv_22=0}},
        .hftd_ctl  ={.bits ={.DM_CORE_TH1=0, .DM_HD_GN2=0, .DM_HD_GN1=16, .DM_HT_GN2=16, .DM_HT_GN1=16, .rsv_28=0}},
        .nr_str    ={.bits ={.DM_N2_STR=0, .DM_N1_STR=0, .DM_N0_STR=0, .DM_XTK_SL=5, .DM_XTK_OFST=32, .DM_XTK_RAT=16}},
        .nr_act    ={.bits ={.DM_NGR=0, .DM_NSL=5, .DM_N2_OFST=0, .DM_N1_OFST=0, .DM_N0_OFST=0}},
        .hf_str    ={.bits ={.DM_CORE_TH2=0, .DM_HI_RAT=0, .DM_H3_GN=16, .DM_H2_GN=21, .DM_H1_GN=26, .DM_HA_STR=0}},
        .hf_act1   ={.bits ={.DM_H2_UPB=220, .DM_H2_LWB=52, .DM_H1_UPB=80, .DM_H1_LWB=20}},
        .hf_act2   ={.bits ={.DM_HSLL=5, .DM_HSLR=5, .DM_H3_UPB=255, .DM_H3_LWB=52, .rsv_24=0}},
        .clip      ={.bits ={.DM_CLIP_TH=100, .DM_UN_TH=32, .DM_OV_TH=223, .rsv_24=0}},
        .p1_act    ={.bits ={.DM_P1_UPB=85, .DM_P1_LWB=85, .rsv_16=0}},
        .lr_rat    ={.bits ={.DM_LR_RAT=15, .rsv_4=0}},
        .hftd_ctl2 ={.bits ={.DM_HD_GN3=16, .DM_HFRB_GN=16, .rsv_12=0}},
        .est_ctl   ={.bits ={.DM_P2_CLIP=0, .DM_P1_BLD=0, .rsv_6=0}},
        .int_ctl   ={.bits ={.DM_INT_LTH=3, .DM_INT_CDTH=5, .rsv_8=0}},
        .ee        ={.bits ={.DM_HPOS_GN=16, .DM_HNEG_GN=16, .rsv_10=0}},
        .lmt       ={.bits ={.DM_LMT_UPB=148, .DM_LMT_LWB=120, .DM_LMT_EN=0, .rsv_17=0}},
        .rccc      ={.bits ={.DM_RCDM_SL=192, .DM_RCCC_EN=0, .rsv_14=0}},
    },
    // IDX_5
    {
        .intp_crs  ={.bits ={.DM_CDG_SL=4, .DM_CDG_OFST=20, .DM_CDG_RAT=16, .DM_CD_KNL=0, .rsv_18=0, .DM_BIN_EO_SEL=0, .DM_BIN_MODE=0, .DM_BYP=0, .DM_MN_MODE=0}},
        .intp_nat  ={.bits ={.DM_HL_OFST=0, .DM_L0_SL=6, .DM_L0_OFST=0, .DM_CD_SLL=3, .DM_CD_SLC=0, .rsv_30=0}},
        .intp_aug  ={.bits ={.DM_DN_OFST=0, .DM_L2_SL=6, .DM_L2_OFST=0, .DM_L1_SL=6, .DM_L1_OFST=0}},
        .luma_lut1 ={.bits ={.DM_LM_Y2=256, .DM_LM_Y1=384, .DM_LM_Y0=511, .rsv_27=0}},
        .luma_lut2 ={.bits ={.DM_LM_Y5=32, .DM_LM_Y4=64, .DM_LM_Y3=128, .rsv_27=0}},
        .sl_ctl    ={.bits ={.DM_SL_EN=0, .DM_SL_HR=16, .DM_SL_Y2=255, .DM_SL_Y1=255, .rsv_22=0}},
        .hftd_ctl  ={.bits ={.DM_CORE_TH1=0, .DM_HD_GN2=0, .DM_HD_GN1=16, .DM_HT_GN2=16, .DM_HT_GN1=16, .rsv_28=0}},
        .nr_str    ={.bits ={.DM_N2_STR=0, .DM_N1_STR=0, .DM_N0_STR=0, .DM_XTK_SL=5, .DM_XTK_OFST=32, .DM_XTK_RAT=16}},
        .nr_act    ={.bits ={.DM_NGR=0, .DM_NSL=5, .DM_N2_OFST=0, .DM_N1_OFST=0, .DM_N0_OFST=0}},
        .hf_str    ={.bits ={.DM_CORE_TH2=0, .DM_HI_RAT=0, .DM_H3_GN=16, .DM_H2_GN=21, .DM_H1_GN=26, .DM_HA_STR=0}},
        .hf_act1   ={.bits ={.DM_H2_UPB=220, .DM_H2_LWB=52, .DM_H1_UPB=80, .DM_H1_LWB=20}},
        .hf_act2   ={.bits ={.DM_HSLL=5, .DM_HSLR=5, .DM_H3_UPB=255, .DM_H3_LWB=52, .rsv_24=0}},
        .clip      ={.bits ={.DM_CLIP_TH=100, .DM_UN_TH=32, .DM_OV_TH=223, .rsv_24=0}},
        .p1_act    ={.bits ={.DM_P1_UPB=85, .DM_P1_LWB=85, .rsv_16=0}},
        .lr_rat    ={.bits ={.DM_LR_RAT=15, .rsv_4=0}},
        .hftd_ctl2 ={.bits ={.DM_HD_GN3=16, .DM_HFRB_GN=16, .rsv_12=0}},
        .est_ctl   ={.bits ={.DM_P2_CLIP=0, .DM_P1_BLD=0, .rsv_6=0}},
        .int_ctl   ={.bits ={.DM_INT_LTH=3, .DM_INT_CDTH=5, .rsv_8=0}},
        .ee        ={.bits ={.DM_HPOS_GN=16, .DM_HNEG_GN=16, .rsv_10=0}},
        .lmt       ={.bits ={.DM_LMT_UPB=148, .DM_LMT_LWB=120, .DM_LMT_EN=0, .rsv_17=0}},
        .rccc      ={.bits ={.DM_RCDM_SL=192, .DM_RCCC_EN=0, .rsv_14=0}},
    },
    // IDX_6
    {
        .intp_crs  ={.bits ={.DM_CDG_SL=4, .DM_CDG_OFST=20, .DM_CDG_RAT=16, .DM_CD_KNL=0, .rsv_18=0, .DM_BIN_EO_SEL=0, .DM_BIN_MODE=0, .DM_BYP=0, .DM_MN_MODE=0}},
        .intp_nat  ={.bits ={.DM_HL_OFST=0, .DM_L0_SL=6, .DM_L0_OFST=0, .DM_CD_SLL=3, .DM_CD_SLC=0, .rsv_30=0}},
        .intp_aug  ={.bits ={.DM_DN_OFST=0, .DM_L2_SL=6, .DM_L2_OFST=0, .DM_L1_SL=6, .DM_L1_OFST=0}},
        .luma_lut1 ={.bits ={.DM_LM_Y2=256, .DM_LM_Y1=384, .DM_LM_Y0=511, .rsv_27=0}},
        .luma_lut2 ={.bits ={.DM_LM_Y5=32, .DM_LM_Y4=64, .DM_LM_Y3=128, .rsv_27=0}},
        .sl_ctl    ={.bits ={.DM_SL_EN=0, .DM_SL_HR=16, .DM_SL_Y2=255, .DM_SL_Y1=255, .rsv_22=0}},
        .hftd_ctl  ={.bits ={.DM_CORE_TH1=0, .DM_HD_GN2=0, .DM_HD_GN1=16, .DM_HT_GN2=16, .DM_HT_GN1=16, .rsv_28=0}},
        .nr_str    ={.bits ={.DM_N2_STR=0, .DM_N1_STR=0, .DM_N0_STR=0, .DM_XTK_SL=5, .DM_XTK_OFST=32, .DM_XTK_RAT=16}},
        .nr_act    ={.bits ={.DM_NGR=0, .DM_NSL=5, .DM_N2_OFST=0, .DM_N1_OFST=0, .DM_N0_OFST=0}},
        .hf_str    ={.bits ={.DM_CORE_TH2=0, .DM_HI_RAT=0, .DM_H3_GN=16, .DM_H2_GN=21, .DM_H1_GN=26, .DM_HA_STR=0}},
        .hf_act1   ={.bits ={.DM_H2_UPB=220, .DM_H2_LWB=52, .DM_H1_UPB=80, .DM_H1_LWB=20}},
        .hf_act2   ={.bits ={.DM_HSLL=5, .DM_HSLR=5, .DM_H3_UPB=255, .DM_H3_LWB=52, .rsv_24=0}},
        .clip      ={.bits ={.DM_CLIP_TH=100, .DM_UN_TH=32, .DM_OV_TH=223, .rsv_24=0}},
        .p1_act    ={.bits ={.DM_P1_UPB=85, .DM_P1_LWB=85, .rsv_16=0}},
        .lr_rat    ={.bits ={.DM_LR_RAT=15, .rsv_4=0}},
        .hftd_ctl2 ={.bits ={.DM_HD_GN3=16, .DM_HFRB_GN=16, .rsv_12=0}},
        .est_ctl   ={.bits ={.DM_P2_CLIP=0, .DM_P1_BLD=0, .rsv_6=0}},
        .int_ctl   ={.bits ={.DM_INT_LTH=3, .DM_INT_CDTH=5, .rsv_8=0}},
        .ee        ={.bits ={.DM_HPOS_GN=16, .DM_HNEG_GN=16, .rsv_10=0}},
        .lmt       ={.bits ={.DM_LMT_UPB=148, .DM_LMT_LWB=120, .DM_LMT_EN=0, .rsv_17=0}},
        .rccc      ={.bits ={.DM_RCDM_SL=192, .DM_RCCC_EN=0, .rsv_14=0}},
    },
    // IDX_7
    {
        .intp_crs  ={.bits ={.DM_CDG_SL=4, .DM_CDG_OFST=20, .DM_CDG_RAT=16, .DM_CD_KNL=0, .rsv_18=0, .DM_BIN_EO_SEL=0, .DM_BIN_MODE=0, .DM_BYP=0, .DM_MN_MODE=0}},
        .intp_nat  ={.bits ={.DM_HL_OFST=0, .DM_L0_SL=6, .DM_L0_OFST=0, .DM_CD_SLL=3, .DM_CD_SLC=0, .rsv_30=0}},
        .intp_aug  ={.bits ={.DM_DN_OFST=0, .DM_L2_SL=6, .DM_L2_OFST=0, .DM_L1_SL=6, .DM_L1_OFST=0}},
        .luma_lut1 ={.bits ={.DM_LM_Y2=256, .DM_LM_Y1=384, .DM_LM_Y0=511, .rsv_27=0}},
        .luma_lut2 ={.bits ={.DM_LM_Y5=32, .DM_LM_Y4=64, .DM_LM_Y3=128, .rsv_27=0}},
        .sl_ctl    ={.bits ={.DM_SL_EN=0, .DM_SL_HR=16, .DM_SL_Y2=255, .DM_SL_Y1=255, .rsv_22=0}},
        .hftd_ctl  ={.bits ={.DM_CORE_TH1=0, .DM_HD_GN2=0, .DM_HD_GN1=16, .DM_HT_GN2=16, .DM_HT_GN1=16, .rsv_28=0}},
        .nr_str    ={.bits ={.DM_N2_STR=0, .DM_N1_STR=0, .DM_N0_STR=0, .DM_XTK_SL=5, .DM_XTK_OFST=32, .DM_XTK_RAT=16}},
        .nr_act    ={.bits ={.DM_NGR=0, .DM_NSL=5, .DM_N2_OFST=0, .DM_N1_OFST=0, .DM_N0_OFST=0}},
        .hf_str    ={.bits ={.DM_CORE_TH2=0, .DM_HI_RAT=0, .DM_H3_GN=16, .DM_H2_GN=21, .DM_H1_GN=26, .DM_HA_STR=0}},
        .hf_act1   ={.bits ={.DM_H2_UPB=220, .DM_H2_LWB=52, .DM_H1_UPB=80, .DM_H1_LWB=20}},
        .hf_act2   ={.bits ={.DM_HSLL=5, .DM_HSLR=5, .DM_H3_UPB=255, .DM_H3_LWB=52, .rsv_24=0}},
        .clip      ={.bits ={.DM_CLIP_TH=100, .DM_UN_TH=32, .DM_OV_TH=223, .rsv_24=0}},
        .p1_act    ={.bits ={.DM_P1_UPB=85, .DM_P1_LWB=85, .rsv_16=0}},
        .lr_rat    ={.bits ={.DM_LR_RAT=15, .rsv_4=0}},
        .hftd_ctl2 ={.bits ={.DM_HD_GN3=16, .DM_HFRB_GN=16, .rsv_12=0}},
        .est_ctl   ={.bits ={.DM_P2_CLIP=0, .DM_P1_BLD=0, .rsv_6=0}},
        .int_ctl   ={.bits ={.DM_INT_LTH=3, .DM_INT_CDTH=5, .rsv_8=0}},
        .ee        ={.bits ={.DM_HPOS_GN=16, .DM_HNEG_GN=16, .rsv_10=0}},
        .lmt       ={.bits ={.DM_LMT_UPB=148, .DM_LMT_LWB=120, .DM_LMT_EN=0, .rsv_17=0}},
        .rccc      ={.bits ={.DM_RCDM_SL=192, .DM_RCCC_EN=0, .rsv_14=0}},
    },
    // IDX_8
    {
        .intp_crs  ={.bits ={.DM_CDG_SL=4, .DM_CDG_OFST=20, .DM_CDG_RAT=16, .DM_CD_KNL=0, .rsv_18=0, .DM_BIN_EO_SEL=0, .DM_BIN_MODE=0, .DM_BYP=0, .DM_MN_MODE=0}},
        .intp_nat  ={.bits ={.DM_HL_OFST=0, .DM_L0_SL=6, .DM_L0_OFST=0, .DM_CD_SLL=3, .DM_CD_SLC=0, .rsv_30=0}},
        .intp_aug  ={.bits ={.DM_DN_OFST=0, .DM_L2_SL=6, .DM_L2_OFST=0, .DM_L1_SL=6, .DM_L1_OFST=0}},
        .luma_lut1 ={.bits ={.DM_LM_Y2=256, .DM_LM_Y1=384, .DM_LM_Y0=511, .rsv_27=0}},
        .luma_lut2 ={.bits ={.DM_LM_Y5=32, .DM_LM_Y4=64, .DM_LM_Y3=128, .rsv_27=0}},
        .sl_ctl    ={.bits ={.DM_SL_EN=0, .DM_SL_HR=16, .DM_SL_Y2=255, .DM_SL_Y1=255, .rsv_22=0}},
        .hftd_ctl  ={.bits ={.DM_CORE_TH1=0, .DM_HD_GN2=0, .DM_HD_GN1=16, .DM_HT_GN2=16, .DM_HT_GN1=16, .rsv_28=0}},
        .nr_str    ={.bits ={.DM_N2_STR=0, .DM_N1_STR=0, .DM_N0_STR=0, .DM_XTK_SL=5, .DM_XTK_OFST=32, .DM_XTK_RAT=16}},
        .nr_act    ={.bits ={.DM_NGR=0, .DM_NSL=5, .DM_N2_OFST=0, .DM_N1_OFST=0, .DM_N0_OFST=0}},
        .hf_str    ={.bits ={.DM_CORE_TH2=0, .DM_HI_RAT=0, .DM_H3_GN=16, .DM_H2_GN=21, .DM_H1_GN=26, .DM_HA_STR=0}},
        .hf_act1   ={.bits ={.DM_H2_UPB=220, .DM_H2_LWB=52, .DM_H1_UPB=80, .DM_H1_LWB=20}},
        .hf_act2   ={.bits ={.DM_HSLL=5, .DM_HSLR=5, .DM_H3_UPB=255, .DM_H3_LWB=52, .rsv_24=0}},
        .clip      ={.bits ={.DM_CLIP_TH=100, .DM_UN_TH=32, .DM_OV_TH=223, .rsv_24=0}},
        .p1_act    ={.bits ={.DM_P1_UPB=85, .DM_P1_LWB=85, .rsv_16=0}},
        .lr_rat    ={.bits ={.DM_LR_RAT=15, .rsv_4=0}},
        .hftd_ctl2 ={.bits ={.DM_HD_GN3=16, .DM_HFRB_GN=16, .rsv_12=0}},
        .est_ctl   ={.bits ={.DM_P2_CLIP=0, .DM_P1_BLD=0, .rsv_6=0}},
        .int_ctl   ={.bits ={.DM_INT_LTH=3, .DM_INT_CDTH=5, .rsv_8=0}},
        .ee        ={.bits ={.DM_HPOS_GN=16, .DM_HNEG_GN=16, .rsv_10=0}},
        .lmt       ={.bits ={.DM_LMT_UPB=148, .DM_LMT_LWB=120, .DM_LMT_EN=0, .rsv_17=0}},
        .rccc      ={.bits ={.DM_RCDM_SL=192, .DM_RCCC_EN=0, .rsv_14=0}},
    },
    // IDX_9
    {
        .intp_crs  ={.bits ={.DM_CDG_SL=4, .DM_CDG_OFST=20, .DM_CDG_RAT=16, .DM_CD_KNL=0, .rsv_18=0, .DM_BIN_EO_SEL=0, .DM_BIN_MODE=0, .DM_BYP=0, .DM_MN_MODE=0}},
        .intp_nat  ={.bits ={.DM_HL_OFST=0, .DM_L0_SL=6, .DM_L0_OFST=0, .DM_CD_SLL=3, .DM_CD_SLC=0, .rsv_30=0}},
        .intp_aug  ={.bits ={.DM_DN_OFST=0, .DM_L2_SL=6, .DM_L2_OFST=0, .DM_L1_SL=6, .DM_L1_OFST=0}},
        .luma_lut1 ={.bits ={.DM_LM_Y2=256, .DM_LM_Y1=384, .DM_LM_Y0=511, .rsv_27=0}},
        .luma_lut2 ={.bits ={.DM_LM_Y5=32, .DM_LM_Y4=64, .DM_LM_Y3=128, .rsv_27=0}},
        .sl_ctl    ={.bits ={.DM_SL_EN=0, .DM_SL_HR=16, .DM_SL_Y2=255, .DM_SL_Y1=255, .rsv_22=0}},
        .hftd_ctl  ={.bits ={.DM_CORE_TH1=0, .DM_HD_GN2=0, .DM_HD_GN1=16, .DM_HT_GN2=16, .DM_HT_GN1=16, .rsv_28=0}},
        .nr_str    ={.bits ={.DM_N2_STR=0, .DM_N1_STR=0, .DM_N0_STR=0, .DM_XTK_SL=5, .DM_XTK_OFST=32, .DM_XTK_RAT=16}},
        .nr_act    ={.bits ={.DM_NGR=0, .DM_NSL=5, .DM_N2_OFST=0, .DM_N1_OFST=0, .DM_N0_OFST=0}},
        .hf_str    ={.bits ={.DM_CORE_TH2=0, .DM_HI_RAT=0, .DM_H3_GN=16, .DM_H2_GN=21, .DM_H1_GN=26, .DM_HA_STR=0}},
        .hf_act1   ={.bits ={.DM_H2_UPB=220, .DM_H2_LWB=52, .DM_H1_UPB=80, .DM_H1_LWB=20}},
        .hf_act2   ={.bits ={.DM_HSLL=5, .DM_HSLR=5, .DM_H3_UPB=255, .DM_H3_LWB=52, .rsv_24=0}},
        .clip      ={.bits ={.DM_CLIP_TH=100, .DM_UN_TH=32, .DM_OV_TH=223, .rsv_24=0}},
        .p1_act    ={.bits ={.DM_P1_UPB=85, .DM_P1_LWB=85, .rsv_16=0}},
        .lr_rat    ={.bits ={.DM_LR_RAT=15, .rsv_4=0}},
        .hftd_ctl2 ={.bits ={.DM_HD_GN3=16, .DM_HFRB_GN=16, .rsv_12=0}},
        .est_ctl   ={.bits ={.DM_P2_CLIP=0, .DM_P1_BLD=0, .rsv_6=0}},
        .int_ctl   ={.bits ={.DM_INT_LTH=3, .DM_INT_CDTH=5, .rsv_8=0}},
        .ee        ={.bits ={.DM_HPOS_GN=16, .DM_HNEG_GN=16, .rsv_10=0}},
        .lmt       ={.bits ={.DM_LMT_UPB=148, .DM_LMT_LWB=120, .DM_LMT_EN=0, .rsv_17=0}},
        .rccc      ={.bits ={.DM_RCDM_SL=192, .DM_RCCC_EN=0, .rsv_14=0}},
    },
    // IDX_10
    {
        .intp_crs  ={.bits ={.DM_CDG_SL=4, .DM_CDG_OFST=20, .DM_CDG_RAT=16, .DM_CD_KNL=0, .rsv_18=0, .DM_BIN_EO_SEL=0, .DM_BIN_MODE=0, .DM_BYP=0, .DM_MN_MODE=0}},
        .intp_nat  ={.bits ={.DM_HL_OFST=0, .DM_L0_SL=6, .DM_L0_OFST=0, .DM_CD_SLL=3, .DM_CD_SLC=0, .rsv_30=0}},
        .intp_aug  ={.bits ={.DM_DN_OFST=0, .DM_L2_SL=6, .DM_L2_OFST=0, .DM_L1_SL=6, .DM_L1_OFST=0}},
        .luma_lut1 ={.bits ={.DM_LM_Y2=256, .DM_LM_Y1=384, .DM_LM_Y0=511, .rsv_27=0}},
        .luma_lut2 ={.bits ={.DM_LM_Y5=32, .DM_LM_Y4=64, .DM_LM_Y3=128, .rsv_27=0}},
        .sl_ctl    ={.bits ={.DM_SL_EN=0, .DM_SL_HR=16, .DM_SL_Y2=255, .DM_SL_Y1=255, .rsv_22=0}},
        .hftd_ctl  ={.bits ={.DM_CORE_TH1=0, .DM_HD_GN2=0, .DM_HD_GN1=16, .DM_HT_GN2=16, .DM_HT_GN1=16, .rsv_28=0}},
        .nr_str    ={.bits ={.DM_N2_STR=0, .DM_N1_STR=0, .DM_N0_STR=0, .DM_XTK_SL=5, .DM_XTK_OFST=32, .DM_XTK_RAT=16}},
        .nr_act    ={.bits ={.DM_NGR=0, .DM_NSL=5, .DM_N2_OFST=0, .DM_N1_OFST=0, .DM_N0_OFST=0}},
        .hf_str    ={.bits ={.DM_CORE_TH2=0, .DM_HI_RAT=0, .DM_H3_GN=16, .DM_H2_GN=21, .DM_H1_GN=26, .DM_HA_STR=0}},
        .hf_act1   ={.bits ={.DM_H2_UPB=220, .DM_H2_LWB=52, .DM_H1_UPB=80, .DM_H1_LWB=20}},
        .hf_act2   ={.bits ={.DM_HSLL=5, .DM_HSLR=5, .DM_H3_UPB=255, .DM_H3_LWB=52, .rsv_24=0}},
        .clip      ={.bits ={.DM_CLIP_TH=100, .DM_UN_TH=32, .DM_OV_TH=223, .rsv_24=0}},
        .p1_act    ={.bits ={.DM_P1_UPB=85, .DM_P1_LWB=85, .rsv_16=0}},
        .lr_rat    ={.bits ={.DM_LR_RAT=15, .rsv_4=0}},
        .hftd_ctl2 ={.bits ={.DM_HD_GN3=16, .DM_HFRB_GN=16, .rsv_12=0}},
        .est_ctl   ={.bits ={.DM_P2_CLIP=0, .DM_P1_BLD=0, .rsv_6=0}},
        .int_ctl   ={.bits ={.DM_INT_LTH=3, .DM_INT_CDTH=5, .rsv_8=0}},
        .ee        ={.bits ={.DM_HPOS_GN=16, .DM_HNEG_GN=16, .rsv_10=0}},
        .lmt       ={.bits ={.DM_LMT_UPB=148, .DM_LMT_LWB=120, .DM_LMT_EN=0, .rsv_17=0}},
        .rccc      ={.bits ={.DM_RCDM_SL=192, .DM_RCCC_EN=0, .rsv_14=0}},
    },
    // IDX_11
    {
        .intp_crs  ={.bits ={.DM_CDG_SL=4, .DM_CDG_OFST=20, .DM_CDG_RAT=16, .DM_CD_KNL=0, .rsv_18=0, .DM_BIN_EO_SEL=0, .DM_BIN_MODE=0, .DM_BYP=0, .DM_MN_MODE=0}},
        .intp_nat  ={.bits ={.DM_HL_OFST=0, .DM_L0_SL=6, .DM_L0_OFST=0, .DM_CD_SLL=3, .DM_CD_SLC=0, .rsv_30=0}},
        .intp_aug  ={.bits ={.DM_DN_OFST=0, .DM_L2_SL=6, .DM_L2_OFST=0, .DM_L1_SL=6, .DM_L1_OFST=0}},
        .luma_lut1 ={.bits ={.DM_LM_Y2=256, .DM_LM_Y1=384, .DM_LM_Y0=511, .rsv_27=0}},
        .luma_lut2 ={.bits ={.DM_LM_Y5=32, .DM_LM_Y4=64, .DM_LM_Y3=128, .rsv_27=0}},
        .sl_ctl    ={.bits ={.DM_SL_EN=0, .DM_SL_HR=16, .DM_SL_Y2=255, .DM_SL_Y1=255, .rsv_22=0}},
        .hftd_ctl  ={.bits ={.DM_CORE_TH1=0, .DM_HD_GN2=0, .DM_HD_GN1=16, .DM_HT_GN2=16, .DM_HT_GN1=16, .rsv_28=0}},
        .nr_str    ={.bits ={.DM_N2_STR=0, .DM_N1_STR=0, .DM_N0_STR=0, .DM_XTK_SL=5, .DM_XTK_OFST=32, .DM_XTK_RAT=16}},
        .nr_act    ={.bits ={.DM_NGR=0, .DM_NSL=5, .DM_N2_OFST=0, .DM_N1_OFST=0, .DM_N0_OFST=0}},
        .hf_str    ={.bits ={.DM_CORE_TH2=0, .DM_HI_RAT=0, .DM_H3_GN=16, .DM_H2_GN=21, .DM_H1_GN=26, .DM_HA_STR=0}},
        .hf_act1   ={.bits ={.DM_H2_UPB=220, .DM_H2_LWB=52, .DM_H1_UPB=80, .DM_H1_LWB=20}},
        .hf_act2   ={.bits ={.DM_HSLL=5, .DM_HSLR=5, .DM_H3_UPB=255, .DM_H3_LWB=52, .rsv_24=0}},
        .clip      ={.bits ={.DM_CLIP_TH=100, .DM_UN_TH=32, .DM_OV_TH=223, .rsv_24=0}},
        .p1_act    ={.bits ={.DM_P1_UPB=85, .DM_P1_LWB=85, .rsv_16=0}},
        .lr_rat    ={.bits ={.DM_LR_RAT=15, .rsv_4=0}},
        .hftd_ctl2 ={.bits ={.DM_HD_GN3=16, .DM_HFRB_GN=16, .rsv_12=0}},
        .est_ctl   ={.bits ={.DM_P2_CLIP=0, .DM_P1_BLD=0, .rsv_6=0}},
        .int_ctl   ={.bits ={.DM_INT_LTH=3, .DM_INT_CDTH=5, .rsv_8=0}},
        .ee        ={.bits ={.DM_HPOS_GN=16, .DM_HNEG_GN=16, .rsv_10=0}},
        .lmt       ={.bits ={.DM_LMT_UPB=148, .DM_LMT_LWB=120, .DM_LMT_EN=0, .rsv_17=0}},
        .rccc      ={.bits ={.DM_RCDM_SL=192, .DM_RCCC_EN=0, .rsv_14=0}},
    },
    // IDX_12
    {
        .intp_crs  ={.bits ={.DM_CDG_SL=4, .DM_CDG_OFST=20, .DM_CDG_RAT=16, .DM_CD_KNL=0, .rsv_18=0, .DM_BIN_EO_SEL=0, .DM_BIN_MODE=0, .DM_BYP=0, .DM_MN_MODE=0}},
        .intp_nat  ={.bits ={.DM_HL_OFST=0, .DM_L0_SL=6, .DM_L0_OFST=0, .DM_CD_SLL=3, .DM_CD_SLC=0, .rsv_30=0}},
        .intp_aug  ={.bits ={.DM_DN_OFST=0, .DM_L2_SL=6, .DM_L2_OFST=0, .DM_L1_SL=6, .DM_L1_OFST=0}},
        .luma_lut1 ={.bits ={.DM_LM_Y2=256, .DM_LM_Y1=384, .DM_LM_Y0=511, .rsv_27=0}},
        .luma_lut2 ={.bits ={.DM_LM_Y5=32, .DM_LM_Y4=64, .DM_LM_Y3=128, .rsv_27=0}},
        .sl_ctl    ={.bits ={.DM_SL_EN=0, .DM_SL_HR=16, .DM_SL_Y2=255, .DM_SL_Y1=255, .rsv_22=0}},
        .hftd_ctl  ={.bits ={.DM_CORE_TH1=0, .DM_HD_GN2=0, .DM_HD_GN1=16, .DM_HT_GN2=16, .DM_HT_GN1=16, .rsv_28=0}},
        .nr_str    ={.bits ={.DM_N2_STR=0, .DM_N1_STR=0, .DM_N0_STR=0, .DM_XTK_SL=5, .DM_XTK_OFST=32, .DM_XTK_RAT=16}},
        .nr_act    ={.bits ={.DM_NGR=0, .DM_NSL=5, .DM_N2_OFST=0, .DM_N1_OFST=0, .DM_N0_OFST=0}},
        .hf_str    ={.bits ={.DM_CORE_TH2=0, .DM_HI_RAT=0, .DM_H3_GN=16, .DM_H2_GN=21, .DM_H1_GN=26, .DM_HA_STR=0}},
        .hf_act1   ={.bits ={.DM_H2_UPB=220, .DM_H2_LWB=52, .DM_H1_UPB=80, .DM_H1_LWB=20}},
        .hf_act2   ={.bits ={.DM_HSLL=5, .DM_HSLR=5, .DM_H3_UPB=255, .DM_H3_LWB=52, .rsv_24=0}},
        .clip      ={.bits ={.DM_CLIP_TH=100, .DM_UN_TH=32, .DM_OV_TH=223, .rsv_24=0}},
        .p1_act    ={.bits ={.DM_P1_UPB=85, .DM_P1_LWB=85, .rsv_16=0}},
        .lr_rat    ={.bits ={.DM_LR_RAT=15, .rsv_4=0}},
        .hftd_ctl2 ={.bits ={.DM_HD_GN3=16, .DM_HFRB_GN=16, .rsv_12=0}},
        .est_ctl   ={.bits ={.DM_P2_CLIP=0, .DM_P1_BLD=0, .rsv_6=0}},
        .int_ctl   ={.bits ={.DM_INT_LTH=3, .DM_INT_CDTH=5, .rsv_8=0}},
        .ee        ={.bits ={.DM_HPOS_GN=16, .DM_HNEG_GN=16, .rsv_10=0}},
        .lmt       ={.bits ={.DM_LMT_UPB=148, .DM_LMT_LWB=120, .DM_LMT_EN=0, .rsv_17=0}},
        .rccc      ={.bits ={.DM_RCDM_SL=192, .DM_RCCC_EN=0, .rsv_14=0}},
    },
};
