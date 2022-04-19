#ifndef _CAM_IDX_DATA_H_
#define _CAM_IDX_DATA_H_

#include "tuning_mapping/cam_idx_struct_ext.h"
#include "tuning_mapping/cam_idx_struct_int.h"

using namespace NSIspTuning;
#include "cam_idx_data_AE.inc"
#include "cam_idx_data_AF.inc"
#include "cam_idx_data_AWB.inc"
#include "cam_idx_data_Flash_AE.inc"
#include "cam_idx_data_Flash_AWB.inc"
#include "cam_idx_data_Flash_Calibration.inc"
#include "cam_idx_data_LCE.inc"
#include "cam_idx_data_GMA.inc"
#include "cam_idx_data_DCE.inc"
#include "cam_idx_data_DM.inc"
#include "cam_idx_data_YNR.inc"
#include "cam_idx_data_YNR_LCE_LINK.inc"
#include "cam_idx_data_YNR_FD.inc"
#include "cam_idx_data_CNR_CNR.inc"
#include "cam_idx_data_EE.inc"
#include "cam_idx_data_NR3D.inc"
#include "cam_idx_data_HFG.inc"
#include "cam_idx_data_OBC.inc"
#include "cam_idx_data_BPC_BPC.inc"
#include "cam_idx_data_BPC_CT.inc"
#include "cam_idx_data_BPC_PDC.inc"
#include "cam_idx_data_LDNR.inc"
#include "cam_idx_data_CNR_CCR.inc"
#include "cam_idx_data_CNR_ABF.inc"
#include "cam_idx_data_FUS.inc"
#include "cam_idx_data_ZFUS.inc"
#include "cam_idx_data_MFNR_THRES.inc"
#include "cam_idx_data_MFNR.inc"
#include "cam_idx_data_BSS.inc"
#include "cam_idx_data_CA_LTM.inc"
#include "cam_idx_data_CCM.inc"
#include "cam_idx_data_COLOR_PARAM.inc"
#include "cam_idx_data_COLOR.inc"
#include "cam_idx_data_ClearZoom.inc"
#include "cam_idx_data_DSDN.inc"
#include "cam_idx_data_YNR_TBL.inc"
#include "cam_idx_data_LTM.inc"
#include "cam_idx_data_HLR.inc"
#include "cam_idx_data_AKS.inc"
#include "cam_idx_data_FRZ.inc"
#include "cam_idx_data_RRZ.inc"
#include "cam_idx_data_SW_MSF.inc"
#include "cam_idx_data_MSYUV.inc"
#include "cam_idx_data_OMC.inc"
#include "cam_idx_data_MSNR_THRES.inc"
#include "cam_idx_data_AD_NR.inc"
#include "cam_idx_data_BPC_BPC_R3.inc"
#include "cam_idx_data_BPC_CT_R3.inc"
#include "cam_idx_data_BPC_PDC_R3.inc"
#include "cam_idx_data_CCM_R3.inc"
#include "cam_idx_data_GMA_R3.inc"
#include "cam_idx_data_OBC_R2.inc"
#include "cam_idx_data_BPC_BPC_R2.inc"
#include "cam_idx_data_AIISP_EV.inc"
#include "cam_idx_data_AIISP_ISO_FEFM.inc"
#include "cam_idx_data_AIISP_ISO_SWME.inc"
#include "cam_idx_data_AIISP_ISO_APU_Part1.inc"
#include "cam_idx_data_AIISP_ISO_APU_Part2.inc"
#include "cam_idx_data_AIISP_ISO_APU_Part3.inc"
#include "cam_idx_data_AIISP_ISO_PostSW.inc"
#include "cam_idx_data_AIISP_ISO_DRC.inc"
#include "cam_idx_data_AIISP_LV_Pre.inc"
#include "cam_idx_data_AIAWB_MA.inc"
#include "cam_idx_data_AIAWB_SA.inc"
#include "cam_idx_data_OBC_R3.inc"
#include "cam_idx_data_BPC_CT_R2.inc"
#include "cam_idx_data_BPC_PDC_R2.inc"
#include "cam_idx_data_GGM_E2E.inc"
#include "cam_idx_data_P1GGM.inc"

