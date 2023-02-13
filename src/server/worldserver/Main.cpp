/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/// \addtogroup Trinityd Trinity Daemon
/// @{
/// \file

#include "Common.h"
#include "AppenderDB.h"
#include "AsyncAcceptor.h"
#include "AuthenticationPackets.h"
#include "Banner.h"
#include "BattlegroundMgr.h"
#include "BigNumber.h"
#include "CliRunnable.h"
#include "Configuration/Config.h"
#include "DatabaseEnv.h"
#include "DatabaseLoader.h"
#include "DeadlineTimer.h"
#include "GitRevision.h"
#include "InstanceLockMgr.h"
#include "IoContext.h"
#include "MapManager.h"
#include "Metric.h"
#include "MySQLThreading.h"
#include "ObjectAccessor.h"
#include "OpenSSLCrypto.h"
#include "OutdoorPvP/OutdoorPvPMgr.h"
#include "ProcessPriority.h"
#include "RASession.h"
#include "RealmList.h"
#include "ScriptLoader.h"
#include "ScriptMgr.h"
#include "ScriptReloadMgr.h"
#include "SecretMgr.h"
#include "TCSoap.h"
#include "TerrainMgr.h"
#include "ThreadPool.h"
#include "World.h"
#include "WorldSocket.h"
#include "WorldSocketMgr.h"
#include "Util.h"
#include <openssl/opensslv.h>
#include <openssl/crypto.h>
#include <boost/asio/signal_set.hpp>
#include <boost/dll/runtime_symbol_info.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/program_options.hpp>
#include <google/protobuf/stubs/common.h>
#include <iostream>
#include <csignal>

#include "Hacks/boost_program_options_with_filesystem_path.h"

// #define _CRT_SECURE_NO_DEPRECATE    //尝试去除assert报错,无用

using namespace boost::program_options;
namespace fs = boost::filesystem;

#ifndef _TRINITY_CORE_CONFIG
    #define _TRINITY_CORE_CONFIG  "worldserver.conf"    //此处可以修改配置文件名,计划直接用dist
#endif

#ifdef _WIN32
#include "ServiceWin32.h"
char serviceName[] = "worldserver"; //服务器名称设置
char serviceLongName[] = "TrinityCore world service";
char serviceDescription[] = "TrinityCore World of Warcraft emulator world service";
/*
 * -1 - not in service mode
 *  0 - stopped
 *  1 - running
 *  2 - paused
 */
int m_ServiceStatus = -1;

#include <boost/dll/shared_library.hpp>
#include <timeapi.h>
#endif

class FreezeDetector    //冻结检测器
{
public:
    FreezeDetector(Trinity::Asio::IoContext& ioContext, uint32 maxCoreStuckTime)
        : _timer(ioContext), _worldLoopCounter(0), _lastChangeMsTime(getMSTime()), _maxCoreStuckTimeInMs(maxCoreStuckTime) { }

    static void Start(std::shared_ptr<FreezeDetector> const& freezeDetector)
    {
        freezeDetector->_timer.expires_from_now(boost::posix_time::seconds(5));
        freezeDetector->_timer.async_wait(std::bind(&FreezeDetector::Handler, std::weak_ptr<FreezeDetector>(freezeDetector), std::placeholders::_1));
    }

    static void Handler(std::weak_ptr<FreezeDetector> freezeDetectorRef, boost::system::error_code const& error);

private:
    Trinity::Asio::DeadlineTimer _timer;
    uint32 _worldLoopCounter;
    uint32 _lastChangeMsTime;
    uint32 _maxCoreStuckTimeInMs;
};

void SignalHandler(boost::system::error_code const& error, int signalNumber);
AsyncAcceptor* StartRaSocketAcceptor(Trinity::Asio::IoContext& ioContext);
bool StartDB();
void StopDB();
void WorldUpdateLoop();
void ClearOnlineAccounts();
void ShutdownCLIThread(std::thread* cliThread);
bool LoadRealmInfo();
variables_map GetConsoleArguments(int argc, char** argv, fs::path& configFile, std::string& cfg_service);

