/*
 * Copyright 2021 BfaCore
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "uldir.h"

enum Definitions
{
    SAY_AGGRO = 0,
    SAY_SANITIZING_STRIKE,
    SAY_PURIFYING_FLAME,
    SAY_ULDIR_DEFENSIVE_BEAM,
    SAY_CLEANSING_PURGE,
    SAY_WIND_TUNNEL,
    SAY_KILL,
    SAY_WIPE,
    SPELL_PERIODIC_ENERGY_GAIN = 295065,
    EVENT_ENERGIZE = 1,
    EVENT_CLEANSING_PURGE,
    EVENT_SANITIZING_STRIKE,
    EVENT_PURIFYING_FLAME,
    EVENT_WIND_TUNNEL,
    EVENT_ULDIR_DEFENSIVE_BEAM,
    //Rooms
    SPELL_FIRST_ROOM_OCCUPANT = 267814,
    SPELL_SECOND_ROOM_OCCUPANT = 267817,
    SPELL_THIRD_ROOM_OCCUPANT = 267819,
    //Depleted Energy
    SPELL_DEPLETED_ENERGY = 274205,
    //Cleansing Purge
    SPELL_CLEANSING_PURGE_AT = 268089,
    SPELL_CLEANSING_PURGE_AURA = 268277,
    //Purifying Flame
    SPELL_PURIFYING_FLAME_SUMMON = 267802,
    SPELL_PURIFYING_FLAME_DAMAGE = 267803,
    SPELL_PURIFYING_FLAME_AT = 267887,
    //Sanitizing Strike
    SPELL_SANITIZING_STRIKE = 267787,
    //Wind Tunnel
    SPELL_WIND_TUNNEL_AT_R_TO_L = 267885,
    SPELL_WIND_TUNNEL_AT_L_TO_R = 267878,
    //275919 Wind Tunnel
    //Defense Grid
    SPELL_DEFENSE_GRID_DAMAGE = 267821,
    //136298 npc, Defense Grid
    SPELL_DEFENSE_GRID_MISSILE_SUMMON = 267832,    
    //Uldir Defensive Beams
    SPELL_ULDIR_DEFENSE_BEAM_H_AT_M = 275228, //npc 136554, from top to ground
    SPELL_ULDIR_DEFENSE_BEAM_V_AT_M = 277961, //wall
    SPELL_ULDIR_DEFENSE_BEAM_V_AT_R = 281642,
    SPELL_ULDIR_DEFENSE_BEAM_V_AT_L = 281644,
    SPELL_ULDIR_DEFENSE_BEAM_AT_DAMAGE = 275432,
    NPC_SURGICAL_GRID = 136554,
    MOTHER_ENCOUNTER = 2141,
};

const Position middle_of_the_room_pos = { -135.431f, -255.882f, 733.840f, 0.0f };
const Position final_pos = { 70.888f, -255.695f, 704.580f, 0.04f };

//135452
struct boss_mother : public BossAI
{
    boss_mother(Creature* creature) : BossAI(creature, DATA_MOTHER)
    {
        instance = creature->GetInstanceScript();
    }

    void Reset() override
    {
        BossAI::Reset();
        me->RemoveAllAreaTriggers();
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->AddAura(AURA_OVERRIDE_POWER_COLOR_ENTROPIC);
        defeated = false;
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FIRST_ROOM_OCCUPANT);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SECOND_ROOM_OCCUPANT);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_THIRD_ROOM_OCCUPANT);
        me->DespawnCreaturesInArea(NPC_PURIFYING_FLAME_2, 125.0f);
        me->DespawnCreaturesInArea(NPC_SURGICAL_GRID, 125.0f);
        Talk(SAY_WIPE);
        _JustReachedHome();
        _DespawnAtEvade();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        Talk(SAY_AGGRO);
        _EnterCombat();
        instance->DoAddAuraOnPlayers(SPELL_FIRST_ROOM_OCCUPANT);
        events.ScheduleEvent(EVENT_SANITIZING_STRIKE, 3s);
        events.ScheduleEvent(EVENT_PURIFYING_FLAME, 6s);
        events.ScheduleEvent(EVENT_WIND_TUNNEL, 20s);
        events.ScheduleEvent(EVENT_ULDIR_DEFENSIVE_BEAM, 30s);
        DoCastSelf(SPELL_PERIODIC_ENERGY_GAIN);
    }

    void DamageTaken(Unit* done_by, uint32& /*damage*/) override
    {
        if (me->HealthBelowPct(2) && !defeated)
        {
            defeated = true;
            _JustDied();
            me->SetFaction(35);
            Talk(20);
            if (GameObject* cache = instance->GetGameObject(GO_MOTHER_CACHE))
            {
                cache->RemoveFlag(GO_FLAG_LOCKED);
            }
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->SetWalk(true);
            me->SetHealth(me->GetMaxHealth());            
            me->DeleteThreatList();
            me->ClearInCombat();
            instance->SendBossKillCredit(MOTHER_ENCOUNTER);
            me->GetScheduler().Schedule(4s, [this](TaskContext context)
            {
                me->GetMotionMaster()->MovePoint(1, final_pos, true);
            });
        }
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (point == 1)
        {
            me->SetFacingTo(0.04f, true);
            Talk(21);
            me->GetScheduler().Schedule(7s, [this] (TaskContext context)
            {
                me->DespawnOrUnsummon();
            });
        }
    }

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_SANITIZING_STRIKE)
        {
            if (Unit* tar = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
            {
                me->AddAura(SPELL_SANITIZING_STRIKE, tar);
            }
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_SANITIZING_STRIKE:
        {
            Talk(SAY_SANITIZING_STRIKE);
            if (Unit* tar = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
            {
                DoCast(tar, SPELL_SANITIZING_STRIKE, false);
            }            
            me->SetPower(POWER_ENERGY, 0);
            events.Repeat(20s);
            break;
        }
        case EVENT_WIND_TUNNEL:
        {
            Talk(SAY_WIND_TUNNEL);
            if (Unit* victim = me->GetVictim())
            {
                Position wind_tunnel_pos = wind_tunnel_positions[2];

                if (victim->HasAura(SPELL_FIRST_ROOM_OCCUPANT))
                    wind_tunnel_pos = wind_tunnel_positions[0];

                else if (victim->HasAura(SPELL_SECOND_ROOM_OCCUPANT))
                    wind_tunnel_pos = wind_tunnel_positions[1];

                 if (Creature* wind_tunnel = me->FindNearestCreature(NPC_WIND_TUNNEL, 75.0f))
                 {
                    if (urand(0, 1))
                        wind_tunnel->CastSpell(wind_tunnel, SPELL_WIND_TUNNEL_AT_L_TO_R);
                    else
                        wind_tunnel->CastSpell(wind_tunnel, SPELL_WIND_TUNNEL_AT_R_TO_L);
                 }
            }
            events.Repeat(30s);
            break;
        }
        case EVENT_PURIFYING_FLAME:
        {
            Talk(SAY_PURIFYING_FLAME);
            UnitList tarlist;
            SelectTargetList(tarlist, 100, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : tarlist)
            {
                targets->SummonCreature(NPC_PURIFYING_FLAME_2, targets->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
            }
            events.Repeat(25s);
            break;
        }
        case EVENT_ULDIR_DEFENSIVE_BEAM:
        {            
            Talk(SAY_ULDIR_DEFENSIVE_BEAM);
            //Mid grid from top to ground
            me->SummonCreature(NPC_SURGICAL_GRID, middle_of_the_room_pos, TEMPSUMMON_MANUAL_DESPAWN);
            events.Repeat(35s);
            break;
        }
        }
    }

private:
    InstanceScript* instance;
    bool defeated;

    Position wind_tunnel_positions[3] =
    {
        { -135.3048f, -255.4786f, 695.2135f },
        { -81.3048f, -255.4786f, 695.2144f },
        { -27.3048f, -255.4786f, 695.2135f }
    };
};

//136429
struct uldir_chamber_1 : public ScriptedAI
{
    uldir_chamber_1(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
    }
};

//137022
struct uldir_chamber_2 : public ScriptedAI
{
    uldir_chamber_2(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
    }
};

//137023
struct uldir_chamber_3 : public ScriptedAI
{
    uldir_chamber_3(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
    }
};

//136322
struct npc_mother_wind_tunnel : public ScriptedAI
{
    npc_mother_wind_tunnel(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
    }
};

//136325
struct npc_corners_purifying_flame : public ScriptedAI
{
    npc_corners_purifying_flame(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
    }


    void IsSummonedBy(Unit* unit) override
    {
        me->CastSpell(nullptr, SPELL_PURIFYING_FLAME_DAMAGE);
    }

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_PURIFYING_FLAME_DAMAGE)
        {
            me->DespawnOrUnsummon();
        }
    }

    void DoAction(int32 action) override
    {

    }
};

