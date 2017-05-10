/**
  @file MeshAlg.cpp

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu
  @created 2003-09-14
  @edited  2008-09-03

  Copyright 2000-2009, Morgan McGuire.
  All rights reserved.

 */

#include "G3D/MeshAlg.h"
#include "G3D/Table.h"
#include "G3D/Set.h"
#include "G3D/Box.h"
#include "G3D/Sphere.h"
#include "G3D/vectorMath.h"
#include "G3D/AABox.h"
#include "G3D/Image1.h"

#include <climits>

namespace G3D {

const int MeshAlg::Face::NONE             = INT_MIN;

void MeshAlg::generateGrid(
    Array<Vector3>&     vertex,
    Array<Vector2>&     texCoord,
    Array<int>&         index,
    int                 wCells, 
    int                 hCells,
    const Vector2&      textureScale,
    bool                spaceCentered,
    bool                twoSided,
    const CoordinateFrame& xform,
    const Image1::Ref&  height) {
        
    vertex.fastClear();
    texCoord.fastClear();
    index.fastClear();

    // Generate vertices                  
    for (int z = 0; z <= hCells; ++z) {
        for (int x = 0; x <= wCells; ++x) {
            Vector3 v(x / (float)wCells, 0, z / (float)hCells);

            Vector2 t = v.xz() * textureScale;

            texCoord.append(t);

            if (height) {
                v.y = height->nearest(v.x * (height->width() - 1), v.z * (height->height() - 1)).value;
            }
            if (spaceCentered) {
                v -= Vector3(0.5f, 0, 0.5f);
            }
            v = xform.pointToWorldSpace(v);
            vertex.append(v);
        }
    }

    // Generate indices
    for (int z = 0; z < hCells; ++z) {
        for (int x = 0; x < wCells; ++x) {
            int A = x + z * (wCells + 1);
            int B = A + 1;
            int C = A + (wCells + 1);
            int D = C + 1;

            //  A       B
            //   *-----*
            //   | \   |
            //   |   \ |
            //   *-----*
            //  C       D

            index.append(A, D, B);
            index.append(A, C, D);
        }
    }

    if (twoSided) {
        // The index array needs to have reversed winding for the bottom
        // and offset by the original number of vertices
        Array<int> ti = index;
        ti.reverse();
        for (int i = 0; i < ti.size(); ++i) {
            ti[i] += vertex.size();
        }
        index.append(ti);

        // Duplicate the arrays
        vertex.append(Array<Vector3>(vertex));
        texCoord.append(Array<Vector2>(texCoord));
    }
}

MeshAlg::Face::Face() {
    for (int i = 0; i < 3; ++i) {
        edgeIndex[i]   = 0;
        vertexIndex[i] = 0;
    }
}


MeshAlg::Edge::Edge() {
    for (int i = 0; i < 2; ++i) {
        vertexIndex[i]   = 0;
        // Negative face indices are faces that don't exist
        faceIndex[i]     = -1;
    }
}


MeshAlg::Geometry& MeshAlg::Geometry::operator=(const MeshAlg::Geometry& src) {
    vertexArray.resize(src.vertexArray.size());
    normalArray.resize(src.vertexArray.size());

    System::memcpy(vertexArray.getCArray(), src.vertexArray.getCArray(), sizeof(Vector3)*vertexArray.size());
    System::memcpy(normalArray.getCArray(), src.normalArray.getCArray(), sizeof(Vector3)*normalArray.size());

    return *this;
}


void MeshAlg::computeNormals(
    Geometry&               geometry,
    const Array<int>&       indexArray) {

    Array<Face> faceArray;
    Array<Vertex> vertexArray;
    Array<Edge> edgeArray;
    Array<Vector3> faceNormalArray;

    computeAdjacency(geometry.vertexArray, indexArray, faceArray, edgeArray, vertexArray);

    computeNormals(geometry.vertexArray, faceArray, vertexArray, 
                   geometry.normalArray, faceNormalArray);
}


void MeshAlg::computeNormals(
    const Array<Vector3>&   vertexGeometry,
    const Array<Face>&      faceArray,
    const Array< Array<int> >& adjacentFaceArray,
    Array<Vector3>&         vertexNormalArray,
    Array<Vector3>&         faceNormalArray) {

    // Construct a fake vertex array for backwards compatibility
    Array<Vertex> fakeVertexArray;
    fakeVertexArray.resize(adjacentFaceArray.size());

    for (int v = 0; v < adjacentFaceArray.size(); ++v) {
        fakeVertexArray[v].faceIndex.resize(adjacentFaceArray[v].size());
        for (int i = 0; i < fakeVertexArray[v].faceIndex.size(); ++i) {
            fakeVertexArray[v].faceIndex[i] = adjacentFaceArray[v][i];
        }
        // We leave out the edges because they aren't used to compute normals
    }

    computeNormals(vertexGeometry, faceArray, fakeVertexArray, 
        vertexNormalArray, faceNormalArray);
}

    
void MeshAlg::computeNormals(
    const Array<Vector3>&   vertexGeometry,
    const Array<Face>&      faceArray,
    const Array<Vertex>&    vertexArray,
    Array<Vector3>&         vertexNormalArray,
    Array<Vector3>&         faceNormalArray) {

    // Face normals (not unit length)
    faceNormalArray.resize(faceArray.size());
    for (int f = 0; f < faceArray.size(); ++f) {
        const Face& face = faceArray[f];

        Vector3 vertex[3];
        for (int j = 0; j < 3; ++j) {
            vertex[j] = vertexGeometry[face.vertexIndex[j]];
            debugAssert(vertex[j].isFinite());
        }

        faceNormalArray[f] = (vertex[1] - vertex[0]).cross(vertex[2] - vertex[0]);
#       ifdef G3D_DEBUG
            const Vector3& N = faceNormalArray[f];
            debugAssert(N.isFinite());
#       endif
    }

    // Per-vertex normals, computed by averaging
    vertexNormalArray.resize(vertexGeometry.size());
    for (int v = 0; v < vertexNormalArray.size(); ++v) {
        Vector3 sum = Vector3::zero();
        for (int k = 0; k < vertexArray[v].faceIndex.size(); ++k) {
            const int f = vertexArray[v].faceIndex[k];
            sum += faceNormalArray[f];
        }
        vertexNormalArray[v] = sum.directionOrZero();
#       ifdef G3D_DEBUG
            const Vector3& N = vertexNormalArray[v];
            debugAssert(N.isUnit() || N.isZero());
#       endif
    }


    for (int f = 0; f < faceArray.size(); ++f) {
        faceNormalArray[f] = faceNormalArray[f].directionOrZero();
#       ifdef G3D_DEBUG
            const Vector3& N = faceNormalArray[f];
            debugAssert(N.isUnit() || N.isZero());
#       endif
    }

}


void MeshAlg::computeFaceNormals(
    const Array<Vector3>&           vertexArray,
    const Array<MeshAlg::Face>&     faceArray,
    Array<Vector3>&                 faceNormals,
    bool                            normalize) {

    faceNormals.resize(faceArray.size());

    for (int f = 0; f < faceArray.size(); ++f) {
        const MeshAlg::Face& face = faceArray[f];

        const Vector3& v0 = vertexArray[face.vertexIndex[0]];
        const Vector3& v1 = vertexArray[face.vertexIndex[1]];
        const Vector3& v2 = vertexArray[face.vertexIndex[2]];
        
        faceNormals[f] = (v1 - v0).cross(v2 - v0);
    }

    if (normalize) {
        for (int f = 0; f < faceArray.size(); ++f) {
            faceNormals[f] = faceNormals[f].direction();
        }
    }
}


void MeshAlg::identifyBackfaces(
    const Array<Vector3>&           vertexArray,
    const Array<MeshAlg::Face>&     faceArray,
    const Vector4&                  HP,
    Array<bool>&                    backface) {

    Vector3 P = HP.xyz();

    backface.resize(faceArray.size());

    if (fuzzyEq(HP.w, 0.0f)) {
        // Infinite case
        for (int f = faceArray.size() - 1; f >= 0; --f) {
            const MeshAlg::Face& face = faceArray[f];

            const Vector3& v0 = vertexArray[face.vertexIndex[0]];
            const Vector3& v1 = vertexArray[face.vertexIndex[1]];
            const Vector3& v2 = vertexArray[face.vertexIndex[2]];
        
            const Vector3 N = (v1 - v0).cross(v2 - v0);

            backface[f] = N.dot(P) < 0;
        }
    } else {
        // Finite case
        for (int f = faceArray.size() - 1; f >= 0; --f) {
            const MeshAlg::Face& face = faceArray[f];

            const Vector3& v0 = vertexArray[face.vertexIndex[0]];
            const Vector3& v1 = vertexArray[face.vertexIndex[1]];
            const Vector3& v2 = vertexArray[face.vertexIndex[2]];
        
            const Vector3 N = (v1 - v0).cross(v2 - v0);

            backface[f] = N.dot(P - v0) < 0;
        }
    }
}


void MeshAlg::identifyBackfaces(
    const Array<Vector3>&           vertexArray,
    const Array<MeshAlg::Face>&     faceArray,
    const Vector4&                  HP,
    Array<bool>&                    backface,
    const Array<Vector3>&           faceNormals) {

    Vector3 P = HP.xyz();

    backface.resize(faceArray.size());

    if (fuzzyEq(HP.w, 0.0f)) {
        // Infinite case
        for (int f = faceArray.size() - 1; f >= 0; --f) {
            const Vector3& N = faceNormals[f];
            backface[f] = N.dot(P) < 0;
        }
    } else {
        // Finite case
        for (int f = faceArray.size() - 1; f >= 0; --f) {
            const MeshAlg::Face& face = faceArray[f];        
            const Vector3& v0 = vertexArray[face.vertexIndex[0]];
            const Vector3& N = faceNormals[f];

            backface[f] = N.dot(P - v0) < 0;
        }
    }
}


void MeshAlg::createIndexArray(int n, Array<int>& array, int start, int run, int skip) {
    debugAssert(skip >= 0);
    debugAssert(run >= 0);

    array.resize(n);
    if (skip == 0) {
        for (int i = 0; i < n; ++i) {
            array[i] = start + i;
        }
    } else {
        int rcount = 0;
        int j = start;
        for (int i = 0; i < n; ++i) {
            array[i] = j;

            ++j;
            ++rcount;

            if (rcount == run) {
                rcount = 0;
                j += skip;
            }
        }
    }
}


void MeshAlg::computeAreaStatistics(
    const Array<Vector3>&   vertexArray,
    const Array<int>&       indexArray,
    double&                 minEdgeLength,
    double&                 meanEdgeLength,
    double&                 medianEdgeLength,
    double&                 maxEdgeLength,
    double&                 minFaceArea,
    double&                 meanFaceArea,
    double&                 medianFaceArea,
    double&                 maxFaceArea) {

    debugAssert(indexArray.size() % 3 == 0);
    
    Array<double> area;
    area.resize(indexArray.size() / 3);
    Array<double> magnitude;
    magnitude.resize(indexArray.size());

    for (int i = 0; i < indexArray.size(); i += 3) {
        const Vector3& v0 = vertexArray[indexArray[i]];
        const Vector3& v1 = vertexArray[indexArray[i + 1]];
        const Vector3& v2 = vertexArray[indexArray[i + 2]];

        area[i / 3] = (v1 - v0).cross(v2 - v0).magnitude() / 2.0;
        magnitude[i] = (v1 - v0).magnitude();
        magnitude[i + 1] = (v2 - v1).magnitude();
        magnitude[i + 2] = (v0 - v2).magnitude();
    }

    area.sort();
    magnitude.sort();

    minEdgeLength = max(0.0, magnitude[0]);
    maxEdgeLength = max(0.0, magnitude.last());
    medianEdgeLength = max(0.0, magnitude[magnitude.size() / 2]);
    meanEdgeLength = 0;
    for (int i = 0; i < magnitude.size(); ++i) {
        meanEdgeLength += magnitude[i];
    }
    meanEdgeLength /= magnitude.size();

    minFaceArea = max(0.0, area[0]);
    maxFaceArea = max(0.0, area.last());
    medianFaceArea = max(0.0, area[area.size() / 2]);
    meanFaceArea = 0;
    for (int i = 0; i < area.size(); ++i) {
        meanFaceArea += area[i];
    }
    meanFaceArea /= area.size();


    // Make sure round-off hasn't pushed values less than zero
    meanFaceArea   = max(0.0, meanFaceArea);
    meanEdgeLength = max(0.0, meanEdgeLength);
}


int MeshAlg::countBoundaryEdges(const Array<MeshAlg::Edge>& edgeArray) {
    int b = 0;

    for (int i = 0; i < edgeArray.size(); ++i) {
        if ((edgeArray[i].faceIndex[0] == MeshAlg::Face::NONE) !=
            (edgeArray[i].faceIndex[1] == MeshAlg::Face::NONE)) {
            ++b;
        }
    }

    return b;
}

void MeshAlg::computeBounds(
    const Array<Vector3>&   vertexArray,
    const Array<int>&       indexArray,
    AABox&                  box, 
    Sphere&                 sphere) {

    // Makes a copy so as to re-use the existing computebounds code
    Array<Vector3> newArray;
    newArray.resize(indexArray.size());
    for (int i = 0; i < indexArray.size(); ++i) {
        newArray[i] = vertexArray[indexArray[i]];
    }
    computeBounds(newArray, box, sphere);
}


void MeshAlg::computeBounds(
    const Array<Vector3>&   vertexArray,
    AABox&                  box, 
    Sphere&                 sphere) {

    Vector3 xmin, xmax, ymin, ymax, zmin, zmax;

    // FIRST PASS: find 6 minima/maxima points
    xmin.x = ymin.y = zmin.z = finf();
    xmax.x = ymax.y = zmax.z = -finf();

    for (int v = 0; v < vertexArray.size(); ++v) {
        const Vector3& vertex = vertexArray[v];

        if (vertex.x < xmin.x) {
            xmin = vertex;
        }

        if (vertex.x > xmax.x) {
            xmax = vertex;
        }

        if (vertex.y < ymin.y) {
            ymin = vertex;
        }

        if (vertex.y > ymax.y) {
            ymax = vertex;
        }

        if (vertex.z < zmin.z) {
            zmin = vertex;
        }

        if (vertex.z > zmax.z) {
            zmax = vertex;
        }
    }

    // Set points dia1 & dia2 to the maximally separated pair
    Vector3 dia1 = xmin; 
    Vector3 dia2 = xmax;
    {
        // Set xspan = distance between the 2 points xmin & xmax (squared)
        float xspan = (xmax - xmin).squaredMagnitude();

        // Same for y & z spans
        float yspan = (ymax - ymin).squaredMagnitude();
        float zspan = (zmax - zmin).squaredMagnitude();
    
        float maxspan = xspan;

        if (yspan > maxspan) {
            maxspan = yspan;
            dia1    = ymin;
            dia2    = ymax;
        }

        if (zspan > maxspan) {
            maxspan = zspan;
            dia1    = zmin;
            dia2    = zmax;
        }
    }


    // dia1, dia2 is a diameter of initial sphere

    // calc initial center
    Vector3 center = (dia1 + dia2) / 2.0;

    // calculate initial radius^2 and radius 
    Vector3 d = dia2 - sphere.center;

    float radSq = d.squaredMagnitude();
    float rad  = sqrt(radSq);

    // SECOND PASS: increment current sphere
    float old_to_p, old_to_new;

    for (int v = 0; v < vertexArray.size(); ++v) {
        const Vector3& vertex = vertexArray[v];

        d = vertex - center;

        float old_to_p_sq = d.squaredMagnitude();

        // do r^2 test first 
        if (old_to_p_sq > radSq) {
             // this point is outside of current sphere
            old_to_p = sqrt(old_to_p_sq);

            // calc radius of new sphere
            rad = (rad + old_to_p) / 2.0f;

            // for next r^2 compare
            radSq = rad * rad;     
            old_to_new = old_to_p - rad;

            // calc center of new sphere
            center = (rad * center + old_to_new * vertex) / old_to_p;
        }    
    }

    const Vector3 min(xmin.x, ymin.y, zmin.z);
    const Vector3 max(xmax.x, ymax.y, zmax.z);

   box = AABox(min, max);

    const float boxRadSq = (max - min).squaredMagnitude() * 0.25f;

    if (boxRadSq >= radSq){
        if (isNaN(center.x) || ! isFinite(rad)) {
            sphere = Sphere(Vector3::zero(), finf());
        } else {
            sphere = Sphere(center, rad);
        }
    } else {
        sphere = Sphere((max + min) * 0.5f, sqrt(boxRadSq));
    }
}

void MeshAlg::computeTangentSpaceBasis(
    const Array<Vector3>&       vertexArray,
    const Array<Vector2>&       texCoordArray,
    const Array<Vector3>&       vertexNormalArray,
    const Array<Face>&          faceArray,
    Array<Vector3>&             tangent,
    Array<Vector3>&             binormal) {

    debugAssertM(faceArray.size() != 0, "Unable to calculate valid tangent space without faces.");

    tangent.resize(vertexArray.size());
    binormal.resize(vertexArray.size());

    // Zero the output arrays.
    System::memset(tangent.getCArray(), 0, sizeof(Vector3) * tangent.size());
    System::memset(binormal.getCArray(), 0, sizeof(Vector3) * binormal.size());

    // Iterate over faces, computing the tangent vectors for each 
    // vertex.  Accumulate those into the tangent and binormal arrays
    // and then orthonormalize at the end.

    for (int f = 0; f < faceArray.size(); ++f) {
        const Face& face = faceArray[f];

        const int i0 = face.vertexIndex[0];
        const int i1 = face.vertexIndex[1];
        const int i2 = face.vertexIndex[2];
        
        const Vector3& v0 = vertexArray[i0];
        const Vector3& v1 = vertexArray[i1];
        const Vector3& v2 = vertexArray[i2];

        const Vector2& t0 = texCoordArray[i0];
        const Vector2& t1 = texCoordArray[i1];
        const Vector2& t2 = texCoordArray[i2];

        // See http://www.terathon.com/code/tangent.html for a derivation of the following code

        // vertex edges
        Vector3 ve1 = v1 - v0;
        Vector3 ve2 = v2 - v0;

        // texture edges
        Vector2 te1 = t1 - t0;
        Vector2 te2 = t2 - t0;

        Vector3 n(ve1.cross(ve2).direction());
        Vector3 t, b;
    
        float r = te1.x * te2.y - te1.y * te2.x;
        if (r == 0.0) {
            // degenerate case
            if (! n.isFinite() || n.isZero()) {
                n = Vector3::unitY();
            }
            n.getTangents(t, b);
        } else {
            r = 1.0f / r;        
            t = (te2.y * ve1 - te1.y * ve2) * r;
            b = (te2.x * ve1 - te1.x * ve2) * r;   
        }

        for (int v = 0; v < 3; ++v) {
            int i = face.vertexIndex[v];
            tangent[i]  += t;
            binormal[i] += b;
        }
    }

    // Normalize the basis vectors
    for (int v = 0; v < vertexArray.size(); ++v) {
        // Remove the component parallel to the normal
        const Vector3& N = vertexNormalArray[v];
        Vector3& T = tangent[v];
        Vector3& B = binormal[v];

        debugAssertM(N.isUnit() || N.isZero(), "Input normals must have unit length");

        T -= T.dot(N) * N;
        B -= B.dot(N) * N;

        // Normalize
        T = T.directionOrZero();
        B = B.directionOrZero();
    }
}



} // G3D namespace
