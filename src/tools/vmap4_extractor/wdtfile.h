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

#include "cascfile.h"
#include "wmo.h"
#include <memory>
#include <string>
#include <vector>

class ADTFile;

#pragma pack(push, 1)
namespace WDT
{
    struct MPHD
    {
        uint32 Flags;
        uint32 LgtFileDataID;
        uint32 OccFileDataID;
        uint32 FogsFileDataID;
        uint32 MpvFileDataID;
        uint32 TexFileDataID;
        uint32 WdlFileDataID;
        uint32 Pd4FileDataID;
    };

    struct MAIN
    {
        struct SMAreaInfo
        {
            uint32 Flag;
            uint32 AsyncId;
        } Data[64][64];
    };

    struct MAID
    {
        struct SMAreaFileIDs
        {
            uint32 RootADT;         // FileDataID of mapname_xx_yy.adt
            uint32 Obj0ADT;         // FileDataID of mapname_xx_yy_obj0.adt
            uint32 Obj1ADT;         // FileDataID of mapname_xx_yy_obj1.adt
            uint32 Tex0ADT;         // FileDataID of mapname_xx_yy_tex0.adt
            uint32 LodADT;          // FileDataID of mapname_xx_yy_lod.adt
            uint32 MapTexture;      // FileDataID of mapname_xx_yy.blp
            uint32 MapTextureN;     // FileDataID of mapname_xx_yy_n.blp
            uint32 MinimapTexture;  // FileDataID of mapxx_yy.blp
        } Data[64][64];
    };
}
#pragma pack(pop)

class WDTFile
{
public:
    WDTFile(uint32 fileDataId, std::string const& description, std::string mapName, bool cache);
    ~WDTFile();
    bool init(uint32 mapId);

    ADTFile* GetMap(int32 x, int32 y);
    void FreeADT(ADTFile* adt);
private:
    CASCFile _file;
    WDT::MPHD _header;
    WDT::MAIN _adtInfo;
    std::unique_ptr<WDT::MAID> _adtFileDataIds;
    std::string _mapName;
    std::vector<std::string> _wmoNames;
    struct ADTCache
    {
        std::unique_ptr<ADTFile> file[64][64];
    };
    std::unique_ptr<ADTCache> _adtCache;
};

#endif
