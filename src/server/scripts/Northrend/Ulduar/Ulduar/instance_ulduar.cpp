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
#include <algorithm>

static DoorData const doorData[] =
{
    {   GO_LEVIATHAN_DOOR, BOSS_LEVIATHAN,    DOOR_TYPE_ROOM, BOUNDARY_S      },
    {   GO_XT_002_DOOR,    BOSS_XT002,        DOOR_TYPE_ROOM, BOUNDARY_S      },
    {   0,                 0,                 DOOR_TYPE_ROOM, BOUNDARY_NONE   }
};

// Used to map boss-identifier to "player-died-in-fight-against"-flag, since not all "bosses" are relevant
static const uint32 BossId_2_PlayerDiedFlag[][2] = 
{
    { BOSS_LEVIATHAN        , DEAD_FLAME_LEVIATHAN  },
    { BOSS_IGNIS            , DEAD_IGNIS            },
    { BOSS_RAZORSCALE       , DEAD_RAZORSCALE       },
    { BOSS_XT002            , DEAD_XT002            },
    { BOSS_ASSEMBLY_OF_IRON , DEAD_ASSEMBLY         },
    { BOSS_STEELBREAKER     , DEAD_NONE             },
    { BOSS_MOLGEIM          , DEAD_NONE             },
    { BOSS_BRUNDIR          , DEAD_NONE             },
    { BOSS_KOLOGARN         , DEAD_KOLOGARN         },
    { BOSS_AURIAYA          , DEAD_AURIAYA          },
    { BOSS_MIMIRON          , DEAD_MIMIRON          },
    { BOSS_HODIR            , DEAD_HODIR            },
    { BOSS_THORIM           , DEAD_THORIM           },
    { BOSS_FREYA            , DEAD_FREYA            },
    { BOSS_BRIGHTLEAF       , DEAD_NONE             },
    { BOSS_IRONBRANCH       , DEAD_NONE             },
    { BOSS_STONEBARK        , DEAD_NONE             },
    { BOSS_VEZAX            , DEAD_VEZAX            },
    { BOSS_YOGGSARON        , DEAD_YOGGSARON        },
    { BOSS_ALGALON          , DEAD_ALGALON          }
};

class instance_ulduar : public InstanceMapScript
{
    public:
        instance_ulduar() : InstanceMapScript(UlduarScriptName, MAP_ULDUAR) { }

        struct instance_ulduar_InstanceMapScript : public InstanceScript
        {
            instance_ulduar_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

        private:
            std::string m_strInstData;

            // 2012/06/24 @DorianGrey - reordered those, due to logical relation (GO to npc and vice versa). Maybe change that again.

            // Leviathan
            uint64 leviathanChestGUID;
            uint64 LeviathanGUID;
            uint64 LeviathanGateGUID;
            uint64 LeviathanDoorGUID;   // used for the laser door behind leviathan only
            std::list<uint64> LeviathanDoorGUIDList;

            // Ignis
            uint64 IgnisGUID;

            // Razorscale
            uint64 RazorscaleGUID;
            uint64 RazorscaleController;
            uint64 RazorHarpoonGUIDs[4];
            uint64 ExpeditionCommanderGUID;

            // XT-002
            uint64 XT002GUID;
            uint64 XT002DoorGUID;
            uint64 XTToyPileGUIDs[4];

            // Assembly of Iron
            uint64 AssemblyGUIDs[3];
            uint64 IronCouncilEntranceGUID;
            uint64 ArchivumDoorGUID;

            // Kologarn
            uint64 KologarnGUID;
            uint64 KologarnChestGUID;
            uint64 KologarnBridgeGUID;
            uint64 KologarnDoorGUID;
            std::set<uint64> mRubbleSpawns;

            // Auriaya
            uint64 AuriayaGUID;

            // Hodir
            uint64 HodirGUID;
            uint64 HodirImageGUID;
            uint64 HodirInDoorGUID;
            uint64 HodirIceDoorGUID;
            uint64 HodirStoneDoorGUID;
            uint64 HodirEntranceDoorGUID;
            uint64 HodirChestGUID;
            uint64 HodirRareCacheGUID;
            
            // Mimiron
            uint64 MimironTrainGUID;
            uint64 MimironImageGUID;
            uint64 MimironGUID;
            uint64 LeviathanMKIIGUID;
            uint64 VX001GUID;
            uint64 AerialUnitGUID;
            uint64 MimironElevatorGUID;
            std::list<uint64> MimironDoorGUIDList;

            // Thorim
            uint64 ThorimCtrlGUID;
            uint64 ThorimGUID;
            uint64 ThorimImageGUID;
            uint64 ThorimLightningFieldGUID;
            uint64 RunicColossusGUID;
            uint64 RuneGiantGUID;
            uint64 RunicDoorGUID;
            uint64 StoneDoorGUID;
            uint64 ThorimChestGUID;
            uint64 ThorimDarkIronPortCullisGUID;

            // Freya
            uint64 FreyaGUID;
            uint64 FreyaImageGUID;
            uint64 ElderBrightleafGUID;
            uint64 ElderIronbranchGUID;
            uint64 ElderStonebarkGUID;
            uint64 FreyaChestGUID;

            // Vezax
            uint64 WayToYoggGUID;
            uint64 VezaxGUID;
            uint64 VezaxDoorGUID;

