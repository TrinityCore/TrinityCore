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

/**
* @file main.cpp
* @brief Authentication Server main program
*
* This file contains the main program for the
* authentication server
*/

#include "AppenderDB.h"
#include "Banner.h"
#include "BigNumber.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "DatabaseLoader.h"
#include "DeadlineTimer.h"
#include "GitRevision.h"
#include "IPLocation.h"
#include "IpNetwork.h"
#include "Locales.h"
#include "LoginRESTService.h"
#include "Memory.h"
#include "MySQLThreading.h"
#include "OpenSSLCrypto.h"
#include "ProcessPriority.h"
#include "RealmList.h"
#include "SecretMgr.h"
#include "SessionManager.h"
#include "SslContext.h"
#include "Util.h"
#include <boost/asio/signal_set.hpp>
#include <boost/dll/runtime_symbol_info.hpp>
#include <boost/program_options.hpp>
#include <boost/filesystem/operations.hpp>
#include <google/protobuf/stubs/common.h>
#include <iostream>
#include <csignal>

#include "Hacks/boost_program_options_with_filesystem_path.h"

using namespace boost::program_options;
namespace fs = boost::filesystem;

#ifndef _TRINITY_BNET_CONFIG
# define _TRINITY_BNET_CONFIG  "bnetserver.conf"
#endif
#ifndef _TRINITY_BNET_CONFIG_DIR
    #define _TRINITY_BNET_CONFIG_DIR "bnetserver.conf.d"
#endif

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
#include "ServiceWin32.h"
#include <tchar.h>
TCHAR serviceName[] = _T("bnetserver");
TCHAR serviceLongName[] = _T("TrinityCore bnet service");
TCHAR serviceDescription[] = _T("TrinityCore Battle.net emulator authentication service");
/*
* -1 - not in service mode
*  0 - stopped
*  1 - running
*  2 - paused
*/
int m_ServiceStatus = -1;

void ServiceStatusWatcher(std::weak_ptr<Trinity::Asio::DeadlineTimer> serviceStatusWatchTimerRef, std::weak_ptr<Trinity::Asio::IoContext> ioContextRef, boost::system::error_code const& error);
#endif

bool StartDB();
void StopDB();
void SignalHandler(std::weak_ptr<Trinity::Asio::IoContext> ioContextRef, boost::system::error_code const& error, int signalNumber);
void KeepDatabaseAliveHandler(std::weak_ptr<Trinity::Asio::DeadlineTimer> dbPingTimerRef, int32 dbPingInterval, boost::system::error_code const& error);
void BanExpiryHandler(std::weak_ptr<Trinity::Asio::DeadlineTimer> banExpiryCheckTimerRef, int32 banExpiryCheckInterval, boost::system::error_code const& error);
variables_map GetConsoleArguments(int argc, char** argv, fs::path& configFile, fs::path& configDir, std::string& winServiceAction);

