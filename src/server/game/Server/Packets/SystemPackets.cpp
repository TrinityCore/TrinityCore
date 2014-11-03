/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

WorldPackets::System::FeatureSystemStatusGlueScreen::FeatureSystemStatusGlueScreen()
    : ServerPacket(SMSG_FEATURE_SYSTEM_STATUS_GLUE_SCREEN, 1) { }

void WorldPackets::System::FeatureSystemStatusGlueScreen::Write()
{
    _worldPacket.WriteBit(BpayStoreEnabled);
    _worldPacket.WriteBit(BpayStoreAvailable);
    _worldPacket.WriteBit(BpayStoreDisabledByParentalControls);
    _worldPacket.WriteBit(CharUndeleteEnabled);
    _worldPacket.FlushBits();
}

WorldPackets::System::SetTimeZoneInformation::SetTimeZoneInformation()
    : ServerPacket(SMSG_SET_TIME_ZONE_INFORMATION) { }

void WorldPackets::System::SetTimeZoneInformation::Write()
{
    _worldPacket.reserve(1 + ServerTimeTZ.length() + GameTimeTZ.length());

    _worldPacket.WriteBits(ServerTimeTZ.length(), 7);
    _worldPacket.WriteBits(GameTimeTZ.length(), 7);
    _worldPacket.WriteString(ServerTimeTZ);
    _worldPacket.WriteString(GameTimeTZ);
}
