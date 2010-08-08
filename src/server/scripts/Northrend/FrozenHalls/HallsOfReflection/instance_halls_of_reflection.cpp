/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#define MAX_ENCOUNTER 3

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
};

enum Events
{
    EVENT_NONE,
    EVENT_NEXT_WAVE,
    EVENT_START_LICH_KING,
};

static Position PriestSpawnPos[ENCOUNTER_WAVE_PRIEST] =
{
    {5277.74,2016.88,707.778,5.96903},
    {5295.88,2040.34,707.778,5.07891},
    {5320.37,1980.13,707.778,2.00713},
    {5280.51,1997.84,707.778,0.296706},
    {5302.45,2042.22,707.778,4.90438},
    {5306.57,1977.47,707.778,1.50098},
};

static Position MageSpawnPos[ENCOUNTER_WAVE_MAGE] =
{
    {5312.75,2037.12,707.778,4.59022},
    {5309.58,2042.67,707.778,4.69494},
    {5275.08,2008.72,707.778,6.21337},
    {5279.65,2004.66,707.778,0.069813},
    {5275.48,2001.14,707.778,0.174533},
    {5316.7,2041.55,707.778,4.50295},
};

static Position MercenarySpawnPos[ENCOUNTER_WAVE_MERCENARY] =
{
    {5302.25,1972.41,707.778,1.37881},
    {5311.03,1972.23,707.778,1.64061},
    {5277.36,1993.23,707.778,0.401426},
    {5318.7,2036.11,707.778,4.2237},
    {5335.72,1996.86,707.778,2.74017},
    {5299.43,1979.01,707.778,1.23918},
};

static Position FootmenSpawnPos[ENCOUNTER_WAVE_FOOTMAN] =
{
    {5306.06,2037,707.778,4.81711},
    {5344.15,2007.17,707.778,3.15905},
    {5337.83,2010.06,707.778,3.22886},
    {5343.29,1999.38,707.778,2.9147},
    {5340.84,1992.46,707.778,2.75762},
    {5325.07,1977.6,707.778,2.07694},
    {5336.6,2017.28,707.778,3.47321},
    {5313.82,1978.15,707.778,1.74533},
    {5280.63,2012.16,707.778,6.05629},
    {5322.96,2040.29,707.778,4.34587},
};

static Position RiflemanSpawnPos[ENCOUNTER_WAVE_RIFLEMAN] =
{
    {5343.47,2015.95,707.778,3.49066},
    {5337.86,2003.4,707.778,2.98451},
    {5319.16,1974,707.778,1.91986},
    {5299.25,2036,707.778,5.02655},
    {5295.64,1973.76,707.778,1.18682},
    {5282.9,2019.6,707.778,5.88176},
};
class instance_halls_of_reflection : public InstanceMapScript
{
public:
    instance_halls_of_reflection() : InstanceMapScript("instance_halls_of_reflection") { }

    InstanceScript* GetInstanceData_InstanceMapScript(Map* pMap)
    {
        return new instance_halls_of_reflection_InstanceMapScript(pMap);
    }

    struct instance_halls_of_reflection_InstanceMapScript : public InstanceScript
    {
        instance_halls_of_reflection_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {};

        uint64 uiFalric;
        uint64 uiMarwyn;
        uint64 uiLichKingEvent;
        uint64 uiJainaPart1;
        uint64 uiSylvanasPart1;

        uint64 uiFrostmourne;
        uint64 uiFrostmourneAltar;
        uint64 uiArthasDoor;
        uint64 uiFrontDoor;

        uint32 uiEncounter[MAX_ENCOUNTER];
        uint32 uiTeamInInstance;
        uint32 uiWaveCount;
        bool bIntroDone;

        EventMap events;

        void Initialize()
        {
            events.Reset();

            uiFalric = 0;
            uiMarwyn = 0;
            uiLichKingEvent = 0;
            uiJainaPart1 = 0;
            uiSylvanasPart1 = 0;

            uiFrostmourne = 0;
            uiFrostmourneAltar = 0;
            uiArthasDoor = 0;
            uiFrontDoor = 0;
            uiTeamInInstance = 0;
            uiWaveCount = 0;
            bIntroDone = false;

            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                uiEncounter[i] = NOT_STARTED;
        }

