/*
 * Copyright (C) 2019+ ATieshCore <https://at-wow.org/>
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

#ifndef _DBCDATABASE_H
#define _DBCDATABASE_H

#include "MySQLConnection.h"

enum DBCDatabaseStatements : uint32
{
    /*  Naming standard for defines:
        {DB}_{SEL/INS/UPD/DEL/REP}_{Summary of data changed}
        When updating more than one field, consider looking at the calling function
        name for a suiting suffix.
    */
    MAX_DBCDATABASE_STATEMENTS
};

class TC_DATABASE_API DBCDatabaseConnection : public MySQLConnection
{
public:
    typedef DBCDatabaseStatements Statements;

    //- Constructors for sync and async connections
    DBCDatabaseConnection(MySQLConnectionInfo& connInfo);
    DBCDatabaseConnection(ProducerConsumerQueue<SQLOperation*>* q, MySQLConnectionInfo& connInfo);
    ~DBCDatabaseConnection();

    //- Loads database type specific prepared statements
    void DoPrepareStatements() override;
};

#endif
