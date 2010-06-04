/**
  @file MeshAlgAdjacency.cpp

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu
  @created 2003-09-14
  @edited  2009-04-26

  Copyright 2000-2009, Morgan McGuire.
  All rights reserved.

 */

#include "G3D/Table.h"
#include "G3D/MeshAlg.h"
#include "G3D/Set.h"
#include "G3D/Stopwatch.h"
#include "G3D/SmallArray.h"

namespace G3D {

/** Two-level table mapping index 0 -> index 1 -> list of face indices */
class MeshEdgeTable {
public:

    /** We  expect 2 faces per edge. */
    typedef SmallArray<int, 2> FaceIndexArray;

    class Edge {
    public:
        int i1;

        FaceIndexArray faceIndexArray;
    };

    /** We expect at most 6 edges per vertex; that matches a typical regular grid mesh */
    typedef SmallArray<Edge, 6> EdgeArray;

    typedef Array< EdgeArray > ET;

private:
    
    ET                   table;

public:

    void clear() {
        table.clear();
    }
    
    void resize(int maxV) {
        table.resize(maxV);
    }

    /**
     Inserts the faceIndex into the edge's face list.
     The index may be a negative number indicating a backface.

     \param v0 Vertex index 0
     \param v1 Vertex index 1
     */
    void insert(int v0, int v1, int faceIndex) {
        
        debugAssert(v0 <= v1);
        EdgeArray& edgeArray = table[v0];
        for (int i = 0; i < edgeArray.size(); ++i) {
            if (edgeArray[i].i1 == v1) {
                edgeArray[i].faceIndexArray.push(faceIndex);
                return;
            }
        }

        Edge& p = edgeArray.next();
        p.i1 = v1;
        p.faceIndexArray.push(faceIndex);
    }

    class Iterator {
        friend class MeshEdgeTable;
    private:

        int                                   m_i0;
        /** Pair index */
        int                                   m_p;
        ET&                                   m_array;
        EdgeArray*                            m_edgeArray;
        bool                                  m_end;

    public:

        int i0() const {
            return m_i0;
        }

        int i1() const {
            return (*m_edgeArray)[m_p].i1;
        }

        FaceIndexArray& faceIndex() {
            return (*m_edgeArray)[m_p].faceIndexArray;
        }

        Iterator& operator++() {
            if ((m_i0 >= 0) && (m_p < m_edgeArray->size() - 1)) {
                ++m_p;
            } else {
                // Skip over elements with no face array
                do {
                    ++m_i0;
                    if (m_i0 == m_array.size()) {
                        m_end = true;
                        return *this;
                    } else {
                        m_edgeArray = &m_array[m_i0];
                        m_p = 0;
                    }
                } while (m_edgeArray->size() == 0);
            }

            return *this;
        }

        bool hasMore() const {
            return ! m_end;
        }

    private:

        Iterator(ET& a) : m_i0(-1), m_p(-1),  m_array(a), m_edgeArray(NULL), m_end(false) {
            ++(*this);
        }

    };

