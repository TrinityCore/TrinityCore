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

/* Script Data Start
SDName: Redridge Mountains
SD%Complete: 0
SDComment:
Script Data End */

#include "ScriptMgr.h"
#include "Containers.h"
#include "G3DPosition.hpp"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "WaypointDefines.h"
#include "World.h"
#include <algorithm>

enum RedridgeSpellData
{
    SPELL_APPLY_QUEST_INVIS_ZONE_3  = 80815, // Used by npc's in Lakeshire Inn
    SPELL_APPLY_QUEST_INVIS_ZONE_4  = 80816, // Used by npc's in Lakeshire Inn

    SPELL_APPLY_QUEST_INVIS_ZONE_19 = 82099,  // Used by npc's in Lakeshire Townhall

    SPELL_CONTROL_ETTIN             = 80704,
    SPELL_CONTROL_ETTIN_2           = 80702,
    SPELL_LIFT_HUGE_BOULDER         = 80739,
    SPELL_LIFT_BOULDER_RIDE         = 82566,
    SPELL_CANYON_ETTIN_SPAWN_SPELL  = 82558,
    SPELL_BOULDER_AURA              = 82556,
    SPELL_DESPAWN_KILL_CREDIT       = 228623,
    SPELL_EJECT_PASSENGER_1         = 80743,
    SPELL_CANYON_ETTIN_DESPAWN      = 82561,
    SPELL_DESPAWN_ETTIN             = 80707,
};

enum RedridgeCreatureData
{
    NPC_FOREMAN_OSLOW         = 341,
    NPC_BRIDGE_WORKER_ALEX    = 653,
    NPC_BRIDGE_WORKER_TRENT   = 648,
    NPC_BRIDGE_WORKER_DMITRI  = 649,
    NPC_BRIDGE_WORKER_JESS    = 650,
    NPC_BRIDGE_WORKER_DANIEL  = 651,
    NPC_BRIDGE_WORKER_MATTHEW = 652,
    NPC_CANYON_ETTIN          = 43094,
    NPC_SUBDUED_CANYON_ETTIN  = 43197,
    NPC_HUGE_BOULDER          = 43196,

    NPC_BIGEARL               = 43248,
};

enum RedridgeTalks
{
    TALK_OSLOW_IDLE         = 0,

    TALK_ALEX_HEAVE         = 1,
    TALK_ALEX_DAMN          = 2,
    TALK_ALEX_PUSH          = 4,
    TALK_ALEX_SCARED        = 5,

    TALK_WORKERS_HO         = 0,

    TALK_MATTHEW_IM_PUSHING = 1,
    TALK_MATTHEW_SCARED     = 2,

    TALK_TRENT_SCARED       = 1,

    TALK_DMITRI_SCARED      = 1,

    TALK_JESS_SCARED        = 1,

    TALK_DANIEL_SCARED      = 1,

    TALK_NOT_SO_HEAVY       = 0,
    TALK_WHERE_THROW        = 1,
    TALK_THROW_IN_WATER     = 2,
    TALK_BYE                = 3
};

/*######
# npc_dumpy_and_keeshan "Used by entries 43249 and 43184"
######*/

class npc_dumpy_and_keeshan : public CreatureScript
{
public:
    npc_dumpy_and_keeshan() : CreatureScript("npc_dumpy_and_keeshan") { }

    struct npc_dumpy_and_keeshanAI : public ScriptedAI
    {
        npc_dumpy_and_keeshanAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _scheduler.Schedule(Seconds(1), [this](TaskContext targetSearch)
            {
                std::list<Creature*> bigEarlList;
                me->GetCreatureListWithEntryInGrid(bigEarlList, NPC_BIGEARL, 5.0f);

                for (Creature* bigEarl : bigEarlList)
                    if ((bigEarl->HasAura(SPELL_APPLY_QUEST_INVIS_ZONE_3) && me->HasAura(SPELL_APPLY_QUEST_INVIS_ZONE_3))
                        || (bigEarl->HasAura(SPELL_APPLY_QUEST_INVIS_ZONE_4) && me->HasAura(SPELL_APPLY_QUEST_INVIS_ZONE_4)))
                        AttackStart(bigEarl);

                if (!me->IsInCombat())
                    targetSearch.Repeat();
            });
        }

