/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "SmartAI.h"
#include "Creature.h"
#include "CreatureGroups.h"
#include "DBCStructure.h"
#include "GameObject.h"
#include "Group.h"
#include "Log.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PetDefines.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Vehicle.h"

SmartAI::SmartAI(Creature* creature) : CreatureAI(creature), mIsCharmed(false), mFollowCreditType(0), mFollowArrivedTimer(0), mFollowCredit(0), mFollowArrivedEntry(0), mFollowDist(0.f), mFollowAngle(0.f),
    _escortState(SMART_ESCORT_NONE), _escortNPCFlags(0), _escortInvokerCheckTimer(1000), _currentWaypointNode(0), _waypointReached(false), _waypointPauseTimer(0), _waypointPauseForced(false), _repeatWaypointPath(false),
    _OOCReached(false), _waypointPathEnded(false), mRun(true), mEvadeDisabled(false), mCanAutoAttack(true), mCanCombatMove(true), mInvincibilityHpLevel(0), mDespawnTime(0), mDespawnState(0), mConditionsTimer(0),
    _gossipReturn(false), mEscortQuestID(0)
{
    mHasConditions = sConditionMgr->HasConditionsForNotGroupedEntry(CONDITION_SOURCE_TYPE_CREATURE_TEMPLATE_VEHICLE, creature->GetEntry());
}

bool SmartAI::IsAIControlled() const
{
    return !mIsCharmed;
}

void SmartAI::StartPath(bool run/* = false*/, uint32 pathId/* = 0*/, bool repeat/* = false*/, Unit* invoker/* = nullptr*/, uint32 nodeId/* = 1*/)
{
    if (me->IsInCombat()) // no wp movement in combat
    {
        TC_LOG_ERROR("misc", "SmartAI::StartPath: Creature entry %u wanted to start waypoint movement (%u) while in combat, ignoring.", me->GetEntry(), pathId);
        return;
    }

    if (HasEscortState(SMART_ESCORT_ESCORTING))
        StopPath();

    SetRun(run);

    if (pathId)
    {
        if (!LoadPath(pathId))
            return;
    }

    if (_path.nodes.empty())
        return;

    _currentWaypointNode = nodeId;
    _waypointPathEnded = false;

    _repeatWaypointPath = repeat;

    // Do not use AddEscortState, removing everything from previous
    _escortState = SMART_ESCORT_ESCORTING;

    if (invoker && invoker->GetTypeId() == TYPEID_PLAYER)
    {
        _escortNPCFlags = me->GetUInt32Value(UNIT_NPC_FLAGS);
        me->SetFlag(UNIT_NPC_FLAGS, 0);
    }

    GetScript()->ProcessEventsFor(SMART_EVENT_WAYPOINT_START, nullptr, _currentWaypointNode, GetScript()->GetPathId());

    me->GetMotionMaster()->MovePath(_path, _repeatWaypointPath);
}

bool SmartAI::LoadPath(uint32 entry)
{
    if (HasEscortState(SMART_ESCORT_ESCORTING))
        return false;

    WaypointPath const* path = sSmartWaypointMgr->GetPath(entry);
    if (!path || path->nodes.empty())
    {
        GetScript()->SetPathId(0);
        return false;
    }

    _path.id = path->id;
    _path.nodes = path->nodes;
    for (WaypointNode& waypoint : _path.nodes)
    {
        Trinity::NormalizeMapCoord(waypoint.x);
        Trinity::NormalizeMapCoord(waypoint.y);
        waypoint.moveType = mRun ? WAYPOINT_MOVE_TYPE_RUN : WAYPOINT_MOVE_TYPE_WALK;
    }

    GetScript()->SetPathId(entry);
    return true;
}

void SmartAI::PausePath(uint32 delay, bool forced)
{
    if (!HasEscortState(SMART_ESCORT_ESCORTING))
    {
        me->PauseMovement(delay, MOTION_SLOT_DEFAULT, forced);
        if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == WAYPOINT_MOTION_TYPE)
        {
            std::pair<uint32, uint32> waypointInfo = me->GetCurrentWaypointInfo();
            GetScript()->ProcessEventsFor(SMART_EVENT_WAYPOINT_PAUSED, nullptr, waypointInfo.first, waypointInfo.second);
        }
        return;
    }

    if (HasEscortState(SMART_ESCORT_PAUSED))
    {
        TC_LOG_ERROR("misc", "SmartAI::PausePath: Creature entry %u wanted to pause waypoint (current waypoint: %u) movement while already paused, ignoring.", me->GetEntry(), _currentWaypointNode);
        return;
    }

    _waypointPauseTimer = delay;

    if (forced)
    {
        _waypointPauseForced = forced;
        SetRun(mRun);
        me->PauseMovement();
        me->SetHomePosition(me->GetPosition());
    }
    else
        _waypointReached = false;

    AddEscortState(SMART_ESCORT_PAUSED);
    GetScript()->ProcessEventsFor(SMART_EVENT_WAYPOINT_PAUSED, nullptr, _currentWaypointNode, GetScript()->GetPathId());
}

