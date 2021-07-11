/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "WaypointManager.h"
#include "Database/DatabaseEnv.h"
#include "GridDefines.h"
#include "Policies/SingletonImp.h"
#include "ProgressBar.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"

INSTANTIATE_SINGLETON_1(WaypointManager);

void WaypointManager::Load()
{
    Cleanup();

    uint32 total_paths = 0;
    uint32 total_nodes = 0;
    uint32 total_behaviors = 0;

    std::set<uint32> movementScriptSet;

    for (const auto& itr : sCreatureMovementScripts)
        movementScriptSet.insert(itr.first);

    // /////////////////////////////////////////////////////
    // creature_movement
    // /////////////////////////////////////////////////////

    QueryResult* result = WorldDatabase.Query("SELECT `id`, COUNT(`point`) FROM `creature_movement` GROUP BY `id`");

    if (!result)
    {
        BarGoLink bar(1);
        bar.step();
        sLog.outString();
        sLog.outString(">> Loaded 0 paths. DB table `creature_movement` is empty.");
    }
    else
    {
        total_paths = (uint32)result->GetRowCount();
        BarGoLink bar(total_paths);

        do
        {
            bar.step();
            Field* fields = result->Fetch();

            // uint32 id    = fields[0].GetUInt32();
            uint32 count = fields[1].GetUInt32();

            total_nodes += count;
        }
        while (result->NextRow());

        sLog.outString();
        sLog.outString(">> Paths loaded");

        delete result;

        //                                    0     1        2             3             4             5           6                  7            8
        result = WorldDatabase.Query("SELECT `id`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `wander_distance`, `script_id`, `orientation` FROM `creature_movement`");

        BarGoLink barRow((int)result->GetRowCount());

        // error after load, we check if creature guid corresponding to the path id has proper MovementType
        std::set<uint32> creatureNoMoveType;

        do
        {
            barRow.step();
            Field* fields = result->Fetch();
            uint32 id           = fields[0].GetUInt32();
            uint32 point        = fields[1].GetUInt32();
            uint32 script_id    = fields[7].GetUInt32();

            if (script_id)
            {
                if (sCreatureMovementScripts.find(script_id) == sCreatureMovementScripts.end())
                {
                    sLog.outErrorDb("Table creature_movement for id %u, point %u have script_id %u that does not exist in `creature_movement_scripts`, ignoring", id, point, script_id);
                    continue;
                }

                movementScriptSet.erase(script_id);
            }

            CreatureData const* cData = sObjectMgr.GetCreatureData(id);

            if (!cData)
            {
                if (!sObjectMgr.IsExistingCreatureGuid(id))
                    sLog.outErrorDb("Table creature_movement contain path for creature guid %u, but this creature guid does not exist. Skipping.", id);
                continue;
            }

            if (cData->movement_type != WAYPOINT_MOTION_TYPE)
                creatureNoMoveType.insert(id);

            WaypointPath &path  = m_pathMap[id];

            // the cleanup queries make sure the following is true
            MANGOS_ASSERT(point >= 1);

            WaypointNode &node  = path[point - 1];

            node.x              = fields[2].GetFloat();
            node.y              = fields[3].GetFloat();
            node.z              = fields[4].GetFloat();
            node.orientation    = fields[8].GetFloat();
            node.delay          = fields[5].GetUInt32();
            node.wander_distance = fields[6].GetFloat();
            node.script_id      = fields[7].GetUInt32();

            // prevent using invalid coordinates
            if (!MaNGOS::IsValidMapCoord(node.x, node.y, node.z, node.orientation == 100.0f ? 0.0f : node.orientation))
            {
                QueryResult* result1 = WorldDatabase.PQuery("SELECT `id`, `map` FROM `creature` WHERE `guid` = '%u'", id);
                if (result1)
                    sLog.outErrorDb("Creature (guidlow %d, entry %d) have invalid coordinates in his waypoint %d (X: %f, Y: %f).",
                                    id, result1->Fetch()[0].GetUInt32(), point, node.x, node.y);
                else
                    sLog.outErrorDb("Waypoint path %d, have invalid coordinates in his waypoint %d (X: %f, Y: %f).",
                                    id, point, node.x, node.y);

                MaNGOS::NormalizeMapCoord(node.x);
                MaNGOS::NormalizeMapCoord(node.y);

                if (result1)
                {
                    node.z = sTerrainMgr.LoadTerrain(result1->Fetch()[1].GetUInt32())->GetHeightStatic(node.x, node.y, node.z);
                    delete result1;
                }

                WorldDatabase.PExecute("UPDATE `creature_movement` SET `position_x` = '%f', `position_y` = '%f', `position_z` = '%f' WHERE `id` = '%u' AND `point` = '%u'", node.x, node.y, node.z, id, point);
            }
        }
        while (result->NextRow());

        if (!creatureNoMoveType.empty())
        {
            for (const auto itr : creatureNoMoveType)
            {
                CreatureData const* cData = sObjectMgr.GetCreatureData(itr);
                CreatureInfo const* cInfo = ObjectMgr::GetCreatureTemplate(cData->creature_id[0]);

                ERROR_DB_STRICT_LOG("Table creature_movement has waypoint for creature guid %u (entry %u), but MovementType is not WAYPOINT_MOTION_TYPE(2). Make sure that this is actually used in a script!", itr, cData->creature_id[0]);

                if (cInfo->movement_type == WAYPOINT_MOTION_TYPE)
                    sLog.outErrorDb("    creature_template for this entry has MovementType WAYPOINT_MOTION_TYPE(2), did you intend to use creature_movement_template ?");
            }
        }

        sLog.outString();
        sLog.outString(">> Waypoints and behaviors loaded");
        sLog.outString();
        sLog.outString(">>> Loaded %u paths, %u nodes and %u behaviors", total_paths, total_nodes, total_behaviors);

        delete result;
    }

    // /////////////////////////////////////////////////////
    // creature_movement_template
    // /////////////////////////////////////////////////////

    result = WorldDatabase.Query("SELECT `entry`, COUNT(`point`) FROM `creature_movement_template` GROUP BY `entry`");

    if (!result)
    {
        BarGoLink bar(1);
        bar.step();
        sLog.outString();
        sLog.outString(">> Loaded 0 path templates. DB table `creature_movement_template` is empty.");
    }
    else
    {
        total_nodes = 0;
        total_behaviors = 0;
        total_paths = (uint32)result->GetRowCount();
        BarGoLink barRow(total_paths);

        do
        {
            barRow.step();
            Field* fields = result->Fetch();

            // uint32 entry = fields[0].GetUInt32();
            uint32 count = fields[1].GetUInt32();

            total_nodes += count;
        }
        while (result->NextRow());

        delete result;

        sLog.outString();
        sLog.outString(">> Path templates loaded");

        //                                    0        1        2             3             4             5           6                  7            8
        result = WorldDatabase.Query("SELECT `entry`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `wander_distance`, `script_id`, `orientation` FROM `creature_movement_template`");

        BarGoLink bar(result->GetRowCount());

        do
        {
            bar.step();
            Field* fields = result->Fetch();

            uint32 entry        = fields[0].GetUInt32();
            uint32 point        = fields[1].GetUInt32();
            uint32 script_id    = fields[7].GetUInt32();

            if (script_id)
            {
                if (sCreatureMovementScripts.find(script_id) == sCreatureMovementScripts.end())
                {
                    sLog.outErrorDb("Table creature_movement_template for entry %u, point %u have script_id %u that does not exist in `creature_movement_scripts`, ignoring", entry, point, script_id);
                    continue;
                }

                movementScriptSet.erase(script_id);
            }

            CreatureInfo const* cInfo = ObjectMgr::GetCreatureTemplate(entry);

            if (!cInfo)
            {
                if (!sObjectMgr.IsExistingCreatureId(entry))
                    sLog.outErrorDb("Table creature_movement_template references unknown creature template %u. Skipping.", entry);
                continue;
            }

            WaypointPath &path  = m_pathTemplateMap[entry << 8];

            // the cleanup queries make sure the following is true
            MANGOS_ASSERT(point >= 1);

            WaypointNode &node  = path[point - 1];

            node.x              = fields[2].GetFloat();
            node.y              = fields[3].GetFloat();
            node.z              = fields[4].GetFloat();
            node.orientation    = fields[8].GetFloat();
            node.delay          = fields[5].GetUInt32();
            node.wander_distance = fields[6].GetFloat();
            node.script_id      = fields[7].GetUInt32();

            // prevent using invalid coordinates
            if (!MaNGOS::IsValidMapCoord(node.x, node.y, node.z, node.orientation == 100.0f ? 0.0f : node.orientation))
            {
                sLog.outErrorDb("Table creature_movement_template for entry %u (point %u) are using invalid coordinates position_x: %f, position_y: %f)",
                                entry, point, node.x, node.y);

                MaNGOS::NormalizeMapCoord(node.x);
                MaNGOS::NormalizeMapCoord(node.y);

                sLog.outErrorDb("Table creature_movement_template for entry %u (point %u) are auto corrected to normalized position_x=%f, position_y=%f",
                                entry, point, node.x, node.y);

                WorldDatabase.PExecute("UPDATE `creature_movement_template` SET `position_x` = '%f', `position_y` = '%f' WHERE `entry` = %u AND `point` = %u", node.x, node.y, entry, point);
            }
        }
        while (result->NextRow());

        delete result;

        sLog.outString();
        sLog.outString(">> Waypoint templates loaded");
        sLog.outString();
        sLog.outString(">>> Loaded %u path templates with %u nodes and %u behaviors", total_paths, total_nodes, total_behaviors);
    }

    // /////////////////////////////////////////////////////
    // creature_movement_special
    // /////////////////////////////////////////////////////

    result = WorldDatabase.Query("SELECT `id`, COUNT(`point`) FROM `creature_movement_special` GROUP BY `id`");

    if (!result)
    {
        BarGoLink bar(1);
        bar.step();
        sLog.outString();
        sLog.outString(">> Loaded 0 paths. DB table `creature_movement_special` is empty.");
    }
    else
    {
        total_nodes = 0;
        total_behaviors = 0;
        total_paths = (uint32)result->GetRowCount();
        BarGoLink bar(total_paths);

        do
        {
            bar.step();
            Field* fields = result->Fetch();

            // uint32 id    = fields[0].GetUInt32();
            uint32 count = fields[1].GetUInt32();

            total_nodes += count;
        }
        while (result->NextRow());

        sLog.outString();
        sLog.outString(">> Paths loaded");

        delete result;

        //                                    0     1        2             3             4             5           6                  7            8
        result = WorldDatabase.Query("SELECT `id`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `wander_distance`, `script_id`, `orientation` FROM `creature_movement_special`");

        BarGoLink barRow((int)result->GetRowCount());

        do
        {
            barRow.step();
            Field* fields = result->Fetch();
            uint32 id           = fields[0].GetUInt32();
            uint32 point        = fields[1].GetUInt32();
            uint32 script_id    = fields[7].GetUInt32();

            if (script_id)
            {
                if (sCreatureMovementScripts.find(script_id) == sCreatureMovementScripts.end())
                {
                    sLog.outErrorDb("Table creature_movement_special for id %u, point %u have script_id %u that does not exist in `creature_movement_scripts`, ignoring", id, point, script_id);
                    continue;
                }

                movementScriptSet.erase(script_id);
            }

            WaypointPath &path  = m_pathSpecialMap[id];

            // the cleanup queries make sure the following is true
            MANGOS_ASSERT(point >= 1);

            WaypointNode &node  = path[point - 1];

            node.x              = fields[2].GetFloat();
            node.y              = fields[3].GetFloat();
            node.z              = fields[4].GetFloat();
            node.orientation    = fields[8].GetFloat();
            node.delay          = fields[5].GetUInt32();
            node.wander_distance = fields[6].GetFloat();
            node.script_id      = fields[7].GetUInt32();

            // prevent using invalid coordinates
            if (!MaNGOS::IsValidMapCoord(node.x, node.y, node.z, node.orientation == 100.0f ? 0.0f : node.orientation))
            {
                sLog.outErrorDb("Table creature_movement_special for Id %u (point %u) are using invalid coordinates position_x: %f, position_y: %f)",
                    id, point, node.x, node.y);

                MaNGOS::NormalizeMapCoord(node.x);
                MaNGOS::NormalizeMapCoord(node.y);

                sLog.outErrorDb("Table creature_movement_special for Id %u (point %u) are auto corrected to normalized position_x=%f, position_y=%f",
                    id, point, node.x, node.y);

                WorldDatabase.PExecute("UPDATE `creature_movement_special` SET `position_x` = '%f', `position_y` = '%f' WHERE `id` = %u AND `point` = %u", node.x, node.y, id, point);
            }
        }
        while (result->NextRow());

        sLog.outString();
        sLog.outString(">> Special waypoints loaded");
        sLog.outString();
        sLog.outString(">>> Loaded %u paths, %u nodes and %u behaviors", total_paths, total_nodes, total_behaviors);

        delete result;
    }

    if (!movementScriptSet.empty())
    {
        for (const auto itr : movementScriptSet)
            sLog.outErrorDb("Table `creature_movement_scripts` contain unused script, id %u.", itr);
    }
}

