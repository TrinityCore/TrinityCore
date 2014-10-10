/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "ModuleManager.h"
#include "DatabaseEnv.h"

Battlenet::ModuleManager::~ModuleManager()
{
    for (auto const& m : _modules)
        delete m.second;
}

void Battlenet::ModuleManager::Load()
{
    QueryResult result = LoginDatabase.Query("SELECT `Hash`, `Name`, `Type`, `System`, `Data` FROM battlenet_modules");
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            ModuleInfo* module = new ModuleInfo();
            module->Type = fields[2].GetString();
            HexStrToByteArray(fields[0].GetString(), module->ModuleId);
            std::string data = fields[4].GetString();
            module->DataSize = data.length() / 2;
            if (module->DataSize)
            {
                module->Data = new uint8[data.length() / 2];
                HexStrToByteArray(data, module->Data);
            }

            _modules[{ fields[3].GetString(), fields[1].GetString() }] = module;
        } while (result->NextRow());
    }
}

Battlenet::ModuleInfo* Battlenet::ModuleManager::CreateModule(std::string const& os, std::string const& name) const
{
    ModuleKey key { os, name };
    ASSERT(_modules.count(key));

    return new ModuleInfo(*_modules.at(key));
}
