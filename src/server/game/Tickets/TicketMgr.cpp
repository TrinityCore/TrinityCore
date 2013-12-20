/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "Common.h"
#include "TicketMgr.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "Language.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Chat.h"
#include "World.h"
#include "Player.h"
#include "Opcodes.h"

inline float GetAge(uint64 t) { return float(time(NULL) - t) / DAY; }

///////////////////////////////////////////////////////////////////////////////////////////////////
// GM ticket
GmTicket::GmTicket() : _id(0), _playerGuid(0), _posX(0), _posY(0), _posZ(0), _mapId(0), _createTime(0), _lastModifiedTime(0),
                       _closedBy(0), _assignedTo(0), _completed(false), _escalatedStatus(TICKET_UNASSIGNED), _viewed(false),
                       _needResponse(false), _haveTicket(false) { }

GmTicket::GmTicket(Player* player, WorldPacket& recvData) : _createTime(time(NULL)), _lastModifiedTime(time(NULL)), _closedBy(0), _assignedTo(0), _completed(false), _escalatedStatus(TICKET_UNASSIGNED), _viewed(false), _haveTicket(false)
{
    _id = sTicketMgr->GenerateTicketId();
    _playerName = player->GetName();
    _playerGuid = player->GetGUID();

    uint32 mapId;
    recvData >> mapId;                      // Map is sent as UInt32!
    _mapId = mapId;

    recvData >> _posX;
    recvData >> _posY;
    recvData >> _posZ;
    recvData >> _message;
    uint32 needResponse;
    recvData >> needResponse;
    _needResponse = (needResponse == 17);   // Requires GM response. 17 = true, 1 = false (17 is default)
    recvData >> _haveTicket;                // Requests further GM interaction on a ticket to which a GM has already responded. Basically means "has a new ticket"
}

GmTicket::~GmTicket() { }

bool GmTicket::LoadFromDB(Field* fields)
{
    //     0       1     2      3          4        5      6     7     8           9            10         11         12       13        14         15        16        17
    // ticketId, guid, name, message, createTime, mapId, posX, posY, posZ, lastModifiedTime, closedBy, assignedTo, comment, response, completed, escalated, viewed, haveTicket
    uint8 index = 0;
    _id                 = fields[  index].GetUInt32();
    _playerGuid         = MAKE_NEW_GUID(fields[++index].GetUInt32(), 0, HIGHGUID_PLAYER);
    _playerName         = fields[++index].GetString();
    _message            = fields[++index].GetString();
    _createTime         = fields[++index].GetUInt32();
    _mapId              = fields[++index].GetUInt16();
    _posX               = fields[++index].GetFloat();
    _posY               = fields[++index].GetFloat();
    _posZ               = fields[++index].GetFloat();
    _lastModifiedTime   = fields[++index].GetUInt32();
    _closedBy           = fields[++index].GetInt32();
    _assignedTo         = MAKE_NEW_GUID(fields[++index].GetUInt32(), 0, HIGHGUID_PLAYER);
    _comment            = fields[++index].GetString();
    _response           = fields[++index].GetString();
    _completed          = fields[++index].GetBool();
    _escalatedStatus    = GMTicketEscalationStatus(fields[++index].GetUInt8());
    _viewed             = fields[++index].GetBool();
    _haveTicket         = fields[++index].GetBool();
    return true;
}

void GmTicket::SaveToDB(SQLTransaction& trans) const
{
    //     0       1     2      3          4        5      6     7     8           9            10         11         12        13        14        15
    // ticketId, guid, name, message, createTime, mapId, posX, posY, posZ, lastModifiedTime, closedBy, assignedTo, comment, completed, escalated, viewed
    uint8 index = 0;
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_GM_TICKET);
    stmt->setUInt32(  index, _id);
    stmt->setUInt32(++index, GUID_LOPART(_playerGuid));
    stmt->setString(++index, _playerName);
    stmt->setString(++index, _message);
    stmt->setUInt32(++index, uint32(_createTime));
    stmt->setUInt16(++index, _mapId);
    stmt->setFloat (++index, _posX);
    stmt->setFloat (++index, _posY);
    stmt->setFloat (++index, _posZ);
    stmt->setUInt32(++index, uint32(_lastModifiedTime));
    stmt->setInt32 (++index, GUID_LOPART(_closedBy));
    stmt->setUInt32(++index, GUID_LOPART(_assignedTo));
    stmt->setString(++index, _comment);
    stmt->setString(++index, _response);
    stmt->setBool  (++index, _completed);
    stmt->setUInt8 (++index, uint8(_escalatedStatus));
    stmt->setBool  (++index, _viewed);
    stmt->setBool  (++index, _haveTicket);

    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void GmTicket::DeleteFromDB()
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GM_TICKET);
    stmt->setUInt32(0, _id);
    CharacterDatabase.Execute(stmt);
}

