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
#include "BattlegroundScore.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameTime.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "strand_of_the_ancients.h"
#include "VehicleDefines.h"
#include "WorldStateMgr.h"

enum BG_SA_Status
{
    BG_SA_NOT_STARTED = 0,
    BG_SA_WARMUP,
    BG_SA_ROUND_ONE,
    BG_SA_SECOND_WARMUP,
    BG_SA_ROUND_TWO,
    BG_SA_BONUS_ROUND
};

enum BG_SA_GateState
{
    // alliance is defender
    BG_SA_ALLIANCE_GATE_OK          = 1,
    BG_SA_ALLIANCE_GATE_DAMAGED     = 2,
    BG_SA_ALLIANCE_GATE_DESTROYED   = 3,
    // horde is defender
    BG_SA_HORDE_GATE_OK             = 4,
    BG_SA_HORDE_GATE_DAMAGED        = 5,
    BG_SA_HORDE_GATE_DESTROYED      = 6,
};

enum StrandOfTheAncientsGameObjects
{
    GO_SEAFORIUM_BOMB_H             = 194086, // Used by horde players
    GO_SEAFORIUM_BOMB_A             = 190753, // Used by alliance players
    GO_SEAFORIUM_CHARGE_H           = 257572,
    GO_SEAFORIUM_CHARGE_A           = 257565,

    GO_GRAVEYARD_WEST_H             = 191307,
    GO_GRAVEYARD_WEST_A             = 191308,

    GO_GRAVEYARD_EAST_H             = 191305,
    GO_GRAVEYARD_EAST_A             = 191306,

    GO_GRAVEYARD_CENTRAL_H          = 191309,
    GO_GRAVEYARD_CENTRAL_A          = 191310,

    GO_COLLISION_DOOR               = 194162,
    GO_TITAN_RELIC_A                = 194083,
    GO_TITAN_RELIC_H                = 194082,

    GO_GATE_OF_THE_GREEN_EMERALD    = 190722,
    GO_GATE_OF_THE_PURPLE_AMETHYST  = 190723,
    GO_GATE_OF_THE_BLUE_SAPPHIRE    = 190724,
    GO_GATE_OF_THE_RED_SUN          = 190726,
    GO_GATE_OF_THE_YELLOW_MOON      = 190727,
    GO_CHAMBER_OF_ANCIENT_RELICS    = 192549
};

enum BG_SA_Timers
{
    BG_SA_BOAT_START                = 60 * IN_MILLISECONDS,
    BG_SA_WARMUPLENGTH              = 120 * IN_MILLISECONDS,
    BG_SA_ROUNDLENGTH               = 600 * IN_MILLISECONDS
};

enum SASounds
{
    SOUND_GRAVEYARD_TAKEN_HORDE     = 8174,
    SOUND_GRAVEYARD_TAKEN_ALLIANCE  = 8212,
    SOUND_DEFEAT_HORDE              = 15905,
    SOUND_VICTORY_HORDE             = 15906,
    SOUND_VICTORY_ALLIANCE          = 15907,
    SOUND_DEFEAT_ALLIANCE           = 15908,
    SOUND_WALL_DESTROYED_ALLIANCE   = 15909,
    SOUND_WALL_DESTROYED_HORDE      = 15910,
    SOUND_WALL_ATTACKED_HORDE       = 15911,
    SOUND_WALL_ATTACKED_ALLIANCE    = 15912
};

enum SATexts
{
    // Kanrethad
    TEXT_ROUND_STARTED              = 1,
    TEXT_ROUND_1_FINISHED           = 2,

    // Rigger Sparklight / Gorgril Rigspark
    TEXT_SPARKLIGHT_RIGSPARK_SPAWN  = 1,

