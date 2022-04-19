..\Simulation\7.3.1.16\Simulator\Spectra480\ParameterParser.exe ..\Simulation\output\com.qti.tuned.lenovo_ov8856_kingcome_front_i.bin p ..\code\lenovo_ov8856_kingcome_front_i
@echo off
adb root
adb remount
timeout 1
adb push output\com.qti.tuned.lenovo_ov8856_kingcome_front_i.bin /vendor/lib64/camera/com.qti.tuned.lenovo_ov8856_kingcome_front_i.bin
timeout 3
echo 即将重启设备，按任意键退出---------Spance---------
adb reboot
timeout 33 & exit