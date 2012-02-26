/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "InstanceScript.h"
#include "DatabaseEnv.h"
#include "Map.h"
#include "Player.h"
#include "GameObject.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Log.h"
#include "LFGMgr.h"

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

void InstanceScript::HandleGameObject(uint64 GUID, bool open, GameObject* go)
{
    if (!go)
        go = instance->GetGameObject(GUID);
    if (go)
        go->SetGoState(open ? GO_STATE_ACTIVE : GO_STATE_READY);
    else
        sLog->outDebug(LOG_FILTER_TSCR, "TSCR: InstanceScript: HandleGameObject failed");
}

bool InstanceScript::IsEncounterInProgress() const
{
    for (std::vector<BossInfo>::const_iterator itr = bosses.begin(); itr != bosses.end(); ++itr)
        if (itr->state == IN_PROGRESS)
            return true;

    return false;
}

void InstanceScript::LoadMinionData(const MinionData* data)
{
    while (data->entry)
    {
        if (data->bossId < bosses.size())
            minions.insert(std::make_pair(data->entry, MinionInfo(&bosses[data->bossId])));

        ++data;
    }
    sLog->outDebug(LOG_FILTER_TSCR, "InstanceScript::LoadMinionData: " UI64FMTD " minions loaded.", uint64(minions.size()));
}

void InstanceScript::LoadDoorData(const DoorData* data)
{
    while (data->entry)
    {
        if (data->bossId < bosses.size())
            doors.insert(std::make_pair(data->entry, DoorInfo(&bosses[data->bossId], data->type, BoundaryType(data->boundary))));

        ++data;
    }
    sLog->outDebug(LOG_FILTER_TSCR, "InstanceScript::LoadDoorData: " UI64FMTD " doors loaded.", uint64(doors.size()));
}

void InstanceScript::UpdateMinionState(Creature* minion, EncounterState state)
{
    switch (state)
    {
        case NOT_STARTED:
            if (!minion->isAlive())
                minion->Respawn();
            else if (minion->isInCombat())
                minion->AI()->EnterEvadeMode();
            break;
        case IN_PROGRESS:
            if (!minion->isAlive())
                minion->Respawn();
            else if (!minion->getVictim())
                minion->AI()->DoZoneInCombat();
            break;
        default:
            break;
    }
}

void InstanceScript::UpdateDoorState(GameObject* door)
{
    DoorInfoMap::iterator lower = doors.lower_bound(door->GetEntry());
    DoorInfoMap::iterator upper = doors.upper_bound(door->GetEntry());
    if (lower == upper)
        return;

    bool open = true;
    for (DoorInfoMap::iterator itr = lower; itr != upper && open; ++itr)
    {
        switch (itr->second.type)
        {
            case DOOR_TYPE_ROOM:
                open = (itr->second.bossInfo->state != IN_PROGRESS);
                break;
            case DOOR_TYPE_PASSAGE:
                open = (itr->second.bossInfo->state == DONE);
                break;
            case DOOR_TYPE_SPAWN_HOLE:
                open = (itr->second.bossInfo->state == IN_PROGRESS);
                break;
            default:
                break;
        }
    }

    door->SetGoState(open ? GO_STATE_ACTIVE : GO_STATE_READY);
}

