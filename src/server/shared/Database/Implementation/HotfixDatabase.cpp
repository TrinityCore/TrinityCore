/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

void HotfixDatabaseConnection::DoPrepareStatements()
{
    if (!m_reconnecting)
        m_stmts.resize(MAX_HOTFIXDATABASE_STATEMENTS);

    PrepareStatement(HOTFIX_SEL_BROADCAST_TEXT, "SELECT * FROM broadcast_text b LEFT JOIN locales_broadcast_text lb ON b.ID = lb.ID", CONNECTION_SYNCH);
    PrepareStatement(HOTFIX_SEL_TAXI_PATH_NODE, "SELECT * FROM taxi_path_node", CONNECTION_SYNCH);
}
