/*
* This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef BATTLEFIELD_TB_
#define BATTLEFIELD_TB_

#include "Battlefield.h"

class BattlefieldTB;
class TolBaradCapturePoint;

namespace WorldPackets
{
    namespace WorldState
    {
        class InitWorldStates;
    }
}

enum TolBaradInfo
{
    BATTLEFIELD_TB_MAPID = 732, // Tol Barad
    BATTLEFIELD_TB_ZONEID = 5095, // Tol Barad
};

enum TolBaradData
{
    BATTLEFIELD_TB_DATA_BUILDINGS_CAPTURED,
    BATTLEFIELD_TB_DATA_TOWERS_INTACT,
    BATTLEFIELD_TB_DATA_TOWERS_DESTROYED,
    BATTLEFIELD_TB_DATA_MAX,
};

enum TolBaradSpells
{
    // Quest completion
    SPELL_VICTORY_ALLIANCE = 94665,
    SPELL_VICTORY_HORDE = 94763,

    // Rewards
    SPELL_REWARD_VICTORY_ALLIANCE = 89789,
    SPELL_REWARD_VICTORY_HORDE = 89791,
    SPELL_REWARD_DEFEAT = 89793,

    SPELL_REWARD_TOWER_INTACT = 89794,
    SPELL_REWARD_TOWER_DAMAGED = 89795,
    SPELL_REWARD_TOWER_DESTROYED = 89796,

    // Player buffs
    SPELL_TB_SLOW_FALL = 88473,
    SPELL_TB_VETERAN = 84655,
    SPELL_TOWER_ATTACK_BONUS = 82629,
    SPELL_TB_SPIRIT_HEAL_CHANNEL = 22011, // this spell replaces m_LastResurrectTimer in Battlefield.cpp?
    SPELL_TB_SPIRITUAL_IMMUNITY = 95332,

    // Vehicle
    SPELL_THICK_LAYER_OF_RUST = 95330,
    SPELL_RIDE_TOL_BARAD_VEHICLE = 84754,
    SPELL_DEPLOY_SIEGE_MODE = 84974,
    SPELL_SIEGE_CANNON_AURA = 85167, // aura, periodically triggers spell 85122
//  SPELL_SIEGE_CANNON_EFFECT = 85122, // targets random
//  SPELL_SIEGE_CANNON_DAMAGE = 85125,
    SPELL_LEAVE_SIEGE_MODE = 85078,

    SPELL_TOWER_RANGE_FINDER_PERIODIC = 85671,
    SPELL_TOWER_RANGE_FINDER = 84979,

    // Teleportation spells
    SPELL_TB_THE_HOLE_TELEPORT = 89035,
    SPELL_TB_D_BLOCK_TELEPORT = 89037,
    SPELL_TB_CURSED_DEPTHS_TELEPORT = 89038,
};

enum TolBaradNpcs
{
    // Cursed Depths area
    NPC_TOLBARAD_CAPTIVE_SPIRIT                     = 47531,
    NPC_TOLBARAD_CELLBLOCK_OOZE                     = 47534,
    NPC_TOLBARAD_ARCHMAGE_GALUS                     = 47537,
    NPC_TOLBARAD_GHASTLY_CONVICT                    = 47590,

    // D-Block area
    NPC_TOLBARAD_SHIVARRA_DESTROYER                 = 47540,
    NPC_TOLBARAD_CELL_WATCHER                       = 47542,
    NPC_TOLBARAD_SVARNOS                            = 47544,
    NPC_TOLBARAD_JAILED_WRATHGUARD                  = 47548,
    NPC_TOLBARAD_IMPRISONED_IMP                     = 47549,

    // The Hole area
    NPC_TOLBARAD_WARDEN_SILVA                       = 48036,
    NPC_TOLBARAD_WARDEN_GUARD                       = 47561,
    NPC_TOLBARAD_IMPRISONED_WORKER                  = 47550,
    NPC_TOLBARAD_EXILED_MAGE                        = 47552,

    // Other
    NPC_CROCOLISK                                   = 47591,
    NPC_PROBLIM                                     = 47593,

    // Graveyard spirits
    NPC_TB_GY_SPIRIT_BARADIN_HOLD_A                 = 45066,
    NPC_TB_GY_SPIRIT_BARADIN_HOLD_H                 = 45067,
    NPC_TB_GY_SPIRIT_IRONCLAD_GARRISON_A            = 45068,
    NPC_TB_GY_SPIRIT_WARDENS_VIGIL_A                = 45069,
    NPC_TB_GY_SPIRIT_EAST_SPIRE_A                   = 45070,
    NPC_TB_GY_SPIRIT_SOUTH_SPIRE_A                  = 45071,
    NPC_TB_GY_SPIRIT_WEST_SPIRE_A                   = 45072,
    NPC_TB_GY_SPIRIT_SLAGWORKS_A                    = 45073,
    NPC_TB_GY_SPIRIT_IRONCLAD_GARRISON_H            = 45074,
    NPC_TB_GY_SPIRIT_WARDENS_VIGIL_H                = 45075,
    NPC_TB_GY_SPIRIT_SLAGWORKS_H                    = 45076,
    NPC_TB_GY_SPIRIT_WEST_SPIRE_H                   = 45077,
    NPC_TB_GY_SPIRIT_EAST_SPIRE_H                   = 45078,
    NPC_TB_GY_SPIRIT_SOUTH_SPIRE_H                  = 45079,

    // Stalker, dummies
    NPC_DEBUG_ANNOUNCER = 43679,
    NPC_TOWER_RANGE_FINDER = 45492,
    NPC_TOWER_CANNON_TARGET = 45561,
    NPC_SIEGE_ENGINE_TURRET = 45564,
};

enum TolBaradGOs
{
    // Towers
    GO_WEST_SPIRE = 204588,
    GO_EAST_SPIRE = 204589,
    GO_SOUTH_SPIRE = 204590,

    GO_CAPTURE_POINT_NORTH_A_DEFENDING          = 205068,
    GO_CAPTURE_POINT_NORTH_H_DEFENDING          = 205096,
    GO_CAPTURE_POINT_EAST_A_DEFENDING           = 205138,
    GO_CAPTURE_POINT_EAST_H_DEFENDING           = 205139,
    GO_CAPTURE_POINT_WEST_A_DEFENDING           = 205101,
    GO_CAPTURE_POINT_WEST_H_DEFENDING           = 205103,

    // Entrance gates and instance door
    GO_TOLBARAD_GATES = 206598,
    GO_TOLBARAD_DOOR = 206576,

    // Other
    GO_TB_MEETING_STONE = 206668,

    GO_TB_INSTANCE_VISUAL_1 = 207746,
    GO_TB_INSTANCE_VISUAL_2 = 207747,
    GO_TB_INSTANCE_VISUAL_3 = 210114,
    GO_TB_INSTANCE_VISUAL_4 = 210115,
};

enum TolBaradGOArtKit
{
    TB_GO_ARTKIT_FLAG_NONE = 0,
    TB_GO_ARTKIT_FLAG_HORDE = 1,
    TB_GO_ARTKIT_FLAG_ALLIANCE = 2,
};

enum TolBaradWorldStates
{
    TB_WS_ALLIANCE_CONTROLS_SHOW = 5385,
    TB_WS_HORDE_CONTROLS_SHOW = 5384,
    TB_WS_ALLIANCE_ATTACKING_SHOW = 5546,
    TB_WS_HORDE_ATTACKING_SHOW = 5547,

    TB_WS_BUILDINGS_CAPTURED = 5348,
    TB_WS_BUILDINGS_CAPTURED_SHOW = 5349,
    TB_WS_TOWERS_DESTROYED = 5347,
    TB_WS_TOWERS_DESTROYED_SHOW = 5350,

    TB_WS_FACTION_CONTROLLING = 5334, // 1 -> Alliance, 2 -> Horde

    TB_WS_TIME_NEXT_BATTLE = 5332,
    TB_WS_TIME_NEXT_BATTLE_SHOW = 5387,
    TB_WS_TIME_BATTLE_END = 5333,
    TB_WS_TIME_BATTLE_END_SHOW = 5346,

    TB_WS_STATE_PREPARATIONS = 5684,
    TB_WS_STATE_BATTLE = 5344,

    /* Not Sure if TB
    TB_WS_0_UNKNOWN = 5587,
    TB_WS_9_UNKNOWN = 5508,
    TB_WS_35_UNKNOWN = 5679,
    TB_WS_36_UNKNOWN = 5678,
    TB_WS_37_UNKNOWN = 5677,
    TB_WS_60_UNKNOWN = 5361,
    TB_WS_61_UNKNOWN = 5360,
    TB_WS_65_UNKNOWN = 5195,
    TB_WS_66_UNKNOWN = 5193,
    */

    TB_WS_PROGRESS_SHOW = 5376,
    TB_WS_PROGRESS = 5377, // 0 horde, 100 alliance
    TB_WS_PROGRESS_PERCENT_GREY = 5378,

    TB_WS_KEEP_HORDE = 5469,
    TB_WS_KEEP_ALLIANCE = 5470,

    TB_WS_GARRISON_HORDE_CONTROLLED = 5418,
    TB_WS_GARRISON_HORDE_CAPTURING = 5419,
    TB_WS_GARRISON_NEUTRAL = 5420, // unused
    TB_WS_GARRISON_ALLIANCE_CAPTURING = 5421,
    TB_WS_GARRISON_ALLIANCE_CONTROLLED = 5422,

    TB_WS_VIGIL_HORDE_CONTROLLED = 5423,
    TB_WS_VIGIL_HORDE_CAPTURING = 5424,
    TB_WS_VIGIL_NEUTRAL = 5425, // unused
    TB_WS_VIGIL_ALLIANCE_CAPTURING = 5426,
    TB_WS_VIGIL_ALLIANCE_CONTROLLED = 5427,

    TB_WS_SLAGWORKS_HORDE_CONTROLLED = 5428,
    TB_WS_SLAGWORKS_HORDE_CAPTURING = 5429,
    TB_WS_SLAGWORKS_NEUTRAL = 5430, // unused
    TB_WS_SLAGWORKS_ALLIANCE_CAPTURING = 5431,
    TB_WS_SLAGWORKS_ALLIANCE_CONTROLLED = 5432,

    TB_WS_WEST_INTACT_HORDE = 5433,
    TB_WS_WEST_DAMAGED_HORDE = 5434,
    TB_WS_WEST_DESTROYED_NEUTRAL = 5435,
    TB_WS_WEST_INTACT_ALLIANCE = 5436,
    TB_WS_WEST_DAMAGED_ALLIANCE = 5437,
    TB_WS_WEST_INTACT_NEUTRAL = 5453, // unused
    TB_WS_WEST_DAMAGED_NEUTRAL = 5454, // unused

    TB_WS_SOUTH_INTACT_HORDE = 5438,
    TB_WS_SOUTH_DAMAGED_HORDE = 5439,
    TB_WS_SOUTH_DESTROYED_NEUTRAL = 5440,
    TB_WS_SOUTH_INTACT_ALLIANCE = 5441,
    TB_WS_SOUTH_DAMAGED_ALLIANCE = 5442,
    TB_WS_SOUTH_INTACT_NEUTRAL = 5455, // unused
    TB_WS_SOUTH_DAMAGED_NEUTRAL = 5456, // unused

    TB_WS_EAST_INTACT_HORDE = 5443,
    TB_WS_EAST_DAMAGED_HORDE = 5444,
    TB_WS_EAST_DESTROYED_NEUTRAL = 5445,
    TB_WS_EAST_INTACT_ALLIANCE = 5446,
    TB_WS_EAST_DAMAGED_ALLIANCE = 5447,
    TB_WS_EAST_INTACT_NEUTRAL = 5451,
    TB_WS_EAST_DAMAGED_NEUTRAL = 5452,
};

