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

#include "Followship_bots_utils.h"


std::vector<FSBSpellDefinition> RogueSpellsTable =
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

    { SPELL_ROGUE_THISTLE_TEA,              FSBSpellType::Heal,     0.f,        80.f,           100.f,           0.f,           true,       60000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_ROGUE_EVASION,                  FSBSpellType::Heal,     0.f,        60.f,           100.f,           0.f,           true,       120000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_ROGUE_CRIMSON_VIAL,             FSBSpellType::Heal,     0.f,        50.f,           100.f,           0.f,           true,       30000,          FSB_RoleMask::FSB_ROLEMASK_ANY },

    { SPELL_ROGUE_KICK,                     FSBSpellType::Damage,   0.f,        0.f,            100.f,           2.f,           false,      15000,          FSB_RoleMask::FSB_ROLEMASK_ANY },

    { SPELL_ROGUE_SHIV,                     FSBSpellType::Damage,   0.f,        0.f,            50.f,            2.f,           false,      30000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_ROGUE_GOUGE,                    FSBSpellType::Damage,   0.f,        0.f,            50.f,            2.f,           false,      25000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_ROGUE_SINISTER_STRIKE,          FSBSpellType::Damage,   0.f,        0.f,            50.f,            2.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_ANY },

    // ASSASSIN
    { SPELL_ROGUE_CHEAP_SHOT,               FSBSpellType::Damage,   0.f,        0.f,            100.f,           2.f,           false,      12000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_ROGUE_AMBUSH,                   FSBSpellType::Damage,   0.f,        0.f,            100.f,           2.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_ROGUE_POISONED_KNIFE,           FSBSpellType::Damage,   0.f,        0.f,            100.f,           30.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },

    { SPELL_ROGUE_DEATHMARK,                FSBSpellType::Damage,   0.f,        0.f,            90.f,            2.f,           false,      120000,         FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_ROGUE_GARROTE,                  FSBSpellType::Damage,   0.f,        0.f,            90.f,            2.f,           false,      6000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_ROGUE_MUTILATE,                 FSBSpellType::Damage,   0.f,        0.f,            90.f,            2.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },

    { SPELL_ROGUE_KINGSBANE,                FSBSpellType::Damage,   0.f,        0.f,            80.f,            2.f,           false,      60000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_ROGUE_FAN_KNIVES,               FSBSpellType::Damage,   0.f,        0.f,            80.f,            4.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_ROGUE_CRIMSON_TEMPEST,          FSBSpellType::Damage,   0.f,        0.f,            80.f,            5.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },

    { SPELL_ROGUE_KIDNEY_SHOT,              FSBSpellType::Damage,   0.f,        0.f,            70.f,            2.f,           false,      30000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_ROGUE_ENVENOM,                  FSBSpellType::Damage,   0.f,        0.f,            70.f,            2.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_ROGUE_RUPTURE,                  FSBSpellType::Damage,   0.f,        0.f,            70.f,            2.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },

    // SUB
    // heals or powerups
    { SPELL_ROGUE_CLOAK_SHADOWS,            FSBSpellType::Heal,     0.f,        40.f,           100.f,           0.f,           true,       120000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_ROGUE_SHADOW_BLADES,            FSBSpellType::Heal,     0.f,        50.f,           100.f,           0.f,           true,       90000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_2 },

    { SPELL_ROGUE_BLIND,                    FSBSpellType::Damage,   0.f,        0.f,            100.f,           15.f,          false,      120000,         FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_2 },

    // need stealth
    { SPELL_ROGUE_SHADOWSTEP,               FSBSpellType::Damage,   0.f,        0.f,            100.f,           25.f,          false,      30000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_2 },
    { SPELL_ROGUE_SHADOWSTRIKE,             FSBSpellType::Damage,   0.f,        0.f,            100.f,           2.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_2 },

    // cc
    { SPELL_ROGUE_SHURIKEN_STORM,           FSBSpellType::Damage,   0.f,        0.f,            80.f,            10.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_2 },

    // combo cc
    { SPELL_ROGUE_SLICE_DICE,               FSBSpellType::Damage,   0.f,        0.f,            70.f,            2.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_2 },
    { SPELL_ROGUE_BLACK_POWDER,             FSBSpellType::Damage,   0.f,        0.f,            70.f,            2.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_2 },

    // normal attacks
    { SPELL_ROGUE_GOREMAW_BITE,             FSBSpellType::Damage,   0.f,        0.f,            60.f,            2.f,           false,      45000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_2 },
    { SPELL_ROGUE_BACKSTAB,                 FSBSpellType::Damage,   0.f,        0.f,            60.f,            2.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_2 },
    { SPELL_ROGUE_GLOOMBLADE,               FSBSpellType::Damage,   0.f,        0.f,            60.f,            2.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_2 },
    { SPELL_ROGUE_SHURIKEN_TOSS,            FSBSpellType::Damage,   0.f,        0.f,            60.f,            30.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_2 },

    // COMBAT
    // heals or powerups
    { SPELL_ROGUE_DREADBLADES,              FSBSpellType::Damage,   0.f,        0.f,            100.f,           2.f,           false,      120000,         FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_3 },
    { SPELL_ROGUE_ROLL_THE_BONES,           FSBSpellType::Damage,   0.f,        0.f,            100.f,           0.f,           true,       45000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_3 },

    // combo cc
    { SPELL_ROGUE_EXPOSE_ARMOR,             FSBSpellType::Damage,   0.25f,      0.f,            70.f,            2.f,           false,      45000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_3 },
    { SPELL_ROGUE_DEADLY_THROW,             FSBSpellType::Damage,   0.f,        0.f,            70.f,            2.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_3 },
    { SPELL_ROGUE_EVISCERATE,               FSBSpellType::Damage,   0.f,        0.f,            70.f,            2.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_3 },

    // normal attacks
    { SPELL_ROGUE_SEPSIS,                   FSBSpellType::Damage,   0.f,        0.f,            60.f,            2.f,           false,      90000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_3 },
    { SPELL_ROGUE_DISMANTLE,                FSBSpellType::Damage,   0.f,        0.f,            60.f,            2.f,           false,      45000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_3 },
    { SPELL_ROGUE_MARKED_FOR_DEATH,         FSBSpellType::Damage,   0.f,        0.f,            60.f,            2.f,           false,      40000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_3 },
    { SPELL_ROGUE_BLADE_FLURRY,             FSBSpellType::Damage,   0.f,        0.f,            60.f,            2.f,           false,      30000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_3 },
    { SPELL_ROGUE_RIPOSTE,                  FSBSpellType::Damage,   0.f,        0.f,            60.f,            2.f,           false,      30000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_3 },
    { SPELL_ROGUE_GHOSTLY_STRIKE,           FSBSpellType::Damage,   0.f,        0.f,            60.f,            2.f,           false,      20000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_3 },

    // less often attacks
    { SPELL_ROGUE_PARALYTIC_POISON,         FSBSpellType::Damage,   0.f,        0.f,            40.f,            2.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE_3 },
};

namespace FSBRogue
{
}
