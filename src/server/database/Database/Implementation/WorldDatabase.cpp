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

#include "WorldDatabase.h"
#include "MySQLPreparedStatement.h"

void WorldDatabaseConnection::DoPrepareStatements()
{
    if (!m_reconnecting)
        m_stmts.resize(MAX_WORLDDATABASE_STATEMENTS);

    PrepareStatement(WORLD_DEL_LINKED_RESPAWN, "DELETE FROM linked_respawn WHERE guid = ? AND linkType  = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_LINKED_RESPAWN_MASTER, "DELETE FROM linked_respawn WHERE linkedGuid = ? AND linkType = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_REP_LINKED_RESPAWN, "REPLACE INTO linked_respawn (guid, linkedGuid, linkType) VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(WORLD_SEL_CREATURE_TEXT, "SELECT CreatureID, GroupID, ID, Text, Type, Language, Probability, Emote, Duration, Sound, SoundPlayType, BroadcastTextId, TextRange FROM creature_text", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_SMART_SCRIPTS, "SELECT entryorguid, source_type, id, link, Difficulties, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, event_param5, event_param_string, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, action_param7, target_type, target_param1, target_param2, target_param3, target_param4, target_x, target_y, target_z, target_o FROM smart_scripts ORDER BY entryorguid, source_type, id, link", CONNECTION_SYNCH);
    PrepareStatement(WORLD_DEL_GAMEOBJECT, "DELETE FROM gameobject WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_EVENT_GAMEOBJECT, "DELETE FROM game_event_gameobject WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_INS_GRAVEYARD_ZONE, "INSERT INTO graveyard_zone (ID, GhostZone) VALUES (?, ?)", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_GRAVEYARD_ZONE, "DELETE FROM graveyard_zone WHERE ID = ? AND GhostZone = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_INS_GAME_TELE, "INSERT INTO game_tele (id, position_x, position_y, position_z, orientation, map, name) VALUES (?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_GAME_TELE, "DELETE FROM game_tele WHERE name = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_INS_NPC_VENDOR, "INSERT INTO npc_vendor (entry, item, maxcount, incrtime, extendedcost, type) VALUES(?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_NPC_VENDOR, "DELETE FROM npc_vendor WHERE entry = ? AND item = ? AND type = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_SEL_NPC_VENDOR_REF, "SELECT item, maxcount, incrtime, ExtendedCost, type, BonusListIDs, PlayerConditionID, IgnoreFiltering FROM npc_vendor WHERE entry = ? ORDER BY slot ASC", CONNECTION_SYNCH);
    PrepareStatement(WORLD_UPD_CREATURE_MOVEMENT_TYPE, "UPDATE creature SET MovementType = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_UPD_CREATURE_FACTION, "UPDATE creature_template SET faction = ? WHERE entry = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_UPD_CREATURE_NPCFLAG, "UPDATE creature_template SET npcflag = ? WHERE entry = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_UPD_CREATURE_POSITION, "UPDATE creature SET position_x = ?, position_y = ?, position_z = ?, orientation = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_UPD_CREATURE_WANDER_DISTANCE, "UPDATE creature SET wander_distance = ?, MovementType = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_UPD_CREATURE_SPAWN_TIME_SECS, "UPDATE creature SET spawntimesecs = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_INS_CREATURE_FORMATION, "INSERT INTO creature_formations (leaderGUID, memberGUID, dist, angle, groupAI) VALUES (?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(WORLD_INS_WAYPOINT_DATA, "INSERT INTO waypoint_data (id, point, position_x, position_y, position_z, orientation) VALUES (?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_WAYPOINT_DATA, "DELETE FROM waypoint_data WHERE id = ? AND point = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_UPD_WAYPOINT_DATA_POINT, "UPDATE waypoint_data SET point = point - 1 WHERE id = ? AND point > ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_UPD_WAYPOINT_DATA_POSITION, "UPDATE waypoint_data SET position_x = ?, position_y = ?, position_z = ?, orientation = ? where id = ? AND point = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_SEL_WAYPOINT_DATA_MAX_ID, "SELECT MAX(id) FROM waypoint_data", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_WAYPOINT_DATA_MAX_POINT, "SELECT MAX(point) FROM waypoint_data WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_WAYPOINT_DATA_BY_ID, "SELECT point, position_x, position_y, position_z, orientation, move_type, delay FROM waypoint_data WHERE id = ? ORDER BY point", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_WAYPOINT_DATA_POS_BY_ID, "SELECT point, position_x, position_y, position_z, orientation FROM waypoint_data WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_WAYPOINT_DATA_POS_FIRST_BY_ID, "SELECT position_x, position_y, position_z, orientation FROM waypoint_data WHERE point = 1 AND id = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_WAYPOINT_DATA_POS_LAST_BY_ID, "SELECT position_x, position_y, position_z, orientation FROM waypoint_data WHERE id = ? ORDER BY point DESC LIMIT 1", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_WAYPOINT_DATA_BY_POS, "SELECT id, point FROM waypoint_data WHERE (abs(position_x - ?) <= ?) and (abs(position_y - ?) <= ?) and (abs(position_z - ?) <= ?)", CONNECTION_SYNCH);
    PrepareStatement(WORLD_INS_CREATURE_ADDON, "INSERT INTO creature_addon(guid, path_id) VALUES (?, ?)", CONNECTION_ASYNC);
    PrepareStatement(WORLD_UPD_CREATURE_ADDON_PATH, "UPDATE creature_addon SET path_id = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_CREATURE_ADDON, "DELETE FROM creature_addon WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_SEL_CREATURE_ADDON_BY_GUID, "SELECT guid FROM creature_addon WHERE guid = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_DEL_CREATURE, "DELETE FROM creature WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_SEL_COMMANDS, "SELECT name, help FROM command", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_CREATURE_TEMPLATE, "SELECT entry, KillCredit1, KillCredit2, name, femaleName, subname, TitleAlt, IconName, RequiredExpansion, VignetteID, faction, npcflag, speed_walk, speed_run, scale, `rank`, dmgschool, BaseAttackTime, RangeAttackTime, BaseVariance, RangeVariance, unit_class, unit_flags, unit_flags2, unit_flags3, family, trainer_class, type, VehicleId, AIName, MovementType, ctm.Ground, ctm.Swim, ctm.Flight, ctm.Rooted, ctm.Chase, ctm.Random, ctm.InteractionPauseTimer, ExperienceModifier, RacialLeader, movementId, WidgetSetID, WidgetSetUnitConditionID, RegenHealth, mechanic_immune_mask, spell_school_immune_mask, flags_extra, ScriptName, StringId FROM creature_template ct LEFT JOIN creature_template_movement ctm ON ct.entry = ctm.CreatureId WHERE entry = ? OR 1 = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_CREATURE_BY_ID, "SELECT guid FROM creature WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_GAMEOBJECT_NEAREST, "SELECT guid, id, position_x, position_y, position_z, map, (POW(position_x - ?, 2) + POW(position_y - ?, 2) + POW(position_z - ?, 2)) AS order_ FROM gameobject WHERE map = ? AND (POW(position_x - ?, 2) + POW(position_y - ?, 2) + POW(position_z - ?, 2)) <= ? ORDER BY order_", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_CREATURE_NEAREST, "SELECT guid, id, position_x, position_y, position_z, map, (POW(position_x - ?, 2) + POW(position_y - ?, 2) + POW(position_z - ?, 2)) AS order_ FROM creature WHERE map = ? AND (POW(position_x - ?, 2) + POW(position_y - ?, 2) + POW(position_z - ?, 2)) <= ? ORDER BY order_", CONNECTION_SYNCH);
    PrepareStatement(WORLD_INS_CREATURE, "INSERT INTO creature (guid, id , map, spawnDifficulties, PhaseId, PhaseGroup, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, wander_distance, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_GAME_EVENT_CREATURE, "DELETE FROM game_event_creature WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_GAME_EVENT_MODEL_EQUIP, "DELETE FROM game_event_model_equip WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_INS_GAMEOBJECT, "INSERT INTO gameobject (guid, id, map, spawnDifficulties, PhaseId, PhaseGroup, position_x, position_y, position_z, orientation, rotation0, rotation1, rotation2, rotation3, spawntimesecs, animprogress, state) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(WORLD_INS_DISABLES, "INSERT INTO disables (entry, sourceType, flags, comment) VALUES (?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(WORLD_SEL_DISABLES, "SELECT entry FROM disables WHERE entry = ? AND sourceType = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_DEL_DISABLES, "DELETE FROM disables WHERE entry = ? AND sourceType = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_UPD_CREATURE_ZONE_AREA_DATA, "UPDATE creature SET zoneId = ?, areaId = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_UPD_GAMEOBJECT_ZONE_AREA_DATA, "UPDATE gameobject SET zoneId = ?, areaId = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_SPAWNGROUP_MEMBER, "DELETE FROM spawn_group WHERE spawnType = ? AND spawnId = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_GAMEOBJECT_ADDON, "DELETE FROM gameobject_addon WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_SEL_GUILD_REWARDS_REQ_ACHIEVEMENTS, "SELECT AchievementRequired FROM guild_rewards_req_achievements WHERE ItemID = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_INS_CONDITION, "INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName, Comment) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
}

WorldDatabaseConnection::WorldDatabaseConnection(MySQLConnectionInfo& connInfo, ConnectionFlags connectionFlags) : MySQLConnection(connInfo, connectionFlags)
{
}

WorldDatabaseConnection::~WorldDatabaseConnection()
{
}
