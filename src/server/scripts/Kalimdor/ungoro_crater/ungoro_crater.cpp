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
SDName: Ungoro_Crater
SD%Complete: 100
SDComment: Quest support: 4245, 4491
SDCategory: Un'Goro Crater
EndScriptData */

/* ContentData
npc_ringo
EndContentData */

#include "scriptPCH.h"

/*######
## npc_ame01
######*/

enum
{
    SAY_AME_START           = -1000446,
    SAY_AME_PROGRESS        = -1000447,
    SAY_AME_END             = -1000448,
    SAY_AME_AGGRO1          = -1000449,
    SAY_AME_AGGRO2          = -1000450,
    SAY_AME_AGGRO3          = -1000451,

    FACTION_ESCORTEE        = 113,
    QUEST_CHASING_AME       = 4245
};

struct npc_ame01AI : public npc_escortAI
{
    npc_ame01AI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        Reset();
    }

    void Reset() override { }

    void JustRespawned() override
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
        npc_escortAI::JustRespawned();
    }

    void WaypointReached(uint32 uiPointId) override
    {
        switch (uiPointId)
        {
            case 0:
                DoScriptText(SAY_AME_START, m_creature);
                break;
            case 19:
                DoScriptText(SAY_AME_PROGRESS, m_creature);
                break;
            case 37:
                DoScriptText(SAY_AME_END, m_creature);
                if (Player* pPlayer = GetPlayerForEscort())
                    pPlayer->GroupEventHappens(QUEST_CHASING_AME, m_creature);
                break;
        }
    }

    void Aggro(Unit* pWho) override
    {
        if (pWho->GetTypeId() == TYPEID_PLAYER)
            return;

        if (Player* pPlayer = GetPlayerForEscort())
        {
            if (pPlayer->GetVictim() && pPlayer->GetVictim() == pWho)
                return;

            switch (urand(0, 2))
            {
                case 0:
                    DoScriptText(SAY_AME_AGGRO1, m_creature);
                    break;
                case 1:
                    DoScriptText(SAY_AME_AGGRO2, m_creature);
                    break;
                case 2:
                    DoScriptText(SAY_AME_AGGRO3, m_creature);
                    break;
            }
        }
    }
};

bool QuestAccept_npc_ame01(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_CHASING_AME)
    {
        if (npc_ame01AI* pAmeAI = dynamic_cast<npc_ame01AI*>(pCreature->AI()))
        {
            pCreature->SetStandState(UNIT_STAND_STATE_STAND);
            pCreature->SetFactionTemporary(FACTION_ESCORTEE, TEMPFACTION_RESTORE_RESPAWN);
            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
            pAmeAI->Start(false, pPlayer->GetGUID(), pQuest);
        }
    }
    return true;
}

CreatureAI* GetAI_npc_ame01(Creature* pCreature)
{
    return new npc_ame01AI(pCreature);
}

/*####
# npc_ringo
####*/

enum
{
    SAY_RIN_START_1             = -1000416,
    SAY_RIN_START_2             = -1000417,

    SAY_FAINT_1                 = -1000418,
    SAY_FAINT_2                 = -1000419,
    SAY_FAINT_3                 = -1000420,
    SAY_FAINT_4                 = -1000421,

    SAY_WAKE_1                  = -1000422,
    SAY_WAKE_2                  = -1000423,
    SAY_WAKE_3                  = -1000424,
    SAY_WAKE_4                  = -1000425,

    SAY_RIN_END_1               = -1000426,
    SAY_SPR_END_2               = -1000427,
    SAY_RIN_END_3               = -1000428,
    EMOTE_RIN_END_4             = -1000429,
    EMOTE_RIN_END_5             = -1000430,
    SAY_RIN_END_6               = -1000431,
    SAY_SPR_END_7               = -1000432,
    EMOTE_RIN_END_8             = -1000433,

    SPELL_REVIVE_RINGO          = 15591,
    QUEST_A_LITTLE_HELP         = 4491,
    NPC_SPRAGGLE                = 9997
};

struct npc_ringoAI : public FollowerAI
{
    npc_ringoAI(Creature* pCreature) : FollowerAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiFaintTimer;
    uint32 m_uiEndEventProgress;
    uint32 m_uiEndEventTimer;

