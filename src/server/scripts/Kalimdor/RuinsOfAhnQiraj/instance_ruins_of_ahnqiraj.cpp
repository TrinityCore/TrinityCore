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
#include "CreatureAI.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ruins_of_ahnqiraj.h"
#include <algorithm>

static constexpr ObjectData creatureData[] =
{
    { NPC_KURINAXX,        DATA_KURINNAXX    },
    { NPC_RAJAXX,          DATA_RAJAXX       },
    { NPC_MOAM,            DATA_MOAM         },
    { NPC_BURU,            DATA_BURU         },
    { NPC_AYAMISS,         DATA_AYAMISS      },
    { NPC_OSSIRIAN,        DATA_OSSIRIAN     },
    { NPC_ANDOROV,         DATA_ANDOROV      },
    { 0,                   0                 } // END
};

struct RajaxxWave
{
    std::string_view StringId;
    int32 BossActionIdOnClear;
};

static constexpr std::array<RajaxxWave, 7> RajaxxWaves =
{{
    { "GeneralRajaxxWave1", 0 },
    { "GeneralRajaxxWave2", ACTION_WAVE_STARTS_3 },
    { "GeneralRajaxxWave3", ACTION_WAVE_STARTS_4 },
    { "GeneralRajaxxWave4", ACTION_WAVE_STARTS_5 },
    { "GeneralRajaxxWave5", ACTION_WAVE_STARTS_6 },
    { "GeneralRajaxxWave6", ACTION_WAVE_STARTS_7 },
    { "GeneralRajaxxWave7", ACTION_RAJAXX_ENTER }
}};

class instance_ruins_of_ahnqiraj : public InstanceMapScript
{
    public:
        instance_ruins_of_ahnqiraj() : InstanceMapScript(AQ20ScriptName, 509) { }

        struct instance_ruins_of_ahnqiraj_InstanceMapScript : public InstanceScript
        {
            instance_ruins_of_ahnqiraj_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, nullptr);

                AndorovEventState = NOT_STARTED;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                auto rajaxxWave = std::ranges::find_if(RajaxxWaves, [creature](std::string_view stringId) { return creature->HasStringId(stringId); }, &RajaxxWave::StringId);
                if (rajaxxWave != RajaxxWaves.end())
                    WaveGuidList[std::ranges::distance(RajaxxWaves.begin(), rajaxxWave)].insert(creature->GetGUID());
            }

            void OnUnitDeath(Unit* unit) override
            {
                InstanceScript::OnUnitDeath(unit);

                if (unit->GetTypeId() != TYPEID_UNIT)
                    return;

                auto rajaxxWave = std::ranges::find_if(RajaxxWaves, [creature = unit->ToCreature()](std::string_view stringId) { return creature->HasStringId(stringId); }, &RajaxxWave::StringId);
                if (rajaxxWave != RajaxxWaves.end())
                {
                    std::ptrdiff_t waveIndex = std::ranges::distance(RajaxxWaves.begin(), rajaxxWave);
                    if (WaveGuidList[waveIndex].erase(unit->GetGUID()) && WaveGuidList[waveIndex].empty())
                    {
                        // start next wave
                        if (waveIndex + 1 < std::ranges::ssize(WaveGuidList))
                            for (ObjectGuid guid : WaveGuidList[waveIndex + 1])
                                if (Creature* creature = instance->GetCreature(guid))
                                    if (creature->IsAlive() && !creature->IsInCombat())
                                        creature->AI()->DoZoneInCombat();

                        if (rajaxxWave->BossActionIdOnClear)
                            if (Creature* rajaxx = GetCreature(DATA_RAJAXX))
                                rajaxx->AI()->DoAction(rajaxxWave->BossActionIdOnClear);
                    }
                }
            }

            bool SetBossState(uint32 bossId, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(bossId, state))
                    return false;

                switch (bossId)
                {
                    case DATA_KURINNAXX:
                        if (state == DONE)
                        {
                            instance->SpawnGroupSpawn(SPAWN_GROUP_ANDOROV);

                            if (Creature* ossirian = GetCreature(DATA_OSSIRIAN))
                                ossirian->AI()->DoAction(ACTION_KURINNAXX_DEFEATED);
                        }
                        break;
                    case DATA_RAJAXX:
                        if (state == DONE)
                        {
                            /// @todo: This part requires additional research. Here we check if Andorov's event was started
                            /// and only then change it to finished to enable vendor. Otherwise players can complete
                            /// Rajaxx's encounter without Andorov and then talk to him to buy items, doubt that should happen
                            if (GetData(DATA_ANDOROV_EVENT_STATE) == IN_PROGRESS)
                            {
                                SetData(DATA_ANDOROV_EVENT_STATE, DONE);

                                if (Creature* andorov = GetCreature(DATA_ANDOROV))
                                    andorov->AI()->DoAction(ACTION_RAJAXX_DEFEATED);
                            }
                        }
                        break;
                }

                return true;
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_ANDOROV_EVENT_STATE)
                {
                    AndorovEventState = data;
                    if (data == IN_PROGRESS)
                    {
                        // Wave 1
                        for (ObjectGuid guid : WaveGuidList[0])
                            if (Creature* creature = instance->GetCreature(guid))
                                if (creature->IsAlive() && !creature->IsInCombat())
                                    creature->AI()->DoZoneInCombat();
                    }
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_ANDOROV_EVENT_STATE)
                    return AndorovEventState;

                return 0;
            }

            void SetGuidData(uint32 type, ObjectGuid data) override
            {
                if (type == DATA_PARALYZED)
                    ParalyzedGUID = data;
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                if (type == DATA_PARALYZED)
                    return ParalyzedGUID;

                return ObjectGuid::Empty;
            }

        protected:
            uint8 AndorovEventState;
            GuidSet WaveGuidList[7];
            ObjectGuid ParalyzedGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_ruins_of_ahnqiraj_InstanceMapScript(map);
        }
};

void AddSC_instance_ruins_of_ahnqiraj()
{
    new instance_ruins_of_ahnqiraj();
}
