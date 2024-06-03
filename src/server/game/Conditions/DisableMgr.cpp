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
#include "Map.h"
#include "ObjectMgr.h"
#include "OutdoorPvP.h"
#include "Player.h"
#include "SpellMgr.h"
#include "StringConvert.h"
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
        uint16 flags;
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
            TC_LOG_ERROR("sql.sql", "Invalid type {} specified in `disables` table, skipped.", type);
            continue;
        }

        uint32 entry = fields[1].GetUInt32();
        uint16 flags = fields[2].GetUInt16();
        std::string params_0 = fields[3].GetString();
        std::string params_1 = fields[4].GetString();

        DisableData data;
        data.flags = flags;

        switch (type)
        {
            case DISABLE_TYPE_SPELL:
                if (!(sSpellMgr->GetSpellInfo(entry, DIFFICULTY_NONE) || flags & SPELL_DISABLE_DEPRECATED_SPELL))
                {
                    TC_LOG_ERROR("sql.sql", "Spell entry {} from `disables` doesn't exist in dbc, skipped.", entry);
                    continue;
                }

                if (!flags || flags > MAX_SPELL_DISABLE_TYPE)
                {
                    TC_LOG_ERROR("sql.sql", "Disable flags for spell {} are invalid, skipped.", entry);
                    continue;
                }

                if (flags & SPELL_DISABLE_MAP)
                {
                    for (std::string_view mapStr : Trinity::Tokenize(params_0, ',', true))
                    {
                        if (Optional<uint32> mapId = Trinity::StringTo<uint32>(mapStr))
                            data.params[0].insert(*mapId);
                        else
                            TC_LOG_ERROR("sql.sql", "Disable map '{}' for spell {} is invalid, skipped.", mapStr, entry);
                    }
                }

                if (flags & SPELL_DISABLE_AREA)
                {
                    for (std::string_view areaStr : Trinity::Tokenize(params_1, ',', true))
                    {
                        if (Optional<uint32> areaId = Trinity::StringTo<uint32>(areaStr))
                            data.params[1].insert(*areaId);
                        else
                            TC_LOG_ERROR("sql.sql", "Disable area '{}' for spell {} is invalid, skipped.", areaStr, entry);
                    }
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
                    TC_LOG_ERROR("sql.sql", "Map entry {} from `disables` doesn't exist in dbc, skipped.", entry);
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
                        TC_LOG_ERROR("sql.sql", "Battleground map {} specified to be disabled in map case, skipped.", entry);
                        continue;
                }
                if (isFlagInvalid)
                {
                    TC_LOG_ERROR("sql.sql", "Disable flags for map {} are invalid, skipped.", entry);
                    continue;
                }
                break;
            }
            case DISABLE_TYPE_BATTLEGROUND:
                if (!sBattlemasterListStore.LookupEntry(entry))
                {
                    TC_LOG_ERROR("sql.sql", "Battleground entry {} from `disables` doesn't exist in dbc, skipped.", entry);
                    continue;
                }
                if (flags)
                    TC_LOG_ERROR("sql.sql", "Disable flags specified for battleground {}, useless data.", entry);
                break;
            case DISABLE_TYPE_OUTDOORPVP:
                if (entry > MAX_OUTDOORPVP_TYPES)
                {
                    TC_LOG_ERROR("sql.sql", "OutdoorPvPTypes value {} from `disables` is invalid, skipped.", entry);
                    continue;
                }
                if (flags)
                    TC_LOG_ERROR("sql.sql", "Disable flags specified for outdoor PvP {}, useless data.", entry);
                break;
            case DISABLE_TYPE_CRITERIA:
                if (!sCriteriaStore.LookupEntry(entry))
                {
                    TC_LOG_ERROR("sql.sql", "Criteria entry {} from `disables` doesn't exist in dbc, skipped.", entry);
                    continue;
                }
                if (flags)
                    TC_LOG_ERROR("sql.sql", "Disable flags specified for Criteria {}, useless data.", entry);
                break;
            case DISABLE_TYPE_VMAP:
            {
                MapEntry const* mapEntry = sMapStore.LookupEntry(entry);
                if (!mapEntry)
                {
                    TC_LOG_ERROR("sql.sql", "Map entry {} from `disables` doesn't exist in dbc, skipped.", entry);
                    continue;
                }
                switch (mapEntry->InstanceType)
                {
                    case MAP_COMMON:
                        if (flags & VMAP::VMAP_DISABLE_AREAFLAG)
                            TC_LOG_INFO("misc", "Areaflag disabled for {} map {}.", MapTypeNames[mapEntry->InstanceType], entry);
                        if (flags & VMAP::VMAP_DISABLE_LIQUIDSTATUS)
                            TC_LOG_INFO("misc", "Liquid status disabled for {} map {}.", MapTypeNames[mapEntry->InstanceType], entry);
                        break;
                    case MAP_INSTANCE:
                    case MAP_RAID:
                    case MAP_BATTLEGROUND:
                    case MAP_ARENA:
                    case MAP_SCENARIO:
                        if (flags & VMAP::VMAP_DISABLE_HEIGHT)
                            TC_LOG_INFO("misc", "Height disabled for {} map {}.", MapTypeNames[mapEntry->InstanceType], entry);
                        if (flags & VMAP::VMAP_DISABLE_LOS)
                            TC_LOG_INFO("misc", "LoS disabled for {} map {}.", MapTypeNames[mapEntry->InstanceType], entry);
                        break;
                }
                break;
            }
            case DISABLE_TYPE_MMAP:
            {
                MapEntry const* mapEntry = sMapStore.LookupEntry(entry);
                if (!mapEntry)
                {
                    TC_LOG_ERROR("sql.sql", "Map entry {} from `disables` doesn't exist in dbc, skipped.", entry);
                    continue;
                }
                if (mapEntry->InstanceType <= MAP_SCENARIO)
                    TC_LOG_INFO("misc", "Pathfinding disabled for {} map {}.", MapTypeNames[mapEntry->InstanceType], entry);
                break;
            }
            case DISABLE_TYPE_PHASE_AREA:
            {
                if (!sPhaseStore.LookupEntry(entry))
                {
                    TC_LOG_ERROR("sql.sql", "Phase entry {} from `disables` doesn't exist in dbc, skipped.", entry);
                    continue;
                }
                if (flags)
                    TC_LOG_ERROR("sql.sql", "Disable flags specified for phase {}, useless data.", entry);
                break;
            }
            default:
                break;
        }

        m_DisableMap[type][entry] = std::move(data);
        ++total_count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} disables in {} ms", total_count, GetMSTimeDiffToNow(oldMSTime));
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
            TC_LOG_ERROR("sql.sql", "Quest entry {} from `disables` doesn't exist, skipped.", entry);
            m_DisableMap[DISABLE_TYPE_QUEST].erase(itr++);
            continue;
        }
        if (itr->second.flags)
            TC_LOG_ERROR("sql.sql", "Disable flags specified for quest {}, useless data.", entry);
        ++itr;
    }

    TC_LOG_INFO("server.loading", ">> Checked {} quest disables in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

bool IsDisabledFor(DisableType type, uint32 entry, WorldObject const* ref, uint8 flags /*= 0*/)
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
            uint16 spellFlags = itr->second.flags;
            if (ref)
            {
                if ((ref->GetTypeId() == TYPEID_PLAYER && (spellFlags & SPELL_DISABLE_PLAYER)) ||
                    (ref->GetTypeId() == TYPEID_UNIT && ((spellFlags & SPELL_DISABLE_CREATURE) || (ref->ToUnit()->IsPet() && (spellFlags & SPELL_DISABLE_PET)))) ||
                    (ref->GetTypeId() == TYPEID_GAMEOBJECT && (spellFlags & SPELL_DISABLE_GAMEOBJECT)))
                {
                    if (spellFlags & (SPELL_DISABLE_ARENAS | SPELL_DISABLE_BATTLEGROUNDS))
                    {
                        if (Map const* map = ref->FindMap())
                        {
                            if (spellFlags & SPELL_DISABLE_ARENAS && map->IsBattleArena())
                                return true;                                    // Current map is Arena and this spell is disabled here

                            if (spellFlags & SPELL_DISABLE_BATTLEGROUNDS && map->IsBattleground())
                                return true;                                    // Current map is a Battleground and this spell is disabled here
                        }
                    }

                    if (spellFlags & SPELL_DISABLE_MAP)
                    {
                        std::unordered_set<uint32> const& mapIds = itr->second.params[0];
                        if (mapIds.find(ref->GetMapId()) != mapIds.end())
                            return true;                                        // Spell is disabled on current map

                        if (!(spellFlags & SPELL_DISABLE_AREA))
                            return false;                                       // Spell is disabled on another map, but not this one, return false

                        // Spell is disabled in an area, but not explicitly our current mapId. Continue processing.
                    }

                    if (spellFlags & SPELL_DISABLE_AREA)
                    {
                        std::unordered_set<uint32> const& areaIds = itr->second.params[1];
                        if (areaIds.find(ref->GetAreaId()) != areaIds.end())
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
            if (!ref)
                return true;
            if (Player const* player = ref->ToPlayer())
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
            return true;
        case DISABLE_TYPE_BATTLEGROUND:
        case DISABLE_TYPE_OUTDOORPVP:
        case DISABLE_TYPE_CRITERIA:
        case DISABLE_TYPE_MMAP:
        case DISABLE_TYPE_PHASE_AREA:
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
    return IsDisabledFor(DISABLE_TYPE_VMAP, entry, nullptr, flags);
}

bool IsPathfindingEnabled(uint32 mapId)
{
    return sWorld->getBoolConfig(CONFIG_ENABLE_MMAPS)
        && !IsDisabledFor(DISABLE_TYPE_MMAP, mapId, nullptr, MMAP_DISABLE_PATHFINDING);
}

} // Namespace
