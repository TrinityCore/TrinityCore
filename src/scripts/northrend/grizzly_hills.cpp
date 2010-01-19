/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Grizzly_Hills
SD%Complete: 80
SDComment: Quest support: 12231, 12247
SDCategory: Grizzly Hills
EndScriptData */

/* ContentData
npc_orsonn_and_kodian
EndContentData */

#include "ScriptedPch.h"

#define GOSSIP_ITEM1 "You're free to go Orsonn, but first tell me what's wrong with the furbolg."
#define GOSSIP_ITEM2 "What happened then?"
#define GOSSIP_ITEM3 "Thank you, Son of Ursoc. I'll see what can be done."
#define GOSSIP_ITEM4 "Who was this stranger?"
#define GOSSIP_ITEM5 "Thank you, Kodian. I'll do what I can."

enum eEnums
{
    GOSSIP_TEXTID_ORSONN1       = 12793,
    GOSSIP_TEXTID_ORSONN2       = 12794,
    GOSSIP_TEXTID_ORSONN3       = 12796,

    GOSSIP_TEXTID_KODIAN1       = 12797,
    GOSSIP_TEXTID_KODIAN2       = 12798,

    NPC_ORSONN                  = 27274,
    NPC_KODIAN                  = 27275,

    //trigger creatures
    NPC_ORSONN_CREDIT           = 27322,
    NPC_KODIAN_CREDIT           = 27321,

    QUEST_CHILDREN_OF_URSOC     = 12247,
    QUEST_THE_BEAR_GODS_OFFSPRING        = 12231
};

bool GossipHello_npc_orsonn_and_kodian(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(QUEST_CHILDREN_OF_URSOC) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(QUEST_THE_BEAR_GODS_OFFSPRING) == QUEST_STATUS_INCOMPLETE)
    {
        switch(pCreature->GetEntry())
        {
            case NPC_ORSONN:
                if (!pPlayer->GetReqKillOrCastCurrentCount(QUEST_CHILDREN_OF_URSOC, NPC_ORSONN_CREDIT) || !pPlayer->GetReqKillOrCastCurrentCount(QUEST_THE_BEAR_GODS_OFFSPRING, NPC_ORSONN_CREDIT))
                {
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                    pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ORSONN1, pCreature->GetGUID());
                    return true;
                }
                break;
            case NPC_KODIAN:
                if (!pPlayer->GetReqKillOrCastCurrentCount(QUEST_CHILDREN_OF_URSOC, NPC_KODIAN_CREDIT) || !pPlayer->GetReqKillOrCastCurrentCount(QUEST_THE_BEAR_GODS_OFFSPRING, NPC_KODIAN_CREDIT))
                {
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                    pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_KODIAN1, pCreature->GetGUID());
                    return true;
                }
                break;
        }
    }

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_orsonn_and_kodian(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ORSONN2, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ORSONN3, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->TalkedToCreature(NPC_ORSONN_CREDIT, pCreature->GetGUID());
            break;

        case GOSSIP_ACTION_INFO_DEF+4:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_KODIAN2, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->TalkedToCreature(NPC_KODIAN_CREDIT, pCreature->GetGUID());
            break;
    }

    return true;
}

void AddSC_grizzly_hills()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_orsonn_and_kodian";
    newscript->pGossipHello = &GossipHello_npc_orsonn_and_kodian;
    newscript->pGossipSelect = &GossipSelect_npc_orsonn_and_kodian;
    newscript->RegisterSelf();
}
