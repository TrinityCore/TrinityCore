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

#include "ulduar.h"
#include "AreaBoundary.h"
#include "CreatureAI.h"
#include "EventMap.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Item.h"
#include "Map.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

static BossBoundaryData const boundaries =
{
    { DATA_FLAME_LEVIATHAN, new RectangleBoundary(148.0f, 401.3f, -155.0f, 90.0f) },
    { DATA_IGNIS, new RectangleBoundary(495.0f, 680.0f, 90.0f, 400.0f) },
    { DATA_RAZORSCALE, new RectangleBoundary(370.0f, 810.0f, -542.0f, -55.0f) },
    { DATA_XT002, new RectangleBoundary(755.0f, 940.0f, -125.0f, 95.0f) },
    { DATA_ASSEMBLY_OF_IRON, new CircleBoundary(Position(1587.2f, 121.0f), 90.0) },
    { DATA_ALGALON, new CircleBoundary(Position(1632.668f, -307.7656f), 45.0) },
    { DATA_ALGALON, new ZRangeBoundary(410.0f, 470.0f) },
    { DATA_HODIR, new EllipseBoundary(Position(2001.5f, -240.0f), 50.0, 75.0) },
    // Thorim sets boundaries dynamically
    { DATA_FREYA, new RectangleBoundary(2094.6f, 2520.0f, -250.0f, 200.0f) },
    { DATA_MIMIRON, new CircleBoundary(Position(2744.0f, 2569.0f), 70.0) },
    { DATA_VEZAX, new RectangleBoundary(1740.0f, 1930.0f, 31.0f, 228.0f) },
    { DATA_YOGG_SARON, new CircleBoundary(Position(1980.42f, -27.68f), 105.0) }
};

static DoorData const doorData[] =
{
    { GO_LEVIATHAN_DOOR,                DATA_FLAME_LEVIATHAN,   EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_XT_002_DOOR,                   DATA_XT002,             EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_IRON_COUNCIL_DOOR,             DATA_ASSEMBLY_OF_IRON,  EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_ARCHIVUM_DOOR,                 DATA_ASSEMBLY_OF_IRON,  EncounterDoorBehavior::OpenWhenDone },
    { GO_HODIR_ENTRANCE,                DATA_HODIR,             EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_HODIR_DOOR,                    DATA_HODIR,             EncounterDoorBehavior::OpenWhenDone },
    { GO_HODIR_ICE_DOOR,                DATA_HODIR,             EncounterDoorBehavior::OpenWhenDone },
    { GO_MIMIRON_DOOR_1,                DATA_MIMIRON,           EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_MIMIRON_DOOR_2,                DATA_MIMIRON,           EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_MIMIRON_DOOR_3,                DATA_MIMIRON,           EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_THORIM_ENCOUNTER_DOOR,         DATA_THORIM,            EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_ANCIENT_GATE_OF_THE_KEEPERS,   DATA_HODIR,             EncounterDoorBehavior::OpenWhenDone },
    { GO_ANCIENT_GATE_OF_THE_KEEPERS,   DATA_MIMIRON,           EncounterDoorBehavior::OpenWhenDone },
    { GO_ANCIENT_GATE_OF_THE_KEEPERS,   DATA_THORIM,            EncounterDoorBehavior::OpenWhenDone },
    { GO_ANCIENT_GATE_OF_THE_KEEPERS,   DATA_FREYA,             EncounterDoorBehavior::OpenWhenDone },
    { GO_VEZAX_DOOR,                    DATA_VEZAX,             EncounterDoorBehavior::OpenWhenDone },
    { GO_YOGG_SARON_DOOR,               DATA_YOGG_SARON,        EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_DOODAD_UL_SIGILDOOR_03,        DATA_ALGALON,           EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_DOODAD_UL_UNIVERSEFLOOR_01,    DATA_ALGALON,           EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_DOODAD_UL_UNIVERSEFLOOR_02,    DATA_ALGALON,           EncounterDoorBehavior::OpenWhenInProgress },
    { GO_DOODAD_UL_UNIVERSEGLOBE01,     DATA_ALGALON,           EncounterDoorBehavior::OpenWhenInProgress },
    { GO_DOODAD_UL_ULDUAR_TRAPDOOR_03,  DATA_ALGALON,           EncounterDoorBehavior::OpenWhenInProgress },
    { 0,                                0,                      EncounterDoorBehavior::OpenWhenNotInProgress },
};

