/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

enum Spells
{
    SPELL_EVICT_SOUL = 115297,
    SPELL_RAISE_FALLEN_CRUSADER = 115139,
    SPELL_SPIRIT_GALE = 115289,
    SPELL_SUMMON_EMPOWERING_SPIRITS = 115147
};

enum Events
{
    EVENT_EVICT_SOUL = 1,
    EVENT_RAISE_FALLEN_CRUSADER,
    EVENT_SPIRIT_GALE,
    EVENT_SUMMON_EMPOWERING_SPIRITS
};

class boss_thalnos_the_soulrender : public CreatureScript
{
public:
    boss_thalnos_the_soulrender() : CreatureScript("boss_thalnos_the_soulrender") { }

    struct boss_thalnos_the_soulrenderAI : public BossAI
    {
        boss_thalnos_the_soulrenderAI(Creature* creature) : BossAI(creature, 59789)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_EVICT_SOUL, 4000);
            events.ScheduleEvent(EVENT_RAISE_FALLEN_CRUSADER, 12000);
            events.ScheduleEvent(EVENT_SPIRIT_GALE, 16000);
            events.ScheduleEvent(EVENT_SUMMON_EMPOWERING_SPIRITS, 20000);
        }

        void KilledUnit(Unit * /*victim*/) override
        {
        }

        void JustDied(Unit * /*victim*/) override
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
                case EVENT_EVICT_SOUL:
                    DoCast(SPELL_EVICT_SOUL);
                    events.ScheduleEvent(EVENT_EVICT_SOUL, 4000);
                    break;
                case EVENT_RAISE_FALLEN_CRUSADER:
                    DoCast(SPELL_RAISE_FALLEN_CRUSADER);
                    events.ScheduleEvent(EVENT_RAISE_FALLEN_CRUSADER, 12000);
                    break;
                case EVENT_SPIRIT_GALE:
                    DoCastAOE(SPELL_SPIRIT_GALE);
                    events.ScheduleEvent(EVENT_SPIRIT_GALE, 16000);
                    break;
                case EVENT_SUMMON_EMPOWERING_SPIRITS:
                    DoCast(SPELL_SUMMON_EMPOWERING_SPIRITS);
                    events.ScheduleEvent(EVENT_SUMMON_EMPOWERING_SPIRITS, 20000);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_thalnos_the_soulrenderAI(creature);
    }
};

void AddSC_boss_thalnos_the_soulrender()
{
    new boss_thalnos_the_soulrender();
}
