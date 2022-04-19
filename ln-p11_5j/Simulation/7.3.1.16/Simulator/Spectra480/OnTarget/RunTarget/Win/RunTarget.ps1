Add-Type -AssemblyName System.Windows.Forms
$currentScriptPath = Split-Path -Path $MyInvocation.MyCommand.Path

. .\WindowsDeviceID.ps1

write-host "Device ID: $deviceId"

if ($deviceId -eq $null) {
$output = [System.Windows.Forms.MessageBox]::Show('Set device Id in .\WindowsDeviceID.ps1')
'No devices found'
return -1
} else {
open-device $deviceId

rmdird /S /Q \data\vendor\camera\output
deld \data\vendor\camera\*

$currdir = $args[0]
$inputdir = $args[1]
$outputdir = $args[2]
$inputFileName = $args[3]

putd $currdir\spectracamsim_config.xml \data\vendor\camera
putd $currdir\stream_config.xml \data\vendor\camera
putd $currdir\meta_config.xml \data\vendor\camera
putd $currdir\isp_config.xml \data\vendor\camera

# copy RAW files and tintless data
putd $inputdir\$inputFileName* \data\vendor\camera\

regd add "HKLM\SYSTEM\CurrentControlSet\Control\Qualcomm\Camera" /v EnableDMFTFrameDump /t REG_DWORD /d 0 /f
regd add "HKLM\SYSTEM\CurrentControlSet\Control\Qualcomm\Camera" /v ForceMFNR /t REG_DWORD /d 0 /f
regd add "HKLM\SYSTEM\CurrentControlSet\Control\Qualcomm\Camera" /v EnableStatsDump /t REG_DWORD /d 0 /f
regd add "HKLM\SYSTEM\CurrentControlSet\Control\Qualcomm\Camera" /v OnTargetSim /t REG_DWORD /d 1 /f

# Check for camera id
[string]$getID = $inputFileName.Substring(3,1);
[int]$cameraId = [convert]::ToInt32($getID)

# 0 -> RFC
# 1-> FFC
if (($cameraId -eq 0) -or ($cameraId -eq 1))
{
    Write-Host "Using camera ID:$cameraId"

    execd \data\vendor\bin\basiccam.exe "-tid 19 -d $cameraId"

    "Copying output files to $outputdir"

    getd \data\vendor\camera\output\*.yuv $outputdir
}
else
{
    write-host "Invalid camera id:$cameraId"
}

return;

}


