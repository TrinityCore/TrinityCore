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
SDName: Arathi Highlands
SD%Complete: 100
SDComment: Quest support: 665
SDCategory: Arathi Highlands
EndScriptData */

/* ContentData
npc_professor_phizzlethorpe
EndContentData */

#include "scriptPCH.h"

/*######
## npc_professor_phizzlethorpe
######*/

enum
{
    SAY_PROGRESS_1          = 845,
    SAY_PROGRESS_2          = 846,
    SAY_PROGRESS_3          = 847,
    EMOTE_PROGRESS_4        = 848,
    SAY_AGGRO               = 859,
    SAY_PROGRESS_5          = 849,
    SAY_PROGRESS_6          = 850,
    SAY_PROGRESS_7          = 851,
    EMOTE_PROGRESS_8        = 889,
    SAY_PROGRESS_9          = 890,

    QUEST_SUNKEN_TREASURE   = 665,
    ENTRY_VENGEFUL_SURGE    = 2776
};

struct npc_professor_phizzlethorpeAI : public npc_escortAI
{
    npc_professor_phizzlethorpeAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        Reset();
    }

    void Reset() override { }

    void WaypointReached(uint32 uiPointId) override
    {
        Player* pPlayer = GetPlayerForEscort();

        if (!pPlayer)
            return;

        switch (uiPointId)
        {
            case 4:
                DoScriptText(SAY_PROGRESS_2, m_creature, pPlayer);
                break;
            case 5:
                DoScriptText(SAY_PROGRESS_3, m_creature, pPlayer);
                break;
            case 8:
                DoScriptText(EMOTE_PROGRESS_4, m_creature);
                break;
            case 9:
                m_creature->SummonCreature(ENTRY_VENGEFUL_SURGE, -2056.41f, -2144.01f, 20.59f, 5.70f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 600000);
                m_creature->SummonCreature(ENTRY_VENGEFUL_SURGE, -2050.17f, -2140.02f, 19.54f, 5.17f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 600000);
                break;
            case 10:
                DoScriptText(SAY_PROGRESS_5, m_creature, pPlayer);
                break;
            case 11:
                DoScriptText(SAY_PROGRESS_6, m_creature, pPlayer);
                SetRun();
                break;
            case 19:
                DoScriptText(SAY_PROGRESS_7, m_creature, pPlayer);
                break;
            case 20:
                DoScriptText(EMOTE_PROGRESS_8, m_creature);
                DoScriptText(SAY_PROGRESS_9, m_creature, pPlayer);
                pPlayer->GroupEventHappens(QUEST_SUNKEN_TREASURE, m_creature);
                break;
        }
    }

    void Aggro(Unit* pWho) override
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }

    void JustSummoned(Creature* pSummoned) override
    {
        pSummoned->AI()->AttackStart(m_creature);
    }
};

bool QuestAccept_npc_professor_phizzlethorpe(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_SUNKEN_TREASURE)
    {
        pCreature->SetFactionTemplateId(FACTION_ESCORT_N_NEUTRAL_PASSIVE);
        DoScriptText(SAY_PROGRESS_1, pCreature, pPlayer);

        if (npc_professor_phizzlethorpeAI* pEscortAI = dynamic_cast<npc_professor_phizzlethorpeAI*>(pCreature->AI()))
            pEscortAI->Start(false, pPlayer->GetGUID(), pQuest, true);
    }
    return true;
}

CreatureAI* GetAI_npc_professor_phizzlethorpe(Creature* pCreature)
{
    return new npc_professor_phizzlethorpeAI(pCreature);
}

/*####
# npc_shakes_o_breen
####*/

enum
{
    QUEST_DEATH_FROM_BELOW     = 667,

    NPC_DAGGERSPINE_RAIDER     = 2595,
    NPC_DAGGERSPINE_SORCERESS  = 2596,

    BREEN_YELL_1 = 6372,
    NAGA_YELL_1  = 854,
    BREEN_SAY_2  = 863,
};

static float m_afNagaCoord[4][4] =
{
    { -2154.049f, -1969.738f, 15.371f, 5.54f },
    { -2157.606f, -1972.530f, 15.552f, 5.54f },
    { -2157.533f, -1968.904f, 15.410f, 5.54f },
    { -2109.839f, -2017.029f, 6.0080f, 5.54f },
};

struct npc_shakes_o_breenAI : npc_escortAI
{
    explicit npc_shakes_o_breenAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        m_uiPlayerCheckTimer = 3000;

