/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "mpqfile.h"
#include <string>
#include <memory>

class ADTFile;

class WDTFile
{
public:
    WDTFile(char const* file_name, std::string mapName, bool cache);
    ~WDTFile();
    bool init(uint32 mapId);

    ADTFile* GetMap(int32 x, int32 y);
    void FreeADT(ADTFile* adt);

    std::string* gWmoInstansName;
    int gnWMO;

private:
    MPQFile _file;
    std::string _mapName;
    std::vector<std::string> _wmoNames;
    struct ADTCache
    {
        std::unique_ptr<ADTFile> file[64][64];
    };
    std::unique_ptr<ADTCache> _adtCache;
};

#endif
