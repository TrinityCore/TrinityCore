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
#include "blood_furnace.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include <algorithm>

static constexpr DoorData doorData[] =
{
    { GO_PRISON_DOOR_01,     DATA_KELIDAN,   DOOR_TYPE_PASSAGE },
    { GO_PRISON_DOOR_02,     DATA_THE_MAKER, DOOR_TYPE_ROOM    },
    { GO_PRISON_DOOR_03,     DATA_THE_MAKER, DOOR_TYPE_PASSAGE },
    { GO_PRISON_DOOR_05,     DATA_BROGGOK,   DOOR_TYPE_ROOM    },
    { GO_SUMMON_DOOR,        DATA_KELIDAN,   DOOR_TYPE_PASSAGE },
    { GO_PRISON_CELL_DOOR_4, DATA_THE_MAKER, DOOR_TYPE_PASSAGE },
    { 0,                     0,              DOOR_TYPE_ROOM    } // END
};

static constexpr ObjectData creatureData[] =
{
    { NPC_THE_MAKER,           DATA_THE_MAKER },
    { NPC_BROGGOK,             DATA_BROGGOK   },
    { NPC_KELIDAN,             DATA_KELIDAN   },
    { 0,                       0              } // END
};

static constexpr ObjectData gameObjectData[] =
{
    { GO_BROGGOK_LEVER,          DATA_BROGGOK_LEVER      },
    { GO_PRISON_DOOR_04,         DATA_PRISON_DOOR_04     },
    { GO_PRISON_DOOR_05,         DATA_PRISON_DOOR_05     },
    { GO_PRISON_CELL_DOOR_5,     DATA_PRISON_CELL_DOOR_5 },
    { GO_PRISON_CELL_DOOR_6,     DATA_PRISON_CELL_DOOR_6 },
    { GO_PRISON_CELL_DOOR_7,     DATA_PRISON_CELL_DOOR_7 },
    { GO_PRISON_CELL_DOOR_8,     DATA_PRISON_CELL_DOOR_8 },
    { 0,                         0                       } // END
};

struct PrisonersWave
{
    std::string_view StringId;
    uint32 CellOrDoorToOpen;
    int32 BossActionIdOnClear;
};

static constexpr std::array<PrisonersWave, 4> PrisonersWaves =
{{
    { "BroggokPrisonerCell1", DATA_PRISON_CELL_DOOR_6, 0 },
    { "BroggokPrisonerCell2", DATA_PRISON_CELL_DOOR_7, 0 },
    { "BroggokPrisonerCell3", DATA_PRISON_CELL_DOOR_8, 0 },
    { "BroggokPrisonerCell4", DATA_PRISON_DOOR_04, ACTION_RELEASE_BROGGOK }
}};

static constexpr std::array<uint32, 4> PrisonCellDoorsData =
{
    DATA_PRISON_CELL_DOOR_5,
    DATA_PRISON_CELL_DOOR_6,
    DATA_PRISON_CELL_DOOR_7,
    DATA_PRISON_CELL_DOOR_8
};

static constexpr std::array<uint32, 4> PrisonersSpawnGroupsData =
{
    SPAWN_GROUP_PRISONERS_1,
    SPAWN_GROUP_PRISONERS_2,
    SPAWN_GROUP_PRISONERS_3,
    SPAWN_GROUP_PRISONERS_4
};

class instance_blood_furnace : public InstanceMapScript
{
    public:
        instance_blood_furnace() : InstanceMapScript(BFScriptName, 542) { }

        struct instance_blood_furnace_InstanceMapScript : public InstanceScript
        {
            instance_blood_furnace_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameObjectData);

