/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "shadowfang_keep.h"
#include "TemporarySummon.h"
#include "Player.h"

ObjectData const creatureData[] =
{
    { BOSS_BARON_ASHBURY,               DATA_BARON_ASHBURY          },
    { BOSS_BARON_SILVERLAINE,           DATA_BARON_SILVERLAINE      },
    { BOSS_COMMANDER_SPRINGVALE,        DATA_COMMANDER_SPRINGVALE   },
    { BOSS_LORD_WALDEN,                 DATA_LORD_WALDEN            },
    { BOSS_LORD_GODFREY,                DATA_LORD_GODFREY           },
};

DoorData const doorData[] =
{
    { GO_ARUGAL_DOOR,                    DATA_LORD_GODFREY,              DOOR_TYPE_ROOM    },
    { 0,                                 0,                              DOOR_TYPE_ROOM    }, // END
};

BossBoundaryData const boundaries =
{
    { DATA_COMMANDER_SPRINGVALE,  new ParallelogramBoundary(Position(-222.75f, 2269.03f), Position(-217.60f, 2249.65f), Position(-267.47f, 2256.10f)) },
    { DATA_LORD_WALDEN,  new CircleBoundary(Position(-146.58f, 2173.037f), 17.0) },
};

class instance_shadowfang_keep : public InstanceMapScript
{
public:
    instance_shadowfang_keep() : InstanceMapScript(SKScriptName, 33) { }

    struct instance_shadowfang_keep_InstanceMapScript : public InstanceScript
    {
        instance_shadowfang_keep_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadDoorData(doorData);
            LoadBossBoundaries(boundaries);
            LoadObjectData(creatureData, nullptr);
            _teamInInstance = 0;
        }

        void OnPlayerEnter(Player* player) override
        {
            if (!_teamInInstance)
            {
                _teamInInstance = player->GetTeam();
                SetData(DATA_TEAM_IN_INSTANCE, _teamInInstance);
            }
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            return true;
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_TEAM_IN_INSTANCE:
                    return _teamInInstance;
                default:
                    break;
            }
            return 0;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_TEAM_IN_INSTANCE:
                    _teamInInstance = data;
                    SaveToDB();
                    break;
                default:
                    break;
            }
        }

        void WriteSaveDataMore(std::ostringstream& data) override
        {
            data << _teamInInstance;
        }

        void ReadSaveDataMore(std::istringstream& data) override
        {
            data >> _teamInInstance;

            uint32 temp = 0;
            data >> temp;

            if (temp)
                SetData(DATA_TEAM_IN_INSTANCE, temp);
        }

        protected:
            EventMap events;

            uint32 _teamInInstance;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_shadowfang_keep_InstanceMapScript(map);
    }
};

void AddSC_instance_shadowfang_keep()
{
    new instance_shadowfang_keep();
}
