/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "ulduar.h"
#include "Player.h"
#include "WorldPacket.h"

static DoorData const doorData[] =
{
    {GO_LEVIATHAN_DOOR,                 BOSS_LEVIATHAN,  DOOR_TYPE_ROOM,         BOUNDARY_S      },
    {GO_XT_002_DOOR,                    BOSS_XT002,      DOOR_TYPE_ROOM,         BOUNDARY_S      },
    {GO_YOGG_SARON_DOOR,                BOSS_YOGG_SARON, DOOR_TYPE_ROOM,         BOUNDARY_S      },
    {GO_DOODAD_UL_SIGILDOOR_03,         BOSS_ALGALON,    DOOR_TYPE_ROOM,         BOUNDARY_W      },
    {GO_DOODAD_UL_UNIVERSEFLOOR_01,     BOSS_ALGALON,    DOOR_TYPE_ROOM,         BOUNDARY_NONE   },
    {GO_DOODAD_UL_UNIVERSEFLOOR_02,     BOSS_ALGALON,    DOOR_TYPE_SPAWN_HOLE,   BOUNDARY_NONE   },
    {GO_DOODAD_UL_UNIVERSEGLOBE01,      BOSS_ALGALON,    DOOR_TYPE_SPAWN_HOLE,   BOUNDARY_NONE   },
    {GO_DOODAD_UL_ULDUAR_TRAPDOOR_03,   BOSS_ALGALON,    DOOR_TYPE_SPAWN_HOLE,   BOUNDARY_NONE   },
    {0,                                 0,               DOOR_TYPE_ROOM,         BOUNDARY_NONE   },
};

MinionData const minionData[] =
{
    { NPC_STEELBREAKER,   BOSS_ASSEMBLY_OF_IRON },
    { NPC_MOLGEIM,        BOSS_ASSEMBLY_OF_IRON },
    { NPC_BRUNDIR,        BOSS_ASSEMBLY_OF_IRON },
    { 0,                  0,                    }
};

class instance_ulduar : public InstanceMapScript
{
    public:
        instance_ulduar() : InstanceMapScript("instance_ulduar", 603) { }

        struct instance_ulduar_InstanceMapScript : public InstanceScript
        {
            instance_ulduar_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            // Creatures
            uint64 LeviathanGUID;
            uint64 IgnisGUID;
            uint64 RazorscaleGUID;
            uint64 RazorscaleController;
            uint64 ExpeditionCommanderGUID;
            uint64 XT002GUID;
            uint64 XTToyPileGUIDs[4];
            uint64 AssemblyGUIDs[3];
            uint64 KologarnGUID;
            uint64 AuriayaGUID;
            uint64 MimironGUID;
            uint64 HodirGUID;
            uint64 ThorimGUID;
            uint64 FreyaGUID;
            uint64 ElderGUIDs[3];
            uint64 VezaxGUID;
            uint64 YoggSaronGUID;
            uint64 VoiceOfYoggSaronGUID;
            uint64 SaraGUID;
            uint64 BrainOfYoggSaronGUID;
            uint64 AlgalonGUID;
            uint64 BrannBronzebeardAlgGUID;

            // GameObjects
            uint64 LeviathanGateGUID;
            uint64 RazorHarpoonGUIDs[4];
            uint64 KologarnChestGUID;
            uint64 KologarnBridgeGUID;
            uint64 KologarnDoorGUID;
            uint64 ThorimChestGUID;
            uint64 HodirRareCacheGUID;
            uint64 HodirChestGUID;
            uint64 HodirDoorGUID;
            uint64 HodirIceDoorGUID;
            uint64 ArchivumDoorGUID;
            uint64 VezaxDoorGUID;
            uint64 BrainRoomDoorGUIDs[3];
            uint64 KeeperGUIDs[4];
            uint64 AlgalonSigilDoorGUID[3];
            uint64 AlgalonFloorGUID[2];
            uint64 AlgalonUniverseGUID;
            uint64 AlgalonTrapdoorGUID;
            uint64 GiftOfTheObserverGUID;

