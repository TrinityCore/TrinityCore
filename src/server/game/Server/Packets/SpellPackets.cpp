/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "SpellPackets.h"
#include "SharedDefines.h"
#include "Spell.h"
#include "SpellInfo.h"

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellMissStatus const& spellMissStatus)
{
    data << uint64(spellMissStatus.TargetGUID);
    data << uint8(spellMissStatus.Reason);
    if (spellMissStatus.Reason == SPELL_MISS_REFLECT)
        data << uint8(spellMissStatus.ReflectStatus);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::TargetLocation const& targetLocation)
{
    data << targetLocation.Transport.WriteAsPacked(); // relative position guid here - transport for example
    data << targetLocation.Location.PositionXYZStream();
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellTargetData const& spellTargetData)
{
    data << uint32(spellTargetData.Flags);

    if (spellTargetData.Unit)
        data << spellTargetData.Unit->WriteAsPacked();

    if (spellTargetData.Item)
        data << spellTargetData.Item->WriteAsPacked();

    if (spellTargetData.SrcLocation)
        data << *spellTargetData.SrcLocation;

    if (spellTargetData.DstLocation)
        data << *spellTargetData.DstLocation;

    if (spellTargetData.Name)
        data << *spellTargetData.Name;
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::RuneData const& runeData)
{
    data << uint8(runeData.Start);
    data << uint8(runeData.Count);
    for (uint8 cooldown : runeData.Cooldowns)
        data << uint8(cooldown);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::MissileTrajectoryResult const& traj)
{
    data << float(traj.Pitch);
    data << uint32(traj.TravelTime);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellAmmo const& spellAmmo)
{
    data << uint32(spellAmmo.DisplayID);
    data << uint32(spellAmmo.InventoryType);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::CreatureImmunities const& immunities)
{
    data << uint32(immunities.School);
    data << uint32(immunities.Value);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellCastData const& spellCastData)
{
    data << spellCastData.CasterGUID.WriteAsPacked();
    data << spellCastData.CasterUnit.WriteAsPacked();
    data << uint8(spellCastData.CastID);                // pending spell cast?
    data << uint32(spellCastData.SpellID);              // spellId
    data << uint32(spellCastData.CastFlags);            // cast flags
    data << uint32(spellCastData.CastTime);             // timestamp

    if (spellCastData.HitTargets && spellCastData.MissStatus)
    {
        // Hit and miss target counts are both uint8, that limits us to 255 targets for each
        // sending more than 255 targets crashes the client (since count sent would be wrong)
        // Spells like 40647 (with a huge radius) can easily reach this limit (spell might need
        // target conditions but we still need to limit the number of targets sent and keeping
        // correct count for both hit and miss).
        static std::size_t const PACKET_TARGET_LIMIT = std::numeric_limits<uint8>::max();
        if (spellCastData.HitTargets->size() > PACKET_TARGET_LIMIT)
            spellCastData.HitTargets->resize(PACKET_TARGET_LIMIT);

        data << uint8(spellCastData.HitTargets->size());
        for (ObjectGuid const& target : *spellCastData.HitTargets)
            data << uint64(target);

        if (spellCastData.MissStatus->size() > PACKET_TARGET_LIMIT)
            spellCastData.MissStatus->resize(PACKET_TARGET_LIMIT);

        data << uint8(spellCastData.MissStatus->size());
        for (WorldPackets::Spells::SpellMissStatus const& status : *spellCastData.MissStatus)
            data << status;
    }

    data << spellCastData.Target;

    if (spellCastData.RemainingPower)
        data << uint32(*spellCastData.RemainingPower);

    if (spellCastData.RemainingRunes)
        data << *spellCastData.RemainingRunes;

    if (spellCastData.MissileTrajectory)
        data << *spellCastData.MissileTrajectory;

    if (spellCastData.Ammo)
        data << *spellCastData.Ammo;

    if (spellCastData.Immunities)
        data << *spellCastData.Immunities;

    if (spellCastData.CastFlags & CAST_FLAG_VISUAL_CHAIN)
    {
        data << uint32(0);
        data << uint32(0);
    }

    if (spellCastData.Target.Flags & TARGET_FLAG_DEST_LOCATION)
        data << uint8(0);
    return data;
}

WorldPacket const* WorldPackets::Spells::SpellGo::Write()
{
    _worldPacket << Cast;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::SpellStart::Write()
{
    _worldPacket << Cast;
    return &_worldPacket;
}
