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
#include "Formulas.h"

BattlegroundMap::BattlegroundMap(uint32 id, time_t expiry, uint32 instanceId, BattlegroundTemplate* bgTemplate)
    : MapInstanced(id, expiry),
    _template(bgTemplate),
    _instanceId(instanceId),
    PreparationPhase(BG_STARTING_EVENT_FIRST)
{
    InitializeTextIds();                // Subclasses define textIds 
    InitializePreparationDelayTimes();  // Subclasses define timers or choose default
    InitializePreparationDelayTimer();  // Assign value to the current timer
    InitializeObjects();                // Adds objects to storage
    InstallBattleground();              // Initialize variables
}

BattlegroundMap::~BattlegroundMap()
{
    DestroyBattleground();              // Cleanup
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
    PreparationTimer = PreparationDelayTimers[BG_STARTING_EVENT_FIRST] - PreparationDelayTimers[BG_STARTING_EVENT_SECOND];
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
            Status = STATUS_WAIT_LEAVE;

        return;
    }

    switch (Status)
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
    ASSERT(PreparationTimer);
    if (PreparationTimer <= diff)
        PreparationTimer = 0;
    else
        PreparationTimer -= diff;
    
    // No timer has passed yet, nothing to do
    if (PreparationTimer)
        return;
    
    // Send message to the players
    SendMessageToAll(PreparationPhaseTextIds[PreparationPhase, 
        PreparationPhase < BG_STARTING_EVENT_FOURTH ? CHAT_MSG_BG_SYSTEM_NEUTRAL : CHAT_MSG_RAID_BOSS_EMOTE);

    // Initialize timer for the next sub-phase of preparation.
    switch (PreparationPhase)
    {
        case BG_STARTING_EVENT_FIRST:
            PreparationTimer = PreparationDelayTimers[BG_STARTING_EVENT_SECOND] - PreparationDelayTimers[BG_STARTING_EVENT_THIRD];
            PreparationPhase = BG_STARTING_EVENT_SECOND;
            break;
        case BG_STARTING_EVENT_SECOND:
            PreparationTimer = PreparationDelayTimers[BG_STARTING_EVENT_THIRD] - PreparationDelayTimers[BG_STARTING_EVENT_FOURTH];
            PreparationPhase = BG_STARTING_EVENT_THIRD;
            break;
        case BG_STARTING_EVENT_THIRD:
            PreparationTimer = PreparationDelayTimers[BG_STARTING_EVENT_FOURTH];
            PreparationPhase = BG_STARTING_EVENT_FOURTH;
            break;
        case BG_STARTING_EVENT_FOURTH:
            Status = STATUS_IN_PROGRESS;
            StartBattleground();
            break;
    }
}

void BattlegroundMap::ProcessInProgress(uint32 const& diff)
{
    if ((EndTimer && EndTimer <= diff))
    {
        OnTimeoutReached();
        Status = STATUS_WAIT_LEAVE;
        PostEndTimer = TIME_TO_AUTOREMOVE:
    }
    else if (PrematureCountdownTimer && PrematureCountdownTimer <= diff))
    {
        // This method will be overridden by inherited classes
        // and it will define the winner of the battleground
        EndBattleground(WINNER_NONE);
        Status = STATUS_WAIT_LEAVE;
        PostEndTimer = TIME_TO_AUTOREMOVE:
    }
    else
    {
        if (EndTimer)
            EndTimer -= diff;
        if (_prematureCountdownTimer)
            _prematureCountdownTimer -= diff;
    }
    break;
}

