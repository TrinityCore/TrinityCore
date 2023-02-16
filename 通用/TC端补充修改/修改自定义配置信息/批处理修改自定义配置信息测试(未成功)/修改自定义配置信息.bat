@echo off&setlocal enabledelayedexpansion
::请设置一个文本中不包含bai的字符，这里我预设为￥，
::如果你的文本中包含，请自行修改，比如设为# $ 等。
set "char=￥"

::设置处理的文本
set "file=worldserver.conf"

call :replace

for /f "delims=" %%a in (tmp.txt$) do (
	set var=%%a
	set var=!var:^DBC.Locale%char%0=^DBC.Locale%char%4!&echo !var:%char%==!>>worldserver.conf.txt
)
del tmp.txt$
pause&goto :eof 2>nul
:replace
for /f "tokens=1* delims==" %%a in ('type "%file%"') do (    
			set temp=%%a%char%%%b    
			call :loop
)
goto :eof 2>nul
:loop
for /f "tokens=1* delims==" %%m in ("!temp!") do (
			set temp=%%m%char%%%n
			if not "%%n"=="" (goto loop) else echo !temp:~0,-1!>>tmp.txt$
)