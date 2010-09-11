/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/** \file
    \ingroup Trinityd
*/

#include <ace/Sig_Handler.h>

#include "Common.h"
#include "SystemConfig.h"
#include "SignalHandler.h"
#include "World.h"
#include "WorldRunnable.h"
#include "WorldSocket.h"
#include "WorldSocketMgr.h"
#include "Configuration/Config.h"
#include "Database/DatabaseEnv.h"
#include "Database/DatabaseWorkerPool.h"

#include "CliRunnable.h"
#include "Log.h"
#include "Master.h"
#include "RASocket.h"
#include "TCSoap.h"
#include "Timer.h"
#include "Util.h"

#include "TcpSocket.h"
#include "Utility.h"
#include "Parse.h"
#include "Socket.h"
#include "SocketHandler.h"
#include "ListenSocket.h"
#include "BigNumber.h"

#ifdef _WIN32
#include "ServiceWin32.h"
extern int m_ServiceStatus;
#endif

/// Handle cored's termination signals
class CoredSignalHandler : public Trinity::SignalHandler
{
    public:
        virtual void HandleSignal(int SigNum)
        {
            switch (SigNum)
            {
                case SIGINT:
                    World::StopNow(RESTART_EXIT_CODE);
                    break;
                case SIGTERM:
                #ifdef _WIN32
                case SIGBREAK:
                    if (m_ServiceStatus != 1)
                #endif /* _WIN32 */
                    World::StopNow(SHUTDOWN_EXIT_CODE);
                    break;
            }
        }
};

class FreezeDetectorRunnable : public ACE_Based::Runnable
{
public:
    FreezeDetectorRunnable() { _delaytime = 0; }
    uint32 m_loops, m_lastchange;
    uint32 w_loops, w_lastchange;
    uint32 _delaytime;
    void SetDelayTime(uint32 t) { _delaytime = t; }
    void run(void)
    {
        if (!_delaytime)
            return;
        sLog.outString("Starting up anti-freeze thread (%u seconds max stuck time)...",_delaytime/1000);
        m_loops = 0;
        w_loops = 0;
        m_lastchange = 0;
        w_lastchange = 0;
        while (!World::IsStopped())
        {
            ACE_Based::Thread::Sleep(1000);
            uint32 curtime = getMSTime();
            // normal work
            if (w_loops != World::m_worldLoopCounter)
            {
                w_lastchange = curtime;
                w_loops = World::m_worldLoopCounter;
            }
            // possible freeze
            else if (getMSTimeDiff(w_lastchange,curtime) > _delaytime)
            {
                sLog.outError("World Thread hangs, kicking out server!");
                *((uint32 volatile*)NULL) = 0;                       // bang crash
            }
        }
        sLog.outString("Anti-freeze thread exiting without problems.");
    }
};

class RARunnable : public ACE_Based::Runnable
{
public:
    uint32 numLoops, loopCounter;

    RARunnable ()
    {
        uint32 socketSelecttime = sWorld.getIntConfig(CONFIG_SOCKET_SELECTTIME);
        numLoops = (sConfig.GetIntDefault ("MaxPingTime", 30) * (MINUTE * 1000000 / socketSelecttime));
        loopCounter = 0;
    }

    void checkping ()
    {
        // ping if need
        if ((++loopCounter) == numLoops)
        {
            loopCounter = 0;
            sLog.outDetail ("Ping MySQL to keep connection alive");
            LoginDatabase.Query ("SELECT 1 FROM realmlist LIMIT 1");
        }
    }

