/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "Map.h"
#include "PoolMgr.h"
#include "icecrown_citadel.h"

#define MAX_ENCOUNTER      12

const Position SpawnLoc[]=
{
    {4571.521f, 2481.815f, 343.365f, 3.166f} //spawn pos
};

DoorData const doorData[] =
{
    {GO_LORD_MARROWGAR_S_ENTRANCE,           DATA_LORD_MARROWGAR_EVENT,        DOOR_TYPE_ROOM,    BOUNDARY_N   },
    {GO_LORD_MARROWGAR_ICE_WALL,             DATA_LORD_MARROWGAR_EVENT,        DOOR_TYPE_PASSAGE, BOUNDARY_NONE},
    {GO_LORD_MARROWGAR_ICE_WALL_1,           DATA_LORD_MARROWGAR_EVENT,        DOOR_TYPE_PASSAGE, BOUNDARY_NONE},
    {GO_ORATORY_OF_THE_DAMNED_ENTRANCE,      DATA_DEATHWHISPER_EVENT,          DOOR_TYPE_ROOM,    BOUNDARY_N   },
    {GO_DEATHBRINGER_S_DOOR,                 DATA_SAURFANG_EVENT,              DOOR_TYPE_PASSAGE, BOUNDARY_NONE},
    {GO_ORANGE_PLAGUE_MONSTER_ENTRANCE,      DATA_FESTERGUT_EVENT,             DOOR_TYPE_ROOM,    BOUNDARY_E   },
    {GO_GREEN_PLAGUE_MONSTER_ENTRANCE,       DATA_ROTFACE_EVENT,               DOOR_TYPE_ROOM,    BOUNDARY_E   },
    {GO_SCIENTIST_ENTRANCE,                  DATA_PROFESSOR_PUTRICIDE_EVENT,   DOOR_TYPE_ROOM,    BOUNDARY_E   },
    {GO_CRIMSON_HALL_DOOR,                   DATA_BLOOD_PRINCE_COUNCIL_EVENT,  DOOR_TYPE_ROOM,    BOUNDARY_S   },
    {GO_BLOOD_ELF_COUNCIL_DOOR,              DATA_BLOOD_PRINCE_COUNCIL_EVENT,  DOOR_TYPE_PASSAGE, BOUNDARY_W   },
    {GO_BLOOD_ELF_COUNCIL_DOOR_RIGHT,        DATA_BLOOD_PRINCE_COUNCIL_EVENT,  DOOR_TYPE_PASSAGE, BOUNDARY_E   },
    {GO_BLOOD_QUEEN_BLOOD_BARRIER,           DATA_BLOOD_QUEEN_LANA_THEL_EVENT, DOOR_TYPE_ROOM,    BOUNDARY_S   },
    {GO_DOODAD_ICECROWN_GRATE_01,            DATA_BLOOD_QUEEN_LANA_THEL_EVENT, DOOR_TYPE_PASSAGE, BOUNDARY_NONE},
    {GO_GREEN_DRAGON_BOSS_ENTRANCE,          DATA_SISTER_SVALNA_EVENT,         DOOR_TYPE_PASSAGE, BOUNDARY_S   },
    {GO_GREEN_DRAGON_BOSS_ENTRANCE,          DATA_VALITHRIA_DREAMWALKER_EVENT, DOOR_TYPE_ROOM,    BOUNDARY_N   },
    {GO_GREEN_DRAGON_BOSS_EXIT,              DATA_VALITHRIA_DREAMWALKER_EVENT, DOOR_TYPE_PASSAGE, BOUNDARY_S   },
    {GO_SINDRAGOSA_ENTRANCE_DOOR,            DATA_SINDRAGOSA_EVENT,            DOOR_TYPE_ROOM,    BOUNDARY_S   },
    {GO_SINDRAGOSA_SHORTCUT_ENTRANCE_DOOR,   DATA_SINDRAGOSA_EVENT,            DOOR_TYPE_PASSAGE, BOUNDARY_E   },
    {GO_SINDRAGOSA_SHORTCUT_EXIT_DOOR,       DATA_SINDRAGOSA_EVENT,            DOOR_TYPE_PASSAGE, BOUNDARY_NONE},
    {GO_SINDRAGOSA_ICE_WALL,                 DATA_SINDRAGOSA_EVENT,            DOOR_TYPE_ROOM,    BOUNDARY_SE  }, 
    {GO_SINDRAGOSA_ICE_WALL,                 DATA_SINDRAGOSA_EVENT,            DOOR_TYPE_ROOM,    BOUNDARY_SW  }, 
    {0,                                      0,                                DOOR_TYPE_ROOM,    BOUNDARY_NONE} // END
};

// this doesnt have to only store questgivers, also can be used for related quest spawns
struct WeeklyQuest
{
    uint32 creatureEntry;
    uint32 questId[2];  // 10 and 25 man versions
};

// when changing the content, remember to update SetData, DATA_BLOOD_QUICKENING_STATE case for NPC_ALRIN_THE_AGILE index
WeeklyQuest const WeeklyQuestData[WeeklyNPCs] =
{
    {NPC_INFILTRATOR_MINCHAR,         {QUEST_DEPROGRAMMING_10,                 QUEST_DEPROGRAMMING_25                }}, // Deprogramming
    {NPC_KOR_KRON_LIEUTENANT,         {QUEST_SECURING_THE_RAMPARTS_10,         QUEST_SECURING_THE_RAMPARTS_25        }}, // Securing the Ramparts
    {NPC_ROTTING_FROST_GIANT_10,      {QUEST_SECURING_THE_RAMPARTS_10,         QUEST_SECURING_THE_RAMPARTS_25        }}, // Securing the Ramparts
    {NPC_ROTTING_FROST_GIANT_25,      {QUEST_SECURING_THE_RAMPARTS_10,         QUEST_SECURING_THE_RAMPARTS_25        }}, // Securing the Ramparts
    {NPC_ALCHEMIST_ADRIANNA,          {QUEST_RESIDUE_RENDEZVOUS_10,            QUEST_RESIDUE_RENDEZVOUS_25           }}, // Residue Rendezvous
    {NPC_ALRIN_THE_AGILE,             {QUEST_BLOOD_QUICKENING_10,              QUEST_BLOOD_QUICKENING_25             }}, // Blood Quickening
    {NPC_INFILTRATOR_MINCHAR_BQ,      {QUEST_BLOOD_QUICKENING_10,              QUEST_BLOOD_QUICKENING_25             }}, // Blood Quickening
    {NPC_MINCHAR_BEAM_STALKER,        {QUEST_BLOOD_QUICKENING_10,              QUEST_BLOOD_QUICKENING_25             }}, // Blood Quickening
    {NPC_VALITHRIA_DREAMWALKER_QUEST, {QUEST_RESPITE_FOR_A_TORNMENTED_SOUL_10, QUEST_RESPITE_FOR_A_TORNMENTED_SOUL_25}}, // Respite for a Tormented Soul
};

class instance_icecrown_citadel : public InstanceMapScript
{
    public:
        instance_icecrown_citadel() : InstanceMapScript("instance_icecrown_citadel", 631) { }

        struct instance_icecrown_citadel_InstanceMapScript : public InstanceScript
        {
            instance_icecrown_citadel_InstanceMapScript(InstanceMap* pMap) : InstanceScript(pMap)
            {
                Initialize();
                LoadDoorData(doorData);
                uiDifficulty = pMap->GetDifficulty();

                uiLordMarrowgar         = 0;
                uiDeathbringerSaurfang  = 0;
                uiSaurfangEventNPC      = 0;
                uiFestergut             = 0;
                uiRotface               = 0;
                uiProfessorPutricide    = 0;
                uiPrinceValanar         = 0;
                uiPrinceKeleseth        = 0;
                uiPrinceTaldaram        = 0;
                uiBloodQueenLanathel    = 0;
                uiValithriaDreamwalker  = 0;
                uiValithriaAlternative  = 0;
                uiValithriaCombatTrigger= 0;
                uiLichKing              = 0;
                uiTirion                = 0;
                uiSaurfangCache         = 0;
                uiTerenasFighter        = 0;
                uiSpiritWarden          = 0;
                teamInInstance          = 0;
                CrokScourgebaneGUID     = 0;
                memset(CrokCaptainGUIDs, 0, 4 * sizeof(uint64));
                SisterSvalnaGUID        = 0;

                uiNecroticStack         = 0;
                uiBloodCouncilController= 0;
                uiBeenWaiting           = 0;
                uiNeckDeep              = 0;
                uiIceWall1              = 0;
                uiIceWall2              = 0;
                uiMarrowgarEntrance     = 0;
                uiLadyDeathwisperTransporter = 0;
                uiOratoryDoor           = 0;
                uiSaurfangDoor          = 0;
                uiOrangeMonsterDoor     = 0;
                uiGreenMonsterDoor      = 0;
                uiProfCollisionDoor     = 0;
                uiPutricideTable        = 0;
                uiOrangePipe            = 0;
                uiGreenPipe             = 0;
                uiOozeValve             = 0;
                uiGasValve              = 0;
                uiProfDoorOrange        = 0;
                uiProfDoorGreen         = 0;
                uiRotfaceEntrance       = 0;
                uiFestergurtEntrance    = 0;
                uiProfessorDoor         = 0;
                uiBloodwingDoor         = 0;
                uiCrimsonHallDoor1      = 0;
                uiCrimsonHallDoorRight  = 0;
                uiCrimsonHallDoorLeft   = 0;
                uiBloodQueenGrate       = 0;
                uiFrostwingDoor         = 0;
                uiValithriaDoorEntrance = 0;
                uiValithriaDoorExit     = 0;
                uiSindragosaShortcutExitDoor = 0;
                uiRoostDoor1            = 0;
                uiRoostDoor2            = 0;
                uiRoostDoor3            = 0;
                uiRoostDoor4            = 0;
                uiValithriaTransporter  = 0;
                uiSindragosaTransporter = 0;
                uiSindragosaDoor1       = 0;
                uiSindragosaShortcutEntranceDoor       = 0;
                uiSindragosaIceWall     = 0;
                uiFirstTp               = 0;
                uiMarrowgarTp           = 0;
                uiFlightWarTp           = 0;
                uiSaurfangTp            = 0;
                uiCitadelTp             = 0;
                uiSindragosaTp          = 0;
                uiLichTp                = 0;

                uiSpiritAlarm1          = 0;
                uiSpiritAlarm2          = 0;
                uiSpiritAlarm3          = 0;
                uiSpiritAlarm4          = 0;

                uiDeathboundWard1       = 0;
                uiDeathboundWard2       = 0;
                uiDeathboundWard3       = 0;
                uiDeathboundWard4       = 0;

                uiUpperSpireLever       = 0;

                uiSindragosa            = 0; 
                uiSpinestalker          = 0; 
                uiRimefang              = 0; 
                frostwyrms              = 0; 
                spinestalkerTrash       = 0; 
                rimefangTrash           = 0; 

                oozeValveActivated      = 0;
                gasValveActivated       = 0;

                isBonedEligible         = true;
                isOozeDanceEligible     = true;
                isNauseaEligible        = 0;
                isOrbWhispererEligible  = 0;
                isPortalJockeyEligible  = 0;

                uiTeleportToOratoryOfTheDamnedActivated = 0;
                uiTeleportToRampartOfSkullsActivated = 0;
                uiTeleportToDeathbringersRiseActivated = 0;
                uiTeleportToUpperSpireActivated = 0;
                uiTeleportToSindragosasLairActivated = 0;
                uiTeleportToFrozenThroneActivated = 0;

                uiIceShard1             = 0;
                uiIceShard2             = 0;
                uiIceShard3             = 0;
                uiIceShard4             = 0;
                uiFrostyEdgeInner       = 0;
                uiFrostyEdgeOuter       = 0;
                uiEdgeDestroyWarning    = 0;
                uilavaman               = 0;
                uihangingman            = 0;
                heroicAttempts          = 50;
                teamInInstance          = 0;

                coldflameJetsState      = NOT_STARTED;

                bloodQuickeningState = NOT_STARTED;
                bloodQuickeningTimer = 0;
                bloodQuickeningMinutes = 0;
            }

