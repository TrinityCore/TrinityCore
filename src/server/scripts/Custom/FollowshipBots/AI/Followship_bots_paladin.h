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

extern std::vector<FSBSpellDefinition> PaladinSpellsTable;

enum FSB_PALADIN_SPECIAL_SPELLS
{
    SPELL_PALADIN_CHARGER = 23214,
    SPELL_PALADIN_WARHORSE = 13819,

    SPELL_PALADIN_REDEMPTION = 7328,
    SPELL_PALADIN_CLEANSE = 4987,
};

enum FSB_PALADIN_SELF_BUFFS
{
    // HEALER
    SPELL_PALADIN_RITE_OF_SANCTIFICATION = 433550,

    // TANK
    SPELL_PALADIN_FURY = 187218
};

enum FSB_PALADIN_BLESSINGS
{
    // HEALER
    SPELL_PALADIN_BLESSING_SACRIFICE = 6940,
    SPELL_PALADIN_BLESSING_SPELLWARDING = 204018,

    // PROTECTION
    SPELL_PALADIN_BLESSING_PROTECTION = 1022,
    SPELL_PALADIN_BLESSING_SALVATION = 204013,

    // DPS
    SPELL_PALADIN_BLESSING_SANCTUARY = 210256,
    SPELL_PALADIN_BLESSING_KINGS = 58054
};

enum FSB_PALADIN_COMBAT_SPELLS
{
    // HEALER
    SPELL_PALADIN_LAY_ON_HANDS = 633,
    SPELL_PALADIN_WORD_OF_GLORY = 150631,
    SPELL_PALADIN_HOLY_LIGHT = 82326, //295698,
    SPELL_PALADIN_SEAL_OF_THE_CRUSADER = 416771,

    SPELL_PALADIN_DIVINE_PROTECTION = 498,

    SPELL_PALADIN_HOLY_SHOCK = 20473,//36340,
    SPELL_PALADIN_HOLY_PRISM = 114165,

    SPELL_PALADIN_BEACON_OF_LIGHT = 53563,
    SPELL_PALADIN_LIGHT_OF_DAWN = 185984,




    // DPS
    SPELL_PALADIN_CRUSADER_STRIKE = 35395,
    SPELL_PALADIN_JUDGEMENT = 20271,
    SPELL_PALADIN_CONSECRATION = 26573,

    SPELL_PALADIN_DIVINE_STORM = 79970,
    SPELL_PALADIN_EXORCISM = 383208,
    SPELL_PALADIN_HAMMER_OF_WRATH = 162763,
    SPELL_PALADIN_EXECUTION_SENTENCE = 343527,

    SPELL_PALADIN_AVENGING_WRATH = 231895,

    SPELL_PALADIN_REPENTANCE = 20066,

    // PROTECTION
    SPELL_PALADIN_AVENGER_SHIELD = 31935,
    SPELL_PALADIN_HOLY_SHIELD = 32777, //31904,
    SPELL_PALADIN_BLESSED_HAMMER = 204301,
    SPELL_PALADIN_HAMMER_OF_THE_RIGHT = 53595,
    SPELL_PALADIN_REBUKE = 96231,
    SPELL_PALADIN_GUARDIAN_ANCIENT_KINGS = 86659,

    // ANY
    SPELL_PALADIN_HAMMER_OF_JUSTICE = 853,
    SPELL_PALADIN_HAND_OF_RECKONING = 62124,

    
    SPELL_PALADIN_FLASH_OF_LIGHT = 19750, //57766,

    SPELL_PALADIN_DIVINE_SHIELD = 642
};

enum FSB_PALADIN_AURAS
{
    SPELL_PALADIN_DEVOTION_AURA = 465,
    SPELL_PALADIN_RETRIBUTION_AURA = 8990,
    SPELL_PALADIN_CONCENTRATION_AURA = 79963,
    SPELL_PALADIN_CRUSADER_AURA = 32223
};

static const uint32 paladinAurasToRemoveForHealer[] =
{
    SPELL_PALADIN_DEVOTION_AURA,
    SPELL_PALADIN_RETRIBUTION_AURA,
    SPELL_PALADIN_FURY
};

static const uint32 paladinAurasToRemoveForDPS[] =
{
    SPELL_PALADIN_DEVOTION_AURA,
    SPELL_PALADIN_CONCENTRATION_AURA,
    SPELL_PALADIN_RITE_OF_SANCTIFICATION,
    SPELL_PALADIN_FURY
};

static const uint32 paladinAurasToRemoveForTank[] =
{
    SPELL_PALADIN_CONCENTRATION_AURA,
    SPELL_PALADIN_RETRIBUTION_AURA,
    SPELL_PALADIN_RITE_OF_SANCTIFICATION
};

namespace FSBPaladin
{
    bool BotHasDevotionAura(Creature* bot);
    bool BotHasGuardianOfAncientKings(Creature* bot);
    bool BotHasDivineProtection(Creature* bot);
    bool BotHasBlessingOfSacrifice(Creature* bot);
    bool BotHasAvengingWrath(Creature* bot);

    void HandleOnSpellCast(Creature* bot, uint32 spellId);

    bool BotOOCHealOwner(Creature* bot, Player* player, uint32& globalCooldown);
    bool BotOOCBuffSelf(Creature* bot, uint32& globalCooldown, uint32& selfBuffTimer, uint32& outSpellId);

    void BotSetRoleAuras(Creature* bot, FSB_Roles role);
}
