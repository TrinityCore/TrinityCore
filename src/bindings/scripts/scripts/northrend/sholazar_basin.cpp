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

/* ScriptData
SDName: Sholazar_Basin
SD%Complete: 100
SDComment: Quest support: 12570, 12573, 12621.
SDCategory: Sholazar_Basin
EndScriptData */

/* ContentData
npc_injured_rainspeaker_oracle
npc_vekjik
avatar_of_freya
EndContentData */

#include "precompiled.h"
#include "escort_ai.h"

/*######
## npc_injured_rainspeaker_oracle
######*/

#define GOSSIP_ITEM1 "I am ready to travel to your village now."

enum
{
    SAY_START_IRO                       = -1571000,
    SAY_QUEST_ACCEPT_IRO                = -1571001,
    SAY_END_IRO                         = -1571002,

    QUEST_FORTUNATE_MISUNDERSTANDINGS   = 12570,
    FACTION_ESCORTEE_A                  = 774,
    FACTION_ESCORTEE_H                  = 775
};

struct TRINITY_DLL_DECL npc_injured_rainspeaker_oracleAI : public npc_escortAI
{
    npc_injured_rainspeaker_oracleAI(Creature* c) : npc_escortAI(c) { c_guid = c->GetGUID(); }

    uint64 c_guid;

    void Reset()
    {
        me->RestoreFaction();
        // if we will have other way to assign this to only one npc remove this part
        if (GUID_LOPART(me->GetGUID()) != 101030)
        {
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }
    }

    void WaypointReached(uint32 i)
    {
        Player* pPlayer = GetPlayerForEscort();

        if (!pPlayer)
            return;

        switch(i)
        {
        case 1: SetRun(); break;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
            m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_SWIMMING);
            m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_JUMPING);
            m_creature->SetSpeed(MOVE_SWIM, 0.85f, true);
            m_creature->AddUnitMovementFlag(MOVEMENTFLAG_SWIMMING + MOVEMENTFLAG_LEVITATING);
            break;
        case 19:
            m_creature->SetUnitMovementFlags(MOVEMENTFLAG_JUMPING);
            break;
        case 28:
            if (Player* pPlayer = GetPlayerForEscort())
                pPlayer->GroupEventHappens(QUEST_FORTUNATE_MISUNDERSTANDINGS, m_creature);
          //  me->RestoreFaction();
            DoScriptText(SAY_END_IRO,m_creature);
            SetRun(false);
            break;
        }
    }

    void JustDied(Unit* killer)
    {
        if (!IsBeingEscorted)
            return;

        if (Player* pPlayer = GetPlayerForEscort())
        {
          if (pPlayer->GetQuestStatus(QUEST_FORTUNATE_MISUNDERSTANDINGS) != QUEST_STATUS_COMPLETE)
            pPlayer->FailQuest(QUEST_FORTUNATE_MISUNDERSTANDINGS);
        }
    }
};


bool GossipHello_npc_injured_rainspeaker_oracle(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(QUEST_FORTUNATE_MISUNDERSTANDINGS) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_injured_rainspeaker_oracle(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        CAST_AI(npc_escortAI, (pCreature->AI()))->Start(true, false, pPlayer->GetGUID());
        CAST_AI(npc_escortAI, (pCreature->AI()))->SetMaxPlayerDistance(35.0f);
        pCreature->SetUnitMovementFlags(MOVEMENTFLAG_JUMPING);
        DoScriptText(SAY_START_IRO, pCreature);

        switch (pPlayer->GetTeam()){
        case ALLIANCE:
            pCreature->setFaction(FACTION_ESCORTEE_A);
            break;
        case HORDE:
            pCreature->setFaction(FACTION_ESCORTEE_H);
            break;
        }
    }
    return true;
}

bool QuestAccept_npc_injured_rainspeaker_oracle(Player* pPlayer, Creature* pCreature, Quest const *_Quest)
{
    DoScriptText(SAY_QUEST_ACCEPT_IRO, pCreature);
    return false;
}