        void DamageTaken(Unit* who, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
        {
            if ((!who || who->GetTypeId() == TYPEID_UNIT) && me->HealthBelowPctDamaged(82, damage))
                damage = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            _scheduler.Update(diff);
        }

    private:
        TaskScheduler _scheduler;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_dumpy_and_keeshanAI(creature);
    }
};

/*######
# npc_big_earl "Used by entry 43248"
######*/

class npc_big_earl : public CreatureScript
{
public:
    npc_big_earl() : CreatureScript("npc_big_earl") { }

    struct npc_big_earlAI : public ScriptedAI
    {
        npc_big_earlAI(Creature* creature) : ScriptedAI(creature) { }

        void DamageTaken(Unit* who, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
        {
            if ((!who || who->GetTypeId() == TYPEID_UNIT) && me->HealthBelowPctDamaged(82, damage))
                damage = 0;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_big_earlAI(creature);
    }
};

enum RedridgeHugeBoulder
{
    EVENT_STORE_GUIDS           = 1,
    EVENT_OSLOW_IDLE_TALK       = 2,
    EVENT_ALEX_IDLE_TALK        = 3,
    EVENT_WORKERS_RESPONSE      = 4,
    EVENT_ALEX_SAY_PUSH         = 5,
    EVENT_MATTHEW_PUSH_RESPONSE = 6,
    EVENT_REPOSITION            = 7,
    EVENT_BRIDGE_WORKERS_COWER  = 8,
    EVENT_OSLOW_GET_UP          = 9,
    EVENT_OSLOW_STUN            = 10,
    EVENT_ETTIN_LINE_1          = 11,
    EVENT_ETTIN_LINE_2          = 12,
    EVENT_MOVE_TO_WATER         = 13,
    EVENT_THROW_BOULDER         = 14,
    EVENT_PATH_AWAY             = 15,
    EVENT_DONE,

    ACTION_OSLOW_GET_UP         = 0,
    ACTION_COWER                = 1,
    ACTION_DONE,

    PATH_ETTIN_TO_WATER         = 4319700,
    PATH_ETTIN_UP_HILL          = 4319701,

    POINT_NEAR_BOULDER          = 1,
    POINT_NEAR_WATER            = 2,
    POINT_UP_PATH               = 3,
};

constexpr Position TrentRepositionPos = { -9281.44f, -2285.27f, 67.5123f, 6.0213f };
constexpr Position DmitriRepositionPos = { -9282.8f, -2293.28f, 67.5089f, 6.2657f };
constexpr Position JessRepositionPos = { -9282.27f, -2290.95f, 67.5319f, 6.0737f };
constexpr Position DanielRepositionPos = { -9281.77f, -2287.55f, 67.5869f, 6.0911f };
constexpr Position MatthewRepositionPos = { -9280.71f, -2283.21f, 67.5747f, 6.0737f };
constexpr Position AlexRepositionPos = { -9279.86f, -2281.42f, 67.5854f, 5.7421f };

// 43196 - Huge Boulder
struct npc_redridge_huge_boulder : public CreatureAI
{
    npc_redridge_huge_boulder(Creature* creature) : CreatureAI(creature) { }

    void Reset() override
    {
        _events.Reset();
        _oslowGUID.Clear();
        _alexGUID.Clear();
        _trentGUID.Clear();
        _dmitriGUID.Clear();
        _jessGUID.Clear();
        _danielGUID.Clear();
        _matthewGUID.Clear();
        _events.ScheduleEvent(EVENT_STORE_GUIDS, 5s);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id != SPELL_LIFT_BOULDER_RIDE)
            return;

