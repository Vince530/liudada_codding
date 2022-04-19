set curdir=%cd%
@echo off
adb get-state >nul 2>&1
if %ERRORLEVEL% equ 0 (
	pushd Android
)else (
	pushd Win
)
CALL InitPlayback.bat

cd %curdir%