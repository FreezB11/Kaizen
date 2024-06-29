@echo off
REM Check if MinGW is installed
where g++ >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo MinGW g++ compiler not found in PATH.
    echo Please install MinGW and add it to your PATH.
    exit /b 1
)

REM Check if a file name was provided
if "%1"=="" (
    echo No source file provided.
    echo Usage: compile filename.cc
    exit /b 1
)

REM Compile the provided .cc file
g++ -o "builds/%~n1.exe" "%1"
if %ERRORLEVEL% neq 0 (
    echo Compilation failed.
    exit /b 1
)

echo Compilation successful. Output: %~n1.exe
exit /b 0