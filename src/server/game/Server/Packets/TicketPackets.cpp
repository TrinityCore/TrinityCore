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

#include "TicketPackets.h"

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
    _worldPacket.WriteBit(Info.HasValue);

    if (Info.HasValue)
    {
        _worldPacket << int32(Info.Value.TicketID);
        _worldPacket << uint8(Info.Value.Category);
        _worldPacket.AppendPackedTime(Info.Value.TicketOpenTime);
        _worldPacket.AppendPackedTime(Info.Value.OldestTicketTime);
        _worldPacket.AppendPackedTime(Info.Value.UpdateTime);
        _worldPacket << uint8(Info.Value.AssignedToGM);
        _worldPacket << uint8(Info.Value.OpenedByGM);
        _worldPacket << int32(Info.Value.WaitTimeOverrideMinutes);

        _worldPacket.WriteBits(Info.Value.TicketDescription.size(), 11);
        _worldPacket.WriteBits(Info.Value.WaitTimeOverrideMessage.size(), 10);

        _worldPacket.WriteString(Info.Value.TicketDescription);
        _worldPacket.WriteString(Info.Value.WaitTimeOverrideMessage);
    }

    return &_worldPacket;
}
