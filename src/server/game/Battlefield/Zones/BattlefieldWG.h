/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "Battlefield.h"

class Group;
class BattlefieldWG;
class WintergraspCapturePoint;

struct BfWGGameObjectBuilding;
struct WintergraspWorkshop;
struct StaticWintergraspTowerInfo;
struct StaticWintergraspWorkshopInfo;
struct WintergraspObjectPositionData;

typedef std::vector<BfWGGameObjectBuilding*> GameObjectBuildingVect;
typedef std::vector<WintergraspWorkshop*> WorkshopVect;

// used in Player.cpp
extern uint32 const ClockWorldState[];

// used in zone_wintergrasp.cpp
TC_GAME_API extern uint32 const WintergraspFaction[];

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
    SPELL_WINTERGRASP_RESTRICTED_FLIGHT_AREA    = 91604,

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
    BATTLEFIELD_WG_DATA_WON_A,
    BATTLEFIELD_WG_DATA_DEF_A,
    BATTLEFIELD_WG_DATA_WON_H,
    BATTLEFIELD_WG_DATA_DEF_H,
    BATTLEFIELD_WG_DATA_MAX,

    BATTLEFIELD_WG_ZONEID                        = 4197,             // Wintergrasp
    BATTLEFIELD_WG_MAPID                         = 571               // Northrend
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
    BATTLEFIELD_WG_WORLD_STATE_SHOW_WORLDSTATE   = 3710,
    BATTLEFIELD_WG_WORLD_STATE_ATTACKED_H        = 4022,
    BATTLEFIELD_WG_WORLD_STATE_ATTACKED_A        = 4023,
    BATTLEFIELD_WG_WORLD_STATE_DEFENDED_H        = 4024,
    BATTLEFIELD_WG_WORLD_STATE_DEFENDED_A        = 4025
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

enum WintergraspQuests
{
    QUEST_VICTORY_WINTERGRASP_A   = 13181,
    QUEST_VICTORY_WINTERGRASP_H   = 13183,
    QUEST_CREDIT_TOWERS_DESTROYED = 35074,
    QUEST_CREDIT_DEFEND_SIEGE     = 31284
};

/*#########################
 *####### Graveyards ######
 *#########################*/

class BfGraveyardWG : public BfGraveyard
{
    public:
        BfGraveyardWG(BattlefieldWG* Bf);

        void SetTextId(uint32 textId) { m_GossipTextId = textId; }
        uint32 GetTextId() const { return m_GossipTextId; }

    protected:
        uint32 m_GossipTextId;
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

    NPC_TAUNKA_SPIRIT_GUIDE                         = 31841, // Horde spirit guide for Wintergrasp
    NPC_DWARVEN_SPIRIT_GUIDE                        = 31842, // Alliance spirit guide for Wintergrasp

    NPC_WINTERGRASP_SIEGE_ENGINE_ALLIANCE           = 28312,
    NPC_WINTERGRASP_SIEGE_ENGINE_HORDE              = 32627,
    NPC_WINTERGRASP_CATAPULT                        = 27881,
    NPC_WINTERGRASP_DEMOLISHER                      = 28094,
    NPC_WINTERGRASP_TOWER_CANNON                    = 28366
};

/* ######################### *
 *  WintergraspCapturePoint  *
 * ######################### */

class WintergraspCapturePoint : public BfCapturePoint
{
    public:
        WintergraspCapturePoint(BattlefieldWG* battlefield, TeamId teamInControl);

        void LinkToWorkshop(WintergraspWorkshop* workshop) { m_Workshop = workshop; }

        void ChangeTeam(TeamId oldteam) override;
        TeamId GetTeam() const { return m_team; }

    protected:
        WintergraspWorkshop* m_Workshop;
};

/* ######################### *
 * WinterGrasp Battlefield   *
 * ######################### */

