/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "TicketMgr.h"
#include "CharacterCache.h"
#include "Chat.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "GameTime.h"
#include "Language.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "TicketPackets.h"
#include "World.h"
#include "WorldSession.h"

inline float GetAge(uint64 t) { return float(GameTime::GetGameTime() - t) / float(DAY); }

///////////////////////////////////////////////////////////////////////////////////////////////////
// GM ticket
GmTicket::GmTicket() : _id(0), _type(TICKET_TYPE_OPEN), _mapId(0), _createTime(0), _lastModifiedTime(0),
                       _completed(false), _escalatedStatus(TICKET_UNASSIGNED), _viewed(false),
                       _needResponse(false), _needMoreHelp(false) { }

GmTicket::GmTicket(Player* player) : _type(TICKET_TYPE_OPEN), _mapId(0), _createTime(GameTime::GetGameTime()), _lastModifiedTime(GameTime::GetGameTime()),
                       _completed(false), _escalatedStatus(TICKET_UNASSIGNED), _viewed(false),
                       _needResponse(false), _needMoreHelp(false)
{
    _id = sTicketMgr->GenerateTicketId();
    _playerName = player->GetName();
    _playerGuid = player->GetGUID();
}

GmTicket::~GmTicket() { }

Player* GmTicket::GetPlayer() const
{
    return ObjectAccessor::FindPlayer(_playerGuid);
}

Player* GmTicket::GetAssignedPlayer() const
{
    return ObjectAccessor::FindPlayer(_assignedTo);
}

bool GmTicket::LoadFromDB(Field* fields)
{
    // 0    1        2        3         4            5        6     7     8     9           10           11         12         13        14        15        16         17         18
    // id, type, playerGuid, name, description, createTime, mapId, posX, posY, posZ, lastModifiedTime, closedBy, assignedTo, comment, response, completed, escalated, viewed, needMoreHelp
    uint8 index = 0;
    _id                 = fields[  index].GetUInt32();
    _type               = TicketType(fields[++index].GetUInt8());
    _playerGuid         = ObjectGuid::Create<HighGuid::Player>(fields[++index].GetUInt32());
    _playerName         = fields[++index].GetString();
    _description        = fields[++index].GetString();
    _createTime         = fields[++index].GetUInt32();
    _mapId              = fields[++index].GetUInt16();
    _pos.m_positionX    = fields[++index].GetFloat();
    _pos.m_positionY    = fields[++index].GetFloat();
    _pos.m_positionZ    = fields[++index].GetFloat();
    _lastModifiedTime   = fields[++index].GetUInt32();
    _closedBy           = fields[++index].GetUInt32() ? ObjectGuid::Create<HighGuid::Player>(fields[index].GetUInt32()) : ObjectGuid::Empty;
    _assignedTo         = fields[++index].GetUInt32() ? ObjectGuid::Create<HighGuid::Player>(fields[index].GetUInt32()) : ObjectGuid::Empty;
    _comment            = fields[++index].GetString();
    _response           = fields[++index].GetString();
    _completed          = fields[++index].GetBool();
    _escalatedStatus    = GMTicketEscalationStatus(fields[++index].GetUInt8());
    _viewed             = fields[++index].GetBool();
    _needMoreHelp       = fields[++index].GetBool();
    return true;
}

void GmTicket::SaveToDB(CharacterDatabaseTransaction trans) const
{
    //  0    1       2         3          4          5        6     7     8     9           10           11          12        13        14        15         16        17         18          19
    // id, type, playerGuid, name, description, createTime, mapId, posX, posY, posZ, lastModifiedTime, closedBy, assignedTo, comment, response, completed, escalated, viewed, needMoreHelp, resolvedBy
    uint8 index = 0;
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_GM_TICKET);
    stmt->setUInt32(  index, _id);
    stmt->setUInt8 (++index, uint8(_type));
    stmt->setUInt32(++index, _playerGuid.GetCounter());
    stmt->setString(++index, _playerName);
    stmt->setString(++index, _description);
    stmt->setUInt32(++index, uint32(_createTime));
    stmt->setUInt16(++index, _mapId);
    stmt->setFloat (++index, _pos.GetPositionX());
    stmt->setFloat (++index, _pos.GetPositionY());
    stmt->setFloat (++index, _pos.GetPositionZ());
    stmt->setUInt32(++index, uint32(_lastModifiedTime));
    stmt->setUInt32(++index, _closedBy.GetCounter());
    stmt->setUInt32(++index, _assignedTo.GetCounter());
    stmt->setString(++index, _comment);
    stmt->setString(++index, _response);
    stmt->setBool  (++index, _completed);
    stmt->setUInt8 (++index, uint8(_escalatedStatus));
    stmt->setBool  (++index, _viewed);
    stmt->setBool  (++index, _needMoreHelp);
    stmt->setInt32 (++index, int32(_resolvedBy.GetCounter()));

    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void GmTicket::DeleteFromDB()
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GM_TICKET);
    stmt->setUInt32(0, _id);
    CharacterDatabase.Execute(stmt);
}

