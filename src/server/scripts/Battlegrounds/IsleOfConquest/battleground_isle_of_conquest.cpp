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

#include "BattlegroundScript.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "GameTime.h"
#include "isle_of_conquest.h"
#include "Map.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "TaskScheduler.h"
#include "TemporarySummon.h"
#include "Timer.h"
#include "Transport.h"
#include "TransportMgr.h"
#include "Vehicle.h"

inline constexpr uint16 MAX_REINFORCEMENTS = 400;

enum BannersTypes
{
    BANNER_A_CONTROLLED,
    BANNER_A_CONTESTED,
    BANNER_H_CONTROLLED,
    BANNER_H_CONTESTED
};

enum BG_IC_ExploitTeleportLocations
{
    IC_EXPLOIT_TELEPORT_LOCATION_ALLIANCE   = 3986,
    IC_EXPLOIT_TELEPORT_LOCATION_HORDE      = 3983
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
    RESOURCE_HONOR_AMOUNT = 12,
    WINNER_HONOR_AMOUNT = 500
};

enum IsleOfConquestPvpStats
{
    PVP_STAT_BASES_ASSAULTED = 245,
    PVP_STAT_BASES_DEFENDED = 246
};

enum IsleOfConquestGameObjects
{
    GO_TELEPORTER_1                             = 195314, // 195314 H-OUT 66549
    GO_TELEPORTER_2                             = 195313, // 195313 H-IN 66548

    GO_TELEPORTER_3                             = 195315, // 195315 A-OUT 66549
    GO_TELEPORTER_4                             = 195316, // 195316 A-IN 66548

    GO_TELEPORTER_EFFECTS_A                     = 195701,
    GO_TELEPORTER_EFFECTS_H                     = 195702,

    GO_DOODAD_HU_PORTCULLIS01                   = 195436,
    GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR01     = 195703,
    GO_DOODAD_PORTCULLISACTIVE02                = 195452,
    GO_DOODAD_VR_PORTCULLIS01                   = 195437,

    GO_HORDE_GATE_1                             = 195494,
    GO_HORDE_GATE_2                             = 195495,
    GO_HORDE_GATE_3                             = 195496,

    GO_ALLIANCE_GATE_1                          = 195699,
    GO_ALLIANCE_GATE_2                          = 195700,
    GO_ALLIANCE_GATE_3                          = 195698,

    GO_DOODAD_ND_WINTERORC_WALL_GATEFX_DOOR01   = 195491,

    // banners
    GO_BANNER_WORKSHOP_CONTROLLED_H             = 195130,
    GO_BANNER_WORKSHOP_CONTROLLED_A             = 195132,
    GO_BANNER_WORKSHOP_CONTROLLED_N             = 195133,
    GO_BANNER_WORKSHOP_CONTESTED_A              = 195144,
    GO_BANNER_WORKSHOP_CONTESTED_H              = 195145,

    GO_BANNER_DOCKS_CONTROLLED_A                = 195149,
    GO_BANNER_DOCKS_CONTESTED_A                 = 195150,
    GO_BANNER_DOCKS_CONTROLLED_H                = 195151,
    GO_BANNER_DOCKS_CONTESTED_H                 = 195152,
    GO_BANNER_DOCKS_CONTROLLED_N                = 195157,

    GO_BANNER_HANGAR_CONTROLLED_A               = 195153,
    GO_BANNER_HANGAR_CONTESTED_A                = 195154,
    GO_BANNER_HANGAR_CONTROLLED_H               = 195155,
    GO_BANNER_HANGAR_CONTESTED_H                = 195156,
    GO_BANNER_HANGAR_CONTROLLED_N               = 195158,

    GO_BANNER_QUARRY_CONTROLLED_A               = 195334,
    GO_BANNER_QUARRY_CONTROLLED_H               = 195336,
    GO_BANNER_QUARRY_CONTESTED_A                = 195335,
    GO_BANNER_QUARRY_CONTESTED_H                = 195337,
    GO_BANNER_QUARRY_CONTROLLED_N               = 195338,

