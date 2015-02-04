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

#ifndef DB2STORE_H
#define DB2STORE_H

#include "Common.h"
#include "DB2StorageLoader.h"
#include "ByteBuffer.h"

/// Interface class for common access
class DB2StorageBase
{
public:
    virtual ~DB2StorageBase() { }

    uint32 GetHash() const { return tableHash; }

    virtual bool HasRecord(uint32 id) const = 0;

    virtual void WriteRecord(uint32 id, uint32 locale, ByteBuffer& buffer) const = 0;

protected:
    uint32 tableHash;
};

template<class T>
class DB2Storage;

template<class T>
bool DB2StorageHasEntry(DB2Storage<T> const& store, uint32 id)
{
    return store.LookupEntry(id) != NULL;
}

template<class T>
void WriteDB2RecordToPacket(DB2Storage<T> const& store, uint32 id, uint32 locale, ByteBuffer& buffer)
{
    uint8 const* entry = (uint8 const*)store.LookupEntry(id);
    ASSERT(entry);

    std::string format = store.GetFormat();
    for (uint32 i = 0; i < format.length(); ++i)
    {
        switch (format[i])
        {
            case FT_IND:
            case FT_INT:
                buffer << *(uint32*)entry;
                entry += 4;
                break;
            case FT_FLOAT:
                buffer << *(float*)entry;
                entry += 4;
                break;
            case FT_BYTE:
                buffer << *(uint8*)entry;
                entry += 1;
                break;
            case FT_STRING:
            {
                LocalizedString* locStr = *(LocalizedString**)entry;
                if (locStr->Str[locale][0] == '\0')
                    locale = 0;

                char const* str = locStr->Str[locale];
                size_t len = strlen(str);
                buffer << uint16(len);
                buffer.WriteString(str, len);
                entry += sizeof(char*);
                break;
            }
            case FT_NA:
            case FT_SORT:
                buffer << uint32(0);
                break;
            case FT_NA_BYTE:
                buffer << uint8(0);
                break;
        }
    }
}

template<class T>
class DB2Storage : public DB2StorageBase
{
    typedef std::list<char*> StringPoolList;
    typedef bool(*EntryChecker)(DB2Storage<T> const&, uint32);
    typedef void(*PacketWriter)(DB2Storage<T> const&, uint32, uint32, ByteBuffer&);
public:
    DB2Storage(char const* f, int32 preparedStmtIndex = -1, EntryChecker checkEntry = nullptr, PacketWriter writePacket = nullptr)
        : nCount(0), fieldCount(0), fmt(f), m_dataTable(nullptr), m_dataTableEx(nullptr), _hotfixStatement(preparedStmtIndex)
    {
        indexTable.asT = NULL;
        CheckEntry = checkEntry ? checkEntry : (EntryChecker)&DB2StorageHasEntry<T>;
        WritePacket = writePacket ? writePacket : (PacketWriter)&WriteDB2RecordToPacket<T>;
    }

    ~DB2Storage() { Clear(); }

    bool HasRecord(uint32 id) const { return CheckEntry(*this, id); }
    T const* LookupEntry(uint32 id) const { return (id >= nCount) ? NULL : indexTable.asT[id]; }
    uint32 GetNumRows() const { return nCount; }
    char const* GetFormat() const { return fmt; }
    uint32 GetFieldCount() const { return fieldCount; }
    void WriteRecord(uint32 id, uint32 locale, ByteBuffer& buffer) const
    {
        WritePacket(*this, id, locale, buffer);
    }

    bool Load(char const* fn, uint32 locale)
    {
        DB2FileLoader db2;
        // Check if load was successful, only then continue
        if (!db2.Load(fn, fmt))
            return false;

        fieldCount = db2.GetCols();
        tableHash = db2.GetHash();

        // load raw non-string data
        m_dataTable = reinterpret_cast<T*>(db2.AutoProduceData(fmt, nCount, indexTable.asChar));

        // create string holders for loaded string fields
        if (char* stringHolders = db2.AutoProduceStringsArrayHolders(fmt, (char*)m_dataTable))
        {
            m_stringPoolList.push_back(stringHolders);

            // load strings from db2 data
            if (char* stringBlock = db2.AutoProduceStrings(fmt, (char*)m_dataTable, locale))
                m_stringPoolList.push_back(stringBlock);
        }

        // error in db2 file at loading if NULL
        return indexTable.asT != NULL;
    }

    bool LoadStringsFrom(char const* fn, uint32 locale)
    {
        // DB2 must be already loaded using Load
        if (!indexTable.asT)
            return false;

        DB2FileLoader db2;
        // Check if load was successful, only then continue
        if (!db2.Load(fn, fmt))
            return false;

        // load strings from another locale db2 data
        if (DB2FileLoader::GetFormatStringFieldCount(fmt))
            if (char* stringBlock = db2.AutoProduceStrings(fmt, (char*)m_dataTable, locale))
                m_stringPoolList.push_back(stringBlock);
        return true;
    }

    void LoadFromDB()
    {
        if (_hotfixStatement == -1)
            return;

        char* extraStringHolders = nullptr;
        if (char* dataTable = DB2DatabaseLoader().Load(fmt, _hotfixStatement, nCount, indexTable.asChar, extraStringHolders, m_stringPoolList))
            m_dataTableEx = reinterpret_cast<T*>(dataTable);

        if (extraStringHolders)
            m_stringPoolList.push_back(extraStringHolders);
    }

    void LoadStringsFromDB(uint32 locale)
    {
        if (_hotfixStatement == -1)
            return;

        if (!DB2FileLoader::GetFormatStringFieldCount(fmt))
            return;

        DB2DatabaseLoader().LoadStrings(fmt, _hotfixStatement + locale, locale, indexTable.asChar, m_stringPoolList);
    }

    void Clear()
    {
        if (!indexTable.asT)
            return;

        delete[] reinterpret_cast<char*>(indexTable.asT);
        indexTable.asT = nullptr;

        delete[] reinterpret_cast<char*>(m_dataTable);
        m_dataTable = nullptr;

        delete[] reinterpret_cast<char*>(m_dataTableEx);
        m_dataTableEx = nullptr;

        while (!m_stringPoolList.empty())
        {
            delete[] m_stringPoolList.front();
            m_stringPoolList.pop_front();
        }

        nCount = 0;
    }

    EntryChecker CheckEntry;
    PacketWriter WritePacket;

private:
    uint32 nCount;
    uint32 fieldCount;
    char const* fmt;
    union
    {
        T** asT;
        char** asChar;
    } indexTable;
    T* m_dataTable;
    T* m_dataTableEx;
    StringPoolList m_stringPoolList;
    int32 _hotfixStatement;
};

#endif
