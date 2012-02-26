/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

static DoorData const doorData[] =
{
    {   GO_LEVIATHAN_DOOR, BOSS_LEVIATHAN,    DOOR_TYPE_ROOM, BOUNDARY_S      },
    {   GO_ALGALON_INVISDOOR,  BOSS_ALGALON,  DOOR_TYPE_ROOM, BOUNDARY_W      },
    {   0,                 0,                 DOOR_TYPE_ROOM, BOUNDARY_NONE   },
};

class instance_ulduar : public InstanceMapScript
{
    public:
        instance_ulduar() : InstanceMapScript("instance_ulduar", 603) { }

        struct instance_ulduar_InstanceMapScript : public InstanceScript
        {
            instance_ulduar_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            uint32 Encounter[MAX_ENCOUNTER];
            std::string m_strInstData;
            std::list<uint64> MimironDoorGUIDList;
            std::set<uint64> mRubbleSpawns;
			
            // Creatures
            uint64 LeviathanGUID;
            uint64 IgnisGUID;
            uint64 RazorscaleGUID;
            uint64 RazorscaleController;
            uint64 RazorHarpoonGUIDs[4];
            uint64 ExpeditionCommanderGUID;
            uint64 XT002GUID;
            uint64 XTToyPileGUIDs[4];
            uint64 AssemblyGUIDs[3];
            uint64 KologarnGUID;
            uint64 AuriayaGUID;
            uint64 MimironTrainGUID;
            uint64 MimironGUID;
            uint64 LeviathanMKIIGUID;
            uint64 VX001GUID;
            uint64 AerialUnitGUID;
            uint64 MimironElevatorGUID;
            uint64 HodirGUID;
            uint64 ThorimGUID;
            uint64 RunicColossusGUID;
            uint64 RuneGiantGUID;
            uint64 RunicDoorGUID;
            uint64 StoneDoorGUID;
            uint64 ThorimDoorGUID;
            uint64 FreyaGUID;
            uint64 KeeperGUIDs[3];
            uint64 VezaxGUID;
            uint64 YoggSaronGUID;
            uint64 SaraGUID;
            uint64 YoggSaronDoorGUID;
            uint64 YoggSaronBrainDoor1GUID;
            uint64 YoggSaronBrainDoor2GUID;
            uint64 YoggSaronBrainDoor3GUID;
            uint64 LeviathanGateGUID;
            uint64 VezaxDoorGUID;
            uint64 AlgalonGUID;
            uint64 AlgalonBrannGUID;
            uint64 AlgalonDoorGUID;
            uint64 AlgalonFloorOOCGUID;
            uint64 AlgalonFloorCOMGUID;
            uint64 AlgalonBridgeGUID;
            uint64 AlgalonGlobeGUID;
            uint64 AlgalonForceFieldGUID;
            uint32 AlgalonIntroDone;
            uint32 SignalTimerState;
            uint32 SignalTimer;
            uint32 SignalTimerMinutes;

            // GameObjects
            uint64 KologarnChestGUID;
            uint64 KologarnBridgeGUID;
            uint64 KologarnDoorGUID;
            uint64 ThorimChestGUID;
            uint64 HodirRareCacheGUID;
            uint64 HodirChestGUID;
            uint64 HodirDoorGUID;
            uint64 HodirIceDoorGUID;
            uint64 HodirStoneDoorGUID;
            uint64 ArchivumDoorGUID;
            uint64 XT002DoorGUID;
            uint64 IronCouncilEntranceGUID;

            // Miscellaneous
            uint64 WayToYoggGUID;
            uint32 TeamInInstance;
            uint32 HodirRareCacheData;
            uint32 ColossusData;
            uint32 SupportKeeperFlag;
            uint32 PlayerDeathFlag;
            uint32 AlgalonKillCount;
            uint8 elderCount;
            bool conSpeedAtory;
            bool Unbroken;