void SmartAI::StopPath(uint32 DespawnTime, uint32 quest, bool fail)
{
    if (!HasEscortState(SMART_ESCORT_ESCORTING))
    {
        std::pair<uint32, uint32> waypointInfo = { 0, 0 };
        if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == WAYPOINT_MOTION_TYPE)
            waypointInfo = me->GetCurrentWaypointInfo();

        if (mDespawnState != 2)
            SetDespawnTime(DespawnTime);

        me->GetMotionMaster()->MoveIdle();

        if (waypointInfo.first)
            GetScript()->ProcessEventsFor(SMART_EVENT_WAYPOINT_STOPPED, nullptr, waypointInfo.first, waypointInfo.second);

        if (!fail)
        {
            if (waypointInfo.first)
                GetScript()->ProcessEventsFor(SMART_EVENT_WAYPOINT_ENDED, nullptr, waypointInfo.first, waypointInfo.second);
            if (mDespawnState == 1)
                StartDespawn();
        }
        return;
    }

    if (quest)
        mEscortQuestID = quest;

    if (mDespawnState != 2)
        SetDespawnTime(DespawnTime);

    me->GetMotionMaster()->MoveIdle();

    GetScript()->ProcessEventsFor(SMART_EVENT_WAYPOINT_STOPPED, nullptr, _currentWaypointNode, GetScript()->GetPathId());

    EndPath(fail);
}

void SmartAI::EndPath(bool fail)
{
    RemoveEscortState(SMART_ESCORT_ESCORTING | SMART_ESCORT_PAUSED | SMART_ESCORT_RETURNING);
    _path.nodes.clear();
    _waypointPauseTimer = 0;

    if (_escortNPCFlags)
    {
        me->SetFlag(UNIT_NPC_FLAGS, _escortNPCFlags);
        _escortNPCFlags = 0;
    }

    ObjectVector const* targets = GetScript()->GetStoredTargetVector(SMART_ESCORT_TARGETS, *me);
    if (targets && mEscortQuestID)
    {
        if (targets->size() == 1 && GetScript()->IsPlayer((*targets->begin())))
        {
            Player* player = targets->front()->ToPlayer();
            if (!fail && player->IsAtGroupRewardDistance(me) && !player->HasCorpse())
                player->GroupEventHappens(mEscortQuestID, me);

            if (fail)
                player->FailQuest(mEscortQuestID);

            if (Group* group = player->GetGroup())
            {
                for (GroupReference* groupRef = group->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* groupGuy = groupRef->GetSource();
                    if (!groupGuy->IsInMap(player))
                        continue;

                    if (!fail && groupGuy->IsAtGroupRewardDistance(me) && !groupGuy->HasCorpse())
                        groupGuy->AreaExploredOrEventHappens(mEscortQuestID);
                    else if (fail)
                        groupGuy->FailQuest(mEscortQuestID);
                }
            }
        }
        else
        {
            for (WorldObject* target : *targets)
            {
                if (GetScript()->IsPlayer(target))
                {
                    Player* player = target->ToPlayer();
                    if (!fail && player->IsAtGroupRewardDistance(me) && !player->HasCorpse())
                        player->AreaExploredOrEventHappens(mEscortQuestID);
                    else if (fail)
                        player->FailQuest(mEscortQuestID);
                }
            }
        }
    }

    // End Path events should be only processed if it was SUCCESSFUL stop or stop called by SMART_ACTION_WAYPOINT_STOP
    if (fail)
        return;

    GetScript()->ProcessEventsFor(SMART_EVENT_WAYPOINT_ENDED, nullptr, _currentWaypointNode, GetScript()->GetPathId());

    if (_repeatWaypointPath)
    {
        if (IsAIControlled())
            StartPath(mRun, GetScript()->GetPathId(), _repeatWaypointPath);
    }
    else
        GetScript()->SetPathId(0);

    if (mDespawnState == 1)
        StartDespawn();
}

