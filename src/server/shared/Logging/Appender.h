/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#ifndef APPENDER_H
#define APPENDER_H

#include "Define.h"
#include <time.h>
#include <string>
#include <map>

enum LogFilterType
{
    LOG_FILTER_GENERAL                           =  0,     // This one should only be used inside Log.cpp
    LOG_FILTER_UNITS                             =  1,     // Anything related to units that doesn't fit in other categories. ie. creature formations
    LOG_FILTER_PETS                              =  2,
    LOG_FILTER_VEHICLES                          =  3,
    LOG_FILTER_TSCR                              =  4,     // C++ AI, instance scripts, etc.
    LOG_FILTER_DATABASE_AI                       =  5,     // SmartAI, EventAI, Creature* * AI
    LOG_FILTER_MAPSCRIPTS                        =  6,
    LOG_FILTER_NETWORKIO                         =  7,
    LOG_FILTER_SPELLS_AURAS                      =  8,
    LOG_FILTER_ACHIEVEMENTSYS                    =  9,
    LOG_FILTER_CONDITIONSYS                      = 10,
    LOG_FILTER_POOLSYS                           = 11,
    LOG_FILTER_AUCTIONHOUSE                      = 12,
    LOG_FILTER_BATTLEGROUND                      = 13,
    LOG_FILTER_OUTDOORPVP                        = 14,
    LOG_FILTER_CHATSYS                           = 15,
    LOG_FILTER_LFG                               = 16,
    LOG_FILTER_MAPS                              = 17,
    LOG_FILTER_PLAYER                            = 18,     // Any player log that does not fit in other player filters
    LOG_FILTER_PLAYER_LOADING                    = 19,     // Debug output from Player::_Load functions
    LOG_FILTER_PLAYER_ITEMS                      = 20,
    LOG_FILTER_PLAYER_SKILLS                     = 21,
    LOG_FILTER_PLAYER_CHATLOG                    = 22,
    LOG_FILTER_LOOT                              = 23,
    LOG_FILTER_GUILD                             = 24,
    LOG_FILTER_TRANSPORTS                        = 25,
    LOG_FILTER_SQL                               = 26,
    LOG_FILTER_GMCOMMAND                         = 27,
    LOG_FILTER_REMOTECOMMAND                     = 28,
    LOG_FILTER_WARDEN                            = 29,
    LOG_FILTER_AUTHSERVER                        = 30,
    LOG_FILTER_WORLDSERVER                       = 31,
    LOG_FILTER_GAMEEVENTS                        = 32,
    LOG_FILTER_CALENDAR                          = 33,
    LOG_FILTER_CHARACTER                         = 34,
    LOG_FILTER_ARENAS                            = 35,
    LOG_FILTER_SQL_DRIVER                        = 36,
    LOG_FILTER_SQL_DEV                           = 37,
    LOG_FILTER_PLAYER_DUMP                       = 38,
    LOG_FILTER_BATTLEFIELD                       = 39,
    LOG_FILTER_SERVER_LOADING                    = 40,
    LOG_FILTER_OPCODES                           = 41,
    LOG_FILTER_SOAP                              = 42
};

const uint8 MaxLogFilter = 43;

// Values assigned have their equivalent in enum ACE_Log_Priority
enum LogLevel
{
    LOG_LEVEL_DISABLED                           = 0,
    LOG_LEVEL_TRACE                              = 1,
    LOG_LEVEL_DEBUG                              = 2,
    LOG_LEVEL_INFO                               = 3,
    LOG_LEVEL_WARN                               = 4,
    LOG_LEVEL_ERROR                              = 5,
    LOG_LEVEL_FATAL                              = 6
};

const uint8 MaxLogLevels = 6;

enum AppenderType
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

struct LogMessage
{
    LogMessage(LogLevel _level, LogFilterType _type, std::string _text)
        : level(_level)
        , type(_type)
        , text(_text)
    {
        mtime = time(NULL);
    }

    static std::string getTimeStr(time_t time);
    std::string getTimeStr();

    LogLevel level;
    LogFilterType type;
    std::string text;
    std::string prefix;
    std::string param1;
    time_t mtime;
};

class Appender
{
    public:
        Appender(uint8 _id, std::string const& name, AppenderType type = APPENDER_NONE, LogLevel level = LOG_LEVEL_DISABLED, AppenderFlags flags = APPENDER_FLAGS_NONE);
        virtual ~Appender();

        uint8 getId() const;
        std::string const& getName() const;
        AppenderType getType() const;
        LogLevel getLogLevel() const;
        AppenderFlags getFlags() const;

        void setLogLevel(LogLevel);
        void write(LogMessage& message);
        static const char* getLogLevelString(LogLevel level);
        static const char* getLogFilterTypeString(LogFilterType type);

    private:
        virtual void _write(LogMessage& /*message*/) = 0;

        uint8 id;
        std::string name;
        AppenderType type;
        LogLevel level;
        AppenderFlags flags;
};

typedef std::map<uint8, Appender*> AppenderMap;

#endif
