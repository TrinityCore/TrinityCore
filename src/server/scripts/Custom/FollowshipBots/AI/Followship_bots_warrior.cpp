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
#include "Followship_bots_utils.h"


std::vector<FSBSpellDefinition> WarriorSpellsTable =
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

    { SPELL_WARRIOR_CHARGE,         FSBSpellType::Damage,            0.f,        0.f,            100.f,          25.f,          false,        20000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_WARRIOR_TAUNT,          FSBSpellType::Damage,            0.f,        0.f,            100.f,          30.f,          false,        8000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_WARRIOR_PUMMEL,         FSBSpellType::Damage,            0.f,        0.f,            100.f,          2.f,           false,        15000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_WARRIOR_HEROIC_THROW,   FSBSpellType::Damage,            0.f,        0.f,            100.f,          30.f,          false,        6000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_WARRIOR_RECKLESSNESS,   FSBSpellType::Damage,            0.f,        0.f,            50.f,           2.f,           true,         90000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_WARRIOR_WHIRLWIND,      FSBSpellType::Damage,            0.f,        0.f,            50.f,           2.f,           true,         1000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_WARRIOR_HAMSTRING,      FSBSpellType::Damage,            0.f,        0.f,            45.f,          2.f,            false,        15000,         FSB_RoleMask::FSB_ROLEMASK_ANY },

    // PROTECTION
    { SPELL_WARRIOR_SHIELD_CHARGE,  FSBSpellType::Damage,            0.f,        0.f,            100.f,         25.f,          false,        45000,         FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_WARRIOR_DISARM,         FSBSpellType::Damage,            0.f,        0.f,            90.f,          2.f,           false,        45000,         FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_WARRIOR_EXECUTE,        FSBSpellType::Damage,            0.f,        0.f,            90.f,          2.f,           false,        6000,         FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_WARRIOR_REVENGE,        FSBSpellType::Damage,            0.f,        0.f,            90.f,          2.f,           false,        1000,         FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_WARRIOR_REND,           FSBSpellType::Damage,            0.f,        0.f,            80.f,          2.f,           false,        1000,         FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_WARRIOR_DEVASTATE,      FSBSpellType::Damage,            0.f,        0.f,            70.f,          2.f,           false,        1000,         FSB_RoleMask::FSB_ROLEMASK_TANK },
    
    { SPELL_WARRIOR_SHIELD_SLAM,    FSBSpellType::Damage,            0.f,        0.f,            80.f,          2.f,           false,        9000,         FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_WARRIOR_SHIELD_BLOCK,   FSBSpellType::Damage,            0.f,        0.f,            80.f,          2.f,           true,         16000,        FSB_RoleMask::FSB_ROLEMASK_TANK },

    { SPELL_WARRIOR_CHALLENGING_SHOUT,FSBSpellType::Damage,            0.f,        0.f,            60.f,          6.f,           true,      120000,         FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_WARRIOR_DISRUPTING_SHOUT,FSBSpellType::Damage,            0.f,        0.f,            60.f,          6.f,           true,       90000,         FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_WARRIOR_DEMO_SHOUT,     FSBSpellType::Damage,            0.f,        0.f,            60.f,          6.f,           true,        45000,         FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_WARRIOR_IGNORE_PAIN,    FSBSpellType::Damage,            0.f,        0.f,            60.f,          2.f,           true,        1000,         FSB_RoleMask::FSB_ROLEMASK_TANK },

    { SPELL_WARRIOR_SHIELD_WALL,   FSBSpellType::Damage,            0.f,        0.f,            50.f,          2.f,           true,        180000,         FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_WARRIOR_LAST_STAND,    FSBSpellType::Damage,            0.f,        0.f,            50.f,          2.f,           true,        180000,         FSB_RoleMask::FSB_ROLEMASK_TANK },

    // DPS
    { SPELL_WARRIOR_MORTAL_STRIKE,  FSBSpellType::Damage,            0.f,        0.f,            90.f,          2.f,           false,       6000,         FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_WARRIOR_SLAM,           FSBSpellType::Damage,            0.f,        0.f,            90.f,          2.f,           false,       1000,         FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_WARRIOR_BLOODTHIRST,    FSBSpellType::Damage,            0.f,        0.f,            90.f,          2.f,           false,       4500,         FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_WARRIOR_RAGING_BLOW,    FSBSpellType::Damage,            0.f,        0.f,            90.f,          2.f,           false,       8000,         FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },

    { SPELL_WARRIOR_SKULLSPLITTER,  FSBSpellType::Damage,            0.f,        0.f,            80.f,          2.f,           false,        21000,         FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_WARRIOR_ONSLAUGHT,      FSBSpellType::Damage,            0.f,        0.f,            80.f,          2.f,           false,        18000,         FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_WARRIOR_OVERPOWER,      FSBSpellType::Damage,            0.f,        0.f,            80.f,          2.f,           false,        12000,         FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },

    { SPELL_WARRIOR_BLADESTORM,     FSBSpellType::Damage,            0.f,        0.f,            70.f,          2.f,           false,        90000,         FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_WARRIOR_CLEAVE,         FSBSpellType::Damage,            0.f,        0.f,            70.f,          2.f,           false,        4500,         FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_WARRIOR_COLOSSUS_SMASH, FSBSpellType::Damage,            0.f,        0.f,            70.f,          2.f,           false,        45000,         FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_WARRIOR_DEMOLISH,       FSBSpellType::Damage,            0.f,        0.f,            70.f,          2.f,           false,        45000,         FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },

    { SPELL_WARRIOR_RAMPAGE,        FSBSpellType::Damage,            0.f,        0.f,            60.f,          2.f,           false,        1000,         FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_WARRIOR_FURIOUS_SLASH,  FSBSpellType::Damage,            0.f,        0.f,            50.f,          2.f,           false,        1000,         FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
};

