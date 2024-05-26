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

#include "ScriptedEscortAI.h"
#include "Creature.h"
#include "Group.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "MovementGenerator.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptSystem.h"
#include "WaypointManager.h"
#include "World.h"

enum Points
{
    POINT_LAST_POINT    = 0xFFFFFF,
    POINT_HOME          = 0xFFFFFE
};

EscortAI::EscortAI(Creature* creature) : ScriptedAI(creature), _pauseTimer(2500ms), _playerCheckTimer(1000), _escortState(STATE_ESCORT_NONE), _maxPlayerDistance(DEFAULT_MAX_PLAYER_DISTANCE),
    _escortQuest(nullptr), _activeAttacker(true), _instantRespawn(false), _returnToStart(false), _despawnAtEnd(true), _despawnAtFar(true),
    _hasImmuneToNPCFlags(false), _started(false), _ended(false), _resume(false)
{
}

void EscortAI::MoveInLineOfSight(Unit* who)
{
    if (!who)
        return;

    if (HasEscortState(STATE_ESCORT_ESCORTING) && AssistPlayerInCombatAgainst(who))
        return;

    ScriptedAI::MoveInLineOfSight(who);
}

void EscortAI::JustDied(Unit* /*killer*/)
{
    if (!HasEscortState(STATE_ESCORT_ESCORTING) || !_playerGUID || !_escortQuest)
        return;

    if (Player* player = GetPlayerForEscort())
    {
        if (Group* group = player->GetGroup())
        {
            for (GroupReference* groupRef = group->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                if (Player* member = groupRef->GetSource())
                    if (member->IsInMap(player))
                        member->FailQuest(_escortQuest->GetQuestId());
        }
        else
            player->FailQuest(_escortQuest->GetQuestId());
    }
}

void EscortAI::InitializeAI()
{
    _escortState = STATE_ESCORT_NONE;

    if (!IsCombatMovementAllowed())
        SetCombatMovement(true);

    // add a small delay before going to first waypoint, normal in near all cases
    _pauseTimer = 2s;

    if (me->GetFaction() != me->GetCreatureTemplate()->faction)
        me->RestoreFaction();

    Reset();
}

void EscortAI::ReturnToLastPoint()
{
    me->GetMotionMaster()->MovePoint(POINT_LAST_POINT, me->GetHomePosition());
}

void EscortAI::EnterEvadeMode(EvadeReason /*why*/)
{
    me->RemoveAllAuras();
    me->CombatStop(true);
    if (!me->IsTapListNotClearedOnEvade())
        me->SetTappedBy(nullptr);

    EngagementOver();

    if (HasEscortState(STATE_ESCORT_ESCORTING))
    {
        AddEscortState(STATE_ESCORT_RETURNING);
        ReturnToLastPoint();
        TC_LOG_DEBUG("scripts.ai.escortai", "EscortAI::EnterEvadeMode: left combat and is now returning to last point ({})", me->GetGUID().ToString());
    }
    else
    {
        me->GetMotionMaster()->MoveTargetedHome();
        if (_hasImmuneToNPCFlags)
            me->SetImmuneToNPC(true);
        Reset();
    }
}

void EscortAI::MovementInform(uint32 type, uint32 id)
{
    // no action allowed if there is no escort
    if (!HasEscortState(STATE_ESCORT_ESCORTING))
        return;

    if (type == POINT_MOTION_TYPE)
    {
        if (_pauseTimer == 0s)
            _pauseTimer = 2s;

        // continue waypoint movement
        if (id == POINT_LAST_POINT)
        {
            TC_LOG_DEBUG("scripts.ai.escortai", "EscortAI::MovementInform: returned to before combat position ({})", me->GetGUID().ToString());
            me->SetWalk(false);
            RemoveEscortState(STATE_ESCORT_RETURNING);
        }
        else if (id == POINT_HOME)
        {
            TC_LOG_DEBUG("scripts.ai.escortai", "EscortAI::MovementInform: returned to home location and restarting waypoint path ({})", me->GetGUID().ToString());
            _started = false;
        }
    }
    else if (type == WAYPOINT_MOTION_TYPE)
    {
        ASSERT(id < _path.Nodes.size(), "EscortAI::MovementInform: referenced movement id (%u) points to non-existing node in loaded path (%s)", id, me->GetGUID().ToString().c_str());
        WaypointNode waypoint = _path.Nodes[id];

        TC_LOG_DEBUG("scripts.ai.escortai", "EscortAI::MovementInform: waypoint node {} reached ({})", waypoint.Id, me->GetGUID().ToString());

        // last point
        if (id == _path.Nodes.size() - 1)
        {
            _started = false;
            _ended = true;
            _pauseTimer = 1s;
        }
    }
}

void EscortAI::UpdateAI(uint32 diff)
{
    // Waypoint Updating
    if (HasEscortState(STATE_ESCORT_ESCORTING) && !me->IsEngaged() && !HasEscortState(STATE_ESCORT_RETURNING))
    {
        if (_pauseTimer.count() <= diff)
        {
            if (!HasEscortState(STATE_ESCORT_PAUSED))
            {
                _pauseTimer = 0s;

                if (_ended)
                {
                    _ended = false;
                    me->GetMotionMaster()->MoveIdle();

                    if (_despawnAtEnd)
                    {
                        TC_LOG_DEBUG("scripts.ai.escortai", "EscortAI::UpdateAI: reached end of waypoints, despawning at end ({})", me->GetGUID().ToString());
                        if (_returnToStart)
                        {
                            Position respawnPosition;
                            float orientation = 0.f;
                            me->GetRespawnPosition(respawnPosition.m_positionX, respawnPosition.m_positionY, respawnPosition.m_positionZ, &orientation);
                            respawnPosition.SetOrientation(orientation);
                            me->GetMotionMaster()->MovePoint(POINT_HOME, respawnPosition);
                            TC_LOG_DEBUG("scripts.ai.escortai", "EscortAI::UpdateAI: returning to spawn location: {} ({})", respawnPosition.ToString(), me->GetGUID().ToString());
                        }
                        else if (_instantRespawn)
                            me->Respawn(true);
                        else
                            me->DespawnOrUnsummon();
                    }
                    TC_LOG_DEBUG("scripts.ai.escortai", "EscortAI::UpdateAI: reached end of waypoints ({})", me->GetGUID().ToString());
                    RemoveEscortState(STATE_ESCORT_ESCORTING);
                    return;
                }

                if (!_started)
                {
                    _started = true;
                    me->GetMotionMaster()->MovePath(_path, false);
                }
                else if (_resume)
                {
                    _resume = false;
                    if (MovementGenerator* movementGenerator = me->GetMotionMaster()->GetCurrentMovementGenerator(MOTION_SLOT_DEFAULT))
                        movementGenerator->Resume(0);
                }
            }
        }
        else
            _pauseTimer -= Milliseconds(diff);
    }

    // Check if player or any member of his group is within range
    if (_despawnAtFar && HasEscortState(STATE_ESCORT_ESCORTING) && !_playerGUID.IsEmpty() && !me->IsEngaged() && !HasEscortState(STATE_ESCORT_RETURNING))
    {
        if (_playerCheckTimer <= diff)
        {
            if (!IsPlayerOrGroupInRange())
            {
                TC_LOG_DEBUG("scripts.ai.escortai", "EscortAI::UpdateAI: failed because player/group was to far away or not found ({})", me->GetGUID().ToString());

                bool isEscort = false;
                if (CreatureData const* creatureData = me->GetCreatureData())
                    isEscort = (sWorld->getBoolConfig(CONFIG_RESPAWN_DYNAMIC_ESCORTNPC) && (creatureData->spawnGroupData->flags & SPAWNGROUP_FLAG_ESCORTQUESTNPC));

                if (_instantRespawn)
                {
                    if (!isEscort)
                      me->DespawnOrUnsummon(0s, 1s);
                    else
                      me->GetMap()->Respawn(SPAWN_TYPE_CREATURE, me->GetSpawnId());
                }
                else
                    me->DespawnOrUnsummon();

                return;
            }

            _playerCheckTimer = 1000;
        }
        else
            _playerCheckTimer -= diff;
    }

    UpdateEscortAI(diff);
}

void EscortAI::UpdateEscortAI(uint32 /*diff*/)
{
    UpdateVictim();
}

void EscortAI::AddWaypoint(uint32 id, float x, float y, float z, bool run)
{
    AddWaypoint(id, x, y, z, 0.0f, {}, run);
}

void EscortAI::AddWaypoint(uint32 id, float x, float y, float z, float orientation/* = 0*/, Optional<Milliseconds> waitTime/* = {}*/, bool run /*= false*/)
{
    Trinity::NormalizeMapCoord(x);
    Trinity::NormalizeMapCoord(y);

    WaypointNode& waypoint = _path.Nodes.emplace_back(id, x, y, z, orientation, waitTime);
    waypoint.MoveType = run ? WaypointMoveType::Run : WaypointMoveType::Walk;
}

void EscortAI::ResetPath()
{
    _path.Nodes.clear();
}

void EscortAI::LoadPath(uint32 pathId)
{
    WaypointPath const* path = sWaypointMgr->GetPath(pathId);
    if (!path)
    {
        TC_LOG_ERROR("scripts.ai.escortai", "EscortAI::LoadPath: (script: {}) path {} is invalid ({})", me->GetScriptName(), pathId, me->GetGUID().ToString());
        return;
    }
    _path = *path;
}

/// @todo get rid of this many variables passed in function.
void EscortAI::Start(bool isActiveAttacker /* = true*/, ObjectGuid playerGUID /* = 0 */, Quest const* quest /* = nullptr */, bool instantRespawn /* = false */, bool canLoopPath /* = false */)
{
    if (_path.Nodes.empty())
    {
        TC_LOG_ERROR("scripts.ai.escortai", "EscortAI::Start: (script: {}) path is empty ({})", me->GetScriptName(), me->GetGUID().ToString());
        return;
    }

    // Queue respawn from the point it starts
    if (CreatureData const* cdata = me->GetCreatureData())
    {
        if (sWorld->getBoolConfig(CONFIG_RESPAWN_DYNAMIC_ESCORTNPC) && (cdata->spawnGroupData->flags & SPAWNGROUP_FLAG_ESCORTQUESTNPC))
            me->SaveRespawnTime(me->GetRespawnDelay());
    }

    if (me->IsEngaged())
    {
        TC_LOG_ERROR("scripts.ai.escortai", "EscortAI::Start: (script: {}) attempts to Start while in combat ({})", me->GetScriptName(), me->GetGUID().ToString());
        return;
    }

    if (HasEscortState(STATE_ESCORT_ESCORTING))
    {
        TC_LOG_ERROR("scripts.ai.escortai", "EscortAI::Start: (script: {}) attempts to Start while already escorting ({})", me->GetScriptName(), me->GetGUID().ToString());
        return;
    }

    if (_path.Nodes.empty())
    {
        TC_LOG_ERROR("scripts.ai.escortai", "EscortAI::Start: (script: {}) is set to return home after waypoint end and instant respawn at waypoint end. Creature will never despawn ({})", me->GetScriptName(), me->GetGUID().ToString());
        return;
    }

    // set variables
    _activeAttacker = isActiveAttacker;
    _playerGUID = playerGUID;
    _escortQuest = quest;
    _instantRespawn = instantRespawn;
    _returnToStart = canLoopPath;

    if (_returnToStart && _instantRespawn)
        TC_LOG_ERROR("scripts.ai.escortai", "EscortAI::Start: (script: {}) is set to return home after waypoint end and instant respawn at waypoint end. Creature will never despawn ({})", me->GetScriptName(), me->GetGUID().ToString());

    me->GetMotionMaster()->MoveIdle();
    me->GetMotionMaster()->Clear(MOTION_PRIORITY_NORMAL);

    // disable npcflags
    me->ReplaceAllNpcFlags(UNIT_NPC_FLAG_NONE);
    me->ReplaceAllNpcFlags2(UNIT_NPC_FLAG_2_NONE);
    if (me->IsImmuneToNPC())
    {
        _hasImmuneToNPCFlags = true;
        me->SetImmuneToNPC(false);
    }

    TC_LOG_DEBUG("scripts.ai.escortai", "EscortAI::Start: (script: {}) started with {} waypoints. ActiveAttacker = {}, Player = {} ({})",
        me->GetScriptName(), uint32(_path.Nodes.size()), _activeAttacker, _playerGUID.ToString(), me->GetGUID().ToString());

    _started = false;
    AddEscortState(STATE_ESCORT_ESCORTING);
}

void EscortAI::SetEscortPaused(bool on)
{
    if (!HasEscortState(STATE_ESCORT_ESCORTING))
        return;

    if (on)
    {
        AddEscortState(STATE_ESCORT_PAUSED);
        if (MovementGenerator* movementGenerator = me->GetMotionMaster()->GetCurrentMovementGenerator(MOTION_SLOT_DEFAULT))
            movementGenerator->Pause(0);
    }
    else
    {
        RemoveEscortState(STATE_ESCORT_PAUSED);
        _resume = true;
    }
}

Player* EscortAI::GetPlayerForEscort()
{
    return ObjectAccessor::GetPlayer(*me, _playerGUID);
}

// see followerAI
bool EscortAI::AssistPlayerInCombatAgainst(Unit* who)
{
    if (!who || !who->GetVictim())
        return false;

    if (me->HasReactState(REACT_PASSIVE))
        return false;

    // experimental (unknown) flag not present
    if (!(me->GetCreatureDifficulty()->TypeFlags & CREATURE_TYPE_FLAG_CAN_ASSIST))
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
    if (me->IsWithinDistInMap(who, GetMaxPlayerDistance()) && me->IsWithinLOSInMap(who))
    {
        me->EngageWithTarget(who);
        return true;
    }

    return false;
}

bool EscortAI::IsPlayerOrGroupInRange()
{
    if (Player* player = GetPlayerForEscort())
    {
        if (Group* group = player->GetGroup())
        {
            for (GroupReference* groupRef = group->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                if (Player* member = groupRef->GetSource())
                    if (me->IsWithinDistInMap(member, GetMaxPlayerDistance()))
                        return true;
        }
        else if (me->IsWithinDistInMap(player, GetMaxPlayerDistance()))
            return true;
    }

    return false;
}
