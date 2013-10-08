#include "Utils.h"
#include "WorldModelHandler.h"
#include "Constants.h"
#include "Stream.h"
#include <cstring>
#include "G3D/Matrix4.h"
#include "G3D/Quat.h"

#ifdef _WIN32
    #include "direct.h"
#else
    #include <sys/stat.h>
    #include <unistd.h>
#endif

const float Constants::TileSize = 533.0f + (1/3.0f);
const float Constants::MaxXY = 32.0f * Constants::TileSize;
const float Constants::ChunkSize = Constants::TileSize / 16.0f;
const float Constants::UnitSize = Constants::ChunkSize / 8.0f;
const float Constants::Origin[] = { -Constants::MaxXY, 0.0f, -Constants::MaxXY };
const float Constants::PI = 3.1415926f;
const float Constants::MaxStandableHeight = 1.5f;
const char* Constants::VMAPMagic =  "VMAP041";
bool Constants::ToWoWCoords = false;
bool Constants::Debug = false;
const float Constants::BaseUnitDim = 0.533333f;
const int Constants::VertexPerMap = (Constants::TileSize / Constants::BaseUnitDim) + 0.5f;
const int Constants::VertexPerTile = 40;
const int Constants::TilesPerMap = Constants::VertexPerMap / Constants::VertexPerTile;

void Utils::CreateDir( const std::string& Path )
{
#ifdef _WIN32
    _mkdir( Path.c_str());
#else
    mkdir( Path.c_str(), 0777 );
#endif
}

void Utils::Reverse(char word[])
{
    int len = strlen(word);
    for (int i = 0;i < len / 2; i++)
    {
        word[i] ^= word[len-i-1];
        word[len-i-1] ^= word[i];
        word[i] ^= word[len-i-1];
    }
}

Vector3 Utils::ToRecast(const Vector3& val )
{
    return Vector3(-val.y, val.z, -val.x);
}

std::string Utils::GetAdtPath(const std::string& world, int x, int y )
{
    return "World\\Maps\\" + world + "\\" + world + "_" + Utils::ToString(x) + "_" + Utils::ToString(y) + ".adt";
}

std::string Utils::FixModelPath(const std::string& path )
{
    return Utils::GetPathBase(path) + ".M2";
}

Vector3 Utils::TransformDoodadVertex(const IDefinition& def, Vector3 vec, bool translate)
{
    // Sources of information:
    /// http://www.pxr.dk/wowdev/wiki/index.php?title=ADT/v18&oldid=3715

    // This function applies to both external doodads and WMOs

    // Rotate our Doodad vertex
    G3D::Matrix4 rot = G3D::Matrix3::fromEulerAnglesXYZ(Utils::ToRadians(def.Rotation.z), Utils::ToRadians(-def.Rotation.x), Utils::ToRadians(def.Rotation.y + 180));
    Vector3 ret = Utils::VectorTransform(vec, rot);

    // And finally scale and translate it to our origin
    ret = ret * def.Scale();
    if (translate)
        ret = ret + Vector3(Constants::MaxXY - def.Position.z, Constants::MaxXY - def.Position.x, def.Position.y);
    return ret;
}

Vector3 Utils::TransformWmoDoodad(const DoodadInstance& inst, const WorldModelDefinition& root, Vector3& vec, bool translate )
{
    G3D::Quat quat = G3D::Quat(-inst.QuatY, inst.QuatZ, -inst.QuatX, inst.QuatW);

    Vector3 ret = Utils::VectorTransform(vec, G3D::Matrix4(quat.toRotationMatrix()));
    ret = ret * (inst.Scale / 1024.0f);
    if (translate)
        ret = ret + Vector3(Constants::MaxXY - inst.Position.z, Constants::MaxXY - inst.Position.x, inst.Position.y);
    return ret;
}

float Utils::ToRadians( float degrees )
{
    return Constants::PI * degrees / 180.0f;
}

Vector3 Utils::VectorTransform(const Vector3& vec, const G3D::Matrix4& matrix, bool normal )
{
    G3D::Vector3 ret(vec.x, vec.y, vec.z);
    ret = matrix.homoMul(ret, normal ? 0 : 1);
    return Vector3(ret.x, ret.y, ret.z);
}

std::string Utils::GetPathBase(const std::string& path )
{
    size_t lastIndex = path.find_last_of(".");
    if (lastIndex != std::string::npos)
        return path.substr(0, lastIndex);
    return path;
}

