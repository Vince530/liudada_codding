const ISP_NVRAM_RRZ_T RRZ_%04d = {
    .ctl       ={.bits ={.RRZ_HORI_EN=0, .RRZ_VERT_EN=0, .RRZ_OUTPUT_WAIT_EN=0, .RRZ_MONO=0, .RRZ_CL=0, .RRZ_CL_HL=0, .RRZ_NNIR=0, .RRZ_VDM_VRZ_MODE=1, .RRZ_HORI_TBL_SEL=0, .rsv_22=0, .RRZ_VERT_TBL_SEL=0, .rsv_30=0}},
    .mode_th   ={.bits ={.RRZ_TH_MD=80, .RRZ_TH_HI=40, .RRZ_TH_LO=80, .RRZ_TH_MD2=80}},
    .mode_ctl  ={.bits ={.RRZ_PRF_BLD=0, .RRZ_PRF=0, .RRZ_BLD_SL=16, .RRZ_CR_MODE=1, .rsv_17=0}},
    .lbld_cfg  ={.bits ={.RRZ_LBLD_TH=600, .rsv_10=0, .RRZ_LBLD_SL=16, .rsv_21=0}},
    .nnir_tbl_sel={.bits ={.RRZ_HORI_TBL2_SEL=32, .rsv_6=0, .RRZ_VERT_TBL2_SEL=32, .rsv_14=0}},
    .sw_ctl={.bits ={.RRZ_FW_TBL_SHIFT=0}},
    .rb_tbl_sel={.bits ={ .RRZ_HORI_TBL2_SEL_RB=0, .rsv_6=0, .RRZ_VERT_TBL2_SEL_RB=0, .rsv_14=0, .RRZ_HORI_TBL_SEL_RB=0, .rsv_22=0, .RRZ_VERT_TBL_SEL_RB=0, .rsv_30=0 }},
};