    // World Trigger
    TEXT_BLUE_GATE_UNDER_ATTACK     = 1,
    TEXT_GREEN_GATE_UNDER_ATTACK    = 2,
    TEXT_RED_GATE_UNDER_ATTACK      = 3,
    TEXT_PURPLE_GATE_UNDER_ATTACK   = 4,
    TEXT_YELLOW_GATE_UNDER_ATTACK   = 5,
    TEXT_YELLOW_GATE_DESTROYED      = 6,
    TEXT_PURPLE_GATE_DESTROYED      = 7,
    TEXT_RED_GATE_DESTROYED         = 8,
    TEXT_GREEN_GATE_DESTROYED       = 9,
    TEXT_BLUE_GATE_DESTROYED        = 10,
    TEXT_EAST_GRAVEYARD_CAPTURED_A  = 11,
    TEXT_WEST_GRAVEYARD_CAPTURED_A  = 12,
    TEXT_SOUTH_GRAVEYARD_CAPTURED_A = 13,
    TEXT_EAST_GRAVEYARD_CAPTURED_H  = 14,
    TEXT_WEST_GRAVEYARD_CAPTURED_H  = 15,
    TEXT_SOUTH_GRAVEYARD_CAPTURED_H = 16,
    TEXT_ANCIENT_GATE_UNDER_ATTACK  = 17,
    TEXT_ANCIENT_GATE_DESTROYED     = 18
};

enum SAWorldStates
{
    BG_SA_TIMER                         = 3557,
    BG_SA_ALLY_ATTACKS                  = 4352,
    BG_SA_HORDE_ATTACKS                 = 4353,
    BG_SA_PURPLE_GATEWS                 = 3614,
    BG_SA_RED_GATEWS                    = 3617,
    BG_SA_BLUE_GATEWS                   = 3620,
    BG_SA_GREEN_GATEWS                  = 3623,
    BG_SA_YELLOW_GATEWS                 = 3638,
    BG_SA_ANCIENT_GATEWS                = 3849,

    BG_SA_LEFT_GY_ALLIANCE              = 3635,
    BG_SA_RIGHT_GY_ALLIANCE             = 3636,
    BG_SA_CENTER_GY_ALLIANCE            = 3637,

    BG_SA_RIGHT_ATT_TOKEN_ALL           = 3627,
    BG_SA_LEFT_ATT_TOKEN_ALL            = 3626,
    BG_SA_LEFT_ATT_TOKEN_HRD            = 3629,
    BG_SA_RIGHT_ATT_TOKEN_HRD           = 3628,
    BG_SA_HORDE_DEFENCE_TOKEN           = 3631,
    BG_SA_ALLIANCE_DEFENCE_TOKEN        = 3630,

    BG_SA_RIGHT_GY_HORDE                = 3632,
    BG_SA_LEFT_GY_HORDE                 = 3633,
    BG_SA_CENTER_GY_HORDE               = 3634,

    BG_SA_BONUS_TIMER                   = 3571,

    BG_SA_ENABLE_TIMER                  = 3564,
    BG_SA_ATTACKER_TEAM                 = 3690,
    BG_SA_DESTROYED_ALLIANCE_VEHICLES   = 3955,
    BG_SA_DESTROYED_HORDE_VEHICLES      = 3956,
};

enum BG_SA_Boat
{
    BG_SA_BOAT_ONE_A    = 208000,
    BG_SA_BOAT_TWO_H    = 208001,
    BG_SA_BOAT_ONE_H    = 193184,
    BG_SA_BOAT_TWO_A    = 193185
};

static constexpr uint32 BG_SA_Factions[2] =
{
    1732,
    1735,
};

enum class StrandOfTheAncientsGraveyard
{
    West,
    East,
    Central
};

enum BG_SA_BroadcastTexts
{
    BG_SA_TEXT_ALLIANCE_CAPTURED_TITAN_PORTAL   = 28944,
    BG_SA_TEXT_HORDE_CAPTURED_TITAN_PORTAL      = 28945,

    BG_SA_TEXT_ROUND_TWO_START_ONE_MINUTE       = 29448,
    BG_SA_TEXT_ROUND_TWO_START_HALF_MINUTE      = 29449
};

enum class DefenseLine
{
    First,
    Second,
    Third,
    Last
};

struct GateInfo
{
    uint32 GameObjectId;
    uint32 WorldState;
    uint8 DamagedText;
    uint8 DestroyedText;
    DefenseLine LineOfDefense;
};