class TC_GAME_API BattlefieldWG : public Battlefield
{
    public:
        ~BattlefieldWG();
        /**
         * \brief Called when the battle start
         * - Spawn relic and turret
         * - Rebuild tower and wall
         * - Invite player to war
         */
        void OnBattleStart() override;

        /**
         * \brief Called when battle end
         * - Remove relic and turret
         * - Change banner/npc in keep if it needed
         * - Saving battlestate
         * - Reward honor/mark to player
         * - Remove vehicle
         * \param endByTimer : true if battle ended when timer is at 00:00, false if battle ended by clicking on relic
         */
        void OnBattleEnd(bool endByTimer) override;

        /**
         * \brief Called when grouping starts (15 minutes before battlestart)
         * - Invite all player in zone to join queue
         */
        void OnStartGrouping() override;

        /**
         * \brief Called when player accept invite to join battle
         * - Update aura
         * - Teleport if it needed
         * - Update worldstate
         * - Update tenacity
         * \param player: Player who accepted invite
         */
        void OnPlayerJoinWar(Player* player) override;

        /**
         * \brief Called when player left the battle
         * - Update player aura
         * \param player : Player who left the battle
         */
        void OnPlayerLeaveWar(Player* player) override;

        /**
         * \brief Called when player left the WG zone
         * \param player : Player who left the zone
         */
        void OnPlayerLeaveZone(Player* player) override;

        /**
         * \brief Called when player enters in WG zone
         * - Update aura
         * - Update worldstate
         * \param player : Player who enters the zone
         */
        void OnPlayerEnterZone(Player* player) override;

        /**
         * \brief Called for update battlefield data
         * - Save battle timer in database every minutes
         * - Update imunity aura from graveyard
         * \param diff : time elapsed since the last call (in ms)
         */
        bool Update(uint32 diff) override;

        /**
         * \brief Called when a creature is created
         * - Update vehicle count
         */
        void OnCreatureCreate(Creature* creature) override;

        /**
         * \brief Called when a creature is removed
         * - Update vehicle count
         */
        void OnCreatureRemove(Creature* creature) override;

        /**
         * \brief Called when a gameobject is created
         */
        void OnGameObjectCreate(GameObject* go) override;

        /**
         * \brief Called when a wall/tower is broken
         * - Update quest
         */
        void BrokenWallOrTower(TeamId team, BfWGGameObjectBuilding* building);

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

        void DoCompleteOrIncrementAchievement(uint32 achievement, Player* player, uint8 incrementNumber = 1) override;

        void RemoveAurasFromPlayer(Player* player);

        /**
         * \brief Called when battlefield is setup, at server start
         */
        bool SetupBattlefield() override;

        /// Return pointer to relic object
        GameObject* GetRelic() { return GetGameObject(m_titansRelicGUID); }

        /// Define relic object
        void SetRelic(ObjectGuid relicGUID) { m_titansRelicGUID = relicGUID; }

        /// Check if players can interact with the relic (Only if the last door has been broken)
        bool CanInteractWithRelic() { return m_isRelicInteractible; }

        /// Define if player can interact with the relic
        void SetRelicInteractible(bool allow) { m_isRelicInteractible = allow; }

        void UpdateVehicleCountWG();
        void UpdateCounterVehicle(bool init);

        void SendInitWorldStatesTo(Player* player);
        void SendInitWorldStatesToAll() override;
        void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override;

        void HandleKill(Player* killer, Unit* victim) override;
        void OnUnitDeath(Unit* unit) override;
        void HandlePromotion(Player* killer, Unit* killed);
        void PromotePlayer(Player* killer);

        void UpdateTenacity();
        void ProcessEvent(WorldObject* obj, uint32 eventId) override;

        bool FindAndRemoveVehicleFromList(Unit* vehicle);

        // returns the graveyardId in the specified area.
        uint8 GetSpiritGraveyardId(uint32 areaId) const;

        uint32 GetData(uint32 data) const override;

    protected:
        bool m_isRelicInteractible;

