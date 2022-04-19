adb wait-for-device root
adb wait-for-device remount
adb push camxoverridesettings_capture.txt /vendor/etc/camera/camxoverridesettings.txt

adb wait-for-device root
adb wait-for-device remount

adb shell stop camera-provider-2-4
adb shell mv ./vendor/bin/hw/android.hardware.camera.provider@2.4-service.old ./vendor/bin/hw/android.hardware.camera.provider@2.4-service
adb shell mv ./vendor/bin/hw/android.hardware.camera.provider@2.4-service_64.old ./vendor/bin/hw/android.hardware.camera.provider@2.4-service_64

adb shell stop cameraserver
adb shell mv ./system/bin/cameraserver.old ./system/bin/cameraserver

adb shell setprop persist.sys.camera.devoption.debug 100
adb shell sync

adb reboot 

adb wait-for-device root
adb wait-for-device remount

REM adb shell start cameraserver
REM adb shell start camera-provider-2-4


adb shell rm data/vendor/camera/*
adb shell rm data/vendor/camera/metadata/*
adb shell rm data/vendor/camera/output/*
adb shell rm sdcard/dcim/camera/*
adb shell mkdir data/vendor/camera/metadata



