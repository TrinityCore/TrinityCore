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

#include "Logger.h"

Logger::Logger(): name(""), level(LOG_LEVEL_DISABLED) { }

void Logger::Create(std::string const& _name, LogLevel _level)
{
    name = _name;
    level = _level;
}

Logger::~Logger()
{
    for (AppenderMap::iterator it = appenders.begin(); it != appenders.end(); ++it)
        it->second = NULL;
    appenders.clear();
}

std::string const& Logger::getName() const
{
    return name;
}

LogLevel Logger::getLogLevel() const
{
    return level;
}

void Logger::addAppender(uint8 id, Appender* appender)
{
    appenders[id] = appender;
}

void Logger::delAppender(uint8 id)
{
    AppenderMap::iterator it = appenders.find(id);
    if (it != appenders.end())
    {
        it->second = NULL;
        appenders.erase(it);
    }
}

void Logger::setLogLevel(LogLevel _level)
{
    level = _level;
}

void Logger::write(LogMessage& message) const
{
    if (!level || level > message.level || message.text.empty())
    {
        //fprintf(stderr, "Logger::write: Logger %s, Level %u. Msg %s Level %u WRONG LEVEL MASK OR EMPTY MSG\n", getName().c_str(), messge.level, message.text.c_str(), .message.level); // DEBUG - RemoveMe
        return;
    }

    for (AppenderMap::const_iterator it = appenders.begin(); it != appenders.end(); ++it)
        if (it->second)
            it->second->write(message);
}
