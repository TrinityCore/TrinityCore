/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

WorldPacket const* WorldPackets::System::FeatureSystemStatus::Write()
{
    _worldPacket << uint8(ComplaintStatus);

    _worldPacket << uint32(ScrollOfResurrectionRequestsRemaining);
    _worldPacket << uint32(ScrollOfResurrectionMaxRequestsPerDay);
    _worldPacket << uint32(CfgRealmID);
    _worldPacket << int32(CfgRealmRecID);
    _worldPacket << uint32(UnkInt27);
    _worldPacket << uint32(TwitterMsTillCanPost);
    _worldPacket << uint32(TokenPollTimeSeconds);
    _worldPacket << uint32(TokenRedeemIndex);

    _worldPacket.WriteBit(VoiceEnabled);
    _worldPacket.WriteBit(EuropaTicketSystemStatus.is_initialized());
    _worldPacket.WriteBit(ScrollOfResurrectionEnabled);
    _worldPacket.WriteBit(BpayStoreEnabled);
    _worldPacket.WriteBit(BpayStoreAvailable);
    _worldPacket.WriteBit(BpayStoreDisabledByParentalControls);
    _worldPacket.WriteBit(ItemRestorationButtonEnabled);
    _worldPacket.WriteBit(BrowserEnabled);
    _worldPacket.WriteBit(SessionAlert.is_initialized());
    _worldPacket.WriteBit(RecruitAFriendSendingEnabled);
    _worldPacket.WriteBit(CharUndeleteEnabled);
    _worldPacket.WriteBit(RestrictedAccount);
    _worldPacket.WriteBit(TutorialsEnabled);
    _worldPacket.WriteBit(NPETutorialsEnabled);
    _worldPacket.WriteBit(TwitterEnabled);
    _worldPacket.WriteBit(CommerceSystemEnabled);
    _worldPacket.WriteBit(Unk67);
    _worldPacket.WriteBit(WillKickFromWorld);
    _worldPacket.WriteBit(UnkBit61);

    _worldPacket.FlushBits();

    if (EuropaTicketSystemStatus)
    {
        _worldPacket.WriteBit(EuropaTicketSystemStatus->TicketsEnabled);
        _worldPacket.WriteBit(EuropaTicketSystemStatus->BugsEnabled);
        _worldPacket.WriteBit(EuropaTicketSystemStatus->ComplaintsEnabled);
        _worldPacket.WriteBit(EuropaTicketSystemStatus->SuggestionsEnabled);

        _worldPacket << uint32(EuropaTicketSystemStatus->ThrottleState.MaxTries);
        _worldPacket << uint32(EuropaTicketSystemStatus->ThrottleState.PerMilliseconds);
        _worldPacket << uint32(EuropaTicketSystemStatus->ThrottleState.TryCount);
        _worldPacket << uint32(EuropaTicketSystemStatus->ThrottleState.LastResetTimeBeforeNow);
    }

    if (SessionAlert)
    {
        _worldPacket << int32(SessionAlert->Delay);
        _worldPacket << int32(SessionAlert->Period);
        _worldPacket << int32(SessionAlert->DisplayTime);
    }

    /*if (bit61)
    {
        var int88 = packet.ReadInt32("int88");
        for (int i = 0; i < int88; i++)
            packet.ReadByte("byte23", i);
    }*/

    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::System::FeatureSystemStatusGlueScreen::Write()
{
    _worldPacket.WriteBit(BpayStoreEnabled);
    _worldPacket.WriteBit(BpayStoreAvailable);
    _worldPacket.WriteBit(BpayStoreDisabledByParentalControls);
    _worldPacket.WriteBit(CharUndeleteEnabled);
    _worldPacket.WriteBit(CommerceSystemEnabled);
    _worldPacket.WriteBit(Unk14);
    _worldPacket.WriteBit(WillKickFromWorld);
    _worldPacket.WriteBit(IsExpansionPreorderInStore);
    _worldPacket.FlushBits();

    _worldPacket << int32(TokenPollTimeSeconds);
    _worldPacket << int32(TokenRedeemIndex);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::System::MOTD::Write()
{
    ASSERT(Text);
    _worldPacket.WriteBits(Text->size(), 4);
    _worldPacket.FlushBits();

    for (std::string const& line : *Text)
    {
        _worldPacket.WriteBits(line.length(), 7);
        _worldPacket.FlushBits();
        _worldPacket.WriteString(line);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::System::SetTimeZoneInformation::Write()
{
    _worldPacket.WriteBits(ServerTimeTZ.length(), 7);
    _worldPacket.WriteBits(GameTimeTZ.length(), 7);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(ServerTimeTZ);
    _worldPacket.WriteString(GameTimeTZ);

    return &_worldPacket;
}
