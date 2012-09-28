#ifndef UTILS_H
#define UTILS_H
#include <cstdio>
#include <string>
#include <sstream>

#include "g3d/Matrix4.h"

#include "Common.h"
#include "Constants.h"

struct Vector3
{
    Vector3() {}
    Vector3(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
    float x;
    float y;
    float z;
    Vector3 operator +(Vector3 const& other)
    {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }
    static Vector3 Read(FILE* file);
};

struct TilePos
{
    TilePos(int x, int y) : X(x), Y(y) {}
    int X;
    int Y;
};

template<typename T>
struct Triangle
{
    Triangle(Constants::TriangleType type, T v0, T v1, T v2) : Type(type), V0(v0), V1(v1), V2(v2) {}
    T V0;
    T V1;
    T V2;
    Constants::TriangleType Type;
};

class MapChunkHeader
{
public:
    MapChunkHeader() {}
    uint32 Flags;
    uint32 IndexX;
    uint32 IndexY;
    uint32 Layers;
    uint32 DoodadRefs;
    uint32 OffsetMCVT;
    uint32 OffsetMCNR;
    uint32 OffsetMCLY;
    uint32 OffsetMCRF;
    uint32 OffsetMCAL;
    uint32 SizeMCAL;
    uint32 OffsetMCSH;
    uint32 SizeMCSH;
    uint32 AreaId;
    uint32 MapObjectRefs;
    uint32 Holes;
    uint32* LowQualityTextureMap;
    uint32 PredTex;
    uint32 NumberEffectDoodad;
    uint32 OffsetMCSE;
    uint32 SoundEmitters;
    uint32 OffsetMCLQ;
    uint32 SizeMCLQ;
    Vector3 Position;
    uint32 OffsetMCCV;

    void Read(FILE* stream)
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
};

class MHDR
{
public:
    MHDR() {}
    uint32 Flags;
    uint32 OffsetMCIN;
    uint32 OffsetMTEX;
    uint32 OffsetMMDX;
    uint32 OffsetMMID;
    uint32 OffsetMWMO;
    uint32 OffsetMWID;
    uint32 OffsetMDDF;
    uint32 OffsetMODF;
    uint32 OffsetMFBO;
    uint32 OffsetMH2O;
    uint32 OffsetMTFX;

    void Read(FILE* stream)
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
};

class ModelHeader
{
public:
    char Magic[5];
    uint32 Version;
    uint32 LengthModelName;
    uint32 OffsetName;
    uint32 ModelFlags;
    uint32 CountGlobalSequences;
    uint32 OffsetGlobalSequences;
    uint32 CountAnimations;
    uint32 OffsetAnimations;
    uint32 CountAnimationLookup;
    uint32 OffsetAnimationLookup;
    uint32 CountBones;
    uint32 OffsetBones;
    uint32 CountKeyBoneLookup;
    uint32 OffsetKeyBoneLookup;
    uint32 CountVertices;
    uint32 OffsetVertices;
    uint32 CountViews;
    uint32 CountColors;
    uint32 OffsetColors;
    uint32 CountTextures;
    uint32 OffsetTextures;
    uint32 CountTransparency;
    uint32 OffsetTransparency;
    uint32 CountUvAnimation;
    uint32 OffsetUvAnimation;
    uint32 CountTexReplace;
    uint32 OffsetTexReplace;
    uint32 CountRenderFlags;
    uint32 OffsetRenderFlags;
    uint32 CountBoneLookup;
    uint32 OffsetBoneLookup;
    uint32 CountTexLookup;
    uint32 OffsetTexLookup;
    uint32 CountTexUnits;
    uint32 OffsetTexUnits;
    uint32 CountTransLookup;
    uint32 OffsetTransLookup;
    uint32 CountUvAnimLookup;
    uint32 OffsetUvAnimLookup;
    Vector3 VertexBox[2];
    float VertexRadius;
    Vector3 BoundingBox[2];
    float BoundingRadius;
    uint32 CountBoundingTriangles;
    uint32 OffsetBoundingTriangles;
    uint32 CountBoundingVertices;
    uint32 OffsetBoundingVertices;
    uint32 CountBoundingNormals;
    uint32 OffsetBoundingNormals;

    void Read(FILE* stream)
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
};

class WorldModelHeader
{
public:
    WorldModelHeader() {}
    uint32 CountMaterials;
    uint32 CountGroups;
    uint32 CountPortals;
    uint32 CountLights;
    uint32 CountModels;
    uint32 CountDoodads;
    uint32 CountSets;
    uint32 AmbientColorUnk;
    uint32 WmoId;
    Vector3 BoundingBox[2];
    uint32 LiquidTypeRelated;

    static WorldModelHeader Read(FILE* stream)
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
};

class DoodadInstance
{
public:
    DoodadInstance() {}
    uint32 FileOffset;
    std::string File;
    Vector3 Position;
    float QuatW;
    float QuatX;
    float QuatY;
    float QuatZ;
    float Scale;
    uint32 LightColor;

    static DoodadInstance Read(FILE* stream)
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
};

class DoodadSet
{
public:
    DoodadSet() {}
    std::string Name;
    uint32 FirstInstanceIndex;
    uint32 CountInstances;
    uint32 UnknownZero;

