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
#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "magtheridons_lair.h"
#include "Map.h"

BossBoundaryData const boundaries =
{
    { DATA_MAGTHERIDON, new CircleBoundary(Position(-18.70f, 2.24f), 52.30) }
};

DoorData const doorData[] =
{
    { GO_MAGTHERIDON_DOOR,      DATA_MAGTHERIDON,           DOOR_TYPE_ROOM },
    { 0,                        0,                          DOOR_TYPE_ROOM } // END
};

ObjectData const creatureData[] =
{
    { NPC_MAGTHERIDON,          DATA_MAGTHERIDON    },
    { NPC_WORLD_TRIGGER,        DATA_WORLD_TRIGGER  },
    { 0,                        0                   } // END

};

ObjectData const gameObjectData[] =
{
    { GO_MAGTHERIDON_HALL,          DATA_MAGTHERIDON_HALL       },
    { GO_MAGTHERIDON_COLUMN_0,      DATA_MAGTHERIDON_COLUMN_0   },
    { GO_MAGTHERIDON_COLUMN_1,      DATA_MAGTHERIDON_COLUMN_1   },
    { GO_MAGTHERIDON_COLUMN_2,      DATA_MAGTHERIDON_COLUMN_2   },
    { GO_MAGTHERIDON_COLUMN_3,      DATA_MAGTHERIDON_COLUMN_3   },
    { GO_MAGTHERIDON_COLUMN_4,      DATA_MAGTHERIDON_COLUMN_4   },
    { GO_MAGTHERIDON_COLUMN_5,      DATA_MAGTHERIDON_COLUMN_5   },
    { 0,                            0                           } //END
};

static MLDataTypes const collapseObjectDatas[] =
{
    DATA_MAGTHERIDON_COLUMN_0,
    DATA_MAGTHERIDON_COLUMN_1,
    DATA_MAGTHERIDON_COLUMN_2,
    DATA_MAGTHERIDON_COLUMN_3,
    DATA_MAGTHERIDON_COLUMN_4,
    DATA_MAGTHERIDON_COLUMN_5,
};

class instance_magtheridons_lair : public InstanceMapScript
{
    public:
        instance_magtheridons_lair() : InstanceMapScript("instance_magtheridons_lair", 544) { }

        struct instance_magtheridons_lair_InstanceMapScript : public InstanceScript
        {
            instance_magtheridons_lair_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                LoadBossBoundaries(boundaries);
                LoadObjectData(creatureData, gameObjectData);
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                if (go->GetEntry() == GO_MANTICRON_CUBE)
                    cubesGUIDS.push_back(go->GetGUID());
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                if (creature->GetEntry() == NPC_HELLFIRE_WARDER)
                    warderGUIDS.push_back(creature->GetGUID());
            }

            void SetData(uint32 data, uint32 value) override
            {
                switch (data)
                {
                    case DATA_MANTICRON_CUBE:
                        for (ObjectGuid gobGUID : cubesGUIDS)
                            if (GameObject* cube = instance->GetGameObject(gobGUID))
                            {
                                if (value == ACTION_ENABLE)
                                    cube->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                                else
                                    cube->AddFlag(GO_FLAG_NOT_SELECTABLE);
                            }
                        break;
                    case DATA_COLLAPSE:
                        if (GameObject* hall = GetGameObject(DATA_MAGTHERIDON_HALL))
                            HandleGameObject(ObjectGuid::Empty, value == ACTION_ENABLE ? true : false, hall);
                        break;
                    case DATA_COLLAPSE_2:
                        for (MLDataTypes type : collapseObjectDatas)
                            if (GameObject* go = GetGameObject(type))
                                HandleGameObject(ObjectGuid::Empty, value == ACTION_ENABLE ? true : false, go);
                        break;
                    case DATA_CALL_WARDERS:
                        for (ObjectGuid warderGuid : warderGUIDS)
                            if (Creature* warder = instance->GetCreature(warderGuid))
                                if (warder->IsAlive())
                                    warder->SetInCombatWithZone();
                        break;
                    default:
                        break;
                }
            }

        protected:
            GuidVector cubesGUIDS;
            GuidVector warderGUIDS;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_magtheridons_lair_InstanceMapScript(map);
        }
};

void AddSC_instance_magtheridons_lair()
{
    new instance_magtheridons_lair();
}
