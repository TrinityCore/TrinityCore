/*
* Copyright (C) 2011-2012 Project SkyFire <http://www.projectskyfire.org/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 3 of the License, or (at your
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

#ifndef BATTLEFIELD_TB_
#define BATTLEFIELD_TB_

#include "Battlefield.h"
#include "Group.h"
#include "ObjectMgr.h"
#include "WorldPacket.h"
#include "World.h"

const uint32 TBClockWorldState[2] = {5333, 5332};
const uint32 TolBaradFaction[3] = {2354, 2355, 35};

class BattlefieldTB;
class BfCapturePointTB;

struct BfTBGameObjectBuilding;
struct BfTBWorkShopData;

typedef std::set<GameObject*> TBGameObjectSet;
typedef std::set<BfTBGameObjectBuilding*> TBGameObjectBuilding;
typedef std::set<BfTBWorkShopData*> TBWorkShop;
typedef std::set<BfCapturePointTB*> TBCapturePointSet;
typedef std::set<Group*> TBGroupSet;

enum eTBpell
{
    SPELL_SPIRITUAL_IMMUNITY_TB                     = 95332,
    SPELL_ALLIANCE_FLAG_TB                          = 14268,
    SPELL_HORDE_FLAG_TB                             = 14267,

    // Reward spells
    SPELL_VICTORY_REWARD_ALLIANCE_TB                = 89789,
    SPELL_VICTORY_REWARD_HORDE_TB                   = 89791,
    SPELL_DEFEAT_REWARD_TB                          = 89793,
    SPELL_DAMAGED_TOWER_TB                          = 89795,
    SPELL_DESTROYED_TOWER_TB                        = 89796,
    SPELL_DEFENDED_TOWER_TB                         = 89794,

    SPELL_TOWER_BONUS                               = 82629,
    SPELL_VETERAN                                   = 84655,
    SPELL_SLOW_FALL_TB                              = 88473,

    SPELL_TOL_BARAD_VICTORY_ALLIANCE                = 89789,
    SPELL_TOL_BARAD_VICTORY_HORDE                   = 89791,
    SPELL_TOL_BARAD_DEFEAT                          = 89793,
    SPELL_TOL_BARAD_TOWER_DEFENDED                  = 89794,
    SPELL_TOL_BARAD_TOWER_DAMAGED                   = 89795,
    SPELL_TOL_BARAD_TOWER_DESTROYED                 = 89796,

    SPELL_TOL_BARAD_QUEST_ALLIANCE                  = 94665,
    SPELL_TOL_BARAD_QUEST_HORDE                     = 94763,
};

enum eTBData32
{
    BATTLEFIELD_TB_DATA_DAMAGED_TOWER_DEF,
    BATTLEFIELD_TB_DATA_BROKEN_TOWER_DEF,
    BATTLEFIELD_TB_DATA_DAMAGED_TOWER_ATT,
    BATTLEFIELD_TB_DATA_BROKEN_TOWER_ATT,
    BATTLEFIELD_TB_DATA_CAPTURED_FORT_DEF,
    BATTLEFIELD_TB_DATA_CAPTURED_FORT_ATT,
    BATTLEFIELD_TB_DATA_MAX,
};

/*#########################
*####### Graveyards ######*
#########################*/

class BfGraveYardTB: public BfGraveYard
{
public:
    BfGraveYardTB(BattlefieldTB* Bf);
    void SetTextId(uint32 textid){m_GossipTextId = textid;}
    uint32 GetTextId(){return m_GossipTextId;}
protected:
    uint32 m_GossipTextId;
};

enum eTBGraveyardId
{
    BATTLEFIELD_TB_GY_WARDENS_VIGIL,
    BATTLEFIELD_TB_GY_IRONGLAD,
    BATTLEFIELD_TB_GY_SLAGWORKS,
    BATTLEFIELD_TB_GY_WEST_SPIRE,
    BATTLEFIELD_TB_GY_SOUTH_SPIRE,
    BATTLEFIELD_TB_GY_EAST_SPIRE,
    BATTLEFIELD_TB_GY_KEEP,
    BATTLEFIELD_TB_GY_HORDE,
    BATTLEFIELD_TB_GY_ALLIANCE,
    BATTLEFIELD_TB_GY_MAX,
};

enum eTBGossipText
{
    BATTLEFIELD_TB_GOSSIPTEXT_GY_KEEP             = -1732000,
    BATTLEFIELD_TB_GOSSIPTEXT_GY_WARDENS_VIGIL    = -1732001,
    BATTLEFIELD_TB_GOSSIPTEXT_GY_IRONGLAD         = -1732002,
    BATTLEFIELD_TB_GOSSIPTEXT_GY_WEST_SPIRE       = -1732003,
    BATTLEFIELD_TB_GOSSIPTEXT_GY_SLAGWORKS        = -1732004,
    BATTLEFIELD_TB_GOSSIPTEXT_GY_SOUTH_SPIRE      = -1732005,
    BATTLEFIELD_TB_GOSSIPTEXT_GY_EAST_SPIRE       = -1732006,
    BATTLEFIELD_TB_GOSSIPTEXT_GY_HORDE            = -1732007,
    BATTLEFIELD_TB_GOSSIPTEXT_GY_ALLIANCE         = -1732008,
};

