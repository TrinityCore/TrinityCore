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
#include "halls_of_reflection.h"

#define MAX_ENCOUNTER 4

/* Halls of Reflection encounters:
0- Falric
1- Marwyn
2- The Lich King
*/

enum eEnum
{
    ENCOUNTER_WAVE_MERCENARY                      = 6,
    ENCOUNTER_WAVE_FOOTMAN                        = 10,
    ENCOUNTER_WAVE_RIFLEMAN                       = 6,
    ENCOUNTER_WAVE_PRIEST                         = 6,
    ENCOUNTER_WAVE_MAGE                           = 6,
    WAVE_STD_SPAWNCYCLE                           = 45 * IN_MILLISECONDS,
};

enum Events
{
    EVENT_NONE,
    EVENT_NEXT_WAVE,
    EVENT_START_LICH_KING,
};

static Position PriestSpawnPos[ENCOUNTER_WAVE_PRIEST] =
{
    {5277.74f, 2016.88f, 707.778f, 5.96903f},
    {5295.88f, 2040.34f, 707.778f, 5.07891f},
    {5320.37f, 1980.13f, 707.778f, 2.00713f},
    {5280.51f, 1997.84f, 707.778f, 0.296706f},
    {5302.45f, 2042.22f, 707.778f, 4.90438f},
    {5306.57f, 1977.47f, 707.778f, 1.50098f},
};

static Position MageSpawnPos[ENCOUNTER_WAVE_MAGE] =
{
    {5312.75f, 2037.12f, 707.778f, 4.59022f},
    {5309.58f, 2042.67f, 707.778f, 4.69494f},
    {5275.08f, 2008.72f, 707.778f, 6.21337f},
    {5279.65f, 2004.66f, 707.778f, 0.069813f},
    {5275.48f, 2001.14f, 707.778f, 0.174533f},
    {5316.7f, 2041.55f, 707.778f, 4.50295f},
};

static Position MercenarySpawnPos[ENCOUNTER_WAVE_MERCENARY] =
{
    {5302.25f, 1972.41f, 707.778f, 1.37881f},
    {5311.03f, 1972.23f, 707.778f, 1.64061f},
    {5277.36f, 1993.23f, 707.778f, 0.401426f},
    {5318.7f, 2036.11f, 707.778f, 4.2237f},
    {5335.72f, 1996.86f, 707.778f, 2.74017f},
    {5299.43f, 1979.01f, 707.778f, 1.23918f},
};

static Position FootmenSpawnPos[ENCOUNTER_WAVE_FOOTMAN] =
{
    {5306.06f, 2037, 707.778f, 4.81711f},
    {5344.15f, 2007.17f, 707.778f, 3.15905f},
    {5337.83f, 2010.06f, 707.778f, 3.22886f},
    {5343.29f, 1999.38f, 707.778f, 2.9147f},
    {5340.84f, 1992.46f, 707.778f, 2.75762f},
    {5325.07f, 1977.6f, 707.778f, 2.07694f},
    {5336.6f, 2017.28f, 707.778f, 3.47321f},
    {5313.82f, 1978.15f, 707.778f, 1.74533f},
    {5280.63f, 2012.16f, 707.778f, 6.05629f},
    {5322.96f, 2040.29f, 707.778f, 4.34587f},
};

static Position RiflemanSpawnPos[ENCOUNTER_WAVE_RIFLEMAN] =
{
    {5343.47f, 2015.95f, 707.778f, 3.49066f},
    {5337.86f, 2003.4f, 707.778f, 2.98451f},
    {5319.16f, 1974, 707.778f, 1.91986f},
    {5299.25f, 2036, 707.778f, 5.02655f},
    {5295.64f, 1973.76f, 707.778f, 1.18682f},
    {5282.9f, 2019.6f, 707.778f, 5.88176f},
};

