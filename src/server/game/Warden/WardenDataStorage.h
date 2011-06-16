/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
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

#ifndef _WARDEN_DATA_STORAGE_H
#define _WARDEN_DATA_STORAGE_H

#include <map>
#include "BigNumber.h"

struct WardenData
{
    uint8 Type;
    BigNumber i;
    uint32 Address;                                         // PROC_CHECK, MEM_CHECK, PAGE_CHECK
    uint8 Length;                                           // PROC_CHECK, MEM_CHECK, PAGE_CHECK
    std::string str;                                        // LUA, MPQ, DRIVER
};

struct WardenDataResult
{
    BigNumber res;                                          // MEM_CHECK
};

class CWardenDataStorage
{
    public:
        CWardenDataStorage();
        ~CWardenDataStorage();
        uint32 InternalDataID;
        std::vector<uint32> MemCheckIds;

    private:
        std::map<uint32, WardenData*> _data_map;
        std::map<uint32, WardenDataResult*> _result_map;

    public:
        inline uint32 GenerateInternalDataID() { return InternalDataID++; }
        WardenData *GetWardenDataById(uint32 Id);
        WardenDataResult *GetWardenResultById(uint32 Id);
        void Init();

    protected:
        void LoadWardenDataResult();
};

extern CWardenDataStorage WardenDataStorage;
#endif
