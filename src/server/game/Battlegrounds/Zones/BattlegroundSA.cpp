/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
#include "Creature.h"
#include "CreatureAI.h"
#include "DB2Stores.h"
#include "GameObject.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Random.h"
#include "UpdateData.h"
#include "WorldStatePackets.h"

BattlegroundSA::BattlegroundSA()
{
    StartMessageIds[BG_STARTING_EVENT_FOURTH] = 0; // handle by Kanrethad

    BgObjects.resize(BG_SA_MAXOBJ);
    BgCreatures.resize(BG_SA_MAXNPC + BG_SA_MAX_GY);
    TimerEnabled = false;
    UpdateWaitTimer = 0;
    SignaledRoundTwo = false;
    SignaledRoundTwoHalfMin = false;
    InitSecondRound = false;
    _gateDestroyed = false;
    Attackers = TEAM_ALLIANCE;
    TotalTime = 0;
    EndRoundTimer = 0;
    ShipsStarted = false;
    Status = BG_SA_NOT_STARTED;

    for (uint8 i = 0; i < MAX_GATES; ++i)
        GateStatus[i] = BG_SA_GATE_OK;

    for (uint8 i = 0; i < 2; i++)
    {
        RoundScores[i].winner = TEAM_ALLIANCE;
        RoundScores[i].time = 0;
        _allVehiclesAlive[i] = true;
    }

    //! This is here to prevent an uninitialised variable warning
    //! The warning only occurs when SetUpBattleGround fails though.
    //! In the future this function should be called BEFORE sending initial worldstates.
    memset(&GraveyardStatus, 0, sizeof(GraveyardStatus));
}

BattlegroundSA::~BattlegroundSA() { }

void BattlegroundSA::Reset()
{
    TotalTime = 0;
    Attackers = ((urand(0, 1)) ? TEAM_ALLIANCE : TEAM_HORDE);
    for (uint8 i = 0; i <= 5; i++)
        GateStatus[i] = BG_SA_GATE_OK;
    ShipsStarted = false;
    _gateDestroyed = false;
    _allVehiclesAlive[TEAM_ALLIANCE] = true;
    _allVehiclesAlive[TEAM_HORDE] = true;
    Status = BG_SA_WARMUP;
}

bool BattlegroundSA::SetupBattleground()
{
    return ResetObjs();
}

