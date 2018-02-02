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
#include "AreaBoundary.h"
#include "ahnkahet.h"
#include "Creature.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"

DoorData const doorData[] =
{
    { GO_PRINCE_TALDARAM_GATE, DATA_PRINCE_TALDARAM, DOOR_TYPE_PASSAGE },
    { 0,                       0,                    DOOR_TYPE_ROOM } // END
};

ObjectData const creatureData[] =
{
    { NPC_ELDER_NADOX,         DATA_ELDER_NADOX         },
    { NPC_PRINCE_TALDARAM,     DATA_PRINCE_TALDARAM     },
    { NPC_JEDOGA_SHADOWSEEKER, DATA_JEDOGA_SHADOWSEEKER },
    { NPC_AMANITAR,            DATA_AMANITAR            },
    { NPC_HERALD_VOLAZJ,       DATA_HERALD_VOLAZJ       },
    { 0,                       0                        }
};

ObjectData const gameObjectData[] =
{
    { GO_PRINCE_TALDARAM_PLATFORM, DATA_PRINCE_TALDARAM_PLATFORM },
    { 0,                           0                             } //END
};

BossBoundaryData const boundaries =
{
    { DATA_JEDOGA_SHADOWSEEKER, new ParallelogramBoundary(Position(460.365f, -661.997f, -20.985f), Position(364.958f,-790.211f, -14.207f), Position(347.436f,-657.978f,14.478f)) }
};

class instance_ahnkahet : public InstanceMapScript
{
    public:
        instance_ahnkahet() : InstanceMapScript(AhnKahetScriptName, 619) { }

        struct instance_ahnkahet_InstanceScript : public InstanceScript
        {
            instance_ahnkahet_InstanceScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameObjectData);
                LoadBossBoundaries(boundaries);

                SpheresState[0]             = 0;
                SpheresState[1]             = 0;
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                switch (go->GetEntry())
                {
                    case GO_PRINCE_TALDARAM_PLATFORM:
                        if (GetBossState(DATA_PRINCE_TALDARAM) == DONE)
                            HandleGameObject(ObjectGuid::Empty, true, go);
                        break;
                    case GO_SPHERE_1:
                        if (SpheresState[0])
                        {
                            go->SetGoState(GO_STATE_ACTIVE);
                            go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                        else
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    case GO_SPHERE_2:
                        if (SpheresState[1])
                        {
                            go->SetGoState(GO_STATE_ACTIVE);
                            go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                        else
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    default:
                        break;
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_SPHERE_1:
                    case DATA_SPHERE_2:
                        SpheresState[type - DATA_SPHERE_1] = data;
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_SPHERE_1:
                    case DATA_SPHERE_2:
                        return SpheresState[type - DATA_SPHERE_1];
                    default:
                        break;
                }
                return 0;
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << SpheresState[0] << ' ' << SpheresState[1];
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> SpheresState[0];
                data >> SpheresState[1];
            }

        protected:
            uint32 SpheresState[2];
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
           return new instance_ahnkahet_InstanceScript(map);
        }
};

void AddSC_instance_ahnkahet()
{
    new instance_ahnkahet();
}
