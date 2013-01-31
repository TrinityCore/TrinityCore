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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"

class npc_shop : public CreatureScript
{
    public:
       npc_shop() : CreatureScript("npc_shop") {}

    // ^_^!
};

void AddSC_npc_shop()
{
    new npc_shop();
}
