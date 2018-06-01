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
#include "CellImpl.h"
#include "Creature.h"
#include "DBCStores.h"
#include "GameObjectData.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "GroupMgr.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "WorldPacket.h"
#include <G3D/g3dmath.h>

Battlefield::Battlefield() : _timer(0), _defenderTeam(TEAM_NEUTRAL), _kickCheckTimer(0), _lastResurrectTimer(0), _active(false), _enabled(false), _startGrouping(false), _map(nullptr),
    _battleId(0), _zoneId(0), _mapId(0), _maxPlayerCount(0), _minPlayerLevel(0), _battleTime(0), _noWarBattleTime(0), _restartAfterCrash(0), _acceptInviteTime(0), _startGroupingTime(0)
{
}

Battlefield::~Battlefield()
{
    for (BattlefieldCapturePoint* capturePoint : _capturePoints)
        delete capturePoint;

    for (BattlefieldGraveyard* graveyard : _graveyardList)
        delete graveyard;
}

void Battlefield::Update(uint32 diff)
{
    _timer.Update(diff);
    if (_timer.Passed())
    {
        // battlefield ends on time
        if (IsWarTime())
            EndBattle(true);
        else // time to start a new battle
            StartBattle();
    }

    // invite players a few minutes before the battle's beginning
    if (!IsWarTime() && !_startGrouping && GetTimer() <= _startGroupingTime)
    {
        _startGrouping = true;
        InvitePlayersInZoneToQueue();
        OnStartGrouping();
    }

    if (IsWarTime())
    {
        _kickCheckTimer.Update(diff);
        if (_kickCheckTimer.Passed())
        {
            time_t now = time(nullptr);

            // accept invite timer
            for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
            {
                for (auto itr = _invitedPlayers[team].begin(); itr != _invitedPlayers[team].end();)
                {
                    if (itr->second <= now)
                    {
                        _playersToKick[team].erase(itr->first);
                        RemovePlayer(itr->first);
                        itr = _invitedPlayers[team].erase(itr);
                    }
                    else
                        ++itr;
                }
            }

            InvitePlayersInZoneToWar();
            InvitePlayersInQueueToWar();

            // kick timer
            for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
            {
                for (auto itr = _playersToKick[team].begin(); itr != _playersToKick[team].end();)
                {
                    if (itr->second <= now)
                    {
                        _invitedPlayers[team].erase(itr->first);
                        RemovePlayer(itr->first);
                        itr = _playersToKick[team].erase(itr);
                    }
                    else
                        ++itr;
                }
            }

            _kickCheckTimer.Reset(1000);
        }

        for (BattlefieldCapturePoint* capturePoint : _capturePoints)
            capturePoint->Update(diff);
    }

    _lastResurrectTimer.Update(diff);
    if (_lastResurrectTimer.Passed())
    {
        for (uint8 itr = 0; itr < _graveyardList.size(); ++itr)
        {
            if (BattlefieldGraveyard* graveyard = GetGraveyard(itr))
                graveyard->Resurrect();
        }

        _lastResurrectTimer.Reset(BATTLEFIELD_RESURRECT_ITERVAL);
    }
}

void Battlefield::AddPlayerToResurrectQueue(ObjectGuid creatureGUID, ObjectGuid playerGUID)
{
    for (uint8 itr = 0; itr < _graveyardList.size(); ++itr)
    {
        if (!_graveyardList[itr])
            continue;

        if (_graveyardList[itr]->HasCreature(creatureGUID))
        {
            _graveyardList[itr]->AddPlayer(playerGUID);
            break;
        }
    }
}

void Battlefield::ToggleBattlefield(bool enable)
{
    if (_active && !enable)
        EndBattle(true);

    _enabled = enable;
}

void Battlefield::StartBattle()
{
    if (_active)
        return;

    for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
    {
        _playersInWar[team].clear();
        _groups[team].clear();
    }

    _timer.Reset(_battleTime);
    _active = true;

    InvitePlayersInZoneToWar();
    InvitePlayersInQueueToWar();

    DoPlaySoundToAll(BATTLEFIELD_SOUND_START);
    OnBattleStart();
}

