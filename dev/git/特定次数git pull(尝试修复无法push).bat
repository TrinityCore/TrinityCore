@echo off
set num=10
echo ������ִ��%num%��pull...
echo �����޸�ִ�д���,�ɱ༭���ļ�,�޸�num�ĸ�ֵ.
cd /d D:\Program Files (x86)\WOWDIY\XCore
for /l %%i in (1,1,%num%) do (
echo ��%%i��pull
 git pull https://github.com/xuehyc/TrinityCore master --rebase
)
