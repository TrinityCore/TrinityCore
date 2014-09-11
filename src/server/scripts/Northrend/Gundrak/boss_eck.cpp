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
#include "gundrak.h"

enum Spells
{
    SPELL_ECK_BERSERK                             = 55816, //Eck goes berserk, increasing his attack speed by 150% and all damage he deals by 500%.
    SPELL_ECK_BITE                                = 55813, //Eck bites down hard, inflicting 150% of his normal damage to an enemy.
    SPELL_ECK_SPIT                                = 55814, //Eck spits toxic bile at enemies in a cone in front of him, inflicting 2970 Nature damage and draining 220 mana every 1 sec for 3 sec.
    SPELL_ECK_SPRING_1                            = 55815, //Eck leaps at a distant target.  --> Drops aggro and charges a random player. Tank can simply taunt him back.
    SPELL_ECK_SPRING_2                            = 55837  //Eck leaps at a distant target.
};

enum Events
{
    EVENT_BITE = 1,
    EVENT_SPIT,
    EVENT_SPRING,
    EVENT_BERSERK
};

class boss_eck : public CreatureScript
{
public:
    boss_eck() : CreatureScript("boss_eck") { }

    struct boss_eckAI : public BossAI
    {
        boss_eckAI(Creature* creature) : BossAI(creature, DATA_ECK_THE_FEROCIOUS_EVENT)
        {
            Berserk = false;
        }

        void Reset() override
        {
            _Reset();
            Berserk = false;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_BITE, 5 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_SPIT, 10 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_SPRING, 8 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_BERSERK, urand(60 * IN_MILLISECONDS, 90 * IN_MILLISECONDS)); //60-90 secs according to wowwiki
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (me->HealthBelowPctDamaged(20, damage) && !Berserk)
            {
                events.RescheduleEvent(EVENT_BERSERK, 1000);
                Berserk = true;
            }
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_BITE:
                    DoCastVictim(SPELL_ECK_BITE);
                    events.ScheduleEvent(EVENT_BITE, urand(8 * IN_MILLISECONDS, 12 * IN_MILLISECONDS));
                    break;
                case EVENT_SPIT:
                    DoCastVictim(SPELL_ECK_SPIT);
                    events.ScheduleEvent(EVENT_SPIT, urand(6 * IN_MILLISECONDS, 14 * IN_MILLISECONDS));
                    break;
                case EVENT_SPRING:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                        if (target->GetTypeId() == TYPEID_PLAYER)
                            DoCast(target, RAND(SPELL_ECK_SPRING_1, SPELL_ECK_SPRING_2));
                    events.ScheduleEvent(EVENT_SPRING, urand(5 * IN_MILLISECONDS, 10 * IN_MILLISECONDS));
                    break;
                case EVENT_BERSERK:
                    DoCast(me, SPELL_ECK_BERSERK);
                    Berserk = true;
                    break;
                default:
                    break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
        }

        private:
            bool Berserk;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_eckAI>(creature);
    }
};

void AddSC_boss_eck()
{
    new boss_eck();
}
