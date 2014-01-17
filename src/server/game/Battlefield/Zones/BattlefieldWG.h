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

#ifndef BATTLEFIELD_WG_
#define BATTLEFIELD_WG_

#include "ObjectAccessor.h"
#include "WorldPacket.h"
#include "Battlefield.h"
#include "World.h"

class Group;
class BattlefieldWG;
class WintergraspCapturePoint;

struct BfWGGameObjectBuilding;
struct WGWorkshop;

typedef std::set<GameObject*> GameObjectSet;
typedef std::set<BfWGGameObjectBuilding*> GameObjectBuilding;
typedef std::set<WGWorkshop*> Workshop;
typedef std::set<Group*> GroupSet;
//typedef std::set<WintergraspCapturePoint *> CapturePointSet; unused ?

enum WintergrastData
{
    BATTLEFIELD_WG_ZONEID                        = 4197,             // Wintergrasp
    BATTLEFIELD_WG_MAPID                         = 571               // Northrend
};

enum WintergraspSpells
{
    // Wartime auras
    SPELL_RECRUIT                               = 37795,
    SPELL_CORPORAL                              = 33280,
    SPELL_LIEUTENANT                            = 55629,
    SPELL_TENACITY                              = 58549,
    SPELL_TENACITY_VEHICLE                      = 59911,
    SPELL_TOWER_CONTROL                         = 62064,
    SPELL_SPIRITUAL_IMMUNITY                    = 58729,
    SPELL_GREAT_HONOR                           = 58555,
    SPELL_GREATER_HONOR                         = 58556,
    SPELL_GREATEST_HONOR                        = 58557,
    SPELL_ALLIANCE_FLAG                         = 14268,
    SPELL_HORDE_FLAG                            = 14267,
    SPELL_GRAB_PASSENGER                        = 61178,

    // Reward spells
    SPELL_VICTORY_REWARD                        = 56902,
    SPELL_DEFEAT_REWARD                         = 58494,
    SPELL_DAMAGED_TOWER                         = 59135,
    SPELL_DESTROYED_TOWER                       = 59136,
    SPELL_DAMAGED_BUILDING                      = 59201,
    SPELL_INTACT_BUILDING                       = 59203,

    SPELL_TELEPORT_BRIDGE                       = 59096,
    SPELL_TELEPORT_FORTRESS                     = 60035,

    SPELL_TELEPORT_DALARAN                      = 53360,
    SPELL_VICTORY_AURA                          = 60044,

    // Other spells
    SPELL_WINTERGRASP_WATER                     = 36444,
    SPELL_ESSENCE_OF_WINTERGRASP                = 58045,
    SPELL_WINTERGRASP_RESTRICTED_FLIGHT_AREA    = 58730,

    // Phasing spells
    SPELL_HORDE_CONTROLS_FACTORY_PHASE_SHIFT    = 56618, // ADDS PHASE 16
    SPELL_ALLIANCE_CONTROLS_FACTORY_PHASE_SHIFT = 56617, // ADDS PHASE 32

    SPELL_HORDE_CONTROL_PHASE_SHIFT             = 55773, // ADDS PHASE 64
    SPELL_ALLIANCE_CONTROL_PHASE_SHIFT          = 55774  // ADDS PHASE 128
};

enum WintergraspData
{
    BATTLEFIELD_WG_DATA_DAMAGED_TOWER_DEF,
    BATTLEFIELD_WG_DATA_BROKEN_TOWER_DEF,
    BATTLEFIELD_WG_DATA_DAMAGED_TOWER_ATT,
    BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT,
    BATTLEFIELD_WG_DATA_MAX_VEHICLE_A,
    BATTLEFIELD_WG_DATA_MAX_VEHICLE_H,
    BATTLEFIELD_WG_DATA_VEHICLE_A,
    BATTLEFIELD_WG_DATA_VEHICLE_H,
    BATTLEFIELD_WG_DATA_MAX
};

enum WintergraspAchievements
{
    ACHIEVEMENTS_WIN_WG                          = 1717,
    ACHIEVEMENTS_WIN_WG_100                      = 1718, /// @todo: Has to be implemented
    ACHIEVEMENTS_WG_GNOMESLAUGHTER               = 1723, /// @todo: Has to be implemented
    ACHIEVEMENTS_WG_TOWER_DESTROY                = 1727,
    ACHIEVEMENTS_DESTRUCTION_DERBY_A             = 1737, /// @todo: Has to be implemented
    ACHIEVEMENTS_WG_TOWER_CANNON_KILL            = 1751, /// @todo: Has to be implemented
    ACHIEVEMENTS_WG_MASTER_A                     = 1752, /// @todo: Has to be implemented
    ACHIEVEMENTS_WIN_WG_TIMER_10                 = 1755,
    ACHIEVEMENTS_STONE_KEEPER_50                 = 2085, /// @todo: Has to be implemented
    ACHIEVEMENTS_STONE_KEEPER_100                = 2086, /// @todo: Has to be implemented
    ACHIEVEMENTS_STONE_KEEPER_250                = 2087, /// @todo: Has to be implemented
    ACHIEVEMENTS_STONE_KEEPER_500                = 2088, /// @todo: Has to be implemented
    ACHIEVEMENTS_STONE_KEEPER_1000               = 2089, /// @todo: Has to be implemented
    ACHIEVEMENTS_WG_RANGER                       = 2199, /// @todo: Has to be implemented
    ACHIEVEMENTS_DESTRUCTION_DERBY_H             = 2476, /// @todo: Has to be implemented
    ACHIEVEMENTS_WG_MASTER_H                     = 2776  /// @todo: Has to be implemented
};

enum WintergraspWorldStates
{
    BATTLEFIELD_WG_WORLD_STATE_VEHICLE_H         = 3490,
    BATTLEFIELD_WG_WORLD_STATE_MAX_VEHICLE_H     = 3491,
    BATTLEFIELD_WG_WORLD_STATE_VEHICLE_A         = 3680,
    BATTLEFIELD_WG_WORLD_STATE_MAX_VEHICLE_A     = 3681,
    BATTLEFIELD_WG_WORLD_STATE_ACTIVE            = 3801,
    BATTLEFIELD_WG_WORLD_STATE_DEFENDER          = 3802,
    BATTLEFIELD_WG_WORLD_STATE_ATTACKER          = 3803,
    BATTLEFIELD_WG_WORLD_STATE_SHOW_WORLDSTATE   = 3710
};

enum WintergraspAreaIds
{
    AREA_WINTERGRASP_FORTRESS       = 4575,
    AREA_THE_SUNKEN_RING            = 4538,
    AREA_THE_BROKEN_TEMPLATE        = 4539,
    AREA_WESTPARK_WORKSHOP          = 4611,
    AREA_EASTPARK_WORKSHOP          = 4612,
    AREA_WINTERGRASP                = 4197,
    AREA_THE_CHILLED_QUAGMIRE       = 4589
};

/*#########################
 *####### Graveyards ######
 *#########################*/

class BfGraveyardWG : public BfGraveyard
{
    public:
        BfGraveyardWG(BattlefieldWG* Bf);

        void SetTextId(int32 textid) { m_GossipTextId = textid; }
        int32 GetTextId() { return m_GossipTextId; }
    protected:
        int32 m_GossipTextId;
};

enum WGGraveyardId
{
    BATTLEFIELD_WG_GY_WORKSHOP_NE,
    BATTLEFIELD_WG_GY_WORKSHOP_NW,
    BATTLEFIELD_WG_GY_WORKSHOP_SE,
    BATTLEFIELD_WG_GY_WORKSHOP_SW,
    BATTLEFIELD_WG_GY_KEEP,
    BATTLEFIELD_WG_GY_HORDE,
    BATTLEFIELD_WG_GY_ALLIANCE,
    BATTLEFIELD_WG_GRAVEYARD_MAX
};

enum WGGossipText
{
    BATTLEFIELD_WG_GOSSIPTEXT_GY_NE              = 20071,
    BATTLEFIELD_WG_GOSSIPTEXT_GY_NW              = 20072,
    BATTLEFIELD_WG_GOSSIPTEXT_GY_SE              = 20074,
    BATTLEFIELD_WG_GOSSIPTEXT_GY_SW              = 20073,
    BATTLEFIELD_WG_GOSSIPTEXT_GY_KEEP            = 20070,
    BATTLEFIELD_WG_GOSSIPTEXT_GY_HORDE           = 20075,
    BATTLEFIELD_WG_GOSSIPTEXT_GY_ALLIANCE        = 20076
};

enum WintergraspNpcs
{
    BATTLEFIELD_WG_NPC_GUARD_H                      = 30739,
    BATTLEFIELD_WG_NPC_GUARD_A                      = 30740,
    BATTLEFIELD_WG_NPC_STALKER                      = 15214,

    BATTLEFIELD_WG_NPC_VIERON_BLAZEFEATHER          = 31102,
    BATTLEFIELD_WG_NPC_STONE_GUARD_MUKAR            = 32296, // <WINTERGRASP QUARTERMASTER>
    BATTLEFIELD_WG_NPC_HOODOO_MASTER_FU_JIN         = 31101, // <MASTER HEXXER>
    BATTLEFIELD_WG_NPC_CHAMPION_ROS_SLAI            = 39173, // <WINTERGRASP QUARTERMASTER>
    BATTLEFIELD_WG_NPC_COMMANDER_DARDOSH            = 31091,
    BATTLEFIELD_WG_NPC_TACTICAL_OFFICER_KILRATH     = 31151,
    BATTLEFIELD_WG_NPC_SIEGESMITH_STRONGHOOF        = 31106,
    BATTLEFIELD_WG_NPC_PRIMALIST_MULFORT            = 31053,
    BATTLEFIELD_WG_NPC_LIEUTENANT_MURP              = 31107,

