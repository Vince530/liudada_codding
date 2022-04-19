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

PUSHD %2
FOR %%i in (%4*) do adb push %%i /data/vendor/camera/%%i >NUL
 
adb shell /vendor/bin/f2player -x /data/vendor/camera/spectracamsim_config.xml -f 1

adb pull /data/vendor/camera/output/. %3 >NUL

cd %curdir%