            // Miscellaneous
            uint32 TeamInInstance;
            uint32 HodirRareCacheData;
            uint32 ColossusData;
            uint8 elderCount;
            uint8 illusion;
            uint8 keepersCount;
            bool conSpeedAtory;
            bool Unbroken;
            bool IsDriveMeCrazyEligible;

            std::set<uint64> mRubbleSpawns;

            void Initialize()
            {
                SetBossNumber(MAX_ENCOUNTER);
                LoadDoorData(doorData);
                LoadMinionData(minionData);
                IgnisGUID                        = 0;
                RazorscaleGUID                   = 0;
                RazorscaleController             = 0;
                ExpeditionCommanderGUID          = 0;
                XT002GUID                        = 0;
                KologarnGUID                     = 0;
                AuriayaGUID                      = 0;
                MimironGUID                      = 0;
                HodirGUID                        = 0;
                ThorimGUID                       = 0;
                FreyaGUID                        = 0;
                VezaxGUID                        = 0;
                YoggSaronGUID                    = 0;
                VoiceOfYoggSaronGUID             = 0;
                SaraGUID                         = 0;
                BrainOfYoggSaronGUID             = 0;
                AlgalonGUID                      = 0;
                KologarnChestGUID                = 0;
                KologarnBridgeGUID               = 0;
                ThorimChestGUID                  = 0;
                HodirRareCacheGUID               = 0;
                HodirChestGUID                   = 0;
                LeviathanGateGUID                = 0;
                VezaxDoorGUID                    = 0;
                HodirDoorGUID                    = 0;
                HodirIceDoorGUID                 = 0;
                ArchivumDoorGUID                 = 0;
                AlgalonUniverseGUID              = 0;
                AlgalonTrapdoorGUID              = 0;
                BrannBronzebeardAlgGUID          = 0;
                GiftOfTheObserverGUID            = 0;
                _algalonTimer                    = 61;
                _maxArmorItemLevel               = 0;
                _maxWeaponItemLevel              = 0;
                TeamInInstance                   = 0;
                HodirRareCacheData               = 0;
                ColossusData                     = 0;
                elderCount                       = 0;
                illusion                         = 0;
                keepersCount                     = 0;
                conSpeedAtory                    = false;
                Unbroken                         = true;
                _algalonSummoned                 = false;
                _summonAlgalon                   = false;

                memset(AlgalonSigilDoorGUID, 0, sizeof(AlgalonSigilDoorGUID));
                memset(AlgalonFloorGUID, 0, sizeof(AlgalonFloorGUID));
                memset(XTToyPileGUIDs, 0, sizeof(XTToyPileGUIDs));
                memset(AssemblyGUIDs, 0, sizeof(AssemblyGUIDs));
                memset(RazorHarpoonGUIDs, 0, sizeof(RazorHarpoonGUIDs));
                memset(ElderGUIDs, 0, sizeof(ElderGUIDs));
                memset(BrainRoomDoorGUIDs, 0, sizeof(BrainRoomDoorGUIDs));
                memset(KeeperGUIDs, 0, sizeof(KeeperGUIDs));
                memset(_summonObservationRingKeeper, false, sizeof(_summonObservationRingKeeper));
                memset(_summonYSKeeper, false, sizeof(_summonYSKeeper));
            }

            void FillInitialWorldStates(WorldPacket& packet)
            {
                packet << uint32(WORLD_STATE_ALGALON_TIMER_ENABLED) << uint32(_algalonTimer && _algalonTimer <= 60);
                packet << uint32(WORLD_STATE_ALGALON_DESPAWN_TIMER) << uint32(std::min<uint32>(_algalonTimer, 60));
            }

            void OnPlayerEnter(Player* player)
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

