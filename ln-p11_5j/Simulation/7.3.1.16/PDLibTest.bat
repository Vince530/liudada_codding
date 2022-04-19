@echo off

echo Start PDLib Test

echo Wait for device
adb wait-for-device root
adb wait-for-device remount

echo SetProp for PDLib test and logging

adb shell "mkdir -p vendor/etc/camera"
adb shell "echo enablePDLibLog=1 >> /vendor/etc/camera/camxoverridesettings.txt" 
adb shell "echo enablePDLibTestMode=1 >> /vendor/etc/camera/camxoverridesettings.txt" 

echo Reboot
adb reboot

echo Start logcat in another process

set logName=PDLibTest.log

START CMD /K CALL "CAFScanLogcat.bat" %logName%
adb wait-for-device root
adb wait-for-device remount

echo Turning on Device Open Camera
adb shell input keyevent 82
timeout 2 >nul
adb shell input keyevent 82
timeout 2 >nul
adb shell svc power stayon true
REM Start camera 
adb shell am start -a android.media.action.STILL_IMAGE_CAMERA --ei android.intent.extras.CAMERA_FACING 0

echo.
echo Once focus is finished, press any key to continue
echo.
echo.
pause

adb shell input keyevent 4
timeout 2 >nul
adb shell rm /vendor/etc/camera/camxoverridesettings.txt
adb reboot