bool BattlegroundSA::ResetObjs()
{
    for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
        if (Player* player = ObjectAccessor::FindPlayer(itr->first))
            SendTransportsRemove(player);

    uint32 atF = BG_SA_Factions[Attackers];
    uint32 defF = BG_SA_Factions[Attackers ? TEAM_ALLIANCE : TEAM_HORDE];

    for (uint8 i = 0; i < BG_SA_MAXOBJ; i++)
        DelObject(i);

    for (uint8 i = 0; i < BG_SA_MAXNPC; i++)
        DelCreature(i);

    for (uint8 i = BG_SA_MAXNPC; i < BG_SA_MAXNPC + BG_SA_MAX_GY; i++)
        DelCreature(i);

    for (uint8 i = 0; i < MAX_GATES; ++i)
        GateStatus[i] = BG_SA_GATE_OK;

    if (!AddCreature(BG_SA_NpcEntries[BG_SA_NPC_KANRETHAD], BG_SA_NPC_KANRETHAD, BG_SA_NpcSpawnlocs[BG_SA_NPC_KANRETHAD]))
    {
        TC_LOG_ERROR("bg.battleground", "SOTA: couldn't spawn Kanrethad, aborted. Entry: %u", BG_SA_NpcEntries[BG_SA_NPC_KANRETHAD]);
        return false;
    }

    for (uint8 i = 0; i <= BG_SA_PORTAL_DEFFENDER_RED; i++)
    {
        if (!AddObject(i, BG_SA_ObjEntries[i], BG_SA_ObjSpawnlocs[i], 0, 0, 0, 0, RESPAWN_ONE_DAY))
        {
            TC_LOG_ERROR("bg.battleground", "SOTA: couldn't spawn BG_SA_PORTAL_DEFFENDER_RED, Entry: %u", BG_SA_ObjEntries[i]);
            continue;
        }
    }

    for (uint8 i = BG_SA_BOAT_ONE; i <= BG_SA_BOAT_TWO; i++)
    {
        uint32 boatid = 0;
        switch (i)
        {
            case BG_SA_BOAT_ONE:
                boatid = Attackers ? BG_SA_BOAT_ONE_H : BG_SA_BOAT_ONE_A;
                break;
            case BG_SA_BOAT_TWO:
                boatid = Attackers ? BG_SA_BOAT_TWO_H : BG_SA_BOAT_TWO_A;
                break;
            default:
                break;
        }
        if (!AddObject(i, boatid, BG_SA_ObjSpawnlocs[i].GetPositionX(),
          BG_SA_ObjSpawnlocs[i].GetPositionY(),
          BG_SA_ObjSpawnlocs[i].GetPositionZ() + (Attackers ? -3.750f: 0),
          BG_SA_ObjSpawnlocs[i].GetOrientation(), 0, 0, 0, 0, RESPAWN_ONE_DAY))
        {
            TC_LOG_ERROR("bg.battleground", "SOTA: couldn't spawn one of the BG_SA_BOAT, Entry: %u", boatid);
            continue;
        }
    }

    for (uint8 i = BG_SA_SIGIL_1; i <= BG_SA_LEFT_FLAGPOLE; i++)
    {
        if (!AddObject(i, BG_SA_ObjEntries[i], BG_SA_ObjSpawnlocs[i], 0, 0, 0, 0, RESPAWN_ONE_DAY))
        {
            TC_LOG_ERROR("bg.battleground", "SOTA: couldn't spawn Sigil, Entry: %u", BG_SA_ObjEntries[i]);
            continue;
        }
    }

    // MAD props for Kiper for discovering those values - 4 hours of his work.
    GetBGObject(BG_SA_BOAT_ONE)->SetParentRotation(QuaternionData(0.f, 0.f, 1.0f, 0.0002f));
    GetBGObject(BG_SA_BOAT_TWO)->SetParentRotation(QuaternionData(0.f, 0.f, 1.0f, 0.00001f));
    SpawnBGObject(BG_SA_BOAT_ONE, RESPAWN_IMMEDIATELY);
    SpawnBGObject(BG_SA_BOAT_TWO, RESPAWN_IMMEDIATELY);

    //Cannons and demolishers - NPCs are spawned
    //By capturing GYs.
    for (uint8 i = 0; i < BG_SA_DEMOLISHER_5; i++)
    {
        if (!AddCreature(BG_SA_NpcEntries[i], i, BG_SA_NpcSpawnlocs[i], Attackers == TEAM_ALLIANCE ? TEAM_HORDE : TEAM_ALLIANCE, 600))
        {
            TC_LOG_ERROR("bg.battleground", "SOTA: couldn't spawn Cannon or demolisher, Entry: %u, Attackers: %s", BG_SA_NpcEntries[i], Attackers == TEAM_ALLIANCE ? "Horde(1)" : "Alliance(0)");
            continue;
        }
    }

    OverrideGunFaction();
    DemolisherStartState(true);

    for (uint8 i = 0; i <= BG_SA_PORTAL_DEFFENDER_RED; i++)
    {
        SpawnBGObject(i, RESPAWN_IMMEDIATELY);
        GetBGObject(i)->SetFaction(defF);
    }

    GetBGObject(BG_SA_TITAN_RELIC)->SetFaction(atF);
    GetBGObject(BG_SA_TITAN_RELIC)->Refresh();

    TotalTime = 0;
    ShipsStarted = false;

    //Graveyards
    for (uint8 i = 0; i < BG_SA_MAX_GY; i++)
    {
        WorldSafeLocsEntry const* sg = sWorldSafeLocsStore.LookupEntry(BG_SA_GYEntries[i]);
        if (!sg)
        {
            TC_LOG_ERROR("bg.battleground", "SOTA: Can't find GY entry %u", BG_SA_GYEntries[i]);
            return false;
        }

        if (i == BG_SA_BEACH_GY)
        {
            GraveyardStatus[i] = Attackers;
            AddSpiritGuide(i + BG_SA_MAXNPC, sg->Loc.X, sg->Loc.Y, sg->Loc.Z, BG_SA_GYOrientation[i], Attackers);
        }
        else
        {
            GraveyardStatus[i] = ((Attackers == TEAM_HORDE)? TEAM_ALLIANCE : TEAM_HORDE);
            if (!AddSpiritGuide(i + BG_SA_MAXNPC, sg->Loc.X, sg->Loc.Y, sg->Loc.Z, BG_SA_GYOrientation[i], Attackers == TEAM_HORDE ? TEAM_ALLIANCE : TEAM_HORDE))
                TC_LOG_ERROR("bg.battleground", "SOTA: couldn't spawn GY: %u", i);
        }
    }

    //GY capture points
    for (uint8 i = BG_SA_CENTRAL_FLAG; i <= BG_SA_LEFT_FLAG; i++)
    {
        if (!AddObject(i, (BG_SA_ObjEntries[i] - (Attackers == TEAM_ALLIANCE ? 1 : 0)), BG_SA_ObjSpawnlocs[i], 0, 0, 0, 0, RESPAWN_ONE_DAY))
        {
            TC_LOG_ERROR("bg.battleground", "SOTA: couldn't spawn Central Flag Entry: %u", BG_SA_ObjEntries[i] - (Attackers == TEAM_ALLIANCE ? 1 : 0));
            continue;
        }
        GetBGObject(i)->SetFaction(atF);
    }

    UpdateObjectInteractionFlags();

    for (uint8 i = BG_SA_BOMB; i < BG_SA_MAXOBJ; i++)
    {
        if (!AddObject(i, BG_SA_ObjEntries[BG_SA_BOMB], BG_SA_ObjSpawnlocs[i], 0, 0, 0, 0, RESPAWN_ONE_DAY))
        {
            TC_LOG_ERROR("bg.battleground", "SOTA: couldn't spawn SA Bomb Entry: %u", BG_SA_ObjEntries[BG_SA_BOMB] + i);
            continue;
        }
        GetBGObject(i)->SetFaction(atF);
    }

    //Player may enter BEFORE we set up BG - lets update his worldstates anyway...
    UpdateWorldState(BG_SA_RIGHT_GY_HORDE, GraveyardStatus[BG_SA_RIGHT_CAPTURABLE_GY] == TEAM_HORDE ? 1 : 0);
    UpdateWorldState(BG_SA_LEFT_GY_HORDE, GraveyardStatus[BG_SA_LEFT_CAPTURABLE_GY] == TEAM_HORDE ? 1 : 0);
    UpdateWorldState(BG_SA_CENTER_GY_HORDE, GraveyardStatus[BG_SA_CENTRAL_CAPTURABLE_GY] == TEAM_HORDE ? 1 : 0);

    UpdateWorldState(BG_SA_RIGHT_GY_ALLIANCE, GraveyardStatus[BG_SA_RIGHT_CAPTURABLE_GY] == TEAM_ALLIANCE ? 1 : 0);
    UpdateWorldState(BG_SA_LEFT_GY_ALLIANCE, GraveyardStatus[BG_SA_LEFT_CAPTURABLE_GY] == TEAM_ALLIANCE ? 1 : 0);
    UpdateWorldState(BG_SA_CENTER_GY_ALLIANCE, GraveyardStatus[BG_SA_CENTRAL_CAPTURABLE_GY] == TEAM_ALLIANCE ? 1 : 0);

    if (Attackers == TEAM_ALLIANCE)
    {
        UpdateWorldState(BG_SA_ALLY_ATTACKS, 1);
        UpdateWorldState(BG_SA_HORDE_ATTACKS, 0);

        UpdateWorldState(BG_SA_RIGHT_ATT_TOKEN_ALL, 1);
        UpdateWorldState(BG_SA_LEFT_ATT_TOKEN_ALL, 1);
        UpdateWorldState(BG_SA_RIGHT_ATT_TOKEN_HRD, 0);
        UpdateWorldState(BG_SA_LEFT_ATT_TOKEN_HRD, 0);

        UpdateWorldState(BG_SA_HORDE_DEFENCE_TOKEN, 1);
        UpdateWorldState(BG_SA_ALLIANCE_DEFENCE_TOKEN, 0);
    }
    else
    {
        UpdateWorldState(BG_SA_HORDE_ATTACKS, 1);
        UpdateWorldState(BG_SA_ALLY_ATTACKS, 0);

        UpdateWorldState(BG_SA_RIGHT_ATT_TOKEN_ALL, 0);
        UpdateWorldState(BG_SA_LEFT_ATT_TOKEN_ALL, 0);
        UpdateWorldState(BG_SA_RIGHT_ATT_TOKEN_HRD, 1);
        UpdateWorldState(BG_SA_LEFT_ATT_TOKEN_HRD, 1);

        UpdateWorldState(BG_SA_HORDE_DEFENCE_TOKEN, 0);
        UpdateWorldState(BG_SA_ALLIANCE_DEFENCE_TOKEN, 1);
    }

    UpdateWorldState(BG_SA_PURPLE_GATEWS, 1);
    UpdateWorldState(BG_SA_RED_GATEWS, 1);
    UpdateWorldState(BG_SA_BLUE_GATEWS, 1);
    UpdateWorldState(BG_SA_GREEN_GATEWS, 1);
    UpdateWorldState(BG_SA_YELLOW_GATEWS, 1);
    UpdateWorldState(BG_SA_ANCIENT_GATEWS, 1);

    for (int i = BG_SA_BOAT_ONE; i <= BG_SA_BOAT_TWO; i++)
        for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer(itr->first))
                SendTransportInit(player);

    // set status manually so preparation is cast correctly in 2nd round too
    SetStatus(STATUS_WAIT_JOIN);

    TeleportPlayers();
    return true;
}