MinionData const minionData[] =
{
    { NPC_STEELBREAKER,   DATA_ASSEMBLY_OF_IRON },
    { NPC_MOLGEIM,        DATA_ASSEMBLY_OF_IRON },
    { NPC_BRUNDIR,        DATA_ASSEMBLY_OF_IRON },
    { 0,                  0                     } // END
};

ObjectData const creatureData[] =
{
    { NPC_FLAME_LEVIATHAN,          DATA_FLAME_LEVIATHAN          },
    { NPC_IGNIS,                    DATA_IGNIS                    },
    { NPC_RAZORSCALE,               DATA_RAZORSCALE               },
    { NPC_XT002,                    DATA_XT002                    },
    { NPC_KOLOGARN,                 DATA_KOLOGARN                 },
    { NPC_AURIAYA,                  DATA_AURIAYA                  },
    { NPC_HODIR,                    DATA_HODIR                    },
    { NPC_THORIM,                   DATA_THORIM                   },
    { NPC_FREYA,                    DATA_FREYA                    },
    { NPC_MIMIRON,                  DATA_MIMIRON                  },
    { NPC_VEZAX,                    DATA_VEZAX                    },
    { NPC_YOGG_SARON,               DATA_YOGG_SARON               },
    { NPC_ALGALON,                  DATA_ALGALON                  },

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
    { NPC_HEART_OF_DECONSTRUCTOR,   DATA_XT002_HEART              },
    { NPC_AZEROTH,                  DATA_AZEROTH                  },
    { 0,                            0,                            }
};

ObjectData const objectData[] =
{
    { GO_MIMIRON_ELEVATOR,             DATA_MIMIRON_ELEVATOR     },
    { GO_MIMIRON_BUTTON,               DATA_MIMIRON_BUTTON       },
    { GO_DOODAD_UL_UNIVERSEGLOBE01,    DATA_UNIVERSE_GLOBE       },
    { GO_DOODAD_UL_ULDUAR_TRAPDOOR_03, DATA_ALGALON_TRAPDOOR     },
    { GO_RAZOR_HARPOON_1,              GO_RAZOR_HARPOON_1        },
    { GO_RAZOR_HARPOON_2,              GO_RAZOR_HARPOON_2        },
    { GO_RAZOR_HARPOON_3,              GO_RAZOR_HARPOON_3        },
    { GO_RAZOR_HARPOON_4,              GO_RAZOR_HARPOON_4        },
    { GO_THORIM_LEVER,                 DATA_THORIM_LEVER         },
    { GO_THORIM_STONE_DOOR,            DATA_STONE_DOOR           },
    { GO_THORIM_RUNIC_DOOR,            DATA_RUNIC_DOOR           },
    { GO_DOODAD_UL_SIGILDOOR_01,       DATA_SIGILDOOR_01         },
    { GO_DOODAD_UL_SIGILDOOR_02,       DATA_SIGILDOOR_02         },
    { GO_DOODAD_UL_SIGILDOOR_03,       DATA_SIGILDOOR_03         },
    { GO_DOODAD_UL_UNIVERSEFLOOR_01,   DATA_UNIVERSE_FLOOR_01    },
    { GO_DOODAD_UL_UNIVERSEFLOOR_02,   DATA_UNIVERSE_FLOOR_02    },
    { GO_GIFT_OF_THE_OBSERVER_10,      DATA_GIFT_OF_THE_OBSERVER },
    { GO_GIFT_OF_THE_OBSERVER_25,      DATA_GIFT_OF_THE_OBSERVER },
    { 0,                               0                         }
};

