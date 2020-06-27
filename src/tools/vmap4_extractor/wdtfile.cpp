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

#include "vmapexport.h"
#include "wdtfile.h"
#include "adtfile.h"
#include "Common.h"
#include "Errors.h"
#include "StringFormat.h"
#include <cstdio>

extern std::shared_ptr<CASC::Storage> CascStorage;

WDTFile::WDTFile(uint32 fileDataId, std::string const& description, std::string mapName, bool cache)
    : _file(CascStorage, fileDataId, description), _mapName(std::move(mapName))
{
    memset(&_header, 0, sizeof(WDT::MPHD));
    memset(&_adtInfo, 0, sizeof(WDT::MAIN));
    if (cache)
    {
        _adtCache = std::make_unique<ADTCache>();
        memset(_adtCache->file, 0, sizeof(_adtCache->file));
    }
    else
        _adtCache = nullptr;
}

WDTFile::~WDTFile() = default;

bool WDTFile::init(uint32 mapId)
{
    if (_file.isEof())
        return false;

    char fourcc[5];
    uint32 size;

    std::string dirname = std::string(szWorkDirWmo) + "/dir_bin";
    FILE* dirfile = fopen(dirname.c_str(), "ab");
    if (!dirfile)
    {
        printf("Can't open dirfile!'%s'\n", dirname.c_str());
        return false;
    }

    while (!_file.isEof())
    {
        _file.read(fourcc,4);
        _file.read(&size, 4);

        flipcc(fourcc);
        fourcc[4] = 0;

        size_t nextpos = _file.getPos() + size;

        if (!strcmp(fourcc, "MPHD"))
        {
            ASSERT(size == sizeof(WDT::MPHD));
            _file.read(&_header, sizeof(WDT::MPHD));
        }
        else if (!strcmp(fourcc,"MAIN"))
        {
            ASSERT(size == sizeof(WDT::MAIN));
            _file.read(&_adtInfo, sizeof(WDT::MAIN));
        }
        else if (!strcmp(fourcc, "MAID"))
        {
            ASSERT(size == sizeof(WDT::MAID));
            _adtFileDataIds = std::make_unique<WDT::MAID>();
            _file.read(_adtFileDataIds.get(), sizeof(WDT::MAID));
        }
        else if (!strcmp(fourcc,"MWMO"))
        {
            // global map objects
            if (size)
            {
                char *buf = new char[size];
                _file.read(buf, size);
                char *p = buf;
                while (p < buf + size)
                {
                    std::string path(p);

                    char* s = GetPlainName(p);
                    NormalizeFileName(s, strlen(s));
                    p = p + strlen(p) + 1;
                    _wmoNames.emplace_back(s);

                    ExtractSingleWmo(path);
                }
                delete[] buf;
            }
        }
        else if (!strcmp(fourcc, "MODF"))
        {
            // global wmo instance data
            if (size)
            {
                uint32 mapObjectCount = size / sizeof(ADT::MODF);
                for (uint32 i = 0; i < mapObjectCount; ++i)
                {
                    ADT::MODF mapObjDef;
                    _file.read(&mapObjDef, sizeof(ADT::MODF));
                    if (!(mapObjDef.Flags & 0x8))
                    {
                        MapObject::Extract(mapObjDef, _wmoNames[mapObjDef.Id].c_str(), true, mapId, mapId, dirfile, nullptr);
                        Doodad::ExtractSet(WmoDoodads[_wmoNames[mapObjDef.Id]], mapObjDef, true, mapId, mapId, dirfile, nullptr);
                    }
                    else
                    {
                        std::string fileName = Trinity::StringFormat("FILE%08X.xxx", mapObjDef.Id);
                        ExtractSingleWmo(fileName);
                        MapObject::Extract(mapObjDef, fileName.c_str(), true, mapId, mapId, dirfile, nullptr);
                        Doodad::ExtractSet(WmoDoodads[fileName], mapObjDef, true, mapId, mapId, dirfile, nullptr);
                    }
                }
            }
        }
        _file.seek((int)nextpos);
    }

    _file.close();
    fclose(dirfile);
    return true;
}

ADTFile* WDTFile::GetMap(int32 x, int32 y)
{
    if (!(x >= 0 && y >= 0 && x < 64 && y < 64))
        return nullptr;

    if (_adtCache && _adtCache->file[x][y])
        return _adtCache->file[x][y].get();

    if (!(_adtInfo.Data[y][x].Flag & 1))
        return nullptr;

    ADTFile* adt;
    std::string name = Trinity::StringFormat(R"(World\Maps\%s\%s_%d_%d_obj0.adt)", _mapName.c_str(), _mapName.c_str(), x, y);
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
