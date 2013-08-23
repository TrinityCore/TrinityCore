/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

/// @TODO Replace references to authserver with socialserver
/// @TODO Replace printf with our log system
/** @TODO Unhack ZMQTask from _closed
 *       couldn't figure out how to send message to ALL threads instead of first who reads it
 */

#include "CommandPuller.h"
#include "Config.h"
#include "Database/DatabaseEnv.h"
#include "HeartbeatBroker.h"
#include "Log.h"
#include "SystemConfig.h"
#include "SignalHandler.h"
#include <ace/Atomic_Op.h>
#include <ace/Sig_Handler.h>

#ifndef _TRINITY_SOCIAL_CONFIG
#define _TRINITY_SOCIAL_CONFIG "socialserver.conf"
#endif

bool StartDB();
void StopDB();

bool stopEvent;

LoginDatabaseWorkerPool LoginDatabase;                      // Accessor to the authserver database

/// Handle socialserver's termination signals
class SocialServerSignalHandler : public Trinity::SignalHandler
{
public:
    virtual void HandleSignal(int sigNum)
    {
        switch (sigNum)
        {
            case SIGINT:
            case SIGTERM:
                stopEvent = true;
                break;
        }
    }
};

/// Print out the usage string for this program on the console.
void usage(const char* prog)
{
    printf("Usage: \n %s [<options>]\n"
        "    -c config_file           use config_file as configuration file\n\r",
        prog);
}

extern int main(int argc, char** argv)
{
    // Command line parsing to get the configuration file name
    char const* configFile = _TRINITY_SOCIAL_CONFIG;
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
        printf("Verify that the file exists and has \'[socialserver]\' written in the top of the file!\n");
        return 1;
    }

    TC_LOG_INFO(LOG_FILTER_SOCIALSERVER, "%s (socialserver)", _FULLVERSION);
    TC_LOG_INFO(LOG_FILTER_SOCIALSERVER, "<Ctrl-C> to stop.\n");
    TC_LOG_INFO(LOG_FILTER_SOCIALSERVER, "Using configuration file %s.", configFile);

    TC_LOG_DEBUG(LOG_FILTER_SOCIALSERVER, "Max allowed open files is %d", ACE::max_handles());

    // authserver PID file creation
    std::string pidFile = sConfigMgr->GetStringDefault("PidFile", "");
    if (!pidFile.empty())
    {
        if (uint32 pid = CreatePIDFile(pidFile))
            TC_LOG_INFO(LOG_FILTER_SOCIALSERVER, "Daemon PID: %u\n", pid);
        else
        {
            TC_LOG_ERROR(LOG_FILTER_SOCIALSERVER, "Cannot create PID file %s.\n", pidFile.c_str());
            return 1;
        }
    }

    // Initialize the database connection
    if (!StartDB())
        return 1;

    SocialServerSignalHandler sigInt, sigTerm;
    ACE_Sig_Handler handler;
    handler.register_handler(SIGINT, &sigInt);
    handler.register_handler(SIGTERM, &sigTerm);

    ///- Handle affinity for multiple processors and process priority
    uint32 affinity = sConfigMgr->GetIntDefault("UseProcessors", 0);
    bool highPriority = sConfigMgr->GetBoolDefault("ProcessPriority", false);
#ifdef _WIN32 // Windows
    {
        HANDLE hProcess = GetCurrentProcess();

        if (affinity > 0)
        {
            ULONG_PTR appAff;
            ULONG_PTR sysAff;

            if (GetProcessAffinityMask(hProcess, &appAff, &sysAff))
            {
                ULONG_PTR currentAffinity = affinity & appAff;            // remove non accessible processors

                if (!currentAffinity)
                    TC_LOG_ERROR(LOG_FILTER_SOCIALSERVER, "Processors marked in UseProcessors bitmask (hex) %x are not accessible for the authserver. Accessible processors bitmask (hex): %x", affinity, appAff);
                else if (SetProcessAffinityMask(hProcess, currentAffinity))
                    TC_LOG_INFO(LOG_FILTER_SOCIALSERVER, "Using processors (bitmask, hex): %x", currentAffinity);
                else
                    TC_LOG_ERROR(LOG_FILTER_SOCIALSERVER, "Can't set used processors (hex): %x", currentAffinity);
            }
        }

        if (highPriority)
        {
            if (SetPriorityClass(hProcess, HIGH_PRIORITY_CLASS))
                TC_LOG_INFO(LOG_FILTER_SOCIALSERVER, "authserver process priority class set to HIGH");
            else
                TC_LOG_ERROR(LOG_FILTER_SOCIALSERVER, "Can't set authserver process priority class.");
        }
    }
