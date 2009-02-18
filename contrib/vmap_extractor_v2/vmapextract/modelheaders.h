#ifndef MODELHEADERS_H
#define MODELHEADERS_H

typedef unsigned char uint8;
typedef char int8;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned int uint32;
typedef int int32;

#pragma pack(push,1)

struct ModelHeader {
    char id[4];
    uint8 version[4];
    uint32 nameLength;
    uint32 nameOfs;
    uint32 type;

    uint32 nGlobalSequences;
    uint32 ofsGlobalSequences;
    uint32 nAnimations;
    uint32 ofsAnimations;
    uint32 nC;
    uint32 ofsC;
    uint32 nD;
    uint32 ofsD;
    uint32 nBones;
    uint32 ofsBones;
    uint32 nF;
    uint32 ofsF;

    uint32 nVertices;
    uint32 ofsVertices;
    uint32 nViews;
    uint32 ofsViews;

    uint32 nColors;
    uint32 ofsColors;

    uint32 nTextures;
    uint32 ofsTextures;

    uint32 nTransparency; // H
    uint32 ofsTransparency;
    uint32 nI;   // always unused ?
    uint32 ofsI;
    uint32 nTexAnims;   // J
    uint32 ofsTexAnims;
    uint32 nK;
    uint32 ofsK;

    uint32 nTexFlags;
    uint32 ofsTexFlags;
    uint32 nY;
    uint32 ofsY;

    uint32 nTexLookup;
    uint32 ofsTexLookup;

    uint32 nTexUnitLookup;      // L
    uint32 ofsTexUnitLookup;
    uint32 nTransparencyLookup; // M
    uint32 ofsTransparencyLookup;
    uint32 nTexAnimLookup;
    uint32 ofsTexAnimLookup;

    float floats[14];

    uint32 nBoundingTriangles;
    uint32 ofsBoundingTriangles;
    uint32 nBoundingVertices;
    uint32 ofsBoundingVertices;
    uint32 nBoundingNormals;
    uint32 ofsBoundingNormals;

    uint32 nO;
    uint32 ofsO;
    uint32 nP;
    uint32 ofsP;
    uint32 nQ;
    uint32 ofsQ;
    uint32 nLights; // R
    uint32 ofsLights;
    uint32 nCameras; // S
    uint32 ofsCameras;
    uint32 nT;
    uint32 ofsT;
    uint32 nRibbonEmitters; // U
    uint32 ofsRibbonEmitters;
    uint32 nParticleEmitters; // V
    uint32 ofsParticleEmitters;

};

// block B - animations
struct ModelAnimation {
    uint32 animID;
    uint32 timeStart;
    uint32 timeEnd;

    float moveSpeed;

    uint32 loopType;
    uint32 flags;
    uint32 d1;
    uint32 d2;
    uint32 playSpeed;  // note: this can't be play speed because it's 0 for some models

    Vec3D boxA, boxB;
    float rad;

    int16 s[2];
};


// sub-block in block E - animation data
struct AnimationBlock {
    int16 type;     // interpolation type (0=none, 1=linear, 2=hermite)
    int16 seq;      // global sequence id or -1
    uint32 nRanges;
    uint32 ofsRanges;
    uint32 nTimes;
    uint32 ofsTimes;
    uint32 nKeys;
    uint32 ofsKeys;
};

// block E - bones
struct ModelBoneDef {
    int32 animid;
    int32 flags;
    int16 parent; // parent bone index
    int16 geoid;
    // new int added to the bone definitions.  Added in WoW 2.0
    int32 unknown;
    AnimationBlock translation;
    AnimationBlock rotation;
    AnimationBlock scaling;
    Vec3D pivot;
};

struct ModelTexAnimDef {
    AnimationBlock trans, rot, scale;
};

struct ModelVertex {
    Vec3D pos;
    uint8 weights[4];
    uint8 bones[4];
    Vec3D normal;
    Vec2D texcoords;
    int unk1, unk2; // always 0,0 so this is probably unused
};

