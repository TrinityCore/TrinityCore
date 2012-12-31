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

#ifndef LOGGER_H
#define LOGGER_H

#include "Appender.h"

class Logger
{
    public:
        Logger();
        ~Logger();

        void Create(std::string const& name, LogFilterType type, LogLevel level);
        void addAppender(uint8 type, Appender *);
        void delAppender(uint8 type);

        std::string const& getName() const;
        LogFilterType getType() const;
        LogLevel getLogLevel() const;
        void setLogLevel(LogLevel level);
        void write(LogMessage& message);

    private:
        std::string name;
        LogFilterType type;
        LogLevel level;
        AppenderMap appenders;
};

#endif