void BattlegroundMap::ProcessEnded(uint32 const& diff)
{
    ASSERT(PostEndTimer);
    if (PostEndTimer <= diff)
    {
        RemoveAllPlayers();
        DestroyBattleground();
    }    
    else
        PostEndTimer -= diff;
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

void BattlegroundMap::SendMessageToAll(int32 entry, ChatMsg type, Unit* source /*=NULL*/, Language language /*= LANG_UNIVERSAL*/)
{
    const char *format = sObjectMgr->GetTrinityStringForDBCLocale(entry);

    char str[1024];
    va_list ap;
    va_start(ap, entry);
    vsnprintf(str, 1024, format, ap);
    va_end(ap);

    SendMessageToAll(str, type, source, language);
}

void BattlegroundMap::SendMessageToAll(char const* string, ChatMsg type, Unit* source /*=NULL*/, Language language /*= LANG_UNIVERSAL*/)
{
    size_t stringLength = strlen(str) + 1;
    size_t packetSize = 1 + 4 + 8 + 4 + 4 + 1 + 8 + 4 + stringLength + 1;

    uint64 targetGuid = source ? source->GetGUID() : 0;
    WorldPacket data(SMSG_MESSAGECHAT, packetSize);
    data << uint8(type);
    data << uint32(language);
    data << uint64(targetGuid);
    data << uint32(0);                                // 2.1.0
    data << uint32(1);
    data << uint8(0);
    data << uint64(targetGuid);
    data << uint32(stringLength);
    data << str;
    data << uint8(0);

    SendPacketToAll(&data);
}

void BattlegroundMap::PlaySoundToAll(uint32 soundId)
{
    WorldPacket data(SMSG_PLAY_SOUND, 4);
    data << uint32(soundId);
    SendPacketToAll(&data);
}

inline char const* BattlegroundMap::ParseStrings(int32 mainEntry, int32 args1, int32 args2 /*=0*/)
{
    char const* text = sObjectMgr->GetTrinityStringForDBCLocale(mainEntry);
    char const* arg1str = args1 ? sObjectMgr->GetTrinityStringForDBCLocale(args1) : "";
    char const* arg2str = args2 ? sObjectMgr->GetTrinityStringForDBCLocale(args2) : "";

    char str[1024];
    snprintf(str, 1024, text, arg1str, arg2str);

    return &str;
}

inline char const* BattlegroundMap::ParseStrings(int32 mainEntry, char const* args1, char const* args2/* = NULL*/)
{
    char const* text = sObjectMgr->GetTrinityStringForDBCLocale(mainEntry);

    char str[1024];
    snprintf(str, 1024, text, args1, args2);

    return &str;
}

inline char const* BattlegroundMap::ParseStrings(char const* mainString, int32 args)
{
    char const* text = sObjectMgr->GetTrinityStringForDBCLocale(args);

    char str[1024];
    snprintf(str, 1024, mainString, text);

    return &str;   
}

inline char const* BattlegroundMap::ParseStrings(int32 mainEntry, int32 args1, const char* args2 /*= NULL*/)
{
    char const* text = sObjectMgr->GetTrinityStringForDBCLocale(mainEntry);
    char const* arg1str = args1 ? sObjectMgr->GetTrinityStringForDBCLocale(args1) : "";

    char str[1024];
    snprintf(str, 1024, text, arg1str, args2);

    return &str;
}

void BattlegroundMap::OnPlayerJoin(Player* player)
{
    ASSERT(player);
    ASSERT(Status != STATUS_WAIT_LEAVE);

    SendPlayerJoinedPacket(player);)

    player->InstanceValid = true;
    player->SetBGTeam(player->GetTeamId());
    ++_participantCount[player->GetBGTeam()];

    if (AreTeamsInBalance())
        _prematureCountdownTimer = 0;
}

void BattlegroundMap::OnPlayerExit(Player* player)
{
    ASSERT(player);

    SendPlayerLeftPacket(player);

    --ParticipantCount[player->GetBGTeam()];

    if (Status == STATUS_IN_PROGRESS && !AreTeamsInBalance())
        PrematureCountdownTimer = sBattlegroundMgr->GetPrematureFinishTime();

    if (Status != STATUS_WAIT_LEAVE)
    {
        delete PlayerScores[player->GetGUIDLow()];
        PlayerScores.erase(player->GetGUIDLow());
    }
}

