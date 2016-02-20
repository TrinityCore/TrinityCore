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
#include "Log.h"

StatsLogger::StatsLogger()
{
    dataStream.connect("localhost", "8086");
}

StatsLogger::~StatsLogger()
{

}

void StatsLogger::LogValue(std::string const& category, uint32 value)
{
    std::string data = category + ",realm=Windows value=" + std::to_string(value) + "i";
    Log(data);
}

void StatsLogger::LogEvent(std::string const& title, std::string const& description)
{
    std::string data = "events,realm=Windows title=\"" + title + "\",text=\"" + description + "\"";
    Log(data);
}

void StatsLogger::Log(std::string& data)
{
    dataStream << "POST " << "/write?db=worldserver" << " HTTP/1.1\r\n";
    dataStream << "Host: " << "localhost:8086" << "\r\n";
    dataStream << "Accept: */*\r\n";
    dataStream << "Content-Type: application/octet-stream\r\n";
    dataStream << "Content-Transfer-Encoding: binary\r\n";
    dataStream << "Content-Length: " << std::to_string(data.length()) << "\r\n\r\n";
    dataStream << data;
    dataStream << "\r\n\r\n";

    std::string http_version;
    dataStream >> http_version;
    unsigned int status_code = 0;
    dataStream >> status_code;
    if (status_code != 204)
    {
        TC_LOG_ERROR("statslogger", "Error sending data '%s', returned HTTP code: %u", data.c_str(), status_code);
    }

    // Read and ignore teh status description
    std::string status_description;
    std::getline(dataStream, status_description);
    // Read and ignore any header
    std::string header;
    while (std::getline(dataStream, header) && header != "\r")
        ;
}
