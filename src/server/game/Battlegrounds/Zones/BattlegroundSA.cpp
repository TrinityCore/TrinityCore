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

#include "BattlegroundSA.h"
#include "BattlegroundScore.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "DB2Stores.h"
#include "GameObject.h"
#include "GameTime.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Random.h"
#include "UpdateData.h"
#include "WorldStateMgr.h"

enum StrandOfTheAncientsPvpStats
{
    PVP_STAT_GATES_DESTROYED        = 231,
    PVP_STAT_DEMOLISHERS_DESTROYED  = 232
};

enum StrandOfTheAncientsEvents
{
    EVENT_HORDE_ASSAULT_STARTED     = 21702,
    EVENT_ALLIANCE_ASSAULT_STARTED  = 23748,
    EVENT_TITAN_RELIC_ACTIVATED     = 20572
};

enum StrandOfTheAncientsCreatures
{
    NPC_KANRETHAD               = 29,
    NPC_DEMOLISHER              = 28781,
    NPC_ANTIPERSONNEL_CANNON    = 27894,
    NPC_RIGGER_SPARKLIGHT       = 29260,
    NPC_GORGRIL_RIGSPARK        = 29262,
    NPC_WORLD_TRIGGER           = 22515,
    NPC_DEMOLISHER_SA           = 28781
};

enum StrandOfTheAncientsSpawnPositions
{
    SPAWN_DEFENDERS = 1399
};

enum StrandOfTheAncientsData
{
    DATA_ATTACKERS  = 1,
    DATA_STATUS     = 2
};

enum StrandOfTheAncientSpells
{
    SPELL_TELEPORT_DEFENDER                 = 52364,
    SPELL_TELEPORT_ATTACKERS                = 60178,
    SPELL_END_OF_ROUND                      = 52459,
    SPELL_REMOVE_SEAFORIUM                  = 59077,
    SPELL_ALLIANCE_CONTROL_PHASE_SHIFT      = 60027,
    SPELL_HORDE_CONTROL_PHASE_SHIFT         = 60028,
    SPELL_CARRYING_SEAFORIUM_CHARGE         = 52415
};

Position const spawnPositionOnTransport[] =
{
    { 0.0f, 5.0f, 9.6f, 3.14f },
    { -6.0f, -3.0f, 8.6f, 0.0f }
};

BattlegroundSA::BattlegroundSA(BattlegroundTemplate const* battlegroundTemplate) : Battleground(battlegroundTemplate)
{
    StartMessageIds[BG_STARTING_EVENT_FOURTH] = 0; // handle by Kanrethad

    BgObjects.resize(0);
    BgCreatures.resize(0);
    TimerEnabled = false;
    UpdateWaitTimer = 0;
    SignaledRoundTwo = false;
    SignaledRoundTwoHalfMin = false;
    InitSecondRound = false;
    Attackers = static_cast<TeamId>(urand(TEAM_ALLIANCE, TEAM_HORDE));
    TotalTime = 0;
    EndRoundTimer = 0;
    ShipsStarted = false;
    Status = BG_SA_NOT_STARTED;

    for (BG_SA_RoundScore& roundScore : RoundScores)
    {
        roundScore.winner = TEAM_ALLIANCE;
        roundScore.time = 0;
    }

    _boatGUIDs = { };
    _staticBombGUIDs = { };
}

BattlegroundSA::~BattlegroundSA() = default;

void BattlegroundSA::Reset()
{
    TotalTime = 0;
    ShipsStarted = false;
    Status = BG_SA_WARMUP;
}

bool BattlegroundSA::SetupBattleground()
{
    return true;
}

