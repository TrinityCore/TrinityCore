@echo off
set num=10
echo ������ִ��%num%��push...
cd /d D:\Program Files (x86)\WOWDIY\TrinityCore
for /l %%i in (1,1,%num%) do (
echo ��%%i��push
 git push
)
