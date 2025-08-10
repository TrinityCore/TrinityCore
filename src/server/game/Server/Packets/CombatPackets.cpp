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

#include "CombatPackets.h"
#include "PacketOperators.h"

namespace WorldPackets::Combat
{
void AttackSwing::Read()
{
    _worldPacket >> Victim;
}

WorldPacket const* AttackStart::Write()
{
    _worldPacket << Attacker;
    _worldPacket << Victim;

    return &_worldPacket;
}

WorldPacket const* SAttackStop::Write()
{
    _worldPacket << Attacker;
    _worldPacket << Victim;
    _worldPacket << Bits<1>(NowDead);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* ThreatUpdate::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << Size<uint32>(ThreatList);
    for (ThreatInfo const& threatInfo : ThreatList)
    {
        _worldPacket << threatInfo.UnitGUID;
        _worldPacket << int64(threatInfo.Threat);
    }

    return &_worldPacket;
}

WorldPacket const* HighestThreatUpdate::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << HighestThreatGUID;
    _worldPacket << Size<uint32>(ThreatList);
    for (ThreatInfo const& threatInfo : ThreatList)
    {
        _worldPacket << threatInfo.UnitGUID;
        _worldPacket << int64(threatInfo.Threat);
    }

    return &_worldPacket;
}

WorldPacket const* ThreatRemove::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << AboutGUID;

    return &_worldPacket;
}

WorldPacket const* AIReaction::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << Reaction;

    return &_worldPacket;
}

WorldPacket const* AttackSwingError::Write()
{
    _worldPacket << Bits<3>(Reason);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* PowerUpdate::Write()
{
    _worldPacket << Guid;
    _worldPacket << Size<uint32>(Powers);
    for (PowerUpdatePower const& power : Powers)
    {
        _worldPacket << uint8(power.PowerType);
        _worldPacket << int32(power.Power);
    }

    return &_worldPacket;
}

WorldPacket const* InterruptPowerRegen::Write()
{
    _worldPacket << int8(PowerType);

    return &_worldPacket;
}

void SetSheathed::Read()
{
    _worldPacket >> CurrentSheathState;
    _worldPacket >> Bits<1>(Animate);
}

WorldPacket const* CancelAutoRepeat::Write()
{
    _worldPacket << Guid;

    return &_worldPacket;
}

WorldPacket const* HealthUpdate::Write()
{
    _worldPacket << Guid;
    _worldPacket << int64(Health);

    return &_worldPacket;
}

WorldPacket const* ThreatClear::Write()
{
    _worldPacket << UnitGUID;

    return &_worldPacket;
}

WorldPacket const* PvPCredit::Write()
{
    _worldPacket << int32(OriginalHonor);
    _worldPacket << int32(Honor);
    _worldPacket << Target;
    _worldPacket << int8(Rank);

    return &_worldPacket;
}

WorldPacket const* BreakTarget::Write()
{
    _worldPacket << UnitGUID;

    return &_worldPacket;
}
}
