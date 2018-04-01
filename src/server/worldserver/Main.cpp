/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
#include "Banner.h"
#include "BattlegroundMgr.h"
#include "BigNumber.h"
#include "CliRunnable.h"
#include "Configuration/Config.h"
#include "DatabaseEnv.h"
#include "DatabaseLoader.h"
#include "GitRevision.h"
#include "InstanceSaveMgr.h"
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
#include "TCSoap.h"
#include "World.h"
#include "WorldSocket.h"
#include "WorldSocketMgr.h"
#include <openssl/opensslv.h>
#include <openssl/crypto.h>
#include <boost/asio/deadline_timer.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/program_options.hpp>
#include <google/protobuf/stubs/common.h>
#include <iostream>
#include <csignal>

using namespace boost::program_options;
namespace fs = boost::filesystem;

#ifndef _TRINITY_CORE_CONFIG
    #define _TRINITY_CORE_CONFIG  "worldserver.conf"
#endif

#define WORLD_SLEEP_CONST 50

#ifdef _WIN32
#include "ServiceWin32.h"
char serviceName[] = "worldserver";
char serviceLongName[] = "TrinityCore world service";
char serviceDescription[] = "TrinityCore World of Warcraft emulator world service";
/*
 * -1 - not in service mode
 *  0 - stopped
 *  1 - running
 *  2 - paused
 */
int m_ServiceStatus = -1;
#endif

class FreezeDetector
{
public:
    FreezeDetector(Trinity::Asio::IoContext& ioContext, uint32 maxCoreStuckTime)
        : _timer(ioContext), _worldLoopCounter(0), _lastChangeMsTime(0), _maxCoreStuckTimeInMs(maxCoreStuckTime) { }

    static void Start(std::shared_ptr<FreezeDetector> const& freezeDetector)
    {
        freezeDetector->_timer.expires_from_now(boost::posix_time::seconds(5));
        freezeDetector->_timer.async_wait(std::bind(&FreezeDetector::Handler, std::weak_ptr<FreezeDetector>(freezeDetector), std::placeholders::_1));
    }

    static void Handler(std::weak_ptr<FreezeDetector> freezeDetectorRef, boost::system::error_code const& error);

private:
    boost::asio::deadline_timer _timer;
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

/// Launch the Trinity server
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
#endif

    std::string configError;
    if (!sConfigMgr->LoadInitial(configFile.generic_string(),
                                 std::vector<std::string>(argv, argv + argc),
                                 configError))
    {
        printf("Error in config file: %s\n", configError.c_str());
        return 1;
    }

    std::shared_ptr<Trinity::Asio::IoContext> ioContext = std::make_shared<Trinity::Asio::IoContext>();

    sLog->RegisterAppender<AppenderDB>();
    // If logs are supposed to be handled async then we need to pass the IoContext into the Log singleton
    sLog->Initialize(sConfigMgr->GetBoolDefault("Log.Async.Enable", false) ? ioContext.get() : nullptr);

    Trinity::Banner::Show("worldserver-daemon",
        [](char const* text)
        {
            TC_LOG_INFO("server.worldserver", "%s", text);
        },
        []()
        {
            TC_LOG_INFO("server.worldserver", "Using configuration file %s.", sConfigMgr->GetFilename().c_str());
            TC_LOG_INFO("server.worldserver", "Using SSL version: %s (library: %s)", OPENSSL_VERSION_TEXT, SSLeay_version(SSLEAY_VERSION));
            TC_LOG_INFO("server.worldserver", "Using Boost version: %i.%i.%i", BOOST_VERSION / 100000, BOOST_VERSION / 100 % 1000, BOOST_VERSION % 100);
        }
    );

    OpenSSLCrypto::threadsSetup();

    std::shared_ptr<void> opensslHandle(nullptr, [](void*) { OpenSSLCrypto::threadsCleanup(); });

    // Seed the OpenSSL's PRNG here.
    // That way it won't auto-seed when calling BigNumber::SetRand and slow down the first world login
    BigNumber seed;
    seed.SetRand(16 * 8);

