/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "halls_of_lightning.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

enum Texts
{
    SAY_AGGRO                               = 0,
    SAY_FORGE                               = 1,
    SAY_STOMP                               = 2,
    SAY_SLAY                                = 3,
    SAY_DEATH                               = 4,
    EMOTE_TO_ANVIL                          = 5,
    EMOTE_SHATTER                           = 6,
};

enum Spells
{
    SPELL_HEAT                              = 52387,
    SPELL_SHATTERING_STOMP                  = 52237,
    SPELL_TEMPER                            = 52238,
    SPELL_TEMPER_DUMMY                      = 52654,
    SPELL_SUMMON_MOLTEN_GOLEM               = 52405,
    SPELL_FORGE_VISUAL                      = 52654,

    // Molten Golem
    SPELL_BLAST_WAVE                        = 23113,
    SPELL_IMMOLATION_STRIKE                 = 52433,
    SPELL_SHATTER                           = 52429,
};

enum Events
{
    EVENT_PAUSE                             = 1,
    EVENT_SHATTERING_STOMP                  = 2,
    EVENT_SHATTER                           = 3,
    EVENT_FORGE_CAST                        = 4,

    // Molten Golem
    EVENT_BLAST                             = 5,
    EVENT_IMMOLATION                        = 6
};

enum Npcs
{
    NPC_VOLKHAN_ANVIL                       = 28823,
    NPC_MOLTEN_GOLEM                        = 28695,
    NPC_BRITTLE_GOLEM                       = 28681,
    MAX_GOLEM                               = 2,
    DATA_SHATTER_RESISTANT                  = 2042
};

enum Phases
{
    PHASE_INTRO                             = 1,
    PHASE_NORMAL
};

/*######
## Boss Volkhan
######*/
class boss_volkhan : public CreatureScript
{
public:
    boss_volkhan() : CreatureScript("boss_volkhan") { }

    struct boss_volkhanAI : public BossAI
    {
        boss_volkhanAI(Creature* creature) : BossAI(creature, DATA_VOLKHAN)
        {
            Initialize();
        }

        void Initialize()
        {
            m_bIsStriking      = false;
            m_bHasTemper       = false;
            m_bCanShatterGolem = false;
            m_uiDelay_Timer    = 1000;
            m_uiSummonPhase    = 0;
            GolemsShattered    = 0;

            m_uiHealthAmountModifier = 1;
        }

        void Reset() override
        {
            Initialize();
            _Reset();
            DespawnGolem();
            m_lGolemGUIDList.clear();
            events.SetPhase(PHASE_INTRO);
            events.ScheduleEvent(EVENT_FORGE_CAST, 2 * IN_MILLISECONDS, 0, PHASE_INTRO);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            events.SetPhase(PHASE_NORMAL);
            events.ScheduleEvent(EVENT_PAUSE,            3.5 * IN_MILLISECONDS, 0, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_SHATTERING_STOMP,   0 * IN_MILLISECONDS, 0, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_SHATTER,            5 * IN_MILLISECONDS, 0, PHASE_NORMAL);
            _EnterCombat();
        }

        void AttackStart(Unit* who) override
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

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            DespawnGolem();

            _JustDied();
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void DespawnGolem()
        {
            if (m_lGolemGUIDList.empty())
                return;

            for (ObjectGuid guid : m_lGolemGUIDList)
            {
                if (Creature* temp = ObjectAccessor::GetCreature(*me, guid))
                    if (temp->IsAlive())
                        temp->DespawnOrUnsummon();
            }

            m_lGolemGUIDList.clear();
        }

        void ShatterGolem()
        {
            if (m_lGolemGUIDList.empty())
                return;

            for (ObjectGuid guid : m_lGolemGUIDList)
            {
                if (Creature* temp = ObjectAccessor::GetCreature(*me, guid))
                {
                    // Only shatter brittle golems
                    if (temp->IsAlive() && temp->GetEntry() == NPC_BRITTLE_GOLEM)
                    {
                        temp->CastSpell(temp, SPELL_SHATTER, false);
                        GolemsShattered += 1;
                    }
                }
            }
        }

        void JustSummoned(Creature* summoned) override
        {
            if (summoned->GetEntry() == NPC_MOLTEN_GOLEM)
            {
                m_lGolemGUIDList.push_back(summoned->GetGUID());

                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    summoned->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);

                // Why healing when just summoned?
                summoned->CastSpell(summoned, SPELL_HEAT, false, NULL, NULL, me->GetGUID());
            }
        }

        void MovementInform(uint32 type, uint32 data) override
        {
            if (type == POINT_MOTION_TYPE && data == EVENT_FORGE_CAST)
            {
                if (m_uiSummonPhase == 2)
                {
                    me->SetOrientation(2.29f);
                    m_uiSummonPhase = 3;
                }
            }
        }

