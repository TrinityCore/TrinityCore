/**
 @file Welder.cpp

 @author Morgan McGuire, Kyle Whitson, Corey Taylor

 @created 2008-07-30
 @edited  2009-11-29
 */

#include "G3D/platform.h"
#include "G3D/Vector2.h"
#include "G3D/Vector3.h"
#include "G3D/Sphere.h"
#include "G3D/PointHashGrid.h"
#include "G3D/Welder.h"
#include "G3D/Stopwatch.h" // for profiling
#include "G3D/AreaMemoryManager.h"
#include "G3D/Any.h"
#include "G3D/stringutils.h"

namespace G3D { namespace _internal{


/** Used by WeldHelper2::smoothNormals. */
class VN {
public:
    Vector3         vertex;
    Vector3         normal;

    VN() {}
    VN(const Vector3& v, const Vector3& n) : vertex(v), normal(n) {}
};

/** Used by WeldHelper::getIndex to maintain a list of vertices by location. */
class VNTi {
public:
    Vector3         vertex;
    Vector3         normal;
    Vector2         texCoord;
    int             index;

    VNTi() : index(0) {}

    VNTi(const Vector3& v, const Vector3& n, const Vector2& t, int i) : 
        vertex(v), normal(n), texCoord(t), index(i) {}
};


}} // G3D

template <> struct HashTrait <G3D::_internal::VN> {
    static size_t hashCode(const G3D::_internal::VN& k) { return static_cast<size_t>(k.vertex.hashCode()); }
};
template <> struct HashTrait <G3D::_internal::VNTi> {
    static size_t hashCode(const G3D::_internal::VNTi& k) { return static_cast<size_t>(k.vertex.hashCode()); }
};


template<> struct EqualsTrait <G3D::_internal::VN> {
    static bool equals(const G3D::_internal::VN& a, const G3D::_internal::VN& b) { return a.vertex == b.vertex; }
};
template<> struct EqualsTrait <G3D::_internal::VNTi> {
    static bool equals(const G3D::_internal::VNTi& a, const G3D::_internal::VNTi& b) { return a.vertex == b.vertex; }
};

template<> struct PositionTrait<G3D::_internal::VN> {
    static void getPosition(const G3D::_internal::VN& v, G3D::Vector3& p) { p = v.vertex; }
};
template<> struct PositionTrait<G3D::_internal::VNTi> {
    static void getPosition(const G3D::_internal::VNTi& v, G3D::Vector3& p) { p = v.vertex; }
};

namespace G3D { namespace _internal {

class WeldHelper {
private:
    /** Used by getIndex and updateTriLists */
    PointHashGrid<VNTi>     weldGrid;

    Array<Vector3>*         outputVertexArray;
    Array<Vector3>*         outputNormalArray;
    Array<Vector2>*         outputTexCoordArray;

    float                   vertexWeldRadius;
    /** Squared radius allowed for welding similar normals. */
    float                   normalWeldRadius2;
    float                   texCoordWeldRadius2;

    float                   normalSmoothingAngle;

    /**
     Returns the index of the vertex in 
     outputVertexArray/outputNormalArray/outputTexCoordArray
     that is within the global tolerances of v,n,t. If there 
     is no such vertex, adds it to the arrays and returns that index.

     Called from updateTriLists().
     */
    int getIndex(const Vector3& v, const Vector3& n, const Vector2& t) {
        PointHashGrid<VNTi>::SphereIterator it = 
                weldGrid.beginSphereIntersection(Sphere(v, vertexWeldRadius));

        if (n.isZero()) {
            // Don't bother trying to match the surface normal, since this vertex has no surface normal.
            while (it.hasMore()) {
                if ((t - it->texCoord).squaredLength() <= texCoordWeldRadius2) {
                    // This is the vertex
                    return it->index;
                }
                ++it;
            }
        } else {
            while (it.hasMore()) {
                if (((n - it->normal).squaredLength() <= normalWeldRadius2) &&
                    ((t - it->texCoord).squaredLength() <= texCoordWeldRadius2)) {
                    // This is the vertex
                    return it->index;
                }
                ++it;
            }
        }

        // Note that a sliver triangle processed before its neighbors may reach here
        // with a zero length normal.

        // The vertex does not exist. Create it.
        const int i = outputVertexArray->size();
        outputVertexArray->append(v);
        outputNormalArray->append(n);
        outputTexCoordArray->append(t);

        // Store in the grid so that it will be remembered.
        weldGrid.insert(VNTi(v, n, t, i));

        return i;
    }


