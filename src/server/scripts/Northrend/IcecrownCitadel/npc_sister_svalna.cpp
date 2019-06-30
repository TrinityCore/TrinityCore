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

#include "icecrown_citadel.h"
#include "AreaBoundary.h"
#include "ScriptMgr.h"

enum ICCSisterSvalnaTexts
{
    // Sister Svalna
    SAY_SVALNA_KILL_CAPTAIN = 1, // happens when she kills a captain
    SAY_SVALNA_KILL = 4,
    SAY_SVALNA_CAPTAIN_DEATH = 5, // happens when a captain resurrected by her dies
    SAY_SVALNA_DEATH = 6,
    EMOTE_SVALNA_IMPALE = 7,
    EMOTE_SVALNA_BROKEN_SHIELD = 8,

    SAY_CROK_INTRO_1 = 0, // Ready your arms, my Argent Brothers. The Vrykul will protect the Frost Queen with their lives.
    SAY_ARNATH_INTRO_2 = 5, // Even dying here beats spending another day collecting reagents for that madman, Finklestein.
    SAY_CROK_INTRO_3 = 1, // Enough idle banter! Our champions have arrived - support them as we push our way through the hall!
    SAY_SVALNA_EVENT_START = 0, // You may have once fought beside me, Crok, but now you are nothing more than a traitor. Come, your second death approaches!
    SAY_CROK_COMBAT_WP_0 = 2, // Draw them back to us, and we'll assist you.
    SAY_CROK_COMBAT_WP_1 = 3, // Quickly, push on!
    SAY_CROK_FINAL_WP = 4, // Her reinforcements will arrive shortly, we must bring her down quickly!
    SAY_SVALNA_RESURRECT_CAPTAINS = 2, // Foolish Crok. You brought my reinforcements with you. Arise, Argent Champions, and serve the Lich King in death!
    SAY_CROK_COMBAT_SVALNA = 5, // I'll draw her attacks. Return our brothers to their graves, then help me bring her down!
    SAY_SVALNA_AGGRO = 3, // Come, Scourgebane. I'll show the master which of us is truly worthy of the title of "Champion"!
    SAY_CAPTAIN_DEATH = 0,
    SAY_CAPTAIN_RESURRECTED = 1,
    SAY_CAPTAIN_KILL = 2,
    SAY_CAPTAIN_SECOND_DEATH = 3,
    SAY_CAPTAIN_SURVIVE_TALK = 4,
    SAY_CROK_WEAKENING_GAUNTLET = 6,
    SAY_CROK_WEAKENING_SVALNA = 7,
    SAY_CROK_DEATH = 8,
};

enum ICCSisterSvalnaSpells
{
    // Crok Scourgebane
    SPELL_ICEBOUND_ARMOR = 70714,
    SPELL_SCOURGE_STRIKE = 71488,
    SPELL_DEATH_STRIKE = 71489,

    // Sister Svalna
    SPELL_CARESS_OF_DEATH = 70078,
    SPELL_IMPALING_SPEAR_KILL = 70196,
    SPELL_REVIVE_CHAMPION = 70053,
    SPELL_UNDEATH = 70089,
    SPELL_IMPALING_SPEAR = 71443,
    SPELL_AETHER_SHIELD = 71463,
    SPELL_HURL_SPEAR = 71466,
    SPELL_DIVINE_SURGE = 71465,

    // Captain Arnath
    SPELL_DOMINATE_MIND = 14515,
    SPELL_FLASH_HEAL_NORMAL = 71595,
    SPELL_POWER_WORD_SHIELD_NORMAL = 71548,
    SPELL_SMITE_NORMAL = 71546,
    SPELL_FLASH_HEAL_UNDEAD = 71782,
    SPELL_POWER_WORD_SHIELD_UNDEAD = 71780,
    SPELL_SMITE_UNDEAD = 71778,

    // Captain Brandon
    SPELL_CRUSADER_STRIKE = 71549,
    SPELL_DIVINE_SHIELD = 71550,
    SPELL_JUDGEMENT_OF_COMMAND = 71551,
    SPELL_HAMMER_OF_BETRAYAL = 71784,

