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
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "AreaTriggerTemplate.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_FEEDING_TIME = 0,
    SAY_GATHERING_CLOUDS = 1,
    SAY_RAZOR_WING = 2,
    SAY_AGGRO = 3,
    SAY_FEEDING_TIME_1 = 4,
    SAY_GATHERING_CLOUDS_1 = 5,
    SAY_RAZOR_WING_1 = 6,
};

enum Spells
{
    SPELL_SPIDER_START = 210284,
    SPELL_ENERGY_TRACKER_TRANSFORM = 225364,
    SPELL_ENERGY_TRANSFORM_COST = 210366,
    SPELL_TRANSFORM_DISSOLVE = 210309,
    SPELL_WEB_WRAPPED = 215188,
    SPELL_BERSERK = 26662,

    //Phase One - Spider form
    SPELL_SPIDER_TRANSFORM_DUMMY = 210326,
    SPELL_SPIDER_TRANSFORM = 210292,
    SPELL_WEB_OF_PAIN_FILTER = 215288,
    SPELL_FEEDING_TIME = 212364,
    SPELL_FEEDING_TIME_2 = 214305,
    SPELL_FEEDING_TIME_FILTER = 214311,
    SPELL_FEEDING_TIME_SUM_STALKER = 214275,
    SPELL_VILE_AMBUSH_FILTER = 214328,
    SPELL_VILE_AMBUSH_MISSILE = 214339,
    SPELL_VILE_AMBUSH_JUMP = 214346,
    SPELL_VILE_AMBUSH_VISUAL_JUMP = 215253,
    SPELL_NECROTIC_VENOM = 215443,
    SPELL_VENOMOUS_POOL_AOE = 213781,
    SPELL_PAIN_LASH = 215306,
    SPELL_TANGLED_WEBS_AT = 217982,

    //Phase Second - Darkwing form
    SPELL_DARKWING_FORM_DUMMY = 210308,
    SPELL_DARKWING_FORM = 210293,
    SPELL_TWISTING_SHADOWS_FILTER = 210864,
    SPELL_TWISTING_SHADOWS_AT = 210792,
    SPELL_GATHERING_CLOUDS = 212707,
    SPELL_SHIMMERING_FEATHER_TRIG = 213064,
    SPELL_RAZOR_WING_FILTER = 210553,
    SPELL_RAZOR_WING = 210547,
    SPELL_RAZOR_WING_VISUAL = 212842,
    SPELL_RAZOR_WING_DMG = 212853,
    SPELL_DARK_STORM_FILTER = 210948,
    SPELL_DARK_STORM_AURA = 211122,
    SPELL_DARK_STORM_AT = 211124,
    SPELL_RAKING_TALONS = 215582,
    SPELL_RAKING_TALONS_2 = 222037,
    SPELL_FOUL_WINDS = 211137,
    SPELL_VIOLENT_WINDS = 218124,

    //Other
    SPELL_DRUID_TRANSFORM = 226017,
    SPELL_SPIDER_TRANSFORM_2 = 228523,
    SPELL_SHIMMERING_FEATHER = 212993,
    SPELL_SHIMMERING_FEATHER_OVERRIDE = 221913,
    SPELL_SWARM = 214450,
};

enum eEvents
{
    //Phase One - Spider form
    EVENT_WEB_OF_PAIN = 1,
    EVENT_FEEDING_TIME = 2,
    EVENT_NECROTIC_VENOM = 3,
    EVENT_SPIDER_TRANSFORM = 4,

    //Phase Second - Darkwing form
    EVENT_DARKWING_FORM = 5,
    EVENT_TWISTING_SHADOWS = 6,
    EVENT_GATHERING_CLOUDS = 7,
    EVENT_SUM_SHIMMERING_FEATHER = 8,
    EVENT_RAZOR_WING = 9,
    EVENT_DARK_STORM = 10,
    EVENT_RAKING_TALONS = 11,
    EVENT_VIOLENT_WINDS = 12,

    EVENT_REACT_AGGRESSIVE = 13,
    EVENT_NEXT_PLATFORM = 14,
    EVENT_CHECH_PLAYER = 15,
};

enum eTransform
{
    SPIDER_FORM = 1,
    DARKWING_FORM = 2
};

enum EGmisc
{
    //SMSG_SET_MOVEMENT_ANIM_KIT
    ANIM_1 = 753,
    ANIM_2 = 2737,

    //SMSG_PLAY_ONE_SHOT_ANIM_KIT
    ANIM_3 = 9779,

    SPELL_EGG_DUMMY_1 = 223438,
    SPELL_EGG_DUMMY_2 = 215508,
    SPELL_SUM_SKITTERING_SPIDERLING = 215505,
};

enum Misc
{
    EVENT_1 = 1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
};
Position const platformPos[3] =
{
    {11405.59f, 11400.70f, -85.32f},
    {11376.42f, 11224.97f, -102.0f},
    {11538.02f, 11298.43f, -87.06f}
};

Position const spiderPos[12] =
{
    {11411.42f, 11402.46f, -51.12f},
    {11413.96f, 11369.06f, -50.60f},
    {11434.47f, 11374.71f, -51.50f},
    {11373.11f, 11388.3f,  -50.58f},
    {11343.57f, 11240.51f, -44.54f},
    {11382.04f, 11262.68f, -53.15f},
    {11403.85f, 11224.34f, -51.75f},
    {11377.61f, 11199.40f, -45.50f},
    {11537.53f, 11264.99f, -47.43f},
    {11503.03f, 11288.73f, -45.12f},
    {11522.21f, 11323.06f, -43.80f},
    {11552.95f, 11302.63f, -38.93f}
};

Position const twistBridgePos[5] =
{
    {11362.16f, 11372.33f, -87.34f},
    {11449.68f, 11389.96f, -85.37f},
    {11365.16f, 11308.75f, -98.53f},
    {11491.63f, 11268.83f, -89.58f},
    {11456.38f, 11238.37f, -93.77f}
};

Position const eventTwistBridgePos[7] =
{
    {11446.38f, 11233.84f, -95.04f},
    {11363.54f, 11370.07f, -87.67f},
    {11421.69f, 11379.41f, -85.65f},
    {11376.41f, 11396.77f, -84.34f},
    {11385.76f, 11380.19f, -85.75f},
    {11427.25f, 11392.06f, -85.07f},
    {11443.09f, 11387.54f, -85.45f}
};

void AddSC_elerethe_renferal()
{
    
}
