/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __BATTLEGROUNDSA_H
#define __BATTLEGROUNDSA_H

class Battleground;

class BattlegroundSAScore : public BattlegroundScore
{
    public:
        BattlegroundSAScore(): demolishers_destroyed(0), gates_destroyed(0) {};
        virtual ~BattlegroundSAScore() {};
    uint8 demolishers_destroyed;
    uint8 gates_destroyed;
};

#define BG_SA_FLAG_AMOUNT 3
#define BG_SA_DEMOLISHER_AMOUNT 4

enum BG_SA_Status
  {
    BG_SA_NOTSTARTED = 0,
    BG_SA_WARMUP,
    BG_SA_ROUND_ONE,
    BG_SA_SECOND_WARMUP,
    BG_SA_ROUND_TWO,
    BG_SA_BONUS_ROUND
  };

enum BG_SA_GateState
  {
    BG_SA_GATE_OK = 1,
    BG_SA_GATE_DAMAGED = 2,
    BG_SA_GATE_DESTROYED = 3
  };

enum BG_SA_Timers
  {
    BG_SA_BOAT_START  =  60000,
    BG_SA_WARMUPLENGTH = 120000,
    BG_SA_ROUNDLENGTH = 600000
  };

enum BG_SA_WorldStates
  {
    BG_SA_TIMER_MINS = 3559,
    BG_SA_TIMER_SEC_TENS = 3560,
    BG_SA_TIMER_SEC_DECS = 3561,
    BG_SA_ALLY_ATTACKS  = 4352,
    BG_SA_HORDE_ATTACKS = 4353,

    BG_SA_PURPLE_GATEWS = 3614,
    BG_SA_RED_GATEWS = 3617,
    BG_SA_BLUE_GATEWS = 3620,
    BG_SA_GREEN_GATEWS = 3623,
    BG_SA_YELLOW_GATEWS = 3638,
    BG_SA_ANCIENT_GATEWS = 3849,


    BG_SA_LEFT_GY_ALLIANCE = 3635,
    BG_SA_RIGHT_GY_ALLIANCE = 3636,
    BG_SA_CENTER_GY_ALLIANCE = 3637,

    BG_SA_RIGHT_ATT_TOKEN_ALL = 3627,
    BG_SA_LEFT_ATT_TOKEN_ALL = 3626,

    BG_SA_LEFT_ATT_TOKEN_HRD = 3629,
    BG_SA_RIGHT_ATT_TOKEN_HRD = 3628,

    BG_SA_HORDE_DEFENCE_TOKEN = 3631,
    BG_SA_ALLIANCE_DEFENCE_TOKEN = 3630,

    BG_SA_RIGHT_GY_HORDE = 3632,
    BG_SA_LEFT_GY_HORDE = 3633,
    BG_SA_CENTER_GY_HORDE = 3634,

    BG_SA_BONUS_TIMER = 0xdf3,
    BG_SA_ENABLE_TIMER = 3564,
  };

enum BG_SA_NPCs
  {
    BG_SA_GUN_1 = 0,
    BG_SA_GUN_2,
    BG_SA_GUN_3,
    BG_SA_GUN_4,
    BG_SA_GUN_5,
    BG_SA_GUN_6,
    BG_SA_GUN_7,
    BG_SA_GUN_8,
    BG_SA_GUN_9,
    BG_SA_GUN_10,
    BG_SA_DEMOLISHER_1,
    BG_SA_DEMOLISHER_2,
    BG_SA_DEMOLISHER_3,
    BG_SA_DEMOLISHER_4,
    BG_SA_NPC_TRIGGER_1,
    BG_SA_NPC_TRIGGER_2,
    BG_SA_NPC_TRIGGER_3,
    BG_SA_NPC_TRIGGER_4,
    BG_SA_NPC_TRIGGER_5,
    BG_SA_NPC_SPARKLIGHT,
    BG_SA_NPC_RIGSPARK,
    BG_SA_MAXNPC
  };

