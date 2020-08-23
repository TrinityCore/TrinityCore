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

#ifndef _GAME_CONFIG_H
#define _GAME_CONFIG_H

#include "Common.h"
#include <unordered_map>

enum class GameConfigType : uint8
{
    GAME_CONFIG_TYPE_BOOL,
    GAME_CONFIG_TYPE_INT,
    GAME_CONFIG_TYPE_FLOAT,
    GAME_CONFIG_TYPE_STRING,

    GAME_CONFIG_TYPE_UNKNOWN
};

class TC_GAME_API GameConfig
{
public:
    static GameConfig* instance();

    void Load();

    // Get config options
    bool GetBoolConfig(std::string const& optionName);
    int32 GetIntConfig(std::string const& optionName);
    float GetFloatConfig(std::string const& optionName);
    std::string GetStringConfig(std::string const& optionName);

private:
    // Add config options
    void AddOption(std::string const& optionName, GameConfigType type, std::string const& value, std::string const& defaultValue);

    void AddBoolOption(std::string const& optionName, bool value = false);
    void AddIntOption(std::string const& optionName, int32 value = 0);
    void AddFloatOption(std::string const& optionName, float value = 1.0f);
    void AddStringOption(std::string const& optionName, std::string const& value = "");

    void CleanAll();

    std::unordered_map<std::string, bool> _boolOptions;
    std::unordered_map<std::string, int32> _intOptions;
    std::unordered_map<std::string, float> _floatOptions;
    std::unordered_map<std::string, std::string> _stringOptions;
};

#define sGameConfig GameConfig::instance()

#endif // _GAME_CONFIG_H
