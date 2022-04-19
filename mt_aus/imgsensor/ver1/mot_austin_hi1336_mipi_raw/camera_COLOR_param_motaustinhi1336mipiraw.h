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
.COMM =
{
    .COLOR =
    {
        .COLOR_Method =
        {
            1,
        }
    },
    .CCM =
    {
        .dynamic_CCM=
        {
            {.set={
                0x1ECE034E, 0x00001FE4, 0x02BD1FBE, 0x00001F85, 0x1F000008, 0x000002F8
            }},
            {.set={
                0x1E8D03C2, 0x00001FB1, 0x02C41F87, 0x00001FB5, 0x1EC9000B, 0x0000032C
            }},
            {.set={
                0x1DF00417, 0x00001FDE, 0x02B01F7A, 0x00001FD6, 0x1ECE0012, 0x00000320
            }},
            {.set={
                0x1F4302FD, 0x00001FC0, 0x02761F9E, 0x00001FEC, 0x1E331FF4, 0x000003D9
            }}
        },

        .dynamic_CCM_AWBGain=
        {
            {
              1342,
              512,
              647
            },
            {
              978,
              512,
              915
            },
            {
              1114,
              512,
              1021
            },
            {
              681,
              512,
              1207
            }
        }
    }
},
.CCM = {
    motaustinhi1336mipiraw_CCM_0000[0],motaustinhi1336mipiraw_CCM_0000[1],motaustinhi1336mipiraw_CCM_0000[2],motaustinhi1336mipiraw_CCM_0000[3],motaustinhi1336mipiraw_CCM_0000[4],motaustinhi1336mipiraw_CCM_0000[5],motaustinhi1336mipiraw_CCM_0006[0],motaustinhi1336mipiraw_CCM_0006[1],motaustinhi1336mipiraw_CCM_0006[2],motaustinhi1336mipiraw_CCM_0006[3],
    motaustinhi1336mipiraw_CCM_0006[4],motaustinhi1336mipiraw_CCM_0006[5],motaustinhi1336mipiraw_CCM_0012[0],motaustinhi1336mipiraw_CCM_0012[1],motaustinhi1336mipiraw_CCM_0012[2],motaustinhi1336mipiraw_CCM_0012[3],motaustinhi1336mipiraw_CCM_0012[4],motaustinhi1336mipiraw_CCM_0012[5],
},
.COLOR_PARAM = {
    motaustinhi1336mipiraw_COLOR_PARAM_0000[0],motaustinhi1336mipiraw_COLOR_PARAM_0001[0],motaustinhi1336mipiraw_COLOR_PARAM_0002[0],
},
.COLOR = {
    motaustinhi1336mipiraw_COLOR_0000[0],motaustinhi1336mipiraw_COLOR_0000[1],motaustinhi1336mipiraw_COLOR_0000[2],motaustinhi1336mipiraw_COLOR_0000[3],motaustinhi1336mipiraw_COLOR_0000[4],motaustinhi1336mipiraw_COLOR_0000[5],motaustinhi1336mipiraw_COLOR_0000[6],motaustinhi1336mipiraw_COLOR_0000[7],motaustinhi1336mipiraw_COLOR_0000[8],motaustinhi1336mipiraw_COLOR_0000[9],
    motaustinhi1336mipiraw_COLOR_0000[10],motaustinhi1336mipiraw_COLOR_0000[11],motaustinhi1336mipiraw_COLOR_0000[12],motaustinhi1336mipiraw_COLOR_0000[13],motaustinhi1336mipiraw_COLOR_0000[14],motaustinhi1336mipiraw_COLOR_0000[15],motaustinhi1336mipiraw_COLOR_0000[16],motaustinhi1336mipiraw_COLOR_0000[17],motaustinhi1336mipiraw_COLOR_0000[18],motaustinhi1336mipiraw_COLOR_0000[19],
    motaustinhi1336mipiraw_COLOR_0000[20],motaustinhi1336mipiraw_COLOR_0000[21],motaustinhi1336mipiraw_COLOR_0000[22],motaustinhi1336mipiraw_COLOR_0000[23],motaustinhi1336mipiraw_COLOR_0000[24],motaustinhi1336mipiraw_COLOR_0000[25],motaustinhi1336mipiraw_COLOR_0000[26],motaustinhi1336mipiraw_COLOR_0000[27],motaustinhi1336mipiraw_COLOR_0000[28],motaustinhi1336mipiraw_COLOR_0000[29],
    motaustinhi1336mipiraw_COLOR_0000[30],motaustinhi1336mipiraw_COLOR_0000[31],motaustinhi1336mipiraw_COLOR_0000[32],motaustinhi1336mipiraw_COLOR_0000[33],motaustinhi1336mipiraw_COLOR_0000[34],motaustinhi1336mipiraw_COLOR_0000[35],motaustinhi1336mipiraw_COLOR_0000[36],motaustinhi1336mipiraw_COLOR_0000[37],motaustinhi1336mipiraw_COLOR_0000[38],motaustinhi1336mipiraw_COLOR_0000[39],
    motaustinhi1336mipiraw_COLOR_0000[40],motaustinhi1336mipiraw_COLOR_0000[41],motaustinhi1336mipiraw_COLOR_0000[42],motaustinhi1336mipiraw_COLOR_0000[43],motaustinhi1336mipiraw_COLOR_0000[44],motaustinhi1336mipiraw_COLOR_0000[45],motaustinhi1336mipiraw_COLOR_0000[46],motaustinhi1336mipiraw_COLOR_0000[47],motaustinhi1336mipiraw_COLOR_0000[48],motaustinhi1336mipiraw_COLOR_0000[49],
    motaustinhi1336mipiraw_COLOR_0000[50],motaustinhi1336mipiraw_COLOR_0000[51],motaustinhi1336mipiraw_COLOR_0000[52],motaustinhi1336mipiraw_COLOR_0000[53],motaustinhi1336mipiraw_COLOR_0000[54],motaustinhi1336mipiraw_COLOR_0000[55],motaustinhi1336mipiraw_COLOR_0000[56],motaustinhi1336mipiraw_COLOR_0000[57],motaustinhi1336mipiraw_COLOR_0000[58],motaustinhi1336mipiraw_COLOR_0000[59],
    motaustinhi1336mipiraw_COLOR_0060[0],motaustinhi1336mipiraw_COLOR_0060[1],motaustinhi1336mipiraw_COLOR_0060[2],motaustinhi1336mipiraw_COLOR_0060[3],motaustinhi1336mipiraw_COLOR_0060[4],motaustinhi1336mipiraw_COLOR_0060[5],motaustinhi1336mipiraw_COLOR_0060[6],motaustinhi1336mipiraw_COLOR_0060[7],motaustinhi1336mipiraw_COLOR_0060[8],motaustinhi1336mipiraw_COLOR_0060[9],
    motaustinhi1336mipiraw_COLOR_0060[10],motaustinhi1336mipiraw_COLOR_0060[11],motaustinhi1336mipiraw_COLOR_0060[12],motaustinhi1336mipiraw_COLOR_0060[13],motaustinhi1336mipiraw_COLOR_0060[14],motaustinhi1336mipiraw_COLOR_0060[15],motaustinhi1336mipiraw_COLOR_0060[16],motaustinhi1336mipiraw_COLOR_0060[17],motaustinhi1336mipiraw_COLOR_0060[18],motaustinhi1336mipiraw_COLOR_0060[19],
    motaustinhi1336mipiraw_COLOR_0060[20],motaustinhi1336mipiraw_COLOR_0060[21],motaustinhi1336mipiraw_COLOR_0060[22],motaustinhi1336mipiraw_COLOR_0060[23],motaustinhi1336mipiraw_COLOR_0060[24],motaustinhi1336mipiraw_COLOR_0060[25],motaustinhi1336mipiraw_COLOR_0060[26],motaustinhi1336mipiraw_COLOR_0060[27],motaustinhi1336mipiraw_COLOR_0060[28],motaustinhi1336mipiraw_COLOR_0060[29],
    motaustinhi1336mipiraw_COLOR_0060[30],motaustinhi1336mipiraw_COLOR_0060[31],motaustinhi1336mipiraw_COLOR_0060[32],motaustinhi1336mipiraw_COLOR_0060[33],motaustinhi1336mipiraw_COLOR_0060[34],motaustinhi1336mipiraw_COLOR_0060[35],motaustinhi1336mipiraw_COLOR_0060[36],motaustinhi1336mipiraw_COLOR_0060[37],motaustinhi1336mipiraw_COLOR_0060[38],motaustinhi1336mipiraw_COLOR_0060[39],
    motaustinhi1336mipiraw_COLOR_0060[40],motaustinhi1336mipiraw_COLOR_0060[41],motaustinhi1336mipiraw_COLOR_0060[42],motaustinhi1336mipiraw_COLOR_0060[43],motaustinhi1336mipiraw_COLOR_0060[44],motaustinhi1336mipiraw_COLOR_0060[45],motaustinhi1336mipiraw_COLOR_0060[46],motaustinhi1336mipiraw_COLOR_0060[47],motaustinhi1336mipiraw_COLOR_0060[48],motaustinhi1336mipiraw_COLOR_0060[49],
    motaustinhi1336mipiraw_COLOR_0060[50],motaustinhi1336mipiraw_COLOR_0060[51],motaustinhi1336mipiraw_COLOR_0060[52],motaustinhi1336mipiraw_COLOR_0060[53],motaustinhi1336mipiraw_COLOR_0060[54],motaustinhi1336mipiraw_COLOR_0060[55],motaustinhi1336mipiraw_COLOR_0060[56],motaustinhi1336mipiraw_COLOR_0060[57],motaustinhi1336mipiraw_COLOR_0060[58],motaustinhi1336mipiraw_COLOR_0060[59],
    motaustinhi1336mipiraw_COLOR_0120[0],motaustinhi1336mipiraw_COLOR_0120[1],motaustinhi1336mipiraw_COLOR_0120[2],motaustinhi1336mipiraw_COLOR_0120[3],motaustinhi1336mipiraw_COLOR_0120[4],motaustinhi1336mipiraw_COLOR_0120[5],motaustinhi1336mipiraw_COLOR_0120[6],motaustinhi1336mipiraw_COLOR_0120[7],motaustinhi1336mipiraw_COLOR_0120[8],motaustinhi1336mipiraw_COLOR_0120[9],
    motaustinhi1336mipiraw_COLOR_0120[10],motaustinhi1336mipiraw_COLOR_0120[11],motaustinhi1336mipiraw_COLOR_0120[12],motaustinhi1336mipiraw_COLOR_0120[13],motaustinhi1336mipiraw_COLOR_0120[14],motaustinhi1336mipiraw_COLOR_0120[15],motaustinhi1336mipiraw_COLOR_0120[16],motaustinhi1336mipiraw_COLOR_0120[17],motaustinhi1336mipiraw_COLOR_0120[18],motaustinhi1336mipiraw_COLOR_0120[19],
    motaustinhi1336mipiraw_COLOR_0120[20],motaustinhi1336mipiraw_COLOR_0120[21],motaustinhi1336mipiraw_COLOR_0120[22],motaustinhi1336mipiraw_COLOR_0120[23],motaustinhi1336mipiraw_COLOR_0120[24],motaustinhi1336mipiraw_COLOR_0120[25],motaustinhi1336mipiraw_COLOR_0120[26],motaustinhi1336mipiraw_COLOR_0120[27],motaustinhi1336mipiraw_COLOR_0120[28],motaustinhi1336mipiraw_COLOR_0120[29],
    motaustinhi1336mipiraw_COLOR_0120[30],motaustinhi1336mipiraw_COLOR_0120[31],motaustinhi1336mipiraw_COLOR_0120[32],motaustinhi1336mipiraw_COLOR_0120[33],motaustinhi1336mipiraw_COLOR_0120[34],motaustinhi1336mipiraw_COLOR_0120[35],motaustinhi1336mipiraw_COLOR_0120[36],motaustinhi1336mipiraw_COLOR_0120[37],motaustinhi1336mipiraw_COLOR_0120[38],motaustinhi1336mipiraw_COLOR_0120[39],
    motaustinhi1336mipiraw_COLOR_0120[40],motaustinhi1336mipiraw_COLOR_0120[41],motaustinhi1336mipiraw_COLOR_0120[42],motaustinhi1336mipiraw_COLOR_0120[43],motaustinhi1336mipiraw_COLOR_0120[44],motaustinhi1336mipiraw_COLOR_0120[45],motaustinhi1336mipiraw_COLOR_0120[46],motaustinhi1336mipiraw_COLOR_0120[47],motaustinhi1336mipiraw_COLOR_0120[48],motaustinhi1336mipiraw_COLOR_0120[49],
    motaustinhi1336mipiraw_COLOR_0120[50],motaustinhi1336mipiraw_COLOR_0120[51],motaustinhi1336mipiraw_COLOR_0120[52],motaustinhi1336mipiraw_COLOR_0120[53],motaustinhi1336mipiraw_COLOR_0120[54],motaustinhi1336mipiraw_COLOR_0120[55],motaustinhi1336mipiraw_COLOR_0120[56],motaustinhi1336mipiraw_COLOR_0120[57],motaustinhi1336mipiraw_COLOR_0120[58],motaustinhi1336mipiraw_COLOR_0120[59],
},
.CCM_R3 = {
    motaustinhi1336mipiraw_CCM_R3_0000[0],motaustinhi1336mipiraw_CCM_R3_0000[1],motaustinhi1336mipiraw_CCM_R3_0000[2],motaustinhi1336mipiraw_CCM_R3_0000[3],motaustinhi1336mipiraw_CCM_R3_0000[4],motaustinhi1336mipiraw_CCM_R3_0000[5],motaustinhi1336mipiraw_CCM_R3_0006[0],motaustinhi1336mipiraw_CCM_R3_0006[1],motaustinhi1336mipiraw_CCM_R3_0006[2],motaustinhi1336mipiraw_CCM_R3_0006[3],
    motaustinhi1336mipiraw_CCM_R3_0006[4],motaustinhi1336mipiraw_CCM_R3_0006[5],motaustinhi1336mipiraw_CCM_R3_0012[0],motaustinhi1336mipiraw_CCM_R3_0012[1],motaustinhi1336mipiraw_CCM_R3_0012[2],motaustinhi1336mipiraw_CCM_R3_0012[3],motaustinhi1336mipiraw_CCM_R3_0012[4],motaustinhi1336mipiraw_CCM_R3_0012[5],
},
