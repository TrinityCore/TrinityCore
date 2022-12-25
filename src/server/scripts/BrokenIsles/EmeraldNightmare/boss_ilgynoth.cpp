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

#include "emerald_nightmare.h"
#include "AreaTriggerAI.h"
#include "AreaTrigger.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_ANNOUNCE = 4,
    SAY_EVADE = 5,
    SAY_DEATH = 6,
};

enum Spells
{
    //ilgynoth
    SPELL_DARK_RECONSTITUTION = 210781,
    SPELL_FINAL_TORPOR = 223121,
    SPELL_CURSED_BLOOD = 215128,
    SPELL_CURSED_BLOOD_EXPLOSION = 215143,
    SPELL_DARKEST_NIGHTMARE_AT = 210786,
    SPELL_KNOCKBACK_AT = 224929,
    SPELL_RECOVERY_TELEPORT = 222531,
    SPELL_KILL_WHISPER = 222173, //? Il'gynoth Kill Whisper

    //Eye ilgynoth
    SPELL_NIGHTMARE_GAZE = 210931,
    SPELL_SUM_NIGHTMARE_HORROR = 210289,

    //Mythic
    SPELL_DEATH_BLOSSOM = 218415, //Remove AT cast
    SPELL_DEATH_BLOSSOM_AT = 215761,
    SPELL_DEATH_BLOSSOM_VISUAL = 215763,
    SPELL_DEATH_BLOSSOM_DMG = 215836,
    SPELL_DISPERSED_SPORES = 215845,
    SPELL_VIOLENT_BLOODBURST = 215971,
    SPELL_VIOLENT_BLOODBURST_AT = 215975,
    SPELL_SUM_SHRIVELED_EYESTALK = 216131,

    //Dominator Tentacle - 105304
    SPELL_NIGHTMARISH_FURY = 215234,
    SPELL_GROUND_SLAM_DMG = 208689,
    SPELL_GROUND_SLAM_VISUAL = 212723,
    SPELL_RUPTURING_ROAR = 208685,

    //Deathglare Tentacle - 105322
    SPELL_MIND_FLAY = 208697,

    //Corruptor Tentacle - 105383
    SPELL_SPEW_CORRUPTION = 208928,

    //Nightmare Horror - 105591
    SPELL_SEEPING_CORRUPTION = 209387,
    SPELL_EYE_OF_FATE = 210984,

    //Nightmare Ichor - 105721
    SPELL_FIXATE = 210099,
    SPELL_NIGHTMARE_EXPLOSION = 209471,
    SPELL_NIGHTMARE_EXPLOSION_PCT = 210048,
    SPELL_REABSORPTION = 212942,

    //Other
    SPELL_SPAWN_BLOOD = 209965,
};

enum eEvents
{
    EVENT_SUMMON_1 = 1,
    EVENT_SUMMON_2 = 2,
    EVENT_SUMMON_3 = 3,
    EVENT_SUMMON_4 = 4,
    EVENT_SUMMON_5 = 5,
    EVENT_SUMMON_6 = 6,
    EVENT_SUMMON_7 = 7,
    EVENT_DARK_RECONSTITUTION = 8,
    EVENT_CURSED_BLOOD = 9,
    EVENT_EYE_RESPAWN = 10,
    EVENT_ANNOUNCE = 11,
    EVENT_ANNOUNCE_FINAL = 12,
    EVENT_CHECK_TARGET_DISTANCE = 13,

    //Mythic
    EVENT_SUM_SHRIVELED_EYESTALK,
    EVENT_DEATH_BLOSSOM,

    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_5,
    EVENT_4,
};

Position const sumPos[4] =
{
    {-12818.1f, 12328.3f, -245.72f, 3.79f}, //105906 - Eye of Ilgynoth
    {-12843.59f, 12331.40f, -246.01f, 3.56f},
    {-12821.79f, 12302.79f, -246.01f, 3.83f},
    {-12856.12f, 12296.79f, -253.16f, 0.72f} //Horror
};

Position const blossPos[22] =
{
    {-12843.5f, 12321.6f, -250.77f},
    {-12840.4f, 12297.1f, -251.92f},
    {-12822.7f, 12281.8f, -250.72f},
    {-12832.5f, 12290.1f, -251.82f},
    {-12848.9f, 12327.6f, -250.40f},
    {-12837.4f, 12314.9f, -250.81f},
    {-12831.4f, 12308.4f, -250.07f},
    {-12824.1f, 12300.7f, -248.79f},
    {-12814.5f, 12290.5f, -248.35f},
    {-12848.0f, 12303.3f, -252.25f},
    {-12854.7f, 12310.2f, -252.30f},
    {-12861.6f, 12319.4f, -252.85f},
    {-12852.3f, 12319.2f, -251.93f},
    {-12844.8f, 12311.6f, -251.94f},
    {-12839.7f, 12305.9f, -251.59f},
    {-12831.2f, 12298.9f, -250.53f},
    {-12823.5f, 12291.4f, -249.49f},
    {-12830.6f, 12277.5f, -252.17f},
    {-12842.2f, 12285.1f, -253.12f},
    {-12852.0f, 12290.9f, -253.25f},
    {-12858.0f, 12298.5f, -253.22f},
    {-12864.3f, 12307.0f, -253.70f}
};

void AddSC_ilgynoth()
{
   
}
