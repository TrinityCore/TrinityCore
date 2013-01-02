/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
SDName: Burning_Steppes
SD%Complete: 100
SDComment: Quest support: 4224, 4866
SDCategory: Burning Steppes
EndScriptData */

/* ContentData
npc_ragged_john
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"

/*######
## npc_ragged_john
######*/

#define GOSSIP_HELLO    "Official buisness, John. I need some information about Marsha Windsor. Tell me about the last time you saw him."
#define GOSSIP_SELECT1  "So what did you do?"
#define GOSSIP_SELECT2  "Start making sense, dwarf. I don't want to have anything to do with your cracker, your pappy, or any sort of 'discreditin'."
#define GOSSIP_SELECT3  "Ironfoe?"
#define GOSSIP_SELECT4  "Interesting... continue John."
#define GOSSIP_SELECT5  "So that's how Windsor died..."
#define GOSSIP_SELECT6  "So how did he die?"
#define GOSSIP_SELECT7  "Ok so where the hell is he? Wait a minute! Are you drunk?"
#define GOSSIP_SELECT8  "WHY is he in Blackrock Depths?"
#define GOSSIP_SELECT9  "300? So the Dark Irons killed him and dragged him into the Depths?"
#define GOSSIP_SELECT10 "Ahh... Ironfoe"
#define GOSSIP_SELECT11 "Thanks, Ragged John. Your story was very uplifting and informative"

class npc_ragged_john : public CreatureScript
{
public:
    npc_ragged_john() : CreatureScript("npc_ragged_john") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->SEND_GOSSIP_MENU(2714, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+1:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                player->SEND_GOSSIP_MENU(2715, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                player->SEND_GOSSIP_MENU(2716, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                player->SEND_GOSSIP_MENU(2717, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
                player->SEND_GOSSIP_MENU(2718, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+5:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
                player->SEND_GOSSIP_MENU(2719, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+6:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
                player->SEND_GOSSIP_MENU(2720, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+7:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT8, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
                player->SEND_GOSSIP_MENU(2721, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+8:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT9, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
                player->SEND_GOSSIP_MENU(2722, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+9:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT10, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
                player->SEND_GOSSIP_MENU(2723, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+10:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT11, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
                player->SEND_GOSSIP_MENU(2725, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+11:
                player->CLOSE_GOSSIP_MENU();
                player->AreaExploredOrEventHappens(4224);
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(4224) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

        player->SEND_GOSSIP_MENU(2713, creature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ragged_johnAI (creature);
    }

    struct npc_ragged_johnAI : public ScriptedAI
    {
        npc_ragged_johnAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() {}

        void MoveInLineOfSight(Unit* who)
        {
            if (who->HasAura(16468))
            {
                if (who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 15) && who->isInAccessiblePlaceFor(me))
                {
                    DoCast(who, 16472);
                    CAST_PLR(who)->AreaExploredOrEventHappens(4866);
                }
            }

            ScriptedAI::MoveInLineOfSight(who);
        }

        void EnterCombat(Unit* /*who*/) {}
    };
};

void AddSC_burning_steppes()
{
    new npc_ragged_john();
}