    static DoodadSet Read(FILE* stream)
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
}

class LiquidHeader
{
public:
    LiquidHeader() {}
    uint32 CountXVertices;
    uint32 CountYVertices;
    uint32 Width;
    uint32 Height;
    Vector3 BaseLocation;
    uint16 MaterialId;

    static LiquidHeader Read(FILE* stream)
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
};

class LiquidData
{
public:
    LiquidData() {}
    float** HeightMap;
    uint8** RenderFlags;

    bool ShouldRender(int x, int y)
    {
        return RenderFlags[x][y] != 0x0F;
    }

    static LiquidData Read(FILE* stream, LiquidHeader header)
    {
        LiquidData ret;
        ret.HeightMap = new float*[header.CountXVertices];
        for (int i = 0; i < header.CountXVertices; ++i)
            ret.HeightMap[i] = new float[header.CountYVertices];

        ret.RenderFlags = new uint8*[header.Width];
        for (int i = 0; i < header.Width; ++i)
            ret.RenderFlags[i] = new uint8[header.Height];

        for (int y = 0; y < header.CountYVertices; y++)
        {
            for (int x = 0; x < header.CountXVertices; x++)
            {
                uint32 discard;
                fread(&discard, sizeof(uint32), 1, stream);
                float tmp;
                fread(&tmp, sizeof(float), 1, stream);
                ret.HeightMap[x][y] = tmp;
            }
        }

        for (int y = 0; y < header.Height; y++)
        {
            for (int x = 0; x < header.Width; x++)
            {
                uint8 tmp;
                fread(&tmp, sizeof(uint8), 1, stream);
                ret.RenderFlags[x][y] = tmp;
            }
        }

        return ret;
    }
};

class H2ORenderMask
{
public:
    H2ORenderMask() {}
    uint8 Mask[8];

    bool ShouldRender(int x, int y)
    {
        return (Mask[y] >> x & 1) != 0;
    }

    static H2ORenderMask Read(FILE* stream)
    {
        H2ORenderMask ret;
        fread(&ret.Mask, sizeof(uint8), 8, stream);
        return ret;
    }
};

class MCNKLiquidData
{
public:
    MCNKLiquidData() {}
    MCNKLiquidData(float** heights, H2ORenderMask mask) : Heights(heights), Mask(mask) {}
    const float MaxStandableHeight = 1.5f;

    float** Heights;
    H2ORenderMask Mask;

    bool IsWater(int x, int y, float height)
    {
        if (!Heights)
            return false;
        if (!Mask->ShouldRender(x, y))
            return false;
        float diff = Heights[x][y] - height;
        if (diff > MaxStandableHeight)
            return true;
        return false;
    }
};

class H2OHeader
{
public:
    H2OHeader() {}
    uint32 OffsetInformation;
    uint32 LayerCount;
    uint32 OffsetRender;

    static H2OHeader Read(FILE* stream)
    {
        H2OHeader ret;
        fread(&ret.OffsetInformation, sizeof(uint32), 1, stream);
        fread(&ret.LayerCount, sizeof(uint32), 1, stream);
        fread(&ret.OffsetRender, sizeof(uint32), 1, stream);
        return ret;
    }
};

class H2OInformation
{
public:
    H2OInformation() {}
    uint16 LiquidType;
    uint16 Flags;
    float HeightLevel1;
    float HeightLevel2;
    uint8 OffsetX;
    uint8 OffsetY;
    uint8 Width;
    uint8 Height;
    uint32 OffsetMask2;
    uint32 OffsetHeightmap;

    static H2OInformation Read(FILE* stream)
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
};

// Dummy class to act as an interface.
class IDefinition
{
public:
    Vector3 Position;
    Vector3 Rotation;
    virtual float Scale() = 0;
};

class Utils
{
public:
    static void Reverse(char word[]);
    static std::string ReadString(FILE* file);
    static uint32 Size(FILE* file);
    static Vector3 ToRecast( Vector3 val );
    static std::string GetAdtPath(std::string world, int x, int y);
    static std::string FixModelPath(std::string path);
    static G3D::Matrix4 GetTransformation(IDefinition def);
    /// They say its better to declare template functions in the header files.
    template <typename T>
    static std::string ToString(T val) 
    { 
        std::stringstream ss;
        ss << val;
        return ss.str();
    }
    static G3D::Matrix4 RotationX(float angle);
    static G3D::Matrix4 RotationY(float angle);
    static G3D::Matrix4 RotationZ(float angle);
    static float ToRadians(float degrees);
    static Vector3 VectorTransform(Vector3 vec, G3D::Matrix matrix);
    static std::string GetPathBase(std::string path);
    static Vector3 GetLiquidVert(G3D::Matrix4 transformation, Vector3 basePosition, float height, int x, int y);
    static float Distance(float x, float y);
    template<typename T>
    static bool IsAllZero(T* arr, uint32 size)
    {
        for (uint32 i = 0; i < size; ++i)
            if (arr[i])
                return false;
        return true;
    }
    static std::string Utils::Replace( std::string str, const std::string& oldStr, const std::string& newStr );

};
#endif