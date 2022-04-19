@echo off
@echo 打印流TAG:  TuningMode:
adb root
adb remount
pause

echo start...

adb shell "echo enable3ADebugData=TRUE >> /vendor/etc/camera/camxoverridesettings.txt" 
adb shell "echo enableTuningMetadata=TRUE >> /vendor/etc/camera/camxoverridesettings.txt"
adb shell setprop persist.vendor.camera.logEntryExitMask 0
adb shell setprop persist.vendor.camera.logInfoMask 0x10
adb shell setprop persist.vendor.camera.logVerboseMask 0x10
adb shell setprop persist.vendor.camera.systemLogEnable 1
adb shell sync

echo end...
pause
adb reboot

