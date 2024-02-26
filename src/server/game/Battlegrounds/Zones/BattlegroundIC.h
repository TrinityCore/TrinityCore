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

#ifndef __BATTLEGROUNDIC_H
#define __BATTLEGROUNDIC_H

#include "Battleground.h"
#include "Object.h"
#include "TaskScheduler.h"
#include "Timer.h"

const uint32 BG_IC_Factions[2] =
{
    1732, // Alliance
    1735  // Horde
};

enum creaturesIC
{
    NPC_HIGH_COMMANDER_HALFORD_WYRMBANE     = 34924, // Alliance Boss
    NPC_OVERLORD_AGMAR                      = 34922, // Horde Boss
    NPC_KOR_KRON_GUARD                      = 34918, // horde guard
    NPC_SEVEN_TH_LEGION_INFANTRY            = 34919, // alliance guard
    NPC_KEEP_CANNON                         = 34944,
    NPC_DEMOLISHER                          = 34775,
    NPC_SIEGE_ENGINE_H                      = 35069,
    NPC_SIEGE_ENGINE_A                      = 34776,
    NPC_GLAIVE_THROWER_A                    = 34802,
    NPC_GLAIVE_THROWER_H                    = 35273,
    NPC_CATAPULT                            = 34793,
    NPC_HORDE_GUNSHIP_CANNON                = 34935,
    NPC_ALLIANCE_GUNSHIP_CANNON             = 34929,
    NPC_HORDE_GUNSHIP_CAPTAIN               = 35003,
    NPC_ALLIANCE_GUNSHIP_CAPTAIN            = 34960,
    NPC_WORLD_TRIGGER_NOT_FLOATING          = 34984,
    NPC_WORLD_TRIGGER_ALLIANCE_FRIENDLY     = 20213,
    NPC_WORLD_TRIGGER_HORDE_FRIENDLY        = 20212
};

#define MAX_REINFORCEMENTS 400

enum Actions
{
    ACTION_GUNSHIP_READY = 1,
    ACTION_IOC_INTERACT_CAPTURABLE_OBJECT = 2,
    ACTION_IOC_CAPTURE_CAPTURABLE_OBJECT = 3
};

enum BannersTypes
{
    BANNER_A_CONTROLLED,
    BANNER_A_CONTESTED,
    BANNER_H_CONTROLLED,
    BANNER_H_CONTESTED
};

enum BG_IC_ExploitTeleportLocations
{
    IC_EXPLOIT_TELEPORT_LOCATION_ALLIANCE = 3986,
    IC_EXPLOIT_TELEPORT_LOCATION_HORDE = 3983
};

enum Spells
{
    SPELL_OIL_REFINERY                      = 68719,
    SPELL_QUARRY                            = 68720,
    SPELL_PARACHUTE                         = 66656,
    SPELL_SLOW_FALL                         = 12438,
    SPELL_DESTROYED_VEHICLE_ACHIEVEMENT     = 68357,
    SPELL_BACK_DOOR_JOB_ACHIEVEMENT         = 68502,
    SPELL_DRIVING_CREDIT_DEMOLISHER         = 68365,
    SPELL_DRIVING_CREDIT_GLAIVE             = 68363,
    SPELL_DRIVING_CREDIT_SIEGE              = 68364,
    SPELL_DRIVING_CREDIT_CATAPULT           = 68362,
    SPELL_SIMPLE_TELEPORT                   = 12980,
    SPELL_TELEPORT_VISUAL_ONLY              = 51347,
    SPELL_PARACHUTE_IC                      = 66657,
    SPELL_LAUNCH_NO_FALLING_DAMAGE          = 66251
};

enum ICWorldStates
{
    BG_IC_ALLIANCE_REINFORCEMENTS_SET   = 4221,
    BG_IC_HORDE_REINFORCEMENTS_SET      = 4222,
    BG_IC_ALLIANCE_REINFORCEMENTS       = 4226,
    BG_IC_HORDE_REINFORCEMENTS          = 4227,
    BG_IC_MAX_REINFORCEMENTS            = 17377,

    BG_IC_GATE_FRONT_H_WS_CLOSED        = 4317,
    BG_IC_GATE_WEST_H_WS_CLOSED         = 4318,
    BG_IC_GATE_EAST_H_WS_CLOSED         = 4319,
    BG_IC_GATE_FRONT_A_WS_CLOSED        = 4328,
    BG_IC_GATE_WEST_A_WS_CLOSED         = 4327,
    BG_IC_GATE_EAST_A_WS_CLOSED         = 4326,
    BG_IC_GATE_FRONT_H_WS_OPEN          = 4322,
    BG_IC_GATE_WEST_H_WS_OPEN           = 4321,
    BG_IC_GATE_EAST_H_WS_OPEN           = 4320,
    BG_IC_GATE_FRONT_A_WS_OPEN          = 4323,
    BG_IC_GATE_WEST_A_WS_OPEN           = 4324,
    BG_IC_GATE_EAST_A_WS_OPEN           = 4325,