bool BattlegroundSA::ResetObjs()
{
    for (ObjectGuid const& bombGuid : _dynamicBombGUIDs)
        if (GameObject* bomb = GetBgMap()->GetGameObject(bombGuid))
            bomb->Delete();

    _dynamicBombGUIDs.clear();

    TeamId const defenders = Attackers == TEAM_ALLIANCE ? TEAM_HORDE : TEAM_ALLIANCE;

    TotalTime = 0;
    ShipsStarted = false;

    UpdateWorldState(BG_SA_ALLY_ATTACKS, Attackers == TEAM_ALLIANCE);
    UpdateWorldState(BG_SA_HORDE_ATTACKS, Attackers == TEAM_HORDE);

    UpdateWorldState(BG_SA_RIGHT_ATT_TOKEN_ALL, Attackers == TEAM_ALLIANCE);
    UpdateWorldState(BG_SA_LEFT_ATT_TOKEN_ALL, Attackers == TEAM_ALLIANCE);

    UpdateWorldState(BG_SA_RIGHT_ATT_TOKEN_HRD, Attackers == TEAM_HORDE);
    UpdateWorldState(BG_SA_LEFT_ATT_TOKEN_HRD, Attackers == TEAM_HORDE);

    UpdateWorldState(BG_SA_HORDE_DEFENCE_TOKEN, defenders == TEAM_HORDE);
    UpdateWorldState(BG_SA_ALLIANCE_DEFENCE_TOKEN, defenders == TEAM_ALLIANCE);

    CaptureGraveyard(StrandOfTheAncientsGraveyard::Central, defenders);
    CaptureGraveyard(StrandOfTheAncientsGraveyard::West, defenders);
    CaptureGraveyard(StrandOfTheAncientsGraveyard::East, defenders);

    UpdateWorldState(BG_SA_ATTACKER_TEAM, Attackers);

    for (ObjectGuid const& guid : _gateGUIDs)
        if (GameObject* gate = GetBgMap()->GetGameObject(guid))
            gate->SetDestructibleState(GO_DESTRUCTIBLE_INTACT, nullptr, true);

    BG_SA_GateState const state = Attackers == TEAM_ALLIANCE ? BG_SA_HORDE_GATE_OK : BG_SA_ALLIANCE_GATE_OK;
    UpdateWorldState(BG_SA_PURPLE_GATEWS, state);
    UpdateWorldState(BG_SA_RED_GATEWS, state);
    UpdateWorldState(BG_SA_BLUE_GATEWS, state);
    UpdateWorldState(BG_SA_GREEN_GATEWS, state);
    UpdateWorldState(BG_SA_YELLOW_GATEWS, state);
    UpdateWorldState(BG_SA_ANCIENT_GATEWS, state);

    GetBgMap()->UpdateSpawnGroupConditions();

    if (GameObject* door = GetBgMap()->GetGameObject(_collisionDoorGUID))
        door->ResetDoorOrButton();

    SetStatus(STATUS_WAIT_JOIN);
    GetBgMap()->DoOnPlayers([&](Player* player)
    {
        SendTransportInit(player);
    });

    TeleportPlayers();
    return true;
}

void BattlegroundSA::StartShips()
{
    if (ShipsStarted)
        return;

    for (ObjectGuid const& guid : _boatGUIDs[Attackers])
    {
        if (GameObject* boat = GetBgMap()->GetGameObject(guid))
        {
            boat->SetGoState(GO_STATE_TRANSPORT_STOPPED);

            // make sure every player knows the transport exists & is moving
            for (auto const& [playerGuid, _] : GetPlayers())
            {
                if (Player const* player = ObjectAccessor::FindPlayer(playerGuid))
                {
                    UpdateData data(player->GetMapId());
                    WorldPacket pkt;
                    boat->BuildValuesUpdateBlockForPlayer(&data, player);
                    data.BuildPacket(&pkt);
                    player->SendDirectMessage(&pkt);
                }
            }
        }
    }

    ShipsStarted = true;
}

