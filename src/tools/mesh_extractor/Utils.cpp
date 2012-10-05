#include "Utils.h"
#include "WorldModelHandler.h"
#include "Constants.h"
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

std::string Utils::ReadString( FILE* file )
{
    std::string ret;
    int i = 0;
    while (true)
    {
        char b;
        fread(&b, sizeof(char), 1, file);
        if (b == 0)
            break;
        ret[i++] = b;
    }
    return ret;
}

uint32 Utils::Size( FILE* file )
{
    // store the old position
    uint32 offset = ftell(file);
    // Get file size
    fseek(file, 0, SEEK_END);
    uint32 size = ftell(file);
    // reset back to the old position
    fseek(file, offset, SEEK_SET);
    return size;
}

Vector3 Utils::ToRecast( Vector3 val )
{
    return Vector3(-val.y, val.z, -val.x);
}

std::string Utils::GetAdtPath( std::string world, int x, int y )
{
    return "World\\Maps\\" + world + "\\" + world + "_" + Utils::ToString(x) + "_" + Utils::ToString(y) + ".adt";
}

std::string Utils::FixModelPath( std::string path )
{
    return Utils::GetPathBase(path) + ".M2";
}

G3D::Matrix4 Utils::RotationX(float angle)
{
    float _cos = cos(angle);
    float _sin = sin(angle);
    G3D::Matrix4 ret = G3D::Matrix4::identity();
    ret[2][2] = _cos;
    ret[2][3] = _sin;
    ret[3][2] = -_sin;
    ret[3][3] = _cos;
    return ret;
}

G3D::Matrix4 Utils::GetTransformation(IDefinition def)
{
    G3D::Matrix4 translation;
    if (def.Position.x == 0.0f && def.Position.y == 0.0f && def.Position.z == 0.0f)
        translation = G3D::Matrix4::identity();
    else
        translation = G3D::Matrix4::translation(-(def.Position.z - Constants::MaxXY),
            -(def.Position.x - Constants::MaxXY), def.Position.y);

    G3D::Matrix4 rotation = RotationX(ToRadians(def.Rotation.z)) * RotationY(ToRadians(def.Rotation.x)) * RotationZ(ToRadians(def.Rotation.y + 180));
    if (def.Scale() < 1.0f || def.Scale() > 1.0f)
        return G3D::Matrix4::scale(def.Scale()) * rotation * translation;
    return rotation * translation;
}

G3D::Matrix4 Utils::RotationY( float angle )
{
    float _cos = cos(angle);
    float _sin = sin(angle);
    G3D::Matrix4 ret = G3D::Matrix4::identity();
    ret[1][1] = _cos;
    ret[1][3] = -_sin;
    ret[3][1] = _sin;
    ret[3][3] = _cos;
    return ret;
}

G3D::Matrix4 Utils::RotationZ( float angle )
{
    float _cos = cos(angle);
    float _sin = sin(angle);
    G3D::Matrix4 ret = G3D::Matrix4::identity();
    ret[1][1] = _cos;
    ret[1][2] = _sin;
    ret[2][1] = -_sin;
    ret[2][2] = _cos;
    return ret;
}

float Utils::ToRadians( float degrees )
{
    return Constants::PI * degrees / 180.0f;
}

Vector3 Utils::VectorTransform( Vector3 vec, G3D::Matrix4 matrix )
{
    Vector3 ret;
    ret.x = vec.x * matrix[1][1] + vec.y * matrix[2][1] + vec.z * matrix[3][1] + matrix[4][1];
    ret.y = vec.x * matrix[1][2] + vec.y * matrix[2][2] + vec.z * matrix[3][2] + matrix[4][2];
    ret.z = vec.x * matrix[1][3] + vec.y * matrix[2][3] + vec.z * matrix[3][3] + matrix[4][3];
    return ret;
}

std::string Utils::GetPathBase( std::string path )
{
    int lastIndex = path.find_last_of(".");
    if (lastIndex != std::string::npos)
        return path.substr(0, lastIndex);
    return path;
}

Vector3 Vector3::Read( FILE* file )
{
    Vector3 ret;
    fread(&ret, sizeof(Vector3), 1, file);
    return ret;
}