        _events.Reset();
        _events.ScheduleEvent(EVENT_REPOSITION, 0ms);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_STORE_GUIDS:
                {
                    if (Creature const* oslow = me->FindNearestCreature(NPC_FOREMAN_OSLOW, 10.0f, true))
                        _oslowGUID = oslow->GetGUID();
                    if (Creature const* alex = me->FindNearestCreature(NPC_BRIDGE_WORKER_ALEX, 10.0f, true))
                        _alexGUID = alex->GetGUID();
                    if (Creature const* trent = me->FindNearestCreature(NPC_BRIDGE_WORKER_TRENT, 10.0f, true))
                        _trentGUID = trent->GetGUID();
                    if (Creature const* dimitri = me->FindNearestCreature(NPC_BRIDGE_WORKER_DMITRI, 10.0f, true))
                        _dmitriGUID = dimitri->GetGUID();
                    if (Creature const* jess = me->FindNearestCreature(NPC_BRIDGE_WORKER_JESS, 10.0f, true))
                        _jessGUID = jess->GetGUID();
                    if (Creature const* daniel = me->FindNearestCreature(NPC_BRIDGE_WORKER_DANIEL, 10.0f, true))
                        _danielGUID = daniel->GetGUID();
                    if (Creature const* matthew = me->FindNearestCreature(NPC_BRIDGE_WORKER_MATTHEW, 10.0f, true))
                        _matthewGUID = matthew->GetGUID();

                    if (!_oslowGUID || !_alexGUID || !_trentGUID || !_dmitriGUID || !_jessGUID || !_danielGUID || !_matthewGUID)
                        _events.Repeat(1s);
                    else
                    {
                        _events.ScheduleEvent(EVENT_OSLOW_IDLE_TALK, 45s, 60s);
                        _events.ScheduleEvent(EVENT_ALEX_IDLE_TALK, 20s, 30s);
                    }
                    break;
                }
                case EVENT_OSLOW_IDLE_TALK:
                {
                    if (Creature const* oslow = ObjectAccessor::GetCreature(*me, _oslowGUID))
                        oslow->AI()->Talk(TALK_OSLOW_IDLE);
                    _events.Repeat(45s, 60s);
                    break;
                }
                case EVENT_ALEX_IDLE_TALK:
                {
                    if (Creature const* alex = ObjectAccessor::GetCreature(*me, _alexGUID))
                    {
                        switch (uint32 text = urand(0, 3))
                        {
                            case TALK_ALEX_HEAVE:
                                alex->AI()->Talk(TALK_ALEX_HEAVE);
                                _events.ScheduleEvent(EVENT_WORKERS_RESPONSE, 1s);
                                break;
                            case TALK_ALEX_DAMN:
                                alex->AI()->Talk(TALK_ALEX_DAMN);
                                _events.ScheduleEvent(EVENT_ALEX_SAY_PUSH, 3s);
                                break;
                            default:
                                alex->AI()->Talk(text);
                                _events.Repeat(10s);
                                break;
                        }
                    }
                    break;
                }
                case EVENT_WORKERS_RESPONSE:
                {
                    if (Creature const* alex = ObjectAccessor::GetCreature(*me, _alexGUID))
                    {
                        if (Creature const* trent = ObjectAccessor::GetCreature(*me, _trentGUID))
                            trent->AI()->Talk(TALK_WORKERS_HO, alex);
                        if (Creature const* dmitri = ObjectAccessor::GetCreature(*me, _dmitriGUID))
                            dmitri->AI()->Talk(TALK_WORKERS_HO, alex);
                        if (Creature const* jess = ObjectAccessor::GetCreature(*me, _jessGUID))
                            jess->AI()->Talk(TALK_WORKERS_HO, alex);
                        if (Creature const* daniel = ObjectAccessor::GetCreature(*me, _danielGUID))
                            daniel->AI()->Talk(TALK_WORKERS_HO, alex);
                        if (Creature const* matthew = ObjectAccessor::GetCreature(*me, _matthewGUID))
                            matthew->AI()->Talk(TALK_WORKERS_HO, alex);
                    }
                    _events.ScheduleEvent(EVENT_ALEX_IDLE_TALK, 20s, 30s);
                    break;
                }
                case EVENT_ALEX_SAY_PUSH:
                {
                    if (Creature const* alex = ObjectAccessor::GetCreature(*me, _alexGUID))
                        alex->AI()->Talk(TALK_ALEX_PUSH);
                    _events.ScheduleEvent(EVENT_MATTHEW_PUSH_RESPONSE, 4s);
                    break;
                }
                case EVENT_MATTHEW_PUSH_RESPONSE:
                {
                    if (Creature const* matthew = ObjectAccessor::GetCreature(*me, _matthewGUID))
                    {
                        if (Creature const* alex = ObjectAccessor::GetCreature(*me, _alexGUID))
                            matthew->AI()->Talk(TALK_MATTHEW_IM_PUSHING, alex);
                    }
                    _events.ScheduleEvent(EVENT_ALEX_IDLE_TALK, 20s, 30s);
                    break;
                }
                case EVENT_REPOSITION:
                {
                    if (Creature* trent = ObjectAccessor::GetCreature(*me, _trentGUID))
                    {
                        trent->SetAIAnimKitId(0);
                        trent->GetMotionMaster()->MovePoint(0, TrentRepositionPos, true, TrentRepositionPos.GetOrientation());
                    }

                    if (Creature* dmitri = ObjectAccessor::GetCreature(*me, _dmitriGUID))
                    {
                        dmitri->SetAIAnimKitId(0);
                        dmitri->GetMotionMaster()->MovePoint(0, DmitriRepositionPos, true, DmitriRepositionPos.GetOrientation());
                    }

                    if (Creature* jess = ObjectAccessor::GetCreature(*me, _jessGUID))
                    {
                        jess->SetAIAnimKitId(0);
                        jess->GetMotionMaster()->MovePoint(0, JessRepositionPos, true, JessRepositionPos.GetOrientation());
                    }

                    if (Creature* daniel = ObjectAccessor::GetCreature(*me, _danielGUID))
                    {
                        daniel->SetAIAnimKitId(0);
                        daniel->GetMotionMaster()->MovePoint(0, DanielRepositionPos, true, DanielRepositionPos.GetOrientation());
                    }

                    if (Creature* matthew = ObjectAccessor::GetCreature(*me, _matthewGUID))
                    {
                        matthew->SetAIAnimKitId(0);
                        matthew->GetMotionMaster()->MovePoint(0, MatthewRepositionPos, true, MatthewRepositionPos.GetOrientation());
                    }

                    if (Creature* alex = ObjectAccessor::GetCreature(*me, _alexGUID))
                    {
                        alex->SetAIAnimKitId(0);
                        alex->GetMotionMaster()->MovePoint(0, AlexRepositionPos, true, AlexRepositionPos.GetOrientation());
                    }
                    break;
                }
                case EVENT_BRIDGE_WORKERS_COWER:
                {
                    // all workers should cower
                    std::vector<ObjectGuid> allWorkers = { _alexGUID, _matthewGUID, _trentGUID, _dmitriGUID, _jessGUID, _danielGUID };
                    for (ObjectGuid const& workerGUID : allWorkers)
                        if (Creature* worker = ObjectAccessor::GetCreature(*me, workerGUID))
                            worker->SetEmoteState(EMOTE_STATE_COWER);

                    // pick two random workers to say random scared things
                    Trinity::Containers::RandomResize(allWorkers, 2);

                    for (ObjectGuid const workerGUID : allWorkers)
                    {
                        Creature* worker = ObjectAccessor::GetCreature(*me, workerGUID);
                        if (!worker)
                            continue;

                        switch (worker->GetEntry())
                        {
                            case NPC_BRIDGE_WORKER_ALEX:
                                worker->AI()->Talk(TALK_ALEX_SCARED, me);
                                break;
                            case NPC_BRIDGE_WORKER_MATTHEW:
                                worker->AI()->Talk(TALK_MATTHEW_SCARED, me);
                                break;
                            case NPC_BRIDGE_WORKER_TRENT:
                                worker->AI()->Talk(TALK_TRENT_SCARED, me);
                                break;
                            case NPC_BRIDGE_WORKER_DMITRI:
                                worker->AI()->Talk(TALK_DMITRI_SCARED, me);
                                break;
                            case NPC_BRIDGE_WORKER_JESS:
                                worker->AI()->Talk(TALK_JESS_SCARED, me);
                                break;
                            case NPC_BRIDGE_WORKER_DANIEL:
                                worker->AI()->Talk(TALK_DANIEL_SCARED, me);
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                }
                case EVENT_OSLOW_GET_UP:
                {
                    if (Creature* oslow = ObjectAccessor::GetCreature(*me, _oslowGUID))
                        oslow->SetStandState(UNIT_STAND_STATE_STAND);

                    _events.ScheduleEvent(EVENT_OSLOW_STUN, 2s);
                    break;
                }
                case EVENT_OSLOW_STUN:
                {
                    if (Creature* oslow = ObjectAccessor::GetCreature(*me, _oslowGUID))
                        oslow->SetEmoteState(EMOTE_STATE_STUN);
                    break;
                }
                case EVENT_DONE:
                {
                    if (Creature* alex = ObjectAccessor::GetCreature(*me, _alexGUID))
                        alex->DespawnOrUnsummon();
                    if (Creature* matthew = ObjectAccessor::GetCreature(*me, _matthewGUID))
                        matthew->DespawnOrUnsummon();
                    if (Creature* trent = ObjectAccessor::GetCreature(*me, _trentGUID))
                        trent->DespawnOrUnsummon();
                    if (Creature* dmitri = ObjectAccessor::GetCreature(*me, _dmitriGUID))
                        dmitri->DespawnOrUnsummon();
                    if (Creature* jess = ObjectAccessor::GetCreature(*me, _jessGUID))
                        jess->DespawnOrUnsummon();
                    if (Creature* daniel = ObjectAccessor::GetCreature(*me, _danielGUID))
                        daniel->DespawnOrUnsummon();
                    if (Creature* oslow = ObjectAccessor::GetCreature(*me, _oslowGUID))
                        oslow->DespawnOrUnsummon();

                    _events.Reset();
                    me->DespawnOrUnsummon();
                    break;
                }
                default:
                    break;
            }
        }
    }