void InstanceScript::AddDoor(GameObject* door, bool add)
{
    DoorInfoMap::iterator lower = doors.lower_bound(door->GetEntry());
    DoorInfoMap::iterator upper = doors.upper_bound(door->GetEntry());
    if (lower == upper)
        return;

    for (DoorInfoMap::iterator itr = lower; itr != upper; ++itr)
    {
        DoorInfo const& data = itr->second;

        if (add)
        {
            data.bossInfo->door[data.type].insert(door);
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
            data.bossInfo->door[data.type].erase(door);
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
        itr->second.bossInfo->minion.insert(minion);
    else
        itr->second.bossInfo->minion.erase(minion);
}

bool InstanceScript::SetBossState(uint32 id, EncounterState state)
{
    if (id < bosses.size())
    {
        BossInfo* bossInfo = &bosses[id];
        if (bossInfo->state == TO_BE_DECIDED) // loading
        {
            bossInfo->state = state;
            //sLog->outError("Inialize boss %u state as %u.", id, (uint32)state);
            return false;
        }
        else
        {
            if (bossInfo->state == state)
                return false;

            if (state == DONE)
                for (MinionSet::iterator i = bossInfo->minion.begin(); i != bossInfo->minion.end(); ++i)
                    if ((*i)->isWorldBoss() && (*i)->isAlive())
                        return false;

            bossInfo->state = state;
            SaveToDB();
        }

        for (uint32 type = 0; type < MAX_DOOR_TYPES; ++type)
            for (DoorSet::iterator i = bossInfo->door[type].begin(); i != bossInfo->door[type].end(); ++i)
                UpdateDoorState(*i);

        for (MinionSet::iterator i = bossInfo->minion.begin(); i != bossInfo->minion.end(); ++i)
            UpdateMinionState(*i, state);

        return true;
    }
    return false;
}

std::string InstanceScript::LoadBossState(const char * data)
{
    if (!data)
        return NULL;
    std::istringstream loadStream(data);
    uint32 buff;
    uint32 bossId = 0;
    for (std::vector<BossInfo>::iterator i = bosses.begin(); i != bosses.end(); ++i, ++bossId)
    {
        loadStream >> buff;
        if (buff < TO_BE_DECIDED)
            SetBossState(bossId, (EncounterState)buff);
    }
    return loadStream.str();
}

std::string InstanceScript::GetBossSaveData()
{
    std::ostringstream saveStream;
    for (std::vector<BossInfo>::iterator i = bosses.begin(); i != bosses.end(); ++i)
        saveStream << (uint32)i->state << ' ';
    return saveStream.str();
}

void InstanceScript::DoUseDoorOrButton(uint64 uiGuid, uint32 uiWithRestoreTime, bool bUseAlternativeState)
{
    if (!uiGuid)
        return;

    GameObject* go = instance->GetGameObject(uiGuid);

    if (go)
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_DOOR || go->GetGoType() == GAMEOBJECT_TYPE_BUTTON)
        {
            if (go->getLootState() == GO_READY)
                go->UseDoorOrButton(uiWithRestoreTime, bUseAlternativeState);
            else if (go->getLootState() == GO_ACTIVATED)
                go->ResetDoorOrButton();
        }
        else
            sLog->outError("SD2: Script call DoUseDoorOrButton, but gameobject entry %u is type %u.", go->GetEntry(), go->GetGoType());
    }
}

void InstanceScript::DoRespawnGameObject(uint64 uiGuid, uint32 uiTimeToDespawn)
{
    if (GameObject* go = instance->GetGameObject(uiGuid))
    {
        //not expect any of these should ever be handled
        if (go->GetGoType() == GAMEOBJECT_TYPE_FISHINGNODE || go->GetGoType() == GAMEOBJECT_TYPE_DOOR ||
            go->GetGoType() == GAMEOBJECT_TYPE_BUTTON || go->GetGoType() == GAMEOBJECT_TYPE_TRAP)
            return;

        if (go->isSpawned())
            return;

        go->SetRespawnTime(uiTimeToDespawn);
    }
}

void InstanceScript::DoUpdateWorldState(uint32 uiStateId, uint32 uiStateData)
{
    Map::PlayerList const& lPlayers = instance->GetPlayers();

    if (!lPlayers.isEmpty())
    {
        for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
            if (Player* player = itr->getSource())
                player->SendUpdateWorldState(uiStateId, uiStateData);
    }
    else
        sLog->outDebug(LOG_FILTER_TSCR, "TSCR: DoUpdateWorldState attempt send data but no players in map.");
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
            if (Player* player = i->getSource())
                if (WorldSession* session = player->GetSession())
                    session->SendNotification("%s", buff);
    }
}

