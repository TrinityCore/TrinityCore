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

#include "Define.h"
#include "Utilities/ByteConverter.h"
#include "Implementation/HotfixDatabase.h"
#include <cassert>
#include <vector>

class TC_SHARED_API DB2FileLoader
{
    public:
    DB2FileLoader();
    ~DB2FileLoader();

    bool Load(const char *filename, const char *fmt);

    class Record
    {
    public:
        float getFloat(size_t field) const
        {
            assert(field < file.fieldCount);
            float val = *reinterpret_cast<float*>(offset + file.GetOffset(field));
            EndianConvert(val);
            return val;
        }
        uint32 getUInt(size_t field) const
        {
            assert(field < file.fieldCount);
            uint32 val = *reinterpret_cast<uint32*>(offset + file.GetOffset(field));
            EndianConvert(val);
            return val;
        }
        uint8 getUInt8(size_t field) const
        {
            assert(field < file.fieldCount);
            return *reinterpret_cast<uint8*>(offset + file.GetOffset(field));
        }
        uint64 getUInt64(size_t field) const
        {
            assert(field < file.fieldCount);
            uint64 val = *reinterpret_cast<uint64*>(offset + file.GetOffset(field));
            EndianConvert(val);
            return val;
        }
        uint16 getUInt16(size_t field) const
        {
            assert(field < file.fieldCount);
            uint16 val = *reinterpret_cast<uint16*>(offset + file.GetOffset(field));
            EndianConvert(val);
            return val;
        }
        const char *getString(size_t field) const
        {
            assert(field < file.fieldCount);
            size_t stringOffset = getUInt(field);
            assert(stringOffset < file.stringSize);
            return reinterpret_cast<char*>(file.stringTable + stringOffset);
        }

    private:
        Record(DB2FileLoader &file_, unsigned char *offset_): offset(offset_), file(file_) {}
        unsigned char *offset;
        DB2FileLoader &file;

        friend class DB2FileLoader;
    };

    // Get record by id
    Record getRecord(size_t id);
    /// Get begin iterator over records

    uint32 GetNumRows() const { return recordCount;}
    uint32 GetCols() const { return fieldCount; }
    uint32 GetOffset(size_t id) const { return (fieldsOffset != NULL && id < fieldCount) ? fieldsOffset[id] : 0; }
    uint32 GetHash() const { return tableHash; }
    uint32 GetBuild() const { return build; }
    bool IsLoaded() const { return (data != NULL); }
    char* AutoProduceData(const char* fmt, uint32& count, char**& indexTable);
    char* AutoProduceStringsArrayHolders(const char* fmt, char* dataTable);
    char* AutoProduceStrings(const char* fmt, char* dataTable, uint32 locale);
    static uint32 GetFormatRecordSize(const char * format, int32 * index_pos = NULL);
    static uint32 GetFormatStringFieldCount(const char * format);
    static uint32 GetFormatLocalizedStringFieldCount(const char * format);
private:
    char const* fileName;

    // WDB2 / WCH2 fields
    uint32 recordSize;
    uint32 recordCount;
    uint32 fieldCount;
    uint32 stringSize;
    uint32 tableHash;
    uint32 build;
    uint32 unk1;
    uint32 minIndex;
    uint32 maxIndex;
    uint32 localeMask;
    uint32 copyIdSize;
    uint32 metaFlags;

    uint32 *fieldsOffset;
    unsigned char* data;
    unsigned char* stringTable;
    unsigned char* idTable;
    uint32 idTableSize;
    unsigned char* copyTable;
};

class TC_SHARED_API DB2DatabaseLoader
{
public:
    explicit DB2DatabaseLoader(std::string const& storageName) : _storageName(storageName) { }

    char* Load(const char* format, HotfixDatabaseStatements preparedStatement, uint32& records, char**& indexTable, char*& stringHolders, std::vector<char*>& stringPool);
    void LoadStrings(const char* format, HotfixDatabaseStatements preparedStatement, uint32 locale, char**& indexTable, std::vector<char*>& stringPool);
    static char* AddString(char const** holder, std::string const& value);

private:
    std::string _storageName;
};

#endif
