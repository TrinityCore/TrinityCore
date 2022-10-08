/*
 * Copyright 2021 FuzionCore Project
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
#include "InstanceScript.h"
#include "VMapFactory.h"
#include "mogu_shan_vault.h"

DoorData const doorData[] =
{
    {GOB_STONE_GUARD_DOOR_ENTRANCE,          DATA_STONE_GUARD,          DOOR_TYPE_ROOM      },
    {GOB_STONE_GUARD_DOOR_EXIT,              DATA_STONE_GUARD,          DOOR_TYPE_PASSAGE   },
    {GOB_FENG_DOOR_FENCE,                    DATA_FENG,                 DOOR_TYPE_ROOM      },
    {GOB_FENG_DOOR_EXIT,                     DATA_FENG,                 DOOR_TYPE_PASSAGE   },
    {GOB_GARAJAL_FENCE,                      DATA_GARAJAL,              DOOR_TYPE_ROOM      },
    {GOB_GARAJAL_EXIT,                       DATA_GARAJAL,              DOOR_TYPE_PASSAGE   },
    {GOB_SPIRIT_KINGS_WIND_WALL,             DATA_SPIRIT_KINGS,         DOOR_TYPE_ROOM      },
    {GOB_SPIRIT_KINGS_EXIT,                  DATA_SPIRIT_KINGS,         DOOR_TYPE_PASSAGE   },
    {GOB_CELESTIAL_DOOR,                     DATA_ELEGON,               DOOR_TYPE_ROOM      },
    {GOB_ELEGON_DOOR_ENTRANCE,               DATA_SPIRIT_KINGS,         DOOR_TYPE_PASSAGE   },
    {GOB_ELEGON_CELESTIAL_DOOR,              DATA_ELEGON,               DOOR_TYPE_ROOM      },
    {GOB_WILL_OF_EMPEROR_ENTRANCE,           DATA_ELEGON,               DOOR_TYPE_PASSAGE   },
};

#define DIST_BETWEEN_TWO_Z      32.39f
#define ACHIEVEMENT_SHOWMOVES   6455

Position woeSpawnPos[8] =
{
    // West
    {3895.44f, 1615.72f, 368.22f, 4.70f},
    {3874.47f, 1615.81f, 368.22f, 4.68f},
    {3851.89f, 1612.51f, 368.22f, 5.03f},
    {3833.06f, 1601.53f, 368.22f, 5.37f},

    // East
    {3833.46f, 1500.18f, 368.22f, 0.87f},
    {3852.07f, 1488.89f, 368.22f, 1.23f},
    {3874.45f, 1485.18f, 368.22f, 1.58f},
    {3895.44f, 1485.12f, 368.22f, 1.60f}
};

Position woeBossSpawnPos[2] =
{
    {3817.58f, 1583.18f, 368.22f, 5.73f},
    {3817.66f, 1517.56f, 368.22f, 0.56f}
};

Position woeRageSpawnPos[3] =
{
    {3812.60f, 1536.72f, 367.64f, 0.16f},
    {3810.98f, 1550.45f, 367.64f, 0.27f},
    {3812.32f, 1563.90f, 367.64f, 6.11f}
};

Position woeMiddleSpawnPos[1] =
{
    {3812.60f, 1536.72f, 367.64f, 0.16f}
};

class instance_mogu_shan_vault : public InstanceMapScript
{
    public:
        instance_mogu_shan_vault() : InstanceMapScript("instance_mogu_shan_vault", 1008) { }

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_mogu_shan_vault_InstanceMapScript(map);
        }

        struct instance_mogu_shan_vault_InstanceMapScript : public InstanceScript
        {
            instance_mogu_shan_vault_InstanceMapScript(InstanceMap* map) : InstanceScript(map) {}

            uint32 actualPetrifierEntry;
            uint8  guardianCount;
            uint8  guardianAliveCount;
            bool   woeIsGasPhaseActive;

            int8   randomDespawnStoneGuardian;
            uint8  nextWillOfEmperorPhase;
            uint8  willOfEmperirLastBigAddSpawned;

            uint32 StoneGuardPetrificationTimer;
            uint32 willOfEmperorTimer;
            uint32 willOfEmperorBossSpawnTimer;
            uint32 willOfEmperorGasPhaseTimer;

            ObjectGuid cursedMogu1Guid;
            ObjectGuid cursedMogu2Guid;
            ObjectGuid ghostEssenceGuid;

            ObjectGuid stoneGuardControlerGuid;
            ObjectGuid fengGuid;
            ObjectGuid siphonShieldGuid;
            ObjectGuid spiritKingsControlerGuid;
            ObjectGuid elegonGuid;
            ObjectGuid infiniteEnergyGuid;

            ObjectGuid inversionGobGuid;
            ObjectGuid stoneGuardExit;
            ObjectGuid cancelGobGuid;
            ObjectGuid ancientMoguDoorGuid;
            ObjectGuid emperorsDoorGuid;
            ObjectGuid celestialCommandGuid;
            ObjectGuid ancientConsoleGuid;

            ObjectGuid energyPlatformGuid;
            ObjectGuid titanDiskGuid;
            ObjectGuid janxiGuid;
            ObjectGuid qinxiGuid;

            std::list<uint32>   m_AuraToClear;

            std::vector<ObjectGuid> stoneGuardGUIDs;
            std::vector<ObjectGuid> fengStatuesGUIDs;
            std::vector<ObjectGuid> spiritKingsGUIDs;
            std::vector<ObjectGuid> titanCirclesGuids;
            std::list<uint32>   achievementGuids;

            void Initialize() override
            {
                SetBossNumber(DATA_MAX_BOSS_DATA);
                LoadDoorData(doorData);

                guardianCount                   = 0;
                guardianAliveCount              = 0;
                woeIsGasPhaseActive             = false;

                randomDespawnStoneGuardian      = urand(1,4);
                nextWillOfEmperorPhase          = 0;
                willOfEmperirLastBigAddSpawned  = 0;

                actualPetrifierEntry            = 0;
                StoneGuardPetrificationTimer    = 10000;
                willOfEmperorTimer              = 0;
                willOfEmperorBossSpawnTimer     = 0;
                willOfEmperorGasPhaseTimer      = 0;

                stoneGuardGUIDs.clear();
                fengStatuesGUIDs.clear();
                spiritKingsGUIDs.clear();
                achievementGuids.clear();

                m_AuraToClear.clear();
                m_AuraToClear.push_back(116541); ///< SPELL_TILES_AURA_EFFECT from stone guard
                m_AuraToClear.push_back(115972); ///< SPELL_INVERSION from Feng
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_STONE_GUARD_CONTROLER:
                        stoneGuardControlerGuid = creature->GetGUID();
                        break;
                    case NPC_JASPER:
                    case NPC_JADE:
                    case NPC_AMETHYST:
                    case NPC_COBALT:
                    {
                        if (creature->IsAlive())
                        {
                            stoneGuardGUIDs.push_back(creature->GetGUID());
                            guardianAliveCount++;
                        }

                        Difficulty difficulty = instance->GetDifficultyID();
                        bool turnOver = (difficulty == DIFFICULTY_10_N || difficulty == DIFFICULTY_10_HC || difficulty == DIFFICULTY_LFR);

                        // In 10N, 10H or LFR, there are only 3 guardians
                        if (guardianAliveCount >= 4 && GetBossState(DATA_STONE_GUARD) != DONE && turnOver)
                        {
                            uint8 choice;
                            Creature* guardian = 0;
                            bool loop = true;
                            do
                            {
                                choice = urand(0, 3);
                                guardian = instance->GetCreature(stoneGuardGUIDs[choice]);
                                // Jasper will always remain for loot purpose
                                if (guardian && guardian->GetEntry() != NPC_JASPER)
                                    loop = false;

                            } while (loop);

                            uint8 i = 0;
                            for (auto itr : stoneGuardGUIDs)
                            {
                                if (i == choice)
                                {
                                    if (Creature* stoneGuard = instance->GetCreature(itr))
                                    {
                                        stoneGuard->DespawnOrUnsummon();
                                        --guardianAliveCount;
                                    }
                                }
                                ++i;
                            }
                        }
                        break;
                    }
                    case NPC_CURSED_MOGU_SCULPTURE_2:
                        if (!cursedMogu1Guid)
                            cursedMogu1Guid = creature->GetGUID();
                        else
                            cursedMogu2Guid = creature->GetGUID();
                        break;
                    case NPC_GHOST_ESSENCE:
                        ghostEssenceGuid = creature->GetGUID();
                        break;
                    case NPC_FENG:
                        fengGuid = creature->GetGUID();
                        break;
                    case NPC_SIPHONING_SHIELD:
                        siphonShieldGuid = creature->GetGUID();
                        break;
                    case NPC_SPIRIT_GUID_CONTROLER:
                        spiritKingsControlerGuid = creature->GetGUID();
                        break;
                    case NPC_ZIAN:
                        // Will be false only if BossState = DONE or NOT_STARTED, as NOT_STARTED = 0, DONE = 0, and max value for BossState = 5
                        if (GetBossState(DATA_SPIRIT_KINGS) % DONE != NOT_STARTED)
                            SetBossState(DATA_SPIRIT_KINGS, NOT_STARTED);
                        // No break here!!!
                    case NPC_MENG:
                    case NPC_QIANG:
                    case NPC_SUBETAI:
                        spiritKingsGUIDs.push_back(creature->GetGUID());
                        break;
                    case NPC_ELEGON:
                        elegonGuid = creature->GetGUID();
                        break;
                    case NPC_INFINITE_ENERGY:
                        infiniteEnergyGuid = creature->GetGUID();
                        break;
                    case NPC_QIN_XI:
                        qinxiGuid = creature->GetGUID();
                        break;
                    case NPC_JAN_XI:
                        janxiGuid = creature->GetGUID();
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
                    case GOB_STONE_GUARD_DOOR_ENTRANCE:
                    case GOB_FENG_DOOR_FENCE:
                    case GOB_FENG_DOOR_EXIT:
                    case GOB_GARAJAL_FENCE:
                    case GOB_GARAJAL_EXIT:
                    case GOB_SPIRIT_KINGS_WIND_WALL:
                    case GOB_SPIRIT_KINGS_EXIT:
                    case GOB_CELESTIAL_DOOR:
                        /// Don't allow players to reach second part if it's in LFR mode
                        if (go->GetEntry() == GOB_GARAJAL_EXIT && instance->IsLFR())
                            break;
                        AddDoor(go, true);
                        break;
                    // Feng
                    case GOB_SPEAR_STATUE:
                    case GOB_FIST_STATUE:
                    case GOB_STAFF_STATUE:
                        fengStatuesGUIDs.push_back(go->GetGUID());
                        break;
                    case GOB_SHIELD_STATUE:
                    {
                        if (!instance->IsHeroic())
                            go->SetObjectScale(0.001f);
                        else
                            fengStatuesGUIDs.push_back(go->GetGUID());
                        break;
                    }
                    case GOB_STONE_GUARD_DOOR_EXIT:
                        AddDoor(go, true);
                        stoneGuardExit = go->GetGUID();
                        break;
                    case GOB_INVERSION:
                        inversionGobGuid = go->GetGUID();
                        break;
                    case GOB_CANCEL:
                        cancelGobGuid = go->GetGUID();
                        break;
                    case GOB_ENERGY_PLATFORM:
                        energyPlatformGuid = go->GetGUID();
                        go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GOB_ELEGON_DOOR_ENTRANCE:
                        AddDoor(go, true);
                        ancientMoguDoorGuid = go->GetGUID();
                        break;
                    case GOB_WILL_OF_EMPEROR_ENTRANCE:
                        AddDoor(go, true);
                        emperorsDoorGuid = go->GetGUID();
                        break;
                    case GOB_ENERGY_TITAN_DISK:
                        titanDiskGuid = go->GetGUID();
                        break;
                    case GOB_ENERGY_TITAN_CIRCLE_1:
                    case GOB_ENERGY_TITAN_CIRCLE_2:
                    case GOB_ENERGY_TITAN_CIRCLE_3:
                        go->SetGoState(GO_STATE_ACTIVE);
                        titanCirclesGuids.push_back(go->GetGUID());
                        break;
                    case GOB_CELESTIAL_COMMAND:
                        celestialCommandGuid = go->GetGUID();
                        break;
                    case GOB_ANCIENT_CONTROL_CONSOLE:
                        ancientConsoleGuid = go->GetGUID();
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                InstanceScript::OnGameObjectRemove(go);

                switch (go->GetEntry())
                {
                    case GOB_STONE_GUARD_DOOR_ENTRANCE:
                    case GOB_FENG_DOOR_FENCE:
                    case GOB_FENG_DOOR_EXIT:
                    case GOB_GARAJAL_FENCE:
                    case GOB_GARAJAL_EXIT:
                    case GOB_SPIRIT_KINGS_WIND_WALL:
                    case GOB_SPIRIT_KINGS_EXIT:
                    case GOB_CELESTIAL_DOOR:
                    case GOB_STONE_GUARD_DOOR_EXIT:
                    case GOB_ELEGON_DOOR_ENTRANCE:
                    case GOB_WILL_OF_EMPEROR_ENTRANCE:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            void OnPlayerExit(Player* player) override
            {
                InstanceScript::OnPlayerExit(player);

                for (const uint32& l_AuraID : m_AuraToClear)
                {
                    if (player->HasAura(l_AuraID))
                        player->RemoveAurasDueToSpell(l_AuraID);
                }
            }

            bool SetBossState(uint32 id, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(id, state))
                    return false;

                switch (id)
                {
                    case DATA_STONE_GUARD:
                    {
                        switch (state)
                        {
                            case IN_PROGRESS:
                                if (Creature* stoneGuardControler = instance->GetCreature(stoneGuardControlerGuid))
                                    stoneGuardControler->AI()->DoAction(ACTION_ENTER_COMBAT);

                                for (auto stoneGuardGuid: stoneGuardGUIDs)
                                    if (Creature* stoneGuard = instance->GetCreature(stoneGuardGuid))
                                        stoneGuard->AI()->DoAction(ACTION_ENTER_COMBAT);
                                break;
                            case FAIL:
                                for (auto stoneGuardGuid: stoneGuardGUIDs)
                                    if (Creature* stoneGuard = instance->GetCreature(stoneGuardGuid))
                                        stoneGuard->AI()->DoAction(ACTION_FAIL);
                                break;
                            case DONE:
                                if (Creature* stoneGuardControler = instance->GetCreature(stoneGuardControlerGuid))
                                    stoneGuardControler->CastSpell(stoneGuardControler, ACHIEVEMENT_STONE_GUARD_KILL, true);
                                break;
                            default:
                                break;
                        }
                        break;
                    }
                    case DATA_SPIRIT_KINGS:
                    {
                        switch (state)
                        {
                            case IN_PROGRESS:
                            {
                                if (Creature* spiritKingsControler = instance->GetCreature(spiritKingsControlerGuid))
                                    spiritKingsControler->AI()->DoAction(ACTION_ENTER_COMBAT);
                                break;
                            }
                            default:
                                break;
                        }
                        break;
                    }
                    case DATA_ELEGON:
                    {
                        switch (state)
                        {
                            case TO_BE_DECIDED:
                            {
                                if (GameObject* titanDisk = instance->GetGameObject(titanDiskGuid))
                                    titanDisk->SetGoState(GO_STATE_ACTIVE);

                                if (GameObject* energyPlatform = instance->GetGameObject(energyPlatformGuid))
                                    energyPlatform->SetGoState(GO_STATE_ACTIVE);

                                for (auto guid: titanCirclesGuids)
                                    if (GameObject* titanCircles = instance->GetGameObject(guid))
                                        titanCircles->SetGoState(GO_STATE_ACTIVE);

                                break;
                            }
                            case FAIL:
                            {
                                if (GameObject* titanDisk = instance->GetGameObject(titanDiskGuid))
                                    titanDisk->SetGoState(GO_STATE_READY);

                                if (GameObject* energyPlatform = instance->GetGameObject(energyPlatformGuid))
                                    energyPlatform->SetGoState(GO_STATE_READY);

                                for (auto guid: titanCirclesGuids)
                                    if (GameObject* titanCircles = instance->GetGameObject(guid))
                                        titanCircles->SetGoState(GO_STATE_READY);

                                break;
                            }
                            default:
                                break;
                        }
                        break;
                    }
                    case DATA_WILL_OF_EMPEROR:
                    {
                        switch (state)
                        {
                            case NOT_STARTED:
                            case FAIL:
                                willOfEmperorTimer              = 0;
                                nextWillOfEmperorPhase          = 0;
                                willOfEmperirLastBigAddSpawned  = 0;
                                willOfEmperorBossSpawnTimer     = 0;
                                willOfEmperorGasPhaseTimer      = 0;
                                woeIsGasPhaseActive             = false;
                                break;
                            case IN_PROGRESS:
                                willOfEmperorTimer              = 10000;
                                nextWillOfEmperorPhase          = 0;
                                willOfEmperirLastBigAddSpawned  = 0;
                                willOfEmperorBossSpawnTimer     = 90000;
                                willOfEmperorGasPhaseTimer      = 210000; // 120 + 90
                                woeIsGasPhaseActive             = false;
                                break;
                            default:
                                break;
                        }
                    }
                    default:
                        break;
                }

                return true;
            }

            void SetData(uint32 type, uint32 data) override
            {
                InstanceScript::SetData(type, data);

                if (type == ACHIEVEMENT_SHOWMOVES)
                    SetAchievementValid(ACHIEVEMENT_SHOWMOVES);

                return;
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == ACHIEVEMENT_SHOWMOVES)
                    return IsAchievementValid(ACHIEVEMENT_SHOWMOVES);

                return InstanceScript::GetData(type);
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    // Creature
                    // Stone Guard
                    case NPC_STONE_GUARD_CONTROLER:
                        return stoneGuardControlerGuid;
                    case NPC_CURSED_MOGU_SCULPTURE_1:
                        return cursedMogu1Guid;
                    case NPC_CURSED_MOGU_SCULPTURE_2:
                        return cursedMogu2Guid;
                    case NPC_GHOST_ESSENCE:
                        return ghostEssenceGuid;
                    case NPC_JASPER:
                    case NPC_JADE:
                    case NPC_AMETHYST:
                    case NPC_COBALT:
                    {
                        for (auto guid: stoneGuardGUIDs)
                            if (Creature* stoneGuard = instance->GetCreature(guid))
                                if (stoneGuard->GetEntry() == type)
                                    return guid;
                        break;
                    }
                    // Feng
                    case NPC_FENG:
                        return fengGuid;
                    // SiphonShield
                    case NPC_SIPHONING_SHIELD:
                        return siphonShieldGuid;
                    // Spirit Kings
                    case NPC_SPIRIT_GUID_CONTROLER:
                        return spiritKingsControlerGuid;
                    case NPC_ZIAN:
                    case NPC_MENG:
                    case NPC_QIANG:
                    case NPC_SUBETAI:
                    {
                        for (auto guid: spiritKingsGUIDs)
                            if (Creature* spiritKing = instance->GetCreature(guid))
                                if (spiritKing->GetEntry() == type)
                                    return guid;
                        break;
                    }
                    // Elegon
                    case NPC_ELEGON:
                        return elegonGuid;
                    case NPC_INFINITE_ENERGY:
                        return infiniteEnergyGuid;
                    // Will of Emperor
                    case NPC_QIN_XI:
                        return qinxiGuid;
                    case NPC_JAN_XI:
                        return janxiGuid;
                    // Gameobject
                    case GOB_SPEAR_STATUE:
                    case GOB_FIST_STATUE:
                    case GOB_SHIELD_STATUE:
                    case GOB_STAFF_STATUE:
                    {
                        for (auto guid: fengStatuesGUIDs)
                            if (GameObject* fengStatue = instance->GetGameObject(guid))
                                if (fengStatue->GetEntry() == type)
                                    return guid;
                        break;
                    }
                    case GOB_STONE_GUARD_DOOR_EXIT:
                        return stoneGuardExit;
                    case GOB_INVERSION:
                        return inversionGobGuid;
                    case GOB_CANCEL:
                        return cancelGobGuid;
                    case GOB_ENERGY_PLATFORM:
                        return energyPlatformGuid;
                    case GOB_ENERGY_TITAN_DISK:
                        return titanDiskGuid;
                    case GOB_ELEGON_DOOR_ENTRANCE:
                        return ancientMoguDoorGuid;
                    case GOB_WILL_OF_EMPEROR_ENTRANCE:
                        return emperorsDoorGuid;
                    case GOB_CELESTIAL_COMMAND:
                        return celestialCommandGuid;
                    case GOB_ANCIENT_CONTROL_CONSOLE:
                        return ancientConsoleGuid;
                    default:
                        break;
                }

                return InstanceScript::GetGuidData(type);
            }

            /*bool IsWipe()
            {
                Map::PlayerList const& PlayerList = instance->GetPlayers();

                if (PlayerList.isEmpty())
                    return true;

                for (Map::PlayerList::const_iterator Itr = PlayerList.begin(); Itr != PlayerList.end(); ++Itr)
                {
                    Player* player = Itr->GetSource();

                    if (!player)
                        continue;

                    if (player->IsAlive() && !player->IsGameMaster() && !player->HasAura(115877)) // Aura 115877 = Totaly Petrified
                        return false;
                }

                return true;
            }*/

            void Update(uint32 diff) override
            {
                InstanceScript::Update(diff);

                UpdateOperations(diff);

                if (GetBossState(DATA_WILL_OF_EMPEROR) != IN_PROGRESS)
                    return;

                if (willOfEmperorTimer && !woeIsGasPhaseActive)
                {
                    if (willOfEmperorTimer <= diff)
                    {
                        switch (nextWillOfEmperorPhase)
                        {
                            case PHASE_WOE_RAGE:
                            {
                                uint8 randomPos = urand(0, 2);
                                uint8 randomPos2 = urand(0, 2);

                                while (randomPos2 == randomPos)
                                    randomPos2 = urand(0, 2);

                                instance->SummonCreature(NPC_EMPEROR_RAGE, woeRageSpawnPos[randomPos]);
                                instance->SummonCreature(NPC_EMPEROR_RAGE, woeRageSpawnPos[randomPos2]);

                                if (willOfEmperirLastBigAddSpawned == PHASE_WOE_STRENGHT)
                                {
                                    nextWillOfEmperorPhase = PHASE_WOE_COURAGE;
                                    willOfEmperorTimer = 20000;
                                }
                                else
                                {
                                    nextWillOfEmperorPhase = PHASE_WOE_STRENGHT;
                                    willOfEmperorTimer = 15000;
                                }
                                break;
                            }
                            case PHASE_WOE_STRENGHT:
                            {
                                instance->SummonCreature(NPC_EMPEROR_STRENGHT, woeSpawnPos[urand(0, 7)]);

                                nextWillOfEmperorPhase = PHASE_WOE_RAGE;
                                willOfEmperirLastBigAddSpawned = PHASE_WOE_STRENGHT;
                                willOfEmperorTimer = 15000;
                                break;
                            }
                            case PHASE_WOE_COURAGE:
                            {
                                instance->SummonCreature(NPC_EMPEROR_COURAGE, woeSpawnPos[urand(0, 7)]);

                                nextWillOfEmperorPhase = PHASE_WOE_RAGE;
                                willOfEmperirLastBigAddSpawned = PHASE_WOE_COURAGE;
                                willOfEmperorTimer = 10000;
                                break;
                            }
                        }
                    }
                    else
                        willOfEmperorTimer -= diff;
                }

                if (willOfEmperorBossSpawnTimer)
                {
                    if (willOfEmperorBossSpawnTimer <= diff)
                    {
                        instance->SummonCreature(NPC_JAN_XI, woeBossSpawnPos[0]);
                        instance->SummonCreature(NPC_QIN_XI, woeBossSpawnPos[1]);
                        willOfEmperorBossSpawnTimer = 0;
                    }
                    else
                        willOfEmperorBossSpawnTimer -= diff;
                }

                if (willOfEmperorGasPhaseTimer)
                {
                    if (willOfEmperorGasPhaseTimer <= diff)
                    {
                        if (!woeIsGasPhaseActive)
                        {
                            if (Creature* trigger = instance->SummonCreature(59481, woeMiddleSpawnPos[0], NULL, 30000))
                                trigger->CastSpell(trigger, 118320, false);
                            willOfEmperorGasPhaseTimer = 30000;
                            woeIsGasPhaseActive = true;
                        }
                        else
                        {
                            willOfEmperorGasPhaseTimer = 120000;
                            woeIsGasPhaseActive = false;
                        }
                    }
                    else
                        willOfEmperorGasPhaseTimer -= diff;
                }
            }

            bool CheckRequiredBosses(uint32 bossId, Player const* player = nullptr) const override
            {
                if (!InstanceScript::CheckRequiredBosses(bossId, player))
                    return false;

                switch (bossId)
                {
                    case DATA_WILL_OF_EMPEROR:
                    case DATA_ELEGON:
                    case DATA_SPIRIT_KINGS:
                    case DATA_GARAJAL:
                    case DATA_FENG:
                        if (GetBossState(bossId - 1) != DONE)
                            return false;
                    default:
                        break;
                }

                return true;
            }

            bool IsAchievementValid(uint32 id) const
            {
                if (achievementGuids.empty())
                    return false;

                for (std::list<uint32>::const_iterator iter = achievementGuids.begin(); iter != achievementGuids.end(); ++iter)
                    if ((*iter) == id)
                        return true;

                return false;
            }

            void SetAchievementValid(uint32 id)
            {
                for (std::list<uint32>::const_iterator iter = achievementGuids.begin(); iter != achievementGuids.end(); ++iter)
                    if ((*iter) == id)
                        return;

                achievementGuids.push_back(id);
                return;
            }
        };
};

void AddSC_instance_mogu_shan_vault()
{
    new instance_mogu_shan_vault();
}
