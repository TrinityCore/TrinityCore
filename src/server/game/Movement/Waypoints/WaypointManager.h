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

#ifndef TRINITY_WAYPOINTMANAGER_H
#define TRINITY_WAYPOINTMANAGER_H

#include "Define.h"
#include "Field.h"
#include "Hash.h"
#include "ObjectGuid.h"
#include "Position.h"
#include "WaypointDefines.h"
#include <unordered_map>

class Unit;

class TC_GAME_API WaypointMgr
{
    public:
        static WaypointMgr* instance();

        // Attempts to reload a single path from database
        void ReloadPath(uint32 pathId);

        // Loads all paths from database, should only run on startup
        void LoadPaths();
        void LoadPathFromDB(Field* fields);
        void LoadPathNodesFromDB(Field* fields);
        void DoPostLoadingChecks();

        void VisualizePath(Unit* owner, WaypointPath const* path, Optional<uint32> displayId);
        void DevisualizePath(Unit* owner, WaypointPath const* path);

        void MoveNode(WaypointPath const* path, WaypointNode const* node, Position const& pos);
        void DeleteNode(WaypointPath const* path, WaypointNode const* node);
        void DeleteNode(uint32 pathId, uint32 nodeId);

        WaypointPath const* GetPath(uint32 pathId) const;
        WaypointNode const* GetNode(WaypointPath const* path, uint32 nodeId) const;
        WaypointNode const* GetNode(uint32 pathId, uint32 nodeId) const;
        WaypointPath const* GetPathByVisualGUID(ObjectGuid guid) const;
        WaypointNode const* GetNodeByVisualGUID(ObjectGuid guid) const;
        ObjectGuid const& GetVisualGUIDByNode(uint32 pathId, uint32 nodeId) const;

    private:
        WaypointMgr() { }

        void _LoadPaths();
        void _LoadPathNodes();

        std::unordered_map<uint32 /*pathId*/, WaypointPath> _pathStore;

        std::unordered_map<std::pair<uint32 /*pathId*/, uint32 /*nodeId*/>, ObjectGuid> _nodeToVisualWaypointGUIDsMap;
        std::unordered_map<ObjectGuid, std::pair<WaypointPath const*, WaypointNode const*>> _visualWaypointGUIDToNodeMap;
};

#define sWaypointMgr WaypointMgr::instance()

#endif
