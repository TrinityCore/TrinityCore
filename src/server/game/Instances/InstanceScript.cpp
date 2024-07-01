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

#include "InstanceScript.h"
#include "AreaBoundary.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "DatabaseEnv.h"
#include "DBCStructure.h"
#include "GameObject.h"
#include "Group.h"
#include "LFGMgr.h"
#include "Log.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Pet.h"
#include "Player.h"
#include "RBAC.h"
#include "ScriptMgr.h"
#include "ScriptReloadMgr.h"
#include "World.h"
#include "WorldSession.h"
#include <cstdarg>
#include <sstream>

BossBoundaryData::~BossBoundaryData()
{
    for (const_iterator it = begin(); it != end(); ++it)
        delete it->Boundary;
}

InstanceScript::InstanceScript(InstanceMap* map) : instance(map), completedEncounters(0), _instanceSpawnGroups(sObjectMgr->GetSpawnGroupsForInstance(map->GetId()))
{
#ifdef TRINITY_API_USE_DYNAMIC_LINKING
    uint32 scriptId = sObjectMgr->GetInstanceTemplate(map->GetId())->ScriptId;
    auto const scriptname = sObjectMgr->GetScriptName(scriptId);
    ASSERT(!scriptname.empty());
   // Acquire a strong reference from the script module
   // to keep it loaded until this object is destroyed.
    module_reference = sScriptMgr->AcquireModuleReferenceOfScriptName(scriptname);
#endif // #ifndef TRINITY_API_USE_DYNAMIC_LINKING
}

void InstanceScript::SaveToDB()
{
    std::string data = GetSaveData();
    if (data.empty())
        return;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_INSTANCE_DATA);
    stmt->setUInt32(0, GetCompletedEncounterMask());
    stmt->setString(1, data);
    stmt->setUInt32(2, instance->GetInstanceId());
    CharacterDatabase.Execute(stmt);
}

bool InstanceScript::IsEncounterInProgress() const
{
    for (std::vector<BossInfo>::const_iterator itr = bosses.begin(); itr != bosses.end(); ++itr)
        if (itr->state == IN_PROGRESS)
            return true;

    return false;
}

void InstanceScript::OnCreatureCreate(Creature* creature)
{
    AddObject(creature, true);
    AddMinion(creature, true);
}

void InstanceScript::OnCreatureRemove(Creature* creature)
{
    AddObject(creature, false);
    AddMinion(creature, false);
}

void InstanceScript::OnGameObjectCreate(GameObject* go)
{
    AddObject(go, true);
    AddDoor(go, true);
}

void InstanceScript::OnGameObjectRemove(GameObject* go)
{
    AddObject(go, false);
    AddDoor(go, false);
}

ObjectGuid InstanceScript::GetObjectGuid(uint32 type) const
{
    ObjectGuidMap::const_iterator i = _objectGuids.find(type);
    if (i != _objectGuids.end())
        return i->second;
    return ObjectGuid::Empty;
}

ObjectGuid InstanceScript::GetGuidData(uint32 type) const
{
    return GetObjectGuid(type);
}

Creature* InstanceScript::GetCreature(uint32 type)
{
    return instance->GetCreature(GetObjectGuid(type));
}

GameObject* InstanceScript::GetGameObject(uint32 type)
{
    return instance->GetGameObject(GetObjectGuid(type));
}

void InstanceScript::SetHeaders(std::string const& dataHeaders)
{
    for (char header : dataHeaders)
        if (isalpha(header))
            headers.push_back(header);
}

void InstanceScript::LoadBossBoundaries(BossBoundaryData const& data)
{
    for (BossBoundaryEntry const& entry : data)
        if (entry.BossId < bosses.size())
            bosses[entry.BossId].boundary.push_back(entry.Boundary);
}

void InstanceScript::LoadMinionData(MinionData const* data)
{
    while (data->entry)
    {
        if (data->bossId < bosses.size())
            minions.insert(std::make_pair(data->entry, MinionInfo(&bosses[data->bossId])));

        ++data;
    }
    TC_LOG_DEBUG("scripts", "InstanceScript::LoadMinionData: {} minions loaded.", uint64(minions.size()));
}

void InstanceScript::LoadDoorData(DoorData const* data)
{
    while (data->entry)
    {
        if (data->bossId < bosses.size())
            doors.insert(std::make_pair(data->entry, DoorInfo(&bosses[data->bossId], data->type)));

        ++data;
    }
    TC_LOG_DEBUG("scripts", "InstanceScript::LoadDoorData: {} doors loaded.", uint64(doors.size()));
}

