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

#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"

std::vector<FSBSpellDefinition> PaladinSpellsTable =
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

    { SPELL_PALADIN_DIVINE_SHIELD,          FSBSpellType::Heal,     0.f,        20.f,           100.f,           0.f,           true,       300000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_PALADIN_FLASH_OF_LIGHT,         FSBSpellType::Heal,     0.1f,       70.f,           60.f,            40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_ANY },

    { SPELL_PALADIN_HAMMER_OF_JUSTICE,      FSBSpellType::Damage,   0.f,        0.f,            100.f,           10.f,          false,      45000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_PALADIN_JUDGEMENT,              FSBSpellType::Damage,   0.f,        0.f,            100.f,           30.f,          false,      11000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_PALADIN_CONSECRATION,           FSBSpellType::Damage,   0.02f,      0.f,            100.f,           2.f,           true,       9000,           FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_PALADIN_CRUSADER_STRIKE,        FSBSpellType::Damage,   0.f,        0.f,            90.f,            2.f,           false,      3000,           FSB_RoleMask::FSB_ROLEMASK_ANY },
    
    // HOLY
    { SPELL_PALADIN_LAY_ON_HANDS,           FSBSpellType::Heal,     0.f,        10.f,           100.f,           40.f,          false,      600000,         FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_PALADIN_WORD_OF_GLORY,          FSBSpellType::Heal,     0.1f,       10.f,           100.f,           40.f,          false,      600000,         FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_PALADIN_LIGHT_OF_DAWN,          FSBSpellType::Heal,     0.f,        100.f,          100.f,           0.f,           true,       1000,           FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_PALADIN_HOLY_LIGHT,             FSBSpellType::Heal,     0.f,        50.f,           100.f,           40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_PALADIN_BLESSING_SPELLWARDING,  FSBSpellType::Heal,     0.f,        20.f,           100.f,           40.f,          false,      300000,         FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_PALADIN_HOLY_PRISM,             FSBSpellType::Heal,     0.f,        100.f,          90.f,            40.f,          false,      45000,          FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_PALADIN_HOLY_SHOCK,             FSBSpellType::Heal,     0.f,        60.f,           90.f,            40.f,          false,      6000,           FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_PALADIN_SEAL_OF_THE_CRUSADER,   FSBSpellType::Heal,     0.05f,      60.f,           60.f,            40.f,          false,      12000,          FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_PALADIN_BLESSING_SACRIFICE,     FSBSpellType::Heal,     0.f,        60.f,           50.f,            40.f,          false,      120000,         FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_PALADIN_DIVINE_PROTECTION,      FSBSpellType::Heal,     0.f,        70.f,           50.f,            0.f,           true,       60000,          FSB_RoleMask::FSB_ROLEMASK_HEALER },

    { SPELL_PALADIN_HOLY_PRISM,             FSBSpellType::Damage,   0.f,        0.f,            100.f,           40.f,          false,      45000,          FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_PALADIN_HOLY_SHOCK,             FSBSpellType::Damage,   0.f,        0.f,            90.f,            40.f,          false,      6000,           FSB_RoleMask::FSB_ROLEMASK_HEALER },

    // TANK
    { SPELL_PALADIN_BLESSING_PROTECTION,    FSBSpellType::Heal,     0.f,        20.f,           100.f,           40.f,          false,      300000,         FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_PALADIN_BLESSING_SALVATION,     FSBSpellType::Heal,     0.02f,      30.f,           100.f,           40.f,          false,      60000,          FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_PALADIN_GUARDIAN_ANCIENT_KINGS, FSBSpellType::Heal,     0.02f,      60.f,           50.f,            0.f,           true,       180000,         FSB_RoleMask::FSB_ROLEMASK_TANK },
    
    { SPELL_PALADIN_REBUKE,                 FSBSpellType::Damage,   0.01f,      0.f,            100.f,           2.f,           false,      15000,          FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_PALADIN_HAND_OF_RECKONING,      FSBSpellType::Damage,   0.f,        0.f,            100.f,           30.f,          false,      8000,           FSB_RoleMask::FSB_ROLEMASK_TANK },
    
    { SPELL_PALADIN_AVENGER_SHIELD,         FSBSpellType::Damage,   0.f,        0.f,            90.f,            30.f,          false,      15000,          FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_PALADIN_HOLY_SHIELD,            FSBSpellType::Damage,   0.f,        0.f,            90.f,            2.f,           true,       10000,          FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_PALADIN_BLESSED_HAMMER,         FSBSpellType::Damage,   0.01f,      0.f,            90.f,            40.f,          false,      3000,           FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_PALADIN_HAMMER_OF_THE_RIGHT,    FSBSpellType::Damage,   0.f,        0.f,            90.f,            2.f,           false,      3000,           FSB_RoleMask::FSB_ROLEMASK_TANK },

    // DPS
    { SPELL_PALADIN_BLESSING_SANCTUARY,     FSBSpellType::Heal,     0.04f,      100.f,          100.f,           40.f,          false,      60000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_PALADIN_EXECUTION_SENTENCE,     FSBSpellType::Damage,   0.04f,      0.f,            100.f,           30.f,          false,      60000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_PALADIN_DIVINE_STORM,           FSBSpellType::Damage,   0.f,        0.f,            100.f,           2.f,           true,       15000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_PALADIN_REPENTANCE,             FSBSpellType::Damage,   0.f,        0.f,            100.f,           30.f,          false,      15000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_PALADIN_EXORCISM,               FSBSpellType::Damage,   0.02f,      0.f,            90.f,            30.f,          false,      15000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_PALADIN_HAMMER_OF_WRATH,        FSBSpellType::Damage,   0.04f,      0.f,            90.f,            40.f,          false,      12000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_PALADIN_AVENGING_WRATH,         FSBSpellType::Damage,   0.f,        0.f,            50.f,            2.f,           true,       120000,         FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    
};

