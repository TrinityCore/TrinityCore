/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "hyjal.h"
#include "hyjal_trash.h"
#include "hyjalAI.h"

enum Spells
{
    SPELL_METEOR            = 33814, //infernal visual
    SPELL_IMMOLATION        = 37059,
    SPELL_FLAME_BUFFET      = 31724,
    NPC_TRIGGER             = 21987, //World Trigger (Tiny)
    MODEL_INVIS             = 11686, //invisible model
    SPELL_DISEASE_CLOUD     = 31607,
    SPELL_KNOCKDOWN         = 31610,
    SPELL_FRENZY            = 31540,
    SPELL_RAISE_DEAD_1      = 31617,
    SPELL_RAISE_DEAD_2      = 31624,
    SPELL_RAISE_DEAD_3      = 31625,
    SPELL_SHADOW_BOLT       = 31627,
    SPELL_BANSHEE_CURSE     = 31651,
    SPELL_BANSHEE_WAIL      = 38183,
    SPELL_ANTI_MAGIC_SHELL  = 31662,
    SPELL_WEB               = 28991,
    SPELL_MANA_BURN         = 31729,
    SPELL_FROST_BREATH      = 31688,
    SPELL_GARGOYLE_STRIKE   = 31664,
    SPELL_EXPLODING_SHOT    = 7896,
};

float HordeWPs[8][3]=//basic waypoints from spawn to leader
{
    {5492.91f,    -2404.61f,    1462.63f},
    {5531.76f,    -2460.87f,    1469.55f},
    {5554.58f,    -2514.66f,    1476.12f},
    {5554.16f,    -2567.23f,    1479.90f},
    {5540.67f,    -2625.99f,    1480.89f},
    {5508.16f,    -2659.20f,    1480.15f}, //random rush starts from here
    {5489.62f,    -2704.05f,    1482.18f},
    {5457.04f,    -2726.26f,    1485.10f}
};
float AllianceWPs[8][3]=//basic waypoints from spawn to leader
{
    {4896.08f,    -1576.35f,    1333.65f},
    {4898.68f,    -1615.02f,    1329.48f},
    {4907.12f,    -1667.08f,    1321.00f},
    {4963.18f,    -1699.35f,    1340.51f},
    {4989.16f,    -1716.67f,    1335.74f}, //first WP in the base, after the gate
    {5026.27f,    -1736.89f,    1323.02f},
    {5037.77f,    -1770.56f,    1324.36f},
    {5067.23f,    -1789.95f,    1321.17f}
};

float FrostWyrmWPs[3][3]=//waypoints for the frost wyrms in horde base
{
    {5580.82f,    -2628.83f,    1528.28f},
    {5550.90f,    -2667.16f,    1505.45f},
    {5459.64f,    -2725.91f,    1484.83f}
};

float GargoyleWPs[3][3]=//waypoints for the gargoyles in horde base
{
    {5533.66f,    -2634.32f,    1495.33f},
    {5517.88f,    -2712.05f,    1490.54f},
    {5459.64f,    -2725.91f,    1484.83f}
};

float FlyPathWPs[3][3]=//waypoints for the gargoyls and frost wyrms in horde base in wave 1/3
{
    {5531.96f, -2772.83f, 1516.68f},
    {5498.32f, -2734.84f, 1497.01f},
    {5456.67f, -2725.48f, 1493.08f}
};

float AllianceOverrunWP[55][3]=//waypoints in the alliance base used in the end in the cleaning wave
{
    {4976.37f, -1708.02f, 1339.43f}, //0spawn
    {4994.83f, -1725.52f, 1333.25f}, //1 start
    {4982.92f, -1753.7f, 1330.69f}, //2 end
    {4996.75f, -1721.47f, 1332.95f}, //3 start
    {5015.74f, -1755.05f, 1322.49f}, //4
    {4998.68f, -1773.44f, 1329.59f}, //5
    {4994.83f, -1725.52f, 1333.25f}, //6 start
    {5022.8f, -1735.46f, 1323.53f}, //7
    {5052.15f, -1729.02f, 1320.88f}, //8
    {5082.43f, -1726.29f, 1327.87f}, //9
    {4994.83f, -1725.52f, 1333.25f}, //10 start
    {5018.92f, -1751.14f, 1322.19f}, //11
    {5040.09f, -1792.09f, 1322.1f}, //12
    {4994.83f, -1725.52f, 1333.25f}, //13 start
    {5023.47f, -1748.1f, 1322.51f}, //14
    {5013.43f, -1842.39f, 1322.07f}, //15
    {4994.83f, -1725.52f, 1333.25f}, //16 start
    {5020.8f, -1756.86f, 1322.2f}, //17
    {5019.53f, -1824.6f, 1321.96f}, //18
    {5043.42f, -1853.75f, 1324.52f}, //19
    {5053.02f, -1864.13f, 1330.36f}, //20
    {5062.49f, -1852.47f, 1330.49f}, //21
    {5015.27f, -1738.77f, 1324.83f}, //35//start 22
    {5027.97f, -1775.25f, 1321.87f}, //34 23
    {5015.94f, -1821.24f, 1321.86f}, //33 24
    {4983.25f, -1857.4f, 1320.48f}, //32 25
    {4981.51f, -1883.7f, 1322.34f}, //31 26
    {5002.33f, -1893.98f, 1325.88f}, //30 27
    {5049.32f, -1886.54f, 1331.69f}, //29 28
    {5089.68f, -1846.88f, 1328.99f}, //28 29
    {5127.90f, -1825.14f, 1335.58f}, //27 30
    {5163.27f, -1789.08f, 1337.04f}, //26 31
    {5138.97f, -1755.88f, 1334.57f}, //25 32
    {5096.63f, -1742.22f, 1329.61f}, //24 33
    {5065.81f, -1729.43f, 1325.66f}, //23 34
    {5049.32f, -1726.31f, 1320.64f}, //22 start
    {5081.07f, -1902.10f, 1346.36f}, //36 abo start
    {5107.65f, -1912.03f, 1356.49f}, //37
    {5132.83f, -1927.07f, 1362.42f}, //38
    {5147.78f, -1954.41f, 1365.98f}, //39
    {5164.96f, -1966.48f, 1367.04f}, //40
    {5189.04f, -1961.06f, 1367.90f}, //41
    {5212.27f, -1975.30f, 1365.58f}, //42
    {5221.82f, -1994.18f, 1364.97f}, //43 end1
    {5202.23f, -1994.94f, 1367.59f}, //44 end2
    {5279.94f, -2049.68f, 1311.38f}, //45 garg1
    {5289.15f, -2219.06f, 1291.12f}, //46 garg2
    {5202.07f, -2136.10f, 1305.07f}, //47 garg3
    {5071.52f, -2425.63f, 1454.48f}, //48 garg4
    {5120.65f, -2467.92f, 1463.93f}, //49 garg5
    {5283.04f, -2043.26f, 1300.11f}, //50 garg target1
    {5313.22f, -2207.60f, 1290.06f}, //51 garg target2
    {5180.41f, -2121.87f, 1292.62f}, //52 garg target3
    {5088.68f, -2432.04f, 1441.73f}, //53 garg target4
    {5111.26f, -2454.73f, 1449.63f}//54 garg target5

};