void BattlegroundSA::PostUpdateImpl(uint32 diff)
{
    if (InitSecondRound)
    {
        if (UpdateWaitTimer < diff)
        {
            if (!SignaledRoundTwo)
            {
                SignaledRoundTwo = true;
                InitSecondRound = false;
                SendBroadcastText(BG_SA_TEXT_ROUND_TWO_START_ONE_MINUTE, CHAT_MSG_BG_SYSTEM_NEUTRAL);
            }
        }
        else
        {
            UpdateWaitTimer -= diff;
            return;
        }
    }
    TotalTime += diff;

    if (Status == BG_SA_WARMUP)
    {
        EndRoundTimer = BG_SA_ROUNDLENGTH;
        UpdateWorldState(BG_SA_TIMER, GameTime::GetGameTime() + (EndRoundTimer / 1000));
        if (TotalTime >= BG_SA_WARMUPLENGTH)
        {
            if (Creature* c = FindKanrethad())
                SendChatMessage(c, TEXT_ROUND_STARTED);

            TotalTime = 0;
            ToggleTimer();
            Status = BG_SA_ROUND_ONE;
            TriggerGameEvent((Attackers == TEAM_ALLIANCE) ? EVENT_ALLIANCE_ASSAULT_STARTED : EVENT_HORDE_ASSAULT_STARTED);
        }
        if (TotalTime >= BG_SA_BOAT_START)
            StartShips();
        return;
    }
    else if (Status == BG_SA_SECOND_WARMUP)
    {
        if (RoundScores[0].time<BG_SA_ROUNDLENGTH)
            EndRoundTimer = RoundScores[0].time;
        else
            EndRoundTimer = BG_SA_ROUNDLENGTH;

        UpdateWorldState(BG_SA_TIMER, GameTime::GetGameTime() + (EndRoundTimer / 1000));
        if (TotalTime >= 60000)
        {
            if (Creature* c = FindKanrethad())
                SendChatMessage(c, TEXT_ROUND_STARTED);

            TotalTime = 0;
            ToggleTimer();
            Status = BG_SA_ROUND_TWO;
            TriggerGameEvent((Attackers == TEAM_ALLIANCE) ? EVENT_ALLIANCE_ASSAULT_STARTED : EVENT_HORDE_ASSAULT_STARTED);
            // status was set to STATUS_WAIT_JOIN manually for Preparation, set it back now
            SetStatus(STATUS_IN_PROGRESS);
            for (const auto& [playerGuid, bp] : GetPlayers())
                if (Player* p = ObjectAccessor::FindPlayer(playerGuid))
                    p->RemoveAurasDueToSpell(SPELL_PREPARATION);
        }
        if (TotalTime >= 30000)
        {
            if (!SignaledRoundTwoHalfMin)
            {
                SignaledRoundTwoHalfMin = true;
                SendBroadcastText(BG_SA_TEXT_ROUND_TWO_START_HALF_MINUTE, CHAT_MSG_BG_SYSTEM_NEUTRAL);
            }
        }
        StartShips();
        return;
    }
    else if (GetStatus() == STATUS_IN_PROGRESS)
    {
        if (Status == BG_SA_ROUND_ONE)
        {
            if (TotalTime >= BG_SA_ROUNDLENGTH)
            {
                EndRound();
                return;
            }
        }
        else if (Status == BG_SA_ROUND_TWO)
        {
            if (TotalTime >= EndRoundTimer)
            {
                CastSpellOnTeam(SPELL_END_OF_ROUND, ALLIANCE);
                CastSpellOnTeam(SPELL_END_OF_ROUND, HORDE);
                RoundScores[1].time = BG_SA_ROUNDLENGTH;
                RoundScores[1].winner = (Attackers == TEAM_ALLIANCE) ? TEAM_HORDE : TEAM_ALLIANCE;
                if (RoundScores[0].time == RoundScores[1].time)
                    EndBattleground(TEAM_OTHER);
                else if (RoundScores[0].time < RoundScores[1].time)
                    EndBattleground(RoundScores[0].winner == TEAM_ALLIANCE ? ALLIANCE : HORDE);
                else
                    EndBattleground(RoundScores[1].winner == TEAM_ALLIANCE ? ALLIANCE : HORDE);
                return;
            }
        }
    }
}

void BattlegroundSA::AddPlayer(Player* player, BattlegroundQueueTypeId queueId)
{
    bool const isInBattleground = IsPlayerInBattleground(player->GetGUID());
    Battleground::AddPlayer(player, queueId);

    SendTransportInit(player);

    if (!isInBattleground)
        TeleportToEntrancePosition(player);
}

void BattlegroundSA::RemovePlayer(Player* /*player*/, ObjectGuid /*guid*/, uint32 /*team*/) { }

void BattlegroundSA::HandleAreaTrigger(Player* /*source*/, uint32 /*trigger*/, bool /*entered*/)
{
    // this is wrong way to implement these things. On official it done by gameobject spell cast.
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;
}

