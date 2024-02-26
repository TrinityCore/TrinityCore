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

#include "BattlegroundIC.h"
#include "Creature.h"
#include "GameObject.h"
#include "Log.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "TemporarySummon.h"
#include "Transport.h"
#include "UnitAI.h"
#include "Vehicle.h"

enum IsleOfConquestPvpStats
{
    PVP_STAT_BASES_ASSAULTED    = 245,
    PVP_STAT_BASES_DEFENDED     = 246
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

Position const GunshipTeleportTriggerPosition[2] =
{
    { 11.69964981079101562f, 0.034145999699831008f, 20.62075996398925781f, 3.211405754089355468f },
    { 7.30560922622680664f, -0.09524600207805633f, 34.51021575927734375f, 3.159045934677124023f }
};

BattlegroundIC::BattlegroundIC(BattlegroundTemplate const* battlegroundTemplate) : Battleground(battlegroundTemplate)
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

BattlegroundIC::~BattlegroundIC() = default;

void BattlegroundIC::PostUpdateImpl(uint32 diff)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
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
                RewardHonorToTeam(RESOURCE_HONOR_AMOUNT, _nodePoints[i]->GetLastControlledTeam() == TEAM_ALLIANCE ? ALLIANCE : HORDE);
                UpdateWorldState((_nodePoints[i]->GetLastControlledTeam() == TEAM_ALLIANCE ? BG_IC_ALLIANCE_REINFORCEMENTS : BG_IC_HORDE_REINFORCEMENTS), _factionReinforcements[_nodePoints[i]->GetLastControlledTeam()]);
            }
        }

        _resourceTimer.Reset(IOC_RESOURCE_TIMER);
    }
}

void BattlegroundIC::StartingEventOpenDoors()
{
    auto gameobjectAction = [&](GuidVector const& guids, std::function<void(GameObject*)> const& action) -> void
    {
        for (ObjectGuid const& guid : guids)
            if (GameObject* gameObject = GetBgMap()->GetGameObject(guid))
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
            if (GameObject* gameobject = GetBgMap()->GetGameObject(guid))
                gameobject->SetDestructibleState(GO_DESTRUCTIBLE_DAMAGED);
    });
}

void BattlegroundIC::HandleKillUnit(Creature* unit, Unit* killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
       return;

    uint32 entry = unit->GetEntry();
    if (entry == NPC_HIGH_COMMANDER_HALFORD_WYRMBANE)
    {
        RewardHonorToTeam(WINNER_HONOR_AMOUNT, HORDE);
        EndBattleground(HORDE);
    }
    else if (entry == NPC_OVERLORD_AGMAR)
    {
        RewardHonorToTeam(WINNER_HONOR_AMOUNT, ALLIANCE);
        EndBattleground(ALLIANCE);
    }

    //Achievement Mowed Down
    // TO-DO: This should be done on the script of each vehicle of the BG.
    if (unit->IsVehicle())
    {
        if (Player* killerPlayer = killer->GetCharmerOrOwnerPlayerOrPlayerItself())
            killerPlayer->CastSpell(killerPlayer, SPELL_DESTROYED_VEHICLE_ACHIEVEMENT, true);
    }
}

void BattlegroundIC::HandleKillPlayer(Player* player, Player* killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    Battleground::HandleKillPlayer(player, killer);

    TeamId const victimTeamId = GetTeamIndexByTeamId(GetPlayerTeam(player->GetGUID()));
    _factionReinforcements[victimTeamId] -= 1;

    UpdateWorldState((GetPlayerTeam(player->GetGUID()) == ALLIANCE ? BG_IC_ALLIANCE_REINFORCEMENTS : BG_IC_HORDE_REINFORCEMENTS), _factionReinforcements[victimTeamId]);

    // we must end the battleground
    if (_factionReinforcements[victimTeamId] < 1)
        EndBattleground(GetPlayerTeam(killer->GetGUID()));
}

