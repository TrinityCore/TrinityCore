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

#ifndef CONFIG_H
#define CONFIG_H

#include "Define.h"
#include <string>
#include <vector>
#include "libenturion_shared.h"

class TC_COMMON_API ConfigMgr
{
    std::string _filename;
    Config _config;

    ConfigMgr() = default;
    ConfigMgr(ConfigMgr const&) = delete;
    ConfigMgr& operator=(ConfigMgr const&) = delete;
    ~ConfigMgr();

public:
    /// Method used only for loading main configuration files (authserver.conf and worldserver.conf)
    bool LoadInitial(std::string file, std::string& error);

    static ConfigMgr* instance();

    bool Reload(std::vector<std::string>& errors);

    std::string GetStringDefault(std::string const& name, const std::string& def) const;
    bool GetBoolDefault(std::string const& name, bool def) const;
    int GetIntDefault(std::string const& name, int def) const;
    float GetFloatDefault(std::string const& name, float def) const;

    std::string const& GetFilename();
    std::vector<std::string> GetKeysByString(std::string const& name);
};

#define sConfigMgr ConfigMgr::instance()

#endif
