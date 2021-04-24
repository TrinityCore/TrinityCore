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

#ifndef ADT_H
#define ADT_H

#include "cascfile.h"
#include "wmo.h"
#include "model.h"

#pragma pack(push, 1)
namespace ADT
{
    struct MDDF
    {
        uint32 Id;
        uint32 UniqueId;
        Vec3D Position;
        Vec3D Rotation;
        uint16 Scale;
        uint16 Flags;
    };

    struct MODF
    {
        uint32 Id;
        uint32 UniqueId;
        Vec3D Position;
        Vec3D Rotation;
        AaBox3D Bounds;
        uint16 Flags;
        uint16 DoodadSet;   // can be larger than number of doodad sets in WMO
        uint16 NameSet;
        uint16 Scale;
    };
}
#pragma pack(pop)

struct ADTOutputCache
{
    uint8 Flags;
    std::vector<uint8> Data;
};

class ADTFile
{
private:
    CASCFile _file;
    bool cacheable;
    std::vector<ADTOutputCache>* dirfileCache;
public:
    ADTFile(std::string const& filename, bool cache);
    ADTFile(uint32 fileDataId, std::string const& description, bool cache);
    ~ADTFile();
    std::vector<std::string> WmoInstanceNames;
    std::vector<std::string> ModelInstanceNames;
    bool init(uint32 map_num, uint32 originalMapId);
    bool initFromCache(uint32 map_num, uint32 originalMapId);
};

char const* GetPlainName(char const* FileName);
char* GetPlainName(char* FileName);
char* GetExtension(char* FileName);
void NormalizeFileName(char* name, size_t len);
//void fixMapNamen(char *name, size_t len);

#endif
