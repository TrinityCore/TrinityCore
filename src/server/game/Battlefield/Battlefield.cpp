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

#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "Battleground.h"
#include "CellImpl.h"
#include "CreatureTextMgr.h"
#include "DBCStores.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "GroupMgr.h"
#include "Log.h"
#include "Map.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "WorldPacket.h"
#include <G3D/g3dmath.h>

Battlefield::Battlefield()
{
    m_Timer = 0;
    m_IsEnabled = true;
    m_isActive = false;
    m_DefenderTeam = TEAM_NEUTRAL;

    m_TypeId = 0;
    m_BattleId = 0;
    m_ZoneId = 0;
    m_Map = nullptr;
    m_MapId = 0;
    m_MaxPlayer = 0;
    m_MinPlayer = 0;
    m_MinLevel = 0;
    m_BattleTime = 0;
    m_NoWarBattleTime = 0;
    m_RestartAfterCrash = 0;
    m_TimeForAcceptInvite = 20;
    m_uiKickDontAcceptTimer = 1000;

    m_uiKickAfkPlayersTimer = 1000;

    m_LastResurrectTimer = 30 * IN_MILLISECONDS;
    m_StartGroupingTimer = 0;
    m_StartGrouping = false;
}

Battlefield::~Battlefield()
{
    for (BfCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        delete itr->second;

    for (GraveyardVect::const_iterator itr = m_GraveyardList.begin(); itr != m_GraveyardList.end(); ++itr)
        delete *itr;
}

// Called when a player enters the zone
void Battlefield::HandlePlayerEnterZone(Player* player, uint32 /*zone*/)
{
    // If battle is started,
    // If not full of players > invite player to join the war
    // If full of players > announce to player that BF is full and kick him after a few second if he desn't leave
    if (IsWarTime())
    {
        if (m_PlayersInWar[player->GetTeamId()].size() + m_InvitedPlayers[player->GetTeamId()].size() < m_MaxPlayer) // Vacant spaces
            InvitePlayerToWar(player);
        else // No more vacant places
        {
            /// @todo Send a packet to announce it to player
            m_PlayersWillBeKick[player->GetTeamId()][player->GetGUID()] = time(nullptr) + 10;
            InvitePlayerToQueue(player);
        }
    }
    else
    {
        // If time left is < 15 minutes invite player to join queue
        if (m_Timer <= m_StartGroupingTimer)
            InvitePlayerToQueue(player);
    }

    // Add player in the list of player in zone
    m_players[player->GetTeamId()].insert(player->GetGUID());
    OnPlayerEnterZone(player);
}

// Called when a player leave the zone
void Battlefield::HandlePlayerLeaveZone(Player* player, uint32 /*zone*/)
{
    if (IsWarTime())
    {
        // If the player is participating to the battle
        if (m_PlayersInWar[player->GetTeamId()].find(player->GetGUID()) != m_PlayersInWar[player->GetTeamId()].end())
        {
            m_PlayersInWar[player->GetTeamId()].erase(player->GetGUID());
            player->GetSession()->SendBfLeaveMessage(m_BattleId);
            if (Group* group = player->GetGroup()) // Remove the player from the raid group
                group->RemoveMember(player->GetGUID());

            OnPlayerLeaveWar(player);
        }
    }

    for (BfCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        itr->second->HandlePlayerLeave(player);

    m_InvitedPlayers[player->GetTeamId()].erase(player->GetGUID());
    m_PlayersWillBeKick[player->GetTeamId()].erase(player->GetGUID());
    m_players[player->GetTeamId()].erase(player->GetGUID());
    SendRemoveWorldStates(player);
    RemovePlayerFromResurrectQueue(player->GetGUID());
    OnPlayerLeaveZone(player);
}

bool Battlefield::Update(uint32 diff)
{
    if (m_Timer <= diff)
    {
        // Battlefield ends on time
        if (IsWarTime())
            EndBattle(true);
        else // Time to start a new battle!
            StartBattle();
    }
    else
        m_Timer -= diff;

    // Invite players a few minutes before the battle's beginning
    if (!IsWarTime() && !m_StartGrouping && m_Timer <= m_StartGroupingTimer)
    {
        m_StartGrouping = true;
        InvitePlayersInZoneToQueue();
        OnStartGrouping();
    }

    bool objective_changed = false;
    if (IsWarTime())
    {
        if (m_uiKickAfkPlayersTimer <= diff)
        {
            m_uiKickAfkPlayersTimer = 1000;
            KickAfkPlayers();
        }
        else
            m_uiKickAfkPlayersTimer -= diff;

        // Kick players who chose not to accept invitation to the battle
        if (m_uiKickDontAcceptTimer <= diff)
        {
            time_t now = time(nullptr);
            for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
                for (PlayerTimerMap::iterator itr = m_InvitedPlayers[team].begin(); itr != m_InvitedPlayers[team].end(); ++itr)
                    if (itr->second <= now)
                        KickPlayerFromBattlefield(itr->first);

            InvitePlayersInZoneToWar();
            for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
                for (PlayerTimerMap::iterator itr = m_PlayersWillBeKick[team].begin(); itr != m_PlayersWillBeKick[team].end(); ++itr)
                    if (itr->second <= now)
                        KickPlayerFromBattlefield(itr->first);

            m_uiKickDontAcceptTimer = 1000;
        }
        else
            m_uiKickDontAcceptTimer -= diff;

        for (BfCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
            if (itr->second->Update(diff))
                objective_changed = true;
    }


    if (m_LastResurrectTimer <= diff)
    {
        for (uint8 i = 0; i < m_GraveyardList.size(); i++)
            if (GetGraveyardById(i))
                m_GraveyardList[i]->Resurrect();
        m_LastResurrectTimer = RESURRECTION_INTERVAL;
    }
    else
        m_LastResurrectTimer -= diff;

    return objective_changed;
}

void Battlefield::InvitePlayersInZoneToQueue()
{
    for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
        for (auto itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                InvitePlayerToQueue(player);
}

void Battlefield::InvitePlayerToQueue(Player* player)
{
    if (m_PlayersInQueue[player->GetTeamId()].count(player->GetGUID()))
        return;

    if (m_PlayersInQueue[player->GetTeamId()].size() <= m_MinPlayer || m_PlayersInQueue[GetOtherTeam(player->GetTeamId())].size() >= m_MinPlayer)
        player->GetSession()->SendBfInvitePlayerToQueue(m_BattleId);
}

void Battlefield::InvitePlayersInQueueToWar()
{
    for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
    {
        for (auto itr = m_PlayersInQueue[team].begin(); itr != m_PlayersInQueue[team].end(); ++itr)
        {
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
            {
                if (m_PlayersInWar[player->GetTeamId()].size() + m_InvitedPlayers[player->GetTeamId()].size() < m_MaxPlayer)
                    InvitePlayerToWar(player);
                else
                {
                    //Full
                }
            }
        }
        m_PlayersInQueue[team].clear();
    }
}

void Battlefield::InvitePlayersInZoneToWar()
{
    for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
    {
        for (auto itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
        {
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
            {
                if (m_PlayersInWar[player->GetTeamId()].count(player->GetGUID()) || m_InvitedPlayers[player->GetTeamId()].count(player->GetGUID()))
                    continue;
                if (m_PlayersInWar[player->GetTeamId()].size() + m_InvitedPlayers[player->GetTeamId()].size() < m_MaxPlayer)
                    InvitePlayerToWar(player);
                else // Battlefield is full of players
                    m_PlayersWillBeKick[player->GetTeamId()][player->GetGUID()] = time(nullptr) + 10;
            }
        }
    }
}

void Battlefield::InvitePlayerToWar(Player* player)
{
    if (!player)
        return;

    /// @todo needed ?
    if (player->IsInFlight())
        return;

    if (player->InArena() || player->GetBattleground())
    {
        m_PlayersInQueue[player->GetTeamId()].erase(player->GetGUID());
        return;
    }

    // If the player does not match minimal level requirements for the battlefield, kick him
    if (player->getLevel() < m_MinLevel)
    {
        if (m_PlayersWillBeKick[player->GetTeamId()].count(player->GetGUID()) == 0)
            m_PlayersWillBeKick[player->GetTeamId()][player->GetGUID()] = time(nullptr) + 10;
        return;
    }

    // Check if player is not already in war
    if (m_PlayersInWar[player->GetTeamId()].count(player->GetGUID()) || m_InvitedPlayers[player->GetTeamId()].count(player->GetGUID()))
        return;

    m_PlayersWillBeKick[player->GetTeamId()].erase(player->GetGUID());
    m_InvitedPlayers[player->GetTeamId()][player->GetGUID()] = time(nullptr) + m_TimeForAcceptInvite;
    player->GetSession()->SendBfInvitePlayerToWar(m_BattleId, m_ZoneId, m_TimeForAcceptInvite);
}

void Battlefield::InitStalker(uint32 entry, Position const& pos)
{
    if (Creature* creature = SpawnCreature(entry, pos))
        StalkerGuid = creature->GetGUID();
    else
        TC_LOG_ERROR("bg.battlefield", "Battlefield::InitStalker: Could not spawn Stalker (Creature entry %u), zone messages will be unavailable!", entry);
}

void Battlefield::KickAfkPlayers()
{
    for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
        for (auto itr = m_PlayersInWar[team].begin(); itr != m_PlayersInWar[team].end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                if (player->isAFK())
                    KickPlayerFromBattlefield(*itr);
}

void Battlefield::KickPlayerFromBattlefield(ObjectGuid guid)
{
    if (Player* player = ObjectAccessor::FindPlayer(guid))
        if (player->GetZoneId() == GetZoneId())
            player->TeleportTo(KickPosition);
}

void Battlefield::StartBattle()
{
    if (m_isActive)
        return;

    for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
    {
        m_PlayersInWar[team].clear();
        m_Groups[team].clear();
    }

    m_Timer = m_BattleTime;
    m_isActive = true;

    InvitePlayersInZoneToWar();
    InvitePlayersInQueueToWar();

    OnBattleStart();
}

void Battlefield::EndBattle(bool endByTimer)
{
    if (!m_isActive)
        return;

    m_isActive = false;

    m_StartGrouping = false;

    if (!endByTimer)
        SetDefenderTeam(GetAttackerTeam());

    OnBattleEnd(endByTimer);

    // Reset battlefield timer
    m_Timer = m_NoWarBattleTime;
    SendInitWorldStatesToAll();
}

void Battlefield::DoPlaySoundToAll(uint32 SoundID)
{
    WorldPacket data;
    data.Initialize(SMSG_PLAY_SOUND, 4);
    data << uint32(SoundID);

    BroadcastPacketToWar(data);
}

bool Battlefield::HasPlayer(Player* player) const
{
    return m_players[player->GetTeamId()].find(player->GetGUID()) != m_players[player->GetTeamId()].end();
}

// Called in WorldSession::HandleBfQueueInviteResponse
void Battlefield::PlayerAcceptInviteToQueue(Player* player)
{
    // Add player in queue
    m_PlayersInQueue[player->GetTeamId()].insert(player->GetGUID());
    // Send notification
    player->GetSession()->SendBfQueueInviteResponse(m_BattleId, m_ZoneId);
}

// Called in WorldSession::HandleBfExitRequest
void Battlefield::AskToLeaveQueue(Player* player)
{
    // Remove player from queue
    m_PlayersInQueue[player->GetTeamId()].erase(player->GetGUID());
}

// Called in WorldSession::HandleHearthAndResurrect
void Battlefield::PlayerAskToLeave(Player* player)
{
    // Player leaving Wintergrasp, teleport to Dalaran.
    // ToDo: confirm teleport destination.
    player->TeleportTo(571, 5804.1499f, 624.7710f, 647.7670f, 1.6400f);
}

// Called in WorldSession::HandleBfEntryInviteResponse
void Battlefield::PlayerAcceptInviteToWar(Player* player)
{
    if (!IsWarTime())
        return;

    if (AddOrSetPlayerToCorrectBfGroup(player))
    {
        player->GetSession()->SendBfEntered(m_BattleId);
        m_PlayersInWar[player->GetTeamId()].insert(player->GetGUID());
        m_InvitedPlayers[player->GetTeamId()].erase(player->GetGUID());

        if (player->isAFK())
            player->ToggleAFK();

        OnPlayerJoinWar(player);                               //for scripting
    }
}

void Battlefield::TeamCastSpell(TeamId team, int32 spellId)
{
    if (spellId > 0)
    {
        for (auto itr = m_PlayersInWar[team].begin(); itr != m_PlayersInWar[team].end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                player->CastSpell(player, uint32(spellId), true);
    }
    else
    {
        for (auto itr = m_PlayersInWar[team].begin(); itr != m_PlayersInWar[team].end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                player->RemoveAuraFromStack(uint32(-spellId));
    }
}

void Battlefield::BroadcastPacketToZone(WorldPacket& data) const
{
    for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
        for (auto itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                player->SendDirectMessage(&data);
}

void Battlefield::BroadcastPacketToQueue(WorldPacket& data) const
{
    for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
        for (auto itr = m_PlayersInQueue[team].begin(); itr != m_PlayersInQueue[team].end(); ++itr)
            if (Player* player = ObjectAccessor::FindConnectedPlayer(*itr))
                player->SendDirectMessage(&data);
}

void Battlefield::BroadcastPacketToWar(WorldPacket& data) const
{
    for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
        for (auto itr = m_PlayersInWar[team].begin(); itr != m_PlayersInWar[team].end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                player->SendDirectMessage(&data);
}

void Battlefield::SendWarning(uint8 id, WorldObject const* target /*= nullptr*/)
{
    if (Creature* stalker = GetCreature(StalkerGuid))
        sCreatureTextMgr->SendChat(stalker, id, target);
}

void Battlefield::SendUpdateWorldState(uint32 field, uint32 value)
{
    for (uint8 i = 0; i < PVP_TEAMS_COUNT; ++i)
        for (auto itr = m_players[i].begin(); itr != m_players[i].end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                player->SendUpdateWorldState(field, value);
}

void Battlefield::RegisterZone(uint32 zoneId)
{
    sBattlefieldMgr->AddZone(zoneId, this);
}

void Battlefield::HideNpc(Creature* creature)
{
    creature->CombatStop();
    creature->SetReactState(REACT_PASSIVE);
    creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
    creature->SetPhaseMask(2, true);
    creature->DisappearAndDie();
    creature->SetVisible(false);
}

void Battlefield::ShowNpc(Creature* creature, bool aggressive)
{
    creature->SetPhaseMask(1, true);
    creature->SetVisible(true);
    creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
    if (!creature->IsAlive())
        creature->Respawn(true);
    if (aggressive)
        creature->SetReactState(REACT_AGGRESSIVE);
    else
    {
        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        creature->SetReactState(REACT_PASSIVE);
    }
}

// ****************************************************
// ******************* Group System *******************
// ****************************************************
Group* Battlefield::GetFreeBfRaid(TeamId TeamId)
{
    for (auto itr = m_Groups[TeamId].begin(); itr != m_Groups[TeamId].end(); ++itr)
        if (Group* group = sGroupMgr->GetGroupByGUID(itr->GetCounter()))
            if (!group->IsFull())
                return group;

    return nullptr;
}

Group* Battlefield::GetGroupPlayer(ObjectGuid guid, TeamId TeamId)
{
    for (auto itr = m_Groups[TeamId].begin(); itr != m_Groups[TeamId].end(); ++itr)
        if (Group* group = sGroupMgr->GetGroupByGUID(itr->GetCounter()))
            if (group->IsMember(guid))
                return group;

    return nullptr;
}

bool Battlefield::AddOrSetPlayerToCorrectBfGroup(Player* player)
{
    if (!player->IsInWorld())
        return false;

    if (Group* group = player->GetGroup())
        group->RemoveMember(player->GetGUID());

    Group* group = GetFreeBfRaid(player->GetTeamId());
    if (!group)
    {
        group = new Group;
        group->SetBattlefieldGroup(this);
        group->Create(player);
        sGroupMgr->AddGroup(group);
        m_Groups[player->GetTeamId()].insert(group->GetGUID());
    }
    else if (group->IsMember(player->GetGUID()))
    {
        uint8 subgroup = group->GetMemberGroup(player->GetGUID());
        player->SetBattlegroundOrBattlefieldRaid(group, subgroup);
    }
    else
        group->AddMember(player);

    return true;
}

//***************End of Group System*******************

//*****************************************************
//***************Spirit Guide System*******************
//*****************************************************

//--------------------
//-Battlefield Method-
//--------------------
BfGraveyard* Battlefield::GetGraveyardById(uint32 id) const
{
    if (id < m_GraveyardList.size())
    {
        if (BfGraveyard* graveyard = m_GraveyardList.at(id))
            return graveyard;
        else
            TC_LOG_ERROR("bg.battlefield", "Battlefield::GetGraveyardById Id:%u does not exist.", id);
    }
    else
        TC_LOG_ERROR("bg.battlefield", "Battlefield::GetGraveyardById Id:%u could not be found.", id);

    return nullptr;
}

WorldSafeLocsEntry const* Battlefield::GetClosestGraveyard(Player* player)
{
    BfGraveyard* closestGY = nullptr;
    float maxdist = -1;
    for (uint8 i = 0; i < m_GraveyardList.size(); i++)
    {
        if (m_GraveyardList[i])
        {
            if (m_GraveyardList[i]->GetControlTeamId() != player->GetTeamId())
                continue;

            float dist = m_GraveyardList[i]->GetDistance(player);
            if (dist < maxdist || maxdist < 0)
            {
                closestGY = m_GraveyardList[i];
                maxdist = dist;
            }
        }
    }

    if (closestGY)
        return sWorldSafeLocsStore.LookupEntry(closestGY->GetGraveyardId());

    return nullptr;
}

void Battlefield::AddPlayerToResurrectQueue(ObjectGuid npcGuid, ObjectGuid playerGuid)
{
    for (uint8 i = 0; i < m_GraveyardList.size(); i++)
    {
        if (!m_GraveyardList[i])
            continue;

        if (m_GraveyardList[i]->HasNpc(npcGuid))
        {
            m_GraveyardList[i]->AddPlayer(playerGuid);
            break;
        }
    }
}

void Battlefield::RemovePlayerFromResurrectQueue(ObjectGuid playerGuid)
{
    for (uint8 i = 0; i < m_GraveyardList.size(); i++)
    {
        if (!m_GraveyardList[i])
            continue;

        if (m_GraveyardList[i]->HasPlayer(playerGuid))
        {
            m_GraveyardList[i]->RemovePlayer(playerGuid);
            break;
        }
    }
}

void Battlefield::SendAreaSpiritHealerQueryOpcode(Player* player, ObjectGuid guid)
{
    WorldPacket data(SMSG_AREA_SPIRIT_HEALER_TIME, 12);
    uint32 time = m_LastResurrectTimer;  // resurrect every 30 seconds

    data << guid << time;
    player->SendDirectMessage(&data);
}

Creature* Battlefield::SpawnCreature(uint32 entry, Position const& pos)
{
    //Get map object
    Map* map = sMapMgr->CreateBaseMap(m_MapId);
    if (!map)
    {
        TC_LOG_ERROR("bg.battlefield", "Battlefield::SpawnCreature: Can't create creature entry: %u, map not found.", entry);
        return nullptr;
    }

    Creature* creature = new Creature();
    if (!creature->Create(map->GenerateLowGuid<HighGuid::Unit>(), map, PHASEMASK_NORMAL, entry, pos))
    {
        TC_LOG_ERROR("bg.battlefield", "Battlefield::SpawnCreature: Can't create creature entry: %u", entry);
        delete creature;
        return nullptr;
    }

    creature->SetHomePosition(pos);

    // Set creature in world
    map->AddToMap(creature);
    creature->setActive(true);

    return creature;
}

// Method for spawning gameobject on map
GameObject* Battlefield::SpawnGameObject(uint32 entry, Position const& pos, QuaternionData const& rot)
{
    // Get map object
    Map* map = sMapMgr->CreateBaseMap(m_MapId);
    if (!map)
        return nullptr;

    // Create gameobject
    GameObject* go = new GameObject;
    if (!go->Create(map->GenerateLowGuid<HighGuid::GameObject>(), entry, map, PHASEMASK_NORMAL, pos, rot, 255, GO_STATE_READY))
    {
        TC_LOG_ERROR("bg.battlefield", "Battlefield::SpawnGameObject: Gameobject template %u could not be found in the database! Battlefield has not been created!", entry);
        TC_LOG_ERROR("bg.battlefield", "Battlefield::SpawnGameObject: Could not create gameobject template %u! Battlefield has not been created!", entry);
        delete go;
        return nullptr;
    }

    // Add to world
    map->AddToMap(go);
    go->setActive(true);

    return go;
}

Creature* Battlefield::GetCreature(ObjectGuid guid)
{
    if (!_map)
        return nullptr;

    return _map->GetCreature(guid);
}

GameObject* Battlefield::GetGameObject(ObjectGuid guid)
{
    if (!_map)
        return nullptr;

    return _map->GetGameObject(guid);
}

//*******************************************************
//******************* CapturePoint **********************
//*******************************************************

BattlefieldCapturePoint::BattlefieldCapturePoint(Battlefield* battlefield) : _battlefield(battlefield)
{
    _team = TEAM_NEUTRAL;
    _value = 0;
    _minValue = 0.0f;
    _maxValue = 0.0f;
    _state = BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL;
    _oldState = BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL;
    _capturePointEntry = 0;
    _neutralValuePct = 0;
    _maxSpeed = 0;
}

void BattlefieldCapturePoint::Update(uint32 diff)
{
    if (!_capturePointGUID)
        return;

    if (GameObject* capturePoint = _battlefield->GetGameObject(_capturePointGUID))
    {
        float radius = capturePoint->GetGOInfo()->capturePoint.radius;

        for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
        {
            for (auto itr = _activePlayers[team].begin(); itr != _activePlayers[team].end();)
            {
                if (Player* player = ObjectAccessor::FindPlayer(*itr))
                {
                    if (!capturePoint->IsWithinDistInMap(player, radius))
                        itr = HandlePlayerLeave(player);
                    else
                        ++itr;
                }
                else
                    ++itr;
            }
        }

        std::list<Player*> players;
        Trinity::AnyPlayerInObjectRangeCheck checker(capturePoint, radius);
        Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(capturePoint, players, checker);
        Cell::VisitWorldObjects(capturePoint, searcher, radius);

        for (Player* player : players)
            if (_activePlayers[player->GetTeamId()].insert(player->GetGUID()).second)
                HandlePlayerEnter(player);
    }

    // get the difference of numbers
    float fact_diff = (float(_activePlayers[TEAM_ALLIANCE].size()) - float(_activePlayers[TEAM_HORDE].size())) * float(diff) / float(BATTLEFIELD_OBJECTIVE_UPDATE_INTERVAL);
    if (G3D::fuzzyEq(fact_diff, 0.0f))
        return;

    uint32 challenger = 0;
    float maxDiff = _maxSpeed * diff;

    if (fact_diff < 0)
    {
        // horde is in majority, but it's already horde-controlled -> no change
        if (_state == BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_HORDE && _value <= -_maxValue)
            return;

        if (fact_diff < -maxDiff)
            fact_diff = -maxDiff;

        challenger = HORDE;
    }
    else
    {
        // ally is in majority, but it's already ally-controlled -> no change
        if (_state == BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE && _value >= _maxValue)
            return;

        if (fact_diff > maxDiff)
            fact_diff = maxDiff;

        challenger = ALLIANCE;
    }

    float oldValue = _value;
    TeamId oldTeam = _team;

    _oldState = _state;
    _value += fact_diff;

    if (_value < -_minValue) // red
    {
        if (_value < -_maxValue)
            _value = -_maxValue;
        _state = BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_HORDE;
        _team = TEAM_HORDE;
    }
    else if (_value > _minValue) // blue
    {
        if (_value > _maxValue)
            _value = _maxValue;
        _state = BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE;
        _team = TEAM_ALLIANCE;
    }
    else if (oldValue * _value <= 0) // grey, go through mid point
    {
        // if challenger is ally, then n->a challenge
        if (challenger == ALLIANCE)
            _state = BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE;
        // if challenger is horde, then n->h challenge
        else if (challenger == HORDE)
            _state = BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE;
        _team = TEAM_NEUTRAL;
    }
    else  // grey, did not go through mid point
    {
        // old phase and current are on the same side, so one team challenges the other
        if (challenger == ALLIANCE && (_oldState == BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_HORDE || _oldState == BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE))
            _state = BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE;
        else if (challenger == HORDE && (_oldState == BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE || _oldState == BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE))
            _state = BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE;
        _team = TEAM_NEUTRAL;
    }

    if (G3D::fuzzyNe(_value, oldValue))
        SendChangePhase();

    // inform if necessary
    if (_oldState != _state)
    {
        if (oldTeam != _team)
            ChangeTeam(oldTeam);
    }
}

void BattlefieldCapturePoint::SendChangePhase()
{
    if (!_capturePointGUID)
        return;

    if (GameObject* capturePoint = _battlefield->GetGameObject(_capturePointGUID))
    {
        SendUpdateWorldState(capturePoint->GetGOInfo()->capturePoint.worldState1, 1);
        SendUpdateWorldState(capturePoint->GetGOInfo()->capturePoint.worldstate2, (uint32)std::ceil((_value + _maxValue) / (2.f * _maxValue) * 100.0f));
        SendUpdateWorldState(capturePoint->GetGOInfo()->capturePoint.worldstate3, _neutralValuePct);
    }
}

bool BattlefieldCapturePoint::HandlePlayerEnter(Player* player)
{
    if (_capturePointGUID)
    {
        if (GameObject* capturePoint = _battlefield->GetGameObject(_capturePointGUID))
        {
            player->SendUpdateWorldState(capturePoint->GetGOInfo()->capturePoint.worldState1, 1);
            player->SendUpdateWorldState(capturePoint->GetGOInfo()->capturePoint.worldstate2, uint32(ceil((_value + _maxValue) / (2.f * _maxValue) * 100.0f)));
            player->SendUpdateWorldState(capturePoint->GetGOInfo()->capturePoint.worldstate3, _neutralValuePct);
        }
    }

    return _activePlayers[player->GetTeamId()].insert(player->GetGUID()).second;
}

GuidUnorderedSet::iterator BattlefieldCapturePoint::HandlePlayerLeave(Player* player)
{
    if (_capturePointGUID)
        if (GameObject* capturePoint = _battlefield->GetGameObject(_capturePointGUID))
            player->SendUpdateWorldState(capturePoint->GetGOInfo()->capturePoint.worldState1, 0);

    GuidUnorderedSet::iterator current = _activePlayers[player->GetTeamId()].find(player->GetGUID());

    if (current == _activePlayers[player->GetTeamId()].end())
        return current; // return end()

    _activePlayers[player->GetTeamId()].erase(current++);
    return current;
}

void BattlefieldCapturePoint::SendUpdateWorldState(uint32 field, uint32 value)
{
    for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
    {
        for (auto itr = _activePlayers[team].begin(); itr != _activePlayers[team].end(); ++itr) // send to all players present in the area
            if (Player* player = ObjectAccessor::FindConnectedPlayer(*itr))
                player->SendUpdateWorldState(field, value);
    }
}

void BattlefieldCapturePoint::SendObjectiveComplete(uint32 id, ObjectGuid guid)
{
    uint8 team;
    switch (_state)
    {
        case BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE:
            team = TEAM_ALLIANCE;
            break;
        case BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_HORDE:
            team = TEAM_HORDE;
            break;
        default:
            return;
    }

    // send to all players present in the area
    for (auto itr = _activePlayers[team].begin(); itr != _activePlayers[team].end(); ++itr)
        if (Player* player = ObjectAccessor::FindConnectedPlayer(*itr))
            player->KilledMonsterCredit(id, guid);
}

void BattlefieldCapturePoint::SetCapturePointData(GameObject* capturePoint)
{
    ASSERT(capturePoint);

    _capturePointGUID = capturePoint->GetGUID();

    // check info existence
    GameObjectTemplate const* goinfo = capturePoint->GetGOInfo();
    if (goinfo->type != GAMEOBJECT_TYPE_CAPTURE_POINT)
        return;

    // get the needed values from goinfo
    _maxValue = float(goinfo->capturePoint.maxTime);
    _maxSpeed = _maxValue / (goinfo->capturePoint.minTime ? float(goinfo->capturePoint.minTime) : 60.f);
    _neutralValuePct = float(goinfo->capturePoint.neutralPercent);
    _minValue = _maxValue * float(goinfo->capturePoint.neutralPercent) / 100.f;
    _capturePointEntry = capturePoint->GetEntry();
    if (_team == TEAM_ALLIANCE)
    {
        _value = _maxValue;
        _state = BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE;
    }
    else
    {
        _value = -_maxValue;
        _state = BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_HORDE;
    }

    return;
}

void BattlefieldCapturePoint::SetTeam(TeamId newTeam)
{
    if (newTeam == TEAM_ALLIANCE)
    {
        _team = newTeam;
        _value = _maxValue;
        _state = BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE;
        SendChangePhase();
    }
    else if (newTeam == TEAM_HORDE)
    {
        _team = newTeam;
        _value = -_maxValue;
        _state = BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_HORDE;
        SendChangePhase();
    }
}

bool BattlefieldCapturePoint::IsInsideObjective(Player* player) const
{
    return _activePlayers[player->GetTeamId()].find(player->GetGUID()) != _activePlayers[player->GetTeamId()].end();
}

GameObject* BattlefieldCapturePoint::GetCapturePointGameObject()
{
    return _battlefield->GetGameObject(_capturePointGUID);
}

//*******************************************************
//******************* Graveyard *************************
//*******************************************************

BattlefieldGraveyard::BattlefieldGraveyard(Battlefield* battlefield)
{
    _battlefield = battlefield;
    _id = 0;
    _controlTeam = TEAM_NEUTRAL;
}

void BattlefieldGraveyard::Initialize(TeamId initialTeam, uint32 id)
{
    _controlTeam = initialTeam;
    _id = id;
}

void BattlefieldGraveyard::SetSpirit(Creature* creature, TeamId team)
{
    if (!creature)
    {
        TC_LOG_ERROR("battlefield", "BattlefieldGraveyard::SetSpirit: battle %u tried to set a spirit with an invalid pointer to creature", _battlefield->GetBattleId());
        return;
    }

    _spiritGuides[team] = creature->GetGUID();
    creature->SetReactState(REACT_PASSIVE);
}

void BattlefieldGraveyard::AddPlayer(ObjectGuid playerGUID)
{
    if (!_resurrectQueue.count(playerGUID))
    {
        _resurrectQueue.insert(playerGUID);
        if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
            player->CastSpell(player, SPELL_WAITING_FOR_RESURRECT, true);
    }
}

void BattlefieldGraveyard::RemovePlayer(ObjectGuid playerGUID)
{
    _resurrectQueue.erase(_resurrectQueue.find(playerGUID));
    if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
        player->RemoveAurasDueToSpell(SPELL_WAITING_FOR_RESURRECT);
}

void BattlefieldGraveyard::Resurrect()
{
    if (_resurrectQueue.empty())
        return;

    for (auto itr = _resurrectQueue.begin(); itr != _resurrectQueue.end(); ++itr)
    {
        // Get player object from his guid
        Player* player = ObjectAccessor::FindPlayer(*itr);
        if (!player)
            continue;

        // Check  if the player is in world and on the good graveyard
        if (player->IsInWorld())
        {
            if (Creature* spirit = _battlefield->GetCreature(_spiritGuides[_controlTeam]))
                spirit->CastSpell(spirit, SPELL_SPIRIT_HEAL, true);
        }

        // Resurrect player
        player->CastSpell(player, SPELL_RESURRECTION_VISUAL, true);
        player->ResurrectPlayer(1.0f);
        player->CastSpell(player, 6962, true);
        player->CastSpell(player, SPELL_SPIRIT_HEAL_MANA, true);
        player->SpawnCorpseBones(false);
    }

    _resurrectQueue.clear();
}

// For changing graveyard control
void BattlefieldGraveyard::GiveControlTo(TeamId team)
{
    _controlTeam = team;
    // Teleport to other graveyard, player witch were on this graveyard
    RelocateDeadPlayers();
}

void BattlefieldGraveyard::RelocateDeadPlayers()
{
    WorldSafeLocsEntry const* closestGrave = nullptr;
    for (auto itr = _resurrectQueue.begin(); itr != _resurrectQueue.end(); ++itr)
    {
        Player* player = ObjectAccessor::FindPlayer(*itr);
        if (!player)
            continue;

        if (closestGrave)
            player->TeleportTo(player->GetMapId(), closestGrave->x, closestGrave->y, closestGrave->z, player->GetOrientation());
        else
        {
            closestGrave = _battlefield->GetClosestGraveYard(player);
            if (closestGrave)
                player->TeleportTo(player->GetMapId(), closestGrave->x, closestGrave->y, closestGrave->z, player->GetOrientation());
        }
    }
}

float BattlefieldGraveyard::GetDistance(Player* player) const
{
    WorldSafeLocsEntry const* safeLoc = sWorldSafeLocsStore.LookupEntry(_id);
    return player->GetDistance2d(safeLoc->x, safeLoc->y);
}

bool BattlefieldGraveyard::HasCreature(ObjectGuid guid)
{
    if (_spiritGuides[TEAM_ALLIANCE] == guid)
        if (_battlefield->GetCreature(_spiritGuides[TEAM_ALLIANCE]))
            return true;

    if (_spiritGuides[TEAM_HORDE] == guid)
        if (_battlefield->GetCreature(_spiritGuides[TEAM_HORDE]))
            return true;

    return false;
}

TeamId BattlefieldGraveyard::GetSpiritTeamId(ObjectGuid guid)
{
    if (_spiritGuides[TEAM_ALLIANCE] == guid)
        if (_battlefield->GetCreature(_spiritGuides[TEAM_ALLIANCE]))
            return TEAM_ALLIANCE;

    if (_spiritGuides[TEAM_HORDE] == guid)
        if (_battlefield->GetCreature(_spiritGuides[TEAM_HORDE]))
            return TEAM_HORDE;

    return TEAM_NEUTRAL;
}