    /**
     Updates each indexArray to refer to vertices in the
     outputVertexArray.

     Called from process()
     */
    void updateTriLists(
        Array<Array<int>*>&         indexArrayArray, 
        const Array<Vector3>&       vertexArray,
        const Array<Vector3>&       normalArray,
        const Array<Vector2>&       texCoordArray) {
        
        // Compute a hash grid so that we can find neighbors quickly.
        // It begins empty and is extended as the tri lists are iterated
        // through.
        weldGrid.clear();

        // Process all triLists
        int numTriLists = indexArrayArray.size();
        int u = 0;
        for (int t = 0; t < numTriLists; ++t) {
            Array<int>& triList = *(indexArrayArray[t]);

            // For all vertices in this list
            for (int v = 0; v < triList.size(); ++v) {
                // This vertex mapped to u in the flatVertexArray
                triList[v] = getIndex(vertexArray[u], normalArray[u], texCoordArray[u]);

                /*
#           ifdef G3D_DEBUG
            {
                int i = triList[v];
                Vector3 N = normalArray[i];
                debugAssertM(N.length() > 0.9f, "Produced non-unit normal");
            }
#           endif
            */
                ++u;
            }
        }
    }

    /** Expands the indexed triangle lists into a triangle list.

        Called from process() */
    void unroll(
        const Array<Array<int>*>&   indexArrayArray, 
        const Array<Vector3>&       vertexArray, 
        const Array<Vector2>&       texCoordArray, 
        Array<Vector3>&             unrolledVertexArray, 
        Array<Vector2>&             unrolledTexCoordArray) {

        int numTriLists = indexArrayArray.size();
        for (int t = 0; t < numTriLists; ++t) {
            const Array<int>& triList = *(indexArrayArray[t]);
            for (int v = 0; v < triList.size(); ++v) {
                int i = triList[v];
                unrolledVertexArray.append(vertexArray[i]);
                unrolledTexCoordArray.append(texCoordArray[i]);
            }
        }
    }

    /** For every three vertices, compute the face normal and store it three times.
        Sliver triangles have a zero surface normal, which we will later take to
        match *any* surface normal. */
    void computeFaceNormals(
        const Array<Vector3>&  vertexArray, 
        Array<Vector3>&        faceNormalArray) {

        debugAssertM(vertexArray.size() % 3 == 0, "Input is not a triangle soup");
        debugAssertM(faceNormalArray.size() == 0, "Output must start empty.");

        for (int v = 0; v < vertexArray.size(); v += 3) {
            const Vector3& e0 = vertexArray[v + 1] - vertexArray[v];
            const Vector3& e1 = vertexArray[v + 2] - vertexArray[v];

            // Note that the length may be zero in the case of sliver polygons, e.g.,
            // those correcting a T-junction.
            const Vector3& n  = e0.cross(e1).directionOrZero(); 

            // Append the normal once per vertex.
            faceNormalArray.append(n, n, n);
        }
    }

    /**
     Computes @a smoothNormalArray, whose elements are those of normalArray averaged
     with neighbors within the angular cutoff.
     */
    void smoothNormals(
        const Array<Vector3>& vertexArray, 
        const Array<Vector3>& normalArray, 
        Array<Vector3>&       smoothNormalArray) {

        // Create an area memory manager for fast deallocation
        MemoryManager::Ref mm = AreaMemoryManager::create(iRound(sizeof(VN) * normalArray.size() * 1.5));
        
        if (normalSmoothingAngle <= 0) {
            smoothNormalArray = normalArray;
            return;
        }

        const float cosThresholdAngle = (float)cos(normalSmoothingAngle);

        debugAssert(vertexArray.size() == normalArray.size());
        smoothNormalArray.resize(normalArray.size());

        // Compute a hash grid so that we can find neighbors quickly.
        PointHashGrid<VN> grid(vertexWeldRadius, mm);
        for (int v = 0; v < normalArray.size(); ++v) {
            grid.insert(VN(vertexArray[v], normalArray[v]));
        }

        for (int v = 0; v < normalArray.size(); ++v) {            
            // Compute the sum of all nearby normals within the cutoff angle.
            // Search within the vertexWeldRadius, since those are the vertices
            // that will collapse to the same point.
            PointHashGrid<VN>::SphereIterator it = 
                grid.beginSphereIntersection(Sphere(vertexArray[v], vertexWeldRadius));

            Vector3 sum;

            const Vector3& original = normalArray[v];
            while (it.hasMore()) {
                const Vector3& N = it->normal;
                const float cosAngle = N.dot(original);

                if (cosAngle > cosThresholdAngle) {
                    // This normal is close enough to consider
                    sum += N;
                }
                ++it;
            }

            const Vector3& average = sum.directionOrZero();

            const bool indeterminate = average.isZero();
            // Never "smooth" a normal so far that it points backwards
            const bool backFacing    = original.dot(average) < 0;

            if (indeterminate || backFacing) {
                // Revert to the face normal
                smoothNormalArray[v] = original;
            } else {
                // Average available normals
                smoothNormalArray[v] = average;
            }
        }
    }

public:


    /**
    Algorithm:

    1. Unroll the indexed triangle list into a triangle list, where
       there are duplicated vertices.

    2. Compute face normals for all triangles, and expand those into
       the triangle vertices.

    3. At each vertex, average all normals that are within normalSmoothingAngle.

    4. Generate output indexArrayArray.  While doing so, merge all vertices where 
       the distance between position, texCoord, and normal is within the thresholds.
     */
    void process(
        Array<Vector3>&     vertexArray,
        Array<Vector2>&     texCoordArray, 
        Array<Vector3>&     normalArray,
        Array<Array<int>*>& indexArrayArray,
        float               normAngle,
        float               texRadius,
        float               normRadius) {

        normalSmoothingAngle = normAngle;
        normalWeldRadius2    = square(normRadius);
        texCoordWeldRadius2  = square(texRadius);

        const bool hasTexCoords = (texCoordArray.size() > 0);

        if (hasTexCoords) {
            debugAssertM(vertexArray.size() == texCoordArray.size(), 
                "Input arrays are not parallel.");
        }

        Array<Vector3> unrolledVertexArray;
        Array<Vector3> unrolledFaceNormalArray;
        Array<Vector3> unrolledSmoothNormalArray;
        Array<Vector2> unrolledTexCoordArray;

        if (! hasTexCoords) {
            // Generate all zero texture coordinates
            texCoordArray.resize(vertexArray.size());
        }

        // Generate a flat (unrolled) triangle list with texture coordinates.
        unroll(indexArrayArray, vertexArray, texCoordArray, 
            unrolledVertexArray, unrolledTexCoordArray);

        // Put the output back into the input slots. 
        outputVertexArray   = &vertexArray;
        outputNormalArray   = &normalArray;
        outputTexCoordArray = &texCoordArray;
        outputVertexArray->fastClear();
        outputNormalArray->fastClear();
        outputTexCoordArray->fastClear();

        // For every three vertices, generate their face normal and store it at 
        // each vertex. The output array has the same length as the input.
        computeFaceNormals(unrolledVertexArray, unrolledFaceNormalArray);

        // Compute smooth normals at vertices.
        if (unrolledFaceNormalArray.size() > 0) {
            smoothNormals(unrolledVertexArray, unrolledFaceNormalArray, unrolledSmoothNormalArray);
            unrolledFaceNormalArray.clear();
        }

        // Regenerate the triangle lists
        updateTriLists(indexArrayArray, unrolledVertexArray, unrolledSmoothNormalArray, unrolledTexCoordArray);

        if (! hasTexCoords) {
            // Throw away the generated texCoords
            texCoordArray.resize(0);
        }
    }

    WeldHelper(float vertRadius) :
        weldGrid(vertRadius),
        vertexWeldRadius(vertRadius) {}

};
} // Internal

void Welder::weld(
    Array<Vector3>&     vertexArray,
    Array<Vector2>&     texCoordArray, 
    Array<Vector3>&     normalArray,
    Array<Array<int>*>& indexArrayArray,
    const Welder::Settings& settings) {

    _internal::WeldHelper(settings.vertexWeldRadius).process(
        vertexArray, texCoordArray, normalArray, indexArrayArray, 
        settings.normalSmoothingAngle, settings.textureWeldRadius, settings.normalWeldRadius);
}


Welder::Settings::Settings(const Any& any) {
    *this = Settings();
    any.verifyName("Welder::Settings");
    for (Any::AnyTable::Iterator it = any.table().begin(); it.hasMore(); ++it) {
        const std::string& key = toLower(it->key);
        if (key == "normalsmoothingangle") {
            normalSmoothingAngle = it->value;
        } else if (key == "vertexweldradius") {
            vertexWeldRadius = it->value;
        } else if (key == "textureweldradius") {
            textureWeldRadius = it->value;
        } else if (key == "normalweldradius") {
            normalWeldRadius = it->value;
        } else {
            any.verify(false, "Illegal key: " + it->key);
        }
    }
}

Welder::Settings::operator Any() const {
    Any a(Any::TABLE, "Welder::Settings");
    a.set("normalSmoothingAngle", normalSmoothingAngle);
    a.set("vertexWeldRadius", vertexWeldRadius);
    a.set("textureWeldRadius", textureWeldRadius);
    a.set("normalWeldRadius", normalWeldRadius);
    return a;
}

} // G3D
