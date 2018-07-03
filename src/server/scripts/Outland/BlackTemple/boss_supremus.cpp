/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "black_temple.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"

enum Texts
{
    EMOTE_NEW_TARGET          = 0,
    EMOTE_PUNCH_GROUND        = 1,
    EMOTE_GROUND_CRACK        = 2
};

enum Spells
{
    SPELL_MOLTEN_PUNCH        = 40126,
    SPELL_HATEFUL_STRIKE      = 41926,
    SPELL_MOLTEN_FLAME        = 40980,
    SPELL_VOLCANIC_ERUPTION   = 40117,
    SPELL_VOLCANIC_SUMMON     = 40276,
    SPELL_VOLCANIC_GEYSER     = 42055,
    SPELL_BERSERK             = 45078,
    SPELL_SNARE_SELF          = 41922,
    SPELL_CHARGE              = 41581
};

enum Events
{
    EVENT_BERSERK = 1,
    EVENT_SWITCH_PHASE,
    EVENT_FLAME,
    EVENT_VOLCANO,
    EVENT_SWITCH_TARGET,
    EVENT_HATEFUL_STRIKE
};

enum Phases
{
    PHASE_INITIAL =  1,
    PHASE_STRIKE  =  2,
    PHASE_CHASE   =  3
};

enum Actions
{
    ACTION_DISABLE_VULCANO = 1
};

class boss_supremus : public CreatureScript
{
public:
    boss_supremus() : CreatureScript("boss_supremus") { }

    struct boss_supremusAI : public BossAI
    {
        boss_supremusAI(Creature* creature) : BossAI(creature, DATA_SUPREMUS) { }

        void Reset() override
        {
            _Reset();
            events.SetPhase(PHASE_INITIAL);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            summons.DespawnAll();
            _DespawnAtEvade();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            ChangePhase();
            events.ScheduleEvent(EVENT_BERSERK, Minutes(15));
            events.ScheduleEvent(EVENT_FLAME, Seconds(20));
        }

        void ChangePhase()
        {
            if (events.IsInPhase(PHASE_INITIAL) || events.IsInPhase(PHASE_CHASE))
            {
                events.SetPhase(PHASE_STRIKE);
                DummyEntryCheckPredicate pred;
                summons.DoAction(ACTION_DISABLE_VULCANO, pred);
                events.ScheduleEvent(EVENT_HATEFUL_STRIKE, Seconds(2), 0, PHASE_STRIKE);
                me->RemoveAurasDueToSpell(SPELL_SNARE_SELF);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
            }
            else
            {
                events.SetPhase(PHASE_CHASE);
                events.ScheduleEvent(EVENT_VOLCANO, Seconds(5), 0, PHASE_CHASE);
                events.ScheduleEvent(EVENT_SWITCH_TARGET, Seconds(10), 0, PHASE_CHASE);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                DoCast(SPELL_SNARE_SELF);
            }
            DoResetThreat();
            DoZoneInCombat();
            events.ScheduleEvent(EVENT_SWITCH_PHASE, Seconds(60));
        }

        Unit* CalculateHatefulStrikeTarget()
        {
            uint64 health = 0;
            Unit* target = nullptr;

            ThreatContainer::StorageType threatList = me->getThreatManager().getThreatList();
            for (ThreatContainer::StorageType::const_iterator itr = threatList.begin(); itr != threatList.end(); ++itr)
            {
                Unit* unit = ObjectAccessor::GetUnit(*me, (*itr)->getUnitGuid());
                if (unit && me->IsWithinMeleeRange(unit))
                {
                    if (unit->GetHealth() > health)
                    {
                        health = unit->GetHealth();
                        target = unit;
                    }
                }
            }

            return target;
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK, true);
                    break;
                case EVENT_FLAME:
                    DoCast(SPELL_MOLTEN_PUNCH);
                    events.Repeat(Seconds(15), Seconds(20));
                    break;
                case EVENT_HATEFUL_STRIKE:
                    if (Unit* target = CalculateHatefulStrikeTarget())
                        DoCast(target, SPELL_HATEFUL_STRIKE);
                    events.Repeat(Seconds(5));
                    break;
                case EVENT_SWITCH_TARGET:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f, true))
                    {
                        DoResetThreat();
                        me->AddThreat(target, 1000000.0f);
                        DoCast(target, SPELL_CHARGE);
                        Talk(EMOTE_NEW_TARGET);
                    }
                    events.Repeat(Seconds(10));
                    break;
                case EVENT_VOLCANO:
                    DoCastAOE(SPELL_VOLCANIC_SUMMON, true);
                    Talk(EMOTE_GROUND_CRACK);
                    events.Repeat(Seconds(10));
                    break;
                case EVENT_SWITCH_PHASE:
                    ChangePhase();
                    break;
                default:
                    break;
            }
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<boss_supremusAI>(creature);
    }
};

class npc_molten_flame : public CreatureScript
{
public:
    npc_molten_flame() : CreatureScript("npc_molten_flame") { }

    struct npc_molten_flameAI : public NullCreatureAI
    {
        npc_molten_flameAI(Creature* creature) : NullCreatureAI(creature) { }

        void InitializeAI() override
        {
            float x, y, z;
            me->GetNearPoint(me, x, y, z, 1, 100.0f, frand(0.f, 2.f * float(M_PI)));
            me->GetMotionMaster()->MovePoint(0, x, y, z);
            DoCastSelf(SPELL_MOLTEN_FLAME, true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<npc_molten_flameAI>(creature);
    }
};

class npc_volcano : public CreatureScript
{
public:
    npc_volcano() : CreatureScript("npc_volcano") { }

    struct npc_volcanoAI : public NullCreatureAI
    {
        npc_volcanoAI(Creature* creature) : NullCreatureAI(creature) { }

        void Reset() override
        {
            _scheduler.Schedule(Seconds(3), [this](TaskContext /*context*/)
            {
                DoCastSelf(SPELL_VOLCANIC_ERUPTION);
            });
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_DISABLE_VULCANO)
            {
                me->RemoveAurasDueToSpell(SPELL_VOLCANIC_ERUPTION);
                me->RemoveAurasDueToSpell(SPELL_VOLCANIC_GEYSER);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _scheduler.Update(diff);
        }

    private:
        TaskScheduler _scheduler;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<npc_volcanoAI>(creature);
    }
};

void AddSC_boss_supremus()
{
    new boss_supremus();
    new npc_molten_flame();
    new npc_volcano();
}
