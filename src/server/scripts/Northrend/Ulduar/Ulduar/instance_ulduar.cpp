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
#include "GameObject.h"
#include "InstanceScript.h"
#include "Item.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "ulduar.h"
#include "Vehicle.h"
#include "WorldStatePackets.h"

static BossBoundaryData const boundaries =
{
    { BOSS_LEVIATHAN, new RectangleBoundary(148.0f, 401.3f, -155.0f, 90.0f) },
    { BOSS_IGNIS, new RectangleBoundary(495.0f, 680.0f, 90.0f, 400.0f) },
    { BOSS_RAZORSCALE, new RectangleBoundary(370.0f, 810.0f, -542.0f, -55.0f) },
    { BOSS_XT002, new RectangleBoundary(755.0f, 940.0f, -125.0f, 95.0f) },
    { BOSS_ASSEMBLY_OF_IRON, new CircleBoundary(Position(1587.2f, 121.0f), 90.0) },
    { BOSS_ALGALON, new CircleBoundary(Position(1632.668f, -307.7656f), 45.0) },
    { BOSS_ALGALON, new ZRangeBoundary(410.0f, 470.0f) },
    { BOSS_HODIR, new EllipseBoundary(Position(2001.5f, -240.0f), 50.0, 75.0) },
    // Thorim sets boundaries dynamically
    { BOSS_FREYA, new RectangleBoundary(2094.6f, 2520.0f, -250.0f, 200.0f) },
    { BOSS_MIMIRON, new CircleBoundary(Position(2744.0f, 2569.0f), 70.0) },
    { BOSS_VEZAX, new RectangleBoundary(1740.0f, 1930.0f, 31.0f, 228.0f) },
    { BOSS_YOGG_SARON, new CircleBoundary(Position(1980.42f, -27.68f), 105.0) }
};

static DoorData const doorData[] =
{
    { GO_LEVIATHAN_DOOR,                BOSS_LEVIATHAN,         DOOR_TYPE_ROOM },
    { GO_XT_002_DOOR,                   BOSS_XT002,             DOOR_TYPE_ROOM },
    { GO_IRON_COUNCIL_DOOR,             BOSS_ASSEMBLY_OF_IRON,  DOOR_TYPE_ROOM },
    { GO_ARCHIVUM_DOOR,                 BOSS_ASSEMBLY_OF_IRON,  DOOR_TYPE_PASSAGE },
    { GO_HODIR_ENTRANCE,                BOSS_HODIR,             DOOR_TYPE_ROOM },
    { GO_HODIR_DOOR,                    BOSS_HODIR,             DOOR_TYPE_PASSAGE },
    { GO_HODIR_ICE_DOOR,                BOSS_HODIR,             DOOR_TYPE_PASSAGE },
    { GO_MIMIRON_DOOR_1,                BOSS_MIMIRON,           DOOR_TYPE_ROOM },
    { GO_MIMIRON_DOOR_2,                BOSS_MIMIRON,           DOOR_TYPE_ROOM },
    { GO_MIMIRON_DOOR_3,                BOSS_MIMIRON,           DOOR_TYPE_ROOM },
    { GO_THORIM_ENCOUNTER_DOOR,         BOSS_THORIM,            DOOR_TYPE_ROOM },
    { GO_ANCIENT_GATE_OF_THE_KEEPERS,   BOSS_HODIR,             DOOR_TYPE_PASSAGE },
    { GO_ANCIENT_GATE_OF_THE_KEEPERS,   BOSS_MIMIRON,           DOOR_TYPE_PASSAGE },
    { GO_ANCIENT_GATE_OF_THE_KEEPERS,   BOSS_THORIM,            DOOR_TYPE_PASSAGE },
    { GO_ANCIENT_GATE_OF_THE_KEEPERS,   BOSS_FREYA,             DOOR_TYPE_PASSAGE },
    { GO_VEZAX_DOOR,                    BOSS_VEZAX,             DOOR_TYPE_PASSAGE },
    { GO_YOGG_SARON_DOOR,               BOSS_YOGG_SARON,        DOOR_TYPE_ROOM },
    { GO_DOODAD_UL_SIGILDOOR_03,        BOSS_ALGALON,           DOOR_TYPE_ROOM },
    { GO_DOODAD_UL_UNIVERSEFLOOR_01,    BOSS_ALGALON,           DOOR_TYPE_ROOM },
    { GO_DOODAD_UL_UNIVERSEFLOOR_02,    BOSS_ALGALON,           DOOR_TYPE_SPAWN_HOLE },
    { GO_DOODAD_UL_UNIVERSEGLOBE01,     BOSS_ALGALON,           DOOR_TYPE_SPAWN_HOLE },
    { GO_DOODAD_UL_ULDUAR_TRAPDOOR_03,  BOSS_ALGALON,           DOOR_TYPE_SPAWN_HOLE },
    { 0,                                0,                      DOOR_TYPE_ROOM },
};