    Unit* pSpraggle;

    void Reset() override
    {
        m_uiFaintTimer = urand(30000, 60000);
        m_uiEndEventProgress = 0;
        m_uiEndEventTimer = 1000;
        pSpraggle = nullptr;
    }

    void JustRespawned() override
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
        FollowerAI::JustRespawned();
    }

    void MoveInLineOfSight(Unit *pWho) override
    {
        FollowerAI::MoveInLineOfSight(pWho);

        if (!m_creature->GetVictim() && !HasFollowState(STATE_FOLLOW_COMPLETE) && pWho->GetEntry() == NPC_SPRAGGLE)
        {
            if (m_creature->IsWithinDistInMap(pWho, INTERACTION_DISTANCE))
            {
                if (Player* pPlayer = GetLeaderForFollower())
                {
                    if (pPlayer->GetQuestStatus(QUEST_A_LITTLE_HELP) == QUEST_STATUS_INCOMPLETE)
                        pPlayer->GroupEventHappens(QUEST_A_LITTLE_HELP, m_creature);
                }

                pSpraggle = pWho;
                SetFollowComplete(true);
            }
        }
    }

    void SpellHit(Unit* pCaster, SpellEntry const* pSpell) override
    {
        if (HasFollowState(STATE_FOLLOW_INPROGRESS | STATE_FOLLOW_PAUSED) && pSpell->Id == SPELL_REVIVE_RINGO)
            ClearFaint();
    }

    void SetFaint()
    {
        if (!HasFollowState(STATE_FOLLOW_POSTEVENT))
        {
            SetFollowPaused(true);

            switch (urand(0, 3))
            {
                case 0:
                    DoScriptText(SAY_FAINT_1, m_creature);
                    break;
                case 1:
                    DoScriptText(SAY_FAINT_2, m_creature);
                    break;
                case 2:
                    DoScriptText(SAY_FAINT_3, m_creature);
                    break;
                case 3:
                    DoScriptText(SAY_FAINT_4, m_creature);
                    break;
            }
        }

        //what does actually happen here? Emote? Aura?
        m_creature->SetStandState(UNIT_STAND_STATE_SLEEP);
    }

    void ClearFaint()
    {
        m_creature->SetStandState(UNIT_STAND_STATE_STAND);

        if (HasFollowState(STATE_FOLLOW_POSTEVENT))
            return;

        switch (urand(0, 3))
        {
            case 0:
                DoScriptText(SAY_WAKE_1, m_creature);
                break;
            case 1:
                DoScriptText(SAY_WAKE_2, m_creature);
                break;
            case 2:
                DoScriptText(SAY_WAKE_3, m_creature);
                break;
            case 3:
                DoScriptText(SAY_WAKE_4, m_creature);
                break;
        }

        SetFollowPaused(false);
    }

    void UpdateFollowerAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        {
            if (HasFollowState(STATE_FOLLOW_POSTEVENT))
            {
                if (m_uiEndEventTimer < uiDiff)
                {
                    if (!pSpraggle || !pSpraggle->IsAlive())
                    {
                        SetFollowComplete();
                        return;
                    }

                    switch (m_uiEndEventProgress)
                    {
                        case 1:
                            DoScriptText(SAY_RIN_END_1, m_creature);
                            m_uiEndEventTimer = 3000;
                            break;
                        case 2:
                            DoScriptText(SAY_SPR_END_2, pSpraggle);
                            m_uiEndEventTimer = 5000;
                            break;
                        case 3:
                            DoScriptText(SAY_RIN_END_3, m_creature);
                            m_uiEndEventTimer = 1000;
                            break;
                        case 4:
                            DoScriptText(EMOTE_RIN_END_4, m_creature);
                            SetFaint();
                            m_uiEndEventTimer = 9000;
                            break;
                        case 5:
                            DoScriptText(EMOTE_RIN_END_5, m_creature);
                            ClearFaint();
                            m_uiEndEventTimer = 1000;
                            break;
                        case 6:
                            DoScriptText(SAY_RIN_END_6, m_creature);
                            m_uiEndEventTimer = 3000;
                            break;
                        case 7:
                            DoScriptText(SAY_SPR_END_7, pSpraggle);
                            m_uiEndEventTimer = 10000;
                            break;
                        case 8:
                            DoScriptText(EMOTE_RIN_END_8, m_creature);
                            m_uiEndEventTimer = 5000;
                            break;
                        case 9:
                            SetFollowComplete();
                            break;
                    }

                    ++m_uiEndEventProgress;
                }
                else
                    m_uiEndEventTimer -= uiDiff;
            }
            else if (HasFollowState(STATE_FOLLOW_INPROGRESS))
            {
                if (!HasFollowState(STATE_FOLLOW_PAUSED))
                {
                    if (m_uiFaintTimer < uiDiff)
                    {
                        SetFaint();
                        m_uiFaintTimer = urand(60000, 120000);
                    }
                    else
                        m_uiFaintTimer -= uiDiff;
                }
            }

            return;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_ringo(Creature* pCreature)
{
    return new npc_ringoAI(pCreature);
}

bool QuestAccept_npc_ringo(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_A_LITTLE_HELP)
    {
        if (npc_ringoAI* pRingoAI = dynamic_cast<npc_ringoAI*>(pCreature->AI()))
        {
            pCreature->SetStandState(UNIT_STAND_STATE_STAND);
            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
            pRingoAI->StartFollow(pPlayer, FACTION_ESCORTEE, pQuest);
        }
    }

    return true;
}

