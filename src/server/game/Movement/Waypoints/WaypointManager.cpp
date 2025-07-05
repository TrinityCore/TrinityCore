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

#include "WaypointManager.h"
#include "DatabaseEnv.h"
#include "GridDefines.h"
#include "Log.h"
#include "MapUtils.h"
#include "ObjectAccessor.h"
#include "Optional.h"
#include "QueryResultStructured.h"
#include "TemporarySummon.h"
#include "Unit.h"

DEFINE_FIELD_ACCESSOR_CACHE(WaypointMgr::, PathQueryResult, PreparedResultSet, (PathId)(MoveType)(Flags)(Velocity));
DEFINE_FIELD_ACCESSOR_CACHE(WaypointMgr::, PathNodeQueryResult, PreparedResultSet, (PathId)(NodeId)(PositionX)(PositionY)(PositionZ)(Orientation)(Delay));

WaypointMgr::WaypointMgr() = default;
WaypointMgr::~WaypointMgr() = default;

void WaypointMgr::LoadPaths()
{
    _LoadPaths();
    _LoadPathNodes();
    DoPostLoadingChecks();
}

void WaypointMgr::_LoadPaths()
{
    uint32 oldMSTime = getMSTime();

    _pathStore.clear();

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_PATH);
    stmt->setUInt32(0, 0);
    stmt->setUInt32(1, 1);

    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 waypoint paths. DB table `waypoint_path` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {
        LoadPathFromDB(*result);
        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} waypoint paths in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void WaypointMgr::_LoadPathNodes()
{
    uint32 oldMSTime = getMSTime();

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_PATH_NODE);
    stmt->setUInt32(0, 0);
    stmt->setUInt32(1, 1);

    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 waypoint path nodes. DB table `waypoint_path_node` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {
        LoadPathNodesFromDB(*result);
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} waypoint path nodes in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void WaypointMgr::LoadPathFromDB(PathQueryResult const& fields)
{
    uint32 pathId = fields.PathId().GetUInt32();

    WaypointPath& path = _pathStore[pathId];

    path.MoveType = WaypointMoveType(fields.MoveType().GetUInt8());
    if (path.MoveType >= WaypointMoveType::Max)
    {
        TC_LOG_ERROR("sql.sql", "PathId {} in `waypoint_path` has invalid MoveType {}, ignoring", pathId, AsUnderlyingType(path.MoveType));
        return;
    }

    path.Id = pathId;
    path.Flags = WaypointPathFlags(fields.Flags().GetUInt8());
    path.Velocity = fields.Velocity().GetFloatOrNull();

    if (path.Velocity && *path.Velocity <= 0.0f)
    {
        TC_LOG_ERROR("sql.sql", "PathId {} in `waypoint_path` has invalid velocity {}, using default velocity instead", pathId, *path.Velocity);
        path.Velocity.reset();
    }

    path.Nodes.clear();
}

void WaypointMgr::LoadPathNodesFromDB(PathNodeQueryResult const& fields)
{
    uint32 pathId = fields.PathId().GetUInt32();

    WaypointPath* path = Trinity::Containers::MapGetValuePtr(_pathStore, pathId);
    if (!path)
    {
        TC_LOG_ERROR("sql.sql", "PathId {} in `waypoint_path_node` does not exist in `waypoint_path`, ignoring", pathId);
        return;
    }

    float x = fields.PositionX().GetFloat();
    float y = fields.PositionY().GetFloat();
    float z = fields.PositionZ().GetFloat();
    Optional<float> o = fields.Orientation().GetFloatOrNull();

    Optional<Milliseconds> delay;
    if (uint32 delayMs = fields.Delay().GetUInt32())
        delay.emplace(delayMs);

    Trinity::NormalizeMapCoord(x);
    Trinity::NormalizeMapCoord(y);

    path->Nodes.emplace_back(fields.NodeId().GetUInt32(), x, y, z, o, delay);
}

void WaypointMgr::DoPostLoadingChecks()
{
    for (auto& [pathId, pathInfo] : _pathStore)
    {
        pathInfo.BuildSegments();

        if (pathInfo.Nodes.empty())
            TC_LOG_ERROR("sql.sql", "PathId {} in `waypoint_path` has no assigned nodes in `waypoint_path_node`", pathInfo.Id);

        if (pathInfo.Flags.HasFlag(WaypointPathFlags::FollowPathBackwardsFromEndToStart) && pathInfo.Nodes.size() < WAYPOINT_PATH_FLAG_FOLLOW_PATH_BACKWARDS_MINIMUM_NODES)
            TC_LOG_ERROR("sql.sql", "PathId {} in `waypoint_path` has FollowPathBackwardsFromEndToStart set, but only {} nodes, requires {}", pathInfo.Id, pathInfo.Nodes.size(), WAYPOINT_PATH_FLAG_FOLLOW_PATH_BACKWARDS_MINIMUM_NODES);
    }
}

WaypointMgr* WaypointMgr::instance()
{
    static WaypointMgr instance;
    return &instance;
}

void WaypointMgr::ReloadPath(uint32 pathId)
{
    // waypoint_path
    {
        WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_PATH);
        stmt->setUInt32(0, pathId);
        stmt->setUInt32(1, 0);

        PreparedQueryResult result = WorldDatabase.Query(stmt);

        if (!result)
        {
            TC_LOG_ERROR("sql.sql", "PathId {} in `waypoint_path` not found, ignoring", pathId);
            return;
        }

        do
        {
            LoadPathFromDB(*result);
        } while (result->NextRow());
    }

    // waypoint_path_data
    {
        WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_PATH_NODE);
        stmt->setUInt32(0, pathId);
        stmt->setUInt32(1, 0);

        PreparedQueryResult result = WorldDatabase.Query(stmt);

        if (!result)
        {
            TC_LOG_ERROR("sql.sql", "PathId {} in `waypoint_path_node` not found, ignoring", pathId);
            return;
        }

        do
        {
            LoadPathNodesFromDB(*result);
        } while (result->NextRow());

        if (WaypointPath* path = Trinity::Containers::MapGetValuePtr(_pathStore, pathId))
            path->BuildSegments();
    }
}