namespace FSBWarrior
{
    bool BotHasDefensiveStance(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->HasAura(SPELL_WARRIOR_DEFENSIVE_STANCE))
            return true;

        return false;

    }

    bool BotHasBattleStance(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->HasAura(SPELL_WARRIOR_BATTLE_STANCE))
            return true;

        return false;

    }

    bool BotHasBerserkerStance(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->HasAura(SPELL_WARRIOR_BERSERKER_STANCE))
            return true;

        return false;

    }

    bool BotHasShieldWall(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->HasAura(SPELL_WARRIOR_SHIELD_WALL))
            return true;

        return false;

    }

    void HandleOnSpellCast(Creature* bot, uint32 spellId)
    {
        switch (spellId)
        {
        case SPELL_WARRIOR_ONSLAUGHT:
            bot->ModifyPower(POWER_RAGE, 300, false);
            break;

        case SPELL_WARRIOR_SHIELD_CHARGE:
        case SPELL_WARRIOR_CHARGE:
            bot->ModifyPower(POWER_RAGE, 200, false);
            break;

        case SPELL_WARRIOR_SKULLSPLITTER:
        case SPELL_WARRIOR_SHIELD_SLAM:
            bot->ModifyPower(POWER_RAGE, 150, false);
            break;

        case SPELL_WARRIOR_BLOODTHIRST:
            bot->ModifyPower(POWER_RAGE, 80, false);
            break;

        default:
            break;
        }
    }

    void BotSetRoleAuras(Creature* bot, FSB_Roles role)
    {
        if (!bot)
            return;

        switch (role)
        {
        case FSB_ROLE_TANK:
            if (!bot->HasAura(SPELL_WARRIOR_DEFENSIVE_STANCE))
                bot->CastSpell(bot, SPELL_WARRIOR_DEFENSIVE_STANCE);
            break;
        case FSB_ROLE_MELEE_DAMAGE:
            if (!bot->HasAura(SPELL_WARRIOR_BATTLE_STANCE) && !bot->HasAura(SPELL_WARRIOR_BERSERKER_STANCE))
            {
                uint32 spellId = urand(0, 1) ? SPELL_WARRIOR_BATTLE_STANCE : SPELL_WARRIOR_BERSERKER_STANCE;
                bot->CastSpell(bot, spellId);
            }
            break;
        default:
            break;
        }
    }
}
