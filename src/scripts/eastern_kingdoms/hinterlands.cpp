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
SDName: Hinterlands
SD%Complete: 100
SDComment: Quest support: 863, 2742
SDCategory: The Hinterlands
EndScriptData */

/* ContentData
npc_00x09hl
npc_rinji
EndContentData */

#include "ScriptedPch.h"
#include "ScriptedEscortAI.h"

/*######
## npc_00x09hl
######*/

enum eOOX
{
    SAY_OOX_START           = -1000287,
    SAY_OOX_AGGRO1          = -1000288,
    SAY_OOX_AGGRO2          = -1000289,
    SAY_OOX_AMBUSH          = -1000290,
    SAY_OOX_END             = -1000292,

    QUEST_RESQUE_OOX_09     = 836,

    NPC_MARAUDING_OWL       = 7808,
    NPC_VILE_AMBUSHER       = 7809,

    FACTION_ESCORTEE_A      = 774,
    FACTION_ESCORTEE_H      = 775
};

struct npc_00x09hlAI : public npc_escortAI
{
    npc_00x09hlAI(Creature* pCreature) : npc_escortAI(pCreature) { }

    void Reset() { }

    void WaypointReached(uint32 uiPointId)
    {
        switch(uiPointId)
        {
            case 26:
                DoScriptText(SAY_OOX_AMBUSH, m_creature);
                break;
            case 43:
                DoScriptText(SAY_OOX_AMBUSH, m_creature);
                break;
            case 64:
                DoScriptText(SAY_OOX_END, m_creature);
                if (Player* pPlayer = GetPlayerForEscort())
                    pPlayer->GroupEventHappens(QUEST_RESQUE_OOX_09, m_creature);
                break;
        }
    }

    void WaypointStart(uint32 uiPointId)
    {
        switch(uiPointId)
        {
            case 27:
                for (uint8 i = 0; i < 3; ++i)
                {
                    const Position src = {147.927444f, -3851.513428f, 130.893f, 0};
                    Position pos;
                    me->GetRandomNearPosition(pos, 7.0f);
                    DoSummon(NPC_MARAUDING_OWL, pos, 25000, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                }
                break;
            case 44:
                for (uint8 i = 0; i < 3; ++i)
                {
                    const Position src = {-141.151581f, -4291.213867f, 120.130f, 0};
                    Position dst;
                    m_creature->GetRandomPoint(src, 7.0f, dst);
                    m_creature->SummonCreature(NPC_VILE_AMBUSHER, dst, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 25000);
                }
                break;
        }
    }

    void Aggro(Unit* pWho)
    {
        if (pWho->GetEntry() == NPC_MARAUDING_OWL || pWho->GetEntry() == NPC_VILE_AMBUSHER)
            return;

        if (rand()%1)
            DoScriptText(SAY_OOX_AGGRO1, m_creature);
        else
            DoScriptText(SAY_OOX_AGGRO2, m_creature);
    }

    void JustSummoned(Creature* pSummoned)
    {
        pSummoned->GetMotionMaster()->MovePoint(0, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ());
    }
};

bool QuestAccept_npc_00x09hl(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_RESQUE_OOX_09)
    {
        pCreature->SetStandState(UNIT_STAND_STATE_STAND);

        if (pPlayer->GetTeam() == ALLIANCE)
            pCreature->setFaction(FACTION_ESCORTEE_A);
        else if (pPlayer->GetTeam() == HORDE)
            pCreature->setFaction(FACTION_ESCORTEE_H);

        DoScriptText(SAY_OOX_START, pCreature, pPlayer);

        if (npc_00x09hlAI* pEscortAI = CAST_AI(npc_00x09hlAI, pCreature->AI()))
            pEscortAI->Start(false, false, pPlayer->GetGUID(), pQuest);
    }
    return true;
}

CreatureAI* GetAI_npc_00x09hl(Creature* pCreature)
{
    return new npc_00x09hlAI(pCreature);
}

/*######
## npc_rinji
######*/

enum eRinji
{
    SAY_RIN_FREE            = -1000403, //from here
    SAY_RIN_BY_OUTRUNNER    = -1000404,
    SAY_RIN_HELP_1          = -1000405,
    SAY_RIN_HELP_2          = -1000406, //to here, are used also by 6182 but this is wrong...
    SAY_RIN_COMPLETE        = -1000407,
    SAY_RIN_PROGRESS_1      = -1000408,
    SAY_RIN_PROGRESS_2      = -1000409,

    QUEST_RINJI_TRAPPED     = 2742,
    NPC_RANGER              = 2694,
    NPC_OUTRUNNER           = 2691,
    GO_RINJI_CAGE           = 142036
};

struct Location
{
    float m_fX, m_fY, m_fZ;
};

Location m_afAmbushSpawn[] =
{
    {191.296204, -2839.329346, 107.388},
    {70.972466,  -2848.674805, 109.459}
};

Location m_afAmbushMoveTo[] =
{
    {166.630386, -2824.780273, 108.153},
    {70.886589,  -2874.335449, 116.675}
};

