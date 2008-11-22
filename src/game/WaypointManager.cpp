/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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

#include "Database/DatabaseEnv.h"
#include "GridDefines.h"
#include "Policies/SingletonImp.h"
#include "WaypointManager.h"
#include "ProgressBar.h"
#include "MapManager.h"
#include "ObjectMgr.h"

INSTANTIATE_SINGLETON_1(WaypointManager);

bool WaypointBehavior::isEmpty()
{
    if (emote || spell || model1 || model2)
        return false;

    for(int i = 0; i < MAX_WAYPOINT_TEXT; ++i)
        if(textid[i])
            return false;

    return true;
}

WaypointBehavior::WaypointBehavior(const WaypointBehavior &b)
{
    emote = b.emote;
    spell = b.spell;
    model1 = b.model1;
    model2 = b.model2;
    for(int i=0; i < MAX_WAYPOINT_TEXT; ++i)
        textid[i] = b.textid[i];
}

void WaypointManager::Load()
{
    Cleanup();

    uint32 total_paths = 0;
    uint32 total_nodes = 0;
    uint32 total_behaviors = 0;

    QueryResult *result = WorldDatabase.Query("SELECT id, COUNT(point) FROM creature_movement GROUP BY id");
    if(result)
    {
        total_paths = result->GetRowCount();
        barGoLink bar( total_paths );
        do
        {
            Field *fields = result->Fetch();
            uint32 id    = fields[0].GetUInt32();
            uint32 count = fields[1].GetUInt32();
            m_pathMap[id].resize(count);

            total_nodes += count;
            bar.step();
        } while( result->NextRow() );
        delete result;
    }

    result = WorldDatabase.Query("SELECT position_x, position_y, position_z, orientation, model1, model2, waittime, emote, spell, textid1, textid2, textid3, textid4, textid5, id, point FROM creature_movement");
    if(result)
    {
        barGoLink bar( result->GetRowCount() );
        do
        {
            Field *fields = result->Fetch();
            uint32 point        = fields[15].GetUInt32();
            uint32 id           = fields[14].GetUInt32();

            WaypointPath &path  = m_pathMap[id];
            // the cleanup queries make sure the following is true
            assert(point >= 1 && point <= path.size());
            WaypointNode &node  = path[point-1];

            node.x              = fields[0].GetFloat();
            node.y              = fields[1].GetFloat();
            node.z              = fields[2].GetFloat();
            node.orientation    = fields[3].GetFloat();
            node.delay          = fields[6].GetUInt16();

            // prevent using invalid coordinates
            if(!Trinity::IsValidMapCoord(node.x, node.y, node.z, node.orientation))
            {
                QueryResult *result1 = WorldDatabase.PQuery("SELECT id, map FROM creature WHERE guid = '%u'", id);
                if(result1)
                    sLog.outErrorDb("ERROR: Creature (guidlow %d, entry %d) have invalid coordinates in his waypoint %d (X: %f, Y: %f).",
                        id, result1->Fetch()[0].GetUInt32(), point, node.x, node.y);
                else
                    sLog.outErrorDb("ERROR: Waypoint path %d, have invalid coordinates in his waypoint %d (X: %f, Y: %f).",
                        id, point, node.x, node.y);

                Trinity::NormalizeMapCoord(node.x);
                Trinity::NormalizeMapCoord(node.y);
                if(result1)
                {
                    node.z = MapManager::Instance ().GetBaseMap(result1->Fetch()[1].GetUInt32())->GetHeight(node.x, node.y, node.z);
                    delete result1;
                }
                WorldDatabase.PExecute("UPDATE creature_movement SET position_x = '%f', position_y = '%f', position_z = '%f' WHERE id = '%u' AND point = '%u'", node.x, node.y, node.z, id, point);
            }

            WaypointBehavior be;
            be.model1           = fields[4].GetUInt32();
            be.model2           = fields[5].GetUInt32();
            be.emote            = fields[7].GetUInt32();
            be.spell            = fields[8].GetUInt32();

            for(int i = 0; i < MAX_WAYPOINT_TEXT; ++i)
            {
                be.textid[i]        = fields[9+i].GetUInt32();
                if(be.textid[i])
                {
                    if (be.textid[i] < MIN_DB_SCRIPT_STRING_ID || be.textid[i] >= MAX_DB_SCRIPT_STRING_ID)
                    {
                        sLog.outErrorDb( "Table `db_script_string` not have string id  %u", be.textid[i]);
                        continue;
                    }
                }
            }

            // save memory by not storing empty behaviors
            if(!be.isEmpty())
            {
                node.behavior   = new WaypointBehavior(be);
                ++total_behaviors;
            }
            else
                node.behavior   = NULL;
            bar.step();
        } while( result->NextRow() );
        delete result;
    }
    sLog.outString( ">> Loaded %u paths, %u nodes and %u behaviors", total_paths, total_nodes, total_behaviors);
}