    BATTLEFIELD_WG_NPC_BOWYER_RANDOLPH              = 31052,
    BATTLEFIELD_WG_NPC_KNIGHT_DAMERON               = 32294, // <WINTERGRASP QUARTERMASTER>
    BATTLEFIELD_WG_NPC_SORCERESS_KAYLANA            = 31051, // <ENCHANTRESS>
    BATTLEFIELD_WG_NPC_MARSHAL_MAGRUDER             = 39172, // <WINTERGRASP QUARTERMASTER>
    BATTLEFIELD_WG_NPC_COMMANDER_ZANNETH            = 31036,
    BATTLEFIELD_WG_NPC_TACTICAL_OFFICER_AHBRAMIS    = 31153,
    BATTLEFIELD_WG_NPC_SIEGE_MASTER_STOUTHANDLE     = 31108,
    BATTLEFIELD_WG_NPC_ANCHORITE_TESSA              = 31054,
    BATTLEFIELD_WG_NPC_SENIOR_DEMOLITIONIST_LEGOSO  = 31109,

    NPC_TAUNKA_SPIRIT_GUIDE                         = 31841, // Horde spirit guide for Wintergrasp
    NPC_DWARVEN_SPIRIT_GUIDE                        = 31842, // Alliance spirit guide for Wintergrasp

    NPC_WINTERGRASP_SIEGE_ENGINE_ALLIANCE           = 28312,
    NPC_WINTERGRASP_SIEGE_ENGINE_HORDE              = 32627,
    NPC_WINTERGRASP_CATAPULT                        = 27881,
    NPC_WINTERGRASP_DEMOLISHER                      = 28094,
    NPC_WINTERGRASP_TOWER_CANNON                    = 28366
};

struct BfWGCoordGY
{
    float x;
    float y;
    float z;
    float o;
    uint32 gyid;
    uint8 type;
    int32 textid;              // for gossip menu
    TeamId startcontrol;
};

uint32 const WGQuest[2][6] =
{
    { 13186, 13181, 13222, 13538, 13177, 13179 },
    { 13185, 13183, 13223, 13539, 13178, 13180 },
};
// 7 in sql, 7 in header
BfWGCoordGY const WGGraveYard[BATTLEFIELD_WG_GRAVEYARD_MAX] =
{
    { 5104.750f, 2300.940f, 368.579f, 0.733038f, 1329, BATTLEFIELD_WG_GY_WORKSHOP_NE, BATTLEFIELD_WG_GOSSIPTEXT_GY_NE, TEAM_NEUTRAL },
    { 5099.120f, 3466.036f, 368.484f, 5.317802f, 1330, BATTLEFIELD_WG_GY_WORKSHOP_NW, BATTLEFIELD_WG_GOSSIPTEXT_GY_NW, TEAM_NEUTRAL },
    { 4314.648f, 2408.522f, 392.642f, 6.268125f, 1333, BATTLEFIELD_WG_GY_WORKSHOP_SE, BATTLEFIELD_WG_GOSSIPTEXT_GY_SE, TEAM_NEUTRAL },
    { 4331.716f, 3235.695f, 390.251f, 0.008500f, 1334, BATTLEFIELD_WG_GY_WORKSHOP_SW, BATTLEFIELD_WG_GOSSIPTEXT_GY_SW, TEAM_NEUTRAL },
    { 5537.986f, 2897.493f, 517.057f, 4.819249f, 1285, BATTLEFIELD_WG_GY_KEEP, BATTLEFIELD_WG_GOSSIPTEXT_GY_KEEP, TEAM_NEUTRAL },
    { 5032.454f, 3711.382f, 372.468f, 3.971623f, 1331, BATTLEFIELD_WG_GY_HORDE, BATTLEFIELD_WG_GOSSIPTEXT_GY_HORDE, TEAM_HORDE },
    { 5140.790f, 2179.120f, 390.950f, 1.972220f, 1332, BATTLEFIELD_WG_GY_ALLIANCE, BATTLEFIELD_WG_GOSSIPTEXT_GY_ALLIANCE, TEAM_ALLIANCE },
};

/* ######################### *
 *  WintergraspCapturePoint  *
 * ######################### */

class WintergraspCapturePoint : public BfCapturePoint
{
    public:
        WintergraspCapturePoint(BattlefieldWG* battlefield, TeamId teamInControl);

        void LinkToWorkshop(WGWorkshop* workshop) { m_Workshop = workshop; }

        void ChangeTeam(TeamId oldteam);
        TeamId GetTeam() const { return m_team; }

    protected:
        WGWorkshop* m_Workshop;
};

/* ######################### *
 * WinterGrasp Battlefield   *
 * ######################### */

class BattlefieldWG : public Battlefield
{
    public:
        ~BattlefieldWG();
        /**
         * \brief Called when the battle start
         * - Spawn relic and turret
         * - Rebuild tower and wall
         * - Invite player to war
         */
        void OnBattleStart();

        /**
         * \brief Called when battle end
         * - Remove relic and turret
         * - Change banner/npc in keep if it needed
         * - Saving battlestate
         * - Reward honor/mark to player
         * - Remove vehicle
         * \param endByTimer : true if battle ended when timer is at 00:00, false if battle ended by clicking on relic
         */
        void OnBattleEnd(bool endByTimer);

        /**
         * \brief Called when grouping starts (15 minutes before battlestart)
         * - Invite all player in zone to join queue
         */
        void OnStartGrouping();

        /**
         * \brief Called when player accept invite to join battle
         * - Update aura
         * - Teleport if it needed
         * - Update worldstate
         * - Update tenacity
         * \param player: Player who accepted invite
         */
        void OnPlayerJoinWar(Player* player);

        /**
         * \brief Called when player left the battle
         * - Update player aura
         * \param player : Player who left the battle
         */
        void OnPlayerLeaveWar(Player* player);

        /**
         * \brief Called when player left the WG zone
         * \param player : Player who left the zone
         */
        void OnPlayerLeaveZone(Player* player);

        /**
         * \brief Called when player enters in WG zone
         * - Update aura
         * - Update worldstate
         * \param player : Player who enters the zone
         */
        void OnPlayerEnterZone(Player* player);

        /**
         * \brief Called for update battlefield data
         * - Save battle timer in database every minutes
         * - Update imunity aura from graveyard
         * \param diff : time elapsed since the last call (in ms)
         */
        bool Update(uint32 diff);

        /**
         * \brief Called when a creature is created
         * - Update vehicle count
         */
        void OnCreatureCreate(Creature* creature);

        /**
         * \brief Called when a creature is removed
         * - Update vehicle count
         */
        void OnCreatureRemove(Creature* creature);

        /**
         * \brief Called when a gameobject is created
         */
        void OnGameObjectCreate(GameObject* go);

        /**
         * \brief Called when a wall/tower is broken
         * - Update quest
         */
        void BrokenWallOrTower(TeamId team);

        /**
         * \brief Called when a tower is damaged
         * - Update tower count (for reward calcul)
         */
        void UpdateDamagedTowerCount(TeamId team);

        /**
         * \brief Called when tower is broken
         * - Update tower buff
         * - check if three south tower is down for remove 10 minutes to wg
         */
        void UpdatedDestroyedTowerCount(TeamId team);

        void DoCompleteOrIncrementAchievement(uint32 achievement, Player* player, uint8 incrementNumber = 1);

        void RemoveAurasFromPlayer(Player* player);

        /**
         * \brief Called when battlefield is setup, at server start
         */
        bool SetupBattlefield();

        /// Return pointer to relic object
        GameObject* GetRelic() { return GetGameObject(m_titansRelicGUID); }

        /// Define relic object
        void SetRelic(uint64 relicGUID) { m_titansRelicGUID = relicGUID; }

        /// Check if players can interact with the relic (Only if the last door has been broken)
        bool CanInteractWithRelic() { return m_isRelicInteractible; }

        /// Define if player can interact with the relic
        void SetRelicInteractible(bool allow) { m_isRelicInteractible = allow; }

        void UpdateVehicleCountWG();
        void UpdateCounterVehicle(bool init);

        void SendInitWorldStatesTo(Player* player);
        void SendInitWorldStatesToAll();
        void FillInitialWorldStates(WorldPacket& data);

        void HandleKill(Player* killer, Unit* victim);
        void OnUnitDeath(Unit* unit);
        void PromotePlayer(Player* killer);

        void UpdateTenacity();
        void ProcessEvent(WorldObject* obj, uint32 eventId);

        bool FindAndRemoveVehicleFromList(Unit* vehicle);

        // returns the graveyardId in the specified area.
        uint8 GetSpiritGraveyardId(uint32 areaId) const;

        uint32 GetData(uint32 data) const;

    protected:
        bool m_isRelicInteractible;

        Workshop WorkshopsList;

        GuidSet DefenderPortalList;
        GuidSet m_KeepGameObject[2];
        GameObjectBuilding BuildingsInZone;

        GuidSet m_vehicles[2];
        GuidSet CanonList;
        GuidSet KeepCreature[2];
        GuidSet OutsideCreature[2];

        uint32 m_tenacityStack;
        uint32 m_saveTimer;

        uint64 m_titansRelicGUID;
};

uint32 const VehNumWorldState[]        = { 3680, 3490 };
uint32 const MaxVehNumWorldState[]     = { 3681, 3491 };
uint32 const ClockWorldState[]         = { 3781, 4354 };
uint32 const WintergraspFaction[]      = { 1732, 1735, 35 };
float const WintergraspStalkerPos[]    = { 4948.985f, 2937.789f, 550.5172f, 1.815142f };

