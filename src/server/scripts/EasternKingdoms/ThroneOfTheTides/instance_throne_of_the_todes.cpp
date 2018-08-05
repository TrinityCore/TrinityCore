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
#include "throne_of_the_tides.h"
#include "InstanceScript.h"
#include "Vehicle.h"

ObjectData const creatureData[] =
{
    { BOSS_LADY_NAZJAR,         DATA_LADY_NAZJAR        },
    { BOSS_COMMANDER_ULTHOK,    DATA_COMMANDER_ULTHOK   },
    { BOSS_MINDBENDER_GURSHA,   DATA_MINDBENDER_GURSHA  },
    { BOSS_OZUMAT,              DATA_OZUMAT             },
    { 0,                        0                       } // END
};

class instance_throne_of_the_tides : public InstanceMapScript
{
    public:
        instance_throne_of_the_tides(): InstanceMapScript(TotTScriptName, 643) {  }

        struct instance_throne_of_the_tides_InstanceMapScript : public InstanceScript
        {
            instance_throne_of_the_tides_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                Initialize();
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, nullptr);
            }

            void Initialize()
            {
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                return true;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case BOSS_OZUMAT:
                    case NPC_OZUMAT_VEHICLE:
                    case NPC_OZUMAT_VEHICLE_BIG:
                        creature->setActive(true);
                        creature->SetFarVisible(true);
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                return 0;
            }

            void SetData(uint32 type, uint32 data) override
            {
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
            }

        private:
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_throne_of_the_tides_InstanceMapScript(map);
        }
};

void AddSC_instance_throne_of_the_tides()
{
    new instance_throne_of_the_tides();
}