        npc_shakes_o_breenAI::Reset();
    }

    uint8 m_uiWaveId;
    uint8 m_uiNagaAlive;
    uint32 m_uiEventTimer;
    uint32 m_uiPlayerCheckTimer;

    void Reset() override
    {
        m_uiEventTimer = 20000;

        if (!HasEscortState(STATE_ESCORT_ESCORTING))
        {
            m_uiWaveId = 0;
            m_uiNagaAlive = 0;
            m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        }
    }

    void WaypointReached(uint32 /*uiPointId*/) override {}

    void DoSummon(uint32 entry, uint8 index) const
    {
        m_creature->SummonCreature(entry, 
            m_afNagaCoord[index][0], 
            m_afNagaCoord[index][1], 
            m_afNagaCoord[index][2], 
            m_afNagaCoord[index][3], TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, MINUTE*IN_MILLISECONDS);
    }

    void DoWaveSummon()
    {
        ++m_uiWaveId;

        if (m_uiWaveId == 3)
            m_creature->MonsterSay(BREEN_SAY_2);

        switch (m_uiWaveId)
        {
            case 1:
            case 3:
                DoSummon(NPC_DAGGERSPINE_RAIDER, 0);
                DoSummon(NPC_DAGGERSPINE_RAIDER, 1);
                DoSummon(NPC_DAGGERSPINE_SORCERESS, 2);
                break;
            case 2:
                DoSummon(NPC_DAGGERSPINE_RAIDER, 0);
                DoSummon(NPC_DAGGERSPINE_RAIDER, 1);
                break;
        }
    }

    void FinishEvent(bool success)
    {
        if (success)
        {
            if (Player* pPlayer = GetPlayerForEscort())
                pPlayer->GroupEventHappens(QUEST_DEATH_FROM_BELOW, m_creature);            
        }
        else
        {
            m_creature->DisappearAndDie();
            return;
        }

        RemoveEscortState(STATE_ESCORT_ESCORTING | STATE_ESCORT_PAUSED);
        Reset();
    }

    void JustSummoned(Creature* pSummoned) override
    {
        if (m_uiWaveId == 1 && pSummoned->GetEntry() == NPC_DAGGERSPINE_RAIDER && !m_uiNagaAlive)
            pSummoned->MonsterYell(NAGA_YELL_1);

        ++m_uiNagaAlive;

        pSummoned->SetNoXP();
        pSummoned->GetMotionMaster()->Clear();
        pSummoned->SetWalk(false);
        pSummoned->GetMotionMaster()->MovePoint(0, m_afNagaCoord[3][0], m_afNagaCoord[3][1], m_afNagaCoord[3][2], MOVE_PATHFINDING);
    }

    void SummonedCreatureJustDied(Creature* pSummoned) override
    {
        --m_uiNagaAlive;
        pSummoned->loot.clear();
    }

    void SummonedMovementInform(Creature* pSummoned, uint32 /*uiMotionType*/, uint32 uiPointId) override
    {
        if (!uiPointId)
        {
            m_creature->AddThreat(pSummoned, 10.0f);
            pSummoned->AddThreat(m_creature, 10.0f);
        }
    }

    void UpdateEscortAI(uint32 const uiDiff) override
    {
        if (HasEscortState(STATE_ESCORT_ESCORTING))
        {
            if (m_uiPlayerCheckTimer < uiDiff)
            {
                auto pPlayer = GetPlayerForEscort();
                if (!pPlayer || !pPlayer->IsInRange(m_creature, 0.0f, 150.0f))
                    FinishEvent(false);
                else
                    m_uiPlayerCheckTimer = 3000;
            }
            else
                m_uiPlayerCheckTimer -= uiDiff;

            if (m_uiEventTimer < uiDiff)
            {
                if (m_uiWaveId < 3)
                {
                    DoWaveSummon();
                    m_uiEventTimer = 20000;                
                }
                else
                {
                    if (m_uiNagaAlive)
                        m_uiEventTimer = 1000;
                    else
                        FinishEvent(true);
                }
            }
            else
                m_uiEventTimer -= uiDiff;            
        }

        npc_escortAI::UpdateEscortAI(uiDiff);
    }
};

bool QuestAccept_npc_shakes_o_breen(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_DEATH_FROM_BELOW)
    {
        if (auto pEscortAI = dynamic_cast<npc_shakes_o_breenAI*>(pCreature->AI()))
        {
            pCreature->MonsterYell(BREEN_YELL_1);
            pEscortAI->Start(false, pPlayer->GetGUID(), pQuest);
            pEscortAI->SetEscortPaused(true);
            pCreature->SetOrientation(2.67f);
        }
    }

    return true;
}

