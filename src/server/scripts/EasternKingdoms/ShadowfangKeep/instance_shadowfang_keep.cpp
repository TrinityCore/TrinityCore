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
#include "Map.h"
#include "Creature.h"
#include "EventMap.h"
#include "CreatureAI.h"

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
    { GO_ARUGALS_LAIR,                  DATA_ARUGAL_DOOR,           },
    { 0,                                0                           } // END
};

DoorData const doorData[] =
{
    { GO_ARUGALS_LAIR,                   DATA_LORD_GODFREY,              DOOR_TYPE_ROOM    },
    { 0,                                 0,                              DOOR_TYPE_ROOM    } // END
};

BossBoundaryData const boundaries =
{
    { DATA_COMMANDER_SPRINGVALE,  new ParallelogramBoundary(Position(-222.75f, 2269.03f), Position(-217.60f, 2249.65f), Position(-267.47f, 2256.10f)) },
    { DATA_LORD_WALDEN,  new CircleBoundary(Position(-146.58f, 2173.037f), 17.0) },
};

enum SpawnGroups
{
    SPAWN_GROUP_ENTRANCE_ALLIANCE                       = 412, // Spawned by default when Baron Ashbury is not defeated for Alliance players
    SPAWN_GROUP_ENTRANCE_HORDE                          = 413, // Spawned by default when Baron Ashbury is not defeated for Horde players

    SPAWN_GROUP_DISEASE_CLOUDS_ENTRANCE                 = 414, // Spawned by default for Horde players
    SPAWN_GROUP_DISEASE_CLOUDS_BARON_ASHBURY            = 415, // Spawned for Horde players when Baron Ashbury has been defeated
    SPAWN_GROUP_DISEASE_CLOUDS_BARON_SILVERLAINE        = 416, // Spawned for Horde players when Baron Silverlaine has been defeated
    SPAWN_GROUP_DISEASE_CLOUDS_COMMANDER_SPRINGVALE     = 417, // Spawned for Horde players when Commander Springvale has been defeated
    SPAWN_GROUP_DISEASE_CLOUDS_LORD_WALDEN              = 418, // Spawned for Horde players when Lord Walden has been defeated

    SPAWN_GROUP_LORD_GODFREY_DEAD_TROUPS_ALLIANCE       = 419, // Spawned for Alliance players when Lord Walden has been defeated
    SPAWN_GROUP_LORD_GODFREY_DEAD_TROUPS_HORDE          = 420, // Spawned for Horde players when Lord Walden has been defeated

    SPAWN_GROUP_BARON_ASHBURY_TROUPS_ALLIANCE           = 421, // Spawned for Alliance players when Baron Ashbury has been defeated
    SPAWN_GROUP_BARON_ASHBURY_TROUPS_HORDE              = 422, // Spawned for Horde players when Baron Ashbury has been defeated

    SPAWN_GROUP_BARON_SILVERLAINE_TROUPS_ALLIANCE       = 423, // Spawned for Alliance players when Baron Silverlaine has been defeated
    SPAWN_GROUP_BARON_SILVERLAINE_TROUPS_HORDE          = 424, // Spawned for Horde players when Baron Silverlaine has been defeated

    SPAWN_GROUP_COMMANDER_SPRINGVALE_TROUPS_ALLIANCE    = 425, // Spawned for Alliance players when Commander Springvale has been defeated
    SPAWN_GROUP_OUTSIDE_TROUPS_ALLIANCE                 = 426, // Spawned for Alliance players when triggering an areatrigger after defeating Commander Springvale
    SPAWN_GROUP_LORD_WALDEN_TROUPS_ALLIANCE             = 427, // Spawned for Alliance players when Lord Walden has been defeated

    SPAWN_GROUP_COMMANDER_SPRINGVALE_TROUPS_HORDE       = 428, // Spawned for Horde players when Commander Springvale or Lord Walden has been defeated
    SPAWN_GROUP_COMMANDER_SPRINGVALE_BELMONT            = 429, // Spawned for Horde players when Commander Springvale has been defeated
    SPAWN_GROUP_LORD_WALDEN_BELMONT                     = 430, // Spawned for Horde players when Lord Walden has been defeated

