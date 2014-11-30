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

WorldPacket const* WorldPackets::Spells::SendUnlearnSpells::Write()
{
    _worldPacket << uint32(Spells.size());
    for (uint32 spellId : Spells)
        _worldPacket << uint32(spellId);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellCastLogData& spellCastLogData)
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

WorldPacket const* WorldPackets::Spells::SendSpellStart::Write()
{
    uint32 castFlags = CAST_FLAG_HAS_TRAJECTORY;

    if ((spell->IsTriggered() && !spell->m_spellInfo->IsAutoRepeatRangedSpell()) || spell->GetTriggeredByAuraSpell())
        castFlags |= CAST_FLAG_PENDING;

    if ((spell->GetCaster()->GetTypeId() == TYPEID_PLAYER ||
        (spell->GetCaster()->GetTypeId() == TYPEID_UNIT && spell->GetCaster()->ToCreature()->IsPet()))
         && spell->m_spellInfo->PowerType != POWER_HEALTH)
        castFlags |= CAST_FLAG_POWER_LEFT_SELF;

    if (spell->m_spellInfo->RuneCostID && spell->m_spellInfo->PowerType == POWER_RUNES)
        castFlags |= CAST_FLAG_NO_GCD; // not needed, but Blizzard sends it


     if (spell->m_CastItem)
        _worldPacket << spell->m_CastItem->GetGUID();
    else
        _worldPacket << spell->GetCaster()->GetGUID();
    _worldPacket << spell->GetCaster()->GetGUID();
    _worldPacket << uint8(spell->m_cast_count);
    _worldPacket << uint32(spell->m_spellInfo->Id);
    _worldPacket << uint32(castFlags);
    _worldPacket << uint32(spell->GetCastTime());

    uint32 HitTargets = 0;
    _worldPacket << HitTargets;
    uint32 MissTargets = 0;
    _worldPacket << MissTargets;
    uint32 MissStatus = 0;
    _worldPacket << MissStatus;

    _worldPacket.ResetBitPos();

    _worldPacket.WriteBits(spell->m_targets.GetTargetMask(), 21);

    bool HasSourceLocation = (spell->m_targets.GetTargetMask() & TARGET_FLAG_SOURCE_LOCATION) && spell->m_targets.GetSrc();
    bool HasDestLocation = (spell->m_targets.GetTargetMask() & TARGET_FLAG_DEST_LOCATION) && spell->m_targets.GetDst();
    bool HasOrientation = false;
    uint32 NameLen = spell->m_targets.GetTargetString().length();
    
    _worldPacket.WriteBit(HasSourceLocation);
    _worldPacket.WriteBit(HasDestLocation);
    _worldPacket.WriteBit(HasOrientation);
    _worldPacket.WriteBits(NameLen, 7);
    
    ObjectGuid targetGuid = spell->m_targets.GetObjectTargetGUID();
    ObjectGuid itemTargetGuid = spell->m_targets.GetItemTargetGUID();

    _worldPacket << targetGuid;
    _worldPacket << itemTargetGuid;

    if (HasSourceLocation)
    {
        _worldPacket << spell->m_targets.GetSrc()->_transportGUID;
        float x, y, z;
        spell->m_targets.GetSrc()->_transportOffset.GetPosition(x, y, z);
        _worldPacket << x;
        _worldPacket << y;
        _worldPacket << z;
    }
    
    if (HasDestLocation)
    {
        _worldPacket << spell->m_targets.GetDst()->_transportGUID;
        float x, y, z;
        spell->m_targets.GetDst()->_transportOffset.GetPosition(x, y, z);
        _worldPacket << x;
        _worldPacket << y;
        _worldPacket << z;
    }

    //if (HasOrientation)
    //  _worldPacket << float(0);

    _worldPacket.WriteString(spell->m_targets.GetTargetString());

    uint32 SpellPowerData = 0;
    _worldPacket << SpellPowerData;

        
    _worldPacket << uint32(0); // TravelTime
    _worldPacket << spell->m_targets.GetElevation();

    _worldPacket << uint32(0); // Ammo DisplayID
    _worldPacket << uint8(0);  // Ammo InventoryType
    
    _worldPacket << uint8(0);  // DestLocSpellCastIndex

    uint32 TargetPoints = 0;
    _worldPacket << TargetPoints;

    _worldPacket << uint32(0); // CreatureImmunities School
    _worldPacket << uint32(0); // CreatureImmunities Value
    
    _worldPacket << uint32(0); // SpellHealPrediction Points
    _worldPacket << uint8(0); // SpellHealPrediction Type
    ObjectGuid BeaconGUID;
    _worldPacket << BeaconGUID; // SpellHealPrediction BeaconGUID

    /*for (uint32 i = 0; i < HitTargets; ++i)
    {
        ObjectGuid HitTargetGUID;
        _worldPacket << HitTargetGUID;
    }
    for (uint32 i = 0; i < MissTargets; ++i)
    {
        ObjectGuid MissTargetGUID;
        _worldPacket << MissTargetGUID;
    }
    for (uint32 i = 0; i < MissStatus; ++i)
    {
        _worldPacket.ResetBitPos();
        uint32 MissReason = 0;
        _worldPacket.WriteBits(MissReason, 4);
        uint32 ReflectStatus = 0;
        if (MissReason == 11)
            _worldPacket.WriteBits(ReflectStatus, 4);
    }
    for (uint32 i = 0; i < SpellPowerData; ++i)
    {
        //uint32 Cost
        //uint8 PowerType
    }
    for (uint32 i = 0; i < TargetPoints; ++i)
    {
        //Transport Guid
        //XYZ
    }*/

    _worldPacket.ResetBitPos();

    _worldPacket.WriteBits(0, 18); // CastFlagsEx

    bool HasRuneData = false;
    bool HasProjectileVisual = false;
    
    _worldPacket.WriteBit(HasRuneData);
    _worldPacket.WriteBit(HasProjectileVisual);

    /*if (HasRuneData)
    {
        _worldPacket << uint8(0); // Start
        _worldPacket << uint8(0); // Count
        _worldPacket.ResetBitPos();

        uint32 CooldownCount = 0;
        _worldPacket.WriteBits(CooldownCount, 3);
        for (uint32 i = 0; i < CooldownCount; ++i)
        {
            _worldPacket << uint8(0); // Cooldowns
        }
    }*/

    /*if (HasProjectileVisual)
    {
        for (uint32 i = 0; i < 2; ++i)
        {
            _worldPacket << uint32(0); // Id
        }
    }*/

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
