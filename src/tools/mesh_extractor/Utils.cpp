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

std::string Utils::ReadString( FILE* file )
{
    std::string ret;
    int i = 0;
    while (true)
    {
        char b;
        if (fread(&b, sizeof(char), 1, file) != 1 || b == 0)
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
    size_t lastIndex = path.find_last_of(".");
    if (lastIndex != std::string::npos)
        return path.substr(0, lastIndex);
    return path;
}

Vector3 Vector3::Read( FILE* file )
{
    Vector3 ret;
    if (fread(&ret, sizeof(Vector3), 1, file) != 1)
        printf("Vector3::Read: Failed to read some data expected 1, read 0\n");
    return ret;
}

Vector3 Utils::GetLiquidVert(G3D::Matrix4 transformation, Vector3 basePosition, float height, int /*x*/, int /*y*/)
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
        printf("SaveToDisk: Could not save file %s to disk, please verify that you have write permissions on that directory\n", path.c_str());
        return;
    }

    uint32 size = Utils::Size(stream);
    uint8* data = new uint8[size];
    // Read the data to an array
    if (fread(data, 1, size, stream) != 1)
    {
        printf("SaveToDisk: Error reading from Stream while trying to save file %s to disck.\n", path.c_str());
        return;        
    }
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
    int count = 0;

    count += fread(&Flags, sizeof(uint32), 1, stream);
    count += fread(&IndexX, sizeof(uint32), 1, stream);
    count += fread(&IndexY, sizeof(uint32), 1, stream);
    count += fread(&Layers, sizeof(uint32), 1, stream);
    count += fread(&DoodadRefs, sizeof(uint32), 1, stream);
    count += fread(&OffsetMCVT, sizeof(uint32), 1, stream);
    count += fread(&OffsetMCNR, sizeof(uint32), 1, stream);
    count += fread(&OffsetMCLY, sizeof(uint32), 1, stream);
    count += fread(&OffsetMCRF, sizeof(uint32), 1, stream);
    count += fread(&OffsetMCAL, sizeof(uint32), 1, stream);
    count += fread(&SizeMCAL, sizeof(uint32), 1, stream);
    count += fread(&OffsetMCSH, sizeof(uint32), 1, stream);
    count += fread(&SizeMCSH, sizeof(uint32), 1, stream);
    count += fread(&AreaId, sizeof(uint32), 1, stream);
    count += fread(&MapObjectRefs, sizeof(uint32), 1, stream);
    count += fread(&Holes, sizeof(uint32), 1, stream);
    LowQualityTextureMap = new uint32[4];
    count += fread(LowQualityTextureMap, sizeof(uint32), 4, stream);
    count += fread(&PredTex, sizeof(uint32), 1, stream);
    count += fread(&NumberEffectDoodad, sizeof(uint32), 1, stream);
    count += fread(&OffsetMCSE, sizeof(uint32), 1, stream);
    count += fread(&SoundEmitters, sizeof(uint32), 1, stream);
    count += fread(&OffsetMCLQ, sizeof(uint32), 1, stream);
    count += fread(&SizeMCLQ, sizeof(uint32), 1, stream);
    Position = Vector3::Read(stream);
    count += fread(&OffsetMCCV, sizeof(uint32), 1, stream);
    
    if (count != 27)
         printf("MapChunkHeader::Read: Failed to read some data expected 27, read %d\n", count);
}

void MHDR::Read(FILE* stream)
{
    int count = 0;

    count += fread(&Flags, sizeof(uint32), 1, stream);
    count += fread(&OffsetMCIN, sizeof(uint32), 1, stream);
    count += fread(&OffsetMTEX, sizeof(uint32), 1, stream);
    count += fread(&OffsetMMDX, sizeof(uint32), 1, stream);
    count += fread(&OffsetMMID, sizeof(uint32), 1, stream);
    count += fread(&OffsetMWMO, sizeof(uint32), 1, stream);
    count += fread(&OffsetMWID, sizeof(uint32), 1, stream);
    count += fread(&OffsetMDDF, sizeof(uint32), 1, stream);
    count += fread(&OffsetMODF, sizeof(uint32), 1, stream);
    count += fread(&OffsetMFBO, sizeof(uint32), 1, stream);
    count += fread(&OffsetMH2O, sizeof(uint32), 1, stream);
    count += fread(&OffsetMTFX, sizeof(uint32), 1, stream);
    
    if (count != 12)
         printf("MHDR::Read: Failed to read some data expected 12, read %d\n", count);
}