uint32 BattlegroundIC::GetGateIDFromEntry(uint32 id)
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

int32 BattlegroundIC::GetWorldStateFromGateEntry(uint32 id, bool open)
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

void BattlegroundIC::UpdateNodeWorldState(ICNodePoint const& node)
{
    UpdateWorldState(node.GetNodeInfo().WorldStateIds.ConflictA, node.GetState() == IsleOfConquestNodeState::ConflictA);
    UpdateWorldState(node.GetNodeInfo().WorldStateIds.ConflictH, node.GetState() == IsleOfConquestNodeState::ConflictH);
    UpdateWorldState(node.GetNodeInfo().WorldStateIds.ControlledA, node.GetState() == IsleOfConquestNodeState::ControlledA);
    UpdateWorldState(node.GetNodeInfo().WorldStateIds.ControlledH, node.GetState() == IsleOfConquestNodeState::ControlledH);
    UpdateWorldState(node.GetNodeInfo().WorldStateIds.Uncontrolled, node.GetState() == IsleOfConquestNodeState::Neutral);
}

ICNodePointType BattlegroundIC::BannerToNodeType(uint32 bannerId)
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

void BattlegroundIC::HandleCapturedNodes(ICNodePoint& node)
{
    if (node.GetLastControlledTeam() == TEAM_NEUTRAL)
        return;

    switch (node.GetNodeInfo().NodeType)
    {
        case NODE_TYPE_QUARRY:
        case NODE_TYPE_REFINERY:
            GetBgMap()->UpdateAreaDependentAuras();
            break;
        case NODE_TYPE_HANGAR:
            if (Transport* transport = GetBgMap()->GetTransport(_gunshipGUIDs[node.GetLastControlledTeam()]))
            {
                // Can't have this in spawngroup, creature is on a transport
                if (TempSummon* trigger = transport->SummonPassenger(NPC_WORLD_TRIGGER_NOT_FLOATING, GunshipTeleportTriggerPosition[node.GetLastControlledTeam()], TEMPSUMMON_MANUAL_DESPAWN))
                    _gunshipTeleportTarget = trigger->GetGUID();

                transport->EnableMovement(true);
            }

            for (ObjectGuid const& guid : _cannonGUIDs[node.GetLastControlledTeam()])
                if (Creature* cannon = GetBgMap()->GetCreature(guid))
                    cannon->SetUninteractible(false);
            break;
        default:
            break;
    }
}

WorldSafeLocsEntry const* BattlegroundIC::GetExploitTeleportLocation(Team team)
{
    return sObjectMgr->GetWorldSafeLoc(team == ALLIANCE ? IC_EXPLOIT_TELEPORT_LOCATION_ALLIANCE : IC_EXPLOIT_TELEPORT_LOCATION_HORDE);
}

