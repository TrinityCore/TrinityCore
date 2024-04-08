@ECHO OFF
CLS

:MENU
ECHO.
ECHO ====================== Extractor ========================
ECHO TrinityCore cameras, dbc, maps, vmaps and mmaps extractor
ECHO =========================================================
ECHO.
ECHO ======================================================
ECHO WARNING! When extracting the vmaps extractor will
ECHO output the text below, it's intended and not an error:
ECHO ======================================================
ECHO Extracting World\Wmo\Band\Final_Stage.wmo
ECHO No such file.
ECHO Couldn't open RootWmo!!!
ECHO Done!
ECHO ======================================================
ECHO.
ECHO 1: Extract base files (NEEDED) and cameras.
ECHO 2: Extract vmaps (needs maps to be extracted before you run this) (OPTIONAL, but highly recommended)
ECHO 3: Extract mmaps (needs vmaps to be extracted before you run this, may take hours) (OPTIONAL, but highly recommended)
ECHO 4: Extract all (may take hours)
ECHO 5: Extract all with logs (may take hours)
ECHO 6: EXIT
ECHO.
SET /P M=Type 1, 2, 3, 4, 5 or 6 then press ENTER:
IF %M%==1 GOTO MAPS
IF %M%==2 GOTO VMAPS
IF %M%==3 GOTO MMAPS
IF %M%==4 GOTO ALL
IF %M%==5 GOTO ALLWITHLOGS
IF %M%==6 GOTO :EOF

:MAPS
ECHO.
START /b /w mapextractor.exe
ECHO Cameras, dbc and maps extracted.
TIMEOUT 5 > NUL
CLS
GOTO MENU

:VMAPS
ECHO.
START /b /w vmap4extractor.exe
START /b /w vmap4assembler.exe Buildings vmaps
RMDIR Buildings /s /q
ECHO Vmaps extracted and reassembled.
TIMEOUT 5 > NUL
CLS
GOTO MENU

:MMAPS
ECHO.
ECHO This may take a few hours to complete. Please be patient.
TIMEOUT 5 > NUL
START /b /w mmaps_generator.exe
ECHO Mmaps generated.
TIMEOUT 5 > NUL
CLS
GOTO MENU

:ALL
ECHO.
ECHO This may take a few hours to complete. Please be patient.
TIMEOUT 5 > NUL
START /b /w mapextractor.exe
ECHO Cameras, dbc and maps extracted.
TIMEOUT 5 > NUL
START /b /w vmap4extractor.exe
ECHO Vmaps extracted.
TIMEOUT 5 > NUL
START /b /w vmap4assembler.exe
RMDIR Buildings /s /q
ECHO Vmaps reassembled.
TIMEOUT 5 > NUL
START /b /w mmaps_generator.exe
ECHO Mmaps generated.
TIMEOUT 5 > NUL
CLS
GOTO MENU

:ALLWITHLOGS
ECHO.
ECHO This may take a few hours to complete. Please be patient.
TIMEOUT 5 > NUL
START /b /w mapextractor.exe > mapextractor.log
ECHO Cameras, dbc and maps extracted.
TIMEOUT 5 > NUL
START /b /w vmap4extractor.exe > vmap4extractor.log
ECHO Vmaps extracted.
TIMEOUT 5 > NUL
START /b /w vmap4assembler.exe > vmap4assembler.log
RMDIR Buildings /s /q
ECHO Vmaps reassembled.
TIMEOUT 5 > NUL
START /b /w mmaps_generator.exe > mmaps_generator.log
ECHO Mmaps generated.
TIMEOUT 5 > NUL
CLS
GOTO MENU
