@ECHO OFF
title Simple Extractor
COLOR 0A

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
PAUSE

CLS
COLOR 0A
ECHO.
ECHO.
ECHO                             ***NOTE*** 
ECHO This entire process will take anywhere from 2 hours to 8 hours or MORE, 
ECHO                depending upon the speed of your machine. (If you have a potato machine *Shauren says that*)
ECHO.
ECHO To continue the extraction process, enter 1, else, enter X to exit.
SET /p v= 		Enter a char:
IF %v%==1 GOTO Extract
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
:EXIT