float HordeOverrunWP[21][3]=//waypoints in the horde base used in the end in the cleaning wave
{
    {5490.72f, -2702.94f, 1482.14f}, //0 start
    {5469.77f, -2741.34f, 1486.95f},
    {5439.47f, -2771.02f, 1494.59f},
    {5408.85f, -2811.92f, 1505.68f},
    {5423.87f, -2857.80f, 1515.55f},
    {5428.19f, -2898.15f, 1524.61f},
    {5394.59f, -2930.05f, 1528.23f},
    {5351.11f, -2935.80f, 1532.24f},
    {5312.37f, -2959.06f, 1536.21f},
    {5264.93f, -2989.80f, 1545.70f},
    {5256.63f, -3056.16f, 1559.24f},
    {5267.32f, -3119.55f, 1575.36f},
    {5305.61f, -3139.88f, 1586.38f},
    {5330.56f, -3135.37f, 1588.58f},
    {5365.87f, -3139.78f, 1583.96f},
    {5389.39f, -3163.57f, 1582.57f}, //15 end
    {5500.86f, -2669.89f, 1481.04f}, //16 start
    {5472.08f, -2715.14f, 1483.55f},
    {5450.11f, -2721.47f, 1485.61f},
    {5433.25f, -2712.93f, 1493.02f}, //19 end 1
    {5429.91f, -2718.44f, 1493.42f}//20 end 2
};

hyjal_trashAI::hyjal_trashAI(Creature* creature) : npc_escortAI(creature)
{
    instance = creature->GetInstanceScript();
    IsEvent = false;
    Delay = 0;
    LastOverronPos = 0;
    IsOverrun = false;
    OverrunType = 0;
    SetupOverrun = false;
    faction = 0;
    useFlyPath = false;
    damageTaken = 0;
    memset(DummyTarget, 0, sizeof(DummyTarget));
    Reset();
}

void hyjal_trashAI::DamageTaken(Unit* done_by, uint32 &damage)
{
    if (done_by->GetTypeId() == TYPEID_PLAYER || done_by->IsPet())
    {
        damageTaken += damage;
        instance->SetData(DATA_RAIDDAMAGE, damage);//store raid's damage
    }
}