#define SCENARIO_NUM 48

#define GEN_TOOL_TIMESTAMP "2021-11-26T16:20:44.015180"

static char _scenarios[SCENARIO_NUM][64] =
{
        "Scene_Capture",
        "Scene_Capture_4cell",
        "Face_Capture",
        "Face_Capture_4cell",
        "Panorama",
        "Scene_Preview",
        "Scene_Preview_ZSD",
        "Face_Preview",
        "Face_Preview_ZSD",
        "Video_1080",
        "Video_1080_2X",
        "Video_1080_4X",
        "Video_1080_8X",
        "EIS_Video_1080",
        "EIS_Video_1080_2X",
        "EIS_Video_1080_4X",
        "EIS_Video_1080_8X",
        "Video_Capture",
        "Video_Capture_2X",
        "Video_Capture_4X",
        "Video_Capture_8X",
        "LLHDR_Capture",
        "LLHDR_Face_Capture",
        "Bokeh_Capture",
        "Flash_Capture",
        "Scene_Preview_ZSD_Flash",
        "Face_Preview_ZSD_Flash",
        "P1_YUV",
        "Zoom_Capture_2X",
        "Zoom_Capture_4X",
        "Zoom_Capture_8X",
        "Zoom_Preview_2X",
        "Zoom_Preview_4X",
        "Zoom_Preview_8X",
        "50_Capture",
        "50_Preview",
        "Night_Vision_Capture",
        "Slow_Motion",
        "Slow_Motion_2X",
        "EIS_Slow_Motion",
        "EIS_Slow_Motion_2X",
        "E2EHDR_Preview",
        "E2EHDR_Video",
        "Default_Capture",
        "Default_Preview",
        "Default_Video",
        "UserDefine",
        "Mismatch",
};

static EISO_GROUP_T _iso_group[SCENARIO_NUM] =
{
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_02,
    EISO_GROUP_00,
    EISO_GROUP_00,
};

#define _EIspProfile_NUM_ 123
#define _ESensorMode_NUM_ 10
#define _EFrontBin_NUM_ 2
#define _ESize_NUM_ 4
#define _EFlash_NUM_ 4
#define _EApp_NUM_ 17
#define _EFaceDetection_NUM_ 2
#define _ECustom_00_NUM_ 3
#define _ECustom_01_NUM_ 3
#define _EZoom_NUM_ 4
#define _EIspLV_NUM_ 10
#define _ELV_NUM_ 6
#define _ECT_NUM_ 10
#define _EISO_NUM_ 20

#include "cam_idx_data_Check.inc"

