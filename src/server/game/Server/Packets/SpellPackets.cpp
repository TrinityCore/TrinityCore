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
#include "Spell.h"
#include "SpellInfo.h"

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
    _worldPacket << float(TravelSpeed);
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
    _worldPacket.WriteBit(Target[0]);

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

WorldPacket const* WorldPackets::Spells::SpellFailure::Write()
{
    _worldPacket << CasterUnit.WriteAsPacked();
    _worldPacket << uint8(CastID);
    _worldPacket << int32(SpellID);
    _worldPacket << uint8(Reason);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::SpellFailedOther::Write()
{
    _worldPacket << CasterUnit.WriteAsPacked();
    _worldPacket << uint8(CastID);
    _worldPacket << int32(SpellID);
    _worldPacket << uint8(Reason);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::ResurrectRequest::Write()
{
    _worldPacket << ResurrectOffererGUID;
    _worldPacket << uint32(Name.length() + 1);
    _worldPacket << Name; // client expects a null-terminated string
    _worldPacket << bool(Sickness);
    _worldPacket << bool(UseTimer);
    _worldPacket << int32(SpellID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::SpellDelayed::Write()
{
    _worldPacket << Caster.WriteAsPacked();
    _worldPacket << int32(ActualDelay);
    return &_worldPacket;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<WorldPackets::Spells::TargetLocation>& location)
{
    location.emplace();
    data >> location->Transport.ReadAsPacked();
    data >> location->Location.m_positionX;
    data >> location->Location.m_positionY;
    data >> location->Location.m_positionZ;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Spells::SpellTargetData& targetData)
{
    data >> targetData.Flags;

    if (targetData.Flags & (TARGET_FLAG_UNIT | TARGET_FLAG_UNIT_MINIPET | TARGET_FLAG_GAMEOBJECT | TARGET_FLAG_CORPSE_ENEMY | TARGET_FLAG_CORPSE_ALLY))
    {
        targetData.Unit.emplace();
        data >> targetData.Unit->ReadAsPacked();
    }

    if (targetData.Flags & (TARGET_FLAG_ITEM | TARGET_FLAG_TRADE_ITEM))
    {
        targetData.Item.emplace();
        data >> targetData.Item->ReadAsPacked();
    }

    if (targetData.Flags & TARGET_FLAG_SOURCE_LOCATION)
        data >> targetData.SrcLocation;

    if (targetData.Flags & TARGET_FLAG_DEST_LOCATION)
        data >> targetData.DstLocation;

    if (targetData.Flags & TARGET_FLAG_STRING)
    {
        targetData.Name.emplace();
        data >> *targetData.Name;
    }

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<MovementInfo>& movementInfo)
{
    movementInfo.emplace();
    data >> movementInfo->pos.m_positionZ;
    data >> movementInfo->pos.m_positionY;
    data >> movementInfo->pos.m_positionX;

    bool hasFallData = data.ReadBit();
    bool hasTime = !data.ReadBit();
    bool hasFacing = !data.ReadBit();

    data.ReadBit(); // HasSpline
    data.ReadBit(); // HeightChangeFailed

    movementInfo->guid[6] = data.ReadBit();
    movementInfo->guid[4] = data.ReadBit();

    bool hasExtraMovementFlags = !data.ReadBit();

    movementInfo->guid[3] = data.ReadBit();
    movementInfo->guid[5] = data.ReadBit();

    bool hasSplineElevation = !data.ReadBit();
    bool hasPitch = !data.ReadBit();

    movementInfo->guid[7] = data.ReadBit();

    bool hasTransportData = data.ReadBit();

    movementInfo->guid[2] = data.ReadBit();

    bool hasMovementFlags = !data.ReadBit();

    movementInfo->guid[1] = data.ReadBit();
    movementInfo->guid[0] = data.ReadBit();

    bool hasTransportTime2 = false;
    bool hasVehicleRecId = false;
    if (hasTransportData)
    {
        movementInfo->transport.guid[6] = data.ReadBit();
        movementInfo->transport.guid[2] = data.ReadBit();
        movementInfo->transport.guid[5] = data.ReadBit();
        hasTransportTime2 = data.ReadBit();
        movementInfo->transport.guid[7] = data.ReadBit();
        movementInfo->transport.guid[4] = data.ReadBit();
        hasVehicleRecId = data.ReadBit();
        movementInfo->transport.guid[0] = data.ReadBit();
        movementInfo->transport.guid[1] = data.ReadBit();
        movementInfo->transport.guid[3] = data.ReadBit();
    }

    if (hasExtraMovementFlags)
        movementInfo->SetExtraMovementFlags(data.ReadBits(12));

    if (hasMovementFlags)
        movementInfo->SetMovementFlags(data.ReadBits(30));

    bool hasFallDirection = false;
    if (hasFallData)
        hasFallDirection = data.ReadBit();

    data.ReadByteSeq(movementInfo->guid[1]);
    data.ReadByteSeq(movementInfo->guid[4]);
    data.ReadByteSeq(movementInfo->guid[7]);
    data.ReadByteSeq(movementInfo->guid[3]);
    data.ReadByteSeq(movementInfo->guid[0]);
    data.ReadByteSeq(movementInfo->guid[2]);
    data.ReadByteSeq(movementInfo->guid[5]);
    data.ReadByteSeq(movementInfo->guid[6]);

    if (hasTransportData)
    {
        data >> movementInfo->transport.seat;
        movementInfo->transport.pos.SetOrientation(data.read<float>());
        data >> movementInfo->transport.time;

        data.ReadByteSeq(movementInfo->transport.guid[6]);
        data.ReadByteSeq(movementInfo->transport.guid[5]);

        if (hasTransportTime2)
            data >> movementInfo->transport.time2;

        data >> movementInfo->transport.pos.m_positionX;

        data.ReadByteSeq(movementInfo->transport.guid[4]);

        data >> movementInfo->transport.pos.m_positionZ;

        data.ReadByteSeq(movementInfo->transport.guid[2]);
        data.ReadByteSeq(movementInfo->transport.guid[0]);

        if (hasVehicleRecId)
            data >> movementInfo->transport.vehicleId;

        data.ReadByteSeq(movementInfo->transport.guid[1]);
        data.ReadByteSeq(movementInfo->transport.guid[3]);

        data >> movementInfo->transport.pos.m_positionY;

        data.ReadByteSeq(movementInfo->transport.guid[7]);
    }

    if (hasFacing)
        movementInfo->pos.SetOrientation(data.read<float>());

    if (hasSplineElevation)
        data >> movementInfo->splineElevation;

    if (hasFallData)
    {
        data >> movementInfo->jump.fallTime;
        if (hasFallDirection)
        {
            data >> movementInfo->jump.sinAngle;
            data >> movementInfo->jump.cosAngle;
            data >> movementInfo->jump.xyspeed;
        }
        data >> movementInfo->jump.zspeed;
    }

    if (hasTime)
        data >> movementInfo->time;

    if (hasPitch)
        data >> movementInfo->pitch;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Spells::MissileTrajectoryRequest& missileTrajectory)
{
    data >> missileTrajectory.Pitch;
    data >> missileTrajectory.Speed;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Spells::SpellCastRequest& castRequest)
{
    data >> castRequest.CastID;
    data >> castRequest.SpellID;
    data >> castRequest.Misc;
    data >> castRequest.SendCastFlags;
    data >> castRequest.Target;

    if (castRequest.SendCastFlags & CAST_FLAG_HAS_TRAJECTORY)
    {
        data >> castRequest.MissileTrajectory;
        bool hasMovementData = data.read<bool>();
        if (hasMovementData)
            data >> castRequest.MoveUpdate;
    }

    if (castRequest.SendCastFlags & CAST_FLAG_HAS_WEIGHT)
    {
        uint32 weightCount = data.read<uint32>();
        castRequest.Weight.resize(weightCount);

        for (WorldPackets::Spells::SpellWeight& weight : castRequest.Weight)
        {
            data >> weight.Type;
            data >> weight.ID;
            data >> weight.Quantity;
        }
    }

    return data;
}

void WorldPackets::Spells::CastSpell::Read()
{
    _worldPacket >> Cast;
}

void WorldPackets::Spells::UseItem::Read()
{
    _worldPacket >> PackSlot;
    _worldPacket >> Slot;
    _worldPacket >> Cast.CastID;
    _worldPacket >> Cast.SpellID;
    _worldPacket >> CastItem;
    _worldPacket >> Cast.Misc;
    _worldPacket >> Cast.SendCastFlags;
    _worldPacket >> Cast.Target;

    if (Cast.SendCastFlags & CAST_FLAG_HAS_TRAJECTORY)
    {
        _worldPacket >> Cast.MissileTrajectory;
        bool hasMovementData = _worldPacket.read<bool>();
        if (hasMovementData)
            _worldPacket >> Cast.MoveUpdate;
    }

    if (Cast.SendCastFlags & CAST_FLAG_HAS_WEIGHT)
    {
        uint32 weightCount = _worldPacket.read<uint32>();
        Cast.Weight.resize(weightCount);

        for (WorldPackets::Spells::SpellWeight& weight : Cast.Weight)
        {
            _worldPacket >> weight.Type;
            _worldPacket >> weight.ID;
            _worldPacket >> weight.Quantity;
        }
    }
}

void WorldPackets::Spells::UpdateMissileTrajectory::Read()
{
    _worldPacket >> FirePos.Pos.m_positionZ;
    _worldPacket >> FirePos.Pos.m_positionX;
    _worldPacket >> Pitch;
    _worldPacket >> ImpactPos.Pos.m_positionX;
    _worldPacket >> FirePos.Pos.m_positionY;
    _worldPacket >> Speed;
    _worldPacket >> ImpactPos.Pos.m_positionY;
    _worldPacket >> MoveMsgID;
    _worldPacket >> SpellID;
    _worldPacket >> ImpactPos.Pos.m_positionZ;

    Guid[5] = _worldPacket.ReadBit();
    Guid[6] = _worldPacket.ReadBit();
    Guid[0] = _worldPacket.ReadBit();
    Guid[7] = _worldPacket.ReadBit();
    Guid[1] = _worldPacket.ReadBit();
    Guid[3] = _worldPacket.ReadBit();
    Guid[2] = _worldPacket.ReadBit();
    Guid[4] = _worldPacket.ReadBit();

    bool hasFallData = false;
    bool hasFallVelocity = false;
    bool hasFacing = false;
    bool hasTransportData = false;
    bool hasTransportTime2 = false;
    bool hasVehicleId = false;
    bool hasSplineElevation = false;
    bool hasPitch = false;
    bool hasMoveTime = false;

    // Thanks to Cataclysm's randomized packet structures we now have to read the packet like this instead of using the MovementStructures helper
    if (_worldPacket.ReadBit())
    {
        Status.emplace();

        Status->guid[2] = _worldPacket.ReadBit();
        Status->heightChangeFailed = _worldPacket.ReadBit();
        bool hasMovementFlags0 = !_worldPacket.ReadBit();
        _worldPacket.ReadBit(); // hasSpline
        Status->guid[4] = _worldPacket.ReadBit();

        if (hasMovementFlags0)
            Status->SetMovementFlags(_worldPacket.ReadBits(30));

        Status->guid[3] = _worldPacket.ReadBit();
        hasPitch = _worldPacket.ReadBit();
        bool hasMovementFlags1 = _worldPacket.ReadBit();
        hasTransportData = _worldPacket.ReadBit();
        Status->guid[7] = _worldPacket.ReadBit();

        if (hasTransportData)
        {
            Status->transport.guid[0] = _worldPacket.ReadBit();
            Status->transport.guid[7] = _worldPacket.ReadBit();
            Status->transport.guid[2] = _worldPacket.ReadBit();
            Status->transport.guid[4] = _worldPacket.ReadBit();
            hasVehicleId = _worldPacket.ReadBit();
            Status->transport.guid[5] = _worldPacket.ReadBit();
            Status->transport.guid[3] = _worldPacket.ReadBit();
            Status->transport.guid[6] = _worldPacket.ReadBit();
            hasTransportTime2 = _worldPacket.ReadBit();
            Status->transport.guid[1] = _worldPacket.ReadBit();
        }

        Status->guid[6] = _worldPacket.ReadBit();
        hasFacing = !_worldPacket.ReadBit();
        hasMoveTime = !_worldPacket.ReadBit();
        Status->guid[5] = _worldPacket.ReadBit();
        hasSplineElevation = !_worldPacket.ReadBit();
        Status->guid[1] = _worldPacket.ReadBit();
        hasFallData = _worldPacket.ReadBit();
        Status->guid[0] = _worldPacket.ReadBit();

        if (hasFallData)
            hasFallVelocity = _worldPacket.ReadBit();

        if (hasMovementFlags1)
            Status->SetExtraMovementFlags(_worldPacket.ReadBits(12));
    }

    _worldPacket.ReadByteSeq(Guid[2]);
    _worldPacket.ReadByteSeq(Guid[1]);
    _worldPacket.ReadByteSeq(Guid[3]);
    _worldPacket.ReadByteSeq(Guid[7]);
    _worldPacket.ReadByteSeq(Guid[6]);
    _worldPacket.ReadByteSeq(Guid[4]);
    _worldPacket.ReadByteSeq(Guid[0]);
    _worldPacket.ReadByteSeq(Guid[5]);

    if (Status.has_value())
    {
        if (hasFallData)
        {
            if (hasFallVelocity)
            {
                _worldPacket >> Status->jump.cosAngle;
                _worldPacket >> Status->jump.sinAngle;
                _worldPacket >> Status->jump.xyspeed;
            }

            _worldPacket >> Status->jump.zspeed;
            _worldPacket >> Status->jump.fallTime;
        }

        if (hasFacing)
            Status->pos.SetOrientation(_worldPacket.read<float>());

        if (hasTransportData)
        {
            _worldPacket >> Status->transport.pos.m_positionZ;
            _worldPacket.ReadByteSeq(Status->transport.guid[3]);
            _worldPacket.ReadByteSeq(Status->transport.guid[7]);
            _worldPacket >> Status->transport.pos.m_positionX;
            Status->transport.pos.SetOrientation(_worldPacket.read<float>());

            if (hasTransportTime2)
                _worldPacket >> Status->transport.time2;

            _worldPacket.ReadByteSeq(Status->transport.guid[2]);
            _worldPacket >> Status->transport.time;
            _worldPacket.ReadByteSeq(Status->transport.guid[0]);
            _worldPacket >> Status->transport.pos.m_positionY;

            if (hasVehicleId)
                _worldPacket >> Status->transport.vehicleId;

            _worldPacket.ReadByteSeq(Status->transport.guid[4]);
            _worldPacket.ReadByteSeq(Status->transport.guid[6]);
            _worldPacket.ReadByteSeq(Status->transport.guid[1]);
            _worldPacket >> Status->transport.seat;
            _worldPacket.ReadByteSeq(Status->transport.guid[5]);
        }

        if (hasSplineElevation)
            _worldPacket >> Status->splineElevation;

        _worldPacket.ReadByteSeq(Status->guid[4]);

        if (hasPitch)
            _worldPacket >> Status->pitch;

        _worldPacket.ReadByteSeq(Status->guid[7]);
        _worldPacket.ReadByteSeq(Status->guid[2]);

        if (hasMoveTime)
            _worldPacket >> Status->time;

        _worldPacket >> Status->pos.m_positionX;
        _worldPacket.ReadByteSeq(Status->guid[5]);
        _worldPacket.ReadByteSeq(Status->guid[3]);
        _worldPacket.ReadByteSeq(Status->guid[1]);
        _worldPacket.ReadByteSeq(Status->guid[0]);
        _worldPacket >> Status->pos.m_positionY;
        _worldPacket >> Status->pos.m_positionZ;
        _worldPacket.ReadByteSeq(Status->guid[6]);
    }
}

WorldPacket const* WorldPackets::Spells::ClearCooldown::Write()
{
    _worldPacket << int32(SpellID);
    _worldPacket << CasterGUID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::ClearCooldowns::Write()
{
    _worldPacket.WriteBit(Guid[1]);
    _worldPacket.WriteBit(Guid[3]);
    _worldPacket.WriteBit(Guid[6]);
    _worldPacket.WriteBits(SpellID.size(), 24);
    _worldPacket.WriteBit(Guid[7]);
    _worldPacket.WriteBit(Guid[5]);
    _worldPacket.WriteBit(Guid[2]);
    _worldPacket.WriteBit(Guid[4]);
    _worldPacket.WriteBit(Guid[0]);

    _worldPacket.WriteByteSeq(Guid[7]);
    _worldPacket.WriteByteSeq(Guid[2]);
    _worldPacket.WriteByteSeq(Guid[4]);
    _worldPacket.WriteByteSeq(Guid[5]);
    _worldPacket.WriteByteSeq(Guid[1]);
    _worldPacket.WriteByteSeq(Guid[3]);

    if (!SpellID.empty())
        _worldPacket.append(SpellID.data(), SpellID.size());

    _worldPacket.WriteByteSeq(Guid[0]);
    _worldPacket.WriteByteSeq(Guid[6]);

    return &_worldPacket;
}
