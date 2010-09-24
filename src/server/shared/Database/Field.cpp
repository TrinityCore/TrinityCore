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

#include "Field.h"

Field::Field()
{
    data.value = NULL;
    data.type = MYSQL_TYPE_NULL;
    data.length = 0;
}

Field::~Field()
{
    CleanUp();
}

void Field::SetByteValue(void* newValue, const size_t newSize, enum_field_types newType, uint32 length)
{
    // This value stores raw bytes that have to be explicitly casted later
    if (newValue)
    {
        data.value = new char [newSize];
        memcpy(data.value, newValue, newSize);
        data.length = length;
    }
    data.type = newType;
    data.raw = true;
}

void Field::SetStructuredValue(char* newValue, enum_field_types newType, const size_t newSize)
{
    // This value stores somewhat structured data that needs function style casting
    if (newValue)
    {
        size_t size = strlen(newValue);
        data.value = new char [size+1];
        memcpy(data.value, newValue, size);
        data.length = size;
    }

    data.type = newType;
    data.raw = false;
}
