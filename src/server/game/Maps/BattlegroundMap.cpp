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

BattlegroundMap::BattlegroundMap(uint32 id, time_t expiry, uint32 instanceId, Map* parent, uint8 spawnMode, BattlegroundTemplate* bgTemplate)
    : Map(id, expiry, instanceId, spawnMode, parent),
    _template(bgTemplate),
    _preparationPhase(BG_STARTING_EVENT_FIRST)
{
    InitializeTextIds();
    InitializePreparationDelayTimes();  // Subclasses define timers or choose default
    InitializePreparationDelayTimer();  // Assign value to the current timer
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

void BattlegroundMap::InitializePreparationDelayTimes()
{
    // Default values for battlegrounds. Arena maps have different ones.
    PreparationPhaseTextIds[BG_STARTING_EVENT_FIRST]  = BG_START_DELAY_2M;
    PreparationPhaseTextIds[BG_STARTING_EVENT_SECOND] = BG_START_DELAY_1M;
    PreparationPhaseTextIds[BG_STARTING_EVENT_THIRD]  = BG_START_DELAY_30S;
    PreparationPhaseTextIds[BG_STARTING_EVENT_FOURTH] = BG_START_DELAY_NONE;
}

void BattlegroundMap::InitializePreparationDelayTimer()
{
    _preparationTimer = PreparationDelayTimers[BG_STARTING_EVENT_FIRST] - PreparationDelayTimers[BG_STARTING_EVENT_SECOND];
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
            _preparationTimer = PreparationDelayTimers[BG_STARTING_EVENT_SECOND] - PreparationDelayTimers[BG_STARTING_EVENT_THIRD];
            _preparationPhase = BG_STARTING_EVENT_SECOND;
            break;
        case BG_STARTING_EVENT_SECOND:
            _preparationTimer = PreparationDelayTimers[BG_STARTING_EVENT_THIRD] - PreparationDelayTimers[BG_STARTING_EVENT_FOURTH];
            _preparationPhase = BG_STARTING_EVENT_THIRD;
            break;
        case BG_STARTING_EVENT_THIRD:
            _preparationTimer = PreparationDelayTimers[BG_STARTING_EVENT_FOURTH];
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
    if (EndTimer <= diff || (_prematureCountdownTimer && _prematureCountdownTimer <= diff))
    {
        // This method will be overridden by inherited classes
        // and it will define the winner of the battleground
        EndBattleground();
        _status = STATUS_WAIT_LEAVE;
    }
    else
    {
        EndTimer -= diff;
        if (_prematureCountdownTimer)
            _prematureCountdownTimer -= diff;
    }
    break;
}

void BattlegroundMap::ProcessEnded(uint32 const& diff)
{
    ASSERT(_postEndTimer);
    if (_postEndTimer <= diff)
    {
        RemoveAllPlayers();
        DestroyBattleground();
    }    
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
    ++_participantCount[player->GetBGTeam()];

    if (AreTeamsInBalance())
        _prematureCountdownTimer = 0;
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

GameObject* BattlegroundMap::AddObject(uint32 type, uint32 entry, Position* pos, float rotation0, float rotation1, float rotation2, float rotation3, uint32 respawnTime /*= 0*/)
{
    // Must be created this way, adding to godatamap would add it to the base map of the instance
    // and when loading it (in go::LoadFromDB()), a new guid would be assigned to the object, and a new object would be created
    // So we must create it specific for this instance
    GameObject* go = new GameObject;
    if (!go->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_GAMEOBJECT), entry, this,
        PHASEMASK_NORMAL, pos->GetPositionX(), pos->GetPositionY, pos->GetPositionZ(), pos->GetOrientation(), rotation0, rotation1, rotation2, rotation3, 100, GO_STATE_READY))
    {
        sLog->outError("BattlegroundMap::AddObject: cannot create gameobject (entry: %u) for BG (map: %u, instance id: %u)!",
            entry, m_MapId, m_InstanceID);
        delete go;
        return NULL;
    }

    if (respawnTime)
        go->SetRespawnTime(respawnTime);

    // Add to world, so it can be later looked up from HashMapHolder
    Add(go);

    // Add to enum type -> guid lookup
    _objectGUIDsByType[type] = go->GetGUID();
    return go;
}

void BattlegroundMap::SpawnObject(uint32 type, uint32 respawntime)
{
    ASSERT(type < _objectGUIDsByType.size());

    uint64 guid = _objectGUIDsByType[type];
    if (!guid)
    {
        sLog->outError("BattlegroundMap::SpawnObject: tired to spawn defined type %u, but was not found in current map. "
                        "Are you missing an AddObject call in the Battleground initialization?", type);
        return;
    }

    GameObject* object = GetGameObject(guid);
    // If it's present in _objectGUIDsByType it MUST also be in world
    ASSERT (object);
    ASSERT (object->IsInWorld());
    ASSERT (object->GetMap() == this);

    if (respawntime)
        object->SetLootState(GO_JUST_DEACTIVATED);
    else if (object->getLootState() == GO_JUST_DEACTIVATED)
        // Change state from GO_JUST_DEACTIVATED to GO_READY in case battleground is starting again
        object->SetLootState(GO_READY);
    
    object->SetRespawnTime(respawntime);
}

