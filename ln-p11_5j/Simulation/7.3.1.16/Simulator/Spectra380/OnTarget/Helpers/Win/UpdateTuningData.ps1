# User should input device Id here
$deviceId = "10.62.36.91"
$binPath = "D:\Builds\camera.win.10.0.0317\CamZ\DeviceMFT\CaptureDevice\CamX\chi-cdk\vendor\bin\"
$rearSensorTuningBin = "com.qti.tuned.qtech_ov13855.bin"
$frontSensorTuningBin = "com.qti.tuned.akerr_ov5695.bin"

Add-Type -AssemblyName System.Windows.Forms
$fileName = $MyInvocation.MyCommand.Name
$currentScriptPath = Split-Path -Path $MyInvocation.MyCommand.Path

function GetRearSensorExtnFileRepo {
    if ($rearSensorTuningBin -eq $null)
    {
        $output = [System.Windows.Forms.MessageBox]::Show('Set rear sensor tuning bin in ' + $fileName)
        write-host "Set rear sensor tuning bin in $fileName !!!"
        return $null
    }
    else
    {
        $rearSensorDir = dird c:\windows\System32\DriverStore\FileRepository\qccamrearsensor_extension*
        return $rearSensorDir.Name
    }
}

function GetFrontSensorExtnFileRepo {
    if ($frontSensorTuningBin -eq $null)
    {
        $output = [System.Windows.Forms.MessageBox]::Show('Set front sensor tuning bin in ' + $fileName)
        write-host "Set front sensor tuning bin in $fileName !!!"
        return $null
    }
    else
    {
        $frontSensorDir = dird c:\windows\System32\DriverStore\FileRepository\qccamfrontsensor_extension*
        return $frontSensorDir.Name
    }
}

write-host "Device ID: $deviceId"

if ($deviceId -eq $null) {
[System.Windows.Forms.MessageBox]::Show('Set device Id in ' + $fileName)
'No devices found'
return -1
} else {
    open-device $deviceId

    $rearSensorFileRepo = GetRearSensorExtnFileRepo
    if ($rearSensorFileRepo -ne $null)
    {
        putd $binPath\$rearSensorTuningBin \windows\System32\DriverStore\FileRepository\$rearSensorFileRepo
    }


    $frontSensorFileRepo = GetFrontSensorExtnFileRepo
    if ($frontSensorFileRepo  -ne $null)
    {
        putd $binPath\$frontSensorTuningBin \windows\System32\DriverStore\FileRepository\$frontSensorFileRepo
    }

    cmdd shutdown /r /t 0

    return;

}

