/*
 * Copyright (C) 2005-2008 MaNGOS 
 *
 * Copyright (C) 2008 Trinity 
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "Common.h"
#include "Database/DatabaseEnv.h"
#include "Database/SQLStorage.h"
#include "GMTicketMgr.h"
#include "ObjectMgr.h"
#include "ProgressBar.h"
#include "Policies/SingletonImp.h"
#include "Player.h"
#include "ObjectDefines.h"

INSTANTIATE_SINGLETON_1(GMTicketMgr);

void GMTicketMgr::LoadGMTickets()
{
    m_GMTicketMap.clear();                                  // For reload case

    QueryResult *result = CharacterDatabase.Query(
        //      0     1           2
        "SELECT guid, ticket_text,UNIX_TIMESTAMP(ticket_lastchange) FROM character_ticket");

    if( !result )
    {
        barGoLink bar( 1 );

        bar.step();

        sLog.outString();
        sLog.outErrorDb(">> Loaded `character_ticket`, table is empty!");
        return;
    }

    barGoLink bar( result->GetRowCount() );

    uint32 count = 0;

    do
    {
        bar.step();

        Field* fields = result->Fetch();

        uint32 guid = fields[0].GetUInt32();
        m_GMTicketMap[guid] = GMTicket(guid, fields[1].GetCppString(), time_t(fields[2].GetUInt64()));
        ++count;

    } while (result->NextRow());
    delete result;

    sLog.outString();
    sLog.outString( ">> Loaded %d GM tickets", count );
}

void GMTicketMgr::DeleteAll()
{
    for(GMTicketMap::iterator itr = m_GMTicketMap.begin(); itr != m_GMTicketMap.end(); ++itr)
    {
        if(Player* owner = objmgr.GetPlayer(MAKE_NEW_GUID(itr->first,0,HIGHGUID_PLAYER)))
            owner->GetSession()->SendGMTicketGetTicket(0x0A,0);
    }
    CharacterDatabase.PExecute("DELETE FROM character_ticket");
    m_GMTicketMap.clear();
}