    GO_BANNER_REFINERY_CONTROLLED_A             = 195339,
    GO_BANNER_REFINERY_CONTROLLED_H             = 195341,
    GO_BANNER_REFINERY_CONTESTED_A              = 195340,
    GO_BANNER_REFINERY_CONTESTED_H              = 195342,
    GO_BANNER_REFINERY_CONTROLLED_N             = 195343,

    GO_BANNER_HORDE_KEEP_CONTROLLED_A           = 195391,
    GO_BANNER_HORDE_KEEP_CONTROLLED_H           = 195393,
    GO_BANNER_HORDE_KEEP_CONTESTED_A            = 195392,
    GO_BANNER_HORDE_KEEP_CONTESTED_H            = 195394,

    GO_BANNER_ALLIANCE_KEEP_CONTROLLED_A        = 195396,
    GO_BANNER_ALLIANCE_KEEP_CONTROLLED_H        = 195398,
    GO_BANNER_ALLIANCE_KEEP_CONTESTED_A         = 195397,
    GO_BANNER_ALLIANCE_KEEP_CONTESTED_H         = 195399,

    GO_KEEP_GATE_H                              = 195223,
    GO_KEEP_GATE_A                              = 195451,
    GO_KEEP_GATE_2_A                            = 195452,

    GO_HORDE_GUNSHIP                            = 195276,
    GO_ALLIANCE_GUNSHIP                         = 195121
};

static constexpr Seconds IOC_RESOURCE_TIMER = 45s;

static constexpr Position GunshipTeleportTriggerPosition[2] =
{
    { 11.69964981079101562f, 0.034145999699831008f, 20.62075996398925781f, 3.211405754089355468f },
    { 7.30560922622680664f, -0.09524600207805633f, 34.51021575927734375f, 3.159045934677124023f }
};

struct battleground_isle_of_conquest : BattlegroundScript
{
    explicit battleground_isle_of_conquest(BattlegroundMap* map) : BattlegroundScript(map)
    {
        _factionReinforcements = { MAX_REINFORCEMENTS, MAX_REINFORCEMENTS };

        _gateStatus = { BG_IC_GATE_OK, BG_IC_GATE_OK, BG_IC_GATE_OK, BG_IC_GATE_OK, BG_IC_GATE_OK, BG_IC_GATE_OK };

        _gunshipGUIDs = { };
        _cannonGUIDs = { };
        _nodePoints = { };
        _keepGateGUIDs = { };
        _keepBannerGUIDs = { };

        _nodePoints[NODE_TYPE_REFINERY] = std::make_unique<ICNodePoint>(IsleOfConquestNodeState::Neutral, nodePointInitial[NODE_TYPE_REFINERY]);
        _nodePoints[NODE_TYPE_QUARRY] = std::make_unique<ICNodePoint>(IsleOfConquestNodeState::Neutral, nodePointInitial[NODE_TYPE_QUARRY]);
        _nodePoints[NODE_TYPE_DOCKS] = std::make_unique<ICNodePoint>(IsleOfConquestNodeState::Neutral, nodePointInitial[NODE_TYPE_DOCKS]);
        _nodePoints[NODE_TYPE_HANGAR] = std::make_unique<ICNodePoint>(IsleOfConquestNodeState::Neutral, nodePointInitial[NODE_TYPE_HANGAR]);
        _nodePoints[NODE_TYPE_WORKSHOP] = std::make_unique<ICNodePoint>(IsleOfConquestNodeState::Neutral, nodePointInitial[NODE_TYPE_WORKSHOP]);
        _nodePoints[NODE_TYPE_GRAVEYARD_A] = std::make_unique<ICNodePoint>(IsleOfConquestNodeState::ControlledA, nodePointInitial[NODE_TYPE_GRAVEYARD_A]);
        _nodePoints[NODE_TYPE_GRAVEYARD_H] = std::make_unique<ICNodePoint>(IsleOfConquestNodeState::ControlledH, nodePointInitial[NODE_TYPE_GRAVEYARD_H]);

        _resourceTimer.Reset(IOC_RESOURCE_TIMER);
    }

