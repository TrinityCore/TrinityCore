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

WorldPacket const* WorldPackets::Spell::CategoryCooldown::Write()
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

WorldPacket const* WorldPackets::Spell::SendKnownSpells::Write()
{
    _worldPacket.reserve(1 + 4 * KnownSpells.size());

    _worldPacket.WriteBit(InitialLogin);
    _worldPacket << uint32(KnownSpells.size());

    for (uint32 spellId : KnownSpells)
        _worldPacket << uint32(spellId);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spell::UpdateActionButtons::Write()
{
    for (uint32 i = 0; i < MAX_ACTION_BUTTONS; ++i)
        _worldPacket << ActionButtons[i];

    _worldPacket << Reason;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Spell::SendUnlearnSpells::Write()
{
    _worldPacket << uint32(Spells.size());
    for (uint32 spellId : Spells)
        _worldPacket << uint32(spellId);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spell::SpellCastLogData& spellCastLogData)
{
    data << spellCastLogData.Health;
    data << spellCastLogData.AttackPower;
    data << spellCastLogData.SpellPower;
    data << int32(spellCastLogData.PowerData.size());
    for (WorldPackets::Spell::SpellLogPowerData const& powerData : spellCastLogData.PowerData)
    {
        data << powerData.PowerType;
        data << powerData.Amount;
    }
    data.WriteBit(false);
    // data << float // Unk data if bit is true
    data.FlushBits();

    return data;
}

WorldPacket const* WorldPackets::Spell::SendAuraUpdate::Write()
{
    return &_worldPacket;
}

void WorldPackets::Spell::SendAuraUpdate::Init(bool IsFullUpdate, ObjectGuid Target, uint32 Count)
{
    _worldPacket.WriteBit(IsFullUpdate);
    _worldPacket << Target;
    _worldPacket << uint32(Count);
}

void WorldPackets::Spell::SendAuraUpdate::BuildUpdatePacket(AuraApplication* aurApp, bool remove, uint16 level)
{
    _worldPacket << uint8(aurApp->GetSlot());
    _worldPacket.ResetBitPos();
    _worldPacket.WriteBit(!remove);

    if (remove)
        return;

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
