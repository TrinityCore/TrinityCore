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

#include "MCS_OnlinePlayers.h"

#include "MapManager.h"
#include "ObjectMgr.h"
#include "Config.h"

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
    if (CD)
        delete CD;
}

void mcs_OnlinePlayers::run()
{
    int OnlineCount = 0;
    std::string IRCOut = "";
	HashMapHolder<Player>::MapType const& m = sObjectAccessor->GetPlayers();
    for (HashMapHolder<Player>::MapType::const_iterator itr = m.begin(); itr != m.end(); ++itr)
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
		   case 6: ChatTag.append("\0037"+sIRC.ojGM6);break;
		   case 7: ChatTag.append("\0037"+sIRC.ojGM7);break;
		   case 8: ChatTag.append("\0037"+sIRC.ojGM8);break;
            }
            if (plr->isAFK())
                ChatTag.append("\002\0037<AFK>\003\002");
            else if (plr->isDND())
                ChatTag.append("\002\0037<DND>\003\002");
            switch (plr->GetTeam())
            {
                case 67:ChatTag.append("\0034");break;      //horde
                case 469:ChatTag.append("\00312");break;    //alliance
            }

            IRCOut.append(IRCCmd::MakeMsg("%s\002%s\003\017\002(%d)\002\017", ChatTag.c_str(), plr->GetName(), plr->getLevel()));

            // after XX players have been added to the string
            // output to irc and reset for the next XX
            if (OnlineCount % sIRC.onlrslt == 0)
            {
                sIRC.Send_IRC_Channel(IRCCmd::ChanOrPM(CD), IRCCmd::MakeMsg("\002 %s", IRCOut.c_str()), true, CD->TYPE.c_str());
                IRCOut = "";
                ACE_Based::Thread::Sleep(1000);
            }
        }
    }
    // Remainder in IRCOUT && Total plyersonline
    sIRC.Send_IRC_Channel(IRCCmd::ChanOrPM(CD), IRCCmd::MakeMsg("\002Players Online(%d):\017 %s", OnlineCount, IRCOut.c_str()), true, CD->TYPE);

    sIRC.Script_Lock[MCS_Players_Online] = false;
}