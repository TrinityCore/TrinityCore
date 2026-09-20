/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 */

#ifndef AIWORLD_TELEMETRYEXPORTER_H
#define AIWORLD_TELEMETRYEXPORTER_H

#include "AgentTelemetrySnapshot.h"
#include <atomic>
#include <memory>
#include <string>
#include <vector>

namespace Trinity::Asio { class IoContext; }

// One bounded asynchronous HTTP request at a time. Submit() is called only
// on the world thread and never performs DNS, socket I/O, or serialization.
class TelemetryExporter
{
public:
    TelemetryExporter(Trinity::Asio::IoContext& ioContext, std::string host, std::string port, std::string token);
    bool Busy() const { return _inFlight->load(std::memory_order_acquire); }
    void Submit(std::vector<AgentTelemetrySnapshot> snapshots, uint64 capturedAtMs);

private:
    Trinity::Asio::IoContext& _ioContext;
    std::string _host;
    std::string _port;
    std::string _token;
    // Shared with a self-owned session so a late completion cannot access a
    // destroyed exporter during shutdown.
    std::shared_ptr<std::atomic<bool>> _inFlight = std::make_shared<std::atomic<bool>>(false);
};

#endif // AIWORLD_TELEMETRYEXPORTER_H
