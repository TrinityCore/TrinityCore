/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "SessionManager.h"
#include "AppenderDB.h"
#include "ProcessPriority.h"
#include "RealmList.h"
#include "GitRevision.h"
#include "Banner.h"
#include "SslContext.h"
#include "DatabaseLoader.h"
#include "LoginRESTService.h"
#include <iostream>
#include <boost/program_options.hpp>
#include <boost/filesystem/path.hpp>
#include <google/protobuf/stubs/common.h>

using boost::asio::ip::tcp;
using namespace boost::program_options;
namespace fs = boost::filesystem;

#ifndef _TRINITY_BNET_CONFIG
# define _TRINITY_BNET_CONFIG  "bnetserver.conf"
#endif

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
#include "ServiceWin32.h"
char serviceName[] = "bnetserver";
char serviceLongName[] = "TrinityCore bnet service";
char serviceDescription[] = "TrinityCore Battle.net emulator authentication service";
/*
* -1 - not in service mode
*  0 - stopped
*  1 - running
*  2 - paused
*/
int m_ServiceStatus = -1;

static boost::asio::deadline_timer* _serviceStatusWatchTimer;
void ServiceStatusWatcher(boost::system::error_code const& error);
#endif

bool StartDB();
void StopDB();
void SignalHandler(boost::system::error_code const& error, int signalNumber);
void KeepDatabaseAliveHandler(boost::system::error_code const& error);
void BanExpiryHandler(boost::system::error_code const& error);
variables_map GetConsoleArguments(int argc, char** argv, fs::path& configFile, std::string& configService);

static boost::asio::io_service* _ioService;
static boost::asio::deadline_timer* _dbPingTimer;
static uint32 _dbPingInterval;
static boost::asio::deadline_timer* _banExpiryCheckTimer;
static uint32 _banExpiryCheckInterval;