            // Yogg-Saron
            uint64 YoggSaronCtrlGUID;
            uint64 YoggSaronGUID;
            uint64 SaraGUID;
            uint64 YoggSaronDoorGUID;
            uint64 YoggSaronBrainDoor1GUID;
            uint64 YoggSaronBrainDoor2GUID;
            uint64 YoggSaronBrainDoor3GUID;

            // Algalon
            uint64 AlgalonGUID;
            uint64 AlgalonBridgeGUID;
            uint64 AlgalonBridgeVisualGUID;
            uint64 AlgalonBridgeDoorGUID;
            uint64 AlgalonGlobeGUID;
            uint64 AlgalonDoor1GUID;
            uint64 AlgalonDoor2GUID;
            uint64 AlgalonAccessGUID;
            uint64 AlgalonChestGUID;

            // Creatures
            uint64 KeeperGUIDs[3];
            uint64 DorenGUID;

            // Miscellaneous
            uint32 ColossusData;
            uint32 SupportKeeperFlag;
            uint32 PlayerDeathFlag;
            uint32 AlgalonKillCount;

            uint32 TeamInInstance;
            uint32 HodirRareCacheData;
            uint32 AlgalonCountdown;
            //   62 - not ready to engage, i.e. Yogg-Saron is still alive
            //   61 - ready to engage, not engaged yet
            // < 61 - engaged, timer running
            //    0 - failed

            uint32 CountdownTimer;
            uint8 elderCount;
            bool conSpeedAtory;

        public:
            void Initialize()
            {
                // Pretty please: Use type-safe fill instead of raw memset !
                SetBossNumber(MAX_ENCOUNTER);
                LoadDoorData(doorData);

                // Leviathan
                leviathanChestGUID  = 0;
                LeviathanGUID       = 0;
                LeviathanGateGUID   = 0;
                LeviathanDoorGUID   = 0;

                // Ignis
                IgnisGUID = 0;

                // Razorscale
                RazorscaleGUID          = 0;
                RazorscaleController    = 0;
                ExpeditionCommanderGUID = 0;
                std::fill(RazorHarpoonGUIDs, RazorHarpoonGUIDs + 4, 0);

                // XT-002
                XT002GUID       = 0;
                XT002DoorGUID   = 0;
                std::fill(XTToyPileGUIDs, XTToyPileGUIDs + 4, 0);

                // Assembly of Iron
                std::fill(AssemblyGUIDs, AssemblyGUIDs + 3, 0);
                IronCouncilEntranceGUID = 0;
                ArchivumDoorGUID        = 0;

                // Kologarn
                KologarnGUID        = 0;
                KologarnChestGUID   = 0;
                KologarnBridgeGUID  = 0;
                KologarnDoorGUID    = 0;

                // Auriaya
                AuriayaGUID = 0;

                // Hodir
                HodirGUID               = 0;
                HodirImageGUID          = 0;
                HodirInDoorGUID         = 0;
                HodirIceDoorGUID        = 0;
                HodirStoneDoorGUID      = 0;
                HodirEntranceDoorGUID   = 0;
                HodirChestGUID          = 0;
                HodirRareCacheGUID      = 0;

                // Mimiron
                MimironTrainGUID    = 0;
                MimironGUID         = 0;
                MimironImageGUID    = 0;
                LeviathanMKIIGUID   = 0;
                VX001GUID           = 0;
                AerialUnitGUID      = 0;
                MimironElevatorGUID = 0;

                // Thorim
                ThorimCtrlGUID               = 0;
                ThorimGUID                   = 0;
                ThorimImageGUID              = 0;
                ThorimLightningFieldGUID     = 0;
                RunicColossusGUID            = 0;
                RuneGiantGUID                = 0;
                RunicDoorGUID                = 0;
                StoneDoorGUID                = 0;
                ThorimChestGUID              = 0;
                ThorimDarkIronPortCullisGUID = 0;

                // Freya
                FreyaGUID           = 0;
                FreyaImageGUID      = 0;
                ElderBrightleafGUID = 0;
                ElderIronbranchGUID = 0;
                ElderStonebarkGUID  = 0;
                FreyaChestGUID      = 0;

                // Vezax
                WayToYoggGUID   = 0;
                VezaxGUID       = 0;
                VezaxDoorGUID   = 0;

                // Yogg-Saron
                YoggSaronCtrlGUID       = 0;
                YoggSaronGUID           = 0;
                SaraGUID                = 0;
                YoggSaronDoorGUID       = 0;
                YoggSaronBrainDoor1GUID = 0;
                YoggSaronBrainDoor2GUID = 0;
                YoggSaronBrainDoor3GUID = 0;

                // Algalon
                AlgalonGUID             = 0;
                AlgalonBridgeGUID       = 0;
                AlgalonBridgeVisualGUID = 0;
                AlgalonBridgeDoorGUID   = 0;
                AlgalonGlobeGUID        = 0;
                AlgalonDoor1GUID        = 0;
                AlgalonDoor2GUID        = 0;
                AlgalonAccessGUID       = 0;
                AlgalonChestGUID        = 0;

                // Creatures
                std::fill(KeeperGUIDs, KeeperGUIDs + 3, 0);
                DorenGUID = 0;

                // Miscellaneous
                ColossusData        = 0;
                SupportKeeperFlag   = 0;
                PlayerDeathFlag     = 0;
                AlgalonKillCount    = 0;

                TeamInInstance      = 0;
                HodirRareCacheData  = 0;
                AlgalonCountdown    = 62; // See above why
                CountdownTimer      = 1*MINUTE*IN_MILLISECONDS;
                elderCount          = 0;
                conSpeedAtory       = false;
            }

