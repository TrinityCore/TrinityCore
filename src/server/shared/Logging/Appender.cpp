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

#include "Appender.h"
#include "Common.h"

std::string LogMessage::getTimeStr(time_t time)
{
    tm* aTm = localtime(&time);
    char buf[20];
    snprintf(buf, 20, "%04d-%02d-%02d_%02d:%02d:%02d", aTm->tm_year+1900, aTm->tm_mon+1, aTm->tm_mday, aTm->tm_hour, aTm->tm_min, aTm->tm_sec);
    return std::string(buf);
}

std::string LogMessage::getTimeStr()
{
    return getTimeStr(mtime);
}

Appender::Appender(uint8 _id, std::string const& _name, AppenderType _type /* = APPENDER_NONE*/, LogLevel _level /* = LOG_LEVEL_DISABLED */, AppenderFlags _flags /* = APPENDER_FLAGS_NONE */):
id(_id), name(_name), type(_type), level(_level), flags(_flags)
{
}

Appender::~Appender()
{
}

uint8 Appender::getId() const
{
    return id;
}

std::string const& Appender::getName() const
{
    return name;
}

AppenderType Appender::getType() const
{
    return type;
}

LogLevel Appender::getLogLevel() const
{
    return level;
}

AppenderFlags Appender::getFlags() const
{
    return flags;
}

void Appender::setLogLevel(LogLevel _level)
{
    level = _level;
}

void Appender::write(LogMessage& message)
{
    if (!level || level > message.level)
    {
        //fprintf(stderr, "Appender::write: Appender %s, Level %s. Msg %s Level %s Type %s WRONG LEVEL MASK\n", getName().c_str(), getLogLevelString(level), message.text.c_str(), getLogLevelString(message.level), getLogFilterTypeString(message.type)); // DEBUG - RemoveMe
        return;
    }

    message.prefix.clear();
    if (flags & APPENDER_FLAGS_PREFIX_TIMESTAMP)
        message.prefix.append(message.getTimeStr().c_str());

    if (flags & APPENDER_FLAGS_PREFIX_LOGLEVEL)
    {
        if (!message.prefix.empty())
            message.prefix.push_back(' ');

        char text[MAX_QUERY_LEN];
        snprintf(text, MAX_QUERY_LEN, "%-5s", Appender::getLogLevelString(message.level));
        message.prefix.append(text);
    }

    if (flags & APPENDER_FLAGS_PREFIX_LOGFILTERTYPE)
    {
        if (!message.prefix.empty())
            message.prefix.push_back(' ');

        char text[MAX_QUERY_LEN];
        snprintf(text, MAX_QUERY_LEN, "[%s]", Appender::getLogFilterTypeString(message.type));
        message.prefix.append(text);
    }

    if (!message.prefix.empty())
        message.prefix.push_back(' ');

    _write(message);
}

const char* Appender::getLogLevelString(LogLevel level)
{
    switch (level)
    {
        case LOG_LEVEL_FATAL:
            return "FATAL";
        case LOG_LEVEL_ERROR:
            return "ERROR";
        case LOG_LEVEL_WARN:
            return "WARN";
        case LOG_LEVEL_INFO:
            return "INFO";
        case LOG_LEVEL_DEBUG:
            return "DEBUG";
        case LOG_LEVEL_TRACE:
            return "TRACE";
        default:
            return "DISABLED";
    }
}

char const* Appender::getLogFilterTypeString(LogFilterType type)
{
    switch (type)
    {
        case LOG_FILTER_GENERAL:
            return "GENERAL";
        case LOG_FILTER_UNITS:
            return "UNITS";
        case LOG_FILTER_PETS:
            return "PETS";
        case LOG_FILTER_VEHICLES:
            return "VEHICLES";
        case LOG_FILTER_TSCR:
            return "TSCR";
        case LOG_FILTER_DATABASE_AI:
            return "DATABASE_AI";
        case LOG_FILTER_MAPSCRIPTS:
            return "MAPSCRIPTS";
        case LOG_FILTER_NETWORKIO:
            return "NETWORKIO";
        case LOG_FILTER_SPELLS_AURAS:
            return "SPELLS_AURAS";
        case LOG_FILTER_ACHIEVEMENTSYS:
            return "ACHIEVEMENTSYS";
        case LOG_FILTER_CONDITIONSYS:
            return "CONDITIONSYS";
        case LOG_FILTER_POOLSYS:
            return "POOLSYS";
        case LOG_FILTER_AUCTIONHOUSE:
            return "AUCTIONHOUSE";
        case LOG_FILTER_BATTLEGROUND:
            return "BATTLEGROUND";
        case LOG_FILTER_OUTDOORPVP:
            return "OUTDOORPVP";
        case LOG_FILTER_CHATSYS:
            return "CHATSYS";
        case LOG_FILTER_LFG:
            return "LFG";
        case LOG_FILTER_MAPS:
            return "MAPS";
        case LOG_FILTER_PLAYER:
            return "PLAYER";
        case LOG_FILTER_PLAYER_LOADING:
            return "PLAYER LOADING";
        case LOG_FILTER_PLAYER_ITEMS:
            return "PLAYER ITEMS";
        case LOG_FILTER_PLAYER_SKILLS:
            return "PLAYER SKILLS";
        case LOG_FILTER_PLAYER_CHATLOG:
            return "PLAYER CHATLOG";
        case LOG_FILTER_LOOT:
            return "LOOT";
        case LOG_FILTER_GUILD:
            return "GUILD";
        case LOG_FILTER_TRANSPORTS:
            return "TRANSPORTS";
        case LOG_FILTER_SQL:
            return "SQL";
        case LOG_FILTER_GMCOMMAND:
            return "GMCOMMAND";
        case LOG_FILTER_REMOTECOMMAND:
            return "REMOTECOMMAND";
        case LOG_FILTER_WARDEN:
            return "WARDEN";
        case LOG_FILTER_AUTHSERVER:
            return "AUTHSERVER";
        case LOG_FILTER_WORLDSERVER:
            return "WORLDSERVER";
        case LOG_FILTER_GAMEEVENTS:
            return "GAMEEVENTS";
        case LOG_FILTER_CALENDAR:
            return "CALENDAR";
        case LOG_FILTER_CHARACTER:
            return "CHARACTER";
        case LOG_FILTER_ARENAS:
            return "ARENAS";
        case LOG_FILTER_SQL_DRIVER:
            return "SQL DRIVER";
        case LOG_FILTER_SQL_DEV:
            return "SQL DEV";
        case LOG_FILTER_PLAYER_DUMP:
            return "PLAYER DUMP";
        case LOG_FILTER_BATTLEFIELD:
            return "BATTLEFIELD";
        case LOG_FILTER_SERVER_LOADING:
            return "SERVER LOADING";
        case LOG_FILTER_OPCODES:
            return "OPCODE";
        case LOG_FILTER_SOAP:
            return "SOAP";
        default:
            break;
    }
    return "???";
}
