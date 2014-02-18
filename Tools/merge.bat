@echo off
COLOR E0
@echo #**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#
@echo #**#S*#**Y**#M*#**B**#O*#*L#**#I*#**D**#**E**#V*#
@echo #**#**#**#**#M*#**E**#R*#*G#**E*#**Tools**#
@echo off
pause
@echo off
pausa

set filename=world.sql

if exist %filename% del %filename%

for %%a in (*.sql) do (
echo -- ------------------------------------------------- >>%filename%
echo -- %%a >> %filename%
echo -- ------------------------------------------------- >>%filename%
copy /b %filename%+"%%a" %filename%
echo. >>%filename%
echo. >>%filename%)