Vector3 Vector3::Read(Stream* file)
{
    return file->Read<Vector3>();
}

Vector3 Utils::GetLiquidVert(const IDefinition& def, Vector3 basePosition, float height, int x, int y, bool translate)
{
    if (Utils::Distance(height, 0.0f) > 0.5f)
        basePosition.z = 0.0f;
    return Utils::TransformDoodadVertex(def, basePosition + Vector3(x * Constants::UnitSize, y * Constants::UnitSize, height), translate);
}

float Utils::Distance( float x, float y )
{
    return sqrt(x*x + y*y);
}

std::string Utils::Replace( std::string str, const std::string& oldStr, const std::string& newStr )
{
    size_t pos = 0;
    while((pos = str.find(oldStr, pos)) != std::string::npos)
    {
        str.replace(pos, oldStr.length(), newStr);
        pos += newStr.length();
    }
    return str;
}

void Utils::SaveToDisk(Stream* stream, const std::string& path)
{
    FILE* disk = fopen(path.c_str(), "wb");
    if (!disk)
    {
        printf("SaveToDisk: Could not save file %s to disk, please verify that you have write permissions on that directory\n", path.c_str());
        delete stream;
        return;
    }

    uint32 size = stream->GetSize();
    stream->Reset(); // Reset the stream just in case
    
    // Read the data to an array
    char* data = stream->Read(size);
   
    // And write it in the file
    size_t wrote = fwrite(data, size, 1, disk);
    if (wrote != 1)
    {
        printf("SaveToDisk: Error writing to the file while trying to save %s to disk.\n", path.c_str());
        delete[] data;
        delete stream;
        fclose(disk);
        return;
    }

    // Close the filestream
    fclose(disk);
    delete stream;

    // Free the used memory
    delete[] data;
}

Vector3 Utils::ToWoWCoords(const Vector3& vec )
{
    return Vector3(-vec.z, -vec.x, vec.y);
}

std::string Utils::GetExtension( std::string path )
{
    std::string::size_type idx = path.rfind('.');
    std::string extension = "";

    if(idx != std::string::npos)
        extension = path.substr(idx+1);
    return extension;
}

void MapChunkHeader::Read(Stream* stream)
{
    Flags = stream->Read<uint32>();
    IndexX = stream->Read<uint32>();
    IndexY = stream->Read<uint32>();
    Layers = stream->Read<uint32>();
    DoodadRefs = stream->Read<uint32>();
    OffsetMCVT = stream->Read<uint32>();
    OffsetMCNR = stream->Read<uint32>();
    OffsetMCLY = stream->Read<uint32>();
    OffsetMCRF = stream->Read<uint32>();
    OffsetMCAL = stream->Read<uint32>();
    SizeMCAL = stream->Read<uint32>();
    OffsetMCSH = stream->Read<uint32>();
    SizeMCSH = stream->Read<uint32>();
    AreaId = stream->Read<uint32>();
    MapObjectRefs = stream->Read<uint32>();
    Holes = stream->Read<uint32>();
    LowQualityTextureMap = new uint32[4];
    stream->Read(LowQualityTextureMap, sizeof(uint32) * 4);
    PredTex = stream->Read<uint32>();
    NumberEffectDoodad = stream->Read<uint32>();
    OffsetMCSE = stream->Read<uint32>();
    SoundEmitters = stream->Read<uint32>();
    OffsetMCLQ = stream->Read<uint32>();
    SizeMCLQ = stream->Read<uint32>();
    Position = Vector3::Read(stream);
    OffsetMCCV = stream->Read<uint32>();
}

void MHDR::Read(Stream* stream)
{
    int count = 0;

    Flags = stream->Read<uint32>();
    OffsetMCIN = stream->Read<uint32>();
    OffsetMTEX = stream->Read<uint32>();
    OffsetMMDX = stream->Read<uint32>();
    OffsetMMID = stream->Read<uint32>();
    OffsetMWMO = stream->Read<uint32>();
    OffsetMWID = stream->Read<uint32>();
    OffsetMDDF = stream->Read<uint32>();
    OffsetMODF = stream->Read<uint32>();
    OffsetMFBO = stream->Read<uint32>();
    OffsetMH2O = stream->Read<uint32>();
    OffsetMTFX = stream->Read<uint32>();
}

