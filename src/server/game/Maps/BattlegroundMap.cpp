/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "BattlegroundMap.h"
#include "BattlegroundMgr.h"
#include "BattlegroundTemplate.h"
#include "WorldSession.h"
#include "WorldPacket.h"
#include "ObjectMgr.h"
#include "Player.h"

BattlegroundMap::BattlegroundMap(uint32 id, time_t expiry, uint32 instanceId, Map* parent, uint8 spawnMode)
    : Map(id, expiry, instanceId, spawnMode, parent)
{
    _preparationTimer = BG_START_DELAY_2M - BG_START_DELAY_1M;
    _preparationPhase = BG_STARTING_EVENT_FIRST;
}

BattlegroundMap::~BattlegroundMap()
{
}

void BattlegroundMap::InitVisibilityDistance()
{
    // Initialize visibility distance for BG/Arenas
    _visibleDistance = World::GetMaxVisibleDistanceInBGArenas();
    _visibilityNotifyPeriod = World::GetVisibilityNotifyPeriodInBGArenas();
}

bool BattlegroundMap::CanEnter(Player* player)
{
    if (player->GetMapRef().getTarget() == this)
    {
        sLog->outError("BGMap::CanEnter - player %u is already in map!", player->GetGUIDLow());
        ASSERT(false);
        return false;
    }

    if (player->GetBattlegroundId() != GetInstanceId())
        return false;

    // player number limit is checked in BattlegroundMgr, no need to do it here

    return Map::CanEnter(player);
}

bool BattlegroundMap::Add(Player* player)
{
    bool ret = Map::Add(player);
    OnPlayerJoin(player);
    return ret;
}

void BattlegroundMap::Remove(Player* player, bool remove)
{
    bool ret = Map::Remove(player, remove);
    OnPlayerExit();
    return ret;
}

void BattlegroundMap::SetUnload()
{
    m_unloadTimer = MIN_UNLOAD_DELAY;
}

void BattlegroundMap::Update(uint32 const& diff)
{
    // If the battleground is empty
    if (GetPlayers().isEmpty())
    {
        // If no one has been invited and is pending to join
        if (!_invitedCount[BG_TEAM_ALLIANCE] && !_invitedCount[BG_TEAM_HORDE])
            _status = STATUS_WAIT_LEAVE;

        return;
    }

    switch (_status)
    {
        // Statuses in chronological order
        case STATUS_WAIT_JOIN:
            ProcessPreparation(diff);
            break;
        case STATUS_IN_PROGRESS:
            ProcessInProgress(diff);
            break;
        case STATUS_WAIT_LEAVE:
            ProcessEnded(diff);
            break;
        default:
            ASSERT(false);
            break;
    }

    Map::Update(diff);
}

void BattlegroundMap::ProcessPreparation(uint32 const& diff)
{
    ASSERT(_preparationTimer);
    if (_preparationTimer <= diff)
        _preparationTimer = 0;
    else
        _preparationTimer -= diff;
    
    // No timer has passed yet, nothing to do
    if (_preparationTimer)
        return;
    
    // Send message to the players
    SendMessageToAll(PreparationPhaseTextIds[_preparationPhase, 
        _preparationPhase < BG_STARTING_EVENT_FOURTH ? CHAT_MSG_BG_SYSTEM_NEUTRAL : CHAT_MSG_RAID_BOSS_EMOTE);

    // Initialize timer for the next sub-phase of preparation.
    switch (_preparationPhase)
    {
        case BG_STARTING_EVENT_FIRST:
            _preparationTimer = BG_START_DELAY_1M - BG_START_DELAY_30S;
            _preparationPhase = BG_STARTING_EVENT_SECOND;
            break;
        case BG_STARTING_EVENT_SECOND:
            _preparationTimer = BG_START_DELAY_30S - BG_START_DELAY_15S;
            _preparationPhase = BG_STARTING_EVENT_THIRD;
            break;
        case BG_STARTING_EVENT_THIRD:
            _preparationTimer = BG_START_DELAY_15S - BG_START_DELAY_NONE;
            _preparationPhase = BG_STARTING_EVENT_FOURTH;
            break;
        case BG_STARTING_EVENT_FOURTH:
            _status = STATUS_IN_PROGRESS;
            StartBattleground();
            break;
    }
}

void BattlegroundMap::ProcessInProgress(uint32 const& diff)
{
    ASSERT(EndTimer);
    if (EndTimer <= diff)
        // This method will be overridden by inherited classes
        // and it will define the winner of the battleground
        EndBattleground();
        _status = STATUS_WAIT_LEAVE;
    else
        EndTimer -= diff;
    break;
}

void BattlegroundMap::ProcessEnded(uint32 const& diff)
{
    ASSERT(_postEndTimer);
    if (_postEndTimer <= diff)
        RemoveAllPlayers();
    else
        _postEndTimer -= diff;
}

void BattlegroundMap::RemoveAllPlayers()
{
    for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
    {
        Player* player = itr->getSource();
        if (!player)
            continue;

        OnPlayerExit(player);

        if (!player->IsBeingTeleportedFar())
            player->TeleportTo(player->GetBattlegroundEntryPoint());
    }
}

void BattlegroundMap::SendMessageToAll(int32 entry, ChatMsg type)
{
    const char *format = sObjectMgr->GetTrinityStringForDBCLocale(entry);

    char str[1024];
    va_list ap;
    va_start(ap, entry);
    vsnprintf(str, 1024, format, ap);
    va_end(ap);

    size_t stringLength = strlen(str) + 1;
    size_t packetSize = 1 + 4 + 8 + 4 + 4 + 1 + 8 + 4 + stringLength + 1;

    WorldPacket data(SMSG_MESSAGECHAT, packetSize);
    data << uint8(type);
    data << uint32(LANG_UNIVERSAL);
    data << uint64(0);
    data << uint32(0);                                // 2.1.0
    data << uint32(1);
    data << uint8(0);
    data << uint64(0);
    data << uint32(stringLength);
    data << str;
    data << uint8(0);

    for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
        if (Player* player = itr->getSource())
            if (plr->GetSession())
                plr->GetSession()->SendPacket(&data);
}

void BattlegroundMap::OnPlayerJoin(Player* player)
{
    ASSERT(player);
    ASSERT(_status != STATUS_WAIT_LEAVE);

    player->InstanceValid = true;
    ++_participantCount[player->GetBGTeam();
}

void BattlegroundMap::OnPlayerExit(Player* player)
{
    ASSERT(player);

    if (_status != STATUS_WAIT_LEAVE)
    {
        --_participantCount[player->GetBGTeam()];
        if (_status == STATUS_IN_PROGRESS && !AreTeamsInBalance())
            _prematureCountdownTimer = sBattlegroundMgr->GetPrematureFinishTime();
    }
}

bool BattlegroundMap::AreTeamsInBalance() const
{
    return !(_participantCount[BG_TEAM_HORDE] < _template.MinPlayersPerTeam ||
             _participantCount[BG_TEAM_ALLIANCE] < _template.MinPlayersPerTeam);
}