void InstanceScript::LoadObjectData(ObjectData const* creatureData, ObjectData const* gameObjectData)
{
    if (creatureData)
        LoadObjectData(creatureData, _creatureInfo);

    if (gameObjectData)
        LoadObjectData(gameObjectData, _gameObjectInfo);

    TC_LOG_DEBUG("scripts", "InstanceScript::LoadObjectData: {} objects loaded.", _creatureInfo.size() + _gameObjectInfo.size());
}

void InstanceScript::LoadObjectData(ObjectData const* data, ObjectInfoMap& objectInfo)
{
    while (data->entry)
    {
        ASSERT(objectInfo.find(data->entry) == objectInfo.end());
        objectInfo[data->entry] = data->type;
        ++data;
    }
}

void InstanceScript::UpdateDoorState(GameObject* door)
{
    DoorInfoMapBounds range = doors.equal_range(door->GetEntry());
    if (range.first == range.second)
        return;

    bool open = true;
    for (; range.first != range.second && open; ++range.first)
    {
        DoorInfo const& info = range.first->second;
        switch (info.type)
        {
            case DOOR_TYPE_ROOM:
                open = (info.bossInfo->state != IN_PROGRESS);
                break;
            case DOOR_TYPE_PASSAGE:
                open = (info.bossInfo->state == DONE);
                break;
            case DOOR_TYPE_SPAWN_HOLE:
                open = (info.bossInfo->state == IN_PROGRESS);
                break;
            default:
                break;
        }
    }

    door->SetGoState(open ? GO_STATE_ACTIVE : GO_STATE_READY);
}

void InstanceScript::UpdateMinionState(Creature* minion, EncounterState state)
{
    switch (state)
    {
        case NOT_STARTED:
            if (!minion->IsAlive())
                minion->Respawn();
            else if (minion->IsInCombat())
                minion->AI()->EnterEvadeMode();
            break;
        case IN_PROGRESS:
            if (!minion->IsAlive())
                minion->Respawn();
            else if (!minion->GetVictim())
                minion->AI()->DoZoneInCombat();
            break;
        default:
            break;
    }
}

void InstanceScript::UpdateSpawnGroups()
{
    if (!_instanceSpawnGroups)
        return;
    enum states { BLOCK, SPAWN, FORCEBLOCK };
    std::unordered_map<uint32, states> newStates;
    for (auto it = _instanceSpawnGroups->begin(), end = _instanceSpawnGroups->end(); it != end; ++it)
    {
        InstanceSpawnGroupInfo const& info = *it;
        states& curValue = newStates[info.SpawnGroupId]; // makes sure there's a BLOCK value in the map
        if (curValue == FORCEBLOCK) // nothing will change this
            continue;
        if (!((1 << GetBossState(info.BossStateId)) & info.BossStates))
            continue;
        if (((instance->GetTeamIdInInstance() == TEAM_ALLIANCE) && (info.Flags & InstanceSpawnGroupInfo::FLAG_HORDE_ONLY))
            || ((instance->GetTeamIdInInstance() == TEAM_HORDE) && (info.Flags & InstanceSpawnGroupInfo::FLAG_ALLIANCE_ONLY)))
            continue;
        if (info.Flags & InstanceSpawnGroupInfo::FLAG_BLOCK_SPAWN)
            curValue = FORCEBLOCK;
        else if (info.Flags & InstanceSpawnGroupInfo::FLAG_ACTIVATE_SPAWN)
            curValue = SPAWN;
    }
    for (auto const& pair : newStates)
    {
        uint32 const groupId = pair.first;
        bool const doSpawn = (pair.second == SPAWN);
        if (instance->IsSpawnGroupActive(groupId) == doSpawn)
            continue; // nothing to do here
        // if we should spawn group, then spawn it...
        if (doSpawn)
            instance->SpawnGroupSpawn(groupId);
        else // otherwise, set it as inactive so it no longer respawns (but don't despawn it)
            instance->SetSpawnGroupInactive(groupId);
    }
}

BossInfo* InstanceScript::GetBossInfo(uint32 id)
{
    ASSERT(id < bosses.size());
    return &bosses[id];
}

void InstanceScript::AddObject(Creature* obj, bool add)
{
    ObjectInfoMap::const_iterator j = _creatureInfo.find(obj->GetEntry());
    if (j != _creatureInfo.end())
        AddObject(obj, j->second, add);
}

