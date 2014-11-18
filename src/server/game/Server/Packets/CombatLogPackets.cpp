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

#include "CombatLogPackets.h"

WorldPacket const* WorldPackets::CombatLog::EnvironmentalDamageLog::Write()
{
    _worldPacket << Victim;
    _worldPacket << uint8(Type);
    _worldPacket << uint32(Amount);
    _worldPacket << uint32(Resisted);
    _worldPacket << uint32(Absorbed);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::CombatLog::AttackerStateUpdate::Write()
{
    _worldPacket << uint32(Flags);
    _worldPacket << AttackerGUID.WriteAsPacked();
    _worldPacket << VictimGUID.WriteAsPacked();
    _worldPacket << uint32(Damage);
    _worldPacket << uint32(OverDamage);
    _worldPacket << uint8(SubDmgCount);

    for (uint32 i = 0; i < SubDmgCount; ++i)
    {
        _worldPacket << uint32(SubDmg[i].SchoolMask);
        _worldPacket << float(SubDmg[i].FDamage);
        _worldPacket << uint32(SubDmg[i].Damage);
    }

    if (Flags & (HITINFO_FULL_ABSORB | HITINFO_PARTIAL_ABSORB))
        for (uint32 i = 0; i < SubDmgCount; ++i)
            _worldPacket << uint32(SubDmg[i].Absorbed);

    if (Flags & (HITINFO_FULL_RESIST | HITINFO_PARTIAL_RESIST))
        for (uint32 i = 0; i < SubDmgCount; ++i)
            _worldPacket << uint32(SubDmg[i].Resisted);

    _worldPacket << uint8(VictimState);
    _worldPacket << uint32(AttackerState);
    _worldPacket << uint32(MeleeSpellID);

    if (Flags & HITINFO_BLOCK)
        _worldPacket << uint32(BlockAmount);

    if (Flags & HITINFO_RAGE_GAIN)
        _worldPacket << uint32(RageGained);

    if (Flags & HITINFO_UNK1)
    {
        _worldPacket << uint32(HitInfo.ArmorReduction);
        _worldPacket << float(HitInfo.CritRollNeeded);
        _worldPacket << float(HitInfo.CombatRoll);
        _worldPacket << float(HitInfo.MissChance);
        _worldPacket << float(HitInfo.DodgeChance);
        _worldPacket << float(HitInfo.ParryChance);
        _worldPacket << float(HitInfo.BlockChance);
        _worldPacket << float(HitInfo.GlanceChance);
        _worldPacket << float(HitInfo.CrushChance);
        _worldPacket << float(HitInfo.MinDamage[0]);
        _worldPacket << float(HitInfo.MaxDamage[0]);
        _worldPacket << float(HitInfo.MinDamage[1]);
        _worldPacket << float(HitInfo.MaxDamage[1]);
        _worldPacket << uint32(HitInfo.SinceLastSwing);
    }

    return &_worldPacket;
}
