powershell Set-ExecutionPolicy -Scope "CurrentUser" -ExecutionPolicy "Unrestricted"

SET currdir=%1%
SET inputdir=%2%
SET outdir=%3%
SET inputFileName=%4%

C:\Windows\SysWOW64\WindowsPowerShell\v1.0\powershell.exe -command "& %~dp0\RunTarget.ps1 '%currdir%' '%inputdir%' '%outdir%' '%inputFileName%'"