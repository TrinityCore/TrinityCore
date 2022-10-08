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
SDName: Boss_Sartura
SD%Complete: 95
SDComment:
SDCategory: Temple of Ahn'Qiraj
EndScriptData */

/*
 * Notes:
 * Whirlwind - Sartura does a physical AoE that does 3k+ damage to everyone within 10 yards of her.
 * During this time she is immune to stuns and taunt. She tends to use this ability after a stun fades.
 */

#include "scriptPCH.h"
#include "temple_of_ahnqiraj.h"

enum
{
    SAY_AGGRO                       = -1531008,
    SAY_SLAY                        = -1531009,
    SAY_DEATH                       = -1531010,

    SPELL_WHIRLWIND                 = 26083,

    // Sartura
    SPELL_CLEAVE                    = 25174,
    SPELL_ENRAGE                    = 26527,
    SPELL_ENRAGEHARD                = 27680,

    TAUNT_IMMUNE                    = 26602,

    EMOTE_ENRAGE                    = -1000003,
    EMOTE_ENRAGEHARD                = -1000004,

    // Royal Guard
    SPELL_KNOCKBACK                 = 19813,
    SPELL_GUARD_WHIRLWIND            = 26038,

};

// ********************
// Battleguard Sartura
// ********************

struct boss_sarturaAI : public ScriptedAI
{
    boss_sarturaAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_temple_of_ahnqiraj*)pCreature->GetInstanceData();
        Reset();
    }

    instance_temple_of_ahnqiraj* m_pInstance;

    uint32 m_uiCleaveTimer;
    uint32 m_uiWhirlWindTimer;
    uint32 m_uiWhirlWindEndTimer;           //15s
    uint32 m_uiAggroResetTimer;
    uint32 m_uiEnrageHardTimer;
    uint32 m_uiEvadeCheckTimer;

    bool m_bIsEnraged;
    bool m_bAttackOff;

    void Reset() override
    {
        m_uiCleaveTimer = 4000;
        m_uiWhirlWindTimer = urand(8000, 12000);;
        m_uiWhirlWindEndTimer = 0;
        m_uiAggroResetTimer = urand(5000, 7500);
        
        m_uiEnrageHardTimer = 10 * 60000;
        m_bIsEnraged = false;
        m_bAttackOff = false;

        m_uiEvadeCheckTimer = 2500;
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        // Sartura has a very large aggro radius
        if (pWho->GetTypeId() == TYPEID_PLAYER && !m_creature->IsInCombat() && m_creature->IsWithinDistInMap(pWho, 85.0f) && m_creature->IsWithinLOSInMap(pWho) && !pWho->HasAuraType(SPELL_AURA_FEIGN_DEATH))
        {
            AttackStart(pWho);
        }
        ScriptedAI::MoveInLineOfSight(pWho);
    }

    void EnterEvadeMode() override
    {
        LeashEncounter();
        ScriptedAI::EnterEvadeMode();
    }

    void Aggro(Unit* /*pWho*/) override
    {
        DoScriptText(SAY_AGGRO, m_creature);
        m_creature->SetInCombatWithZone();

        if (m_pInstance)
            m_pInstance->SetData(TYPE_SARTURA, IN_PROGRESS);
    }

    void KilledUnit(Unit* /*pVictim*/) override
    {
        DoScriptText(SAY_SLAY, m_creature);
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_SARTURA, DONE);
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_SARTURA, FAIL);
    }

    void AssignRandomThreat()
    {
        if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
        {
            if (m_creature->IsWithinDist(pTarget, VISIBLE_RANGE))
            {
                DoResetThreat();
                m_creature->GetThreatManager().addThreatDirectly(pTarget, urand(1000, 2000));
            }
        }
    }

    void LeashEncounter()
    {
        GuidList m_lRoyalGuardsGuid;
        m_pInstance->GetRoyalGuardGUIDList(m_lRoyalGuardsGuid);
        for (const auto& guid : m_lRoyalGuardsGuid)
        {
            if (Creature* pRoyalGuard = m_creature->GetMap()->GetCreature(guid))
            {
                if (pRoyalGuard->IsDead()) pRoyalGuard->Respawn(); else pRoyalGuard->AI()->EnterEvadeMode();
            }
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiWhirlWindEndTimer)                          // Is in Whirlwind
        {
            // While in whirlwind, switch to random targets often
            if (m_uiAggroResetTimer < uiDiff)
            {
                AssignRandomThreat();
                m_uiAggroResetTimer = urand(1000, 2000);
            }
            else
                m_uiAggroResetTimer -= uiDiff;

            // End Whirlwind Phase
            if (m_uiWhirlWindEndTimer <= uiDiff)
            {
                m_uiWhirlWindEndTimer = 0;
                m_uiWhirlWindTimer = urand(5000, 10000);
                m_uiAggroResetTimer = urand(3000, 7000); 
                // Remove the negative haste modifier from Whirlwind to restore Sartura's auto attack
                m_creature->ApplyAttackTimePercentMod(BASE_ATTACK, 0, true);
                m_creature->SetAttackTimer(BASE_ATTACK, 100);
                m_creature->RemoveAurasByCasterSpell(TAUNT_IMMUNE, m_creature->GetObjectGuid());
            }
            else
                m_uiWhirlWindEndTimer -= uiDiff;
        }
        else // if (!m_uiWhirlWindEndTimer)                 // Is not in whirlwind
        {

            // Enter Whirlwind Phase
            if (m_uiWhirlWindTimer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_WHIRLWIND) == CAST_OK)
                {
                    m_creature->CastSpell(m_creature, TAUNT_IMMUNE, true);
                    AssignRandomThreat();
                    m_uiWhirlWindEndTimer = 15000;
                    m_uiAggroResetTimer = urand(1000, 2000);
                }
            }
            else
                m_uiWhirlWindTimer -= uiDiff;

            // Aquire a new target sometimes
            if (m_uiAggroResetTimer < uiDiff)
            {
                AssignRandomThreat();
                m_uiAggroResetTimer = urand(3000, 7000);
            }
            else
                m_uiAggroResetTimer -= uiDiff;

            // Sundering Cleave
            if (m_uiCleaveTimer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE) == CAST_OK)
                    m_uiCleaveTimer = urand(3000, 4000);
            }
            else
                m_uiCleaveTimer -= uiDiff;

        }
        
        // If she is <25% enrage
        if (!m_bIsEnraged && m_creature->GetHealthPercent() <= 20.0f)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_ENRAGE, m_uiWhirlWindEndTimer ? CF_TRIGGERED : 0) == CAST_OK)
            {
                DoScriptText(EMOTE_ENRAGE, m_creature);
                m_bIsEnraged = true;
            }
        }

        // After 10 minutes hard enrage
        if (m_uiEnrageHardTimer)
        {
            if (m_uiEnrageHardTimer <= uiDiff)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_ENRAGEHARD, m_uiWhirlWindEndTimer ? CF_TRIGGERED : 0) == CAST_OK)
                {
                    DoScriptText(EMOTE_ENRAGEHARD, m_creature);
                    m_uiEnrageHardTimer = 0;
                    m_bIsEnraged = true;
                }
            }
            else
                m_uiEnrageHardTimer -= uiDiff;
        }

        DoMeleeAttackIfReady();

        // Leash check
        if (m_uiEvadeCheckTimer < uiDiff)
        {
            m_uiEvadeCheckTimer = 2500;
            if (m_creature->GetPositionY() > 1780)
            {
                EnterEvadeMode();
                LeashEncounter();
            }
        }
        else
            m_uiEvadeCheckTimer -= uiDiff;
    }
};

