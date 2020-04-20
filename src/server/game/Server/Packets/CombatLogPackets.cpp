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
#include "UnitDefines.h"

WorldPacket const* WorldPackets::CombatLog::AttackerStateUpdate::Write()
{
    _worldPacket << int32(HitInfo);
    _worldPacket << AttackerGUID.WriteAsPacked();
    _worldPacket << VictimGUID.WriteAsPacked();
    _worldPacket << int32(Damage);
    _worldPacket << int32(OverDamage);
    _worldPacket << uint8(SubDmg.is_initialized());

    if (SubDmg)
    {
        _worldPacket << int32(SubDmg->SchoolMask);
        _worldPacket << float(SubDmg->FDamage);
        _worldPacket << int32(SubDmg->Damage);

        if (HitInfo & (HITINFO_FULL_ABSORB | HITINFO_PARTIAL_ABSORB))
            _worldPacket << int32(SubDmg->Absorbed);
        if (HitInfo & (HITINFO_FULL_RESIST | HITINFO_PARTIAL_RESIST))
            _worldPacket << int32(SubDmg->Resisted);
    }

    _worldPacket << uint8(VictimState);
    _worldPacket << uint32(AttackerState);
    _worldPacket << uint32(MeleeSpellID);

    if (HitInfo & HITINFO_BLOCK)
        _worldPacket << int32(BlockAmount);

    if (HitInfo & HITINFO_RAGE_GAIN)
        _worldPacket << int32(RageGained);

    if (HitInfo & HITINFO_UNK1)
    {
        _worldPacket << uint32(UnkState.State1);
        _worldPacket << float(UnkState.State2);
        _worldPacket << float(UnkState.State3);
        _worldPacket << float(UnkState.State4);
        _worldPacket << float(UnkState.State5);
        _worldPacket << float(UnkState.State6);
        _worldPacket << float(UnkState.State7);
        _worldPacket << float(UnkState.State8);
        _worldPacket << float(UnkState.State9);
        _worldPacket << float(UnkState.State10);
        _worldPacket << float(UnkState.State11);
        _worldPacket << uint32(UnkState.State12);
    }

    if (HitInfo & (HITINFO_BLOCK | HITINFO_UNK12))
        _worldPacket << float(Unk);

    return &_worldPacket;
}
