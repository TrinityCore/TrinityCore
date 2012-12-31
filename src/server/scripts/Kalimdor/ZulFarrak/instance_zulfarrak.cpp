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
#include "InstanceScript.h"
#include "zulfarrak.h"
#include "Player.h"
#include "TemporarySummon.h"

#define NPC_GAHZRILLA 7273
#define PATH_ADDS 81553

int const pyramidSpawnTotal = 54;
/* list of wave spawns: 0 = wave ID, 1 = creature id, 2 = x, 3 = y
no z coordinat b/c they're all the same */
float pyramidSpawns [pyramidSpawnTotal][4] = {
    {1, 7789, 1894.64f, 1206.29f},
    {1, 7787, 1890.08f, 1218.68f},
    {1, 8876, 1883.76f, 1222.3f},
    {1, 7789, 1874.18f, 1221.24f},
    {1, 7787, 1892.28f, 1225.49f},
    {1, 7788, 1889.94f, 1212.21f},
    {1, 7787, 1879.02f, 1223.06f},
    {1, 7789, 1874.45f, 1204.44f},
    {1, 8876, 1898.23f, 1217.97f},
    {1, 7787, 1882.07f, 1225.7f},
    {1, 8877, 1896.46f, 1205.62f},
    {1, 7787, 1886.97f, 1225.86f},
    {1, 7787, 1894.72f, 1221.91f},
    {1, 7787, 1883.5f, 1218.25f},
    {1, 7787, 1886.93f, 1221.4f},
    {1, 8876, 1889.82f, 1222.51f},
    {1, 7788, 1893.07f, 1215.26f},
    {1, 7788, 1878.57f, 1214.16f},
    {1, 7788, 1883.74f, 1212.35f},
    {1, 8877, 1877, 1207.27f},
    {1, 8877, 1873.63f, 1204.65f},
    {1, 8876, 1877.4f, 1216.41f},
    {1, 8877, 1899.63f, 1202.52f},
    {2, 7789, 1902.83f, 1223.41f},
    {2, 8876, 1889.82f, 1222.51f},
    {2, 7787, 1883.5f, 1218.25f},
    {2, 7788, 1883.74f, 1212.35f},
    {2, 8877, 1877, 1207.27f},
    {2, 7787, 1890.08f, 1218.68f},
    {2, 7789, 1894.64f, 1206.29f},
    {2, 8876, 1877.4f, 1216.41f},
    {2, 7787, 1892.28f, 1225.49f},
    {2, 7788, 1893.07f, 1215.26f},
    {2, 8877, 1896.46f, 1205.62f},
    {2, 7789, 1874.45f, 1204.44f},
    {2, 7789, 1874.18f, 1221.24f},
    {2, 7787, 1879.02f, 1223.06f},
    {2, 8876, 1898.23f, 1217.97f},
    {2, 7787, 1882.07f, 1225.7f},
    {2, 8877, 1873.63f, 1204.65f},
    {2, 7787, 1886.97f, 1225.86f},
    {2, 7788, 1878.57f, 1214.16f},
    {2, 7787, 1894.72f, 1221.91f},
    {2, 7787, 1886.93f, 1221.4f},
    {2, 8876, 1883.76f, 1222.3f},
    {2, 7788, 1889.94f, 1212.21f},
    {2, 8877, 1899.63f, 1202.52f},
    {3, 7788, 1878.57f, 1214.16f},
    {3, 7787, 1894.72f, 1221.91f},
    {3, 7787, 1886.93f, 1221.4f},
    {3, 8876, 1883.76f, 1222.3f},
    {3, 7788, 1889.94f, 1212.21f},
    {3, 7275, 1889.23f, 1207.72f},
    {3, 7796, 1879.77f, 1207.96f}
};

float Spawnsway[2][3] =
{
    {1884.86f, 1228.62f, 9},
    {1887.53f, 1263, 41}
};