            void OnCreatureCreate(Creature* creature)
            {
                if (!TeamInInstance)
                {
                    Map::PlayerList const& Players = instance->GetPlayers();
                    if (!Players.isEmpty())
                        if (Player* player = Players.begin()->getSource())
                            TeamInInstance = player->GetTeam();
                }

                switch (creature->GetEntry())
                {
                    case NPC_LEVIATHAN:
                        LeviathanGUID = creature->GetGUID();
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
                    case NPC_MIMIRON:
                        MimironGUID = creature->GetGUID();
                        break;

                    // Hodir
                    case NPC_HODIR:
                        HodirGUID = creature->GetGUID();
                        break;
                    case NPC_EIVI_NIGHTFEATHER:
                        if (TeamInInstance == HORDE)
                            creature->UpdateEntry(NPC_TOR_GREYCLOUD, HORDE);
                        break;
                    case NPC_ELLIE_NIGHTFEATHER:
                        if (TeamInInstance == HORDE)
                            creature->UpdateEntry(NPC_KAR_GREYCLOUD, HORDE);
                        break;
                    case NPC_ELEMENTALIST_MAHFUUN:
                        if (TeamInInstance == HORDE)
                            creature->UpdateEntry(NPC_SPIRITWALKER_TARA, HORDE);
                        break;
                    case NPC_ELEMENTALIST_AVUUN:
                        if (TeamInInstance == HORDE)
                            creature->UpdateEntry(NPC_SPIRITWALKER_YONA, HORDE);
                        break;
                    case NPC_MISSY_FLAMECUFFS:
                        if (TeamInInstance == HORDE)
                            creature->UpdateEntry(NPC_AMIRA_BLAZEWEAVER, HORDE);
                        break;
                    case NPC_SISSY_FLAMECUFFS:
                        if (TeamInInstance == HORDE)
                            creature->UpdateEntry(NPC_VEESHA_BLAZEWEAVER, HORDE);
                        break;
                    case NPC_FIELD_MEDIC_PENNY:
                        if (TeamInInstance == HORDE)
                            creature->UpdateEntry(NPC_BATTLE_PRIEST_ELIZA, HORDE);
                        break;
                    case NPC_FIELD_MEDIC_JESSI:
                        if (TeamInInstance == HORDE)
                            creature->UpdateEntry(NPC_BATTLE_PRIEST_GINA, HORDE);
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
            }

            void OnCreatureRemove(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    case NPC_XT_TOY_PILE:
                        for (uint8 i = 0; i < 4; ++i)
                            if (XTToyPileGUIDs[i] == creature->GetGUID())
                            {
                                XTToyPileGUIDs[i] = 0;
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
                            BrannBronzebeardAlgGUID = 0;
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* gameObject)
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
                            HandleGameObject(0, false, gameObject);
                        break;
                    case GO_KOLOGARN_DOOR:
                        KologarnDoorGUID = gameObject->GetGUID();
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
                    case GO_LEVIATHAN_DOOR:
                        AddDoor(gameObject, true);
                        break;
                    case GO_LEVIATHAN_GATE:
                        LeviathanGateGUID = gameObject->GetGUID();
                        if (GetBossState(BOSS_LEVIATHAN) == DONE)
                            gameObject->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                        break;
                    case GO_XT_002_DOOR:
                        AddDoor(gameObject, true);
                        break;
                    case GO_VEZAX_DOOR:
                        VezaxDoorGUID = gameObject->GetGUID();
                        HandleGameObject(0, false, gameObject);
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
                    case GO_HODIR_DOOR:
                        HodirDoorGUID = gameObject->GetGUID();
                        break;
                    case GO_HODIR_ICE_DOOR:
                        HodirIceDoorGUID = gameObject->GetGUID();
                        break;
                    case GO_ARCHIVUM_DOOR:
                        ArchivumDoorGUID = gameObject->GetGUID();
                        if (GetBossState(BOSS_ASSEMBLY_OF_IRON) != DONE)
                            HandleGameObject(ArchivumDoorGUID, false);
                        break;
                    case GO_YOGG_SARON_DOOR:
                        AddDoor(gameObject, true);
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
                }
            }

