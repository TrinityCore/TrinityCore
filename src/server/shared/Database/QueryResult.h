/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include "AutoPtr.h"
#include <ace/Thread_Mutex.h>

#include "Field.h"

#ifdef _WIN32
  #include <winsock2.h>
#endif
#include <mysql.h>

class ResultSet
{
    public:
        ResultSet(MYSQL_RES* result, MYSQL_FIELD* fields, uint64 rowCount, uint32 fieldCount);
        ~ResultSet();

        bool NextRow();
        uint64 GetRowCount() const { return _rowCount; }
        uint32 GetFieldCount() const { return _fieldCount; }

        Field* Fetch() const { return _currentRow; }
        const Field & operator [] (uint32 index) const
        {
            ASSERT(index < _fieldCount);
            return _currentRow[index];
        }

    protected:
        uint64 _rowCount;
        Field* _currentRow;
        uint32 _fieldCount;

    private:
        void CleanUp();
        MYSQL_RES* _result;
        MYSQL_FIELD* _fields;
};

typedef Trinity::AutoPtr<ResultSet, ACE_Thread_Mutex> QueryResult;

class PreparedResultSet
{
    public:
        PreparedResultSet(MYSQL_STMT* stmt, MYSQL_RES* result, uint64 rowCount, uint32 fieldCount);
        ~PreparedResultSet();

        bool NextRow();
        uint64 GetRowCount() const { return m_rowCount; }
        uint32 GetFieldCount() const { return m_fieldCount; }

        Field* Fetch() const
        {
            ASSERT(m_rowPosition < m_rowCount);
            return m_rows[uint32(m_rowPosition)];
        }

        const Field & operator [] (uint32 index) const
        {
            ASSERT(m_rowPosition < m_rowCount);
            ASSERT(index < m_fieldCount);
            return m_rows[uint32(m_rowPosition)][index];
        }

    protected:
        std::vector<Field*> m_rows;
        uint64 m_rowCount;
        uint64 m_rowPosition;
        uint32 m_fieldCount;

    private:
        MYSQL_BIND* m_rBind;
        MYSQL_STMT* m_stmt;
        MYSQL_RES* m_res;

        my_bool* m_isNull;
        unsigned long* m_length;

        void FreeBindBuffer();
        void CleanUp();
        bool _NextRow();

};

typedef Trinity::AutoPtr<PreparedResultSet, ACE_Thread_Mutex> PreparedQueryResult;

#endif