void WaypointManager::Cleanup()
{
    // check if points need to be renumbered and do it
    if (QueryResult* result = WorldDatabase.Query("SELECT 1 from `creature_movement` As T WHERE `point` <> (SELECT COUNT(*) FROM `creature_movement` WHERE `id` = T.`id` AND `point` <= T.`point`) LIMIT 1"))
    {
        delete result;
        WorldDatabase.DirectExecute("CREATE TEMPORARY TABLE `temp` LIKE `creature_movement`");
        WorldDatabase.DirectExecute("INSERT INTO `temp` SELECT * FROM `creature_movement`");
        WorldDatabase.DirectExecute("ALTER TABLE `creature_movement` DROP PRIMARY KEY");
        WorldDatabase.DirectExecute("UPDATE `creature_movement` AS T SET `point` = (SELECT COUNT(*) FROM `temp` WHERE `id` = T.`id` AND `point` <= T.`point`)");
        WorldDatabase.DirectExecute("ALTER TABLE `creature_movement` ADD PRIMARY KEY (`id`, `point`)");
        WorldDatabase.DirectExecute("DROP TABLE `temp`");

        sLog.outErrorDb("Table `creature_movement` was auto corrected for using points out of order (invalid or points missing)");

        MANGOS_ASSERT(!(result = WorldDatabase.Query("SELECT 1 from `creature_movement` As T WHERE `point` <> (SELECT COUNT(*) FROM `creature_movement` WHERE `id` = T.`id` AND `point` <= T.`point`) LIMIT 1")));
    }

    if (QueryResult* result = WorldDatabase.Query("SELECT 1 from `creature_movement_template` As T WHERE `point` <> (SELECT COUNT(*) FROM `creature_movement_template` WHERE `entry` = T.`entry` AND `point` <= T.`point`) LIMIT 1"))
    {
        delete result;
        WorldDatabase.DirectExecute("CREATE TEMPORARY TABLE `temp` LIKE `creature_movement_template`");
        WorldDatabase.DirectExecute("INSERT INTO `temp` SELECT * FROM `creature_movement_template`");
        WorldDatabase.DirectExecute("ALTER TABLE `creature_movement_template` DROP PRIMARY KEY");
        WorldDatabase.DirectExecute("UPDATE `creature_movement_template` AS T SET `point` = (SELECT COUNT(*) FROM `temp` WHERE `entry` = T.`entry` AND `point` <= T.`point`)");
        WorldDatabase.DirectExecute("ALTER TABLE `creature_movement_template` ADD PRIMARY KEY (`entry`, `point`)");
        WorldDatabase.DirectExecute("DROP TABLE `temp`");

        sLog.outErrorDb("Table `creature_movement_template` was auto corrected for using points out of order (invalid or points missing)");

        MANGOS_ASSERT(!(result = WorldDatabase.Query("SELECT 1 from `creature_movement_template` As T WHERE `point` <> (SELECT COUNT(*) FROM `creature_movement_template` WHERE `entry` = T.`entry` AND `point` <= T.`point`) LIMIT 1")));
    }

    if (QueryResult* result = WorldDatabase.Query("SELECT 1 from `creature_movement_special` As T WHERE `point` <> (SELECT COUNT(*) FROM `creature_movement_special` WHERE `id` = T.`id` AND `point` <= T.`point`) LIMIT 1"))
    {
        delete result;
        WorldDatabase.DirectExecute("CREATE TEMPORARY TABLE `temp` LIKE `creature_movement_special`");
        WorldDatabase.DirectExecute("INSERT INTO `temp` SELECT * FROM `creature_movement_special`");
        WorldDatabase.DirectExecute("ALTER TABLE `creature_movement_special` DROP PRIMARY KEY");
        WorldDatabase.DirectExecute("UPDATE `creature_movement_special` AS T SET `point` = (SELECT COUNT(*) FROM `temp` WHERE `id` = T.`id` AND `point` <= T.`point`)");
        WorldDatabase.DirectExecute("ALTER TABLE `creature_movement_special` ADD PRIMARY KEY (`id`, `point`)");
        WorldDatabase.DirectExecute("DROP TABLE `temp`");

        sLog.outErrorDb("Table `creature_movement_special` was auto corrected for using points out of order (invalid or points missing)");

        MANGOS_ASSERT(!(result = WorldDatabase.Query("SELECT 1 from `creature_movement_special` As T WHERE `point` <> (SELECT COUNT(*) FROM `creature_movement_special` WHERE `id` = T.`id` AND `point` <= T.`point`) LIMIT 1")));
    }
}

