/**
 @file MeshAlg.h

 Indexed Mesh algorithms.

 @maintainer Morgan McGuire, http://graphics.cs.williams.edu

 @created 2003-09-14
 @edited  2010-01-18
*/

#ifndef G3D_MeshAlg_h
#define G3D_MeshAlg_h

#include "G3D/platform.h"
#include "G3D/Array.h"
#include "G3D/Vector3.h"
#include "G3D/CoordinateFrame.h"
#include "G3D/SmallArray.h"
#include "G3D/constants.h"
#include "G3D/Image1.h"

#ifdef G3D_WIN32
// Turn off "conditional expression is constant" warning; MSVC generates this
// for debug assertions in inlined methods.
#pragma warning (disable : 4127)
#endif

namespace G3D {

/**
  Indexed <B>mesh alg</B>orithms.  You have to build your own mesh class.
  <P>
  No mesh class is provided with G3D because there isn't an "ideal" 
  mesh format-- one application needs keyframed animation, another
  skeletal animation, a third texture coordinates, a fourth
  cannot precompute information, etc.  Instead of compromising, this
  class implements the hard parts of mesh computation and you can write
  your own ideal mesh class on top of it.

  \sa G3D::ArticulatedModel, G3D::IFSModel
  */ 
class MeshAlg {
public:

    /** \deprecated */
    typedef PrimitiveType Primitive;

    /** Adjacency information for a vertex.
        Does not contain the vertex position or normal,
        which are stored in the MeshAlg::Geometry object.
        <CODE>Vertex</CODE>s must be stored in an array
        parallel to (indexed in the same way as) 
        MeshAlg::Geometry::vertexArray.
        */
    class Vertex {
    public:
        Vertex() {}

        /**
         Array of edges adjacent to this vertex.
         Let e = edgeIndex[i].  
         edge[(e >= 0) ? e : ~e].vertexIndex[0] == this
         vertex index.
         
         Edges may be listed multiple times if they are
         degenerate.
         */
        SmallArray<int, 6>          edgeIndex;

        /**
         Returns true if e or ~e is in the edgeIndex list.
         */
        inline bool inEdge(int e) const {
            return edgeIndex.contains(~e) || edgeIndex.contains(e);
        }

        /**
         Array of faces containing this vertex.  Faces
         may be listed multiple times if they are degenerate.
        */
        SmallArray<int, 6>          faceIndex;

        inline bool inFace(int f) const {
            debugAssert(f >= 0);
            return faceIndex.contains(f);
        }
    };


    /**
     Oriented, indexed triangle.
     */
    class Face {
    public:
        Face();

        /**
         Used by Edge::faceIndex to indicate a missing face.
         This is a large negative value.
         */
        static const int        NONE;


        /**
         Vertices in the face in counter-clockwise order.
         Degenerate faces may include the same vertex multiple times.
         */
        int                     vertexIndex[3];

        inline bool containsVertex(int v) const {
            return contains(vertexIndex, 3, v);
        }

        /**
         Edge indices in counter-clockwise order.  Edges are
         undirected, so it is important to know which way 
         each edge is pointing in a face.  This is encoded
         using negative indices.
         
         If <CODE>edgeIndex[i] >= 0</CODE> then this face
         contains the directed edge
         between vertex indices  
         <CODE>edgeArray[face.edgeIndex[i]].vertexIndex[0]</CODE>
         and
         <CODE>edgeArray[face.edgeIndex[i]].vertexIndex[1]</CODE>.
         
         If <CODE>edgeIndex[i] < 0</CODE> then 
         <CODE>~edgeIndex[i]</CODE> (i.e. the two's
         complement of) is used and this face contains the directed
         edge between vertex indices
         <CODE>edgeArray[~face.edgeIndex[i]].vertexIndex[0]</CODE>
         and
         <CODE>edgeArray[~face.edgeIndex[i]].vertexIndex[1]</CODE>.

         Degenerate faces may include the same edge multiple times.
         */
        // Temporarily takes on the value Face::NONE during adjacency
        // computation to indicate an edge that has not yet been assigned.
        int                     edgeIndex[3];

        inline bool containsEdge(int e) const {
            if (e < 0) {
                e = ~e;
            }
            return contains(edgeIndex, 3, e) || contains(edgeIndex, 3, ~e);
        }

        /** Contains the forward edge e if e >= 0 and the backward edge 
            ~e otherwise. */
        inline bool containsDirectedEdge(int e) const {
            return contains(edgeIndex, 3, e);
        }
    };


    /** Oriented, indexed edge */
    class Edge {
    public:
        Edge();

