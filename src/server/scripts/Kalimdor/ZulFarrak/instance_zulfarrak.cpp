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
#include "zulfarrak.h"

#define NPC_GAHZRILLA 7273
#define PATH_ADDS 81553

int const pyramidSpawnTotal = 54;
/* list of wave spawns: 0 = wave ID, 1 = creature id, 2 = x, 3 = y
no z coordinat b/c they're all the same */
float pyramidSpawns [pyramidSpawnTotal][4] = {
    {1,7789,1894.64,1206.29},
    {1,7787,1890.08,1218.68},
    {1,8876,1883.76,1222.3},
    {1,7789,1874.18,1221.24},
    {1,7787,1892.28,1225.49},
    {1,7788,1889.94,1212.21},
    {1,7787,1879.02,1223.06},
    {1,7789,1874.45,1204.44},
    {1,8876,1898.23,1217.97},
    {1,7787,1882.07,1225.7},
    {1,8877,1896.46,1205.62},
    {1,7787,1886.97,1225.86},
    {1,7787,1894.72,1221.91},
    {1,7787,1883.5,1218.25},
    {1,7787,1886.93,1221.4},
    {1,8876,1889.82,1222.51},
    {1,7788,1893.07,1215.26},
    {1,7788,1878.57,1214.16},
    {1,7788,1883.74,1212.35},
    {1,8877,1877,1207.27},
    {1,8877,1873.63,1204.65},
    {1,8876,1877.4,1216.41},
    {1,8877,1899.63,1202.52},
    {2,7789,1902.83,1223.41},
    {2,8876,1889.82,1222.51},
    {2,7787,1883.5,1218.25},
    {2,7788,1883.74,1212.35},
    {2,8877,1877,1207.27},
    {2,7787,1890.08,1218.68},
    {2,7789,1894.64,1206.29},
    {2,8876,1877.4,1216.41},
    {2,7787,1892.28,1225.49},
    {2,7788,1893.07,1215.26},
    {2,8877,1896.46,1205.62},
    {2,7789,1874.45,1204.44},
    {2,7789,1874.18,1221.24},
    {2,7787,1879.02,1223.06},
    {2,8876,1898.23,1217.97},
    {2,7787,1882.07,1225.7},
    {2,8877,1873.63,1204.65},
    {2,7787,1886.97,1225.86},
    {2,7788,1878.57,1214.16},
    {2,7787,1894.72,1221.91},
    {2,7787,1886.93,1221.4},
    {2,8876,1883.76,1222.3},
    {2,7788,1889.94,1212.21},
    {2,8877,1899.63,1202.52},
    {3,7788,1878.57,1214.16},
    {3,7787,1894.72,1221.91},
    {3,7787,1886.93,1221.4},
    {3,8876,1883.76,1222.3},
    {3,7788,1889.94,1212.21},
    {3,7275,1889.23,1207.72},
    {3,7796,1879.77,1207.96}
};    

float Spawnsway[2][3] =
{
    {1884.86,1228.62,9},
    {1887.53,1263,41}
};

struct instance_zulfarrak : public ScriptedInstance
{
    instance_zulfarrak(Map* pMap) : ScriptedInstance(pMap) {Initialize();}

    uint32 GahzRillaEncounter;
    uint64 ZumrahGUID;
    uint64 BlyGUID;
    uint64 WeegliGUID;
    uint64 OroGUID;
    uint64 RavenGUID;
    uint64 MurtaGUID;
    uint64 EndDoorGUID;
    uint32 PyramidPhase;    
    uint32 major_wave_Timer;
    uint32 minor_wave_Timer;
    uint32 addGroupSize;
    uint32 waypoint;

    void Initialize()
    {
        GahzRillaEncounter = NOT_STARTED;
    }

