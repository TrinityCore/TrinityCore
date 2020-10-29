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
#include "scarlet_monastery.h"

enum Yells
{
    SAY_AGGRO               = 0,
    SAY_HEALTH_BELOW_50     = 1,
    SAY_SLAY                = 2
};

enum Spells
{
    SPELL_SHADOW_BOLT   = 20825,
    SPELL_FIRE_NOVA     = 12470,
    SPELL_FLAME_SHOCK   = 23038,
    SPELL_FLAME_SPIKE   = 8814
};

enum Events
{
    EVENT_SHADOW_BOLT = 1,
    EVENT_FIRE_NOVA,
    EVENT_FLAME_SHOCK,
    EVENT_FLAME_SPIKE
};

static constexpr uint8 const MaxChainedEvents = 4;

struct boss_bloodmage_thalnos : public BossAI
{
    boss_bloodmage_thalnos(Creature* creature) : BossAI(creature, DATA_BLOODMAGE_THALNOS), _triggeredText(false)
    {
        InitializeEventCooldowns();
    }

    void Reset() override
    {
        _triggeredText = false;
        InitializeEventCooldowns();
        _Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_FLAME_SPIKE, 8s, 10s);
        events.ScheduleEvent(EVENT_SHADOW_BOLT, 1ms);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer())
            Talk(SAY_SLAY);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (!_triggeredText && me->HealthBelowPctDamaged(50, damage))
        {
            Talk(SAY_HEALTH_BELOW_50);
            _triggeredText = true;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SHADOW_BOLT:
                    DoCastVictim(SPELL_SHADOW_BOLT);
                    ScheduleNextEvent();
                    break;
                case EVENT_FLAME_SHOCK:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20.f, true, true, -SPELL_FLAME_SHOCK))
                        DoCast(target, SPELL_FLAME_SHOCK);
                    else
                        DoCastVictim(SPELL_FLAME_SHOCK);

                    ScheduleNextEvent();
                    break;
                case EVENT_FIRE_NOVA:
                    DoCastAOE(SPELL_FIRE_NOVA);
                    ScheduleNextEvent();
                    break;
                case EVENT_FLAME_SPIKE:
                    DoCastVictim(SPELL_FLAME_SPIKE);
                    events.Repeat(3min);
                    break;
                default:
                    break;
            }
        }

        if (!me->HasSpellFocus())
            DoMeleeAttackIfReady();
    }

private:
    bool _triggeredText;
    int8 _remainingEventCycles[MaxChainedEvents];

    void InitializeEventCooldowns()
    {
        _remainingEventCycles[EVENT_SHADOW_BOLT] = 0;
        _remainingEventCycles[EVENT_FLAME_SHOCK] = 1;
        _remainingEventCycles[EVENT_FIRE_NOVA] = 3;
    }

    void UpdateEventCooldowns()
    {
        for (uint8 i : { EVENT_FIRE_NOVA, EVENT_FLAME_SHOCK })
        {
            if (_remainingEventCycles[i] == 0)
            {
                if (i == EVENT_FLAME_SHOCK)
                    _remainingEventCycles[i] = 2;
                else if (i == EVENT_FIRE_NOVA)
                    _remainingEventCycles[i] = 3;
            }
            else
                _remainingEventCycles[i]--;
        }
    }

    uint32 GetNextEventId() const
    {
        std::vector<uint32> possibleEventIds;
        for (uint8 i : { EVENT_SHADOW_BOLT, EVENT_FIRE_NOVA, EVENT_FLAME_SHOCK })
        {
            // We have an long overdue event pending. Prioritize it.
            if (_remainingEventCycles[i] <= -3)
                return i;

            // Otherwise pick a random event that's ready for execution
            if (_remainingEventCycles[i] == 0)
                possibleEventIds.push_back(i);
        }

        if (!possibleEventIds.empty())
            return Trinity::Containers::SelectRandomContainerElement(possibleEventIds);

        return 0;
    }

    void ScheduleNextEvent()
    {
        UpdateEventCooldowns();
        events.ScheduleEvent(GetNextEventId(), 3s);
    }
};

void AddSC_boss_bloodmage_thalnos()
{
    RegisterScarletMonasteryCreatureAI(boss_bloodmage_thalnos);
}
