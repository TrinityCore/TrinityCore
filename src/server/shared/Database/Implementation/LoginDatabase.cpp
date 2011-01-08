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

#include "LoginDatabase.h"

bool LoginDatabaseConnection::Open()
{
    if (!MySQLConnection::Open())
        return false;

    if (!m_reconnecting)
        m_stmts.resize(MAX_LOGINDATABASE_STATEMENTS);

    for (uint32 index = 0; index < MAX_LOGINDATABASE_STATEMENTS; ++index)
    {
        PreparedStatementTable const& pst = LoginDatabasePreparedStatements[index];        
        PrepareStatement(pst.index, pst.query, pst.type);
    }

    m_statementTable = LoginDatabasePreparedStatements;

    return true;
}