    SPAWN_GROUP_LORD_GODFREY_IVAR_BLOODFANG             = 431, // Spawned for Alliance players when triggering an areatrigger near Lord Godfrey's room
    SPAWN_GROUP_LORD_GODFREY_BELMONT                    = 432  // Spawned for Horde players when triggering an areatrigger near Lord Godfrey's room
};

struct SpawnGroupInfo
{
    uint32 AllianceSpawnGroup = 0;
    uint32 HordeSpawnGroup = 0;
    uint32 DiseaseCloudsSpawnGroup = 0;
};

std::unordered_map<uint32 /*bossStateId*/, SpawnGroupInfo> SpawnGroupsByBossStateId =
{
    { DATA_BARON_ASHBURY,           { SPAWN_GROUP_BARON_ASHBURY_TROUPS_ALLIANCE,        SPAWN_GROUP_BARON_ASHBURY_TROUPS_HORDE,         SPAWN_GROUP_DISEASE_CLOUDS_BARON_ASHBURY        }},
    { DATA_BARON_SILVERLAINE,       { SPAWN_GROUP_BARON_SILVERLAINE_TROUPS_ALLIANCE,    SPAWN_GROUP_BARON_SILVERLAINE_TROUPS_HORDE,     SPAWN_GROUP_DISEASE_CLOUDS_BARON_SILVERLAINE    }},
    { DATA_COMMANDER_SPRINGVALE,    { SPAWN_GROUP_COMMANDER_SPRINGVALE_TROUPS_ALLIANCE, SPAWN_GROUP_COMMANDER_SPRINGVALE_BELMONT,       SPAWN_GROUP_DISEASE_CLOUDS_COMMANDER_SPRINGVALE }},
    { DATA_LORD_WALDEN,             { SPAWN_GROUP_LORD_WALDEN_TROUPS_ALLIANCE,          SPAWN_GROUP_LORD_WALDEN_BELMONT,                SPAWN_GROUP_DISEASE_CLOUDS_LORD_WALDEN          }},
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
        }

        void OnPlayerEnter(Player* player) override
        {
            if (!_teamInInstance.has_value())
            {
                _teamInInstance = player->GetTeam();

                // Setting up entrance spawns when Baron Ashbury has not been defeated yet
                if (GetBossState(DATA_BARON_ASHBURY) != DONE)
                    instance->SpawnGroupSpawn(*_teamInInstance == ALLIANCE ? SPAWN_GROUP_ENTRANCE_ALLIANCE : SPAWN_GROUP_ENTRANCE_HORDE);

                // Setting up disease clouds based on instance progress
                if (*_teamInInstance == HORDE)
                {
                    for (uint32 bossId : { DATA_BARON_ASHBURY, DATA_BARON_SILVERLAINE, DATA_COMMANDER_SPRINGVALE, DATA_LORD_WALDEN })
                    {
                        if (GetBossState(bossId) == DONE)
                        {
                            SpawnGroupInfo spawnGroupInfo = SpawnGroupsByBossStateId[bossId];
                            instance->SpawnGroupSpawn(spawnGroupInfo.DiseaseCloudsSpawnGroup);
                        }
                    }
                }

                // Setting up dead troup spawns when Lord Walden has been defeated already
                if (GetBossState(DATA_LORD_WALDEN) == DONE)
                    instance->SpawnGroupSpawn(*_teamInInstance == ALLIANCE ? SPAWN_GROUP_LORD_GODFREY_DEAD_TROUPS_ALLIANCE : SPAWN_GROUP_LORD_GODFREY_DEAD_TROUPS_HORDE);
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
                case NPC_HIGH_WARLORD_CROMUSH:
                    if (creature->ToTempSummon())
                        _cromushGUID = creature->GetGUID();
                    break;
                case NPC_PISTOL_BARRAGE_DUMMY:
                    if (Creature* godfrey = GetCreature(DATA_LORD_GODFREY))
                        if (godfrey->IsAIEnabled)
                            godfrey->AI()->JustSummoned(creature);
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
                    if (GetBossState(DATA_LORD_WALDEN) == DONE)
                        go->SetGoState(GO_STATE_ACTIVE);
                    break;
                case GO_ARUGALS_LAIR:
                    if (GetBossState(DATA_LORD_GODFREY) != DONE)
                        go->SetGoState(GO_STATE_READY);
                    break;
                default:
                    break;
            }
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            if (state != DONE || type == BOSS_LORD_GODFREY)
                return true;

            SpawnGroupInfo spawnGroupInfo = SpawnGroupsByBossStateId[type];

            // Clean up previous spawned groups
            DespawnPreviousTroups();

            // Spawn group linked to boss encounter
            instance->SpawnGroupSpawn(*_teamInInstance == ALLIANCE ? spawnGroupInfo.AllianceSpawnGroup : spawnGroupInfo.HordeSpawnGroup);

            // Spawn disease clouds linked to boss encounter
            if (*_teamInInstance == HORDE)
                instance->SpawnGroupSpawn(spawnGroupInfo.DiseaseCloudsSpawnGroup);

            // Spawn dead troups after defeating Lord Walden
            if (type == DATA_LORD_WALDEN)
                instance->SpawnGroupSpawn(*_teamInInstance == ALLIANCE ? SPAWN_GROUP_LORD_GODFREY_DEAD_TROUPS_ALLIANCE : SPAWN_GROUP_LORD_GODFREY_DEAD_TROUPS_HORDE);

            // Special case for Commander Springvale Horde troups
            if (*_teamInInstance == HORDE)
            {
                if ((type == DATA_LORD_WALDEN && GetBossState(DATA_COMMANDER_SPRINGVALE) != DONE)
                    || (type == DATA_COMMANDER_SPRINGVALE && GetBossState(DATA_LORD_WALDEN) != DONE))
                    instance->SpawnGroupSpawn(SPAWN_GROUP_COMMANDER_SPRINGVALE_TROUPS_HORDE);
            }

            return true;
        }

        void SetData(uint32 type, uint32 /*value*/) override
        {
            switch (type)
            {
                case DATA_OUTSIDE_TROUPS_SPAWN:
                    if (*_teamInInstance == ALLIANCE)
                        instance->SpawnGroupSpawn(SPAWN_GROUP_OUTSIDE_TROUPS_ALLIANCE);
                    break;
                case DATA_GODFREY_INTRO_SPAWN:
                    if (*_teamInInstance == ALLIANCE)
                        instance->SpawnGroupDespawn(SPAWN_GROUP_LORD_WALDEN_TROUPS_ALLIANCE);
                    else
                    {
                        instance->SpawnGroupDespawn(SPAWN_GROUP_COMMANDER_SPRINGVALE_TROUPS_HORDE);
                        instance->SpawnGroupDespawn(SPAWN_GROUP_LORD_WALDEN_BELMONT);
                    }

                    instance->SpawnGroupSpawn(*_teamInInstance == ALLIANCE ? SPAWN_GROUP_LORD_GODFREY_IVAR_BLOODFANG : SPAWN_GROUP_LORD_GODFREY_BELMONT);
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

        void DespawnPreviousTroups()
        {
            if (*_teamInInstance == ALLIANCE)
            {
                instance->SpawnGroupDespawn(SPAWN_GROUP_ENTRANCE_ALLIANCE);
                instance->SpawnGroupDespawn(SPAWN_GROUP_BARON_ASHBURY_TROUPS_ALLIANCE);
                instance->SpawnGroupDespawn(SPAWN_GROUP_BARON_SILVERLAINE_TROUPS_ALLIANCE);
                instance->SpawnGroupDespawn(SPAWN_GROUP_COMMANDER_SPRINGVALE_TROUPS_ALLIANCE);
                instance->SpawnGroupDespawn(SPAWN_GROUP_OUTSIDE_TROUPS_ALLIANCE);
            }
            else
            {
                instance->SpawnGroupDespawn(SPAWN_GROUP_ENTRANCE_HORDE);
                instance->SpawnGroupDespawn(SPAWN_GROUP_BARON_ASHBURY_TROUPS_HORDE);
                instance->SpawnGroupDespawn(SPAWN_GROUP_BARON_SILVERLAINE_TROUPS_HORDE);
                instance->SpawnGroupDespawn(SPAWN_GROUP_COMMANDER_SPRINGVALE_BELMONT);

                // Despawn the summoned Cromush version as he is not a part of the spawn groups
                if (Creature* cromush = instance->GetCreature(_cromushGUID))
                    cromush->DespawnOrUnsummon();
            }
        }

        protected:
            EventMap events;
            Optional<uint32>_teamInInstance;
            ObjectGuid _cromushGUID;
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
