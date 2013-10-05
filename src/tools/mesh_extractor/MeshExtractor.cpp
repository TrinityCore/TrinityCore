#include "MPQManager.h"
#include "WDT.h"
#include "ContinentBuilder.h"
#include "Cache.h"
#include "DBC.h"
#include "Constants.h"
#include "Model.h"

#include "Recast.h"
#include "DetourNavMesh.h"
#include "DetourNavMeshQuery.h"

#include <stdio.h>

#include <set>

MPQManager* MPQHandler;
CacheClass* Cache;

void ExtractMMaps(std::set<uint32>& mapIds, uint32 threads)
{
    DBC* dbc = MPQHandler->GetDBC("Map");
    printf("Map.dbc contains %u rows.\n", dbc->Records.size());
    for (std::vector<Record*>::iterator itr = dbc->Records.begin(); itr != dbc->Records.end(); ++itr)
    {
        uint32 mapId = (*itr)->Values[0];

        // Skip this map if a list of specific maps was provided and this one is not contained in it.
        if (!mapIds.empty() && mapIds.find(mapId) == mapIds.end())
        {
            if (Constants::Debug)
                printf("Map %u will not be built.\n", mapId);
            continue;
        }

        std::string name = (*itr)->GetString(1);
        WDT wdt("World\\maps\\" + name + "\\" + name + ".wdt");
        if (!wdt.IsValid)
        {
            printf("Could not find WDT data for map %u (%s)\n", mapId, name.c_str());
            continue;
        }
        printf("Building %s MapId %u\n", name.c_str(), mapId);
        ContinentBuilder builder(name, mapId, &wdt, threads);
        builder.Build();
    }
}

void ExtractDBCs()
{
    printf("Extracting DBCs\n");
    // Create the file system structure
    std::string baseDBCPath = "dbc/";
    Utils::CreateDir(baseDBCPath);

    std::set<std::string> DBCFiles;
    const size_t extLen = strlen(".dbc");
    // Populate list of DBC files
    // We get the DBC names by going over the (guaranteed to exist) default locale files
    // Then we look in other locale files in case that they are available.
    for (std::map<uint32, std::deque<MPQArchive*> >::iterator itr = MPQHandler->LocaleFiles.begin(); itr != MPQHandler->LocaleFiles.end(); ++itr)
        for (std::deque<MPQArchive*>::iterator itr2 = itr->second.begin(); itr2 != itr->second.end(); ++itr2)
            for (std::vector<std::string>::iterator itr3 = (*itr2)->Files.begin(); itr3 != (*itr2)->Files.end(); ++itr3)
                if (itr3->rfind(".dbc") == itr3->length() - extLen) // Check if the extension is ".dbc"
                    if (DBCFiles.find(*itr3) == DBCFiles.end())
                        DBCFiles.insert(*itr3);

    const size_t folderLen = strlen("DBFilesClient\\");
    // Iterate over all available locales
    for (std::set<uint32>::iterator itr = MPQHandler->AvailableLocales.begin(); itr != MPQHandler->AvailableLocales.end(); ++itr)
    {
        printf("Extracting DBCs for locale %s\n", MPQManager::Languages[*itr]);
        std::string path = baseDBCPath;
        if (*itr != uint32(MPQHandler->BaseLocale))
        {
            path += std::string(MPQManager::Languages[*itr]) + "/";
            Utils::CreateDir(path);
        }

        std::string component = "component.wow-" + std::string(MPQManager::Languages[*itr]) + ".txt";
        // Extract the component file
        Utils::SaveToDisk(MPQHandler->GetFileFromLocale(component, *itr), path + component);
        // Extract the DBC files for the given locale
        for (std::set<std::string>::iterator itr2 = DBCFiles.begin(); itr2 != DBCFiles.end(); ++itr2)
            Utils::SaveToDisk(MPQHandler->GetFileFromLocale(*itr2, *itr), path + (itr2->c_str() + folderLen));
    }
    printf("DBC extraction finished!\n");
}

