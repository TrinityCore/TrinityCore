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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "TicketMgr.h"
#include "Policies/SingletonImp.h"
#include "World.h"
#include "ObjectMgr.h"
#include "Language.h"
#include "Player.h"
#include "Common.h"
#include "ObjectAccessor.h"
INSTANTIATE_SINGLETON_1( TicketMgr );

GM_Ticket* TicketMgr::GetGMTicket(uint64 ticketGuid)
{
    for(GmTicketList::iterator i = GM_TicketList.begin(); i != GM_TicketList.end();)
    {
        if((*i)->guid == ticketGuid)
        {
            return (*i);
        }
        ++i;
    }
    return NULL;
}

GM_Ticket* TicketMgr::GetGMTicketByPlayer(uint64 playerGuid)
{
    for(GmTicketList::iterator i = GM_TicketList.begin(); i != GM_TicketList.end();)
    {
        if((*i)->playerGuid == playerGuid && (*i)->closed == 0)
        {
            return (*i);
        }
        ++i;
    }
    return NULL;
}

GM_Ticket* TicketMgr::GetGMTicketByName(const char* name)
{
    std::string pname = name;
    if(!normalizePlayerName(pname))
        return NULL;

    uint64 playerGuid = objmgr.GetPlayerGUIDByName(pname.c_str());
    if(!playerGuid)
        return NULL;

    for(GmTicketList::iterator i = GM_TicketList.begin(); i != GM_TicketList.end();)
    {
        if((*i)->playerGuid == playerGuid && (*i)->closed == 0)
        {
            return (*i);
        }
        ++i;
    }
    return NULL;
}

void TicketMgr::AddGMTicket(GM_Ticket *ticket, bool startup)
{
    ASSERT( ticket );
    GM_TicketList.push_back(ticket);

    // save
    if(!startup)
        SaveGMTicket(ticket);
}

void TicketMgr::DeleteGMTicketPermanently(uint64 ticketGuid)
{
    for(GmTicketList::iterator i = GM_TicketList.begin(); i != GM_TicketList.end();)
    {
        if((*i)->guid == ticketGuid)
            i = GM_TicketList.erase(i);
        else
            ++i;
    }

    // delete database record
    CharacterDatabase.PExecute("DELETE FROM `gm_tickets` WHERE guid= '%u'", ticketGuid);
}


void TicketMgr::LoadGMTickets()
{
    // Delete all out of object holder
    GM_TicketList.clear();
    QueryResult *result = CharacterDatabase.Query( "SELECT `guid`, `playerGuid`, `name`, `message`, `createtime`, `map`, `posX`, `posY`, `posZ`, `timestamp`, `closed`, `assignedto`, `comment` FROM `gm_tickets`" );
    GM_Ticket *ticket;

    if(!result)
        return;

    // Assign values from SQL to the object holder
    do
    {
        Field *fields = result->Fetch();
        ticket = new GM_Ticket;
        ticket->guid = fields[0].GetUInt64();
        ticket->playerGuid = fields[1].GetUInt64();
        ticket->name = fields[2].GetString();
        ticket->message = fields[3].GetString();
        ticket->createtime = fields[4].GetUInt64();
        ticket->map = fields[5].GetUInt32();
        ticket->pos_x = fields[6].GetFloat();
        ticket->pos_y = fields[7].GetFloat();
        ticket->pos_z = fields[8].GetFloat();
        ticket->timestamp = fields[9].GetUInt64();
        ticket->closed = fields[10].GetUInt64();
        ticket->assignedToGM = fields[11].GetUInt64();
        ticket->comment = fields[12].GetString();

        AddGMTicket(ticket, true);

    } while( result->NextRow() );

    sWorld.SendGMText(LANG_COMMAND_TICKETRELOAD, result->GetRowCount());

    delete result;
}

void TicketMgr::RemoveGMTicket(uint64 ticketGuid, uint64 GMguid)
{
    for(GmTicketList::iterator i = GM_TicketList.begin(); i != GM_TicketList.end();)
    {
        if((*i)->guid == ticketGuid && (*i)->closed == 0)
        {
            (*i)->closed = GMguid;
            SaveGMTicket((*i));
        }
        ++i;
    }
}


void TicketMgr::RemoveGMTicketByPlayer(uint64 playerGuid, uint64 GMguid)
{
    for(GmTicketList::iterator i = GM_TicketList.begin(); i != GM_TicketList.end();)
    {
        if((*i)->playerGuid == playerGuid && (*i)->closed == 0)
        {
            (*i)->closed = GMguid;
            SaveGMTicket((*i));
        }
        ++i;
    }
}

void TicketMgr::SaveGMTicket(GM_Ticket* ticket)
{
    std::string msg = ticket->message;
    CharacterDatabase.escape_string(msg);
    std::stringstream ss;
    ss << "REPLACE INTO `gm_tickets` (`guid`, `playerGuid`, `name`, `message`, `createtime`, `map`, `posX`, `posY`, `posZ`, `timestamp`, `closed`, `assignedto`, `comment`) VALUES('";
    ss << ticket->guid << "', '";
    ss << ticket->playerGuid << "', '";
    ss << ticket->name << "', '";
    ss << msg << "', '" ;
    ss << ticket->createtime << "', '";
    ss << ticket->map << "', '";
    ss << ticket->pos_x << "', '";
    ss << ticket->pos_y << "', '";
    ss << ticket->pos_z << "', '";
    ss << ticket->timestamp << "', '";
    ss << ticket->closed << "', '";
    ss << ticket->assignedToGM << "', '";
    ss << ticket->comment << "');";
    CharacterDatabase.BeginTransaction();
    CharacterDatabase.Execute(ss.str().c_str());
    CharacterDatabase.CommitTransaction();

}

void TicketMgr::UpdateGMTicket(GM_Ticket *ticket)
{
    SaveGMTicket(ticket);
}

void TicketMgr::InitTicketID()
{
    QueryResult *result = CharacterDatabase.Query("SELECT MAX(guid) FROM gm_tickets");
    if(result)
    {
        m_ticketid = result->Fetch()[0].GetUInt64();
        delete result;
    }
}

uint64 TicketMgr::GenerateTicketID()
{
    return ++m_ticketid;
}