void GmTicket::SendResponse(WorldSession* session) const
{
    WorldPackets::Ticket::GMTicketResponse gmTicketResponse;
    gmTicketResponse.ResponseID = 1;
    gmTicketResponse.TicketID = _id;
    gmTicketResponse.Description = _description;

    std::string_view responseText = _response;
    for (std::string_view& responseTextChunk : gmTicketResponse.ResponseText)
    {
        responseTextChunk = responseText.substr(0, 3999);
        responseText.remove_prefix(responseTextChunk.length());
    }

    session->SendPacket(gmTicketResponse.Write());
}

std::string GmTicket::FormatMessageString(ChatHandler& handler, bool detailed) const
{
    time_t curTime = GameTime::GetGameTime();

    std::stringstream ss;
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTGUID, _id);
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTNAME, _playerName.c_str());
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTAGECREATE, (secsToTimeString(curTime - _createTime, TimeFormat::ShortText)).c_str());
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTAGE, (secsToTimeString(curTime - _lastModifiedTime, TimeFormat::ShortText)).c_str());

    std::string name;
    if (sCharacterCache->GetCharacterNameByGuid(_assignedTo, name))
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, name.c_str());

    if (detailed)
    {
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTMESSAGE, _description.c_str());
        if (!_comment.empty())
            ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTCOMMENT, _comment.c_str());
        if (!_response.empty())
            ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTRESPONSE, _response.c_str());
    }
    return ss.str();
}

std::string GmTicket::FormatMessageString(ChatHandler& handler, char const* closedName, char const* assignedToName, char const* unassignedName, char const* deletedName, char const* completedName) const
{
    std::stringstream ss;
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTGUID, _id);
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTNAME, _playerName.c_str());
    if (closedName)
        ss << handler.PGetParseString(LANG_COMMAND_TICKETCLOSED, closedName);
    if (assignedToName)
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, assignedToName);
    if (unassignedName)
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTUNASSIGNED, unassignedName);
    if (deletedName)
        ss << handler.PGetParseString(LANG_COMMAND_TICKETDELETED, deletedName);
    if (completedName)
        ss << handler.PGetParseString(LANG_COMMAND_TICKETCOMPLETED, completedName);
    return ss.str();
}

void GmTicket::SetDescription(std::string const& message)
{
    _description = message;
    _lastModifiedTime = uint64(GameTime::GetGameTime());
}

