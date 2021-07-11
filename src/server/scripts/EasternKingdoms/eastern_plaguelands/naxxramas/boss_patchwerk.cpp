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
SDName: Boss_Patchwerk
SD%Complete: 80
SDComment: TODO: confirm how hateful strike work
SDCategory: Naxxramas
EndScriptData */

#include "scriptPCH.h"
#include "naxxramas.h"

enum PatchwerkData
{
    SAY_AGGRO1            = 13068,
    SAY_AGGRO2            = 13069,
    SAY_SLAY              = 13071,
    SAY_DEATH             = 13070,

    EMOTE_BERSERK         = 4428,
    EMOTE_ENRAGE          = 2384,

    SPELL_HATEFULSTRIKE   = 28308,
    SPELL_ENRAGE          = 28131, // 5% enrage soft enrage
    SPELL_BERSERK         = 27680, // 7min hard enrage
    SPELL_SLIMEBOLT       = 32309  // Added in patch 1.12
};

constexpr float MELEE_DISTANCE = 5.0; 

enum ePatchwerkEvents
{
    EVENT_BERSERK = 1,
    EVENT_HATEFULSTRIKE,
    EVENT_SLIMEBOLT
};

static constexpr uint32 BERSERK_TIMER           = 7 * 60 * 1000; // 7 minutes enrage
static constexpr uint32 HATEFUL_CD              = 1200;

// 30 sec after berserk he starts throwing slime at ppl
// this was added in 1.12.1 to cope with guilds kiting him
static constexpr uint32 SLIMEBOLT_INITIAL       = BERSERK_TIMER + 30000;
static constexpr uint32 SLIMEBOLT_REPEAT_CD     = 5000; 

struct boss_patchwerkAI : public ScriptedAI
{
    boss_patchwerkAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_naxxramas*)pCreature->GetInstanceData();
        Reset();
    }

    instance_naxxramas* m_pInstance;

    EventMap m_events;

    bool   m_bEnraged;
    bool   m_bBerserk;
    ObjectGuid previousTarget;

    void Reset() override
    {
        m_events.Reset();
        m_bEnraged = false;
        m_bBerserk = false;
        previousTarget = 0;
    }

    void KilledUnit(Unit* pVictim) override
    {
        if (urand(0, 4))
            return;

        DoScriptText(SAY_SLAY, m_creature);
    }

    void JustDied(Unit* pKiller) override
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_PATCHWERK, DONE);
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_PATCHWERK, FAIL);
    }

    void Aggro(Unit* pWho) override
    {
        DoScriptText(urand(0, 1) ? SAY_AGGRO1 : SAY_AGGRO2, m_creature);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_PATCHWERK, IN_PROGRESS);
            
        m_events.ScheduleEvent(EVENT_BERSERK, BERSERK_TIMER);
        m_events.ScheduleEvent(EVENT_HATEFULSTRIKE, HATEFUL_CD);
#if SUPPORTED_CLIENT_BUILD >= CLIENT_BUILD_1_12_1
        m_events.ScheduleEvent(EVENT_SLIMEBOLT, SLIMEBOLT_INITIAL);