void ModelHeader::Read(FILE* stream)
{
    int count = 0;

    count += fread(&Magic, sizeof(char), 4, stream);
    Magic[4] = '\0'; // null-terminate it.
    count += fread(&Version, sizeof(uint32), 1, stream);
    count += fread(&LengthModelName, sizeof(uint32), 1, stream);
    count += fread(&OffsetName, sizeof(uint32), 1, stream);
    count += fread(&ModelFlags, sizeof(uint32), 1, stream);
    count += fread(&CountGlobalSequences, sizeof(uint32), 1, stream);
    count += fread(&OffsetGlobalSequences, sizeof(uint32), 1, stream);
    count += fread(&CountAnimations, sizeof(uint32), 1, stream);
    count += fread(&OffsetAnimations, sizeof(uint32), 1, stream);
    count += fread(&CountAnimationLookup, sizeof(uint32), 1, stream);
    count += fread(&OffsetAnimationLookup, sizeof(uint32), 1, stream);
    count += fread(&CountBones, sizeof(uint32), 1, stream);
    count += fread(&OffsetBones, sizeof(uint32), 1, stream);
    count += fread(&CountKeyBoneLookup, sizeof(uint32), 1, stream);
    count += fread(&OffsetKeyBoneLookup, sizeof(uint32), 1, stream);
    count += fread(&CountVertices, sizeof(uint32), 1, stream);
    count += fread(&OffsetVertices, sizeof(uint32), 1, stream);
    count += fread(&CountViews, sizeof(uint32), 1, stream);
    count += fread(&CountColors, sizeof(uint32), 1, stream);
    count += fread(&OffsetColors, sizeof(uint32), 1, stream);
    count += fread(&CountTextures, sizeof(uint32), 1, stream);
    count += fread(&OffsetTextures, sizeof(uint32), 1, stream);
    count += fread(&CountTransparency, sizeof(uint32), 1, stream);
    count += fread(&OffsetTransparency, sizeof(uint32), 1, stream);
    count += fread(&CountUvAnimation, sizeof(uint32), 1, stream);
    count += fread(&OffsetUvAnimation, sizeof(uint32), 1, stream);
    count += fread(&CountTexReplace, sizeof(uint32), 1, stream);
    count += fread(&OffsetTexReplace, sizeof(uint32), 1, stream);
    count += fread(&CountRenderFlags, sizeof(uint32), 1, stream);
    count += fread(&OffsetRenderFlags, sizeof(uint32), 1, stream);
    count += fread(&CountBoneLookup, sizeof(uint32), 1, stream);
    count += fread(&OffsetBoneLookup, sizeof(uint32), 1, stream);
    count += fread(&CountTexLookup, sizeof(uint32), 1, stream);
    count += fread(&OffsetTexLookup, sizeof(uint32), 1, stream);
    count += fread(&CountTexUnits, sizeof(uint32), 1, stream);
    count += fread(&OffsetTexUnits, sizeof(uint32), 1, stream);
    count += fread(&CountTransLookup, sizeof(uint32), 1, stream);
    count += fread(&OffsetTransLookup, sizeof(uint32), 1, stream);
    count += fread(&CountUvAnimLookup, sizeof(uint32), 1, stream);
    count += fread(&OffsetUvAnimLookup, sizeof(uint32), 1, stream);
    VertexBox[0] = Vector3::Read(stream);
    VertexBox[1] = Vector3::Read(stream);
    count += fread(&VertexRadius, sizeof(float), 1, stream);
    BoundingBox[0] = Vector3::Read(stream);
    BoundingBox[1] = Vector3::Read(stream);
    count += fread(&BoundingRadius, sizeof(float), 1, stream);
    count += fread(&CountBoundingTriangles, sizeof(uint32), 1, stream);
    count += fread(&OffsetBoundingTriangles, sizeof(uint32), 1, stream);
    count += fread(&CountBoundingVertices, sizeof(uint32), 1, stream);
    count += fread(&OffsetBoundingVertices, sizeof(uint32), 1, stream);
    count += fread(&CountBoundingNormals, sizeof(uint32), 1, stream);
    count += fread(&OffsetBoundingNormals, sizeof(uint32), 1, stream);
    
    if (count != 51)
         printf("ModelHeader::Read: Failed to read some data expected 51, read %d\n", count);

}