int main(int argc, char** argv)
{
    signal(SIGABRT, &Trinity::AbortHandler);

    Trinity::VerifyOsVersion();

    Trinity::Locale::Init();

    auto configFile = fs::absolute(_TRINITY_BNET_CONFIG);
    auto configDir  = fs::absolute(_TRINITY_BNET_CONFIG_DIR);
    std::string winServiceAction;
    auto vm = GetConsoleArguments(argc, argv, configFile, configDir, winServiceAction);
    // exit if help or version is enabled
    if (vm.count("help") || vm.count("version"))
        return 0;

    uint32 dummy = 0;

    GOOGLE_PROTOBUF_VERIFY_VERSION;

    auto protobufHandle = Trinity::make_unique_ptr_with_deleter<[](void*) { google::protobuf::ShutdownProtobufLibrary(); }>(&dummy);

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
    Trinity::Service::Init(serviceLongName, serviceName, serviceDescription, &main, &m_ServiceStatus);
    if (winServiceAction == "install")
        return Trinity::Service::Install();
    if (winServiceAction == "uninstall")
        return Trinity::Service::Uninstall();
    if (winServiceAction == "run")
        return Trinity::Service::Run();
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

    sLog->RegisterAppender<AppenderDB>();
    sLog->Initialize(nullptr);

    Trinity::Banner::Show("bnetserver",
        [](char const* text)
        {
            TC_LOG_INFO("server.bnetserver", "{}", text);
        },
        []()
        {
            TC_LOG_INFO("server.bnetserver", "Using configuration file {}.", sConfigMgr->GetFilename());
            TC_LOG_INFO("server.bnetserver", "Using SSL version: {} (library: {})", OPENSSL_VERSION_TEXT, OpenSSL_version(OPENSSL_VERSION));
            TC_LOG_INFO("server.bnetserver", "Using Boost version: {}.{}.{}", BOOST_VERSION / 100000, BOOST_VERSION / 100 % 1000, BOOST_VERSION % 100);
        }
    );

    for (std::string const& key : overriddenKeys)
        TC_LOG_INFO("server.authserver", "Configuration field '{}' was overridden with environment variable.", key);

    OpenSSLCrypto::threadsSetup(boost::dll::program_location().remove_filename());

    auto opensslHandle = Trinity::make_unique_ptr_with_deleter<[](void*) { OpenSSLCrypto::threadsCleanup(); }>(&dummy);

    // bnetserver PID file creation
    std::string pidFile = sConfigMgr->GetStringDefault("PidFile", "");
    if (!pidFile.empty())
    {
        if (uint32 pid = CreatePIDFile(pidFile))
            TC_LOG_INFO("server.bnetserver", "Daemon PID: {}\n", pid);
        else
        {
            TC_LOG_ERROR("server.bnetserver", "Cannot create PID file {}.\n", pidFile);
            return 1;
        }
    }

    if (!Battlenet::SslContext::Initialize())
    {
        TC_LOG_ERROR("server.bnetserver", "Failed to initialize SSL context");
        return 1;
    }

    // Initialize the database connection
    if (!StartDB())
        return 1;

    auto dbHandle = Trinity::make_unique_ptr_with_deleter<[](void*) { StopDB(); }>(&dummy);

    if (vm.count("update-databases-only"))
        return 0;

    sSecretMgr->Initialize(SECRET_OWNER_BNETSERVER);

    // Load IP Location Database
    sIPLocation->Load();

    std::shared_ptr<Trinity::Asio::IoContext> ioContext = std::make_shared<Trinity::Asio::IoContext>();

    Trinity::Net::ScanLocalNetworks();

    std::string httpBindIp = sConfigMgr->GetStringDefault("BindIP", "0.0.0.0");
    int32 httpPort = sConfigMgr->GetIntDefault("LoginREST.Port", 8081);
    if (httpPort <= 0 || httpPort > 0xFFFF)
    {
        TC_LOG_ERROR("server.bnetserver", "Specified login service port ({}) out of allowed range (1-65535)", httpPort);
        return 1;
    }

    if (!sLoginService.StartNetwork(*ioContext, httpBindIp, httpPort))
    {
        TC_LOG_ERROR("server.bnetserver", "Failed to initialize login service");
        return 1;
    }

    auto sLoginServiceHandle = Trinity::make_unique_ptr_with_deleter<&Battlenet::LoginRESTService::StopNetwork>(&sLoginService);

    // Start the listening port (acceptor) for auth connections
    int32 bnport = sConfigMgr->GetIntDefault("BattlenetPort", 1119);
    if (bnport <= 0 || bnport > 0xFFFF)
    {
        TC_LOG_ERROR("server.bnetserver", "Specified battle.net port ({}) out of allowed range (1-65535)", bnport);
        return 1;
    }

    // Get the list of realms for the server
    sRealmList->Initialize(*ioContext, sConfigMgr->GetIntDefault("RealmsStateUpdateDelay", 10));

    auto sRealmListHandle = Trinity::make_unique_ptr_with_deleter<&RealmList::Close>(sRealmList);

    std::string bindIp = sConfigMgr->GetStringDefault("BindIP", "0.0.0.0");

    if (!sSessionMgr.StartNetwork(*ioContext, bindIp, bnport))
    {
        TC_LOG_ERROR("server.bnetserver", "Failed to initialize network");
        return 1;
    }

    auto sSessionMgrHandle = Trinity::make_unique_ptr_with_deleter<&Battlenet::SessionManager::StopNetwork>(&sSessionMgr);

    // Set signal handlers
    boost::asio::signal_set signals(*ioContext, SIGINT, SIGTERM);
#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
    signals.add(SIGBREAK);
#endif
    signals.async_wait([ioContextRef = std::weak_ptr(ioContext)](boost::system::error_code const& error, int signalNumber) mutable
    {
        SignalHandler(std::move(ioContextRef), error, signalNumber);
    });

    // Set process priority according to configuration settings
    SetProcessPriority("server.bnetserver", sConfigMgr->GetIntDefault(CONFIG_PROCESSOR_AFFINITY, 0), sConfigMgr->GetBoolDefault(CONFIG_HIGH_PRIORITY, false));

    // Enabled a timed callback for handling the database keep alive ping
    int32 dbPingInterval = sConfigMgr->GetIntDefault("MaxPingTime", 30);
    std::shared_ptr<Trinity::Asio::DeadlineTimer> dbPingTimer = std::make_shared<Trinity::Asio::DeadlineTimer>(*ioContext);
    dbPingTimer->expires_from_now(boost::posix_time::minutes(dbPingInterval));
    dbPingTimer->async_wait([timerRef = std::weak_ptr(dbPingTimer), dbPingInterval](boost::system::error_code const& error) mutable
    {
        KeepDatabaseAliveHandler(std::move(timerRef), dbPingInterval, error);
    });

    int32 banExpiryCheckInterval = sConfigMgr->GetIntDefault("BanExpiryCheckInterval", 60);
    std::shared_ptr<Trinity::Asio::DeadlineTimer> banExpiryCheckTimer = std::make_shared<Trinity::Asio::DeadlineTimer>(*ioContext);
    banExpiryCheckTimer->expires_from_now(boost::posix_time::seconds(banExpiryCheckInterval));
    banExpiryCheckTimer->async_wait([timerRef = std::weak_ptr(banExpiryCheckTimer), banExpiryCheckInterval](boost::system::error_code const& error) mutable
    {
        BanExpiryHandler(std::move(timerRef), banExpiryCheckInterval, error);
    });

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
    std::shared_ptr<Trinity::Asio::DeadlineTimer> serviceStatusWatchTimer;
    if (m_ServiceStatus != -1)
    {
        serviceStatusWatchTimer = std::make_shared<Trinity::Asio::DeadlineTimer>(*ioContext);
        serviceStatusWatchTimer->expires_from_now(boost::posix_time::seconds(1));
        serviceStatusWatchTimer->async_wait([timerRef = std::weak_ptr(serviceStatusWatchTimer), ioContextRef = std::weak_ptr(ioContext)](boost::system::error_code const& error) mutable
        {
            ServiceStatusWatcher(std::move(timerRef), std::move(ioContextRef), error);
        });
    }
#endif

    // Start the io service worker loop
    ioContext->run();

    banExpiryCheckTimer->cancel();
    dbPingTimer->cancel();

    TC_LOG_INFO("server.bnetserver", "Halting process...");

    signals.cancel();

    return 0;
}