const uint32 BG_SA_NpcEntries[BG_SA_MAXNPC] =
  {
    27894,
    27894,
    27894,
    27894,
    27894,
    27894,
    27894,
    27894,
    27894,
    27894,
    //4 beach demolishers
    28781,
    28781,
    28781,
    28781,
    //Triggers
    23472,
    23472,
    23472,
    23472,
    23472,
    //Fizzle Sparklight, or whatever his name was
    29260,
    29262
  };

const float BG_SA_NpcSpawnlocs[BG_SA_MAXNPC + BG_SA_DEMOLISHER_AMOUNT][4] =
  {
    //Cannons
    { 1436.429f, 110.05f, 41.407f, 5.4f },
    { 1404.9023f, 84.758f, 41.183f, 5.46f },
    { 1068.693f, -86.951f, 93.81f, 0.02f },
    { 1068.83f, -127.56f, 96.45f, 0.0912f },
    { 1422.115f, -196.433f, 42.1825f, 1.0222f },
    { 1454.887f, -220.454f, 41.956f, 0.9627f },
    { 1232.345f, -187.517f, 66.945f, 0.45f },
    { 1249.634f, -224.189f, 66.72f, 0.635f },
    { 1236.213f, 92.287f, 64.965f, 5.751f },
    { 1215.11f, 57.772f, 64.739f, 5.78f } ,
    //Demolishers
    { 1611.597656,-117.270073,8.719355,2.513274},
    { 1575.562500,-158.421875,5.024450,2.129302},
    { 1618.047729,61.424641,7.248210,3.979351},
    { 1575.103149,98.873344,2.830360,3.752458},
    //trigger
    { 1453.49, -250.453, 30.896, 4.2883},
    { 1377.05, 97.036, 30.8605, 2.46539},
    { 1186.05, 58.8048, 56.5491, 2.75992},
    { 1042.83, -72.839, 84.8145, 3.58615},
    { 1233.62, -250.49, 55.4036, 3.7016},
    //Npcs
    { 1348.644165, -298.786469, 31.080130, 1.710423},
    { 1358.191040, 195.527786, 31.018187, 4.171337},
    //Demolishers2
    { 1371.055786, -317.071136, 35.007359, 1.947460},
    { 1424.034912, -260.195190, 31.084425, 2.820013},
    { 1353.139893, 223.745438, 35.265411, 4.343684},
    { 1404.809570, 197.027237, 32.046032, 3.605401}
  };

enum BG_SA_Objects
  {
    BG_SA_GREEN_GATE = 0,
    BG_SA_YELLOW_GATE,
    BG_SA_BLUE_GATE,
    BG_SA_RED_GATE,
    BG_SA_PURPLE_GATE,
    BG_SA_ANCIENT_GATE,
    BG_SA_TITAN_RELIC,
    BG_SA_BOAT_ONE,
    BG_SA_BOAT_TWO,
    BG_SA_SIGIL_1,
    BG_SA_SIGIL_2,
    BG_SA_SIGIL_3,
    BG_SA_SIGIL_4,
    BG_SA_SIGIL_5,
    BG_SA_CENTRAL_FLAGPOLE,
    BG_SA_RIGHT_FLAGPOLE,
    BG_SA_LEFT_FLAGPOLE,
    BG_SA_CENTRAL_FLAG,
    BG_SA_RIGHT_FLAG,
    BG_SA_LEFT_FLAG,
    BG_SA_PORTAL_DEFFENDER_BLUE,
    BG_SA_PORTAL_DEFFENDER_GREEN,
    BG_SA_PORTAL_DEFFENDER_YELLOW,
    BG_SA_PORTAL_DEFFENDER_PURPLE,
    BG_SA_PORTAL_DEFFENDER_RED,
    BG_SA_BOMB,
    BG_SA_MAXOBJ = BG_SA_BOMB+68
  };

