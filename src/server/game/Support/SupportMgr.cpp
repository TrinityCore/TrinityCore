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

#include "SupportMgr.h"
#include "CharacterCache.h"
#include "Chat.h"
#include "DatabaseEnv.h"
#include "Language.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Timer.h"
#include "World.h"
#include <sstream>

inline time_t GetAge(uint64 t) { return (time(nullptr) - t) / DAY; }

Ticket::Ticket() : _id(0), _mapId(0), _createTime(0) { }

Ticket::Ticket(Player* player) : _id(0), _mapId(0), _createTime(time(nullptr))
{
    _playerGuid = player->GetGUID();
}

Ticket::~Ticket() { }

Player* Ticket::GetPlayer() const
{
    return ObjectAccessor::FindConnectedPlayer(_playerGuid);
}

std::string Ticket::GetPlayerName() const
{
    std::string name;
    if (!_playerGuid.IsEmpty())
        sCharacterCache->GetCharacterNameByGuid(_playerGuid, name);

    return name;
}

Player* Ticket::GetAssignedPlayer() const
{
    return ObjectAccessor::FindConnectedPlayer(_assignedTo);
}

std::string Ticket::GetAssignedToName() const
{
    std::string name;
    if (!_assignedTo.IsEmpty())
        sCharacterCache->GetCharacterNameByGuid(_assignedTo, name);

    return name;
}

void Ticket::TeleportTo(Player* player) const
{
    player->TeleportTo(_mapId, _pos.GetPositionX(), _pos.GetPositionY(), _pos.GetPositionZ(), 0.0f, 0);
}

std::string Ticket::FormatViewMessageString(ChatHandler& handler, char const* closedName, char const* assignedToName, char const* unassignedName, char const* deletedName) const
{
    std::stringstream ss;
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTGUID, _id);
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTNAME, GetPlayerName().c_str());
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

BugTicket::BugTicket() { }

BugTicket::BugTicket(Player* player) : Ticket(player)
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
    _createTime         = fields[++idx].GetInt64();
    _mapId              = fields[++idx].GetUInt16();
    _pos.m_positionX    = fields[++idx].GetFloat();
    _pos.m_positionY    = fields[++idx].GetFloat();
    _pos.m_positionZ    = fields[++idx].GetFloat();
    _pos.SetOrientation(fields[++idx].GetFloat());

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

void BugTicket::SaveToDB() const
{
    uint8 idx = 0;
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_GM_BUG);
    stmt->setUInt32(idx, _id);
    stmt->setUInt64(++idx, _playerGuid.GetCounter());
    stmt->setString(++idx, _note);
    stmt->setInt64(++idx, _createTime);
    stmt->setUInt16(++idx, _mapId);
    stmt->setFloat(++idx, _pos.GetPositionX());
    stmt->setFloat(++idx, _pos.GetPositionY());
    stmt->setFloat(++idx, _pos.GetPositionZ());
    stmt->setFloat(++idx, _pos.GetOrientation());
    stmt->setInt64(++idx, _closedBy.GetCounter());
    stmt->setUInt64(++idx, _assignedTo.GetCounter());
    stmt->setString(++idx, _comment);

    CharacterDatabase.Execute(stmt);
}

void BugTicket::DeleteFromDB()
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GM_BUG);
    stmt->setUInt32(0, _id);
    CharacterDatabase.Execute(stmt);
}

std::string BugTicket::FormatViewMessageString(ChatHandler& handler, bool detailed) const
{
    time_t curTime = time(nullptr);

    std::stringstream ss;
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTGUID, _id);
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTNAME, GetPlayerName().c_str());
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTAGECREATE, (secsToTimeString(curTime - _createTime, true, false)).c_str());

    if (!_assignedTo.IsEmpty())
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, GetAssignedToName().c_str());

    if (detailed)
    {
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTMESSAGE, _note.c_str());
        if (!_comment.empty())
            ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTCOMMENT, _comment.c_str());
    }
    return ss.str();
}

