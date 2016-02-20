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

#include "StatsLogger.h"

StatsLogger::StatsLogger()
{

}

StatsLogger::~StatsLogger()
{

}

void StatsLogger::Update(uint32 diff)
{
    boost::asio::ip::tcp::iostream influxDbStream;
    influxDbStream.expires_from_now(boost::posix_time::seconds(60));
    influxDbStream.connect("localhost", "8086");

    std::string influxDbData = "update_time_diff,realm=Windows value=" + std::to_string(diff) + "i";

    influxDbStream << "POST " << "/write?db=worldserver" << " HTTP/1.0\r\n";
    influxDbStream << "Host: " << "localhost:8086" << "\r\n";
    influxDbStream << "Accept: */*\r\n";
    influxDbStream << "Content-Type: application/octet-stream\r\n";
    influxDbStream << "Content-Transfer-Encoding: binary\r\n";
    influxDbStream << "Content-Length: " << std::to_string(influxDbData.length()) << "\r\n\r\n";
    influxDbStream << influxDbData;
    influxDbStream << "\r\n\r\n";

    std::string http_version;
    influxDbStream >> http_version;
    unsigned int status_code;
    influxDbStream >> status_code;
    if (status_code != 204)
    {
        printf("Something went wrong\n");
    }
}
