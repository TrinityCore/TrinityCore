/* Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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

#include "precompiled.h"

/*######
## npc_agnetta_tyrsdottar
######*/

#define SAY_AGGRO                  -1571003
#define GOSSIP_AGNETTA             "Skip the warmup, sister... or are you too scared to face soemeone your own size?"

enum
{
    QUEST_ITS_THAT_YOUR_GOBLIN      = 12969,
    FACTION_HOSTILE_AT1             = 45
};


struct TRINITY_DLL_DECL npc_agnetta_tyrsdottarAI : public ScriptedAI
{
    npc_agnetta_tyrsdottarAI(Creature* pCreature) : ScriptedAI(pCreature) { }

    void Reset()
    {
        me->RestoreFaction();
    }
};

CreatureAI* GetAI_npc_agnetta_tyrsdottar(Creature* pCreature)
{
    return new npc_agnetta_tyrsdottarAI(pCreature);
}

bool GossipHello_npc_agnetta_tyrsdottar(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_ITS_THAT_YOUR_GOBLIN) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_AGNETTA, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(13691, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_agnetta_tyrsdottar(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction )
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        DoScriptText(SAY_AGGRO, pCreature);
        pPlayer->CLOSE_GOSSIP_MENU();
        pCreature->setFaction(FACTION_HOSTILE_AT1);
        pCreature->AI()->AttackStart(pPlayer);
    }

    return true;
}

/*######
## npc_frostborn_scout
######*/

#define GOSSIP_ITEM1    "Are you okay? I've come to take you back to Frosthold if you can stand."
#define GOSSIP_ITEM2    "I'm sorry that I didn't get here sooner. What happened?"
#define GOSSIP_ITEM3    "I'll go get some help. Hang in there."

enum
{
    QUEST_MISSING_SCOUTS  =  12864
};


bool GossipHello_npc_frostborn_scout(Player* pPlayer, Creature* pCreature)
{

    if (pPlayer->GetQuestStatus(QUEST_MISSING_SCOUTS) == QUEST_STATUS_INCOMPLETE)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->PlayerTalkClass->SendGossipMenu(13611, pCreature->GetGUID());
    }

    return true;
}

bool GossipSelect_npc_frostborn_scout(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiAction)
    {
    case GOSSIP_ACTION_INFO_DEF+1:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
        pPlayer->PlayerTalkClass->SendGossipMenu(13612, pCreature->GetGUID());
        break;
    case GOSSIP_ACTION_INFO_DEF+2:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
        pPlayer->PlayerTalkClass->SendGossipMenu(13613, pCreature->GetGUID());
        break;
    case GOSSIP_ACTION_INFO_DEF+3:
        pPlayer->PlayerTalkClass->SendGossipMenu(13614, pCreature->GetGUID());
        pPlayer->AreaExploredOrEventHappens(QUEST_MISSING_SCOUTS);
        break;
    }

    return true;
}

/*######
## npc_thorim
######*/

#define GOSSIP_HN "Thorim?"
#define GOSSIP_SN1 "Can you tell me what became of Sif?"
#define GOSSIP_SN2 "He did more than that, Thorim. He controls Ulduar now."
#define GOSSIP_SN3 "It needn't end this way."

enum
{
    QUEST_SIBLING_RIVALRY = 13064,
    NPC_THORIM = 29445,
    GOSSIP_TEXTID_THORIM1 = 13799,
    GOSSIP_TEXTID_THORIM2 = 13801,
    GOSSIP_TEXTID_THORIM3 = 13802,
    GOSSIP_TEXTID_THORIM4 = 13803
};

bool GossipHello_npc_thorim(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(QUEST_SIBLING_RIVALRY) == QUEST_STATUS_INCOMPLETE) {
        pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_HN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_THORIM1, pCreature->GetGUID());
        return true;
    }
    return false;
}

bool GossipSelect_npc_thorim(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_SN1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_THORIM2, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_SN2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_THORIM3, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_SN3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_THORIM4, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->AreaExploredOrEventHappens(QUEST_SIBLING_RIVALRY);
            break;
    }
    return true;
}

void AddSC_storm_peaks()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_agnetta_tyrsdottar";
    newscript->GetAI = &GetAI_npc_agnetta_tyrsdottar;
    newscript->pGossipHello = &GossipHello_npc_agnetta_tyrsdottar;
    newscript->pGossipSelect = &GossipSelect_npc_agnetta_tyrsdottar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_frostborn_scout";
    newscript->pGossipHello = &GossipHello_npc_frostborn_scout;
    newscript->pGossipSelect = &GossipSelect_npc_frostborn_scout;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_thorim";
    newscript->pGossipHello = &GossipHello_npc_thorim;
    newscript->pGossipSelect = &GossipSelect_npc_thorim;
    newscript->RegisterSelf();
}
