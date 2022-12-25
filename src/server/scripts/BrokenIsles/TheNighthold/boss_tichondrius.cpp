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
#include "thenighthold.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "AreaTrigger.h"
#include "AreaTriggerTemplate.h"

enum Says
{
    SAY_AGGRO                       = 0,
    SAY_FEAST_OF_BLOOD              = 1,
    SAY_CARRION_PLAGUE              = 2,
    SAY_CARRION_PLAGUE_HIT_PLAYER   = 3,
    SAY_ECHOES_OF_THE_VOID          = 4,
    SAY_CHANGE_PHASE                = 5,
    SAY_SUMMON_GUARDS               = 6,
    SAY_WIPE                        = 7,
    SAY_KILL_PLAYER                 = 8,
    SAY_DEATH                       = 9,
};

enum Spells
{
    SPELL_BERSERK                   = 62535,
    SPELL_TICH_LIGHT                = 217507,

    SPELL_VAMPIRIC_AURA_AT          = 206892,
    SPELL_VAMPIRIC_HEAL             = 206894,
    SPELL_CARRION_PLAGUE_FILTER     = 212997,
    SPELL_CARRION_PLAGUE            = 206480,
    SPELL_SEEKER_SWARM_FILTER       = 213238,
    SPELL_SEEKER_SWARM_DMG          = 206474,
    SPELL_FEAST_OF_BLOOD            = 208230,
    SPELL_ECHOES_OF_THE_VOID        = 213531,
    SPELL_ECHOES_OF_THE_VOID_DMG    = 213534,
    SPELL_SUM_FEL_SPIRE             = 208369,
    SPELL_ILLUSIONARY_NIGHT         = 206365,
    SPELL_ILLUSIONARY_NIGHT_PHASE   = 206311,

    SPELL_BRAND_OF_ARGUS            = 212794,
    SPELL_BRAND_OF_ARGUS_EXPLOSION  = 212795,
    SPELL_BRAND_OF_ARGUS_VISUAL     = 215413,
    SPELL_FLAMES_OF_ARGUS_AT        = 216465,

    //Tainted Blood
    SPELL_FEAST_OF_BLOOD_JUMP       = 216421,
    SPELL_FEAST_OF_BLOOD_FIXATE     = 216423,

    //Fel Spire
    SPELL_SUM_GO_FEL_SPIRE          = 215668,
    SPELL_FEL_SPIRE_KNOCK           = 216295,
    SPELL_FEL_SPIRE_TICK_AT         = 215875,
    SPELL_FEL_SPIRE_AT              = 213650,
    SPELL_FEL_SPIRE_SHELTER         = 215879,
    SPELL_FEL_SPIRE_VIS_DMG         = 215906,
    SPELL_FEL_SPIRE_DESTROYED       = 215918,

    //Carrion Nightmare
    SPELL_CARRION_NIGHTMARE_VISUAL  = 215973,
    SPELL_CARRION_NIGHTMARE_BEEM    = 215988,

    //Phantasmal Bloodfang
    SPELL_BAT_GHOST_VISUAL          = 215605,
    SPELL_ESSENCE_OF_NIGHT_AT       = 206462,
    SPELL_ESSENCE_OF_NIGHT          = 206466,

    //Felsworn Spellguard
    SPELL_MOD_SCALE                 = 202427,
    SPELL_TELEPORT_OUT              = 142193,
    SPELL_RAPID_PURSUIT             = 216028,
    SPELL_VOLATILE_WOUND            = 216024,
    SPELL_NETHER_ZONE_AT            = 216026,

    //Sightless Watcher
    SPELL_FEL_DISSOLVE_IN           = 211762,
    SPELL_BURNING_SOUL              = 216040,
    SPELL_BURNING_SOUL_DMG          = 216041,
    SPELL_RING_OF_SHADOWS_AT        = 216723,
    SPELL_RING_OF_SHADOWS_VISUAL    = 216727,
};

enum eEvents
{
    EVENT_CARRION_PLAGUE            = 1,
    EVENT_SEEKER_SWARM              = 2,
    EVENT_FEAST_OF_BLOOD            = 3,
    EVENT_ECHOES_OF_THE_VOID        = 4,
    EVENT_ILLUSIONARY_NIGHT_START   = 5,
    EVENT_SUM_GUARDS                = 6,
    EVENT_BRAND_OF_ARGUS            = 7,
};

enum eMisc
{
    //SMSG_SET_AI_ANIM_KIT
    NIGHTMARE_ANIM_1                = 11056,
};

Position const centrPos = { 241.41f, 3399.45f, 171.80f };

Position const nightmarePos[5] =
{
    {240.79f, 3430.17f, 171.8f, 5.09f},
    {241.73f, 3354.39f, 171.8f, 1.45f},
    {252.31f, 3430.54f, 171.8f, 4.58f},
    {289.90f, 3398.10f, 171.8f, 3.05f},
    {210.68f, 3390.30f, 171.8f, 6.28f}
};

Position const guardPos[3] =
{
    {289.26f, 3394.23f, 171.91f, 2.38f},
    {246.59f, 3351.88f, 171.82f, 2.38f},
    {265.80f, 3374.88f, 171.78f, 2.35f}
};

enum Misc
{
    EVENT_1 = 1,
    EVENT_2,
    EVENT_3,
};

void AddSC_boss_tichondrius()
{
    
}