void Battlefield::EndBattle(bool endByTimer)
{
    if (!_active)
        return;

    _active = false;

    _startGrouping = false;

    if (!endByTimer)
        SetDefenderTeam(GetAttackerTeam());

    DoPlaySoundToAll(GetDefenderTeam() == TEAM_ALLIANCE ? BATTLEFIELD_SOUND_ALLIANCE_WINS : BATTLEFIELD_SOUND_HORDE_WINS);
    OnBattleEnd(endByTimer);

    // Reset battlefield timer
    _timer.Reset(_noWarBattleTime);
    SendInitWorldStatesToAll();
}

void Battlefield::SendUpdateWorldState(uint32 field, uint32 value)
{
    for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
    {
        for (auto itr = _players[team].begin(); itr != _players[team].end(); ++itr)
            if (Player* player = ObjectAccessor::FindConnectedPlayer(*itr))
                player->SendUpdateWorldState(field, value);
    }
}

void Battlefield::InvitePlayersInZoneToWar()
{
    for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
    {
        for (ObjectGuid guid : _players[team])
        {
            if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
            {
                // dead or in flight
                if (!player->IsAlive() || player->IsInFlight())
                    continue;

                // level requirement
                if (player->getLevel() < _minPlayerLevel && _playersToKick[player->GetTeamId()].find(guid) == _playersToKick[player->GetTeamId()].end())
                {
                    _playersToKick[player->GetTeamId()][guid] = time(nullptr) + 1;
                    continue;
                }

                // already invited
                if (_invitedPlayers[player->GetTeamId()].find(guid) != _invitedPlayers[player->GetTeamId()].end())
                    continue;

                // afk
                if (_playersInWar[player->GetTeamId()].find(guid) != _playersInWar[player->GetTeamId()].end() && player->isAFK() &&
                    _playersToKick[player->GetTeamId()].find(guid) == _playersToKick[player->GetTeamId()].end())
                {
                    _playersToKick[player->GetTeamId()][guid] = time(nullptr) + 1;
                    continue;
                }

                // not in war and not being kicked
                if (_playersInWar[player->GetTeamId()].find(guid) == _playersInWar[player->GetTeamId()].end() &&
                    _playersToKick[player->GetTeamId()].find(guid) == _playersToKick[player->GetTeamId()].end())
                {
                    // if there is vacant space, invite
                    if (_playersInWar[player->GetTeamId()].size() + _invitedPlayers[player->GetTeamId()].size() < _maxPlayerCount)
                        InvitePlayerToWar(player);
                    else // if not, kick and invite to queue
                    {
                        _playersToKick[player->GetTeamId()][guid] = time(nullptr) + 10;
                        player->GetSession()->SendBattlefieldEjectPending(_battleId, true);
                        InvitePlayerToQueue(player);
                    }
                }
            }
        }
    }
}

void Battlefield::InvitePlayersInZoneToQueue()
{
    for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
    {
        for (ObjectGuid value : _players[team])
            if (Player* player = ObjectAccessor::FindConnectedPlayer(value))
                InvitePlayerToQueue(player);
    }
}

void Battlefield::InvitePlayersInQueueToWar()
{
    for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
    {
        while (!_playerQueue[team].empty())
        {
            ObjectGuid playerGuid = _playerQueue[team].front();
            if (Player* player = ObjectAccessor::FindConnectedPlayer(playerGuid))
            {
                if (!player || player->InArena() || player->GetBattleground() || player->getLevel() < _minPlayerLevel ||
                    _playersInWar[player->GetTeamId()].find(player->GetGUID()) != _playersInWar[player->GetTeamId()].end() || // already in war
                    _invitedPlayers[player->GetTeamId()].find(player->GetGUID()) != _invitedPlayers[player->GetTeamId()].end()) // already invited
                {
                    _playerQueue[team].pop_front();
                    continue;
                }

                // vacant space
                if (_playersInWar[player->GetTeamId()].size() + _invitedPlayers[player->GetTeamId()].size() >= _maxPlayerCount)
                    break;

                _playersToKick[player->GetTeamId()].erase(player->GetGUID());
                _invitedPlayers[player->GetTeamId()][player->GetGUID()] = time(nullptr) + _acceptInviteTime;
                player->GetSession()->SendBattlefieldInvitePlayerToWar(_battleId, _zoneId, _acceptInviteTime);
            }
            _playerQueue[team].pop_front();
        }
    }
}