void hyjal_trashAI::UpdateAI(uint32 /*diff*/)
{
    if (IsOverrun && !SetupOverrun)
    {
        SetupOverrun = true;
        if (faction == 0)
        {
            if (me->GetEntry() == GARGOYLE)
            {
                DummyTarget[0] = AllianceOverrunWP[50+OverrunType][0]; //+OverrunType 0 - 4
                DummyTarget[1] = AllianceOverrunWP[50+OverrunType][1];
                DummyTarget[2] = AllianceOverrunWP[50+OverrunType][2];
            }
            if (me->GetEntry() == ABOMINATION)
            {
                for (uint8 i = 0; i < 4; ++i)
                    AddWaypoint(i, AllianceWPs[i][0]+irand(-3, 3), AllianceWPs[i][1]+irand(-3, 3), AllianceWPs[i][2]);
                switch (OverrunType)
                {
                    case 0:
                        AddWaypoint(4, AllianceOverrunWP[22][0]+irand(-3, 3), AllianceOverrunWP[22][1]+irand(-3, 3), AllianceOverrunWP[22][2]);
                        AddWaypoint(5, AllianceOverrunWP[23][0]+irand(-3, 3), AllianceOverrunWP[23][1]+irand(-3, 3), AllianceOverrunWP[23][2]);
                        AddWaypoint(6, AllianceOverrunWP[24][0]+irand(-3, 3), AllianceOverrunWP[24][1]+irand(-3, 3), AllianceOverrunWP[24][2]);
                        AddWaypoint(7, AllianceOverrunWP[25][0]+irand(-3, 3), AllianceOverrunWP[25][1]+irand(-3, 3), AllianceOverrunWP[25][2]);
                        AddWaypoint(8, AllianceOverrunWP[26][0]+irand(-3, 3), AllianceOverrunWP[26][1]+irand(-3, 3), AllianceOverrunWP[26][2]);
                        AddWaypoint(9, AllianceOverrunWP[27][0]+irand(-3, 3), AllianceOverrunWP[27][1]+irand(-3, 3), AllianceOverrunWP[27][2]);
                        AddWaypoint(10, AllianceOverrunWP[28][0]+irand(-3, 3), AllianceOverrunWP[28][1]+irand(-3, 3), AllianceOverrunWP[28][2]);

                        AddWaypoint(11, AllianceOverrunWP[36][0]+irand(-3, 3), AllianceOverrunWP[36][1]+irand(-3, 3), AllianceOverrunWP[36][2]);
                        AddWaypoint(12, AllianceOverrunWP[37][0]+irand(-3, 3), AllianceOverrunWP[37][1]+irand(-3, 3), AllianceOverrunWP[37][2]);
                        AddWaypoint(13, AllianceOverrunWP[38][0]+irand(-3, 3), AllianceOverrunWP[38][1]+irand(-3, 3), AllianceOverrunWP[38][2]);
                        AddWaypoint(14, AllianceOverrunWP[39][0]+irand(-3, 3), AllianceOverrunWP[39][1]+irand(-3, 3), AllianceOverrunWP[39][2]);
                        AddWaypoint(15, AllianceOverrunWP[40][0]+irand(-3, 3), AllianceOverrunWP[40][1]+irand(-3, 3), AllianceOverrunWP[40][2]);
                        AddWaypoint(16, AllianceOverrunWP[41][0]+irand(-3, 3), AllianceOverrunWP[41][1]+irand(-3, 3), AllianceOverrunWP[41][2]);
                        AddWaypoint(17, AllianceOverrunWP[42][0]+irand(-3, 3), AllianceOverrunWP[42][1]+irand(-3, 3), AllianceOverrunWP[42][2]);
                        AddWaypoint(18, AllianceOverrunWP[43][0]+irand(-3, 3), AllianceOverrunWP[43][1]+irand(-3, 3), AllianceOverrunWP[43][2]);
                        me->SetHomePosition(AllianceOverrunWP[43][0]+irand(-3, 3), AllianceOverrunWP[43][1]+irand(-3, 3), AllianceOverrunWP[43][2], 0);
                        SetDespawnAtEnd(false);
                        LastOverronPos = 18;
                        Start(true, true);
                        break;
                     case 1:
                        AddWaypoint(4, AllianceOverrunWP[22][0]+irand(-3, 3), AllianceOverrunWP[22][1]+irand(-3, 3), AllianceOverrunWP[22][2]);
                        AddWaypoint(5, AllianceOverrunWP[23][0]+irand(-3, 3), AllianceOverrunWP[23][1]+irand(-3, 3), AllianceOverrunWP[23][2]);
                        AddWaypoint(6, AllianceOverrunWP[24][0]+irand(-3, 3), AllianceOverrunWP[24][1]+irand(-3, 3), AllianceOverrunWP[24][2]);
                        AddWaypoint(7, AllianceOverrunWP[25][0]+irand(-3, 3), AllianceOverrunWP[25][1]+irand(-3, 3), AllianceOverrunWP[25][2]);
                        AddWaypoint(8, AllianceOverrunWP[26][0]+irand(-3, 3), AllianceOverrunWP[26][1]+irand(-3, 3), AllianceOverrunWP[26][2]);
                        AddWaypoint(9, AllianceOverrunWP[27][0]+irand(-3, 3), AllianceOverrunWP[27][1]+irand(-3, 3), AllianceOverrunWP[27][2]);
                        AddWaypoint(10, AllianceOverrunWP[28][0]+irand(-3, 3), AllianceOverrunWP[28][1]+irand(-3, 3), AllianceOverrunWP[28][2]);

                        AddWaypoint(11, AllianceOverrunWP[36][0]+irand(-3, 3), AllianceOverrunWP[36][1]+irand(-3, 3), AllianceOverrunWP[36][2]);
                        AddWaypoint(12, AllianceOverrunWP[37][0]+irand(-3, 3), AllianceOverrunWP[37][1]+irand(-3, 3), AllianceOverrunWP[37][2]);
                        AddWaypoint(13, AllianceOverrunWP[38][0]+irand(-3, 3), AllianceOverrunWP[38][1]+irand(-3, 3), AllianceOverrunWP[38][2]);
                        AddWaypoint(14, AllianceOverrunWP[39][0]+irand(-3, 3), AllianceOverrunWP[39][1]+irand(-3, 3), AllianceOverrunWP[39][2]);
                        AddWaypoint(15, AllianceOverrunWP[40][0]+irand(-3, 3), AllianceOverrunWP[40][1]+irand(-3, 3), AllianceOverrunWP[40][2]);
                        AddWaypoint(16, AllianceOverrunWP[41][0]+irand(-3, 3), AllianceOverrunWP[41][1]+irand(-3, 3), AllianceOverrunWP[41][2]);
                        AddWaypoint(17, AllianceOverrunWP[42][0]+irand(-3, 3), AllianceOverrunWP[42][1]+irand(-3, 3), AllianceOverrunWP[42][2]);
                        AddWaypoint(18, AllianceOverrunWP[44][0]+irand(-3, 3), AllianceOverrunWP[44][1]+irand(-3, 3), AllianceOverrunWP[44][2]);
                        me->SetHomePosition(AllianceOverrunWP[44][0]+irand(-3, 3), AllianceOverrunWP[44][1]+irand(-3, 3), AllianceOverrunWP[44][2], 0);
                        SetDespawnAtEnd(false);
                        LastOverronPos = 18;
                        Start(true, true);
                        break;
                    default:
                        for (uint8 i = 22; i < 36; ++i)
                            AddWaypoint(i-18, AllianceOverrunWP[i][0]+irand(-3, 3), AllianceOverrunWP[i][1]+irand(-3, 3), AllianceOverrunWP[i][2]);

                        SetDespawnAtEnd(true);
                        LastOverronPos = 17;
                        Start(true, true);
                        break;
                }
            }
            if (me->GetEntry() == GHOUL)
            {
                for (uint8 i = 0; i < 4; ++i)
                    AddWaypoint(i, AllianceWPs[i][0]+irand(-3, 3), AllianceWPs[i][1]+irand(-3, 3), AllianceWPs[i][2]);
                switch (OverrunType)
                {
                    case 0:
                        AddWaypoint(4, AllianceOverrunWP[1][0]+irand(-3, 3), AllianceOverrunWP[1][1]+irand(-3, 3), AllianceOverrunWP[1][2]);
                        AddWaypoint(5, AllianceOverrunWP[2][0]+irand(-3, 3), AllianceOverrunWP[2][1]+irand(-3, 3), AllianceOverrunWP[2][2]);
                        me->SetHomePosition(AllianceOverrunWP[2][0]+irand(-3, 3), AllianceOverrunWP[2][1]+irand(-3, 3), AllianceOverrunWP[2][2], 0);
                        SetDespawnAtEnd(false);
                        LastOverronPos = 5;
                        Start(true, true);
                        break;
                    case 1:
                        AddWaypoint(4, AllianceOverrunWP[3][0]+irand(-3, 3), AllianceOverrunWP[3][1]+irand(-3, 3), AllianceOverrunWP[3][2]);
                        AddWaypoint(5, AllianceOverrunWP[4][0]+irand(-3, 3), AllianceOverrunWP[4][1]+irand(-3, 3), AllianceOverrunWP[4][2]);
                        AddWaypoint(6, AllianceOverrunWP[5][0]+irand(-3, 3), AllianceOverrunWP[5][1]+irand(-3, 3), AllianceOverrunWP[5][2]);
                        me->SetHomePosition(AllianceOverrunWP[5][0]+irand(-3, 3), AllianceOverrunWP[5][1]+irand(-3, 3), AllianceOverrunWP[5][2], 0);
                        SetDespawnAtEnd(false);
                        LastOverronPos = 6;
                        Start(true, true);
                        break;
                    case 2:
                        AddWaypoint(4, AllianceOverrunWP[6][0]+irand(-3, 3), AllianceOverrunWP[6][1]+irand(-3, 3), AllianceOverrunWP[6][2]);
                        AddWaypoint(5, AllianceOverrunWP[7][0]+irand(-3, 3), AllianceOverrunWP[7][1]+irand(-3, 3), AllianceOverrunWP[7][2]);
                        AddWaypoint(6, AllianceOverrunWP[8][0]+irand(-3, 3), AllianceOverrunWP[8][1]+irand(-3, 3), AllianceOverrunWP[8][2]);
                        AddWaypoint(7, AllianceOverrunWP[9][0]+irand(-3, 3), AllianceOverrunWP[9][1]+irand(-3, 3), AllianceOverrunWP[9][2]);
                        me->SetHomePosition(AllianceOverrunWP[9][0]+irand(-3, 3), AllianceOverrunWP[9][1]+irand(-3, 3), AllianceOverrunWP[9][2], 0);
                        SetDespawnAtEnd(false);
                        LastOverronPos = 7;
                        Start(true, true);
                        break;
                    case 3:
                        AddWaypoint(4, AllianceOverrunWP[10][0]+irand(-3, 3), AllianceOverrunWP[10][1]+irand(-3, 3), AllianceOverrunWP[10][2]);
                        AddWaypoint(5, AllianceOverrunWP[11][0]+irand(-3, 3), AllianceOverrunWP[11][1]+irand(-3, 3), AllianceOverrunWP[11][2]);
                        AddWaypoint(6, AllianceOverrunWP[12][0]+irand(-3, 3), AllianceOverrunWP[12][1]+irand(-3, 3), AllianceOverrunWP[12][2]);
                        me->SetHomePosition(AllianceOverrunWP[12][0]+irand(-3, 3), AllianceOverrunWP[12][1]+irand(-3, 3), AllianceOverrunWP[12][2], 0);
                        SetDespawnAtEnd(false);
                        LastOverronPos = 6;
                        Start(true, true);
                        break;
                    case 4:
                        AddWaypoint(4, AllianceOverrunWP[13][0]+irand(-3, 3), AllianceOverrunWP[13][1]+irand(-3, 3), AllianceOverrunWP[13][2]);
                        AddWaypoint(5, AllianceOverrunWP[14][0]+irand(-3, 3), AllianceOverrunWP[14][1]+irand(-3, 3), AllianceOverrunWP[14][2]);
                        AddWaypoint(6, AllianceOverrunWP[15][0]+irand(-3, 3), AllianceOverrunWP[15][1]+irand(-3, 3), AllianceOverrunWP[15][2]);
                        me->SetHomePosition(AllianceOverrunWP[15][0]+irand(-3, 3), AllianceOverrunWP[15][1]+irand(-3, 3), AllianceOverrunWP[15][2], 0);
                        SetDespawnAtEnd(false);
                        LastOverronPos = 6;
                        Start(true, true);
                        break;
                    case 5:
                        AddWaypoint(4, AllianceOverrunWP[16][0]+irand(-3, 3), AllianceOverrunWP[16][1]+irand(-3, 3), AllianceOverrunWP[16][2]);
                        AddWaypoint(5, AllianceOverrunWP[17][0]+irand(-3, 3), AllianceOverrunWP[17][1]+irand(-3, 3), AllianceOverrunWP[17][2]);
                        AddWaypoint(6, AllianceOverrunWP[18][0]+irand(-3, 3), AllianceOverrunWP[18][1]+irand(-3, 3), AllianceOverrunWP[18][2]);
                        AddWaypoint(7, AllianceOverrunWP[19][0]+irand(-3, 3), AllianceOverrunWP[19][1]+irand(-3, 3), AllianceOverrunWP[19][2]);
                        AddWaypoint(8, AllianceOverrunWP[20][0]+irand(-3, 3), AllianceOverrunWP[20][1]+irand(-3, 3), AllianceOverrunWP[20][2]);
                        AddWaypoint(9, AllianceOverrunWP[21][0]+irand(-3, 3), AllianceOverrunWP[21][1]+irand(-3, 3), AllianceOverrunWP[21][2]);
                        me->SetHomePosition(AllianceOverrunWP[21][0]+irand(-3, 3), AllianceOverrunWP[21][1]+irand(-3, 3), AllianceOverrunWP[21][2], 0);
                        SetDespawnAtEnd(false);
                        LastOverronPos = 9;
                        Start(true, true);
                        break;
                    default:
                        for (uint8 i = 22; i < 36; ++i)
                            AddWaypoint(i-18, AllianceOverrunWP[i][0]+irand(-3, 3), AllianceOverrunWP[i][1]+irand(-3, 3), AllianceOverrunWP[i][2]);
                        SetDespawnAtEnd(true);
                        LastOverronPos = 17;
                        Start(true, true);
                        break;
                }
            }
        }
        if (faction == 1)
        {
            if (me->GetEntry() == GHOUL)
            {
                for (uint8 i = 0; i < 6; ++i)
                    AddWaypoint(i, HordeWPs[i][0]+irand(-3, 3), HordeWPs[i][1]+irand(-3, 3), HordeWPs[i][2]);
                switch (OverrunType)
                {
                    case 0:
                        AddWaypoint(5, HordeOverrunWP[16][0]+irand(-10, 10), HordeOverrunWP[16][1]+irand(-10, 10), HordeOverrunWP[16][2]);
                        AddWaypoint(6, HordeOverrunWP[17][0]+irand(-10, 10), HordeOverrunWP[17][1]+irand(-10, 10), HordeOverrunWP[17][2]);
                        AddWaypoint(7, HordeOverrunWP[18][0], HordeOverrunWP[18][1], HordeOverrunWP[18][2]);
                        AddWaypoint(8, HordeOverrunWP[19][0], HordeOverrunWP[19][1], HordeOverrunWP[19][2]);
                        me->SetHomePosition(HordeOverrunWP[19][0], HordeOverrunWP[19][1], HordeOverrunWP[19][2], 0);
                        SetDespawnAtEnd(false);
                        LastOverronPos = 8;
                        Start(true, true);
                        break;
                    case 1:
                        AddWaypoint(5, HordeOverrunWP[16][0]+irand(-10, 10), HordeOverrunWP[16][1]+irand(-10, 10), HordeOverrunWP[16][2]);
                        AddWaypoint(6, HordeOverrunWP[17][0]+irand(-10, 10), HordeOverrunWP[17][1]+irand(-10, 10), HordeOverrunWP[17][2]);
                        AddWaypoint(7, HordeOverrunWP[18][0], HordeOverrunWP[18][1], HordeOverrunWP[18][2]);
                        AddWaypoint(8, HordeOverrunWP[20][0], HordeOverrunWP[20][1], HordeOverrunWP[20][2]);
                        me->SetHomePosition(HordeOverrunWP[20][0], HordeOverrunWP[20][1], HordeOverrunWP[20][2], 0);
                        SetDespawnAtEnd(false);
                        LastOverronPos = 8;
                        Start(true, true);
                        break;
                    default:
                        for (uint8 i = 0; i < 16; ++i)
                            AddWaypoint(i+6, HordeOverrunWP[i][0]+irand(-10, 10), HordeOverrunWP[i][1]+irand(-10, 10), HordeOverrunWP[i][2]);
                        SetDespawnAtEnd(true);
                        LastOverronPos = 21;
                        Start(true, true);
                        break;
                }
            }
            if (me->GetEntry() == ABOMINATION)
            {
                for (uint8 i = 0; i < 6; ++i)
                    AddWaypoint(i, HordeWPs[i][0]+irand(-10, 10), HordeWPs[i][1]+irand(-10, 10), HordeWPs[i][2]);
                for (uint8 i = 0; i < 16; ++i)
                    AddWaypoint(i+6, HordeOverrunWP[i][0]+irand(-10, 10), HordeOverrunWP[i][1]+irand(-10, 10), HordeOverrunWP[i][2]);
                SetDespawnAtEnd(true);
                LastOverronPos = 21;
                Start(true, true);
            }
        }
    }
}