/// Launch the Trinity server   //启动Trinity服务器
extern int main(int argc, char** argv)
{
    signal(SIGABRT, &Trinity::AbortHandler);

    auto configFile = fs::absolute(_TRINITY_CORE_CONFIG);
    std::string configService;

    auto vm = GetConsoleArguments(argc, argv, configFile, configService);
    // exit if help or version is enabled
    if (vm.count("help") || vm.count("version"))
        return 0;

    GOOGLE_PROTOBUF_VERIFY_VERSION;

    std::shared_ptr<void> protobufHandle(nullptr, [](void*) { google::protobuf::ShutdownProtobufLibrary(); });

#ifdef _WIN32
    if (configService.compare("install") == 0)
        return WinServiceInstall() ? 0 : 1;
    else if (configService.compare("uninstall") == 0)
        return WinServiceUninstall() ? 0 : 1;
    else if (configService.compare("run") == 0)
        return WinServiceRun() ? 0 : 0;

    Optional<UINT> newTimerResolution;
    boost::system::error_code dllError;
    std::shared_ptr<boost::dll::shared_library> winmm(new boost::dll::shared_library("winmm.dll", dllError, boost::dll::load_mode::search_system_folders), [&](boost::dll::shared_library* lib)
    {
        try
        {
            if (newTimerResolution)
                lib->get<decltype(timeEndPeriod)>("timeEndPeriod")(*newTimerResolution);
        }
        catch (std::exception const&)
        {
            // ignore
        }

        delete lib;
    });

    if (winmm->is_loaded())
    {
        try
        {
            auto timeGetDevCapsPtr = winmm->get<decltype(timeGetDevCaps)>("timeGetDevCaps");
            // setup timer resolution
            TIMECAPS timeResolutionLimits;
            if (timeGetDevCapsPtr(&timeResolutionLimits, sizeof(TIMECAPS)) == TIMERR_NOERROR)
            {
                auto timeBeginPeriodPtr = winmm->get<decltype(timeBeginPeriod)>("timeBeginPeriod");
                newTimerResolution = std::min(std::max(timeResolutionLimits.wPeriodMin, 1u), timeResolutionLimits.wPeriodMax);
                timeBeginPeriodPtr(*newTimerResolution);
            }
        }
        catch (std::exception const& e)
        {
            printf("Failed to initialize timer resolution: %s\n", e.what());
        }
    }

#endif

    std::string configError;
    if (!sConfigMgr->LoadInitial(configFile.generic_string(),
                                 std::vector<std::string>(argv, argv + argc),
                                 configError))
    {
        printf("Error in config file: %s\n", configError.c_str());
        return 1;
    }

    std::vector<std::string> overriddenKeys = sConfigMgr->OverrideWithEnvVariablesIfAny();

    std::shared_ptr<Trinity::Asio::IoContext> ioContext = std::make_shared<Trinity::Asio::IoContext>();

    sLog->RegisterAppender<AppenderDB>();
    // If logs are supposed to be handled async then we need to pass the IoContext into the Log singleton
    sLog->Initialize(sConfigMgr->GetBoolDefault("Log.Async.Enable", false) ? ioContext.get() : nullptr);

    Trinity::Banner::Show("worldserver-daemon",
        [](char const* text)
        {
            TC_LOG_INFO("server.worldserver", "{}", text);
        },
        []()
        {
            TC_LOG_INFO("server.worldserver", "Using configuration file {}.", sConfigMgr->GetFilename());
            //输出 使用的配置
            TC_LOG_INFO("server.worldserver", "Using SSL version: {} (library: {})", OPENSSL_VERSION_TEXT, OpenSSL_version(OPENSSL_VERSION));
            //输出 使用的SSL版本
            TC_LOG_INFO("server.worldserver", "Using Boost version: {}.{}.{}", BOOST_VERSION / 100000, BOOST_VERSION / 100 % 1000, BOOST_VERSION % 100);
            //输出 使用的Boost版本
        }
    );

    for (std::string const& key : overriddenKeys)
        TC_LOG_INFO("server.worldserver", "Configuration field '{}' was overridden with environment variable.", key);

    OpenSSLCrypto::threadsSetup(boost::dll::program_location().remove_filename());
    //打开Openssl加密
    std::shared_ptr<void> opensslHandle(nullptr, [](void*) { OpenSSLCrypto::threadsCleanup(); });

    // Seed the OpenSSL's PRNG here.
    // That way it won't auto-seed when calling BigNumber::SetRand and slow down the first world login
    BigNumber seed;
    seed.SetRand(16 * 8);

    /// worldserver PID file creation
    //Worldserver PID文件创建
    std::string pidFile = sConfigMgr->GetStringDefault("PidFile", "");
    if (!pidFile.empty())
    {
        if (uint32 pid = CreatePIDFile(pidFile))
            TC_LOG_INFO("server.worldserver", "Daemon PID: {}\n", pid);
        else
        {
            TC_LOG_ERROR("server.worldserver", "Cannot create PID file {}.\n", pidFile);
            return 1;
        }
    }

    // Set signal handlers (this must be done before starting IoContext threads, because otherwise they would unblock and exit)
    //设置信号控制器(这个必须在开始输入输出线程完成,否则他们将会清理并且退出)
    boost::asio::signal_set signals(*ioContext, SIGINT, SIGTERM);
#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
    signals.add(SIGBREAK);
#endif
    signals.async_wait(SignalHandler);

    // Start the Boost based thread pool
    int numThreads = sConfigMgr->GetIntDefault("ThreadPool", 1);
    if (numThreads < 1)
        numThreads = 1;

    std::shared_ptr<Trinity::ThreadPool> threadPool = std::make_shared<Trinity::ThreadPool>(numThreads);

    for (int i = 0; i < numThreads; ++i)
        threadPool->PostWork([ioContext]() { ioContext->run(); });

    std::shared_ptr<void> ioContextStopHandle(nullptr, [ioContext](void*) { ioContext->stop(); });

    // Set process priority according to configuration settings
    // 通过配置属性设置进程
    SetProcessPriority("server.worldserver", sConfigMgr->GetIntDefault(CONFIG_PROCESSOR_AFFINITY, 0), sConfigMgr->GetBoolDefault(CONFIG_HIGH_PRIORITY, false));

    // Start the databases
    //启动数据库
    if (!StartDB())
        return 1;

    std::shared_ptr<void> dbHandle(nullptr, [](void*) { StopDB(); });

    if (vm.count("update-databases-only"))
        return 0;

    // Set server offline (not connectable)
    // 设置服务器离线(无法连接)
    LoginDatabase.DirectPExecute("UPDATE realmlist SET flag = flag | {} WHERE id = '{}'", REALM_FLAG_OFFLINE, realm.Id.Realm);
    //登录数据库中直接运行SQL
    sRealmList->Initialize(*ioContext, sConfigMgr->GetIntDefault("RealmsStateUpdateDelay", 10));

    std::shared_ptr<void> sRealmListHandle(nullptr, [](void*) { sRealmList->Close(); });

    LoadRealmInfo();

    sMetric->Initialize(realm.Name, *ioContext, []()
    {
        TC_METRIC_VALUE("online_players", sWorld->GetPlayerCount());
        //在线玩家总数
        TC_METRIC_VALUE("db_queue_login", uint64(LoginDatabase.QueueSize()));
        TC_METRIC_VALUE("db_queue_character", uint64(CharacterDatabase.QueueSize()));
        TC_METRIC_VALUE("db_queue_world", uint64(WorldDatabase.QueueSize()));
    });

    TC_METRIC_EVENT("events", "Worldserver started", "");

    std::shared_ptr<void> sMetricHandle(nullptr, [](void*)
    {
        TC_METRIC_EVENT("events", "Worldserver shutdown", "");
        //事件,世界服务器关闭
        sMetric->Unload();
    });

    sScriptMgr->SetScriptLoader(AddScripts);
    std::shared_ptr<void> sScriptMgrHandle(nullptr, [](void*)
    {
        sScriptMgr->Unload();
        sScriptReloadMgr->Unload();
    });

    // Initialize the World
    sSecretMgr->Initialize(SECRET_OWNER_WORLDSERVER);//初始化私人世界服务器
    sWorld->SetInitialWorldSettings();

    std::shared_ptr<void> mapManagementHandle(nullptr, [](void*)
    {
        // unload battleground templates before different singletons destroyed
        sBattlegroundMgr->DeleteAllBattlegrounds();
        //删除所有战场
        sOutdoorPvPMgr->Die();                    // unload it before MapManager    //在地图管理器前卸载
        sMapMgr->UnloadAll();                     // unload all grids (including locked in memory)  //卸载所有的grid(包括锁定在内存中的)
        sTerrainMgr.UnloadAll();
        sInstanceLockMgr.Unload();
    });

    // Start the Remote Access port (acceptor) if enabled
    std::unique_ptr<AsyncAcceptor> raAcceptor;
    if (sConfigMgr->GetBoolDefault("Ra.Enable", false))
        raAcceptor.reset(StartRaSocketAcceptor(*ioContext));

    // Start soap serving thread if enabled
    std::shared_ptr<std::thread> soapThread;
    if (sConfigMgr->GetBoolDefault("SOAP.Enabled", false))
    {
        soapThread.reset(new std::thread(TCSoapThread, sConfigMgr->GetStringDefault("SOAP.IP", "127.0.0.1"), uint16(sConfigMgr->GetIntDefault("SOAP.Port", 7878))),
            [](std::thread* thr)    //soap重置进程
        {
            thr->join();
            delete thr;
        });
    }

    // Launch the worldserver listener socket   // 启动服务器监听套接字
    uint16 worldPort = uint16(sWorld->getIntConfig(CONFIG_PORT_WORLD));
    uint16 instancePort = uint16(sWorld->getIntConfig(CONFIG_PORT_INSTANCE));
    std::string worldListener = sConfigMgr->GetStringDefault("BindIP", "0.0.0.0");

    int networkThreads = sConfigMgr->GetIntDefault("Network.Threads", 1);

    if (networkThreads <= 0)
    {
        TC_LOG_ERROR("server.worldserver", "Network.Threads must be greater than 0");   //错误提示,服务器的网络进程必须大于0;
        World::StopNow(ERROR_EXIT_CODE);
        return 1;
    }

    if (!sWorldSocketMgr.StartWorldNetwork(*ioContext, worldListener, worldPort, instancePort, networkThreads))
    {
        TC_LOG_ERROR("server.worldserver", "Failed to initialize network"); //初始化网络失败;
        World::StopNow(ERROR_EXIT_CODE);
        return 1;
    }

    std::shared_ptr<void> sWorldSocketMgrHandle(nullptr, [](void*)
    {
        sWorld->KickAll();                                       // save and kick all players   //保存并踢出所有玩家
        sWorld->UpdateSessions(1);                             // real players unload required UpdateSessions call  // 踢出真实玩家需要更新Session调用

        sWorldSocketMgr.StopNetwork();

        ///- Clean database before leaving  //- 在离开前要清除数据库
        ClearOnlineAccounts();
    });

    // Set server online (allow connecting now)
    LoginDatabase.DirectPExecute("UPDATE realmlist SET flag = flag & ~{}, population = 0 WHERE id = '{}'", REALM_FLAG_OFFLINE, realm.Id.Realm);
    realm.PopulationLevel = 0.0f;
    realm.Flags = RealmFlags(realm.Flags & ~uint32(REALM_FLAG_OFFLINE));

    // Start the freeze check callback cycle in 5 seconds (cycle itself is 1 sec)    // 在5秒内启动冻结检测调用循环(循环自身是1秒)
    std::shared_ptr<FreezeDetector> freezeDetector;
    if (int coreStuckTime = sConfigMgr->GetIntDefault("MaxCoreStuckTime", 60))
    {
        freezeDetector = std::make_shared<FreezeDetector>(*ioContext, coreStuckTime * 1000);
        FreezeDetector::Start(freezeDetector);
        TC_LOG_INFO("server.worldserver", "Starting up anti-freeze thread ({} seconds max stuck time)...", coreStuckTime);
        //启动防止冻结进程
    }

    sScriptMgr->OnStartup();

    //TC_LOG_INFO("server.worldserver", "小女孩自研版");
    // 我自行添加的版权信息,发现放上去太丑了,暂时注释

    TC_LOG_INFO("server.worldserver", "{} (worldserver-daemon) ready...", GitRevision::GetFullVersion());
    //服务器启动完成提示信息
    
    // Launch CliRunnable thread
    std::shared_ptr<std::thread> cliThread;
#ifdef _WIN32
    if (sConfigMgr->GetBoolDefault("Console.Enable", true) && (m_ServiceStatus == -1)/* need disable console in service mode*/)
#else
    if (sConfigMgr->GetBoolDefault("Console.Enable", true))
#endif
    {
        cliThread.reset(new std::thread(CliThread), &ShutdownCLIThread);
    }

    WorldUpdateLoop();

    // Shutdown starts here
    WorldPackets::Auth::ConnectTo::ShutdownEncryption();
    WorldPackets::Auth::EnterEncryptedMode::ShutdownEncryption();

    ioContextStopHandle.reset();

    threadPool.reset();

    sLog->SetSynchronous();

    sScriptMgr->OnShutdown();

    // set server offline
    LoginDatabase.DirectPExecute("UPDATE realmlist SET flag = flag | {} WHERE id = '{}'", REALM_FLAG_OFFLINE, realm.Id.Realm);
    //更新数据库中对应标记
    TC_LOG_INFO("server.worldserver", "Halting process...");
    //worldserver正在停止进程.
    
    // 0 - normal shutdown   // 0 - 正常关闭
    // 1 - shutdown at error // 1 - 错误退出
    // 2 - restart command used, this code can be used by restarter for restart Trinityd
    // 2 - 使用了重启命令,这个编码可以被重启器用来重启Trinity模拟器

    return World::GetExitCode();
    //返回退出代码
}

