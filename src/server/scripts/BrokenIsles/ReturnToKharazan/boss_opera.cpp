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

#include "new_karazhan.h"

enum Says
{
    /// Opera: Wikket

        // Galindre
    SAY_GALINDRE_AGGRO = 0,
    SAY_MAGNIFICENT = 1,
    SAY_MAGNIFICENT_WARN = 2,

    // Elfyra
    SAY_ELFYRA_AGGRO = 0,
    SAY_ELFYRA_GRAVITY = 1,
    SAY_ELFYRA_ASSISTANTS = 2,
    SAY_ELFYRA_DEATH = 3,

    /// Opera: Westfall

        //Toe
        SAY_TOE_AGGRO = 0,
        SAY_TOE_TIME_OUT = 1,
        SAY_TOE_RETURN_FIGHT = 2,
        SAY_TOE_FLAME_GALE = 3,
        SAY_TOE_DEATH = 4,

        /// Opera: Beautiful Beast
        SAY_COGGLESTON_AGGRO = 0,
        SAY_COGGLESTON_SUMMON = 1,
        SAY_COGGLESTON_DEATH = 2,

        SAY_CAULDRONS_LEFTOVERS = 0,
        SAY_CAULDRONS_DEATH = 1,

        SAY_LUMINORE_HEAT_WAVE = 0,
        SAY_LUMINORE_DEATH = 1,

        SAY_BABBLET_FIXATE = 0,
        SAY_BABBLET_DEATH = 1,
};

enum Spells
{
    ///Opera: Other
        //Monkey King
    SPELL_SHADOWSTEP = 108611,

    //Barnes
    SPELL_FEIGN_DEATH = 196391,
    SPELL_BLINK_VISUAL = 232198,

    /// Opera: Wikket
    SPELL_WIKKET_BOND = 231869,
    SPELL_SHARED_HEALTH = 229010,
    SPELL_NAUGHTY_INTRO_CONVERS = 227864,
    //Galindre
    SPELL_MAGIC_MAGNIFICENT = 232235, // Intro visual
    SPELL_FLASHY_BOLT = 227341,
    SPELL_WONDROUS_RADIANCE = 227410,
    SPELL_MAGIC_MAGNIFICENT_IMMUNE = 227346,
    SPELL_MAGIC_MAGNIFICENT_DMG = 227776,
    SPELL_MAGIC_MAGNIFICENT_UNK = 227347, //?
    //Elfyra
    SPELL_RIDE_VEH_BROOM = 227821,
    SPELL_DREARY_BOLT = 227543,
    SPELL_SUMMON_ASSISTANTS = 227477,
    SPELL_MODSCALE = 214567,
    SPELL_DEFY_GRAVITY = 227447,

    /// Opera: Westfall
        //Mrrgria Summons
        SPELL_POISONOUS_SHANK_FILTER = 228065,
        SPELL_POISONOUS_SHANK_TP = 227319,
        SPELL_POISONOUS_SHANK_DMG = 227325,

        //Toe summons
        SPELL_BUBBLE_BLAST = 227420,

        //Toe
        SPELL_BURNING_LEG_SWEEP = 227568,
        SPELL_DASHING_FLAME_GALE = 227449,
        SPELL_DASHING_FLAME_GALE_FILTER = 227452,
        SPELL_DASHING_FLAME_GALE_CHARGE = 227453,
        SPELL_DASHING_FLAME_GALE_AT = 227467,

        //Mrrgria
        SPELL_THUNDER_RITUAL = 227777,
        SPELL_WASH_AWAY_FILTER = 227783,
        SPELL_WASH_AWAY_AT = 227790,
        SPELL_STUN = 78320,

        /// Opera: Beautiful Beast
        SPELL_EMINENCE = 228729,

        //Coggleston
        SPELL_SPECTRAL_SERVICE = 232156,
        SPELL_DENT_ARMOR = 227985,
        SPELL_DINNER_BELL = 227987,
        SPELL_KARA_KAZHAM = 232153,

