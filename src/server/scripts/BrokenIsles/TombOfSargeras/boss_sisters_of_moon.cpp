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

#include "AreaTriggerAI.h"
#include "tomb_of_sargeras.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "AreaTrigger.h"
#include "AreaTriggerTemplate.h"

enum Says
{
    //Captain Yathae Moonstrike
    SAY_TWILIGHT_VOLLEY = 0,
    SAY_INCORPOREAL_SHOT_WARN = 1,
    SAY_RAPID_SHOT = 2,

    //Priestess Lunaspyre
    SAY_EMBRACE_ECLIPSE_WARN = 0,
    SAY_EMBRACE_ECLIPSE = 1,
    SAY_MOON_BURN = 2,
};

enum Spells
{
    SPELL_SHARED_HEALTH = 235215,
    SPELL_PHASE_1_CONVERSATION = 243034,
    SPELL_PHASE_2_CONVERSATION = 243044,
    SPELL_PHASE_3_CONVERSATION = 243047,
    SPELL_INCORPOREAL_TELEPORT = 236115,
    SPELL_LUNAR_GHOST = 235268,
    SPELL_LUNAR_GHOST_CAT = 235270,
    SPELL_CORPOREAL_GHOST = 234999,
    SPELL_CORPOREAL_GHOST_MOUNT = 236324,
    SPELL_BERSERK = 243262,

    SPELL_FONT_OF_ELUNE_AT = 236357,
    SPELL_LIGHT_SIDE_MOON_AT = 234565,
    SPELL_LIGHT_SIDE_MOON_WANING = 234587,
    SPELL_LIGHT_SIDE_MOON_DUMMY = 234664,
    SPELL_LUNAR_SUFFUSION = 234995,
    SPELL_DARK_SIDE_MOON_AT = 234657,
    SPELL_DARK_SIDE_MOON_WANING_AT = 234659,
    SPELL_DARK_SIDE_MOON_DUMMY = 234668,
    SPELL_UMBRA_SUFFUSION = 234996,
    SPELL_ASTRAL_PURGE = 234998,
    SPELL_ASTRAL_VULNERABILITY = 236330, //Mythic

    //Huntress Kasparian
    SPELL_MOON_GLAIVE = 236547,
    SPELL_DISCORPORATE = 236550,
    SPELL_TWILIGHT_GLAIVE_FILTER = 237561,
    SPELL_TWILIGHT_GLAIVE_AT = 236529, //Dmg 236541
    SPELL_SABERLEAP = 236344,
    SPELL_SPECTRAL_GLAIVE = 237633,
    SPELL_GLAIVE_STORM_FILTER_BIG = 239378,
    SPELL_GLAIVE_STORM_FILTER_MEDIUM = 239382,
    SPELL_GLAIVE_STORM_FILTER_SMALL = 239385,
    SPELL_GLAIVE_STORM_AT_BIG = 239379,
    SPELL_GLAIVE_STORM_AT_MEDIUM = 239383,
    SPELL_GLAIVE_STORM_AT_SMALL = 239386,

    //Priestess Lunaspyre
    SPELL_MOON_BURN_FILTER = 236518,
    SPELL_MOON_BURN_DMG = 236519,
    SPELL_LUNAR_STRIKE = 237632,
    SPELL_LUNAR_BEACON = 236712,
    SPELL_LUNAR_BARRAGE_MARK = 236717,
    SPELL_LUNAR_BARRAGE_AT = 236726,
    SPELL_LUNAR_FIRE = 239264,
    SPELL_EMBRACE_ECLIPSE = 233263,
    SPELL_EMBRACE_ECLIPSE_FRIEND = 233264,
    SPELL_LUNAR_DETONATION = 237782,
    SPELL_UMBRA_DETONATION = 233284,

    //Captain Yathae Moonstrike
    SPELL_INCORPOREAL_SHOT_FILTER = 236304,
    SPELL_INCORPOREAL_SHOT_MARK = 236305,
    SPELL_INCORPOREAL_SHOT_DMG_BETWEEN = 236306,
    SPELL_INCORPOREAL_SHOT_DMG_AOE = 248911,
    SPELL_INCORPOREAL_SHOT_VISUAL = 237570,
    SPELL_TWILIGHT_VOLLEY_AT = 236442,
    SPELL_SHADOW_SHOT = 237630,
    SPELL_CALL_MOONTALON = 236694,
    SPELL_RAPID_SHOT_FILTER_MARK = 236672,
    SPELL_RAPID_SHOT_FILTER_DMG = 236600,
    SPELL_RAPID_SHOT_MARK = 236596,
    SPELL_RAPID_SHOT_DMG = 236603,

    //Moontalon
    SPELL_MOONTALON_DISSOLVE_IN = 239960,
    SPELL_DEATHLY_SCREECH = 236697,

    //achieve add
    SPELL_CRY_OF_THE_LOST_SOULS = 242494,
};

enum eEvents
{
    //Huntress Kasparian
    EVENT_MOON_GLAIVE = 1,
    EVENT_TWILIGHT_GLAIVE = 2,
    EVENT_JUMP_KASPARIAN = 3,
    EVENT_SPECTRAL_GLAIVE = 4,
    EVENT_GLAIVE_STORM = 5,

    //Priestess Lunaspyre
    EVENT_MOON_BURN = 1,
    EVENT_LUNAR_STRIKE = 2,
    EVENT_TP_LUNASPERE = 3,
    EVENT_LUNAR_BEACON = 4,
    EVENT_LUNAR_FIRE = 5,
    EVENT_EMBRACE_ECLIPSE = 6,

    //Captain Yathae
    EVENT_INCORPOREAL_SHOT = 1,
    EVENT_TWILIGHT_VOLLEY = 2,
    EVENT_SHADOW_SHOT = 3,
    EVENT_TP_YATHAE = 4,
    EVENT_CALL_MOONTALON = 5,
    EVENT_RAPID_SHOT = 6,
};

enum Achieve { ACHIEVEMENT = 1 };

uint32 const sistersEntry[3] =
{
    NPC_HUNTRESS_KASPARIAN,
    NPC_PRIESTESS_LUNASPYRE,
    NPC_CAPTAIN_YATHAE
};

Position const sistersPos[3] =
{
    {6208.61f, -1026.84f, 2899.56f, 2.77f},
    {6208.68f, -1037.31f, 2899.55f, 2.97f},
    {6215.13f, -1019.96f, 2899.55f, 2.66f}
};

enum Misc
{
    ACTION_1 = 1,
    ACTION_2,
    ACTION_3,
    ACTION_4,
    ACTION_5,
    ACTION_6,
};

Position const centrPos = { 6190.06f, -1020.03f, 2899.50f };

void AddSC_boss_sisters_of_moon()
{
    
}
