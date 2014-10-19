/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "model.h"
#include "dbcfile.h"
#include "adtfile.h"
#include "vmapexport.h"

#include <algorithm>
#include <stdio.h>

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

extern HANDLE CascStorage;

void ExtractGameobjectModels()
{
    printf("Extracting GameObject models...");
    DBCFile dbc(CascStorage, "DBFilesClient\\GameObjectDisplayInfo.dbc");
    if(!dbc.open())
    {
        printf("Fatal error: Invalid GameObjectDisplayInfo.dbc file format!\n");
        exit(1);
    }

    DBCFile fileData(CascStorage, "DBFilesClient\\FileData.dbc");
    if (!fileData.open())
    {
        printf("Fatal error: Invalid FileData.dbc file format!\n");
        exit(1);
    }

    std::string basepath = szWorkDirWmo;
    basepath += "/";
    std::string path;

    std::string modelListPath = basepath + "temp_gameobject_models";
    FILE* model_list = fopen(modelListPath.c_str(), "wb");
    if (!model_list)
    {
        printf("Fatal error: Could not open file %s\n", modelListPath.c_str());
        return;
    }

    size_t maxFileId = fileData.getMaxId() + 1;
    uint32* fileDataIndex = new uint32[maxFileId];
    memset(fileDataIndex, 0, maxFileId * sizeof(uint32));
    size_t files = fileData.getRecordCount();
    for (uint32 i = 0; i < files; ++i)
        fileDataIndex[fileData.getRecord(i).getUInt(0)] = i;

    for (DBCFile::Iterator it = dbc.begin(); it != dbc.end(); ++it)
    {
        uint32 fileId = it->getUInt(1);
        if (!fileId)
            continue;

        uint32 fileIndex = fileDataIndex[fileId];
        if (!fileIndex)
            continue;

        std::string filename = fileData.getRecord(fileIndex).getString(1);
        std::string filepath = fileData.getRecord(fileIndex).getString(2);

        path = filepath + filename;

        if (path.length() < 4)
            continue;

        FixNameCase((char*)path.c_str(), path.size());
        char * name = GetPlainName((char*)path.c_str());
        FixNameSpaces(name, strlen(name));

        char * ch_ext = GetExtension(name);
        if (!ch_ext)
            continue;

        strToLower(ch_ext);

        bool result = false;
        if (!strcmp(ch_ext, ".wmo"))
            result = ExtractSingleWmo(path);
        else if (!strcmp(ch_ext, ".mdl"))   // TODO: extract .mdl files, if needed
            continue;
        else if (!strcmp(ch_ext, ".mdx") || !strcmp(ch_ext, ".m2"))
            result = ExtractSingleModel(path);

        if (result)
        {
            uint32 displayId = it->getUInt(0);
            uint32 path_length = strlen(name);
            fwrite(&displayId, sizeof(uint32), 1, model_list);
            fwrite(&path_length, sizeof(uint32), 1, model_list);
            fwrite(name, sizeof(char), path_length, model_list);
        }
    }

    fclose(model_list);

    delete[] fileDataIndex;

    printf("Done!\n");
}