enum eTBFortType
{
    BATTLEFIELD_TB_FORT_WARDENS_VIGIL,
    BATTLEFIELD_TB_FORT_IRONGLAD,
    BATTLEFIELD_TB_FORT_SLAGWORKS,
    BATTLEFIELD_TB_FORT_MAX,
};

enum eTBNpc
{
    BATTLEFIELD_TB_NPC_GUARD_H   = 51166,
    BATTLEFIELD_TB_NPC_GUARD_A   = 51165,
    BATTLEFIELD_TB_NPC_HUNTER_A  = 47595,
    BATTLEFIELD_TB_NPC_MAGE_A    = 47598,
    BATTLEFIELD_TB_NPC_PALADIN_A = 47600,
    BATTLEFIELD_TB_NPC_DRUID_H   = 47607,
    BATTLEFIELD_TB_NPC_MAGE_H    = 47608,
    BATTLEFIELD_TB_NPC_ROGUE_H   = 47609,
    BATTLEFIELD_TB_NPC_SHAMAN_H  = 47610,
};

struct BfTBCoordGY
{
    float x;
    float y;
    float z;
    float o;
    uint32 guid;
    uint8 type;
    uint32 textid; // for gossip menu
    TeamId startcontrol;
};

const BfTBCoordGY TBGraveYard[BATTLEFIELD_TB_GY_MAX]=
{
    {-1244.58f, 981.233f, 155.425f, 0.733038f, 1789, BATTLEFIELD_TB_GY_KEEP,           BATTLEFIELD_TB_GOSSIPTEXT_GY_KEEP, TEAM_NEUTRAL},
    {-1572.14f, 1169.94f, 159.501f, 5.317802f, 1785, BATTLEFIELD_TB_GY_WARDENS_VIGIL,  BATTLEFIELD_TB_GOSSIPTEXT_GY_WARDENS_VIGIL, TEAM_NEUTRAL},
    {-970.465f, 1088.33f, 132.992f, 6.268125f, 1783, BATTLEFIELD_TB_GY_IRONGLAD,       BATTLEFIELD_TB_GOSSIPTEXT_GY_IRONGLAD, TEAM_NEUTRAL},
    {-1052.1f, 1490.65f, 191.407f, 0.008500f, 1784,  BATTLEFIELD_TB_GY_WEST_SPIRE,     BATTLEFIELD_TB_GOSSIPTEXT_GY_WEST_SPIRE, TEAM_NEUTRAL},
    {-1343.65f, 568.823f, 139.158f, 4.819249f, 1787, BATTLEFIELD_TB_GY_SLAGWORKS,      BATTLEFIELD_TB_GOSSIPTEXT_GY_SLAGWORKS, TEAM_NEUTRAL},
    {-1600.28f, 869.21f, 193.948f, 4.819249f, 1786,  BATTLEFIELD_TB_GY_SOUTH_SPIRE,    BATTLEFIELD_TB_GOSSIPTEXT_GY_SOUTH_SPIRE, TEAM_NEUTRAL},
    {-944.34f, 576.111f, 157.543f, 4.819249f, 1788,  BATTLEFIELD_TB_GY_EAST_SPIRE,     BATTLEFIELD_TB_GOSSIPTEXT_GY_EAST_SPIRE, TEAM_NEUTRAL},
    {-540.168f, 1331.29f, 22.8201f, 3.971623f, 1807, BATTLEFIELD_TB_GY_HORDE,          BATTLEFIELD_TB_GOSSIPTEXT_GY_HORDE, TEAM_HORDE},
    {-456.946f, 1168.55f, 15.7554f, 1.972220f, 1808, BATTLEFIELD_TB_GY_ALLIANCE,       BATTLEFIELD_TB_GOSSIPTEXT_GY_ALLIANCE, TEAM_ALLIANCE},
};

/*#########################
* BfCapturePointTB       *
#########################*/

class BfCapturePointTB: public BfCapturePoint
{
    public:
    BfCapturePointTB(BattlefieldTB* bf, TeamId control);
    void LinkToWorkShop(BfTBWorkShopData* ws) {m_WorkShop = ws;}

    void ChangeTeam(TeamId oldteam);
    TeamId GetTeam() const { return _team; }

protected:
    BfTBWorkShopData* m_WorkShop;
};

/*#########################
* TolBarad Battlefield    *
#########################*/

class BattlefieldTB: public Battlefield
{
    public:

    void OnBattleStart();
    void OnBattleEnd(bool endbytimer);
    void OnStartGrouping();
    void OnPlayerJoinWar(Player* player);
    void OnPlayerLeaveWar(Player* player);
    void OnPlayerLeaveZone(Player* player);
    void OnPlayerEnterZone(Player* player);
    bool Update(uint32 diff);
    void OnCreatureCreate(Creature* creature, bool add);
    void AddBrokenTower(TeamId team);
    void DoCompleteOrIncrementAchievement(uint32 achievement, Player* player, uint8 incrementNumber = 1);
    void AddPlayerToResurrectQueue(uint64 npc_guid, uint64 player_guid);
    bool SetupBattlefield();

    WorldPacket BuildInitWorldStates();
    void SendInitWorldStatesTo(Player* player);
    void SendInitWorldStatesToAll();

