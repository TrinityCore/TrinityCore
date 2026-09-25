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

#include "AIGroup.h"
#include "AIGroupScript.h"
#include "Containers.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "Random.h"
#include "TemporarySummon.h"
#include "Vehicle.h"
#include "WaypointManager.h"

AIGroupScript::AIGroupScript()
{
    go = nullptr;
    me = nullptr;
}

AIGroupScript::~AIGroupScript()
{
}

void AIGroupScript::OnInitialize(WorldObject* object)
{
    if (object)
    {
        switch (object->GetTypeId())
        {
            case TYPEID_UNIT:
                me = object->ToCreature();
                break;
            case TYPEID_GAMEOBJECT:
                go = object->ToGameObject();
                break;
            default:
                return;
        }
    }
    else
    {
        TC_LOG_ERROR("misc", "AIGroupScript::OnInitialize: Initialized objects are NULL.");
        return;
    }

    // Load copy of script
    GetScript();

    InstallEvents();
}

void AIGroupScript::GetScript()
{
    AIGroupEventList eventList;
    if (me)
    {
        eventList = sAIGroupMgr->GetScript(me->GetCurrentTriggersId());
        FillScript(eventList);
    }
}

void AIGroupScript::InstallEvents()
{
    if (!mInstallEvents.empty())
    {
        for (AIGroupEventList::const_iterator it = mInstallEvents.begin(); it != mInstallEvents.end(); ++it)
            mEvents.push_back(*it);

        mInstallEvents.clear();
    }
}

void AIGroupScript::FillScript(AIGroupEventList eventList)
{
    for (AIGroupEventList::const_iterator it = eventList.begin(); it != eventList.end(); ++it)
    {
        mEvents.push_back(*it);
        RecalcTimer(mEvents.back());
    }
}

void AIGroupScript::MovementInform(uint32 type, uint32 id)
{
    if (mActionSets.empty())
        return;

    if (type == WAYPOINT_MOTION_TYPE)
    {
        auto activeActionSet = std::max_element(mActionSets.begin(), mActionSets.end(), [this](AIGroupActiveActionSet const& left, AIGroupActiveActionSet const& right)
        {
            if (IsActionSetPaused(left))
                return !IsActionSetPaused(right);

            if (IsActionSetPaused(right))
                return false;

            return sAIGroupMgr->GetPriorityPercentForPriorityType(ActionSetPriorityType(sAIGroupMgr->GetActionSetPriority(left.Id))) <
                sAIGroupMgr->GetPriorityPercentForPriorityType(ActionSetPriorityType(sAIGroupMgr->GetActionSetPriority(right.Id)));
        });

        if (IsActionSetPaused(*activeActionSet))
            return;

        if (activeActionSet->CurrentAction >= activeActionSet->Actions.size() || !activeActionSet->ActionStarted)
            return;

        ActionSetEventHolder const& action = activeActionSet->Actions[activeActionSet->CurrentAction];
        if (action.Type != AI_GROUP_FOLLOW_PATH)
            return;

        WaypointPath const* path = sWaypointMgr->GetPath(action.Path);
        if (!path || path->nodes.empty() || id != path->nodes.size() - 1)
            return;

        activeActionSet->ActionTimer = 0;
        activeActionSet->ActionStarted = false;
        ++activeActionSet->CurrentAction;
    }
}

void AIGroupScript::StartActionSet(uint32 actionSetId, ObjectGuid invokerGuid)
{
    if (me && !me->IsAlive() && !(sAIGroupMgr->GetActionSetFlags(actionSetId) & uint32(ActionSetFlags::AllowAllActionsWhileDead)))
        return;

    AIGroupActionSet actionSet = sAIGroupMgr->GetActionSet(actionSetId);
    if (actionSet.empty())
        return;

    mActionSets.erase(std::remove_if(mActionSets.begin(), mActionSets.end(), [actionSetId](AIGroupActiveActionSet const& activeActionSet)
    {
        if (activeActionSet.Id == actionSetId)
            return false;

        return !(sAIGroupMgr->GetActionSetFlags(activeActionSet.Id) & uint32(ActionSetFlags::Resumable));
    }), mActionSets.end());

    for (AIGroupActiveActionSet& activeActionSet : mActionSets)
        if (activeActionSet.Id == actionSetId)
            return;

    mActionSets.emplace_back(actionSetId, std::move(actionSet), invokerGuid);
}

