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

#ifndef STATSLOGGER_H__
#define STATSLOGGER_H__

#include "Common.h"
#include <boost/asio/ip/tcp.hpp>

class StatsLogger
{
private:
    StatsLogger();
    ~StatsLogger();

    boost::asio::ip::tcp::iostream dataStream;

    void Log(std::string const& data);

public:
    static StatsLogger* instance()
    {
        static StatsLogger instance;
        return &instance;
    }

    void LogValue(std::string const& category, uint32 value);
    void LogEvent(std::string const& title, std::string const& description);
};

#define sStatsLogger StatsLogger::instance()
#endif // STATSLOGGER_H__
