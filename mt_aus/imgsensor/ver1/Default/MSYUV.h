const FEATURE_NVRAM_MSYUV_T MSYUV_%04d = {
	.MSYUV_SCALES=7,

    ///////////// MS YNR (7 levels) ////////////
    // Level 1 - NR
    .MSYUV_MS1_YNR_Y_STD=8,
    .MSYUV_MS1_YNR_Y_BLD=16,
    .MSYUV_MS1_YNR_Y_CEN=0,
    .MSYUV_MS1_YNR_C_STD=8,
    .MSYUV_MS1_YNR_C_BLD=48,
    .MSYUV_MS1_YNR_C_L_DIFF=8,
    .MSYUV_MS1_YNR_SL2_STR=16,
    // Level 2 - NR
    .MSYUV_MS2_YNR_Y_STD=4,
    .MSYUV_MS2_YNR_Y_BLD=16,
    .MSYUV_MS2_YNR_Y_CEN=0,
    .MSYUV_MS2_YNR_C_STD=4,
    .MSYUV_MS2_YNR_C_BLD=48,
    .MSYUV_MS2_YNR_C_L_DIFF=4,
    .MSYUV_MS2_YNR_SL2_STR=8,
    // Level 3 - NR
    .MSYUV_MS3_YNR_Y_STD=2,
    .MSYUV_MS3_YNR_Y_BLD=16,
    .MSYUV_MS3_YNR_Y_CEN=0,
    .MSYUV_MS3_YNR_C_STD=2,
    .MSYUV_MS3_YNR_C_BLD=48,
    .MSYUV_MS3_YNR_C_L_DIFF=2,
    .MSYUV_MS3_YNR_SL2_STR=4,
    // Level 4 - NR
    .MSYUV_MS4_YNR_Y_STD=1,
    .MSYUV_MS4_YNR_Y_BLD=16,
    .MSYUV_MS4_YNR_Y_CEN=0,
    .MSYUV_MS4_YNR_C_STD=1,
    .MSYUV_MS4_YNR_C_BLD=48,
    .MSYUV_MS4_YNR_C_L_DIFF=1,
    .MSYUV_MS4_YNR_SL2_STR=2,
    // Level 5 - NR
    .MSYUV_MS5_YNR_Y_STD=0,
    .MSYUV_MS5_YNR_Y_BLD=16,
    .MSYUV_MS5_YNR_Y_CEN=0,
    .MSYUV_MS5_YNR_C_STD=0,
    .MSYUV_MS5_YNR_C_BLD=48,
    .MSYUV_MS5_YNR_C_L_DIFF=1,
    .MSYUV_MS5_YNR_SL2_STR=1,
    // Level 6 - NR
    .MSYUV_MS6_YNR_Y_STD=0,
    .MSYUV_MS6_YNR_Y_BLD=16,
    .MSYUV_MS6_YNR_Y_CEN=0,
    .MSYUV_MS6_YNR_C_STD=0,
    .MSYUV_MS6_YNR_C_BLD=48,
    .MSYUV_MS6_YNR_C_L_DIFF=1,
    .MSYUV_MS6_YNR_SL2_STR=0,

    ///////////// MS EE (7 levels) ////////////
    // Level 1 - EE
    .MSYUV_MS1_EE_H1_GAIN=0,
    .MSYUV_MS1_EE_H2_GAIN=0,
    .MSYUV_MS1_EE_H3_GAIN=0,
    .MSYUV_MS1_EE_OVRSH_CLIP_STR=7,
    .MSYUV_MS1_EE_GLUT_Y1=32,
    .MSYUV_MS1_EE_GLUT_Y2=64,
    .MSYUV_MS1_EE_GLUT_Y3=112,
    .MSYUV_MS1_EE_GLUT_Y4=128,
    .MSYUV_MS1_EE_GLUT_Y5=40,
    .MSYUV_MS1_EE_FLT_CORE_TH=8,
    .MSYUV_MS1_EE_DOT_TH=6,
    .MSYUV_MS1_EE_DOT_REDUC_AMNT=128,
    .MSYUV_MS1_EE_RESP_SMO_STR=4,
    .MSYUV_MS1_EE_RESP_CLIP_LUMA_LWB=140,
    .MSYUV_MS1_EE_RESP_CLIP_LUMA_UPB=64,
    .MSYUV_MS1_EE_RESP_CLIP_LUMA_SPC_TH=0,
    .MSYUV_MS1_EE_RESP_CLIP=255,
    // Level 2 - EE
    .MSYUV_MS2_EE_H1_GAIN=0,
    .MSYUV_MS2_EE_H2_GAIN=0,
    .MSYUV_MS2_EE_H3_GAIN=0,
    .MSYUV_MS2_EE_OVRSH_CLIP_STR=7,
    .MSYUV_MS2_EE_GLUT_Y1=32,
    .MSYUV_MS2_EE_GLUT_Y2=64,
    .MSYUV_MS2_EE_GLUT_Y3=112,
    .MSYUV_MS2_EE_GLUT_Y4=128,
    .MSYUV_MS2_EE_GLUT_Y5=40,
    .MSYUV_MS2_EE_FLT_CORE_TH=8,
    .MSYUV_MS2_EE_DOT_TH=6,
    .MSYUV_MS2_EE_DOT_REDUC_AMNT=128,
    .MSYUV_MS2_EE_RESP_SMO_STR=4,
    .MSYUV_MS2_EE_RESP_CLIP_LUMA_LWB=140,
    .MSYUV_MS2_EE_RESP_CLIP_LUMA_UPB=64,
    .MSYUV_MS2_EE_RESP_CLIP_LUMA_SPC_TH=0,
    .MSYUV_MS2_EE_RESP_CLIP=255,
    // Level 3 - EE
    .MSYUV_MS3_EE_H1_GAIN=0,
    .MSYUV_MS3_EE_H2_GAIN=0,
    .MSYUV_MS3_EE_H3_GAIN=0,
    .MSYUV_MS3_EE_OVRSH_CLIP_STR=7,
    .MSYUV_MS3_EE_GLUT_Y1=32,
    .MSYUV_MS3_EE_GLUT_Y2=64,
    .MSYUV_MS3_EE_GLUT_Y3=112,
    .MSYUV_MS3_EE_GLUT_Y4=128,
    .MSYUV_MS3_EE_GLUT_Y5=40,
    .MSYUV_MS3_EE_FLT_CORE_TH=8,
    .MSYUV_MS3_EE_DOT_TH=6,
    .MSYUV_MS3_EE_DOT_REDUC_AMNT=128,
    .MSYUV_MS3_EE_RESP_SMO_STR=4,
    .MSYUV_MS3_EE_RESP_CLIP_LUMA_LWB=140,
    .MSYUV_MS3_EE_RESP_CLIP_LUMA_UPB=64,
    .MSYUV_MS3_EE_RESP_CLIP_LUMA_SPC_TH=0,
    .MSYUV_MS3_EE_RESP_CLIP=255,
    // Level 4 - EE
    .MSYUV_MS4_EE_H1_GAIN=0,
    .MSYUV_MS4_EE_H2_GAIN=0,
    .MSYUV_MS4_EE_H3_GAIN=0,
    .MSYUV_MS4_EE_OVRSH_CLIP_STR=7,
    .MSYUV_MS4_EE_GLUT_Y1=32,
    .MSYUV_MS4_EE_GLUT_Y2=64,
    .MSYUV_MS4_EE_GLUT_Y3=112,
    .MSYUV_MS4_EE_GLUT_Y4=128,
    .MSYUV_MS4_EE_GLUT_Y5=40,
    .MSYUV_MS4_EE_FLT_CORE_TH=8,
    .MSYUV_MS4_EE_DOT_TH=6,
    .MSYUV_MS4_EE_DOT_REDUC_AMNT=128,
    .MSYUV_MS4_EE_RESP_SMO_STR=4,
    .MSYUV_MS4_EE_RESP_CLIP_LUMA_LWB=140,
    .MSYUV_MS4_EE_RESP_CLIP_LUMA_UPB=64,
    .MSYUV_MS4_EE_RESP_CLIP_LUMA_SPC_TH=0,
    .MSYUV_MS4_EE_RESP_CLIP=255,
    // Level 4 - EE
    .MSYUV_MS5_EE_H1_GAIN=0,
    .MSYUV_MS5_EE_H2_GAIN=0,
    .MSYUV_MS5_EE_H3_GAIN=0,
    .MSYUV_MS5_EE_OVRSH_CLIP_STR=7,
    .MSYUV_MS5_EE_GLUT_Y1=32,
    .MSYUV_MS5_EE_GLUT_Y2=64,
    .MSYUV_MS5_EE_GLUT_Y3=112,
    .MSYUV_MS5_EE_GLUT_Y4=128,
    .MSYUV_MS5_EE_GLUT_Y5=40,
    .MSYUV_MS5_EE_FLT_CORE_TH=8,
    .MSYUV_MS5_EE_DOT_TH=6,
    .MSYUV_MS5_EE_DOT_REDUC_AMNT=128,
    .MSYUV_MS5_EE_RESP_SMO_STR=4,
    .MSYUV_MS5_EE_RESP_CLIP_LUMA_LWB=140,
    .MSYUV_MS5_EE_RESP_CLIP_LUMA_UPB=64,
    .MSYUV_MS5_EE_RESP_CLIP_LUMA_SPC_TH=0,
    .MSYUV_MS5_EE_RESP_CLIP=255,
    // Level 4 - EE
    .MSYUV_MS6_EE_H1_GAIN=0,
    .MSYUV_MS6_EE_H2_GAIN=0,
    .MSYUV_MS6_EE_H3_GAIN=0,
    .MSYUV_MS6_EE_OVRSH_CLIP_STR=7,
    .MSYUV_MS6_EE_GLUT_Y1=32,
    .MSYUV_MS6_EE_GLUT_Y2=64,
    .MSYUV_MS6_EE_GLUT_Y3=112,
    .MSYUV_MS6_EE_GLUT_Y4=128,
    .MSYUV_MS6_EE_GLUT_Y5=40,
    .MSYUV_MS6_EE_FLT_CORE_TH=8,
    .MSYUV_MS6_EE_DOT_TH=6,
    .MSYUV_MS6_EE_DOT_REDUC_AMNT=128,
    .MSYUV_MS6_EE_RESP_SMO_STR=4,
    .MSYUV_MS6_EE_RESP_CLIP_LUMA_LWB=140,
    .MSYUV_MS6_EE_RESP_CLIP_LUMA_UPB=64,
    .MSYUV_MS6_EE_RESP_CLIP_LUMA_SPC_TH=0,
    .MSYUV_MS6_EE_RESP_CLIP=255,

    ///////////// MS MSF LINK (6 levels) ////////////
    // Level 0 - MSF_LINK
    .MSYUV_MS0_YNR_MSF_NR=64,
    .MSYUV_MS0_YNR_MSF_BLD=40,
    .MSYUV_MS0_YNR_MSF_CEN=16,
    // Level 1 - MSF_LINK
    .MSYUV_MS1_YNR_MSF_NR=64,
    .MSYUV_MS1_YNR_MSF_BLD=40,
    .MSYUV_MS1_YNR_MSF_CEN=16,
    // Level 2 - MSF_LINK
    .MSYUV_MS2_YNR_MSF_NR=64,
    .MSYUV_MS2_YNR_MSF_BLD=40,
    .MSYUV_MS2_YNR_MSF_CEN=16,
    // Level 3 - MSF_LINK
    .MSYUV_MS3_YNR_MSF_NR=64,
    .MSYUV_MS3_YNR_MSF_BLD=40,
    .MSYUV_MS3_YNR_MSF_CEN=16,
    // Level 4 - MSF_LINK
    .MSYUV_MS4_YNR_MSF_NR=64,
    .MSYUV_MS4_YNR_MSF_BLD=40,
    .MSYUV_MS4_YNR_MSF_CEN=16,
    // Level 5 - MSF_LINK
    .MSYUV_MS5_YNR_MSF_NR=64,
    .MSYUV_MS5_YNR_MSF_BLD=40,
    .MSYUV_MS5_YNR_MSF_CEN=16,

    ///////////// MS CNR (6 levels) ////////////
    // Level 1 - NR
    .MSYUV_MS1_CNR_SCALE_MODE=1,
    .MSYUV_MS1_CNR_C_STD=8,
    .MSYUV_MS1_CNR_C_BLD=48,
    .MSYUV_MS1_CNR_C_L_DIFF=8,
    .MSYUV_MS1_CNR_SL2_STR=16,
    // Level 2 - NR
    .MSYUV_MS2_CNR_SCALE_MODE=1,
    .MSYUV_MS2_CNR_C_STD=8,
    .MSYUV_MS2_CNR_C_BLD=48,
    .MSYUV_MS2_CNR_C_L_DIFF=8,
    .MSYUV_MS2_CNR_SL2_STR=8,
    // Level 3 - NR
    .MSYUV_MS3_CNR_SCALE_MODE=1,
    .MSYUV_MS3_CNR_C_STD=8,
    .MSYUV_MS3_CNR_C_BLD=48,
    .MSYUV_MS3_CNR_C_L_DIFF=8,
    .MSYUV_MS3_CNR_SL2_STR=4,
    // Level 4 - NR
    .MSYUV_MS4_CNR_SCALE_MODE=1,
    .MSYUV_MS4_CNR_C_STD=8,
    .MSYUV_MS4_CNR_C_BLD=48,
    .MSYUV_MS4_CNR_C_L_DIFF=8,
    .MSYUV_MS4_CNR_SL2_STR=2,
    // Level 5 - NR
    .MSYUV_MS5_CNR_SCALE_MODE=1,
    .MSYUV_MS5_CNR_C_STD=8,
    .MSYUV_MS5_CNR_C_BLD=48,
    .MSYUV_MS5_CNR_C_L_DIFF=8,
    .MSYUV_MS5_CNR_SL2_STR=1,

    // RSV
    .MSYUV_MS1_RSV1 = 0,
    .MSYUV_MS1_RSV2 = 0,
    .MSYUV_MS1_RSV3 = 0,
    .MSYUV_MS1_RSV4 = 0,
    .MSYUV_MS2_RSV1 = 0,
    .MSYUV_MS2_RSV2 = 0,
    .MSYUV_MS2_RSV3 = 0,
    .MSYUV_MS2_RSV4 = 0,
    .MSYUV_MS3_RSV1 = 0,
    .MSYUV_MS3_RSV2 = 0,
    .MSYUV_MS3_RSV3 = 0,
    .MSYUV_MS3_RSV4 = 0,
    .MSYUV_MS4_RSV1 = 0,
    .MSYUV_MS4_RSV2 = 0,
    .MSYUV_MS4_RSV3 = 0,
    .MSYUV_MS4_RSV4 = 0,
    .MSYUV_MS5_RSV1 = 0,
    .MSYUV_MS5_RSV2 = 0,
    .MSYUV_MS5_RSV3 = 0,
    .MSYUV_MS5_RSV4 = 0,
};
