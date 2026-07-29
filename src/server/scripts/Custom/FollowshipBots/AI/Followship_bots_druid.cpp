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

#include "SpellAuras.h"
#include "Log.h"

#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"

#include "Followship_bots_group_handler.h"
#include "Followship_bots_movement_handler.h"
#include "Followship_bots_spells_handler.h"
#include "Followship_bots_stats_handler.h"

std::vector<FSBSpellDefinition> DruidSpellsTable =
{
    // Spell ID                             Spell Type              ManaCost %  HP % for heal   Chance           Dist/Range     SelfCast    Cooldown Ms     RoleMask

    // ANY
    { SPELL_HUMAN_WILL_TO_SURVIVE,          FSBSpellType::Heal,     0.f,        80.f,           100.f,           0.f,           true,       180000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_DWARF_STONEFORM,                FSBSpellType::Heal,     0.f,        80.f,           100.f,           0.f,           true,       120000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_DRAENEI_GIFT_NAARU,             FSBSpellType::Heal,     0.f,        50.f,           100.f,           30.f,          false,      120000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_PANDAREN_QUAKING_PALM,          FSBSpellType::Damage,   0.f,        0.f,            100.f,           2.f,           false,      120000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_ORC_BLOOD_FURY,                 FSBSpellType::Damage,   0.f,        0.f,            100.f,           0.f,           true,       120000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_UNDEAD_WILL_OF_FORSAKEN,        FSBSpellType::Heal,     0.f,        80.f,           100.f,           0.f,           true,        30000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_TAUREN_WAR_STOMP,               FSBSpellType::Damage,   0.f,        0.f,            100.f,           8.f,           false,       90000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_TROLL_BERSERKING,               FSBSpellType::Damage,   0.f,        0.f,            100.f,           0.f,           true,       180000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_BLOODELF_ARCANE_TORRENT,        FSBSpellType::Damage,   0.f,        0.f,            100.f,           8.f,           false,      120000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_GOBLIN_ROCKET_BARRAGE,          FSBSpellType::Damage,   0.f,        0.f,            100.f,          30.f,           false,       90000,         FSB_RoleMask::FSB_ROLEMASK_ANY },

    { SPELL_DRUID_WRATH,                FSBSpellType::Damage,   0.f,        0.f,            70.f,            40.f,         false,       1000,        FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_DRUID_BARKSKIN,             FSBSpellType::Heal,     0.f,        60.f,           100.f,            0.f,          true,        60000,       FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_DRUID_REGROWTH,             FSBSpellType::Heal,     0.f,        70.f,           100.f,            30.f,         false,       1000,        FSB_RoleMask::FSB_ROLEMASK_ANY },

    // TANK
    { SPELL_DRUID_REGROWTH,             FSBSpellType::Heal,     0.f,        50.f,           100.f,            0.f,         true,       36000,        FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_DRUID_SKULL_BASH,           FSBSpellType::Damage,   0.f,        0.f,            100.f,            13.f,         false,       15000,       FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_DRUID_BEAR_GROWL,           FSBSpellType::Damage,   0.f,        0.f,            100.f,            40.f,         false,       8000,        FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_DRUID_BEAR_URSOC,           FSBSpellType::Damage,   0.f,        0.f,            90.f,            2.f,          true,        180000,      FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_DRUID_BEAR_SURVIVAL_INSTINCTS,FSBSpellType::Damage, 0.f,        0.f,            90.f,            2.f,          true,        180000,      FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_DRUID_BEAR_LUNAR_BEAM,      FSBSpellType::Damage,   0.f,        0.f,            90.f,            2.f,          false,       60000,       FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_DRUID_BEAR_SUNDERING_ROAR,  FSBSpellType::Damage,   0.f,        0.f,            90.f,            2.f,          false,       60000,       FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_DRUID_BEAR_RED_MOON,        FSBSpellType::Damage,   0.f,        0.f,            90.f,            40.f,         false,       30000,       FSB_RoleMask::FSB_ROLEMASK_TANK },
    
    { SPELL_DRUID_BEAR_THRASH,          FSBSpellType::Damage,   0.f,        0.f,            80.f,             8.f,          false,       6000,        FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_DRUID_BEAR_MANGLE,          FSBSpellType::Damage,   0.f,        0.f,            80.f,             2.f,          false,       6000,        FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_DRUID_BEAR_MAUL,            FSBSpellType::Damage,   0.f,        0.f,            80.f,             2.f,          false,       1000,        FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_DRUID_BEAR_RAZE,            FSBSpellType::Damage,   0.f,        0.f,            80.f,             2.f,          false,       1000,        FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_DRUID_BEAR_INCAPACITATING_ROAR,FSBSpellType::Damage,   0.f,        0.f,            70.f,             2.f,          false,      30000,        FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_DRUID_SWIPE,                FSBSpellType::Damage,   0.f,         0.f,           50.f,            2.f,        false,       1000,        FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_DRUID_BEAR_IRONFUR,         FSBSpellType::Damage,   0.f,         0.f,           50.f,            2.f,        true,       1000,        FSB_RoleMask::FSB_ROLEMASK_TANK },

    // MELEE
    { SPELL_DRUID_SKULL_BASH,           FSBSpellType::Damage,   0.f,         0.f,            100.f,           13.f,        false,       15000,       FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_DRUID_CAT_AVATAR_ASHAMANE,  FSBSpellType::Damage,   0.f,         0.f,            90.f,            2.f,         true,        180000,      FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_DRUID_CAT_FERAL_FRENZY,     FSBSpellType::Damage,   0.25f,       0.f,            90.f,            8.f,         false,       45000,       FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_DRUID_CAT_THRASH,           FSBSpellType::Damage,   0.f,         0.f,            90.f,            8.f,         false,       6000,        FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_DRUID_CAT_SHRED,            FSBSpellType::Damage,   0.f,         0.f,            90.f,            2.5f,        false,       1000,        FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_DRUID_CAT_MANGLE,           FSBSpellType::Damage,   0.4f,        0.f,            90.f,            2.5f,        false,       6000,        FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_DRUID_CAT_FEROCIOUS_BITE,   FSBSpellType::Damage,   0.25f,       0.f,            80.f,            2.5f,        false,       6000,        FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_DRUID_CAT_PRIMAL_WRATH,     FSBSpellType::Damage,   0.f,         0.f,            80.f,            2.5f,        false,       1000,        FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_DRUID_CAT_TIGER_FURY,       FSBSpellType::Damage,   0.f,         0.f,            50.f,            2.5f,        true,        30000,        FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_DRUID_SWIPE,                FSBSpellType::Damage,   0.f,         0.f,            50.f,            2.5f,        false,       1000,        FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_DRUID_CAT_RIP,              FSBSpellType::Damage,   0.2f,        0.f,            50.f,            2.5f,        false,       1000,        FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_DRUID_CAT_RAKE,              FSBSpellType::Damage,   0.f,         0.f,            50.f,            2.5f,        false,       1000,        FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    

    // RANGED
    { SPELL_DRUID_HIBERNATE,            FSBSpellType::Damage,   0.f,        0.f,             100.f,            30.f,        false,       40000,       FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_DRUID_ROOTS,                FSBSpellType::Damage,   0.f,        0.f,             100.f,            30.f,        false,       1000,        FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_DRUID_STARFIRE,             FSBSpellType::Damage,   0.05f,      0.f,             100.f,            40.f,        false,       1000,        FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_DRUID_SOLAR_BEAM,           FSBSpellType::Damage,   0.f,        0.f,             100.f,            40.f,        false,       60000,       FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_DRUID_WILD_MUSHROOM,        FSBSpellType::Damage,   0.05f,      0.f,             100.f,            40.f,        false,       30000,       FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_DRUID_TYPHOON,              FSBSpellType::Damage,   0.f,        0.f,             80.f,            15.f,        false,       30000,       FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_DRUID_NEW_MOON,             FSBSpellType::Damage,   0.f,        0.f,             80.f,            40.f,        false,       20000,       FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_DRUID_STARSURGE,            FSBSpellType::Damage,   0.f,        0.f,             80.f,            40.f,        false,       10000,       FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_DRUID_STARFALL,             FSBSpellType::Damage,   0.1f,       0.f,             80.f,            40.f,        false,       8000,        FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },  
    { SPELL_DRUID_MOONFIRE,             FSBSpellType::Damage,   0.f,        0.f,             70.f,            30.f,        false,       1000,        FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_DRUID_SUNFIRE,              FSBSpellType::Damage,   0.f,        0.f,             70.f,            40.f,        false,       1000,        FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_DRUID_CELESTIAL_ALIGNMENT,  FSBSpellType::Damage,   0.f,        0.f,             50.f,             40.f,        true,        180000,      FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },

    // HEALER
    { SPELL_DRUID_NATURE_CURE,          FSBSpellType::Heal,     0.f,        100.f,           100.f,            40.f,        false,        8000,        FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_DRUID_REJUVENATION,         FSBSpellType::Heal,     0.f,        80.f,            100.f,            40.f,        false,        1000,        FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_DRUID_WILD_GROWTH,          FSBSpellType::Heal,     0.f,        70.f,            100.f,            40.f,        false,        10000,       FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_DRUID_TREE_OF_LIFE,         FSBSpellType::Heal,     0.f,        50.f,            50.f,             0.f,         true,         180000,      FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_DRUID_IRONBARK,             FSBSpellType::Heal,     0.f,        50.f,            50.f,             0.f,         true,         90000,       FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_DRUID_LIFEBLOOM,            FSBSpellType::Heal,     0.f,        50.f,            50.f,             40.f,        false,        1000,        FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_DRUID_SWIFTMEND,            FSBSpellType::Heal,     0.f,        30.f,            50.f,             40.f,        false,        15000,       FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_DRUID_TRANQUILITY,          FSBSpellType::Heal,     0.f,        30.f,            50.f,             40.f,        true,         180000,      FSB_RoleMask::FSB_ROLEMASK_HEALER },
};

namespace FSBDruid
{
    bool BotOOCHealOwner(Creature* bot, Player* player, uint32& globalCooldown)
    {
        if (!player || !bot)
            return false;

        if (bot->HasAura(SPELL_DRUID_BEAR) || bot->HasAura(SPELL_DRUID_CAT))
            return false;

        uint32 now = getMSTime();

        if (player->GetHealthPct() <= 50 && !player->HasAura(SPELL_DRUID_LIFEBLOOM))
        {
            bot->CastSpell(player, SPELL_DRUID_LIFEBLOOM, false);
            globalCooldown = now + 1500;

            TC_LOG_DEBUG("scripts.ai.core", "FSB Out-of-combat: Bot: {} Player Heal < 50", bot->GetName());

            return true;

        }
        else if (player->GetHealthPct() <= 90 && !player->HasAura(SPELL_DRUID_REGROWTH))
        {
            bot->CastSpell(player, SPELL_DRUID_REGROWTH, false);
            globalCooldown = now + 1500;

            TC_LOG_DEBUG("scripts.ai.core", "FSB Out-of-combat: Bot: {} Player Heal < 70", bot->GetName());

            return true;
        }

        return false;
    }

    bool BotOOCBuffSelf(Creature* bot, uint32& globalCooldown, uint32& selfBuffTimer, uint32& outSpellId)
    {
        if (!bot)
            return false;

        uint32 now = getMSTime();

        bool isCat = bot->HasAura(SPELL_DRUID_CAT);

        if (isCat && !bot->HasAura(SPELL_DRUID_CAT_PROWL))
        {

            bot->CastSpell(bot, SPELL_DRUID_CAT_PROWL, false);
            selfBuffTimer = now + 60000; // 1 minute
            globalCooldown = now + 1500; // use 10s cooldown to not interrup duration of channel spell
            outSpellId = SPELL_DRUID_CAT_PROWL;

            return true;
        }

        if (bot->IsUnderWater() && !bot->HasAura(SPELL_DRUID_AQUATIC))
        {
            bot->CastSpell(bot, SPELL_DRUID_AQUATIC, false);
            return true;
        }
        else if (!bot->IsUnderWater() && bot->HasAura(SPELL_DRUID_AQUATIC))
        {
            bot->RemoveAurasDueToSpell(SPELL_DRUID_AQUATIC);
            return true;
        }

        return false;
    }

    bool BotOnAuraApplied(Creature* bot, AuraApplication const* aurApp, bool applied, FSBBotStats& botStats)
    {
        if (!bot)
            return false;

        if (!aurApp || !aurApp->GetBase())
            return false;

        switch (aurApp->GetBase()->GetId())
        {
        case SPELL_DRUID_BEAR:
        {
            float hpPct = bot->GetPctModifierValue(UNIT_MOD_HEALTH, TOTAL_PCT);
            float armorPct = bot->GetPctModifierValue(UNIT_MOD_ARMOR, TOTAL_PCT);

            if (applied)
            {
                bot->SetStatPctModifier(UNIT_MOD_HEALTH, TOTAL_PCT, hpPct + 0.25f);
                bot->SetStatPctModifier(UNIT_MOD_ARMOR, TOTAL_PCT, armorPct + 2.2f);
            }
            else if (!applied)
            {
                bot->SetStatPctModifier(UNIT_MOD_HEALTH, TOTAL_PCT, hpPct - 0.25f);
                bot->SetStatPctModifier(UNIT_MOD_ARMOR, TOTAL_PCT, armorPct - 2.2f);
            }
            FSBStats::RecalculateStats(bot, false, false);
            return true;
        }
        case SPELL_DRUID_TREE_OF_LIFE:
        {
            float armorPct = bot->GetPctModifierValue(UNIT_MOD_ARMOR, TOTAL_PCT);

            if (applied)
            {
                botStats.spellPowerPct += 0.1f;
                bot->SetStatPctModifier(UNIT_MOD_ARMOR, TOTAL_PCT, armorPct + 1.2f);
            }

            if (!applied)
            {
                botStats.spellPowerPct -= 0.1f;
                bot->SetStatPctModifier(UNIT_MOD_ARMOR, TOTAL_PCT, armorPct - 1.2f);
            }
            FSBStats::RecalculateStats(bot, false, false);
            return true;
        }
        case SPELL_DRUID_MOONKIN:
        {
            float armorPct = bot->GetPctModifierValue(UNIT_MOD_ARMOR, TOTAL_PCT);

            if (applied)
            {
                botStats.spellPowerPct += 0.1f;
                bot->SetStatPctModifier(UNIT_MOD_ARMOR, TOTAL_PCT, armorPct + 1.25f);
            }

            if (!applied)
            {
                botStats.spellPowerPct -= 0.1f;
                bot->SetStatPctModifier(UNIT_MOD_ARMOR, TOTAL_PCT, armorPct - 1.25f);
            }
            FSBStats::RecalculateStats(bot, false, false);
            return true;
        }
        default:
            return false;
        }
    }

    void HandleOnSpellCast(Creature* bot, uint32 spellId)
    {
        switch (spellId)
        {
        case SPELL_DRUID_BEAR_MANGLE:
            bot->ModifyPower(POWER_RAGE, 120, false);
            break;
        case SPELL_DRUID_BEAR_THRASH:
            bot->ModifyPower(POWER_RAGE, 60, false);
            break;

        case SPELL_DRUID_ROOTS:
        {
            Unit* victim = bot->GetVictim();

            if (victim && bot->IsWithinMeleeRange(victim) && victim->HasAura(SPELL_DRUID_ROOTS))
            {
                //float x, y, z;
                //bot->GetRandomPoint(bot->GetPosition(), 10.0f, x, y, z);
                bot->GetMotionMaster()->MovePoint(FSBMovement::MOVEMENT_POINT_DRUID_ROOTS_ESCAPE, bot->GetPositionX() + frand(-10.f, 10.f), bot->GetPositionY(), bot->GetPositionZ());
            }
            break;
        }

        default:
            break;
        }
    }

    void BotSetRoleAuras(Creature* bot, FSB_Roles role, bool recalculateStats)
    {
        if (!bot)
            return;

        switch (role)
        {
        case FSB_ROLE_TANK:
        {
            for (uint32 spellId : druidAurasToRemoveForTank)
            {
                if (bot->HasAura(spellId))
                    bot->RemoveAurasDueToSpell(spellId);
            }

            if (!bot->HasAura(SPELL_DRUID_BEAR))
            {
                bot->CastSpell(bot, SPELL_DRUID_BEAR);
                uint32 bearDisplayId = RAND(2281, 29241, 29293, 29415, 29416);
                bot->SetDisplayId(bearDisplayId, false);
            }
            break;
        }
        case FSB_ROLE_HEALER:
        {
            for (uint32 spellId : druidAurasToRemoveForHealer)
            {
                if (bot->HasAura(spellId))
                    bot->RemoveAurasDueToSpell(spellId);
            }

            if (!bot->HasAura(SPELL_DRUID_TREANT))
                bot->CastSpell(bot, SPELL_DRUID_TREANT);
            break;
        }
        case FSB_ROLE_MELEE_DAMAGE:
        {
            for (uint32 spellId : druidAurasToRemoveForMelee)
            {
                if (bot->HasAura(spellId))
                    bot->RemoveAurasDueToSpell(spellId);
            }

            if (!bot->HasAura(SPELL_DRUID_CAT))
            {
                bot->CastSpell(bot, SPELL_DRUID_CAT);
                uint32 catDisplayId = RAND(29405, 29407, 892, 29406, 29408);
                bot->SetDisplayId(catDisplayId, false);
            }
            break;
        }
        case FSB_ROLE_RANGED_DAMAGE:
        {
            for (uint32 spellId : druidAurasToRemoveForDamage)
            {
                if (bot->HasAura(spellId))
                    bot->RemoveAurasDueToSpell(spellId);
            }

            if (!bot->HasAura(SPELL_DRUID_MOONKIN))
            {
                bot->CastSpell(bot, SPELL_DRUID_MOONKIN);
                uint32 moonkinDisplayId = RAND(15374, 115607);
                bot->SetDisplayId(moonkinDisplayId, false);
            }
            break;
        }
        default:
            break;
        }

        if (recalculateStats)
            FSBStats::RecalculateStats(bot, false, true);
    }

    bool BotHasMarkWild(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->HasAura(SPELL_DRUID_MARK_WILD))
            return true;

        return false;

    }

    bool BotHasSurvivalInstincts(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->HasAura(SPELL_DRUID_BEAR_SURVIVAL_INSTINCTS))
            return true;

        return false;

    }

    bool BotHasIronbark(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->HasAura(SPELL_DRUID_IRONBARK))
            return true;

        return false;

    }

    bool BotInitialCombatSpells(Creature* bot, uint32& globalCooldown, bool& botCastedCombatBuffs, FSB_Roles botRole)
    {
        if (botCastedCombatBuffs)
            return false;

        if (!bot || !bot->IsAlive())
            return false;

        if (!bot->IsInCombat())
            return false;

        Unit* target = nullptr;
        Unit* tank = FSBGroup::BotGetFirstGroupTank(bot);

        switch (botRole)
        {
        case FSB_ROLE_HEALER:
            if (tank)
                target = tank;
            else
            {
                Player* player = FSBMgr::Get()->GetBotOwner(bot);

                if (!player)
                    break;

                if (!player->IsAlive())
                    break;

                if (!player->IsInCombat())
                    break;

                target = player;
            }
            break;
        case FSB_ROLE_RANGED_DAMAGE:
            target = bot;
            break;
        default:
            target = bot;
            break;
        }

        if (target)
        {
            uint32 now = getMSTime();

            if (!target->HasAura(SPELL_DRUID_REJUVENATION))
            {
                if (FSBSpells::BotCastSpell(bot, SPELL_DRUID_REJUVENATION, target))
                {
                    globalCooldown = now + 1500;
                    TC_LOG_DEBUG("scripts.ai.fsb", "FSB: Initial Combat Spell Cast: Rejuvenation on target: {}", target->GetName());
                    return true;
                }
            }
            else if (!target->HasAura(SPELL_DRUID_LIFEBLOOM))
            {
                if (FSBSpells::BotCastSpell(bot, SPELL_DRUID_LIFEBLOOM, target))
                {
                    globalCooldown = now + 1500;
                    TC_LOG_DEBUG("scripts.ai.fsb", "FSB: Initial Combat Spell Cast: Lifebloom on target: {}", target->GetName());
                    botCastedCombatBuffs = true;
                    return true;
                }
            }
        }
        return false;

    }
}