        /** Degenerate edges may include the same vertex times. */
        int                     vertexIndex[2];
        
        inline bool containsVertex(int v) const {
            return contains(vertexIndex, 2, v);
        }

        /**
         The edge is directed <B>forward</B> in face 0
         <B>backward</B> in face 1. Face index of MeshAlg::Face::NONE
         indicates a boundary (a.k.a. crack, broken) edge.
         */
        int                     faceIndex[2];
        
        /** Returns true if f is contained in the faceIndex array in either slot.
            To see if it is forward in that face, just check edge.faceIndex[0] == f.*/
        inline bool inFace(int f) const {
            return contains(faceIndex, 2, f);
        }

        /**
         Returns true if either faceIndex is NONE.
         */
        inline bool boundary() const {
            return (faceIndex[0] == Face::NONE) ||
                   (faceIndex[1] == Face::NONE);
        }

        /**
         Returns the reversed edge.
         */
        inline Edge reverse() const {
            Edge e;
            e.vertexIndex[0] = vertexIndex[1];
            e.vertexIndex[1] = vertexIndex[0];
            e.faceIndex[0]   = faceIndex[1];
            e.faceIndex[1]   = faceIndex[0];
            return e;
        }
    };
    

    /**
     Convenient for passing around the per-vertex data that changes under
     animation. The faces and edges are needed to interpret 
     these values.
     */
    class Geometry {
    public:        
        /** Vertex positions */
        Array<Vector3>          vertexArray;

        /** Vertex normals */
        Array<Vector3>          normalArray;

        /**
         Assignment is optimized using SSE.
         */
        Geometry& operator=(const Geometry& src);

        void clear() {
            vertexArray.clear();
            normalArray.clear();
        }
    };

    /**
     Given a set of vertices and a set of indices for traversing them
     to create triangles, computes other mesh properties.  

     <B>Colocated vertices are treated as separate.</B>  To have
     colocated vertices collapsed (necessary for many algorithms,
     like shadowing), weld the mesh before computing adjacency.
     
     <I>Recent change: In version 6.00, colocated vertices were automatically
     welded by this routine and degenerate faces and edges were removed.  That
     is no longer the case.</I>

     Where two faces meet, there are two opposite directed edges.  These
     are collapsed into a single bidirectional edge in the edgeArray.
     If four faces meet exactly at the same edge, that edge will appear
     twice in the array, and so on.  If an edge is a boundary of the mesh 
     (i.e. if the edge has only one adjacent face) it will appear in the 
     array with one  face index set to MeshAlg::Face::NONE.

     @param vertexGeometry  %Vertex positions to use when deciding colocation.
     @param indexArray      Order to traverse vertices to make triangles
     @param faceArray       <I>Output</I>
     @param edgeArray       <I>Output</I>.  Sorted so that boundary edges are at the end of the array. 
     @param vertexArray     <I>Output</I> 
     */
    static void computeAdjacency(
        const Array<Vector3>&   vertexGeometry,
        const Array<int>&       indexArray,
        Array<Face>&            faceArray,
        Array<Edge>&            edgeArray,
        Array<Vertex>&          vertexArray);

    /**
     @deprecated Use the other version of computeAdjacency, which takes Array<Vertex>.
     @param facesAdjacentToVertex <I>Output</I> adjacentFaceArray[v] is an array of
                        indices for faces touching vertex index v
     */
    static void computeAdjacency(
        const Array<Vector3>&   vertexArray,
        const Array<int>&       indexArray,
        Array<Face>&            faceArray,
        Array<Edge>&            edgeArray,
        Array< Array<int> >&    facesAdjacentToVertex);

    /**
     Computes some basic mesh statistics including: min, max mean and median, 
     edge lengths; and min, mean, median, and max face area.

     @param vertexArray         %Vertex positions to use when deciding colocation.
     @param indexArray          Order to traverse vertices to make triangles
     @param minEdgeLength       Minimum edge length
     @param meanEdgeLength      Mean edge length
     @param medianEdgeLength    Median edge length
     @param maxEdgeLength       Max edge length
     @param minFaceArea         Minimum face area
     @param meanFaceArea        Mean face area
     @param medianFaceArea      Median face area
     @param maxFaceArea         Max face area
     */
    static void computeAreaStatistics(
        const Array<Vector3>&   vertexArray,
        const Array<int>&       indexArray,
        double&                 minEdgeLength,
        double&                 meanEdgeLength,
        double&                 medianEdgeLength,
        double&                 maxEdgeLength,
        double&                 minFaceArea,
        double&                 meanFaceArea,
        double&                 medianFaceArea,
        double&                 maxFaceArea);

private:

    /** Helper for weldAdjacency */
    static void weldBoundaryEdges(
        Array<Face>&       faceArray,
        Array<Edge>&       edgeArray,
        Array<Vertex>&     vertexArray);

public:

    /**
     Computes tangent and binormal vectors,
     which provide a (mostly) consistent
     parameterization over the surface for
     effects like bump mapping.  In the resulting coordinate frame, 
     T = x (varies with texture s coordinate), B = y (varies with negative texture t coordinate), 
     and N = z for a right-handed coordinate frame.  If a billboard is vertical on the screen
     in view of the camera, the tangent space matches the camera's coordinate frame.

     The vertex, texCoord, tangent, and binormal
     arrays are parallel arrays.

     The resulting tangent and binormal might not be exactly
     perpendicular to each other.  They are guaranteed to
     be perpendicular to the normal.

     @cite Max McGuire
    */
    static void computeTangentSpaceBasis(
        const Array<Vector3>&       vertexArray,
        const Array<Vector2>&       texCoordArray,
        const Array<Vector3>&       vertexNormalArray,
        const Array<Face>&          faceArray,
        Array<Vector3>&             tangent,
        Array<Vector3>&             binormal);

    /** @deprecated */
    static void computeNormals(
        const Array<Vector3>&   vertexArray,
        const Array<Face>&      faceArray,
        const Array< Array<int> >& adjacentFaceArray,
        Array<Vector3>&         vertexNormalArray,
        Array<Vector3>&         faceNormalArray);

    /**
     Vertex normals are weighted by the area of adjacent faces.
     Nelson Max showed this is superior to uniform weighting for
     general meshes in jgt.

     @param vertexNormalArray Output. Unit length
     @param faceNormalArray Output.   Degenerate faces produce zero magnitude normals. Unit length
     @see weld
    */
    static void computeNormals(
        const Array<Vector3>&   vertexGeometry,
        const Array<Face>&      faceArray,
        const Array<Vertex>&    vertexArray,
        Array<Vector3>&         vertexNormalArray,
        Array<Vector3>&         faceNormalArray);

    /** Computes unit length normals in place using the other computeNormals methods.
     If you already have a face array use another method; it will be faster. 
         @see weld*/
    static void computeNormals(
        Geometry&               geometry,
        const Array<int>&       indexArray);

    /**
     Computes face normals only.  Significantly faster (especially if
     normalize is false) than computeNormals.
     @see weld
     */
    static void computeFaceNormals(
        const Array<Vector3>&           vertexArray,
        const Array<Face>&              faceArray,
        Array<Vector3>&                 faceNormals,
        bool                            normalize = true);

    /**
     Classifies each face as a backface or a front face relative
     to the observer point P (which is at infinity when P.w = 0).
     A face with normal exactly perpendicular to the observer vector
     may be classified as either a front or a back face arbitrarily.
     */
    static void identifyBackfaces(
        const Array<Vector3>&           vertexArray,
        const Array<Face>&              faceArray,
        const Vector4&                  P,
        Array<bool>&                    backface);

    /** A faster version of identifyBackfaces for the case where
        face normals have already been computed */
    static void identifyBackfaces(
        const Array<Vector3>&           vertexArray,
        const Array<Face>&              faceArray,
        const Vector4&                  P,
        Array<bool>&                    backface,
        const Array<Vector3>&           faceNormals);

    /**
     Welds nearby and colocated elements of the <I>oldVertexArray</I> together so that
     <I>newVertexArray</I> contains no vertices within <I>radius</I> of one another.
     Every vertex in newVertexPositions also appears in oldVertexPositions.
     This is useful for downsampling meshes and welding cracks created by artist errors
     or numerical imprecision.  

     The two integer arrays map indices back and forth between the arrays according to:
     <PRE>
     oldVertexArray[toOld[ni]] == newVertexArray[ni]
     oldVertexArray[oi] == newVertexArray[toNew[ni]]
     </PRE>

     Note that newVertexPositions is never longer than oldVertexPositions
     and is shorter when vertices are welded.

     Welding with a large radius will effectively compute a lower level of detail for
     the mesh.

     The welding method runs in roughly linear time in the length of oldVertexArray--
     a uniform spatial grid is used to achieve nearly constant time vertex collapses
     for uniformly distributed vertices.

     It is sometimes desirable to keep the original vertex ordering but 
     identify the unique vertices.  The following code computes 
     array canonical s.t. canonical[v] = first occurance of 
     a vertex near oldVertexPositions[v] in oldVertexPositions.

     <PRE>
        Array<int> canonical(oldVertexPositions.size()), toNew, toOld;
        computeWeld(oldVertexPositions, Array<Vector3>(), toNew, toOld, radius);
        for (int v = 0; v < canonical.size(); ++v) {
            canonical[v] = toOld[toNew[v]];
        }
     </PRE>

     See also G3D::MeshAlg::weldAdjacency.

     @cite The method is that described as the 'Grouper' in Baum, Mann, Smith, and Winget, 
     Making Radiosity Usable: Automatic Preprocessing and Meshing Techniques for
     the Generation of Accurate Radiosity Solutions, Computer Graphics vol 25, no 4, July 1991.

     @deprecated Use weld.
     */
    static void computeWeld(
        const Array<Vector3>& oldVertexPositions,
        Array<Vector3>&       newVertexPositions,
        Array<int>&           toNew,
        Array<int>&           toOld,
        double                radius = fuzzyEpsilon);