void ShutdownCLIThread(std::thread* cliThread)
{
    if (cliThread != nullptr)
    {
#ifdef _WIN32
        // First try to cancel any I/O in the CLI thread
        // 首先尝试在CLT进程中取消任何的输入输出.
        if (!CancelSynchronousIo(cliThread->native_handle()))
        {
            // if CancelSynchronousIo() fails, print the error and try with old way
            DWORD errorCode = GetLastError();
            //未知错误
            
            // if CancelSynchronousIo fails with ERROR_NOT_FOUND then there was nothing to cancel, proceed with shutdown
            if (errorCode != ERROR_NOT_FOUND)
            {
                LPCSTR errorBuffer;
                DWORD numCharsWritten = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
                    nullptr, errorCode, 0, (LPTSTR)&errorBuffer, 0, nullptr);
                if (!numCharsWritten)
                    errorBuffer = "Unknown error";

                TC_LOG_DEBUG("server.worldserver", "Error cancelling I/O of CliThread, error code {}, detail: {}", uint32(errorCode), errorBuffer);
                //输出错误代码

                if (numCharsWritten)
                    LocalFree((LPSTR)errorBuffer);

                // send keyboard input to safely unblock the CLI thread
                INPUT_RECORD b[4];
                HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);
                b[0].EventType = KEY_EVENT;
                b[0].Event.KeyEvent.bKeyDown = TRUE;
                b[0].Event.KeyEvent.uChar.AsciiChar = 'X';
                b[0].Event.KeyEvent.wVirtualKeyCode = 'X';
                b[0].Event.KeyEvent.wRepeatCount = 1;

                b[1].EventType = KEY_EVENT;
                b[1].Event.KeyEvent.bKeyDown = FALSE;
                b[1].Event.KeyEvent.uChar.AsciiChar = 'X';
                b[1].Event.KeyEvent.wVirtualKeyCode = 'X';
                b[1].Event.KeyEvent.wRepeatCount = 1;

                b[2].EventType = KEY_EVENT;
                b[2].Event.KeyEvent.bKeyDown = TRUE;
                b[2].Event.KeyEvent.dwControlKeyState = 0;
                b[2].Event.KeyEvent.uChar.AsciiChar = '\r';
                b[2].Event.KeyEvent.wVirtualKeyCode = VK_RETURN;
                b[2].Event.KeyEvent.wRepeatCount = 1;
                b[2].Event.KeyEvent.wVirtualScanCode = 0x1c;

                b[3].EventType = KEY_EVENT;
                b[3].Event.KeyEvent.bKeyDown = FALSE;
                b[3].Event.KeyEvent.dwControlKeyState = 0;
                b[3].Event.KeyEvent.uChar.AsciiChar = '\r';
                b[3].Event.KeyEvent.wVirtualKeyCode = VK_RETURN;
                b[3].Event.KeyEvent.wVirtualScanCode = 0x1c;
                b[3].Event.KeyEvent.wRepeatCount = 1;
                DWORD numb;
                WriteConsoleInput(hStdIn, b, 4, &numb);
            }
        }