        //Luminore
        SPELL_CANDLE_HAT = 227497,
        SPELL_BURNING_BLAZE = 228193,
        SPELL_HEAT_WAVE = 228025,

        //Babblet
        SPELL_MAID_ATTIRE = 227505,
        SPELL_SEVERE_DUSTING = 228213,
        SPELL_SEVERE_DUSTING_CONFUSE = 228215,
        SPELL_FIXATE = 228221,

        //Cauldrons
        SPELL_CAULDRON_DRESSING = 227898,
        SPELL_SOUP_SPRAY = 228011,
        SPELL_DRENCHED = 228013,
        SPELL_LEFTOVERS = 228019,
        SPELL_LEFTOVERS_VISUAL = 228015,
};

enum eEvents
{
    ///> Barnes
    EVENT_START_TALK = 1,
    EVENT_END_TALK = 2,
    EVENT_TELEPORT = 3,

    //Opera: Wikket
    EVENT_WIKKET_1 = 4,
    EVENT_WIKKET_2 = 5,
    EVENT_WIKKET_3 = 6,

    //Opera: Westfall
    EVENT_WESTFALL = 7,

    //Opera: Beautiful Beast
    EVENT_BEAUTIFUL_BEAST = 8,
    ///<

        //Wikket bosses
        EVENT_WIK_GALINDRE_1 = 1,
        EVENT_WIK_GALINDRE_2 = 2,
        EVENT_WIK_GALINDRE_3 = 3,
        EVENT_WIK_GALINDRE_4 = 4,
        EVENT_WIK_GALINDRE_FLASHY_BOLT = 5,
        EVENT_WIK_GALINDRE_WONDROUS_RADIANCE = 6,
        EVENT_WIK_GALINDRE_MAGIC_MAGNIFICENT = 7,
        EVENT_WIK_GALINDRE_AGGRO_TALK = 8,

        EVENT_WIK_ELFYRA_DREARY_BOLT = 1,
        EVENT_WIK_ELFYRA_SUM_ASSISTANTS = 2,
        EVENT_WIK_ELFYRA_SUM_ASSISTANTS_2 = 3,
        EVENT_WIK_ELFYRA_DEFY_GRAVITY = 4,

        //Westfall bosses
        EVENT_TOE_BURNING_LEG_SWEEP = 1,
        EVENT_TOE_DASHING_FLAME_GALE = 2,
        EVENT_TOE_DASHING_FLAME_GALE_CHARGE = 3,

        EVENT_MRRG_THUNDER_RITUAL = 1,
        EVENT_MRRG_WASH_AWAY = 2,

        //BB bosses
        EVENT_LUMINORE_BURNING_BLAZE = 1,
        EVENT_LUMINORE_HEAT_WAVE = 2,

        EVENT_CAULDRON_SOUP_SPRAY = 1,
        EVENT_CAULDRON_LEFTOVERS = 2,

        EVENT_BABBLET_FIXATE = 1,
        EVENT_BABBLET_FOLLOW_TARGET = 2,

        EVENT_COGGLESTON_DENT_ARMOR = 1,
        EVENT_SUMMON_HELPERS = 2,
        EVENT_DINNER_BELL = 3,
};

enum eAnim // SMSG_PLAY_ONE_SHOT_ANIM_KIT
{
    MONKEY_KING_PUNCH_ANIM = 9782,
    GALINDRE_UNK_ANIM = 1173,
};

enum eFaction
{
    WEST_FACTION_NEUTRAL_GANGSTERS = 1828,
    WEST_FACTION_NEUTRAL_MURLOCS = 2220,
    WEST_FACTION_AGGRESSIVE = 16,
};

enum Miscs
{
    ACTION_1 = 1,
    ACTION_2,
    ACTION_3,
};

enum MiscEvents
{
    EVENT_1 = 1,
    EVENT_2 = 2,
    EVENT_3 = 3,
    EVENT_4 = 4,
    EVENT_5 = 5,
    EVENT_6 = 6,
};

void AddSC_npc_kara_barnes_new()
{
    
}
