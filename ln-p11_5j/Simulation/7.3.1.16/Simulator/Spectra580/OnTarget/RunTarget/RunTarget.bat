set curdir=%cd%

adb get-state
if %ERRORLEVEL% equ 0 (
	pushd %~dp0\Android
)else (
	pushd %~dp0\Win
)
CALL RunTarget.bat %~dp0 inputdir outputdir inputfilename

cd %curdir%