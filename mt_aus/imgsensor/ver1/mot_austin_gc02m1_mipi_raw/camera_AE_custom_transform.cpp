#include <utils/Log.h>
#include <fcntl.h>
#include <cutils/log.h>
#include <string.h>

#include "camera_custom_nvram.h"
#include "camera_custom_sensor.h"
#include "image_sensor.h"
#include "kd_imgsensor_define.h"
//#include "ae_param.h"

//camera_info_header
#include "camera_info_motaustingc02m1mipiraw.h"

#if MTK_CAM_NEW_NVRAM_SUPPORT
    #include INCLUDE_FILENAME_TUNING_MAPPING
#endif

#define NEW_BINNINGSUM_TRANSFORM 1

typedef NSFeature::AECustomTransform<SENSOR_ID, MODULE_INDEX> SensorInfoSingleton_T;

namespace NSFeature {

UINT32 transBinSum_motaustingc02m1mipiraw(VOID* const pData);
UINT32 transATR_motaustingc02m1mipiraw(VOID* const pData);

template <>
UINT32
SensorInfoSingleton_T::
impAECustomTransform(AE_CUSTOM_TRANSFORM_ENUM const AECusFuncType, VOID* const pData) const
{
    switch(AECusFuncType)
    {
        case AE_CUSTOM_TRANSFORM_BINSUM:
            transBinSum_motaustingc02m1mipiraw(pData);
            break;
        case AE_CUSTOM_TRANSFORM_ATR:
            transATR_motaustingc02m1mipiraw(pData);
            break;
        default:
            ALOGD("[impAECustomTransform] undefined function type");
            break;
    }
    return 0;
}

UINT32 transBinSumToEvSetting_motaustingc02m1mipiraw(strEvSetting &EvSetting, MUINT32 u4MaxAfeGain, MUINT32 u4Magnification)
{
    if(EvSetting.u4AfeGain * u4Magnification > u4MaxAfeGain){
        EvSetting.u4AfeGain = u4MaxAfeGain;
        EvSetting.u4IspGain *= (EvSetting.u4AfeGain * u4Magnification / u4MaxAfeGain);
    }else{
        EvSetting.u4AfeGain *= u4Magnification;
    }

    return 0;
}

UINT32 transBinSumToHdrEvSetting_motaustingc02m1mipiraw(strHdrEvSetting &HdrEvSetting, MUINT32 u4MaxAfeGain, MUINT32 u4Magnification)
{
    // 1. LE
    if(HdrEvSetting.i4LEAfeGain * u4Magnification > u4MaxAfeGain){
        HdrEvSetting.i4LEAfeGain = u4MaxAfeGain;
        HdrEvSetting.i4LEIspGain *= (HdrEvSetting.i4LEAfeGain * u4Magnification / u4MaxAfeGain);
    }else{
        HdrEvSetting.i4LEAfeGain *= u4Magnification;
    }
    HdrEvSetting.le_real_iso *= u4Magnification;

    // 2. ME
    if(HdrEvSetting.i4MEAfeGain * u4Magnification > u4MaxAfeGain){
        HdrEvSetting.i4MEAfeGain = u4MaxAfeGain;
        HdrEvSetting.i4MEIspGain *= (HdrEvSetting.i4MEAfeGain * u4Magnification / u4MaxAfeGain);
    }else{
        HdrEvSetting.i4MEAfeGain *= u4Magnification;
    }
    HdrEvSetting.me_real_iso *= u4Magnification;

    // 3. SE
    if(HdrEvSetting.i4SEAfeGain * u4Magnification > u4MaxAfeGain){
        HdrEvSetting.i4SEAfeGain = u4MaxAfeGain;
        HdrEvSetting.i4SEIspGain *= (HdrEvSetting.i4SEAfeGain * u4Magnification / u4MaxAfeGain);
    }else{
        HdrEvSetting.i4SEAfeGain *= u4Magnification;
    }
    HdrEvSetting.se_real_iso *= u4Magnification;

    return 0;
}

UINT32 transBinSum_motaustingc02m1mipiraw(VOID* const pData)
{
    strBinningSumTrans* pAEData = (strBinningSumTrans*)pData;
    MUINT32 u4BinningSumRatio   = pAEData->u4BinningSumRatio;
    MUINT32 u4MaximumBinningSumRatio   = pAEData->u4MaximumBinningSumRatio;
    MUINT32 u4Eposuretime       = pAEData->pRealSetting->EvSetting.u4Eposuretime;
    MUINT32 u4AfeGain           = pAEData->pRealSetting->EvSetting.u4AfeGain;
    MUINT32 u4IspGain           = pAEData->pRealSetting->EvSetting.u4IspGain;
    MUINT32 u4ISO               = pAEData->pRealSetting->u4ISO;
    MUINT32 u4MiniISOGain       = pAEData->pAeNVRAM->hw.params.iso_gain;    // Min ISO
    MUINT32 u4MaxAfeGain       = pAEData->pAeNVRAM->hw.params.max_gain;    // Max sensor gain
    MUINT32 u4Magnification = u4MaximumBinningSumRatio / u4BinningSumRatio;

#if NEW_BINNINGSUM_TRANSFORM
    /* new scheme of binning sum transform:
       modify exposure parameters by multiplying (u4MaximumBinningSumRatio / u4BinningSumRatio)*/
    ALOGD("[%s()] + u4Magnification:%d targetMode:%d\n", __FUNCTION__, u4Magnification, pAEData->pRealSetting->i4AETarget);

    if(u4Magnification == 1) return 0;

    transBinSumToEvSetting_motaustingc02m1mipiraw(pAEData->pRealSetting->EvSetting, u4MaxAfeGain, u4Magnification);
    transBinSumToHdrEvSetting_motaustingc02m1mipiraw(pAEData->pRealSetting->HdrEvSetting, u4MaxAfeGain, u4Magnification);

    u4ISO *= u4Magnification;

    ALOGD("[%s()] - u4Eposuretime:%d u4AfeGain:%d u4IspGain:%d u4ISO:%d u4MiniISO:%d MiniAfeGain:%d MiniIspGain:%d\n", __FUNCTION__,
        pAEData->pRealSetting->EvSetting.u4Eposuretime, pAEData->pRealSetting->EvSetting.u4AfeGain,
        pAEData->pRealSetting->EvSetting.u4IspGain, u4ISO, u4MiniISOGain, AE_GAIN_BASE_AFE, AE_GAIN_BASE_ISP);
#else
    // ALOGD("[%s()] + u4Eposuretime:%d u4AfeGain:%d u4IspGain:%d u4ISO:%d\n", __FUNCTION__,
    //     u4Eposuretime, u4AfeGain, u4IspGain, u4ISO);
    if (u4ISO > u4MiniISOGain * u4BinningSumRatio)
    {
        if (u4IspGain >= AE_GAIN_BASE_ISP * u4BinningSumRatio)
        {
            u4IspGain = u4IspGain / u4BinningSumRatio;
            pAEData->pRealSetting->EvSetting.u4IspGain = u4IspGain;
        }
        else
        {
            u4AfeGain = u4AfeGain * u4IspGain / (AE_GAIN_BASE_ISP * u4BinningSumRatio);
            u4IspGain = AE_GAIN_BASE_ISP;
            pAEData->pRealSetting->EvSetting.u4AfeGain = u4AfeGain;
            pAEData->pRealSetting->EvSetting.u4IspGain = u4IspGain;
        }
        u4ISO = u4ISO / u4BinningSumRatio;
        pAEData->pRealSetting->u4ISO = u4ISO;
    }
    else
    {
        u4Eposuretime = u4Eposuretime / u4BinningSumRatio;
        pAEData->pRealSetting->EvSetting.u4Eposuretime = u4Eposuretime;
    }
    
    ALOGD("[%s()] - u4Eposuretime:%d u4AfeGain:%d u4IspGain:%d u4ISO:%d u4MiniISO:%d MiniAfeGain:%d MiniIspGain:%d\n", __FUNCTION__,
        u4Eposuretime, u4AfeGain, u4IspGain, u4ISO, u4MiniISOGain, AE_GAIN_BASE_AFE, AE_GAIN_BASE_ISP);
#endif

    return 0;
}

UINT32 transATR_motaustingc02m1mipiraw(VOID* const pData)
{
    strAEOutput* pAEData = (strAEOutput*)pData;
    // to do for ATR customization
    return 0;
}

};  //  NSFeature