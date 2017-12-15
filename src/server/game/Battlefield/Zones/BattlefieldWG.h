/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "GameObjectData.h"

class WintergraspCapturePoint;
class WintergraspBuilding;
class WintergraspWorkshop;

typedef std::unordered_set<WintergraspBuilding*> BuildingSet;
typedef std::unordered_set<WintergraspWorkshop*> WorkshopSet;

// used in Player.cpp
extern uint32 const ClockWorldState[];

// used in zone_wintergrasp.cpp
TC_GAME_API extern uint32 const WintergraspFaction[];

enum WintergraspSpells
{
    // Wartime auras
    SPELL_RECRUIT                                   = 37795,
    SPELL_CORPORAL                                  = 33280,
    SPELL_LIEUTENANT                                = 55629,
    SPELL_TENACITY                                  = 58549,
    SPELL_TENACITY_VEHICLE                          = 59911,
    SPELL_TOWER_CONTROL                             = 62064,
    SPELL_SPIRITUAL_IMMUNITY                        = 58729,
    SPELL_GREAT_HONOR                               = 58555,
    SPELL_GREATER_HONOR                             = 58556,
    SPELL_GREATEST_HONOR                            = 58557,
    SPELL_ALLIANCE_FLAG                             = 14268,
    SPELL_HORDE_FLAG                                = 14267,
    SPELL_GRAB_PASSENGER                            = 61178,

    // Reward spells
    SPELL_VICTORY_REWARD                            = 56902,
    SPELL_DEFEAT_REWARD                             = 58494,
    SPELL_DAMAGED_TOWER                             = 59135,
    SPELL_DESTROYED_TOWER                           = 59136,
    SPELL_DAMAGED_BUILDING                          = 59201,
    SPELL_INTACT_BUILDING                           = 59203,

    SPELL_TELEPORT_BRIDGE                           = 59096,
    SPELL_TELEPORT_FORTRESS                         = 60035,

    SPELL_TELEPORT_DALARAN                          = 53360,
    SPELL_VICTORY_AURA                              = 60044,

    // Other spells
    SPELL_WINTERGRASP_WATER                         = 36444,
    SPELL_ESSENCE_OF_WINTERGRASP                    = 58045,
    SPELL_WINTERGRASP_RESTRICTED_FLIGHT_AREA        = 58730,

    // Phasing spells
    SPELL_HORDE_CONTROLS_FACTORY_PHASE_SHIFT        = 56618, // ADDS PHASE 16
    SPELL_ALLIANCE_CONTROLS_FACTORY_PHASE_SHIFT     = 56617, // ADDS PHASE 32

    SPELL_HORDE_CONTROL_PHASE_SHIFT                 = 55773, // ADDS PHASE 64
    SPELL_ALLIANCE_CONTROL_PHASE_SHIFT              = 55774  // ADDS PHASE 128
};

enum WintergraspMiscData
{
    ZONEID_WINTERGRASP                              = 4197, // Wintergrasp
    MAPID_WINTERGRASP                               = 571   // Northrend
};

enum WintergraspAchievements
{
    ACHIEVEMENTS_WIN_WG                             = 1717,
    ACHIEVEMENTS_WIN_WG_100                         = 1718, /// @todo: Has to be implemented
    ACHIEVEMENTS_WG_GNOMESLAUGHTER                  = 1723, /// @todo: Has to be implemented
    ACHIEVEMENTS_WG_TOWER_DESTROY                   = 1727,
    ACHIEVEMENTS_DESTRUCTION_DERBY_A                = 1737, /// @todo: Has to be implemented
    ACHIEVEMENTS_WG_TOWER_CANNON_KILL               = 1751, /// @todo: Has to be implemented
    ACHIEVEMENTS_WG_MASTER_A                        = 1752, /// @todo: Has to be implemented
    ACHIEVEMENTS_WIN_WG_TIMER_10                    = 1755,
    ACHIEVEMENTS_STONE_KEEPER_50                    = 2085, /// @todo: Has to be implemented
    ACHIEVEMENTS_STONE_KEEPER_100                   = 2086, /// @todo: Has to be implemented
    ACHIEVEMENTS_STONE_KEEPER_250                   = 2087, /// @todo: Has to be implemented
    ACHIEVEMENTS_STONE_KEEPER_500                   = 2088, /// @todo: Has to be implemented
    ACHIEVEMENTS_STONE_KEEPER_1000                  = 2089, /// @todo: Has to be implemented
    ACHIEVEMENTS_WG_RANGER                          = 2199, /// @todo: Has to be implemented
    ACHIEVEMENTS_DESTRUCTION_DERBY_H                = 2476, /// @todo: Has to be implemented
    ACHIEVEMENTS_WG_MASTER_H                        = 2776  /// @todo: Has to be implemented
};