bool BattlegroundMap::AreTeamsInBalance() const
{
    return !(ParticipantCount[BG_TEAM_HORDE] < _template.MinPlayersPerTeam ||
             ParticipantCount[BG_TEAM_ALLIANCE] < _template.MinPlayersPerTeam);
}

GameObject* BattlegroundMap::AddGameObject(uint32 type, uint32 entry, float x, float y, float z, float o, float r0, float r1, float r2, float r3, uint32 respawnTime /*= 0*/)
{
    Position pos;
    pos.Relocate(x, y, z, o);
    return AddGameObject(type, entry, &pos, r0, r1, r2, r3, respawnTime);
}

GameObject* BattlegroundMap::AddGameObject(uint32 type, uint32 entry, Position* pos, float rotation0, float rotation1, float rotation2, float rotation3, uint32 respawnTime /*= 0*/)
{
    // Must be created this way, adding to godatamap would add it to the base map of the instance
    // and when loading it (in go::LoadFromDB()), a new guid would be assigned to the object, and a new object would be created
    // So we must create it specific for this instance
    GameObject* go = new GameObject;
    if (!go->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_GAMEOBJECT), entry, this,
        PHASEMASK_NORMAL, pos->GetPositionX(), pos->GetPositionY, pos->GetPositionZ(), pos->GetOrientation(), rotation0, rotation1, rotation2, rotation3, 100, GO_STATE_READY))
    {
        sLog->outError("BattlegroundMap::AddObject: cannot create gameobject (entry: %u) for BG (map: %u)!",
            entry, GetId());
        delete go;
        return NULL;
    }

    if (respawnTime)
        go->SetRespawnTime(respawnTime);

    // Add to world, so it can be later looked up from HashMapHolder
    Add(go);

    // Add to enum type -> guid lookup
    ObjectGUIDsByType[type] = go->GetGUID();
    return go;
}

GameObject* BattlegroundMap::GetGameObject(uint32 type)
{
    ASSERT(type < ObjectGUIDsByType.size());

    uint64 guid = ObjectGUIDsByType[type];
    if (!guid)
    {
        sLog->outError("BattlegroundMap::GetGameObject: tired to get defined type %u, but was not found in current map. "
            "Are you missing an AddObject call in the Battleground initialization?", type);
        return NULL;
    }

    return Map::GetGameObject(guid);
}

void BattlegroundMap::SpawnGameObject(uint32 type, uint32 respawntime)
{
    GameObject* object = GetGameObject(type);
    // If it's present in ObjectGUIDsByType it MUST also be in world
    ASSERT(object);
    ASSERT(object->IsInWorld());
    ASSERT(object->GetMap() == this);

    if (respawntime)
        object->SetLootState(GO_JUST_DEACTIVATED);
    else if (object->getLootState() == GO_JUST_DEACTIVATED)
        // Change state from GO_JUST_DEACTIVATED to GO_READY in case battleground is starting again
        object->SetLootState(GO_READY);
    
    object->SetRespawnTime(respawntime);
}

bool BattlegroundMap::DeleteGameObject(uint32 type)
{
    ASSERT(type < ObjectGUIDsByType.size());

    uint64 guid = ObjectGUIDsByType[type];
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
    ObjectGUIDsByType[type] = 0;
    return true;
}

// Some doors aren't despawned so we cannot handle their closing in gameobject::update()
// It would be nice to correctly implement GO_ACTIVATED state and open/close doors in gameobject code
void BattlegroundMap::DoorClose(uint32 type)
{
    if (GameObject* obj = GetGameObject(type))
    {
        // If doors are open, close it
        if (obj->getLootState() == GO_ACTIVATED && obj->GetGoState() != GO_STATE_READY)
        {
            // Change state to allow door to be closed
            obj->SetLootState(GO_READY);
            obj->UseDoorOrButton(RESPAWN_ONE_DAY);
        }
    }
    else
        sLog->outError("BattlegroundMap::DoorClose: door gameobject (type: %u, GUID: %u) not found for BG (map: %u)!",
        type, GUID_LOPART(ObjectGUIDsByType[type]), GetId());
}