//136289
struct npc_summons_purifying_flame : public ScriptedAI
{
    npc_summons_purifying_flame(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
    }
};

//136298
struct npc_mother_defense_grid : public ScriptedAI
{
    npc_mother_defense_grid(Creature* creature) : ScriptedAI(creature)
    {
        timer = 200;
    }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (timer < diff)
        {
            timer = 200;
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 10.0f);

            for (Player* player : playerList)
            {
                if (player->HasAura(SPELL_FIRST_ROOM_OCCUPANT))
                {
                    // if player goes from chamber #1 to chamber #2
                    if (player->GetPosition().m_positionX > first_to_second)
                    {
                        player->RemoveAura(SPELL_FIRST_ROOM_OCCUPANT);
                        player->AddAura(SPELL_SECOND_ROOM_OCCUPANT);

                        instance->DoCastSpellOnPlayers(SPELL_DEFENSE_GRID_DAMAGE);
                        player->Yell(player->GetName(), LANG_UNIVERSAL);
                    }
                }
                else if (player->HasAura(SPELL_SECOND_ROOM_OCCUPANT))
                {
                    // if player goes from chamber #2 to chamber #3
                    if (player->GetPosition().m_positionX > second_to_third)
                    {
                        player->RemoveAura(SPELL_SECOND_ROOM_OCCUPANT);
                        player->AddAura(SPELL_THIRD_ROOM_OCCUPANT);

                        instance->DoCastSpellOnPlayers(SPELL_DEFENSE_GRID_DAMAGE);
                        player->Yell(player->GetName(), LANG_UNIVERSAL);
                    }
                    // if player goes from chamber #2 to chamber #1
                    else if (player->GetPosition().m_positionX < first_to_second)
                    {
                        player->RemoveAura(SPELL_SECOND_ROOM_OCCUPANT);
                        player->AddAura(SPELL_FIRST_ROOM_OCCUPANT);

                        instance->DoCastSpellOnPlayers(SPELL_DEFENSE_GRID_DAMAGE);
                        player->Yell(player->GetName(), LANG_UNIVERSAL);
                    }
                }

                else if (player->HasAura(SPELL_THIRD_ROOM_OCCUPANT))
                {
                    // if player goes from chamber #3 to chamber #2
                    if (player->GetPosition().m_positionX < second_to_third)
                    {
                        player->RemoveAura(SPELL_THIRD_ROOM_OCCUPANT);
                        player->AddAura(SPELL_SECOND_ROOM_OCCUPANT);

                        instance->DoCastSpellOnPlayers(SPELL_DEFENSE_GRID_DAMAGE);
                        player->Yell(player->GetName(), LANG_UNIVERSAL);
                    }
                }
            }
        }
        else
            timer -= diff;
    }