enum TolBaradText
{
    // DEBUG Announcer
    TB_TEXT_EAST_SPIRE_DAMAGED              = 1,
    TB_TEXT_EAST_SPIRE_DESTROYED            = 2,
    TB_TEXT_WEST_SPIRE_DAMAGED              = 3,
    TB_TEXT_WEST_SPIRE_DESTROYED            = 4,
    TB_TEXT_SOUTH_SPIRE_DAMAGED             = 5,
    TB_TEXT_SOUTH_SPIRE_DESTROYED           = 6,
    TB_TEXT_GARRISON_ALLIANCE_GAINED        = 7,
    TB_TEXT_GARRISON_ALLIANCE_LOST          = 8,
    TB_TEXT_GARRISON_HORDE_GAINED           = 9,
    TB_TEXT_GARRISON_HORDE_LOST             = 10,
    TB_TEXT_VIGIL_ALLIANCE_GAINED           = 11,
    TB_TEXT_VIGIL_ALLIANCE_LOST             = 12,
    TB_TEXT_VIGIL_HORDE_GAINED              = 13,
    TB_TEXT_VIGIL_HORDE_LOST                = 14,
    TB_TEXT_SLAGWORKS_ALLIANCE_GAINED       = 15,
    TB_TEXT_SLAGWORKS_ALLIANCE_LOST         = 16,
    TB_TEXT_SLAGWORKS_HORDE_GAINED          = 17,
    TB_TEXT_SLAGWORKS_HORDE_LOST            = 18,
    TB_TEXT_FORTRESS_DEFEND_ALLIANCE        = 19,
    TB_TEXT_FORTRESS_DEFEND_HORDE           = 20,
    TB_TEXT_FORTRESS_CAPTURE_ALLIANCE       = 21,
    TB_TEXT_FORTRESS_CAPTURE_HORDE          = 22,
    TB_TEXT_VEHICLE_OUTSIDE_WARNING         = 23,
    TB_TEXT_PREPARATIONS_IN_5_MIN           = 24,
    TB_TEXT_PREPARATIONS_IN_2_MIN           = 25,
    TB_TEXT_PREPARATIONS_IN_1_MIN           = 26,
};