#endif
        cliThread->join();
        delete cliThread;
    }
}

void WorldUpdateLoop()
{
    uint32 minUpdateDiff = uint32(sConfigMgr->GetIntDefault("MinWorldUpdateTime", 1));
    uint32 realCurrTime = 0;
    uint32 realPrevTime = getMSTime();

    uint32 maxCoreStuckTime = uint32(sConfigMgr->GetIntDefault("MaxCoreStuckTime", 60)) * 1000;
    uint32 halfMaxCoreStuckTime = maxCoreStuckTime / 2;
    if (!halfMaxCoreStuckTime)
        halfMaxCoreStuckTime = std::numeric_limits<uint32>::max();

    LoginDatabase.WarnAboutSyncQueries(true);
    CharacterDatabase.WarnAboutSyncQueries(true);
    WorldDatabase.WarnAboutSyncQueries(true);
    HotfixDatabase.WarnAboutSyncQueries(true);

    ///- While we have not World::m_stopEvent, update the world
    while (!World::IsStopped())
    {
        ++World::m_worldLoopCounter;
        realCurrTime = getMSTime();

        uint32 diff = getMSTimeDiff(realPrevTime, realCurrTime);
        if (diff < minUpdateDiff)
        {
            uint32 sleepTime = minUpdateDiff - diff;
            if (sleepTime >= halfMaxCoreStuckTime)
                TC_LOG_ERROR("server.worldserver", "WorldUpdateLoop() waiting for {} ms with MaxCoreStuckTime set to {} ms", sleepTime, maxCoreStuckTime);
            // sleep until enough time passes that we can update all timers
            std::this_thread::sleep_for(Milliseconds(sleepTime));
            continue;
        }

        sWorld->Update(diff);
        realPrevTime = realCurrTime;

#ifdef _WIN32
        if (m_ServiceStatus == 0)
            World::StopNow(SHUTDOWN_EXIT_CODE);
            //worldserver关闭
        while (m_ServiceStatus == 2)
            Sleep(1000);
          //休眠1000毫秒
#endif
    }

    LoginDatabase.WarnAboutSyncQueries(false);
    CharacterDatabase.WarnAboutSyncQueries(false);
    WorldDatabase.WarnAboutSyncQueries(false);
    HotfixDatabase.WarnAboutSyncQueries(false);
}