void hyjal_trashAI::JustDied(Unit* /*killer*/)
{
    if (IsEvent && !me->isWorldBoss())
        instance->SetData(DATA_TRASH, 0);//signal trash is dead

    if ((instance->GetData(DATA_RAIDDAMAGE) < MINRAIDDAMAGE && !me->isWorldBoss()) || (damageTaken < me->GetMaxHealth()/4 && me->isWorldBoss()))
        me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);//no loot
}

class npc_giant_infernal : public CreatureScript
{
public:
    npc_giant_infernal() : CreatureScript("npc_giant_infernal") { }

    struct npc_giant_infernalAI : public hyjal_trashAI
    {
        npc_giant_infernalAI(Creature* creature) : hyjal_trashAI(creature)
        {
            instance = creature->GetInstanceScript();
            meteor = false;//call once!
            CanMove = false;
            Delay = rand()%30000;
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetDisplayId(MODEL_INVIS);
            go = false;
            Reset();
        }

        bool meteor;
        bool CanMove;
        bool go;
        uint32 spawnTimer;
        uint32 FlameBuffetTimer;
        bool imol;

        void Reset() override
        {
            spawnTimer = 2000;
            FlameBuffetTimer= 2000;
            imol = false;
        }

        void EnterCombat(Unit* /*who*/) override { }