uint8 const WG_MAX_OBJ              = 32;
uint8 const WG_MAX_TURRET           = 15;
uint8 const WG_MAX_KEEP_NPC         = 39;
uint8 const WG_MAX_OUTSIDE_NPC      = 14;
uint8 const WG_OUTSIDE_ALLIANCE_NPC = 7;
uint8 const WG_MAX_TELEPORTER       = 12;
uint8 const WG_MAX_WORKSHOP = 6;

enum WintergraspGameObjectBuildingType
{
    BATTLEFIELD_WG_OBJECTTYPE_DOOR,
    BATTLEFIELD_WG_OBJECTTYPE_TITANRELIC,
    BATTLEFIELD_WG_OBJECTTYPE_WALL,
    BATTLEFIELD_WG_OBJECTTYPE_DOOR_LAST,
    BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER,
    BATTLEFIELD_WG_OBJECTTYPE_TOWER
};

enum WintergraspGameObjectState
{
    BATTLEFIELD_WG_OBJECTSTATE_NONE,
    BATTLEFIELD_WG_OBJECTSTATE_NEUTRAL_INTACT,
    BATTLEFIELD_WG_OBJECTSTATE_NEUTRAL_DAMAGE,
    BATTLEFIELD_WG_OBJECTSTATE_NEUTRAL_DESTROY,
    BATTLEFIELD_WG_OBJECTSTATE_HORDE_INTACT,
    BATTLEFIELD_WG_OBJECTSTATE_HORDE_DAMAGE,
    BATTLEFIELD_WG_OBJECTSTATE_HORDE_DESTROY,
    BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_INTACT,
    BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_DAMAGE,
    BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_DESTROY
};

enum WintergraspWorkshopIds
{
    BATTLEFIELD_WG_WORKSHOP_NE,
    BATTLEFIELD_WG_WORKSHOP_NW,
    BATTLEFIELD_WG_WORKSHOP_SE,
    BATTLEFIELD_WG_WORKSHOP_SW,
    BATTLEFIELD_WG_WORKSHOP_KEEP_WEST,
    BATTLEFIELD_WG_WORKSHOP_KEEP_EAST
};

enum WintergraspWorldstates
{
    WORLDSTATE_WORKSHOP_NE      = 3701,
    WORLDSTATE_WORKSHOP_NW      = 3700,
    WORLDSTATE_WORKSHOP_SE      = 3703,
    WORLDSTATE_WORKSHOP_SW      = 3702,
    WORLDSTATE_WORKSHOP_K_W     = 3698,
    WORLDSTATE_WORKSHOP_K_E     = 3699
};

enum WintergraspTeamControl
{
    BATTLEFIELD_WG_TEAM_ALLIANCE,
    BATTLEFIELD_WG_TEAM_HORDE,
    BATTLEFIELD_WG_TEAM_NEUTRAL
};

/// @todo: Can this be handled with creature_text or SmartAI ?
enum WintergraspText
{
    BATTLEFIELD_WG_TEXT_WORKSHOP_NAME_NE         = 12055,
    BATTLEFIELD_WG_TEXT_WORKSHOP_NAME_NW         = 12052,
    BATTLEFIELD_WG_TEXT_WORKSHOP_NAME_SE         = 12053,
    BATTLEFIELD_WG_TEXT_WORKSHOP_NAME_SW         = 12054,
    BATTLEFIELD_WG_TEXT_WORKSHOP_ATTACK          = 12051,
    BATTLEFIELD_WG_TEXT_WORKSHOP_TAKEN           = 12050,
    BATTLEFIELD_WG_TEXT_ALLIANCE                 = 12057,
    BATTLEFIELD_WG_TEXT_HORDE                    = 12056,
    BATTLEFIELD_WG_TEXT_WILL_START               = 12058,
    BATTLEFIELD_WG_TEXT_START                    = 12067,
    BATTLEFIELD_WG_TEXT_FIRSTRANK                = 12059,
    BATTLEFIELD_WG_TEXT_SECONDRANK               = 12060,
    BATTLEFIELD_WG_TEXT_KEEPTOWER_NAME_NE        = 12062,
    BATTLEFIELD_WG_TEXT_KEEPTOWER_NAME_NW        = 12064,
    BATTLEFIELD_WG_TEXT_KEEPTOWER_NAME_SE        = 12061,
    BATTLEFIELD_WG_TEXT_KEEPTOWER_NAME_SW        = 12063,
    BATTLEFIELD_WG_TEXT_TOWER_DAMAGE             = 12065,
    BATTLEFIELD_WG_TEXT_TOWER_DESTROY            = 12066,
    BATTLEFIELD_WG_TEXT_TOWER_NAME_S             = 12069,
    BATTLEFIELD_WG_TEXT_TOWER_NAME_E             = 12070,
    BATTLEFIELD_WG_TEXT_TOWER_NAME_W             = 12071,
    BATTLEFIELD_WG_TEXT_DEFEND_KEEP              = 12068,
    BATTLEFIELD_WG_TEXT_WIN_KEEP                 = 12072
};

enum WintergraspGameObject
{
    GO_WINTERGRASP_FACTORY_BANNER_NE             = 190475,
    GO_WINTERGRASP_FACTORY_BANNER_NW             = 190487,
    GO_WINTERGRASP_FACTORY_BANNER_SE             = 194959,
    GO_WINTERGRASP_FACTORY_BANNER_SW             = 194962,

    GO_WINTERGRASP_TITAN_S_RELIC                 = 192829,

    GO_WINTERGRASP_FORTRESS_TOWER_1              = 190221,
    GO_WINTERGRASP_FORTRESS_TOWER_2              = 190373,
    GO_WINTERGRASP_FORTRESS_TOWER_3              = 190377,
    GO_WINTERGRASP_FORTRESS_TOWER_4              = 190378,

    GO_WINTERGRASP_SHADOWSIGHT_TOWER             = 190356,
    GO_WINTERGRASP_WINTER_S_EDGE_TOWER           = 190357,
    GO_WINTERGRASP_FLAMEWATCH_TOWER              = 190358,

    GO_WINTERGRASP_FORTRESS_GATE                 = 190375,
    GO_WINTERGRASP_VAULT_GATE                    = 191810,

    GO_WINTERGRASP_KEEP_COLLISION_WALL           = 194323
};

struct WintergraspObjectPositionData
{
    float x;
    float y;
    float z;
    float o;
    uint32 entryHorde;
    uint32 entryAlliance;
};

// *****************************************************
// ************ Destructible (Wall, Tower..) ***********
// *****************************************************

struct WintergraspBuildingSpawnData
{
    uint32 entry;
    uint32 WorldState;
    float x;
    float y;
    float z;
    float o;
    uint32 type;
    uint32 nameId;
};

struct WintergraspRebuildableBuildingData
{
    uint64 Guid;
    uint32 entry;
    uint32 WorldState;
    float x;
    float y;
    float z;
    float o;
    uint32 type;
    uint32 nameId;
};

const WintergraspBuildingSpawnData WGGameObjectBuilding[WG_MAX_OBJ] =
{
    // Wall (Not spawned in db)
    // Entry  WS    X        Y        Z        O         type                          NameID
    { 190219, 3749, 5371.46f, 3047.47f, 407.571f, 3.14159f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 190220, 3750, 5331.26f, 3047.1f, 407.923f, 0.052359f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 191795, 3764, 5385.84f, 2909.49f, 409.713f, 0.00872f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 191796, 3772, 5384.45f, 2771.84f, 410.27f, 3.14159f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 191799, 3762, 5371.44f, 2630.61f, 408.816f, 3.13286f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 191800, 3766, 5301.84f, 2909.09f, 409.866f, 0.008724f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 191801, 3770, 5301.06f, 2771.41f, 409.901f, 3.14159f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 191802, 3751, 5280.2f, 2995.58f, 408.825f, 1.61443f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 191803, 3752, 5279.14f, 2956.02f, 408.604f, 1.5708f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 191804, 3767, 5278.69f, 2882.51f, 409.539f, 1.5708f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 191806, 3769, 5279.5f, 2798.94f, 409.998f, 1.5708f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 191807, 3759, 5279.94f, 2724.77f, 409.945f, 1.56207f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 191808, 3760, 5279.6f, 2683.79f, 409.849f, 1.55334f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 191809, 3761, 5330.96f, 2630.78f, 409.283f, 3.13286f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 190369, 3753, 5256.08f, 2933.96f, 409.357f, 3.13286f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 190370, 3758, 5257.46f, 2747.33f, 409.743f, -3.13286f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 190371, 3754, 5214.96f, 2934.09f, 409.19f, -0.008724f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 190372, 3757, 5215.82f, 2747.57f, 409.188f, -3.13286f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 190374, 3755, 5162.27f, 2883.04f, 410.256f, 1.57952f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 190376, 3756, 5163.72f, 2799.84f, 409.227f, 1.57952f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },

    // Tower of keep (Not spawned in db)
    { 190221, 3711, 5281.15f, 3044.59f, 407.843f, 3.11539f, BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER, BATTLEFIELD_WG_TEXT_KEEPTOWER_NAME_NW },
    { 190373, 3713, 5163.76f, 2932.23f, 409.19f, 3.12412f, BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER, BATTLEFIELD_WG_TEXT_KEEPTOWER_NAME_SW },
    { 190377, 3714, 5166.4f, 2748.37f, 409.188f, -1.5708f, BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER, BATTLEFIELD_WG_TEXT_KEEPTOWER_NAME_SE },
    { 190378, 3712, 5281.19f, 2632.48f, 409.099f, -1.58825f, BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER, BATTLEFIELD_WG_TEXT_KEEPTOWER_NAME_NE },

    // Wall (with passage) (Not spawned in db)
    { 191797, 3765, 5343.29f, 2908.86f, 409.576f, 0.008724f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 191798, 3771, 5342.72f, 2771.39f, 409.625f, 3.14159f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },
    { 191805, 3768, 5279.13f, 2840.8f, 409.783f, 1.57952f, BATTLEFIELD_WG_OBJECTTYPE_WALL, 0 },

    // South tower (Not spawned in db)
    { 190356, 3704, 4557.17f, 3623.94f, 395.883f, 1.67552f, BATTLEFIELD_WG_OBJECTTYPE_TOWER, BATTLEFIELD_WG_TEXT_TOWER_NAME_W },
    { 190357, 3705, 4398.17f, 2822.5f, 405.627f, -3.12412f, BATTLEFIELD_WG_OBJECTTYPE_TOWER, BATTLEFIELD_WG_TEXT_TOWER_NAME_S },
    { 190358, 3706, 4459.1f, 1944.33f, 434.991f, -2.00276f, BATTLEFIELD_WG_OBJECTTYPE_TOWER, BATTLEFIELD_WG_TEXT_TOWER_NAME_E },

    // Door of forteress (Not spawned in db)
    { GO_WINTERGRASP_FORTRESS_GATE, 3763, 5162.99f, 2841.23f, 410.162f, -3.13286f, BATTLEFIELD_WG_OBJECTTYPE_DOOR, 0 },

    // Last door (Not spawned in db)
    { GO_WINTERGRASP_VAULT_GATE, 3773, 5397.11f, 2841.54f, 425.899f, 3.14159f, BATTLEFIELD_WG_OBJECTTYPE_DOOR_LAST, 0 },
};

