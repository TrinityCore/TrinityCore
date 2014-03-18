@echo off
title Servername : AuthServer Restarter
:start
authserver.exe
goto restart

:restart
authserver.exe
goto restart