void SignalHandler(boost::system::error_code const& error, int /*signalNumber*/)
{
    if (!error)
        World::StopNow(SHUTDOWN_EXIT_CODE);
}

void FreezeDetector::Handler(std::weak_ptr<FreezeDetector> freezeDetectorRef, boost::system::error_code const& error)
{
    if (!error)
    {
        if (std::shared_ptr<FreezeDetector> freezeDetector = freezeDetectorRef.lock())
        {
            uint32 curtime = getMSTime();

            uint32 worldLoopCounter = World::m_worldLoopCounter;
            if (freezeDetector->_worldLoopCounter != worldLoopCounter)
            {
                freezeDetector->_lastChangeMsTime = curtime;
                freezeDetector->_worldLoopCounter = worldLoopCounter;
            }
            // possible freeze  //可能的冻结
            else
            {
                uint32 msTimeDiff = getMSTimeDiff(freezeDetector->_lastChangeMsTime, curtime);

              /*  if (msTimeDiff > freezeDetector->_maxCoreStuckTimeInMs)
                {
                    TC_LOG_ERROR("server.worldserver", "World Thread hangs for {} ms, forcing a crash!", msTimeDiff);
                    ABORT_MSG("World Thread hangs for %u ms, forcing a crash!", msTimeDiff);
                }*/
                //增加了逍遥837的creature数据后,经常宕机,尝试把此处注释,看能不能缓解

            }

            freezeDetector->_timer.expires_from_now(boost::posix_time::seconds(1));
            freezeDetector->_timer.async_wait(std::bind(&FreezeDetector::Handler, freezeDetectorRef, std::placeholders::_1));
        }
    }
}

