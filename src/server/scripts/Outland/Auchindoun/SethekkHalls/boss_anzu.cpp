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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "sethekk_halls.h"

enum AnzuTexts
{
    SAY_SUMMON_BROOD            = 0,
    SAY_SPELL_BOMB              = 1
};

enum AnzuSpells
{
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
    EVENT_SUMMON
};

enum AnzuPhases : uint8
{
    PHASE_NONE                  = 0,
    PHASE_HEALTH_66,
    PHASE_HEALTH_33
};

Position const PosSummonBrood[7] =
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
    boss_anzu(Creature* creature) : BossAI(creature, DATA_ANZU), _phase(PHASE_NONE) { }

    void Reset() override
    {
        //_Reset();
        events.Reset();
        _phase = PHASE_NONE;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_PARALYZING_SCREECH, 14s);
        events.ScheduleEvent(EVENT_CYCLONE_OF_FEATHERS, 5s);
    }

    void DamageTaken(Unit* /*killer*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_phase < PHASE_HEALTH_66 && me->HealthBelowPctDamaged(66, damage))
        {
            _phase++;
            Talk(SAY_SUMMON_BROOD);
            events.ScheduleEvent(EVENT_SUMMON, 3s);
        }

        if (_phase < PHASE_HEALTH_33 && me->HealthBelowPctDamaged(33, damage))
        {
            _phase++;
            Talk(SAY_SUMMON_BROOD);
            events.ScheduleEvent(EVENT_SUMMON, 3s);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_PARALYZING_SCREECH:
                    DoCastVictim(SPELL_PARALYZING_SCREECH);
                    events.Repeat(25s);
                    break;
                case EVENT_CYCLONE_OF_FEATHERS:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_CYCLONE_OF_FEATHERS);
                    events.Repeat(21s);
                    break;
                case EVENT_SUMMON:
                    // TODO: Add pathing for Brood of Anzu
                    for (uint8 i = 0; i < 7; i++)
                        me->SummonCreature(NPC_BROOD_OF_ANZU, PosSummonBrood[i], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 46s);

                    DoCastSelf(SPELL_BANISH_SELF);
                    events.ScheduleEvent(EVENT_SPELL_BOMB, 12s);
                    break;
                case EVENT_SPELL_BOMB:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    {
                        if (target->GetPowerType() == POWER_MANA)
                        {
                            DoCast(target, SPELL_SPELL_BOMB);
                            Talk(SAY_SPELL_BOMB, target);
                        }
                    }
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    uint8 _phase;
};

void AddSC_boss_anzu()
{
    RegisterSethekkHallsCreatureAI(boss_anzu);
}
