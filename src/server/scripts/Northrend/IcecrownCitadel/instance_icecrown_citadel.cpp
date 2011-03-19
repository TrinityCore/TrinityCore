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

static const DoorData doorData[] =
{
    {GO_LORD_MARROWGAR_S_ENTRANCE,           DATA_LORD_MARROWGAR,        DOOR_TYPE_ROOM,    BOUNDARY_N   },
    {GO_ICEWALL,                             DATA_LORD_MARROWGAR,        DOOR_TYPE_PASSAGE, BOUNDARY_NONE},
    {GO_DOODAD_ICECROWN_ICEWALL02,           DATA_LORD_MARROWGAR,        DOOR_TYPE_PASSAGE, BOUNDARY_NONE},
    {GO_ORATORY_OF_THE_DAMNED_ENTRANCE,      DATA_LADY_DEATHWHISPER,     DOOR_TYPE_ROOM,    BOUNDARY_N   },
    {GO_SAURFANG_S_DOOR,                     DATA_DEATHBRINGER_SAURFANG, DOOR_TYPE_PASSAGE, BOUNDARY_NONE},
    {GO_ORANGE_PLAGUE_MONSTER_ENTRANCE,      DATA_FESTERGUT,             DOOR_TYPE_ROOM,    BOUNDARY_E   },
    {GO_GREEN_PLAGUE_MONSTER_ENTRANCE,       DATA_ROTFACE,               DOOR_TYPE_ROOM,    BOUNDARY_E   },
    {GO_SCIENTIST_ENTRANCE,                  DATA_PROFESSOR_PUTRICIDE,   DOOR_TYPE_ROOM,    BOUNDARY_E   },
    {GO_CRIMSON_HALL_DOOR,                   DATA_BLOOD_PRINCE_COUNCIL,  DOOR_TYPE_ROOM,    BOUNDARY_S   },
    {GO_BLOOD_ELF_COUNCIL_DOOR,              DATA_BLOOD_PRINCE_COUNCIL,  DOOR_TYPE_PASSAGE, BOUNDARY_W   },
    {GO_BLOOD_ELF_COUNCIL_DOOR_RIGHT,        DATA_BLOOD_PRINCE_COUNCIL,  DOOR_TYPE_PASSAGE, BOUNDARY_E   },
    {GO_DOODAD_ICECROWN_BLOODPRINCE_DOOR_01, DATA_BLOOD_QUEEN_LANA_THEL, DOOR_TYPE_ROOM,    BOUNDARY_S   },
    {GO_DOODAD_ICECROWN_GRATE_01,            DATA_BLOOD_QUEEN_LANA_THEL, DOOR_TYPE_PASSAGE, BOUNDARY_NONE},
    {GO_GREEN_DRAGON_BOSS_ENTRANCE,          DATA_VALITHRIA_DREAMWALKER, DOOR_TYPE_ROOM,    BOUNDARY_N   },
    {GO_GREEN_DRAGON_BOSS_EXIT,              DATA_VALITHRIA_DREAMWALKER, DOOR_TYPE_PASSAGE, BOUNDARY_S   },
    {GO_SINDRAGOSA_ENTRANCE_DOOR,            DATA_SINDRAGOSA,            DOOR_TYPE_ROOM,    BOUNDARY_S   },
    {GO_SINDRAGOSA_SHORTCUT_ENTRANCE_DOOR,   DATA_SINDRAGOSA,            DOOR_TYPE_PASSAGE, BOUNDARY_E   },
    {GO_SINDRAGOSA_SHORTCUT_EXIT_DOOR,       DATA_SINDRAGOSA,            DOOR_TYPE_PASSAGE, BOUNDARY_NONE},
    {GO_ICE_WALL,                            DATA_SINDRAGOSA,            DOOR_TYPE_ROOM,    BOUNDARY_SE  },
    {GO_ICE_WALL,                            DATA_SINDRAGOSA,            DOOR_TYPE_ROOM,    BOUNDARY_SW  },
    {0,                                      0,                          DOOR_TYPE_ROOM,    BOUNDARY_NONE} // END
};