const float BG_SA_ObjSpawnlocs[BG_SA_MAXOBJ][4] =
  {
    { 1411.57f, 108.163f, 28.692f, 5.441f },
    { 1055.452f, -108.1f, 82.134f, 0.034f },
    { 1431.3413f, -219.437f, 30.893f, 0.9736f },
    { 1227.667f, -212.555f, 55.372f, 0.5023f },
    { 1214.681f, 81.21f, 53.413f, 5.745f },
    { 878.555f, -108.2f, 117.845f, 0.0f },
    { 836.5f, -108.8f, 120.219f, 0.0f },
    //Ships
    { 2679.696777, -826.891235, 3.712860, 5.78367f}, //rot2 1 rot3 0.0002
    { 2574.003662, 981.261475, 2.603424, 0.807696},
    //Sigils
    { 1414.054f, 106.72f, 41.442f, 5.441f },
    { 1060.63f, -107.8f, 94.7f, 0.034f },
    { 1433.383f, -216.4f, 43.642f, 0.9736f },
    { 1230.75f, -210.724f, 67.611f, 0.5023f },
    { 1217.8f, 79.532f, 66.58f, 5.745f },
    //Flagpoles
    { 1215.114258,-65.711861,70.084267,-3.124123},
    {1338.863892,-153.336533,30.895121,-2.530723},
    {1309.124268,9.410645,30.893402,-1.623156},
    //Flags
    { 1215.108032,-65.715767,70.084267,-3.124123},
    { 1338.859253,-153.327316,30.895077,-2.530723},
    { 1309.192017,9.416233,30.893402,1.518436},
    //Portal
    {1468.380005, -225.798996, 30.896200, 0.0}, //blue
    {1394.270020, 72.551399, 31.054300, 0.0},//green
    {1065.260010, -89.79501, 81.073402, 0.0},//yellow
    {1216.069946, 47.904301, 54.278198,0.0}, //purple
    {1255.569946, -233.548996, 56.43699, 0.0},//red
    //Bombs
    {1333.45, 211.354, 31.0538, 5.03666},
    {1334.29, 209.582, 31.0532, 1.28088},
    {1332.72, 210.049, 31.0532, 1.28088},
    {1334.28, 210.78, 31.0538, 3.85856},
    {1332.64, 211.39, 31.0532, 1.29266},
    {1371.41, 194.028, 31.5107, 0.753095},
    {1372.39, 194.951, 31.4679, 0.753095},
    {1371.58, 196.942, 30.9349, 1.01777},
    {1370.43, 196.614, 30.9349, 0.957299},
    {1369.46, 196.877, 30.9351, 2.45348},
    {1370.35, 197.361, 30.9349, 1.08689},
    {1369.47, 197.941, 30.9349, 0.984787},
    {1592.49, 47.5969, 7.52271, 4.63218},
    {1593.91, 47.8036, 7.65856, 4.63218},
    {1593.13, 46.8106, 7.54073, 4.63218},
    {1589.22, 36.3616, 7.45975, 4.64396},
    {1588.24, 35.5842, 7.55613, 4.79564},
    {1588.14, 36.7611, 7.49675, 4.79564},
    {1595.74, 35.5278, 7.46602, 4.90246},
    {1596, 36.6475, 7.47991, 4.90246},
    {1597.03, 36.2356, 7.48631, 4.90246},
    {1597.93, 37.1214, 7.51725, 4.90246},
    {1598.16, 35.888, 7.50018, 4.90246},
    {1579.6, -98.0917, 8.48478, 1.37996},
    {1581.2, -98.401, 8.47483, 1.37996},
    {1580.38, -98.9556, 8.4772, 1.38781},
    {1585.68, -104.966, 8.88551, 0.493246},
    {1586.15, -106.033, 9.10616, 0.493246},
    {1584.88, -105.394, 8.82985, 0.493246},
    {1581.87, -100.899, 8.46164, 0.929142},
    {1581.48, -99.4657, 8.46926, 0.929142},
    {1583.2, -91.2291, 8.49227, 1.40038},
    {1581.94, -91.0119, 8.49977, 1.40038},
    {1582.33, -91.951, 8.49353, 1.1844},
    {1342.06, -304.049, 30.9532, 5.59507},
    {1340.96, -304.536, 30.9458, 1.28323},
    {1341.22, -303.316, 30.9413, 0.486051},
    {1342.22, -302.939, 30.986, 4.87643},
    {1382.16, -287.466, 32.3063, 4.80968},
    {1381, -287.58, 32.2805, 4.80968},
    {1381.55, -286.536, 32.3929, 2.84225},
    {1382.75, -286.354, 32.4099, 1.00442},
    {1379.92, -287.34, 32.2872, 3.81615},
    {1100.52, -2.41391, 70.2984, 0.131054},
    {1099.35, -2.13851, 70.3375, 4.4586},
    {1099.59, -1.00329, 70.238, 2.49903},
    {1097.79, 0.571316, 70.159, 4.00307},
    {1098.74, -7.23252, 70.7972, 4.1523},
    {1098.46, -5.91443, 70.6715, 4.1523},
    {1097.53, -7.39704, 70.7959, 4.1523},
    {1097.32, -6.64233, 70.7424, 4.1523},
    {1096.45, -5.96664, 70.7242, 4.1523},
    {971.725, 0.496763, 86.8467, 2.09233},
    {973.589, 0.119518, 86.7985, 3.17225},
    {972.524, 1.25333, 86.8351, 5.28497},
    {971.993, 2.05668, 86.8584, 5.28497},
    {973.635, 2.11805, 86.8197, 2.36722},
    {974.791, 1.74679, 86.7942, 1.5936},
    {974.771, 3.0445, 86.8125, 0.647199},
    {979.554, 3.6037, 86.7923, 1.69178},
    {979.758, 2.57519, 86.7748, 1.76639},
    {980.769, 3.48904, 86.7939, 1.76639},
    {979.122, 2.87109, 86.7794, 1.76639},
    {986.167, 4.85363, 86.8439, 1.5779},
    {986.176, 3.50367, 86.8217, 1.5779},
    {987.33, 4.67389, 86.8486, 1.5779},
    {985.23, 4.65898, 86.8368, 1.5779},
    {984.556, 3.54097, 86.8137, 1.5779},
  };