#endif
    }

    void DoHatefulStrike()
    {
        // The ability is used on highest HP target in melee
        // current tank cannot be hit by hateful as long as there are other players in melee
        
        // todo: can it hit anything other than players?

        Unit* mainTank = m_creature->GetVictim();
        
        // Shouldnt really be possible, but hey, weirder things have happened
        if (!mainTank)
            return;
        ObjectGuid const& mainTankGuid = mainTank->GetObjectGuid();

        Unit* pTarget = nullptr;
        uint32 uiHighestHP = 0;
        uint8 threatListPosition = 0;

        ThreatList const& tList = m_creature->GetThreatManager().getThreatList();
        for (const auto iter : tList)
        {
            // Only top 4 players on threat in melee range are targetted.
            if (threatListPosition > 3)
                break;

            if (!iter->getUnitGuid().IsPlayer())
                continue;
            
            Player* pTempTarget = m_creature->GetMap()->GetPlayer(iter->getUnitGuid());
            if (!pTempTarget)
                continue;

            if (!m_creature->IsInMap(pTempTarget))
                continue;

            if (!m_creature->CanReachWithMeleeSpellAttack(pTempTarget))
                continue;

            // Skipping maintank, only using him if there is no other viable target 
            // todo: not sure if this is correct. Should we target the MT over the offtanks, if the offtanks have less hp?
            if (iter->getUnitGuid() != mainTankGuid)
            {
                // target has higher hp than anyone checked so far
                if (pTempTarget->GetHealth() > uiHighestHP)
                {
                    pTarget = pTempTarget;
                    uiHighestHP = pTarget->GetHealth();
                }
            }

            threatListPosition++;
        }

        // If we found no viable target, we choose the maintank
        if (!pTarget)
            pTarget = mainTank;

        if (pTarget->GetObjectGuid() != previousTarget)
        {
            m_creature->SetInFront(pTarget);
            m_creature->SetTargetGuid(pTarget->GetObjectGuid());
            previousTarget = pTarget->GetObjectGuid();
        }
        DoCastSpellIfCan(pTarget, SPELL_HATEFULSTRIKE, CF_TRIGGERED);
    }

    bool CustomGetTarget()
    {
        if (!m_creature->IsAlive())
            return false;

        Unit* target = nullptr;

        // No taunt aura or taunt aura caster is dead, standard target selection
        if (!target && !m_creature->GetThreatManager().isThreatListEmpty())
            target = m_creature->GetThreatManager().getHostileTarget();

        if (target)
        {
            // Nostalrius : Correction bug sheep/fear
            if (!m_creature->HasUnitState(UNIT_STAT_STUNNED | UNIT_STAT_PENDING_STUNNED | UNIT_STAT_FEIGN_DEATH | UNIT_STAT_CONFUSED | UNIT_STAT_FLEEING)
                && (!m_creature->HasAuraType(SPELL_AURA_MOD_FEAR) || m_creature->HasAuraType(SPELL_AURA_PREVENTS_FLEEING)) && !m_creature->HasAuraType(SPELL_AURA_MOD_CONFUSE))
            {
                if (!m_creature->IsAttackReady(BASE_ATTACK) && m_creature->CanReachWithMeleeAutoAttack(target)) // he does not have offhand attack
                    return true;

                if (target->GetObjectGuid() != previousTarget)
                {
                    m_creature->SetInFront(target);
                    m_creature->SetTargetGuid(target->GetObjectGuid());
                    previousTarget = target->GetObjectGuid();
                }
                AttackStart(target);
            }
            return true;
        }

        // no target but something prevent go to evade mode // Nostalrius - fix evade quand CM.
        if (!m_creature->IsInCombat() || m_creature->HasAuraType(SPELL_AURA_MOD_TAUNT) || m_creature->GetCharmerGuid())
            return false;

        // last case when creature don't must go to evade mode:
        // it in combat but attacker not make any damage and not enter to aggro radius to have record in threat list
        // for example at owner command to pet attack some far away creature
        // Note: creature not have targeted movement generator but have attacker in this case
        if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() != CHASE_MOTION_TYPE)
        {
            for (const auto itr : m_creature->GetAttackers())
            {
                if (itr->IsInMap(m_creature) && itr->IsTargetable(true, false))
                    return false;
            }
        }

        // enter in evade mode in other case
        m_creature->OnLeaveCombat();
        return false;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!CustomGetTarget() || !m_creature->GetVictim())
            return;

        // Soft Enrage at 5%
        if (!m_bEnraged)
        {
            if (m_creature->GetHealthPercent() < 5.0f)
            {
                DoCastSpellIfCan(m_creature, SPELL_ENRAGE);
                DoScriptText(EMOTE_ENRAGE, m_creature);
                m_bEnraged = true;
            }
        }

        m_events.Update(uiDiff);
        while (auto l_EventId = m_events.ExecuteEvent())
        {
            switch (l_EventId)
            {
                case EVENT_BERSERK:
                    if (DoCastSpellIfCan(m_creature, SPELL_BERSERK) == CAST_OK)
                    {
                        DoScriptText(EMOTE_BERSERK, m_creature);
                        m_bBerserk = true;
                    }
                    else
                        m_events.Repeat(100);
                    break;
                case EVENT_HATEFULSTRIKE:
                    DoHatefulStrike();
                    m_events.Repeat(HATEFUL_CD);
                    break;
                case EVENT_SLIMEBOLT:
                    if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SLIMEBOLT) == CAST_OK)
                        m_events.Repeat(SLIMEBOLT_REPEAT_CD);
                    else
                        m_events.Repeat(100);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_patchwerk(Creature* pCreature)
{
    return new boss_patchwerkAI(pCreature);
}

void AddSC_boss_patchwerk()
{
    Script* NewScript;
    NewScript = new Script;
    NewScript->Name = "boss_patchwerk";
    NewScript->GetAI = &GetAI_boss_patchwerk;
    NewScript->RegisterSelf();
}