enum TolBaradEvent
{
    EVENT_COUNT_CAPTURED_BASE = 1,
};

// Quest Infantry NPCs
enum TBQuestInfantryEntry
{
    NPC_ALLIANCE_WARRIOR_INFANTRY = 47599,
    NPC_ALLIANCE_PALADIN_INFANTRY = 47600,
    NPC_ALLIANCE_HUNTER_INFANTRY = 47595,
    NPC_ALLIANCE_MAGE_INFANTRY = 47598,

    NPC_HORDE_DRUID_INFANTRY = 47607,
    NPC_HORDE_MAGE_INFANTRY = 47608,
    NPC_HORDE_ROGUE_INFANTRY = 47609,
    NPC_HORDE_SHAMAN_INFANTRY = 47610,
};

// Guard NPCs
enum TBGuardEntry
{
    NPC_BARADIN_GUARD                       = 51165,
    NPC_HELLSCREAMS_SENTRY                  = 51166,
};

enum TBFactionNPCEntry
{
    // Guards
    NPC_BARADIN_GUARD_1 = 47324,
    NPC_BARADIN_GUARD_2 = 47325,
    NPC_BARADIN_GRUNT_1 = 47335,
    NPC_BARADIN_GRUNT_2 = 47336,

    // Questgivers
    NPC_SERGEANT_PARKER = 48066, // Everytime
    NPC_COMMANDER_STEVENS = 48039, // One of these three
    NPC_2ND_LIEUTENANT_WANSWORTH = 48061,
    NPC_MARSHAL_FALLOWS = 48074,

