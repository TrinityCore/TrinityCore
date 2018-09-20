/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef BUILT_IN_CONFIG_H
#define BUILT_IN_CONFIG_H

#include "Define.h"
#include <string>

/// Provides helper functions to access built-in values
/// which can be overwritten in config
namespace BuiltInConfig
{
    /// Returns the CMake command when any is specified in the config,
    /// returns the built-in path otherwise
    TC_COMMON_API std::string GetCMakeCommand();
    /// Returns the build directory path when any is specified in the config,
    /// returns the built-in one otherwise
    TC_COMMON_API std::string GetBuildDirectory();
    /// Returns the source directory path when any is specified in the config,
    /// returns the built-in one otherwise
    TC_COMMON_API std::string GetSourceDirectory();
    /// Returns the path to the mysql executable (`mysql`) when any is specified
    /// in the config, returns the built-in one otherwise
    TC_COMMON_API std::string GetMySQLExecutable();

} // namespace BuiltInConfig

#endif // BUILT_IN_CONFIG_H