void GmTicket::WritePacket(WorldPacket& data) const
{
    data << uint32(GMTICKET_STATUS_HASTEXT);
    data << uint32(_id);
    data << _message;
    data << uint8(_haveTicket);
    data << GetAge(_lastModifiedTime);
    if (GmTicket* ticket = sTicketMgr->GetOldestOpenTicket())
        data << GetAge(ticket->GetLastModifiedTime());
    else
        data << float(0);

    // I am not sure how blizzlike this is, and we don't really have a way to find out
    data << GetAge(sTicketMgr->GetLastChange());

    data << uint8(std::min(_escalatedStatus, TICKET_IN_ESCALATION_QUEUE));                              // escalated data
    data << uint8(_viewed ? GMTICKET_OPENEDBYGM_STATUS_OPENED : GMTICKET_OPENEDBYGM_STATUS_NOT_OPENED); // whether or not it has been viewed
}

void GmTicket::SendResponse(WorldSession* session) const
{
    WorldPacket data(SMSG_GMRESPONSE_RECEIVED);
    data << uint32(1);          // responseID
    data << uint32(_id);        // ticketID
    data << _message.c_str();

    size_t len = _response.size();
    char const* s = _response.c_str();

    for (int i = 0; i < 4; i++)
    {
        if (len)
        {
            size_t writeLen = std::min<size_t>(len, 3999);
            data.append(s, writeLen);

            len -= writeLen;
            s += writeLen;
        }

        data << uint8(0);
    }

    session->SendPacket(&data);
}

std::string GmTicket::FormatMessageString(ChatHandler& handler, bool detailed) const
{
    time_t curTime = time(NULL);

    std::stringstream ss;
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTGUID, _id);
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTNAME, _playerName.c_str());
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTAGECREATE, (secsToTimeString(curTime - _createTime, true, false)).c_str());
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTAGE, (secsToTimeString(curTime - _lastModifiedTime, true, false)).c_str());

    std::string name;
    if (sObjectMgr->GetPlayerNameByGUID(_assignedTo, name))
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, name.c_str());

    if (detailed)
    {
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTMESSAGE, _message.c_str());
        if (!_comment.empty())
            ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTCOMMENT, _comment.c_str());
        if (!_response.empty())
            ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTRESPONSE, _response.c_str());
    }
    return ss.str();
}

std::string GmTicket::FormatMessageString(ChatHandler& handler, const char* szClosedName, const char* szAssignedToName, const char* szUnassignedName, const char* szDeletedName) const
{
    std::stringstream ss;
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTGUID, _id);
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTNAME, _playerName.c_str());
    if (szClosedName)
        ss << handler.PGetParseString(LANG_COMMAND_TICKETCLOSED, szClosedName);
    if (szAssignedToName)
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, szAssignedToName);
    if (szUnassignedName)
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTUNASSIGNED, szUnassignedName);
    if (szDeletedName)
        ss << handler.PGetParseString(LANG_COMMAND_TICKETDELETED, szDeletedName);
    return ss.str();
}

void GmTicket::SetUnassigned()
{
    _assignedTo = 0;
    switch (_escalatedStatus)
    {
        case TICKET_ASSIGNED: _escalatedStatus = TICKET_UNASSIGNED; break;
        case TICKET_ESCALATED_ASSIGNED: _escalatedStatus = TICKET_IN_ESCALATION_QUEUE; break;
        case TICKET_UNASSIGNED:
        case TICKET_IN_ESCALATION_QUEUE:
        default:
            break;
    }
}

void GmTicket::TeleportTo(Player* player) const
{
    player->TeleportTo(_mapId, _posX, _posY, _posZ, 0.0f, 0);
}

void GmTicket::SetChatLog(std::list<uint32> time, std::string const& log)
{
    std::stringstream ss(log);
    std::stringstream newss;
    std::string line;
    while (std::getline(ss, line))
    {
        newss << secsToTimeString(time.front()) << ": " << line << "\n";
        time.pop_front();
    }

    _chatLog = newss.str();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Ticket manager
TicketMgr::TicketMgr() : _status(true), _lastTicketId(0), _lastSurveyId(0), _openTicketCount(0),
    _lastChange(time(NULL)) { }

TicketMgr::~TicketMgr()
{
    for (GmTicketList::const_iterator itr = _ticketList.begin(); itr != _ticketList.end(); ++itr)
        delete itr->second;
}

void TicketMgr::Initialize()
{
    SetStatus(sWorld->getBoolConfig(CONFIG_ALLOW_TICKETS));
}

void TicketMgr::ResetTickets()
{
    for (GmTicketList::const_iterator itr = _ticketList.begin(); itr != _ticketList.end();)
    {
        if (itr->second->IsClosed())
        {
            uint32 ticketId = itr->second->GetId();
            ++itr;
            sTicketMgr->RemoveTicket(ticketId);
        }
        else
            ++itr;
    }

    _lastTicketId = 0;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_GM_TICKETS);

    CharacterDatabase.Execute(stmt);
}

