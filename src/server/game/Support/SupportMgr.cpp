/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "Chat.h"
#include "Language.h"
#include "SupportMgr.h"

inline time_t GetAge(uint64 t) { return (time(nullptr) - t) / DAY; }

Ticket::Ticket() : _id(0), _mapId(0), _createTime(0) { }

Ticket::Ticket(Player* player) : _id(0), _mapId(0), _createTime(time(nullptr))
{
    _playerGuid = player->GetGUID();
}

Ticket::~Ticket() { }

void Ticket::TeleportTo(Player* player) const
{
    player->TeleportTo(_mapId, _pos.x, _pos.y, _pos.z, 0.0f, 0);
}

std::string Ticket::FormatViewMessageString(ChatHandler& handler, char const* closedName, char const* assignedToName, char const* unassignedName, char const* deletedName, char const* /*completedName*/) const
{
    std::stringstream ss;
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTGUID, _id);
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTNAME, GetPlayer()->GetName().c_str());
    if (closedName)
        ss << handler.PGetParseString(LANG_COMMAND_TICKETCLOSED, closedName);
    if (assignedToName)
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, assignedToName);
    if (unassignedName)
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTUNASSIGNED, unassignedName);
    if (deletedName)
        ss << handler.PGetParseString(LANG_COMMAND_TICKETDELETED, deletedName);
    return ss.str();
}

GmTicket::GmTicket() : _lastModifiedTime(0), _completed(false), _escalatedStatus(TICKET_UNASSIGNED), _viewed(false), _needResponse(false), _needMoreHelp(false) { }

GmTicket::GmTicket(Player* player) : Ticket(player), _lastModifiedTime(time(nullptr)), _completed(false), _escalatedStatus(TICKET_UNASSIGNED),
_viewed(false), _needResponse(false), _needMoreHelp(false)
{
    _id = sSupportMgr->GenerateGmTicketId();
}

GmTicket::~GmTicket() { }

void GmTicket::SetGmAction(uint32 needResponse, bool needMoreHelp)
{
    _needResponse = (needResponse == 17);   // Requires GM response. 17 = true, 1 = false (17 is default)
    _needMoreHelp = needMoreHelp;           // Requests further GM interaction on a ticket to which a GM has already responded. Basically means "has a new ticket"
}

void GmTicket::SetUnassigned()
{
    _assignedTo.Clear();
    switch (_escalatedStatus)
    {
        case TICKET_ASSIGNED: _escalatedStatus = TICKET_UNASSIGNED;
            break;
        case TICKET_ESCALATED_ASSIGNED: _escalatedStatus = TICKET_IN_ESCALATION_QUEUE;
            break;
        case TICKET_UNASSIGNED:
        case TICKET_IN_ESCALATION_QUEUE:
        default:
            break;
    }
}

void GmTicket::SetChatLog(std::list<uint32> time, std::string const& log)
{
    std::stringstream ss(log);
    std::stringstream newss;
    std::string line;
    while (std::getline(ss, line) && !time.empty())
    {
        newss << secsToTimeString(time.front()) << ": " << line << "\n";
        time.pop_front();
    }

    _chatLog = newss.str();
}

void GmTicket::SendResponse(WorldSession* session) const
{
    WorldPackets::Ticket::GMTicketResponse resp;
    resp.TicketID = GetId();
    resp.ResponseID = 2; //TODO : research
    resp.Description = GetDescription();
    resp.ResponseText = GetResponse();

    session->SendPacket(resp.Write());
}

void GmTicket::LoadFromDB(Field* fields)
{
    uint8 idx = 0;
    _id                 = fields[  idx].GetUInt32();
    _playerGuid         = ObjectGuid::Create<HighGuid::Player>(fields[++idx].GetUInt64());
    _description        = fields[++idx].GetString();
    _createTime         = fields[++idx].GetUInt32();
    _mapId              = fields[++idx].GetUInt16();
    _pos.x              = fields[++idx].GetFloat();
    _pos.y              = fields[++idx].GetFloat();
    _pos.z              = fields[++idx].GetFloat();
    _lastModifiedTime   = fields[++idx].GetUInt32();

    int64 closedBy      = fields[++idx].GetInt64();
    if (closedBy == 0)
        _closedBy = ObjectGuid::Empty;
    else if (closedBy < 0)
        _closedBy.SetRawValue(0, uint64(closedBy));
    else
        _closedBy = ObjectGuid::Create<HighGuid::Player>(uint64(closedBy));

    uint64 assignedTo   = fields[++idx].GetUInt64();
    if (assignedTo == 0)
        _assignedTo = ObjectGuid::Empty;
    else
        _assignedTo = ObjectGuid::Create<HighGuid::Player>(assignedTo);

    _comment            = fields[++idx].GetString();
    _response           = fields[++idx].GetString();
    _completed          = fields[++idx].GetBool();
    _escalatedStatus    = GMTicketEscalationStatus(fields[++idx].GetUInt8());
    _viewed             = fields[++idx].GetBool();
    _needMoreHelp       = fields[++idx].GetBool();
}