        void OnCreatureCreate(Creature* pCreature, bool add)
        {
            if (!add)
                return;

            Map::PlayerList const &players = instance->GetPlayers();
            if (!players.isEmpty())
                if (Player* pPlayer = players.begin()->getSource())
                    uiTeamInInstance = pPlayer->GetTeam();

            switch(pCreature->GetEntry())
            {
                case NPC_FALRIC:
                    uiFalric = pCreature->GetGUID();
                    break;
                case NPC_MARWYN:
                    uiMarwyn = pCreature->GetGUID();
                    break;
                case NPC_LICH_KING_EVENT:
                    uiLichKingEvent = pCreature->GetGUID();
                    break;
                case NPC_JAINA_PART1:
                    uiJainaPart1 = pCreature->GetGUID();
                    break;
                case NPC_SYLVANAS_PART1:
                    uiSylvanasPart1 = pCreature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* pGo, bool add)
        {
            if (!add)
                return;

            // TODO: init state depending on encounters
            switch(pGo->GetEntry())
            {
                case GO_FROSTMOURNE:
                    uiFrostmourne = pGo->GetGUID();
                    pGo->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_INTERACT_COND);
                    HandleGameObject(0, false, pGo);
                    break;
                case GO_FROSTMOURNE_ALTAR:
                    uiFrostmourneAltar = pGo->GetGUID();
                    pGo->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_INTERACT_COND);
                    HandleGameObject(0, true, pGo);
                    break;
                case GO_FRONT_DOOR:
                    uiFrontDoor = pGo->GetGUID();
                    pGo->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_INTERACT_COND);
                    HandleGameObject(0, true, pGo);
                    break;
                case GO_ARTHAS_DOOR:
                    uiArthasDoor = pGo->GetGUID();
                    pGo->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_INTERACT_COND);

                    if (uiEncounter[1] == DONE)
                        HandleGameObject(0, true, pGo);
                    else
                        HandleGameObject(0, false, pGo);
                    break;
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            if (type == DATA_WAVE_COUNT && data == SPECIAL)
            {
                bIntroDone = true;
                events.ScheduleEvent(EVENT_NEXT_WAVE, 10000);
                return;
            }


            if (uiWaveCount && data == NOT_STARTED)
                DoWipe();

            switch(type)
            {
                case DATA_FALRIC_EVENT:
                    uiEncounter[0] = data;
                    if (data == DONE)
                        events.ScheduleEvent(EVENT_NEXT_WAVE, 60000);
                    break;
                case DATA_MARWYN_EVENT:
                    uiEncounter[1] = data;
                    if (data == DONE)
                        HandleGameObject(uiArthasDoor, true);
                    break;
                case DATA_LICHKING_EVENT:
                    uiEncounter[2] = data;
                    break;
            }

            if (data == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 type)
        {
            switch(type)
            {
                case DATA_FALRIC_EVENT:         return uiEncounter[0];
                case DATA_MARWYN_EVENT:         return uiEncounter[1];
                case DATA_LICHKING_EVENT:       return uiEncounter[2];
                case DATA_WAVE_COUNT:           return uiWaveCount;
                case DATA_TEAM_IN_INSTANCE:     return uiTeamInInstance;
            }

            return 0;
        }

