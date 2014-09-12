/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "Creature.h"
#include "CreatureAI.h"
#include "DatabaseEnv.h"
#include "GameObject.h"
#include "Group.h"
#include "InstanceScript.h"
#include "LFGMgr.h"
#include "Log.h"
#include "Map.h"
#include "Player.h"
#include "Pet.h"
#include "WorldSession.h"
#include "Opcodes.h"

void InstanceScript::SaveToDB()
{
    std::string data = GetSaveData();
    if (data.empty())
        return;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_INSTANCE_DATA);
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

void InstanceScript::SetHeaders(std::string const& dataHeaders)
{
    for (char header : dataHeaders)
        if (isalpha(header))
            headers.push_back(header);
}

void InstanceScript::LoadMinionData(const MinionData* data)
{
    while (data->entry)
    {
        if (data->bossId < bosses.size())
            minions.insert(std::make_pair(data->entry, MinionInfo(&bosses[data->bossId])));

        ++data;
    }
    TC_LOG_DEBUG("scripts", "InstanceScript::LoadMinionData: " UI64FMTD " minions loaded.", uint64(minions.size()));
}

void InstanceScript::LoadDoorData(const DoorData* data)
{
    while (data->entry)
    {
        if (data->bossId < bosses.size())
            doors.insert(std::make_pair(data->entry, DoorInfo(&bosses[data->bossId], data->type, BoundaryType(data->boundary))));

        ++data;
    }
    TC_LOG_DEBUG("scripts", "InstanceScript::LoadDoorData: " UI64FMTD " doors loaded.", uint64(doors.size()));
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
            switch (data.boundary)
            {
                default:
                case BOUNDARY_NONE:
                    break;
                case BOUNDARY_N:
                case BOUNDARY_S:
                    data.bossInfo->boundary[data.boundary] = door->GetPositionX();
                    break;
                case BOUNDARY_E:
                case BOUNDARY_W:
                    data.bossInfo->boundary[data.boundary] = door->GetPositionY();
                    break;
                case BOUNDARY_NW:
                case BOUNDARY_SE:
                    data.bossInfo->boundary[data.boundary] = door->GetPositionX() + door->GetPositionY();
                    break;
                case BOUNDARY_NE:
                case BOUNDARY_SW:
                    data.bossInfo->boundary[data.boundary] = door->GetPositionX() - door->GetPositionY();
                    break;
            }
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
            //TC_LOG_ERROR("misc", "Inialize boss %u state as %u.", id, (uint32)state);
            return false;
        }
        else
        {
            if (bossInfo->state == state)
                return false;

            if (state == DONE)
                for (MinionSet::iterator i = bossInfo->minion.begin(); i != bossInfo->minion.end(); ++i)
                    if (Creature* minion = instance->GetCreature(*i))
                        if (minion->isWorldBoss() && minion->IsAlive())
                            return false;

            bossInfo->state = state;
            SaveToDB();
        }

        for (uint32 type = 0; type < MAX_DOOR_TYPES; ++type)
            for (DoorSet::iterator i = bossInfo->door[type].begin(); i != bossInfo->door[type].end(); ++i)
                if (GameObject* door = instance->GetGameObject(*i))
                    UpdateDoorState(door);

        for (MinionSet::iterator i = bossInfo->minion.begin(); i != bossInfo->minion.end(); ++i)
            if (Creature* minion = instance->GetCreature(*i))
                UpdateMinionState(minion, state);

        return true;
    }
    return false;
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
        if (buff == IN_PROGRESS || buff == SPECIAL)
            buff = NOT_STARTED;

        if (buff < TO_BE_DECIDED)
            SetBossState(bossId, EncounterState(buff));
    }
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

void InstanceScript::HandleGameObject(uint64 guid, bool open, GameObject* go /*= nullptr*/)
{
    if (!go)
        go = instance->GetGameObject(guid);
    if (go)
        go->SetGoState(open ? GO_STATE_ACTIVE : GO_STATE_READY);
    else
        TC_LOG_DEBUG("scripts", "InstanceScript: HandleGameObject failed");
}

void InstanceScript::DoUseDoorOrButton(uint64 guid, uint32 withRestoreTime /*= 0*/, bool useAlternativeState /*= false*/)
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
            TC_LOG_ERROR("scripts", "InstanceScript: DoUseDoorOrButton can't use gameobject entry %u, because type is %u.", go->GetEntry(), go->GetGoType());
    }
    else
        TC_LOG_DEBUG("scripts", "InstanceScript: HandleGameObject failed");
}