void GmTicket::SetUnassigned()
{
    _assignedTo.Clear();
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

void GmTicket::SetPosition(uint32 mapId, Position const& pos)
{
    _mapId = mapId;
    _pos = pos;
}

void GmTicket::SetGmAction(uint32 needResponse, bool needMoreHelp)
{
    _needResponse = (needResponse == 17);   // Requires GM response. 17 = true, 1 = false (17 is default)
    _needMoreHelp = needMoreHelp;           // Requests further GM interaction on a ticket to which a GM has already responded. Basically means "has a new ticket"
}

void GmTicket::TeleportTo(Player* player) const
{
    player->TeleportTo(_mapId, _pos.GetPositionX(), _pos.GetPositionY(), _pos.GetPositionZ(), 0.0f, 0);
}

void GmTicket::SetChatLog(std::span<uint32 const> times, std::string const& log)
{
    _chatLog.clear();
    std::vector<std::string_view> lines = Trinity::Tokenize(log, '\n', false);
    if (times.size() != lines.size())
        return;

    for (std::size_t i = 0; i < lines.size(); ++i)
    {
        using namespace std::string_view_literals;

        _chatLog += secsToTimeString(times[i]);
        _chatLog += ": "sv;
        _chatLog += lines[i];
        _chatLog += "\n"sv;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Ticket manager
TicketMgr::TicketMgr() : _status(true), _lastTicketId(0), _lastSurveyId(0), _openTicketCount(0),
    _lastChange(GameTime::GetGameTime()) { }

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

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_GM_TICKETS);

    CharacterDatabase.Execute(stmt);
}

TicketMgr* TicketMgr::instance()
{
    static TicketMgr instance;
    return &instance;
}

void TicketMgr::LoadTickets()
{
    uint32 oldMSTime = getMSTime();

    for (GmTicketList::const_iterator itr = _ticketList.begin(); itr != _ticketList.end(); ++itr)
        delete itr->second;
    _ticketList.clear();

    _lastTicketId = 0;
    _openTicketCount = 0;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GM_TICKETS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 GM tickets. DB table `gm_ticket` is empty!");

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

    TC_LOG_INFO("server.loading", ">> Loaded {} GM tickets in {} ms", count, GetMSTimeDiffToNow(oldMSTime));

}

void TicketMgr::LoadSurveys()
{
    // we don't actually load anything into memory here as there's no reason to
    _lastSurveyId = 0;

    uint32 oldMSTime = getMSTime();
    if (QueryResult result = CharacterDatabase.Query("SELECT MAX(surveyId) FROM gm_survey"))
        _lastSurveyId = (*result)[0].GetUInt32();

    TC_LOG_INFO("server.loading", ">> Loaded GM Survey count from database in {} ms", GetMSTimeDiffToNow(oldMSTime));

}

void TicketMgr::AddTicket(GmTicket* ticket)
{
    _ticketList[ticket->GetId()] = ticket;
    if (!ticket->IsClosed())
        ++_openTicketCount;
    CharacterDatabaseTransaction trans = CharacterDatabaseTransaction(nullptr);
    ticket->SaveToDB(trans);
}

void TicketMgr::CloseTicket(uint32 ticketId, ObjectGuid source)
{
    if (GmTicket* ticket = GetTicket(ticketId))
    {
        CharacterDatabaseTransaction trans = CharacterDatabaseTransaction(nullptr);
        ticket->SetClosedBy(source);
        if (!source.IsEmpty())
            --_openTicketCount;
        ticket->SaveToDB(trans);
    }
}

void TicketMgr::ResolveAndCloseTicket(uint32 ticketId, ObjectGuid source)
{
    if (GmTicket* ticket = GetTicket(ticketId))
    {
        CharacterDatabaseTransaction trans = CharacterDatabaseTransaction(nullptr);
        ticket->SetClosedBy(source);
        ticket->SetResolvedBy(source);
        if (!source.IsEmpty())
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

void TicketMgr::UpdateLastChange()
{
    _lastChange = uint64(GameTime::GetGameTime());
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
    WorldPackets::Ticket::GMTicketGetTicketResponse response;

    if (ticket)
    {
        response.Result = GMTICKET_STATUS_HASTEXT;

        WorldPackets::Ticket::GMTicketInfo& ticketInfo = response.Info;
        ticketInfo.TicketID = ticket->GetId();
        ticketInfo.TicketDescription = ticket->GetMessage();
        ticketInfo.Category = ticket->GetNeedMoreHelp();
        ticketInfo.TicketOpenTime = GetAge(ticket->GetLastModifiedTime());
        if (GmTicket const* oldestTicket = sTicketMgr->GetOldestOpenTicket())
            ticketInfo.OldestTicketTime = GetAge(oldestTicket->GetLastModifiedTime());

        ticketInfo.UpdateTime = GetAge(sTicketMgr->GetLastChange());
        ticketInfo.AssignedToGM = std::min(ticket->GetEscalatedStatus(), TICKET_IN_ESCALATION_QUEUE);
        ticketInfo.OpenedByGM = ticket->IsViewed() ? GMTICKET_OPENEDBYGM_STATUS_OPENED : GMTICKET_OPENEDBYGM_STATUS_NOT_OPENED;
    }
    else
        response.Result = GMTICKET_STATUS_DEFAULT;

    session->SendPacket(response.Write());
}

std::string GmTicket::GetAssignedToName() const
{
    std::string name;
    // save queries if ticket is not assigned
    if (!_assignedTo.IsEmpty())
        sCharacterCache->GetCharacterNameByGuid(_assignedTo, name);

    return name;
}