/*######
## at_scent_larkorwi
######*/

enum
{
    QUEST_SCENT_OF_LARKORWI     = 4291,
    NPC_LARKORWI_MATE           = 9683
};

bool AreaTrigger_at_scent_larkorwi(Player* pPlayer, AreaTriggerEntry const* pAt)
{
    if (pPlayer->IsAlive() && !pPlayer->IsGameMaster() && pPlayer->GetQuestStatus(QUEST_SCENT_OF_LARKORWI) == QUEST_STATUS_INCOMPLETE)
    {
        if (!GetClosestCreatureWithEntry(pPlayer, NPC_LARKORWI_MATE, 25.0f))
        {
            static std::unordered_map<uint32, time_t> cooldown;
            if (cooldown[pAt->id] < time(nullptr))
            {
                pPlayer->SummonCreature(NPC_LARKORWI_MATE, pAt->x, pAt->y, pAt->z, 3.3f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 2 * MINUTE * IN_MILLISECONDS);
                cooldown[pAt->id] = time(nullptr) + MINUTE;
            }
        }
    }

    return false;
}

enum
{
    SPELL_MERGING_OOZES = 16032,
    NPC_PRIMAL_OOZE = 6557
};

struct mob_captured_felwood_oozeAI : public ScriptedAI
{
    mob_captured_felwood_oozeAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }
    uint32 initialTimer;
    bool mergeDone;

    void Reset() override
    {
        initialTimer = 1000;
        mergeDone = false;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (initialTimer < uiDiff)
        {
            // If no Primal Ooze found within 30yd, instant despawn
            if (Creature* primalOoze = m_creature->FindNearestCreature(NPC_PRIMAL_OOZE, 30.0f))
                m_creature->GetMotionMaster()->MoveFollow(primalOoze, 2.0f, 0);
            else
                m_creature->DespawnOrUnsummon();

            initialTimer = 2000;
        }
        else
            initialTimer -= uiDiff;
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == FOLLOW_MOTION_TYPE && !mergeDone)
        {
            if (Creature* primalOoze = m_creature->FindNearestCreature(NPC_PRIMAL_OOZE, 5.0f))
                if (DoCastSpellIfCan(primalOoze, SPELL_MERGING_OOZES))
                    mergeDone = true;
        }
    }
};

CreatureAI* GetAI_mob_captured_felwood_ooze(Creature* pCreature)
{
    return new mob_captured_felwood_oozeAI(pCreature);
}

enum
{
    SPELL_FOOLS_PLIGHT              = 23504,
    SPELL_CHAIN_LIGHTNING           = 23206,
    SPELL_TEMPTRESS_KISS            = 23205,
    SPELL_SILENCE                   = 23207,
    
    EMOTE_SILENCE                   = -1000652,

    NPC_SIMONE_THE_INCONSPICUOUS    = 14527,
    NPC_SIMONE_THE_SEDUCTRESS       = 14533,
    NPC_PRECIOUS                    = 14528,
    NPC_PRECIOUS_THE_DEVOURER       = 14538,
    NPC_THE_CLEANER                 = 14503,