void BattlegroundSA::TeleportPlayers() const
{
    for (auto const& [playerGuid, bp] : GetPlayers())
    {
        if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
        {
            // should remove spirit of redemption
            if (player->HasAuraType(SPELL_AURA_SPIRIT_OF_REDEMPTION))
                player->RemoveAurasByType(SPELL_AURA_MOD_SHAPESHIFT);

            if (!player->IsAlive())
            {
                player->ResurrectPlayer(1.0f);
                player->SpawnCorpseBones();
            }

            player->ResetAllPowers();
            player->CombatStopWithPets(true);

            player->CastSpell(player, SPELL_PREPARATION, true);

            TeleportToEntrancePosition(player);
        }
    }
}

// This function teleports player to entrance position, but it's not implemented correctly
// It is also used on round swap; which should be handled by the following spells: 52365, 52528, 53464, 53465 (Split Teleport (FACTION) (Boat X))
// This spell however cannot work with current system because of grid limitations.
// On battleground start, this function should work fine, except that it is called to late and we need a NearTeleport to solve this.
void BattlegroundSA::TeleportToEntrancePosition(Player* player) const
{
    if (GetTeamIndexByTeamId(GetPlayerTeam(player->GetGUID())) == Attackers)
    {
        ObjectGuid const boatGUID = _boatGUIDs[Attackers][urand(0, 1)];

        if (GameObject* boat = GetBgMap()->GetGameObject(boatGUID))
        {
            if (TransportBase* transport = boat->ToTransportBase())
            {
                player->Relocate(spawnPositionOnTransport[Attackers]);
                transport->AddPassenger(player);
                player->m_movementInfo.transport.pos.Relocate(spawnPositionOnTransport[Attackers]);
                float x, y, z, o;
                spawnPositionOnTransport[Attackers].GetPosition(x, y, z, o);
                transport->CalculatePassengerPosition(x, y, z, &o);
                player->Relocate(x, y, z, o);

                if (player->IsInWorld())
                    player->NearTeleportTo({ x, y, z, o });
            }
        }
    }
    else if (WorldSafeLocsEntry const* defenderSpawn = sObjectMgr->GetWorldSafeLoc(SPAWN_DEFENDERS))
    {
        if (player->IsInWorld())
            player->TeleportTo(defenderSpawn->Loc);
        else
            player->WorldRelocate(defenderSpawn->Loc);
    }
}

