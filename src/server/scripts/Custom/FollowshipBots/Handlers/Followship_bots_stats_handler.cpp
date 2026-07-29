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

#include "Log.h"
#include "ObjectMgr.h"
#include "DB2Stores.h"
#include "GameTables.h"
#include "SpellAuraEffects.h"

#include "Followship_bots_config.h"
#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"

#include "Followship_bots_powers_handler.h"
#include "Followship_bots_stats_handler.h"

namespace FSBStats
{
    // Get (base) stats for bot depending on class
    FSB_ClassStats const* GetBotClassStats(FSB_Class botClass)
    {
        for (auto const& entry : BotClassStatsTable)
        {
            if (entry.classId == botClass)
                return &entry;
        }

        return nullptr;
    }

    void ApplyBotBaseClassStats(Creature* bot, FSB_Class botClass)
    {
        auto const* stats = GetBotClassStats(botClass);
        if (!stats)
            return;

        bot->SetClass(FSBUtils::FSBToTCClass(botClass));

        // Health
        ApplyBotHealth(bot, botClass, true);        

        // Power
        ApplyBotPower(bot, botClass, true);

        // Attack Power
        ApplyBotAttackPower(bot, botClass);

        // Damage
        bot->SetBaseAttackTime(BASE_ATTACK, stats->baseAttackTime);
        bot->SetBaseAttackTime(RANGED_ATTACK, stats->baseRangedAttackTime);
        ApplyBotDamage(bot, botClass);

        // Armor
        ApplyBotArmor(bot, botClass);
    }

    void ApplyBotHealth(Creature* bot, FSB_Class botClass, bool updateHealth)
    {
        if (!bot)
            return;

        auto const* stats = GetBotClassStats(botClass);
        if (!stats)
            return;

        int32 level = bot->GetLevel();
        float modifier = FollowshipBotsConfig::configFSBHealthRate;

        // Get player-level stats using core's PlayerLevelInfo
        FSB_Race botRace = FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry());
        Races tcRace = FSBUtils::BotRaceToTC(botRace);
        Classes tcClass = FSBUtils::FSBToTCClass(botClass);

        PlayerLevelInfo levelInfo;
        sObjectMgr->GetPlayerLevelInfo(tcRace, tcClass, level, &levelInfo);

        // Use stamina from PlayerLevelInfo to calculate health
        float stamina = levelInfo.stats[STAT_STAMINA];
        
        // Get HP per stamina ratio from game table (varies by level)
        float hpPerStamina = 10.0f;
        if (GtHpPerStaEntry const* hpBase = sHpPerStaGameTable.GetRow(level))
            hpPerStamina = hpBase->Health;

        // Calculate health bonus from stamina (same as Player::GetHealthBonusFromStamina)
        float healthFromStamina = stamina * hpPerStamina;

        // Add base health from config and apply modifier
        uint32 baseHealth = ((float)stats->baseHealth + healthFromStamina) * modifier;
        
        bot->SetStatFlatModifier(UNIT_MOD_HEALTH, BASE_VALUE, baseHealth);
        float totalHealth = bot->GetTotalAuraModValue(UNIT_MOD_HEALTH);

        bot->SetCreateHealth(baseHealth);
        bot->SetMaxHealth(uint32(totalHealth));

        if(updateHealth)
            bot->SetHealth(uint32(totalHealth));

