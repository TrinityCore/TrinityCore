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
#include "Config.h"

StatsLogger::StatsLogger() : _batchTimer(nullptr), _updateInterval(0), _enabled(false)
{
}

StatsLogger::~StatsLogger()
{
    delete _batchTimer;
}

void StatsLogger::Initialize(boost::asio::io_service& ioService, uint32 updateInterval)
{
    _dataStream.connect("localhost", "8086");
    _updateInterval = updateInterval;
    _batchTimer = new boost::asio::deadline_timer(ioService);
    LoadFromConfigs();
}

void StatsLogger::LoadFromConfigs()
{
    bool previousValue = _enabled;
    _enabled = sConfigMgr->GetBoolDefault("InfluxDB.Enable", false);

    // Schedule a send at this point only if the config changed from Disabled to Enabled.
    // In all other cases no further action is needed.
    if (_enabled && !previousValue)
        ScheduleSend();
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
    _queuedData.Enqueue(new std::string(data));
}

void StatsLogger::SendBatch()
{
    std::stringstream batchedData;
    std::string* data;
    bool firstLoop = true;
    while (_queuedData.Dequeue(data))
    {
        if (!firstLoop)
            batchedData << "\n";

        batchedData << *data;
        firstLoop = false;
        delete data;
    }

    if (batchedData.tellp() == std::streampos(0))
    {
        ScheduleSend();
        return;
    }

    batchedData << "\r\n";

    _dataStream << "POST " << "/write?db=worldserver" << " HTTP/1.1\r\n";
    _dataStream << "Host: " << "localhost:8086" << "\r\n";
    _dataStream << "Accept: */*\r\n";
    _dataStream << "Content-Type: application/octet-stream\r\n";
    _dataStream << "Content-Transfer-Encoding: binary\r\n";

    _dataStream << "Content-Length: " << std::to_string(batchedData.tellp() - std::streampos(2)) << "\r\n\r\n";
    _dataStream << batchedData.rdbuf();
    _dataStream << "\r\n";

    std::string http_version;
    _dataStream >> http_version;
    unsigned int status_code = 0;
    _dataStream >> status_code;
    if (status_code != 204)
    {
        TC_LOG_ERROR("statslogger", "Error sending data, returned HTTP code: %u. Request content: '%s'", status_code, batchedData.str().c_str());
    }

    // Read and ignore teh status description
    std::string status_description;
    std::getline(_dataStream, status_description);
    // Read and ignore any header
    std::string header;
    while (std::getline(_dataStream, header) && header != "\r")
        ;

    ScheduleSend();
}

void StatsLogger::ScheduleSend()
{
    if (_enabled)
    {
        _batchTimer->expires_from_now(boost::posix_time::seconds(_updateInterval));
        _batchTimer->async_wait(std::bind(&StatsLogger::SendBatch, this));
    }
}

void StatsLogger::ForceSend()
{
    // Send what's queued only if io_service is stopped (so only on shutdown)
    if (_enabled && _batchTimer->get_io_service().stopped())
        SendBatch();
}
