/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "heart_of_fear.h"
#include "Vehicle.h"

// TODO Important : SPELL_INVISIBLE_STRIKE Ajouter le flag SPELL_ATTR5_START_PERIODIC_AT_APPLY
//                  123470 ajouter le flag SPELL_ATTR5_START_PERIODIC_AT_APPLY
//                  122994 : Changer les targets
//                  Ajouter des dégats aux 2 areatrigger
//                  Trouver le visuel du vent sur les cotés

enum eSpells
{
    SPELL_TEMPEST_SLASH_SUMMON          = 122842,
    SPELL_TEMPEST_SLASH_AURA            = 122854,

    SPELL_INVISIBLE_STRIKE              = 122949,
    SPELL_INVISIBLE_STRIKE_VISUAL       = 123017,

    SPELL_WIND_STEP                     = 123175,
    SPELL_WIND_STEP_DAMAGE              = 123180,

    SPELL_INTENSIFY                     = 123470,

    SPELL_OVERWHELMING_ASSAULT          = 123474,

    // Storm Unleashed
    SPELL_S_U_VISUAL                    = 123814,
    SPELL_S_U_TORNADO_VISUAL            = 124024,

    SPELL_S_U_SPAWN_TORNADO             = 123639,
    SPELL_S_U_SPAWN_ALL_TORNADOS        = 124023, // Spawn a tornado under each player

    SPELL_S_U_RIDE_VEHICLE              = 124026,
};

enum eAreaTriggers
{
    ROOM_NORTH                  = 8196,
    ROOM_SOUTH                  = 8197
};

enum eEvents
{
    EVENT_TEMPEST_SLASH         = 1,
    EVENT_INVISIBLE_STRIKE      = 2,
    EVENT_INVISIBLE_STRIKE_END  = 3,
    EVENT_OVERWHELMING_ASSAULT  = 4,

    EVENT_S_U_SPAWN_TORNADO     = 5,
    EVENT_S_U_JUMP_TO_SIDE      = 6,
    EVENT_S_U_SWITCH            = 7
};

enum ePos
{
    MIDDLE = 0,
    EAST   = 1,
    WEST   = 2
};

#define POSITION_Y_MIDDLE 280.0f

Position tayakPos[3] =
{
    { -2119.18f, 281.18f, 420.90f, 1.57f }, // Middle
    { -2119.18f, 377.58f, 422.16f, 4.71f }, // East
    { -2119.18f, 185.16f, 422.16f, 1.57f }, // West
};

#define TIMER_TO_SET urand(0, 60000)

class boss_blade_lord_tayak : public CreatureScript
{
    public:
        boss_blade_lord_tayak() : CreatureScript("boss_blade_lord_tayak") {}

        struct boss_blade_lord_tayakAI : public BossAI
        {
            boss_blade_lord_tayakAI(Creature* creature) : BossAI(creature, DATA_TAYAK) {}

            uint64 previousTargetGUID;
            uint64 tempestSlashTargetGUID;
            uint8  tornadoCount;
            uint8  prevSide;

            bool unleashedStormEventStarted;

            void Reset()
            {
                _Reset();

                tempestSlashTargetGUID      = 0;
                previousTargetGUID          = 0;
                unleashedStormEventStarted  = false;
                tornadoCount                = 0;
                prevSide                    = 0;

                me->RemoveAurasDueToSpell(SPELL_INTENSIFY);

                events.ScheduleEvent(EVENT_TEMPEST_SLASH,        TIMER_TO_SET);
                events.ScheduleEvent(EVENT_INVISIBLE_STRIKE,     TIMER_TO_SET);
                events.ScheduleEvent(EVENT_OVERWHELMING_ASSAULT, 20500);
            }

            void EnterCombat(Unit* attacker)
            {
                me->AddAura(SPELL_INTENSIFY, me);
            }

            void MovementInform(uint32 uiType, uint32 id)
            {
                if (uiType != POINT_MOTION_TYPE
                 && uiType != EFFECT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case 1: // Middle
                    {
                        prevSide = 1;
                        instance->SetData(DATA_TAYAK_SIDE, urand(0, 1) ? EAST: WEST);
                        me->AddAura(SPELL_S_U_VISUAL, me);
                        me->CastSpell(me, SPELL_S_U_SPAWN_ALL_TORNADOS, false);
                        events.ScheduleEvent(EVENT_S_U_JUMP_TO_SIDE, 2000);
                        break;
                    }
                    case 2:
                    case 3:
                    {
                        instance->SetData(DATA_TAYAK_SIDE, id == (EAST + 1) ? WEST: EAST);

                        if (prevSide != 1) // Already spawned all tornados while at middle
                            me->CastSpell(me, SPELL_S_U_SPAWN_ALL_TORNADOS, false); // Send all players to the other side

                        prevSide = id;
                        events.ScheduleEvent(EVENT_S_U_SPAWN_TORNADO, 1500);
                        events.ScheduleEvent(EVENT_S_U_SWITCH, 90000);
                        break;
                    }
                }
            }

