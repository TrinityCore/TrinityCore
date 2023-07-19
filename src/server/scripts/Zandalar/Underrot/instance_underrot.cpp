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
#include "underrot.h"

BossBoundaryData const boundaries =
{
    { DATA_ELDER_LEAXA,          new CircleBoundary(Position(869.502014f, 1230.199951f), 58.0f) },
    { DATA_CRAGMAW_THE_INFESTED, new CircleBoundary(Position(852.797974f, 982.133545f), 90.0f) }
};

ObjectData const creatureData[] =
{
    { BOSS_ELDER_LEAXA,             DATA_ELDER_LEAXA            },
    { BOSS_SPORECALLER_ZANCHA,      DATA_SPORECALLER_ZANCHA     },
    { BOSS_CRAGMAW_THE_INFESTED,    DATA_CRAGMAW_THE_INFESTED   },
    { BOSS_UNBOUND_ABOMINATION,     DATA_UNBOUND_ABOMINATION    },
    { 0,                            0                           }  // END
};

DoorData const doorData[] =
{
    { GO_WALL_DOOR_SHORTCUT_ENTRANCE,        DATA_SPORECALLER_ZANCHA,  DOOR_TYPE_PASSAGE },
    { 0,                                     0,                        DOOR_TYPE_ROOM    }  // END
};

DungeonEncounterData const encounters[] =
{
    { DATA_ELDER_LEAXA,             {{ 2111 }} },
    { DATA_CRAGMAW_THE_INFESTED,    {{ 2112 }} },
    { DATA_SPORECALLER_ZANCHA,      {{ 2118 }} },
    { DATA_UNBOUND_ABOMINATION,     {{ 2123 }} },
};

class instance_underrot : public InstanceMapScript
{
public:
    instance_underrot() : InstanceMapScript(UnderrotScriptName, 1841) { }

    struct instance_underrot_InstanceMapScript : public InstanceScript
    {
        instance_underrot_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            LoadDoorData(doorData);
            LoadBossBoundaries(boundaries);
            LoadDungeonEncounterData(encounters);

            _cragmawCrawgEating = false;
        }

        uint32 GetData(uint32 dataId) const override
        {
            switch (dataId)
            {
                case DATA_CRAGMAW_CRAWG_EATING:
                    return _cragmawCrawgEating ? 1 : 0;
                default:
                    break;
            }
            return 0;
        }

        void SetData(uint32 dataId, uint32 /*value*/) override
        {
            switch (dataId)
            {
                case DATA_CRAGMAW_CRAWG_EATING:
                    _cragmawCrawgEating = true;
                    break;
                default:
                    break;
            }
        }

    private:
        bool _cragmawCrawgEating;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_underrot_InstanceMapScript(map);
    }
};

void AddSC_instance_underrot()
{
    new instance_underrot();
}