            void Initialize()
            {
                memset(&uiEncounter, 0, sizeof(uiEncounter));
                //While Gunship Battle is not implemented
                uiEncounter[DATA_GUNSHIP_BATTLE_EVENT] = DONE;
            }

            void FillInitialWorldStates(WorldPacket& data)
            {
                data << uint32(WORLDSTATE_SHOW_TIMER)         << uint32(bloodQuickeningState == IN_PROGRESS);
                data << uint32(WORLDSTATE_EXECUTION_TIME)     << uint32(bloodQuickeningMinutes);
                data << uint32(WORLDSTATE_SHOW_ATTEMPTS)      << uint32(instance->IsHeroic());
                data << uint32(WORLDSTATE_ATTEMPTS_REMAINING) << uint32(heroicAttempts);
                data << uint32(WORLDSTATE_ATTEMPTS_MAX)       << uint32(MaxHeroicAttempts);
            };

            bool IsEncounterInProgress() const
            {
                if (!instance->GetPlayersCountExceptGMs())
                    return false;
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (uiEncounter[i] == IN_PROGRESS)
                        return true;
                return false;
            }

            void OnPlayerEnter(Player* player)
            {
                if (!teamInInstance)
                    teamInInstance = player->GetTeam();
            }

            void OnCreatureCreate(Creature* creature)
            {
                if (!teamInInstance)
                {
                Map::PlayerList const &players = instance->GetPlayers();
                if (!players.isEmpty())
                    if (Player* pPlayer = players.begin()->getSource())
                        teamInInstance = pPlayer->GetTeam();
                }
                switch(creature->GetEntry())
                {
                    case NPC_OOZE_COVERED_TENTACLE_STALKER:
                    case NPC_SLIMY_TENTACLE_STALKER:
                    case NPC_ORANGE_GAS_STALKER:
                    case NPC_TEAR_GAS_STALKER:
                        creature->SetReactState(REACT_PASSIVE);
                        break;
                    case NPC_KOR_KRON_GENERAL:
                        if (teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_ALLIANCE_COMMANDER, ALLIANCE);
                        break;
                    case NPC_TORTUNOK:
                        if (teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_ALANA_MOONSTRIKE, ALLIANCE);
                        break;
                    case NPC_GERARDO_THE_SUAVE:
                        if (teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_TALAN_MOONSTRIKE, ALLIANCE);
                        break;
                    case NPC_UVLUS_BANEFIRE:
                        if (teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_MALFUS_GRIMFROST, ALLIANCE);
                        break;
                    case NPC_IKFIRUS_THE_VILE:
                        if (teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_YILI, ALLIANCE);
                        break;
                    case NPC_VOL_GUK:
                        if (teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_JEDEBIA, ALLIANCE);
                        break;
                    case NPC_HARAGG_THE_UNSEEN:
                        if (teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_NIBY_THE_ALMIGHTY, ALLIANCE);
                        break;
                    case NPC_GARROSH_HELLSCREAM:
                        if (teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_KING_VARIAN_WRYNN, ALLIANCE);
                        break;
                    case NPC_SE_HIGH_OVERLORD_SAURFANG:
                        if (teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_SE_MURADIN_BRONZEBEARD, ALLIANCE, creature->GetCreatureData());
                    case NPC_SE_MURADIN_BRONZEBEARD:
                        uiSaurfangEventNPC = creature->GetGUID();
                        creature->LastUsedScriptID = creature->GetScriptId();
                        if (uiEncounter[DATA_SAURFANG_EVENT] != DONE && uiEncounter[DATA_SAURFANG_EVENT] != IN_PROGRESS)
                            creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        break;
                    case NPC_SE_KOR_KRON_REAVER:
                        if (teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_SE_SKYBREAKER_MARINE, ALLIANCE);
                        break;
                    case NPC_LORD_MARROWGAR:
                        uiLordMarrowgar = creature->GetGUID();
                        //Lord Marrowgar has lard hitbox
                        creature->SetFloatValue(UNIT_FIELD_COMBATREACH, 10.0f);
                        break;
                    case NPC_DEATHBRINGER_SAURFANG:
                        uiDeathbringerSaurfang = creature->GetGUID();
                        break;
                    case NPC_FROST_FREEZE_TRAP:
                        coldflameJets.insert(creature->GetGUID());
                        break;
                    case NPC_FESTERGUT:
                        uiFestergut = creature->GetGUID();
                        break;
                    case NPC_ROTFACE:
                        uiRotface = creature->GetGUID();
                        break;
                    case NPC_PROFESSOR_PUTRICIDE:
                        uiProfessorPutricide = creature->GetGUID();
                        break;
                    case NPC_PRINCE_VALANAR_ICC:
                        uiPrinceValanar = creature->GetGUID();
                        creature->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
                        break;
                    case NPC_PRINCE_KELESETH_ICC:
                        uiPrinceKeleseth = creature->GetGUID();
                        creature->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
                        break;
                    case NPC_PRINCE_TALDARAM_ICC:
                        uiPrinceTaldaram = creature->GetGUID();
                        creature->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
                        break;
                    case NPC_BLOOD_ORB_CONTROLLER:
                        uiBloodCouncilController = creature->GetGUID();
                        break;
                    case NPC_BLOOD_QUEEN_LANA_THEL:
                        uiBloodQueenLanathel = creature->GetGUID();
                        creature->SetReactState(REACT_DEFENSIVE);
                        break;
                    case NPC_CROK_SCOURGEBANE:
                        CrokScourgebaneGUID = creature->GetGUID();
                        break;
                    // we can only do this because there are no gaps in their entries
                    case NPC_CAPTAIN_ARNATH:
                    case NPC_CAPTAIN_BRANDON:
                    case NPC_CAPTAIN_GRONDEL:
                    case NPC_CAPTAIN_RUPERT:
                        CrokCaptainGUIDs[creature->GetEntry()-NPC_CAPTAIN_ARNATH] = creature->GetGUID();
                        break;
                    case NPC_SISTER_SVALNA:
                        SisterSvalnaGUID = creature->GetGUID();
                        break;
                    case NPC_VALITHRIA_DREAMWALKER:
                        uiValithriaDreamwalker = creature->GetGUID();
                        break;
                    case NPC_VALITHRIA_ALTERNATIVE:
                        uiValithriaAlternative = creature->GetGUID();
                        break;
                    case NPC_COMBAT_TRIGGER:
                    {
                        uiValithriaCombatTrigger = creature->GetGUID();
                        creature->SetReactState(REACT_AGGRESSIVE);
                        creature->SetSpeed(MOVE_RUN, 0.0f, true);
                        creature->SetSpeed(MOVE_WALK, 0.0f, true);
                        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);
                        creature->SetVisible(false);
                        break;
                    }
                    case NPC_SINDRAGOSA: 
                        uiSindragosa = creature->GetGUID(); 
                        break; 
                    case NPC_SPINESTALKER: 
                        uiSpinestalker = creature->GetGUID(); 
                        if (!creature->isDead()) 
                            ++frostwyrms; 
                        break; 
                    case NPC_RIMEFANG: 
                        uiRimefang = creature->GetGUID(); 
                        if (!creature->isDead()) 
                            ++frostwyrms; 
                        break;
                    case NPC_DEATHBOUND_WARD:
                    {
                        float x, y;
                        creature->GetPosition(x, y);
                        if      (fabs(x - (-193.786f)) < 10.0f && fabs(y - 2290.22f) < 10.0f)
                            uiDeathboundWard1 = creature->GetGUID();
                        else if (fabs(x - (-194.007f)) < 10.0f && fabs(y - 2137.95f) < 10.0f)
                            uiDeathboundWard2 = creature->GetGUID();
                        else if (fabs(x - (-300.354f)) < 10.0f && fabs(y - 2242.18f) < 10.0f)
                            uiDeathboundWard3 = creature->GetGUID();
                        else if (fabs(x - (-300.566f)) < 10.0f && fabs(y - 2182.60f) < 10.0f)
                            uiDeathboundWard4 = creature->GetGUID();
                        creature->SetReactState(REACT_PASSIVE);
                        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE);
                        break;
                    }
                    case NPC_LICH_KING:
                    {
                        uiLichKing = creature->GetGUID();
                        break;
                    }
                    case NPC_TIRION_ICC:
                    {
                        uiTirion = creature->GetGUID();
                        break;
                    }
                    case NPC_TERENAS_FIGHTER:
                    {
                        uiTerenasFighter = creature->GetGUID();
                        break;
                    }
                    case NPC_SPIRIT_WARDEN:
                    {
                        uiSpiritWarden = creature->GetGUID();
                        break;
                    }
                }
            }

            // Weekly quest spawn prevention
            uint32 GetCreatureEntry(uint32 /*guidLow*/, CreatureData const* data)
            {
                uint32 entry = data->id;
                switch (entry)
                {
                    case NPC_INFILTRATOR_MINCHAR:
                    case NPC_KOR_KRON_LIEUTENANT:
                    case NPC_ALCHEMIST_ADRIANNA:
                    case NPC_ALRIN_THE_AGILE:
                    case NPC_INFILTRATOR_MINCHAR_BQ:
                    case NPC_MINCHAR_BEAM_STALKER:
                    case NPC_VALITHRIA_DREAMWALKER_QUEST:
                    {
                        for (uint8 questIndex = 0; questIndex < WEEKLY_NPCS; ++questIndex)
                        {
                            if (WeeklyQuestData[questIndex].creatureEntry == entry)
                            {
                                uint8 diffIndex = instance->GetSpawnMode() & 1;
                                if (!sPoolMgr->IsSpawnedObject<Quest>(WeeklyQuestData[questIndex].questId[diffIndex]))
                                    entry = 0;
                                break;
                            }
                        }
                        break;
                    }
                    default:
                        break;
                }

                return entry;
            }

            void OnCreatureRemove(Creature* creature)
            {
                if (creature->GetEntry() == NPC_FROST_FREEZE_TRAP)
                    coldflameJets.erase(creature->GetGUID());
            }

            void OnCreatureDeath(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    case NPC_YMIRJAR_BATTLE_MAIDEN:
                    case NPC_YMIRJAR_DEATHBRINGER:
                    case NPC_YMIRJAR_FROSTBINDER:
                    case NPC_YMIRJAR_HUNTRESS:
                    case NPC_YMIRJAR_WARLORD:
                        if (Creature* crok = instance->GetCreature(CrokScourgebaneGUID))
                            crok->AI()->SetGUID(creature->GetGUID(), ACTION_VRYKUL_DEATH);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go)
            {
                if (go)
                {
                    Position pos;
                    go->GetPosition(&pos);
                    gameObjectPositions[go->GetGUID()] = pos;
                }
                switch (go->GetEntry())
                {
                    //Lower Spire
                    case GO_SPIRIT_ALARM1:
                    {
                        uiSpiritAlarm1 = go->GetGUID();
                        break;
                    }
                    case GO_SPIRIT_ALARM2:
                    {
                        uiSpiritAlarm2 = go->GetGUID();
                        break;
                    }
                    case GO_SPIRIT_ALARM3:
                    {
                        uiSpiritAlarm3 = go->GetGUID();
                        go->SetPhaseMask(2, true);
                        break;
                    }
                    case GO_SPIRIT_ALARM4:
                    {
                        uiSpiritAlarm4 = go->GetGUID();
                        go->SetPhaseMask(2, true);
                        break;
                    }
                    //Lord Marrowgar
                    case GO_LORD_MARROWGAR_ICE_WALL:
                    {
                        uiIceWall1 = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_LORD_MARROWGAR_EVENT] == DONE, go);
                        break;
                    }
                    case GO_LORD_MARROWGAR_ICE_WALL_1:
                    {
                        uiIceWall2 = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_LORD_MARROWGAR_EVENT] == DONE, go);
                        break;
                    }
                    case GO_LORD_MARROWGAR_S_ENTRANCE:
                    {
                        uiMarrowgarEntrance = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_LORD_MARROWGAR_EVENT] != IN_PROGRESS, go);
                        break;
                    }
                    //Lady Deathwhisper
                    case GO_ORATORY_OF_THE_DAMNED_ENTRANCE:
                    {
                        uiOratoryDoor = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_DEATHWHISPER_EVENT] != IN_PROGRESS && uiEncounter[DATA_LORD_MARROWGAR_EVENT] == DONE, go);
                        break;
                    }
                    case GO_LADY_DEATHWHISPER_ELEVATOR:
                    {
                        uiLadyDeathwisperTransporter = go->GetGUID();
                        if (uiEncounter[DATA_DEATHWHISPER_EVENT] == DONE)
                        {
                            go->SetUInt32Value(GAMEOBJECT_LEVEL, 0);
                            go->SetGoState(GO_STATE_READY);
                        }
                        break;
                    }
                    //Deathbringer Saurfang
                    case GO_DEATHBRINGER_S_DOOR:
                    {
                        uiSaurfangDoor = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_SAURFANG_EVENT] == DONE, go);
                        break;
                    }
                    case GO_DEATHBRINGER_S_CACHE_10N:
                    case GO_DEATHBRINGER_S_CACHE_25N:
                    case GO_DEATHBRINGER_S_CACHE_10H:
                    case GO_DEATHBRINGER_S_CACHE_25H:
                    {
                        uiSaurfangCache = go->GetGUID();
                        break;
                    }
                    //Upper Reaches
                    case GO_BLOODWING_DOOR:
                    {
                        uiBloodwingDoor = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_SAURFANG_EVENT] == DONE, go);
                        break;
                    }
                    case GO_FROSTWING_DOOR:
                    {
                        uiFrostwingDoor = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_SAURFANG_EVENT] == DONE, go);
                        break;
                    }
                    case GO_PLAGUE_SIGIL:
                    {
                        uiPlagueSigil = go->GetGUID();
                        go->SetGoState(uiEncounter[DATA_PROFESSOR_PUTRICIDE_EVENT] == DONE ? GO_STATE_READY : GO_STATE_ACTIVE);
                        break;
                    }
                    case GO_BLOODWING_SIGIL:
                    {
                        uiBloodwingSigil = go->GetGUID();
                        go->SetGoState(uiEncounter[DATA_BLOOD_QUEEN_LANA_THEL_EVENT] == DONE ? GO_STATE_READY : GO_STATE_ACTIVE);
                        break;
                    }
                    case GO_FROSTWING_SIGIL:
                    {
                        uiFrostwingSigil = go->GetGUID();
                        go->SetGoState(uiEncounter[DATA_SINDRAGOSA_EVENT] == DONE ? GO_STATE_READY : GO_STATE_ACTIVE);
                        break;
                    }
                    case GO_INCONSPICUOUS_LEVER:
                    {
                        uiUpperSpireLever = go->GetGUID();
                        HandleGameObject(NULL, false, go);
                        break;
                    }

                    //Plagueworks
                    case GO_ORANGE_PLAGUE_MONSTER_ENTRANCE:
                    {
                        uiOrangeMonsterDoor = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_FESTERGUT_EVENT] != IN_PROGRESS, go);
                        break;
                    }
                    case GO_GREEN_PLAGUE_MONSTER_ENTRANCE:
                    {
                        uiGreenMonsterDoor = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_ROTFACE_EVENT] != IN_PROGRESS, go);
                        break;
                    }
                    case GO_SCIENTIST_AIRLOCK_DOOR_COLLISION:
                    {
                        uiProfCollisionDoor = go->GetGUID();
                        HandleGameObject(NULL, oozeValveActivated && gasValveActivated, go);
                        break;
                    }
                    case GO_SCIENTIST_AIRLOCK_DOOR_ORANGE:
                    {
                        uiProfDoorOrange = go->GetGUID();
                        if (gasValveActivated == SPECIAL)
                            go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                        else
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    }
                    case GO_SCIENTIST_AIRLOCK_DOOR_GREEN:
                    {
                        uiProfDoorGreen = go->GetGUID();
                        if (oozeValveActivated == SPECIAL)
                            go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                        else
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    }
                    case GO_DOODAD_ICECROWN_ORANGETUBES02:
                    {
                        uiOrangePipe = go->GetGUID();
                        if (gasValveActivated == SPECIAL)
                            go->SetGoState(GO_STATE_ACTIVE);
                        else
                            go->SetGoState(GO_STATE_READY);
                        break;
                    }
                    case GO_DOODAD_ICECROWN_GREENTUBES02:
                    {
                        uiGreenPipe = go->GetGUID();
                        if (oozeValveActivated == SPECIAL)
                            go->SetGoState(GO_STATE_ACTIVE);
                        else
                            go->SetGoState(GO_STATE_READY);
                        break;
                    }
                    case GO_SCIENTIST_ENTRANCE:
                    {
                        uiProfessorDoor = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_PROFESSOR_PUTRICIDE_EVENT] != IN_PROGRESS, go);
                        break;
                    }
                    case GO_DRINK_ME:
                    {
                        uiPutricideTable = go->GetGUID();
                        if (uiEncounter[DATA_PROFESSOR_PUTRICIDE_EVENT] == DONE)
                            go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                        break;
                    }
                    case GO_OOZE_VALVE:
                    {
                        uiOozeValve = go->GetGUID();
                        if (oozeValveActivated == SPECIAL)
                            go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                        else
                            if (uiEncounter[DATA_FESTERGUT_EVENT] == DONE && uiEncounter[DATA_ROTFACE_EVENT] == DONE)
                                go->SetGoState(GO_STATE_READY);
                            else
                                go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    }
                    case GO_GAS_VALVE:
                    {
                        uiGasValve = go->GetGUID();
                        if (gasValveActivated == SPECIAL)
                            go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                        else
                            if (uiEncounter[DATA_FESTERGUT_EVENT] == DONE && uiEncounter[DATA_ROTFACE_EVENT] == DONE)
                                go->SetGoState(GO_STATE_READY);
                            else
                                go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    }

                    //Crimson Hall
                    //Blood Prince Council
                    case GO_CRIMSON_HALL_DOOR:
                    {
                        uiCrimsonHallDoor1 = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_BLOOD_PRINCE_COUNCIL_EVENT] != IN_PROGRESS, go);
                        break;
                    }
                    case GO_BLOOD_ELF_COUNCIL_DOOR:
                    {
                        uiCrimsonHallDoorLeft = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_BLOOD_PRINCE_COUNCIL_EVENT] == DONE, go);
                        break;
                    }
                    case GO_BLOOD_ELF_COUNCIL_DOOR_RIGHT:
                    {
                        uiCrimsonHallDoorRight = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_BLOOD_PRINCE_COUNCIL_EVENT] == DONE, go);
                        break;
                    }
                    //Blood Queen Lana'thel
                    case GO_BLOOD_QUEEN_BLOOD_BARRIER:
                    {
                        uiBloodQueenBloodBarrier = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_BLOOD_QUEEN_LANA_THEL_EVENT] != IN_PROGRESS, go);
                        break;
                    }
                    case GO_DOODAD_ICECROWN_GRATE_01:
                    {
                        uiBloodQueenGrate = go->GetGUID();
                        go->SetGoState(uiEncounter[DATA_BLOOD_QUEEN_LANA_THEL_EVENT] == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                        break;
                    }

                    //Frostwing Halls
                    //Valithria Dreamwalker
                    case GO_DREAMWALKER_CACHE_10_N:
                    case GO_DREAMWALKER_CACHE_25_N:
                    case GO_DREAMWALKER_CACHE_10_H:
                    case GO_DREAMWALKER_CACHE_25_H:
                    {
                        uiDreamwalkerCache = go->GetGUID();
                        break;
                    }
                    case GO_GREEN_DRAGON_BOSS_ENTRANCE:
                    {
                        uiValithriaDoorEntrance = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_VALITHRIA_DREAMWALKER_EVENT] != IN_PROGRESS, go);
                        break;
                    }
                    case GO_GREEN_DRAGON_BOSS_EXIT:
                    {
                        uiValithriaDoorExit = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_VALITHRIA_DREAMWALKER_EVENT] == DONE, go);
                        break;
                    }
                    case GO_DREAMWALKER_DOOR_1:
                    {
                        uiRoostDoor1 = go->GetGUID();
                        break;
                    }
                    case GO_DREAMWALKER_DOOR_2:
                    {
                        uiRoostDoor2 = go->GetGUID();
                        break;
                    }
                    case GO_DREAMWALKER_DOOR_3:
                    {
                        uiRoostDoor3 = go->GetGUID();
                        break;
                    }
                    case GO_DREAMWALKER_DOOR_4:
                    {
                        uiRoostDoor4 = go->GetGUID();
                        break;
                    }
                    case GO_VALITHRIA_ELEVATOR:
                    {
                        uiValithriaTransporter = go->GetGUID();
                        if (uiEncounter[DATA_VALITHRIA_DREAMWALKER_EVENT] == DONE)
                        {
                            go->SetUInt32Value(GAMEOBJECT_LEVEL, 0);
                            go->SetGoState(GO_STATE_READY);
                        }
                        break;
                    }
                    //Sindragosa                   
                    case GO_SINDRAGOSA_ENTRANCE_DOOR:
                    {
                        uiSindragosaDoor1 = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_VALITHRIA_DREAMWALKER_EVENT] == DONE, go);
                        break;
                    }
                    case GO_SINDRAGOSA_SHORTCUT_ENTRANCE_DOOR:
                    {
                        uiSindragosaShortcutEntranceDoor = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_SINDRAGOSA_EVENT] == DONE, go);
                        break;
                    }
                    case GO_SINDRAGOSA_SHORTCUT_EXIT_DOOR:
                    {
                        uiSindragosaShortcutExitDoor = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_SINDRAGOSA_EVENT] == DONE, go);
                        break;
                    }
                    case GO_SINDRAGOSA_ICE_WALL:
                    {
                        uiSindragosaIceWall = go->GetGUID();
                        HandleGameObject(NULL, uiEncounter[DATA_SINDRAGOSA_EVENT] != IN_PROGRESS, go);
                        break;
                    }
                    case GO_SINDRAGOSA_ELEVATOR:
                    {
                        uiSindragosaTransporter = go->GetGUID();
                        if (uiEncounter[DATA_SINDRAGOSA_EVENT] == DONE)
                        {
                            go->SetUInt32Value(GAMEOBJECT_LEVEL, 0);
                            go->SetGoState(GO_STATE_READY);
                        }
                        break;
                    }

                    //Lich King
                    case GO_LAVAMAN:
                    {
                        uilavaman = go->GetGUID();
                        if (uiEncounter[DATA_LICH_KING_EVENT] == DONE)
                            go->SetRespawnTime(5*DAY);
                        break;
                    }
                    case GO_HANGINGMAN:
                    {
                        uihangingman = go->GetGUID();
                        break;
                    }
                    case GO_ICE_SHARD_1:
                    {
                        uiIceShard1 = go->GetGUID();
                        go->SetGoState(uiEncounter[DATA_LICH_KING_EVENT] == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                        break;
                    }
                    case GO_ICE_SHARD_2:     
                    {
                        uiIceShard2 = go->GetGUID();
                        go->SetGoState(uiEncounter[DATA_LICH_KING_EVENT] == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                        break;
                    }
                    case GO_ICE_SHARD_3:
                    {
                        uiIceShard3 = go->GetGUID();
                        go->SetGoState(uiEncounter[DATA_LICH_KING_EVENT] == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                        break;
                    }
                    case GO_ICE_SHARD_4:
                    {
                        uiIceShard4 = go->GetGUID();
                        go->SetGoState(uiEncounter[DATA_LICH_KING_EVENT] == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                        break;
                    }
                    case GO_FROSTY_EDGE_OUTER:
                    {
                        uiFrostyEdgeOuter = go->GetGUID();
                        go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    }
                    case GO_FROSTY_EDGE_INNER:
                    {
                        uiFrostyEdgeInner = go->GetGUID();
                        go->SetGoState(GO_STATE_READY);
                        break;
                    }
                    case GO_EDGE_DESTROY_WARNING:
                    {
                        uiEdgeDestroyWarning = go->GetGUID();
                        go->SetGoState(GO_STATE_READY);
                        break;
                    }

                    //Teleports
                    case GO_TELEPORT_LIGHT_S_HAMMER:
                    {
                        uiFirstTp = go->GetGUID();
                        MakeObjectClickable(go, uiEncounter[DATA_LORD_MARROWGAR_EVENT] == DONE);
                        go->SetGoState(uiEncounter[DATA_LORD_MARROWGAR_EVENT] == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                        break;
                    }
                    case GO_TELEPORT_ORATORY_OF_THE_DAMNED:
                    {
                        uiMarrowgarTp = go->GetGUID();
                        MakeObjectClickable(go, uiEncounter[DATA_LORD_MARROWGAR_EVENT] == DONE);
                        go->SetGoState(uiEncounter[DATA_LORD_MARROWGAR_EVENT] == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                        break;
                    }
                    case GO_TELEPORT_RAMPART_OF_SKULLS:
                    {
                        uiFlightWarTp = go->GetGUID();
                        MakeObjectClickable(go, uiEncounter[DATA_DEATHWHISPER_EVENT] == DONE);
                        go->SetGoState(uiEncounter[DATA_DEATHWHISPER_EVENT] == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                        break;
                    }
                    case GO_TELEPORT_DEATHBRINGER_RISE:
                    {
                        uiSaurfangTp = go->GetGUID();
                        MakeObjectClickable(go, uiEncounter[DATA_DEATHWHISPER_EVENT] == DONE);
                        go->SetGoState(uiEncounter[DATA_DEATHWHISPER_EVENT] == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                        break;
                    }
                    case GO_TELEPORT_UPPER_SPIRE:
                    {
                        uiCitadelTp = go->GetGUID();
                        MakeObjectClickable(go, uiEncounter[DATA_SAURFANG_EVENT] == DONE);
                        HandleGameObject(NULL, false, go);
                        break;
                    }
                    case GO_TELEPORT_SINDRAGOSA_S_LAIR:
                    {
                        uiSindragosaTp = go->GetGUID();
                        MakeObjectClickable(go, uiEncounter[DATA_VALITHRIA_DREAMWALKER_EVENT] == DONE);
                        HandleGameObject(NULL, false, go);
                        break;
                    }
                    case GO_TELEPORT_FROZEN_THRONE:
                    {
                        uiLichTp = go->GetGUID();
                        bool bAllOthersAreDone = true;
                        for (uint8 i = 0; i <= 11 && bAllOthersAreDone; ++i)
                            bAllOthersAreDone &= (uiEncounter[i] == DONE);
                        MakeObjectClickable(go, bAllOthersAreDone);
                        go->SetGoState(bAllOthersAreDone ? GO_STATE_ACTIVE : GO_STATE_READY);
                        break;
                    }
                }
            }

            uint64 GetData64(uint32 type)
            {
                switch(type)
                {
                    case GUID_LORD_MARROWGAR:                   return uiLordMarrowgar;
                    case GUID_SAURFANG:                         return uiDeathbringerSaurfang;
                    case GUID_SAURFANG_EVENT_NPC:               return uiSaurfangEventNPC;
                    case GUID_FESTERGUT:                        return uiFestergut;
                    case GUID_ROTFACE:                          return uiRotface;
                    case GUID_PROFESSOR_PUTRICIDE:              return uiProfessorPutricide;
                    case GUID_PRINCE_VALANAR_ICC:               return uiPrinceValanar;
                    case GUID_PRINCE_KELESETH_ICC:              return uiPrinceKeleseth;
                    case GUID_PRINCE_TALDARAM_ICC:              return uiPrinceTaldaram;
                    case GUID_BLOOD_QUEEN_LANA_THEL:            return uiBloodQueenLanathel;
                    case GUID_VALITHRIA_DREAMWALKER:            return uiValithriaDreamwalker;
                    case GUID_VALITHRIA_ALTERNATIVE:            return uiValithriaAlternative;
                    case GUID_VALITHRIA_COMBAT_TRIGGER:         return uiValithriaCombatTrigger;
                    case GUID_SINDRAGOSA:                       return uiSindragosa; 
                    case GUID_SPINESTALKER:                     return uiSpinestalker; 
                    case GUID_RIMEFANG:                         return uiRimefang; 
                    case GUID_LICH_KING:                        
                    {
                        if (!uiLichKing || !instance->GetCreature(uiLichKing))
                            instance->LoadGrid(428.6f, -2123.88f);
                        return uiLichKing;
                    }
                    case GUID_TIRION:                           return uiTirion;
                    case GUID_BLOOD_PRINCES_CONTROL:            return uiBloodCouncilController;
                    case GUID_PUTRICIDE_TABLE:                  return uiPutricideTable;
                    case GUID_SINDRAGOSA_ENTRANCE_DOOR:         return uiSindragosaDoor1;

                    case GUID_TELEPORT_LIGHTS_HAMMER:          
                    {
                        if (!uiFirstTp || !instance->GetGameObject(uiFirstTp))
                            instance->LoadGrid(-17.0711f, 2211.47f);
                        return uiFirstTp;
                    }
                    case GUID_TELEPORT_ORATORY_OF_THE_DAMNED:   
                    {
                        if (!uiMarrowgarTp || !instance->GetGameObject(uiMarrowgarTp))
                            instance->LoadGrid(-503.62f, 2211.47f);
                        return uiMarrowgarTp;
                    }
                    case GUID_TELEPORT_RAMPART_OF_SKULLS:    
                    {
                        if (!uiFlightWarTp || !instance->GetGameObject(uiFlightWarTp))
                            instance->LoadGrid(-615.145f, 2211.47f);
                        return uiFlightWarTp;
                    }
                    case GUID_TELEPORT_DEATHBRINGERS_RISE:    
                    {
                        if (!uiSaurfangTp || !instance->GetGameObject(uiSaurfangTp))
                            instance->LoadGrid(-549.131f, 2211.29f);
                        return uiSaurfangTp;
                    }
                    case GUID_TELEPORT_UPPER_SPIRE:           
                    {
                        if (!uiCitadelTp || !instance->GetGameObject(uiCitadelTp))
                            instance->LoadGrid(4199.35f, 2769.42f);
                        return uiCitadelTp;
                    }
                    case GUID_TELEPORT_SINDRAGOSAS_LAIR:      
                    {
                        if (!uiSindragosaTp || !instance->GetGameObject(uiSindragosaTp))
                            instance->LoadGrid(4356.58f, 2565.75f);
                        return uiSindragosaTp;
                    }
                    case GUID_TELEPORT_FROZEN_THRONE:         
                    {
                        if (!uiLichTp || !instance->GetGameObject(uiLichTp))
                            instance->LoadGrid(4356.93f, 2769.41f);
                        return uiLichTp;
                    }
                    case GUID_PROF_COLLISION_DOOR:              return uiProfCollisionDoor;
                    case GUID_PROF_ORANGE_DOOR:                 return uiOrangeMonsterDoor;
                    case GUID_PROF_GREEN_DOOR:                  return uiGreenMonsterDoor;

                    case GUID_SPIRIT_ALARM1:                    return uiSpiritAlarm1;
                    case GUID_SPIRIT_ALARM2:                    return uiSpiritAlarm2;
                    case GUID_SPIRIT_ALARM3:                    return uiSpiritAlarm3;
                    case GUID_SPIRIT_ALARM4:                    return uiSpiritAlarm4;

                    case GUID_LAVAMAN:                          return uilavaman;
                    case GUID_HANGINGMAN:                       return uihangingman;

                    case GUID_DEATHBOUND_WARD1:                 return uiDeathboundWard1;
                    case GUID_DEATHBOUND_WARD2:                 return uiDeathboundWard2;
                    case GUID_DEATHBOUND_WARD3:                 return uiDeathboundWard3;
                    case GUID_DEATHBOUND_WARD4:                 return uiDeathboundWard4;

                    case GUID_INCONSPICUOUS_LEVER:
                    {
                        if (!uiUpperSpireLever || !instance->GetGameObject(uiUpperSpireLever))
                            instance->LoadGrid(4231.39f, 2765.97f);
                        return uiUpperSpireLever;
                    }
                    case GUID_ICE_SHARD_1:
                        return uiIceShard1;
                    case GUID_ICE_SHARD_2:
                        return uiIceShard2;
                    case GUID_ICE_SHARD_3:
                        return uiIceShard3;
                    case GUID_ICE_SHARD_4:
                        return uiIceShard4;
                    case GUID_FROSTY_EDGE_OUTER:
                        return uiFrostyEdgeOuter;
                    case GUID_FROSTY_EDGE_INNER:
                        return uiFrostyEdgeInner;
                    case GUID_EDGE_DESTROY_WARNING:
                        return uiEdgeDestroyWarning;
                    case GUID_TERENAS_FIGHTER:
                        return uiTerenasFighter;
                    case GUID_SPIRIT_WARDEN:
                        return uiSpiritWarden;
                    case GUID_DEATHBRINGER_S_DOOR:
                        return uiSaurfangDoor;
                    case GUID_CROK_SCOURGEBANE:
                        return CrokScourgebaneGUID;
                    case GUID_CAPTAIN_ARNATH:
                    case GUID_CAPTAIN_BRANDON:
                    case GUID_CAPTAIN_GRONDEL:
                    case GUID_CAPTAIN_RUPERT:
                        return CrokCaptainGUIDs[type-GUID_CAPTAIN_ARNATH];
                    case GUID_SISTER_SVALNA:
                        return SisterSvalnaGUID;
                }
                return 0;
            }

            uint32 GetCompletedEncounterMask() const
            {
                uint32 mask = 0;
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (GetBossState(i) == DONE)
                        mask |= 1 << i;

                return mask;
            }

            void MakeObjectClickable(GameObject *obj, bool clickable = true)
            {
                if (clickable)
                    obj->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                else
                    obj->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
            }

            void MakeObjectClickable(const uint32 objectDataId, bool clickable = true)
            {
                uint64 objGUID = GetData64(objectDataId);
                GameObject *obj = instance->GetGameObject(objGUID);
                if (!obj)
                {
                    instance->LoadGrid(gameObjectPositions[objGUID].GetPositionX(), gameObjectPositions[objGUID].GetPositionY());
                    obj = instance->GetGameObject(objGUID);
                }
                if (!obj)
                    return;
                MakeObjectClickable(obj, clickable);
            }


            void EnableObject(const uint32 teleportId, GOState state)
            {
                if (GameObject *teleport = instance->GetGameObject(GetData64(teleportId)))
                    teleport->SetGoState(state);
            }

            void SetData(uint32 type, uint32 data)
            {
                switch(type)
                {
                    case DATA_LORD_MARROWGAR_EVENT:
                    {
                        HandleGameObject(uiMarrowgarEntrance, data != IN_PROGRESS);
                        if(data == DONE)
                        {
                            MakeObjectClickable(GUID_TELEPORT_LIGHTS_HAMMER);
                            EnableObject(GUID_TELEPORT_LIGHTS_HAMMER, data == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                            MakeObjectClickable(GUID_TELEPORT_ORATORY_OF_THE_DAMNED);
                            HandleGameObject(uiIceWall1, true);
                            HandleGameObject(uiIceWall2, true);
                            HandleGameObject(uiOratoryDoor, true);
                        }
                        uiEncounter[DATA_LORD_MARROWGAR_EVENT] = data;
                        break;
                    }
                    case DATA_DEATHWHISPER_EVENT:
                    {
                        HandleGameObject(uiOratoryDoor, data != IN_PROGRESS);
                        if(data == DONE)
                        {
                            MakeObjectClickable(GUID_TELEPORT_RAMPART_OF_SKULLS);
                            EnableObject(GUID_TELEPORT_RAMPART_OF_SKULLS, data == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                            MakeObjectClickable(GUID_TELEPORT_DEATHBRINGERS_RISE);
                            EnableObject(GUID_TELEPORT_DEATHBRINGERS_RISE, data == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                            HandleGameObject(uiOratoryDoor, true);
                            if (GameObject* go = instance->GetGameObject(uiLadyDeathwisperTransporter))
                            {
                                go->SetUInt32Value(GAMEOBJECT_LEVEL, 0);
                                go->SetGoState(GO_STATE_READY);
                            }
                        }
                        uiEncounter[DATA_DEATHWHISPER_EVENT] = data;
                        break;
                    }
                    /*case DATA_GUNSHIP_BATTLE_EVENT:
                        switch(data)
                        {
                            case DONE:
                                break;
                            case NOT_STARTED:
                                break;
                        }
                        uiEncounter[DATA_GUNSHIP_BATTLE_EVENT] = data;
                        break;*/
                    case DATA_SAURFANG_EVENT:
                    {
                        //Preload the area around the Upper Spire teleport
                        instance->LoadGrid(4199.35f, 2769.42f);
                        MakeObjectClickable(GUID_TELEPORT_DEATHBRINGERS_RISE, data != IN_PROGRESS);
                        EnableObject(GUID_TELEPORT_DEATHBRINGERS_RISE, data == IN_PROGRESS ? GO_STATE_READY : GO_STATE_ACTIVE);
                        if (data == DONE)
                        {
                            MakeObjectClickable(GUID_TELEPORT_UPPER_SPIRE);
                            if (GameObject* pChest = instance->GetGameObject(uiSaurfangCache))
                                pChest->SetRespawnTime(pChest->GetRespawnDelay());
                            HandleGameObject(uiSaurfangDoor, true);
                            HandleGameObject(uiBloodwingDoor, true);
                            HandleGameObject(uiFrostwingDoor, true);
                        }
                        uiEncounter[DATA_SAURFANG_EVENT] = data;
                        break;
                    }
                    case DATA_FESTERGUT_EVENT:
                    {
                        HandleGameObject(uiOrangeMonsterDoor, data != IN_PROGRESS);
                        uiEncounter[DATA_FESTERGUT_EVENT] = data;
                        if (uiEncounter[DATA_ROTFACE_EVENT] == DONE && uiEncounter[DATA_FESTERGUT_EVENT] == DONE)
                        {
                            if (GameObject *pGasValve = instance->GetGameObject(uiGasValve))
                                pGasValve->SetGoState(GO_STATE_READY);
                            if (GameObject *pOozeValve = instance->GetGameObject(uiOozeValve))
                                pOozeValve->SetGoState(GO_STATE_READY);
                        }
                        break;
                    }
                    case DATA_GAS_VALVE_ACTIVATED:
                    {
                        switch (data)
                        {
                            case IN_PROGRESS:
                            {
                                gasValveActivated = IN_PROGRESS;
                                //Fill up the gas pipe
                                if (GameObject *go = instance->GetGameObject(uiOrangePipe))
                                    go->SetGoState(GO_STATE_ACTIVE);
                                if (Creature *pProfessor = instance->GetCreature(uiProfessorPutricide))
                                    pProfessor->AI()->DoAction(ACTION_ACTIVATE_ORANGE_DOOR);
                                if (oozeValveActivated == IN_PROGRESS)
                                {
                                    oozeValveActivated = DONE;
                                    gasValveActivated = DONE;
                                }
                                break;
                            }
                            case DONE:
                            {
                                if (gasValveActivated == FAIL)
                                    break;
                                gasValveActivated = SPECIAL;
                                if (GameObject *goOrangeDoor = instance->GetGameObject(uiProfDoorOrange))
                                    goOrangeDoor->SetGoState(GO_STATE_READY);
                                if (oozeValveActivated == SPECIAL)
                                    if (Creature *pProfessor = instance->GetCreature(uiProfessorPutricide))
                                        pProfessor->AI()->DoAction(ACTION_OPEN_DOORS);
                                break;
                            }
                            case FAIL:
                            {
                                if (gasValveActivated == DONE)
                                    break;
                                //Failed to activate valves simultaneously
                                //Empty pipes
                                HandleGameObject(uiGreenPipe, false);
                                HandleGameObject(uiOrangePipe, false);
                                //Empty doors
                                HandleGameObject(uiProfDoorGreen, true);
                                HandleGameObject(uiProfDoorOrange, true);
                                //Make valves usable
                                if (GameObject *goValve = instance->GetGameObject(uiOozeValve))
                                    goValve->SetGoState(GO_STATE_READY);
                                if (GameObject *goValve = instance->GetGameObject(uiGasValve))
                                    goValve->SetGoState(GO_STATE_READY);
                                gasValveActivated = FAIL;
                                oozeValveActivated = FAIL;
                                break;
                            }
                            case SPECIAL:
                            {
                                //Remove airlock door
                                HandleGameObject(uiProfCollisionDoor, true);
                                //Open ooze and gas doors
                                if (GameObject* go = instance->GetGameObject(uiProfDoorOrange))
                                    go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                                if (GameObject* go = instance->GetGameObject(uiProfDoorGreen))
                                    go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                                //Make sure that professor's inner door is opened
                                instance->LoadGrid(4356.0f, 3155.0f);
                                HandleGameObject(uiProfessorDoor, true);
                                break;
                            }
                        }
                        break;
                    }
                    case DATA_ROTFACE_EVENT:
                    {
                        HandleGameObject(uiGreenMonsterDoor, data != IN_PROGRESS);
                        uiEncounter[DATA_ROTFACE_EVENT] = data;
                        if (uiEncounter[DATA_ROTFACE_EVENT] == DONE && uiEncounter[DATA_FESTERGUT_EVENT] == DONE)
                        {
                            if (GameObject *pGasValve = instance->GetGameObject(uiGasValve))
                                pGasValve->SetGoState(GO_STATE_READY);
                            if (GameObject *pOozeValve = instance->GetGameObject(uiOozeValve))
                                pOozeValve->SetGoState(GO_STATE_READY);
                        }
                        break;
                    }
                    case DATA_OOZE_VALVE_ACTIVATED:
                    {
                        switch (data)
                        {
                            case IN_PROGRESS:
                            {
                                oozeValveActivated = IN_PROGRESS;
                                //Fill up the ooze pipe
                                if (GameObject *go = instance->GetGameObject(uiGreenPipe))
                                    go->SetGoState(GO_STATE_ACTIVE);
                                if (Creature *pProfessor = instance->GetCreature(uiProfessorPutricide))
                                    pProfessor->AI()->DoAction(ACTION_ACTIVATE_GREEN_DOOR);
                                if (gasValveActivated == IN_PROGRESS)
                                {
                                    oozeValveActivated = DONE;
                                    gasValveActivated = DONE;
                                }
                                break;
                            }
                            case DONE:
                            {
                                if (oozeValveActivated == FAIL)
                                    break;
                                oozeValveActivated = SPECIAL;
                                if (GameObject *goGreenDoor = instance->GetGameObject(uiProfDoorGreen))
                                    goGreenDoor->SetGoState(GO_STATE_READY);
                                if (gasValveActivated == SPECIAL)
                                    if (Creature *pProfessor = instance->GetCreature(uiProfessorPutricide))
                                        pProfessor->AI()->DoAction(ACTION_OPEN_DOORS);
                                break;
                            }
                            case FAIL:
                            {
                                if (oozeValveActivated == DONE)
                                    break;
                                //Failed to activate valves simultaneously
                                //Empty pipes
                                HandleGameObject(uiGreenPipe, false);
                                HandleGameObject(uiOrangePipe, false);
                                //Empty doors
                                HandleGameObject(uiProfDoorGreen, true);
                                HandleGameObject(uiProfDoorOrange, true);
                                //Make valves usable
                                if (GameObject *goValve = instance->GetGameObject(uiOozeValve))
                                    goValve->SetGoState(GO_STATE_READY);
                                if (GameObject *goValve = instance->GetGameObject(uiGasValve))
                                    goValve->SetGoState(GO_STATE_READY);
                                gasValveActivated = FAIL;
                                oozeValveActivated = FAIL;
                                break;
                            }
                            case SPECIAL:
                            {
                                //Remove airlock door
                                HandleGameObject(uiProfCollisionDoor, true);
                                //Open ooze and gas doors
                                if (GameObject* go = instance->GetGameObject(uiProfDoorOrange))
                                    go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                                if (GameObject* go = instance->GetGameObject(uiProfDoorGreen))
                                    go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                                //Make sure that professor's inner door is opened
                                instance->LoadGrid(4356.0f, 3155.0f);
                                HandleGameObject(uiProfessorDoor, true);
                                break;
                            }
                        }
                        break;
                    }
                    case DATA_PROFESSOR_PUTRICIDE_EVENT:
                    {
                        if (instance->IsHeroic())
                        {
                            if (data == FAIL && heroicAttempts)
                            {
                                --heroicAttempts;
                                DoUpdateWorldState(WORLDSTATE_ATTEMPTS_REMAINING, heroicAttempts);
                                if (!heroicAttempts)
                                    if (Creature* putricide = instance->GetCreature(uiProfessorPutricide))
                                        putricide->DespawnOrUnsummon();
                            }
                        }
                        instance->LoadGrid(4356.0f, 3155.0f);
                        HandleGameObject(uiProfessorDoor, data != IN_PROGRESS);
                        if(data == DONE)
                        {
                            //Prevent future using of Putricide's mixtures
                            if (GameObject *table = instance->GetGameObject(uiPutricideTable))
                                table->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                            instance->LoadGrid(4357.0f, 2823.0f);
                            if (GameObject* go = instance->GetGameObject(uiPlagueSigil))
                                go->SetGoState(GO_STATE_READY);
                            if (uiEncounter[DATA_BLOOD_QUEEN_LANA_THEL_EVENT] == DONE && uiEncounter[DATA_SINDRAGOSA_EVENT] == DONE)
                                MakeObjectClickable(GUID_TELEPORT_FROZEN_THRONE);
                        }
                        uiEncounter[DATA_PROFESSOR_PUTRICIDE_EVENT] = data;
                        break;
                    }
                    case DATA_BLOOD_PRINCE_COUNCIL_EVENT:
                    {
                        if(data == DONE)
                        {
                            HandleGameObject(uiCrimsonHallDoor1, true);
                            HandleGameObject(uiCrimsonHallDoorRight, true);
                            HandleGameObject(uiCrimsonHallDoorLeft, true);
                        }
                        HandleGameObject(uiCrimsonHallDoor1, data != IN_PROGRESS);
                        uiEncounter[DATA_BLOOD_PRINCE_COUNCIL_EVENT] = data;
                        break;
                    }
                    case DATA_BLOOD_QUEEN_LANA_THEL_EVENT:
                    {
                        if (instance->IsHeroic())
                        {
                            if (data == FAIL && heroicAttempts)
                            {
                                --heroicAttempts;
                                DoUpdateWorldState(WORLDSTATE_ATTEMPTS_REMAINING, heroicAttempts);
                                if (!heroicAttempts)
                                    if (Creature* bq = instance->GetCreature(uiBloodQueenLanathel))
                                        bq->DespawnOrUnsummon();
                            }
                        }
                        if(data == DONE)
                        {
                            HandleGameObject(uiBloodQueenGrate, true);
                            instance->LoadGrid(4412, 2769);
                            if (GameObject *go = instance->GetGameObject(uiBloodwingSigil))
                                go->SetGoState(GO_STATE_READY);
                            if (uiEncounter[DATA_PROFESSOR_PUTRICIDE_EVENT] == DONE && uiEncounter[DATA_SINDRAGOSA_EVENT] == DONE)
                                MakeObjectClickable(GUID_TELEPORT_FROZEN_THRONE);
                        }
                        HandleGameObject(uiBloodQueenBloodBarrier, data != IN_PROGRESS);
                        uiEncounter[DATA_BLOOD_QUEEN_LANA_THEL_EVENT] = data;
                        break;
                    }
                    case DATA_VALITHRIA_DREAMWALKER_EVENT:
                    {
                        if(data == DONE)
                        {
                            MakeObjectClickable(GUID_TELEPORT_SINDRAGOSAS_LAIR);
                            if (GameObject* pChest = instance->GetGameObject(uiDreamwalkerCache))
                                pChest->SetRespawnTime(pChest->GetRespawnDelay());
                            if (GameObject* go = instance->GetGameObject(uiValithriaTransporter))
                            {
                                go->SetUInt32Value(GAMEOBJECT_LEVEL, 0);
                                go->SetGoState(GO_STATE_READY);
                            }
                            HandleGameObject(uiValithriaDoorEntrance, true);
                            HandleGameObject(uiValithriaDoorExit, true);
                            HandleGameObject(uiSindragosaDoor1, true);
                        }
                        if(data == NOT_STARTED || data == FAIL)
                        {
                            HandleGameObject(uiValithriaDoorEntrance, true);
                            HandleGameObject(uiRoostDoor3, false);
                            HandleGameObject(uiRoostDoor2, false);         
                            HandleGameObject(uiRoostDoor1, false);
                            HandleGameObject(uiRoostDoor4, false);
                        }
                        if(data == IN_PROGRESS)
                        {
                            HandleGameObject(uiValithriaDoorEntrance, false);
                            HandleGameObject(uiRoostDoor3, true);
                            HandleGameObject(uiRoostDoor2, true);
                            if (uiDifficulty == RAID_DIFFICULTY_25MAN_NORMAL || uiDifficulty == RAID_DIFFICULTY_25MAN_HEROIC)
                            {
                                HandleGameObject(uiRoostDoor1, true);
                                HandleGameObject(uiRoostDoor4, true);
                            }
                        }
                        uiEncounter[DATA_VALITHRIA_DREAMWALKER_EVENT] = data;
                        break;
                    }
                    case DATA_SINDRAGOSA_EVENT:
                    {
                        HandleGameObject(uiSindragosaIceWall, data != IN_PROGRESS);
                        HandleGameObject(uiSindragosaDoor1, data != IN_PROGRESS);
                        if (instance->IsHeroic())
                        {
                            if (data == FAIL && heroicAttempts)
                            {
                                --heroicAttempts;
                                DoUpdateWorldState(WORLDSTATE_ATTEMPTS_REMAINING, heroicAttempts);
                                if (!heroicAttempts)
                                    if (Creature* sindra = instance->GetCreature(uiSindragosa))
                                        sindra->DespawnOrUnsummon();
                            }
                        }
                        if (data == DONE)
                        {
                            HandleGameObject(uiSindragosaShortcutEntranceDoor, true);
                            HandleGameObject(uiSindragosaShortcutExitDoor, true);
                            if (GameObject* go = instance->GetGameObject(uiSindragosaTransporter))
                            {
                                go->SetUInt32Value(GAMEOBJECT_LEVEL, 0);
                                go->SetGoState(GO_STATE_READY);
                            }
                            instance->LoadGrid(4357.0f, 2714.0f);
                            if (GameObject *go = instance->GetGameObject(uiFrostwingSigil))
                                go->SetGoState(GO_STATE_READY);
                        }
                        if (uiEncounter[DATA_PROFESSOR_PUTRICIDE_EVENT] == DONE && uiEncounter[DATA_BLOOD_QUEEN_LANA_THEL_EVENT] == DONE)
                            MakeObjectClickable(GUID_TELEPORT_FROZEN_THRONE);
                        uiEncounter[DATA_SINDRAGOSA_EVENT] = data;
                        break;
                    }
                    case DATA_LICH_KING_EVENT:
                        if(data == NOT_STARTED)
                        {
                            if (GameObject *go = instance->GetGameObject(uilavaman))
                                go->SetPhaseMask(2,true);
                        }
                        if (data == DONE)
                        {
                            if (GameObject *go = instance->GetGameObject(uilavaman))
                                go->SetPhaseMask(1,true);
                            if (GameObject *go = instance->GetGameObject(uilavaman))
                                go->SetRespawnTime(5*DAY);;
                            if (GameObject *go = instance->GetGameObject(uihangingman))
                                go->SetPhaseMask(2,true);
                        }
                        uiEncounter[DATA_LICH_KING_EVENT] = data;
                        break;
                    case DATA_BONED_ACHIEVEMENT:
                        isBonedEligible = data ? true : false;
                        break;
                    case DATA_OOZE_DANCE_ACHIEVEMENT:
                        isOozeDanceEligible = data ? true : false;
                        break;
                    case DATA_NAUSEA_ACHIEVEMENT:
                        isNauseaEligible = data ? true : false;
                        break;
                    case DATA_ORB_WHISPERER_ACHIEVEMENT:
                        isOrbWhispererEligible = data ? true : false;
                        break;
                    case DATA_PORTAL_JOCKEY_ACHIEVEMENT:
                        isPortalJockeyEligible = data ? true : false;
                        break;
                    case DATA_SINDRAGOSA_FROSTWYRMS:
                    {
                        if (instance->IsHeroic() && !heroicAttempts)
                            return;
                        if (data > 1) 
                            frostwyrms = data; 
                        else if (data == 1) 
                            ++frostwyrms; 
                        else if (!data && !--frostwyrms && GetBossState(DATA_SINDRAGOSA_EVENT) != DONE) 
                        { 
                            instance->LoadGrid(SindragosaSpawnPos.GetPositionX(), SindragosaSpawnPos.GetPositionY()); 
                            if (Creature* boss = instance->SummonCreature(NPC_SINDRAGOSA, SindragosaSpawnPos)) 
                            { 
                                boss->setActive(true); 
                                boss->AI()->DoAction(ACTION_START_FROSTWYRM); 
                            } 
                        } 
                        break; 
                    }
                    case DATA_SPINESTALKER_EVENT:
                    {
                        if (data > 1) 
                            spinestalkerTrash = data; 
                        else if (data == 1) 
                            ++spinestalkerTrash; 
                        else if (!data && !--spinestalkerTrash) 
                            if (Creature* spinestalk = instance->GetCreature(uiSpinestalker)) 
                                spinestalk->AI()->DoAction(ACTION_START_FROSTWYRM); 
                        break;
                    }
                    case DATA_RIMEFANG_EVENT:
                    {
                        if (data > 1) 
                            rimefangTrash = data; 
                        else if (data == 1) 
                            ++rimefangTrash; 
                        else if (!data && !--rimefangTrash) 
                            if (Creature* rime = instance->GetCreature(uiRimefang)) 
                                rime->AI()->DoAction(ACTION_START_FROSTWYRM);
                        break;
                    }
                    case DATA_COLDFLAME_JETS_EVENT:
                        coldflameJetsState = data;
                        if (coldflameJetsState == DONE)
                        {
                            SaveToDB();
                            for (std::set<uint64>::iterator itr = coldflameJets.begin(); itr != coldflameJets.end(); ++itr)
                                if (Creature* trap = instance->GetCreature(*itr))
                                    trap->AI()->DoAction(ACTION_STOP_TRAPS);
                        }
                        break;
                    case DATA_BLOOD_QUICKENING_STATE:
                    {
                        // skip if nothing changes
                        if (bloodQuickeningState == data)
                            break;

                        // 5 is the index of Blood Quickening
                        if (!sPoolMgr->IsSpawnedObject<Quest>(WeeklyQuestData[5].questId[instance->GetSpawnMode() & 1]))
                            break;

                        switch (data)
                        {
                            case IN_PROGRESS:
                                bloodQuickeningTimer = 60000;
                                bloodQuickeningMinutes = 30;
                                DoUpdateWorldState(WORLDSTATE_SHOW_TIMER, 1);
                                DoUpdateWorldState(WORLDSTATE_EXECUTION_TIME, bloodQuickeningMinutes);
                                break;
                            case DONE:
                                bloodQuickeningTimer = 0;
                                bloodQuickeningMinutes = 0;
                                DoUpdateWorldState(WORLDSTATE_SHOW_TIMER, 0);
                                break;
                            default:
                                break;
                        }

                        bloodQuickeningState = data;
                        break;
                    }
                    case DATA_NECK_DEEP_ACHIEVEMENT:         
                        uiNeckDeep = data;
                        break;
                    case DATA_BEEN_WAITING_ACHIEVEMENT:         
                        uiNecroticStack = data;
                        break;
                    //Teleports
                    case DATA_TELEPORT_ORATORY_OF_THE_DAMNED_ACTIVATED:
                        uiTeleportToOratoryOfTheDamnedActivated = data;
                        break;
                    case DATA_TELEPORT_RAMPART_OF_SKULLS_ACTIVATED:
                        uiTeleportToRampartOfSkullsActivated = data;
                        break;
                    case DATA_TELEPORT_DEATHBRINGER_S_RISE_ACTIVATED:
                        uiTeleportToDeathbringersRiseActivated = data;
                        break;
                    case DATA_TELEPORT_UPPER_SPIRE_ACTIVATED:
                        uiTeleportToUpperSpireActivated = data;
                        break;
                    case DATA_TELEPORT_SINDRAGOSA_S_LAIR_ACTIVATED:
                        uiTeleportToSindragosasLairActivated = data;
                        break;
                    case DATA_TELEPORT_FROZEN_THRONE_ACTIVATED:
                        uiTeleportToFrozenThroneActivated = data;
                        break;
                    default: 
                        break; 
                }

                SaveToDB();
            }

            uint32 GetData(uint32 type)
            {
                switch(type)
                {
                    case DATA_LORD_MARROWGAR_EVENT:
                        return uiEncounter[DATA_LORD_MARROWGAR_EVENT];
                    case DATA_DEATHWHISPER_EVENT:
                        return uiEncounter[DATA_DEATHWHISPER_EVENT];
                    case DATA_GUNSHIP_BATTLE_EVENT:
                        return uiEncounter[DATA_GUNSHIP_BATTLE_EVENT];
                    case DATA_SAURFANG_EVENT:
                        return uiEncounter[DATA_SAURFANG_EVENT];
                    case DATA_FESTERGUT_EVENT:
                        return uiEncounter[DATA_FESTERGUT_EVENT];
                    case DATA_ROTFACE_EVENT:
                        return uiEncounter[DATA_ROTFACE_EVENT];
                    case DATA_PROFESSOR_PUTRICIDE_EVENT:
                        return uiEncounter[DATA_PROFESSOR_PUTRICIDE_EVENT];
                    case DATA_BLOOD_PRINCE_COUNCIL_EVENT:
                        return uiEncounter[DATA_BLOOD_PRINCE_COUNCIL_EVENT];
                    case DATA_BLOOD_QUEEN_LANA_THEL_EVENT:
                        return uiEncounter[DATA_BLOOD_QUEEN_LANA_THEL_EVENT];
                    case DATA_VALITHRIA_DREAMWALKER_EVENT:
                        return uiEncounter[DATA_VALITHRIA_DREAMWALKER_EVENT];
                    case DATA_SINDRAGOSA_EVENT:
                        return uiEncounter[DATA_SINDRAGOSA_EVENT];
                    case DATA_LICH_KING_EVENT:
                        return uiEncounter[DATA_LICH_KING_EVENT];

                    case DATA_PORTAL_JOCKEY_ACHIEVEMENT:
                        return isPortalJockeyEligible ? true : false;
                    case DATA_SINDRAGOSA_FROSTWYRMS: 
                        return frostwyrms; 
                    case DATA_SPINESTALKER_EVENT: 
                        return spinestalkerTrash; 
                    case DATA_RIMEFANG_EVENT: 
                        return rimefangTrash; 
                    case DATA_COLDFLAME_JETS_EVENT:
                        return coldflameJetsState;
                    case DATA_TEAM_IN_INSTANCE:
                        return teamInInstance;
                    case DATA_NECK_DEEP_ACHIEVEMENT:         
                        return uiNeckDeep;
                    case DATA_BEEN_WAITING_ACHIEVEMENT:              
                        return uiNecroticStack;
                    case DATA_HEROIC_ATTEMPTS:
                        return heroicAttempts;

                    //Teleports
                    case DATA_TELEPORT_ORATORY_OF_THE_DAMNED_ACTIVATED:
                        return uiTeleportToOratoryOfTheDamnedActivated;
                    case DATA_TELEPORT_RAMPART_OF_SKULLS_ACTIVATED:
                        return uiTeleportToRampartOfSkullsActivated;
                    case DATA_TELEPORT_DEATHBRINGER_S_RISE_ACTIVATED:
                        return uiTeleportToDeathbringersRiseActivated;
                    case DATA_TELEPORT_UPPER_SPIRE_ACTIVATED:
                        return uiTeleportToUpperSpireActivated;
                    case DATA_TELEPORT_SINDRAGOSA_S_LAIR_ACTIVATED:
                        return uiTeleportToSindragosasLairActivated;
                    case DATA_TELEPORT_FROZEN_THRONE_ACTIVATED:
                        return uiTeleportToFrozenThroneActivated;
                    default: 
                        break; 
                } 


                return 0;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;
                //While Gunship Battle isn't implemented
                uiEncounter[DATA_GUNSHIP_BATTLE_EVENT] = DONE;
                std::ostringstream saveStream;
                saveStream << "I C " << uiEncounter[DATA_LORD_MARROWGAR_EVENT] << " " << uiEncounter[DATA_DEATHWHISPER_EVENT] << " " << uiEncounter[DATA_GUNSHIP_BATTLE_EVENT] << " " << uiEncounter[DATA_SAURFANG_EVENT]
                << " " << uiEncounter[DATA_FESTERGUT_EVENT] << " " << uiEncounter[DATA_ROTFACE_EVENT] << " " << uiEncounter[DATA_PROFESSOR_PUTRICIDE_EVENT] << " " << uiEncounter[DATA_BLOOD_PRINCE_COUNCIL_EVENT] << " " << uiEncounter[DATA_BLOOD_QUEEN_LANA_THEL_EVENT]
                << " " << uiEncounter[DATA_VALITHRIA_DREAMWALKER_EVENT] << " " << uiEncounter[DATA_SINDRAGOSA_EVENT] << " " << uiEncounter[DATA_LICH_KING_EVENT];
                //Saving additional data
                saveStream << " " << uint32(gasValveActivated) << " " << uint32(oozeValveActivated) << " " << uint32(coldflameJetsState) << " " << uint32(bloodQuickeningState) << " " << uint32(bloodQuickeningMinutes);
                saveStream << " " << uint32(uiTeleportToOratoryOfTheDamnedActivated);
                saveStream << " " << uint32(uiTeleportToRampartOfSkullsActivated);
                saveStream << " " << uint32(uiTeleportToDeathbringersRiseActivated);
                saveStream << " " << uint32(uiTeleportToUpperSpireActivated);
                saveStream << " " << uint32(uiTeleportToSindragosasLairActivated);
                saveStream << " " << uint32(uiTeleportToFrozenThroneActivated);

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target*/, uint32 /*miscvalue1*/)
            {
                switch (criteria_id)
                {
                    case CRITERIA_BONED_10N:
                    case CRITERIA_BONED_25N:
                    case CRITERIA_BONED_10H:
                    case CRITERIA_BONED_25H:
                        return isBonedEligible;
                    case CRITERIA_DANCES_WITH_OOZES_10N:
                    case CRITERIA_DANCES_WITH_OOZES_25N:
                    case CRITERIA_DANCES_WITH_OOZES_10H:
                    case CRITERIA_DANCES_WITH_OOZES_25H:
                        return isOozeDanceEligible;
                    case CRITERIA_NAUSEA_10N:
                    case CRITERIA_NAUSEA_25N:
                    case CRITERIA_NAUSEA_10H:
                    case CRITERIA_NAUSEA_25H:
                        return isNauseaEligible;
                    case CRITERIA_ORB_WHISPERER_10N:
                    case CRITERIA_ORB_WHISPERER_25N:
                    case CRITERIA_ORB_WHISPERER_10H:
                    case CRITERIA_ORB_WHISPERER_25H:
                        return isOrbWhispererEligible;
                    // Only one criteria for both modes, need to do it like this
                    case CRITERIA_KILL_LANA_THEL_10M:
                    case CRITERIA_ONCE_BITTEN_TWICE_SHY_10N:
                    case CRITERIA_ONCE_BITTEN_TWICE_SHY_10V:
                        return CAST_INST(InstanceMap, instance)->GetMaxPlayers() == 10;
                    case CRITERIA_KILL_LANA_THEL_25M:
                    case CRITERIA_ONCE_BITTEN_TWICE_SHY_25N:
                    case CRITERIA_ONCE_BITTEN_TWICE_SHY_25V:
                        return CAST_INST(InstanceMap, instance)->GetMaxPlayers() == 25;
                    case CRITERIA_PORTAL_JOCKEY_10N:
                    case CRITERIA_PORTAL_JOCKEY_10H:
                    case CRITERIA_PORTAL_JOCKEY_25N:
                    case CRITERIA_PORTAL_JOCKEY_25H:
                        return isPortalJockeyEligible;
                    default:
                        break;
                }

                return false;
            }

            void Load(const char* in)
            {
                if (!in)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(in);

                char dataHead1, dataHead2;

                std::istringstream loadStream(in);
                uint32 data0, data1, data2, data3, data4, data5, data6, data7, data8, data9, data10, data11, data12, data13;
                loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3 >> data4 >> data5 >> data6 >> data7 >> data8 >> data9 >> data10 >> data11 >> data12 >> data13;

                if (dataHead1 == 'I' && dataHead2 == 'C')
                {
                    uiEncounter[DATA_LORD_MARROWGAR_EVENT] = data0;
                    uiEncounter[DATA_DEATHWHISPER_EVENT] = data1;
                    uiEncounter[DATA_GUNSHIP_BATTLE_EVENT] = data2;
                    //While not implemented
                    uiEncounter[DATA_GUNSHIP_BATTLE_EVENT] = DONE;
                    uiEncounter[DATA_SAURFANG_EVENT] = data3;
                    uiEncounter[DATA_FESTERGUT_EVENT] = data4;
                    uiEncounter[DATA_ROTFACE_EVENT] = data5;
                    uiEncounter[DATA_PROFESSOR_PUTRICIDE_EVENT] = data6;
                    uiEncounter[DATA_BLOOD_PRINCE_COUNCIL_EVENT] = data7;
                    uiEncounter[DATA_BLOOD_QUEEN_LANA_THEL_EVENT] = data8;
                    uiEncounter[DATA_VALITHRIA_DREAMWALKER_EVENT] = data9;
                    uiEncounter[DATA_SINDRAGOSA_EVENT] = data10;
                    uiEncounter[DATA_LICH_KING_EVENT] = data11;
                    //Loading additional data
                    gasValveActivated = data12;
                    oozeValveActivated = data13;

                    for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    {
                        if (uiEncounter[i] == IN_PROGRESS)
                            uiEncounter[i] = NOT_STARTED;
                    }
                    if (uiEncounter[DATA_FESTERGUT_EVENT] != DONE || uiEncounter[DATA_ROTFACE_EVENT] != DONE)
                        gasValveActivated = oozeValveActivated = NOT_STARTED;
                    if (gasValveActivated == IN_PROGRESS || gasValveActivated == DONE)
                        gasValveActivated = NOT_STARTED;
                    if (oozeValveActivated == IN_PROGRESS || oozeValveActivated == DONE)
                        oozeValveActivated = NOT_STARTED;

                    uint32 temp = 0;
                    loadStream >> temp;
                    coldflameJetsState = temp ? DONE : NOT_STARTED;
                    temp = 0;
                    loadStream >> temp;
                    bloodQuickeningState = temp ? DONE : NOT_STARTED;   // DONE means finished (not success/fail)
                    loadStream >> bloodQuickeningMinutes;
                    loadStream >> uiTeleportToOratoryOfTheDamnedActivated;
                    loadStream >> uiTeleportToRampartOfSkullsActivated;
                    loadStream >> uiTeleportToDeathbringersRiseActivated;
                    loadStream >> uiTeleportToUpperSpireActivated;
                    loadStream >> uiTeleportToSindragosasLairActivated;
                    loadStream >> uiTeleportToFrozenThroneActivated;
                } else OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

            void Update(uint32 diff)
            {
                if (bloodQuickeningMinutes)
                {
                    if (bloodQuickeningTimer <= diff)
                    {
                        --bloodQuickeningMinutes;
                        bloodQuickeningTimer = 60000;
                        if (bloodQuickeningMinutes)
                        {
                            DoUpdateWorldState(WORLDSTATE_SHOW_TIMER, 1);
                            DoUpdateWorldState(WORLDSTATE_EXECUTION_TIME, bloodQuickeningMinutes);
                        }
                        else
                        {
                            bloodQuickeningState = DONE;
                            DoUpdateWorldState(WORLDSTATE_SHOW_TIMER, 0);
                            if (Creature* bq = instance->GetCreature(uiBloodQueenLanathel))
                                bq->AI()->DoAction(ACTION_KILL_MINCHAR);
                        }
                        SaveToDB();
                    }
                    else
                        bloodQuickeningTimer -= diff;
                }
            }

        private:
            uint64 uiLordMarrowgar;
            uint64 uiDeathbringerSaurfang;
            uint64 uiSaurfangEventNPC;
            uint64 uiFestergut;
            uint64 uiRotface;
            uint64 uiProfessorPutricide;
            uint64 uiPrinceValanar;
            uint64 uiPrinceKeleseth;
            uint64 uiPrinceTaldaram;
            uint64 uiBloodQueenLanathel;
            uint64 uiValithriaDreamwalker;
            uint64 uiValithriaAlternative;
            uint64 uiValithriaCombatTrigger;
            uint64 uiLichKing;
            uint64 uiTirion;
            uint64 uiTerenasFighter;
            uint64 uiSpiritWarden;
            uint64 CrokScourgebaneGUID;
            uint64 CrokCaptainGUIDs[4];
            uint64 SisterSvalnaGUID;
            uint64 uiIceWall1;
            uint64 uiIceWall2;
            uint64 uiMarrowgarEntrance;
            uint64 uiFrozenThrone;
            uint64 uiSaurfangCache;
            uint64 uiLadyDeathwisperTransporter;
            uint64 uiOratoryDoor;
            uint64 uiSaurfangDoor;
            uint64 uiOrangeMonsterDoor;
            uint64 uiGreenMonsterDoor;
            uint64 uiProfCollisionDoor;
            uint64 uiPutricideTable;
            uint64 uiOrangePipe;
            uint64 uiGreenPipe;
            uint64 uiOozeValve;
            uint64 uiGasValve;
            uint64 uiProfDoorOrange;
            uint64 uiProfDoorGreen;
            uint64 uiRotfaceEntrance;
            uint64 uiFestergurtEntrance;
            uint64 uiProfessorDoor;
            uint64 uiBloodwingDoor;
            uint64 uiCrimsonHallDoor1;
            uint64 uiCrimsonHallDoorRight;
            uint64 uiCrimsonHallDoorLeft;
            uint64 uiBloodQueenGrate;
            uint64 uiBloodQueenBloodBarrier;
            uint64 uiFrostwingDoor;
            uint64 uiValithriaDoorEntrance;
            uint64 uiValithriaDoorExit;
            uint64 uiSindragosaShortcutExitDoor;
            uint64 uiRoostDoor1;
            uint64 uiRoostDoor2;
            uint64 uiRoostDoor3;
            uint64 uiRoostDoor4;
            uint64 uiValithriaTransporter;
            uint64 uiSindragosaTransporter;
            uint64 uiDreamwalkerCache;
            uint64 uiSindragosaDoor1;
            uint64 uiSindragosaShortcutEntranceDoor;
            uint64 uiSindragosaIceWall;
            uint64 uiFirstTp;
            uint64 uiMarrowgarTp;
            uint64 uiFlightWarTp;
            uint64 uiSaurfangTp;
            uint64 uiCitadelTp;
            uint64 uiSindragosaTp;
            uint64 uiLichTp;
            uint64 uiBloodCouncilController;
            uint64 uiPlagueSigil;
            uint64 uiBloodwingSigil;
            uint64 uiFrostwingSigil;
            uint64 uiSpiritAlarm1;
            uint64 uiSpiritAlarm2;
            uint64 uiSpiritAlarm3;
            uint64 uiSpiritAlarm4;
            uint64 uilavaman;
            uint64 uihangingman;
            uint64 uiDeathboundWard1;
            uint64 uiDeathboundWard2;
            uint64 uiDeathboundWard3;
            uint64 uiDeathboundWard4;
            uint64 uiUpperSpireLever;
            uint64 uiIceShard1;
            uint64 uiIceShard2;
            uint64 uiIceShard3;
            uint64 uiIceShard4;
            uint64 uiFrostyEdgeInner;
            uint64 uiFrostyEdgeOuter;
            uint64 uiEdgeDestroyWarning;

            uint8 uiDifficulty;
            uint8 uiBeenWaiting;
            uint8 uiNeckDeep;
            uint8 uiNecroticStack;
            uint64 uiSindragosa; 
            uint64 uiSpinestalker; 
            uint64 uiRimefang;
            uint16 coldflameJetsState;
            std::set<uint64> coldflameJets;
            uint16 frostwyrms; 
            uint16 spinestalkerTrash; 
            uint16 rimefangTrash;
            uint16 heroicAttempts;
            uint16 bloodQuickeningState;
            uint16 bloodQuickeningMinutes;
            uint16 bloodQuickeningTimer;
            uint8 oozeValveActivated;
            uint8 gasValveActivated;

            uint8 isBonedEligible;
            uint8 isOozeDanceEligible;
            uint8 isNauseaEligible;
            uint8 isOrbWhispererEligible;
            uint8 isPortalJockeyEligible;

            uint32 uiTeleportToOratoryOfTheDamnedActivated;
            uint32 uiTeleportToRampartOfSkullsActivated;
            uint32 uiTeleportToDeathbringersRiseActivated;
            uint32 uiTeleportToUpperSpireActivated;
            uint32 uiTeleportToSindragosasLairActivated;
            uint32 uiTeleportToFrozenThroneActivated;

            uint32 teamInInstance;
            uint32 uiEncounter[MAX_ENCOUNTER];
            std::map<uint64, Position> gameObjectPositions;
        };

        InstanceScript* GetInstanceScript(InstanceMap* pMap) const
        {
            return new instance_icecrown_citadel_InstanceMapScript(pMap);
        }
};
void DespawnAllCreaturesAround(Creature *ref, uint32 entry)
{
    while (Unit *unit = ref->FindNearestCreature(entry, 80.0f, true))
        if (Creature *creature = unit->ToCreature())
            creature->DespawnOrUnsummon();
}
void UnsummonSpecificCreaturesNearby(Creature *ref, uint32 entry, float radius)
{
    std::list<Creature*> allCreaturesWithEntry;
    GetCreatureListWithEntryInGrid(allCreaturesWithEntry, ref, entry, radius);
    for(std::list<Creature*>::iterator itr = allCreaturesWithEntry.begin(); itr != allCreaturesWithEntry.end(); ++itr)
    {
        Creature *candidate = *itr;

        if (!candidate)
            continue;
        if (TempSummon* summon = candidate->ToTempSummon())
            summon->DespawnOrUnsummon();
    }
}
uint32 GetPhase(const EventMap &em)
{
    switch (em.GetPhaseMask())
    {
        case 0x01: return 0;
        case 0x02: return 1;
        case 0x04: return 2;
        case 0x08: return 3;
        case 0x10: return 4;
        case 0x20: return 5;
        case 0x40: return 6;
        case 0x80: return 7;
        default:
            return 0;
    }
}
void LeaveOnlyPlayers(std::list<Unit*> &unitList)
{
    for (std::list<Unit*>::iterator itr = unitList.begin(); itr != unitList.end();)
    {
        if ((*itr)->GetTypeId() != TYPEID_PLAYER)
            unitList.erase(itr++);
        else
            ++itr;
    }

    std::list<Unit*>::iterator itr = unitList.begin();
    std::advance(itr, urand(0, unitList.size()-1));
    Unit* target = *itr;
    unitList.clear();
    unitList.push_back(target);
}
class TeleportToFrozenThrone : public BasicEvent
{
    public:
        TeleportToFrozenThrone(Player *player, uint8 attempts): pPlayer(player), attemptsLeft(attempts) { }

        bool Execute(uint64 /*eventTime*/, uint32 /*updateTime*/)
        {
            pPlayer->CastSpell(pPlayer, SPELL_TELEPORT_ICC_FROZEN_THRONE, true);
            if (--attemptsLeft)
                pPlayer->m_Events.AddEvent(new TeleportToFrozenThrone(pPlayer, attemptsLeft), pPlayer->m_Events.CalculateTime(uint64(1500)));
            return true;
        }
    private:
        Player *pPlayer;
        uint8 attemptsLeft;
};
void TeleportPlayerToFrozenThrone(Player *player)
{
    player->m_Events.AddEvent(new TeleportToFrozenThrone(player, 2), player->m_Events.CalculateTime(uint64(5000)));
}
TPlayerList GetPlayersInTheMap(Map *pMap)
{
    TPlayerList players;
    const Map::PlayerList &PlayerList = pMap->GetPlayers();
    if (!PlayerList.isEmpty())
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (Player* player = i->getSource())
                players.push_back(player);
    return players;
}
TPlayerList GetAttackablePlayersInTheMap(Map *pMap)
{
    TPlayerList players = GetPlayersInTheMap(pMap);
    for (TPlayerList::iterator it = players.begin(); it != players.end();)
        if (!(*it)->isTargetableForAttack())
            players.erase(it++);
        else
            ++it;
    return players;
}
void AddSC_instance_icecrown_citadel()
{
    new instance_icecrown_citadel();
}
