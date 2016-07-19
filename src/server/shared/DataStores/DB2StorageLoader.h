/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DB2_FILE_LOADER_H
#define DB2_FILE_LOADER_H

#include "DB2Meta.h"
#include "Utilities/ByteConverter.h"
#include "Implementation/HotfixDatabase.h"
#include "Errors.h"
#include <vector>

class TC_SHARED_API DB2FileLoader
{
    public:
    DB2FileLoader();
    ~DB2FileLoader();

    bool Load(char const* filename, DB2Meta const* meta);

    class Record
    {
    public:
        float getFloat(uint32 field, uint32 arrayIndex) const
        {
            ASSERT(field < file.fieldCount);
            float val = *reinterpret_cast<float*>(offset + GetOffset(field) + arrayIndex * sizeof(float));
            EndianConvert(val);
            return val;
        }

        uint32 getUInt(uint32 field, uint32 arrayIndex) const
        {
            ASSERT(field < file.fieldCount);
            return GetVarInt(field, GetByteSize(field), arrayIndex);
        }

        uint8 getUInt8(uint32 field, uint32 arrayIndex) const
        {
            ASSERT(field < file.fieldCount);
            ASSERT(GetByteSize(field) == 1);
            return *reinterpret_cast<uint8*>(offset + GetOffset(field) + arrayIndex * sizeof(uint8));
        }

        uint16 getUInt16(uint32 field, uint32 arrayIndex) const
        {
            ASSERT(field < file.fieldCount);
            ASSERT(GetByteSize(field) == 2);
            uint16 val = *reinterpret_cast<uint16*>(offset + GetOffset(field) + arrayIndex * sizeof(uint16));
            EndianConvert(val);
            return val;
        }

        char const* getString(uint32 field, uint32 arrayIndex) const
        {
            ASSERT(field < file.fieldCount);
            uint32 stringOffset = *reinterpret_cast<uint32*>(offset + GetOffset(field) + arrayIndex * sizeof(uint32));
            EndianConvert(stringOffset);
            ASSERT(stringOffset < file.stringSize);
            return reinterpret_cast<char*>(file.stringTable + stringOffset);
        }

    private:
        uint16 GetOffset(uint32 field) const
        {
            ASSERT(field < file.fieldCount);
            return file.fields[field].Offset;
        }

        uint16 GetByteSize(uint32 field) const
        {
            ASSERT(field < file.fieldCount);
            return 4 - file.fields[field].UnusedBits / 8;
        }

        uint32 GetVarInt(uint32 field, uint16 size, uint32 arrayIndex) const
        {
            ASSERT(field < file.fieldCount);
            switch (size)
            {
                case 1:
                {
                    return *reinterpret_cast<uint8*>(offset + GetOffset(field) + arrayIndex * sizeof(uint8));
                }
                case 2:
                {
                    uint16 val = *reinterpret_cast<uint16*>(offset + GetOffset(field) + arrayIndex * sizeof(uint16));
                    EndianConvert(val);
                    return val;
                }
                case 3:
                {
#pragma pack(push, 1)
                    struct dbcint24 { uint8 v[3]; };
#pragma pack(pop)
                    dbcint24 val = *reinterpret_cast<dbcint24*>(offset + GetOffset(field) + arrayIndex * sizeof(dbcint24));
                    EndianConvert(val);
                    return uint32(val.v[0]) | (uint32(val.v[1]) << 8) | (uint32(val.v[2]) << 16);
                }
                case 4:
                {
                    uint32 val = *reinterpret_cast<uint32*>(offset + GetOffset(field) + arrayIndex * sizeof(uint32));
                    EndianConvert(val);
                    return val;
                }
                default:
                    break;
            }

            ASSERT(false, "GetByteSize(field) < 4");
            return 0;
        }

        Record(DB2FileLoader &file_, unsigned char *offset_): offset(offset_), file(file_) {}
        unsigned char *offset;
        DB2FileLoader &file;

        friend class DB2FileLoader;
    };

    // Get record by id
    Record getRecord(size_t id);

    uint32 GetNumRows() const { return recordCount;}
    uint32 GetCols() const { return fieldCount; }
    uint32 GetTableHash() const { return tableHash; }
    uint32 GetLayoutHash() const { return layoutHash; }
    bool IsLoaded() const { return (data != NULL); }
    char* AutoProduceData(uint32& count, char**& indexTable);
    char* AutoProduceStringsArrayHolders(char* dataTable);
    char* AutoProduceStrings(char* dataTable, uint32 locale);
    void AutoProduceRecordCopies(uint32 records, char** indexTable, char* dataTable);

private:
#pragma pack(push, 1)
    struct FieldEntry
    {
        uint16 UnusedBits;
        uint16 Offset;
    };
#pragma pack(pop)

    char const* fileName;
    DB2Meta const* meta;

    // WDB2 / WCH2 fields
    uint32 recordSize;
    uint32 recordCount;
    uint32 fieldCount;
    uint32 stringSize;
    uint32 tableHash;
    uint32 layoutHash;
    uint32 minIndex;
    uint32 maxIndex;
    uint32 localeMask;
    uint32 copyIdSize;
    uint32 metaFlags;

    unsigned char* data;
    unsigned char* stringTable;
    unsigned char* idTable;
    uint32 idTableSize;
    unsigned char* copyTable;
    FieldEntry* fields;
};

class TC_SHARED_API DB2DatabaseLoader
{
public:
    DB2DatabaseLoader(std::string const& storageName, DB2Meta const* meta) : _storageName(storageName), _meta(meta) { }

    char* Load(HotfixDatabaseStatements preparedStatement, uint32& records, char**& indexTable, char*& stringHolders, std::vector<char*>& stringPool);
    void LoadStrings(HotfixDatabaseStatements preparedStatement, uint32 locale, uint32 records, char** indexTable, std::vector<char*>& stringPool);
    static char* AddString(char const** holder, std::string const& value);

private:
    std::string _storageName;
    DB2Meta const* _meta;
};

#endif
