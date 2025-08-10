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
#include "neltharions_lair.h"

BossBoundaryData const boundaries =
{
    { DATA_ROKMORA, new RectangleBoundary(2855.4377f, 2953.1074f, 1360.5552f, 1438.9974f) }
};

ObjectData const creatureData[] =
{
    { BOSS_ROKMORA,               DATA_ROKMORA               },
    { BOSS_ULAROGG_CRAGSHAPER,    DATA_ULAROGG_CRAGSHAPER    },
    { BOSS_NARAXAS,               DATA_NARAXAS               },
    { BOSS_DARGRUL_THE_UNDERKING, DATA_DARGRUL_THE_UNDERKING },
    { 0,                          0                          }  // END
};

DungeonEncounterData const encounters[] =
{
    { DATA_ROKMORA,               {{ 1790 }} },
    { DATA_ULAROGG_CRAGSHAPER,    {{ 1791 }} },
    { DATA_NARAXAS,               {{ 1792 }} },
    { DATA_DARGRUL_THE_UNDERKING, {{ 1793 }} },
};

static DoorData const doorData[] =
{
    { GO_MYSTIC_BARRIER, DATA_ROKMORA, EncounterDoorBehavior::OpenWhenDone },
    { 0,                 0,            EncounterDoorBehavior::OpenWhenNotInProgress }
};

class instance_neltharions_lair : public InstanceMapScript
{
    public:
        instance_neltharions_lair() : InstanceMapScript(NLScriptName, 1458) { }

        struct instance_neltharions_lair_InstanceMapScript: public InstanceScript
        {
            instance_neltharions_lair_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, nullptr);
                LoadDoorData(doorData);
                LoadBossBoundaries(boundaries);
                LoadDungeonEncounterData(encounters);

                _rokmoraIntroState = NOT_STARTED;
            }

            uint32 GetData(uint32 dataId) const override
            {
                switch (dataId)
                {
                    case DATA_ROKMORA_INTRO_STATE:
                        return _rokmoraIntroState;
                    default:
                        break;
                }
                return 0;
            }

            void SetData(uint32 dataId, uint32 value) override
            {
                switch (dataId)
                {
                    case DATA_ROKMORA_INTRO_STATE:
                        _rokmoraIntroState = value;
                        break;
                    default:
                        break;
                }
            }

        private:
            uint8 _rokmoraIntroState;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_neltharions_lair_InstanceMapScript(map);
        }
};

void AddSC_instance_neltharions_lair()
{
    new instance_neltharions_lair();
}