    void OnCreatureCreate(Creature* pCreature, bool /*add*/)
    {
        switch (pCreature->GetEntry())
        {
            case ENTRY_ZUMRAH:
                ZumrahGUID = pCreature->GetGUID();
                break;
            case ENTRY_BLY:
                BlyGUID = pCreature->GetGUID();
                pCreature->SetReactState(REACT_PASSIVE); // starts out passive (in a cage)
                break;
            case ENTRY_RAVEN:
                RavenGUID = pCreature->GetGUID();
                pCreature->SetReactState(REACT_PASSIVE);// starts out passive (in a cage)
                break;
            case ENTRY_ORO:
                OroGUID = pCreature->GetGUID();
                pCreature->SetReactState(REACT_PASSIVE);// starts out passive (in a cage)
                break;
            case ENTRY_WEEGLI:
                WeegliGUID = pCreature->GetGUID();
                pCreature->SetReactState(REACT_PASSIVE);// starts out passive (in a cage)
                break;
            case ENTRY_MURTA:
                MurtaGUID = pCreature->GetGUID();
                pCreature->SetReactState(REACT_PASSIVE);// starts out passive (in a cage)
                break;
            case NPC_GAHZRILLA:
                if (GahzRillaEncounter >= IN_PROGRESS)
                    pCreature->DisappearAndDie();
                else
                    GahzRillaEncounter = IN_PROGRESS;
                break;
        }
    }