void BattlegroundSA::ProcessEvent(WorldObject* obj, uint32 eventId, WorldObject* invoker /*= nullptr*/)
{
    switch (eventId)
    {
        case EVENT_ALLIANCE_ASSAULT_STARTED:
            for (ObjectGuid const& bombGuid : _staticBombGUIDs[TEAM_ALLIANCE])
                if (GameObject* bomb = GetBgMap()->GetGameObject(bombGuid))
                    bomb->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
            break;
        case EVENT_HORDE_ASSAULT_STARTED:
            for (ObjectGuid const& bombGuid : _staticBombGUIDs[TEAM_HORDE])
                if (GameObject* bomb = GetBgMap()->GetGameObject(bombGuid))
                    bomb->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
            break;
        default:
            break;
    }

    if (GameObject* go = Object::ToGameObject(obj))
    {
        switch (go->GetGoType())
        {
            case GAMEOBJECT_TYPE_GOOBER:
                if (invoker)
                    if (eventId == EVENT_TITAN_RELIC_ACTIVATED)
                        TitanRelicActivated(invoker->ToPlayer());
                break;
            case GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING:
            {
                if (GateInfo const* gate = GetGate(obj->GetEntry()))
                {
                    uint32 gateId = gate->GameObjectId;

                    // damaged
                    if (eventId == go->GetGOInfo()->destructibleBuilding.DamagedEvent)
                    {
                        BG_SA_GateState gateState = Attackers == TEAM_HORDE ? BG_SA_ALLIANCE_GATE_DAMAGED : BG_SA_HORDE_GATE_DAMAGED;

                        if (Creature* c = obj->FindNearestCreature(NPC_WORLD_TRIGGER, 500.0f))
                            SendChatMessage(c, gate->DamagedText, invoker);

                        PlaySoundToAll(Attackers == TEAM_ALLIANCE ? SOUND_WALL_ATTACKED_ALLIANCE : SOUND_WALL_ATTACKED_HORDE);

                        UpdateWorldState(gate->WorldState, gateState);
                    }
                    // destroyed
                    else if (eventId == go->GetGOInfo()->destructibleBuilding.DestroyedEvent)
                    {
                        BG_SA_GateState gateState = Attackers == TEAM_HORDE ? BG_SA_ALLIANCE_GATE_DESTROYED : BG_SA_HORDE_GATE_DESTROYED;
                        if (Creature* c = obj->FindNearestCreature(NPC_WORLD_TRIGGER, 500.0f))
                            SendChatMessage(c, gate->DestroyedText, invoker);

                        PlaySoundToAll(Attackers == TEAM_ALLIANCE ? SOUND_WALL_DESTROYED_ALLIANCE : SOUND_WALL_DESTROYED_HORDE);

                        // check if other gate from same line of defense is already destroyed for honor reward
                        bool rewardHonor = true;
                        switch (gateId)
                        {
                            case GO_GATE_OF_THE_GREEN_EMERALD:
                                if (IsGateDestroyed(GetGate(GO_GATE_OF_THE_BLUE_SAPPHIRE)))
                                    rewardHonor = false;
                                break;
                            case GO_GATE_OF_THE_BLUE_SAPPHIRE:
                                if (IsGateDestroyed(GetGate(GO_GATE_OF_THE_GREEN_EMERALD)))
                                    rewardHonor = false;
                                break;
                            case GO_GATE_OF_THE_RED_SUN:
                                if (IsGateDestroyed(GetGate(GO_GATE_OF_THE_PURPLE_AMETHYST)))
                                    rewardHonor = false;
                                break;
                            case GO_GATE_OF_THE_PURPLE_AMETHYST:
                                if (IsGateDestroyed(GetGate(GO_GATE_OF_THE_RED_SUN)))
                                    rewardHonor = false;
                                break;
                            default:
                                break;
                        }

                        if (invoker)
                        {
                            if (Unit* unit = invoker->ToUnit())
                            {
                                if (Player* player = unit->GetCharmerOrOwnerPlayerOrPlayerItself())
                                {
                                    UpdatePvpStat(player, PVP_STAT_GATES_DESTROYED, 1);
                                    if (rewardHonor)
                                        UpdatePlayerScore(player, SCORE_BONUS_HONOR, GetBonusHonorFromKill(1));
                                }
                            }
                        }

                        if (rewardHonor)
                            MakeObjectsInteractable(gate->LineOfDefense);

                        UpdateWorldState(gate->WorldState, gateState);
                        GetBgMap()->UpdateSpawnGroupConditions();
                    }
                }
                break;
            }
            default:
                break;
        }
    }
}

void BattlegroundSA::HandleKillUnit(Creature* creature, Unit* killer)
{
    if (creature->GetEntry() == NPC_DEMOLISHER_SA)
    {
        if (Player* killerPlayer = killer->GetCharmerOrOwnerPlayerOrPlayerItself())
            UpdatePvpStat(killerPlayer, PVP_STAT_DEMOLISHERS_DESTROYED, 1);
        int32 worldStateId = Attackers == TEAM_HORDE ? BG_SA_DESTROYED_HORDE_VEHICLES : BG_SA_DESTROYED_ALLIANCE_VEHICLES;
        int32 currentDestroyedVehicles = sWorldStateMgr->GetValue(worldStateId, GetBgMap());
        UpdateWorldState(worldStateId, currentDestroyedVehicles + 1);
    }
}

void BattlegroundSA::DestroyGate(Player* /*player*/, GameObject* /*go*/)
{
}

