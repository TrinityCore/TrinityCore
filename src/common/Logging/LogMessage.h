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

#ifndef LogMessage_h__
#define LogMessage_h__

#include "Define.h"
#include "LogCommon.h"
#include <string>
#include <ctime>

struct TC_COMMON_API LogMessage
{
    LogMessage(LogLevel _level, std::string const& _type, std::string&& _text);
    LogMessage(LogLevel _level, std::string const& _type, std::string&& _text, std::string&& _param1);

    LogMessage(LogMessage const& /*other*/) = delete;
    LogMessage& operator=(LogMessage const& /*other*/) = delete;

    static std::string getTimeStr(time_t time);
    std::string getTimeStr();

    LogLevel const level;
    std::string const type;
    std::string const text;
    std::string prefix;
    std::string param1;
    time_t mtime;

    ///@ Returns size of the log message content in bytes
    uint32 Size() const
    {
        return static_cast<uint32>(prefix.size() + text.size());
    }
};

#endif // LogMessage_h__
