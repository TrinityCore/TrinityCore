/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "SQLStorage.h"
#include "SQLStorageImpl.h"

const char CreatureInfosrcfmt[]="iiiiiiiiiisssiiiiiiifffiffiifiiiiiiiiiiffiiiiiiiiiiiiiiiiiiiiiiiisiifffliiiiiiiliiisi";
const char CreatureInfodstfmt[]="iiiiiiiiiisssibbiiiifffiffiifiiiiiiiiiiffiiiiiiiiiiiiiiiiiiiiiiiisiifffliiiiiiiliiiii";
const char GameObjectInfosrcfmt[]="iiissssiifiiiiiiiiiiiiiiiiiiiiiiiiiiiiiissi";
const char GameObjectInfodstfmt[]="iiissssiifiiiiiiiiiiiiiiiiiiiiiiiiiiiiiisii";

SQLStorage sCreatureStorage(CreatureInfosrcfmt, CreatureInfodstfmt, "entry","creature_template");
SQLStorage sGOStorage(GameObjectInfosrcfmt, GameObjectInfodstfmt, "entry","gameobject_template");

void SQLStorage::Free ()
{
    uint32 offset = 0;
    for (uint32 x = 0; x < iNumFields; ++x)
    {
        switch(dst_format[x])
        {
            case FT_BYTE:
                offset += sizeof(char);
                break;
            case FT_FLOAT:
                offset += sizeof(float);
                break;
            case FT_LOGIC:
                offset += sizeof(bool);
                break;
            case FT_INT:
                offset += sizeof(uint32);
                break;
            case FT_STRING:
            {
                for (uint32 y = 0; y < MaxEntry; ++y)
                    if (pIndex[y])
                        delete [] *(char**)((char*)(pIndex[y])+offset);

                offset += sizeof(char*);
                break;
            }
            case FT_NA:
            case FT_NA_BYTE:
                break;
            case FT_IND:
            case FT_SORT:
                assert(false && "SQL storage has a field type that does not match what is in the core. Check SQLStorage.cpp or your database.");
                break;
            default:
                assert(false && "Unknown field format character in SQLStorage.cpp");
                break;
        }
    }

    delete [] pIndex;
    delete [] data;
}

void SQLStorage::Load()
{
    SQLStorageLoader loader;
    loader.Load(*this);
}
