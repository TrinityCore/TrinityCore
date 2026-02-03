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
#include "eye_of_azshara.h"

BossBoundaryData const boundaries =
{
    { DATA_KING_DEEPBEARD, new CircleBoundary(Position(-3448.65f, 4161.68f, 29.18f), 68.0f) }
};

ObjectData const creatureData[] =
{
    { BOSS_WARLORD_PARJESH,  DATA_WARLORD_PARJESH  },
    { BOSS_LADY_HATECOIL,    DATA_LADY_HATECOIL    },
    { BOSS_KING_DEEPBEARD,   DATA_KING_DEEPBEARD   },
    { BOSS_SERPENTRIX,       DATA_SERPENTRIX       },
    { BOSS_WRATH_OF_AZSHARA, DATA_WRATH_OF_AZSHARA },
    { 0,                     0                     }  // END
};

DoorData const doorData[] =
{
    { GO_WATER_DOOR_1, DATA_KING_DEEPBEARD, EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_WATER_DOOR_2, DATA_KING_DEEPBEARD, EncounterDoorBehavior::OpenWhenNotInProgress },
    { 0,               0,                   EncounterDoorBehavior::OpenWhenNotInProgress }  // END
};

DungeonEncounterData const encounters[] =
{
    { DATA_WARLORD_PARJESH,  {{ 1810 }} },
    { DATA_LADY_HATECOIL,    {{ 1811 }} },
    { DATA_KING_DEEPBEARD,   {{ 1812 }} },
    { DATA_SERPENTRIX,       {{ 1813 }} },
    { DATA_WRATH_OF_AZSHARA, {{ 1814 }} }
};

class instance_eye_of_azshara : public InstanceMapScript
{
public:
    instance_eye_of_azshara() : InstanceMapScript(EOAScriptName, 1456) { }

    struct AddSC_instance_eye_of_azshara_InstanceMapScript : public InstanceScript
    {
        AddSC_instance_eye_of_azshara_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            LoadDoorData(doorData);
            LoadDungeonEncounterData(encounters);
            LoadBossBoundaries(boundaries);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new AddSC_instance_eye_of_azshara_InstanceMapScript(map);
    }
};

void AddSC_instance_eye_of_azshara()
{
    new instance_eye_of_azshara();
}