void ExtractGameobjectModels()
{
    Constants::ToWoWCoords = true;
    printf("Extracting GameObject models\n");

    std::string baseBuildingsPath = "Buildings/";
    std::string baseVmapsPath = "vmaps/";
    Utils::CreateDir(baseVmapsPath);
    Utils::CreateDir(baseBuildingsPath);

    FILE* modelList = fopen((baseVmapsPath + "GameObjectModels.list").c_str(), "wb");
    if (!modelList)
    {
        printf("Could not create file vmaps/GameObjectModels.list, please make sure that you have the write permissions in the folder\n");
        return;
    }

    DBC* dbc = MPQHandler->GetDBC("GameObjectDisplayInfo");
    for (std::vector<Record*>::iterator itr = dbc->Records.begin(); itr != dbc->Records.end(); ++itr)
    {
        std::string path = (*itr)->GetString(1);
        std::string fileName = Utils::GetPlainName(path.c_str());
        std::string extension = Utils::GetExtension(fileName);
        // Convert the extension to lowercase
        std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
        if (extension == "mdx" || extension == "m2")
        {
            fileName = Utils::FixModelPath(fileName);
            Model model(path);

            if (model.IsBad)
                continue;

            FILE* output = fopen((baseBuildingsPath + fileName).c_str(), "wb");
            if (!output)
            {
                printf("Could not create file %s, please check that you have write permissions\n", (baseBuildingsPath + fileName).c_str());
                continue;
            }
            // Placeholder for 0 values
            int Nop[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

            fwrite(Constants::VMAPMagic, 8, 1, output);
            uint32 numVerts = model.Header.CountBoundingVertices;
            fwrite(&numVerts, sizeof(uint32), 1, output);
            uint32 numGroups = 1;
            fwrite(&numGroups, sizeof(uint32), 1, output);
            fwrite(Nop, 4 * 3 , 1, output); // rootwmoid, flags, groupid
            fwrite(Nop, sizeof(float), 3 * 2, output);//bbox, only needed for WMO currently
            fwrite(Nop, 4, 1, output);// liquidflags
            fwrite("GRP ", 4, 1, output);

            uint32 branches = 1;
            uint32 wsize = sizeof(branches) + sizeof(uint32) * branches;
            fwrite(&wsize, sizeof(uint32), 1, output);
            fwrite(&branches, sizeof(branches), 1, output);
            uint32 numTris = model.Header.CountBoundingTriangles;
            fwrite(&numTris, sizeof(uint32), 1, output);
            fwrite("INDX", 4, 1, output);
            wsize = sizeof(uint32) + sizeof(unsigned short) * numTris;
            fwrite(&wsize, sizeof(int), 1, output);
            fwrite(&numTris, sizeof(uint32), 1, output);
            uint16* indices = new uint16[numTris];

            if (numTris > 0)
            {
                uint32 i = 0;
                for (std::vector<Triangle<uint16> >::iterator itr2 = model.Triangles.begin(); itr2 != model.Triangles.end(); ++itr2, ++i)
                {
                    indices[i * 3 + 0] = itr2->V0;
                    indices[i * 3 + 1] = itr2->V1;
                    indices[i * 3 + 2] = itr2->V2;
                }
                fwrite(indices, sizeof(uint16), numTris, output);
            }


            fwrite("VERT", 4, 1, output);
            wsize = sizeof(int) + sizeof(float) * 3 * numVerts;
            fwrite(&wsize, sizeof(int), 1, output);
            fwrite(&numVerts, sizeof(int), 1, output);
            float* vertices = new float[numVerts*3];

            if (numVerts > 0)
            {
                uint32 i = 0;
                for (std::vector<Vector3>::iterator itr2 = model.Vertices.begin(); itr2 != model.Vertices.end(); ++itr2, ++i)
                {
                    vertices[i * 3 + 0] = itr2->x;
                    vertices[i * 3 + 1] = itr2->y;
                    vertices[i * 3 + 2] = itr2->z;
                }

                fwrite(vertices, sizeof(float), numVerts * 3, output);
            }

            fclose(output);
            delete[] indices;
            delete[] vertices;

            uint32 displayId = (*itr)->Values[0];
            uint32 pathLength = fileName.size();
            fwrite(&displayId, sizeof(uint32), 1, modelList);
            fwrite(&pathLength, sizeof(uint32), 1, modelList);
            fwrite(fileName.c_str(), sizeof(char), pathLength, modelList);
        }
        else if (extension == "wmo")
        {
            WorldModelRoot model(path);

            FILE* output = fopen((baseBuildingsPath + fileName).c_str(), "wb");
            if (!output)
            {
                printf("Could not create file %s, please check that you have write permissions\n", (baseBuildingsPath + fileName).c_str());
                continue;
            }

            fwrite(Constants::VMAPMagic, 1, 8, output);
            uint32 numVertices = 0;
            fwrite(&numVertices, sizeof(uint32), 1, output); // will be filled later
            fwrite(&model.Header.CountGroups, sizeof(uint32), 1, output);
            fwrite(&model.Header.WmoId, sizeof(uint32), 1, output);

            const char grp[] = { 'G' , 'R' , 'P', ' ' };
            for (std::vector<WorldModelGroup>::iterator itr2 = model.Groups.begin(); itr2 != model.Groups.end(); ++itr2)
            {
                const WMOGroupHeader& header = itr2->Header;
                fwrite(&header.Flags, sizeof(uint32), 1, output);
                fwrite(&header.WmoId, sizeof(uint32), 1, output);
                fwrite(&header.BoundingBox[0], sizeof(uint32), 1, output);
                fwrite(&header.BoundingBox[1], sizeof(uint32), 1, output);
                uint32 LiquidFlags = itr2->HasLiquidData ? 1 : 0;
                fwrite(&LiquidFlags, sizeof(uint32), 1, output);

                fwrite(grp, sizeof(char), sizeof(grp), output);
                uint32 k = 0;
                uint32 mobaBatch = itr2->MOBALength / 12;
                uint32* MobaEx = new uint32[mobaBatch*4];

                for(uint32 i = 8; i < itr2->MOBALength; i += 12)
                    MobaEx[k++] = itr2->MOBA[i];

                int mobaSizeGrp = mobaBatch * 4 + 4;
                fwrite(&mobaSizeGrp, 4, 1, output);
                fwrite(&mobaBatch, 4, 1, output);
                fwrite(MobaEx, 4, k, output);
                delete[] MobaEx;

                //@TODO: Finish this.
            }

            fclose(output);
        }
    }

    fclose(modelList);
    printf("GameObject models extraction finished!");
    Constants::ToWoWCoords = false;
}

bool HandleArgs(int argc, char** argv, uint32& threads, std::set<uint32>& mapList, bool& debugOutput, uint32& extractFlags)
{
    char* param = NULL;
    extractFlags = 0;

    for (int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "--threads") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            threads = atoi(param);
            printf("Using %u threads\n", threads);
        }
        else if (strcmp(argv[i], "--maps") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            char* copy = strdup(param);
            char* token = strtok(copy, ",");
            while (token)
            {
                mapList.insert(atoi(token));
                token = strtok(NULL, ",");
            }
            
            free(copy);

            printf("Extracting only provided list of maps (%u).\n", uint32(mapList.size()));
        }
        else if (strcmp(argv[i], "--debug") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;
            debugOutput = atoi(param);
            if (debugOutput)
                printf("Output will contain debug information (.obj files)\n");
        }
        else if (strcmp(argv[i], "--extract") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            extractFlags = atoi(param);

            if (!(extractFlags & Constants::EXTRACT_FLAG_ALLOWED)) // Tried to use an invalid flag
                return false;

            printf("Detected flags: \n");
            printf("* Extract DBCs: %s\n", (extractFlags & Constants::EXTRACT_FLAG_DBC) ? "Yes" : "No");
            printf("* Extract Maps: %s\n", (extractFlags & Constants::EXTRACT_FLAG_MAPS) ? "Yes" : "No");
            printf("* Extract VMaps: %s\n", (extractFlags & Constants::EXTRACT_FLAG_VMAPS) ? "Yes" : "No");
            printf("* Extract GameObject Models: %s\n", (extractFlags & Constants::EXTRACT_FLAG_GOB_MODELS) ? "Yes" : "No");
            printf("* Extract MMaps: %s\n", (extractFlags & Constants::EXTRACT_FLAG_MMAPS) ? "Yes" : "No");
        }
    }
    return true;
}

