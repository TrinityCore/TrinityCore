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

#ifndef LogCommon_h__
#define LogCommon_h__

enum LogLevel
{
    LOG_LEVEL_DISABLED                           = 0,
    LOG_LEVEL_TRACE                              = 1,
    LOG_LEVEL_DEBUG                              = 2,
    LOG_LEVEL_INFO                               = 3,
    LOG_LEVEL_WARN                               = 4,
    LOG_LEVEL_ERROR                              = 5,
    LOG_LEVEL_FATAL                              = 6,

    NUM_ENABLED_LOG_LEVELS                       = 6
};

enum AppenderType : uint8
{
    APPENDER_NONE,
    APPENDER_CONSOLE,
    APPENDER_FILE,
    APPENDER_DB
};

enum AppenderFlags
{
    APPENDER_FLAGS_NONE                          = 0x00,
    APPENDER_FLAGS_PREFIX_TIMESTAMP              = 0x01,
    APPENDER_FLAGS_PREFIX_LOGLEVEL               = 0x02,
    APPENDER_FLAGS_PREFIX_LOGFILTERTYPE          = 0x04,
    APPENDER_FLAGS_USE_TIMESTAMP                 = 0x08, // only used by FileAppender
    APPENDER_FLAGS_MAKE_FILE_BACKUP              = 0x10  // only used by FileAppender
};

#endif // LogCommon_h__