void BattlegroundSA::StartShips()
{
    if (ShipsStarted)
        return;

    DoorOpen(BG_SA_BOAT_ONE);
    DoorOpen(BG_SA_BOAT_TWO);

    for (int i = BG_SA_BOAT_ONE; i <= BG_SA_BOAT_TWO; i++)
    {
        for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
        {
            if (Player* p = ObjectAccessor::FindPlayer(itr->first))
            {
                UpdateData data(p->GetMapId());
                WorldPacket pkt;
                GetBGObject(i)->BuildValuesUpdateBlockForPlayer(&data, p);
                data.BuildPacket(&pkt);
                p->SendDirectMessage(&pkt);
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
        if (TotalTime >= BG_SA_WARMUPLENGTH)
        {
            if (Creature* c = GetBGCreature(BG_SA_NPC_KANRETHAD))
                SendChatMessage(c, TEXT_ROUND_STARTED);

            TotalTime = 0;
            ToggleTimer();
            DemolisherStartState(false);
            Status = BG_SA_ROUND_ONE;
            StartCriteriaTimer(CRITERIA_TIMED_TYPE_EVENT, (Attackers == TEAM_ALLIANCE) ? 23748 : 21702);
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

        if (TotalTime >= 60000)
        {
            if (Creature* c = GetBGCreature(BG_SA_NPC_KANRETHAD))
                SendChatMessage(c, TEXT_ROUND_STARTED);

            TotalTime = 0;
            ToggleTimer();
            DemolisherStartState(false);
            Status = BG_SA_ROUND_TWO;
            StartCriteriaTimer(CRITERIA_TIMED_TYPE_EVENT, (Attackers == TEAM_ALLIANCE) ? 23748 : 21702);
            // status was set to STATUS_WAIT_JOIN manually for Preparation, set it back now
            SetStatus(STATUS_IN_PROGRESS);
            for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
                if (Player* p = ObjectAccessor::FindPlayer(itr->first))
                    p->RemoveAurasDueToSpell(SPELL_BG_PREPARATION);
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
                CastSpellOnTeam(SPELL_END_OF_ROUND, ALLIANCE);
                CastSpellOnTeam(SPELL_END_OF_ROUND, HORDE);
                RoundScores[0].winner = Attackers;
                RoundScores[0].time = BG_SA_ROUNDLENGTH;
                TotalTime = 0;
                Status = BG_SA_SECOND_WARMUP;
                Attackers = (Attackers == TEAM_ALLIANCE) ? TEAM_HORDE : TEAM_ALLIANCE;
                UpdateWaitTimer = 5000;
                SignaledRoundTwo = false;
                SignaledRoundTwoHalfMin = false;
                InitSecondRound = true;
                ToggleTimer();
                ResetObjs();
                GetBgMap()->UpdateAreaDependentAuras();
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
                    EndBattleground(0);
                else if (RoundScores[0].time < RoundScores[1].time)
                    EndBattleground(RoundScores[0].winner == TEAM_ALLIANCE ? ALLIANCE : HORDE);
                else
                    EndBattleground(RoundScores[1].winner == TEAM_ALLIANCE ? ALLIANCE : HORDE);
                return;
            }
        }
        if (Status == BG_SA_ROUND_ONE || Status == BG_SA_ROUND_TWO)
        {
            SendTime();
            UpdateDemolisherSpawns();
        }
    }
}

void BattlegroundSA::StartingEventCloseDoors() { }

void BattlegroundSA::StartingEventOpenDoors() { }

void BattlegroundSA::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    bool allyAttacks = Attackers == TEAM_ALLIANCE;
    bool hordeAttacks = Attackers == TEAM_HORDE;

    packet.Worldstates.emplace_back(uint32(BG_SA_ANCIENT_GATEWS), int32(GateStatus[BG_SA_ANCIENT_GATE]));
    packet.Worldstates.emplace_back(uint32(BG_SA_YELLOW_GATEWS), int32(GateStatus[BG_SA_YELLOW_GATE]));
    packet.Worldstates.emplace_back(uint32(BG_SA_GREEN_GATEWS), int32(GateStatus[BG_SA_GREEN_GATE]));
    packet.Worldstates.emplace_back(uint32(BG_SA_BLUE_GATEWS), int32(GateStatus[BG_SA_BLUE_GATE]));
    packet.Worldstates.emplace_back(uint32(BG_SA_RED_GATEWS), int32(GateStatus[BG_SA_RED_GATE]));
    packet.Worldstates.emplace_back(uint32(BG_SA_PURPLE_GATEWS), int32(GateStatus[BG_SA_PURPLE_GATE]));

    packet.Worldstates.emplace_back(uint32(BG_SA_BONUS_TIMER), 0);

    packet.Worldstates.emplace_back(uint32(BG_SA_HORDE_ATTACKS), int32(hordeAttacks));
    packet.Worldstates.emplace_back(uint32(BG_SA_ALLY_ATTACKS), int32(allyAttacks));

    // Time will be sent on first update...
    packet.Worldstates.emplace_back(uint32(BG_SA_ENABLE_TIMER), int32(TimerEnabled));
    packet.Worldstates.emplace_back(uint32(BG_SA_TIMER_MINS), 0);
    packet.Worldstates.emplace_back(uint32(BG_SA_TIMER_SEC_TENS), 0);
    packet.Worldstates.emplace_back(uint32(BG_SA_TIMER_SEC_DECS), 0);

    packet.Worldstates.emplace_back(uint32(BG_SA_RIGHT_GY_HORDE), int32(GraveyardStatus[BG_SA_RIGHT_CAPTURABLE_GY] == TEAM_HORDE));
    packet.Worldstates.emplace_back(uint32(BG_SA_LEFT_GY_HORDE), int32(GraveyardStatus[BG_SA_LEFT_CAPTURABLE_GY] == TEAM_HORDE));
    packet.Worldstates.emplace_back(uint32(BG_SA_CENTER_GY_HORDE), int32(GraveyardStatus[BG_SA_CENTRAL_CAPTURABLE_GY] == TEAM_HORDE));

    packet.Worldstates.emplace_back(uint32(BG_SA_RIGHT_GY_ALLIANCE), int32(GraveyardStatus[BG_SA_RIGHT_CAPTURABLE_GY] == TEAM_ALLIANCE));
    packet.Worldstates.emplace_back(uint32(BG_SA_LEFT_GY_ALLIANCE), int32(GraveyardStatus[BG_SA_LEFT_CAPTURABLE_GY] == TEAM_ALLIANCE));
    packet.Worldstates.emplace_back(uint32(BG_SA_CENTER_GY_ALLIANCE), int32(GraveyardStatus[BG_SA_CENTRAL_CAPTURABLE_GY] == TEAM_ALLIANCE));

    packet.Worldstates.emplace_back(uint32(BG_SA_HORDE_DEFENCE_TOKEN), int32(allyAttacks));
    packet.Worldstates.emplace_back(uint32(BG_SA_ALLIANCE_DEFENCE_TOKEN), int32(hordeAttacks));

    packet.Worldstates.emplace_back(uint32(BG_SA_LEFT_ATT_TOKEN_HRD), int32(hordeAttacks));
    packet.Worldstates.emplace_back(uint32(BG_SA_RIGHT_ATT_TOKEN_HRD), int32(hordeAttacks));
    packet.Worldstates.emplace_back(uint32(BG_SA_RIGHT_ATT_TOKEN_ALL), int32(allyAttacks));
    packet.Worldstates.emplace_back(uint32(BG_SA_LEFT_ATT_TOKEN_ALL), int32(allyAttacks));
}

void BattlegroundSA::AddPlayer(Player* player)
{
    Battleground::AddPlayer(player);
    PlayerScores[player->GetGUID()] = new BattlegroundSAScore(player->GetGUID(), player->GetBGTeam());

    SendTransportInit(player);

    TeleportToEntrancePosition(player);
}

void BattlegroundSA::RemovePlayer(Player* /*player*/, ObjectGuid /*guid*/, uint32 /*team*/) { }

void BattlegroundSA::HandleAreaTrigger(Player* /*source*/, uint32 /*trigger*/, bool /*entered*/)
{
    // this is wrong way to implement these things. On official it done by gameobject spell cast.
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;
}

void BattlegroundSA::TeleportPlayers()
{
    for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
    {
        if (Player* player = ObjectAccessor::FindPlayer(itr->first))
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

            player->CastSpell(player, SPELL_BG_PREPARATION, true);

            TeleportToEntrancePosition(player);
        }
    }
}

