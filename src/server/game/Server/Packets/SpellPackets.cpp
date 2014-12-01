/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

WorldPacket const* WorldPackets::Spells::SendAuraUpdate::Write()
{
    return &_worldPacket;
}

void WorldPackets::Spells::SendAuraUpdate::Init(bool IsFullUpdate, ObjectGuid Target, uint32 Count)
{
    _worldPacket.WriteBit(IsFullUpdate);
    _worldPacket << Target;
    _worldPacket << uint32(Count);
}

void WorldPackets::Spells::SendAuraUpdate::BuildUpdatePacket(AuraApplication* aurApp, bool remove, uint16 level)
{
    _worldPacket << uint8(aurApp->GetSlot());
    _worldPacket.ResetBitPos();
    _worldPacket.WriteBit(!remove);

    if (remove)
    {
        _worldPacket.FlushBits();
        return;
    }
    Aura const* aura = aurApp->GetBase();
    _worldPacket << uint32(aura->GetId());

    uint8 flags = aurApp->GetFlags();
    if (aura->GetMaxDuration() > 0 && !(aura->GetSpellInfo()->AttributesEx5 & SPELL_ATTR5_HIDE_DURATION))
        flags |= AFLAG_DURATION;
    _worldPacket << uint8(flags);

    _worldPacket << uint32(aurApp->GetEffectMask());

    _worldPacket << uint16(level);

    // send stack amount for aura which could be stacked (never 0 - causes incorrect display) or charges
    // stack amount has priority over charges (checked on retail with spell 50262)
    _worldPacket << uint8(aura->GetSpellInfo()->StackAmount ? aura->GetStackAmount() : aura->GetCharges());

    uint32 int72 = 0;
    _worldPacket << int72;

    size_t pos = _worldPacket.wpos();
    uint32 count = 0;
    _worldPacket << count;

    //for (int72)
    //    float

    if (flags & AFLAG_SCALABLE)
    {
        for (AuraEffect const* effect : aura->GetAuraEffects())
        {
            if (effect && aurApp->HasEffect(effect->GetEffIndex()))       // Not all of aura's effects have to be applied on every target
            {
                _worldPacket << int32(effect->GetAmount());
                count++;
            }
        }
    }

    _worldPacket.put<uint32>(pos, count);

    _worldPacket.ResetBitPos();

    _worldPacket.WriteBit(!(flags & AFLAG_NOCASTER));
    _worldPacket.WriteBit(aura->GetDuration());
    _worldPacket.WriteBit(aura->GetMaxDuration());

    if (!(flags & AFLAG_NOCASTER))
        _worldPacket << aura->GetCasterGUID().WriteAsPacked();

    if (aura->GetDuration())
    {
        _worldPacket << uint32(aura->GetDuration());
    }

    if (aura->GetMaxDuration())
    {
        _worldPacket << uint32(aura->GetMaxDuration());
    }
}

void WorldPackets::Spells::SpellCastRequest::Read()
{
    if (_worldPacket.GetOpcode() == CMSG_PET_CAST_SPELL)
        _worldPacket >> PetGuid;

    _worldPacket >> CastID;
    _worldPacket >> SpellID;
    _worldPacket >> Misc;

    TC_LOG_ERROR("spells", "SpellID %u Misc %u", SpellID, Misc);

    _worldPacket.ResetBitPos();

    TargetFlags = _worldPacket.ReadBits(21);
    bool HasSrcLocation = _worldPacket.ReadBit();
    bool HasDstLocation = _worldPacket.ReadBit();
    bool HasOrientation = _worldPacket.ReadBit();
    uint32 NameLen = _worldPacket.ReadBits(7);

    _worldPacket >> UnitGuid;
    _worldPacket >> ItemGuid;

    if (HasSrcLocation)
    {
        _worldPacket >> SrcTransportGuid;
        _worldPacket >> SrcPos.m_positionX;
        _worldPacket >> SrcPos.m_positionY;
        _worldPacket >> SrcPos.m_positionZ;
    }

    if (HasDstLocation)
    {
        _worldPacket >> DstTransportGuid;
        _worldPacket >> DstPos.m_positionX;
        _worldPacket >> DstPos.m_positionY;
        _worldPacket >> DstPos.m_positionZ;
    }

    if (HasOrientation)
        _worldPacket >> Orientation;

    Name = _worldPacket.ReadString(NameLen);

    _worldPacket >> Pitch;
    _worldPacket >> Speed;

    _worldPacket >> Guid;

    _worldPacket.ResetBitPos();

    SendCastFlags = _worldPacket.ReadBits(5);

    bool HasMoveUpdate = _worldPacket.ReadBit();
    uint32 SpellWeightCount = _worldPacket.ReadBits(2);

    if (HasMoveUpdate)
    {
        _worldPacket >> movementInfo;
    }

    // SpellWeight
    for (uint32 i = 0; i < SpellWeightCount; ++i)
    {
        _worldPacket.ResetBitPos();
        uint32 Type = _worldPacket.ReadBits(2);
        uint32 ID;
        _worldPacket >> ID;
        uint32 Quantity;
        _worldPacket >> Quantity;
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::TargetLocation const& targetLocation)
{
    data << targetLocation.Transport;
    // data << targetLocation.Location.PositionXYZStream();
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