AsyncAcceptor* StartRaSocketAcceptor(Trinity::Asio::IoContext& ioContext)
{
    uint16 raPort = uint16(sConfigMgr->GetIntDefault("Ra.Port", 3443));
    std::string raListener = sConfigMgr->GetStringDefault("Ra.IP", "0.0.0.0");

    AsyncAcceptor* acceptor = new AsyncAcceptor(ioContext, raListener, raPort);
    if (!acceptor->Bind())
    {
        TC_LOG_ERROR("server.worldserver", "Failed to bind RA socket acceptor");
        //绑定RA套接字接收器失败
        delete acceptor;
        return nullptr;
    }

    acceptor->AsyncAccept<RASession>();
    return acceptor;
}

bool LoadRealmInfo()
{
    if (Realm const* realmListRealm = sRealmList->GetRealm(realm.Id))
    {
        realm.Id = realmListRealm->Id;
        realm.Build = realmListRealm->Build;
        realm.ExternalAddress = std::make_unique<boost::asio::ip::address>(*realmListRealm->ExternalAddress);
        realm.LocalAddress = std::make_unique<boost::asio::ip::address>(*realmListRealm->LocalAddress);
        realm.LocalSubnetMask = std::make_unique<boost::asio::ip::address>(*realmListRealm->LocalSubnetMask);
        realm.Port = realmListRealm->Port;
        realm.Name = realmListRealm->Name;
        realm.NormalizedName = realmListRealm->NormalizedName;
        realm.Type = realmListRealm->Type;
        realm.Flags = realmListRealm->Flags;
        realm.Timezone = realmListRealm->Timezone;
        realm.AllowedSecurityLevel = realmListRealm->AllowedSecurityLevel;
        realm.PopulationLevel = realmListRealm->PopulationLevel;
        return true;
    }

    return false;
}

