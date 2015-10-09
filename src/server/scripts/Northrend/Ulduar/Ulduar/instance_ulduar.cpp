/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "InstanceScript.h"
#include "Vehicle.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "WorldPacket.h"
#include "ulduar.h"

static DoorData const doorData[] =
{
    { GO_LEVIATHAN_DOOR,                BOSS_LEVIATHAN,         DOOR_TYPE_ROOM,         BOUNDARY_S      },
    { GO_XT_002_DOOR,                   BOSS_XT002,             DOOR_TYPE_ROOM,         BOUNDARY_S      },
    { GO_IRON_COUNCIL_DOOR,             BOSS_ASSEMBLY_OF_IRON,  DOOR_TYPE_ROOM,         BOUNDARY_N      },
    { GO_ARCHIVUM_DOOR,                 BOSS_ASSEMBLY_OF_IRON,  DOOR_TYPE_PASSAGE,      BOUNDARY_S      },
    { GO_HODIR_ENTRANCE,                BOSS_HODIR,             DOOR_TYPE_ROOM,         BOUNDARY_E      },
    { GO_HODIR_DOOR,                    BOSS_HODIR,             DOOR_TYPE_PASSAGE,      BOUNDARY_NONE   },
    { GO_HODIR_ICE_DOOR,                BOSS_HODIR,             DOOR_TYPE_PASSAGE,      BOUNDARY_W      },
    { GO_MIMIRON_DOOR_1,                BOSS_MIMIRON,           DOOR_TYPE_ROOM,         BOUNDARY_W      },
    { GO_MIMIRON_DOOR_2,                BOSS_MIMIRON,           DOOR_TYPE_ROOM,         BOUNDARY_E      },
    { GO_MIMIRON_DOOR_3,                BOSS_MIMIRON,           DOOR_TYPE_ROOM,         BOUNDARY_S      },
    { GO_VEZAX_DOOR,                    BOSS_VEZAX,             DOOR_TYPE_PASSAGE,      BOUNDARY_E      },
    { GO_YOGG_SARON_DOOR,               BOSS_YOGG_SARON,        DOOR_TYPE_ROOM,         BOUNDARY_S      },
    { GO_DOODAD_UL_SIGILDOOR_03,        BOSS_ALGALON,           DOOR_TYPE_ROOM,         BOUNDARY_W      },
    { GO_DOODAD_UL_UNIVERSEFLOOR_01,    BOSS_ALGALON,           DOOR_TYPE_ROOM,         BOUNDARY_NONE   },
    { GO_DOODAD_UL_UNIVERSEFLOOR_02,    BOSS_ALGALON,           DOOR_TYPE_SPAWN_HOLE,   BOUNDARY_NONE   },
    { GO_DOODAD_UL_UNIVERSEGLOBE01,     BOSS_ALGALON,           DOOR_TYPE_SPAWN_HOLE,   BOUNDARY_NONE   },
    { GO_DOODAD_UL_ULDUAR_TRAPDOOR_03,  BOSS_ALGALON,           DOOR_TYPE_SPAWN_HOLE,   BOUNDARY_NONE   },
    { 0,                                0,                      DOOR_TYPE_ROOM,         BOUNDARY_NONE   },
};

MinionData const minionData[] =
{
    { NPC_STEELBREAKER,   BOSS_ASSEMBLY_OF_IRON },
    { NPC_MOLGEIM,        BOSS_ASSEMBLY_OF_IRON },
    { NPC_BRUNDIR,        BOSS_ASSEMBLY_OF_IRON },
    { 0,                  0,                    }
};

ObjectData const creatureData[] =
{
    { NPC_BRANN_BRONZEBEARD_INTRO,  DATA_BRANN_BRONZEBEARD_INTRO  },
    { NPC_LORE_KEEPER_OF_NORGANNON, DATA_LORE_KEEPER_OF_NORGANNON },
    { NPC_HIGH_EXPLORER_DELLORAH,   DATA_DELLORAH                 },
    { NPC_BRONZEBEARD_RADIO,        DATA_BRONZEBEARD_RADIO        },
    { 0,                            0,                            }
};

class instance_ulduar : public InstanceMapScript
{
    public:
        instance_ulduar() : InstanceMapScript(UlduarScriptName, 603) { }

        struct instance_ulduar_InstanceMapScript : public InstanceScript
        {
            instance_ulduar_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(MAX_ENCOUNTER);

                LoadDoorData(doorData);
                LoadMinionData(minionData);
                LoadObjectData(creatureData, nullptr);

                _algalonTimer = 61;
                _maxArmorItemLevel = 0;
                _maxWeaponItemLevel = 0;
                TeamInInstance = 0;
                HodirRareCacheData = 0;
                ColossusData = 0;
                elderCount = 0;
                illusion = 0;
                keepersCount = 0;
                conSpeedAtory = false;
                lumberjacked = false;
                Unbroken = true;
                IsDriveMeCrazyEligible = true;
                _algalonSummoned = false;
                _summonAlgalon = false;
                _CoUAchivePlayerDeathMask = 0;

                memset(_summonObservationRingKeeper, 0, sizeof(_summonObservationRingKeeper));
                memset(_summonYSKeeper, 0, sizeof(_summonYSKeeper));
            }

            // Creatures
            ObjectGuid LeviathanGUID;
            GuidVector LeviathanVehicleGUIDs;
            ObjectGuid IgnisGUID;
            ObjectGuid RazorscaleGUID;
            ObjectGuid RazorscaleController;
            ObjectGuid ExpeditionCommanderGUID;
            ObjectGuid XT002GUID;
            ObjectGuid XTToyPileGUIDs[4];
            ObjectGuid AssemblyGUIDs[3];
            ObjectGuid KologarnGUID;
            ObjectGuid AuriayaGUID;
            ObjectGuid HodirGUID;
            ObjectGuid ThorimGUID;
            ObjectGuid FreyaGUID;
            ObjectGuid ElderGUIDs[3];
            ObjectGuid FreyaAchieveTriggerGUID;
            ObjectGuid MimironGUID;
            ObjectGuid MimironVehicleGUIDs[3];
            ObjectGuid MimironComputerGUID;
            ObjectGuid MimironWorldTriggerGUID;
            ObjectGuid VezaxGUID;
            ObjectGuid YoggSaronGUID;
            ObjectGuid VoiceOfYoggSaronGUID;
            ObjectGuid SaraGUID;
            ObjectGuid BrainOfYoggSaronGUID;
            ObjectGuid KeeperGUIDs[4];
            ObjectGuid AlgalonGUID;
            ObjectGuid BrannBronzebeardAlgGUID;

