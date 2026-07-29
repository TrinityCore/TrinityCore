/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Followship_bots_defines.h"

struct FSB_ClassStats
{
    FSB_Class classId;

    Powers powerType;

    // Base stats at level 1
    uint32 baseHealth;

    // Regen (flat, before auras/mods)
    int32 baseHpRegenOOC;
    int32 basePowerRegenOOC;

    int32 baseHpRegenIC;
    int32 basePowerRegenIC;

    float baseClassDamageVariance;
    float baseDamagePerLevel;

    int32 baseAttackTime;
    int32 baseRangedAttackTime;

    int32 baseSpellPower;
    int32 spellPowerPerLevel;

    int32 armorPerLevel;
    float baseArmorVariance;
};

static constexpr FSB_ClassStats BotClassStatsTable[] =
{
    // PALADIN
    {
        .classId = FSB_Class::Paladin,
        .powerType = POWER_MANA,
        .baseHealth = 60,    // base HP
        .baseHpRegenOOC = 3,      // HP regen %
        .basePowerRegenOOC = 2,       // Power regen %
        .baseHpRegenIC = 0,
        .basePowerRegenIC = 1,
        .baseClassDamageVariance = 0.9f,
        .baseDamagePerLevel = 1.7f,
        .baseAttackTime = 2000,
        .baseRangedAttackTime = 2000,
        .baseSpellPower = 8,
        .spellPowerPerLevel = 2,
        .armorPerLevel = 4,
        .baseArmorVariance = 0.8f
    },

    // WARRIOR
    {
        .classId = FSB_Class::Warrior,
        .powerType = POWER_RAGE,
        .baseHealth = 90,    // base HP
        .baseHpRegenOOC = 5,      // HP regen %
        .basePowerRegenOOC = -2,       // Power regen %
        .baseHpRegenIC = 0,
        .basePowerRegenIC = 0,
        .baseClassDamageVariance = 0.9f,
        .baseDamagePerLevel = 2.2f,
        .baseAttackTime = 2000,
        .baseRangedAttackTime = 2000,
        .baseSpellPower = 2,
        .spellPowerPerLevel = 1,
        .armorPerLevel = 4,
        .baseArmorVariance = 0.8f
    },

    // PRIEST
    {
        .classId = FSB_Class::Priest,
        .powerType = POWER_MANA,
        .baseHealth = 50,             // base HP
        .baseHpRegenOOC = 3,              // HP regen %
        .basePowerRegenOOC = 4,              // Power regen %
        .baseHpRegenIC = 0,
        .basePowerRegenIC = 2,
        .baseClassDamageVariance = 0.2f,
        .baseDamagePerLevel = 0.7f,
        .baseAttackTime = 3500,
        .baseRangedAttackTime = 2500,
        .baseSpellPower = 8,
        .spellPowerPerLevel = 3,
        .armorPerLevel = 1,
        .baseArmorVariance = 0.2f
    },

    // WARLOCK
    {
        .classId = FSB_Class::Warlock,
        .powerType = POWER_MANA,
        .baseHealth = 50,             // base HP
        .baseHpRegenOOC = 3,              // HP regen %
        .basePowerRegenOOC = 4,              // Power regen %
        .baseHpRegenIC = 0,
        .basePowerRegenIC = 2,
        .baseClassDamageVariance = 0.2f,
        .baseDamagePerLevel = 0.7f,
        .baseAttackTime = 3500,
        .baseRangedAttackTime = 2500,
        .baseSpellPower = 9,
        .spellPowerPerLevel = 4,
        .armorPerLevel = 1,
        .baseArmorVariance = 0.2f
    },

    // MAGE
    {
        .classId = FSB_Class::Mage,
        .powerType = POWER_MANA,
        .baseHealth = 50,
        .baseHpRegenOOC = 2,
        .basePowerRegenOOC = 6,
        .baseHpRegenIC = 0,
        .basePowerRegenIC = 2,
        .baseClassDamageVariance = 0.2f,
        .baseDamagePerLevel = 0.7f,
        .baseAttackTime = 3500,
        .baseRangedAttackTime = 2500,
        .baseSpellPower = 10,
        .spellPowerPerLevel = 5,
        .armorPerLevel = 1,
        .baseArmorVariance = 0.2f
    },

    // MONK
    {
        .classId = FSB_Class::Monk,
        .powerType = POWER_MANA,
        .baseHealth = 60,
        .baseHpRegenOOC = 3,
        .basePowerRegenOOC = 5,
        .baseHpRegenIC = 0,
        .basePowerRegenIC = 2,
        .baseClassDamageVariance = 1.f,
        .baseDamagePerLevel = 2.0f,
        .baseAttackTime = 2000,
        .baseRangedAttackTime = 2500,
        .baseSpellPower = 8,
        .spellPowerPerLevel = 3,
        .armorPerLevel = 2,
        .baseArmorVariance = 0.4f
    },

    // DRUID
    {
        .classId = FSB_Class::Druid,
        .powerType = POWER_MANA,
        .baseHealth = 60,
        .baseHpRegenOOC = 3,
        .basePowerRegenOOC = 5,
        .baseHpRegenIC = 0,
        .basePowerRegenIC = 2,
        .baseClassDamageVariance = 0.7f,
        .baseDamagePerLevel = 1.5f,
        .baseAttackTime = 2000,
        .baseRangedAttackTime = 2500,
        .baseSpellPower = 8,
        .spellPowerPerLevel = 3,
        .armorPerLevel = 2,
        .baseArmorVariance = 0.4f
    },

    // ROGUE
    {
        .classId = FSB_Class::Rogue,
        .powerType = POWER_ENERGY,
        .baseHealth = 60,
        .baseHpRegenOOC = 3,
        .basePowerRegenOOC = 10,
        .baseHpRegenIC = 0,
        .basePowerRegenIC = 10,
        .baseClassDamageVariance = 1.2f,
        .baseDamagePerLevel = 1.8f,
        .baseAttackTime = 1500,
        .baseRangedAttackTime = 2500,
        .baseSpellPower = 1,
        .spellPowerPerLevel = 1,
        .armorPerLevel = 2,
        .baseArmorVariance = 0.4f
    },

    // HUNTER
    {
        .classId = FSB_Class::Hunter,
        .powerType = POWER_FOCUS,
        .baseHealth = 80,
        .baseHpRegenOOC = 3,
        .basePowerRegenOOC = 5,
        .baseHpRegenIC = 0,
        .basePowerRegenIC = 5,
        .baseClassDamageVariance = 1.f,
        .baseDamagePerLevel = 1.4f,
        .baseAttackTime = 2500,
        .baseRangedAttackTime = 2000,
        .baseSpellPower = 1,
        .spellPowerPerLevel = 1,
        .armorPerLevel = 3,
        .baseArmorVariance = 0.6f
    },

    // SHAMAN
    {
        .classId = FSB_Class::Shaman,
        .powerType = POWER_MANA,
        .baseHealth = 50,    // base HP
        .baseHpRegenOOC = 3,      // HP regen %
        .basePowerRegenOOC = 2,       // Power regen %
        .baseHpRegenIC = 0,
        .basePowerRegenIC = 1,
        .baseClassDamageVariance = 0.9f,
        .baseDamagePerLevel = 1.5f,
        .baseAttackTime = 2000,
        .baseRangedAttackTime = 2000,
        .baseSpellPower = 2,
        .spellPowerPerLevel = 4,
        .armorPerLevel = 3,
        .baseArmorVariance = 0.6f
    },
};

namespace FSBStats
{
    FSB_ClassStats const* GetBotClassStats(FSB_Class botClass);
    void ApplyBotBaseClassStats(Creature* creature, FSB_Class botClass);

    void ApplyBotHealth(Creature* bot, FSB_Class botClass, bool updateHealth);
    void ApplyBotPower(Creature* bot, FSB_Class botClass, bool updatePower);
    void ApplyBotAttackPower(Creature* bot, FSB_Class botClass);
    void ApplyBotDamage(Creature* bot, FSB_Class botClass);
    void ApplyBotArmor(Creature* bot, FSB_Class botClass);

    float ApplyBotDamageTakenReduction(Creature* bot);
    float ApplyBotDamageDoneReduction(Creature* bot);

    void UpdateBotLevelToPlayer(Creature* bot);
    void RecalculateStats(Creature* bot, bool updateHealth, bool updatePower);

    int32 BotGetSpellPower(const Creature* bot);

}
