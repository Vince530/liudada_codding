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
    motaustingc02m1bmipiraw_CCM_0000[0],motaustingc02m1bmipiraw_CCM_0000[1],motaustingc02m1bmipiraw_CCM_0000[2],motaustingc02m1bmipiraw_CCM_0000[3],motaustingc02m1bmipiraw_CCM_0000[4],motaustingc02m1bmipiraw_CCM_0000[5],motaustingc02m1bmipiraw_CCM_0006[0],motaustingc02m1bmipiraw_CCM_0006[1],motaustingc02m1bmipiraw_CCM_0006[2],motaustingc02m1bmipiraw_CCM_0006[3],
    motaustingc02m1bmipiraw_CCM_0006[4],motaustingc02m1bmipiraw_CCM_0006[5],motaustingc02m1bmipiraw_CCM_0012[0],motaustingc02m1bmipiraw_CCM_0012[1],motaustingc02m1bmipiraw_CCM_0012[2],motaustingc02m1bmipiraw_CCM_0012[3],motaustingc02m1bmipiraw_CCM_0012[4],motaustingc02m1bmipiraw_CCM_0012[5],
},
.COLOR_PARAM = {
    motaustingc02m1bmipiraw_COLOR_PARAM_0000[0],motaustingc02m1bmipiraw_COLOR_PARAM_0001[0],motaustingc02m1bmipiraw_COLOR_PARAM_0002[0],
},
.COLOR = {
    motaustingc02m1bmipiraw_COLOR_0000[0],motaustingc02m1bmipiraw_COLOR_0000[1],motaustingc02m1bmipiraw_COLOR_0000[2],motaustingc02m1bmipiraw_COLOR_0000[3],motaustingc02m1bmipiraw_COLOR_0000[4],motaustingc02m1bmipiraw_COLOR_0000[5],motaustingc02m1bmipiraw_COLOR_0000[6],motaustingc02m1bmipiraw_COLOR_0000[7],motaustingc02m1bmipiraw_COLOR_0000[8],motaustingc02m1bmipiraw_COLOR_0000[9],
    motaustingc02m1bmipiraw_COLOR_0000[10],motaustingc02m1bmipiraw_COLOR_0000[11],motaustingc02m1bmipiraw_COLOR_0000[12],motaustingc02m1bmipiraw_COLOR_0000[13],motaustingc02m1bmipiraw_COLOR_0000[14],motaustingc02m1bmipiraw_COLOR_0000[15],motaustingc02m1bmipiraw_COLOR_0000[16],motaustingc02m1bmipiraw_COLOR_0000[17],motaustingc02m1bmipiraw_COLOR_0000[18],motaustingc02m1bmipiraw_COLOR_0000[19],
    motaustingc02m1bmipiraw_COLOR_0000[20],motaustingc02m1bmipiraw_COLOR_0000[21],motaustingc02m1bmipiraw_COLOR_0000[22],motaustingc02m1bmipiraw_COLOR_0000[23],motaustingc02m1bmipiraw_COLOR_0000[24],motaustingc02m1bmipiraw_COLOR_0000[25],motaustingc02m1bmipiraw_COLOR_0000[26],motaustingc02m1bmipiraw_COLOR_0000[27],motaustingc02m1bmipiraw_COLOR_0000[28],motaustingc02m1bmipiraw_COLOR_0000[29],
    motaustingc02m1bmipiraw_COLOR_0000[30],motaustingc02m1bmipiraw_COLOR_0000[31],motaustingc02m1bmipiraw_COLOR_0000[32],motaustingc02m1bmipiraw_COLOR_0000[33],motaustingc02m1bmipiraw_COLOR_0000[34],motaustingc02m1bmipiraw_COLOR_0000[35],motaustingc02m1bmipiraw_COLOR_0000[36],motaustingc02m1bmipiraw_COLOR_0000[37],motaustingc02m1bmipiraw_COLOR_0000[38],motaustingc02m1bmipiraw_COLOR_0000[39],
    motaustingc02m1bmipiraw_COLOR_0000[40],motaustingc02m1bmipiraw_COLOR_0000[41],motaustingc02m1bmipiraw_COLOR_0000[42],motaustingc02m1bmipiraw_COLOR_0000[43],motaustingc02m1bmipiraw_COLOR_0000[44],motaustingc02m1bmipiraw_COLOR_0000[45],motaustingc02m1bmipiraw_COLOR_0000[46],motaustingc02m1bmipiraw_COLOR_0000[47],motaustingc02m1bmipiraw_COLOR_0000[48],motaustingc02m1bmipiraw_COLOR_0000[49],
    motaustingc02m1bmipiraw_COLOR_0000[50],motaustingc02m1bmipiraw_COLOR_0000[51],motaustingc02m1bmipiraw_COLOR_0000[52],motaustingc02m1bmipiraw_COLOR_0000[53],motaustingc02m1bmipiraw_COLOR_0000[54],motaustingc02m1bmipiraw_COLOR_0000[55],motaustingc02m1bmipiraw_COLOR_0000[56],motaustingc02m1bmipiraw_COLOR_0000[57],motaustingc02m1bmipiraw_COLOR_0000[58],motaustingc02m1bmipiraw_COLOR_0000[59],
    motaustingc02m1bmipiraw_COLOR_0060[0],motaustingc02m1bmipiraw_COLOR_0060[1],motaustingc02m1bmipiraw_COLOR_0060[2],motaustingc02m1bmipiraw_COLOR_0060[3],motaustingc02m1bmipiraw_COLOR_0060[4],motaustingc02m1bmipiraw_COLOR_0060[5],motaustingc02m1bmipiraw_COLOR_0060[6],motaustingc02m1bmipiraw_COLOR_0060[7],motaustingc02m1bmipiraw_COLOR_0060[8],motaustingc02m1bmipiraw_COLOR_0060[9],
    motaustingc02m1bmipiraw_COLOR_0060[10],motaustingc02m1bmipiraw_COLOR_0060[11],motaustingc02m1bmipiraw_COLOR_0060[12],motaustingc02m1bmipiraw_COLOR_0060[13],motaustingc02m1bmipiraw_COLOR_0060[14],motaustingc02m1bmipiraw_COLOR_0060[15],motaustingc02m1bmipiraw_COLOR_0060[16],motaustingc02m1bmipiraw_COLOR_0060[17],motaustingc02m1bmipiraw_COLOR_0060[18],motaustingc02m1bmipiraw_COLOR_0060[19],
    motaustingc02m1bmipiraw_COLOR_0060[20],motaustingc02m1bmipiraw_COLOR_0060[21],motaustingc02m1bmipiraw_COLOR_0060[22],motaustingc02m1bmipiraw_COLOR_0060[23],motaustingc02m1bmipiraw_COLOR_0060[24],motaustingc02m1bmipiraw_COLOR_0060[25],motaustingc02m1bmipiraw_COLOR_0060[26],motaustingc02m1bmipiraw_COLOR_0060[27],motaustingc02m1bmipiraw_COLOR_0060[28],motaustingc02m1bmipiraw_COLOR_0060[29],
    motaustingc02m1bmipiraw_COLOR_0060[30],motaustingc02m1bmipiraw_COLOR_0060[31],motaustingc02m1bmipiraw_COLOR_0060[32],motaustingc02m1bmipiraw_COLOR_0060[33],motaustingc02m1bmipiraw_COLOR_0060[34],motaustingc02m1bmipiraw_COLOR_0060[35],motaustingc02m1bmipiraw_COLOR_0060[36],motaustingc02m1bmipiraw_COLOR_0060[37],motaustingc02m1bmipiraw_COLOR_0060[38],motaustingc02m1bmipiraw_COLOR_0060[39],
    motaustingc02m1bmipiraw_COLOR_0060[40],motaustingc02m1bmipiraw_COLOR_0060[41],motaustingc02m1bmipiraw_COLOR_0060[42],motaustingc02m1bmipiraw_COLOR_0060[43],motaustingc02m1bmipiraw_COLOR_0060[44],motaustingc02m1bmipiraw_COLOR_0060[45],motaustingc02m1bmipiraw_COLOR_0060[46],motaustingc02m1bmipiraw_COLOR_0060[47],motaustingc02m1bmipiraw_COLOR_0060[48],motaustingc02m1bmipiraw_COLOR_0060[49],
    motaustingc02m1bmipiraw_COLOR_0060[50],motaustingc02m1bmipiraw_COLOR_0060[51],motaustingc02m1bmipiraw_COLOR_0060[52],motaustingc02m1bmipiraw_COLOR_0060[53],motaustingc02m1bmipiraw_COLOR_0060[54],motaustingc02m1bmipiraw_COLOR_0060[55],motaustingc02m1bmipiraw_COLOR_0060[56],motaustingc02m1bmipiraw_COLOR_0060[57],motaustingc02m1bmipiraw_COLOR_0060[58],motaustingc02m1bmipiraw_COLOR_0060[59],
    motaustingc02m1bmipiraw_COLOR_0120[0],motaustingc02m1bmipiraw_COLOR_0120[1],motaustingc02m1bmipiraw_COLOR_0120[2],motaustingc02m1bmipiraw_COLOR_0120[3],motaustingc02m1bmipiraw_COLOR_0120[4],motaustingc02m1bmipiraw_COLOR_0120[5],motaustingc02m1bmipiraw_COLOR_0120[6],motaustingc02m1bmipiraw_COLOR_0120[7],motaustingc02m1bmipiraw_COLOR_0120[8],motaustingc02m1bmipiraw_COLOR_0120[9],
    motaustingc02m1bmipiraw_COLOR_0120[10],motaustingc02m1bmipiraw_COLOR_0120[11],motaustingc02m1bmipiraw_COLOR_0120[12],motaustingc02m1bmipiraw_COLOR_0120[13],motaustingc02m1bmipiraw_COLOR_0120[14],motaustingc02m1bmipiraw_COLOR_0120[15],motaustingc02m1bmipiraw_COLOR_0120[16],motaustingc02m1bmipiraw_COLOR_0120[17],motaustingc02m1bmipiraw_COLOR_0120[18],motaustingc02m1bmipiraw_COLOR_0120[19],
    motaustingc02m1bmipiraw_COLOR_0120[20],motaustingc02m1bmipiraw_COLOR_0120[21],motaustingc02m1bmipiraw_COLOR_0120[22],motaustingc02m1bmipiraw_COLOR_0120[23],motaustingc02m1bmipiraw_COLOR_0120[24],motaustingc02m1bmipiraw_COLOR_0120[25],motaustingc02m1bmipiraw_COLOR_0120[26],motaustingc02m1bmipiraw_COLOR_0120[27],motaustingc02m1bmipiraw_COLOR_0120[28],motaustingc02m1bmipiraw_COLOR_0120[29],
    motaustingc02m1bmipiraw_COLOR_0120[30],motaustingc02m1bmipiraw_COLOR_0120[31],motaustingc02m1bmipiraw_COLOR_0120[32],motaustingc02m1bmipiraw_COLOR_0120[33],motaustingc02m1bmipiraw_COLOR_0120[34],motaustingc02m1bmipiraw_COLOR_0120[35],motaustingc02m1bmipiraw_COLOR_0120[36],motaustingc02m1bmipiraw_COLOR_0120[37],motaustingc02m1bmipiraw_COLOR_0120[38],motaustingc02m1bmipiraw_COLOR_0120[39],
    motaustingc02m1bmipiraw_COLOR_0120[40],motaustingc02m1bmipiraw_COLOR_0120[41],motaustingc02m1bmipiraw_COLOR_0120[42],motaustingc02m1bmipiraw_COLOR_0120[43],motaustingc02m1bmipiraw_COLOR_0120[44],motaustingc02m1bmipiraw_COLOR_0120[45],motaustingc02m1bmipiraw_COLOR_0120[46],motaustingc02m1bmipiraw_COLOR_0120[47],motaustingc02m1bmipiraw_COLOR_0120[48],motaustingc02m1bmipiraw_COLOR_0120[49],
    motaustingc02m1bmipiraw_COLOR_0120[50],motaustingc02m1bmipiraw_COLOR_0120[51],motaustingc02m1bmipiraw_COLOR_0120[52],motaustingc02m1bmipiraw_COLOR_0120[53],motaustingc02m1bmipiraw_COLOR_0120[54],motaustingc02m1bmipiraw_COLOR_0120[55],motaustingc02m1bmipiraw_COLOR_0120[56],motaustingc02m1bmipiraw_COLOR_0120[57],motaustingc02m1bmipiraw_COLOR_0120[58],motaustingc02m1bmipiraw_COLOR_0120[59],
},
.CCM_R3 = {
    motaustingc02m1bmipiraw_CCM_R3_0000[0],motaustingc02m1bmipiraw_CCM_R3_0000[1],motaustingc02m1bmipiraw_CCM_R3_0000[2],motaustingc02m1bmipiraw_CCM_R3_0000[3],motaustingc02m1bmipiraw_CCM_R3_0000[4],motaustingc02m1bmipiraw_CCM_R3_0000[5],motaustingc02m1bmipiraw_CCM_R3_0006[0],motaustingc02m1bmipiraw_CCM_R3_0006[1],motaustingc02m1bmipiraw_CCM_R3_0006[2],motaustingc02m1bmipiraw_CCM_R3_0006[3],
    motaustingc02m1bmipiraw_CCM_R3_0006[4],motaustingc02m1bmipiraw_CCM_R3_0006[5],motaustingc02m1bmipiraw_CCM_R3_0012[0],motaustingc02m1bmipiraw_CCM_R3_0012[1],motaustingc02m1bmipiraw_CCM_R3_0012[2],motaustingc02m1bmipiraw_CCM_R3_0012[3],motaustingc02m1bmipiraw_CCM_R3_0012[4],motaustingc02m1bmipiraw_CCM_R3_0012[5],
},
