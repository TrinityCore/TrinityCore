/**
  @file MeshAlgWeld.cpp

  The MeshAlg::computeWeld method.

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu
  @created 2003-10-22
  @edited  2005-02-24

  Copyright 2000-2003, Morgan McGuire.
  All rights reserved.

 */

#include "G3D/MeshAlg.h"
#include "G3D/Table.h"
#include "G3D/Set.h"

namespace G3D {

namespace _internal {

class Welder {
private:

    // Intentionally illegal
    Welder& operator=(const Welder& w);

public:
    /** Indices of newVertexArray elements in <B>or near</B> a grid cell. */
    typedef Array<int> List;

    enum {GRID_RES = 32};

    List grid[GRID_RES][GRID_RES][GRID_RES];

    const Array<Vector3>& oldVertexArray;
    Array<Vector3>&       newVertexArray;
    Array<int>&           toNew;
    Array<int>&           toOld;

    /** Must be less than one grid cell, not checked */
    const float           radius;

    /** (oldVertexArray[i] - offset) * scale is on the range [0, 1] */
    Vector3               offset;
    Vector3               scale;

    Welder
    (const Array<Vector3>& _oldVertexArray,
     Array<Vector3>&       _newVertexArray,
     Array<int>&           _toNew,
     Array<int>&           _toOld,
     float                 _radius);
        
    /**
     Computes the grid index from an ordinate.
     */
    void toGridCoords(Vector3 v, int& x, int& y, int& z) const;

    /** Gets the index of a vertex, adding it to 
        newVertexArray if necessary. */
    int getIndex(const Vector3& vertex);
    
    void weld();
};

} // namespace _internal

} // namespace G3D

template<> struct HashTrait<G3D::_internal::Welder::List*> {
    static size_t hashCode(const G3D::_internal::Welder::List* key) { return reinterpret_cast<size_t>(key); }
};


namespace G3D {
namespace _internal {

Welder::Welder(    
    const Array<Vector3>& _oldVertexArray,
    Array<Vector3>&       _newVertexArray,
    Array<int>&           _toNew,
    Array<int>&           _toOld,
    float                 _radius) :
    oldVertexArray(_oldVertexArray),
    newVertexArray(_newVertexArray),
    toNew(_toNew),
    toOld(_toOld),
    radius(_radius) {

    // Compute a scale factor that moves the range
    // of all ordinates to [0, 1]
    Vector3 minBound = Vector3::inf();
    Vector3 maxBound = -minBound;

    for (int i = 0; i < oldVertexArray.size(); ++i) {
        minBound = minBound.min(oldVertexArray[i]);
        maxBound = maxBound.max(oldVertexArray[i]);
    }

    offset = minBound;
    scale  = maxBound - minBound;
    for (int i = 0; i < 3; ++i) {
        // The model might have zero extent along some axis
        if (fuzzyEq(scale[i], 0.0f)) {
            scale[i] = 1.0;
        } else {
            scale[i] = 1.0f / scale[i];
        }
    }
}


void Welder::toGridCoords(Vector3 v, int& x, int& y, int& z) const {
    v = (v - offset) * scale;
    x = iClamp(iFloor(v.x * GRID_RES), 0, GRID_RES - 1);
    y = iClamp(iFloor(v.y * GRID_RES), 0, GRID_RES - 1);
    z = iClamp(iFloor(v.z * GRID_RES), 0, GRID_RES - 1);
}


int Welder::getIndex(const Vector3& vertex) {

    int closestIndex = -1;
    double distanceSquared = inf();

    int ix, iy, iz;
    toGridCoords(vertex, ix, iy, iz);

    // Check against all vertices within radius of this grid cube
    const List& list = grid[ix][iy][iz];

    for (int i = 0; i < list.size(); ++i) {
        double d = (newVertexArray[list[i]] - vertex).squaredMagnitude();

        if (d < distanceSquared) {
            distanceSquared = d;
            closestIndex = list[i];
        }
    }

    if (distanceSquared <= radius * radius) {

        return closestIndex;

    } else {

        // This is a new vertex
        int newIndex = newVertexArray.size();
        newVertexArray.append(vertex);

        // Create a new vertex and store its index in the
        // neighboring grid cells (usually, only 1 neighbor)

        Set<List*> neighbors;

        for (float dx = -1; dx <= +1; ++dx) {
            for (float dy = -1; dy <= +1; ++dy) {
                for (float dz = -1; dz <= +1; ++dz) {
                    int ix, iy, iz;
                    toGridCoords(vertex + Vector3(dx, dy, dz) * radius, ix, iy, iz);
                    neighbors.insert(&(grid[ix][iy][iz]));
                }
            }
        }

        Set<List*>::Iterator neighbor(neighbors.begin());
        Set<List*>::Iterator none(neighbors.end());

        while (neighbor != none) {
            (*neighbor)->append(newIndex);
            ++neighbor;
        }

        return newIndex;
    }
}


void Welder::weld() {
    newVertexArray.resize(0);

    // Prime the vertex positions
    for (int i = 0; i < oldVertexArray.size(); ++i) {
        getIndex(oldVertexArray[i]);
    }

    // Now create the official remapping by snapping to 
    // nearby vertices.
    toNew.resize(oldVertexArray.size());
    toOld.resize(newVertexArray.size());

    for (int oi = 0; oi < oldVertexArray.size(); ++oi) {
        toNew[oi] = getIndex(oldVertexArray[oi]);
        toOld[toNew[oi]] = oi;
    }
}

} // internal namespace


void MeshAlg::computeWeld(
    const Array<Vector3>& oldVertexArray,
    Array<Vector3>&       newVertexArray,
    Array<int>&           toNew,
    Array<int>&           toOld,
    float                 radius) {

    shared_ptr<_internal::Welder> welder = shared_ptr<_internal::Welder> (new _internal::Welder(oldVertexArray, newVertexArray, toNew, toOld, radius));
    welder->weld();
}

} // G3D namespace