ComplaintTicket::ComplaintTicket() : _complaintType(GMTICKET_SUPPORT_COMPLAINT_TYPE_NONE) { }

ComplaintTicket::ComplaintTicket(Player* player) : Ticket(player), _complaintType(GMTICKET_SUPPORT_COMPLAINT_TYPE_NONE)
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
    _createTime             = fields[++idx].GetInt64();
    _mapId                  = fields[++idx].GetUInt16();
    _pos.m_positionX        = fields[++idx].GetFloat();
    _pos.m_positionY        = fields[++idx].GetFloat();
    _pos.m_positionZ        = fields[++idx].GetFloat();
    _pos.SetOrientation(fields[++idx].GetFloat());
    _targetCharacterGuid    = ObjectGuid::Create<HighGuid::Player>(fields[++idx].GetUInt64());
    _complaintType          = GMSupportComplaintType(fields[++idx].GetUInt8());
    int32 reportLineIndex = fields[++idx].GetInt32();
    if (reportLineIndex != -1)
        _chatLog.ReportLineIndex = reportLineIndex;

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
    _chatLog.Lines.emplace_back(fields[0].GetInt64(), fields[1].GetString());
}

void ComplaintTicket::SaveToDB() const
{
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    uint8 idx = 0;
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_GM_COMPLAINT);
    stmt->setUInt32(idx, _id);
    stmt->setUInt64(++idx, _playerGuid.GetCounter());
    stmt->setString(++idx, _note);
    stmt->setInt64(++idx, _createTime);
    stmt->setUInt16(++idx, _mapId);
    stmt->setFloat(++idx, _pos.GetPositionX());
    stmt->setFloat(++idx, _pos.GetPositionY());
    stmt->setFloat(++idx, _pos.GetPositionZ());
    stmt->setFloat(++idx, _pos.GetOrientation());
    stmt->setUInt64(++idx, _targetCharacterGuid.GetCounter());
    stmt->setUInt8(++idx, _complaintType);
    if (_chatLog.ReportLineIndex)
        stmt->setInt32(++idx, *_chatLog.ReportLineIndex);
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
        stmt->setInt64(++idx, c.Timestamp);
        stmt->setString(++idx, c.Text);

        trans->Append(stmt);
        ++lineIndex;
    }

    CharacterDatabase.CommitTransaction(trans);
}

void ComplaintTicket::DeleteFromDB()
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GM_COMPLAINT);
    stmt->setUInt32(0, _id);
    CharacterDatabase.Execute(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GM_COMPLAINT_CHATLOG);
    stmt->setUInt32(0, _id);
    CharacterDatabase.Execute(stmt);
}

std::string ComplaintTicket::FormatViewMessageString(ChatHandler& handler, bool detailed) const
{
    time_t curTime = time(nullptr);

    std::stringstream ss;
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTGUID, _id);
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTNAME, GetPlayerName().c_str());
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTAGECREATE, (secsToTimeString(curTime - _createTime, true, false)).c_str());

    if (!_assignedTo.IsEmpty())
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, GetAssignedToName().c_str());

    if (detailed)
    {
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTMESSAGE, _note.c_str());
        if (!_comment.empty())
            ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTCOMMENT, _comment.c_str());
    }
    return ss.str();
}

SuggestionTicket::SuggestionTicket() { }

SuggestionTicket::SuggestionTicket(Player* player) : Ticket(player)
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
    _createTime         = fields[++idx].GetInt64();
    _mapId              = fields[++idx].GetUInt16();
    _pos.m_positionX    = fields[++idx].GetFloat();
    _pos.m_positionY    = fields[++idx].GetFloat();
    _pos.m_positionZ    = fields[++idx].GetFloat();
    _pos.SetOrientation(fields[++idx].GetFloat());

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