    void ProcessEvent(GameObject* obj, uint32 eventId);
protected:
    TBGameObjectBuilding BuildingsInZone;
    GuidSet KeepCreature[2];
    GuidSet WarCreature[2];
    TBWorkShop WorkShopList;
    TBGameObjectSet m_KeepGameObject[2];
    GuidSet m_vehicles[2];
    GuidSet m_PlayersIsSpellImu;  // Player is dead
    uint32 m_saveTimer;
};

enum eTBGameObjectBuildingType
{
    BATTLEFIELD_TB_OBJECTTYPE_TOWER,
};

enum eTBGameObjectState
{
    BATTLEFIELD_TB_OBJECTSTATE_NONE,
    BATTLEFIELD_TB_OBJECTSTATE_NEUTRAL_INTACT, // Not sure
    BATTLEFIELD_TB_OBJECTSTATE_NEUTRAL_DAMAGE, // Not sure
    BATTLEFIELD_TB_OBJECTSTATE_NEUTRAL_DESTROY, // Not sure
    BATTLEFIELD_TB_OBJECTSTATE_HORDE_INTACT,
    BATTLEFIELD_TB_OBJECTSTATE_HORDE_DAMAGE,
    BATTLEFIELD_TB_OBJECTSTATE_HORDE_DESTROY,
    BATTLEFIELD_TB_OBJECTSTATE_ALLIANCE_INTACT,
    BATTLEFIELD_TB_OBJECTSTATE_ALLIANCE_DAMAGE,
    BATTLEFIELD_TB_OBJECTSTATE_ALLIANCE_DESTROY,
};

enum eTBTeamControl
{
    BATTLEFIELD_TB_TEAM_ALLIANCE,
    BATTLEFIELD_TB_TEAM_HORDE,
    BATTLEFIELD_TB_TEAM_NEUTRAL,
};

enum eTBText
{
    BATTLEFIELD_TB_TEXT_FORT_TAKEN              = 12080,
    BATTLEFIELD_TB_TEXT_FORT_ATTACK             = 12081,
    BATTLEFIELD_TB_TEXT_WARDENS_VIGIL_NAME      = 12082,
    BATTLEFIELD_TB_TEXT_SLAGWORKS_NAME          = 12083,
    BATTLEFIELD_TB_TEXT_IRONCLAD_GARRISON_NAME  = 12084,
    BATTLEFIELD_TB_TEXT_HORDE                   = 12085,
    BATTLEFIELD_TB_TEXT_ALLIANCE                = 12086,
    BATTLEFIELD_TB_TEXT_WILL_START              = 12087,
    BATTLEFIELD_TB_TEXT_FIRSTRANK               = 12088,
    BATTLEFIELD_TB_TEXT_SECONDRANK              = 12089,
    BATTLEFIELD_TB_TEXT_TOWER_DAMAGE            = 12090,
    BATTLEFIELD_TB_TEXT_TOWER_DESTROY           = 12091,
    BATTLEFIELD_TB_TEXT_START                   = 12092,
    BATTLEFIELD_TB_TEXT_DEFEND_KEEP             = 12093,
    BATTLEFIELD_TB_TEXT_TOWER_NAME_SOUTH        = 12094,
    BATTLEFIELD_TB_TEXT_TOWER_NAME_EAST         = 12095,
    BATTLEFIELD_TB_TEXT_TOWER_NAME_WEST         = 12096,
    BATTLEFIELD_TB_TEXT_WIN_KEEP                = 12097,
};

enum eTBObject
{
    BATTLEFIELD_TB_GAMEOBJECT_CAPTURE_NORTH     = 190475,
    BATTLEFIELD_TB_GAMEOBJECT_CAPTURE_WEST      = 190487,
    BATTLEFIELD_TB_GAMEOBJECT_CAPTURE_EAST      = 194959,

    BATTLEFIELD_TB_GAMEOBJECT_BANNER_ALLY       = 207391,
    BATTLEFIELD_TB_GAMEOBJECT_BANNER_HORDE      = 207400,
};

struct BfTBObjectPosition
{
    float x;
    float y;
    float z;
    float o;
    uint32 entryh;
    uint32 entrya;
};

//*********************************************************
//************Destructible (Wall, Tower..)******************
//*********************************************************

struct BfTBBuildingSpawnData
{
    uint32 entry;
    uint32 WorldState;
    float x;
    float y;
    float z;
    float o;
    uint32 type;
    uint32 nameid;
};

#define TB_MAX_OBJ 3
const BfTBBuildingSpawnData TBGameObjectBuillding[TB_MAX_OBJ] =
{
    //South tower
    {204588, 5453, -950.41f, 1469.1f, 176.596f, -2.10312f,   BATTLEFIELD_TB_OBJECTTYPE_TOWER, BATTLEFIELD_TB_TEXT_TOWER_NAME_WEST},
    {204590, 3705, -1618.91f, 954.542f, 168.601f, 0.069812f, BATTLEFIELD_TB_OBJECTTYPE_TOWER, BATTLEFIELD_TB_TEXT_TOWER_NAME_SOUTH},
    {204589, 3706, -1013.28f, 529.538f, 146.427f, 1.97222f,  BATTLEFIELD_TB_OBJECTTYPE_TOWER, BATTLEFIELD_TB_TEXT_TOWER_NAME_EAST},
};