void WaypointManager::Unload()
{
    for (auto& itr : m_pathMap)
        _clearPath(itr.second);
    m_pathMap.clear();

    for (auto& itr : m_pathTemplateMap)
        _clearPath(itr.second);
    m_pathTemplateMap.clear();

    for (auto& itr : m_pathSpecialMap)
        _clearPath(itr.second);
    m_pathSpecialMap.clear();
}

void WaypointManager::_clearPath(WaypointPath &path)
{
    path.clear();
}

/// - Insert at a certain point, if pointId == 0 insert last. In this case pointId will be changed to the id to which the node was added
WaypointNode const* WaypointManager::AddNode(uint32 entry, uint32 dbGuid, uint32& pointId, WaypointPathOrigin wpDest, float x, float y, float z)
{
    // Support only normal movement tables
    if (wpDest != PATH_FROM_GUID && wpDest != PATH_FROM_ENTRY)
        return nullptr;

    // Prepare information
    char const* const table = wpDest == PATH_FROM_GUID ? "creature_movement" : "creature_movement_template";
    char const* const key_field = wpDest == PATH_FROM_GUID ? "id" : "entry";
    uint32 key = wpDest == PATH_FROM_GUID ? dbGuid : ((entry << 8) /*+ pathId*/);
    uint32 keydb = wpDest == PATH_FROM_GUID ? dbGuid : entry;
    WaypointPathMap* wpMap = wpDest == PATH_FROM_GUID ? &m_pathMap : &m_pathTemplateMap;

    WaypointPath& path = (*wpMap)[key];

    if (pointId == 0 && !path.empty())                      // Start with highest waypoint
        pointId = path.rbegin()->first + 1;

    uint32 nextPoint = pointId;
    WaypointNode temp = WaypointNode(x, y, z, 100, 0, 0, 0);
    WaypointPath::iterator find = path.find(nextPoint);
    if (find != path.end())                                 // Point already exists
    {
        do                                                  // Move points along until a free spot is found
        {
            std::swap(temp, find->second);
            ++find;
            ++nextPoint;
        } while (find != path.end() && find->first == nextPoint);
        // After this, we have:
        // pointId, pointId+1, ..., nextPoint [ Can be == path.end ]]
    }

    // Insert new or remaining
    path[nextPoint] = temp;

    // Update original waypoints
    for (WaypointPath::reverse_iterator rItr = path.rbegin(); rItr != path.rend() && rItr->first > pointId; ++rItr)
    {
        if (rItr->first <= nextPoint)
            WorldDatabase.PExecuteLog("UPDATE %s SET point=point+1 WHERE %s=%u AND point=%u", table, key_field, keydb, rItr->first - 1);
    }
    // Insert new Point to database
    WorldDatabase.PExecuteLog("INSERT INTO %s (%s,point,position_x,position_y,position_z,orientation) VALUES (%u,%u, %f,%f,%f, 100)", table, key_field, keydb, pointId+1, x, y, z);

    return &path[pointId];
}