void InstanceScript::AddObject(GameObject* obj, bool add)
{
    ObjectInfoMap::const_iterator j = _gameObjectInfo.find(obj->GetEntry());
    if (j != _gameObjectInfo.end())
        AddObject(obj, j->second, add);
}

void InstanceScript::AddObject(WorldObject* obj, uint32 type, bool add)
{
    if (add)
        _objectGuids[type] = obj->GetGUID();
    else
    {
        ObjectGuidMap::iterator i = _objectGuids.find(type);
        if (i != _objectGuids.end() && i->second == obj->GetGUID())
            _objectGuids.erase(i);
    }
}

void InstanceScript::AddDoor(GameObject* door, bool add)
{
    DoorInfoMapBounds range = doors.equal_range(door->GetEntry());
    if (range.first == range.second)
        return;

    for (; range.first != range.second; ++range.first)
    {
        DoorInfo const& data = range.first->second;

        if (add)
        {
            data.bossInfo->door[data.type].insert(door->GetGUID());
        }
        else
            data.bossInfo->door[data.type].erase(door->GetGUID());
    }

    if (add)
        UpdateDoorState(door);
}

void InstanceScript::AddMinion(Creature* minion, bool add)
{
    MinionInfoMap::iterator itr = minions.find(minion->GetEntry());
    if (itr == minions.end())
        return;

    if (add)
        itr->second.bossInfo->minion.insert(minion->GetGUID());
    else
        itr->second.bossInfo->minion.erase(minion->GetGUID());
}

bool InstanceScript::SetBossState(uint32 id, EncounterState state)
{
    if (id < bosses.size())
    {
        BossInfo* bossInfo = &bosses[id];
        if (bossInfo->state == TO_BE_DECIDED) // loading
        {
            bossInfo->state = state;
            TC_LOG_DEBUG("scripts", "InstanceScript: Initialize boss {} state as {} (map {}, {}).", id, GetBossStateName(state), instance->GetId(), instance->GetInstanceId());
            return false;
        }
        else
        {
            if (bossInfo->state == state)
                return false;

            if (bossInfo->state == DONE)
            {
                TC_LOG_ERROR("map", "InstanceScript: Tried to set instance boss {} state from {} back to {} for map {}, instance id {}. Blocked!", id, GetBossStateName(bossInfo->state), GetBossStateName(state), instance->GetId(), instance->GetInstanceId());
                return false;
            }

            if (state == DONE)
                for (GuidSet::iterator i = bossInfo->minion.begin(); i != bossInfo->minion.end(); ++i)
                    if (Creature* minion = instance->GetCreature(*i))
                        if (minion->isWorldBoss() && minion->IsAlive())
                            return false;

            bossInfo->state = state;
            SaveToDB();
        }

        for (uint32 type = 0; type < MAX_DOOR_TYPES; ++type)
            for (GuidSet::iterator i = bossInfo->door[type].begin(); i != bossInfo->door[type].end(); ++i)
                if (GameObject* door = instance->GetGameObject(*i))
                    UpdateDoorState(door);

        GuidSet minions = bossInfo->minion; // Copy to prevent iterator invalidation (minion might be unsummoned in UpdateMinionState)
        for (GuidSet::iterator i = minions.begin(); i != minions.end(); ++i)
            if (Creature* minion = instance->GetCreature(*i))
                UpdateMinionState(minion, state);

        UpdateSpawnGroups();
        return true;
    }
    return false;
}

bool InstanceScript::_SkipCheckRequiredBosses(Player const* player /*= nullptr*/) const
{
    return player && player->GetSession()->HasPermission(rbac::RBAC_PERM_SKIP_CHECK_INSTANCE_REQUIRED_BOSSES);
}

void InstanceScript::Create()
{
    for (size_t i = 0; i < bosses.size(); ++i)
        SetBossState(i, NOT_STARTED);
    UpdateSpawnGroups();
}

void InstanceScript::Load(char const* data)
{
    if (!data)
    {
        OUT_LOAD_INST_DATA_FAIL;
        return;
    }

    OUT_LOAD_INST_DATA(data);

    std::istringstream loadStream(data);

    if (ReadSaveDataHeaders(loadStream))
    {
        ReadSaveDataBossStates(loadStream);
        ReadSaveDataMore(loadStream);
    }
    else
        OUT_LOAD_INST_DATA_FAIL;

    OUT_LOAD_INST_DATA_COMPLETE;
}

bool InstanceScript::ReadSaveDataHeaders(std::istringstream& data)
{
    for (char header : headers)
    {
        char buff;
        data >> buff;

        if (header != buff)
            return false;
    }

    return true;
}

