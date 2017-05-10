@ECHO OFF
CLS
:MENU
ECHO.
ECHO ...............................................
ECHO Trinitycore dbc/db2, maps, vmaps, mmaps extractor
ECHO ...............................................
ECHO PRESS 1, 2, 3 OR 4 to select your task, or 5 to EXIT.
ECHO ...............................................
ECHO.
ECHO If you see one row with the error
ECHO "Couldn't open RootWmo!!!"
ECHO Ignore it, it's not real error.
ECHO.
ECHO 1 - Extract dbc/db2 and maps
ECHO 2 - Extract vmaps (needs maps to be extracted before you run this)
ECHO 3 - Extract mmaps (needs vmaps to be extracted before you run this, may take hours)
ECHO 4 - Extract all (may take hours)
ECHO 5 - EXIT
ECHO.
SET /P M=Type 1, 2, 3, 4 or 5 then press ENTER:
IF %M%==1 GOTO MAPS
IF %M%==2 GOTO VMAPS
IF %M%==3 GOTO MMAPS
IF %M%==4 GOTO ALL
IF %M%==5 GOTO EOF
:MAPS
start mapextractor.exe
ECHO wait before mapextractor.exe closes before continue
pause
GOTO MENU
:VMAPS
md vmaps
start vmap4extractor.exe
ECHO wait before vmap4extractor.exe closes before continue
pause
start vmap4assembler.exe Buildings vmaps
ECHO wait before vmap4assembler.exe closes before continue
pause
rmdir Buildings /s /q
GOTO MENU
:MMAPS
md mmaps
start mmaps_generator.exe
pause
GOTO MENU
:ALL
start mapextractor.exe
ECHO wait before mapextractor.exe closes before continue
pause
md vmaps
start vmap4extractor.exe
ECHO wait before vmap4extractor.exe closes before continue
pause
start vmap4assembler.exe Buildings vmaps
ECHO wait before vmap4assembler.exe closes before continue
pause
rmdir Buildings /s /q
md mmaps
start mmaps_generator.exe --threads %NUMBER_OF_PROCESSORS%
ECHO wait before mmaps_generator.exe closes before continue (may take hours)
pause
GOTO MENU
