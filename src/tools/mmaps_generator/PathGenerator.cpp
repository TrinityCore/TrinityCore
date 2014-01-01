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

#include "PathCommon.h"
#include "MapBuilder.h"

using namespace MMAP;

bool checkDirectories(bool debugOutput)
{
    std::vector<std::string> dirFiles;

    if (getDirContents(dirFiles, "maps") == LISTFILE_DIRECTORY_NOT_FOUND || dirFiles.empty())
    {
        printf("'maps' directory is empty or does not exist\n");
        return false;
    }

    dirFiles.clear();
    if (getDirContents(dirFiles, "vmaps", "*.vmtree") == LISTFILE_DIRECTORY_NOT_FOUND || dirFiles.empty())
    {
        printf("'vmaps' directory is empty or does not exist\n");
        return false;
    }

    dirFiles.clear();
    if (getDirContents(dirFiles, "mmaps") == LISTFILE_DIRECTORY_NOT_FOUND)
    {
        printf("'mmaps' directory does not exist\n");
        return false;
    }

    dirFiles.clear();
    if (debugOutput)
    {
        if (getDirContents(dirFiles, "meshes") == LISTFILE_DIRECTORY_NOT_FOUND)
        {
            printf("'meshes' directory does not exist (no place to put debugOutput files)\n");
            return false;
        }
    }

    return true;
}

bool handleArgs(int argc, char** argv,
               int &mapnum,
               int &tileX,
               int &tileY,
               float &maxAngle,
               bool &skipLiquid,
               bool &skipContinents,
               bool &skipJunkMaps,
               bool &skipBattlegrounds,
               bool &debugOutput,
               bool &silent,
               bool &bigBaseUnit,
               char* &offMeshInputPath,
               char* &file,
               int& threads)
{
    char* param = NULL;
    for (int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "--maxAngle") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            float maxangle = atof(param);
            if (maxangle <= 90.f && maxangle >= 45.f)
                maxAngle = maxangle;
            else
                printf("invalid option for '--maxAngle', using default\n");
        }
        else if (strcmp(argv[i], "--threads") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;
            threads = atoi(param);
            printf("Using %i threads to extract mmaps\n", threads);
        }
        else if (strcmp(argv[i], "--file") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;
            file = param;
        }
        else if (strcmp(argv[i], "--tile") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            char* stileX = strtok(param, ",");
            char* stileY = strtok(NULL, ",");
            int tilex = atoi(stileX);
            int tiley = atoi(stileY);

            if ((tilex > 0 && tilex < 64) || (tilex == 0 && strcmp(stileX, "0") == 0))
                tileX = tilex;
            if ((tiley > 0 && tiley < 64) || (tiley == 0 && strcmp(stileY, "0") == 0))
                tileY = tiley;

            if (tileX < 0 || tileY < 0)
            {
                printf("invalid tile coords.\n");
                return false;
            }
        }
        else if (strcmp(argv[i], "--skipLiquid") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            if (strcmp(param, "true") == 0)
                skipLiquid = true;
            else if (strcmp(param, "false") == 0)
                skipLiquid = false;
            else
                printf("invalid option for '--skipLiquid', using default\n");
        }
        else if (strcmp(argv[i], "--skipContinents") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            if (strcmp(param, "true") == 0)
                skipContinents = true;
            else if (strcmp(param, "false") == 0)
                skipContinents = false;
            else
                printf("invalid option for '--skipContinents', using default\n");
        }
        else if (strcmp(argv[i], "--skipJunkMaps") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            if (strcmp(param, "true") == 0)
                skipJunkMaps = true;
            else if (strcmp(param, "false") == 0)
                skipJunkMaps = false;
            else
                printf("invalid option for '--skipJunkMaps', using default\n");
        }
        else if (strcmp(argv[i], "--skipBattlegrounds") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            if (strcmp(param, "true") == 0)
                skipBattlegrounds = true;
            else if (strcmp(param, "false") == 0)
                skipBattlegrounds = false;
            else
                printf("invalid option for '--skipBattlegrounds', using default\n");
        }
        else if (strcmp(argv[i], "--debugOutput") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            if (strcmp(param, "true") == 0)
                debugOutput = true;
            else if (strcmp(param, "false") == 0)
                debugOutput = false;
            else
                printf("invalid option for '--debugOutput', using default true\n");
        }
        else if (strcmp(argv[i], "--silent") == 0)
        {
            silent = true;
        }
        else if (strcmp(argv[i], "--bigBaseUnit") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            if (strcmp(param, "true") == 0)
                bigBaseUnit = true;
            else if (strcmp(param, "false") == 0)
                bigBaseUnit = false;
            else
                printf("invalid option for '--bigBaseUnit', using default false\n");
        }
        else if (strcmp(argv[i], "--offMeshInput") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            offMeshInputPath = param;
        }
        else
        {
            int map = atoi(argv[i]);
            if (map > 0 || (map == 0 && (strcmp(argv[i], "0") == 0)))
                mapnum = map;
            else
            {
                printf("invalid map id\n");
                return false;
            }
        }
    }

    return true;
}

int finish(const char* message, int returnValue)
{
    printf("%s", message);
    getchar(); // Wait for user input
    return returnValue;
}

int main(int argc, char** argv)
{
    int threads = 3, mapnum = -1;
    float maxAngle = 55.0f;
    int tileX = -1, tileY = -1;
    bool skipLiquid = false,
         skipContinents = false,
         skipJunkMaps = true,
         skipBattlegrounds = false,
         debugOutput = false,
         silent = false,
         bigBaseUnit = false;
    char* offMeshInputPath = NULL;
    char* file = NULL;

    bool validParam = handleArgs(argc, argv, mapnum,
                                 tileX, tileY, maxAngle,
                                 skipLiquid, skipContinents, skipJunkMaps, skipBattlegrounds,
                                 debugOutput, silent, bigBaseUnit, offMeshInputPath, file, threads);

    if (!validParam)
        return silent ? -1 : finish("You have specified invalid parameters", -1);

    if (mapnum == -1 && debugOutput)
    {
        if (silent)
            return -2;

        printf("You have specifed debug output, but didn't specify a map to generate.\n");
        printf("This will generate debug output for ALL maps.\n");
        printf("Are you sure you want to continue? (y/n) ");
        if (getchar() != 'y')
            return 0;
    }

    if (!checkDirectories(debugOutput))
        return silent ? -3 : finish("Press any key to close...", -3);

    MapBuilder builder(maxAngle, skipLiquid, skipContinents, skipJunkMaps,
                       skipBattlegrounds, debugOutput, bigBaseUnit, offMeshInputPath);

    uint32 start = getMSTime();
    if (file)
        builder.buildMeshFromFile(file);
    else if (tileX > -1 && tileY > -1 && mapnum >= 0)
        builder.buildSingleTile(mapnum, tileX, tileY);
    else if (mapnum >= 0)
        builder.buildMap(uint32(mapnum));
    else
        builder.buildAllMaps(threads);

    if (!silent)
        printf("Finished. MMAPS were built in %u ms!\n", GetMSTimeDiffToNow(start));
    return 0;
}
