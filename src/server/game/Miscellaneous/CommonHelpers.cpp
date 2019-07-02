/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "CommonHelpers.h"
#include "Common.h"
#include "Item.h"
#include "ItemTemplate.h"
#include "Player.h"
#include "SharedDefines.h"

enum PlayerSpecializationIconicSpellIds
{
    /* Warrior - Arms */
    SPELL_SWEEPING_STRIKES = 12328,
    SPELL_MORTAL_STRIKE = 12294,
    SPELL_BLADESTORM = 46924,

    /* Warrior - Fury */
    SPELL_DEATH_WISH = 12292,
    SPELL_BLOODTHIRST = 23881,
    PASSIVE_TITANS_GRIP = 46917,

    /* Warrior - Protection */
    SPELL_VIGILANCE = 50720,
    SPELL_DEVASTATE = 20243,
    SPELL_SHOCKWAVE = 46968,

    /* Paladin - Holy*/
    PASSIVE_ILLUMINATION = 20215,
    SPELL_HOLY_SHOCK = 20473,
    SPELL_BEACON_OF_LIGHT = 53563,

    /* Paladin - Protection */
    SPELL_BLESS_OF_SANC = 20911,
    SPELL_HOLY_SHIELD = 20925,
    SPELL_HAMMER_OF_RIGHTEOUS = 53595,

    /* Paladin - Retribution */
    SPELL_SEAL_OF_COMMAND = 20375,
    SPELL_CRUSADER_STRIKE = 35395,
    SPELL_DIVINE_STORM = 53385,

    /* Hunter - Beast Mastery */
    SPELL_BESTIAL_WRATH = 19574,
    PASSIVE_BEAST_WITHIN = 34692,
    PASSIVE_BEAST_MASTERY = 53270,

    /* Hunter - Marksmanship */
    SPELL_AIMED_SHOT = 19434,
    PASSIVE_TRUESHOT_AURA = 19506,
    SPELL_CHIMERA_SHOT = 53209,

    /* Hunter - Survival */
    PASSIVE_LOCK_AND_LOAD = 56344,
    SPELL_WYVERN_STING = 19386,
    SPELL_EXPLOSIVE_SHOT = 53301,

    /* Rogue - Assassination */
    SPELL_COLD_BLOOD = 14177,
    SPELL_MUTILATE = 1329,
    SPELL_HUNGER_FOR_BLOOD = 51662,

    /* Rogue - Combat */
    SPELL_BLADE_FLURRY = 13877,
    SPELL_ADRENALINE_RUSH = 13750,
    SPELL_KILLING_SPREE = 51690,

    /* Rogue - Sublety */
    SPELL_HEMORRHAGE = 16511,
    SPELL_PREMEDITATION = 14183,
    SPELL_SHADOW_DANCE = 51713,

    /* Priest - Discipline */
    PASSIVE_SOUL_WARDING = 63574,
    SPELL_POWER_INFUSION = 10060,
    SPELL_PENANCE = 47540,

    /* Priest - Holy */
    PASSIVE_SPIRIT_REDEMPTION = 20711,
    SPELL_DESPERATE_PRAYER = 19236,
    SPELL_GUARDIAN_SPIRIT = 47788,

    /* Priest - Shadow */
    SPELL_VAMPIRIC_EMBRACE = 15286,
    SPELL_SHADOWFORM = 15473,
    SPELL_VAMPIRIC_TOUCH = 34914,

    /* Death Knight - Blood */
    SPELL_RUNE_TAP = 48982,
    SPELL_HYSTERIA = 49016,
    SPELL_HEART_STRIKE = 55050,

    /* Death Knight - Frost */
    PASSIVE_ICY_TALONS = 50887,
    SPELL_FROST_STRIKE = 49143,
    SPELL_HOWLING_BLAST = 49184,

    /* Death Knight - Unholy */
    PASSIVE_UNHOLY_BLIGHT = 49194,
    PASSIVE_MASTER_OF_GHOUL = 52143,
    SPELL_SCOURGE_STRIKE = 55090,

    /* Shaman - Elemental*/
    PASSIVE_ELEMENTAL_FOCUS = 16164,
    SPELL_TOTEM_OF_WRATH = 30706,
    SPELL_THUNDERSTORM = 51490,

    /* Shaman - Enhancement */
    PASSIVE_SPIRIT_WEAPONS = 16268,
    SPELL_LAVA_LASH = 60103,
    SPELL_FERAL_SPIRIT = 51533,

    /* Shaman - Restoration*/
    SPELL_SHA_NATURE_SWIFT = 591,
    SPELL_MANA_TIDE_TOTEM = 590,
    SPELL_RIPTIDE = 61295,

    /* Mage - Arcane */
    SPELL_FOCUS_MAGIC = 54646,
    SPELL_ARCANE_POWER = 12042,
    SPELL_ARCANE_BARRAGE = 44425,

    /* Mage - Fire */
    SPELL_PYROBLAST = 11366,
    SPELL_COMBUSTION = 11129,
    SPELL_LIVING_BOMB = 44457,

