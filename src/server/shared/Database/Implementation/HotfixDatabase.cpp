/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "HotfixDatabase.h"
#include "Util.h"

/*
    Hotfix database statements are constructed in a special way
    Each db2 storage that contains localized string data
    must declare a prepared statement for each locale in the same order as
    locales are defined (enforced during compilation)

    '@' character is replaced with locale index for PrepareStatement call
*/

// Force locale statments to appear exactly in locale declaration order, right after normal data fetch statement
#define PREPARE_LOCALE_STMT(stmtBase, loc, sql, con) \
    static_assert(stmtBase + loc == stmtBase##_##loc, "Invalid prepared statement index for " STRINGIZE(stmtBase##_##loc)); \
    PrepareLocaleStatement(stmtBase##_##loc, loc, sql, con);

#define PREPARE_LOCALE_STMTS(stmtBase, sql, con) \
    PREPARE_LOCALE_STMT(stmtBase, LOCALE_koKR, sql, con) \
    PREPARE_LOCALE_STMT(stmtBase, LOCALE_frFR, sql, con) \
    PREPARE_LOCALE_STMT(stmtBase, LOCALE_deDE, sql, con) \
    PREPARE_LOCALE_STMT(stmtBase, LOCALE_zhCN, sql, con) \
    PREPARE_LOCALE_STMT(stmtBase, LOCALE_zhTW, sql, con) \
    PREPARE_LOCALE_STMT(stmtBase, LOCALE_esES, sql, con) \
    PREPARE_LOCALE_STMT(stmtBase, LOCALE_esMX, sql, con) \
    PREPARE_LOCALE_STMT(stmtBase, LOCALE_ruRU, sql, con)

void HotfixDatabaseConnection::DoPrepareStatements()
{
    if (!m_reconnecting)
        m_stmts.resize(MAX_HOTFIXDATABASE_STATEMENTS);

    // BroadcastText.db2
    PrepareStatement(HOTFIX_SEL_BROADCAST_TEXT, "SELECT * FROM broadcast_text ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMTS(HOTFIX_SEL_BROADCAST_TEXT, "SELECT ID, MaleText_loc@, FemaleText_loc@ FROM locales_broadcast_text", CONNECTION_SYNCH);

    // TaxiPathNode.db2
    PrepareStatement(HOTFIX_SEL_TAXI_PATH_NODE, "SELECT * FROM taxi_path_node ORDER BY ID DESC", CONNECTION_SYNCH);
}

void HotfixDatabaseConnection::PrepareLocaleStatement(uint32 index, uint32 localeIndex, const char* sql, ConnectionFlags flags)
{
    Tokenizer tokens(sql, '@');
    std::ostringstream stmt;
    stmt << tokens[0];
    for (std::size_t i = 1; i < tokens.size(); ++i)
        stmt << localeIndex << tokens[i];

    PrepareStatement(index, stmt.str().c_str(), flags);
}