void PrintUsage()
{
    printf("MeshExtractor help.\n");
    printf("* Use \"--threads <number>\" to specify <number> threads, default to 4 (Only available when extracting MMaps)\n");
    printf("* Use \"--maps a,b,c,d,e\" to extract only the maps specified (Do not use spaces)\n");
    printf("* Use \"--debug 1\" to generate debug information of the tiles (Only available when extracting MMaps)\n");
    printf("* Use \"--extract X\" to extract the data specified by the flag X (Note: You can combine the flags with the bitwise OR operator |). Available flags are: \n");
    {
        printf("- %u to extract DBCs\n", Constants::EXTRACT_FLAG_DBC);
        printf("- %u to extract Maps (Not yet implemented)\n", Constants::EXTRACT_FLAG_MAPS);
        printf("- %u to extract VMaps (Not yet implemented)\n", Constants::EXTRACT_FLAG_VMAPS);
        printf("- %u to extract GameObject models (Not yet finished, you need to run VMapAssembler on the extracted files)\n", Constants::EXTRACT_FLAG_GOB_MODELS);
        printf("- %u to extract MMaps (Not yet finished)\n", Constants::EXTRACT_FLAG_MMAPS);
    }
}

void LoadTile(dtNavMesh*& navMesh, const char* tile)
{
    FILE* f = fopen(tile, "rb");
    if (!f)
        return;
    MmapTileHeader header;

    if (fread(&header, sizeof(MmapTileHeader), 1, f) != 1)
        return;

    uint8* nav = new uint8[header.size];
    if (fread(nav, header.size, 1, f) != 1)
        return;

    navMesh->addTile(nav, header.size, DT_TILE_FREE_DATA, 0, NULL);

    fclose(f);
}

