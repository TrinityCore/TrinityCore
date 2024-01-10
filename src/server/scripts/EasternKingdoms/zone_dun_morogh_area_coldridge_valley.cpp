/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "Containers.h"
#include "ScriptMgr.h"
#include "CombatAI.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum WoundedColdridgeMountaineer
{
    NPC_JOREN_IRONSTOCK            = 37081,
    SAY_THANK_PLAYER               = 0,
    SPELL_HEAL_WOUNDED_MOUNTAINEER = 69855,
    SPELL_LOW_HEALTH               = 76143,
    EVENT_TURN_TO_PLAYER           = 1,
    EVENT_THANK_PLAYER             = 2,
    EVENT_MOVE_TO_SAFETY           = 3
};

/*######
# wounded_coldridge_mountaineer
######*/

class npc_wounded_coldridge_mountaineer : public CreatureScript
{
public:
    npc_wounded_coldridge_mountaineer() : CreatureScript("npc_wounded_coldridge_mountaineer") { }

    struct npc_wounded_coldridge_mountaineerAI : public ScriptedAI
    {
        npc_wounded_coldridge_mountaineerAI(Creature* creature) : ScriptedAI(creature), _tapped(false) { }

        void Reset() override
        {
            _events.Reset();
            DoCastSelf(SPELL_LOW_HEALTH);
            _tapped = false;
        }

        void SpellHit(WorldObject* caster, SpellInfo const* spell) override
        {
            if (_tapped)
                return;

            if (spell->Id == SPELL_HEAL_WOUNDED_MOUNTAINEER)
            {
                if (caster->GetTypeId() == TYPEID_PLAYER)
                {
                    _tapped = true;
                    _playerGUID = caster->GetGUID();
                    me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    _events.ScheduleEvent(EVENT_TURN_TO_PLAYER, Seconds(2));
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!_tapped)
                return;

            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_TURN_TO_PLAYER:
                    me->SetFacingToObject(ObjectAccessor::GetUnit(*me, _playerGUID));
                    _events.ScheduleEvent(EVENT_THANK_PLAYER, Seconds(1));
                    break;
                case EVENT_THANK_PLAYER:
                    Talk(SAY_THANK_PLAYER, ObjectAccessor::GetUnit(*me, _playerGUID));
                    _events.ScheduleEvent(EVENT_MOVE_TO_SAFETY, Seconds(5));
                    break;
                case EVENT_MOVE_TO_SAFETY:
                    if (Creature* joren = me->FindNearestCreature(NPC_JOREN_IRONSTOCK, 75.0f, true))
                         me->GetMotionMaster()->MovePoint(0, joren->GetPosition(), true);
                    me->DespawnOrUnsummon(Seconds(5));
                    break;
                default:
                    break;
                }
            }
        }
    private:
        EventMap _events;
        ObjectGuid _playerGUID;
        bool _tapped;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_wounded_coldridge_mountaineerAI(creature);
    }
};

/*####
## npc_wounded_milita
####*/

enum WoundedMilita
{
    QUEST_KILL_CREDIT  = 44175,
    SPELL_FLASH_HEAL   = 2061,
    EVENT_RESET_HEALTH = 4
};

class npc_wounded_milita : public CreatureScript
{
public:
    npc_wounded_milita() : CreatureScript("npc_wounded_milita") { }

    struct npc_wounded_militaAI : public ScriptedAI
    {
        npc_wounded_militaAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            _hitBySpell = false;
            _percentHP = urand(15, 55);
        }

        void Reset() override
        {
            Initialize();
            me->SetHealth(me->CountPctFromMaxHealth(_percentHP));
        }

        void SpellHit(WorldObject* caster, SpellInfo const* spell) override
        {
            if (!_hitBySpell)
            {
                _hitBySpell = true;
                _events.ScheduleEvent(EVENT_RESET_HEALTH, Seconds(30));
            }

            if (spell->Id == SPELL_FLASH_HEAL)
                if (Player* player = caster->ToPlayer())
                    player->KilledMonsterCredit(QUEST_KILL_CREDIT);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!_hitBySpell)
                return;

            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_RESET_HEALTH:
                        me->SetHealth(me->CountPctFromMaxHealth(_percentHP));
                        _hitBySpell = false;
                        break;
                    default:
                        break;
                }
            }
        }
    private:
        EventMap _events;
        uint8 _percentHP;
        bool _hitBySpell;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_wounded_militaAI(creature);
    }
};