void GmTicket::SaveToDB(SQLTransaction& trans) const
{
    uint8 idx = 0;
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_GM_TICKET);
    stmt->setUInt32(idx, _id);
    stmt->setUInt64(++idx, _playerGuid.GetCounter());
    stmt->setString(++idx, _description);
    stmt->setUInt32(++idx, _createTime);
    stmt->setUInt16(++idx, _mapId);
    stmt->setFloat(++idx, _pos.x);
    stmt->setFloat(++idx, _pos.y);
    stmt->setFloat(++idx, _pos.z);
    stmt->setUInt32(++idx, uint32(_lastModifiedTime));
    stmt->setInt64(++idx, int64(_closedBy.GetCounter()));
    stmt->setUInt64(++idx, _assignedTo.GetCounter());
    stmt->setString(++idx, _comment);
    stmt->setString(++idx, _response);
    stmt->setBool(++idx, _completed);
    stmt->setUInt8(++idx, uint8(_escalatedStatus));
    stmt->setBool(++idx, _viewed);
    stmt->setBool(++idx, _needMoreHelp);

    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void GmTicket::DeleteFromDB()
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GM_TICKET);
    stmt->setUInt32(0, _id);
    CharacterDatabase.Execute(stmt);
}

std::string GmTicket::FormatViewMessageString(ChatHandler& handler, bool detailed) const
{
    time_t curTime = time(nullptr);

    std::stringstream ss;
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTGUID, _id);
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTNAME, GetPlayer()->GetName().c_str());
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTAGECREATE, (secsToTimeString(curTime - _createTime, true, false)).c_str());
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTAGE, (secsToTimeString(curTime - _lastModifiedTime, true, false)).c_str());

    std::string name;
    if (ObjectMgr::GetPlayerNameByGUID(_assignedTo, name))
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

std::string GmTicket::FormatViewMessageString(ChatHandler& handler, const char* szClosedName, const char* szAssignedToName, const char* szUnassignedName, const char* szDeletedName, const char* szCompletedName) const
{
    std::stringstream ss;
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTGUID, _id);
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTNAME, GetPlayer()->GetName().c_str());
    if (szClosedName)
        ss << handler.PGetParseString(LANG_COMMAND_TICKETCLOSED, szClosedName);
    if (szAssignedToName)
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, szAssignedToName);
    if (szUnassignedName)
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTUNASSIGNED, szUnassignedName);
    if (szDeletedName)
        ss << handler.PGetParseString(LANG_COMMAND_TICKETDELETED, szDeletedName);
    if (szCompletedName)
        ss << handler.PGetParseString(LANG_COMMAND_TICKETCOMPLETED, szCompletedName);
    return ss.str();
}

BugTicket::BugTicket() : _facing(0.0f) { }

BugTicket::BugTicket(Player* player) : Ticket(player), _facing(0.0f)
{
    _id = sSupportMgr->GenerateBugId();
}

BugTicket::~BugTicket() { }

void BugTicket::LoadFromDB(Field* fields)
{
    uint8 idx = 0;
    _id                 = fields[  idx].GetUInt32();
    _playerGuid         = ObjectGuid::Create<HighGuid::Player>(fields[++idx].GetUInt64());
    _note               = fields[++idx].GetString();
    _createTime         = fields[++idx].GetUInt32();
    _mapId              = fields[++idx].GetUInt32();
    _pos.x              = fields[++idx].GetFloat();
    _pos.y              = fields[++idx].GetFloat();
    _pos.z              = fields[++idx].GetFloat();
    _facing             = fields[++idx].GetFloat();

    int64 closedBy      = fields[++idx].GetInt64();
    if (closedBy == 0)
        _closedBy = ObjectGuid::Empty;
    else if (closedBy < 0)
        _closedBy.SetRawValue(0, uint64(closedBy));
    else
        _closedBy = ObjectGuid::Create<HighGuid::Player>(uint64(closedBy));

    uint64 assignedTo   = fields[++idx].GetUInt64();
    if (assignedTo == 0)
        _assignedTo = ObjectGuid::Empty;
    else
        _assignedTo = ObjectGuid::Create<HighGuid::Player>(assignedTo);

    _comment            = fields[++idx].GetString();
}

