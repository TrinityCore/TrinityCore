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

/*#ifdef WIN32
    #define Delay(x) Sleep(x)
#else
    #define Delay(x) sleep(x / 1000)
#endif*/
// IRCClient Constructor
IRCClient::IRCClient()
{
//    for (int i = 0;i < 5;i++)
//        sIRC->Script_Lock[i] = false;
}
// IRCClient Destructor
IRCClient::~IRCClient(){}

void TrinityChatThread()
{
    //call irc bot
    IRCClient* a = nullptr;
    // run the bot within a thread
    a->run();
}

// ZThread Entry This function is called when the thread is created in Master.cpp (trinitycore)
void IRCClient::run()
{
//    iLog.WriteLog(" %s : ****** TrinityCore With TriniChat Has Been Started ******", iLog.GetLogDateTimeStr().c_str());

    // before we begin we wait a few
    // mangos is still starting up.
    //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    boost::this_thread::sleep(boost::posix_time::milliseconds(500));
    std::stringstream ss(sIRC->_bot_names);
    string temp = "";
    uint8 counter = 0;
    for(uint8 i=0;i<sIRC->_bot_names.length();i++)
    {
        if(sIRC->_bot_names[i] == ',')
        {
            sIRC->_ignore_bots[counter] = temp;
            temp = "";
            counter++;
        }
        else
        {
            temp += sIRC->_bot_names[i];
        }
    }
    // check for hanging name
    sIRC->_ignore_bots[counter] = temp;
    TC_LOG_INFO("server.loading", ">> TrinityChat Ignore Bots set.");
    TC_LOG_ERROR("misc", "\n%s\n%s\n%s\n%s",
        "***************************************",
        "**   TriniChat2 Threaded IRC Client   **",
        "**     With Enhanced GM Control.     **",
        "***************************************");
    TC_LOG_ERROR("misc", "****** TriniChat: %s ********", sIRC->_Mver.c_str());
    int cCount = 1;
    // Clean Up MySQL Tables
    TC_LOG_ERROR("misc", "*** TriniChat: Cleaning Up Inchan Table*");
    WorldDatabase.PExecute("DELETE FROM `irc_inchan`");
    sIRC->_Max_Script_Inst = 0;
    // Create a loop to keep the thread running untill active is set to false
    while (sIRC->Active && !World::IsStopped())
    {
        // Initialize socket library
        if (this->InitSock())
        {
            // Connect To The IRC Server
            TC_LOG_ERROR("misc", "*** TriniChat: Connecting to %s Try # %d ******", sIRC->_Host.c_str(), cCount);
           if (this->Connect(sIRC->_Host.c_str(), sIRC->_Port))
           {
               // On connection success reset the connection counter
               cCount = 0;
               TC_LOG_ERROR("misc", "*** TriniChat: Connected And Logging In*");
                // Login to the IRC server
                if (this->Login(sIRC->_Nick, sIRC->_User, sIRC->_Pass))
                {
                    TC_LOG_ERROR("misc", "*** TriniChat: Logged In And Running!! *");
                    // While we are connected to the irc server keep listening for data on the socket
                    while (sIRC->Connected && !World::IsStopped()){ sIRC->SockRecv(); }
                }
                TC_LOG_ERROR("misc", "*** TriniChat: Connection To IRC Server Lost! ***");
            }
            // When an error occures or connection lost cleanup
            Disconnect();
            // Increase the connection counter
            cCount++;
            // if MAX_CONNECT_ATTEMPT is reached stop trying
            if (sIRC->_MCA != 0 && cCount == sIRC->_MCA)
                sIRC->Active = false;
            // If we need to reattempt a connection wait WAIT_CONNECT_TIME milli seconds before we try again
            if (sIRC->Active)
            {
                boost::this_thread::sleep_for(boost::posix_time::milliseconds(_wct));
            }
        }
        else
        {
            // Socket could not initialize cancel
            sIRC->Active = false;
            TC_LOG_ERROR("misc", "** TriniChat: Could not initialize socket");
        }
    }
    while (!World::IsStopped()){};
}

std::string IRCClient::GetChatLine(int nItem)
{
    return sIRC->ILINES[nItem];
}