void BattlegroundSA::TeleportToEntrancePosition(Player* player)
{
    if (player->GetTeamId() == Attackers)
    {
        if (!ShipsStarted)
        {
            // player->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);

            if (urand(0, 1))
                player->TeleportTo(607, 2682.936f, -830.368f, 15.0f, 2.895f, 0);
            else
                player->TeleportTo(607, 2577.003f, 980.261f, 15.0f, 0.807f, 0);
        }
        else
            player->TeleportTo(607, 1600.381f, -106.263f, 8.8745f, 3.78f, 0);
    }
    else
        player->TeleportTo(607, 1209.7f, -65.16f, 70.1f, 0.0f, 0);
}

void BattlegroundSA::ProcessEvent(WorldObject* obj, uint32 eventId, WorldObject* invoker /*= NULL*/)
{
    if (GameObject* go = obj->ToGameObject())
    {
        switch (go->GetGoType())
        {
            case GAMEOBJECT_TYPE_GOOBER:
                if (invoker)
                    if (eventId == BG_SA_EVENT_TITAN_RELIC_ACTIVATED)
                        TitanRelicActivated(invoker->ToPlayer());
                break;
            case GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING:
            {
                if (GateInfo const* gate = GetGate(obj->GetEntry()))
                {
                    uint8 gateId = gate->GateId;

                    // damaged
                    if (eventId == go->GetGOInfo()->destructibleBuilding.DamagedEvent)
                    {
                        GateStatus[gateId] = BG_SA_GATE_DAMAGED;

                        if (Creature* c = obj->FindNearestCreature(NPC_WORLD_TRIGGER, 500.0f))
                            SendChatMessage(c, gate->DamagedText, invoker);

                        PlaySoundToAll(Attackers == TEAM_ALLIANCE ? SOUND_WALL_ATTACKED_ALLIANCE : SOUND_WALL_ATTACKED_HORDE);
                    }
                    // destroyed
                    else if (eventId == go->GetGOInfo()->destructibleBuilding.DestroyedEvent)
                    {
                        GateStatus[gate->GateId] = BG_SA_GATE_DESTROYED;
                        _gateDestroyed = true;

                        if (gateId < 5)
                            DelObject(gateId + 14);

                        if (Creature* c = obj->FindNearestCreature(NPC_WORLD_TRIGGER, 500.0f))
                            SendChatMessage(c, gate->DestroyedText, invoker);

                        PlaySoundToAll(Attackers == TEAM_ALLIANCE ? SOUND_WALL_DESTROYED_ALLIANCE : SOUND_WALL_DESTROYED_HORDE);

                        bool rewardHonor = true;
                        switch (gateId)
                        {
                            case BG_SA_GREEN_GATE:
                                if (GateStatus[BG_SA_BLUE_GATE] == BG_SA_GATE_DESTROYED)
                                    rewardHonor = false;
                                break;
                            case BG_SA_BLUE_GATE:
                                if (GateStatus[BG_SA_GREEN_GATE] == BG_SA_GATE_DESTROYED)
                                    rewardHonor = false;
                                break;
                            case BG_SA_RED_GATE:
                                if (GateStatus[BG_SA_PURPLE_GATE] == BG_SA_GATE_DESTROYED)
                                    rewardHonor = false;
                                break;
                            case BG_SA_PURPLE_GATE:
                                if (GateStatus[BG_SA_RED_GATE] == BG_SA_GATE_DESTROYED)
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
                                    UpdatePlayerScore(player, SCORE_DESTROYED_WALL, 1);
                                    if (rewardHonor)
                                        UpdatePlayerScore(player, SCORE_BONUS_HONOR, GetBonusHonorFromKill(1));
                                }
                            }
                        }

                        UpdateObjectInteractionFlags();
                    }
                    else
                        break;

                    UpdateWorldState(gate->WorldState, GateStatus[gateId]);
                }
                break;
            }
            default:
                break;
        }
    }
}

