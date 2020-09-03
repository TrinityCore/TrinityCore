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

#include "DatabaseEnv.h"
#include "CustomConfig.h"
#include "Log.h"
#include "Timer.h"
#include "Util.h"
#include "StringConvert.h"

CustomConfig* CustomConfig::instance()
{
    static CustomConfig instance;
    return &instance;
}

void CustomConfig::CleanAll()
{
    _boolOptions.clear();
    _intOptions.clear();
    _floatOptions.clear();
    _stringOptions.clear();
}

void CustomConfig::AddBoolOption(std::string const& optionName, bool value /*= false*/)
{
    auto const& itr = _boolOptions.find(optionName);
    if (itr != _boolOptions.end())
    {
        TC_LOG_FATAL("server.loading", "> Bool option (%s) exists already!", optionName.c_str());
        return;
    }

    _boolOptions.insert(std::make_pair(optionName, value));
}

void CustomConfig::AddIntOption(std::string const& optionName, int32 value /*= 0*/)
{
    auto const& itr = _intOptions.find(optionName);
    if (itr != _intOptions.end())
    {
        TC_LOG_FATAL("server.loading", "> Int option (%s) exists already!", optionName.c_str());
        return;
    }

    _intOptions.insert(std::make_pair(optionName, value));
}

void CustomConfig::AddFloatOption(std::string const& optionName, float value /*= 1.0f*/)
{
    auto const& itr = _floatOptions.find(optionName);
    if (itr != _floatOptions.end())
    {
        TC_LOG_FATAL("server.loading", "> Float option (%s) exists already!", optionName.c_str());
        return;
    }

    _floatOptions.insert(std::make_pair(optionName, value));
}

void CustomConfig::AddStringOption(std::string const& optionName, std::string const& value /*= ""*/)
{
    auto const& itr = _stringOptions.find(optionName);
    if (itr != _stringOptions.end())
    {
        TC_LOG_FATAL("server.loading", "> Int option (%s) exists already!", optionName.c_str());
        return;
    }

    _stringOptions.insert(std::make_pair(optionName, value));
}

void CustomConfig::AddOption(std::string const& optionName, GameConfigType type, std::string const& value, std::string const& defaultValue)
{
    switch (type)
    {
    case GameConfigType::GAME_CONFIG_TYPE_BOOL:
        AddBoolOption(optionName, Trinity::StringTo<bool>(value.empty() ? defaultValue : value).value());
        break;
    case GameConfigType::GAME_CONFIG_TYPE_INT:
        AddIntOption(optionName, Trinity::StringTo<int32>(value.empty() ? defaultValue : value).value());
        break;
    case GameConfigType::GAME_CONFIG_TYPE_FLOAT:
        AddFloatOption(optionName, Trinity::StringTo<float>(value.empty() ? defaultValue : value).value());
        break;
    case GameConfigType::GAME_CONFIG_TYPE_STRING:
        AddStringOption(optionName, value.empty() ? defaultValue : value);
        break;
    default:
        TC_LOG_FATAL("server.loading", "> Invalid option type (%u) for option name (%s)", static_cast<uint8>(type), optionName.c_str());
        break;
    }
}

void CustomConfig::Load()
{
    CleanAll();

    uint32 oldMSTime = getMSTime();

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_CUSTOM_CONFIG);
    PreparedQueryResult result = WorldDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_WARN("server.loading", ">> Loaded 0 game config options. DB table `game_config` is empty.");
        return;
    }

    uint32 count = 0;

    auto GetTypeString = [](std::string optionType) -> GameConfigType
    {
        if (optionType == "bool")
            return GameConfigType::GAME_CONFIG_TYPE_BOOL;
        else if (optionType == "int")
            return GameConfigType::GAME_CONFIG_TYPE_INT;
        else if (optionType == "float")
            return GameConfigType::GAME_CONFIG_TYPE_FLOAT;
        else if (optionType == "string")
            return GameConfigType::GAME_CONFIG_TYPE_STRING;
        else
            return GameConfigType::GAME_CONFIG_TYPE_UNKNOWN;
    };

    do
    {
        Field* fields = result->Fetch();

        std::string const& optionName   = fields[0].GetString();
        std::string const& optionType   = fields[1].GetString();
        std::string const& defaultValue = fields[2].GetString();
        std::string const& customValue  = fields[3].GetString();

        auto _type = GetTypeString(optionType);

        if (_type == GameConfigType::GAME_CONFIG_TYPE_UNKNOWN)
        {
            TC_LOG_FATAL("server.loading", "> Don't support type (%s) for option (%s)", optionType.c_str(), optionName.c_str());
            continue;
        }

        AddOption(optionName, _type, customValue, defaultValue);

        count++;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u game config option in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

bool CustomConfig::GetBoolConfig(std::string const& optionName, bool defaultValue /*= false*/)
{
    auto const& itr = _boolOptions.find(optionName);
    if (itr == _boolOptions.end())
    {
        TC_LOG_FATAL("server.loading", "> Bool option (%s) not found!", optionName.c_str());
        return defaultValue;
    }

    return _boolOptions.at(optionName);
}

int32 CustomConfig::GetIntConfig(std::string const& optionName, int32 defaultValue /*= 0*/)
{
    auto const& itr = _intOptions.find(optionName);
    if (itr == _intOptions.end())
    {
        TC_LOG_FATAL("server.loading", "> Int option (%s) not found!", optionName.c_str());
        return defaultValue;
    }

    return _intOptions.at(optionName);
}

float CustomConfig::GetFloatConfig(std::string const& optionName, float defaultValue /*= 1.0f*/)
{
    auto const& itr = _floatOptions.find(optionName);
    if (itr == _floatOptions.end())
    {
        TC_LOG_FATAL("server.loading", "> Float option (%s) not found!", optionName.c_str());
        return defaultValue;
    }

    return _floatOptions.at(optionName);
}

std::string CustomConfig::GetStringConfig(std::string const& optionName, std::string const& defaultValue /*= ""*/)
{
    auto const& itr = _stringOptions.find(optionName);
    if (itr == _stringOptions.end())
    {
        TC_LOG_FATAL("server.loading", "> String option (%s) not found!", optionName.c_str());
        return defaultValue;
    }

    return _stringOptions.at(optionName);
}