CreatureAI* GetAI_npc_injured_rainspeaker_oracle(Creature* pCreature)
{
    return new npc_injured_rainspeaker_oracleAI(pCreature);
}

/*######
## npc_vekjik
######*/

#define GOSSIP_VEKJIK_ITEM1 "Shaman Vekjik, I have spoken with the big-tongues and they desire peace. I have brought this offering on their behalf."
#define GOSSIP_VEKJIK_ITEM2 "No no... I had no intentions of betraying your people. I was only defending myself. it was all a misunderstanding."

enum
{
    GOSSIP_TEXTID_VEKJIK1       = 13137,
    GOSSIP_TEXTID_VEKJIK2       = 13138,

    SAY_TEXTID_VEKJIK1          = -1000208,

    SPELL_FREANZYHEARTS_FURY    = 51469,

    QUEST_MAKING_PEACE          = 12573
};

bool GossipHello_npc_vekjik(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(QUEST_MAKING_PEACE) == QUEST_STATUS_INCOMPLETE)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_VEKJIK_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_VEKJIK1, pCreature->GetGUID());
        return true;
    }

    pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_vekjik(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_VEKJIK_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_VEKJIK2, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->CLOSE_GOSSIP_MENU();
            DoScriptText(SAY_TEXTID_VEKJIK1, pCreature, pPlayer);
            pPlayer->AreaExploredOrEventHappens(QUEST_MAKING_PEACE);
            pCreature->CastSpell(pPlayer, SPELL_FREANZYHEARTS_FURY, false);
            break;
    }

    return true;
}


/*######
## avatar_of_freya
######*/

#define GOSSIP_ITEM_AOF1 "I want to stop the Scourge as much as you do. How can I help?"
#define GOSSIP_ITEM_AOF2 "You can trust me. I am no friend of the Lich King."
#define GOSSIP_ITEM_AOF3 "I will not fail."

enum
{
    QUEST_FREYA_PACT         = 12621,

    SPELL_FREYA_CONVERSATION = 52045,

    GOSSIP_TEXTID_AVATAR1    = 13303,
    GOSSIP_TEXTID_AVATAR2    = 13304,
    GOSSIP_TEXTID_AVATAR3    = 13305
};


bool GossipHello_npc_avatar_of_freya(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(QUEST_FREYA_PACT) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_AOF1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXTID_AVATAR1, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_avatar_of_freya(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiAction)
    {
    case GOSSIP_ACTION_INFO_DEF+1:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_AOF2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
        pPlayer->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXTID_AVATAR2, pCreature->GetGUID());
        break;
    case GOSSIP_ACTION_INFO_DEF+2:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_AOF3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
        pPlayer->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXTID_AVATAR3, pCreature->GetGUID());
        break;
    case GOSSIP_ACTION_INFO_DEF+3:
        pPlayer->CastSpell(pPlayer, SPELL_FREYA_CONVERSATION, true);
        pPlayer->CLOSE_GOSSIP_MENU();
        break;
    }
    return true;
}

void AddSC_sholazar_basin()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "npc_injured_rainspeaker_oracle";
    newscript->GetAI = &GetAI_npc_injured_rainspeaker_oracle;
    newscript->pGossipHello = &GossipHello_npc_injured_rainspeaker_oracle;
    newscript->pGossipSelect = &GossipSelect_npc_injured_rainspeaker_oracle;
    newscript->pQuestAccept = &QuestAccept_npc_injured_rainspeaker_oracle;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_vekjik";
    newscript->pGossipHello = &GossipHello_npc_vekjik;
    newscript->pGossipSelect = &GossipSelect_npc_vekjik;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_avatar_of_freya";
    newscript->pGossipHello = &GossipHello_npc_avatar_of_freya;
    newscript->pGossipSelect = &GossipSelect_npc_avatar_of_freya;
    newscript->RegisterSelf();
}
