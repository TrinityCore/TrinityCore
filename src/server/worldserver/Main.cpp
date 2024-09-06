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
#include "IpNetwork.h"
#include "Locales.h"
#include "MapManager.h"
#include "Memory.h"
#include "Metric.h"
#include "MySQLThreading.h"
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

using namespace boost::program_options;
namespace fs = boost::filesystem;

#ifndef _TRINITY_CORE_CONFIG
    #define _TRINITY_CORE_CONFIG  "worldserver.conf"
#endif

#ifndef _TRINITY_CORE_CONFIG_DIR
    #define _TRINITY_CORE_CONFIG_DIR "worldserver.conf.d"
#endif

#ifdef _WIN32
#include "ServiceWin32.h"
#include <tchar.h>
TCHAR serviceName[] = _T("worldserver");
TCHAR serviceLongName[] = _T("TrinityCore world service");
TCHAR serviceDescription[] = _T("TrinityCore World of Warcraft emulator world service");
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

class FreezeDetector
{
public:
    FreezeDetector(Trinity::Asio::IoContext& ioContext, uint32 maxCoreStuckTime)
        : _timer(ioContext), _worldLoopCounter(0), _lastChangeMsTime(getMSTime()), _maxCoreStuckTimeInMs(maxCoreStuckTime) { }

