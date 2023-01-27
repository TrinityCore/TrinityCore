@echo off
setlocal
:quick
rem Quick install section
rem This will automatically use the variables below to install the SmartAi scripts to ur DB
rem To use: Set your environment variables below and change 'set quick=off' to 'set quick=on' 
set quick=off
if %quick% == off goto standard
echo (( patch Quick Installer ))
rem -- Change the values below to match your server --
set svr=localhost
set user=root
set pass=
set port=3306
set wdb=skyfire
set sd2db=null
rem -- Don't change past this point --
set yesno=y
goto install

:standard
rem Standard install section
color 6
echo .
echo    ````````````$````````$
echo    ````````````$````````$  *SmartAI Lab scripts*
echo    $$$```$$$``$$$``$$$``$
echo    $``$`````$``$``$```$`$$$$$    Mists of Pandaria 5.4.x Version
echo    $$$```$$$$``$``$`````$```$          for JadeCoreDB original
echo    $````$```$``$``$```$`$```$         
echo    $`````$$$$``$$``$$$``$```$ 
echo.
echo Credits to: Zic24,Verron,DeftaL,Rubill,Nex20,Zippo,JuKoT,melk,SuuZeR,Piro,Alex, Jcarter4562 and Discover
echo Project owner: cooler-SAI
echo                            Powered by SmartAI Engine
echo.
set /p svr=What is your MySQL host name?           [localhost]   : 
if %svr%. == . set svr=localhost
set /p user=What is your MySQL user name?           [root]        : 
if %user%. == . set user=root
set /p pass=What is your MySQL password?            [ ]           : 
if %pass%. == . set pass=
set /p port=What is your MySQL port?                [3306]        : 
if %port%. == . set port=3306
set /p wdb=What is your World database name?       [world]      : 
if %wdb%. == . set wdb=world

:install
set dbpath=!Milestone
set optim=DB_Optimizer
set mysql=.

:checkpaths
if not exist %dbpath% then goto patherror
if not exist %optim% then goto patherror
if not exist %mysql%\mysql.exe then goto patherror
goto world

:patherror
echo Cannot find required files, please ensure you have done a fully
echo recursive checkout from the HG.
pause
goto :eof

:world
if %quick% == off echo.
if %quick% == off echo This will add all *patch* scripts to your current DB.
if %quick% == off set /p yesno=Do you wish to continue? (y/n) 
if %quick% == off if %yesno% neq y if %yesno% neq Y goto sd2

echo.
echo Importing *patch* Milestone

for %%i in (%dbpath%\*.sql) do if %%i neq Database\Character_Structure.sql if %%i neq Database\Auth_Structure.sql echo %%i & %mysql%\mysql -q -s -h %svr% --user=%user% --password=%pass% --port=%port% %wdb% < %%i



if %quick% neq off goto optimize


if %quick% neq off goto :eof

:done
endlocal
echo.
echo All finished! Thank you for using this scripts.
echo.
pause