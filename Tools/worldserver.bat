@echo off
title Servername : AuthServer Restarter
:start
worldserver.exe
goto restart

:restart
worldserver.exe
goto restart