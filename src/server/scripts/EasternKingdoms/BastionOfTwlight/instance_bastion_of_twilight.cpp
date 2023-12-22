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

#include "ScriptMgr.h"
#include "bastion_of_twilight.h"
#include "InstanceScript.h"

ObjectData const creatureData[] =
{
    { NPC_HALFUS_WYRMBREAKER,   BOSS_HALFUS_WYRMBREAKER },
    { NPC_CHOGALL,              BOSS_CHOGALL            },
    { NPC_SINESTRA,             BOSS_SINESTRA           },
    { 0,                        0                       } // END
};

DoorData const doorData[] =
{
    { GO_HALFUS_ENTRANCE,               BOSS_HALFUS_WYRMBREAKER,        EncounterDoorBehavior::OpenWhenNotInProgress    },
    { GO_HALFUS_EXIT,                   BOSS_HALFUS_WYRMBREAKER,        EncounterDoorBehavior::OpenWhenDone             },
    { GO_DRAGON_SIBLINGS_DOOR_ENTRANCE, BOSS_THERALION_AND_VALIONA,     EncounterDoorBehavior::OpenWhenNotInProgress    },
    { GO_DRAGON_SIBLINGS_DOOR_EXIT,     BOSS_THERALION_AND_VALIONA,     EncounterDoorBehavior::OpenWhenDone             },
    { GO_ASCENDANT_COUNCIL_ENTRANCE,    BOSS_ASCENDANT_COUNCIL,         EncounterDoorBehavior::OpenWhenNotInProgress    },
    { GO_ASCENDANT_COUNCIL_EXIT,        BOSS_ASCENDANT_COUNCIL,         EncounterDoorBehavior::OpenWhenDone             },
    { GO_CHOGALL_ENTRANCE,              BOSS_CHOGALL,                   EncounterDoorBehavior::OpenWhenNotInProgress    },
    { 0,                                0,                              EncounterDoorBehavior::OpenWhenNotInProgress    }  // END
};

DungeonEncounterData const encounters[] =
{
    { BOSS_HALFUS_WYRMBREAKER,      {{ 1030 }}          },
    { BOSS_THERALION_AND_VALIONA,   {{ 1032 }}          },
    { BOSS_ASCENDANT_COUNCIL,       {{ 1028 }}          },
    { BOSS_CHOGALL,                 {{ 1029 }}          },
    { BOSS_SINESTRA,                {{ 1082, 1083 }}    }
};

class instance_bastion_of_twilight : public InstanceMapScript
{
public:
    instance_bastion_of_twilight() : InstanceMapScript(BotScriptName, 671) { }

    struct instance_bastion_of_twilight_InstanceMapScript : public InstanceScript
    {
        instance_bastion_of_twilight_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            LoadDoorData(doorData);
            LoadDungeonEncounterData(encounters);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_bastion_of_twilight_InstanceMapScript(map);
    }
};

void AddSC_instance_bastion_of_twilight()
{
    new instance_bastion_of_twilight();
}