DungeonEncounterData const encounters[] =
{
    { DATA_FLAME_LEVIATHAN, {{ 1132 }} },
    { DATA_IGNIS, {{ 1136 }} },
    { DATA_RAZORSCALE, {{ 1139 }} },
    { DATA_XT002, {{ 1142 }} },
    { DATA_ASSEMBLY_OF_IRON, {{ 1140 }} },
    { DATA_KOLOGARN, {{ 1137 }} },
    { DATA_AURIAYA, {{ 1131 }} },
    { DATA_HODIR, {{ 1135 }} },
    { DATA_THORIM, {{ 1141 }} },
    { DATA_FREYA, {{ 1133 }} },
    { DATA_MIMIRON, {{ 1138 }} },
    { DATA_VEZAX, {{ 1134 }} },
    { DATA_YOGG_SARON, {{ 1143 }} },
    { DATA_ALGALON, {{ 1130 }} },
    { DATA_BRIGHTLEAF, {{ 1164 }} },
    { DATA_IRONBRANCH, {{ 1165 }} },
    { DATA_STONEBARK, {{ 1166 }} }
};

UlduarKeeperDespawnEvent::UlduarKeeperDespawnEvent(Creature* owner, Milliseconds despawnTimerOffset) : _owner(owner), _despawnTimer(despawnTimerOffset)
{
}