    void run ()
    {
        SocketHandler h;

        // Launch the RA listener socket
        ListenSocket<RASocket> RAListenSocket (h);
        bool usera = sConfig.GetBoolDefault ("Ra.Enable", false);
        bool needInit = true;

        if (usera)
        {
            port_t raport = sConfig.GetIntDefault ("Ra.Port", 3443);
            std::string stringip = sConfig.GetStringDefault ("Ra.IP", "0.0.0.0");
            ipaddr_t raip;
            if (!Utility::u2ip (stringip, raip))
                sLog.outError ("Trinity RA can not bind to ip %s", stringip.c_str ());
            else if (RAListenSocket.Bind (raip, raport))
                sLog.outError ("Trinity RA can not bind to port %d on %s", raport, stringip.c_str ());
            else
            {
                h.Add (&RAListenSocket);

                sLog.outString ("Starting Remote access listner on port %d on %s", raport, stringip.c_str ());
            }

            if ((LoginDatabase.GetBundleMask() & MYSQL_BUNDLE_RA))
            {
                LoginDatabase.Init_MySQL_Connection();
                needInit = false;
            }
            if (needInit)
                MySQL::Thread_Init();
        }

        // Socket Selet time is in microseconds , not miliseconds!!
        uint32 socketSelecttime = sWorld.getIntConfig(CONFIG_SOCKET_SELECTTIME);

        // if use ra spend time waiting for io, if not use ra ,just sleep
        if (usera)
        {
            while (!World::IsStopped())
            {
                h.Select (0, socketSelecttime);
                checkping ();
            }

            if (!needInit)
                LoginDatabase.End_MySQL_Connection();
            else
                MySQL::Thread_End();
        }
        else
        {
            while (!World::IsStopped())
            {
                ACE_Based::Thread::Sleep(static_cast<unsigned long> (socketSelecttime / 1000));
                // checkping (); -- What?
            }
        }
    }
};

Master::Master()
{
}

Master::~Master()
{
}

