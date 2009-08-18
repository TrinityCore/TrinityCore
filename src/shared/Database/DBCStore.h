/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef DBCSTORE_H
#define DBCSTORE_H

#include "DBCFileLoader.h"

template<class T>
class DBCStorage
{
    typedef std::list<char*> StringPoolList;
    public:
        explicit DBCStorage(const char *f) : nCount(0), fieldCount(0), fmt(f), indexTable(NULL), m_dataTable(NULL) { }
        ~DBCStorage() { Clear(); }

        T const* LookupEntry(uint32 id) const { return (id>=nCount)?NULL:indexTable[id]; }
        uint32  GetNumRows() const { return nCount; }
        char const* GetFormat() const { return fmt; }
        uint32 GetFieldCount() const { return fieldCount; }

        bool Load(char const* fn, uint32 customEntriesCount = 0)
        {
            DBCFileLoader dbc;
            // Check if load was sucessful, only then continue
            if(!dbc.Load(fn, fmt, customEntriesCount))
                return false;

            fieldCount = dbc.GetCols();
            m_dataTable = (T*)dbc.AutoProduceData(fmt,nCount,(char**&)indexTable);
            m_stringPoolList.push_back(dbc.AutoProduceStrings(fmt,(char*)m_dataTable));

            // error in dbc file at loading if NULL
            return indexTable!=NULL;
        }

        bool LoadStringsFrom(char const* fn)
        {
            // DBC must be already loaded using Load
            if(!indexTable)
                return false;

            DBCFileLoader dbc;
            // Check if load was successful, only then continue
            if(!dbc.Load(fn, fmt))
                return false;

            m_stringPoolList.push_back(dbc.AutoProduceStrings(fmt,(char*)m_dataTable));

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

            while(!m_stringPoolList.empty())
            {
                delete[] m_stringPoolList.front();
                m_stringPoolList.pop_front();
            }
            nCount = 0;
        }

    private:
        uint32 nCount;
        uint32 fieldCount;
        char const* fmt;
        T** indexTable;
        T* m_dataTable;
        StringPoolList m_stringPoolList;
};
#endif
