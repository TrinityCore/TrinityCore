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

#include "Logger.h"
#include "Appender.h"
#include "LogMessage.h"

Logger::Logger(std::string const& name, LogLevel level): _name(name), _level(level) { }

std::string const& Logger::getName() const
{
    return _name;
}

LogLevel Logger::getLogLevel() const
{
    return _level;
}

void Logger::addAppender(uint8 id, Appender* appender)
{
    _appenders[id] = appender;
}

void Logger::delAppender(uint8 id)
{
    _appenders.erase(id);
}

void Logger::setLogLevel(LogLevel level)
{
    _level = level;
}

void Logger::write(LogMessage* message) const
{
    if (!_level || _level > message->level || message->text.empty())
    {
        //fprintf(stderr, "Logger::write: Logger %s, Level %u. Msg %s Level %u WRONG LEVEL MASK OR EMPTY MSG\n", getName().c_str(), getLogLevel(), message.text.c_str(), message.level);
        return;
    }

    for (auto it = _appenders.begin(); it != _appenders.end(); ++it)
        if (it->second)
            it->second->write(message);
}
