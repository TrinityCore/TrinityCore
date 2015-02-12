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

#include "SpellPackets.h"
#include "SpellAuraEffects.h"
#include "MovementPackets.h"

void WorldPackets::Spells::CancelAura::Read()
{
    _worldPacket >> SpellID;
    _worldPacket >> CasterGUID;
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
    _worldPacket.reserve(1 + 4 * KnownSpells.size());

    _worldPacket.WriteBit(InitialLogin);
    _worldPacket << uint32(KnownSpells.size());

    for (uint32 spellId : KnownSpells)
        _worldPacket << uint32(spellId);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::UpdateActionButtons::Write()
{
    for (uint32 i = 0; i < MAX_ACTION_BUTTONS; ++i)
        _worldPacket << ActionButtons[i];

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

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellCastLogData const& spellCastLogData)
{
    data << spellCastLogData.Health;
    data << spellCastLogData.AttackPower;
    data << spellCastLogData.SpellPower;
    data << int32(spellCastLogData.PowerData.size());
    for (WorldPackets::Spells::SpellLogPowerData const& powerData : spellCastLogData.PowerData)
    {
        data << powerData.PowerType;
        data << powerData.Amount;
    }
    data.WriteBit(false);
    // data << float // Unk data if bit is true
    data.FlushBits();

    return data;
}

WorldPacket const* WorldPackets::Spells::AuraUpdate::Write()
{
    _worldPacket.WriteBit(UpdateAll);
    _worldPacket << UnitGUID;
    _worldPacket << uint32(Auras.size());
    for (auto& aura : Auras)
    {
        _worldPacket << aura.Slot;
        if (_worldPacket.WriteBit(aura.AuraData.HasValue))
        {
            AuraDataInfo const& data = aura.AuraData.Value;
            _worldPacket << uint32(data.SpellID);
            _worldPacket << uint8(data.Flags);
            _worldPacket << uint32(data.ActiveFlags);
            _worldPacket << uint16(data.CastLevel);
            _worldPacket << uint8(data.Applications);
            _worldPacket << uint32(data.EstimatedPoints.size());
            _worldPacket << uint32(data.Points.size());

            if (!data.EstimatedPoints.empty())
                _worldPacket.append(data.EstimatedPoints.data(), data.EstimatedPoints.size());

            if (!data.Points.empty())
                _worldPacket.append(data.Points.data(), data.Points.size());

            _worldPacket.WriteBit(data.CastUnit.HasValue);
            _worldPacket.WriteBit(data.Duration.HasValue);
            _worldPacket.WriteBit(data.Remaining.HasValue);

            if (data.CastUnit.HasValue)
                _worldPacket << data.CastUnit.Value;

            if (data.Duration.HasValue)
                _worldPacket << uint32(data.Duration.Value);

            if (data.Remaining.HasValue)
                _worldPacket << uint32(data.Remaining.Value);
        }

        _worldPacket.FlushBits();
    }

    return &_worldPacket;
}

ByteBuffer& operator>>(ByteBuffer& buffer, WorldPackets::Spells::TargetLocation& location)
{
    buffer >> location.Transport;
    buffer >> location.Location.m_positionX;
    buffer >> location.Location.m_positionY;
    buffer >> location.Location.m_positionZ;
    return buffer;
}

ByteBuffer& operator>>(ByteBuffer& buffer, WorldPackets::Spells::SpellTargetData& targetData)
{
    buffer.ResetBitPos();

    targetData.Flags = buffer.ReadBits(21);
    targetData.SrcLocation.HasValue = buffer.ReadBit();
    targetData.DstLocation.HasValue = buffer.ReadBit();
    targetData.Orientation.HasValue = buffer.ReadBit();
    uint32 nameLength = buffer.ReadBits(7);

    buffer >> targetData.Unit;
    buffer >> targetData.Item;

    if (targetData.SrcLocation.HasValue)
        buffer >> targetData.SrcLocation.Value;

    if (targetData.DstLocation.HasValue)
        buffer >> targetData.DstLocation.Value;

    if (targetData.Orientation.HasValue)
        buffer >> targetData.Orientation.Value;

    targetData.Name = buffer.ReadString(nameLength);

    return buffer;
}

ByteBuffer& operator>>(ByteBuffer& buffer, WorldPackets::Spells::MissileTrajectoryRequest& trajectory)
{
    buffer >> trajectory.Pitch;
    buffer >> trajectory.Speed;
    return buffer;
}

ByteBuffer& operator>>(ByteBuffer& buffer, WorldPackets::Spells::SpellCastRequest& request)
{
    buffer >> request.CastID;
    buffer >> request.SpellID;
    buffer >> request.Misc;
    buffer >> request.Target;
    buffer >> request.MissileTrajectory;
    buffer >> request.Charmer;

    buffer.ResetBitPos();
    request.SendCastFlags = buffer.ReadBits(5);
    request.MoveUpdate.HasValue = buffer.ReadBit();
    request.Weight.resize(buffer.ReadBits(2));

    if (request.MoveUpdate.HasValue)
        buffer >> request.MoveUpdate.Value;

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

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::TargetLocation const& targetLocation)
{
    data << targetLocation.Transport;
    data << targetLocation.Location.m_positionX;
    data << targetLocation.Location.m_positionY;
    data << targetLocation.Location.m_positionZ;
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellTargetData const& spellTargetData)
{
    data.WriteBits(spellTargetData.Flags, 21);
    data.WriteBit(spellTargetData.SrcLocation.HasValue);
    data.WriteBit(spellTargetData.DstLocation.HasValue);
    data.WriteBit(spellTargetData.Orientation.HasValue);
    data.WriteBits(spellTargetData.Name.size(), 7);
    data.FlushBits();

    data << spellTargetData.Unit;
    data << spellTargetData.Item;

    if (spellTargetData.SrcLocation.HasValue)
        data << spellTargetData.SrcLocation.Value;

    if (spellTargetData.DstLocation.HasValue)
        data << spellTargetData.DstLocation.Value;

    if (spellTargetData.Orientation.HasValue)
        data << spellTargetData.Orientation.Value;

    data.WriteString(spellTargetData.Name);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellMissStatus const& spellMissStatus)
{
    data.WriteBits(spellMissStatus.Reason, 4);
    data.WriteBits(spellMissStatus.ReflectStatus, 4);
    // No need to flush bits as we written exactly 8 bits (1 byte)
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellPowerData const& spellPowerData)
{
    data << spellPowerData.Cost;
    data << spellPowerData.Type;
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::RuneData const& runeData)
{
    data << runeData.Start;
    data << runeData.Count;

    data.WriteBits(runeData.Cooldowns.size(), 3);
    data.FlushBits();

    for (uint8 cd : runeData.Cooldowns)
        data << cd;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::MissileTrajectoryResult const& missileTrajectory)
{
    data << missileTrajectory.TravelTime;
    data << missileTrajectory.Pitch;
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellAmmo const& spellAmmo)
{
    data << spellAmmo.DisplayID;
    data << spellAmmo.InventoryType;
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::ProjectileVisualData const& projectileVisual)
{
    data << projectileVisual.ID[0];
    data << projectileVisual.ID[1];
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::CreatureImmunities const& immunities)
{
    data << immunities.School;
    data << immunities.Value;
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellHealPrediction const& spellPred)
{
    data << spellPred.Points;
    data << spellPred.Type;
    data << spellPred.BeaconGUID;
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellCastData const& spellCastData)
{
    data << spellCastData.CasterGUID;
    data << spellCastData.CasterUnit;
    data << spellCastData.CastID;
    data << spellCastData.SpellID;
    data << spellCastData.CastFlags;
    data << spellCastData.CastTime;
    data << uint32(spellCastData.HitTargets.size());
    data << uint32(spellCastData.MissTargets.size());
    data << uint32(spellCastData.MissStatus.size());
    data << spellCastData.Target;
    data << uint32(spellCastData.RemainingPower.size());
    data << spellCastData.MissileTrajectory;
    data << spellCastData.Ammo;
    data << spellCastData.DestLocSpellCastIndex;
    data << uint32(spellCastData.TargetPoints.size());
    data << spellCastData.Immunities;
    data << spellCastData.Predict;

    for (ObjectGuid const& target : spellCastData.HitTargets)
        data << target;

    for (ObjectGuid const& target : spellCastData.MissTargets)
        data << target;

    for (WorldPackets::Spells::SpellMissStatus const& status : spellCastData.MissStatus)
        data << status;

    for (WorldPackets::Spells::SpellPowerData const& power : spellCastData.RemainingPower)
        data << power;

    for (WorldPackets::Spells::TargetLocation const& targetLoc : spellCastData.TargetPoints)
        data << targetLoc;

    data.WriteBits(spellCastData.CastFlagsEx, 18);
    data.WriteBit(spellCastData.RemainingRunes.HasValue);
    data.WriteBit(spellCastData.ProjectileVisual.HasValue);
    data.FlushBits();

    if (spellCastData.RemainingRunes.HasValue)
        data << spellCastData.RemainingRunes.Value;

    if (spellCastData.ProjectileVisual.HasValue)
        data << spellCastData.ProjectileVisual.Value;

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

    _worldPacket.WriteBit(LogData.HasValue);
    _worldPacket.FlushBits();

    if (LogData.HasValue)
        _worldPacket << LogData.Value;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::LearnedSpells::Write()
{
    _worldPacket << uint32(SpellID.size());
    for (int32 spell : SpellID)
        _worldPacket << spell;

    _worldPacket.WriteBit(SuppressMessaging);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::SpellFailure::Write()
{
    _worldPacket << CasterUnit;
    _worldPacket << CastID;
    _worldPacket << SpellID;
    _worldPacket << Reason;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::SpellFailedOther::Write()
{
    _worldPacket << CasterUnit;
    _worldPacket << CastID;
    _worldPacket << SpellID;
    _worldPacket << Reason;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::CastFailed::Write()
{
    _worldPacket << SpellID;
    _worldPacket << Reason;
    _worldPacket << FailedArg1;
    _worldPacket << FailedArg2;
    _worldPacket << CastID;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellModifierData const& spellModifierData)
{
    data << spellModifierData.ModifierValue;
    data << spellModifierData.ClassIndex;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellModifier const& spellModifier)
{
    data << spellModifier.ModIndex;
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

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spells::CooldownEvent::Write()
{
    _worldPacket << CasterGUID;
    _worldPacket << int32(SpellID);

    return &_worldPacket;
}
