/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "BattlegroundScore.h"
#include "BattlegroundSA.h"
#include "GameObject.h"
#include "Language.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "WorldPacket.h"
#include "WorldSession.h"

void BattlegroundSA::InstallBattleground()
{
    _timerEnabled = false;
    BgCreatures.resize(BG_SA_MAXNPC + BG_SA_MAX_GY);
}
    Attackers = TEAM_ALLIANCE;
    TotalTime = 0;
    EndRoundTimer = 0;
    ShipsStarted = false;
    Status = BG_SA_NOT_STARTED;

    _attackers = urand(BG_TEAM_ALLIANCE, BG_TEAM_HORDE);
        GateStatus[i] = BG_SA_GATE_OK;

    for (uint8 i = 0; i < 2; i++)
        RoundScores[i].winner = TEAM_ALLIANCE;
        RoundScores[i].time = 0;
        _allVehiclesAlive[i] = true;
    }

    //! This is here to prevent an uninitialised variable warning
    //! The warning only occurs when SetUpBattleGround fails though.
    //! In the future this function should be called BEFORE sending initial worldstates.
    memset(&GraveyardStatus, 0, sizeof(GraveyardStatus));

    _shipsStarted = false;

    _round = 0;
    _gateDestroyed = false;
    _allVehiclesAlive[TEAM_ALLIANCE] = true;
    _allVehiclesAlive[TEAM_HORDE] = true;
}

void BattlegroundSA::InitializeTextIds()
{
    PreparationPhaseTextIds[BG_STARTING_EVENT_FIRST]  = LANG_BG_SA_START_TWO_MINUTES;
    PreparationPhaseTextIds[BG_STARTING_EVENT_SECOND] = LANG_BG_SA_START_ONE_MINUTE;
    PreparationPhaseTextIds[BG_STARTING_EVENT_THIRD]  = LANG_BG_SA_START_HALF_MINUTE;
    PreparationPhaseTextIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_SA_HAS_BEGUN;
}

void BattlegroundSA::InitializeObjects()
{
    for (uint8 i = 0; i < BG_SA_MAXOBJ; ++i)
        DeleteGameObject(i);
    for (uint8 i = 0; i < BG_SA_MAXNPC; ++i)
        DeleteCreature(i);

    for (uint8 i = BG_SA_MAXNPC; i < BG_SA_MAXNPC + BG_SA_MAX_GY; ++i)
        DeleteCreature(i);

    for (uint8 i = 0; i < BG_SA_GATE_COUNT; ++i)
        _gateStatus[i] = BG_SA_GATE_OK;

    for (uint8 i = 0; i < BG_SA_BOAT_ONE; ++i)
        AddGameObject(i, BG_SA_ObjEntries[i], BG_SA_ObjSpawnlocs[i][0], BG_SA_ObjSpawnlocs[i][1], BG_SA_ObjSpawnlocs[i][2], BG_SA_ObjSpawnlocs[i][3], 0, 0, 0, 0, RESPAWN_ONE_DAY);

    for (uint8 i = BG_SA_BOAT_ONE; i < BG_SA_SIGIL_1; ++i)
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
    for (uint8 i = BG_SA_SIGIL_1; i < BG_SA_CENTRAL_FLAG; i++)
}

