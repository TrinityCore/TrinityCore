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
SDComment: Quest support: 2742
SDCategory: The Hinterlands
EndScriptData */

/* ContentData
npc_rinji
EndContentData */

#include "precompiled.h"
#include "escortAI.h"

/*######
## npc_rinji
######*/

enum
{
    SAY_RIN_FREE            = -1000403,
    SAY_RIN_BY_OUTRUNNER    = -1000404,
    SAY_RIN_HELP_1          = -1000405,
    SAY_RIN_HELP_2          = -1000406,
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

struct TRINITY_DLL_DECL npc_rinjiAI : public npc_escortAI
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
        if (IsBeingEscorted)
        {
            if (pWho->GetEntry() == NPC_OUTRUNNER && !m_bIsByOutrunner)
            {
                DoScriptText(SAY_RIN_BY_OUTRUNNER, pWho);
                m_bIsByOutrunner = true;
            }

            if (rand()%4)
                return;

            //only if attacked and escorter is not in combat?
            switch(rand()%2)
            {
                case 0: DoScriptText(SAY_RIN_HELP_1, m_creature); break;
                case 1: DoScriptText(SAY_RIN_HELP_2, m_creature); break;
            }
        }
    }

    void DoSpawnAmbush(bool bFirst)
    {
        if (!bFirst)
            m_iSpawnId = 1;

        m_creature->SummonCreature(NPC_RANGER,
            m_afAmbushSpawn[m_iSpawnId].m_fX, m_afAmbushSpawn[m_iSpawnId].m_fY, m_afAmbushSpawn[m_iSpawnId].m_fZ, 0.0f,
            TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60000);

        for(int i = 0; i < 2; ++i)
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
        Player* pPlayer = (Player*)Unit::GetUnit(*m_creature, PlayerGUID);

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

    void UpdateAI(const uint32 uiDiff)
    {
        npc_escortAI::UpdateAI(uiDiff);

        if (IsBeingEscorted && m_uiPostEventCount && !m_creature->getVictim())
        {
            if (m_uiPostEventTimer < uiDiff)
            {
                m_uiPostEventTimer = 3000;

                if (Unit* pPlayer = Unit::GetUnit(*m_creature, PlayerGUID))
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
    npc_rinjiAI* pTempAI = new npc_rinjiAI(pCreature);

    pTempAI->FillPointMovementListForCreature();

    return (CreatureAI*)pTempAI;
}

void AddSC_hinterlands()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_rinji";
    newscript->GetAI = &GetAI_npc_rinji;
    newscript->pQuestAccept = &QuestAccept_npc_rinji;
    newscript->RegisterSelf();
}
