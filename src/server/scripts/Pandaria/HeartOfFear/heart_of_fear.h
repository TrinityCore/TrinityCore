/*
 * Copyright (C) 2022 BfaCore Reforged
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

#ifndef HEART_OF_FEAR_H_
#define HEART_OF_FEAR_H_

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"
#include "Group.h"
#include "GameObject.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"

enum eData
{
    DATA_ZORLOK         = 0,
    DATA_TAYAK          = 1,
    DATA_GARALON        = 2,
    DATA_MELJARAK       = 3,
    DATA_UNSOK          = 4,
    DATA_SHEKZEER       = 5,
    DATA_MAX_BOSS_DATA  = 6
};

enum eSpells
{
    // --- Blade Lord Ta'yak (spells shared with trash) ---
    SPELL_TEMPEST_SLASH         = 122842,
    SPELL_UNSEEN_STRIKE_TR      = 122949,   // Unattackable + Speed 200%. Triggers SPELL_UNSEEN_STRIKE_DMG after 5 secs, SPELL_UNSEEN_STRIKE_MKR on target, SPELL_UNSEEN_STRIKE_INV on self.
    SPELL_UNSEEN_STRIKE_MKR     = 123017,   // Target marker visual aura.
    SPELL_WIND_STEP_TP          = 123175,   // Teleport. Triggers SPELL_WIND_STEP_DUMMY.
    SPELL_OVERWHELMING_ASS      = 123474,

    // --- Grand Empress Shek'zeer ---
    SPELL_CONVERT_SERVANT       = 123713,   // Player converted into Servant of the empress. Also used in instance_heart_of_fear.cpp for IsWipe()

    // Trashes
    SPELL_ARTERIAL_SPIRIT       = 123422,
    SPELL_GOUGE_THROAT          = 123434,
    SPELL_SLOW                  = 31589,
    SPELL_VITAL_STRIKES         = 123421,
    SPELL_UNDYING_DEVOTION      = 123502,
    SPELL_BRAIN_FREEZE          = 57761,
    SPELL_DISMANTLED_ARMOR      = 123417,
    SPELL_MASS_SPELL_REFLEXION  = 124817,
    SPELL_SHIELD_SLAM           = 124815,
    SPELL_STUNNING_STRIKE       = 123420,
    SPELL_BLURRING_SLASH        = 123437,
    SPELL_RIPOSTE               = 123436,
    SPELL_ICE_TRAP              = 135382,
    SPELL_MASH_AND_GNASH        = 124809,
    SPELL_JAWBONE_SLAM          = 123490,
    SPELL_WIND_SLASH            = 125716,
    SPELL_GALE_FORCE_WINDS      = 123497,
    SPELL_WINDBURST             = 123499,
    SPELL_SUMMON_ZEPHYR         = 124085,
    SPELL_SWIFT_STEP            = 125742,
    SPELL_ALMOST_UNSEEN_STRIKE  = 125810,
    SPELL_ZEALOUS_RUSH          = 123622,
    SPELL_UNDERWHELMING_ASSAULT = 125728,
    SPELL_GUST                  = 124072,
    SPELL_BURST                 = 125054,
    SPELL_ZEPHYR                = 124087,
    SPELL_CARAPACE              = 126928,
    SPELL_SEPARATION_ANXIETY    = 126933,
    SPELL_SWARMGUARDS_AEGIS     = 126926,
    SPELL_AMBER_VOLLEY          = 126937,
    SPELL_AMBER_VOLLEY_MISSILE  = 126941,
    SPELL_GREVIOUS_WHIRL        = 126907,
    SPELL_MORTAL_REND           = 126901,
    SPELL_BURNING_STING         = 125490,
    SPELL_SEARING_SLASH         = 125480,
    SPELL_AMBER_SPEW            = 125069,
    SPELL_SLAM                  = 125081,
    SPELL_CORROSIVE_AURA        = 122348,
    SPELL_AMBER_EMANATION       = 125426,
    SPELL_AMBER_INFUSION        = 125432,
    SPELL_BAND_OF_VALOR         = 125422,
    SPELL_TOXIC_HIVEBOMB        = 125865,
    SPELL_TOXIC_SPEW            = 125871,
    SPELL_DISPATCH              = 125877,
    SPELL_SONIC_BLADE           = 125888,
    SPELL_CRY_HAVOC             = 125907,
    SPELL_FRENZIED_ASSAULT      = 125900,

    /// Reshape Life (Un'sok)
    SPELL_RESHAPE_LIFE          = 122370,

    // Generic enrage spell
    SPELL_BERSERK               = 26662
};

enum eActions
{
    // Ta'yak
    ACTION_TAYAK_TALK_TRASH     = 1,

    // Garalon
    ACTION_GARALON_VISIBLE      = 8,

    // Shek'zeer
    ACTION_SHEKZEER_COMBAT      = 9,

    // Trash
    ACTION_AMBER_VOLLEY         = 10,
    ACTION_REACH_HOME           = 11
};

enum eCreatures
{
    // Boss
    NPC_ZORLOK                      = 62980,
    NPC_TAYAK                       = 62543,
    NPC_GARALON                     = 62164,
    NPC_MELJARAK                    = 62397,
    NPC_UNSOK                       = 62511,
    NPC_SHEKZEER                    = 62837,

    // Generic / Trash
    NPC_SRATHIK_SHIELD_MASTER       = 63032,
    NPC_ZARTHIK_SUPPLICANT          = 63853,
    NPC_SETTHIK_ZEPHYRIAN           = 63593,
    NPC_KORTHIK_SILENTWING          = 64355,
    NPC_ZARTHIK_SUPPLICANT_2        = 67177,
    NPC_SETTHIK_GALESLICER          = 64353,
    NPC_ENSLAVED_BONESMASHER        = 63030,
    NPC_ZARTHIK_SUPPLICANT_3        = 66181,
    NPC_SETTHIK_FANATIC             = 63031,
    NPC_INSTRUCTOR_KLITHAK          = 64338,
    NPC_INSTRUCTOR_TAKTHOK          = 64339,
    NPC_INSTRUCTOR_MALTIK           = 64340,
    NPC_INSTRUCTOR_ZARIK            = 64341,
    NPC_ZARTHIK_ZEALOT              = 63035,
    NPC_KORTHIK_SWARMER             = 64357,
    NPC_SETTHIK_GUSTWING            = 63592,
    NPC_COAGULATED_AMBER            = 63597,
    NPC_COAGULATED_AMBER2           = 63594,
    NPC_SRATHIK_AMBERCALLER         = 64917,
    NPC_SRATHIK_POOLTENDER          = 63570,
    NPC_ZARTHIK_AUGURER             = 64454,
    NPC_SETTHIK_WINDBLADE_TRASH     = 64453,
    NPC_KORTHIK_WARSINGER           = 64458
};

enum eGameObjects
{
    GOB_ANTECHAMBER_DOOR_ENTRANCE   = 214483,
    GOB_ANTECHAMBER_DOOR_EXIT       = 214484,
    GOB_ORATIUM_DOOR_ENTRANCE       = 214485,
    GOB_QUARTERS_DOOR_ENTRANCE      = 214486,
    GOB_QUARTERS_DOOR_EXIT          = 214487,
    GOB_STAIRWAYS_DOOR_EXIT         = 214488,
    GOB_BALCONY_DOOR_EXIT           = 214489,
    GOB_ATRIUM_DOOR_ENTRANCE        = 214490,
    GOB_ATRIUM_DOOR_EXIT            = 214491,
    GOB_SANCTUM_DOOR_ENTRANCE       = 214492,
    GOB_HEARTOFFEAR_DOOR_ENTRANCE   = 214493,

    // Zor'lok Barriers
    GOB_ARENA_WALLS                 = 212916,
    GOB_FINAL_PHASE_WALLS           = 212943,

    // Garalon Doors
    GOB_DOOR_TO_MELJARAK            = 214634,
    GOB_GARALON_WALLS               = 212695,

    // Mel'ajrak weapon rack
    GOB_WEAPON_RACK                 = 211675,

    // Shek'zeer Gameobjects
    GOB_EMPRESS_CHAMBER             = 213277,
    GOB_MANTID_QUEEN_CEIL           = 213276
};

enum eWeapons
{
    // --- Bosses (also used by some trash) ---
    EQUIP_ZORLOK                    = 85947,
    EQUIP_TAYAK_MELJARAK            = 85401,
    EQUIP_UNSOK                     = 86983,

    // --- Trashes ---
    EQUIP_TRASH_1                   = 84677,
    EQUIP_TRASH_2                   = 45926,
    EQUIP_TRASH_3                   = 88684,
    EQUIP_TRASH_4                   = 85401,
    EQUIP_TRASH_5                   = 85576,
    EQUIP_TRASH_6                   = 85399,
    EQUIP_TRASH_7                   = 82849,
    EQUIP_TRASH_8                   = 84676,
    EQUIP_TRASH_9                   = 84769
};

enum eEvents
{
    // Trashes
    EVENT_ARTERIAL_SPIRIT,
    EVENT_GOUGE_THROAT,
    EVENT_SLOW,
    EVENT_VITAL_STRIKES,
    EVENT_UNDYING_DEVOTION,
    EVENT_BRAIN_FREEZE,
    EVENT_DISMANTLED_ARMOR,
    EVENT_MASS_SPELL_REFLEXION,
    EVENT_SHIELD_SLAM,
    EVENT_STUNNING_STRIKE,
    EVENT_BLURRING_SLASH,
    EVENT_RIPOSTE,
    EVENT_ICE_TRAP,
    EVENT_MASH_AND_GNASH,
    EVENT_JAWBONE_SLAM,
    EVENT_WIND_SLASH,
    EVENT_GALE_FORCE_WINDS,
    EVENT_WINDBURST,
    EVENT_SUMMON_ZEPHYR,
    EVENT_SWIFT_STEP,
    EVENT_WIND_STEP,
    EVENT_OVERWHELMING_ASSAULT,
    EVENT_TRASH_TEMPEST_SLASH,
    EVENT_TRASH_UNSEEN_STRIKE,
    EVENT_ZEALOUS_RUSH,
    EVENT_UNDERWHELMING_ASSAULT,
    EVENT_ALMOST_UNSEEN_STRIKE,
    EVENT_GUST,
    EVENT_BURST,
    EVENT_CARAPACE,
    EVENT_AMBER_VOLLEY,
    EVENT_GREVIOUS_WHIRL,
    EVENT_MORTAL_REND,
    EVENT_ATRIUM_PATH,
    EVENT_BURNING_STING,
    EVENT_SEARING_SLASH,
    EVENT_AMBER_SPEW,
    EVENT_SLAM,
    EVENT_AMBER_INFUSION,
    EVENT_TOXIC_HIVEBOMB,
    EVENT_TOXIC_SPEW,
    EVENT_DISPATCH,
    EVENT_SONIC_BLADE,
    EVENT_CRY_HAVOC,
    EVENT_FRENZIED_ASSAULT,
    EVENT_ZEPHYR_MOVE
};

#define DISPLAYID_INVISIBLE 11686

#endif // HEART_OF_FEAR_H_
