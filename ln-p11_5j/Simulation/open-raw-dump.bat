
echo disable reproc-allow
adb root
adb wait-for-device
adb remount
adb wait-for-device

echo start...

adb shell setprop persist.vendor.camera.autoImageDump 1
adb shell setprop persist.vendor.camera.autoImageDumpMask 0x1
adb shell setprop persist.vendor.camera.reprocessDump 1
adb shell setprop persist.vendor.camera.autoImageDumpIFEoutputPortMask 0
::0xF08
 
adb reboot


echo end...

pause
