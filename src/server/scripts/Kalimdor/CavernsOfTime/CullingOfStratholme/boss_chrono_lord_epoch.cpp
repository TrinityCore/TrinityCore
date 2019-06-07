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

#include "culling_of_stratholme.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include <vector>

enum Spells
{
    SPELL_CURSE_OF_EXERTION = 52772,
    SPELL_TIME_WARP = 52766,
    SPELL_TIME_STOP = 58848,
    SPELL_WOUNDING_STRIKE = 52771,
    SPELL_TIME_STEP_DUMMY = 52736,
    SPELL_TIME_STEP_CHARGE = 52737
};

enum Yells
{
    SAY_TIME_WARP = 2,
    SAY_SLAY = 3,
    SAY_DEATH = 4
};

enum Events
{
    EVENT_CURSE_OF_EXERTION = 1,
    EVENT_TIME_WARP,
    EVENT_TIME_STOP,
    EVENT_WOUNDING_STRIKE,
    EVENT_TIME_STEP
};

class boss_epoch : public CreatureScript
{
    public:
        boss_epoch() : CreatureScript("boss_epoch") { }

        struct boss_epochAI : public BossAI
        {
            boss_epochAI(Creature* creature) : BossAI(creature, DATA_EPOCH), _stepTargetIndex(0) { }

            void InitializeAI() override
            {
                if (instance->GetBossState(DATA_EPOCH) == DONE)
                    me->RemoveLootMode(LOOT_MODE_DEFAULT);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();

                _stepTargetIndex = 0;
                _stepTargets.clear();
                events.ScheduleEvent(EVENT_WOUNDING_STRIKE, Seconds(4), Seconds(6));
                events.ScheduleEvent(EVENT_CURSE_OF_EXERTION, Seconds(10), Seconds(17));
                events.ScheduleEvent(EVENT_TIME_WARP, Seconds(25));
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_TIME_STOP, Seconds(15));
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_CURSE_OF_EXERTION:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            DoCast(target, SPELL_CURSE_OF_EXERTION);
                        events.ScheduleEvent(EVENT_CURSE_OF_EXERTION, 9300);
                        break;
                    case EVENT_TIME_WARP:
                        Talk(SAY_TIME_WARP);
                        DoCastAOE(SPELL_TIME_WARP);
                        DoCastAOE(SPELL_TIME_STEP_DUMMY);
                        events.Repeat(Seconds(25));
                        break;
                    case EVENT_TIME_STOP:
                        DoCastAOE(SPELL_TIME_STOP);
                        events.Repeat(Seconds(25));
                        break;
                    case EVENT_WOUNDING_STRIKE:
                        DoCastVictim(SPELL_WOUNDING_STRIKE);
                        events.Repeat(Seconds(12), Seconds(18));
                        break;
                    case EVENT_TIME_STEP:
                    {
                        // In each step, we charge to a random target that was previously hit by SPELL_TIME_STEP_DUMMY
                        // Once we run out of targets, we charge back to the tank, then stop
                        uint32 nTargets = _stepTargets.size();
                        Unit* target = nullptr;
                        while (nTargets > _stepTargetIndex)
                        {
                            uint32 selected = urand(_stepTargetIndex, nTargets - 1);
                            if (_stepTargetIndex != selected)
                                std::swap(_stepTargets[_stepTargetIndex], _stepTargets[selected]);
                            if ((target = ObjectAccessor::GetUnit(*me, _stepTargets[_stepTargetIndex++])))
                                break;
                        }
                        if (target)
                            events.Repeat(Milliseconds(500));
                        else
                            target = me->GetVictim();

                        if (target)
                            DoCast(target, SPELL_TIME_STEP_CHARGE, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void SpellHitTarget(Unit* target, SpellInfo const* info) override
            {
                if (info->Id == SPELL_TIME_STEP_DUMMY && me->IsHostileTo(target))
                {
                    _stepTargets.push_back(target->GetGUID());
                    events.RescheduleEvent(EVENT_TIME_STEP, Milliseconds(500));
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

        private:
            uint32 _stepTargetIndex;
            std::vector<ObjectGuid> _stepTargets;
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
