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
#include "DB2Stores.h"
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
            PowerData.emplace_back(int32(cost.Power), unitCaster->GetPower(Powers(cost.Power)), int32(cost.Amount));
            if (cost.Power == primaryPowerType)
                primaryPowerAdded = true;
        }

        if (!primaryPowerAdded)
            PowerData.emplace(PowerData.begin(), int32(primaryPowerType), unitCaster->GetPower(primaryPowerType), 0);
    }
}

template<class T, class U>
bool ContentTuningParams::GenerateDataForUnits(T* /*attacker*/, U* /*target*/)
{
    return false;
}

template<>
bool ContentTuningParams::GenerateDataForUnits<Creature, Player>(Creature* attacker, Player* target)
{
    CreatureTemplate const* creatureTemplate = attacker->GetCreatureTemplate();
    CreatureDifficulty const* creatureDifficulty = creatureTemplate->GetDifficulty(attacker->GetMap()->GetDifficultyID());

    Type = TYPE_CREATURE_TO_PLAYER_DAMAGE;
    PlayerLevelDelta = target->m_activePlayerData->ScalingPlayerLevelDelta;
    PlayerItemLevel = target->GetAverageItemLevel();
    TargetItemLevel = 0;
    if (ContentTuningEntry const* contentTuning = sContentTuningStore.LookupEntry(creatureDifficulty->ContentTuningID))
    {
        ScalingHealthItemLevelCurveID = contentTuning->HealthItemLevelCurveID;
        TargetContentTuningID = contentTuning->ID;
    }
    TargetLevel = target->GetLevel();
    Expansion = creatureDifficulty->HealthScalingExpansion;
    TargetScalingLevelDelta = int8(attacker->m_unitData->ScalingLevelDelta);
    return true;
}

template<>
bool ContentTuningParams::GenerateDataForUnits<Player, Creature>(Player* attacker, Creature* target)
{
    CreatureTemplate const* creatureTemplate = target->GetCreatureTemplate();
    CreatureDifficulty const* creatureDifficulty = creatureTemplate->GetDifficulty(target->GetMap()->GetDifficultyID());

    Type = TYPE_PLAYER_TO_CREATURE_DAMAGE;
    PlayerLevelDelta = attacker->m_activePlayerData->ScalingPlayerLevelDelta;
    PlayerItemLevel = attacker->GetAverageItemLevel();
    TargetItemLevel = 0;
    if (ContentTuningEntry const* contentTuning = sContentTuningStore.LookupEntry(creatureDifficulty->ContentTuningID))
    {
        ScalingHealthItemLevelCurveID = contentTuning->HealthItemLevelCurveID;
        TargetContentTuningID = contentTuning->ID;
    }
    TargetLevel = target->GetLevel();
    Expansion = creatureDifficulty->HealthScalingExpansion;
    TargetScalingLevelDelta = int8(target->m_unitData->ScalingLevelDelta);
    return true;
}

template<>
bool ContentTuningParams::GenerateDataForUnits<Creature, Creature>(Creature* attacker, Creature* target)
{
    Creature* accessor = target->HasScalableLevels() ? target : attacker;
    CreatureTemplate const* creatureTemplate = accessor->GetCreatureTemplate();
    CreatureDifficulty const* creatureDifficulty = creatureTemplate->GetDifficulty(accessor->GetMap()->GetDifficultyID());

    Type = TYPE_CREATURE_TO_CREATURE_DAMAGE;
    PlayerLevelDelta = 0;
    PlayerItemLevel = 0;
    TargetLevel = target->GetLevel();
    Expansion = creatureDifficulty->HealthScalingExpansion;
    TargetScalingLevelDelta = int8(accessor->m_unitData->ScalingLevelDelta);
    TargetContentTuningID = creatureDifficulty->ContentTuningID;
    return true;
}

template<>
bool ContentTuningParams::GenerateDataForUnits<Unit, Unit>(Unit* attacker, Unit* target)
{
    if (Player* playerAttacker = Object::ToPlayer(attacker))
    {
        if (Player* playerTarget = Object::ToPlayer(target))
            return GenerateDataForUnits(playerAttacker, playerTarget);
        else if (Creature* creatureTarget = Object::ToCreature(target))
        {
            if (creatureTarget->HasScalableLevels())
                return GenerateDataForUnits(playerAttacker, creatureTarget);
        }
    }
    else if (Creature* creatureAttacker = Object::ToCreature(attacker))
    {
        if (Player* playerTarget = Object::ToPlayer(target))
        {
            if (creatureAttacker->HasScalableLevels())
                return GenerateDataForUnits(creatureAttacker, playerTarget);
        }
        else if (Creature* creatureTarget = Object::ToCreature(target))
        {
            if (creatureAttacker->HasScalableLevels() || creatureTarget->HasScalableLevels())
                return GenerateDataForUnits(creatureAttacker, creatureTarget);
        }
    }

    return false;
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
        data << int32(powerData.PowerType);
        data << int32(powerData.Amount);
        data << int32(powerData.Cost);
    }

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, ContentTuningParams const& contentTuningParams)
{
    data << float(contentTuningParams.PlayerItemLevel);
    data << float(contentTuningParams.TargetItemLevel);
    data << int16(contentTuningParams.PlayerLevelDelta);
    data << uint32(contentTuningParams.ScalingHealthItemLevelCurveID);
    data << uint8(contentTuningParams.TargetLevel);
    data << uint8(contentTuningParams.Expansion);
    data << int8(contentTuningParams.TargetScalingLevelDelta);
    data << uint32(contentTuningParams.Flags);
    data << int32(contentTuningParams.PlayerContentTuningID);
    data << int32(contentTuningParams.TargetContentTuningID);
    data << int32(contentTuningParams.Unused927);
    data.WriteBits(contentTuningParams.Type, 4);
    data.FlushBits();
    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, SpellCastVisual& visual)
{
    data >> visual.SpellXSpellVisualID;
    data >> visual.ScriptVisualID;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellCastVisual const& visual)
{
    data << int32(visual.SpellXSpellVisualID);
    data << int32(visual.ScriptVisualID);

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
