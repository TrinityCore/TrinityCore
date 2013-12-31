/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include <cstdio>
#include "DBC.h"
#include "Define.h"

DBC::DBC(Stream* stream) : StringBlock(NULL), StringBlockSize(0), IsFaulty(true)
{
    delete[] stream->Read(4); // Read the magic "WDBC"

    RecordCount = stream->Read<int>();
    Records.reserve(RecordCount);
    Fields = stream->Read<int>();
    RecordSize = stream->Read<int>();
    StringBlockSize = stream->Read<uint32>();

    for (int i = 0; i < RecordCount; i++)
    {
        Record* rec = new Record(this);
        Records.push_back(rec);
        int size = 0;
        for (int f = 0; f < Fields; f++)
        {
            if (size + 4 > RecordSize)
            {
                IsFaulty = true;
                break;
            }
            rec->Values.push_back(stream->Read<uint32>());
            size += 4;
        }
    }
    StringBlock = (uint8*)stream->Read(StringBlockSize);
}

DBC::~DBC()
{
    delete[] StringBlock;
    for (std::vector<Record*>::iterator itr = Records.begin(); itr != Records.end(); ++itr)
        delete *itr;
}

std::string DBC::GetStringByOffset( int offset ) const
{
    int len = 0;
    for (uint32 i = offset; i < StringBlockSize; i++)
    {
        if (!StringBlock[i])
        {
            len = (i - offset);
            break;
        }
    }
    char* d = new char[len+1];
    strcpy(d, (const char*)(StringBlock + offset));
    d[len] = '\0';
    std::string val = std::string(d);
    delete[] d;
    return val;
}

Record const* DBC::GetRecordById( int id ) const
{
    // we assume Id is index 0
    for (std::vector<Record*>::const_iterator itr = Records.begin(); itr != Records.end(); ++itr)
        if ((*itr)->Values[0] == id)
            return *itr;
    return NULL;
}