MinionData const minionData[] =
{
    { NPC_STEELBREAKER,   BOSS_ASSEMBLY_OF_IRON },
    { NPC_MOLGEIM,        BOSS_ASSEMBLY_OF_IRON },
    { NPC_BRUNDIR,        BOSS_ASSEMBLY_OF_IRON },
    { 0,                  0                     } // END
};

ObjectData const creatureData[] =
{
    { NPC_FLAME_LEVIATHAN,          BOSS_LEVIATHAN                },
    { NPC_IGNIS,                    BOSS_IGNIS                    },
    { NPC_RAZORSCALE,               BOSS_RAZORSCALE               },
    { NPC_XT002,                    BOSS_XT002                    },
    { NPC_KOLOGARN,                 BOSS_KOLOGARN                 },
    { NPC_AURIAYA,                  BOSS_AURIAYA                  },
    { NPC_HODIR,                    BOSS_HODIR                    },
    { NPC_THORIM,                   BOSS_THORIM                   },
    { NPC_FREYA,                    BOSS_FREYA                    },
    { NPC_MIMIRON,                  BOSS_MIMIRON                  },
    { NPC_VEZAX,                    BOSS_VEZAX                    },
    { NPC_YOGG_SARON,               BOSS_YOGG_SARON               },
    { NPC_ALGALON,                  BOSS_ALGALON                  },

    { NPC_EXPEDITION_COMMANDER,     DATA_EXPEDITION_COMMANDER     },
    { NPC_RAZORSCALE_CONTROLLER,    DATA_RAZORSCALE_CONTROL       },
    { NPC_SIF,                      DATA_SIF                      },
    { NPC_RUNIC_COLOSSUS,           DATA_RUNIC_COLOSSUS           },
    { NPC_RUNE_GIANT,               DATA_RUNE_GIANT               },
    { NPC_THORIM_CONTROLLER,        DATA_THORIM_CONTROLLER        },
    { NPC_COMPUTER,                 DATA_COMPUTER                 },
    { NPC_WORLD_TRIGGER_MIMIRON,    DATA_MIMIRON_WORLD_TRIGGER    },
    { NPC_VOICE_OF_YOGG_SARON,      DATA_VOICE_OF_YOGG_SARON      },
    { NPC_SARA,                     DATA_SARA                     },
    { NPC_BRAIN_OF_YOGG_SARON,      DATA_BRAIN_OF_YOGG_SARON      },
    { NPC_BRANN_BRONZBEARD_ALG,     DATA_BRANN_BRONZEBEARD_ALG    },
    { NPC_BRANN_BRONZEBEARD_INTRO,  DATA_BRANN_BRONZEBEARD_INTRO  },
    { NPC_LORE_KEEPER_OF_NORGANNON, DATA_LORE_KEEPER_OF_NORGANNON },
    { NPC_HIGH_EXPLORER_DELLORAH,   DATA_DELLORAH                 },
    { NPC_BRONZEBEARD_RADIO,        DATA_BRONZEBEARD_RADIO        },
    { 0,                            0,                            }
};