void InstanceScript::ReadSaveDataBossStates(std::istringstream& data)
{
    uint32 bossId = 0;
    for (std::vector<BossInfo>::iterator i = bosses.begin(); i != bosses.end(); ++i, ++bossId)
    {
        uint32 buff;
        data >> buff;
        if (buff == IN_PROGRESS || buff == FAIL || buff == SPECIAL)
            buff = NOT_STARTED;

        if (buff < TO_BE_DECIDED)
            SetBossState(bossId, EncounterState(buff));
    }
    UpdateSpawnGroups();
}

std::string InstanceScript::GetSaveData()
{
    OUT_SAVE_INST_DATA;

    std::ostringstream saveStream;

    WriteSaveDataHeaders(saveStream);
    WriteSaveDataBossStates(saveStream);
    WriteSaveDataMore(saveStream);

    OUT_SAVE_INST_DATA_COMPLETE;

    return saveStream.str();
}

void InstanceScript::WriteSaveDataHeaders(std::ostringstream& data)
{
    for (char header : headers)
        data << header << ' ';
}

void InstanceScript::WriteSaveDataBossStates(std::ostringstream& data)
{
    for (BossInfo const& bossInfo : bosses)
        data << uint32(bossInfo.state) << ' ';
}

void InstanceScript::HandleGameObject(ObjectGuid guid, bool open, GameObject* go /*= nullptr*/)
{
    if (!go)
        go = instance->GetGameObject(guid);
    if (go)
        go->SetGoState(open ? GO_STATE_ACTIVE : GO_STATE_READY);
    else
        TC_LOG_DEBUG("scripts", "InstanceScript: HandleGameObject failed");
}

void InstanceScript::DoUseDoorOrButton(ObjectGuid guid, uint32 withRestoreTime /*= 0*/, bool useAlternativeState /*= false*/)
{
    if (!guid)
        return;

    if (GameObject* go = instance->GetGameObject(guid))
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_DOOR || go->GetGoType() == GAMEOBJECT_TYPE_BUTTON)
        {
            if (go->getLootState() == GO_READY)
                go->UseDoorOrButton(withRestoreTime, useAlternativeState);
            else if (go->getLootState() == GO_ACTIVATED)
                go->ResetDoorOrButton();
        }
        else
            TC_LOG_ERROR("scripts", "InstanceScript: DoUseDoorOrButton can't use gameobject entry {}, because type is {}.", go->GetEntry(), go->GetGoType());
    }
    else
        TC_LOG_DEBUG("scripts", "InstanceScript: DoUseDoorOrButton failed");
}

void InstanceScript::DoCloseDoorOrButton(ObjectGuid guid)
{
    if (!guid)
        return;

    if (GameObject* go = instance->GetGameObject(guid))
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_DOOR || go->GetGoType() == GAMEOBJECT_TYPE_BUTTON)
        {
            if (go->getLootState() == GO_ACTIVATED)
                go->ResetDoorOrButton();
        }
        else
            TC_LOG_ERROR("scripts", "InstanceScript: DoCloseDoorOrButton can't use gameobject entry {}, because type is {}.", go->GetEntry(), go->GetGoType());
    }
    else
        TC_LOG_DEBUG("scripts", "InstanceScript: DoCloseDoorOrButton failed");
}

void InstanceScript::DoRespawnGameObject(ObjectGuid guid, Seconds timeToDespawn /*= 1min */)
{
    if (GameObject* go = instance->GetGameObject(guid))
    {
        switch (go->GetGoType())
        {
            case GAMEOBJECT_TYPE_DOOR:
            case GAMEOBJECT_TYPE_BUTTON:
            case GAMEOBJECT_TYPE_TRAP:
            case GAMEOBJECT_TYPE_FISHINGNODE:
                // not expect any of these should ever be handled
                TC_LOG_ERROR("scripts", "InstanceScript: DoRespawnGameObject can't respawn gameobject entry {}, because type is {}.", go->GetEntry(), go->GetGoType());
                return;
            default:
                break;
        }

        if (go->isSpawned())
            return;

        go->SetRespawnTime(timeToDespawn.count());
    }
    else
        TC_LOG_DEBUG("scripts", "InstanceScript: DoRespawnGameObject failed");
}