void SmartAI::ResumePath()
{
    GetScript()->ProcessEventsFor(SMART_EVENT_WAYPOINT_RESUMED, nullptr, _currentWaypointNode, GetScript()->GetPathId());

    RemoveEscortState(SMART_ESCORT_PAUSED);

    _waypointPauseForced = false;
    _waypointReached = false;
    _waypointPauseTimer = 0;

    SetRun(mRun);
    me->ResumeMovement();
}

void SmartAI::ReturnToLastOOCPos()
{
    if (!IsAIControlled())
        return;

    me->SetWalk(false);
    me->GetMotionMaster()->MovePoint(SMART_ESCORT_LAST_OOC_POINT, me->GetHomePosition());
}

void SmartAI::UpdateAI(uint32 diff)
{
    CheckConditions(diff);

    GetScript()->OnUpdate(diff);

    UpdatePath(diff);
    UpdateFollow(diff);
    UpdateDespawn(diff);

    if (!IsAIControlled())
        return;

    if (!UpdateVictim())
        return;

    if (mCanAutoAttack)
        DoMeleeAttackIfReady();
}

bool SmartAI::IsEscortInvokerInRange()
{
    if (ObjectVector const* targets = GetScript()->GetStoredTargetVector(SMART_ESCORT_TARGETS, *me))
    {
        float checkDist = me->GetInstanceScript() ? SMART_ESCORT_MAX_PLAYER_DIST * 2 : SMART_ESCORT_MAX_PLAYER_DIST;
        if (targets->size() == 1 && GetScript()->IsPlayer((*targets->begin())))
        {
            Player* player = (*targets->begin())->ToPlayer();
            if (me->GetDistance(player) <= checkDist)
                return true;

            if (Group* group = player->GetGroup())
            {
                for (GroupReference* groupRef = group->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* groupGuy = groupRef->GetSource();
                    if (groupGuy->IsInMap(player) && me->GetDistance(groupGuy) <= checkDist)
                        return true;
                }
            }
        }
        else
        {
            for (WorldObject* target : *targets)
            {
                if (GetScript()->IsPlayer(target))
                {
                    if (me->GetDistance(target->ToPlayer()) <= checkDist)
                        return true;
                }
            }
        }

        // no valid target found
        return false;
    }

    // no player invoker was stored, just ignore range check
    return true;
}

///@todo move escort related logic
void SmartAI::WaypointPathStarted(uint32 pathId)
{
    if (!HasEscortState(SMART_ESCORT_ESCORTING))
    {
        // @todo remove the constant 1 at some point, it's never anything different
        GetScript()->ProcessEventsFor(SMART_EVENT_WAYPOINT_START, nullptr, 1, pathId);
        return;
    }
}

///@todo Implement new smart event SMART_EVENT_WAYPOINT_STARTED
void SmartAI::WaypointStarted(uint32 /*nodeId*/, uint32 /*pathId*/)
{
}

void SmartAI::WaypointReached(uint32 nodeId, uint32 pathId)
{
    if (!HasEscortState(SMART_ESCORT_ESCORTING))
    {
        GetScript()->ProcessEventsFor(SMART_EVENT_WAYPOINT_REACHED, nullptr, nodeId, pathId);
        return;
    }

    _currentWaypointNode = nodeId;

    GetScript()->ProcessEventsFor(SMART_EVENT_WAYPOINT_REACHED, nullptr, _currentWaypointNode, pathId);

    if (_waypointPauseTimer && !_waypointPauseForced)
    {
        _waypointReached = true;
        me->PauseMovement();
        me->SetHomePosition(me->GetPosition());
    }
    else if (HasEscortState(SMART_ESCORT_ESCORTING) && me->GetMotionMaster()->GetCurrentMovementGeneratorType() == WAYPOINT_MOTION_TYPE)
    {
        if (_currentWaypointNode == _path.nodes.size())
            _waypointPathEnded = true;
        else
            SetRun(mRun);
    }
}

///@todo move escort related logic
void SmartAI::WaypointPathEnded(uint32 nodeId, uint32 pathId)
{
    if (!HasEscortState(SMART_ESCORT_ESCORTING))
    {
        GetScript()->ProcessEventsFor(SMART_EVENT_WAYPOINT_ENDED, nullptr, nodeId, pathId);
        return;
    }
}

