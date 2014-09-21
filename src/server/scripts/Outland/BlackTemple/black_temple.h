/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#define BTScriptName "instance_black_temple"
#define DataHeader   "BT"

uint32 const EncounterCount         = 9;

enum DataTypes
{
    // Encounter States/Boss GUIDs
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

    DATA_GATHIOS_THE_SHATTERER      = 11,
    DATA_HIGH_NETHERMANCER_ZEREVOR  = 12,
    DATA_LADY_MALANDE               = 13,
    DATA_VERAS_DARKSHADOW           = 14,
    DATA_BLOOD_ELF_COUNCIL_VOICE    = 15,

    DATA_GO_ILLIDAN_GATE            = 16,
    DATA_GO_ILLIDAN_DOOR_R          = 17,
    DATA_GO_ILLIDAN_DOOR_L          = 18
};

enum CreatureIds
{
    NPC_HIGH_WARLORD_NAJENTUS       = 22887,
    NPC_SUPREMUS                    = 22898,
    NPC_SHADE_OF_AKAMA              = 22841,
    NPC_AKAMA_SHADE                 = 23191, // This is the Akama that starts the Shade of Akama encounter.
    NPC_AKAMA                       = 23089, // This is the Akama that starts the Illidan encounter.

    NPC_GATHIOS_THE_SHATTERER       = 22949,
    NPC_HIGH_NETHERMANCER_ZEREVOR   = 22950,
    NPC_LADY_MALANDE                = 22951,
    NPC_VERAS_DARKSHADOW            = 22952,
    NPC_ILLIDARI_COUNCIL            = 23426,
    NPC_BLOOD_ELF_COUNCIL_VOICE     = 23499,

    NPC_ILLIDAN_STORMRAGE           = 22917,

    NPC_SUPREMUS_VOLCANO            = 23085
};

enum GameObjectIds
{
    GO_NAJENTUS_GATE                = 185483,
    GO_NAJENTUS_SPINE               = 185584,
    GO_SUPREMUS_GATE                = 185882,
    GO_SHADE_OF_AKAMA_DOOR          = 185478,
    GO_TERON_DOOR_1                 = 185480,
    GO_TERON_DOOR_2                 = 186153,
    GO_GURTOGG_DOOR                 = 185892,
    GO_TEMPLE_DOOR                  = 185479,
    GO_MOTHER_SHAHRAZ_DOOR          = 185482,
    GO_COUNCIL_DOOR_1               = 185481,
    GO_COUNCIL_DOOR_2               = 186152,
    GO_ILLIDAN_GATE                 = 185905,
    GO_ILLIDAN_DOOR_R               = 186261,
    GO_ILLIDAN_DOOR_L               = 186262
};

template<class AI>
AI* GetBlackTempleAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, BTScriptName);
}

#endif // BLACK_TEMPLE_H_