// *********************
// Sartura's Royal Guard
// *********************

struct mob_sartura_royal_guardAI : public ScriptedAI
{
    mob_sartura_royal_guardAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_temple_of_ahnqiraj*)pCreature->GetInstanceData();
        Reset();
    }

    instance_temple_of_ahnqiraj* m_pInstance;

    uint32 m_uiKnockbackTimer;
    uint32 m_uiWhirlWindTimer;
    uint32 m_uiWhirlWindEndTimer;           //15s
    uint32 m_uiAggroResetTimer;
    uint32 m_uiEvadeCheckTimer;

    void Reset() override
    {
        m_uiKnockbackTimer = urand(6000, 12000);
        m_uiWhirlWindTimer = urand(8000, 10000);
        m_uiWhirlWindEndTimer = 0;
        m_uiAggroResetTimer = urand(5000, 7500);
        m_uiEvadeCheckTimer = 2500;
    }

    void Aggro(Unit* /*pWho*/) override
    {
        m_creature->SetInCombatWithZone();
    }

    void AssignRandomThreat()
    {
        if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
        {
            DoResetThreat();
            m_creature->GetThreatManager().addThreatDirectly(pTarget, urand(1000, 2000));
        }
    }

    void LeashEncounter()
    {
        if (Creature* pSartura = m_pInstance->GetSingleCreatureFromStorage(NPC_BATTLEGUARD_SARTURA))
        {
            if (pSartura->IsAlive())
            {
                pSartura->AI()->EnterEvadeMode();

                GuidList m_lRoyalGuardsGuid;
                m_pInstance->GetRoyalGuardGUIDList(m_lRoyalGuardsGuid);
                for (const auto& guid : m_lRoyalGuardsGuid)
                {
                    if (Creature* pRoyalGuard = m_creature->GetMap()->GetCreature(guid))
                    {
                        if (pRoyalGuard->IsDead()) pRoyalGuard->Respawn(); else pRoyalGuard->AI()->EnterEvadeMode();
                    }
                }
            }
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        
        if (m_uiWhirlWindEndTimer)                          // Is in Whirlwind
        {
            // While in whirlwind, switch to random targets often
            if (m_uiAggroResetTimer < uiDiff)
            {
                AssignRandomThreat();
                m_uiAggroResetTimer = urand(1000, 2000);
            }
            else
                m_uiAggroResetTimer -= uiDiff;

            // End Whirlwind Phase
            if (m_uiWhirlWindEndTimer <= uiDiff)
            {
                m_uiWhirlWindEndTimer = 0;
                m_uiWhirlWindTimer = urand(2000, 6000);
                m_uiAggroResetTimer = urand(3000, 7000);
            }
            else
                m_uiWhirlWindEndTimer -= uiDiff;
        }
        else // if (!m_uiWhirlWindEndTimer)                 // Is not in whirlwind
        {
            // Enter Whirlwind Phase
            if (m_uiWhirlWindTimer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_GUARD_WHIRLWIND) == CAST_OK)
                {
                    AssignRandomThreat();
                    m_uiWhirlWindEndTimer = 8000;
                    m_uiAggroResetTimer = urand(1000, 2000);
                }
            }
            else
                m_uiWhirlWindTimer -= uiDiff;

            // Aquire a new target sometimes
            if (m_uiAggroResetTimer < uiDiff)
            {
                AssignRandomThreat();
                m_uiAggroResetTimer = urand(3000, 7000);
            }
            else
                m_uiAggroResetTimer -= uiDiff;

            // Knockback
            if (m_uiKnockbackTimer < uiDiff)
            {
                if(m_creature->CanReachWithMeleeAutoAttack(m_creature->GetVictim()))
                    if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_KNOCKBACK) == CAST_OK)
                        m_uiKnockbackTimer = urand(8000, 14000);
            }
            else
                m_uiKnockbackTimer -= uiDiff;

        }

        DoMeleeAttackIfReady();

        // Leash check
        if (m_uiEvadeCheckTimer < uiDiff)
        {
            m_uiEvadeCheckTimer = 2500;
            if (m_creature->GetPositionY() > 1780)
                LeashEncounter();
        }
        else
            m_uiEvadeCheckTimer -= uiDiff;
    }
};