void AIGroupScript::TerminateActionSets()
{
    mActionSets.erase(std::remove_if(mActionSets.begin(), mActionSets.end(), [](AIGroupActiveActionSet const& actionSet)
    {
        return !(sAIGroupMgr->GetActionSetFlags(actionSet.Id) & uint32(ActionSetFlags::AllowAllActionsWhileDead));
    }), mActionSets.end());

    if (me && mActionSets.empty())
        me->currentRunningActionSet = 0;
}

uint32 AIGroupScript::GetActionDuration(ActionSetEventHolder const& action) const
{
    if (action.TimeB > action.TimeA)
        return urand(action.TimeA, action.TimeB);

    return action.TimeA;
}

float AIGroupScript::GetStringIdSearchRadius(ActionSetEventHolder const& action) const
{
    double searchRadius = 0;

    switch (AI_GROUP_ACTION(action.Type))
    {
        case AI_GROUP_TELEPORT:
        case AI_GROUP_WANDER:
        case AI_GROUP_FOLLOW_GUID:
        case AI_GROUP_GUARD_GUID:
        case AI_GROUP_UNIT_CAST:
        case AI_GROUP_UNIT_ACTIVATE_OBJECT:
        case AI_GROUP_UNIT_FACE_GUID:
        case AI_GROUP_MOVETO_GUID:
        case AI_GROUP_ATTACK_GUID:
        case AI_GROUP_UNIT_SEND_LOCAL_EVENT:
        case AI_GROUP_UNIT_BROADCAST_LOCAL_EVENT:
        case AI_GROUP_AVOID:
        case AI_GROUP_AVOID_GUID:
        case AI_GROUP_UNIT_ACTIVATE_OBJECTS:
        case AI_GROUP_UNIT_CALL_FOR_HELP:
        case AI_GROUP_UNIT_COMBAT_TRIGGER:
        case AI_GROUP_TRIGGER_ACTIONS_NEAREST_UNIT_IC:
        case AI_GROUP_UNIT_CAST_FAILURE:
        case AI_GROUP_TRIGGER_ACTIONS_UNITS:
        case AI_GROUP_TRIGGER_ACTIONS_NEAREST_UNIT:
        case AI_GROUP_UNIT_CAST_WITH_POINTS:
        case AI_GROUP_UNIT_RIDE_VEHICLE:
        case AI_GROUP_VEHICLE_RECALL_OR_RESPAWN_PASSENGERS:
        case AI_GROUP_VEHICLE_RECALL_LIVING_PASSENGERS:
        case AI_GROUP_VEHICLE_RESPAWN_ALL_PASSENGERS:
        case AI_GROUP_UNIT_SEND_TAP_LIST:
        case AI_GROUP_UNIT_GET_TAP_LIST:
        case AI_GROUP_TIER_TRANSITION_MOVETO:
        case AI_GROUP_TIER_TRANSITION_MOVETO_GUID:
            searchRadius = action.Extra0;
            break;
        case AI_GROUP_JUMP_POINT:
        case AI_GROUP_JUMP_GUID:
            searchRadius = action.Extra2;
            break;
        default:
            break;
    }

    return searchRadius == 0 ? 100.0f : float(searchRadius);
}

