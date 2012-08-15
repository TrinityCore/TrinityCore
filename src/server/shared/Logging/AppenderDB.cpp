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

#include "AppenderDB.h"
#include "Database/DatabaseEnv.h"

AppenderDB::AppenderDB(uint8 id, std::string const& name, LogLevel level, uint8 realmId):
Appender(id, name, APPENDER_DB, level), realm(realmId), enable(false)
{
}

AppenderDB::~AppenderDB()
{
}

void AppenderDB::_write(LogMessage& message)
{
    if (!enable)
        return;
    switch (message.type)
    {
        case LOG_FILTER_SQL:
        case LOG_FILTER_SQL_DRIVER:
        case LOG_FILTER_SQL_DEV:
            break; // Avoid infinite loop, PExecute triggers Logging with LOG_FILTER_SQL type
        default:
            PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_LOG);
            stmt->setUInt64(0, message.mtime);
            stmt->setUInt32(1, realm);
            stmt->setUInt8(2, message.type);
            stmt->setUInt8(3, message.level);
            stmt->setString(4, message.text);
            LoginDatabase.Execute(stmt);
            break;
    }
}

void AppenderDB::setEnable(bool _enable)
{
    enable = _enable;
}
