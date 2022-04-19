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

#define CCM_BASE                                                     CCM_CCM_BASE
#define CCM_R3_BASE                                                  CCM_R3_CCM_BASE

const ISP_NVRAM_MULTI_CCM_STRUCT CCM_BASE[6] = {
    // IDX_0
    {
            .CCM_CT_valid_NUM = 6,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1EA103B1, 0x00001FAE, 0x03471F11, 0x00001FA8, 0x1C901E97, 0x000006D9
        }},
        {.set={//CT_01
            0x1E880398, 0x00001FE0, 0x03581F19, 0x00001F8F, 0x1D5A1F24, 0x00000582
        }},
        {.set={//CT_02
            0x1E7903C0, 0x00001FC7, 0x03471F35, 0x00001F84, 0x1E621F8B, 0x00000413
        }},
        {.set={//CT_03
            0x1DA80459, 0x00001FFF, 0x033F1F0F, 0x00001FB2, 0x1E7C1F8D, 0x000003F7
        }},
        {.set={//CT_04
            0x1DEF0408, 0x00000009, 0x034F1F5E, 0x00001F53, 0x1EAE1FC6, 0x0000038C
        }},
        {.set={//CT_05
            0x1DE2040C, 0x00000012, 0x03561F75, 0x00001F35, 0x1EAF1FD4, 0x0000037D
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
    .AWBGain=
    {
        {//CT_00
            474,  // i4R	469
            512,  // i4G	512
            1255  // i4B	1334
        },
        {//CT_01
            567,  // i4R
            512,  // i4G
            1191  // i4B
        },
        {//CT_02
            696,  // i4R
            512,  // i4G
            1039  // i4B
        },
        {//CT_03
            786,  // i4R
            512,  // i4G
            1058  // i4B
        },
        {//CT_04
            854,  // i4R
            512,  // i4G
            751  // i4B
        },
        {//CT_05
            980,  // i4R
            512,  // i4G
            720  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    }

    },
    // IDX_1
    {
            .CCM_CT_valid_NUM = 6,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1EA103B1, 0x00001FAE, 0x03471F11, 0x00001FA8, 0x1C901E97, 0x000006D9
        }},
        {.set={//CT_01
            0x1E880398, 0x00001FE0, 0x03581F19, 0x00001F8F, 0x1D5A1F24, 0x00000582
        }},
        {.set={//CT_02
            0x1E7903C0, 0x00001FC7, 0x03471F35, 0x00001F84, 0x1E621F8B, 0x00000413
        }},
        {.set={//CT_03
            0x1DA80459, 0x00001FFF, 0x033F1F0F, 0x00001FB2, 0x1E7C1F8D, 0x000003F7
        }},
        {.set={//CT_04
            0x1DEF0408, 0x00000009, 0x034F1F5E, 0x00001F53, 0x1EAE1FC6, 0x0000038C
        }},
        {.set={//CT_05
            0x1DE2040C, 0x00000012, 0x03561F75, 0x00001F35, 0x1EAF1FD4, 0x0000037D
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
    .AWBGain=
    {
        {//CT_00
            469,  // i4R
            512,  // i4G
            1334  // i4B
        },
        {//CT_01
            567,  // i4R
            512,  // i4G
            1191  // i4B
        },
        {//CT_02
            696,  // i4R
            512,  // i4G
            1039  // i4B
        },
        {//CT_03
            786,  // i4R
            512,  // i4G
            1058  // i4B
        },
        {//CT_04
            854,  // i4R
            512,  // i4G
            751  // i4B
        },
        {//CT_05
            980,  // i4R
            512,  // i4G
            720  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    }

    },
    // IDX_2
    {
            .CCM_CT_valid_NUM = 6,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1EA103B1, 0x00001FAE, 0x03471F11, 0x00001FA8, 0x1C901E97, 0x000006D9
        }},
        {.set={//CT_01
            0x1E880398, 0x00001FE0, 0x03581F19, 0x00001F8F, 0x1D5A1F24, 0x00000582
        }},
        {.set={//CT_02
            0x1E7903C0, 0x00001FC7, 0x03471F35, 0x00001F84, 0x1E621F8B, 0x00000413
        }},
        {.set={//CT_03
            0x1DA80459, 0x00001FFF, 0x033F1F0F, 0x00001FB2, 0x1E7C1F8D, 0x000003F7
        }},
        {.set={//CT_04
            0x1DEF0408, 0x00000009, 0x034F1F5E, 0x00001F53, 0x1EAE1FC6, 0x0000038C
        }},
        {.set={//CT_05
            0x1DE2040C, 0x00000012, 0x03561F75, 0x00001F35, 0x1EAF1FD4, 0x0000037D
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
    .AWBGain=
    {
        {//CT_00
            469,  // i4R
            512,  // i4G
            1334  // i4B
        },
        {//CT_01
            567,  // i4R
            512,  // i4G
            1191  // i4B
        },
        {//CT_02
            696,  // i4R
            512,  // i4G
            1039  // i4B
        },
        {//CT_03
            786,  // i4R
            512,  // i4G
            1058  // i4B
        },
        {//CT_04
            854,  // i4R
            512,  // i4G
            751  // i4B
        },
        {//CT_05
            980,  // i4R
            512,  // i4G
            720  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    }

    },
    // IDX_3
    {
            .CCM_CT_valid_NUM = 6,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1EA103B1, 0x00001FAE, 0x03471F11, 0x00001FA8, 0x1C901E97, 0x000006D9
        }},
        {.set={//CT_01
            0x1E880398, 0x00001FE0, 0x03581F19, 0x00001F8F, 0x1D5A1F24, 0x00000582
        }},
        {.set={//CT_02
            0x1E7903C0, 0x00001FC7, 0x03471F35, 0x00001F84, 0x1E621F8B, 0x00000413
        }},
        {.set={//CT_03
            0x1DA80459, 0x00001FFF, 0x033F1F0F, 0x00001FB2, 0x1E7C1F8D, 0x000003F7
        }},
        {.set={//CT_04
            0x1DEF0408, 0x00000009, 0x034F1F5E, 0x00001F53, 0x1EAE1FC6, 0x0000038C
        }},
        {.set={//CT_05
            0x1DE2040C, 0x00000012, 0x03561F75, 0x00001F35, 0x1EAF1FD4, 0x0000037D
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
    .AWBGain=
    {
        {//CT_00
            469,  // i4R
            512,  // i4G
            1334  // i4B
        },
        {//CT_01
            567,  // i4R
            512,  // i4G
            1191  // i4B
        },
        {//CT_02
            696,  // i4R
            512,  // i4G
            1039  // i4B
        },
        {//CT_03
            786,  // i4R
            512,  // i4G
            1058  // i4B
        },
        {//CT_04
            854,  // i4R
            512,  // i4G
            751  // i4B
        },
        {//CT_05
            980,  // i4R
            512,  // i4G
            720  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    }

    },
    // IDX_4
    {
            .CCM_CT_valid_NUM = 6,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1EA103B1, 0x00001FAE, 0x03471F11, 0x00001FA8, 0x1C901E97, 0x000006D9
        }},
        {.set={//CT_01
            0x1E880398, 0x00001FE0, 0x03581F19, 0x00001F8F, 0x1D5A1F24, 0x00000582
        }},
        {.set={//CT_02
            0x1E7903C0, 0x00001FC7, 0x03471F35, 0x00001F84, 0x1E621F8B, 0x00000413
        }},
        {.set={//CT_03
            0x1DA80459, 0x00001FFF, 0x033F1F0F, 0x00001FB2, 0x1E7C1F8D, 0x000003F7
        }},
        {.set={//CT_04
            0x1DEF0408, 0x00000009, 0x034F1F5E, 0x00001F53, 0x1EAE1FC6, 0x0000038C
        }},
        {.set={//CT_05
            0x1DE2040C, 0x00000012, 0x03561F75, 0x00001F35, 0x1EAF1FD4, 0x0000037D
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
    .AWBGain=
    {
        {//CT_00
            469,  // i4R
            512,  // i4G
            1334  // i4B
        },
        {//CT_01
            567,  // i4R
            512,  // i4G
            1191  // i4B
        },
        {//CT_02
            696,  // i4R
            512,  // i4G
            1039  // i4B
        },
        {//CT_03
            786,  // i4R
            512,  // i4G
            1058  // i4B
        },
        {//CT_04
            854,  // i4R
            512,  // i4G
            751  // i4B
        },
        {//CT_05
            980,  // i4R
            512,  // i4G
            720  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    }

    },
    // IDX_5
    {
            .CCM_CT_valid_NUM = 6,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1EA103B1, 0x00001FAE, 0x03471F11, 0x00001FA8, 0x1C901E97, 0x000006D9
        }},
        {.set={//CT_01
            0x1E880398, 0x00001FE0, 0x03581F19, 0x00001F8F, 0x1D5A1F24, 0x00000582
        }},
        {.set={//CT_02
            0x1E7903C0, 0x00001FC7, 0x03471F35, 0x00001F84, 0x1E621F8B, 0x00000413
        }},
        {.set={//CT_03
            0x1DA80459, 0x00001FFF, 0x033F1F0F, 0x00001FB2, 0x1E7C1F8D, 0x000003F7
        }},
        {.set={//CT_04
            0x1DEF0408, 0x00000009, 0x034F1F5E, 0x00001F53, 0x1EAE1FC6, 0x0000038C
        }},
        {.set={//CT_05
            0x1DE2040C, 0x00000012, 0x03561F75, 0x00001F35, 0x1EAF1FD4, 0x0000037D
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
    .AWBGain=
    {
        {//CT_00
            469,  // i4R
            512,  // i4G
            1334  // i4B
        },
        {//CT_01
            567,  // i4R
            512,  // i4G
            1191  // i4B
        },
        {//CT_02
            696,  // i4R
            512,  // i4G
            1039  // i4B
        },
        {//CT_03
            786,  // i4R
            512,  // i4G
            1058  // i4B
        },
        {//CT_04
            854,  // i4R
            512,  // i4G
            751  // i4B
        },
        {//CT_05
            980,  // i4R
            512,  // i4G
            720  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    }

    },
};
const ISP_NVRAM_MULTI_CCM_STRUCT CCM_R3_BASE[6] = {
    // IDX_0
    {
            .CCM_CT_valid_NUM = 6,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1EA103B1, 0x00001FAE, 0x03471F11, 0x00001FA8, 0x1C901E97, 0x000006D9
        }},
        {.set={//CT_01
            0x1E880398, 0x00001FE0, 0x03581F19, 0x00001F8F, 0x1D5A1F24, 0x00000582
        }},
        {.set={//CT_02
            0x1E7903C0, 0x00001FC7, 0x03471F35, 0x00001F84, 0x1E621F8B, 0x00000413
        }},
        {.set={//CT_03
            0x1DA80459, 0x00001FFF, 0x033F1F0F, 0x00001FB2, 0x1E7C1F8D, 0x000003F7
        }},
        {.set={//CT_04
            0x1DEF0408, 0x00000009, 0x034F1F5E, 0x00001F53, 0x1EAE1FC6, 0x0000038C
        }},
        {.set={//CT_05
            0x1DE2040C, 0x00000012, 0x03561F75, 0x00001F35, 0x1EAF1FD4, 0x0000037D
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
    .AWBGain=
    {
        {//CT_00
            469,  // i4R
            512,  // i4G
            1334  // i4B
        },
        {//CT_01
            567,  // i4R
            512,  // i4G
            1191  // i4B
        },
        {//CT_02
            696,  // i4R
            512,  // i4G
            1039  // i4B
        },
        {//CT_03
            786,  // i4R
            512,  // i4G
            1058  // i4B
        },
        {//CT_04
            854,  // i4R
            512,  // i4G
            751  // i4B
        },
        {//CT_05
            980,  // i4R
            512,  // i4G
            720  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    }

    },
    // IDX_1
    {
            .CCM_CT_valid_NUM = 6,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1EA103B1, 0x00001FAE, 0x03471F11, 0x00001FA8, 0x1C901E97, 0x000006D9
        }},
        {.set={//CT_01
            0x1E880398, 0x00001FE0, 0x03581F19, 0x00001F8F, 0x1D5A1F24, 0x00000582
        }},
        {.set={//CT_02
            0x1E7903C0, 0x00001FC7, 0x03471F35, 0x00001F84, 0x1E621F8B, 0x00000413
        }},
        {.set={//CT_03
            0x1DA80459, 0x00001FFF, 0x033F1F0F, 0x00001FB2, 0x1E7C1F8D, 0x000003F7
        }},
        {.set={//CT_04
            0x1DEF0408, 0x00000009, 0x034F1F5E, 0x00001F53, 0x1EAE1FC6, 0x0000038C
        }},
        {.set={//CT_05
            0x1DE2040C, 0x00000012, 0x03561F75, 0x00001F35, 0x1EAF1FD4, 0x0000037D
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
    .AWBGain=
    {
        {//CT_00
            469,  // i4R
            512,  // i4G
            1334  // i4B
        },
        {//CT_01
            567,  // i4R
            512,  // i4G
            1191  // i4B
        },
        {//CT_02
            696,  // i4R
            512,  // i4G
            1039  // i4B
        },
        {//CT_03
            786,  // i4R
            512,  // i4G
            1058  // i4B
        },
        {//CT_04
            854,  // i4R
            512,  // i4G
            751  // i4B
        },
        {//CT_05
            980,  // i4R
            512,  // i4G
            720  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    }

    },
    // IDX_2
    {
            .CCM_CT_valid_NUM = 6,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1EA103B1, 0x00001FAE, 0x03471F11, 0x00001FA8, 0x1C901E97, 0x000006D9
        }},
        {.set={//CT_01
            0x1E880398, 0x00001FE0, 0x03581F19, 0x00001F8F, 0x1D5A1F24, 0x00000582
        }},
        {.set={//CT_02
            0x1E7903C0, 0x00001FC7, 0x03471F35, 0x00001F84, 0x1E621F8B, 0x00000413
        }},
        {.set={//CT_03
            0x1DA80459, 0x00001FFF, 0x033F1F0F, 0x00001FB2, 0x1E7C1F8D, 0x000003F7
        }},
        {.set={//CT_04
            0x1DEF0408, 0x00000009, 0x034F1F5E, 0x00001F53, 0x1EAE1FC6, 0x0000038C
        }},
        {.set={//CT_05
            0x1DE2040C, 0x00000012, 0x03561F75, 0x00001F35, 0x1EAF1FD4, 0x0000037D
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
    .AWBGain=
    {
        {//CT_00
            469,  // i4R
            512,  // i4G
            1334  // i4B
        },
        {//CT_01
            567,  // i4R
            512,  // i4G
            1191  // i4B
        },
        {//CT_02
            696,  // i4R
            512,  // i4G
            1039  // i4B
        },
        {//CT_03
            786,  // i4R
            512,  // i4G
            1058  // i4B
        },
        {//CT_04
            854,  // i4R
            512,  // i4G
            751  // i4B
        },
        {//CT_05
            980,  // i4R
            512,  // i4G
            720  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    }

    },
    // IDX_3
    {
            .CCM_CT_valid_NUM = 6,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1EA103B1, 0x00001FAE, 0x03471F11, 0x00001FA8, 0x1C901E97, 0x000006D9
        }},
        {.set={//CT_01
            0x1E880398, 0x00001FE0, 0x03581F19, 0x00001F8F, 0x1D5A1F24, 0x00000582
        }},
        {.set={//CT_02
            0x1E7903C0, 0x00001FC7, 0x03471F35, 0x00001F84, 0x1E621F8B, 0x00000413
        }},
        {.set={//CT_03
            0x1DA80459, 0x00001FFF, 0x033F1F0F, 0x00001FB2, 0x1E7C1F8D, 0x000003F7
        }},
        {.set={//CT_04
            0x1DEF0408, 0x00000009, 0x034F1F5E, 0x00001F53, 0x1EAE1FC6, 0x0000038C
        }},
        {.set={//CT_05
            0x1DE2040C, 0x00000012, 0x03561F75, 0x00001F35, 0x1EAF1FD4, 0x0000037D
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
    .AWBGain=
    {
        {//CT_00
            469,  // i4R
            512,  // i4G
            1334  // i4B
        },
        {//CT_01
            567,  // i4R
            512,  // i4G
            1191  // i4B
        },
        {//CT_02
            696,  // i4R
            512,  // i4G
            1039  // i4B
        },
        {//CT_03
            786,  // i4R
            512,  // i4G
            1058  // i4B
        },
        {//CT_04
            854,  // i4R
            512,  // i4G
            751  // i4B
        },
        {//CT_05
            980,  // i4R
            512,  // i4G
            720  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    }

    },
    // IDX_4
    {
            .CCM_CT_valid_NUM = 6,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1EA103B1, 0x00001FAE, 0x03471F11, 0x00001FA8, 0x1C901E97, 0x000006D9
        }},
        {.set={//CT_01
            0x1E880398, 0x00001FE0, 0x03581F19, 0x00001F8F, 0x1D5A1F24, 0x00000582
        }},
        {.set={//CT_02
            0x1E7903C0, 0x00001FC7, 0x03471F35, 0x00001F84, 0x1E621F8B, 0x00000413
        }},
        {.set={//CT_03
            0x1DA80459, 0x00001FFF, 0x033F1F0F, 0x00001FB2, 0x1E7C1F8D, 0x000003F7
        }},
        {.set={//CT_04
            0x1DEF0408, 0x00000009, 0x034F1F5E, 0x00001F53, 0x1EAE1FC6, 0x0000038C
        }},
        {.set={//CT_05
            0x1DE2040C, 0x00000012, 0x03561F75, 0x00001F35, 0x1EAF1FD4, 0x0000037D
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
    .AWBGain=
    {
        {//CT_00
            469,  // i4R
            512,  // i4G
            1334  // i4B
        },
        {//CT_01
            567,  // i4R
            512,  // i4G
            1191  // i4B
        },
        {//CT_02
            696,  // i4R
            512,  // i4G
            1039  // i4B
        },
        {//CT_03
            786,  // i4R
            512,  // i4G
            1058  // i4B
        },
        {//CT_04
            854,  // i4R
            512,  // i4G
            751  // i4B
        },
        {//CT_05
            980,  // i4R
            512,  // i4G
            720  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    }

    },
    // IDX_5
    {
            .CCM_CT_valid_NUM = 6,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1EA103B1, 0x00001FAE, 0x03471F11, 0x00001FA8, 0x1C901E97, 0x000006D9
        }},
        {.set={//CT_01
            0x1E880398, 0x00001FE0, 0x03581F19, 0x00001F8F, 0x1D5A1F24, 0x00000582
        }},
        {.set={//CT_02
            0x1E7903C0, 0x00001FC7, 0x03471F35, 0x00001F84, 0x1E621F8B, 0x00000413
        }},
        {.set={//CT_03
            0x1DA80459, 0x00001FFF, 0x033F1F0F, 0x00001FB2, 0x1E7C1F8D, 0x000003F7
        }},
        {.set={//CT_04
            0x1DEF0408, 0x00000009, 0x034F1F5E, 0x00001F53, 0x1EAE1FC6, 0x0000038C
        }},
        {.set={//CT_05
            0x1DE2040C, 0x00000012, 0x03561F75, 0x00001F35, 0x1EAF1FD4, 0x0000037D
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
    .AWBGain=
    {
        {//CT_00
            469,  // i4R
            512,  // i4G
            1334  // i4B
        },
        {//CT_01
            567,  // i4R
            512,  // i4G
            1191  // i4B
        },
        {//CT_02
            696,  // i4R
            512,  // i4G
            1039  // i4B
        },
        {//CT_03
            786,  // i4R
            512,  // i4G
            1058  // i4B
        },
        {//CT_04
            854,  // i4R
            512,  // i4G
            751  // i4B
        },
        {//CT_05
            980,  // i4R
            512,  // i4G
            720  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    }

    },
};
