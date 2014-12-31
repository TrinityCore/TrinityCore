/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

DBC::DBC( FILE* stream ) : StringBlock(NULL), StringBlockSize(0), IsFaulty(true)
{
    char magic[5];
    uint32 count = 0;
    count += fread(&magic, sizeof(char), 4, stream);
    magic[4] = '\0';
    count += fread(&RecordCount, sizeof(uint32), 1, stream);
    Records.reserve(RecordCount);
    count += fread(&Fields, sizeof(uint32), 1, stream);
    count += fread(&RecordSize, sizeof(uint32), 1, stream);
    count += fread(&StringBlockSize, sizeof(uint32), 1, stream);
    if (count != 8)
        printf("DBC::DBC: Failed to read some data expected 8, read %u\n", count);

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
            uint32 tmp;
            if (fread(&tmp, sizeof(uint32), 1, stream) != 1)
                printf("DBC::DBC: Failed to read some data expected 1, read 0\n");
            rec->Values.push_back(tmp);
            size += 4;
        }
    }
    StringBlock = new uint8[StringBlockSize];
    count = fread(StringBlock, sizeof(uint8), StringBlockSize, stream);
    if (count != StringBlockSize)
        printf("DBC::DBC: Failed to read some data expected %u, read %u\n", StringBlockSize, count);
}

std::string DBC::GetStringByOffset( int offset )
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
    delete [] d;
    return val;
}

Record* DBC::GetRecordById( int id )
{
    // we assume Id is index 0
    for (std::vector<Record*>::iterator itr = Records.begin(); itr != Records.end(); ++itr)
        if ((*itr)->Values[0] == id)
            return *itr;
    return NULL;
}
