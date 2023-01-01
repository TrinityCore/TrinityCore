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

#ifndef CONFIG_H
#define CONFIG_H

#include "Define.h"
#include <string>
#include <vector>

class TC_COMMON_API ConfigMgr
{
    ConfigMgr() = default;
    ConfigMgr(ConfigMgr const&) = delete;
    ConfigMgr& operator=(ConfigMgr const&) = delete;
    ~ConfigMgr() = default;

public:
    /// Method used only for loading main configuration files (bnetserver.conf and worldserver.conf)
    bool LoadInitial(std::string file, std::vector<std::string> args, std::string& error);
    bool LoadAdditionalFile(std::string file, bool keepOnReload, std::string& error);

    /// Overrides configuration with environment variables and returns overridden keys
    std::vector<std::string> OverrideWithEnvVariablesIfAny();

    static ConfigMgr* instance();

    bool Reload(std::vector<std::string>& errors);

    std::string GetStringDefault(std::string const& name, const std::string& def, bool quiet = false) const;
    bool GetBoolDefault(std::string const& name, bool def, bool quiet = false) const;
    int32 GetIntDefault(std::string const& name, int32 def, bool quiet = false) const;
    int64 GetInt64Default(std::string const& name, int64 def, bool quiet = false) const;
    float GetFloatDefault(std::string const& name, float def, bool quiet = false) const;

    std::string const& GetFilename();
    std::vector<std::string> const& GetArguments() const;
    std::vector<std::string> GetKeysByString(std::string const& name);

private:
    template<class T>
    T GetValueDefault(std::string const& name, T def, bool quiet) const;
};

#define sConfigMgr ConfigMgr::instance()

#endif
