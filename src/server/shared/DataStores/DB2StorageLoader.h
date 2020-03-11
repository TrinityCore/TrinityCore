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

#ifndef DB2_FILE_LOADER_H
#define DB2_FILE_LOADER_H

#include "Define.h"
#include "Utilities/ByteConverter.h"
#include <cassert>
#include <list>
#include <string>

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
            float val = *reinterpret_cast<float*>(offset+file.GetOffset(field));
            EndianConvert(val);
            return val;
        }
        uint32 getUInt(size_t field) const
        {
            assert(field < file.fieldCount);
            uint32 val = *reinterpret_cast<uint32*>(offset+file.GetOffset(field));
            EndianConvert(val);
            return val;
        }
        uint8 getUInt8(size_t field) const
        {
            assert(field < file.fieldCount);
            return *reinterpret_cast<uint8*>(offset+file.GetOffset(field));
        }

        const char *getString(size_t field) const
        {
            assert(field < file.fieldCount);
            size_t stringOffset = getUInt(field);
            assert(stringOffset < file.stringSize);
            return reinterpret_cast<char*>(file.stringTable + stringOffset);
        }

    private:
        Record(DB2FileLoader& file_, unsigned char* offset_): offset(offset_), file(file_) {}
        unsigned char *offset;
        DB2FileLoader& file;

        friend class DB2FileLoader;
    };

    // Get record by id
    Record getRecord(size_t id);
    /// Get begin iterator over records

    uint32 GetNumRows() const { return recordCount;}
    uint32 GetCols() const { return fieldCount; }
    uint32 GetOffset(size_t id) const { return (fieldsOffset != nullptr && id < fieldCount) ? fieldsOffset[id] : 0; }
    uint32 GetHash() const { return tableHash; }
    bool IsLoaded() const { return (data != nullptr); }
    char* AutoProduceData(char const* fmt, uint32& count, char**& indexTable);
    char* AutoProduceStringsArrayHolders(char const* fmt, char* dataTable);
    char* AutoProduceStrings(char const* fmt, char* dataTable, uint32 locale);
    static uint32 GetFormatRecordSize(char const* format, int32* index_pos = nullptr);
    static uint32 GetFormatStringFieldCount(const char* format);
private:

    uint32 recordSize;
    uint32 recordCount;
    uint32 fieldCount;
    uint32 stringSize;
    uint32 *fieldsOffset;
    unsigned char *data;
    unsigned char *stringTable;

    // WDB2 / WCH2 fields
    uint32 tableHash;    // WDB2
    uint32 build;        // WDB2

    int unk1;            // WDB2 (Unix time in WCH2)
    int minIndex;        // WDB2
    int maxIndex;        // WDB2 (index table)
    int locale;          // WDB2
    int unk5;            // WDB2
};

class DB2DatabaseLoader
{
public:
    explicit DB2DatabaseLoader(std::string const& storageName) : _storageName(storageName) { }

    char* Load(const char* format, int32 preparedStatement, uint32& records, char**& indexTable, char*& stringHolders, std::list<char*>& stringPool);
    void LoadStrings(const char* format, int32 preparedStatement, uint32 locale, char**& indexTable, std::list<char*>& stringPool);
    static char* AddLocaleString(LocalizedString* holder, uint32 locale, std::string const& value);

private:
    std::string _storageName;
};

#endif
