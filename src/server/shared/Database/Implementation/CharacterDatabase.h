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

#ifndef _CHARACTERDATABASE_H
#define _CHARACTERDATABASE_H

#include "DatabaseWorkerPool.h"
#include "MySQLConnection.h"

class CharacterDatabaseConnection : public MySQLConnection
{
    public:
        //- Constructors for sync and async connections
        CharacterDatabaseConnection(const MySQLConnectionInfo& connInfo) : MySQLConnection(connInfo) {}
        CharacterDatabaseConnection(ACE_Activation_Queue* q, const MySQLConnectionInfo& connInfo) : MySQLConnection(q, connInfo) {}

        //- Loads databasetype specific prepared statements
        bool Open();
};

typedef DatabaseWorkerPool<CharacterDatabaseConnection> CharacterDatabaseWorkerPool;

enum CharacterDatabaseStatements
{
    /*  Naming standard for defines:
        {DB}_{SET/DEL/ADD/REP}_{Summary of data changed}
        When updating more than one field, consider looking at the calling function
        name for a suiting suffix.
    */

    CHAR_DEL_QUEST_POOL_SAVE,
    CHAR_ADD_QUEST_POOL_SAVE,
    CHAR_DEL_OLD_GUILD_EVENT_LOGS,
    CHAR_DEL_OLD_GUILD_BANK_EVENT_LOGS,
    CHAR_DEL_NONEXISTENT_GUILD_BANK_ITEM,
    CHAR_DEL_NONEXISTENT_CHARACTER_GROUP_MEMBERS,
    CHAR_DEL_LEADERLESS_GROUPS,
    CHAR_DEL_TINY_GROUPS,
    CHAR_DEL_NONEXISTENT_GROUP_MEMBERS,
    CHAR_DEL_NONEXISTENT_GROUP_INSTANCES,
    CHAR_DEL_EXPIRED_BANS,
    CHAR_GET_GUID_BY_NAME,
    CHAR_ADD_BAN,
    CHAR_SET_NOT_BANNED,
    CHAR_GET_BANINFO,
    CHAR_GET_GUID_BY_NAME_FILTER,
    CHAR_GET_BANINFO_LIST,
    CHAR_GET_BANNED_NAME,
    CHAR_LOAD_PLAYER,
    CHAR_LOAD_PLAYER_GROUP,
    CHAR_LOAD_PLAYER_BOUNDINSTANCES,
    CHAR_LOAD_PLAYER_AURAS,
    CHAR_LOAD_PLAYER_SPELLS,
    CHAR_LOAD_PLAYER_QUESTSTATUS,
    CHAR_LOAD_PLAYER_DAILYQUESTSTATUS,
    CHAR_LOAD_PLAYER_WEKLYQUESTSTATUS,
    CHAR_LOAD_PLAYER_REPUTATION,
    CHAR_LOAD_PLAYER_INVENTORY,
    CHAR_LOAD_PLAYER_ACTIONS,
    CHAR_LOAD_PLAYER_ACTIONS_SPEC,
    CHAR_LOAD_PLAYER_MAILCOUNT,
    CHAR_LOAD_PLAYER_MAILDATE,
    CHAR_LOAD_PLAYER_SOCIALLIST,
    CHAR_LOAD_PLAYER_HOMEBIND,
    CHAR_LOAD_PLAYER_SPELLCOOLDOWNS,
    CHAR_LOAD_PLAYER_DECLINEDNAMES,
    CHAR_LOAD_PLAYER_GUILD,
    CHAR_LOAD_PLAYER_ARENAINFO,
    CHAR_LOAD_PLAYER_ACHIEVEMENTS,
    CHAR_LOAD_PLAYER_CRITERIAPROGRESS,
    CHAR_LOAD_PLAYER_EQUIPMENTSETS,
    CHAR_LOAD_PLAYER_BGDATA,
    CHAR_LOAD_PLAYER_GLYPHS,
    CHAR_LOAD_PLAYER_TALENTS,
    CHAR_LOAD_PLAYER_ACCOUNTDATA,
    CHAR_LOAD_PLAYER_SKILLS,
    CHAR_LOAD_PLAYER_RANDOMBG,
    CHAR_LOAD_PLAYER_ARENASTATS,
    CHAR_LOAD_PLAYER_BANNED,
    CHAR_LOAD_ACCOUNT_DATA,
    CHAR_LOAD_PLAYER_MAILITEMS,
    CHAR_LOAD_AUCTION_ITEMS,
    CHAR_LOAD_GUILD_BANK_ITEMS,
    CHAR_LOAD_ITEM_REFUNDS,
    CHAR_LOAD_ITEM_BOP_TRADE,
    CHAR_DEL_ITEM_BOP_TRADE,
    CHAR_ADD_ITEM_BOP_TRADE,
    CHAR_DEL_INVENTORY_ITEM,
    CHAR_DEL_ITEM_INSTANCE,
    CHAR_GET_ACCOUNT_BY_NAME,
    MAX_CHARACTERDATABASE_STATEMENTS,
};

#endif
