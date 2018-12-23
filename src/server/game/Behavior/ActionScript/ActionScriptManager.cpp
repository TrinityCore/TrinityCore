/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "ActionScriptManager.h"
#include "DatabaseEnv.h"
#include "Duration.h"
#include "Log.h"

void ActionScriptManager::GlobalInit()
{
    TimePoint start = std::chrono::steady_clock::now();

    auto& i = _instance();
    assert(!i);
    i = std::make_unique<ActionScriptManager>();
    i->Init();

    uint32 ms = std::chrono::duration_cast<Milliseconds>(std::chrono::steady_clock::now() - start).count();
    TC_LOG_INFO("server.loading", ">> Loaded %u behavior scripts in %u ms", i->GetScriptCount(), ms);
}

void ActionScriptManager::Init()
{
    // @todo init the actual script data

    QueryResult result = WorldDatabase.Query("SELECT spawnType, entry, index, scriptId FROM actionscript_assign ORDER BY spawnType ASC, entry ASC, index DESC");
    do
    {
        Field* fields = result->Fetch();
        SpawnObjectType type = SpawnObjectType(fields[0].GetUInt8());
        uint32 templateId = fields[1].GetUInt32();
        uint32 index = fields[2].GetUInt32();
        uint32 scriptId = fields[3].GetUInt32();

        std::vector<Optional<uint32>>& data = _scriptsByTemplate[{type, templateId}];
        if (data.empty())
            data.resize(index + 1);
        data[index] = scriptId;
    } while (result->NextRow());
}
