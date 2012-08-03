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

/* FIXME
#include "DatabaseWorkerPool.h"
#include "Implementation/LoginDatabase.h" // For logging
extern DatabaseWorkerPool LoginDatabase;
*/

AppenderDB::AppenderDB(uint8 id, std::string const& name, LogLevel level, uint8 realmId):
Appender(id, name, APPENDER_DB, level), realm(realmId), enable(false)
{
}

AppenderDB::~AppenderDB()
{
}

void AppenderDB::_write(LogMessage& /*message*/)
{
/* FIXME
    if (enable)
        LoginDatabase.PExecute("INSERT INTO logs (time, realm, type, severity, string) "
            "VALUES (" UI64FMTD ", %u, %u, '%s');", message.mtime, realm, message.type, message.level, message.text.c_str());
*/
}

void AppenderDB::setEnable(bool _enable)
{
    enable = _enable;
}