void ModelHeader::Read(Stream* stream)
{
    stream->Read(Magic, 4);
    Magic[4] = '\0'; // null-terminate it.
    Version = stream->Read<uint32>();
    LengthModelName = stream->Read<uint32>();
    OffsetName = stream->Read<uint32>();
    ModelFlags = stream->Read<uint32>();
    CountGlobalSequences = stream->Read<uint32>();
    OffsetGlobalSequences = stream->Read<uint32>();
    CountAnimations = stream->Read<uint32>();
    OffsetAnimations = stream->Read<uint32>();
    CountAnimationLookup = stream->Read<uint32>();
    OffsetAnimationLookup = stream->Read<uint32>();
    CountBones = stream->Read<uint32>();
    OffsetBones = stream->Read<uint32>();
    CountKeyBoneLookup = stream->Read<uint32>();
    OffsetKeyBoneLookup = stream->Read<uint32>();
    CountVertices = stream->Read<uint32>();
    OffsetVertices = stream->Read<uint32>();
    CountViews = stream->Read<uint32>();
    CountColors = stream->Read<uint32>();
    OffsetColors = stream->Read<uint32>();
    CountTextures = stream->Read<uint32>();
    OffsetTextures = stream->Read<uint32>();
    CountTransparency = stream->Read<uint32>();
    OffsetTransparency = stream->Read<uint32>();
    CountUvAnimation = stream->Read<uint32>();
    OffsetUvAnimation = stream->Read<uint32>();
    CountTexReplace = stream->Read<uint32>();
    OffsetTexReplace = stream->Read<uint32>();
    CountRenderFlags = stream->Read<uint32>();
    OffsetRenderFlags = stream->Read<uint32>();
    CountBoneLookup = stream->Read<uint32>();
    OffsetBoneLookup = stream->Read<uint32>();
    CountTexLookup = stream->Read<uint32>();
    OffsetTexLookup = stream->Read<uint32>();
    CountTexUnits = stream->Read<uint32>();
    OffsetTexUnits = stream->Read<uint32>();
    CountTransLookup = stream->Read<uint32>();
    OffsetTransLookup = stream->Read<uint32>();
    CountUvAnimLookup = stream->Read<uint32>();
    OffsetUvAnimLookup = stream->Read<uint32>();
    VertexBox[0] = Vector3::Read(stream);
    VertexBox[1] = Vector3::Read(stream);
    VertexRadius = stream->Read<float>();
    BoundingBox[0] = Vector3::Read(stream);
    BoundingBox[1] = Vector3::Read(stream);
    BoundingRadius = stream->Read<float>();
    CountBoundingTriangles = stream->Read<uint32>();
    OffsetBoundingTriangles = stream->Read<uint32>();
    CountBoundingVertices = stream->Read<uint32>();
    OffsetBoundingVertices = stream->Read<uint32>();
    CountBoundingNormals = stream->Read<uint32>();
    OffsetBoundingNormals = stream->Read<uint32>();
}

WorldModelHeader WorldModelHeader::Read(Stream* stream)
{
    WorldModelHeader ret;
    int count = 0;
    ret.CountMaterials = stream->Read<uint32>();
    ret.CountGroups = stream->Read<uint32>();
    ret.CountPortals = stream->Read<uint32>();
    ret.CountLights = stream->Read<uint32>();
    ret.CountModels = stream->Read<uint32>();
    ret.CountDoodads = stream->Read<uint32>();
    ret.CountSets = stream->Read<uint32>();
    ret.AmbientColorUnk = stream->Read<uint32>();
    ret.WmoId = stream->Read<uint32>();
    ret.BoundingBox[0] = Vector3::Read(stream);
    ret.BoundingBox[1] = Vector3::Read(stream);
    ret.LiquidTypeRelated = stream->Read<uint32>();

    return ret;
}

DoodadInstance DoodadInstance::Read(Stream* stream)
{
    DoodadInstance ret;

    ret.FileOffset = stream->Read<uint32>();
    ret.Position = Vector3::Read(stream);
    ret.QuatW = stream->Read<float>();
    ret.QuatX = stream->Read<float>();
    ret.QuatY = stream->Read<float>();
    ret.QuatZ = stream->Read<float>();
    ret.Scale = stream->Read<float>();
    ret.LightColor = stream->Read<uint32>();
    return ret;
}

DoodadSet DoodadSet::Read(Stream* stream)
{
    DoodadSet ret;

    ret.Name = std::string(stream->Read(20), 20);
    ret.FirstInstanceIndex = stream->Read<uint32>();
    ret.CountInstances = stream->Read<uint32>();
    ret.UnknownZero = stream->Read<uint32>();
    
    return ret;
}

