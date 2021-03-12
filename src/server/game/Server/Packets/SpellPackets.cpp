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
    if (predict.BeaconGUID.has_value())
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

    if (spellTargetData.Unit.has_value())
        data << spellTargetData.Unit->WriteAsPacked();

    if (spellTargetData.Item.has_value())
        data << spellTargetData.Item->WriteAsPacked();

    if (spellTargetData.SrcLocation)
        data << *spellTargetData.SrcLocation;

    if (spellTargetData.DstLocation)
        data << *spellTargetData.DstLocation;

    if (spellTargetData.Name.has_value())
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
        if (missTarget.Reason == SPELL_MISS_REFLECT)
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
    {
        // Hit and miss target counts are both uint8, that limits us to 255 targets for each
        // sending more than 255 targets crashes the client (since count sent would be wrong)
        // Spells like 40647 (with a huge radius) can easily reach this limit (spell might need
        // target conditions but we still need to limit the number of targets sent and keeping
        // correct count for both hit and miss).
        static std::size_t const PACKET_TARGET_LIMIT = std::numeric_limits<uint8>::max();
        if (spellCastData.HitInfo->HitTargets.size() > PACKET_TARGET_LIMIT)
            spellCastData.HitInfo->HitTargets.resize(PACKET_TARGET_LIMIT);

        if (spellCastData.HitInfo->MissStatus.size() > PACKET_TARGET_LIMIT)
            spellCastData.HitInfo->MissStatus.resize(PACKET_TARGET_LIMIT);

        data << *spellCastData.HitInfo;
    }

    data << spellCastData.Target;

    if (spellCastData.RemainingPower.has_value())
        data << uint32(*spellCastData.RemainingPower);

    if (spellCastData.RemainingRunes)
        data << *spellCastData.RemainingRunes;

    if (spellCastData.MissileTrajectory)
        data << *spellCastData.MissileTrajectory;

    if (spellCastData.Ammo)
        data << *spellCastData.Ammo;

    if (spellCastData.ProjectileVisuals)
        data << *spellCastData.ProjectileVisuals;

    if (spellCastData.DestLocSpellCastIndex.has_value())
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

    _worldPacket << uint8(InterruptImmunities.has_value());
    if (InterruptImmunities)
        _worldPacket << *InterruptImmunities;

    _worldPacket << uint8(HealPrediction.has_value());
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
        data << auraData.CastUnit.value().WriteAsPacked();

    if (auraData.Duration)
        data << int32(*auraData.Duration);

    if (auraData.Remaining)
        data << int32(*auraData.Remaining);

    for (uint8 i = 0; i < 3 /*MAX_SPELL_EFFECTS*/; ++i)
        if (auraData.Points[i].has_value())
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