    void DoAction(int32 const param) override
    {
        switch (param)
        {
            case ACTION_OSLOW_GET_UP:
                _events.ScheduleEvent(EVENT_OSLOW_GET_UP, 500ms);

                // in case player who started event disconnects
                _events.ScheduleEvent(EVENT_DONE, 120s);
                break;
            case ACTION_COWER:
                _events.ScheduleEvent(EVENT_BRIDGE_WORKERS_COWER, 3s);
                break;
            case ACTION_DONE:
                _events.ScheduleEvent(EVENT_DONE, 0s);
                break;
            default:
                break;
        }
    }

private:
    EventMap _events;
    ObjectGuid _oslowGUID;
    ObjectGuid _alexGUID;
    ObjectGuid _trentGUID;
    ObjectGuid _dmitriGUID;
    ObjectGuid _jessGUID;
    ObjectGuid _danielGUID;
    ObjectGuid _matthewGUID;
};

constexpr Position EttinNearBoulderPosition = { -9272.053f, -2291.7463f, 68.54081f };

// 43197 - Subdued Canyon Ettin
struct npc_redridge_subdued_canyon_ettin : public CreatureAI
{
    npc_redridge_subdued_canyon_ettin(Creature* creature) : CreatureAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        _events.Reset();
    }

    void OnDespawn() override
    {
        Unit* owner = me->GetOwner();
        if (!owner)
            return;

        owner->RemoveAurasDueToSpell(SPELL_CANYON_ETTIN_SPAWN_SPELL);
    }