void SmartAI::MovementInform(uint32 type, uint32 id)
{
    if (type == POINT_MOTION_TYPE && id == SMART_ESCORT_LAST_OOC_POINT)
        me->ClearUnitState(UNIT_STATE_EVADE);

    GetScript()->ProcessEventsFor(SMART_EVENT_MOVEMENTINFORM, nullptr, type, id);

    if (!HasEscortState(SMART_ESCORT_ESCORTING))
        return;

    if (type == POINT_MOTION_TYPE && id == SMART_ESCORT_LAST_OOC_POINT)
        _OOCReached = true;
}

void SmartAI::EnterEvadeMode(EvadeReason /*why*/)
{
    if (mEvadeDisabled)
    {
        GetScript()->ProcessEventsFor(SMART_EVENT_EVADE);
        return;
    }

    if (!IsAIControlled())
    {
        me->AttackStop();
        return;
    }

    if (!_EnterEvadeMode())
        return;

    me->AddUnitState(UNIT_STATE_EVADE);

    GetScript()->ProcessEventsFor(SMART_EVENT_EVADE); // must be after _EnterEvadeMode (spells, auras, ...)

    SetRun(mRun);

    if (Unit* owner = me->GetCharmerOrOwner())
    {
        me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
        me->ClearUnitState(UNIT_STATE_EVADE);
    }
    else if (HasEscortState(SMART_ESCORT_ESCORTING))
    {
        AddEscortState(SMART_ESCORT_RETURNING);
        ReturnToLastOOCPos();
    }
    else if (Unit* target = mFollowGuid ? ObjectAccessor::GetUnit(*me, mFollowGuid) : nullptr)
    {
        me->GetMotionMaster()->MoveFollow(target, mFollowDist, mFollowAngle);
        // evade is not cleared in MoveFollow, so we can't keep it
        me->ClearUnitState(UNIT_STATE_EVADE);
    }
    else
        me->GetMotionMaster()->MoveTargetedHome();

    if (!me->HasUnitState(UNIT_STATE_EVADE))
        GetScript()->OnReset();
}

void SmartAI::MoveInLineOfSight(Unit* who)
{
    if (!who)
        return;

    GetScript()->OnMoveInLineOfSight(who);

    if (!IsAIControlled())
        return;

    if (HasEscortState(SMART_ESCORT_ESCORTING) && AssistPlayerInCombatAgainst(who))
        return;

    CreatureAI::MoveInLineOfSight(who);
}

bool SmartAI::AssistPlayerInCombatAgainst(Unit* who)
{
    if (me->HasReactState(REACT_PASSIVE) || !IsAIControlled())
        return false;

    if (!who || !who->GetVictim())
        return false;

    // experimental (unknown) flag not present
    if (!(me->GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_CAN_ASSIST))
        return false;

    // not a player
    if (!who->EnsureVictim()->GetCharmerOrOwnerPlayerOrPlayerItself())
        return false;

    if (!who->isInAccessiblePlaceFor(me))
        return false;

    if (!CanAIAttack(who))
        return false;

    // we cannot attack in evade mode
    if (me->IsInEvadeMode())
        return false;

    // or if enemy is in evade mode
    if (who->GetTypeId() == TYPEID_UNIT && who->ToCreature()->IsInEvadeMode())
        return false;

    if (!me->IsValidAssistTarget(who->GetVictim()))
        return false;

    // too far away and no free sight
    if (me->IsWithinDistInMap(who, SMART_MAX_AID_DIST) && me->IsWithinLOSInMap(who))
    {
        me->EngageWithTarget(who);
        return true;
    }

    return false;
}

void SmartAI::InitializeAI()
{
    GetScript()->OnInitialize(me);

    mDespawnTime = 0;
    mDespawnState = 0;
    _escortState = SMART_ESCORT_NONE;

    me->SetVisible(true);

    if (!me->isDead())
    {
        GetScript()->ProcessEventsFor(SMART_EVENT_RESPAWN);
        GetScript()->OnReset();
    }

    mFollowGuid.Clear(); // do not reset follower on Reset(), we need it after combat evade
    mFollowDist = 0;
    mFollowAngle = 0;
    mFollowCredit = 0;
    mFollowArrivedTimer = 1000;
    mFollowArrivedEntry = 0;
    mFollowCreditType = 0;
}