WorldPacket const* WorldPackets::Spells::CategoryCooldown::Write()
{
    _worldPacket.reserve(4 + 8 * CategoryCooldowns.size());

    _worldPacket.WriteBits(CategoryCooldowns.size(), 23);
    _worldPacket.FlushBits();

    for (CategoryCooldownInfo const& cooldown : CategoryCooldowns)
    {
        _worldPacket << uint32(cooldown.Category);
        _worldPacket << int32(cooldown.ModCooldown);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::PlaySpellVisual::Write()
{
    _worldPacket << float(TargetPosition.GetPositionZ());
    _worldPacket << int32(SpellVisualID);
    _worldPacket << uint16(MissReason);
    _worldPacket << float(TargetPosition.GetOrientation());
    _worldPacket << float(TargetPosition.GetPositionX());
    _worldPacket << uint16(ReflectStatus);
    _worldPacket << float(TargetPosition.GetPositionY());

    _worldPacket.WriteBit(Target[1]);
    _worldPacket.WriteBit(Source[3]);
    _worldPacket.WriteBit(Source[0]);
    _worldPacket.WriteBit(Target[2]);
    _worldPacket.WriteBit(Target[5]);
    _worldPacket.WriteBit(Source[2]);
    _worldPacket.WriteBit(Source[4]);
    _worldPacket.WriteBit(Target[6]);

    _worldPacket.WriteBit(SpeedAsTime);

    _worldPacket.WriteBit(Source[6]);
    _worldPacket.WriteBit(Target[7]);
    _worldPacket.WriteBit(Source[5]);
    _worldPacket.WriteBit(Source[1]);
    _worldPacket.WriteBit(Source[7]);
    _worldPacket.WriteBit(Target[3]);
    _worldPacket.WriteBit(Target[4]);
    _worldPacket.FlushBits();

    _worldPacket.WriteByteSeq(Source[7]);
    _worldPacket.WriteByteSeq(Source[4]);
    _worldPacket.WriteByteSeq(Target[7]);
    _worldPacket.WriteByteSeq(Source[1]);
    _worldPacket.WriteByteSeq(Source[3]);
    _worldPacket.WriteByteSeq(Source[0]);
    _worldPacket.WriteByteSeq(Source[6]);
    _worldPacket.WriteByteSeq(Target[0]);
    _worldPacket.WriteByteSeq(Target[4]);
    _worldPacket.WriteByteSeq(Source[5]);
    _worldPacket.WriteByteSeq(Target[1]);
    _worldPacket.WriteByteSeq(Target[5]);
    _worldPacket.WriteByteSeq(Target[6]);
    _worldPacket.WriteByteSeq(Target[2]);
    _worldPacket.WriteByteSeq(Source[2]);
    _worldPacket.WriteByteSeq(Target[3]);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::PlaySpellVisualKit::Write()
{
    _worldPacket << uint32(Duration);
    _worldPacket << int32(KitRecID);
    _worldPacket << int32(KitType);

    _worldPacket.WriteBit(Unit[4]);
    _worldPacket.WriteBit(Unit[7]);
    _worldPacket.WriteBit(Unit[5]);
    _worldPacket.WriteBit(Unit[3]);
    _worldPacket.WriteBit(Unit[1]);
    _worldPacket.WriteBit(Unit[2]);
    _worldPacket.WriteBit(Unit[0]);
    _worldPacket.WriteBit(Unit[6]);

    _worldPacket.WriteByteSeq(Unit[0]);
    _worldPacket.WriteByteSeq(Unit[4]);
    _worldPacket.WriteByteSeq(Unit[1]);
    _worldPacket.WriteByteSeq(Unit[6]);
    _worldPacket.WriteByteSeq(Unit[7]);
    _worldPacket.WriteByteSeq(Unit[2]);
    _worldPacket.WriteByteSeq(Unit[3]);
    _worldPacket.WriteByteSeq(Unit[5]);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::SendKnownSpells::Write()
{
    _worldPacket.reserve(1 + 2  + 6 * KnownSpells.size() + 2 + 14 * SpellHistoryEntries.size());

    _worldPacket << uint8(InitialLogin);
    _worldPacket << uint16(KnownSpells.size());

    for (uint32 SpellID : KnownSpells)
    {
        _worldPacket << uint32(SpellID);
        _worldPacket << int16(0); // Slot (unused)
    }

    _worldPacket << uint16(SpellHistoryEntries.size());
    for (SpellHistoryEntry const& entry : SpellHistoryEntries)
    {
        _worldPacket << uint32(entry.SpellID);
        _worldPacket << uint32(entry.ItemID);
        _worldPacket << uint16(entry.Category);
        _worldPacket << int32(entry.RecoveryTime);
        _worldPacket << int32(entry.CategoryRecoveryTime);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::SendUnlearnSpells::Write()
{
    _worldPacket << uint32(Spells.size());
    for (uint32 spellId : Spells)
        _worldPacket << uint32(spellId);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::UnlearnedSpells::Write()
{
    _worldPacket << uint32(SpellID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::UpdateActionButtons::Write()
{
    _worldPacket.append(ActionButtons.data(), ActionButtons.size());
    _worldPacket << Reason;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellModifierData const& spellModifierData)
{
    data << uint8(spellModifierData.ClassIndex);
    data << float(spellModifierData.ModifierValue);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellModifier const& spellModifier)
{
    data << uint32(spellModifier.ModifierData.size());
    data << uint8(spellModifier.ModIndex);
    for (WorldPackets::Spells::SpellModifierData const& modData : spellModifier.ModifierData)
        data << modData;

    return data;
}

WorldPacket const* WorldPackets::Spells::SetSpellModifier::Write()
{
    _worldPacket << uint32(Modifiers.size());
    for (WorldPackets::Spells::SpellModifier const& spellMod : Modifiers)
        _worldPacket << spellMod;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::ConvertRune::Write()
{
    _worldPacket << uint8(Index);
    _worldPacket << uint8(Rune);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::ResyncRunes::Write()
{
    _worldPacket << uint32(Runes.size());
    for (auto const& rune : Runes)
    {
        _worldPacket << uint8(rune.RuneType);
        _worldPacket << uint8(rune.Cooldown);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::AddRunePower::Write()
{
    _worldPacket << uint32(AddedRunesMask);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::SupercededSpells::Write()
{
    _worldPacket << int32(SpellID);
    _worldPacket << int32(Superceded);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::AuraPointsDepleted::Write()
{
    _worldPacket.WriteBit(Unit[2]);
    _worldPacket.WriteBit(Unit[4]);
    _worldPacket.WriteBit(Unit[1]);
    _worldPacket.WriteBit(Unit[7]);
    _worldPacket.WriteBit(Unit[5]);
    _worldPacket.WriteBit(Unit[0]);
    _worldPacket.WriteBit(Unit[3]);
    _worldPacket.WriteBit(Unit[6]);

    _worldPacket.WriteByteSeq(Unit[5]);
    _worldPacket.WriteByteSeq(Unit[0]);
    _worldPacket << uint8(EffectIndex);
    _worldPacket.WriteByteSeq(Unit[3]);
    _worldPacket.WriteByteSeq(Unit[7]);
    _worldPacket.WriteByteSeq(Unit[4]);
    _worldPacket.WriteByteSeq(Unit[2]);
    _worldPacket << uint8(Slot);
    _worldPacket.WriteByteSeq(Unit[6]);
    _worldPacket.WriteByteSeq(Unit[1]);

    return &_worldPacket;
}