    void SpellHit(WorldObject* caster, SpellInfo const* spell) override
    {
        if (!caster || !caster->IsPlayer())
            return;

        switch (spell->Id)
        {
            case SPELL_BOULDER_AURA:
                me->GetMotionMaster()->MovePoint(POINT_NEAR_BOULDER, EttinNearBoulderPosition, true, {}, {}, MovementWalkRunSpeedSelectionMode::ForceWalk);
                break;
            case SPELL_DESPAWN_KILL_CREDIT:
                if (Player* player = ObjectAccessor::GetPlayer(*me, caster->GetGUID()))
                    player->RewardPlayerAndGroupAtEvent(NPC_FOREMAN_OSLOW, player);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ETTIN_LINE_1:
                    Talk(TALK_NOT_SO_HEAVY);
                    _events.ScheduleEvent(EVENT_ETTIN_LINE_2, 3s);
                    break;
                case EVENT_ETTIN_LINE_2:
                    Talk(TALK_WHERE_THROW);

                    if (Creature* boulder = ObjectAccessor::GetCreature(*me, _boulderGUID))
                        boulder->AI()->DoAction(ACTION_COWER);

                    _events.ScheduleEvent(EVENT_MOVE_TO_WATER, 9s);
                    break;
                case EVENT_MOVE_TO_WATER:
                    me->GetMotionMaster()->MovePath(PATH_ETTIN_TO_WATER, false);
                    Talk(TALK_THROW_IN_WATER);
                    break;
                case EVENT_THROW_BOULDER:
                    me->CastSpell(nullptr, SPELL_EJECT_PASSENGER_1);
                    _events.ScheduleEvent(EVENT_PATH_AWAY, 6s);
                    break;
                case EVENT_PATH_AWAY:
                    Talk(TALK_BYE);

                    if (Creature* boulder = ObjectAccessor::GetCreature(*me, _boulderGUID))
                        boulder->AI()->DoAction(ACTION_DONE);

                    me->GetMotionMaster()->MovePath(PATH_ETTIN_UP_HILL, false);
                    break;
                default:
                    break;
            }
        }
    }

    void MovementInform(uint32 movementType, uint32 pointId) override
    {
        if (movementType != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_NEAR_BOULDER)
        {
            if (Creature const* boulder = me->FindNearestCreature(NPC_HUGE_BOULDER, 5.0f, true))
            {
                _boulderGUID = boulder->GetGUID();
                me->CastSpell(nullptr, SPELL_LIFT_HUGE_BOULDER, false);

                if (Creature const* daniel = me->FindNearestCreature(NPC_BRIDGE_WORKER_DANIEL, 20.0f, true))
                    me->SetFacingToObject(daniel);

                _events.ScheduleEvent(EVENT_ETTIN_LINE_1, 2500ms);
                boulder->AI()->DoAction(ACTION_OSLOW_GET_UP);
            }
        }
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == PATH_ETTIN_TO_WATER)
        {
            _events.ScheduleEvent(EVENT_THROW_BOULDER, 0s);
        }
        else if (pathId == PATH_ETTIN_UP_HILL)
        {
            me->CastSpell(nullptr, SPELL_CANYON_ETTIN_DESPAWN);
            me->CastSpell(nullptr, SPELL_DESPAWN_ETTIN);
        }
    }

