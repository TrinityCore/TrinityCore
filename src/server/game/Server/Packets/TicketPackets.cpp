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

#include "LFGPackets.h"
#include "TicketPackets.h"
#include "PacketUtilities.h"

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
    _worldPacket.AppendPackedTime(OldestTicketTime);
    _worldPacket.AppendPackedTime(UpdateTime);

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
    }

    _worldPacket.FlushBits();
    return &_worldPacket;
}

void WorldPackets::Ticket::GMTicketAcknowledgeSurvey::Read()
{
    _worldPacket >> CaseID;
}

WorldPacket const* WorldPackets::Ticket::GMTicketGetTicketResponse::Write()
{
    _worldPacket << Result;
    _worldPacket.WriteBit(Info.is_initialized());
    _worldPacket.FlushBits();

    if (Info)
    {
        _worldPacket << int32(Info->TicketID);
        _worldPacket << uint8(Info->Category);
        _worldPacket.AppendPackedTime(Info->TicketOpenTime);
        _worldPacket.AppendPackedTime(Info->OldestTicketTime);
        _worldPacket.AppendPackedTime(Info->UpdateTime);
        _worldPacket << uint8(Info->AssignedToGM);
        _worldPacket << uint8(Info->OpenedByGM);
        _worldPacket << int32(Info->WaitTimeOverrideMinutes);

        _worldPacket.WriteBits(Info->TicketDescription.size(), 11);
        _worldPacket.WriteBits(Info->WaitTimeOverrideMessage.size(), 10);
        _worldPacket.FlushBits();

        _worldPacket.WriteString(Info->TicketDescription);
        _worldPacket.WriteString(Info->WaitTimeOverrideMessage);
    }


    return &_worldPacket;
}

void WorldPackets::Ticket::GMTicketCreate::Read()
{
    _worldPacket >> Map;
    _worldPacket >> Pos;
    _worldPacket >> Flags;

    uint16 descLength = _worldPacket.ReadBits(11);
    Description = _worldPacket.ReadString(descLength);
    _worldPacket.ResetBitPos();

    NeedResponse = _worldPacket.ReadBit();
    NeedMoreHelp = _worldPacket.ReadBit();
    _worldPacket >> DataLength;

    if (DataLength > 0)
    {
        _worldPacket >> ChatHistoryData.TextCount;
        for (uint8 i = 0; i < ChatHistoryData.TextCount; ++i)
            ChatHistoryData.Sent.push_back(_worldPacket.read<uint32>());

        _worldPacket >> ChatHistoryData.DecompressedSize;

        //Note: don't ask why, but it works...
        uint32 realLength = DataLength - ((ChatHistoryData.TextCount * 4) + 5);
        ChatHistoryData.Data.resize(realLength);
        _worldPacket.read(ChatHistoryData.Data.contents(), realLength);
    }
}

void WorldPackets::Ticket::GMTicketUpdateText::Read()
{
    uint16 descLength = _worldPacket.ReadBits(11);
    Description = _worldPacket.ReadString(descLength);
}

