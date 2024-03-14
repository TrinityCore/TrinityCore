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
#include "CharacterPackets.h"
#include "SpellPackets.h"

namespace WorldPackets::Spells
{
void CancelAura::Read()
{
    _worldPacket >> SpellID;
    _worldPacket >> CasterGUID;
}

void CancelChannelling::Read()
{
    _worldPacket >> ChannelSpell;
    _worldPacket >> Reason;
}

void CancelModSpeedNoControlAuras::Read()
{
    _worldPacket >> TargetGUID;
}

void PetCancelAura::Read()
{
    _worldPacket >> PetGUID;
    _worldPacket >> SpellID;
}

WorldPacket const* SendKnownSpells::Write()
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

WorldPacket const* UpdateActionButtons::Write()
{
    _worldPacket.append(ActionButtons.data(), ActionButtons.size());
    _worldPacket << Reason;

    return &_worldPacket;
}

void SetActionButton::Read()
{
    _worldPacket >> Action;
    _worldPacket >> Index;
}

WorldPacket const* SendUnlearnSpells::Write()
{
    _worldPacket << uint32(Spells.size());
    for (uint32 spellId : Spells)
        _worldPacket << uint32(spellId);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, AuraDataInfo const& auraData)
{
    data << auraData.CastID;
    data << int32(auraData.SpellID);
    data << auraData.Visual;
    data << uint16(auraData.Flags);
    data << uint32(auraData.ActiveFlags);
    data << uint16(auraData.CastLevel);
    data << uint8(auraData.Applications);
    data << int32(auraData.ContentTuningID);
    data.WriteBit(auraData.CastUnit.has_value());
    data.WriteBit(auraData.Duration.has_value());
    data.WriteBit(auraData.Remaining.has_value());
    data.WriteBit(auraData.TimeMod.has_value());
    data.WriteBits(auraData.Points.size(), 6);
    data.WriteBits(auraData.EstimatedPoints.size(), 6);
    data.WriteBit(auraData.ContentTuning.has_value());

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

ByteBuffer& operator<<(ByteBuffer& data, AuraInfo const& aura)
{
    data << aura.Slot;
    data.WriteBit(aura.AuraData.has_value());
    data.FlushBits();

    if (aura.AuraData)
        data << *aura.AuraData;

    return data;
}

WorldPacket const* AuraUpdate::Write()
{
    _worldPacket.WriteBit(UpdateAll);
    _worldPacket.WriteBits(Auras.size(), 9);
    for (AuraInfo const& aura : Auras)
        _worldPacket << aura;

    _worldPacket << UnitGUID;

    return &_worldPacket;
}

ByteBuffer& operator>>(ByteBuffer& buffer, TargetLocation& location)
{
    buffer >> location.Transport;
    buffer >> location.Location;
    return buffer;
}

ByteBuffer& operator>>(ByteBuffer& buffer, SpellTargetData& targetData)
{
    buffer.ResetBitPos();

    targetData.Flags = buffer.ReadBits(28);
    bool hasSrcLocation = buffer.ReadBit();
    bool hasDstLocation = buffer.ReadBit();
    bool hasOrientation = buffer.ReadBit();
    bool hasMapID = buffer.ReadBit();
    uint32 nameLength = buffer.ReadBits(7);

    buffer >> targetData.Unit;
    buffer >> targetData.Item;

    if (hasSrcLocation)
        buffer >> targetData.SrcLocation.emplace();

    if (hasDstLocation)
        buffer >> targetData.DstLocation.emplace();

    if (hasOrientation)
        targetData.Orientation = buffer.read<float>();

    if (hasMapID)
        targetData.MapID = buffer.read<int32>();

    targetData.Name = buffer.ReadString(nameLength);

    return buffer;
}

ByteBuffer& operator>>(ByteBuffer& buffer, MissileTrajectoryRequest& trajectory)
{
    buffer >> trajectory.Pitch;
    buffer >> trajectory.Speed;
    return buffer;
}

ByteBuffer& operator>>(ByteBuffer& data, SpellCraftingReagent& optionalReagent)
{
    data >> optionalReagent.ItemID;
    data >> optionalReagent.DataSlotIndex;
    data >> optionalReagent.Quantity;
    if (data.ReadBit())
        optionalReagent.Unknown_1000 = data.read<uint8>();

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, SpellExtraCurrencyCost& extraCurrencyCost)
{
    data >> extraCurrencyCost.CurrencyID;
    data >> extraCurrencyCost.Count;
    return data;
}

ByteBuffer& operator>>(ByteBuffer& buffer, SpellCastRequest& request)
{
    buffer >> request.CastID;
    buffer >> request.Misc[0];
    buffer >> request.Misc[1];
    buffer >> request.SpellID;
    buffer >> request.Visual;
    buffer >> request.MissileTrajectory;
    buffer >> request.CraftingNPC;
    request.OptionalCurrencies.resize(buffer.read<uint32>());
    request.OptionalReagents.resize(buffer.read<uint32>());
    request.RemovedModifications.resize(buffer.read<uint32>());

    for (SpellExtraCurrencyCost& optionalCurrency : request.OptionalCurrencies)
        buffer >> optionalCurrency;

    request.SendCastFlags = buffer.ReadBits(5);
    bool hasMoveUpdate = buffer.ReadBit();
    request.Weight.resize(buffer.ReadBits(2));
    bool hasCraftingOrderID = buffer.ReadBit();
    buffer >> request.Target;

    if (hasCraftingOrderID)
        request.CraftingOrderID = buffer.read<uint64>();

    for (SpellCraftingReagent& optionalReagent : request.OptionalReagents)
        buffer >> optionalReagent;

    for (SpellCraftingReagent& optionalReagent : request.RemovedModifications)
        buffer >> optionalReagent;

    if (hasMoveUpdate)
        buffer >> request.MoveUpdate.emplace();

    for (SpellWeight& weight : request.Weight)
    {
        buffer.ResetBitPos();
        weight.Type = buffer.ReadBits(2);
        buffer >> weight.ID;
        buffer >> weight.Quantity;
    }

    return buffer;
}

void CastSpell::Read()
{
    _worldPacket >> Cast;
}

void PetCastSpell::Read()
{
    _worldPacket >> PetGUID;
    _worldPacket >> Cast;
}

void UseItem::Read()
{
    _worldPacket >> PackSlot;
    _worldPacket >> Slot;
    _worldPacket >> CastItem;
    _worldPacket >> Cast;
}

WorldPacket const* SpellPrepare::Write()
{
    _worldPacket << ClientCastID;
    _worldPacket << ServerCastID;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, TargetLocation const& targetLocation)
{
    data << targetLocation.Transport;
    data << targetLocation.Location;
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellTargetData const& spellTargetData)
{
    data.WriteBits(spellTargetData.Flags, 28);
    data.WriteBit(spellTargetData.SrcLocation.has_value());
    data.WriteBit(spellTargetData.DstLocation.has_value());
    data.WriteBit(spellTargetData.Orientation.has_value());
    data.WriteBit(spellTargetData.MapID.has_value());
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

ByteBuffer& operator<<(ByteBuffer& data, SpellMissStatus const& spellMissStatus)
{
    data << uint8(spellMissStatus.Reason);
    if (spellMissStatus.Reason == SPELL_MISS_REFLECT)
        data << uint8(spellMissStatus.ReflectStatus);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellPowerData const& spellPowerData)
{
    data << int32(spellPowerData.Cost);
    data << int8(spellPowerData.Type);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, RuneData const& runeData)
{
    data << uint8(runeData.Start);
    data << uint8(runeData.Count);
    data << uint32(runeData.Cooldowns.size());
    if (!runeData.Cooldowns.empty())
        data.append(runeData.Cooldowns.data(), runeData.Cooldowns.size());

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MissileTrajectoryResult const& missileTrajectory)
{
    data << uint32(missileTrajectory.TravelTime);
    data << float(missileTrajectory.Pitch);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, CreatureImmunities const& immunities)
{
    data << int32(immunities.School);
    data << int32(immunities.Value);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellHealPrediction const& spellPred)
{
    data << int32(spellPred.Points);
    data << uint8(spellPred.Type);
    data << spellPred.BeaconGUID;
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellCastData const& spellCastData)
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
    data << uint8(spellCastData.DestLocSpellCastIndex);
    data << spellCastData.Immunities;
    data << spellCastData.Predict;
    data.WriteBits(spellCastData.HitTargets.size(), 16);
    data.WriteBits(spellCastData.MissTargets.size(), 16);
    data.WriteBits(spellCastData.MissStatus.size(), 16);
    data.WriteBits(spellCastData.RemainingPower.size(), 9);
    data.WriteBit(spellCastData.RemainingRunes.has_value());
    data.WriteBits(spellCastData.TargetPoints.size(), 16);
    data.WriteBit(spellCastData.AmmoDisplayID.has_value());
    data.WriteBit(spellCastData.AmmoInventoryType.has_value());
    data.FlushBits();

    data << spellCastData.Target;

    for (ObjectGuid const& hitTarget : spellCastData.HitTargets)
        data << hitTarget;

    for (ObjectGuid const& missTarget : spellCastData.MissTargets)
        data << missTarget;

    for (SpellMissStatus const& missStatus : spellCastData.MissStatus)
        data << missStatus;

    for (SpellPowerData const& power : spellCastData.RemainingPower)
        data << power;

    if (spellCastData.RemainingRunes)
        data << *spellCastData.RemainingRunes;

    for (TargetLocation const& targetLoc : spellCastData.TargetPoints)
        data << targetLoc;

    if (spellCastData.AmmoDisplayID.has_value())
        data << int32(*spellCastData.AmmoDisplayID);

    if (spellCastData.AmmoInventoryType.has_value())
        data << int32(*spellCastData.AmmoInventoryType);

    return data;
}

WorldPacket const* SpellStart::Write()
{
    _worldPacket << Cast;

    return &_worldPacket;
}

WorldPacket const* SpellGo::Write()
{
    *this << Cast;

    WriteLogDataBit();
    FlushBits();

    WriteLogData();

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, LearnedSpellInfo const& learnedSpellInfo)
{
    data << int32(learnedSpellInfo.SpellID);
    data.WriteBit(learnedSpellInfo.IsFavorite);
    data.WriteBit(learnedSpellInfo.field_8.has_value());
    data.WriteBit(learnedSpellInfo.Superceded.has_value());
    data.WriteBit(learnedSpellInfo.TraitDefinitionID.has_value());
    data.FlushBits();

    if (learnedSpellInfo.field_8)
        data << int32(*learnedSpellInfo.field_8);

    if (learnedSpellInfo.Superceded)
        data << int32(*learnedSpellInfo.Superceded);

    if (learnedSpellInfo.TraitDefinitionID)
        data << int32(*learnedSpellInfo.TraitDefinitionID);

    return data;
}

WorldPacket const* LearnedSpells::Write()
{
    _worldPacket << uint32(ClientLearnedSpellData.size());
    _worldPacket << uint32(SpecializationID);
    _worldPacket.WriteBit(SuppressMessaging);
    _worldPacket.FlushBits();

    for (LearnedSpellInfo const& spell : ClientLearnedSpellData)
        _worldPacket << spell;

    return &_worldPacket;
}

WorldPacket const* SupercededSpells::Write()
{
    _worldPacket << uint32(ClientLearnedSpellData.size());

    for (LearnedSpellInfo const& spell : ClientLearnedSpellData)
        _worldPacket << spell;

    return &_worldPacket;
}

WorldPacket const* SpellFailure::Write()
{
    _worldPacket << CasterUnit;
    _worldPacket << CastID;
    _worldPacket << int32(SpellID);
    _worldPacket << Visual;
    _worldPacket << uint16(Reason);

    return &_worldPacket;
}

WorldPacket const* SpellFailedOther::Write()
{
    _worldPacket << CasterUnit;
    _worldPacket << CastID;
    _worldPacket << uint32(SpellID);
    _worldPacket << Visual;
    _worldPacket << uint8(Reason);

    return &_worldPacket;
}

WorldPacket const* CastFailed::Write()
{
    _worldPacket << CastID;
    _worldPacket << int32(SpellID);
    _worldPacket << Visual;
    _worldPacket << int32(Reason);
    _worldPacket << int32(FailedArg1);
    _worldPacket << int32(FailedArg2);

    return &_worldPacket;
}

WorldPacket const* PetCastFailed::Write()
{
    _worldPacket << CastID;
    _worldPacket << int32(SpellID);
    _worldPacket << int32(Reason);
    _worldPacket << int32(FailedArg1);
    _worldPacket << int32(FailedArg2);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellModifierData const& spellModifierData)
{
    data << float(spellModifierData.ModifierValue);
    data << uint8(spellModifierData.ClassIndex);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellModifier const& spellModifier)
{
    data << uint8(spellModifier.ModIndex);
    data << uint32(spellModifier.ModifierData.size());
    for (SpellModifierData const& modData : spellModifier.ModifierData)
        data << modData;

    return data;
}

WorldPacket const* SetSpellModifier::Write()
{
    _worldPacket << uint32(Modifiers.size());
    for (SpellModifier const& spellMod : Modifiers)
        _worldPacket << spellMod;

    return &_worldPacket;
}

WorldPacket const* UnlearnedSpells::Write()
{
    _worldPacket << uint32(SpellID.size());
    for (uint32 spellId : SpellID)
        _worldPacket << uint32(spellId);

    _worldPacket.WriteBit(SuppressMessaging);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* CooldownEvent::Write()
{
    _worldPacket << int32(SpellID);
    _worldPacket.WriteBit(IsPet);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* ClearCooldowns::Write()
{
    _worldPacket << uint32(SpellID.size());
    if (!SpellID.empty())
        _worldPacket.append(SpellID.data(), SpellID.size());

    _worldPacket.WriteBit(IsPet);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* ClearCooldown::Write()
{
    _worldPacket << uint32(SpellID);
    _worldPacket.WriteBit(ClearOnHold);
    _worldPacket.WriteBit(IsPet);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* ModifyCooldown::Write()
{
    _worldPacket << int32(SpellID);
    _worldPacket << int32(DeltaTime);
    _worldPacket.WriteBit(IsPet);
    _worldPacket.WriteBit(WithoutCategoryCooldown);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellCooldownStruct const& cooldown)
{
    data << uint32(cooldown.SrecID);
    data << uint32(cooldown.ForcedCooldown);
    data << float(cooldown.ModRate);
    return data;
}

WorldPacket const* SpellCooldown::Write()
{
    _worldPacket << Caster;
    _worldPacket << uint8(Flags);
    _worldPacket << uint32(SpellCooldowns.size());
    for (SpellCooldownStruct const& cooldown : SpellCooldowns)
        _worldPacket << cooldown;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellHistoryEntry const& historyEntry)
{
    data << uint32(historyEntry.SpellID);
    data << uint32(historyEntry.ItemID);
    data << uint32(historyEntry.Category);
    data << int32(historyEntry.RecoveryTime);
    data << int32(historyEntry.CategoryRecoveryTime);
    data << float(historyEntry.ModRate);
    data.WriteBit(historyEntry.unused622_1.has_value());
    data.WriteBit(historyEntry.unused622_2.has_value());
    data.WriteBit(historyEntry.OnHold);
    if (historyEntry.unused622_1)
        data << uint32(*historyEntry.unused622_1);
    if (historyEntry.unused622_2)
        data << uint32(*historyEntry.unused622_2);
    data.FlushBits();

    return data;
}

WorldPacket const* SendSpellHistory::Write()
{
    _worldPacket << uint32(Entries.size());
    for (SpellHistoryEntry const& historyEntry : Entries)
        _worldPacket << historyEntry;

    return &_worldPacket;
}

WorldPacket const* ClearAllSpellCharges::Write()
{
    _worldPacket.WriteBit(IsPet);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* ClearSpellCharges::Write()
{
    _worldPacket << int32(Category);
    _worldPacket.WriteBit(IsPet);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* SetSpellCharges::Write()
{
    _worldPacket << int32(Category);
    _worldPacket << uint32(NextRecoveryTime);
    _worldPacket << uint8(ConsumedCharges);
    _worldPacket << float(ChargeModRate);
    _worldPacket.WriteBit(IsPet);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellChargeEntry const& chargeEntry)
{
    data << uint32(chargeEntry.Category);
    data << uint32(chargeEntry.NextRecoveryTime);
    data << float(chargeEntry.ChargeModRate);
    data << uint8(chargeEntry.ConsumedCharges);
    return data;
}

WorldPacket const* SendSpellCharges::Write()
{
    _worldPacket << uint32(Entries.size());
    for (SpellChargeEntry const& chargeEntry : Entries)
        _worldPacket << chargeEntry;

    return &_worldPacket;
}

WorldPacket const* ClearTarget::Write()
{
    _worldPacket << Guid;

    return &_worldPacket;
}

WorldPacket const* CancelOrphanSpellVisual::Write()
{
    _worldPacket << int32(SpellVisualID);

    return &_worldPacket;
}

WorldPacket const* CancelSpellVisual::Write()
{
    _worldPacket << Source;
    _worldPacket << int32(SpellVisualID);

    return &_worldPacket;
}

WorldPacket const* CancelSpellVisualKit::Write()
{
    _worldPacket << Source;
    _worldPacket << int32(SpellVisualKitID);
    _worldPacket.WriteBit(MountedVisual);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* PlayOrphanSpellVisual::Write()
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

WorldPacket const* PlaySpellVisual::Write()
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

WorldPacket const* PlaySpellVisualKit::Write()
{
    _worldPacket << Unit;
    _worldPacket << int32(KitRecID);
    _worldPacket << int32(KitType);
    _worldPacket << uint32(Duration);
    _worldPacket.WriteBit(MountedVisual);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* SpellVisualLoadScreen::Write()
{
    _worldPacket << int32(SpellVisualKitID);
    _worldPacket << int32(Delay);

    return &_worldPacket;
}

void CancelCast::Read()
{
    _worldPacket >> CastID;
    _worldPacket >> SpellID;
}

void OpenItem::Read()
{
    _worldPacket >> Slot
                 >> PackSlot;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellChannelStartInterruptImmunities const& interruptImmunities)
{
    data << int32(interruptImmunities.SchoolImmunities);
    data << int32(interruptImmunities.Immunities);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellTargetedHealPrediction const& targetedHealPrediction)
{
    data << targetedHealPrediction.TargetGUID;
    data << targetedHealPrediction.Predict;
    return data;
}

WorldPacket const* SpellChannelStart::Write()
{
    _worldPacket << CasterGUID;
    _worldPacket << int32(SpellID);
    _worldPacket << Visual;
    _worldPacket << uint32(ChannelDuration);
    _worldPacket.WriteBit(InterruptImmunities.has_value());
    _worldPacket.WriteBit(HealPrediction.has_value());
    _worldPacket.FlushBits();

    if (InterruptImmunities)
        _worldPacket << *InterruptImmunities;

    if (HealPrediction)
        _worldPacket << *HealPrediction;

    return &_worldPacket;
}

WorldPacket const* SpellChannelUpdate::Write()
{
    _worldPacket << CasterGUID;
    _worldPacket << int32(TimeRemaining);
    return &_worldPacket;
}

WorldPacket const* ResurrectRequest::Write()
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

void UnlearnSkill::Read()
{
    _worldPacket >> SkillLine;
}

void SelfRes::Read()
{
    _worldPacket >> SpellID;
}

void GetMirrorImageData::Read()
{
    _worldPacket >> UnitGUID;
}

MirrorImageComponentedData::MirrorImageComponentedData()
    : ServerPacket(SMSG_MIRROR_IMAGE_COMPONENTED_DATA, 8 + 4 + 8 * 1 + 8 + 11 * 4)
{
}

MirrorImageComponentedData::~MirrorImageComponentedData() = default;

WorldPacket const* MirrorImageComponentedData::Write()
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

WorldPacket const* MirrorImageCreatureData::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << int32(DisplayID);
    _worldPacket << int32(SpellVisualKitID);

    return &_worldPacket;
}

void SpellClick::Read()
{
    _worldPacket >> SpellClickUnitGuid;
    TryAutoDismount = _worldPacket.ReadBit();
}

WorldPacket const* ResyncRunes::Write()
{
    _worldPacket << Runes;

    return &_worldPacket;
}

WorldPacket const* AddRunePower::Write()
{
    _worldPacket << uint32(AddedRunesMask);

    return &_worldPacket;
}

void MissileTrajectoryCollision::Read()
{
    _worldPacket >> Target;
    _worldPacket >> SpellID;
    _worldPacket >> CastID;
    _worldPacket >> CollisionPos;
}

WorldPacket const* NotifyMissileTrajectoryCollision::Write()
{
    _worldPacket << Caster;
    _worldPacket << CastID;
    _worldPacket << CollisionPos;

    return &_worldPacket;
}

void UpdateMissileTrajectory::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> CastID;
    _worldPacket >> MoveMsgID;
    _worldPacket >> SpellID;
    _worldPacket >> Pitch;
    _worldPacket >> Speed;
    _worldPacket >> FirePos;
    _worldPacket >> ImpactPos;
    bool hasStatus = _worldPacket.ReadBit();

    _worldPacket.ResetBitPos();
    if (hasStatus)
        _worldPacket >> Status.emplace();
}

WorldPacket const* SpellDelayed::Write()
{
    _worldPacket << Caster;
    _worldPacket << uint32(ActualDelay);

    return &_worldPacket;
}

WorldPacket const* DispelFailed::Write()
{
    _worldPacket << CasterGUID;
    _worldPacket << VictimGUID;
    _worldPacket << uint32(SpellID);
    _worldPacket << uint32(FailedSpells.size());
    if (!FailedSpells.empty())
        _worldPacket.append(FailedSpells.data(), FailedSpells.size());

    return &_worldPacket;
}

WorldPacket const* CustomLoadScreen::Write()
{
    _worldPacket << uint32(TeleportSpellID);
    _worldPacket << uint32(LoadingScreenID);
    return &_worldPacket;
}

WorldPacket const* MountResult::Write()
{
    _worldPacket << int32(Result);

    return &_worldPacket;
}

WorldPacket const* MissileCancel::Write()
{
    _worldPacket << OwnerGUID;
    _worldPacket << int32(SpellID);
    _worldPacket.WriteBit(Reverse);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void TradeSkillSetFavorite::Read()
{
    _worldPacket >> RecipeID;
    IsFavorite = _worldPacket.ReadBit();
}

void KeyboundOverride::Read()
{
    _worldPacket >> OverrideID;
}
}