void SmartAI::JustReachedHome()
{
    GetScript()->OnReset();
    GetScript()->ProcessEventsFor(SMART_EVENT_REACHED_HOME);

    CreatureGroup* formation = me->GetFormation();
    if (!formation || formation->GetLeader() == me || !formation->IsFormed())
    {
        if (me->GetMotionMaster()->GetCurrentMovementGeneratorType(MOTION_SLOT_DEFAULT) != WAYPOINT_MOTION_TYPE)
        {
            if (me->GetWaypointPath())
                me->GetMotionMaster()->MovePath(me->GetWaypointPath(), true);
        }
        else
            me->ResumeMovement();
    }
    else if (formation->IsFormed())
        me->GetMotionMaster()->MoveIdle(); // wait the order of leader
}

void SmartAI::JustEngagedWith(Unit* enemy)
{
    if (IsAIControlled())
        me->InterruptNonMeleeSpells(false); // must be before ProcessEvents

    GetScript()->ProcessEventsFor(SMART_EVENT_AGGRO, enemy);
}

void SmartAI::JustDied(Unit* killer)
{
    if (HasEscortState(SMART_ESCORT_ESCORTING))
        EndPath(true);

    GetScript()->ProcessEventsFor(SMART_EVENT_DEATH, killer);
}

void SmartAI::KilledUnit(Unit* victim)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_KILL, victim);
}

void SmartAI::JustSummoned(Creature* creature)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_SUMMONED_UNIT, creature);
}

void SmartAI::AttackStart(Unit* who)
{
    // dont allow charmed npcs to act on their own
    if (!IsAIControlled())
    {
        if (who)
            me->Attack(who, mCanAutoAttack);
        return;
    }

    if (who && me->Attack(who, mCanAutoAttack))
    {
        me->GetMotionMaster()->Clear(MOTION_PRIORITY_NORMAL);
        me->PauseMovement();

        if (mCanCombatMove)
        {
            SetRun(mRun);
            me->GetMotionMaster()->MoveChase(who);
        }
    }
}

void SmartAI::SpellHit(Unit* unit, SpellInfo const* spellInfo)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_SPELLHIT, unit, 0, 0, false, spellInfo);
}

void SmartAI::SpellHitTarget(Unit* target, SpellInfo const* spellInfo)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_SPELLHIT_TARGET, target, 0, 0, false, spellInfo);
}

void SmartAI::DamageTaken(Unit* doneBy, uint32& damage)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_DAMAGED, doneBy, damage);

    if (!IsAIControlled()) // don't allow players to use unkillable units
        return;

    if (mInvincibilityHpLevel && (damage >= me->GetHealth() - mInvincibilityHpLevel))
        damage = me->GetHealth() - mInvincibilityHpLevel; // damage should not be nullified, because of player damage req.
}

void SmartAI::HealReceived(Unit* doneBy, uint32& addhealth)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_RECEIVE_HEAL, doneBy, addhealth);
}

void SmartAI::ReceiveEmote(Player* player, uint32 textEmote)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_RECEIVE_EMOTE, player, textEmote);
}

void SmartAI::IsSummonedBy(Unit* summoner)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_JUST_SUMMONED, summoner);
}

void SmartAI::DamageDealt(Unit* doneTo, uint32& damage, DamageEffectType /*damagetype*/)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_DAMAGED_TARGET, doneTo, damage);
}

void SmartAI::SummonedCreatureDespawn(Creature* unit)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_SUMMON_DESPAWNED, unit);
}

void SmartAI::CorpseRemoved(uint32& respawnDelay)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_CORPSE_REMOVED, nullptr, respawnDelay);
}

void SmartAI::PassengerBoarded(Unit* who, int8 seatId, bool apply)
{
    GetScript()->ProcessEventsFor(apply ? SMART_EVENT_PASSENGER_BOARDED : SMART_EVENT_PASSENGER_REMOVED, who, uint32(seatId), 0, apply);
}

void SmartAI::OnCharmed(bool apply)
{
    if (apply) // do this before we change charmed state, as charmed state might prevent these things from processing
    {
        if (HasEscortState(SMART_ESCORT_ESCORTING | SMART_ESCORT_PAUSED | SMART_ESCORT_RETURNING))
            EndPath(true);
    }

    mIsCharmed = apply;

    if (!apply && !me->IsInEvadeMode())
    {
        if (_repeatWaypointPath)
            StartPath(mRun, GetScript()->GetPathId(), true);
        else
            me->SetWalk(!mRun);

        if (Unit* charmer = me->GetCharmer())
            AttackStart(charmer);
    }

    GetScript()->ProcessEventsFor(SMART_EVENT_CHARMED, nullptr, 0, 0, apply);
}

