adb wait-for-device root
adb wait-for-device remount

adb shell stop camera-provider-2-4
adb shell stop cameraserver

if not exist "C:\TuningData\" mkdir C:\TuningData


C:\ParameterParser\ParameterParser "C:\TuningData\com.qti.tuned.sunny_imx519.bin" p "C:\Dropbox\Feature2_OnTarget\sm8250_sunny_imx519"

echo finish creating tuning binary

adb push C:\TuningData\com.qti.tuned.sunny_imx519.bin /vendor/lib64/camera/com.qti.tuned.sunny_imx519.bin

adb shell start cameraserver
adb shell start camera-provider-2-4


adb wait-for-device
adb wait-for-device root
adb wait-for-device remount



