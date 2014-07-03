/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include <openssl/opensslv.h>
#include <openssl/crypto.h>
#include <iostream>
#include <cstdlib>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "Common.h"
#include "Database/DatabaseEnv.h"
#include "Configuration/Config.h"
#include "Log.h"
#include "SystemConfig.h"
#include "Util.h"
#include "RealmList.h"
#include "AsyncAcceptor.h"
#include "AuthSession.h"


#ifdef __linux__
#include <sched.h>
#include <sys/resource.h>
#define PROCESS_HIGH_PRIORITY -15 // [-20, 19], default is 0
#endif

#ifndef _TRINITY_REALM_CONFIG
# define _TRINITY_REALM_CONFIG  "authserver.conf"
#endif

bool StartDB();
void StopDB();
void SetProcessPriority();

boost::asio::io_service _ioService;
boost::asio::deadline_timer _dbPingTimer(_ioService);
uint32 _dbPingInterval;

LoginDatabaseWorkerPool LoginDatabase;                      // Accessor to the authserver database

using boost::asio::ip::tcp;


void SignalHandler(const boost::system::error_code& error, int signalNumber)
{
    if (!error)
    {
        switch (signalNumber)
        {
        case SIGINT:
        case SIGTERM:
            _ioService.stop();
            break;
        }
    }
}

void KeepDatabaseAliveHandler(const boost::system::error_code& error)
{
    if (!error)
    {
        TC_LOG_INFO("server.authserver", "Ping MySQL to keep connection alive");
        LoginDatabase.KeepAlive();

        _dbPingTimer.expires_from_now(boost::posix_time::minutes(_dbPingInterval));
    }
}

/// Print out the usage string for this program on the console.
void usage(const char* prog)
{
    TC_LOG_INFO("server.authserver", "Usage: \n %s [<options>]\n"
        "    -c config_file           use config_file as configuration file\n\r",
        prog);
}

/// Launch the auth server
int main(int argc, char** argv)
{
    // Command line parsing to get the configuration file name
    char const* configFile = _TRINITY_REALM_CONFIG;
    int count = 1;
    while (count < argc)
    {
        if (strcmp(argv[count], "-c") == 0)
        {
            if (++count >= argc)
            {
                printf("Runtime-Error: -c option requires an input argument\n");
                usage(argv[0]);
                return 1;
            }
            else
                configFile = argv[count];
        }
        ++count;
    }

    if (!sConfigMgr->LoadInitial(configFile))
    {
        printf("Invalid or missing configuration file : %s\n", configFile);
        printf("Verify that the file exists and has \'[authserver]\' written in the top of the file!\n");
        return 1;
    }

    TC_LOG_INFO("server.authserver", "%s (authserver)", _FULLVERSION);
    TC_LOG_INFO("server.authserver", "<Ctrl-C> to stop.\n");
    TC_LOG_INFO("server.authserver", "Using configuration file %s.", configFile);

    TC_LOG_INFO("server.authserver", "%s (Library: %s)", OPENSSL_VERSION_TEXT, SSLeay_version(SSLEAY_VERSION));

    // authserver PID file creation
    std::string pidFile = sConfigMgr->GetStringDefault("PidFile", "");
    if (!pidFile.empty())
    {
        if (uint32 pid = CreatePIDFile(pidFile))
            TC_LOG_INFO("server.authserver", "Daemon PID: %u\n", pid);
        else
        {
            TC_LOG_ERROR("server.authserver", "Cannot create PID file %s.\n", pidFile.c_str());
            return 1;
        }
    }

    // Initialize the database connection
    if (!StartDB())
        return 1;

    // Get the list of realms for the server
    sRealmList.Initialize(sConfigMgr->GetIntDefault("RealmsStateUpdateDelay", 20));

    if (sRealmList.size() == 0)
    {
        TC_LOG_ERROR("server.authserver", "No valid realms specified.");
        return 1;
    }

    // Launch the listening network socket

    int32 port = sConfigMgr->GetIntDefault("RealmServerPort", 3724);
    if (port < 0 || port > 0xFFFF)
    {
        TC_LOG_ERROR("server.authserver", "Specified port out of allowed range (1-65535)");
        return 1;
    }

    std::string bindIp = sConfigMgr->GetStringDefault("BindIP", "0.0.0.0");

    AsyncAcceptor<AuthSession> authServer(_ioService, bindIp, port);

    // Set signal handlers
    boost::asio::signal_set signals(_ioService, SIGINT, SIGTERM);
    signals.async_wait(SignalHandler);

    SetProcessPriority();

    _dbPingInterval = sConfigMgr->GetIntDefault("MaxPingTime", 30);

    _dbPingTimer.expires_from_now(boost::posix_time::seconds(_dbPingInterval));
    _dbPingTimer.async_wait(KeepDatabaseAliveHandler);

    // Start the io service
    _ioService.run();

    // Close the Database Pool and library
    StopDB();

    TC_LOG_INFO("server.authserver", "Halting process...");
    return 0;
}


