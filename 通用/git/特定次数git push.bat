@echo off
set num=999
echo ������ִ��%num%��push...
echo �����޸�ִ�д���,�ɱ༭���ļ�,�޸�num�ĸ�ֵ.
cd /d D:\Program Files (x86)\WOWDIY\XCore
for /l %%i in (1,1,%num%) do (
echo ��%%i��push
 git push https://github.com/xuehyc/XCore master
)
