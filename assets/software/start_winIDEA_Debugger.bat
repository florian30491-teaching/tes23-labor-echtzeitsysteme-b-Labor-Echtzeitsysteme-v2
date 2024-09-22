@echo off
setlocal

REM Relativer Pfad zum Debugger
set DEBUGGER_PATH=temp_winIDEA\winIDEA.exe

REM Starten des Debuggers
start "" %DEBUGGER_PATH%

echo Debugger gestartet.
endlocal