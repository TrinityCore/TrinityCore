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

#include "Creature.h"
#include "CreatureAI.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "darkmaul_citadel.h"

ObjectData const creatureData[] =
{
    { BOSS_TUNK,     DATA_TUNK     },
    { BOSS_GORGROTH, DATA_GORGROTH },
    { BOSS_RAVNYR,   DATA_RAVNYR   },
    { 0,             0             }  // END
};

static DoorData const doorData[] =
{
    { GO_TEMP_DOOR, DATA_TUNK, EncounterDoorBehavior::OpenWhenDone },
    { 0,            0,         EncounterDoorBehavior::OpenWhenNotInProgress }
};

DungeonEncounterData const encounters[] =
{
    { DATA_TUNK,   {{ 2325 }} },
    { DATA_RAVNYR, {{ 2326 }} }
};

class instance_darkmaul_citadel : public InstanceMapScript
{
public:
    instance_darkmaul_citadel() : InstanceMapScript(DCScriptName, 2236) { }

    struct instance_darkmaul_citadel_InstanceMapScript: public InstanceScript
    {
        instance_darkmaul_citadel_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
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
        return new instance_darkmaul_citadel_InstanceMapScript(map);
    }
};

void AddSC_instance_darkmaul_citadel()
{
    new instance_darkmaul_citadel();
}
