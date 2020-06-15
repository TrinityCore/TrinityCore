/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef BLACK_TEMPLE_H_
#define BLACK_TEMPLE_H_

#include "CreatureAIImpl.h"

#define BTScriptName "instance_black_temple"
#define DataHeader   "BT"

uint32 const EncounterCount         = 9;

enum BTDataTypes
{
    // Encounter States
    DATA_HIGH_WARLORD_NAJENTUS      = 0,
    DATA_SUPREMUS                   = 1,
    DATA_SHADE_OF_AKAMA             = 2,
    DATA_TERON_GOREFIEND            = 3,
    DATA_GURTOGG_BLOODBOIL          = 4,
    DATA_RELIQUARY_OF_SOULS         = 5,
    DATA_MOTHER_SHAHRAZ             = 6,
    DATA_ILLIDARI_COUNCIL           = 7,
    DATA_ILLIDAN_STORMRAGE          = 8,

    // Additional Data
    DATA_AKAMA_SHADE                = 9,

    DATA_AKAMA                      = 10,
    DATA_MAIEV                      = 11,
    DATA_GO_ILLIDAN_GATE            = 12,
    DATA_BLACK_TEMPLE_TRIGGER       = 13,

    DATA_GATHIOS_THE_SHATTERER      = 14,
    DATA_HIGH_NETHERMANCER_ZEREVOR  = 15,
    DATA_LADY_MALANDE               = 16,
    DATA_VERAS_DARKSHADOW           = 17,
    DATA_BLOOD_ELF_COUNCIL_VOICE    = 18,

    DATA_GO_DEN_OF_MORTAL_DOOR      = 19,

    DATA_ESSENCE_OF_SUFFERING       = 20,
    DATA_ESSENCE_OF_DESIRE          = 21,
    DATA_ESSENCE_OF_ANGER           = 22,

    DATA_ILLIDAN_MUSIC_CONTROLLER   = 23,
};

enum TriggerEmotes
{
    EMOTE_HIGH_WARLORD_NAJENTUS_DIED = 0,
    EMOTE_DEN_OF_MORTAL_DOOR_OPEN    = 1
};

enum BTCreatureIds
{
    //Bosses
    NPC_HIGH_WARLORD_NAJENTUS       = 22887,
    NPC_SUPREMUS                    = 22898,
    NPC_SHADE_OF_AKAMA              = 22841,
    NPC_TERON_GOREFIEND             = 22871,
    NPC_GURTOGG_BLOODBOIL           = 22948,
    NPC_RELIQUARY_OF_SOULS          = 22856,
    NPC_MOTHER_SHAHRAZ              = 22947,
    NPC_ILLIDARI_COUNCIL            = 23426,
    NPC_ILLIDAN_STORMRAGE           = 22917,

    //Misc
    NPC_GATHIOS_THE_SHATTERER       = 22949,
    NPC_HIGH_NETHERMANCER_ZEREVOR   = 22950,
    NPC_LADY_MALANDE                = 22951,
    NPC_VERAS_DARKSHADOW            = 22952,
    NPC_BLOOD_ELF_COUNCIL_VOICE     = 23499,
    NPC_AKAMA                       = 23089, // This is the Akama that starts the Illidan encounter.
    NPC_AKAMA_SHADE                 = 23191, // This is the Akama that starts the Shade of Akama encounter.
    NPC_SUPREMUS_VOLCANO            = 23085,
    NPC_BLACK_TEMPLE_TRIGGER        = 22984,
    NPC_RELIQUARY_WORLD_TRIGGER     = 23472,
    NPC_ENSLAVED_SOUL               = 23469,
    NPC_ASHTONGUE_STALKER           = 23374,
    NPC_ASHTONGUE_BATTLELORD        = 22844,
    NPC_ASHTONGUE_MYSTIC            = 22845,
    NPC_ASHTONGUE_PRIMALIST         = 22847,
    NPC_ASHTONGUE_STORMCALLER       = 22846,
    NPC_ASHTONGUE_FERAL_SPIRIT      = 22849,
    NPC_STORM_FURY                  = 22848,
    NPC_SPIRIT_OF_UDALO             = 23410,
    NPC_SPIRIT_OF_OLUM              = 23411,
    NPC_FLAME_OF_AZZINOTH           = 22997,
    NPC_BLADE_OF_AZZINOTH           = 22996,
    NPC_MAIEV_SHADOWSONG            = 23197,
    NPC_ILLIDAN_DB_TARGET           = 23070,
    NPC_ILLIDARI_ELITE              = 23226,
    NPC_GLAIVE_TARGET               = 23448,
    NPC_GLAIVE_WORLD_TRIGGER        = 22515,
    NPC_DEMON_FIRE                  = 23069
};

enum BTGameObjectIds
{
    GO_NAJENTUS_GATE                = 185483,
    GO_NAJENTUS_SPINE               = 185584,
    GO_SUPREMUS_GATE                = 185882,
    GO_SHADE_OF_AKAMA_DOOR          = 185478,
    GO_TERON_DOOR_1                 = 185480,
    GO_TERON_DOOR_2                 = 186153,
    GO_GURTOGG_DOOR                 = 185892,
    GO_DEN_OF_MORTAL_DOOR           = 185479,
    GO_MOTHER_SHAHRAZ_DOOR          = 185482,
    GO_COUNCIL_DOOR_1               = 185481,
    GO_COUNCIL_DOOR_2               = 186152,
    GO_ILLIDAN_GATE                 = 185905,
    GO_ILLIDAN_DOOR_R               = 186261,
    GO_ILLIDAN_DOOR_L               = 186262,
    GO_ILLIDAN_CAGE_TRAP            = 185916,
    GO_ILLIDAN_MUSIC_CONTROLLER     = 185966
};

enum BlackTempleMisc
{
    AKAMA_FACTION_COMBAT            = 1868,
    AKAMA_INTRO                     = 1,
    AKAMA_FIGHT                     = 2,
    ACTION_ACTIVE_AKAMA_INTRO       = 3,
    ACTION_OPEN_DOOR                = 4
};

template<class AI, class T>
inline AI* GetBlackTempleAI(T* obj)
{
    return GetInstanceAI<AI>(obj, BTScriptName);
}

#endif // BLACK_TEMPLE_H_