    QUEST_STAVE_OF_THE_ANCIENTS     = 7636
};

#define GOSSIP_ITEM                 "Show me your real face, demon."

/*######
## npc_precious_the_devourer 14538
######*/

struct npc_precious_the_devourerAI : public ScriptedAI
{
    npc_precious_the_devourerAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }
    
    ObjectGuid m_simoneGuid;
    uint32 m_uiSplitCheck_Timer;
    
    void Reset() override
    {
        m_creature->SetVisibility(VISIBILITY_ON);
        m_uiSplitCheck_Timer    = 7500;
    }

    void Aggro(Unit* pWho) override
    {
        if (Creature* pSimone = m_creature->GetMap()->GetCreature(m_simoneGuid))
        {
            if (pSimone->IsAlive())
            {
                pSimone->AI()->AttackStart(pWho);
            }
        }
    }
    
    void EnterEvadeMode() override
    {
        if (Creature* pSimone = m_creature->GetMap()->GetCreature(m_simoneGuid))
        {
            if (!pSimone->IsAlive())
            {
                m_creature->ForcedDespawn();
            }
        }
                
        ScriptedAI::EnterEvadeMode();
    }
    
    void DamageTaken(Unit* pDealer, uint32& /*uiDamage*/) override
    {
        if (Creature* pSimone = m_creature->GetMap()->GetCreature(m_simoneGuid))
        {
            if (pSimone->IsAlive())
                pSimone->UpdateLeashExtensionTime();
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        {
            if (m_uiSplitCheck_Timer < uiDiff) 
            {
                m_uiSplitCheck_Timer = 2500;
                if (Creature* pSimone = m_creature->GetMap()->GetCreature(m_simoneGuid))
                {
                    if (pSimone->IsInCombat())
                        pSimone->AI()->EnterEvadeMode();
                }
            }
            else
                m_uiSplitCheck_Timer -= uiDiff;
                
            return;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_precious_the_devourer(Creature* pCreature)
{
    return new npc_precious_the_devourerAI(pCreature);
}

/*######
## npc_simone_seductress 14533
######*/

struct npc_simone_seductressAI : public ScriptedAI
{
    npc_simone_seductressAI(Creature* pCreature) : ScriptedAI(pCreature) 
    {
        m_uiDespawn_Timer = 20*MINUTE*IN_MILLISECONDS;
        Reset();
    }

    ObjectGuid m_hunterGuid;
    ObjectGuid m_simoneGuid;
    ObjectGuid m_preciousGuid;

    uint32 m_uiTemptressKiss_Timer;
    uint32 m_uiLightingBolt_Timer;
    uint32 m_uiThreatCheck_Timer;
    uint32 m_uiSplitCheck_Timer;
    
    uint32 m_uiDespawn_Timer;

    void Reset() override
    {
        m_creature->SetVisibility(VISIBILITY_ON);
        
        m_hunterGuid.Clear();

        m_uiTemptressKiss_Timer = urand(3000, 6000);
        m_uiLightingBolt_Timer  = urand(3000, 6000);
        m_uiThreatCheck_Timer   = 5000;
        m_uiSplitCheck_Timer    = 7500;
    }
    
    void JustReachedHome() override
    {
        if (Creature* pPrecious = m_creature->GetMap()->GetCreature(m_preciousGuid))
        {
            if (!pPrecious->IsAlive())
            {
                pPrecious->ForcedDespawn();
                Creature* pPreciousNew = m_creature->SummonCreature(NPC_PRECIOUS_THE_DEVOURER,
                                         m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), m_creature->GetAngle(m_creature), TEMPSUMMON_DEAD_DESPAWN, 0, true);

                if (pPreciousNew)
                {
                    m_preciousGuid = pPreciousNew->GetObjectGuid();
                
                    if (npc_precious_the_devourerAI * pDevourer = dynamic_cast<npc_precious_the_devourerAI*> (pPreciousNew->AI()))
                        pDevourer->m_simoneGuid = m_creature->GetObjectGuid();
                }
            }
        }
        else
        {
            Creature* pPreciousNew = m_creature->SummonCreature(NPC_PRECIOUS_THE_DEVOURER,
                                     m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), m_creature->GetAngle(m_creature), TEMPSUMMON_DEAD_DESPAWN, 0, true);
                
            if (pPreciousNew)
            {
                m_preciousGuid = pPreciousNew->GetObjectGuid();
            
                if (npc_precious_the_devourerAI * pDevourer = dynamic_cast<npc_precious_the_devourerAI*> (pPreciousNew->AI()))
                    pDevourer->m_simoneGuid = m_creature->GetObjectGuid();
            }
        }
    
        Reset();
    }

    void Aggro(Unit* pWho) override
    {
        if (Creature* pPrecious = m_creature->GetMap()->GetCreature(m_preciousGuid))
        {
            if (pPrecious->IsAlive())
            {
                if (pWho)
                    pPrecious->AI()->AttackStart(pWho);
            }
        }

        if (pWho->GetClass() == CLASS_HUNTER && (m_hunterGuid.IsEmpty() || m_hunterGuid == pWho->GetObjectGuid())/*&& pWho->GetQuestStatus(QUEST_STAVE_OF_THE_ANCIENTS) == QUEST_STATUS_INCOMPLETE*/)
        {
            m_hunterGuid = pWho->GetObjectGuid();
        }
        else
            DemonDespawn();
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        if (Creature* pSimone = m_creature->GetMap()->GetCreature(m_simoneGuid))
        {
            // DRSS
            uint32 m_respawn_delay_Timer = 3*HOUR;
            if (sWorld.GetActiveSessionCount() > BLIZZLIKE_REALM_POPULATION)
                m_respawn_delay_Timer *= float(BLIZZLIKE_REALM_POPULATION) / float(sWorld.GetActiveSessionCount());

            pSimone->SetRespawnDelay(m_respawn_delay_Timer);
            pSimone->SetRespawnTime(m_respawn_delay_Timer);
            pSimone->SaveRespawnTime();
        }
    }
        
    void DemonDespawn(bool triggered = true)
    {
        if (Creature* pSimone = m_creature->GetMap()->GetCreature(m_simoneGuid))
        {
            pSimone->SetRespawnDelay(15*MINUTE);
            pSimone->SetRespawnTime(15*MINUTE);
            pSimone->SaveRespawnTime();
        }
        
        if (triggered)
        {
            Creature* pCleaner = m_creature->SummonCreature(NPC_THE_CLEANER, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), m_creature->GetAngle(m_creature), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 20*MINUTE*IN_MILLISECONDS);
            if (pCleaner)
            {
                ThreatList const& SimonetList = m_creature->GetThreatManager().getThreatList();
                
                for (const auto itr : SimonetList)
                {
                    if (Unit* pUnit = m_creature->GetMap()->GetUnit(itr->getUnitGuid()))
                    {
                        if (pUnit->IsAlive())
                        {
                            pCleaner->SetInCombatWith(pUnit);
                            pCleaner->AddThreat(pUnit);
                            pCleaner->AI()->AttackStart(pUnit);
                        }
                    }
                }
                
                if (Creature* pPrecious = m_creature->GetMap()->GetCreature(m_preciousGuid))
                {
                    ThreatList const& PrecioustList = pPrecious->GetThreatManager().getThreatList();
                
                    for (const auto itr : PrecioustList)
                    {
                        if (Unit* pUnit = m_creature->GetMap()->GetUnit(itr->getUnitGuid()))
                        {
                            if (pUnit->IsAlive())
                            {
                                pCleaner->SetInCombatWith(pUnit);
                                pCleaner->AddThreat(pUnit);
                                pCleaner->AI()->AttackStart(pUnit);
                            }
                        }
                    }
                }
            }
        }
        
        if (Creature* pPrecious = m_creature->GetMap()->GetCreature(m_preciousGuid))
        {
            pPrecious->SetVisibility(VISIBILITY_OFF);
            pPrecious->ForcedDespawn();
            pPrecious->RemoveFromWorld();
        }
        
        m_creature->SetVisibility(VISIBILITY_OFF);
        m_creature->ForcedDespawn();
        m_creature->RemoveFromWorld();
    }
    
    void DamageTaken(Unit* /*pDealer*/, uint32& /*uiDamage*/) override
    {
        if (Creature* pPrecious = m_creature->GetMap()->GetCreature(m_preciousGuid))
        {
            if (pPrecious->IsAlive())
                pPrecious->UpdateLeashExtensionTime();
        }
    }
    
    void SpellHit(Unit* /*pCaster*/, SpellEntry const* pSpell) override
    {
        if (pSpell && pSpell->Id == 14280)   // Viper Sting (Rank 3)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_SILENCE, CF_TRIGGERED) == CAST_OK)
                DoScriptText(EMOTE_SILENCE, m_creature);
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_uiDespawn_Timer < uiDiff)
        {
            if (m_creature->IsAlive() && !m_creature->IsInCombat())
                DemonDespawn(false);
        }
        else
            m_uiDespawn_Timer -= uiDiff;
    
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        {
            if (m_uiSplitCheck_Timer < uiDiff) 
            {
                m_uiSplitCheck_Timer = 2500;
                if (Creature* pPrecious = m_creature->GetMap()->GetCreature(m_preciousGuid))
                {
                    if (pPrecious->IsInCombat())
                        pPrecious->AI()->EnterEvadeMode();
                }
            }
            else
                m_uiSplitCheck_Timer -= uiDiff;
                
            return;
        }
        
        if (m_creature->GetThreatManager().getThreatList().size() > 1)
        {
            DemonDespawn();
        }
        if (m_uiThreatCheck_Timer < uiDiff) 
        {
            m_uiThreatCheck_Timer = 2000;
            if (Creature* pPrecious = m_creature->GetMap()->GetCreature(m_preciousGuid))
            {
                if (pPrecious->GetThreatManager().getThreatList().size() > 1 /*|| pHunter->IsDead()*/)
                    DemonDespawn();
            }
        }
        else
            m_uiThreatCheck_Timer -= uiDiff;

        if (m_uiTemptressKiss_Timer < uiDiff) 
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_TEMPTRESS_KISS) == CAST_OK)
                m_uiTemptressKiss_Timer = 45000;
        }
        else 
            m_uiTemptressKiss_Timer -= uiDiff;

        if (m_uiLightingBolt_Timer < uiDiff) 
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CHAIN_LIGHTNING) == CAST_OK)
                m_uiLightingBolt_Timer = urand(8000, 12000);
        } 
        else 
            m_uiLightingBolt_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_simone_seductress(Creature* pCreature)
{
    return new npc_simone_seductressAI(pCreature);
}

