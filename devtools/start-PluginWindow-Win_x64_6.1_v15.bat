@echo off
REM This command file lets you start Gocad.
REM DO NOT EDIT THIS FILE DIRECTLY!
REM Change settings and rerun configure.pl instead

SETLOCAL

REM Change to directory of start-PluginWindow so it can be run from anywhere
cd /d %~dp0

set OUTPUT_DIRECTORY=Win_x64_6.1_v15

call "setenv-Win_x64_6.1_v15.bat"
"%GOCADROOT%\bin\%OUTPUT_DIRECTORY%\gocad_run.exe"