void BattlegroundSA::ResetObjectsAndWorldstates()
{
    uint32 atF = BG_SA_Factions[_attackers];
    uint32 defF = BG_SA_Factions[_attackers ? BG_TEAM_ALLIANCE : BG_TEAM_HORDE];

    for (uint8 i = BG_SA_BOAT_ONE; i <= BG_SA_BOAT_TWO; ++i)
        for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
            if (Player* player = itr->getSource())
                SendTransportsRemove(player);

    // MAD props for Kiper for discovering those values - 4 hours of his work.
    GetGameObject(BG_SA_BOAT_ONE)->UpdateRotationFields(1.0f, 0.0002f);
    GetGameObject(BG_SA_BOAT_TWO)->UpdateRotationFields(1.0f, 0.00001f);
    SpawnGameObject(BG_SA_BOAT_ONE, RESPAWN_IMMEDIATELY);
    SpawnGameObject(BG_SA_BOAT_TWO, RESPAWN_IMMEDIATELY);

    //Cannons and demolishers - NPCs are spawned
    //By capturing GYs.
    for (uint8 i = 0; i < BG_SA_DEMOLISHER_5; i++)
        AddCreature(BG_SA_NpcEntries[i], i, (_attackers == BG_TEAM_ALLIANCE ? BG_TEAM_HORDE : BG_TEAM_ALLIANCE), BG_SA_NpcSpawnlocs[i][0], BG_SA_NpcSpawnlocs[i][1], BG_SA_NpcSpawnlocs[i][2], BG_SA_NpcSpawnlocs[i][3], 600);
        if (!AddCreature(BG_SA_NpcEntries[i], i, (Attackers == TEAM_ALLIANCE ? TEAM_HORDE : TEAM_ALLIANCE),
              BG_SA_NpcSpawnlocs[i][0], BG_SA_NpcSpawnlocs[i][1],
              BG_SA_NpcSpawnlocs[i][2], BG_SA_NpcSpawnlocs[i][3], 600))
        return false;
        }

    OverrideGunFaction();
    DemolisherStartState(true);

    for (uint8 i = 0; i <= BG_SA_PORTAL_DEFFENDER_RED; i++)
    {
        SpawnGameObject(i, RESPAWN_IMMEDIATELY);
        GetBGObject(i)->SetUInt32Value(GAMEOBJECT_FACTION, defF);
    }

    GetGameObject(BG_SA_TITAN_RELIC)->SetUInt32Value(GAMEOBJECT_FACTION, atF);
    GetGameObject(BG_SA_TITAN_RELIC)->Refresh();

    _shipsStarted = false;

    //Graveyards
    for (uint8 i = 0; i < BG_SA_MAX_GY; i++)
    {
        WorldSafeLocsEntry const* sg = NULL;
        sg = sWorldSafeLocsStore.LookupEntry(BG_SA_GYEntries[i]);

        if (i == BG_SA_BEACH_GY && sg)
        {
            _graveyardStatus[i] = _attackers;
            AddSpiritGuide(i + BG_SA_MAXNPC, sg->x, sg->y, sg->z, BG_SA_GYOrientation[i], ((_attackers == BG_TEAM_HORDE)? HORDE : ALLIANCE));
        }

        else if (sg)
        {
            _graveyardStatus[i] = ((_attackers == BG_TEAM_HORDE)? BG_TEAM_ALLIANCE : BG_TEAM_HORDE);
            AddSpiritGuide(i + BG_SA_MAXNPC, sg->Loc.X, sg->Loc.Y, sg->Loc.Z, BG_SA_GYOrientation[i], Attackers);
        }
            if (!AddSpiritGuide(i + BG_SA_MAXNPC, sg->x, sg->y, sg->z, BG_SA_GYOrientation[i], ((Attackers == TEAM_HORDE)? ALLIANCE : HORDE)))
                sLog->outError("SOTA: couldn't spawn GY: %u", i);
    }

    //GY capture points
    for (uint8 i = BG_SA_CENTRAL_FLAG; i <= BG_SA_LEFT_FLAG; i++)
    {
        AddGameObject(i, (BG_SA_ObjEntries[i] - (_attackers == BG_TEAM_ALLIANCE ? 1:0)),
        {
        AddObject(i, BG_SA_ObjEntries[i],
            continue;
        }
            0, 0, 0, 0, RESPAWN_ONE_DAY)->SetUInt32Value(GAMEOBJECT_FACTION, defF);
    }

    for (uint8 i = BG_SA_BOMB; i < BG_SA_MAXOBJ; i++)
    {
        if (!AddObject(i, BG_SA_ObjEntries[BG_SA_BOMB], BG_SA_ObjSpawnlocs[i], 0, 0, 0, 0, RESPAWN_ONE_DAY))
        {
            TC_LOG_ERROR("bg.battleground", "SOTA: couldn't spawn SA Bomb Entry: %u", BG_SA_ObjEntries[BG_SA_BOMB] + i);
            0, 0, 0, 0, RESPAWN_ONE_DAY)->SetUInt32Value(GAMEOBJECT_FACTION, atF);
        GetBGObject(i)->SetFaction(atF);
    }

    //Player may enter BEFORE we set up BG - lets update his worldstates anyway...
    UpdateWorldState(BG_SA_RIGHT_GY_HORDE , _graveyardStatus[BG_SA_RIGHT_CAPTURABLE_GY] == BG_TEAM_HORDE?1:0);
    UpdateWorldState(BG_SA_LEFT_GY_HORDE , _graveyardStatus[BG_SA_LEFT_CAPTURABLE_GY] == BG_TEAM_HORDE?1:0);
    UpdateWorldState(BG_SA_CENTER_GY_HORDE , _graveyardStatus[BG_SA_CENTRAL_CAPTURABLE_GY] == BG_TEAM_HORDE?1:0);

    UpdateWorldState(BG_SA_RIGHT_GY_ALLIANCE, GraveyardStatus[BG_SA_RIGHT_CAPTURABLE_GY] == TEAM_ALLIANCE ? 1 : 0);
    UpdateWorldState(BG_SA_LEFT_GY_ALLIANCE, GraveyardStatus[BG_SA_LEFT_CAPTURABLE_GY] == TEAM_ALLIANCE ? 1 : 0);
    UpdateWorldState(BG_SA_CENTER_GY_ALLIANCE, GraveyardStatus[BG_SA_CENTRAL_CAPTURABLE_GY] == TEAM_ALLIANCE ? 1 : 0);

    if (_attackers == BG_TEAM_ALLIANCE)
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

    for (uint8 i = BG_SA_BOAT_ONE; i <= BG_SA_BOAT_TWO; ++i)
        for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
            if (Player *plr = sObjectMgr->GetPlayer(itr->first))
                SendTransportInit(player);

    // set status manually so preparation is cast correctly in 2nd round too
    SetStatus(STATUS_WAIT_JOIN);

    TeleportPlayers();
}

