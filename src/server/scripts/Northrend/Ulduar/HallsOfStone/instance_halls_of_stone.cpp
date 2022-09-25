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

#include "ScriptMgr.h"
#include "Creature.h"
#include "GameObject.h"
#include "halls_of_stone.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"

DoorData const doorData[] =
{
    { GO_SJONNIR_DOOR, DATA_TRIBUNAL_OF_AGES, DOOR_TYPE_PASSAGE },
    { 0,               0,                     DOOR_TYPE_ROOM    } // END
};

ObjectData const creatureData[] =
{
    { NPC_KRYSTALLUS,               DATA_KRYSTALLUS             },
    { NPC_MAIDEN_OF_GRIEF,          DATA_MAIDEN_OF_GRIEF        },
    { NPC_SJONNIR_THE_IRONSHAPER,   DATA_SJONNIR_THE_IRONSHAPER },
    { NPC_KADDRAK,                  DATA_KADDRAK                },
    { NPC_MARNAK,                   DATA_MARNAK                 },
    { NPC_ABEDNEUM,                 DATA_ABEDNEUM               },
    { 0,                            0                           } // END
};

ObjectData const gameObjectData[] =
{
    { GO_KADDRAK,               DATA_GO_KADDRAK             },
    { GO_MARNAK,                DATA_GO_MARNAK              },
    { GO_ABEDNEUM,              DATA_GO_ABEDNEUM            },
    { GO_TRIBUNAL_CONSOLE,      DATA_GO_TRIBUNAL_CONSOLE    },
    { GO_TRIBUNAL_SKY_FLOOR,    DATA_GO_SKY_FLOOR           },
    { GO_TRIBUNAL_CHEST,        DATA_GO_TRIBUNAL_CHEST      },
    { GO_TRIBUNAL_CHEST_HERO,   DATA_GO_TRIBUNAL_CHEST      },
    { 0,                        0                           } // END
};

class instance_halls_of_stone : public InstanceMapScript
{
    public:
        instance_halls_of_stone() : InstanceMapScript(HoSScriptName, 599) { }

        struct instance_halls_of_stone_InstanceMapScript : public InstanceScript
        {
            instance_halls_of_stone_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameObjectData);
                LoadDoorData(doorData);
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                switch (go->GetEntry())
                {
                    case GO_TRIBUNAL_CHEST:
                    case GO_TRIBUNAL_CHEST_HERO:
                        if (GetBossState(DATA_TRIBUNAL_OF_AGES) == DONE)
                            go->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_TRIBUNAL_OF_AGES:
                        if (state == DONE)
                            if (GameObject* go = GetGameObject(DATA_GO_TRIBUNAL_CHEST))
                                go->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                        break;
                    default:
                        break;
                }

                return true;
            }

            bool CheckRequiredBosses(uint32 bossId, Player const* player = nullptr) const override
            {
                if (_SkipCheckRequiredBosses(player))
                    return true;

                switch (bossId)
                {
                    case DATA_SJONNIR_THE_IRONSHAPER:
                        if (GetBossState(DATA_TRIBUNAL_OF_AGES) != DONE)
                            return false;
                        break;
                    default:
                        break;
                }

                return true;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_halls_of_stone_InstanceMapScript(map);
        }
};

void AddSC_instance_halls_of_stone()
{
    new instance_halls_of_stone();
}
