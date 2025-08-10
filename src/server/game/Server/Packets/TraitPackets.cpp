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

#include "TraitPackets.h"
#include "PacketOperators.h"

namespace WorldPackets::Traits
{
void TraitsCommitConfig::Read()
{
    _worldPacket >> Config;
    _worldPacket >> SavedConfigID;
    _worldPacket >> SavedLocalIdentifier;
}

WorldPacket const* TraitConfigCommitFailed::Write()
{
    _worldPacket << int32(ConfigID);
    _worldPacket << int32(SpellID);
    _worldPacket << Bits<4>(Reason);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void ClassTalentsRequestNewConfig::Read()
{
    _worldPacket >> Config;
}

void ClassTalentsRenameConfig::Read()
{
    _worldPacket >> ConfigID;
    _worldPacket >> SizedString::BitsSize<9>(Name);

    _worldPacket >> SizedString::Data<Strings::DontValidateUtf8>(Name);
}

void ClassTalentsDeleteConfig::Read()
{
    _worldPacket >> ConfigID;
}

void ClassTalentsSetStarterBuildActive::Read()
{
    _worldPacket >> ConfigID;
    _worldPacket >> Bits<1>(Active);
}

void ClassTalentsSetUsesSharedActionBars::Read()
{
    _worldPacket >> ConfigID;
    _worldPacket >> Bits<1>(UsesShared);
    _worldPacket >> Bits<1>(IsLastSelectedSavedConfig);
}
}
