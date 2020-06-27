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

#include "TileAssembler.h"
#include "BoundingIntervalHierarchy.h"
#include "MapTree.h"
#include "StringFormat.h"
#include "VMapDefinitions.h"
#include <boost/filesystem.hpp>
#include <iomanip>
#include <set>
#include <sstream>

using G3D::Vector3;
using G3D::AABox;
using G3D::inf;
using std::pair;

template<> struct BoundsTrait<VMAP::ModelSpawn*>
{
    static void getBounds(const VMAP::ModelSpawn* const &obj, G3D::AABox& out) { out = obj->getBounds(); }
};

namespace VMAP
{
    Vector3 ModelPosition::transform(const Vector3& pIn) const
    {
        Vector3 out = pIn * iScale;
        out = iRotation * out;
        return out;
    }

    //=================================================================

    TileAssembler::TileAssembler(const std::string& pSrcDirName, const std::string& pDestDirName)
        : iDestDir(pDestDirName), iSrcDir(pSrcDirName)
    {
        boost::filesystem::create_directory(iDestDir);
    }

    TileAssembler::~TileAssembler()
    {
    }

    bool TileAssembler::convertWorld2()
    {
        bool success = readMapSpawns();
        if (!success)
            return false;

        float constexpr invTileSize = 1.0f / 533.33333f;

        // export Map data
        while (!mapData.empty())
        {
            MapSpawns data = std::move(mapData.front());
            mapData.pop_front();

            // build global map tree
            std::vector<ModelSpawn*> mapSpawns;
            mapSpawns.reserve(data.UniqueEntries.size());
            printf("Calculating model bounds for map %u...\n", data.MapId);
            for (auto entry = data.UniqueEntries.begin(); entry != data.UniqueEntries.end(); ++entry)
            {
                // M2 models don't have a bound set in WDT/ADT placement data, i still think they're not used for LoS at all on retail
                if (entry->second.flags & MOD_M2)
                    if (!calculateTransformedBound(entry->second))
                        continue;

                mapSpawns.push_back(&entry->second);
                spawnedModelFiles.insert(entry->second.name);

                std::map<uint32, std::set<TileSpawn>>& tileEntries = (entry->second.flags & MOD_PARENT_SPAWN) ? data.ParentTileEntries : data.TileEntries;

                G3D::AABox const& bounds = entry->second.iBound;
                G3D::Vector2int16 low(int16(bounds.low().x * invTileSize), int16(bounds.low().y * invTileSize));
                G3D::Vector2int16 high(int16(bounds.high().x * invTileSize), int16(bounds.high().y * invTileSize));
                for (int x = low.x; x <= high.x; ++x)
                    for (int y = low.y; y <= high.y; ++y)
                        tileEntries[StaticMapTree::packTileID(x, y)].emplace(entry->second.ID, entry->second.flags);
            }

            printf("Creating map tree for map %u...\n", data.MapId);
            BIH pTree;

            try
            {
                pTree.build(mapSpawns, BoundsTrait<ModelSpawn*>::getBounds);
            }
            catch (std::exception& e)
            {
                printf("Exception ""%s"" when calling pTree.build", e.what());
                return false;
            }

            // ===> possibly move this code to StaticMapTree class

            // write map tree file
            std::stringstream mapfilename;
            mapfilename << iDestDir << '/' << std::setfill('0') << std::setw(4) << data.MapId << ".vmtree";
            FILE* mapfile = fopen(mapfilename.str().c_str(), "wb");
            if (!mapfile)
            {
                success = false;
                printf("Cannot open %s\n", mapfilename.str().c_str());
                break;
            }

            //general info
            if (success && fwrite(VMAP_MAGIC, 1, 8, mapfile) != 8) success = false;
            // Nodes
            if (success && fwrite("NODE", 4, 1, mapfile) != 1) success = false;
            if (success) success = pTree.writeToFile(mapfile);

            // spawn id to index map
            uint32 mapSpawnsSize = mapSpawns.size();
            if (success && fwrite("SIDX", 4, 1, mapfile) != 1) success = false;
            if (success && fwrite(&mapSpawnsSize, sizeof(uint32), 1, mapfile) != 1) success = false;
            for (uint32 i = 0; i < mapSpawnsSize; ++i)
            {
                if (success && fwrite(&mapSpawns[i]->ID, sizeof(uint32), 1, mapfile) != 1) success = false;
                if (success && fwrite(&i, sizeof(uint32), 1, mapfile) != 1) success = false;
            }

            fclose(mapfile);

            // <====

            // write map tile files, similar to ADT files, only with extra BIH tree node info
            for (auto tileItr = data.TileEntries.begin(); tileItr != data.TileEntries.end(); ++tileItr)
            {
                uint32 x, y;
                StaticMapTree::unpackTileID(tileItr->first, x, y);
                std::string tileFileName = Trinity::StringFormat("%s/%04u_%02u_%02u.vmtile", iDestDir.c_str(), data.MapId, y, x);
                if (FILE* tileFile = fopen(tileFileName.c_str(), "wb"))
                {
                    std::set<TileSpawn> const& parentTileEntries = data.ParentTileEntries[tileItr->first];

                    uint32 nSpawns = tileItr->second.size() + parentTileEntries.size();

                    // file header
                    if (success && fwrite(VMAP_MAGIC, 1, 8, tileFile) != 8) success = false;
                    // write number of tile spawns
                    if (success && fwrite(&nSpawns, sizeof(uint32), 1, tileFile) != 1) success = false;
                    // write tile spawns
                    for (auto spawnItr = tileItr->second.begin(); spawnItr != tileItr->second.end() && success; ++spawnItr)
                        success = ModelSpawn::writeToFile(tileFile, data.UniqueEntries[spawnItr->Id]);

                    for (auto spawnItr = parentTileEntries.begin(); spawnItr != parentTileEntries.end() && success; ++spawnItr)
                        success = ModelSpawn::writeToFile(tileFile, data.UniqueEntries[spawnItr->Id]);

                    fclose(tileFile);
                }
            }
        }

        // add an object models, listed in temp_gameobject_models file
        exportGameobjectModels();
        // export objects
        std::cout << "\nConverting Model Files" << std::endl;
        for (std::set<std::string>::iterator mfile = spawnedModelFiles.begin(); mfile != spawnedModelFiles.end(); ++mfile)
        {
            std::cout << "Converting " << *mfile << std::endl;
            if (!convertRawFile(*mfile))
            {
                std::cout << "error converting " << *mfile << std::endl;
                success = false;
                break;
            }
        }

        return success;
    }