// this doesnt have to only store questgivers, also can be used for related quest spawns
struct WeeklyQuest
{
    uint32 creatureEntry;
    uint32 questId[2];  // 10 and 25 man versions
} WeeklyQuestData[WeeklyNPCs] =
{
    {NPC_INFILTRATOR_MINCHAR,         {QUEST_DEPROGRAMMING_10,                 QUEST_DEPROGRAMMING_25                }}, // Deprogramming
    {NPC_KOR_KRON_LIEUTENANT,         {QUEST_SECURING_THE_RAMPARTS_10,         QUEST_SECURING_THE_RAMPARTS_25        }}, // Securing the Ramparts
    {NPC_ALCHEMIST_ADRIANNA,          {QUEST_RESIDUE_RENDEZVOUS_10,            QUEST_RESIDUE_RENDEZVOUS_25           }}, // Residue Rendezvous
    {NPC_ALRIN_THE_AGILE,             {QUEST_BLOOD_QUICKENING_10,              QUEST_BLOOD_QUICKENING_25             }}, // Blood Quickening
    {NPC_INFILTRATOR_MINCHAR_BQ,      {QUEST_BLOOD_QUICKENING_10,              QUEST_BLOOD_QUICKENING_25             }}, // Blood Quickening
    {NPC_MINCHAR_BEAM_STALKER,        {QUEST_BLOOD_QUICKENING_10,              QUEST_BLOOD_QUICKENING_25             }}, // Blood Quickening
    {NPC_VALITHRIA_DREAMWALKER_QUEST, {QUEST_RESPITE_FOR_A_TORNMENTED_SOUL_10, QUEST_RESPITE_FOR_A_TORNMENTED_SOUL_25}}, // Respite for a Tormented Soul
};

class instance_icecrown_citadel : public InstanceMapScript
{
    public:
        instance_icecrown_citadel() : InstanceMapScript(ICCScriptName, 631) { }

        struct instance_icecrown_citadel_InstanceMapScript : public InstanceScript
        {
            instance_icecrown_citadel_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                teamInInstance = 0;
                heroicAttempts = MaxHeroicAttempts;
                ladyDeathwisperElevator = 0;
                deathbringerSaurfang = 0;
                saurfangDoor = 0;
                saurfangEventNPC = 0;
                deathbringersCache = 0;
                saurfangTeleport = 0;
                plagueSigil = 0;
                bloodwingSigil = 0;
                frostwingSigil = 0;
                memset(putricidePipes, 0, 2*sizeof(uint64));
                memset(putricideGates, 0, 2*sizeof(uint64));
                putricideCollision = 0;
                festergut = 0;
                rotface = 0;
                professorPutricide = 0;
                putricideTable = 0;
                memset(bloodCouncil, 0, 3*sizeof(uint64));
                bloodCouncilController = 0;
                bloodQueenLanaThel = 0;
                sindragosa = 0;
                spinestalker = 0;
                rimefang = 0;
                frostwyrms = 0;
                spinestalkerTrash = 0;
                rimefangTrash = 0;
                isBonedEligible = true;
                isOozeDanceEligible = true;
                isNauseaEligible = true;
                isOrbWhispererEligible = true;
                coldflameJetsState = NOT_STARTED;
                bloodQuickeningState = NOT_STARTED;
                bloodQuickeningTimer = 0;
                bloodQuickeningMinutes = 0;
            }

            void FillInitialWorldStates(WorldPacket& data)
            {
                data << uint32(WORLDSTATE_SHOW_TIMER)         << uint32(bloodQuickeningState == IN_PROGRESS);
                data << uint32(WORLDSTATE_EXECUTION_TIME)     << uint32(bloodQuickeningMinutes);
                data << uint32(WORLDSTATE_SHOW_ATTEMPTS)      << uint32(instance->IsHeroic());
                data << uint32(WORLDSTATE_ATTEMPTS_REMAINING) << uint32(heroicAttempts);
                data << uint32(WORLDSTATE_ATTEMPTS_MAX)       << uint32(MaxHeroicAttempts);
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
                        if (Player* player = players.begin()->getSource())
                            teamInInstance = player->GetTeam();
                }

