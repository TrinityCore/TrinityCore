/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef DEF_SHADOWFANG_H
#define DEF_SHADOWFANG_H

#include "SpellScript.h"

#define DataHeader "SK"
#define SKScriptName "instance_shadowfang_keep"

uint32 const EncounterCount = 7;

enum SKSpells
{
    // Ivar Bloodfang
    SPELL_CLEAVE                = 87719,

    // High Warlord Cromush
    SPELL_TELEPORT_VISUAL       = 12980,

    // Bloodfang Berserker
    SPELL_STEALTH               = 58506,
    SPELL_PERMANENT_FEIGN_DEATH = 29266,

    // Plague Dummy
    SPELL_DISEASE_CLOUD         = 88198
};

enum SKCreatures
{
    // Baron Ashbury
    BOSS_BARON_ASHBURY          = 46962,

    // Baron Silverlaine
    BOSS_BARON_SILVERLAINE      = 3887,

    NPC_NANDOS_DUMMY            = 51047,
    NPC_WOLF_MASTER_NANDOS      = 50851,
    NPC_LUPINE_SPECTRE          = 50923,
    NPC_ODO_DUMMY               = 50934,
    NPC_ODO_THE_BLINDWATCHER    = 50857,
    NPC_RAZORCLAW_DUMMY         = 51080,
    NPC_RAZORCLAW_THE_BUTCHER   = 50869,
    NPC_RETHILGORE_DUMMY        = 51085,
    NPC_RETHILGORE              = 50834,

    // Commander Springvale
    BOSS_COMMANDER_SPRINGVALE   = 4278,
    NPC_TORMENTED_OFFICER       = 50615,
    NPC_WAILING_GUARDSMAN       = 50613,
    NPC_SHIELD_FOCUS            = 50547,
    NPC_DESECRATION_STALKER     = 50503,

    // Lord Walden
    BOSS_LORD_WALDEN            = 46963,
    NPC_MYSTERY_MIXTURE         = 50522,

    // Lord Godfrey
    BOSS_LORD_GODFREY           = 46964,
    NPC_BLOODTHIRSTY_GHOUL      = 50561,
    NPC_PISTOL_BARRAGE_DUMMY    = 52065,

        // Generic NPCs
    NPC_VETERAN_FORSAKEN_TROOPER = 47030,
    NPC_DEATHSTALKER_BELMONT    = 47293,
    NPC_FORSAKEN_BLIGHTSPREADER = 47031,
    NPC_HIGH_WARLORD_CROMUSH    = 47294,
    NPC_DISEASE_BUNNY           = 23837,
    NPC_BLOODFANG_BERSERKER     = 47027,
    NPC_PACKLEADER_IVAR         = 47006,
    NPC_HIGH_MAGISTRATE_HENRY   = 47862
};

enum SKGameObjectIds
{
    GO_COURTYARD_DOOR   = 18895,
    GO_SORCERERS_DOOR   = 18972,
    GO_ARUGAL_DOOR      = 18971
};

enum SKDataTypes
{
    // Bosses
    DATA_BARON_ASHBURY          = 0,
    DATA_BARON_SILVERLAINE      = 1,
    DATA_COMMANDER_SPRINGVALE   = 2,
    DATA_LORD_WALDEN            = 3,
    DATA_LORD_GODFREY           = 4,
    DATA_APOTHECARY_HUMMEL      = 5,

    DATA_TEAM_IN_INSTANCE,

    DATA_ARUGAL_DOOR,
    DATA_SORCERER_GATE,
    DATA_COURTYARD_DOOR
};

template<class AI>
AI* GetShadowfangKeepAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, SKScriptName);
}

#define RegisterShadowfangKeepCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetShadowfangKeepAI)

#endif
