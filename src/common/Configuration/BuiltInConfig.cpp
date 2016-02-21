/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "BuiltInConfig.h"
#include "Config.h"
#include "GitRevision.h"

template<typename Fn>
static std::string GetStringWithDefaultValueFromFunction(
    std::string const& key, Fn getter)
{
    std::string const value = sConfigMgr->GetStringDefault(key, "");
    return value.empty() ? getter() : value;
}

std::string BuiltInConfig::GetCMakeCommand()
{
    return GetStringWithDefaultValueFromFunction(
        "CMakeCommand", GitRevision::GetCMakeCommand);
}

std::string BuiltInConfig::GetBuildDirectory()
{
    return GetStringWithDefaultValueFromFunction(
        "BuildDirectory", GitRevision::GetBuildDirectory);
}

std::string BuiltInConfig::GetSourceDirectory()
{
    return GetStringWithDefaultValueFromFunction(
        "SourceDirectory", GitRevision::GetSourceDirectory);
}

std::string BuiltInConfig::GetMySQLExecutable()
{
    return GetStringWithDefaultValueFromFunction(
        "MySQLExecutable", GitRevision::GetMySQLExecutable);
}