void TicketMgr::LoadTickets()
{
    uint32 oldMSTime = getMSTime();

    for (GmTicketList::const_iterator itr = _ticketList.begin(); itr != _ticketList.end(); ++itr)
        delete itr->second;
    _ticketList.clear();

    _lastTicketId = 0;
    _openTicketCount = 0;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GM_TICKETS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 GM tickets. DB table `gm_tickets` is empty!");

        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();
        GmTicket* ticket = new GmTicket();
        if (!ticket->LoadFromDB(fields))
        {
            delete ticket;
            continue;
        }
        if (!ticket->IsClosed())
            ++_openTicketCount;

        // Update max ticket id if necessary
        uint32 id = ticket->GetId();
        if (_lastTicketId < id)
            _lastTicketId = id;

        _ticketList[id] = ticket;
        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u GM tickets in %u ms", count, GetMSTimeDiffToNow(oldMSTime));

}

void TicketMgr::LoadSurveys()
{
    // we don't actually load anything into memory here as there's no reason to
    _lastSurveyId = 0;

    uint32 oldMSTime = getMSTime();
    if (QueryResult result = CharacterDatabase.Query("SELECT MAX(surveyId) FROM gm_surveys"))
        _lastSurveyId = (*result)[0].GetUInt32();

    TC_LOG_INFO("server.loading", ">> Loaded GM Survey count from database in %u ms", GetMSTimeDiffToNow(oldMSTime));

}

void TicketMgr::AddTicket(GmTicket* ticket)
{
    _ticketList[ticket->GetId()] = ticket;
    if (!ticket->IsClosed())
        ++_openTicketCount;
    SQLTransaction trans = SQLTransaction(NULL);
    ticket->SaveToDB(trans);
}

void TicketMgr::CloseTicket(uint32 ticketId, int64 source)
{
    if (GmTicket* ticket = GetTicket(ticketId))
    {
        SQLTransaction trans = SQLTransaction(NULL);
        ticket->SetClosedBy(source);
        if (source)
            --_openTicketCount;
        ticket->SaveToDB(trans);
    }
}

void TicketMgr::RemoveTicket(uint32 ticketId)
{
    if (GmTicket* ticket = GetTicket(ticketId))
    {
        ticket->DeleteFromDB();
        _ticketList.erase(ticketId);
        delete ticket;
    }
}

void TicketMgr::ShowList(ChatHandler& handler, bool onlineOnly) const
{
    handler.SendSysMessage(onlineOnly ? LANG_COMMAND_TICKETSHOWONLINELIST : LANG_COMMAND_TICKETSHOWLIST);
    for (GmTicketList::const_iterator itr = _ticketList.begin(); itr != _ticketList.end(); ++itr)
        if (!itr->second->IsClosed() && !itr->second->IsCompleted())
            if (!onlineOnly || itr->second->GetPlayer())
                handler.SendSysMessage(itr->second->FormatMessageString(handler).c_str());
}

void TicketMgr::ShowClosedList(ChatHandler& handler) const
{
    handler.SendSysMessage(LANG_COMMAND_TICKETSHOWCLOSEDLIST);
    for (GmTicketList::const_iterator itr = _ticketList.begin(); itr != _ticketList.end(); ++itr)
        if (itr->second->IsClosed())
            handler.SendSysMessage(itr->second->FormatMessageString(handler).c_str());
}

void TicketMgr::ShowEscalatedList(ChatHandler& handler) const
{
    handler.SendSysMessage(LANG_COMMAND_TICKETSHOWESCALATEDLIST);
    for (GmTicketList::const_iterator itr = _ticketList.begin(); itr != _ticketList.end(); ++itr)
        if (!itr->second->IsClosed() && itr->second->GetEscalatedStatus() == TICKET_IN_ESCALATION_QUEUE)
            handler.SendSysMessage(itr->second->FormatMessageString(handler).c_str());
}

void TicketMgr::SendTicket(WorldSession* session, GmTicket* ticket) const
{
    WorldPacket data(SMSG_GMTICKET_GETTICKET, (ticket ? (4 + 4 + 1 + 4 + 4 + 4 + 1 + 1) : 4));

    if (ticket)
        ticket->WritePacket(data);
    else
        data << uint32(GMTICKET_STATUS_DEFAULT);

    session->SendPacket(&data);
}