struct npc_rinjiAI : public npc_escortAI
{
    npc_rinjiAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        m_bIsByOutrunner = false;
        m_iSpawnId = 0;
    }

    bool m_bIsByOutrunner;
    uint32 m_uiPostEventCount;
    uint32 m_uiPostEventTimer;
    int m_iSpawnId;

    void Reset()
    {
        m_uiPostEventCount = 0;
        m_uiPostEventTimer = 3000;
    }

    void JustRespawned()
    {
        m_bIsByOutrunner = false;
        m_iSpawnId = 0;

        npc_escortAI::JustRespawned();
    }

    void EnterCombat(Unit* pWho)
    {
        if (HasEscortState(STATE_ESCORT_ESCORTING))
        {
            if (pWho->GetEntry() == NPC_OUTRUNNER && !m_bIsByOutrunner)
            {
                DoScriptText(SAY_RIN_BY_OUTRUNNER, pWho);
                m_bIsByOutrunner = true;
            }

            if (rand()%4)
                return;

            //only if attacked and escorter is not in combat?
            DoScriptText(RAND(SAY_RIN_HELP_1,SAY_RIN_HELP_2), m_creature);
        }
    }

    void DoSpawnAmbush(bool bFirst)
    {
        if (!bFirst)
            m_iSpawnId = 1;

        m_creature->SummonCreature(NPC_RANGER,
            m_afAmbushSpawn[m_iSpawnId].m_fX, m_afAmbushSpawn[m_iSpawnId].m_fY, m_afAmbushSpawn[m_iSpawnId].m_fZ, 0.0f,
            TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60000);

        for (int i = 0; i < 2; ++i)
        {
            m_creature->SummonCreature(NPC_OUTRUNNER,
                m_afAmbushSpawn[m_iSpawnId].m_fX, m_afAmbushSpawn[m_iSpawnId].m_fY, m_afAmbushSpawn[m_iSpawnId].m_fZ, 0.0f,
                TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60000);
        }
    }

    void JustSummoned(Creature* pSummoned)
    {
        pSummoned->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
        pSummoned->GetMotionMaster()->MovePoint(0, m_afAmbushMoveTo[m_iSpawnId].m_fX, m_afAmbushMoveTo[m_iSpawnId].m_fY, m_afAmbushMoveTo[m_iSpawnId].m_fZ);
    }

    void WaypointReached(uint32 uiPointId)
    {
        Player* pPlayer = GetPlayerForEscort();

        if (!pPlayer)
            return;

        switch(uiPointId)
        {
            case 1:
                DoScriptText(SAY_RIN_FREE, m_creature, pPlayer);
                break;
            case 7:
                DoSpawnAmbush(true);
                break;
            case 13:
                DoSpawnAmbush(false);
                break;
            case 17:
                DoScriptText(SAY_RIN_COMPLETE, m_creature, pPlayer);
                pPlayer->GroupEventHappens(QUEST_RINJI_TRAPPED, m_creature);
                SetRun();
                m_uiPostEventCount = 1;
                break;
        }
    }

    void UpdateEscortAI(const uint32 uiDiff)
    {
        //Check if we have a current target
        if (!UpdateVictim())
        {
            if (HasEscortState(STATE_ESCORT_ESCORTING) && m_uiPostEventCount)
            {
                if (m_uiPostEventTimer <= uiDiff)
                {
                    m_uiPostEventTimer = 3000;

                    if (Unit* pPlayer = GetPlayerForEscort())
                    {
                        switch(m_uiPostEventCount)
                        {
                            case 1:
                                DoScriptText(SAY_RIN_PROGRESS_1, m_creature, pPlayer);
                                ++m_uiPostEventCount;
                                break;
                            case 2:
                                DoScriptText(SAY_RIN_PROGRESS_2, m_creature, pPlayer);
                                m_uiPostEventCount = 0;
                                break;
                        }
                    }
                    else
                    {
                        m_creature->ForcedDespawn();
                        return;
                    }
                }
                else
                    m_uiPostEventTimer -= uiDiff;
            }

            return;
        }

        DoMeleeAttackIfReady();
    }
};

bool QuestAccept_npc_rinji(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_RINJI_TRAPPED)
    {
        if (GameObject* pGo = pCreature->FindNearestGameObject(GO_RINJI_CAGE, INTERACTION_DISTANCE))
            pGo->UseDoorOrButton();

        if (npc_rinjiAI* pEscortAI = CAST_AI(npc_rinjiAI, pCreature->AI()))
            pEscortAI->Start(false, false, pPlayer->GetGUID(), pQuest);
    }
    return true;
}

CreatureAI* GetAI_npc_rinji(Creature* pCreature)
{
    return new npc_rinjiAI(pCreature);
}

void AddSC_hinterlands()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_00x09hl";
    newscript->GetAI = &GetAI_npc_00x09hl;
    newscript->pQuestAccept = &QuestAccept_npc_00x09hl;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_rinji";
    newscript->GetAI = &GetAI_npc_rinji;
    newscript->pQuestAccept = &QuestAccept_npc_rinji;
    newscript->RegisterSelf();
}
