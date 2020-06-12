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

#include "DisableMgr.h"
#include "CriteriaHandler.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "OutdoorPvP.h"
#include "Player.h"
#include "SpellMgr.h"
#include "VMapManager2.h"
#include "World.h"

namespace DisableMgr
{

char const* MapTypeNames[] =
{
    "World",
    "Dungeon",
    "Raid",
    "Battleground",
    "Arena",
    "Scenario"
};

namespace
{
    struct DisableData
    {
        uint8 flags;
        std::unordered_set<uint32> params[2];                   // params0, params1
    };

    // single disables here with optional data
    typedef std::unordered_map<uint32, DisableData> DisableTypeMap;

    std::array<DisableTypeMap, MAX_DISABLE_TYPES> m_DisableMap;
}

void LoadDisables()
{
    uint32 oldMSTime = getMSTime();

    // reload case
    for (std::size_t i = 0; i < m_DisableMap.size(); ++i)
        m_DisableMap[i].clear();

    QueryResult result = WorldDatabase.Query("SELECT sourceType, entry, flags, params_0, params_1 FROM disables");

    uint32 total_count = 0;

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 disables. DB table `disables` is empty!");
        return;
    }

    Field* fields;
    do
    {
        fields = result->Fetch();
        uint32 type = fields[0].GetUInt32();
        if (type >= MAX_DISABLE_TYPES)
        {
            TC_LOG_ERROR("sql.sql", "Invalid type %u specified in `disables` table, skipped.", type);
            continue;
        }

        uint32 entry = fields[1].GetUInt32();
        uint8 flags = fields[2].GetUInt8();
        std::string params_0 = fields[3].GetString();
        std::string params_1 = fields[4].GetString();

        DisableData data;
        data.flags = flags;

        switch (type)
        {
            case DISABLE_TYPE_SPELL:
                if (!(sSpellMgr->GetSpellInfo(entry, DIFFICULTY_NONE) || flags & SPELL_DISABLE_DEPRECATED_SPELL))
                {
                    TC_LOG_ERROR("sql.sql", "Spell entry %u from `disables` doesn't exist in dbc, skipped.", entry);
                    continue;
                }

                if (!flags || flags > MAX_SPELL_DISABLE_TYPE)
                {
                    TC_LOG_ERROR("sql.sql", "Disable flags for spell %u are invalid, skipped.", entry);
                    continue;
                }

                if (flags & SPELL_DISABLE_MAP)
                {
                    Tokenizer tokens(params_0, ',');
                    for (uint8 i = 0; i < tokens.size(); )
                        data.params[0].insert(atoi(tokens[i++]));
                }

                if (flags & SPELL_DISABLE_AREA)
                {
                    Tokenizer tokens(params_1, ',');
                    for (uint8 i = 0; i < tokens.size(); )
                        data.params[1].insert(atoi(tokens[i++]));
                }

                break;
            // checked later
            case DISABLE_TYPE_QUEST:
                break;
            case DISABLE_TYPE_MAP:
            case DISABLE_TYPE_LFG_MAP:
            {
                MapEntry const* mapEntry = sMapStore.LookupEntry(entry);
                if (!mapEntry)
                {
                    TC_LOG_ERROR("sql.sql", "Map entry %u from `disables` doesn't exist in dbc, skipped.", entry);
                    continue;
                }
                bool isFlagInvalid = false;
                switch (mapEntry->InstanceType)
                {
                    case MAP_COMMON:
                        if (flags)
                            isFlagInvalid = true;
                        break;
                    case MAP_INSTANCE:
                    case MAP_RAID:
                        if (flags & DUNGEON_STATUSFLAG_HEROIC && !sDB2Manager.GetMapDifficultyData(entry, DIFFICULTY_HEROIC))
                            flags -= DUNGEON_STATUSFLAG_HEROIC;
                        if (flags & RAID_STATUSFLAG_10MAN_HEROIC && !sDB2Manager.GetMapDifficultyData(entry, DIFFICULTY_10_HC))
                            flags -= RAID_STATUSFLAG_10MAN_HEROIC;
                        if (flags & RAID_STATUSFLAG_25MAN_HEROIC && !sDB2Manager.GetMapDifficultyData(entry, DIFFICULTY_25_HC))
                            flags -= RAID_STATUSFLAG_25MAN_HEROIC;
                        if (!flags)
                            isFlagInvalid = true;
                        break;
                    case MAP_BATTLEGROUND:
                    case MAP_ARENA:
                        TC_LOG_ERROR("sql.sql", "Battleground map %u specified to be disabled in map case, skipped.", entry);
                        continue;
                }
                if (isFlagInvalid)
                {
                    TC_LOG_ERROR("sql.sql", "Disable flags for map %u are invalid, skipped.", entry);
                    continue;
                }
                break;
            }
            case DISABLE_TYPE_BATTLEGROUND:
                if (!sBattlemasterListStore.LookupEntry(entry))
                {
                    TC_LOG_ERROR("sql.sql", "Battleground entry %u from `disables` doesn't exist in dbc, skipped.", entry);
                    continue;
                }
                if (flags)
                    TC_LOG_ERROR("sql.sql", "Disable flags specified for battleground %u, useless data.", entry);
                break;
            case DISABLE_TYPE_OUTDOORPVP:
                if (entry > MAX_OUTDOORPVP_TYPES)
                {
                    TC_LOG_ERROR("sql.sql", "OutdoorPvPTypes value %u from `disables` is invalid, skipped.", entry);
                    continue;
                }
                if (flags)
                    TC_LOG_ERROR("sql.sql", "Disable flags specified for outdoor PvP %u, useless data.", entry);
                break;
            case DISABLE_TYPE_CRITERIA:
                if (!sCriteriaStore.LookupEntry(entry))
                {
                    TC_LOG_ERROR("sql.sql", "Criteria entry %u from `disables` doesn't exist in dbc, skipped.", entry);
                    continue;
                }
                if (flags)
                    TC_LOG_ERROR("sql.sql", "Disable flags specified for Criteria %u, useless data.", entry);
                break;
            case DISABLE_TYPE_VMAP:
            {
                MapEntry const* mapEntry = sMapStore.LookupEntry(entry);
                if (!mapEntry)
                {
                    TC_LOG_ERROR("sql.sql", "Map entry %u from `disables` doesn't exist in dbc, skipped.", entry);
                    continue;
                }
                switch (mapEntry->InstanceType)
                {
                    case MAP_COMMON:
                        if (flags & VMAP::VMAP_DISABLE_AREAFLAG)
                            TC_LOG_INFO("misc", "Areaflag disabled for %s map %u.", MapTypeNames[mapEntry->InstanceType], entry);
                        if (flags & VMAP::VMAP_DISABLE_LIQUIDSTATUS)
                            TC_LOG_INFO("misc", "Liquid status disabled for %s map %u.", MapTypeNames[mapEntry->InstanceType], entry);
                        break;
                    case MAP_INSTANCE:
                    case MAP_RAID:
                    case MAP_BATTLEGROUND:
                    case MAP_ARENA:
                    case MAP_SCENARIO:
                        if (flags & VMAP::VMAP_DISABLE_HEIGHT)
                            TC_LOG_INFO("misc", "Height disabled for %s map %u.", MapTypeNames[mapEntry->InstanceType], entry);
                        if (flags & VMAP::VMAP_DISABLE_LOS)
                            TC_LOG_INFO("misc", "LoS disabled for %s map %u.", MapTypeNames[mapEntry->InstanceType], entry);
                        break;
                }
                break;
            }
            case DISABLE_TYPE_MMAP:
            {
                MapEntry const* mapEntry = sMapStore.LookupEntry(entry);
                if (!mapEntry)
                {
                    TC_LOG_ERROR("sql.sql", "Map entry %u from `disables` doesn't exist in dbc, skipped.", entry);
                    continue;
                }
                if (mapEntry->InstanceType <= MAP_SCENARIO)
                    TC_LOG_INFO("misc", "Pathfinding disabled for %s map %u.", MapTypeNames[mapEntry->InstanceType], entry);
                break;
            }
            default:
                break;
        }

        m_DisableMap[type][entry] = std::move(data);
        ++total_count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u disables in %u ms", total_count, GetMSTimeDiffToNow(oldMSTime));
}

void CheckQuestDisables()
{
    uint32 oldMSTime = getMSTime();

    std::size_t count = m_DisableMap[DISABLE_TYPE_QUEST].size();
    if (!count)
    {
        TC_LOG_INFO("server.loading", ">> Checked 0 quest disables.");
        return;
    }

    // check only quests, rest already done at startup
    for (auto itr = m_DisableMap[DISABLE_TYPE_QUEST].begin(); itr != m_DisableMap[DISABLE_TYPE_QUEST].end();)
    {
        uint32 entry = itr->first;
        if (!sObjectMgr->GetQuestTemplate(entry))
        {
            TC_LOG_ERROR("sql.sql", "Quest entry %u from `disables` doesn't exist, skipped.", entry);
            m_DisableMap[DISABLE_TYPE_QUEST].erase(itr++);
            continue;
        }
        if (itr->second.flags)
            TC_LOG_ERROR("sql.sql", "Disable flags specified for quest %u, useless data.", entry);
        ++itr;
    }

    TC_LOG_INFO("server.loading", ">> Checked " SZFMTD " quest disables in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

bool IsDisabledFor(DisableType type, uint32 entry, Unit const* unit, uint8 flags)
{
    ASSERT(type < MAX_DISABLE_TYPES);
    if (m_DisableMap[type].empty())
        return false;

    DisableTypeMap::iterator itr = m_DisableMap[type].find(entry);
    if (itr == m_DisableMap[type].end())    // not disabled
        return false;

    switch (type)
    {
        case DISABLE_TYPE_SPELL:
        {
            uint8 spellFlags = itr->second.flags;
            if (unit)
            {
                if ((spellFlags & SPELL_DISABLE_PLAYER && unit->GetTypeId() == TYPEID_PLAYER) ||
                    (unit->GetTypeId() == TYPEID_UNIT && ((unit->IsPet() && spellFlags & SPELL_DISABLE_PET) || spellFlags & SPELL_DISABLE_CREATURE)))
                {
                    if (spellFlags & SPELL_DISABLE_MAP)
                    {
                        std::unordered_set<uint32> const& mapIds = itr->second.params[0];
                        if (mapIds.find(unit->GetMapId()) != mapIds.end())
                            return true;                                        // Spell is disabled on current map

                        if (!(spellFlags & SPELL_DISABLE_AREA))
                            return false;                                       // Spell is disabled on another map, but not this one, return false

                        // Spell is disabled in an area, but not explicitly our current mapId. Continue processing.
                    }

                    if (spellFlags & SPELL_DISABLE_AREA)
                    {
                        std::unordered_set<uint32> const& areaIds = itr->second.params[1];
                        if (areaIds.find(unit->GetAreaId()) != areaIds.end())
                            return true;                                        // Spell is disabled in this area
                        return false;                                           // Spell is disabled in another area, but not this one, return false
                    }
                    else
                        return true;                                            // Spell disabled for all maps
                }

                return false;
            }
            else if (spellFlags & SPELL_DISABLE_DEPRECATED_SPELL)    // call not from spellcast
                return true;
            else if (flags & SPELL_DISABLE_LOS)
                return (spellFlags & SPELL_DISABLE_LOS) != 0;

            break;
        }
        case DISABLE_TYPE_MAP:
        case DISABLE_TYPE_LFG_MAP:
            if (Player const* player = unit->ToPlayer())
            {
                MapEntry const* mapEntry = sMapStore.LookupEntry(entry);
                if (mapEntry->IsDungeon())
                {
                    uint8 disabledModes = itr->second.flags;
                    Difficulty targetDifficulty = player->GetDifficultyID(mapEntry);
                    sDB2Manager.GetDownscaledMapDifficultyData(entry, targetDifficulty);
                    switch (targetDifficulty)
                    {
                        case DIFFICULTY_NORMAL:
                            return (disabledModes & DUNGEON_STATUSFLAG_NORMAL) != 0;
                        case DIFFICULTY_HEROIC:
                            return (disabledModes & DUNGEON_STATUSFLAG_HEROIC) != 0;
                        case DIFFICULTY_10_HC:
                            return (disabledModes & RAID_STATUSFLAG_10MAN_HEROIC) != 0;
                        case DIFFICULTY_25_HC:
                            return (disabledModes & RAID_STATUSFLAG_25MAN_HEROIC) != 0;
                        default:
                            return false;
                    }
                }
                else if (mapEntry->InstanceType == MAP_COMMON)
                    return true;
            }
            return false;
        case DISABLE_TYPE_QUEST:
            if (!unit)
                return true;
            if (Player const* player = unit->ToPlayer())
                if (player->IsGameMaster())
                    return false;
            return true;
        case DISABLE_TYPE_BATTLEGROUND:
        case DISABLE_TYPE_OUTDOORPVP:
        case DISABLE_TYPE_CRITERIA:
        case DISABLE_TYPE_MMAP:
            return true;
        case DISABLE_TYPE_VMAP:
           return (flags & itr->second.flags) != 0;
        default:
            break;
    }

    return false;
}

bool IsVMAPDisabledFor(uint32 entry, uint8 flags)
{
    return IsDisabledFor(DISABLE_TYPE_VMAP, entry, NULL, flags);
}

bool IsPathfindingEnabled(uint32 mapId)
{
    return sWorld->getBoolConfig(CONFIG_ENABLE_MMAPS)
        && !IsDisabledFor(DISABLE_TYPE_MMAP, mapId, NULL, MMAP_DISABLE_PATHFINDING);
}

} // Namespace
