/* 
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * Thanks to the original authors: MaNGOS <http://www.mangosproject.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef SQLSTORAGE_H
#define SQLSTORAGE_H

#include "Common.h"
#include "Database/DatabaseEnv.h"

class SQLStorage
{
    public:

        SQLStorage(const char*fmt,const char * _entry_field,const char * sqlname)
        {
            format=fmt;
            entry_field = _entry_field;
            table=sqlname;
            data=NULL;
            pIndex=NULL;
            iNumFields =strlen(fmt);
            MaxEntry = 0;
        }
        ~SQLStorage()
        {
            Free();
        }

        template<class T>
            T const* LookupEntry(uint32 id) const
        {
            if( id == 0 )
                return NULL;
            if(id >= MaxEntry)
                return NULL;
            return reinterpret_cast<T const*>(pIndex[id]);
        }

        uint32 RecordCount;
        uint32 MaxEntry;
        uint32 iNumFields;
        void Load();
        void Free();
    private:
        char** pIndex;

        char *data;
        const char *format;
        const char *table;
        const char *entry_field;
        //bool HasString;
};
#endif
