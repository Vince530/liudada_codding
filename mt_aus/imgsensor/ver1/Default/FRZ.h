const ISP_NVRAM_FRZ_T FRZ_%04d = {
    .table_sel ={.bits ={.FRZ_HORI_TBL_SEL=0, .FRZ_HORI_TBL_SEL_RB= 0, .rsv_10=0, .FRZ_VERT_TBL_SEL=0, .FRZ_VERT_TBL_SEL_RB=0, .rsv_26=0}},
    .mode_ctl  ={.bits ={.FRZ_MONO=0, .FRZ_COS_TBL_EN=1, .FRZ_CR_MODE=1, .rsv_3=0, .FRZ_BLD_SL=16, .FRZ_TBL_SHIFT=0}},
    .mode_th   ={.bits ={.FRZ_TH_MD=80, .FRZ_TH_HI=40, .FRZ_TH_LO=80, .FRZ_TH_MD2=80}},
    .cl_mode   ={.bits ={.FRZ_CL=0, .FRZ_CL_HL=0, .FRZ_LBLD_SL=16, .rsv_7=0, .FRZ_LBLD_TH=600, .rsv_26=0}},
    .zero_ofst ={.bits ={.FRZ_ZERO_OFST=256, .rsv_16=0}},
    .sw_ctl = {.bits ={.FRZ_FW_TBL_SHIFT=0}},
};