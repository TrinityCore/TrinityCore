/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "Player.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "Unit.h"

void WorldPackets::Spells::SpellCastLogData::Initialize(Unit const* unit)
{
    Health = unit->GetHealth();
    AttackPower = unit->GetTotalAttackPowerValue(unit->getClass() == CLASS_HUNTER ? RANGED_ATTACK : BASE_ATTACK);
    SpellPower = unit->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_SPELL);
    PowerData.emplace_back(int32(unit->GetPowerType()), unit->GetPower(unit->GetPowerType()), int32(0));
}

void WorldPackets::Spells::SpellCastLogData::Initialize(Spell const* spell)
{
    Health = spell->GetCaster()->GetHealth();
    AttackPower = spell->GetCaster()->GetTotalAttackPowerValue(spell->GetCaster()->getClass() == CLASS_HUNTER ? RANGED_ATTACK : BASE_ATTACK);
    SpellPower = spell->GetCaster()->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_SPELL);
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
        bool SandboxScalingData::GenerateDataForUnits(T* /*attacker*/, U* /*target*/)
        {
            return false;
        }

        template<>
        bool SandboxScalingData::GenerateDataForUnits<Creature, Player>(Creature* attacker, Player* target)
        {
            CreatureTemplate const* creatureTemplate = attacker->GetCreatureTemplate();

            Type = TYPE_CREATURE_TO_PLAYER_DAMAGE;
            PlayerLevelDelta = target->GetInt32Value(PLAYER_FIELD_SCALING_PLAYER_LEVEL_DELTA);
            PlayerItemLevel = target->GetAverageItemLevel();
            TargetLevel = target->getLevel();
            Expansion = creatureTemplate->RequiredExpansion;
            Class = creatureTemplate->unit_class;
            TargetMinScalingLevel = uint8(creatureTemplate->levelScaling->MinLevel);
            TargetMaxScalingLevel = uint8(creatureTemplate->levelScaling->MaxLevel);
            TargetScalingLevelDelta = int8(creatureTemplate->levelScaling->DeltaLevel);
            return true;
        }

        template<>
        bool SandboxScalingData::GenerateDataForUnits<Player, Creature>(Player* attacker, Creature* target)
        {
            CreatureTemplate const* creatureTemplate = target->GetCreatureTemplate();

            Type = TYPE_PLAYER_TO_CREATURE_DAMAGE;
            PlayerLevelDelta = attacker->GetInt32Value(PLAYER_FIELD_SCALING_PLAYER_LEVEL_DELTA);
            PlayerItemLevel = attacker->GetAverageItemLevel();
            TargetLevel = target->getLevel();
            Expansion = creatureTemplate->RequiredExpansion;
            Class = creatureTemplate->unit_class;
            TargetMinScalingLevel = uint8(creatureTemplate->levelScaling->MinLevel);
            TargetMaxScalingLevel = uint8(creatureTemplate->levelScaling->MaxLevel);
            TargetScalingLevelDelta = int8(creatureTemplate->levelScaling->DeltaLevel);
            return true;
        }

        template<>
        bool SandboxScalingData::GenerateDataForUnits<Creature, Creature>(Creature* attacker, Creature* target)
        {
            CreatureTemplate const* creatureTemplate = target->HasScalableLevels() ? target->GetCreatureTemplate() : attacker->GetCreatureTemplate();

            Type = TYPE_CREATURE_TO_CREATURE_DAMAGE;
            PlayerLevelDelta = 0;
            PlayerItemLevel = 0;
            TargetLevel = target->getLevel();
            Expansion = creatureTemplate->RequiredExpansion;
            Class = creatureTemplate->unit_class;
            TargetMinScalingLevel = uint8(creatureTemplate->levelScaling->MinLevel);
            TargetMaxScalingLevel = uint8(creatureTemplate->levelScaling->MaxLevel);
            TargetScalingLevelDelta = int8(creatureTemplate->levelScaling->DeltaLevel);
            return true;
        }

        template<>
        bool SandboxScalingData::GenerateDataForUnits<Unit, Unit>(Unit* attacker, Unit* target)
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
