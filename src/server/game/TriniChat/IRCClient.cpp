/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "IRCClient.h"
#include "World.h"
#include "ObjectMgr.h"
#include "MapManager.h"

#include "framework/Policies/SingletonImp.h"
INSTANTIATE_SINGLETON_1(IRCClient);

#ifdef WIN32
    #define Delay(x) Sleep(x)
#else
    #define Delay(x) sleep(x / 1000)
#endif
// IRCClient Constructor
IRCClient::IRCClient()
{
    for (int i = 0;i > 5;i++)
        sIRC.Script_Lock[i] = false;
}
// IRCClient Destructor
IRCClient::~IRCClient(){}

// ZThread Entry This function is called when the thread is created in Master.cpp (trinitycore)
void IRCClient::run()
{
    sIRC.iLog.WriteLog(" %s : ****** Trinity Core With TriniChat Has Been Started ******", sIRC.iLog.GetLogDateTimeStr().c_str());

    // before we begin we wait a few 
    // mangos is still starting up.
    ACE_Based::Thread::Sleep(500);
    sLog->outError(LOG_FILTER_GENERAL, "\n%s\n%s\n%s\n%s",
        "***************************************",
        "**   TriniChat2 Threaded IRC Client   **",
        "**     With Enhanced GM Control.     **",
        "***************************************");
    sLog->outError(LOG_FILTER_GENERAL, "****** TriniChat: %s ********", sIRC._Mver.c_str());
    int cCount = 1;
    // Clean Up MySQL Tables
    sLog->outError(LOG_FILTER_GENERAL, "*** TriniChat: Cleaning Up Inchan Table*");
    WorldDatabase.PExecute("DELETE FROM `irc_inchan`");
    sIRC._Max_Script_Inst = 0;
    // Create a loop to keep the thread running untill active is set to false
    while (sIRC.Active && !World::IsStopped())
    {
        // Initialize socket library
        if (this->InitSock())
        {
            // Connect To The IRC Server
            sLog->outError(LOG_FILTER_GENERAL, "*** TriniChat: Connecting to %s Try # %d ******", sIRC._Host.c_str(), cCount);
           if (this->Connect(sIRC._Host.c_str(), sIRC._Port))
           {
               // On connection success reset the connection counter
               cCount = 0;
               sLog->outError(LOG_FILTER_GENERAL, "*** TriniChat: Connected And Logging In*");
                // Login to the IRC server
                if (this->Login(sIRC._Nick, sIRC._User, sIRC._Pass))
                {
                    sLog->outError(LOG_FILTER_GENERAL, "*** TriniChat: Logged In And Running!! *");
                    // While we are connected to the irc server keep listening for data on the socket
                    while (sIRC.Connected && !World::IsStopped()){ sIRC.SockRecv(); }
                }
                sLog->outError(LOG_FILTER_GENERAL, "*** TriniChat: Connection To IRC Server Lost! ***");
            }
            // When an error occures or connection lost cleanup
            Disconnect();
            // Increase the connection counter
            cCount++;
            // if MAX_CONNECT_ATTEMPT is reached stop trying
            if (sIRC._MCA != 0 && cCount == sIRC._MCA)
                sIRC.Active = false;
            // If we need to reattempt a connection wait WAIT_CONNECT_TIME milli seconds before we try again
            if (sIRC.Active)
                ACE_Based::Thread::Sleep(sIRC._wct);
        }
        else
        {
            // Socket could not initialize cancel
            sIRC.Active = false;
            sLog->outError(LOG_FILTER_GENERAL, "** TriniChat: Could not initialize socket");
        }
    }
    while (!World::IsStopped()){};
}

std::string IRCClient::GetChatLine(int nItem)
{
    return sIRC.ILINES[nItem];
}