/*######
## npc_milos_gyro
######*/

enum MilosGyro
{
    NPC_MILO                      = 37518,
    SPELL_RIDE_VEHICLE_HARD_CODED = 46598,
    SPELL_EJECT_ALL_PASSENGERS    = 50630,
    SAY_MILO_FLIGHT_1             = 0,
    SAY_MILO_FLIGHT_2             = 1,
    SAY_MILO_FLIGHT_3             = 2,
    SAY_MILO_FLIGHT_4             = 3,
    SAY_MILO_FLIGHT_5             = 4,
    SAY_MILO_FLIGHT_6             = 5,
    SAY_MILO_FLIGHT_7             = 6,
    EVENT_START_PATH              = 5,
    EVENT_MILO_SAY_0              = 6,
    EVENT_MILO_SAY_1              = 7,
    EVENT_MILO_SAY_2              = 8,
    EVENT_MILO_SAY_3              = 9,
    EVENT_MILO_SAY_4              = 10,
    EVENT_MILO_SAY_5              = 11,
    EVENT_MILO_SAY_6              = 12,
    EVENT_MILO_DESPAWN            = 13
};

Position const kharanosPath[] =
{
    { -6247.328f, 299.5365f, 390.266f   },
    { -6247.328f, 299.5365f, 390.266f   },
    { -6250.934f, 283.5417f, 393.46f    },
    { -6253.335f, 252.7066f, 403.0702f  },
    { -6257.292f, 217.4167f, 424.3807f  },
    { -6224.2f,   159.9861f, 447.0882f  },
    { -6133.597f, 164.3177f, 491.0316f  },
    { -6084.236f, 183.375f, 508.5401f   },
    { -6020.382f, 179.5052f, 521.5396f  },
    { -5973.592f, 161.7396f, 521.5396f  },
    { -5953.665f, 151.6111f, 514.5687f  },
    { -5911.031f, 146.4462f, 482.1806f  },
    { -5886.389f, 124.125f, 445.6252f   },
    { -5852.08f,  55.80903f, 406.7922f  },
    { -5880.707f, 12.59028f, 406.7922f  },
    { -5927.887f, -74.02257f, 406.7922f },
    { -5988.436f, -152.0174f, 425.6251f },
    { -6015.274f, -279.467f, 449.528f   },
    { -5936.465f, -454.1875f, 449.528f  },
    { -5862.575f, -468.0504f, 444.3899f },
    { -5783.58f,  -458.6042f, 432.5026f },
    { -5652.707f, -463.4427f, 415.0308f },
    { -5603.897f, -466.3438f, 409.8931f },
    { -5566.957f, -472.5642f, 399.0056f }
};
size_t const pathSize = std::extent<decltype(kharanosPath)>::value;

class npc_milos_gyro : public CreatureScript
{
public:
    npc_milos_gyro() : CreatureScript("npc_milos_gyro") { }

    struct npc_milos_gyro_AI : public VehicleAI
    {
        npc_milos_gyro_AI(Creature* creature) : VehicleAI(creature), _waitBeforePath(true) { }

        void Reset() override
        {
            _events.Reset();
            _miloGUID.Clear();
            _waitBeforePath = true;
        }

        void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
        {
            if (apply && passenger->GetTypeId() == TYPEID_PLAYER)
            {
                if (Creature* milo = passenger->SummonCreature(NPC_MILO, me->GetPosition(), TEMPSUMMON_CORPSE_DESPAWN, 0s))
                {
                    _waitBeforePath = false;
                    _miloGUID = milo->GetGUID();
                    milo->CastSpell(me, SPELL_RIDE_VEHICLE_HARD_CODED);
                    _events.ScheduleEvent(EVENT_START_PATH, Seconds(1));
                }
            }
        }

        void MovementInform(uint32 type, uint32 pointId) override
        {
            if (type == EFFECT_MOTION_TYPE && pointId == pathSize)
                _events.ScheduleEvent(EVENT_MILO_DESPAWN, Seconds(1));
        }