void WaypointManager::Cleanup()
{
    // check if points need to be renumbered and do it
    if(QueryResult *result = WorldDatabase.Query("SELECT 1 from creature_movement As T WHERE point <> (SELECT COUNT(*) FROM creature_movement WHERE id = T.id AND point <= T.point) LIMIT 1"))
    {
        delete result;
        WorldDatabase.DirectExecute("CREATE TEMPORARY TABLE temp LIKE creature_movement");
        WorldDatabase.DirectExecute("INSERT INTO temp SELECT * FROM creature_movement");
        WorldDatabase.DirectExecute("ALTER TABLE creature_movement DROP PRIMARY KEY");
        WorldDatabase.DirectExecute("UPDATE creature_movement AS T SET point = (SELECT COUNT(*) FROM temp WHERE id = T.id AND point <= T.point)");
        WorldDatabase.DirectExecute("ALTER TABLE creature_movement ADD PRIMARY KEY (id, point)");
        WorldDatabase.DirectExecute("DROP TABLE temp");
        assert(!(result = WorldDatabase.Query("SELECT 1 from creature_movement As T WHERE point <> (SELECT COUNT(*) FROM creature_movement WHERE id = T.id AND point <= T.point) LIMIT 1")));
    }
}

void WaypointManager::Unload()
{
    for(WaypointPathMap::iterator itr = m_pathMap.begin(); itr != m_pathMap.end(); ++itr)
        _clearPath(itr->second);
    m_pathMap.clear();
}

void WaypointManager::_clearPath(WaypointPath &path)
{
    for(WaypointPath::iterator itr = path.begin(); itr != path.end(); ++itr)
        if(itr->behavior)
            delete itr->behavior;
    path.clear();
}

/// - Insert after the last point
void WaypointManager::AddLastNode(uint32 id, float x, float y, float z, float o, uint32 delay, uint32 wpGuid)
{
    _addNode(id, GetLastPoint(id, 0) + 1, x, y, z, o, delay, wpGuid);
}

/// - Insert after a certain point
void WaypointManager::AddAfterNode(uint32 id, uint32 point, float x, float y, float z, float o, uint32 delay, uint32 wpGuid)
{
    for(uint32 i = GetLastPoint(id, 0); i > point; i--)
        WorldDatabase.PExecuteLog("UPDATE creature_movement SET point=point+1 WHERE id='%u' AND point='%u'", id, i);

    _addNode(id, point + 1, x, y, z, o, delay, wpGuid);
}

/// - Insert without checking for collision
void WaypointManager::_addNode(uint32 id, uint32 point, float x, float y, float z, float o, uint32 delay, uint32 wpGuid)
{
    if(point == 0) return;                                  // counted from 1 in the DB
    WorldDatabase.PExecuteLog("INSERT INTO creature_movement (id,point,position_x,position_y,position_z,orientation,wpguid,waittime) VALUES ('%u','%u','%f', '%f', '%f', '%f', '%d', '%d')", id, point, x, y, z, o, wpGuid, delay);
    WaypointPathMap::iterator itr = m_pathMap.find(id);
    if(itr == m_pathMap.end())
        itr = m_pathMap.insert(WaypointPathMap::value_type(id, WaypointPath())).first;
    itr->second.insert(itr->second.begin() + (point - 1), WaypointNode(x, y, z, o, delay, NULL));
}

uint32 WaypointManager::GetLastPoint(uint32 id, uint32 default_notfound)
{
    uint32 point = default_notfound;
    /*QueryResult *result = WorldDatabase.PQuery( "SELECT MAX(point) FROM creature_movement WHERE id = '%u'", id);
    if( result )
    {
        point = (*result)[0].GetUInt32()+1;
        delete result;
    }*/
    WaypointPathMap::iterator itr = m_pathMap.find(id);
    if(itr != m_pathMap.end() && itr->second.size() != 0)
        point = itr->second.size();
    return point;
}

void WaypointManager::DeleteNode(uint32 id, uint32 point)
{
    if(point == 0) return;                                  // counted from 1 in the DB
    WorldDatabase.PExecuteLog("DELETE FROM creature_movement WHERE id='%u' AND point='%u'", id, point);
    WorldDatabase.PExecuteLog("UPDATE creature_movement SET point=point-1 WHERE id='%u' AND point>'%u'", id, point);
    WaypointPathMap::iterator itr = m_pathMap.find(id);
    if(itr != m_pathMap.end() && point <= itr->second.size())
        itr->second.erase(itr->second.begin() + (point-1));
}

