#include "RobotConfig.h"
#include "Log.h"
#include "Util.h"
#include <boost/property_tree/ini_parser.hpp>
#include <algorithm>
#include <memory>
#include <mutex>

#include <boost/filesystem/operations.hpp>

#ifndef ROBOT_CONFIG_FILE_NAME
# define ROBOT_CONFIG_FILE_NAME  "robot.conf"
#endif

namespace bpt = boost::property_tree;
namespace fs = boost::filesystem;

namespace
{
    std::string _filename;
    std::vector<std::string> _args;
    bpt::ptree _config;
    std::mutex _configLock;
}

bool RobotConfig::LoadInitial(std::string const& file, std::vector<std::string> args,
    std::string& error)
{
    std::lock_guard<std::mutex> lock(_configLock);

    _filename = file;
    _args = args;

    try
    {
        bpt::ptree fullTree;
        bpt::ini_parser::read_ini(file, fullTree);

        if (fullTree.empty())
        {
            error = "empty file (" + file + ")";
            return false;
        }

        // Since we're using only one section per config file, we skip the section and have direct property access
        _config = fullTree.begin()->second;
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

RobotConfig* RobotConfig::instance()
{
    static RobotConfig instance;
    return &instance;
}

bool RobotConfig::Reload(std::string& error)
{
    return LoadInitial(_filename, std::move(_args), error);
}

template<class T>
T RobotConfig::GetValueDefault(std::string const& name, T def) const
{
    try
    {
        return _config.get<T>(bpt::ptree::path_type(name, '/'));
    }
    catch (bpt::ptree_bad_path const&)
    {
        TC_LOG_WARN("server.loading", "Missing name %s in config file %s, add \"%s = %s\" to this file",
            name.c_str(), _filename.c_str(), name.c_str(), std::to_string(def).c_str());
    }
    catch (bpt::ptree_bad_data const&)
    {
        TC_LOG_ERROR("server.loading", "Bad value defined for name %s in config file %s, going to use %s instead",
            name.c_str(), _filename.c_str(), std::to_string(def).c_str());
    }

    return def;
}

template<>
std::string RobotConfig::GetValueDefault<std::string>(std::string const& name, std::string def) const
{
    try
    {
        return _config.get<std::string>(bpt::ptree::path_type(name, '/'));
    }
    catch (bpt::ptree_bad_path const&)
    {
        TC_LOG_WARN("server.loading", "Missing name %s in config file %s, add \"%s = %s\" to this file",
            name.c_str(), _filename.c_str(), name.c_str(), def.c_str());
    }
    catch (bpt::ptree_bad_data const&)
    {
        TC_LOG_ERROR("server.loading", "Bad value defined for name %s in config file %s, going to use %s instead",
            name.c_str(), _filename.c_str(), def.c_str());
    }

    return def;
}

std::string RobotConfig::GetStringDefault(std::string const& name, const std::string& def) const
{
    std::string val = GetValueDefault(name, def);
    val.erase(std::remove(val.begin(), val.end(), '"'), val.end());
    return val;
}

bool RobotConfig::GetBoolDefault(std::string const& name, bool def) const
{
    std::string val = GetValueDefault(name, std::string(def ? "1" : "0"));
    val.erase(std::remove(val.begin(), val.end(), '"'), val.end());
    return StringToBool(val);
}

int RobotConfig::GetIntDefault(std::string const& name, int def) const
{
    return GetValueDefault(name, def);
}

float RobotConfig::GetFloatDefault(std::string const& name, float def) const
{
    return GetValueDefault(name, def);
}

std::string const& RobotConfig::GetFilename()
{
    std::lock_guard<std::mutex> lock(_configLock);
    return _filename;
}

std::vector<std::string> const& RobotConfig::GetArguments() const
{
    return _args;
}

std::vector<std::string> RobotConfig::GetKeysByString(std::string const& name)
{
    std::lock_guard<std::mutex> lock(_configLock);

    std::vector<std::string> keys;

    for (bpt::ptree::value_type const& child : _config)
        if (child.first.compare(0, name.length(), name) == 0)
            keys.push_back(child.first);

    return keys;
}

bool RobotConfig::StartRobotSystem()
{
    auto configFile = fs::absolute(ROBOT_CONFIG_FILE_NAME);
    std::string configError;
    LoadInitial(configFile.generic_string(), std::vector<std::string>(), configError);

    Enable = GetIntDefault("Enable", 0);
    ResetRobots = GetIntDefault("ResetRobots", 0);
    AccountNamePrefix = GetStringDefault("AccountNamePrefix", "ROBOT");
    OnlineLevel = GetIntDefault("OnlineLevel", 0);
    CountEachLevel = GetIntDefault("CountEachLevel", 100);
    OnlineRobotLevelGap = GetIntDefault("OnlineRobotLevelGap", 3);
    OnlineMinDelay = GetIntDefault("OnlineMinDelay", 60000);
    OnlineMaxDelay = GetIntDefault("OnlineMaxDelay", 300000);
    GroupInterest = GetIntDefault("GroupInterest", 1);
    TeleportMinRange = GetFloatDefault("TeleportMinRange", 500.0f);
    TeleportMaxRange = GetFloatDefault("TeleportMaxRange", 5000.0f);
    DeathMinDelay = GetIntDefault("DeathMinDelay", 1800000);
    DeathMaxDelay = GetIntDefault("DeathMaxDelay", 3600000);
    SoloMinDelay = GetIntDefault("SoloMinDelay", 600000);
    SoloMaxDelay = GetIntDefault("SoloMaxDelay", 1200000);

    if (Enable == 0)
    {
        return false;
    }

    return true;
}