    // Captain Grondel
    SPELL_CHARGE = 71553,
    SPELL_MORTAL_STRIKE = 71552,
    SPELL_SUNDER_ARMOR = 71554,
    SPELL_CONFLAGRATION = 71785,

    // Captain Rupert
    SPELL_FEL_IRON_BOMB_NORMAL = 71592,
    SPELL_MACHINE_GUN_NORMAL = 71594,
    SPELL_ROCKET_LAUNCH_NORMAL = 71590,
    SPELL_FEL_IRON_BOMB_UNDEAD = 71787,
    SPELL_MACHINE_GUN_UNDEAD = 71788,
    SPELL_ROCKET_LAUNCH_UNDEAD = 71786,
};

enum ICCSisterSvalnaTimedEventIds
{
    // Crok Scourgebane
    EVENT_SCOURGE_STRIKE = 1,
    EVENT_DEATH_STRIKE,
    EVENT_HEALTH_CHECK,
    EVENT_CROK_INTRO_3,
    EVENT_START_PATHING,

    // Sister Svalna
    EVENT_ARNATH_INTRO_2,
    EVENT_SVALNA_START,
    EVENT_SVALNA_RESURRECT,
    EVENT_SVALNA_COMBAT,
    EVENT_IMPALING_SPEAR,
    EVENT_AETHER_SHIELD,

    // Captain Arnath
    EVENT_ARNATH_FLASH_HEAL,
    EVENT_ARNATH_PW_SHIELD,
    EVENT_ARNATH_SMITE,
    EVENT_ARNATH_DOMINATE_MIND,

    // Captain Brandon
    EVENT_BRANDON_CRUSADER_STRIKE,
    EVENT_BRANDON_DIVINE_SHIELD,
    EVENT_BRANDON_JUDGEMENT_OF_COMMAND,
    EVENT_BRANDON_HAMMER_OF_BETRAYAL,

    // Captain Grondel
    EVENT_GRONDEL_CHARGE_CHECK,
    EVENT_GRONDEL_MORTAL_STRIKE,
    EVENT_GRONDEL_SUNDER_ARMOR,
    EVENT_GRONDEL_CONFLAGRATION,

    // Captain Rupert
    EVENT_RUPERT_FEL_IRON_BOMB,
    EVENT_RUPERT_MACHINE_GUN,
    EVENT_RUPERT_ROCKET_LAUNCH,
};

enum ICCSisterSvalnaActions
{
    ACTION_KILL_CAPTAIN = 1,
    ACTION_START_GAUNTLET,
    ACTION_RESURRECT_CAPTAINS,
    ACTION_CAPTAIN_DIES,
    ACTION_RESET_EVENT
};

// Helper defines
// Captain Arnath
#define SPELL_FLASH_HEAL (IsUndead ? SPELL_FLASH_HEAL_UNDEAD : SPELL_FLASH_HEAL_NORMAL)
#define SPELL_POWER_WORD_SHIELD (IsUndead ? SPELL_POWER_WORD_SHIELD_UNDEAD : SPELL_POWER_WORD_SHIELD_NORMAL)
#define SPELL_SMITE (IsUndead ? SPELL_SMITE_UNDEAD : SPELL_SMITE_NORMAL)

// Captain Rupert
#define SPELL_FEL_IRON_BOMB (IsUndead ? SPELL_FEL_IRON_BOMB_UNDEAD : SPELL_FEL_IRON_BOMB_NORMAL)
#define SPELL_MACHINE_GUN (IsUndead ? SPELL_MACHINE_GUN_UNDEAD : SPELL_MACHINE_GUN_NORMAL)
#define SPELL_ROCKET_LAUNCH (IsUndead ? SPELL_ROCKET_LAUNCH_UNDEAD : SPELL_ROCKET_LAUNCH_NORMAL)

RectangleBoundary const SisterSvalnaBoundary = RectangleBoundary(4291.0f, 4423.0f, 2438.0f, 2653.0f);

void AddSC_icecrown_citadel()
{
}
