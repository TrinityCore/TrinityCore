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

enum ScriptTexts
{
    SAY_INTRO                  = 0,
    SAY_AGGRO                  = 1,
    SAY_KILL_1                 = 2,
    SAY_KILL_2                 = 3,
    SAY_OMEGA                  = 4,
    SAY_DEATH                  = 5,
    SAY_PROTOCOL               = 6
};

enum Spells
{
    //Anraphet
    SPELL_ALPHA_BEAMS          = 76184,
    SPELL_CRUMBLING_RUIN       = 75609,
    SPELL_DESTRUCTION_PROTOCOL = 77437,
    SPELL_NEMESIS_STRIKE       = 75604,
    SPELL_OMEGA_STANCE         = 75622,

    //Flame Warden
    SPELL_LAVA_ERUPTION        = 77273,
    SPELL_RAGING_INFERNO       = 77241,
    //Air Warden
    SPELL_WIND_SHEAR           = 77334,
    //Earth Warden
    SPELL_IMPALE               = 77235,
    SPELL_ROCKWAVE             = 77234,
    //Water Warden
    SPELL_BUBBLE_BOUND         = 77336
};

enum Cords
{
    //Cords for Anraphet intro
    X = 0,
    Y = 0,
    Z = 0
};

enum Events
{
    EVENT_ALPHA_BEAMS          = 1,
    EVENT_CRUMBLING_RUIN       = 2,
    EVENT_DESTRUCTION_PROTOCOL = 3,
    EVENT_NEMESIS_STRIKE       = 4,
    EVENT_OMEGA_STANCE         = 5
};

/*enum Timers
{
    TIMER_ALPHA_BEAMS      = 15000,
    TIMER_NEMESIS_STRIKE   = 10000,
    TIMER_OMEGA_STANCE     = 20000
    //TIMER_RUIN,
};*/

class boss_anraphet : public CreatureScript
{
    public:
        boss_anraphet() : CreatureScript("boss_anraphet") { }

        struct boss_anraphetAI : public BossAI
        {
            boss_anraphetAI(Creature* creature) : BossAI(creature, DATA_ANRAPHET_EVENT)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;
            uint8 wardenKilled;

            void Reset()
            {
                events.Reset();

                if (instance)
                    instance->SetData(DATA_ANRAPHET_EVENT, NOT_STARTED);

                wardenKilled = 0;
            }

            void EnterCombat(Unit* /*who*/)
            {
                //DoScriptText(SAY_AGGRO, me);

                if (instance)
                    instance->SetData(DATA_ANRAPHET_EVENT, IN_PROGRESS);

                events.ScheduleEvent(EVENT_ALPHA_BEAMS, 8000+rand()%2000);
                events.ScheduleEvent(EVENT_CRUMBLING_RUIN, urand(10000, 16000));
                events.ScheduleEvent(EVENT_NEMESIS_STRIKE, 12000);
                events.ScheduleEvent(EVENT_OMEGA_STANCE, 10000);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CRUMBLING_RUIN);

                DoZoneInCombat();
            }

            void KilledUnit(Unit* /*Killed*/)
            {
                //DoScriptText(RAND(SAY_KILL_1, SAY_KILL_2), me);
            }

            void WardenKilled()
            {
                wardenKilled++;

                if (wardenKilled == 4)
                    preBattlePhase();
            }

            void preBattlePhase()
            {
                //Enter the room and kill all troggs

                //DoScriptText(SAY_INTRO, me);
                //DoScriptText(SAY_PROTOCOL me);
                me->GetMotionMaster()->MovePoint(0, X, Y, Z);
                DoCast(SPELL_DESTRUCTION_PROTOCOL);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                   return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while(uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ALPHA_BEAMS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, true))
                                DoCast(target, SPELL_ALPHA_BEAMS);
                                events.ScheduleEvent(EVENT_ALPHA_BEAMS, urand(8000, 12000));
                            break;
                        case EVENT_CRUMBLING_RUIN:
                            DoCast(me->getVictim(), SPELL_CRUMBLING_RUIN);
                            events.ScheduleEvent(EVENT_CRUMBLING_RUIN, urand(10000, 16000));
                            break;
                        case EVENT_NEMESIS_STRIKE:
                            DoCast(me->getVictim(), SPELL_NEMESIS_STRIKE);
                            events.ScheduleEvent(EVENT_NEMESIS_STRIKE, 2000);
                            break;
                        case EVENT_OMEGA_STANCE:
                            //DoScriptText(SAY_OMEGA, me);
                            DoCast(me, SPELL_OMEGA_STANCE);
                            events.ScheduleEvent(EVENT_OMEGA_STANCE, 14000);
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
                    instance->SetData(DATA_ANRAPHET_EVENT, DONE);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_anraphetAI(creature);
        }
};

class boss_flame_warden : public CreatureScript
{
    public:
        boss_flame_warden() : CreatureScript("boss_flame_warden") { }

        struct boss_flame_wardenAI : public BossAI
        {
            boss_flame_wardenAI(Creature* creature) : BossAI(creature, DATA_FLAME_WARDEN)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;

            uint32 LavaTimer;
            uint32 InfernoTimer;