void BugTicket::SaveToDB(SQLTransaction& trans) const
{
    uint8 idx = 0;
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_GM_BUG);
    stmt->setUInt32(idx, _id);
    stmt->setUInt64(++idx, _playerGuid.GetCounter());
    stmt->setString(++idx, _note);
    stmt->setUInt32(++idx, _mapId);
    stmt->setFloat(++idx, _pos.x);
    stmt->setFloat(++idx, _pos.y);
    stmt->setFloat(++idx, _pos.z);
    stmt->setFloat(++idx, _facing);
    stmt->setInt64(++idx, _closedBy.GetCounter());
    stmt->setUInt64(++idx, _assignedTo.GetCounter());
    stmt->setString(++idx, _comment);

    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void BugTicket::DeleteFromDB()
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GM_BUG);
    stmt->setUInt32(0, _id);
    CharacterDatabase.Execute(stmt);
}

std::string BugTicket::FormatViewMessageString(ChatHandler& handler, bool detailed) const
{
    time_t curTime = time(nullptr);

    std::stringstream ss;
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTGUID, _id);
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTNAME, GetPlayer()->GetName().c_str());
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTAGECREATE, (secsToTimeString(curTime - _createTime, true, false)).c_str());

    std::string name;
    if (ObjectMgr::GetPlayerNameByGUID(_assignedTo, name))
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, name.c_str());

    if (detailed)
    {
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTMESSAGE, _note.c_str());
        if (!_comment.empty())
            ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTCOMMENT, _comment.c_str());
    }
    return ss.str();
}

ComplaintTicket::ComplaintTicket() : _facing(0.0f), _complaintType(GMTICKET_SUPPORT_COMPLAINT_TYPE_NONE) { }

ComplaintTicket::ComplaintTicket(Player* player) : Ticket(player), _facing(0.0f), _complaintType(GMTICKET_SUPPORT_COMPLAINT_TYPE_NONE)
{
    _id = sSupportMgr->GenerateComplaintId();
}

ComplaintTicket::~ComplaintTicket() { }

void ComplaintTicket::LoadFromDB(Field* fields)
{
    uint8 idx = 0;
    _id                     = fields[  idx].GetUInt32();
    _playerGuid             = ObjectGuid::Create<HighGuid::Player>(fields[++idx].GetUInt64());
    _note                   = fields[++idx].GetString();
    _createTime             = fields[++idx].GetUInt32();
    _mapId                  = fields[++idx].GetUInt32();
    _pos.x                  = fields[++idx].GetFloat();
    _pos.y                  = fields[++idx].GetFloat();
    _pos.z                  = fields[++idx].GetFloat();
    _facing                 = fields[++idx].GetFloat();
    _targetCharacterGuid    = ObjectGuid::Create<HighGuid::Player>(fields[++idx].GetUInt64());
    _complaintType          = GMSupportComplaintType(fields[++idx].GetUInt8());
    int32 reportLineIndex = fields[++idx].GetInt32();
    if (reportLineIndex != -1)
        _chatLog.ReportLineIndex.Set(reportLineIndex);

    int64 closedBy = fields[++idx].GetInt64();
    if (closedBy == 0)
        _closedBy = ObjectGuid::Empty;
    else if (closedBy < 0)
        _closedBy.SetRawValue(0, uint64(closedBy));
    else
        _closedBy = ObjectGuid::Create<HighGuid::Player>(uint64(closedBy));

    uint64 assignedTo       = fields[++idx].GetUInt64();
    if (assignedTo == 0)
        _assignedTo = ObjectGuid::Empty;
    else
        _assignedTo = ObjectGuid::Create<HighGuid::Player>(assignedTo);

    _comment                = fields[++idx].GetString();
}

void ComplaintTicket::LoadChatLineFromDB(Field* fields)
{
    _chatLog.Lines.emplace_back(fields[0].GetUInt32(), fields[1].GetString());
}

void ComplaintTicket::SaveToDB(SQLTransaction& trans) const
{
    bool isInTransaction = bool(trans);
    if (!isInTransaction)
        trans = CharacterDatabase.BeginTransaction();

    uint8 idx = 0;
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_GM_COMPLAINT);
    stmt->setUInt32(idx, _id);
    stmt->setUInt64(++idx, _playerGuid.GetCounter());
    stmt->setString(++idx, _note);
    stmt->setUInt32(++idx, _mapId);
    stmt->setFloat(++idx, _pos.x);
    stmt->setFloat(++idx, _pos.y);
    stmt->setFloat(++idx, _pos.z);
    stmt->setFloat(++idx, _facing);
    stmt->setUInt64(++idx, _targetCharacterGuid.GetCounter());
    stmt->setUInt8(++idx, _complaintType);
    if (_chatLog.ReportLineIndex.HasValue)
        stmt->setInt32(++idx, _chatLog.ReportLineIndex.Value);
    else
        stmt->setInt32(++idx, -1); // empty ReportLineIndex
    stmt->setInt64(++idx, _closedBy.GetCounter());
    stmt->setUInt64(++idx, _assignedTo.GetCounter());
    stmt->setString(++idx, _comment);
    trans->Append(stmt);

    uint32 lineIndex = 0;
    for (auto const& c : _chatLog.Lines)
    {
        idx = 0;
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GM_COMPLAINT_CHATLINE);
        stmt->setUInt32(idx, _id);
        stmt->setUInt32(++idx, lineIndex);
        stmt->setUInt32(++idx, c.Timestamp);
        stmt->setString(++idx, c.Text);

        trans->Append(stmt);
        ++lineIndex;
    }

    if (!isInTransaction)
        CharacterDatabase.CommitTransaction(trans);
}

