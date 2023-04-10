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

#ifndef APPENDER_H
#define APPENDER_H

#include "Define.h"
#include "LogCommon.h"
#include <stdexcept>
#include <string>
#include <vector>

struct LogMessage;

class TC_COMMON_API Appender
{
    public:
        Appender(uint8 _id, std::string const& name, LogLevel level = LOG_LEVEL_DISABLED, AppenderFlags flags = APPENDER_FLAGS_NONE);
        virtual ~Appender();

        uint8 getId() const;
        std::string const& getName() const;
        virtual AppenderType getType() const = 0;
        LogLevel getLogLevel() const;
        AppenderFlags getFlags() const;

        void setLogLevel(LogLevel);
        void write(LogMessage* message);
        static char const* getLogLevelString(LogLevel level);
        virtual void setRealmId(uint32 /*realmId*/) { }

    private:
        virtual void _write(LogMessage const* /*message*/) = 0;

        uint8 id;
        std::string name;
        LogLevel level;
        AppenderFlags flags;
};

class TC_COMMON_API InvalidAppenderArgsException : public std::length_error
{
public:
    explicit InvalidAppenderArgsException(std::string const& message) : std::length_error(message) { }
};

enum LogFilterType
{
    LOG_FILTER_GENERAL = 0,  //bnet world          // This one should only be used inside Log.cpp
    LOG_FILTER_UNITS = 1,  //world               // Anything related to units that doesn't fit in other categories. ie. creature formations
    LOG_FILTER_PETS = 2,  //world
    LOG_FILTER_VEHICLES = 3,  //world
    LOG_FILTER_TSCR = 4,  //world               // C++ AI, instance scripts, etc.
    LOG_FILTER_DATABASE_AI = 5,  //world               // SmartAI, Creature* * AI
    LOG_FILTER_MAPSCRIPTS = 6,  //world
    LOG_FILTER_NETWORKIO = 7,  //bnet world
    LOG_FILTER_SPELLS_AURAS = 8,  //world
    LOG_FILTER_ACHIEVEMENTSYS = 9,  //world
    LOG_FILTER_CONDITIONSYS = 10, //world
    LOG_FILTER_POOLSYS = 11, //world
    LOG_FILTER_AUCTIONHOUSE = 12, //world
    LOG_FILTER_BATTLEGROUND = 13, //world
    LOG_FILTER_OUTDOORPVP = 14, //world
    LOG_FILTER_CHATSYS = 15, //world
    LOG_FILTER_LFG = 16, //world
    LOG_FILTER_MAPS = 17, //world
    LOG_FILTER_PLAYER = 18, //world               // Any player log that does not fit in other player filters
    LOG_FILTER_PLAYER_LOADING = 19, //world               // Debug output from Player::_Load functions
    LOG_FILTER_PLAYER_ITEMS = 20, //world
    LOG_FILTER_PLAYER_SKILLS = 21, //world
    LOG_FILTER_PLAYER_CHATLOG = 22, //world
    LOG_FILTER_LOOT = 23, //world
    LOG_FILTER_GUILD = 24, //world
    LOG_FILTER_TRANSPORTS = 25, //world
    LOG_FILTER_SQL = 26, //bnet world
    LOG_FILTER_GMCOMMAND = 27, //world
    LOG_FILTER_REMOTECOMMAND = 28, //world
    LOG_FILTER_WARDEN = 29, //world
    LOG_FILTER_WORLDSERVER = 31, //world
    LOG_FILTER_GAMEEVENTS = 32, //world
    LOG_FILTER_CALENDAR = 33, //world
    LOG_FILTER_CHARACTER = 34, //world
    LOG_FILTER_SQL_DRIVER = 36, //bnet world
    LOG_FILTER_SQL_DEV = 37, //bnet world
    LOG_FILTER_PLAYER_DUMP = 38, //world
    LOG_FILTER_BATTLEFIELD = 39, //world
    LOG_FILTER_SERVER_LOADING = 40, //world
    LOG_FILTER_OPCODES = 41, //world
    LOG_FILTER_REALMLIST = 44, //bnet
    LOG_FILTER_BATTLENET = 45, //bnet
    LOG_FILTER_BNET_SESSION = 47, //bnet
    LOG_FILTER_PROC = 48, //world
    LOG_FILTER_DONATE = 50, //world
    LOG_FILTER_BATTLEPET = 51, //world
    LOG_FILTER_PROTOBUF = 52, //world
    LOG_FILTER_AREATRIGGER = 53, //world
    LOG_FILTER_GOLD = 54, //world
    LOG_FILTER_WORLD_QUEST = 55, //world
    LOG_FILTER_CHALLENGE = 56, //world
    LOG_FILTER_PATH_GENERATOR = 58, //world
    LOG_FILTER_MMAPS = 59, //world
    LOG_FILTER_VMAPS = 60, //world

    LOG_FILTER_MAX
};
#endif