        uint32 GetData(uint32 data) const override
        {
            if (data == DATA_SHATTER_RESISTANT)
                return GolemsShattered;

            return 0;
        }

        void UpdateAI(uint32 diff) override
        {
            // Return since we have no target and are in CombatPhase
            if (events.IsInPhase(PHASE_NORMAL) && !UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_PAUSE:
                        if (m_bIsStriking)
                        {
                            if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() != CHASE_MOTION_TYPE)
                                if (me->GetVictim())
                                    me->GetMotionMaster()->MoveChase(me->GetVictim());

                            m_bHasTemper = false;
                            m_bIsStriking = false;
                            events.ScheduleEvent(EVENT_PAUSE, 3.5 * IN_MILLISECONDS, 0, PHASE_NORMAL);
                        }
                        break;
                    case EVENT_SHATTERING_STOMP:
                        if (!m_bHasTemper && m_uiHealthAmountModifier >= 3)
                        {
                            // Should he stomp even if he has no brittle golem to shatter?
                            Talk(SAY_STOMP);

                            DoCast(me, SPELL_SHATTERING_STOMP);

                            Talk(EMOTE_SHATTER);
                            events.ScheduleEvent(EVENT_SHATTERING_STOMP, 30 * IN_MILLISECONDS, 0, PHASE_NORMAL);
                            m_bCanShatterGolem = true;
                        }
                        break;
                    case EVENT_SHATTER:
                        if (m_bCanShatterGolem)
                        {
                            ShatterGolem();
                            events.ScheduleEvent(EVENT_SHATTER, 3 * IN_MILLISECONDS, 0, PHASE_NORMAL);
                            m_bCanShatterGolem = false;
                        }
                        break;
                    case EVENT_FORGE_CAST:
                        DoCast(me, SPELL_FORGE_VISUAL);
                        events.ScheduleEvent(EVENT_FORGE_CAST, 15 * IN_MILLISECONDS, 0, PHASE_INTRO);
                        break;
                    default:
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
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
                    me->GetMotionMaster()->MovePoint(EVENT_FORGE_CAST, me->GetHomePosition());
                    m_uiSummonPhase = 2;        // Set Next Phase
                    break;
                case 2:
                    // 2 - Check if reached Anvil
                    // This is handled in: void MovementInform(uint32, uint32) override
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
                    if (m_uiDelay_Timer <= diff)
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
                        m_uiDelay_Timer -= diff;
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

        private:
            GuidList m_lGolemGUIDList;
            uint32 m_uiHealthAmountModifier;
            uint8 GolemsShattered;
            uint32 m_uiDelay_Timer;
            uint32 m_uiSummonPhase;

            bool m_bHasTemper;
            bool m_bIsStriking;
            bool m_bCanShatterGolem;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfLightningAI<boss_volkhanAI>(creature);
    }
};

/*######
## npc_molten_golem
######*/

class npc_molten_golem : public CreatureScript
{
public:
    npc_molten_golem() : CreatureScript("npc_molten_golem") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfLightningAI<npc_molten_golemAI>(creature);
    }

    struct npc_molten_golemAI : public ScriptedAI
    {
        npc_molten_golemAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            m_bIsFrozen = false;
            events.ScheduleEvent(EVENT_BLAST,      20 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_IMMOLATION,  5 * IN_MILLISECONDS);
        }

        bool m_bIsFrozen;

        void Reset() override
        {
            Initialize();
        }

        void AttackStart(Unit* who) override
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

        void DamageTaken(Unit* /*pDoneBy*/, uint32 &uiDamage) override
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

        void SpellHit(Unit* /*pCaster*/, const SpellInfo* pSpell) override
        {
            // This is the dummy effect of the spells
            if (pSpell->Id == SPELL_SHATTER)
                if (me->GetEntry() == NPC_BRITTLE_GOLEM)
                    me->DespawnOrUnsummon();
        }

        void UpdateAI(uint32 diff) override
        {
            // Return since we have no target or if we are frozen
            if (!UpdateVictim() || m_bIsFrozen)
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_BLAST:
                        DoCast(me, SPELL_BLAST_WAVE);
                        events.ScheduleEvent(EVENT_BLAST, 20 * IN_MILLISECONDS);
                        break;
                    case EVENT_IMMOLATION:
                        DoCastVictim(SPELL_IMMOLATION_STRIKE);
                        events.ScheduleEvent(EVENT_BLAST, 5 * IN_MILLISECONDS);
                        break;
                    default:
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

            DoMeleeAttackIfReady();
        }

        private:
            EventMap events;
    };
};

class achievement_shatter_resistant : public AchievementCriteriaScript
{
    public:
        achievement_shatter_resistant() : AchievementCriteriaScript("achievement_shatter_resistant") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
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