bool AIGroupScript::ExecuteAction(ActionSetEventHolder const& action, ObjectGuid const& invokerGuid)
{
    AIGroupObjectVector targets;
    if (!action.StringId.empty())
    {
        if (WorldObject* baseObject = GetBaseObject())
        {
            std::vector<Creature*> creatures;
            baseObject->GetCreatureListWithOptionsInGrid(creatures, GetStringIdSearchRadius(action), { .StringId = action.StringId });
            for (Creature* creature : creatures)
                targets.push_back(creature);

            std::vector<GameObject*> gameObjects;
            baseObject->GetGameObjectListWithOptionsInGrid(gameObjects, GetStringIdSearchRadius(action), { .StringId = action.StringId });
            for (GameObject* gameObject : gameObjects)
                targets.push_back(gameObject);
        }
    }
    else if (action.TargetType != AIGROUP_TARGET_NONE)
        GetActionTargets(targets, action);
    else if (WorldObject* baseObject = GetBaseObject())
        if (WorldObject* invoker = ObjectAccessor::GetWorldObject(*baseObject, invokerGuid))
            targets.push_back(invoker);

    switch (AI_GROUP_ACTION(action.Type))
    {
        case AI_GROUP_SPAWN:
            return true;
        case AI_GROUP_IDLE:
            return false;
        case AI_GROUP_WANDER:
            me->GetMotionMaster()->MoveRandom(float(action.Extra1));
            return false;
        case AI_GROUP_FOLLOW_PATH:
            me->GetMotionMaster()->MovePath(action.Path, false);
            return false;
        case AI_GROUP_UNIT_SAY:
            if (!targets.empty())
                me->Say(action.Extra2, targets.front());
            else
                me->Say(action.Extra2);
            return true;
        case AI_GROUP_UNIT_CAST:
            if (!targets.empty())
                me->CastSpell(targets.front(), uint32(action.Extra2));
            return true;
        case AI_GROUP_DESPAWN:
            if (WorldObject* baseObject = GetBaseObject())
            {
                if (Creature* creature = baseObject->ToCreature())
                    creature->DespawnOrUnsummon();
                else if (GameObject* gameobject = baseObject->ToGameObject())
                    gameobject->DespawnOrUnsummon();
            }
            return true;
        case AI_GROUP_UNIT_SET_FACING:
            me->SetFacingTo(action.Extra2);
            return true;
        case AI_GROUP_UNIT_FACE_GUID:
            if (!targets.empty())
                me->SetFacingToObject(targets.front());
            return true;
        case AI_GROUP_UNIT_EMOTE:
            me->PerformEmote(static_cast<Emote>(action.Extra2));
            return true;
        case AI_GROUP_UNIT_YELL:
            if (!targets.empty())
                me->Yell(action.Extra2, targets.front());
            else
                me->Yell(action.Extra2);
            return true;
        case AI_GROUP_UNIT_CHAT_EMOTE:
            if (!targets.empty())
                me->TextEmote(action.Extra2, targets.front());
            else
                me->TextEmote(action.Extra2);
            return true;
        case AI_GROUP_UNIT_TRIGGERS:
            me->SetTriggersId(action.Extra2);
            return true;
        case AI_GROUP_UNIT_TRIGGERS_RESET:
            me->ResetTriggersId();
            return true;
        case AI_GROUP_UNIT_WHISPER:
            if (!targets.empty())
                if (Player* player = targets.front()->ToPlayer())
                    me->Whisper(action.Extra2, player);
            return true;
        default:
            return true;
    }
}

void AIGroupScript::FinishActionSet(AIGroupActiveActionSet& actionSet)
{
    if (sAIGroupMgr->GetActionSetFlags(actionSet.Id) & uint32(ActionSetFlags::Looping))
        actionSet.CurrentAction = 0;
    else
        actionSet.CurrentAction = actionSet.Actions.size();

    actionSet.ActionTimer = 0;
    actionSet.ActionStarted = false;
}

bool AIGroupScript::CanActionBeInfinite(uint16 action)
{
    switch (action)
    {
        case AI_GROUP_WANDER:
        case AI_GROUP_FOLLOW_GUID:
        case AI_GROUP_PATROL_LINE:
        case AI_GROUP_PATROL_CIRCLE:
        case AI_GROUP_GUARD_GUID:
            return true;
        default:
            return false;
    }
}

bool AIGroupScript::ShouldStopMovementForAction(uint16 action)
{
    switch (action)
    {
        case AI_GROUP_WANDER:
        case AI_GROUP_FOLLOW_GUID:
        case AI_GROUP_PATROL_LINE:
        case AI_GROUP_PATROL_CIRCLE:
        case AI_GROUP_GUARD_GUID:
            return true;
        default:
            return false;
    }
}

bool AIGroupScript::IsActionWaitable(uint16 action)
{
    switch (action)
    {
        case AI_GROUP_FOLLOW_PATH:
        case AI_GROUP_MOVETO:
            return true;
        default:
            return false;
    }
}