    void OnGameObjectCreate(GameObject* pGo, bool /*apply*/)
    {
        switch(pGo->GetEntry())
        {
            case GO_END_DOOR:
                EndDoorGUID = pGo->GetGUID();
                break;
        }
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case EVENT_PYRAMID:
                return PyramidPhase;
        }
        return 0;
    }

    uint64 GetData64(uint32 data)
    {
        switch(data)
        {
            case ENTRY_ZUMRAH:
                return ZumrahGUID;
            case ENTRY_BLY:
                return BlyGUID;
            case ENTRY_RAVEN:
                return RavenGUID;
            case ENTRY_ORO:
                return OroGUID;
            case ENTRY_WEEGLI:
                return WeegliGUID;
            case ENTRY_MURTA:
                return MurtaGUID;
            case GO_END_DOOR:
                return EndDoorGUID;
        }
        return 0;
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case EVENT_PYRAMID:
                PyramidPhase=data;
                break;
        };
    }   

    virtual void Update(uint32 diff)
    {
        switch (PyramidPhase)
        {
            case PYRAMID_NOT_STARTED:
            case PYRAMID_KILLED_ALL_TROLLS:
                break;
            case PYRAMID_ARRIVED_AT_STAIR:
                SpawnPyramidWave(1);
                SetData(EVENT_PYRAMID,PYRAMID_WAVE_1);
                major_wave_Timer=120000;
                minor_wave_Timer=0;
                addGroupSize=2;
                break;
            case PYRAMID_WAVE_1:
                if (IsWaveAllDead())
                {
                    SetData(EVENT_PYRAMID,PYRAMID_PRE_WAVE_2);
                    major_wave_Timer = 10000; //give players a few seconds before wave 2 starts to rebuff
                }
                else
                    if (minor_wave_Timer<diff)
                    {
                        SendAddsUpStairs(addGroupSize++);
                        minor_wave_Timer=10000;
                    }
                    else
                        minor_wave_Timer -= diff;
                break;
            case PYRAMID_PRE_WAVE_2:
                if (major_wave_Timer<diff)
                {
                    // beginning 2nd wave!
                    SpawnPyramidWave(2);
                    SetData(EVENT_PYRAMID,PYRAMID_WAVE_2);
                    minor_wave_Timer = 0;
                    addGroupSize=2;
                }
                else
                    major_wave_Timer -= diff;
                break;
            case PYRAMID_WAVE_2:
                if (IsWaveAllDead())
                {
                    SpawnPyramidWave(3);
                    SetData(EVENT_PYRAMID,PYRAMID_PRE_WAVE_3);
                    major_wave_Timer = 5000; //give NPCs time to return to their home spots
                } 
                else 
                    if (minor_wave_Timer<diff)
                    {
                        SendAddsUpStairs(addGroupSize++);
                        minor_wave_Timer=10000;
                    } 
                    else 
                        minor_wave_Timer -= diff;
                break;
            case PYRAMID_PRE_WAVE_3:
                if (major_wave_Timer<diff)
                {
                    // move NPCs to bottom of stair
                    MoveNPCIfAlive(ENTRY_BLY,1887.92,1228.179,9.98,4.78);
                    MoveNPCIfAlive(ENTRY_MURTA,1891.57,1228.68,9.69,4.78);
                    MoveNPCIfAlive(ENTRY_ORO,1897.23,1228.34,9.43,4.78);
                    MoveNPCIfAlive(ENTRY_RAVEN,1883.68,1227.95,9.543,4.78);
                    MoveNPCIfAlive(ENTRY_WEEGLI,1878.02,1227.65,9.485,4.78);
                    SetData(EVENT_PYRAMID,PYRAMID_WAVE_3);
                } 
                else 
                    major_wave_Timer -= diff;
                break;
            case PYRAMID_WAVE_3:
                if (IsWaveAllDead()) // move NPCS to their final positions
                {
                    SetData(EVENT_PYRAMID,PYRAMID_KILLED_ALL_TROLLS);
                    MoveNPCIfAlive(ENTRY_BLY,1883.82,1200.83,8.87,1.32);
                    MoveNPCIfAlive(ENTRY_MURTA,1891.83,1201.45,8.87,1.32);
                    MoveNPCIfAlive(ENTRY_ORO,1894.50,1204.40,8.87,1.32);
                    MoveNPCIfAlive(ENTRY_RAVEN,1874.11,1206.17,8.87,1.32);
                    MoveNPCIfAlive(ENTRY_WEEGLI,1877.52,1199.63,8.87,1.32);
                }
                break;
        };
    }

    std::list<uint64> addsAtBase,movedadds;

    void MoveNPCIfAlive(uint32 entry,float x,float y,float z,float o)
    {
       if (Creature* npc = instance->GetCreature(GetData64(entry)))
       {
           if (npc->isAlive())
           {
                npc->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                npc->GetMotionMaster()->MovePoint(1,x,y,z);
                npc->SetHomePosition(x,y,z,o);
           }
        }
    }

    void SpawnPyramidWave(uint32 wave){
        for (int i = 0; i < pyramidSpawnTotal; i++)
        {
            if (pyramidSpawns[i][0] == (float)wave)
            {
                Position pos = {pyramidSpawns[i][2], pyramidSpawns[i][3], 8.87, 0};
                TempSummon* ts = instance->SummonCreature(pyramidSpawns[i][1],pos);
                ts->GetMotionMaster()->MoveRandom(10);
                addsAtBase.push_back(ts->GetGUID());
            }
        }
    }

    bool IsWaveAllDead(){
        for(std::list<uint64>::iterator itr = addsAtBase.begin(); itr != addsAtBase.end(); ++itr)
        {
            if (Creature* add = instance->GetCreature((*itr)))
            {
                if (add->isAlive())
                    return false;
            }
        }
        for(std::list<uint64>::iterator itr = movedadds.begin(); itr != movedadds.end(); ++itr)
        {
            if (Creature* add = instance->GetCreature(((*itr))))
            {
                if (add->isAlive())
                    return false;
            }
        }
        return true;
    }

    void SendAddsUpStairs(uint32 count)
    {
        //pop a add from list, send him up the stairs...
        for (uint32 addCount = 0; addCount<count && !addsAtBase.empty(); addCount++)
        {
            if (Creature* add = instance->GetCreature(*addsAtBase.begin()))
            {
                add->GetMotionMaster()->MovePath(PATH_ADDS,false);
                movedadds.push_back(add->GetGUID());
            }
            addsAtBase.erase(addsAtBase.begin());
        }
    }
};

InstanceData* GetInstanceData_instance_zulfarrak(Map* pMap)
{
    return new instance_zulfarrak(pMap);
}

void AddSC_instance_zulfarrak()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_zulfarrak";
    newscript->GetInstanceData = &GetInstanceData_instance_zulfarrak;
    newscript->RegisterSelf();
}
