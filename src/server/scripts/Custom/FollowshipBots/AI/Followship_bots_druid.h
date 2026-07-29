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

#pragma once

#include "Followship_bots_spells_handler.h"

extern std::vector<FSBSpellDefinition> DruidSpellsTable;

enum DRUID_SHAPESHIFT_FORMS
{
    SPELL_DRUID_BEAR = 5487, //18309,
    SPELL_DRUID_CAT = 768, //197167,
    SPELL_DRUID_MOONKIN = 24858,
    SPELL_DRUID_TREANT = 176295,
    SPELL_DRUID_TRAVEL = 468849, //783,
    SPELL_DRUID_AQUATIC = 83448,
};

enum DRUID_BUFF_SPELLS
{
    SPELL_DRUID_MARK_WILD = 1126,
    SPELL_DRUID_THORNS = 418805
};

enum DRUID_SPECIAL_SPELLS
{
    SPELL_DRUID_CAT_PROWL = 5215,

    SPELL_DRUID_REVIVE = 50769,
    SPELL_DRUID_REBIRTH = 20484,
};

enum DRUID_COMBAT_SPELLS
{
    SPELL_DRUID_WRATH = 5176, //76815,
    SPELL_DRUID_REGROWTH = 8936, //97426,
    SPELL_DRUID_BARKSKIN = 22812,

    SPELL_DRUID_SKULL_BASH = 106839, // BEAR & CAT
    SPELL_DRUID_SWIPE = 48562,

    // BEAR
    SPELL_DRUID_BEAR_GROWL = 6795, //182848,
    SPELL_DRUID_BEAR_THRASH = 77758, //292576,
    SPELL_DRUID_BEAR_MANGLE = 33917, //288266,
    SPELL_DRUID_BEAR_URSOC = 102558,
    SPELL_DRUID_BEAR_LUNAR_BEAM = 204066,
    SPELL_DRUID_BEAR_MAUL = 6807, //141061,
    SPELL_DRUID_BEAR_RAZE = 400254,
    SPELL_DRUID_BEAR_RED_MOON = 1252871,
    SPELL_DRUID_BEAR_SUNDERING_ROAR = 1253799,
    SPELL_DRUID_BEAR_SURVIVAL_INSTINCTS = 61336,
    SPELL_DRUID_BEAR_IRONFUR = 192081,
    SPELL_DRUID_BEAR_INCAPACITATING_ROAR = 99,
    SPELL_DRUID_BEAR_FRENZIED_REGEN = 22842,

    // CAT
    SPELL_DRUID_CAT_THRASH = 106830, //172035,
    SPELL_DRUID_CAT_SHRED = 5221, //215442,
    SPELL_DRUID_CAT_MANGLE = 59988, //79828,
    SPELL_DRUID_CAT_FEROCIOUS_BITE = 22568, //27557,
    SPELL_DRUID_CAT_FERAL_FRENZY = 274838,
    SPELL_DRUID_CAT_AVATAR_ASHAMANE = 102543,
    SPELL_DRUID_CAT_PRIMAL_WRATH = 285381,
    SPELL_DRUID_CAT_TIGER_FURY = 5217,
    SPELL_DRUID_CAT_RIP = 59989,
    SPELL_DRUID_CAT_RAKE = 1822,
    

    // RANGED
    SPELL_DRUID_MOONFIRE = 8921, //15798,
    SPELL_DRUID_ROOTS = 37823,
    SPELL_DRUID_FORCE_NATURE = 205636,
    SPELL_DRUID_SOLAR_BEAM = 78675,
    SPELL_DRUID_NEW_MOON = 274281,
    SPELL_DRUID_STARFALL = 1286243,
    SPELL_DRUID_WILD_MUSHROOM = 88747,
    SPELL_DRUID_CELESTIAL_ALIGNMENT = 194223,
    SPELL_DRUID_STARSURGE = 197626,
    SPELL_DRUID_STARFIRE = 194153,
    SPELL_DRUID_HIBERNATE = 2637,
    SPELL_DRUID_SUNFIRE = 93402,
    SPELL_DRUID_TYPHOON = 132469,

    // HEALER
    SPELL_DRUID_TREE_OF_LIFE = 33891,
    SPELL_DRUID_IRONBARK = 102342,
    SPELL_DRUID_LIFEBLOOM = 33763,
    SPELL_DRUID_SWIFTMEND = 18562,
    SPELL_DRUID_TRANQUILITY = 740,
    SPELL_DRUID_NATURE_CURE = 88423,
    SPELL_DRUID_REJUVENATION = 774,
    SPELL_DRUID_WILD_GROWTH = 48438,
    SPELL_DRUID_REMOVE_CORRUPTION = 2782,

    // COMBAT BUFFS
    
};

static const uint32 druidAurasToRemoveForHealer[] =
{
    SPELL_DRUID_BEAR,
    SPELL_DRUID_MOONKIN,
    SPELL_DRUID_CAT,
};

static const uint32 druidAurasToRemoveForTank[] =
{
    SPELL_DRUID_TREANT,
    SPELL_DRUID_MOONKIN,
    SPELL_DRUID_CAT,
};

static const uint32 druidAurasToRemoveForMelee[] =
{
    SPELL_DRUID_TREANT,
    SPELL_DRUID_MOONKIN,
    SPELL_DRUID_BEAR,
};

static const uint32 druidAurasToRemoveForDamage[] =
{
    SPELL_DRUID_TREANT,
    SPELL_DRUID_BEAR,
    SPELL_DRUID_CAT,
};

namespace FSBDruid
{
    bool BotOOCHealOwner(Creature* bot, Player* player, uint32& globalCooldown);
    bool BotOOCBuffSelf(Creature* bot, uint32& globalCooldown, uint32& selfBuffTimer, uint32& outSpellId);
    bool BotInitialCombatSpells(Creature* bot, uint32& globalCooldown, bool& botCastedCombatBuffs, FSB_Roles botRole);
    bool BotOnAuraApplied(Creature* bot, AuraApplication const* aurApp, bool applied, FSBBotStats& botStats);
    void HandleOnSpellCast(Creature* bot, uint32 spellId);
    void BotSetRoleAuras(Creature* bot, FSB_Roles role, bool recalculateStats = true);
    bool BotHasMarkWild(Creature* bot);
    bool BotHasIronbark(Creature* bot);
    bool BotHasSurvivalInstincts(Creature* bot);
}
