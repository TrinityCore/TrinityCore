/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "CombatLogPacketsCommon.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "Unit.h"

void WorldPackets::Spells::SpellCastLogData::Initialize(Unit const* unit)
{
    Health = unit->GetHealth();
    AttackPower = unit->GetTotalAttackPowerValue(unit->getClass() == CLASS_HUNTER ? RANGED_ATTACK : BASE_ATTACK);
    SpellPower = unit->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_SPELL);
    PowerData.emplace_back(int32(unit->getPowerType()), unit->GetPower(unit->getPowerType()), int32(0));
}

void WorldPackets::Spells::SpellCastLogData::Initialize(Spell const* spell)
{
    Health = spell->GetCaster()->GetHealth();
    AttackPower = spell->GetCaster()->GetTotalAttackPowerValue(spell->GetCaster()->getClass() == CLASS_HUNTER ? RANGED_ATTACK : BASE_ATTACK);
    SpellPower = spell->GetCaster()->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_SPELL);
    Powers primaryPowerType = spell->GetCaster()->getPowerType();
    bool primaryPowerAdded = false;
    for (SpellPowerCost const& cost : spell->GetPowerCost())
    {
        PowerData.emplace_back(int32(cost.Power), spell->GetCaster()->GetPower(Powers(cost.Power)), int32(cost.Amount));
        if (cost.Power == primaryPowerType)
            primaryPowerAdded = true;
    }

    if (!primaryPowerAdded)
        PowerData.insert(PowerData.begin(), SpellLogPowerData(int32(primaryPowerType), spell->GetCaster()->GetPower(primaryPowerType), 0));
}

ByteBuffer& WorldPackets::CombatLog::CombatLogServerPacket::WriteLogData()
{
    return _fullLogPacket << LogData;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellCastLogData const& spellCastLogData)
{
    data << int64(spellCastLogData.Health);
    data << int32(spellCastLogData.AttackPower);
    data << int32(spellCastLogData.SpellPower);
    data.WriteBits(spellCastLogData.PowerData.size(), 9);
    data.FlushBits();

    for (WorldPackets::Spells::SpellLogPowerData const& powerData : spellCastLogData.PowerData)
    {
        data << int32(powerData.PowerType);
        data << int32(powerData.Amount);
        data << int32(powerData.Cost);
    }

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SandboxScalingData const& sandboxScalingData)
{
    data.WriteBits(sandboxScalingData.Type, 3);
    data << int16(sandboxScalingData.PlayerLevelDelta);
    data << uint16(sandboxScalingData.PlayerItemLevel);
    data << uint8(sandboxScalingData.TargetLevel);
    data << uint8(sandboxScalingData.Expansion);
    data << uint8(sandboxScalingData.Class);
    data << uint8(sandboxScalingData.TargetMinScalingLevel);
    data << uint8(sandboxScalingData.TargetMaxScalingLevel);
    data << int8(sandboxScalingData.TargetScalingLevelDelta);
    return data;
}
