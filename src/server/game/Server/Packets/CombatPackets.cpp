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
#include "Unit.h"

void WorldPackets::Combat::AttackSwing::Read()
{
    _worldPacket >> Victim;
}

WorldPacket const* WorldPackets::Combat::AttackStart::Write()
{
    _worldPacket << Attacker;
    _worldPacket << Victim;

    return &_worldPacket;
}

WorldPackets::Combat::SAttackStop::SAttackStop(Unit const* attacker, Unit const* victim) : ServerPacket(SMSG_ATTACK_STOP, 16 + 16 + 1)
{
    Attacker = attacker->GetGUID();
    if (victim)
    {
        Victim = victim->GetGUID();
        NowDead = !victim->IsAlive(); // using isAlive instead of isDead to catch JUST_DIED death states as well
    }
}

WorldPacket const* WorldPackets::Combat::SAttackStop::Write()
{
    _worldPacket << Attacker;
    _worldPacket << Victim;
    _worldPacket.WriteBit(NowDead);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::ThreatUpdate::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << int32(ThreatList.size());
    for (WorldPackets::Combat::ThreatInfo const& threatInfo : ThreatList)
    {
        _worldPacket << threatInfo.UnitGUID;
        _worldPacket << int64(threatInfo.Threat);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::HighestThreatUpdate::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << HighestThreatGUID;
    _worldPacket << int32(ThreatList.size());
    for (WorldPackets::Combat::ThreatInfo const& threatInfo : ThreatList)
    {
        _worldPacket << threatInfo.UnitGUID;
        _worldPacket << int64(threatInfo.Threat);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::ThreatRemove::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << AboutGUID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::AIReaction::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << Reaction;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::AttackSwingError::Write()
{
    _worldPacket.WriteBits(Reason, 3);
    _worldPacket.FlushBits();
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::PowerUpdate::Write()
{
    _worldPacket << Guid;
    _worldPacket << uint32(Powers.size());
    for (PowerUpdatePower const& power : Powers)
    {
        _worldPacket << int32(power.Power);
        _worldPacket << uint8(power.PowerType);
    }

    return &_worldPacket;
}

void WorldPackets::Combat::SetSheathed::Read()
{
    _worldPacket >> CurrentSheathState;
    Animate = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::Combat::CancelAutoRepeat::Write()
{
    _worldPacket << Guid;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::HealthUpdate::Write()
{
    _worldPacket << Guid;
    _worldPacket << int64(Health);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::ThreatClear::Write()
{
    _worldPacket << UnitGUID;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::PvPCredit::Write()
{
    _worldPacket << int32(OriginalHonor);
    _worldPacket << int32(Honor);
    _worldPacket << Target;
    _worldPacket << int32(Rank);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::BreakTarget::Write()
{
    _worldPacket << UnitGUID;

    return &_worldPacket;
}
