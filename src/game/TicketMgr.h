/*
 * Copyright (C) 2005-2009 MaNGOS
 *
 * Copyright (C) 2008-2009 Trinity
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

#ifndef _TICKETMGR_H
#define _TICKETMGR_H

#include "Policies/Singleton.h"
#include "Database/DatabaseEnv.h"
#include "Util.h"
#include "Config/ConfigEnv.h"
#include <map>

struct GM_Ticket
{
    uint64 guid;
    uint64 playerGuid;
    std::string name;
    std::string message;
    uint64 timestamp;
    uint16 closed;
    uint64 assignedToGM;
    std::string comment;
};

// Map Typedef
typedef std::list<GM_Ticket*>                                       GmTicketList;

class TicketMgr
{
    public:
        TicketMgr(){m_ticketid = 1;}    //constructor
        ~TicketMgr(){}  //destructor

        // Object Holder
        GmTicketList         GM_TicketList;

        void AddGMTicket(GM_Ticket *ticket, bool startup);
        void DeleteAllRemovedGMTickets();
        void DeleteGMTicketPermanently(uint64 ticketGuid);
        void LoadGMTickets();
        void RemoveGMTicketByPlayer(uint64 playerGuid, uint64 GMguid);
        void RemoveGMTicket(uint64 ticketGuid, uint64 GMguid);
        void UpdateGMTicket(GM_Ticket *ticket);
        void SaveGMTicket(GM_Ticket* ticket);

        uint64 GenerateTicketID();
        void InitTicketID();
        GM_Ticket* GetGMTicket(uint64 ticketGuid);
        GM_Ticket* GetGMTicketByPlayer(uint64 playerGuid);
        GM_Ticket* GetGMTicketByName(const char *name);


    protected:
        uint64 m_ticketid;
};

#endif
#define ticketmgr Trinity::Singleton<TicketMgr>::Instance()