WorldModelHeader WorldModelHeader::Read(FILE* stream)
{
    WorldModelHeader ret;
    int count = 0;

    count += fread(&ret.CountMaterials, sizeof(uint32), 1, stream);
    count += fread(&ret.CountGroups, sizeof(uint32), 1, stream);
    count += fread(&ret.CountPortals, sizeof(uint32), 1, stream);
    count += fread(&ret.CountLights, sizeof(uint32), 1, stream);
    count += fread(&ret.CountModels, sizeof(uint32), 1, stream);
    count += fread(&ret.CountDoodads, sizeof(uint32), 1, stream);
    count += fread(&ret.CountSets, sizeof(uint32), 1, stream);
    count += fread(&ret.AmbientColorUnk, sizeof(uint32), 1, stream);
    count += fread(&ret.WmoId, sizeof(uint32), 1, stream);
    ret.BoundingBox[0] = Vector3::Read(stream);
    ret.BoundingBox[1] = Vector3::Read(stream);
    count += fread(&ret.LiquidTypeRelated, sizeof(uint32), 1, stream);
    
    if (count != 10)
         printf("WorldModelHeader::Read: Failed to read some data expected 10, read %d\n", count);

    return ret;
}

DoodadInstance DoodadInstance::Read(FILE* stream)
{
    DoodadInstance ret;
    int count = 0;

    count += fread(&ret.FileOffset, sizeof(uint32), 1, stream);
    ret.Position = Vector3::Read(stream);
    count += fread(&ret.QuatW, sizeof(float), 1, stream);
    count += fread(&ret.QuatX, sizeof(float), 1, stream);
    count += fread(&ret.QuatY, sizeof(float), 1, stream);
    count += fread(&ret.QuatZ, sizeof(float), 1, stream);
    count += fread(&ret.Scale, sizeof(float), 1, stream);
    count += fread(&ret.LightColor, sizeof(uint32), 1, stream);
    
    if (count != 7)
         printf("DoodadInstance::Read: Failed to read some data expected 7, read %d\n", count);

    return ret;
}

DoodadSet DoodadSet::Read(FILE* stream)
{
    DoodadSet ret;
    char name[21];
    int count = 0;

    count += fread(&name, sizeof(char), 20, stream);
    name[20] = '\0';
    ret.Name = name;
    count += fread(&ret.FirstInstanceIndex, sizeof(uint32), 1, stream);
    count += fread(&ret.CountInstances, sizeof(uint32), 1, stream);
    count += fread(&ret.UnknownZero, sizeof(uint32), 1, stream);

    if (count != 23)
         printf("DoodadSet::Read: Failed to read some data expected 23, read %d\n", count);

    return ret;
}