// ****************
// Vekniss Guardian
// ****************

enum
{
    SPELL_IMPALE        = 26025,
    SPELL_FRENZY        = 8599,

    EMOTE_EMIT          = 10755,
    EMOTE_FRENZY        = 10645,
    SOUND_CHARGE        = 3330,
};

// array of GUIDs permitted to emote on aggro
static uint32 const aEmoteGUIDs[8] = { 87595, 87671, 87610, 87611, 87618, 87627, 87628, 87641 };

struct mob_vekniss_guardianAI : public ScriptedAI
{
    mob_vekniss_guardianAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        m_uiImpaleTimer = 0;
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiImpaleTimer;
    uint32 m_uiEmoteTimer;
    uint32 m_uiEvadeCheckTimer;

    bool m_bCalledForHelp;
    bool m_bFrenzied;
    bool m_bIsAlone;

    void Reset() override
    {
        m_bCalledForHelp = false;
        m_bFrenzied = false;
        m_uiEmoteTimer = 0;
        m_uiEvadeCheckTimer = 2500;
    }

    void Aggro(Unit* /*pWho*/) override
    {
        for (uint32 i : aEmoteGUIDs)
        {
            if (m_creature->GetGUIDLow() == i)
            {
                m_uiEmoteTimer = 2500;
                break;
            }
        }
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        // Increased aggro radius
        if (pWho->GetTypeId() == TYPEID_PLAYER && !m_creature->IsInCombat() && m_creature->IsWithinDistInMap(pWho, 50.0f) && m_creature->IsWithinLOSInMap(pWho) && !pWho->HasAuraType(SPELL_AURA_FEIGN_DEATH))
        {
            AttackStart(pWho);
        }
        ScriptedAI::MoveInLineOfSight(pWho);
    }

