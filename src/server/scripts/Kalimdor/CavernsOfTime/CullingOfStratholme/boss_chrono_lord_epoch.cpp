/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

/* Script Data Start
SDName: Boss epoch
SDAuthor: Tartalo
SD%Complete: 80
SDComment: @todo Intro, consecutive attacks to a random target durin time wrap, adjust timers
SDCategory:
Script Data End */

#include "ScriptMgr.h"
#include "culling_of_stratholme.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_CURSE_OF_EXERTION                     = 52772,
    SPELL_TIME_WARP                             = 52766, //Time slows down, reducing attack, casting and movement speed by 70% for 6 sec.
    SPELL_TIME_STOP                             = 58848, //Stops time in a 50 yard sphere for 2 sec.
    SPELL_WOUNDING_STRIKE                       = 52771  //Used only on the tank
};

enum Yells
{
    SAY_INTRO                                   = 0,
    SAY_AGGRO                                   = 1,
    SAY_TIME_WARP                               = 2,
    SAY_SLAY                                    = 3,
    SAY_DEATH                                   = 4
};

enum Events
{
    EVENT_CURSE_OF_EXERTION                     = 1,
    EVENT_TIME_WARP,
    EVENT_TIME_STOP,
    EVENT_WOUNDING_STRIKE
};

class boss_epoch : public CreatureScript
{
    public:
        boss_epoch() : CreatureScript("boss_epoch") { }

        struct boss_epochAI : public BossAI
        {
            boss_epochAI(Creature* creature) : BossAI(creature, DATA_EPOCH) { }

            void JustEngagedWith(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                _JustEngagedWith();

                events.ScheduleEvent(EVENT_CURSE_OF_EXERTION, 9300ms);
                events.ScheduleEvent(EVENT_TIME_WARP, 25300);
                events.ScheduleEvent(EVENT_TIME_STOP, 21300);
                events.ScheduleEvent(EVENT_WOUNDING_STRIKE, 5300ms);
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_CURSE_OF_EXERTION:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            DoCast(target, SPELL_CURSE_OF_EXERTION);
                        events.ScheduleEvent(EVENT_CURSE_OF_EXERTION, 9300ms);
                        break;
                    case EVENT_TIME_WARP:
                        Talk(SAY_TIME_WARP);
                        DoCastAOE(SPELL_TIME_WARP);
                        events.ScheduleEvent(EVENT_TIME_WARP, 25300);
                        break;
                    case EVENT_TIME_STOP:
                        DoCastAOE(SPELL_TIME_STOP);
                        events.ScheduleEvent(EVENT_TIME_STOP, 21300);
                        break;
                    case EVENT_WOUNDING_STRIKE:
                        DoCastVictim(SPELL_WOUNDING_STRIKE);
                        events.ScheduleEvent(EVENT_WOUNDING_STRIKE, 5300ms);
                        break;
                    default:
                        break;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                _JustDied();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetCullingOfStratholmeAI<boss_epochAI>(creature);
        }
};

void AddSC_boss_epoch()
{
    new boss_epoch();
}
