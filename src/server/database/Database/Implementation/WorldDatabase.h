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

#ifndef _WORLDDATABASE_H
#define _WORLDDATABASE_H

#include "MySQLConnection.h"

enum WorldDatabaseStatements : uint32
{
    /*  Naming standard for defines:
        {DB}_{SEL/INS/UPD/DEL/REP}_{Summary of data changed}
        When updating more than one field, consider looking at the calling function
        name for a suiting suffix.
    */

    WORLD_DEL_LINKED_RESPAWN,
    WORLD_DEL_LINKED_RESPAWN_MASTER,
    WORLD_REP_LINKED_RESPAWN,
    WORLD_SEL_CREATURE_TEXT,
    WORLD_SEL_SMART_SCRIPTS,
    WORLD_SEL_SMARTAI_WP,
    WORLD_DEL_GAMEOBJECT,
    WORLD_DEL_EVENT_GAMEOBJECT,
    WORLD_INS_GRAVEYARD_ZONE,
    WORLD_DEL_GRAVEYARD_ZONE,
    WORLD_INS_GAME_TELE,
    WORLD_DEL_GAME_TELE,
    WORLD_INS_NPC_VENDOR,
    WORLD_DEL_NPC_VENDOR,
    WORLD_SEL_NPC_VENDOR_REF,
    WORLD_UPD_CREATURE_MOVEMENT_TYPE,
    WORLD_UPD_CREATURE_FACTION,
    WORLD_UPD_CREATURE_NPCFLAG,
    WORLD_UPD_CREATURE_POSITION,
    WORLD_UPD_CREATURE_WANDER_DISTANCE,
    WORLD_UPD_CREATURE_SPAWN_TIME_SECS,
    WORLD_INS_CREATURE_FORMATION,
    WORLD_INS_WAYPOINT_DATA,
    WORLD_DEL_WAYPOINT_DATA,
    WORLD_UPD_WAYPOINT_DATA_POINT,
    WORLD_UPD_WAYPOINT_DATA_POSITION,
    WORLD_UPD_WAYPOINT_DATA_WPGUID,
    WORLD_UPD_WAYPOINT_DATA_ALL_WPGUID,
    WORLD_SEL_WAYPOINT_DATA_MAX_ID,
    WORLD_SEL_WAYPOINT_DATA_BY_ID,
    WORLD_SEL_WAYPOINT_DATA_POS_BY_ID,
    WORLD_SEL_WAYPOINT_DATA_POS_FIRST_BY_ID,
    WORLD_SEL_WAYPOINT_DATA_POS_LAST_BY_ID,
    WORLD_SEL_WAYPOINT_DATA_BY_WPGUID,
    WORLD_SEL_WAYPOINT_DATA_ALL_BY_WPGUID,
    WORLD_SEL_WAYPOINT_DATA_MAX_POINT,
    WORLD_SEL_WAYPOINT_DATA_BY_POS,
    WORLD_SEL_WAYPOINT_DATA_WPGUID_BY_ID,
    WORLD_SEL_WAYPOINT_DATA_ACTION,
    WORLD_SEL_WAYPOINT_SCRIPTS_MAX_ID,
    WORLD_UPD_CREATURE_ADDON_PATH,
    WORLD_INS_CREATURE_ADDON,
    WORLD_DEL_CREATURE_ADDON,
    WORLD_SEL_CREATURE_ADDON_BY_GUID,
    WORLD_INS_WAYPOINT_SCRIPT,
    WORLD_DEL_WAYPOINT_SCRIPT,
    WORLD_UPD_WAYPOINT_SCRIPT_ID,
    WORLD_UPD_WAYPOINT_SCRIPT_X,
    WORLD_UPD_WAYPOINT_SCRIPT_Y,
    WORLD_UPD_WAYPOINT_SCRIPT_Z,
    WORLD_UPD_WAYPOINT_SCRIPT_O,
    WORLD_SEL_WAYPOINT_SCRIPT_ID_BY_GUID,
    WORLD_DEL_CREATURE,
    WORLD_SEL_COMMANDS,
    WORLD_SEL_CREATURE_TEMPLATE,
    WORLD_SEL_WAYPOINT_SCRIPT_BY_ID,
    WORLD_SEL_ITEM_TEMPLATE_BY_NAME,
    WORLD_SEL_CREATURE_BY_ID,
    WORLD_SEL_GAMEOBJECT_NEAREST,
    WORLD_SEL_CREATURE_NEAREST,
    WORLD_SEL_GAMEOBJECT_TARGET,
    WORLD_INS_CREATURE,
    WORLD_DEL_GAME_EVENT_CREATURE,
    WORLD_DEL_GAME_EVENT_MODEL_EQUIP,
    WORLD_INS_GAMEOBJECT,
    WORLD_SEL_DISABLES,
    WORLD_INS_DISABLES,
    WORLD_DEL_DISABLES,
    WORLD_UPD_CREATURE_ZONE_AREA_DATA,
    WORLD_UPD_GAMEOBJECT_ZONE_AREA_DATA,
    WORLD_DEL_SPAWNGROUP_MEMBER,
    WORLD_DEL_GAMEOBJECT_ADDON,

    MAX_WORLDDATABASE_STATEMENTS
};

class TC_DATABASE_API WorldDatabaseConnection : public MySQLConnection
{
public:
    typedef WorldDatabaseStatements Statements;

    //- Constructors for sync and async connections
    WorldDatabaseConnection(MySQLConnectionInfo& connInfo);
    WorldDatabaseConnection(ProducerConsumerQueue<SQLOperation*>* q, MySQLConnectionInfo& connInfo);
    ~WorldDatabaseConnection();

    //- Loads database type specific prepared statements
    void DoPrepareStatements() override;
};

#endif