    void OnUpdate(uint32 diff) override
    {
        BattlegroundScript::OnUpdate(diff);

        if (battleground->GetStatus() != STATUS_IN_PROGRESS)
            return;

        _scheduler.Update(diff);
        _resourceTimer.Update(diff);
        if (_resourceTimer.Passed())
        {
            for (uint8 i = 0; i < NODE_TYPE_DOCKS; ++i)
            {
                if (_nodePoints[i]->GetLastControlledTeam() != TEAM_NEUTRAL && !_nodePoints[i]->IsContested())
                {
                    _factionReinforcements[_nodePoints[i]->GetLastControlledTeam()] += 1;
                    battleground->RewardHonorToTeam(RESOURCE_HONOR_AMOUNT, _nodePoints[i]->GetLastControlledTeam() == TEAM_ALLIANCE ? ALLIANCE : HORDE);
                    UpdateWorldState((_nodePoints[i]->GetLastControlledTeam() == TEAM_ALLIANCE ? BG_IC_ALLIANCE_REINFORCEMENTS : BG_IC_HORDE_REINFORCEMENTS), _factionReinforcements[_nodePoints[i]->GetLastControlledTeam()]);
                }
            }

            _resourceTimer.Reset(IOC_RESOURCE_TIMER);
        }
    }

    void OnStart() override
    {
        BattlegroundScript::OnStart();

        auto gameobjectAction = [&](GuidVector const& guids, std::function<void(GameObject*)> const& action) -> void
        {
            for (ObjectGuid const& guid : guids)
                if (GameObject* gameObject = battlegroundMap->GetGameObject(guid))
                    action(gameObject);
        };

        gameobjectAction(_mainGateDoorGUIDs, [&](GameObject* gameobject) -> void
        {
            gameobject->UseDoorOrButton();
            gameobject->DespawnOrUnsummon(20s);
        });

        gameobjectAction(_portcullisGUIDs, [&](GameObject* gameobject) -> void
        {
            gameobject->UseDoorOrButton();
        });

        gameobjectAction(_teleporterGUIDs, [&](GameObject* gameobject) -> void
        {
            gameobject->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
        });

        gameobjectAction(_teleporterEffectGUIDs, [&](GameObject* gameobject) -> void
        {
            gameobject->SetGoState(GO_STATE_ACTIVE);
        });

        _scheduler.Schedule(20s, [&](TaskContext)
        {
            for (ObjectGuid const& guid : _wallGUIDs)
                if (GameObject* gameobject = battlegroundMap->GetGameObject(guid))
                    gameobject->SetDestructibleState(GO_DESTRUCTIBLE_DAMAGED);
        });
    }

    void OnUnitKilled(Creature* unit, Unit* killer) override
    {
        BattlegroundScript::OnUnitKilled(unit, killer);

        if (battleground->GetStatus() != STATUS_IN_PROGRESS)
            return;

        uint32 entry = unit->GetEntry();
        if (entry == NPC_HIGH_COMMANDER_HALFORD_WYRMBANE)
        {
            battleground->RewardHonorToTeam(WINNER_HONOR_AMOUNT, HORDE);
            battleground->EndBattleground(HORDE);
        }
        else if (entry == NPC_OVERLORD_AGMAR)
        {
            battleground->RewardHonorToTeam(WINNER_HONOR_AMOUNT, ALLIANCE);
            battleground->EndBattleground(ALLIANCE);
        }

        //Achievement Mowed Down
        // TO-DO: This should be done on the script of each vehicle of the BG.
        if (unit->IsVehicle())
        {
            if (Player* killerPlayer = killer->GetCharmerOrOwnerPlayerOrPlayerItself())
                killerPlayer->CastSpell(killerPlayer, SPELL_DESTROYED_VEHICLE_ACHIEVEMENT, true);
        }
    }

    void OnPlayerKilled(Player* player, Player* killer) override
    {
        BattlegroundScript::OnPlayerKilled(player, killer);

        if (battleground->GetStatus() != STATUS_IN_PROGRESS)
            return;

        TeamId const victimTeamId = Battleground::GetTeamIndexByTeamId(battleground->GetPlayerTeam(player->GetGUID()));
        _factionReinforcements[victimTeamId] -= 1;

        UpdateWorldState((battleground->GetPlayerTeam(player->GetGUID()) == ALLIANCE ? BG_IC_ALLIANCE_REINFORCEMENTS : BG_IC_HORDE_REINFORCEMENTS), _factionReinforcements[victimTeamId]);

        // we must end the battleground
        if (_factionReinforcements[victimTeamId] < 1)
            battleground->EndBattleground(battleground->GetPlayerTeam(killer->GetGUID()));
    }

