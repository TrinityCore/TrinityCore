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
SDName: Blasted_Lands
SD%Complete: 90
SDComment: Quest support: 2784, 2801, 3628. Missing some texts for Fallen Hero. Teleporter to Rise of the Defiler missing group support.
SDCategory: Blasted Lands
EndScriptData */

/* ContentData
npc_deathly_usher
npc_fallen_hero_of_horde
EndContentData */

#include "ScriptPCH.h"

/*######
## npc_deathly_usher
######*/

#define GOSSIP_ITEM_USHER "I wish to to visit the Rise of the Defiler."

#define SPELL_TELEPORT_SINGLE           12885
#define SPELL_TELEPORT_SINGLE_IN_GROUP  13142
#define SPELL_TELEPORT_GROUP            27686

class npc_deathly_usher : public CreatureScript
{
public:
    npc_deathly_usher() : CreatureScript("npc_deathly_usher") { }

    bool OnGossipSelect(Player* pPlayer, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            creature->CastSpell(pPlayer, SPELL_TELEPORT_SINGLE, true);
        }

        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* creature)
    {
        if (pPlayer->GetQuestStatus(3628) == QUEST_STATUS_INCOMPLETE && pPlayer->HasItemCount(10757, 1))
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_USHER, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

};

/*######
## npc_fallen_hero_of_horde
######*/
#define GOSSIP_H_F1 "Why are you here?"
#define GOSSIP_H_F2 "Continue story..."

#define GOSSIP_ITEM_FALLEN "Continue..."

#define GOSSIP_ITEM_FALLEN1 "What could be worse than death?"
#define GOSSIP_ITEM_FALLEN2 "Subordinates?"
#define GOSSIP_ITEM_FALLEN3 "What are the stones of binding?"
#define GOSSIP_ITEM_FALLEN4 "You can count on me, Hero"
#define GOSSIP_ITEM_FALLEN5 "I shall"

class npc_fallen_hero_of_horde : public CreatureScript
{
public:
    npc_fallen_hero_of_horde() : CreatureScript("npc_fallen_hero_of_horde") { }

    bool OnGossipSelect(Player* pPlayer, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_FALLEN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
                pPlayer->SEND_GOSSIP_MENU(1392, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+11:
                pPlayer->SEND_GOSSIP_MENU(1411, creature->GetGUID());
                if (pPlayer->GetQuestStatus(2784) == QUEST_STATUS_INCOMPLETE)
                    pPlayer->AreaExploredOrEventHappens(2784);
                if (pPlayer->GetTeam() == ALLIANCE)
                {
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_FALLEN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                    pPlayer->SEND_GOSSIP_MENU(1411, creature->GetGUID());
                }
                break;

            case GOSSIP_ACTION_INFO_DEF+2:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_FALLEN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 21);
                pPlayer->SEND_GOSSIP_MENU(1451, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+21:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_FALLEN1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 22);
                pPlayer->SEND_GOSSIP_MENU(1452, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+22:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_FALLEN2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);
                pPlayer->SEND_GOSSIP_MENU(1453, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+23:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_FALLEN3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 24);
                pPlayer->SEND_GOSSIP_MENU(1454, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+24:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_FALLEN4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 25);
                pPlayer->SEND_GOSSIP_MENU(1455, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+25:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_FALLEN5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 26);
                pPlayer->SEND_GOSSIP_MENU(1456, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+26:
                pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->AreaExploredOrEventHappens(2801);
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* creature)
    {
        if (creature->isQuestGiver())
            pPlayer->PrepareQuestMenu(creature->GetGUID());

        if (pPlayer->GetQuestStatus(2784) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_H_F1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        if (pPlayer->GetQuestStatus(2801) == QUEST_STATUS_INCOMPLETE && pPlayer->GetTeam() == HORDE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_H_F2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

        if (pPlayer->GetQuestStatus(2801) == QUEST_STATUS_INCOMPLETE && pPlayer->GetTeam() == ALLIANCE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_H_F1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

};

void AddSC_blasted_lands()
{
    new npc_deathly_usher();
    new npc_fallen_hero_of_horde();
}