void SuggestionTicket::SaveToDB() const
{
    uint8 idx = 0;
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_GM_SUGGESTION);
    stmt->setUInt32(idx, _id);
    stmt->setUInt64(++idx, _playerGuid.GetCounter());
    stmt->setString(++idx, _note);
    stmt->setInt64(++idx, _createTime);
    stmt->setUInt16(++idx, _mapId);
    stmt->setFloat(++idx, _pos.GetPositionX());
    stmt->setFloat(++idx, _pos.GetPositionY());
    stmt->setFloat(++idx, _pos.GetPositionZ());
    stmt->setFloat(++idx, _pos.GetOrientation());
    stmt->setInt64(++idx, _closedBy.GetCounter());
    stmt->setUInt64(++idx, _assignedTo.GetCounter());
    stmt->setString(++idx, _comment);

    CharacterDatabase.Execute(stmt);
}

void SuggestionTicket::DeleteFromDB()
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GM_SUGGESTION);
    stmt->setUInt32(0, _id);
    CharacterDatabase.Execute(stmt);
}

std::string SuggestionTicket::FormatViewMessageString(ChatHandler& handler, bool detailed) const
{
    time_t curTime = time(nullptr);

    std::stringstream ss;
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTGUID, _id);
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTNAME, GetPlayerName().c_str());
    ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTAGECREATE, (secsToTimeString(curTime - _createTime, true, false)).c_str());

    if (!_assignedTo.IsEmpty())
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, GetAssignedToName().c_str());

    if (detailed)
    {
        ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTMESSAGE, _note.c_str());
        if (!_comment.empty())
            ss << handler.PGetParseString(LANG_COMMAND_TICKETLISTCOMMENT, _comment.c_str());
    }
    return ss.str();
}

SupportMgr::SupportMgr() : _supportSystemStatus(false), _ticketSystemStatus(false), _bugSystemStatus(false), _complaintSystemStatus(false), _suggestionSystemStatus(false),
_lastBugId(0), _lastComplaintId(0), _lastSuggestionId(0), _lastChange(0),
_openBugTicketCount(0), _openComplaintTicketCount(0), _openSuggestionTicketCount(0) { }

SupportMgr::~SupportMgr()
{
    for (auto const& b : _bugTicketList)
        delete b.second;

    for (auto const& c : _complaintTicketList)
        delete c.second;

    for (auto const& s : _suggestionTicketList)
        delete s.second;
}

SupportMgr* SupportMgr::instance()
{
    static SupportMgr instance;
    return &instance;
}

template<>
TC_GAME_API BugTicket* SupportMgr::GetTicket<BugTicket>(uint32 bugId)
{
    BugTicketList::const_iterator itr = _bugTicketList.find(bugId);
    if (itr != _bugTicketList.end())
        return itr->second;

    return nullptr;

}

template<>
TC_GAME_API ComplaintTicket* SupportMgr::GetTicket<ComplaintTicket>(uint32 complaintId)
{
    ComplaintTicketList::const_iterator itr = _complaintTicketList.find(complaintId);
    if (itr != _complaintTicketList.end())
        return itr->second;

    return nullptr;
}

template<>
TC_GAME_API SuggestionTicket* SupportMgr::GetTicket<SuggestionTicket>(uint32 suggestionId)
{
    SuggestionTicketList::const_iterator itr = _suggestionTicketList.find(suggestionId);
    if (itr != _suggestionTicketList.end())
        return itr->second;

    return nullptr;

}

