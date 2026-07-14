/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 */

#include "RewireConfig.h"
#include "RewireQueue.h"

#include "Log.h"
#include "Player.h"
#include "ScriptMgr.h"

#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

#include <chrono>
#include <cstdlib>
#include <memory>
#include <string>
#include <string_view>

namespace Trinity::Rewire
{
namespace
{
class Runtime final
{
public:
    static Runtime& Instance()
    {
        static Runtime runtime;
        return runtime;
    }

    void Start()
    {
        std::string const configPath = []
        {
            if (char const* value = std::getenv("REWIRE_CONFIG_PATH"))
                return std::string(value);
            return std::string("rewire.configs");
        }();

        std::string error;
        if (!RewireConfigLoader::Load(configPath, _config, error))
        {
            TC_LOG_ERROR("server.rewire", "REWIRE disabled: {}", error);
            _enabled = false;
            return;
        }

        _enabled = _config.Enabled;
        if (!_enabled)
        {
            TC_LOG_INFO("server.rewire", "REWIRE is disabled by configuration {}", configPath);
            return;
        }

        _queue = std::make_unique<PersistentQueue>(_config.Queue.SpoolPath, _config.Queue.Capacity);
        if (!_queue->Initialize(error))
        {
            TC_LOG_ERROR("server.rewire", "REWIRE disabled: {}", error);
            _queue.reset();
            _enabled = false;
            return;
        }

        _flushCountdownMs = _config.Queue.FlushIntervalMs;
        TC_LOG_INFO("server.rewire", "REWIRE enabled for Firebase project '{}' using collection '{}' and spool '{}'",
            _config.Firebase.ProjectId, _config.Firebase.Collection, _config.Queue.SpoolPath.generic_string());
    }

    void Update(std::uint32_t diff)
    {
        if (!_enabled || !_queue)
            return;

        if (diff < _flushCountdownMs)
        {
            _flushCountdownMs -= diff;
            return;
        }

        Flush();
        _flushCountdownMs = _config.Queue.FlushIntervalMs;
    }

    void Stop()
    {
        Flush();
        _queue.reset();
        _enabled = false;
    }

    void RecordPlayerEvent(std::string_view eventName, Player const& player)
    {
        if (!_enabled || !_queue)
            return;

        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

        writer.StartObject();
        writer.Key("schema");
        writer.String(_config.Conversion.SourceSchema.c_str());
        writer.Key("targetSchema");
        writer.String(_config.Conversion.TargetSchema.c_str());
        writer.Key("nodeId");
        writer.String(_config.NodeId.c_str());
        writer.Key("shardCount");
        writer.Uint(_config.ShardCount);
        writer.Key("event");
        writer.String(eventName.data(), static_cast<rapidjson::SizeType>(eventName.size()));
        writer.Key("timestampMs");
        writer.Int64(std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count());
        writer.Key("player");
        writer.StartObject();
        writer.Key("guid");
        writer.Uint64(player.GetGUID().GetCounter());
        writer.Key("name");
        writer.String(player.GetName().c_str());
        writer.Key("level");
        writer.Uint(player.GetLevel());
        writer.Key("mapId");
        writer.Uint(player.GetMapId());
        writer.EndObject();
        writer.EndObject();

        std::string error;
        if (!_queue->Enqueue(std::string(buffer.GetString(), buffer.GetSize()), error))
            TC_LOG_ERROR("server.rewire", "Failed to queue '{}' event for player {}: {}", eventName, player.GetGUID().ToString(), error);
    }

private:
    void Flush()
    {
        if (!_queue)
            return;

        std::string error;
        if (!_queue->Flush(error))
            TC_LOG_ERROR("server.rewire", "REWIRE queue flush failed: {}", error);
    }

    RewireConfig _config;
    std::unique_ptr<PersistentQueue> _queue;
    std::uint32_t _flushCountdownMs = 0;
    bool _enabled = false;
};

class RewireWorldScript final : public WorldScript
{
public:
    RewireWorldScript() : WorldScript("RewireWorldScript") { }

    void OnStartup() override
    {
        Runtime::Instance().Start();
    }

    void OnUpdate(std::uint32_t diff) override
    {
        Runtime::Instance().Update(diff);
    }

    void OnShutdown() override
    {
        Runtime::Instance().Stop();
    }
};

class RewirePlayerScript final : public PlayerScript
{
public:
    RewirePlayerScript() : PlayerScript("RewirePlayerScript") { }

    void OnLogin(Player* player, bool /*firstLogin*/) override
    {
        Runtime::Instance().RecordPlayerEvent("login", *player);
    }

    void OnSave(Player* player) override
    {
        Runtime::Instance().RecordPlayerEvent("save", *player);
    }

    void OnLogout(Player* player) override
    {
        Runtime::Instance().RecordPlayerEvent("logout", *player);
    }
};
}
}

void AddRewireScripts()
{
    new Trinity::Rewire::RewireWorldScript();
    new Trinity::Rewire::RewirePlayerScript();
}
