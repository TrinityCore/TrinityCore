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
    PrepareStatement(WORLD_SEL_CREATURE_TEXT, "SELECT CreatureID, GroupID, ID, Text, Type, Language, Probability, Emote, Duration, Sound, BroadcastTextId, TextRange FROM creature_text", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_SMART_SCRIPTS, "SELECT entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, event_param5, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_param4, target_x, target_y, target_z, target_o FROM smart_scripts ORDER BY entryorguid, source_type, id, link", CONNECTION_SYNCH);
    PrepareStatement(WORLD_DEL_GAMEOBJECT, "DELETE FROM gameobject WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_EVENT_GAMEOBJECT, "DELETE FROM game_event_gameobject WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_INS_GRAVEYARD_ZONE, "INSERT INTO graveyard_zone (ID, GhostZone, Faction) VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_GRAVEYARD_ZONE, "DELETE FROM graveyard_zone WHERE ID = ? AND GhostZone = ? AND Faction = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_INS_GAME_TELE, "INSERT INTO game_tele (id, position_x, position_y, position_z, orientation, map, name) VALUES (?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_GAME_TELE, "DELETE FROM game_tele WHERE name = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_INS_NPC_VENDOR, "INSERT INTO npc_vendor (entry, item, maxcount, incrtime, extendedcost) VALUES(?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_NPC_VENDOR, "DELETE FROM npc_vendor WHERE entry = ? AND item = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_SEL_NPC_VENDOR_REF, "SELECT item, maxcount, incrtime, ExtendedCost FROM npc_vendor WHERE entry = ? ORDER BY slot ASC", CONNECTION_SYNCH);
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
    PrepareStatement(WORLD_UPD_WAYPOINT_DATA_WPGUID, "UPDATE waypoint_data SET wpguid = ? WHERE id = ? and point = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_SEL_WAYPOINT_DATA_MAX_ID, "SELECT MAX(id) FROM waypoint_data", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_WAYPOINT_DATA_MAX_POINT, "SELECT MAX(point) FROM waypoint_data WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_WAYPOINT_DATA_BY_ID, "SELECT point, position_x, position_y, position_z, orientation, move_type, delay, action, action_chance FROM waypoint_data WHERE id = ? ORDER BY point", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_WAYPOINT_DATA_POS_BY_ID, "SELECT point, position_x, position_y, position_z, orientation FROM waypoint_data WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_WAYPOINT_DATA_POS_FIRST_BY_ID, "SELECT position_x, position_y, position_z, orientation FROM waypoint_data WHERE point = 1 AND id = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_WAYPOINT_DATA_POS_LAST_BY_ID, "SELECT position_x, position_y, position_z, orientation FROM waypoint_data WHERE id = ? ORDER BY point DESC LIMIT 1", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_WAYPOINT_DATA_BY_WPGUID, "SELECT id, point FROM waypoint_data WHERE wpguid = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_WAYPOINT_DATA_ALL_BY_WPGUID, "SELECT id, point, delay, move_type, action, action_chance FROM waypoint_data WHERE wpguid = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_UPD_WAYPOINT_DATA_ALL_WPGUID, "UPDATE waypoint_data SET wpguid = 0", CONNECTION_ASYNC);
    PrepareStatement(WORLD_SEL_WAYPOINT_DATA_BY_POS, "SELECT id, point FROM waypoint_data WHERE (abs(position_x - ?) <= ?) and (abs(position_y - ?) <= ?) and (abs(position_z - ?) <= ?)", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_WAYPOINT_DATA_WPGUID_BY_ID, "SELECT wpguid FROM waypoint_data WHERE id = ? and wpguid <> 0", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_WAYPOINT_DATA_ACTION, "SELECT DISTINCT action FROM waypoint_data", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_WAYPOINT_SCRIPTS_MAX_ID, "SELECT MAX(guid) FROM waypoint_scripts", CONNECTION_SYNCH);
    PrepareStatement(WORLD_INS_CREATURE_ADDON, "INSERT INTO creature_addon(guid, path_id) VALUES (?, ?)", CONNECTION_ASYNC);
    PrepareStatement(WORLD_UPD_CREATURE_ADDON_PATH, "UPDATE creature_addon SET path_id = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_CREATURE_ADDON, "DELETE FROM creature_addon WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_SEL_CREATURE_ADDON_BY_GUID, "SELECT guid FROM creature_addon WHERE guid = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_INS_WAYPOINT_SCRIPT, "INSERT INTO waypoint_scripts (guid) VALUES (?)", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_WAYPOINT_SCRIPT, "DELETE FROM waypoint_scripts WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_UPD_WAYPOINT_SCRIPT_ID, "UPDATE waypoint_scripts SET id = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_UPD_WAYPOINT_SCRIPT_X, "UPDATE waypoint_scripts SET x = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_UPD_WAYPOINT_SCRIPT_Y, "UPDATE waypoint_scripts SET y = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_UPD_WAYPOINT_SCRIPT_Z, "UPDATE waypoint_scripts SET z = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_UPD_WAYPOINT_SCRIPT_O, "UPDATE waypoint_scripts SET o = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_SEL_WAYPOINT_SCRIPT_ID_BY_GUID, "SELECT id FROM waypoint_scripts WHERE guid = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_DEL_CREATURE, "DELETE FROM creature WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_SEL_COMMANDS, "SELECT name, help FROM command", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_CREATURE_TEMPLATE, "SELECT entry, difficulty_entry_1, difficulty_entry_2, difficulty_entry_3, KillCredit1, KillCredit2, modelid1, modelid2, modelid3, modelid4, name, subname, IconName, gossip_menu_id, minlevel, maxlevel, exp, faction, npcflag, speed_walk, speed_run, scale, `rank`, dmgschool, BaseAttackTime, RangeAttackTime, BaseVariance, RangeVariance, unit_class, unit_flags, unit_flags2, dynamicflags, family, type, type_flags, lootid, pickpocketloot, skinloot, PetSpellDataId, VehicleId, mingold, maxgold, AIName, MovementType, ctm.Ground, ctm.Swim, ctm.Flight, ctm.Rooted, ctm.Chase, ctm.Random, ctm.InteractionPauseTimer, HoverHeight, HealthModifier, ManaModifier, ArmorModifier, DamageModifier, ExperienceModifier, RacialLeader, movementId, RegenHealth, mechanic_immune_mask, spell_school_immune_mask, flags_extra, ScriptName, StringId FROM creature_template ct LEFT JOIN creature_template_movement ctm ON ct.entry = ctm.CreatureId WHERE entry = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_WAYPOINT_SCRIPT_BY_ID, "SELECT guid, delay, command, datalong, datalong2, dataint, x, y, z, o FROM waypoint_scripts WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_ITEM_TEMPLATE_BY_NAME, "SELECT entry FROM item_template WHERE name = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_ITEM_TEMPLATE_LOCALE_BY_NAME, "SELECT ID FROM item_template_locale WHERE Name = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_CREATURE_BY_ID, "SELECT guid FROM creature WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_GAMEOBJECT_NEAREST, "SELECT guid, id, position_x, position_y, position_z, map, (POW(position_x - ?, 2) + POW(position_y - ?, 2) + POW(position_z - ?, 2)) AS order_ FROM gameobject WHERE map = ? AND (POW(position_x - ?, 2) + POW(position_y - ?, 2) + POW(position_z - ?, 2)) <= ? ORDER BY order_", CONNECTION_SYNCH);
    PrepareStatement(WORLD_SEL_CREATURE_NEAREST, "SELECT guid, id, position_x, position_y, position_z, map, (POW(position_x - ?, 2) + POW(position_y - ?, 2) + POW(position_z - ?, 2)) AS order_ FROM creature WHERE map = ? AND (POW(position_x - ?, 2) + POW(position_y - ?, 2) + POW(position_z - ?, 2)) <= ? ORDER BY order_", CONNECTION_SYNCH);
    PrepareStatement(WORLD_INS_CREATURE, "INSERT INTO creature (guid, id , map, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, wander_distance, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_GAME_EVENT_CREATURE, "DELETE FROM game_event_creature WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_GAME_EVENT_MODEL_EQUIP, "DELETE FROM game_event_model_equip WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_INS_GAMEOBJECT, "INSERT INTO gameobject (guid, id, map, spawnMask, phaseMask, position_x, position_y, position_z, orientation, rotation0, rotation1, rotation2, rotation3, spawntimesecs, animprogress, state) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(WORLD_INS_DISABLES, "INSERT INTO disables (entry, sourceType, flags, comment) VALUES (?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(WORLD_SEL_DISABLES, "SELECT entry FROM disables WHERE entry = ? AND sourceType = ?", CONNECTION_SYNCH);
    PrepareStatement(WORLD_DEL_DISABLES, "DELETE FROM disables WHERE entry = ? AND sourceType = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_UPD_CREATURE_ZONE_AREA_DATA, "UPDATE creature SET zoneId = ?, areaId = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_UPD_GAMEOBJECT_ZONE_AREA_DATA, "UPDATE gameobject SET zoneId = ?, areaId = ? WHERE guid = ?", CONNECTION_ASYNC);
    // Milestone 2.12F4B2: AIWorld's own narrow, startup-only read of every
    // creature.guid whose stored zoneId matches a configured value
    // (FetchCreatureSpawnIdsForZone(), AIWorld/Reconciliation/
    // CreatureSpawnZoneFilter.cpp) - reads the column WORLD_UPD_CREATURE_
    // ZONE_AREA_DATA above writes, never computes zone/area itself
    // (Map::GetZoneAndAreaId() would need a live Map*/vmap data). P3 fix
    // (STATIC review): a never-recalculated/new row commonly reads as
    // zoneId = 0 and is excluded, but a STALE row (calculated once, then
    // moved/re-scoped without a fresh recalculation) may still carry an
    // old, nonzero zoneId - freshly recalculating for the CURRENT
    // creature table state is the actual precondition, not just "zoneId
    // is populated".
    PrepareStatement(WORLD_SEL_CREATURE_GUIDS_BY_ZONE, "SELECT guid FROM creature WHERE zoneId = ?", CONNECTION_SYNCH);

    // AI WorldFactionCatalog's own startup-only bulk read of the whole
    // creature_entry -> WorldFactionId default table (data/elwynn/factions/
    // README.md's own generated output) - one query, not one per
    // CreatureEntry.
    PrepareStatement(WORLD_SEL_AI_WORLD_FACTION_ENTRY_DEFAULTS, "SELECT creature_entry, world_faction_id FROM ai_world_faction_entry_defaults", CONNECTION_SYNCH);

    // AI AgentTypeCatalog's own startup-only bulk read of the whole
    // creature_entry -> AgentType default table (AIWorld_Current_Roadmap.md,
    // Etapa 3's own AgentType identity fix) - one query, not one per
    // CreatureEntry, the same shape WORLD_SEL_AI_WORLD_FACTION_ENTRY_DEFAULTS
    // above already provides for WorldFactionCatalog.
    PrepareStatement(WORLD_SEL_AI_AGENT_TYPE_ENTRY_DEFAULTS, "SELECT creature_entry, agent_type FROM ai_agent_type_entry_defaults", CONNECTION_SYNCH);

    // Runtime participation/scope boundary fix (AIWorld_Current_Roadmap.md,
    // Etapa 3): AI SpawnParticipationCatalog's own startup-only bulk read of
    // the whole spawn_id -> SpawnParticipationMode default table - one
    // query, not one per SpawnId, the same shape
    // WORLD_SEL_AI_AGENT_TYPE_ENTRY_DEFAULTS above already provides for
    // AgentTypeCatalog (keyed by SpawnId here, not CreatureEntry - see that
    // catalog's own comment for why).
    PrepareStatement(WORLD_SEL_AI_SPAWN_PARTICIPATION_DEFAULTS, "SELECT spawn_id, participation_mode FROM ai_spawn_participation_defaults", CONNECTION_SYNCH);

    // AI WorldFactionRelationCatalog's own startup-only bulk read of the
    // whole static WorldFaction diplomacy matrix - one query, not one per
    // (from, to) pair, the same shape WORLD_SEL_AI_WORLD_FACTION_ENTRY_DEFAULTS
    // above already provides for WorldFactionCatalog.
    PrepareStatement(WORLD_SEL_AI_WORLD_FACTION_RELATIONS, "SELECT from_world_faction_id, to_world_faction_id, relation FROM ai_world_faction_relations", CONNECTION_SYNCH);

    // AI WorldFactionReputationCatalog's own startup-only bulk read of the
    // whole WorldFactionId -> Trinity Faction.dbc id bridge table
    // (AIWorld_Current_Roadmap.md, login/allegiance-change ReputationMgr
    // bridge) - one query, not one per WorldFactionId.
    PrepareStatement(WORLD_SEL_AI_WORLD_FACTION_REPUTATION_DEFAULTS, "SELECT world_faction_id, faction_id FROM ai_world_faction_reputation_defaults", CONNECTION_SYNCH);
    PrepareStatement(WORLD_DEL_SPAWNGROUP_MEMBER, "DELETE FROM spawn_group WHERE spawnType = ? AND spawnId = ?", CONNECTION_ASYNC);
    PrepareStatement(WORLD_DEL_GAMEOBJECT_ADDON, "DELETE FROM gameobject_addon WHERE guid = ?", CONNECTION_ASYNC);
}

WorldDatabaseConnection::WorldDatabaseConnection(MySQLConnectionInfo& connInfo) : MySQLConnection(connInfo)
{
}

WorldDatabaseConnection::WorldDatabaseConnection(ProducerConsumerQueue<SQLOperation*>* q, MySQLConnectionInfo& connInfo) : MySQLConnection(q, connInfo)
{
}

WorldDatabaseConnection::~WorldDatabaseConnection()
{
}