void WaypointMgr::VisualizePath(Unit* owner, WaypointPath const* path, Optional<uint32> displayId)
{
    for (WaypointNode const& node : path->Nodes)
    {
        std::pair<uint32, uint32> pathNodePair(path->Id, node.Id);

        auto itr = _nodeToVisualWaypointGUIDsMap.find(pathNodePair);
        if (itr != _nodeToVisualWaypointGUIDsMap.end())
            continue;

        TempSummon* summon = owner->SummonCreature(VISUAL_WAYPOINT, node.X, node.Y, node.Z, node.Orientation ? *node.Orientation : 0.0f);
        if (!summon)
            continue;

        if (displayId)
        {
            summon->SetDisplayId(*displayId, true);
            summon->SetObjectScale(0.5f);
        }

        _nodeToVisualWaypointGUIDsMap[pathNodePair] = summon->GetGUID();
        _visualWaypointGUIDToNodeMap[summon->GetGUID()] = std::pair<WaypointPath const*, WaypointNode const*>(path, &node);
    }
}

void WaypointMgr::DevisualizePath(Unit* owner, WaypointPath const* path)
{
    for (WaypointNode const& node : path->Nodes)
    {
        std::pair<uint32, uint32> pathNodePair(path->Id, node.Id);
        auto itr = _nodeToVisualWaypointGUIDsMap.find(pathNodePair);
        if (itr == _nodeToVisualWaypointGUIDsMap.end())
            continue;

        Creature* creature = ObjectAccessor::GetCreature(*owner, itr->second);
        if (!creature)
            continue;

        _visualWaypointGUIDToNodeMap.erase(itr->second);
        _nodeToVisualWaypointGUIDsMap.erase(pathNodePair);

        creature->DespawnOrUnsummon();
    }
}

void WaypointMgr::MoveNode(WaypointPath const* path, WaypointNode const* node, Position const& pos)
{
    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_WAYPOINT_PATH_NODE_POSITION);
    stmt->setFloat(0, pos.GetPositionX());
    stmt->setFloat(1, pos.GetPositionY());
    stmt->setFloat(2, pos.GetPositionZ());
    stmt->setFloat(3, pos.GetOrientation());
    stmt->setUInt32(4, path->Id);
    stmt->setUInt32(5, node->Id);
    WorldDatabase.Execute(stmt);
}

void WaypointMgr::DeleteNode(WaypointPath const* path, WaypointNode const* node)
{
    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_WAYPOINT_PATH_NODE);
    stmt->setUInt32(0, path->Id);
    stmt->setUInt32(1, node->Id);
    WorldDatabase.Execute(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_WAYPOINT_PATH_NODE);
    stmt->setUInt32(0, path->Id);
    stmt->setUInt32(1, node->Id);
    WorldDatabase.Execute(stmt);
}

void WaypointMgr::DeleteNode(uint32 pathId, uint32 nodeId)
{
    WaypointPath const* path = GetPath(pathId);
    if (!path)
        return;

    WaypointNode const* node = GetNode(path, nodeId);
    if (!node)
        return;

    DeleteNode(path, node);
}

WaypointPath const* WaypointMgr::GetPath(uint32 pathId) const
{
    return Trinity::Containers::MapGetValuePtr(_pathStore, pathId);
}

WaypointNode const* WaypointMgr::GetNode(WaypointPath const* path, uint32 nodeId) const
{
    for (WaypointNode const& node : path->Nodes)
    {
        if (node.Id == nodeId)
            return &node;
    }
    return nullptr;
}

WaypointNode const* WaypointMgr::GetNode(uint32 pathId, uint32 nodeId) const
{
    WaypointPath const* path = GetPath(pathId);
    if (!path)
        return nullptr;

    return GetNode(path, nodeId);
}

WaypointPath const* WaypointMgr::GetPathByVisualGUID(ObjectGuid guid) const
{
    auto itr = _visualWaypointGUIDToNodeMap.find(guid);
    if (itr == _visualWaypointGUIDToNodeMap.end())
        return nullptr;

    return itr->second.first;
}

WaypointNode const* WaypointMgr::GetNodeByVisualGUID(ObjectGuid guid) const
{
    auto itr = _visualWaypointGUIDToNodeMap.find(guid);
    if (itr == _visualWaypointGUIDToNodeMap.end())
        return nullptr;

    return itr->second.second;
}

ObjectGuid const& WaypointMgr::GetVisualGUIDByNode(uint32 pathId, uint32 nodeId) const
{
    auto itr = _nodeToVisualWaypointGUIDsMap.find(std::make_pair(pathId, nodeId));
    if (itr == _nodeToVisualWaypointGUIDsMap.end())
        return ObjectGuid::Empty;

    return itr->second;
}

void WaypointPath::BuildSegments()
{
    ContinuousSegments.assign(1, { 0, 0 });
    for (std::size_t i = 0; i < Nodes.size(); ++i)
    {
        ++ContinuousSegments.back().second;

        // split on delay
        if (i + 1 != Nodes.size() && Nodes[i].Delay)
            ContinuousSegments.emplace_back(i, 1);
    }
}