void BattlegroundSA::StartBattleground()
{
    if (_round == 2 && _roundScores[0].time < BG_SA_ROUNDLENGTH)
        EndTimer = _roundScores[0].time;
    else
        EndTimer = BG_SA_ROUNDLENGTH;

    ToggleTimer();
    _timerWorldStateUpdate = 5 * IN_MILLISECONDS;
    DemolisherStartState(false);
    StartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, (_attackers == BG_TEAM_ALLIANCE) ? 23748 : 21702);
}

void BattlegroundSA::EndBattleground(BattlegroundWinner winner)
{
    //honor reward for winning
    if (winner == WINNER_ALLIANCE)
        RewardHonorToTeam(GetBonusHonorFromKill(1), BG_TEAM_ALLIANCE);
    else if (winner == WINNER_HORDE)
        RewardHonorToTeam(GetBonusHonorFromKill(1), BG_TEAM_HORDE);

    //complete map_end rewards (even if no team wins)
    RewardHonorToTeam(GetBonusHonorFromKill(2), BG_TEAM_ALLIANCE);
    RewardHonorToTeam(GetBonusHonorFromKill(2), BG_TEAM_HORDE);

    BattlegroundMap::EndBattleground(winner);
}

void BattlegroundSA::StartShips()
{
    if (_shipsStarted)
        return;

    DoorOpen(BG_SA_BOAT_ONE);
    DoorOpen(BG_SA_BOAT_TWO);

    for (int i = BG_SA_BOAT_ONE; i <= BG_SA_BOAT_TWO; i++)
    {
        for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
        {
            if (Player* p = ObjectAccessor::FindPlayer(itr->first))
            {
                UpdateData data(p->GetMapId());
                WorldPacket pkt;
                GetGameObject(i)->BuildValuesUpdateBlockForPlayer(&data, player);
                data.BuildPacket(&pkt);
                p->GetSession()->SendPacket(&pkt);
            }
        }
    }

    _shipsStarted = true;
        }
        else
}

    if (Status == BG_SA_WARMUP )
{
    if (PreparationPhase <= BG_STARTING_EVENT_FOURTH)
    {
        BattlegroundMap::ProcessPreparation(diff);
        if (_timerBoats <= diff)

            StartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, (Attackers == TEAM_ALLIANCE) ? 23748 : 21702);
            StartShips();
        else
            _timerBoats -= diff;
        return;
    }

    if (PreparationTimer <= diff)
    {
            SendWarningToAll(LANG_BG_SA_HAS_BEGUN);
                SendChatMessage(c, TEXT_ROUND_STARTED);

            // status was set to STATUS_WAIT_JOIN manually for Preparation, set it back now
            SetStatus(STATUS_IN_PROGRESS);
            for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
                if (Player* p = ObjectAccessor::FindPlayer(itr->first))
                    p->RemoveAurasDueToSpell(SPELL_PREPARATION);
        {
            case BG_STARTING_EVENT_FOURTH + 1:
                SendMessageToAll(LANG_BG_SA_ROUND_TWO_START_ONE_MINUTE, CHAT_MSG_BG_SYSTEM_NEUTRAL);
                PreparationTimer = 30 * IN_MILLISECONDS;   // Next message in 30 seconds
                StartShips();
                break;
            case BG_STARTING_EVENT_FOURTH + 2:
                SendMessageToAll(LANG_BG_SA_ROUND_TWO_START_HALF_MINUTE, CHAT_MSG_BG_SYSTEM_NEUTRAL);
                PreparationTimer = 30 * IN_MILLISECONDS;   // Start in 30 seconds
                break;
            case BG_STARTING_EVENT_FOURTH + 3:
                SendMessageToAll(LANG_BG_SA_HAS_BEGUN, CHAT_MSG_RAID_BOSS_EMOTE);
                StartBattleground();
                break;
                GetBgMap()->UpdateAreaDependentAuras();
                CastSpellOnTeam(SPELL_END_OF_ROUND, ALLIANCE);
                CastSpellOnTeam(SPELL_END_OF_ROUND, HORDE);
        }
    }
    else
        PreparationTimer -= diff;
}

