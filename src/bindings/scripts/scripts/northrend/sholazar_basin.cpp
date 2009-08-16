/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDComment: Quest support: 12570
SDCategory: Sholazar_Basin
EndScriptData */

/* ContentData
npc_injured_rainspeaker_oracle
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
        Player* pPlayer = Unit::GetPlayer(PlayerGUID);

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
            if (Player* pPlayer = Unit::GetPlayer(PlayerGUID))
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

        if (Player* pPlayer = Unit::GetPlayer(PlayerGUID))
        {            
          if (pPlayer->GetQuestStatus(QUEST_FORTUNATE_MISUNDERSTANDINGS) != QUEST_STATUS_COMPLETE)
            pPlayer->FailQuest(QUEST_FORTUNATE_MISUNDERSTANDINGS);
        }
    }

    void UpdateAI(Player* pPlayer, Creature* pCreature,const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);
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
}