    bool TileAssembler::readMapSpawns()
    {
        std::string fname = iSrcDir + "/dir_bin";
        FILE* dirf = fopen(fname.c_str(), "rb");
        if (!dirf)
        {
            printf("Could not read dir_bin file!\n");
            return false;
        }
        printf("Read coordinate mapping...\n");
        uint32 mapID, check;
        std::map<uint32, MapSpawns> data;
        while (!feof(dirf))
        {
            // read mapID, Flags, NameSet, UniqueId, Pos, Rot, Scale, Bound_lo, Bound_hi, name
            check = fread(&mapID, sizeof(uint32), 1, dirf);
            if (check == 0) // EoF...
                break;

            ModelSpawn spawn;
            if (!ModelSpawn::readFromFile(dirf, spawn))
                break;

            auto map_iter = data.emplace(std::piecewise_construct, std::forward_as_tuple(mapID), std::forward_as_tuple());
            if (map_iter.second)
            {
                map_iter.first->second.MapId = mapID;
                printf("spawning Map %u\n", mapID);
            }

            map_iter.first->second.UniqueEntries.emplace(spawn.ID, spawn);
        }

        mapData.resize(data.size());
        auto dst = mapData.begin();
        for (auto src = data.begin(); src != data.end(); ++src, ++dst)
            *dst = std::move(src->second);

        bool success = (ferror(dirf) == 0);
        fclose(dirf);
        return success;
    }

