/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DBC_H
#define DBC_H
#include <vector>
#include <string>
#include "Define.h"
#include "Stream.h"

class Record;

class DBC
{
public:
    DBC(Stream* stream);
    ~DBC();

    std::string GetStringByOffset(int offset) const;

    Record const* GetRecordById(int id) const;

    std::string Name;
    std::vector<Record*> Records;
    int RecordCount;
    int Fields;
    int RecordSize;
    uint8* StringBlock;
    uint32 StringBlockSize;
    bool IsFaulty;
};

class Record
{
public:
    Record(DBC* dbc) : Source(dbc) {}

    DBC* Source;
    std::vector<int> Values;

    int operator[](int index) const
    {
        return Values[index];
    }

    template <typename T>
    T GetValue(int index) const
    {
        return *(T*)(&Values[index]);
    }

    const std::string GetString(int index) const
    {
        return Source->GetStringByOffset(Values[index]);
    }
};

#endif