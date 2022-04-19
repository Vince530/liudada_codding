adb wait-for-device root
adb wait-for-device remount
adb push camxoverridesettings_replay.txt /vendor/etc/camera/camxoverridesettings.txt

adb wait-for-device root
adb wait-for-device remount
adb shell stop camera-provider-2-4
adb shell stop cameraserver

echo check cameraserver if exist, reboot
adb shell ls /system/bin/cameraserver > /dev/null
echo return: %ERRORLEVEL%

if %ERRORLEVEL% equ 0 (
    echo need reboot
    adb shell mv ./vendor/bin/hw/android.hardware.camera.provider@2.4-service ./vendor/bin/hw/android.hardware.camera.provider@2.4-service.old
    adb shell mv ./vendor/bin/hw/android.hardware.camera.provider@2.4-service_64 ./vendor/bin/hw/android.hardware.camera.provider@2.4-service_64.old
    adb shell mv ./system/bin/cameraserver ./system/bin/cameraserver.old

    adb reboot
) else (
    echo no need to reboot
)

adb wait-for-device root
adb wait-for-device remount
adb shell cp /vendor/lib64/hw/com.qti.chi.override.so /vendor/lib64/

adb shell ls /vendor/lib64/com.qti.chi.override.so > /dev/null
echo return: %ERRORLEVEL%

REM echo return: %ERRORLEVEL%
REM if %ERRORLEVEL% equ 0 (
REM  echo /vendor/lib64/com.qti.chi.override.so found
REM ) else (
REM  echo copying com.qti.chi.override.so
REM  adb shell cp /vendor/lib64/hw/com.qti.chi.override.so /vendor/lib64/
REM )

REM echo check f2player app
REM adb shell "[ -f /vendor/bin/f2player ]"
REM echo return: %ERRORLEVEL%
REM if %ERRORLEVEL% equ 0 (
    REM echo f2player is on target
REM ) else (
    REM adb push ..\Binary\f2player /vendor/bin/f2player
REM )

