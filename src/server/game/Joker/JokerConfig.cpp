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
    Enable = GetIntDefault("Enable", 0);

    ThreatMod = GetFloatDefault("ThreatMod", 1.0f);

    AttackMod_Max_Normal = GetFloatDefault("AttackMod_Max_Normal", 2.0f);
    AttackMod_Min_Normal = GetFloatDefault("AttackMod_Min_Normal", 1.0f);
    AttackMod_Level_Normal = GetFloatDefault("AttackMod_Level_Normal", 1.0f);

    AttackMod_Max_Elite = GetFloatDefault("AttackMod_Max_Elite", 5.0f);
    AttackMod_Min_Elite = GetFloatDefault("AttackMod_Min_Elite", 2.0f);
    AttackMod_Level_Elite = GetFloatDefault("AttackMod_Level_Elite", 1.0f);

    AttackMod_Max_UniqueElite = GetFloatDefault("AttackMod_Max_UniqueElite", 6.0f);
    AttackMod_Min_UniqueElite = GetFloatDefault("AttackMod_Min_UniqueElite", 2.5f);
    AttackMod_Level_UniqueElite = GetFloatDefault("AttackMod_Level_UniqueElite", 1.0f);

    AttackMod_Max_RaidElite = GetFloatDefault("AttackMod_Max_RaidElite", 1.0f);
    AttackMod_Min_RaidElite = GetFloatDefault("AttackMod_Min_RaidElite", 1.0f);
    AttackMod_Level_RaidElite = GetFloatDefault("AttackMod_Level_RaidElite", 1000.0f);

    AttackMod_Max_InstanceEncounter = GetFloatDefault("AttackMod_Max_InstanceEncounter", 10.0f);
    AttackMod_Min_InstanceEncounter = GetFloatDefault("AttackMod_Min_InstanceEncounter", 4.0f);
    AttackMod_Level_InstanceEncounter = GetFloatDefault("AttackMod_Level_InstanceEncounter", 1.0f);

    AttackMod_Max_Rare = GetFloatDefault("AttackMod_Max_Rare", 7.0f);
    AttackMod_Min_Rare = GetFloatDefault("AttackMod_Min_Rare", 3.0f);
    AttackMod_Level_Rare = GetFloatDefault("AttackMod_Level_Rare", 1.0f);

    AttackMod_Max_RareElite = GetFloatDefault("AttackMod_Max_RareElite", 9.0f);
    AttackMod_Min_RareElite = GetFloatDefault("AttackMod_Min_RareElite", 3.5f);
    AttackMod_Level_RareElite = GetFloatDefault("AttackMod_Level_RareElite", 1.0f);

    AttackMod_Max_WorldBoss = GetFloatDefault("AttackMod_Max_WorldBoss", 1.0f);
    AttackMod_Min_WorldBoss = GetFloatDefault("AttackMod_Min_WorldBoss", 1.0f);
    AttackMod_Level_WorldBoss = GetFloatDefault("AttackMod_Level_WorldBoss", 1000.0f);


    SpellMod_Max_Normal = GetFloatDefault("SpellMod_Max_Normal", 1.0f);
    SpellMod_Min_Normal = GetFloatDefault("SpellMod_Min_Normal", 1.0f);
    SpellMod_Level_Normal = GetFloatDefault("SpellMod_Level_Normal", 1.0f);

    SpellMod_Max_Elite = GetFloatDefault("SpellMod_Max_Elite", 1.0f);
    SpellMod_Min_Elite = GetFloatDefault("SpellMod_Min_Elite", 1.0f);
    SpellMod_Level_Elite = GetFloatDefault("SpellMod_Level_Elite", 1.0f);

    SpellMod_Max_UniqueElite = GetFloatDefault("SpellMod_Max_UniqueElite", 1.0f);
    SpellMod_Min_UniqueElite = GetFloatDefault("SpellMod_Min_UniqueElite", 1.0f);
    SpellMod_Level_UniqueElite = GetFloatDefault("SpellMod_Level_UniqueElite", 1.0f);

    SpellMod_Max_RaidElite = GetFloatDefault("SpellMod_Max_RaidElite", 1.0f);
    SpellMod_Min_RaidElite = GetFloatDefault("SpellMod_Min_RaidElite", 1.0f);
    SpellMod_Level_RaidElite = GetFloatDefault("SpellMod_Level_RaidElite", 1.0f);

    SpellMod_Max_InstanceEncounter = GetFloatDefault("SpellMod_Max_InstanceEncounter", 1.0f);
    SpellMod_Min_InstanceEncounter = GetFloatDefault("SpellMod_Min_InstanceEncounter", 1.0f);
    SpellMod_Level_InstanceEncounter = GetFloatDefault("SpellMod_Level_InstanceEncounter", 1.0f);

    SpellMod_Max_Rare = GetFloatDefault("SpellMod_Max_Rare", 1.0f);
    SpellMod_Min_Rare = GetFloatDefault("SpellMod_Min_Rare", 1.0f);
    SpellMod_Level_Rare = GetFloatDefault("SpellMod_Level_Rare", 1.0f);

    SpellMod_Max_RareElite = GetFloatDefault("SpellMod_Max_RareElite", 1.0f);
    SpellMod_Min_RareElite = GetFloatDefault("SpellMod_Min_RareElite", 1.0f);
    SpellMod_Level_RareElite = GetFloatDefault("SpellMod_Level_RareElite", 1.0f);

    SpellMod_Max_WorldBoss = GetFloatDefault("SpellMod_Max_WorldBoss", 1.0f);
    SpellMod_Min_WorldBoss = GetFloatDefault("SpellMod_Min_WorldBoss", 1.0f);
    SpellMod_Level_WorldBoss = GetFloatDefault("SpellMod_Level_WorldBoss", 1.0f);


    HPMod_Max_Normal = GetFloatDefault("HPMod_Max_Normal", 2.0f);
    HPMod_Min_Normal = GetFloatDefault("HPMod_Min_Normal", 1.0f);
    HPMod_Level_Normal = GetFloatDefault("HPMod_Level_Normal", 1.0f);

    HPMod_Max_Elite = GetFloatDefault("HPMod_Max_Elite", 6.0f);
    HPMod_Min_Elite = GetFloatDefault("HPMod_Min_Elite", 3.0f);
    HPMod_Level_Elite = GetFloatDefault("HPMod_Level_Elite", 1.0f);

    HPMod_Max_UniqueElite = GetFloatDefault("HPMod_Max_UniqueElite", 8.0f);
    HPMod_Min_UniqueElite = GetFloatDefault("HPMod_Min_UniqueElite", 4.0f);
    HPMod_Level_UniqueElite = GetFloatDefault("HPMod_Level_UniqueElite", 1.0f);

    HPMod_Max_RaidElite = GetFloatDefault("HPMod_Max_RaidElite", 1.0f);
    HPMod_Min_RaidElite = GetFloatDefault("HPMod_Min_RaidElite", 1.0f);
    HPMod_Level_RaidElite = GetFloatDefault("HPMod_Level_RaidElite", 1000.0f);

    HPMod_Max_InstanceEncounter = GetFloatDefault("HPMod_Max_InstanceEncounter", 25.0f);
    HPMod_Min_InstanceEncounter = GetFloatDefault("HPMod_Min_InstanceEncounter", 10.0f);
    HPMod_Level_InstanceEncounter = GetFloatDefault("HPMod_Level_InstanceEncounter", 5.0f);

    HPMod_Max_Rare = GetFloatDefault("HPMod_Max_Rare", 3.0f);
    HPMod_Min_Rare = GetFloatDefault("HPMod_Min_Rare", 1.0f);
    HPMod_Level_Rare = GetFloatDefault("HPMod_Level_Rare", 1.0f);

    HPMod_Max_RareElite = GetFloatDefault("HPMod_Max_RareElite", 5.0f);
    HPMod_Min_RareElite = GetFloatDefault("HPMod_Min_RareElite", 2.0f);
    HPMod_Level_RareElite = GetFloatDefault("HPMod_Level_RareElite", 1.0f);

    HPMod_Max_WorldBoss = GetFloatDefault("HPMod_Max_WorldBoss", 1.0f);
    HPMod_Min_WorldBoss = GetFloatDefault("HPMod_Min_WorldBoss", 1.0f);
    HPMod_Level_WorldBoss = GetFloatDefault("HPMod_Level_WorldBoss", 1000.0f);


    MPMod_Max_Normal = GetFloatDefault("MPMod_Max_Normal", 1.0f);
    MPMod_Min_Normal = GetFloatDefault("MPMod_Min_Normal", 1.0f);
    MPMod_Level_Normal = GetFloatDefault("MPMod_Level_Normal", 1000.0f);

    MPMod_Max_Elite = GetFloatDefault("MPMod_Max_Elite", 1.0f);
    MPMod_Min_Elite = GetFloatDefault("MPMod_Min_Elite", 1.0f);
    MPMod_Level_Elite = GetFloatDefault("MPMod_Level_Elite", 1000.0f);

    MPMod_Max_UniqueElite = GetFloatDefault("MPMod_Max_UniqueElite", 1.0f);
    MPMod_Min_UniqueElite = GetFloatDefault("MPMod_Min_UniqueElite", 1.0f);
    MPMod_Level_UniqueElite = GetFloatDefault("MPMod_Level_UniqueElite", 1000.0f);

    MPMod_Max_RaidElite = GetFloatDefault("MPMod_Max_RaidElite", 1.0f);
    MPMod_Min_RaidElite = GetFloatDefault("MPMod_Min_RaidElite", 1.0f);
    MPMod_Level_RaidElite = GetFloatDefault("MPMod_Level_RaidElite", 1000.0f);

    MPMod_Max_InstanceEncounter = GetFloatDefault("MPMod_Max_InstanceEncounter", 1.0f);
    MPMod_Min_InstanceEncounter = GetFloatDefault("MPMod_Min_InstanceEncounter", 1.0f);
    MPMod_Level_InstanceEncounter = GetFloatDefault("MPMod_Level_InstanceEncounter", 1000.0f);

    MPMod_Max_Rare = GetFloatDefault("MPMod_Max_Rare", 1.0f);
    MPMod_Min_Rare = GetFloatDefault("MPMod_Min_Rare", 1.0f);
    MPMod_Level_Rare = GetFloatDefault("MPMod_Level_Rare", 1000.0f);

    MPMod_Max_RareElite = GetFloatDefault("MPMod_Max_RareElite", 1.0f);
    MPMod_Min_RareElite = GetFloatDefault("MPMod_Min_RareElite", 1.0f);
    MPMod_Level_RareElite = GetFloatDefault("MPMod_Level_RareElite", 1000.0f);

    MPMod_Max_WorldBoss = GetFloatDefault("MPMod_Max_WorldBoss", 1.0f);
    MPMod_Min_WorldBoss = GetFloatDefault("MPMod_Min_WorldBoss", 1.0f);
    MPMod_Level_WorldBoss = GetFloatDefault("MPMod_Level_WorldBoss", 1000.0f);

    CreatureModException = GetStringDefault("CreatureModException", "");
    CreatureModExceptionSet.clear();
    std::string exceptions = TrimString(CreatureModException);
    std::vector<std::string> exceptionVector = SplitString(exceptions, " ", true);
    for (std::vector<std::string>::iterator exceptionIT = exceptionVector.begin(); exceptionIT != exceptionVector.end(); exceptionIT++)
    {
        std::string eachExceptionStr = *exceptionIT;
        uint32 eachEntry = atoi(eachExceptionStr.c_str());
        CreatureModExceptionSet.insert(eachEntry);
    }

    MaxModLevel = GetIntDefault("MaxModLevel", 60);

    MaxTrainerSpellLevel = GetIntDefault("MaxTrainerSpellLevel", 80);

    PlayerMod = GetFloatDefault("PlayerMod", 1);

    LootCountEachGroup_Normal = GetIntDefault("LootCountEachGroup_Normal", 1);
    LootCountEachGroup_InstanceEncounter = GetIntDefault("LootCountEachGroup_InstanceEncounter", 1);
    LootCountEachGroup_UniqueElite = GetIntDefault("LootCountEachGroup_UniqueElite", 1);
    LootCountEachGroup_Elite = GetIntDefault("LootCountEachGroup_Elite", 1);
    LootCountEachGroup_RareElite = GetIntDefault("LootCountEachGroup_RareElite", 1);
    LootCountEachGroup_WorldBoss = GetIntDefault("LootCountEachGroup_WorldBoss", 1);
    LootCountEachGroup_Rare = GetIntDefault("LootCountEachGroup_Rare", 1);

    ServerExpansion = GetIntDefault("ServerExpansion", 0);

    if (Enable == 0)
    {
        return false;
    }

    return true;
}

std::vector<std::string> JokerConfig::SplitString(std::string srcStr, std::string delimStr, bool repeatedCharIgnored)
{
    std::vector<std::string> resultStringVector;
    std::replace_if(srcStr.begin(), srcStr.end(), [&](const char& c) {if (delimStr.find(c) != std::string::npos) { return true; } else { return false; }}/*pred*/, delimStr.at(0));
    size_t pos = srcStr.find(delimStr.at(0));
    std::string addedString = "";
    while (pos != std::string::npos) {
        addedString = srcStr.substr(0, pos);
        if (!addedString.empty() || !repeatedCharIgnored) {
            resultStringVector.push_back(addedString);
        }
        srcStr.erase(srcStr.begin(), srcStr.begin() + pos + 1);
        pos = srcStr.find(delimStr.at(0));
    }
    addedString = srcStr;
    if (!addedString.empty() || !repeatedCharIgnored) {
        resultStringVector.push_back(addedString);
    }
    return resultStringVector;
}

std::string JokerConfig::TrimString(std::string srcStr)
{
    std::string result = srcStr;
    if (!result.empty())
    {
        result.erase(0, result.find_first_not_of(" "));
        result.erase(result.find_last_not_of(" ") + 1);
    }

    return result;
}
