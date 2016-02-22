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
    using namespace std::chrono;

    std::string data = category + ",realm=Windows value=" + std::to_string(value) + "i"
        + " " + std::to_string(duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count());

    Enqueue(data);
}

void StatsLogger::LogEvent(std::string const& title, std::string const& description)
{
    using namespace std::chrono;

    std::string data = "events,realm=Windows title=\"" + title + "\",text=\"" + description + "\""
        + " " + std::to_string(duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count());

    Enqueue(data);
}

void StatsLogger::Enqueue(std::string const& data)
{
    queuedData.Enqueue(new std::string(data));
//Warning: temporarily calling SendBatch() till asio is implemented"
    SendBatch();
}

void StatsLogger::SendBatch()
{
    std::stringstream batchedData;
    std::string* data;
    bool firstLoop = true;
    while (queuedData.Dequeue(data))
    {
        if (!firstLoop)
            batchedData << "\n";

        batchedData << *data;
        firstLoop = false;
    }

    if (batchedData.tellp() == std::streampos(0))
        return;

    batchedData << "\r\n";

    dataStream << "POST " << "/write?db=worldserver" << " HTTP/1.1\r\n";
    dataStream << "Host: " << "localhost:8086" << "\r\n";
    dataStream << "Accept: */*\r\n";
    dataStream << "Content-Type: application/octet-stream\r\n";
    dataStream << "Content-Transfer-Encoding: binary\r\n";

    dataStream << "Content-Length: " << std::to_string(batchedData.tellp() - std::streampos(2)) << "\r\n\r\n";
    dataStream << batchedData.rdbuf();
    dataStream << "\r\n";

    std::string http_version;
    dataStream >> http_version;
    unsigned int status_code = 0;
    dataStream >> status_code;
    if (status_code != 204)
    {
        TC_LOG_ERROR("statslogger", "Error sending data, returned HTTP code: %u. Request content: '%s'", status_code, batchedData.str().c_str());
    }

    // Read and ignore teh status description
    std::string status_description;
    std::getline(dataStream, status_description);
    // Read and ignore any header
    std::string header;
    while (std::getline(dataStream, header) && header != "\r")
        ;
}