private:
    EventMap _events;
    ObjectGuid _boulderGUID;
};

// 80704 - Control Ettin
class spell_redridge_control_ettin : public SpellScript
{
    SpellCastResult CheckCast()
    {
        // check for a spawn spell with a valid caster (subdued ettin)
        Aura const* spawnAura = GetCaster()->GetAura(SPELL_CANYON_ETTIN_SPAWN_SPELL, [](Aura const* aura)
        {
            return aura->GetCaster() != nullptr;
        });

        if (spawnAura != nullptr)
        {
            // fail if the subdued ettin is no longer alive
            if (!spawnAura->GetCaster()->IsAlive())
                return SPELL_FAILED_BAD_IMPLICIT_TARGETS;
        }
        else
        {
            // no spawn spell, so require nearby canyon ettin
            if (!GetCaster()->FindNearestCreature(NPC_CANYON_ETTIN, GetSpellInfo()->GetMaxRange(), true))
                return SPELL_FAILED_OUT_OF_RANGE;
        }

        return SPELL_CAST_OK;
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/) const
    {
        if (Unit const* target = GetHitUnit())
        {
            // conditions ensure this ettin is owned by player
            if (target->GetEntry() == NPC_SUBDUED_CANYON_ETTIN)
            {
                GetCaster()->CastSpell(nullptr, SPELL_BOULDER_AURA, false);
                GetCaster()->CastSpell(nullptr, SPELL_DESPAWN_KILL_CREDIT, false);
            }
            else
                GetCaster()->CastSpell(nullptr, SPELL_CONTROL_ETTIN_2, false);
        }
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_redridge_control_ettin::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_redridge_control_ettin::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 80702 - Control Ettin
class spell_redridge_control_ettin_2 : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/) const
    {
        if (Creature* target = GetHitCreature())
            target->DespawnOrUnsummon();

