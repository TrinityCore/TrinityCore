@echo off
SET NAME=SingleCore-TC cherry-pick tool
TITLE %NAME%
COLOR 0B
set mod=%1

:commit
set /P commit=Enter the commit: 

git cherry-pick %commit%
echo.
goto commit