/*
 * This file is part of the KitronCore Project. See AUTHORS file for Copyright information
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

#include "Config.h"
#include "Log.h"

bool ConfigMgr::LoadInitial(std::string file, std::string& error)
{
    _filename = std::move(file);
    char *load_error;

    Config config = LoadConfig(_filename.c_str(), &load_error);
    if (load_error != nullptr) {
        error.append(load_error);
        delete load_error;

        return false;
    }

    auto oldConfig = _config;
    _config = config;
    Config_Free(oldConfig);

    return true;
}

ConfigMgr::~ConfigMgr()
{
    Config_Free(_config);
}

ConfigMgr* ConfigMgr::instance()
{
    static ConfigMgr instance;
    return &instance;
}

bool ConfigMgr::Reload(std::vector<std::string>& errors)
{
    std::string error;
    if (!LoadInitial(_filename, error))
        errors.push_back(std::move(error));

    return errors.empty();
}

std::string ConfigMgr::GetStringDefault(std::string const& name, const std::string& def) const
{
    const char *val = Config_GetStringDefault(&_config, name.c_str(), def.c_str());

    std::string str_val(val);
    str_val.erase(std::remove(str_val.begin(), str_val.end(), '"'), str_val.end());
    delete val;

    return str_val;
}

bool ConfigMgr::GetBoolDefault(std::string const& name, bool def) const
{
    return Config_GetBoolDefault(&_config, name.c_str(), def);
}

int ConfigMgr::GetIntDefault(std::string const& name, int def) const
{
    return Config_GetIntDefault(&_config, name.c_str(), def);
}

float ConfigMgr::GetFloatDefault(std::string const& name, float def) const
{
    return Config_GetFloatDefault(&_config, name.c_str(), def);
}

std::string const& ConfigMgr::GetFilename()
{
    return _filename;
}

std::vector<std::string> ConfigMgr::GetKeysByString(std::string const& name)
{
    std::vector<std::string> matchingKeys;
    auto name_cstr = name.c_str();

    const char* const* keys;
    auto length = Config_GetKeys(&_config, &keys);
    for (uintptr_t i = 0; i < length; ++i) {
        auto res = strcasestr(keys[i], name_cstr);
        if (res != nullptr && keys[i] - res == 0) {
            matchingKeys.emplace_back(res);
        }
    }

    delete keys;
    return matchingKeys;
}