        void WaypointReached(uint32 waypointId) override
        {
            if (waypointId == 0 && !IsOverrun)
            {
                if (instance->GetData(DATA_ALLIANCE_RETREAT))//2.alliance boss down, attack thrall
                {
                    Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_THRALL));
                    if (target && target->IsAlive())
                        me->AddThreat(target, 0.0f);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (Delay <= diff)
            {
                Delay=0;
            }else{
                Delay-=diff;
                return;
            }
            if (!meteor)
            {
                float x, y, z;
                me->GetPosition(x, y, z);
                Creature* trigger = me->SummonCreature(NPC_TRIGGER, x+8, y+8, z+25+rand()%10, me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 1000);
                if (trigger)
                {
                    trigger->SetVisible(false);
                    trigger->setFaction(me->getFaction());
                    trigger->SetDisableGravity(true);
                    trigger->CastSpell(me, SPELL_METEOR, true);
                }
                me->GetMotionMaster()->Clear();
                meteor = true;
            } else if (!CanMove){
                if (spawnTimer <= diff)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetDisplayId(me->GetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID));
                    CanMove = true;
                    if (instance->GetData(DATA_ALLIANCE_RETREAT) && !instance->GetData(DATA_HORDE_RETREAT))
                    {
                        Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_THRALL));
                        if (target && target->IsAlive())
                            me->AddThreat(target, 0.0f);
                    } else if (instance->GetData(DATA_ALLIANCE_RETREAT) && instance->GetData(DATA_HORDE_RETREAT)){
                        //do overrun
                    }
                } else spawnTimer -= diff;
            }
            if (!CanMove)return;
            hyjal_trashAI::UpdateAI(diff);
            if (IsEvent || IsOverrun)
                npc_escortAI::UpdateAI(diff);
            if (IsEvent)
            {
                if (!go)
                {
                    go = true;
                    AddWaypoint(0, HordeWPs[7][0]+irand(-3, 3),    HordeWPs[7][1]+irand(-3, 3),    HordeWPs[7][2]);//HordeWPs[7] infront of thrall
                    Start(true, true);
                    SetDespawnAtEnd(false);
                }
            }

            if (!UpdateVictim())
                return;
            if (!imol)
            {
                DoCast(me, SPELL_IMMOLATION);
                imol=true;
            }
            if (FlameBuffetTimer <= diff)
            {
                DoCastVictim(SPELL_FLAME_BUFFET, true);
                FlameBuffetTimer = 7000;
            } else FlameBuffetTimer -= diff;
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_giant_infernalAI>(creature);
    }
};

class npc_abomination : public CreatureScript
{
public:
    npc_abomination() : CreatureScript("npc_abomination") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_abominationAI>(creature);
    }

    struct npc_abominationAI : public hyjal_trashAI
    {
        npc_abominationAI(Creature* creature) : hyjal_trashAI(creature)
        {
            instance = creature->GetInstanceScript();
            go = false;
            Reset();
        }

        bool go;
        uint32 KnockDownTimer;
        void Reset() override
        {
            KnockDownTimer = 10000;
        }

        void WaypointReached(uint32 waypointId) override
        {
            if (waypointId == 7 && !IsOverrun)
            {
                if (instance->GetData(DATA_ALLIANCE_RETREAT))//2.alliance boss down, attack thrall
                {
                    Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_THRALL));
                    if (target && target->IsAlive())
                        me->AddThreat(target, 0.0f);
                }
                else
                {
                    Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_JAINAPROUDMOORE));
                    if (target && target->IsAlive())
                        me->AddThreat(target, 0.0f);
                }
            }
            if (waypointId == LastOverronPos && IsOverrun)
            {
                if ((faction == 0 && LastOverronPos == 17) || (faction == 1 && LastOverronPos == 21))
                {
                    me->setDeathState(DEAD);
                    me->RemoveCorpse();
                }
            }
        }

        void EnterCombat(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            hyjal_trashAI::UpdateAI(diff);
            if (IsEvent || IsOverrun)
                npc_escortAI::UpdateAI(diff);
            if (IsEvent)
            {
                if (!go)
                {
                    go = true;
                    if (instance->GetData(DATA_ALLIANCE_RETREAT))//2.alliance boss down, use horde WPs
                    {
                        for (uint8 i = 0; i < 8; ++i)
                            AddWaypoint(i, HordeWPs[i][0]+irand(-3, 3),    HordeWPs[i][1]+irand(-3, 3),    HordeWPs[i][2]);
                        Start(false, true);
                        SetDespawnAtEnd(false);
                    }else//use alliance WPs
                    {
                        for (uint8 i = 0; i < 8; ++i)
                            AddWaypoint(i, AllianceWPs[i][0]+irand(-3, 3),    AllianceWPs[i][1]+irand(-3, 3),    AllianceWPs[i][2]);
                        Start(false, true);
                        SetDespawnAtEnd(false);
                    }
                }
            }
            if (!me->HasAura(SPELL_DISEASE_CLOUD))
                DoCast(me, SPELL_DISEASE_CLOUD);
            if (!UpdateVictim())
                return;
            if (KnockDownTimer <= diff)
            {
                DoCastVictim(SPELL_KNOCKDOWN);
                KnockDownTimer = 15000+rand()%10000;
            } else KnockDownTimer -= diff;
            DoMeleeAttackIfReady();
        }
    };

};

