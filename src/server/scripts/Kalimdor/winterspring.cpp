/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Winterspring
SD%Complete: 90
SDComment: Quest support: 5126 (Loraxs' tale missing proper gossip items text). Vendor Rivern Frostwind. Obtain Cache of Mau'ari
SDCategory: Winterspring
EndScriptData */

/* ContentData
npc_lorax
npc_rivern_frostwind
npc_witch_doctor_mauari
EndContentData */

#include "ScriptPCH.h"

/*######
## npc_lorax
######*/

#define GOSSIP_HL "Talk to me"

#define GOSSIP_SL1 "What do you do here?"
#define GOSSIP_SL2 "I can help you"
#define GOSSIP_SL3 "What deal?"
#define GOSSIP_SL4 "Then what happened?"
#define GOSSIP_SL5 "He is not safe, i'll make sure of that."

class npc_lorax : public CreatureScript
{
public:
    npc_lorax() : CreatureScript("npc_lorax") { }

    bool OnGossipSelect(Player* pPlayer, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SL1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                pPlayer->SEND_GOSSIP_MENU(3759, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+1:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SL2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                pPlayer->SEND_GOSSIP_MENU(3760, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SL3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                pPlayer->SEND_GOSSIP_MENU(3761, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SL4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                pPlayer->SEND_GOSSIP_MENU(3762, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SL5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
                pPlayer->SEND_GOSSIP_MENU(3763, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+5:
                pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->AreaExploredOrEventHappens(5126);
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* creature)
    {
        if (creature->isQuestGiver())
            pPlayer->PrepareQuestMenu(creature->GetGUID());

        if (pPlayer->GetQuestStatus(5126) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

};

/*######
## npc_rivern_frostwind
######*/

class npc_rivern_frostwind : public CreatureScript
{
public:
    npc_rivern_frostwind() : CreatureScript("npc_rivern_frostwind") { }

    bool OnGossipSelect(Player* pPlayer, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_TRADE)
            pPlayer->GetSession()->SendListInventory(creature->GetGUID());

        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* creature)
    {
        if (creature->isQuestGiver())
            pPlayer->PrepareQuestMenu(creature->GetGUID());

        if (creature->isVendor() && pPlayer->GetReputationRank(589) == REP_EXALTED)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

};

/*######
## npc_witch_doctor_mauari
######*/

#define GOSSIP_HWDM "I'd like you to make me a new Cache of Mau'ari please."

class npc_witch_doctor_mauari : public CreatureScript
{
public:
    npc_witch_doctor_mauari() : CreatureScript("npc_witch_doctor_mauari") { }

    bool OnGossipSelect(Player* pPlayer, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            creature->CastSpell(pPlayer, 16351, false);
        }

        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* creature)
    {
        if (creature->isQuestGiver())
            pPlayer->PrepareQuestMenu(creature->GetGUID());

        if (pPlayer->GetQuestRewardStatus(975))
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HWDM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->SEND_GOSSIP_MENU(3377, creature->GetGUID());
        }else
            pPlayer->SEND_GOSSIP_MENU(3375, creature->GetGUID());

        return true;
    }

};

void AddSC_winterspring()
{
    new npc_lorax();
    new npc_rivern_frostwind();
    new npc_witch_doctor_mauari();
}
