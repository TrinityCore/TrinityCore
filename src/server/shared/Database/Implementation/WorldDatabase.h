/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "DatabaseWorkerPool.h"
#include "MySQLConnection.h"

class WorldDatabaseConnection : public MySQLConnection
{
    public:
        //- Constructors for sync and async connections
        WorldDatabaseConnection(MySQLConnectionInfo& connInfo) : MySQLConnection(connInfo) {}
        WorldDatabaseConnection(ACE_Activation_Queue* q, MySQLConnectionInfo& connInfo) : MySQLConnection(q, connInfo) {}

        //- Loads database type specific prepared statements
        void DoPrepareStatements();
};

typedef DatabaseWorkerPool<WorldDatabaseConnection> WorldDatabaseWorkerPool;

enum WorldDatabaseStatements
{
    /*  Naming standard for defines:
        {DB}_{SEL/INS/UPD/DEL/REP}_{Summary of data changed}
        When updating more than one field, consider looking at the calling function
        name for a suiting suffix.
    */

    WORLD_SEL_QUEST_POOLS,
    WORLD_DEL_CRELINKED_RESPAWN,
    WORLD_REP_CREATURE_LINKED_RESPAWN,
    WORLD_SEL_CREATURE_TEXT,
    WORLD_SEL_SMART_SCRIPTS,
    WORLD_SEL_SMARTAI_WP,
    WORLD_DEL_GAMEOBJECT,
    WORLD_DEL_EVENT_GAMEOBJECT,
    WORLD_INS_GRAVEYARD_ZONE,
    WORLD_DEL_GRAVEYARD_ZONE,
    WORLD_INS_GAME_TELE,
    WORLD_DEL_GAME_TELE,
    WORLD_INS_NPC_VENODR,
    WORLD_DEL_NPC_VENDOR,
    WORLD_UPD_CREATURE_MOVEMENT_TYPE,
    WORLD_UPD_CREATURE_FACTION,
    WORLD_UPD_CREATURE_NPCFLAG,
    WORLD_UPD_CREATURE_POSITION,
    WORLD_UPD_CREATURE_SPAWN_DISTANCE,
    WORLD_UPD_CREATURE_SPAWN_TIME_SECS,
    WORLD_INS_CREATURE_FORMATION,
    WORLD_INS_WAYPOINT_DATA,
    WORLD_DEL_WAYPOINT_DATA,
    WORLD_UPD_WAYPOINT_DATA_POINT,
    WORLD_UPD_WAYPOINT_DATA_POSITION,
    WORLD_UPD_WAYPOINT_DATA_WPGUID,
    WOLRD_UPD_ALL_WAYPOINT_DATA_WPGUID,
    WORLD_UPD_CREATURE_ADDON_PATH,
    WORLD_INS_CREATURE_ADDON,
    WORLD_DEL_CREATURE_ADDON,
    WORLD_INS_WAYPOINT_SCRIPT,
    WORLD_DEL_WAYPOINT_SCRIPT,
    WORLD_UPD_WAYPOINT_SCRIPT_ID,
    WORLD_UPD_WAYPOINT_SCRIPT_X,
    WORLD_UPD_WAYPOINT_SCRIPT_Y,
    WORLD_UPD_WAYPOINT_SCRIPT_Z,
    WORLD_UPD_WAYPOINT_SCRIPT_O,
    WORLD_DEL_CREATURE,

    MAX_WORLDDATABASE_STATEMENTS,
};

#endif