    BG_IC_DOCKS_UNCONTROLLED            = 4301,
    BG_IC_DOCKS_CONFLICT_A              = 4305,
    BG_IC_DOCKS_CONFLICT_H              = 4302,
    BG_IC_DOCKS_CONTROLLED_A            = 4304,
    BG_IC_DOCKS_CONTROLLED_H            = 4303,

    BG_IC_HANGAR_UNCONTROLLED           = 4296,
    BG_IC_HANGAR_CONFLICT_A             = 4300,
    BG_IC_HANGAR_CONFLICT_H             = 4297,
    BG_IC_HANGAR_CONTROLLED_A           = 4299,
    BG_IC_HANGAR_CONTROLLED_H           = 4298,

    BG_IC_QUARRY_UNCONTROLLED           = 4306,
    BG_IC_QUARRY_CONFLICT_A             = 4310,
    BG_IC_QUARRY_CONFLICT_H             = 4307,
    BG_IC_QUARRY_CONTROLLED_A           = 4309,
    BG_IC_QUARRY_CONTROLLED_H           = 4308,

    BG_IC_REFINERY_UNCONTROLLED         = 4311,
    BG_IC_REFINERY_CONFLICT_A           = 4315,
    BG_IC_REFINERY_CONFLICT_H           = 4312,
    BG_IC_REFINERY_CONTROLLED_A         = 4314,
    BG_IC_REFINERY_CONTROLLED_H         = 4313,

    BG_IC_WORKSHOP_UNCONTROLLED         = 4294,
    BG_IC_WORKSHOP_CONFLICT_A           = 4228,
    BG_IC_WORKSHOP_CONFLICT_H           = 4293,
    BG_IC_WORKSHOP_CONTROLLED_A         = 4229,
    BG_IC_WORKSHOP_CONTROLLED_H         = 4230,

    BG_IC_ALLIANCE_KEEP_UNCONTROLLED    = 4341,
    BG_IC_ALLIANCE_KEEP_CONFLICT_A      = 4342,
    BG_IC_ALLIANCE_KEEP_CONFLICT_H      = 4343,
    BG_IC_ALLIANCE_KEEP_CONTROLLED_A    = 4339,
    BG_IC_ALLIANCE_KEEP_CONTROLLED_H    = 4340,

    BG_IC_HORDE_KEEP_UNCONTROLLED       = 4346,
    BG_IC_HORDE_KEEP_CONFLICT_A         = 4347,
    BG_IC_HORDE_KEEP_CONFLICT_H         = 4348,
    BG_IC_HORDE_KEEP_CONTROLLED_A       = 4344,
    BG_IC_HORDE_KEEP_CONTROLLED_H       = 4345
};

enum BG_IC_GateState
{
    BG_IC_GATE_OK           = 1,
    BG_IC_GATE_DAMAGED      = 2,
    BG_IC_GATE_DESTROYED    = 3
};

enum ICDoorList
{
    BG_IC_H_FRONT,
    BG_IC_H_WEST,
    BG_IC_H_EAST,
    BG_IC_A_FRONT,
    BG_IC_A_WEST,
    BG_IC_A_EAST,
    BG_IC_MAXDOOR
};

enum ICNodePointType
{
    NODE_TYPE_REFINERY,
    NODE_TYPE_QUARRY,
    NODE_TYPE_DOCKS,
    NODE_TYPE_HANGAR,
    NODE_TYPE_WORKSHOP,

    // Graveyards
    NODE_TYPE_GRAVEYARD_A,
    NODE_TYPE_GRAVEYARD_H,

    MAX_NODE_TYPES
};

enum class IsleOfConquestNodeState
{
    Neutral,
    ConflictA,
    ConflictH,
    ControlledA,
    ControlledH
};

