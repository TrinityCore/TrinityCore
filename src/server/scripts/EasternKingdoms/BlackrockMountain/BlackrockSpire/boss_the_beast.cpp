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
#include "blackrock_spire.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_FLAMEBREAK                = 16785,
    SPELL_IMMOLATE                  = 20294,
    SPELL_TERRIFYINGROAR            = 14100,
};

enum Events
{
    EVENT_FLAME_BREAK              = 1,
    EVENT_IMMOLATE                 = 2,
    EVENT_TERRIFYING_ROAR          = 3,
};

class boss_the_beast : public CreatureScript
{
public:
    boss_the_beast() : CreatureScript("boss_the_beast") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackrockSpireAI<boss_thebeastAI>(creature);
    }

    struct boss_thebeastAI : public BossAI
    {
        boss_thebeastAI(Creature* creature) : BossAI(creature, DATA_THE_BEAST) { }

        void Reset() override
        {
            _Reset();
        }

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);
            events.ScheduleEvent(EVENT_FLAME_BREAK,     12s);
            events.ScheduleEvent(EVENT_IMMOLATE,         3s);
            events.ScheduleEvent(EVENT_TERRIFYING_ROAR, 23s);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
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
                    case EVENT_FLAME_BREAK:
                        DoCastVictim(SPELL_FLAMEBREAK);
                        events.ScheduleEvent(EVENT_FLAME_BREAK, 10s);
                        break;
                    case EVENT_IMMOLATE:
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100, true))
                            DoCast(target, SPELL_IMMOLATE);
                        events.ScheduleEvent(EVENT_IMMOLATE, 8s);
                        break;
                    case EVENT_TERRIFYING_ROAR:
                        DoCastVictim(SPELL_TERRIFYINGROAR);
                        events.ScheduleEvent(EVENT_TERRIFYING_ROAR, 20s);
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
        }
    };
};

void AddSC_boss_thebeast()
{
    new boss_the_beast();
}