/* Ships:
 * 193182 - ally
 * 193183 - horde
 * 193184 - horde
 * 193185 - ally
 * Banners:
 * 191308 - left one,
 * 191306 - right one,
 * 191310 - central,
 * Ally ones, substract 1
 * to get horde ones.
 */

const uint32 BG_SA_ObjEntries[BG_SA_MAXOBJ + BG_SA_FLAG_AMOUNT] =
  {
    190722,
    190727,
    190724,
    190726,
    190723,
    192549,
    192834,
    193182,
    193185,
    192687,
    192685,
    192689,
    192690,
    192691,
    191311,
    191311,
    191311,
    191310,
    191306,
    191308,
    192819,
    192819,
    192819,
    192819,
    192819,
    190753
  };

const uint32 BG_SA_Factions[2] =
  {
    1732,
    1735,
  };

enum BG_SA_Graveyards
  {
    BG_SA_BEACH_GY = 0,
    BG_SA_DEFENDER_LAST_GY,
    BG_SA_RIGHT_CAPTURABLE_GY,
    BG_SA_LEFT_CAPTURABLE_GY,
    BG_SA_CENTRAL_CAPTURABLE_GY,
    BG_SA_MAX_GY
  };

const uint32 BG_SA_GYEntries[BG_SA_MAX_GY] =
  {
    1350,
    1349,
    1347,
    1346,
    1348,
  };

