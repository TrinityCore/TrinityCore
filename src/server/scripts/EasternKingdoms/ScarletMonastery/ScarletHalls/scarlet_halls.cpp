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

#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "scarlet_halls.h"

ObjectData const creatureData[] =
{
    { BOSS_HOUNDMASTER_BRAUN,   DATA_HOUNDMASTER_BRAUN      },
    { BOSS_ARMSMASTER_HARLAN,   DATA_ARMSMASTER_HARLAN      },
    { BOSS_FLAMEWEAVER_KOEGLER, DATA_FLAMEWEAVER_KOEGLER    },
    { 0,                        0                           } // END
};

DoorData const doorData[] =
{
    { GO_HERODS_DOOR_HARLAN_ENCOUNTER_ENTRANCE, DATA_ARMSMASTER_HARLAN, EncounterDoorBehavior::OpenWhenNotInProgress },
    { 0,                                        0,                      EncounterDoorBehavior::OpenWhenNotInProgress } //End
};

DungeonEncounterData const encounters[] =
{
    { DATA_HOUNDMASTER_BRAUN,   {{ 1422 }} },
    { DATA_ARMSMASTER_HARLAN,   {{ 1421 }} },
    { DATA_FLAMEWEAVER_KOEGLER, {{ 1420 }} },
};

class instance_scarlet_halls : public InstanceMapScript
{
public:
    instance_scarlet_halls() : InstanceMapScript(ScarletHallsScriptName, 1001) { }

    struct instance_scarlet_halls_InstanceMapScript : public InstanceScript
    {
        instance_scarlet_halls_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
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
        return new instance_scarlet_halls_InstanceMapScript(map);
    }
};

void AddSC_instance_scarlet_halls()
{
    new instance_scarlet_halls();
}
