/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
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

#ifndef WDTFILE_H
#define WDTFILE_H

#include "cascfile.h"
#include "wmo.h"
#include <memory>
#include <string>
#include <vector>

class ADTFile;

class WDTFile
{
public:
    WDTFile(char const* storagePath, std::string mapName, bool cache);
    ~WDTFile();
    bool init(uint32 mapId);

    ADTFile* GetMap(int32 x, int32 y);
    void FreeADT(ADTFile* adt);
private:
    CASCFile _file;
    std::string _mapName;
    std::vector<std::string> _wmoNames;
    struct ADTCache
    {
        std::unique_ptr<ADTFile> file[64][64];
    };
    std::unique_ptr<ADTCache> _adtCache;
};

#endif