GateInfo const Gates[] =
{
    { GO_GATE_OF_THE_GREEN_EMERALD,   BG_SA_GREEN_GATEWS,   TEXT_GREEN_GATE_UNDER_ATTACK,   TEXT_GREEN_GATE_DESTROYED,      DefenseLine::First  },
    { GO_GATE_OF_THE_YELLOW_MOON,     BG_SA_YELLOW_GATEWS,  TEXT_YELLOW_GATE_UNDER_ATTACK,  TEXT_YELLOW_GATE_DESTROYED,     DefenseLine::Third  },
    { GO_GATE_OF_THE_BLUE_SAPPHIRE,   BG_SA_BLUE_GATEWS,    TEXT_BLUE_GATE_UNDER_ATTACK,    TEXT_BLUE_GATE_DESTROYED,       DefenseLine::First  },
    { GO_GATE_OF_THE_RED_SUN,         BG_SA_RED_GATEWS,     TEXT_RED_GATE_UNDER_ATTACK,     TEXT_RED_GATE_DESTROYED,        DefenseLine::Second },
    { GO_GATE_OF_THE_PURPLE_AMETHYST, BG_SA_PURPLE_GATEWS,  TEXT_PURPLE_GATE_UNDER_ATTACK,  TEXT_PURPLE_GATE_DESTROYED,     DefenseLine::Second },
    { GO_CHAMBER_OF_ANCIENT_RELICS,   BG_SA_ANCIENT_GATEWS, TEXT_ANCIENT_GATE_UNDER_ATTACK, TEXT_ANCIENT_GATE_DESTROYED,    DefenseLine::Last   }
};

struct BG_SA_RoundScore
{
    TeamId winner;
    uint32 time;
};

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
    NPC_KANRETHAD                   = 29,
    NPC_DEMOLISHER                  = 28781,
    NPC_ANTIPERSONNEL_CANNON        = 27894,
    NPC_RIGGER_SPARKLIGHT           = 29260,
    NPC_GORGRIL_RIGSPARK            = 29262,
    NPC_WORLD_TRIGGER               = 22515,
    NPC_DEMOLISHER_SA               = 28781
};

enum StrandOfTheAncientsSpawnPositions
{
    SPAWN_DEFENDERS                 = 1399
};

enum StrandOfTheAncientsData
{
    DATA_ATTACKERS                  = 1,
    DATA_STATUS                     = 2
};

enum StrandOfTheAncientSpells
{
    SPELL_TELEPORT_DEFENDER = 52364,
    SPELL_TELEPORT_ATTACKERS = 60178,
    SPELL_END_OF_ROUND = 52459,
    SPELL_REMOVE_SEAFORIUM = 59077,
    SPELL_ALLIANCE_CONTROL_PHASE_SHIFT = 60027,
    SPELL_HORDE_CONTROL_PHASE_SHIFT = 60028,
    SPELL_CARRYING_SEAFORIUM_CHARGE = 52415
};

static constexpr Position spawnPositionOnTransport[] =
{
    { 0.0f, 5.0f, 9.6f, 3.14f },
    { -6.0f, -3.0f, 8.6f, 0.0f }
};

struct battleground_strand_of_the_ancients : BattlegroundScript
{
    explicit battleground_strand_of_the_ancients(BattlegroundMap* map) : BattlegroundScript(map)
    {
        _timerEnabled = false;
        _updateWaitTimer = 0;
        _signaledRoundTwo = false;
        _signaledRoundTwoHalfMin = false;
        _initSecondRound = false;
        _attackers = static_cast<TeamId>(urand(TEAM_ALLIANCE, TEAM_HORDE));
        _totalTime = 0;
        _endRoundTimer = 0;
        _shipsStarted = false;
        _status = BG_SA_NOT_STARTED;

        _roundScores = { };

        for (BG_SA_RoundScore& roundScore : _roundScores)
        {
            roundScore.winner = TEAM_ALLIANCE;
            roundScore.time = 0;
        }

        _boatGUIDs = { };
        _staticBombGUIDs = { };
    }

    void OnInit() override
    {
        BattlegroundScript::OnInit();
        _status = BG_SA_WARMUP;
        ResetObjs();
    }