int main(int argc, char* argv[])
{
    _setmaxstdio(2048);
    uint32 threads = 4, extractFlags = 0;
    std::set<uint32> mapIds;

    if (!HandleArgs(argc, argv, threads, mapIds, Constants::Debug, extractFlags))
    {
        PrintUsage();
        return -1;
    }

    if (extractFlags == 0)
    {
        printf("You must provide valid extract flags.\n");
        PrintUsage();
        return -1;
    }

    Cache = new CacheClass();
    MPQHandler = new MPQManager();
    MPQHandler->Initialize();

    if (extractFlags & Constants::EXTRACT_FLAG_DBC)
        ExtractDBCs();

    if (extractFlags & Constants::EXTRACT_FLAG_MMAPS)
        ExtractMMaps(mapIds, threads);

    if (extractFlags & Constants::EXTRACT_FLAG_GOB_MODELS)
        ExtractGameobjectModels();

    if (extractFlags & Constants::EXTRACT_FLAG_TEST)
    {
        float start[] = { -1.37402868f, -21.7641087f, -20.1751060f };
        float end[] = { -22.756405f, -62.745014f, -21.371508f };

        //
        float m_spos[3];
        m_spos[0] = -start[1];
        m_spos[1] = start[2];
        m_spos[2] = -start[0];

        //
        float m_epos[3];
        m_epos[0] = -end[1];
        m_epos[1] = end[2];
        m_epos[2] = -end[0];

        //
        dtQueryFilter m_filter;
        m_filter.setIncludeFlags(Constants::POLY_AREA_ROAD | Constants::POLY_AREA_TERRAIN);
        m_filter.setExcludeFlags(Constants::POLY_AREA_WATER);

        //
        float m_polyPickExt[3];
        m_polyPickExt[0] = 2.5f;
        m_polyPickExt[1] = 2.5f;
        m_polyPickExt[2] = 2.5f;

        //
        dtPolyRef m_startRef;
        dtPolyRef m_endRef;

        FILE* mmap = fopen("mmaps/389.mmap", "rb");
        dtNavMeshParams params;
        int count = fread(&params, sizeof(dtNavMeshParams), 1, mmap);
        fclose(mmap);
        if (count != 1)
        {
            printf("main: Error reading from .mmap\n");
            return 0;
        }

        dtNavMesh* navMesh = new dtNavMesh();
        dtNavMeshQuery* navMeshQuery = new dtNavMeshQuery();

        navMesh->init(&params);
        for (int i = 0; i <= 32; ++i)
        {
            for (int j = 0; j <= 32; ++j)
            {
                char buff[100];
                sprintf(buff, "mmaps/389%02i%02i.mmtile", i, j);
                LoadTile(navMesh, buff);
            }
        }
        
        navMeshQuery->init(navMesh, 2048);

        float nearestPt[3];

        navMeshQuery->findNearestPoly(m_spos, m_polyPickExt, &m_filter, &m_startRef, nearestPt);
        navMeshQuery->findNearestPoly(m_epos, m_polyPickExt, &m_filter, &m_endRef, nearestPt);

        if ( !m_startRef || !m_endRef )
        {
            std::cerr << "Could not find any nearby poly's (" << m_startRef << "," << m_endRef << ")" << std::endl;
            return 0;
        }

        int hops;
        dtPolyRef* hopBuffer = new dtPolyRef[8192];
        dtStatus status = navMeshQuery->findPath(m_startRef, m_endRef, m_spos, m_epos, &m_filter, hopBuffer, &hops, 8192);
        
        int resultHopCount;
        float* straightPath = new float[2048*3];
        unsigned char* pathFlags = new unsigned char[2048];
        dtPolyRef* pathRefs = new dtPolyRef[2048];

        status = navMeshQuery->findStraightPath(m_spos, m_epos, hopBuffer, hops, straightPath, pathFlags, pathRefs, &resultHopCount, 2048);
        std::vector<Vector3> FinalPath;
        FinalPath.reserve(resultHopCount);
        for (uint32 i = 0; i < resultHopCount; ++i)
        {
            Vector3 finalV = Utils::ToWoWCoords(Vector3(straightPath[i * 3 + 0], straightPath[i * 3 + 1], straightPath[i * 3 + 2]));
            FinalPath.push_back(finalV);
            printf("Point %f %f %f\n", finalV.x, finalV.y, finalV.z);
        }
    }

    return 0;
}