void BattlegroundSA::HandleKillUnit(Creature* creature, Player* killer)
{
    if (creature->GetEntry() == NPC_DEMOLISHER_SA)
    {
        UpdatePlayerScore(killer, SCORE_DESTROYED_DEMOLISHER, 1);
        _allVehiclesAlive[Attackers] = false;
    }
}

/*
  You may ask what the fuck does it do?
  Prevents owner overwriting guns faction with own.
 */
void BattlegroundSA::OverrideGunFaction()
{
    if (!BgCreatures[0])
        return;

    for (uint8 i = BG_SA_GUN_1; i <= BG_SA_GUN_10; i++)
    {
        if (Creature* gun = GetBGCreature(i))
            gun->setFaction(BG_SA_Factions[Attackers ? TEAM_ALLIANCE : TEAM_HORDE]);
    }

    for (uint8 i = BG_SA_DEMOLISHER_1; i <= BG_SA_DEMOLISHER_4; i++)
    {
        if (Creature* dem = GetBGCreature(i))
            dem->setFaction(BG_SA_Factions[Attackers]);
    }
}

void BattlegroundSA::DemolisherStartState(bool start)
{
    if (!BgCreatures[0])
        return;

    // set flags only for the demolishers on the beach, factory ones dont need it
    for (uint8 i = BG_SA_DEMOLISHER_1; i <= BG_SA_DEMOLISHER_4; i++)
    {
        if (Creature* dem = GetBGCreature(i))
        {
            if (start)
                dem->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            else
                dem->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        }
    }
}