/// Initialize connection to the database
bool StartDB()
{
    MySQL::Library_Init();

    std::string dbstring = sConfigMgr->GetStringDefault("LoginDatabaseInfo", "");
    if (dbstring.empty())
    {
        TC_LOG_ERROR("server.authserver", "Database not specified");
        return false;
    }

    int32 worker_threads = sConfigMgr->GetIntDefault("LoginDatabase.WorkerThreads", 1);
    if (worker_threads < 1 || worker_threads > 32)
    {
        TC_LOG_ERROR("server.authserver", "Improper value specified for LoginDatabase.WorkerThreads, defaulting to 1.");
        worker_threads = 1;
    }

    int32 synch_threads = sConfigMgr->GetIntDefault("LoginDatabase.SynchThreads", 1);
    if (synch_threads < 1 || synch_threads > 32)
    {
        TC_LOG_ERROR("server.authserver", "Improper value specified for LoginDatabase.SynchThreads, defaulting to 1.");
        synch_threads = 1;
    }

    // NOTE: While authserver is singlethreaded you should keep synch_threads == 1. Increasing it is just silly since only 1 will be used ever.
    if (!LoginDatabase.Open(dbstring, uint8(worker_threads), uint8(synch_threads)))
    {
        TC_LOG_ERROR("server.authserver", "Cannot connect to database");
        return false;
    }

    TC_LOG_INFO("server.authserver", "Started auth database connection pool.");
    sLog->SetRealmId(0); // Enables DB appenders when realm is set.
    return true;
}

/// Close the connection to the database
void StopDB()
{
    LoginDatabase.Close();
    MySQL::Library_End();
}

void SetProcessPriority()
{
#if defined(_WIN32) || defined(__linux__)

    ///- Handle affinity for multiple processors and process priority
    uint32 affinity = sConfigMgr->GetIntDefault("UseProcessors", 0);
    bool highPriority = sConfigMgr->GetBoolDefault("ProcessPriority", false);

#ifdef _WIN32 // Windows

    HANDLE hProcess = GetCurrentProcess();
    if (affinity > 0)
    {
        ULONG_PTR appAff;
        ULONG_PTR sysAff;

        if (GetProcessAffinityMask(hProcess, &appAff, &sysAff))
        {
            // remove non accessible processors
            ULONG_PTR currentAffinity = affinity & appAff;

            if (!currentAffinity)
                TC_LOG_ERROR("server.authserver", "Processors marked in UseProcessors bitmask (hex) %x are not accessible for the authserver. Accessible processors bitmask (hex): %x", affinity, appAff);
            else if (SetProcessAffinityMask(hProcess, currentAffinity))
                TC_LOG_INFO("server.authserver", "Using processors (bitmask, hex): %x", currentAffinity);
            else
                TC_LOG_ERROR("server.authserver", "Can't set used processors (hex): %x", currentAffinity);
        }
    }

    if (highPriority)
    {
        if (SetPriorityClass(hProcess, HIGH_PRIORITY_CLASS))
            TC_LOG_INFO("server.authserver", "authserver process priority class set to HIGH");
        else
            TC_LOG_ERROR("server.authserver", "Can't set authserver process priority class.");
    }

#else // Linux

    if (affinity > 0)
    {
        cpu_set_t mask;
        CPU_ZERO(&mask);

        for (unsigned int i = 0; i < sizeof(affinity) * 8; ++i)
            if (affinity & (1 << i))
                CPU_SET(i, &mask);

        if (sched_setaffinity(0, sizeof(mask), &mask))
            TC_LOG_ERROR("server.authserver", "Can't set used processors (hex): %x, error: %s", affinity, strerror(errno));
        else
        {
            CPU_ZERO(&mask);
            sched_getaffinity(0, sizeof(mask), &mask);
            TC_LOG_INFO("server.authserver", "Using processors (bitmask, hex): %lx", *(__cpu_mask*)(&mask));
        }
    }

    if (highPriority)
    {
        if (setpriority(PRIO_PROCESS, 0, PROCESS_HIGH_PRIORITY))
            TC_LOG_ERROR("server.authserver", "Can't set authserver process priority class, error: %s", strerror(errno));
        else
            TC_LOG_INFO("server.authserver", "authserver process priority class set to %i", getpriority(PRIO_PROCESS, 0));
    }

#endif
#endif
}
