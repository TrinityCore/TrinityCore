/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 */

#ifndef TRINITYCORE_REWIRE_QUEUE_H
#define TRINITYCORE_REWIRE_QUEUE_H

#include <cstddef>
#include <deque>
#include <filesystem>
#include <mutex>
#include <string>

namespace Trinity::Rewire
{
class PersistentQueue final
{
public:
    PersistentQueue(std::filesystem::path spoolPath, std::size_t capacity);

    bool Initialize(std::string& error);
    bool Enqueue(std::string payload, std::string& error);
    bool Flush(std::string& error);

    std::size_t Pending() const;
    std::filesystem::path const& GetSpoolPath() const { return _spoolPath; }

private:
    bool FlushLocked(std::string& error);

    std::filesystem::path _spoolPath;
    std::size_t _capacity;
    mutable std::mutex _mutex;
    std::deque<std::string> _pending;
};
}

#endif // TRINITYCORE_REWIRE_QUEUE_H
