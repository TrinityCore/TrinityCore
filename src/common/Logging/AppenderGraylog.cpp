/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "AppenderGraylog.h"
#include "LogMessage.h"
#include "Util.h"
#include <sstream>
#include <boost/algorithm/string/replace.hpp>

#ifdef WITH_CPR
    #include <cpr/cpr.h>
#endif

AppenderGraylog::AppenderGraylog(uint8 id, std::string const& name, LogLevel level, AppenderFlags flags, std::vector<char const*> extraArgs)
    : Appender(id, name, level, flags), _realmId(0)
{
    _graylogSourceURL = extraArgs[0];
}

void AppenderGraylog::_write(LogMessage const* message)
{
    #ifdef WITH_CPR
        if (_graylogSourceURL.empty())
            return;

        std::string text    = message->text;
        uint32 logLevel     = message->level;

        boost::replace_all(text, "\"", "\\\"");

        std::ostringstream payload;
        payload << "{";
        payload << "\"host\": \"" << _realmName << "\", ";
        payload << "\"_realmId\": \"" << _realmId << "\", ";
        payload << "\"short_message\" : \"" << text << "\", ";
        payload << "\"level\" : " << logLevel;
        payload << "}";

        cpr::Response r = cpr::Post(cpr::Url{ _graylogSourceURL }, cpr::Body{ payload.str() });
    #endif
}

void AppenderGraylog::setRealmId(uint32 realmId, std::string realmName)
{
    _realmId = realmId;
    _realmName = realmName;
}