void BattlegroundSA::ProcessInProgress(uint32 const& diff)
{
    BattlegroundMap::ProcessInProgress(diff);

    // Respawn dead demolishers
    UpdateDemolisherSpawns();

void BattlegroundSA::StartingEventCloseDoors() { }
        if (_timerWorldStateUpdate <= diff)
            SendTime();
        else
            _timerWorldStateUpdate -= diff;


void BattlegroundSA::StartingEventOpenDoors()
{
    switch (_round)
    {
        case 1:
            _roundScores[0].winner = _attackers == BG_TEAM_ALLIANCE ? BG_TEAM_HORDE : BG_TEAM_ALLIANCE;
            _roundScores[0].time = BG_SA_ROUNDLENGTH;

            _attackers = (1 - _attackers);
            Status = STATUS_WAIT_JOIN;
            _round = 2;
            PreparationTimer = BG_SA_WARMUPLENGTH / 2;
            _timerBoats = BG_SA_BOAT_START;
            ToggleTimer();
            ResetObjectsAndWorldstates();
            break;
        case 2:
            _roundScores[1].time = BG_SA_ROUNDLENGTH;
            _roundScores[1].winner = _attackers == BG_TEAM_ALLIANCE ? BG_TEAM_HORDE : BG_TEAM_ALLIANCE;

            if (_roundScores[0].time == _roundScores[1].time)
                EndBattleground(WINNER_NONE);
            else if (_roundScores[0].time < _roundScores[1].time)
                EndBattleground(_roundScores[0].winner == BG_TEAM_ALLIANCE ? WINNER_ALLIANCE : WINNER_HORDE);
            else
                EndBattleground(_roundScores[1].winner == BG_TEAM_ALLIANCE ? WINNER_ALLIANCE : WINNER_HORDE);
            break;
    }

void BattlegroundSA::FillInitialWorldStates(WorldPacket& data)
{
    bool allyAttacks = Attackers == TEAM_ALLIANCE;
    bool hordeAttacks = Attackers == TEAM_HORDE;

  data << uint32(BG_SA_ANCIENT_GATEWS) << uint32(GateStatus[BG_SA_ANCIENT_GATE]);
  data << uint32(BG_SA_YELLOW_GATEWS) << uint32(GateStatus[BG_SA_YELLOW_GATE]);
  data << uint32(BG_SA_GREEN_GATEWS) << uint32(GateStatus[BG_SA_GREEN_GATE]);
  data << uint32(BG_SA_BLUE_GATEWS) << uint32(GateStatus[BG_SA_BLUE_GATE]);
  data << uint32(BG_SA_RED_GATEWS) << uint32(GateStatus[BG_SA_RED_GATE]);
  data << uint32(BG_SA_PURPLE_GATEWS) << uint32(GateStatus[BG_SA_PURPLE_GATE]);

    data << uint32(BG_SA_BONUS_TIMER) << uint32(0);

    data << uint32(BG_SA_HORDE_ATTACKS) << uint32(hordeAttacks);
    data << uint32(BG_SA_ALLY_ATTACKS) << uint32(allyAttacks);

    // Time will be sent on first update...
  data << uint32(BG_SA_ENABLE_TIMER) << ((_timerEnabled) ? uint32(1) : uint32(0));
    data << uint32(BG_SA_TIMER_MINS) << uint32(0);
    data << uint32(BG_SA_TIMER_SEC_TENS) << uint32(0);
    data << uint32(BG_SA_TIMER_SEC_DECS) << uint32(0);

    data << uint32(BG_SA_RIGHT_GY_HORDE) << uint32(GraveyardStatus[BG_SA_RIGHT_CAPTURABLE_GY] == TEAM_HORDE);
    data << uint32(BG_SA_LEFT_GY_HORDE) << uint32(GraveyardStatus[BG_SA_LEFT_CAPTURABLE_GY] == TEAM_HORDE);
    data << uint32(BG_SA_CENTER_GY_HORDE) << uint32(GraveyardStatus[BG_SA_CENTRAL_CAPTURABLE_GY] == TEAM_HORDE);

  data << uint32(BG_SA_RIGHT_GY_ALLIANCE) << uint32(GraveyardStatus[BG_SA_RIGHT_CAPTURABLE_GY] == TEAM_ALLIANCE?1:0);
  data << uint32(BG_SA_LEFT_GY_ALLIANCE) << uint32(GraveyardStatus[BG_SA_LEFT_CAPTURABLE_GY] == TEAM_ALLIANCE?1:0);
  data << uint32(BG_SA_CENTER_GY_ALLIANCE) << uint32(GraveyardStatus[BG_SA_CENTRAL_CAPTURABLE_GY] == TEAM_ALLIANCE?1:0);

    data << uint32(BG_SA_HORDE_DEFENCE_TOKEN) << uint32(allyAttacks);
    data << uint32(BG_SA_ALLIANCE_DEFENCE_TOKEN) << uint32(hordeAttacks);

    data << uint32(BG_SA_LEFT_ATT_TOKEN_HRD) << uint32(hordeAttacks);
    data << uint32(BG_SA_RIGHT_ATT_TOKEN_HRD) << uint32(hordeAttacks);
    data << uint32(BG_SA_RIGHT_ATT_TOKEN_ALL) <<  uint32(allyAttacks);
    data << uint32(BG_SA_LEFT_ATT_TOKEN_ALL) <<  uint32(allyAttacks);
}

void BattlegroundSA::OnPlayerJoin(Player *plr)
{
    Battleground::AddPlayer(player);
    PlayerScores[player->GetGUID()] = new BattlegroundSAScore(player->GetGUID(), player->GetBGTeam());

    SendTransportInit(player);
    PlayerScores[plr->GetGUIDLow()] = sc;

    if (!_shipsStarted)
    {
        if (plr->GetTeamId() == Attackers)
        {
            //player->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);

            if (urand(0, 1))
                player->TeleportTo(607, 2682.936f, -830.368f, 15.0f, 2.895f, 0);
            else
                player->TeleportTo(607, 2577.003f, 980.261f, 15.0f, 0.807f, 0);

        }
        else
            player->TeleportTo(607, 1209.7f, -65.16f, 70.1f, 0.0f, 0);
    }
    else
    {
        if (plr->GetTeamId() == _attackers)
            player->TeleportTo(607, 1600.381f, -106.263f, 8.8745f, 3.78f, 0);
        else
            player->TeleportTo(607, 1209.7f, -65.16f, 70.1f, 0.0f, 0);
    }
void BattlegroundSA::RemovePlayer(Player* /*player*/, ObjectGuid /*guid*/, uint32 /*team*/) { }
}

    BattlegroundScoreMap::iterator itr = m_PlayerScores.find(Source->GetGUID());
    if (itr == m_PlayerScores.end())                         // player not found...
        ((BattlegroundSAScore*)itr->second)->DemolishersDestroyed += value;
        ((BattlegroundSAScore*)itr->second)->GatesDestroyed += value;
        Battleground::UpdatePlayerScore(Source, type, value, doAddHonor);
void BattlegroundSA::TeleportPlayers()
{
    for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
    {
        if (Player* player = itr->getSource())
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

            if (player->GetBGTeam() == _attackers)
                if (Player* p = ObjectAccessor::FindPlayer(itr->first))
                    p->CastSpell(p, SPELL_PREPARATION, true);

            if (player->GetTeamId() == Attackers)
            {
                plr->CastSpell(plr, 12438, true);     //Without this player falls before boat loads...

                if (urand(0, 1))
                    player->TeleportTo(607, 2682.936f, -830.368f, 15.0f, 2.895f, 0);
                else
                    player->TeleportTo(607, 2577.003f, 980.261f, 50.0f, 0.807f, 0);
            }
            else
                player->TeleportTo(607, 1209.7f, -65.16f, 70.1f, 0.0f, 0);
        }
    }
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
        GateStatus[i] = BG_SA_GATE_DAMAGED;
                        if (Creature* c = obj->FindNearestCreature(NPC_WORLD_TRIGGER, 500.0f))
                            SendChatMessage(c, gate->DamagedText, invoker);
            UpdateWorldState(uws, _gateStatus[i]);
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
            SendMessageToAll(LANG_BG_SA_CHAMBER_BREACHED, CHAT_MSG_RAID_BOSS_EMOTE);
                                    rewardHonor = false;
            SendMessageToAll(ParseStrings(LANG_BG_SA_WAS_DESTROYED, go->GetGOInfo()->name.c_str()), CHAT_MSG_RAID_BOSS_EMOTE);
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
        SendMessageToAll(ParseStrings(LANG_BG_SA_IS_UNDER_ATTACK, go->GetGOInfo()->name.c_str()), CHAT_MSG_RAID_BOSS_EMOTE);
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
                    }
                    else
                        break;

void BattlegroundSA::HandleKillUnit(Creature* unit, Player* killer)
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
    if (!m_BgCreatures[0])
    for (uint8 i = BG_SA_GUN_1; i <= BG_SA_GUN_10; i++)
    {
        if (Creature* gun = GetCreature(i))
            gun->setFaction(BG_SA_Factions[_attackers ? BG_TEAM_ALLIANCE : BG_TEAM_HORDE]);
    }

    for (uint8 i = BG_SA_DEMOLISHER_1; i <= BG_SA_DEMOLISHER_4; i++)
    {
        if (Creature* dem = GetCreature(i))
            dem->setFaction(BG_SA_Factions[_attackers]);
    }
}

