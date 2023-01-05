@echo off
set num=10
echo 本程序共执行%num%次push...
cd /d D:\Program Files (x86)\WOWDIY\TrinityCore
for /l %%i in (1,1,%num%) do (
echo 第%%i次push
 git push
)
