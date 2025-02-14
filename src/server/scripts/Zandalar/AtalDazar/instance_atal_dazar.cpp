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

#include "AreaBoundary.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "atal_dazar.h"

BossBoundaryData const boundaries =
{
    { DATA_REZAN, new ZRangeBoundary(639.0f, 650.0f) }, // 647.65f
    { DATA_VOLKAAL, new ZRangeBoundary(709.0f, 730.0f) },
    { DATA_PRIESTESS_ALUNZA, new PolygonBoundary({ 0.0f, 0.0f, 0.0f },
        {
            { -1025.9933f, 2361.0408f },
            { -1025.3562f, 2335.1824f },
            { -1039.7438f, 2334.5159f },
            { -1039.3069f, 2301.5972f },
            { -1056.4854f, 2301.4658f },
            { -1056.2940f, 2283.9922f },
            { -1039.5042f, 2283.8018f },
            { -1038.6632f, 2250.5894f },
            { -1026.9938f, 2250.8943f },
            { -1027.5638f, 2221.2890f },
            { -1066.7467f, 2220.9265f },
            { -1068.1931f, 2224.4500f },
            { -1075.2456f, 2224.4426f },
            { -1075.1584f, 2203.5364f },
            { -1120.4791f, 2201.6090f },
            { -1169.1852f, 2292.5390f }, // in mountain
            { -1119.9462f, 2379.7322f },
            { -1087.9506f, 2381.5403f },
            { -1076.0125f, 2379.9875f },
            { -1074.5750f, 2359.8690f },
            { -1067.1986f, 2364.1672f },
        }
    )},
};

constexpr ObjectData creatureData[] =
{
    { BOSS_PRIESTESS_ALUNZA, DATA_PRIESTESS_ALUNZA  },
    { BOSS_VOLKAAL,          DATA_VOLKAAL           },
    { BOSS_REZAN,            DATA_REZAN             },
    { BOSS_YAZMA,            DATA_YAZMA             },
    { 0,                     0                      }  // END
};

constexpr DoorData doorData[] =
{
    { GO_VOLKAAL_DOOR_1, DATA_VOLKAAL, EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_VOLKAAL_DOOR_2, DATA_VOLKAAL, EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_VOLKAAL_DOOR_3, DATA_VOLKAAL, EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_VOLKAAL_DOOR_4, DATA_VOLKAAL, EncounterDoorBehavior::OpenWhenNotInProgress },
    { 0,                 0,            EncounterDoorBehavior::OpenWhenNotInProgress }  // END
};

constexpr DungeonEncounterData encounters[] =
{
    { DATA_PRIESTESS_ALUNZA, {{ 2084 }} },
    { DATA_VOLKAAL,          {{ 2085 }} },
    { DATA_REZAN,            {{ 2086 }} },
    { DATA_YAZMA,            {{ 2087 }} }
};

class instance_atal_dazar : public InstanceMapScript
{
public:
    instance_atal_dazar() : InstanceMapScript(AtalDazarScriptName, 1763) { }

    struct instance_atal_dazar_InstanceMapScript : public InstanceScript
    {
        instance_atal_dazar_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            LoadDoorData(doorData);
            LoadBossBoundaries(boundaries);
            LoadDungeonEncounterData(encounters);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_atal_dazar_InstanceMapScript(map);
    }
};

void AddSC_instance_atal_dazar()
{
    new instance_atal_dazar();
}
