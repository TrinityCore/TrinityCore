/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "WorldDatabase.h"

void WorldDatabaseConnection::DoPrepareStatements()
{
    if (!m_reconnecting)
        m_stmts.resize(MAX_WORLDDATABASE_STATEMENTS);

    PREPARE_STATEMENT(WORLD_LOAD_QUEST_POOLS, "SELECT entry, pool_entry FROM pool_quest", CONNECTION_SYNCH)
    PREPARE_STATEMENT(WORLD_DEL_CRELINKED_RESPAWN, "DELETE FROM linked_respawn WHERE guid = ?", CONNECTION_ASYNC)
    PREPARE_STATEMENT(WORLD_REP_CRELINKED_RESPAWN, "REPLACE INTO linked_respawn (guid, linkedGuid) VALUES (?, ?)", CONNECTION_ASYNC)
    PREPARE_STATEMENT(WORLD_LOAD_CRETEXT, "SELECT entry, groupid, id, text, type, language, probability, emote, duration, sound FROM creature_text", CONNECTION_SYNCH)
    PREPARE_STATEMENT(WORLD_LOAD_SMART_SCRIPTS, "SELECT entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o FROM smart_scripts ORDER BY entryorguid, source_type, id, link", CONNECTION_SYNCH)
    PREPARE_STATEMENT(WORLD_LOAD_SMARTAI_WP, "SELECT entry, pointid, position_x, position_y, position_z FROM waypoints ORDER BY entry, pointid", CONNECTION_SYNCH)
    PREPARE_STATEMENT(WORLD_DEL_GAMEOBJECT, "DELETE FROM gameobject WHERE guid = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_DEL_EVENT_GAMEOBJECT, "DELETE FROM game_event_gameobject WHERE guid = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_INS_GRAVEYARD_ZONE, "INSERT INTO game_graveyard_zone (id, ghost_zone, faction) VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_DEL_GRAVEYARD_ZONE, "DELETE FROM game_graveyard_zone WHERE id = ? AND ghost_zone = ? AND faction = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_INS_GAME_TELE, "INSERT INTO game_tele (id, position_x, position_y, position_z, orientation, map, name) VALUES (?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_DEL_GAME_TELE, "DELETE FROM game_tele WHERE name = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_INS_NPC_VENODR, "INSERT INTO npc_vendor (entry, item, maxcount, incrtime, extendedcost) VALUES(?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_DEL_NPC_VENDOR, "DELETE FROM npc_vendor WHERE entry = ? AND item = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_UPD_CREATURE_MOVEMENT_TYPE, "UPDATE creature SET MovementType = ? WHERE guid = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_UPD_CREATURE_FACTION, "UPDATE creature_template SET faction_A = ?, faction_H = ? WHERE entry = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_UPD_CREATURE_NPCFLAG, "UPDATE creature_template SET npcflag = ? WHERE entry = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_UPD_CREATURE_POSITION, "UPDATE creature SET position_x = ?, position_y = ?, position_z = ?, orientation = ? WHERE guid = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_UPD_CREATURE_SPAWN_DISTANCE, "UPDATE creature SET spawndist = ?, MovementType = ? WHERE guid = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_UPD_CREATURE_SPAWN_TIME_SECS, "UPDATE creature SET spawntimesecs = ? WHERE guid = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_INS_CREATURE_FORMATION, "INSERT INTO creature_formations (leaderGUID, memberGUID, dist, angle, groupAI) VALUES (?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_INS_WAYPOINT_DATA, "INSERT INTO waypoint_data (id, point, position_x, position_y, position_z) VALUES (?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_DEL_WAYPOINT_DATA, "DELETE FROM waypoint_data WHERE id = ? AND point = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_UPD_WAYPOINT_DATA_POINT, "UPDATE waypoint_data SET point = point - 1 WHERE id = ? AND point > ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_UPD_WAYPOINT_DATA_POSITION, "UPDATE waypoint_data SET position_x = ?, position_y = ?, position_z = ? where id = ? AND point = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_UPD_WAYPOINT_DATA_WPGUID, "UPDATE waypoint_data SET wpguid = ? WHERE id = ? and point = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WOLRD_UPD_ALL_WAYPOINT_DATA_WPGUID, "UPDATE waypoint_data SET wpguid = 0", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_INS_CREATURE_ADDON, "INSERT INTO creature_addon(guid, path_id) VALUES (?, ?)", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_UPD_CREATURE_ADDON_PATH, "UPDATE creature_addon SET path_id = ? WHERE guid = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_DEL_CREATURE_ADDON, "DELETE FROM creature_addon WHERE guid = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_INS_WAYPOINT_SCRIPT, "INSERT INTO waypoint_scripts (guid) VALUES (?)", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_DEL_WAYPOINT_SCRIPT, "DELETE FROM waypoint_scripts WHERE guid = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_UPD_WAYPOINT_SCRIPT_ID, "UPDATE waypoint_scripts SET id = ? WHERE guid = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_UPD_WAYPOINT_SCRIPT_X, "UPDATE waypoint_scripts SET x = ? WHERE guid = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_UPD_WAYPOINT_SCRIPT_Y, "UPDATE waypoint_scripts SET y = ? WHERE guid = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_UPD_WAYPOINT_SCRIPT_Z, "UPDATE waypoint_scripts SET z = ? WHERE guid = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_UPD_WAYPOINT_SCRIPT_O, "UPDATE waypoint_scripts SET o = ? WHERE guid = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_DEL_CREATURE, "DELETE FROM creature WHERE guid = ?", CONNECTION_ASYNC);
}
