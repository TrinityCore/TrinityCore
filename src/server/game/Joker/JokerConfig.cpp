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

    NormalAttackMod_Total = GetFloatDefault("NormalAttackMod_Total", 1.0f);
    InstanceEncounterAttackMod_Total = GetFloatDefault("InstanceEncounterAttackMod_Total", 1.0f);
    EliteAttackMod_Total = GetFloatDefault("EliteAttackMod_Total", 1.0f);
    UniqueEliteAttackMod_Total = GetFloatDefault("UniqueEliteAttackMod_Total", 1.0f);
    RareAttackMod_Total = GetFloatDefault("RareAttackMod_Total", 1.0f);
    WorldBossAttackMod_Total = GetFloatDefault("WorldBossAttackMod_Total", 1.0f);
    RareEliteAttackMod_Total = GetFloatDefault("RareEliteAttackMod_Total", 1.0f);

    NormalSpellMod_Total = GetFloatDefault("NormalSpellMod_Total", 1.0f);
    InstanceEncounterSpellMod_Total = GetFloatDefault("InstanceEncounterSpellMod_Total", 1.0f);
    EliteSpellMod_Total = GetFloatDefault("EliteSpellMod_Total", 1.0f);
    UniqueEliteSpellMod_Total = GetFloatDefault("UniqueEliteSpellMod_Total", 1.0f);
    RareSpellMod_Total = GetFloatDefault("RareSpellMod_Total", 1.0f);
    WorldBossSpellMod_Total = GetFloatDefault("WorldBossSpellMod_Total", 1.0f);
    RareEliteSpellMod_Total = GetFloatDefault("RareEliteSpellMod_Total", 1.0f);

    NormalHPMod_Total = GetFloatDefault("NormalHPMod_Total", 1.0f);
    InstanceEncounterHPMod_Total = GetFloatDefault("InstanceEncounterHPMod_Total", 1.0f);
    EliteHPMod_Total = GetFloatDefault("EliteHPMod_Total", 1.0f);
    UniqueEliteHPMod_Total = GetFloatDefault("UniqueEliteHPMod_Total", 1.0f);
    RareHPMod_Total = GetFloatDefault("RareHPMod_Total", 1.0f);
    WorldBossHPMod_Total = GetFloatDefault("WorldBossHPMod_Total", 1.0f);
    RareEliteHPMod_Total = GetFloatDefault("RareEliteHPMod_Total", 1.0f);

    NormalMPMod_Total = GetFloatDefault("NormalMPMod_Total", 1.0f);
    InstanceEncounterMPMod_Total = GetFloatDefault("InstanceEncounterMPMod_Total", 1.0f);
    EliteMPMod_Total = GetFloatDefault("EliteMPMod_Total", 1.0f);
    UniqueEliteMPMod_Total = GetFloatDefault("UniqueEliteMPMod_Total", 1.0f);
    RareMPMod_Total = GetFloatDefault("RareMPMod_Total", 1.0f);
    WorldBossMPMod_Total = GetFloatDefault("WorldBossMPMod_Total", 1.0f);
    RareEliteMPMod_Total = GetFloatDefault("RareEliteMPMod_Total", 1.0f);

    PlayerHPMod_Total = GetFloatDefault("PlayerHPMod_Total", 1.0f);
    PlayerMPMod_Total = GetFloatDefault("PlayerMPMod_Total", 1.0f);

    NormalAttackMod_Level = GetFloatDefault("NormalAttackMod_Level", 1.0f);
    InstanceEncounterAttackMod_Level = GetFloatDefault("InstanceEncounterAttackMod_Level", 1.0f);
    EliteAttackMod_Level = GetFloatDefault("EliteAttackMod_Level", 1.0f);
    UniqueEliteAttackMod_Level = GetFloatDefault("UniqueEliteAttackMod_Level", 1.0f);
    RareAttackMod_Level = GetFloatDefault("RareAttackMod_Level", 1.0f);
    WorldBossAttackMod_Level = GetFloatDefault("WorldBossAttackMod_Level", 1.0f);
    RareEliteAttackMod_Level = GetFloatDefault("RareEliteAttackMod_Level", 1.0f);

    NormalSpellMod_Level = GetFloatDefault("NormalSpellMod_Level", 1.0f);
    InstanceEncounterSpellMod_Level = GetFloatDefault("InstanceEncounterSpellMod_Level", 1.0f);
    EliteSpellMod_Level = GetFloatDefault("EliteSpellMod_Level", 1.0f);
    UniqueEliteSpellMod_Level = GetFloatDefault("UniqueEliteSpellMod_Level", 1.0f);
    RareSpellMod_Level = GetFloatDefault("RareSpellMod_Level", 1.0f);
    WorldBossSpellMod_Level = GetFloatDefault("WorldBossSpellMod_Level", 1.0f);
    RareEliteSpellMod_Level = GetFloatDefault("RareEliteSpellMod_Level", 1.0f);

    NormalHPMod_Level = GetFloatDefault("NormalHPMod_Level", 1.0f);
    InstanceEncounterHPMod_Level = GetFloatDefault("InstanceEncounterHPMod_Level", 1.0f);
    EliteHPMod_Level = GetFloatDefault("EliteHPMod_Level", 1.0f);
    UniqueEliteHPMod_Level = GetFloatDefault("UniqueEliteHPMod_Level", 1.0f);
    RareHPMod_Level = GetFloatDefault("RareHPMod_Level", 1.0f);
    WorldBossHPMod_Level = GetFloatDefault("WorldBossHPMod_Level", 1.0f);
    RareEliteHPMod_Level = GetFloatDefault("RareEliteHPMod_Level", 1.0f);

    NormalMPMod_Level = GetFloatDefault("NormalMPMod_Level", 1.0f);
    InstanceEncounterMPMod_Level = GetFloatDefault("InstanceEncounterMPMod_Level", 1.0f);
    EliteMPMod_Level = GetFloatDefault("EliteMPMod_Level", 1.0f);
    UniqueEliteMPMod_Level = GetFloatDefault("UniqueEliteMPMod_Level", 1.0f);
    RareMPMod_Level = GetFloatDefault("RareMPMod_Level", 1.0f);
    WorldBossMPMod_Level = GetFloatDefault("WorldBossMPMod_Level", 1.0f);
    RareEliteMPMod_Level = GetFloatDefault("RareEliteMPMod_Level", 1.0f);

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

    PlayerHPMod_Level = GetFloatDefault("PlayerHPMod_Level", 1.0f);
    PlayerMPMod_Level = GetFloatDefault("PlayerMPMod_Level", 1.0f);

    MaxModLevel = GetIntDefault("MaxModLevel", 1);

    MaxTrainerSpellLevel = GetIntDefault("MaxTrainerSpellLevel", 80);

    LootCountEachGroup_Normal = GetIntDefault("LootCountEachGroup_Normal", 1);
    LootCountEachGroup_InstanceEncounter = GetIntDefault("LootCountEachGroup_InstanceEncounter", 1);    
    LootCountEachGroup_UniqueElite = GetIntDefault("LootCountEachGroup_UniqueElite", 1);
    LootCountEachGroup_Elite = GetIntDefault("LootCountEachGroup_Elite", 1);
    LootCountEachGroup_RareElite = GetIntDefault("LootCountEachGroup_RareElite", 1);
    LootCountEachGroup_WorldBoss = GetIntDefault("LootCountEachGroup_WorldBoss", 1);
    LootCountEachGroup_Rare = GetIntDefault("LootCountEachGroup_Rare", 1);


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
