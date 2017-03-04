/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef MapExtractor_DB2_h__
#define MapExtractor_DB2_h__

#include "DB2Meta.h"
#include "CascHandles.h"
#include "CascLib.h"
#include "Utilities/ByteConverter.h"
#include "Errors.h"

class DB2FileLoader
{
    public:
    DB2FileLoader();
    ~DB2FileLoader();

    bool Load(CASC::FileHandle const& db2Handle, DB2Meta const* meta);

    class Record
    {
    public:
        float getFloat(std::uint32_t field, std::uint32_t arrayIndex) const
        {
            ASSERT(field < file.fieldCount);
            float val = *reinterpret_cast<float*>(offset + GetOffset(field) + arrayIndex * sizeof(float));
            EndianConvert(val);
            return val;
        }

        std::uint32_t getUInt(std::uint32_t field, std::uint32_t arrayIndex) const
        {
            ASSERT(field < file.fieldCount);
            return GetVarInt(field, GetByteSize(field), arrayIndex);
        }

        std::uint8_t getUInt8(std::uint32_t field, std::uint32_t arrayIndex) const
        {
            ASSERT(field < file.fieldCount);
            ASSERT(GetByteSize(field) == 1);
            return *reinterpret_cast<std::uint8_t*>(offset + GetOffset(field) + arrayIndex * sizeof(std::uint8_t));
        }

        std::uint16_t getUInt16(std::uint32_t field, std::uint32_t arrayIndex) const
        {
            ASSERT(field < file.fieldCount);
            ASSERT(GetByteSize(field) == 2);
            std::uint16_t val = *reinterpret_cast<std::uint16_t*>(offset + GetOffset(field) + arrayIndex * sizeof(std::uint16_t));
            EndianConvert(val);
            return val;
        }

        char const* getString(std::uint32_t field, std::uint32_t arrayIndex) const
        {
            ASSERT(field < file.fieldCount);
            std::uint32_t stringOffset = *reinterpret_cast<std::uint32_t*>(offset + GetOffset(field) + arrayIndex * sizeof(std::uint32_t));
            EndianConvert(stringOffset);
            ASSERT(stringOffset < file.stringSize);
            return reinterpret_cast<char*>(file.stringTable + stringOffset);
        }

    private:
        std::uint16_t GetOffset(std::uint32_t field) const
        {
            ASSERT(field < file.fieldCount);
            return file.fields[field].Offset;
        }

        std::uint16_t GetByteSize(std::uint32_t field) const
        {
            ASSERT(field < file.fieldCount);
            return 4 - file.fields[field].UnusedBits / 8;
        }

        std::uint32_t GetVarInt(std::uint32_t field, std::uint16_t size, std::uint32_t arrayIndex) const
        {
            ASSERT(field < file.fieldCount);
            switch (size)
            {
                case 1:
                {
                    return *reinterpret_cast<std::uint8_t*>(offset + GetOffset(field) + arrayIndex * sizeof(std::uint8_t));
                }
                case 2:
                {
                    std::uint16_t val = *reinterpret_cast<std::uint16_t*>(offset + GetOffset(field) + arrayIndex * sizeof(std::uint16_t));
                    EndianConvert(val);
                    return val;
                }
                case 3:
                {
#pragma pack(push, 1)
                    struct dbcint24 { std::uint8_t v[3]; };
#pragma pack(pop)
                    dbcint24 val = *reinterpret_cast<dbcint24*>(offset + GetOffset(field) + arrayIndex * sizeof(dbcint24));
                    EndianConvert(val);
                    return std::uint32_t(val.v[0]) | (std::uint32_t(val.v[1]) << 8) | (std::uint32_t(val.v[2]) << 16);
                }
                case 4:
                {
                    std::uint32_t val = *reinterpret_cast<std::uint32_t*>(offset + GetOffset(field) + arrayIndex * sizeof(std::uint32_t));
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
    std::uint32_t getId(size_t row) { return ((std::uint32_t*)idTable)[row]; }
    std::pair<std::uint32_t, std::uint32_t> GetRowCopy(std::uint32_t i) const;

    std::uint32_t GetNumRows() const { return recordCount; }
    std::uint32_t GetNumRowCopies() const { return copyIdSize / 8; }
    std::uint32_t GetMaxId() const;

private:
#pragma pack(push, 1)
    struct FieldEntry
    {
        std::uint16_t UnusedBits;
        std::uint16_t Offset;
    };
#pragma pack(pop)

    DB2Meta const* meta;

    // WDB2 / WCH2 fields
    std::uint32_t recordSize;
    std::uint32_t recordCount;
    std::uint32_t fieldCount;
    std::uint32_t stringSize;
    std::uint32_t tableHash;
    std::uint32_t layoutHash;
    std::uint32_t minIndex;
    std::uint32_t maxIndex;
    std::uint32_t localeMask;
    std::uint32_t copyIdSize;
    std::uint32_t metaFlags;

    unsigned char* data;
    unsigned char* stringTable;
    unsigned char* idTable;
    std::uint32_t idTableSize;
    unsigned char* copyTable;
    FieldEntry* fields;
};

#endif // MapExtractor_DB2_h__
