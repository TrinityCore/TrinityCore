@ECHO off
COLOR 0B
REM *****************************************************************************************
REM Set your compiler and another features here. Possible VC14 
REM currently possible VC14 (MS Visual studio 14 2015)
REM Warning! VS Express edition not supported! Also need check path (below) to VC10/11 binary
SET compiler=VC14

REM Install path for SingleCore_TC (in this be created ./bin and ./etc folders)
SET INSTALL_PATH="C:\\SingleCore"

rem Platform for build. Possible Win32, Win64. Warning! Win64 build possible only on 64-bit main OS!
SET BUILD_PLATFORM=Win64

rem Count of cores on PC, where project compiled. for speedup only
SET CORE_NUMBER=8

rem Used mangos memory manager. Possible managers - STD, TBB (not recommended), FASTMM (default)
SET MEMORY_MANAGER=FASTMM

SET win_partition=D
SET win_platform=x64
SET vc_path=Program Files (x86)

:menu
cls
echo ######################################
echo # Welcome to the SingleCore compiler #
echo ######################################
echo.
echo Compile settings
echo --------------
echo Compiler: %compiler%
echo Install path: %INSTALL_PATH%
echo Build platform: %BUILD_PLATFORM%
echo CPU core(s) number: %CORE_NUMBER%
echo.
echo Windows partition: %win_partition%
echo Windows platform: %win_platform%
echo.
echo 1 - Change compiler
echo 2 - Change install path
echo 3 - Change build platform
echo 4 - Change CPU core number
echo.
echo 5 - Change Windows partition
echo 6 - Change Windows platform
echo.
echo 9 - Start compile
echo.
set /P menu=Select a number: 
if "%menu%"=="1" goto compiler
if "%menu%"=="2" goto path
if "%menu%"=="3" goto platform
if "%menu%"=="4" goto core
if "%menu%"=="5" goto win_part
if "%menu%"=="6" goto win_platform
if "%menu%"=="9" goto start
if "%menu%"=="%menu%" echo. & echo Wrong number! & pause & goto menu

:compiler
cls

echo 1 - VC14
REM echo 2 - VC10

set /P menu=Select a number: 
if "%menu%"=="1" SET compiler=VC11 & goto menu
if "%menu%"=="2" SET compiler=VC10 & goto menu
if "%menu%"=="%menu%" echo. & echo Wrong number! & pause & goto compiler

:path
cls
set /P install_drive=Enter the partition drive letter first: 
set /P install_path=Enter the folder name: 
set INSTALL_PATH="%install_drive%:\\%install_path%"
goto menu

:platform
cls
echo 1 - Win32
echo 2 - Win64

set /P menu=Select a number: 
if "%menu%"=="1" SET BUILD_PLATFORM=Win32 & goto menu
if "%menu%"=="2" SET BUILD_PLATFORM=Win64 & goto menu
if "%menu%"=="%menu%" echo. & echo Wrong number! & pause & goto platform

:core
cls
set /P CORE_NUMBER=Enter how many CPU core(s) you want to use for compile: 
goto menu

:win_part
cls
set /P win_partition=Enter the Windows partition drive letter: 
goto menu

:win_platform
cls
echo 1 - x86
echo 2 - x64

set /P menu=Select a number: 
if "%menu%"=="1" SET win_platform=x86 & goto menu
if "%menu%"=="2" SET win_platform=x64 & goto menu
if "%menu%"=="%menu%" echo. & echo Wrong number! & pause & goto win_platform

:start
REM *****************************************************************************************
if %compiler%==VC14 goto :vc14
if %win_platform%==x86 set vc_path=Program Files
if %win_platform%==x64 set vc_path=Program Files (x86)
goto :help
REM *****************************************************************************************
:vc14
SET COMPILER="Visual Studio 14"
if %BUILD_PLATFORM%==Win64 (SET COMPILER="Visual Studio 14 Win64")
SET COMPILER_PATH="%win_partition%:/Visual Studio 15/VC/bin/cl.exe /w"
SET LINKER_PATH="%win_partition%:/Visual Studio 15/VC/bin/link.exe"
SET VC_VARS="%win_partition%:\\Visual Studio 15\\VC\\"
goto :common
REM *****************************************************************************************
:help
echo "Set up parameters in this bat file!"
exit
REM *****************************************************************************************
:common
SET RESULT_CONF=Release
SET MEMMAN_STR1="0"
SET MEMMAN_STR3="0"
SET MEMMAN_STR2="0"
if %MEMORY_MANAGER%==STD    (SET MEMMAN_STR2="1")
if %MEMORY_MANAGER%==TBB    (SET MEMMAN_STR3="1")
if %MEMORY_MANAGER%==FASTMM (SET MEMMAN_STR1="1")
SET C_FLAGS="/DWIN32 /D_WINDOWS /W3 /Zm1000 /EHsc /GR"
goto :begin
REM *****************************************************************************************

:begin
if not exist build (
    mkdir build
)

if not exist %INSTALL_PATH% (
mkdir %INSTALL_PATH%
    if not exist %INSTALL_PATH% (
    echo Please, make output directory %INSTALL_PATH%
    exit
    )
)

if %BUILD_PLATFORM%==Win32 goto :win32
if %BUILD_PLATFORM%==Win64 goto :win64
goto :help

REM *****************************************************************************************
:win32
cd build
cmake -G %COMPILER% -DPCH=1 -DCMAKE_CXX_COMPILER=%COMPILER_PATH% -DCMAKE_CXX_FLAGS=%C_FLAGS% -DCMAKE_C_FLAGS=%C_FLAGS% -DCMAKE_CXX_COMPILER=%COMPILER_PATH% -DCMAKE_INSTALL_PREFIX=%INSTALL_PATH% -DUSE_FASTMM_MALLOC=%MEMMAN_STR1% -DUSE_STD_MALLOC=%MEMMAN_STR2% -DUSE_TBB_MALLOC=%MEMMAN_STR3% ..
call %VC_VARS%vcvarsall.bat
MSBuild INSTALL.vcxproj /m:%CORE_NUMBER% /t:Rebuild /p:Configuration=%RESULT_CONF%;Platform=%BUILD_PLATFORM%
goto :end
REM *****************************************************************************************
:win64
cd build
cmake -G %COMPILER% -DPCH=1 -DCMAKE_CXX_COMPILER=%COMPILER_PATH% -DCMAKE_CXX_FLAGS=%C_FLAGS% -DCMAKE_C_FLAGS=%C_FLAGS% -DCMAKE_CXX_COMPILER=%COMPILER_PATH% -DCMAKE_INSTALL_PREFIX=%INSTALL_PATH% -DUSE_FASTMM_MALLOC=%MEMMAN_STR1% -DUSE_STD_MALLOC=%MEMMAN_STR2% -DUSE_TBB_MALLOC=%MEMMAN_STR3% ..
call %VC_VARS%vcvarsall.bat
MSBuild INSTALL.vcxproj /m:%CORE_NUMBER%  /t:Rebuild /p:Configuration=%RESULT_CONF%;Platform=x64
goto :end
REM *****************************************************************************************

:end
cd ..
if exist %INSTALL_PATH%\bin\aiplayerbot.conf.dist (
    del %INSTALL_PATH%\bin\aiplayerbot.conf.dist
)
copy src\game\playerbot\aiplayerbot.conf.dist.in %INSTALL_PATH%\bin\aiplayerbot.conf.dist

pause