            // GameObjects
            ObjectGuid LeviathanGateGUID;
            ObjectGuid RazorHarpoonGUIDs[4];
            ObjectGuid KologarnChestGUID;
            ObjectGuid KologarnBridgeGUID;
            ObjectGuid ThorimChestGUID;
            ObjectGuid HodirRareCacheGUID;
            ObjectGuid HodirChestGUID;
            ObjectGuid MimironTramGUID;
            ObjectGuid MimironElevatorGUID;
            ObjectGuid MimironButtonGUID;
            ObjectGuid BrainRoomDoorGUIDs[3];
            ObjectGuid AlgalonSigilDoorGUID[3];
            ObjectGuid AlgalonFloorGUID[2];
            ObjectGuid AlgalonUniverseGUID;
            ObjectGuid AlgalonTrapdoorGUID;
            ObjectGuid GiftOfTheObserverGUID;

            // Miscellaneous
            uint32 TeamInInstance;
            uint32 HodirRareCacheData;
            uint32 ColossusData;
            uint8 elderCount;
            uint8 illusion;
            uint8 keepersCount;
            bool conSpeedAtory;
            bool lumberjacked;
            bool Unbroken;
            bool IsDriveMeCrazyEligible;

            void FillInitialWorldStates(WorldPacket& packet) override
            {
                packet << uint32(WORLD_STATE_ALGALON_TIMER_ENABLED) << uint32(_algalonTimer && _algalonTimer <= 60);
                packet << uint32(WORLD_STATE_ALGALON_DESPAWN_TIMER) << uint32(std::min<uint32>(_algalonTimer, 60));
            }