void ComplaintTicket::DeleteFromDB()
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GM_COMPLAINT);
    stmt->setUInt32(0, _id);
    CharacterDatabase.Execute(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GM_COMPLAINT_CHATLOG);
    stmt->setUInt32(0, _id);
}

std::string ComplaintTicket::FormatViewMessageString(ChatHandler& handler, bool detailed) const
{
    time_t curTime = time(nullptr);

    std::stringstream ss;
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTGUID, _id);
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTNAME, GetPlayer()->GetName().c_str());
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTAGECREATE, (secsToTimeString(curTime - _createTime, true, false)).c_str());

    std::string name;
    if (ObjectMgr::GetPlayerNameByGUID(_assignedTo, name))
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, name.c_str());

    if (detailed)
    {
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTMESSAGE, _note.c_str());
        if (!_comment.empty())
            ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTCOMMENT, _comment.c_str());
    }
    return ss.str();
}

SuggestionTicket::SuggestionTicket() : _facing(0.0f) { }

SuggestionTicket::SuggestionTicket(Player* player) : Ticket(player), _facing(0.0f)
{
    _id = sSupportMgr->GenerateSuggestionId();
}

SuggestionTicket::~SuggestionTicket() { }

void SuggestionTicket::LoadFromDB(Field* fields)
{
    uint8 idx = 0;
    _id                 = fields[  idx].GetUInt32();
    _playerGuid         = ObjectGuid::Create<HighGuid::Player>(fields[++idx].GetUInt64());
    _note               = fields[++idx].GetString();
    _createTime         = fields[++idx].GetUInt32();
    _mapId              = fields[++idx].GetUInt32();
    _pos.x              = fields[++idx].GetFloat();
    _pos.y              = fields[++idx].GetFloat();
    _pos.z              = fields[++idx].GetFloat();
    _facing             = fields[++idx].GetFloat();

    int64 closedBy = fields[++idx].GetInt64();
    if (closedBy == 0)
        _closedBy = ObjectGuid::Empty;
    else if (closedBy < 0)
        _closedBy.SetRawValue(0, uint64(closedBy));
    else
        _closedBy = ObjectGuid::Create<HighGuid::Player>(uint64(closedBy));

    uint64 assignedTo   = fields[++idx].GetUInt64();
    if (assignedTo == 0)
        _assignedTo = ObjectGuid::Empty;
    else
        _assignedTo = ObjectGuid::Create<HighGuid::Player>(assignedTo);

    _comment            = fields[++idx].GetString();
}

void SuggestionTicket::SaveToDB(SQLTransaction& trans) const
{
    uint8 idx = 0;
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_GM_SUGGESTION);
    stmt->setUInt32(idx, _id);
    stmt->setUInt64(++idx, _playerGuid.GetCounter());
    stmt->setString(++idx, _note);
    stmt->setUInt32(++idx, _mapId);
    stmt->setFloat(++idx, _pos.x);
    stmt->setFloat(++idx, _pos.y);
    stmt->setFloat(++idx, _pos.z);
    stmt->setFloat(++idx, _facing);
    stmt->setInt64(++idx, _closedBy.GetCounter());
    stmt->setUInt64(++idx, _assignedTo.GetCounter());
    stmt->setString(++idx, _comment);

    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void SuggestionTicket::DeleteFromDB()
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GM_SUGGESTION);
    stmt->setUInt32(0, _id);
    CharacterDatabase.Execute(stmt);
}

std::string SuggestionTicket::FormatViewMessageString(ChatHandler& handler, bool detailed) const
{
    time_t curTime = time(nullptr);

    std::stringstream ss;
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTGUID, _id);
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTNAME, GetPlayer()->GetName().c_str());
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTAGECREATE, (secsToTimeString(curTime - _createTime, true, false)).c_str());

    std::string name;
    if (ObjectMgr::GetPlayerNameByGUID(_assignedTo, name))
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, name.c_str());

    if (detailed)
    {
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTMESSAGE, _note.c_str());
        if (!_comment.empty())
            ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTCOMMENT, _comment.c_str());
    }
    return ss.str();
}

