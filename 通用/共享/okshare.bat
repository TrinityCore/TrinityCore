@echo off
color 2f
mode con cols=50 lines=30
title  OKShare  【制作：wnsdt】
ver | findstr "6.1">nul && set bulid=nt6 && goto sc_top
ver | findstr "10.">nul && set bulid=nt10 && goto sc_top
ver | findstr "5.">nul && set bulid=nt5 && goto sc_top
ver | findstr "6.3">nul && set bulid=nt10 && goto sc_top
ver | findstr "6.2">nul && set bulid=nt10 && goto sc_top
echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo                       警  告
echo.     
echo.&echo.&echo.
echo          软件不支持你的系统，按任意键退出！
pause>nul 2>nul
exit
:sc_top
cls
del /q %temp%\info.txt>nul 2>nul
:sc_menu
echo.&echo.&echo.
echo             局域网共享一键修复 19.3.13
echo.
echo    --------------------------------------------
echo.&echo.&echo.
echo               1、本机网络信息
echo.
echo               2、简单共享（无密码）
echo.
echo               3、密码共享
echo.
echo               4、共享和权限管理
echo.
echo               5、权限设置指南（图文）
echo.
echo               6、打印机共享指南（图文）
echo.
echo               7、更新与反馈
echo.&echo.&echo.&echo.&echo.
set select=
set str1=1234567
set /p select= 输入数字，按回车:
if not defined select goto sc_wrong
echo %select%|findstr "[%str1%]">nul||goto sc_wrong
if %select%==1 (goto sc_info)
if %select%==2 (goto sc_zd)
if %select%==3 (goto sc_sd)
if %select%==4 (goto sc_gl) 
if %select%==5 (goto sc_help) 
if %select%==6 (goto sc_print) 
if %select%==7 (goto sc_update) 
:sc_wrong
mshta vbscript:msgbox("只能输入1-7的数字",64,"提示")(window.close) 
goto sc_top
:sc_info
cls
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo                  正在处理信息....
if %bulid%==nt5 (goto sc_nt5) else (goto sc_nt6)
:sc_nt5
(echo.
echo.)>>%temp%\info.txt
ping www.baidu.com -n 1 >nul || echo              互联网状态：       [ 离线 ]>>%temp%\info.txt && goto sc_ver_nt5
echo              互联网状态：       [ 在线 ]>>%temp%\info.txt
:sc_ver_nt5
(echo ----------------------------------------------------------
echo.)>>%temp%\info.txt
for /f "skip=1 tokens=2-4 delims=, " %%a in ('wmic os get caption') do (
if exist %windir%\SysWOW64 echo         系统版本：       %%a %%b %%c  64位>>%temp%\info.txt & goto sc_ver_nt5_next
echo         系统版本：       %%a %%b %%c  32位>>%temp%\info.txt
)
:sc_ver_nt5_next
(echo.
echo         计算机名：            %COMPUTERNAME%
echo.)>>%temp%\info.txt
for /f "tokens=2 delims= " %%a in ('net config workstation^|findstr /c:"工作站域"') do echo         工作组：              %%a>>%temp%\info.txt & goto sc_info_nt5
:sc_info_nt5
(echo.
echo         当前用户：            %USERNAME%
echo.)>>%temp%\info.txt
for /f "delims=" %%a in ('date /t') do echo         本机日期：            %%a>>%temp%\info.txt
echo.>>%temp%\info.txt
for /f "delims=" %%a in ('time /t') do echo         本机时间：            %%a>>%temp%\info.txt
echo ---------------------------------------------------------->>%temp%\info.txt
goto sc_info_more
:sc_nt6
(echo.
echo.)>>%temp%\info.txt
ping www.baidu.com -n 1 >nul || echo          互联网状态：       [ 离线 ]>>%temp%\info.txt && goto sc_ver_nt6
echo          互联网状态：       [ 在线 ]>>%temp%\info.txt
:sc_ver_nt6
(echo ----------------------------------------------------------
echo.)>>%temp%\info.txt
for /f "skip=1 tokens=2-5 delims=?, " %%a in ('wmic os get caption') do (
if exist %windir%\SysWOW64 echo    系统版本：      %%a %%b %%c %%d 64位>>%temp%\info.txt & goto sc_ver_nt6_next
echo    系统版本：       %%a %%b %%c %%d 32位>>%temp%\info.txt
)
:sc_ver_nt6_next
(echo.
echo    计算机名：            %COMPUTERNAME%
echo.)>>%temp%\info.txt
for /f "tokens=2 delims= " %%a in ('net config workstation^|findstr /c:"工作站域"') do echo    工作组：              %%a>>%temp%\info.txt
(echo.
echo    当前用户：            %USERNAME%
echo.)>>%temp%\info.txt
for /f "delims=" %%a in ('date /t') do echo    本机日期：            %%a>>%temp%\info.txt
echo.>>%temp%\info.txt
for /f "delims=" %%a in ('time /t') do echo    本机时间：            %%a>>%temp%\info.txt
echo ---------------------------------------------------------->>%temp%\info.txt
:sc_info_more
if %bulid%==nt5 ipconfig /all|findstr /v /c:"Windows IP Configuration"|findstr /v /c:"Host Name"|findstr /v /c:"Primary Dns Suffix"|findstr /v /c:"Node Type"|findstr /v /c:"IP Routing Enabled"|findstr /v /c:"WINS Proxy Enabled">>%temp%\info.txt && goto sc_info_next
ipconfig /all|findstr /v /c:"Windows IP 配置"|findstr /v /c:"主机名"|findstr /v /c:"主 DNS 后缀"|findstr /v /c:"节点类型"|findstr /v /c:"IP 路由已启用"|findstr /v /c:"WINS 代理已启用">>%temp%\info.txt
:sc_info_next
(echo.
echo ----------------------------------------------------------
echo.
echo.)>>%temp%\info.txt
start /w notepad %temp%\info.txt
del /q %temp%\info.txt>nul 2>nul
goto sc_top
:sc_zd
call :sc_qxfix
cls
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo                    开始修复......
net user guest /active:yes>nul 2>nul
net user guest "">nul 2>nul
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Lsa" /v forceguest /t REG_DWORD /d 0x1 /f>nul 2>nul
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Lsa" /v LimitBlankPasswordUse /t REG_DWORD /d 0x0 /f>nul 2>nul
if %bulid%==nt10 reg add "HKLM\SYSTEM\CurrentControlSet\Services\LanmanWorkstation\Parameters" /v AllowInsecureGuestAuth /t REG_DWORD /d 0x1 /f>nul 2>nul
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Lsa" /v restrictanonymoussam /t REG_DWORD /d 0x0 /f>nul 2>nul
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Lsa\MSV1_0" /v LmCompatibilityLevel /t REG_DWORD /d 0x1 /f>nul 2>nul
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Lsa" /v everyoneincludesanonymous /t REG_DWORD /d 0x1 /f>nul 2>nul
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Lsa" /v NoLmHash /t REG_DWORD /d 0x0 /f>nul 2>nul
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\services\LanmanServer\Parameters" /v restrictnullsessaccess /t REG_DWORD /d 0x0 /f>nul 2>nul
goto sc_main
:sc_sd
call :sc_qxfix
cls
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo                    开始修复......
net user guest /active:no>nul 2>nul
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Lsa" /v forceguest /t REG_DWORD /d 0x0 /f>nul 2>nul
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Lsa\MSV1_0" /v NtlmMinClientSec /t REG_DWORD /d 0x0 /f>nul 2>nul
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Lsa\MSV1_0" /v NtlmMinServerSec /t REG_DWORD /d 0x0 /f>nul 2>nul
goto sc_main
:sc_main
sc config LanmanWorkstation start= auto>nul 2>nul
sc config LanmanServer start= auto>nul 2>nul
sc config Winmgmt start= auto>nul 2>nul
sc config RpcSs start= auto>nul 2>nul
sc config Netman start= auto>nul 2>nul
sc config RasMan start= demand>nul 2>nul
sc config SSDPSRV start= auto>nul 2>nul
sc config BFE start= auto>nul 2>nul
sc config ALG start= demand>nul 2>nul
sc config SharedAccess start= auto>nul 2>nul
net start SharedAccess /y>nul 2>nul
sc config Browser start= auto>nul 2>nul
net start Browser /y>nul 2>nul
sc config Dnscache start= auto>nul 2>nul
net start Dnscache /y>nul 2>nul
sc config Dhcp start= auto>nul 2>nul
net start Dhcp /y>nul 2>nul
sc config lmhosts start= auto>nul 2>nul
net start lmhosts /y>nul 2>nul
sc config Spooler start= auto>nul 2>nul
net start Spooler /y>nul 2>nul
sc config upnphost start= demand>nul 2>nul
net start upnphost /y>nul 2>nul
reg query "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\services\Netlogon" /v Start|findstr "0x4">nul 2>nul && sc config Netlogon start= demand>nul 2>nul
reg add "HKLM\SYSTEM\CurrentControlSet\services\NetBT\Parameters" /v TransportBindName /t REG_SZ /d \Device\ /f>nul 2>nul
reg delete "HKLM\SYSTEM\CurrentControlSet\services\LanmanServer\Parameters" /v SMB1 /F>nul 2>nul
reg delete "HKLM\SYSTEM\CurrentControlSet\services\LanmanServer\Parameters" /v SMB2 /F>nul 2>nul
reg delete "HKLM\SYSTEM\CurrentControlSet\services\NetBT\Parameters" /v SMBDeviceEnabled /F>nul 2>nul
sc config netbt start= system>nul 2>nul
net start netbt>nul 2>nul
if %bulid%==nt5 (goto sc_sernt5) else (goto sc_sernt6)
:sc_sernt5
sc config PlugPlay start= auto>nul 2>nul
sc config TapiSrv start= auto>nul 2>nul
sc config Nla start= auto>nul 2>nul
net start Nla /y>nul 2>nul
netsh firewall set service type = fileandprint mode = enable scope = subnet>nul 2>nul
set "nbt=HKLM\SYSTEM\CurrentControlSet\services\NetBT\Parameters\Interfaces"
for /f "tokens=2 delims={" %%a in ('reg query "%nbt%"') do (reg query "%nbt%\TCPIP_{%%a" /s|findstr /i /c:"NetbiosOptions">nul && reg add "%nbt%\TCPIP_{%%a" /v NetbiosOptions /t REG_DWORD /d 0x0 /f>nul 2>nul)
goto sc_main2_etc
:sc_sernt6
sc config DcomLaunch start= auto>nul 2>nul
sc config RpcEptMapper start= auto>nul 2>nul
sc config SamSs start= auto>nul 2>nul
sc config nsi start= auto>nul 2>nul
sc config SstpSvc start= demand>nul 2>nul
sc config MpsSvc start= auto>nul 2>nul
net start MpsSvc /y>nul 2>nul
sc config NlaSvc start= auto>nul 2>nul
sc config netprofm start= auto>nul 2>nul
sc config fdPHost start= auto>nul 2>nul
net start fdPHost /y>nul 2>nul
sc config FDResPub start= auto>nul 2>nul
net start FDResPub /y>nul 2>nul
sc config HomeGroupListener start= auto>nul 2>nul
sc config WMPNetworkSvc start= auto>nul 2>nul
net start WMPNetworkSvc /y>nul 2>nul
sc config HomeGroupProvider start= auto>nul 2>nul
net start HomeGroupProvider /y>nul 2>nul
netsh advfirewall firewall set rule group=\"网络发现\" new enable=Yes>nul 2>nul
netsh advfirewall firewall set rule group=\"文件和打印机共享\" new enable=Yes>nul 2>nul
if %bulid%==nt10 powershell -NonInteractive "Enable-WindowsOptionalFeature -Online -FeatureName SMB1Protocol">nul 2>nul
for /f "delims=" %%a in ('reg query "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\services\NetBT\Parameters\Interfaces" /s /e /f "0x2"^|findstr "\Tcpip_"') do reg add "%%a" /v NetbiosOptions /t REG_DWORD /d 0x0 /f>nul 2>nul
:sc_main2_etc
(echo [Unicode]
echo Unicode=yes
echo [Version]
echo signature="$CHICAGO$"
echo Revision=1
echo [Privilege Rights]
echo sedenynetworklogonright = 
echo senetworklogonright = Everyone,Administrators,Users,Power Users,Backup Operators,guest)>>%temp%\zcl.inf
secedit /configure /db %temp%\zcl.sdb /cfg %temp%\zcl.inf /log %temp%\zcl.log /quiet
del /q %temp%\zcl.*>nul 2>nul
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Lsa" /v restrictanonymous /t REG_DWORD /d 0x0 /f>nul 2>nul
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\services\LanmanServer\Parameters" /v AutoShareServer /t REG_DWORD /d 0x1 /f>nul 2>nul
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\services\LanmanServer\Parameters" /v AutoShareWks /t REG_DWORD /d 0x1 /f>nul 2>nul
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\Browser\Parameters" /v MaintainServerList /t REG_SZ /d Auto /f>nul 2>nul
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\Browser\Parameters" /v IsDomainMaster /t REG_SZ /d FALSE /f>nul 2>nul
reg query "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\services\NetBT\Parameters" /v EnableLMHOSTS|findstr "0x0">nul 2>nul && reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\services\NetBT\Parameters" /v EnableLMHOSTS /t REG_DWORD /d 0x1 /f>nul 2>nul
reg delete "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\RemoteComputer\NameSpace\{D6277990-4C6A-11CF-8D87-00AA0060F5BF}" /f>nul 2>nul
net use * /del /y>nul 2>nul
net config server /hidden:no>nul 2>nul
net share ipc$>nul 2>nul
reg delete "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\services\NetBT\Parameters" /v NodeType /f>nul 2>nul
reg delete "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\services\NetBT\Parameters" /v DhcpNodeType /f>nul 2>nul
goto sc_tip
:sc_gl
cls
reg query "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Lsa" /v forceguest|findstr "0x1">nul 2>nul||goto classic
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Lsa" /v forceguest /t REG_DWORD /d 0x0 /f>nul 2>nul
set jlb=y
:classic
echo.&echo.&echo.&echo.
echo          功能：管理本机共享，修改共享权限
echo.
echo              家庭版系统仅支持查看共享
echo   ----------------------------------------------
echo.&echo.&echo.&echo.&echo.
echo                    【使用说明】
echo.&echo.
echo        点左侧“共享”可查看本机所有共享；
echo.
echo        右键点左侧“共享”可“新建共享”；
echo.
echo        右键点右侧共享可“停止共享”（能多选）；
echo.
echo        右键点右侧共享选“属性”可修改权限；
echo.&echo.&echo.&echo.&echo.&echo.&echo.
fsmgmt.msc
if %jlb%==y reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Lsa" /v forceguest /t REG_DWORD /d 0x1 /f>nul 2>nul
goto sc_top
:sc_tip
cls
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo                    修复已完成！！！
mshta vbscript:msgbox("请手动重启计算机",64,"提示")(window.close) 
exit
:sc_help
cls
start "%ProgramFiles%\Internet Explorer\iexplore.exe" "https://zhuanlan.zhihu.com/p/24285252"
goto sc_top
:sc_print
cls
start "%ProgramFiles%\Internet Explorer\iexplore.exe" "https://zhuanlan.zhihu.com/p/24187152"
goto sc_top
:sc_update
cls
start "%ProgramFiles%\Internet Explorer\iexplore.exe" "https://zhuanlan.zhihu.com/p/24178142"
goto sc_top
goto :eof
:sc_qxfix
cls
echo.&echo.&echo.
echo                     【使用说明】
echo    --------------------------------------------
echo.
echo          复制共享文件夹的地址栏路径到下方
echo.
echo           如果只共享打印机，按回车键跳过
echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo 粘贴路径，按回车:
echo.&echo.
set /p lj=
for %%a in ("%lj%") do set name=%%~na
net share "%name%"="%lj%">nul 2>nul
if %bulid%==nt5 cacls "%lj%" /t /e /p everyone:f >nul 2>nul && goto :eof
icacls "%lj%" /grant everyone:(oi)(ci)F>nul 2>nul
goto :eof
