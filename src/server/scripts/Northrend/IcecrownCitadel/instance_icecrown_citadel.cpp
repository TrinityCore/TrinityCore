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

#include "icecrown_citadel.h"
#include "AreaBoundary.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "EventMap.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QuestPools.h"
#include "ScriptMgr.h"
#include "TemporarySummon.h"
#include "Transport.h"
#include "TransportMgr.h"
#include "WorldStatePackets.h"
#include <sstream>
#include <unordered_set>

enum EventIds
{
    EVENT_PLAYERS_GUNSHIP_SPAWN     = 22663,
    EVENT_PLAYERS_GUNSHIP_COMBAT    = 22664,
    EVENT_PLAYERS_GUNSHIP_SAURFANG  = 22665,
    EVENT_ENEMY_GUNSHIP_COMBAT      = 22860,
    EVENT_ENEMY_GUNSHIP_DESPAWN     = 22861,
    EVENT_QUAKE                     = 23437,
    EVENT_SECOND_REMORSELESS_WINTER = 23507,
    EVENT_TELEPORT_TO_FROSTMOURNE   = 23617
};

enum TimedEvents
{
    EVENT_UPDATE_EXECUTION_TIME = 1,
    EVENT_QUAKE_SHATTER         = 2,
    EVENT_REBUILD_PLATFORM      = 3,
    EVENT_RESPAWN_GUNSHIP       = 4
};

enum SpawnGroups
{
    SPAWN_GROUP_ALLIANCE_ROS   = 57,
    SPAWN_GROUP_HORDE_ROS      = 58
};

BossBoundaryData const boundaries =
{
    { DATA_LORD_MARROWGAR,        new CircleBoundary(Position(-428.0f,2211.0f), 95.0) },
    { DATA_LORD_MARROWGAR,        new RectangleBoundary(-430.0f, -330.0f, 2110.0f, 2310.0f) },
    { DATA_LADY_DEATHWHISPER,     new RectangleBoundary(-670.0f, -520.0f, 2145.0f, 2280.0f) },
    { DATA_DEATHBRINGER_SAURFANG, new RectangleBoundary(-565.0f, -465.0f, 2160.0f, 2260.0f) },
    { DATA_ROTFACE,               new RectangleBoundary(4385.0f, 4505.0f, 3082.0f, 3195.0f) },
    { DATA_FESTERGUT,             new RectangleBoundary(4205.0f, 4325.0f, 3082.0f, 3195.0f) },
    { DATA_PROFESSOR_PUTRICIDE,   new ParallelogramBoundary(Position(4356.0f, 3290.0f), Position(4435.0f, 3194.0f), Position(4280.0f, 3194.0f)) },
    { DATA_PROFESSOR_PUTRICIDE,   new RectangleBoundary(4280.0f, 4435.0f, 3150.0f, 4360.0f) },
    { DATA_BLOOD_PRINCE_COUNCIL,  new EllipseBoundary(Position(4660.95f, 2769.194f), 85.0, 60.0) },
    { DATA_BLOOD_QUEEN_LANA_THEL, new CircleBoundary(Position(4595.93f, 2769.365f), 64.0) },
    { DATA_BLOOD_QUEEN_LANA_THEL, new ZRangeBoundary(391.78f, 473.43f) },
    { DATA_SISTER_SVALNA,         new RectangleBoundary(4291.0f, 4423.0f, 2438.0f, 2653.0f) },
    { DATA_VALITHRIA_DREAMWALKER, new RectangleBoundary(4112.5f, 4293.5f, 2385.0f, 2585.0f) },
    { DATA_SINDRAGOSA,            new EllipseBoundary(Position(4408.6f, 2484.0f), 100.0, 75.0) }
};

DoorData const doorData[] =
{
    { GO_LORD_MARROWGAR_S_ENTRANCE,           DATA_LORD_MARROWGAR,        DOOR_TYPE_ROOM },
    { GO_ICEWALL,                             DATA_LORD_MARROWGAR,        DOOR_TYPE_PASSAGE },
    { GO_DOODAD_ICECROWN_ICEWALL02,           DATA_LORD_MARROWGAR,        DOOR_TYPE_PASSAGE },
    { GO_ORATORY_OF_THE_DAMNED_ENTRANCE,      DATA_LADY_DEATHWHISPER,     DOOR_TYPE_ROOM  },
    { GO_SAURFANG_S_DOOR,                     DATA_DEATHBRINGER_SAURFANG, DOOR_TYPE_PASSAGE },
    { GO_ORANGE_PLAGUE_MONSTER_ENTRANCE,      DATA_FESTERGUT,             DOOR_TYPE_ROOM },
    { GO_GREEN_PLAGUE_MONSTER_ENTRANCE,       DATA_ROTFACE,               DOOR_TYPE_ROOM },
    { GO_SCIENTIST_ENTRANCE,                  DATA_PROFESSOR_PUTRICIDE,   DOOR_TYPE_ROOM },
    { GO_CRIMSON_HALL_DOOR,                   DATA_BLOOD_PRINCE_COUNCIL,  DOOR_TYPE_ROOM },
    { GO_BLOOD_ELF_COUNCIL_DOOR,              DATA_BLOOD_PRINCE_COUNCIL,  DOOR_TYPE_PASSAGE },
    { GO_BLOOD_ELF_COUNCIL_DOOR_RIGHT,        DATA_BLOOD_PRINCE_COUNCIL,  DOOR_TYPE_PASSAGE },
    { GO_DOODAD_ICECROWN_BLOODPRINCE_DOOR_01, DATA_BLOOD_QUEEN_LANA_THEL, DOOR_TYPE_ROOM },
    { GO_DOODAD_ICECROWN_GRATE_01,            DATA_BLOOD_QUEEN_LANA_THEL, DOOR_TYPE_PASSAGE },
    { GO_GREEN_DRAGON_BOSS_ENTRANCE,          DATA_SISTER_SVALNA,         DOOR_TYPE_PASSAGE },
    { GO_GREEN_DRAGON_BOSS_ENTRANCE,          DATA_VALITHRIA_DREAMWALKER, DOOR_TYPE_ROOM },
    { GO_GREEN_DRAGON_BOSS_EXIT,              DATA_VALITHRIA_DREAMWALKER, DOOR_TYPE_PASSAGE },
    { GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_01,  DATA_VALITHRIA_DREAMWALKER, DOOR_TYPE_SPAWN_HOLE },
    { GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_02,  DATA_VALITHRIA_DREAMWALKER, DOOR_TYPE_SPAWN_HOLE },
    { GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_03,  DATA_VALITHRIA_DREAMWALKER, DOOR_TYPE_SPAWN_HOLE },
    { GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_04,  DATA_VALITHRIA_DREAMWALKER, DOOR_TYPE_SPAWN_HOLE },
    { GO_SINDRAGOSA_ENTRANCE_DOOR,            DATA_SINDRAGOSA,            DOOR_TYPE_ROOM },
    { GO_SINDRAGOSA_SHORTCUT_ENTRANCE_DOOR,   DATA_SINDRAGOSA,            DOOR_TYPE_PASSAGE },
    { GO_SINDRAGOSA_SHORTCUT_EXIT_DOOR,       DATA_SINDRAGOSA,            DOOR_TYPE_PASSAGE },
    { GO_ICE_WALL,                            DATA_SINDRAGOSA,            DOOR_TYPE_ROOM },
    { GO_ICE_WALL,                            DATA_SINDRAGOSA,            DOOR_TYPE_ROOM },
    { 0,                                      0,                          DOOR_TYPE_ROOM }  // END
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
    { NPC_INFILTRATOR_MINCHAR,         { QUEST_DEPROGRAMMING_10,                 QUEST_DEPROGRAMMING_25                 } }, // Deprogramming
    { NPC_KOR_KRON_LIEUTENANT,         { QUEST_SECURING_THE_RAMPARTS_10,         QUEST_SECURING_THE_RAMPARTS_25         } }, // Securing the Ramparts
    { NPC_ROTTING_FROST_GIANT_10,      { QUEST_SECURING_THE_RAMPARTS_10,         QUEST_SECURING_THE_RAMPARTS_25         } }, // Securing the Ramparts
    { NPC_ROTTING_FROST_GIANT_25,      { QUEST_SECURING_THE_RAMPARTS_10,         QUEST_SECURING_THE_RAMPARTS_25         } }, // Securing the Ramparts
    { NPC_ALCHEMIST_ADRIANNA,          { QUEST_RESIDUE_RENDEZVOUS_10,            QUEST_RESIDUE_RENDEZVOUS_25            } }, // Residue Rendezvous
    { NPC_ALRIN_THE_AGILE,             { QUEST_BLOOD_QUICKENING_10,              QUEST_BLOOD_QUICKENING_25              } }, // Blood Quickening
    { NPC_INFILTRATOR_MINCHAR_BQ,      { QUEST_BLOOD_QUICKENING_10,              QUEST_BLOOD_QUICKENING_25              } }, // Blood Quickening
    { NPC_MINCHAR_BEAM_STALKER,        { QUEST_BLOOD_QUICKENING_10,              QUEST_BLOOD_QUICKENING_25              } }, // Blood Quickening
    { NPC_VALITHRIA_DREAMWALKER_QUEST, { QUEST_RESPITE_FOR_A_TORNMENTED_SOUL_10, QUEST_RESPITE_FOR_A_TORNMENTED_SOUL_25 } }  // Respite for a Tormented Soul
};