    /// worldserver PID file creation
    std::string pidFile = sConfigMgr->GetStringDefault("PidFile", "");
    if (!pidFile.empty())
    {
        if (uint32 pid = CreatePIDFile(pidFile))
            TC_LOG_INFO("server.worldserver", "Daemon PID: %u\n", pid);
        else
        {
            TC_LOG_ERROR("server.worldserver", "Cannot create PID file %s.\n", pidFile.c_str());
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
    std::shared_ptr<std::vector<std::thread>> threadPool(new std::vector<std::thread>(), [ioContext](std::vector<std::thread>* del)
    {
        ioContext->stop();
        for (std::thread& thr : *del)
            thr.join();

        delete del;
    });

    if (numThreads < 1)
        numThreads = 1;

    for (int i = 0; i < numThreads; ++i)
        threadPool->push_back(std::thread([ioContext]() { ioContext->run(); }));

    // Set process priority according to configuration settings
    SetProcessPriority("server.worldserver", sConfigMgr->GetIntDefault(CONFIG_PROCESSOR_AFFINITY, 0), sConfigMgr->GetBoolDefault(CONFIG_HIGH_PRIORITY, false));

    // Start the databases
    if (!StartDB())
        return 1;

    std::shared_ptr<void> dbHandle(nullptr, [](void*) { StopDB(); });

    // Set server offline (not connectable)
    LoginDatabase.DirectPExecute("UPDATE realmlist SET flag = flag | %u WHERE id = '%d'", REALM_FLAG_OFFLINE, realm.Id.Realm);

    sRealmList->Initialize(*ioContext, sConfigMgr->GetIntDefault("RealmsStateUpdateDelay", 10));

    std::shared_ptr<void> sRealmListHandle(nullptr, [](void*) { sRealmList->Close(); });

    LoadRealmInfo();

    sMetric->Initialize(realm.Name, *ioContext, []()
    {
        TC_METRIC_VALUE("online_players", sWorld->GetPlayerCount());
    });

    TC_METRIC_EVENT("events", "Worldserver started", "");

    std::shared_ptr<void> sMetricHandle(nullptr, [](void*)
    {
        TC_METRIC_EVENT("events", "Worldserver shutdown", "");
        sMetric->ForceSend();
    });

    sScriptMgr->SetScriptLoader(AddScripts);
    std::shared_ptr<void> sScriptMgrHandle(nullptr, [](void*)
    {
        sScriptMgr->Unload();
        sScriptReloadMgr->Unload();
    });

    // Initialize the World
    sWorld->SetInitialWorldSettings();

    std::shared_ptr<void> mapManagementHandle(nullptr, [](void*)
    {
        // unload battleground templates before different singletons destroyed
        sBattlegroundMgr->DeleteAllBattlegrounds();

        sInstanceSaveMgr->Unload();
        sOutdoorPvPMgr->Die();                    // unload it before MapManager
        sMapMgr->UnloadAll();                     // unload all grids (including locked in memory)
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
            [](std::thread* thr)
        {
            thr->join();
            delete thr;
        });
    }

    // Launch the worldserver listener socket
    uint16 worldPort = uint16(sWorld->getIntConfig(CONFIG_PORT_WORLD));
    uint16 instancePort = uint16(sWorld->getIntConfig(CONFIG_PORT_INSTANCE));
    std::string worldListener = sConfigMgr->GetStringDefault("BindIP", "0.0.0.0");

    int networkThreads = sConfigMgr->GetIntDefault("Network.Threads", 1);

    if (networkThreads <= 0)
    {
        TC_LOG_ERROR("server.worldserver", "Network.Threads must be greater than 0");
        return 1;
    }

    if (!sWorldSocketMgr.StartWorldNetwork(*ioContext, worldListener, worldPort, instancePort, networkThreads))
    {
        TC_LOG_ERROR("server.worldserver", "Failed to initialize network");
        return 1;
    }

    std::shared_ptr<void> sWorldSocketMgrHandle(nullptr, [](void*)
    {
        sWorld->KickAll();                                       // save and kick all players
        sWorld->UpdateSessions(1);                             // real players unload required UpdateSessions call

        sWorldSocketMgr.StopNetwork();

        ///- Clean database before leaving
        ClearOnlineAccounts();
    });

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

    // Set server online (allow connecting now)
    LoginDatabase.DirectPExecute("UPDATE realmlist SET flag = flag & ~%u, population = 0 WHERE id = '%u'", REALM_FLAG_OFFLINE, realm.Id.Realm);
    realm.PopulationLevel = 0.0f;
    realm.Flags = RealmFlags(realm.Flags & ~uint32(REALM_FLAG_OFFLINE));

    // Start the freeze check callback cycle in 5 seconds (cycle itself is 1 sec)
    std::shared_ptr<FreezeDetector> freezeDetector;
    if (int coreStuckTime = sConfigMgr->GetIntDefault("MaxCoreStuckTime", 0))
    {
        freezeDetector = std::make_shared<FreezeDetector>(*ioContext, coreStuckTime * 1000);
        FreezeDetector::Start(freezeDetector);
        TC_LOG_INFO("server.worldserver", "Starting up anti-freeze thread (%u seconds max stuck time)...", coreStuckTime);
    }

    TC_LOG_INFO("server.worldserver", "%s (worldserver-daemon) ready...", GitRevision::GetFullVersion());

    sScriptMgr->OnStartup();

    WorldUpdateLoop();

    // Shutdown starts here
    threadPool.reset();

    sLog->SetSynchronous();

    sScriptMgr->OnShutdown();

    // set server offline
    LoginDatabase.DirectPExecute("UPDATE realmlist SET flag = flag | %u WHERE id = '%d'", REALM_FLAG_OFFLINE, realm.Id.Realm);

    TC_LOG_INFO("server.worldserver", "Halting process...");

    // 0 - normal shutdown
    // 1 - shutdown at error
    // 2 - restart command used, this code can be used by restarter for restart Trinityd

    return World::GetExitCode();
}

void ShutdownCLIThread(std::thread* cliThread)
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
                LPSTR errorBuffer;
                DWORD numCharsWritten = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
                    nullptr, errorCode, 0, (LPTSTR)&errorBuffer, 0, nullptr);
                if (!numCharsWritten)
                    errorBuffer = "Unknown error";

