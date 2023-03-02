/* This file is part of the ScriptDev2 Project. See AUTHORS file for Copyright information
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
SDName: Razorfen_Kraul
SD%Complete: 100
SDComment: Quest support: 1144, 1221
SDCategory: Razorfen Kraul
EndScriptData */

/* ContentData
quest_willix_the_importer
EndContentData */

#include "scriptPCH.h"

/*######
## npc_willix_the_importer
######*/

enum
{
    QUEST_WILLIX_THE_IMPORTER  = 1144,

    SAY_WILLIX_READY           = -1047000,
    SAY_WILLIX_1               = -1047001,
    SAY_WILLIX_2               = -1047002,
    SAY_WILLIX_3               = -1047003,
    SAY_WILLIX_4               = -1047004,
    SAY_WILLIX_5               = -1047005,
    SAY_WILLIX_6               = -1047006,
    SAY_WILLIX_7               = -1047007,
    SAY_WILLIX_END             = -1047008,

    SAY_WILLIX_AGGRO_1         = -1047009,
    SAY_WILLIX_AGGRO_2         = -1047010,
    SAY_WILLIX_AGGRO_3         = -1047011,
    SAY_WILLIX_AGGRO_4         = -1047012,

    NPC_RAGING_AGAMAR          = 4514
};

static float const aBoarSpawn[4][3] =
{
    {2151.420f, 1733.18f, 52.10f},
    {2144.463f, 1726.89f, 51.93f},
    {1956.433f, 1597.97f, 81.75f},
    {1958.971f, 1599.01f, 81.44f}
};

struct npc_willix_the_importerAI : public npc_escortAI
{
    npc_willix_the_importerAI(Creature* m_creature) : npc_escortAI(m_creature)
    {
        Reset();
    }

    void Reset() override {}