    NPC_COMMANDER_ZANOTH = 48069, // Everytime!
    NPC_STAFF_SERGEANT_LAZGAR = 48062, // One of these three
    NPC_DRILLMASTER_RAZGOTH = 48070,
    NPC_PRIVATE_GARNOTH = 48071,

    // Portal summoners
    NPC_MAVEN_ZARA = 50173,
    NPC_RHAGHA = 50167,
};

// Questing
enum TBQuesting
{
    CELLBLOCK_THE_HOLE          = 0, // The Hole area
    CELLBLOCK_D_BLOCK           = 1, // D-Block area
    CELLBLOCK_CURSED_DEPTHS     = 2, // Cursed Depths area
    CELLBLOCK_MAX               = 3,
    CELLBLOCK_NONE,

    AREA_THE_HOLE = 5659,
    AREA_D_BLOCK = 5657,
    AREA_CURSED_DEPTHS = 5658,

    GO_GATE_TO_THE_HOLE                     = 206845,
    GO_GATE_D_BLOCK                         = 206844,
    GO_CURSED_DEPTHS_GATE                   = 206843,

    GO_CRATE_OF_CELLBLOCK_RATIONS           = 206996,
    GO_CURSED_SHACKLES                      = 206905,
    GO_DUSTY_PRISON_JOURNAL                 = 206890,
};

// Capture Points
enum TBCapturePointId
{
    TB_BASE_IRONCLAD_GARRISON = 0,
    TB_BASE_WARDENS_VIGIL = 1,
    TB_BASE_SLAGWORKS = 2,
    TB_BASE_COUNT = 3,
};

// Towers
enum TBTowerId
{
    TB_TOWER_EAST_SPIRE = 0,
    TB_TOWER_SOUTH_SPIRE = 1,
    TB_TOWER_WEST_SPIRE = 2,
    TB_TOWERS_COUNT = 3,
};