Vector3 Utils::GetLiquidVert(G3D::Matrix4 transformation, Vector3 basePosition, float height, int x, int y)
{
    if (Utils::Distance(height, 0.0f) > 0.5f)
        basePosition.z = 0.0f;
    return Utils::VectorTransform(basePosition + Vector3(basePosition.x * Constants::UnitSize, basePosition.y * Constants::UnitSize, height), transformation);
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

G3D::Matrix4 Utils::GetWmoDoodadTransformation( DoodadInstance inst, WorldModelDefinition root )
{
    G3D::Matrix4 rootTransformation = Utils::GetTransformation(root);
    G3D::Matrix4 translation = G3D::Matrix4::translation(inst.Position.x, inst.Position.y, inst.Position.z);
    G3D::Matrix4 scale = G3D::Matrix4::scale(inst.Scale);
    G3D::Matrix4 rotation = Utils::RotationY(Constants::PI);
    G3D::Quat quat(-inst.QuatY, inst.QuatZ, -inst.QuatX, inst.QuatW);
    G3D::Matrix4 quatRotation = quat.toRotationMatrix();

    return scale * rotation * quatRotation ** translation * rootTransformation;
}

void Utils::SaveToDisk( FILE* stream, std::string path )
{
    FILE* disk = fopen(path.c_str(), "wb");
    if (!disk)
    {
        printf("Could not save file %s to disk, please verify that you have write permissions on that directory\n", path.c_str());
        return;
    }

    uint32 size = Utils::Size(stream);
    uint8* data = new uint8[size];
    // Read the data to an array
    fread(data, 1, size, stream);
    // And write it in the file
    fwrite(data, 1, size, disk);

    // Close the filestream
    fclose(disk);
    // Free the used memory
    delete data;
}

Vector3 Utils::ToWoWCoords( Vector3 vec )
{
    return Vector3(vec.x, -vec.z, vec.y);
}

std::string Utils::GetExtension( std::string path )
{
    std::string::size_type idx = path.rfind('.');
    std::string extension = "";

    if(idx != std::string::npos)
        extension = path.substr(idx+1);
    return extension;
}

void MapChunkHeader::Read(FILE* stream)
{
    fread(&Flags, sizeof(uint32), 1, stream);
    fread(&IndexX, sizeof(uint32), 1, stream);
    fread(&IndexY, sizeof(uint32), 1, stream);
    fread(&Layers, sizeof(uint32), 1, stream);
    fread(&DoodadRefs, sizeof(uint32), 1, stream);
    fread(&OffsetMCVT, sizeof(uint32), 1, stream);
    fread(&OffsetMCNR, sizeof(uint32), 1, stream);
    fread(&OffsetMCLY, sizeof(uint32), 1, stream);
    fread(&OffsetMCRF, sizeof(uint32), 1, stream);
    fread(&OffsetMCAL, sizeof(uint32), 1, stream);
    fread(&SizeMCAL, sizeof(uint32), 1, stream);
    fread(&OffsetMCSH, sizeof(uint32), 1, stream);
    fread(&SizeMCSH, sizeof(uint32), 1, stream);
    fread(&AreaId, sizeof(uint32), 1, stream);
    fread(&MapObjectRefs, sizeof(uint32), 1, stream);
    fread(&Holes, sizeof(uint32), 1, stream);
    LowQualityTextureMap = new uint32[4];
    fread(LowQualityTextureMap, sizeof(uint32), 4, stream);
    fread(&PredTex, sizeof(uint32), 1, stream);
    fread(&NumberEffectDoodad, sizeof(uint32), 1, stream);
    fread(&OffsetMCSE, sizeof(uint32), 1, stream);
    fread(&SoundEmitters, sizeof(uint32), 1, stream);
    fread(&OffsetMCLQ, sizeof(uint32), 1, stream);
    fread(&SizeMCLQ, sizeof(uint32), 1, stream);
    Position = Vector3::Read(stream);
    fread(&OffsetMCCV, sizeof(uint32), 1, stream);
}

void MHDR::Read(FILE* stream)
{
    fread(&Flags, sizeof(uint32), 1, stream);
    fread(&OffsetMCIN, sizeof(uint32), 1, stream);
    fread(&OffsetMTEX, sizeof(uint32), 1, stream);
    fread(&OffsetMMDX, sizeof(uint32), 1, stream);
    fread(&OffsetMMID, sizeof(uint32), 1, stream);
    fread(&OffsetMWMO, sizeof(uint32), 1, stream);
    fread(&OffsetMWID, sizeof(uint32), 1, stream);
    fread(&OffsetMDDF, sizeof(uint32), 1, stream);
    fread(&OffsetMODF, sizeof(uint32), 1, stream);
    fread(&OffsetMFBO, sizeof(uint32), 1, stream);
    fread(&OffsetMH2O, sizeof(uint32), 1, stream);
    fread(&OffsetMTFX, sizeof(uint32), 1, stream);
}

void ModelHeader::Read(FILE* stream)
{
    fread(&Magic, sizeof(char), 4, stream);
    Magic[4] = '\0'; // null-terminate it.
    fread(&Version, sizeof(uint32), 1, stream);
    fread(&LengthModelName, sizeof(uint32), 1, stream);
    fread(&OffsetName, sizeof(uint32), 1, stream);
    fread(&ModelFlags, sizeof(uint32), 1, stream);
    fread(&CountGlobalSequences, sizeof(uint32), 1, stream);
    fread(&OffsetGlobalSequences, sizeof(uint32), 1, stream);
    fread(&CountAnimations, sizeof(uint32), 1, stream);
    fread(&OffsetAnimations, sizeof(uint32), 1, stream);
    fread(&CountAnimationLookup, sizeof(uint32), 1, stream);
    fread(&OffsetAnimationLookup, sizeof(uint32), 1, stream);
    fread(&CountBones, sizeof(uint32), 1, stream);
    fread(&OffsetBones, sizeof(uint32), 1, stream);
    fread(&CountKeyBoneLookup, sizeof(uint32), 1, stream);
    fread(&OffsetKeyBoneLookup, sizeof(uint32), 1, stream);
    fread(&CountVertices, sizeof(uint32), 1, stream);
    fread(&OffsetVertices, sizeof(uint32), 1, stream);
    fread(&CountViews, sizeof(uint32), 1, stream);
    fread(&CountColors, sizeof(uint32), 1, stream);
    fread(&OffsetColors, sizeof(uint32), 1, stream);
    fread(&CountTextures, sizeof(uint32), 1, stream);
    fread(&OffsetTextures, sizeof(uint32), 1, stream);
    fread(&CountTransparency, sizeof(uint32), 1, stream);
    fread(&OffsetTransparency, sizeof(uint32), 1, stream);
    fread(&CountUvAnimation, sizeof(uint32), 1, stream);
    fread(&OffsetUvAnimation, sizeof(uint32), 1, stream);
    fread(&CountTexReplace, sizeof(uint32), 1, stream);
    fread(&OffsetTexReplace, sizeof(uint32), 1, stream);
    fread(&CountRenderFlags, sizeof(uint32), 1, stream);
    fread(&OffsetRenderFlags, sizeof(uint32), 1, stream);
    fread(&CountBoneLookup, sizeof(uint32), 1, stream);
    fread(&OffsetBoneLookup, sizeof(uint32), 1, stream);
    fread(&CountTexLookup, sizeof(uint32), 1, stream);
    fread(&OffsetTexLookup, sizeof(uint32), 1, stream);
    fread(&CountTexUnits, sizeof(uint32), 1, stream);
    fread(&OffsetTexUnits, sizeof(uint32), 1, stream);
    fread(&CountTransLookup, sizeof(uint32), 1, stream);
    fread(&OffsetTransLookup, sizeof(uint32), 1, stream);
    fread(&CountUvAnimLookup, sizeof(uint32), 1, stream);
    fread(&OffsetUvAnimLookup, sizeof(uint32), 1, stream);
    VertexBox[0] = Vector3::Read(stream);
    VertexBox[1] = Vector3::Read(stream);
    fread(&VertexRadius, sizeof(float), 1, stream);
    BoundingBox[0] = Vector3::Read(stream);
    BoundingBox[1] = Vector3::Read(stream);
    fread(&BoundingRadius, sizeof(float), 1, stream);
    fread(&CountBoundingTriangles, sizeof(uint32), 1, stream);
    fread(&OffsetBoundingTriangles, sizeof(uint32), 1, stream);
    fread(&CountBoundingVertices, sizeof(uint32), 1, stream);
    fread(&OffsetBoundingVertices, sizeof(uint32), 1, stream);
    fread(&CountBoundingNormals, sizeof(uint32), 1, stream);
    fread(&OffsetBoundingNormals, sizeof(uint32), 1, stream);
}

WorldModelHeader WorldModelHeader::Read(FILE* stream)
{
    WorldModelHeader ret;
    fread(&ret.CountMaterials, sizeof(uint32), 1, stream);
    fread(&ret.CountGroups, sizeof(uint32), 1, stream);
    fread(&ret.CountPortals, sizeof(uint32), 1, stream);
    fread(&ret.CountLights, sizeof(uint32), 1, stream);
    fread(&ret.CountModels, sizeof(uint32), 1, stream);
    fread(&ret.CountDoodads, sizeof(uint32), 1, stream);
    fread(&ret.CountSets, sizeof(uint32), 1, stream);
    fread(&ret.AmbientColorUnk, sizeof(uint32), 1, stream);
    fread(&ret.WmoId, sizeof(uint32), 1, stream);
    ret.BoundingBox[0] = Vector3::Read(stream);
    ret.BoundingBox[1] = Vector3::Read(stream);
    fread(&ret.LiquidTypeRelated, sizeof(uint32), 1, stream);
    return ret;
}

DoodadInstance DoodadInstance::Read(FILE* stream)
{
    DoodadInstance ret;
    fread(&ret.FileOffset, sizeof(uint32), 1, stream);
    ret.Position = Vector3::Read(stream);
    fread(&ret.QuatW, sizeof(float), 1, stream);
    fread(&ret.QuatX, sizeof(float), 1, stream);
    fread(&ret.QuatY, sizeof(float), 1, stream);
    fread(&ret.QuatZ, sizeof(float), 1, stream);
    fread(&ret.Scale, sizeof(float), 1, stream);
    fread(&ret.LightColor, sizeof(uint32), 1, stream);
    return ret;
}

DoodadSet DoodadSet::Read(FILE* stream)
{
    DoodadSet ret;
    char name[21];
    fread(&name, sizeof(char), 20, stream);
    name[20] = '\0';
    ret.Name = name;
    fread(&ret.FirstInstanceIndex, sizeof(uint32), 1, stream);
    fread(&ret.CountInstances, sizeof(uint32), 1, stream);
    fread(&ret.UnknownZero, sizeof(uint32), 1, stream);
    return ret;
}

LiquidHeader LiquidHeader::Read(FILE* stream)
{
    LiquidHeader ret;
    fread(&ret.CountXVertices, sizeof(uint32), 1, stream);
    fread(&ret.CountYVertices, sizeof(uint32), 1, stream);
    fread(&ret.Width, sizeof(uint32), 1, stream);
    fread(&ret.Height, sizeof(uint32), 1, stream);
    ret.BaseLocation = Vector3::Read(stream);
    fread(&ret.MaterialId, sizeof(uint16), 1, stream);
    return ret;
}

LiquidData LiquidData::Read(FILE* stream, LiquidHeader& header)
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
            uint32 discard;
            fread(&discard, sizeof(uint32), 1, stream);
            float tmp;
            fread(&tmp, sizeof(float), 1, stream);
            ret.HeightMap[x][y] = tmp;
        }
    }

    for (uint32 y = 0; y < header.Height; y++)
    {
        for (uint32 x = 0; x < header.Width; x++)
        {
            uint8 tmp;
            fread(&tmp, sizeof(uint8), 1, stream);
            ret.RenderFlags[x][y] = tmp;
        }
    }

    return ret;
}

