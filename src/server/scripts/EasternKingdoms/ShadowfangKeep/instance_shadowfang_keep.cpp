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
#include "shadowfang_keep.h"
#include "AreaBoundary.h"
#include "GameObject.h"
#include "Player.h"
#include "InstanceScript.h"
#include "shadowfang_keep.h"

ObjectData const creatureData[] =
{
    { BOSS_BARON_ASHBURY,               DATA_BARON_ASHBURY          },
    { BOSS_BARON_SILVERLAINE,           DATA_BARON_SILVERLAINE      },
    { BOSS_COMMANDER_SPRINGVALE,        DATA_COMMANDER_SPRINGVALE   },
    { BOSS_LORD_WALDEN,                 DATA_LORD_WALDEN            },
    { BOSS_LORD_GODFREY,                DATA_LORD_GODFREY           },
    { NPC_DEBUG_ANNOUNCER,              DATA_DEBUG_ANNOUNCER        },
    { 0,                                0                           } // END
};

ObjectData const gameobjectData[] =
{
    { GO_COURTYARD_DOOR,                DATA_COURTYARD_DOOR,        },
    { GO_SORCERERS_DOOR,                DATA_SORCERER_GATE,         },
    { GO_ARUGAL_DOOR,                   DATA_ARUGAL_DOOR,           },
    { 0,                                0                           } // END
};

DoorData const doorData[] =
{
    { GO_ARUGAL_DOOR,                    DATA_LORD_GODFREY,              DOOR_TYPE_ROOM    },
    { GO_COURTYARD_DOOR,                 DATA_BARON_ASHBURY,             DOOR_TYPE_PASSAGE }, // Tempfix until events have been implemented
    { GO_SORCERERS_DOOR,                 DATA_LORD_WALDEN,               DOOR_TYPE_PASSAGE }, // Tempfix until events have been implemented
    { 0,                                 0,                              DOOR_TYPE_ROOM    } // END
};

BossBoundaryData const boundaries =
{
    { DATA_COMMANDER_SPRINGVALE,  new ParallelogramBoundary(Position(-222.75f, 2269.03f), Position(-217.60f, 2249.65f), Position(-267.47f, 2256.10f)) },
    { DATA_LORD_WALDEN,  new CircleBoundary(Position(-146.58f, 2173.037f), 17.0) },
};

enum SpawnGroups
{
    SPAWN_GROUP_ENTRANCE_ALLIANCE                       = 412,
    SPAWN_GROUP_ENTRANCE_HORDE                          = 413,
    SPAWN_GROUP_DISEASE_CLOUDS_ENTRANCE                 = 414,
    SPAWN_GROUP_DISEASE_CLOUDS_BARON_ASHBURY            = 415,
    SPAWN_GROUP_DISEASE_CLOUDS_BARON_SILVERLAINE        = 416,
    SPAWN_GROUP_DISEASE_CLOUDS_COMMANDER_SPRINGVALE     = 417,
    SPAWN_GROUP_DISEASE_CLOUDS_LORD_WALDEN              = 418,
    SPAWN_GROUP_LORD_GODFREY_DEAD_TROUPS_ALLIANCE       = 419,
    SPAWN_GROUP_LORD_GODFREY_DEAD_TROUPS_HORDE          = 420,
    SPAWN_GROUP_BARON_ASHBURY_TROUPS_ALLIANCE           = 421,
    SPAWN_GROUP_BARON_ASHBURY_TROUPS_HORDE              = 422,
    SPAWN_GROUP_BARON_SILVERLAINE_TROUPS_ALLIANCE       = 423,
    SPAWN_GROUP_BARON_SILVERLAINE_TROUPS_HORDE          = 424,
    SPAWN_GROUP_COMMANDER_SPRINGVALE_TROUPS_ALLIANCE    = 425,
    SPAWN_GROUP_OUTSIDE_TROUPS_ALLIANCE                 = 426,
};

class instance_shadowfang_keep : public InstanceMapScript
{
public:
    instance_shadowfang_keep() : InstanceMapScript(SKScriptName, 33) { }

    struct instance_shadowfang_keep_InstanceMapScript : public InstanceScript
    {
        instance_shadowfang_keep_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadDoorData(doorData);
            LoadBossBoundaries(boundaries);
            LoadObjectData(creatureData, gameobjectData);
            _currentlyActiveTroupSpawnGroup = 0;
        }

