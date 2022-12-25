/*
 * Copyright 2023 AzgathCore
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

#include "stormstout_brewery.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

enum eHabaneroBeer
{
    NPC_BARREL = 56731,
    SPELL_GUSHING_BREW_BVIS = 114379, // Gushing Brew beam visual (The Great Wheel).
    SPELL_PROC_EXPLOSION = 106787
};

enum Spells
{
    // FRIENDLY
    SPELL_AUNTIE_VISUAL = 115618, // Auntie Stormstout visual.
    SPELL_GUSHING_BREW_A = 114380, // Gushing Brew aura (NPC that has beam cast on).
    SPELL_LEAKING_BEER_B_A = 146604, // Dummy for NPC on Keg.
    SPELL_BEER_PUDDLE_VIS = 112960, // Beer on ground visual.

    // HOSTILE

    // Aqua Dancer - Once killed, their deaths will damage the Sodden Hozen Brawlers for half their health.
    SPELL_AQUATIC_ILLUSION = 107044, // Gives Sodden Hozen Brawler SPELL_WATER_STRIKE.
    SPELL_AQUAT_ILLUSION_R = 114655, // Removal damage.

    // Fiery Trickster - Once killed, their deaths will damage the Inflamed Hozen Brawlers for half their health.
    SPELL_FIERY_ILLUSION = 107175, // Gives Inflamed Hozen Brawler SPELL_FIRE_STRIKE.
    SPELL_FIERY_ILLUSION_R = 114656, // Removal damage.

    // Sodded Hozen Brawler
    SPELL_WATER_STRIKE = 107046,

    // Inflamed Hozen Brawler
    SPELL_FIRE_STRIKE = 107176,

    // Hozen Bouncer - 2 bouncers only, after Ook-Ook. After yells they run, crash into each other, die.
    SPELL_HOZEN_DOORGUARD = 107019,

    // Sleepy Hozen Brawler, Drunken Hozen Brawler.
    SPELL_COSMETIC_SLEEP = 124557, // Used by Sleepy.
    SPELL_UPPERCUT = 80182,

    SPELL_SPICY_EXPLOSION = 107205,

    SPELL_BREW_BARREL_EXPL = 107351, // Barrel monkey explosion.

    // Stout Brew Alemental
    SPELL_BREW_BOLT = 115652,
    SPELL_BLACKOUT_BREW = 106851,
    SPELL_BLACKOUT_DRUNK = 106857, // At 10 stacks of SPELL_BLACKOUT_BREW.

    // Sudsy Brew Alemental
    SPELL_BREW_BOLT2 = 115650,
    SPELL_SUDS = 116178, // Creates NPC_POOL_OF_SUDS at target location.
    AURA_SUDS = 116179, // Periodic dmg trigger aura.
    SPELL_SUDS_DUMMY_VIS = 119418, // Tooltip: "Can summon puddles of suds."

    // Unruly Alemental
    SPELL_BREW_BOLT3 = 118104,
    SPELL_BREWHAHA = 118099,

    // Bubbling Brew Alemental
    SPELL_BREW_BOLT4 = 116155,
    SPELL_BUBBLE_SHIELD = 128708,

    // Fizzy Brew Alemental
    // Uses SPELL_BREW_BOLT2.
    SPELL_CARBONATION_M = 116162, // Missile.
    SPELL_CARBONATION_S = 116164, // Creates NPC_CARBONATION_POOL at target location.
    AURA_CARBONATION = 116168, // Periodic dmg trigger aura.

    // Bloated Brew Alemental
    // Uses SPELL_BREW_BOLT.
    SPELL_BLOAT = 106546,

    // Yeasty Brew Alemental
    // Uses SPELL_BREW_BOLT4.
    // Uses Ferment in boss script.
};

enum Events
{
    // Trash

    EVENT_UPPERCUT = 1,
    EVENT_WATER_STRIKE,
    EVENT_FIRE_STRIKE,

    EVENT_BREW_BOLT,
    EVENT_BLACKOUT_BREW,
    EVENT_BREW_BOLT2,
    EVENT_SUDS,
    EVENT_BREW_BOLT3,
    EVENT_CARBONATION,
    EVENT_BLOAT,
    EVENT_BUBBLE_SHIELD,
    EVENT_BREW_BOLT4,

    // Hozen Bouncer
    EVENT_CHECK_OOK,
    EVENT_SAY_OOK_KILLED,
    EVENT_SAY_MEANS,
    EVENT_SAY_NEW_OOK,
    EVENT_SAY_PARTY,
    EVENT_RUN_AND_CRASH,
    EVENT_BOUNCER_DIE,

    // Chen Stormstout / Auntie Stormstout intro event
    EVENT_AUNTIE_ENTRANCE_SAY_1,
    EVENT_CHEN_ENTRANCE_SAY_1,
    EVENT_AUNTIE_ENTRANCE_SAY_2,
    EVENT_CHEN_ENTRANCE_SAY_2,
    EVENT_AUNTIE_ENTRANCE_SAY_3,
    EVENT_CHEN_ENTRANCE_SAY_3,
    EVENT_AUNTIE_ENTRANCE_SAY_4,
    EVENT_CHEN_ENTRANCE_SAY_4,
    EVENT_AUNTIE_ENTRANCE_SAY_5,
    EVENT_CHEN_ENTRANCE_SAY_5,
    EVENT_AUNTIE_ENTRANCE_SAY_6,
    EVENT_CHEN_ENTRANCE_SAY_6,
    EVENT_CHEN_ENTRANCE_SAY_7,

    // Ancestral Brewmaster
    EVENT_SPEAK_HOPTALLUS_1,
    EVENT_SPEAK_HOPTALLUS_2,
    EVENT_SPEAK_RANDOM
};

enum AncestralBrewmasterYells
{
    SAY_ABM_HOPTALLUS_1 = 0, // Whatzit... are they... what are they doin' to our alementals?
    SAY_ABM_HOPTALLUS_2 = 0, // Hey... hey YOU! Those are OUR flying... beer monsters?
};

void AddSC_stormstout_brewery()
{
   
}