ObjectData const objectData[] =
{
    { GO_MIMIRON_ELEVATOR,             DATA_MIMIRON_ELEVATOR },
    { GO_MIMIRON_BUTTON,               DATA_MIMIRON_BUTTON   },
    { GO_DOODAD_UL_UNIVERSEGLOBE01,    DATA_UNIVERSE_GLOBE   },
    { GO_DOODAD_UL_ULDUAR_TRAPDOOR_03, DATA_ALGALON_TRAPDOOR },
    { GO_RAZOR_HARPOON_1,              GO_RAZOR_HARPOON_1    },
    { GO_RAZOR_HARPOON_2,              GO_RAZOR_HARPOON_2    },
    { GO_RAZOR_HARPOON_3,              GO_RAZOR_HARPOON_3    },
    { GO_RAZOR_HARPOON_4,              GO_RAZOR_HARPOON_4    },
    { GO_THORIM_LEVER,                 DATA_THORIM_LEVER     },
    { GO_THORIM_STONE_DOOR,            DATA_STONE_DOOR       },
    { GO_THORIM_RUNIC_DOOR,            DATA_RUNIC_DOOR       },
    { 0,                               0                     }
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
                LoadBossBoundaries(boundaries);
                LoadDoorData(doorData);
                LoadMinionData(minionData);
                LoadObjectData(creatureData, objectData);

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
            GuidVector LeviathanVehicleGUIDs;

            ObjectGuid XTToyPileGUIDs[4];
            ObjectGuid AssemblyGUIDs[3];

            ObjectGuid ElderGUIDs[3];
            ObjectGuid FreyaAchieveTriggerGUID;
            ObjectGuid MimironVehicleGUIDs[3];
            ObjectGuid KeeperGUIDs[4];

            // GameObjects
            ObjectGuid LeviathanGateGUID;
            ObjectGuid KologarnChestGUID;
            ObjectGuid KologarnBridgeGUID;
            ObjectGuid ThorimDarkIronPortcullisGUID;
            ObjectGuid CacheOfStormsGUID;
            ObjectGuid CacheOfStormsHardmodeGUID;
            ObjectGuid HodirRareCacheGUID;
            ObjectGuid HodirChestGUID;
            ObjectGuid MimironTramGUID;

            ObjectGuid BrainRoomDoorGUIDs[3];
            ObjectGuid AlgalonSigilDoorGUID[3];
            ObjectGuid AlgalonFloorGUID[2];

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

            void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override
            {
                packet.Worldstates.emplace_back(uint32(WORLD_STATE_ALGALON_TIMER_ENABLED), int32(_algalonTimer && _algalonTimer <= 60));
                packet.Worldstates.emplace_back(uint32(WORLD_STATE_ALGALON_DESPAWN_TIMER), int32(std::min<uint32>(_algalonTimer, 60)));
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
                        algalon->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
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
                InstanceScript::OnCreatureCreate(creature);

                if (!TeamInInstance)
                {
                    Map::PlayerList const& Players = instance->GetPlayers();
                    if (!Players.isEmpty())
                        if (Player* player = Players.begin()->GetSource())
                            TeamInInstance = player->GetTeam();
                }

                switch (creature->GetEntry())
                {
                    case NPC_SALVAGED_DEMOLISHER:
                    case NPC_SALVAGED_SIEGE_ENGINE:
                    case NPC_SALVAGED_CHOPPER:
                        LeviathanVehicleGUIDs.push_back(creature->GetGUID());
                        break;

                    // XT-002 Deconstructor
                    case NPC_XT_TOY_PILE:
                        for (uint8 i = 0; i < 4; ++i)
                        {
                            if (!XTToyPileGUIDs[i])
                            {
                                XTToyPileGUIDs[i] = creature->GetGUID();
                                break;
                            }
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

                    // Hodir
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

                    // Thorim
                    case NPC_MERCENARY_CAPTAIN_H:
                        if (TeamInInstance == HORDE)
                            creature->UpdateEntry(NPC_MERCENARY_CAPTAIN_A);
                        break;
                    case NPC_MERCENARY_SOLDIER_H:
                        if (TeamInInstance == HORDE)
                            creature->UpdateEntry(NPC_MERCENARY_SOLDIER_A);
                        break;

                    // Freya
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
                    case NPC_LEVIATHAN_MKII:
                        MimironVehicleGUIDs[0] = creature->GetGUID();
                        break;
                    case NPC_VX_001:
                        MimironVehicleGUIDs[1] = creature->GetGUID();
                        break;
                    case NPC_AERIAL_COMMAND_UNIT:
                        MimironVehicleGUIDs[2] = creature->GetGUID();
                        break;

                    // Yogg-Saron
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
                    //! These creatures are summoned by something else than Algalon
                    //! but need to be controlled/despawned by him - so they need to be
                    //! registered in his summon list
                    case NPC_ALGALON_VOID_ZONE_VISUAL_STALKER:
                    case NPC_ALGALON_STALKER_ASTEROID_TARGET_01:
                    case NPC_ALGALON_STALKER_ASTEROID_TARGET_02:
                    case NPC_UNLEASHED_DARK_MATTER:
                        if (Creature* algalon = GetCreature(BOSS_ALGALON))
                            algalon->AI()->JustSummoned(creature);
                        break;
                }

                InstanceScript::OnCreatureCreate(creature);
            }

            void OnCreatureRemove(Creature* creature) override
            {
                InstanceScript::OnCreatureRemove(creature);

                switch (creature->GetEntry())
                {
                    case NPC_XT_TOY_PILE:
                        for (uint8 i = 0; i < 4; ++i)
                        {
                            if (XTToyPileGUIDs[i] == creature->GetGUID())
                            {
                                XTToyPileGUIDs[i].Clear();
                                break;
                            }
                        }
                        break;
                    case NPC_STEELBREAKER:
                    case NPC_MOLGEIM:
                    case NPC_BRUNDIR:
                        AddMinion(creature, false);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* gameObject) override
            {
                InstanceScript::OnGameObjectCreate(gameObject);

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
                    case GO_THORIM_DARK_IRON_PORTCULLIS:
                        ThorimDarkIronPortcullisGUID = gameObject->GetGUID();
                        break;
                    case GO_CACHE_OF_STORMS_10:
                    case GO_CACHE_OF_STORMS_25:
                        CacheOfStormsGUID = gameObject->GetGUID();
                        break;
                    case GO_CACHE_OF_STORMS_HARDMODE_10:
                    case GO_CACHE_OF_STORMS_HARDMODE_25:
                        CacheOfStormsHardmodeGUID = gameObject->GetGUID();
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
                    case GO_LEVIATHAN_GATE:
                        LeviathanGateGUID = gameObject->GetGUID();
                        if (GetBossState(BOSS_LEVIATHAN) == DONE)
                            gameObject->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
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
                            gameObject->AddFlag(GO_FLAG_IN_USE);
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
                        break;
                    case GO_DOODAD_UL_UNIVERSEFLOOR_01:
                        AlgalonFloorGUID[0] = gameObject->GetGUID();
                        break;
                    case GO_DOODAD_UL_UNIVERSEFLOOR_02:
                        AlgalonFloorGUID[1] = gameObject->GetGUID();
                        break;
                    case GO_GIFT_OF_THE_OBSERVER_10:
                    case GO_GIFT_OF_THE_OBSERVER_25:
                        GiftOfTheObserverGUID = gameObject->GetGUID();
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
                    for (uint8 i = 0; i < BOSS_ALGALON; ++i)
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
                            DoStartCriteriaTimer(CRITERIA_TIMED_TYPE_EVENT, CRITERIA_CON_SPEED_ATORY);
                            conSpeedAtory = true;
                        }
                        break;
                    case NPC_IRONBRANCH:
                    case NPC_STONEBARK:
                    case NPC_BRIGHTLEAF:
                        if (!lumberjacked)
                        {
                            DoStartCriteriaTimer(CRITERIA_TIMED_TYPE_EVENT, CRITERIA_LUMBERJACKED);
                            lumberjacked = true;
                        }
                        break;
                    default:
                        break;
                }
            }

            void ProcessEvent(WorldObject* /*gameObject*/, uint32 eventId) override
            {
                switch (eventId)
                {
                    // Flame Leviathan's Tower Event triggers
                    case EVENT_TOWER_OF_STORM_DESTROYED:
                        if (Creature* flameLeviathan = GetCreature(BOSS_LEVIATHAN))
                            flameLeviathan->AI()->DoAction(ACTION_TOWER_OF_STORM_DESTROYED);
                        break;
                    case EVENT_TOWER_OF_FROST_DESTROYED:
                        if (Creature* flameLeviathan = GetCreature(BOSS_LEVIATHAN))
                            flameLeviathan->AI()->DoAction(ACTION_TOWER_OF_FROST_DESTROYED);
                        break;
                    case EVENT_TOWER_OF_FLAMES_DESTROYED:
                        if (Creature* flameLeviathan = GetCreature(BOSS_LEVIATHAN))
                            flameLeviathan->AI()->DoAction(ACTION_TOWER_OF_FLAMES_DESTROYED);
                        break;
                    case EVENT_TOWER_OF_LIFE_DESTROYED:
                        if (Creature* flameLeviathan = GetCreature(BOSS_LEVIATHAN))
                            flameLeviathan->AI()->DoAction(ACTION_TOWER_OF_LIFE_DESTROYED);
                        break;

                    // Yogg-Saron Event triggers
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
                                gameObject->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                            }
                            HandleGameObject(KologarnBridgeGUID, false);
                        }
                        break;
                    case BOSS_HODIR:
                        if (state == DONE)
                        {
                            if (GameObject* HodirRareCache = instance->GetGameObject(HodirRareCacheGUID))
                                if (GetData(DATA_HODIR_RARE_CACHE))
                                    HodirRareCache->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                            if (GameObject* HodirChest = instance->GetGameObject(HodirChestGUID))
                                HodirChest->SetRespawnTime(HodirChest->GetRespawnDelay());

                            instance->SummonCreature(NPC_HODIR_OBSERVATION_RING, ObservationRingKeepersPos[1]);
                        }
                        break;
                    case BOSS_THORIM:
                        if (state == DONE)
                        {
                            if (Creature* thorim = GetCreature(BOSS_THORIM))
                            {
                                if (GameObject* cache = instance->GetGameObject(thorim->AI()->GetData(DATA_THORIM_HARDMODE) ? CacheOfStormsHardmodeGUID : CacheOfStormsGUID))
                                {
                                    cache->SetLootRecipient(thorim->GetLootRecipient());
                                    cache->SetRespawnTime(cache->GetRespawnDelay());
                                    cache->RemoveFlag(GO_FLAG_LOCKED);
                                    cache->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                                    cache->RemoveFlag(GO_FLAG_NODESPAWN);
                                }
                            }

                            instance->SummonCreature(NPC_THORIM_OBSERVATION_RING, ObservationRingKeepersPos[2]);
                        }
                        else
                        {
                            DoCloseDoorOrButton(GetGuidData(DATA_THORIM_LEVER));
                            DoCloseDoorOrButton(ThorimDarkIronPortcullisGUID);
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
                                    for (uint8 slot = EQUIPMENT_SLOT_MAINHAND; slot <= EQUIPMENT_SLOT_OFFHAND; ++slot)
                                        if (Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                                            if (item->GetItemLevel(player) > _maxWeaponItemLevel)
                                                _maxWeaponItemLevel = item->GetItemLevel(player);
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
                                            if (slot >= EQUIPMENT_SLOT_MAINHAND && slot <= EQUIPMENT_SLOT_OFFHAND)
                                            {
                                                if (item->GetItemLevel(player) > _maxWeaponItemLevel)
                                                    _maxWeaponItemLevel = item->GetItemLevel(player);
                                            }
                                            else if (item->GetItemLevel(player) > _maxArmorItemLevel)
                                                _maxArmorItemLevel = item->GetItemLevel(player);
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
                        if (data == 2 && GetBossState(BOSS_LEVIATHAN) == NOT_STARTED)
                        {
                            _events.ScheduleEvent(EVENT_LEVIATHAN_BREAK_DOOR, 5 * IN_MILLISECONDS);
                            SaveToDB();
                        }
                        break;
                    case DATA_HODIR_RARE_CACHE:
                        HodirRareCacheData = data;
                        if (!HodirRareCacheData)
                        {
                            if (Creature* hodir = GetCreature(BOSS_HODIR))
                                if (GameObject* gameObject = instance->GetGameObject(HodirRareCacheGUID))
                                    hodir->RemoveGameObject(gameObject, false);
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
                    // XT-002 Deconstructor
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

                    // Freya
                    case BOSS_BRIGHTLEAF:
                        return ElderGUIDs[0];
                    case BOSS_IRONBRANCH:
                        return ElderGUIDs[1];
                    case BOSS_STONEBARK:
                        return ElderGUIDs[2];

                    // Mimiron
                    case DATA_LEVIATHAN_MK_II:
                        return MimironVehicleGUIDs[0];
                    case DATA_VX_001:
                        return MimironVehicleGUIDs[1];
                    case DATA_AERIAL_COMMAND_UNIT:
                        return MimironVehicleGUIDs[2];

                    // Yogg-Saron
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
                }

                return InstanceScript::GetGuidData(data);
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
                    data << ' ' << uint32(!KeeperGUIDs[i].IsEmpty() ? 1 : 0);

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
                                if (Creature* algalon = GetCreature(BOSS_ALGALON))
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
                                        vehicleCreature->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                                        vehicleCreature->DespawnOrUnsummon(5 * MINUTE * IN_MILLISECONDS);
                                    }
                                }
                            }
                            break;
                        case EVENT_LEVIATHAN_BREAK_DOOR:
                            if (Creature* leviathan = GetCreature(BOSS_LEVIATHAN))
                                leviathan->AI()->DoAction(ACTION_MOVE_TO_CENTER_POSITION);
                            if (GameObject* gameObject = instance->GetGameObject(LeviathanGateGUID))
                                gameObject->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
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
                    Spell::SendCastResult(GetExplTargetUnit()->ToPlayer(), GetSpellInfo(), GetSpell()->m_SpellVisual, GetSpell()->m_castId, SPELL_FAILED_AFFECTING_COMBAT);
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
