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
#include "DB2CascFileSource.h"
#include "Errors.h"
#include "ExtractorDB2LoadInfo.h"
#include "model.h"
#include "StringFormat.h"
#include "vmapexport.h"
#include "VMapDefinitions.h"
#include <CascLib.h>
#include <algorithm>
#include <cstdio>
#include "advstd.h"

bool ExtractSingleModel(std::string& fname)
{
    if (fname.length() < 4)
        return false;

    std::string extension = fname.substr(fname.length() - 4, 4);
    if (extension == ".mdx" || extension == ".MDX" || extension == ".mdl" || extension == ".MDL")
    {
        fname.erase(fname.length() - 2, 2);
        fname.append("2");
    }

    std::string originalName = fname;

    char* name = GetPlainName((char*)fname.c_str());
    NormalizeFileName(name, strlen(name));

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

extern std::shared_ptr<CASC::Storage> CascStorage;

bool GetHeaderMagic(std::string const& fileName, std::array<char, 4>* magic)
{
    *magic = { };
    std::unique_ptr<CASC::File> file(CascStorage->OpenFile(fileName.c_str(), CASC_LOCALE_ALL_WOW));
    if (!file)
        return false;

    uint32 bytesToRead = uint32(magic->size() * sizeof(std::remove_pointer_t<decltype(magic)>::value_type));
    uint32 bytesRead = 0;
    if (!file->ReadFile(magic->data(), bytesToRead, &bytesRead) || bytesRead != bytesToRead)
        return false;

    return true;
}

void ExtractGameobjectModels()
{
    printf("Extracting GameObject models...\n");

    DB2CascFileSource source(CascStorage, GameobjectDisplayInfoLoadInfo::Instance.Meta->FileDataId);
    DB2FileLoader db2;
    try
    {
        db2.Load(&source, &GameobjectDisplayInfoLoadInfo::Instance);
    }
    catch (std::exception const& e)
    {
        printf("Fatal error: Invalid GameObjectDisplayInfo.db2 file format!\n%s\n", e.what());
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

    fwrite(VMAP::RAW_VMAP_MAGIC, 1, 8, model_list);

    for (uint32 rec = 0; rec < db2.GetRecordCount(); ++rec)
    {
        DB2Record record = db2.GetRecord(rec);
        if (!record)
            continue;

        uint32 fileId = record.GetUInt32("FileDataID");
        if (!fileId)
            continue;

        std::string fileName = Trinity::StringFormat("FILE{:08X}.xxx", fileId);
        bool result = false;
        std::array<char, 4> headerRaw;
        if (!GetHeaderMagic(fileName, &headerRaw))
            continue;

        std::string_view header(headerRaw.data(), headerRaw.size());
        if (header == "REVM")
            result = ExtractSingleWmo(fileName);
        else if (header == "MD20" || header == "MD21")
            result = ExtractSingleModel(fileName);
        else if (header == "BLP2")
            continue;   // broken db2 data
        else
            ABORT_MSG("%s header: 0x%X%X%X%X - " STRING_VIEW_FMT, fileName.c_str(),
                uint32(headerRaw[3]), uint32(headerRaw[2]), uint32(headerRaw[1]), uint32(headerRaw[0]),
                STRING_VIEW_FMT_ARG(header));

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