                switch (creature->GetEntry())
                {
                    case NPC_KOR_KRON_GENERAL:
                        if (teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_ALLIANCE_COMMANDER, ALLIANCE);
                        break;
                    case NPC_KOR_KRON_LIEUTENANT:
                        if (teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_SKYBREAKER_LIEUTENANT, ALLIANCE);
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
                    case NPC_DEATHBRINGER_SAURFANG:
                        deathbringerSaurfang = creature->GetGUID();
                        break;
                    case NPC_SE_HIGH_OVERLORD_SAURFANG:
                        if (teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_SE_MURADIN_BRONZEBEARD, ALLIANCE, creature->GetCreatureData());
                    case NPC_SE_MURADIN_BRONZEBEARD:
                        saurfangEventNPC = creature->GetGUID();
                        creature->LastUsedScriptID = creature->GetScriptId();
                        break;
                    case NPC_SE_KOR_KRON_REAVER:
                        if (teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_SE_SKYBREAKER_MARINE, ALLIANCE);
                        break;
                    case NPC_FROST_FREEZE_TRAP:
                        coldflameJets.insert(creature->GetGUID());
                        break;
                    case NPC_FESTERGUT:
                        festergut = creature->GetGUID();
                        break;
                    case NPC_ROTFACE:
                        rotface = creature->GetGUID();
                        break;
                    case NPC_PROFESSOR_PUTRICIDE:
                        professorPutricide = creature->GetGUID();
                        break;
                    case NPC_PRINCE_KELESETH:
                        bloodCouncil[0] = creature->GetGUID();
                        break;
                    case NPC_PRINCE_TALDARAM:
                        bloodCouncil[1] = creature->GetGUID();
                        break;
                    case NPC_PRINCE_VALANAR:
                        bloodCouncil[2] = creature->GetGUID();
                        break;
                    case NPC_BLOOD_ORB_CONTROLLER:
                        bloodCouncilController = creature->GetGUID();
                        break;
                    case NPC_BLOOD_QUEEN_LANA_THEL:
                        bloodQueenLanaThel = creature->GetGUID();
                        break;
                    case NPC_SINDRAGOSA:
                        sindragosa = creature->GetGUID();
                        break;
                    case NPC_SPINESTALKER:
                        spinestalker = creature->GetGUID();
                        if (!creature->isDead())
                            ++frostwyrms;
                        break;
                    case NPC_RIMEFANG:
                        rimefang = creature->GetGUID();
                        if (!creature->isDead())
                            ++frostwyrms;
                        break;
                    default:
                        break;
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
                        for (uint8 questIndex = 0; questIndex < WeeklyNPCs; ++questIndex)
                        {
                            if (WeeklyQuestData[questIndex].creatureEntry == entry)
                            {
                                uint8 diffIndex = uint8(instance->GetSpawnMode() & 1);
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

            void OnGameObjectCreate(GameObject* go)
            {
                switch (go->GetEntry())
                {
                    case GO_DOODAD_ICECROWN_ICEWALL02:
                    case GO_ICEWALL:
                    case GO_LORD_MARROWGAR_S_ENTRANCE:
                    case GO_ORATORY_OF_THE_DAMNED_ENTRANCE:
                    case GO_ORANGE_PLAGUE_MONSTER_ENTRANCE:
                    case GO_GREEN_PLAGUE_MONSTER_ENTRANCE:
                    case GO_SCIENTIST_ENTRANCE:
                    case GO_CRIMSON_HALL_DOOR:
                    case GO_BLOOD_ELF_COUNCIL_DOOR:
                    case GO_BLOOD_ELF_COUNCIL_DOOR_RIGHT:
                    case GO_DOODAD_ICECROWN_BLOODPRINCE_DOOR_01:
                    case GO_DOODAD_ICECROWN_GRATE_01:
                    case GO_GREEN_DRAGON_BOSS_ENTRANCE:
                    case GO_GREEN_DRAGON_BOSS_EXIT:
                    case GO_SINDRAGOSA_ENTRANCE_DOOR:
                    case GO_SINDRAGOSA_SHORTCUT_ENTRANCE_DOOR:
                    case GO_SINDRAGOSA_SHORTCUT_EXIT_DOOR:
                    case GO_ICE_WALL:
                        AddDoor(go, true);
                        break;
                    case GO_LADY_DEATHWHISPER_ELEVATOR:
                        ladyDeathwisperElevator = go->GetGUID();
                        if (GetBossState(DATA_LADY_DEATHWHISPER) == DONE)
                        {
                            go->SetUInt32Value(GAMEOBJECT_LEVEL, 0);
                            go->SetGoState(GO_STATE_READY);
                        }
                        break;
                    case GO_SAURFANG_S_DOOR:
                        saurfangDoor = go->GetGUID();
                        AddDoor(go, true);
                        break;
                    case GO_DEATHBRINGER_S_CACHE_10N:
                    case GO_DEATHBRINGER_S_CACHE_25N:
                    case GO_DEATHBRINGER_S_CACHE_10H:
                    case GO_DEATHBRINGER_S_CACHE_25H:
                        deathbringersCache = go->GetGUID();
                        break;
                    case GO_SCOURGE_TRANSPORTER_SAURFANG:
                        saurfangTeleport = go->GetGUID();
                        break;
                    case GO_PLAGUE_SIGIL:
                        plagueSigil = go->GetGUID();
                        if (GetBossState(DATA_PROFESSOR_PUTRICIDE) == DONE)
                            HandleGameObject(plagueSigil, false, go);
                        break;
                    case GO_BLOODWING_SIGIL:
                        bloodwingSigil = go->GetGUID();
                        if (GetBossState(DATA_BLOOD_QUEEN_LANA_THEL) == DONE)
                            HandleGameObject(bloodwingSigil, false, go);
                        break;
                    case GO_SIGIL_OF_THE_FROSTWING:
                        frostwingSigil = go->GetGUID();
                        if (GetBossState(DATA_SINDRAGOSA) == DONE)
                            HandleGameObject(frostwingSigil, false, go);
                        break;
                    case GO_SCIENTIST_AIRLOCK_DOOR_COLLISION:
                        putricideCollision = go->GetGUID();
                        if (GetBossState(DATA_FESTERGUT) == DONE && GetBossState(DATA_ROTFACE) == DONE)
                            HandleGameObject(putricideCollision, true, go);
                        break;
                    case GO_SCIENTIST_AIRLOCK_DOOR_ORANGE:
                        putricideGates[0] = go->GetGUID();
                        if (GetBossState(DATA_FESTERGUT) == DONE && GetBossState(DATA_ROTFACE) == DONE)
                            go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                        else if (GetBossState(DATA_FESTERGUT) == DONE)
                            HandleGameObject(putricideGates[1], false, go);
                        break;
                    case GO_SCIENTIST_AIRLOCK_DOOR_GREEN:
                        putricideGates[1] = go->GetGUID();
                        if (GetBossState(DATA_ROTFACE) == DONE && GetBossState(DATA_FESTERGUT) == DONE)
                            go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                        else if (GetBossState(DATA_ROTFACE) == DONE)
                            HandleGameObject(putricideGates[1], false, go);
                        break;
                    case GO_DOODAD_ICECROWN_ORANGETUBES02:
                        putricidePipes[0] = go->GetGUID();
                        if (GetBossState(DATA_FESTERGUT) == DONE)
                            HandleGameObject(putricidePipes[0], true, go);
                        break;
                    case GO_DOODAD_ICECROWN_GREENTUBES02:
                        putricidePipes[1] = go->GetGUID();
                        if (GetBossState(DATA_ROTFACE) == DONE)
                            HandleGameObject(putricidePipes[1], true, go);
                        break;
                    case GO_DRINK_ME:
                        putricideTable = go->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go)
            {
                switch (go->GetEntry())
                {
                    case GO_DOODAD_ICECROWN_ICEWALL02:
                    case GO_ICEWALL:
                    case GO_LORD_MARROWGAR_S_ENTRANCE:
                    case GO_ORATORY_OF_THE_DAMNED_ENTRANCE:
                    case GO_SAURFANG_S_DOOR:
                    case GO_ORANGE_PLAGUE_MONSTER_ENTRANCE:
                    case GO_GREEN_PLAGUE_MONSTER_ENTRANCE:
                    case GO_SCIENTIST_ENTRANCE:
                    case GO_CRIMSON_HALL_DOOR:
                    case GO_BLOOD_ELF_COUNCIL_DOOR:
                    case GO_BLOOD_ELF_COUNCIL_DOOR_RIGHT:
                    case GO_DOODAD_ICECROWN_BLOODPRINCE_DOOR_01:
                    case GO_DOODAD_ICECROWN_GRATE_01:
                    case GO_GREEN_DRAGON_BOSS_ENTRANCE:
                    case GO_GREEN_DRAGON_BOSS_EXIT:
                    case GO_SINDRAGOSA_ENTRANCE_DOOR:
                    case GO_SINDRAGOSA_SHORTCUT_ENTRANCE_DOOR:
                    case GO_SINDRAGOSA_SHORTCUT_EXIT_DOOR:
                    case GO_ICE_WALL:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type)
            {
                switch (type)
                {
                    case DATA_SINDRAGOSA_FROSTWYRMS:
                        return frostwyrms;
                    case DATA_SPINESTALKER:
                        return spinestalkerTrash;
                    case DATA_RIMEFANG:
                        return rimefangTrash;
                    case DATA_COLDFLAME_JETS:
                        return coldflameJetsState;
                    case DATA_TEAM_IN_INSTANCE:
                        return teamInInstance;
                    case DATA_BLOOD_QUICKENING_STATE:
                        return bloodQuickeningState;
                    case DATA_HEROIC_ATTEMPTS:
                        return heroicAttempts;
                    default:
                        break;
                }

                return 0;
            }

            uint64 GetData64(uint32 type)
            {
                switch (type)
                {
                    case DATA_DEATHBRINGER_SAURFANG:
                        return deathbringerSaurfang;
                    case DATA_SAURFANG_EVENT_NPC:
                        return saurfangEventNPC;
                    case GO_SAURFANG_S_DOOR:
                        return saurfangDoor;
                    case GO_SCOURGE_TRANSPORTER_SAURFANG:
                        return saurfangTeleport;
                    case DATA_FESTERGUT:
                        return festergut;
                    case DATA_ROTFACE:
                        return rotface;
                    case DATA_PROFESSOR_PUTRICIDE:
                        return professorPutricide;
                    case DATA_PUTRICIDE_TABLE:
                        return putricideTable;
                    case DATA_PRINCE_KELESETH_GUID:
                        return bloodCouncil[0];
                    case DATA_PRINCE_TALDARAM_GUID:
                        return bloodCouncil[1];
                    case DATA_PRINCE_VALANAR_GUID:
                        return bloodCouncil[2];
                    case DATA_BLOOD_PRINCES_CONTROL:
                        return bloodCouncilController;
                    case DATA_BLOOD_QUEEN_LANA_THEL:
                        return bloodQueenLanaThel;
                    case DATA_SINDRAGOSA:
                        return sindragosa;
                    case DATA_SPINESTALKER:
                        return spinestalker;
                    case DATA_RIMEFANG:
                        return rimefang;
                    default:
                        break;
                }

                return 0;
            }

            bool SetBossState(uint32 type, EncounterState state)
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_LADY_DEATHWHISPER:
                        SetBossState(DATA_GUNSHIP_EVENT, state);    // TEMP HACK UNTIL GUNSHIP SCRIPTED
                        if (state == DONE)
                            if (GameObject* elevator = instance->GetGameObject(ladyDeathwisperElevator))
                            {
                                elevator->SetUInt32Value(GAMEOBJECT_LEVEL, 0);
                                elevator->SetGoState(GO_STATE_READY);
                            }
                        break;
                    case DATA_DEATHBRINGER_SAURFANG:
                        switch (state)
                        {
                            case DONE:
                                DoRespawnGameObject(deathbringersCache, 7*DAY);
                            case NOT_STARTED:
                                if (GameObject* teleporter = instance->GetGameObject(saurfangTeleport))
                                {
                                    HandleGameObject(saurfangTeleport, true, teleporter);
                                    teleporter->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                                }
                                break;
                            default:
                                break;
                        }
                        break;
                    case DATA_FESTERGUT:
                        if (state == DONE)
                        {
                            if (GetBossState(DATA_ROTFACE) == DONE)
                            {
                                HandleGameObject(putricideCollision, true);
                                if (GameObject* go = instance->GetGameObject(putricideGates[0]))
                                    go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                                if (GameObject* go = instance->GetGameObject(putricideGates[1]))
                                    go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                            }
                            else
                                HandleGameObject(putricideGates[0], false);
                            HandleGameObject(putricidePipes[0], true);
                        }
                        break;
                    case DATA_ROTFACE:
                        if (state == DONE)
                        {
                            if (GetBossState(DATA_FESTERGUT) == DONE)
                            {
                                HandleGameObject(putricideCollision, true);
                                if (GameObject* go = instance->GetGameObject(putricideGates[0]))
                                    go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                                if (GameObject* go = instance->GetGameObject(putricideGates[1]))
                                    go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                            }
                            else
                                HandleGameObject(putricideGates[1], false);
                            HandleGameObject(putricidePipes[1], true);
                        }
                        break;
                    case DATA_PROFESSOR_PUTRICIDE:
                        HandleGameObject(plagueSigil, state != DONE);
                        if (instance->IsHeroic())
                        {
                            if (state == FAIL && heroicAttempts)
                            {
                                --heroicAttempts;
                                DoUpdateWorldState(WORLDSTATE_ATTEMPTS_REMAINING, heroicAttempts);
                                if (!heroicAttempts)
                                    if (Creature* putricide = instance->GetCreature(professorPutricide))
                                        putricide->DespawnOrUnsummon();
                            }
                        }
                        break;
                    case DATA_BLOOD_QUEEN_LANA_THEL:
                        HandleGameObject(bloodwingSigil, state != DONE);
                        if (instance->IsHeroic())
                        {
                            if (state == FAIL && heroicAttempts)
                            {
                                --heroicAttempts;
                                DoUpdateWorldState(WORLDSTATE_ATTEMPTS_REMAINING, heroicAttempts);
                                if (!heroicAttempts)
                                    if (Creature* bq = instance->GetCreature(bloodQueenLanaThel))
                                        bq->DespawnOrUnsummon();
                            }
                        }
                        break;
                    case DATA_VALITHRIA_DREAMWALKER:
                        break;
                    case DATA_SINDRAGOSA:
                        HandleGameObject(frostwingSigil, state != DONE);
                        if (instance->IsHeroic())
                        {
                            if (state == FAIL && heroicAttempts)
                            {
                                --heroicAttempts;
                                DoUpdateWorldState(WORLDSTATE_ATTEMPTS_REMAINING, heroicAttempts);
                                if (!heroicAttempts)
                                    if (Creature* sindra = instance->GetCreature(sindragosa))
                                        sindra->DespawnOrUnsummon();
                            }
                        }
                        break;
                    case DATA_THE_LICH_KING:
                        break;
                    default:
                        break;
                 }

                 return true;
            }

            void SetData(uint32 type, uint32 data)
            {
                switch (type)
                {
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
                    case DATA_SINDRAGOSA_FROSTWYRMS:
                        if (instance->IsHeroic() && !heroicAttempts)
                            return;
                        if (data > 1)
                            frostwyrms = data;
                        else if (data == 1)
                            ++frostwyrms;
                        else if (!data && !--frostwyrms && GetBossState(DATA_SINDRAGOSA) != DONE)
                        {
                            instance->LoadGrid(SindragosaSpawnPos.GetPositionX(), SindragosaSpawnPos.GetPositionY());
                            if (Creature* boss = instance->SummonCreature(NPC_SINDRAGOSA, SindragosaSpawnPos))
                            {
                                boss->setActive(true);
                                boss->AI()->DoAction(ACTION_START_FROSTWYRM);
                            }
                        }
                        break;
                    case DATA_SPINESTALKER:
                        if (data > 1)
                            spinestalkerTrash = data;
                        else if (data == 1)
                            ++spinestalkerTrash;
                        else if (!data && !--spinestalkerTrash)
                            if (Creature* spinestalk = instance->GetCreature(spinestalker))
                                spinestalk->AI()->DoAction(ACTION_START_FROSTWYRM);
                        break;
                    case DATA_RIMEFANG:
                        if (data > 1)
                            rimefangTrash = data;
                        else if (data == 1)
                            ++rimefangTrash;
                        else if (!data && !--rimefangTrash)
                            if (Creature* rime = instance->GetCreature(rimefang))
                                rime->AI()->DoAction(ACTION_START_FROSTWYRM);
                        break;
                    case DATA_COLDFLAME_JETS:
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
                        // 3 is the index of Blood Quickening
                        if (!sPoolMgr->IsSpawnedObject<Quest>(WeeklyQuestData[3].questId[instance->GetSpawnMode() & 1]))
                            break;
                        if (bloodQuickeningState == data)
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
                        }
                        bloodQuickeningState = data;
                        SaveToDB();
                        break;
                    }
                    default:
                        break;
                }
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
                    default:
                        break;
                }

                return false;
            }