// NPCs spawned at Light's Hammer on Lich King dead
Position const JainaSpawnPos    = { -48.65278f, 2211.026f, 27.98586f, 3.124139f };
Position const MuradinSpawnPos  = { -47.34549f, 2208.087f, 27.98586f, 3.106686f };
Position const UtherSpawnPos    = { -26.58507f, 2211.524f, 30.19898f, 3.124139f };
Position const SylvanasSpawnPos = { -41.45833f, 2222.891f, 27.98586f, 3.647738f };

class instance_icecrown_citadel : public InstanceMapScript
{
    public:
        instance_icecrown_citadel() : InstanceMapScript(ICCScriptName, 631) { }

        struct instance_icecrown_citadel_InstanceMapScript : public InstanceScript
        {
            instance_icecrown_citadel_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadBossBoundaries(boundaries);
                LoadDoorData(doorData);
                TeamInInstance = map->GetTeamInInstance();
                HeroicAttempts = MaxHeroicAttempts;
                ColdflameJetsState = NOT_STARTED;
                UpperSpireTeleporterActiveState = NOT_STARTED;
                BloodQuickeningState = NOT_STARTED;
                BloodQuickeningMinutes = 0;
                BloodPrinceIntro = 1;
                SindragosaIntro = 1;
                IsBonedEligible = true;
                IsOozeDanceEligible = true;
                IsNauseaEligible = true;
                IsOrbWhispererEligible = true;
                IsFactionBuffActive = true;
            }

            // A function to help reduce the number of lines for teleporter management.
            void SetTeleporterState(GameObject* go, bool usable)
            {
                if (usable)
                {
                    go->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                    go->SetGoState(GO_STATE_ACTIVE);
                }
                else
                {
                    go->SetFlag(GO_FLAG_NOT_SELECTABLE);
                    go->SetGoState(GO_STATE_READY);
                }
            }

            void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override
            {
                packet.Worldstates.emplace_back(WORLDSTATE_SHOW_TIMER, BloodQuickeningState == IN_PROGRESS ? 1 : 0);
                packet.Worldstates.emplace_back(WORLDSTATE_EXECUTION_TIME, BloodQuickeningMinutes);
                packet.Worldstates.emplace_back(WORLDSTATE_SHOW_ATTEMPTS, instance->IsHeroic() ? 1 : 0);
                packet.Worldstates.emplace_back(WORLDSTATE_ATTEMPTS_REMAINING, HeroicAttempts);
                packet.Worldstates.emplace_back(WORLDSTATE_ATTEMPTS_MAX, MaxHeroicAttempts);
            }

            void OnPlayerEnter(Player* player) override
            {
                uint8 spawnGroupId = TeamInInstance == ALLIANCE ? SPAWN_GROUP_ALLIANCE_ROS : SPAWN_GROUP_HORDE_ROS;
                if (!instance->IsSpawnGroupActive(spawnGroupId))
                    instance->SpawnGroupSpawn(spawnGroupId);

                if (GetBossState(DATA_LADY_DEATHWHISPER) == DONE && GetBossState(DATA_ICECROWN_GUNSHIP_BATTLE) != DONE)
                    SpawnGunship();

                if (IsFactionBuffActive)
                    DoCastSpellOnPlayer(player, TeamInInstance == ALLIANCE ? SPELL_STRENGHT_OF_WRYNN : SPELL_HELLSCREAMS_WARSONG);
            }

            void OnPlayerLeave(Player* player) override
            {
                DoRemoveAurasDueToSpellOnPlayer(player, TeamInInstance == ALLIANCE ? SPELL_STRENGHT_OF_WRYNN : SPELL_HELLSCREAMS_WARSONG, true, true);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                if (creature->IsGuardian() && creature->GetOwnerGUID().IsPlayer())
                {
                    if (IsFactionBuffActive)
                        creature->CastSpell(creature, TeamInInstance == ALLIANCE ? SPELL_STRENGHT_OF_WRYNN : SPELL_HELLSCREAMS_WARSONG, true);
                }

                switch (creature->GetEntry())
                {
                    case NPC_NERUBAR_BROODKEEPER:
                    {
                        uint8 group = (creature->GetPositionX() > -230.0f) ? 0 : 1;
                        nerubarBroodkeepersGUIDs[group].emplace_back(creature->GetGUID());
                        break;
                    }
                    case NPC_LORD_MARROWGAR:
                        LordMarrowgarGUID = creature->GetGUID();
                        break;
                    case NPC_LADY_DEATHWHISPER:
                        LadyDeahtwhisperGUID = creature->GetGUID();
                        break;
                    case NPC_DEATHBRINGER_SAURFANG:
                        DeathbringerSaurfangGUID = creature->GetGUID();
                        break;
                    case NPC_ALLIANCE_GUNSHIP_CANNON:
                    case NPC_HORDE_GUNSHIP_CANNON:
                        creature->SetControlled(true, UNIT_STATE_ROOT);
                        break;
                    case NPC_SE_HIGH_OVERLORD_SAURFANG:
                    case NPC_SE_MURADIN_BRONZEBEARD:
                        DeathbringerSaurfangEventGUID = creature->GetGUID();
                        break;
                    case NPC_FESTERGUT:
                        FestergutGUID = creature->GetGUID();
                        break;
                    case NPC_ROTFACE:
                        RotfaceGUID = creature->GetGUID();
                        break;
                    case NPC_PROFESSOR_PUTRICIDE:
                        ProfessorPutricideGUID = creature->GetGUID();
                        break;
                    case NPC_VOLATILE_OOZE:
                    case NPC_GAS_CLOUD:
                        //! These creatures are summoned by something else than Professor Putricide
                        //! but need to be controlled/despawned by him - so they need to be
                        //! registered on his summon list
                        if (Creature* professorPutricide = instance->GetCreature(ProfessorPutricideGUID))
                            professorPutricide->AI()->JustSummoned(creature);
                        break;
                    case NPC_PRINCE_KELESETH:
                        BloodCouncilGUIDs[0] = creature->GetGUID();
                        break;
                    case NPC_PRINCE_TALDARAM:
                        BloodCouncilGUIDs[1] = creature->GetGUID();
                        break;
                    case NPC_PRINCE_VALANAR:
                        BloodCouncilGUIDs[2] = creature->GetGUID();
                        break;
                    case NPC_BLOOD_ORB_CONTROLLER:
                        BloodCouncilControllerGUID = creature->GetGUID();
                        break;
                    case NPC_BLOOD_QUEEN_LANA_THEL_COUNCIL:
                        BloodQueenLanaThelCouncilGUID = creature->GetGUID();
                        break;
                    case NPC_BLOOD_QUEEN_LANA_THEL:
                        BloodQueenLanaThelGUID = creature->GetGUID();
                        break;
                    case NPC_INFILTRATOR_MINCHAR_BQ:
                         // keep him in air
                         creature->SetEmoteState(EMOTE_ONESHOT_NONE);
                         creature->SetDisableGravity(true);
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
                        ValithriaDreamwalkerGUID = creature->GetGUID();
                        break;
                    case NPC_THE_LICH_KING_VALITHRIA:
                        ValithriaLichKingGUID = creature->GetGUID();
                        break;
                    case NPC_GREEN_DRAGON_COMBAT_TRIGGER:
                        ValithriaTriggerGUID = creature->GetGUID();
                        break;
                    case NPC_SINDRAGOSA:
                        SindragosaGUID = creature->GetGUID();
                        break;
                    case NPC_SPINESTALKER:
                        SpinestalkerGUID = creature->GetGUID();
                        break;
                    case NPC_RIMEFANG:
                        RimefangGUID = creature->GetGUID();
                        break;
                    case NPC_INVISIBLE_STALKER:
                        // Teleporter visual at center
                        if (creature->GetExactDist2d(4357.052f, 2769.421f) < 10.0f)
                            creature->CastSpell(creature, SPELL_ARTHAS_TELEPORTER_CEREMONY, false);
                        break;
                    case NPC_THE_LICH_KING:
                        TheLichKingGUID = creature->GetGUID();
                        break;
                    case NPC_HIGHLORD_TIRION_FORDRING_LK:
                        HighlordTirionFordringGUID = creature->GetGUID();
                        break;
                    case NPC_TERENAS_MENETHIL_FROSTMOURNE:
                    case NPC_TERENAS_MENETHIL_FROSTMOURNE_H:
                        TerenasMenethilGUID = creature->GetGUID();
                        break;
                    case NPC_WICKED_SPIRIT:
                        // Remove corpse as soon as it dies (and respawn 10 seconds later)
                        creature->SetCorpseDelay(0);
                        creature->SetReactState(REACT_PASSIVE);
                        break;
                    default:
                        break;
                }
            }

