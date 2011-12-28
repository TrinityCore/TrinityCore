/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
//Basic headers
#include "WaypointMovementGenerator.h"
//Extended headers
#include "ObjectMgr.h"
#include "World.h"
//Creature-specific headers
#include "Creature.h"
#include "CreatureAI.h"
#include "CreatureGroups.h"
//Player-specific
#include "Player.h"
#include "MoveSplineInit.h"
#include "MoveSpline.h"

void WaypointMovementGenerator<Creature>::LoadPath(Creature &creature)
{
    if (!path_id)
        path_id = creature.GetWaypointPath();

    i_path = sWaypointMgr->GetPath(path_id);

    if (!i_path)
    {
        // No movement found for entry
        sLog->outErrorDb("WaypointMovementGenerator::LoadPath: creature %s (Entry: %u GUID: %u) doesn't have waypoint path id: %u", creature.GetName(), creature.GetEntry(), creature.GetGUIDLow(), path_id);
        return;
    }

    StartMoveNow(creature);
}

void WaypointMovementGenerator<Creature>::Initialize(Creature &creature)
{
    LoadPath(creature);
    creature.AddUnitState(UNIT_STAT_ROAMING|UNIT_STAT_ROAMING_MOVE);
}

void WaypointMovementGenerator<Creature>::Finalize(Creature &creature)
{
    creature.ClearUnitState(UNIT_STAT_ROAMING|UNIT_STAT_ROAMING_MOVE);
    creature.SetWalk(false);
}

void WaypointMovementGenerator<Creature>::Reset(Creature &creature)
{
    creature.AddUnitState(UNIT_STAT_ROAMING|UNIT_STAT_ROAMING_MOVE);
    StartMoveNow(creature);
}

void WaypointMovementGenerator<Creature>::OnArrived(Creature& creature)
{
    if (!i_path || i_path->empty())
        return;
    if (m_isArrivalDone)
        return;

    creature.ClearUnitState(UNIT_STAT_ROAMING_MOVE);
    m_isArrivalDone = true;

    if (i_path->at(i_currentNode)->event_id && urand(0, 99) < i_path->at(i_currentNode)->event_chance)
    {
        sLog->outDebug(LOG_FILTER_MAPSCRIPTS, "Creature movement start script %u at point %u for %u.", i_path->at(i_currentNode)->event_id, i_currentNode, creature.GetGUID());
        creature.GetMap()->ScriptsStart(sWaypointScripts, i_path->at(i_currentNode)->event_id, &creature, NULL/*, false*/);
    }

    // Inform script
    MovementInform(creature);
    Stop(i_path->at(i_currentNode)->delay);
}

bool WaypointMovementGenerator<Creature>::StartMove(Creature &creature)
{
    if (!i_path || i_path->empty())
        return false;
    if (Stopped())
        return true;

    const WaypointData *node = i_path->at(i_currentNode);

    if (m_isArrivalDone)
    {
        if ((i_currentNode == i_path->size() - 1) &&  !repeating) // If that's our last waypoint
        {
            creature.SetHomePosition(node->x, node->y, node->z, creature.GetOrientation());
            creature.GetMotionMaster()->Initialize();
            return false;
        }

        i_currentNode = (i_currentNode+1) % i_path->size();

    }

    m_isArrivalDone = false;

    creature.AddUnitState(UNIT_STAT_ROAMING_MOVE);

    Movement::MoveSplineInit init(creature);
    init.MoveTo(node->x, node->y, node->z);

    if (node->orientation != 100 && node->delay != 0)
        init.SetFacing(node->orientation);

    init.SetWalk(!node->run);
    init.Launch();

    //Call for creature group update
    if (creature.GetFormation() && creature.GetFormation()->getLeader() == &creature)
        creature.GetFormation()->LeaderMoveTo(node->x, node->y, node->z);

    return true;
}

bool WaypointMovementGenerator<Creature>::Update(Creature &creature, const uint32 &diff)
{
    // Waypoint movement can be switched on/off
    // This is quite handy for escort quests and other stuff
    if (creature.HasUnitState(UNIT_STAT_NOT_MOVE))
    {
        creature.ClearUnitState(UNIT_STAT_ROAMING_MOVE);
        return true;
    }
    // prevent a crash at empty waypoint path.
    if (!i_path || i_path->empty())
        return false;

    if (Stopped())
        if (CanMove(diff))
            return StartMove(creature);

    if (creature.IsStopped())
        Stop(STOP_TIME_FOR_PLAYER);
    else if (creature.movespline->Finalized())
    {
        OnArrived(creature);
        StartMove(creature);
    }

     return true;
 }

