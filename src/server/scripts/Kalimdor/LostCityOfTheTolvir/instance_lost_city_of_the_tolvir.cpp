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
#include "Containers.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "EventMap.h"
#include "InstanceScript.h"
#include "lost_city_of_the_tolvir.h"
#include "Map.h"

static constexpr ObjectData const creatureData[] =
{
    { NPC_GENERAL_HUSAM,        BOSS_GENERAL_HUSAM       },
    { NPC_LOCKMAW,              BOSS_LOCKMAW             },
    { NPC_HIGH_PROPHET_BARIM,   BOSS_HIGH_PROPHET_BARIM  },
    { NPC_SIAMAT,               BOSS_SIAMAT              },
    { NPC_DUST_FLAIL,           DATA_DUST_FLAIL          },
    { 0,                        0                        } // End
};

static constexpr DungeonEncounterData const encounters[] =
{
    { BOSS_GENERAL_HUSAM,       {{ 1052 }} },
    { BOSS_LOCKMAW,             {{ 1054 }} },
    { BOSS_HIGH_PROPHET_BARIM,  {{ 1053 }} },
    { BOSS_SIAMAT,              {{ 1055 }} }
};

enum LCTEvents
{
    EVENT_SPAWN_HEROIC_AUGH = 1
};

enum LCTSpawnGroups
{
    SPAWN_GROUP_ID_SIAMAT_WIND_TUNNEL   = 1036,
    SPAWN_GROUP_ID_AUGH_HEROIC          = 1037
};

class instance_lost_city_of_the_tolvir : public InstanceMapScript
{
public:
    instance_lost_city_of_the_tolvir() : InstanceMapScript(LCTScriptName, 755) { }

    struct instance_lost_city_of_the_tolvir_InstanceMapScript : public InstanceScript
    {
        instance_lost_city_of_the_tolvir_InstanceMapScript(InstanceMap* map) : InstanceScript(map), _heroicAughDespawned(false)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadDungeonEncounterData(encounters);
            LoadObjectData(creatureData, nullptr);
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
                case NPC_ADD_STALKER:
                    _lockmawAddStalkerGUIDs.push_back(creature->GetGUID());
                    break;
                case NPC_FRENZIED_CROCOLISK:
                case NPC_AUGH_ADD_1:
                case NPC_AUGH_ADD_2:
                    // Some adds are spawned by Add Stalkers so we have to register them via instance script for Lockmaw to clean up
                    if (Creature* lockmaw = GetCreature(BOSS_LOCKMAW))
                        if (CreatureAI* ai = lockmaw->AI())
                            ai->JustSummoned(creature);
                    break;
                default:
                    break;
            }
        }

        bool SetBossState(uint32 id, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            switch (id)
            {
                case BOSS_LOCKMAW:
                    if (state == DONE && (instance->IsHeroic() || instance->IsTimewalking()))
                        _events.ScheduleEvent(EVENT_SPAWN_HEROIC_AUGH, 1ms);
                    break;
                default:
                    break;
            }

            if (GetBossState(BOSS_GENERAL_HUSAM) == DONE && GetBossState(BOSS_LOCKMAW) == DONE && GetBossState(BOSS_HIGH_PROPHET_BARIM) == DONE)
                EnableSiamat();

            return true;
        }

        void SetData(uint32 type, uint32 value) override
        {
            switch (type)
            {
                case DATA_SHUFFLE_ADD_STALKERS:
                    Trinity::Containers::RandomShuffle(_lockmawAddStalkerGUIDs);
                    break;
                case DATA_HEROIC_AUGH_DESPAWNED:
                    _heroicAughDespawned = value != 0 ? true : false;
                    break;
                default:
                    break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_HEROIC_AUGH_DESPAWNED:
                    return static_cast<uint8>(_heroicAughDespawned);
                default:
                    return 0;
            }

            return 0;
        }

        void Update(uint32 diff) override
        {
            InstanceScript::Update(diff);

            _events.Update(diff);
            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SPAWN_HEROIC_AUGH:
                        instance->SpawnGroupSpawn(SPAWN_GROUP_ID_AUGH_HEROIC);
                        break;
                    default:
                        break;
                }
            }
        }

        void AfterDataLoad() override
        {
            if (GetBossState(BOSS_GENERAL_HUSAM) == DONE && GetBossState(BOSS_LOCKMAW) == DONE && GetBossState(BOSS_HIGH_PROPHET_BARIM) == DONE)
                EnableSiamat();
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_ADD_STALKER_1:
                case DATA_ADD_STALKER_2:
                case DATA_ADD_STALKER_3:
                case DATA_ADD_STALKER_4:
                    if (_lockmawAddStalkerGUIDs.size() >= (type - DATA_ADD_STALKER_1 + 1))
                        return _lockmawAddStalkerGUIDs[(type - DATA_ADD_STALKER_1)];
                    else
                        return ObjectGuid::Empty;
                default:
                    return InstanceScript::GetGuidData(type);
            }

            return InstanceScript::GetGuidData(type);
        }
    private:
        EventMap _events;
        std::vector<ObjectGuid> _lockmawAddStalkerGUIDs;
        bool _heroicAughDespawned;

        void EnableSiamat()
        {
            instance->SpawnGroupSpawn(SPAWN_GROUP_ID_SIAMAT_WIND_TUNNEL);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_lost_city_of_the_tolvir_InstanceMapScript(map);
    }
};

void AddSC_instance_lost_city_of_the_tolvir()
{
    new instance_lost_city_of_the_tolvir();
}
