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
#include "ScriptPCH.h"
#include "halls_of_origination.h"

enum Spells
{
    //Rajh
    SPELL_SUN_STRIKE           = 73872,
    SPELL_INFERNO_LEAP         = 87647, //Value: 32375 to 37625
    SPELL_INFERNO_LEAP_2       = 89876, //Value: 120250 to 139750
    SPELL_SUMMON_SUN_ORB       = 80352,
    SPELL_BLESSING_OF_THE_SUN  = 76352,
    SPELL_SUMMON_SOLAR_WIND    = 74104,

    //Solar Wind
    SPELL_SOLAR_WIND           = 89130,
    SPELL_SOLAR_FIRE           = 89131
};

enum Texts
{
    SAY_AGGRO    = 0,
    SAY_KILL     = 1,
    SAY_DEATH    = 2,
    SAY_ENERGIZE = 3
};

enum EnergizeCords
{
    //Find cords for the center of room
    X = 0,
    Y = 0,
    Z = 0
};

enum Events
{
    EVENT_SUN_STRIKE           = 1,
    EVENT_INFERNO_LEAP         = 2,
    EVENT_BLESSING_OF_THE_SUN  = 3,
    EVENT_SUMMON_SUN_ORB       = 4,
    EVENT_SUMMON_SOLAR_WIND    = 5
};

class boss_rajh : public CreatureScript
{
    public:
        boss_rajh() : CreatureScript("boss_rajh") { }

        struct boss_rajhAI : public BossAI
        {
            boss_rajhAI(Creature* creature) : BossAI(creature, DATA_RAJH_EVENT)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;

            void Reset()
            {
                if (instance)
                    instance->SetData(DATA_RAJH_EVENT, NOT_STARTED);

                me->SetPower(POWER_ENERGY, me->GetMaxPower(POWER_ENERGY));
            }

            void EnterCombat(Unit* /*who*/)
            {
                //DoScriptText(SAY_AGGRO, me);

                if (instance)
                    instance->SetData(DATA_RAJH_EVENT, IN_PROGRESS);

                me->SetPower(POWER_ENERGY, me->GetMaxPower(POWER_ENERGY));

                events.ScheduleEvent(EVENT_SUN_STRIKE, 10000);
                events.ScheduleEvent(EVENT_INFERNO_LEAP, 15000);
                events.ScheduleEvent(EVENT_BLESSING_OF_THE_SUN, 12000);
                events.ScheduleEvent(EVENT_SUMMON_SUN_ORB, 25000);
                events.ScheduleEvent(EVENT_SUMMON_SOLAR_WIND, 20000);

                DoZoneInCombat();
            }

            void EnergizeSun()
            {
                //DoScriptText(SAY_ENERGIZE, me);
                me->GetMotionMaster()->MovePoint(0, X, Y, Z);
                DoCastAOE(SPELL_BLESSING_OF_THE_SUN);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while(uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUN_STRIKE:
                            DoCast(me->getVictim(), SPELL_SUN_STRIKE);
                            events.ScheduleEvent(EVENT_SUN_STRIKE, 10000);
                            break;
                        case EVENT_INFERNO_LEAP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, true))
                                DoCast(target, SPELL_INFERNO_LEAP);
                            events.ScheduleEvent(EVENT_INFERNO_LEAP, urand(15000, 22000));
                            break;
                        case EVENT_BLESSING_OF_THE_SUN:
                            if (me->GetPower(POWER_ENERGY) == 0)
                                EnergizeSun();
                            events.ScheduleEvent(EVENT_BLESSING_OF_THE_SUN, 15000);
                            break;
                        case EVENT_SUMMON_SUN_ORB:
                            DoCast(SPELL_SUMMON_SUN_ORB);
                            events.ScheduleEvent(EVENT_SUMMON_SUN_ORB, 25000);
                            break;
                        case EVENT_SUMMON_SOLAR_WIND:
                            DoCast(SPELL_SUMMON_SOLAR_WIND);
                            events.ScheduleEvent(EVENT_SUMMON_SOLAR_WIND, 30000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*who*/)
            {
                //DoScriptText(SAY_DEATH, me);

                if (instance)
                    instance->SetData(DATA_RAJH_EVENT, DONE);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_rajhAI(creature);
        }
};

class mob_solar_wind : public CreatureScript
{
public:
    mob_solar_wind() : CreatureScript("mob_solar_wind") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_solar_windAI(creature);
    }

    struct mob_solar_windAI : public ScriptedAI
    {
        mob_solar_windAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = (InstanceScript*)creature->GetInstanceScript();
            Reset();
        }

        InstanceScript* instance;

        void EnterCombat(Unit* /*who*/)
        {
            DoCast(me, SPELL_SOLAR_FIRE);
        }

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);
        }

        void JustDied(Unit* /*killer*/)
        {
            // used to despawn corpse immediately
            me->DespawnOrUnsummon();
        }
    };
};

void AddSC_boss_rajh()
{
    new boss_rajh;
    new mob_solar_wind;
}