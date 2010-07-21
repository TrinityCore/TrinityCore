/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "ProgressBar.h"
#include "SpellMgr.h"
#include "DisableMgr.h"

DisableMgr::DisableMgr()
{
}

DisableMgr::~DisableMgr()
{
    for (DisableMap::iterator itr = m_DisableMap.begin(); itr != m_DisableMap.end(); ++itr)
        itr->second.clear();
    m_DisableMap.clear();
}

void DisableMgr::LoadDisables()
{
    // reload case
    for (DisableMap::iterator itr = m_DisableMap.begin(); itr != m_DisableMap.end(); ++itr)
        itr->second.clear();
    m_DisableMap.clear();

    QueryResult_AutoPtr result = WorldDatabase.Query("SELECT sourceType,entry,flags FROM disables");

    uint32 total_count = 0;

    if (!result)
    {
        barGoLink bar(1);
        bar.step();

        sLog.outString();
        sLog.outString(">> Loaded %u disables", total_count);
        return;
    }

    barGoLink bar(result->GetRowCount());

    Field* fields;
    do
    {
        bar.step();
        fields = result->Fetch();
        DisableType type = DisableType(fields[0].GetUInt32());
        if (type >= MAX_DISABLE_TYPES)
        {
            sLog.outErrorDb("Invalid type %u specified in `disables` table, skipped.", type);
            continue;
        }
        uint32 entry = fields[1].GetUInt32();
        uint8 flags = fields[2].GetUInt8();
        switch (type)
        {
            case DISABLE_TYPE_SPELL:
                if (!sSpellStore.LookupEntry(entry))
                {
                    sLog.outErrorDb("Spell entry %u from `disables` doesn't exist in dbc, skipped.", entry);
                    continue;
                }
                if (!flags || flags > 7)
                {
                    sLog.outErrorDb("Disable flags for spell %u are invalid, skipped.", entry);
                    continue;
                }
                break;
            // checked later
            case DISABLE_TYPE_QUEST:
                break;
            case DISABLE_TYPE_MAP:
            {
                MapEntry const* mapEntry = sMapStore.LookupEntry(entry);
                if (!mapEntry)
                {
                    sLog.outErrorDb("Map entry %u from `disables` doesn't exist in dbc, skipped.", entry);
                    continue;
                }
                bool isFlagInvalid = false;
                switch (mapEntry->map_type)
                {
                    case MAP_COMMON:
                        if (flags)
                            isFlagInvalid = true;
                        break;
                    case MAP_INSTANCE:
                    case MAP_RAID:
                        if (flags & DUNGEON_STATUSFLAG_HEROIC && !GetMapDifficultyData(entry, DUNGEON_DIFFICULTY_HEROIC))
                            isFlagInvalid = true;
                        else if (flags & RAID_STATUSFLAG_10MAN_HEROIC && !GetMapDifficultyData(entry, RAID_DIFFICULTY_10MAN_HEROIC))
                            isFlagInvalid = true;
                        else if (flags & RAID_STATUSFLAG_25MAN_HEROIC && !GetMapDifficultyData(entry, RAID_DIFFICULTY_25MAN_HEROIC))
                            isFlagInvalid = true;
                        break;
                    case MAP_BATTLEGROUND:
                    case MAP_ARENA:
                        sLog.outErrorDb("Battleground map specified to be disabled in map case, skipped.", entry);
                        continue;
                }
                if (isFlagInvalid)
                {
                    sLog.outErrorDb("Disable flags for map %u are invalid, skipped.", entry);
                    continue;
                }
                break;
            }
            case DISABLE_TYPE_BATTLEGROUND:
                if (!sBattlemasterListStore.LookupEntry(entry))
                {
                    sLog.outErrorDb("Battleground entry %u from `disables` doesn't exist in dbc, skipped.", entry);
                    continue;
                }
                if (flags)
                    sLog.outErrorDb("Disable flags specified for battleground %u, useless data.", entry);
                break;
            case DISABLE_TYPE_ACHIEVEMENT_CRITERIA:
                if (!sAchievementCriteriaStore.LookupEntry(entry))
                {
                    sLog.outErrorDb("Achievement Criteria entry %u from `disables` doesn't exist in dbc, skipped.", entry);
                    continue;
                }
                if (flags)
                    sLog.outErrorDb("Disable flags specified for Achievement Criteria %u, useless data.", entry);
                break;
        }
        m_DisableMap[type].insert(DisableTypeMap::value_type(entry, flags));
        ++total_count;
   } while (result->NextRow());

    sLog.outString();
    sLog.outString(">> Loaded %u disables.", total_count);
}

