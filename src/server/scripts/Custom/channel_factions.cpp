/*******************************************************************************************
*              ______                   ______                   _____                     *
*             / _____)                 |  ___ \                 / ___ \       _            *
*            | /  ___  ____  ____ _   _| | _ | | ___ _   _ ____| |   | |_   _| |_          *
*            | | (___)/ _  |/ ___) | | | || || |/ _ \ | | / _  ) |   | | | | |  _)         *
*            | \____/( ( | | |   | |_| | || || | |_| \ V ( (/ /| |___| | |_| | |__         *
*             \_____/ \_||_|_|    \__  |_||_||_|\___/ \_/ \____)\_____/ \____|\___)        *
*                                (____/                                                    *
*                               or any other files are protected. You cannot re-release    * 
*                               anywhere unless you were given permission.                 *
*                           (C) GaryMoveOut 2013. All rights reserved.                     *
*                                                                           Thx MarWit!    *
********************************************************************************************/

#include "ScriptPCH.h"
#include "Channel.h"
#include "Player.h"
#include <sstream>

class channel_factions : public PlayerScript
{
    public:
        channel_factions() : PlayerScript("channel_factions"){}

    void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Channel* channel )
    {
        if (!player || !channel)
            return;

        std::stringstream ssMsg;
        ssMsg << ((player->GetTeam() == HORDE) ? "|TInterface\\PVPFrame\\PVP-Currency-Horde:18:18:-3:-3|t" : "|TInterface\\PVPFrame\\PVP-Currency-Alliance:18:18:-3:-3|t") << msg;
        msg = ssMsg.str();
    }
};

void AddSC_channel_factions()
{
    new channel_factions();
}
