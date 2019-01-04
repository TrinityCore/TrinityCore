/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "Creature.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "blackwing_descent.h"

ObjectData const creatureData[] =
{
    { BOSS_MAGMAW,      DATA_MAGMAW                 },
    { 0,                0                           }// END
};

ObjectData const gameobjectData[] =
{
    { 0,        0                          }  // END
};

DoorData const doorData[] =
{
    { 0,        0,          DOOR_TYPE_ROOM }  // END
};

class instance_blackwing_descent : public InstanceMapScript
{
    public:
        instance_blackwing_descent() : InstanceMapScript(BWDScriptName, 669) { }

        struct instance_blackwing_descent_InstanceMapScript : public InstanceScript
        {
            instance_blackwing_descent_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameobjectData);
                LoadDoorData(doorData);
                Initialize();
            }

            void Initialize()
            {
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                /*
                switch (creature->GetEntry())
                {
                    default:
                        break;
                }
                */
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                return true;
            }

            /*
            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    default:
                        break;
                }
            }
            */

            /*
            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                }

                return 0;
            }
            */

            /*
            void WriteSaveDataMore(std::ostringstream& data) override
            {
            }
            */

            /*
            void ReadSaveDataMore(std::istringstream& data) override
            {
            }
            */
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_blackwing_descent_InstanceMapScript(map);
        }
};

void AddSC_instance_blackwing_descent()
{
    new instance_blackwing_descent();
}