    void OnUpdate(uint32 diff) override
    {
        BattlegroundScript::OnUpdate(diff);
        if (_initSecondRound)
        {
            if (_updateWaitTimer < diff)
            {
                if (!_signaledRoundTwo)
                {
                    _signaledRoundTwo = true;
                    _initSecondRound = false;
                    battleground->SendBroadcastText(BG_SA_TEXT_ROUND_TWO_START_ONE_MINUTE, CHAT_MSG_BG_SYSTEM_NEUTRAL);
                }
            }
            else
            {
                _updateWaitTimer -= diff;
                return;
            }
        }
        _totalTime += diff;

        if (_status == BG_SA_WARMUP)
        {
            _endRoundTimer = BG_SA_ROUNDLENGTH;
            UpdateWorldState(BG_SA_TIMER, GameTime::GetGameTime() + (_endRoundTimer / 1000));
            if (_totalTime >= BG_SA_WARMUPLENGTH)
            {
                if (Creature* c = FindKanrethad())
                    battleground->SendChatMessage(c, TEXT_ROUND_STARTED);

                _totalTime = 0;
                ToggleTimer();
                _status = BG_SA_ROUND_ONE;
                TriggerGameEvent((_attackers == TEAM_ALLIANCE) ? EVENT_ALLIANCE_ASSAULT_STARTED : EVENT_HORDE_ASSAULT_STARTED);
            }
            if (_totalTime >= BG_SA_BOAT_START)
                StartShips();
            return;
        }
        else if (_status == BG_SA_SECOND_WARMUP)
        {
            if (_roundScores[0].time < BG_SA_ROUNDLENGTH)
                _endRoundTimer = _roundScores[0].time;
            else
                _endRoundTimer = BG_SA_ROUNDLENGTH;

            UpdateWorldState(BG_SA_TIMER, GameTime::GetGameTime() + (_endRoundTimer / 1000));
            if (_totalTime >= 60000)
            {
                if (Creature* c = FindKanrethad())
                    battleground->SendChatMessage(c, TEXT_ROUND_STARTED);

                _totalTime = 0;
                ToggleTimer();
                _status = BG_SA_ROUND_TWO;
                TriggerGameEvent((_attackers == TEAM_ALLIANCE) ? EVENT_ALLIANCE_ASSAULT_STARTED : EVENT_HORDE_ASSAULT_STARTED);
                // status was set to STATUS_WAIT_JOIN manually for Preparation, set it back now
                battleground->SetStatus(STATUS_IN_PROGRESS);
                for (const auto& [playerGuid, bp] : battleground->GetPlayers())
                    if (Player* p = ObjectAccessor::FindPlayer(playerGuid))
                        p->RemoveAurasDueToSpell(SPELL_PREPARATION);
            }
            if (_totalTime >= 30000)
            {
                if (!_signaledRoundTwoHalfMin)
                {
                    _signaledRoundTwoHalfMin = true;
                    battleground->SendBroadcastText(BG_SA_TEXT_ROUND_TWO_START_HALF_MINUTE, CHAT_MSG_BG_SYSTEM_NEUTRAL);
                }
            }
            StartShips();
            return;
        }
        else if (battleground->GetStatus() == STATUS_IN_PROGRESS)
        {
            if (_status == BG_SA_ROUND_ONE)
            {
                if (_totalTime >= BG_SA_ROUNDLENGTH)
                {
                    EndRound();
                    return;
                }
            }
            else if (_status == BG_SA_ROUND_TWO)
            {
                if (_totalTime >= _endRoundTimer)
                {
                    battleground->CastSpellOnTeam(SPELL_END_OF_ROUND, ALLIANCE);
                    battleground->CastSpellOnTeam(SPELL_END_OF_ROUND, HORDE);
                    _roundScores[1].time = BG_SA_ROUNDLENGTH;
                    _roundScores[1].winner = (_attackers == TEAM_ALLIANCE) ? TEAM_HORDE : TEAM_ALLIANCE;
                    if (_roundScores[0].time == _roundScores[1].time)
                        battleground->EndBattleground(TEAM_OTHER);
                    else if (_roundScores[0].time < _roundScores[1].time)
                        battleground->EndBattleground(_roundScores[0].winner == TEAM_ALLIANCE ? ALLIANCE : HORDE);
                    else
                        battleground->EndBattleground(_roundScores[1].winner == TEAM_ALLIANCE ? ALLIANCE : HORDE);
                    return;
                }
            }
        }
    }

    void Reset()
    {
        _totalTime = 0;
        _shipsStarted = false;
        _status = BG_SA_WARMUP;
    }

