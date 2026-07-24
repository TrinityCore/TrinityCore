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
#include "scholomance.h"
#include "ScriptedCreature.h"

enum DarkreaverTexts
{
    SAY_SPAWN                     = 0
};

enum DarkreaverSpells
{
    SPELL_SHADOW_BOLT             = 17393,
    SPELL_CLEAVE                  = 15284,
    SPELL_BLOOD_LEECH             = 22644,
    SPELL_DOMINATE_MIND           = 7645,

    SPELL_SUMMON_FALLEN_CHARGER   = 23261
};

enum DarkreaverEvents
{
    EVENT_SHADOW_BOLT             = 1,
    EVENT_CLEAVE,
    EVENT_BLOOD_LEECH,
    EVENT_DOMINATE_MIND
};

// 14516 - Death Knight Darkreaver
struct boss_death_knight_darkreaver : public ScriptedAI
{
    boss_death_knight_darkreaver(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        Talk(SAY_SPAWN);
    }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_SHADOW_BOLT, 0s);
        _events.ScheduleEvent(EVENT_CLEAVE, 5s, 10s);
        _events.ScheduleEvent(EVENT_BLOOD_LEECH, 10s, 15s);
        _events.ScheduleEvent(EVENT_DOMINATE_MIND, 10s, 15s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastSelf(SPELL_SUMMON_FALLEN_CHARGER, true);
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
                case EVENT_SHADOW_BOLT:
                    DoCastVictim(SPELL_SHADOW_BOLT);
                    _events.Repeat(5s, 10s);
                    break;
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    _events.Repeat(5s, 10s);
                    break;
                case EVENT_BLOOD_LEECH:
                    DoCastSelf(SPELL_BLOOD_LEECH);
                    _events.Repeat(15s, 25s);
                    break;
                case EVENT_DOMINATE_MIND:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1))
                        DoCast(target, SPELL_DOMINATE_MIND);
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
};

void AddSC_boss_death_knight_darkreaver()
{
    RegisterScholomanceCreatureAI(boss_death_knight_darkreaver);
}
