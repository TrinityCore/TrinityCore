/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#ifndef DEF_DEADMINES_H
#define DEF_DEADMINES_H

#define DMScriptName "instance_deadmines"

enum Data
{
    DATA_GLUBTOK,
    DATA_HELIX,
    DATA_FOEREAPER,
    DATA_RIPSNARL,
    DATA_COOKIE,
    DATA_CANNON_BLAST_TIMER,
    DATA_VANESSA,
    DATA_VANNESSA_NIGHTMARE,
    DATA_NIGHTMARE_HELIX,
    DATA_NIGHTMARE_MECHANICAL,

    EVENT_VISION_OF_THE_PAST,
    DATA_ALLIANCE_WARRIOR,
    DATA_ALLIANCE_PRIEST,
    DATA_ALLIANCE_HUNTER,
    DATA_ALLIANCE_ROGUE,
    DATA_ALLIANCE_MAGE,
    DATA_VANESSA_VANCLEEF,
    DATA_EDWIN_VANCLEEF,

    MAX_BOSSES
};

enum eCreatures
{
    NPC_GLUBTOK                     = 47162,
    NPC_OAF                         = 47297,
    NPC_HELIX_GEARBREAKER           = 47296,
    NPC_GENERAL_PURPOSE_BUNNY_JMF   = 45979,
    NPC_GENERAL_PURPOSE_BUNNY_JMF2  = 47242,
    NPC_OGRE_HENCHMAN               = 48230,
    NPC_FOE_REAPER_5000             = 43778,
    NPC_MINE_RAT                    = 51462,
    NPC_ADMIRAL_RIPSNARL            = 47626,
    NPC_VAPOR                       = 47714,
    NPC_FIRE_WALL                   = 40859,
    NPC_HARVEST_TARGET              = 47468,
    NPC_CAPTAIN_COOKIE              = 47739,
    NPC_VANESSA_VANCLEEF            = 49429,
    NPC_VANESSA_BOSS                = 49541,
    NPC_VANESSA_NOTE                = 49564,
    NPC_SCORCH_MARK_BUNNY_JMF       = 48446,
    NPC_TRAP_BUNNY                  = 49454,
    NPC_STEAM_VALVE                 = 49457,
    NPC_ROPE                        = 49550,
    NPC_ROPE_ANCHOR                 = 49552,
    NPC_DEFIAS_REAPER               = 47403,
    NPC_PROTOTYPE_REAPER            = 49208,
    NPC_COOKIES_CAULDRON            = 47754,

    NPC_DEFIAS_SHADOWGUARD          = 48505,
    NPC_DEFIAS_ENFORCER             = 48502,
    NPC_DEFIAS_BLOODWIZARD          = 48417,
    NPC_DEFIAS_PIRATE               = 48522,
    NPC_HELIX_CREW                  = 49136,

    //Nightmare NPC
    NPC_VANESSA_NIGHTMARE           = 49671,
    NPC_GLUBTOK_NIGHTMARE           = 49670,
    NPC_FIRE_BUNNY                  = 51594,
    NPC_COLAPSING                   = 49481,
    NPC_HELIX_NIGHTMARE             = 49674,
    NPC_NIGHTMARE_SPIDER            = 49493,
    NPC_MAIN_SPIDER                 = 49494,
    NPC_CHATTERING_HORROR           = 49495,
    NPC_SPARK                       = 49520,
    NPC_MECHANICAL_NIGHTMARE        = 49681,

    NPC_ENRAGED_WORGEN              = 49532,
    NPC_EMME_HARRINGTON             = 49534,
    NPC_ERIK_HARRINGTON             = 49535,
    NPC_CALISSA_HARRINGTON          = 49536,
    NPC_JAMES_HARRINGTON            = 49539,

    // Vision of the past
    NPC_EDWIN_VANCLEEF              = 42697,
    NPC_VANESSA_VANCLEEF_2          = 42371,
    NPC_ALLIANCE_WARRIOR            = 42699,
    NPC_ALLIANCE_HUNTER             = 42701,
    NPC_ALLIANCE_MAGE               = 42702,
    NPC_ALLIANCE_PRIEST             = 42703,
    NPC_ALLIANCE_ROGUE              = 42700

};

enum GameObjects
{
    GO_FACTORY_DOOR                 = 13965, // Door after Glubtok
    GO_IRONCLAD_DOOR                = 16397, // Door before ship
    GO_FOUNDRY_DOOR                 = 16399, // Door after Foe Reaper 5000
    GO_HEAVY_DOOR                   = 17154, // Door before Foe Reaper 5000
    GO_HEAVY_DOOR_HELIX             = 16400, // Door after helix

    GO_DEFIAS_CANNON                = 16398,
    GO_MR_SMITE_CHEST               = 144111
};

enum eSound
{
    SOUND_CANNONFIRE                = 1400,
    SOUND_DESTROYDOOR               = 3079,
};

enum eAcievement
{
    ACHIEVE_RAT_PACK                = 5367,
};

enum sharedSpells
{
    SPELL_NIGHTMARE_ELIXIR      = 92113,
    SPELL_OFFLINE               = 88348,
};

const Position CookieSpawn =
{
    -88.1319f, -819.33f, 39.23453f, 0.0f
};

#endif
