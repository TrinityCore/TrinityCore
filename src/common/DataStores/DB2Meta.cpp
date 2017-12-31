/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "DB2Meta.h"
#include "Errors.h"

DB2FieldDefault::DB2FieldDefault(uint8 u8)
{
    AsUInt8 = u8;
}

DB2FieldDefault::DB2FieldDefault(uint16 u16)
{
    AsUInt16 = u16;
}

DB2FieldDefault::DB2FieldDefault(uint32 u32)
{
    AsUInt32 = u32;
}

DB2FieldDefault::DB2FieldDefault(float f)
{
    AsFloat = f;
}

DB2FieldDefault::DB2FieldDefault(char const* str)
{
    AsString = str;
}

DB2Meta::DB2Meta(int32 indexField, uint32 fieldCount, uint32 layoutHash, char const* types, uint8 const* arraySizes, DB2FieldDefault const* fieldDefaults)
    : IndexField(indexField), FieldCount(fieldCount), LayoutHash(layoutHash), Types(types), ArraySizes(arraySizes), FieldDefaults(fieldDefaults)
{
}

bool DB2Meta::HasIndexFieldInData() const
{
    return IndexField != -1;
}

uint32 DB2Meta::GetIndexField() const
{
    return IndexField == -1 ? 0 : uint32(IndexField);
}

uint32 DB2Meta::GetRecordSize() const
{
    uint32 size = 0;
    for (uint32 i = 0; i < FieldCount; ++i)
    {
        for (uint8 j = 0; j < ArraySizes[i]; ++j)
        {
            switch (Types[i])
            {
                case FT_BYTE:
                    size += 1;
                    break;
                case FT_SHORT:
                    size += 2;
                    break;
                case FT_FLOAT:
                case FT_INT:
                    size += 4;
                    break;
                case FT_STRING:
                    size += sizeof(char*);
                    break;
                default:
                    ASSERT(false, "Unsupported column type specified %c", Types[i]);
                    break;
            }
        }
    }

    if (!HasIndexFieldInData())
        size += 4;

    return size;
}

uint32 DB2Meta::GetDbIndexField() const
{
    if (IndexField == -1)
        return 0;

    uint32 index = 0;
    for (uint32 i = 0; i < FieldCount && i < uint32(IndexField); ++i)
        index += ArraySizes[i];

    return index;
}

uint32 DB2Meta::GetDbFieldCount() const
{
    uint32 fields = 0;
    for (uint32 i = 0; i < FieldCount; ++i)
        fields += ArraySizes[i];

    if (!HasIndexFieldInData())
        ++fields;

    return fields;
}

DB2FieldMeta::DB2FieldMeta(bool isSigned, DBCFormer type, char const* name)
    : IsSigned(isSigned), Type(type), Name(name)
{
}