void WaypointManager::DeleteNode(uint32 entry, uint32 dbGuid, uint32 point, int32 pathId, WaypointPathOrigin wpOrigin)
{
    // Support only normal movement tables
    if (wpOrigin != PATH_FROM_GUID && wpOrigin != PATH_FROM_ENTRY)
        return;

    WaypointPath* path = GetPathFromOrigin(entry, dbGuid, pathId, wpOrigin);
    if (!path)
        return;

    char const* const table = wpOrigin == PATH_FROM_GUID ? "creature_movement" : "creature_movement_template";
    char const* const key_field = wpOrigin == PATH_FROM_GUID ? "id" : "entry";
    uint32 const key = wpOrigin == PATH_FROM_GUID ? dbGuid : entry;
    WorldDatabase.PExecuteLog("DELETE FROM %s WHERE %s=%u AND point=%u", table, key_field, key, point+1);

    path->erase(point);
}

void WaypointManager::DeletePath(uint32 id)
{
    WorldDatabase.PExecuteLog("DELETE FROM creature_movement WHERE id=%u", id);
    WaypointPathMap::iterator itr = m_pathMap.find(id);
    if (itr != m_pathMap.end())
        _clearPath(itr->second);
    // the path is not removed from the map, just cleared
    // WMGs have pointers to the path, so deleting them would crash
    // this wastes some memory, but these functions are
    // only meant to be called by GM commands
}

