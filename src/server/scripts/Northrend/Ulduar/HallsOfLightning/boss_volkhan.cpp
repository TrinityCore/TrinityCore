/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Boss Volkhan
SD%Complete: 90%
SDComment: Event should be pretty close minus a few visual flaws
SDCategory: Halls of Lightning
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "halls_of_lightning.h"
#include "Player.h"
#include "SpellInfo.h"

enum Enums
{
    SAY_AGGRO                               = 0,
    SAY_FORGE                               = 1,
    SAY_STOMP                               = 2,
    SAY_SLAY                                = 3,
    SAY_DEATH                               = 4,
    EMOTE_TO_ANVIL                          = 5,
    EMOTE_SHATTER                           = 6,

    SPELL_HEAT_N                            = 52387,
    SPELL_HEAT_H                            = 59528,
    SPELL_SHATTERING_STOMP_N                = 52237,
    SPELL_SHATTERING_STOMP_H                = 59529,

    SPELL_TEMPER                            = 52238,
    SPELL_TEMPER_DUMMY                      = 52654,

    SPELL_SUMMON_MOLTEN_GOLEM               = 52405,

    // Molten Golem
    SPELL_BLAST_WAVE                        = 23113,
    SPELL_IMMOLATION_STRIKE_N               = 52433,
    SPELL_IMMOLATION_STRIKE_H               = 59530,
    SPELL_SHATTER_N                         = 52429,
    SPELL_SHATTER_H                         = 59527,

    NPC_VOLKHAN_ANVIL                       = 28823,
    NPC_MOLTEN_GOLEM                        = 28695,
    NPC_BRITTLE_GOLEM                       = 28681,

    MAX_GOLEM                               = 2,

    DATA_SHATTER_RESISTANT                  = 2042
};