            void OnPlayerEnter(Player* player) override
            {
                if (!TeamInInstance)
                    TeamInInstance = player->GetTeam();

                if (_summonAlgalon)
                {
                    _summonAlgalon = false;
                    TempSummon* algalon = instance->SummonCreature(NPC_ALGALON, AlgalonLandPos);
                    if (_algalonTimer && _algalonTimer <= 60)
                        algalon->AI()->DoAction(ACTION_INIT_ALGALON);
                    else
                        algalon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                }

                // Keepers at Observation Ring
                if (GetBossState(BOSS_FREYA) == DONE && _summonObservationRingKeeper[0] && !KeeperGUIDs[0])
                {
                    _summonObservationRingKeeper[0] = false;
                    instance->SummonCreature(NPC_FREYA_OBSERVATION_RING, ObservationRingKeepersPos[0]);
                }
                if (GetBossState(BOSS_HODIR) == DONE && _summonObservationRingKeeper[1] && !KeeperGUIDs[1])
                {
                    _summonObservationRingKeeper[1] = false;
                    instance->SummonCreature(NPC_HODIR_OBSERVATION_RING, ObservationRingKeepersPos[1]);
                }
                if (GetBossState(BOSS_THORIM) == DONE && _summonObservationRingKeeper[2] && !KeeperGUIDs[2])
                {
                    _summonObservationRingKeeper[2] = false;
                    instance->SummonCreature(NPC_THORIM_OBSERVATION_RING, ObservationRingKeepersPos[2]);
                }
                if (GetBossState(BOSS_MIMIRON) == DONE && _summonObservationRingKeeper[3] && !KeeperGUIDs[3])
                {
                    _summonObservationRingKeeper[3] = false;
                    instance->SummonCreature(NPC_MIMIRON_OBSERVATION_RING, ObservationRingKeepersPos[3]);
                }

                // Keepers in Yogg-Saron's room
                if (_summonYSKeeper[0])
                    instance->SummonCreature(NPC_FREYA_YS, YSKeepersPos[0]);
                if (_summonYSKeeper[1])
                    instance->SummonCreature(NPC_HODIR_YS, YSKeepersPos[1]);
                if (_summonYSKeeper[2])
                    instance->SummonCreature(NPC_THORIM_YS, YSKeepersPos[2]);
                if (_summonYSKeeper[3])
                    instance->SummonCreature(NPC_MIMIRON_YS, YSKeepersPos[3]);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                if (!TeamInInstance)
                {
                    Map::PlayerList const& Players = instance->GetPlayers();
                    if (!Players.isEmpty())
                        if (Player* player = Players.begin()->GetSource())
                            TeamInInstance = player->GetTeam();
                }

                switch (creature->GetEntry())
                {
                    case NPC_LEVIATHAN:
                        LeviathanGUID = creature->GetGUID();
                        break;
                    case NPC_SALVAGED_DEMOLISHER:
                    case NPC_SALVAGED_SIEGE_ENGINE:
                    case NPC_SALVAGED_CHOPPER:
                        LeviathanVehicleGUIDs.push_back(creature->GetGUID());
                        break;
                    case NPC_IGNIS:
                        IgnisGUID = creature->GetGUID();
                        break;

                    // Razorscale
                    case NPC_RAZORSCALE:
                        RazorscaleGUID = creature->GetGUID();
                        break;
                    case NPC_RAZORSCALE_CONTROLLER:
                        RazorscaleController = creature->GetGUID();
                        break;
                    case NPC_EXPEDITION_COMMANDER:
                        ExpeditionCommanderGUID = creature->GetGUID();
                        break;

                    // XT-002 Deconstructor
                    case NPC_XT002:
                        XT002GUID = creature->GetGUID();
                        break;
                    case NPC_XT_TOY_PILE:
                        for (uint8 i = 0; i < 4; ++i)
                            if (!XTToyPileGUIDs[i])
                            {
                                XTToyPileGUIDs[i] = creature->GetGUID();
                                break;
                            }
                        break;

                    // Assembly of Iron
                    case NPC_STEELBREAKER:
                        AssemblyGUIDs[0] = creature->GetGUID();
                        AddMinion(creature, true);
                        break;
                    case NPC_MOLGEIM:
                        AssemblyGUIDs[1] = creature->GetGUID();
                        AddMinion(creature, true);
                        break;
                    case NPC_BRUNDIR:
                        AssemblyGUIDs[2] = creature->GetGUID();
                        AddMinion(creature, true);
                        break;

                    case NPC_KOLOGARN:
                        KologarnGUID = creature->GetGUID();
                        break;
                    case NPC_AURIAYA:
                        AuriayaGUID = creature->GetGUID();
                        break;

                    // Hodir
                    case NPC_HODIR:
                        HodirGUID = creature->GetGUID();
                        break;
                    case NPC_EIVI_NIGHTFEATHER:
                        if (TeamInInstance == HORDE)
                            creature->UpdateEntry(NPC_TOR_GREYCLOUD);
                        break;
                    case NPC_ELLIE_NIGHTFEATHER:
                        if (TeamInInstance == HORDE)
                            creature->UpdateEntry(NPC_KAR_GREYCLOUD);
                        break;
                    case NPC_ELEMENTALIST_MAHFUUN:
                        if (TeamInInstance == HORDE)
                            creature->UpdateEntry(NPC_SPIRITWALKER_TARA);
                        break;
                    case NPC_ELEMENTALIST_AVUUN:
                        if (TeamInInstance == HORDE)
                            creature->UpdateEntry(NPC_SPIRITWALKER_YONA);
                        break;
                    case NPC_MISSY_FLAMECUFFS:
                        if (TeamInInstance == HORDE)
                            creature->UpdateEntry(NPC_AMIRA_BLAZEWEAVER);
                        break;
                    case NPC_SISSY_FLAMECUFFS:
                        if (TeamInInstance == HORDE)
                            creature->UpdateEntry(NPC_VEESHA_BLAZEWEAVER);
                        break;
                    case NPC_FIELD_MEDIC_PENNY:
                        if (TeamInInstance == HORDE)
                            creature->UpdateEntry(NPC_BATTLE_PRIEST_ELIZA);
                        break;
                    case NPC_FIELD_MEDIC_JESSI:
                        if (TeamInInstance == HORDE)
                            creature->UpdateEntry(NPC_BATTLE_PRIEST_GINA);
                        break;

                    case NPC_THORIM:
                        ThorimGUID = creature->GetGUID();
                        break;

                    // Freya
                    case NPC_FREYA:
                        FreyaGUID = creature->GetGUID();
                        break;
                    case NPC_IRONBRANCH:
                        ElderGUIDs[0] = creature->GetGUID();
                        if (GetBossState(BOSS_FREYA) == DONE)
                            creature->DespawnOrUnsummon();
                        break;
                    case NPC_BRIGHTLEAF:
                        ElderGUIDs[1] = creature->GetGUID();
                        if (GetBossState(BOSS_FREYA) == DONE)
                            creature->DespawnOrUnsummon();
                        break;
                    case NPC_STONEBARK:
                        ElderGUIDs[2] = creature->GetGUID();
                        if (GetBossState(BOSS_FREYA) == DONE)
                            creature->DespawnOrUnsummon();
                        break;
                    case NPC_FREYA_ACHIEVE_TRIGGER:
                        FreyaAchieveTriggerGUID = creature->GetGUID();
                        break;

                    // Mimiron
                    case NPC_MIMIRON:
                        MimironGUID = creature->GetGUID();
                        break;
                    case NPC_LEVIATHAN_MKII:
                        MimironVehicleGUIDs[0] = creature->GetGUID();
                        break;
                    case NPC_VX_001:
                        MimironVehicleGUIDs[1] = creature->GetGUID();
                        break;
                    case NPC_AERIAL_COMMAND_UNIT:
                        MimironVehicleGUIDs[2] = creature->GetGUID();
                        break;
                    case NPC_COMPUTER:
                        MimironComputerGUID = creature->GetGUID();
                        break;
                    case NPC_WORLD_TRIGGER_MIMIRON:
                        MimironWorldTriggerGUID = creature->GetGUID();
                        break;

                    case NPC_VEZAX:
                        VezaxGUID = creature->GetGUID();
                        break;

                    // Yogg-Saron
                    case NPC_YOGG_SARON:
                        YoggSaronGUID = creature->GetGUID();
                        break;
                    case NPC_VOICE_OF_YOGG_SARON:
                        VoiceOfYoggSaronGUID = creature->GetGUID();
                        break;
                    case NPC_BRAIN_OF_YOGG_SARON:
                        BrainOfYoggSaronGUID = creature->GetGUID();
                        break;
                    case NPC_SARA:
                        SaraGUID = creature->GetGUID();
                        break;
                    case NPC_FREYA_YS:
                        KeeperGUIDs[0] = creature->GetGUID();
                        _summonYSKeeper[0] = false;
                        SaveToDB();
                        ++keepersCount;
                        break;
                    case NPC_HODIR_YS:
                        KeeperGUIDs[1] = creature->GetGUID();
                        _summonYSKeeper[1] = false;
                        SaveToDB();
                        ++keepersCount;
                        break;
                    case NPC_THORIM_YS:
                        KeeperGUIDs[2] = creature->GetGUID();
                        _summonYSKeeper[2] = false;
                        SaveToDB();
                        ++keepersCount;
                        break;
                    case NPC_MIMIRON_YS:
                        KeeperGUIDs[3] = creature->GetGUID();
                        _summonYSKeeper[3] = false;
                        SaveToDB();
                        ++keepersCount;
                        break;
                    case NPC_SANITY_WELL:
                        creature->SetReactState(REACT_PASSIVE);
                        break;

                    // Algalon
                    case NPC_ALGALON:
                        AlgalonGUID = creature->GetGUID();
                        break;
                    case NPC_BRANN_BRONZBEARD_ALG:
                        BrannBronzebeardAlgGUID = creature->GetGUID();
                        break;
                    //! These creatures are summoned by something else than Algalon
                    //! but need to be controlled/despawned by him - so they need to be
                    //! registered in his summon list
                    case NPC_ALGALON_VOID_ZONE_VISUAL_STALKER:
                    case NPC_ALGALON_STALKER_ASTEROID_TARGET_01:
                    case NPC_ALGALON_STALKER_ASTEROID_TARGET_02:
                    case NPC_UNLEASHED_DARK_MATTER:
                        if (Creature* algalon = instance->GetCreature(AlgalonGUID))
                            algalon->AI()->JustSummoned(creature);
                        break;
                }

                InstanceScript::OnCreatureCreate(creature);
            }

            void OnCreatureRemove(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_XT_TOY_PILE:
                        for (uint8 i = 0; i < 4; ++i)
                            if (XTToyPileGUIDs[i] == creature->GetGUID())
                            {
                                XTToyPileGUIDs[i].Clear();
                                break;
                            }
                        break;
                    case NPC_STEELBREAKER:
                    case NPC_MOLGEIM:
                    case NPC_BRUNDIR:
                        AddMinion(creature, false);
                        break;
                    case NPC_BRANN_BRONZBEARD_ALG:
                        if (BrannBronzebeardAlgGUID == creature->GetGUID())
                            BrannBronzebeardAlgGUID.Clear();
                        break;
                    default:
                        break;
                }

