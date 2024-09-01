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

Logger::Logger(std::string const& _name, LogLevel _level): name(_name), level(_level) { }

std::string const& Logger::getName() const
{
    return name;
}

LogLevel Logger::getLogLevel() const
{
    return level;
}

void Logger::addAppender(Appender* appender)
{
    appenders.push_back(appender);
}

void Logger::setLogLevel(LogLevel _level)
{
    level = _level;
}

void Logger::write(LogMessage* message) const
{
    if (!level || level > message->level || message->text.empty())
    {
        //fprintf(stderr, "Logger::write: Logger %s, Level %u. Msg %s Level %u WRONG LEVEL MASK OR EMPTY MSG\n", getName().c_str(), getLogLevel(), message.text.c_str(), message.level);
        return;
    }

    for (Appender* appender : appenders)
        appender->write(message);
}
