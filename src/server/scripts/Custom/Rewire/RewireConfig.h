/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 */

#ifndef TRINITYCORE_REWIRE_CONFIG_H
#define TRINITYCORE_REWIRE_CONFIG_H

#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <string>

namespace Trinity::Rewire
{
enum class FirebaseAuthMode : std::uint8_t
{
    ApplicationDefault,
    ServiceAccountFile
};

struct QueueConfig
{
    std::size_t Capacity = 8192;
    std::uint32_t FlushIntervalMs = 1000;
    std::filesystem::path SpoolPath = "rewire-spool/state.ndjson";
};

struct FirebaseConfig
{
    std::string ProjectId;
    std::string DatabaseId = "(default)";
    std::string Collection = "rewire_state";
    FirebaseAuthMode AuthMode = FirebaseAuthMode::ApplicationDefault;
    std::filesystem::path ServiceAccountPath;
};

struct ConversionConfig
{
    std::string SourceSchema = "trinitycore.rewire.state.v1";
    std::string TargetSchema = "firestore.document.v1";
};

struct RewireConfig
{
    std::uint32_t SchemaVersion = 1;
    bool Enabled = false;
    std::string NodeId = "auto";
    std::uint32_t ShardCount = 1;
    QueueConfig Queue;
    FirebaseConfig Firebase;
    ConversionConfig Conversion;
};

class RewireConfigLoader final
{
public:
    static bool Load(std::filesystem::path const& path, RewireConfig& config, std::string& error);
};
}

#endif // TRINITYCORE_REWIRE_CONFIG_H