private:
    float timer;
    float first_to_second = -108.608f;
    float second_to_third = -54.6701f;
};

//136736
struct npc_red_queen_room : public ScriptedAI
{
    npc_red_queen_room(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
    }
};

const Position wind_tunnel_push_positions[6] =
{
    { -135.568f, -285.398f,	695.298f, float(M_PI / 2.0) },
    { -135.576f, -225.922f,	695.298f, float(3 * M_PI / 2.0) },
    { -81.5712f, -285.398f,	695.298f, float(M_PI / 2.0) },
    { -81.6562f, -225.922f,	695.298f, float(3 * M_PI / 2.0) },
    { -27.5035f, -285.398f,	695.298f, float(M_PI / 2.0) },
    { -27.6267f, -225.922f,	695.298f, float(3 * M_PI / 2.0) }
};

//267878, 17765 at
struct at_wind_tunnel_l_to_r : public AreaTriggerAI
{
    at_wind_tunnel_l_to_r(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    void OnInitialize() override
    {
        at->SetPeriodicProcTimer(500);
    }

    void OnPeriodicProc() override
    {
        std::list<Player*> playerList;
        at->GetPlayerListInGrid(playerList, 100.0f);
        for (Player* player : playerList)
        {
            if (player->HasAura(SPELL_FIRST_ROOM_OCCUPANT))
                player->ApplyMovementForce(at->GetGUID(), wind_tunnel_push_positions[1], -5.f, 0);

            else if (player->HasAura(SPELL_SECOND_ROOM_OCCUPANT))
                player->ApplyMovementForce(at->GetGUID(), wind_tunnel_push_positions[3], -5.f, 0);

            else if (player->HasAura(SPELL_THIRD_ROOM_OCCUPANT))
                player->ApplyMovementForce(at->GetGUID(), wind_tunnel_push_positions[5], -5.f, 0);
        }
    }

    void OnRemove() override
    {
        if (InstanceScript* instance = at->GetInstanceScript())
            instance->DoRemoveForcedMovementsOnPlayers(at->GetGUID());
    }
};

//267885, 19645 at
struct at_wind_tunnel_r_to_l : public AreaTriggerAI
{
    at_wind_tunnel_r_to_l(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    void OnInitialize() override
    {
        at->SetPeriodicProcTimer(500);
    }

    void OnPeriodicProc() override
    {
        std::list<Player*> playerList;
        at->GetPlayerListInGrid(playerList, 75.0f);
        for (Player* player : playerList)
        {
            if (player->HasAura(SPELL_FIRST_ROOM_OCCUPANT))
                player->ApplyMovementForce(at->GetGUID(), wind_tunnel_push_positions[0], -5.f, 0);

            else if (player->HasAura(SPELL_SECOND_ROOM_OCCUPANT))
                player->ApplyMovementForce(at->GetGUID(), wind_tunnel_push_positions[2], -5.f, 0);

            else if (player->HasAura(SPELL_THIRD_ROOM_OCCUPANT))
                player->ApplyMovementForce(at->GetGUID(), wind_tunnel_push_positions[4], -5.f, 0);
        }
    }

    void OnRemove() override
    {
        if (InstanceScript* instance = at->GetInstanceScript())
            instance->DoRemoveForcedMovementsOnPlayers(at->GetGUID());
    }
};

//136554
struct npc_surgical_grid : public ScriptedAI
{
    npc_surgical_grid(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* unit) override
    {
        //me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
        me->SetDisplayId(16925);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);        
        me->GetScheduler().Schedule(1s, [this] (TaskContext context)
        {
            me->CastSpell(me, SPELL_ULDIR_DEFENSE_BEAM_H_AT_M);
            me->SetWalk(true);
            me->SetSpeedRate(MOVE_WALK, me->GetSpeed(MOVE_WALK) / 2);
            me->UpdateSpeed(MOVE_WALK);
            me->GetMotionMaster()->MoveTargetedHome();
        });        
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
        if (me->GetPositionZ() < 696.0f)
        {
            me->DespawnOrUnsummon();
        }        
    }

private:
    TaskScheduler scheduler;    
};

struct at_surgical_grid : public AreaTriggerAI
{
    at_surgical_grid(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    void OnInitialize() override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        Position pos = caster->GetPosition();

        at->MovePosition(pos, 60.0f, caster->GetOrientation());
        at->SetDestination(pos, 15000);    
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsPlayer())
        {
            at->GetCaster()->CastSpell(unit, SPELL_ULDIR_DEFENSE_BEAM_AT_DAMAGE);
        }
    }

