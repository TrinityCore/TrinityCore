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

#include "thenighthold.h"
#include "GameObject.h"

DoorData const doorData[] =
{
    {GO_SCORPYRON_DOOR_1,           DATA_SKORPYRON,         DOOR_TYPE_ROOM},
    {GO_SCORPYRON_DOOR_2,           DATA_SKORPYRON,         DOOR_TYPE_PASSAGE},
    {GO_ANOMALY_DOOR_1,             DATA_ANOMALY,           DOOR_TYPE_ROOM},
    {GO_ANOMALY_DOOR_2,             DATA_ANOMALY,           DOOR_TYPE_PASSAGE},
    {GO_TRILLIAX_DOOR_1,            DATA_TRILLIAX,          DOOR_TYPE_PASSAGE},
    {GO_TRILLIAX_DOOR_2,            DATA_TRILLIAX,          DOOR_TYPE_ROOM},
    {GO_STAR_AUGUR_ETRAEUS_DOOR,    DATA_ETRAEUS,           DOOR_TYPE_ROOM},
    {GO_BOTANIST_LEFT_DOOR,         DATA_TELARN,            DOOR_TYPE_ROOM},
    {GO_BOTANIST_RIGHT_DOOR,        DATA_TELARN,            DOOR_TYPE_ROOM},
    {GO_ALURIEL_DOOR_PORTAL,        DATA_ALURIEL,           DOOR_TYPE_PASSAGE},
    {GO_TICHONDRIUS_DOOR_1,         DATA_TICHONDRIUS,       DOOR_TYPE_ROOM},
    {GO_TICHONDRIUS_DOOR_2,         DATA_TICHONDRIUS,       DOOR_TYPE_ROOM},
    {GO_TICHONDRIUS_DOOR_3,         DATA_TICHONDRIUS,       DOOR_TYPE_ROOM},
    {GO_TICHONDRIUS_DOOR_4,         DATA_TICHONDRIUS,       DOOR_TYPE_ROOM},
    {GO_TICHONDRIUS_DOOR_5,         DATA_TICHONDRIUS,       DOOR_TYPE_ROOM},
    {GO_ELISANDE_DOOR_1,            DATA_ELISANDE,          DOOR_TYPE_ROOM},
    {GO_ELISANDE_DOOR_2,            DATA_ELISANDE,          DOOR_TYPE_ROOM},
    {GO_ELISANDE_DOOR_3,            DATA_ELISANDE,          DOOR_TYPE_ROOM},
    {0,                             0,                      DOOR_TYPE_ROOM} // END
};

ObjectData const creatureData[] =
{
    { NPC_SKORPYRON,            DATA_SKORPYRON },
    { NPC_CHRONOMATIC_ANOMALY,  DATA_ANOMALY },
    { NPC_TRILLIAX,             DATA_TRILLIAX },

    { NPC_SPELLBLADE_ALURIEL,   DATA_ALURIEL },
    { NPC_STAR_AUGUR_ETRAEUS,   DATA_ETRAEUS },
    { NPC_TELARN,               DATA_TELARN },

    { NPC_KROSUS,               DATA_KROSUS },
    { NPC_IMGAGE_OF_KADGNAR,    DATA_IMAGE_OF_KADGHAR },
    { NPC_CHAOS_MAGE_BELORN,    DATA_CHAOS_MAGE_BELORN },
    { NPC_SUMMONER_XIV,         DATA_SUMMONER_XIV },
    { NPC_FELWEAVER_PHARAMERE,  DATA_FELWEAVER_PHARAMERE },

    { NPC_TICHONDRIUS,          DATA_TICHONDRIUS },

    { NPC_ELISANDE,             DATA_ELISANDE },
    { NPC_GULDAN,               DATA_GULDAN },
    { NPC_CRYSTALL_OF_ILLIDAN,  NPC_CRYSTALL_OF_ILLIDAN },
    { 0,                        0 } // END
};

ObjectData const objectData[] =
{
    { GO_ANOMALY_PRE,       GO_ANOMALY_PRE          },
    { GO_KROSUS_PLATFORM1,  DATA_KROSUS_PLATFORM1   },
    { GO_KROSUS_PLATFORM2,  DATA_KROSUS_PLATFORM2   },
    { GO_KROSUS_PLATFORM3,  DATA_KROSUS_PLATFORM3   },
    { GO_KROSUS_PLATFORM4,  DATA_KROSUS_PLATFORM4   },
    { GO_EYE_OF_AMANTUL,    GO_EYE_OF_AMANTUL       },
    { GO_STATUE_1,          GO_STATUE_1             },
    { GO_STATUE_2,          GO_STATUE_2             },
    { GO_STATUE_3,          GO_STATUE_3             },
    { GO_STATUE_4,          GO_STATUE_4             },
    { GO_ROOM,              GO_ROOM             },
    { 0,                    0,                      }
};

void AddSC_instance_the_nighthold()
{
    
}