void BattlegroundSA::CaptureGraveyard(StrandOfTheAncientsGraveyard graveyard, TeamId teamId)
{
    switch (graveyard)
    {
        case StrandOfTheAncientsGraveyard::West:
            UpdateWorldState(BG_SA_LEFT_GY_ALLIANCE, teamId == TEAM_ALLIANCE);
            UpdateWorldState(BG_SA_LEFT_GY_HORDE, teamId == TEAM_HORDE);
            break;
        case StrandOfTheAncientsGraveyard::East:
            UpdateWorldState(BG_SA_RIGHT_GY_ALLIANCE, teamId == TEAM_ALLIANCE);
            UpdateWorldState(BG_SA_RIGHT_GY_HORDE, teamId == TEAM_HORDE);
            break;
        case StrandOfTheAncientsGraveyard::Central:
            UpdateWorldState(BG_SA_CENTER_GY_ALLIANCE, teamId == TEAM_ALLIANCE);
            UpdateWorldState(BG_SA_CENTER_GY_HORDE, teamId == TEAM_HORDE);

            CaptureGraveyard(StrandOfTheAncientsGraveyard::East, teamId);
            CaptureGraveyard(StrandOfTheAncientsGraveyard::West, teamId);
            break;
        default:
            break;
    }
}

void BattlegroundSA::TitanRelicActivated(Player* clicker)
{
    if (!clicker)
        return;

    TeamId clickerTeamId = GetTeamIndexByTeamId(GetPlayerTeam(clicker->GetGUID()));
    if (clickerTeamId == Attackers)
    {
        if (clickerTeamId == TEAM_ALLIANCE)
            SendBroadcastText(BG_SA_TEXT_ALLIANCE_CAPTURED_TITAN_PORTAL, CHAT_MSG_BG_SYSTEM_ALLIANCE);
        else
            SendBroadcastText(BG_SA_TEXT_HORDE_CAPTURED_TITAN_PORTAL, CHAT_MSG_BG_SYSTEM_HORDE);

        if (Status == BG_SA_ROUND_ONE)
        {
            EndRound();
            // Achievement Storm the Beach (1310)
            for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
            {
                if (Player* player = ObjectAccessor::FindPlayer(itr->first))
                    if (GetTeamIndexByTeamId(GetPlayerTeam(player->GetGUID())) == Attackers)
                        player->UpdateCriteria(CriteriaType::BeSpellTarget, 65246);
            }

            if (Creature* c = FindKanrethad())
                SendChatMessage(c, TEXT_ROUND_1_FINISHED);
        }
        else if (Status == BG_SA_ROUND_TWO)
        {
            RoundScores[1].winner = Attackers;
            RoundScores[1].time = TotalTime;
            ToggleTimer();
            // Achievement Storm the Beach (1310)
            for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
            {
                if (Player* player = ObjectAccessor::FindPlayer(itr->first))
                    if (GetTeamIndexByTeamId(GetPlayerTeam(player->GetGUID())) == Attackers && RoundScores[1].winner == Attackers)
                        player->UpdateCriteria(CriteriaType::BeSpellTarget, 65246);
            }

            if (RoundScores[0].time == RoundScores[1].time)
                EndBattleground(TEAM_OTHER);
            else if (RoundScores[0].time < RoundScores[1].time)
                EndBattleground(RoundScores[0].winner == TEAM_ALLIANCE ? ALLIANCE : HORDE);
            else
                EndBattleground(RoundScores[1].winner == TEAM_ALLIANCE ? ALLIANCE : HORDE);
        }
    }
}

void BattlegroundSA::ToggleTimer()
{
    TimerEnabled = !TimerEnabled;
    UpdateWorldState(BG_SA_ENABLE_TIMER, TimerEnabled);
}

void BattlegroundSA::EndBattleground(Team winner)
{
    // honor reward for winning
    if (winner == ALLIANCE)
        RewardHonorToTeam(GetBonusHonorFromKill(1), ALLIANCE);
    else if (winner == HORDE)
        RewardHonorToTeam(GetBonusHonorFromKill(1), HORDE);

    // complete map_end rewards (even if no team wins)
    RewardHonorToTeam(GetBonusHonorFromKill(2), ALLIANCE);
    RewardHonorToTeam(GetBonusHonorFromKill(2), HORDE);

    Battleground::EndBattleground(winner);
}

void BattlegroundSA::SendTransportInit(Player* player)
{
    UpdateData transData(player->GetMapId());
    for (ObjectGuid const& boatGuid : _boatGUIDs[Attackers])
        if (GameObject const* boat = GetBgMap()->GetGameObject(boatGuid))
            boat->BuildCreateUpdateBlockForPlayer(&transData, player);

    WorldPacket packet;
    transData.BuildPacket(&packet);
    player->SendDirectMessage(&packet);
}

