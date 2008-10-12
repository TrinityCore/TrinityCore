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
#include "MCS_OnlinePlayers.h"

#include "MapManager.h"
#include "ObjectMgr.h"
#include "Config/ConfigEnv.h"

mcs_OnlinePlayers::mcs_OnlinePlayers() { CD = NULL; }

mcs_OnlinePlayers::mcs_OnlinePlayers(_CDATA *_CD)
{
    //create a new instance of data struct and copy its data
    CD = new _CDATA();
    CD->CMD = _CD->CMD;
    CD->FROM = _CD->FROM;
    CD->PARAMS = _CD->PARAMS;
    CD->PCOUNT = _CD->PCOUNT;
    CD->USER = _CD->USER;
	CD->TYPE = _CD->TYPE;
}

mcs_OnlinePlayers::~mcs_OnlinePlayers()
{
    if(CD)
        delete CD;
}

void mcs_OnlinePlayers::run()
{
    int OnlineCount = 0;
    std::string IRCOut = "";
    HashMapHolder<Player>::MapType& m = ObjectAccessor::Instance().GetPlayers();
    for(HashMapHolder<Player>::MapType::iterator itr = m.begin(); itr != m.end(); ++itr)
    {
        if (itr->second && itr->second->GetSession()->GetPlayer() && itr->second->GetSession()->GetPlayer()->IsInWorld())
        {
            OnlineCount++;
            Player *plr = itr->second->GetSession()->GetPlayer();
            std::string ChatTag = " ";
            switch(plr->GetSession()->GetSecurity())
            {
                  case 0: ChatTag.append("");break;
                  case 1: ChatTag.append("\0037"+sIRC.ojGM1);break;
                  case 2: ChatTag.append("\0037"+sIRC.ojGM2);break;
                  case 3: ChatTag.append("\0037"+sIRC.ojGM3);break;
                  case 4: ChatTag.append("\0037"+sIRC.ojGM4);break;
                  case 5: ChatTag.append("\0037"+sIRC.ojGM5);break;
            }
            if(plr->isAFK())
                ChatTag.append("\002\0037<AFK>\003\002");
            else if(plr->isDND())
                ChatTag.append("\002\0037<DND>\003\002");
            switch (plr->GetTeam())
            {
                case 67:ChatTag.append("\0034");break;      //horde
                case 469:ChatTag.append("\00312");break;    //alliance
            }

            IRCOut.append(IRCCmd::MakeMsg("%s\002%s\003\017\002(%d)\002\017", ChatTag.c_str(), plr->GetName(), plr->getLevel()));

            // after XX players have been added to the string
            // output to irc and reset for the next XX
            if(OnlineCount % sIRC.onlrslt == 0)
            {
                sIRC.Send_IRC_Channel(IRCCmd::ChanOrPM(CD), IRCCmd::MakeMsg("\002 %s", IRCOut.c_str()), true, CD->TYPE.c_str());
                IRCOut = "";
                ZThread::Thread::sleep(1000);
            }
        }
    }
    // Remainder in IRCOUT && Total plyersonline
    sIRC.Send_IRC_Channel(IRCCmd::ChanOrPM(CD), IRCCmd::MakeMsg("\002Players Online(%d):\017 %s", OnlineCount, IRCOut.c_str()), true, CD->TYPE);

    sIRC.Script_Lock[MCS_Players_Online] = false;
}
