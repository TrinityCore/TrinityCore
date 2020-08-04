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

#include "SpellPackets.h"

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellHealPrediction const& predict)
{
    data << int32(predict.Points);
    data << uint8(predict.Type);
    if (predict.BeaconGUID.is_initialized())
        data << predict.BeaconGUID->WriteAsPacked();
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::CreatureImmunities const& immunities)
{
    data << int32(immunities.School);
    data << int32(immunities.Value);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::MissileTrajectoryResult const& missileTrajectory)
{
    data << float(missileTrajectory.Pitch);
    data << int32(missileTrajectory.TravelTime);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellAmmo const& spellAmmo)
{
    data << int32(spellAmmo.DisplayID);
    data << int32(spellAmmo.InventoryType);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::RuneData const& runeData)
{
    data << uint8(runeData.Start);
    data << uint8(runeData.Count);
    if (!runeData.Cooldowns.empty())
        data.append(runeData.Cooldowns.data(), runeData.Cooldowns.size());

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::TargetLocation const& targetLocation)
{
    data << targetLocation.Transport.WriteAsPacked();
    data << targetLocation.Location.PositionXYZStream();
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::ProjectileVisual const& projectileVisual)
{
    data << int32(projectileVisual.Id[0]);
    data << int32(projectileVisual.Id[1]);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellTargetData const& spellTargetData)
{
    data << uint32(spellTargetData.Flags);

    if (spellTargetData.Unit.is_initialized())
        data << spellTargetData.Unit->WriteAsPacked();

    if (spellTargetData.Item.is_initialized())
        data << spellTargetData.Item->WriteAsPacked();

    if (spellTargetData.SrcLocation)
        data << *spellTargetData.SrcLocation;

    if (spellTargetData.DstLocation)
        data << *spellTargetData.DstLocation;

    if (spellTargetData.Name.is_initialized())
        data << *spellTargetData.Name;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellHitInfo const& spellHitInfo)
{
    data << uint8(spellHitInfo.HitTargets.size());
    for (ObjectGuid const& hitTarget : spellHitInfo.HitTargets)
        data << hitTarget;

    data << uint8(spellHitInfo.MissStatus.size());
    for (WorldPackets::Spells::SpellMissStatus const& missTarget : spellHitInfo.MissStatus)
    {
        data << missTarget.MissTarget;
        data << uint8(missTarget.Reason);
        if (missTarget.ReflectStatus)
            data << uint8(missTarget.ReflectStatus);
    }
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellCastData const& spellCastData)
{
    data << spellCastData.CasterGUID.WriteAsPacked();
    data << spellCastData.CasterUnit.WriteAsPacked();
    data << uint8(spellCastData.CastID);
    data << uint32(spellCastData.SpellID);
    data << uint32(spellCastData.CastFlags);
    data << uint32(spellCastData.CastFlagsEx);
    data << uint32(spellCastData.CastTime);

    if (spellCastData.HitInfo)
        data << *spellCastData.HitInfo;

    data << spellCastData.Target;

    if (spellCastData.RemainingPower.is_initialized())
        data << uint32(*spellCastData.RemainingPower);

    if (spellCastData.RemainingRunes)
        data << *spellCastData.RemainingRunes;

    if (spellCastData.MissileTrajectory)
        data << *spellCastData.MissileTrajectory;

    if (spellCastData.Ammo)
        data << *spellCastData.Ammo;

    if (spellCastData.ProjectileVisuals)
        data << *spellCastData.ProjectileVisuals;

    if (spellCastData.DestLocSpellCastIndex.is_initialized())
        data << uint8(*spellCastData.DestLocSpellCastIndex);

    // Todo: TARGET_FLAG_EXTRA_TARGETS (unused as it seems though)

    if (spellCastData.Immunities)
        data << *spellCastData.Immunities;

    if (spellCastData.Predict)
        data << *spellCastData.Predict;

    return data;
}

WorldPacket const* WorldPackets::Spells::SpellStart::Write()
{
    _worldPacket << Cast;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::SpellGo::Write()
{
    _worldPacket << Cast;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::TargetedHealPrediction const& predict)
{
    data << predict.TargetGUID.WriteAsPacked();
    data << predict.Predict;
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::ChannelStartInterruptImmunities const& immunity)
{
    data << immunity.SchoolImmunities;
    data << immunity.Immunities;
    return data;
}

WorldPacket const* WorldPackets::Spells::ChannelStart::Write()
{
    _worldPacket << CasterGUID.WriteAsPacked();
    _worldPacket << uint32(SpellID);
    _worldPacket << int32(ChannelDuration);

    _worldPacket << uint8(InterruptImmunities.is_initialized());
    if (InterruptImmunities)
        _worldPacket << *InterruptImmunities;

    _worldPacket << uint8(HealPrediction.is_initialized());
    if (HealPrediction)
        _worldPacket << *HealPrediction;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::MountResult::Write()
{
    _worldPacket << int32(Result);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::AuraDataInfo const& auraData)
{
    data << int32(auraData.SpellID);
    if (auraData.SpellID <= 0)
        return data;

    data << int16(auraData.Flags);
    data << uint8(auraData.CastLevel);
    data << uint8(auraData.Applications);

    if (auraData.CastUnit)
        data << auraData.CastUnit.get().WriteAsPacked();

    if (auraData.Duration)
        data << int32(*auraData.Duration);

    if (auraData.Remaining)
        data << int32(*auraData.Remaining);

    for (uint8 i = 0; i < 3 /*MAX_SPELL_EFFECTS*/; ++i)
        if (auraData.Points[i].is_initialized())
            data << int32(*auraData.Points[i]);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::AuraInfo const& aura)
{
    data << uint8(aura.Slot);
    data << aura.AuraData;

    return data;
}

WorldPacket const* WorldPackets::Spells::AuraUpdate::Write()
{
    _worldPacket << UnitGUID.WriteAsPacked();

    for (AuraInfo const& aura : Auras)
        _worldPacket << aura;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::AuraUpdateAll::Write()
{
    _worldPacket << UnitGUID.WriteAsPacked();

    for (AuraInfo const& aura : Auras)
        _worldPacket << aura;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::MissileCancel::Write()
{
    _worldPacket.WriteBit(OwnerGUID[7]);
    _worldPacket.WriteBit(OwnerGUID[2]);
    _worldPacket.WriteBit(OwnerGUID[4]);
    _worldPacket.WriteBit(OwnerGUID[6]);
    _worldPacket.WriteBit(Reverse);
    _worldPacket.WriteBit(OwnerGUID[1]);
    _worldPacket.WriteBit(OwnerGUID[0]);
    _worldPacket.WriteBit(OwnerGUID[3]);
    _worldPacket.WriteBit(OwnerGUID[5]);

    _worldPacket.FlushBits();

    _worldPacket.WriteByteSeq(OwnerGUID[6]);
    _worldPacket.WriteByteSeq(OwnerGUID[1]);
    _worldPacket.WriteByteSeq(OwnerGUID[4]);
    _worldPacket.WriteByteSeq(OwnerGUID[2]);
    _worldPacket.WriteByteSeq(OwnerGUID[5]);
    _worldPacket.WriteByteSeq(OwnerGUID[7]);
    _worldPacket << uint32(SpellID);
    _worldPacket.WriteByteSeq(OwnerGUID[0]);
    _worldPacket.WriteByteSeq(OwnerGUID[3]);

    return &_worldPacket;
}