SupportMgr::SupportMgr() : _lastGmTicketId(0), _lastBugId(0), _lastComplaintId(0), _lastSuggestionId(0), _openGmTicketCount(0),
_openBugTicketCount(0), _openComplaintTicketCount(0), _openSuggestionTicketCount(0) { }

SupportMgr::~SupportMgr()
{
    for (auto const& t : _gmTicketList)
        delete t.second;

    for (auto const& b : _bugTicketList)
        delete b.second;

    for (auto const& c : _complaintTicketList)
        delete c.second;

    for (auto const& s : _suggestionTicketList)
        delete s.second;
}

void SupportMgr::Initialize()
{
    SetSupportSystemStatus(sWorld->getBoolConfig(CONFIG_SUPPORT_ENABLED));
    SetTicketSystemStatus(sWorld->getBoolConfig(CONFIG_SUPPORT_TICKETS_ENABLED));
    SetBugSystemStatus(sWorld->getBoolConfig(CONFIG_SUPPORT_BUGS_ENABLED));
    SetComplaintSystemStatus(sWorld->getBoolConfig(CONFIG_SUPPORT_COMPLAINTS_ENABLED));
    SetSuggestionSystemStatus(sWorld->getBoolConfig(CONFIG_SUPPORT_SUGGESTIONS_ENABLED));
}

template<>
GmTicket* SupportMgr::GetTicket<GmTicket>(uint32 ticketId)
{
    GmTicketList::const_iterator itr = _gmTicketList.find(ticketId);
    if (itr != _gmTicketList.end())
        return itr->second;

    return nullptr;

}

template<>
BugTicket* SupportMgr::GetTicket<BugTicket>(uint32 bugId)
{
    BugTicketList::const_iterator itr = _bugTicketList.find(bugId);
    if (itr != _bugTicketList.end())
        return itr->second;

    return nullptr;

}

template<>
ComplaintTicket* SupportMgr::GetTicket<ComplaintTicket>(uint32 complaintId)
{
    ComplaintTicketList::const_iterator itr = _complaintTicketList.find(complaintId);
    if (itr != _complaintTicketList.end())
        return itr->second;

    return nullptr;
}

template<>
SuggestionTicket* SupportMgr::GetTicket<SuggestionTicket>(uint32 suggestionId)
{
    SuggestionTicketList::const_iterator itr = _suggestionTicketList.find(suggestionId);
    if (itr != _suggestionTicketList.end())
        return itr->second;

    return nullptr;

}

template<>
uint32 SupportMgr::GetOpenTicketCount<GmTicket>() const { return _openGmTicketCount; }

template<>
uint32 SupportMgr::GetOpenTicketCount<BugTicket>() const { return _openBugTicketCount; }

template<>
uint32 SupportMgr::GetOpenTicketCount<ComplaintTicket>() const { return _openComplaintTicketCount; }

template<>
uint32 SupportMgr::GetOpenTicketCount<SuggestionTicket>() const { return _openSuggestionTicketCount; }