class npc_ghoul : public CreatureScript
{
public:
    npc_ghoul() : CreatureScript("npc_ghoul") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_ghoulAI>(creature);
    }

    struct npc_ghoulAI : public hyjal_trashAI
    {
        npc_ghoulAI(Creature* creature) : hyjal_trashAI(creature)
        {
            instance = creature->GetInstanceScript();
            go = false;
            Reset();
        }

        bool go;
        uint32 FrenzyTimer;
        uint32 MoveTimer;
        bool RandomMove;
        void Reset() override
        {
            FrenzyTimer = 5000+rand()%5000;
            MoveTimer = 2000;
            RandomMove = false;
        }

        void WaypointReached(uint32 waypointId) override
        {
            if (waypointId == 7 && !IsOverrun)
            {
                if (instance->GetData(DATA_ALLIANCE_RETREAT))//2.alliance boss down, attack thrall
                {
                    Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_THRALL));
                    if (target && target->IsAlive())
                        me->AddThreat(target, 0.0f);
                }
                else
                {
                    Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_JAINAPROUDMOORE));
                    if (target && target->IsAlive())
                        me->AddThreat(target, 0.0f);
                }
            }
            if (waypointId == LastOverronPos && IsOverrun)
            {
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_ATTACK_UNARMED);
                if ((faction == 0 && LastOverronPos == 17) || (faction == 1 && LastOverronPos == 21))
                {
                    me->setDeathState(DEAD);
                    me->RemoveCorpse();
                }
            }
        }

        void EnterCombat(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            hyjal_trashAI::UpdateAI(diff);
            if (IsEvent || IsOverrun)
                npc_escortAI::UpdateAI(diff);
            if (IsEvent)
            {
                if (!go)
                {
                    go = true;
                    if (instance->GetData(DATA_ALLIANCE_RETREAT))//2.alliance boss down, use horde WPs
                    {
                        for (uint8 i = 0; i < 8; ++i)
                            AddWaypoint(i, HordeWPs[i][0]+irand(-3, 3),    HordeWPs[i][1]+irand(-3, 3),    HordeWPs[i][2]);
                        Start(false, true);
                        SetDespawnAtEnd(false);
                    }else//use alliance WPs
                    {
                        for (uint8 i = 0; i < 8; ++i)
                            AddWaypoint(i, AllianceWPs[i][0]+irand(-3, 3),    AllianceWPs[i][1]+irand(-3, 3),    AllianceWPs[i][2]);
                        Start(false, true);
                        SetDespawnAtEnd(false);
                    }
                }
            }
            if (FrenzyTimer <= diff)
            {
                DoCast(me, SPELL_FRENZY);
                FrenzyTimer = 15000+rand()%15000;
            } else FrenzyTimer -= diff;
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

};

class npc_necromancer : public CreatureScript
{
public:
    npc_necromancer() : CreatureScript("npc_necromancer") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_necromancerAI>(creature);
    }

    struct npc_necromancerAI : public hyjal_trashAI
    {
        npc_necromancerAI(Creature* creature) : hyjal_trashAI(creature), summons(me)
        {
            instance = creature->GetInstanceScript();
            go = false;
            Reset();
        }

        SummonList summons;
        bool go;
        uint32 ShadowBoltTimer;

        void Reset() override
        {
            ShadowBoltTimer = 1000+rand()%5000;
            summons.DespawnAll();
        }

        void JustSummoned(Creature* summon) override
        {
            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30, true);
            if (target)
                summon->Attack(target, false);
            summons.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            summons.Despawn(summon);
        }

        void WaypointReached(uint32 waypointId) override
        {
            if (waypointId == 7 && !IsOverrun)
            {
                if (instance->GetData(DATA_ALLIANCE_RETREAT))//2.alliance boss down, attack thrall
                {
                    Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_THRALL));
                    if (target && target->IsAlive())
                        me->AddThreat(target, 0.0f);
                }
                else
                {
                    Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_JAINAPROUDMOORE));
                    if (target && target->IsAlive())
                        me->AddThreat(target, 0.0f);
                }
            }
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            switch (urand(0, 2))
            {
                case 0:
                    DoSpawnCreature(17902, 3, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
                    DoSpawnCreature(17902, -3, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
                    break;
                case 1:
                    DoSpawnCreature(17903, 3, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
                    DoSpawnCreature(17903, -3, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
                    break;
                case 2:
                    DoSpawnCreature(RAND(17902, 17903), 3, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
                    break;
            }
        }

        void EnterCombat(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            hyjal_trashAI::UpdateAI(diff);

            if (IsEvent || IsOverrun)
                npc_escortAI::UpdateAI(diff);

            if (IsEvent)
            {
                if (!go)
                {
                    go = true;
                    if (instance->GetData(DATA_ALLIANCE_RETREAT))//2.alliance boss down, use horde WPs
                    {
                        for (uint8 i = 0; i < 8; ++i)
                            AddWaypoint(i, HordeWPs[i][0]+irand(-3, 3),    HordeWPs[i][1]+irand(-3, 3),    HordeWPs[i][2]);
                        Start(true, true);
                        SetDespawnAtEnd(false);
                    }else//use alliance WPs
                    {
                        for (uint8 i = 0; i < 8; ++i)
                            AddWaypoint(i, AllianceWPs[i][0]+irand(-3, 3),    AllianceWPs[i][1]+irand(-3, 3),    AllianceWPs[i][2]);
                        Start(true, true);
                        SetDespawnAtEnd(false);
                    }
                }
            }

            if (!UpdateVictim())
                return;

            if (ShadowBoltTimer <= diff)
            {
                DoCastVictim(SPELL_SHADOW_BOLT);
                ShadowBoltTimer = 20000+rand()%10000;
            } else ShadowBoltTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

class npc_banshee : public CreatureScript
{
public:
    npc_banshee() : CreatureScript("npc_banshee") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_bansheeAI>(creature);
    }

    struct npc_bansheeAI : public hyjal_trashAI
    {
        npc_bansheeAI(Creature* creature) : hyjal_trashAI(creature)
        {
            instance = creature->GetInstanceScript();
            go = false;
            Reset();
        }

        bool go;
        uint32 CourseTimer;
        uint32 WailTimer;
        uint32 ShellTimer;

        void Reset() override
        {
            CourseTimer = 20000+rand()%5000;
            WailTimer = 15000+rand()%5000;
            ShellTimer = 50000+rand()%10000;
        }

        void WaypointReached(uint32 waypointId) override
        {
            if (waypointId == 7 && !IsOverrun)
            {
                if (instance->GetData(DATA_ALLIANCE_RETREAT))//2.alliance boss down, attack thrall
                {
                    Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_THRALL));
                    if (target && target->IsAlive())
                        me->AddThreat(target, 0.0f);
                }
                else
                {
                    Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_JAINAPROUDMOORE));
                    if (target && target->IsAlive())
                        me->AddThreat(target, 0.0f);
                }
            }
        }

        void EnterCombat(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            hyjal_trashAI::UpdateAI(diff);
            if (IsEvent || IsOverrun)
                npc_escortAI::UpdateAI(diff);
            if (IsEvent)
            {
                if (!go)
                {
                    go = true;
                    if (instance->GetData(DATA_ALLIANCE_RETREAT))//2.alliance boss down, use horde WPs
                    {
                        for (uint8 i = 0; i < 8; ++i)
                            AddWaypoint(i, HordeWPs[i][0]+irand(-3, 3),    HordeWPs[i][1]+irand(-3, 3),    HordeWPs[i][2]);
                        Start(false, true);
                        SetDespawnAtEnd(false);
                    }else//use alliance WPs
                    {
                        for (uint8 i = 0; i < 8; ++i)
                            AddWaypoint(i, AllianceWPs[i][0]+irand(-3, 3),    AllianceWPs[i][1]+irand(-3, 3),    AllianceWPs[i][2]);
                        Start(false, true);
                        SetDespawnAtEnd(false);
                    }
                }
            }
            if (!UpdateVictim())
                return;
            if (CourseTimer <= diff)
            {
                DoCastVictim(SPELL_BANSHEE_CURSE);
                CourseTimer = 20000+rand()%5000;
            } else CourseTimer -= diff;
            if (WailTimer <= diff)
            {
                DoCastVictim(SPELL_BANSHEE_WAIL);
                WailTimer = 15000+rand()%5000;
            } else WailTimer -= diff;
            if (ShellTimer <= diff)
            {
                DoCast(me, SPELL_ANTI_MAGIC_SHELL);
                ShellTimer = 50000+rand()%10000;
            } else ShellTimer -= diff;
            DoMeleeAttackIfReady();
        }
    };

};

