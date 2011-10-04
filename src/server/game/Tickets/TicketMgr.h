/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"

class ChatHandler;

// from blizzard lua
enum GMTicketSystemStatus
{
    GMTICKET_QUEUE_STATUS_DISABLED = 0,
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

class GmTicket
{
public:
    GmTicket();
    explicit GmTicket(Player* player, WorldPacket& recv_data);
    ~GmTicket();

    bool IsClosed() const { return _closedBy; }
    bool IsCompleted() const { return _completed; }
    bool IsFromPlayer(uint64 guid) const { return guid == _playerGuid; }
    bool IsAssigned() const { return _assignedTo != 0; }
    bool IsAssignedTo(uint64 guid) const { return guid == _assignedTo; }
    bool IsAssignedNotTo(uint64 guid) const { return IsAssigned() && !IsAssignedTo(guid); }

    uint32 GetId() const { return _id; }
    Player* GetPlayer() const { return ObjectAccessor::FindPlayer(_playerGuid); }
    std::string GetPlayerName() const { return _playerName; }
    std::string GetMessage() const { return _message; }
    Player* GetAssignedPlayer() const { return ObjectAccessor::FindPlayer(_assignedTo); }
    uint64 GetAssignedToGUID() const { return _assignedTo; }
    std::string GetAssignedToName() const
    {
        std::string name;
        // save queries if ticket is not assigned
        if (_assignedTo)
            sObjectMgr->GetPlayerNameByGUID(_assignedTo, name);

        return name;
    }
    uint64 GetLastModifiedTime() const { return _lastModifiedTime; }
    GMTicketEscalationStatus GetEscalatedStatus() const { return _escalatedStatus; }

    void SetEscalatedStatus(GMTicketEscalationStatus escalatedStatus) { _escalatedStatus = escalatedStatus; }
    void SetAssignedTo(uint64 guid, bool isAdmin)
    {
        _assignedTo = guid;
        if (isAdmin && _escalatedStatus == TICKET_IN_ESCALATION_QUEUE)
            _escalatedStatus = TICKET_ESCALATED_ASSIGNED;
        else if (_escalatedStatus == TICKET_UNASSIGNED)
            _escalatedStatus = TICKET_ASSIGNED;
    }
    void SetClosedBy(const int64& value) { _closedBy = value; }
    void SetMessage(const std::string& message)
    {
        _message = message;
        _lastModifiedTime = uint64(time(NULL));
    }
    void SetComment(const std::string& comment) { _comment = comment; }
    void SetViewed() { _viewed = true; }
    void SetUnassigned();

    void AppendResponse(const std::string& response) { _response += response; }

    bool LoadFromDB(Field* fields);
    void SaveToDB(SQLTransaction& trans) const;
    void DeleteFromDB();

    void WritePacket(WorldPacket& data) const;
    void SendResponse(WorldSession* session) const;

    void TeleportTo(Player* player) const;
    std::string FormatMessageString(ChatHandler& handler, bool detailed = false) const;
    std::string FormatMessageString(ChatHandler& handler, const char* szClosedName, const char* szAssignedToName, const char* szUnassignedName, const char* szDeletedName) const;

private:
    uint32 _id;
    uint64 _playerGuid;
    std::string _playerName;
    float _posX;
    float _posY;
    float _posZ;
    uint16 _mapId;
    std::string _message;
    uint64 _createTime;
    uint64 _lastModifiedTime;
    int64 _closedBy; // 0 = Open, -1 = Console, playerGuid = player abandoned ticket, other = GM who closed it.
    uint64 _assignedTo;
    std::string _comment;
    bool _completed;
    GMTicketEscalationStatus _escalatedStatus;
    bool _viewed;
    std::string _response;
};
typedef std::map<uint32, GmTicket*> GmTicketList;

class TicketMgr
{
    friend class ACE_Singleton<TicketMgr, ACE_Null_Mutex>;

private:
    TicketMgr();

public:
    void LoadTickets();
    void LoadSurveys();

    GmTicket* GetTicket(uint32 ticketId)
    {
        GmTicketList::iterator itr = _ticketList.find(ticketId);
        if (itr != _ticketList.end())
            return itr->second;

        return NULL;
    }

    GmTicket* GetTicketByPlayer(uint64 playerGuid)
    {
        for (GmTicketList::const_iterator itr = _ticketList.begin(); itr != _ticketList.end(); ++itr)
            if (itr->second && itr->second->IsFromPlayer(playerGuid) && !itr->second->IsClosed())
                return itr->second;

        return NULL;
    }

    GmTicket* GetOldestOpenTicket()
    {
        for (GmTicketList::const_iterator itr = _ticketList.begin(); itr != _ticketList.end(); ++itr)
            if (itr->second && !itr->second->IsClosed() && !itr->second->IsCompleted())
                return itr->second;

        return NULL;
    }

    void AddTicket(GmTicket* ticket);
    void CloseTicket(uint32 ticketId, int64 source = -1);
    void RemoveTicket(uint32 ticketId);

    bool GetStatus() const { return _status; }
    void SetStatus(bool status) { _status = status; }

    uint64 GetLastChange() const { return _lastChange; }
    void UpdateLastChange() { _lastChange = uint64(time(NULL)); }

    uint32 GenerateTicketId() { return ++_lastTicketId; }
    uint32 GetOpenTicketCount() const { return _openTicketCount; }
    uint32 GetNextSurveyID() { return ++_lastSurveyId; }

    void Initialize();
    void ResetTickets();

    void ShowList(ChatHandler& handler, bool onlineOnly) const;
    void ShowClosedList(ChatHandler& handler) const;
    void ShowEscalatedList(ChatHandler& handler) const;

    void SendTicket(WorldSession* session, GmTicket* ticket) const;

protected:
    void _RemoveTicket(uint32 ticketId, int64 source = -1, bool permanently = false);

    GmTicketList _ticketList;

    bool   _status;
    uint32 _lastTicketId;
    uint32 _lastSurveyId;
    uint32 _openTicketCount;
    uint64 _lastChange;
};

#define sTicketMgr ACE_Singleton<TicketMgr, ACE_Null_Mutex>::instance()

#endif // _TICKETMGR_H