ComplaintTicketList SupportMgr::GetComplaintsByPlayerGuid(ObjectGuid playerGuid) const
{
    ComplaintTicketList ret;
    for (auto const& c : _complaintTicketList)
        if (c.second->GetPlayerGuid() == playerGuid)
            ret.insert(c);

    return ret;
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
TC_GAME_API uint32 SupportMgr::GetOpenTicketCount<BugTicket>() const { return _openBugTicketCount; }

template<>
TC_GAME_API uint32 SupportMgr::GetOpenTicketCount<ComplaintTicket>() const { return _openComplaintTicketCount; }

template<>
TC_GAME_API uint32 SupportMgr::GetOpenTicketCount<SuggestionTicket>() const { return _openSuggestionTicketCount; }

void SupportMgr::LoadBugTickets()
{
    uint32 oldMSTime = getMSTime();

    for (auto const& c : _bugTicketList)
        delete c.second;
    _bugTicketList.clear();

    _lastBugId = 0;
    _openBugTicketCount = 0;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GM_BUGS);
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

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GM_COMPLAINTS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 GM complaints. DB table `gm_complaint` is empty!");
        return;
    }

    uint32 count = 0;
    CharacterDatabasePreparedStatement* chatLogStmt;
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

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GM_SUGGESTIONS);
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

void SupportMgr::AddTicket(BugTicket* ticket)
{
    _bugTicketList[ticket->GetId()] = ticket;
    if (!ticket->IsClosed())
        ++_openBugTicketCount;

    ticket->SaveToDB();
}

void SupportMgr::AddTicket(ComplaintTicket* ticket)
{
    _complaintTicketList[ticket->GetId()] = ticket;
    if (!ticket->IsClosed())
        ++_openComplaintTicketCount;

    ticket->SaveToDB();
}

void SupportMgr::AddTicket(SuggestionTicket* ticket)
{
    _suggestionTicketList[ticket->GetId()] = ticket;
    if (!ticket->IsClosed())
        ++_openSuggestionTicketCount;

    ticket->SaveToDB();
}

template<>
TC_GAME_API void SupportMgr::RemoveTicket<BugTicket>(uint32 ticketId)
{
    if (BugTicket* ticket = GetTicket<BugTicket>(ticketId))
    {
        ticket->DeleteFromDB();
        _bugTicketList.erase(ticketId);
        delete ticket;
    }
}

template<>
TC_GAME_API void SupportMgr::RemoveTicket<ComplaintTicket>(uint32 ticketId)
{
    if (ComplaintTicket* ticket = GetTicket<ComplaintTicket>(ticketId))
    {
        ticket->DeleteFromDB();
        _complaintTicketList.erase(ticketId);
        delete ticket;
    }
}

template<>
TC_GAME_API void SupportMgr::RemoveTicket<SuggestionTicket>(uint32 ticketId)
{
    if (SuggestionTicket* ticket = GetTicket<SuggestionTicket>(ticketId))
    {
        ticket->DeleteFromDB();
        _suggestionTicketList.erase(ticketId);
        delete ticket;
    }
}

template<>
TC_GAME_API void SupportMgr::CloseTicket<BugTicket>(uint32 ticketId, ObjectGuid closedBy)
{
    if (BugTicket* ticket = GetTicket<BugTicket>(ticketId))
    {
        ticket->SetClosedBy(closedBy);
        if (!closedBy.IsEmpty())
            --_openBugTicketCount;
        ticket->SaveToDB();
    }
}

template<>
TC_GAME_API void SupportMgr::CloseTicket<ComplaintTicket>(uint32 ticketId, ObjectGuid closedBy)
{
    if (ComplaintTicket* ticket = GetTicket<ComplaintTicket>(ticketId))
    {
        ticket->SetClosedBy(closedBy);
        if (!closedBy.IsEmpty())
            --_openComplaintTicketCount;
        ticket->SaveToDB();
    }
}

template<>
TC_GAME_API void SupportMgr::CloseTicket<SuggestionTicket>(uint32 ticketId, ObjectGuid closedBy)
{
    if (SuggestionTicket* ticket = GetTicket<SuggestionTicket>(ticketId))
    {
        ticket->SetClosedBy(closedBy);
        if (!closedBy.IsEmpty())
            --_openSuggestionTicketCount;
        ticket->SaveToDB();
    }
}

template<>
TC_GAME_API void SupportMgr::ResetTickets<BugTicket>()
{
    for (auto const& c : _bugTicketList)
        delete c.second;
    _bugTicketList.clear();

    _lastBugId = 0;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_GM_BUGS);
    CharacterDatabase.Execute(stmt);
}