class instance_halls_of_reflection : public InstanceMapScript
{
public:
    instance_halls_of_reflection() : InstanceMapScript("instance_halls_of_reflection", 668) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_halls_of_reflection_InstanceMapScript(map);
    }

    struct instance_halls_of_reflection_InstanceMapScript : public InstanceScript
    {
        instance_halls_of_reflection_InstanceMapScript(Map* map) : InstanceScript(map) {};

        uint64 uiFalric;
        uint64 uiMarwyn;
        uint64 uiLichKingEvent;
        uint64 uiJainaPart1;
        uint64 uiSylvanasPart1;
        uint64 uiLoralen;
        uint64 uiKoreln;
        uint64 uiLeader;

        uint64 uiGunship;
        uint64 uiChest;
        uint64 uiPortal;

        uint64 uiFrostmourne;
        uint64 uiFrostmourneAltar;
        uint64 uiFrostwornDoor;
        uint64 uiArthasDoor;
        uint64 uiFrontDoor;
        uint64 uiRunDoor;
        uint32 uiWall[4];
        uint64 uiWallID[4];
        uint64 uiCaveDoor;

        uint32 uiEncounter[MAX_ENCOUNTER];
        uint32 uiTeamInInstance;
        uint32 uiWaveCount;
        uint32 uiIntroDone;
        uint32 uiDataPhase;
        uint32 uiCurrentWall;
        uint32 uiWaveState;

        EventMap events;

        void Initialize()
        {
            events.Reset();

            uiFalric = 0;
            uiMarwyn = 0;
            uiLichKingEvent = 0;
            uiJainaPart1 = 0;
            uiSylvanasPart1 = 0;
            uiKoreln = 0;
            uiLoralen = 0;
            uiLeader = 0;

            uiGunship = 0;
            uiChest = 0;
            uiPortal = 0;

            uiFrostmourne = 0;
            uiFrostmourneAltar = 0;
            uiArthasDoor = 0;
            uiFrostwornDoor = 0;
            uiFrontDoor = 0;
            uiCaveDoor = 0;
            uiTeamInInstance = 0;
            uiWaveCount = 0;
            uiIntroDone = 0;
            uiCurrentWall = 0;
            uiWaveState = 0;

            for (uint8 i = 0; i < 4; ++i)
            {
                uiWall[i] = 0;
                uiWallID[i] = 0;
            }

            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                uiEncounter[i] = NOT_STARTED;
        }

        void OnCreatureCreate(Creature* creature)
        {

			if (uiTeamInInstance == 0)
			{
				Player* player = instance->GetPlayers().getFirst()->getSource();
				uiTeamInInstance = player->GetTeam();
			}

            switch (creature->GetEntry())
            {
                case NPC_FALRIC:
                case NPC_FALRIC_H:
                    uiFalric = creature->GetGUID();
                    creature->SetVisible(false);
                    creature->SetReactState(REACT_PASSIVE);
                    break;
                case NPC_MARWYN:
                case NPC_MARWYN_H:
                    uiMarwyn = creature->GetGUID();
                    creature->SetVisible(false);
                    creature->SetReactState(REACT_PASSIVE);
                    break;
                case NPC_LICH_KING_EVENT:
                    uiLichKingEvent = creature->GetGUID();
                    break;
                case NPC_JAINA_PART1:
                    if (uiTeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_SYLVANAS_PART1, HORDE);
                    uiJainaPart1 = creature->GetGUID();
                    uiSylvanasPart1 = creature->GetGUID();
                    break;
                case NPC_SYLVANAS_PART1:
                    if (uiTeamInInstance == ALLIANCE)
                        creature->UpdateEntry(NPC_JAINA_PART1, ALLIANCE);
                    uiJainaPart1 = creature->GetGUID();
                    uiSylvanasPart1 = creature->GetGUID();
                    break;
                case NPC_KORELN:
                    if (uiTeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_LORALEN, HORDE);
                    uiKoreln = creature->GetGUID();
                    uiLoralen = creature->GetGUID();
                    break;
                case NPC_LORALEN:
                    if (uiTeamInInstance == ALLIANCE)
                        creature->UpdateEntry(NPC_KORELN, ALLIANCE);
                    uiKoreln = creature->GetGUID();
                    uiLoralen = creature->GetGUID();
                    break;
                case NPC_JAINA_PART2:
                    if (uiTeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_SYLVANAS_PART2, HORDE);
                    uiLeader = creature->GetGUID();
                    break;
                case NPC_SYLVANAS_PART2:
                    if (uiTeamInInstance == ALLIANCE)
                        creature->UpdateEntry(NPC_JAINA_PART2, ALLIANCE);
                    uiLeader = creature->GetGUID();
                    break;
                case NPC_LICH_KING_BOSS:
                    uiLichKingEvent = creature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_FROSTMOURNE:
                    uiFrostmourne = go->GetGUID();
                    HandleGameObject(0, false, go);
                    break;
                case GO_FROSTMOURNE_ALTAR:
                    uiFrostmourneAltar = go->GetGUID();
                    HandleGameObject(0, true, go);
                    break;
                case GO_FRONT_DOOR:
                    uiFrontDoor = go->GetGUID();
                    HandleGameObject(0, true, go);
                    break;
                case GO_FROSTWORN_DOOR:
                    uiFrostwornDoor = go->GetGUID();

                    if (uiEncounter[1] == DONE)
                        HandleGameObject(0, true, go);
                    else
                        HandleGameObject(0, false, go);
                    break;
                case GO_RUN_DOOR:
                    uiRunDoor = go->GetGUID();
                    break;
                case GO_ARTHAS_DOOR:
                    uiArthasDoor = go->GetGUID();

                    if (uiEncounter[2] == DONE)
                        HandleGameObject(0, true, go);

                    if (uiEncounter[2] == DONE && uiEncounter[3] != DONE) // Frostworn General done and LK not, so spawn and open path to LK
                    {
                        SetData(DATA_PHASE, 3);
                        instance->SummonCreature(NPC_LICH_KING_BOSS, OutroSpawns[0]);
                        instance->SummonCreature(uiTeamInInstance == HORDE ? NPC_SYLVANAS_PART2 : NPC_JAINA_PART2, OutroSpawns[1]);
                    }

                    break;
                case GO_ICE_WALL_1:
                    uiWallID[0] = go->GetGUID();
                    break;
                case GO_ICE_WALL_2:
                    uiWallID[1] = go->GetGUID();
                    break;
                case GO_ICE_WALL_3:
                    uiWallID[2] = go->GetGUID();
                    break;
                case GO_ICE_WALL_4:
                    uiWallID[3] = go->GetGUID();
                    break;
                case GO_CAVE:
                    uiCaveDoor = go->GetGUID();
                    break;
                case GO_CAPTAIN_CHEST_1:
                    if (!instance->IsHeroic() && uiTeamInInstance == HORDE)
                        uiChest = go->GetGUID();
                    break;
                case GO_CAPTAIN_CHEST_3:
                    if (instance->IsHeroic() && uiTeamInInstance == HORDE)
                        uiChest = go->GetGUID();
                    break;
                case GO_CAPTAIN_CHEST_2:
                    if (!instance->IsHeroic() && uiTeamInInstance == ALLIANCE)
                        uiChest = go->GetGUID();
                    break;
                case GO_CAPTAIN_CHEST_4:
                    if (instance->IsHeroic() && uiTeamInInstance == ALLIANCE)
                        uiChest = go->GetGUID();
                    break;
                case GO_SKYBREAKER:
                    if (uiTeamInInstance == ALLIANCE)
                        uiGunship = go->GetGUID();
                    break;
                case GO_ORGRIM_HAMMER:
                    if (uiTeamInInstance == HORDE)
                        uiGunship = go->GetGUID();
                    break;
                case GO_PORTAL:
                    uiPortal = go->GetGUID();
                    break;
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            if (type == DATA_WIPE)
            {
                DoWipe();
                return;
            }

            if (type == DATA_WAVES_STATE && data == IN_PROGRESS)
            {
                uiWaveState = data;
                HandleGameObject(uiFrontDoor, false);
                events.CancelEvent(EVENT_NEXT_WAVE);
                events.ScheduleEvent(EVENT_NEXT_WAVE, 10000);
                return;
            }

            switch (type)
            {
                case DATA_INTRO_EVENT:
                    uiIntroDone = data;
                    break;
                case DATA_FALRIC_EVENT:
                    uiEncounter[0] = data;
                    if (data == DONE)
                    {
                        events.CancelEvent(EVENT_NEXT_WAVE);
                        events.ScheduleEvent(EVENT_NEXT_WAVE, WAVE_STD_SPAWNCYCLE);
                    }
                    break;
                case DATA_MARWYN_EVENT:
                    uiEncounter[1] = data;
                    if (data == DONE)
                    {
                        HandleGameObject(uiFrostwornDoor, true);
                        HandleGameObject(uiFrontDoor, true);
                    }
                    break;
                case DATA_FROSWORN_EVENT:
                    uiEncounter[2] = data;
                    if (data == DONE)
                    {
                        HandleGameObject(uiArthasDoor, true);
                        SetData(DATA_PHASE, 3);

                        instance->SummonCreature(NPC_LICH_KING_BOSS, OutroSpawns[0]);
                        instance->SummonCreature(uiTeamInInstance == HORDE ? NPC_SYLVANAS_PART2 : NPC_JAINA_PART2, OutroSpawns[1]);
                    }
                    break;
                case DATA_LICHKING_EVENT:
                    uiEncounter[3] = data;

                    if (data == IN_PROGRESS)
                    {
                        // Respawn all ice uiWalls on gossip select
                        for (uint8 i = 0; i<4; i++)
                            HandleGameObject(uiWallID[i], false);

                        // Open door on gossip select
                        HandleGameObject(uiRunDoor, true);
                        if (instance->IsHeroic())
                            DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_NOT_RETREATING_EVENT);
                    }

                    if (data == FAIL)
                    {
                        // Open ice uiWalls on wipe (way back for alive players)
                        for (uint8 i = 0; i<4; i++)
                            HandleGameObject(uiWallID[i], true);

                        // Open door on wipe (way back for alive players)
                        HandleGameObject(uiRunDoor, true);

                        if (Creature* pLichKing = instance->GetCreature(uiLichKingEvent))
                            pLichKing->DespawnOrUnsummon(10000);

                        if (Creature* pLeader = instance->GetCreature(uiLeader))
                            pLeader->DespawnOrUnsummon(10000);

                        DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_NOT_RETREATING_EVENT);
                        DoCastSpellOnPlayers(5); // Kill all players

                        SetData(DATA_PHASE, 3);
                        instance->SummonCreature(NPC_LICH_KING_BOSS, OutroSpawns[0]);
                        instance->SummonCreature(uiTeamInInstance == HORDE ? NPC_SYLVANAS_PART2 : NPC_JAINA_PART2, OutroSpawns[1]);
                    }

                    if (data == DONE)
                    {
                        // Open ice uiWalls on complete (way back for alive players)
                        for (uint8 i = 0; i<4; i++)
                            HandleGameObject(uiWallID[i], true);

                        // Open door on complete (way back for alive players)
                        HandleGameObject(uiRunDoor, true);

                        if (GameObject* pChest = instance->GetGameObject(uiChest))
                            pChest->SetPhaseMask(1, true);
                        if (GameObject* pPortal = instance->GetGameObject(uiPortal))
                            pPortal->SetPhaseMask(1, true);

                        if (!instance->IsHeroic())
                        {
                            DoCompleteAchievement(ACHIEV_HALLS_OF_REFLECTION_N);
                        }
                        else
                        {
                            DoCompleteAchievement(ACHIEV_HALLS_OF_REFLECTION_H);
                            DoCastSpellOnPlayers(SPELL_ACHIEV_CHECK);
                            DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_NOT_RETREATING_EVENT);
                        }

                    }
                    break;
                case DATA_ICE_WALL_1:
                    uiWall[0] = data;
                    if (data == IN_PROGRESS)
                    {
                        uiCurrentWall = 1;
                    }
                    break;
                case DATA_ICE_WALL_2:
                    uiWall[1] = data;
                    if (data == IN_PROGRESS)
                    {
                        uiCurrentWall = 2;
                    }
                    break;
                case DATA_ICE_WALL_3:
                    uiWall[2] = data;
                    if (data == IN_PROGRESS)
                    {
                        uiCurrentWall = 3;
                    }
                    break;
                case DATA_ICE_WALL_4:
                    uiWall[3] = data;
                    if (data == IN_PROGRESS)
                    {
                        uiCurrentWall = 4;
                    }
                    break;
                case DATA_PHASE:
                    uiDataPhase = data;
                    break;
                case DATA_CURRENT_WALL:
                    uiCurrentWall = data;
                    break;
                case DATA_WAVES_STATE:
                    uiWaveState = data;
                    break;
            }

            if (data == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 type)
        {
            switch (type)
            {
                case DATA_INTRO_EVENT:          return uiIntroDone;
                case DATA_TEAM_IN_INSTANCE:     return uiTeamInInstance;

                case DATA_FALRIC_EVENT:         return uiEncounter[0];
                case DATA_MARWYN_EVENT:         return uiEncounter[1];
                case DATA_WAVE_COUNT:           return uiWaveCount;
                case DATA_WAVES_STATE:          return uiWaveState;

                case DATA_FROSWORN_EVENT:       return uiEncounter[2];

                case DATA_LICHKING_EVENT:       return uiEncounter[3];
                case DATA_ICE_WALL_1:           return uiWall[0];
                case DATA_ICE_WALL_2:           return uiWall[1];
                case DATA_ICE_WALL_3:           return uiWall[2];
                case DATA_ICE_WALL_4:           return uiWall[3];
                case DATA_PHASE:                return uiDataPhase;
                case DATA_CURRENT_WALL:         return uiCurrentWall;
            }

            return 0;
        }

        uint64 GetData64(uint32 identifier)
        {
            switch (identifier)
            {
                case DATA_FALRIC:               return uiFalric;
                case DATA_MARWYN:               return uiMarwyn;
                case DATA_LICHKING:             return uiLichKingEvent;
                case DATA_ESCAPE_LEADER:        return uiLeader;
                case DATA_FROSTMOURNE:          return uiFrostmourne;
                case DATA_FRONT_DOOR:           return uiFrontDoor;
                case DATA_FROSTWORN_DOOR:       return uiFrostwornDoor;
                case DATA_ARTHAS_DOOR:          return uiArthasDoor;
                case DATA_RUN_DOOR:             return uiRunDoor;
                case GO_ICE_WALL_1:             return uiWallID[0];
                case GO_ICE_WALL_2:             return uiWallID[1];
                case GO_ICE_WALL_3:             return uiWallID[2];
                case GO_ICE_WALL_4:             return uiWallID[3];
                case GO_CAVE:                   return uiCaveDoor;
                case GO_CAPTAIN_CHEST_1:
                case GO_CAPTAIN_CHEST_2:
                case GO_CAPTAIN_CHEST_3:
                case GO_CAPTAIN_CHEST_4:        return uiChest;
                case GO_SKYBREAKER:
                case GO_ORGRIM_HAMMER:            return uiGunship;
            }

            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "H R " << uiEncounter[0] << " " << uiEncounter[1] << " " << uiEncounter[2] << " " << uiEncounter[3] << " " << uiIntroDone;

            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
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
            uint16 data0, data1, data2, data3, data4;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3 >> data4;

            if (dataHead1 == 'H' && dataHead2 == 'R')
            {
                uiEncounter[0] = data0;
                uiEncounter[1] = data1;
                uiEncounter[2] = data2;
                uiEncounter[3] = data3;
                uiIntroDone = data4;

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (uiEncounter[i] == IN_PROGRESS)
                        uiEncounter[i] = NOT_STARTED;

                if (uiEncounter[0] == DONE)
                    uiWaveCount = 5;

            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        void AddWave()
        {
            DoUpdateWorldState(WORLD_STATE_HOR, 1);
            DoUpdateWorldState(WORLD_STATE_HOR_WAVE_COUNT, uiWaveCount);
            if (uiWaveCount > 10)    // should not happen, either
                return;
            switch (uiWaveCount)
            {
                case 1:
                case 2:
                case 3:
                case 4:
                    if (Creature* pFalric = instance->GetCreature(uiFalric))
                        SpawnWave(pFalric);
                    events.CancelEvent(EVENT_NEXT_WAVE);
                    events.ScheduleEvent(EVENT_NEXT_WAVE, WAVE_STD_SPAWNCYCLE);
                    break;
                case 5:
                    if (GetData(DATA_FALRIC_EVENT) == DONE)
                    {
                        events.CancelEvent(EVENT_NEXT_WAVE);
                        events.ScheduleEvent(EVENT_NEXT_WAVE, WAVE_STD_SPAWNCYCLE / 3);
                    }
                    else if (Creature* pFalric = instance->GetCreature(uiFalric))
                    {
                        pFalric->SetReactState(REACT_AGGRESSIVE);
                        pFalric->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        if (pFalric->AI())
                            pFalric->AI()->DoAction(ACTION_ENTER_COMBAT);
                    }
                    break;
                case 6:
                case 7:
                case 8:
                case 9:
                    if (Creature* pMarwyn  = instance->GetCreature(uiMarwyn))
                        SpawnWave(pMarwyn);
                    events.CancelEvent(EVENT_NEXT_WAVE);
                    events.ScheduleEvent(EVENT_NEXT_WAVE, WAVE_STD_SPAWNCYCLE);
                    break;
                case 10:
                    if (GetData(DATA_MARWYN_EVENT) != DONE) // wave should not be started if DONE. Check anyway to avoid bug exploit!
                        if (Creature* pMarwyn = instance->GetCreature(uiMarwyn))
                        {
                            pMarwyn->SetReactState(REACT_AGGRESSIVE);
                            pMarwyn->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            if (pMarwyn->AI())
                                pMarwyn->AI()->DoAction(ACTION_ENTER_COMBAT);
                        }

                        break;
                default:
                    break;
            }
        }

        // Wipe has been detected. Perform cleanup and reset.
        void DoWipe()
        {
            if (GetData(DATA_WAVES_STATE) == IN_PROGRESS)    // are the waves already done ?
            {
                HandleGameObject(uiFrontDoor, true);
                HandleGameObject(uiFrostwornDoor, false);
                // Reset - set down to the last uiEncounter that was fulfilled
                if (GetData(DATA_FALRIC_EVENT) != DONE)
                {
                    SetData(DATA_WAVES_STATE, FAIL);
                    uiWaveCount = 0;
                    events.Reset();
                    DoUpdateWorldState(WORLD_STATE_HOR, 1);
                    DoUpdateWorldState(WORLD_STATE_HOR_WAVE_COUNT, uiWaveCount);
                    if (GetData(DATA_INTRO_EVENT) == DONE)
                    {
                        if (Creature* pMarwyn = instance->GetCreature(uiMarwyn))
                            pMarwyn->SetVisible(true);
                        if (Creature* pFalric = instance->GetCreature(uiFalric))
                            pFalric->SetVisible(true);
                    }
                }
                else if (GetData(DATA_MARWYN_EVENT) != DONE)
                {
                    SetData(DATA_WAVES_STATE, FAIL);
                    uiWaveCount = 5;
                    events.Reset();
                    DoUpdateWorldState(WORLD_STATE_HOR, 1);
                    DoUpdateWorldState(WORLD_STATE_HOR_WAVE_COUNT, uiWaveCount);
                    if (GetData(DATA_INTRO_EVENT) == DONE)
                    {
                        if (Creature* pMarwyn = instance->GetCreature(uiMarwyn))
                            pMarwyn->SetVisible(true);
                    }
                }
            }
            else
            {
                // Falric and Marwyn have been finished by the group
                if (GetData(DATA_LICHKING_EVENT) == NOT_STARTED)
                {
                    // Lichking-Event was not started yet, i.e. the group has wiped on the Frostworn General
                    HandleGameObject(uiFrontDoor, true);

                    if (GetData(DATA_MARWYN_EVENT) == DONE)
                        HandleGameObject(uiFrostwornDoor, true);
                }
                else
                {
                    // Group has wiped on escape
                    SetData(DATA_LICHKING_EVENT, NOT_STARTED);
                    SetData(DATA_WIPE, 1);
                    Creature* pSylvanasOrJaina = instance->GetCreature(GetData64(DATA_ESCAPE_LEADER));
                    if (pSylvanasOrJaina && pSylvanasOrJaina->GetAI())
                    {
                        pSylvanasOrJaina->Respawn(true);
                        pSylvanasOrJaina->GetAI()->Reset();
                    }
                    Creature* pLichKing = instance->GetCreature(GetData64(DATA_LICHKING));
                    if (pLichKing && pLichKing->GetAI())
                    {
                        pLichKing->Respawn(true);
                        pLichKing->GetAI()->Reset();
                    }
                    // TODO: maybe something is missing here
                }
            }
        }

        // spawn a wave on behalf of the summoner.
        void SpawnWave(Creature* summoner)
        {
            uint32 numSpawns = 4 + (uiWaveCount > 5 ? (instance->IsHeroic() ? 2 : 1) : 0); // Additional adds on later waves
            Position pos;
            summoner->SetVisible(true);

            for (uint32 i = 0; i < numSpawns; i++)
            {
                uint32 entry = RAND(NPC_WAVE_MERCENARY, NPC_WAVE_FOOTMAN, NPC_WAVE_RIFLEMAN, NPC_WAVE_PRIEST, NPC_WAVE_MAGE);

                switch (entry)
                {
                    case NPC_WAVE_MERCENARY:
                        pos = MercenarySpawnPos[urand(0, ENCOUNTER_WAVE_MERCENARY-1)];
                        break;
                    case NPC_WAVE_FOOTMAN:
                        pos = FootmenSpawnPos[urand(0, ENCOUNTER_WAVE_FOOTMAN-1)];
                        break;
                    case NPC_WAVE_RIFLEMAN:
                        pos = RiflemanSpawnPos[urand(0, ENCOUNTER_WAVE_RIFLEMAN-1)];
                        break;
                    case NPC_WAVE_PRIEST:
                        pos = PriestSpawnPos[urand(0, ENCOUNTER_WAVE_PRIEST-1)];
                        break;
                    case NPC_WAVE_MAGE:
                        pos = MageSpawnPos[urand(0, ENCOUNTER_WAVE_MAGE-1)];
                        break;
                }

                // We need a fast despawn here, otherwise the DoWipe check will fail and instance will get stuck
                summoner->SummonCreature(entry, pos, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
            }

        }

        void Update(uint32 diff)
        {
            if (!instance->HavePlayers())
                return;

            // if boss-fight is in progress, no events have to be executed!
            if ((GetData(DATA_FALRIC_EVENT) == IN_PROGRESS) || GetData(DATA_MARWYN_EVENT) == IN_PROGRESS)
            {
                // there should not be _any_ event of next_wave during boss-fight
                events.CancelEvent(EVENT_NEXT_WAVE);
                return;
            }
            else if (GetData(DATA_MARWYN_EVENT) == DONE)
            {
                events.CancelEvent(EVENT_NEXT_WAVE);
            }

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_NEXT_WAVE:
                    uiWaveCount++;
                    AddWave();
                    break;
            }
        }
    };

};

void AddSC_instance_halls_of_reflection()
{
    new instance_halls_of_reflection();
}
