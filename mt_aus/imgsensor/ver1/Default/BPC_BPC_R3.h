const ISP_NVRAM_BPC_BPC_T BPC_BPC_R3_%04d = {
    .func_con  ={.bits ={.rsv_0=0, .BPC_BPC_LUT_EN=0, .BPC_PDC_EN=0, .BPC_CT_EN=1, .BPC_BPC_EN=1}},
    .in_th_1   ={.bits ={.rsv_0=0, .BPC_BPC_TH_Y=125, .BPC_BPC_TH_LWB=46}},
    .in_th_2   ={.bits ={.rsv_0=0, .BPC_BPC_TH_XA=354, .BPC_BPC_TH_UPB=483}},
    .in_th_3   ={.bits ={.rsv_0=0, .BPC_BPC_TH_SLB=3, .BPC_BPC_TH_SLA=8, .BPC_BPC_TH_XB=669}},
    .in_th_4   ={.bits ={.rsv_0=0, .BPC_BPC_DK_TH_XB=933, .BPC_BPC_DK_TH_XA=653}},
    .in_th_5   ={.bits ={.rsv_0=0, .BPC_BPC_DK_TH_SLB=3, .BPC_BPC_DK_TH_SLA=9}},
    .c_th_1    ={.bits ={.rsv_0=0, .BPC_BPC_C_TH_Y=201, .BPC_BPC_C_TH_LWB=90}},
    .c_th_2    ={.bits ={.rsv_0=0, .BPC_BPC_C_TH_XA=406, .BPC_BPC_C_TH_UPB=376}},
    .c_th_3    ={.bits ={.rsv_0=0, .BPC_BPC_C_TH_SLB=3, .BPC_BPC_C_TH_SLA=7, .BPC_BPC_C_TH_XB=912}},
    .dtc       ={.bits ={.rsv_0=0, .BPC_BPC_DTC_MODE=0, .BPC_BPC_CS_RNG=1, .BPC_BPC_RNG=1, .BPC_BPC_CS_MODE=1, .BPC_BPC_EXC=1, .BPC_BPC_CT_LV=0, .BPC_BPC_NO_LV=3, .BPC_BPC_TH_MUL=10, .BPC_BPC_AVG_MODE=0}},
    .cor       ={.bits ={.rsv_0=0, .BPC_BPC_DIR_MAX=25, .BPC_BPC_DIR_TH=5, .BPC_BPC_DIR_TH2=5, .BPC_BPC_CRC_MODE=0}},
    .rank      ={.bits ={.rsv_0=0, .BPC_BPC_RANK_IDXB=1, .BPC_BPC_RANK_IDXR=1, .BPC_BPC_RANK_IDXG=1}},
    .bld_1     ={.bits ={.rsv_0=0, .BPC_BPC_BLD_SP=5, .BPC_BPC_BLD_LWB=200, .BPC_BPC_BLD_MODE=0}},
    .bld_2     ={.bits ={.rsv_0=0, .BPC_BPC_BLD0=0, .BPC_BPC_BLD1=64}},
    .ll        ={.bits ={.rsv_0=0, .BPC_BPC_LL_LWB=0, .BPC_BPC_LL_LSP=0}},
    .zhdr_tun  ={.bits ={.rsv_0=0, .BPC_ZHDR_OSC_COUNT=5}},
    .obc_zofst ={.bits ={.rsv_0=0, .BPC_OBC_ZOFST=7936}},
    .pd_exc_con={.bits ={.rsv_0=0, .BPC_ZHDR_OSC_PD_MODE=0, .BPC_ZHDR_CLAMP_EN=1, .BPC_ZHDR_OUT_SEL_EN=0, .BPC_PDC_INTP_CC_EN=1, .BPC_PDC_INTP_PD_MODE=0, .BPC_BPC_RANK_PD_MODE=0, .BPC_BPC_LBL_PD_MODE=0, .BPC_BPC_OC_MEAN_EN=0, .BPC_BPC_AVG_PD_MODE=0}},
};