            void JustDied(Unit* attacker)
            {
                _JustDied();
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);

                if (summon->GetEntry() == NPC_TEMPEST_SLASH)
                    summon->AI()->SetGUID(instance->GetObjectGuid(tempestSlashTargetGUID));
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                summons.Despawn(summon);
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                if (!unleashedStormEventStarted)
                {
                    if (me->HealthBelowPctDamaged(20, damage))
                    {
                        events.Reset();
                        me->SetReactState(REACT_PASSIVE);
                        me->GetMotionMaster()->MoveJump(tayakPos[MIDDLE], 20.0f, 20.0f, 1);
                        unleashedStormEventStarted = true;
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint8 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TEMPEST_SLASH:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 2))
                            {
                                me->SetFacingToObject(target);
                                tempestSlashTargetGUID = target->GetGUID().GetEntry();
                                me->CastSpell(target, SPELL_TEMPEST_SLASH_SUMMON, false);
                            }
                            events.ScheduleEvent(EVENT_TEMPEST_SLASH, TIMER_TO_SET);
                            break;
                        }
                        case EVENT_INVISIBLE_STRIKE:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 2))
                            {
                                previousTargetGUID = me->GetVictim()->GetGUID().GetEntry();

                                me->AddAura(SPELL_INVISIBLE_STRIKE_VISUAL, target);
                                me->CastSpell(target, SPELL_INVISIBLE_STRIKE, false);
                                me->getThreatManager().clearReferences();
                                me->getThreatManager().addThreat(target, 10000000.0f);
                                me->GetMotionMaster()->MoveChase(target, ATTACK_DISTANCE);
                            }
                            events.ScheduleEvent(EVENT_INVISIBLE_STRIKE_END, TIMER_TO_SET);
                            break;
                        }
                        case EVENT_INVISIBLE_STRIKE_END:
                        {
                            if (Unit* oldTarget = ObjectAccessor::GetUnit(*me, instance->GetObjectGuid(previousTargetGUID)))
                            {
                                me->getThreatManager().clearReferences();
                                me->getThreatManager().addThreat(oldTarget, 1000.0f);
                                me->GetMotionMaster()->MoveChase(oldTarget, ATTACK_DISTANCE);
                            }
                            events.ScheduleEvent(EVENT_INVISIBLE_STRIKE, TIMER_TO_SET);
                            break;
                        }
                        case EVENT_OVERWHELMING_ASSAULT:
                        {
                            me->CastSpell(me->GetVictim(), SPELL_OVERWHELMING_ASSAULT, false);
                            events.ScheduleEvent(EVENT_OVERWHELMING_ASSAULT, 20500);
                            break;
                        }
                        case EVENT_S_U_SPAWN_TORNADO:
                        {
                            uint8 tornadoToSpawn = 1;

                            if (!(++tornadoCount % 5))
                                tornadoToSpawn = 2;

                            std::list<Creature*> tornadoSpawner;
                            GetCreatureListWithEntryInGrid(tornadoSpawner, me, NPC_S_U_TORNADO_SPAWNER, 10.0f);

                            Trinity::Containers::RandomResizeList(tornadoSpawner, tornadoToSpawn);

                            for (Creature* spawner : tornadoSpawner)
                                spawner->CastSpell(spawner, SPELL_S_U_SPAWN_TORNADO, true);

                            events.ScheduleEvent(EVENT_S_U_SPAWN_TORNADO, 1500);
                            break;
                        }
                        case EVENT_S_U_JUMP_TO_SIDE:
                        {
                            uint8 nextSide = instance->GetData(DATA_TAYAK_SIDE);
                            me->GetMotionMaster()->MoveJump(tayakPos[nextSide], 20.0f, 20.0f, nextSide + 1);
                            events.Reset();
                            break;
                        }
                        case EVENT_S_U_SWITCH:
                        {
                            uint8 nextSide = instance->GetData(DATA_TAYAK_SIDE) == WEST ? EAST: WEST;
                            me->GetMotionMaster()->MoveJump(tayakPos[nextSide], 20.0f, 20.0f, nextSide + 1);
                            events.Reset();
                            break;
                        }
                        default:
                            break;
                    }
                }

                if (!me->HasAura(SPELL_INVISIBLE_STRIKE))
                    DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_blade_lord_tayakAI(creature);
        }
};

class mob_tempest_slash : public CreatureScript
{
    public:
        mob_tempest_slash() : CreatureScript("mob_tempest_slash") {}

        struct mob_tempest_slashAI : public ScriptedAI
        {
            mob_tempest_slashAI(Creature* creature) : ScriptedAI(creature)
            {}