    void ResetObjs()
    {
        for (ObjectGuid const& bombGuid : _dynamicBombGUIDs)
            if (GameObject* bomb = battlegroundMap->GetGameObject(bombGuid))
                bomb->Delete();

        _dynamicBombGUIDs.clear();

        TeamId const defenders = _attackers == TEAM_ALLIANCE ? TEAM_HORDE : TEAM_ALLIANCE;

        _totalTime = 0;
        _shipsStarted = false;

        UpdateWorldState(BG_SA_ALLY_ATTACKS, _attackers == TEAM_ALLIANCE);
        UpdateWorldState(BG_SA_HORDE_ATTACKS, _attackers == TEAM_HORDE);

        UpdateWorldState(BG_SA_RIGHT_ATT_TOKEN_ALL, _attackers == TEAM_ALLIANCE);
        UpdateWorldState(BG_SA_LEFT_ATT_TOKEN_ALL, _attackers == TEAM_ALLIANCE);

        UpdateWorldState(BG_SA_RIGHT_ATT_TOKEN_HRD, _attackers == TEAM_HORDE);
        UpdateWorldState(BG_SA_LEFT_ATT_TOKEN_HRD, _attackers == TEAM_HORDE);

        UpdateWorldState(BG_SA_HORDE_DEFENCE_TOKEN, defenders == TEAM_HORDE);
        UpdateWorldState(BG_SA_ALLIANCE_DEFENCE_TOKEN, defenders == TEAM_ALLIANCE);

        CaptureGraveyard(StrandOfTheAncientsGraveyard::Central, defenders);
        CaptureGraveyard(StrandOfTheAncientsGraveyard::West, defenders);
        CaptureGraveyard(StrandOfTheAncientsGraveyard::East, defenders);

        UpdateWorldState(BG_SA_ATTACKER_TEAM, _attackers);

        for (ObjectGuid const& guid : _gateGUIDs)
            if (GameObject* gate = battlegroundMap->GetGameObject(guid))
                gate->SetDestructibleState(GO_DESTRUCTIBLE_INTACT, nullptr, true);

        BG_SA_GateState const state = _attackers == TEAM_ALLIANCE ? BG_SA_HORDE_GATE_OK : BG_SA_ALLIANCE_GATE_OK;
        UpdateWorldState(BG_SA_PURPLE_GATEWS, state);
        UpdateWorldState(BG_SA_RED_GATEWS, state);
        UpdateWorldState(BG_SA_BLUE_GATEWS, state);
        UpdateWorldState(BG_SA_GREEN_GATEWS, state);
        UpdateWorldState(BG_SA_YELLOW_GATEWS, state);
        UpdateWorldState(BG_SA_ANCIENT_GATEWS, state);

        battlegroundMap->UpdateSpawnGroupConditions();

        if (GameObject* door = battlegroundMap->GetGameObject(_collisionDoorGUID))
            door->ResetDoorOrButton();

        battleground->SetStatus(STATUS_WAIT_JOIN);
        battlegroundMap->DoOnPlayers([&](Player* player)
        {
            SendTransportInit(player);
        });

        TeleportPlayers();
    }

    void StartShips()
    {
        if (_shipsStarted)
            return;

        for (ObjectGuid const& guid : _boatGUIDs[_attackers])
        {
            if (GameObject* boat = battlegroundMap->GetGameObject(guid))
            {
                boat->SetGoState(GO_STATE_TRANSPORT_STOPPED);

                // make sure every player knows the transport exists & is moving
                for (auto const& [playerGuid, _] : battleground->GetPlayers())
                    if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                        boat->SendUpdateToPlayer(player);
            }
        }

        _shipsStarted = true;
    }

    void OnPlayerJoined(Player* player, bool inBattleground) override
    {
        BattlegroundScript::OnPlayerJoined(player, inBattleground);
        SendTransportInit(player);
        if (!inBattleground)
            TeleportToEntrancePosition(player);
    }