void SmartAI::DoAction(int32 param)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_ACTION_DONE, nullptr, param);
}

uint32 SmartAI::GetData(uint32 /*id*/) const
{
    return 0;
}

void SmartAI::SetData(uint32 id, uint32 value, Unit* invoker)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_DATA_SET, invoker, id, value);
}

void SmartAI::SetGUID(ObjectGuid const& /*guid*/, int32 /*id*/) { }

ObjectGuid SmartAI::GetGUID(int32 /*id*/) const
{
    return ObjectGuid::Empty;
}

void SmartAI::SetRun(bool run)
{
    if (run == mRun)
        return;

    me->SetWalk(!run);
    mRun = run;
    for (auto& node : _path.nodes)
        node.moveType = run ? WAYPOINT_MOVE_TYPE_RUN : WAYPOINT_MOVE_TYPE_WALK;
}

void SmartAI::SetDisableGravity(bool fly)
{
    me->SetDisableGravity(fly);
}

void SmartAI::SetCanFly(bool fly)
{
    me->SetCanFly(fly);
}

void SmartAI::SetSwim(bool swim)
{
    me->SetSwim(swim);
}

void SmartAI::SetEvadeDisabled(bool disable)
{
    mEvadeDisabled = disable;
}

bool SmartAI::GossipHello(Player* player)
{
    _gossipReturn = false;
    GetScript()->ProcessEventsFor(SMART_EVENT_GOSSIP_HELLO, player);
    return _gossipReturn;
}

bool SmartAI::GossipSelect(Player* player, uint32 menuId, uint32 gossipListId)
{
    _gossipReturn = false;
    GetScript()->ProcessEventsFor(SMART_EVENT_GOSSIP_SELECT, player, menuId, gossipListId);
    return _gossipReturn;
}

bool SmartAI::GossipSelectCode(Player* /*player*/, uint32 /*menuId*/, uint32 /*gossipListId*/, char const* /*code*/)
{
    return false;
}

void SmartAI::QuestAccept(Player* player, Quest const* quest)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_ACCEPTED_QUEST, player, quest->GetQuestId());
}

void SmartAI::QuestReward(Player* player, Quest const* quest, uint32 opt)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_REWARD_QUEST, player, quest->GetQuestId(), opt);
}

void SmartAI::SetCombatMove(bool on)
{
    if (mCanCombatMove == on)
        return;

    mCanCombatMove = on;

    if (!IsAIControlled())
        return;

    if (me->IsEngaged())
    {
        if (on)
        {
            if (!me->HasReactState(REACT_PASSIVE) && me->GetVictim() && !me->GetMotionMaster()->HasMovementGenerator([](MovementGenerator const* movement) -> bool
            {
                return movement->Mode == MOTION_MODE_DEFAULT && movement->Priority == MOTION_PRIORITY_NORMAL;
            }))
            {
                SetRun(mRun);
                me->GetMotionMaster()->MoveChase(me->GetVictim());
            }
        }
        else if (MovementGenerator* movement = me->GetMotionMaster()->GetMovementGenerator([](MovementGenerator const* a) -> bool
        {
            return a->GetMovementGeneratorType() == CHASE_MOTION_TYPE && a->Mode == MOTION_MODE_DEFAULT && a->Priority == MOTION_PRIORITY_NORMAL;
        }))
            me->GetMotionMaster()->Remove(movement);
    }
}

void SmartAI::SetFollow(Unit* target, float dist, float angle, uint32 credit, uint32 end, uint32 creditType)
{
    if (!target)
    {
        StopFollow(false);
        return;
    }

    mFollowGuid = target->GetGUID();
    mFollowDist = dist;
    mFollowAngle = angle;
    mFollowArrivedTimer = 1000;
    mFollowCredit = credit;
    mFollowArrivedEntry = end;
    mFollowCreditType = creditType;
    SetRun(mRun);
    me->GetMotionMaster()->MoveFollow(target, mFollowDist, mFollowAngle);
}

