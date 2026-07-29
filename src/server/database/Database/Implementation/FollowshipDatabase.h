/*
 * This file is part of the Stefal WoW Project.
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
 */

#ifndef _FOLLOWSHIPDATABASE_H
#define _FOLLOWSHIPDATABASE_H

#include "MySQLConnection.h"

enum FollowshipDatabaseStatements : uint32
{
    /*  Naming standard for defines:
        {DB}_{SEL/INS/UPD/DEL/REP}_{Summary of data changed}
    */

    FSB_SEL_BOT_OWNERS_ALL,
    FSB_SEL_BOT_OWNERS_BY_PLAYER,
    FSB_SEL_BOT_OWNER_ID,
    FSB_INS_BOT_OWNER,
    FSB_DEL_BOT_OWNER_BY_GUID,
    FSB_DEL_BOT_OWNER_BY_ENTRY_PLAYER,
    FSB_SEL_BOT_TEMPLATES_ALL,
    FSB_INS_BOT_TEMPLATE,
    FSB_DEL_BOT_TEMPLATE,
    FSB_SEL_BOT_CHATTER_ALL,
    FSB_SEL_BOT_SPELLS_ALL,

    MAX_FOLLOWSHIPDATABASE_STATEMENTS
};

class TC_DATABASE_API FollowshipDatabaseConnection : public MySQLConnection
{
public:
    typedef FollowshipDatabaseStatements Statements;

    FollowshipDatabaseConnection(MySQLConnectionInfo& connInfo, ConnectionFlags connectionFlags);
    ~FollowshipDatabaseConnection();

    //- Loads database type specific prepared statements
    void DoPrepareStatements() override;
};

#endif