void BattlegroundSA::SendTransportsRemove(Player* player)
{
    UpdateData transData(player->GetMapId());
    for (ObjectGuid const& boatGuid : _boatGUIDs[Attackers])
        if (GameObject const* boat = GetBgMap()->GetGameObject(boatGuid))
            boat->BuildOutOfRangeUpdateBlock(&transData);

    WorldPacket packet;
    transData.BuildPacket(&packet);
    player->SendDirectMessage(&packet);
}

bool BattlegroundSA::IsGateDestroyed(GateInfo const* gateInfo) const
{
    if (!gateInfo)
        return false;

    int32 value = GetBgMap()->GetWorldStateValue(gateInfo->WorldState);
    return value == BG_SA_ALLIANCE_GATE_DESTROYED || value == BG_SA_HORDE_GATE_DESTROYED;
}

void BattlegroundSA::HandleCaptureGraveyardAction(GameObject* graveyardBanner, Player* player)
{
    if (!graveyardBanner || !player)
        return;

    TeamId const teamId = GetTeamIndexByTeamId(GetPlayerTeam(player->GetGUID()));
    // Only attackers can capture graveyard by gameobject action
    if (teamId != Attackers)
        return;

    switch (graveyardBanner->GetEntry())
    {
        case GO_GRAVEYARD_WEST_A:
        case GO_GRAVEYARD_WEST_H:
            CaptureGraveyard(StrandOfTheAncientsGraveyard::West, teamId);
            break;
        case GO_GRAVEYARD_EAST_A:
        case GO_GRAVEYARD_EAST_H:
            CaptureGraveyard(StrandOfTheAncientsGraveyard::East, teamId);
            break;
        case GO_GRAVEYARD_CENTRAL_A:
        case GO_GRAVEYARD_CENTRAL_H:
            CaptureGraveyard(StrandOfTheAncientsGraveyard::Central, teamId);
            break;
        default:
            break;
    }
}

void BattlegroundSA::MakeObjectsInteractable(DefenseLine defenseLine)
{
    auto makeInteractable = [&](ObjectGuid const& guid) -> void
    {
        if (GameObject* gameObject = GetBgMap()->GetGameObject(guid))
            gameObject->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
    };

    switch (defenseLine)
    {
        case DefenseLine::First:
            makeInteractable(_graveyardWest);
            makeInteractable(_graveyardEast);
            break;
        case DefenseLine::Second:
            makeInteractable(_graveyardCentral);
            break;
        case DefenseLine::Third:
            break;
        case DefenseLine::Last:
            // make titan orb interactable
            if (GameObject* door = GetBgMap()->GetGameObject(_collisionDoorGUID))
                door->UseDoorOrButton();

            makeInteractable(_titanRelicGUID);
            break;
        default:
            break;
    }
}

Creature* BattlegroundSA::FindKanrethad() const
{
    return GetBgMap()->GetCreature(_kanrethadGUID);
}

void BattlegroundSA::EndRound()
{
    RoundScores[0].winner = Attackers;
    RoundScores[0].time = std::min<uint32>(TotalTime, BG_SA_ROUNDLENGTH);

    Attackers = (Attackers == TEAM_ALLIANCE) ? TEAM_HORDE : TEAM_ALLIANCE;
    Status = BG_SA_SECOND_WARMUP;
    TotalTime = 0;
    ToggleTimer();

    UpdateWaitTimer = 5000;
    SignaledRoundTwo = false;
    SignaledRoundTwoHalfMin = false;
    InitSecondRound = true;
    ResetObjs();
    GetBgMap()->UpdateAreaDependentAuras();

    CastSpellOnTeam(SPELL_END_OF_ROUND, ALLIANCE);
    CastSpellOnTeam(SPELL_END_OF_ROUND, HORDE);

    RemoveAuraOnTeam(SPELL_CARRYING_SEAFORIUM_CHARGE, HORDE);
    RemoveAuraOnTeam(SPELL_CARRYING_SEAFORIUM_CHARGE, ALLIANCE);
}