void WaypointManager::SetNodePosition(uint32 entry, uint32 dbGuid, uint32 point, int32 pathId, WaypointPathOrigin wpOrigin, float x, float y, float z)
{
    // Support only normal movement tables
    if (wpOrigin != PATH_FROM_GUID && wpOrigin != PATH_FROM_ENTRY)
    {
        return;
    }

    WaypointPath* path = GetPathFromOrigin(entry, dbGuid, pathId, wpOrigin);
    if (!path)
    {
        return;
    }

    char const* const table = wpOrigin == PATH_FROM_GUID ? "creature_movement" : "creature_movement_template";
    char const* const key_field = wpOrigin == PATH_FROM_GUID ? "id" : "entry";
    uint32 const key = wpOrigin == PATH_FROM_GUID ? dbGuid : entry;
    WorldDatabase.PExecuteLog("UPDATE %s SET position_x=%f, position_y=%f, position_z=%f WHERE %s=%u AND point=%u", table, x, y, z, key_field, key, point+1);

    WaypointPath::iterator find = path->find(point);
    if (find != path->end())
    {
        find->second.x = x;
        find->second.y = y;
        find->second.z = z;
    }
}

void WaypointManager::SetNodeWaittime(uint32 entry, uint32 dbGuid, uint32 point, int32 pathId, WaypointPathOrigin wpOrigin, uint32 waittime)
{
    // Support only normal movement tables
    if (wpOrigin != PATH_FROM_GUID && wpOrigin != PATH_FROM_ENTRY)
        return;

    WaypointPath* path = GetPathFromOrigin(entry, dbGuid, pathId, wpOrigin);
    if (!path)
        return;

    char const* const table = wpOrigin == PATH_FROM_GUID ? "creature_movement" : "creature_movement_template";
    char const* const key_field = wpOrigin == PATH_FROM_GUID ? "id" : "entry";
    uint32 const key = wpOrigin == PATH_FROM_GUID ? dbGuid : entry;
    WorldDatabase.PExecuteLog("UPDATE %s SET waittime=%u WHERE %s=%u AND point=%u", table, waittime, key_field, key, point+1);

    WaypointPath::iterator find = path->find(point);
    if (find != path->end())
        find->second.delay = waittime;
}

