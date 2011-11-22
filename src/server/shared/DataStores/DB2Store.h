/*
 * Copyright (C) 2011 TrintiyCore <http://www.trinitycore.org/>
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

#include "DB2FileLoader.h"
#include "DB2fmt.h"
#include "Logging/Log.h"
#include "Field.h"
#include "DatabaseWorkerPool.h"
#include "Implementation/WorldDatabase.h"
#include "DatabaseEnv.h"

#include <vector>

template<class T>
class DB2Storage
{
    typedef std::list<char*> StringPoolList;
    typedef std::vector<T*> DataTableEx;
public:
    explicit DB2Storage(const char *f) : nCount(0), fieldCount(0), fmt(f), indexTable(NULL), m_dataTable(NULL) { }
    ~DB2Storage() { Clear(); }

    T const* LookupEntry(uint32 id) const { return (id>=nCount)?NULL:indexTable[id]; }
    uint32  GetNumRows() const { return nCount; }
    char const* GetFormat() const { return fmt; }
    uint32 GetFieldCount() const { return fieldCount; }

        /// Copies the provided entry and stores it.
        void AddEntry(uint32 id, const T* entry)
        {
            if (LookupEntry(id))
                return;

            if (id >= nCount)
            {
                // reallocate index table
                char** tmpIdxTable = new char*[id+1];
                memset(tmpIdxTable, 0, (id+1) * sizeof(char*));
                memcpy(tmpIdxTable, (char*)indexTable, nCount * sizeof(char*));
                delete[] ((char*)indexTable);
                nCount = id + 1;
                indexTable = (T**)tmpIdxTable;
            }

            T* entryDst = new T;
            memcpy((char*)entryDst, (char*)entry, sizeof(T));
            m_dataTableEx.push_back(entryDst);
            indexTable[id] = entryDst;
        }

    bool Load(char const* fn)
    {
        DB2FileLoader db2;
        // Check if load was sucessful, only then continue
        if (!db2.Load(fn, fmt))
            return false;

        fieldCount = db2.GetCols();

        // load raw non-string data
        m_dataTable = (T*)db2.AutoProduceData(fmt, nCount, (char**&)indexTable);

        // create string holders for loaded string fields
        m_stringPoolList.push_back(db2.AutoProduceStringsArrayHolders(fmt, (char*)m_dataTable));

        // load strings from dbc data
        m_stringPoolList.push_back(db2.AutoProduceStrings(fmt, (char*)m_dataTable));

        // error in dbc file at loading if NULL
        return indexTable!=NULL;
    }

    bool LoadStringsFrom(char const* fn)
    {
        // DBC must be already loaded using Load
        if (!indexTable)
            return false;

        DB2FileLoader db2;
        // Check if load was successful, only then continue
        if (!db2.Load(fn, fmt))
            return false;

        // load strings from another locale dbc data
        m_stringPoolList.push_back(db2.AutoProduceStrings(fmt, (char*)m_dataTable));

        return true;
    }

    void Clear()
    {
        if (!indexTable)
            return;

        delete[] ((char*)indexTable);
        indexTable = NULL;
        delete[] ((char*)m_dataTable);
        m_dataTable = NULL;
            for (typename DataTableEx::const_iterator itr = m_dataTableEx.begin(); itr != m_dataTableEx.end(); ++itr)
                delete *itr;
            m_dataTableEx.clear();

        while (!m_stringPoolList.empty())
        {
            delete[] m_stringPoolList.front();
            m_stringPoolList.pop_front();
        }
        nCount = 0;
    }

    void EraseEntry(uint32 id) { indexTable[id] = NULL; }

private:
    uint32 nCount;
    uint32 fieldCount;
    uint32 recordSize;
    char const* fmt;
    T** indexTable;
    T* m_dataTable;
    DataTableEx m_dataTableEx;
    StringPoolList m_stringPoolList;
};

#endif