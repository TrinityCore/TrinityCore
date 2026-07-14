/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 */

#include "RewireConfig.h"

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/istreamwrapper.h>

#include <fstream>
#include <limits>
#include <sstream>
#include <utility>

namespace Trinity::Rewire
{
namespace
{
bool ReadString(rapidjson::Value const& object, char const* name, std::string& value, std::string& error)
{
    auto member = object.FindMember(name);
    if (member == object.MemberEnd())
        return true;

    if (!member->value.IsString())
    {
        error = std::string("'") + name + "' must be a string";
        return false;
    }

    value.assign(member->value.GetString(), member->value.GetStringLength());
    return true;
}

bool ReadBool(rapidjson::Value const& object, char const* name, bool& value, std::string& error)
{
    auto member = object.FindMember(name);
    if (member == object.MemberEnd())
        return true;

    if (!member->value.IsBool())
    {
        error = std::string("'") + name + "' must be a boolean";
        return false;
    }

    value = member->value.GetBool();
    return true;
}

template <typename T>
bool ReadUnsigned(rapidjson::Value const& object, char const* name, T& value, std::string& error)
{
    auto member = object.FindMember(name);
    if (member == object.MemberEnd())
        return true;

    if (!member->value.IsUint64() || member->value.GetUint64() > std::numeric_limits<T>::max())
    {
        error = std::string("'") + name + "' must be an unsigned integer in range";
        return false;
    }

    value = static_cast<T>(member->value.GetUint64());
    return true;
}

rapidjson::Value const* ReadObject(rapidjson::Value const& parent, char const* name, std::string& error)
{
    auto member = parent.FindMember(name);
    if (member == parent.MemberEnd())
        return nullptr;

    if (!member->value.IsObject())
    {
        error = std::string("'") + name + "' must be an object";
        return nullptr;
    }

    return &member->value;
}

bool Validate(RewireConfig const& config, std::string& error)
{
    if (config.SchemaVersion != 1)
    {
        error = "unsupported schemaVersion; expected 1";
        return false;
    }

    if (config.NodeId.empty())
    {
        error = "nodeId must not be empty";
        return false;
    }

    if (config.ShardCount == 0)
    {
        error = "shardCount must be greater than zero";
        return false;
    }

    if (config.Queue.Capacity == 0 || config.Queue.FlushIntervalMs == 0 || config.Queue.SpoolPath.empty())
    {
        error = "queue capacity, flushIntervalMs, and spoolPath must be configured";
        return false;
    }

    if (!config.Enabled)
        return true;

    if (config.Firebase.ProjectId.empty())
    {
        error = "firebase.projectId is required when REWIRE is enabled";
        return false;
    }

    if (config.Firebase.Collection.empty())
    {
        error = "firebase.collection must not be empty";
        return false;
    }

    if (config.Firebase.AuthMode == FirebaseAuthMode::ServiceAccountFile && config.Firebase.ServiceAccountPath.empty())
    {
        error = "firebase.auth.serviceAccountPath is required for service_account_file authentication";
        return false;
    }

    return true;
}
}

bool RewireConfigLoader::Load(std::filesystem::path const& path, RewireConfig& config, std::string& error)
{
    std::ifstream stream(path);
    if (!stream)
    {
        error = "unable to open REWIRE config: " + path.generic_string();
        return false;
    }

    rapidjson::IStreamWrapper input(stream);
    rapidjson::Document document;
    document.ParseStream(input);

    if (document.HasParseError())
    {
        std::ostringstream message;
        message << "invalid JSON at offset " << document.GetErrorOffset() << ": "
                << rapidjson::GetParseError_En(document.GetParseError());
        error = message.str();
        return false;
    }

    if (!document.IsObject())
    {
        error = "REWIRE config root must be an object";
        return false;
    }

    RewireConfig parsed;
    if (!ReadUnsigned(document, "schemaVersion", parsed.SchemaVersion, error) ||
        !ReadBool(document, "enabled", parsed.Enabled, error) ||
        !ReadString(document, "nodeId", parsed.NodeId, error) ||
        !ReadUnsigned(document, "shardCount", parsed.ShardCount, error))
        return false;

    if (rapidjson::Value const* queue = ReadObject(document, "queue", error))
    {
        std::string spoolPath = parsed.Queue.SpoolPath.generic_string();
        if (!ReadUnsigned(*queue, "capacity", parsed.Queue.Capacity, error) ||
            !ReadUnsigned(*queue, "flushIntervalMs", parsed.Queue.FlushIntervalMs, error) ||
            !ReadString(*queue, "spoolPath", spoolPath, error))
            return false;
        parsed.Queue.SpoolPath = std::move(spoolPath);
    }
    else if (!error.empty())
        return false;

    if (rapidjson::Value const* firebase = ReadObject(document, "firebase", error))
    {
        if (!ReadString(*firebase, "projectId", parsed.Firebase.ProjectId, error) ||
            !ReadString(*firebase, "databaseId", parsed.Firebase.DatabaseId, error) ||
            !ReadString(*firebase, "collection", parsed.Firebase.Collection, error))
            return false;

        if (rapidjson::Value const* auth = ReadObject(*firebase, "auth", error))
        {
            std::string mode = "application_default";
            std::string serviceAccountPath;
            if (!ReadString(*auth, "mode", mode, error) ||
                !ReadString(*auth, "serviceAccountPath", serviceAccountPath, error))
                return false;

            if (mode == "application_default")
                parsed.Firebase.AuthMode = FirebaseAuthMode::ApplicationDefault;
            else if (mode == "service_account_file")
                parsed.Firebase.AuthMode = FirebaseAuthMode::ServiceAccountFile;
            else
            {
                error = "firebase.auth.mode must be 'application_default' or 'service_account_file'";
                return false;
            }

            parsed.Firebase.ServiceAccountPath = std::move(serviceAccountPath);
        }
        else if (!error.empty())
            return false;
    }
    else if (!error.empty())
        return false;

    if (rapidjson::Value const* conversion = ReadObject(document, "conversion", error))
    {
        if (!ReadString(*conversion, "sourceSchema", parsed.Conversion.SourceSchema, error) ||
            !ReadString(*conversion, "targetSchema", parsed.Conversion.TargetSchema, error))
            return false;
    }
    else if (!error.empty())
        return false;

    if (!Validate(parsed, error))
        return false;

    config = std::move(parsed);
    error.clear();
    return true;
}
}
