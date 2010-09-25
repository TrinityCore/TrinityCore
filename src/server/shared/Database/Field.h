/*
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

#ifndef _FIELD_H
#define _FIELD_H

#include "Common.h"
#include "Log.h"

#include <mysql.h>

class Field
{
    friend class ResultSet;
    friend class PreparedResultSet;

    public:

        bool GetBool() const // Wrapper, actually gets integer
        {
            return GetUInt8() == 1 ? true : false;
        }

        uint8 GetUInt8() const
        {
            if (!data.value)
                return 0;

            #ifdef TRINITY_DEBUG
            if (!IsNumeric())
            {
                sLog.outSQLDriver("Error: GetUInt8() on non-numeric field.");
                return 0;
            }
            #endif
            if (data.raw)
                return *reinterpret_cast<uint8*>(data.value);
            return static_cast<uint8>(atol((char*)data.value));
        }

        int8 GetInt8() const
        {
            if (!data.value)
                return 0;

            #ifdef TRINITY_DEBUG
            if (!IsNumeric())
            {
                sLog.outSQLDriver("Error: GeInt8() on non-numeric field.");
                return 0;
            }
            #endif
            if (data.raw)
                return *reinterpret_cast<int8*>(data.value);
            return static_cast<int8>(atol((char*)data.value));
        }

        uint16 GetUInt16() const
        {
            if (!data.value)
                return 0;

            #ifdef TRINITY_DEBUG
            if (!IsNumeric())
            {
                sLog.outSQLDriver("Error: GetUInt16() on non-numeric field.");
                return 0;
            }
            #endif
            if (data.raw)
                return *reinterpret_cast<uint16*>(data.value);
            return static_cast<uint16>(atol((char*)data.value));
        }

        int16 GetInt16() const
        {
            if (!data.value)
                return 0;

            #ifdef TRINITY_DEBUG
            if (!IsNumeric())
            {
                sLog.outSQLDriver("Error: GetInt16() on non-numeric field.");
                return 0;
            }
            #endif
            if (data.raw)
                return *reinterpret_cast<int16*>(data.value);
            return static_cast<int16>(atol((char*)data.value));
        }

        uint32 GetUInt32() const
        {
            if (!data.value)
                return 0;

            #ifdef TRINITY_DEBUG
            if (!IsNumeric())
            {
                sLog.outSQLDriver("Error: GetUInt32() on non-numeric field.");
                return 0;
            }
            #endif
            if (data.raw)
                return *reinterpret_cast<uint32*>(data.value);
            return static_cast<uint32>(atol((char*)data.value));
        }

        int32 GetInt32() const
        {
            if (!data.value)
                return 0;

            #ifdef TRINITY_DEBUG
            if (!IsNumeric())
            {
                sLog.outSQLDriver("Error: GetInt32() on non-numeric field.");
                return 0;
            }
            #endif
            if (data.raw)
                return *reinterpret_cast<int32*>(data.value);
            return static_cast<int32>(atol((char*)data.value));
        }

        uint64 GetUInt64() const
        {
            if (!data.value)
                return 0;

            #ifdef TRINITY_DEBUG
            if (!IsNumeric())
            {
                sLog.outSQLDriver("Error: GetUInt64() on non-numeric field.");
                return 0;
            }
            #endif
            if (data.raw)
                return *reinterpret_cast<uint64*>(data.value);
            return static_cast<uint64>(atol((char*)data.value));
        }

        int64 GetInt64() const
        {
            if (!data.value)
                return 0;

            #ifdef TRINITY_DEBUG
            if (!IsNumeric())
            {
                sLog.outSQLDriver("Error: GetInt64() on non-numeric field.");
                return 0;
            }
            #endif
            if (data.raw)
                return *reinterpret_cast<int64*>(data.value);
            return static_cast<int64>(atol((char*)data.value));
        }

        float GetFloat() const
        {
            if (!data.value)
                return 0.0f;

            #ifdef TRINITY_DEBUG
            if (!IsNumeric())
            {
                sLog.outSQLDriver("Error: GetFloat() on non-numeric field.");
                return 0.0f;
            }
            #endif
            if (data.raw)
                return *reinterpret_cast<float*>(data.value);
            return static_cast<float>(atof((char*)data.value));
        }

        double GetDouble() const
        {
            if (!data.value)
                return 0.0f;

            #ifdef TRINITY_DEBUG
            if (!IsNumeric())
            {
                sLog.outSQLDriver("Error: GetDouble() on non-numeric field.");
                return 0.0f;
            }
            #endif
            if (data.raw)
                return *reinterpret_cast<double*>(data.value);
            return static_cast<double>(atof((char*)data.value));
        }

        const char* GetCString() const
        {
            if (!data.value)
                return NULL;

            #ifdef TRINITY_DEBUG
            if (IsNumeric())
            {
                sLog.outSQLDriver("Error: GetCString() on numeric field.");
                return NULL;
            }
            #endif
            return static_cast<const char*>(data.value);
        }

        std::string GetString() const
        {
            if (!data.value)
                return "";

            if (data.raw)
            {
                const char* string = GetCString();
                if (!string)
                    string = "";
                return std::string(string, data.length);
            }
            return std::string((char*)data.value);
        }

    protected:
        Field();
        ~Field();

        struct
        {
            enum_field_types type;  // Field type
            void* value;            // Actual data in memory
            bool raw;               // Raw bytes? (Prepared statement or adhoc)
            uint32 length;          // Length (prepared strings only)
        } data;

        void SetByteValue(const void* newValue, const size_t newSize, enum_field_types newType, uint32 length);
        void SetStructuredValue(char* newValue, enum_field_types newType);

        void CleanUp()
        {
            delete[] ((char*)data.value);
            data.value = NULL;
        }

        static size_t SizeForType(MYSQL_FIELD* field)
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
                    sLog.outSQLDriver("SQL::SizeForType(): invalid field type %u", uint32(field->type));
                    return 0;
            }
        }

        bool IsNumeric() const
        {
            return (data.type == MYSQL_TYPE_TINY ||
                    data.type == MYSQL_TYPE_SHORT ||
                    data.type == MYSQL_TYPE_INT24 ||
                    data.type == MYSQL_TYPE_LONG ||
                    data.type == MYSQL_TYPE_FLOAT ||
                    data.type == MYSQL_TYPE_DOUBLE ||
                    data.type == MYSQL_TYPE_LONGLONG );
        }
};

#endif

