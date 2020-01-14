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

#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "wailing_caverns.h"

enum Texts
{
    SAY_AGGRO = 0
};

enum Spells
{
    SPELL_LIGHTNING_BOLT       = 20805,
    SPELL_DRUID_SLUMBER        = 8040,
    SPELL_COBRAHN_SERPENT_FORM = 7965,
    SPELL_POISON               = 744
};

enum Events
{
    EVENT_LIGHTNING_BOLT       = 1,
    EVENT_DRUID_SLUMBER        = 2,
    EVENT_COBRAHN_SERPENT_FORM = 3,
    EVENT_POISON               = 4
};

enum Phases
{
    PHASE_NORMAL       = 1,
    PHASE_SERPENT_FORM = 2
};

class boss_lord_cobrahn : public CreatureScript
{
public:
    boss_lord_cobrahn() : CreatureScript("boss_lord_cobrahn") { }

    struct boss_lord_cobrahnAI : public BossAI
    {
        boss_lord_cobrahnAI(Creature* creature) : BossAI(creature, DATA_LORD_COBRAHN) { }

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);
            Talk(SAY_AGGRO);
            events.SetPhase(PHASE_NORMAL);
            events.ScheduleEvent(EVENT_LIGHTNING_BOLT, Seconds(1), 0, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_DRUID_SLUMBER, Seconds(20), 0, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_COBRAHN_SERPENT_FORM, Seconds(38), 0, PHASE_NORMAL);
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
                    case EVENT_LIGHTNING_BOLT:
                        DoCastVictim(SPELL_LIGHTNING_BOLT);
                        events.ScheduleEvent(EVENT_LIGHTNING_BOLT, Seconds(1), 0, PHASE_NORMAL);
                        break;
                    case EVENT_DRUID_SLUMBER:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            DoCast(target, SPELL_DRUID_SLUMBER);
                        break;
                    case EVENT_COBRAHN_SERPENT_FORM:
                        events.SetPhase(PHASE_SERPENT_FORM);
                        DoCastSelf(SPELL_COBRAHN_SERPENT_FORM);
                        events.ScheduleEvent(EVENT_POISON, Seconds(13), PHASE_SERPENT_FORM);
                        break;
                    case EVENT_POISON:
                        DoCastVictim(SPELL_POISON);
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetWailingCavernsAI<boss_lord_cobrahnAI>(creature);
    }
};


void AddSC_boss_lord_cobrahn()
{
    new boss_lord_cobrahn();
}