/// Initialize connection to the databases
//  初始化数据库连接
bool StartDB()
{
    MySQL::Library_Init();

    // Load databases
    DatabaseLoader loader("server.worldserver", DatabaseLoader::DATABASE_NONE);
    loader
        .AddDatabase(LoginDatabase, "Login")
        //增加数Login据库,下面依次类推
        .AddDatabase(CharacterDatabase, "Character")
        .AddDatabase(WorldDatabase, "World")
        .AddDatabase(HotfixDatabase, "Hotfix");

    if (!loader.Load()) //如果加载失败
        return false;

    ///- Get the realm Id from the configuration file
    realm.Id.Realm = sConfigMgr->GetIntDefault("RealmID", 0);
    if (!realm.Id.Realm)
    {
        TC_LOG_ERROR("server.worldserver", "Realm ID not defined in configuration file");
        //服务器ID未在配置中定义
        return false;
    }

    TC_LOG_INFO("server.worldserver", "Realm running as realm ID {}", realm.Id.Realm);

    ///- Clean the database before starting
    // 在开始前清理数据库
    ClearOnlineAccounts();

    ///- Insert version info into DB
    //插入版本信息

    WorldDatabase.PExecute("UPDATE version SET core_version = '{}', core_revision = '{}'", GitRevision::GetFullVersion(), GitRevision::GetHash());  // One-time query   //一次性查询
    //在数据库中更新版本信息
    sWorld->LoadDBVersion();

    TC_LOG_INFO("server.worldserver", "Using World DB: {}", sWorld->GetDBVersion());
    return true;
}

