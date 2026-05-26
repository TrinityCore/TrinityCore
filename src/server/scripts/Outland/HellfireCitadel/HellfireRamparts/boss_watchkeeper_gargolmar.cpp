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
 * Timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "hellfire_ramparts.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

enum GargolmarTexts
{
    SAY_TAUNT              = 0,
    SAY_HEAL               = 1,
    SAY_SURGE              = 2,
    SAY_AGGRO              = 3,
    SAY_SLAY               = 4
};

enum GargolmarSpells
{
    SPELL_MORTAL_WOUND     = 30641,
    SPELL_SURGE            = 34645,
    SPELL_REQUEST_HEAL     = 30642,
    SPELL_RETALIATION      = 22857
};

enum GargolmarEvents
{
    EVENT_TAUNT            = 1,
    EVENT_MORTAL_WOUND,
    EVENT_SURGE,
    EVENT_REQUEST_HEAL,
    EVENT_RETALIATION
};

enum GargolmarMisc
{
    SOUND_DEATH            = 10336
};

// 17306 - Watchkeeper Gargolmar
struct boss_watchkeeper_gargolmar : public BossAI
{
    boss_watchkeeper_gargolmar(Creature* creature) : BossAI(creature, DATA_WATCHKEEPER_GARGOLMAR), _hasRequestedHeal(false), _hasRetaliation(false) { }

    void JustAppeared() override
    {
        // This is just timed, not on LoS or areatrigger (the source is videos)
        events.ScheduleEvent(EVENT_TAUNT, 10min, 15min);
    }

    void Reset() override
    {
        _Reset();
        _hasRequestedHeal = false;
        _hasRetaliation = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_MORTAL_WOUND, 5s, 10s);
        events.ScheduleEvent(EVENT_SURGE, 3s, 5s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_hasRequestedHeal && me->HealthBelowPctDamaged(40, damage))
        {
            _hasRequestedHeal = true;
            events.ScheduleEvent(EVENT_REQUEST_HEAL, 0s);
        }

        if (!_hasRetaliation && me->HealthBelowPctDamaged(20, damage))
        {
            _hasRetaliation = true;
            events.ScheduleEvent(EVENT_RETALIATION, 0s);
        }
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_SURGE:
                if (roll_chance_i(50))
                    Talk(SAY_SURGE);
                break;
            case SPELL_REQUEST_HEAL:
                Talk(SAY_HEAL);
                break;
            default:
                break;
        }
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        DoPlaySoundToSet(me, SOUND_DEATH);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                if (eventId == EVENT_TAUNT)
                    Talk(SAY_TAUNT);
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
                case EVENT_MORTAL_WOUND:
                    DoCastVictim(SPELL_MORTAL_WOUND);
                    events.Repeat(5s, 15s);
                    break;
                case EVENT_SURGE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::MaxDistance, 0))
                        DoCast(target, SPELL_SURGE);
                    events.Repeat(15s, 40s);
                    break;
                case EVENT_REQUEST_HEAL:
                    DoCastSelf(SPELL_REQUEST_HEAL);
                    break;
                case EVENT_RETALIATION:
                    DoCastSelf(SPELL_RETALIATION);
                    events.Repeat(30s);
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
    bool _hasRequestedHeal;
    bool _hasRetaliation;
};

void AddSC_boss_watchkeeper_gargolmar()
{
    RegisterHellfireRampartsCreatureAI(boss_watchkeeper_gargolmar);
}
