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

#include "Config.h"
#include "Log.h"
#include "StringConvert.h"
#include "Util.h"
#include <boost/property_tree/ini_parser.hpp>
#include <algorithm>
#include <memory>
#include <mutex>

namespace bpt = boost::property_tree;

namespace
{
    std::string _filename;
    std::vector<std::string> _additonalFiles;
    std::vector<std::string> _args;
    bpt::ptree _config;
    std::mutex _configLock;

    bool LoadFile(std::string const& file, bpt::ptree& fullTree, std::string& error)
    {
        try
        {
            bpt::ini_parser::read_ini(file, fullTree);

            if (fullTree.empty())
            {
                error = "empty file (" + file + ")";
                return false;
            }
        }
        catch (bpt::ini_parser::ini_parser_error const& e)
        {
            if (e.line() == 0)
                error = e.message() + " (" + e.filename() + ")";
            else
                error = e.message() + " (" + e.filename() + ":" + std::to_string(e.line()) + ")";
            return false;
        }

        return true;
    }
}

bool ConfigMgr::LoadInitial(std::string file, std::vector<std::string> args,
                            std::string& error)
{
    std::lock_guard<std::mutex> lock(_configLock);

    _filename = std::move(file);
    _args = std::move(args);

    bpt::ptree fullTree;
    if (!LoadFile(_filename, fullTree, error))
        return false;

    // Since we're using only one section per config file, we skip the section and have direct property access
    _config = fullTree.begin()->second;

    return true;
}

bool ConfigMgr::LoadAdditionalFile(std::string file, bool keepOnReload, std::string& error)
{
    bpt::ptree fullTree;
    if (!LoadFile(file, fullTree, error))
        return false;

    for (bpt::ptree::value_type const& child : fullTree.begin()->second)
        _config.put_child(bpt::ptree::path_type(child.first, '/'), child.second);

    if (keepOnReload)
        _additonalFiles.emplace_back(std::move(file));

    return true;
}

ConfigMgr* ConfigMgr::instance()
{
    static ConfigMgr instance;
    return &instance;
}

bool ConfigMgr::Reload(std::vector<std::string>& errors)
{
    std::string error;
    if (!LoadInitial(_filename, std::move(_args), error))
        errors.push_back(std::move(error));

    for (std::string const& additionalFile : _additonalFiles)
        if (!LoadAdditionalFile(additionalFile, false, error))
            errors.push_back(std::move(error));

    return errors.empty();
}

template<class T>
T ConfigMgr::GetValueDefault(std::string const& name, T def, bool quiet) const
{
    try
    {
        return _config.get<T>(bpt::ptree::path_type(name, '/'));
    }
    catch (bpt::ptree_bad_path const&)
    {
        if (!quiet)
        {
            TC_LOG_WARN("server.loading", "Missing name %s in config file %s, add \"%s = %s\" to this file",
                name.c_str(), _filename.c_str(), name.c_str(), std::to_string(def).c_str());
        }
    }
    catch (bpt::ptree_bad_data const&)
    {
        TC_LOG_ERROR("server.loading", "Bad value defined for name %s in config file %s, going to use %s instead",
            name.c_str(), _filename.c_str(), std::to_string(def).c_str());
    }

    return def;
}

template<>
std::string ConfigMgr::GetValueDefault<std::string>(std::string const& name, std::string def, bool quiet) const
{
    try
    {
        return _config.get<std::string>(bpt::ptree::path_type(name, '/'));
    }
    catch (bpt::ptree_bad_path const&)
    {
        if (!quiet)
        {
            TC_LOG_WARN("server.loading", "Missing name %s in config file %s, add \"%s = %s\" to this file",
                name.c_str(), _filename.c_str(), name.c_str(), def.c_str());
        }
    }
    catch (bpt::ptree_bad_data const&)
    {
        TC_LOG_ERROR("server.loading", "Bad value defined for name %s in config file %s, going to use %s instead",
            name.c_str(), _filename.c_str(), def.c_str());
    }

    return def;
}

std::string ConfigMgr::GetStringDefault(std::string const& name, const std::string& def, bool quiet) const
{
    std::string val = GetValueDefault(name, def, quiet);
    val.erase(std::remove(val.begin(), val.end(), '"'), val.end());
    return val;
}

bool ConfigMgr::GetBoolDefault(std::string const& name, bool def, bool quiet) const
{
    std::string val = GetValueDefault(name, std::string(def ? "1" : "0"), quiet);
    val.erase(std::remove(val.begin(), val.end(), '"'), val.end());
    Optional<bool> boolVal = Trinity::StringTo<bool>(val);
    if (boolVal)
        return *boolVal;
    else
    {
        TC_LOG_ERROR("server.loading", "Bad value defined for name %s in config file %s, going to use '%s' instead",
            name.c_str(), _filename.c_str(), def ? "true" : "false");
        return def;
    }
}

int ConfigMgr::GetIntDefault(std::string const& name, int def, bool quiet) const
{
    return GetValueDefault(name, def, quiet);
}

float ConfigMgr::GetFloatDefault(std::string const& name, float def, bool quiet) const
{
    return GetValueDefault(name, def, quiet);
}

std::string const& ConfigMgr::GetFilename()
{
    std::lock_guard<std::mutex> lock(_configLock);
    return _filename;
}

std::vector<std::string> const& ConfigMgr::GetArguments() const
{
    return _args;
}

std::vector<std::string> ConfigMgr::GetKeysByString(std::string const& name)
{
    std::lock_guard<std::mutex> lock(_configLock);

    std::vector<std::string> keys;

    for (bpt::ptree::value_type const& child : _config)
        if (child.first.compare(0, name.length(), name) == 0)
            keys.push_back(child.first);

    return keys;
}