            void OnCreatureRemove(Creature* creature) override
            {
                if (creature->GetEntry() == NPC_SINDRAGOSA)
                    SindragosaGUID.Clear();
            }

            // Weekly quest spawn prevention
            uint32 GetCreatureEntry(ObjectGuid::LowType /*guidLow*/, CreatureData const* data) override
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
                                uint8 diffIndex = instance->Is25ManRaid() ? 1 : 0;
                                if (!sQuestPoolMgr->IsQuestActive(WeeklyQuestData[questIndex].questId[diffIndex]))
                                    return 0;
                                break;
                            }
                        }

                        if (entry == NPC_KOR_KRON_LIEUTENANT && TeamInInstance == ALLIANCE)
                            return NPC_SKYBREAKER_LIEUTENANT;
                        break;
                    }
                    case NPC_HORDE_GUNSHIP_CANNON:
                    case NPC_ORGRIMS_HAMMER_CREW:
                    case NPC_SKY_REAVER_KORM_BLACKSCAR:
                        if (TeamInInstance == ALLIANCE)
                            return 0;
                        break;
                    case NPC_ALLIANCE_GUNSHIP_CANNON:
                    case NPC_SKYBREAKER_DECKHAND:
                    case NPC_HIGH_CAPTAIN_JUSTIN_BARTLETT:
                        if (TeamInInstance == HORDE)
                            return 0;
                        break;
                    case NPC_ZAFOD_BOOMBOX:
                        if (GameObjectTemplate const* go = sObjectMgr->GetGameObjectTemplate(GO_THE_SKYBREAKER_A))
                            if ((TeamInInstance == ALLIANCE && int32(data->mapId) == go->moTransport.SpawnMap) ||
                                (TeamInInstance == HORDE && int32(data->mapId) != go->moTransport.SpawnMap))
                                return entry;
                        return 0;
                    case NPC_IGB_MURADIN_BRONZEBEARD:
                        if ((TeamInInstance == ALLIANCE && data->spawnPoint.GetPositionX() > 10.0f) ||
                            (TeamInInstance == HORDE && data->spawnPoint.GetPositionX() < 10.0f))
                            return entry;
                        return 0;
                    case NPC_SE_HIGH_OVERLORD_SAURFANG:
                        return TeamInInstance == ALLIANCE ? NPC_SE_MURADIN_BRONZEBEARD : NPC_SE_HIGH_OVERLORD_SAURFANG;
                    case NPC_KOR_KRON_GENERAL:
                        return TeamInInstance == ALLIANCE ? NPC_ALLIANCE_COMMANDER : NPC_KOR_KRON_GENERAL;
                    case NPC_TORTUNOK:
                        return TeamInInstance == ALLIANCE ? NPC_ALANA_MOONSTRIKE : NPC_TORTUNOK;
                    case NPC_GERARDO_THE_SUAVE:
                        return TeamInInstance == ALLIANCE ? NPC_TALAN_MOONSTRIKE : NPC_GERARDO_THE_SUAVE;
                    case NPC_UVLUS_BANEFIRE:
                        return TeamInInstance == ALLIANCE ? NPC_MALFUS_GRIMFROST : NPC_UVLUS_BANEFIRE;
                    case NPC_IKFIRUS_THE_VILE:
                        return TeamInInstance == ALLIANCE ? NPC_YILI : NPC_IKFIRUS_THE_VILE;
                    case NPC_VOL_GUK:
                        return TeamInInstance == ALLIANCE ? NPC_JEDEBIA : NPC_VOL_GUK;
                    case NPC_HARAGG_THE_UNSEEN:
                        return TeamInInstance == ALLIANCE ? NPC_NIBY_THE_ALMIGHTY : NPC_HARAGG_THE_UNSEEN;
                    case NPC_GARROSH_HELLSCREAM:
                        return TeamInInstance == ALLIANCE ? NPC_KING_VARIAN_WRYNN : NPC_GARROSH_HELLSCREAM;
                    case NPC_SE_KOR_KRON_REAVER:
                        return TeamInInstance == ALLIANCE ? NPC_SE_SKYBREAKER_MARINE : NPC_SE_KOR_KRON_REAVER;
                    default:
                        break;
                }

                return entry;
            }

            uint32 GetGameObjectEntry(ObjectGuid::LowType /*spawnId*/, uint32 entry) override
            {
                switch (entry)
                {
                    case GO_GUNSHIP_ARMORY_H_10N:
                    case GO_GUNSHIP_ARMORY_H_25N:
                    case GO_GUNSHIP_ARMORY_H_10H:
                    case GO_GUNSHIP_ARMORY_H_25H:
                        if (TeamInInstance == ALLIANCE)
                            return 0;
                        break;
                    case GO_GUNSHIP_ARMORY_A_10N:
                    case GO_GUNSHIP_ARMORY_A_25N:
                    case GO_GUNSHIP_ARMORY_A_10H:
                    case GO_GUNSHIP_ARMORY_A_25H:
                        if (TeamInInstance == HORDE)
                            return 0;
                        break;
                    default:
                        break;
                }

                return entry;
            }

            void OnUnitDeath(Unit* unit) override
            {
                Creature* creature = unit->ToCreature();
                if (!creature)
                    return;

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
                    case NPC_FROSTWING_WHELP:
                        if (FrostwyrmGUIDs.empty())
                            return;

                        if (creature->AI()->GetData(1/*DATA_FROSTWYRM_OWNER*/) == DATA_SPINESTALKER)
                        {
                            SpinestalkerTrash.erase(creature->GetSpawnId());
                            if (SpinestalkerTrash.empty())
                                if (Creature* spinestalk = instance->GetCreature(SpinestalkerGUID))
                                    spinestalk->AI()->DoAction(ACTION_START_FROSTWYRM);
                        }
                        else
                        {
                            RimefangTrash.erase(creature->GetSpawnId());
                            if (RimefangTrash.empty())
                                if (Creature* spinestalk = instance->GetCreature(RimefangGUID))
                                    spinestalk->AI()->DoAction(ACTION_START_FROSTWYRM);
                        }
                        break;
                    case NPC_RIMEFANG:
                    case NPC_SPINESTALKER:
                    {
                        if (instance->IsHeroic() && !HeroicAttempts)
                            return;

                        if (GetBossState(DATA_SINDRAGOSA) == DONE)
                            return;

                        FrostwyrmGUIDs.erase(creature->GetSpawnId());
                        if (FrostwyrmGUIDs.empty())
                        {
                            instance->LoadGrid(SindragosaSpawnPos.GetPositionX(), SindragosaSpawnPos.GetPositionY());
                            if (Creature* boss = instance->SummonCreature(NPC_SINDRAGOSA, SindragosaSpawnPos))
                                boss->AI()->DoAction(ACTION_START_FROSTWYRM);
                        }
                        break;
                    }
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
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
                    case GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_02:
                    case GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_03:
                    case GO_SINDRAGOSA_ENTRANCE_DOOR:
                    case GO_SINDRAGOSA_SHORTCUT_ENTRANCE_DOOR:
                    case GO_SINDRAGOSA_SHORTCUT_EXIT_DOOR:
                    case GO_ICE_WALL:
                        AddDoor(go, true);
                        break;
                    // these 2 gates are functional only on 25man modes
                    case GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_01:
                    case GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_04:
                        if (instance->Is25ManRaid())
                            AddDoor(go, true);
                        break;
                    case GO_LADY_DEATHWHISPER_ELEVATOR:
                        LadyDeathwisperElevatorGUID = go->GetGUID();
                        if (GetBossState(DATA_LADY_DEATHWHISPER) == DONE)
                        {
                            go->SetGoState(GO_STATE_TRANSPORT_ACTIVE);
                            go->HandleCustomTypeCommand(GameObjectType::SetTransportAutoCycleBetweenStopFrames(true));
                        }
                        break;
                    case GO_THE_SKYBREAKER_H:
                    case GO_ORGRIMS_HAMMER_A:
                        EnemyGunshipGUID = go->GetGUID();
                        break;
                    case GO_GUNSHIP_ARMORY_H_10N:
                    case GO_GUNSHIP_ARMORY_H_25N:
                    case GO_GUNSHIP_ARMORY_H_10H:
                    case GO_GUNSHIP_ARMORY_H_25H:
                    case GO_GUNSHIP_ARMORY_A_10N:
                    case GO_GUNSHIP_ARMORY_A_25N:
                    case GO_GUNSHIP_ARMORY_A_10H:
                    case GO_GUNSHIP_ARMORY_A_25H:
                        GunshipArmoryGUID = go->GetGUID();
                        break;
                    case GO_SAURFANG_S_DOOR:
                        DeathbringerSaurfangDoorGUID = go->GetGUID();
                        AddDoor(go, true);
                        break;
                    case GO_DEATHBRINGER_S_CACHE_10N:
                    case GO_DEATHBRINGER_S_CACHE_25N:
                    case GO_DEATHBRINGER_S_CACHE_10H:
                    case GO_DEATHBRINGER_S_CACHE_25H:
                        DeathbringersCacheGUID = go->GetGUID();
                        break;
                    case GO_SCOURGE_TRANSPORTER_LICHKING:
                        TeleporterLichKingGUID = go->GetGUID();
                        if (GetBossState(DATA_PROFESSOR_PUTRICIDE) == DONE && GetBossState(DATA_BLOOD_QUEEN_LANA_THEL) == DONE && GetBossState(DATA_SINDRAGOSA) == DONE)
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GO_SCOURGE_TRANSPORTER_UPPERSPIRE:
                        TeleporterUpperSpireGUID = go->GetGUID();
                        if (GetBossState(DATA_DEATHBRINGER_SAURFANG) != DONE || GetData(DATA_UPPERSPIRE_TELE_ACT) != DONE)
                            SetTeleporterState(go, false);
                        else
                            SetTeleporterState(go, true);
                        break;
                    case GO_SCOURGE_TRANSPORTER_LIGHTSHAMMER:
                        TeleporterLightsHammerGUID = go->GetGUID();
                        SetTeleporterState(go, GetBossState(DATA_LORD_MARROWGAR) == DONE);
                        break;
                    case GO_SCOURGE_TRANSPORTER_RAMPART:
                        TeleporterRampartsGUID = go->GetGUID();
                        SetTeleporterState(go, GetBossState(DATA_LADY_DEATHWHISPER) == DONE);
                        break;
                    case GO_SCOURGE_TRANSPORTER_DEATHBRINGER:
                        TeleporterDeathBringerGUID = go->GetGUID();
                        SetTeleporterState(go, GetBossState(DATA_ICECROWN_GUNSHIP_BATTLE) == DONE);
                        break;
                    case GO_SCOURGE_TRANSPORTER_ORATORY:
                        TeleporterOratoryGUID = go->GetGUID();
                        SetTeleporterState(go, GetBossState(DATA_LORD_MARROWGAR) == DONE);
                        break;
                    case GO_SCOURGE_TRANSPORTER_SINDRAGOSA:
                        TeleporterSindragosaGUID = go->GetGUID();
                        SetTeleporterState(go, GetBossState(DATA_VALITHRIA_DREAMWALKER) == DONE);
                        break;
                    case GO_PLAGUE_SIGIL:
                        PlagueSigilGUID = go->GetGUID();
                        if (GetBossState(DATA_PROFESSOR_PUTRICIDE) == DONE)
                            HandleGameObject(PlagueSigilGUID, false, go);
                        break;
                    case GO_BLOODWING_SIGIL:
                        BloodwingSigilGUID = go->GetGUID();
                        if (GetBossState(DATA_BLOOD_QUEEN_LANA_THEL) == DONE)
                            HandleGameObject(BloodwingSigilGUID, false, go);
                        break;
                    case GO_SIGIL_OF_THE_FROSTWING:
                        FrostwingSigilGUID = go->GetGUID();
                        if (GetBossState(DATA_SINDRAGOSA) == DONE)
                            HandleGameObject(FrostwingSigilGUID, false, go);
                        break;
                    case GO_SCIENTIST_AIRLOCK_DOOR_COLLISION:
                        PutricideCollisionGUID = go->GetGUID();
                        if (GetBossState(DATA_FESTERGUT) == DONE && GetBossState(DATA_ROTFACE) == DONE)
                            HandleGameObject(PutricideCollisionGUID, true, go);
                        break;
                    case GO_SCIENTIST_AIRLOCK_DOOR_ORANGE:
                        PutricideGateGUIDs[0] = go->GetGUID();
                        if (GetBossState(DATA_FESTERGUT) == DONE && GetBossState(DATA_ROTFACE) == DONE)
                            go->SetGoState(GO_STATE_DESTROYED);
                        else if (GetBossState(DATA_FESTERGUT) == DONE)
                            HandleGameObject(PutricideGateGUIDs[1], false, go);
                        break;
                    case GO_SCIENTIST_AIRLOCK_DOOR_GREEN:
                        PutricideGateGUIDs[1] = go->GetGUID();
                        if (GetBossState(DATA_ROTFACE) == DONE && GetBossState(DATA_FESTERGUT) == DONE)
                            go->SetGoState(GO_STATE_DESTROYED);
                        else if (GetBossState(DATA_ROTFACE) == DONE)
                            HandleGameObject(PutricideGateGUIDs[1], false, go);
                        break;
                    case GO_DOODAD_ICECROWN_ORANGETUBES02:
                        PutricidePipeGUIDs[0] = go->GetGUID();
                        if (GetBossState(DATA_FESTERGUT) == DONE)
                            HandleGameObject(PutricidePipeGUIDs[0], true, go);
                        break;
                    case GO_DOODAD_ICECROWN_GREENTUBES02:
                        PutricidePipeGUIDs[1] = go->GetGUID();
                        if (GetBossState(DATA_ROTFACE) == DONE)
                            HandleGameObject(PutricidePipeGUIDs[1], true, go);
                        break;
                    case GO_DRINK_ME:
                        PutricideTableGUID = go->GetGUID();
                        break;
                    case GO_CACHE_OF_THE_DREAMWALKER_10N:
                    case GO_CACHE_OF_THE_DREAMWALKER_25N:
                    case GO_CACHE_OF_THE_DREAMWALKER_10H:
                    case GO_CACHE_OF_THE_DREAMWALKER_25H:
                        if (Creature* valithria = instance->GetCreature(ValithriaDreamwalkerGUID))
                            go->SetLootRecipient(valithria->GetLootRecipient(), valithria->GetLootRecipientGroup());
                        go->RemoveFlag(GO_FLAG_LOCKED | GO_FLAG_NOT_SELECTABLE | GO_FLAG_NODESPAWN);
                        break;
                    case GO_ARTHAS_PLATFORM:
                        ArthasPlatformGUID = go->GetGUID();
                        break;
                    case GO_ARTHAS_PRECIPICE:
                        ArthasPrecipiceGUID = go->GetGUID();
                        break;
                    case GO_DOODAD_ICECROWN_THRONEFROSTYEDGE01:
                        FrozenThroneEdgeGUID = go->GetGUID();
                        break;
                    case GO_DOODAD_ICECROWN_THRONEFROSTYWIND01:
                        FrozenThroneWindGUID = go->GetGUID();
                        break;
                    case GO_DOODAD_ICECROWN_SNOWEDGEWARNING01:
                        FrozenThroneWarningGUID = go->GetGUID();
                        break;
                    case GO_FROZEN_LAVAMAN:
                        FrozenBolvarGUID = go->GetGUID();
                        if (GetBossState(DATA_THE_LICH_KING) == DONE)
                            go->SetRespawnTime(7 * DAY);
                        break;
                    case GO_LAVAMAN_PILLARS_CHAINED:
                        PillarsChainedGUID = go->GetGUID();
                        if (GetBossState(DATA_THE_LICH_KING) == DONE)
                            go->SetRespawnTime(7 * DAY);
                        break;
                    case GO_LAVAMAN_PILLARS_UNCHAINED:
                        PillarsUnchainedGUID = go->GetGUID();
                        if (GetBossState(DATA_THE_LICH_KING) == DONE)
                            go->SetRespawnTime(7 * DAY);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) override
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
                    case GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_01:
                    case GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_02:
                    case GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_03:
                    case GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_04:
                    case GO_SINDRAGOSA_ENTRANCE_DOOR:
                    case GO_SINDRAGOSA_SHORTCUT_ENTRANCE_DOOR:
                    case GO_SINDRAGOSA_SHORTCUT_EXIT_DOOR:
                    case GO_ICE_WALL:
                        AddDoor(go, false);
                        break;
                    case GO_THE_SKYBREAKER_A:
                    case GO_ORGRIMS_HAMMER_H:
                        GunshipGUID.Clear();
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_SINDRAGOSA_FROSTWYRMS:
                        return FrostwyrmGUIDs.size();
                    case DATA_SPINESTALKER:
                        return SpinestalkerTrash.size();
                    case DATA_RIMEFANG:
                        return RimefangTrash.size();
                    case DATA_COLDFLAME_JETS:
                        return ColdflameJetsState;
                    case DATA_UPPERSPIRE_TELE_ACT:
                        return UpperSpireTeleporterActiveState;
                    case DATA_TEAM_IN_INSTANCE:
                        return TeamInInstance;
                    case DATA_BLOOD_QUICKENING_STATE:
                        return BloodQuickeningState;
                    case DATA_HEROIC_ATTEMPTS:
                        return HeroicAttempts;
                    case DATA_BLOOD_PRINCE_COUNCIL_INTRO:
                        return BloodPrinceIntro;
                    case DATA_SINDRAGOSA_INTRO:
                        return SindragosaIntro;
                    case DATA_FACTION_BUFF:
                        return IsFactionBuffActive ? 1 : 0;
                    default:
                        break;
                }

                return 0;
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_LORD_MARROWGAR:
                        return LordMarrowgarGUID;
                    case DATA_LADY_DEATHWHISPER:
                        return LadyDeahtwhisperGUID;
                    case DATA_ICECROWN_GUNSHIP_BATTLE:
                        return GunshipGUID;
                    case DATA_ENEMY_GUNSHIP:
                        return EnemyGunshipGUID;
                    case DATA_DEATHBRINGER_SAURFANG:
                        return DeathbringerSaurfangGUID;
                    case DATA_SAURFANG_EVENT_NPC:
                        return DeathbringerSaurfangEventGUID;
                    case GO_SAURFANG_S_DOOR:
                        return DeathbringerSaurfangDoorGUID;
                    case DATA_FESTERGUT:
                        return FestergutGUID;
                    case DATA_ROTFACE:
                        return RotfaceGUID;
                    case DATA_PROFESSOR_PUTRICIDE:
                        return ProfessorPutricideGUID;
                    case DATA_PUTRICIDE_TABLE:
                        return PutricideTableGUID;
                    case DATA_PRINCE_KELESETH:
                        return BloodCouncilGUIDs[0];
                    case DATA_PRINCE_TALDARAM:
                        return BloodCouncilGUIDs[1];
                    case DATA_PRINCE_VALANAR:
                        return BloodCouncilGUIDs[2];
                    case DATA_BLOOD_PRINCES_CONTROL:
                        return BloodCouncilControllerGUID;
                    case DATA_BLOOD_QUEEN_LANA_THEL_COUNCIL:
                        return BloodQueenLanaThelCouncilGUID;
                    case DATA_BLOOD_QUEEN_LANA_THEL:
                        return BloodQueenLanaThelGUID;
                    case DATA_CROK_SCOURGEBANE:
                        return CrokScourgebaneGUID;
                    case DATA_CAPTAIN_ARNATH:
                    case DATA_CAPTAIN_BRANDON:
                    case DATA_CAPTAIN_GRONDEL:
                    case DATA_CAPTAIN_RUPERT:
                        return CrokCaptainGUIDs[type - DATA_CAPTAIN_ARNATH];
                    case DATA_SISTER_SVALNA:
                        return SisterSvalnaGUID;
                    case DATA_VALITHRIA_DREAMWALKER:
                        return ValithriaDreamwalkerGUID;
                    case DATA_VALITHRIA_LICH_KING:
                        return ValithriaLichKingGUID;
                    case DATA_VALITHRIA_TRIGGER:
                        return ValithriaTriggerGUID;
                    case DATA_SINDRAGOSA:
                        return SindragosaGUID;
                    case DATA_SPINESTALKER:
                        return SpinestalkerGUID;
                    case DATA_RIMEFANG:
                        return RimefangGUID;
                    case DATA_THE_LICH_KING:
                        return TheLichKingGUID;
                    case DATA_HIGHLORD_TIRION_FORDRING:
                        return HighlordTirionFordringGUID;
                    case DATA_ARTHAS_PLATFORM:
                        return ArthasPlatformGUID;
                    case DATA_TERENAS_MENETHIL:
                        return TerenasMenethilGUID;
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

            void HandleHeroicAttempts()
            {
                if (HeroicAttempts)
                {
                    --HeroicAttempts;
                    DoUpdateWorldState(WORLDSTATE_ATTEMPTS_REMAINING, HeroicAttempts);
                }

                if (!HeroicAttempts)
                {
                    for (ObjectGuid const& bossGuid : { ProfessorPutricideGUID, BloodQueenLanaThelGUID, SindragosaGUID, TheLichKingGUID })
                    {
                        if (Creature* boss = instance->GetCreature(bossGuid))
                            if (boss->IsAlive())
                                boss->DespawnOrUnsummon();
                    }
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_LORD_MARROWGAR:
                    {
                        if (state == DONE)
                        {
                            if (GameObject* teleporter = instance->GetGameObject(TeleporterLightsHammerGUID))
                                SetTeleporterState(teleporter, true);
                            if (GameObject* teleporter = instance->GetGameObject(TeleporterOratoryGUID))
                                SetTeleporterState(teleporter, true);
                        }
                        break;
                    }
                    case DATA_LADY_DEATHWHISPER:
                    {
                        if (state == DONE)
                        {
                            if (GameObject* teleporter = instance->GetGameObject(TeleporterRampartsGUID))
                                SetTeleporterState(teleporter, true);

                            if (GameObject* elevator = instance->GetGameObject(LadyDeathwisperElevatorGUID))
                            {
                                elevator->SetGoState(GO_STATE_TRANSPORT_ACTIVE);
                                elevator->HandleCustomTypeCommand(GameObjectType::SetTransportAutoCycleBetweenStopFrames(true));
                            }

                            SpawnGunship();
                        }
                        break;
                    }
                    case DATA_ICECROWN_GUNSHIP_BATTLE:
                        if (state == DONE)
                        {
                            if (GameObject* teleporter = instance->GetGameObject(TeleporterDeathBringerGUID))
                                SetTeleporterState(teleporter, true);

                            if (GameObject* loot = instance->GetGameObject(GunshipArmoryGUID))
                                loot->RemoveFlag(GO_FLAG_LOCKED | GO_FLAG_NOT_SELECTABLE | GO_FLAG_NODESPAWN);
                        }
                        else if (state == FAIL)
                            Events.ScheduleEvent(EVENT_RESPAWN_GUNSHIP, 30s);
                        break;
                    case DATA_DEATHBRINGER_SAURFANG:
                        switch (state)
                        {
                            case DONE:
                            {
                                if (GameObject* loot = instance->GetGameObject(DeathbringersCacheGUID))
                                {
                                    if (Creature* deathbringer = instance->GetCreature(DeathbringerSaurfangGUID))
                                        loot->SetLootRecipient(deathbringer->GetLootRecipient(), deathbringer->GetLootRecipientGroup());
                                    loot->RemoveFlag(GO_FLAG_LOCKED | GO_FLAG_NOT_SELECTABLE | GO_FLAG_NODESPAWN);
                                }

                                if (GameObject* teleporter = instance->GetGameObject(TeleporterUpperSpireGUID))
                                    SetTeleporterState(teleporter, true);

                                if (GameObject* teleporter = instance->GetGameObject(TeleporterDeathBringerGUID))
                                    SetTeleporterState(teleporter, true);
                                break;
                            }
                            case NOT_STARTED:
                            {
                                if (GameObject* teleporter = instance->GetGameObject(TeleporterDeathBringerGUID))
                                    SetTeleporterState(teleporter, true);
                                break;
                            }
                            case IN_PROGRESS:
                            {
                                if (GameObject* teleporter = instance->GetGameObject(TeleporterDeathBringerGUID))
                                    SetTeleporterState(teleporter, false);
                                break;
                            }
                            default:
                                break;
                        }
                        break;
                    case DATA_FESTERGUT:
                        if (state == DONE)
                        {
                            if (GetBossState(DATA_ROTFACE) == DONE)
                            {
                                HandleGameObject(PutricideCollisionGUID, true);
                                if (GameObject* go = instance->GetGameObject(PutricideGateGUIDs[0]))
                                    go->SetGoState(GO_STATE_DESTROYED);
                                if (GameObject* go = instance->GetGameObject(PutricideGateGUIDs[1]))
                                    go->SetGoState(GO_STATE_DESTROYED);
                            }
                            else
                                HandleGameObject(PutricideGateGUIDs[0], false);
                            HandleGameObject(PutricidePipeGUIDs[0], true);
                        }
                        break;
                    case DATA_ROTFACE:
                        if (state == DONE)
                        {
                            if (GetBossState(DATA_FESTERGUT) == DONE)
                            {
                                HandleGameObject(PutricideCollisionGUID, true);
                                if (GameObject* go = instance->GetGameObject(PutricideGateGUIDs[0]))
                                    go->SetGoState(GO_STATE_DESTROYED);
                                if (GameObject* go = instance->GetGameObject(PutricideGateGUIDs[1]))
                                    go->SetGoState(GO_STATE_DESTROYED);
                            }
                            else
                                HandleGameObject(PutricideGateGUIDs[1], false);
                            HandleGameObject(PutricidePipeGUIDs[1], true);
                        }
                        break;
                    case DATA_PROFESSOR_PUTRICIDE:
                        HandleGameObject(PlagueSigilGUID, state != DONE);
                        if (instance->IsHeroic() && state == FAIL)
                            HandleHeroicAttempts();
                        else if (state == DONE)
                            CheckLichKingAvailability();
                        break;
                    case DATA_BLOOD_QUEEN_LANA_THEL:
                        HandleGameObject(BloodwingSigilGUID, state != DONE);
                        if (instance->IsHeroic() && state == FAIL)
                            HandleHeroicAttempts();
                        else if (state == DONE)
                            CheckLichKingAvailability();
                        break;
                    case DATA_VALITHRIA_DREAMWALKER:
                        if (state == DONE)
                        {
                            if (sQuestPoolMgr->IsQuestActive(WeeklyQuestData[8].questId[instance->Is25ManRaid() ? 1 : 0]))
                                instance->SummonCreature(NPC_VALITHRIA_DREAMWALKER_QUEST, ValithriaSpawnPos);
                            if (GameObject* teleporter = instance->GetGameObject(TeleporterSindragosaGUID))
                                SetTeleporterState(teleporter, true);
                        }
                        break;
                    case DATA_SINDRAGOSA:
                        HandleGameObject(FrostwingSigilGUID, state != DONE);
                        if (instance->IsHeroic() && state == FAIL)
                            HandleHeroicAttempts();
                        else if (state == DONE)
                            CheckLichKingAvailability();
                        break;
                    case DATA_THE_LICH_KING:
                    {
                        // set the platform as active object to dramatically increase visibility range
                        // note: "active" gameobjects do not block grid unloading
                        if (GameObject* precipice = instance->GetGameObject(ArthasPrecipiceGUID))
                            precipice->SetFarVisible(state == IN_PROGRESS);

                        if (GameObject* platform = instance->GetGameObject(ArthasPlatformGUID))
                            platform->SetFarVisible(state == IN_PROGRESS);

                        if (instance->IsHeroic() && state == FAIL)
                            HandleHeroicAttempts();
                        else if (state == DONE)
                        {
                            if (GameObject* bolvar = instance->GetGameObject(FrozenBolvarGUID))
                                bolvar->SetRespawnTime(7 * DAY);
                            if (GameObject* pillars = instance->GetGameObject(PillarsChainedGUID))
                                pillars->SetRespawnTime(7 * DAY);
                            if (GameObject* pillars = instance->GetGameObject(PillarsUnchainedGUID))
                                pillars->SetRespawnTime(7 * DAY);

                            instance->SummonCreature(NPC_LADY_JAINA_PROUDMOORE_QUEST, JainaSpawnPos);
                            instance->SummonCreature(NPC_MURADIN_BRONZEBEARD_QUEST, MuradinSpawnPos);
                            instance->SummonCreature(NPC_UTHER_THE_LIGHTBRINGER_QUEST, UtherSpawnPos);
                            instance->SummonCreature(NPC_LADY_SYLVANAS_WINDRUNNER_QUEST, SylvanasSpawnPos);
                        }
                        break;
                    }
                    default:
                        break;
                 }

                 return true;
            }

            void SpawnGunship()
            {
                if (!GunshipGUID)
                {
                    SetBossState(DATA_ICECROWN_GUNSHIP_BATTLE, NOT_STARTED);
                    uint32 gunshipEntry = TeamInInstance == HORDE ? GO_ORGRIMS_HAMMER_H : GO_THE_SKYBREAKER_A;
                    if (Transport* gunship = sTransportMgr->CreateTransport(gunshipEntry, instance))
                        GunshipGUID = gunship->GetGUID();
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_BONED_ACHIEVEMENT:
                        IsBonedEligible = data ? true : false;
                        break;
                    case DATA_OOZE_DANCE_ACHIEVEMENT:
                        IsOozeDanceEligible = data ? true : false;
                        break;
                    case DATA_NAUSEA_ACHIEVEMENT:
                        IsNauseaEligible = data ? true : false;
                        break;
                    case DATA_ORB_WHISPERER_ACHIEVEMENT:
                        IsOrbWhispererEligible = data ? true : false;
                        break;
                    case DATA_COLDFLAME_JETS:
                        ColdflameJetsState = data;
                        if (ColdflameJetsState == DONE)
                            SaveToDB();
                        break;
                    case DATA_BLOOD_QUICKENING_STATE:
                    {
                        // skip if nothing changes
                        if (BloodQuickeningState == data)
                            break;

                        // 5 is the index of Blood Quickening
                        if (!sQuestPoolMgr->IsQuestActive(WeeklyQuestData[5].questId[instance->Is25ManRaid() ? 1 : 0]))
                            break;

                        switch (data)
                        {
                            case IN_PROGRESS:
                                Events.ScheduleEvent(EVENT_UPDATE_EXECUTION_TIME, 1min);
                                BloodQuickeningMinutes = 30;
                                DoUpdateWorldState(WORLDSTATE_SHOW_TIMER, 1);
                                DoUpdateWorldState(WORLDSTATE_EXECUTION_TIME, BloodQuickeningMinutes);
                                break;
                            case DONE:
                                Events.CancelEvent(EVENT_UPDATE_EXECUTION_TIME);
                                BloodQuickeningMinutes = 0;
                                DoUpdateWorldState(WORLDSTATE_SHOW_TIMER, 0);
                                break;
                            default:
                                break;
                        }

                        BloodQuickeningState = data;
                        SaveToDB();
                        break;
                    }
                    case DATA_UPPERSPIRE_TELE_ACT:
                        UpperSpireTeleporterActiveState = data;
                        if (UpperSpireTeleporterActiveState == DONE)
                        {
                            if (GameObject* go = instance->GetGameObject(TeleporterUpperSpireGUID))
                                SetTeleporterState(go, true);
                            SaveToDB();
                        }
                        break;
                    case DATA_BLOOD_PRINCE_COUNCIL_INTRO:
                        BloodPrinceIntro = data;
                        break;
                    case DATA_SINDRAGOSA_INTRO:
                        SindragosaIntro = data;
                        break;
                    case DATA_FACTION_BUFF:
                        IsFactionBuffActive = data ? true : false;
                        if (!IsFactionBuffActive)
                            DoRemoveAurasDueToSpellOnPlayers(TeamInInstance == ALLIANCE ? SPELL_STRENGHT_OF_WRYNN : SPELL_HELLSCREAMS_WARSONG, true, true);
                        break;
                    case DATA_NERUBAR_BROODKEEPER_EVENT:
                    {
                        uint8 group = (data == AT_NERUBAR_BROODKEEPER) ? 0 : 1;
                        for (ObjectGuid guid : nerubarBroodkeepersGUIDs[group])
                            if (Creature* nerubar = instance->GetCreature(guid))
                                nerubar->AI()->DoAction(ACTION_NERUBAR_FALL);
                        break;
                    }
                    default:
                        break;
                }
            }

            void SetGuidData(uint32 type, ObjectGuid guid) override
            {
                switch (type)
                {
                    case DATA_SINDRAGOSA_FROSTWYRMS:
                        FrostwyrmGUIDs.insert(guid.GetCounter());
                        break;
                    case DATA_SPINESTALKER:
                        SpinestalkerTrash.insert(guid.GetCounter());
                        break;
                    case DATA_RIMEFANG:
                        RimefangTrash.insert(guid.GetCounter());
                        break;
                }
            }

            bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target*/, uint32 /*miscvalue1*/) override
            {
                switch (criteria_id)
                {
                    case CRITERIA_BONED_10N:
                    case CRITERIA_BONED_25N:
                    case CRITERIA_BONED_10H:
                    case CRITERIA_BONED_25H:
                        return IsBonedEligible;
                    case CRITERIA_DANCES_WITH_OOZES_10N:
                    case CRITERIA_DANCES_WITH_OOZES_25N:
                    case CRITERIA_DANCES_WITH_OOZES_10H:
                    case CRITERIA_DANCES_WITH_OOZES_25H:
                        return IsOozeDanceEligible;
                    case CRITERIA_NAUSEA_10N:
                    case CRITERIA_NAUSEA_25N:
                    case CRITERIA_NAUSEA_10H:
                    case CRITERIA_NAUSEA_25H:
                        return IsNauseaEligible;
                    case CRITERIA_ORB_WHISPERER_10N:
                    case CRITERIA_ORB_WHISPERER_25N:
                    case CRITERIA_ORB_WHISPERER_10H:
                    case CRITERIA_ORB_WHISPERER_25H:
                        return IsOrbWhispererEligible;
                    // Only one criteria for both modes, need to do it like this
                    case CRITERIA_KILL_LANA_THEL_10M:
                    case CRITERIA_ONCE_BITTEN_TWICE_SHY_10N:
                    case CRITERIA_ONCE_BITTEN_TWICE_SHY_10V:
                        return instance->ToInstanceMap()->GetMaxPlayers() == 10;
                    case CRITERIA_KILL_LANA_THEL_25M:
                    case CRITERIA_ONCE_BITTEN_TWICE_SHY_25N:
                    case CRITERIA_ONCE_BITTEN_TWICE_SHY_25V:
                        return instance->ToInstanceMap()->GetMaxPlayers() == 25;
                    default:
                        break;
                }

                return false;
            }

            bool CheckRequiredBosses(uint32 bossId, Player const* player = nullptr) const override
            {
                if (_SkipCheckRequiredBosses(player))
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
                        [[fallthrough]];
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
                        [[fallthrough]];
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
                        [[fallthrough]];
                    case DATA_SINDRAGOSA:
                        if (GetBossState(DATA_VALITHRIA_DREAMWALKER) != DONE)
                            return false;
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
                        [[fallthrough]];
                    case DATA_DEATHBRINGER_SAURFANG:
                        if (GetBossState(DATA_ICECROWN_GUNSHIP_BATTLE) != DONE)
                            return false;
                        [[fallthrough]];
                    case DATA_ICECROWN_GUNSHIP_BATTLE:
                        if (GetBossState(DATA_LADY_DEATHWHISPER) != DONE)
                            return false;
                        [[fallthrough]];
                    case DATA_LADY_DEATHWHISPER:
                        if (GetBossState(DATA_LORD_MARROWGAR) != DONE)
                            return false;
                        [[fallthrough]];
                    case DATA_LORD_MARROWGAR:
                    default:
                        break;
                }

                return true;
            }

            void CheckLichKingAvailability()
            {
                if (GetBossState(DATA_PROFESSOR_PUTRICIDE) == DONE && GetBossState(DATA_BLOOD_QUEEN_LANA_THEL) == DONE && GetBossState(DATA_SINDRAGOSA) == DONE)
                {
                    if (GameObject* teleporter = instance->GetGameObject(TheLichKingTeleportGUID))
                    {
                        teleporter->SetGoState(GO_STATE_ACTIVE);

                        std::list<Creature*> stalkers;
                        teleporter->GetCreatureListWithEntryInGrid(stalkers, NPC_INVISIBLE_STALKER, 100.0f);
                        if (stalkers.empty())
                            return;

                        stalkers.sort(Trinity::ObjectDistanceOrderPred(teleporter));
                        stalkers.front()->CastSpell(nullptr, SPELL_ARTHAS_TELEPORTER_CEREMONY, false);
                        stalkers.pop_front();
                        for (std::list<Creature*>::iterator itr = stalkers.begin(); itr != stalkers.end(); ++itr)
                            (*itr)->AI()->Reset();
                    }
                }
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << HeroicAttempts << ' '
                    << ColdflameJetsState << ' '
                    << BloodQuickeningState << ' '
                    << BloodQuickeningMinutes << ' '
                    << UpperSpireTeleporterActiveState;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                uint32 temp = 0;

                data >> HeroicAttempts;

                data >> temp;
                ColdflameJetsState = temp == DONE ? DONE : NOT_STARTED;

                data >> temp;
                BloodQuickeningState = temp == DONE ? DONE : NOT_STARTED;

                data >> BloodQuickeningMinutes;

                data >> temp;
                UpperSpireTeleporterActiveState = temp == DONE ? DONE : NOT_STARTED;
            }

            void Update(uint32 diff) override
            {
                if (BloodQuickeningState != IN_PROGRESS && GetBossState(DATA_THE_LICH_KING) != IN_PROGRESS && GetBossState(DATA_ICECROWN_GUNSHIP_BATTLE) != FAIL)
                    return;

                Events.Update(diff);

                while (uint32 eventId = Events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_UPDATE_EXECUTION_TIME:
                        {
                            --BloodQuickeningMinutes;
                            if (BloodQuickeningMinutes)
                            {
                                Events.ScheduleEvent(EVENT_UPDATE_EXECUTION_TIME, 1min);
                                DoUpdateWorldState(WORLDSTATE_SHOW_TIMER, 1);
                                DoUpdateWorldState(WORLDSTATE_EXECUTION_TIME, BloodQuickeningMinutes);
                            }
                            else
                            {
                                BloodQuickeningState = DONE;
                                DoUpdateWorldState(WORLDSTATE_SHOW_TIMER, 0);
                                if (Creature* bq = instance->GetCreature(BloodQueenLanaThelGUID))
                                    bq->AI()->DoAction(ACTION_KILL_MINCHAR);
                            }
                            SaveToDB();
                            break;
                        }
                        case EVENT_QUAKE_SHATTER:
                        {
                            if (GameObject* platform = instance->GetGameObject(ArthasPlatformGUID))
                                platform->SetDestructibleState(GO_DESTRUCTIBLE_DAMAGED);
                            if (GameObject* edge = instance->GetGameObject(FrozenThroneEdgeGUID))
                                edge->SetGoState(GO_STATE_ACTIVE);
                            if (GameObject* wind = instance->GetGameObject(FrozenThroneWindGUID))
                                wind->SetGoState(GO_STATE_READY);
                            if (GameObject* warning = instance->GetGameObject(FrozenThroneWarningGUID))
                                warning->SetGoState(GO_STATE_READY);
                            if (Creature* theLichKing = instance->GetCreature(TheLichKingGUID))
                                theLichKing->AI()->DoAction(ACTION_RESTORE_LIGHT);
                            break;
                        }
                        case EVENT_REBUILD_PLATFORM:
                            if (GameObject* platform = instance->GetGameObject(ArthasPlatformGUID))
                                platform->SetDestructibleState(GO_DESTRUCTIBLE_REBUILDING);
                            if (GameObject* edge = instance->GetGameObject(FrozenThroneEdgeGUID))
                                edge->SetGoState(GO_STATE_READY);
                            if (GameObject* wind = instance->GetGameObject(FrozenThroneWindGUID))
                                wind->SetGoState(GO_STATE_ACTIVE);
                            break;
                        case EVENT_RESPAWN_GUNSHIP:
                            SpawnGunship();
                            break;
                        default:
                            break;
                    }
                }
            }

            void ProcessEvent(WorldObject* source, uint32 eventId, WorldObject* /*invoker*/) override
            {
                switch (eventId)
                {
                    case EVENT_ENEMY_GUNSHIP_DESPAWN:
                        if (GetBossState(DATA_ICECROWN_GUNSHIP_BATTLE) == DONE)
                            source->AddObjectToRemoveList();
                        break;
                    case EVENT_ENEMY_GUNSHIP_COMBAT:
                        if (Creature* captain = source->FindNearestCreature(TeamInInstance == HORDE ? NPC_IGB_HIGH_OVERLORD_SAURFANG : NPC_IGB_MURADIN_BRONZEBEARD, 100.0f))
                            captain->AI()->DoAction(ACTION_ENEMY_GUNSHIP_TALK);
                        [[fallthrough]];
                    case EVENT_PLAYERS_GUNSHIP_SPAWN:
                    case EVENT_PLAYERS_GUNSHIP_COMBAT:
                        if (GameObject* go = source->ToGameObject())
                            if (Transport* transport = go->ToTransport())
                                transport->EnableMovement(false);
                        break;
                    case EVENT_PLAYERS_GUNSHIP_SAURFANG:
                        if (Creature* captain = source->FindNearestCreature(TeamInInstance == HORDE ? NPC_IGB_HIGH_OVERLORD_SAURFANG : NPC_IGB_MURADIN_BRONZEBEARD, 100.0f))
                            captain->AI()->DoAction(ACTION_EXIT_SHIP);
                        if (GameObject* go = source->ToGameObject())
                            if (Transport* transport = go->ToTransport())
                                transport->EnableMovement(false);
                        break;
                    case EVENT_QUAKE:
                        if (GameObject* warning = instance->GetGameObject(FrozenThroneWarningGUID))
                            warning->SetGoState(GO_STATE_ACTIVE);
                        Events.ScheduleEvent(EVENT_QUAKE_SHATTER, 5s);
                        break;
                    case EVENT_SECOND_REMORSELESS_WINTER:
                        if (GameObject* platform = instance->GetGameObject(ArthasPlatformGUID))
                        {
                            platform->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);
                            Events.ScheduleEvent(EVENT_REBUILD_PLATFORM, 1500ms);
                        }
                        break;
                    case EVENT_TELEPORT_TO_FROSTMOURNE: // Harvest Soul (normal mode)
                        if (Creature* terenas = instance->SummonCreature(NPC_TERENAS_MENETHIL_FROSTMOURNE, TerenasSpawn, nullptr, 63000))
                        {
                            terenas->AI()->DoAction(ACTION_FROSTMOURNE_INTRO);
                            std::list<Creature*> triggers;
                            terenas->GetCreatureListWithEntryInGrid(triggers, NPC_WORLD_TRIGGER_INFINITE_AOI, 100.0f);
                            if (!triggers.empty())
                            {
                                triggers.sort(Trinity::ObjectDistanceOrderPred(terenas, false));
                                Unit* visual = triggers.front();
                                visual->CastSpell(visual, SPELL_FROSTMOURNE_TELEPORT_VISUAL, true);
                            }

                            if (Creature* warden = instance->SummonCreature(NPC_SPIRIT_WARDEN, SpiritWardenSpawn, nullptr, 63000))
                            {
                                terenas->AI()->AttackStart(warden);
                                warden->GetThreatManager().AddThreat(terenas, 300000.0f, nullptr, true, true);
                            }
                        }
                        break;
                    default:
                        break;
                }
            }

        protected:
            EventMap Events;
            ObjectGuid LordMarrowgarGUID;
            ObjectGuid LadyDeahtwhisperGUID;
            ObjectGuid LadyDeathwisperElevatorGUID;
            ObjectGuid GunshipGUID;
            ObjectGuid EnemyGunshipGUID;
            ObjectGuid GunshipArmoryGUID;
            ObjectGuid DeathbringerSaurfangGUID;
            ObjectGuid DeathbringerSaurfangDoorGUID;
            ObjectGuid DeathbringerSaurfangEventGUID;   // Muradin Bronzebeard or High Overlord Saurfang
            ObjectGuid DeathbringersCacheGUID;
            ObjectGuid TeleporterLichKingGUID;
            ObjectGuid TeleporterUpperSpireGUID;
            ObjectGuid TeleporterLightsHammerGUID;
            ObjectGuid TeleporterRampartsGUID;
            ObjectGuid TeleporterDeathBringerGUID;
            ObjectGuid TeleporterOratoryGUID;
            ObjectGuid TeleporterSindragosaGUID;
            ObjectGuid PlagueSigilGUID;
            ObjectGuid BloodwingSigilGUID;
            ObjectGuid FrostwingSigilGUID;
            ObjectGuid PutricidePipeGUIDs[2];
            ObjectGuid PutricideGateGUIDs[2];
            ObjectGuid PutricideCollisionGUID;
            ObjectGuid FestergutGUID;
            ObjectGuid RotfaceGUID;
            ObjectGuid ProfessorPutricideGUID;
            ObjectGuid PutricideTableGUID;
            ObjectGuid BloodCouncilGUIDs[3];
            ObjectGuid BloodCouncilControllerGUID;
            ObjectGuid BloodQueenLanaThelCouncilGUID;
            ObjectGuid BloodQueenLanaThelGUID;
            ObjectGuid CrokScourgebaneGUID;
            ObjectGuid CrokCaptainGUIDs[4];
            ObjectGuid SisterSvalnaGUID;
            ObjectGuid ValithriaDreamwalkerGUID;
            ObjectGuid ValithriaLichKingGUID;
            ObjectGuid ValithriaTriggerGUID;
            ObjectGuid SindragosaGUID;
            ObjectGuid SpinestalkerGUID;
            ObjectGuid RimefangGUID;
            ObjectGuid TheLichKingTeleportGUID;
            ObjectGuid TheLichKingGUID;
            ObjectGuid HighlordTirionFordringGUID;
            ObjectGuid TerenasMenethilGUID;
            ObjectGuid ArthasPlatformGUID;
            ObjectGuid ArthasPrecipiceGUID;
            ObjectGuid FrozenThroneEdgeGUID;
            ObjectGuid FrozenThroneWindGUID;
            ObjectGuid FrozenThroneWarningGUID;
            ObjectGuid FrozenBolvarGUID;
            ObjectGuid PillarsChainedGUID;
            ObjectGuid PillarsUnchainedGUID;
            Team TeamInInstance;
            uint32 ColdflameJetsState;
            uint32 UpperSpireTeleporterActiveState;
            std::unordered_set<ObjectGuid::LowType> FrostwyrmGUIDs;
            std::unordered_set<ObjectGuid::LowType> SpinestalkerTrash;
            std::unordered_set<ObjectGuid::LowType> RimefangTrash;
            uint32 BloodQuickeningState;
            uint32 HeroicAttempts;
            uint16 BloodQuickeningMinutes;
            uint8 BloodPrinceIntro;
            uint8 SindragosaIntro;
            bool IsBonedEligible;
            bool IsOozeDanceEligible;
            bool IsNauseaEligible;
            bool IsOrbWhispererEligible;
            bool IsFactionBuffActive;
            std::array<GuidVector, 2> nerubarBroodkeepersGUIDs;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_icecrown_citadel_InstanceMapScript(map);
        }
};

void AddSC_instance_icecrown_citadel()
{
    new instance_icecrown_citadel();
}
