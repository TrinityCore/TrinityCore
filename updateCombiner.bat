@echo off
setlocal EnableDelayedExpansion
set WorldUpdates=All_World_Updates.sql
set CharactersUpdates=All_Characters_Updates.sql
set AuthUpdates=All_Auth_Updates.sql

if exist %CharactersUpdates% del %CharactersUpdates%
if exist %AuthUpdates% del %AuthUpdates%
if exist %WorldUpdates% del %WorldUpdates%

for %%a in (sql\updates\world\*.sql) do (
echo /* >>%WorldUpdates%
echo * %%a >>%WorldUpdates%
echo */ >>%WorldUpdates%
copy/b %WorldUpdates%+"%%a" %WorldUpdates%
echo. >>%WorldUpdates%
echo. >>%WorldUpdates%)


for %%a in (sql\updates\characters\*.sql) do (
echo /* >>%CharactersUpdates%
echo * %%a >>%CharactersUpdates%
echo */ >>%CharactersUpdates%
copy/b %CharactersUpdates%+"%%a" %CharactersUpdates%
echo. >>%CharactersUpdates%
echo. >>%CharactersUpdates%)


for %%a in (sql\updates\auth\*.sql) do (
echo /* >>%AuthUpdates%
echo * %%a >>%AuthUpdates%
echo */ >>%AuthUpdates%
copy/b %AuthUpdates%+"%%a" %AuthUpdates%
echo. >>%AuthUpdates%
echo. >>%AuthUpdates%)