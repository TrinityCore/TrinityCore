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

#ifndef TRINITY_M2STRUCTURE_H
#define TRINITY_M2STRUCTURE_H

#include "Common.h"
#include "Util.h"

#include <G3D/Vector3.h>
#include <G3D/AABox.h>

// Structures using to access raw DBC data and required packing to portability
#pragma pack(push, 1)
// Structures for M2 file. Source: https://wowdev.wiki
template<typename T>
struct M2SplineKey
{
    T p0;
    T p1;
    T p2;
};

struct M2Header
{
    char   Magic[4];               // "MD20"
    uint32 Version;                // The version of the format.
    uint32 lName;                  // Length of the model's name including the trailing \0
    uint32 ofsName;                // Offset to the name, it seems like models can get reloaded by this name.should be unique, i guess.
    uint32 GlobalModelFlags;       // 0x0001: tilt x, 0x0002: tilt y, 0x0008: add 2 fields in header, 0x0020: load .phys data (MoP+), 0x0080: has _lod .skin files (MoP?+), 0x0100: is camera related.
    uint32 nGlobalSequences;
    uint32 ofsGlobalSequences;     // A list of timestamps.
    uint32 nAnimations;
    uint32 ofsAnimations;          // Information about the animations in the model.
    uint32 nAnimationLookup;
    uint32 ofsAnimationLookup;     // Mapping of global IDs to the entries in the Animation sequences block.
    uint32 nBones;                 // MAX_BONES = 0x100
    uint32 ofsBones;               // Information about the bones in this model.
    uint32 nKeyBoneLookup;
    uint32 ofsKeyBoneLookup;       // Lookup table for key skeletal bones.
    uint32 nVertices;
    uint32 ofsVertices;            // Vertices of the model.
    uint32 nViews;                 // Views (LOD) are now in .skins.
    uint32 nSubmeshAnimations;
    uint32 ofsSubmeshAnimations;   // Submesh color and alpha animations definitions.
    uint32 nTextures;
    uint32 ofsTextures;            // Textures of this model.
    uint32 nTransparency;
    uint32 ofsTransparency;        // Transparency of textures.
    uint32 nUVAnimation;
    uint32 ofsUVAnimation;
    uint32 nTexReplace;
    uint32 ofsTexReplace;          // Replaceable Textures.
    uint32 nRenderFlags;
    uint32 ofsRenderFlags;         // Blending modes / render flags.
    uint32 nBoneLookupTable;
    uint32 ofsBoneLookupTable;     // A bone lookup table.
    uint32 nTexLookup;
    uint32 ofsTexLookup;           // The same for textures.
    uint32 nTexUnits;              // possibly removed with cata?!
    uint32 ofsTexUnits;            // And texture units. Somewhere they have to be too.
    uint32 nTransLookup;
    uint32 ofsTransLookup;         // Everything needs its lookup. Here are the transparencies.
    uint32 nUVAnimLookup;
    uint32 ofsUVAnimLookup;
    G3D::AABox BoundingBox;            // min/max( [1].z, 2.0277779f ) - 0.16f seems to be the maximum camera height
    float  BoundingSphereRadius;
    G3D::AABox CollisionBox;
    float  CollisionSphereRadius;
    uint32 nBoundingTriangles;
    uint32 ofsBoundingTriangles;   // Our bounding volumes. Similar structure like in the old ofsViews.
    uint32 nBoundingVertices;
    uint32 ofsBoundingVertices;
    uint32 nBoundingNormals;
    uint32 ofsBoundingNormals;
    uint32 nAttachments;
    uint32 ofsAttachments;         // Attachments are for weapons etc.
    uint32 nAttachLookup;
    uint32 ofsAttachLookup;        // Of course with a lookup.
    uint32 nEvents;
    uint32 ofsEvents;              // Used for playing sounds when dying and a lot else.
    uint32 nLights;
    uint32 ofsLights;              // Lights are mainly used in loginscreens but in wands and some doodads too.
    uint32 nCameras;               // Format of Cameras changed with version 271!
    uint32 ofsCameras;             // The cameras are present in most models for having a model in the Character-Tab.
    uint32 nCameraLookup;
    uint32 ofsCameraLookup;        // And lookup-time again.
    uint32 nRibbonEmitters;
    uint32 ofsRibbonEmitters;      // Things swirling around. See the CoT-entrance for light-trails.
    uint32 nParticleEmitters;
    uint32 ofsParticleEmitters;    // Spells and weapons, doodads and loginscreens use them. Blood dripping of a blade? Particles.
    uint32 nBlendMaps;             // This has to deal with blending. Exists IFF (flags & 0x8) != 0. When set, textures blending is overriden by the associated array. See M2/WotLK#Blend_mode_overrides
    uint32 ofsBlendMaps;           // Same as above. Points to an array of uint16 of nBlendMaps entries -- From WoD information.};
};

struct M2Array
{
    uint32_t number;
    uint32 offset_elements;
};
struct M2Track
{
    uint16_t interpolation_type;
    uint16_t global_sequence;
    M2Array timestamps;
    M2Array values;
};

struct M2Camera
{
    uint32_t type; // 0: portrait, 1: characterinfo; -1: else (flyby etc.); referenced backwards in the lookup table.
    float far_clip;
    float near_clip;
    M2Track positions; // How the camera's position moves. Should be 3*3 floats.
    G3D::Vector3 position_base;
    M2Track target_positions; // How the target moves. Should be 3*3 floats.
    G3D::Vector3 target_position_base;
    M2Track rolldata; // The camera can have some roll-effect. Its 0 to 2*Pi.
    M2Track fovdata;  // FoV for this segment
};
#pragma pack(pop)

#endif