    void TeleportPlayers() const
    {
        for (auto const& [playerGuid, bp] : battleground->GetPlayers())
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
    void TeleportToEntrancePosition(Player* player) const
    {
        if (Battleground::GetTeamIndexByTeamId(battleground->GetPlayerTeam(player->GetGUID())) == _attackers)
        {
            ObjectGuid const boatGUID = _boatGUIDs[_attackers][urand(0, 1)];

            if (GameObject* boat = battlegroundMap->GetGameObject(boatGUID))
            {
                if (TransportBase* transport = boat->ToTransportBase())
                {
                    player->Relocate(spawnPositionOnTransport[_attackers]);
                    transport->AddPassenger(player);
                    player->m_movementInfo.transport.pos.Relocate(spawnPositionOnTransport[_attackers]);
                    float x, y, z, o;
                    spawnPositionOnTransport[_attackers].GetPosition(x, y, z, o);
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

    void ProcessEvent(WorldObject* obj, uint32 eventId, WorldObject* invoker) override
    {
        BattlegroundScript::ProcessEvent(obj, eventId, invoker);

        switch (eventId)
        {
            case EVENT_ALLIANCE_ASSAULT_STARTED:
                for (ObjectGuid const& bombGuid : _staticBombGUIDs[TEAM_ALLIANCE])
                    if (GameObject* bomb = battlegroundMap->GetGameObject(bombGuid))
                        bomb->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                break;
            case EVENT_HORDE_ASSAULT_STARTED:
                for (ObjectGuid const& bombGuid : _staticBombGUIDs[TEAM_HORDE])
                    if (GameObject* bomb = battlegroundMap->GetGameObject(bombGuid))
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
                            BG_SA_GateState gateState = _attackers == TEAM_HORDE ? BG_SA_ALLIANCE_GATE_DAMAGED : BG_SA_HORDE_GATE_DAMAGED;

                            if (Creature* c = obj->FindNearestCreature(NPC_WORLD_TRIGGER, 500.0f))
                                battleground->SendChatMessage(c, gate->DamagedText, invoker);

                            battleground->PlaySoundToAll(_attackers == TEAM_ALLIANCE ? SOUND_WALL_ATTACKED_ALLIANCE : SOUND_WALL_ATTACKED_HORDE);

                            UpdateWorldState(gate->WorldState, gateState);
                        }
                        // destroyed
                        else if (eventId == go->GetGOInfo()->destructibleBuilding.DestroyedEvent)
                        {
                            BG_SA_GateState gateState = _attackers == TEAM_HORDE ? BG_SA_ALLIANCE_GATE_DESTROYED : BG_SA_HORDE_GATE_DESTROYED;
                            if (Creature* c = obj->FindNearestCreature(NPC_WORLD_TRIGGER, 500.0f))
                                battleground->SendChatMessage(c, gate->DestroyedText, invoker);

                            battleground->PlaySoundToAll(_attackers == TEAM_ALLIANCE ? SOUND_WALL_DESTROYED_ALLIANCE : SOUND_WALL_DESTROYED_HORDE);

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
                                        battleground->UpdatePvpStat(player, PVP_STAT_GATES_DESTROYED, 1);
                                        if (rewardHonor)
                                            battleground->UpdatePlayerScore(player, SCORE_BONUS_HONOR, battleground->GetBonusHonorFromKill(1));
                                    }
                                }
                            }

                            if (rewardHonor)
                                MakeObjectsInteractable(gate->LineOfDefense);

                            UpdateWorldState(gate->WorldState, gateState);
                            battlegroundMap->UpdateSpawnGroupConditions();
                        }
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }

    void OnUnitKilled(Creature* victim, Unit* killer) override
    {
        if (victim->GetEntry() == NPC_DEMOLISHER_SA)
        {
            if (Player* killerPlayer = killer->GetCharmerOrOwnerPlayerOrPlayerItself())
                battleground->UpdatePvpStat(killerPlayer, PVP_STAT_DEMOLISHERS_DESTROYED, 1);
            int32 worldStateId = _attackers == TEAM_HORDE ? BG_SA_DESTROYED_HORDE_VEHICLES : BG_SA_DESTROYED_ALLIANCE_VEHICLES;
            int32 currentDestroyedVehicles = sWorldStateMgr->GetValue(worldStateId, battlegroundMap);
            UpdateWorldState(worldStateId, currentDestroyedVehicles + 1);
        }
    }

    void CaptureGraveyard(StrandOfTheAncientsGraveyard graveyard, TeamId teamId)
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

    void TitanRelicActivated(Player const* clicker)
    {
        if (!clicker)
            return;

        TeamId const clickerTeamId = Battleground::GetTeamIndexByTeamId(battleground->GetPlayerTeam(clicker->GetGUID()));
        if (clickerTeamId == _attackers)
        {
            if (clickerTeamId == TEAM_ALLIANCE)
                battleground->SendBroadcastText(BG_SA_TEXT_ALLIANCE_CAPTURED_TITAN_PORTAL, CHAT_MSG_BG_SYSTEM_ALLIANCE);
            else
                battleground->SendBroadcastText(BG_SA_TEXT_HORDE_CAPTURED_TITAN_PORTAL, CHAT_MSG_BG_SYSTEM_HORDE);

            if (_status == BG_SA_ROUND_ONE)
            {
                EndRound();
                // Achievement Storm the Beach (1310)
                for (auto itr = battleground->GetPlayers().begin(); itr != battleground->GetPlayers().end(); ++itr)
                {
                    if (Player* player = ObjectAccessor::FindPlayer(itr->first))
                        if (Battleground::GetTeamIndexByTeamId(battleground->GetPlayerTeam(player->GetGUID())) == _attackers)
                            player->UpdateCriteria(CriteriaType::BeSpellTarget, 65246);
                }

                if (Creature* c = FindKanrethad())
                    battleground->SendChatMessage(c, TEXT_ROUND_1_FINISHED);
            }
            else if (_status == BG_SA_ROUND_TWO)
            {
                _roundScores[1].winner = _attackers;
                _roundScores[1].time = _totalTime;
                ToggleTimer();
                // Achievement Storm the Beach (1310)
                for (auto itr = battleground->GetPlayers().begin(); itr != battleground->GetPlayers().end(); ++itr)
                {
                    if (Player* player = ObjectAccessor::FindPlayer(itr->first))
                        if (Battleground::GetTeamIndexByTeamId(battleground->GetPlayerTeam(player->GetGUID())) == _attackers && _roundScores[1].winner == _attackers)
                            player->UpdateCriteria(CriteriaType::BeSpellTarget, 65246);
                }

                if (_roundScores[0].time == _roundScores[1].time)
                    battleground->EndBattleground(TEAM_OTHER);
                else if (_roundScores[0].time < _roundScores[1].time)
                    battleground->EndBattleground(_roundScores[0].winner == TEAM_ALLIANCE ? ALLIANCE : HORDE);
                else
                    battleground->EndBattleground(_roundScores[1].winner == TEAM_ALLIANCE ? ALLIANCE : HORDE);
            }
        }
    }

    void ToggleTimer()
    {
        _timerEnabled = !_timerEnabled;
        UpdateWorldState(BG_SA_ENABLE_TIMER, _timerEnabled);
    }

    void OnEnd(Team winner) override
    {
        BattlegroundScript::OnEnd(winner);

        // honor reward for winning
        if (winner == ALLIANCE)
            battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(1), ALLIANCE);
        else if (winner == HORDE)
            battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(1), HORDE);

        // complete map_end rewards (even if no team wins)
        battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(2), ALLIANCE);
        battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(2), HORDE);
    }

    void SendTransportInit(Player* player) const
    {
        for (ObjectGuid const& boatGuid : _boatGUIDs[_attackers])
            if (GameObject* boat = battlegroundMap->GetGameObject(boatGuid))
                boat->SendUpdateToPlayer(player);
    }

    bool IsGateDestroyed(GateInfo const* gateInfo) const
    {
        if (!gateInfo)
            return false;

        int32 value = battlegroundMap->GetWorldStateValue(gateInfo->WorldState);
        return value == BG_SA_ALLIANCE_GATE_DESTROYED || value == BG_SA_HORDE_GATE_DESTROYED;
    }

    void HandleCaptureGraveyardAction(GameObject const* graveyardBanner, Player const* player)
    {
        if (!graveyardBanner || !player)
            return;

        TeamId const teamId = Battleground::GetTeamIndexByTeamId(battleground->GetPlayerTeam(player->GetGUID()));
        // Only attackers can capture graveyard by gameobject action
        if (teamId != _attackers)
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

    void MakeObjectsInteractable(DefenseLine defenseLine) const
    {
        auto makeInteractable = [&](ObjectGuid const& guid) -> void
        {
            if (GameObject* gameObject = battlegroundMap->GetGameObject(guid))
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
                if (GameObject* door = battlegroundMap->GetGameObject(_collisionDoorGUID))
                    door->UseDoorOrButton();

                makeInteractable(_titanRelicGUID);
                break;
            default:
                break;
        }
    }

    Creature* FindKanrethad() const
    {
        return battlegroundMap->GetCreature(_kanrethadGUID);
    }

    void EndRound()
    {
        _roundScores[0].winner = _attackers;
        _roundScores[0].time = std::min<uint32>(_totalTime, BG_SA_ROUNDLENGTH);

        _attackers = (_attackers == TEAM_ALLIANCE) ? TEAM_HORDE : TEAM_ALLIANCE;
        _status = BG_SA_SECOND_WARMUP;
        _totalTime = 0;
        ToggleTimer();

        _updateWaitTimer = 5000;
        _signaledRoundTwo = false;
        _signaledRoundTwoHalfMin = false;
        _initSecondRound = true;
        ResetObjs();
        battlegroundMap->UpdateAreaDependentAuras();

        battleground->CastSpellOnTeam(SPELL_END_OF_ROUND, ALLIANCE);
        battleground->CastSpellOnTeam(SPELL_END_OF_ROUND, HORDE);

        battleground->RemoveAuraOnTeam(SPELL_CARRYING_SEAFORIUM_CHARGE, HORDE);
        battleground->RemoveAuraOnTeam(SPELL_CARRYING_SEAFORIUM_CHARGE, ALLIANCE);
    }

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        BattlegroundScript::OnGameObjectCreate(gameobject);

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
                if (_status != BG_SA_SECOND_WARMUP && _status != BG_SA_WARMUP)
                    gameobject->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                break;
            case GO_SEAFORIUM_BOMB_H:
                _staticBombGUIDs[TEAM_HORDE].insert(gameobject->GetGUID());
                if (_status != BG_SA_SECOND_WARMUP && _status != BG_SA_WARMUP)
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

    void DoAction(uint32 actionId, WorldObject* source, WorldObject* target) override
    {
        BattlegroundScript::DoAction(actionId, source, target);

        switch (actionId)
        {
            case ACTION_SOTA_CAPTURE_GRAVEYARD:
                HandleCaptureGraveyardAction(Object::ToGameObject(target), Object::ToPlayer(source));
                break;
            default:
                break;
        }
    }

    void OnCreatureCreate(Creature* creature) override
    {
        BattlegroundScript::OnCreatureCreate(creature);
        switch (creature->GetEntry())
        {
            case NPC_DEMOLISHER:
                creature->SetFaction(BG_SA_Factions[_attackers]);
                break;
            case NPC_ANTIPERSONNEL_CANNON:
                creature->SetFaction(BG_SA_Factions[_attackers == TEAM_HORDE ? TEAM_ALLIANCE : TEAM_HORDE]);
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

    uint32 GetData(uint32 dataId) const override
    {
        switch (dataId)
        {
            case DATA_ATTACKERS:
                return _attackers;
            case DATA_STATUS:
                return _status;
            default:
                return BattlegroundScript::GetData(dataId);
        }
    }

    static GateInfo const* GetGate(uint32 entry)
    {
        for (GateInfo const& gate : Gates)
            if (gate.GameObjectId == entry)
                return &gate;

        return nullptr;
    }

private:
    /// Id of attacker team
    TeamId _attackers;

    /// Totale elapsed time of current round
    uint32 _totalTime;
    /// Max time of round
    uint32 _endRoundTimer;
    /// For know if boats has start moving or not yet
    bool _shipsStarted;
    /// Statu of battle (Start or not, and what round)
    BG_SA_Status _status;
    /// Score of each round
    std::array<BG_SA_RoundScore, 2> _roundScores;
    /// used for know we are in timer phase or not (used for worldstate update)
    bool _timerEnabled;
    /// 5secs before starting the 1min countdown for second round
    uint32 _updateWaitTimer;
    /// for know if warning about second round start has been sent
    bool _signaledRoundTwo;
    /// for know if warning about second round start has been sent
    bool _signaledRoundTwoHalfMin;
    /// for know if second round has been init
    bool _initSecondRound;

    // [team][boat_idx]
    std::array<std::array<ObjectGuid, 2 /*BOAT_COUNT*/>, PVP_TEAMS_COUNT> _boatGUIDs;
    std::array<GuidUnorderedSet, PVP_TEAMS_COUNT> _staticBombGUIDs; // bombs ready to be picked up
    GuidUnorderedSet _dynamicBombGUIDs; // bombs thrown by players, ready to explode/disarm

    ObjectGuid _graveyardWest;
    ObjectGuid _graveyardEast;
    ObjectGuid _graveyardCentral;
    GuidUnorderedSet _gateGUIDs;
    ObjectGuid _collisionDoorGUID;
    ObjectGuid _kanrethadGUID;
    ObjectGuid _titanRelicGUID;
};

void AddSC_battleground_strand_of_the_ancients()
{
    RegisterBattlegroundMapScript(battleground_strand_of_the_ancients, 607);
}