        WorkshopVect Workshops;

        GuidVector DefenderPortalList[BG_TEAMS_COUNT];
        GameObjectBuildingVect BuildingsInZone;

        GuidUnorderedSet m_vehicles[BG_TEAMS_COUNT];
        GuidVector CanonList;

        TeamId m_tenacityTeam;
        uint32 m_tenacityStack;
        uint32 m_saveTimer;

        ObjectGuid m_titansRelicGUID;
};

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

enum WintergraspTowerIds
{
    BATTLEFIELD_WG_TOWER_FORTRESS_NW,
    BATTLEFIELD_WG_TOWER_FORTRESS_SW,
    BATTLEFIELD_WG_TOWER_FORTRESS_SE,
    BATTLEFIELD_WG_TOWER_FORTRESS_NE,
    BATTLEFIELD_WG_TOWER_SHADOWSIGHT,
    BATTLEFIELD_WG_TOWER_WINTER_S_EDGE,
    BATTLEFIELD_WG_TOWER_FLAMEWATCH
};

enum WintergraspWorkshopIds
{
    BATTLEFIELD_WG_WORKSHOP_SE,
    BATTLEFIELD_WG_WORKSHOP_SW,
    BATTLEFIELD_WG_WORKSHOP_NE,
    BATTLEFIELD_WG_WORKSHOP_NW,
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

enum WintergraspText
{
    // Invisible Stalker
    BATTLEFIELD_WG_TEXT_SOUTHERN_TOWER_DAMAGE           = 1,
    BATTLEFIELD_WG_TEXT_SOUTHERN_TOWER_DESTROY          = 2,
    BATTLEFIELD_WG_TEXT_EASTERN_TOWER_DAMAGE            = 3,
    BATTLEFIELD_WG_TEXT_EASTERN_TOWER_DESTROY           = 4,
    BATTLEFIELD_WG_TEXT_WESTERN_TOWER_DAMAGE            = 5,
    BATTLEFIELD_WG_TEXT_WESTERN_TOWER_DESTROY           = 6,
    BATTLEFIELD_WG_TEXT_NW_KEEPTOWER_DAMAGE             = 7,
    BATTLEFIELD_WG_TEXT_NW_KEEPTOWER_DESTROY            = 8,
    BATTLEFIELD_WG_TEXT_SE_KEEPTOWER_DAMAGE             = 9,
    BATTLEFIELD_WG_TEXT_SE_KEEPTOWER_DESTROY            = 10,
    BATTLEFIELD_WG_TEXT_BROKEN_TEMPLE_ATTACK_ALLIANCE   = 11,
    BATTLEFIELD_WG_TEXT_BROKEN_TEMPLE_CAPTURE_ALLIANCE  = 12,
    BATTLEFIELD_WG_TEXT_BROKEN_TEMPLE_ATTACK_HORDE      = 13,
    BATTLEFIELD_WG_TEXT_BROKEN_TEMPLE_CAPTURE_HORDE     = 14,
    BATTLEFIELD_WG_TEXT_EASTSPARK_ATTACK_ALLIANCE       = 15,
    BATTLEFIELD_WG_TEXT_EASTSPARK_CAPTURE_ALLIANCE      = 16,
    BATTLEFIELD_WG_TEXT_EASTSPARK_ATTACK_HORDE          = 17,
    BATTLEFIELD_WG_TEXT_EASTSPARK_CAPTURE_HORDE         = 18,
    BATTLEFIELD_WG_TEXT_SUNKEN_RING_ATTACK_ALLIANCE     = 19,
    BATTLEFIELD_WG_TEXT_SUNKEN_RING_CAPTURE_ALLIANCE    = 20,
    BATTLEFIELD_WG_TEXT_SUNKEN_RING_ATTACK_HORDE        = 21,
    BATTLEFIELD_WG_TEXT_SUNKEN_RING_CAPTURE_HORDE       = 22,
    BATTLEFIELD_WG_TEXT_WESTSPARK_ATTACK_ALLIANCE       = 23,
    BATTLEFIELD_WG_TEXT_WESTSPARK_CAPTURE_ALLIANCE      = 24,
    BATTLEFIELD_WG_TEXT_WESTSPARK_ATTACK_HORDE          = 25,
    BATTLEFIELD_WG_TEXT_WESTSPARK_CAPTURE_HORDE         = 26,