            bool CheckRequiredBosses(uint32 bossId, Player const* player = NULL) const
            {
                if (player && player->isGameMaster())
                    return true;

                switch (bossId)
                {
                    case DATA_THE_LICH_KING:
                        if (!CheckPlagueworks(bossId))
                            return false;
                        if (!CheckCrimsonHalls(bossId))
                            return false;
                        if (!CheckFrostwingHalls(bossId))
                            return false;
                        break;
                    case DATA_SINDRAGOSA:
                    case DATA_VALITHRIA_DREAMWALKER:
                        if (!CheckFrostwingHalls(bossId))
                            return false;
                        break;
                    case DATA_BLOOD_QUEEN_LANA_THEL:
                    case DATA_BLOOD_PRINCE_COUNCIL:
                        if (!CheckCrimsonHalls(bossId))
                            return false;
                        break;
                    case DATA_FESTERGUT:
                    case DATA_ROTFACE:
                    case DATA_PROFESSOR_PUTRICIDE:
                        if (!CheckPlagueworks(bossId))
                            return false;
                        break;
                    default:
                        break;
                }

                if (!CheckLowerSpire(bossId))
                    return false;

                return true;
            }

            bool CheckPlagueworks(uint32 bossId) const
            {
                switch (bossId)
                {
                    case DATA_THE_LICH_KING:
                        if (GetBossState(DATA_PROFESSOR_PUTRICIDE) != DONE)
                            return false;
                        // no break
                    case DATA_PROFESSOR_PUTRICIDE:
                        if (GetBossState(DATA_FESTERGUT) != DONE || GetBossState(DATA_ROTFACE) != DONE)
                            return false;
                        break;
                    default:
                        break;
                }

                return true;
            }