/// Initialize connection to the database
bool StartDB()
{
    MySQL::Library_Init();

    // Load databases
    DatabaseLoader loader("server.bnetserver", DatabaseLoader::DATABASE_NONE);
    loader
        .AddDatabase(LoginDatabase, "Login");

    if (!loader.Load())
        return false;

    TC_LOG_INFO("server.bnetserver", "Started auth database connection pool.");
    sLog->SetRealmId(0); // Enables DB appenders when realm is set.
    return true;
}

/// Close the connection to the database
void StopDB()
{
    LoginDatabase.Close();
    MySQL::Library_End();
}

void SignalHandler(std::weak_ptr<Trinity::Asio::IoContext> ioContextRef, boost::system::error_code const& error, int /*signalNumber*/)
{
    if (!error)
        if (std::shared_ptr<Trinity::Asio::IoContext> ioContext = ioContextRef.lock())
            ioContext->stop();
}

void KeepDatabaseAliveHandler(std::weak_ptr<Trinity::Asio::DeadlineTimer> dbPingTimerRef, int32 dbPingInterval, boost::system::error_code const& error)
{
    if (!error)
    {
        if (std::shared_ptr<Trinity::Asio::DeadlineTimer> dbPingTimer = dbPingTimerRef.lock())
        {
            TC_LOG_INFO("server.bnetserver", "Ping MySQL to keep connection alive");
            LoginDatabase.KeepAlive();

            dbPingTimer->expires_from_now(boost::posix_time::minutes(dbPingInterval));
            dbPingTimer->async_wait([timerRef = std::move(dbPingTimerRef), dbPingInterval](boost::system::error_code const& error) mutable
            {
                KeepDatabaseAliveHandler(std::move(timerRef), dbPingInterval, error);
            });
        }
    }
}