            void Reset()
            {
                if (instance)
                    instance->SetData(DATA_FLAME_WARDEN, NOT_STARTED);

                LavaTimer = 5000;
                InfernoTimer = 20000;
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (instance)
                    instance->SetData(DATA_FLAME_WARDEN, IN_PROGRESS);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (LavaTimer <= diff)
                {
                    if (Unit *target = (SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true)))
                        DoCast(target, SPELL_LAVA_ERUPTION);
                    LavaTimer = 5000+rand()%5000;
                }
                else LavaTimer -= diff;

                if (InfernoTimer <= diff)
                {
                    DoCast(SPELL_RAGING_INFERNO);
                    InfernoTimer = 20000+rand()%7500;
                }
                else InfernoTimer -= diff;

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*who*/)
            {
                if (Creature *anraphet = me->FindNearestCreature(BOSS_ANRAPHET, 1000, true))
                      if (boss_anraphet::boss_anraphetAI* pAI = CAST_AI(boss_anraphet::boss_anraphetAI, anraphet->AI()))
                                pAI->WardenKilled();

                if (instance)
                    instance->SetData(DATA_FLAME_WARDEN, DONE);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_flame_wardenAI(creature);
        }
};

class boss_air_warden : public CreatureScript
{
    public:
        boss_air_warden() : CreatureScript("boss_air_warden") { }

        struct boss_air_wardenAI : public BossAI
        {
            boss_air_wardenAI(Creature* creature) : BossAI(creature, DATA_AIR_WARDEN)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;

            uint32 WindTimer;

            void Reset()
            {
                if (instance)
                    instance->SetData(DATA_AIR_WARDEN, NOT_STARTED);

                WindTimer = 7500;
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (instance)
                    instance->SetData(DATA_AIR_WARDEN, IN_PROGRESS);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (WindTimer <= diff)
                {
                    if (Unit *target = (SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true)))
                        DoCast(target, SPELL_WIND_SHEAR);
                    WindTimer = 7500+rand()%7500;
                } else WindTimer -= diff;

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*who*/)
            {
                if (Creature *anraphet = me->FindNearestCreature(BOSS_ANRAPHET, 1000, true))
                      if (boss_anraphet::boss_anraphetAI* pAI = CAST_AI(boss_anraphet::boss_anraphetAI, anraphet->AI()))
                                pAI->WardenKilled();
                if (instance)
                    instance->SetData(DATA_AIR_WARDEN, DONE);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_air_wardenAI(creature);
        }
};

class boss_earth_warden : public CreatureScript
{
    public:
        boss_earth_warden() : CreatureScript("boss_earth_warden") { }

        struct boss_earth_wardenAI : public BossAI
        {
            boss_earth_wardenAI(Creature* creature) : BossAI(creature, DATA_EARTH_WARDEN)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;

            uint32 RockTimer;
            uint32 ImpaleTimer;

            void Reset()
            {
                if (instance)
                    instance->SetData(DATA_EARTH_WARDEN, NOT_STARTED);

                RockTimer = 10000;
                ImpaleTimer = 5000;
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (instance)
                    instance->SetData(DATA_EARTH_WARDEN, IN_PROGRESS);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (RockTimer <= diff)
                {
                    if (Unit* target = (SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true)))
                        DoCast(target, SPELL_WIND_SHEAR);
                    RockTimer = 20000+rand()%7500;
                }
                else RockTimer -= diff;

                if (ImpaleTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_WIND_SHEAR);
                    ImpaleTimer = 7500+rand()%7500;
                }
                else ImpaleTimer -= diff;

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*who*/)
            {
                if (Creature* anraphet = me->FindNearestCreature(BOSS_ANRAPHET, 1000, true))
                      if (boss_anraphet::boss_anraphetAI* pAI = CAST_AI(boss_anraphet::boss_anraphetAI, anraphet->AI()))
                                pAI->WardenKilled();

                if (instance)
                    instance->SetData(DATA_EARTH_WARDEN, DONE);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_earth_wardenAI(creature);
        }
};

class boss_water_warden : public CreatureScript
{
    public:
        boss_water_warden() : CreatureScript("boss_water_warden") { }

        struct boss_water_wardenAI : public BossAI
        {
            boss_water_wardenAI(Creature* creature) : BossAI(creature, DATA_WATER_WARDEN)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;

            uint32 BubbleTimer;

            void Reset()
            {
                if (instance)
                    instance->SetData(DATA_WATER_WARDEN, NOT_STARTED);

                BubbleTimer = 5000;
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (instance)
                    instance->SetData(DATA_WATER_WARDEN, IN_PROGRESS);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (BubbleTimer <= diff)
                {
                    if (Unit *target = (SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true)))
                        DoCast(target, SPELL_BUBBLE_BOUND);
                    BubbleTimer = 15000+rand()%7500;
                }
                else BubbleTimer -= diff;

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*who*/)
            {
                if (Creature *anraphet = me->FindNearestCreature(BOSS_ANRAPHET, 1000, true))
                      if (boss_anraphet::boss_anraphetAI* pAI = CAST_AI(boss_anraphet::boss_anraphetAI, anraphet->AI()))
                                pAI->WardenKilled();

                if (instance)
                    instance->SetData(DATA_WATER_WARDEN, DONE);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_water_wardenAI(creature);
        }
};

void AddSC_boss_anraphet()
{
    new boss_anraphet;
    new boss_flame_warden;
    new boss_air_warden;
    new boss_earth_warden;
    new boss_water_warden;
}