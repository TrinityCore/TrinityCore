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

#include "ScriptPCH.h"
#include "halls_of_reflection.h"

/* Halls of Reflection encounters:
0- Falric
1- Marwyn
2- Frostworn General
3- The Lich King
*/

enum eEnum
{
    ENCOUNTER_WAVE_MERCENARY                      = 6,
    ENCOUNTER_WAVE_FOOTMAN                        = 10,
    ENCOUNTER_WAVE_RIFLEMAN                       = 6,
    ENCOUNTER_WAVE_PRIEST                         = 6,
    ENCOUNTER_WAVE_MAGE                           = 6,
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
    {5316.7f,  2041.55f, 707.778f, 4.50295f},
};

static Position MercenarySpawnPos[ENCOUNTER_WAVE_MERCENARY] =
{
    {5302.25f, 1972.41f, 707.778f, 1.37881f},
    {5311.03f, 1972.23f, 707.778f, 1.64061f},
    {5277.36f, 1993.23f, 707.778f, 0.401426f},
    {5318.7f,  2036.11f, 707.778f, 4.2237f},
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
    {5336.6f,  2017.28f, 707.778f, 3.47321f},
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
    {5282.9f,  2019.6f, 707.778f, 5.88176f},
};

class instance_halls_of_reflection : public InstanceMapScript
{
public:
    instance_halls_of_reflection() : InstanceMapScript("instance_halls_of_reflection", 668) { }

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_halls_of_reflection_InstanceMapScript(pMap);
    }

    struct instance_halls_of_reflection_InstanceMapScript : public InstanceScript
    {
        instance_halls_of_reflection_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {};

        uint64 uiFalric;
        uint64 uiMarwyn;
        uint64 uiLichKing;
        uint64 uiJainaPart1;
        uint64 uiSylvanasPart1;
        uint64 uiLoralen;
        uint64 uiKoreln;
        uint64 uiLider;

        uint64 uiGunship;
        uint64 uiChest;
        uint64 uiPortal;

        uint64 uiFrostmourne;
        uint64 uiFrontDoor;
        uint64 uiFrostwornDoor;
        uint64 uiArthasDoor;
        uint64 uiRunDoor;
        uint64 uiWall[4];
        uint64 uiWallID[4];
        uint64 uiCaveDoor;

        uint32 uiEncounter[MAX_ENCOUNTER];
        uint32 uiTeamInInstance;
        uint32 uiWaveCount;
        uint32 uiIntroDone;
        uint32 uiSummons;
        uint32 uiDataPhase;

        EventMap events;

        void Initialize()
        {
            events.Reset();

            uiFalric = 0;
            uiMarwyn = 0;
            uiLichKing = 0;
            uiJainaPart1 = 0;
            uiSylvanasPart1 = 0;
            uiKoreln = 0;
            uiLoralen = 0;
            uiLider = 0;

            uiGunship = 0;
            uiChest = 0;
            uiPortal = 0;

            uiFrostmourne = 0;
            uiArthasDoor = 0;
            uiFrostwornDoor = 0;
            uiFrontDoor = 0;
            uiCaveDoor = 0;
            uiTeamInInstance = 0;
            uiWaveCount = 0;
            uiIntroDone = 0;

            for (uint8 i = 0; i < 4; ++i)
            {
                uiWall[i] = 0;
                uiWallID[i] = 0;
            }

            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                uiEncounter[i] = NOT_STARTED;
        }

        void OpenDoor(uint64 guid)
        {
            if(!guid) return;
            GameObject* go = instance->GetGameObject(guid);
            if(go) go->SetGoState(GO_STATE_ACTIVE);
        }

        void CloseDoor(uint64 guid)
        {
            if(!guid) return;
            GameObject* go = instance->GetGameObject(guid);
            if(go) go->SetGoState(GO_STATE_READY);
        }

        void OnCreatureCreate(Creature* creature)
        {
            Map::PlayerList const &players = instance->GetPlayers();
            if (!players.isEmpty())
                if (Player* pPlayer = players.begin()->getSource())
                    uiTeamInInstance = pPlayer->GetTeam();

            switch(creature->GetEntry())
            {
                case NPC_FALRIC:
                    uiFalric = creature->GetGUID();
                    break;
                case NPC_MARWYN:
                    uiMarwyn = creature->GetGUID();
                    break;
                case NPC_LICH_KING_EVENT:
                    break;
                case NPC_JAINA_PART1:
                    if (uiTeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_SYLVANAS_PART1, HORDE);                    
                    uiJainaPart1 = creature->GetGUID();
                    uiSylvanasPart1 = creature->GetGUID();                    
                    break;
                case NPC_KORELN:
                    if (uiTeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_LORALEN, HORDE);
                    uiKoreln = creature->GetGUID();
                    uiLoralen = creature->GetGUID();
                    break;
                case NPC_SYLVANAS_PART1:
                    uiSylvanasPart1 = creature->GetGUID();
                    break;
                case NPC_FROSTWORN_GENERAL:
                    creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    break;
                case NPC_JAINA_OUTRO:
                    if (uiTeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_SYLVANA_OUTRO, HORDE);
                    creature->SetHealth(252000);
                    uiLider = creature->GetGUID();
                    break;
                case BOSS_LICH_KING:
                    creature->SetHealth(20917000);
                    uiLichKing = creature->GetGUID();
                    break;                    
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            // TODO: init state depending on encounters
            switch(go->GetEntry())
            {
                case GO_FROSTMOURNE:
                    uiFrostmourne = go->GetGUID();
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                    HandleGameObject(0, false, go);
                    break;
                case GO_FROSTMOURNE_ALTAR:
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                    HandleGameObject(0, true, go);
                    break;
                case GO_FRONT_DOOR:
                    uiFrontDoor = go->GetGUID();
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                    OpenDoor(uiFrontDoor);
                    break;
                case GO_FROSTWORN_DOOR:
                    uiFrostwornDoor = go->GetGUID();
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);

                    if (uiEncounter[1] == DONE)
                        OpenDoor(uiFrostwornDoor);
                    else
                        CloseDoor(uiFrostwornDoor);
                    break;
                case GO_RUN_DOOR:
                    uiRunDoor = go->GetGUID();
                    break;
                case GO_ARTHAS_DOOR:
                    uiArthasDoor = go->GetGUID();
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
                    go->SetPhaseMask(2, true);
                    if (!instance->IsHeroic() && uiTeamInInstance == HORDE)
                        uiChest = go->GetGUID();
                    break;
                case GO_CAPTAIN_CHEST_3:
                    go->SetPhaseMask(2, true);
                    if (instance->IsHeroic() && uiTeamInInstance == HORDE)
                        uiChest = go->GetGUID();
                    break;
                case GO_CAPTAIN_CHEST_2:
                    go->SetPhaseMask(2, true);
                    if (!instance->IsHeroic() && uiTeamInInstance == ALLIANCE)
                        uiChest = go->GetGUID();
                    break;
                case GO_CAPTAIN_CHEST_4:
                    go->SetPhaseMask(2, true);
                    if (instance->IsHeroic() && uiTeamInInstance == ALLIANCE)
                        uiChest = go->GetGUID();
                    break;
                case GO_SKYBREAKER:
                    go->SetPhaseMask(2, true);
                    if (uiTeamInInstance == ALLIANCE)
                        uiGunship = go->GetGUID();
                    break;
                case GO_ORGRIM_HAMMER:
                    go->SetPhaseMask(2, true);
                    if (uiTeamInInstance == HORDE)
                        uiGunship = go->GetGUID();
                    break;
                case GO_PORTAL:
                    go->SetPhaseMask(2, true);
                    uiPortal = go->GetGUID();
                    break;
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            if (type == DATA_WAVE_COUNT && data == SPECIAL)
            {
                CloseDoor(uiFrontDoor);
                events.ScheduleEvent(EVENT_NEXT_WAVE, 10000);
                return;
            }

            if (uiWaveCount && data == NOT_STARTED)
                DoWipe();

            switch(type)
            {
                case DATA_INTRO_EVENT:
                    uiIntroDone = data;
                    break;
                case DATA_FALRIC_EVENT:
                    uiEncounter[0] = data;
                    if (data == DONE)
                        events.ScheduleEvent(EVENT_NEXT_WAVE, 60000);
                    break;
                case DATA_MARWYN_EVENT:
                    uiEncounter[1] = data;
                    if (data == DONE)
                    {
                        OpenDoor(uiFrostwornDoor);
                        OpenDoor(uiFrontDoor);
                    }
                    break;
                case DATA_FROSWORN_EVENT:
                    uiEncounter[2] = data;
                    if (data == DONE)
                    {
                        OpenDoor(uiArthasDoor);
                        SetData(DATA_PHASE, 3);
                        instance->SummonCreature(BOSS_LICH_KING, OutroSpawns[0]);
                        instance->SummonCreature(NPC_JAINA_OUTRO, OutroSpawns[1]);
                    }
                    break;
                case DATA_LICHKING_EVENT:
                    uiEncounter[3] = data;
                    if(data == IN_PROGRESS)
                    {
                        OpenDoor(uiRunDoor);

                        if(instance->IsHeroic())
                            DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_NOT_RETREATING_EVENT);
                    }
                    if(data == FAIL)
                    {
                        for(uint8 i = 0; i<4; i++)
                            OpenDoor(uiWallID[i]);

                        CloseDoor(uiRunDoor);

                        if(Creature* pLichKing = instance->GetCreature(uiLichKing))
                            pLichKing->DespawnOrUnsummon(10000);
                        if(Creature* pLider = instance->GetCreature(uiLider))
                            pLider->DespawnOrUnsummon(10000);

                        DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_NOT_RETREATING_EVENT);
                        DoCastSpellOnPlayers(5); // Kill all players

                        SetData(DATA_PHASE, 3);
                        instance->SummonCreature(BOSS_LICH_KING, OutroSpawns[0]);
                        instance->SummonCreature(NPC_JAINA_OUTRO, OutroSpawns[1]);
                    }
                    if(data == DONE)
                    {
                        if(GameObject *pChest = instance->GetGameObject(uiChest))
                            pChest->SetPhaseMask(1, true);
                        if(GameObject *pPortal = instance->GetGameObject(uiPortal))
                            pPortal->SetPhaseMask(1, true);

                        DoCompleteAchievement(ACHIEV_HALLS_OF_REFLECTION_N);
                        if(instance->IsHeroic())
                        {
                            DoCompleteAchievement(ACHIEV_HALLS_OF_REFLECTION_H);
                            DoCastSpellOnPlayers(SPELL_ACHIEV_CHECK);
                            DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_NOT_RETREATING_EVENT);
                        }
                    }
                    break;
                case DATA_SUMMONS:
                    if (data == 3) uiSummons = 0;
                    else if (data == 1) ++uiSummons;
                    else if (data == 0) --uiSummons;
                    data = NOT_STARTED;
                    break;
                case DATA_ICE_WALL_1:
                    uiWall[0] = data;
                    break;
                case DATA_ICE_WALL_2:
                    uiWall[1] = data;
                    break;
                case DATA_ICE_WALL_3:
                    uiWall[2] = data;
                    break;
                case DATA_ICE_WALL_4:
                    uiWall[3] = data;
                    break;
                case DATA_PHASE:
                    uiDataPhase = data;
                    break;
            }

            if (data == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 type)
        {
            switch(type)
            {
                case DATA_INTRO_EVENT:          return uiIntroDone;
                case DATA_TEAM_IN_INSTANCE:     return uiTeamInInstance;

                case DATA_FALRIC_EVENT:         return uiEncounter[0];
                case DATA_MARWYN_EVENT:         return uiEncounter[1];
                case DATA_WAVE_COUNT:           return uiWaveCount;

                case DATA_FROSWORN_EVENT:       return uiEncounter[2];

                case DATA_LICHKING_EVENT:       return uiEncounter[3];
                case DATA_ICE_WALL_1:           return uiWall[0];
                case DATA_ICE_WALL_2:           return uiWall[1];
                case DATA_ICE_WALL_3:           return uiWall[2];
                case DATA_ICE_WALL_4:           return uiWall[3];
                case DATA_SUMMONS:              return uiSummons;

                case DATA_PHASE:                return uiDataPhase;
            }

            return 0;
        }

        uint64 GetData64(uint32 identifier)
        {
            switch(identifier)
            {
                case DATA_FALRIC:               return uiFalric;
                case DATA_MARWYN:               return uiMarwyn;
                case DATA_LICHKING:             return uiLichKing;
                case DATA_ESCAPE_LIDER:         return uiLider;
                case DATA_FROSTMOURNE:          return uiFrostmourne;
                case DATA_FRONT_DOOR:           return uiFrontDoor;
                case DATA_FROSTWORN_DOOR:       return uiFrostwornDoor;
                case DATA_ARTHAS_DOOR:          return uiArthasDoor;
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
            saveStream << "H R 1 " << uiEncounter[0] << " " << uiEncounter[1] << " " << uiEncounter[2] << " " << uiEncounter[3] << " " << uiIntroDone;

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
            uint16 version;
            uint16 data0, data1, data2, data3, data4;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> version >> data0 >> data1 >> data2 >> data3 >> data4;

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

                OpenDoor(uiFrontDoor);
                if (uiEncounter[1] == DONE)
                    OpenDoor(uiFrostwornDoor);
                if (uiEncounter[2] == DONE)
                    OpenDoor(uiArthasDoor);

            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        void AddWave()
        {
            DoUpdateWorldState(WORLD_STATE_HOR, 1);
            DoUpdateWorldState(WORLD_STATE_HOR_WAVE_COUNT, uiWaveCount);

            switch(uiWaveCount)
            {
                case 1:
                case 2:
                case 3:
                case 4:
                    if (Creature* pFalric = instance->GetCreature(uiFalric))
                        SpawnWave(pFalric);
                    break;
                case 5:
                    if (GetData(DATA_FALRIC_EVENT) == DONE)
                        events.ScheduleEvent(EVENT_NEXT_WAVE, 10000);
                    else if (Creature* pFalric = instance->GetCreature(uiFalric))
                        if (pFalric->AI())
                            pFalric->AI()->DoAction(ACTION_ENTER_COMBAT);
                    break;
                case 6:
                case 7:
                case 8:
                case 9:
                    if (Creature* pMarwyn  = instance->GetCreature(uiMarwyn))
                        SpawnWave(pMarwyn);
                    break;
                case 10:
                    if (GetData(DATA_MARWYN_EVENT) != DONE) // wave should not have been started if DONE. Check anyway to avoid bug exploit!
                        if (Creature* pMarwyn = instance->GetCreature(uiMarwyn))
                            if (pMarwyn->AI())
                                pMarwyn->AI()->DoAction(ACTION_ENTER_COMBAT);
                    break;
            }
        }

        // Wipe has been detected. Perform cleanup and reset.
        void DoWipe()
        {
            
            if (GetData(DATA_MARWYN_EVENT) != DONE) {
                
                SetData(DATA_WAVE_COUNT, FAIL);
                uiWaveCount = 0;
                events.Reset();
                DoUpdateWorldState(WORLD_STATE_HOR, 1);
                DoUpdateWorldState(WORLD_STATE_HOR_WAVE_COUNT, uiWaveCount);
                OpenDoor(uiFrontDoor);

            // TODO
            // in case of wipe, the event is normally restarted by jumping into the center of the room.
            // As I can't find a trigger area there, just respawn Jaina/Sylvanas so the event may be restarted.
            if (Creature* pFalric = instance->GetCreature(uiFalric))
                pFalric->SetVisible(false);
            if (Creature* pMarwyn = instance->GetCreature(uiMarwyn))
                pMarwyn->SetVisible(false);
            }
        }

        // spawn a wave on behalf of the summoner.
        void SpawnWave(Creature* pSummoner)
        {
            uint32 index;

            pSummoner->SetVisible(true);

            // TODO: do composition at random. # of spawn also depends on uiWaveCount
            // As of now, it is just one of each.
            index = urand(0, ENCOUNTER_WAVE_MERCENARY-1);
            pSummoner->SummonCreature(NPC_WAVE_MERCENARY, MercenarySpawnPos[index], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0);

            index = urand(0, ENCOUNTER_WAVE_FOOTMAN-1);
            pSummoner->SummonCreature(NPC_WAVE_FOOTMAN, FootmenSpawnPos[index], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0);

            index = urand(0, ENCOUNTER_WAVE_RIFLEMAN-1);
            pSummoner->SummonCreature(NPC_WAVE_RIFLEMAN, RiflemanSpawnPos[index], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0);

            index = urand(0, ENCOUNTER_WAVE_PRIEST-1);
            pSummoner->SummonCreature(NPC_WAVE_PRIEST, PriestSpawnPos[index], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0);

            index = urand(0, ENCOUNTER_WAVE_MAGE-1);
            pSummoner->SummonCreature(NPC_WAVE_MAGE, MageSpawnPos[index], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0);
        }

        void Update(uint32 diff)
        {
            if (!instance->HavePlayers())
                return;

            events.Update(diff);

            switch(events.ExecuteEvent())
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