    /**
     Modifies the face, edge, and vertex arrays in place so that
     colocated (within radius) vertices are treated as identical.
     Note that the vertexArray and corresponding geometry will
     contain elements that are no longer used.  In the vertexArray,
     these elements are initialized to MeshAlg::Vertex() but not 
     removed (because removal would change the indexing).
     
     This is a good preprocessing step for algorithms that are only
     concerned with the shape of a mesh (e.g. cartoon rendering, fur, shadows)
     and not the indexing of the vertices.

     Use this method when you have already computed adjacency information
     and want to collapse colocated vertices within that data without
     disturbing the actual mesh vertices or indexing scheme.  
     
     If you have not computed adjacency already, use MeshAlg::computeWeld
     instead and compute adjacency information after welding.

     @deprecated Use weld.

     @param faceArray Mutated in place.  Size is maintained (degenerate
            faces are <b>not</B> removed).
     @param edgeArray Mutated in place.  May shrink if boundary edges
            are welded together.
     @param vertexArray Mutated in place.  Size is maintained (duplicate
            vertices contain no adjacency info).
    */
    static void weldAdjacency(
        const Array<Vector3>& originalGeometry,
        Array<Face>&          faceArray,
        Array<Edge>&          edgeArray,
        Array<Vertex>&        vertexArray,
        double                radius = fuzzyEpsilon);


    /**
     Counts the number of edges (in an edge array returned from 
     MeshAlg::computeAdjacency) that have only one adjacent face.
     */
    static int countBoundaryEdges(const Array<Edge>& edgeArray);


    /**
     Generates an array of integers from start to start + n - 1 that have run numbers
     in series then omit the next skip before the next run.  Useful for turning
     a triangle list into an indexed face set.

     Example: 
     <PRE>
       createIndexArray(10, x);
       // x = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9] 

       createIndexArray(5, x, 2);
       // x = [2, 3, 4, 5, 6, 7] 

       createIndexArray(6, x, 0, 2, 1);
       // x = [0, 1, 3, 4, 6, 7]
     </PRE>
     */
    static void createIndexArray(
        int                 n, 
        Array<int>&         array,
        int                 start   = 0,
        int                 run     = 1,
        int                 skip    = 0);

    /**
     Computes a conservative, near-optimal axis aligned bounding box and sphere. 

      @cite The bounding sphere uses the method from J. Ritter. An effcient bounding sphere. In Andrew S. Glassner, editor, Graphics Gems. Academic Press, Boston, MA, 1990.

    */
    static void computeBounds(const Array<Vector3>& vertex, class AABox& box, class Sphere& sphere);

    /** Computes bounds for a subset of the vertices.  It is ok if vertices appear more than once in the index array. */
    static void computeBounds(const Array<Vector3>& vertex, const Array<int>& index, class AABox& box, class Sphere& sphere);
    
    /**
     In debug mode, asserts that the adjacency references between the
     face, edge, and vertex array are consistent.
     */
    static void debugCheckConsistency(
        const Array<Face>&      faceArray,
        const Array<Edge>&      edgeArray,
        const Array<Vertex>&    vertexArray);

    /**
     Generates a unit square in the X-Z plane composed of a grid of wCells x hCells
     squares and then transforms it by xform.

     @param vertex Output vertices
     @param texCoord Output texture coordinates
     @param index Output triangle list indices
     @param textureScale Lower-right texture coordinate
     @param spaceCentered If true, the coordinates generated are centered at the origin before the transformation.
     @param twoSided If true, matching top and bottom planes are generated.
     \param elevation If non-NULL, values from this image are used as elevations.  Apply an \a xform to adjust the scale
     */
    static void generateGrid(
        Array<Vector3>&     vertex,
        Array<Vector2>&     texCoord,
        Array<int>&         index,
        int                 wCells = 10, 
        int                 hCells = 10,
        const Vector2&      textureScale = Vector2(1,1),
        bool                spaceCentered = true,
        bool                twoSided = true,
        const CoordinateFrame& xform = CoordinateFrame(),
        const Image1::Ref&  elevation = NULL);