#elif __linux__ // Linux

    if (affinity > 0)
    {
        cpu_set_t mask;
        CPU_ZERO(&mask);

        for (unsigned int i = 0; i < sizeof(affinity) * 8; ++i)
            if (affinity & (1 << i))
                CPU_SET(i, &mask);

        if (sched_setaffinity(0, sizeof(mask), &mask))
            TC_LOG_ERROR(LOG_FILTER_SOCIALSERVER, "Can't set used processors (hex): %x, error: %s", affinity, strerror(errno));
        else
        {
            CPU_ZERO(&mask);
            sched_getaffinity(0, sizeof(mask), &mask);
            TC_LOG_INFO(LOG_FILTER_SOCIALSERVER, "Using processors (bitmask, hex): %x", *(uint32*)(&mask));
        }
    }

    if (highPriority)
    {
        if (setpriority(PRIO_PROCESS, 0, PROCESS_HIGH_PRIORITY))
            TC_LOG_ERROR(LOG_FILTER_SOCIALSERVER, "Can't set authserver process priority class, error: %s", strerror(errno));
        else
            TC_LOG_INFO(LOG_FILTER_SOCIALSERVER, "authserver process priority class set to %i", getpriority(PRIO_PROCESS, 0));
    }
#endif

    zmqpp::context* ctx = new zmqpp::context();
    zmqpp::socket* inproc = new zmqpp::socket(*ctx, zmqpp::socket_type::req);
    inproc->bind("inproc://workers");
    HeartbeatBroker broker;
    CommandPuller puller;
    try
    {
        broker.open(ctx);
        puller.open(ctx);

        // maximum counter for next ping
        uint32 numLoops = (sConfigMgr->GetIntDefault("MaxPingTime", 30) * (MINUTE * 1000000 / 100000));
        uint32 loopCounter = 0;

        // Wait for termination signal
        ACE_Time_Value interval(0, 100000);
        while (!stopEvent)
        {
            ACE_OS::sleep(interval);

            if ((++loopCounter) == numLoops)
            {
                loopCounter = 0;
                TC_LOG_INFO(LOG_FILTER_SOCIALSERVER, "Ping MySQL to keep connection alive");
                LoginDatabase.KeepAlive();
            }
        }
    }
    catch (zmqpp::exception const& ex)
    {
        sLog->outInfo(LOG_FILTER_SOCIALSERVER, "zmqpp::exception %s", ex.what());
        // If exception was thrown in open then it will never run HandleClose by itself
        if (!broker.thr_count())
            broker.close();
        if (!puller.thr_count())
            puller.close();
    }

    inproc->send("kill");
    broker.wait();
    puller.wait();
    inproc->close();

    delete ctx;

    StopDB();

    return 0;
}

/// Initialize connection to the database
bool StartDB()
{
    MySQL::Library_Init();

    std::string dbstring = sConfigMgr->GetStringDefault("LoginDatabaseInfo", "");
    if (dbstring.empty())
    {
        TC_LOG_ERROR(LOG_FILTER_AUTHSERVER, "Database not specified");
        return false;
    }

    int32 worker_threads = sConfigMgr->GetIntDefault("LoginDatabase.WorkerThreads", 1);
    if (worker_threads < 1 || worker_threads > 32)
    {
        TC_LOG_ERROR(LOG_FILTER_AUTHSERVER, "Improper value specified for LoginDatabase.WorkerThreads, defaulting to 1.");
        worker_threads = 1;
    }

    int32 synch_threads = sConfigMgr->GetIntDefault("LoginDatabase.SynchThreads", 1);
    if (synch_threads < 1 || synch_threads > 32)
    {
        TC_LOG_ERROR(LOG_FILTER_AUTHSERVER, "Improper value specified for LoginDatabase.SynchThreads, defaulting to 1.");
        synch_threads = 1;
    }

    // NOTE: While authserver is singlethreaded you should keep synch_threads == 1. Increasing it is just silly since only 1 will be used ever.
    if (!LoginDatabase.Open(dbstring.c_str(), uint8(worker_threads), uint8(synch_threads)))
    {
        TC_LOG_ERROR(LOG_FILTER_AUTHSERVER, "Cannot connect to database");
        return false;
    }

    TC_LOG_INFO(LOG_FILTER_SOCIALSERVER, "Started auth database connection pool.");
    sLog->SetRealmId(0); // Enables DB appenders when realm is set.
    return true;
}

/// Close the connection to the database
void StopDB()
{
    LoginDatabase.Close();
    MySQL::Library_End();
}