    static uint32 GetGateIDFromEntry(uint32 id)
    {
        switch (id)
        {
            case GO_HORDE_GATE_1:
                return BG_IC_H_FRONT;
            case GO_HORDE_GATE_2:
                return BG_IC_H_WEST;
            case GO_HORDE_GATE_3:
                return BG_IC_H_EAST;
            case GO_ALLIANCE_GATE_3:
                return BG_IC_A_FRONT;
            case GO_ALLIANCE_GATE_1:
                return BG_IC_A_WEST;
            case GO_ALLIANCE_GATE_2:
                return BG_IC_A_EAST;
            default:
                return 0;
        }
    }

    static int32 GetWorldStateFromGateEntry(uint32 id, bool open)
    {
        int32 uws = 0;

        switch (id)
        {
            case GO_HORDE_GATE_1:
                uws = (open ? BG_IC_GATE_FRONT_H_WS_OPEN : BG_IC_GATE_FRONT_H_WS_CLOSED);
                break;
            case GO_HORDE_GATE_2:
                uws = (open ? BG_IC_GATE_WEST_H_WS_OPEN : BG_IC_GATE_WEST_H_WS_CLOSED);
                break;
            case GO_HORDE_GATE_3:
                uws = (open ? BG_IC_GATE_EAST_H_WS_OPEN : BG_IC_GATE_EAST_H_WS_CLOSED);
                break;
            case GO_ALLIANCE_GATE_3:
                uws = (open ? BG_IC_GATE_FRONT_A_WS_OPEN : BG_IC_GATE_FRONT_A_WS_CLOSED);
                break;
            case GO_ALLIANCE_GATE_1:
                uws = (open ? BG_IC_GATE_WEST_A_WS_OPEN : BG_IC_GATE_WEST_A_WS_CLOSED);
                break;
            case GO_ALLIANCE_GATE_2:
                uws = (open ? BG_IC_GATE_EAST_A_WS_OPEN : BG_IC_GATE_EAST_A_WS_CLOSED);
                break;
            default:
                break;
        }
        return uws;
    }

    void UpdateNodeWorldState(ICNodePoint const& node) const
    {
        UpdateWorldState(node.GetNodeInfo().WorldStateIds.ConflictA, node.GetState() == IsleOfConquestNodeState::ConflictA);
        UpdateWorldState(node.GetNodeInfo().WorldStateIds.ConflictH, node.GetState() == IsleOfConquestNodeState::ConflictH);
        UpdateWorldState(node.GetNodeInfo().WorldStateIds.ControlledA, node.GetState() == IsleOfConquestNodeState::ControlledA);
        UpdateWorldState(node.GetNodeInfo().WorldStateIds.ControlledH, node.GetState() == IsleOfConquestNodeState::ControlledH);
        UpdateWorldState(node.GetNodeInfo().WorldStateIds.Uncontrolled, node.GetState() == IsleOfConquestNodeState::Neutral);
    }