bool UlduarKeeperDespawnEvent::Execute(uint64 /*eventTime*/, uint32 /*updateTime*/)
{
    _owner->CastSpell(_owner, SPELL_TELEPORT_KEEPER_VISUAL);
    _owner->DespawnOrUnsummon(1s + _despawnTimer);
    return true;
}

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
                LoadDungeonEncounterData(encounters);

                _maxArmorItemLevel = 0;
                _maxWeaponItemLevel = 0;
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
                _algalonFirstIntro = true;

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

            // Miscellaneous
            uint32 HodirRareCacheData;
            uint32 ColossusData;
            uint8 elderCount;
            uint8 illusion;
            uint8 keepersCount;
            bool conSpeedAtory;
            bool lumberjacked;
            bool Unbroken;
            bool IsDriveMeCrazyEligible;

            void OnPlayerEnter(Player* /*player*/) override
            {
                if (_summonAlgalon)
                {
                    _summonAlgalon = false;
                    TempSummon* algalon = instance->SummonCreature(NPC_ALGALON, AlgalonLandPos);
                    if (!_algalonFirstIntro)
                        algalon->AI()->DoAction(ACTION_INIT_ALGALON);
                    else
                        algalon->SetImmuneToPC(false);
                }

                // Keepers at Observation Ring
                if (GetBossState(DATA_FREYA) == DONE && _summonObservationRingKeeper[0] && !KeeperGUIDs[0])
                {
                    _summonObservationRingKeeper[0] = false;
                    instance->SummonCreature(NPC_FREYA_OBSERVATION_RING, ObservationRingKeepersPos[0]);
                }
                if (GetBossState(DATA_HODIR) == DONE && _summonObservationRingKeeper[1] && !KeeperGUIDs[1])
                {
                    _summonObservationRingKeeper[1] = false;
                    instance->SummonCreature(NPC_HODIR_OBSERVATION_RING, ObservationRingKeepersPos[1]);
                }
                if (GetBossState(DATA_THORIM) == DONE && _summonObservationRingKeeper[2] && !KeeperGUIDs[2])
                {
                    _summonObservationRingKeeper[2] = false;
                    instance->SummonCreature(NPC_THORIM_OBSERVATION_RING, ObservationRingKeepersPos[2]);
                }
                if (GetBossState(DATA_MIMIRON) == DONE && _summonObservationRingKeeper[3] && !KeeperGUIDs[3])
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

                switch (creature->GetEntry())
                {
                    case NPC_SALVAGED_DEMOLISHER:
                    case NPC_SALVAGED_SIEGE_ENGINE:
                    case NPC_SALVAGED_CHOPPER:
                        if (GetBossState(DATA_FLAME_LEVIATHAN) == DONE)
                            DespawnLeviatanVehicle(creature);
                        else
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

                    // Freya
                    case NPC_IRONBRANCH:
                        ElderGUIDs[0] = creature->GetGUID();
                        if (GetBossState(DATA_FREYA) == DONE)
                            creature->DespawnOrUnsummon();
                        break;
                    case NPC_BRIGHTLEAF:
                        ElderGUIDs[1] = creature->GetGUID();
                        if (GetBossState(DATA_FREYA) == DONE)
                            creature->DespawnOrUnsummon();
                        break;
                    case NPC_STONEBARK:
                        ElderGUIDs[2] = creature->GetGUID();
                        if (GetBossState(DATA_FREYA) == DONE)
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
                        ++keepersCount;
                        DoUpdateWorldState(WORLD_STATE_YOGG_SARON_KEEPERS, keepersCount);
                        break;
                    case NPC_HODIR_YS:
                        KeeperGUIDs[1] = creature->GetGUID();
                        _summonYSKeeper[1] = false;
                        ++keepersCount;
                        DoUpdateWorldState(WORLD_STATE_YOGG_SARON_KEEPERS, keepersCount);
                        break;
                    case NPC_THORIM_YS:
                        KeeperGUIDs[2] = creature->GetGUID();
                        _summonYSKeeper[2] = false;
                        ++keepersCount;
                        DoUpdateWorldState(WORLD_STATE_YOGG_SARON_KEEPERS, keepersCount);
                        break;
                    case NPC_MIMIRON_YS:
                        KeeperGUIDs[3] = creature->GetGUID();
                        _summonYSKeeper[3] = false;
                        ++keepersCount;
                        DoUpdateWorldState(WORLD_STATE_YOGG_SARON_KEEPERS, keepersCount);
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
                        if (Creature* algalon = GetCreature(DATA_ALGALON))
                            algalon->AI()->JustSummoned(creature);
                        break;
                }

                InstanceScript::OnCreatureCreate(creature);
            }

            uint32 GetCreatureEntry(ObjectGuid::LowType /*guidLow*/, CreatureData const* data) override
            {
                uint32 entry = data->id;
                switch (entry)
                {
                    case NPC_EIVI_NIGHTFEATHER:
                        return instance->GetTeamInInstance() == HORDE ? NPC_TOR_GREYCLOUD : NPC_EIVI_NIGHTFEATHER;
                    case NPC_ELLIE_NIGHTFEATHER:
                        return instance->GetTeamInInstance() == HORDE ? NPC_KAR_GREYCLOUD : NPC_ELLIE_NIGHTFEATHER;
                    case NPC_ELEMENTALIST_MAHFUUN:
                        return instance->GetTeamInInstance() == HORDE ? NPC_SPIRITWALKER_TARA : NPC_ELEMENTALIST_MAHFUUN;
                    case NPC_ELEMENTALIST_AVUUN:
                        return instance->GetTeamInInstance() == HORDE ? NPC_SPIRITWALKER_YONA : NPC_ELEMENTALIST_AVUUN;
                    case NPC_MISSY_FLAMECUFFS:
                        return instance->GetTeamInInstance() == HORDE ? NPC_AMIRA_BLAZEWEAVER : NPC_MISSY_FLAMECUFFS;
                    case NPC_SISSY_FLAMECUFFS:
                        return instance->GetTeamInInstance() == HORDE ? NPC_VEESHA_BLAZEWEAVER : NPC_SISSY_FLAMECUFFS;
                    case NPC_FIELD_MEDIC_PENNY:
                        return instance->GetTeamInInstance() == HORDE ? NPC_BATTLE_PRIEST_ELIZA : NPC_FIELD_MEDIC_PENNY;
                    case NPC_FIELD_MEDIC_JESSI:
                        return instance->GetTeamInInstance() == HORDE ? NPC_BATTLE_PRIEST_GINA : NPC_FIELD_MEDIC_JESSI;
                    case NPC_MERCENARY_CAPTAIN_H:
                        return instance->GetTeamInInstance() == HORDE ? NPC_MERCENARY_CAPTAIN_A : NPC_MERCENARY_CAPTAIN_H;
                    case NPC_MERCENARY_SOLDIER_H:
                        return instance->GetTeamInInstance() == HORDE ? NPC_MERCENARY_SOLDIER_A : NPC_MERCENARY_SOLDIER_H;
                    default:
                        return entry;
                }
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
                        if (GetBossState(DATA_KOLOGARN) == DONE)
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
                        if (GetBossState(DATA_FLAME_LEVIATHAN) == DONE)
                            gameObject->SetGoState(GO_STATE_DESTROYED);
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
                            gameObject->SetFlag(GO_FLAG_IN_USE);
                        break;
                    case GO_DOODAD_UL_SIGILDOOR_01:
                    case GO_DOODAD_UL_SIGILDOOR_02:
                        if (_algalonSummoned)
                            gameObject->SetGoState(GO_STATE_ACTIVE);
                        break;
                    default:
                        break;
                }
            }

            void OnUnitDeath(Unit* unit) override
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
                            TriggerGameEvent(CRITERIA_CON_SPEED_ATORY);
                            conSpeedAtory = true;
                        }
                        break;
                    case NPC_IRONBRANCH:
                    case NPC_STONEBARK:
                    case NPC_BRIGHTLEAF:
                        if (!lumberjacked)
                        {
                            TriggerGameEvent(CRITERIA_LUMBERJACKED);
                            lumberjacked = true;
                        }
                        break;
                    default:
                        break;
                }
            }

            void ProcessEvent(WorldObject* /*gameObject*/, uint32 eventId, WorldObject* /*invoker*/) override
            {
                switch (eventId)
                {
                    // Flame Leviathan's Tower Event triggers
                    case EVENT_TOWER_OF_STORM_DESTROYED:
                        if (Creature* flameLeviathan = GetCreature(DATA_FLAME_LEVIATHAN))
                            flameLeviathan->AI()->DoAction(ACTION_TOWER_OF_STORM_DESTROYED);
                        break;
                    case EVENT_TOWER_OF_FROST_DESTROYED:
                        if (Creature* flameLeviathan = GetCreature(DATA_FLAME_LEVIATHAN))
                            flameLeviathan->AI()->DoAction(ACTION_TOWER_OF_FROST_DESTROYED);
                        break;
                    case EVENT_TOWER_OF_FLAMES_DESTROYED:
                        if (Creature* flameLeviathan = GetCreature(DATA_FLAME_LEVIATHAN))
                            flameLeviathan->AI()->DoAction(ACTION_TOWER_OF_FLAMES_DESTROYED);
                        break;
                    case EVENT_TOWER_OF_LIFE_DESTROYED:
                        if (Creature* flameLeviathan = GetCreature(DATA_FLAME_LEVIATHAN))
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
                    case DATA_FLAME_LEVIATHAN:
                        if (state == DONE)
                            _events.ScheduleEvent(EVENT_DESPAWN_LEVIATHAN_VEHICLES, 5s);
                        break;
                    case DATA_IGNIS:
                    case DATA_RAZORSCALE:
                    case DATA_XT002:
                    case DATA_ASSEMBLY_OF_IRON:
                    case DATA_AURIAYA:
                    case DATA_VEZAX:
                    case DATA_YOGG_SARON:
                        break;
                    case DATA_MIMIRON:
                        if (state == DONE)
                            instance->SummonCreature(NPC_MIMIRON_OBSERVATION_RING, ObservationRingKeepersPos[3]);
                        break;
                    case DATA_FREYA:
                        if (state == DONE)
                            instance->SummonCreature(NPC_FREYA_OBSERVATION_RING, ObservationRingKeepersPos[0]);
                        break;
                    case DATA_IRONBRANCH:
                    case DATA_STONEBARK:
                    case DATA_BRIGHTLEAF:
                        if (GetBossState(DATA_BRIGHTLEAF) == DONE && GetBossState(DATA_IRONBRANCH) == DONE && GetBossState(DATA_STONEBARK) == DONE && GetBossState(DATA_FREYA) != DONE)
                            if (Creature* trigger = instance->GetCreature(FreyaAchieveTriggerGUID))
                                trigger->CastSpell(trigger, SPELL_LUMBERJACKED_CREDIT, true);
                        break;
                    case DATA_KOLOGARN:
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
                    case DATA_HODIR:
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
                    case DATA_THORIM:
                        if (state == DONE)
                        {
                            if (Creature* thorim = GetCreature(DATA_THORIM))
                            {
                                if (GameObject* cache = instance->GetGameObject(thorim->AI()->GetData(DATA_THORIM_HARDMODE) ? CacheOfStormsHardmodeGUID : CacheOfStormsGUID))
                                {
                                    cache->SetTapList(thorim->GetTapList());
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
                    case DATA_ALGALON:
                        if (state == DONE)
                        {
                            if (GameObject* gift = GetGameObject(DATA_GIFT_OF_THE_OBSERVER))
                                gift->SetRespawnTime(gift->GetRespawnDelay());
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
                            _algalonFirstIntro = false;
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
                        if (data >= 2 && GetBossState(DATA_FLAME_LEVIATHAN) == NOT_STARTED)
                        {
                            _events.ScheduleEvent(EVENT_LEVIATHAN_BREAK_DOOR, 5s);
                        }
                        break;
                    case DATA_HODIR_RARE_CACHE:
                        HodirRareCacheData = data;
                        if (!HodirRareCacheData)
                        {
                            if (Creature* hodir = GetCreature(DATA_HODIR))
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
                    case DATA_BRIGHTLEAF:
                        return ElderGUIDs[0];
                    case DATA_IRONBRANCH:
                        return ElderGUIDs[1];
                    case DATA_STONEBARK:
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

            bool CheckAchievementCriteriaMeet(uint32 criteriaId, Player const*, Unit const* /* = nullptr */, uint32 /* = 0 */) override
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
                    case CRITERIA_C_O_U_LEVIATHAN_10:
                    case CRITERIA_C_O_U_LEVIATHAN_25:
                    case CRITERIA_C_O_U_IGNIS_10:
                    case CRITERIA_C_O_U_IGNIS_25:
                    case CRITERIA_C_O_U_RAZORSCALE_10:
                    case CRITERIA_C_O_U_RAZORSCALE_25:
                    case CRITERIA_C_O_U_XT002_10:
                    case CRITERIA_C_O_U_XT002_25:
                    case CRITERIA_C_O_U_IRON_COUNCIL_10:
                    case CRITERIA_C_O_U_IRON_COUNCIL_25:
                    case CRITERIA_C_O_U_KOLOGARN_10:
                    case CRITERIA_C_O_U_KOLOGARN_25:
                    case CRITERIA_C_O_U_AURIAYA_10:
                    case CRITERIA_C_O_U_AURIAYA_25:
                    case CRITERIA_C_O_U_HODIR_10:
                    case CRITERIA_C_O_U_HODIR_25:
                    case CRITERIA_C_O_U_THORIM_10:
                    case CRITERIA_C_O_U_THORIM_25:
                    case CRITERIA_C_O_U_FREYA_10:
                    case CRITERIA_C_O_U_FREYA_25:
                    case CRITERIA_C_O_U_MIMIRON_10:
                    case CRITERIA_C_O_U_MIMIRON_25:
                    case CRITERIA_C_O_U_VEZAX_10:
                    case CRITERIA_C_O_U_VEZAX_25:
                    case CRITERIA_C_O_U_YOGG_SARON_10:
                    case CRITERIA_C_O_U_YOGG_SARON_25:
                        return false;
                }

                return false;
            }

            void AfterDataLoad() override
            {
                if (GetBossState(DATA_FLAME_LEVIATHAN) == DONE)
                    SetData(DATA_COLOSSUS, DONE);

                if (GetBossState(DATA_FREYA) == DONE)
                    _summonObservationRingKeeper[0] = true;
                if (GetBossState(DATA_HODIR) == DONE)
                    _summonObservationRingKeeper[1] = true;
                if (GetBossState(DATA_THORIM) == DONE)
                    _summonObservationRingKeeper[2] = true;
                if (GetBossState(DATA_MIMIRON) == DONE)
                    _summonObservationRingKeeper[3] = true;
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
                        case EVENT_DESPAWN_LEVIATHAN_VEHICLES:
                            // Eject all players from vehicles and make them untargetable.
                            // They will be despawned after a while
                            for (auto const& vehicleGuid : LeviathanVehicleGUIDs)
                                if (Creature* vehicleCreature = instance->GetCreature(vehicleGuid))
                                    DespawnLeviatanVehicle(vehicleCreature);
                            break;
                        case EVENT_LEVIATHAN_BREAK_DOOR:
                            if (Creature* leviathan = GetCreature(DATA_FLAME_LEVIATHAN))
                                leviathan->AI()->DoAction(ACTION_MOVE_TO_CENTER_POSITION);
                            if (GameObject* gameObject = instance->GetGameObject(LeviathanGateGUID))
                                gameObject->SetGoState(GO_STATE_DESTROYED);
                            break;
                    }
                }
            }

            void DespawnLeviatanVehicle(Creature* vehicleCreature)
            {
                if (Vehicle* vehicle = vehicleCreature->GetVehicleKit())
                {
                    vehicle->RemoveAllPassengers();
                    vehicleCreature->SetUninteractible(true);
                    vehicleCreature->DespawnOrUnsummon(5min);
                }
            }

            void UpdateDoorState(GameObject* door) override
            {
                // Leviathan doors are set to EncounterStateForOpenDoor::NotInProgress except the one it uses to enter the room
                // which has to be set to EncounterStateForOpenDoor::Done
                if (door->GetEntry() == GO_LEVIATHAN_DOOR && door->GetPositionX() > 400.f)
                    door->SetGoState(GetBossState(DATA_FLAME_LEVIATHAN) == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                else
                    InstanceScript::UpdateDoorState(door);
            }

            void AddDoor(GameObject* door, bool add) override
            {
                // Leviathan doors are South except the one it uses to enter the room
                // which is North and should not be used for boundary checks in BossAI::IsInBoundary()
                if (door->GetEntry() == GO_LEVIATHAN_DOOR && door->GetPositionX() > 400.f)
                {
                    if (add)
                        GetBossInfo(DATA_FLAME_LEVIATHAN)->door[uint32(EncounterDoorBehavior::OpenWhenDone)].insert(door->GetGUID());
                    else
                        GetBossInfo(DATA_FLAME_LEVIATHAN)->door[uint32(EncounterDoorBehavior::OpenWhenDone)].erase(door->GetGUID());

                    if (add)
                        UpdateDoorState(door);
                }
                else
                    InstanceScript::AddDoor(door, add);
            }

        private:
            EventMap _events;
            bool _summonAlgalon;
            bool _algalonSummoned;
            bool _algalonFirstIntro;
            bool _summonObservationRingKeeper[4];
            bool _summonYSKeeper[4];
            uint32 _maxArmorItemLevel;
            uint32 _maxWeaponItemLevel;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_ulduar_InstanceMapScript(map);
        }
};

void AddSC_instance_ulduar()
{
    new instance_ulduar();
}
