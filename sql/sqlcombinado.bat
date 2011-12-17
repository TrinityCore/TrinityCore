@echo ##########################################################
@echo ##                                                      ##
@echo ##     ReanEmu - Archivo de unificacion de SQL's        ##
@echo ##                                                      ##
@echo ##########################################################
@echo By Eilo and Hispano, thnx to Jeutie
@echo .
@echo .
@echo .
@echo Las siguientes lineas unirán todos los archivos sql que
@echo esten dentro de la carpeta sql/update de manera que ahora
@echo puedan importar todas las actualizaciones de la carpeta
@echo con tan solo un archivo en vez de una por una.
@echo .
@echo .
@echo .
@echo El proceso empezara AHORA!
@echo off
pause
@echo off
setlocal EnableDelayedExpansion
set WorldTraducciones=All_World_Traducciones.sql
set WorldRean=All_World_Rean.sql
set WorldUpdates=All_World_Updates.sql
set CharactersRean=All_Characters_Rean.sql
set CharactersUpdates=All_Characters_Updates.sql
set AuthRean=All_Auth_Rean.sql
set AuthUpdates=All_Auth_Updates.sql

if exist %AuthUpdates% del %AuthUpdates%
if exist %AuthRean% del %AuthRean%
if exist %CharactersUpdates% del %CharactersUpdates%
if exist %CharactersRean% del %CharactersRean%
if exist %WorldUpdates% del %WorldUpdates%
if exist %WorldTraducciones% del %WorldTraducciones%
if exist %WorldRean% del %WorldRean%


for %%a in (updates\world\reanemu\*.sql) do (
echo /* >>%WorldRean%
echo * %%a >>%WorldRean%
echo */ >>%WorldRean%
copy/b %WorldRean%+"%%a" %WorldRean%
echo. >>%WorldRean%
echo. >>%WorldRean%)


for %%a in (updates\world\traducciones\*.sql) do (
echo /* >>%WorldTraducciones%
echo * %%a >>%WorldTraducciones%
echo */ >>%WorldTraducciones%
copy/b %WorldTraducciones%+"%%a" %WorldTraducciones%
echo. >>%WorldTraducciones%
echo. >>%WorldTraducciones%)


for %%a in (updates\world\*.sql) do (
echo /* >>%WorldUpdates%
echo * %%a >>%WorldUpdates%
echo */ >>%WorldUpdates%
copy/b %WorldUpdates%+"%%a" %WorldUpdates%
echo. >>%WorldUpdates%
echo. >>%WorldUpdates%)


for %%a in (updates\characters\*.sql) do (
echo /* >>%CharactersUpdates%
echo * %%a >>%CharactersUpdates%
echo */ >>%CharactersUpdates%
copy/b %CharactersUpdates%+"%%a" %CharactersUpdates%
echo. >>%CharactersUpdates%
echo. >>%CharactersUpdates%)


for %%a in (updates\characters\reanemu\*.sql) do (
echo /* >>%CharactersRean%
echo * %%a >>%CharactersRean%
echo */ >>%CharactersRean%
copy/b %CharactersRean%+"%%a" %CharactersRean%
echo. >>%CharactersRean%
echo. >>%CharactersRean%)


for %%a in (updates\auth\*.sql) do (
echo /* >>%AuthUpdates%
echo * %%a >>%AuthUpdates%
echo */ >>%AuthUpdates%
copy/b %AuthUpdates%+"%%a" %AuthUpdates%
echo. >>%AuthUpdates%
echo. >>%AuthUpdates%)  


for %%a in (updates\auth\reanemu\*.sql) do (
echo /* >>%AuthRean%
echo * %%a >>%AuthRean%
echo */ >>%AuthRean%
copy/b %AuthRean%+"%%a" %AuthRean%
echo. >>%AuthRean%
echo. >>%AuthRean%)  


@echo ReanEmu
pause
