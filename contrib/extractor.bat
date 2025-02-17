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
TIMEOUT 5 > NUL
CLS
GOTO MENU

:VMAPS
ECHO.
START /b /w vmap4extractor.exe
START /b /w vmap4assembler.exe Buildings vmaps
RMDIR Buildings /s /q
TIMEOUT 5 > NUL
CLS
GOTO MENU

:MMAPS
ECHO.
ECHO This may take a few hours to complete. Please be patient.
TIMEOUT 5 > NUL
START /b /w mmaps_generator.exe
TIMEOUT 5 > NUL
CLS
GOTO MENU

:ALL
ECHO.
ECHO This may take a few hours to complete. Please be patient.
TIMEOUT 5 > NUL
START /b /w mapextractor.exe
TIMEOUT 5 > NUL
START /b /w vmap4extractor.exe
TIMEOUT 5 > NUL
START /b /w vmap4assembler.exe
RMDIR Buildings /s /q
TIMEOUT 5 > NUL
START /b /w mmaps_generator.exe
TIMEOUT 5 > NUL
CLS
GOTO MENU

REM "2>&1" merges Standard Error (stderr) with Standard Output (stdout).
REM The results are redirected ">" into the log file.
:ALLWITHLOGS
ECHO.
ECHO This may take a few hours to complete. Please be patient.
ECHO.
TIMEOUT 5 > NUL
ECHO Extracting cameras, dbc and maps.
START /b /w mapextractor.exe 2>&1 > mapextractor.log
ECHO cameras, dbc and maps extracted.
ECHO.
TIMEOUT 5 > NUL
ECHO Extracting Buildings for Vmaps.
START /b /w vmap4extractor.exe 2>&1 > vmap4extractor.log
ECHO Buildings for Vmaps extracted.
ECHO.
TIMEOUT 5 > NUL
ECHO Assembling Buildings with Vmaps.
START /b /w vmap4assembler.exe 2>&1 > vmap4assembler.log
RMDIR Buildings /s /q
ECHO Buildings with Vmaps Assembled.
ECHO.
TIMEOUT 5 > NUL
ECHO Generating Mmaps (This takes the longest time).
START /b /w mmaps_generator.exe 2>&1 > mmaps_generator.log
ECHO Mmaps generated.
TIMEOUT 5 > NUL
CLS
GOTO MENU
