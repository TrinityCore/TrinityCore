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
        static const char* getLogLevelString(LogLevel level);
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

#endif