WorldPacket const* WorldPackets::Ticket::GMTicketUpdate::Write()
{
    _worldPacket << uint8(Result);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Ticket::GMTicketStatusUpdate::Write()
{
    _worldPacket << int32(StatusInt);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Ticket::GMTicketResponse::Write()
{
    _worldPacket << uint32(TicketID);
    _worldPacket << uint32(ResponseID);

    _worldPacket.WriteBits(Description.size(), 11);
    _worldPacket.WriteBits(ResponseText.size(), 14);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(Description);
    _worldPacket.WriteString(ResponseText);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Ticket::GMTicketResolveResponse::Write()
{
    _worldPacket.WriteBit(ShowSurvey);

    _worldPacket.FlushBits();
    return &_worldPacket;
}

void WorldPackets::Ticket::GMSurveySubmit::Read()
{
    _worldPacket >> SurveyID;

    SurveyQuestion.resize(_worldPacket.ReadBits(4));
    uint16 commentLength = _worldPacket.ReadBits(11);

    for (auto& q : SurveyQuestion)
    {
        _worldPacket >> q.QuestionID;
        _worldPacket >> q.Answer;
        q.AnswerComment = _worldPacket.ReadString(_worldPacket.ReadBits(11));
    }

    Comment = _worldPacket.ReadString(commentLength);
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
    uint16 textLength = data.ReadBits(12);
    data.ResetBitPos();
    Text = data.ReadString(textLength);
}

WorldPackets::Ticket::SupportTicketSubmitComplaint::SupportTicketChatLine::SupportTicketChatLine(uint32 timestamp, std::string const& text) :
    Timestamp(timestamp), Text(text)
{
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Ticket::SupportTicketSubmitComplaint::SupportTicketChatLine& line)
{
    data >> line.Timestamp;
    uint16 textLength = data.ReadBits(12);
    data.ResetBitPos();
    line.Text = data.ReadString(textLength);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Ticket::SupportTicketSubmitComplaint::SupportTicketChatLog& chatlog)
{
    uint32 linesCount = data.read<uint32>();

    for (uint32 i = 0; i < linesCount; i++)
        chatlog.Lines.emplace_back(data);

    bool hasReportLineIndex = data.ReadBit();
    if (hasReportLineIndex)
        chatlog.ReportLineIndex = data.read<uint32>();

    data.ResetBitPos();

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<WorldPackets::Ticket::SupportTicketSubmitComplaint::SupportTicketMailInfo>& mail)
{
    mail = boost::in_place();

    data >> mail->MailID;
    uint16 bodyLength = data.ReadBits(13);
    uint16 subjectLength = data.ReadBits(9);

    mail->MailBody = data.ReadString(bodyLength);
    mail->MailSubject = data.ReadString(subjectLength);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<WorldPackets::Ticket::SupportTicketSubmitComplaint::SupportTicketCalendarEventInfo>& event)
{
    event = boost::in_place();

    data >> event->EventID;
    data >> event->InviteID;
    uint8 titleLength = data.ReadBits(8);

    event->EventTitle = data.ReadString(titleLength);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<WorldPackets::Ticket::SupportTicketSubmitComplaint::SupportTicketPetInfo>& pet)
{
    pet = boost::in_place();

    data >> pet->PetID;
    uint8 nameLength = data.ReadBits(8);

    pet->PetName = data.ReadString(nameLength);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<WorldPackets::Ticket::SupportTicketSubmitComplaint::SupportTicketGuildInfo>& guild)
{
    guild = boost::in_place();

    data >> guild->GuildID;
    uint8 nameLength = data.ReadBits(8);

    guild->GuildName = data.ReadString(nameLength);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<WorldPackets::Ticket::SupportTicketSubmitComplaint::Struct5E4383>& str)
{
    str = boost::in_place();

    data >> str->RideTicket;
    data >> str->_40;
    data >> str->_56;
    data >> str->_72;

    uint8 _88Length = data.ReadBits(8);
    uint8 _217Length = data.ReadBits(8);
    uint8 _1242Length = data.ReadBits(8);

    str->_88 = data.ReadString(_88Length);
    str->_217 = data.ReadString(_217Length);
    str->_1242 = data.ReadString(_1242Length);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<WorldPackets::Ticket::SupportTicketSubmitComplaint::Struct5E3DFB>& str)
{
    str = boost::in_place();

    data >> str->RideTicket;

    uint16 _32Length = data.ReadBits(9);
    data.ResetBitPos();

    str->_32 = data.ReadString(_32Length);

    return data;
}

void WorldPackets::Ticket::SupportTicketSubmitComplaint::Read()
{
    _worldPacket >> Header;
    _worldPacket >> ChatLog;
    _worldPacket >> TargetCharacterGUID;
    ComplaintType = _worldPacket.ReadBits(5);

    uint16 noteLength = _worldPacket.ReadBits(10);
    bool hasMailInfo = _worldPacket.ReadBit();
    bool hasCalendarInfo = _worldPacket.ReadBit();
    bool hasPetInfo = _worldPacket.ReadBit();
    bool hasGuildInfo = _worldPacket.ReadBit();
    bool has5E4383 = _worldPacket.ReadBit();
    bool has5E3DFB = _worldPacket.ReadBit();

    _worldPacket.ResetBitPos();

    Note = _worldPacket.ReadString(noteLength);

    if (hasMailInfo)
        _worldPacket >> MailInfo;

    if (hasCalendarInfo)
        _worldPacket >> CalenderInfo;

    if (hasPetInfo)
        _worldPacket >> PetInfo;

    if (hasGuildInfo)
        _worldPacket >> GuildInfo;

    if (has5E4383)
        _worldPacket >> _5E4383;

    if (has5E3DFB)
        _worldPacket >> _5E3DFB;
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
