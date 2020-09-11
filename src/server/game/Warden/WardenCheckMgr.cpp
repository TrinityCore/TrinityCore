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

#include "WardenCheckMgr.h"

#include "Common.h"
#include "DatabaseEnv.h"
#include "Errors.h"
#include "Log.h"
#include "Warden.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"

WardenCheckMgr::WardenCheckMgr() { }

void WardenCheckMgr::LoadWardenChecks()
{
    uint32 oldMSTime = getMSTime();

    // Check if Warden is enabled by config before loading anything
    if (!sWorld->getBoolConfig(CONFIG_WARDEN_ENABLED))
    {
        TC_LOG_INFO("warden", ">> Warden disabled, loading checks skipped.");
        return;
    }

    QueryResult result = WorldDatabase.Query("SELECT MAX(id) FROM warden_checks");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 Warden checks. DB table `warden_checks` is empty!");
        return;
    }

    Field* fields = result->Fetch();

    uint16 maxCheckId = fields[0].GetUInt16();

    _checks.resize(maxCheckId+1);

    //                                    0    1     2     3        4       5      6      7
    result = WorldDatabase.Query("SELECT id, type, data, result, address, length, str, comment FROM warden_checks ORDER BY id ASC");

    uint32 count = 0;
    do
    {
        fields = result->Fetch();

        uint16 const id  = fields[0].GetUInt16();
        WardenCheckType const type = static_cast<WardenCheckType>(fields[1].GetUInt8());
        WardenCheckCategory const category = GetWardenCheckCategory(type);

        if (category == NUM_CHECK_CATEGORIES)
        {
            TC_LOG_ERROR("sql.sql", "Warden check with id %u lists check type %u in `warden_checks`, which is not supported. Skipped.", id, type);
            continue;
        }

        if ((type == LUA_EVAL_CHECK) && (id > 9999))
        {
            TC_LOG_ERROR("sql.sql", "Warden Lua check with id %u found in `warden_checks`. Lua checks may have four-digit IDs at most. Skipped.", id);
            continue;
        }

        WardenCheck& wardenCheck = _checks[id];
        wardenCheck.CheckId = id;
        wardenCheck.Type = type;

        if (type == PAGE_CHECK_A || type == PAGE_CHECK_B || type == DRIVER_CHECK)
            wardenCheck.Data = fields[2].GetBinary();

        if (type == MPQ_CHECK || type == MEM_CHECK)
            _checkResults.emplace(id, fields[3].GetBinary());

        if (type == MEM_CHECK || type == PAGE_CHECK_A || type == PAGE_CHECK_B || type == PROC_CHECK)
            wardenCheck.Address = fields[4].GetUInt32();

        if (type == PAGE_CHECK_A || type == PAGE_CHECK_B || type == PROC_CHECK)
            wardenCheck.Length = fields[5].GetUInt8();

        // PROC_CHECK support missing
        if (type == MEM_CHECK || type == MPQ_CHECK || type == LUA_EVAL_CHECK || type == DRIVER_CHECK || type == MODULE_CHECK)
            wardenCheck.Str = fields[6].GetString();

        wardenCheck.Comment = fields[7].GetString();
        if (wardenCheck.Comment.empty())
            wardenCheck.Comment = "Undocumented Check";

        if (type == LUA_EVAL_CHECK)
        {
            if (wardenCheck.Str.size() > WARDEN_MAX_LUA_CHECK_LENGTH)
            {
                TC_LOG_ERROR("sql.sql", "Found over-long Lua check for Warden check with id %u in `warden_checks`. Max length is %u. Skipped.", id, WARDEN_MAX_LUA_CHECK_LENGTH);
                continue;
            }

            std::string str = fmt::sprintf("%04u", id);
            ASSERT(str.size() == 4);
            std::copy(str.begin(), str.end(), wardenCheck.IdStr.begin());
        }

        // initialize action with default action from config, this may be overridden later
        wardenCheck.Action = WardenActions(sWorld->getIntConfig(CONFIG_WARDEN_CLIENT_FAIL_ACTION));

        _pools[category].push_back(id);
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u warden checks in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void WardenCheckMgr::LoadWardenOverrides()
{
    uint32 oldMSTime = getMSTime();

    // Check if Warden is enabled by config before loading anything
    if (!sWorld->getBoolConfig(CONFIG_WARDEN_ENABLED))
    {
        TC_LOG_INFO("warden", ">> Warden disabled, loading check overrides skipped.");
        return;
    }

    //                                                      0        1
    QueryResult result = CharacterDatabase.Query("SELECT wardenId, action FROM warden_action");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 Warden action overrides. DB table `warden_action` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint16 checkId = fields[0].GetUInt16();
        uint8  action  = fields[1].GetUInt8();

        // Check if action value is in range (0-2, see WardenActions enum)
        if (action > WARDEN_ACTION_BAN)
            TC_LOG_ERROR("warden", "Warden check override action out of range (ID: %u, action: %u)", checkId, action);
        // Check if check actually exists before accessing the _checks vector
        else if (checkId >= _checks.size())
            TC_LOG_ERROR("warden", "Warden check action override for non-existing check (ID: %u, action: %u), skipped", checkId, action);
        else
        {
            _checks[checkId].Action = WardenActions(action);
            ++count;
        }
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u warden action overrides in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

WardenCheckMgr* WardenCheckMgr::instance()
{
    static WardenCheckMgr instance;
    return &instance;
}

WardenCheck const& WardenCheckMgr::GetCheckData(uint16 Id) const
{
    ASSERT(Id < _checks.size(), "Requested Warden data for invalid check ID %u", uint32(Id));
    return _checks[Id];
}

WardenCheckResult const& WardenCheckMgr::GetCheckResult(uint16 Id) const
{
    auto it = _checkResults.find(Id);
    ASSERT(it != _checkResults.end(), "Requested Warden result for invalid check ID %u", uint32(Id));
    return it->second;
}