        void UpdateAI(uint32 diff) override
        {
            if (_waitBeforePath)
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_START_PATH:
                        me->GetMotionMaster()->MoveSmoothPath(uint32(pathSize), kharanosPath, pathSize, false, true);
                        _events.ScheduleEvent(EVENT_MILO_SAY_0, Seconds(5));
                        break;
                    case EVENT_MILO_SAY_0:
                        if (Creature* milo = ObjectAccessor::GetCreature(*me, _miloGUID))
                            milo->AI()->Talk(SAY_MILO_FLIGHT_1, me);
                        _events.ScheduleEvent(EVENT_MILO_SAY_1, Seconds(6));
                        break;
                    case EVENT_MILO_SAY_1:
                        if (Creature* milo = ObjectAccessor::GetCreature(*me, _miloGUID))
                            milo->AI()->Talk(SAY_MILO_FLIGHT_2, me);
                        _events.ScheduleEvent(EVENT_MILO_SAY_2, Seconds(11));
                        break;
                    case EVENT_MILO_SAY_2:
                        if (Creature* milo = ObjectAccessor::GetCreature(*me, _miloGUID))
                            milo->AI()->Talk(SAY_MILO_FLIGHT_3, me);
                        _events.ScheduleEvent(EVENT_MILO_SAY_3, Seconds(11));
                        break;
                    case EVENT_MILO_SAY_3:
                        if (Creature* milo = ObjectAccessor::GetCreature(*me, _miloGUID))
                            milo->AI()->Talk(SAY_MILO_FLIGHT_4, me);
                        _events.ScheduleEvent(EVENT_MILO_SAY_4, Seconds(18));
                        break;
                    case EVENT_MILO_SAY_4:
                        if (Creature* milo = ObjectAccessor::GetCreature(*me, _miloGUID))
                            milo->AI()->Talk(SAY_MILO_FLIGHT_5, me);
                        _events.ScheduleEvent(EVENT_MILO_SAY_5, Seconds(11));
                        break;
                    case EVENT_MILO_SAY_5:
                        if (Creature* milo = ObjectAccessor::GetCreature(*me, _miloGUID))
                            milo->AI()->Talk(SAY_MILO_FLIGHT_6, me);
                        _events.ScheduleEvent(EVENT_MILO_SAY_6, Seconds(14));
                        break;
                    case EVENT_MILO_SAY_6:
                        if (Creature* milo = ObjectAccessor::GetCreature(*me, _miloGUID))
                            milo->AI()->Talk(SAY_MILO_FLIGHT_7, me);
                        break;
                    case EVENT_MILO_DESPAWN:
                        me->RemoveAllAuras();
                        if (Creature* milo = ObjectAccessor::GetCreature(*me, _miloGUID))
                            milo->DespawnOrUnsummon();
                        _waitBeforePath = true;
                        break;
                    default:
                        break;
                }
            }
        }
    private:
        EventMap _events;
        ObjectGuid _miloGUID;
        bool _waitBeforePath;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_milos_gyro_AI(creature);
    }
};

/*######
# spell_a_trip_to_ironforge_quest_complete
# 70046 - A Trip to Ironforge - Quest Complete
######*/

class spell_a_trip_to_ironforge_quest_complete : public SpellScriptLoader
{
public:
    spell_a_trip_to_ironforge_quest_complete() : SpellScriptLoader("spell_a_trip_to_ironforge_quest_complete") { }

    class spell_a_trip_to_ironforge_quest_complete_SpellScript : public SpellScript
    {
        void HandleForceCast(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            GetHitUnit()->CastSpell(GetHitUnit(), GetEffectInfo().TriggerSpell, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_a_trip_to_ironforge_quest_complete_SpellScript::HandleForceCast, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_a_trip_to_ironforge_quest_complete_SpellScript();
    }
};

/*######
# spell_follow_that_gyrocopter_quest_start
# 70047 - Follow That Gyro-Copter - Quest Start
######*/

class spell_follow_that_gyrocopter_quest_start : public SpellScriptLoader
{
public:
    spell_follow_that_gyrocopter_quest_start() : SpellScriptLoader("spell_follow_that_gyrocopter_quest_start") { }