            void FillInitialWorldStates(WorldPacket& packet)
            {
                packet << static_cast<uint32>(WORLD_STATE_ALGALON_TIMER_ENABLED) << static_cast<uint32>(AlgalonCountdown && AlgalonCountdown < 61);
                packet << static_cast<uint32>(WORLD_STATE_ALGALON_DESPAWN_TIMER) << static_cast<uint32>(std::min<uint32>(AlgalonCountdown, 60)); // cast to uint32 required since std::min returns const uint32&
            }            

            void OnPlayerEnter(Player* /*player*/)
            {
                if (!TeamInInstance)
                    TeamInInstance = GetMajorityTeam();
            }

            void __OnPlayerDeath(Player* /*player*/) 
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; i++)
                {
                    if (GetBossState(UlduarBosses(i)) == IN_PROGRESS)
                    {
                        if (i == BOSS_ALGALON)
                            ++AlgalonKillCount; // Something happens to Algalon on player death, thus count them
                        PlayerDeathFlag |= BossId_2_PlayerDiedFlag[i][1];
                    }
                }  
            }

            void __OnCreatureDeath(Creature* creature)
            {
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
                            DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEVEMENT_CRITERIA_CON_SPEED_ATORY);
                            conSpeedAtory = true;
                        }
                        break;
                    // reward leviathan kill all over the formation grounds area
                    // otherwise, there may occur some problems due to kill-credit since he's killed using vehicles
                    case NPC_LEVIATHAN:
                        {
                            Map::PlayerList const& playerList = instance->GetPlayers();

                            if (playerList.isEmpty())
                                return;

                            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                            {
                                if (Player* player = i->getSource())
                                {
                                    // has been rewarded
                                    if (player->IsAtGroupRewardDistance(creature))
                                        continue;

                                    // is somewhere else
                                    if (player->GetAreaId() != AREA_FORMATION_GROUNDS)
                                        continue;

                                    if (player->isAlive() || !player->GetCorpse())
                                        player->KilledMonsterCredit(NPC_LEVIATHAN, 0);
                                }
                            }
                        }
                        break;
                    default:
                        break;
                }
            }

            void OnUnitDeath(Unit* unit)
            {
                if (Player* player = unit->ToPlayer())
                    __OnPlayerDeath(player);
                else if (Creature* creature = unit->ToCreature())
                    __OnCreatureDeath(creature);
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
                        return !(PlayerDeathFlag & DEAD_ALGALON);
                    default:
                        break;
                }

                // Yogg-Saron
                switch (criteria_id)
                {
                    case ACHIEVEMENT_CRITERIA_THE_ASSASSINATION_OF_KING_LLANE_10:
                    case ACHIEVEMENT_CRITERIA_THE_ASSASSINATION_OF_KING_LLANE_25:
                    {
                        if (GetBossState(BOSS_YOGGSARON) != IN_PROGRESS)
                            return false;

                        if (Creature* ctrl = instance->GetCreature(YoggSaronCtrlGUID))
                            return (ctrl->AI()->GetData(DATA_PORTAL_PHASE) == 0);

                        return false;
                    }
                    case ACHIEVEMENT_CRITERIA_THE_TORTURED_CHAMPION_10:
                    case ACHIEVEMENT_CRITERIA_THE_TORTURED_CHAMPION_25:
                    {
                        if (GetBossState(BOSS_YOGGSARON) != IN_PROGRESS)
                            return false;

                        if (Creature* ctrl = instance->GetCreature(YoggSaronCtrlGUID))
                            return (ctrl->AI()->GetData(DATA_PORTAL_PHASE) == 2);

                        return false;
                    }
                    case ACHIEVEMENT_CRITERIA_FORGING_OF_THE_DEMON_SOUL_10:
                    case ACHIEVEMENT_CRITERIA_FORGING_OF_THE_DEMON_SOUL_25:
                    {
                        if (GetBossState(BOSS_YOGGSARON) != IN_PROGRESS)
                            return false;

                        if (Creature* ctrl = instance->GetCreature(YoggSaronCtrlGUID))
                            return (ctrl->AI()->GetData(DATA_PORTAL_PHASE) == 1);

                        return false;
                    }
                    default:
                        break;
                }
                return false;
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    // Misc. guys
                    case NPC_RUNIC_COLOSSUS:
                        RunicColossusGUID = creature->GetGUID();
                        break;
                    case NPC_RUNE_GIANT:
                        RuneGiantGUID = creature->GetGUID();
                        break;
                    
                    // Flame Leviathan
                    case NPC_LEVIATHAN:
                        LeviathanGUID = creature->GetGUID();
                        // if no colossus is alive and we wiped
                        if (GetData(DATA_COLOSSUS) == 2)
                            creature->GetMotionMaster()->MovePoint(1, Center);
                        break;

                    // Ignis
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

                    // XT002
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
                        break;
                    case NPC_MOLGEIM:
                        AssemblyGUIDs[1] = creature->GetGUID();
                        break;
                    case NPC_BRUNDIR:
                        AssemblyGUIDs[2] = creature->GetGUID();
                        break;
                    case NPC_PROSPECTOR_DOREN:
                        DorenGUID = creature->GetGUID();
                        if (GetBossState(BOSS_ASSEMBLY_OF_IRON) != DONE)
                        {
                            creature->setActive(false);
                            creature->SetVisible(false);
                        }

                        // make sure algalon is spawned after a crash, if he should be
                        if (AlgalonCountdown < 62)
                            if (Creature* algalon = creature->SummonCreature(NPC_ALGALON, 1632.668f, -302.7656f, 417.3211f, 1.530165f))
                                algalon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        break;

                    // Kologarn
                    case NPC_KOLOGARN:
                        KologarnGUID = creature->GetGUID();
                        break;
                    case NPC_KOLOGARN_BRIDGE:
                        // The below hacks are courtesy of the grid/visibility-system
                        // TODO: Check if this is still required
                        // What happens? The NPC as corpse build the bridge, but must not be present until Kologarn was beaten
                        if (GetBossState(BOSS_KOLOGARN) == DONE)
                        {
                            creature->setDeathState(CORPSE);
                            creature->DestroyForNearbyPlayers();
                            creature->UpdateObjectVisibility(true);
                        }
                        else
                        {
                            creature->setDeathState(CORPSE);
                            creature->RemoveCorpse(true);
                        }
                        break;

                    // Auriaya
                    case NPC_AURIAYA:
                        AuriayaGUID = creature->GetGUID();
                        break;

                    // Mimiron
                    case NPC_MIMIRON:
                        MimironGUID = creature->GetGUID();
                        break;
                    case NPC_MIMIRON_IMAGE:
                        MimironImageGUID = creature->GetGUID();
                        creature->SetVisible(false);
                        creature->setActive(false);
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

                    // Hodir
                    case NPC_HODIR:
                        HodirGUID = creature->GetGUID();
                        break;
                    case NPC_HODIR_IMAGE:
                        HodirImageGUID = creature->GetGUID();
                        creature->SetVisible(false);
                        creature->setActive(false);
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

                    // Thorim
                    case NPC_THORIM:
                        ThorimGUID = creature->GetGUID();
                        break;
                    case NPC_THORIM_IMAGE:
                        ThorimImageGUID = creature->GetGUID();
                        creature->SetVisible(false);
                        creature->setActive(false);
                        break;
                    case NPC_THORIM_CTRL:
                        ThorimCtrlGUID = creature->GetGUID();
                        break;
                    case NPC_MERCENARY_CAPTAIN_A:
                        if (TeamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_MERCENARY_CAPTAIN_H, 1692);
                        break;
                    case NPC_MERCENARY_SOLDIER_A:
                        if (TeamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_MERCENARY_SOLDIER_H, 1692);
                        break;

                    // Freya
                    case NPC_FREYA:
                        FreyaGUID = creature->GetGUID();
                        break;
                    case NPC_FREYA_IMAGE:
                        FreyaImageGUID = creature->GetGUID();
                        creature->SetVisible(false);
                        creature->setActive(false);
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

                    // Vezax
                    case NPC_VEZAX:
                        VezaxGUID = creature->GetGUID();
                        break;

                    // Yogg-Saron
                    case NPC_SARA:
                        SaraGUID = creature->GetGUID();
                        break;
                    case NPC_YOGGSARON:
                        YoggSaronGUID = creature->GetGUID();
                        break;
                    case NPC_YOGGSARON_CTRL:
                        YoggSaronCtrlGUID = creature->GetGUID();
                        break;

                    // Algalon
                    case NPC_ALGALON:
                        AlgalonGUID = creature->GetGUID();
                        if (AlgalonCountdown < 62)
                        {
                            creature->setFaction(7);
                            creature->setActive(true);
                        }
                        else
                            creature->SetVisible(false);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* gameObject)
            {
                switch (gameObject->GetEntry())
                {
                    // Leviathan related
                    case GO_LEVIATHAN_DOOR:
                        AddDoor(gameObject, true);
                        // we need only the laser behind leviathan
                        if (gameObject->GetPositionX() > 200.f)
                        {
                            if ((GetBossState(BOSS_LEVIATHAN) == IN_PROGRESS) || (GetBossState(BOSS_LEVIATHAN) == NOT_STARTED && GetData(DATA_COLOSSUS) == 2))
                                gameObject->SetGoState(GO_STATE_READY);
                            LeviathanDoorGUID = gameObject->GetGUID();
                        }
                        break;
                    case GO_LEVIATHAN_GATE:
                        LeviathanGateGUID = gameObject->GetGUID();
                        if ((GetBossState(BOSS_LEVIATHAN) == DONE) || (GetBossState(BOSS_LEVIATHAN) == NOT_STARTED && GetData(DATA_COLOSSUS) == 2))
                            gameObject->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                        break;
                    case GO_LEVIATHAN_CHEST_10:
                    case GO_LEVIATHAN_CHEST_25:
                        leviathanChestGUID = gameObject->GetGUID();
                        break;

                    // Razorscale related
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
                    
                    // XT002 related
                    case GO_XT_002_DOOR:
                        AddDoor(gameObject, true);
                        XT002DoorGUID = gameObject->GetGUID();
                        HandleGameObject(0, GetBossState(BOSS_LEVIATHAN) == DONE, gameObject);
                        break;

                    // Iron-Council related
                    case GO_IRON_COUNCIL_ENTRANCE:
                        IronCouncilEntranceGUID = gameObject->GetGUID();
                        break;
                    case GO_ARCHIVUM_DOOR:
                        ArchivumDoorGUID = gameObject->GetGUID();
                        HandleGameObject(0, GetBossState(BOSS_ASSEMBLY_OF_IRON) == DONE, gameObject);
                        break;

                    // Kologarn related
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
                        HandleGameObject(KologarnDoorGUID, GetBossState(BOSS_ASSEMBLY_OF_IRON)==DONE);
                        break;

                    // Thorim related
                    case GO_THORIM_DARK_IRON_PROTCULLIS:
                        ThorimDarkIronPortCullisGUID = gameObject->GetGUID();
                        break;
                    case GO_THORIM_CHEST_HERO:
                    case GO_THORIM_CHEST:
                        ThorimChestGUID = gameObject->GetGUID();
                        break;
                    case GO_THORIM_LIGHTNING_FIELD:
                        ThorimLightningFieldGUID = gameObject->GetGUID();
                        break;
                    case GO_THORIM_STONE_DOOR:
                        StoneDoorGUID = gameObject->GetGUID();
                        break;
                    case GO_THORIM_RUNIC_DOOR:
                        RunicDoorGUID = gameObject->GetGUID();
                        break;

                    // Hodir related
                    case GO_HODIR_RARE_CACHE_OF_WINTER_HERO:
                    case GO_HODIR_RARE_CACHE_OF_WINTER:
                        HodirRareCacheGUID = gameObject->GetGUID();
                        gameObject->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    case GO_HODIR_CHEST_HERO:
                    case GO_HODIR_CHEST:
                        HodirChestGUID = gameObject->GetGUID();
                        break;
                    case GO_HODIR_OUT_DOOR_ICE:
                        HodirIceDoorGUID = gameObject->GetGUID();
                        if (GetBossState(BOSS_HODIR) == DONE)
                            HandleGameObject(HodirIceDoorGUID, true);
                        break;
                    case GO_HODIR_OUT_DOOR_STONE:
                        HodirStoneDoorGUID = gameObject->GetGUID();
                        if (GetBossState(BOSS_HODIR) == DONE)
                            HandleGameObject(HodirIceDoorGUID, true);
                        break;
                    case GO_HODIR_IN_DOOR_STONE:
                        HodirInDoorGUID = gameObject->GetGUID();
                        break;

                    // Freya related
                    case GO_FREYA_CHEST_HERO:
                    case GO_FREYA_CHEST:
                        FreyaChestGUID = gameObject->GetGUID();
                        break;
                   
                    // Mimiron related
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

                    // Vezax related
                    case GO_WAY_TO_YOGG:
                        WayToYoggGUID = gameObject->GetGUID();
                        if (GetBossState(BOSS_FREYA) == DONE &&
                            GetBossState(BOSS_MIMIRON) == DONE &&
                            GetBossState(BOSS_HODIR) == DONE &&
                            GetBossState(BOSS_THORIM) == DONE)
                            gameObject->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
                        break;
                    case GO_VEZAX_DOOR:
                        VezaxDoorGUID = gameObject->GetGUID();
                        if (GetBossState(BOSS_VEZAX) == DONE)
                            HandleGameObject(0, true, gameObject);
                        else
                            HandleGameObject(0, false, gameObject);
                        break;

                    // Yogg-Saron related
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
                    case GO_YOGGBRAIN_DOOR_3:
                        YoggSaronBrainDoor3GUID = gameObject->GetGUID();
                        HandleGameObject(NULL, false, gameObject);
                        break;

                    // Algalon related
                    case GO_ALGALON_PLATFORM:
                        HandleGameObject(NULL, false, gameObject);
                        break;
                    case GO_ALGALON_BRIDGE:
                        AlgalonBridgeGUID = gameObject->GetGUID();
                        HandleGameObject(NULL, false, gameObject);
                        break;
                    case GO_ALGALON_B_VISUAL:
                        AlgalonBridgeVisualGUID = gameObject->GetGUID();
                        HandleGameObject(NULL, false, gameObject);
                        break;
                    case GO_ALGALON_B_DOOR:
                        AlgalonBridgeDoorGUID = gameObject->GetGUID();
                        HandleGameObject(NULL, true, gameObject);
                        break;
                    case GO_ALGALON_GLOBE:
                        AlgalonGlobeGUID = gameObject->GetGUID();
                        HandleGameObject(NULL, false, gameObject);
                        break;
                    case GO_ALGALON_DOOR_1:
                        AlgalonDoor1GUID = gameObject->GetGUID();
                        HandleGameObject(NULL, AlgalonCountdown < 62 ? true : false, gameObject);
                        break;
                    case GO_ALGALON_DOOR_2:
                        AlgalonDoor2GUID = gameObject->GetGUID();
                        HandleGameObject(NULL, AlgalonCountdown < 62 ? true : false, gameObject);
                        break;
                    case GO_ALGALON_ACCESS:
                        AlgalonAccessGUID = gameObject->GetGUID();
                        if (AlgalonCountdown < 62)
                        {
                            gameObject->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            gameObject->SetGoState(GO_STATE_ACTIVE);
                        }
                        break;
                    case GO_GIFT_OF_THE_OBSERVER_10:
                    case GO_GIFT_OF_THE_OBSERVER_25:
                        AlgalonChestGUID = gameObject->GetGUID();
                        break;
                    default:
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
                        default:
                            break;
                    }
            }


            bool SetBossState(uint32 type, EncounterState state)
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                if (UlduarBosses(type) <= BOSS_ALGALON)
                    if (GetBossState(UlduarBosses(type)) != DONE)
                        InstanceScript::SetBossState(UlduarBosses(type), state);

                if (state == DONE)
                    SaveToDB();

                switch (type)
                {
                    case BOSS_LEVIATHAN:
                        for (std::list<uint64>::iterator i = LeviathanDoorGUIDList.begin(); i != LeviathanDoorGUIDList.end(); ++i)
                        {
                            if (GameObject* gameObject = instance->GetGameObject(*i))
                                gameObject->SetGoState(state == IN_PROGRESS ? GO_STATE_READY : GO_STATE_ACTIVE );
                        }

                        if (GameObject* gameObject = instance->GetGameObject(LeviathanDoorGUID))
                        {
                            /*if (state == NOT_STARTED || state == IN_PROGRESS)
                                gameObject->SetGoState(GO_STATE_READY);
                            else*/
                                gameObject->SetGoState(GO_STATE_ACTIVE);
                        }

                        if (state == DONE)
                        {
                            if (GameObject* gameObject = instance->GetGameObject(leviathanChestGUID))
                                gameObject->SetRespawnTime(gameObject->GetRespawnDelay());

                            HandleGameObject(XT002DoorGUID, true);
                        }
                        break;
                    case BOSS_IGNIS:
                    case BOSS_RAZORSCALE:
                    case BOSS_XT002:
                        // Door should closed during these fights :o
                        HandleGameObject(XT002DoorGUID, state != IN_PROGRESS);
                        break;
                    case BOSS_ASSEMBLY_OF_IRON:
                        // Prevent fleeing :o
                        HandleGameObject(IronCouncilEntranceGUID, state != IN_PROGRESS);
                        if (state == DONE)
                        {
                            HandleGameObject(ArchivumDoorGUID, true);
                            if (Creature* doren = instance->GetCreature(DorenGUID))
                            {
                                doren->SetVisible(true);
                                doren->setActive(true);
                            }
                        }
                        break;
                    case BOSS_AURIAYA:
                        if (state == DONE)
                            if (GameObject* train = instance->GetGameObject(MimironTrainGUID))
                                train->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    case BOSS_FREYA:
                        if (state == DONE)
                        {
                            if (Creature* freya = instance->GetCreature(FreyaImageGUID))
                            {
                                freya->SetVisible(true);
                                freya->setActive(true);
                            }
                        }
                        break;
                    case BOSS_MIMIRON:
                        for (std::list<uint64>::iterator i = MimironDoorGUIDList.begin(); i != MimironDoorGUIDList.end(); ++i)
                        {
                            if (GameObject* gameobject = instance->GetGameObject(*i))
                                gameobject->SetGoState(state == IN_PROGRESS ? GO_STATE_READY : GO_STATE_ACTIVE);
                        }
                        if (state == DONE)
                        {
                            if (Creature* mimiron = instance->GetCreature(MimironImageGUID))
                            {
                                mimiron->SetVisible(true);
                                mimiron->setActive(true);
                            }
                        }
                        break;
                    case BOSS_VEZAX:
                        if (state == DONE)
                            HandleGameObject(VezaxDoorGUID, true);
                        break;
                    case BOSS_YOGGSARON:
                        if (state == IN_PROGRESS)
                            HandleGameObject(YoggSaronDoorGUID, false);
                        else
                            HandleGameObject(YoggSaronDoorGUID, true);
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
                        /* Due to HordeGuides, the door should be open when the encounter is in progress. (It opens after finishing AoI.)
                        if (state == IN_PROGRESS)
                            HandleGameObject(KologarnDoorGUID, false);
                        else
                            HandleGameObject(KologarnDoorGUID, true);
                        */
                        break;
                    case BOSS_HODIR:
                        if (state == DONE)
                        {
                            HandleGameObject(HodirIceDoorGUID, true);
                            HandleGameObject(HodirStoneDoorGUID, true);
                            HandleGameObject(HodirInDoorGUID, true);
                            if (GetData(DATA_HODIR_RARE_CACHE))
                            {
                                if (GameObject* HodirRareCache = instance->GetGameObject(HodirRareCacheGUID))
                                    HodirRareCache->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            }
                            else
                            {
                                if (GameObject* HodirChest = instance->GetGameObject(HodirChestGUID))
                                    HodirChest->SetRespawnTime(HodirChest->GetRespawnDelay());
                            }

                            if (Creature* hodir = instance->GetCreature(HodirImageGUID))
                            {
                                hodir->SetVisible(true);
                                hodir->setActive(true);
                            }
                        }
                        HandleGameObject(HodirEntranceDoorGUID, state != IN_PROGRESS);
                        break;
                    case BOSS_THORIM:
                        if (state == DONE)
                        {
                            if (GameObject* gameObject = instance->GetGameObject(ThorimChestGUID))
                                gameObject->SetRespawnTime(gameObject->GetRespawnDelay());
                            if (GameObject* gameObject = instance->GetGameObject(ThorimLightningFieldGUID))
                                gameObject->SetGoState(state == IN_PROGRESS ? GO_STATE_READY : GO_STATE_ACTIVE);

                            if (Creature* thorim = instance->GetCreature(ThorimImageGUID))
                            {
                                thorim->SetVisible(true);
                                thorim->setActive(true);
                            }
                        }
                        break;
                    case BOSS_ALGALON:
                        switch (state)
                        {
                            case SPECIAL:
                                if (Creature* algalon = instance->GetCreature(AlgalonGUID))
                                {
                                    algalon->setFaction(7);
                                    algalon->setActive(true);
                                    algalon->SetVisible(true);
                                    DoUpdateWorldState(WORLD_STATE_ALGALON_TIMER_ENABLED, 1);
                                    DoUpdateWorldState(WORLD_STATE_ALGALON_DESPAWN_TIMER, 60);
                                }
                                HandleGameObject(AlgalonDoor1GUID, true);
                                HandleGameObject(AlgalonDoor2GUID, true);
                                AlgalonCountdown = 61;
                                SaveToDB();
                                break;
                            case NOT_STARTED:
                                HandleGameObject(AlgalonGlobeGUID, false);
                                HandleGameObject(AlgalonBridgeGUID, false);
                                HandleGameObject(AlgalonBridgeVisualGUID, false);
                                HandleGameObject(AlgalonBridgeDoorGUID, true);
                                break;
                            case IN_PROGRESS:
                                if (AlgalonCountdown > 60)
                                {
                                    AlgalonCountdown = 60;
                                    DoUpdateWorldState(WORLD_STATE_ALGALON_TIMER_ENABLED, 1);
                                    DoUpdateWorldState(WORLD_STATE_ALGALON_DESPAWN_TIMER, AlgalonCountdown);
                                    SaveToDB();
                                }
                                HandleGameObject(AlgalonGlobeGUID, true);
                                HandleGameObject(AlgalonBridgeGUID, true);
                                HandleGameObject(AlgalonBridgeVisualGUID, true);
                                HandleGameObject(AlgalonBridgeDoorGUID, false);
                                break;
                            case DONE:
                                AlgalonCountdown = 0;
                                DoUpdateWorldState(WORLD_STATE_ALGALON_TIMER_ENABLED, 0);
                                HandleGameObject(AlgalonGlobeGUID, false);
                                HandleGameObject(AlgalonBridgeGUID, false);
                                HandleGameObject(AlgalonBridgeVisualGUID, false);
                                HandleGameObject(AlgalonBridgeDoorGUID, true);
                                if (GameObject* chest = instance->GetGameObject(AlgalonChestGUID))
                                    chest->SetRespawnTime(chest->GetRespawnDelay());
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }
                if (GetBossState(BOSS_FREYA) == DONE &&
                    GetBossState(BOSS_MIMIRON) == DONE &&
                    GetBossState(BOSS_HODIR) == DONE &&
                    GetBossState(BOSS_THORIM) == DONE)
                    if (instance->GetGameObject(WayToYoggGUID))
                        HandleGameObject(WayToYoggGUID, true);

                return true;
            }

            EncounterState GetBossState(uint32 id)
            {
                if (UlduarBosses(id) <= BOSS_ALGALON)
                    return InstanceScript::GetBossState(UlduarBosses(id));
                return NOT_STARTED;
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
                            go->SetGoState(GOState(data));
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
                    case DATA_ADD_HELP_FLAG:
                        SupportKeeperFlag |= UlduarKeeperSupport(data);
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
                        if (Creature* Leviathan = instance->GetCreature(LeviathanGUID))
                            Leviathan->AI()->SetData(type, data);
                        break;
                    default:
                        break;
                }
            }

            uint64 GetData64(uint32 data) const
            {
                switch (data)
                {                    
                    case BOSS_IGNIS:                return IgnisGUID;
                    case BOSS_KOLOGARN:             return KologarnGUID;
                    case BOSS_AURIAYA:              return AuriayaGUID;
                    case BOSS_HODIR:                return HodirGUID;
                    case BOSS_THORIM:               return ThorimGUID;
                    case BOSS_FREYA:                return FreyaGUID;
                    case BOSS_VEZAX:                return VezaxGUID;
                    case BOSS_ALGALON:              return AlgalonGUID;

                    // Leviathan
                    case BOSS_LEVIATHAN:            return LeviathanGUID;
                    case DATA_RUNIC_COLOSSUS:       return RunicColossusGUID;
                    case DATA_RUNE_GIANT:           return RuneGiantGUID;

                    // Razorscale
                    case BOSS_RAZORSCALE:           return RazorscaleGUID;
                    case DATA_RAZORSCALE_CONTROL:   return RazorscaleController;
                    case DATA_EXPEDITION_COMMANDER: return ExpeditionCommanderGUID;
                    case GO_RAZOR_HARPOON_1:        return RazorHarpoonGUIDs[0];
                    case GO_RAZOR_HARPOON_2:        return RazorHarpoonGUIDs[1];
                    case GO_RAZOR_HARPOON_3:        return RazorHarpoonGUIDs[2];
                    case GO_RAZOR_HARPOON_4:        return RazorHarpoonGUIDs[3];

                    // XT002
                    case BOSS_XT002:                return XT002GUID;
                    case DATA_TOY_PILE_0:
                    case DATA_TOY_PILE_1:
                    case DATA_TOY_PILE_2:
                    case DATA_TOY_PILE_3:           return XTToyPileGUIDs[data - DATA_TOY_PILE_0];

                    // Assembly of Iron
                    case BOSS_STEELBREAKER:         return AssemblyGUIDs[0];
                    case BOSS_MOLGEIM:              return AssemblyGUIDs[1];
                    case BOSS_BRUNDIR:              return AssemblyGUIDs[2];

                    // Kologarn
                    case GO_KOLOGARN_DOOR:          return KologarnDoorGUID;

                    // Freya
                    case BOSS_BRIGHTLEAF:           return KeeperGUIDs[0];
                    case BOSS_IRONBRANCH:           return KeeperGUIDs[1];
                    case BOSS_STONEBARK:            return KeeperGUIDs[2];
                    case NPC_FREYA_IMAGE:           return FreyaImageGUID;

                    // Hodir
                    case NPC_HODIR_IMAGE:           return HodirImageGUID;
                    case GO_HODIR_IN_DOOR_STONE:    return HodirInDoorGUID;

                    // Thorim
                    case GO_THORIM_DARK_IRON_PROTCULLIS: return ThorimDarkIronPortCullisGUID;
                    case GO_THORIM_LIGHTNING_FIELD:      return ThorimLightningFieldGUID;
                    case NPC_THORIM_CTRL:                return ThorimCtrlGUID;
                    case NPC_THORIM_IMAGE:               return ThorimImageGUID;

                    // Mimiron
                    case BOSS_MIMIRON:              return MimironGUID;
                    case NPC_MIMIRON_IMAGE:         return MimironImageGUID;
                    case DATA_LEVIATHAN_MK_II:      return LeviathanMKIIGUID;
                    case DATA_VX_001:               return VX001GUID;
                    case DATA_AERIAL_UNIT:          return AerialUnitGUID;

                    // Yogg-Saron
                    case NPC_YOGGSARON_CTRL:        return YoggSaronCtrlGUID;
                    case BOSS_YOGGSARON:            return YoggSaronGUID;
                    case BOSS_SARA:                 return SaraGUID;
                    case DATA_BRAIN_DOOR_1:         return YoggSaronBrainDoor1GUID;
                    case DATA_BRAIN_DOOR_2:         return YoggSaronBrainDoor2GUID;
                    case DATA_BRAIN_DOOR_3:         return YoggSaronBrainDoor3GUID;

                    // Algalon
                    case DATA_SIGILDOOR_01:         return AlgalonDoor1GUID;
                    case DATA_SIGILDOOR_02:         return AlgalonDoor2GUID;
                    default: break;
                }

                return 0;
            }

            uint32 GetData(uint32 type) const
            {
                switch (type)
                {
                    case DATA_COLOSSUS:
                        return ColossusData;
                    case DATA_KEEPER_SUPPORT_YOGG:
                        return SupportKeeperFlag;
                    case DATA_HODIR_RARE_CACHE:
                        return HodirRareCacheData;
                    case DATA_UNBROKEN:
                        if (Creature* Leviathan = instance->GetCreature(LeviathanGUID))
                            return Leviathan->AI()->GetData(type);
                    default:
                        break;
                }
                return 0;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "U U " << GetBossSaveData() << GetData(DATA_COLOSSUS) << " " << SupportKeeperFlag << " " << PlayerDeathFlag << " " << AlgalonCountdown;

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
                    for (uint32 i = 0; i < MAX_ENCOUNTER; i++)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }

                    loadStream >> ColossusData;
                    loadStream >> SupportKeeperFlag;
                    loadStream >> PlayerDeathFlag;
                    loadStream >> AlgalonCountdown;
                }
                OUT_LOAD_INST_DATA_COMPLETE;
            }

            // Here: Only handles Algalon's timer
            void Update(uint32 diff)
            {
                // Note: AlgalonCountdown goes down to 61 once the encounter got started
                if (AlgalonCountdown > 0 && AlgalonCountdown < 61)
                {
                    if (CountdownTimer < diff)
                    {
                        AlgalonCountdown--;

                        if (AlgalonCountdown)
                        {
                            DoUpdateWorldState(WORLD_STATE_ALGALON_TIMER_ENABLED, 1);
                            DoUpdateWorldState(WORLD_STATE_ALGALON_DESPAWN_TIMER, AlgalonCountdown);
                        }
                        else
                        {
                            if (Creature* algalon = instance->GetCreature(AlgalonGUID))
                                algalon->AI()->DoAction(1);
                        }
                        SaveToDB();
                        CountdownTimer += 1*MINUTE*IN_MILLISECONDS;
                    }
                    CountdownTimer -= diff;
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

            if (pInstance->GetBossState(BOSS_AURIAYA) != DONE)
                return false;

            switch (pGo->GetEntry())
            {
                // Activate
                case 194437:    // [ok]
                case 194912:
                    pInstance->SetData(DATA_CALL_TRAM, 0);
                    break;
                // Call
                case 194438:
                case 194914:    // [ok]
                    pInstance->SetData(DATA_CALL_TRAM, 0);
                    break;
                default:
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