class instance_zulfarrak : public InstanceMapScript
{
public:
    instance_zulfarrak() : InstanceMapScript("instance_zulfarrak", 209) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_zulfarrak_InstanceMapScript(map);
    }

    struct instance_zulfarrak_InstanceMapScript : public InstanceScript
    {
        instance_zulfarrak_InstanceMapScript(Map* map) : InstanceScript(map) {}

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
            ZumrahGUID = 0;
            BlyGUID = 0;
            WeegliGUID = 0;
            OroGUID = 0;
            RavenGUID = 0;
            MurtaGUID = 0;
            EndDoorGUID = 0;
            PyramidPhase = 0;
            major_wave_Timer = 0;
            minor_wave_Timer = 0;
            addGroupSize = 0;
            waypoint = 0;
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case ENTRY_ZUMRAH:
                    ZumrahGUID = creature->GetGUID();
                    break;
                case ENTRY_BLY:
                    BlyGUID = creature->GetGUID();
                    creature->SetReactState(REACT_PASSIVE); // starts out passive (in a cage)
                    break;
                case ENTRY_RAVEN:
                    RavenGUID = creature->GetGUID();
                    creature->SetReactState(REACT_PASSIVE);// starts out passive (in a cage)
                    break;
                case ENTRY_ORO:
                    OroGUID = creature->GetGUID();
                    creature->SetReactState(REACT_PASSIVE);// starts out passive (in a cage)
                    break;
                case ENTRY_WEEGLI:
                    WeegliGUID = creature->GetGUID();
                    creature->SetReactState(REACT_PASSIVE);// starts out passive (in a cage)
                    break;
                case ENTRY_MURTA:
                    MurtaGUID = creature->GetGUID();
                    creature->SetReactState(REACT_PASSIVE);// starts out passive (in a cage)
                    break;
                case NPC_GAHZRILLA:
                    if (GahzRillaEncounter >= IN_PROGRESS)
                        creature->DisappearAndDie();
                    else
                        GahzRillaEncounter = IN_PROGRESS;
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_END_DOOR:
                    EndDoorGUID = go->GetGUID();
                    break;
            }
        }

        uint32 GetData(uint32 type) const
        {
            switch (type)
            {
                case EVENT_PYRAMID:
                    return PyramidPhase;
            }
            return 0;
        }

        uint64 GetData64(uint32 data) const
        {
            switch (data)
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
            switch (type)
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
                    SetData(EVENT_PYRAMID, PYRAMID_WAVE_1);
                    major_wave_Timer=120000;
                    minor_wave_Timer=0;
                    addGroupSize=2;
                    break;
                case PYRAMID_WAVE_1:
                    if (IsWaveAllDead())
                    {
                        SetData(EVENT_PYRAMID, PYRAMID_PRE_WAVE_2);
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
                        SetData(EVENT_PYRAMID, PYRAMID_WAVE_2);
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
                        SetData(EVENT_PYRAMID, PYRAMID_PRE_WAVE_3);
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
                        MoveNPCIfAlive(ENTRY_BLY, 1887.92f, 1228.179f, 9.98f, 4.78f);
                        MoveNPCIfAlive(ENTRY_MURTA, 1891.57f, 1228.68f, 9.69f, 4.78f);
                        MoveNPCIfAlive(ENTRY_ORO, 1897.23f, 1228.34f, 9.43f, 4.78f);
                        MoveNPCIfAlive(ENTRY_RAVEN, 1883.68f, 1227.95f, 9.543f, 4.78f);
                        MoveNPCIfAlive(ENTRY_WEEGLI, 1878.02f, 1227.65f, 9.485f, 4.78f);
                        SetData(EVENT_PYRAMID, PYRAMID_WAVE_3);
                    }
                    else
                        major_wave_Timer -= diff;
                    break;
                case PYRAMID_WAVE_3:
                    if (IsWaveAllDead()) // move NPCS to their final positions
                    {
                        SetData(EVENT_PYRAMID, PYRAMID_KILLED_ALL_TROLLS);
                        MoveNPCIfAlive(ENTRY_BLY, 1883.82f, 1200.83f, 8.87f, 1.32f);
                        MoveNPCIfAlive(ENTRY_MURTA, 1891.83f, 1201.45f, 8.87f, 1.32f);
                        MoveNPCIfAlive(ENTRY_ORO, 1894.50f, 1204.40f, 8.87f, 1.32f);
                        MoveNPCIfAlive(ENTRY_RAVEN, 1874.11f, 1206.17f, 8.87f, 1.32f);
                        MoveNPCIfAlive(ENTRY_WEEGLI, 1877.52f, 1199.63f, 8.87f, 1.32f);
                    }
                    break;
            };
        }

        std::list<uint64> addsAtBase, movedadds;

        void MoveNPCIfAlive(uint32 entry, float x, float y, float z, float o)
        {
           if (Creature* npc = instance->GetCreature(GetData64(entry)))
           {
               if (npc->isAlive())
               {
                    npc->SetWalk(true);
                    npc->GetMotionMaster()->MovePoint(1, x, y, z);
                    npc->SetHomePosition(x, y, z, o);
               }
            }
        }

        void SpawnPyramidWave(uint32 wave)
        {
            for (int i = 0; i < pyramidSpawnTotal; i++)
            {
                if (pyramidSpawns[i][0] == (float)wave)
                {
                    Position pos = {pyramidSpawns[i][2], pyramidSpawns[i][3], 8.87f, 0};
                    TempSummon* ts = instance->SummonCreature(uint32(pyramidSpawns[i][1]), pos);
                    ts->GetMotionMaster()->MoveRandom(10);
                    addsAtBase.push_back(ts->GetGUID());
                }
            }
        }

        bool IsWaveAllDead()
        {
            for (std::list<uint64>::iterator itr = addsAtBase.begin(); itr != addsAtBase.end(); ++itr)
            {
                if (Creature* add = instance->GetCreature((*itr)))
                {
                    if (add->isAlive())
                        return false;
                }
            }
            for (std::list<uint64>::iterator itr = movedadds.begin(); itr != movedadds.end(); ++itr)
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
                    add->GetMotionMaster()->MovePath(PATH_ADDS, false);
                    movedadds.push_back(add->GetGUID());
                }
                addsAtBase.erase(addsAtBase.begin());
            }
        }
    };

};

void AddSC_instance_zulfarrak()
{
    new instance_zulfarrak();
}