void BattlegroundSA::DemolisherStartState(bool start)
{
    // set flags only for the demolishers on the beach, factory ones dont need it
    for (uint8 i = BG_SA_DEMOLISHER_1; i <= BG_SA_DEMOLISHER_4; i++)
    {
        if (Creature* dem = GetCreature(i))
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
    if (!_gateStatus[i])
    if (GameObject* g = GetGameObject(i))
            _gateStatus[i] = BG_SA_GATE_DESTROYED;
                UpdateWorldState(uws, GateStatus[i]);
                    if (_gateStatus[BG_SA_BLUE_GATE] == BG_SA_GATE_DESTROYED)
                    if (GateStatus[BG_SA_GREEN_GATE] == BG_SA_GATE_DESTROYED)
                    if (_gateStatus[BG_SA_PURPLE_GATE] == BG_SA_GATE_DESTROYED)
                    if (GateStatus[BG_SA_RED_GATE] == BG_SA_GATE_DESTROYED)
                DeleteGameObject(i+9);
}

WorldSafeLocsEntry const* BattlegroundSA::GetClosestGraveYard(Player* player)
{
    uint32 safeloc = 0;
    WorldSafeLocsEntry const* ret;
    WorldSafeLocsEntry const* closest;
    float dist, nearest;
    float x, y, z;

    player->GetPosition(x, y, z);

    if (player->GetTeamId() == _attackers)
        safeloc = BG_SA_GYEntries[BG_SA_BEACH_GY];
    else
        safeloc = BG_SA_GYEntries[BG_SA_DEFENDER_LAST_GY];

    closest = sWorldSafeLocsStore.LookupEntry(safeloc);
    nearest = std::sqrt((closest->Loc.X - x)*(closest->Loc.X - x) + (closest->Loc.Y - y)*(closest->Loc.Y - y) + (closest->Loc.Z - z)*(closest->Loc.Z - z));

    for (uint8 i = BG_SA_RIGHT_CAPTURABLE_GY; i < BG_SA_MAX_GY; i++)
    {
        if (_graveyardStatus[i] != player->GetTeamId())
            continue;

        ret = sWorldSafeLocsStore.LookupEntry(BG_SA_GYEntries[i]);
        dist = std::sqrt((ret->Loc.X - x)*(ret->Loc.X - x) + (ret->Loc.Y - y)*(ret->Loc.Y - y) + (ret->Loc.Z - z)*(ret->Loc.Z - z));
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
    UpdateWorldState(BG_SA_TIMER_MINS, EndTimer/60000);
    UpdateWorldState(BG_SA_TIMER_SEC_TENS, (EndTimer%60000)/10000);
    UpdateWorldState(BG_SA_TIMER_SEC_DECS, ((EndTimer%60000)%10000)/1000);
}

void BattlegroundSA::EventPlayerClickedOnFlag(Player* source, GameObject* go)
{
    switch (go->GetEntry())
    {
        case 191307:
        case 191308:
            if (_gateStatus[BG_SA_GREEN_GATE] == BG_SA_GATE_DESTROYED || _gateStatus[BG_SA_BLUE_GATE] == BG_SA_GATE_DESTROYED)
                CaptureGraveyard(BG_SA_LEFT_CAPTURABLE_GY, source);
            break;
        case 191305:
        case 191306:
            if (_gateStatus[BG_SA_GREEN_GATE] == BG_SA_GATE_DESTROYED || _gateStatus[BG_SA_BLUE_GATE] == BG_SA_GATE_DESTROYED)
                CaptureGraveyard(BG_SA_RIGHT_CAPTURABLE_GY, source);
            break;
        case 191310:
        case 191309:
            if ((_gateStatus[BG_SA_GREEN_GATE] == BG_SA_GATE_DESTROYED || _gateStatus[BG_SA_BLUE_GATE] == BG_SA_GATE_DESTROYED) && (_gateStatus[BG_SA_RED_GATE] == BG_SA_GATE_DESTROYED || _gateStatus[BG_SA_PURPLE_GATE] == BG_SA_GATE_DESTROYED))
                CaptureGraveyard(BG_SA_CENTRAL_CAPTURABLE_GY, source);
            break;
        default:
            return;
    };
}

void BattlegroundSA::CaptureGraveyard(BG_SA_Graveyards i, Player* Source)
{
    if (_graveyardStatus[i] == _attackers)
        return;

    DeleteCreature(BG_SA_MAXNPC + i);
    _graveyardStatus[i] = Source->GetTeamId();
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
            DeleteGameObject(flag);
            AddGameObject(flag, (BG_SA_ObjEntries[flag] - (Source->GetTeamId() == BG_TEAM_ALLIANCE ? 0:1)),
                BG_SA_ObjSpawnlocs[flag], 0, 0, 0, 0, RESPAWN_ONE_DAY);

            npc = BG_SA_NPC_RIGSPARK;
            AddCreature(BG_SA_NpcEntries[npc], npc, Attackers,
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

            UpdateWorldState(BG_SA_LEFT_GY_ALLIANCE, (_graveyardStatus[i] == BG_TEAM_ALLIANCE? 1:0));
            UpdateWorldState(BG_SA_LEFT_GY_HORDE, (_graveyardStatus[i] == BG_TEAM_ALLIANCE? 0:1));
            if (Source->GetTeamId() == BG_TEAM_ALLIANCE)
                SendMessageToAll(LANG_BG_SA_A_GY_WEST, CHAT_MSG_RAID_BOSS_EMOTE);
            break;
        case BG_SA_RIGHT_CAPTURABLE_GY:
            flag = BG_SA_RIGHT_FLAG;
            DeleteGameObject(flag);
            AddGameObject(flag, (BG_SA_ObjEntries[flag] - (Source->GetTeamId() == BG_TEAM_ALLIANCE ? 0:1)),
                BG_SA_ObjSpawnlocs[flag], 0, 0, 0, 0, RESPAWN_ONE_DAY);

            npc = BG_SA_NPC_SPARKLIGHT;
            AddCreature(BG_SA_NpcEntries[npc], npc, Attackers,
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

            UpdateWorldState(BG_SA_RIGHT_GY_ALLIANCE, (_graveyardStatus[i] == BG_TEAM_ALLIANCE? 1:0));
            UpdateWorldState(BG_SA_RIGHT_GY_HORDE, (_graveyardStatus[i] == BG_TEAM_ALLIANCE? 0:1));
            if (Source->GetTeamId() == BG_TEAM_ALLIANCE)
                SendMessageToAll(LANG_BG_SA_A_GY_EAST, CHAT_MSG_RAID_BOSS_EMOTE);
            break;
        case BG_SA_CENTRAL_CAPTURABLE_GY:
            flag = BG_SA_CENTRAL_FLAG;
            DeleteGameObject(flag);
            AddGameObject(flag, (BG_SA_ObjEntries[flag] - (Source->GetTeamId() == BG_TEAM_ALLIANCE ? 0:1)),
              BG_SA_ObjSpawnlocs[flag], 0, 0, 0, 0, RESPAWN_ONE_DAY);

            UpdateWorldState(BG_SA_CENTER_GY_ALLIANCE, GraveyardStatus[i] == TEAM_ALLIANCE);
            UpdateWorldState(BG_SA_CENTER_GY_HORDE, GraveyardStatus[i] == TEAM_HORDE);

            if (Creature* c = Source->FindNearestCreature(NPC_WORLD_TRIGGER, 500.0f))
                SendChatMessage(c, Source->GetTeamId() == TEAM_ALLIANCE ? TEXT_SOUTH_GRAVEYARD_CAPTURED_A : TEXT_SOUTH_GRAVEYARD_CAPTURED_H, Source);

            UpdateWorldState(BG_SA_CENTER_GY_ALLIANCE, (GraveyardStatus[i] == TEAM_ALLIANCE? 1:0));
            UpdateWorldState(BG_SA_CENTER_GY_HORDE, (GraveyardStatus[i] == TEAM_ALLIANCE? 0:1));
            if (Source->GetTeamId() == TEAM_ALLIANCE)
                SendWarningToAll(LANG_BG_SA_A_GY_SOUTH);
                SendWarningToAll(LANG_BG_SA_H_GY_SOUTH);
            break;
        default:
            ASSERT(false);
            break;
    };
}

void BattlegroundSA::EventPlayerUsedGO(Player* source, GameObject* object)
{
    if (!clicker)
        return;

    if (GateStatus[BG_SA_ANCIENT_GATE] == BG_SA_GATE_DESTROYED &&
        GateStatus[BG_SA_YELLOW_GATE] == BG_SA_GATE_DESTROYED &&
        (GateStatus[BG_SA_PURPLE_GATE] == BG_SA_GATE_DESTROYED || GateStatus[BG_SA_RED_GATE] == BG_SA_GATE_DESTROYED) &&
        (GateStatus[BG_SA_GREEN_GATE] == BG_SA_GATE_DESTROYED || GateStatus[BG_SA_BLUE_GATE] == BG_SA_GATE_DESTROYED))
    {
        if (source->GetBGTeam() == _attackers)
        {
            if (Source->GetTeamId() == TEAM_ALLIANCE)
                SendMessageToAll(LANG_BG_SA_ALLIANCE_CAPTURED_RELIC, CHAT_MSG_BG_SYSTEM_NEUTRAL);
            else
                SendMessageToAll(LANG_BG_SA_HORDE_CAPTURED_RELIC, CHAT_MSG_BG_SYSTEM_NEUTRAL);

            //Achievement Storm the Beach (1310)
            if ((BG_SA_ROUNDLENGTH - EndTimer) < 4 * MINUTE)
                for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
                    if (Player* player = itr->getSource())
                        if (player->GetBGTeam() == _attackers)
                            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, 65246);

            if (_round == 1)
            {
                    if (Player* player = ObjectAccessor::FindPlayer(itr->first))
                        if (player->GetTeamId() == Attackers)
                            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, 65246);
                
                _attackers = (_attackers == BG_TEAM_ALLIANCE) ? BG_TEAM_HORDE : BG_TEAM_ALLIANCE;
                ToggleTimer();
                SendMessageToAll(LANG_BG_SA_ROUND_ONE_END, CHAT_MSG_RAID_BOSS_EMOTE);
                if (Creature* c = GetBGCreature(BG_SA_NPC_KANRETHAD))
                    SendChatMessage(c, TEXT_ROUND_1_FINISHED);

                GetBgMap()->UpdateAreaDependentAuras();
                CastSpellOnTeam(SPELL_END_OF_ROUND, ALLIANCE);
                CastSpellOnTeam(SPELL_END_OF_ROUND, HORDE);
            }
            else if (_round == 2)
            {
                _roundScores[1].winner = _attackers;
                _roundScores[1].time = BG_SA_ROUNDLENGTH - EndTimer;
                ToggleTimer();
                //Achievement Storm the Beach (1310)
                    if (Player* player = ObjectAccessor::FindPlayer(itr->first))
                        if (player->GetTeamId() == Attackers && RoundScores[1].winner == Attackers)
                            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, 65246);

                if (_roundScores[0].time == _roundScores[1].time)
                    EndBattleground(WINNER_NONE);
                else if (_roundScores[0].time < _roundScores[1].time)
                    EndBattleground(_roundScores[0].winner == BG_TEAM_ALLIANCE ? WINNER_ALLIANCE : WINNER_HORDE);
                else
                    EndBattleground(_roundScores[1].winner == BG_TEAM_ALLIANCE ? WINNER_ALLIANCE : WINNER_HORDE);
            }
        }
    }
}