void InstanceScript::DoUpdateWorldState(uint32 uiStateId, uint32 uiStateData)
{
    Map::PlayerList const& lPlayers = instance->GetPlayers();

    if (!lPlayers.isEmpty())
    {
        for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
            if (Player* player = itr->GetSource())
                player->SendUpdateWorldState(uiStateId, uiStateData);
    }
    else
        TC_LOG_DEBUG("scripts", "DoUpdateWorldState attempt send data but no players in map.");
}

// Send Notify to all players in instance
void InstanceScript::DoSendNotifyToInstance(char const* format, ...)
{
    InstanceMap::PlayerList const& players = instance->GetPlayers();

    if (!players.isEmpty())
    {
        va_list ap;
        va_start(ap, format);
        char buff[1024];
        vsnprintf(buff, 1024, format, ap);
        va_end(ap);
        for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
            if (Player* player = i->GetSource())
                if (WorldSession* session = player->GetSession())
                    session->SendNotification("%s", buff);
    }
}

// Update Achievement Criteria for all players in instance
void InstanceScript::DoUpdateAchievementCriteria(AchievementCriteriaTypes type, uint32 miscValue1 /*= 0*/, uint32 miscValue2 /*= 0*/, Unit* unit /*= nullptr*/)
{
    Map::PlayerList const& PlayerList = instance->GetPlayers();

    if (!PlayerList.isEmpty())
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (Player* player = i->GetSource())
                player->UpdateAchievementCriteria(type, miscValue1, miscValue2, unit);
}

// Start timed achievement for all players in instance
void InstanceScript::DoStartTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry)
{
    Map::PlayerList const& PlayerList = instance->GetPlayers();

    if (!PlayerList.isEmpty())
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (Player* player = i->GetSource())
                player->StartTimedAchievement(type, entry);
}

// Stop timed achievement for all players in instance
void InstanceScript::DoStopTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry)
{
    Map::PlayerList const& PlayerList = instance->GetPlayers();

    if (!PlayerList.isEmpty())
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (Player* player = i->GetSource())
                player->RemoveTimedAchievement(type, entry);
}

void InstanceScript::DoRemoveAurasDueToSpellOnPlayers(uint32 spell, bool includePets /*= false*/, bool includeControlled /*= false*/)
{
    Map::PlayerList const& playerList = instance->GetPlayers();
    for (auto itr = playerList.begin(); itr != playerList.end(); ++itr)
        DoRemoveAurasDueToSpellOnPlayer(itr->GetSource(), spell, includePets, includeControlled);
}

void InstanceScript::DoRemoveAurasDueToSpellOnPlayer(Player* player, uint32 spell, bool includePets /*= false*/, bool includeControlled /*= false*/)
{
    if (!player)
        return;

    player->RemoveAurasDueToSpell(spell);

    if (!includePets)
        return;

    for (uint8 itr2 = 0; itr2 < MAX_SUMMON_SLOT; ++itr2)
    {
        if (ObjectGuid summonGUID = player->m_SummonSlot[itr2])
            if (Creature* summon = instance->GetCreature(summonGUID))
                summon->RemoveAurasDueToSpell(spell);
    }

    if (!includeControlled)
        return;

    for (auto itr2 = player->m_Controlled.begin(); itr2 != player->m_Controlled.end(); ++itr2)
    {
        if (Unit* controlled = *itr2)
            if (controlled->IsInWorld() && controlled->GetTypeId() == TYPEID_UNIT)
                controlled->RemoveAurasDueToSpell(spell);
    }
}

void InstanceScript::DoCastSpellOnPlayers(uint32 spell, bool includePets /*= false*/, bool includeControlled /*= false*/)
{
    Map::PlayerList const& playerList = instance->GetPlayers();
    for (auto itr = playerList.begin(); itr != playerList.end(); ++itr)
        DoCastSpellOnPlayer(itr->GetSource(), spell, includePets, includeControlled);
}

void InstanceScript::DoCastSpellOnPlayer(Player* player, uint32 spell, bool includePets /*= false*/, bool includeControlled /*= false*/)
{
    if (!player)
        return;

    player->CastSpell(player, spell, true);

    if (!includePets)
        return;

    for (uint8 itr2 = 0; itr2 < MAX_SUMMON_SLOT; ++itr2)
    {
        if (ObjectGuid summonGUID = player->m_SummonSlot[itr2])
            if (Creature* summon = instance->GetCreature(summonGUID))
                summon->CastSpell(player, spell, true);
    }

    if (!includeControlled)
        return;

    for (auto itr2 = player->m_Controlled.begin(); itr2 != player->m_Controlled.end(); ++itr2)
    {
        if (Unit* controlled = *itr2)
            if (controlled->IsInWorld() && controlled->GetTypeId() == TYPEID_UNIT)
                controlled->CastSpell(player, spell, true);
    }
}

