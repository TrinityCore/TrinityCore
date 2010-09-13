/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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

#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <ace/Refcounted_Auto_Ptr.h>
#include <ace/Null_Mutex.h>

#include "Field.h"
#include "Log.h"

#ifdef _WIN32
  #include <winsock2.h>
#endif
#include <mysql.h>

class ResultSet
{
    public:
        ResultSet(MYSQL_RES *result, MYSQL_FIELD *fields, uint64 rowCount, uint32 fieldCount);
        ~ResultSet();

        bool NextRow();

        Field *Fetch() const { return mCurrentRow; }

        const Field & operator [] (int index) const { return mCurrentRow[index]; }

        uint32 GetFieldCount() const { return mFieldCount; }
        uint64 GetRowCount() const { return mRowCount; }

    protected:
        Field *mCurrentRow;
        uint32 mFieldCount;
        uint64 mRowCount;

    private:
        enum Field::DataTypes ConvertNativeType(enum_field_types mysqlType) const;
        void EndQuery();
        MYSQL_RES *mResult;

};

typedef ACE_Refcounted_Auto_Ptr<ResultSet, ACE_Null_Mutex> QueryResult;

typedef std::vector<std::string> QueryFieldNames;

class QueryNamedResult
{
    public:
        explicit QueryNamedResult(ResultSet* query, QueryFieldNames const& names) : mQuery(query), mFieldNames(names) {}
        ~QueryNamedResult() { delete mQuery; }

        // compatible interface with ResultSet
        bool NextRow() { return mQuery->NextRow(); }
        Field *Fetch() const { return mQuery->Fetch(); }
        uint32 GetFieldCount() const { return mQuery->GetFieldCount(); }
        uint64 GetRowCount() const { return mQuery->GetRowCount(); }
        Field const& operator[] (int index) const { return (*mQuery)[index]; }

        // named access
        Field const& operator[] (const std::string &name) const { return mQuery->Fetch()[GetField_idx(name)]; }
        QueryFieldNames const& GetFieldNames() const { return mFieldNames; }

        uint32 GetField_idx(const std::string &name) const
        {
            for (size_t idx = 0; idx < mFieldNames.size(); ++idx)
            {
                if(mFieldNames[idx] == name)
                    return idx;
            }
            ASSERT(false && "unknown field name");
            return uint32(-1);
        }

    protected:
        ResultSet *mQuery;
        QueryFieldNames mFieldNames;
};

class ResultBind
{
    friend class PreparedResultSet;
    public:

        ResultBind(MYSQL_STMT* stmt) : m_rBind(NULL), m_stmt(stmt), m_res(NULL), m_isNull(NULL), m_length(NULL), m_fieldCount(0) {}

        ~ResultBind()
        {
            CleanUp();  // Clean up buffer
        }

        void BindResult(uint64& num_rows);

    protected:
        MYSQL_BIND* m_rBind;
        MYSQL_STMT* m_stmt;
        MYSQL_RES* m_res;

        void FreeBindBuffer();
        bool IsValidIndex(uint32 index) { return index < m_fieldCount; }

    private:

        void CleanUp();

        size_t SizeForType(MYSQL_FIELD* field)
        {
            switch (field->type)
            {
                case MYSQL_TYPE_NULL:
                    return 0;
                case MYSQL_TYPE_TINY:
                    return 1;
                case MYSQL_TYPE_YEAR:
                case MYSQL_TYPE_SHORT:
                    return 2;
                case MYSQL_TYPE_INT24:
                case MYSQL_TYPE_LONG:
                case MYSQL_TYPE_FLOAT:
                    return 4;
                case MYSQL_TYPE_DOUBLE:
                case MYSQL_TYPE_LONGLONG:
                case MYSQL_TYPE_BIT:
                    return 8;

                case MYSQL_TYPE_TIMESTAMP:
                case MYSQL_TYPE_DATE:
                case MYSQL_TYPE_TIME:
                case MYSQL_TYPE_DATETIME:
                    return sizeof(MYSQL_TIME);

                case MYSQL_TYPE_TINY_BLOB:
                case MYSQL_TYPE_MEDIUM_BLOB:
                case MYSQL_TYPE_LONG_BLOB:
                case MYSQL_TYPE_BLOB:
                case MYSQL_TYPE_STRING:
                case MYSQL_TYPE_VAR_STRING:
                    return field->max_length + 1;

                case MYSQL_TYPE_DECIMAL:
                case MYSQL_TYPE_NEWDECIMAL:
                    return 64;

                case MYSQL_TYPE_GEOMETRY:
                /*
                Following types are not sent over the wire:
                MYSQL_TYPE_ENUM:
                MYSQL_TYPE_SET:
                */
                default:
                    sLog.outSQLDriver("ResultBind::SizeForType(): invalid field type %u", uint32(field->type));
                    return 0;
            }
        }

        my_bool* m_isNull;
        unsigned long* m_length;
        uint32 m_fieldCount;
};

class PreparedResultSet
{
    template<class T> friend class DatabaseWorkerPool;
    public:
        PreparedResultSet(MYSQL_STMT* stmt)
        {
            num_rows = 0;
            row_position = 0;
            rbind = new ResultBind(stmt);
            rbind->BindResult(num_rows);
        }
        ~PreparedResultSet()
        {
            delete rbind;
        }

        operator bool() { return num_rows > 0; }

        uint8 GetUInt8(uint32 index);
        int8 GetInt8(uint32 index);
        uint16 GetUInt16(uint32 index);
        int16 GetInt16(uint32 index);
        uint32 GetUInt32(uint32 index);
        int32 GetInt32(uint32 index);
        uint64 GetUInt64(uint32 index);
        int64 GetInt64(uint32 index);
        float GetFloat(uint32 index);
        std::string GetString(uint32 index);
        const char* GetCString(uint32 index);

        bool NextRow();

    private:
        bool CheckFieldIndex(uint32 index)  const
        {
            if (!rbind->IsValidIndex(index))
                return false;

            if (rbind->m_isNull[index])
                return false;

            return true;
        }

        ResultBind* rbind;
        uint64 row_position;
        uint64 num_rows;
};

typedef ACE_Refcounted_Auto_Ptr<PreparedResultSet, ACE_Null_Mutex> PreparedQueryResult;

#endif

