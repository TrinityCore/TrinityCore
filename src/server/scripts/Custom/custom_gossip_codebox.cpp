/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Custom_Gossip_Codebox
SD%Complete: 100
SDComment: Show a codebox in gossip option
SDCategory: Script Examples
EndScriptData */

#include "precompiled.h"
#include <cstring>

#define GOSSIP_ITEM_EXTENDED    "A quiz: what's your name?"
#define GOSSIP_ITEM             "I'm not interested"

#define SAY_NOT_INTERESTED      "Normal select, guess you're not interested."
#define SAY_WRONG               "Wrong!"
#define SAY_RIGHT               "You're right, you are allowed to see my inner secrets."

//This function is called when the player opens the gossip menubool
class custom_gossip_codebox : public GameObjectScript
{
public:
    custom_gossip_codebox() : GameObjectScript("custom_gossip_codebox") { }

    bool GossipSelectWithCode(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction, const char* sCode)
    {
        if (uiSender == GOSSIP_SENDER_MAIN)
        {
            if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
            {
                if (std::strcmp(sCode, pPlayer->GetName())!=0)
                {
                    pCreature->Say(SAY_WRONG, LANG_UNIVERSAL, 0);
                    pCreature->CastSpell(pPlayer, 12826, true);
                }
                else
                {
                    pCreature->Say(SAY_RIGHT, LANG_UNIVERSAL, 0);
                    pCreature->CastSpell(pPlayer, 26990, true);
                }
                pPlayer->CLOSE_GOSSIP_MENU();
                return true;
            }
        }
        return false;
    }

    bool GossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
    {
        if (uiAction == GOSSIP_ACTION_INFO_DEF+2)
        {
            pCreature->Say(SAY_NOT_INTERESTED, LANG_UNIVERSAL, 0);
            pPlayer->CLOSE_GOSSIP_MENU();
        }
        return true;
    }

    bool GossipHello(Player* pPlayer, Creature* pCreature)
    {
        pPlayer->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1, "", 0, true);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

        pPlayer->PlayerTalkClass->SendGossipMenu(907, pCreature->GetGUID());
        return true;
    }

};

//This function is called when the player clicks an option on the gossip menubool


void AddSC_custom_gossip_codebox()
{
    new custom_gossip_codebox();
}