/// Main function
int Master::Run()
{
    BigNumber seed1;
    seed1.SetRand(16 * 8);

    sLog.outString( "%s (core-daemon)", _FULLVERSION );
    sLog.outString( "<Ctrl-C> to stop.\n" );

    sLog.outString( " ______                       __");
    sLog.outString( "/\\__  _\\       __          __/\\ \\__");
    sLog.outString( "\\/_/\\ \\/ _ __ /\\_\\    ___ /\\_\\ \\ ,_\\  __  __");
    sLog.outString( "   \\ \\ \\/\\`'__\\/\\ \\ /' _ `\\/\\ \\ \\ \\/ /\\ \\/\\ \\");
    sLog.outString( "    \\ \\ \\ \\ \\/ \\ \\ \\/\\ \\/\\ \\ \\ \\ \\ \\_\\ \\ \\_\\ \\");
    sLog.outString( "     \\ \\_\\ \\_\\  \\ \\_\\ \\_\\ \\_\\ \\_\\ \\__\\\\/`____ \\");
    sLog.outString( "      \\/_/\\/_/   \\/_/\\/_/\\/_/\\/_/\\/__/ `/___/> \\");
    sLog.outString( "                                 C O R E  /\\___/");
    sLog.outString( "http://TrinityCore.org                    \\/__/\n");

    /// worldd PID file creation
    std::string pidfile = sConfig.GetStringDefault("PidFile", "");
    if(!pidfile.empty())
    {
        uint32 pid = CreatePIDFile(pidfile);
        if( !pid )
        {
            sLog.outError( "Cannot create PID file %s.\n", pidfile.c_str() );
            return 1;
        }

        sLog.outString( "Daemon PID: %u\n", pid );
    }

    ///- Start the databases
    if (!_StartDB())
        return 1;

    ///- Initialize the World
    sWorld.SetInitialWorldSettings();


    // Initialise the signal handlers
    CoredSignalHandler SignalINT, SignalTERM;
    #ifdef _WIN32
    CoredSignalHandler SignalBREAK;
    #endif /* _WIN32 */

    // Register realmd's signal handlers
    ACE_Sig_Handler Handler;
    Handler.register_handler(SIGINT, &SignalINT);
    Handler.register_handler(SIGTERM, &SignalTERM);
    #ifdef _WIN32
    Handler.register_handler(SIGBREAK, &SignalBREAK);
    #endif /* _WIN32 */


    ///- Launch WorldRunnable thread
    ACE_Based::Thread world_thread(new WorldRunnable);
    world_thread.setPriority(ACE_Based::Highest);

    // set server online
    LoginDatabase.PExecute("UPDATE realmlist SET color = 0, population = 0 WHERE id = '%d'",realmID);

    ACE_Based::Thread* cliThread = NULL;

#ifdef _WIN32
    if (sConfig.GetBoolDefault("Console.Enable", true) && (m_ServiceStatus == -1)/* need disable console in service mode*/)
#else
    if (sConfig.GetBoolDefault("Console.Enable", true))
#endif
    {
        ///- Launch CliRunnable thread
        cliThread = new ACE_Based::Thread(new CliRunnable);
    }

    ACE_Based::Thread rar_thread(new RARunnable);

    ///- Handle affinity for multiple processors and process priority on Windows
    #ifdef _WIN32
    {
        HANDLE hProcess = GetCurrentProcess();

        uint32 Aff = sConfig.GetIntDefault("UseProcessors", 0);
        if(Aff > 0)
        {
            ULONG_PTR appAff;
            ULONG_PTR sysAff;

            if(GetProcessAffinityMask(hProcess,&appAff,&sysAff))
            {
                ULONG_PTR curAff = Aff & appAff;            // remove non accessible processors

                if(!curAff )
                {
                    sLog.outError("Processors marked in UseProcessors bitmask (hex) %x not accessible for Trinityd. Accessible processors bitmask (hex): %x",Aff,appAff);
                }
                else
                {
                    if(SetProcessAffinityMask(hProcess,curAff))
                        sLog.outString("Using processors (bitmask, hex): %x", curAff);
                    else
                        sLog.outError("Can't set used processors (hex): %x",curAff);
                }
            }
            sLog.outString("");
        }

        bool Prio = sConfig.GetBoolDefault("ProcessPriority", false);

//        if(Prio && (m_ServiceStatus == -1)/* need set to default process priority class in service mode*/)
        if(Prio)
        {
            if(SetPriorityClass(hProcess,HIGH_PRIORITY_CLASS))
                sLog.outString("TrinityCore process priority class set to HIGH");
            else
                sLog.outError("Can't set Trinityd process priority class.");
            sLog.outString("");
        }
    }
    #endif
    //Start soap serving thread
    ACE_Based::Thread* soap_thread = NULL;

    if(sConfig.GetBoolDefault("SOAP.Enabled", false))
    {
        TCSoapRunnable *runnable = new TCSoapRunnable();
        runnable->setListenArguments(sConfig.GetStringDefault("SOAP.IP", "127.0.0.1"), sConfig.GetIntDefault("SOAP.Port", 7878));
        soap_thread = new ACE_Based::Thread(runnable);
    }

    uint32 realCurrTime, realPrevTime;
    realCurrTime = realPrevTime = getMSTime();

    ///- Start up freeze catcher thread
    if(uint32 freeze_delay = sConfig.GetIntDefault("MaxCoreStuckTime", 0))
    {
        FreezeDetectorRunnable *fdr = new FreezeDetectorRunnable();
        fdr->SetDelayTime(freeze_delay*1000);
        ACE_Based::Thread freeze_thread(fdr);
        freeze_thread.setPriority(ACE_Based::Highest);
    }

    ///- Launch the world listener socket
    port_t wsport = sWorld.getIntConfig(CONFIG_PORT_WORLD);
    std::string bind_ip = sConfig.GetStringDefault ("BindIP", "0.0.0.0");

    if (sWorldSocketMgr->StartNetwork (wsport, bind_ip.c_str ()) == -1)
    {
        sLog.outError ("Failed to start network");
        World::StopNow(ERROR_EXIT_CODE);
        // go down and shutdown the server
    }

    sWorldSocketMgr->Wait ();

    if(soap_thread)
    {
          soap_thread->wait();
          soap_thread->destroy();
          delete soap_thread;
    }

    // set server offline
    LoginDatabase.PExecute("UPDATE realmlist SET color = 2 WHERE id = '%d'",realmID);

    // when the main thread closes the singletons get unloaded
    // since worldrunnable uses them, it will crash if unloaded after master
    world_thread.wait();
    rar_thread.wait ();

    ///- Clean database before leaving
    clearOnlineAccounts();

    ///- Wait for delay threads to end
    CharacterDatabase.Close();
    WorldDatabase.Close();
    LoginDatabase.Close();

    sLog.outString( "Halting process..." );

    if (cliThread)
    {
        #ifdef _WIN32

        // this only way to terminate CLI thread exist at Win32 (alt. way exist only in Windows Vista API)
        //_exit(1);
        // send keyboard input to safely unblock the CLI thread
        INPUT_RECORD b[5];
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

        cliThread->wait();

        #else

        cliThread->destroy();

        #endif

        delete cliThread;
    }

    // for some unknown reason, unloading scripts here and not in worldrunnable
    // fixes a memory leak related to detaching threads from the module
    //UnloadScriptingModule();

    // Exit the process with specified return value
    return World::GetExitCode();
}