            bool CheckCrimsonHalls(uint32 bossId) const
            {
                switch (bossId)
                {
                    case DATA_THE_LICH_KING:
                        if (GetBossState(DATA_BLOOD_QUEEN_LANA_THEL) != DONE)
                            return false;
                        // no break
                    case DATA_BLOOD_QUEEN_LANA_THEL:
                        if (GetBossState(DATA_BLOOD_PRINCE_COUNCIL) != DONE)
                            return false;
                        break;
                    default:
                        break;
                }

                return true;
            }

            bool CheckFrostwingHalls(uint32 bossId) const
            {
                switch (bossId)
                {
                    case DATA_THE_LICH_KING:
                        if (GetBossState(DATA_SINDRAGOSA) != DONE)
                            return false;
                        // no break
                    case DATA_SINDRAGOSA:
                        //if (GetBossState(DATA_VALITHRIA_DREAMWALKER) != DONE)
                        //    return false;
                        break;
                    default:
                        break;
                }

                return true;
            }

            bool CheckLowerSpire(uint32 bossId) const
            {
                switch (bossId)
                {
                    case DATA_THE_LICH_KING:
                    case DATA_SINDRAGOSA:
                    case DATA_BLOOD_QUEEN_LANA_THEL:
                    case DATA_PROFESSOR_PUTRICIDE:
                    case DATA_VALITHRIA_DREAMWALKER:
                    case DATA_BLOOD_PRINCE_COUNCIL:
                    case DATA_ROTFACE:
                    case DATA_FESTERGUT:
                        if (GetBossState(DATA_DEATHBRINGER_SAURFANG) != DONE)
                            return false;
                        // no break
                    case DATA_DEATHBRINGER_SAURFANG:
                        if (GetBossState(DATA_GUNSHIP_EVENT) != DONE)
                            return false;
                        // no break
                    case DATA_GUNSHIP_EVENT:
                        if (GetBossState(DATA_LADY_DEATHWHISPER) != DONE)
                            return false;
                        // no break
                    case DATA_LADY_DEATHWHISPER:
                        if (GetBossState(DATA_LORD_MARROWGAR) != DONE)
                            return false;
                        // no break
                    case DATA_LORD_MARROWGAR:
                    default:
                        break;
                }

                return true;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "I C " << GetBossSaveData() << coldflameJetsState
                    << " " << bloodQuickeningState << " " << bloodQuickeningMinutes;

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(const char* str)
            {
                if (!str)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(str);

                char dataHead1, dataHead2;

                std::istringstream loadStream(str);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'I' && dataHead2 == 'C')
                {
                    for (uint32 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }

                    uint32 temp = 0;
                    loadStream >> temp;
                    coldflameJetsState = temp ? DONE : NOT_STARTED;
                    temp = 0;
                    loadStream >> temp;
                    bloodQuickeningState = temp ? DONE : NOT_STARTED;   // DONE means finished (not success/fail)
                    loadStream >> bloodQuickeningMinutes;
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

            void Update(uint32 diff)
            {
                if (bloodQuickeningState == IN_PROGRESS)
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
                            if (Creature* bq = instance->GetCreature(bloodQueenLanaThel))
                                bq->AI()->DoAction(ACTION_KILL_MINCHAR);
                        }
                        SaveToDB();
                    }
                    else
                        bloodQuickeningTimer -= diff;
                }
            }

        private:
            std::set<uint64> coldflameJets;
            uint64 ladyDeathwisperElevator;
            uint64 deathbringerSaurfang;
            uint64 saurfangDoor;
            uint64 saurfangEventNPC;  // Muradin Bronzebeard or High Overlord Saurfang
            uint64 deathbringersCache;
            uint64 saurfangTeleport;
            uint64 plagueSigil;
            uint64 bloodwingSigil;
            uint64 frostwingSigil;
            uint64 putricidePipes[2];
            uint64 putricideGates[2];
            uint64 putricideCollision;
            uint64 festergut;
            uint64 rotface;
            uint64 professorPutricide;
            uint64 putricideTable;
            uint64 bloodCouncil[3];
            uint64 bloodCouncilController;
            uint64 bloodQueenLanaThel;
            uint64 sindragosa;
            uint64 spinestalker;
            uint64 rimefang;
            uint32 teamInInstance;
            uint32 bloodQuickeningTimer;
            uint32 coldflameJetsState;
            uint32 frostwyrms;
            uint32 spinestalkerTrash;
            uint32 rimefangTrash;
            uint32 bloodQuickeningState;
            uint16 heroicAttempts;
            uint16 bloodQuickeningMinutes;
            bool isBonedEligible;
            bool isOozeDanceEligible;
            bool isNauseaEligible;
            bool isOrbWhispererEligible;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_icecrown_citadel_InstanceMapScript(map);
        }
};

void AddSC_instance_icecrown_citadel()
{
    new instance_icecrown_citadel();
}
