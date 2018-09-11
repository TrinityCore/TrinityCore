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
ECHO WARNING! when extracting the vmaps extractor will
ECHO output the text below, it's intended and not an error:
ECHO ..........................................
ECHO Extracting World\Wmo\Band\Final_Stage.wmo
ECHO No such file.
ECHO Couldn't open RootWmo!!!
ECHO Done!
ECHO ..........................................
ECHO.
ECHO Press 1, 2, 3 or 4 to start extracting or 5 to exit.
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
IF %M%==5 GOTO :EOF

:MAPS
start /b /w mapextractor.exe
GOTO MENU

:VMAPS
start /b /w vmap4extractor.exe
start /b /w vmap4assembler.exe Buildings vmaps
rmdir Buildings /s /q
GOTO MENU

:MMAPS
ECHO This may take a few hours to complete. Please be patient.
PAUSE
start /b /w mmaps_generator.exe
GOTO MENU

:ALL
ECHO This may take a few hours to complete. Please be patient.
PAUSE
start /b /w mapextractor.exe
start /b /w vmap4extractor.exe
start /b /w vmap4assembler.exe
rmdir Buildings /s /q
start /b /w mmaps_generator.exe
GOTO MENU