    void OnUnitExit(Unit* unit) override
    {
        if (unit->HasAura(SPELL_ULDIR_DEFENSE_BEAM_AT_DAMAGE))
        {
            unit->RemoveAurasDueToSpell(SPELL_ULDIR_DEFENSE_BEAM_AT_DAMAGE);
        }
    }
};

//291079
struct go_mothers_cache : public GameObjectAI
{
    go_mothers_cache(GameObject* go) : GameObjectAI(go)
    {
        go->AddFlag(GO_FLAG_LOCKED);
    }

    void Reset() override
    {    
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }

private:
    TaskScheduler scheduler;
};

void AddSC_boss_mother()
{
    RegisterCreatureAI(boss_mother);
    RegisterCreatureAI(uldir_chamber_1);                 
    RegisterCreatureAI(uldir_chamber_2); 
    RegisterCreatureAI(uldir_chamber_3);
    RegisterCreatureAI(npc_red_queen_room);
    RegisterCreatureAI(npc_mother_defense_grid);
    RegisterCreatureAI(npc_mother_wind_tunnel);
    RegisterCreatureAI(npc_corners_purifying_flame);
    RegisterCreatureAI(npc_summons_purifying_flame);
    RegisterAreaTriggerAI(at_wind_tunnel_l_to_r);
    RegisterAreaTriggerAI(at_wind_tunnel_r_to_l);
    RegisterCreatureAI(npc_surgical_grid);
    RegisterAreaTriggerAI(at_surgical_grid);
    RegisterGameObjectAI(go_mothers_cache);
}
