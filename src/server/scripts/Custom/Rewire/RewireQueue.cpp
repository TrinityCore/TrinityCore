/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 */

#include "RewireQueue.h"

#include <fstream>
#include <system_error>
#include <utility>

namespace Trinity::Rewire
{
PersistentQueue::PersistentQueue(std::filesystem::path spoolPath, std::size_t capacity)
    : _spoolPath(std::move(spoolPath)), _capacity(capacity)
{
}

bool PersistentQueue::Initialize(std::string& error)
{
    std::lock_guard lock(_mutex);

    std::error_code filesystemError;
    if (std::filesystem::path const parent = _spoolPath.parent_path(); !parent.empty())
        std::filesystem::create_directories(parent, filesystemError);

    if (filesystemError)
    {
        error = "unable to create REWIRE spool directory: " + filesystemError.message();
        return false;
    }

    std::ofstream stream(_spoolPath, std::ios::app);
    if (!stream)
    {
        error = "unable to open REWIRE spool file: " + _spoolPath.generic_string();
        return false;
    }

    error.clear();
    return true;
}

bool PersistentQueue::Enqueue(std::string payload, std::string& error)
{
    std::lock_guard lock(_mutex);

    if (_pending.size() >= _capacity && !FlushLocked(error))
        return false;

    if (_pending.size() >= _capacity)
    {
        error = "REWIRE ingestion queue remains full after flush";
        return false;
    }

    _pending.emplace_back(std::move(payload));
    error.clear();
    return true;
}

bool PersistentQueue::Flush(std::string& error)
{
    std::lock_guard lock(_mutex);
    return FlushLocked(error);
}

std::size_t PersistentQueue::Pending() const
{
    std::lock_guard lock(_mutex);
    return _pending.size();
}

bool PersistentQueue::FlushLocked(std::string& error)
{
    if (_pending.empty())
    {
        error.clear();
        return true;
    }

    std::ofstream stream(_spoolPath, std::ios::app);
    if (!stream)
    {
        error = "unable to append to REWIRE spool file: " + _spoolPath.generic_string();
        return false;
    }

    for (std::string const& payload : _pending)
        stream << payload << '\n';

    stream.flush();
    if (!stream)
    {
        error = "failed while flushing REWIRE spool file: " + _spoolPath.generic_string();
        return false;
    }

    _pending.clear();
    error.clear();
    return true;
}
}
