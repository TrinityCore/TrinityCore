/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "Containers.h"
#include "CreatureAI.h"
#include "EventMap.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "throne_of_the_four_winds.h"
#include "Map.h"
#include "TemporarySummon.h"
#include "Weather.h"

ObjectData const creatureData[] =
{
    { BOSS_ANSHAL,  DATA_ANSHAL },
    { BOSS_NEZIR,   DATA_NEZIR  },
    { BOSS_ROHASH,  DATA_ROHASH },
    { BOSS_ALAKIR,  DATA_ALAKIR },
    { 0,            0           } // End
};

ObjectData const gameObjectData[] =
{
    { GO_SKYWALL_RAID_CENTER_PLATFORM,  DATA_SKYWALL_RAID_CENTER_PLATFORM   },
    { 0,                                0                                   } // End
};

class instance_throne_of_the_four_winds : public InstanceMapScript
{
    public:
        instance_throne_of_the_four_winds() : InstanceMapScript(TFWScriptName, 754) { }

        struct instance_throne_of_the_four_winds_InstanceMapScript : public InstanceScript
        {
            instance_throne_of_the_four_winds_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameObjectData);
                Initialize();
            }

            void Initialize()
            {
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                creature->setActive(true);
                creature->SetFarVisible(true);
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                go->setActive(true);
                go->SetFarVisible(true);
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                return true;
            }

            void SetData(uint32 data, uint32 value) override
            {
            }


            void Update(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case 0:
                            break;
                        default:
                            break;
                    }
                }
            }

            void ReadSaveDataMore(std::istringstream& /*data*/) override
            {
            }

        protected:
            EventMap events;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_throne_of_the_four_winds_InstanceMapScript(map);
        }
};

void AddSC_instance_throne_of_the_four_winds()
{
    new instance_throne_of_the_four_winds();
}