enum WintergraspAreaIds
{
    AREA_WINTERGRASP_FORTRESS                       = 4575,
    AREA_THE_SUNKEN_RING                            = 4538,
    AREA_THE_BROKEN_TEMPLE                          = 4539,
    AREA_WESTPARK_WORKSHOP                          = 4611,
    AREA_EASTPARK_WORKSHOP                          = 4612,
    AREA_WINTERGRASP                                = 4197,
    AREA_THE_CHILLED_QUAGMIRE                       = 4589
};

enum WintergraspBuildingType
{
    OBJECTTYPE_DOOR,
    OBJECTTYPE_TITANRELIC,
    OBJECTTYPE_WALL,
    OBJECTTYPE_DOOR_LAST,
    OBJECTTYPE_KEEP_TOWER,
    OBJECTTYPE_TOWER,
    OBJECTTYPE_MAX
};

enum WintergraspGameObjectState
{
    OBJECTSTATE_NONE,
    OBJECTSTATE_NEUTRAL_INTACT,
    OBJECTSTATE_NEUTRAL_DAMAGED,
    OBJECTSTATE_NEUTRAL_DESTROYED,
    OBJECTSTATE_HORDE_INTACT,
    OBJECTSTATE_HORDE_DAMAGED,
    OBJECTSTATE_HORDE_DESTROYED,
    OBJECTSTATE_ALLIANCE_INTACT,
    OBJECTSTATE_ALLIANCE_DAMAGED,
    OBJECTSTATE_ALLIANCE_DESTROYED
};

enum WintergraspGraveyardId
{
    GRAVEYARDID_WORKSHOP_NE,
    GRAVEYARDID_WORKSHOP_NW,
    GRAVEYARDID_WORKSHOP_SE,
    GRAVEYARDID_WORKSHOP_SW,
    GRAVEYARDID_KEEP,
    GRAVEYARDID_HORDE,
    GRAVEYARDID_ALLIANCE,
    GRAVEYARDID_MAX
};

enum WintergraspTowerId
{
    TOWERID_FORTRESS_NW,
    TOWERID_FORTRESS_SW,
    TOWERID_FORTRESS_SE,
    TOWERID_FORTRESS_NE,
    TOWERID_SHADOWSIGHT,
    TOWERID_WINTER_S_EDGE,
    TOWERID_FLAMEWATCH,
    TOWERID_MAX
};

enum WintergraspWorkshopId
{
    WORKSHOPID_NE,
    WORKSHOPID_NW,
    WORKSHOPID_SE,
    WORKSHOPID_SW,
    WORKSHOPID_KEEP_WEST,
    WORKSHOPID_KEEP_EAST,
    WORKSHOPID_MAX
};

enum WintergraspData
{
    DATA_WINTERGRASP_DAMAGED_TOWER_DEFENCE,
    DATA_WINTERGRASP_BROKEN_TOWER_DEFENCE,
    DATA_WINTERGRASP_DAMAGED_TOWER_ATTACK,
    DATA_WINTERGRASP_BROKEN_TOWER_ATTACK,
    DATA_WINTERGRASP_MAX_VEHICLE_ALLIANCE,
    DATA_WINTERGRASP_MAX_VEHICLE_HORDE,
    DATA_WINTERGRASP_VEHICLE_ALLIANCE,
    DATA_WINTERGRASP_VEHICLE_HORDE,
    DATA_WINTERGRASP_WON_ALLIANCE,
    DATA_WINTERGRASP_DEF_ALLIANCE,
    DATA_WINTERGRASP_WON_HORDE,
    DATA_WINTERGRASP_DEF_HORDE,
    DATA_WINTERGRASP_MAX
};