template<>
TC_GAME_API void SupportMgr::ResetTickets<ComplaintTicket>()
{
    for (auto const& c : _complaintTicketList)
        delete c.second;
    _complaintTicketList.clear();

    _lastComplaintId = 0;

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    trans->Append(CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_GM_COMPLAINTS));
    trans->Append(CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_GM_COMPLAINT_CHATLOGS));
    CharacterDatabase.CommitTransaction(trans);
}

template<>
TC_GAME_API void SupportMgr::ResetTickets<SuggestionTicket>()
{
    for (auto const& c : _suggestionTicketList)
        delete c.second;
    _suggestionTicketList.clear();

    _lastSuggestionId = 0;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_GM_SUGGESTIONS);
    CharacterDatabase.Execute(stmt);
}

template<>
TC_GAME_API void SupportMgr::ShowList<BugTicket>(ChatHandler& handler) const
{
    handler.SendSysMessage(LANG_COMMAND_TICKETSHOWLIST);
    for (BugTicketList::const_iterator itr = _bugTicketList.begin(); itr != _bugTicketList.end(); ++itr)
        if (!itr->second->IsClosed())
            handler.SendSysMessage(itr->second->FormatViewMessageString(handler).c_str());
}

template<>
TC_GAME_API void SupportMgr::ShowList<ComplaintTicket>(ChatHandler& handler) const
{
    handler.SendSysMessage(LANG_COMMAND_TICKETSHOWLIST);
    for (ComplaintTicketList::const_iterator itr = _complaintTicketList.begin(); itr != _complaintTicketList.end(); ++itr)
        if (!itr->second->IsClosed())
            handler.SendSysMessage(itr->second->FormatViewMessageString(handler).c_str());
}

template<>
TC_GAME_API void SupportMgr::ShowList<SuggestionTicket>(ChatHandler& handler) const
{
    handler.SendSysMessage(LANG_COMMAND_TICKETSHOWLIST);
    for (SuggestionTicketList::const_iterator itr = _suggestionTicketList.begin(); itr != _suggestionTicketList.end(); ++itr)
        if (!itr->second->IsClosed())
            handler.SendSysMessage(itr->second->FormatViewMessageString(handler).c_str());
}

template<>
TC_GAME_API void SupportMgr::ShowClosedList<BugTicket>(ChatHandler& handler) const
{
    handler.SendSysMessage(LANG_COMMAND_TICKETSHOWCLOSEDLIST);
    for (BugTicketList::const_iterator itr = _bugTicketList.begin(); itr != _bugTicketList.end(); ++itr)
        if (itr->second->IsClosed())
            handler.SendSysMessage(itr->second->FormatViewMessageString(handler).c_str());
}

template<>
TC_GAME_API void SupportMgr::ShowClosedList<ComplaintTicket>(ChatHandler& handler) const
{
    handler.SendSysMessage(LANG_COMMAND_TICKETSHOWCLOSEDLIST);
    for (ComplaintTicketList::const_iterator itr = _complaintTicketList.begin(); itr != _complaintTicketList.end(); ++itr)
        if (itr->second->IsClosed())
            handler.SendSysMessage(itr->second->FormatViewMessageString(handler).c_str());
}

template<>
TC_GAME_API void SupportMgr::ShowClosedList<SuggestionTicket>(ChatHandler& handler) const
{
    handler.SendSysMessage(LANG_COMMAND_TICKETSHOWCLOSEDLIST);
    for (SuggestionTicketList::const_iterator itr = _suggestionTicketList.begin(); itr != _suggestionTicketList.end(); ++itr)
        if (itr->second->IsClosed())
            handler.SendSysMessage(itr->second->FormatViewMessageString(handler).c_str());
}

void SupportMgr::UpdateLastChange()
{
    _lastChange = uint64(time(nullptr));
}