// Complete Achievement for all players in instance
void InstanceScript::DoCompleteAchievement(uint32 achievement)
{
    AchievementEntry const* pAE = GetAchievementStore()->LookupEntry(achievement);
    Map::PlayerList const &PlayerList = instance->GetPlayers();

    if (!pAE)
    {
        sLog->outError("TSCR: DoCompleteAchievement called for not existing achievement %u", achievement);
        return;
    }

    if (!PlayerList.isEmpty())
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (Player *pPlayer = i->getSource())
                pPlayer->CompletedAchievement(pAE);
}

// Update Achievement Criteria for all players in instance
void InstanceScript::DoUpdateAchievementCriteria(AchievementCriteriaTypes type, uint32 miscValue1 /*= 0*/, uint32 miscValue2 /*= 0*/, Unit* unit /*= NULL*/)
{
    Map::PlayerList const &PlayerList = instance->GetPlayers();

    if (!PlayerList.isEmpty())
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (Player* player = i->getSource())
                player->UpdateAchievementCriteria(type, miscValue1, miscValue2, unit);
}

// Start timed achievement for all players in instance
void InstanceScript::DoStartTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry)
{
    Map::PlayerList const &PlayerList = instance->GetPlayers();

    if (!PlayerList.isEmpty())
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (Player* player = i->getSource())
                player->GetAchievementMgr().StartTimedAchievement(type, entry);
}

// Stop timed achievement for all players in instance
void InstanceScript::DoStopTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry)
{
    Map::PlayerList const &PlayerList = instance->GetPlayers();

    if (!PlayerList.isEmpty())
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (Player* player = i->getSource())
                player->GetAchievementMgr().RemoveTimedAchievement(type, entry);
}

// Remove Auras due to Spell on all players in instance
void InstanceScript::DoRemoveAurasDueToSpellOnPlayers(uint32 spell)
{
    Map::PlayerList const& PlayerList = instance->GetPlayers();
    if (!PlayerList.isEmpty())
    {
        for (Map::PlayerList::const_iterator itr = PlayerList.begin(); itr != PlayerList.end(); ++itr)
        {
            if (Player* player = itr->getSource())
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
            if (Player* player = i->getSource())
                player->CastSpell(player, spell, true);
}

bool InstanceScript::CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target*/ /*= NULL*/, uint32 /*miscvalue1*/ /*= 0*/)
{
    sLog->outError("Achievement system call InstanceScript::CheckAchievementCriteriaMeet but instance script for map %u not have implementation for achievement criteria %u",
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
        case ENCOUNTER_FRAME_ADD:
        case ENCOUNTER_FRAME_REMOVE:
        case 2:
            data.append(unit->GetPackGUID());
            data << uint8(param1);
            break;
        case 3:
        case 4:
        case 6:
            data << uint8(param1);
            data << uint8(param2);
            break;
        case 5:
            data << uint8(param1);
            break;
        case 7:
        default:
            break;
    }

    instance->SendToPlayers(&data);
}

void InstanceScript::UpdateEncounterState(EncounterCreditType type, uint32 creditEntry, Unit* source)
{
    DungeonEncounterList const* encounters = sObjectMgr->GetDungeonEncounterList(instance->GetId(), instance->GetDifficulty());
    if (!encounters)
        return;

    for (DungeonEncounterList::const_iterator itr = encounters->begin(); itr != encounters->end(); ++itr)
    {
        if ((*itr)->creditType == type && (*itr)->creditEntry == creditEntry)
        {
            completedEncounters |= 1 << (*itr)->dbcEntry->encounterIndex;
            sLog->outDebug(LOG_FILTER_TSCR, "Instance %s (instanceId %u) completed encounter %s", instance->GetMapName(), instance->GetInstanceId(), (*itr)->dbcEntry->encounterName[0]);
            if (uint32 dungeonId = (*itr)->lastEncounterDungeon)
            {
                Map::PlayerList const& players = instance->GetPlayers();
                if (!players.isEmpty())
                    for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                        if (Player* player = i->getSource())
                            if (!source || player->IsAtGroupRewardDistance(source))
                                sLFGMgr->RewardDungeonDoneFor(dungeonId, player);
            }
            return;
        }
    }
}
