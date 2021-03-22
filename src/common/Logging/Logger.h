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

#ifndef LOGGER_H
#define LOGGER_H

#include "Define.h"
#include "LogCommon.h"
#include <unordered_map>
#include <string>

class Appender;
struct LogMessage;

class TC_COMMON_API Logger
{
    public:
        Logger(std::string const& name, LogLevel level);

        void addAppender(uint8 type, Appender* appender);
        void delAppender(uint8 type);

        std::string const& getName() const;
        LogLevel getLogLevel() const;
        void setLogLevel(LogLevel level);
        void write(LogMessage* message) const;

    private:
        std::string name;
        LogLevel level;
        std::unordered_map<uint8, Appender*> appenders;
};

#endif
