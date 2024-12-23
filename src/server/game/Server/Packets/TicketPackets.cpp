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

#include "TicketPackets.h"
#include "PacketUtilities.h"
#include "SupportMgr.h"

namespace WorldPackets::Ticket
{
ByteBuffer& operator>>(ByteBuffer& data, SupportTicketHeader& header)
{
    data >> header.MapID;
    data >> header.Position;
    data >> header.Facing;
    data >> header.Program;

    return data;
}

WorldPacket const* GMTicketSystemStatus::Write()
{
    _worldPacket << int32(Status);

    return &_worldPacket;
}

WorldPacket const* GMTicketCaseStatus::Write()
{
    _worldPacket << int32(Cases.size());

    for (GMTicketCase const& c : Cases)
    {
        _worldPacket << int32(c.CaseID);
        _worldPacket << c.CaseOpened;
        _worldPacket << int32(c.CaseStatus);
        _worldPacket << uint16(c.CfgRealmID);
        _worldPacket << uint64(c.CharacterID);
        _worldPacket << int32(c.WaitTimeOverrideMinutes);

        _worldPacket << SizedString::BitsSize<11>(c.Url);
        _worldPacket << SizedString::BitsSize<10>(c.WaitTimeOverrideMessage);
        _worldPacket << SizedCString::BitsSize<24>(c.Title);
        _worldPacket << SizedCString::BitsSize<24>(c.Description);
        _worldPacket.FlushBits();

        _worldPacket << SizedString::Data(c.Url);
        _worldPacket << SizedString::Data(c.WaitTimeOverrideMessage);
        _worldPacket << SizedCString::Data(c.Title);
        _worldPacket << SizedCString::Data(c.Description);
    }

    return &_worldPacket;
}

void GMTicketAcknowledgeSurvey::Read()
{
    _worldPacket >> CaseID;
}

void SubmitUserFeedback::Read()
{
    _worldPacket >> Header;
    uint32 noteLength = _worldPacket.ReadBits(24);
    IsSuggestion = _worldPacket.ReadBit();
    if (noteLength)
    {
        Note = _worldPacket.ReadString(noteLength - 1);
        _worldPacket.read_skip<char>(); // null terminator
    }
}

SupportTicketChatLine::SupportTicketChatLine(time_t timestamp, std::string const& text) :
    Timestamp(timestamp), Text(text)
{ }

ByteBuffer& operator>>(ByteBuffer& data, SupportTicketChatLine& line)
{
    data >> line.Timestamp;
    line.Text = data.ReadString(data.ReadBits(12));

    return data;
}

SupportTicketChatLine::SupportTicketChatLine(ByteBuffer& data)
{
    data >> *this;
}

ByteBuffer& operator>>(ByteBuffer& data, SupportTicketChatLog& chatlog)
{
    uint32 linesCount = data.read<uint32>();
    bool hasReportLineIndex = data.ReadBit();
    data.ResetBitPos();

    for (uint32 i = 0; i < linesCount; i++)
        chatlog.Lines.emplace_back(data);

    if (hasReportLineIndex)
        chatlog.ReportLineIndex = data.read<uint32>();

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, SupportTicketHorusChatLine& line)
{
    data >> line.Timestamp;
    data >> line.PlayerGuid;

    data >> OptionalInit(line.ClubID);
    data >> OptionalInit(line.ChannelGuid);
    data >> OptionalInit(line.WorldServer);
    data >> OptionalInit(line.Cmd);
    uint32 textLength = data.ReadBits(12);

    if (line.ClubID)
        data >> *line.ClubID;

    if (line.ChannelGuid)
        data >> *line.ChannelGuid;

    if (line.WorldServer)
    {
        data >> line.WorldServer->Realm;
        data >> line.WorldServer->Server;
        data >> line.WorldServer->Type;
    }

    if (line.Cmd)
        data >> *line.Cmd;

    line.Text = data.ReadString(textLength);

    return data;
}

SupportTicketHorusChatLine::SupportTicketHorusChatLine(ByteBuffer& data)
{
    data >> *this;
}

ByteBuffer& operator>>(ByteBuffer& data, SupportTicketHorusChatLog& chatlog)
{
    uint32 linesCount = data.read<uint32>();
    data.ResetBitPos();

    for (uint32 i = 0; i < linesCount; i++)
        chatlog.Lines.emplace_back(data);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<SupportTicketMailInfo>& mail)
{
    mail.emplace();

    data >> mail->MailID;
    uint32 bodyLength = data.ReadBits(13);
    uint32 subjectLength = data.ReadBits(9);
    mail->MailBody = data.ReadString(bodyLength);
    mail->MailSubject = data.ReadString(subjectLength);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<SupportTicketCalendarEventInfo>& event)
{
    event.emplace();

    data >> event->EventID;
    data >> event->InviteID;
    event->EventTitle = data.ReadString(data.ReadBits(8));

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<SupportTicketPetInfo>& pet)
{
    pet.emplace();

    data >> pet->PetID;
    pet->PetName = data.ReadString(data.ReadBits(8));

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<SupportTicketGuildInfo>& guild)
{
    guild.emplace();

    uint32 nameLength = data.ReadBits(7);
    data >> guild->GuildID;
    guild->GuildName = data.ReadString(nameLength);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<SupportTicketLFGListEntryInfo>& lfgListSearchResult)
{
    lfgListSearchResult.emplace();

    data >> lfgListSearchResult->Ticket;
    data >> lfgListSearchResult->ActivityID;
    data >> lfgListSearchResult->FactionID;
    data >> lfgListSearchResult->LastTouchedName;
    data >> lfgListSearchResult->LastTouchedComment;
    data >> lfgListSearchResult->LastTouchedVoiceChat;
    data >> lfgListSearchResult->LastTouchedAny;
    data >> lfgListSearchResult->PartyGuid;

    uint32 nameLength = data.ReadBits(10);
    uint32 commentLength = data.ReadBits(11);
    uint32 voiceChatLength = data.ReadBits(8);

    lfgListSearchResult->Name = data.ReadString(nameLength);
    lfgListSearchResult->Comment = data.ReadString(commentLength);
    lfgListSearchResult->VoiceChat = data.ReadString(voiceChatLength);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<SupportTicketLFGListApplicant>& lfgListApplicant)
{
    lfgListApplicant.emplace();

    data >> lfgListApplicant->Ticket;
    lfgListApplicant->Comment = data.ReadString(data.ReadBits(9));

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<SupportTicketClubFinderInfo>& clubInfo)
{
    clubInfo.emplace();

    data >> clubInfo->PostingID;
    data >> clubInfo->ClubID;
    data >> clubInfo->GuildID;
    clubInfo->PostingDescription = data.ReadString(data.ReadBits(12));

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<SupportTicketArenaTeamInfo>& arenaTeam)
{
    arenaTeam.emplace();

    uint32 arenaTeamNameLength = data.ReadBits(7);
    data >> arenaTeam->ArenaTeamID;
    arenaTeam->ArenaTeamName = data.ReadString(arenaTeamNameLength);

    return data;
}

void SupportTicketSubmitComplaint::Read()
{
    _worldPacket >> Header;
    _worldPacket >> TargetCharacterGUID;
    _worldPacket >> ReportType;
    _worldPacket >> MajorCategory;
    _worldPacket >> MinorCategoryFlags;
    _worldPacket >> ChatLog;

    uint32 noteLength = _worldPacket.ReadBits(10);
    bool hasMailInfo = _worldPacket.ReadBit();
    bool hasCalendarInfo = _worldPacket.ReadBit();
    bool hasPetInfo = _worldPacket.ReadBit();
    bool hasGuildInfo = _worldPacket.ReadBit();
    bool hasLfgListEntryInfo = _worldPacket.ReadBit();
    bool hasLfgListAppInfo = _worldPacket.ReadBit();
    bool hasVoiceChatInfo = _worldPacket.ReadBit();
    bool hasClubFinderResult = _worldPacket.ReadBit();
    bool hasArenaTeamInfo = _worldPacket.ReadBit();

    _worldPacket.ResetBitPos();

    if (hasVoiceChatInfo)
    {
        VoiceChatInfo.emplace();
        VoiceChatInfo->TargetIsCurrentlyInVoiceChatWithPlayer = _worldPacket.ReadBit();
        _worldPacket.ResetBitPos();
    }

    _worldPacket >> HorusChatLog;

    Note = _worldPacket.ReadString(noteLength);

    if (hasMailInfo)
        _worldPacket >> MailInfo;

    if (hasCalendarInfo)
        _worldPacket >> CalenderInfo;

    if (hasPetInfo)
        _worldPacket >> PetInfo;

    if (hasGuildInfo)
        _worldPacket >> GuildInfo;

    if (hasLfgListEntryInfo)
        _worldPacket >> LfgListEntryInfo;

    if (hasLfgListAppInfo)
        _worldPacket >> LfgListAppInfo;

    if (hasClubFinderResult)
        _worldPacket >> ClubFinderInfo;

    if (hasArenaTeamInfo)
        _worldPacket >> ArenaTeamInfo;
}

ByteBuffer& operator>>(ByteBuffer& data, Complaint::ComplaintOffender& complaintOffender)
{
    data >> complaintOffender.PlayerGuid;
    data >> complaintOffender.RealmAddress;
    data >> complaintOffender.TimeSinceOffence;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Complaint::ComplaintChat& chat)
{
    data >> chat.Command;
    data >> chat.ChannelID;
    chat.MessageLog = data.ReadString(data.ReadBits(12));

    return data;
}

void Complaint::Read()
{
    _worldPacket >> ComplaintType;
    _worldPacket >> Offender;

    switch (ComplaintType)
    {
        case SUPPORT_SPAM_TYPE_MAIL:
            _worldPacket >> MailID;
            break;
        case SUPPORT_SPAM_TYPE_CHAT:
            _worldPacket >> Chat;
            break;
        case SUPPORT_SPAM_TYPE_CALENDAR:
            _worldPacket >> EventGuid;
            _worldPacket >> InviteGuid;
            break;
        default:
            break;
    }
}

WorldPacket const* ComplaintResult::Write()
{
    _worldPacket << uint32(ComplaintType);
    _worldPacket << uint8(Result);

    return &_worldPacket;
}

void BugReport::Read()
{
    Type = _worldPacket.ReadBit();
    uint32 diagLen = _worldPacket.ReadBits(12);
    uint32 textLen = _worldPacket.ReadBits(10);
    DiagInfo = _worldPacket.ReadString(diagLen);
    Text = _worldPacket.ReadString(textLen);
}
}