void SmartAI::StopFollow(bool complete)
{
    mFollowGuid.Clear();
    mFollowDist = 0;
    mFollowAngle = 0;
    mFollowCredit = 0;
    mFollowArrivedTimer = 1000;
    mFollowArrivedEntry = 0;
    mFollowCreditType = 0;
    me->GetMotionMaster()->MoveIdle();

    if (!complete)
        return;

    Player* player = ObjectAccessor::GetPlayer(*me, mFollowGuid);
    if (player)
    {
        if (!mFollowCreditType)
            player->RewardPlayerAndGroupAtEvent(mFollowCredit, me);
        else
            player->GroupEventHappens(mFollowCredit, me);
    }

    SetDespawnTime(5000);
    StartDespawn();
    GetScript()->ProcessEventsFor(SMART_EVENT_FOLLOW_COMPLETED, player);
}

void SmartAI::SetTimedActionList(SmartScriptHolder& e, uint32 entry, Unit* invoker)
{
    GetScript()->SetTimedActionList(e, entry, invoker);
}

void SmartAI::OnGameEvent(bool start, uint16 eventId)
{
    GetScript()->ProcessEventsFor(start ? SMART_EVENT_GAME_EVENT_START : SMART_EVENT_GAME_EVENT_END, nullptr, eventId);
}

void SmartAI::OnSpellClick(Unit* clicker, bool spellClickHandled)
{
    if (!spellClickHandled)
        return;

    GetScript()->ProcessEventsFor(SMART_EVENT_ON_SPELLCLICK, clicker);
}

void SmartAI::CheckConditions(uint32 diff)
{
    if (!mHasConditions)
        return;

    if (mConditionsTimer <= diff)
    {
        if (Vehicle* vehicleKit = me->GetVehicleKit())
        {
            for (SeatMap::iterator itr = vehicleKit->Seats.begin(); itr != vehicleKit->Seats.end(); ++itr)
                if (Unit* passenger = ObjectAccessor::GetUnit(*me, itr->second.Passenger.Guid))
                {
                    if (Player* player = passenger->ToPlayer())
                    {
                        if (!sConditionMgr->IsObjectMeetingNotGroupedConditions(CONDITION_SOURCE_TYPE_CREATURE_TEMPLATE_VEHICLE, me->GetEntry(), player, me))
                        {
                            player->ExitVehicle();
                            return; // check other pessanger in next tick
                        }
                    }
                }
        }

        mConditionsTimer = 1000;
    }
    else
        mConditionsTimer -= diff;
}

void SmartAI::UpdatePath(uint32 diff)
{
    if (!HasEscortState(SMART_ESCORT_ESCORTING))
        return;

    if (_escortInvokerCheckTimer < diff)
    {
        if (!IsEscortInvokerInRange())
        {
            StopPath(0, mEscortQuestID, true);

            // allow to properly hook out of range despawn action, which in most cases should perform the same operation as dying
            GetScript()->ProcessEventsFor(SMART_EVENT_DEATH, me);
            me->DespawnOrUnsummon();
            return;
        }
        _escortInvokerCheckTimer = 1000;
    }
    else
        _escortInvokerCheckTimer -= diff;

    // handle pause
    if (HasEscortState(SMART_ESCORT_PAUSED) && (_waypointReached || _waypointPauseForced))
    {
        if (_waypointPauseTimer <= diff)
        {
            if (!me->IsInCombat() && !HasEscortState(SMART_ESCORT_RETURNING))
                ResumePath();
        }
        else
            _waypointPauseTimer -= diff;
    }
    else if (_waypointPathEnded) // end path
    {
        _waypointPathEnded = false;
        StopPath();
        return;
    }

    if (HasEscortState(SMART_ESCORT_RETURNING))
    {
        if (_OOCReached) // reached OOC WP
        {
            _OOCReached = false;
            RemoveEscortState(SMART_ESCORT_RETURNING);
            if (!HasEscortState(SMART_ESCORT_PAUSED))
                ResumePath();
        }
    }
}

void SmartAI::UpdateFollow(uint32 diff)
{
    if (mFollowGuid)
    {
        if (mFollowArrivedTimer < diff)
        {
            if (me->FindNearestCreature(mFollowArrivedEntry, INTERACTION_DISTANCE, true))
            {
                StopFollow(true);
                return;
            }

            mFollowArrivedTimer = 1000;
        }
        else
            mFollowArrivedTimer -= diff;
    }
}

