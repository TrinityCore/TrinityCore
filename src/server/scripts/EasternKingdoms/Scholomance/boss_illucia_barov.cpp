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

enum IlluciaSpells
{
    SPELL_CURSE_OF_AGONY        = 18671,
    SPELL_DOMINATE_MIND         = 14515,
    SPELL_FEAR                  = 12542,
    SPELL_SHADOW_SHOCK          = 17289,
    SPELL_SILENCE               = 12528
};

enum IlluciaEvents
{
    EVENT_CURSE_OF_AGONY        = 1,
    EVENT_DOMINATE_MIND,
    EVENT_FEAR,
    EVENT_SHADOW_SHOCK,
    EVENT_SILENCE
};

// 10502 - Lady Illucia Barov
struct boss_illucia_barov : public BossAI
{
    boss_illucia_barov(Creature* creature) : BossAI(creature, DATA_LADY_ILLUCIA_BAROV) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_CURSE_OF_AGONY, 10s, 20s);
        events.ScheduleEvent(EVENT_DOMINATE_MIND, 15s, 25s);
        events.ScheduleEvent(EVENT_FEAR, 15s, 30s);
        events.ScheduleEvent(EVENT_SHADOW_SHOCK, 10s, 15s);
        events.ScheduleEvent(EVENT_SILENCE, 10s, 15s);
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
                case EVENT_CURSE_OF_AGONY:
                    DoCastSelf(SPELL_CURSE_OF_AGONY);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_DOMINATE_MIND:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1))
                        DoCast(target, SPELL_DOMINATE_MIND);
                    events.Repeat(25s, 40s);
                    break;
                case EVENT_FEAR:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_FEAR);
                    events.Repeat(15s, 25s);
                    break;
                case EVENT_SHADOW_SHOCK:
                    DoCastVictim(SPELL_SHADOW_SHOCK);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_SILENCE:
                    DoCastSelf(SPELL_SILENCE);
                    events.Repeat(20s, 30s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

void AddSC_boss_illuciabarov()
{
    RegisterScholomanceCreatureAI(boss_illucia_barov);
}