bool Battlefield::InvitePlayerToWar(Player* player)
{
    if (!player || player->InArena() || player->GetBattleground() || player->getLevel() < _minPlayerLevel)
        return false;

    // check if player is not already in war
    if (_playersInWar[player->GetTeamId()].find(player->GetGUID()) != _playersInWar[player->GetTeamId()].end())
        return true;

    // check if already invited
    if (_invitedPlayers[player->GetTeamId()].find(player->GetGUID()) != _invitedPlayers[player->GetTeamId()].end())
        return true;

    // vacant space
    if (_playersInWar[player->GetTeamId()].size() + _invitedPlayers[player->GetTeamId()].size() >= _maxPlayerCount)
        return false;

    _playersToKick[player->GetTeamId()].erase(player->GetGUID());
    _invitedPlayers[player->GetTeamId()][player->GetGUID()] = time(nullptr) + _acceptInviteTime;
    player->GetSession()->SendBattlefieldInvitePlayerToWar(_battleId, _zoneId, _acceptInviteTime);
    return true;
}

void Battlefield::InvitePlayerToQueue(Player* player)
{
    // dont invite while in taxi flight
    if (player->IsInFlight())
        return;

    // minimum player level
    if (player->getLevel() < _minPlayerLevel)
        return;

    // check if already in queue
    auto itr = std::find(_playerQueue[player->GetTeamId()].begin(), _playerQueue[player->GetTeamId()].end(), player->GetGUID());
    if (itr != _playerQueue[player->GetTeamId()].end())
        return;

    // send invite
    player->GetSession()->SendBattlefieldInvitePlayerToQueue(_battleId);
}

void Battlefield::HandlePlayerEnterZone(Player* player, uint32 /*zone*/)
{
    if (player->IsGameMaster())
        return;

    if (IsEnabled())
    {
        if (IsWarTime() && !player->IsInFlight())
        {
            if (!InvitePlayerToWar(player))
            {
                if (_playersToKick[player->GetTeamId()].find(player->GetGUID()) == _playersToKick[player->GetTeamId()].end())
                {
                    _playersToKick[player->GetTeamId()][player->GetGUID()] = time(nullptr) + 10;
                    player->GetSession()->SendBattlefieldEjectPending(_battleId, true);
                    InvitePlayerToQueue(player);
                }
            }
        }
        else
        {
            // If time left is < 15 minutes invite player to join queue
            if (GetTimer() <= _startGroupingTime)
                InvitePlayerToQueue(player);
        }

        // Add player in the list of player in zone
        _players[player->GetTeamId()].insert(player->GetGUID());
    }

    OnPlayerEnterZone(player);
}

void Battlefield::HandlePlayerLeaveZone(Player* player, uint32 /*zone*/)
{
    if (IsEnabled())
    {
        for (BattlefieldCapturePoint* capturePoint : _capturePoints)
            capturePoint->HandlePlayerLeave(player);

        if (IsWarTime())
        {
            // if the player is participating
            if (_playersInWar[player->GetTeamId()].find(player->GetGUID()) != _playersInWar[player->GetTeamId()].end())
            {
                _playersInWar[player->GetTeamId()].erase(player->GetGUID());
                player->GetSession()->SendBattlefieldLeaveMessage(_battleId);
                if (Group* group = player->GetGroup()) // Remove the player from the raid group
                    group->RemoveMember(player->GetGUID());

                OnPlayerLeaveWar(player);
            }
        }

        _invitedPlayers[player->GetTeamId()].erase(player->GetGUID());
        _playersToKick[player->GetTeamId()].erase(player->GetGUID());
        _players[player->GetTeamId()].erase(player->GetGUID());
    }

    RemovePlayerFromResurrectQueue(player->GetGUID());
    OnPlayerLeaveZone(player);
}