LiquidHeader LiquidHeader::Read(FILE* stream)
{
    LiquidHeader ret;
    int count = 0;
    count += fread(&ret.CountXVertices, sizeof(uint32), 1, stream);
    count += fread(&ret.CountYVertices, sizeof(uint32), 1, stream);
    count += fread(&ret.Width, sizeof(uint32), 1, stream);
    count += fread(&ret.Height, sizeof(uint32), 1, stream);
    ret.BaseLocation = Vector3::Read(stream);
    count += fread(&ret.MaterialId, sizeof(uint16), 1, stream);

    if (count != 5)
         printf("LiquidHeader::Read: Failed to read some data expected 5, read %d\n", count);

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
            float tmp;
            if (fread(&discard, sizeof(uint32), 1, stream) == 1 &&
                fread(&tmp, sizeof(float), 1, stream) == 1)
            {
                ret.HeightMap[x][y] = tmp;
            }
        }
    }

    for (uint32 y = 0; y < header.Height; y++)
    {
        for (uint32 x = 0; x < header.Width; x++)
        {
            uint8 tmp = 0;
            if (fread(&tmp, sizeof(uint8), 1, stream) == 1)
                ret.RenderFlags[x][y] = tmp;
        }
    }

    return ret;
}

H2ORenderMask H2ORenderMask::Read(FILE* stream)
{
    H2ORenderMask ret;
    if (int count = fread(&ret.Mask, sizeof(uint8), 8, stream) != 8)
        printf("H2OHeader::Read: Failed to read some data expected 8, read %d\n", count);
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
    int count = 0;
    count += fread(&ret.OffsetInformation, sizeof(uint32), 1, stream);
    count += fread(&ret.LayerCount, sizeof(uint32), 1, stream);
    count += fread(&ret.OffsetRender, sizeof(uint32), 1, stream);

    if (count != 3)
        printf("H2OHeader::Read: Failed to read some data expected 3, read %d\n", count);

    return ret;
}

H2OInformation H2OInformation::Read(FILE* stream)
{
    H2OInformation ret;
    int count = 0;
    count += fread(&ret.LiquidType, sizeof(uint16), 1, stream);
    count += fread(&ret.Flags, sizeof(uint16), 1, stream);
    count += fread(&ret.HeightLevel1, sizeof(float), 1, stream);
    count += fread(&ret.HeightLevel2, sizeof(float), 1, stream);
    count += fread(&ret.OffsetX, sizeof(uint8), 1, stream);
    count += fread(&ret.OffsetY, sizeof(uint8), 1, stream);
    count += fread(&ret.Width, sizeof(uint8), 1, stream);
    count += fread(&ret.Height, sizeof(uint8), 1, stream);
    count += fread(&ret.OffsetMask2, sizeof(uint32), 1, stream);
    count += fread(&ret.OffsetHeightmap, sizeof(uint32), 1, stream);

    if (count != 10)
        printf("H2OInformation::Read: Failed to read some data expected 10, read %d\n", count);

    return ret;
}

char* Utils::GetPlainName(const char* FileName)
{
    char* temp;

    if((temp = (char*)strrchr(FileName, '\\')) != NULL)
        FileName = temp + 1;
    return (char*)FileName;
}

WMOGroupHeader WMOGroupHeader::Read( FILE* stream )
{
    WMOGroupHeader ret;
    int count = 0;
    count += fread(&ret.OffsetGroupName, sizeof(uint32), 1, stream);
    count += fread(&ret.OffsetDescriptiveName, sizeof(uint32), 1, stream);
    count += fread(&ret.Flags, sizeof(uint32), 1, stream);
    ret.BoundingBox[0] = Vector3::Read(stream);
    ret.BoundingBox[1] = Vector3::Read(stream);
    count += fread(&ret.OffsetPortals, sizeof(uint32), 1, stream);
    count += fread(&ret.CountPortals, sizeof(uint32), 1, stream);
    count += fread(&ret.CountBatches, sizeof(uint16), 4, stream);
    count += fread(&ret.Fogs, sizeof(uint8), 4, stream);
    count += fread(&ret.LiquidTypeRelated, sizeof(uint32), 1, stream);
    count += fread(&ret.WmoId, sizeof(uint32), 1, stream);

    if (count != 15)
        printf("WMOGroupHeader::Read: Failed to read some data expected 15, read %d\n", count);

    return ret;
}