Position const BG_IC_SpiritGuidePos[MAX_NODE_TYPES+2] =
{
    {0.0f, 0.0f, 0.0f, 0.0f},                     // no grave
    {0.0f, 0.0f, 0.0f, 0.0f},                     // no grave
    {629.57f, -279.83f, 11.33f, 0.0f},            // dock
    {780.729f, -1103.08f, 135.51f, 2.27f},        // hangar
    {775.74f, -652.77f, 9.31f, 4.27f},            // workshop
    {278.42f, -883.20f, 49.89f, 1.53f},           // alliance starting base
    {1300.91f, -834.04f, 48.91f, 1.69f},          // horde starting base
    {438.86f, -310.04f, 51.81f, 5.87f},           // last resort alliance
    {1148.65f, -1250.98f, 16.60f, 1.74f},         // last resort horde
};

enum ICBroadcastTexts
{
    BG_IC_TEXT_FRONT_GATE_HORDE_DESTROYED       = 35409,
    BG_IC_TEXT_FRONT_GATE_ALLIANCE_DESTROYED    = 35410,
    BG_IC_TEXT_WEST_GATE_HORDE_DESTROYED        = 35411,
    BG_IC_TEXT_WEST_GATE_ALLIANCE_DESTROYED     = 35412,
    BG_IC_TEXT_EAST_GATE_HORDE_DESTROYED        = 35413,
    BG_IC_TEXT_EAST_GATE_ALLIANCE_DESTROYED     = 35414
};

// I.E: Hangar, Quarry, Graveyards .. etc
struct IoCStaticNodeInfo
{
    ICNodePointType NodeType;

    struct
    {
        uint32 Assaulted;
        uint32 Defended;
        uint32 AllianceTaken;
        uint32 HordeTaken;
    } TextIds;

    struct
    {
        int32 Uncontrolled;
        int32 ConflictA;
        int32 ConflictH;
        int32 ControlledA;
        int32 ControlledH;
    } WorldStateIds;
};

class ICNodePoint
{
public:
    explicit ICNodePoint(IsleOfConquestNodeState state, IoCStaticNodeInfo const& nodeInfo) : _state(state), _nodeInfo(nodeInfo)
    {
        switch (state)
        {
            case IsleOfConquestNodeState::ControlledH:
                _lastControlled = TEAM_HORDE;
                break;
            case IsleOfConquestNodeState::ControlledA:
                _lastControlled = TEAM_ALLIANCE;
                break;
            case IsleOfConquestNodeState::ConflictA:
            case IsleOfConquestNodeState::ConflictH:
            case IsleOfConquestNodeState::Neutral:
                _lastControlled = TEAM_NEUTRAL;
                break;
        }
    }

    IsleOfConquestNodeState GetState() const { return _state; }

    bool IsContested() const
    {
        return _state == IsleOfConquestNodeState::ConflictA || _state == IsleOfConquestNodeState::ConflictH;
    }

    TeamId GetLastControlledTeam() const { return _lastControlled; }

    IoCStaticNodeInfo const& GetNodeInfo() const { return _nodeInfo; }

    void UpdateState(IsleOfConquestNodeState state)
    {
        switch (state)
        {
            case IsleOfConquestNodeState::ControlledA:
                _lastControlled = TEAM_ALLIANCE;
                break;
            case IsleOfConquestNodeState::ControlledH:
                _lastControlled = TEAM_HORDE;
                break;
            case IsleOfConquestNodeState::Neutral:
                _lastControlled = TEAM_NEUTRAL;
                break;
            case IsleOfConquestNodeState::ConflictA:
            case IsleOfConquestNodeState::ConflictH:
                break;
        }

        _state = state;
    }
private:
    IsleOfConquestNodeState _state;
    TeamId _lastControlled;
    IoCStaticNodeInfo _nodeInfo;
};

