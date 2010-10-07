/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _TICKETMGR_H
#define _TICKETMGR_H

#include <string>
#include <ace/Singleton.h>
#include "Common.h"
#include "DatabaseEnv.h"
#include "SQLStorage.h"
#include "SQLStorageImpl.h"

// from blizzard lua
enum GMTicketSystemStatus
{
    GMTICKET_QUEUE_STATUS_DISABLED = -1,
    GMTICKET_QUEUE_STATUS_ENABLED = 1,
};

enum GMTicketStatus
{
    GMTICKET_STATUS_HASTEXT                      = 0x06,
    GMTICKET_STATUS_DEFAULT                      = 0x0A,
};

enum GMTicketResponse
{
    GMTICKET_RESPONSE_FAILURE                     = 1,
    GMTICKET_RESPONSE_SUCCESS                     = 2,
    GMTICKET_RESPONSE_TICKET_DELETED              = 9,
};

// from Blizzard LUA:
// GMTICKET_ASSIGNEDTOGM_STATUS_NOT_ASSIGNED = 0;    -- ticket is not currently assigned to a gm
// GMTICKET_ASSIGNEDTOGM_STATUS_ASSIGNED = 1;        -- ticket is assigned to a normal gm
// GMTICKET_ASSIGNEDTOGM_STATUS_ESCALATED = 2;        -- ticket is in the escalation queue
// 3 is a custom value and should never actually be sent
enum GMTicketEscalationStatus
{
    TICKET_UNASSIGNED                             = 0,
    TICKET_ASSIGNED                               = 1,
    TICKET_IN_ESCALATION_QUEUE                    = 2,
    TICKET_ESCALATED_ASSIGNED                     = 3,
};

// from blizzard lua
enum GMTicketOpenedByGMStatus
{
    GMTICKET_OPENEDBYGM_STATUS_NOT_OPENED = 0,      // ticket has never been opened by a gm
    GMTICKET_OPENEDBYGM_STATUS_OPENED = 1,          // ticket has been opened by a gm
};

enum LagReportType
{
    LAG_REPORT_TYPE_LOOT = 1,
    LAG_REPORT_TYPE_AUCTION_HOUSE = 2,
    LAG_REPORT_TYPE_MAIL = 3,
    LAG_REPORT_TYPE_CHAT = 4,
    LAG_REPORT_TYPE_MOVEMENT = 5,
    LAG_REPORT_TYPE_SPELL = 6
};

struct GM_Ticket
{
    uint64 guid;
    uint64 playerGuid;
    std::string name;
    float pos_x;
    float pos_y;
    float pos_z;
    uint32 map;
    std::string message;
    uint64 createtime;
    uint64 timestamp;
    int64 closed; // 0 = Open, -1 = Console, playerGuid = player abandoned ticket, other = GM who closed it.
    uint64 assignedToGM;
    std::string comment;
    bool completed;
    uint8 escalated;
    bool viewed;
    std::string response;
};
typedef std::list<GM_Ticket*> GmTicketList;

class TicketMgr
{
    TicketMgr();
    friend class ACE_Singleton<TicketMgr, ACE_Null_Mutex>;

public:
    void LoadGMTickets();
    void LoadGMSurveys();

    GM_Ticket *GetGMTicket(uint64 ticketGuid)
    {
        for (GmTicketList::const_iterator i = m_GMTicketList.begin(); i != m_GMTicketList.end(); ++i)
            if ((*i) && (*i)->guid == ticketGuid)
                return (*i);

        return NULL;
    }

    GM_Ticket *GetGMTicketByPlayer(uint64 playerGuid)
    {
        for (GmTicketList::const_iterator i = m_GMTicketList.begin(); i != m_GMTicketList.end(); ++i)
            if ((*i) && (*i)->playerGuid == playerGuid && (*i)->closed == 0)
                return (*i);

        return NULL;
    }

    void AddOrUpdateGMTicket(GM_Ticket &ticket, bool create = false);
    void _AddOrUpdateGMTicket(GM_Ticket &ticket);
    void RemoveGMTicket(uint64 ticketGuid, int64 source = -1, bool permanently = false);
    void RemoveGMTicket(GM_Ticket *ticket, int64 source = -1, bool permanently = false);
    uint64 GenerateGMTicketId();
    bool GetStatus() const { return status; }
    void SetStatus(bool newStatus) { status = newStatus; }
    uint64 GetOpenTicketCount() { return m_openTickets; }
    uint64 GetNextSurveyID() { return ++m_GMSurveyID; }

    GM_Ticket *GetOldestOpenGMTicket()
    {
        for (GmTicketList::const_iterator i = m_GMTicketList.begin(); i != m_GMTicketList.end(); ++i)
            if ((*i) && (*i)->closed == 0 && !(*i)->completed)
                return (*i);

        return NULL;
    }

    time_t GetLastChange() { return lastChange; }
    void UpdateLastChange() { lastChange = time(NULL); }

    GmTicketList m_GMTicketList;

protected:
    uint64 m_GMticketid;
    uint64 m_GMSurveyID;
    bool status;
    uint64 m_openTickets;
    uint32 m_gmCount;
    time_t lastChange;
};

#define sTicketMgr (*ACE_Singleton<TicketMgr, ACE_Null_Mutex>::instance())

#endif // _TICKETMGR_H