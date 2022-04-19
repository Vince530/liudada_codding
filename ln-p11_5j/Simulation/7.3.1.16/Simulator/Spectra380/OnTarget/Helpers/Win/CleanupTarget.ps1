Add-Type -AssemblyName System.Windows.Forms

$currentScriptPath = Split-Path -Path $MyInvocation.MyCommand.Path
. .\WindowsDeviceID.ps1

write-host "Device ID: $deviceId"

$homeDir = Resolve-path ~

if ($deviceId -eq $null) {
$output = [System.Windows.Forms.MessageBox]::Show('Set device Id in ' + $homeDir + '\AppData\Roaming\Qualcomm\Chromatix7\Simulation\OnTarget\Win\WindowsDeviceID.ps1')
'No devices found'
return -1
} else {
open-device $deviceId

deld \data\vendor\camera\*
deld c:\Users\HCKtest\Pictures\Camera` Roll\*.jpg
rmdird /S /Q \data\vendor\camera\output
deld \data\vendor\camera\*

regd add "HKLM\SYSTEM\CurrentControlSet\Control\Qualcomm\Camera" /v EnableDMFTFrameDump /t REG_DWORD /d 0 /f
regd add "HKLM\SYSTEM\CurrentControlSet\Control\Qualcomm\Camera" /v ForceMFNR /t REG_DWORD /d 0 /f
regd add "HKLM\SYSTEM\CurrentControlSet\Control\Qualcomm\Camera" /v EnableStatsDump /t REG_DWORD /d 0 /f
    regd add "HKLM\SYSTEM\CurrentControlSet\Control\Qualcomm\Camera" /v OnTargetSim /t REG_DWORD /d 0 /f

return;

}