void BattlegroundSA::ToggleTimer()
{
    _timerEnabled = !_timerEnabled;
    UpdateWorldState(BG_SA_ENABLE_TIMER, (TimerEnabled) ? 1 : 0);
}

    // complete map_end rewards (even if no team wins)
void BattlegroundSA::UpdateDemolisherSpawns()
{
    for (uint8 i = BG_SA_DEMOLISHER_1; i <= BG_SA_DEMOLISHER_8; i++)
    {
        if (!BgCreatures[i].IsEmpty())
        {
            if (Creature* Demolisher = GetBGCreature(i))
            if (Demolisher->isDead())
            {
                // Demolisher is not in list
                    if (DemoliserRespawnList.find(i) == DemoliserRespawnList.end())
                        DemoliserRespawnList[i] = getMSTime()+30000;
                else if (DemoliserRespawnList[i] < getMSTime())
                {
                            Demolisher->Relocate(BG_SA_NpcSpawnlocs[i]);
                    Demolisher->Respawn();
                    DemoliserRespawnList.erase(i);
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
            go->BuildCreateUpdateBlockForPlayer(&transData, player);

        if (!BgObjects[BG_SA_BOAT_TWO].IsEmpty())

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
            go->BuildOutOfRangeUpdateBlock(&transData);
        if (GameObject* go = GetGameObject(BG_SA_BOAT_TWO))
            go->BuildOutOfRangeUpdateBlock(&transData);
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
        case SPELL_PREPARATION:
            return Status == BG_SA_WARMUP || Status == BG_SA_SECOND_WARMUP;
        default:
           break;
    }

    return true;
}