    BATTLEFIELD_WG_TEXT_START_GROUPING                  = 27,
    BATTLEFIELD_WG_TEXT_START_BATTLE                    = 28,
    BATTLEFIELD_WG_TEXT_FORTRESS_DEFEND_ALLIANCE        = 29,
    BATTLEFIELD_WG_TEXT_FORTRESS_CAPTURE_ALLIANCE       = 30,
    BATTLEFIELD_WG_TEXT_FORTRESS_DEFEND_HORDE           = 31,
    BATTLEFIELD_WG_TEXT_FORTRESS_CAPTURE_HORDE          = 32,

    BATTLEFIELD_WG_TEXT_NE_KEEPTOWER_DAMAGE             = 33,
    BATTLEFIELD_WG_TEXT_NE_KEEPTOWER_DESTROY            = 34,
    BATTLEFIELD_WG_TEXT_SW_KEEPTOWER_DAMAGE             = 35,
    BATTLEFIELD_WG_TEXT_SW_KEEPTOWER_DESTROY            = 36,

    BATTLEFIELD_WG_TEXT_RANK_CORPORAL                   = 37,
    BATTLEFIELD_WG_TEXT_RANK_FIRST_LIEUTENANT           = 38
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

// ********************************************************************
// *         Structs using for Building, Graveyard, Workshop          *
// ********************************************************************

// Structure for different buildings that can be destroyed during battle
struct TC_GAME_API BfWGGameObjectBuilding
{
private:
    // WG object
    BattlefieldWG* _wg;

    // Linked gameobject
    ObjectGuid _buildGUID;

    // the team that controls this point
    TeamId _teamControl;

    WintergraspGameObjectBuildingType _type;
    uint32 _worldState;

    WintergraspGameObjectState _state;

    StaticWintergraspTowerInfo const* _staticTowerInfo;

    // GameObject associations
    GuidVector m_GameObjectList[BG_TEAMS_COUNT];

    // Creature associations
    GuidVector m_CreatureBottomList[BG_TEAMS_COUNT];
    GuidVector m_CreatureTopList[BG_TEAMS_COUNT];
    GuidVector m_TowerCannonBottomList;
    GuidVector m_TurretTopList;

public:
    BfWGGameObjectBuilding(BattlefieldWG* wg, WintergraspGameObjectBuildingType type, uint32 worldState);
    void Init(GameObject* go);

    ObjectGuid const& GetGUID() const { return _buildGUID; }

    void Rebuild();

    // Called when associated gameobject is damaged
    void Damaged();

    // Called when associated gameobject is destroyed
    void Destroyed();

    void UpdateCreatureAndGo();

    void UpdateTurretAttack(bool disable);

    void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet);

    void Save();
};

// Structure for the 6 workshop
struct TC_GAME_API WintergraspWorkshop
{
private:
    BattlefieldWG* _wg;                             // Pointer to wintergrasp
    ObjectGuid _buildGUID;
    WintergraspGameObjectState _state;              // For worldstate
    TeamId _teamControl;                            // Team witch control the workshop

    StaticWintergraspWorkshopInfo const* _staticInfo;

public:
    WintergraspWorkshop(BattlefieldWG* wg, uint8 type);

    uint8 GetId() const;
    TeamId GetTeamControl() const { return _teamControl; }

    // Called on change faction in CapturePoint class
    void GiveControlTo(TeamId teamId, bool init = false);

    void UpdateGraveyardAndWorkshop();

    void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet);

    void Save();
};

#endif