struct ModelView {
    uint32 nIndex, ofsIndex; // Vertices in this model (index into vertices[])
    uint32 nTris, ofsTris;   // indices
    uint32 nProps, ofsProps; // additional vtx properties
    uint32 nSub, ofsSub;     // materials/renderops/submeshes
    uint32 nTex, ofsTex;     // material properties/textures
    int32 lod;               // LOD bias?
};


/// One material + render operation
struct ModelGeoset {
    uint16 d1;      // mesh part id?
    uint16 d2;      // ?
    uint16 vstart;  // first vertex
    uint16 vcount;  // num vertices
    uint16 istart;  // first index
    uint16 icount;  // num indices
    uint16 d3;      // number of bone indices
    uint16 d4;      // offset into bone index list
    uint16 d5;      // ?
    uint16 d6;      // root bone?
    Vec3D v;
    float unknown[4];   // Added in WoW 2.0?
};

/// A texture unit (sub of material)
struct ModelTexUnit{
    // probably the texture units
    // size always >=number of materials it seems
    uint16 flags;       // Flags
    uint16 order;       // ?
    uint16 op;          // Material this texture is part of (index into mat)
    uint16 op2;         // Always same as above?
    int16 colorIndex;   // color or -1
    uint16 flagsIndex;  // more flags...
    uint16 texunit;     // Texture unit (0 or 1)
    uint16 d4;          // ? (seems to be always 1)
    uint16 textureid;   // Texture id (index into global texture list)
    uint16 texunit2;    // copy of texture unit value?
    uint16 transid;     // transparency id (index into transparency list)
    uint16 texanimid;   // texture animation id
};

// block X - render flags
struct ModelRenderFlags {
    uint16 flags;
    uint16 blend;
};

// block G - color defs
struct ModelColorDef {
    AnimationBlock color;
    AnimationBlock opacity;
};

// block H - transp defs
struct ModelTransDef {
    AnimationBlock trans;
};

struct ModelTextureDef {
    uint32 type;
    uint32 flags;
    uint32 nameLen;
    uint32 nameOfs;
};

struct ModelLightDef {
    int16 type;
    int16 bone;
    Vec3D pos;
    AnimationBlock ambColor;
    AnimationBlock ambIntensity;
    AnimationBlock color;
    AnimationBlock intensity;
    AnimationBlock attStart;
    AnimationBlock attEnd;
    AnimationBlock unk1;
};

struct ModelCameraDef {
    int32 id;
    float fov, farclip, nearclip;
    AnimationBlock transPos;
    Vec3D pos;
    AnimationBlock transTarget;
    Vec3D target;
    AnimationBlock rot;
};


struct ModelParticleParams {
    float mid;
    uint32 colors[3];
    float sizes[3];
    int16 d[10];
    float unk[3];
    float scales[3];
    float slowdown;
    float rotation;
    float f2[16];
};

struct ModelParticleEmitterDef {
    int32 id;
    int32 flags;
    Vec3D pos;
    int16 bone;
    int16 texture;
    int32 nZero1;
    int32 ofsZero1;
    int32 nZero2;
    int32 ofsZero2;
    int16 blend;
    int16 type;
    int16 s1;
    int16 s2;
    int16 cols;
    int16 rows;
    AnimationBlock params[10];
    ModelParticleParams p;
    AnimationBlock unk;
};


struct ModelRibbonEmitterDef {
    int32 id;
    int32 bone;
    Vec3D pos;
    int32 nTextures;
    int32 ofsTextures;
    int32 nUnknown;
    int32 ofsUnknown;
    AnimationBlock color;
    AnimationBlock opacity;
    AnimationBlock above;
    AnimationBlock below;
    float res, length, unk;
    int16 s1, s2;
    AnimationBlock unk1;
    AnimationBlock unk2;
};


#pragma pack(pop)


#endif

