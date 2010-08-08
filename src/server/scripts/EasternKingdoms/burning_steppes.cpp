/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"

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

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                pPlayer->SEND_GOSSIP_MENU(2714, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+1:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                pPlayer->SEND_GOSSIP_MENU(2715, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                pPlayer->SEND_GOSSIP_MENU(2716, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                pPlayer->SEND_GOSSIP_MENU(2717, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
                pPlayer->SEND_GOSSIP_MENU(2718, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+5:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
                pPlayer->SEND_GOSSIP_MENU(2719, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+6:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
                pPlayer->SEND_GOSSIP_MENU(2720, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+7:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT8, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
                pPlayer->SEND_GOSSIP_MENU(2721, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+8:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT9, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
                pPlayer->SEND_GOSSIP_MENU(2722, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+9:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT10, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
                pPlayer->SEND_GOSSIP_MENU(2723, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+10:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT11, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
                pPlayer->SEND_GOSSIP_MENU(2725, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+11:
                pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->AreaExploredOrEventHappens(4224);
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (pPlayer->GetQuestStatus(4224) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

        pPlayer->SEND_GOSSIP_MENU(2713, pCreature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_ragged_johnAI (pCreature);
    }

    struct npc_ragged_johnAI : public ScriptedAI
    {
        npc_ragged_johnAI(Creature *c) : ScriptedAI(c) {}

        void Reset() {}

        void MoveInLineOfSight(Unit *who)
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

        void EnterCombat(Unit * /*who*/) {}
    };

};




void AddSC_burning_steppes()
{
    new npc_ragged_john();
}
