@echo off &setlocal EnableDelayedExpansion
set usage=Usage: %0 ^<-id ^| -hash^>
set errormsg=Error: No valid revision information found

set cmres=false
if "%1"=="-id" set cmres=true
if "%1"=="-hash" set cmres=true
if not "!cmres!"=="true" (
  echo !usage!
  exit /B 1
)

for /F "tokens=2,3 delims=-" %%a IN ('"git describe --match=init --abbrev=12"') do (
  set res=false
  if %%c=="" set res=true
  if %%d=="" set res=true
  if "!res!"=="true" (
      echo !errormsg!
      exit /B 1
  )

  if "%1"=="-id" (
   echo %%a
  ) else if "%1"=="-hash" (
    set str=%%b
    set str=!str:~1!
    echo !str!
  )
)
