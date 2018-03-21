/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "adtfile.h"
#include "DB2CascFileSource.h"
#include "DB2Meta.h"
#include "Errors.h"
#include "model.h"
#include "StringFormat.h"
#include "vmapexport.h"
#include <CascLib.h>
#include <algorithm>
#include <cstdio>

bool ExtractSingleModel(std::string& fname)
{
    if (fname.substr(fname.length() - 4, 4) == ".mdx")
    {
        fname.erase(fname.length() - 2, 2);
        fname.append("2");
    }

    std::string originalName = fname;

    char* name = GetPlainName((char*)fname.c_str());
    FixNameCase(name, strlen(name));
    FixNameSpaces(name, strlen(name));

    std::string output(szWorkDirWmo);
    output += "/";
    output += name;

    if (FileExists(output.c_str()))
        return true;

    Model mdl(originalName);
    if (!mdl.open())
        return false;

    return mdl.ConvertToVMAPModel(output.c_str());
}

extern CASC::StorageHandle CascStorage;

struct GameobjectDisplayInfoLoadInfo
{
    static DB2FileLoadInfo const* Instance()
    {
        static DB2FieldMeta const fields[] =
        {
            { false, FT_INT, "ID" },
            { false, FT_INT, "FileDataID" },
            { false, FT_FLOAT, "GeoBoxMinX" },
            { false, FT_FLOAT, "GeoBoxMinY" },
            { false, FT_FLOAT, "GeoBoxMinZ" },
            { false, FT_FLOAT, "GeoBoxMaxX" },
            { false, FT_FLOAT, "GeoBoxMaxY" },
            { false, FT_FLOAT, "GeoBoxMaxZ" },
            { false, FT_FLOAT, "OverrideLootEffectScale" },
            { false, FT_FLOAT, "OverrideNameScale" },
            { false, FT_SHORT, "ObjectEffectPackageID" },
        };
        static char const* types = "ifffh";
        static uint8 const arraySizes[5] = { 1, 6, 1, 1, 1 };
        static DB2Meta const meta(-1, 5, 0x9F2098D1, types, arraySizes, -1);
        static DB2FileLoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, &meta);
        return &loadInfo;
    }
};

enum ModelTypes : uint32
{
    MODEL_MD20 = '02DM',
    MODEL_MD21 = '12DM',
    MODEL_WMO  = 'MVER'
};

bool GetHeaderMagic(std::string const& fileName, uint32* magic)
{
    *magic = 0;
    CASC::FileHandle file = CASC::OpenFile(CascStorage, fileName.c_str(), CASC_LOCALE_ALL);
    if (!file)
        return false;

    DWORD bytesRead = 0;
    if (!CASC::ReadFile(file, magic, 4, &bytesRead) || bytesRead != 4)
        return false;

    return true;
}

void ExtractGameobjectModels()
{
    printf("Extracting GameObject models...\n");

    DB2CascFileSource source(CascStorage, "DBFilesClient\\GameObjectDisplayInfo.db2");
    DB2FileLoader db2;
    if (!db2.Load(&source, GameobjectDisplayInfoLoadInfo::Instance()))
    {
        printf("Fatal error: Invalid GameObjectDisplayInfo.db2 file format!\n");
        exit(1);
    }

    std::string basepath = szWorkDirWmo;
    basepath += "/";

    std::string modelListPath = basepath + "temp_gameobject_models";
    FILE* model_list = fopen(modelListPath.c_str(), "wb");
    if (!model_list)
    {
        printf("Fatal error: Could not open file %s\n", modelListPath.c_str());
        return;
    }

    for (uint32 rec = 0; rec < db2.GetRecordCount(); ++rec)
    {
        DB2Record record = db2.GetRecord(rec);
        uint32 fileId = record.GetUInt32("FileDataID");
        if (!fileId)
            continue;

        std::string fileName = Trinity::StringFormat("FILE%08X.xxx", fileId);
        bool result = false;
        uint32 header;
        if (!GetHeaderMagic(fileName, &header))
            continue;

        if (header == MODEL_WMO)
            result = ExtractSingleWmo(fileName);
        else if (header == MODEL_MD20 || header == MODEL_MD21)
            result = ExtractSingleModel(fileName);
        else
            ASSERT(false, "%s header: %d - %c%c%c%c", fileName.c_str(), header, (header >> 24) & 0xFF, (header >> 16) & 0xFF, (header >> 8) & 0xFF, header & 0xFF);

        if (result)
        {
            uint32 displayId = record.GetId();
            uint32 path_length = fileName.length();
            fwrite(&displayId, sizeof(uint32), 1, model_list);
            fwrite(&path_length, sizeof(uint32), 1, model_list);
            fwrite(fileName.c_str(), sizeof(char), path_length, model_list);
        }
    }

    fclose(model_list);

    printf("Done!\n");
}
