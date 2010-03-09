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

#include "DatabaseEnv.h"

Field::Field() :
mValue(NULL), mType(DB_TYPE_UNKNOWN)
{
}

Field::Field(Field &f)
{
    const char *value;

    value = f.GetString();

    if (value && (mValue = new char[strlen(value) + 1]))
        strcpy(mValue, value);
    else
        mValue = NULL;

    mType = f.GetType();
}

Field::Field(const char *value, enum Field::DataTypes type) :
mType(type)
{
    if (value && (mValue = new char[strlen(value) + 1]))
        strcpy(mValue, value);
    else
        mValue = NULL;
}

Field::~Field()
{
    if (mValue)
        delete [] mValue;
}

void Field::SetValue(const char *value)
{
    if (mValue)
        delete [] mValue;

    if (value)
    {
        mValue = new char[strlen(value) + 1];
        strcpy(mValue, value);
    }
    else
        mValue = NULL;
}