/*######
## Boss Volkhan
######*/
class boss_volkhan : public CreatureScript
{
public:
    boss_volkhan() : CreatureScript("boss_volkhan") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_volkhanAI>(creature);
    }

    struct boss_volkhanAI : public ScriptedAI
    {
        boss_volkhanAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        std::list<uint64> m_lGolemGUIDList;

        bool m_bHasTemper;
        bool m_bIsStriking;
        bool m_bCanShatterGolem;

        uint8 GolemsShattered;
        uint32 m_uiPause_Timer;
        uint32 m_uiShatteringStomp_Timer;
        uint32 m_uiShatter_Timer;
        uint32 m_uiDelay_Timer;
        uint32 m_uiSummonPhase;

        uint32 m_uiHealthAmountModifier;

        void Reset() OVERRIDE
        {
            m_bIsStriking = false;
            m_bHasTemper = false;
            m_bCanShatterGolem = false;

            m_uiPause_Timer = 3500;
            m_uiShatteringStomp_Timer = 0;
            m_uiShatter_Timer = 5000;
            m_uiDelay_Timer = 1000;
            m_uiSummonPhase = 0;
            GolemsShattered = 0;

            m_uiHealthAmountModifier = 1;

            DespawnGolem();
            m_lGolemGUIDList.clear();

            instance->SetBossState(DATA_VOLKHAN, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);

            instance->SetBossState(DATA_VOLKHAN, IN_PROGRESS);
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (me->Attack(who, true))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);

                if (!m_bHasTemper)
                    me->GetMotionMaster()->MoveChase(who);
            }
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_DEATH);
            DespawnGolem();

            instance->SetBossState(DATA_VOLKHAN, DONE);
        }

        void KilledUnit(Unit* who) OVERRIDE
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void DespawnGolem()
        {
            if (m_lGolemGUIDList.empty())
                return;

            for (std::list<uint64>::const_iterator itr = m_lGolemGUIDList.begin(); itr != m_lGolemGUIDList.end(); ++itr)
            {
                if (Creature* temp = Unit::GetCreature(*me, *itr))
                {
                    if (temp->IsAlive())
                        temp->DespawnOrUnsummon();
                }
            }

            m_lGolemGUIDList.clear();
        }

        void ShatterGolem()
        {
            if (m_lGolemGUIDList.empty())
                return;

            for (std::list<uint64>::const_iterator itr = m_lGolemGUIDList.begin(); itr != m_lGolemGUIDList.end(); ++itr)
            {
                if (Creature* temp = Unit::GetCreature(*me, *itr))
                {
                    // Only shatter brittle golems
                    if (temp->IsAlive() && temp->GetEntry() == NPC_BRITTLE_GOLEM)
                    {
                        temp->CastSpell(temp, DUNGEON_MODE(SPELL_SHATTER_N, SPELL_SHATTER_H), false);
                        GolemsShattered += 1;
                    }
                }
            }
        }

        void JustSummoned(Creature* summoned) OVERRIDE
        {
            if (summoned->GetEntry() == NPC_MOLTEN_GOLEM)
            {
                m_lGolemGUIDList.push_back(summoned->GetGUID());

                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    summoned->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);

                // Why healing when just summoned?
                summoned->CastSpell(summoned, DUNGEON_MODE(SPELL_HEAT_N, SPELL_HEAT_H), false, NULL, NULL, me->GetGUID());
            }
        }

        void JustReachedHome() OVERRIDE
        {
            if (m_uiSummonPhase == 2)
            {
                me->SetOrientation(2.29f);
                m_uiSummonPhase = 3;
            }
        }

        uint32 GetData(uint32 data) const OVERRIDE
        {
            if (data == DATA_SHATTER_RESISTANT)
                return GolemsShattered;

            return 0;
        }

        void UpdateAI(uint32 uiDiff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (m_bIsStriking)
            {
                if (m_uiPause_Timer <= uiDiff)
                {
                    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() != CHASE_MOTION_TYPE)
                        if (me->GetVictim())
                            me->GetMotionMaster()->MoveChase(me->GetVictim());

                    m_bHasTemper = false;
                    m_bIsStriking = false;
                    m_uiPause_Timer = 3500;
                }
                else
                    m_uiPause_Timer -= uiDiff;

                return;
            }

            // When to start shatter? After 60, 40 or 20% hp?
            if (!m_bHasTemper && m_uiHealthAmountModifier >= 3)
            {
                if (m_uiShatteringStomp_Timer <= uiDiff)
                {
                    // Should he stomp even if he has no brittle golem to shatter?
                    Talk(SAY_STOMP);

                    DoCast(me, SPELL_SHATTERING_STOMP_N);

                    Talk(EMOTE_SHATTER);

                    m_uiShatteringStomp_Timer = 30000;
                    m_bCanShatterGolem = true;
                }
                else
                    m_uiShatteringStomp_Timer -= uiDiff;
            }

            // Shatter Golems 3 seconds after Shattering Stomp
            if (m_bCanShatterGolem)
            {
                if (m_uiShatter_Timer <= uiDiff)
                {
                    ShatterGolem();
                    m_uiShatter_Timer = 3000;
                    m_bCanShatterGolem = false;
                }
                else
                    m_uiShatter_Timer -= uiDiff;
            }

            // Health check
            if (!m_bCanShatterGolem && me->HealthBelowPct(100 - 20 * m_uiHealthAmountModifier))
            {
                ++m_uiHealthAmountModifier;

                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(false);

                Talk(SAY_FORGE);

                m_bHasTemper = true;

                m_uiSummonPhase = 1;
            }

            switch (m_uiSummonPhase)
            {
                case 1:
                    // 1 - Start run to Anvil
                    Talk(EMOTE_TO_ANVIL);
                    me->GetMotionMaster()->MoveTargetedHome();
                    m_uiSummonPhase = 2;        // Set Next Phase
                    break;

                case 2:
                    // 2 - Check if reached Anvil
                    // This is handled in: void JustReachedHome() OVERRIDE
                    break;

                case 3:
                    // 3 - Cast Temper on the Anvil
                    if (Unit* target = GetClosestCreatureWithEntry(me, NPC_VOLKHAN_ANVIL, 1000.0f, true))
                    {
                        me->SetOrientation(2.29f);
                        DoCast(target, SPELL_TEMPER, false);
                        DoCast(target, SPELL_TEMPER_DUMMY, false);
                    }
                    m_uiDelay_Timer = 1000;     // Delay 2 seconds before next phase can begin
                    m_uiSummonPhase = 4;        // Set Next Phase
                    break;

                case 4:
                    // 4 - Wait for delay to expire
                    if (m_uiDelay_Timer <= uiDiff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0))
                        {
                            me->SetReactState(REACT_AGGRESSIVE);
                            me->SetInCombatWith(target);
                            me->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);
                        }
                        m_uiSummonPhase = 5;
                    }
                    else
                        m_uiDelay_Timer -= uiDiff;
                    break;

                case 5:
                    // 5 - Spawn the Golems
                    if (Creature* creatureTarget = GetClosestCreatureWithEntry(me, NPC_VOLKHAN_ANVIL, 1000.0f, true))
                        for (uint8 i = 0; i < MAX_GOLEM; ++i)
                            me->CastSpell(creatureTarget, SPELL_SUMMON_MOLTEN_GOLEM, true);

                    m_bIsStriking = true;
                    m_uiSummonPhase = 0;        // Reset back to Phase 0 for next time
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };

};