                PrisonersEventState = NOT_STARTED;
                ShouldResetPrisoners = true;
            }

            void OnPlayerEnter(Player* /*player*/) override
            {
                if (ShouldResetPrisoners)
                {
                    for (uint32 group : PrisonersSpawnGroupsData)
                        instance->SpawnGroupSpawn(group, true);

                    ShouldResetPrisoners = false;
                }
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                auto prisonerWave = std::ranges::find_if(PrisonersWaves, [creature](std::string_view stringId) { return creature->HasStringId(stringId); }, &PrisonersWave::StringId);
                if (prisonerWave != PrisonersWaves.end())
                    WaveGuidList[std::ranges::distance(PrisonersWaves.begin(), prisonerWave)].insert(creature->GetGUID());
            }

            void OnUnitDeath(Unit* unit) override
            {
                InstanceScript::OnUnitDeath(unit);

                if (unit->GetTypeId() != TYPEID_UNIT)
                    return;

                auto prisonerWave = std::ranges::find_if(PrisonersWaves, [creature = unit->ToCreature()](std::string_view stringId) { return creature->HasStringId(stringId); }, &PrisonersWave::StringId);
                if (prisonerWave != PrisonersWaves.end())
                {
                    std::ptrdiff_t waveIndex = std::ranges::distance(PrisonersWaves.begin(), prisonerWave);
                    if (WaveGuidList[waveIndex].erase(unit->GetGUID()) && WaveGuidList[waveIndex].empty())
                    {
                        if (prisonerWave->CellOrDoorToOpen)
                            if (GameObject* go = GetGameObject(prisonerWave->CellOrDoorToOpen))
                                HandleGameObject(ObjectGuid::Empty, true, go);

                        if (waveIndex + 1 < std::ranges::ssize(WaveGuidList))
                            for (ObjectGuid guid : WaveGuidList[waveIndex + 1])
                                if (Creature* creature = instance->GetCreature(guid))
                                    creature->AI()->DoZoneInCombat();

                        if (prisonerWave->BossActionIdOnClear)
                            if (Creature* broggok = GetCreature(DATA_BROGGOK))
                                broggok->AI()->DoAction(prisonerWave->BossActionIdOnClear);
                    }
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                if (go->GetEntry() == GO_PRISON_DOOR_04)
                    if (GetBossState(DATA_BROGGOK) == DONE)
                        HandleGameObject(ObjectGuid::Empty, true, go);
            }

            void SetData(uint32 type, uint32 data) override
            {
                // This have to be done without boss state since encounter starts when Broggok is engaged, not when prisoners event starts
                if (type == DATA_PRISONERS_EVENT)
                {
                    // Do not set data to current - don't trigger events more than once
                    if (PrisonersEventState == data)
                        return;

                    PrisonersEventState = data;

                    switch (data)
                    {
                        case IN_PROGRESS:
                        {
                            if (Creature* broggok = GetCreature(DATA_BROGGOK))
                                broggok->AI()->DoAction(ACTION_PERFORM_INTRO);

                            if (GameObject* go = GetGameObject(DATA_PRISON_DOOR_05))
                                HandleGameObject(ObjectGuid::Empty, false, go);

                            if (GameObject* go = GetGameObject(DATA_PRISON_CELL_DOOR_5))
                                HandleGameObject(ObjectGuid::Empty, true, go);

                            for (ObjectGuid guid : WaveGuidList[0])
                                if (Creature* creature = instance->GetCreature(guid))
                                    creature->AI()->DoZoneInCombat();

                            break;
                        }
                        case FAIL:
                        {
                            if (GameObject* lever = GetGameObject(DATA_BROGGOK_LEVER))
                                lever->ActivateObject(GameObjectActions(GameObjectActions::MakeActive));

                            if (Creature* broggok = GetCreature(DATA_BROGGOK))
                                broggok->AI()->DoAction(ACTION_DESPAWN_TRIGGER);

                            if (GameObject* go = GetGameObject(DATA_PRISON_DOOR_05))
                                HandleGameObject(ObjectGuid::Empty, true, go);

                            for (uint32 data : PrisonCellDoorsData)
                                if (GameObject* go = GetGameObject(data))
                                    HandleGameObject(ObjectGuid::Empty, false, go);

                            for (uint32 group : PrisonersSpawnGroupsData)
                                instance->SpawnGroupSpawn(group, true);

                            break;
                        }
                        default:
                            break;
                    }
                }
            }

            void ReadSaveDataMore(std::istringstream& /*data*/) override
            {
                ShouldResetPrisoners = GetBossState(DATA_BROGGOK) != DONE;
            }

        protected:
            uint8 PrisonersEventState;
            GuidSet WaveGuidList[4];
            bool ShouldResetPrisoners;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_blood_furnace_InstanceMapScript(map);
        }
};

void AddSC_instance_blood_furnace()
{
    new instance_blood_furnace();
}