    bool TileAssembler::calculateTransformedBound(ModelSpawn &spawn)
    {
        std::string modelFilename(iSrcDir);
        modelFilename.push_back('/');
        modelFilename.append(spawn.name);

        ModelPosition modelPosition;
        modelPosition.iDir = spawn.iRot;
        modelPosition.iScale = spawn.iScale;
        modelPosition.init();

        WorldModel_Raw raw_model;
        if (!raw_model.Read(modelFilename.c_str()))
            return false;

        uint32 groups = raw_model.groupsArray.size();
        if (groups != 1)
            printf("Warning: '%s' does not seem to be a M2 model!\n", modelFilename.c_str());

        AABox modelBound;

        modelBound.merge(modelPosition.transform(raw_model.groupsArray[0].bounds.low()));
        modelBound.merge(modelPosition.transform(raw_model.groupsArray[0].bounds.high()));

        spawn.iBound = modelBound + spawn.iPos;
        spawn.flags |= MOD_HAS_BOUND;
        return true;
    }

#pragma pack(push, 1)
    struct WMOLiquidHeader
    {
        int xverts, yverts, xtiles, ytiles;
        float pos_x;
        float pos_y;
        float pos_z;
        short material;
    };
#pragma pack(pop)
    //=================================================================
    bool TileAssembler::convertRawFile(const std::string& pModelFilename)
    {
        bool success = true;
        std::string filename = iSrcDir;
        if (filename.length() >0)
            filename.push_back('/');
        filename.append(pModelFilename);

        WorldModel_Raw raw_model;
        if (!raw_model.Read(filename.c_str()))
            return false;

        // write WorldModel
        WorldModel model;
        model.setRootWmoID(raw_model.RootWMOID);
        if (!raw_model.groupsArray.empty())
        {
            std::vector<GroupModel> groupsArray;

            uint32 groups = raw_model.groupsArray.size();
            for (uint32 g = 0; g < groups; ++g)
            {
                GroupModel_Raw& raw_group = raw_model.groupsArray[g];
                groupsArray.push_back(GroupModel(raw_group.mogpflags, raw_group.GroupWMOID, raw_group.bounds ));
                groupsArray.back().setMeshData(raw_group.vertexArray, raw_group.triangles);
                groupsArray.back().setLiquidData(raw_group.liquid);
            }

            model.setGroupModels(groupsArray);
        }

        success = model.writeFile(iDestDir + "/" + pModelFilename + ".vmo");
        //std::cout << "readRawFile2: '" << pModelFilename << "' tris: " << nElements << " nodes: " << nNodes << std::endl;
        return success;
    }

