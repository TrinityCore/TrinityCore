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

enum JandiceTexts
{
    EMOTE_DROP_JOURNAL          = 0
};

enum JandiceSpells
{
    SPELL_CURSE_OF_BLOOD        = 16098,
    SPELL_BANISH                = 8994,
    SPELL_SUMMON_ILLUSION       = 17773,
    SPELL_SPREAD                = 17774,

    SPELL_DROP_JOURNAL          = 26096
};

enum JandiceEvents
{
    EVENT_CURSE_OF_BLOOD        = 1,
    EVENT_BANISH,
    EVENT_SUMMON_ILLUSION
};

// 10503 - Jandice Barov
struct boss_jandice_barov : public ScriptedAI
{
    boss_jandice_barov(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_CURSE_OF_BLOOD, 5s, 10s);
        _events.ScheduleEvent(EVENT_BANISH, 10s, 15s);
        _events.ScheduleEvent(EVENT_SUMMON_ILLUSION, 15s, 25s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastSelf(SPELL_DROP_JOURNAL);
        Talk(EMOTE_DROP_JOURNAL);
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
                case EVENT_CURSE_OF_BLOOD:
                    DoCastSelf(SPELL_CURSE_OF_BLOOD);
                    _events.Repeat(25s, 30s);
                    break;
                case EVENT_BANISH:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_BANISH);
                    _events.Repeat(15s, 25s);
                    break;
                case EVENT_SUMMON_ILLUSION:
                    DoCastSelf(SPELL_SUMMON_ILLUSION);
                    DoCastSelf(SPELL_SPREAD);
                    _events.Repeat(30s, 40s);
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

void AddSC_boss_jandicebarov()
{
    RegisterScholomanceCreatureAI(boss_jandice_barov);
}
