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

#include "CombatPackets.h"
#include "SpellPackets.h"

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

WorldPackets::Combat::SAttackStop::SAttackStop(Unit const* attacker, Unit const* victim) : ServerPacket(SMSG_ATTACKSTOP, 16 + 16 + 1)
{
    Attacker = attacker->GetGUID();
    if (victim)
    {
        Victim = victim->GetGUID();
        NowDead = victim->isDead();
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
        _worldPacket << threatInfo.Threat;
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
        _worldPacket << threatInfo.Threat;
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

WorldPacket const* WorldPackets::Combat::AttackerStateUpdate::Write()
{
    if (_worldPacket.WriteBit(LogData.HasValue))
        _worldPacket << LogData.Value;

    // Placeholder for size which will be calculated at the end based on packet size
    // Client uses this size to copy remaining packet to another CDataStore
    _worldPacket << int32(0);
    size_t pos = _worldPacket.wpos();

    _worldPacket << HitInfo;
    _worldPacket << AttackerGUID;
    _worldPacket << VictimGUID;
    _worldPacket << Damage;
    _worldPacket << OverDamage;
    if (_worldPacket.WriteBit(SubDmg.HasValue))
    {
        _worldPacket << SubDmg.Value.SchoolMask;
        _worldPacket << SubDmg.Value.FDamage;
        _worldPacket << SubDmg.Value.Damage;
        if (HitInfo & (HITINFO_FULL_ABSORB | HITINFO_PARTIAL_ABSORB))
            _worldPacket << SubDmg.Value.Absorbed;
        if (HitInfo & (HITINFO_FULL_RESIST | HITINFO_PARTIAL_RESIST))
            _worldPacket << SubDmg.Value.Resisted;
    }

    _worldPacket << VictimState;
    _worldPacket << AttackerState;
    _worldPacket << MeleeSpellID;
    if (HitInfo & HITINFO_BLOCK)
        _worldPacket << BlockAmount;
    if (HitInfo & HITINFO_RAGE_GAIN)
        _worldPacket << RageGained;
    if (HitInfo & HITINFO_UNK1)
    {
        _worldPacket << UnkState.State1;
        _worldPacket << UnkState.State2;
        _worldPacket << UnkState.State3;
        _worldPacket << UnkState.State4;
        _worldPacket << UnkState.State5;
        _worldPacket << UnkState.State6;
        _worldPacket << UnkState.State7;
        _worldPacket << UnkState.State8;
        _worldPacket << UnkState.State9;
        _worldPacket << UnkState.State10;
        _worldPacket << UnkState.State11;
        _worldPacket << UnkState.State12;
    }
    if (HitInfo & (HITINFO_BLOCK|HITINFO_UNK12))
        _worldPacket << Unk;

    // Update size placeholder
    _worldPacket.put<int32>(pos - sizeof(int32), _worldPacket.wpos() - pos);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::AttackSwingError::Write()
{
    _worldPacket.WriteBits(Reason, 2);
    _worldPacket.FlushBits();
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::PowerUpdate::Write()
{
    _worldPacket << Guid;
    _worldPacket << uint32(Powers.size());
    for (PowerUpdatePower const& power : Powers)
    {
        _worldPacket << power.Power;
        _worldPacket << power.PowerType;
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