                InstanceScript::OnCreatureRemove(creature);
            }

            void OnGameObjectCreate(GameObject* gameObject) override
            {
                switch (gameObject->GetEntry())
                {
                    case GO_KOLOGARN_CHEST_HERO:
                    case GO_KOLOGARN_CHEST:
                        KologarnChestGUID = gameObject->GetGUID();
                        break;
                    case GO_KOLOGARN_BRIDGE:
                        KologarnBridgeGUID = gameObject->GetGUID();
                        if (GetBossState(BOSS_KOLOGARN) == DONE)
                            HandleGameObject(ObjectGuid::Empty, false, gameObject);
                        break;
                    case GO_THORIM_CHEST_HERO:
                    case GO_THORIM_CHEST:
                        ThorimChestGUID = gameObject->GetGUID();
                        break;
                    case GO_HODIR_RARE_CACHE_OF_WINTER_HERO:
                    case GO_HODIR_RARE_CACHE_OF_WINTER:
                        HodirRareCacheGUID = gameObject->GetGUID();
                        break;
                    case GO_HODIR_CHEST_HERO:
                    case GO_HODIR_CHEST:
                        HodirChestGUID = gameObject->GetGUID();
                        break;
                    case GO_MIMIRON_TRAM:
                        MimironTramGUID = gameObject->GetGUID();
                        break;
                    case GO_MIMIRON_ELEVATOR:
                        MimironElevatorGUID = gameObject->GetGUID();
                        break;
                    case GO_MIMIRON_BUTTON:
                        MimironButtonGUID = gameObject->GetGUID();
                        break;
                    case GO_LEVIATHAN_GATE:
                        LeviathanGateGUID = gameObject->GetGUID();
                        if (GetBossState(BOSS_LEVIATHAN) == DONE)
                            gameObject->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                        break;
                    case GO_LEVIATHAN_DOOR:
                    case GO_XT_002_DOOR:
                    case GO_IRON_COUNCIL_DOOR:
                    case GO_ARCHIVUM_DOOR:
                    case GO_HODIR_ENTRANCE:
                    case GO_HODIR_DOOR:
                    case GO_HODIR_ICE_DOOR:
                    case GO_MIMIRON_DOOR_1:
                    case GO_MIMIRON_DOOR_2:
                    case GO_MIMIRON_DOOR_3:
                    case GO_VEZAX_DOOR:
                    case GO_YOGG_SARON_DOOR:
                        AddDoor(gameObject, true);
                        break;
                    case GO_RAZOR_HARPOON_1:
                        RazorHarpoonGUIDs[0] = gameObject->GetGUID();
                        break;
                    case GO_RAZOR_HARPOON_2:
                        RazorHarpoonGUIDs[1] = gameObject->GetGUID();
                        break;
                    case GO_RAZOR_HARPOON_3:
                        RazorHarpoonGUIDs[2] = gameObject->GetGUID();
                        break;
                    case GO_RAZOR_HARPOON_4:
                        RazorHarpoonGUIDs[3] = gameObject->GetGUID();
                        break;
                    case GO_MOLE_MACHINE:
                        if (GetBossState(BOSS_RAZORSCALE) == IN_PROGRESS)
                            gameObject->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GO_BRAIN_ROOM_DOOR_1:
                        BrainRoomDoorGUIDs[0] = gameObject->GetGUID();
                        break;
                    case GO_BRAIN_ROOM_DOOR_2:
                        BrainRoomDoorGUIDs[1] = gameObject->GetGUID();
                        break;
                    case GO_BRAIN_ROOM_DOOR_3:
                        BrainRoomDoorGUIDs[2] = gameObject->GetGUID();
                        break;
                    case GO_CELESTIAL_PLANETARIUM_ACCESS_10:
                    case GO_CELESTIAL_PLANETARIUM_ACCESS_25:
                        if (_algalonSummoned)
                            gameObject->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                        break;
                    case GO_DOODAD_UL_SIGILDOOR_01:
                        AlgalonSigilDoorGUID[0] = gameObject->GetGUID();
                        if (_algalonSummoned)
                            gameObject->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GO_DOODAD_UL_SIGILDOOR_02:
                        AlgalonSigilDoorGUID[1] = gameObject->GetGUID();
                        if (_algalonSummoned)
                            gameObject->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GO_DOODAD_UL_SIGILDOOR_03:
                        AlgalonSigilDoorGUID[2] = gameObject->GetGUID();
                        AddDoor(gameObject, true);
                        break;
                    case GO_DOODAD_UL_UNIVERSEFLOOR_01:
                        AlgalonFloorGUID[0] = gameObject->GetGUID();
                        AddDoor(gameObject, true);
                        break;
                    case GO_DOODAD_UL_UNIVERSEFLOOR_02:
                        AlgalonFloorGUID[1] = gameObject->GetGUID();
                        AddDoor(gameObject, true);
                        break;
                    case GO_DOODAD_UL_UNIVERSEGLOBE01:
                        AlgalonUniverseGUID = gameObject->GetGUID();
                        AddDoor(gameObject, true);
                        break;
                    case GO_DOODAD_UL_ULDUAR_TRAPDOOR_03:
                        AlgalonTrapdoorGUID = gameObject->GetGUID();
                        AddDoor(gameObject, true);
                        break;
                    case GO_GIFT_OF_THE_OBSERVER_10:
                    case GO_GIFT_OF_THE_OBSERVER_25:
                        GiftOfTheObserverGUID = gameObject->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* gameObject) override
            {
                switch (gameObject->GetEntry())
                {
                    case GO_LEVIATHAN_DOOR:
                    case GO_XT_002_DOOR:
                    case GO_IRON_COUNCIL_DOOR:
                    case GO_ARCHIVUM_DOOR:
                    case GO_HODIR_ENTRANCE:
                    case GO_HODIR_DOOR:
                    case GO_HODIR_ICE_DOOR:
                    case GO_MIMIRON_DOOR_1:
                    case GO_MIMIRON_DOOR_2:
                    case GO_MIMIRON_DOOR_3:
                    case GO_VEZAX_DOOR:
                    case GO_YOGG_SARON_DOOR:
                    case GO_DOODAD_UL_SIGILDOOR_03:
                    case GO_DOODAD_UL_UNIVERSEFLOOR_01:
                    case GO_DOODAD_UL_UNIVERSEFLOOR_02:
                    case GO_DOODAD_UL_UNIVERSEGLOBE01:
                    case GO_DOODAD_UL_ULDUAR_TRAPDOOR_03:
                        AddDoor(gameObject, false);
                        break;
                    default:
                        break;
                }
            }

            void OnUnitDeath(Unit* unit) override
            {
                // Champion/Conqueror of Ulduar
                if (unit->GetTypeId() == TYPEID_PLAYER)
                {
                    for (uint8 i = 0; i < BOSS_ALGALON; i++)
                    {
                        if (GetBossState(i) == IN_PROGRESS)
                        {
                            _CoUAchivePlayerDeathMask |= (1 << i);
                            SaveToDB();
                        }
                    }
                }

                Creature* creature = unit->ToCreature();
                if (!creature)
                    return;

                switch (creature->GetEntry())
                {
                    case NPC_CORRUPTED_SERVITOR:
                    case NPC_MISGUIDED_NYMPH:
                    case NPC_GUARDIAN_LASHER:
                    case NPC_FOREST_SWARMER:
                    case NPC_MANGROVE_ENT:
                    case NPC_IRONROOT_LASHER:
                    case NPC_NATURES_BLADE:
                    case NPC_GUARDIAN_OF_LIFE:
                        if (!conSpeedAtory)
                        {
                            DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, CRITERIA_CON_SPEED_ATORY);
                            conSpeedAtory = true;
                        }
                        break;
                    case NPC_IRONBRANCH:
                    case NPC_STONEBARK:
                    case NPC_BRIGHTLEAF:
                        if (!lumberjacked)
                        {
                            DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, CRITERIA_LUMBERJACKED);
                            lumberjacked = true;
                        }
                        break;
                    default:
                        break;
                }
            }

            void ProcessEvent(WorldObject* /*gameObject*/, uint32 eventId) override
            {
                // Flame Leviathan's Tower Event triggers
                Creature* FlameLeviathan = instance->GetCreature(LeviathanGUID);

                switch (eventId)
                {
                    case EVENT_TOWER_OF_STORM_DESTROYED:
                        if (FlameLeviathan && FlameLeviathan->IsAlive())
                            FlameLeviathan->AI()->DoAction(ACTION_TOWER_OF_STORM_DESTROYED);
                        break;
                    case EVENT_TOWER_OF_FROST_DESTROYED:
                        if (FlameLeviathan && FlameLeviathan->IsAlive())
                            FlameLeviathan->AI()->DoAction(ACTION_TOWER_OF_FROST_DESTROYED);
                        break;
                    case EVENT_TOWER_OF_FLAMES_DESTROYED:
                        if (FlameLeviathan && FlameLeviathan->IsAlive())
                            FlameLeviathan->AI()->DoAction(ACTION_TOWER_OF_FLAMES_DESTROYED);
                        break;
                    case EVENT_TOWER_OF_LIFE_DESTROYED:
                        if (FlameLeviathan && FlameLeviathan->IsAlive())
                            FlameLeviathan->AI()->DoAction(ACTION_TOWER_OF_LIFE_DESTROYED);
                        break;
                    case EVENT_ACTIVATE_SANITY_WELL:
                        if (Creature* freya = instance->GetCreature(KeeperGUIDs[0]))
                            freya->AI()->DoAction(4/*ACTION_SANITY_WELLS*/);
                        break;
                    case EVENT_HODIRS_PROTECTIVE_GAZE_PROC:
                        if (Creature* hodir = instance->GetCreature(KeeperGUIDs[1]))
                            hodir->AI()->DoAction(5/*ACTION_FLASH_FREEZE*/);
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case BOSS_LEVIATHAN:
                        if (state == DONE)
                            _events.ScheduleEvent(EVENT_DESPAWN_LEVIATHAN_VEHICLES, 5 * IN_MILLISECONDS);
                        break;
                    case BOSS_IGNIS:
                    case BOSS_RAZORSCALE:
                    case BOSS_XT002:
                    case BOSS_ASSEMBLY_OF_IRON:
                    case BOSS_AURIAYA:
                    case BOSS_VEZAX:
                    case BOSS_YOGG_SARON:
                        break;
                    case BOSS_MIMIRON:
                        if (state == DONE)
                            instance->SummonCreature(NPC_MIMIRON_OBSERVATION_RING, ObservationRingKeepersPos[3]);
                        break;
                    case BOSS_FREYA:
                        if (state == DONE)
                            instance->SummonCreature(NPC_FREYA_OBSERVATION_RING, ObservationRingKeepersPos[0]);
                        break;
                    case BOSS_IRONBRANCH:
                    case BOSS_STONEBARK:
                    case BOSS_BRIGHTLEAF:
                        if (GetBossState(BOSS_BRIGHTLEAF) == DONE && GetBossState(BOSS_IRONBRANCH) == DONE && GetBossState(BOSS_STONEBARK) == DONE && GetBossState(BOSS_FREYA) != DONE)
                            if (Creature* trigger = instance->GetCreature(FreyaAchieveTriggerGUID))
                                trigger->CastSpell(trigger, SPELL_LUMBERJACKED_CREDIT, true);
                        break;
                    case BOSS_KOLOGARN:
                        if (state == DONE)
                        {
                            if (GameObject* gameObject = instance->GetGameObject(KologarnChestGUID))
                            {
                                gameObject->SetRespawnTime(gameObject->GetRespawnDelay());
                                gameObject->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            }
                            HandleGameObject(KologarnBridgeGUID, false);
                        }
                        break;
                    case BOSS_HODIR:
                        if (state == DONE)
                        {
                            if (GameObject* HodirRareCache = instance->GetGameObject(HodirRareCacheGUID))
                                if (GetData(DATA_HODIR_RARE_CACHE))
                                    HodirRareCache->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            if (GameObject* HodirChest = instance->GetGameObject(HodirChestGUID))
                                HodirChest->SetRespawnTime(HodirChest->GetRespawnDelay());

                            instance->SummonCreature(NPC_HODIR_OBSERVATION_RING, ObservationRingKeepersPos[1]);
                        }
                        break;
                    case BOSS_THORIM:
                        if (state == DONE)
                        {
                            if (GameObject* gameObject = instance->GetGameObject(ThorimChestGUID))
                                gameObject->SetRespawnTime(gameObject->GetRespawnDelay());

                            instance->SummonCreature(NPC_THORIM_OBSERVATION_RING, ObservationRingKeepersPos[2]);
                        }
                        break;
                    case BOSS_ALGALON:
                        if (state == DONE)
                        {
                            _events.CancelEvent(EVENT_UPDATE_ALGALON_TIMER);
                            _events.CancelEvent(EVENT_DESPAWN_ALGALON);
                            DoUpdateWorldState(WORLD_STATE_ALGALON_TIMER_ENABLED, 0);
                            _algalonTimer = 61;
                            if (GameObject* gameObject = instance->GetGameObject(GiftOfTheObserverGUID))
                                gameObject->SetRespawnTime(gameObject->GetRespawnDelay());
                            // get item level (recheck weapons)
                            Map::PlayerList const& players = instance->GetPlayers();
                            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                if (Player* player = itr->GetSource())
                                    for (uint8 slot = EQUIPMENT_SLOT_MAINHAND; slot <= EQUIPMENT_SLOT_RANGED; ++slot)
                                        if (Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                                            if (item->GetTemplate()->ItemLevel > _maxWeaponItemLevel)
                                                _maxWeaponItemLevel = item->GetTemplate()->ItemLevel;
                        }
                        else if (state == IN_PROGRESS)
                        {
                            // get item level (armor cannot be swapped in combat)
                            Map::PlayerList const& players = instance->GetPlayers();
                            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                            {
                                if (Player* player = itr->GetSource())
                                {
                                    for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
                                    {
                                        if (slot == EQUIPMENT_SLOT_TABARD || slot == EQUIPMENT_SLOT_BODY)
                                            continue;

                                        if (Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                                        {
                                            if (slot >= EQUIPMENT_SLOT_MAINHAND && slot <= EQUIPMENT_SLOT_RANGED)
                                            {
                                                if (item->GetTemplate()->ItemLevel > _maxWeaponItemLevel)
                                                    _maxWeaponItemLevel = item->GetTemplate()->ItemLevel;
                                            }
                                            else if (item->GetTemplate()->ItemLevel > _maxArmorItemLevel)
                                                _maxArmorItemLevel = item->GetTemplate()->ItemLevel;
                                        }
                                    }
                                }
                            }
                        }
                        break;
                }

                return true;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_COLOSSUS:
                        ColossusData = data;
                        if (data == 2)
                        {
                            if (Creature* Leviathan = instance->GetCreature(LeviathanGUID))
                                Leviathan->AI()->DoAction(ACTION_MOVE_TO_CENTER_POSITION);
                            if (GameObject* gameObject = instance->GetGameObject(LeviathanGateGUID))
                                gameObject->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                            SaveToDB();
                        }
                        break;
                    case DATA_HODIR_RARE_CACHE:
                        HodirRareCacheData = data;
                        if (!HodirRareCacheData)
                        {
                            if (Creature* Hodir = instance->GetCreature(HodirGUID))
                                if (GameObject* gameObject = instance->GetGameObject(HodirRareCacheGUID))
                                    Hodir->RemoveGameObject(gameObject, false);
                        }
                        break;
                    case DATA_UNBROKEN:
                        Unbroken = data != 0;
                        break;
                    case DATA_ILLUSION:
                        illusion = data;
                        break;
                    case DATA_DRIVE_ME_CRAZY:
                        IsDriveMeCrazyEligible = data ? true : false;
                        break;
                    case EVENT_DESPAWN_ALGALON:
                        DoUpdateWorldState(WORLD_STATE_ALGALON_TIMER_ENABLED, 1);
                        DoUpdateWorldState(WORLD_STATE_ALGALON_DESPAWN_TIMER, 60);
                        _algalonTimer = 60;
                        _events.ScheduleEvent(EVENT_DESPAWN_ALGALON, 3600000);
                        _events.ScheduleEvent(EVENT_UPDATE_ALGALON_TIMER, 60000);
                        break;
                    case DATA_ALGALON_SUMMON_STATE:
                        _algalonSummoned = true;
                        break;
                    default:
                        break;
                }
            }

            void SetGuidData(uint32 /*type*/, ObjectGuid /*data*/) override
            {
            }

            ObjectGuid GetGuidData(uint32 data) const override
            {
                switch (data)
                {
                    case BOSS_LEVIATHAN:
                        return LeviathanGUID;
                    case BOSS_IGNIS:
                        return IgnisGUID;

                    // Razorscale
                    case BOSS_RAZORSCALE:
                        return RazorscaleGUID;
                    case DATA_RAZORSCALE_CONTROL:
                        return RazorscaleController;
                    case DATA_EXPEDITION_COMMANDER:
                        return ExpeditionCommanderGUID;
                    case GO_RAZOR_HARPOON_1:
                        return RazorHarpoonGUIDs[0];
                    case GO_RAZOR_HARPOON_2:
                        return RazorHarpoonGUIDs[1];
                    case GO_RAZOR_HARPOON_3:
                        return RazorHarpoonGUIDs[2];
                    case GO_RAZOR_HARPOON_4:
                        return RazorHarpoonGUIDs[3];

                    // XT-002 Deconstructor
                    case BOSS_XT002:
                        return XT002GUID;
                    case DATA_TOY_PILE_0:
                    case DATA_TOY_PILE_1:
                    case DATA_TOY_PILE_2:
                    case DATA_TOY_PILE_3:
                        return XTToyPileGUIDs[data - DATA_TOY_PILE_0];

                    // Assembly of Iron
                    case DATA_STEELBREAKER:
                        return AssemblyGUIDs[0];
                    case DATA_MOLGEIM:
                        return AssemblyGUIDs[1];
                    case DATA_BRUNDIR:
                        return AssemblyGUIDs[2];

                    case BOSS_KOLOGARN:
                        return KologarnGUID;
                    case BOSS_AURIAYA:
                        return AuriayaGUID;
                    case BOSS_HODIR:
                        return HodirGUID;
                    case BOSS_THORIM:
                        return ThorimGUID;

                    // Freya
                    case BOSS_FREYA:
                        return FreyaGUID;
                    case BOSS_BRIGHTLEAF:
                        return ElderGUIDs[0];
                    case BOSS_IRONBRANCH:
                        return ElderGUIDs[1];
                    case BOSS_STONEBARK:
                        return ElderGUIDs[2];

                    // Mimiron
                    case BOSS_MIMIRON:
                        return MimironGUID;
                    case DATA_LEVIATHAN_MK_II:
                        return MimironVehicleGUIDs[0];
                    case DATA_VX_001:
                        return MimironVehicleGUIDs[1];
                    case DATA_AERIAL_COMMAND_UNIT:
                        return MimironVehicleGUIDs[2];
                    case DATA_COMPUTER:
                        return MimironComputerGUID;
                    case DATA_MIMIRON_WORLD_TRIGGER:
                        return MimironWorldTriggerGUID;
                    case DATA_MIMIRON_ELEVATOR:
                        return MimironElevatorGUID;
                    case DATA_MIMIRON_BUTTON:
                        return MimironButtonGUID;

                    case BOSS_VEZAX:
                        return VezaxGUID;

                    // Yogg-Saron
                    case BOSS_YOGG_SARON:
                        return YoggSaronGUID;
                    case DATA_VOICE_OF_YOGG_SARON:
                        return VoiceOfYoggSaronGUID;
                    case DATA_BRAIN_OF_YOGG_SARON:
                        return BrainOfYoggSaronGUID;
                    case DATA_SARA:
                        return SaraGUID;
                    case GO_BRAIN_ROOM_DOOR_1:
                        return BrainRoomDoorGUIDs[0];
                    case GO_BRAIN_ROOM_DOOR_2:
                        return BrainRoomDoorGUIDs[1];
                    case GO_BRAIN_ROOM_DOOR_3:
                        return BrainRoomDoorGUIDs[2];
                    case DATA_FREYA_YS:
                        return KeeperGUIDs[0];
                    case DATA_HODIR_YS:
                        return KeeperGUIDs[1];
                    case DATA_THORIM_YS:
                        return KeeperGUIDs[2];
                    case DATA_MIMIRON_YS:
                        return KeeperGUIDs[3];

                    // Algalon
                    case BOSS_ALGALON:
                        return AlgalonGUID;
                    case DATA_SIGILDOOR_01:
                        return AlgalonSigilDoorGUID[0];
                    case DATA_SIGILDOOR_02:
                        return AlgalonSigilDoorGUID[1];
                    case DATA_SIGILDOOR_03:
                        return AlgalonSigilDoorGUID[2];
                    case DATA_UNIVERSE_FLOOR_01:
                        return AlgalonFloorGUID[0];
                    case DATA_UNIVERSE_FLOOR_02:
                        return AlgalonFloorGUID[1];
                    case DATA_UNIVERSE_GLOBE:
                        return AlgalonUniverseGUID;
                    case DATA_ALGALON_TRAPDOOR:
                        return AlgalonTrapdoorGUID;
                    case DATA_BRANN_BRONZEBEARD_ALG:
                        return BrannBronzebeardAlgGUID;
                }

                return ObjectGuid::Empty;
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_COLOSSUS:
                        return ColossusData;
                    case DATA_HODIR_RARE_CACHE:
                        return HodirRareCacheData;
                    case DATA_UNBROKEN:
                        return uint32(Unbroken);
                    case DATA_ILLUSION:
                        return illusion;
                    case DATA_KEEPERS_COUNT:
                        return keepersCount;
                    default:
                        break;
                }

                return 0;
            }

            bool CheckAchievementCriteriaMeet(uint32 criteriaId, Player const*, Unit const* /* = NULL */, uint32 /* = 0 */) override
            {
                switch (criteriaId)
                {
                    case CRITERIA_HERALD_OF_TITANS:
                        return _maxArmorItemLevel <= MAX_HERALD_ARMOR_ITEMLEVEL && _maxWeaponItemLevel <= MAX_HERALD_WEAPON_ITEMLEVEL;
                    case CRITERIA_WAITS_DREAMING_STORMWIND_25:
                    case CRITERIA_WAITS_DREAMING_STORMWIND_10:
                        return illusion == STORMWIND_ILLUSION;
                    case CRITERIA_WAITS_DREAMING_CHAMBER_25:
                    case CRITERIA_WAITS_DREAMING_CHAMBER_10:
                        return illusion == CHAMBER_ILLUSION;
                    case CRITERIA_WAITS_DREAMING_ICECROWN_25:
                    case CRITERIA_WAITS_DREAMING_ICECROWN_10:
                        return illusion == ICECROWN_ILLUSION;
                    case CRITERIA_DRIVE_ME_CRAZY_10:
                    case CRITERIA_DRIVE_ME_CRAZY_25:
                        return IsDriveMeCrazyEligible;
                    case CRITERIA_THREE_LIGHTS_IN_THE_DARKNESS_10:
                    case CRITERIA_THREE_LIGHTS_IN_THE_DARKNESS_25:
                        return keepersCount <= 3;
                    case CRITERIA_TWO_LIGHTS_IN_THE_DARKNESS_10:
                    case CRITERIA_TWO_LIGHTS_IN_THE_DARKNESS_25:
                        return keepersCount <= 2;
                    case CRITERIA_ONE_LIGHT_IN_THE_DARKNESS_10:
                    case CRITERIA_ONE_LIGHT_IN_THE_DARKNESS_25:
                        return keepersCount <= 1;
                    case CRITERIA_ALONE_IN_THE_DARKNESS_10:
                    case CRITERIA_ALONE_IN_THE_DARKNESS_25:
                        return keepersCount == 0;
                    case CRITERIA_C_O_U_LEVIATHAN_10:
                    case CRITERIA_C_O_U_LEVIATHAN_25:
                        return (_CoUAchivePlayerDeathMask & (1 << BOSS_LEVIATHAN)) == 0;
                    case CRITERIA_C_O_U_IGNIS_10:
                    case CRITERIA_C_O_U_IGNIS_25:
                        return (_CoUAchivePlayerDeathMask & (1 << BOSS_IGNIS)) == 0;
                    case CRITERIA_C_O_U_RAZORSCALE_10:
                    case CRITERIA_C_O_U_RAZORSCALE_25:
                        return (_CoUAchivePlayerDeathMask & (1 << BOSS_RAZORSCALE)) == 0;
                    case CRITERIA_C_O_U_XT002_10:
                    case CRITERIA_C_O_U_XT002_25:
                        return (_CoUAchivePlayerDeathMask & (1 << BOSS_XT002)) == 0;
                    case CRITERIA_C_O_U_IRON_COUNCIL_10:
                    case CRITERIA_C_O_U_IRON_COUNCIL_25:
                        return (_CoUAchivePlayerDeathMask & (1 << BOSS_ASSEMBLY_OF_IRON)) == 0;
                    case CRITERIA_C_O_U_KOLOGARN_10:
                    case CRITERIA_C_O_U_KOLOGARN_25:
                        return (_CoUAchivePlayerDeathMask & (1 << BOSS_KOLOGARN)) == 0;
                    case CRITERIA_C_O_U_AURIAYA_10:
                    case CRITERIA_C_O_U_AURIAYA_25:
                        return (_CoUAchivePlayerDeathMask & (1 << BOSS_AURIAYA)) == 0;
                    case CRITERIA_C_O_U_HODIR_10:
                    case CRITERIA_C_O_U_HODIR_25:
                        return (_CoUAchivePlayerDeathMask & (1 << BOSS_HODIR)) == 0;
                    case CRITERIA_C_O_U_THORIM_10:
                    case CRITERIA_C_O_U_THORIM_25:
                        return (_CoUAchivePlayerDeathMask & (1 << BOSS_THORIM)) == 0;
                    case CRITERIA_C_O_U_FREYA_10:
                    case CRITERIA_C_O_U_FREYA_25:
                        return (_CoUAchivePlayerDeathMask & (1 << BOSS_FREYA)) == 0;
                    case CRITERIA_C_O_U_MIMIRON_10:
                    case CRITERIA_C_O_U_MIMIRON_25:
                        return (_CoUAchivePlayerDeathMask & (1 << BOSS_MIMIRON)) == 0;
                    case CRITERIA_C_O_U_VEZAX_10:
                    case CRITERIA_C_O_U_VEZAX_25:
                        return (_CoUAchivePlayerDeathMask & (1 << BOSS_VEZAX)) == 0;
                    case CRITERIA_C_O_U_YOGG_SARON_10:
                    case CRITERIA_C_O_U_YOGG_SARON_25:
                        return (_CoUAchivePlayerDeathMask & (1 << BOSS_YOGG_SARON)) == 0;
                }

                return false;
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << GetData(DATA_COLOSSUS) << ' ' << _algalonTimer << ' ' << uint32(_algalonSummoned ? 1 : 0);

                for (uint8 i = 0; i < 4; ++i)
                    data << ' ' << uint32(KeeperGUIDs[i] ? 1 : 0);

                data << ' ' << _CoUAchivePlayerDeathMask;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                uint32 tempState;
                data >> tempState;
                if (tempState == IN_PROGRESS || tempState > SPECIAL)
                    tempState = NOT_STARTED;
                SetData(DATA_COLOSSUS, tempState);

                data >> _algalonTimer;
                data >> tempState;
                _algalonSummoned = tempState != 0;
                if (_algalonSummoned && GetBossState(BOSS_ALGALON) != DONE)
                {
                    _summonAlgalon = true;
                    if (_algalonTimer && _algalonTimer <= 60)
                    {
                        _events.ScheduleEvent(EVENT_UPDATE_ALGALON_TIMER, 60000);
                        DoUpdateWorldState(WORLD_STATE_ALGALON_TIMER_ENABLED, 1);
                        DoUpdateWorldState(WORLD_STATE_ALGALON_DESPAWN_TIMER, _algalonTimer);
                    }
                }

                for (uint8 i = 0; i < 4; ++i)
                {
                    data >> tempState;
                    _summonYSKeeper[i] = tempState != 0;
                }

                if (GetBossState(BOSS_FREYA) == DONE && !_summonYSKeeper[0])
                    _summonObservationRingKeeper[0] = true;
                if (GetBossState(BOSS_HODIR) == DONE && !_summonYSKeeper[1])
                    _summonObservationRingKeeper[1] = true;
                if (GetBossState(BOSS_THORIM) == DONE && !_summonYSKeeper[2])
                    _summonObservationRingKeeper[2] = true;
                if (GetBossState(BOSS_MIMIRON) == DONE && !_summonYSKeeper[3])
                    _summonObservationRingKeeper[3] = true;

                data >> _CoUAchivePlayerDeathMask;
            }

            void Update(uint32 diff) override
            {
                if (_events.Empty())
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_UPDATE_ALGALON_TIMER:
                            SaveToDB();
                            DoUpdateWorldState(WORLD_STATE_ALGALON_DESPAWN_TIMER, --_algalonTimer);
                            if (_algalonTimer)
                                _events.ScheduleEvent(EVENT_UPDATE_ALGALON_TIMER, 60000);
                            else
                            {
                                DoUpdateWorldState(WORLD_STATE_ALGALON_TIMER_ENABLED, 0);
                                _events.CancelEvent(EVENT_UPDATE_ALGALON_TIMER);
                                if (Creature* algalon = instance->GetCreature(AlgalonGUID))
                                    algalon->AI()->DoAction(EVENT_DESPAWN_ALGALON);
                            }
                            break;
                        case EVENT_DESPAWN_LEVIATHAN_VEHICLES:
                            // Eject all players from vehicles and make them untargetable.
                            // They will be despawned after a while
                            for (auto const& vehicleGuid : LeviathanVehicleGUIDs)
                            {
                                if (Creature* vehicleCreature = instance->GetCreature(vehicleGuid))
                                {
                                    if (Vehicle* vehicle = vehicleCreature->GetVehicleKit())
                                    {
                                        vehicle->RemoveAllPassengers();
                                        vehicleCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                        vehicleCreature->DespawnOrUnsummon(5 * MINUTE * IN_MILLISECONDS);
                                    }
                                }
                            }
                            break;
                    }
                }
            }

            void UpdateDoorState(GameObject* door) override
            {
                // Leviathan doors are set to DOOR_TYPE_ROOM except the one it uses to enter the room
                // which has to be set to DOOR_TYPE_PASSAGE
                if (door->GetEntry() == GO_LEVIATHAN_DOOR && door->GetPositionX() > 400.f)
                    door->SetGoState(GetBossState(BOSS_LEVIATHAN) == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                else
                    InstanceScript::UpdateDoorState(door);
            }

            void AddDoor(GameObject* door, bool add) override
            {
                // Leviathan doors are South except the one it uses to enter the room
                // which is North and should not be used for boundary checks in BossAI::CheckBoundary()
                if (door->GetEntry() == GO_LEVIATHAN_DOOR && door->GetPositionX() > 400.f)
                {
                    if (add)
                        GetBossInfo(BOSS_LEVIATHAN)->door[DOOR_TYPE_PASSAGE].insert(door->GetGUID());
                    else
                        GetBossInfo(BOSS_LEVIATHAN)->door[DOOR_TYPE_PASSAGE].erase(door->GetGUID());

                    if (add)
                        UpdateDoorState(door);
                }
                else
                    InstanceScript::AddDoor(door, add);
            }

        private:
            EventMap _events;
            uint32 _algalonTimer;
            bool _summonAlgalon;
            bool _algalonSummoned;
            bool _summonObservationRingKeeper[4];
            bool _summonYSKeeper[4];
            uint32 _maxArmorItemLevel;
            uint32 _maxWeaponItemLevel;
            uint32 _CoUAchivePlayerDeathMask;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_ulduar_InstanceMapScript(map);
        }
};

class spell_ulduar_teleporter : public SpellScriptLoader
{
    public:
        spell_ulduar_teleporter() : SpellScriptLoader("spell_ulduar_teleporter") { }

        class spell_ulduar_teleporter_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ulduar_teleporter_SpellScript);

            SpellCastResult CheckRequirement()
            {
                if (GetExplTargetUnit()->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_DONT_REPORT;

                if (GetExplTargetUnit()->IsInCombat())
                {
                    Spell::SendCastResult(GetExplTargetUnit()->ToPlayer(), GetSpellInfo(), 0, SPELL_FAILED_AFFECTING_COMBAT);
                    return SPELL_FAILED_AFFECTING_COMBAT;
                }

                return SPELL_CAST_OK;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_ulduar_teleporter_SpellScript::CheckRequirement);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_ulduar_teleporter_SpellScript();
        }
};

void AddSC_instance_ulduar()
{
    new instance_ulduar();
    new spell_ulduar_teleporter();
}