    static ICNodePointType BannerToNodeType(uint32 bannerId)
    {
        switch (bannerId)
        {
            case GO_BANNER_ALLIANCE_KEEP_CONTESTED_A:
            case GO_BANNER_ALLIANCE_KEEP_CONTESTED_H:
            case GO_BANNER_ALLIANCE_KEEP_CONTROLLED_A:
            case GO_BANNER_ALLIANCE_KEEP_CONTROLLED_H:
                return NODE_TYPE_GRAVEYARD_A;
            case GO_BANNER_HORDE_KEEP_CONTESTED_A:
            case GO_BANNER_HORDE_KEEP_CONTESTED_H:
            case GO_BANNER_HORDE_KEEP_CONTROLLED_A:
            case GO_BANNER_HORDE_KEEP_CONTROLLED_H:
                return NODE_TYPE_GRAVEYARD_H;
            case GO_BANNER_DOCKS_CONTESTED_A:
            case GO_BANNER_DOCKS_CONTESTED_H:
            case GO_BANNER_DOCKS_CONTROLLED_A:
            case GO_BANNER_DOCKS_CONTROLLED_H:
            case GO_BANNER_DOCKS_CONTROLLED_N:
                return NODE_TYPE_DOCKS;
            case GO_BANNER_HANGAR_CONTESTED_A:
            case GO_BANNER_HANGAR_CONTESTED_H:
            case GO_BANNER_HANGAR_CONTROLLED_A:
            case GO_BANNER_HANGAR_CONTROLLED_H:
            case GO_BANNER_HANGAR_CONTROLLED_N:
                return NODE_TYPE_HANGAR;
            case GO_BANNER_WORKSHOP_CONTESTED_A:
            case GO_BANNER_WORKSHOP_CONTESTED_H:
            case GO_BANNER_WORKSHOP_CONTROLLED_A:
            case GO_BANNER_WORKSHOP_CONTROLLED_H:
            case GO_BANNER_WORKSHOP_CONTROLLED_N:
                return NODE_TYPE_WORKSHOP;
            case GO_BANNER_QUARRY_CONTESTED_A:
            case GO_BANNER_QUARRY_CONTESTED_H:
            case GO_BANNER_QUARRY_CONTROLLED_A:
            case GO_BANNER_QUARRY_CONTROLLED_H:
            case GO_BANNER_QUARRY_CONTROLLED_N:
                return NODE_TYPE_QUARRY;
            case GO_BANNER_REFINERY_CONTESTED_A:
            case GO_BANNER_REFINERY_CONTESTED_H:
            case GO_BANNER_REFINERY_CONTROLLED_A:
            case GO_BANNER_REFINERY_CONTROLLED_H:
            case GO_BANNER_REFINERY_CONTROLLED_N:
                return NODE_TYPE_REFINERY;
            default:
                break;
        }

        return MAX_NODE_TYPES;
    }

    void HandleCapturedNodes(ICNodePoint& node)
    {
        if (node.GetLastControlledTeam() == TEAM_NEUTRAL)
            return;

        switch (node.GetNodeInfo().NodeType)
        {
            case NODE_TYPE_QUARRY:
            case NODE_TYPE_REFINERY:
                battlegroundMap->UpdateAreaDependentAuras();
                break;
            case NODE_TYPE_HANGAR:
                if (Transport* transport = battlegroundMap->GetTransport(_gunshipGUIDs[node.GetLastControlledTeam()]))
                {
                    // Can't have this in spawngroup, creature is on a transport
                    if (TempSummon* trigger = transport->SummonPassenger(NPC_WORLD_TRIGGER_NOT_FLOATING, GunshipTeleportTriggerPosition[node.GetLastControlledTeam()], TEMPSUMMON_MANUAL_DESPAWN))
                        _gunshipTeleportTarget = trigger->GetGUID();

                    transport->EnableMovement(true);
                }

                for (ObjectGuid const& guid : _cannonGUIDs[node.GetLastControlledTeam()])
                    if (Creature* cannon = battlegroundMap->GetCreature(guid))
                        cannon->SetUninteractible(false);
                break;
            default:
                break;
        }
    }

    void OnCreatureCreate(Creature* creature) override
    {
        BattlegroundScript::OnCreatureCreate(creature);

        if (creature->HasStringId("bg_ioc_faction_1735"))
            creature->SetFaction(FACTION_HORDE_GENERIC_WG);
        else if (creature->HasStringId("bg_ioc_faction_1732"))
            creature->SetFaction(FACTION_ALLIANCE_GENERIC_WG);

        switch (creature->GetEntry())
        {
            case NPC_ALLIANCE_GUNSHIP_CANNON:
                _cannonGUIDs[TEAM_ALLIANCE].emplace_back(creature->GetGUID());
                creature->SetUninteractible(true);
                creature->SetControlled(true, UNIT_STATE_ROOT);
                break;
            case NPC_HORDE_GUNSHIP_CANNON:
                _cannonGUIDs[TEAM_HORDE].emplace_back(creature->GetGUID());
                creature->SetUninteractible(true);
                creature->SetControlled(true, UNIT_STATE_ROOT);
                break;
            default:
                break;
        }
    }

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        BattlegroundScript::OnGameObjectCreate(gameobject);

