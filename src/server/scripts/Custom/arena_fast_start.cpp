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
********************************************************************************************/

#include "ScriptPCH.h"
#include "Player.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include <sstream> 

class fast_arena_start : public GameObjectScript
{
    public:

        fast_arena_start() : GameObjectScript("fast_arena_start")
        { }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            if (Battleground *bg = player->GetBattleground())
                if (bg->isArena())
                    ChatHandler(player->GetSession()).PSendSysMessage("Players clicked: %u", bg->ClickFastStart(player, go));

            return false;
        }
};

void AddSC_fast_arena_start()
{
    new fast_arena_start();
}