void WaypointManager::SetNodeOrientation(uint32 entry, uint32 dbGuid, uint32 point, int32 pathId, WaypointPathOrigin wpOrigin, float orientation)
{
    // Support only normal movement tables
    if (wpOrigin != PATH_FROM_GUID && wpOrigin != PATH_FROM_ENTRY)
        return;

    WaypointPath* path = GetPathFromOrigin(entry, dbGuid, pathId, wpOrigin);
    if (!path)
        return;

    char const* const table = wpOrigin == PATH_FROM_GUID ? "creature_movement" : "creature_movement_template";
    char const* const key_field = wpOrigin == PATH_FROM_GUID ? "id" : "entry";
    uint32 const key = wpOrigin == PATH_FROM_GUID ? dbGuid : entry;
    WorldDatabase.PExecuteLog("UPDATE %s SET orientation=%f WHERE %s=%u AND point=%u", table, orientation, key_field, key, point+1);

    WaypointPath::iterator find = path->find(point);
    if (find != path->end())
        find->second.orientation = orientation;
}

/// return true if a valid scriptId is provided
bool WaypointManager::SetNodeScriptId(uint32 entry, uint32 dbGuid, uint32 point, int32 pathId, WaypointPathOrigin wpOrigin, uint32 scriptId)
{
    // Support only normal movement tables
    if (wpOrigin != PATH_FROM_GUID && wpOrigin != PATH_FROM_ENTRY)
        return false;

    WaypointPath* path = GetPathFromOrigin(entry, dbGuid, pathId, wpOrigin);
    if (!path)
        return false;

    char const* const table = wpOrigin == PATH_FROM_GUID ? "creature_movement" : "creature_movement_template";
    char const* const key_field = wpOrigin == PATH_FROM_GUID ? "id" : "entry";
    uint32 const key = wpOrigin == PATH_FROM_GUID ? dbGuid : entry;
    WorldDatabase.PExecuteLog("UPDATE %s SET script_id=%u WHERE %s=%u AND point=%u", table, scriptId, key_field, key, point+1);

    WaypointPath::iterator find = path->find(point);
    if (find != path->end())
        find->second.script_id = scriptId;

    return sCreatureMovementScripts.find(scriptId) != sCreatureMovementScripts.end();
}