void BanExpiryHandler(std::weak_ptr<Trinity::Asio::DeadlineTimer> banExpiryCheckTimerRef, int32 banExpiryCheckInterval, boost::system::error_code const& error)
{
    if (!error)
    {
        if (std::shared_ptr<Trinity::Asio::DeadlineTimer> banExpiryCheckTimer = banExpiryCheckTimerRef.lock())
        {
            LoginDatabase.Execute(LoginDatabase.GetPreparedStatement(LOGIN_DEL_EXPIRED_IP_BANS));
            LoginDatabase.Execute(LoginDatabase.GetPreparedStatement(LOGIN_UPD_EXPIRED_ACCOUNT_BANS));
            LoginDatabase.Execute(LoginDatabase.GetPreparedStatement(LOGIN_DEL_BNET_EXPIRED_ACCOUNT_BANNED));

            banExpiryCheckTimer->expires_from_now(boost::posix_time::seconds(banExpiryCheckInterval));
            banExpiryCheckTimer->async_wait([timerRef = std::move(banExpiryCheckTimerRef), banExpiryCheckInterval](boost::system::error_code const& error) mutable
            {
                BanExpiryHandler(std::move(timerRef), banExpiryCheckInterval, error);
            });
        }
    }
}

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
void ServiceStatusWatcher(std::weak_ptr<Trinity::Asio::DeadlineTimer> serviceStatusWatchTimerRef, std::weak_ptr<Trinity::Asio::IoContext> ioContextRef, boost::system::error_code const& error)
{
    if (!error)
    {
        if (std::shared_ptr<Trinity::Asio::IoContext> ioContext = ioContextRef.lock())
        {
            if (m_ServiceStatus == 0)
            {
                ioContext->stop();
            }
            else if (std::shared_ptr<Trinity::Asio::DeadlineTimer> serviceStatusWatchTimer = serviceStatusWatchTimerRef.lock())
            {
                serviceStatusWatchTimer->expires_from_now(boost::posix_time::seconds(1));
                serviceStatusWatchTimer->async_wait([timerRef = std::move(serviceStatusWatchTimerRef), ioContextRef = std::move(ioContextRef)](boost::system::error_code const& error) mutable
                {
                    ServiceStatusWatcher(std::move(timerRef), std::move(ioContextRef), error);
                });
            }
        }
    }
}
#endif

variables_map GetConsoleArguments(int argc, char** argv, fs::path& configFile, fs::path& configDir, [[maybe_unused]] std::string& winServiceAction)
{
    options_description all("Allowed options");
    all.add_options()
        ("help,h", "print usage message")
        ("version,v", "print version build info")
        ("config,c", value<fs::path>(&configFile)->default_value(fs::absolute(_TRINITY_BNET_CONFIG)),
                     "use <arg> as configuration file")
        ("config-dir,cd", value<fs::path>(&configDir)->default_value(fs::absolute(_TRINITY_BNET_CONFIG_DIR)),
            "use <arg> as directory with additional config files")
        ("update-databases-only,u", "updates databases only")
        ;
#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
    options_description win("Windows platform specific options");
    win.add_options()
        ("service,s", value<std::string>(&winServiceAction)->default_value(""), "Windows service options: [install | uninstall]")
        ;

    all.add(win);
#endif
    variables_map variablesMap;
    try
    {
        store(command_line_parser(argc, argv).options(all).allow_unregistered().run(), variablesMap);
        notify(variablesMap);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }

    if (variablesMap.count("help"))
    {
        std::cout << all << "\n";
    }
    else if (variablesMap.count("version"))
    {
        std::cout << GitRevision::GetFullVersion() << "\n";
    }

    return variablesMap;
}

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
#include "WheatyExceptionReport.h"
// must be at end of file because of init_seg pragma
INIT_CRASH_HANDLER();
#endif
