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

#include "MovementPackets.h"
#include "SpellPackets.h"

void WorldPackets::Spells::CancelAura::Read()
{
    _worldPacket >> SpellID;
    _worldPacket >> CasterGUID;
}

void WorldPackets::Spells::PetCancelAura::Read()
{
    _worldPacket >> PetGUID;
    _worldPacket >> SpellID;
}

void WorldPackets::Spells::CancelChannelling::Read()
{
    _worldPacket >> ChannelSpell;
    _worldPacket >> Reason;
}

WorldPacket const* WorldPackets::Spells::CategoryCooldown::Write()
{
    _worldPacket.reserve(4 + 8 * CategoryCooldowns.size());

    _worldPacket << uint32(CategoryCooldowns.size());

    for (CategoryCooldownInfo const& cooldown : CategoryCooldowns)
    {
        _worldPacket << uint32(cooldown.Category);
        _worldPacket << int32(cooldown.ModCooldown);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::SendKnownSpells::Write()
{
    _worldPacket.reserve(1 + 4 * KnownSpells.size() + 4 * FavoriteSpells.size());

    _worldPacket.WriteBit(InitialLogin);
    _worldPacket << uint32(KnownSpells.size());
    _worldPacket << uint32(FavoriteSpells.size());

    for (uint32 spellId : KnownSpells)
        _worldPacket << uint32(spellId);

    for (uint32 spellId : FavoriteSpells)
        _worldPacket << uint32(spellId);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::UpdateActionButtons::Write()
{
    _worldPacket.append(ActionButtons.data(), ActionButtons.size());
    _worldPacket << Reason;

    return &_worldPacket;
}

void WorldPackets::Spells::SetActionButton::Read()
{
    _worldPacket >> Action;
    _worldPacket >> Index;
}

WorldPacket const* WorldPackets::Spells::SendUnlearnSpells::Write()
{
    _worldPacket << uint32(Spells.size());
    for (uint32 spellId : Spells)
        _worldPacket << uint32(spellId);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::AuraDataInfo const& auraData)
{
    data << auraData.CastID;
    data << int32(auraData.SpellID);
    data << auraData.Visual;
    data << uint16(auraData.Flags);
    data << uint32(auraData.ActiveFlags);
    data << uint16(auraData.CastLevel);
    data << uint8(auraData.Applications);
    data << int32(auraData.ContentTuningID);
    data.WriteBit(auraData.CastUnit.is_initialized());
    data.WriteBit(auraData.Duration.is_initialized());
    data.WriteBit(auraData.Remaining.is_initialized());
    data.WriteBit(auraData.TimeMod.is_initialized());
    data.WriteBits(auraData.Points.size(), 6);
    data.WriteBits(auraData.EstimatedPoints.size(), 6);
    data.WriteBit(auraData.ContentTuning.is_initialized());

    if (auraData.ContentTuning)
        data << *auraData.ContentTuning;

    if (auraData.CastUnit)
        data << *auraData.CastUnit;

    if (auraData.Duration)
        data << uint32(*auraData.Duration);

    if (auraData.Remaining)
        data << uint32(*auraData.Remaining);

    if (auraData.TimeMod)
        data << float(*auraData.TimeMod);

    if (!auraData.Points.empty())
        data.append(auraData.Points.data(), auraData.Points.size());

    if (!auraData.EstimatedPoints.empty())
        data.append(auraData.EstimatedPoints.data(), auraData.EstimatedPoints.size());

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::AuraInfo const& aura)
{
    data << aura.Slot;
    data.WriteBit(aura.AuraData.is_initialized());
    data.FlushBits();

    if (aura.AuraData)
        data << *aura.AuraData;

    return data;
}

WorldPacket const* WorldPackets::Spells::AuraUpdate::Write()
{
    _worldPacket.WriteBit(UpdateAll);
    _worldPacket.WriteBits(Auras.size(), 9);
    for (AuraInfo const& aura : Auras)
        _worldPacket << aura;

    _worldPacket << UnitGUID;

    return &_worldPacket;
}

ByteBuffer& operator>>(ByteBuffer& buffer, Optional<WorldPackets::Spells::TargetLocation>& location)
{
    location = boost::in_place();
    buffer >> location->Transport;
    buffer >> location->Location.m_positionX;
    buffer >> location->Location.m_positionY;
    buffer >> location->Location.m_positionZ;
    return buffer;
}

ByteBuffer& operator>>(ByteBuffer& buffer, WorldPackets::Spells::SpellTargetData& targetData)
{
    buffer.ResetBitPos();

    targetData.Flags = buffer.ReadBits(26);
    bool hasSrcLocation = buffer.ReadBit();
    bool hasDstLocation = buffer.ReadBit();
    bool hasOrientation = buffer.ReadBit();
    bool hasMapID = buffer.ReadBit();
    uint32 nameLength = buffer.ReadBits(7);

    buffer >> targetData.Unit;
    buffer >> targetData.Item;

    if (hasSrcLocation)
        buffer >> targetData.SrcLocation;

    if (hasDstLocation)
        buffer >> targetData.DstLocation;

    if (hasOrientation)
        targetData.Orientation = buffer.read<float>();

    if (hasMapID)
        targetData.MapID = buffer.read<int32>();

    targetData.Name = buffer.ReadString(nameLength);

    return buffer;
}

ByteBuffer& operator>>(ByteBuffer& buffer, WorldPackets::Spells::MissileTrajectoryRequest& trajectory)
{
    buffer >> trajectory.Pitch;
    buffer >> trajectory.Speed;
    return buffer;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Spells::SpellOptionalReagent& optionalReagent)
{
    data >> optionalReagent.ItemID;
    data >> optionalReagent.Slot;
    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Spells::SpellExtraCurrencyCost& extraCurrencyCost)
{
    data >> extraCurrencyCost.CurrencyID;
    data >> extraCurrencyCost.Count;
    return data;
}

ByteBuffer& operator>>(ByteBuffer& buffer, WorldPackets::Spells::SpellCastRequest& request)
{
    buffer >> request.CastID;
    buffer >> request.Misc[0];
    buffer >> request.Misc[1];
    buffer >> request.SpellID;
    buffer >> request.Visual;
    buffer >> request.MissileTrajectory;
    buffer >> request.CraftingNPC;
    request.OptionalReagents.resize(buffer.read<uint32>());
    request.OptionalCurrencies.resize(buffer.read<uint32>());

    for (WorldPackets::Spells::SpellOptionalReagent& optionalReagent : request.OptionalReagents)
        buffer >> optionalReagent;

    for (WorldPackets::Spells::SpellExtraCurrencyCost& optionalCurrency : request.OptionalCurrencies)
        buffer >> optionalCurrency;

    request.SendCastFlags = buffer.ReadBits(5);
    bool hasMoveUpdate = buffer.ReadBit();
    request.Weight.resize(buffer.ReadBits(2));
    buffer >> request.Target;

    if (hasMoveUpdate)
    {
        request.MoveUpdate = boost::in_place();
        buffer >> *request.MoveUpdate;
    }

    for (WorldPackets::Spells::SpellWeight& weight : request.Weight)
    {
        buffer.ResetBitPos();
        weight.Type = buffer.ReadBits(2);
        buffer >> weight.ID;
        buffer >> weight.Quantity;
    }

    return buffer;
}

void WorldPackets::Spells::CastSpell::Read()
{
    _worldPacket >> Cast;
}

void WorldPackets::Spells::PetCastSpell::Read()
{
    _worldPacket >> PetGUID;
    _worldPacket >> Cast;
}

void WorldPackets::Spells::UseItem::Read()
{
    _worldPacket >> PackSlot;
    _worldPacket >> Slot;
    _worldPacket >> CastItem;
    _worldPacket >> Cast;
}

WorldPacket const* WorldPackets::Spells::SpellPrepare::Write()
{
    _worldPacket << ClientCastID;
    _worldPacket << ServerCastID;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::TargetLocation const& targetLocation)
{
    data << targetLocation.Transport;
    data << float(targetLocation.Location.m_positionX);
    data << float(targetLocation.Location.m_positionY);
    data << float(targetLocation.Location.m_positionZ);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellTargetData const& spellTargetData)
{
    data.WriteBits(spellTargetData.Flags, 26);
    data.WriteBit(spellTargetData.SrcLocation.is_initialized());
    data.WriteBit(spellTargetData.DstLocation.is_initialized());
    data.WriteBit(spellTargetData.Orientation.is_initialized());
    data.WriteBit(spellTargetData.MapID.is_initialized());
    data.WriteBits(spellTargetData.Name.size(), 7);
    data.FlushBits();

    data << spellTargetData.Unit;
    data << spellTargetData.Item;

    if (spellTargetData.SrcLocation)
        data << *spellTargetData.SrcLocation;

    if (spellTargetData.DstLocation)
        data << *spellTargetData.DstLocation;

    if (spellTargetData.Orientation)
        data << *spellTargetData.Orientation;

    if (spellTargetData.MapID)
        data << *spellTargetData.MapID;

    data.WriteString(spellTargetData.Name);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellMissStatus const& spellMissStatus)
{
    data.WriteBits(spellMissStatus.Reason, 4);
    if (spellMissStatus.Reason == SPELL_MISS_REFLECT)
        data.WriteBits(spellMissStatus.ReflectStatus, 4);

    data.FlushBits();
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellHitStatus const& spellHitStatus)
{
    data << uint8(spellHitStatus.Reason);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellPowerData const& spellPowerData)
{
    data << int32(spellPowerData.Cost);
    data << int8(spellPowerData.Type);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::RuneData const& runeData)
{
    data << uint8(runeData.Start);
    data << uint8(runeData.Count);
    data << uint32(runeData.Cooldowns.size());
    if (!runeData.Cooldowns.empty())
        data.append(runeData.Cooldowns.data(), runeData.Cooldowns.size());

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::MissileTrajectoryResult const& missileTrajectory)
{
    data << uint32(missileTrajectory.TravelTime);
    data << float(missileTrajectory.Pitch);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellAmmo const& spellAmmo)
{
    data << int32(spellAmmo.DisplayID);
    data << int8(spellAmmo.InventoryType);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::CreatureImmunities const& immunities)
{
    data << int32(immunities.School);
    data << int32(immunities.Value);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellHealPrediction const& spellPred)
{
    data << int32(spellPred.Points);
    data << uint8(spellPred.Type);
    data << spellPred.BeaconGUID;
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellCastData const& spellCastData)
{
    data << spellCastData.CasterGUID;
    data << spellCastData.CasterUnit;
    data << spellCastData.CastID;
    data << spellCastData.OriginalCastID;
    data << int32(spellCastData.SpellID);
    data << spellCastData.Visual;
    data << uint32(spellCastData.CastFlags);
    data << uint32(spellCastData.CastFlagsEx);
    data << uint32(spellCastData.CastTime);
    data << spellCastData.MissileTrajectory;
    data << int32(spellCastData.Ammo.DisplayID);
    data << uint8(spellCastData.DestLocSpellCastIndex);
    data << spellCastData.Immunities;
    data << spellCastData.Predict;
    data.WriteBits(spellCastData.HitTargets.size(), 16);
    data.WriteBits(spellCastData.MissTargets.size(), 16);
    data.WriteBits(spellCastData.HitStatus.size(), 16);
    data.WriteBits(spellCastData.MissStatus.size(), 16);
    data.WriteBits(spellCastData.RemainingPower.size(), 9);
    data.WriteBit(spellCastData.RemainingRunes.is_initialized());
    data.WriteBits(spellCastData.TargetPoints.size(), 16);
    data.FlushBits();

    for (WorldPackets::Spells::SpellMissStatus const& missStatus : spellCastData.MissStatus)
        data << missStatus;

    data << spellCastData.Target;

    for (ObjectGuid const& hitTarget : spellCastData.HitTargets)
        data << hitTarget;

    for (ObjectGuid const& missTarget : spellCastData.MissTargets)
        data << missTarget;

    for (WorldPackets::Spells::SpellHitStatus const& hitStatus : spellCastData.HitStatus)
        data << hitStatus;

    for (WorldPackets::Spells::SpellPowerData const& power : spellCastData.RemainingPower)
        data << power;

    if (spellCastData.RemainingRunes)
        data << *spellCastData.RemainingRunes;

    for (WorldPackets::Spells::TargetLocation const& targetLoc : spellCastData.TargetPoints)
        data << targetLoc;

    return data;
}

WorldPacket const* WorldPackets::Spells::SpellStart::Write()
{
    _worldPacket << Cast;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::SpellGo::Write()
{
    *this << Cast;

    WriteLogDataBit();
    FlushBits();

    WriteLogData();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::LearnedSpells::Write()
{
    _worldPacket << uint32(SpellID.size());
    _worldPacket << uint32(FavoriteSpellID.size());
    _worldPacket << uint32(SpecializationID);
    for (int32 spell : SpellID)
        _worldPacket << spell;

    for (int32 spell : FavoriteSpellID)
        _worldPacket << spell;

    _worldPacket.WriteBit(SuppressMessaging);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::SupercededSpells::Write()
{
    _worldPacket << uint32(SpellID.size());
    _worldPacket << uint32(Superceded.size());
    _worldPacket << uint32(FavoriteSpellID.size());

    if (!SpellID.empty())
        _worldPacket.append(SpellID.data(), SpellID.size());

    if (!Superceded.empty())
        _worldPacket.append(Superceded.data(), Superceded.size());

    if (!FavoriteSpellID.empty())
        _worldPacket.append(FavoriteSpellID.data(), FavoriteSpellID.size());

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::SpellFailure::Write()
{
    _worldPacket << CasterUnit;
    _worldPacket << CastID;
    _worldPacket << int32(SpellID);
    _worldPacket << Visual;
    _worldPacket << uint16(Reason);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::SpellFailedOther::Write()
{
    _worldPacket << CasterUnit;
    _worldPacket << CastID;
    _worldPacket << uint32(SpellID);
    _worldPacket << Visual;
    _worldPacket << uint8(Reason);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::CastFailed::Write()
{
    _worldPacket << CastID;
    _worldPacket << int32(SpellID);
    _worldPacket << Visual;
    _worldPacket << int32(Reason);
    _worldPacket << int32(FailedArg1);
    _worldPacket << int32(FailedArg2);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::PetCastFailed::Write()
{
    _worldPacket << CastID;
    _worldPacket << int32(SpellID);
    _worldPacket << int32(Reason);
    _worldPacket << int32(FailedArg1);
    _worldPacket << int32(FailedArg2);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellModifierData const& spellModifierData)
{
    data << float(spellModifierData.ModifierValue);
    data << uint8(spellModifierData.ClassIndex);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellModifier const& spellModifier)
{
    data << uint8(spellModifier.ModIndex);
    data << uint32(spellModifier.ModifierData.size());
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

WorldPacket const* WorldPackets::Spells::UnlearnedSpells::Write()
{
    _worldPacket << uint32(SpellID.size());
    for (uint32 spellId : SpellID)
        _worldPacket << uint32(spellId);

    _worldPacket.WriteBit(SuppressMessaging);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::CooldownEvent::Write()
{
    _worldPacket << int32(SpellID);
    _worldPacket.WriteBit(IsPet);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::ClearCooldowns::Write()
{
    _worldPacket << uint32(SpellID.size());
    if (!SpellID.empty())
        _worldPacket.append(SpellID.data(), SpellID.size());

    _worldPacket.WriteBit(IsPet);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::ClearCooldown::Write()
{
    _worldPacket << uint32(SpellID);
    _worldPacket.WriteBit(ClearOnHold);
    _worldPacket.WriteBit(IsPet);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::ModifyCooldown::Write()
{
    _worldPacket << int32(SpellID);
    _worldPacket << int32(DeltaTime);
    _worldPacket.WriteBit(IsPet);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellCooldownStruct const& cooldown)
{
    data << uint32(cooldown.SrecID);
    data << uint32(cooldown.ForcedCooldown);
    data << float(cooldown.ModRate);
    return data;
}

WorldPacket const* WorldPackets::Spells::SpellCooldown::Write()
{
    _worldPacket << Caster;
    _worldPacket << uint8(Flags);
    _worldPacket << uint32(SpellCooldowns.size());
    for (SpellCooldownStruct const& cooldown : SpellCooldowns)
        _worldPacket << cooldown;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellHistoryEntry const& historyEntry)
{
    data << uint32(historyEntry.SpellID);
    data << uint32(historyEntry.ItemID);
    data << uint32(historyEntry.Category);
    data << int32(historyEntry.RecoveryTime);
    data << int32(historyEntry.CategoryRecoveryTime);
    data << float(historyEntry.ModRate);
    data.WriteBit(historyEntry.unused622_1.is_initialized());
    data.WriteBit(historyEntry.unused622_2.is_initialized());
    data.WriteBit(historyEntry.OnHold);
    if (historyEntry.unused622_1)
        data << uint32(*historyEntry.unused622_1);
    if (historyEntry.unused622_2)
        data << uint32(*historyEntry.unused622_2);
    data.FlushBits();

    return data;
}

WorldPacket const* WorldPackets::Spells::SendSpellHistory::Write()
{
    _worldPacket << uint32(Entries.size());
    for (SpellHistoryEntry const& historyEntry : Entries)
        _worldPacket << historyEntry;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::ClearAllSpellCharges::Write()
{
    _worldPacket.WriteBit(IsPet);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::ClearSpellCharges::Write()
{
    _worldPacket << int32(Category);
    _worldPacket.WriteBit(IsPet);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::SetSpellCharges::Write()
{
    _worldPacket << int32(Category);
    _worldPacket << uint32(NextRecoveryTime);
    _worldPacket << uint8(ConsumedCharges);
    _worldPacket << float(ChargeModRate);
    _worldPacket.WriteBit(IsPet);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellChargeEntry const& chargeEntry)
{
    data << uint32(chargeEntry.Category);
    data << uint32(chargeEntry.NextRecoveryTime);
    data << float(chargeEntry.ChargeModRate);
    data << uint8(chargeEntry.ConsumedCharges);
    return data;
}

WorldPacket const* WorldPackets::Spells::SendSpellCharges::Write()
{
    _worldPacket << uint32(Entries.size());
    for (SpellChargeEntry const& chargeEntry : Entries)
        _worldPacket << chargeEntry;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::ClearTarget::Write()
{
    _worldPacket << Guid;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::CancelOrphanSpellVisual::Write()
{
    _worldPacket << int32(SpellVisualID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::CancelSpellVisual::Write()
{
    _worldPacket << Source;
    _worldPacket << int32(SpellVisualID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::CancelSpellVisualKit::Write()
{
    _worldPacket << Source;
    _worldPacket << int32(SpellVisualKitID);
    _worldPacket.WriteBit(MountedVisual);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::PlayOrphanSpellVisual::Write()
{
    _worldPacket << SourceLocation;
    _worldPacket << SourceRotation;
    _worldPacket << TargetLocation;
    _worldPacket << Target;
    _worldPacket << int32(SpellVisualID);
    _worldPacket << float(TravelSpeed);
    _worldPacket << float(LaunchDelay);
    _worldPacket << float(MinDuration);
    _worldPacket.WriteBit(SpeedAsTime);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::PlaySpellVisual::Write()
{
    _worldPacket << Source;
    _worldPacket << Target;
    _worldPacket << Transport;
    _worldPacket << TargetPosition;
    _worldPacket << uint32(SpellVisualID);
    _worldPacket << float(TravelSpeed);
    _worldPacket << uint16(HitReason);
    _worldPacket << uint16(MissReason);
    _worldPacket << uint16(ReflectStatus);
    _worldPacket << float(LaunchDelay);
    _worldPacket << float(MinDuration);
    _worldPacket.WriteBit(SpeedAsTime);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::PlaySpellVisualKit::Write()
{
    _worldPacket << Unit;
    _worldPacket << int32(KitRecID);
    _worldPacket << int32(KitType);
    _worldPacket << uint32(Duration);
    _worldPacket.WriteBit(MountedVisual);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Spells::CancelCast::Read()
{
    _worldPacket >> CastID;
    _worldPacket >> SpellID;
}

void WorldPackets::Spells::OpenItem::Read()
{
    _worldPacket >> Slot
                 >> PackSlot;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellChannelStartInterruptImmunities const& interruptImmunities)
{
    data << int32(interruptImmunities.SchoolImmunities);
    data << int32(interruptImmunities.Immunities);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellTargetedHealPrediction const& targetedHealPrediction)
{
    data << targetedHealPrediction.TargetGUID;
    data << targetedHealPrediction.Predict;
    return data;
}

WorldPacket const* WorldPackets::Spells::SpellChannelStart::Write()
{
    _worldPacket << CasterGUID;
    _worldPacket << int32(SpellID);
    _worldPacket << Visual;
    _worldPacket << uint32(ChannelDuration);
    _worldPacket.WriteBit(InterruptImmunities.is_initialized());
    _worldPacket.WriteBit(HealPrediction.is_initialized());
    _worldPacket.FlushBits();

    if (InterruptImmunities)
        _worldPacket << *InterruptImmunities;

    if (HealPrediction)
        _worldPacket << *HealPrediction;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::SpellChannelUpdate::Write()
{
    _worldPacket << CasterGUID;
    _worldPacket << int32(TimeRemaining);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::ResurrectRequest::Write()
{
    _worldPacket << ResurrectOffererGUID;
    _worldPacket << uint32(ResurrectOffererVirtualRealmAddress);
    _worldPacket << uint32(PetNumber);
    _worldPacket << int32(SpellID);
    _worldPacket.WriteBits(Name.length(), 11);
    _worldPacket.WriteBit(UseTimer);
    _worldPacket.WriteBit(Sickness);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(Name);

    return &_worldPacket;
}

void WorldPackets::Spells::UnlearnSkill::Read()
{
    _worldPacket >> SkillLine;
}

void WorldPackets::Spells::SelfRes::Read()
{
    _worldPacket >> SpellID;
}

void WorldPackets::Spells::GetMirrorImageData::Read()
{
    _worldPacket >> UnitGUID;
    _worldPacket >> DisplayID;
}

WorldPacket const* WorldPackets::Spells::MirrorImageComponentedData::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << int32(DisplayID);
    _worldPacket << int32(SpellVisualKitID);
    _worldPacket << uint8(RaceID);
    _worldPacket << uint8(Gender);
    _worldPacket << uint8(ClassID);
    _worldPacket << uint32(Customizations.size());
    _worldPacket << GuildGUID;
    _worldPacket << uint32(ItemDisplayID.size());

    for (Character::ChrCustomizationChoice const& customization : Customizations)
        _worldPacket << customization;

    for (int32 itemDisplayId : ItemDisplayID)
        _worldPacket << int32(itemDisplayId);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::MirrorImageCreatureData::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << int32(DisplayID);
    _worldPacket << int32(SpellVisualKitID);

    return &_worldPacket;
}

void WorldPackets::Spells::SpellClick::Read()
{
    _worldPacket >> SpellClickUnitGuid;
    TryAutoDismount = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::Spells::ResyncRunes::Write()
{
    _worldPacket << Runes;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::AddRunePower::Write()
{
    _worldPacket << uint32(AddedRunesMask);

    return &_worldPacket;
}

void WorldPackets::Spells::MissileTrajectoryCollision::Read()
{
    _worldPacket >> Target;
    _worldPacket >> SpellID;
    _worldPacket >> CastID;
    _worldPacket >> CollisionPos;
}

WorldPacket const* WorldPackets::Spells::NotifyMissileTrajectoryCollision::Write()
{
    _worldPacket << Caster;
    _worldPacket << CastID;
    _worldPacket << CollisionPos;

    return &_worldPacket;
}

void WorldPackets::Spells::UpdateMissileTrajectory::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> MoveMsgID;
    _worldPacket >> SpellID;
    _worldPacket >> Pitch;
    _worldPacket >> Speed;
    _worldPacket >> FirePos;
    _worldPacket >> ImpactPos;
    bool hasStatus = _worldPacket.ReadBit();

    _worldPacket.ResetBitPos();
    if (hasStatus)
    {
        Status = boost::in_place();
        _worldPacket >> *Status;
    }
}

WorldPacket const* WorldPackets::Spells::SpellDelayed::Write()
{
    _worldPacket << Caster;
    _worldPacket << uint32(ActualDelay);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::DispelFailed::Write()
{
    _worldPacket << CasterGUID;
    _worldPacket << VictimGUID;
    _worldPacket << uint32(SpellID);
    _worldPacket << uint32(FailedSpells.size());
    if (!FailedSpells.empty())
        _worldPacket.append(FailedSpells.data(), FailedSpells.size());

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::CustomLoadScreen::Write()
{
    _worldPacket << uint32(TeleportSpellID);
    _worldPacket << uint32(LoadingScreenID);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::MountResult::Write()
{
    _worldPacket << int32(Result);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::MissileCancel::Write()
{
    _worldPacket << OwnerGUID;
    _worldPacket << int32(SpellID);
    _worldPacket.WriteBit(Reverse);
    _worldPacket.FlushBits();

    return &_worldPacket;
}
