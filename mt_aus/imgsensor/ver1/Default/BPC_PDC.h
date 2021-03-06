const ISP_NVRAM_BPC_PDC_T BPC_PDC_%04d = {
    .con       ={.bits ={.rsv_0=0, .BPC_PDC_CT=0, .BPC_PDC_MODE=1, .BPC_PDC_ORI_EN=0}},
    .cur_bi    ={.bits ={.BPC_PDC_ISL=7, .BPC_PDC_ITH=0, .BPC_PDC_BSL=6, .BPC_PDC_BTH=40}},
    .cur_ag    ={.bits ={.rsv_0=0, .BPC_PDC_GSL=8, .BPC_PDC_ASL=7}},
    .th_n      ={.bits ={.rsv_0=0, .BPC_PDC_NTH=80}},
    .diff_th_gr_1={.bits ={.rsv_0=0, .BPC_PDC_DIFF_TH_GR_Y1=4095, .BPC_PDC_DIFF_TH_GR_SLP1=0}},
    .diff_th_gr_2={.bits ={.rsv_0=0, .BPC_PDC_DIFF_TH_GR_X2=4095, .BPC_PDC_DIFF_TH_GR_Y2=4095, .BPC_PDC_DIFF_TH_GR_SLP2=0}},
    .diff_th_gr_3={.bits ={.rsv_0=0, .BPC_PDC_DIFF_TH_GR_X3=4095, .BPC_PDC_DIFF_TH_GR_Y3=4095, .BPC_PDC_DIFF_TH_GR_SLP3=0}},
    .diff_th_gb_1={.bits ={.rsv_0=0, .BPC_PDC_DIFF_TH_GB_Y1=4095, .BPC_PDC_DIFF_TH_GB_SLP1=0}},
    .diff_th_gb_2={.bits ={.rsv_0=0, .BPC_PDC_DIFF_TH_GB_X2=4095, .BPC_PDC_DIFF_TH_GB_Y2=4095, .BPC_PDC_DIFF_TH_GB_SLP2=0}},
    .diff_th_gb_3={.bits ={.rsv_0=0, .BPC_PDC_DIFF_TH_GB_X3=4095, .BPC_PDC_DIFF_TH_GB_Y3=4095, .BPC_PDC_DIFF_TH_GB_SLP3=0}},
    .diff_th_r_1={.bits ={.rsv_0=0, .BPC_PDC_DIFF_TH_R_Y1=4095, .BPC_PDC_DIFF_TH_R_SLP1=0}},
    .diff_th_r_2={.bits ={.rsv_0=0, .BPC_PDC_DIFF_TH_R_X2=4095, .BPC_PDC_DIFF_TH_R_Y2=4095, .BPC_PDC_DIFF_TH_R_SLP2=0}},
    .diff_th_r_3={.bits ={.rsv_0=0, .BPC_PDC_DIFF_TH_R_X3=4095, .BPC_PDC_DIFF_TH_R_Y3=4095, .BPC_PDC_DIFF_TH_R_SLP3=0}},
    .diff_th_b_1={.bits ={.rsv_0=0, .BPC_PDC_DIFF_TH_B_Y1=4095, .BPC_PDC_DIFF_TH_B_SLP1=0}},
    .diff_th_b_2={.bits ={.rsv_0=0, .BPC_PDC_DIFF_TH_B_X2=4095, .BPC_PDC_DIFF_TH_B_Y2=4095, .BPC_PDC_DIFF_TH_B_SLP2=0}},
    .diff_th_b_3={.bits ={.rsv_0=0, .BPC_PDC_DIFF_TH_B_X3=4095, .BPC_PDC_DIFF_TH_B_Y3=4095, .BPC_PDC_DIFF_TH_B_SLP3=0}},
    .bld_wt    ={.bits ={.rsv_0=0, .BPC_PDC_BLD_WT_SLP=15, .rsv_8=0}},
    .gain_g    ={.bits ={.rsv_0=0, .BPC_PDC_GAIN_GB=1024, .BPC_PDC_GAIN_GR=1024}},
    .gain_rb   ={.bits ={.rsv_0=0, .BPC_PDC_GAIN_B=1024, .BPC_PDC_GAIN_R=1024}},
};