void BattlegroundSA::OnGameObjectCreate(GameObject* gameobject)
{
    Battleground::OnGameObjectCreate(gameobject);

    if (gameobject->GetGoType() == GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING)
        _gateGUIDs.insert(gameobject->GetGUID());

    switch (gameobject->GetEntry())
    {
        case BG_SA_BOAT_ONE_A:
            _boatGUIDs[TEAM_ALLIANCE][0] = gameobject->GetGUID();
            break;
        case BG_SA_BOAT_TWO_A:
            _boatGUIDs[TEAM_ALLIANCE][1] = gameobject->GetGUID();
            break;
        case BG_SA_BOAT_ONE_H:
            _boatGUIDs[TEAM_HORDE][0] = gameobject->GetGUID();
            break;
        case BG_SA_BOAT_TWO_H:
            _boatGUIDs[TEAM_HORDE][1] = gameobject->GetGUID();
            break;
        case GO_SEAFORIUM_BOMB_A:
            _staticBombGUIDs[TEAM_ALLIANCE].insert(gameobject->GetGUID());
            if (Status != BG_SA_SECOND_WARMUP && Status != BG_SA_WARMUP)
                gameobject->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
            break;
        case GO_SEAFORIUM_BOMB_H:
            _staticBombGUIDs[TEAM_HORDE].insert(gameobject->GetGUID());
            if (Status != BG_SA_SECOND_WARMUP && Status != BG_SA_WARMUP)
                gameobject->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
            break;
        case GO_SEAFORIUM_CHARGE_A:
        case GO_SEAFORIUM_CHARGE_H:
            _dynamicBombGUIDs.insert(gameobject->GetGUID());
            break;
        case GO_GRAVEYARD_EAST_A:
        case GO_GRAVEYARD_EAST_H:
            _graveyardEast = gameobject->GetGUID();
            break;
        case GO_GRAVEYARD_WEST_A:
        case GO_GRAVEYARD_WEST_H:
            _graveyardWest = gameobject->GetGUID();
            break;
        case GO_GRAVEYARD_CENTRAL_A:
        case GO_GRAVEYARD_CENTRAL_H:
            _graveyardCentral = gameobject->GetGUID();
            break;
        case GO_COLLISION_DOOR:
            _collisionDoorGUID = gameobject->GetGUID();
            break;
        case GO_TITAN_RELIC_A:
        case GO_TITAN_RELIC_H:
            _titanRelicGUID = gameobject->GetGUID();
            break;
        default:
            break;
    }
}

void BattlegroundSA::DoAction(uint32 actionId, WorldObject* source, WorldObject* target)
{
    switch (actionId)
    {
        case ACTION_SOTA_CAPTURE_GRAVEYARD:
            HandleCaptureGraveyardAction(Object::ToGameObject(target), Object::ToPlayer(source));
            break;
        default:
            break;
    }
}

void BattlegroundSA::OnCreatureCreate(Creature* creature)
{
    Battleground::OnCreatureCreate(creature);

    switch (creature->GetEntry())
    {
        case NPC_DEMOLISHER:
            creature->SetFaction(BG_SA_Factions[Attackers]);
            break;
        case NPC_ANTIPERSONNEL_CANNON:
            creature->SetFaction(BG_SA_Factions[Attackers == TEAM_HORDE ? TEAM_ALLIANCE : TEAM_HORDE]);
            break;
        case NPC_KANRETHAD:
            _kanrethadGUID = creature->GetGUID();
            break;
        case NPC_RIGGER_SPARKLIGHT:
        case NPC_GORGRIL_RIGSPARK:
            creature->AI()->Talk(TEXT_SPARKLIGHT_RIGSPARK_SPAWN);
            break;
        default:
            break;
    }
}

void BattlegroundSA::OnMapSet(BattlegroundMap* map)
{
    Battleground::OnMapSet(map);
    ResetObjs();
}

uint32 BattlegroundSA::GetData(uint32 dataId) const
{
    switch (dataId)
    {
        case DATA_ATTACKERS:
            return Attackers;
        case DATA_STATUS:
            return Status;
        default:
            return Battleground::GetData(dataId);
    }
}