bool AIGroupScript::IsActionSetPaused(AIGroupActiveActionSet const& actionSet) const
{
    if (!me)
        return false;

    uint32 flags = sAIGroupMgr->GetActionSetFlags(actionSet.Id);
    return (me->IsInCombat() && (flags & uint32(ActionSetFlags::PauseForCombat))) ||
        (me->IsReturningHome() && (flags & uint32(ActionSetFlags::PauseUntilAllMembersAreDoneReturning)));
}

void AIGroupScript::UpdateActionSets(uint32 diff)
{
    if (mActionSets.empty())
    {
        if (me)
            me->currentRunningActionSet = 0;
        return;
    }

    auto activeActionSet = std::max_element(mActionSets.begin(), mActionSets.end(), [this](AIGroupActiveActionSet const& left, AIGroupActiveActionSet const& right)
    {
        if (IsActionSetPaused(left))
            return !IsActionSetPaused(right);

        if (IsActionSetPaused(right))
            return false;

        return sAIGroupMgr->GetPriorityPercentForPriorityType(ActionSetPriorityType(sAIGroupMgr->GetActionSetPriority(left.Id))) <
            sAIGroupMgr->GetPriorityPercentForPriorityType(ActionSetPriorityType(sAIGroupMgr->GetActionSetPriority(right.Id)));
    });

    if (IsActionSetPaused(*activeActionSet))
    {
        if (me)
            me->currentRunningActionSet = 0;
        return;
    }

    if (me)
        me->currentRunningActionSet = activeActionSet->Id;

    while (activeActionSet->CurrentAction < activeActionSet->Actions.size())
    {
        ActionSetEventHolder const& action = activeActionSet->Actions[activeActionSet->CurrentAction];

        if (activeActionSet->ActionStarted)
        {
            if (IsActionWaitable(action.Type))
                return;

            if (CanActionBeInfinite(action.Type) && action.TimeA == 0)
                return;

            if (activeActionSet->ActionTimer > diff)
            {
                activeActionSet->ActionTimer -= diff;
                return;
            }

            if (ShouldStopMovementForAction(action.Type))
                me->GetMotionMaster()->MoveIdle();

            activeActionSet->ActionTimer = 0;
            activeActionSet->ActionStarted = false;
            ++activeActionSet->CurrentAction;
            continue;
        }

        activeActionSet->ActionStarted = true;
        activeActionSet->ActionTimer = GetActionDuration(action);
        if (ExecuteAction(action, activeActionSet->InvokerGuid) ||
            (activeActionSet->ActionTimer == 0 && !CanActionBeInfinite(action.Type) && !IsActionWaitable(action.Type)))
        {
            activeActionSet->ActionStarted = false;
            ++activeActionSet->CurrentAction;
        }
    }

    FinishActionSet(*activeActionSet);
    uint32 activeActionSetId = activeActionSet->Id;
    mActionSets.erase(std::remove_if(mActionSets.begin(), mActionSets.end(), [](AIGroupActiveActionSet const& actionSet)
    {
        return actionSet.CurrentAction >= actionSet.Actions.size();
    }), mActionSets.end());

    if (me)
        me->currentRunningActionSet = mActionSets.empty() ? 0 : activeActionSetId;
}

void AIGroupScript::ReplaceActionTriggers()
{
    AIGroupEventList preservedEvents;

    for (ActionTriggersHolder const& event : mEvents)
    {
        if (event.Flags & Unremovable)
            preservedEvents.push_back(event);
    }

    mEvents = std::move(preservedEvents);
    GetScript();
}

WorldObject* AIGroupScript::GetBaseObject() const
{
    WorldObject* object = nullptr;

    if (me)
        object = me;
    else if (go)
        object = go;

    return object;
}

void AIGroupScript::GetWorldObjectsInDist(AIGroupObjectVector& objects, float distance) const
{
    WorldObject* object = GetBaseObject();
    if (!object)
        return;

    Trinity::AllWorldObjectsInRange checker(object, distance);
    Trinity::WorldObjectListSearcher<Trinity::AllWorldObjectsInRange> searcher(object, objects, checker);
    Cell::VisitAllObjects(object, searcher, distance);
}