void InstanceScript::DoRespawnGameObject(uint64 guid, uint32 timeToDespawn /*= MINUTE*/)
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
                TC_LOG_ERROR("scripts", "InstanceScript: DoRespawnGameObject can't respawn gameobject entry %u, because type is %u.", go->GetEntry(), go->GetGoType());
                return;
            default:
                break;
        }

        if (go->isSpawned())
            return;

        go->SetRespawnTime(timeToDespawn);
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
void InstanceScript::DoUpdateAchievementCriteria(AchievementCriteriaTypes type, uint32 miscValue1 /*= 0*/, uint32 miscValue2 /*= 0*/, Unit* unit /*= NULL*/)
{
    Map::PlayerList const &PlayerList = instance->GetPlayers();

    if (!PlayerList.isEmpty())
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (Player* player = i->GetSource())
                player->UpdateAchievementCriteria(type, miscValue1, miscValue2, unit);
}

// Start timed achievement for all players in instance
void InstanceScript::DoStartTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry)
{
    Map::PlayerList const &PlayerList = instance->GetPlayers();

    if (!PlayerList.isEmpty())
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (Player* player = i->GetSource())
                player->StartTimedAchievement(type, entry);
}

// Stop timed achievement for all players in instance
void InstanceScript::DoStopTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry)
{
    Map::PlayerList const &PlayerList = instance->GetPlayers();

    if (!PlayerList.isEmpty())
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (Player* player = i->GetSource())
                player->RemoveTimedAchievement(type, entry);
}

// Remove Auras due to Spell on all players in instance
void InstanceScript::DoRemoveAurasDueToSpellOnPlayers(uint32 spell)
{
    Map::PlayerList const& PlayerList = instance->GetPlayers();
    if (!PlayerList.isEmpty())
    {
        for (Map::PlayerList::const_iterator itr = PlayerList.begin(); itr != PlayerList.end(); ++itr)
        {
            if (Player* player = itr->GetSource())
            {
                player->RemoveAurasDueToSpell(spell);
                if (Pet* pet = player->GetPet())
                    pet->RemoveAurasDueToSpell(spell);
            }
        }
    }
}

// Cast spell on all players in instance
void InstanceScript::DoCastSpellOnPlayers(uint32 spell)
{
    Map::PlayerList const &PlayerList = instance->GetPlayers();

    if (!PlayerList.isEmpty())
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (Player* player = i->GetSource())
                player->CastSpell(player, spell, true);
}

bool InstanceScript::CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target*/ /*= NULL*/, uint32 /*miscvalue1*/ /*= 0*/)
{
    TC_LOG_ERROR("misc", "Achievement system call InstanceScript::CheckAchievementCriteriaMeet but instance script for map %u not have implementation for achievement criteria %u",
        instance->GetId(), criteria_id);
    return false;
}

void InstanceScript::SendEncounterUnit(uint32 type, Unit* unit /*= NULL*/, uint8 param1 /*= 0*/, uint8 param2 /*= 0*/)
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
        case ENCOUNTER_FRAME_UNK7:
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

    for (DungeonEncounterList::const_iterator itr = encounters->begin(); itr != encounters->end(); ++itr)
    {
        DungeonEncounter const* encounter = *itr;
        if (encounter->creditType == type && encounter->creditEntry == creditEntry)
        {
            completedEncounters |= 1 << encounter->dbcEntry->encounterIndex;
            if (encounter->lastEncounterDungeon)
            {
                dungeonId = encounter->lastEncounterDungeon;
                TC_LOG_DEBUG("lfg", "UpdateEncounterState: Instance %s (instanceId %u) completed encounter %s. Credit Dungeon: %u", instance->GetMapName(), instance->GetInstanceId(), encounter->dbcEntry->encounterName[0], dungeonId);
                break;
            }
        }
    }

    if (dungeonId)
    {
        Map::PlayerList const& players = instance->GetPlayers();
        for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
        {
            if (Player* player = i->GetSource())
                if (Group* grp = player->GetGroup())
                    if (grp->isLFGGroup())
                    {
                        sLFGMgr->FinishDungeon(grp->GetGUID(), dungeonId);
                        return;
                    }
        }
    }
}
