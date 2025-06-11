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
#include "the_slave_pens.h"

enum QuagmirranSpells
{
    SPELL_ACID_SPRAY                = 38153,
    SPELL_CLEAVE                    = 40504,
    SPELL_UPPERCUT                  = 32055,
    SPELL_POISON_BOLT_VOLLEY        = 34780
};

enum QuagmirranEvents
{
    EVENT_ACID_SPRAY                = 1,
    EVENT_CLEAVE,
    EVENT_UPPERCUT,
    EVENT_POISON_BOLT_VOLLEY
};

// 17942 - Quagmirran
struct boss_quagmirran : public BossAI
{
    boss_quagmirran(Creature* creature) : BossAI(creature, DATA_QUAGMIRRAN) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_ACID_SPRAY, 25s);
        events.ScheduleEvent(EVENT_CLEAVE, 9s);
        events.ScheduleEvent(EVENT_UPPERCUT, 20s);
        events.ScheduleEvent(EVENT_POISON_BOLT_VOLLEY, 31s);
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
                case EVENT_ACID_SPRAY:
                    DoCastAOE(SPELL_ACID_SPRAY);
                    events.Repeat(20s, 25s);
                    break;
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    events.Repeat(18s, 34s);
                    break;
                case EVENT_UPPERCUT:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 10.0f, true))
                    DoCast(target, SPELL_UPPERCUT);
                    events.Repeat(22s);
                    break;
                case EVENT_POISON_BOLT_VOLLEY:
                    DoCastSelf(SPELL_POISON_BOLT_VOLLEY);
                    events.Repeat(24s);
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

void AddSC_boss_quagmirran()
{
    RegisterSlavePensCreatureAI(boss_quagmirran);
}
