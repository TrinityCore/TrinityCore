#ifndef UTILS_H
#define UTILS_H
#include <cstdio>
#include <string>
#include <sstream>

#include "G3D/Matrix4.h"
#include "DetourNavMesh.h"

#include "Define.h"
#include "Constants.h"

#include <ace/Stack_Trace.h>

struct WorldModelDefinition;
class DoodadInstance;

#define ASSERT(assertion) { if (!(assertion)) { ACE_Stack_Trace st; fprintf(stderr, "\n%s:%i in %s ASSERTION FAILED:\n  %s\n%s\n", __FILE__, __LINE__, __FUNCTION__, #assertion, st.c_str()); *((volatile int*)NULL) = 0; } }

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
    Triangle() {}
    Triangle(Constants::TriangleType type, T v0, T v1, T v2) : V0(v0), V1(v1), V2(v2), Type(type) {}
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

    void Read(FILE* stream);
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

    void Read(FILE* stream);
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

    void Read(FILE* stream);
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

    static WorldModelHeader Read(FILE* stream);
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

    static DoodadInstance Read(FILE* stream);
};

class DoodadSet
{
public:
    DoodadSet() {}
    std::string Name;
    uint32 FirstInstanceIndex;
    uint32 CountInstances;
    uint32 UnknownZero;

    static DoodadSet Read(FILE* stream);
};

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

    static LiquidHeader Read(FILE* stream);
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

    static LiquidData Read(FILE* stream, LiquidHeader& header);
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

    static H2ORenderMask Read(FILE* stream);
};

class MCNKLiquidData
{
public:
    MCNKLiquidData() {}
    MCNKLiquidData(float** heights, H2ORenderMask mask) : Heights(heights), Mask(mask) {}

    float** Heights;
    H2ORenderMask Mask;

    bool IsWater(int x, int y, float height);
};

class H2OHeader
{
public:
    H2OHeader() {}
    uint32 OffsetInformation;
    uint32 LayerCount;
    uint32 OffsetRender;

    static H2OHeader Read(FILE* stream);
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

    static H2OInformation Read(FILE* stream);
};

class WMOGroupHeader
{
public:
    WMOGroupHeader() {}

    uint32 OffsetGroupName;
    uint32 OffsetDescriptiveName;
    uint32 Flags;
    Vector3 BoundingBox[2];
    uint32 OffsetPortals;
    uint32 CountPortals;
    uint16 CountBatches[4];
    uint8 Fogs[4];
    uint32 LiquidTypeRelated;
    uint32 WmoId;

    static WMOGroupHeader Read(FILE* stream);
};

// Dummy class to act as an interface.
class IDefinition
{
public:
    Vector3 Position;
    Vector3 Rotation;
    virtual float Scale() const { return 1.0f; };
};

#define MMAP_MAGIC 0x4d4d4150   // 'MMAP'
#define MMAP_VERSION 3

struct MmapTileHeader
{
    uint32 mmapMagic;
    uint32 dtVersion;
    uint32 mmapVersion;
    uint32 size;
    bool usesLiquids;

    MmapTileHeader() : mmapMagic(MMAP_MAGIC), dtVersion(DT_NAVMESH_VERSION),
        mmapVersion(MMAP_VERSION), size(0), usesLiquids(true) {}
};

class Utils
{
public:
    static void Reverse(char word[]);
    static std::string ReadString(FILE* file);
    static uint32 Size(FILE* file);
    static Vector3 ToRecast(const Vector3& val );
    static std::string GetAdtPath(const std::string& world, int x, int y);
    static std::string FixModelPath(const std::string& path);
    static G3D::Matrix4 GetTransformation(const IDefinition& def);
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
    static Vector3 VectorTransform(const Vector3& vec, const G3D::Matrix4& matrix);
    static std::string GetPathBase(const std::string& path);
    static Vector3 GetLiquidVert(const G3D::Matrix4& transformation, Vector3 basePosition, float height, int x, int y);
    static float Distance(float x, float y);
    template<typename T>
    static bool IsAllZero(T* arr, uint32 size)
    {
        for (uint32 i = 0; i < size; ++i)
            if (arr[i])
                return false;
        return true;
    }
    static std::string Replace( std::string str, const std::string& oldStr, const std::string& newStr );
    static G3D::Matrix4 GetWmoDoodadTransformation(const DoodadInstance& inst, const WorldModelDefinition& root );
    static void CreateDir( const std::string& Path );
    static void SaveToDisk(FILE* stream, const std::string& path);
    static Vector3 ToWoWCoords(const Vector3& vec );
    static std::string GetExtension( std::string path );
    static char* GetPlainName(const char* FileName);
};
#endif