void SupportMgr::LoadGmTickets()
{
    uint32 oldMSTime = getMSTime();

    for (auto const& c : _gmTicketList)
        delete c.second;
    _gmTicketList.clear();

    _lastGmTicketId = 0;
    _openGmTicketCount = 0;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GM_TICKETS);
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
        ticket->LoadFromDB(fields);

        if (!ticket->IsClosed())
            ++_openGmTicketCount;

        uint32 id = ticket->GetId();
        if (_lastGmTicketId < id)
            _lastGmTicketId = id;

        _gmTicketList[id] = ticket;
        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u GM tickets in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SupportMgr::LoadBugTickets()
{
    uint32 oldMSTime = getMSTime();

    for (auto const& c : _bugTicketList)
        delete c.second;
    _bugTicketList.clear();

    _lastBugId = 0;
    _openBugTicketCount = 0;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GM_BUGS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 GM bugs. DB table `gm_bug` is empty!");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();
        BugTicket* bug = new BugTicket();
        bug->LoadFromDB(fields);

        if (!bug->IsClosed())
            ++_openBugTicketCount;

        uint32 id = bug->GetId();
        if (_lastBugId < id)
            _lastBugId = id;

        _bugTicketList[id] = bug;
        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u GM bugs in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SupportMgr::LoadComplaintTickets()
{
    uint32 oldMSTime = getMSTime();

    for (auto const& c : _complaintTicketList)
        delete c.second;
    _complaintTicketList.clear();

    _lastComplaintId = 0;
    _openComplaintTicketCount = 0;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GM_COMPLAINTS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 GM complaints. DB table `gm_complaint` is empty!");
        return;
    }

    uint32 count = 0;
    PreparedStatement* chatLogStmt;
    PreparedQueryResult chatLogResult;
    do
    {
        Field* fields = result->Fetch();
        ComplaintTicket* complaint = new ComplaintTicket();
        complaint->LoadFromDB(fields);

        if (!complaint->IsClosed())
            ++_openComplaintTicketCount;

        uint32 id = complaint->GetId();
        if (_lastComplaintId < id)
            _lastComplaintId = id;

        chatLogStmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GM_COMPLAINT_CHATLINES);
        chatLogStmt->setUInt32(0, id);
        chatLogResult = CharacterDatabase.Query(chatLogStmt);

        if (chatLogResult)
        {
            do
            {
                Field* chatLineFields = chatLogResult->Fetch();
                complaint->LoadChatLineFromDB(chatLineFields);
            } while (chatLogResult->NextRow());
        }

        _complaintTicketList[id] = complaint;
        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u GM complaints in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SupportMgr::LoadSuggestionTickets()
{
    uint32 oldMSTime = getMSTime();

    for (auto const& c : _suggestionTicketList)
        delete c.second;
    _suggestionTicketList.clear();

    _lastSuggestionId = 0;
    _openSuggestionTicketCount = 0;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GM_SUGGESTIONS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 GM suggestions. DB table `gm_suggestion` is empty!");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();
        SuggestionTicket* suggestion = new SuggestionTicket();
        suggestion->LoadFromDB(fields);

        if (!suggestion->IsClosed())
            ++_openSuggestionTicketCount;

        uint32 id = suggestion->GetId();
        if (_lastSuggestionId < id)
            _lastSuggestionId = id;

        _suggestionTicketList[id] = suggestion;
        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u GM suggestions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SupportMgr::AddTicket(GmTicket* ticket)
{
    _gmTicketList[ticket->GetId()] = ticket;
    if (!ticket->IsClosed())
        ++_openGmTicketCount;

    SQLTransaction trans = SQLTransaction(nullptr);
    ticket->SaveToDB(trans);
}

void SupportMgr::AddTicket(BugTicket* ticket)
{
    _bugTicketList[ticket->GetId()] = ticket;
    if (!ticket->IsClosed())
        ++_openBugTicketCount;

    SQLTransaction trans = SQLTransaction(nullptr);
    ticket->SaveToDB(trans);
}

void SupportMgr::AddTicket(ComplaintTicket* ticket)
{
    _complaintTicketList[ticket->GetId()] = ticket;
    if (!ticket->IsClosed())
        ++_openComplaintTicketCount;

    SQLTransaction trans = SQLTransaction(nullptr);
    ticket->SaveToDB(trans);
}

void SupportMgr::AddTicket(SuggestionTicket* ticket)
{
    _suggestionTicketList[ticket->GetId()] = ticket;
    if (!ticket->IsClosed())
        ++_openSuggestionTicketCount;

    SQLTransaction trans = SQLTransaction(nullptr);
    ticket->SaveToDB(trans);
}

template<>
void SupportMgr::RemoveTicket<GmTicket>(uint32 ticketId)
{
    if (GmTicket* ticket = GetTicket<GmTicket>(ticketId))
    {
        ticket->DeleteFromDB();
        _gmTicketList.erase(ticketId);
        delete ticket;
    }
}

template<>
void SupportMgr::RemoveTicket<BugTicket>(uint32 ticketId)
{
    if (BugTicket* ticket = GetTicket<BugTicket>(ticketId))
    {
        ticket->DeleteFromDB();
        _bugTicketList.erase(ticketId);
        delete ticket;
    }
}

template<>
void SupportMgr::RemoveTicket<ComplaintTicket>(uint32 ticketId)
{
    if (ComplaintTicket* ticket = GetTicket<ComplaintTicket>(ticketId))
    {
        ticket->DeleteFromDB();
        _complaintTicketList.erase(ticketId);
        delete ticket;
    }
}

template<>
void SupportMgr::RemoveTicket<SuggestionTicket>(uint32 ticketId)
{
    if (SuggestionTicket* ticket = GetTicket<SuggestionTicket>(ticketId))
    {
        ticket->DeleteFromDB();
        _suggestionTicketList.erase(ticketId);
        delete ticket;
    }
}

template<>
void SupportMgr::CloseTicket<GmTicket>(uint32 ticketId, ObjectGuid closedBy)
{
    if (GmTicket* ticket = GetTicket<GmTicket>(ticketId))
    {
        SQLTransaction trans = SQLTransaction(NULL);
        ticket->SetClosedBy(closedBy);
        if (!closedBy.IsEmpty())
            --_openGmTicketCount;
        ticket->SaveToDB(trans);
    }
}

template<>
void SupportMgr::CloseTicket<BugTicket>(uint32 ticketId, ObjectGuid closedBy)
{
    if (BugTicket* ticket = GetTicket<BugTicket>(ticketId))
    {
        SQLTransaction trans = SQLTransaction(NULL);
        ticket->SetClosedBy(closedBy);
        if (!closedBy.IsEmpty())
            --_openBugTicketCount;
        ticket->SaveToDB(trans);
    }
}

template<>
void SupportMgr::CloseTicket<ComplaintTicket>(uint32 ticketId, ObjectGuid closedBy)
{
    if (ComplaintTicket* ticket = GetTicket<ComplaintTicket>(ticketId))
    {
        SQLTransaction trans = SQLTransaction(NULL);
        ticket->SetClosedBy(closedBy);
        if (!closedBy.IsEmpty())
            --_openComplaintTicketCount;
        ticket->SaveToDB(trans);
    }
}

template<>
void SupportMgr::CloseTicket<SuggestionTicket>(uint32 ticketId, ObjectGuid closedBy)
{
    if (SuggestionTicket* ticket = GetTicket<SuggestionTicket>(ticketId))
    {
        SQLTransaction trans = SQLTransaction(NULL);
        ticket->SetClosedBy(closedBy);
        if (!closedBy.IsEmpty())
            --_openSuggestionTicketCount;
        ticket->SaveToDB(trans);
    }
}

template<>
void SupportMgr::ResetTickets<GmTicket>()
{
    for (auto const& c : _gmTicketList)
        delete c.second;
    _gmTicketList.clear();

    _lastGmTicketId = 0;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_GM_TICKETS);
    CharacterDatabase.Execute(stmt);
}

template<>
void SupportMgr::ResetTickets<BugTicket>()
{
    for (auto const& c : _bugTicketList)
        delete c.second;
    _bugTicketList.clear();

    _lastBugId = 0;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_GM_BUGS);
    CharacterDatabase.Execute(stmt);
}