void WaypointManager::DeletePath(uint32 id)
{
    WorldDatabase.PExecuteLog("DELETE FROM creature_movement WHERE id='%u'", id);
    WaypointPathMap::iterator itr = m_pathMap.find(id);
    if(itr != m_pathMap.end())
        _clearPath(itr->second);
    // the path is not removed from the map, just cleared
    // WMGs have pointers to the path, so deleting them would crash
    // this wastes some memory, but these functions are
    // only meant to be called by GM commands
}

void WaypointManager::SetNodePosition(uint32 id, uint32 point, float x, float y, float z)
{
    if(point == 0) return;                                  // counted from 1 in the DB
    WorldDatabase.PExecuteLog("UPDATE creature_movement SET position_x = '%f',position_y = '%f',position_z = '%f' where id = '%u' AND point='%u'", x, y, z, id, point);
    WaypointPathMap::iterator itr = m_pathMap.find(id);
    if(itr != m_pathMap.end() && point <= itr->second.size())
    {
        itr->second[point-1].x = x;
        itr->second[point-1].y = y;
        itr->second[point-1].z = z;
    }
}

void WaypointManager::SetNodeText(uint32 id, uint32 point, const char *text_field, const char *text)
{
    if(point == 0) return;                                  // counted from 1 in the DB
    if(!text_field) return;
    std::string field = text_field;
    WorldDatabase.escape_string(field);

    if(!text)
    {
        WorldDatabase.PExecuteLog("UPDATE creature_movement SET %s=NULL WHERE id='%u' AND point='%u'", field.c_str(), id, point);
    }
    else
    {
        std::string text2 = text;
        WorldDatabase.escape_string(text2);
        WorldDatabase.PExecuteLog("UPDATE creature_movement SET %s='%s' WHERE id='%u' AND point='%u'", field.c_str(), text2.c_str(), id, point);
    }

    WaypointPathMap::iterator itr = m_pathMap.find(id);
    if(itr != m_pathMap.end() && point <= itr->second.size())
    {
        WaypointNode &node = itr->second[point-1];
        if(!node.behavior) node.behavior = new WaypointBehavior();

//        if(field == "text1") node.behavior->text[0] = text ? text : "";
//        if(field == "text2") node.behavior->text[1] = text ? text : "";
//        if(field == "text3") node.behavior->text[2] = text ? text : "";
//        if(field == "text4") node.behavior->text[3] = text ? text : "";
//        if(field == "text5") node.behavior->text[4] = text ? text : "";
        if(field == "emote") node.behavior->emote   = text ? atoi(text) : 0;
        if(field == "spell") node.behavior->spell   = text ? atoi(text) : 0;
        if(field == "model1") node.behavior->model1 = text ? atoi(text) : 0;
        if(field == "model2") node.behavior->model2 = text ? atoi(text) : 0;
    }
}

void WaypointManager::CheckTextsExistance(std::set<int32>& ids)
{
    WaypointPathMap::iterator pmItr = m_pathMap.begin();
    for ( ; pmItr != m_pathMap.end(); ++pmItr)
    {
        for (int i = 0; i < pmItr->second.size(); ++i)
        {
            if (!pmItr->second[i].behavior)
                continue;

            // Now we check text existence and put all zero texts ids to the end of array

            // Counting leading zeros for futher textid shift
            int zeroCount = 0;
            for (int j = 0; j < MAX_WAYPOINT_TEXT; ++j)
            {
                if (!pmItr->second[i].behavior->textid[j])
                {
                    ++zeroCount;
                    continue;
                }
                else
                {
                    if (!objmgr.GetMangosStringLocale(pmItr->second[i].behavior->textid[j]))
                    {
                        sLog.outErrorDb("ERROR: Some waypoint has textid%u with not existing %u text.", j, pmItr->second[i].behavior->textid[j]);
                        pmItr->second[i].behavior->textid[j] = 0;
                        ++zeroCount;
                        continue;
                    }
                    else
                        ids.erase(pmItr->second[i].behavior->textid[j]);

                    // Shifting check
                    if (zeroCount)
                    {
                        // Correct textid but some zeros leading, so move it forward.
                        pmItr->second[i].behavior->textid[j-zeroCount] = pmItr->second[i].behavior->textid[j];
                        pmItr->second[i].behavior->textid[j] = 0;
                    }
                }
            }
        }
    }
}