        void OnPlayerEnter(Player* player) override
        {
            if (!_teamInInstance.is_initialized())
            {
                _teamInInstance = player->GetTeam();
                UpdateSpawnGroups();
            }
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
                case NPC_FORSAKEN_BLIGHTSPREADER:
                    creature->SetDisplayId(creature->GetCreatureTemplate()->Modelid1);
                    break;
                default:
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            InstanceScript::OnGameObjectCreate(go);

            switch (go->GetEntry())
            {
                case GO_COURTYARD_DOOR:
                    if (GetBossState(DATA_BARON_ASHBURY) == DONE)
                        go->SetGoState(GO_STATE_ACTIVE);
                    break;
                case GO_SORCERERS_DOOR:
                case GO_ARUGAL_DOOR:
                    if (GetBossState(DATA_LORD_WALDEN) == DONE)
                        go->SetGoState(GO_STATE_ACTIVE);
                    break;
                default:
                    break;
            }
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            if (state == DONE)
            {
                UpdateSpawnGroups();

                switch (type)
                {
                    case DATA_BARON_ASHBURY:
                        _currentlyActiveTroupSpawnGroup = *_teamInInstance == ALLIANCE ? SPAWN_GROUP_BARON_ASHBURY_TROUPS_ALLIANCE : SPAWN_GROUP_BARON_ASHBURY_TROUPS_HORDE;
                        instance->SpawnGroupSpawn(_currentlyActiveTroupSpawnGroup);
                        break;
                    case DATA_BARON_SILVERLAINE:
                        _currentlyActiveTroupSpawnGroup = *_teamInInstance == ALLIANCE ? SPAWN_GROUP_BARON_SILVERLAINE_TROUPS_ALLIANCE : SPAWN_GROUP_BARON_SILVERLAINE_TROUPS_HORDE;
                        instance->SpawnGroupSpawn(_currentlyActiveTroupSpawnGroup);
                        break;
                    case DATA_COMMANDER_SPRINGVALE:
                        if (*_teamInInstance == ALLIANCE)
                        {
                            _currentlyActiveTroupSpawnGroup = 0;
                            instance->SpawnGroupSpawn(SPAWN_GROUP_COMMANDER_SPRINGVALE_TROUPS_ALLIANCE);
                        }
                        break;
                    default:
                        break;
                }
            }

            return true;
        }

        void UpdateSpawnGroups()
        {
            // Disease cloud spawns
            if (*_teamInInstance == HORDE)
            {
                instance->SpawnGroupSpawn(SPAWN_GROUP_DISEASE_CLOUDS_ENTRANCE);

                if (GetBossState(DATA_BARON_ASHBURY) == DONE)
                    instance->SpawnGroupSpawn(SPAWN_GROUP_DISEASE_CLOUDS_BARON_ASHBURY);

                if (GetBossState(DATA_BARON_SILVERLAINE) == DONE)
                    instance->SpawnGroupSpawn(SPAWN_GROUP_DISEASE_CLOUDS_BARON_SILVERLAINE);

                if (GetBossState(DATA_COMMANDER_SPRINGVALE) == DONE)
                    instance->SpawnGroupSpawn(SPAWN_GROUP_DISEASE_CLOUDS_COMMANDER_SPRINGVALE);

                if (GetBossState(DATA_LORD_WALDEN) == DONE)
                    instance->SpawnGroupSpawn(SPAWN_GROUP_DISEASE_CLOUDS_LORD_WALDEN);
            }

            // Despawning previous troups
            if (_currentlyActiveTroupSpawnGroup)
                instance->SpawnGroupDespawn(_currentlyActiveTroupSpawnGroup);

            // Entrance handling
            if (GetBossState(DATA_BARON_ASHBURY) != DONE)
            {
                _currentlyActiveTroupSpawnGroup = *_teamInInstance == ALLIANCE ? SPAWN_GROUP_ENTRANCE_ALLIANCE : SPAWN_GROUP_ENTRANCE_HORDE;
                instance->SpawnGroupSpawn(_currentlyActiveTroupSpawnGroup);
            }

            // Lord Godfrey room setup
            if (GetBossState(DATA_LORD_WALDEN) == DONE)
                instance->SpawnGroupSpawn(*_teamInInstance == ALLIANCE ? SPAWN_GROUP_LORD_GODFREY_DEAD_TROUPS_ALLIANCE : SPAWN_GROUP_LORD_GODFREY_DEAD_TROUPS_HORDE);
        }

        void SetData(uint32 type, uint32 value) override
        {
            switch (type)
            {
                case DATA_OUTSIDE_TROUPS_SPAWN:
                    if (*_teamInInstance == ALLIANCE)
                    {
                        if (_currentlyActiveTroupSpawnGroup)
                            instance->SpawnGroupDespawn(_currentlyActiveTroupSpawnGroup);

                        instance->SpawnGroupSpawn(SPAWN_GROUP_OUTSIDE_TROUPS_ALLIANCE);
                    }
                    break;
                default:
                    break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_TEAM_IN_INSTANCE:
                    return *_teamInInstance;
                default:
                    break;
            }
            return 0;
        }

        protected:
            EventMap events;
            Optional<uint32>_teamInInstance;
            uint32 _currentlyActiveTroupSpawnGroup;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_shadowfang_keep_InstanceMapScript(map);
    }
};

void AddSC_instance_shadowfang_keep()
{
    new instance_shadowfang_keep();
}
