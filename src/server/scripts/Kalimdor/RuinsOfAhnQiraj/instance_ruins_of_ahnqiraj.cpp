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

ObjectData const creatureData[] =
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

                AndorovEventState = EVENT_STATE_NOT_STARTED;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                if (creature->HasStringId("GeneralRajaxxWave1"))
                    WaveGuidList[0].insert(creature->GetGUID());

                if (creature->HasStringId("GeneralRajaxxWave2"))
                    WaveGuidList[1].insert(creature->GetGUID());

                if (creature->HasStringId("GeneralRajaxxWave3"))
                    WaveGuidList[2].insert(creature->GetGUID());

                if (creature->HasStringId("GeneralRajaxxWave4"))
                    WaveGuidList[3].insert(creature->GetGUID());

                if (creature->HasStringId("GeneralRajaxxWave5"))
                    WaveGuidList[4].insert(creature->GetGUID());

                if (creature->HasStringId("GeneralRajaxxWave6"))
                    WaveGuidList[5].insert(creature->GetGUID());

                if (creature->HasStringId("GeneralRajaxxWave7"))
                    WaveGuidList[6].insert(creature->GetGUID());
            }

            void OnUnitDeath(Unit* unit) override
            {
                InstanceScript::OnUnitDeath(unit);

                if (unit->GetTypeId() != TYPEID_UNIT)
                    return;

                // Wave 2
                if (WaveGuidList[0].find(unit->GetGUID()) != WaveGuidList[0].end())
                {
                    WaveGuidList[0].erase(unit->GetGUID());
                    if (WaveGuidList[0].size() == 0)
                    {
                        for (ObjectGuid guid : WaveGuidList[1])
                            if (Creature* creature = instance->GetCreature(guid))
                                if (creature->IsAlive() && !creature->IsInCombat())
                                    creature->AI()->DoZoneInCombat();
                    }
                }

                // Wave 3
                if (WaveGuidList[1].find(unit->GetGUID()) != WaveGuidList[1].end())
                {
                    WaveGuidList[1].erase(unit->GetGUID());
                    if (WaveGuidList[1].size() == 0)
                    {
                        for (ObjectGuid guid : WaveGuidList[2])
                            if (Creature* creature = instance->GetCreature(guid))
                                if (creature->IsAlive() && !creature->IsInCombat())
                                    creature->AI()->DoZoneInCombat();

                        if (Creature* rajaxx = GetCreature(DATA_RAJAXX))
                            rajaxx->AI()->DoAction(ACTION_WAVE_STARTS_3);
                    }
                }

                // Wave 4
                if (WaveGuidList[2].find(unit->GetGUID()) != WaveGuidList[2].end())
                {
                    WaveGuidList[2].erase(unit->GetGUID());
                    if (WaveGuidList[2].size() == 0)
                    {
                        for (ObjectGuid guid : WaveGuidList[3])
                            if (Creature* creature = instance->GetCreature(guid))
                                if (creature->IsAlive() && !creature->IsInCombat())
                                    creature->AI()->DoZoneInCombat();

                        if (Creature* rajaxx = GetCreature(DATA_RAJAXX))
                            rajaxx->AI()->DoAction(ACTION_WAVE_STARTS_4);
                    }
                }

                // Wave 5
                if (WaveGuidList[3].find(unit->GetGUID()) != WaveGuidList[3].end())
                {
                    WaveGuidList[3].erase(unit->GetGUID());
                    if (WaveGuidList[3].size() == 0)
                    {
                        for (ObjectGuid guid : WaveGuidList[4])
                            if (Creature* creature = instance->GetCreature(guid))
                                if (creature->IsAlive() && !creature->IsInCombat())
                                    creature->AI()->DoZoneInCombat();

                        if (Creature* rajaxx = GetCreature(DATA_RAJAXX))
                            rajaxx->AI()->DoAction(ACTION_WAVE_STARTS_5);
                    }
                }

                // Wave 6
                if (WaveGuidList[4].find(unit->GetGUID()) != WaveGuidList[4].end())
                {
                    WaveGuidList[4].erase(unit->GetGUID());
                    if (WaveGuidList[4].size() == 0)
                    {
                        for (ObjectGuid guid : WaveGuidList[5])
                            if (Creature* creature = instance->GetCreature(guid))
                                if (creature->IsAlive() && !creature->IsInCombat())
                                    creature->AI()->DoZoneInCombat();

                        if (Creature* rajaxx = GetCreature(DATA_RAJAXX))
                            rajaxx->AI()->DoAction(ACTION_WAVE_STARTS_6);
                    }
                }

                // Wave 7
                if (WaveGuidList[5].find(unit->GetGUID()) != WaveGuidList[5].end())
                {
                    WaveGuidList[5].erase(unit->GetGUID());
                    if (WaveGuidList[5].size() == 0)
                    {
                        for (ObjectGuid guid : WaveGuidList[6])
                            if (Creature* creature = instance->GetCreature(guid))
                                if (creature->IsAlive() && !creature->IsInCombat())
                                    creature->AI()->DoZoneInCombat();

                        if (Creature* rajaxx = GetCreature(DATA_RAJAXX))
                            rajaxx->AI()->DoAction(ACTION_WAVE_STARTS_7);
                    }
                }

                // Rajaxx
                if (WaveGuidList[6].find(unit->GetGUID()) != WaveGuidList[6].end())
                {
                    WaveGuidList[6].erase(unit->GetGUID());
                    if (WaveGuidList[6].size() == 0)
                    {
                        if (Creature* rajaxx = GetCreature(DATA_RAJAXX))
                            rajaxx->AI()->DoAction(ACTION_RAJAXX_ENTER);
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
                            if (GetData(DATA_ANDOROV_EVENT_STATE) == EVENT_STATE_STARTED)
                            {
                                SetData(DATA_ANDOROV_EVENT_STATE, EVENT_STATE_FINISHED);

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
                    if (data == EVENT_STATE_STARTED)
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