const Position WGTurret[WG_MAX_TURRET] =
{
    { 5391.19f, 3060.8f,  419.616f, 1.69557f },
    { 5266.75f, 2976.5f,  421.067f, 3.20354f },
    { 5234.86f, 2948.8f,  420.88f,  1.61311f },
    { 5323.05f, 2923.7f,  421.645f, 1.5817f },
    { 5363.82f, 2923.87f, 421.709f, 1.60527f },
    { 5264.04f, 2861.34f, 421.587f, 3.21142f },
    { 5264.68f, 2819.78f, 421.656f, 3.15645f },
    { 5322.16f, 2756.69f, 421.646f, 4.69978f },
    { 5363.78f, 2756.77f, 421.629f, 4.78226f },
    { 5236.2f,  2732.68f, 421.649f, 4.72336f },
    { 5265.02f, 2704.63f, 421.7f,   3.12507f },
    { 5350.87f, 2616.03f, 421.243f, 4.72729f },
    { 5390.95f, 2615.5f,  421.126f, 4.6409f },
    { 5148.8f,  2820.24f, 421.621f, 3.16043f },
    { 5147.98f, 2861.93f, 421.63f,  3.18792f },
};

// Here there is all npc keeper spawn point
const WintergraspObjectPositionData WGKeepNPC[WG_MAX_KEEP_NPC] =
{
    // X          Y            Z           O         horde                          alliance
    // North East
    { 5326.203125f, 2660.026367f, 409.100891f, 2.543383f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Roaming Guard
    { 5298.430176f, 2738.760010f, 409.316010f, 3.971740f, BATTLEFIELD_WG_NPC_VIERON_BLAZEFEATHER, BATTLEFIELD_WG_NPC_BOWYER_RANDOLPH }, // Vieron Blazefeather
    { 5335.310059f, 2764.110107f, 409.274994f, 4.834560f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5349.810059f, 2763.629883f, 409.333008f, 4.660030f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    // North
    { 5373.470215f, 2789.060059f, 409.322998f, 2.600540f, BATTLEFIELD_WG_NPC_STONE_GUARD_MUKAR, BATTLEFIELD_WG_NPC_KNIGHT_DAMERON }, // Stone Guard Mukar
    { 5296.560059f, 2789.870117f, 409.274994f, 0.733038f, BATTLEFIELD_WG_NPC_HOODOO_MASTER_FU_JIN, BATTLEFIELD_WG_NPC_SORCERESS_KAYLANA }, // Voodoo Master Fu'jin
    { 5372.670000f, 2786.740000f, 409.442000f, 2.809980f, BATTLEFIELD_WG_NPC_CHAMPION_ROS_SLAI, BATTLEFIELD_WG_NPC_MARSHAL_MAGRUDER }, // Wintergrasp Quartermaster
    { 5368.709961f, 2856.360107f, 409.322998f, 2.949610f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5367.910156f, 2826.520020f, 409.322998f, 3.333580f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5389.270020f, 2847.370117f, 418.759003f, 3.106690f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5388.560059f, 2834.770020f, 418.759003f, 3.071780f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5359.129883f, 2837.989990f, 409.364014f, 4.698930f, BATTLEFIELD_WG_NPC_COMMANDER_DARDOSH, BATTLEFIELD_WG_NPC_COMMANDER_ZANNETH }, // Commander Dardosh
    { 5366.129883f, 2833.399902f, 409.322998f, 3.141590f, BATTLEFIELD_WG_NPC_TACTICAL_OFFICER_KILRATH, BATTLEFIELD_WG_NPC_TACTICAL_OFFICER_AHBRAMIS }, // Tactical Officer Kilrath
    // X          Y            Z           O         horde  alliance
    // North West
    { 5350.680176f, 2917.010010f, 409.274994f, 1.466080f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5335.120117f, 2916.800049f, 409.444000f, 1.500980f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5295.560059f, 2926.669922f, 409.274994f, 0.872665f, BATTLEFIELD_WG_NPC_SIEGESMITH_STRONGHOOF, BATTLEFIELD_WG_NPC_SIEGE_MASTER_STOUTHANDLE }, // Stronghoof
    { 5371.399902f, 3026.510010f, 409.205994f, 3.250030f, BATTLEFIELD_WG_NPC_PRIMALIST_MULFORT, BATTLEFIELD_WG_NPC_ANCHORITE_TESSA }, // Primalist Mulfort
    { 5392.123535f, 3031.110352f, 409.187683f, 3.677212f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Roaming Guard
    // South
    { 5270.060059f, 2847.550049f, 409.274994f, 3.071780f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5270.160156f, 2833.479980f, 409.274994f, 3.124140f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5179.109863f, 2837.129883f, 409.274994f, 3.211410f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5179.669922f, 2846.600098f, 409.274994f, 3.089230f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5234.970215f, 2883.399902f, 409.274994f, 4.293510f, BATTLEFIELD_WG_NPC_LIEUTENANT_MURP, BATTLEFIELD_WG_NPC_SENIOR_DEMOLITIONIST_LEGOSO }, // Lieutenant Murp
    // X          Y            Z           O         horde  alliance
    // Portal guards (from around the fortress)
    { 5319.209473f, 3055.947754f, 409.176636f, 1.020201f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5311.612305f, 3061.207275f, 408.734161f, 0.965223f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5264.713379f, 3017.283447f, 408.479706f, 3.482424f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5269.096191f, 3008.315918f, 408.826294f, 3.843706f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5201.414551f, 2945.096924f, 409.190735f, 0.945592f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5193.386230f, 2949.617188f, 409.190735f, 1.145859f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5148.116211f, 2904.761963f, 409.193756f, 3.368532f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5153.355957f, 2895.501465f, 409.199310f, 3.549174f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5154.353027f, 2787.349365f, 409.250183f, 2.555644f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5150.066406f, 2777.876953f, 409.343903f, 2.708797f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5193.706543f, 2732.882812f, 409.189514f, 4.845073f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5202.126953f, 2737.570557f, 409.189514f, 5.375215f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5269.181152f, 2671.174072f, 409.098999f, 2.457459f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5264.960938f, 2662.332520f, 409.098999f, 2.598828f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5307.111816f, 2616.006836f, 409.095734f, 5.355575f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },       // Standing Guard
    { 5316.770996f, 2619.430176f, 409.027740f, 5.363431f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A }        // Standing Guard
};

const WintergraspObjectPositionData WGOutsideNPC[WG_MAX_OUTSIDE_NPC] =
{
    { 5032.04f, 3681.79f, 362.980f, 4.210f, BATTLEFIELD_WG_NPC_VIERON_BLAZEFEATHER, 0 },
    { 5020.71f, 3626.19f, 360.150f, 4.640f, BATTLEFIELD_WG_NPC_HOODOO_MASTER_FU_JIN, 0 },
    { 4994.85f, 3660.51f, 359.150f, 2.260f, BATTLEFIELD_WG_NPC_COMMANDER_DARDOSH, 0 },
    { 5015.46f, 3677.11f, 362.970f, 6.009f, BATTLEFIELD_WG_NPC_TACTICAL_OFFICER_KILRATH, 0 },
    { 5031.12f, 3663.77f, 363.500f, 3.110f, BATTLEFIELD_WG_NPC_SIEGESMITH_STRONGHOOF, 0 },
    { 5042.74f, 3675.82f, 363.060f, 3.358f, BATTLEFIELD_WG_NPC_PRIMALIST_MULFORT, 0 },
    { 5014.45f, 3640.87f, 361.390f, 3.280f, BATTLEFIELD_WG_NPC_LIEUTENANT_MURP, 0 },
    { 5100.07f, 2168.89f, 365.779f, 1.972f, 0, BATTLEFIELD_WG_NPC_BOWYER_RANDOLPH },
    { 5081.70f, 2173.73f, 365.878f, 0.855f, 0, BATTLEFIELD_WG_NPC_SORCERESS_KAYLANA },
    { 5078.28f, 2183.70f, 365.029f, 1.466f, 0, BATTLEFIELD_WG_NPC_COMMANDER_ZANNETH },
    { 5088.49f, 2188.18f, 365.647f, 5.253f, 0, BATTLEFIELD_WG_NPC_TACTICAL_OFFICER_AHBRAMIS },
    { 5095.67f, 2193.28f, 365.924f, 4.939f, 0, BATTLEFIELD_WG_NPC_SIEGE_MASTER_STOUTHANDLE },
    { 5088.61f, 2167.66f, 365.689f, 0.680f, 0, BATTLEFIELD_WG_NPC_ANCHORITE_TESSA },
    { 5080.40f, 2199.00f, 359.489f, 2.967f, 0, BATTLEFIELD_WG_NPC_SENIOR_DEMOLITIONIST_LEGOSO },
};

struct WintergraspTeleporterData
{
    uint32 entry;
    float x;
    float y;
    float z;
    float o;
};

const WintergraspTeleporterData WGPortalDefenderData[WG_MAX_TELEPORTER] =
{
    // Player teleporter
    { 190763, 5153.41f, 2901.35f, 409.191f, -0.069f },
    { 190763, 5268.70f, 2666.42f, 409.099f, -0.715f },
    { 190763, 5197.05f, 2944.81f, 409.191f, 2.3387f },
    { 190763, 5196.67f, 2737.34f, 409.189f, -2.932f },
    { 190763, 5314.58f, 3055.85f, 408.862f, 0.5410f },
    { 190763, 5391.28f, 2828.09f, 418.675f, -2.164f },
    { 190763, 5153.93f, 2781.67f, 409.246f, 1.6580f },
    { 190763, 5311.44f, 2618.93f, 409.092f, -2.373f },
    { 190763, 5269.21f, 3013.84f, 408.828f, -1.762f },
    { 190763, 5401.62f, 2853.66f, 418.674f, 2.6354f },
    // Vehicle teleporter
    { 192951, 5314.51f, 2703.69f, 408.550f, -0.890f },
    { 192951, 5316.25f, 2977.04f, 408.539f, -0.820f },
};

// *********************************************************
// **********Tower Element(GameObject, Creature)************
// *********************************************************

struct WintergraspTowerData
{
    uint32 towerEntry;                  // Gameobject id of tower
    uint8 nbObject;                     // Number of gameobjects spawned on this point
    WintergraspObjectPositionData GameObject[6];   // Gameobject position and entry (Horde/Alliance)

    // Creature: Turrets and Guard /// @todo: Killed on Tower destruction ? Tower damage ? Requires confirming
    uint8 nbCreatureBottom;
    WintergraspObjectPositionData CreatureBottom[9];
    uint8 nbCreatureTop;
    WintergraspObjectPositionData CreatureTop[5];
};

uint8 const WG_MAX_ATTACKTOWERS = 3;
// 192414 : 0 in sql, 1 in header
// 192278 : 0 in sql, 3 in header
const WintergraspTowerData AttackTowers[WG_MAX_ATTACKTOWERS] =
{
    // West tower
    {
        190356,
        6,
        {
            { 4559.109863f, 3606.219971f, 419.998993f, -1.483530f, 192488, 192501 },    // Flag on tower
            { 4539.419922f, 3622.489990f, 420.033997f, -3.071770f, 192488, 192501 },    // Flag on tower
            { 4555.259766f, 3641.649902f, 419.973999f, 1.675510f, 192488, 192501 },     // Flag on tower
            { 4574.870117f, 3625.909912f, 420.079010f, 0.080117f, 192488, 192501 },     // Flag on tower
            { 4433.899902f, 3534.139893f, 360.274994f, -1.850050f, 192269, 192278 },    // Flag near workshop
            { 4572.930176f, 3475.520020f, 363.009003f, 1.42240f, 192269, 192278 }       // Flag near bridge
        },
        1,
        {
            { 4418.688477f, 3506.251709f, 358.975494f, 4.293305f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Roaming Guard
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
        },
        0,
        {
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
        }
    },

    // South Tower
    {
        190357,
        5,
        {
            { 4416.000000f, 2822.669922f, 429.851013f, -0.017452f, 192488, 192501 },    // Flag on tower
            { 4398.819824f, 2804.699951f, 429.791992f, -1.588250f, 192488, 192501 },    // Flag on tower
            { 4387.620117f, 2719.570068f, 389.934998f, -1.544620f, 192366, 192414 },    // Flag near tower
            { 4464.120117f, 2855.449951f, 406.110992f, 0.829032f, 192366, 192429 },     // Flag near tower
            { 4526.459961f, 2810.179932f, 391.200012f, -2.993220f, 192269, 192278 },    // Flag near bridge
            { 0, 0, 0, 0, 0, 0 },
        },
        6,
        {
            { 4452.859863f, 2808.870117f, 402.604004f, 6.056290f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Standing Guard
            { 4455.899902f, 2835.958008f, 401.122559f, 0.034907f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Standing Guard
            { 4412.649414f, 2953.792236f, 374.799957f, 0.980838f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Roaming Guard
            { 4362.089844f, 2811.510010f, 407.337006f, 3.193950f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Standing Guard
            { 4412.290039f, 2753.790039f, 401.015015f, 5.829400f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Standing Guard
            { 4421.939941f, 2773.189941f, 400.894989f, 5.707230f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Standing Guard
            { 0, 0, 0, 0, 0, 0},
            { 0, 0, 0, 0, 0, 0},
            { 0, 0, 0, 0, 0, 0},
        },
        0,
        {
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
        },
    },

    // East Tower
    {
        190358,
        4,
        {
            { 4466.790039f, 1960.420044f, 459.144012f, 1.151920f, 192488, 192501 },     // Flag on tower
            { 4475.350098f, 1937.030029f, 459.070007f, -0.43633f, 192488, 192501 },     // Flag on tower
            { 4451.759766f, 1928.099976f, 459.075989f, -2.00713f, 192488, 192501 },     // Flag on tower
            { 4442.990234f, 1951.900024f, 459.092987f, 2.740160f, 192488, 192501 },     // Flag on tower
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
        },
        5,
        {
            { 4501.060059f, 1990.280029f, 431.157013f, 1.029740f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Standing Guard
            { 4463.830078f, 2015.180054f, 430.299988f, 1.431170f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Standing Guard
            { 4494.580078f, 1943.760010f, 435.627014f, 6.195920f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Standing Guard
            { 4450.149902f, 1897.579956f, 435.045013f, 4.398230f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Standing Guard
            { 4428.870117f, 1906.869995f, 432.648010f, 3.996800f, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Standing Guard
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
        },
        0,
        {
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
        },
    },
};

struct WintergraspTowerCannonData
{
    uint32 towerEntry;
    uint8 nbTowerCannonBottom;
    Position TowerCannonBottom[5];
    uint8 nbTurretTop;
    Position TurretTop[5];
};

const uint8 WG_MAX_TOWER_CANNON = 7;

const WintergraspTowerCannonData TowerCannon[WG_MAX_TOWER_CANNON] =
{
    {
        190221,
        0,
        {
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
        2,
        {
            { 5255.88f, 3047.63f, 438.499f, 3.13677f },
            { 5280.9f, 3071.32f, 438.499f, 1.62879f },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
    },
    {
        190373,
        0,
        {
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
        2,
        {
            { 5138.59f, 2935.16f, 439.845f, 3.11723f },
            { 5163.06f, 2959.52f, 439.846f, 1.47258f },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
    },
    {
        190377,
        0,
        {
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
        2,
        {
            { 5163.84f, 2723.74f, 439.844f, 1.3994f },
            { 5139.69f, 2747.4f, 439.844f, 3.17221f },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
    },
    {
        190378,
        0,
        {
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
        2,
        {
            { 5278.21f, 2607.23f, 439.755f, 4.71944f },
            { 5255.01f, 2631.98f, 439.755f, 3.15257f },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
    },
    {
        190356,
        2,
        {
            {4537.380371f, 3599.531738f, 402.886993f, 3.998462f},
            {4581.497559f, 3604.087158f, 402.886963f, 5.651723f},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
        },
        2,
        {
            {4469.448242f, 1966.623779f, 465.647217f, 1.153573f},
            {4581.895996f, 3626.438477f, 426.539062f, 0.117806f},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
        },
    },
    {
        190357,
        2,
        {
            { 4421.640137f, 2799.935791f, 412.630920f, 5.459298f },
            { 4420.263184f, 2845.340332f, 412.630951f, 0.742197f },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
        3,
        {
            { 4423.430664f, 2822.762939f, 436.283142f, 6.223487f },
            { 4397.825684f, 2847.629639f, 436.283325f, 1.579430f },
            { 4398.814941f, 2797.266357f, 436.283051f, 4.703747f },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
    },
    {
        190358,
        2,
        {
            { 4448.138184f, 1974.998779f, 441.995911f, 1.967238f },
            { 4448.713379f, 1955.148682f, 441.995178f, 0.380733f },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
        2,
        {
            { 4469.448242f, 1966.623779f, 465.647217f, 1.153573f },
            { 4481.996582f, 1933.658325f, 465.647186f, 5.873029f },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
    },
};

// *********************************************************
// *****************WorkShop Data & Element*****************
// *********************************************************

struct WGWorkshopData
{
    uint8 id;
    uint32 worldstate;
    uint32 text;
};

const WGWorkshopData WorkshopsData[WG_MAX_WORKSHOP] =
{
    // NE
    {BATTLEFIELD_WG_WORKSHOP_NE, WORLDSTATE_WORKSHOP_NE, BATTLEFIELD_WG_TEXT_WORKSHOP_NAME_NE},
    // NW
    {BATTLEFIELD_WG_WORKSHOP_NW, WORLDSTATE_WORKSHOP_NW, BATTLEFIELD_WG_TEXT_WORKSHOP_NAME_NW},
    // SE
    {BATTLEFIELD_WG_WORKSHOP_SE, WORLDSTATE_WORKSHOP_SE, BATTLEFIELD_WG_TEXT_WORKSHOP_NAME_SE},
    // SW
    {BATTLEFIELD_WG_WORKSHOP_SW, WORLDSTATE_WORKSHOP_SW, BATTLEFIELD_WG_TEXT_WORKSHOP_NAME_SW},
    // KEEP WEST - It can't be taken, so it doesn't have a textid
    {BATTLEFIELD_WG_WORKSHOP_KEEP_WEST, WORLDSTATE_WORKSHOP_K_W, 0},
    // KEEP EAST - It can't be taken, so it doesn't have a textid
    {BATTLEFIELD_WG_WORKSHOP_KEEP_EAST, WORLDSTATE_WORKSHOP_K_E, 0}
};

// ********************************************************************
// *         Structs using for Building, Graveyard, Workshop          *
// ********************************************************************
// Structure for different buildings that can be destroyed during battle
struct BfWGGameObjectBuilding
{
    BfWGGameObjectBuilding(BattlefieldWG* WG)
    {
        m_WG = WG;
        m_Team = 0;
        m_BuildGUID = 0;
        m_Type = 0;
        m_WorldState = 0;
        m_State = 0;
        m_NameId = 0;
    }

    // the team that controls this point
    uint8 m_Team;

    // WG object
    BattlefieldWG* m_WG;

    // Linked gameobject
    uint64 m_BuildGUID;

    // eWGGameObjectBuildingType
    uint32 m_Type;

    // WorldState
    uint32 m_WorldState;

    // eWGGameObjectState
    uint32 m_State;

    // Name id for warning text
    uint32 m_NameId;

    // GameObject associations
    GuidSet m_GameObjectList[2];

    // Creature associations
    GuidSet m_CreatureBottomList[2];
    GuidSet m_CreatureTopList[2];
    GuidSet m_TowerCannonBottomList;
    GuidSet m_TurretTopList;

    void Rebuild()
    {
        switch (m_Type)
        {
            case BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER:
            case BATTLEFIELD_WG_OBJECTTYPE_DOOR_LAST:
            case BATTLEFIELD_WG_OBJECTTYPE_DOOR:
            case BATTLEFIELD_WG_OBJECTTYPE_WALL:
                m_Team = m_WG->GetDefenderTeam();           // Objects that are part of the keep should be the defender's
                break;
            case BATTLEFIELD_WG_OBJECTTYPE_TOWER:
                m_Team = m_WG->GetAttackerTeam();           // The towers in the south should be the attacker's
                break;
            default:
                m_Team = TEAM_NEUTRAL;
                break;
        }

        if (GameObject* build = m_WG->GetGameObject(m_BuildGUID))
        {
            // Rebuild gameobject
            if (build->IsDestructibleBuilding())
            {
                build->SetDestructibleState(GO_DESTRUCTIBLE_REBUILDING, NULL, true);
                if (build->GetEntry() == GO_WINTERGRASP_VAULT_GATE)
                    if (GameObject* go = build->FindNearestGameObject(GO_WINTERGRASP_KEEP_COLLISION_WALL, 50.0f))
                        go->SetGoState(GO_STATE_READY);

                // Update worldstate
                m_State = BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_INTACT - (m_Team * 3);
                m_WG->SendUpdateWorldState(m_WorldState, m_State);
            }
            UpdateCreatureAndGo();
            build->SetFaction(WintergraspFaction[m_Team]);
        }
    }

    // Called when associated gameobject is damaged
    void Damaged()
    {
        // Update worldstate
        m_State = BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_DAMAGE - (m_Team * 3);
        m_WG->SendUpdateWorldState(m_WorldState, m_State);

        // Send warning message
        if (m_NameId)                                       // tower damage + name
            m_WG->SendWarningToAllInZone(m_NameId);

        for (GuidSet::const_iterator itr = m_CreatureTopList[m_WG->GetAttackerTeam()].begin(); itr != m_CreatureTopList[m_WG->GetAttackerTeam()].end(); ++itr)
            if (Creature* creature = m_WG->GetCreature(*itr))
                m_WG->HideNpc(creature);

        for (GuidSet::const_iterator itr = m_TurretTopList.begin(); itr != m_TurretTopList.end(); ++itr)
            if (Creature* creature = m_WG->GetCreature(*itr))
                m_WG->HideNpc(creature);

        if (m_Type == BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER)
            m_WG->UpdateDamagedTowerCount(m_WG->GetDefenderTeam());
        else if (m_Type == BATTLEFIELD_WG_OBJECTTYPE_TOWER)
            m_WG->UpdateDamagedTowerCount(m_WG->GetAttackerTeam());
    }

    // Called when associated gameobject is destroyed
    void Destroyed()
    {
        // Update worldstate
        m_State = BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_DESTROY - (m_Team * 3);
        m_WG->SendUpdateWorldState(m_WorldState, m_State);

        // Warn players
        if (m_NameId)
            m_WG->SendWarningToAllInZone(m_NameId);

        switch (m_Type)
        {
            // Inform the global wintergrasp script of the destruction of this object
            case BATTLEFIELD_WG_OBJECTTYPE_TOWER:
            case BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER:
                m_WG->UpdatedDestroyedTowerCount(TeamId(m_Team));
                break;
            case BATTLEFIELD_WG_OBJECTTYPE_DOOR_LAST:
                if (GameObject* build = m_WG->GetGameObject(m_BuildGUID))
                    if (GameObject* go = build->FindNearestGameObject(GO_WINTERGRASP_KEEP_COLLISION_WALL, 50.0f))
                        go->SetGoState(GO_STATE_ACTIVE);
                m_WG->SetRelicInteractible(true);
                if (m_WG->GetRelic())
                    m_WG->GetRelic()->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                else
                    TC_LOG_ERROR("misc", "BattlefieldWG: Relic not found.");
                break;
        }

        m_WG->BrokenWallOrTower(TeamId(m_Team));
    }

    void Init(GameObject* go, uint32 type, uint32 worldstate, uint32 nameid)
    {
        if (!go)
            return;

        // GameObject associated to object
        m_BuildGUID = go->GetGUID();

        // Type of building (WALL/TOWER/DOOR)
        m_Type = type;

        // WorldState for client (icon on map)
        m_WorldState = worldstate;

        // NameId for Warning text
        m_NameId = nameid;

        switch (m_Type)
        {
            case BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER:
            case BATTLEFIELD_WG_OBJECTTYPE_DOOR_LAST:
            case BATTLEFIELD_WG_OBJECTTYPE_DOOR:
            case BATTLEFIELD_WG_OBJECTTYPE_WALL:
                m_Team = m_WG->GetDefenderTeam();           // Objects that are part of the keep should be the defender's
                break;
            case BATTLEFIELD_WG_OBJECTTYPE_TOWER:
                m_Team = m_WG->GetAttackerTeam();           // The towers in the south should be the attacker's
                break;
            default:
                m_Team = TEAM_NEUTRAL;
                break;
        }

        m_State = sWorld->getWorldState(m_WorldState);
        switch (m_State)
        {
            case BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_INTACT:
            case BATTLEFIELD_WG_OBJECTSTATE_HORDE_INTACT:
                go->SetDestructibleState(GO_DESTRUCTIBLE_REBUILDING, NULL, true);
                break;
            case BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_DESTROY:
            case BATTLEFIELD_WG_OBJECTSTATE_HORDE_DESTROY:
                go->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);
                break;
            case BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_DAMAGE:
            case BATTLEFIELD_WG_OBJECTSTATE_HORDE_DAMAGE:
                go->SetDestructibleState(GO_DESTRUCTIBLE_DAMAGED);
                break;
        }

        int32 towerid = -1;
        switch (go->GetEntry())
        {
            case GO_WINTERGRASP_FORTRESS_TOWER_1:
                towerid = 0;
                break;
            case GO_WINTERGRASP_FORTRESS_TOWER_2:
                towerid = 1;
                break;
            case GO_WINTERGRASP_FORTRESS_TOWER_3:
                towerid = 2;
                break;
            case GO_WINTERGRASP_FORTRESS_TOWER_4:
                towerid = 3;
                break;
            case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
                towerid = 4;
                break;
            case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
                towerid = 5;
                break;
            case GO_WINTERGRASP_FLAMEWATCH_TOWER:
                towerid = 6;
                break;
        }

        if (towerid > 3) // Attacker towers
        {
            // Spawn associate gameobjects
            for (uint8 i = 0; i < AttackTowers[towerid - 4].nbObject; i++)
            {
                WintergraspObjectPositionData gobData = AttackTowers[towerid - 4].GameObject[i];
                if (GameObject* go = m_WG->SpawnGameObject(gobData.entryHorde, gobData.x, gobData.y, gobData.z, gobData.o))
                    m_GameObjectList[TEAM_HORDE].insert(go->GetGUID());
                if (GameObject* go = m_WG->SpawnGameObject(gobData.entryAlliance, gobData.x, gobData.y, gobData.z, gobData.o))
                    m_GameObjectList[TEAM_ALLIANCE].insert(go->GetGUID());
            }

            // Spawn associate npc bottom
            for (uint8 i = 0; i < AttackTowers[towerid - 4].nbCreatureBottom; i++)
            {
                WintergraspObjectPositionData creatureData = AttackTowers[towerid - 4].CreatureBottom[i];
                if (Creature* creature = m_WG->SpawnCreature(creatureData.entryHorde, creatureData.x, creatureData.y, creatureData.z, creatureData.o, TEAM_HORDE))
                    m_CreatureBottomList[TEAM_HORDE].insert(creature->GetGUID());
                if (Creature* creature = m_WG->SpawnCreature(creatureData.entryAlliance, creatureData.x, creatureData.y, creatureData.z, creatureData.o, TEAM_ALLIANCE))
                    m_CreatureBottomList[TEAM_ALLIANCE].insert(creature->GetGUID());
            }

            // Spawn associate npc top
            for (uint8 i = 0; i < AttackTowers[towerid - 4].nbCreatureTop; i++)
            {
                WintergraspObjectPositionData creatureData = AttackTowers[towerid - 4].CreatureTop[i];
                if (Creature* creature = m_WG->SpawnCreature(creatureData.entryHorde, creatureData.x, creatureData.y, creatureData.z, creatureData.o, TEAM_HORDE))
                    m_CreatureTopList[TEAM_HORDE].insert(creature->GetGUID());
                if (Creature* creature = m_WG->SpawnCreature(creatureData.entryAlliance, creatureData.x, creatureData.y, creatureData.z, creatureData.o, TEAM_ALLIANCE))
                    m_CreatureTopList[TEAM_ALLIANCE].insert(creature->GetGUID());
            }
        }

        if (towerid >= 0)
        {
            // Spawn Turret bottom
            for (uint8 i = 0; i < TowerCannon[towerid].nbTowerCannonBottom; i++)
            {
                Position turretPos;
                TowerCannon[towerid].TowerCannonBottom[i].GetPosition(&turretPos);
                if (Creature* turret = m_WG->SpawnCreature(NPC_WINTERGRASP_TOWER_CANNON, turretPos, TEAM_ALLIANCE))
                {
                    m_TowerCannonBottomList.insert(turret->GetGUID());
                    switch (go->GetEntry())
                    {
                        case GO_WINTERGRASP_FORTRESS_TOWER_1:
                        case GO_WINTERGRASP_FORTRESS_TOWER_2:
                        case GO_WINTERGRASP_FORTRESS_TOWER_3:
                        case GO_WINTERGRASP_FORTRESS_TOWER_4:
                            turret->setFaction(WintergraspFaction[m_WG->GetDefenderTeam()]);
                            break;
                        case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
                        case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
                        case GO_WINTERGRASP_FLAMEWATCH_TOWER:
                            turret->setFaction(WintergraspFaction[m_WG->GetAttackerTeam()]);
                            break;
                    }
                    m_WG->HideNpc(turret);
                }
            }

            // Spawn Turret top
            for (uint8 i = 0; i < TowerCannon[towerid].nbTurretTop; i++)
            {
                Position towerCannonPos;
                TowerCannon[towerid].TurretTop[i].GetPosition(&towerCannonPos);
                if (Creature* turret = m_WG->SpawnCreature(NPC_WINTERGRASP_TOWER_CANNON, towerCannonPos, TeamId(0)))
                {
                    m_TurretTopList.insert(turret->GetGUID());
                    switch (go->GetEntry())
                    {
                        case GO_WINTERGRASP_FORTRESS_TOWER_1:
                        case GO_WINTERGRASP_FORTRESS_TOWER_2:
                        case GO_WINTERGRASP_FORTRESS_TOWER_3:
                        case GO_WINTERGRASP_FORTRESS_TOWER_4:
                            turret->setFaction(WintergraspFaction[m_WG->GetDefenderTeam()]);
                            break;
                        case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
                        case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
                        case GO_WINTERGRASP_FLAMEWATCH_TOWER:
                            turret->setFaction(WintergraspFaction[m_WG->GetAttackerTeam()]);
                            break;
                    }
                    m_WG->HideNpc(turret);
                }
            }
            UpdateCreatureAndGo();
        }
    }

    void UpdateCreatureAndGo()
    {
        for (GuidSet::const_iterator itr = m_CreatureTopList[m_WG->GetDefenderTeam()].begin(); itr != m_CreatureTopList[m_WG->GetDefenderTeam()].end(); ++itr)
            if (Creature* creature = m_WG->GetCreature(*itr))
                m_WG->HideNpc(creature);

        for (GuidSet::const_iterator itr = m_CreatureTopList[m_WG->GetAttackerTeam()].begin(); itr != m_CreatureTopList[m_WG->GetAttackerTeam()].end(); ++itr)
            if (Creature* creature = m_WG->GetCreature(*itr))
                m_WG->ShowNpc(creature, true);

        for (GuidSet::const_iterator itr = m_CreatureBottomList[m_WG->GetDefenderTeam()].begin(); itr != m_CreatureBottomList[m_WG->GetDefenderTeam()].end(); ++itr)
            if (Creature* creature = m_WG->GetCreature(*itr))
                m_WG->HideNpc(creature);

        for (GuidSet::const_iterator itr = m_CreatureBottomList[m_WG->GetAttackerTeam()].begin(); itr != m_CreatureBottomList[m_WG->GetAttackerTeam()].end(); ++itr)
            if (Creature* creature = m_WG->GetCreature(*itr))
                m_WG->ShowNpc(creature, true);

        for (GuidSet::const_iterator itr = m_GameObjectList[m_WG->GetDefenderTeam()].begin(); itr != m_GameObjectList[m_WG->GetDefenderTeam()].end(); ++itr)
            if (GameObject* object = m_WG->GetGameObject(*itr))
                object->SetRespawnTime(RESPAWN_ONE_DAY);

        for (GuidSet::const_iterator itr = m_GameObjectList[m_WG->GetAttackerTeam()].begin(); itr != m_GameObjectList[m_WG->GetAttackerTeam()].end(); ++itr)
            if (GameObject* object = m_WG->GetGameObject(*itr))
                object->SetRespawnTime(RESPAWN_IMMEDIATELY);
    }

    void UpdateTurretAttack(bool disable)
    {
        for (GuidSet::const_iterator itr = m_TowerCannonBottomList.begin(); itr != m_TowerCannonBottomList.end(); ++itr)
        {
            if (Creature* creature = m_WG->GetCreature(*itr))
            {
                if (GameObject* build = m_WG->GetGameObject(m_BuildGUID))
                {
                    if (disable)
                        m_WG->HideNpc(creature);
                    else
                        m_WG->ShowNpc(creature, true);

                    switch (build->GetEntry())
                    {
                        case GO_WINTERGRASP_FORTRESS_TOWER_1:
                        case GO_WINTERGRASP_FORTRESS_TOWER_2:
                        case GO_WINTERGRASP_FORTRESS_TOWER_3:
                        case GO_WINTERGRASP_FORTRESS_TOWER_4:
                        {
                            creature->setFaction(WintergraspFaction[m_WG->GetDefenderTeam()]);
                            break;
                        }
                        case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
                        case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
                        case GO_WINTERGRASP_FLAMEWATCH_TOWER:
                        {
                            creature->setFaction(WintergraspFaction[m_WG->GetAttackerTeam()]);
                            break;
                        }
                    }
                }
            }
        }

        for (GuidSet::const_iterator itr = m_TurretTopList.begin(); itr != m_TurretTopList.end(); ++itr)
        {
            if (Creature* creature = m_WG->GetCreature(*itr))
            {
                if (GameObject* build = m_WG->GetGameObject(m_BuildGUID))
                {
                    if (disable)
                        m_WG->HideNpc(creature);
                    else
                        m_WG->ShowNpc(creature, true);

                    switch (build->GetEntry())
                    {
                        case GO_WINTERGRASP_FORTRESS_TOWER_1:
                        case GO_WINTERGRASP_FORTRESS_TOWER_2:
                        case GO_WINTERGRASP_FORTRESS_TOWER_3:
                        case GO_WINTERGRASP_FORTRESS_TOWER_4:
                        {
                            creature->setFaction(WintergraspFaction[m_WG->GetDefenderTeam()]);
                            break;
                        }
                        case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
                        case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
                        case GO_WINTERGRASP_FLAMEWATCH_TOWER:
                        {
                            creature->setFaction(WintergraspFaction[m_WG->GetAttackerTeam()]);
                            break;
                        }
                    }
                }
            }
        }
    }

    void Save()
    {
        sWorld->setWorldState(m_WorldState, m_State);
    }
};

struct WGWorkshop
{
    // pointer to the battlefield that the workshop belongs to
    BattlefieldWG* bf;
    // id of the workshop, useful to retrieve data of the WorkshopsData array
    uint8 workshopId;
    // team that controls the node
    uint8 teamControl;
    // for worldstate
    uint32 state;

    WGWorkshop(BattlefieldWG* _bf, uint8 _workshopId)
    {
        ASSERT(_bf || _workshopId < WG_MAX_WORKSHOP);

        bf = _bf;
        workshopId = _workshopId;
        teamControl = BATTLEFIELD_WG_TEAM_NEUTRAL;
        state = BATTLEFIELD_WG_OBJECTSTATE_NONE;
    }

    void GiveControlTo(uint8 team, bool init /* for first call in setup*/)
    {
        switch (team)
        {
            case BATTLEFIELD_WG_TEAM_NEUTRAL:
            {
                // Send warning message to all player to inform a faction attack to a workshop
                // alliance / horde attacking a workshop
                bf->SendWarningToAllInZone(teamControl ? WorkshopsData[workshopId].text : WorkshopsData[workshopId].text + 1);
                break;
            }
            case BATTLEFIELD_WG_TEAM_ALLIANCE:
            case BATTLEFIELD_WG_TEAM_HORDE:
            {
                // Updating worldstate
                state = team == BATTLEFIELD_WG_TEAM_ALLIANCE ? BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_INTACT : BATTLEFIELD_WG_OBJECTSTATE_HORDE_INTACT;
                bf->SendUpdateWorldState(WorkshopsData[workshopId].worldstate, state);

                // Warning message
                if (!init)                              // workshop taken - alliance
                    bf->SendWarningToAllInZone(team == BATTLEFIELD_WG_TEAM_ALLIANCE ? WorkshopsData[workshopId].text : WorkshopsData[workshopId].text+1);

                // Found associate graveyard and update it
                if (workshopId < BATTLEFIELD_WG_WORKSHOP_KEEP_WEST)
                    if (bf->GetGraveyardById(workshopId))
                        bf->GetGraveyardById(workshopId)->GiveControlTo(team == BATTLEFIELD_WG_TEAM_ALLIANCE ? TEAM_ALLIANCE : TEAM_HORDE);

                teamControl = team;
                break;
            }
        }

        if (!init)
            bf->UpdateCounterVehicle(false);
    }

    void UpdateGraveyardAndWorkshop()
    {
        if (workshopId < BATTLEFIELD_WG_WORKSHOP_KEEP_WEST)
            bf->GetGraveyardById(workshopId)->GiveControlTo(TeamId(teamControl));
        else
            GiveControlTo(bf->GetDefenderTeam(), true);
    }

    void Save()
    {
        sWorld->setWorldState(WorkshopsData[workshopId].worldstate, state);
    }
};

// Structure for the 6 workshop
struct WintergraspWorkshopData
{
    BattlefieldWG* m_WG;                                    // Pointer to wintergrasp
    uint64 m_BuildGUID;
    uint32 m_Type;
    uint32 m_State;                                         // For worldstate
    uint32 m_WorldState;
    uint32 m_TeamControl;                                   // Team witch control the workshop
    GuidSet m_CreatureOnPoint[2];                           // Contain all Creature associate to this point
    GuidSet m_GameObjectOnPoint[2];                     // Contain all Gameobject associate to this point
    uint32 m_NameId;                                        // Id of trinity_string witch contain name of this node, using for alert message

    WintergraspWorkshopData(BattlefieldWG* WG)
    {
        m_WG = WG;
        m_BuildGUID = 0;
        m_Type = 0;
        m_State = 0;
        m_WorldState = 0;
        m_TeamControl = 0;
        m_NameId = 0;
    }

    // Spawning associate creature and store them
    void AddCreature(const WintergraspObjectPositionData& obj)
    {
        if (Creature* creature = m_WG->SpawnCreature(obj.entryHorde, obj.x, obj.y, obj.z, obj.o, TEAM_HORDE))
            m_CreatureOnPoint[TEAM_HORDE].insert(creature->GetGUID());

        if (Creature* creature = m_WG->SpawnCreature(obj.entryAlliance, obj.x, obj.y, obj.z, obj.o, TEAM_ALLIANCE))
            m_CreatureOnPoint[TEAM_ALLIANCE].insert(creature->GetGUID());
    }

    // Spawning Associate gameobject and store them
    void AddGameObject(const WintergraspObjectPositionData& obj)
    {
        if (GameObject* gameobject = m_WG->SpawnGameObject(obj.entryHorde, obj.x, obj.y, obj.z, obj.o))
            m_GameObjectOnPoint[TEAM_HORDE].insert(gameobject->GetGUID());
        if (GameObject* gameobject = m_WG->SpawnGameObject(obj.entryAlliance, obj.x, obj.y, obj.z, obj.o))
            m_GameObjectOnPoint[TEAM_ALLIANCE].insert(gameobject->GetGUID());
    }

    // Init method, setup variable
    void Init(uint32 worldstate, uint32 type, uint32 nameid)
    {
        m_WorldState = worldstate;
        m_Type = type;
        m_NameId = nameid;
    }

    // Called on change faction in CapturePoint class
    void GiveControlTo(uint8 team, bool init /* for first call in setup*/)
    {
        switch (team)
        {
            case BATTLEFIELD_WG_TEAM_NEUTRAL:
            {
                // Send warning message to all player for inform a faction attack a workshop
                // alliance / horde attacking workshop
                m_WG->SendWarningToAllInZone(m_TeamControl ? m_NameId : m_NameId + 1);
                break;
            }
            case BATTLEFIELD_WG_TEAM_ALLIANCE:
            {
                // Show Alliance creature
                for (GuidSet::const_iterator itr = m_CreatureOnPoint[TEAM_ALLIANCE].begin(); itr != m_CreatureOnPoint[TEAM_ALLIANCE].end(); ++itr)
                    if (Creature* creature = m_WG->GetCreature(*itr))
                        m_WG->ShowNpc(creature, creature->GetEntry() != 30499);

                // Hide Horde creature
                for (GuidSet::const_iterator itr = m_CreatureOnPoint[TEAM_HORDE].begin(); itr != m_CreatureOnPoint[TEAM_HORDE].end(); ++itr)
                    if (Creature* creature = m_WG->GetCreature(*itr))
                        m_WG->HideNpc(creature);

                // Show Alliance gameobject
                for (GuidSet::const_iterator itr = m_GameObjectOnPoint[TEAM_ALLIANCE].begin(); itr != m_GameObjectOnPoint[TEAM_ALLIANCE].end(); ++itr)
                    if (GameObject* object = m_WG->GetGameObject(*itr))
                        object->SetRespawnTime(RESPAWN_IMMEDIATELY);

                // Hide Horde gameobject
                for (GuidSet::const_iterator itr = m_GameObjectOnPoint[TEAM_HORDE].begin(); itr != m_GameObjectOnPoint[TEAM_HORDE].end(); ++itr)
                    if (GameObject* object = m_WG->GetGameObject(*itr))
                        object->SetRespawnTime(RESPAWN_ONE_DAY);


                // Updating worldstate
                m_State = BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_INTACT;
                m_WG->SendUpdateWorldState(m_WorldState, m_State);

                // Warning message
                if (!init)                              // workshop taken - alliance
                    m_WG->SendWarningToAllInZone(m_NameId);

                // Found associate graveyard and update it
                if (m_Type < BATTLEFIELD_WG_WORKSHOP_KEEP_WEST)
                    if (m_WG->GetGraveyardById(m_Type))
                        m_WG->GetGraveyardById(m_Type)->GiveControlTo(TEAM_ALLIANCE);

                m_TeamControl = team;
                break;
            }
            case BATTLEFIELD_WG_TEAM_HORDE:
            {
                // Show Horde creature
                for (GuidSet::const_iterator itr = m_CreatureOnPoint[TEAM_HORDE].begin(); itr != m_CreatureOnPoint[TEAM_HORDE].end(); ++itr)
                    if (Creature* creature = m_WG->GetCreature(*itr))
                        m_WG->ShowNpc(creature, creature->GetEntry() != 30400);

                // Hide Alliance creature
                for (GuidSet::const_iterator itr = m_CreatureOnPoint[TEAM_ALLIANCE].begin(); itr != m_CreatureOnPoint[TEAM_ALLIANCE].end(); ++itr)
                    if (Creature* creature = m_WG->GetCreature(*itr))
                        m_WG->HideNpc(creature);

                // Hide Alliance gameobject
                for (GuidSet::const_iterator itr = m_GameObjectOnPoint[TEAM_ALLIANCE].begin(); itr != m_GameObjectOnPoint[TEAM_ALLIANCE].end(); ++itr)
                    if (GameObject* object = m_WG->GetGameObject(*itr))
                        object->SetRespawnTime(RESPAWN_ONE_DAY);

                // Show Horde gameobject
                for (GuidSet::const_iterator itr = m_GameObjectOnPoint[TEAM_HORDE].begin(); itr != m_GameObjectOnPoint[TEAM_HORDE].end(); ++itr)
                    if (GameObject* object = m_WG->GetGameObject(*itr))
                        object->SetRespawnTime(RESPAWN_IMMEDIATELY);

                // Update worlstate
                m_State = BATTLEFIELD_WG_OBJECTSTATE_HORDE_INTACT;
                m_WG->SendUpdateWorldState(m_WorldState, m_State);

                // Warning message
                if (!init)                              // workshop taken - horde
                    m_WG->SendWarningToAllInZone(m_NameId + 1);

                // Update graveyard control
                if (m_Type < BATTLEFIELD_WG_WORKSHOP_KEEP_WEST)
                    if (m_WG->GetGraveyardById(m_Type))
                        m_WG->GetGraveyardById(m_Type)->GiveControlTo(TEAM_HORDE);

                m_TeamControl = team;
                break;
            }
        }
        if (!init)
            m_WG->UpdateCounterVehicle(false);
    }

    void UpdateGraveyardAndWorkshop()
    {
        if (m_Type < BATTLEFIELD_WG_WORKSHOP_KEEP_WEST)
            m_WG->GetGraveyardById(m_Type)->GiveControlTo(TeamId(m_TeamControl));
        else
            GiveControlTo(m_WG->GetDefenderTeam(), true);
    }

    void Save()
    {
        sWorld->setWorldState(m_WorldState, m_State);
    }
};

#endif