enum WintergraspWorldstates
{
    WORLDSTATE_WINTERGRASP_WORKSHOP_NE              = 3701,
    WORLDSTATE_WINTERGRASP_WORKSHOP_NW              = 3700,
    WORLDSTATE_WINTERGRASP_WORKSHOP_SE              = 3703,
    WORLDSTATE_WINTERGRASP_WORKSHOP_SW              = 3702,
    WORLDSTATE_WINTERGRASP_WORKSHOP_KEEP_W          = 3698,
    WORLDSTATE_WINTERGRASP_WORKSHOP_KEEP_E          = 3699,
    WORLDSTATE_WINTERGRASP_VEHICLE_HORDE            = 3490,
    WORLDSTATE_WINTERGRASP_MAX_VEHICLE_HORDE        = 3491,
    WORLDSTATE_WINTERGRASP_VEHICLE_ALLIANCE         = 3680,
    WORLDSTATE_WINTERGRASP_MAX_VEHICLE_ALLIANCE     = 3681,
    WORLDSTATE_WINTERGRASP_ACTIVE                   = 3801,
    WORLDSTATE_WINTERGRASP_DEFENDER                 = 3802,
    WORLDSTATE_WINTERGRASP_ATTACKER                 = 3803,
    WORLDSTATE_WINTERGRASP_SHOW_WORLDSTATE          = 3710,
    WORLDSTATE_WINTERGRASP_ATTACKED_HORDE           = 4022,
    WORLDSTATE_WINTERGRASP_ATTACKED_ALLIANCE        = 4023,
    WORLDSTATE_WINTERGRASP_DEFENDED_HORDE           = 4024,
    WORLDSTATE_WINTERGRASP_DEFENDED_ALLIANCE        = 4025
};

enum WGGossipText
{
    GOSSIP_WINTERGRASP_GRAVEYARD_NE                 = 20071,
    GOSSIP_WINTERGRASP_GRAVEYARD_NW                 = 20072,
    GOSSIP_WINTERGRASP_GRAVEYARD_SE                 = 20074,
    GOSSIP_WINTERGRASP_GRAVEYARD_SW                 = 20073,
    GOSSIP_WINTERGRASP_GRAVEYARD_KEEP               = 20070,
    GOSSIP_WINTERGRASP_GRAVEYARD_HORDE              = 20075,
    GOSSIP_WINTERGRASP_GRAVEYARD_ALLIANCE           = 20076
};

enum WintergraspNpcs
{
    NPC_WINTERGRASP_GUARD_HORDE                     = 30739,
    NPC_WINTERGRASP_GUARD_ALLIANCE                  = 30740,
    NPC_WINTERGRASP_STALKER                         = 27869,

    NPC_WINTERGRASP_VIERON_BLAZEFEATHER             = 31102,
    NPC_WINTERGRASP_STONE_GUARD_MUKAR               = 32296, // <WINTERGRASP QUARTERMASTER>
    NPC_WINTERGRASP_HOODOO_MASTER_FU_JIN            = 31101, // <MASTER HEXXER>
    NPC_WINTERGRASP_CHAMPION_ROS_SLAI               = 39173, // <WINTERGRASP QUARTERMASTER>
    NPC_WINTERGRASP_COMMANDER_DARDOSH               = 31091,
    NPC_WINTERGRASP_TACTICAL_OFFICER_KILRATH        = 31151,
    NPC_WINTERGRASP_SIEGESMITH_STRONGHOOF           = 31106,
    NPC_WINTERGRASP_PRIMALIST_MULFORT               = 31053,
    NPC_WINTERGRASP_LIEUTENANT_MURP                 = 31107,

