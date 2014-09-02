/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <list>
#include <mutex>
#include <boost/property_tree/ptree.hpp>

class ConfigMgr
{
    ConfigMgr() { }
    ~ConfigMgr() { }

public:
    /// Method used only for loading main configuration files (authserver.conf and worldserver.conf)
    bool LoadInitial(std::string const& file, std::string& error);

    static ConfigMgr* instance()
    {
        static ConfigMgr instance;
        return &instance;
    }

    bool Reload(std::string& error);

    std::string GetStringDefault(std::string const& name, const std::string& def);
    bool GetBoolDefault(std::string const& name, bool def);
    int GetIntDefault(std::string const& name, int def);
    float GetFloatDefault(std::string const& name, float def);

    std::string const& GetFilename();
    std::list<std::string> GetKeysByString(std::string const& name);

private:
    std::string _filename;
    boost::property_tree::ptree _config;
    std::mutex _configLock;

    ConfigMgr(ConfigMgr const&);
    ConfigMgr& operator=(ConfigMgr const&);
};

#define sConfigMgr ConfigMgr::instance()

#endif
