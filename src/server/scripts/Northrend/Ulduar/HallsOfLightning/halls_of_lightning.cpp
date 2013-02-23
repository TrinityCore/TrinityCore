/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "halls_of_lightning.h"

enum Spells
{
    //Titanium Thunderer
    SPELL_COUNTERATTACK        = 52883,
    SPELL_DEADLY_THROW         = 52885,
    SPELL_DEADLY_THROW_H       = 59180,
    SPELL_DEFLECTION           = 52879,
    SPELL_DEFLECTION_H         = 59181,
    SPELL_THROW                = 52904,
    SPELL_THROW_H              = 59179,

    //Titanium Siegebreaker
    SPELL_BLADE_TURNING        = 52891,
    SPELL_BLADE_TURNING_H      = 59173,
    SPELL_FRIGHTENING_SHOUT_10 = 19134, //10 yards range
    SPELL_FRIGHTENING_SHOUT_15 = 29544, //15 yards range
    SPELL_PENETRATING_STRIKE   = 52890,
    SPELL_PIERCING_HOWL        = 23600,
    SPELL_SPELL_DAMPING        = 52896,
    SPELL_SPELL_DAMPING_H      = 59177,

    SPELL_FREEZE               = 16245,
};

enum ThundererEvents
{
    EVENT_COUNTERATTACK = 1,
    EVENT_DEADLY_THROW,
    EVENT_DEFLECTION,
    EVENT_THROW,
};

class mob_titanium_thunderer : public CreatureScript
{
    public:
        mob_titanium_thunderer() : CreatureScript("mob_titanium_thunderer") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new mob_titanium_thundererAI(pCreature);
        }

        struct mob_titanium_thundererAI : public ScriptedAI
        {
            mob_titanium_thundererAI(Creature* creature) : ScriptedAI(creature)
            {
                me->AddAura(SPELL_FREEZE, me);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }

            EventMap events;

            void Reset()
            {
                //Falsche Timer habe keine Informationen ueber die richtigen gefunden
                events.Reset();
                events.ScheduleEvent(EVENT_COUNTERATTACK, urand(16000, 18000));
                events.ScheduleEvent(EVENT_DEADLY_THROW, urand(9000, 12000));
                events.ScheduleEvent(EVENT_DEFLECTION, 15000);
                events.ScheduleEvent(EVENT_THROW, urand(20000, 25000));

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                DoCast(me, SPELL_FREEZE);
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (!who)
                    return;

                if (who->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (me->IsWithinDistInMap(who, 25.0f))
                {
                    if (rand() % 100 < 35) //kA ob es wirklich so getriggert wird. Habe aber auch keinen Areatrigger fuer diese Zone gefunden
                    {
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                        me->RemoveAura(SPELL_FREEZE);
                        me->SetInCombatWith(who);
                    }
                }
            }

            void EnterCombat(Unit* victim)
            {
                if (me->IsInRange(victim, 8.0f, 30.0f))
                    DoCast(victim, DUNGEON_MODE(SPELL_THROW, SPELL_THROW_H));
            }

            void JustReachedHome()
            {
                //Wenn es hier getriggert wird kann es passieren, dass der NPC sofort bei Aktivierung wieder erstarrt

                /*me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                DoCast(me, SPELL_FREEZE);*/
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_COUNTERATTACK:
                            DoCast(me->getVictim(), SPELL_COUNTERATTACK);
                            events.ScheduleEvent(EVENT_COUNTERATTACK, urand(16000, 18000));
                            break;
                        case EVENT_DEADLY_THROW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            {
                                if (me->IsInRange(target, 8.0f, 30.0f))
                                    DoCast(target, DUNGEON_MODE(SPELL_DEADLY_THROW, SPELL_DEADLY_THROW_H));
                            }
                            events.ScheduleEvent(EVENT_DEADLY_THROW, urand(9000, 12000));
                            break;
                        case EVENT_DEFLECTION:
                            DoCast(me, DUNGEON_MODE(SPELL_DEFLECTION, SPELL_DEFLECTION_H));
                            events.ScheduleEvent(EVENT_DEFLECTION, 15000);
                            break;
                        case EVENT_THROW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            {
                                if (me->IsInRange(target, 8.0f, 30.0f))
                                    DoCast(target, DUNGEON_MODE(SPELL_THROW, SPELL_THROW_H));
                            }
                            events.ScheduleEvent(EVENT_THROW, urand(20000, 25000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        };
};

enum SiegebreakerEvents
{
    EVENT_BLADE_TURNING = 1,
    EVENT_PENETRATING_STRIKE,
    EVENT_PIERCING_HOWL,
    EVENT_SPELL_DAMPING,
};

class mob_titanium_siegebreaker : public CreatureScript
{
    public:
        mob_titanium_siegebreaker() : CreatureScript("mob_titanium_siegebreaker") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new mob_titanium_siegebreakerAI(pCreature);
        }

        struct mob_titanium_siegebreakerAI : public ScriptedAI
        {
            mob_titanium_siegebreakerAI(Creature* creature) : ScriptedAI(creature)
            {
                me->AddAura(SPELL_FREEZE, me);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }

            //Info: Siehe mob_titanium_thunderer

            EventMap events;

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_BLADE_TURNING, 12000);
                events.ScheduleEvent(EVENT_PENETRATING_STRIKE, urand(8000, 10000));
                events.ScheduleEvent(EVENT_PIERCING_HOWL, urand(20000, 25000));
                events.ScheduleEvent(EVENT_SPELL_DAMPING, urand(14000, 18000));

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                DoCast(me, SPELL_FREEZE);
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (!who)
                    return;

                if (who->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (me->IsWithinDistInMap(who, 35.0f))
                {
                    if (rand() % 100 < 25)
                    {
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                        me->RemoveAura(SPELL_FREEZE);
                        me->SetInCombatWith(who);
                    }
                }
            }

            void JustDied(Unit* killer)
            {
                DoCast(killer, DUNGEON_MODE(SPELL_FRIGHTENING_SHOUT_10, SPELL_FRIGHTENING_SHOUT_15));
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BLADE_TURNING:
                            DoCast(DUNGEON_MODE(SPELL_BLADE_TURNING, SPELL_BLADE_TURNING_H));
                            events.ScheduleEvent(EVENT_BLADE_TURNING, 15000);
                            break;
                        case EVENT_PENETRATING_STRIKE:
                            DoCast(me->getVictim(), SPELL_PENETRATING_STRIKE);
                            events.ScheduleEvent(EVENT_PENETRATING_STRIKE, urand(10000, 12000));
                            break;
                        case EVENT_PIERCING_HOWL:
                            DoCast(SPELL_PIERCING_HOWL);
                            events.ScheduleEvent(EVENT_PIERCING_HOWL, urand(23000, 27000));
                            break;
                        case EVENT_SPELL_DAMPING:
                            DoCast(DUNGEON_MODE(SPELL_SPELL_DAMPING, SPELL_SPELL_DAMPING_H));
                            events.ScheduleEvent(EVENT_SPELL_DAMPING, urand(17000, 20000));
                            break;
                    }
                }
                DoMeleeAttackIfReady();

            }

        };
};

void AddSC_halls_of_lightning()
{
    new mob_titanium_thunderer();
    new mob_titanium_siegebreaker();
}
