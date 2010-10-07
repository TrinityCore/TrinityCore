/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

bool WorldDatabaseConnection::Open()
{
    if (!MySQLConnection::Open())
        return false;

    m_stmts.resize(MAX_WORLDDATABASE_STATEMENTS);

    /*
        ##################################
        LOAD YOUR PREPARED STATEMENTS HERE
        ##################################
    */
    PrepareStatement(WORLD_DEL_CRESPAWNTIME, "DELETE FROM creature_respawn WHERE guid = ? AND instance = ?");
    PrepareStatement(WORLD_ADD_CRESPAWNTIME, "INSERT INTO creature_respawn VALUES (?, ?, ?)");
    PrepareStatement(WORLD_LOAD_QUEST_POOLS, "SELECT entry, pool_entry FROM pool_quest");
    PrepareStatement(WORLD_DEL_CRELINKED_RESPAWN, "DELETE FROM creature_linked_respawn WHERE guid = ?");
    PrepareStatement(WORLD_REP_CRELINKED_RESPAWN, "REPLACE INTO creature_linked_respawn (guid,linkedGuid) VALUES (?, ?)");
    PrepareStatement(WORLD_DEL_GAMEOBJECT_RESPAWN_TIMES, "DELETE FROM gameobject_respawn WHERE respawntime <= UNIX_TIMESTAMP(NOW())");
    PrepareStatement(WORLD_LOAD_CRETEXT, "SELECT entry, groupid, id, text, type, language, probability, emote, duration, sound FROM creature_text");

    return true;
}
