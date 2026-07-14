/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 */

#include "RewireQueue.h"

#include <algorithm>
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

    _durable.clear();
    _buffered.clear();

    std::ifstream input(_spoolPath);
    if (input)
    {
        for (std::string line; std::getline(input, line);)
        {
            if (!line.empty())
                _durable.emplace_back(std::move(line));
        }

        if (!input.eof())
        {
            error = "failed while reading REWIRE spool file: " + _spoolPath.generic_string();
            return false;
        }
    }

    std::ofstream output(_spoolPath, std::ios::app);
    if (!output)
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

    if (_buffered.size() >= _capacity && !FlushLocked(error))
        return false;

    if (_buffered.size() >= _capacity)
    {
        error = "REWIRE ingestion buffer remains full after flush";
        return false;
    }

    _buffered.emplace_back(std::move(payload));
    error.clear();
    return true;
}

bool PersistentQueue::Flush(std::string& error)
{
    std::lock_guard lock(_mutex);
    return FlushLocked(error);
}

std::vector<std::string> PersistentQueue::PeekBatch(std::size_t maxItems) const
{
    std::lock_guard lock(_mutex);

    std::size_t const count = std::min(maxItems, _durable.size());
    std::vector<std::string> batch;
    batch.reserve(count);

    auto itr = _durable.begin();
    for (std::size_t index = 0; index < count; ++index, ++itr)
        batch.push_back(*itr);

    return batch;
}

bool PersistentQueue::Acknowledge(std::size_t count, std::string& error)
{
    std::lock_guard lock(_mutex);

    if (count > _durable.size())
    {
        error = "REWIRE acknowledgement count exceeds durable backlog";
        return false;
    }

    for (std::size_t index = 0; index < count; ++index)
        _durable.pop_front();

    return RewriteSpoolLocked(error);
}

std::size_t PersistentQueue::Pending() const
{
    std::lock_guard lock(_mutex);
    return _durable.size() + _buffered.size();
}

std::size_t PersistentQueue::Buffered() const
{
    std::lock_guard lock(_mutex);
    return _buffered.size();
}

bool PersistentQueue::FlushLocked(std::string& error)
{
    if (_buffered.empty())
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

    for (std::string const& payload : _buffered)
        stream << payload << '\n';

    stream.flush();
    if (!stream)
    {
        error = "failed while flushing REWIRE spool file: " + _spoolPath.generic_string();
        return false;
    }

    while (!_buffered.empty())
    {
        _durable.emplace_back(std::move(_buffered.front()));
        _buffered.pop_front();
    }

    error.clear();
    return true;
}

bool PersistentQueue::RewriteSpoolLocked(std::string& error)
{
    std::filesystem::path const temporaryPath = _spoolPath.string() + ".tmp";

    {
        std::ofstream stream(temporaryPath, std::ios::trunc);
        if (!stream)
        {
            error = "unable to create REWIRE spool temporary file: " + temporaryPath.generic_string();
            return false;
        }

        for (std::string const& payload : _durable)
            stream << payload << '\n';

        stream.flush();
        if (!stream)
        {
            error = "failed while writing REWIRE spool temporary file: " + temporaryPath.generic_string();
            return false;
        }
    }

    std::error_code filesystemError;
    std::filesystem::rename(temporaryPath, _spoolPath, filesystemError);
    if (filesystemError)
    {
        std::filesystem::remove(_spoolPath, filesystemError);
        filesystemError.clear();
        std::filesystem::rename(temporaryPath, _spoolPath, filesystemError);
    }

    if (filesystemError)
    {
        std::filesystem::remove(temporaryPath);
        error = "unable to replace REWIRE spool file: " + filesystemError.message();
        return false;
    }

    error.clear();
    return true;
}
}