// Vehicles
enum TBVehicles
{
    NPC_ABANDONED_SIEGE_ENGINE = 45344,
};

// Banners
enum TBFactionBannerEntry
{
    GO_BARADINS_WARDEN_BANNER = 207391, // Alliance banner
    GO_HELLSCREAM_REACH_BANNER = 207400, // Horde banner
};

// Portals
enum TBPortalEntry
{
    TB_PORTAL_ALLIANCE = 208227, // Portal to Stormwind
    TB_PORTAL_HORDE = 208226, // Portal to Orgrimmar
};

/* ################### *
 * Tol Barad graveyard *
 * ################### */

enum TBGraveyardAreaId
{
    // Tol Barad
    TB_GY_BARADIN_HOLD = 1789,
    TB_GY_IRONCLAD_GARRISON = 1783,
    TB_GY_WARDENS_VIGIL = 1785,
    TB_GY_SLAGWORKS = 1787,
    TB_GY_WEST_SPIRE = 1784,
    TB_GY_SOUTH_SPIRE = 1786,
    TB_GY_EAST_SPIRE = 1788,
    BATTLEFIELD_TB_GRAVEYARD_MAX = 7,

    // Tol Barad Peninsula
    TBP_GY_ALLIANCE_DAILY = 1808,
    TBP_GY_HORDE_DAILY = 1807,
};

/* ####################### *
 * Tol Barad capture point *
 * ####################### */

class TolBaradCapturePoint : public BfCapturePoint
{
    public:
        TolBaradCapturePoint(BattlefieldTB* battlefield, TeamId teamInControl);

        void ChangeTeam(TeamId /*oldteam*/) override;
};

/* ##################### *
 * Tol Barad battlefield *
 * ##################### */

class TC_GAME_API BattlefieldTB : public Battlefield
{
    public:
        ~BattlefieldTB();

        void OnStartGrouping() override;
        void OnBattleStart() override;
        void OnBattleEnd(bool endByTimer) override;

        void OnPlayerEnterZone(Player* player) override;
        void OnPlayerLeaveZone(Player* player) override;

        void OnPlayerJoinWar(Player* player) override;
        void OnPlayerLeaveWar(Player* player) override;

        bool Update(uint32 diff) override;

        void OnCreatureCreate(Creature* creature) override;
        //void OnCreatureRemove(Creature* creature) override;

        void OnGameObjectCreate(GameObject* go) override;

        void UpdateCapturedBaseCount();
        //void UpdatedDestroyedTowerCount(TeamId team);

        //void DoCompleteOrIncrementAchievement(uint32 achievement, Player* player, uint8 incrementNumber = 1) override;

        bool SetupBattlefield() override;

        void SendInitWorldStatesTo(Player* player);
        void SendInitWorldStatesToAll() override;
        void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& /*data*/) override;
        void UpdateWorldStates();

        void HandleKill(Player* killer, Unit* victim) override;
        //void OnUnitDeath(Unit* unit) override;
        void PromotePlayer(Player* killer);
        void RemoveAurasFromPlayer(Player* player);

        void ProcessEvent(WorldObject* obj, uint32 eventId) override;

        void TowerDamaged(TBTowerId tbTowerId);
        void TowerDestroyed(TBTowerId tbTowerId);

        // returns the graveyardId in the specified area.
        //uint8 GetSpiritGraveyardId(uint32 areaId) const;

        void UpdateNPCsAndGameObjects();
        void CreateCapturePoints();

    protected:
        // Minutes till battle preparation warnings
        bool warnedFiveMinutes;
        bool warnedTwoMinutes;
        bool warnedOneMinute;

        uint32 m_saveTimer;

        bool updatedNPCAndObjects;
        uint32 m_updateObjectsTimer;

        uint32 m_BonusTime;

        GuidSet BattleInactiveNPCs;
        GuidSet BattleInactiveGOs;

        GuidSet TemporaryNPCs;
        GuidSet TemporaryGOs;

        GuidSet Towers;

        uint8 m_iCellblockRandom;

        ObjectGuid TBGatesGUID;
        ObjectGuid TBDoorGUID;

        ObjectGuid m_gateToTheHoleGUID;
        ObjectGuid m_gateDBlockGUID;
        ObjectGuid m_gateCursedDepthsGUID;
};

#endif