    void EnterEvadeMode() override
    {
        m_creature->UpdateSpeed(MOVE_RUN, false);
        ScriptedAI::EnterEvadeMode();
    }

    void ImpaleAssist(Unit* pWho)
    {
        m_creature->UpdateSpeed(MOVE_RUN, true, 2.5);
        m_creature->GetMotionMaster()->MovePoint(1, pWho->GetPositionX(), pWho->GetPositionY(), pWho->GetPositionZ());
        m_creature->PlayDistanceSound(SOUND_CHARGE);
    }

    void MovementInform(uint32 uiMotionType, uint32 /*uiPointId*/) override
    {
        if (uiMotionType != POINT_MOTION_TYPE)
            return;

        DoCastSpellIfCan(m_creature, SPELL_IMPALE);
        m_creature->UpdateSpeed(MOVE_RUN, false);
        DoStartMovement(m_creature->GetVictim());
    }

    void DamageTaken(Unit* /*pDoneBy*/, uint32& uiDamage) override
    {
        if (m_creature->GetHealthPercent() < 25.0f && !m_bCalledForHelp)
        {
            m_bCalledForHelp = true;
            m_bIsAlone = true;
            std::list<Creature*> lAssistList;
            GetCreatureListWithEntryInGrid(lAssistList, m_creature, 15233, 45.0f);

            for (const auto& itr : lAssistList)
            {
                if (itr->GetObjectGuid() == m_creature->GetObjectGuid())
                    continue;

                if (itr->IsAlive() && m_creature->IsWithinLOSInMap(itr))
                {
                    if (m_bIsAlone)
                        m_bIsAlone = false;
                    if (mob_vekniss_guardianAI* pVeknissAI = dynamic_cast<mob_vekniss_guardianAI*>(itr->AI()))
                        pVeknissAI->ImpaleAssist(m_creature);
                }
            }
            if (m_bIsAlone)
                DoCastSpellIfCan(m_creature, SPELL_IMPALE);
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiEvadeCheckTimer < uiDiff)
        {
            m_uiEvadeCheckTimer = 2500;
            if (m_creature->IsInEvadeMode())
            {
                if (Unit* pTarget = m_creature->GetVictim())
                    m_creature->Relocate(pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ());
            }
        }
        else
            m_uiEvadeCheckTimer -= uiDiff;

        if (m_uiEmoteTimer)
        {
            if (m_uiEmoteTimer < uiDiff)
            {
                DoScriptText(EMOTE_EMIT, m_creature);
                m_uiEmoteTimer = 0;
            }
            else
                m_uiEmoteTimer -= uiDiff;
        }

        if (m_creature->GetHealthPercent() < 30.0f && !m_bFrenzied)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_FRENZY) == CAST_OK)
            {
                DoScriptText(EMOTE_FRENZY, m_creature);
                m_bFrenzied = true;
            }
        }

        if (m_uiImpaleTimer)                                                                    // stop chasing momentarily after casting impale to prevent z-axis problems
        {
            if (m_uiImpaleTimer < uiDiff)
            {
                
                m_uiImpaleTimer = 0;
            }
            else
                m_uiImpaleTimer -= uiDiff;
        }

        DoMeleeAttackIfReady();
    }
};


CreatureAI* GetAI_boss_sartura(Creature* pCreature)
{
    return new boss_sarturaAI(pCreature);
}

CreatureAI* GetAI_mob_sartura_royal_guard(Creature* pCreature)
{
    return new mob_sartura_royal_guardAI(pCreature);
}

CreatureAI* GetAI_mob_vekniss_guardian(Creature* pCreature)
{
    return new mob_vekniss_guardianAI(pCreature);
}

void AddSC_boss_sartura()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_sartura";
    pNewScript->GetAI = &GetAI_boss_sartura;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_sartura_royal_guard";
    pNewScript->GetAI = &GetAI_mob_sartura_royal_guard;
    pNewScript->RegisterSelf(); 

    pNewScript = new Script;
    pNewScript->Name = "mob_vekniss_guardian";
    pNewScript->GetAI = &GetAI_mob_vekniss_guardian;
    pNewScript->RegisterSelf();
}
