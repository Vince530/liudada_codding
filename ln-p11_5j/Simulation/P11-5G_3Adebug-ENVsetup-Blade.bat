@echo off

echo $wait for device
adb wait-for-device
echo $root
adb root
timeout 2
echo $remount
adb remount
timeout 3
echo $getenforce
adb shell getenforce
echo $setenforce 0
adb shell setenforce 0
echo $getenforce
adb shell getenforce
echo $push Capture3AData.dat data/vendor/camera/
adb push output\Capture3AData.dat data/vendor/camera/
echo $chmod 777 data/vendor/camera/
adb shell chmod 777 data/vendor/camera/
echo $chmod 777 data/vendor/camera/Capture3AData.dat
adb shell chmod 777 data/vendor/camera/Capture3AData.dat
echo $[OK]Completed ENVsetup for 3Adebugdata !!!
timeout 3
adb shell setprop persist.camera.tuning.on 1
adb shell "echo enable3ADebugData=TRUE >> /vendor/etc/camera/camxoverridesettings.txt" 
adb shell "echo enableTuningMetadata=TRUE >> /vendor/etc/camera/camxoverridesettings.txt"


adb shell "ps -A | grep  cameraserver | awk '{print $2}' | xargs kill -9"
pause