LiquidHeader LiquidHeader::Read(Stream* stream)
{
    LiquidHeader ret;
    ret.CountXVertices = stream->Read<uint32>();
    ret.CountYVertices = stream->Read<uint32>();
    ret.Width = stream->Read<uint32>();
    ret.Height = stream->Read<uint32>();
    ret.BaseLocation = Vector3::Read(stream);
    ret.MaterialId = stream->Read<uint16>();

    return ret;
}

LiquidData LiquidData::Read(Stream* stream, LiquidHeader& header)
{
    LiquidData ret;
    ret.HeightMap = new float*[header.CountXVertices];
    for (uint32 i = 0; i < header.CountXVertices; ++i)
        ret.HeightMap[i] = new float[header.CountYVertices];

    ret.RenderFlags = new uint8*[header.Width];
    for (uint32 i = 0; i < header.Width; ++i)
        ret.RenderFlags[i] = new uint8[header.Height];

    for (uint32 y = 0; y < header.CountYVertices; y++)
    {
        for (uint32 x = 0; x < header.CountXVertices; x++)
        {
            stream->Read<uint32>(); // Dummy value
            ret.HeightMap[x][y] = stream->Read<float>();
        }
    }

    for (uint32 y = 0; y < header.Height; y++)
        for (uint32 x = 0; x < header.Width; x++)
            ret.RenderFlags[x][y] = stream->Read<uint8>();

    return ret;
}

H2ORenderMask H2ORenderMask::Read(Stream* stream)
{
    H2ORenderMask ret;
    stream->Read(ret.Mask, sizeof(uint8) * 8);
    return ret;
}

bool MCNKLiquidData::IsWater(int x, int y, float height)
{
    if (!Heights)
        return false;
    if (!Mask.ShouldRender(x, y))
        return false;
    float diff = Heights[x][y] - height;
    if (diff > Constants::MaxStandableHeight)
        return true;
    return false;
}

H2OHeader H2OHeader::Read(Stream* stream)
{
    H2OHeader ret;
    
    ret.OffsetInformation = stream->Read<uint32>();
    ret.LayerCount = stream->Read<uint32>();
    ret.OffsetRender = stream->Read<uint32>();
    
    return ret;
}

H2OInformation H2OInformation::Read(Stream* stream)
{
    H2OInformation ret;
    ret.LiquidType = stream->Read<uint16>();
    ret.Flags = stream->Read<uint16>();
    ret.HeightLevel1 = stream->Read<float>();
    ret.HeightLevel2 = stream->Read<float>();
    ret.OffsetX = stream->Read<uint8>();
    ret.OffsetY = stream->Read<uint8>();
    ret.Width = stream->Read<uint8>();
    ret.Height = stream->Read<uint8>();
    ret.OffsetMask2 = stream->Read<uint32>();
    ret.OffsetHeightmap = stream->Read<uint32>();
    
    return ret;
}

char* Utils::GetPlainName(const char* FileName)
{
    char* temp;

    if((temp = (char*)strrchr(FileName, '\\')) != NULL)
        FileName = temp + 1;
    return (char*)FileName;
}

WMOGroupHeader WMOGroupHeader::Read(Stream* stream)
{
    WMOGroupHeader ret;
    ret.OffsetGroupName = stream->Read<uint32>();
    ret.OffsetDescriptiveName = stream->Read<uint32>();
    ret.Flags = stream->Read<uint32>();
    ret.BoundingBox[0] = Vector3::Read(stream);
    ret.BoundingBox[1] = Vector3::Read(stream);
    ret.OffsetPortals = stream->Read<uint32>();
    ret.CountPortals = stream->Read<uint32>();
    stream->Read(ret.CountBatches, sizeof(uint16) * 4);
    stream->Read(ret.Fogs, sizeof(uint8) * 4);
    ret.LiquidTypeRelated = stream->Read<uint32>();
    ret.WmoId = stream->Read<uint32>();
    
    return ret;
}

void Utils::InitializeMmapTileHeader(MmapTileHeader& header)
{
    memset(&header, 0, sizeof(MmapTileHeader));
    header.mmapMagic = MMAP_MAGIC;
    header.dtVersion = DT_NAVMESH_VERSION;
    header.mmapVersion = MMAP_VERSION;
    header.size = 0;
    header.usesLiquids = true;
}