    NPC_WINTERGRASP_BOWYER_RANDOLPH                 = 31052,
    NPC_WINTERGRASP_KNIGHT_DAMERON                  = 32294, // <WINTERGRASP QUARTERMASTER>
    NPC_WINTERGRASP_SORCERESS_KAYLANA               = 31051, // <ENCHANTRESS>
    NPC_WINTERGRASP_MARSHAL_MAGRUDER                = 39172, // <WINTERGRASP QUARTERMASTER>
    NPC_WINTERGRASP_COMMANDER_ZANNETH               = 31036,
    NPC_WINTERGRASP_TACTICAL_OFFICER_AHBRAMIS       = 31153,
    NPC_WINTERGRASP_SIEGE_MASTER_STOUTHANDLE        = 31108,
    NPC_WINTERGRASP_ANCHORITE_TESSA                 = 31054,
    NPC_WINTERGRASP_SENIOR_DEMOLITIONIST_LEGOSO     = 31109,

    NPC_TAUNKA_SPIRIT_GUIDE                         = 31841, // Horde spirit guide for Wintergrasp
    NPC_DWARVEN_SPIRIT_GUIDE                        = 31842, // Alliance spirit guide for Wintergrasp

    NPC_WINTERGRASP_SIEGE_ENGINE_ALLIANCE           = 28312,
    NPC_WINTERGRASP_SIEGE_ENGINE_HORDE              = 32627,
    NPC_WINTERGRASP_SIEGE_TURRET_HORDE              = 32629,
    NPC_WINTERGRASP_SIEGE_TURRET_ALLIANCE           = 28319,
    NPC_WINTERGRASP_CATAPULT                        = 27881,
    NPC_WINTERGRASP_DEMOLISHER                      = 28094,
    NPC_WINTERGRASP_TOWER_CANNON                    = 28366,

    NPC_WINTERGRASP_PVP_KILL_HORDE                  = 39019,
    NPC_WINTERGRASP_PVP_KILL_ALLIANCE               = 31086
};

enum WintergraspText
{
    TEXT_WINTERGRASP_SOUTHERN_TOWER_DAMAGE          = 1,
    TEXT_WINTERGRASP_SOUTHERN_TOWER_DESTROY         = 2,
    TEXT_WINTERGRASP_EASTERN_TOWER_DAMAGE           = 3,
    TEXT_WINTERGRASP_EASTERN_TOWER_DESTROY          = 4,
    TEXT_WINTERGRASP_WESTERN_TOWER_DAMAGE           = 5,
    TEXT_WINTERGRASP_WESTERN_TOWER_DESTROY          = 6,
    TEXT_WINTERGRASP_NW_KEEPTOWER_DAMAGE            = 7,
    TEXT_WINTERGRASP_NW_KEEPTOWER_DESTROY           = 8,
    TEXT_WINTERGRASP_SE_KEEPTOWER_DAMAGE            = 9,
    TEXT_WINTERGRASP_SE_KEEPTOWER_DESTROY           = 10,
    TEXT_WINTERGRASP_BROKEN_TEMPLE_ATTACK_ALLIANCE  = 11,
    TEXT_WINTERGRASP_BROKEN_TEMPLE_CAPTURE_ALLIANCE = 12,
    TEXT_WINTERGRASP_BROKEN_TEMPLE_ATTACK_HORDE     = 13,
    TEXT_WINTERGRASP_BROKEN_TEMPLE_CAPTURE_HORDE    = 14,
    TEXT_WINTERGRASP_EASTSPARK_ATTACK_ALLIANCE      = 15,
    TEXT_WINTERGRASP_EASTSPARK_CAPTURE_ALLIANCE     = 16,
    TEXT_WINTERGRASP_EASTSPARK_ATTACK_HORDE         = 17,
    TEXT_WINTERGRASP_EASTSPARK_CAPTURE_HORDE        = 18,
    TEXT_WINTERGRASP_SUNKEN_RING_ATTACK_ALLIANCE    = 19,
    TEXT_WINTERGRASP_SUNKEN_RING_CAPTURE_ALLIANCE   = 20,
    TEXT_WINTERGRASP_SUNKEN_RING_ATTACK_HORDE       = 21,
    TEXT_WINTERGRASP_SUNKEN_RING_CAPTURE_HORDE      = 22,
    TEXT_WINTERGRASP_WESTSPARK_ATTACK_ALLIANCE      = 23,
    TEXT_WINTERGRASP_WESTSPARK_CAPTURE_ALLIANCE     = 24,
    TEXT_WINTERGRASP_WESTSPARK_ATTACK_HORDE         = 25,
    TEXT_WINTERGRASP_WESTSPARK_CAPTURE_HORDE        = 26,