//*********************************************************
//**********Keep Element(GameObject, Creature)**************
//*********************************************************

#define TB_MAX_WAR_NPC 10
const BfTBObjectPosition TBWarNPC[TB_MAX_WAR_NPC] =
{
    // X        Y         Z         O          horde                       alliance
    {-817.969f,  1195.67f, 112.003f, 6.23603f,  BATTLEFIELD_TB_NPC_GUARD_A, BATTLEFIELD_TB_NPC_GUARD_H}, // Guard - bridge
    {-722.403f,  1193.26f, 103.641f, 6.25959f,  BATTLEFIELD_TB_NPC_GUARD_A, BATTLEFIELD_TB_NPC_GUARD_H}, // Guard - bridge
    {-722.751f, 1178.52f, 103.649f, 6.25959f,   BATTLEFIELD_TB_NPC_GUARD_A, BATTLEFIELD_TB_NPC_GUARD_H}, // Guard - bridge
    {-818.092f, 1180.13f, 111.991f, 6.2753f,    BATTLEFIELD_TB_NPC_GUARD_A, BATTLEFIELD_TB_NPC_GUARD_H}, // Guard - bridge
    {-1438.67f, 1140.87f, 123.549f, 4.57729f, 45344, 45344}, // Abandoned Siege Engine
    {-1442.58f, 1094.62f, 120.946f, 5.9321f, 45344, 45344}, // Abandoned Siege Engine
    {-1274.5f, 798.2f, 120.436f, 1.95014f, 45344, 45344},   // Abandoned Siege Engine
    {-1206.68f, 793.54f, 121.123f, 4.78543f, 45344, 45344}, // Abandoned Siege Engine
    {-1096.55f, 1086.82f, 124.975f, 2.88555f, 45344, 45344}, // Abandoned Siege Engine
    {-1109.07f, 1201.8f, 122.709f, 4.32284f, 45344, 45344}, // Abandoned Siege Engine
};

