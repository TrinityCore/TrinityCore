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

#ifndef _HOTFIXDATABASE_H
#define _HOTFIXDATABASE_H

#include "DatabaseWorkerPool.h"
#include "MySQLConnection.h"

class HotfixDatabaseConnection : public MySQLConnection
{
    public:
        //- Constructors for sync and async connections
        HotfixDatabaseConnection(MySQLConnectionInfo& connInfo) : MySQLConnection(connInfo) { }
        HotfixDatabaseConnection(ProducerConsumerQueue<SQLOperation*>* q, MySQLConnectionInfo& connInfo) : MySQLConnection(q, connInfo) { }

        //- Loads database type specific prepared statements
        void DoPrepareStatements() override;

    private:
        void PrepareLocaleStatement(uint32 index, uint32 localeIndex, const char* sql, ConnectionFlags flags);
};

typedef DatabaseWorkerPool<HotfixDatabaseConnection> HotfixDatabaseWorkerPool;

enum HotfixDatabaseStatements
{
    /*  Naming standard for defines:
        {DB}_{SEL/INS/UPD/DEL/REP}_{Summary of data changed}
        When updating more than one field, consider looking at the calling function
        name for a suiting suffix.

        DB2 locale loading statements must have the name of base statement with locale enum value name suffix
    */

    HOTFIX_SEL_BROADCAST_TEXT,
    HOTFIX_SEL_BROADCAST_TEXT_LOCALE_koKR,
    HOTFIX_SEL_BROADCAST_TEXT_LOCALE_frFR,
    HOTFIX_SEL_BROADCAST_TEXT_LOCALE_deDE,
    HOTFIX_SEL_BROADCAST_TEXT_LOCALE_zhCN,
    HOTFIX_SEL_BROADCAST_TEXT_LOCALE_zhTW,
    HOTFIX_SEL_BROADCAST_TEXT_LOCALE_esES,
    HOTFIX_SEL_BROADCAST_TEXT_LOCALE_esMX,
    HOTFIX_SEL_BROADCAST_TEXT_LOCALE_ruRU,

    HOTFIX_SEL_TAXI_PATH_NODE,
    MAX_HOTFIXDATABASE_STATEMENTS
};

#endif
