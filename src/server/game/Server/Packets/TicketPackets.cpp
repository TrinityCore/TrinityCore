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

void WorldPackets::Ticket::Complaint::Read()
{
    _worldPacket >> ComplaintType; // 0 = mail, 1 = chat
    _worldPacket >> Offender.PlayerGuid;

    switch (ComplaintType)
    {
        case 0: // mail
            _worldPacket.read_skip<uint32>(); // unused
            _worldPacket >> MailID;
            _worldPacket.read_skip<uint32>(); // unused
            break;
        case 1: // chat
            _worldPacket >> Chat.ChatFlags;
            _worldPacket >> Chat.Command;
            _worldPacket >> Chat.ChannelID;
            _worldPacket >> Offender.TimeSinceOffence;
            _worldPacket >> Chat.MessageLog;
            break;
        default:
            break;
    }
}

WorldPacket const* WorldPackets::Ticket::ComplaintResult::Write()
{
    _worldPacket << uint8(Result);
    _worldPacket << uint8(ComplaintType);

    return &_worldPacket;
}

void WorldPackets::Ticket::SupportTicketSubmitSuggestion::Read()
{
    uint32 noteLen = _worldPacket.ReadBits(12);
    Note = _worldPacket.ReadString(noteLen);

    _worldPacket >> Header._Position.Pos.m_positionY;
    _worldPacket >> Header._Position.Pos.m_positionZ;
    _worldPacket >> Header._Position.Pos.m_positionX;
    _worldPacket >> Header.MapID;
    _worldPacket >> Header.Facing;
}

void WorldPackets::Ticket::SupportTicketSubmitBug::Read()
{
    uint32 noteLen = _worldPacket.ReadBits(12);
    Note = _worldPacket.ReadString(noteLen);

    _worldPacket >> Header._Position.Pos.m_positionY;
    _worldPacket >> Header._Position.Pos.m_positionZ;
    _worldPacket >> Header._Position.Pos.m_positionX;
    _worldPacket >> Header.MapID;
    _worldPacket >> Header.Facing;
}

void WorldPackets::Ticket::SupportTicketSubmitComplaint::Read()
{
    TargetCharacterGUID[5] = _worldPacket.ReadBit();
    TargetCharacterGUID[0] = _worldPacket.ReadBit();
    TargetCharacterGUID[1] = _worldPacket.ReadBit();

    uint32 noteLen = _worldPacket.ReadBits(12);

    TargetCharacterGUID[3] = _worldPacket.ReadBit();
    TargetCharacterGUID[2] = _worldPacket.ReadBit();
    TargetCharacterGUID[4] = _worldPacket.ReadBit();
    TargetCharacterGUID[7] = _worldPacket.ReadBit();

    ComplaintType = _worldPacket.ReadBits(4);

    TargetCharacterGUID[6] = _worldPacket.ReadBit();

    _worldPacket.ReadByteSeq(TargetCharacterGUID[3]);
    _worldPacket.ReadByteSeq(TargetCharacterGUID[5]);
    _worldPacket.ReadByteSeq(TargetCharacterGUID[1]);
    _worldPacket.ReadByteSeq(TargetCharacterGUID[2]);
    _worldPacket.ReadByteSeq(TargetCharacterGUID[6]);
    _worldPacket.ReadByteSeq(TargetCharacterGUID[0]);

    Note = _worldPacket.ReadString(noteLen);

    _worldPacket.ReadByteSeq(TargetCharacterGUID[7]);
    _worldPacket.ReadByteSeq(TargetCharacterGUID[4]);

    _worldPacket >> Header._Position.Pos.m_positionY;
    _worldPacket >> Header._Position.Pos.m_positionZ;
    _worldPacket >> Header._Position.Pos.m_positionX;
    _worldPacket >> Header.MapID;
    _worldPacket >> Header.Facing;

    bool hasChatLogReportLineIndex = _worldPacket.ReadBit();
    uint32 chatLogSize = _worldPacket.ReadBits(22);

    std::vector<uint32> chatLogLineLengths;
    chatLogLineLengths.reserve(chatLogSize);
    for (uint32 i = 0; i < chatLogSize; ++i)
        chatLogLineLengths.push_back(_worldPacket.ReadBits(13));

    ChatLog.Lines.resize(chatLogSize);
    uint32 lineIndex = 0;
    for (SupportTicketChatLine& line : ChatLog.Lines)
    {
        _worldPacket >> line.Timestamp;
        line.Text = _worldPacket.ReadString(chatLogLineLengths[lineIndex]);
        ++lineIndex;
    }

    if (hasChatLogReportLineIndex)
        ChatLog.ReportLineIndex = _worldPacket.read<int32>();
}