CreatureAI* GetAI_npc_shakes_o_breen(Creature* pCreature)
{
    return new npc_shakes_o_breenAI(pCreature);
}

/*######
## npc_kinelory
######*/

enum
{
    SAY_START               = 816,
    SAY_REACH_BOTTOM        = 817,
    SAY_AGGRO_KINELORY      = 897,
    SAY_AGGRO_JORELL        = 896,
    SAY_WATCH_BACK          = 818,
    EMOTE_BELONGINGS        = 819,
    SAY_DATA_FOUND          = 821,
    SAY_ESCAPE              = 822,
    SAY_FINISH              = 892,
    EMOTE_HAND_PACK         = 891,

    SPELL_REJUVENATION      = 3627,
    SPELL_BEAR_FORM         = 4948,

    NPC_JORELL              = 2733,
    NPC_QUAE                = 2712,

    QUEST_HINTS_NEW_PLAGUE  = 660
};

struct npc_kineloryAI : public npc_escortAI
{
    npc_kineloryAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiBearFormTimer;
    uint32 m_uiHealTimer;

    void Reset() override
    {
        m_uiBearFormTimer = urand(5000, 7000);
        m_uiHealTimer     = urand(2000, 5000);
    }

    void JustRespawned() override
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
        npc_escortAI::JustRespawned();
    }

    void WaypointReached(uint32 uiPointId) override
    {
        switch (uiPointId)
        {
            case 9:
                DoScriptText(SAY_REACH_BOTTOM, m_creature);
                break;
            case 16:
                DoScriptText(SAY_WATCH_BACK, m_creature);
                DoScriptText(EMOTE_BELONGINGS, m_creature);
                break;
            case 17:
                DoScriptText(SAY_DATA_FOUND, m_creature);
                break;
            case 18:
                DoScriptText(SAY_ESCAPE, m_creature);
                if (Player* pPlayer = GetPlayerForEscort())
                    m_creature->SetFacingToObject(pPlayer);
                SetRun();
                break;
            case 33:
                DoScriptText(SAY_FINISH, m_creature);
                if (Creature* pQuae = GetClosestCreatureWithEntry(m_creature, NPC_QUAE, 10.0f))
                {
                    DoScriptText(EMOTE_HAND_PACK, m_creature, pQuae);
                    m_creature->SetFacingToObject(pQuae);
                }
                break;
            case 34:
                if (Player* pPlayer = GetPlayerForEscort())
                    pPlayer->GroupEventHappens(QUEST_HINTS_NEW_PLAGUE, m_creature);
                break;
        }
    }

    void Aggro(Unit* pWho) override
    {
        if (pWho->GetEntry() == NPC_JORELL)
            DoScriptText(SAY_AGGRO_JORELL, pWho, m_creature);
        else if (roll_chance_i(10))
            DoScriptText(SAY_AGGRO_KINELORY, m_creature);
    }

    void UpdateEscortAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiBearFormTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_BEAR_FORM) == CAST_OK)
                m_uiBearFormTimer = urand(25000, 30000);
        }
        else
            m_uiBearFormTimer -= uiDiff;

        if (m_uiHealTimer < uiDiff)
        {
            if (m_creature->GetHealthPercent() < 80.0f)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_REJUVENATION) == CAST_OK)
                    m_uiHealTimer = urand(15000, 25000);
            }
        }
        else
            m_uiHealTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_kinelory(Creature* pCreature)
{
    return new npc_kineloryAI(pCreature);
}

bool QuestAccept_npc_kinelory(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_HINTS_NEW_PLAGUE)
    {
        if (npc_kineloryAI* pKineloryAI = dynamic_cast<npc_kineloryAI*>(pCreature->AI()))
        {
            DoScriptText(SAY_START, pCreature);
            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
            pKineloryAI->Start(false, pPlayer->GetGUID(), pQuest);
        }
    }
    return true;
}

void AddSC_arathi_highlands()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_professor_phizzlethorpe";
    newscript->GetAI = &GetAI_npc_professor_phizzlethorpe;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_professor_phizzlethorpe;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_shakes_o_breen";
    newscript->GetAI = &GetAI_npc_shakes_o_breen;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_shakes_o_breen;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_kinelory";
    newscript->GetAI = &GetAI_npc_kinelory;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_kinelory;
    newscript->RegisterSelf();
}
