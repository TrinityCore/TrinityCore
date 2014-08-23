/**
  @file MeshBuilder.cpp

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu

  @created 2002-02-27
  @edited  2005-02-24
 */

#include "G3D/MeshBuilder.h"
#include "G3D/MeshAlg.h"

namespace G3D {

void MeshBuilder::setName(const std::string& n) {
    name = n;
}


void MeshBuilder::commit(std::string& n, Array<int>& indexArray, Array<Vector3>& outvertexArray) {
    n = name;

    // Make the data fit in a unit cube
    centerTriList();

    Array<int> toNew, toOld;

    if (close == MeshBuilder::AUTO_WELD) {
        Array<int> index;
        MeshAlg::createIndexArray(triList.size(), index);
        double minEdgeLen, maxEdgeLen, meanEdgeLen, medianEdgeLen;
        double minFaceArea, maxFaceArea, meanFaceArea, medianFaceArea;
        MeshAlg::computeAreaStatistics(triList, index,
            minEdgeLen, meanEdgeLen, medianEdgeLen, maxEdgeLen,
            minFaceArea, meanFaceArea, medianFaceArea, maxFaceArea);
        close = minEdgeLen * 0.1;
    }

    MeshAlg::computeWeld(triList, outvertexArray, toNew, toOld, (float)close);

    // Construct triangles
    for (int t = 0; t < triList.size(); t += 3) {
        int index[3];

        for (int i = 0; i < 3; ++i) {
           index[i] = toNew[t + i];
        }

        // Throw out zero size triangles
        if ((index[0] != index[1]) &&
            (index[1] != index[2]) &&
            (index[2] != index[0])) {
            indexArray.append(index[0], index[1], index[2]);
        }
    }
}


void MeshBuilder::centerTriList() {
    // Compute the range of the vertices
    Vector3 vmin, vmax;

    computeBounds(vmin, vmax);

    const Vector3 diagonal = vmax - vmin;
    float scale = max(max(diagonal.x, diagonal.y), diagonal.z) / 2.0f;
    debugAssert(scale > 0);

    const Vector3 translation = vmin + diagonal / 2.0f;

    // Center and scale all vertices in the input list
    int v;

    if (scaleAndCenter) {
        //Matrix3 rot90 = Matrix3::fromAxisAngle(Vector3::UNIT_Y, toRadians(180)) * Matrix3::fromAxisAngle(Vector3::UNIT_X, toRadians(90));
        for (v = 0; v < triList.size(); ++v) {
            triList[v] = (triList[v] - translation) / scale;
            //triList[v] = rot90 * triList[v];
        }
    }
}


void MeshBuilder::computeBounds(Vector3& min, Vector3& max) {
    min = Vector3::inf(); 
    max = -min;

    int v;
    for (v = 0; v < triList.size(); ++v) {
        min = min.min(triList[v]);
        max = max.max(triList[v]);
    }
}


void MeshBuilder::addTriangle(const Vector3& a, const Vector3& b, const Vector3& c) {
    triList.append(a, b, c);

    if (_twoSided) {
        triList.append(c, b, a);
    }
}


void MeshBuilder::addQuad(const Vector3& a, const Vector3& b, const Vector3& c, const Vector3& d) {
    addTriangle(a, b, c);
    addTriangle(a, c, d);
}


void MeshBuilder::addTriangle(const Triangle& t) {
    addTriangle(t.vertex(0), t.vertex(1), t.vertex(2));
}

} // namespace