    class spell_follow_that_gyrocopter_quest_start_SpellScript : public SpellScript
    {
        void HandleForceCast(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            GetHitUnit()->CastSpell(GetHitUnit(), GetEffectInfo().TriggerSpell, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_follow_that_gyrocopter_quest_start_SpellScript::HandleForceCast, EFFECT_1, SPELL_EFFECT_FORCE_CAST);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_follow_that_gyrocopter_quest_start_SpellScript();
    }
};

/*######
# spell_low_health
# 76143 - Low Health
######*/

class spell_low_health: public SpellScriptLoader
{
public:
    spell_low_health() : SpellScriptLoader("spell_low_health") { }

    class spell_low_health_SpellScript : public SpellScript
    {
        void HandleDummyEffect(SpellEffIndex /*eff*/)
        {
            if (Creature* target = GetHitCreature())
            {
                target->SetRegenerateHealth(false);
                target->SetHealth(target->CountPctFromMaxHealth(10));
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_low_health_SpellScript::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_low_health_SpellScript();
    }
};

Position const RockjawInvaderSpawnPoints[7] =
{
    { -6237.6807f, 375.5191f, 385.44696f, 5.168368339538574218f },
    { -6299.6113f, 347.11978f, 377.25546f, 6.068230628967285156f },
    { -6208.724f, 354.3229f, 387.3534f, 4.338659286499023437f },
    { -6261.8228f, 371.06598f, 383.35944f, 5.383506298065185546f },
    { -6253.722f, 340.1389f, 382.50888f, 5.957066535949707031f },
    { -6286.6113f, 316.9566f, 376.9441f, 6.195390701293945312f },
    { -6204.599f, 304.64932f, 388.9596f, 2.362043619155883789f }
};

enum JorenIronstockData
{
    NPC_ROCKJAW_INVADER                 = 37070,

    SAY_SHOOT_ROCKJAW                   = 0,

    SPELL_SHOOT                         = 70014
};

// 37081 - Joren Ironstock
struct npc_joren_ironstock : public ScriptedAI
{
    npc_joren_ironstock(Creature* creature) : ScriptedAI(creature) { }

    void EnqueueInvader(Unit* invader, Seconds minTime = 1s, Seconds maxTime = 9s)
    {
        _scheduler.Schedule(minTime, maxTime, [this, guid = invader->GetGUID()](TaskContext /*task*/)
        {
            _invadersToShoot.push(guid);
        });
    }

    void JustAppeared() override
    {
        me->SetTemplateRooted(true);

        _scheduler.Schedule(1s, [this](TaskContext task)
        {
            if (Creature* invader = me->SummonCreature(NPC_ROCKJAW_INVADER, Trinity::Containers::SelectRandomContainerElement(RockjawInvaderSpawnPoints), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 18s))
            {
                if (me->HasInArc(float(M_PI), invader) && !me->IsInCombat())
                    EnqueueInvader(invader, 1s, 3s);
                else
                    EnqueueInvader(invader, 5s, 8s);
                invader->AI()->AttackStart(me);
            }
            task.Repeat(3s, 20s);
        });

        _scheduler.Schedule(1s, [this](TaskContext task)
        {
            if (!_invadersToShoot.empty())
            {
                ObjectGuid guid = _invadersToShoot.front();
                _invadersToShoot.pop();

                Creature* invader = ObjectAccessor::GetCreature(*me, guid);
                if (invader && invader->IsAlive())
                {
                    SpellCastResult result = DoCast(invader, SPELL_SHOOT);
                    if (result == SpellCastResult::SPELL_CAST_OK)
                    {
                        if (roll_chance_i(50))
                            Talk(SAY_SHOOT_ROCKJAW, invader);
                    }
                    else
                        _invadersToShoot.push(guid);
                }
            }
            task.Repeat(1s);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;
    }

private:
    TaskScheduler _scheduler;
    std::queue<ObjectGuid> _invadersToShoot;
};

void AddSC_dun_morogh_area_coldridge_valley()
{
    new npc_wounded_coldridge_mountaineer();
    new npc_wounded_milita();
    new npc_milos_gyro();
    new spell_a_trip_to_ironforge_quest_complete();
    new spell_follow_that_gyrocopter_quest_start();
    new spell_low_health();
    RegisterCreatureAI(npc_joren_ironstock);
}