//Here there is all npc keeper spawn point
#define TB_MAX_KEEP_NPC 34
const BfTBObjectPosition TBKeepNPC[TB_MAX_KEEP_NPC] =
{ // TODO - separate some npcs - only bridge npcs should be visible when battle is on. Also need to add vehicles visible at battle start.
    // X        Y         Z         O          horde                       alliance
    {-1209.79f, 1000,     119.728f, 0.171371f, BATTLEFIELD_TB_NPC_GUARD_H, BATTLEFIELD_TB_NPC_GUARD_A}, // Guard
    {-1218.18f, 950.03f,  119.578f, 4.79658f,  BATTLEFIELD_TB_NPC_GUARD_H, BATTLEFIELD_TB_NPC_GUARD_A}, // Guard
    {-1251.04f, 948.433f, 119.698f, 4.68269f,  BATTLEFIELD_TB_NPC_GUARD_H, BATTLEFIELD_TB_NPC_GUARD_A}, // Guard
    {-1265.94f, 966.629f, 119.728f, 3.16924f,  BATTLEFIELD_TB_NPC_GUARD_H, BATTLEFIELD_TB_NPC_GUARD_A}, // Guard
    {-1266.78f, 996.851f, 119.586f, 3.16924f,  BATTLEFIELD_TB_NPC_GUARD_H, BATTLEFIELD_TB_NPC_GUARD_A}, // Guard
    {-1248.83f, 1012.51f, 119.728f, 1.60629f,  BATTLEFIELD_TB_NPC_GUARD_H, BATTLEFIELD_TB_NPC_GUARD_A}, // Guard
    {-1217.35f, 1013.63f, 119.728f, 1.60629f,  BATTLEFIELD_TB_NPC_GUARD_H, BATTLEFIELD_TB_NPC_GUARD_A}, // Guard
    {-1208.71f, 963.233f, 119.728f, 0.171371f, BATTLEFIELD_TB_NPC_GUARD_H, BATTLEFIELD_TB_NPC_GUARD_A}, // Guard
    {-1454.06f, 1270.45f, 133.584f, 0, BATTLEFIELD_TB_NPC_HUNTER_A, BATTLEFIELD_TB_NPC_DRUID_H},       // Trash
    {-1421.28f, 1304.17f, 133.584f, 0, BATTLEFIELD_TB_NPC_MAGE_A, BATTLEFIELD_TB_NPC_MAGE_H},          // Trash
    {-1443.37f, 1338.5f, 133.828f, 0,  BATTLEFIELD_TB_NPC_HUNTER_A, BATTLEFIELD_TB_NPC_MAGE_H},        // Trash
    {-1497.46f, 1386.06f, 133.591f, 0, BATTLEFIELD_TB_NPC_MAGE_A, BATTLEFIELD_TB_NPC_SHAMAN_H},        // Trash
    {-1545.21f, 1361.79f, 133.585f, 0, BATTLEFIELD_TB_NPC_HUNTER_A, BATTLEFIELD_TB_NPC_SHAMAN_H},      // Trash
    {-1570.75f, 1318.13f, 133.585f, 0, BATTLEFIELD_TB_NPC_MAGE_A, BATTLEFIELD_TB_NPC_ROGUE_H},         // Trash
    {-1536.95f, 1276.91f, 133.585f, 0, BATTLEFIELD_TB_NPC_PALADIN_A, BATTLEFIELD_TB_NPC_ROGUE_H},      // Trash
    {-1490.08f, 1238.24f, 133.584f, 0, BATTLEFIELD_TB_NPC_PALADIN_A, BATTLEFIELD_TB_NPC_SHAMAN_H},     // Trash
    {-1474.11f, 643.198f, 123.422f, 0, BATTLEFIELD_TB_NPC_PALADIN_A, BATTLEFIELD_TB_NPC_SHAMAN_H},     // Trash
    {-1414.45f, 711.19f, 123.422f, 0,  BATTLEFIELD_TB_NPC_PALADIN_A, BATTLEFIELD_TB_NPC_ROGUE_H},      // Trash
    {-1446.55f, 756.924f, 123.422f, 0, BATTLEFIELD_TB_NPC_MAGE_A, BATTLEFIELD_TB_NPC_ROGUE_H},         // Trash
    {-1518.74f, 680.033f, 123.422f, 0, BATTLEFIELD_TB_NPC_MAGE_A, BATTLEFIELD_TB_NPC_MAGE_H},   // Trash
    {-1474.18f, 721.503f, 123.423f, 0, BATTLEFIELD_TB_NPC_MAGE_A, BATTLEFIELD_TB_NPC_MAGE_H},   // Trash
    {-1440.74f, 592.324f, 123.422f, 0, BATTLEFIELD_TB_NPC_MAGE_A, BATTLEFIELD_TB_NPC_DRUID_H},  // Trash
    {-1365, 688.187f, 123.423f, 0,     BATTLEFIELD_TB_NPC_MAGE_A, BATTLEFIELD_TB_NPC_DRUID_H},  // Trash
    {-956.408f, 929.511f, 121.442f, 0, BATTLEFIELD_TB_NPC_MAGE_A, BATTLEFIELD_TB_NPC_DRUID_H},  // Trash
    {-954.937f, 978.588f, 121.441f, 0, BATTLEFIELD_TB_NPC_MAGE_A, BATTLEFIELD_TB_NPC_DRUID_H},  // Trash
    {-945.342f, 1026.22f, 121.441f, 0, BATTLEFIELD_TB_NPC_MAGE_A, BATTLEFIELD_TB_NPC_MAGE_H},   // Trash
    {-832.92f, 969.778f, 121.441f, 0,  BATTLEFIELD_TB_NPC_HUNTER_A, BATTLEFIELD_TB_NPC_MAGE_H}, // Trash
    {-881.724f, 1025.98f, 121.44f, 0,  BATTLEFIELD_TB_NPC_HUNTER_A, BATTLEFIELD_TB_NPC_ROGUE_H}, // Trash
    {-883.355f, 934.504f, 121.44f, 0,  BATTLEFIELD_TB_NPC_HUNTER_A, BATTLEFIELD_TB_NPC_ROGUE_H}, // Trash
    {-883.944f, 976.156f, 121.441f, 5.41424f,  BATTLEFIELD_TB_NPC_PALADIN_A, BATTLEFIELD_TB_NPC_SHAMAN_H}, // Trash
    {-834.767f, 924.951f, 121.441f, 0.782656f, BATTLEFIELD_TB_NPC_PALADIN_A, BATTLEFIELD_TB_NPC_SHAMAN_H}, // Trash
    {-837.744f, 1027.21f, 121.441f, 3.95564f,  BATTLEFIELD_TB_NPC_PALADIN_A, BATTLEFIELD_TB_NPC_SHAMAN_H}, // Trash
    {-1229.6f,  980.568f, 119.362f, 0.095962f, 48069, 48066}, // Commander Zanoth / Sergeant Parker
    {-1231.44f, 987.257f, 119.466f, 0.626106f, 48070, 48061}, // Drillmaster Razgoth / 2nd Lieutenant Wansworth
};

//*********************************************************
//*****************WorkShop Data & Element*****************
//*********************************************************

struct BfTBCapturePointDataBase
{
    uint32 entry;
    uint32 worldstate;
    uint32 type;
    uint32 nameid;
    BfTBObjectPosition CapturePoint;
    uint8 nbgob;
    BfTBObjectPosition GameObjectData[2];
};