void BattlegroundSA::DestroyGate(Player* /*player*/, GameObject* /*go*/)
{
}

WorldSafeLocsEntry const* BattlegroundSA::GetClosestGraveYard(Player* player)
{
    uint32 safeloc = 0;
    WorldSafeLocsEntry const* ret;
    WorldSafeLocsEntry const* closest;
    float dist, nearest;
    float x, y, z;

    player->GetPosition(x, y, z);

    if (player->GetTeamId() == Attackers)
        safeloc = BG_SA_GYEntries[BG_SA_BEACH_GY];
    else
        safeloc = BG_SA_GYEntries[BG_SA_DEFENDER_LAST_GY];

    closest = sWorldSafeLocsStore.LookupEntry(safeloc);
    nearest = player->GetExactDistSq(closest->Loc.X, closest->Loc.Y, closest->Loc.Z);

    for (uint8 i = BG_SA_RIGHT_CAPTURABLE_GY; i < BG_SA_MAX_GY; i++)
    {
        if (GraveyardStatus[i] != player->GetTeamId())
            continue;

        ret = sWorldSafeLocsStore.LookupEntry(BG_SA_GYEntries[i]);
        dist = player->GetExactDistSq(ret->Loc.X, ret->Loc.Y, ret->Loc.Z);
        if (dist < nearest)
        {
            closest = ret;
            nearest = dist;
        }
    }

    return closest;
}

void BattlegroundSA::SendTime()
{
    uint32 end_of_round = (EndRoundTimer - TotalTime);
    UpdateWorldState(BG_SA_TIMER_MINS, end_of_round/60000);
    UpdateWorldState(BG_SA_TIMER_SEC_TENS, (end_of_round%60000)/10000);
    UpdateWorldState(BG_SA_TIMER_SEC_DECS, ((end_of_round%60000)%10000)/1000);
}

bool BattlegroundSA::CanInteractWithObject(uint32 objectId)
{
    switch (objectId)
    {
        case BG_SA_TITAN_RELIC:
            if (GateStatus[BG_SA_ANCIENT_GATE] != BG_SA_GATE_DESTROYED || GateStatus[BG_SA_YELLOW_GATE] != BG_SA_GATE_DESTROYED)
                return false;
            // no break
        case BG_SA_CENTRAL_FLAG:
            if (GateStatus[BG_SA_RED_GATE] != BG_SA_GATE_DESTROYED && GateStatus[BG_SA_PURPLE_GATE] != BG_SA_GATE_DESTROYED)
                return false;
            // no break
        case BG_SA_LEFT_FLAG:
        case BG_SA_RIGHT_FLAG:
            if (GateStatus[BG_SA_GREEN_GATE] != BG_SA_GATE_DESTROYED && GateStatus[BG_SA_BLUE_GATE] != BG_SA_GATE_DESTROYED)
                return false;
            break;
        default:
            ABORT();
            break;
    }

    return true;
}

void BattlegroundSA::UpdateObjectInteractionFlags(uint32 objectId)
{
    if (GameObject* go = GetBGObject(objectId))
    {
        if (CanInteractWithObject(objectId))
            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
        else
            go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
    }
}

void BattlegroundSA::UpdateObjectInteractionFlags()
{
    for (uint8 i = BG_SA_CENTRAL_FLAG; i <= BG_SA_LEFT_FLAG; ++i)
        UpdateObjectInteractionFlags(i);
    UpdateObjectInteractionFlags(BG_SA_TITAN_RELIC);
}

void BattlegroundSA::EventPlayerClickedOnFlag(Player* source, GameObject* go)
{
    switch (go->GetEntry())
    {
        case 191307:
        case 191308:
            if (CanInteractWithObject(BG_SA_LEFT_FLAG))
                CaptureGraveyard(BG_SA_LEFT_CAPTURABLE_GY, source);
            break;
        case 191305:
        case 191306:
            if (CanInteractWithObject(BG_SA_RIGHT_FLAG))
                CaptureGraveyard(BG_SA_RIGHT_CAPTURABLE_GY, source);
            break;
        case 191310:
        case 191309:
            if (CanInteractWithObject(BG_SA_CENTRAL_FLAG))
                CaptureGraveyard(BG_SA_CENTRAL_CAPTURABLE_GY, source);
            break;
        default:
            return;
    };
}

