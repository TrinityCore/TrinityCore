/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 */

#include "tc_catch2.h"

#include "RewireConfig.h"
#include "RewireQueue.h"

#include <atomic>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace
{
class TemporaryDirectory final
{
public:
    TemporaryDirectory()
    {
        static std::atomic_uint64_t sequence = 0;
        auto const timestamp = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        _path = std::filesystem::temp_directory_path() /
            ("trinitycore-rewire-" + std::to_string(timestamp) + "-" + std::to_string(sequence.fetch_add(1)));
        std::filesystem::create_directories(_path);
    }

    ~TemporaryDirectory()
    {
        std::error_code error;
        std::filesystem::remove_all(_path, error);
    }

    std::filesystem::path const& Path() const { return _path; }

private:
    std::filesystem::path _path;
};

std::filesystem::path WriteConfig(TemporaryDirectory const& directory, std::string const& content)
{
    std::filesystem::path const path = directory.Path() / "rewire.configs";
    std::ofstream stream(path);
    stream << content;
    stream.close();
    return path;
}
}

TEST_CASE("REWIRE declarative configuration loads", "[rewire][config]")
{
    TemporaryDirectory directory;
    std::filesystem::path const path = WriteConfig(directory, R"json({
        "schemaVersion": 1,
        "enabled": true,
        "nodeId": "node-test",
        "shardCount": 4,
        "queue": {
            "capacity": 32,
            "flushIntervalMs": 250,
            "spoolPath": "state.ndjson"
        },
        "firebase": {
            "projectId": "rewire-test",
            "databaseId": "(default)",
            "collection": "player_state",
            "auth": {
                "mode": "application_default",
                "serviceAccountPath": ""
            }
        },
        "conversion": {
            "sourceSchema": "trinitycore.rewire.state.v1",
            "targetSchema": "firestore.document.v1"
        }
    })json");

    Trinity::Rewire::RewireConfig config;
    std::string error;
    REQUIRE(Trinity::Rewire::RewireConfigLoader::Load(path, config, error));
    REQUIRE(error.empty());
    CHECK(config.Enabled);
    CHECK(config.NodeId == "node-test");
    CHECK(config.ShardCount == 4);
    CHECK(config.Queue.Capacity == 32);
    CHECK(config.Queue.FlushIntervalMs == 250);
    CHECK(config.Firebase.ProjectId == "rewire-test");
    CHECK(config.Firebase.Collection == "player_state");
}

TEST_CASE("REWIRE configuration rejects unsupported schemas", "[rewire][config]")
{
    TemporaryDirectory directory;
    std::filesystem::path const path = WriteConfig(directory, R"json({
        "schemaVersion": 2,
        "enabled": false
    })json");

    Trinity::Rewire::RewireConfig config;
    std::string error;
    CHECK_FALSE(Trinity::Rewire::RewireConfigLoader::Load(path, config, error));
    CHECK(error == "unsupported schemaVersion; expected 1");
}

TEST_CASE("REWIRE service-account mode requires a key path", "[rewire][config]")
{
    TemporaryDirectory directory;
    std::filesystem::path const path = WriteConfig(directory, R"json({
        "schemaVersion": 1,
        "enabled": true,
        "firebase": {
            "projectId": "rewire-test",
            "auth": {
                "mode": "service_account_file",
                "serviceAccountPath": ""
            }
        }
    })json");

    Trinity::Rewire::RewireConfig config;
    std::string error;
    CHECK_FALSE(Trinity::Rewire::RewireConfigLoader::Load(path, config, error));
    CHECK(error == "firebase.auth.serviceAccountPath is required for service_account_file authentication");
}

TEST_CASE("REWIRE queue persists capacity and explicit flushes", "[rewire][queue]")
{
    TemporaryDirectory directory;
    std::filesystem::path const spool = directory.Path() / "state.ndjson";
    Trinity::Rewire::PersistentQueue queue(spool, 2);

    std::string error;
    REQUIRE(queue.Initialize(error));
    REQUIRE(queue.Enqueue("first", error));
    REQUIRE(queue.Enqueue("second", error));
    CHECK(queue.Pending() == 2);

    REQUIRE(queue.Enqueue("third", error));
    CHECK(queue.Pending() == 1);
    REQUIRE(queue.Flush(error));
    CHECK(queue.Pending() == 0);

    std::ifstream stream(spool);
    std::vector<std::string> lines;
    for (std::string line; std::getline(stream, line);)
        lines.push_back(std::move(line));

    REQUIRE(lines.size() == 3);
    CHECK(lines[0] == "first");
    CHECK(lines[1] == "second");
    CHECK(lines[2] == "third");
}
