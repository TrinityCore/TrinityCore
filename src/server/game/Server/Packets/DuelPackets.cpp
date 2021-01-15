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

#include "DuelPackets.h"

void WorldPackets::Duel::CanDuel::Read()
{
    _worldPacket >> TargetGUID;
}

WorldPacket const* WorldPackets::Duel::CanDuelResult::Write()
{
    _worldPacket << TargetGUID;
    _worldPacket.WriteBit(Result);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Duel::DuelComplete::Write()
{
    _worldPacket.WriteBit(Started);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Duel::DuelCountdown::Write()
{
    _worldPacket << uint32(Countdown);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Duel::DuelRequested::Write()
{
    _worldPacket << ArbiterGUID;
    _worldPacket << RequestedByGUID;
    _worldPacket << RequestedByWowAccount;

    return &_worldPacket;
}

void WorldPackets::Duel::DuelResponse::Read()
{
    _worldPacket >> ArbiterGUID;
    Accepted = _worldPacket.ReadBit();
    Forfeited = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::Duel::DuelWinner::Write()
{
    _worldPacket.WriteBits(BeatenName.size(), 6);
    _worldPacket.WriteBits(WinnerName.size(), 6);
    _worldPacket.WriteBit(Fled);
    _worldPacket << uint32(BeatenVirtualRealmAddress);
    _worldPacket << uint32(WinnerVirtualRealmAddress);
    _worldPacket.WriteString(BeatenName);
    _worldPacket.WriteString(WinnerName);

    return &_worldPacket;
}
