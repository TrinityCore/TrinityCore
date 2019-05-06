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

#include "vmapexport.h"
#include "adtfile.h"
#include "StringFormat.h"
#include <algorithm>
#include <cstdio>
#include "Errors.h"

char const* GetPlainName(char const* FileName)
{
    const char * szTemp;

    if((szTemp = strrchr(FileName, '\\')) != nullptr)
        FileName = szTemp + 1;
    return FileName;
}

char* GetPlainName(char* FileName)
{
    char * szTemp;

    if((szTemp = strrchr(FileName, '\\')) != nullptr)
        FileName = szTemp + 1;
    return FileName;
}

void fixnamen(char* name, size_t len)
{
    if (len < 3)
        return;

    for (size_t i = 0; i < len - 3; i++)
    {
        if (i > 0 && name[i] >= 'A' && name[i] <= 'Z' && isalpha(name[i-1]))
            name[i] |= 0x20;
        else if ((i == 0 || !isalpha(name[i-1])) && name[i]>='a' && name[i]<='z')
            name[i] &= ~0x20;
    }
    //extension in lowercase
    for (size_t i = len - 3; i < len; i++)
        name[i] |= 0x20;
}

void fixname2(char* name, size_t len)
{
    if (len < 3)
        return;

    for (size_t i = 0; i < len - 3; i++)
        if (name[i] == ' ')
        name[i] = '_';
}

char* GetExtension(char* FileName)
{
    if (char* szTemp = strrchr(FileName, '.'))
        return szTemp;
    return nullptr;
}

ADTFile::ADTFile(char* filename): _file(filename)
{
    Adtfilename.append(filename);
}

bool ADTFile::init(uint32 map_num, uint32 tileX, uint32 tileY)
{
    if (_file.isEof())
        return false;

    uint32 size;
    std::string dirname = std::string(szWorkDirWmo) + "/dir_bin";
    FILE *dirfile;
    dirfile = fopen(dirname.c_str(), "ab");
    if(!dirfile)
    {
        printf("Can't open dirfile!'%s'\n", dirname.c_str());
        return false;
    }

    while (!_file.isEof())
    {
        char fourcc[5];
        _file.read(&fourcc,4);
        _file.read(&size, 4);
        flipcc(fourcc);
        fourcc[4] = 0;

        size_t nextpos = _file.getPos() + size;

        if (!strcmp(fourcc,"MCIN"))
        {
        }
        else if (!strcmp(fourcc,"MTEX"))
        {
        }
        else if (!strcmp(fourcc,"MMDX"))
        {
            if (size)
            {
                char *buf = new char[size];
                _file.read(buf, size);
                char *p = buf;
                while (p < buf + size)
                {
                    fixnamen(p, strlen(p));
                    char* s = GetPlainName(p);
                    fixname2(s, strlen(s));

                    ModelInstanceNames.emplace_back(s);

                    std::string path(p);
                    ExtractSingleModel(path);

                    p = p+strlen(p)+1;
                }
                delete[] buf;
            }
        }
        else if (!strcmp(fourcc,"MWMO"))
        {
            if (size)
            {
                char* buf = new char[size];
                _file.read(buf, size);
                char* p = buf;
                while (p < buf + size)
                {
                    std::string path(p);

                    char* s = GetPlainName(p);
                    fixnamen(s, strlen(s));
                    fixname2(s, strlen(s));
                    WmoInstanceNames.emplace_back(s);

                    ExtractSingleWmo(path);

                    p += strlen(p) + 1;
                }
                delete[] buf;
            }
        }
        //======================
        else if (!strcmp(fourcc, "MDDF"))
        {
            if (size)
            {
                uint32 doodadCount = size / sizeof(ADT::MDDF);
                for (uint32 i = 0; i < doodadCount; ++i)
                {
                    ADT::MDDF doodadDef;
                    _file.read(&doodadDef, sizeof(ADT::MDDF));
                    Doodad::Extract(doodadDef, ModelInstanceNames[doodadDef.Id].c_str(), map_num, tileX, tileY, dirfile);
                }
            }
        }
        else if (!strcmp(fourcc,"MODF"))
        {
            if (size)
            {
                uint32 mapObjectCount = size / sizeof(ADT::MODF);
                for (uint32 i = 0; i < mapObjectCount; ++i)
                {
                    ADT::MODF mapObjDef;
                    _file.read(&mapObjDef, sizeof(ADT::MODF));
                    MapObject::Extract(mapObjDef, WmoInstanceNames[mapObjDef.Id].c_str(), map_num, tileX, tileY, dirfile);
                    Doodad::ExtractSet(WmoDoodads[WmoInstanceNames[mapObjDef.Id]], mapObjDef, map_num, tileX, tileY, dirfile);
                }
            }
        }
        //======================
        _file.seek(nextpos);
    }
    _file.close();
    fclose(dirfile);
    return true;
}

ADTFile::~ADTFile()
{
    _file.close();
}