// TODO Add flags.
#define TB_MAX_WORKSHOP  3
const BfTBCapturePointDataBase TBCapturePointDataBase[TB_MAX_WORKSHOP]=
{
    // Ironclad
    {192031, 5429, BATTLEFIELD_TB_FORT_IRONGLAD, BATTLEFIELD_TB_TEXT_IRONCLAD_GARRISON_NAME,
        {-877.823f, 980.493f, 121.441f, 3.05341f, BATTLEFIELD_TB_GAMEOBJECT_CAPTURE_NORTH, BATTLEFIELD_TB_GAMEOBJECT_CAPTURE_NORTH},
        2,
        //gameobject
        {
            {-989.841f, 964.901f, 121.564f, 2.88383f, BATTLEFIELD_TB_GAMEOBJECT_BANNER_HORDE, BATTLEFIELD_TB_GAMEOBJECT_BANNER_ALLY},
            {-989.134f, 993.65f, 121.674f, 3.40062f, BATTLEFIELD_TB_GAMEOBJECT_BANNER_HORDE, BATTLEFIELD_TB_GAMEOBJECT_BANNER_ALLY},
        }
    },

    // Warden's
    {192030, 5424, BATTLEFIELD_TB_FORT_WARDENS_VIGIL, BATTLEFIELD_TB_TEXT_WARDENS_VIGIL_NAME,
        {-1492.85f, 1310.62f, 152.962f, 5.4646f, BATTLEFIELD_TB_GAMEOBJECT_CAPTURE_WEST, BATTLEFIELD_TB_GAMEOBJECT_CAPTURE_WEST},
        2,
        //gameobject
        {
            {-1445.56f, 1236.89f, 133.822f, 5.92265f, BATTLEFIELD_TB_GAMEOBJECT_BANNER_HORDE, BATTLEFIELD_TB_GAMEOBJECT_BANNER_ALLY},
            {-1420.72f, 1262.17f, 133.659f, 5.35717f, BATTLEFIELD_TB_GAMEOBJECT_BANNER_HORDE, BATTLEFIELD_TB_GAMEOBJECT_BANNER_ALLY},
        }
    },
    // Slagworks
    {192033, 5429, BATTLEFIELD_TB_FORT_SLAGWORKS, BATTLEFIELD_TB_TEXT_SLAGWORKS_NAME,
        {-1438.86f, 685.013f, 123.422f, 0.795405f, BATTLEFIELD_TB_GAMEOBJECT_CAPTURE_EAST, BATTLEFIELD_TB_GAMEOBJECT_CAPTURE_EAST},
        2,
        //gameobject
        {
            {-1378.03f, 726.273f, 124.3f, 0.906316f, BATTLEFIELD_TB_GAMEOBJECT_BANNER_HORDE, BATTLEFIELD_TB_GAMEOBJECT_BANNER_ALLY},
            {-1402.82f, 747.984f, 123.332f, 0.252082f, BATTLEFIELD_TB_GAMEOBJECT_BANNER_HORDE, BATTLEFIELD_TB_GAMEOBJECT_BANNER_ALLY},
        }
    },
};

/********************************************************************
*                Structs using for Building, Graveyard, Workshop      *
********************************************************************/

// Structure for different building witch can be destroy during battle
struct BfTBGameObjectBuilding
{
    BfTBGameObjectBuilding(BattlefieldTB* TB)
    {
        m_TB = TB;
        m_Team = 0;
        m_Build = NULL;
        m_Type = 0;
        m_WorldState = 0;
        m_State = 0;
        m_NameId = 0;
    }
    // Team witch control this point
    uint8 m_Team;

    // TB object
    BattlefieldTB* m_TB;

    // Linked gameobject
    GameObject* m_Build;

    // eTBGameObjectBuildingType
    uint32 m_Type;

    // WorldState
    uint32 m_WorldState;

    // eTBGameObjectState
    uint32 m_State;

    // Name id for warning text
    uint32 m_NameId;

    // GameObject associate
    TBGameObjectSet m_GameObjectList[2];

    // Creature associate
    GuidSet m_CreatureBottomList[2];
    GuidSet m_CreatureTopList[2];
    GuidSet m_TurretBottomList;
    GuidSet m_TurretTopList;

    void Rebuild()
    {
        switch (m_Type)
        {
            case BATTLEFIELD_TB_OBJECTTYPE_TOWER:
                m_Team = m_TB->GetAttackerTeam(); // Tower in south are for attacker
                break;
            default:
                m_Team = TEAM_NEUTRAL;
                break;
        }

        // Rebuild gameobject
        m_Build->SetDestructibleState(GO_DESTRUCTIBLE_REBUILDING, NULL, true);
        // Updating worldstate
        m_State = BATTLEFIELD_TB_OBJECTSTATE_ALLIANCE_INTACT-(m_Team*3);
        m_TB->SendUpdateWorldState(m_WorldState, m_State);
        // UpdateCreatureAndGo();
        m_Build->SetUInt32Value(GAMEOBJECT_FACTION, TolBaradFaction[m_Team]);
    }

    // Called when associate gameobject is damaged
    void Damaged()
    {
        // Updating worldstate
        m_State = BATTLEFIELD_TB_OBJECTSTATE_ALLIANCE_DAMAGE-(m_Team*3);
        m_TB->SendUpdateWorldState(m_WorldState, m_State);
        // Send warning message
        if (m_NameId)
            m_TB->SendWarningToAllInZone(m_NameId);
    }

    // Called when associate gameobject is destroy
    void Destroyed()
    {
        // Updating worldstate
        m_State = BATTLEFIELD_TB_OBJECTSTATE_ALLIANCE_DESTROY-(m_Team*3);
        m_TB->SendUpdateWorldState(m_WorldState, m_State);
        // Warning
        if (m_NameId)
            m_TB->SendWarningToAllInZone(m_NameId);
        switch (m_Type)
        {
            // If destroy tower, inform TB script of it (using for reward calculation and event with south towers)
            case BATTLEFIELD_TB_OBJECTTYPE_TOWER:
                m_TB->AddBrokenTower(TeamId(m_Team));
                break;
        }
    }