    /** Converts quadlist (QUADS), 
        triangle fan (TRIANGLE_FAN),
        tristrip(TRIANGLE_STRIP), and quadstrip (QUAD_STRIP) indices into
        triangle list (TRIANGLES) indices and appends them to outIndices. */
    template<class IndexType>
    static void toIndexedTriList(
        const Array<IndexType>& inIndices, 
        MeshAlg::Primitive      inType, 
        Array<IndexType>&       outIndices) {

        debugAssert(
            inType == PrimitiveType::TRIANGLE_STRIP ||
            inType == PrimitiveType::TRIANGLE_FAN ||
            inType == PrimitiveType::QUADS ||
            inType == PrimitiveType::QUAD_STRIP);

        const int inSize = inIndices.size();

        switch(inType) {
        case PrimitiveType::TRIANGLE_FAN:
            {
            debugAssert(inSize >= 3);

            int N = outIndices.size();
            outIndices.resize(N + (inSize - 2) * 3);

            for (IndexType i = 1, outIndex = N; i <= (inSize - 2); ++i, outIndex += 3) {
                outIndices[outIndex] = inIndices[0];
                outIndices[outIndex + 1] = inIndices[i];
                outIndices[outIndex + 2] = inIndices[i + 1];
            }

            break;
            }

        case PrimitiveType::TRIANGLE_STRIP:
            {
            debugAssert(inSize >= 3);

            int N = outIndices.size();
            outIndices.resize(N + (inSize - 2) * 3);

            bool atEven = false;
            for (IndexType i = 0, outIndex = N; i < (inSize - 2); ++i, outIndex += 3) {
                if (atEven) {
                    outIndices[outIndex] = inIndices[i + 1];
                    outIndices[outIndex + 1] = inIndices[i];
                    outIndices[outIndex + 2] = inIndices[i + 2];
                    atEven = false;
                } else {
                    outIndices[outIndex] = inIndices[i];
                    outIndices[outIndex + 1] = inIndices[i + 1];
                    outIndices[outIndex + 2] = inIndices[i + 2];
                    atEven = true;
                }
            }

            break;
            }

        case PrimitiveType::QUADS:
            {
            debugAssert(inIndices.size() >= 4);

            int N = outIndices.size();
            outIndices.resize(N + (inSize / 4) * 3);

            for (IndexType i = 0, outIndex = N; i <= (inSize - 4); i += 4, outIndex += 6) {
                outIndices[outIndex] = inIndices[i];
                outIndices[outIndex + 1] = inIndices[i + 1];
                outIndices[outIndex + 2] = inIndices[i + 3];
                outIndices[outIndex + 3] = inIndices[i + 1];
                outIndices[outIndex + 4] = inIndices[i + 2];
                outIndices[outIndex + 5] = inIndices[i + 3];
            }

            break;
            }

        case PrimitiveType::QUAD_STRIP:
            {
            debugAssert(inIndices.size() >= 4);

            int N = outIndices.size();
            outIndices.resize(N + (inSize - 2) * 3);

            for (IndexType i = 0, outIndex = N; i <= (inSize - 2); i += 2, outIndex += 6) {
                outIndices[outIndex] = inIndices[i];
                outIndices[outIndex + 1] = inIndices[i + 1];
                outIndices[outIndex + 2] = inIndices[i + 2];
                outIndices[outIndex + 3] = inIndices[i + 2];
                outIndices[outIndex + 4] = inIndices[i + 1];
                outIndices[outIndex + 5] = inIndices[i + 3];
            }
            break;
            }
        default:
            alwaysAssertM(false, "Illegal argument");
        }
    }

protected:

    /**
     Helper for computeAdjacency.  If a directed edge with index e already
     exists from i0 to i1 then e is returned.  If a directed edge with index e
     already exists from i1 to i0, ~e is returned (the complement) and
     edgeArray[e] is set to f.  Otherwise, a new edge is created from i0 to i1
     with first face index f and its index is returned.
    
     @param vertexArray Vertex positions to use when deciding colocation.
     
     @param area Area of face f.  When multiple edges of the same direction 
       are found between the same vertices (usually because of degenerate edges)
       the face with larger area is kept in the edge table.
     */
    static int findEdgeIndex(
        const Array<Vector3>&   vertexArray,
        Array<Edge>&            geometricEdgeArray,
        int i0, int i1, int f, double area);
};
}
#endif