/*######
## npc_simone_the_inconspicuous 14527
######*/

struct npc_simone_the_inconspicuousAI : public ScriptedAI
{
    npc_simone_the_inconspicuousAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    uint32 m_uiFoolsPlight_Timer;
    uint32 m_uiTransform_Timer;
    uint32 m_uiTransformEmote_Timer;
    bool m_bTransform;

    ObjectGuid m_playerGuid;
    Creature* pPrecious;

    void Reset() override
    {
        m_creature->SetRespawnDelay(35*MINUTE);
        m_creature->SetRespawnTime(35*MINUTE);
    
        m_creature->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        m_creature->SetVisibility(VISIBILITY_ON);
        
        m_uiFoolsPlight_Timer    = urand(5000, 10000);
        m_uiTransform_Timer      = 10000;
        m_uiTransformEmote_Timer = 5000;
        m_bTransform             = false;

        if (pPrecious = GetClosestCreatureWithEntry(m_creature, NPC_PRECIOUS, 100.0f))
        {
            pPrecious->SetVisibility(VISIBILITY_ON);
            pPrecious->GetMotionMaster()->MoveFollow(m_creature, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
        }
        else
        {
           pPrecious = m_creature->SummonCreature(NPC_PRECIOUS, 
                       m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), m_creature->GetAngle(m_creature), TEMPSUMMON_DEAD_DESPAWN, 0);
           pPrecious->GetMotionMaster()->MoveFollow(m_creature, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
        }
    }
    
    void Transform()
    {
        if (Player* pPlayer = m_creature->GetMap()->GetPlayer(m_playerGuid))
        {
            Creature* pPreciousDevourer = nullptr;
            Creature* pDemon    = m_creature->SummonCreature(NPC_SIMONE_THE_SEDUCTRESS,
                                  m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), m_creature->GetAngle(m_creature), TEMPSUMMON_DEAD_DESPAWN, 0);
            Creature* pPrecious = GetClosestCreatureWithEntry(m_creature, NPC_PRECIOUS, 100.0f);
            
            if (pDemon)
            {
                if (npc_simone_seductressAI * pSimone = dynamic_cast<npc_simone_seductressAI*> (pDemon->AI())) 
                    pSimone->m_simoneGuid = m_creature->GetObjectGuid();

                m_creature->SetVisibility(VISIBILITY_OFF);
                m_creature->ForcedDespawn();
            }
                
            if (pDemon && pPrecious)
            {
                pPreciousDevourer = m_creature->SummonCreature(NPC_PRECIOUS_THE_DEVOURER,
                                    pPrecious->GetPositionX(), pPrecious->GetPositionY(), pPrecious->GetPositionZ(), pPrecious->GetAngle(pPrecious), TEMPSUMMON_DEAD_DESPAWN, 0, true);
                
                if (pPreciousDevourer)
                {
                    if (npc_simone_seductressAI * pSimone = dynamic_cast<npc_simone_seductressAI*> (pDemon->AI()))
                        pSimone->m_preciousGuid = pPreciousDevourer->GetObjectGuid();
                    
                    if (npc_precious_the_devourerAI * pDevourer = dynamic_cast<npc_precious_the_devourerAI*> (pPreciousDevourer->AI()))
                        pDevourer->m_simoneGuid = pDemon->GetObjectGuid();
                }
                
                pPrecious->SetVisibility(VISIBILITY_OFF);
                pPrecious->ForcedDespawn();
            }
        }
    }