    TEXT_WINTERGRASP_START_GROUPING                 = 27,
    TEXT_WINTERGRASP_START_BATTLE                   = 28,
    TEXT_WINTERGRASP_FORTRESS_DEFEND_ALLIANCE       = 29,
    TEXT_WINTERGRASP_FORTRESS_CAPTURE_ALLIANCE      = 30,
    TEXT_WINTERGRASP_FORTRESS_DEFEND_HORDE          = 31,
    TEXT_WINTERGRASP_FORTRESS_CAPTURE_HORDE         = 32,

    TEXT_WINTERGRASP_NE_KEEPTOWER_DAMAGE            = 33,
    TEXT_WINTERGRASP_NE_KEEPTOWER_DESTROY           = 34,
    TEXT_WINTERGRASP_SW_KEEPTOWER_DAMAGE            = 35,
    TEXT_WINTERGRASP_SW_KEEPTOWER_DESTROY           = 36,

    TEXT_WINTERGRASP_RANK_CORPORAL                  = 37,
    TEXT_WINTERGRASP_RANK_FIRST_LIEUTENANT          = 38
};

enum WintergraspGameObject
{
    GO_WINTERGRASP_FACTORY_BANNER_NE                = 190475,
    GO_WINTERGRASP_FACTORY_BANNER_NW                = 190487,
    GO_WINTERGRASP_FACTORY_BANNER_SE                = 194959,
    GO_WINTERGRASP_FACTORY_BANNER_SW                = 194962,

    GO_WINTERGRASP_TITAN_S_RELIC                    = 192829,

    GO_WINTERGRASP_FORTRESS_TOWER_1                 = 190221,
    GO_WINTERGRASP_FORTRESS_TOWER_2                 = 190373,
    GO_WINTERGRASP_FORTRESS_TOWER_3                 = 190377,
    GO_WINTERGRASP_FORTRESS_TOWER_4                 = 190378,

    GO_WINTERGRASP_SHADOWSIGHT_TOWER                = 190356,
    GO_WINTERGRASP_WINTER_S_EDGE_TOWER              = 190357,
    GO_WINTERGRASP_FLAMEWATCH_TOWER                 = 190358,

    GO_WINTERGRASP_FORTRESS_GATE                    = 190375,
    GO_WINTERGRASP_VAULT_GATE                       = 191810,

    GO_WINTERGRASP_KEEP_COLLISION_WALL              = 194323,
    GO_WINTERGRASP_VEHICLE_TELEPORTER               = 192951
};

enum WintergraspQuests
{
    QUEST_WINTERGRASP_VICTORY_ALLIANCE              = 13181,
    QUEST_WINTERGRASP_VICTORY_HORDE                 = 13183
};

enum WintergraspSpawnGroupIds
{
    SPAWNGROUP_WINTERGRASP_KEEP_CANNONS = 23
};

struct WintergraspGraveyardData
{
    WintergraspGraveyardId Id;
    uint32 Entry;
    uint32 TextId; // for gossip menu
    TeamId StartControl;
};

struct WintergraspBuildingSpawnData
{
    uint32 Entry;
    uint32 WorldState;
    WintergraspBuildingType Type;
};

