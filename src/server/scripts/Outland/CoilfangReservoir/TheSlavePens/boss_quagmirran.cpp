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

/* ScriptData
SDName: boss_quagmirran
SD%Complete: 100%
SDComment:
SDCategory: Coilfang Reservoir, The Slave Pens
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "the_slave_pens.h"

enum Spells
{
    SPELL_ACID_SPRAY                = 38153,
    SPELL_CLEAVE                    = 40504,
    SPELL_UPPERCUT                  = 32055,
    SPELL_POISON_BOLT_VOLLEY        = 34780 // 39340
};

enum Events
{
    EVENT_ACID_SPRAY                = 1,
    EVENT_CLEAVE                    = 2,
    EVENT_UPPERCUT                  = 3,
    EVENT_POISON_BOLT_VOLLEY        = 4
};

struct boss_quagmirran : public BossAI
{
    boss_quagmirran(Creature* creature) : BossAI(creature, DATA_QUAGMIRRAN) { }

    void Reset() override
    {
        _Reset();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_ACID_SPRAY, 25s);
        events.ScheduleEvent(EVENT_CLEAVE, 9s);
        events.ScheduleEvent(EVENT_UPPERCUT, 20s);
        events.ScheduleEvent(EVENT_POISON_BOLT_VOLLEY, 31s);
    }

    void KilledUnit(Unit* /*victim*/) override { }

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
                    events.ScheduleEvent(EVENT_ACID_SPRAY, 20s, 25s);
                    break;
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE, true);
                    events.ScheduleEvent(EVENT_CLEAVE, 18s, 34s);
                    break;
                case EVENT_UPPERCUT:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 10.0f, true))
                    DoCast(target, SPELL_UPPERCUT);
                    events.ScheduleEvent(EVENT_UPPERCUT, 22s);
                    break;
                case EVENT_POISON_BOLT_VOLLEY:
                    DoCast(me, SPELL_POISON_BOLT_VOLLEY);
                    events.ScheduleEvent(EVENT_POISON_BOLT_VOLLEY, 24s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

void AddSC_boss_quagmirran()
{
    RegisterSlavePensCreatureAI(boss_quagmirran);
}