void BattlegroundSA::CaptureGraveyard(BG_SA_Graveyards i, Player* Source)
{
    if (GraveyardStatus[i] == Attackers)
        return;

    DelCreature(BG_SA_MAXNPC + i);
    GraveyardStatus[i] = Source->GetTeamId();
    WorldSafeLocsEntry const* sg = sWorldSafeLocsStore.LookupEntry(BG_SA_GYEntries[i]);
    if (!sg)
    {
        TC_LOG_ERROR("bg.battleground", "BattlegroundSA::CaptureGraveyard: non-existant GY entry: %u", BG_SA_GYEntries[i]);
        return;
    }

    AddSpiritGuide(i + BG_SA_MAXNPC, sg->Loc.X, sg->Loc.Y, sg->Loc.Z, BG_SA_GYOrientation[i], GraveyardStatus[i]);
    uint32 npc = 0;
    uint32 flag = 0;

    switch (i)
    {
        case BG_SA_LEFT_CAPTURABLE_GY:
            flag = BG_SA_LEFT_FLAG;
            DelObject(flag);
            AddObject(flag, (BG_SA_ObjEntries[flag] - (Source->GetTeamId() == TEAM_ALLIANCE ? 0 : 1)),
                BG_SA_ObjSpawnlocs[flag], 0, 0, 0, 0, RESPAWN_ONE_DAY);

            npc = BG_SA_NPC_RIGSPARK;
            if (Creature* rigspark = AddCreature(BG_SA_NpcEntries[npc], npc, BG_SA_NpcSpawnlocs[npc], Attackers))
                rigspark->AI()->Talk(TEXT_SPARKLIGHT_RIGSPARK_SPAWN);

            for (uint8 j = BG_SA_DEMOLISHER_7; j <= BG_SA_DEMOLISHER_8; j++)
            {
                AddCreature(BG_SA_NpcEntries[j], j, BG_SA_NpcSpawnlocs[j], (Attackers == TEAM_ALLIANCE ? TEAM_HORDE : TEAM_ALLIANCE), 600);

                if (Creature* dem = GetBGCreature(j))
                    dem->setFaction(BG_SA_Factions[Attackers]);
            }

            UpdateWorldState(BG_SA_LEFT_GY_ALLIANCE, GraveyardStatus[i] == TEAM_ALLIANCE);
            UpdateWorldState(BG_SA_LEFT_GY_HORDE, GraveyardStatus[i] == TEAM_HORDE);

            if (Creature* c = Source->FindNearestCreature(NPC_WORLD_TRIGGER, 500.0f))
                SendChatMessage(c, Source->GetTeamId() == TEAM_ALLIANCE ? TEXT_WEST_GRAVEYARD_CAPTURED_A : TEXT_WEST_GRAVEYARD_CAPTURED_H, Source);

            break;
        case BG_SA_RIGHT_CAPTURABLE_GY:
            flag = BG_SA_RIGHT_FLAG;
            DelObject(flag);
            AddObject(flag, (BG_SA_ObjEntries[flag] - (Source->GetTeamId() == TEAM_ALLIANCE ? 0 : 1)),
                BG_SA_ObjSpawnlocs[flag], 0, 0, 0, 0, RESPAWN_ONE_DAY);

            npc = BG_SA_NPC_SPARKLIGHT;
            if (Creature* sparklight = AddCreature(BG_SA_NpcEntries[npc], npc, BG_SA_NpcSpawnlocs[npc], Attackers))
                sparklight->AI()->Talk(TEXT_SPARKLIGHT_RIGSPARK_SPAWN);

            for (uint8 j = BG_SA_DEMOLISHER_5; j <= BG_SA_DEMOLISHER_6; j++)
            {
                AddCreature(BG_SA_NpcEntries[j], j, BG_SA_NpcSpawnlocs[j], Attackers == TEAM_ALLIANCE ? TEAM_HORDE : TEAM_ALLIANCE, 600);

                if (Creature* dem = GetBGCreature(j))
                    dem->setFaction(BG_SA_Factions[Attackers]);
            }

            UpdateWorldState(BG_SA_RIGHT_GY_ALLIANCE, GraveyardStatus[i] == TEAM_ALLIANCE);
            UpdateWorldState(BG_SA_RIGHT_GY_HORDE, GraveyardStatus[i] == TEAM_HORDE);

            if (Creature* c = Source->FindNearestCreature(NPC_WORLD_TRIGGER, 500.0f))
                SendChatMessage(c, Source->GetTeamId() == TEAM_ALLIANCE ? TEXT_EAST_GRAVEYARD_CAPTURED_A : TEXT_EAST_GRAVEYARD_CAPTURED_H, Source);

            break;
        case BG_SA_CENTRAL_CAPTURABLE_GY:
            flag = BG_SA_CENTRAL_FLAG;
            DelObject(flag);
            AddObject(flag, (BG_SA_ObjEntries[flag] - (Source->GetTeamId() == TEAM_ALLIANCE ? 0 : 1)),
              BG_SA_ObjSpawnlocs[flag], 0, 0, 0, 0, RESPAWN_ONE_DAY);

            UpdateWorldState(BG_SA_CENTER_GY_ALLIANCE, GraveyardStatus[i] == TEAM_ALLIANCE);
            UpdateWorldState(BG_SA_CENTER_GY_HORDE, GraveyardStatus[i] == TEAM_HORDE);

            if (Creature* c = Source->FindNearestCreature(NPC_WORLD_TRIGGER, 500.0f))
                SendChatMessage(c, Source->GetTeamId() == TEAM_ALLIANCE ? TEXT_SOUTH_GRAVEYARD_CAPTURED_A : TEXT_SOUTH_GRAVEYARD_CAPTURED_H, Source);

            break;
        default:
            ABORT();
            break;
    };
}