struct WintergraspTowerInfo
{
    WintergraspTowerId TowerId;

    struct
    {
        uint8 Damaged;
        uint8 Destroyed;
    } TextIds;
};

struct WintergraspObjectPositionData
{
    Position Location;
    uint32 HordeEntry;
    uint32 AllianceEntry;
};

struct WintergraspGameObjectData
{
    Position Location;
    QuaternionData Rotation;
    uint32 HordeEntry;
    uint32 AllianceEntry;
};

struct WintergraspTowerData
{
    uint32 TowerEntry;
    std::vector<WintergraspGameObjectData> GameObject;
    std::vector<WintergraspObjectPositionData> CreatureBottom;
};

struct WintergraspTowerCannonData
{
    uint32 TowerEntry;
    std::vector<Position> TowerCannonBottom;
    std::vector<Position> TurretTop;
};

struct WintergraspWorkshopInfo
{
    WintergraspWorkshopId WorkshopId;
    uint32 WorldStateId;

    struct
    {
        uint8 AllianceCapture;
        uint8 AllianceAttack;
        uint8 HordeCapture;
        uint8 HordeAttack;
    } TextIds;
};

class TC_GAME_API BattlefieldWintergrasp : public Battlefield
{
    public:
        ~BattlefieldWintergrasp();

        bool SetupBattlefield() override;
        void Update(uint32 diff) override;
        void OnBattleStart() override;
        void OnBattleEnd(bool endByTimer) override;
        void OnStartGrouping() override;
        void OnPlayerJoinWar(Player* player) override;
        void OnPlayerLeaveWar(Player* player) override;
        void OnPlayerLeaveZone(Player* player) override;
        void OnPlayerEnterZone(Player* player) override;
        void OnCreatureCreate(Creature* creature) override;
        void OnCreatureRemove(Creature* creature) override;
        void OnGameObjectCreate(GameObject* gameObject) override;
        void OnGameObjectRemove(GameObject* gameObject) override;
        void OnUnitDeath(Unit* unit) override;
        void DoCompleteOrIncrementAchievement(uint32 achievement, Player* player, uint8 incrementNumber = 1) override;
        void FillInitialWorldStates(WorldPacket& data) override;
        void SendInitWorldStatesToAll() override;
        void HandleKill(Player* killer, Unit* victim) override;
        void ProcessEvent(WorldObject* object, uint32 eventId) override;
        uint32 GetData(uint32 data) const override;

        void RemoveAurasFromPlayer(Player* player);
        void SetRelic(ObjectGuid relicGUID) { _titansRelicGUID = relicGUID; }
        void SetRelicInteractible();
        void UpdateDamagedTowerCount(TeamId team);
        void UpdatedDestroyedTowerCount(TeamId team);
        void UpdateVehicleCountWG();
        void UpdateVehicleCounter(bool initialize);
        void SendInitWorldStatesTo(Player const* player);
        void HandlePromotion(Player* killer, Unit* killed);
        void PromotePlayer(Player* killer);
        void UpdateTenacity();
        void SendWarning(uint8 id, Player const* target = nullptr);
        void SendSpellAreaUpdate(uint32 areaId);

        GameObject* GetRelic() { return GetGameObject(_titansRelicGUID); }
        bool CanInteractWithRelic() const { return _relicInteractible; }
        WintergraspGraveyardId GetSpiritGraveyardId(uint32 areaId) const;

    private:
        WintergraspBuilding* GetBuilding(uint32 entry) const;
        WintergraspBuilding* GetBuilding(ObjectGuid guid) const;
        WintergraspWorkshop* GetWorkshop(WintergraspWorkshopId id) const;

        void ApplyTenacity(Unit* target, bool vehicle = false);

