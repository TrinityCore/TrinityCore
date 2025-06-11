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
#include "scholomance.h"
#include "ScriptedCreature.h"

enum IlluciaSpells
{
    SPELL_CURSE_OF_AGONY        = 18671,
    SPELL_DOMINATE              = 7645, // UNUSED YET added for documentation
    SPELL_FEAR                  = 12542,
    SPELL_SHADOW_SHOCK          = 17234,
    SPELL_SILENCE               = 12528
};

enum IlluciaEvents
{
    EVENT_CURSE_OF_AGONY = 1,
    EVENT_SHADOW_SHOCK,
    EVENT_SILENCE,
    EVENT_FEAR
};

// 10502 - Lady Illucia Barov
struct boss_illucia_barov : public BossAI
{
    boss_illucia_barov(Creature* creature) : BossAI(creature, DATA_LADY_ILLUCIA_BAROV) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_CURSE_OF_AGONY, 18s);
        events.ScheduleEvent(EVENT_SHADOW_SHOCK, 9s);
        events.ScheduleEvent(EVENT_SILENCE, 5s);
        events.ScheduleEvent(EVENT_FEAR, 30s);
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
                    DoCastVictim(SPELL_CURSE_OF_AGONY);
                    events.Repeat(30s);
                    break;
                case EVENT_SHADOW_SHOCK:
                    DoCast(SelectTarget(SelectTargetMethod::Random, 0, 100, true), SPELL_SHADOW_SHOCK);
                    events.Repeat(12s);
                    break;
                case EVENT_SILENCE:
                    DoCastSelf(SPELL_SILENCE);
                    events.Repeat(14s);
                    break;
                case EVENT_FEAR:
                    DoCastVictim(SPELL_FEAR);
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
};

void AddSC_boss_illuciabarov()
{
    RegisterScholomanceCreatureAI(boss_illucia_barov);
}