void BattlegroundSA::TitanRelicActivated(Player* clicker)
{
    if (!clicker)
        return;

    if (CanInteractWithObject(BG_SA_TITAN_RELIC))
    {
        if (clicker->GetTeamId() == Attackers)
        {
            if (clicker->GetTeamId() == TEAM_ALLIANCE)
                SendBroadcastText(BG_SA_TEXT_ALLIANCE_CAPTURED_TITAN_PORTAL, CHAT_MSG_BG_SYSTEM_ALLIANCE);
            else
                SendBroadcastText(BG_SA_TEXT_HORDE_CAPTURED_TITAN_PORTAL, CHAT_MSG_BG_SYSTEM_HORDE);

            if (Status == BG_SA_ROUND_ONE)
            {
                RoundScores[0].winner = Attackers;
                RoundScores[0].time = TotalTime;
                // Achievement Storm the Beach (1310)
                for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
                {
                    if (Player* player = ObjectAccessor::FindPlayer(itr->first))
                        if (player->GetTeamId() == Attackers)
                            player->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 65246);
                }

                Attackers = (Attackers == TEAM_ALLIANCE) ? TEAM_HORDE : TEAM_ALLIANCE;
                Status = BG_SA_SECOND_WARMUP;
                TotalTime = 0;
                ToggleTimer();

                if (Creature* c = GetBGCreature(BG_SA_NPC_KANRETHAD))
                    SendChatMessage(c, TEXT_ROUND_1_FINISHED);

                UpdateWaitTimer = 5000;
                SignaledRoundTwo = false;
                SignaledRoundTwoHalfMin = false;
                InitSecondRound = true;
                ResetObjs();
                GetBgMap()->UpdateAreaDependentAuras();
                CastSpellOnTeam(SPELL_END_OF_ROUND, ALLIANCE);
                CastSpellOnTeam(SPELL_END_OF_ROUND, HORDE);
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
                        if (player->GetTeamId() == Attackers && RoundScores[1].winner == Attackers)
                            player->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 65246);
                }

                if (RoundScores[0].time == RoundScores[1].time)
                    EndBattleground(0);
                else if (RoundScores[0].time < RoundScores[1].time)
                    EndBattleground(RoundScores[0].winner == TEAM_ALLIANCE ? ALLIANCE : HORDE);
                else
                    EndBattleground(RoundScores[1].winner == TEAM_ALLIANCE ? ALLIANCE : HORDE);
            }
        }
    }
}

void BattlegroundSA::ToggleTimer()
{
    TimerEnabled = !TimerEnabled;
    UpdateWorldState(BG_SA_ENABLE_TIMER, TimerEnabled);
}

void BattlegroundSA::EndBattleground(uint32 winner)
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

void BattlegroundSA::UpdateDemolisherSpawns()
{
    for (uint8 i = BG_SA_DEMOLISHER_1; i <= BG_SA_DEMOLISHER_8; i++)
    {
        if (!BgCreatures[i].IsEmpty())
        {
            if (Creature* Demolisher = GetBGCreature(i))
            {
                if (Demolisher->isDead())
                {
                    // Demolisher is not in list
                    if (DemoliserRespawnList.find(i) == DemoliserRespawnList.end())
                    {
                        DemoliserRespawnList[i] = getMSTime()+30000;
                    }
                    else
                    {
                        if (DemoliserRespawnList[i] < getMSTime())
                        {
                            Demolisher->Relocate(BG_SA_NpcSpawnlocs[i]);
                            Demolisher->Respawn();
                            DemoliserRespawnList.erase(i);
                        }
                    }
                }
            }
        }
    }
}

void BattlegroundSA::SendTransportInit(Player* player)
{
    if (!BgObjects[BG_SA_BOAT_ONE].IsEmpty() || !BgObjects[BG_SA_BOAT_TWO].IsEmpty())
    {
        UpdateData transData(player->GetMapId());
        if (!BgObjects[BG_SA_BOAT_ONE].IsEmpty())
            GetBGObject(BG_SA_BOAT_ONE)->BuildCreateUpdateBlockForPlayer(&transData, player);

        if (!BgObjects[BG_SA_BOAT_TWO].IsEmpty())
            GetBGObject(BG_SA_BOAT_TWO)->BuildCreateUpdateBlockForPlayer(&transData, player);

        WorldPacket packet;
        transData.BuildPacket(&packet);
        player->SendDirectMessage(&packet);
    }
}

void BattlegroundSA::SendTransportsRemove(Player* player)
{
    if (!BgObjects[BG_SA_BOAT_ONE].IsEmpty() || !BgObjects[BG_SA_BOAT_TWO].IsEmpty())
    {
        UpdateData transData(player->GetMapId());
        if (!BgObjects[BG_SA_BOAT_ONE].IsEmpty())
            GetBGObject(BG_SA_BOAT_ONE)->BuildOutOfRangeUpdateBlock(&transData);
        if (!BgObjects[BG_SA_BOAT_TWO].IsEmpty())
            GetBGObject(BG_SA_BOAT_TWO)->BuildOutOfRangeUpdateBlock(&transData);
        WorldPacket packet;
        transData.BuildPacket(&packet);
        player->SendDirectMessage(&packet);
    }
}

bool BattlegroundSA::CheckAchievementCriteriaMeet(uint32 criteriaId, Player const* source, Unit const* target, uint32 miscValue)
{
    switch (criteriaId)
    {
        case BG_CRITERIA_CHECK_NOT_EVEN_A_SCRATCH:
            return _allVehiclesAlive[GetTeamIndexByTeamId(source->GetTeam())];
        case BG_CRITERIA_CHECK_DEFENSE_OF_THE_ANCIENTS:
            return source->GetTeamId() != Attackers && !_gateDestroyed;
    }

    return Battleground::CheckAchievementCriteriaMeet(criteriaId, source, target, miscValue);
}

bool BattlegroundSA::IsSpellAllowed(uint32 spellId, Player const* /*player*/) const
{
    switch (spellId)
    {
        case SPELL_ALLIANCE_CONTROL_PHASE_SHIFT:
            return Attackers == TEAM_HORDE;
        case SPELL_HORDE_CONTROL_PHASE_SHIFT:
            return Attackers == TEAM_ALLIANCE;
        case SPELL_BG_PREPARATION:
            return Status == BG_SA_WARMUP || Status == BG_SA_SECOND_WARMUP;
        default:
           break;
    }

    return true;
}