/// Initialize connection to the databases
bool Master::_StartDB()
{
    sLog.SetLogDB(false);
    std::string dbstring;
    uint8 num_threads;
    int32 mask;

    dbstring = sConfig.GetStringDefault("WorldDatabaseInfo", "");
    if (dbstring.empty())
    {
        sLog.outError("World database not specified in configuration file");
        return false;
    }

    num_threads = sConfig.GetIntDefault("WorldDatabase.WorkerThreads", 1);
    if (num_threads < 1 || num_threads > 32)
    {
        sLog.outError("World database: invalid number of worker threads specified. "
            "Please pick a value between 1 and 32.");
        return false;
    }

    mask = sConfig.GetIntDefault("WorldDatabase.ThreadBundleMask", MYSQL_BUNDLE_ALL);

    ///- Initialise the world database
    if (!WorldDatabase.Open(dbstring, num_threads, MySQLThreadBundle(mask)))
    {
        sLog.outError("Cannot connect to world database %s", dbstring.c_str());
        return false;
    }
    ///- Get character database info from configuration file
    dbstring = sConfig.GetStringDefault("CharacterDatabaseInfo", "");
    if (dbstring.empty())
    {
        sLog.outError("Character database not specified in configuration file");
        return false;
    }

    num_threads = sConfig.GetIntDefault("CharacterDatabase.WorkerThreads", 1);
    if (num_threads < 1 || num_threads > 32)
    {
        sLog.outError("Character database: invalid number of worker threads specified. "
            "Please pick a value between 1 and 32.");
        return false;
    }

    mask = sConfig.GetIntDefault("CharacterDatabase.ThreadBundleMask", MYSQL_BUNDLE_ALL);

    ///- Initialise the Character database
    if (!CharacterDatabase.Open(dbstring, num_threads, MySQLThreadBundle(mask)))
    {
        sLog.outError("Cannot connect to Character database %s", dbstring.c_str());
        return false;
    }

    ///- Get login database info from configuration file
    dbstring = sConfig.GetStringDefault("LoginDatabaseInfo", "");
    if (dbstring.empty())
    {
        sLog.outError("Login database not specified in configuration file");
        return false;
    }

    num_threads = sConfig.GetIntDefault("LoginDatabase.WorkerThreads", 1);
    if (num_threads < 1 || num_threads > 32)
    {
        sLog.outError("Login database: invalid number of worker threads specified. "
            "Please pick a value between 1 and 32.");
        return false;
    }

    mask = sConfig.GetIntDefault("LoginDatabase.ThreadBundleMask", MYSQL_BUNDLE_ALL);

    ///- Initialise the login database
    if (!LoginDatabase.Open(dbstring, num_threads, MySQLThreadBundle(mask)))
    {
        sLog.outError("Cannot connect to login database %s", dbstring.c_str());
        return false;
    }
    ///- Get the realm Id from the configuration file
    realmID = sConfig.GetIntDefault("RealmID", 0);
    if (!realmID)
    {
        sLog.outError("Realm ID not defined in configuration file");
        return false;
    }
    sLog.outString("Realm running as realm ID %d", realmID);

    ///- Initialize the DB logging system
    sLog.SetLogDBLater(sConfig.GetBoolDefault("EnableLogDB", false)); // set var to enable DB logging once startup finished.
    sLog.SetLogDB(false);
    sLog.SetRealmID(realmID);

    ///- Clean the database before starting
    clearOnlineAccounts();

    ///- Insert version info into DB
    WorldDatabase.PExecute("UPDATE version SET core_version = '%s', core_revision = '%s'", _FULLVERSION, _REVISION);

    sWorld.LoadDBVersion();

    sLog.outString("Using World DB: %s", sWorld.GetDBVersion());
    sLog.outString("Using creature EventAI: %s", sWorld.GetCreatureEventAIVersion());
    return true;
}

/// Clear 'online' status for all accounts with characters in this realm
void Master::clearOnlineAccounts()
{
    // Cleanup online status for characters hosted at current realm
    /// \todo Only accounts with characters logged on *this* realm should have online status reset. Move the online column from 'account' to 'realmcharacters'?
    LoginDatabase.PExecute(
        "UPDATE account SET online = 0 WHERE online > 0 "
        "AND id IN (SELECT acctid FROM realmcharacters WHERE realmid = '%d')",realmID);

    CharacterDatabase.Execute("UPDATE characters SET online = 0 WHERE online<>0");

    // Battleground instance ids reset at server restart
    CharacterDatabase.Execute("UPDATE character_battleground_data SET instance_id = 0");
}
