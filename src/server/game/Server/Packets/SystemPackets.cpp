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

#include "SystemPackets.h"
#include "Errors.h"

WorldPacket const* WorldPackets::System::FeatureSystemStatus::Write()
{
    _worldPacket << int8(ComplaintStatus);
    _worldPacket << int32(ScrollOfResurrectionRequestsRemaining);
    _worldPacket << int32(ScrollOfResurrectionMaxRequestsPerDay);
    _worldPacket << int32(CfgRealmID);
    _worldPacket << int32(CfgRealmRecID);
    _worldPacket.WriteBit(ItemRestorationButtonEnabled);
    _worldPacket.WriteBit(TravelPassEnabled);
    _worldPacket.WriteBit(ScrollOfResurrectionEnabled);
    _worldPacket.WriteBit(EuropaTicketSystemStatus.has_value());
    _worldPacket.WriteBit(SessionAlert.has_value());
    _worldPacket.WriteBit(VoiceEnabled);
    _worldPacket.FlushBits();

    if (EuropaTicketSystemStatus)
    {
        _worldPacket << int32(EuropaTicketSystemStatus->TryCount);
        _worldPacket << int32(EuropaTicketSystemStatus->LastResetTimeBeforeNow);
        _worldPacket << int32(EuropaTicketSystemStatus->MaxTries);
        _worldPacket << int32(EuropaTicketSystemStatus->PerMilliseconds);
    }

    if (SessionAlert)
    {
        _worldPacket << int32(SessionAlert->Period);
        _worldPacket << int32(SessionAlert->Delay);
        _worldPacket << int32(SessionAlert->DisplayTime);
    }
    return &_worldPacket;
}

WorldPacket const* WorldPackets::System::MOTD::Write()
{
    ASSERT(Text);
    _worldPacket << int32(Text->size());

    for (std::string const& line : *Text)
        _worldPacket << line;

    return &_worldPacket;
}
