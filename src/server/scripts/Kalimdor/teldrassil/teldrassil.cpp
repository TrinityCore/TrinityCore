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
SDName: Teldrassil
SD%Complete: 100
SDComment: Quest support: 938
SDCategory: Teldrassil
EndScriptData */

/* ContentData
npc_mist
EndContentData */

#include "scriptPCH.h"

/*####
# npc_mist
####*/

enum MistData
{
    SAY_AT_HOME       = 1330,
    EMOTE_AT_HOME     = 1340,
    QUEST_MIST        = 938,
    NPC_ARYNIA        = 3519,
    FACTION_DARNASSUS = 79
};

struct npc_mistAI : public FollowerAI
{
    npc_mistAI(Creature* pCreature) : FollowerAI(pCreature)
    {
        Reset();
    }

    void Reset() override { }

    void JustRespawned() override
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
        FollowerAI::JustRespawned();
    }

    void MoveInLineOfSight(Unit *pWho) override
    {
        FollowerAI::MoveInLineOfSight(pWho);

        if (!m_creature->GetVictim() && !HasFollowState(STATE_FOLLOW_COMPLETE) && pWho->GetEntry() == NPC_ARYNIA)
        {
            if (m_creature->IsWithinDistInMap(pWho, 10.0f))
            {
                DoScriptText(SAY_AT_HOME, pWho);
                DoComplete();
            }
        }
    }

    void DoComplete()
    {
        DoScriptText(EMOTE_AT_HOME, m_creature);

        if (Player* pPlayer = GetLeaderForFollower())
        {
            if (pPlayer->GetQuestStatus(QUEST_MIST) == QUEST_STATUS_INCOMPLETE)
                pPlayer->GroupEventHappens(QUEST_MIST, m_creature);
        }

        //The follow is over (and for later development, run off to the woods before really end)
        SetFollowComplete();
    }

    //call not needed here, no known abilities
    /*void UpdateFollowerAI(uint32 const uiDiff)
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }*/
};

CreatureAI* GetAI_npc_mist(Creature* pCreature)
{
    return new npc_mistAI(pCreature);
}

struct npc_sethirAI : public ScriptedAI
{
    npc_sethirAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    void Reset() override { }

    void Aggro(Unit* pUnit) override
    {
        m_creature->MonsterSay("Filfh! Filfh everywhere! The forests must be cleansed!");
        for (uint32 counter = 0; counter < 6; counter++)
        {
            if (Creature* summoned = DoSpawnCreature(6911, 8.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 1000))
                if (summoned->AI())
                    summoned->AI()->AttackStart(pUnit);
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_sethir(Creature* pCreature)
{
    return new npc_sethirAI(pCreature);
}

bool QuestAccept_npc_mist(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_MIST)
    {
        if (npc_mistAI* pMistAI = dynamic_cast<npc_mistAI*>(pCreature->AI()))
        {
            pCreature->SetFactionTemporary(FACTION_DARNASSUS, TEMPFACTION_RESTORE_RESPAWN);
            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
            pMistAI->StartFollow(pPlayer, FACTION_DARNASSUS, pQuest);
        } 
    }

    return true;
}

//Alita
enum TreshalaFallowbrookData
{
    QUEST_MORTALITY_WANES = 1142
};

bool QuestComplete_npc_treshala_fallowbrook(Player* pPlayer, Creature* pQuestGiver, Quest const* pQuest)
{
    if (!pQuestGiver)
        return false;
    if (pQuest->GetQuestId() == QUEST_MORTALITY_WANES)
    {
        pQuestGiver->HandleEmoteCommand(EMOTE_ONESHOT_CRY);
    }
    return false;//return false meaning let DB take over (probably)(nothing in db anyway)
}

void AddSC_teldrassil()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_mist";
    newscript->GetAI = &GetAI_npc_mist;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_mist;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_sethir";
    newscript->GetAI = &GetAI_npc_sethir;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_treshala_fallowbrook";
    newscript->pQuestRewardedNPC = &QuestComplete_npc_treshala_fallowbrook;
    newscript->RegisterSelf();
}
