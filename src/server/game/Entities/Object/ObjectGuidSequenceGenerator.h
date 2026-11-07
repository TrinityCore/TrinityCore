/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef TRINITYCORE_OBJECT_GUID_SEQUENCE_GENERATOR_H
#define TRINITYCORE_OBJECT_GUID_SEQUENCE_GENERATOR_H

#include "ObjectGuid.h"
#include <atomic>

class ObjectGuidGenerator
{
public:
    explicit ObjectGuidGenerator(HighGuid high, ObjectGuid::LowType start = UI64LIT(1)) : _nextGuid(start), _high(high) { }

    void Set(ObjectGuid::LowType val) { _nextGuid = val; }
    ObjectGuid::LowType Generate();
    ObjectGuid::LowType GetNextAfterMaxUsed() const { return _nextGuid; }

private:
    std::atomic<ObjectGuid::LowType> _nextGuid;
    HighGuid _high;
};

#endif // TRINITYCORE_OBJECT_GUID_SEQUENCE_GENERATOR_H
