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

void WorldPackets::Spells::SpellCastLogData::Initialize(Unit const* unit)
{
    Health = unit->GetHealth();
    AttackPower = unit->GetTotalAttackPowerValue(unit->getClass() == CLASS_HUNTER ? RANGED_ATTACK : BASE_ATTACK);
    SpellPower = unit->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_SPELL);
    Armor = unit->GetArmor();
    PowerData.emplace_back(int32(unit->GetPowerType()), unit->GetPower(unit->GetPowerType()), int32(0));
}

void WorldPackets::Spells::SpellCastLogData::Initialize(Spell const* spell)
{
    Health = spell->GetCaster()->GetHealth();
    AttackPower = spell->GetCaster()->GetTotalAttackPowerValue(spell->GetCaster()->getClass() == CLASS_HUNTER ? RANGED_ATTACK : BASE_ATTACK);
    SpellPower = spell->GetCaster()->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_SPELL);
    Armor = spell->GetCaster()->GetArmor();
    Powers primaryPowerType = spell->GetCaster()->GetPowerType();
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

namespace WorldPackets
{
    namespace Spells
    {
        template<class T, class U>
        bool ContentTuningParams::GenerateDataForUnits(T* /*attacker*/, U* /*target*/)
        {
            return false;
        }

        template<>
        bool ContentTuningParams::GenerateDataForUnits<Creature, Player>(Creature* attacker, Player* target)
        {
            CreatureTemplate const* creatureTemplate = attacker->GetCreatureTemplate();
            CreatureLevelScaling const* creatureScaling = creatureTemplate->GetLevelScaling(attacker->GetMap()->GetDifficultyID());

            Type = TYPE_CREATURE_TO_PLAYER_DAMAGE;
            PlayerLevelDelta = target->m_activePlayerData->ScalingPlayerLevelDelta;
            PlayerItemLevel = target->GetAverageItemLevel();
            TargetItemLevel = 0;
            ScalingHealthItemLevelCurveID = target->m_unitData->ScalingHealthItemLevelCurveID;
            TargetLevel = target->getLevel();
            Expansion = creatureTemplate->HealthScalingExpansion;
            TargetMinScalingLevel = uint8(creatureScaling->MinLevel);
            TargetMaxScalingLevel = uint8(creatureScaling->MaxLevel);
            TargetScalingLevelDelta = int8(attacker->m_unitData->ScalingLevelDelta);
            return true;
        }

        template<>
        bool ContentTuningParams::GenerateDataForUnits<Player, Creature>(Player* attacker, Creature* target)
        {
            CreatureTemplate const* creatureTemplate = target->GetCreatureTemplate();
            CreatureLevelScaling const* creatureScaling = creatureTemplate->GetLevelScaling(target->GetMap()->GetDifficultyID());

            Type = TYPE_PLAYER_TO_CREATURE_DAMAGE;
            PlayerLevelDelta = attacker->m_activePlayerData->ScalingPlayerLevelDelta;
            PlayerItemLevel = attacker->GetAverageItemLevel();
            TargetItemLevel = 0;
            ScalingHealthItemLevelCurveID = target->m_unitData->ScalingHealthItemLevelCurveID;
            TargetLevel = target->getLevel();
            Expansion = creatureTemplate->HealthScalingExpansion;
            TargetMinScalingLevel = uint8(creatureScaling->MinLevel);
            TargetMaxScalingLevel = uint8(creatureScaling->MaxLevel);
            TargetScalingLevelDelta = int8(target->m_unitData->ScalingLevelDelta);
            return true;
        }

        template<>
        bool ContentTuningParams::GenerateDataForUnits<Creature, Creature>(Creature* attacker, Creature* target)
        {
            Creature* accessor = target->HasScalableLevels() ? target : attacker;
            CreatureTemplate const* creatureTemplate = accessor->GetCreatureTemplate();
            CreatureLevelScaling const* creatureScaling = creatureTemplate->GetLevelScaling(accessor->GetMap()->GetDifficultyID());

            Type = TYPE_CREATURE_TO_CREATURE_DAMAGE;
            PlayerLevelDelta = 0;
            PlayerItemLevel = 0;
            TargetLevel = target->getLevel();
            Expansion = creatureTemplate->HealthScalingExpansion;
            TargetMinScalingLevel = uint8(creatureScaling->MinLevel);
            TargetMaxScalingLevel = uint8(creatureScaling->MaxLevel);
            TargetScalingLevelDelta = int8(accessor->m_unitData->ScalingLevelDelta);
            return true;
        }

        template<>
        bool ContentTuningParams::GenerateDataForUnits<Unit, Unit>(Unit* attacker, Unit* target)
        {
            if (Player* playerAttacker = attacker->ToPlayer())
            {
                if (Player* playerTarget = target->ToPlayer())
                    return GenerateDataForUnits(playerAttacker, playerTarget);
                else if (Creature* creatureTarget = target->ToCreature())
                {
                    if (creatureTarget->HasScalableLevels())
                        return GenerateDataForUnits(playerAttacker, creatureTarget);
                }
            }
            else if (Creature* creatureAttacker = attacker->ToCreature())
            {
                if (Player* playerTarget = target->ToPlayer())
                {
                    if (creatureAttacker->HasScalableLevels())
                        return GenerateDataForUnits(creatureAttacker, playerTarget);
                }
                else if (Creature* creatureTarget = target->ToCreature())
                {
                    if (creatureAttacker->HasScalableLevels() || creatureTarget->HasScalableLevels())
                        return GenerateDataForUnits(creatureAttacker, creatureTarget);
                }
            }

            return false;
        }
    }
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
    data << int32(spellCastLogData.Armor);
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

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::ContentTuningParams const& contentTuningParams)
{
    data << int16(contentTuningParams.PlayerLevelDelta);
    data << uint16(contentTuningParams.PlayerItemLevel);
    data << uint16(contentTuningParams.TargetItemLevel);
    data << uint16(contentTuningParams.ScalingHealthItemLevelCurveID);
    data << uint8(contentTuningParams.TargetLevel);
    data << uint8(contentTuningParams.Expansion);
    data << uint8(contentTuningParams.TargetMinScalingLevel);
    data << uint8(contentTuningParams.TargetMaxScalingLevel);
    data << int8(contentTuningParams.TargetScalingLevelDelta);
    data.WriteBits(contentTuningParams.Type, 4);
    data.WriteBit(contentTuningParams.ScalesWithItemLevel);
    data.FlushBits();
    return data;
}