        WorkshopSet _workshopSet;
        BuildingSet _buildingSet;
        GuidUnorderedSet _vehicleSet[PVP_TEAMS_COUNT];
        GuidUnorderedSet _keepCannonList;
        GuidUnorderedSet _teleporterList;
        ObjectGuid _titansRelicGUID;
        ObjectGuid _stalkerGUID;
        TeamId _tenacityTeam;
        bool _relicInteractible;
        uint32 _tenacityStack;
        TimeTrackerSmall _saveTimer;
};

class WintergraspGraveyard : public BattlefieldGraveyard
{
    public:
        explicit WintergraspGraveyard(BattlefieldWintergrasp* battlefield);

        void SetTextId(uint32 textId) { _gossipTextId = textId; }
        void SetIsSpellAreaForced(bool value) { _spellAreaForced = value; }

        uint32 GetTextId() const { return _gossipTextId; }
        bool IsSpellAreaForced() const { return _spellAreaForced; }

    protected:
        uint32 _gossipTextId;
        bool _spellAreaForced;
};

class WintergraspCapturePoint : public BattlefieldCapturePoint
{
    public:
        explicit WintergraspCapturePoint(BattlefieldWintergrasp* battlefield, TeamId teamInControl);

        void LinkToWorkshop(WintergraspWorkshop* workshop) { _workshop = workshop; }
        void ChangeTeam(TeamId oldteam) override;
        TeamId GetTeam() const { return _team; }

    protected:
        WintergraspWorkshop* _workshop;
};

class TC_GAME_API WintergraspBuilding
{
    public:
        explicit WintergraspBuilding(BattlefieldWintergrasp* wintergrasp, WintergraspBuildingType type, uint32 entry, uint32 worldState);

        void Initialize(GameObject* gameObject);
        void Rebuild();
        void Damaged();
        void Destroyed();
        void CleanRelatedObject(ObjectGuid guid);
        void UpdateCreatureAndGo();
        void UpdateTurretAttack(bool disable);
        void UpdateForNoBattle(bool initialize = false);
        void FillInitialWorldStates(WorldPacket& data);
        void Save();

        ObjectGuid const GetGUID() const { return _buildGUID; }
        uint32 GetEntry() const { return _entry; }
        bool IsDestroyed() const { return _state == OBJECTSTATE_NEUTRAL_DESTROYED || _state == OBJECTSTATE_HORDE_DESTROYED || _state == OBJECTSTATE_ALLIANCE_DESTROYED; }
        bool IsDamaged() const { return _state == OBJECTSTATE_NEUTRAL_DAMAGED || _state == OBJECTSTATE_HORDE_DAMAGED || _state == OBJECTSTATE_ALLIANCE_DAMAGED; }

    private:
        BattlefieldWintergrasp* _battlefield;
        WintergraspTowerInfo const* _info;
        WintergraspBuildingType _type;
        WintergraspGameObjectState _state;
        ObjectGuid _buildGUID;
        TeamId _teamControl;
        uint32 _entry;
        uint32 _worldState;

        GuidVector _gameObjectList[PVP_TEAMS_COUNT];
        GuidVector _creatureList[PVP_TEAMS_COUNT];
        GuidVector _bottomCannonList;
        GuidVector _topCannonList;
};

class TC_GAME_API WintergraspWorkshop
{
    public:
        explicit WintergraspWorkshop(BattlefieldWintergrasp* wintergrasp, uint8 type);

        void LinkCapturePoint(WintergraspCapturePoint* capturePoint) { _capturePoint = capturePoint; }
        void GiveControlTo(TeamId teamId, bool initialize = false);
        void UpdateForBattle();
        void UpdateForNoBattle();
        void FillInitialWorldStates(WorldPacket& data);
        void Save();

        WintergraspCapturePoint* GetCapturePoint() const { return _capturePoint; }
        WintergraspWorkshopId GetId() const;
        TeamId GetTeamControl() const { return _teamControl; }

    private:
        BattlefieldWintergrasp* _battlefield;
        WintergraspCapturePoint* _capturePoint;
        WintergraspWorkshopInfo const* _info;
        WintergraspGameObjectState _state;
        ObjectGuid _buildGUID;
        TeamId _teamControl;
};

#endif