    void TileAssembler::exportGameobjectModels()
    {
        FILE* model_list = fopen((iSrcDir + "/" + "temp_gameobject_models").c_str(), "rb");
        if (!model_list)
            return;

        char ident[8];
        if (fread(ident, 1, 8, model_list) != 8 || memcmp(ident, VMAP::RAW_VMAP_MAGIC, 8) != 0)
        {
            fclose(model_list);
            return;
        }

        FILE* model_list_copy = fopen((iDestDir + "/" + GAMEOBJECT_MODELS).c_str(), "wb");
        if (!model_list_copy)
        {
            fclose(model_list);
            return;
        }

        fwrite(VMAP::VMAP_MAGIC, 1, 8, model_list_copy);

        uint32 name_length, displayId;
        uint8 isWmo;
        char buff[500];
        while (true)
        {
            if (fread(&displayId, sizeof(uint32), 1, model_list) != 1)
                if (feof(model_list))   // EOF flag is only set after failed reading attempt
                    break;

            if (fread(&isWmo, sizeof(uint8), 1, model_list) != 1
                || fread(&name_length, sizeof(uint32), 1, model_list) != 1
                || name_length >= sizeof(buff)
                || fread(&buff, sizeof(char), name_length, model_list) != name_length)
            {
                std::cout << "\nFile 'temp_gameobject_models' seems to be corrupted" << std::endl;
                break;
            }

            std::string model_name(buff, name_length);

            WorldModel_Raw raw_model;
            if (!raw_model.Read((iSrcDir + "/" + model_name).c_str()) )
                continue;

            spawnedModelFiles.insert(model_name);
            AABox bounds;
            bool boundEmpty = true;
            for (uint32 g = 0; g < raw_model.groupsArray.size(); ++g)
            {
                std::vector<Vector3>& vertices = raw_model.groupsArray[g].vertexArray;

                uint32 nvectors = vertices.size();
                for (uint32 i = 0; i < nvectors; ++i)
                {
                    Vector3& v = vertices[i];
                    if (boundEmpty)
                        bounds = AABox(v, v), boundEmpty = false;
                    else
                        bounds.merge(v);
                }
            }

            if (bounds.isEmpty())
            {
                std::cout << "\nModel " << std::string(buff, name_length) << " has empty bounding box" << std::endl;
                continue;
            }

            if (!bounds.isFinite())
            {
                std::cout << "\nModel " << std::string(buff, name_length) << " has invalid bounding box" << std::endl;
                continue;
            }

            fwrite(&displayId, sizeof(uint32), 1, model_list_copy);
            fwrite(&isWmo, sizeof(uint8), 1, model_list_copy);
            fwrite(&name_length, sizeof(uint32), 1, model_list_copy);
            fwrite(&buff, sizeof(char), name_length, model_list_copy);
            fwrite(&bounds.low(), sizeof(Vector3), 1, model_list_copy);
            fwrite(&bounds.high(), sizeof(Vector3), 1, model_list_copy);
        }

        fclose(model_list);
        fclose(model_list_copy);
    }

// temporary use defines to simplify read/check code (close file and return at fail)
#define READ_OR_RETURN(V, S) if (fread((V), (S), 1, rf) != 1) { \
                                fclose(rf); printf("%s readfail, op = %s\n", __FUNCTION__, #V); return(false); }
#define READ_OR_RETURN_WITH_DELETE(V, S) if (fread((V), (S), 1, rf) != 1) { \
                                fclose(rf); printf("%s readfail, op = %s\n", __FUNCTION__, #V); delete[] V; return(false); };
#define CMP_OR_RETURN(V, S)  if (strcmp((V), (S)) != 0)        { \
                                fclose(rf); printf("%s cmpfail, %s!=%s\n", __FUNCTION__, V, S);return(false); }

    bool GroupModel_Raw::Read(FILE* rf)
    {
        char blockId[5];
        blockId[4] = 0;
        int blocksize;

        READ_OR_RETURN(&mogpflags, sizeof(uint32));
        READ_OR_RETURN(&GroupWMOID, sizeof(uint32));


        Vector3 vec1, vec2;
        READ_OR_RETURN(&vec1, sizeof(Vector3));

        READ_OR_RETURN(&vec2, sizeof(Vector3));
        bounds.set(vec1, vec2);

        READ_OR_RETURN(&liquidflags, sizeof(uint32));

        // will this ever be used? what is it good for anyway??
        uint32 branches;
        READ_OR_RETURN(&blockId, 4);
        CMP_OR_RETURN(blockId, "GRP ");
        READ_OR_RETURN(&blocksize, sizeof(int));
        READ_OR_RETURN(&branches, sizeof(uint32));
        for (uint32 b=0; b<branches; ++b)
        {
            uint32 indexes;
            // indexes for each branch (not used jet)
            READ_OR_RETURN(&indexes, sizeof(uint32));
        }

        // ---- indexes
        READ_OR_RETURN(&blockId, 4);
        CMP_OR_RETURN(blockId, "INDX");
        READ_OR_RETURN(&blocksize, sizeof(int));
        uint32 nindexes;
        READ_OR_RETURN(&nindexes, sizeof(uint32));
        if (nindexes >0)
        {
            uint16 *indexarray = new uint16[nindexes];
            READ_OR_RETURN_WITH_DELETE(indexarray, nindexes*sizeof(uint16));
            triangles.reserve(nindexes / 3);
            for (uint32 i=0; i<nindexes; i+=3)
                triangles.push_back(MeshTriangle(indexarray[i], indexarray[i+1], indexarray[i+2]));

            delete[] indexarray;
        }

        // ---- vectors
        READ_OR_RETURN(&blockId, 4);
        CMP_OR_RETURN(blockId, "VERT");
        READ_OR_RETURN(&blocksize, sizeof(int));
        uint32 nvectors;
        READ_OR_RETURN(&nvectors, sizeof(uint32));

        if (nvectors >0)
        {
            float *vectorarray = new float[nvectors*3];
            READ_OR_RETURN_WITH_DELETE(vectorarray, nvectors*sizeof(float)*3);
            for (uint32 i=0; i<nvectors; ++i)
                vertexArray.push_back( Vector3(vectorarray + 3*i) );

            delete[] vectorarray;
        }
        // ----- liquid
        liquid = nullptr;
        if (liquidflags & 3)
        {
            READ_OR_RETURN(&blockId, 4);
            CMP_OR_RETURN(blockId, "LIQU");
            READ_OR_RETURN(&blocksize, sizeof(int));
            uint32 liquidType;
            READ_OR_RETURN(&liquidType, sizeof(uint32));
            if (liquidflags & 1)
            {
                WMOLiquidHeader hlq;
                READ_OR_RETURN(&hlq, sizeof(WMOLiquidHeader));
                liquid = new WmoLiquid(hlq.xtiles, hlq.ytiles, Vector3(hlq.pos_x, hlq.pos_y, hlq.pos_z), liquidType);
                uint32 size = hlq.xverts * hlq.yverts;
                READ_OR_RETURN(liquid->GetHeightStorage(), size * sizeof(float));
                size = hlq.xtiles * hlq.ytiles;
                READ_OR_RETURN(liquid->GetFlagsStorage(), size);
            }
            else
            {
                liquid = new WmoLiquid(0, 0, Vector3::zero(), liquidType);
                liquid->GetHeightStorage()[0] = bounds.high().z;
            }
        }

        return true;
    }

    GroupModel_Raw::~GroupModel_Raw()
    {
        delete liquid;
    }

    bool WorldModel_Raw::Read(const char * path)
    {
        FILE* rf = fopen(path, "rb");
        if (!rf)
        {
            printf("ERROR: Can't open raw model file: %s\n", path);
            return false;
        }

        char ident[9];
        ident[8] = '\0';

        READ_OR_RETURN(&ident, 8);
        CMP_OR_RETURN(ident, RAW_VMAP_MAGIC);

        // we have to read one int. This is needed during the export and we have to skip it here
        uint32 tempNVectors;
        READ_OR_RETURN(&tempNVectors, sizeof(tempNVectors));

        uint32 groups;
        READ_OR_RETURN(&groups, sizeof(uint32));
        READ_OR_RETURN(&RootWMOID, sizeof(uint32));

        groupsArray.resize(groups);
        bool succeed = true;
        for (uint32 g = 0; g < groups && succeed; ++g)
            succeed = groupsArray[g].Read(rf);

        if (succeed) /// rf will be freed inside Read if the function had any errors.
            fclose(rf);
        return succeed;
    }

    // drop of temporary use defines
    #undef READ_OR_RETURN
    #undef READ_OR_RETURN_WITH_DELETE
    #undef CMP_OR_RETURN
}
