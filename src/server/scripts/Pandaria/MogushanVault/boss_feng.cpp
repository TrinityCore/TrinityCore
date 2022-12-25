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

#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "mogu_shan_vault.h"

enum eSpells
{
    // Shared
    SPELL_SPIRIT_BOLT = 118530,
    SPELL_STRENGHT_OF_SPIRIT = 116363,
    SPELL_DRAW_ESSENCE = 121631,
    SPELL_NULLIFICATION_BARRIER_PLAYERS = 115811,
    SPELL_FENG_THE_ACCURSED_BONUS = 132189,

    // Visuals
    SPELL_SPIRIT_FIST = 115743,
    SPELL_SPIRIT_SPEAR = 115740,
    SPELL_SPIRIT_STAFF = 115742,
    SPELL_SPIRIT_SHIELD = 115741,

    // Spirit of the Fist
    SPELL_LIGHTNING_LASH = 131788,
    SPELL_LIGHTNING_FISTS = 116157,
    SPELL_EPICENTER = 116018,

    // Spirit of the Spear
    SPELL_FLAMING_SPEAR = 116942,
    SPELL_WILDFIRE_SPARK = 116784,
    SPELL_DRAW_FLAME = 116711,
    SPELL_WILDFIRE_INFUSION_STACK = 116821,
    SPELL_WILDFIRE_INFUSION = 116817,
    SPELL_ARCHIMONDES_FIRE = 116787,

    // Spirit of the Staff
    SPELL_ARCANE_SHOCK = 131790,
    SPELL_ARCANE_VELOCITY = 116364,
    SPELL_ARCANE_RESONANCE = 116417,

    // Spirit of the Shield (Heroic)
    SPELL_SHADOWBURN = 131792,
    SPELL_SIPHONING_SHIELD = 118071,
    SPELL_CHAINS_OF_SHADOW = 118783,

    // Stolen Essences of Stone
    SPELL_NULLIFICATION_BARRIER = 115817,
    SPELL_SHROUD_OF_REVERSAL = 115911,

    // Controler Visual
    SPELL_VISUAL_FIST = 105032,
    SPELL_VISUAL_SPEAR = 118485,
    SPELL_VISUAL_STAFF = 118486,
    SPELL_VISUAL_SHIELD = 117303,

    // Inversions Spell
    SPELL_INVERSION = 115972,

    SPELL_EPICENTER_INVERSION = 118300,
    SPELL_LIGHTNING_FISTS_INVERSION = 118302,
    SPELL_ARCANE_RESONANCE_INVERSION = 118304,
    SPELL_ARCANE_VELOCITY_INVERSION = 118305,
    SPELL_WILDFIRE_SPARK_INVERSION = 118307,
    SPELL_FLAMING_SPEAR_INVERSION = 118308,
    SPELL_SIPHONING_SHIELD_INVERSION = 118471,
    SPELL_SHADOWBURN_INVERSION = 132296,
    SPELL_LIGHTNING_LASH_INVERSION = 132297,
    SPELL_ARCANE_SHOCK_INVERSION = 132298,

    // Siphon Shield
    SPELL_SUMMON_SHIELD = 117203,
    SPELL_TOGGLE_SHIELD = 121296,
    SPELL_SHIELD_DISPLAYED = 117763,
    SPELL_SHIELD_VISUAL = 117240,
    SPELL_SOUL_FRAGMENT = 45537,
    SPELL_SUMMON_SOUL_FRAGMENT = 117717,
    SPELL_BACK_TO_FENG = 117781,
    SPELL_LINKED_SHIELD = 45537,

    // Soul Fragment
    SPELL_SOUL_DISPLAY = 32395,
    SPELL_ICE_TRAP = 135382
};

enum eEvents
{
    EVENT_DOT_ATTACK = 1,
    EVENT_RE_ATTACK = 2,

    EVENT_LIGHTNING_FISTS = 3,
    EVENT_EPICENTER = 4,

    EVENT_WILDFIRE_SPARK = 5,
    EVENT_DRAW_FLAME = 6,

    EVENT_ARCANE_VELOCITY = 7,
    EVENT_ARCANE_VELOCITY_END = 8,
    EVENT_ARCANE_RESONANCE = 9,
    EVENT_SPIRIT_BOLTS = 10,

    EVENT_SIPHONING_SHIELD = 11,
    EVENT_CHAINS_OF_SHADOW = 12,

    EVENT_SHIELD_CASTSOULS = 13,
    EVENT_SHIELD_CHECKSOULS = 14,
    EVENT_SHIELD_BACK = 15,
    EVENT_SHIELD_DESTROY = 16,
    EVENT_SOUL_WALK = 17,
    EVENT_SOUL_GROW = 18,
    EVENT_SHIELD_BARRIER = 19
};

