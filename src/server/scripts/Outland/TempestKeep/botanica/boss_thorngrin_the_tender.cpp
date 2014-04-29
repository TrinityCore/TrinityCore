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
#include "the_botanica.h"

enum Says
{
    SAY_AGGRO                   = 0,
    SAY_20_PERCENT_HP           = 1,
    SAY_KILL                    = 2,
    SAY_CAST_SACRIFICE          = 3,
    SAY_50_PERCENT_HP           = 4,
    SAY_CAST_HELLFIRE           = 5,
    SAY_DEATH                   = 6,
    EMOTE_ENRAGE                = 7
};

enum Spells
{
    SPELL_SACRIFICE             = 34661,
    SPELL_HELLFIRE_NORMAL       = 34659,
    SPELL_HELLFIRE_HEROIC       = 39131,
    SPELL_ENRAGE                = 34670
};

enum Events
{
    EVENT_SACRIFICE             = 1,
    EVENT_HELLFIRE              = 2,
    EVENT_ENRAGE                = 3
};

class boss_thorngrin_the_tender : public CreatureScript
{
    public: boss_thorngrin_the_tender() : CreatureScript("thorngrin_the_tender") { }

        struct boss_thorngrin_the_tenderAI : public BossAI
        {
            boss_thorngrin_the_tenderAI(Creature* creature) : BossAI(creature, DATA_THORNGRIN_THE_TENDER) { }

            void Reset() override
            {
                _Reset();
                _phase1 = true;
                _phase2 = true;
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                events.ScheduleEvent(EVENT_SACRIFICE, 5700);
                events.ScheduleEvent(EVENT_HELLFIRE, IsHeroic() ? urand(17400, 19300) : 18000);
                events.ScheduleEvent(EVENT_ENRAGE, 12000);
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(SAY_KILL);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void DamageTaken(Unit* /*killer*/, uint32 &damage) override
            {
                if (me->HealthBelowPctDamaged(50, damage) && _phase1)
                {
                    _phase1 = false;
                    Talk(SAY_50_PERCENT_HP);
                }
                if (me->HealthBelowPctDamaged(20, damage) && _phase2)
                {
                    _phase2 = false;
                    Talk(SAY_20_PERCENT_HP);
                }
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
                        case EVENT_SACRIFICE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                            {
                                Talk(SAY_CAST_SACRIFICE);
                                DoCast(target, SPELL_SACRIFICE, true);
                            }
                            events.ScheduleEvent(EVENT_SACRIFICE, 29400);
                            break;
                        case EVENT_HELLFIRE:
                            Talk(SAY_CAST_HELLFIRE);
                            DoCastVictim(DUNGEON_MODE(SPELL_HELLFIRE_NORMAL, SPELL_HELLFIRE_HEROIC), true);
                            events.ScheduleEvent(EVENT_HELLFIRE, IsHeroic() ? urand(17400, 19300) : 18000);
                            break;
                        case EVENT_ENRAGE:
                            Talk(EMOTE_ENRAGE);
                            DoCast(me, SPELL_ENRAGE);
                            events.ScheduleEvent(EVENT_ENRAGE, 33000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool _phase1;
            bool _phase2;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_thorngrin_the_tenderAI(creature);
        }
};

void AddSC_boss_thorngrin_the_tender()
{
    new boss_thorngrin_the_tender();
}
