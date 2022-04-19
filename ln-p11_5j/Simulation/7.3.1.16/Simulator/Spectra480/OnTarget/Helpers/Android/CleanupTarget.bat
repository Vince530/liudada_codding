adb wait-for-device root
adb wait-for-device remount

adb shell rm data/vendor/camera/*
adb shell rm data/vendor/camera/metadata/*
adb shell rm data/vendor/camera/output/*
adb shell rm sdcard/dcim/camera/*
adb shell mkdir data/vendor/camera/metadata