const IDX_MODULE_ARRAY idx_mod_array = {
    {
        _EIspProfile_NUM_,
        _ESensorMode_NUM_,
        _EFrontBin_NUM_,
        _ESize_NUM_,
        _EFlash_NUM_,
        _EApp_NUM_,
        _EFaceDetection_NUM_,
        _ECustom_00_NUM_,
        _ECustom_01_NUM_,
        _EZoom_NUM_,
        _EIspLV_NUM_,
        _ELV_NUM_,
        _ECT_NUM_,
        _EISO_NUM_,
    },
    {
        (IDX_BASE_T*)&cam_data_AE,
        (IDX_BASE_T*)&cam_data_AF,
        (IDX_BASE_T*)&cam_data_AWB,
        (IDX_BASE_T*)&cam_data_Flash_AE,
        (IDX_BASE_T*)&cam_data_Flash_AWB,
        (IDX_BASE_T*)&cam_data_Flash_Calibration,
        (IDX_BASE_T*)&cam_data_LCE,
        (IDX_BASE_T*)&cam_data_GMA,
        (IDX_BASE_T*)&cam_data_DCE,
        (IDX_BASE_T*)&cam_data_DM,
        (IDX_BASE_T*)&cam_data_YNR,
        (IDX_BASE_T*)&cam_data_YNR_LCE_LINK,
        (IDX_BASE_T*)&cam_data_YNR_FD,
        (IDX_BASE_T*)&cam_data_CNR_CNR,
        (IDX_BASE_T*)&cam_data_EE,
        (IDX_BASE_T*)&cam_data_NR3D,
        (IDX_BASE_T*)&cam_data_HFG,
        (IDX_BASE_T*)&cam_data_OBC,
        (IDX_BASE_T*)&cam_data_BPC_BPC,
        (IDX_BASE_T*)&cam_data_BPC_CT,
        (IDX_BASE_T*)&cam_data_BPC_PDC,
        (IDX_BASE_T*)&cam_data_LDNR,
        (IDX_BASE_T*)&cam_data_CNR_CCR,
        (IDX_BASE_T*)&cam_data_CNR_ABF,
        (IDX_BASE_T*)&cam_data_FUS,
        (IDX_BASE_T*)&cam_data_ZFUS,
        (IDX_BASE_T*)&cam_data_MFNR_THRES,
        (IDX_BASE_T*)&cam_data_MFNR,
        (IDX_BASE_T*)&cam_data_BSS,
        (IDX_BASE_T*)&cam_data_CA_LTM,
        (IDX_BASE_T*)&cam_data_CCM,
        (IDX_BASE_T*)&cam_data_COLOR_PARAM,
        (IDX_BASE_T*)&cam_data_COLOR,
        (IDX_BASE_T*)&cam_data_ClearZoom,
        (IDX_BASE_T*)&cam_data_DSDN,
        (IDX_BASE_T*)&cam_data_YNR_TBL,
        (IDX_BASE_T*)&cam_data_LTM,
        (IDX_BASE_T*)&cam_data_HLR,
        (IDX_BASE_T*)&cam_data_AKS,
        (IDX_BASE_T*)&cam_data_FRZ,
        (IDX_BASE_T*)&cam_data_RRZ,
        (IDX_BASE_T*)&cam_data_SW_MSF,
        (IDX_BASE_T*)&cam_data_MSYUV,
        (IDX_BASE_T*)&cam_data_OMC,
        (IDX_BASE_T*)&cam_data_MSNR_THRES,
        (IDX_BASE_T*)&cam_data_AD_NR,
        (IDX_BASE_T*)&cam_data_BPC_BPC_R3,
        (IDX_BASE_T*)&cam_data_BPC_CT_R3,
        (IDX_BASE_T*)&cam_data_BPC_PDC_R3,
        (IDX_BASE_T*)&cam_data_CCM_R3,
        (IDX_BASE_T*)&cam_data_GMA_R3,
        (IDX_BASE_T*)&cam_data_OBC_R2,
        (IDX_BASE_T*)&cam_data_BPC_BPC_R2,
        (IDX_BASE_T*)&cam_data_AIISP_EV,
        (IDX_BASE_T*)&cam_data_AIISP_ISO_FEFM,
        (IDX_BASE_T*)&cam_data_AIISP_ISO_SWME,
        (IDX_BASE_T*)&cam_data_AIISP_ISO_APU_Part1,
        (IDX_BASE_T*)&cam_data_AIISP_ISO_APU_Part2,
        (IDX_BASE_T*)&cam_data_AIISP_ISO_APU_Part3,
        (IDX_BASE_T*)&cam_data_AIISP_ISO_PostSW,
        (IDX_BASE_T*)&cam_data_AIISP_ISO_DRC,
        (IDX_BASE_T*)&cam_data_AIISP_LV_Pre,
        (IDX_BASE_T*)&cam_data_AIAWB_MA,
        (IDX_BASE_T*)&cam_data_AIAWB_SA,
        (IDX_BASE_T*)&cam_data_OBC_R3,
        (IDX_BASE_T*)&cam_data_BPC_CT_R2,
        (IDX_BASE_T*)&cam_data_BPC_PDC_R2,
        (IDX_BASE_T*)&cam_data_GGM_E2E,
        (IDX_BASE_T*)&cam_data_P1GGM,
    },
    SCENARIO_NUM,
    (char (*)[][64])&_scenarios
};
#endif