void WaypointMovementGenerator<Creature>::MovementInform(Creature &creature)
{
    if (creature.AI())
        creature.AI()->MovementInform(WAYPOINT_MOTION_TYPE, i_currentNode);
}

bool WaypointMovementGenerator<Creature>::GetResetPosition(Creature&, float& x, float& y, float& z)
{
    // prevent a crash at empty waypoint path.
    if (!i_path || i_path->empty())
        return false;

    const WaypointData* node = i_path->at(i_currentNode);
    x = node->x; y = node->y; z = node->z;
    return true;
}


//----------------------------------------------------//

uint32 FlightPathMovementGenerator::GetPathAtMapEnd() const
{
    if (i_currentNode >= i_path->size())
        return i_path->size();

    uint32 curMapId = (*i_path)[i_currentNode].mapid;
    for (uint32 i = i_currentNode; i < i_path->size(); ++i)
    {
        if ((*i_path)[i].mapid != curMapId)
            return i;
    }

    return i_path->size();
}

void FlightPathMovementGenerator::Initialize(Player &player)
{
    Reset(player);
}

void FlightPathMovementGenerator::Finalize(Player & player)
{
    // remove flag to prevent send object build movement packets for flight state and crash (movement generator already not at top of stack)
    player.ClearUnitState(UNIT_STAT_IN_FLIGHT);

    player.Dismount();
    player.RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_TAXI_FLIGHT);

    if(player.m_taxi.empty())
    {
        player.getHostileRefManager().setOnlineOfflineState(true);
        if(player.pvpInfo.inHostileArea)
            player.CastSpell(&player, 2479, true);

        // update z position to ground and orientation for landing point
        // this prevent cheating with landing  point at lags
        // when client side flight end early in comparison server side
        player.StopMoving();
    }
}

//#define    PLAYER_FLIGHT_SPEED       = 32.0f

void FlightPathMovementGenerator::Reset(Player & player)
{
    player.getHostileRefManager().setOnlineOfflineState(false);
    player.AddUnitState(UNIT_STAT_IN_FLIGHT);
    player.SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_TAXI_FLIGHT);

    Movement::MoveSplineInit init(player);
    uint32 end = GetPathAtMapEnd();
    for (uint32 i = GetCurrentNode(); i != end; ++i)
    {
        G3D::Vector3 vertice((*i_path)[i].x,(*i_path)[i].y,(*i_path)[i].z);
        init.Path().push_back(vertice);
    }
    init.SetFirstPointId(GetCurrentNode());
    init.SetFly();
    init.SetVelocity(32.0f);
    init.Launch();
}

bool FlightPathMovementGenerator::Update(Player &player, const uint32 diff)
{
    uint32 pointId = (uint32)player.movespline->currentPathIdx();
    if (pointId > i_currentNode)
    {
        bool departureEvent = true;
        do
        {
            DoEventIfAny(player,(*i_path)[i_currentNode],departureEvent);
            if (pointId == i_currentNode)
                break;
            i_currentNode += (uint32)departureEvent;
            departureEvent = !departureEvent;
        } while(true);
    }

    return i_currentNode < (i_path->size()-1);

    // we have arrived at the end of the path
    return false;
}

void FlightPathMovementGenerator::SetCurrentNodeAfterTeleport()
{
    if (i_path->empty())
        return;

    uint32 map0 = (*i_path)[0].mapid;
    for (size_t i = 1; i < i_path->size(); ++i)
    {
        if ((*i_path)[i].mapid != map0)
        {
            i_currentNode = i;
            return;
        }
    }
}

void FlightPathMovementGenerator::DoEventIfAny(Player& player, TaxiPathNodeEntry const& node, bool departure)
{
    if (uint32 eventid = departure ? node.departureEventID : node.arrivalEventID)
    {
        sLog->outDebug(LOG_FILTER_MAPSCRIPTS, "Taxi %s event %u of node %u of path %u for player %s", departure ? "departure" : "arrival", eventid, node.index, node.path, player.GetName());
        player.GetMap()->ScriptsStart(sEventScripts, eventid, &player, &player);
    }
}

bool FlightPathMovementGenerator::GetResetPosition(Player&, float& x, float& y, float& z)
{
    const TaxiPathNodeEntry& node = (*i_path)[i_currentNode];
    x = node.x; y = node.y; z = node.z;
    return true;
}

