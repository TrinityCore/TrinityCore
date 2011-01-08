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

        //- Loads databasetype specific prepared statements
        bool Open();
};

typedef DatabaseWorkerPool<WorldDatabaseConnection> WorldDatabaseWorkerPool;

enum WorldDatabaseStatements
{
    /*  Naming standard for defines:
        {DB}_{SET/DEL/ADD/REP}_{Summary of data changed}
        When updating more than one field, consider looking at the calling function
        name for a suiting suffix.
    */

    WORLD_LOAD_QUEST_POOLS,
    WORLD_DEL_CRELINKED_RESPAWN,
    WORLD_REP_CRELINKED_RESPAWN,
    WORLD_LOAD_CRETEXT,
    WORLD_LOAD_SMART_SCRIPTS,
    WORLD_LOAD_SMARTAI_WP,
    MAX_WORLDDATABASE_STATEMENTS,
};

static const PreparedStatementTable WorldDatabasePreparedStatements[] =
{
    {WORLD_LOAD_QUEST_POOLS, "SELECT entry, pool_entry FROM pool_quest", CONNECTION_SYNCH},
    {WORLD_DEL_CRELINKED_RESPAWN, "DELETE FROM linked_respawn WHERE guid = ?", CONNECTION_ASYNC},
    {WORLD_REP_CRELINKED_RESPAWN, "REPLACE INTO linked_respawn (guid,linkedGuid) VALUES (?, ?)", CONNECTION_ASYNC},
    {WORLD_LOAD_CRETEXT, "SELECT entry, groupid, id, text, type, language, probability, emote, duration, sound FROM creature_text", CONNECTION_SYNCH},
    {WORLD_LOAD_SMART_SCRIPTS,  "SELECT entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o FROM smart_scripts ORDER BY entryorguid, source_type, id, link", CONNECTION_SYNCH},
    {WORLD_LOAD_SMARTAI_WP,  "SELECT entry, pointid, position_x, position_y, position_z FROM waypoints ORDER BY entry, pointid", CONNECTION_SYNCH}

};

#endif