void Battlefield::KickPlayer(Player* player)
{
    if (!player)
        return;

    BFLeaveReason reason = BF_LEAVE_REASON_EXITED;
    if (player->getLevel() < _minPlayerLevel)
        reason = BF_LEAVE_REASON_LOW_LEVEL;
    player->GetSession()->SendBattlefieldLeaveMessage(_battleId, reason);

    _invitedPlayers[player->GetTeamId()].erase(player->GetGUID());
    _playersToKick[player->GetTeamId()].erase(player->GetGUID());

    if (player->GetMapId() == _mapId && player->GetZoneId() == _zoneId)
    {
        for (BattlefieldCapturePoint* capturePoint : _capturePoints)
            capturePoint->HandlePlayerLeave(player);

        if (_playersInWar[player->GetTeamId()].find(player->GetGUID()) != _playersInWar[player->GetTeamId()].end())
        {
            _playersInWar[player->GetTeamId()].erase(player->GetGUID());
            if (Group* group = player->GetGroup())
                group->RemoveMember(player->GetGUID());

            OnPlayerLeaveWar(player);
        }

        _players[player->GetTeamId()].erase(player->GetGUID());

        RemovePlayerFromResurrectQueue(player->GetGUID());
        OnPlayerLeaveZone(player);

        player->TeleportTo(player->m_homebindMapId, player->m_homebindX, player->m_homebindY, player->m_homebindZ, player->GetOrientation());
    }
}

void Battlefield::PlayerAcceptsInviteToQueue(Player* player)
{
    // add player to queue
    _playerQueue[player->GetTeamId()].push_back(player->GetGUID());

    // notify
    player->GetSession()->SendBattlefieldQueueInviteResponse(_battleId, _zoneId);
}

void Battlefield::PlayerAcceptsInviteToWar(Player* player)
{
    if (!IsWarTime())
        return;

    if (AddOrSetPlayerToCorrectBfGroup(player))
    {
        player->GetSession()->SendBattlefieldEntered(_battleId);
        _playersInWar[player->GetTeamId()].insert(player->GetGUID());
        _invitedPlayers[player->GetTeamId()].erase(player->GetGUID());

        if (player->isAFK())
            player->ToggleAFK();

        OnPlayerJoinWar(player);
    }
}

void Battlefield::PlayerLeavesQueue(Player* player, bool kick /*= false*/)
{
    // remove player from queue
    auto itr = std::find(_playerQueue[player->GetTeamId()].begin(), _playerQueue[player->GetTeamId()].end(), player->GetGUID());
    if (itr != _playerQueue[player->GetTeamId()].end())
        _playerQueue[player->GetTeamId()].erase(itr);

    // kick or notify
    if (kick)
        KickPlayer(player);
    else
        player->GetSession()->SendBattlefieldLeaveMessage(_battleId);
}