    void Init(GameObject* go, uint32 type, uint32 worldstate, uint32 nameid)
    {
        // GameObject associate to object
        m_Build = go;
        // Type of building (WALL/TOWER/DOOR)
        m_Type = type;
        // WorldState for client (icon on map)
        m_WorldState = worldstate;
        // NameId for Warning text
        m_NameId = nameid;
        switch (m_Type)
        {
            case BATTLEFIELD_TB_OBJECTTYPE_TOWER:
                m_Team=m_TB->GetDefenderTeam();//Tower in south are for attacker
                break;
            default:
                m_Team=TEAM_NEUTRAL;
                break;
        }
        m_State=sWorld->getWorldState(m_WorldState);
        switch (m_State)
        {
            case BATTLEFIELD_TB_OBJECTSTATE_ALLIANCE_INTACT:
            case BATTLEFIELD_TB_OBJECTSTATE_HORDE_INTACT:
                if (m_Build)
                    m_Build->SetDestructibleState(GO_DESTRUCTIBLE_REBUILDING, NULL, true);
                break;
            case BATTLEFIELD_TB_OBJECTSTATE_ALLIANCE_DESTROY:
            case BATTLEFIELD_TB_OBJECTSTATE_HORDE_DESTROY:
                if (m_Build)
                {
                    m_Build->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED);
                    m_Build->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);
                    m_Build->SetUInt32Value(GAMEOBJECT_DISPLAYID, m_Build->GetGOInfo()->building.destroyedDisplayId);
                }
                break;
            case BATTLEFIELD_TB_OBJECTSTATE_ALLIANCE_DAMAGE:
            case BATTLEFIELD_TB_OBJECTSTATE_HORDE_DAMAGE:
                if (m_Build)
                {
                    m_Build->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED);
                    m_Build->SetUInt32Value(GAMEOBJECT_DISPLAYID, m_Build->GetGOInfo()->building.damagedDisplayId);
                }
                break;
        }

        int32 towerid = -1;
        switch (go->GetEntry())
        {
            case 204588:
                towerid = 4;
                break;
            case 204589:
                towerid = 5;
                break;
            case 204590:
                towerid = 6;
                break;
        }
    }

    void UpdateCreatureAndGo()
    {
        for (GuidSet::const_iterator itr = m_CreatureTopList[m_TB->GetDefenderTeam()].begin(); itr != m_CreatureTopList[m_TB->GetDefenderTeam()].end(); ++itr)
              if (Unit* unit = ObjectAccessor::FindUnit((*itr)))
                if (Creature* creature = unit->ToCreature())
                    m_TB->HideNpc(creature);

        for (GuidSet::const_iterator itr = m_CreatureTopList[m_TB->GetAttackerTeam()].begin(); itr != m_CreatureTopList[m_TB->GetAttackerTeam()].end(); ++itr)
            if (Unit* unit = ObjectAccessor::FindUnit((*itr)))
                if (Creature* creature = unit->ToCreature())
                    m_TB->ShowNpc(creature, true);

        for (GuidSet::const_iterator itr = m_CreatureBottomList[m_TB->GetDefenderTeam()].begin(); itr != m_CreatureBottomList[m_TB->GetDefenderTeam()].end(); ++itr)
            if (Unit* unit = ObjectAccessor::FindUnit((*itr)))
                if (Creature* creature = unit->ToCreature())
                    m_TB->HideNpc(creature);

        for (GuidSet::const_iterator itr = m_CreatureBottomList[m_TB->GetAttackerTeam()].begin(); itr != m_CreatureBottomList[m_TB->GetAttackerTeam()].end(); ++itr)
            if (Unit* unit = ObjectAccessor::FindUnit((*itr)))
                if (Creature* creature = unit->ToCreature())
                    m_TB->ShowNpc(creature, true);

        for (TBGameObjectSet::const_iterator itr = m_GameObjectList[m_TB->GetDefenderTeam()].begin(); itr != m_GameObjectList[m_TB->GetDefenderTeam()].end(); ++itr)
            (*itr)->SetRespawnTime(RESPAWN_ONE_DAY);

        for (TBGameObjectSet::const_iterator itr = m_GameObjectList[m_TB->GetAttackerTeam()].begin(); itr != m_GameObjectList[m_TB->GetAttackerTeam()].end(); ++itr)
            (*itr)->SetRespawnTime(RESPAWN_IMMEDIATELY);
    }

    void Save()
    {
        sWorld->setWorldState(m_WorldState, m_State);
    }
};

// Structure for the 6 workshop
struct BfTBWorkShopData
{
    BattlefieldTB* m_TB;                      // Object du joug
    GameObject* m_Build;
    uint32 m_Type;
    uint32 m_State;                           // For worldstate
    uint32 m_WorldState;
    uint32 m_TeamControl;                     // Team witch control the workshop
    GuidSet m_CreatureOnPoint[2];             // Contain all Creature associate to this point
    TBGameObjectSet m_GameObjectOnPoint[2];   // Contain all Gameobject associate to this point
    uint32 m_NameId;                          // Id of skyfire_string witch contain name of this node, using for alert message