/*######
## npc_molten_golem
######*/
class npc_molten_golem : public CreatureScript
{
public:
    npc_molten_golem() : CreatureScript("npc_molten_golem") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_molten_golemAI(creature);
    }

    struct npc_molten_golemAI : public ScriptedAI
    {
        npc_molten_golemAI(Creature* creature) : ScriptedAI(creature) { }

        bool m_bIsFrozen;

        uint32 m_uiBlast_Timer;
        uint32 m_uiDeathDelay_Timer;
        uint32 m_uiImmolation_Timer;

        void Reset() OVERRIDE
        {
            m_bIsFrozen = false;

            m_uiBlast_Timer = 20000;
            m_uiDeathDelay_Timer = 0;
            m_uiImmolation_Timer = 5000;
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (me->Attack(who, true))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);

                if (!m_bIsFrozen)
                    me->GetMotionMaster()->MoveChase(who);
            }
        }

        void DamageTaken(Unit* /*pDoneBy*/, uint32 &uiDamage) OVERRIDE
        {
            if (uiDamage > me->GetHealth())
            {
                me->UpdateEntry(NPC_BRITTLE_GOLEM);
                me->SetHealth(1);
                uiDamage = 0;
                me->RemoveAllAuras();
                me->AttackStop();
                // me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);  //Set in DB
                // me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE); //Set in DB
                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(false);
                if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == CHASE_MOTION_TYPE)
                    me->GetMotionMaster()->MovementExpired();
                m_bIsFrozen = true;
            }
        }

        void SpellHit(Unit* /*pCaster*/, const SpellInfo* pSpell) OVERRIDE
        {
            // This is the dummy effect of the spells
            if (pSpell->Id == SPELL_SHATTER_N || pSpell->Id == SPELL_SHATTER_H)
                if (me->GetEntry() == NPC_BRITTLE_GOLEM)
                    me->DespawnOrUnsummon();
        }

        void UpdateAI(uint32 uiDiff) OVERRIDE
        {
            // Return since we have no target or if we are frozen
            if (!UpdateVictim() || m_bIsFrozen)
                return;

            if (m_uiBlast_Timer <= uiDiff)
            {
                DoCast(me, SPELL_BLAST_WAVE);
                m_uiBlast_Timer = 20000;
            }
            else
                m_uiBlast_Timer -= uiDiff;

            if (m_uiImmolation_Timer <= uiDiff)
            {
                DoCastVictim(SPELL_IMMOLATION_STRIKE_N);
                m_uiImmolation_Timer = 5000;
            }
            else
                m_uiImmolation_Timer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};

class achievement_shatter_resistant : public AchievementCriteriaScript
{
    public:
        achievement_shatter_resistant() : AchievementCriteriaScript("achievement_shatter_resistant") { }

        bool OnCheck(Player* /*source*/, Unit* target) OVERRIDE
        {
            return target && target->GetAI()->GetData(DATA_SHATTER_RESISTANT) < 5;
        }
};

void AddSC_boss_volkhan()
{
    new boss_volkhan();
    new npc_molten_golem();
    new achievement_shatter_resistant();
}
