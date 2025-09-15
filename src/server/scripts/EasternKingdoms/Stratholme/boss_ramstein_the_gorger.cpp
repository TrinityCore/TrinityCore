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
 * Intro NYI
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "stratholme.h"

enum RamsteinSpells
{
    SPELL_FLURRY            = 15088,
    SPELL_TRAMPLE           = 5568,
    SPELL_KNOCKOUT          = 17307
};

enum RamsteinEvents
{
    EVENT_TRAMPLE           = 1,
    EVENT_KNOCKOUT
};

enum RamsteinMisc
{
    SUMMON_GROUP_SENTRY     = 0,
    SUMMON_GROUP_UNDEAD     = 1
};

// 10439 - Ramstein the Gorger
struct boss_ramstein_the_gorger : public ScriptedAI
{
    boss_ramstein_the_gorger(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _events.Reset();
        DoCastSelf(SPELL_FLURRY);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_TRAMPLE, 10s, 15s);
        _events.ScheduleEvent(EVENT_KNOCKOUT, 10s, 20s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->SummonCreatureGroup(SUMMON_GROUP_SENTRY);
        me->SummonCreatureGroup(SUMMON_GROUP_UNDEAD);

        _instance->SetData(TYPE_RAMSTEIN, DONE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TRAMPLE:
                    DoCastSelf(SPELL_TRAMPLE);
                    _events.Repeat(10s, 25s);
                    break;
                case EVENT_KNOCKOUT:
                    DoCastVictim(SPELL_KNOCKOUT);
                    _events.Repeat(15s, 20s);
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
    EventMap _events;
    InstanceScript* _instance;
};

void AddSC_boss_ramstein_the_gorger()
{
    RegisterStratholmeCreatureAI(boss_ramstein_the_gorger);
}
