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

#include "Appender.h"
#include "Common.h"
#include "Util.h"
#include "StringFormat.h"

#include <utility>
#include <sstream>

std::string LogMessage::getTimeStr(time_t time)
{
    tm aTm;
    localtime_r(&time, &aTm);
    char buf[20];
    snprintf(buf, 20, "%04d-%02d-%02d_%02d:%02d:%02d", aTm.tm_year+1900, aTm.tm_mon+1, aTm.tm_mday, aTm.tm_hour, aTm.tm_min, aTm.tm_sec);
    return std::string(buf);
}

std::string LogMessage::getTimeStr()
{
    return getTimeStr(mtime);
}

Appender::Appender(uint8 _id, std::string const& _name, LogLevel _level /* = LOG_LEVEL_DISABLED */, AppenderFlags _flags /* = APPENDER_FLAGS_NONE */):
id(_id), name(_name), level(_level), flags(_flags) { }

Appender::~Appender() { }

uint8 Appender::getId() const
{
    return id;
}

std::string const& Appender::getName() const
{
    return name;
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

void Appender::write(LogMessage* message)
{
    if (!level || level > message->level)
        return;

    std::ostringstream ss;

    if (flags & APPENDER_FLAGS_PREFIX_TIMESTAMP)
        ss << message->getTimeStr() << ' ';

    if (flags & APPENDER_FLAGS_PREFIX_LOGLEVEL)
        ss << Trinity::StringFormat("%-5s ", Appender::getLogLevelString(message->level));

    if (flags & APPENDER_FLAGS_PREFIX_LOGFILTERTYPE)
        ss << '[' << message->type << "] ";

    message->prefix = ss.str();
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