void BattlegroundMap::DoorOpen(uint32 type)
{
    if (GameObject* obj = GetGameObject(type))
    {
        // Change state to be sure they will be opened
        obj->SetLootState(GO_READY);
        obj->UseDoorOrButton(RESPAWN_ONE_DAY);
    }
    else
        sLog->outError("BattlegroundMap::DoorOpen: door gameobject (type: %u, GUID: %u) not found for BG (map: %u, instance id: %u)!",
        type, GUID_LOPART(ObjectGUIDsByType[type]), m_MapId, m_InstanceID);
}

void BattlegroundMap::AddSpiritGuide(uint32 type, float x, float y, float z, float o, uint32 team)
{
    uint32 entry = (team == BG_TEAM_ALLIANCE) ?
        BG_CREATURE_ENTRY_A_SPIRITGUIDE :
        BG_CREATURE_ENTRY_H_SPIRITGUIDE;

    Creature* pCreature = AddCreature(entry, type, team, x, y, z, o);
    pCreature->setDeathState(DEAD);
    pCreature->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, pCreature->GetGUID());
    // aura
    // TODO: Fix display here
    // pCreature->SetVisibleAura(0, SPELL_SPIRIT_HEAL_CHANNEL);
    // casting visual effect
    pCreature->SetUInt32Value(UNIT_CHANNEL_SPELL, SPELL_SPIRIT_HEAL_CHANNEL);
    // correct cast speed
    pCreature->SetFloatValue(UNIT_MOD_CAST_SPEED, 1.0f);
    //pCreature->CastSpell(pCreature, SPELL_SPIRIT_HEAL_CHANNEL, true);
}

Creature* BattlegroundMap::AddCreature(uint32 entry, uint32 type, uint32 teamval, float x, float y, float z, float o, uint32 respawntime /*= 0*/)
{
    Position pos;
    pos.Relocate(x, y, z, o);
    AddCreature(entry, type, teamval, pos, respawntime);
}

Creature* BattlegroundMap::AddCreature(uint32 entry, uint32 type, uint32 teamval, Position* pos, uint32 respawntime /*= 0*/)
{
    ASSERT(type < ObjectGUIDsByType.size());

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
    ObjectGUIDsByType[type] = creature->GetGUID();

    if (respawntime)
        creature->SetRespawnDelay(respawntime);

    return creature;
}

Creature* BattlegroundMap::GetCreature(uint32 type)
{
    ASSERT(type < ObjectGUIDsByType.size());

    uint64 guid = ObjectGUIDsByType[type];
    if (!guid)
    {
        sLog->outError("BattlegroundMap::GetCreature: Tried to delete creature type: %u from battleground (map: %u), but creature was not registered in this BattlegroundMap!", type, GetId());
        return NULL;        // Already deleted or never added
    }

    return Map::GetCreature(guid);
}

bool BattlegroundMap::DeleteCreature(uint32 type)
{
    ASSERT(type < ObjectGUIDsByType.size());

    uint64 guid = ObjectGUIDsByType[type];
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
    ObjectGUIDsByType[type] = 0;
    return true;
}

int32 BattlegroundMap::GetObjectType(uint64 const& guid) const
{
    for (uint32 i = 0; i < ObjectGUIDsByType.size(); ++i)
        if (ObjectGUIDsByType[i] == guid)
            return i;

    return -1;
}