void BattlegroundIC::OnCreatureCreate(Creature* creature)
{
    Battleground::OnCreatureCreate(creature);
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

void BattlegroundIC::OnGameObjectCreate(GameObject* gameobject)
{
    Battleground::OnGameObjectCreate(gameobject);

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

void BattlegroundIC::OnMapSet(BattlegroundMap* map)
{
    Battleground::OnMapSet(map);

    if (Transport* transport = sTransportMgr->CreateTransport(GO_HORDE_GUNSHIP, map))
    {
        _gunshipGUIDs[TEAM_HORDE] = transport->GetGUID();
        transport->EnableMovement(false);
    }

    if (Transport* transport = sTransportMgr->CreateTransport(GO_ALLIANCE_GUNSHIP, map))
    {
        _gunshipGUIDs[TEAM_ALLIANCE] = transport->GetGUID();
        transport->EnableMovement(false);
    }
}

void BattlegroundIC::DoAction(uint32 actionId, WorldObject* source, WorldObject* target)
{

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

void BattlegroundIC::OnPlayerInteractWithBanner(Player* player, GameObject* banner)
{
    if (!player || !banner)
        return;

    Team const playerTeam = GetPlayerTeam(player->GetGUID());
    TeamId const playerTeamId = GetTeamIndexByTeamId(playerTeam);
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

    GetBgMap()->UpdateSpawnGroupConditions();
}

void BattlegroundIC::OnPlayerAssaultNode(Player* player, ICNodePoint& node)
{
    if (!player)
        return;

    Team const playerTeam = GetPlayerTeam(player->GetGUID());
    TeamId const playerTeamId = GetTeamIndexByTeamId(playerTeam);

    IsleOfConquestNodeState const newState = playerTeamId == TEAM_HORDE ? IsleOfConquestNodeState::ConflictH : IsleOfConquestNodeState::ConflictA;
    node.UpdateState(newState);

    UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);

    ChatMsg const messageType = playerTeamId == TEAM_ALLIANCE ? CHAT_MSG_BG_SYSTEM_ALLIANCE : CHAT_MSG_BG_SYSTEM_HORDE;
    SendBroadcastText(node.GetNodeInfo().TextIds.Assaulted, messageType, player);
    UpdateNodeWorldState(node);

    // apply side effects of each node, only if it wasn't neutral before
    if (node.GetLastControlledTeam() == TEAM_NEUTRAL)
        return;

    switch (node.GetNodeInfo().NodeType)
    {
        case NODE_TYPE_HANGAR:
            if (Transport* transport = GetBgMap()->GetTransport(_gunshipGUIDs[node.GetLastControlledTeam()]))
                transport->EnableMovement(false);

            for (ObjectGuid const& guid : _cannonGUIDs[node.GetLastControlledTeam()])
            {
                if (Creature* cannon = GetBgMap()->GetCreature(guid))
                {
                    cannon->GetVehicleKit()->RemoveAllPassengers();
                    cannon->SetUninteractible(true);
                }
            }

            // Despawn teleport trigger target
            if (Creature* creature = FindBgMap()->GetCreature(_gunshipTeleportTarget))
                creature->DespawnOrUnsummon();
            break;
        default:
            break;
    }
}

void BattlegroundIC::OnPlayerDefendNode(Player* player, ICNodePoint& node)
{
    if (!player)
        return;

    Team const playerTeam = GetPlayerTeam(player->GetGUID());
    TeamId const playerTeamId = GetTeamIndexByTeamId(playerTeam);

    node.UpdateState(playerTeamId == TEAM_HORDE ? IsleOfConquestNodeState::ControlledH : IsleOfConquestNodeState::ControlledA);
    HandleCapturedNodes(node);
    UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);

    ChatMsg const messageType = playerTeamId == TEAM_ALLIANCE ? CHAT_MSG_BG_SYSTEM_ALLIANCE : CHAT_MSG_BG_SYSTEM_HORDE;
    SendBroadcastText(node.GetNodeInfo().TextIds.Defended, messageType, player);
    UpdateNodeWorldState(node);
}

void BattlegroundIC::ProcessEvent(WorldObject* target, uint32 eventId, WorldObject* invoker)
{
    Battleground::ProcessEvent(target, eventId, invoker);

    if (GameObject* obj = Object::ToGameObject(target))
        if (obj->GetGoType() == GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING)
            if (obj->GetGOInfo()->destructibleBuilding.DestroyedEvent == eventId)
                OnGateDestroyed(obj, invoker);
}

void BattlegroundIC::HandleCaptureNodeAction(GameObject* banner)
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
    SendBroadcastText(textId, messageType);
    UpdateNodeWorldState(node);
}

void BattlegroundIC::OnGateDestroyed(GameObject* gate, WorldObject* destroyer)
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
            if (GameObject* keepGate = GetBgMap()->GetGameObject(guid))
                keepGate->UseDoorOrButton();

        if (GameObject* banner = GetBgMap()->GetGameObject(bannerGuid))
            banner->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
    }

    SendBroadcastText(textId, msgType, destroyer);
}