class npc_crypt_fiend : public CreatureScript
{
public:
    npc_crypt_fiend() : CreatureScript("npc_crypt_fiend") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_crypt_fiendAI>(creature);
    }

    struct npc_crypt_fiendAI : public hyjal_trashAI
    {
        npc_crypt_fiendAI(Creature* creature) : hyjal_trashAI(creature)
        {
            instance = creature->GetInstanceScript();
            go = false;
            Reset();
        }

        bool go;
        uint32 WebTimer;

        void Reset() override
        {
            WebTimer = 20000+rand()%5000;
        }

        void WaypointReached(uint32 waypointId) override
        {
            if (waypointId == 7 && !IsOverrun)
            {
                if (instance->GetData(DATA_ALLIANCE_RETREAT))//2.alliance boss down, attack thrall
                {
                    Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_THRALL));
                    if (target && target->IsAlive())
                        me->AddThreat(target, 0.0f);
                }
                else
                {
                    Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_JAINAPROUDMOORE));
                    if (target && target->IsAlive())
                        me->AddThreat(target, 0.0f);
                }
            }
        }

        void EnterCombat(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            hyjal_trashAI::UpdateAI(diff);
            if (IsEvent || IsOverrun)
                npc_escortAI::UpdateAI(diff);
            if (IsEvent)
            {
                if (!go)
                {
                    go = true;
                    if (instance->GetData(DATA_ALLIANCE_RETREAT))//2.alliance boss down, use horde WPs
                    {
                        for (uint8 i = 0; i < 8; ++i)
                            AddWaypoint(i, HordeWPs[i][0]+irand(-3, 3),    HordeWPs[i][1]+irand(-3, 3),    HordeWPs[i][2]);
                        Start(false, true);
                        SetDespawnAtEnd(false);
                    }else//use alliance WPs
                    {
                        for (uint8 i = 0; i < 8; ++i)
                            AddWaypoint(i, AllianceWPs[i][0]+irand(-3, 3),    AllianceWPs[i][1]+irand(-3, 3),    AllianceWPs[i][2]);
                        Start(false, true);
                        SetDespawnAtEnd(false);
                    }
                }
            }
            if (!UpdateVictim())
                return;
            if (WebTimer <= diff)
            {
                DoCastVictim(SPELL_WEB);
                WebTimer = 20000+rand()%5000;
            } else WebTimer -= diff;
            DoMeleeAttackIfReady();
        }
    };

};

class npc_fel_stalker : public CreatureScript
{
public:
    npc_fel_stalker() : CreatureScript("npc_fel_stalker") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_fel_stalkerAI>(creature);
    }

    struct npc_fel_stalkerAI : public hyjal_trashAI
    {
        npc_fel_stalkerAI(Creature* creature) : hyjal_trashAI(creature)
        {
            instance = creature->GetInstanceScript();
            go = false;
            Reset();
        }

        bool go;
        uint32 ManaBurnTimer;

        void Reset() override
        {
            ManaBurnTimer = 9000+rand()%5000;
        }

        void WaypointReached(uint32 waypointId) override
        {
            if (waypointId == 7 && !IsOverrun)
            {
                if (instance->GetData(DATA_ALLIANCE_RETREAT))//2.alliance boss down, attack thrall
                {
                    Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_THRALL));
                    if (target && target->IsAlive())
                        me->AddThreat(target, 0.0f);
                }
                else
                {
                    Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_JAINAPROUDMOORE));
                    if (target && target->IsAlive())
                        me->AddThreat(target, 0.0f);
                }
            }
        }

        void EnterCombat(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            hyjal_trashAI::UpdateAI(diff);
            if (IsEvent || IsOverrun)
                npc_escortAI::UpdateAI(diff);
            if (IsEvent)
            {
                if (!go)
                {
                    go = true;
                    if (instance->GetData(DATA_ALLIANCE_RETREAT))//2.alliance boss down, use horde WPs
                    {
                        for (uint8 i = 0; i < 8; ++i)
                            AddWaypoint(i, HordeWPs[i][0]+irand(-3, 3),    HordeWPs[i][1]+irand(-3, 3),    HordeWPs[i][2]);
                        Start(false, true);
                        SetDespawnAtEnd(false);
                    }else//use alliance WPs
                    {
                        for (uint8 i = 0; i < 8; ++i)
                            AddWaypoint(i, AllianceWPs[i][0]+irand(-3, 3),    AllianceWPs[i][1]+irand(-3, 3),    AllianceWPs[i][2]);
                        Start(false, true);
                        SetDespawnAtEnd(false);
                    }
                }
            }
            if (!UpdateVictim())
                return;
            if (ManaBurnTimer <= diff)
            {
                DoCastVictim(SPELL_MANA_BURN);
                ManaBurnTimer = 9000+rand()%5000;
            } else ManaBurnTimer -= diff;
            DoMeleeAttackIfReady();
        }
    };

};

class npc_frost_wyrm : public CreatureScript
{
public:
    npc_frost_wyrm() : CreatureScript("npc_frost_wyrm") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_frost_wyrmAI>(creature);
    }

    struct npc_frost_wyrmAI : public hyjal_trashAI
    {
        npc_frost_wyrmAI(Creature* creature) : hyjal_trashAI(creature)
        {
            instance = creature->GetInstanceScript();
            go = false;
            Reset();
        }

        bool go;
        uint32 FrostBreathTimer;
        uint32 MoveTimer;

        void Reset() override
        {
            FrostBreathTimer = 5000;
            MoveTimer = 0;
            me->SetDisableGravity(true);
        }

        void WaypointReached(uint32 waypointId) override
        {
            if (waypointId == 2 && !IsOverrun)
            {
                Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_THRALL));
                if (target && target->IsAlive())
                {
                    me->AddThreat(target, 0.0f);
                    DoCast(target, SPELL_FROST_BREATH, true);
                }
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (IsEvent)
                instance->SetData(DATA_TRASH, 0);//signal trash is dead

            float x, y, z;
            me->GetPosition(x, y, z);
            z = me->GetMap()->GetHeight(me->GetPhaseMask(), x, y, z);
            me->GetMotionMaster()->MovePoint(0, x, y, z);
            me->SetPosition(x, y, z, 0);
        }

        void EnterCombat(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            hyjal_trashAI::UpdateAI(diff);

            if (IsEvent || IsOverrun)
            {
                CAST_AI(hyjal_trashAI, me->AI())->SetCanAttack(false);
                npc_escortAI::UpdateAI(diff);
            }

            if (IsEvent)
            {
                if (!go)
                {
                    go = true;
                    if (!useFlyPath)
                    {
                        for (uint8 i = 0; i < 3; ++i)
                            AddWaypoint(i, FrostWyrmWPs[i][0],    FrostWyrmWPs[i][1],    FrostWyrmWPs[i][2]);
                        Start(false, true);
                        SetDespawnAtEnd(false);
                    }
                    else
                    {//fly path FlyPathWPs
                        for (uint8 i = 0; i < 3; ++i)
                            AddWaypoint(i, FlyPathWPs[i][0]+irand(-10, 10),    FlyPathWPs[i][1]+irand(-10, 10),    FlyPathWPs[i][2]);
                        Start(false, true);
                        SetDespawnAtEnd(false);
                    }
                }
            }

            if (!UpdateVictim())
                return;

            if (!me->IsWithinDist(me->GetVictim(), 25))
            {
                if (MoveTimer <= diff)
                {
                    me->GetMotionMaster()->MoveChase(me->GetVictim());
                    MoveTimer = 2000;
                } else MoveTimer-=diff;
            }

            if (FrostBreathTimer <= diff)
            {
                if (!me->IsWithinDist(me->GetVictim(), 25))
                {
                    DoCastVictim(SPELL_FROST_BREATH);
                    me->StopMoving();
                    me->GetMotionMaster()->Clear();
                    FrostBreathTimer = 4000;
                }
            } else FrostBreathTimer -= diff;
        }
    };
};