    BfTBWorkShopData(BattlefieldTB* TB)
    {
        m_TB            = TB;
        m_Build         = NULL;
        m_Type          = 0;
        m_State         = 0;
        m_WorldState    = 0;
        m_TeamControl   = 0;
        m_NameId        = 0;
    }
    // Spawning associate creature and store them
    void AddCreature(BfTBObjectPosition obj)
    {
        if (Creature* creature = m_TB->SpawnCreature(obj.entryh, obj.x, obj.y, obj.z, obj.o, TEAM_HORDE))
            m_CreatureOnPoint[TEAM_HORDE].insert(creature->GetGUID());

        if (Creature* creature = m_TB->SpawnCreature(obj.entrya, obj.x, obj.y, obj.z, obj.o, TEAM_ALLIANCE))
            m_CreatureOnPoint[TEAM_ALLIANCE].insert(creature->GetGUID());
    }
    // Spawning Associate gameobject and store them
    void AddGameObject(BfTBObjectPosition obj)
    {
        if (GameObject* gameobject = m_TB->SpawnGameObject(obj.entryh, obj.x, obj.y, obj.z, obj.o))
            m_GameObjectOnPoint[TEAM_HORDE].insert(gameobject);

        if (GameObject* gameobject = m_TB->SpawnGameObject(obj.entrya, obj.x, obj.y, obj.z, obj.o))
            m_GameObjectOnPoint[TEAM_ALLIANCE].insert(gameobject);
    }

    // Init method, setup variable
    void Init(uint32 worldstate, uint32 type, uint32 nameid)
    {
        m_WorldState  = worldstate;
        m_Type        = type;
        m_NameId      = nameid;
    }

    // Called on change faction in CapturePoint class
    void ChangeControl(uint8 team, bool init /* for first call in setup*/)
    {
        switch (team)
        {
            case BATTLEFIELD_TB_TEAM_NEUTRAL:
            {
                // Send warning message to all player for inform a faction attack a workshop
                m_TB->SendWarningToAllInZone(m_NameId),
                    sObjectMgr->GetSkyFireStringForDBCLocale(m_TeamControl ? BATTLEFIELD_TB_TEXT_ALLIANCE : BATTLEFIELD_TB_TEXT_HORDE);
                break;
            }
            case BATTLEFIELD_TB_TEAM_ALLIANCE:
            {
                // Show Alliance gameobject
                for (TBGameObjectSet::const_iterator itr = m_GameObjectOnPoint[TEAM_ALLIANCE].begin(); itr != m_GameObjectOnPoint[TEAM_ALLIANCE].end(); ++itr)
                    (*itr)->SetRespawnTime(RESPAWN_IMMEDIATELY);

                // Hide Horde gameobject
                for (TBGameObjectSet::const_iterator itr = m_GameObjectOnPoint[TEAM_HORDE].begin(); itr != m_GameObjectOnPoint[TEAM_HORDE].end(); ++itr)
                    (*itr)->SetRespawnTime(RESPAWN_ONE_DAY);

                // Updating worldstate
                m_State = BATTLEFIELD_TB_OBJECTSTATE_ALLIANCE_INTACT;
                m_TB->SendUpdateWorldState(m_WorldState, m_State);

                // Warning message
                if (!init)
                    m_TB->SendWarningToAllInZone(m_NameId),
                    sObjectMgr->GetSkyFireStringForDBCLocale(BATTLEFIELD_TB_TEXT_ALLIANCE);

                // Found associate graveyard and update it
                if (m_Type < BATTLEFIELD_TB_FORT_MAX)
                    if (m_TB && m_TB->GetGraveYardById(m_Type))
                        m_TB->GetGraveYardById(m_Type)->ChangeControl(TEAM_ALLIANCE);

                m_TeamControl = team;
                break;
            }
            case BATTLEFIELD_TB_TEAM_HORDE:
            {
                // Hide Alliance gameobject
                for (TBGameObjectSet::const_iterator itr = m_GameObjectOnPoint[TEAM_ALLIANCE].begin(); itr != m_GameObjectOnPoint[TEAM_ALLIANCE].end(); ++itr)
                    (*itr)->SetRespawnTime(RESPAWN_ONE_DAY);

                // Show Horde gameobject
                for (TBGameObjectSet::const_iterator itr = m_GameObjectOnPoint[TEAM_HORDE].begin(); itr != m_GameObjectOnPoint[TEAM_HORDE].end(); ++itr)
                    (*itr)->SetRespawnTime(RESPAWN_IMMEDIATELY);

                // Update worlstate
                m_State = BATTLEFIELD_TB_OBJECTSTATE_HORDE_INTACT;
                m_TB->SendUpdateWorldState(m_WorldState, m_State);

                // Warning message
                if (!init)
                    m_TB->SendWarningToAllInZone(m_NameId),
                        sObjectMgr->GetSkyFireStringForDBCLocale(BATTLEFIELD_TB_TEXT_HORDE);

                // Update graveyard control
                if (m_Type < BATTLEFIELD_TB_FORT_MAX)
                    if (m_TB && m_TB->GetGraveYardById(m_Type))
                        m_TB->GetGraveYardById(m_Type)->ChangeControl(TEAM_HORDE);

                m_TeamControl = team;
                break;
            }
        }
    }

    void UpdateGraveYardAndWorkshop()
    {
        if (m_Type < BATTLEFIELD_TB_FORT_MAX)
            m_TB->GetGraveYardById(m_Type)->ChangeControl(TeamId(m_TeamControl));
        else
            ChangeControl(m_TB->GetDefenderTeam(), true);
    }
    void Save()
    {
        sWorld->setWorldState(m_WorldState, m_State);
    }
};

#endif