        //TC_LOG_DEBUG("scripts.ai.fsb", "FSB: Bot {} statsHandler health base: {}, total: {}, stamina: {}, hpPerSta: {}", 
        //    bot->GetName(), baseHealth, totalHealth, stamina, hpPerStamina);
    }

    void ApplyBotPower(Creature* bot, FSB_Class botClass, bool updatePower)
    {
        if (!bot)
            return;

        auto const* stats = GetBotClassStats(botClass);
        if (!stats)
            return;

        int32 level = bot->GetLevel();

        float modifier = FollowshipBotsConfig::configFSBPowerRate;

        Powers basePowerType = stats->powerType;
        
        // Get base mana from core's GetPlayerClassLevelInfo (uses GtBaseMPEntry game table)
        Classes tcClass = FSBUtils::FSBToTCClass(botClass);
        uint32 baseMana = 0;
        sObjectMgr->GetPlayerClassLevelInfo(tcClass, level, baseMana);
        
        uint32 basePower = baseMana * modifier;

        if (FSBPowers::IsRageUser(bot))
        {
            basePowerType = POWER_RAGE;
            basePower = 1000;
        }

        if (FSBPowers::IsEnergyUser(bot))
        {
            basePowerType = POWER_ENERGY;
            basePower = 100;
        }

        if (FSBPowers::IsFocusUser(bot))
        {
            basePowerType = POWER_FOCUS;
            basePower = 100;
        }

        bot->SetPowerType(basePowerType, true);

        bot->SetStatFlatModifier(UnitMods(UNIT_MOD_POWER_START + AsUnderlyingType(basePowerType)), BASE_VALUE, (float)basePower);
        bot->SetCreateMana(0);
        float totalPower = bot->GetTotalAuraModValue(UnitMods(UNIT_MOD_POWER_START + AsUnderlyingType(basePowerType)));
        bot->SetMaxPower(basePowerType, totalPower);
            

        if (updatePower)
        {
            if (!FSBPowers::IsRageUser(bot))
                bot->SetPower(basePowerType, totalPower, true);
        }
        else bot->SetPower(basePowerType, bot->GetPower(basePowerType), true);
    }

    void ApplyBotAttackPower(Creature* bot, FSB_Class botClass)
    {
        if (!bot)
            return;

        auto const* stats = GetBotClassStats(botClass);
        if (!stats)
            return;

        int32 level = bot->GetLevel();

        // Get player-level stats using core's PlayerLevelInfo
        FSB_Race botRace = FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry());
        Races tcRace = FSBUtils::BotRaceToTC(botRace);
        Classes tcClass = FSBUtils::FSBToTCClass(botClass);

        PlayerLevelInfo levelInfo;
        sObjectMgr->GetPlayerLevelInfo(tcRace, tcClass, level, &levelInfo);

        // Get class-specific stat multipliers from ChrClassesEntry
        ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(tcClass);
        if (!classEntry)
        {
            TC_LOG_ERROR("scripts.fsb.stats", "FSB: ApplyBotAttackPower - Failed to get ChrClassesEntry for class {}", tcClass);
            return;
        }
        
        // Calculate attack power from stats (same as Player::UpdateAttackPowerAndDamage)
        float strength = levelInfo.stats[STAT_STRENGTH];
        float agility = levelInfo.stats[STAT_AGILITY];
        
        float strengthValue = std::max(strength * classEntry->AttackPowerPerStrength, 0.0f);
        float agilityValue = std::max(agility * classEntry->AttackPowerPerAgility, 0.0f);
        
        uint32 finalAP = uint32(strengthValue + agilityValue);
        uint32 finalRAP = uint32(agilityValue * classEntry->RangedAttackPowerPerAgility);

        bot->SetBaseAttackPower(finalAP);
        bot->SetBaseRangedAttackPower(finalRAP);
        bot->UpdateAttackPowerAndDamage();
        bot->UpdateAttackPowerAndDamage(true);

        //TC_LOG_DEBUG("scripts.ai.fsb", "FSB: Stats AttackPower Bot: {} Has STR: {}, AGI: {}, AP: {}, RAP: {}",
        //    bot->GetName(), strength, agility, finalAP, finalRAP);
    }

    void ApplyBotDamage(Creature* bot, FSB_Class botClass)
    {
        if (!bot)
            return;

        auto const* stats = GetBotClassStats(botClass);
        if (!stats)
            return;

        float modifier = FollowshipBotsConfig::configFSBDamageRate;

        bot->SetDamageModifier(1.0f);

        int32 level = bot->GetLevel();
        float basedamage = stats->baseDamagePerLevel * float(level) * stats->baseClassDamageVariance * modifier;

        float weaponBaseMinDamage = basedamage;
        float weaponBaseMaxDamage = weaponBaseMinDamage * 1.5f;

        bot->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, weaponBaseMinDamage);
        bot->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, weaponBaseMaxDamage);

        bot->SetBaseWeaponDamage(OFF_ATTACK, MINDAMAGE, weaponBaseMinDamage);
        bot->SetBaseWeaponDamage(OFF_ATTACK, MAXDAMAGE, weaponBaseMaxDamage);

        bot->SetBaseWeaponDamage(RANGED_ATTACK, MINDAMAGE, weaponBaseMinDamage);
        bot->SetBaseWeaponDamage(RANGED_ATTACK, MAXDAMAGE, weaponBaseMaxDamage);

        bot->UpdateDamagePhysical(RANGED_ATTACK);
        bot->UpdateDamagePhysical(BASE_ATTACK);
        bot->UpdateDamagePhysical(OFF_ATTACK);
    }

    void ApplyBotArmor(Creature* bot, FSB_Class botClass)
    {
        if (!bot)
            return;

        auto const* stats = GetBotClassStats(botClass);
        if (!stats)
            return;

        int32 level = bot->GetLevel();

        // Get player-level stats from core (same pattern as ApplyBotHealth/AttackPower)
        FSB_Race botRace = FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry());
        Races tcRace = FSBUtils::BotRaceToTC(botRace);
        Classes tcClass = FSBUtils::FSBToTCClass(botClass);

        PlayerLevelInfo levelInfo;
        sObjectMgr->GetPlayerLevelInfo(tcRace, tcClass, level, &levelInfo);

        float agility = levelInfo.stats[STAT_AGILITY];

        float modifier = FollowshipBotsConfig::configFSBArmorRate;

        // 1. Base armor: agility * 2 (player model) + armorPerLevel (compensates for no items)
        float baseArmor = (agility * 2.0f + (float)(stats->armorPerLevel * level)) * modifier * stats->baseArmorVariance;
        bot->SetStatFlatModifier(UNIT_MOD_ARMOR, BASE_VALUE, baseArmor);

        // 2. Apply BASE_PCT
        UnitMods unitMod = UNIT_MOD_ARMOR;
        float value = baseArmor * bot->GetPctModifierValue(unitMod, BASE_PCT);

        // 3. SPELL_AURA_MOD_ARMOR_PCT_FROM_STAT (e.g., Guardian Druid armor from primary stat)
        ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(tcClass);
        Stats primaryStat = STAT_STRENGTH;
        if (classEntry)
        {
            if (classEntry->PrimaryStatPriority >= 4)
                primaryStat = STAT_STRENGTH;
            else if (classEntry->PrimaryStatPriority >= 2)
                primaryStat = STAT_AGILITY;
            else
                primaryStat = STAT_INTELLECT;
        }

        bot->GetTotalAuraModifier(SPELL_AURA_MOD_ARMOR_PCT_FROM_STAT, [&value, &levelInfo, primaryStat](AuraEffect const* aurEff) {
            int32 miscValue = aurEff->GetMiscValue();
            Stats stat = (miscValue != -2) ? Stats(miscValue) : primaryStat;
            value += CalculatePct(float(levelInfo.stats[stat]), aurEff->GetAmount());
            return true;
        });

        float baseValue = value;

        // 4. TOTAL_VALUE (bonus armor from auras)
        value += bot->GetFlatModifierValue(unitMod, TOTAL_VALUE);

        // 5. TOTAL_PCT
        value *= bot->GetPctModifierValue(unitMod, TOTAL_PCT);

        // 6. SPELL_AURA_MOD_BONUS_ARMOR_PCT
        value *= bot->GetTotalAuraMultiplier(SPELL_AURA_MOD_BONUS_ARMOR_PCT);

        bot->SetArmor(int32(value), int32(value - baseValue));
        //TC_LOG_DEBUG("scripts.ai.fsb", "FSB: Bot {} statsHandler armor base: {}, total: {}, agility: {}", bot->GetName(), baseValue, value, agility);
    }

    void UpdateBotLevelToPlayer(Creature* bot)
    {
        if (!bot || !bot->GetOwner())
            return;

        Player* player = bot->GetOwner()->ToPlayer();
        if (!player)
            return;

        uint8 pLevel = player->GetLevel();
        if (bot->GetLevel() == pLevel)
            return;

        bot->SetLevel(pLevel);

        RecalculateStats(bot, true, true);
    }

    void RecalculateStats(Creature* bot, bool updateHealth, bool updatePower)
    {
        if (!bot)
            return;

        FSB_Class cls = FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry());

        ApplyBotHealth(bot, cls, updateHealth);
        ApplyBotPower(bot, cls, updatePower);
        ApplyBotAttackPower(bot, cls);
        ApplyBotDamage(bot, cls);
        ApplyBotArmor(bot, cls);
    }

    int32 BotGetSpellPower(const Creature* bot)
    {
        if (!bot)
            return 0;

        FSB_Class botClass = FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry());
        uint8 level = bot->GetLevel();

        auto const* stats = GetBotClassStats(botClass);
        if (!stats)
            return 0;

        int32 baseSP = stats->baseSpellPower;
        float spPct = 1.f;
        int32 levelSP = stats->spellPowerPerLevel * (level - 1);

        if (FSB_BaseAI* ai = CAST_AI(FSB_BaseAI, bot->AI()))
        {
            spPct += ai->botStats.spellPowerPct;
        }

        int32 value = (baseSP + levelSP) * spPct;

        return value;

    }

    // This is applied in DamageTaken() so with every damage
    float ApplyBotDamageTakenReduction(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return 1.0f;

        float multiplier = 1.0f;

        if (FSBWarrior::BotHasDefensiveStance(bot))
            multiplier *= 0.85f;

        if (FSBWarrior::BotHasShieldWall(bot))
            multiplier *= 0.60f;

        if (FSBPaladin::BotHasDevotionAura(bot))
            multiplier *= 0.97f;

        if (FSBPaladin::BotHasGuardianOfAncientKings(bot))
            multiplier *= 0.50f;

        if (FSBPaladin::BotHasDivineProtection(bot))
            multiplier *= 0.80f;

        if (FSBPaladin::BotHasBlessingOfSacrifice(bot))
            multiplier *= 0.70f;

        if (FSBWarlock::BotHasUnendingResolve(bot))
            multiplier *= 0.75f;

        if (FSBDruid::BotHasMarkWild(bot))
            multiplier *= 0.985f;

        if (FSBDruid::BotHasIronbark(bot))
            multiplier *= 0.8f;

        if (FSBDruid::BotHasSurvivalInstincts(bot))
            multiplier *= 0.5f;

        if (FSBPriest::BotHasPainSuppression(bot))
            multiplier *= 0.6f;

        if (FSBMonk::BotHasFortifyingBrew(bot))
            multiplier *= 0.8f;

        return multiplier;
    }

    // This is applied in DamageDealt() so with every damage bot does
    // This method can also increase damage done > 1.f
    float ApplyBotDamageDoneReduction(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return 1.0f;

        float multiplier = 1.0f;

        if (FSBWarrior::BotHasDefensiveStance(bot))
            multiplier *= 0.90f;

        if (FSBWarrior::BotHasBattleStance(bot))
            multiplier *= 1.03f;

        if (FSBWarrior::BotHasBerserkerStance(bot))
            multiplier *= 1.15f;

        if (FSBPaladin::BotHasAvengingWrath(bot))
            multiplier *= 1.2f;

        if (FSBDruid::BotHasMarkWild(bot))
            multiplier *= 1.03f;

        return multiplier;
    }
}
