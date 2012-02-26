@echo off
setlocal EnableDelayedExpansion
set WorldUpdates=World_Updates.sql
set CharactersUpdates=Characters_Updates.sql
set AuthUpdates=Auth_Updates.sql
set fullFile=World_Full.sql


(for %%F in (sql\updates\world\*world*.sql) do ^
if NOT "%%F" == %WorldUpdates% ^
for /F "tokens=*" %%L in (%%F) do (
  echo %%L
)) > %WorldUpdates%


(for %%F in (sql\updates\auth_char\*characters*.sql) do ^
if NOT "%%F" == %CharactersUpdates% ^
for /F "tokens=*" %%L in (%%F) do (
  echo %%L
)) > %CharactersUpdates%


(for %%F in (sql\updates\*auth*.sql) do ^
if NOT "%%F" == %RealmdUpdates% ^
for /F "tokens=*" %%L in (%%F) do (
  echo %%L
)) > %AuthUpdates%


(for %%F in (sql\FULL\*world*.sql) do ^
if NOT "%%F" == %fullFile% ^
for /F "tokens=*" %%L in (%%F) do (
  echo %%L
)) > %fullFile%