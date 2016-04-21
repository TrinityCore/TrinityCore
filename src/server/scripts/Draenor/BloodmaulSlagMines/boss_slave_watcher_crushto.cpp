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
    SPELL_CRUSHINGLEAP = 150751,
    SPELL_EARTHCRUSH = 153679,
    SPELL_FEROCIOUSYELL = 150759,
    SPELL_RAISETHEMINNERS = 150801,
    SPELL_WILDSLAM = 150753,
};

enum Events
{
    EVENT_CRUSHINGLEAP = 1,
    EVENT_EARTHCRUSH,
    EVENT_FEROCIOUSYELL,
    EVENT_RAISETHEMINNERS,
    EVENT_WILDSLAM,
};

enum Minners
{
    CAPTURED_MINNER = 74356,
};

class Boss_SlaveWatcherCrushto : public CreatureScript
{
public:
    Boss_SlaveWatcherCrushto() : CreatureScript("boss_slave_watcher_crushto") { }

    struct Boss_SlaveWatcherCrushtoAI : public BossAI
    {
        Boss_SlaveWatcherCrushtoAI(Creature* creature) : BossAI(creature, 74787)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_CRUSHINGLEAP, 4000);
            events.ScheduleEvent(EVENT_EARTHCRUSH, 8000);
            events.ScheduleEvent(EVENT_FEROCIOUSYELL, 12000);
            events.ScheduleEvent(EVENT_RAISETHEMINNERS, 16000);
            events.ScheduleEvent(EVENT_WILDSLAM, 20000);
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

            Position pos = me->GetPosition();

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CRUSHINGLEAP:
                    DoCastVictim(SPELL_CRUSHINGLEAP);
                    events.ScheduleEvent(EVENT_CRUSHINGLEAP, 4000);
                    break;
                case EVENT_EARTHCRUSH:
                    DoCastAOE(SPELL_EARTHCRUSH);
                    events.ScheduleEvent(EVENT_EARTHCRUSH, 8000);
                    break;
                case EVENT_FEROCIOUSYELL:
                    DoCast(me,SPELL_FEROCIOUSYELL);
                    DoCastAOE(SPELL_FEROCIOUSYELL);
                    events.ScheduleEvent(EVENT_FEROCIOUSYELL, 12000);
                    break;
                case EVENT_RAISETHEMINNERS:
                    DoCast(SPELL_RAISETHEMINNERS);
                    me->SummonCreature(CAPTURED_MINNER, pos.GetPositionX(), pos.GetPositionY(),pos.GetPositionZ(), 2.1f, TEMPSUMMON_DEAD_DESPAWN, 5000);
                    me->SummonCreature(CAPTURED_MINNER, pos.GetPositionX(), pos.GetPositionY(),pos.GetPositionZ(), 2.1f, TEMPSUMMON_DEAD_DESPAWN, 5000);
                    me->SummonCreature(CAPTURED_MINNER, pos.GetPositionX(), pos.GetPositionY(),pos.GetPositionZ(), 2.1f, TEMPSUMMON_DEAD_DESPAWN, 5000);
                    me->SummonCreature(CAPTURED_MINNER, pos.GetPositionX(), pos.GetPositionY(),pos.GetPositionZ(), 2.1f, TEMPSUMMON_DEAD_DESPAWN, 5000);
                    events.ScheduleEvent(EVENT_RAISETHEMINNERS, 16000);
                    break;
                case EVENT_WILDSLAM:
                    DoCastAOE(SPELL_WILDSLAM);
                    events.ScheduleEvent(EVENT_WILDSLAM, 20000);
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
        return new Boss_SlaveWatcherCrushtoAI(creature);
    }
};

void AddSC_Boss_SlaveWatcherCrushto()
{
    new Boss_SlaveWatcherCrushto();
}
