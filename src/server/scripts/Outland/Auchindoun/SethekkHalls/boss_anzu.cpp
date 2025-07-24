/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

/*
 * Pathing for Brood of Anzu is NYI (try to remove extra flag to ignore pathfinding when paths will be implemented)
 * Birds-helpers are NYI
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "sethekk_halls.h"

enum AnzuTexts
{
    SAY_INTRO_1                 = 0,
    SAY_INTRO_2                 = 1,
    SAY_SUMMON                  = 2,
    SAY_BOMB                    = 3
};

enum AnzuSpells
{
    SPELL_SHADOWFORM            = 37816,

    SPELL_PARALYZING_SCREECH    = 40184,
    SPELL_SPELL_BOMB            = 40303,
    SPELL_CYCLONE_OF_FEATHERS   = 40321,
    SPELL_BANISH_SELF           = 42354
};

enum AnzuEvents
{
    EVENT_PARALYZING_SCREECH    = 1,
    EVENT_SPELL_BOMB,
    EVENT_CYCLONE_OF_FEATHERS,
    EVENT_SUMMON_1,
    EVENT_SUMMON_2,

    EVENT_INTRO_1,
    EVENT_INTRO_2,
    EVENT_INTRO_3
};

enum AnzuPhases : uint8
{
    PHASE_NONE                  = 0,
    PHASE_HEALTH_66,
    PHASE_HEALTH_33
};

enum AnzuMisc
{
    NPC_BROOD_OF_ANZU           = 23132
};

static Position const PosSummonBrood[] =
{
    { -118.1717f, 284.5299f, 121.2287f, 2.775074f },
    { -98.15528f, 293.4469f, 109.2385f, 0.174533f },
    { -99.70160f, 270.1699f, 98.27389f, 6.178465f },
    { -69.25543f, 303.0768f, 97.84479f, 5.532694f },
    { -87.59662f, 263.5181f, 92.70478f, 1.658063f },
    { -73.54323f, 276.6267f, 94.25807f, 2.802979f },
    { -81.70527f, 280.8776f, 44.58830f, 0.526849f }
};

// 23035 - Anzu
struct boss_anzu : public BossAI
{
    boss_anzu(Creature* creature) : BossAI(creature, DATA_ANZU), _phase(PHASE_NONE), _deadBroodCount(0) { }

    void JustAppeared() override
    {
        events.ScheduleEvent(EVENT_INTRO_1, 0s);
    }

    void Reset() override
    {
        _Reset();
        _phase = PHASE_NONE;
        _deadBroodCount = 0;
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_PARALYZING_SCREECH, 15s, 25s);
        events.ScheduleEvent(EVENT_SPELL_BOMB, 20s, 30s);
        events.ScheduleEvent(EVENT_CYCLONE_OF_FEATHERS, 10s, 15s);
    }

    void DamageTaken(Unit* /*killer*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_phase < PHASE_HEALTH_66 && me->HealthBelowPctDamaged(66, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_SUMMON_1, 0s);
        }

        if (_phase < PHASE_HEALTH_33 && me->HealthBelowPctDamaged(33, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_SUMMON_1, 0s);
        }
    }

    void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
    {
        _deadBroodCount++;

        if (_deadBroodCount == std::size(PosSummonBrood))
        {
            me->RemoveAurasDueToSpell(SPELL_BANISH_SELF);
            _deadBroodCount = 0;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_INTRO_1:
                        Talk(SAY_INTRO_1);
                        DoCastSelf(SPELL_SHADOWFORM);
                        events.ScheduleEvent(EVENT_INTRO_2, 6s);
                        break;
                    case EVENT_INTRO_2:
                        Talk(SAY_INTRO_2);
                        events.ScheduleEvent(EVENT_INTRO_3, 4s);
                        break;
                    case EVENT_INTRO_3:
                        me->RemoveAurasDueToSpell(SPELL_SHADOWFORM);
                        me->SetImmuneToAll(false);
                        break;
                    default:
                        break;
                }
            }
            return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_PARALYZING_SCREECH:
                    DoCastSelf(SPELL_PARALYZING_SCREECH);
                    events.Repeat(25s, 35s);
                    break;
                case EVENT_SPELL_BOMB:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    {
                        if (target->GetPowerType() == POWER_MANA)
                        {
                            DoCast(target, SPELL_SPELL_BOMB);
                            Talk(SAY_BOMB, target);
                        }
                    }
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_CYCLONE_OF_FEATHERS:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_CYCLONE_OF_FEATHERS);
                    events.Repeat(20s, 25s);
                    break;
                case EVENT_SUMMON_1:
                    me->SetReactState(REACT_PASSIVE);
                    Talk(SAY_SUMMON);

                    _deadBroodCount = 0;
                    for (Position const& summonPos : PosSummonBrood)
                        me->SummonCreature(NPC_BROOD_OF_ANZU, summonPos, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 46s);

                    events.ScheduleEvent(EVENT_SUMMON_2, 3s);
                    break;
                case EVENT_SUMMON_2:
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoCastSelf(SPELL_BANISH_SELF);
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
    uint8 _phase;
    uint8 _deadBroodCount;
};

void AddSC_boss_anzu()
{
    RegisterSethekkHallsCreatureAI(boss_anzu);
}
