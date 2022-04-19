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

#Check for basiccam
$result = dird \data\vendor\bin\BasicCam.exe | out-string

if ($result -eq $null) {
"Basiccam not found. Copying basiccam now"
mkdird \data\vendor\bin\
putd $currentScriptPath\..\binary\basiccam*.* \data\vendor\bin\
}
else
{
write-host "Basiccam found"
}

return;

}