const IoCStaticNodeInfo nodePointInitial[MAX_NODE_TYPES] =
{
    { NODE_TYPE_REFINERY, { 35377, 35378, 35379, 35380 }, { BG_IC_REFINERY_UNCONTROLLED, BG_IC_REFINERY_CONFLICT_A, BG_IC_REFINERY_CONFLICT_H, BG_IC_REFINERY_CONTROLLED_A, BG_IC_REFINERY_CONTROLLED_H } },
    { NODE_TYPE_QUARRY, { 35373, 35374, 35375, 35376 }, { BG_IC_QUARRY_UNCONTROLLED, BG_IC_QUARRY_CONFLICT_A, BG_IC_QUARRY_CONFLICT_H, BG_IC_QUARRY_CONTROLLED_A, BG_IC_QUARRY_CONTROLLED_H } },
    { NODE_TYPE_DOCKS, { 35365, 35366, 35367, 35368 }, { BG_IC_DOCKS_UNCONTROLLED, BG_IC_DOCKS_CONFLICT_A, BG_IC_DOCKS_CONFLICT_H, BG_IC_DOCKS_CONTROLLED_A, BG_IC_DOCKS_CONTROLLED_H } },
    { NODE_TYPE_HANGAR, { 35369, 35370, 35371, 35372 }, { BG_IC_HANGAR_UNCONTROLLED, BG_IC_HANGAR_CONFLICT_A, BG_IC_HANGAR_CONFLICT_H, BG_IC_HANGAR_CONTROLLED_A, BG_IC_HANGAR_CONTROLLED_H } },
    { NODE_TYPE_WORKSHOP, { 35278, 35286, 35279, 35280 }, { BG_IC_WORKSHOP_UNCONTROLLED, BG_IC_WORKSHOP_CONFLICT_A, BG_IC_WORKSHOP_CONFLICT_H, BG_IC_WORKSHOP_CONTROLLED_A, BG_IC_WORKSHOP_CONTROLLED_H } },
    { NODE_TYPE_GRAVEYARD_A, { 35461, 35459, 35463, 35466 }, { BG_IC_ALLIANCE_KEEP_UNCONTROLLED, BG_IC_ALLIANCE_KEEP_CONFLICT_A, BG_IC_ALLIANCE_KEEP_CONFLICT_H, BG_IC_ALLIANCE_KEEP_CONTROLLED_A, BG_IC_ALLIANCE_KEEP_CONTROLLED_H } },
    { NODE_TYPE_GRAVEYARD_H, { 35462, 35460, 35464, 35465 }, { BG_IC_HORDE_KEEP_UNCONTROLLED, BG_IC_HORDE_KEEP_CONFLICT_A, BG_IC_HORDE_KEEP_CONFLICT_H, BG_IC_HORDE_KEEP_CONTROLLED_A, BG_IC_HORDE_KEEP_CONTROLLED_H } }
};

enum HonorRewards
{
    RESOURCE_HONOR_AMOUNT   = 12,
    WINNER_HONOR_AMOUNT     = 500
};

class BattlegroundIC : public Battleground
{
    public:
        BattlegroundIC(BattlegroundTemplate const* battlegroundTemplate);
        ~BattlegroundIC() override;

        /* inherited from BattlegroundClass */
        void StartingEventOpenDoors() override;
        void PostUpdateImpl(uint32 diff) override;

        void HandleKillUnit(Creature* unit, Unit* killer) override;
        void HandleKillPlayer(Player* player, Player* killer) override;

        WorldSafeLocsEntry const* GetExploitTeleportLocation(Team team) override;

        void OnCreatureCreate(Creature* creature) override;
        void OnGameObjectCreate(GameObject* gameobject) override;
        void OnMapSet(BattlegroundMap* map) override;

        void DoAction(uint32 actionId, WorldObject* source, WorldObject* target) override;
        void OnPlayerInteractWithBanner(Player* player, GameObject* banner);
        void OnPlayerAssaultNode(Player* player, ICNodePoint& node);
        void OnPlayerDefendNode(Player* player, ICNodePoint& node);
        void ProcessEvent(WorldObject* target, uint32 eventId, WorldObject* invoker) override;

    private:
        std::array<uint16, PVP_TEAMS_COUNT> _factionReinforcements;
        std::array<BG_IC_GateState, 6> _gateStatus;
        std::array<std::unique_ptr<ICNodePoint>, 7> _nodePoints;
        std::array<ObjectGuid, PVP_TEAMS_COUNT> _gunshipGUIDs;
        GuidVector _teleporterGUIDs;
        GuidVector _teleporterEffectGUIDs;
        GuidVector _mainGateDoorGUIDs;
        GuidVector _portcullisGUIDs;
        GuidVector _wallGUIDs;
        std::array<GuidVector, PVP_TEAMS_COUNT> _cannonGUIDs;
        std::array<GuidVector, PVP_TEAMS_COUNT> _keepGateGUIDs;
        std::array<ObjectGuid, PVP_TEAMS_COUNT> _keepBannerGUIDs;
        ObjectGuid _gunshipTeleportTarget;

        TaskScheduler _scheduler;
        TimeTracker _resourceTimer;

        static uint32 GetGateIDFromEntry(uint32 id);
        static int32 GetWorldStateFromGateEntry(uint32 id, bool open);

        void UpdateNodeWorldState(ICNodePoint const& node);
        void HandleCapturedNodes(ICNodePoint& node);
        void HandleCaptureNodeAction(GameObject* banner);
        void OnGateDestroyed(GameObject* gate, WorldObject* destroyer);

        static ICNodePointType BannerToNodeType(uint32 bannerId);
};

#endif
