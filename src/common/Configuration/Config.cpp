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
#include <boost/filesystem/directory.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <algorithm>
#include <cstdlib>
#include <memory>
#include <mutex>

namespace bpt = boost::property_tree;
namespace fs  = boost::filesystem;

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

    // Converts ini keys to the environment variable key (upper snake case).
    // Example of conversions:
    //   SomeConfig => SOME_CONFIG
    //   myNestedConfig.opt1 => MY_NESTED_CONFIG_OPT_1
    //   LogDB.Opt.ClearTime => LOG_DB_OPT_CLEAR_TIME
    std::string IniKeyToEnvVarKey(std::string const& key)
    {
        std::string result;

        const char *str = key.c_str();
        size_t n = key.length();

        char curr;
        bool isEnd;
        bool nextIsUpper;
        bool currIsNumeric;
        bool nextIsNumeric;

        for (size_t i = 0; i < n; ++i)
        {
            curr = str[i];
            if (curr == ' ' || curr == '.' || curr == '-')
            {
                result += '_';
                continue;
            }

            isEnd = i == n - 1;
            if (!isEnd)
            {
                nextIsUpper = isupper(str[i + 1]);

                // handle "aB" to "A_B"
                if (!isupper(curr) && nextIsUpper)
                {
                    result += static_cast<char>(std::toupper(curr));
                    result += '_';
                    continue;
                }

                currIsNumeric = isNumeric(curr);
                nextIsNumeric = isNumeric(str[i + 1]);

                // handle "a1" to "a_1"
                if (!currIsNumeric && nextIsNumeric)
                {
                    result += static_cast<char>(std::toupper(curr));
                    result += '_';
                    continue;
                }

                // handle "1a" to "1_a"
                if (currIsNumeric && !nextIsNumeric)
                {
                    result += static_cast<char>(std::toupper(curr));
                    result += '_';
                    continue;
                }
            }

            result += static_cast<char>(std::toupper(curr));
        }
        return result;
    }

    Optional<std::string> EnvVarForIniKey(std::string const& key)
    {
        std::string envKey = "TC_" + IniKeyToEnvVarKey(key);
        char* val = std::getenv(envKey.c_str());
        if (!val)
            return std::nullopt;

        return std::string(val);
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

    std::lock_guard<std::mutex> lock(_configLock);

    for (bpt::ptree::value_type const& child : fullTree.begin()->second)
        _config.put_child(bpt::ptree::path_type(child.first, '/'), child.second);

    if (keepOnReload)
        _additonalFiles.emplace_back(std::move(file));

    return true;
}

bool ConfigMgr::LoadAdditionalDir(std::string const& dir, bool keepOnReload, std::vector<std::string>& loadedFiles, std::vector<std::string>& errors)
{
    fs::path dirPath = dir;
    if (!fs::exists(dirPath) || !fs::is_directory(dirPath))
        return true;

    for (fs::directory_entry const& f : fs::recursive_directory_iterator(dirPath))
    {
        if (!fs::is_regular_file(f))
            continue;

        fs::path configFile = fs::absolute(f);
        if (configFile.extension() != ".conf")
            continue;

        std::string fileName = configFile.generic_string();
        std::string error;
        if (LoadAdditionalFile(fileName, keepOnReload, error))
            loadedFiles.push_back(std::move(fileName));
        else
            errors.push_back(std::move(error));
    }

    return errors.empty();
}

std::vector<std::string> ConfigMgr::OverrideWithEnvVariablesIfAny()
{
    std::lock_guard<std::mutex> lock(_configLock);

    std::vector<std::string> overriddenKeys;

    for (bpt::ptree::value_type& itr: _config)
    {
        if (!itr.second.empty() || itr.first.empty())
            continue;

        Optional<std::string> envVar = EnvVarForIniKey(itr.first);
        if (!envVar)
            continue;

        itr.second = bpt::ptree(*envVar);

        overriddenKeys.push_back(itr.first);
    }

    return overriddenKeys;
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

    OverrideWithEnvVariablesIfAny();

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
        Optional<std::string> envVar = EnvVarForIniKey(name);
        if (envVar)
        {
            Optional<T> castedVar = Trinity::StringTo<T>(*envVar);
            if (!castedVar)
            {
                TC_LOG_ERROR("server.loading", "Bad value defined for name {} in environment variables, going to use default instead", name);
                return def;
            }

            if (!quiet)
                TC_LOG_WARN("server.loading", "Missing name {} in config file {}, recovered with environment '{}' value.", name, _filename, *envVar);

            return *castedVar;
        }
        else if (!quiet)
        {
            TC_LOG_WARN("server.loading", "Missing name {} in config file {}, add \"{} = {}\" to this file",
                name, _filename, name, def);
        }
    }
    catch (bpt::ptree_bad_data const&)
    {
        TC_LOG_ERROR("server.loading", "Bad value defined for name {} in config file {}, going to use {} instead",
            name, _filename, def);
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
        Optional<std::string> envVar = EnvVarForIniKey(name);
        if (envVar)
        {
            if (!quiet)
                TC_LOG_WARN("server.loading", "Missing name {} in config file {}, recovered with environment '{}' value.", name, _filename, *envVar);

            return *envVar;
        }
        else if (!quiet)
        {
            TC_LOG_WARN("server.loading", "Missing name {} in config file {}, add \"{} = {}\" to this file",
                name, _filename, name, def);
        }
    }
    catch (bpt::ptree_bad_data const&)
    {
        TC_LOG_ERROR("server.loading", "Bad value defined for name {} in config file {}, going to use {} instead",
            name, _filename, def);
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
        TC_LOG_ERROR("server.loading", "Bad value defined for name {} in config file {}, going to use '{}' instead",
            name, _filename, def ? "true" : "false");
        return def;
    }
}

int32 ConfigMgr::GetIntDefault(std::string const& name, int32 def, bool quiet) const
{
    return GetValueDefault(name, def, quiet);
}

int64 ConfigMgr::GetInt64Default(std::string const& name, int64 def, bool quiet) const
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
