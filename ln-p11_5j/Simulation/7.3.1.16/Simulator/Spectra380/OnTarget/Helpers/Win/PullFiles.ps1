Add-Type -AssemblyName System.Windows.Forms
$fileName = $MyInvocation.MyCommand.Name

# User should input device Id (KDNet or LAN IP address)here
$deviceId = "10.62.36.91"

write-host "Device ID: $deviceId"

if ($deviceId -eq $null) {
[System.Windows.Forms.MessageBox]::Show('Set device Id in ' + $fileName)
'No devices found'
return -1
} else {
open-device $deviceId

getd \data\vendor\camera\*.* $pwd
getd c:\Users\HCKtest\Pictures\Camera` Roll\*.jpg $pwd

return;

}

