/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
    SPELL_FROSTBOLT         = 21369,
    SPELL_ICE_ARMOR         = 18100, // This is actually a buff he gives himself
    SPELL_FREEZE            = 18763,
    SPELL_FEAR              = 26070,
    SPELL_CHILL_NOVA        = 18099,
    SPELL_FROSTVOLLEY       = 8398
};

enum Events
{
    EVENT_FROSTBOLT = 1,
    EVENT_ICE_ARMOR,
    EVENT_FREEZE,
    EVENT_FEAR,
    EVENT_CHILL_NOVA,
    EVENT_FROSTVOLLEY
};

class boss_boss_ras_frostwhisper : public CreatureScript
{
public:
    boss_boss_ras_frostwhisper() : CreatureScript("boss_boss_ras_frostwhisper") { }

    struct boss_rasfrostAI : public ScriptedAI
    {
        boss_rasfrostAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            events.Reset();
            DoCast(me, SPELL_ICE_ARMOR);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ICE_ARMOR, 2000);
            events.ScheduleEvent(EVENT_FROSTBOLT, 8000);
            events.ScheduleEvent(EVENT_CHILL_NOVA, 12000);
            events.ScheduleEvent(EVENT_FREEZE, 18000);
            events.ScheduleEvent(EVENT_FEAR, 45000);
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
                    case EVENT_ICE_ARMOR:
                        DoCast(me, SPELL_ICE_ARMOR);
                        events.ScheduleEvent(EVENT_ICE_ARMOR, 180000);
                        break;
                    case EVENT_FROSTBOLT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                            DoCast(target, SPELL_FROSTBOLT);
                        events.ScheduleEvent(EVENT_FROSTBOLT, 8000);
                        break;
                    case EVENT_FREEZE:
                        DoCastVictim(SPELL_FREEZE);
                        events.ScheduleEvent(EVENT_FREEZE, 24000);
                        break;
                    case EVENT_FEAR:
                        DoCastVictim(SPELL_FEAR);
                        events.ScheduleEvent(EVENT_FEAR, 30000);
                        break;
                    case EVENT_CHILL_NOVA:
                        DoCastVictim(SPELL_CHILL_NOVA);
                        events.ScheduleEvent(EVENT_CHILL_NOVA, 14000);
                        break;
                    case EVENT_FROSTVOLLEY:
                        DoCastVictim(SPELL_FROSTVOLLEY);
                        events.ScheduleEvent(EVENT_FROSTVOLLEY, 15000);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        private:
            EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_rasfrostAI(creature);
    }
};

void AddSC_boss_rasfrost()
{
    new boss_boss_ras_frostwhisper();
}
