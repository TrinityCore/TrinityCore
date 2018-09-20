/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "halls_of_stone.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"

enum Yells
{
    SAY_AGGRO                           = 0,
    SAY_SLAY                            = 1,
    SAY_DEATH                           = 2,
    SAY_STUN                            = 3
};

enum Spells
{
    SPELL_PARTING_SORROW                = 59723,
    SPELL_STORM_OF_GRIEF                = 50752,
    SPELL_SHOCK_OF_SORROW               = 50760,
    SPELL_PILLAR_OF_WOE                 = 50761
};

enum Events
{
    EVENT_PARTING_SORROW                = 1,
    EVENT_STORM_OF_GRIEF,
    EVENT_SHOCK_OF_SORROW,
    EVENT_PILLAR_OF_WOE
};

enum Achievements
{
    ACHIEV_GOOD_GRIEF_START_EVENT       = 20383,
};

class boss_maiden_of_grief : public CreatureScript
{
    public:
        boss_maiden_of_grief() : CreatureScript("boss_maiden_of_grief") { }

        struct boss_maiden_of_griefAI : public BossAI
        {
            boss_maiden_of_griefAI(Creature* creature) : BossAI(creature, DATA_MAIDEN_OF_GRIEF) { }

            void Reset() override
            {
                _Reset();

                if (IsHeroic())
                    events.ScheduleEvent(EVENT_PARTING_SORROW, 25s, 30s);
                events.ScheduleEvent(EVENT_STORM_OF_GRIEF, 10s);
                events.ScheduleEvent(EVENT_SHOCK_OF_SORROW, 20s, 25s);
                events.ScheduleEvent(EVENT_PILLAR_OF_WOE, 5s, 15s);

                instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_GOOD_GRIEF_START_EVENT);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();
                Talk(SAY_AGGRO);

                instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_GOOD_GRIEF_START_EVENT);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
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
                        case EVENT_PARTING_SORROW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_PARTING_SORROW);
                            events.ScheduleEvent(EVENT_PARTING_SORROW, 30s, 40s);
                            break;
                        case EVENT_STORM_OF_GRIEF:
                            DoCastVictim(SPELL_STORM_OF_GRIEF, true);
                            events.ScheduleEvent(EVENT_STORM_OF_GRIEF, 15s, 20s);
                            break;
                        case EVENT_SHOCK_OF_SORROW:
                            ResetThreatList();
                            Talk(SAY_STUN);
                            DoCastAOE(SPELL_SHOCK_OF_SORROW);
                            events.ScheduleEvent(EVENT_SHOCK_OF_SORROW, 20s, 30s);
                            break;
                        case EVENT_PILLAR_OF_WOE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                                DoCast(target, SPELL_PILLAR_OF_WOE);
                            else
                                DoCastVictim(SPELL_PILLAR_OF_WOE);
                            events.ScheduleEvent(EVENT_PILLAR_OF_WOE, 5s, 25s);
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
            return GetHallsOfStoneAI<boss_maiden_of_griefAI>(creature);
        }
};

void AddSC_boss_maiden_of_grief()
{
    new boss_maiden_of_grief();
}