void AIGroupScript::GetActionTargets(AIGroupObjectVector& targets, ActionSetEventHolder const& action, WorldObject* invoker /*= nullptr*/) const
{
    WorldObject* scriptTrigger = nullptr;
    if (invoker)
        scriptTrigger = invoker;

    WorldObject* baseObject = GetBaseObject();

    AIGroupTarget target(AIGroupTargetType(action.TargetType), action.TargetParam1, action.TargetParam2, action.TargetParam3, action.TargetParam4);

    auto selectHostileTarget = [this, &target](size_t position, SelectTargetMethod method)
    {
        if (target.HostileRandom.PowerType)
            return me->AI()->SelectTarget(method, position, PowerUsersSelector(me, Powers(target.HostileRandom.PowerType - 1), float(target.HostileRandom.MaxDist), target.HostileRandom.PlayerOnly));

        return me->AI()->SelectTarget(method, position, float(target.HostileRandom.MaxDist), target.HostileRandom.PlayerOnly);
    };

    switch (target.Type)
    {
        case AIGROUP_TARGET_NONE:
            break;
        case AIGROUP_TARGET_SELF:
            if (baseObject)
                targets.push_back(baseObject);
            break;
        case AIGROUP_TARGET_VICTIM:
            if (me)
                if (Unit* victim = me->GetVictim())
                    targets.push_back(victim);
            break;
        case AIGROUP_TARGET_HOSTILE_SECOND_AGGRO:
            if (me)
                if (Unit* target = selectHostileTarget(1, SelectTargetMethod::MaxThreat))
                    targets.push_back(target);
            break;
        case AIGROUP_TARGET_HOSTILE_LAST_AGGRO:
            if (me)
                if (Unit* target = selectHostileTarget(0, SelectTargetMethod::MinThreat))
                    targets.push_back(target);
            break;
        case AIGROUP_TARGET_HOSTILE_RANDOM:
            if (me)
                if (Unit* target = selectHostileTarget(0, SelectTargetMethod::Random))
                    targets.push_back(target);
            break;
        case AIGROUP_TARGET_HOSTILE_RANDOM_NOT_TOP:
            if (me)
                if (Unit* target = selectHostileTarget(1, SelectTargetMethod::Random))
                    targets.push_back(target);
            break;
        case AIGROUP_TARGET_ACTION_INVOKER:
            if (scriptTrigger)
                targets.push_back(scriptTrigger);
            break;
        case AIGROUP_TARGET_UNUSED:
            break;
        case AIGROUP_TARGET_CREATURE_RANGE:
        {
            AIGroupObjectVector units;
            GetWorldObjectsInDist(units, float(target.UnitRange.MaxDist));

            for (WorldObject* unit : units)
            {
                if (!unit->IsCreature())
                    continue;

                if (me && me->GetGUID() == unit->GetGUID())
                    continue;

                if ((!target.UnitRange.Creature || unit->ToCreature()->GetEntry() == target.UnitRange.Creature) && baseObject->IsInRange(unit, float(target.UnitRange.MinDist), float(target.UnitRange.MaxDist)))
                    targets.push_back(unit);
            }

            if (target.UnitRange.MaxSize)
                Trinity::Containers::RandomResize(targets, target.UnitRange.MaxSize);
            break;
        }
        case AIGROUP_TARGET_CREATURE_GUID:
        {
            if (!baseObject)
                break;

            if (Creature* creature = FindCreatureNear(baseObject, target.UnitGuid.DbGuid))
                if (!target.UnitGuid.Entry || creature->GetEntry() == target.UnitGuid.Entry)
                    targets.push_back(creature);
            break;
        }
        case AIGROUP_TARGET_CREATURE_DISTANCE:
        {
            AIGroupObjectVector units;
            GetWorldObjectsInDist(units, float(target.UnitDistance.Dist));

            for (WorldObject* unit : units)
            {
                if (!unit->IsCreature())
                    continue;

                if (me && me->GetGUID() == unit->GetGUID())
                    continue;

                if (!target.UnitDistance.Creature || unit->ToCreature()->GetEntry() == target.UnitDistance.Creature)
                    targets.push_back(unit);

            }

            if (target.UnitDistance.MaxSize)
                Trinity::Containers::RandomResize(targets, target.UnitDistance.MaxSize);
            break;
        }
        case AIGROUP_TARGET_STORED:
            break;
        case AIGROUP_TARGET_GAMEOBJECT_RANGE:
        {
            if (!baseObject)
                break;

            AIGroupObjectVector units;
            GetWorldObjectsInDist(units, float(target.GameObjectRange.MaxDist));

            for (WorldObject* unit : units)
            {
                if (!unit->IsGameObject())
                    continue;

                if (go && go->GetGUID() == unit->GetGUID())
                    continue;

                if ((!target.GameObjectRange.Entry || unit->ToGameObject()->GetEntry() == target.GameObjectRange.Entry) && baseObject->IsInRange(unit, float(target.GameObjectRange.MinDist), float(target.GameObjectRange.MaxDist)))
                    targets.push_back(unit);
            }

            if (target.GameObjectRange.MaxSize)
                Trinity::Containers::RandomResize(targets, target.GameObjectRange.MaxSize);
            break;
        }
        case AIGROUP_TARGET_GAMEOBJECT_GUID:
        {
            if (!baseObject)
                break;

            if (GameObject* gameObject = FindGameObjectNear(baseObject, target.GameObjectGuid.DbGuid))
                if (!target.GameObjectGuid.Entry || gameObject->GetEntry() == target.GameObjectGuid.Entry)
                    targets.push_back(gameObject);
            break;
        }
        case AIGROUP_TARGET_GAMEOBJECT_DISTANCE:
        {
            AIGroupObjectVector units;
            GetWorldObjectsInDist(units, float(target.GameObjectDistance.Dist));

            for (WorldObject* unit : units)
            {
                if (!unit->IsGameObject())
                    continue;

                if (go && go->GetGUID() == unit->GetGUID())
                    continue;

                if (!target.GameObjectDistance.Entry || unit->ToGameObject()->GetEntry() == target.GameObjectDistance.Entry)
                    targets.push_back(unit);
            }

            if (target.GameObjectDistance.MaxSize)
                Trinity::Containers::RandomResize(targets, target.GameObjectDistance.MaxSize);
            break;
        }
        case AIGROUP_TARGET_INVOKER_PARTY:
            if (scriptTrigger)
            {
                if (Player* player = scriptTrigger->ToPlayer())
                {
                    if (Group* group = player->GetGroup())
                    {
                        for (GroupReference* groupRef = group->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                            if (Player* member = groupRef->GetSource())
                                if (member->IsInMap(player))
                                    targets.push_back(member);
                    }
                    // We still add the player to the list if there is no group. If we do
                    // this even if there is a group (thus the else-check), it will add the
                    // same player to the list twice. We don't want that to happen.
                    else
                        targets.push_back(scriptTrigger);
                }
            }
            break;
        case AIGROUP_TARGET_PLAYER_RANGE:
        {
            AIGroupObjectVector units;
            GetWorldObjectsInDist(units, float(target.PlayerRange.MaxDist));

            if (!units.empty() && baseObject)
                for (WorldObject* unit : units)
                    if (unit->IsPlayer() && baseObject->IsInRange(unit, float(target.PlayerRange.MinDist), float(target.PlayerRange.MaxDist)))
                        targets.push_back(unit);
            break;
        }
        case AIGROUP_TARGET_PLAYER_DISTANCE:
        {
            AIGroupObjectVector units;
            GetWorldObjectsInDist(units, float(target.PlayerDistance.Dist));
            for (WorldObject* unit : units)
                if (unit->IsPlayer())
                    targets.push_back(unit);
            break;
        }
        case AIGROUP_TARGET_CLOSEST_CREATURE:
            if (baseObject)
                if (Creature* creature = baseObject->FindNearestCreature(target.ClosestCreature.Entry, float(target.ClosestCreature.Dist ? target.ClosestCreature.Dist : 100), !target.ClosestCreature.Dead))
                    targets.push_back(creature);
            break;
        case AIGROUP_TARGET_CLOSEST_GAMEOBJECT:
            if (baseObject)
                if (GameObject* gameObject = baseObject->FindNearestGameObject(target.ClosestGameObject.Entry, float(target.ClosestGameObject.Dist ? target.ClosestGameObject.Dist : 100)))
                    targets.push_back(gameObject);
            break;
        case AIGROUP_TARGET_CLOSEST_PLAYER:
            if (baseObject)
                if (Player* player = baseObject->SelectNearestPlayer(float(target.PlayerDistance.Dist)))
                    targets.push_back(player);
            break;
        case AIGROUP_TARGET_ACTION_INVOKER_VEHICLE:
            if (scriptTrigger && scriptTrigger->ToUnit() && scriptTrigger->ToUnit()->GetVehicle() && scriptTrigger->ToUnit()->GetVehicle()->GetBase())
                targets.push_back(scriptTrigger->ToUnit()->GetVehicle()->GetBase());
            break;
        case AIGROUP_TARGET_OWNER_OR_SUMMONER:
        {
            if (me)
            {
                ObjectGuid charmerOrOwnerGuid = me->GetCharmerOrOwnerGUID();

                if (!charmerOrOwnerGuid)
                    if (TempSummon* tempSummon = me->ToTempSummon())
                        if (WorldObject* summoner = tempSummon->GetSummoner())
                            charmerOrOwnerGuid = summoner->GetGUID();

                if (!charmerOrOwnerGuid)
                    charmerOrOwnerGuid = me->GetCreatorGUID();

                if (WorldObject* owner = ObjectAccessor::GetWorldObject(*me, charmerOrOwnerGuid))
                    targets.push_back(owner);
            }
            else if (go)
            {
                if (Unit* owner = ObjectAccessor::GetUnit(*go, go->GetOwnerGUID()))
                    targets.push_back(owner);
            }

            // Get owner of owner
            if (target.Owner.UseCharmerOrOwner && !targets.empty())
            {
                WorldObject* owner = targets.front();
                targets.clear();

                if (Unit* base = ObjectAccessor::GetUnit(*owner, owner->GetCharmerOrOwnerGUID()))
                    targets.push_back(base);
            }
            break;
        }
        case AIGROUP_TARGET_THREAT_LIST:
        {
            if (me && me->CanHaveThreatList())
                for (auto* ref : me->GetThreatManager().GetUnsortedThreatList())
                    if (!target.ThreatList.MaxDist || me->IsWithinCombatRange(ref->GetVictim(), float(target.ThreatList.MaxDist)))
                        targets.push_back(ref->GetVictim());
            break;
        }
        case AIGROUP_TARGET_CLOSEST_ENEMY:
        {
            if (me)
                if (Unit* selected = me->SelectNearestTarget(target.ClosestUnit.MaxDist, target.ClosestUnit.PlayerOnly != 0))
                    targets.push_back(selected);
            break;
        }
        case AIGROUP_TARGET_CLOSEST_FRIENDLY:
        {
            if (!me)
                break;

            Unit* selected = nullptr;
            Trinity::AnyFriendlyUnitInObjectRangeCheck checker(me, me, target.ClosestUnit.MaxDist, target.ClosestUnit.PlayerOnly);
            Trinity::UnitLastSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(me, selected, checker);
            Cell::VisitAllObjects(me, searcher, target.ClosestUnit.MaxDist);
            if (selected)
                targets.push_back(selected);
            break;
        }
        case AIGROUP_TARGET_LOOT_RECIPIENTS:
        {
            if (me)
            {
                if (Group* lootGroup = me->GetLootRecipientGroup())
                {
                    for (GroupReference* it = lootGroup->GetFirstMember(); it != nullptr; it = it->next())
                        if (Player* recipient = it->GetSource())
                            if (recipient->IsInMap(me))
                                targets.push_back(recipient);
                }
                else
                {
                    if (Player* recipient = me->GetLootRecipient())
                        targets.push_back(recipient);
                }
            }
            break;
        }
        case AIGROUP_TARGET_FARTHEST:
            if (me)
            {
                if (Unit* unit = me->AI()->SelectTarget(SelectTargetMethod::MaxDistance, 0, FarthestTargetSelector(me, float(target.Farthest.MaxDist), target.Farthest.PlayerOnly, target.Farthest.IsInLos != 0)))
                    targets.push_back(unit);
            }
            break;

        case AIGROUP_TARGET_VEHICLE_PASSENGER:
        {
            if (me && me->IsVehicle())
                for (std::pair<int8 const, VehicleSeat>& seat : me->GetVehicleKit()->Seats)
                    if (!target.Vehicle.SeatMask || (target.Vehicle.SeatMask & (1 << seat.first)))
                        if (Unit* unit = ObjectAccessor::GetUnit(*me, seat.second.Passenger.Guid))
                            targets.push_back(unit);
            break;
        }
        case AIGROUP_TARGET_CLOSEST_UNSPAWNED_GAMEOBJECT:
            if (baseObject)
                if (GameObject* gameObject = baseObject->FindNearestUnspawnedGameObject(target.ClosestGameObject.Entry, float(target.ClosestGameObject.Dist ? target.ClosestGameObject.Dist : 100)))
                    targets.push_back(gameObject);
            break;
        default:
            break;
    }
}

GameObject* AIGroupScript::FindGameObjectNear(WorldObject* searchObject, ObjectGuid::LowType guid) const
{
    auto bounds = searchObject->GetMap()->GetGameObjectBySpawnIdStore().equal_range(guid);
    if (bounds.first == bounds.second)
        return nullptr;

    return bounds.first->second;
}

Creature* AIGroupScript::FindCreatureNear(WorldObject* searchObject, ObjectGuid::LowType guid) const
{
    auto bounds = searchObject->GetMap()->GetCreatureBySpawnIdStore().equal_range(guid);
    if (bounds.first == bounds.second)
        return nullptr;

    auto creatureItr = std::find_if(bounds.first, bounds.second, [](Map::CreatureBySpawnIdContainer::value_type const& pair)
    {
        return pair.second->IsAlive();
    });

    return creatureItr != bounds.second ? creatureItr->second : bounds.first->second;
}

void AIGroupScript::ProcessEventsFor(UnitActionTriggers trigger, Unit* unit, uint32 triggerParam1, uint32 triggerParam2, GameObject* gob)
{
    for (ActionTriggersHolder& holder : mEvents)
    {
        UnitActionTriggers triggerType = UnitActionTriggers(holder.TriggerId);
        if (triggerType == trigger)
            ProcessEvent(holder, unit, triggerParam1, triggerParam2, gob);
    }
}

void AIGroupScript::ProcessEvent(ActionTriggersHolder& holder, Unit* unit, uint32 triggerParam1, uint32 /*triggerParam2*/, GameObject* /*gob*/)
{
    if (!holder.IsTriggerActive || ((holder.Flags & NotRepeatable) && holder.IsTriggerUsed))
        return;

    bool shouldStartActionSet = false;

    switch (holder.TriggerId)
    {
        case OnDeath:
        case OnSpawn:
            shouldStartActionSet = true;
            break;
        case OnSpell:
            if (triggerParam1 == holder.TriggerParam1)
            {
                shouldStartActionSet = true;
                RecalcTimer(holder);
            }
            break;
        case OnEmote:
            if (triggerParam1 == holder.TriggerParam1)
            {
                shouldStartActionSet = true;
                RecalcTimer(holder);
            }
            break;
        default:
            break;
    }

    if (!shouldStartActionSet || !roll_chance_i(holder.Chance))
        return;

    if (holder.Flags & NotRepeatable)
        holder.IsTriggerUsed = true;

    StartActionSet(holder.ActionSetId, unit ? unit->GetGUID() : ObjectGuid::Empty);
}

void AIGroupScript::RecalcTimer(ActionTriggersHolder& holder)
{
    holder.RepeatTimer = urand(holder.RepeatMin, holder.RepeatMax);
    holder.IsTriggerActive = holder.RepeatTimer ? false : true;
}

void AIGroupScript::UpdateTimer(ActionTriggersHolder& holder, uint32 const diff)
{
    if ((holder.Flags & NotRepeatable) && holder.IsTriggerUsed)
        return;

    if (holder.RepeatTimer < diff)
        holder.IsTriggerActive = true;
    else
        holder.RepeatTimer -= diff;
}

void AIGroupScript::OnUpdate(uint32 const diff)
{
    for (ActionTriggersHolder& holder : mEvents)
        UpdateTimer(holder, diff);

    UpdateActionSets(diff);
}