class npc_gargoyle : public CreatureScript
{
public:
    npc_gargoyle() : CreatureScript("npc_gargoyle") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_gargoyleAI>(creature);
    }

    struct npc_gargoyleAI : public hyjal_trashAI
    {
        npc_gargoyleAI(Creature* creature) : hyjal_trashAI(creature)
        {
            instance = creature->GetInstanceScript();
            go = false;
            for (uint8 i = 0; i < 3; ++i)
                DummyTarget[i] = 0;
            Reset();
        }

        bool go;
        uint32 StrikeTimer;
        uint32 MoveTimer;
        float Zpos;
        bool forcemove;

        void Reset() override
        {
            forcemove = true;
            Zpos = 10.0f;
            StrikeTimer = 2000+rand()%5000;
            MoveTimer = 0;
            me->SetDisableGravity(true);
        }

        void WaypointReached(uint32 waypointId) override
        {
            if (waypointId == 2 && !IsOverrun)
            {
                Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_THRALL));
                if (target && target->IsAlive())
                {
                    me->AddThreat(target, 0.0f);
                    DoCast(target, SPELL_GARGOYLE_STRIKE, true);
                }
            }
        }

        void JustDied(Unit* killer) override
        {
            float x, y, z;
            me->GetPosition(x, y, z);
            z = me->GetMap()->GetHeight(me->GetPhaseMask(), x, y, z);
            me->GetMotionMaster()->MovePoint(0, x, y, z);
            me->SetPosition(x, y, z, 0);
            hyjal_trashAI::JustDied(killer);
        }

        void UpdateAI(uint32 diff) override
        {
            hyjal_trashAI::UpdateAI(diff);

            if (IsEvent || IsOverrun)
            {
                CAST_AI(hyjal_trashAI, me->AI())->SetCanAttack(false);
                npc_escortAI::UpdateAI(diff);
            }

            if (IsEvent)
            {
                if (!go)
                {
                    go = true;
                    if (!useFlyPath)
                    {
                        for (uint8 i = 0; i < 3; ++i)
                            AddWaypoint(i, GargoyleWPs[i][0]+irand(-10, 10), GargoyleWPs[i][1]+irand(-10, 10), GargoyleWPs[i][2]);
                        Start(false, true);
                        SetDespawnAtEnd(false);
                    }else{//fly path FlyPathWPs
                        for (uint8 i = 0; i < 3; ++i)
                            AddWaypoint(i, FlyPathWPs[i][0]+irand(-10, 10),    FlyPathWPs[i][1]+irand(-10, 10),    FlyPathWPs[i][2]);
                        Start(false, true);
                        SetDespawnAtEnd(false);
                    }
                }
            }

            if (IsOverrun && !UpdateVictim())
            {
                if (faction == 0)//alliance
                {
                    if (StrikeTimer <= diff)
                    {
                        me->CastSpell(DummyTarget[0], DummyTarget[1], DummyTarget[2], SPELL_GARGOYLE_STRIKE, false);
                        StrikeTimer = 2000+rand()%1000;
                    } else StrikeTimer -= diff;
                    }
            }

            if (!UpdateVictim())
                return;

            if (!me->IsWithinDist(me->GetVictim(), 20) || forcemove)
            {
                forcemove = false;
                if (forcemove)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->Attack(target, false);
                }
                if (MoveTimer <= diff)
                {
                    float x, y, z;
                    me->EnsureVictim()->GetPosition(x, y, z);
                    me->GetMotionMaster()->MovePoint(0, x, y, z+Zpos);
                    Zpos -= 1.0f;
                    if (Zpos <= 0)
                        Zpos = 0;
                    MoveTimer = 2000;
                } else MoveTimer-=diff;
            }

            if (StrikeTimer <= diff)
            {
                if (me->IsWithinDist(me->GetVictim(), 20))
                {
                    DoCastVictim(SPELL_GARGOYLE_STRIKE);
                    me->StopMoving();
                    me->GetMotionMaster()->Clear();
                    StrikeTimer = 2000+rand()%1000;
                } else StrikeTimer=0;
            } else StrikeTimer -= diff;
        }
    };
};

class alliance_rifleman : public CreatureScript
{
public:
    alliance_rifleman() : CreatureScript("alliance_rifleman") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new alliance_riflemanAI(creature);
    }

    struct alliance_riflemanAI : public ScriptedAI
    {
        alliance_riflemanAI(Creature* creature) : ScriptedAI(creature)
        {
            SetCombatMovement(false);
        }

        uint32 ExplodeTimer;

        void JustDied(Unit* /*killer*/) override
        {
        }

        void Reset() override
        {
            ExplodeTimer = 5000+rand()%5000;
        }

        void MoveInLineOfSight(Unit* who) override

        {
            if (!who || me->GetVictim())
                return;

            if (me->IsValidAttackTarget(who))
            {
                //float attackRadius = me->GetAttackDistance(who);
                if (me->IsWithinDistInMap(who, 30))
                    AttackStart(who);
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            //Check if we have a target
            if (!UpdateVictim())
                return;
            if (ExplodeTimer <= diff)
            {
                if (!me->IsWithinDistInMap(me->GetVictim(), 30))
                {
                    EnterEvadeMode();
                    return;
                }
                int dmg = 500+rand()%700;
                me->CastCustomSpell(me->GetVictim(), SPELL_EXPLODING_SHOT, &dmg, 0, 0, false);
                ExplodeTimer = 5000+rand()%5000;
            } else ExplodeTimer -= diff;
            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_hyjal_trash()
{
    new npc_giant_infernal();
    new npc_abomination();
    new npc_ghoul();
    new npc_necromancer();
    new npc_banshee();
    new npc_crypt_fiend();
    new npc_fel_stalker();
    new npc_frost_wyrm();
    new npc_gargoyle();
    new alliance_rifleman();
}
