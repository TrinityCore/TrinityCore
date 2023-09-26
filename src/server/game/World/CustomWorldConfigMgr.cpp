/*
 * Copyright (C) since 2016 AtieshCore <https://at-wow.org/>
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

#include "CustomWorldConfigMgr.h"
#include "DatabaseEnv.h"
#include "GridDefines.h"
#include "ObjectDefines.h"
#include "ObjectMgr.h"
#include "Log.h"
#include "Player.h"
#include "World.h"
#include "StringConvert.h"

CustomWorldConfig* CustomWorldConfig::instance()
{
    static CustomWorldConfig instance;
    return &instance;
}

void CustomWorldConfig::AddCustomOption(CustomWorldConfigType type, uint32 IDinTypeGroup, std::string const& defaultValue, std::string const& value)
{
    switch (type)
    {
        case CustomWorldConfigType::GAME_CONFIG_TYPE_BOOL:
        {
            Optional<bool> boolValDefault = Trinity::StringTo<bool>(defaultValue);
            Optional<bool> boolVal = Trinity::StringTo<bool>(value);
            CustomAddBoolOption(IDinTypeGroup, value.empty() ? *boolValDefault : *boolVal);
            break;
        }
        case CustomWorldConfigType::GAME_CONFIG_TYPE_INT:
            CustomAddIntOption(IDinTypeGroup, value.empty() ? (uint32)std::stoi(defaultValue) : (uint32)std::stoi(value));
            break;
        case CustomWorldConfigType::GAME_CONFIG_TYPE_FLOAT:
            CustomAddFloatOption(IDinTypeGroup, value.empty() ? std::stof(defaultValue) : std::stof(value));
            break;
        case CustomWorldConfigType::GAME_CONFIG_TYPE_RATES:
            CustomAddRateOption(IDinTypeGroup, value.empty() ? std::stof(defaultValue) : std::stof(value));
            break;
        default:
            ABORT();
            break;
    }
}

void CustomWorldConfig::LoadCustom()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.PQuery("SELECT `OptionName`, `Type`, `IDInTypeGroup`, `DefaultValue`, `CustomValue` FROM world_custom_config");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 world custom config options. DB table `world_custom_config` is empty.");
        return;
    }

    uint32 count = 0;

    auto GetTypeString = [](std::string optionType) -> CustomWorldConfigType
    {
        if (optionType == "bool")
            return CustomWorldConfigType::GAME_CONFIG_TYPE_BOOL;
        else if (optionType == "int")
            return CustomWorldConfigType::GAME_CONFIG_TYPE_INT;
        else if (optionType == "float")
            return CustomWorldConfigType::GAME_CONFIG_TYPE_FLOAT;
        else if (optionType == "rate")
            return CustomWorldConfigType::GAME_CONFIG_TYPE_RATES;
        else
            return CustomWorldConfigType::GAME_CONFIG_TYPE_UNKNOWN;
    };

    do
    {
        Field* fields = result->Fetch();

        std::string const& optionName = fields[0].GetString();
        std::string const& optionType = fields[1].GetString();
        uint32 const& IDinTypeGroup = fields[2].GetUInt32();
        std::string const& defaultValue = fields[3].GetString();
        std::string const& customValue = fields[4].GetString();

        auto _type = GetTypeString(optionType);

        if (_type == CustomWorldConfigType::GAME_CONFIG_TYPE_UNKNOWN)
        {
            TC_LOG_ERROR("config", "> Don't support type ({}) for option ({})", optionType, optionName);
            continue;
        }

        AddCustomOption(_type, IDinTypeGroup, defaultValue, customValue);

        count++;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} World Custom Configs in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void CustomWorldConfig::CustomAddBoolOption(uint32 IDinTypeGroup, bool const& value)
{
    if (!sWorld->customSetBoolConfig(CustomWorldBoolConfigs(IDinTypeGroup), value))
    {
        TC_LOG_ERROR("config", "> Custom Bool option ({}) did not registered in core!", IDinTypeGroup);
        return;
    }
}

void CustomWorldConfig::CustomAddIntOption(uint32 IDinTypeGroup, uint32 const& value)
{
    if (!sWorld->customSetIntConfig(CustomWorldIntConfigs(IDinTypeGroup), value))
    {
        TC_LOG_ERROR("config", "> Custom Int option ({}) did not registered in core!", IDinTypeGroup);
        return;
    }
}

void CustomWorldConfig::CustomAddFloatOption(uint32 IDinTypeGroup, float const& value)
{
    if (!sWorld->customSetFloatConfig(CustomWorldFloatConfigs(IDinTypeGroup), value))
    {
        TC_LOG_ERROR("config", "> Custom Float option ({}) did not registered in core!", IDinTypeGroup);
        return;
    }
}

void CustomWorldConfig::CustomAddRateOption(uint32 IDinTypeGroup, float const& value)
{
    if (!sWorld->customSetRate(CustomRates(IDinTypeGroup), value))
    {
        TC_LOG_ERROR("config", "> Custom Rate option ({}) did not registered in core!", IDinTypeGroup);
        return;
    }
}