            void OnGameObjectRemove(GameObject* gameObject)
            {
                switch (gameObject->GetEntry())
                {
                    case GO_LEVIATHAN_DOOR:
                    case GO_XT_002_DOOR:
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

            void OnUnitDeath(Unit* unit)
            {
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
                    default:
                        break;
                }
            }

            void ProcessEvent(WorldObject* /*gameObject*/, uint32 eventId)
            {
                // Flame Leviathan's Tower Event triggers
                Creature* FlameLeviathan = instance->GetCreature(LeviathanGUID);

                switch (eventId)
                {
                    case EVENT_TOWER_OF_STORM_DESTROYED:
                        if (FlameLeviathan && FlameLeviathan->isAlive())
                            FlameLeviathan->AI()->DoAction(ACTION_TOWER_OF_STORM_DESTROYED);
                        break;
                    case EVENT_TOWER_OF_FROST_DESTROYED:
                        if (FlameLeviathan && FlameLeviathan->isAlive())
                            FlameLeviathan->AI()->DoAction(ACTION_TOWER_OF_FROST_DESTROYED);
                        break;
                    case EVENT_TOWER_OF_FLAMES_DESTROYED:
                        if (FlameLeviathan && FlameLeviathan->isAlive())
                            FlameLeviathan->AI()->DoAction(ACTION_TOWER_OF_FLAMES_DESTROYED);
                        break;
                    case EVENT_TOWER_OF_LIFE_DESTROYED:
                        if (FlameLeviathan && FlameLeviathan->isAlive())
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

            bool SetBossState(uint32 type, EncounterState state)
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case BOSS_LEVIATHAN:
                    case BOSS_IGNIS:
                    case BOSS_RAZORSCALE:
                    case BOSS_XT002:
                    case BOSS_AURIAYA:
                        break;
                    case BOSS_MIMIRON:
                        if (state == DONE)
                            instance->SummonCreature(NPC_MIMIRON_OBSERVATION_RING, ObservationRingKeepersPos[3]);
                        break;
                    case BOSS_FREYA:
                        if (state == DONE)
                            instance->SummonCreature(NPC_FREYA_OBSERVATION_RING, ObservationRingKeepersPos[0]);
                        break;
                    case BOSS_ASSEMBLY_OF_IRON:
                        if (state == DONE)
                            HandleGameObject(ArchivumDoorGUID, true);
                        break;
                    case BOSS_VEZAX:
                        if (state == DONE)
                            HandleGameObject(VezaxDoorGUID, true);
                        break;
                    case BOSS_YOGG_SARON:
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
                            HandleGameObject(HodirDoorGUID, true);
                            HandleGameObject(HodirIceDoorGUID, true);

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
                                if (Player* player = itr->getSource())
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
                                if (Player* player = itr->getSource())
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

            void SetData(uint32 type, uint32 data)
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
                        Unbroken = bool(data);
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

            void SetData64(uint32 /*type*/, uint64 /*data*/)
            {
            }

            uint64 GetData64(uint32 data) const
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
                    case BOSS_MIMIRON:
                        return MimironGUID;
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

                return 0;
            }

            uint32 GetData(uint32 type) const
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

            bool CheckAchievementCriteriaMeet(uint32 criteriaId, Player const*, Unit const* /* = NULL */, uint32 /* = 0 */)
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
                }

                return false;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "U U " << GetBossSaveData() << GetData(DATA_COLOSSUS) << ' ' << _algalonTimer << ' ' << (_algalonSummoned ? 1 : 0);

                for (uint8 i = 0; i < 4; ++i)
                    saveStream << ' ' << (KeeperGUIDs[i] ? 1 : 0);

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(char const* strIn)
            {
                if (!strIn)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(strIn);

                char dataHead1, dataHead2;

                std::istringstream loadStream(strIn);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'U' && dataHead2 == 'U')
                {
                    for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;

                        SetBossState(i, EncounterState(tmpState));
                    }

                    uint32 tempState;
                    loadStream >> tempState;
                    if (tempState == IN_PROGRESS || tempState > SPECIAL)
                        tempState = NOT_STARTED;
                    SetData(DATA_COLOSSUS, tempState);

                    loadStream >> _algalonTimer;
                    loadStream >> tempState;
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
                        loadStream >> tempState;
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
                }

                OUT_LOAD_INST_DATA_COMPLETE;
            }

            void Update(uint32 diff)
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
                    }
                }
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
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_ulduar_InstanceMapScript(map);
        }
};

void AddSC_instance_ulduar()
{
    new instance_ulduar();
}