template<>
void SupportMgr::ResetTickets<ComplaintTicket>()
{
    for (auto const& c : _complaintTicketList)
        delete c.second;
    _complaintTicketList.clear();

    _lastComplaintId = 0;

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    trans->Append(CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_GM_COMPLAINTS));
    trans->Append(CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_GM_COMPLAINT_CHATLOGS));
    CharacterDatabase.CommitTransaction(trans);
}

template<>
void SupportMgr::ResetTickets<SuggestionTicket>()
{
    for (auto const& c : _suggestionTicketList)
        delete c.second;
    _suggestionTicketList.clear();

    _lastSuggestionId = 0;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_GM_SUGGESTIONS);
    CharacterDatabase.Execute(stmt);
}

template<>
void SupportMgr::ShowList<GmTicket>(ChatHandler& handler, bool onlineOnly) const
{
    handler.SendSysMessage(onlineOnly ? LANG_COMMAND_TICKETSHOWONLINELIST : LANG_COMMAND_TICKETSHOWLIST);
    for (GmTicketList::const_iterator itr = _gmTicketList.begin(); itr != _gmTicketList.end(); ++itr)
        if (!itr->second->IsClosed() && !itr->second->IsCompleted())
            if (!onlineOnly || itr->second->GetPlayer())
                handler.SendSysMessage(itr->second->FormatViewMessageString(handler).c_str());
}

template<>
void SupportMgr::ShowList<GmTicket>(ChatHandler& handler) const
{
    handler.SendSysMessage(LANG_COMMAND_TICKETSHOWLIST);
    for (GmTicketList::const_iterator itr = _gmTicketList.begin(); itr != _gmTicketList.end(); ++itr)
        if (!itr->second->IsClosed() && !itr->second->IsCompleted())
                handler.SendSysMessage(itr->second->FormatViewMessageString(handler).c_str());
}

template<>
void SupportMgr::ShowList<BugTicket>(ChatHandler& handler) const
{
    handler.SendSysMessage(LANG_COMMAND_TICKETSHOWLIST);
    for (BugTicketList::const_iterator itr = _bugTicketList.begin(); itr != _bugTicketList.end(); ++itr)
        if (!itr->second->IsClosed())
            handler.SendSysMessage(itr->second->FormatViewMessageString(handler).c_str());
}

