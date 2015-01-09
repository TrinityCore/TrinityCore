/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

/**
* @file main.cpp
* @brief Authentication Server main program
*
* This file contains the main program for the
* authentication server
*/

#include "ComponentManager.h"
#include "ModuleManager.h"
#include "SessionManager.h"
#include "Common.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "ProcessPriority.h"
#include "RealmList.h"
#include "SystemConfig.h"
#include "Util.h"
#include "ZmqContext.h"
#include <cstdlib>
#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/program_options.hpp>
#include <openssl/opensslv.h>
#include <openssl/crypto.h>

using boost::asio::ip::tcp;
using namespace boost::program_options;

#ifndef _TRINITY_BNET_CONFIG
# define _TRINITY_BNET_CONFIG  "bnetserver.conf"
#endif

bool StartDB();
void StopDB();
void SignalHandler(const boost::system::error_code& error, int signalNumber);
void KeepDatabaseAliveHandler(const boost::system::error_code& error);
variables_map GetConsoleArguments(int argc, char** argv, std::string& configFile);

boost::asio::io_service _ioService;
boost::asio::deadline_timer _dbPingTimer(_ioService);
uint32 _dbPingInterval;
LoginDatabaseWorkerPool LoginDatabase;

int main(int argc, char** argv)
{
    std::string configFile = _TRINITY_BNET_CONFIG;
    auto vm = GetConsoleArguments(argc, argv, configFile);
    // exit if help is enabled
    if (vm.count("help"))
        return 0;

    std::string configError;
    if (!sConfigMgr->LoadInitial(configFile, configError))
    {
        printf("Error in config file: %s\n", configError.c_str());
        return 1;
    }

    TC_LOG_INFO("server.bnetserver", "%s (bnetserver)", _FULLVERSION);
    TC_LOG_INFO("server.bnetserver", "<Ctrl-C> to stop.\n");
    TC_LOG_INFO("server.bnetserver", "Using configuration file %s.", configFile.c_str());
    TC_LOG_INFO("server.bnetserver", "Using SSL version: %s (library: %s)", OPENSSL_VERSION_TEXT, SSLeay_version(SSLEAY_VERSION));
    TC_LOG_INFO("server.bnetserver", "Using Boost version: %i.%i.%i", BOOST_VERSION / 100000, BOOST_VERSION / 100 % 1000, BOOST_VERSION % 100);

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

    int32 worldListenPort = sConfigMgr->GetIntDefault("WorldserverListenPort", 1118);
    if (worldListenPort < 0 || worldListenPort > 0xFFFF)
    {
        TC_LOG_ERROR("server.bnetserver", "Specified worldserver listen port (%d) out of allowed range (1-65535)", worldListenPort);
        return 1;
    }

    // Initialize the database connection
    if (!StartDB())
        return 1;

    sIpcContext->Initialize();

    // Get the list of realms for the server
    sRealmList->Initialize(_ioService, sConfigMgr->GetIntDefault("RealmsStateUpdateDelay", 10), worldListenPort);

    // Start the listening port (acceptor) for auth connections
    int32 bnport = sConfigMgr->GetIntDefault("BattlenetPort", 1119);
    if (bnport < 0 || bnport > 0xFFFF)
    {
        TC_LOG_ERROR("server.bnetserver", "Specified battle.net port (%d) out of allowed range (1-65535)", bnport);
        StopDB();
        return 1;
    }

    std::string bindIp = sConfigMgr->GetStringDefault("BindIP", "0.0.0.0");

    sSessionMgr.StartNetwork(_ioService, bindIp, bnport);

    // Set signal handlers
    boost::asio::signal_set signals(_ioService, SIGINT, SIGTERM);
#if PLATFORM == PLATFORM_WINDOWS
    signals.add(SIGBREAK);
#endif
    signals.async_wait(SignalHandler);

    // Set process priority according to configuration settings
    SetProcessPriority("server.bnetserver");

    // Enabled a timed callback for handling the database keep alive ping
    _dbPingInterval = sConfigMgr->GetIntDefault("MaxPingTime", 30);
    _dbPingTimer.expires_from_now(boost::posix_time::minutes(_dbPingInterval));
    _dbPingTimer.async_wait(KeepDatabaseAliveHandler);

    sComponentMgr->Load();
    sModuleMgr->Load();

    // Start the io service worker loop
    _ioService.run();

    sIpcContext->Close();

    sRealmList->Close();

    // Close the Database Pool and library
    StopDB();

    TC_LOG_INFO("server.bnetserver", "Halting process...");
    return 0;
}


/// Initialize connection to the database
bool StartDB()
{
    MySQL::Library_Init();

    std::string dbstring = sConfigMgr->GetStringDefault("LoginDatabaseInfo", "");
    if (dbstring.empty())
    {
        TC_LOG_ERROR("server.bnetserver", "Database not specified");
        return false;
    }

    int32 worker_threads = sConfigMgr->GetIntDefault("LoginDatabase.WorkerThreads", 1);
    if (worker_threads < 1 || worker_threads > 32)
    {
        TC_LOG_ERROR("server.bnetserver", "Improper value specified for LoginDatabase.WorkerThreads, defaulting to 1.");
        worker_threads = 1;
    }

    int32 synch_threads = sConfigMgr->GetIntDefault("LoginDatabase.SynchThreads", 1);
    if (synch_threads < 1 || synch_threads > 32)
    {
        TC_LOG_ERROR("server.bnetserver", "Improper value specified for LoginDatabase.SynchThreads, defaulting to 1.");
        synch_threads = 1;
    }

    if (!LoginDatabase.Open(dbstring, uint8(worker_threads), uint8(synch_threads)))
    {
        TC_LOG_ERROR("server.bnetserver", "Cannot connect to database");
        return false;
    }

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

void SignalHandler(const boost::system::error_code& error, int /*signalNumber*/)
{
    if (!error)
        _ioService.stop();
}

void KeepDatabaseAliveHandler(const boost::system::error_code& error)
{
    if (!error)
    {
        TC_LOG_INFO("server.bnetserver", "Ping MySQL to keep connection alive");
        LoginDatabase.KeepAlive();

        _dbPingTimer.expires_from_now(boost::posix_time::minutes(_dbPingInterval));
        _dbPingTimer.async_wait(KeepDatabaseAliveHandler);
    }
}

variables_map GetConsoleArguments(int argc, char** argv, std::string& configFile)
{
    options_description all("Allowed options");
    all.add_options()
        ("help,h", "print usage message")
        ("config,c", value<std::string>(&configFile)->default_value(_TRINITY_BNET_CONFIG), "use <arg> as configuration file")
        ;
    variables_map variablesMap;
    try
    {
        store(command_line_parser(argc, argv).options(all).allow_unregistered().run(), variablesMap);
        notify(variablesMap);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    if (variablesMap.count("help")) {
        std::cout << all << "\n";
    }

    return variablesMap;
}
