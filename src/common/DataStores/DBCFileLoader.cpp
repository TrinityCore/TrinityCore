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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits>
#include <cstring>

#include "DBCFileLoader.h"
#include "Errors.h"

DBCFileLoader::DBCFileLoader() : recordSize(0), recordCount(0), fieldCount(0), stringSize(0), fieldsOffset(nullptr), data(nullptr), stringTable(nullptr) { }

bool DBCFileLoader::Load(char const* filename, char const* fmt)
{
    uint32 header;
    if (data)
    {
        delete [] data;
        data = nullptr;
    }

    FILE* f = fopen(filename, "rb");
    if (!f)
        return false;

    if (fread(&header, 4, 1, f) != 1)                        // Number of records
    {
        fclose(f);
        return false;
    }


    EndianConvert(header);

    if (header != 0x43424457)                                //'WDBC'
    {
        fclose(f);
        return false;
    }

    if (fread(&recordCount, 4, 1, f) != 1)                   // Number of records
    {
        fclose(f);
        return false;
    }

    EndianConvert(recordCount);

    if (fread(&fieldCount, 4, 1, f) != 1)                    // Number of fields
    {
        fclose(f);
        return false;
    }

    EndianConvert(fieldCount);

    if (fread(&recordSize, 4, 1, f) != 1)                    // Size of a record
    {
        fclose(f);
        return false;
    }

    EndianConvert(recordSize);

    if (fread(&stringSize, 4, 1, f) != 1)                    // String size
    {
        fclose(f);
        return false;
    }

    EndianConvert(stringSize);

    fieldsOffset = new uint32[fieldCount];
    fieldsOffset[0] = 0;
    for (uint32 i = 1; i < fieldCount; ++i)
    {
        fieldsOffset[i] = fieldsOffset[i - 1];
        if (fmt[i - 1] == FT_BYTE || fmt[i - 1] == FT_NA_BYTE)  // byte fields
            fieldsOffset[i] += sizeof(uint8);
        else if (fmt[i - 1] == FT_LONG)
            fieldsOffset[i] += sizeof(uint64);
        else                                                // 4 byte fields (int32/float/strings)
            fieldsOffset[i] += sizeof(uint32);
    }

    data = new unsigned char[recordSize * recordCount + stringSize];
    stringTable = data + recordSize*recordCount;

    if (fread(data, recordSize * recordCount + stringSize, 1, f) != 1)
    {
        fclose(f);
        return false;
    }

    fclose(f);

    return true;
}

DBCFileLoader::~DBCFileLoader()
{
    delete[] data;

    delete[] fieldsOffset;
}

DBCFileLoader::Record DBCFileLoader::getRecord(size_t id)
{
    ASSERT(data);
    return Record(*this, data + id * recordSize);
}

uint32 DBCFileLoader::GetFormatRecordSize(char const* format, int32* index_pos)
{
    uint32 recordsize = 0;
    int32 i = -1;
    for (uint32 x = 0; format[x]; ++x)
    {
        switch (format[x])
        {
            case FT_FLOAT:
                recordsize += sizeof(float);
                break;
            case FT_INT:
                recordsize += sizeof(uint32);
                break;
            case FT_STRING:
                recordsize += sizeof(char*);
                break;
            case FT_SORT:
                i = x;
                break;
            case FT_IND:
                i = x;
                recordsize += sizeof(uint32);
                break;
            case FT_BYTE:
                recordsize += sizeof(uint8);
                break;
            case FT_LONG:
                recordsize += sizeof(uint64);
                break;
            case FT_NA:
            case FT_NA_BYTE:
                break;
            default:
                ASSERT(false && "Unknown field format character in DBCfmt.h");
                break;
        }
    }

    if (index_pos)
        *index_pos = i;

    return recordsize;
}

char* DBCFileLoader::AutoProduceData(char const* format, uint32& records, char**& indexTable)
{
    /*
    format STRING, NA, FLOAT, NA, INT <=>
    struct{
    char* field0,
    float field1,
    int field2
    }entry;

    this func will generate  entry[rows] data;
    */

    typedef char* ptr;
    if (strlen(format) != fieldCount)
        return nullptr;

    //get struct size and index pos
    int32 i;
    uint32 recordsize = GetFormatRecordSize(format, &i);

    if (i >= 0)
    {
        uint32 maxi = 0;
        //find max index
        for (uint32 y = 0; y < recordCount; ++y)
        {
            uint32 ind = getRecord(y).getUInt(i);
            if (ind > maxi)
                maxi = ind;
        }

        ++maxi;
        records = maxi;
        indexTable = new ptr[maxi];
        memset(indexTable, 0, maxi * sizeof(ptr));
    }
    else
    {
        records = recordCount;
        indexTable = new ptr[recordCount];
    }

    char* dataTable = new char[recordCount * recordsize];

    uint32 offset = 0;

    for (uint32 y = 0; y < recordCount; ++y)
    {
        if (i >= 0)
            indexTable[getRecord(y).getUInt(i)] = &dataTable[offset];
        else
            indexTable[y] = &dataTable[offset];

        for (uint32 x=0; x < fieldCount; ++x)
        {
            switch (format[x])
            {
                case FT_FLOAT:
                    *((float*)(&dataTable[offset])) = getRecord(y).getFloat(x);
                    offset += sizeof(float);
                    break;
                case FT_IND:
                case FT_INT:
                    *((uint32*)(&dataTable[offset])) = getRecord(y).getUInt(x);
                    offset += sizeof(uint32);
                    break;
                case FT_BYTE:
                    *((uint8*)(&dataTable[offset])) = getRecord(y).getUInt8(x);
                    offset += sizeof(uint8);
                    break;
                case FT_LONG:
                    *((uint64*)(&dataTable[offset])) = getRecord(y).getUInt64(x);
                    offset += sizeof(uint64);
                    break;
                case FT_STRING:
                    *((char**)(&dataTable[offset])) = nullptr;   // will replace non-empty or "" strings in AutoProduceStrings
                    offset += sizeof(char*);
                    break;
                case FT_NA:
                case FT_NA_BYTE:
                case FT_SORT:
                    break;
                default:
                    ASSERT(false && "Unknown field format character in DBCfmt.h");
                    break;
            }
        }
    }

    return dataTable;
}

char* DBCFileLoader::AutoProduceStrings(char const* format, char* dataTable)
{
    if (strlen(format) != fieldCount)
        return nullptr;

    char* stringPool = new char[stringSize];
    memcpy(stringPool, stringTable, stringSize);

    uint32 offset = 0;

    for (uint32 y = 0; y < recordCount; ++y)
    {
        for (uint32 x = 0; x < fieldCount; ++x)
        {
            switch (format[x])
            {
                case FT_FLOAT:
                    offset += sizeof(float);
                    break;
                case FT_IND:
                case FT_INT:
                    offset += sizeof(uint32);
                    break;
                case FT_BYTE:
                    offset += sizeof(uint8);
                    break;
                case FT_LONG:
                    offset += sizeof(uint64);
                    break;
                case FT_STRING:
                {
                    // fill only not filled entries
                    char** slot = (char**)(&dataTable[offset]);
                    if (!*slot || !**slot)
                    {
                        const char * st = getRecord(y).getString(x);
                        *slot = stringPool + (st - (char const*)stringTable);
                    }
                    offset += sizeof(char*);
                    break;
                 }
                 case FT_NA:
                 case FT_NA_BYTE:
                 case FT_SORT:
                     break;
                 default:
                     ASSERT(false && "Unknown field format character in DBCfmt.h");
                     break;
            }
        }
    }

    return stringPool;
}