template<>
void SupportMgr::ShowList<ComplaintTicket>(ChatHandler& handler) const
{
    handler.SendSysMessage(LANG_COMMAND_TICKETSHOWLIST);
    for (ComplaintTicketList::const_iterator itr = _complaintTicketList.begin(); itr != _complaintTicketList.end(); ++itr)
        if (!itr->second->IsClosed())
            handler.SendSysMessage(itr->second->FormatViewMessageString(handler).c_str());
}

template<>
void SupportMgr::ShowList<SuggestionTicket>(ChatHandler& handler) const
{
    handler.SendSysMessage(LANG_COMMAND_TICKETSHOWLIST);
    for (SuggestionTicketList::const_iterator itr = _suggestionTicketList.begin(); itr != _suggestionTicketList.end(); ++itr)
        if (!itr->second->IsClosed())
            handler.SendSysMessage(itr->second->FormatViewMessageString(handler).c_str());
}

template<>
void SupportMgr::ShowClosedList<GmTicket>(ChatHandler& handler) const
{
    handler.SendSysMessage(LANG_COMMAND_TICKETSHOWCLOSEDLIST);
    for (GmTicketList::const_iterator itr = _gmTicketList.begin(); itr != _gmTicketList.end(); ++itr)
            if (itr->second->IsClosed())
                handler.SendSysMessage(itr->second->FormatViewMessageString(handler).c_str());
}

template<>
void SupportMgr::ShowClosedList<BugTicket>(ChatHandler& handler) const
{
    handler.SendSysMessage(LANG_COMMAND_TICKETSHOWCLOSEDLIST);
    for (BugTicketList::const_iterator itr = _bugTicketList.begin(); itr != _bugTicketList.end(); ++itr)
        if (itr->second->IsClosed())
            handler.SendSysMessage(itr->second->FormatViewMessageString(handler).c_str());
}

template<>
void SupportMgr::ShowClosedList<ComplaintTicket>(ChatHandler& handler) const
{
    handler.SendSysMessage(LANG_COMMAND_TICKETSHOWCLOSEDLIST);
    for (ComplaintTicketList::const_iterator itr = _complaintTicketList.begin(); itr != _complaintTicketList.end(); ++itr)
        if (itr->second->IsClosed())
            handler.SendSysMessage(itr->second->FormatViewMessageString(handler).c_str());
}

template<>
void SupportMgr::ShowClosedList<SuggestionTicket>(ChatHandler& handler) const
{
    handler.SendSysMessage(LANG_COMMAND_TICKETSHOWCLOSEDLIST);
    for (SuggestionTicketList::const_iterator itr = _suggestionTicketList.begin(); itr != _suggestionTicketList.end(); ++itr)
        if (itr->second->IsClosed())
            handler.SendSysMessage(itr->second->FormatViewMessageString(handler).c_str());
}

void SupportMgr::ShowGmEscalatedList(ChatHandler& handler) const
{
    handler.SendSysMessage(LANG_COMMAND_TICKETSHOWESCALATEDLIST);
    for (GmTicketList::const_iterator itr = _gmTicketList.begin(); itr != _gmTicketList.end(); ++itr)
        if (!itr->second->IsClosed() && itr->second->GetEscalatedStatus() == TICKET_IN_ESCALATION_QUEUE)
            handler.SendSysMessage(itr->second->FormatViewMessageString(handler).c_str());
}

void SupportMgr::SendGmTicket(WorldSession* session, GmTicket* ticket) const
{
    WorldPackets::Ticket::GMTicketGetTicketResponse response;

    if (ticket)
    {
        response.Result = GMTICKET_STATUS_HASTEXT;
        response.Info.HasValue = true;

        response.Info.Value.TicketID = ticket->GetId();
        response.Info.Value.TicketDescription = ticket->GetDescription();
        response.Info.Value.Category = ticket->GetEscalatedStatus();
        response.Info.Value.TicketOpenTime = GetAge(ticket->GetLastModifiedTime());
        response.Info.Value.OldestTicketTime = sSupportMgr->GetOldestOpenTicket() ? GetAge(sSupportMgr->GetOldestOpenTicket()->GetLastModifiedTime()) : float(0);
        response.Info.Value.UpdateTime = GetAge(sSupportMgr->GetLastChange());
        response.Info.Value.AssignedToGM = ticket->IsAssigned();
        response.Info.Value.OpenedByGM = ticket->IsViewed();
        response.Info.Value.WaitTimeOverrideMessage = "";
        response.Info.Value.WaitTimeOverrideMinutes = 0;
    }
    else
        response.Result = GMTICKET_STATUS_DEFAULT;

    session->SendPacket(response.Write());
}

void SupportMgr::SendGmTicketUpdate(WorldSession* session, GMTicketResponse response) const
{
    WorldPackets::Ticket::GMTicketUpdate update;
    update.Result = response;

    session->SendPacket(update.Write());
}