            void Initialize()
            {
                SetBossNumber(MAX_ENCOUNTER);
                LoadDoorData(doorData);
                IgnisGUID                        = 0;
                RazorscaleGUID                   = 0;
                RazorscaleController             = 0;
                ExpeditionCommanderGUID          = 0;
                XT002GUID                        = 0;
                XT002DoorGUID                    = 0;
                KologarnGUID                     = 0;
                AuriayaGUID                      = 0;
                MimironGUID                      = 0;
                HodirGUID                        = 0;
                ThorimGUID                       = 0;
                FreyaGUID                        = 0;
                VezaxGUID                        = 0;
                YoggSaronGUID                    = 0;
                YoggSaronDoorGUID                = 0;
                YoggSaronBrainDoor1GUID          = 0;
                YoggSaronBrainDoor2GUID          = 0;
                YoggSaronBrainDoor3GUID          = 0;
                SaraGUID                         = 0;
                SupportKeeperFlag                = 0;
                PlayerDeathFlag                  = 0;
                AlgalonGUID                      = 0;
                AlgalonBrannGUID                 = 0;
                AlgalonDoorGUID                  = 0;
                AlgalonBridgeGUID                = 0;
                AlgalonGlobeGUID                 = 0;
                AlgalonFloorOOCGUID              = 0;
                AlgalonFloorCOMGUID              = 0;
                AlgalonForceFieldGUID            = 0;
                SignalTimerState                 = 0;
                SignalTimer                      = 0;
                SignalTimerMinutes               = 0;
                KologarnChestGUID                = 0;
                KologarnBridgeGUID               = 0;
                ThorimChestGUID                  = 0;
                HodirRareCacheGUID               = 0;
                HodirChestGUID                   = 0;
                LeviathanGateGUID                = 0;
                VezaxDoorGUID                    = 0;
                HodirDoorGUID                    = 0;
                HodirIceDoorGUID                 = 0;
                HodirStoneDoorGUID               = 0;
                ArchivumDoorGUID                 = 0;
                IronCouncilEntranceGUID          = 0;
                TeamInInstance                   = 0;
                HodirRareCacheData               = 0;
                WayToYoggGUID                    = 0;
                ColossusData                     = 0;
                elderCount                       = 0;
                conSpeedAtory                    = false;
                Unbroken                         = true;

                memset(Encounter, 0, sizeof(Encounter));
                memset(XTToyPileGUIDs, 0, sizeof(XTToyPileGUIDs));
                memset(AssemblyGUIDs, 0, sizeof(AssemblyGUIDs));
                memset(RazorHarpoonGUIDs, 0, sizeof(RazorHarpoonGUIDs));
                memset(KeeperGUIDs, 0, sizeof(KeeperGUIDs));
				
                AlgalonIntroDone = false;
            }

            uint32 TypeToDeadFlag(uint32 type)
            {
                  uint32 return_value = 1;
                  for (uint32 i = 0; i < type; i++)
                  {
                       return_value *= 2;
                  }
                  return return_value;
            }	
            void OnPlayerKilled(Player* /*player*/)
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                {
                    if (Encounter[i] == IN_PROGRESS)
                    {
                        if (i < BOSS_ALGALON)
                            PlayerDeathFlag |= UlduarBossDeadFlags(TypeToDeadFlag(i));
                        else if (i == BOSS_ALGALON)
                            AlgalonKillCount++;
                    }
                }
            }

            bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target = NULL*/, uint32 /*miscvalue1 = 0*/)
            {
                switch (criteria_id)
                {
                    // Kills without Death Achievement
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_FLAMELEVIATAN_10:
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_FLAMELEVIATAN_25:
                        return !(PlayerDeathFlag & DEAD_FLAME_LEVIATHAN);
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_IGNIS_10:
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_IGNIS_25:
                        return !(PlayerDeathFlag & DEAD_IGNIS);
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_RAZORSCALE_10:
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_RAZORSCALE_25:
                        return !(PlayerDeathFlag & DEAD_RAZORSCALE);
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_XT002_10:
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_XT002_25:
                        return !(PlayerDeathFlag & DEAD_XT002);
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_ASSEMBLY_10:
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_ASSEMBLY_25:
                        return !(PlayerDeathFlag & DEAD_ASSEMBLY);
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_KOLOGARN_10:
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_KOLOGARN_25:
                        return !(PlayerDeathFlag & DEAD_KOLOGARN);
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_AURIAYA_10:
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_AURIAYA_25:
                        return !(PlayerDeathFlag & DEAD_AURIAYA);
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_HODIR_10:
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_HODIR_25:
                        return !(PlayerDeathFlag & DEAD_HODIR);
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_THORIM_10:
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_THORIM_25:
                        return !(PlayerDeathFlag & DEAD_THORIM);
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_FREYA_10:
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_FREYA_25:
                        return !(PlayerDeathFlag & DEAD_FREYA);
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_MIMIRON_10:
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_MIMIRON_25:
                        return !(PlayerDeathFlag & DEAD_MIMIRON);
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_VEZAX_10:
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_VEZAX_25:
                        return !(PlayerDeathFlag & DEAD_VEZAX);
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_YOGGSARON_10:
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_YOGGSARON_25:
                        return !(PlayerDeathFlag & DEAD_YOGGSARON);
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_ALGALON_10:
                    case ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_ALGALON_25:
                        return !(AlgalonKillCount);
               }

                // Yogg-Saron
                switch (criteria_id)
                {
                    case ACHIEVEMENT_CRITERIA_THE_ASSASSINATION_OF_KING_LLANE_10:
                    case ACHIEVEMENT_CRITERIA_THE_ASSASSINATION_OF_KING_LLANE_25:
                    {
                        if (GetBossState(BOSS_YOGGSARON) != IN_PROGRESS)
                            return false;

                        if (Creature* Sara = instance->GetCreature(SaraGUID))
                            return (Sara->AI()->GetData(DATA_PORTAL_PHASE) == 0);

                        return false;
					}
                    case ACHIEVEMENT_CRITERIA_THE_TORTURED_CHAMPION_10:
                    case ACHIEVEMENT_CRITERIA_THE_TORTURED_CHAMPION_25:
                    {
                        if (GetBossState(BOSS_YOGGSARON) != IN_PROGRESS)
                            return false;

                        if (Creature* Sara = instance->GetCreature(SaraGUID))
                            return (Sara->AI()->GetData(DATA_PORTAL_PHASE) == 2);

                        return false;
                    }
                    case ACHIEVEMENT_CRITERIA_FORGING_OF_THE_DEMON_SOUL_10:
                    case ACHIEVEMENT_CRITERIA_FORGING_OF_THE_DEMON_SOUL_25:
                    {
                        if (GetBossState(BOSS_YOGGSARON) != IN_PROGRESS)
                            return false;

                        if (Creature* Sara = instance->GetCreature(SaraGUID))
                            return (Sara->AI()->GetData(DATA_PORTAL_PHASE) == 1);

                        return false;
                    }
                }
                return false;
            }
			
            bool IsEncounterInProgress() const
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                {
                    if (Encounter[i] == IN_PROGRESS)
                        return true;
                }

                return false;
            }

            void OnPlayerEnter(Player* player)
            {
                if (!TeamInInstance)
                    TeamInInstance = player->GetTeam();
                if (!TeamInInstance)
                {
                    Map::PlayerList const& Players = instance->GetPlayers();
                    if (!Players.isEmpty())
                        if (Player* player = Players.begin()->getSource())
                            TeamInInstance = player->GetTeam();
                }
            }  

            void FillInitialWorldStates(WorldPacket& data)
            {
                data << uint32(WORLDSTATE_SHOW_TIMER)            << uint32(SignalTimerState == IN_PROGRESS);
                data << uint32(WORLDSTATE_ALGALON_TIMER)         << uint32(SignalTimerMinutes ? SignalTimerMinutes : 60);
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
                    case NPC_RAZORSCALE:
                        RazorscaleGUID = creature->GetGUID();
                        break;
                    case NPC_RAZORSCALE_CONTROLLER:
                        RazorscaleController = creature->GetGUID();
                        break;
                    case NPC_EXPEDITION_COMMANDER:
                        ExpeditionCommanderGUID = creature->GetGUID();
                        break;
                    case NPC_XT002:
                        XT002GUID = creature->GetGUID();
                        break;
                    case NPC_XT_TOY_PILE:
                        for (uint8 i = 0; i < 4; ++i)
                            if (!XTToyPileGUIDs[i])
                                XTToyPileGUIDs[i] = creature->GetGUID();
                        break;

                    // Assembly of Iron
                    case NPC_STEELBREAKER:
                        AssemblyGUIDs[0] = creature->GetGUID();
                        break;
                    case NPC_MOLGEIM:
                        AssemblyGUIDs[1] = creature->GetGUID();
                        break;
                    case NPC_BRUNDIR:
                        AssemblyGUIDs[2] = creature->GetGUID();
                        break;

                    // Freya's Keeper
                    case NPC_IRONBRANCH:
                        KeeperGUIDs[0] = creature->GetGUID();
                        if (GetBossState(BOSS_FREYA) == DONE)
                            creature->DespawnOrUnsummon();
                        break;
                    case NPC_BRIGHTLEAF:
                        KeeperGUIDs[1] = creature->GetGUID();
                        if (GetBossState(BOSS_FREYA) == DONE)
                            creature->DespawnOrUnsummon();
                        break;
                    case NPC_STONEBARK:
                        KeeperGUIDs[2] = creature->GetGUID();
                        if (GetBossState(BOSS_FREYA) == DONE)
                            creature->DespawnOrUnsummon();
                         break;

                    // Kologarn
                    case NPC_KOLOGARN:
                        KologarnGUID = creature->GetGUID();
                        break;
                    case NPC_AURIAYA:
                        AuriayaGUID = creature->GetGUID();
                        break;
                    case NPC_HODIR:
                        HodirGUID = creature->GetGUID();
                        break;
                    case NPC_FREYA:
                        FreyaGUID = creature->GetGUID();
                        break;
                    case NPC_VEZAX:
                        VezaxGUID = creature->GetGUID();
                        break;
                    case NPC_ALGALON:
                        AlgalonGUID = creature->GetGUID();
                        if (AlgalonIntroDone && !SignalTimerMinutes)
                            creature->DespawnOrUnsummon();
                        creature->setActive(true);
                        break;
                    case NPC_BRANN_ALGALON:
                        AlgalonBrannGUID = creature->GetGUID();
                        creature->setActive(true);
                        break;

                    // Mimiron
                    case NPC_MIMIRON:
                        MimironGUID = creature->GetGUID();
                        break;
                    case NPC_LEVIATHAN_MKII:
                        LeviathanMKIIGUID = creature->GetGUID();
                        break;
                    case NPC_VX_001:
                        VX001GUID = creature->GetGUID();
                        break;
                    case NPC_AERIAL_COMMAND_UNIT:
                        AerialUnitGUID = creature->GetGUID();
                        break;
                    // Thorim
                    case NPC_THORIM:
                        ThorimGUID = creature->GetGUID();
                        break;
                    case NPC_RUNIC_COLOSSUS:
                        RunicColossusGUID = creature->GetGUID();
                        break;
                    case NPC_RUNE_GIANT:
                        RuneGiantGUID = creature->GetGUID();
                        break;

                    // Yogg-Saron
                    case NPC_YOGGSARON:
                        YoggSaronGUID = creature->GetGUID();
                        break;
                    case NPC_SARA:
                        SaraGUID = creature->GetGUID();
                        break;
					
                    // Hodir's Helper NPCs
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
                }

             }

            void OnGameObjectCreate(GameObject* gameObject)
            {
                switch (gameObject->GetEntry())
                {
                    case GO_IRON_COUNCIL_ENTRANCE:
                        IronCouncilEntranceGUID = gameObject->GetGUID();
                        break;
                    case GO_XT002_DOOR:
                        XT002DoorGUID = gameObject->GetGUID();
                        break;
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
                        if (GetBossState(BOSS_HODIR) == DONE)
                            HandleGameObject(HodirIceDoorGUID, true);
                        break;
                    case GO_HODIR_STONE_DOOR:
                        HodirStoneDoorGUID = gameObject->GetGUID();
                        if (GetBossState(BOSS_HODIR) == DONE)
                            HandleGameObject(HodirStoneDoorGUID, true);
                        break;
                    case GO_ARCHIVUM_DOOR:
                        ArchivumDoorGUID = gameObject->GetGUID();
                        HandleGameObject(0, GetBossState(BOSS_ASSEMBLY_OF_IRON) == DONE, gameObject);
                        break;
                    case GO_MIMIRON_TRAIN:
                        gameObject->setActive(true);
                        MimironTrainGUID = gameObject->GetGUID();
                        break;
                    case GO_MIMIRON_ELEVATOR:
                        gameObject->setActive(true);
                        MimironElevatorGUID = gameObject->GetGUID();
                        break;
                    case GO_MIMIRON_DOOR_1:
                    case GO_MIMIRON_DOOR_2:
                    case GO_MIMIRON_DOOR_3:
                        gameObject->setActive(true);
                        MimironDoorGUIDList.push_back(gameObject->GetGUID());
                        break;
                    case GO_WAY_TO_YOGG:
                        WayToYoggGUID = gameObject->GetGUID();
                        if (GetBossState(BOSS_FREYA) == DONE &&
                            GetBossState(BOSS_MIMIRON) == DONE &&
                            GetBossState(BOSS_HODIR) == DONE &&
                            GetBossState(BOSS_THORIM) == DONE)
                            gameObject->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
                        break;
                    case GO_THORIM_CHEST_HERO:
                    case GO_THORIM_CHEST:
                        ThorimChestGUID = gameObject->GetGUID();
                        break;
                    case GO_THORIM_ENCOUNTER_DOOR:
                        ThorimDoorGUID = gameObject->GetGUID();
                        break;
                    case GO_THORIM_STONE_DOOR:
                        StoneDoorGUID = gameObject->GetGUID();
                        break;
                    case GO_THORIM_RUNIC_DOOR:
                        RunicDoorGUID = gameObject->GetGUID();
                    break;
                    case GO_ALGALON_DOOR:
                        AlgalonDoorGUID       = gameObject->GetGUID();
                        gameObject->SetGoState(GO_STATE_READY);
                        if (AlgalonIntroDone)
                            gameObject->SetGoState(GO_STATE_ACTIVE);
                    break;
                    case GO_ALGALON_FLOOR_OOC:
                        AlgalonFloorOOCGUID   = gameObject->GetGUID();
                        gameObject->SetGoState(GO_STATE_READY);
                        gameObject->setActive(true);
                        gameObject->SetPhaseMask(PHASEMASK_ANYWHERE,false);
                    break;
                    case GO_ALGALON_FLOOR_COM:
                        AlgalonFloorCOMGUID   = gameObject->GetGUID();
                        gameObject->SetGoState(GO_STATE_ACTIVE);
                        gameObject->SetPhaseMask(PHASEMASK_ANYWHERE,false);
                    break;
                    case GO_ALGALON_BRIDGE:
                        AlgalonBridgeGUID     = gameObject->GetGUID();
                        gameObject->SetGoState(GO_STATE_READY);
                        gameObject->SetPhaseMask(PHASEMASK_ANYWHERE,false);
                    break;
                    case GO_ALGALON_GLOBE:
                        AlgalonGlobeGUID      = gameObject->GetGUID();
                        HandleGameObject(0, false, gameObject);
                        gameObject->SetPhaseMask(PHASEMASK_ANYWHERE,false);
                    break;
                    case GO_ALGALON_INVISDOOR:
                        AlgalonForceFieldGUID= gameObject->GetGUID();
                        AddDoor(gameObject, true);
                        gameObject->SetGoState(GO_STATE_ACTIVE);
                        gameObject->SetPhaseMask(PHASEMASK_ANYWHERE,false);
                    break;
                    case GO_ALGALON_CONSOLE:
                        if (AlgalonIntroDone)
                        {
                            gameObject->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }          
                    break;
                    case GO_YOGGSARON_DOOR:
                        YoggSaronDoorGUID = gameObject->GetGUID();
                        HandleGameObject(NULL, true, gameObject);
                    break;
                    case GO_YOGGBRAIN_DOOR_1:
                        YoggSaronBrainDoor1GUID = gameObject->GetGUID();
                    break;
                    case GO_YOGGBRAIN_DOOR_2:
                        YoggSaronBrainDoor2GUID = gameObject->GetGUID();
                        HandleGameObject(NULL, false, gameObject);
                    break;
                    case GO_YOGGBRAIN_DOOR_3:
                        YoggSaronBrainDoor3GUID = gameObject->GetGUID();
                        HandleGameObject(NULL, false, gameObject);
                    break;
                }
            }

            void OnGameObjectRemove(GameObject* gameObject)
            {
                switch (gameObject->GetEntry())
                {
                    case GO_LEVIATHAN_DOOR:
                        AddDoor(gameObject, false);
                        break;
                    case GO_XT_002_DOOR:
                        AddDoor(gameObject, false);
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
                if (FlameLeviathan && FlameLeviathan->isAlive()) // No leviathan, no event triggering ;)
                    switch (eventId)
                    {
                        case EVENT_TOWER_OF_STORM_DESTROYED:
                            FlameLeviathan->AI()->DoAction(ACTION_TOWER_OF_STORM_DESTROYED);
                            break;
                        case EVENT_TOWER_OF_FROST_DESTROYED:
                            FlameLeviathan->AI()->DoAction(ACTION_TOWER_OF_FROST_DESTROYED);
                            break;
                        case EVENT_TOWER_OF_FLAMES_DESTROYED:
                            FlameLeviathan->AI()->DoAction(ACTION_TOWER_OF_FLAMES_DESTROYED);
                            break;
                        case EVENT_TOWER_OF_LIFE_DESTROYED:
                            FlameLeviathan->AI()->DoAction(ACTION_TOWER_OF_LIFE_DESTROYED);
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
                    case BOSS_AURIAYA:
                    case BOSS_FREYA:
                        break;
                    case BOSS_XT002:
                        HandleGameObject(XT002DoorGUID, state != IN_PROGRESS);
                        break;
                    case BOSS_MIMIRON:
                        for (std::list<uint64>::iterator i = MimironDoorGUIDList.begin(); i != MimironDoorGUIDList.end(); i++)
                        {
                            if (GameObject* obj = instance->GetGameObject(*i))
                                obj->SetGoState(state == IN_PROGRESS ? GO_STATE_READY : GO_STATE_ACTIVE );
                        }
                        break;
                    case BOSS_ASSEMBLY_OF_IRON:
                        if (state == NOT_STARTED)
                            HandleGameObject(ArchivumDoorGUID, false);
                        HandleGameObject(IronCouncilEntranceGUID, state != IN_PROGRESS);
                        if (state == DONE)
                            HandleGameObject(ArchivumDoorGUID, true);
                        break;
                    case BOSS_VEZAX:
                        if (state == DONE)
                            HandleGameObject(VezaxDoorGUID, true);
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
                        if (state == IN_PROGRESS)
                            HandleGameObject(KologarnDoorGUID, false);
                        else
                            HandleGameObject(KologarnDoorGUID, true);
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
                            HandleGameObject(HodirStoneDoorGUID, true);
                        }
                        break;
                    case BOSS_THORIM:
                        if (GameObject* obj = instance->GetGameObject(ThorimDoorGUID))
                            obj->SetGoState(state == IN_PROGRESS ? GO_STATE_READY : GO_STATE_ACTIVE);
                        break;
                    case BOSS_ALGALON:
                        if (state == IN_PROGRESS)
                        {
                            HandleGameObject(AlgalonDoorGUID, false);     // Close Door
                            HandleGameObject(AlgalonFloorOOCGUID, true);  // Makes bridge disappear
                            HandleGameObject(AlgalonFloorCOMGUID, false); // Makes round combat floor appear 
                            HandleGameObject(AlgalonBridgeGUID, true);    // Removes collision from bridge
                            HandleGameObject(AlgalonGlobeGUID, true);      // "Roomchanging" 
                            HandleGameObject(AlgalonForceFieldGUID, false);// Invisible Forcefield, prevents escape
                        }
                        else
                        {
                            HandleGameObject(AlgalonDoorGUID, true);
                            HandleGameObject(AlgalonFloorOOCGUID, false);
                            HandleGameObject(AlgalonFloorCOMGUID, true);
                            HandleGameObject(AlgalonBridgeGUID, false);
                            HandleGameObject(AlgalonGlobeGUID, false);
                            HandleGameObject(AlgalonForceFieldGUID, true);

                        }
                        break;
                    case BOSS_YOGGSARON:
                        if (state == IN_PROGRESS)
                            HandleGameObject(YoggSaronDoorGUID, false);
                        else
                            HandleGameObject(YoggSaronDoorGUID, true);
                        break;
                }

                if (GetBossState(BOSS_FREYA) == DONE &&
                    GetBossState(BOSS_MIMIRON) == DONE &&
                    GetBossState(BOSS_HODIR) == DONE &&
                    GetBossState(BOSS_THORIM) == DONE)
                    if (GameObject* go = instance->GetGameObject(WayToYoggGUID))
                        go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
                return true;
                if (GetBossState(BOSS_IGNIS) == DONE && GetBossState(BOSS_RAZORSCALE) == DONE)
                    if (GameObject* go = instance->GetGameObject(XT002DoorGUID))
                        HandleGameObject(XT002DoorGUID, true);
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
                    case DATA_CALL_TRAM:
                        if (GameObject* go = instance->GetGameObject(MimironTrainGUID))
                            go->UseDoorOrButton();
                        break;
                    case DATA_MIMIRON_ELEVATOR:
                        if (GameObject* go = instance->GetGameObject(MimironElevatorGUID))
                            go->SetGoState(GOState(data));
                        break;
                    case DATA_RUNIC_DOOR:
                        if (GameObject* go = instance->GetGameObject(RunicDoorGUID))
                            go->SetGoState(GOState(data));
                        break;
                    case DATA_STONE_DOOR:
                        if (GameObject* go = instance->GetGameObject(StoneDoorGUID))
                            go->SetGoState(GOState(data));
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
                    case DATA_ADD_HELP_FLAG:
                        SupportKeeperFlag |= UlduarKeeperSupport(data);
                        break;
                    case DATA_ALGALON_INTRO:
                        AlgalonIntroDone = data;
                        SaveToDB();
                        break;
                    case DATA_ALGALON_TIMER:
                        {
                            if (SignalTimerState == data)
                                break;
                            switch (data)
                            {
                                case IN_PROGRESS:
                                    SignalTimer = 60000;
                                    SignalTimerMinutes = 60;
                                    DoUpdateWorldState(WORLDSTATE_SHOW_TIMER, 1);
                                    DoUpdateWorldState(WORLDSTATE_ALGALON_TIMER , SignalTimerMinutes);
                                    break;
                                case DONE:
                                    SignalTimer = 0;
                                    SignalTimerMinutes = 0;
                                    DoUpdateWorldState(WORLDSTATE_SHOW_TIMER, 0);
                                    break;
                                default:
                                    break;
                            }

                            SignalTimerState = data;
                            SaveToDB();
                        break;
                        }
                    default:
                        break;
                }
            }

            void SetData64(uint32 /*type*/, uint64 /*data*/)
            {
            }

            uint64 GetData64(uint32 data)
            {
                switch (data)
                {
                    case BOSS_LEVIATHAN:
                        return LeviathanGUID;
                    case BOSS_IGNIS:
                        return IgnisGUID;
                    case BOSS_RAZORSCALE:
                        return RazorscaleGUID;
                    case DATA_RAZORSCALE_CONTROL:
                        return RazorscaleController;
                    case BOSS_XT002:
                        return XT002GUID;
                    case DATA_TOY_PILE_0:
                    case DATA_TOY_PILE_1:
                    case DATA_TOY_PILE_2:
                    case DATA_TOY_PILE_3:
                        return XTToyPileGUIDs[data - DATA_TOY_PILE_0];
                    case BOSS_KOLOGARN:
                        return KologarnGUID;
                    case BOSS_AURIAYA:
                        return AuriayaGUID;
                    case BOSS_MIMIRON:
                        return MimironGUID;
                    case DATA_LEVIATHAN_MK_II:      
                        return LeviathanMKIIGUID;
                    case DATA_VX_001:               
                        return VX001GUID;
                    case DATA_AERIAL_UNIT:          
                        return AerialUnitGUID;
                    case BOSS_HODIR:
                        return HodirGUID;
                    case BOSS_THORIM:
                        return ThorimGUID;
                    case DATA_RUNIC_COLOSSUS:       
                        return RunicColossusGUID;
                    case DATA_RUNE_GIANT:           
                        return RuneGiantGUID;
                    case BOSS_FREYA:
                        return FreyaGUID;
                    case BOSS_VEZAX:
                        return VezaxGUID;
                    // Yogg-Saron
                    case BOSS_YOGGSARON:
                        return YoggSaronGUID;
                    case TYPE_SARA:
                        return SaraGUID;
                    case TYPE_BRAIN_DOOR_1 :
                        return YoggSaronBrainDoor1GUID;
                    case TYPE_BRAIN_DOOR_2 :
                        return YoggSaronBrainDoor2GUID;
                    case TYPE_BRAIN_DOOR_3 :
                        return YoggSaronBrainDoor3GUID;
                    //Algalon the Observer
                    case BOSS_ALGALON:
                        return AlgalonGUID;
                    case GO_ALGALON_DOOR:
                        return AlgalonDoorGUID;
                    case NPC_BRANN_ALGALON:
                        return AlgalonBrannGUID;

                    // Razorscale expedition commander
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

                    // Assembly of Iron
                    case BOSS_STEELBREAKER:
                        return AssemblyGUIDs[0];
                    case BOSS_MOLGEIM:
                        return AssemblyGUIDs[1];
                    case BOSS_BRUNDIR:
                        return AssemblyGUIDs[2];

                    // Freya's Keepers
                    case BOSS_BRIGHTLEAF:
                        return KeeperGUIDs[0];
                    case BOSS_IRONBRANCH:
                        return KeeperGUIDs[1];
                    case BOSS_STONEBARK:
                        return KeeperGUIDs[2];
                }

                return 0;
            }

            uint32 GetData(uint32 type)
            {
                switch (type)
                {
                    case DATA_COLOSSUS:
                        return ColossusData;
                    case DATA_HODIR_RARE_CACHE:
                        return HodirRareCacheData;
                    case DATA_UNBROKEN:
                        return uint32(Unbroken);
                    case DATA_ALGALON_INTRO:
                        return AlgalonIntroDone;
                        break;
                    case DATA_ALGALON_TIMER:
                        return SignalTimerState;
                        break;
                    case DATA_KEEPER_SUPPORT_YOGG:
                        return SupportKeeperFlag;
                        break;
                    default:
                        break;
                }

                return 0;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "U U " << GetBossSaveData() << GetData(DATA_COLOSSUS) << " " << PlayerDeathFlag << " "  << AlgalonIntroDone << " " << SignalTimerState << " " << SignalTimerMinutes;

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
                uint32 data1,data2,data3;

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

                        if (i == DATA_COLOSSUS)
                            SetData(i, tmpState);
                        else
                            SetBossState(i, EncounterState(tmpState));
                    Encounter[i] = tmpState;
                    }
                    loadStream >> data1;
                    loadStream >> data2;
                    loadStream >> data3;

                    SetData(DATA_ALGALON_INTRO, data1);
                    SignalTimerState = data2;
                    SignalTimerMinutes = data3;
                    uint32 tmpState, tmpState2;
                    loadStream >> tmpState >> tmpState2;
                    ColossusData = tmpState;
                    PlayerDeathFlag = tmpState2;
                }

                OUT_LOAD_INST_DATA_COMPLETE;
            }
            void Update(uint32 diff)
            {
                if (SignalTimerState == IN_PROGRESS)
                {
                    if (SignalTimer <= diff)
                    {
                        --SignalTimerMinutes;
                        SignalTimer = 60000;
                        if (SignalTimerMinutes)
                        {
                            DoUpdateWorldState(WORLDSTATE_SHOW_TIMER, 1);
                            DoUpdateWorldState(WORLDSTATE_ALGALON_TIMER, SignalTimerMinutes);
                        }
                        else
                        {
                            SignalTimerState = FAIL;
                            DoUpdateWorldState(WORLDSTATE_SHOW_TIMER, 0);
                            if (Creature* Algalon = instance->GetCreature(AlgalonGUID))
                                Algalon->AI()->DoAction(ACTION_ALGALON_ASCEND);

                            SetBossState(BOSS_ALGALON, FAIL);
                        }
                        SaveToDB();
                    }
                    else
                        SignalTimer -= diff;
                }
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_ulduar_InstanceMapScript(map);
        }
};

class go_call_tram : public GameObjectScript
{
public:
    go_call_tram() : GameObjectScript("go_call_tram") { }

    bool OnGossipHello(Player* /*pPlayer*/, GameObject* pGo)
    {
        InstanceScript* pInstance = pGo->GetInstanceScript();

        if (!pInstance)
            return false;

        switch (pGo->GetEntry())
        {
            case 194914:
            case 194438:
                pInstance->SetData(DATA_CALL_TRAM, 0);
                break;
            case 194912:
            case 194437:
                pInstance->SetData(DATA_CALL_TRAM, 1);
                break;
        }
        return true;
    }
};

void AddSC_instance_ulduar()
{
    new instance_ulduar();
    new go_call_tram();
}