void BattlegroundMap::UpdatePlayerScore(Player* source, uint32 type, uint32 value, bool addHonor /*= true*/)
{
    //this procedure is called from virtual function implemented in bg subclass
    BattlegroundScoreMap::const_iterator itr = PlayerScores.find(Source->GetGUIDLow());
    if (itr == PlayerScores.end())                         // player not found...
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

void BattlegroundMap::SendPlayerJoinedPacket(Player* player)
{
    WorldPacket data(SMSG_BATTLEGROUND_PLAYER_JOINED, 8);
    data << uint64(player->GetGUID());
    SendPacketToTeam(&data, player->GetBGTeam(), player);
}

void BattlegroundMap::SendPlayerLeftPacket(Player* player)
{
    WorldPacket data(SMSG_BATTLEGROUND_PLAYER_LEFT, 8);
    data << uint64(player->GetGUID());
    SendPacketToTeam(&data, player->GetBGTeam(), player);
}

void BattlegroundMap::UpdateWorldState(uint32 type, uint32 value)
{
    WorldPacket data(SMSG_UPDATE_WORLD_STATE, 4+4);
    data << uint32(type);
    data << uint32(value);
    SendPacketToAll(&data);
}

void BattlegroundMap::BuildPVPLogDataPacket(WorldPacket& data)
{
    data->Initialize(MSG_PVP_LOG_DATA, (1+1+4+40*bg->GetPlayerScoresSize()));
    *data << uint8(0);                                      // 1 for arena's

    if (GetStatus() != STATUS_WAIT_LEAVE)
        *data << uint8(0);                                  // bg not ended
    else
    {
        *data << uint8(1);                                  // bg ended
        *data << uint8(GetWinningTeam());                   // who won
    }

    *data << uint32(PlayerScores.size());
    for (BattlegroundScoreMap::const_iterator itr = PlayerScores.begin(); itr != PlayerScores.end(); ++itr)
    {
        *data << uint64(MAKE_NEW_GUID(itr->first, 0, HIGHGUID_PLAYER));
        itr->second->AppendToPacket(&data);
    }
}

void BattlegroundMap::SendPacketToAll(WorldPacket* data)
{
    for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
        if (Player* player = itr->getSource())
            if (player->GetSession())
                player->GetSession()->SendPacket(&data);
}

void BattlegroundMap::SendPacketToTeam(WorldPacket* data, uint32 team, Player* exclude)
{
    for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
        if (Player* player = itr->getSource())
            if (player->GetSession() && team == player->GetBGTeam() && player != exclude))
                player->GetSession()->SendPacket(&data);
}

inline uint32 BattlegroundMap::GetBonusHonorFromKill uint32 kills) const
{
    //variable kills means how many honorable kills you scored (so we need kills * honor_for_one_kill)
    return Trinity::Honor::hk_honor_at_level(std::min(GetMaxLevel(), 80U), float(kills));
}

inline void BattlegroundMap::StartTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry)
{
    for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
        if (Player* player = itr->getSource())
            player->GetAchievementMgr().StartTimedAchievement(type, entry);
}

void BattlegroundMap::RewardHonorToTeam(uint32 amount, BattlegroundTeamId team)
{
    for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
        if (Player* player = itr->getSource() && player->GetBGTeam() == team)
            UpdatePlayerScore(player, SCORE_BONUS_HONOR, amount);
}

void BattlegroundMap::RewardReputationToTeam(uint32 targetFaction, uint32 amount, BattlegroundTeamId team)
{
    for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
        if (Player* player = itr->getSource() && player->GetBGTeam() == team)
            player->GetReputationMgr().ModifyReputation(targetFaction, amount);
}

void BattlegroundMap::CastSpellOnTeam(uint32 spell, BattlegroundTeamId team)
{
    for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
        if (Player* player = itr->getSource() && player->GetBGTeam() == team)
            player->CastSpell(player, spell, true);
}

void BattlegroundMap::RemoveAuraOnTeam(uint32 spell, BattlegroundTeamId team)
{
    for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
        if (Player* player = itr->getSource() && player->GetBGTeam() == team)
            player->RemoveAura(spell);
}
