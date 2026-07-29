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

#include "Followship_bots_mage.h"
#include "Followship_bots_utils_spells.h"

std::vector<FSBSpellDefinition> MageSpellsTable =
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

    { SPELL_MAGE_POLYMORPH,                 FSBSpellType::Damage,   0.f,        0.f,            40.f,            30.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_MAGE_BLINK,                     FSBSpellType::Damage,   0.f,        0.f,            55.f,            2.f,           true,       20000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_MAGE_COUNTERSPELL,              FSBSpellType::Damage,   0.f,        0.f,            100.f,           40.f,          true,       25000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    

    // FROST
    { SPELL_MAGE_ICE_BLOCK,                 FSBSpellType::Damage,   0.f,        0.f,            100.f,           2.f,           true,        240000,        FSB_RoleMask::FSB_ROLEMASK_RANGED_FROST },
    { SPELL_MAGE_FLURRY,                    FSBSpellType::Damage,   0.f,        0.f,            90.f,            40.f,          false,       30000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_FROST },
    { SPELL_MAGE_ICE_LANCE,                 FSBSpellType::Damage,   0.f,        0.f,            90.f,            40.f,          false,       1000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_FROST },
    { SPELL_MAGE_FROSTBOLT,                 FSBSpellType::Damage,   0.f,        0.f,            70.f,            40.f,          false,       1000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_FROST },
    { SPELL_MAGE_FROSTFIRE_BOLT,            FSBSpellType::Damage,   0.f,        0.f,            70.f,            40.f,          false,       1000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_FROST },
    { SPELL_MAGE_CONE_OF_COLD,              FSBSpellType::Damage,   0.f,        0.f,            70.f,            6.f,           false,       25000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_MAGE_FROST_NOVA,                FSBSpellType::Damage,   0.04f,      0.f,            65.f,            6.f,           false,       30000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_FROST },
    { SPELL_MAGE_ICE_NOVA,                  FSBSpellType::Damage,   0.f,        0.f,            60.f,            40.f,          false,       25000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_ARCANE },
    { SPELL_MAGE_ICE_BARRIER,               FSBSpellType::Damage,   0.f,        0.f,            65.f,            2.f,           true,        25000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_FROST },
    { SPELL_MAGE_BLIZZARD,                  FSBSpellType::Damage,   0.f,        0.f,            50.f,            30.f,          false,       12000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_FROST },
    { SPELL_MAGE_WATER_ELEMENTAL,           FSBSpellType::Damage,   0.f,        0.f,            50.f,            30.f,          false,       15000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_FROST },
    { SPELL_MAGE_FROZEN_ORB,                FSBSpellType::Damage,   0.f,        0.f,            20.f,            40.f,          false,       60000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_FROST },
    { SPELL_MAGE_RAY_FROST,                 FSBSpellType::Damage,   0.f,        0.f,            50.f,            40.f,          false,       60000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_FROST },
    { SPELL_MAGE_RING_FROST,                FSBSpellType::Damage,   0.f,        0.f,            50.f,            30.f,          false,       45000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_FROST },
    

    // FIRE
    { SPELL_MAGE_FIREBALL,                  FSBSpellType::Damage,   0.f,        0.f,            90.f,            40.f,          false,       1000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_MAGE_FIRE_BLAST,                FSBSpellType::Damage,   0.f,        0.f,            80.f,            40.f,          false,       14000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_FIRE },
    { SPELL_MAGE_SCORCH,                    FSBSpellType::Damage,   0.f,        0.f,            80.f,            40.f,          false,       1000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_FIRE },
    { SPELL_MAGE_COMBUSTION,                FSBSpellType::Damage,   0.f,        0.f,            70.f,            2.f,           true,        120000,        FSB_RoleMask::FSB_ROLEMASK_RANGED_FIRE },
    { SPELL_MAGE_BLAZING_BARRIER,           FSBSpellType::Damage,   0.f,        0.f,            70.f,            2.f,           true,        30000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_FIRE },
    { SPELL_MAGE_FLAMESTRIKE,               FSBSpellType::Damage,   0.f,        0.f,            60.f,            40.f,          false,       1000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_FIRE },
    { SPELL_MAGE_PHOENIX_FLAMES,            FSBSpellType::Damage,   0.04f,      0.f,            60.f,            40.f,          false,       25000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_FIRE },
    { SPELL_MAGE_PYROBLAST,                 FSBSpellType::Damage,   0.f,        0.f,            70.f,            40.f,          false,       1000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_FIRE },
    { SPELL_MAGE_METEOR,                    FSBSpellType::Damage,   0.f,        0.f,            50.f,            40.f,          false,       45000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_FIRE },
    { SPELL_MAGE_DRAGON_BREATH,             FSBSpellType::Damage,   0.f,        0.f,            50.f,            6.f,           false,       45000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_FIRE },
    
    

    // ARCANE
    { SPELL_MAGE_ARCANE_MISSILES,           FSBSpellType::Damage,   0.08f,      0.f,            50.f,            30.f,          false,       1000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_ARCANE },
    { SPELL_MAGE_ARCANE_EXPLOSION,          FSBSpellType::Damage,   0.f,        0.f,            60.f,            6.f,           true,        1000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_MAGE_ARCANE_SUPERNOVA,          FSBSpellType::Damage,   0.f,        0.f,            60.f,            40.f,          false,       45000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_ARCANE },
    { SPELL_MAGE_ARCANE_BLAST,              FSBSpellType::Damage,   0.f,        0.f,            70.f,            40.f,          false,       1000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_ARCANE },
    { SPELL_MAGE_ARCANE_BARRAGE,            FSBSpellType::Damage,   0.f,        0.f,            75.f,            40.f,          false,       1000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_ARCANE },
    { SPELL_MAGE_ARCANE_PULSE,              FSBSpellType::Damage,   0.f,        0.f,            75.f,            40.f,          false,       1000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_ARCANE },
    { SPELL_MAGE_ARCANE_TOUCH_MAGI,         FSBSpellType::Damage,   0.f,        0.f,            75.f,            40.f,          false,       45000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_ARCANE },
    { SPELL_MAGE_ARCANE_SURGE,              FSBSpellType::Damage,   0.f,        0.f,            75.f,            40.f,          false,       90000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_ARCANE },
    { SPELL_MAGE_SPELL_STEAL,               FSBSpellType::Damage,   0.f,        0.f,            75.f,            30.f,          false,       1000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_ARCANE },
    { SPELL_MAGE_TIME_WARP,                 FSBSpellType::Damage,   0.f,        0.f,            90.f,            2.f,           true,        300000,        FSB_RoleMask::FSB_ROLEMASK_RANGED_ARCANE },
    { SPELL_MAGE_EVOCATION,                 FSBSpellType::Damage,   0.f,        0.f,            90.f,            10.f,          true,        45000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_ARCANE },
    { SPELL_MAGE_PRESENCE_MIND,             FSBSpellType::Damage,   0.f,        0.f,            90.f,            10.f,          true,        45000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_ARCANE },
    { SPELL_MAGE_PRISMATIC_BARRIER,         FSBSpellType::Damage,   0.f,        0.f,            90.f,            10.f,          true,        45000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_ARCANE },

    
};
