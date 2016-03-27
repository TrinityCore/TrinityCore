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

#include "Metric.h"
#include "Log.h"
#include "Config.h"
#include "Util.h"

void Metric::Initialize(std::string const& realmName, boost::asio::io_service& ioService, std::function<void()> overallStatusLogger)
{
    _realmName = realmName;
    _batchTimer = Trinity::make_unique<boost::asio::deadline_timer>(ioService);
    _overallStatusTimer = Trinity::make_unique<boost::asio::deadline_timer>(ioService);
    _overallStatusLogger = overallStatusLogger;
    LoadFromConfigs();
}

bool Metric::Connect()
{
    _dataStream.connect(_hostname, _port);
    auto error = _dataStream.error();
    if (error)
    {
        TC_LOG_ERROR("metric", "Error connecting to '%s:%s', disabling Metric. Error message : %s",
            _hostname.c_str(), _port.c_str(), error.message().c_str());
        _enabled = false;
        return false;
    }
    _dataStream.clear();
    return true;
}

void Metric::LoadFromConfigs()
{
    bool previousValue = _enabled;
    _enabled = sConfigMgr->GetBoolDefault("Metric.Enable", false);
    _updateInterval = sConfigMgr->GetIntDefault("Metric.Interval", 10);
    if (_updateInterval < 1)
    {
        TC_LOG_ERROR("metric", "'Metric.Interval' config set to %d, overriding to 1.", _updateInterval);
        _updateInterval = 1;
    }

    _overallStatusTimerInterval = sConfigMgr->GetIntDefault("Metric.OverallStatusInterval", 1);
    if (_overallStatusTimerInterval < 1)
    {
        TC_LOG_ERROR("metric", "'Metric.OverallStatusInterval' config set to %d, overriding to 1.", _overallStatusTimerInterval);
        _overallStatusTimerInterval = 1;
    }

    // Schedule a send at this point only if the config changed from Disabled to Enabled.
    // Cancel any scheduled operation if the config changed from Enabled to Disabled.
    if (_enabled && !previousValue)
    {
        std::string connectionInfo = sConfigMgr->GetStringDefault("Metric.ConnectionInfo", "");
        if (connectionInfo.empty())
        {
            TC_LOG_ERROR("metric", "'Metric.ConnectionInfo' not specified in configuration file.");
            return;
        }

        Tokenizer tokens(connectionInfo, ';');
        if (tokens.size() != 3)
        {
            TC_LOG_ERROR("metric", "'Metric.ConnectionInfo' specified with wrong format in configuration file.");
            return;
        }

        _hostname.assign(tokens[0]);
        _port.assign(tokens[1]);
        _databaseName.assign(tokens[2]);
        Connect();

        ScheduleSend();
        ScheduleOverallStatusLog();
    }
}

void Metric::Update()
{
    if (_overallStatusTimerTriggered)
    {
        _overallStatusTimerTriggered = false;
        _overallStatusLogger();
    }
}

void Metric::LogEvent(std::string const& category, std::string const& title, std::string const& description)
{
    using namespace std::chrono;

    MetricData* data = new MetricData;
    data->Category = category;
    data->Timestamp = system_clock::now();
    data->Type = METRIC_DATA_EVENT;
    data->Title = title;
    data->Text = description;

    _queuedData.Enqueue(data);
}

void Metric::SendBatch()
{
    using namespace std::chrono;

    std::stringstream batchedData;
    MetricData* data;
    bool firstLoop = true;
    while (_queuedData.Dequeue(data))
    {
        if (!firstLoop)
            batchedData << "\n";

        batchedData << data->Category;
        if (!_realmName.empty())
            batchedData << ",realm=" << _realmName;

        batchedData << " ";

        switch (data->Type)
        {
            case METRIC_DATA_VALUE:
                batchedData << "value=" << data->Value;
                break;
            case METRIC_DATA_EVENT:
                batchedData << "title=\"" << data->Title << "\",text=\"" << data->Text << "\"";
                break;
        }

        batchedData << " ";

        batchedData << std::to_string(duration_cast<nanoseconds>(data->Timestamp.time_since_epoch()).count());

        firstLoop = false;
        delete data;
    }

    // Check if there's any data to send
    if (batchedData.tellp() == std::streampos(0))
    {
        ScheduleSend();
        return;
    }

    if (!_dataStream.good() && !Connect())
        return;

    _dataStream << "POST " << "/write?db=" << _databaseName << " HTTP/1.1\r\n";
    _dataStream << "Host: " << _hostname << ":" << _port << "\r\n";
    _dataStream << "Accept: */*\r\n";
    _dataStream << "Content-Type: application/octet-stream\r\n";
    _dataStream << "Content-Transfer-Encoding: binary\r\n";

    _dataStream << "Content-Length: " << std::to_string(batchedData.tellp()) << "\r\n\r\n";
    _dataStream << batchedData.rdbuf();

    std::string http_version;
    _dataStream >> http_version;
    unsigned int status_code = 0;
    _dataStream >> status_code;
    if (status_code != 204)
    {
        TC_LOG_ERROR("metric", "Error sending data, returned HTTP code: %u", status_code);
    }

    // Read and ignore the status description
    std::string status_description;
    std::getline(_dataStream, status_description);
    // Read headers
    std::string header;
    while (std::getline(_dataStream, header) && header != "\r")
    {
        if (header == "Connection: close\r")
            _dataStream.close();
    }

    ScheduleSend();
}

void Metric::ScheduleSend()
{
    if (_enabled)
    {
        _batchTimer->expires_from_now(boost::posix_time::seconds(_updateInterval));
        _batchTimer->async_wait(std::bind(&Metric::SendBatch, this));
    }
    else
    {
        _dataStream.close();
        MetricData* data;
        // Clear the queue
        while (_queuedData.Dequeue(data))
            ;
    }
}

void Metric::ForceSend()
{
    // Send what's queued only if io_service is stopped (so only on shutdown)
    if (_enabled && _batchTimer->get_io_service().stopped())
        SendBatch();
}

void Metric::ScheduleOverallStatusLog()
{
    if (_enabled)
    {
        _overallStatusTimer->expires_from_now(boost::posix_time::seconds(_overallStatusTimerInterval));
        _overallStatusTimer->async_wait([this](const boost::system::error_code&)
        {
            _overallStatusTimerTriggered = true;
            ScheduleOverallStatusLog();
        });
    }
}

Metric* Metric::instance()
{
    static Metric instance;
    return &instance;
}
