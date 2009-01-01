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

enum GMticketType
{
	GM_TICKET_TYPE_STUCK				= 1,
	GM_TICKET_TYPE_BEHAVIOR_HARASSMENT	= 2,
	GM_TICKET_TYPE_GUILD				= 3,
	GM_TICKET_TYPE_ITEM					= 4,
	GM_TICKET_TYPE_ENVIRONMENTAL		= 5,
	GM_TICKET_TYPE_NON_QUEST_CREEP		= 6,
	GM_TICKET_TYPE_QUEST_QUEST_NPC		= 7,
	GM_TICKET_TYPE_TECHNICAL			= 8,
	GM_TICKET_TYPE_ACCOUNT_BILLING		= 9,
	GM_TICKET_TYPE_CHARACTER			= 10
};

// Map Typedef
typedef std::list<GM_Ticket*>                                       GmTicketList;

class TicketMgr
{
	public:
		TicketMgr(){}	//constructor
		~TicketMgr(){}	//destructor

		// Object Holder
		GmTicketList         GM_TicketList;

		void AddGMTicket(GM_Ticket *ticket, bool startup);
		void DeleteAllRemovedGMTickets();
		void DeleteGMTicketPermanently(uint64 ticketGuid);
		void LoadGMTickets();
		void RemoveGMTicketByPlayer(uint64 playerGuid);
		void RemoveGMTicket(uint64 ticketGuid);
		void UpdateGMTicket(GM_Ticket *ticket);
		void SaveGMTicket(GM_Ticket* ticket);
		
		uint64 GenerateTicketID();
		GM_Ticket* GetGMTicket(uint64 ticketGuid);
		GM_Ticket* GetGMTicketByPlayer(uint64 playerGuid);
		GM_Ticket* GetGMTicketByName(const char *name);
		

	protected:
		uint64 m_ticketid;
};

#endif
#define ticketmgr Trinity::Singleton<TicketMgr>::Instance()