H2ORenderMask H2ORenderMask::Read(FILE* stream)
{
    H2ORenderMask ret;
    fread(&ret.Mask, sizeof(uint8), 8, stream);
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

H2OHeader H2OHeader::Read(FILE* stream)
{
    H2OHeader ret;
    fread(&ret.OffsetInformation, sizeof(uint32), 1, stream);
    fread(&ret.LayerCount, sizeof(uint32), 1, stream);
    fread(&ret.OffsetRender, sizeof(uint32), 1, stream);
    return ret;
}

H2OInformation H2OInformation::Read(FILE* stream)
{
    H2OInformation ret;
    fread(&ret.LiquidType, sizeof(uint16), 1, stream);
    fread(&ret.Flags, sizeof(uint16), 1, stream);
    fread(&ret.HeightLevel1, sizeof(float), 1, stream);
    fread(&ret.HeightLevel2, sizeof(float), 1, stream);
    fread(&ret.OffsetX, sizeof(uint8), 1, stream);
    fread(&ret.OffsetY, sizeof(uint8), 1, stream);
    fread(&ret.Width, sizeof(uint8), 1, stream);
    fread(&ret.Height, sizeof(uint8), 1, stream);
    fread(&ret.OffsetMask2, sizeof(uint32), 1, stream);
    fread(&ret.OffsetHeightmap, sizeof(uint32), 1, stream);
    return ret;
}

char* Utils::GetPlainName(const char* FileName)
{
    char* temp;

    if((temp = (char*)strrchr(FileName, '\\')) != NULL)
        FileName = temp + 1;
    return (char*)FileName;
}