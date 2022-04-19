adb wait-for-device root
adb wait-for-device remount >nul 2>&1 

set curdir=%cd%

adb shell rm data/vendor/camera/*
adb shell rm data/vendor/camera/output/*

pushd %1
adb push spectracamsim_config.xml /data/vendor/camera/ >NUL
adb push stream_config.xml /data/vendor/camera/ >NUL
adb push meta_config.xml /data/vendor/camera/ >NUL
adb push isp_config.xml /data/vendor/camera/ >NUL

adb push spectracamsim_config_y2j.xml /data/vendor/camera/ >NUL
adb push stream_config_y2j.xml /data/vendor/camera/ >NUL

PUSHD %2
FOR %%i in (%4*) do adb push %%i /data/vendor/camera/%%i >NUL
adb push %4.bin /data/vendor/camera/output >NUL 
 
adb shell /vendor/bin/f2player -x /data/vendor/camera/spectracamsim_config.xml -f 1

adb shell cp /data/vendor/camera/output/*.yuv /data/vendor/camera/%4_0.yuv >NUL
adb shell mv /data/vendor/camera/output/*.p010 /data/vendor/camera/output/%4_0.p010 >NUL

adb shell /vendor/bin/f2player -x /data/vendor/camera/spectracamsim_config_y2j.xml -f 1

adb pull /data/vendor/camera/output/. %3 >NUL

cd %curdir%