const float BG_SA_GYOrientation[BG_SA_MAX_GY] =
  {
    6.202f,
    1.926f, //right capturable GY
    3.917f, //left capturable GY
    3.104f, //center, capturable
    6.148f, //defender last GY
  };

struct BG_SA_RoundScore
{
  TeamId winner;
  uint32 time;
};

class BattlegroundSA : public Battleground
{
    friend class BattlegroundMgr;

    public:
        BattlegroundSA();
        ~BattlegroundSA();
        void Update(uint32 diff);

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player *plr);
        virtual void StartingEventCloseDoors();
        virtual void StartingEventOpenDoors();
    virtual bool SetupBattleground();
    virtual void Reset();
    virtual void FillInitialWorldStates(WorldPacket& data);
    virtual void EventPlayerDamagedGO(Player* plr, GameObject* go, uint8 hitType, uint32 destroyedEvent);
    virtual void HandleKillUnit(Creature* unit, Player* killer);
    virtual WorldSafeLocsEntry const* GetClosestGraveYard(Player* player);
    virtual void EventPlayerClickedOnFlag(Player *Source, GameObject* target_obj);
    virtual void EventPlayerUsedGO(Player* Source, GameObject* object);
    uint32 GetGateIDFromDestroyEventID(uint32 id)
        {
            uint32 i = 0;
            switch(id)
            {
                case 19046: i = BG_SA_GREEN_GATE;   break; //Green gate destroyed
                case 19045: i = BG_SA_BLUE_GATE;    break; //blue gate
                case 19047: i = BG_SA_RED_GATE;     break; //red gate
                case 19048: i = BG_SA_PURPLE_GATE;  break; //purple gate
                case 19049: i = BG_SA_YELLOW_GATE;  break; //yellow gate
                case 19837: i = BG_SA_ANCIENT_GATE; break; //ancient gate
            }
            return i;
        }
        uint32 GetWorldStateFromGateID(uint32 id)
        {
            uint32 uws = 0;
            switch(id)
            {
                case BG_SA_GREEN_GATE:   uws = BG_SA_GREEN_GATEWS;   break;
                case BG_SA_YELLOW_GATE:  uws = BG_SA_YELLOW_GATEWS;  break;
                case BG_SA_BLUE_GATE:    uws = BG_SA_BLUE_GATEWS;    break;
                case BG_SA_RED_GATE:     uws = BG_SA_RED_GATEWS;     break;
                case BG_SA_PURPLE_GATE:  uws = BG_SA_PURPLE_GATEWS;  break;
                case BG_SA_ANCIENT_GATE: uws = BG_SA_ANCIENT_GATEWS; break;
            }
            return uws;
        }
    void EndBattleground(uint32 winner);

        void RemovePlayer(Player *plr,uint64 guid);
        void HandleAreaTrigger(Player *Source, uint32 Trigger);


        /* Scorekeeping */
        void UpdatePlayerScore(Player *Source, uint32 type, uint32 value, bool doAddHonor = true);

    private:
    bool ResetObjs();
    void StartShips();
    void TeleportPlayers();
    void OverrideGunFaction();
    void DemolisherStartState(bool start);
    void DestroyGate(Player* pl, GameObject* /*go*/, uint32 destroyedEvent);
    void SendTime();
    void CaptureGraveyard(BG_SA_Graveyards i, Player *Source);
    void ToggleTimer();
    void UpdateDemolisherSpawns();
    TeamId attackers;
    uint32 TotalTime;
    uint32 BG_SA_ENDROUNDTIME;
    bool ShipsStarted;
    BG_SA_GateState GateStatus[6];
    BG_SA_Status status;
    TeamId GraveyardStatus[BG_SA_MAX_GY];
    BG_SA_RoundScore RoundScores[2];
    bool TimerEnabled;
    uint32 UpdateWaitTimer;//5secs before starting the 1min countdown for second round
    bool SignaledRoundTwo;
    bool SignaledRoundTwoHalfMin;
    bool InitSecondRound;
};
#endif