    /* Mage - Frost */
    SPELL_ICY_VEINS = 12472,
    SPELL_ICE_BARRIER = 11426,
    SPELL_DEEP_FREEZE = 44572,

    /* Warlock - Affliction */
    PASSIVE_SIPHON_LIFE = 63108,
    SPELL_UNSTABLE_AFFLICTION = 30108,
    SPELL_HAUNT = 48181,

    /* Warlock - Demonology */
    SPELL_SOUL_LINK = 19028,
    SPELL_DEMONIC_EMPOWERMENT = 47193,
    SPELL_METAMORPHOSIS = 59672,

    /* Warlock - Destruction */
    SPELL_SHADOWBURN = 17877,
    SPELL_CONFLAGRATE = 17962,
    SPELL_CHAOS_BOLT = 50796,

    /* Druid - Balance */
    SPELL_INSECT_SWARM = 5570,
    SPELL_MOONKIN_FORM = 24858,
    SPELL_STARFALL = 48505,

    /* Druid - Feral */
    SPELL_SURVIVAL_INSTINCTS = 61336,
    SPELL_MANGLE = 33917,
    SPELL_BERSERK = 50334,

    /* Druid - Restoration */
    SPELL_SWIFTMEND = 18562,
    SPELL_TREE_OF_LIFE = 33891,
    SPELL_WILD_GROWTH = 48438
};

static const uint8 MaximumSpecializationIconicSpells = 3u;

// As it turns out, finding out "how many points does the player have in spec X" is actually really expensive to do frequently
// So instead, we just check for a handful of spells that, realistically, no spec is gonna go without (and "has spell" is cheap!)
// Can players deliberately trick this check? Yes.
// Is it worth doing? No.
// Close enough.
static const uint32 PlayerSpecializationIconicSpells[MAX_CLASSES][MAX_TALENT_TREES][MaximumSpecializationIconicSpells] = {
    { // CLASS_NONE
        {0,0,0},
        {0,0,0},
        {0,0,0}
    },
    { // CLASS_WARRIOR
        {SPELL_BLADESTORM, SPELL_MORTAL_STRIKE, SPELL_SWEEPING_STRIKES}, // Arms
        {PASSIVE_TITANS_GRIP, SPELL_BLOODTHIRST, SPELL_DEATH_WISH}, // Fury
        {SPELL_SHOCKWAVE, SPELL_DEVASTATE, SPELL_VIGILANCE} // Protection
    },
    { // CLASS_PALADIN
        {SPELL_BEACON_OF_LIGHT, SPELL_HOLY_SHOCK, PASSIVE_ILLUMINATION}, // Holy
        {SPELL_HAMMER_OF_RIGHTEOUS, SPELL_HOLY_SHIELD, SPELL_BLESS_OF_SANC}, // Protection
        {SPELL_DIVINE_STORM, SPELL_CRUSADER_STRIKE, SPELL_SEAL_OF_COMMAND} // Retribution
    },
    { // CLASS_HUNTER
        {PASSIVE_BEAST_MASTERY, PASSIVE_BEAST_WITHIN, SPELL_BESTIAL_WRATH}, // Beast Mastery
        {SPELL_CHIMERA_SHOT, PASSIVE_TRUESHOT_AURA, SPELL_AIMED_SHOT}, // Marksmanship
        {SPELL_EXPLOSIVE_SHOT, SPELL_WYVERN_STING, PASSIVE_LOCK_AND_LOAD} // Survival
    },
    { // CLASS_ROGUE
        {SPELL_HUNGER_FOR_BLOOD, SPELL_MUTILATE, SPELL_COLD_BLOOD}, // Assassination
        {SPELL_KILLING_SPREE, SPELL_ADRENALINE_RUSH, SPELL_BLADE_FLURRY}, // Combat
        {SPELL_SHADOW_DANCE, SPELL_PREMEDITATION, SPELL_HEMORRHAGE} // Sublety
    },
    { // CLASS_PRIEST
        {SPELL_PENANCE, SPELL_POWER_INFUSION, PASSIVE_SOUL_WARDING}, // Discipline
        {SPELL_GUARDIAN_SPIRIT, PASSIVE_SPIRIT_REDEMPTION, SPELL_DESPERATE_PRAYER}, // Holy
        {SPELL_VAMPIRIC_TOUCH, SPELL_SHADOWFORM, SPELL_VAMPIRIC_EMBRACE} // Shadow
    },
    { // CLASS_DEATH_KNIGHT
        {SPELL_HEART_STRIKE, SPELL_HYSTERIA, SPELL_RUNE_TAP}, // Blood
        {SPELL_HOWLING_BLAST, SPELL_FROST_STRIKE, PASSIVE_ICY_TALONS}, // Frost
        {SPELL_SCOURGE_STRIKE, PASSIVE_MASTER_OF_GHOUL, PASSIVE_UNHOLY_BLIGHT} // Unholy
    },
    { // CLASS_SHAMAN
        {SPELL_THUNDERSTORM, SPELL_TOTEM_OF_WRATH, PASSIVE_ELEMENTAL_FOCUS}, // Elemental
        {SPELL_FERAL_SPIRIT, SPELL_LAVA_LASH, PASSIVE_SPIRIT_WEAPONS}, // Enhancement
        {SPELL_RIPTIDE, SPELL_MANA_TIDE_TOTEM, SPELL_SHA_NATURE_SWIFT} // Restoration
    },
    { // CLASS_MAGE
        {SPELL_ARCANE_BARRAGE, SPELL_ARCANE_POWER, SPELL_FOCUS_MAGIC}, // Arcane
        {SPELL_LIVING_BOMB, SPELL_COMBUSTION, SPELL_PYROBLAST}, // Fire
        {SPELL_DEEP_FREEZE, SPELL_ICE_BARRIER, SPELL_ICY_VEINS} // Frost
    },
    { // CLASS_WARLOCK
        {SPELL_HAUNT, SPELL_UNSTABLE_AFFLICTION, PASSIVE_SIPHON_LIFE}, // Affliction
        {SPELL_METAMORPHOSIS, SPELL_DEMONIC_EMPOWERMENT, SPELL_SOUL_LINK}, // Demonology
        {SPELL_CHAOS_BOLT, SPELL_CONFLAGRATE, SPELL_SHADOWBURN} // Destruction
    },
    { // CLASS_UNK
        {0,0,0},
        {0,0,0},
        {0,0,0}
    },
    { // CLASS_DRUID
        {SPELL_STARFALL, SPELL_MOONKIN_FORM, SPELL_INSECT_SWARM}, // Balance
        {SPELL_BERSERK, SPELL_MANGLE, SPELL_SURVIVAL_INSTINCTS}, // Feral
        {SPELL_WILD_GROWTH, SPELL_TREE_OF_LIFE, SPELL_SWIFTMEND} // Restoration
    }
};

