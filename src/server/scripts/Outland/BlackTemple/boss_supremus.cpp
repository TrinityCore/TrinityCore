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
struct boss_supremus : public BossAI
{
    boss_supremus(Creature* creature) : BossAI(creature, DATA_SUPREMUS) { }

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

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        ChangePhase();
        events.ScheduleEvent(EVENT_BERSERK, 15min);
        events.ScheduleEvent(EVENT_FLAME, 20s);
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
        ResetThreatList();
        DoZoneInCombat();
        events.ScheduleEvent(EVENT_SWITCH_PHASE, 1min);
    }

    Unit* CalculateHatefulStrikeTarget()
    {
        uint32 health = 0;
        Unit* target = nullptr;

        for (auto* ref : me->GetThreatManager().GetUnsortedThreatList())
        {
            Unit* unit = ref->GetVictim();
            if (me->IsWithinMeleeRange(unit))
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
                    ResetThreatList();
                    AddThreat(target, 1000000.0f);
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

struct npc_molten_flame : public NullCreatureAI
{
    npc_molten_flame(Creature* creature) : NullCreatureAI(creature) { }

    void InitializeAI() override
    {
        float x, y, z;
        me->GetNearPoint(me, x, y, z, 100.0f, frand(0.f, 2.f * float(M_PI)));
        me->GetMotionMaster()->MovePoint(0, x, y, z);
        DoCastSelf(SPELL_MOLTEN_FLAME, true);
    }
};

struct npc_volcano : public NullCreatureAI
{
    npc_volcano(Creature* creature) : NullCreatureAI(creature) { }

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

void AddSC_boss_supremus()
{
    RegisterBlackTempleCreatureAI(boss_supremus);
    RegisterBlackTempleCreatureAI(npc_molten_flame);
    RegisterBlackTempleCreatureAI(npc_volcano);
}
