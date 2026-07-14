/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 */

#include "RewireFirestoreConverter.h"

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

#include <sstream>

namespace Trinity::Rewire
{
namespace
{
void WriteStringValue(rapidjson::Writer<rapidjson::StringBuffer>& writer, char const* value)
{
    writer.StartObject();
    writer.Key("stringValue");
    writer.String(value);
    writer.EndObject();
}

void WriteIntegerValue(rapidjson::Writer<rapidjson::StringBuffer>& writer, std::uint64_t value)
{
    writer.StartObject();
    writer.Key("integerValue");
    writer.String(std::to_string(value).c_str());
    writer.EndObject();
}

bool ReadRequiredString(rapidjson::Value const& object, char const* name, std::string& value, std::string& error)
{
    auto member = object.FindMember(name);
    if (member == object.MemberEnd() || !member->value.IsString())
    {
        error = std::string("source event field '") + name + "' must be a string";
        return false;
    }

    value.assign(member->value.GetString(), member->value.GetStringLength());
    return true;
}

bool ReadRequiredUint64(rapidjson::Value const& object, char const* name, std::uint64_t& value, std::string& error)
{
    auto member = object.FindMember(name);
    if (member == object.MemberEnd() || !member->value.IsUint64())
    {
        error = std::string("source event field '") + name + "' must be an unsigned integer";
        return false;
    }

    value = member->value.GetUint64();
    return true;
}
}

bool FirestoreConverter::Convert(std::string_view sourceEvent, RewireConfig const& config, std::string& output, std::string& error)
{
    rapidjson::Document source;
    source.Parse(sourceEvent.data(), sourceEvent.size());
    if (source.HasParseError())
    {
        std::ostringstream message;
        message << "invalid source event JSON at offset " << source.GetErrorOffset() << ": "
                << rapidjson::GetParseError_En(source.GetParseError());
        error = message.str();
        return false;
    }

    if (!source.IsObject())
    {
        error = "source event root must be an object";
        return false;
    }

    std::string schema;
    std::string targetSchema;
    std::string nodeId;
    std::string eventName;
    std::uint64_t shardCount = 0;
    std::uint64_t timestampMs = 0;

    if (!ReadRequiredString(source, "schema", schema, error) ||
        !ReadRequiredString(source, "targetSchema", targetSchema, error) ||
        !ReadRequiredString(source, "nodeId", nodeId, error) ||
        !ReadRequiredString(source, "event", eventName, error) ||
        !ReadRequiredUint64(source, "shardCount", shardCount, error) ||
        !ReadRequiredUint64(source, "timestampMs", timestampMs, error))
        return false;

    if (schema != config.Conversion.SourceSchema)
    {
        error = "source schema does not match configured conversion sourceSchema";
        return false;
    }

    if (targetSchema != config.Conversion.TargetSchema)
    {
        error = "target schema does not match configured conversion targetSchema";
        return false;
    }

    auto player = source.FindMember("player");
    if (player == source.MemberEnd() || !player->value.IsObject())
    {
        error = "source event field 'player' must be an object";
        return false;
    }

    std::uint64_t guid = 0;
    std::uint64_t level = 0;
    std::uint64_t mapId = 0;
    std::string playerName;
    if (!ReadRequiredUint64(player->value, "guid", guid, error) ||
        !ReadRequiredString(player->value, "name", playerName, error) ||
        !ReadRequiredUint64(player->value, "level", level, error) ||
        !ReadRequiredUint64(player->value, "mapId", mapId, error))
        return false;

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

    writer.StartObject();
    writer.Key("document");
    writer.StartObject();
    writer.Key("name");
    std::string const documentName = "projects/" + config.Firebase.ProjectId + "/databases/" +
        config.Firebase.DatabaseId + "/documents/" + config.Firebase.Collection + "/" + std::to_string(guid);
    writer.String(documentName.c_str());
    writer.Key("fields");
    writer.StartObject();

    writer.Key("schema");
    WriteStringValue(writer, schema.c_str());
    writer.Key("targetSchema");
    WriteStringValue(writer, targetSchema.c_str());
    writer.Key("nodeId");
    WriteStringValue(writer, nodeId.c_str());
    writer.Key("event");
    WriteStringValue(writer, eventName.c_str());
    writer.Key("shardCount");
    WriteIntegerValue(writer, shardCount);
    writer.Key("timestampMs");
    WriteIntegerValue(writer, timestampMs);
    writer.Key("playerGuid");
    WriteIntegerValue(writer, guid);
    writer.Key("playerName");
    WriteStringValue(writer, playerName.c_str());
    writer.Key("playerLevel");
    WriteIntegerValue(writer, level);
    writer.Key("mapId");
    WriteIntegerValue(writer, mapId);

    writer.EndObject();
    writer.EndObject();
    writer.Key("currentDocument");
    writer.StartObject();
    writer.Key("exists");
    writer.Bool(false);
    writer.EndObject();
    writer.EndObject();

    output.assign(buffer.GetString(), buffer.GetSize());
    error.clear();
    return true;
}
}