    Iterator begin() {
        return Iterator(table);
    }
};


/**
 Assigns the edge index into the next unassigned edge
 index.  The edge index may be negative, indicating
 a reverse edge.
 */
static void assignEdgeIndex(MeshAlg::Face& face, int e) {
    for (int i = 0; i < 3; ++i) {
        if (face.edgeIndex[i] == MeshAlg::Face::NONE) {
            face.edgeIndex[i] = e;
            return;
        }
    }

    debugAssertM(false, "Face has already been assigned 3 edges");
}


void MeshAlg::computeAdjacency(
    const Array<Vector3>&   vertexGeometry,
    const Array<int>&       indexArray,
    Array<Face>&            faceArray,
    Array<Edge>&            edgeArray,
    Array< Array<int> >&    adjacentFaceArray) {

    Array<Vertex> vertexArray;

    computeAdjacency(vertexGeometry, indexArray, faceArray, edgeArray, vertexArray);

    // Convert the vertexArray into adjacentFaceArray
    adjacentFaceArray.clear();
    adjacentFaceArray.resize(vertexArray.size());
    for (int v = 0; v < adjacentFaceArray.size(); ++v) {
        const SmallArray<int, 6>& src = vertexArray[v].faceIndex;
        Array<int>& dst = adjacentFaceArray[v];
        dst.resize(src.size());
        for (int f = 0; f < dst.size(); ++f) {
            dst[f] = src[f];
        }
    }
}


void MeshAlg::computeAdjacency(
    const Array<Vector3>&   vertexGeometry,
    const Array<int>&       indexArray,
    Array<Face>&            faceArray,
    Array<Edge>&            edgeArray,
    Array<Vertex>&          vertexArray) {

    MeshEdgeTable           edgeTable;

    edgeArray.clear();
    vertexArray.clear();
    faceArray.clear();
    
    // Face normals
    Array<Vector3> faceNormal;
    faceNormal.resize(indexArray.size() / 3);
    faceArray.resize(faceNormal.size());

    // This array has the same size as the vertex array
    vertexArray.resize(vertexGeometry.size());

    edgeTable.resize(vertexArray.size());

    // Iterate through the triangle list
    for (int q = 0, f = 0; q < indexArray.size(); ++f, q += 3) {

        Vector3 vertex[3];
        MeshAlg::Face& face = faceArray[f];

        // Construct the face
        for (int j = 0; j < 3; ++j) {
            int v = indexArray[q + j];
            face.vertexIndex[j] = v;
            face.edgeIndex[j]   = Face::NONE;

            // Store back pointers in the vertices
            vertexArray[v].faceIndex.append(f);

            // We'll need these vertices to find the face normal
            vertex[j]           = vertexGeometry[v];
        }

        // Compute the face normal
        const Vector3& N = (vertex[1] - vertex[0]).cross(vertex[2] - vertex[0]);
        faceNormal[f] = N.directionOrZero();

        static const int nextIndex[] = {1, 2, 0};

        // Add each edge to the edge table.
        for (int j = 0; j < 3; ++j) {
            const int      i0 = indexArray[q + j];
            const int      i1 = indexArray[q + nextIndex[j]];

            if (i0 < i1) {
                // The edge was directed in the same manner as in the face
                edgeTable.insert(i0, i1, f);
            } else {
                // The edge was directed in the opposite manner as in the face
                edgeTable.insert(i1, i0, ~f);
            }
        }
    }

    // For each edge in the edge table, create an edge in the edge array.
    // Collapse every 2 edges from adjacent faces.

    MeshEdgeTable::Iterator cur = edgeTable.begin();

    Array<Edge> tempEdgeArray;
    while (cur.hasMore()) {
        MeshEdgeTable::FaceIndexArray& faceIndexArray = cur.faceIndex();

        // Process this edge
        while (faceIndexArray.size() > 0) {

            // Remove the last index
            int f0 = faceIndexArray.pop();

            // Find the normal to that face
            const Vector3& n0 = faceNormal[(f0 >= 0) ? f0 : ~f0];

            bool found = false;

            // We try to find the matching face with the closest
            // normal.  This ensures that we don't introduce a lot
            // of artificial ridges into flat parts of a mesh.
            float ndotn = -2;
            int f1 = -1, i1 = -1;
            
            // Try to find the face with the matching edge
            for (int i = faceIndexArray.size() - 1; i >= 0; --i) {
                int f = faceIndexArray[i];

                if ((f >= 0) != (f0 >= 0)) {
                    // This face contains the oppositely oriented edge
                    // and has not been assigned too many edges

                    const Vector3& n1 = faceNormal[(f >= 0) ? f : ~f];
                    float d = n1.dot(n0);

                    if (found) {
                        // We previously found a good face; see if this
                        // one is better.
                        if (d > ndotn) {
                            // This face is better.
                            ndotn = d;
                            f1    = f;
                            i1    = i;
                        }
                    } else {
                        // This is the first face we've found
                        found = true;
                        ndotn = d;
                        f1    = f;
                        i1    = i;
                    }
                }
            }

            // Create the new edge
            int e = tempEdgeArray.size();
            Edge& edge = tempEdgeArray.next();
            
            edge.vertexIndex[0] = cur.i0();
            edge.vertexIndex[1] = cur.i1();

            if (f0 >= 0) {
                edge.faceIndex[0] = f0;
                edge.faceIndex[1] = Face::NONE;
                assignEdgeIndex(faceArray[f0], e); 
            } else {
                // The face indices above are two's complemented.
                // this code restores them to regular indices.
                debugAssert((~f0) >= 0);
                edge.faceIndex[1] = ~f0;
                edge.faceIndex[0] = Face::NONE;

                // The edge index *does* need to be inverted, however.
                assignEdgeIndex(faceArray[~f0], ~e); 
            }

            if (found) {
                // We found a matching face; remove both
                // faces from the active list.
                faceIndexArray.fastRemove(i1);

                if (f1 >= 0) {
                    edge.faceIndex[0] = f1;
                    assignEdgeIndex(faceArray[f1], e); 
                } else {
                    edge.faceIndex[1] = ~f1;
                    assignEdgeIndex(faceArray[~f1], ~e); 
                }
            }
        }

        ++cur;
    }

    edgeTable.clear();

    // Move boundary edges to the end of the list and then
    // clean up the face references into them
    {
        // Map old edge indices to new edge indices
        Array<int> newIndex;
        newIndex.resize(tempEdgeArray.size());

        // Index of the start and end of the edge array
        int i = 0;
        int j = tempEdgeArray.size() - 1;

        edgeArray.resize(tempEdgeArray.size());
        for (int e = 0; e < tempEdgeArray.size(); ++e) {
            if (tempEdgeArray[e].boundary()) {
                newIndex[e] = j;
                --j;
            } else {
                newIndex[e] = i;
                ++i;
            }
            edgeArray[newIndex[e]] = tempEdgeArray[e];
        }

        debugAssertM(i == j + 1, "Counting from front and back of array did not match");

        // Fix the faces
        for (int f = 0; f < faceArray.size(); ++f) {
            Face& face = faceArray[f];
            for (int q = 0; q < 3; ++q) {
                int e = face.edgeIndex[q];
                if (e < 0) {
                    // Backwards edge; twiddle before and after conversion
                    face.edgeIndex[q] = ~newIndex[~e];
                } else {
                    // Regular edge; remap the index
                    face.edgeIndex[q] = newIndex[e];
                }
            }
        }
    }

    // Now order the edge indices inside the faces correctly.
    for (int f = 0; f < faceArray.size(); ++f) {
        Face& face = faceArray[f];
        int e0 = face.edgeIndex[0];
        int e1 = face.edgeIndex[1];
        int e2 = face.edgeIndex[2];

        // e0 will always remain first.  The only 
        // question is whether e1 and e2 should be swapped.
    
        // See if e1 begins at the vertex where e1 ends.
        const int e0End = (e0 < 0) ? 
            edgeArray[~e0].vertexIndex[0] :
            edgeArray[e0].vertexIndex[1];

        const int e1Begin = (e1 < 0) ? 
            edgeArray[~e1].vertexIndex[1] :
            edgeArray[e1].vertexIndex[0];

        if (e0End != e1Begin) {
            // We must swap e1 and e2
            face.edgeIndex[1] = e2;
            face.edgeIndex[2] = e1;
        }
    }

    // Fill out the edge adjacency information in the vertex array
    for (int e = 0; e < edgeArray.size(); ++e) {
        const Edge& edge = edgeArray[e];
        vertexArray[edge.vertexIndex[0]].edgeIndex.append(e);
        vertexArray[edge.vertexIndex[1]].edgeIndex.append(~e);
    }
}


void MeshAlg::weldBoundaryEdges(
    Array<Face>&       faceArray,
    Array<Edge>&       edgeArray,
    Array<Vertex>&     vertexArray) {

    // Copy over the original edge array
    Array<Edge> oldEdgeArray = edgeArray;

    // newEdgeIndex[e] is the new index of the old edge with index e
    // Note that newEdgeIndex[e] might be negative, indicating that
    // the edge switched direction between the arrays.
    Array<int> newEdgeIndex;
    newEdgeIndex.resize(edgeArray.size());
    edgeArray.resize(0);

    // boundaryEdgeIndices[v_low] is an array of the indices of 
    // all boundary edges whose lower vertex is v_low.
    Table<int, Array<int> > boundaryEdgeIndices;

    // Copy over non-boundary edges to the new array
    for (int e = 0; e < oldEdgeArray.size(); ++e) {
        if (oldEdgeArray[e].boundary()) {

            // Add to the boundary table
            const int v_low = iMin(oldEdgeArray[e].vertexIndex[0], oldEdgeArray[e].vertexIndex[1]);
            if (! boundaryEdgeIndices.containsKey(v_low)) {
                boundaryEdgeIndices.set(v_low, Array<int>());
            }
            boundaryEdgeIndices[v_low].append(e);

            // We'll fill out newEdgeIndex[e] later, when we find pairs

        } else {

            // Copy the edge to the new array
            newEdgeIndex[e] = edgeArray.size();
            edgeArray.append(oldEdgeArray[e]);

        }
    }


    // Remove all edges from the table that have pairs.
    Table<int, Array<int> >::Iterator cur = boundaryEdgeIndices.begin();
    Table<int, Array<int> >::Iterator end = boundaryEdgeIndices.end();
    while (cur != end) {
        Array<int>&     boundaryEdge = cur->value;

        for (int i = 0; i < boundaryEdge.size(); ++i) {
            int ei = boundaryEdge[i];
            const Edge& edgei = oldEdgeArray[ei];

            for (int j = i + 1; j < boundaryEdge.size(); ++j) {
                int ej = boundaryEdge[j];
                const Edge& edgej = oldEdgeArray[ej];

                // See if edge ei is the reverse (match) of edge ej.

                // True if the edges match
                bool match = false;

                // True if edgej's vertex indices are reversed from
                // edgei's (usually true).
                bool reversej = false;
                
                int u = edgei.vertexIndex[0];
                int v = edgei.vertexIndex[1];

                if (edgei.faceIndex[0] != Face::NONE) {
                    //        verts|faces
                    // edgei = [u v A /]

                    if (edgej.faceIndex[0] != Face::NONE) {
                        if ((edgej.vertexIndex[0] == v) && (edgej.vertexIndex[1] == u)) {
                            // This is the most common of the four cases

                            // edgej = [v u B /]
                            match = true;
                            reversej = true;
                        }
                    } else {
                        if ((edgej.vertexIndex[0] == u) && (edgej.vertexIndex[1] == v)) {
                            // edgej = [u v / B]
                            match = true;
                        }
                    }
                } else {
                    // edgei = [u v / A]
                    if (edgej.faceIndex[0] != Face::NONE) {
                        if ((edgej.vertexIndex[0] == u) && (edgej.vertexIndex[1] == v)) {
                            // edgej = [u v B /]
                            match = true;
                        }
                    } else {
                        if ((edgej.vertexIndex[0] == v) && (edgej.vertexIndex[1] == u)) {
                            // edgej = [v u / B]
                            match = true;
                            reversej = true;
                        }
                    }
                }

                if (match) {
                    // ei and ej can be paired as a single edge
                    int e = edgeArray.size();
                    Edge& edge = edgeArray.next();

                    // Follow the direction of edgei.
                    edge = edgei;
                    newEdgeIndex[ei] = e;

                    // Insert the face index for edgej.
                    int fj = edgej.faceIndex[0];
                    if (fj == Face::NONE) {
                        fj = edgej.faceIndex[1];
                    }
                    
                    if (edge.faceIndex[0] == Face::NONE) {
                        edge.faceIndex[0] = fj;
                    } else {
                        edge.faceIndex[1] = fj;
                    }
                    
                    if (reversej) {
                        // The new edge is backwards of the old edge for ej
                        newEdgeIndex[ej] = ~e;
                    } else {
                        newEdgeIndex[ej] = e;
                    }

                    // Remove both ei and ej from being candidates for future pairing.
                    // Remove ej first since it comes later in the list (removing
                    // ei would decrease the index of ej to j - 1).
                    boundaryEdge.fastRemove(j);
                    boundaryEdge.fastRemove(i);

                    // Re-process element i, which is now a new edge index
                    --i;

                    // Jump out of the j for-loop
                    break;
                }
            }
        }
        ++cur;
    }

    // Anything remaining in the table is a real boundary edge; just copy it to
    // the end of the array.
    cur = boundaryEdgeIndices.begin();
    end = boundaryEdgeIndices.end();
    while (cur != end) {
        Array<int>&     boundaryEdge = cur->value;

        for (int b = 0; b < boundaryEdge.size(); ++b) {
            const int e = boundaryEdge[b];

            newEdgeIndex[e] = edgeArray.size();
            edgeArray.append(oldEdgeArray[e]);
        }

        ++cur;
    }

    // Finally, fix up edge indices in the face and vertex arrays
    for (int f = 0; f < faceArray.size(); ++f) {
        Face& face = faceArray[f];
        for (int i = 0; i < 3; ++i) {
            int e = face.edgeIndex[i];

            if (e < 0) {
                face.edgeIndex[i] = ~newEdgeIndex[~e];
            } else {
                face.edgeIndex[i] = newEdgeIndex[e];
            }
        }
    }

    for (int v = 0; v < vertexArray.size(); ++v) {
        Vertex& vertex = vertexArray[v];
        for (int i = 0; i < vertex.edgeIndex.size(); ++i) {
            int e = vertex.edgeIndex[i];

            if (e < 0) {
                vertex.edgeIndex[i] = ~newEdgeIndex[~e];
            } else {
                vertex.edgeIndex[i] = newEdgeIndex[e];
            }
        }
    }
}


void MeshAlg::weldAdjacency(
    const Array<Vector3>& originalGeometry,
    Array<Face>&          faceArray,
    Array<Edge>&          edgeArray,
    Array<Vertex>&        vertexArray,
    double                radius) {

    // Num vertices
    const int n = originalGeometry.size();

    // canonical[v] = first occurance of any vertex near oldVertexArray[v]
    Array<int> canonical;
    canonical.resize(n);

    Array<int> toNew, toOld;
    // Throw away the new vertex array
    Array<Vector3> dummy;
    computeWeld(originalGeometry, dummy, toNew, toOld, radius);

    for (int v = 0; v < canonical.size(); ++v) {
        // Round-trip through the toNew/toOld process.  This will give
        // us the original vertex.
        canonical[v] = toOld[toNew[v]];
    }

    // Destroy vertexArray (we reconstruct it below)
    vertexArray.clear();
    vertexArray.resize(n);

    bool hasBoundaryEdges = false;

    // Fix edge vertex indices
    for (int e = 0; e < edgeArray.size(); ++e) {
        Edge& edge = edgeArray[e];

        const int v0 = canonical[edge.vertexIndex[0]];
        const int v1 = canonical[edge.vertexIndex[1]];

        edge.vertexIndex[0] = v0;
        edge.vertexIndex[1] = v1;

        vertexArray[v0].edgeIndex.append(e);
        vertexArray[v1].edgeIndex.append(~e);

        hasBoundaryEdges = hasBoundaryEdges || edge.boundary();
    }

    // Fix face vertex indices
    for (int f = 0; f < faceArray.size(); ++f) {
        Face& face = faceArray[f];
        for (int i = 0; i < 3; ++i) {
            const int v = canonical[face.vertexIndex[i]];

            face.vertexIndex[i] = v;

            // Add the back pointer
            vertexArray[v].faceIndex.append(f);
        }
    }

    if (hasBoundaryEdges) {
        // As a result of the welding, some of the boundary edges at
        // the end of the array may now have mates and no longer be
        // boundaries.  Try to pair these up.

        weldBoundaryEdges(faceArray, edgeArray, vertexArray);
    }
}


void MeshAlg::debugCheckConsistency(
    const Array<Face>&      faceArray,
    const Array<Edge>&      edgeArray,
    const Array<Vertex>&    vertexArray) {

#ifdef _DEBUG
    for (int v = 0; v < vertexArray.size(); ++v) {
        const MeshAlg::Vertex& vertex = vertexArray[v];

        for (int i = 0; i < vertex.edgeIndex.size(); ++i) {
            const int e = vertex.edgeIndex[i];
            debugAssert(edgeArray[(e >= 0) ? e : ~e].containsVertex(v));
        }

        for (int i = 0; i < vertex.faceIndex.size(); ++i) {
            const int f = vertex.faceIndex[i];
            debugAssert(faceArray[f].containsVertex(v));
        }

    }

    for (int e = 0; e < edgeArray.size(); ++e) {
        const MeshAlg::Edge& edge = edgeArray[e];

        for (int i = 0; i < 2; ++i) {
            debugAssert((edge.faceIndex[i] == MeshAlg::Face::NONE) ||
                faceArray[edge.faceIndex[i]].containsEdge(e));

            debugAssert(vertexArray[edge.vertexIndex[i]].inEdge(e));
        }        
    }

    // Every face's edge must be on that face
    for (int f = 0; f < faceArray.size(); ++f) {
        const MeshAlg::Face& face = faceArray[f];
        for (int i = 0; i < 3; ++i) {
            int e = face.edgeIndex[i];
            int ei = (e >= 0) ? e : ~e;
            debugAssert(edgeArray[ei].inFace(f));

            // Make sure the edge is oriented appropriately 
            if (e >= 0) {
                debugAssert(edgeArray[ei].faceIndex[0] == (int)f);
            } else {
                debugAssert(edgeArray[ei].faceIndex[1] == (int)f);
            }

            debugAssert(vertexArray[face.vertexIndex[i]].inFace(f));
        }
    }
#else
    (void)faceArray;
    (void)edgeArray;
    (void)vertexArray;
#endif // _DEBUG
}

} // G3D namespace