        uint64 GetData64(uint32 identifier)
        {
            switch(identifier)
            {
                case DATA_FALRIC:               return uiFalric;
                case DATA_MARWYN:               return uiMarwyn;
                case DATA_LICHKING:             return uiLichKingEvent;
                case DATA_FROSTMOURNE:          return uiFrostmourne;
            }

            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "H R 1 " << uiEncounter[0] << " " << uiEncounter[1] << " " << uiEncounter[2];

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
            uint16 data0, data1, data2;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> version >> data0 >> data1 >> data2;

            if (dataHead1 == 'H' && dataHead2 == 'R')
            {
                uiEncounter[0] = data0;
                uiEncounter[1] = data1;
                uiEncounter[2] = data2;

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (uiEncounter[i] == IN_PROGRESS)
                        uiEncounter[i] = NOT_STARTED;

            } else OUT_LOAD_INST_DATA_FAIL;

            if (uiEncounter[0] == DONE || uiEncounter[1] == DONE)
                bIntroDone = true;

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
                    if (Creature *pFalric = instance->GetCreature(uiFalric))
                        SpawnWave(pFalric);
                    break;
                case 5:
                    if (GetData(DATA_FALRIC_EVENT) == DONE)
                        events.ScheduleEvent(EVENT_NEXT_WAVE, 10000);
                    else if (Creature *pFalric = instance->GetCreature(uiFalric))
                        if (pFalric->AI())
                            pFalric->AI()->DoAction(ACTION_ENTER_COMBAT);
                    break;
                case 6:
                case 7:
                case 8:
                case 9:
                    if (Creature *pMarwyn  = instance->GetCreature(uiMarwyn))
                        SpawnWave(pMarwyn);
                    break;
                case 10:
                    if (GetData(DATA_MARWYN_EVENT) != DONE) // wave should not have been started if DONE. Check anyway to avoid bug exploit!
                        if (Creature *pMarwyn = instance->GetCreature(uiMarwyn))
                            if (pMarwyn->AI())
                                pMarwyn->AI()->DoAction(ACTION_ENTER_COMBAT);
                    break;
            }
        }

        // Wipe has been detected. Perform cleanup and reset.
        void DoWipe()
        {
            uiWaveCount = 0;
            events.Reset();
            DoUpdateWorldState(WORLD_STATE_HOR, 1);
            DoUpdateWorldState(WORLD_STATE_HOR_WAVE_COUNT, uiWaveCount);
            HandleGameObject(uiFrontDoor, true);

            // TODO
            // in case of wipe, the event is normally restarted by jumping into the center of the room.
            // As I can't find a trigger area there, just respawn Jaina/Sylvanas so the event may be restarted.
            if (Creature* pJaina = instance->GetCreature(uiJainaPart1))
                pJaina->Respawn();
            if (Creature* pSylvanas = instance->GetCreature(uiSylvanasPart1))
                pSylvanas->Respawn();

            if (Creature* pFalric = instance->GetCreature(uiFalric))
                pFalric->SetVisibility(VISIBILITY_OFF);
            if (Creature* pMarwyn = instance->GetCreature(uiMarwyn))
                pMarwyn->SetVisibility(VISIBILITY_OFF);
        }

        // spawn a wave on behalf of the summoner.
        void SpawnWave(Creature *pSummoner)
        {
            uint32 index;

            pSummoner->SetVisibility(VISIBILITY_ON);

            // TODO: do composition at random. # of spawn also depends on uiWaveCount
            // As of now, it is just one of each.
            index = urand(0,ENCOUNTER_WAVE_MERCENARY-1);
            pSummoner->SummonCreature(NPC_WAVE_MERCENARY, MercenarySpawnPos[index], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0);

            index = urand(0,ENCOUNTER_WAVE_FOOTMAN-1);
            pSummoner->SummonCreature(NPC_WAVE_FOOTMAN, FootmenSpawnPos[index], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0);

            index = urand(0,ENCOUNTER_WAVE_RIFLEMAN-1);
            pSummoner->SummonCreature(NPC_WAVE_RIFLEMAN, RiflemanSpawnPos[index], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0);

            index = urand(0,ENCOUNTER_WAVE_PRIEST-1);
            pSummoner->SummonCreature(NPC_WAVE_PRIEST, PriestSpawnPos[index], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0);

            index = urand(0,ENCOUNTER_WAVE_MAGE-1);
            pSummoner->SummonCreature(NPC_WAVE_MAGE, MageSpawnPos[index], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0);
        }

        void Update(uint32 diff)
        {
            if (!instance->HavePlayers())
                return;

            events.Update(diff);

            switch(uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_NEXT_WAVE:
                    uiWaveCount++;
                    AddWave();
                    break;
                case EVENT_START_LICH_KING:
                    // TODO
                    break;
            }
        }
    };

};


void AddSC_instance_halls_of_reflection()
{
    new instance_halls_of_reflection();
}