bool Battlefield::AddOrSetPlayerToCorrectBfGroup(Player* player)
{
    if (!player->IsInWorld())
        return false;

    if (Group* group = player->GetGroup())
        group->RemoveMember(player->GetGUID());

    Group* group = GetFreeGroup(player->GetTeamId());
    if (!group)
    {
        group = new Group;
        group->SetBattlefieldGroup(this);
        group->Create(player);
        sGroupMgr->AddGroup(group);
        _groups[player->GetTeamId()].insert(group->GetGUID());
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

void Battlefield::RemovePlayerFromResurrectQueue(ObjectGuid playerGuid)
{
    for (uint8 itr = 0; itr < _graveyardList.size(); ++itr)
    {
        if (!_graveyardList[itr])
            continue;

        if (_graveyardList[itr]->HasPlayer(playerGuid))
        {
            _graveyardList[itr]->RemovePlayer(playerGuid);
            break;
        }
    }
}

void Battlefield::SendAreaSpiritHealerQueryOpcode(Player* player, ObjectGuid guid)
{
    WorldPacket data(SMSG_AREA_SPIRIT_HEALER_TIME, 12);
    uint32 time = _lastResurrectTimer.GetExpiry(); // resurrect every 30 seconds

    data << guid << time;
    player->SendDirectMessage(&data);
}

Creature* Battlefield::SpawnCreature(uint32 entry, Position const& pos)
{
    if (!_map)
        return nullptr;

    Creature* creature = new Creature();
    if (!creature->Create(_map->GenerateLowGuid<HighGuid::Unit>(), _map, PHASEMASK_NORMAL, entry, pos))
    {
        TC_LOG_ERROR("battlefield", "Battlefield::SpawnCreature: can't create creature entry %u", entry);
        delete creature;
        return nullptr;
    }

    creature->SetHomePosition(pos);

    // Add to world
    _map->LoadGrid(pos.GetPositionX(), pos.GetPositionY());
    _map->AddToMap(creature);

    return creature;
}

GameObject* Battlefield::SpawnGameObject(uint32 entry, Position const& pos, QuaternionData const& rot)
{
    if (!_map)
        return nullptr;

    GameObject* go = new GameObject();
    if (!go->Create(_map->GenerateLowGuid<HighGuid::GameObject>(), entry, _map, PHASEMASK_NORMAL, pos, rot, 255, GO_STATE_READY))
    {
        TC_LOG_ERROR("battlefield", "Battlefield::SpawnGameObject: can't create gameobject entry %u", entry);
        delete go;
        return nullptr;
    }

    // Add to world
    _map->LoadGrid(pos.GetPositionX(), pos.GetPositionY());
    _map->AddToMap(go);

    return go;
}

void Battlefield::HideCreature(Creature* creature)
{
    creature->Respawn(true);
    creature->SetReactState(REACT_PASSIVE);
    creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
    creature->SetVisible(false);
}

void Battlefield::ShowCreature(Creature* creature, bool aggressive)
{
    creature->SetVisible(true);
    creature->Respawn(true);
    creature->SetReactState(aggressive ? REACT_AGGRESSIVE : REACT_PASSIVE);
    creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
}

void Battlefield::DoPlaySoundToAll(uint32 soundId)
{
    WorldPacket data;
    data.Initialize(SMSG_PLAY_SOUND, 4);
    data << uint32(soundId);

    BroadcastPacketToWar(data);
}

void Battlefield::BroadcastPacketToZone(WorldPacket& data) const
{
    for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
    {
        for (auto itr = _players[team].begin(); itr != _players[team].end(); ++itr)
            if (Player* player = ObjectAccessor::FindConnectedPlayer(*itr))
                player->SendDirectMessage(&data);
    }
}

void Battlefield::BroadcastPacketToQueue(WorldPacket& data) const
{
    for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
    {
        for (auto itr = _playerQueue[team].begin(); itr != _playerQueue[team].end(); ++itr)
            if (Player* player = ObjectAccessor::FindConnectedPlayer(*itr))
                player->SendDirectMessage(&data);
    }
}

void Battlefield::BroadcastPacketToWar(WorldPacket& data) const
{
    for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
    {
        for (auto itr = _playersInWar[team].begin(); itr != _playersInWar[team].end(); ++itr)
            if (Player* player = ObjectAccessor::FindConnectedPlayer(*itr))
                player->SendDirectMessage(&data);
    }
}

void Battlefield::TeamCastSpell(TeamId team, int32 spellId)
{
    if (spellId > 0)
    {
        for (auto itr = _playersInWar[team].begin(); itr != _playersInWar[team].end(); ++itr)
        {
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                player->CastSpell(player, uint32(spellId), true);
        }
    }
    else
    {
        for (auto itr = _playersInWar[team].begin(); itr != _playersInWar[team].end(); ++itr)
        {
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                player->RemoveAuraFromStack(uint32(-spellId));
        }
    }
}

bool Battlefield::HasPlayer(Player* player) const
{
    return _players[player->GetTeamId()].find(player->GetGUID()) != _players[player->GetTeamId()].end();
}

std::list<Player*> Battlefield::GetPlayerListInSourceRange(WorldObject* source, float range, TeamId teamId) const
{
    std::list<Player*> playerList;
    for (ObjectGuid guid : _players[teamId])
    {
        if (Player* player = ObjectAccessor::FindPlayer(guid))
            if (player->IsWithinDist(source, range))
                playerList.push_back(player);
    }

    return playerList;
}

BattlefieldGraveyard* Battlefield::GetGraveyard(uint32 id) const
{
    if (id < _graveyardList.size())
    {
        if (BattlefieldGraveyard* graveyard = _graveyardList.at(id))
            return graveyard;
        else
            TC_LOG_ERROR("battlefield", "Battlefield::GetGraveyard: id %u could not be found", id);
    }
    else
        TC_LOG_ERROR("battlefield", "Battlefield::GetGraveyard: id %u could not be found", id);

    return nullptr;
}

WorldSafeLocsEntry const* Battlefield::GetClosestGraveyard(Player* player) const
{
    BattlefieldGraveyard* closestGY = nullptr;
    float maxdist = -1;
    for (uint8 itr = 0; itr < _graveyardList.size(); ++itr)
    {
        if (_graveyardList[itr])
        {
            if (_graveyardList[itr]->GetControlTeamId() != player->GetTeamId())
                continue;

            float dist = _graveyardList[itr]->GetDistance(player);
            if (dist < maxdist || maxdist < 0)
            {
                closestGY = _graveyardList[itr];
                maxdist = dist;
            }
        }
    }

    if (closestGY)
        return sWorldSafeLocsStore.LookupEntry(closestGY->GetId());

    return nullptr;
}

Group* Battlefield::GetFreeGroup(TeamId TeamId) const
{
    for (auto itr = _groups[TeamId].begin(); itr != _groups[TeamId].end(); ++itr)
    {
        if (Group* group = sGroupMgr->GetGroupByGUID(itr->GetCounter()))
            if (!group->IsFull())
                return group;
    }

    return nullptr;
}

Group* Battlefield::GetGroup(ObjectGuid guid, TeamId TeamId) const
{
    for (auto itr = _groups[TeamId].begin(); itr != _groups[TeamId].end(); ++itr)
    {
        if (Group* group = sGroupMgr->GetGroupByGUID(itr->GetCounter()))
            if (group->IsMember(guid))
                return group;
    }

    return nullptr;
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

void Battlefield::RemovePlayer(ObjectGuid playerGUID)
{
    Player* source = ObjectAccessor::FindPlayer(playerGUID);
    if (source)
    {
        BFLeaveReason reason = BF_LEAVE_REASON_EXITED;
        if (source->getLevel() < _minPlayerLevel)
            reason = BF_LEAVE_REASON_LOW_LEVEL;
        source->GetSession()->SendBattlefieldLeaveMessage(_battleId, reason);

        if (source->GetMapId() == _mapId && source->GetZoneId() == _zoneId)
        {
            for (BattlefieldCapturePoint* capturePoint : _capturePoints)
                capturePoint->HandlePlayerLeave(source);

            if (_playersInWar[source->GetTeamId()].find(source->GetGUID()) != _playersInWar[source->GetTeamId()].end())
            {
                _playersInWar[source->GetTeamId()].erase(source->GetGUID());
                if (Group* group = source->GetGroup())
                    group->RemoveMember(source->GetGUID());

                OnPlayerLeaveWar(source);
            }

            _players[source->GetTeamId()].erase(source->GetGUID());

            RemovePlayerFromResurrectQueue(source->GetGUID());
            OnPlayerLeaveZone(source);

            source->TeleportTo(source->m_homebindMapId, source->m_homebindX, source->m_homebindY, source->m_homebindZ, source->GetOrientation());
        }
    }
}

//*******************************************************
//******************* CapturePoint **********************
//*******************************************************

BattlefieldCapturePoint::BattlefieldCapturePoint(Battlefield* battlefield) : _battlefield(battlefield)
{
    _team = TEAM_NEUTRAL;
    _value = 0.f;
    _minValue = 0.f;
    _maxValue = 0.f;
    _state = BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL;
    _oldState = BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL;
    _capturePointEntry = 0;
    _neutralValuePct = 0;
    _maxSpeed = 0.f;
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
        {
            if (_activePlayers[player->GetTeamId()].insert(player->GetGUID()).second)
                HandlePlayerEnter(player);
        }
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
    {
        if (Player* player = ObjectAccessor::FindConnectedPlayer(*itr))
            player->KilledMonsterCredit(id, guid);
    }
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
    if (_resurrectQueue.insert(playerGUID).second)
    {
        if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
            player->CastSpell(player, BATTLEFIELD_SPELL_WAITING_FOR_RESURRECT, true);
    }
}

void BattlefieldGraveyard::RemovePlayer(ObjectGuid playerGUID)
{
    _resurrectQueue.erase(playerGUID);
    if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
        player->RemoveAurasDueToSpell(BATTLEFIELD_SPELL_WAITING_FOR_RESURRECT);
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
                spirit->CastSpell(spirit, BATTLEFIELD_SPELL_SPIRIT_HEAL, true);
        }

        // Resurrect player
        player->CastSpell(player, BATTLEFIELD_SPELL_RESURRECTION_VISUAL, true);
        player->ResurrectPlayer(1.0f);
        player->CastSpell(player, 6962, true);
        player->CastSpell(player, BATTLEFIELD_SPELL_SPIRIT_HEAL_MANA, true);
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
            closestGrave = _battlefield->GetClosestGraveyard(player);
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