        if (gameobject->IsDestructibleBuilding())
            _wallGUIDs.emplace_back(gameobject->GetGUID());

        if (gameobject->HasStringId("bg_ioc_faction_1735"))
            gameobject->SetFaction(FACTION_HORDE_GENERIC_WG);
        else if (gameobject->HasStringId("bg_ioc_faction_1732"))
            gameobject->SetFaction(FACTION_ALLIANCE_GENERIC_WG);

        switch (gameobject->GetEntry())
        {
            case GO_TELEPORTER_1:
            case GO_TELEPORTER_2:
            case GO_TELEPORTER_3:
            case GO_TELEPORTER_4:
                _teleporterGUIDs.emplace_back(gameobject->GetGUID());
                break;
            case GO_TELEPORTER_EFFECTS_A:
            case GO_TELEPORTER_EFFECTS_H:
                _teleporterEffectGUIDs.emplace_back(gameobject->GetGUID());
                break;
            case GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR01:
            case GO_DOODAD_ND_WINTERORC_WALL_GATEFX_DOOR01:
                _mainGateDoorGUIDs.emplace_back(gameobject->GetGUID());
                break;
            case GO_DOODAD_HU_PORTCULLIS01:
            case GO_DOODAD_VR_PORTCULLIS01:
                _portcullisGUIDs.emplace_back(gameobject->GetGUID());
                break;
            case GO_KEEP_GATE_H:
                _keepGateGUIDs[TEAM_HORDE].emplace_back(gameobject->GetGUID());
                break;
            case GO_KEEP_GATE_A:
            case GO_KEEP_GATE_2_A:
                _keepGateGUIDs[TEAM_ALLIANCE].emplace_back(gameobject->GetGUID());
                break;
            case GO_BANNER_ALLIANCE_KEEP_CONTROLLED_A:
                _keepBannerGUIDs[TEAM_ALLIANCE] = gameobject->GetGUID();
                break;
            case GO_BANNER_HORDE_KEEP_CONTROLLED_H:
                _keepBannerGUIDs[TEAM_HORDE] = gameobject->GetGUID();
                break;
            default:
                break;
        }
    }

    void OnInit() override
    {
        BattlegroundScript::OnInit();

        if (Transport* transport = sTransportMgr->CreateTransport(GO_HORDE_GUNSHIP, battlegroundMap))
        {
            _gunshipGUIDs[TEAM_HORDE] = transport->GetGUID();
            transport->EnableMovement(false);
        }

        if (Transport* transport = sTransportMgr->CreateTransport(GO_ALLIANCE_GUNSHIP, battlegroundMap))
        {
            _gunshipGUIDs[TEAM_ALLIANCE] = transport->GetGUID();
            transport->EnableMovement(false);
        }
    }

    void DoAction(uint32 actionId, WorldObject* source, WorldObject* target) override
    {
        BattlegroundScript::DoAction(actionId, source, target);

        switch (actionId)
        {
            case ACTION_IOC_INTERACT_CAPTURABLE_OBJECT:
                OnPlayerInteractWithBanner(WorldObject::ToPlayer(source), WorldObject::ToGameObject(target));
                break;
            case ACTION_IOC_CAPTURE_CAPTURABLE_OBJECT:
                HandleCaptureNodeAction(WorldObject::ToGameObject(target));
                break;
            default:
                break;
        }
    }

    void OnPlayerInteractWithBanner(Player* player, GameObject* banner)
    {
        if (!player || !banner)
            return;

        Team const playerTeam = battleground->GetPlayerTeam(player->GetGUID());
        TeamId const playerTeamId = Battleground::GetTeamIndexByTeamId(playerTeam);
        ICNodePointType const nodeType = BannerToNodeType(banner->GetEntry());
        if (nodeType == MAX_NODE_TYPES)
            return;

        ICNodePoint& node = *_nodePoints[nodeType];

        bool assault = false;
        bool defend = false;

        switch (node.GetState())
        {
            case IsleOfConquestNodeState::Neutral:
                assault = true;
                break;
            case IsleOfConquestNodeState::ControlledH:
                assault = playerTeamId != TEAM_HORDE;
                break;
            case IsleOfConquestNodeState::ControlledA:
                assault = playerTeamId != TEAM_ALLIANCE;
                break;
            case IsleOfConquestNodeState::ConflictA:
                defend = playerTeamId == node.GetLastControlledTeam();
                assault = !defend && playerTeamId == TEAM_HORDE;
                break;
            case IsleOfConquestNodeState::ConflictH:
                defend = playerTeamId == node.GetLastControlledTeam();
                assault = !defend && playerTeamId == TEAM_ALLIANCE;
                break;
        }

        if (assault)
            OnPlayerAssaultNode(player, node);
        else if (defend)
            OnPlayerDefendNode(player, node);

        battlegroundMap->UpdateSpawnGroupConditions();
    }

    void OnPlayerAssaultNode(Player* player, ICNodePoint& node)
    {
        if (!player)
            return;

        Team const playerTeam = battleground->GetPlayerTeam(player->GetGUID());
        TeamId const playerTeamId = Battleground::GetTeamIndexByTeamId(playerTeam);

        IsleOfConquestNodeState const newState = playerTeamId == TEAM_HORDE ? IsleOfConquestNodeState::ConflictH : IsleOfConquestNodeState::ConflictA;
        node.UpdateState(newState);

        battleground->UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);

        ChatMsg const messageType = playerTeamId == TEAM_ALLIANCE ? CHAT_MSG_BG_SYSTEM_ALLIANCE : CHAT_MSG_BG_SYSTEM_HORDE;
        battleground->SendBroadcastText(node.GetNodeInfo().TextIds.Assaulted, messageType, player);
        UpdateNodeWorldState(node);

        // apply side effects of each node, only if it wasn't neutral before
        if (node.GetLastControlledTeam() == TEAM_NEUTRAL)
            return;

        switch (node.GetNodeInfo().NodeType)
        {
            case NODE_TYPE_HANGAR:
                if (Transport* transport = battlegroundMap->GetTransport(_gunshipGUIDs[node.GetLastControlledTeam()]))
                    transport->EnableMovement(false);

                for (ObjectGuid const& guid : _cannonGUIDs[node.GetLastControlledTeam()])
                {
                    if (Creature* cannon = battlegroundMap->GetCreature(guid))
                    {
                        cannon->GetVehicleKit()->RemoveAllPassengers();
                        cannon->SetUninteractible(true);
                    }
                }

                // Despawn teleport trigger target
                if (Creature* creature = battlegroundMap->GetCreature(_gunshipTeleportTarget))
                    creature->DespawnOrUnsummon();
                break;
            default:
                break;
        }
    }

    void OnPlayerDefendNode(Player* player, ICNodePoint& node)
    {
        if (!player)
            return;

        Team const playerTeam = battleground->GetPlayerTeam(player->GetGUID());
        TeamId const playerTeamId = Battleground::GetTeamIndexByTeamId(playerTeam);

        node.UpdateState(playerTeamId == TEAM_HORDE ? IsleOfConquestNodeState::ControlledH : IsleOfConquestNodeState::ControlledA);
        HandleCapturedNodes(node);
        battleground->UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);

        ChatMsg const messageType = playerTeamId == TEAM_ALLIANCE ? CHAT_MSG_BG_SYSTEM_ALLIANCE : CHAT_MSG_BG_SYSTEM_HORDE;
        battleground->SendBroadcastText(node.GetNodeInfo().TextIds.Defended, messageType, player);
        UpdateNodeWorldState(node);
    }

    void ProcessEvent(WorldObject* target, uint32 eventId, WorldObject* invoker) override
    {
        BattlegroundScript::ProcessEvent(target, eventId, invoker);

        if (GameObject* obj = Object::ToGameObject(target))
            if (obj->GetGoType() == GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING)
                if (obj->GetGOInfo()->destructibleBuilding.DestroyedEvent == eventId)
                    OnGateDestroyed(obj, invoker);
    }

    void HandleCaptureNodeAction(GameObject* banner)
    {
        if (!banner)
            return;

        ICNodePointType const nodeType = BannerToNodeType(banner->GetEntry());
        if (nodeType == MAX_NODE_TYPES)
            return;

        ICNodePoint& node = *_nodePoints[nodeType];
        if (node.GetState() == IsleOfConquestNodeState::ConflictH)
            node.UpdateState(IsleOfConquestNodeState::ControlledH);
        else if (node.GetState() == IsleOfConquestNodeState::ConflictA)
            node.UpdateState(IsleOfConquestNodeState::ControlledA);

        HandleCapturedNodes(node);

        ChatMsg const messageType = node.GetLastControlledTeam() == TEAM_ALLIANCE ? CHAT_MSG_BG_SYSTEM_ALLIANCE : CHAT_MSG_BG_SYSTEM_HORDE;
        uint32 const textId = node.GetLastControlledTeam() == TEAM_ALLIANCE ? node.GetNodeInfo().TextIds.AllianceTaken : node.GetNodeInfo().TextIds.HordeTaken;
        battleground->SendBroadcastText(textId, messageType);
        UpdateNodeWorldState(node);
    }

    void OnGateDestroyed(GameObject* gate, WorldObject* destroyer)
    {
        _gateStatus[GetGateIDFromEntry(gate->GetEntry())] = BG_IC_GATE_DESTROYED;
        int32 const wsGateOpen = GetWorldStateFromGateEntry(gate->GetEntry(), true);
        int32 const wsGateClosed = GetWorldStateFromGateEntry(gate->GetEntry(), false);
        if (wsGateOpen)
        {
            UpdateWorldState(wsGateClosed, 0);
            UpdateWorldState(wsGateOpen, 1);
        }

        TeamId teamId = TEAM_NEUTRAL;
        uint32 textId;
        ChatMsg msgType;
        switch (gate->GetEntry())
        {
            case GO_HORDE_GATE_1:
                textId = BG_IC_TEXT_FRONT_GATE_HORDE_DESTROYED;
                msgType = CHAT_MSG_BG_SYSTEM_ALLIANCE;
                teamId = TEAM_HORDE;
                break;
            case GO_HORDE_GATE_2:
                textId = BG_IC_TEXT_WEST_GATE_HORDE_DESTROYED;
                msgType = CHAT_MSG_BG_SYSTEM_ALLIANCE;
                teamId = TEAM_HORDE;
                break;
            case GO_HORDE_GATE_3:
                textId = BG_IC_TEXT_EAST_GATE_HORDE_DESTROYED;
                msgType = CHAT_MSG_BG_SYSTEM_ALLIANCE;
                teamId = TEAM_HORDE;
                break;
            case GO_ALLIANCE_GATE_1:
                textId = BG_IC_TEXT_WEST_GATE_ALLIANCE_DESTROYED;
                msgType = CHAT_MSG_BG_SYSTEM_HORDE;
                teamId = TEAM_ALLIANCE;
                break;
            case GO_ALLIANCE_GATE_2:
                textId = BG_IC_TEXT_EAST_GATE_ALLIANCE_DESTROYED;
                msgType = CHAT_MSG_BG_SYSTEM_HORDE;
                teamId = TEAM_ALLIANCE;
                break;
            case GO_ALLIANCE_GATE_3:
                textId = BG_IC_TEXT_FRONT_GATE_ALLIANCE_DESTROYED;
                msgType = CHAT_MSG_BG_SYSTEM_HORDE;
                teamId = TEAM_ALLIANCE;
                break;
            default:
                return;
        }

        if (teamId != TEAM_NEUTRAL)
        {
            GuidVector const keepGates = _keepGateGUIDs[teamId];
            ObjectGuid const bannerGuid = _keepBannerGUIDs[teamId];

            for (ObjectGuid const& guid : keepGates)
                if (GameObject* keepGate = battlegroundMap->GetGameObject(guid))
                    keepGate->UseDoorOrButton();

            if (GameObject* banner = battlegroundMap->GetGameObject(bannerGuid))
                banner->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
        }

        battleground->SendBroadcastText(textId, msgType, destroyer);
    }

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
};

void AddSC_battleground_isle_of_conquest()
{
    RegisterBattlegroundMapScript(battleground_isle_of_conquest, 628);
}
