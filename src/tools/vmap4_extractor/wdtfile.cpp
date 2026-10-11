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

#include "wdtfile.h"
#include "adtfile.h"
#include "Errors.h"
#include "Memory.h"
#include "model.h"
#include "StringFormat.h"
#include "Util.h"
#include "vmapexport.h"
#include "wmo.h"
#include <algorithm>
#include <cstdio>

extern std::shared_ptr<CASC::Storage> CascStorage;

WDTFile::WDTFile(uint32 fileDataId, std::string const& description, std::string mapName, bool cache)
    : _file(CascStorage, fileDataId, description), _header(), _adtInfo(), _mapName(std::move(mapName)),
    _adtCache(cache ? std::make_unique<ADTCache>() : nullptr)
{
}

WDTFile::~WDTFile() = default;

bool WDTFile::init(uint32 mapId)
{
    if (_file.isEof())
        return false;

    char fourcc[4];
    uint32 size;

    std::string dirname = Trinity::StringFormat("{}/dir_bin/{:04}", szWorkDirWmo, mapId);
    auto dirfile = Trinity::make_unique_ptr_with_deleter<&::fclose>(fopen(dirname.c_str(), "ab"));
    if (!dirfile)
    {
        printf("Can't open dirfile!'%s'\n", dirname.c_str());
        return false;
    }

    while (!_file.isEof())
    {
        _file.read(fourcc,4);
        _file.read(&size, 4);

        std::ranges::reverse(fourcc);

        size_t nextpos = _file.getPos() + size;

        if (!memcmp(fourcc, "MPHD", 4))
        {
            ASSERT(size == sizeof(WDT::MPHD));
            _file.read(&_header, sizeof(WDT::MPHD));
        }
        else if (!memcmp(fourcc, "MAIN", 4))
        {
            ASSERT(size == sizeof(WDT::MAIN));
            _file.read(&_adtInfo, sizeof(WDT::MAIN));
        }
        else if (!memcmp(fourcc, "MAID", 4))
        {
            ASSERT(size == sizeof(WDT::MAID));
            _adtFileDataIds = std::make_unique<WDT::MAID>();
            _file.read(_adtFileDataIds.get(), sizeof(WDT::MAID));
        }
        else if (!memcmp(fourcc, "MWMO", 4))
        {
            // global map objects
            if (size)
            {
                char* p = _file.getPointer();
                _file.seekRelative(size);
                char* end = _file.getPointer();
                while (p < end)
                {
                    std::size_t length = std::ranges::distance(p, CStringSentinel.Checked(end));
                    _wmoNames.emplace_back(p, length);

                    p += length + 1;
                }
            }
        }
        else if (!memcmp(fourcc, "MODF", 4))
        {
            // global wmo instance data
            if (size)
            {
                uint32 mapObjectCount = size / sizeof(ADT::MODF);
                for (uint32 i = 0; i < mapObjectCount; ++i)
                {
                    ADT::MODF mapObjDef;
                    _file.read(&mapObjDef, sizeof(ADT::MODF));

                    std::string fileName;
                    if (mapObjDef.Flags & 0x8)
                        fileName = Trinity::StringFormat("FILE{:08X}.xxx", mapObjDef.Id);
                    else
                        fileName = _wmoNames[mapObjDef.Id];

                    if (ExtractedModelData const* extracted = ExtractSingleWmo(fileName))
                    {
                        if (extracted->HasCollision())
                            MapObject::Extract(mapObjDef, fileName.c_str(), true, mapId, mapId, dirfile.get(), nullptr);

                        if (extracted->Doodads)
                            Doodad::ExtractSet(*extracted->Doodads, mapObjDef, true, mapId, mapId, dirfile.get(), nullptr);
                    }
                }
            }
        }
        _file.seek((int)nextpos);
    }

    _file.close();
    return true;
}

ADTFile* WDTFile::GetMap(int32 x, int32 y, bool createIfMissing)
{
    if (!(x >= 0 && y >= 0 && x < 64 && y < 64))
        return nullptr;

    if (_adtCache && _adtCache->file[x][y])
        return _adtCache->file[x][y].get();

    if (!(_adtInfo.Data[y][x].Flag & 1))
        return nullptr;

    if (!createIfMissing)
        return nullptr;

    ADTFile* adt;
    std::string name = Trinity::StringFormat(R"(World\Maps\{}\{}_{}_{}_obj0.adt)", _mapName, _mapName, x, y);
    if (_header.Flags & 0x200)
        adt = new ADTFile(_adtFileDataIds->Data[y][x].Obj0ADT, name, _adtCache != nullptr);
    else
        adt = new ADTFile(name, _adtCache != nullptr);

    if (_adtCache)
        _adtCache->file[x][y].reset(adt);

    return adt;
}

void WDTFile::FreeADT(ADTFile* adt)
{
    if (_adtCache)
        return;

    delete adt;
}