void DisableMgr::CheckQuestDisables()
{
    uint32 count = m_DisableMap[DISABLE_TYPE_QUEST].size();
    if (!count)
    {
        barGoLink bar(1);
        bar.step();
        sLog.outString();
        sLog.outString(">> Done.");
        return;
    }

    barGoLink bar(count);
    // check only quests, rest already done at startup
    for (DisableTypeMap::iterator itr = m_DisableMap[DISABLE_TYPE_QUEST].begin(); itr != m_DisableMap[DISABLE_TYPE_QUEST].end();)
    {
        bar.step();
        const uint32 entry = itr->first;
        if (!objmgr.GetQuestTemplate(entry))
        {
            sLog.outErrorDb("Quest entry %u from `disables` doesn't exist, skipped.", entry);
            m_DisableMap[DISABLE_TYPE_QUEST].erase(itr++);
            continue;
        }
        if (itr->second)
            sLog.outErrorDb("Disable flags specified for quest %u, useless data.", entry);
        ++itr;
    }

    sLog.outString();
    sLog.outString(">> Done.");
}

bool DisableMgr::IsDisabledFor(DisableType type, uint32 entry, Unit const* pUnit)
{
    assert(type < MAX_DISABLE_TYPES);
    if (m_DisableMap[type].empty())
        return false;

    DisableTypeMap::iterator itr = m_DisableMap[type].find(entry);
    if (itr == m_DisableMap[type].end())    // not disabled
        return false;

    switch (type)
    {
        case DISABLE_TYPE_SPELL:
        {
            uint8 flags = itr->second;
            if (flags & SPELL_DISABLE_PLAYER && pUnit->GetTypeId() == TYPEID_PLAYER)
                return true;
            else if (pUnit->GetTypeId() == TYPEID_UNIT)
            {
                if (pUnit->ToCreature()->isPet())
                {
                    if (flags & SPELL_DISABLE_PET)
                        return true;
                }
                else if (flags & SPELL_DISABLE_CREATURE)
                    return true;
            }
            return false;
        }
        case DISABLE_TYPE_MAP:
            if (!pUnit)
                return true;
            if (Player const* pPlayer = pUnit->ToPlayer())
            {
                MapEntry const* mapEntry = sMapStore.LookupEntry(entry);
                if (mapEntry->IsDungeon())
                {
                    uint8 disabledModes = itr->second;
                    switch(mapEntry->IsRaid() ? pPlayer->GetRaidDifficulty() : pPlayer->GetDungeonDifficulty())
                    {
                        case DUNGEON_DIFFICULTY_NORMAL:
                            return disabledModes & DUNGEON_STATUSFLAG_NORMAL;
                        case DUNGEON_DIFFICULTY_HEROIC:
                            return disabledModes & DUNGEON_STATUSFLAG_HEROIC;
                        case RAID_DIFFICULTY_10MAN_HEROIC:
                            return disabledModes & RAID_STATUSFLAG_10MAN_HEROIC;
                        case RAID_DIFFICULTY_25MAN_HEROIC:
                            return disabledModes & RAID_STATUSFLAG_25MAN_HEROIC;
                    }
                }
                else if (mapEntry->map_type == MAP_COMMON)
                    return true;
            }
            return false;
        case DISABLE_TYPE_QUEST:
            if (!pUnit)
                return true;
            if (Player const* pPlayer = pUnit->ToPlayer())
                if (pPlayer->isGameMaster())
                    return false;
            return true;
        case DISABLE_TYPE_BATTLEGROUND:
        case DISABLE_TYPE_ACHIEVEMENT_CRITERIA:
            return true;
        default:
            return false;
    }

    return false;
}
