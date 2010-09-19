/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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

#include "CharacterDatabase.h"

bool CharacterDatabaseConnection::Open(const std::string& infoString)
{
    if (!MySQLConnection::Open(infoString))
        return false;

    m_stmts.resize(MAX_CHARACTERDATABASE_STATEMENTS);
    /*
        ##################################
        LOAD YOUR PREPARED STATEMENTS HERE
        ##################################
    */
    PrepareStatement(CHAR_DEL_QUEST_POOL_SAVE, "DELETE FROM pool_quest_save WHERE pool_id = ?");
    PrepareStatement(CHAR_ADD_QUEST_POOL_SAVE, "INSERT INTO pool_quest_save (pool_id, quest_id) VALUES (?, ?)");
    PrepareStatement(CHAR_DEL_OLD_GUILD_EVENT_LOGS, "DELETE FROM guild_eventlog WHERE LogGuid > ?");
    PrepareStatement(CHAR_DEL_OLD_GUILD_BANK_EVENT_LOGS, "DELETE FROM guild_bank_eventlog WHERE LogGuid > ?");
    PrepareStatement(CHAR_DEL_NONEXISTENT_GUILD_BANK_ITEM, "DELETE FROM guild_bank_item WHERE guildid = ? AND TabId = ? AND SlotId = ?");
    PrepareStatement(CHAR_DEL_NONEXISTENT_CHARACTER_GROUP_MEMBERS, "DELETE FROM group_member WHERE NOT EXISTS (SELECT guid FROM characters WHERE guid=memberGuid)");
    PrepareStatement(CHAR_DEL_LEADERLESS_GROUPS, "DELETE FROM groups WHERE NOT EXISTS (SELECT guid FROM characters WHERE guid=leaderGuid)");
    PrepareStatement(CHAR_DEL_TINY_GROUPS, "DELETE FROM groups WHERE guid NOT IN (SELECT guid FROM group_member GROUP BY guid HAVING COUNT(guid) > 1)");
    PrepareStatement(CHAR_DEL_NONEXISTENT_GROUP_MEMBERS, "DELETE FROM group_member WHERE guid NOT IN (SELECT guid FROM groups)");
    PrepareStatement(CHAR_DEL_NONEXISTENT_GROUP_INSTANCES, "DELETE FROM group_instance WHERE guid NOT IN (SELECT guid FROM groups)");
    PrepareStatement(CHAR_DEL_EXPIRED_BANS, "UPDATE character_banned SET active = 0 WHERE unbandate <= UNIX_TIMESTAMP() AND unbandate <> bandate");
    PrepareStatement(CHAR_GET_GUID_BY_NAME, "SELECT guid FROM characters WHERE name = ?");
    PrepareStatement(CHAR_ADD_BAN, "INSERT INTO character_banned VALUES (?, UNIX_TIMESTAMP(), UNIX_TIMESTAMP()+?, ?, ?, 1)");
    PrepareStatement(CHAR_SET_NOT_BANNED, "UPDATE character_banned SET active = 0 WHERE guid = ?");
    PrepareStatement(CHAR_GET_BANINFO, "SELECT FROM_UNIXTIME(bandate), unbandate-bandate, active, unbandate, banreason, bannedby FROM character_banned WHERE guid = ? ORDER BY bandate ASC");
    PrepareStatement(CHAR_GET_GUID_BY_NAME_FILTER, "SELECT guid, name FROM characters WHERE name LIKE CONCAT('%%', ?, '%%')");
    PrepareStatement(CHAR_GET_BANINFO_LIST, "SELECT bandate, unbandate, bannedby, banreason FROM character_banned WHERE guid = ? ORDER BY unbandate");
    PrepareStatement(CHAR_GET_BANNED_NAME, "SELECT characters.name FROM characters, character_banned WHERE character_banned.guid = ? AND character_banned.guid = characters.guid");

    return true;
}
