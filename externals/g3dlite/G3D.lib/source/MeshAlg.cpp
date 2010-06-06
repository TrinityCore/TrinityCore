/**
  @file MeshAlg.cpp

  @maintainer Morgan McGuire, matrix@graphics3d.com
  @created 2003-09-14
  @edited  2008-09-03

  Copyright 2000-2008, Morgan McGuire.
  All rights reserved.

 */

#include "G3D/MeshAlg.h"
#include "G3D/Table.h"
#include "G3D/Set.h"
#include "G3D/Box.h"
#include "G3D/Sphere.h"
#include "G3D/vectorMath.h"
#include "G3D/AABox.h"

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
    const CoordinateFrame& xform) {
        
    vertex.fastClear();
    texCoord.fastClear();
    index.fastClear();

    // Generate vertices                  
    for (int z = 0; z <= hCells; ++z) {
        for (int x = 0; x <= wCells; ++x) {
            Vector3 v(x / (float)wCells, 0, z / (float)hCells);

            Vector2 t = v.xz() * textureScale;

            texCoord.append(t);

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
    Array<Vertex> fakeVertexArray(adjacentFaceArray.size());

    for (int v = 0; v < adjacentFaceArray.size(); ++v) {
        fakeVertexArray[v].faceIndex = adjacentFaceArray[v];
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

    if (fuzzyEq(HP.w, 0.0)) {
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

    if (fuzzyEq(HP.w, 0.0)) {
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

    Array<double> area(indexArray.size() / 3);
    Array<double> magnitude(indexArray.size());

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
    Box&                    box, 
    Sphere&                 sphere) {

    Array<Vector3> newArray(indexArray.size());
    for (int i = 0; i < indexArray.size(); ++i) {
        newArray[i] = vertexArray[indexArray[i]];
    }
    computeBounds(newArray, box, sphere);
}


void MeshAlg::computeBounds(
    const Array<Vector3>&   vertexArray,
    Box&                    box, 
    Sphere&                 sphere) {

    Vector3 xmin, xmax, ymin, ymax, zmin, zmax;

    // FIRST PASS: find 6 minima/maxima points
    xmin.x = ymin.y = zmin.z = inf();
    xmax.x = ymax.y = zmax.z = -inf();

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
        double xspan = (xmax - xmin).squaredMagnitude();

        // Same for y & z spans
        double yspan = (ymax - ymin).squaredMagnitude();
        double zspan = (zmax - zmin).squaredMagnitude();
    
        double maxspan = xspan;

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

    double radSq = d.squaredMagnitude();
    double rad  = sqrt(radSq);

    // SECOND PASS: increment current sphere
    double old_to_p, old_to_new;

    for (int v = 0; v < vertexArray.size(); ++v) {
        const Vector3& vertex = vertexArray[v];

        d = vertex - center;

        double old_to_p_sq = d.squaredMagnitude();

    	// do r^2 test first 
        if (old_to_p_sq > radSq) {
		 	// this point is outside of current sphere
    		old_to_p = sqrt(old_to_p_sq);

    		// calc radius of new sphere
		    rad = (rad + old_to_p) / 2.0;

            // for next r^2 compare
		    radSq = rad * rad; 	
		    old_to_new = old_to_p - rad;

		    // calc center of new sphere
            center = (rad * center + old_to_new * vertex) / old_to_p;
		}	
	}

	const Vector3 min(xmin.x, ymin.y, zmin.z);
	const Vector3 max(xmax.x, ymax.y, zmax.z);

    box = Box(min, max);

	const double boxRadSq = (max - min).squaredMagnitude() * 0.25;

	if (boxRadSq >= radSq){
        if (isNaN(center.x) || ! isFinite(rad)) {
            sphere = Sphere(Vector3::zero(), inf());
        } else {
    		sphere = Sphere(center, rad);
        }
	}else{
		sphere = Sphere((max + min) * 0.5, sqrt(boxRadSq));
	}
}


void MeshAlg::computeTangentVectors(
    const Vector3&  normal,
    const Vector3   position[3],
    const Vector2   texCoord[3],
    Vector3&        tangent, 
    Vector3&        binormal) {

    Vector3 v[3];
    Vector2 t[3];

    // TODO: don't need the copy
    // Make a copy so that we can sort
    for (int i = 0; i < 3; ++i) {
        v[i] = position[i];
        t[i] = texCoord[i];
    }

    /////////////////////////////////////////////////
    // Begin by computing the tangent

    // Bubble sort the vertices by decreasing texture coordinate y.
    if (t[0].y < t[1].y) {
        std::swap(v[0], v[1]);
        std::swap(t[0], t[1]);
    }

    // t0 >= t1

    if (t[0].y < t[2].y) {
        std::swap(v[0], v[2]);
        std::swap(t[0], t[2]);
    }

    // t0 >= t2, t0 >= t1

    if (t[1].y < t[2].y) {
        std::swap(v[1], v[2]);
        std::swap(t[1], t[2]);
    }

    // t0 >= t1 >= t2

    float amount;

    // Compute the direction of constant y.
    if (fuzzyEq(t[2].y, t[0].y)) {
        // Degenerate case-- the texture coordinates do not vary across this 
        // triangle.
        amount = 1.0;
    } else {
        // Solve lerp(t[0].y, t[2].y, amount) = t[1].y for amount:
        //
        // t0 + (t2 - t0) * a = t1
        // a = (t1 - t0) / (t2 - t0)

        amount = (t[1].y - t[0].y) / (t[2].y - t[0].y);
    }

    tangent = lerp(v[0], v[2], amount) - v[1];

    // Make sure the tangent points in the right direction and is 
    // perpendicular to the normal.
    if (lerp(t[0].x, t[2].x, amount) < t[1].x) {
        tangent = -tangent;
    }

    // TODO: do we need this?  We take this component off
    // at the end anyway
    tangent -= tangent.dot(normal) * normal;

    // Normalize the tangent so it contributes
    // equally at the vertex (TODO: do we need this?)
    if (fuzzyEq(tangent.magnitude(), 0.0)) {
        tangent = Vector3::unitX();
    } else {
        tangent = tangent.direction();
    }

    //////////////////////////////////////////////////
    // Now compute the binormal (same code, but in x)

    // Sort the vertices by texture coordinate x.
    if (t[0].x < t[1].x) {
        std::swap(v[0], v[1]);
        std::swap(t[0], t[1]);
    }

    if (t[0].x < t[2].x) {
        std::swap(v[0], v[2]);
        std::swap(t[0], t[2]);
    }

    if (t[1].x < t[2].x) {
        std::swap(v[1], v[2]);
        std::swap(t[1], t[2]);
    }

    // Compute the direction of constant x.
    if (fuzzyEq(t[2].x, t[0].x)) {
        amount = 1.0;
    } else {
        amount = (t[1].x - t[0].x) / (t[2].x - t[0].x);
    }

    binormal = lerp(v[0], v[2], amount) - v[1];

    // Make sure the binormal points in the right direction and is 
    // perpendicular to the normal.
    if (lerp(t[0].y, t[2].y, amount) < t[1].y) {
        binormal = -binormal;
    }

    binormal -= binormal.dot(normal) * normal;

    // Normalize the binormal so that it contributes
    // an equal amount to the per-vertex value (TODO: do we need this? 
    // Nelson Max showed that we don't for computing per-vertex normals)
    if (fuzzyEq(binormal.magnitude(), 0.0)) {
        binormal = Vector3::unitZ();
    } else {
        binormal = binormal.direction();
    }

    // This computation gives the opposite convention of what we want.
    binormal = -binormal;

}


void MeshAlg::computeTangentSpaceBasis(
    const Array<Vector3>&       vertexArray,
    const Array<Vector2>&       texCoordArray,
    const Array<Vector3>&       vertexNormalArray,
    const Array<Face>&          faceArray,
    Array<Vector3>&             tangent,
    Array<Vector3>&             binormal) {

    debugAssertM(faceArray.size() != 0, "Unable to calculate valid tangent space without faces.");

    // The three vertices and texCoords of each face
    Vector3 position[3];
    Vector2 texCoord[3];
    Vector3 t, b;

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

        for (int v = 0; v < 3; ++v) {
            int i = face.vertexIndex[v];
            position[v] = vertexArray[i];
            texCoord[v] = texCoordArray[i];
        }

        const Vector3 faceNormal((position[1] - position[0]).cross(position[2] - position[0]).direction());
        computeTangentVectors(faceNormal, position, texCoord, t, b);

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
        debugAssertM(N.isUnit() || N.isZero(), "Input normals must have unit length");

        tangent[v]  -= tangent[v].dot(N) * N;
        binormal[v] -= binormal[v].dot(N) * N;

        // Normalize
        tangent[v]  = tangent[v].directionOrZero();
        binormal[v] = binormal[v].directionOrZero();

        // Note that the tangent and binormal might not be perpendicular anymore
    }
}



} // G3D namespace
