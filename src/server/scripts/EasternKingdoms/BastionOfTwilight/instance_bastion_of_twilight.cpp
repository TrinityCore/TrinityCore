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
#include "CreatureAI.h"
#include "bastion_of_twilight.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "TemporarySummon.h"
#include "VehicleDefines.h"
#include "WorldPacket.h"

ObjectData const creatureData[] =
{
    { BOSS_HALFUS_WYRMBREAKER,          DATA_HALFUS_WYRMBREAKER     },
    { BOSS_PROTO_BEHEMOTH,              DATA_PROTO_BEHEMOTH         },
    { BOSS_THERALION,                   DATA_THERALION              },
    { BOSS_VALIONA,                     DATA_VALIONA                },
    { BOSS_IGNACIOUS,                   DATA_IGNACIOUS              },
    { BOSS_FELUDIUS,                    DATA_FELUDIUS               },
    { BOSS_TERRASTRA,                   DATA_TERRASTRA              },
    { BOSS_ARION,                       DATA_ARION                  },
    { BOSS_ELEMENTIUM_MONSTROSITY,      DATA_ELEMENTIUM_MONSTROSITY },
    { BOSS_CHOGALL,                     DATA_CHOGALL                },
    { BOSS_SINESTRA,                    DATA_SINESTRA               },
    { 0,                                0                           } // END
};

ObjectData const gameobjectData[] =
{
    //{ GO_IRON_CLAD_DOOR,                DATA_IRON_CLAD_DOOR     },
    { 0,                                0                       } // END
};

DoorData const doorData[] =
{
    { GO_HALFUS_ENTRANCE,                   DATA_HALFUS_WYRMBREAKER,        DOOR_TYPE_ROOM      },
    { GO_HALFUS_EXIT,                       DATA_HALFUS_WYRMBREAKER,        DOOR_TYPE_PASSAGE   },
    { GO_DRAGON_SIBLINGS_DOOR_ENTRANCE,     DATA_THERALION_AND_VALIONA,     DOOR_TYPE_ROOM      },
    { GO_DRAGON_SIBLINGS_DOOR_EXIT,         DATA_THERALION_AND_VALIONA,     DOOR_TYPE_PASSAGE   },
    { GO_ASCENDANT_COUNCIL_ENTRANCE,        DATA_ASCENDANT_COUNCIL,         DOOR_TYPE_ROOM      },
    { GO_ASCENDANT_COUNCIL_EXIT,            DATA_ASCENDANT_COUNCIL,         DOOR_TYPE_PASSAGE   },
    { GO_CHOGALL_ENTRANCE,                  DATA_CHOGALL,                   DOOR_TYPE_ROOM      },
    { 0,                                    0,                              DOOR_TYPE_ROOM      } // END
};

class instance_bastion_of_twilight : public InstanceMapScript
{
    public:
        instance_bastion_of_twilight() : InstanceMapScript(BoTScriptName, 671) { }

        struct instance_bastion_of_twilight_InstanceMapScript : public InstanceScript
        {
            instance_bastion_of_twilight_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(!map->IsHeroic() ? EncounterCountNormal : EncounterCountHeroic); // Sinestra only in heroic mode
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameobjectData);

                if (!map->IsHeroic())
                    GenerateUnresponsiveDragonData();
            }

            void GenerateUnresponsiveDragonData()
            {
            }

            /*
            void OnPlayerEnter(Player* player) override
            {
            }
            */

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case 0:
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case 0:
                        break;
                    default:
                        break;
                }
                return true;
            }

            void OnUnitDeath(Unit* unit) override
            {
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case 0:
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                return 0;
            }

            /*
            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << _teamInInstance << ' '
                    << _foeReaper5000Intro << ' '
                    << _ironCladDoorState;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> _teamInInstance;
                data >> _foeReaper5000Intro;
                data >> _ironCladDoorState;
            }
            */

            void Update(uint32 diff) override
            {
            }

        protected:
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_bastion_of_twilight_InstanceMapScript(map);
        }
};

void AddSC_instance_bastion_of_twilight()
{
    new instance_bastion_of_twilight();
}