        // subdued ettin minion casts 82558 to player
        std::list<TempSummon*> minionList;
        GetCaster()->GetAllMinionsByEntry(minionList, NPC_SUBDUED_CANYON_ETTIN);
        if (TempSummon* ettin = minionList.front())
            ettin->CastSpell(GetCaster(), SPELL_CANYON_ETTIN_SPAWN_SPELL, false);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_redridge_control_ettin_2::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
# npc_redridge_citizen "Used by entries 43222 and 43247"
######*/

enum RedridgeCitizen
{
    EVENT_DETERMINE_EVENT           = 7,     // Determine where npc is located by aura
    EVENT_PLAYEMOTE                 = 8,     // Used by npc's in Lakeshire Inn
    EVENT_SAY_TEXT                  = 9,     // Used by npc's in Lakeshire Townhall
    EVENT_LEAVE_TOWNHALL            = 10,    // Used by npc's in Lakeshire Townhall

    SAY_IN_TOWNHALL                 = 0,     // Used by npc's in Lakeshire Townhall
    SAY_LEAVE_TOWNHALL              = 1,     // Used by npc's in Lakeshire Townhall
};

const Emote EmoteID[6] =
{
    EMOTE_ONESHOT_CHEER,
    EMOTE_ONESHOT_ROAR,
    EMOTE_ONESHOT_SHOUT,
    EMOTE_ONESHOT_POINT,
    EMOTE_ONESHOT_BATTLE_ROAR,
    EMOTE_ONESHOT_NO
};

WaypointPath const TownhallPath =
{
    8,
    {
        { 0, -9221.39f, -2198.45f, 66.34846f },
        { 1, -9221.39f, -2198.45f, 66.34846f },
        { 2, -9226.39f, -2196.45f, 66.34846f },
        { 3, -9231.64f, -2196.45f, 65.34846f },
        { 4, -9231.39f, -2205.45f, 66.34846f },
        { 5, -9231.64f, -2210.45f, 66.34846f },
        { 6, -9244.14f, -2211.20f, 66.34846f },
        { 7, -9255.31f, -2211.62f, 63.93340f }
    },
    WaypointMoveType::Walk
};

class npc_redridge_citizen : public CreatureScript
{
public:
    npc_redridge_citizen() : CreatureScript("npc_redridge_citizen") { }

    struct npc_redridge_citizenAI : public ScriptedAI
    {
        npc_redridge_citizenAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _events.Reset();
            _events.ScheduleEvent(EVENT_DETERMINE_EVENT, Seconds(2));
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            if (!UpdateVictim())
            {
                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_DETERMINE_EVENT: // Determine where npc is located
                        if (me->HasAura(SPELL_APPLY_QUEST_INVIS_ZONE_3) || me->HasAura(SPELL_APPLY_QUEST_INVIS_ZONE_4))  // Lakeshire Inn
                            _events.ScheduleEvent(EVENT_PLAYEMOTE, Seconds(5), Seconds(15));
                        else if (me->HasAura(SPELL_APPLY_QUEST_INVIS_ZONE_19)) // Lakeshire Townhall
                            _events.ScheduleEvent(EVENT_SAY_TEXT, Seconds(5), Seconds(30));
                        break;
                    case EVENT_PLAYEMOTE:
                        me->HandleEmoteCommand(EmoteID[urand(0, 5)]);
                        _events.ScheduleEvent(EVENT_PLAYEMOTE, Seconds(10), Seconds(25));
                        break;
                    case EVENT_SAY_TEXT:
                        if (roll_chance_i(3))
                        {
                            Talk(SAY_LEAVE_TOWNHALL);
                            _events.ScheduleEvent(EVENT_LEAVE_TOWNHALL, Seconds(2));
                            break;
                        }
                        if (roll_chance_i(30))
                            Talk(SAY_IN_TOWNHALL);
                        _events.Repeat(Seconds(30), Seconds(60));
                        break;
                    case EVENT_LEAVE_TOWNHALL:
                        me->GetMotionMaster()->MovePath(TownhallPath, false);
                        me->DespawnOrUnsummon(Seconds(30), Seconds(60));
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    private:
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_redridge_citizenAI(creature);
    }
};

void AddSC_redridge_mountains()
{
    new npc_big_earl();
    new npc_dumpy_and_keeshan();
    RegisterCreatureAI(npc_redridge_huge_boulder);
    RegisterCreatureAI(npc_redridge_subdued_canyon_ettin);
    RegisterSpellScript(spell_redridge_control_ettin);
    RegisterSpellScript(spell_redridge_control_ettin_2);
    new npc_redridge_citizen();
}