bool InstanceScript::ServerAllowsTwoSideGroups()
{
    return sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GROUP);
}

bool InstanceScript::CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target*/ /*= nullptr*/, uint32 /*miscvalue1*/ /*= 0*/)
{
    TC_LOG_ERROR("misc", "Achievement system call InstanceScript::CheckAchievementCriteriaMeet but instance script for map {} not have implementation for achievement criteria {}",
        instance->GetId(), criteria_id);
    return false;
}

void InstanceScript::SendEncounterUnit(EncounterFrameType type, Unit const* unit /*= nullptr*/, uint8 param1 /*= 0*/, uint8 param2 /*= 0*/)
{
    // size of this packet is at most 15 (usually less)
    WorldPacket data(SMSG_UPDATE_INSTANCE_ENCOUNTER_UNIT, 15);
    data << uint32(type);

    switch (type)
    {
        case ENCOUNTER_FRAME_ENGAGE:
        case ENCOUNTER_FRAME_DISENGAGE:
        case ENCOUNTER_FRAME_UPDATE_PRIORITY:
            if (!unit)
                return;
            data << unit->GetPackGUID();
            data << uint8(param1);
            break;
        case ENCOUNTER_FRAME_ADD_TIMER:
        case ENCOUNTER_FRAME_ENABLE_OBJECTIVE:
        case ENCOUNTER_FRAME_DISABLE_OBJECTIVE:
            data << uint8(param1);
            break;
        case ENCOUNTER_FRAME_UPDATE_OBJECTIVE:
            data << uint8(param1);
            data << uint8(param2);
            break;
        case ENCOUNTER_FRAME_PHASE_SHIFT_CHANGED:
        default:
            break;
    }

    instance->SendToPlayers(&data);
}

void InstanceScript::UpdateEncounterState(EncounterCreditType type, uint32 creditEntry, Unit* /*source*/)
{
    DungeonEncounterList const* encounters = sObjectMgr->GetDungeonEncounterList(instance->GetId(), instance->GetDifficulty());
    if (!encounters)
        return;

    uint32 dungeonId = 0;

    for (auto const& encounter : *encounters)
    {
        if (encounter->creditType == type && encounter->creditEntry == creditEntry)
        {
            completedEncounters |= 1 << encounter->dbcEntry->Bit;
            if (encounter->lastEncounterDungeon)
            {
                dungeonId = encounter->lastEncounterDungeon;
                TC_LOG_DEBUG("lfg", "UpdateEncounterState: Instance {} (instanceId {}) completed encounter {}. Credit Dungeon: {}", instance->GetMapName(), instance->GetInstanceId(), encounter->dbcEntry->Name[0], dungeonId);
                break;
            }
        }
    }

    if (dungeonId)
    {
        Map::PlayerList const& players = instance->GetPlayers();
        for (auto const& ref : players)
        {
            if (Player* player = ref.GetSource())
            {
                if (Group* grp = player->GetGroup())
                {
                    if (grp->isLFGGroup())
                    {
                        sLFGMgr->FinishDungeon(grp->GetGUID(), dungeonId, instance);
                        return;
                    }
                }
            }
        }
    }
}

void InstanceScript::UpdateEncounterStateForKilledCreature(uint32 creatureId, Unit* source)
{
    UpdateEncounterState(ENCOUNTER_CREDIT_KILL_CREATURE, creatureId, source);
}

void InstanceScript::UpdateEncounterStateForSpellCast(uint32 spellId, Unit* source)
{
    UpdateEncounterState(ENCOUNTER_CREDIT_CAST_SPELL, spellId, source);
}

/*static*/ char const* InstanceScript::GetBossStateName(uint8 state)
{
    // See enum EncounterState in InstanceScript.h
    switch (state)
    {
        case NOT_STARTED:
            return "NOT_STARTED";
        case IN_PROGRESS:
            return "IN_PROGRESS";
        case FAIL:
            return "FAIL";
        case DONE:
            return "DONE";
        case SPECIAL:
            return "SPECIAL";
        case TO_BE_DECIDED:
            return "TO_BE_DECIDED";
        default:
            return "INVALID";
    }
}

bool InstanceHasScript(WorldObject const* obj, char const* scriptName)
{
    if (InstanceMap* instance = obj->GetMap()->ToInstanceMap())
        return instance->GetScriptName() == scriptName;

    return false;
}
