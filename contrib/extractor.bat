@ECHO OFF
title Simple Extractor
COLOR 0A

:MENU
CLS
ECHO.
ECHO     ______                       __
ECHO    /\__  _\       __          __/\ \__
ECHO    \/_/\ \/ _ __ /\_\    ___ /\_\ \, _\  __  __
ECHO         \ \ \/\`'__\/\ \ /' _ `\/\ \ \ \/ /\ \/\ \
ECHO          \ \ \ \ \/ \ \ \/\ \/\ \ \ \ \ \_\ \ \_\ \
ECHO           \ \_\ \_\  \ \_\ \_\ \_\ \_\ \__\//`____ \
ECHO            \/_/\/_/   \/_/\/_/\/_/\/_/\/__/ `/___/  \
ECHO                                       C O R E  /\___/
ECHO      http://TrinityCore.org                    \/__/
ECHO.
ECHO.
ECHO.
ECHO.
ECHO                             ***NOTE*** 
ECHO This entire process will take anywhere from 2 hours to 8 hours, 
ECHO depending upon the speed of your machine.
ECHO.
ECHO Choose what you need to do...
ECHO 1) Extract All (DB2 / DBC / MAPS / MMAPS / VMAPS / CAMERA)
ECHO 2) Extract Camera
ECHO 3) Extract DBC Only
ECHO 4) Extract MAPS Only
ECHO 5) Extract vMAPS Only
ECHO 6) Extract MMAPS Only (Requires Maps + vMaps + Dbc)
ECHO 7) Extract GT - GameTables (Only BFA)
ECHO X) Exit Program

SET /p v= Enter a char:
IF %v%==1 GOTO Extract
IF %v%==2 GOTO CAMERA
IF %v%==3 GOTO DBC
IF %v%==4 GOTO MAPS
IF %v%==5 GOTO vMAPS
IF %v%==6 GOTO MMAPS
IF %v%==7 GOTO GT
IF %v%==x GOTO EXIT
IF %v%==X GOTO EXIT

:Extract
CLS
COLOR 0A
ECHO.
ECHO Now extracting dbcs and maps, please do not exit the program!
ECHO.
RMDIR /s /q .\buildings
RMDIR /s /q .\Cameras
RMDIR /s /q .\db2
RMDIR /s /q .\dbc
RMDIR /s /q .\maps
RMDIR /s /q .\mmaps
RMDIR /s /q .\vmaps
mapextractor.exe
ECHO.
ECHO Dbcs and maps are finished extracting... Now extracting vmaps...
ECHO.
vmap4extractor.exe
ECHO.
ECHO Vmaps are now extracted... Now assembling vmaps...
ECHO.
MKDIR vmaps
vmap4assembler.exe Buildings vmaps
ECHO.
ECHO.
ECHO Vmaps are now assembled... Now ready to build mmaps...
ECHO.
ECHO.
MKDIR mmaps
mmaps_generator.exe
PAUSE

CLS
ECHO.
ECHO All /camera/maps/db2/dbc/vmaps/mmaps completed!
ECHO.
ECHO You will now need to move the folders dbc, vmaps, maps, and mmaps to your server directory. 
ECHO.
ECHO.
PAUSE
GOTO MENU

:DBC
CLS
COLOR 0A
ECHO.
ECHO Now extracting Dbc's, please do not exit the program!
ECHO.
RMDIR /s /q .\dbc
MKDIR dbc
mapextractor.exe -e 2

CLS
ECHO.
ECHO DBCs are finished...
ECHO.
PAUSE
GOTO MENU

:CAMERA
CLS
COLOR 0A
ECHO.
ECHO Now extracting Cameras, please do not exit the program!
ECHO.
RMDIR /s /q .\Cameras
MKDIR Cameras
mapextractor.exe -e 4

CLS
ECHO.
ECHO Camera are finished...
ECHO.
PAUSE
GOTO MENU

:MAPS
CLS
COLOR 0A
ECHO.
ECHO Now extracting Cameras, please do not exit the program!
ECHO.
RMDIR /s /q .\maps
MKDIR maps
mapextractor.exe -e 1

CLS
ECHO.
ECHO MAPS are finished...
ECHO.
PAUSE
GOTO MENU

:vMAPS
CLS
COLOR 0A
ECHO.
ECHO Now extracting VMAPS, please do not exit the program!
ECHO.
RMDIR /s /q .\Buildings
RMDIR /s /q .\vmaps
vmap4extractor.exe
ECHO.
ECHO Vmaps are now extracted... Now assembling vmaps...
ECHO.
MKDIR vmaps
vmap4assembler.exe Buildings vmaps
ECHO.
ECHO.

CLS
ECHO.
ECHO VMAPS are finished...
ECHO.
PAUSE
GOTO MENU

:MMAPS
CLS
COLOR 0A
ECHO.
ECHO Now extracting Dbc's, please do not exit the program!
ECHO.
RMDIR /s /q .\mmaps
MKDIR mmaps
mmaps_generator.exe

CLS
ECHO.
ECHO MMAPS are finished...
ECHO.
PAUSE
GOTO MENU

:GT
CLS
COLOR 0A
ECHO.
ECHO Now extracting gt, please do not exit the program!
ECHO.
RMDIR /s /q .\gt
MKDIR gt
mapextractor.exe -e 8

CLS
ECHO.
ECHO GT are finished...
ECHO.
PAUSE
GOTO MENU

:EXIT