    static void Start(std::shared_ptr<FreezeDetector> const& freezeDetector)
    {
        freezeDetector->_timer.expires_from_now(boost::posix_time::seconds(5));
        freezeDetector->_timer.async_wait([freezeDetectorRef = std::weak_ptr(freezeDetector)](boost::system::error_code const& error) mutable
        {
            Handler(std::move(freezeDetectorRef), error);
        });
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
void ClearOnlineAccounts(uint32 realmId);
struct ShutdownTCSoapThread { void operator()(std::thread* thread) const; };
struct ShutdownCLIThread { void operator()(std::thread* cliThread) const; };
variables_map GetConsoleArguments(int argc, char** argv, fs::path& configFile, fs::path& configDir, std::string& winServiceAction);

/// Launch the Trinity server
extern int main(int argc, char** argv)
{
    signal(SIGABRT, &Trinity::AbortHandler);

    Trinity::VerifyOsVersion();

    Trinity::Locale::Init();

    auto configFile = fs::absolute(_TRINITY_CORE_CONFIG);
    auto configDir  = fs::absolute(_TRINITY_CORE_CONFIG_DIR);
    std::string winServiceAction;

    auto vm = GetConsoleArguments(argc, argv, configFile, configDir, winServiceAction);
    // exit if help or version is enabled
    if (vm.count("help") || vm.count("version"))
        return 0;

    uint32 dummy = 0;

    GOOGLE_PROTOBUF_VERIFY_VERSION;

    auto protobufHandle = Trinity::make_unique_ptr_with_deleter(&dummy, [](void*) { google::protobuf::ShutdownProtobufLibrary(); });

#ifdef _WIN32
    if (winServiceAction == "install")
        return WinServiceInstall() ? 0 : 1;
    if (winServiceAction == "uninstall")
        return WinServiceUninstall() ? 0 : 1;
    if (winServiceAction == "run")
        return WinServiceRun() ? 0 : 1;

    Optional<UINT> newTimerResolution;
    boost::system::error_code dllError;
    auto winmm = Trinity::make_unique_ptr_with_deleter(new boost::dll::shared_library("winmm.dll", dllError, boost::dll::load_mode::search_system_folders), [&](boost::dll::shared_library* lib)
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

    std::vector<std::string> loadedConfigFiles;
    std::vector<std::string> configDirErrors;
    bool additionalConfigFileLoadSuccess = sConfigMgr->LoadAdditionalDir(configDir.generic_string(), true, loadedConfigFiles, configDirErrors);
    for (std::string const& loadedConfigFile : loadedConfigFiles)
        printf("Loaded additional config file %s\n", loadedConfigFile.c_str());

    if (!additionalConfigFileLoadSuccess)
    {
        for (std::string const& configDirError : configDirErrors)
            printf("Error in additional config files: %s\n", configDirError.c_str());

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
            TC_LOG_INFO("server.worldserver", "Using SSL version: {} (library: {})", OPENSSL_VERSION_TEXT, OpenSSL_version(OPENSSL_VERSION));
            TC_LOG_INFO("server.worldserver", "Using Boost version: {}.{}.{}", BOOST_VERSION / 100000, BOOST_VERSION / 100 % 1000, BOOST_VERSION % 100);
        }
    );

    for (std::string const& key : overriddenKeys)
        TC_LOG_INFO("server.worldserver", "Configuration field '{}' was overridden with environment variable.", key);

    OpenSSLCrypto::threadsSetup(boost::dll::program_location().remove_filename());

    auto opensslHandle = Trinity::make_unique_ptr_with_deleter(&dummy, [](void*) { OpenSSLCrypto::threadsCleanup(); });

    // Seed the OpenSSL's PRNG here.
    // That way it won't auto-seed when calling BigNumber::SetRand and slow down the first world login
    BigNumber seed;
    seed.SetRand(16 * 8);

    /// worldserver PID file creation
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
    boost::asio::signal_set signals(*ioContext, SIGINT, SIGTERM);
#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
    signals.add(SIGBREAK);
#endif
    signals.async_wait(SignalHandler);

    // Start the Boost based thread pool
    int numThreads = sConfigMgr->GetIntDefault("ThreadPool", 1);
    if (numThreads < 1)
        numThreads = 1;

    std::unique_ptr<Trinity::ThreadPool> threadPool = std::make_unique<Trinity::ThreadPool>(numThreads);

    for (int i = 0; i < numThreads; ++i)
        threadPool->PostWork([ioContext]() { ioContext->run(); });

    auto ioContextStopHandle = Trinity::make_unique_ptr_with_deleter(ioContext.get(), [](Trinity::Asio::IoContext* ctx) { ctx->stop(); });

    // Set process priority according to configuration settings
    SetProcessPriority("server.worldserver", sConfigMgr->GetIntDefault(CONFIG_PROCESSOR_AFFINITY, 0), sConfigMgr->GetBoolDefault(CONFIG_HIGH_PRIORITY, false));

    // Start the databases
    if (!StartDB())
        return 1;

    auto dbHandle = Trinity::make_unique_ptr_with_deleter(&dummy, [](void*) { StopDB(); });

    if (vm.count("update-databases-only"))
        return 0;

    Trinity::Net::ScanLocalNetworks();

    sRealmList->Initialize(*ioContext, sConfigMgr->GetIntDefault("RealmsStateUpdateDelay", 10));

    auto sRealmListHandle = Trinity::make_unique_ptr_with_deleter(sRealmList, [](RealmList* realmList) { realmList->Close(); });

    ///- Get the realm Id from the configuration file
    uint32 realmId = sConfigMgr->GetIntDefault("RealmID", 0);
    if (!realmId)
    {
        TC_LOG_ERROR("server.worldserver", "Realm ID not defined in configuration file");
        return 1;
    }

    sRealmList->SetCurrentRealmId(realmId);

    TC_LOG_INFO("server.worldserver", "Realm running as realm ID {}", realmId);

    ///- Clean the database before starting
    ClearOnlineAccounts(realmId);

    std::shared_ptr<Realm const> realm = sRealmList->GetCurrentRealm();
    if (!realm)
        return 1;

    // Set server offline (not connectable)
    LoginDatabase.DirectPExecute("UPDATE realmlist SET flag = flag | {} WHERE id = '{}'", Trinity::Legacy::REALM_FLAG_OFFLINE, realmId);

    sMetric->Initialize(realm->Name, *ioContext, []()
    {
        TC_METRIC_VALUE("online_players", sWorld->GetPlayerCount());
        TC_METRIC_VALUE("db_queue_login", uint64(LoginDatabase.QueueSize()));
        TC_METRIC_VALUE("db_queue_character", uint64(CharacterDatabase.QueueSize()));
        TC_METRIC_VALUE("db_queue_world", uint64(WorldDatabase.QueueSize()));
    });

    realm = nullptr;

    TC_METRIC_EVENT("events", "Worldserver started", "");

    auto sMetricHandle = Trinity::make_unique_ptr_with_deleter(sMetric, [](Metric* metric)
    {
        TC_METRIC_EVENT("events", "Worldserver shutdown", "");
        metric->Unload();
    });

    auto scriptReloadMgrHandle = Trinity::make_unique_ptr_with_deleter(sScriptReloadMgr, [](ScriptReloadMgr* mgr) { mgr->Unload(); });

    sScriptMgr->SetScriptLoader(AddScripts);
    auto sScriptMgrHandle = Trinity::make_unique_ptr_with_deleter(sScriptMgr, [](ScriptMgr* mgr) { mgr->Unload(); });

    // Initialize the World
    sSecretMgr->Initialize(SECRET_OWNER_WORLDSERVER);
    if (!sWorld->SetInitialWorldSettings())
        return 1;

    auto instanceLockMgrHandle = Trinity::make_unique_ptr_with_deleter(&sInstanceLockMgr, [](InstanceLockMgr* mgr) { mgr->Unload(); });

    auto terrainMgrHandle = Trinity::make_unique_ptr_with_deleter(&sTerrainMgr, [](TerrainMgr* mgr) { mgr->UnloadAll(); });

    auto outdoorPvpMgrHandle = Trinity::make_unique_ptr_with_deleter(sOutdoorPvPMgr, [](OutdoorPvPMgr* mgr) { mgr->Die(); });

    // unload all grids (including locked in memory)
    auto mapManagementHandle = Trinity::make_unique_ptr_with_deleter(sMapMgr, [](MapManager* mgr) { mgr->UnloadAll(); });

    // unload battleground templates before different singletons destroyed
    auto battlegroundMgrHandle = Trinity::make_unique_ptr_with_deleter(sBattlegroundMgr, [](BattlegroundMgr* mgr) { mgr->DeleteAllBattlegrounds(); });

    // Start the Remote Access port (acceptor) if enabled
    std::unique_ptr<AsyncAcceptor> raAcceptor;
    if (sConfigMgr->GetBoolDefault("Ra.Enable", false))
        raAcceptor.reset(StartRaSocketAcceptor(*ioContext));

    // Start soap serving thread if enabled
    std::unique_ptr<std::thread, ShutdownTCSoapThread> soapThread;
    if (sConfigMgr->GetBoolDefault("SOAP.Enabled", false))
    {
        if (std::thread* soap = CreateSoapThread(sConfigMgr->GetStringDefault("SOAP.IP", "127.0.0.1"), uint16(sConfigMgr->GetIntDefault("SOAP.Port", 7878))))
            soapThread.reset(soap);
        else
            return -1;
    }

    // Launch the worldserver listener socket
    uint16 worldPort = uint16(sWorld->getIntConfig(CONFIG_PORT_WORLD));
    uint16 instancePort = uint16(sWorld->getIntConfig(CONFIG_PORT_INSTANCE));
    std::string worldListener = sConfigMgr->GetStringDefault("BindIP", "0.0.0.0");

    int networkThreads = sConfigMgr->GetIntDefault("Network.Threads", 1);

    if (networkThreads <= 0)
    {
        TC_LOG_ERROR("server.worldserver", "Network.Threads must be greater than 0");
        World::StopNow(ERROR_EXIT_CODE);
        return 1;
    }

    if (!sWorldSocketMgr.StartWorldNetwork(*ioContext, worldListener, worldPort, instancePort, networkThreads))
    {
        TC_LOG_ERROR("server.worldserver", "Failed to initialize network");
        World::StopNow(ERROR_EXIT_CODE);
        return 1;
    }

    auto sWorldSocketMgrHandle = Trinity::make_unique_ptr_with_deleter(&sWorldSocketMgr, [realmId](WorldSocketMgr* mgr)
    {
        sWorld->KickAll();                                       // save and kick all players
        sWorld->UpdateSessions(1);                             // real players unload required UpdateSessions call

        mgr->StopNetwork();

        ///- Clean database before leaving
        ClearOnlineAccounts(realmId);
    });

    // Set server online (allow connecting now)
    LoginDatabase.DirectPExecute("UPDATE realmlist SET flag = flag & ~{}, population = 0 WHERE id = '{}'", Trinity::Legacy::REALM_FLAG_OFFLINE, realmId);

    // Start the freeze check callback cycle in 5 seconds (cycle itself is 1 sec)
    std::shared_ptr<FreezeDetector> freezeDetector;
    if (int coreStuckTime = sConfigMgr->GetIntDefault("MaxCoreStuckTime", 60))
    {
        freezeDetector = std::make_shared<FreezeDetector>(*ioContext, coreStuckTime * 1000);
        FreezeDetector::Start(freezeDetector);
        TC_LOG_INFO("server.worldserver", "Starting up anti-freeze thread ({} seconds max stuck time)...", coreStuckTime);
    }

    sScriptMgr->OnStartup();

    TC_LOG_INFO("server.worldserver", "{} (worldserver-daemon) ready...", GitRevision::GetFullVersion());

    // Launch CliRunnable thread
    std::unique_ptr<std::thread, ShutdownCLIThread> cliThread;
#ifdef _WIN32
    if (sConfigMgr->GetBoolDefault("Console.Enable", true) && (m_ServiceStatus == -1)/* need disable console in service mode*/)
#else
    if (sConfigMgr->GetBoolDefault("Console.Enable", true))
#endif
    {
        cliThread.reset(new std::thread(CliThread));
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
    LoginDatabase.DirectPExecute("UPDATE realmlist SET flag = flag | {} WHERE id = '{}'", Trinity::Legacy::REALM_FLAG_OFFLINE, realmId);

    TC_LOG_INFO("server.worldserver", "Halting process...");

    // 0 - normal shutdown
    // 1 - shutdown at error
    // 2 - restart command used, this code can be used by restarter for restart Trinityd

    return World::GetExitCode();
}

void ShutdownTCSoapThread::operator()(std::thread* thread) const
{
    thread->join();
    delete thread;
}

void ShutdownCLIThread::operator()(std::thread* cliThread) const
{
    if (cliThread != nullptr)
    {
#ifdef _WIN32
        // First try to cancel any I/O in the CLI thread
        if (!CancelSynchronousIo(cliThread->native_handle()))
        {
            // if CancelSynchronousIo() fails, print the error and try with old way
            DWORD errorCode = GetLastError();

            // if CancelSynchronousIo fails with ERROR_NOT_FOUND then there was nothing to cancel, proceed with shutdown
            if (errorCode != ERROR_NOT_FOUND)
            {
                LPCSTR errorBuffer;
                DWORD numCharsWritten = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
                    nullptr, errorCode, 0, (LPTSTR)&errorBuffer, 0, nullptr);
                if (!numCharsWritten)
                    errorBuffer = "Unknown error";

                TC_LOG_DEBUG("server.worldserver", "Error cancelling I/O of CliThread, error code {}, detail: {}", uint32(errorCode), errorBuffer);

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

        while (m_ServiceStatus == 2)
            Sleep(1000);
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
            // possible freeze
            else
            {
                uint32 msTimeDiff = getMSTimeDiff(freezeDetector->_lastChangeMsTime, curtime);
                if (msTimeDiff > freezeDetector->_maxCoreStuckTimeInMs)
                {
                    TC_LOG_ERROR("server.worldserver", "World Thread hangs for {} ms, forcing a crash!", msTimeDiff);
                    ABORT_MSG("World Thread hangs for %u ms, forcing a crash!", msTimeDiff);
                }
            }

            freezeDetector->_timer.expires_from_now(boost::posix_time::seconds(1));
            freezeDetector->_timer.async_wait([freezeDetectorRef = std::move(freezeDetectorRef)](boost::system::error_code const& error) mutable
            {
                Handler(std::move(freezeDetectorRef), error);
            });
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
        delete acceptor;
        return nullptr;
    }

    acceptor->AsyncAccept<RASession>();
    return acceptor;
}

/// Initialize connection to the databases
bool StartDB()
{
    MySQL::Library_Init();

    // Load databases
    DatabaseLoader loader("server.worldserver", DatabaseLoader::DATABASE_NONE);
    loader
        .AddDatabase(LoginDatabase, "Login")
        .AddDatabase(CharacterDatabase, "Character")
        .AddDatabase(WorldDatabase, "World")
        .AddDatabase(HotfixDatabase, "Hotfix");

    if (!loader.Load())
        return false;

    ///- Insert version info into DB
    WorldDatabase.PExecute("UPDATE version SET core_version = '{}', core_revision = '{}'", GitRevision::GetFullVersion(), GitRevision::GetHash());        // One-time query

    sWorld->LoadDBVersion();

    TC_LOG_INFO("server.worldserver", "Using World DB: {}", sWorld->GetDBVersion());
    return true;
}

void StopDB()
{
    HotfixDatabase.Close();
    WorldDatabase.Close();
    CharacterDatabase.Close();
    LoginDatabase.Close();

    MySQL::Library_End();
}

/// Clear 'online' status for all accounts with characters in this realm
void ClearOnlineAccounts(uint32 realmId)
{
    // Reset online status for all accounts with characters on the current realm
    LoginDatabase.DirectPExecute("UPDATE account SET online = 0 WHERE online > 0 AND id IN (SELECT acctid FROM realmcharacters WHERE realmid = {})", realmId);

    // Reset online status for all characters
    CharacterDatabase.DirectExecute("UPDATE characters SET online = 0 WHERE online <> 0");

    // Battleground instance ids reset at server restart
    CharacterDatabase.DirectExecute("UPDATE character_battleground_data SET instanceId = 0");
}
/// @}

variables_map GetConsoleArguments(int argc, char** argv, fs::path& configFile, fs::path& configDir, [[maybe_unused]] std::string& winServiceAction)
{
    options_description all("Allowed options");
    all.add_options()
        ("help,h", "print usage message")
        ("version,v", "print version build info")
        ("config,c", value<fs::path>(&configFile)->default_value(fs::absolute(_TRINITY_CORE_CONFIG)),
                     "use <arg> as configuration file")
        ("config-dir,cd", value<fs::path>(&configDir)->default_value(fs::absolute(_TRINITY_CORE_CONFIG_DIR)),
                     "use <arg> as directory with additional config files")
        ("update-databases-only,u", "updates databases only")
        ;
#ifdef _WIN32
    options_description win("Windows platform specific options");
    win.add_options()
        ("service,s", value<std::string>(&winServiceAction)->default_value(""), "Windows service options: [install | uninstall]")
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