    void BeginEvent(ObjectGuid playerGuid)
    {
        m_playerGuid = playerGuid;
        m_creature->GetMotionMaster()->MoveIdle();
        m_creature->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
        m_bTransform = true;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_bTransform) 
        {
            if (m_uiTransformEmote_Timer)
            {
                if (m_uiTransformEmote_Timer <= uiDiff)
                {
                    m_creature->HandleEmote(EMOTE_ONESHOT_SHOUT);
                    m_uiTransformEmote_Timer = 0;
                }
                else
                    m_uiTransformEmote_Timer -= uiDiff;
            }

            if (m_uiTransform_Timer < uiDiff) 
            {
                m_bTransform = false;
                Transform();
            } 
            else 
                m_uiTransform_Timer -= uiDiff;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiFoolsPlight_Timer < uiDiff) 
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FOOLS_PLIGHT) == CAST_OK)
                m_uiFoolsPlight_Timer = urand(5000, 10000);
        } 
        else 
            m_uiFoolsPlight_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

bool GossipHello_npc_simone_the_inconspicuous(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_STAVE_OF_THE_ANCIENTS) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_ITEM , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetObjectGuid());
    return true;
}

bool GossipSelect_npc_simone_the_inconspicuous(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction )
{
    pPlayer->CLOSE_GOSSIP_MENU();
    ((npc_simone_the_inconspicuousAI*)pCreature->AI())->BeginEvent(pPlayer->GetObjectGuid());
    pCreature->HandleEmote(EMOTE_ONESHOT_LAUGH);
    return true;
}

CreatureAI* GetAI_npc_simone_the_inconspicuous(Creature* pCreature)
{
    return new npc_simone_the_inconspicuousAI(pCreature);
}

void AddSC_ungoro_crater()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_ame01";
    newscript->GetAI = &GetAI_npc_ame01;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_ame01;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_ringo";
    newscript->GetAI = &GetAI_npc_ringo;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_ringo;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "at_scent_larkorwi";
    newscript->pAreaTrigger = &AreaTrigger_at_scent_larkorwi;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_simone_seductress";
    newscript->GetAI = &GetAI_npc_simone_seductress;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_simone_the_inconspicuous";
    newscript->GetAI = &GetAI_npc_simone_the_inconspicuous;
    newscript->pGossipHello =  &GossipHello_npc_simone_the_inconspicuous;
    newscript->pGossipSelect = &GossipSelect_npc_simone_the_inconspicuous;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_precious_the_devourer";
    newscript->GetAI = &GetAI_npc_precious_the_devourer;    
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_captured_felwood_ooze";
    newscript->GetAI = &GetAI_mob_captured_felwood_ooze;
    newscript->RegisterSelf();
}
