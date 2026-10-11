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
#include "AreaBoundary.h"
#include "FlatSet.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "magtheridons_lair.h"
#include "Map.h"
#include "ScriptedCreature.h"

static BossBoundaryData const boundaries =
{
    { DATA_MAGTHERIDON, new CircleBoundary(Position(-18.70f, 2.24f), 52.30f) }
};

static constexpr DoorData doorData[] =
{
    { GO_MAGTHERIDON_DOOR,      DATA_MAGTHERIDON,           EncounterDoorBehavior::OpenWhenNotInProgress },
};

static constexpr ObjectData creatureData[] =
{
    { NPC_MAGTHERIDON,          DATA_MAGTHERIDON    },
    { NPC_WORLD_TRIGGER,        DATA_WORLD_TRIGGER  },

};

static constexpr ObjectData gameObjectData[] =
{
    { GO_MAGTHERIDON_HALL,          DATA_MAGTHERIDON_HALL       },
    { GO_MAGTHERIDON_COLUMN_0,      DATA_MAGTHERIDON_COLUMN_0   },
    { GO_MAGTHERIDON_COLUMN_1,      DATA_MAGTHERIDON_COLUMN_1   },
    { GO_MAGTHERIDON_COLUMN_2,      DATA_MAGTHERIDON_COLUMN_2   },
    { GO_MAGTHERIDON_COLUMN_3,      DATA_MAGTHERIDON_COLUMN_3   },
    { GO_MAGTHERIDON_COLUMN_4,      DATA_MAGTHERIDON_COLUMN_4   },
    { GO_MAGTHERIDON_COLUMN_5,      DATA_MAGTHERIDON_COLUMN_5   },
};

static constexpr std::array<uint32, 6> ColumnObjectDataTypes =
{
    DATA_MAGTHERIDON_COLUMN_0,
    DATA_MAGTHERIDON_COLUMN_1,
    DATA_MAGTHERIDON_COLUMN_2,
    DATA_MAGTHERIDON_COLUMN_3,
    DATA_MAGTHERIDON_COLUMN_4,
    DATA_MAGTHERIDON_COLUMN_5
};

static constexpr DungeonEncounterData encounters[] =
{
    { DATA_MAGTHERIDON, {{ 651 }} }
};

class instance_magtheridons_lair : public InstanceMapScript
{
    public:
        instance_magtheridons_lair() : InstanceMapScript(MLScriptName, 544) { }

        struct instance_magtheridons_lair_InstanceMapScript : public InstanceScript
        {
            instance_magtheridons_lair_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                LoadBossBoundaries(boundaries);
                LoadObjectData(creatureData, gameObjectData);
                LoadDungeonEncounterData(encounters);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                if (creature->GetEntry() == NPC_HELLFIRE_WARDER)
                    WarderGuids.insert(creature->GetGUID());
            }

            void OnCreatureRemove(Creature* creature) override
            {
                InstanceScript::OnCreatureRemove(creature);

                if (creature->GetEntry() == NPC_HELLFIRE_WARDER)
                    WarderGuids.erase(creature->GetGUID());
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                if (go->GetEntry() == GO_MANTICRON_CUBE)
                    CubeGuids.insert(go->GetGUID());
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                InstanceScript::OnGameObjectRemove(go);

                if (go->GetEntry() == GO_MANTICRON_CUBE)
                    CubeGuids.erase(go->GetGUID());
            }

            void SetData(uint32 data, uint32 value) override
            {
                switch (data)
                {
                    case DATA_MANTICRON_CUBE:
                        for (ObjectGuid const& guid : CubeGuids)
                            if (GameObject* go = instance->GetGameObject(guid))
                                go->ActivateObject(value == ACTION_ENABLE ? GameObjectActions::MakeActive : GameObjectActions::MakeInert, 0);
                        break;
                    case DATA_COLLAPSE_1:
                        if (GameObject* go = GetGameObject(DATA_MAGTHERIDON_HALL))
                            HandleGameObject(ObjectGuid::Empty, value == ACTION_ENABLE, go);
                        break;
                    case DATA_COLLAPSE_2:
                        for (uint32 columnData : ColumnObjectDataTypes)
                            if (GameObject* go = GetGameObject(columnData))
                                HandleGameObject(ObjectGuid::Empty, value == ACTION_ENABLE, go);
                        break;
                    case DATA_CALL_WARDERS:
                        for (ObjectGuid const& guid : WarderGuids)
                            if (Creature* warder = instance->GetCreature(guid))
                                if (warder->IsAlive())
                                    warder->AI()->DoZoneInCombat();
                        break;
                    default:
                        break;
                }
            }

        protected:
            Trinity::Containers::FlatSet<ObjectGuid> CubeGuids;
            Trinity::Containers::FlatSet<ObjectGuid> WarderGuids;
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
