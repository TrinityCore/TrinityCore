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

#include "adtfile.h"
#include "Common.h"
#include "Memory.h"
#include "StringFormat.h"
#include "Util.h"
#include "model.h"
#include "vmapexport.h"
#include "wmo.h"
#include <algorithm>
#include <cstdio>

std::string_view GetPlainName(std::string_view fileName)
{
    std::size_t lastSeparatorPos = fileName.find_last_of("\\/"sv);

    if (lastSeparatorPos != std::string_view::npos)
        fileName.remove_prefix(lastSeparatorPos + 1);

    return fileName;
}

void NormalizeFileName(std::string& name)
{
    if (name.starts_with("FILE"sv)) // name is FileDataId formatted, do not normalize
        return;

    auto ptr = name.begin() + (name.length() - 1);

    //extension in lowercase
    for (; *ptr != '.' && ptr >= name.begin(); --ptr)
        if (*ptr >= 'A' && *ptr <= 'Z')
            *ptr |= 0x20;

    for (; ptr >= name.begin(); --ptr)
    {
        if (ptr > name.begin() && *ptr >= 'A' && *ptr <= 'Z' && isalpha(*(ptr - 1)))
            *ptr |= 0x20;
        else if ((ptr == name.begin() || !isalpha(*(ptr - 1))) && *ptr >= 'a' && *ptr <= 'z')
            *ptr &= ~0x20;
        else if (*ptr == ' ')
            *ptr = '_';
    }
}

extern std::shared_ptr<CASC::Storage> CascStorage;

ADTFile::ADTFile(std::string const& filename, bool cache) : _file(CascStorage, filename.c_str(), false)
{
    cacheable = cache;
    dirfileCache = nullptr;
}

ADTFile::ADTFile(uint32 fileDataId, std::string const& description, bool cache) : _file(CascStorage, fileDataId, description, false)
{
    cacheable = cache;
    dirfileCache = nullptr;
}

bool ADTFile::init(uint32 map_num, uint32 originalMapId)
{
    if (dirfileCache)
        return initFromCache(map_num, originalMapId);

    if (_file.isEof())
        return false;

    uint32 size;
    std::string dirname = Trinity::StringFormat("{}/dir_bin/{:04}", szWorkDirWmo, map_num);
    auto dirfile = Trinity::make_unique_ptr_with_deleter<&::fclose>(fopen(dirname.c_str(), "ab"));
    if(!dirfile)
    {
        printf("Can't open dirfile!'%s'\n", dirname.c_str());
        return false;
    }

    if (cacheable)
        dirfileCache = new std::vector<ADTOutputCache>();

    while (!_file.isEof())
    {
        char fourcc[4];
        _file.read(&fourcc,4);
        _file.read(&size, 4);
        std::ranges::reverse(fourcc);

        size_t nextpos = _file.getPos() + size;

        if (!memcmp(fourcc, "MMDX", 4))
        {
            if (size)
            {
                char* p = _file.getPointer();
                _file.seekRelative(size);
                char* end = _file.getPointer();
                while (p < end)
                {
                    std::size_t length = std::ranges::distance(p, CStringSentinel.Checked(end));
                    ModelInstanceNames.emplace_back(p, length);

                    p += length + 1;
                }
            }
        }
        else if (!memcmp(fourcc, "MWMO", 4))
        {
            if (size)
            {
                char* p = _file.getPointer();
                _file.seekRelative(size);
                char* end = _file.getPointer();
                while (p < end)
                {
                    std::size_t length = std::ranges::distance(p, CStringSentinel.Checked(end));
                    WmoInstanceNames.emplace_back(p, length);

                    p += length + 1;
                }
            }
        }
        //======================
        else if (!memcmp(fourcc, "MDDF", 4))
        {
            if (size)
            {
                uint32 doodadCount = size / sizeof(ADT::MDDF);
                for (uint32 i = 0; i < doodadCount; ++i)
                {
                    ADT::MDDF doodadDef;
                    _file.read(&doodadDef, sizeof(ADT::MDDF));

                    std::string fileName;
                    if (doodadDef.Flags & 0x40)
                        fileName = Trinity::StringFormat("FILE{:08X}.xxx", doodadDef.Id);
                    else
                        fileName = ModelInstanceNames[doodadDef.Id];

                    if (ExtractSingleModel(fileName))
                        Doodad::Extract(doodadDef, fileName.c_str(), map_num, originalMapId, dirfile.get(), dirfileCache);
                }

                ModelInstanceNames.clear();
            }
        }
        else if (!memcmp(fourcc, "MODF", 4))
        {
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
                        fileName = WmoInstanceNames[mapObjDef.Id];

                    if (ExtractedModelData const* extracted = ExtractSingleWmo(fileName))
                    {
                        if (extracted->HasCollision())
                            MapObject::Extract(mapObjDef, fileName.c_str(), false, map_num, originalMapId, dirfile.get(), dirfileCache);

                        if (extracted->Doodads)
                            Doodad::ExtractSet(*extracted->Doodads, mapObjDef, false, map_num, originalMapId, dirfile.get(), dirfileCache);
                    }
                }

                WmoInstanceNames.clear();
            }
        }

        //======================
        _file.seek(nextpos);
    }

    _file.close();
    return true;
}

bool ADTFile::initFromCache(uint32 map_num, uint32 originalMapId)
{
    if (dirfileCache->empty())
        return true;

    std::string dirname = Trinity::StringFormat("{}/dir_bin/{:04}", szWorkDirWmo, map_num);
    auto dirfile = Trinity::make_unique_ptr_with_deleter<&::fclose>(fopen(dirname.c_str(), "ab"));
    if (!dirfile)
    {
        printf("Can't open dirfile!'%s'\n", dirname.c_str());
        return false;
    }

    for (ADTOutputCache const& cached : *dirfileCache)
    {
        uint8 flags = cached.Flags;
        if (map_num != originalMapId)
            flags |= MOD_PARENT_SPAWN;
        fwrite(&flags, sizeof(uint8), 1, dirfile.get());
        fwrite(cached.Data.data(), cached.Data.size(), 1, dirfile.get());
    }

    return true;
}

ADTFile::~ADTFile()
{
    _file.close();
    delete dirfileCache;
}
