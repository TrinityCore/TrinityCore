/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "LFGPackets.h"
#include "TicketPackets.h"
#include "PacketUtilities.h"
#include "SupportMgr.h"

using namespace WorldPackets;

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Ticket::SupportTicketHeader& header)
{
    data >> header.MapID;
    data >> header.Position;
    data >> header.Facing;

    return data;
}

WorldPacket const* WorldPackets::Ticket::GMTicketSystemStatus::Write()
{
    _worldPacket << int32(Status);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Ticket::GMTicketCaseStatus::Write()
{
    _worldPacket << int32(Cases.size());

    for (auto const& c : Cases)
    {
        _worldPacket << int32(c.CaseID);
        _worldPacket << int32(c.CaseOpened);
        _worldPacket << int32(c.CaseStatus);
        _worldPacket << int16(c.CfgRealmID);
        _worldPacket << int64(c.CharacterID);
        _worldPacket << int32(c.WaitTimeOverrideMinutes);

        _worldPacket.WriteBits(c.Url.size(), 11);
        _worldPacket.WriteBits(c.WaitTimeOverrideMessage.size(), 10);

        _worldPacket.WriteString(c.Url);
        _worldPacket.WriteString(c.WaitTimeOverrideMessage);
    }

    _worldPacket.FlushBits();
    return &_worldPacket;
}

void WorldPackets::Ticket::GMTicketAcknowledgeSurvey::Read()
{
    _worldPacket >> CaseID;
}

void WorldPackets::Ticket::SupportTicketSubmitBug::Read()
{
    _worldPacket >> Header;
    Note = _worldPacket.ReadString(_worldPacket.ReadBits(10));
}

void WorldPackets::Ticket::SupportTicketSubmitSuggestion::Read()
{
    _worldPacket >> Header;
    Note = _worldPacket.ReadString(_worldPacket.ReadBits(10));
}

WorldPackets::Ticket::SupportTicketSubmitComplaint::SupportTicketChatLine::SupportTicketChatLine(ByteBuffer& data)
{
    data >> Timestamp;
    Text = data.ReadString(data.ReadBits(12));
}

WorldPackets::Ticket::SupportTicketSubmitComplaint::SupportTicketChatLine::SupportTicketChatLine(uint32 timestamp, std::string const& text) :
    Timestamp(timestamp), Text(text)
{ }

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Ticket::SupportTicketSubmitComplaint::SupportTicketChatLine& line)
{
    data >> line.Timestamp;
    line.Text = data.ReadString(data.ReadBits(12));

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Ticket::SupportTicketSubmitComplaint::SupportTicketChatLog& chatlog)
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

ByteBuffer& operator>>(ByteBuffer& data, Optional<WorldPackets::Ticket::SupportTicketSubmitComplaint::SupportTicketMailInfo>& mail)
{
    mail = boost::in_place();

    data >> mail->MailID;
    uint32 bodyLength = data.ReadBits(13);
    uint32 subjectLength = data.ReadBits(9);
    mail->MailBody = data.ReadString(bodyLength);
    mail->MailSubject = data.ReadString(subjectLength);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<WorldPackets::Ticket::SupportTicketSubmitComplaint::SupportTicketCalendarEventInfo>& event)
{
    event = boost::in_place();

    data >> event->EventID;
    data >> event->InviteID;
    event->EventTitle = data.ReadString(data.ReadBits(8));

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<WorldPackets::Ticket::SupportTicketSubmitComplaint::SupportTicketPetInfo>& pet)
{
    pet = boost::in_place();

    data >> pet->PetID;
    pet->PetName = data.ReadString(data.ReadBits(8));

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<WorldPackets::Ticket::SupportTicketSubmitComplaint::SupportTicketGuildInfo>& guild)
{
    guild = boost::in_place();

    uint32 nameLength = data.ReadBits(7);
    data >> guild->GuildID;
    guild->GuildName = data.ReadString(nameLength);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<WorldPackets::Ticket::SupportTicketSubmitComplaint::SupportTicketLFGListSearchResult>& lfgListSearchResult)
{
    lfgListSearchResult = boost::in_place();

    data >> lfgListSearchResult->RideTicket;
    data >> lfgListSearchResult->GroupFinderActivityID;
    data >> lfgListSearchResult->LastTitleAuthorGuid;
    data >> lfgListSearchResult->LastDescriptionAuthorGuid;
    data >> lfgListSearchResult->LastVoiceChatAuthorGuid;

    uint32 titleLength = data.ReadBits(8);
    uint32 descriptionLength = data.ReadBits(11);
    uint32 voiceChatLength = data.ReadBits(8);

    lfgListSearchResult->Title = data.ReadString(titleLength);
    lfgListSearchResult->Description = data.ReadString(descriptionLength);
    lfgListSearchResult->VoiceChat = data.ReadString(voiceChatLength);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<WorldPackets::Ticket::SupportTicketSubmitComplaint::SupportTicketLFGListApplicant>& lfgListApplicant)
{
    lfgListApplicant = boost::in_place();

    data >> lfgListApplicant->RideTicket;
    lfgListApplicant->Comment = data.ReadString(data.ReadBits(9));

    return data;
}

void WorldPackets::Ticket::SupportTicketSubmitComplaint::Read()
{
    _worldPacket >> Header;
    _worldPacket >> ChatLog;
    _worldPacket >> TargetCharacterGUID;
    ComplaintType = _worldPacket.ReadBits(5);

    uint32 noteLength = _worldPacket.ReadBits(10);
    bool hasMailInfo = _worldPacket.ReadBit();
    bool hasCalendarInfo = _worldPacket.ReadBit();
    bool hasPetInfo = _worldPacket.ReadBit();
    bool hasGuildInfo = _worldPacket.ReadBit();
    bool hasLFGListSearchResult = _worldPacket.ReadBit();
    bool hasLFGListApplicant = _worldPacket.ReadBit();

    _worldPacket.ResetBitPos();

    if (hasMailInfo)
        _worldPacket >> MailInfo;

    Note = _worldPacket.ReadString(noteLength);

    if (hasCalendarInfo)
        _worldPacket >> CalenderInfo;

    if (hasPetInfo)
        _worldPacket >> PetInfo;

    if (hasGuildInfo)
        _worldPacket >> GuildInfo;

    if (hasLFGListSearchResult)
        _worldPacket >> LFGListSearchResult;

    if (hasLFGListApplicant)
        _worldPacket >> LFGListApplicant;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Ticket::Complaint::ComplaintOffender& complaintOffender)
{
    data >> complaintOffender.PlayerGuid;
    data >> complaintOffender.RealmAddress;
    data >> complaintOffender.TimeSinceOffence;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Ticket::Complaint::ComplaintChat& chat)
{
    data >> chat.Command;
    data >> chat.ChannelID;
    chat.MessageLog = data.ReadString(data.ReadBits(12));

    return data;
}

void WorldPackets::Ticket::Complaint::Read()
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

WorldPacket const* WorldPackets::Ticket::ComplaintResult::Write()
{
    _worldPacket << uint32(ComplaintType);
    _worldPacket << uint8(Result);

    return &_worldPacket;
}

void WorldPackets::Ticket::BugReport::Read()
{
    Type = _worldPacket.ReadBit();
    uint32 diagLen = _worldPacket.ReadBits(12);
    uint32 textLen = _worldPacket.ReadBits(10);
    DiagInfo = _worldPacket.ReadString(diagLen);
    Text = _worldPacket.ReadString(textLen);
}