            uint32 checkNearPlayerTimer;
            Position* centerPos;
            bool isArrived;
            float nextOrientation;

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
                me->AddAura(SPELL_TEMPEST_SLASH_AURA, me);
                isArrived = false;
                centerPos = NULL;
                nextOrientation = 0.0f;
            }

            void SetGUID(uint64 guid, int32 /*id*/ = 0)
            {
                if (Player* player = ObjectAccessor::FindPlayer(GetGUID(guid)))
                    me->GetMotionMaster()->MoveCharge(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), 12.0f, 1, false);
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (id == 1)
                {
                    isArrived = true;
                    me->GetPosition(centerPos->m_positionX,centerPos->m_positionY);
                }
                else if (id == 2)
                    isArrived = true;
            }

            void UpdateAI(uint32 diff)
            {
                if (!isArrived)
                    return;

                if (!centerPos)
                    return;

                float x = centerPos->GetPositionX() + (1.0f * cos(nextOrientation));
                float y = centerPos->GetPositionY() + (1.0f * sin(nextOrientation));

                me->GetMotionMaster()->MovePoint(2, x, y, me->GetPositionZ());
                nextOrientation += 1.0f;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_tempest_slashAI(creature);
        }
};

class mob_tayak_tornado_all : public CreatureScript
{
    public:
        mob_tayak_tornado_all() : CreatureScript("mob_tayak_tornado_all") {}

        struct mob_tayak_tornado_allAI : public ScriptedAI
        {
            mob_tayak_tornado_allAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;

            void Reset()
            {
                if (!pInstance)
                    return;

                DoZoneInCombat(me, 200.0f);

                Unit* nearestPlayer = SelectTarget(SELECT_TARGET_NEAREST, 0, 0, true, -SPELL_S_U_RIDE_VEHICLE);

                if (!nearestPlayer)
                {
                    me->DespawnOrUnsummon();
                    return;
                }

                nearestPlayer->CastSpell(me, SPELL_S_U_RIDE_VEHICLE, true);
                uint8 otherSide = pInstance->GetData(DATA_TAYAK_SIDE) == EAST ? WEST: EAST;
                me->GetMotionMaster()->MovePoint(1, tayakPos[otherSide]);
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (id == 1)
                    me->DespawnOrUnsummon();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_tayak_tornado_allAI(creature);
        }
};

class mob_tayak_tornado : public CreatureScript
{
    public:
        mob_tayak_tornado() : CreatureScript("mob_tayak_tornado") {}

        struct mob_tayak_tornadoAI : public ScriptedAI
        {
            mob_tayak_tornadoAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;

            void Reset()
            {
                if (!pInstance)
                    return;

                uint8 otherSide = pInstance->GetData(DATA_TAYAK_SIDE) == EAST ? WEST: EAST;
                me->GetMotionMaster()->MovePoint(1, me->GetPositionX(), tayakPos[otherSide].GetPositionY(), tayakPos[otherSide].GetPositionZ());
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (id == 1)
                    me->DespawnOrUnsummon();
            }

            void UpdateAI(uint32 diff)
            {
                if (me->GetVehicleKit()->GetPassenger(0))
                    return;

                if (Player* player = me->SelectNearestPlayer(1.0f))
                    if (!player->HasSpell(SPELL_S_U_RIDE_VEHICLE))
                        player->CastSpell(me, SPELL_S_U_RIDE_VEHICLE, true);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_tayak_tornadoAI(creature);
        }
};

// invisible strike damages - 122994
class spell_invisible_strike : public SpellScriptLoader
{
    public:
        spell_invisible_strike() : SpellScriptLoader("spell_invisible_strike") { }

        class spell_invisible_strike_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_invisible_strike_SpellScript);

            uint8 targetCount;

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targetCount = targets.size();
            }

            void DealDamage()
            {
                SetHitDamage(GetHitDamage() / targetCount);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_invisible_strike_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
                OnHit                    += SpellHitFn(spell_invisible_strike_SpellScript::DealDamage);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_invisible_strike_SpellScript();
        }
};

// Wind Step - 123175
class spell_wind_step : public SpellScriptLoader
{
    public:
        spell_wind_step() : SpellScriptLoader("spell_wind_step") { }

        class spell_wind_step_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_wind_step_SpellScript);

            void HandleScript()
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        caster->AddAura(SPELL_WIND_STEP_DAMAGE, target);
                    }
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_wind_step_SpellScript::HandleScript);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_wind_step_SpellScript();
        }
};

void AddSC_boss_blade_lord_tayak()
{
    new boss_blade_lord_tayak();
    new mob_tempest_slash();
    new mob_tayak_tornado_all();
    new mob_tayak_tornado();
    new spell_wind_step();
    new spell_invisible_strike();
}