void SmartAI::UpdateDespawn(uint32 diff)
{
    if (mDespawnState <= 1 || mDespawnState > 3)
        return;

    if (mDespawnTime < diff)
    {
        if (mDespawnState == 2)
        {
            me->SetVisible(false);
            mDespawnTime = 5000;
            mDespawnState++;
        }
        else
            me->DespawnOrUnsummon();
    }
    else
        mDespawnTime -= diff;
}

void SmartGameObjectAI::UpdateAI(uint32 diff)
{
    GetScript()->OnUpdate(diff);
}

void SmartGameObjectAI::InitializeAI()
{
    GetScript()->OnInitialize(me);
    //Reset();
}

void SmartGameObjectAI::Reset()
{
    GetScript()->OnReset();
}

// Called when a player opens a gossip dialog with the gameobject.
bool SmartGameObjectAI::GossipHello(Player* player)
{
    _gossipReturn = false;
    GetScript()->ProcessEventsFor(SMART_EVENT_GOSSIP_HELLO, player, 0, 0, false, nullptr, me);
    return _gossipReturn;
}

bool SmartGameObjectAI::OnReportUse(Player* player)
{
    _gossipReturn = false;
    GetScript()->ProcessEventsFor(SMART_EVENT_GOSSIP_HELLO, player, 1, 0, false, nullptr, me);
    return _gossipReturn;
}

// Called when a player selects a gossip item in the gameobject's gossip menu.
bool SmartGameObjectAI::GossipSelect(Player* player, uint32 sender, uint32 action)
{
    _gossipReturn = false;
    GetScript()->ProcessEventsFor(SMART_EVENT_GOSSIP_SELECT, player, sender, action, false, nullptr, me);
    return _gossipReturn;
}

// Called when a player selects a gossip with a code in the gameobject's gossip menu.
bool SmartGameObjectAI::GossipSelectCode(Player* /*player*/, uint32 /*menuId*/, uint32 /*gossipListId*/, char const* /*code*/)
{
    return false;
}

// Called when a player accepts a quest from the gameobject.
void SmartGameObjectAI::QuestAccept(Player* player, Quest const* quest)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_ACCEPTED_QUEST, player, quest->GetQuestId(), 0, false, nullptr, me);
}

// Called when a player selects a quest reward.
void SmartGameObjectAI::QuestReward(Player* player, Quest const* quest, uint32 opt)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_REWARD_QUEST, player, quest->GetQuestId(), opt, false, nullptr, me);
}

// Called when the gameobject is destroyed (destructible buildings only).
void SmartGameObjectAI::Destroyed(WorldObject* attacker, uint32 eventId)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_DEATH, attacker ? attacker->ToUnit() : nullptr, eventId, 0, false, nullptr, me);
}

void SmartGameObjectAI::SetData(uint32 id, uint32 value, Unit* invoker)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_DATA_SET, invoker, id, value);
}

void SmartGameObjectAI::SetTimedActionList(SmartScriptHolder& e, uint32 entry, Unit* invoker)
{
    GetScript()->SetTimedActionList(e, entry, invoker);
}

void SmartGameObjectAI::OnGameEvent(bool start, uint16 eventId)
{
    GetScript()->ProcessEventsFor(start ? SMART_EVENT_GAME_EVENT_START : SMART_EVENT_GAME_EVENT_END, nullptr, eventId);
}

void SmartGameObjectAI::OnLootStateChanged(uint32 state, Unit* unit)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_GO_LOOT_STATE_CHANGED, unit, state);
}

void SmartGameObjectAI::EventInform(uint32 eventId)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_GO_EVENT_INFORM, nullptr, eventId);
}

void SmartGameObjectAI::SpellHit(Unit* unit, SpellInfo const* spellInfo)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_SPELLHIT, unit, 0, 0, false, spellInfo);
}

class SmartTrigger : public AreaTriggerScript
{
    public:

        SmartTrigger() : AreaTriggerScript("SmartTrigger") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* trigger) override
        {
            if (!player->IsAlive())
                return false;

            TC_LOG_DEBUG("scripts.ai", "AreaTrigger %u is using SmartTrigger script", trigger->id);
            SmartScript script;
            script.OnInitialize(nullptr, trigger);
            script.ProcessEventsFor(SMART_EVENT_AREATRIGGER_ONTRIGGER, player, trigger->id);
            return true;
        }
};

void AddSC_SmartScripts()
{
    new SmartTrigger();
}