bool BattlegroundMap::DeleteObject(uint32 type)
{
    ASSERT(type < _objectGUIDsByType.size());

    uint64 guid = _objectGUIDsByType[type];
    if (!guid)
    {
        sLog->outError("BattlegroundMap::DeleteObject: Tried to delete object type: %u from battleground (map: %u), but object was not registered in this BattlegroundMap!", type, GetId());
        return true;        // Already deleted or never added
    }

    GameObject* object = GetGameObject(guid);
    if (!object)
    {
        sLog->outError("BattlegroundMap::DeleteObject: Tried to delete object type: %u, entry: %u from battleground (map: %u), but object was not found in world!", type, GUID_ENPART(guid), GetId());
        return false;      // Was added, but now it's not in world any more. Data is desynchronized
    }

    object->SetRespawnTime(0);
    object->Delete();
    _objectGUIDsByType[type] = 0;
    return true;
}

Creature* BattlegroundMap::AddCreature(uint32 entry, uint32 type, uint32 teamval, Position* pos, uint32 respawntime /*= 0*/)
{
    ASSERT(type < _objectGUIDsByType.size());

    Creature* creature = new Creature;
    if (!creature->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_UNIT), map, PHASEMASK_NORMAL, entry, 0, teamval, pos->GetPositionX(), pos->GetPositionY, pos->GetPositionZ(), pos->GetOrientation()))
    {
        sLog->outError("BattlegroundMap::AddCreature: cannot create creature (entry: %u) for BG (map: %u)!",
            entry, GetId());
        delete creature;
        return NULL;
    }

    creature->SetHomePosition(pos);

    CreatureTemplate const *creatureInfo = sObjectMgr->GetCreatureTemplate(entry);
    if (!creatureInfo)
    {
        sLog->outError("BattlegroundMap::AddCreature: creature template (entry: %u) does not exist for BG (map: %u)!",
            entry, GetId());
        delete creature;
        return NULL;
    }

    // Force using DB speeds
    creature->SetSpeed(MOVE_WALK, creatureInfo->speed_walk);
    creature->SetSpeed(MOVE_RUN, creatureInfo->speed_run);

    Add(creature);
    _objectGUIDsByType[type] = creature->GetGUID();

    if (respawntime)
        creature->SetRespawnDelay(respawntime);

    return creature;
}

bool BattlegroundMap::DeleteCreature(uint32 type)
{
    ASSERT(type < _objectGUIDsByType.size());

    uint64 guid = _objectGUIDsByType[type];
    if (!guid)
    {
        sLog->outError("BattlegroundMap::DeleteCreaeture: Tried to delete creature type: %u from battleground (map: %u), but creature was not registered in this BattlegroundMap!", type, GetId());
        return true;        // Already deleted or never added
    }

    Creature* creature = GetCreature(guid);
    if (!creature)
    {
        sLog->outError("BattlegroundMap::DeleteCreaeture: Tried to delete creature type: %u, entry: %u from battleground (map: %u), but creature was not found in world!", type, GUID_ENPART(guid), GetId());
        return false;      // Was added, but now it's not in world any more. Data is desynchronized
    }

    creature->AddObjectToRemoveList();
    _objectGUIDsByType[type] = 0;
    return true;
}

void BattlegroundMap::UpdatePlayerScore(Player* source, uint32 type, uint32 value, bool addHonor /*= true*/)
{
    //this procedure is called from virtual function implemented in bg subclass
    BattlegroundScoreMap::const_iterator itr = ScoreMap.find(Source->GetGUIDLow());
    if (itr == ScoreMap.end())                         // player not found...
        return;

    switch (type)
    {
        case SCORE_KILLING_BLOWS:                           // Killing blows
            itr->second->KillingBlows += value;
            break;
        case SCORE_DEATHS:                                  // Deaths
            itr->second->Deaths += value;
            break;
        case SCORE_HONORABLE_KILLS:                         // Honorable kills
            itr->second->HonorableKills += value;
            break;
        case SCORE_BONUS_HONOR:                             // Honor bonus
            // do not add honor in arenas
            if (!IsBattleArena())
            {
                // reward honor instantly
                if (addHonor)
                    source->RewardHonor(NULL, 1, value);    // RewardHonor calls UpdatePlayerScore with doAddHonor = false
                else
                    itr->second->BonusHonor += value;
            }
            break;
        case SCORE_DAMAGE_DONE:                             // Damage Done
            itr->second->DamageDone += value;
            break;
        case SCORE_HEALING_DONE:                            // Healing Done
            itr->second->HealingDone += value;
            break;
        default:
            sLog->outError("BattlegroundMap::UpdatePlayerScore: unknown score type (%u) for BG (map: %u)!",
                type, GetId());
            break;
    }
}
