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

#include "end_time.h"
#include "EventMap.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptMgr.h"

#include <array>

ObjectData const creatureData[] =
{
    { BOSS_MUROZOND,    DATA_MUROZOND   },
    { 0,                0               } // END
};

ObjectData const gameobjectData[] =
{
    { GO_HOURGLASS_OF_TIME, DATA_HOURGLASS_OF_TIME } // END
};

DoorData const doorData[] =
{
    { 0, 0, DOOR_TYPE_ROOM } // END
};

enum Events
{
    EVENT_RESPAWN_MUROZOND = 1
};

enum SpawnGroups
{
    SPAWN_GROUP_ID_MUROZOND_CHEST   = 437
};

enum AreaIds
{
    AREA_ID_BRONZE_DRAGON_SHRINE = 5795
};

std::array<Position const, 2> MurozondSpawnPositions =
{
    Position(4288.125f, -456.40277f, 160.4989f,  2.98451f), // Initial spawn position
    Position(4181.117f, -420.21933f, 138.38057f, 3.10668f)  // Respawn position
};

class instance_end_time : public InstanceMapScript
{
public:
    instance_end_time() : InstanceMapScript(ETScriptName, 938) { }

    struct instance_end_time_InstanceMapScript : public InstanceScript
    {
        instance_end_time_InstanceMapScript(InstanceMap* map) : InstanceScript(map), _killedInfiniteDragonkins(0)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadDoorData(doorData);
            LoadObjectData(creatureData, gameobjectData);
        }

        void Create() override
        {
            InstanceScript::Create();

            // The instance has been created without save data, just spawn Murozond at his initial position.
            instance->SummonCreature(BOSS_MUROZOND, MurozondSpawnPositions[0]);
        }

        void Load(char const* data) override
        {
            InstanceScript::Load(data);

            // The instance has been created from existing save data, but Murozond has not been defeated yet. Spawn him at his initial position.
            if (GetBossState(DATA_MUROZOND) != DONE)
                instance->SummonCreature(BOSS_MUROZOND, MurozondSpawnPositions[0]);
        }

        void OnUnitDeath(Unit* unit) override
        {
            if (!unit->IsCreature())
                return;

            switch (unit->GetEntry())
            {
                case NPC_INFINITE_SUPRESSOR:
                case NPC_INFINITE_WARDEN:
                    ++_killedInfiniteDragonkins;
                    if (_killedInfiniteDragonkins == 4 || _killedInfiniteDragonkins == 8)
                        if (Creature* murozond = GetCreature(DATA_MUROZOND))
                            if (murozond->IsAIEnabled)
                                murozond->AI()->SetData(DATA_MUROZOND_INTRO, _killedInfiniteDragonkins == 4 ? IN_PROGRESS : DONE);
                    break;
                default:
                    break;
            }
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
                case NPC_NOZDORMU_DRAGON_SHRINES:
                    if (creature->GetAreaId() == AREA_ID_BRONZE_DRAGON_SHRINE)
                        AddObject(creature, DATA_NOZDORMU_BRONZE_DRAGON_SHRINE, true);
                    break;
                default:
                    break;
            }
        }

        void OnCreatureRemove(Creature* creature) override
        {
            InstanceScript::OnCreatureRemove(creature);

            switch (creature->GetEntry())
            {
                case NPC_NOZDORMU_DRAGON_SHRINES:
                    if (creature->GetAreaId() == AREA_ID_BRONZE_DRAGON_SHRINE)
                        AddObject(creature, DATA_NOZDORMU_BRONZE_DRAGON_SHRINE, false);
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
                case DATA_MUROZOND:
                    if (state == FAIL)
                        _events.ScheduleEvent(EVENT_RESPAWN_MUROZOND, 30s);
                    else if (state == DONE)
                        instance->SpawnGroupSpawn(SPAWN_GROUP_ID_MUROZOND_CHEST);
                    break;
                default:
                    break;
            }

            return true;
        }

        void Update(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_RESPAWN_MUROZOND:
                        instance->SummonCreature(BOSS_MUROZOND, MurozondSpawnPositions[1]);
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap _events;
        uint8 _killedInfiniteDragonkins;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_end_time_InstanceMapScript(map);
    }
};

void AddSC_instance_end_time()
{
    new instance_end_time();
}