uint8 Trinity::Helpers::Entity::GetPlayerSpecialization(Player const* who)
{
    if (!who)
        return 0;

    uint8 playerClass = who->GetClass();
    for (uint8 tier = 0; tier < MaximumSpecializationIconicSpells; ++tier)
    {
        for (uint8 tree = 0; tree < MAX_TALENT_TREES; ++tree)
            if (PlayerSpecializationIconicSpells[playerClass][tree][tier] && who->HasSpell(PlayerSpecializationIconicSpells[playerClass][tree][tier]))
                return tree;
    }

    return 0;
}

bool Trinity::Helpers::Entity::IsPlayerHealer(Player const* who)
{
    if (!who)
        return false;

    switch (who->GetClass())
    {
        case CLASS_WARRIOR:
        case CLASS_HUNTER:
        case CLASS_ROGUE:
        case CLASS_DEATH_KNIGHT:
        case CLASS_MAGE:
        case CLASS_WARLOCK:
        default:
            return false;
        case CLASS_PALADIN:
            return (Trinity::Helpers::Entity::GetPlayerSpecialization(who) == SPEC_PALADIN_HOLY);
        case CLASS_PRIEST:
            return (Trinity::Helpers::Entity::GetPlayerSpecialization(who) != SPEC_PRIEST_SHADOW);
        case CLASS_SHAMAN:
            return (Trinity::Helpers::Entity::GetPlayerSpecialization(who) == SPEC_SHAMAN_RESTORATION);
        case CLASS_DRUID:
            return (Trinity::Helpers::Entity::GetPlayerSpecialization(who) == SPEC_DRUID_RESTORATION);
    }
}

bool Trinity::Helpers::Entity::IsPlayerRangedAttacker(Player const* who)
{
    if (!who)
        return false;

    switch (who->GetClass())
    {
        case CLASS_WARRIOR:
        case CLASS_PALADIN:
        case CLASS_ROGUE:
        case CLASS_DEATH_KNIGHT:
        default:
            return false;
        case CLASS_MAGE:
        case CLASS_WARLOCK:
            return true;
        case CLASS_HUNTER:
        {
            // check if we have a ranged weapon equipped
            Item const* rangedSlot = who->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
            if (ItemTemplate const* rangedTemplate = rangedSlot ? rangedSlot->GetTemplate() : nullptr)
            {
                if ((1 << rangedTemplate->SubClass) & ITEM_SUBCLASS_MASK_WEAPON_RANGED)
                    return true;
            }
            return false;
        }
        case CLASS_PRIEST:
            return (Trinity::Helpers::Entity::GetPlayerSpecialization(who) == SPEC_PRIEST_SHADOW);
        case CLASS_SHAMAN:
            return (Trinity::Helpers::Entity::GetPlayerSpecialization(who) == SPEC_SHAMAN_ELEMENTAL);
        case CLASS_DRUID:
            return (Trinity::Helpers::Entity::GetPlayerSpecialization(who) == SPEC_DRUID_BALANCE);
    }
}