void StopDB()   //停止数据库
{
    CharacterDatabase.Close();
    WorldDatabase.Close();
    LoginDatabase.Close();

    MySQL::Library_End();
}

/// Clear 'online' status for all accounts with characters in this realm
//清除本服务器上的所有在线状态
void ClearOnlineAccounts()
{
    // Reset online status for all accounts with characters on the current realm
    //为当前服务器上所有账号的角色重置在线状态
    LoginDatabase.DirectPExecute("UPDATE account SET online = 0 WHERE online > 0 AND id IN (SELECT acctid FROM realmcharacters WHERE realmid = {})", realm.Id.Realm);
    //在数据库中设置在线状态为0
    // Reset online status for all characters
    // 为所有角色重置在线状态
    CharacterDatabase.DirectExecute("UPDATE characters SET online = 0 WHERE online <> 0");
    //角色数据库中设置不在线

    // Battleground instance ids reset at server restart
    //在服务器重启时重置战场副本的ID.
    CharacterDatabase.DirectExecute("UPDATE character_battleground_data SET instanceId = 0");
    //角色数据库运行SQL设置角色战场数据的副本ID为0.
}

/// @}

variables_map GetConsoleArguments(int argc, char** argv, fs::path& configFile, std::string& configService)
{
    // Silences warning about configService not be used if the OS is not Windows
    (void)configService;

    options_description all("Allowed options");
    all.add_options()
        ("help,h", "print usage message")
        ("version,v", "print version build info")
        ("config,c", value<fs::path>(&configFile)->default_value(fs::absolute(_TRINITY_CORE_CONFIG)),
                     "use <arg> as configuration file")
        ("update-databases-only,u", "updates databases only")
        ;
#ifdef _WIN32
    options_description win("Windows platform specific options");
    win.add_options()
        ("service,s", value<std::string>(&configService)->default_value(""), "Windows service options: [install | uninstall]")
        ;

    all.add(win);
#endif
    variables_map vm;
    try
    {
        store(command_line_parser(argc, argv).options(all).allow_unregistered().run(), vm);
        notify(vm);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }

    if (vm.count("help"))
    {
        std::cout << all << "\n";
    }
    else if (vm.count("version"))
    {
        std::cout << GitRevision::GetFullVersion() << "\n";
    }

    return vm;
}
//小女孩中文注释,2022年3月15日13:56:05
