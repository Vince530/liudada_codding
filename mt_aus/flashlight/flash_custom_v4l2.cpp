#define LOG_TAG "flash_custom_v4l2.cpp"
#define MTK_LOG_ENABLE 1

#include <cutils/log.h>
//#include "mtkcam/def/BuiltinTypes.h"
//#include "kd_camera_feature.h"
//#include "camera_custom_nvram.h"
#include "flash_tuning_custom.h"
#include "strobe_param.h"
#include <string.h>

/* flashlight devices */
struct flashlight_device_id {
        int type;
        int ct;
        int part;
        char name[FLASHLIGHT_NAME_SIZE]; /* device name */
        int channel;                     /* device channel */
        int decouple;                    /* device decouple */
};

const struct flashlight_device_id flashlight_id[] = {
        /* {TYPE, CT, PART, "NAME", CHANNEL, DECOUPLE} */
        {STROBE_TYPE_REAR, 1, 1, "mt6362_flash_ch1", 0, 0},
        {STROBE_TYPE_REAR, 2, 1, "mt6362_flash_ch2", 0, 0},
        {STROBE_TYPE_REAR, 1, 2, "led0", 0, 0},
        {STROBE_TYPE_REAR, 2, 2, "led1", 0, 0},
};

const int flashlight_device_num =
        sizeof(flashlight_id) / sizeof(struct flashlight_device_id);

#define MAX_DUTY_1_1_1 32
#define MAX_TORCH_DUTY_1_1_1 16

#define MAX_DUTY_1_2_1 32
#define MAX_TORCH_DUTY_1_2_1 16

#define MAX_DUTY_DEFAULT 18
#define MAX_TORCH_DUTY_DEFAULT 6

const int current_1_1_1[MAX_DUTY_1_1_1]
{
          25,   50,  75, 100, 125, 150, 175,  200,  225,  250,
         275,  300, 325, 350, 375, 400, 450,  500,  550,  600,
         650,  700, 750, 800, 850, 900, 950, 1000, 1050, 1100,
        1150, 1200
};
const int current_1_2_1[MAX_DUTY_1_2_1]
{
          25,   50,  75, 100, 125, 150, 175,  200,  225,  250,
         275,  300, 325, 350, 375, 400, 450,  500,  550,  600,
         650,  700, 750, 800, 850, 900, 950, 1000, 1050, 1100,
        1150, 1200
};
const int current_default[MAX_DUTY_DEFAULT]
{
         48,  93,  141,  188,  281,  375,  469,  563, 656, 750,
        844, 938, 1031, 1125, 1219, 1313, 1406, 1500
};

int cust_getMaxDuty(int type, int ct, int part)
{
    if (type == STROBE_TYPE_REAR && ct == 1 && part == 1)
        return MAX_DUTY_1_1_1;
    else if (type == STROBE_TYPE_REAR && ct == 2 && part == 1)
        return MAX_DUTY_1_2_1;
    return MAX_DUTY_DEFAULT;
}

int cust_getMaxTorchDuty(int type, int ct, int part)
{
    if (type == STROBE_TYPE_REAR && ct == 1 && part == 1)
        return MAX_TORCH_DUTY_1_1_1;
    else if (type == STROBE_TYPE_REAR && ct == 2 && part == 1)
        return MAX_TORCH_DUTY_1_2_1;
    return MAX_TORCH_DUTY_DEFAULT;
}

int cust_duty2Current(int type, int ct, int part, int duty)
{
    if (type == STROBE_TYPE_REAR && ct == 1 && part == 1){
        if (duty < 0 || duty >= MAX_DUTY_1_1_1)
            return 25;
        else
            return current_1_1_1[duty];
    }else if (type == STROBE_TYPE_REAR && ct == 2 && part == 1){
        if (duty < 0 || duty >= MAX_DUTY_1_2_1)
            return 25;
        else
            return current_1_2_1[duty];
    }

    if (duty < 0 || duty >= MAX_DUTY_DEFAULT)
        return 25;
    return current_default[duty];
}

int cust_getDriverName(int type, int ct, int part, char *driverName)
{
    ALOGD("%s(): type(%d), ct(%d), part(%d).",
            __FUNCTION__, type, ct, part);
    for (int i = 0; i < flashlight_device_num; i++) {
        if (type == flashlight_id[i].type &&
                ct == flashlight_id[i].ct &&
                part == flashlight_id[i].part) {
            strncpy(driverName, flashlight_id[i].name,
                    strlen(flashlight_id[i].name));
            return 0;
        }
    }
    return -1;
}