    void JustRespawned() override
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
        npc_escortAI::JustRespawned();
    }

    // Exact use of these texts remains unknown, it seems that he should only talk when he initiates the attack or he is the first who is attacked by a npc
    void Aggro(Unit* pWho) override
    {
        switch (urand(0, 6))                                // Not always said
        {
            case 0:
                DoScriptText(SAY_WILLIX_AGGRO_1, m_creature, pWho);
                break;
            case 1:
                DoScriptText(SAY_WILLIX_AGGRO_2, m_creature, pWho);
                break;
            case 2:
                DoScriptText(SAY_WILLIX_AGGRO_3, m_creature, pWho);
                break;
            case 3:
                DoScriptText(SAY_WILLIX_AGGRO_4, m_creature, pWho);
                break;
        }
    }

    void JustSummoned(Creature* pSummoned) override
    {
        pSummoned->AI()->AttackStart(m_creature);
    }

    void WaypointReached(uint32 uiPointId) override
    {
        switch (uiPointId)
        {
            case 2:
                DoScriptText(SAY_WILLIX_1, m_creature);
                break;
            case 6:
                DoScriptText(SAY_WILLIX_2, m_creature);
                break;
            case 9:
                DoScriptText(SAY_WILLIX_3, m_creature);
                break;
            case 14:
                DoScriptText(SAY_WILLIX_4, m_creature);
                // Summon 2 boars on the pathway
                m_creature->SummonCreature(NPC_RAGING_AGAMAR, aBoarSpawn[0][0], aBoarSpawn[0][1], aBoarSpawn[0][2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                m_creature->SummonCreature(NPC_RAGING_AGAMAR, aBoarSpawn[1][0], aBoarSpawn[1][1], aBoarSpawn[1][2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                break;
            case 25:
                DoScriptText(SAY_WILLIX_5, m_creature);
                break;
            case 33:
                DoScriptText(SAY_WILLIX_6, m_creature);
                break;
            case 44:
                DoScriptText(SAY_WILLIX_7, m_creature);
                // Summon 2 boars at the end
                m_creature->SummonCreature(NPC_RAGING_AGAMAR, aBoarSpawn[2][0], aBoarSpawn[2][1], aBoarSpawn[2][2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                m_creature->SummonCreature(NPC_RAGING_AGAMAR, aBoarSpawn[3][0], aBoarSpawn[3][1], aBoarSpawn[3][2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                break;
            case 45:
                DoScriptText(SAY_WILLIX_END, m_creature);
                m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                // Complete event
                if (Player* pPlayer = GetPlayerForEscort())
                    pPlayer->GroupEventHappens(QUEST_WILLIX_THE_IMPORTER, m_creature);
                SetEscortPaused(true);
                break;
        }
    }
};

CreatureAI* GetAI_npc_willix_the_importer(Creature* pCreature)
{
    return new npc_willix_the_importerAI(pCreature);
}

bool QuestAccept_npc_willix_the_importer(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_WILLIX_THE_IMPORTER)
    {
        if (npc_willix_the_importerAI* pEscortAI = dynamic_cast<npc_willix_the_importerAI*>(pCreature->AI()))
        {
            // After 4.0.1 set run = true
            pEscortAI->Start(false, pPlayer->GetGUID(), pQuest);
            DoScriptText(SAY_WILLIX_READY, pCreature, pPlayer);
            pCreature->SetFactionTemporary(FACTION_ESCORT_N_NEUTRAL_PASSIVE, TEMPFACTION_RESTORE_RESPAWN);
            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
        }
    }

    return true;
}

/*######
## npc_snufflenose_gopher
######*/

enum
{
    SPELL_SNUFFLENOSE_COMMAND   = 8283,
    NPC_SNUFFLENOSE_GOPHER      = 4781,
    GO_BLUELEAF_TUBER           = 20920,

    SAY_GOPHER_SPAWN            = -1780223,
    SAY_GOPHER_COMMAND          = -1780224,
    SAY_GOPHER_FOUND            = -1780225
};

struct npc_snufflenose_gopherAI : public FollowerAI
{
    npc_snufflenose_gopherAI(Creature* pCreature) :  FollowerAI(pCreature)
    {
        Reset();
        DoScriptText(SAY_GOPHER_SPAWN, m_creature);

        // Follow player by default
        if (Unit* unitOwner = m_creature->GetOwner())
            if (Player* owner = unitOwner->ToPlayer())
                StartFollow(owner);

        SetFollowPaused(true);
    }

    bool m_bIsMovementActive;

    ObjectGuid m_targetTuberGuid;
    GuidList m_foundTubers;
    uint32 m_followPausedTimer;

    void Reset() override
    {
        m_creature->SetFactionTemplateId(35);
        m_bIsMovementActive  = false;
        m_followPausedTimer = 3000;
    }

    void MovementInform(uint32 uiMoveType, uint32 uiPointId) override
    {
        if (uiMoveType != POINT_MOTION_TYPE || !uiPointId)
            return;

        if (!HasFollowState(STATE_FOLLOW_PAUSED))
            return;

        if (GameObject* pGo = m_creature->GetMap()->GetGameObject(m_targetTuberGuid))
        {
            pGo->SetRespawnTime(3 * MINUTE);
            pGo->Refresh();

            pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
            m_foundTubers.push_back(m_targetTuberGuid);
        }

        // Wait for 5 seconds after uncovering tuber before following again
        m_followPausedTimer = 5000; 
        m_bIsMovementActive = false;
    }

    // Function to search for new tuber in range
    void DoFindNewTuber()
    {   
        std::list<GameObject*> lTubersInRange;
        GetGameObjectListWithEntryInGrid(lTubersInRange, m_creature, GO_BLUELEAF_TUBER, 60.0f);

        if (lTubersInRange.empty())
            return;

        lTubersInRange.sort(ObjectDistanceOrder(m_creature));
        GameObject* pNearestTuber = nullptr;

        // Always need to find new ones
        for (const auto itr : lTubersInRange)
        {
            if (IsValidTuber(itr))
            {
                pNearestTuber = itr;
                break;
            }

        }

        if (!pNearestTuber)
            return;

        DoScriptText(SAY_GOPHER_FOUND, m_creature);

        m_targetTuberGuid = pNearestTuber->GetObjectGuid();

        float fX, fY, fZ;
        pNearestTuber->GetContactPoint(m_creature, fX, fY, fZ);
        m_creature->GetMotionMaster()->MovePoint(1, fX, fY, fZ);
        m_bIsMovementActive = true;
        SetFollowPaused(true);
    }

    bool IsValidTuber(GameObject* tuber)
    {
        Unit* viewPoint = m_creature;

        // Do LOS checks from Player if exists
        if (Unit* owner = m_creature->GetOwner())
            viewPoint = owner;

        if (tuber->isSpawned() || !tuber->HasFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND) || !tuber->IsWithinLOSInMap(viewPoint))
            return false;

        // Check if tuber is in list of already found tubers
        for (const auto& guid : m_foundTubers)
            if (tuber->GetObjectGuid() == guid)
                return false;

        // Check that tuber is not more than 15 yards above or below current position
        return fabs(viewPoint->GetPositionZ() - tuber->GetPositionZ()) <= 15;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_bIsMovementActive)
            return;

        if (m_followPausedTimer < uiDiff)
            SetFollowPaused(false);
        else
            m_followPausedTimer -= uiDiff;

        FollowerAI::UpdateAI(uiDiff);
    }

};

CreatureAI* GetAI_npc_snufflenose_gopher(Creature* pCreature)
{
    return new npc_snufflenose_gopherAI(pCreature);
}

bool EffectDummyCreature_npc_snufflenose_gopher(WorldObject* pCaster, uint32 uiSpellId, SpellEffectIndex uiEffIndex, Creature* pCreatureTarget)
{
    Unit* pUnit = pCaster->ToUnit();
    if (!pUnit)
        return false;

    // always check spellid and effectindex
    if (uiSpellId == SPELL_SNUFFLENOSE_COMMAND && uiEffIndex == EFFECT_INDEX_0)
    {
        if (pCreatureTarget->GetEntry() == NPC_SNUFFLENOSE_GOPHER)
        {
            // Do nothing if player has not targeted gopher
            if (pUnit->GetTargetGuid() != pCreatureTarget->GetObjectGuid())
            {
                // Send Spell_FAILED_BAD_TARGETS
                pCreatureTarget->SendPetCastFail(uiSpellId, (SpellCastResult)0x0A);
                return false;
            }

            DoScriptText(SAY_GOPHER_COMMAND, pCreatureTarget, pUnit);

            if (npc_snufflenose_gopherAI* pGopherAI = dynamic_cast<npc_snufflenose_gopherAI*>(pCreatureTarget->AI()))
            {
                if (pGopherAI->HasFollowState(STATE_FOLLOW_PAUSED))
                {
                    pGopherAI->SetFollowPaused(false);
                    pGopherAI->m_bIsMovementActive = false;
                    pGopherAI->m_targetTuberGuid = 0;
                }
                else
                    pGopherAI->DoFindNewTuber();
            }
        }
        // always return true when we are handling this spell and effect
        return true;
    }

    return false;
}

enum
{
    SPELL_DEFENSIVE_STANCE       =   7164,
    SPELL_IMPROVED_BLOCKING      =   3248,
    SPELL_SHIELD_BASH            =   11972,

};

struct RazorfenDefenderAI : public ScriptedAI
{
    RazorfenDefenderAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiImprovedBlocking_Timer;
    uint32 m_uiShieldBash_Timer;

    void Reset() override
    {
        m_uiImprovedBlocking_Timer = 1000;
        m_uiShieldBash_Timer      = 6600;
        DoCastSpellIfCan(m_creature, SPELL_DEFENSIVE_STANCE, true);
    }

    void Aggro(Unit* pWho) override
    {
        m_creature->SetInCombatWithZone();
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiShieldBash_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHIELD_BASH) == CAST_OK)
                m_uiShieldBash_Timer = 8100;
        }
        else
            m_uiShieldBash_Timer -= uiDiff;

        if (m_uiImprovedBlocking_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_IMPROVED_BLOCKING, true) == CAST_OK)
                m_uiImprovedBlocking_Timer = urand(6000, 9000);
        }
        else
            m_uiImprovedBlocking_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_RazorfenDefenderAI(Creature* pCreature)
{
    return new RazorfenDefenderAI(pCreature);
}

void AddSC_razorfen_kraul()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "razorfen_defender";
    pNewScript->GetAI = &GetAI_RazorfenDefenderAI;
    pNewScript->RegisterSelf();


    pNewScript = new Script;
    pNewScript->Name = "npc_willix_the_importer";
    pNewScript->GetAI = &GetAI_npc_willix_the_importer;
    pNewScript->pQuestAcceptNPC = &QuestAccept_npc_willix_the_importer;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_snufflenose_gopher";
    pNewScript->GetAI = &GetAI_npc_snufflenose_gopher;
    pNewScript->pEffectDummyCreature = &EffectDummyCreature_npc_snufflenose_gopher;
    pNewScript->RegisterSelf();
}