                TC_LOG_DEBUG("server.worldserver", "Error cancelling I/O of CliThread, error code %u, detail: %s", uint32(errorCode), errorBuffer);

                if (numCharsWritten)
                    LocalFree(errorBuffer);

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
    uint32 realCurrTime = 0;
    uint32 realPrevTime = getMSTime();

    ///- While we have not World::m_stopEvent, update the world
    while (!World::IsStopped())
    {
        ++World::m_worldLoopCounter;
        realCurrTime = getMSTime();

        uint32 diff = getMSTimeDiff(realPrevTime, realCurrTime);

        sWorld->Update(diff);
        realPrevTime = realCurrTime;

        uint32 executionTimeDiff = getMSTimeDiff(realCurrTime, getMSTime());

        // we know exactly how long it took to update the world, if the update took less than WORLD_SLEEP_CONST, sleep for WORLD_SLEEP_CONST - world update time
        if (executionTimeDiff < WORLD_SLEEP_CONST)
            std::this_thread::sleep_for(std::chrono::milliseconds(WORLD_SLEEP_CONST - executionTimeDiff));

#ifdef _WIN32
        if (m_ServiceStatus == 0)
            World::StopNow(SHUTDOWN_EXIT_CODE);

        while (m_ServiceStatus == 2)
            Sleep(1000);
#endif
    }
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
            else if (getMSTimeDiff(freezeDetector->_lastChangeMsTime, curtime) > freezeDetector->_maxCoreStuckTimeInMs)
            {
                TC_LOG_ERROR("server.worldserver", "World Thread hangs, kicking out server!");
                ABORT();
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
        realm.ExternalAddress = Trinity::make_unique<boost::asio::ip::address>(*realmListRealm->ExternalAddress);
        realm.LocalAddress = Trinity::make_unique<boost::asio::ip::address>(*realmListRealm->LocalAddress);
        realm.LocalSubnetMask = Trinity::make_unique<boost::asio::ip::address>(*realmListRealm->LocalSubnetMask);
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

    ///- Get the realm Id from the configuration file
    realm.Id.Realm = sConfigMgr->GetIntDefault("RealmID", 0);
    if (!realm.Id.Realm)
    {
        TC_LOG_ERROR("server.worldserver", "Realm ID not defined in configuration file");
        return false;
    }

    TC_LOG_INFO("server.worldserver", "Realm running as realm ID %u", realm.Id.Realm);

    ///- Clean the database before starting
    ClearOnlineAccounts();

    ///- Insert version info into DB
    WorldDatabase.PExecute("UPDATE version SET core_version = '%s', core_revision = '%s'", GitRevision::GetFullVersion(), GitRevision::GetHash());        // One-time query

    sWorld->LoadDBVersion();

    TC_LOG_INFO("server.worldserver", "Using World DB: %s", sWorld->GetDBVersion());
    return true;
}

void StopDB()
{
    CharacterDatabase.Close();
    WorldDatabase.Close();
    LoginDatabase.Close();

    MySQL::Library_End();
}

/// Clear 'online' status for all accounts with characters in this realm
void ClearOnlineAccounts()
{
    // Reset online status for all accounts with characters on the current realm
    LoginDatabase.DirectPExecute("UPDATE account SET online = 0 WHERE online > 0 AND id IN (SELECT acctid FROM realmcharacters WHERE realmid = %d)", realm.Id.Realm);

    // Reset online status for all characters
    CharacterDatabase.DirectExecute("UPDATE characters SET online = 0 WHERE online <> 0");

    // Battleground instance ids reset at server restart
    CharacterDatabase.DirectExecute("UPDATE character_battleground_data SET instanceId = 0");
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