namespace FSBPaladin
{
    bool BotHasAvengingWrath(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->HasAura(SPELL_PALADIN_AVENGING_WRATH))
            return true;

        return false;

    }

    bool BotHasBlessingOfSacrifice(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->HasAura(SPELL_PALADIN_BLESSING_SACRIFICE))
            return true;

        return false;

    }

    bool BotHasDivineProtection(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->HasAura(SPELL_PALADIN_DIVINE_PROTECTION))
            return true;

        return false;

    }

    bool BotHasDevotionAura(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->HasAura(SPELL_PALADIN_DEVOTION_AURA))
            return true;

        return false;

    }

    bool BotHasGuardianOfAncientKings(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->HasAura(SPELL_PALADIN_GUARDIAN_ANCIENT_KINGS))
            return true;

        return false;

    }

    void HandleOnSpellCast(Creature* /*bot*/, uint32 spellId)
    {
        switch (spellId)
        {
        case SPELL_PALADIN_JUDGEMENT:
        case SPELL_PALADIN_CRUSADER_STRIKE:
            //bot->ModifyPower(POWER_HOLY_POWER, 1, false);
            //TC_LOG_DEBUG("scripts.ai.fsb", "FSB bot {} casted spell and will receive holy power. Total HP: {}", bot->GetName(), bot->GetPower(POWER_HOLY_POWER));
            break;

        default:
            break;
        }
    }

    bool BotOOCHealOwner(Creature* bot, Player* player, uint32& globalCooldown)
    {
        if (!player || !bot)
            return false;

        uint32 now = getMSTime();

        if (player->GetHealthPct() <= 50)
        {
            bot->CastSpell(player, SPELL_PALADIN_HOLY_LIGHT, false);
            globalCooldown = now + 1500;

            TC_LOG_DEBUG("scripts.ai.core", "FSB Out-of-combat: Bot: {} Player Heal < 50", bot->GetName());

            return true;

        }
        else if (player->GetHealthPct() <= 90)
        {
            bot->CastSpell(player, SPELL_PALADIN_FLASH_OF_LIGHT, false);
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

        bool isHealer = FSBMgr::Get()->GetRole(bot) == FSB_ROLE_HEALER;
        bool isTank = FSBMgr::Get()->GetRole(bot) == FSB_ROLE_TANK;

        if (isHealer && !bot->HasAura(SPELL_PALADIN_RITE_OF_SANCTIFICATION))
        {
            bot->CastSpell(bot, SPELL_PALADIN_RITE_OF_SANCTIFICATION, false);
            selfBuffTimer = now + 60000; // 1 minute
            globalCooldown = now + 1500; // use 10s cooldown to not interrup duration of channel spell
            outSpellId = SPELL_PALADIN_RITE_OF_SANCTIFICATION;

            return true;
        }

        if (isTank && !bot->HasAura(SPELL_PALADIN_FURY))
        {
            bot->CastSpell(bot, SPELL_PALADIN_FURY, false);
            selfBuffTimer = now + 60000; // 1 minute
            globalCooldown = now + 1500; // use 10s cooldown to not interrup duration of channel spell
            outSpellId = SPELL_PALADIN_FURY;

            return true;
        }

        return false;
    }


    void BotSetRoleAuras(Creature* bot, FSB_Roles role)
    {
        switch (role)
        {
        case FSB_ROLE_TANK:
        {
            for (uint32 spellId : paladinAurasToRemoveForTank)
            {
                if (bot->HasAura(spellId))
                    bot->RemoveAurasDueToSpell(spellId);
            }

            if(!bot->HasAura(SPELL_PALADIN_DEVOTION_AURA))
                bot->CastSpell(bot, SPELL_PALADIN_DEVOTION_AURA);
            break;
        }
        case FSB_ROLE_HEALER:
        {
            for (uint32 spellId : paladinAurasToRemoveForHealer)
            {
                if (bot->HasAura(spellId))
                    bot->RemoveAurasDueToSpell(spellId);
            }

            if (!bot->HasAura(SPELL_PALADIN_CONCENTRATION_AURA))
                bot->CastSpell(bot, SPELL_PALADIN_CONCENTRATION_AURA);
            break;
        }
        case FSB_ROLE_MELEE_DAMAGE:
        {
            for (uint32 spellId : paladinAurasToRemoveForDPS)
            {
                if (bot->HasAura(spellId))
                    bot->RemoveAurasDueToSpell(spellId);
            }

            if (!bot->HasAura(SPELL_PALADIN_RETRIBUTION_AURA))
                bot->CastSpell(bot, SPELL_PALADIN_RETRIBUTION_AURA);
            break;
        }
        default:
            break;
        }
    }
}
