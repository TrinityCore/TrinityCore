@echo off
set num=10
echo 本程序共执行%num%次push...
echo 如需修改执行次数,可编辑本文件,修改num的赋值.
cd /d D:\Program Files (x86)\WOWDIY\TrinityCore
for /l %%i in (1,1,%num%) do (
echo 第%%i次push
 git push
)
