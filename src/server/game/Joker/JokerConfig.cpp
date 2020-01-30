#include "JokerConfig.h"
#include "Log.h"
#include "Util.h"
#include <boost/property_tree/ini_parser.hpp>
#include <algorithm>
#include <memory>
#include <mutex>

#include <boost/filesystem/operations.hpp>

#ifndef JOKER_CONFIG_FILE_NAME
# define JOKER_CONFIG_FILE_NAME  "joker.conf"
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

bool JokerConfig::LoadInitial(std::string const& file, std::vector<std::string> args,
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

JokerConfig* JokerConfig::instance()
{
    static JokerConfig instance;
    return &instance;
}

bool JokerConfig::Reload(std::string& error)
{
    return LoadInitial(_filename, std::move(_args), error);
}

template<class T>
T JokerConfig::GetValueDefault(std::string const& name, T def) const
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
std::string JokerConfig::GetValueDefault<std::string>(std::string const& name, std::string def) const
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

std::string JokerConfig::GetStringDefault(std::string const& name, const std::string& def) const
{
    std::string val = GetValueDefault(name, def);
    val.erase(std::remove(val.begin(), val.end(), '"'), val.end());
    return val;
}

bool JokerConfig::GetBoolDefault(std::string const& name, bool def) const
{
    std::string val = GetValueDefault(name, std::string(def ? "1" : "0"));
    val.erase(std::remove(val.begin(), val.end(), '"'), val.end());
    return StringToBool(val);
}

int JokerConfig::GetIntDefault(std::string const& name, int def) const
{
    return GetValueDefault(name, def);
}

float JokerConfig::GetFloatDefault(std::string const& name, float def) const
{
    return GetValueDefault(name, def);
}

std::string const& JokerConfig::GetFilename()
{
    std::lock_guard<std::mutex> lock(_configLock);
    return _filename;
}

std::vector<std::string> const& JokerConfig::GetArguments() const
{
    return _args;
}

std::vector<std::string> JokerConfig::GetKeysByString(std::string const& name)
{
    std::lock_guard<std::mutex> lock(_configLock);

    std::vector<std::string> keys;

    for (bpt::ptree::value_type const& child : _config)
        if (child.first.compare(0, name.length(), name) == 0)
            keys.push_back(child.first);

    return keys;
}

bool JokerConfig::StartJokerSystem()
{
    auto configFile = fs::absolute(JOKER_CONFIG_FILE_NAME);
    std::string configError;
    LoadInitial(configFile.generic_string(), std::vector<std::string>(), configError);
    enable = GetIntDefault("Enable", 0);

    InstanceEncounterDamageMod_Warrior = GetFloatDefault("InstanceEncounterDamageMod_Warrior", 1);
    InstanceEncounterDamageMod_Paladin = GetFloatDefault("InstanceEncounterDamageMod_Paladin", 1);
    InstanceEncounterDamageMod_Mage = GetFloatDefault("InstanceEncounterDamageMod_Mage", 1);
    EliteDamageMod_Warrior = GetFloatDefault("EliteDamageMod_Warrior", 1);
    EliteDamageMod_Paladin = GetFloatDefault("EliteDamageMod_Paladin", 1);
    EliteDamageMod_Mage = GetFloatDefault("EliteDamageMod_Mage", 1);
    UniqueEliteDamageMod_Warrior = GetFloatDefault("UniqueEliteDamageMod_Warrior", 1);
    UniqueEliteDamageMod_Paladin = GetFloatDefault("UniqueEliteDamageMod_Paladin", 1);
    UniqueEliteDamageMod_Mage = GetFloatDefault("UniqueEliteDamageMod_Mage", 1);
    RareDamageMod_Warrior = GetFloatDefault("RareDamageMod_Warrior", 1);
    RareDamageMod_Paladin = GetFloatDefault("RareDamageMod_Paladin", 1);
    RareDamageMod_Mage = GetFloatDefault("RareDamageMod_Mage", 1);
    RareEliteDamageMod_Warrior = GetFloatDefault("RareEliteDamageMod_Warrior", 1);
    RareEliteDamageMod_Paladin = GetFloatDefault("RareEliteDamageMod_Paladin", 1);
    RareEliteDamageMod_Mage = GetFloatDefault("RareEliteDamageMod_Mage", 1);

    InstanceEncounterAPMod_Warrior = GetFloatDefault("InstanceEncounterAPMod_Warrior", 1);
    InstanceEncounterAPMod_Paladin = GetFloatDefault("InstanceEncounterAPMod_Paladin", 1);
    InstanceEncounterAPMod_Mage = GetFloatDefault("InstanceEncounterAPMod_Mage", 1);
    EliteAPMod_Warrior = GetFloatDefault("EliteAPMod_Warrior", 1);
    EliteAPMod_Paladin = GetFloatDefault("EliteAPMod_Paladin", 1);
    EliteAPMod_Mage = GetFloatDefault("EliteAPMod_Mage", 1);
    UniqueEliteAPMod_Warrior = GetFloatDefault("UniqueEliteAPMod_Warrior", 1);
    UniqueEliteAPMod_Paladin = GetFloatDefault("UniqueEliteAPMod_Paladin", 1);
    UniqueEliteAPMod_Mage = GetFloatDefault("UniqueEliteAPMod_Mage", 1);
    RareAPMod_Warrior = GetFloatDefault("RareAPMod_Warrior", 1);
    RareAPMod_Paladin = GetFloatDefault("RareAPMod_Paladin", 1);
    RareAPMod_Mage = GetFloatDefault("RareAPMod_Mage", 1);
    RareEliteAPMod_Warrior = GetFloatDefault("RareEliteAPMod_Warrior", 1);
    RareEliteAPMod_Paladin = GetFloatDefault("RareEliteAPMod_Paladin", 1);
    RareEliteAPMod_Mage = GetFloatDefault("RareEliteAPMod_Mage", 1);

    if (enable == 0)
    {
        return false;
    }
}