int main(int argc, char** argv)
{
    signal(SIGABRT, &Trinity::AbortHandler);

    auto configFile = fs::absolute(_TRINITY_BNET_CONFIG);
    std::string configService;
    auto vm = GetConsoleArguments(argc, argv, configFile, configService);
    // exit if help or version is enabled
    if (vm.count("help") || vm.count("version"))
        return 0;

    GOOGLE_PROTOBUF_VERIFY_VERSION;

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
    if (configService.compare("install") == 0)
        return WinServiceInstall() ? 0 : 1;
    else if (configService.compare("uninstall") == 0)
        return WinServiceUninstall() ? 0 : 1;
    else if (configService.compare("run") == 0)
        return WinServiceRun() ? 0 : 1;
#endif

    std::string configError;
    if (!sConfigMgr->LoadInitial(configFile.generic_string(),
                                 std::vector<std::string>(argv, argv + argc),
                                 configError))
    {
        printf("Error in config file: %s\n", configError.c_str());
        return 1;
    }

    sLog->RegisterAppender<AppenderDB>();
    sLog->Initialize(nullptr);

    Trinity::Banner::Show("bnetserver",
        [](char const* text)
        {
            TC_LOG_INFO("server.bnetserver", "%s", text);
        },
            []()
        {
            TC_LOG_INFO("server.bnetserver", "Using configuration file %s.", sConfigMgr->GetFilename().c_str());
            TC_LOG_INFO("server.bnetserver", "Using SSL version: %s (library: %s)", OPENSSL_VERSION_TEXT, SSLeay_version(SSLEAY_VERSION));
            TC_LOG_INFO("server.bnetserver", "Using Boost version: %i.%i.%i", BOOST_VERSION / 100000, BOOST_VERSION / 100 % 1000, BOOST_VERSION % 100);
        }
    );

    // Seed the OpenSSL's PRNG here.
    // That way it won't auto-seed when calling BigNumber::SetRand and slow down the first world login
    BigNumber seed;
    seed.SetRand(16 * 8);

    // bnetserver PID file creation
    std::string pidFile = sConfigMgr->GetStringDefault("PidFile", "");
    if (!pidFile.empty())
    {
        if (uint32 pid = CreatePIDFile(pidFile))
            TC_LOG_INFO("server.bnetserver", "Daemon PID: %u\n", pid);
        else
        {
            TC_LOG_ERROR("server.bnetserver", "Cannot create PID file %s.\n", pidFile.c_str());
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

    _ioService = new boost::asio::io_service();

    // Start the listening port (acceptor) for auth connections
    int32 bnport = sConfigMgr->GetIntDefault("BattlenetPort", 1119);
    if (bnport < 0 || bnport > 0xFFFF)
    {
        TC_LOG_ERROR("server.bnetserver", "Specified battle.net port (%d) out of allowed range (1-65535)", bnport);
        StopDB();
        delete _ioService;
        return 1;
    }

    if (!sLoginService.Start(*_ioService))
    {
        StopDB();
        delete _ioService;
        TC_LOG_ERROR("server.bnetserver", "Failed to initialize login service");
        return 1;
    }

    // Get the list of realms for the server
    sRealmList->Initialize(*_ioService, sConfigMgr->GetIntDefault("RealmsStateUpdateDelay", 10));

    std::string bindIp = sConfigMgr->GetStringDefault("BindIP", "0.0.0.0");

    sSessionMgr.StartNetwork(*_ioService, bindIp, bnport);

    // Set signal handlers
    boost::asio::signal_set signals(*_ioService, SIGINT, SIGTERM);
#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
    signals.add(SIGBREAK);
#endif
    signals.async_wait(SignalHandler);

    // Set process priority according to configuration settings
    SetProcessPriority("server.bnetserver");

    // Enabled a timed callback for handling the database keep alive ping
    _dbPingInterval = sConfigMgr->GetIntDefault("MaxPingTime", 30);
    _dbPingTimer = new boost::asio::deadline_timer(*_ioService);
    _dbPingTimer->expires_from_now(boost::posix_time::minutes(_dbPingInterval));
    _dbPingTimer->async_wait(KeepDatabaseAliveHandler);

    _banExpiryCheckInterval = sConfigMgr->GetIntDefault("BanExpiryCheckInterval", 60);
    _banExpiryCheckTimer = new boost::asio::deadline_timer(*_ioService);
    _banExpiryCheckTimer->expires_from_now(boost::posix_time::seconds(_banExpiryCheckInterval));
    _banExpiryCheckTimer->async_wait(BanExpiryHandler);

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
    if (m_ServiceStatus != -1)
    {
        _serviceStatusWatchTimer = new boost::asio::deadline_timer(*_ioService);
        _serviceStatusWatchTimer->expires_from_now(boost::posix_time::seconds(1));
        _serviceStatusWatchTimer->async_wait(ServiceStatusWatcher);
    }
#endif

    // Start the io service worker loop
    _ioService->run();

    _banExpiryCheckTimer->cancel();
    _dbPingTimer->cancel();

    sLoginService.Stop();

    sSessionMgr.StopNetwork();

    sRealmList->Close();

    // Close the Database Pool and library
    StopDB();

    TC_LOG_INFO("server.bnetserver", "Halting process...");

    signals.cancel();

    delete _banExpiryCheckTimer;
    delete _dbPingTimer;
    delete _ioService;
    google::protobuf::ShutdownProtobufLibrary();
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

void SignalHandler(boost::system::error_code const& error, int /*signalNumber*/)
{
    if (!error)
        _ioService->stop();
}

void KeepDatabaseAliveHandler(boost::system::error_code const& error)
{
    if (!error)
    {
        TC_LOG_INFO("server.bnetserver", "Ping MySQL to keep connection alive");
        LoginDatabase.KeepAlive();

        _dbPingTimer->expires_from_now(boost::posix_time::minutes(_dbPingInterval));
        _dbPingTimer->async_wait(KeepDatabaseAliveHandler);
    }
}

void BanExpiryHandler(boost::system::error_code const& error)
{
    if (!error)
    {
        LoginDatabase.Execute(LoginDatabase.GetPreparedStatement(LOGIN_DEL_EXPIRED_IP_BANS));
        LoginDatabase.Execute(LoginDatabase.GetPreparedStatement(LOGIN_UPD_EXPIRED_ACCOUNT_BANS));
        LoginDatabase.Execute(LoginDatabase.GetPreparedStatement(LOGIN_DEL_BNET_EXPIRED_ACCOUNT_BANNED));

        _banExpiryCheckTimer->expires_from_now(boost::posix_time::seconds(_banExpiryCheckInterval));
        _banExpiryCheckTimer->async_wait(BanExpiryHandler);
    }
}

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
void ServiceStatusWatcher(boost::system::error_code const& error)
{
    if (!error)
    {
        if (m_ServiceStatus == 0)
        {
            _ioService->stop();
            delete _serviceStatusWatchTimer;
        }
        else
        {
            _serviceStatusWatchTimer->expires_from_now(boost::posix_time::seconds(1));
            _serviceStatusWatchTimer->async_wait(ServiceStatusWatcher);
        }
    }
}
#endif

variables_map GetConsoleArguments(int argc, char** argv, fs::path& configFile, std::string& configService)
{
    (void)configService;

    options_description all("Allowed options");
    all.add_options()
        ("help,h", "print usage message")
        ("version,v", "print version build info")
        ("config,c", value<fs::path>(&configFile)->default_value(fs::absolute(_TRINITY_BNET_CONFIG)),
                     "use <arg> as configuration file")
        ;
#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
    options_description win("Windows platform specific options");
    win.add_options()
        ("service,s", value<std::string>(&configService)->default_value(""), "Windows service options: [install | uninstall]")
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
