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

#define CCM_BASE                                                     CCM_CCM_BASE
#define CCM_R3_BASE                                                  CCM_R3_CCM_BASE

const ISP_NVRAM_MULTI_CCM_STRUCT CCM_BASE[6] = {
    // IDX_0
    {
    
        .CCM_CT_valid_NUM = 5,
    
        .CCM_Coef = {1, 2, 2},
    
        .CCM_Reg =
        {
            {.set={//CT_00
            0x1E7F0433, 0x00001F4E, 0x03751EE9, 0x00001FA2, 0x1C841E9F, 0x000006DD
            }},
            {.set={//CT_01
            0x1E7F0433, 0x00001F4E, 0x03751EE9, 0x00001FA2, 0x1C841E9F, 0x000006DD
            }},
            {.set={//CT_02
            0x1DFF04D8, 0x00001F29, 0x038C1EF6, 0x00001F7E, 0x1DB91F7D, 0x000004CA
            }},
            {.set={//CT_03
            0x1CAB05D8, 0x00001F7D, 0x03871ECC, 0x00001FAD, 0x1DC21F6D, 0x000004D1
            }},
            {.set={//CT_04
            0x1D8C04F2, 0x00001F82, 0x035F1F4F, 0x00001F52, 0x1E221FC3, 0x0000041B
            }},
            {.set={//CT_05
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_06
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_07
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_08
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_09
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }}
        },
    
        .AWBGain =
        {
            {//CT_00
            518,  // i4R
                512,    // i4G
            1139  // i4B
            },
            {//CT_01
            518,  // i4R
                512,    // i4G
            1139  // i4B
            },
            {//CT_02
            700,  // i4R
                512,    // i4G
            1012  // i4B
            },
            {//CT_03
            783,  // i4R
                512,    // i4G
            1095  // i4B
            },
            {//CT_04
            868,  // i4R
                512,    // i4G
            708  // i4B
            },
            {//CT_05
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_06
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_07
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_08
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_09
                512,    // i4R
                512,    // i4G
                512     // i4B
            }
        }
    },
    // IDX_1
    {
    
        .CCM_CT_valid_NUM = 5,
    
        .CCM_Coef = {1, 2, 2},
    
        .CCM_Reg =
        {
            {.set={//CT_00
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_01
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_02
                0x1E7403C2, 0x00001FCA, 0x02BC1F6D, 0x00001FD7, 0x1EB41FDF, 0x0000036D
            }},
            {.set={//CT_03
                0x1DE4043E, 0x00001FDE, 0x02C01F43, 0x00001FFD, 0x1ECF1FE2, 0x0000034F
            }},
            {.set={//CT_04
                0x1EA2034F, 0x0000000F, 0x02941FA4, 0x00001FC8, 0x1EE21FFD, 0x00000321
            }},
            {.set={//CT_05
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_06
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_07
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_08
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_09
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }}
        },
    
        .AWBGain =
        {
            {//CT_00
                512,    // i4R
                512,    // i4G
               1482     // i4B
            },
            {//CT_01
                562,    // i4R
                512,    // i4G
               1247     // i4B
            },
            {//CT_02
                817,    // i4R
                512,    // i4G
               1072     // i4B
            },
            {//CT_03
                930,    // i4R
                512,    // i4G
               1159     // i4B
            },
            {//CT_04
               1001,    // i4R
                512,    // i4G
                713     // i4B
            },
            {//CT_05
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_06
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_07
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_08
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_09
                512,    // i4R
                512,    // i4G
                512     // i4B
            }
        }
    },
    // IDX_2
    {
    
        .CCM_CT_valid_NUM = 5,
    
        .CCM_Coef = {1, 2, 2},
    
        .CCM_Reg =
        {
            {.set={//CT_00
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_01
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_02
                0x1E7403C2, 0x00001FCA, 0x02BC1F6D, 0x00001FD7, 0x1EB41FDF, 0x0000036D
            }},
            {.set={//CT_03
                0x1DE4043E, 0x00001FDE, 0x02C01F43, 0x00001FFD, 0x1ECF1FE2, 0x0000034F
            }},
            {.set={//CT_04
                0x1EA2034F, 0x0000000F, 0x02941FA4, 0x00001FC8, 0x1EE21FFD, 0x00000321
            }},
            {.set={//CT_05
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_06
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_07
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_08
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_09
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }}
        },
    
        .AWBGain =
        {
            {//CT_00
                512,    // i4R
                512,    // i4G
               1482     // i4B
            },
            {//CT_01
                562,    // i4R
                512,    // i4G
               1247     // i4B
            },
            {//CT_02
                817,    // i4R
                512,    // i4G
               1072     // i4B
            },
            {//CT_03
                930,    // i4R
                512,    // i4G
               1159     // i4B
            },
            {//CT_04
               1001,    // i4R
                512,    // i4G
                713     // i4B
            },
            {//CT_05
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_06
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_07
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_08
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_09
                512,    // i4R
                512,    // i4G
                512     // i4B
            }
        }
    },
    // IDX_3
    {
    
        .CCM_CT_valid_NUM = 5,
    
        .CCM_Coef = {1, 2, 2},
    
        .CCM_Reg =
        {
            {.set={//CT_00
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_01
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_02
                0x1E7403C2, 0x00001FCA, 0x02BC1F6D, 0x00001FD7, 0x1EB41FDF, 0x0000036D
            }},
            {.set={//CT_03
                0x1DE4043E, 0x00001FDE, 0x02C01F43, 0x00001FFD, 0x1ECF1FE2, 0x0000034F
            }},
            {.set={//CT_04
                0x1EA2034F, 0x0000000F, 0x02941FA4, 0x00001FC8, 0x1EE21FFD, 0x00000321
            }},
            {.set={//CT_05
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_06
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_07
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_08
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_09
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }}
        },
    
        .AWBGain =
        {
            {//CT_00
                512,    // i4R
                512,    // i4G
               1482     // i4B
            },
            {//CT_01
                562,    // i4R
                512,    // i4G
               1247     // i4B
            },
            {//CT_02
                817,    // i4R
                512,    // i4G
               1072     // i4B
            },
            {//CT_03
                930,    // i4R
                512,    // i4G
               1159     // i4B
            },
            {//CT_04
               1001,    // i4R
                512,    // i4G
                713     // i4B
            },
            {//CT_05
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_06
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_07
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_08
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_09
                512,    // i4R
                512,    // i4G
                512     // i4B
            }
        }
    },
    // IDX_4
    {
    
        .CCM_CT_valid_NUM = 5,
    
        .CCM_Coef = {1, 2, 2},
    
        .CCM_Reg =
        {
            {.set={//CT_00
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_01
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_02
                0x1E7403C2, 0x00001FCA, 0x02BC1F6D, 0x00001FD7, 0x1EB41FDF, 0x0000036D
            }},
            {.set={//CT_03
                0x1DE4043E, 0x00001FDE, 0x02C01F43, 0x00001FFD, 0x1ECF1FE2, 0x0000034F
            }},
            {.set={//CT_04
                0x1EA2034F, 0x0000000F, 0x02941FA4, 0x00001FC8, 0x1EE21FFD, 0x00000321
            }},
            {.set={//CT_05
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_06
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_07
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_08
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_09
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }}
        },
    
        .AWBGain =
        {
            {//CT_00
                512,    // i4R
                512,    // i4G
               1482     // i4B
            },
            {//CT_01
                562,    // i4R
                512,    // i4G
               1247     // i4B
            },
            {//CT_02
                817,    // i4R
                512,    // i4G
               1072     // i4B
            },
            {//CT_03
                930,    // i4R
                512,    // i4G
               1159     // i4B
            },
            {//CT_04
               1001,    // i4R
                512,    // i4G
                713     // i4B
            },
            {//CT_05
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_06
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_07
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_08
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_09
                512,    // i4R
                512,    // i4G
                512     // i4B
            }
        }
    },
    // IDX_5
    {
    
        .CCM_CT_valid_NUM = 5,
    
        .CCM_Coef = {1, 2, 2},
    
        .CCM_Reg =
        {
            {.set={//CT_00
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_01
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_02
                0x1E7403C2, 0x00001FCA, 0x02BC1F6D, 0x00001FD7, 0x1EB41FDF, 0x0000036D
            }},
            {.set={//CT_03
                0x1DE4043E, 0x00001FDE, 0x02C01F43, 0x00001FFD, 0x1ECF1FE2, 0x0000034F
            }},
            {.set={//CT_04
                0x1E240402, 0x00001FDA, 0x02F41F5D, 0x00001FAF, 0x1E7F1FD4, 0x000003AD
            }},
            {.set={//CT_05
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_06
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_07
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_08
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_09
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }}
        },
    
        .AWBGain =
        {
            {//CT_00
                512,    // i4R
                512,    // i4G
               1482     // i4B
            },
            {//CT_01
                562,    // i4R
                512,    // i4G
               1247     // i4B
            },
            {//CT_02
                817,    // i4R
                512,    // i4G
               1072     // i4B
            },
            {//CT_03
                930,    // i4R
                512,    // i4G
               1159     // i4B
            },
            {//CT_04
               1001,    // i4R
                512,    // i4G
                713     // i4B
            },
            {//CT_05
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_06
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_07
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_08
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_09
                512,    // i4R
                512,    // i4G
                512     // i4B
            }
        }
    },
};
const ISP_NVRAM_MULTI_CCM_STRUCT CCM_R3_BASE[6] = {
    // IDX_0
    {
    
        .CCM_CT_valid_NUM = 5,
    
        .CCM_Coef = {1, 2, 2},
    
        .CCM_Reg =
        {
            {.set={//CT_00
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_01
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_02
                0x1E7403C2, 0x00001FCA, 0x02BC1F6D, 0x00001FD7, 0x1EB41FDF, 0x0000036D
            }},
            {.set={//CT_03
                0x1DE4043E, 0x00001FDE, 0x02C01F43, 0x00001FFD, 0x1ECF1FE2, 0x0000034F
            }},
            {.set={//CT_04
                0x1EA2034F, 0x0000000F, 0x02941FA4, 0x00001FC8, 0x1EE21FFD, 0x00000321
            }},
            {.set={//CT_05
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_06
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_07
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_08
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_09
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }}
        },
    
        .AWBGain =
        {
            {//CT_00
                512,    // i4R
                512,    // i4G
               1482     // i4B
            },
            {//CT_01
                562,    // i4R
                512,    // i4G
               1247     // i4B
            },
            {//CT_02
                817,    // i4R
                512,    // i4G
               1072     // i4B
            },
            {//CT_03
                930,    // i4R
                512,    // i4G
               1159     // i4B
            },
            {//CT_04
               1001,    // i4R
                512,    // i4G
                713     // i4B
            },
            {//CT_05
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_06
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_07
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_08
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_09
                512,    // i4R
                512,    // i4G
                512     // i4B
            }
        }
    },
    // IDX_1
    {
    
        .CCM_CT_valid_NUM = 5,
    
        .CCM_Coef = {1, 2, 2},
    
        .CCM_Reg =
        {
            {.set={//CT_00
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_01
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_02
                0x1E7403C2, 0x00001FCA, 0x02BC1F6D, 0x00001FD7, 0x1EB41FDF, 0x0000036D
            }},
            {.set={//CT_03
                0x1DE4043E, 0x00001FDE, 0x02C01F43, 0x00001FFD, 0x1ECF1FE2, 0x0000034F
            }},
            {.set={//CT_04
                0x1EA2034F, 0x0000000F, 0x02941FA4, 0x00001FC8, 0x1EE21FFD, 0x00000321
            }},
            {.set={//CT_05
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_06
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_07
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_08
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_09
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }}
        },
    
        .AWBGain =
        {
            {//CT_00
                512,    // i4R
                512,    // i4G
               1482     // i4B
            },
            {//CT_01
                562,    // i4R
                512,    // i4G
               1247     // i4B
            },
            {//CT_02
                817,    // i4R
                512,    // i4G
               1072     // i4B
            },
            {//CT_03
                930,    // i4R
                512,    // i4G
               1159     // i4B
            },
            {//CT_04
               1001,    // i4R
                512,    // i4G
                713     // i4B
            },
            {//CT_05
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_06
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_07
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_08
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_09
                512,    // i4R
                512,    // i4G
                512     // i4B
            }
        }
    },
    // IDX_2
    {
    
        .CCM_CT_valid_NUM = 5,
    
        .CCM_Coef = {1, 2, 2},
    
        .CCM_Reg =
        {
            {.set={//CT_00
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_01
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_02
                0x1E7403C2, 0x00001FCA, 0x02BC1F6D, 0x00001FD7, 0x1EB41FDF, 0x0000036D
            }},
            {.set={//CT_03
                0x1DE4043E, 0x00001FDE, 0x02C01F43, 0x00001FFD, 0x1ECF1FE2, 0x0000034F
            }},
            {.set={//CT_04
                0x1EA2034F, 0x0000000F, 0x02941FA4, 0x00001FC8, 0x1EE21FFD, 0x00000321
            }},
            {.set={//CT_05
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_06
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_07
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_08
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_09
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }}
        },
    
        .AWBGain =
        {
            {//CT_00
                512,    // i4R
                512,    // i4G
               1482     // i4B
            },
            {//CT_01
                562,    // i4R
                512,    // i4G
               1247     // i4B
            },
            {//CT_02
                817,    // i4R
                512,    // i4G
               1072     // i4B
            },
            {//CT_03
                930,    // i4R
                512,    // i4G
               1159     // i4B
            },
            {//CT_04
               1001,    // i4R
                512,    // i4G
                713     // i4B
            },
            {//CT_05
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_06
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_07
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_08
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_09
                512,    // i4R
                512,    // i4G
                512     // i4B
            }
        }
    },
    // IDX_3
    {
    
        .CCM_CT_valid_NUM = 5,
    
        .CCM_Coef = {1, 2, 2},
    
        .CCM_Reg =
        {
            {.set={//CT_00
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_01
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_02
                0x1E7403C2, 0x00001FCA, 0x02BC1F6D, 0x00001FD7, 0x1EB41FDF, 0x0000036D
            }},
            {.set={//CT_03
                0x1DE4043E, 0x00001FDE, 0x02C01F43, 0x00001FFD, 0x1ECF1FE2, 0x0000034F
            }},
            {.set={//CT_04
                0x1EA2034F, 0x0000000F, 0x02941FA4, 0x00001FC8, 0x1EE21FFD, 0x00000321
            }},
            {.set={//CT_05
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_06
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_07
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_08
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_09
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }}
        },
    
        .AWBGain =
        {
            {//CT_00
                512,    // i4R
                512,    // i4G
               1482     // i4B
            },
            {//CT_01
                562,    // i4R
                512,    // i4G
               1247     // i4B
            },
            {//CT_02
                817,    // i4R
                512,    // i4G
               1072     // i4B
            },
            {//CT_03
                930,    // i4R
                512,    // i4G
               1159     // i4B
            },
            {//CT_04
               1001,    // i4R
                512,    // i4G
                713     // i4B
            },
            {//CT_05
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_06
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_07
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_08
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_09
                512,    // i4R
                512,    // i4G
                512     // i4B
            }
        }
    },
    // IDX_4
    {
    
        .CCM_CT_valid_NUM = 5,
    
        .CCM_Coef = {1, 2, 2},
    
        .CCM_Reg =
        {
            {.set={//CT_00
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_01
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_02
                0x1E7403C2, 0x00001FCA, 0x02BC1F6D, 0x00001FD7, 0x1EB41FDF, 0x0000036D
            }},
            {.set={//CT_03
                0x1DE4043E, 0x00001FDE, 0x02C01F43, 0x00001FFD, 0x1ECF1FE2, 0x0000034F
            }},
            {.set={//CT_04
                0x1EA2034F, 0x0000000F, 0x02941FA4, 0x00001FC8, 0x1EE21FFD, 0x00000321
            }},
            {.set={//CT_05
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_06
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_07
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_08
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_09
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }}
        },
    
        .AWBGain =
        {
            {//CT_00
                512,    // i4R
                512,    // i4G
               1482     // i4B
            },
            {//CT_01
                562,    // i4R
                512,    // i4G
               1247     // i4B
            },
            {//CT_02
                817,    // i4R
                512,    // i4G
               1072     // i4B
            },
            {//CT_03
                930,    // i4R
                512,    // i4G
               1159     // i4B
            },
            {//CT_04
               1001,    // i4R
                512,    // i4G
                713     // i4B
            },
            {//CT_05
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_06
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_07
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_08
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_09
                512,    // i4R
                512,    // i4G
                512     // i4B
            }
        }
    },
    // IDX_5
    {
    
        .CCM_CT_valid_NUM = 5,
    
        .CCM_Coef = {1, 2, 2},
    
        .CCM_Reg =
        {
            {.set={//CT_00
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_01
                0x1EC0032B, 0x00000015, 0x02651F68, 0x00000033, 0x1E7D1FBE, 0x000003C5
            }},
            {.set={//CT_02
                0x1E7403C2, 0x00001FCA, 0x02BC1F6D, 0x00001FD7, 0x1EB41FDF, 0x0000036D
            }},
            {.set={//CT_03
                0x1DE4043E, 0x00001FDE, 0x02C01F43, 0x00001FFD, 0x1ECF1FE2, 0x0000034F
            }},
            {.set={//CT_04
                0x1E240402, 0x00001FDA, 0x02F41F5D, 0x00001FAF, 0x1E7F1FD4, 0x000003AD
            }},
            {.set={//CT_05
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_06
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_07
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_08
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }},
            {.set={//CT_09
                0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
            }}
        },
    
        .AWBGain =
        {
            {//CT_00
                512,    // i4R
                512,    // i4G
               1482     // i4B
            },
            {//CT_01
                562,    // i4R
                512,    // i4G
               1247     // i4B
            },
            {//CT_02
                817,    // i4R
                512,    // i4G
               1072     // i4B
            },
            {//CT_03
                930,    // i4R
                512,    // i4G
               1159     // i4B
            },
            {//CT_04
               1001,    // i4R
                512,    // i4G
                713     // i4B
            },
            {//CT_05
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_06
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_07
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_08
                512,    // i4R
                512,    // i4G
                512     // i4B
            },
            {//CT_09
                512,    // i4R
                512,    // i4G
                512     // i4B
            }
        }
    },
};
