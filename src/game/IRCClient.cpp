/*
 * MangChat By |Death| And Cybrax
 *
 * This Program Is Free Software; You Can Redistribute It And/Or Modify It Under The Terms 
 * Of The GNU General Public License
 * Written and Developed by Cybrax. cybraxvd@gmail.com
 * |Death| <death@hell360.net>, Lice <lice@yeuxverts.net>, Dj_baby & Sanaell, Tase
 * With Help And Support From The MaNGOS Project Community.
 * PLEASE RETAIN THE COPYRIGHT OF THE AUTHORS.
 */
#include "IRCClient.h"
#include "World.h"
#include "ObjectMgr.h"
#include "MapManager.h"

#include "Policies/SingletonImp.h"
INSTANTIATE_SINGLETON_1( IRCClient );

#ifdef WIN32
    #define Delay(x) Sleep(x)
#else
    #define Delay(x) sleep(x / 1000)
#endif
// IRCClient Constructor
IRCClient::IRCClient()
{
    for(int i = 0;i > 5;i++)
        sIRC.Script_Lock[i] = false;
}
// IRCClient Destructor
IRCClient::~IRCClient(){}

// ZThread Entry This function is called when the thread is created in Master.cpp (mangosd)
void IRCClient::run()
{
    sIRC.iLog.WriteLog(" %s : IRC bot started.", sIRC.iLog.GetLogDateTimeStr().c_str());

    // before we begin we wait a few 
    // mangos is still starting up.
    ZThread::Thread::sleep(500);
    int cCount = 0;
    // Clean Up MySQL Tables
    sLog.outString("Cleaning up IRC_Inchan table...");
    WorldDatabase.PExecute("DELETE FROM `IRC_Inchan`");
    sIRC._Max_Script_Inst = 0;
    // Create a loop to keep the thread running untill active is set to false
    while(sIRC.Active && !World::m_stopEvent)
    {
        // Initialize socket library
        if(this->InitSock())
        {
            // Connect To The IRC Server
            sLog.outString("IRC: Connecting to %s Try # %d ******", sIRC._Host.c_str(), cCount);
            if(this->Connect(sIRC._Host.c_str(), sIRC._Port))
            {
                // On connection success reset the connection counter
                cCount = 0;
                sLog.outString("IRC connected and logging in");
                // Login to the IRC server
                if(this->Login(sIRC._Nick, sIRC._User, sIRC._Pass))
                {
                    sLog.outString("IRC logged in and running");
                    // While we are connected to the irc server keep listening for data on the socket
                    while(sIRC.Connected && !World::m_stopEvent){ sIRC.SockRecv(); }
                }
                sLog.outString("Connection to IRC server lost!");
            }
            // When an error occures or connection lost cleanup
            Disconnect();
            // Increase the connection counter
            cCount++;
            // if MAX_CONNECT_ATTEMPT is reached stop trying
            if(sIRC._MCA != 0 && cCount == sIRC._MCA)
                sIRC.Active = false;
            // If we need to reattempt a connection wait WAIT_CONNECT_TIME milli seconds before we try again
            if(sIRC.Active)
                ZThread::Thread::sleep(sIRC._wct);
        }
        else
        {
            // Socket could not initialize cancel
            sIRC.Active = false;
            sLog.outError("IRC: Could not initialize socket");
        }
    }
    // we need to keep the thread alive or mangos will crash
    // when sending chat or join/leave channels.
    // even when we are not connected the functions must still
    // be availlable where chat is sent to so we keep it running
    while(!World::m_stopEvent){};
}
