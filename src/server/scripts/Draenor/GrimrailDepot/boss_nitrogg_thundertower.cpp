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
    SPELL_BLACKROCK_GRENADE = 163539,
    SPELL_BLACKROCK_MORTAR = 163550,
    SPELL_BLACKROCK_MUNITIONS = 167709 // NO INFO OF THIS SPELL
};

enum Events
{
    EVENT_BLACKROCK_GRENADE = 1,
    EVENT_BLACKROCK_MORTAR,
    EVENT_BLACKROCK_MUNITIONS
};

class boss_nitrogg_thundertower : public CreatureScript
{
public:
    boss_nitrogg_thundertower() : CreatureScript("boss_nitrogg_thundertower") { }

    struct boss_nitrogg_thundertowerAI : public BossAI
    {
        boss_nitrogg_thundertowerAI(Creature* creature) : BossAI(creature, 79545)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_BLACKROCK_GRENADE, 4000);
            events.ScheduleEvent(EVENT_BLACKROCK_MORTAR, 8000);
            events.ScheduleEvent(EVENT_BLACKROCK_MUNITIONS, 12000);
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
                case EVENT_BLACKROCK_GRENADE:
                    DoCastVictim(SPELL_BLACKROCK_GRENADE);
                    events.ScheduleEvent(EVENT_BLACKROCK_GRENADE, 4000);
                    break;
                case EVENT_BLACKROCK_MORTAR:
                    DoCast(SPELL_BLACKROCK_MORTAR);
                    events.ScheduleEvent(EVENT_BLACKROCK_MORTAR, 8000);
                    break;
                case EVENT_BLACKROCK_MUNITIONS:
                    DoCast(SPELL_BLACKROCK_MUNITIONS);
                    events.ScheduleEvent(EVENT_BLACKROCK_MUNITIONS, 12000);
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
        return new boss_nitrogg_thundertowerAI(creature);
    }
};

void AddSC_boss_nitrogg_thundertower()
{
    new boss_nitrogg_thundertower();
}

