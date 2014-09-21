/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "blackrock_caverns.h"

enum Sounds
{
    SOUND_AGGRO                    = 18559,
    SOUND_DEATH                    = 18563
};

enum Spells
{
    SPELL_TERRIFYING_ROAR          = 76028, // Not yet Implemented
    SPELL_BERSERKER_CHARGE         = 76030,
    SPELL_MAGMA_SPIT               = 76031,
    SPELL_FLAMEBREAK               = 76032,
    SPELL_BERSERK                  = 82395  // Not yet Implemented
};

enum Events
{
    EVENT_TERRIFYING_ROAR          = 1,
    EVENT_BERSERKER_CHARGE         = 2,
    EVENT_MAGMA_SPIT               = 3,
    EVENT_FLAMEBREAK               = 4,
    EVENT_BERSERK                  = 5
};

class boss_beauty : public CreatureScript
{
    public: boss_beauty(): CreatureScript("boss_beauty") {}

        struct boss_beautyAI : public BossAI
        {
            boss_beautyAI(Creature* creature) : BossAI(creature, DATA_BEAUTY) {}

            void Reset() override
            {

            }

            void EnterCombat(Unit* who) override
            {
                _EnterCombat();
                events.ScheduleEvent(SPELL_MAGMA_SPIT, urand(7000, 10000));
                events.ScheduleEvent(EVENT_BERSERKER_CHARGE, urand(16000, 19000));
                events.ScheduleEvent(EVENT_FLAMEBREAK, urand(18000, 22000));
                DoPlaySoundToSet(me, SOUND_AGGRO);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                DoPlaySoundToSet(me, SOUND_DEATH);
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
                        case SPELL_MAGMA_SPIT:
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true), SPELL_MAGMA_SPIT, true);
                            events.ScheduleEvent(SPELL_MAGMA_SPIT, urand(7000, 10000));
                            break;
                        case EVENT_BERSERKER_CHARGE:
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true), SPELL_BERSERKER_CHARGE, true);
                            events.ScheduleEvent(EVENT_BERSERKER_CHARGE, urand(16000, 19000));
                            break;
                        case EVENT_FLAMEBREAK:
                            DoCast(me, SPELL_FLAMEBREAK);
                            events.ScheduleEvent(EVENT_FLAMEBREAK, urand(18000, 22000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_beautyAI(creature);
        }
};

void AddSC_boss_beauty()
{
    new boss_beauty();
}
