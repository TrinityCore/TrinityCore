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

#include "CombatLogPacketsCommon.h"
#include "Creature.h"
#include "Map.h"
#include "Player.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "Unit.h"

namespace WorldPackets
{
namespace Spells
{
void SpellCastLogData::Initialize(Unit const* unit)
{
    Health = unit->GetHealth();
    AttackPower = unit->GetTotalAttackPowerValue(unit->GetClass() == CLASS_HUNTER ? RANGED_ATTACK : BASE_ATTACK);
    SpellPower = unit->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_SPELL);
    Armor = unit->GetArmor();
    PowerData.emplace_back(int32(unit->GetPowerType()), unit->GetPower(unit->GetPowerType()), int32(0));
}

void SpellCastLogData::Initialize(Spell const* spell)
{
    if (Unit const* unitCaster = spell->GetCaster()->ToUnit())
    {
        Health = unitCaster->GetHealth();
        AttackPower = unitCaster->GetTotalAttackPowerValue(unitCaster->GetClass() == CLASS_HUNTER ? RANGED_ATTACK : BASE_ATTACK);
        SpellPower = unitCaster->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_SPELL);
        Armor = unitCaster->GetArmor();
        Powers primaryPowerType = unitCaster->GetPowerType();
        bool primaryPowerAdded = false;
        for (SpellPowerCost const& cost : spell->GetPowerCost())
        {
            PowerData.emplace_back(int8(cost.Power), unitCaster->GetPower(Powers(cost.Power)), int32(cost.Amount));
            if (cost.Power == primaryPowerType)
                primaryPowerAdded = true;
        }

        if (!primaryPowerAdded)
            PowerData.emplace(PowerData.begin(), int8(primaryPowerType), unitCaster->GetPower(primaryPowerType), 0);
    }
}

template<class T, class U>
bool ContentTuningParams::GenerateDataForUnits(T* /*attacker*/, U* /*target*/)
{
    return false;
}

template<>
bool ContentTuningParams::GenerateDataForUnits<Creature, Player>(Creature* /*attacker*/, Player* /*target*/)
{
    return true;
}

template<>
bool ContentTuningParams::GenerateDataForUnits<Player, Creature>(Player* /*attacker*/, Creature* /*target*/)
{
    return true;
}

template<>
bool ContentTuningParams::GenerateDataForUnits<Creature, Creature>(Creature* /*attacker*/, Creature* /*target*/)
{
    return true;
}

template<>
bool ContentTuningParams::GenerateDataForUnits<Unit, Unit>(Unit* /*attacker*/, Unit* /*target*/)
{
    return true;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellCastLogData const& spellCastLogData)
{
    data << int64(spellCastLogData.Health);
    data << int32(spellCastLogData.AttackPower);
    data << int32(spellCastLogData.SpellPower);
    data << int32(spellCastLogData.Armor);
    data << BitsSize<9>(spellCastLogData.PowerData);
    data.FlushBits();

    for (SpellLogPowerData const& powerData : spellCastLogData.PowerData)
    {
        data << int8(powerData.PowerType);
        data << int32(powerData.Amount);
        data << int32(powerData.Cost);
    }

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, ContentTuningParams const& contentTuningParams)
{
    data << uint16(contentTuningParams.PlayerItemLevel);
    data << int16(contentTuningParams.PlayerLevelDelta);
    data << uint32(contentTuningParams.TargetItemLevel);
    data << uint8(contentTuningParams.TargetLevel);
    data << uint8(contentTuningParams.Expansion);
    data << uint8(contentTuningParams.TargetMinScalingLevel);
    data << uint8(contentTuningParams.TargetMaxScalingLevel);
    data << int8(contentTuningParams.TargetScalingLevelDelta);
    data.WriteBits(contentTuningParams.Type, 4);
    data.WriteBits(contentTuningParams.ScalesWithItemLevel, 1);
    data.FlushBits();
    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, SpellCastVisual& visual)
{
    data >> visual.SpellXSpellVisualID;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellCastVisual const& visual)
{
    data << int32(visual.SpellXSpellVisualID);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellSupportInfo const& supportInfo)
{
    data << supportInfo.CasterGUID;
    data << int32(supportInfo.SpellID);
    data << int32(supportInfo.Amount);
    data << float(supportInfo.Percentage);

    return data;
}
}
}

ByteBuffer& WorldPackets::CombatLog::CombatLogServerPacket::WriteLogData()
{
    return _fullLogPacket << LogData;
}