enum eFengPhases
{
    PHASE_NONE = 0,
    PHASE_FIST = 1,
    PHASE_SPEAR = 2,
    PHASE_STAFF = 3,
    PHASE_SHIELD = 4
};

enum eTalk
{
    TALK_AGGRO = 0,
    TALK_PHASE_1 = 1,
    TALK_PHASE_2 = 2,
    TALK_PHASE_3 = 3,
    TALK_PHASE_4 = 4,
    TALK_DEATH = 5,
    TALK_SLAY = 6
};

enum EquipId
{
    EQUIP_ID_FISTS = 82769,
    EQUIP_ID_SPEAR = 82770,
    EQUIP_ID_STAFF = 82771,
    EQUIP_ID_HAXE = 61887, // Not exactly the right weapon... - not found in [82760, 82780]
    EQUIP_ID_SHIELD = 82767, // Shield
};

enum eShieldPhases
{
    PHASE_INACTIVE = 0, // Feng isn't using Siphoning Shield
    PHASE_THROWN = 1, // Feng has just thrown the shield, but it's not on the floor yet
    PHASE_LANDED = 2, // Shield on the ground, casting
    PHASE_INTERRUPTED = 3, // Shield has been recalled by Feng, stop casting on the ground
    PHASE_BACK = 4, // Shield is flying back to Feng
};

enum eSoulActions
{
    ACTION_SOUL_HOME = 20,
    ACTION_SOUL_KILLED = 21,
    ACTION_SOUL_REMOVE = 22
};

#define SHIELD_ON_FENG 5
#define DISPLAYID_SHIELD 11686

Position modPhasePositions[4] =
{
    {4063.26f, 1320.50f, 466.30f, 5.5014f}, // Phase Fist
    {4021.17f, 1320.50f, 466.30f, 3.9306f}, // Phase Spear
    {4021.17f, 1362.80f, 466.30f, 2.0378f}, // Phase Staff
    {4063.26f, 1362.80f, 466.30f, 0.7772f}, // Phase Shield
};


uint32 statueEntryInOrder[4] = { GOB_FIST_STATUE,   GOB_SPEAR_STATUE,   GOB_STAFF_STATUE,   GOB_SHIELD_STATUE };
uint32 controlerVisualId[4] = { SPELL_VISUAL_FIST, SPELL_VISUAL_SPEAR, SPELL_VISUAL_STAFF, SPELL_VISUAL_SHIELD };
uint32 fengVisualId[4] = { SPELL_SPIRIT_FIST, SPELL_SPIRIT_SPEAR, SPELL_SPIRIT_STAFF, SPELL_SPIRIT_SHIELD };

#define MAX_INVERSION_SPELLS    10
uint32 inversionMatching[MAX_INVERSION_SPELLS][2] =
{
    {SPELL_EPICENTER,        SPELL_EPICENTER_INVERSION},
    {SPELL_LIGHTNING_FISTS,  SPELL_LIGHTNING_FISTS_INVERSION},
    {SPELL_ARCANE_RESONANCE, SPELL_ARCANE_RESONANCE_INVERSION},
    {SPELL_ARCANE_VELOCITY,  SPELL_ARCANE_VELOCITY_INVERSION},
    {SPELL_WILDFIRE_SPARK,   SPELL_WILDFIRE_SPARK_INVERSION},
    {SPELL_FLAMING_SPEAR,    SPELL_FLAMING_SPEAR_INVERSION},
    {SPELL_SHADOWBURN,       SPELL_SHADOWBURN_INVERSION},
    {SPELL_LIGHTNING_LASH,   SPELL_LIGHTNING_LASH_INVERSION},
    {SPELL_ARCANE_SHOCK,     SPELL_ARCANE_SHOCK_INVERSION},
    {SPELL_SIPHONING_SHIELD, SPELL_SIPHONING_SHIELD_INVERSION}
};

#define MAX_DIST    60.0f
Position fengCenterPos = { 4041.979980f, 1341.859985f, 466.388000f, 3.140160f };

// Positions for Siphoning Shield
Position shieldPositions[3] =
{
    {4067.59f, 1326.71f, 466.30f, 2.579275f},
    {4020.77f, 1363.22f, 466.30f, 5.500957f},
    {4036.06f, 1362.29f, 466.30f, 4.253744f}
};

#define SHIELD_POSITIONS_COUNT 3;

void AddSC_boss_feng()
{
    
}
