/**
  @file MeshBuilder.h

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu

  @created 2002-02-27
  @edited  2004-10-04
 */ 
#ifndef G3D_MESHBUILDER_H
#define G3D_MESHBUILDER_H

#include "G3D/platform.h"
#include "G3D/Array.h"
#include "G3D/Vector3.h"
#include "G3D/Triangle.h"

namespace G3D {

/**
 Allows creation of optimized watertight meshes from unoptimized polygon soups.
 See also G3D::MeshAlg for algorithms that operate on the output.
 */
class MeshBuilder {
public:

    /**
     Set setWeldRadius to AUTO_WELD to weld vertices closer than 1/2
     the smallest edge length in a model.
     */
    enum {AUTO_WELD = -100};

private:
    /** Indices of vertices in <B>or near</B>  a grid cell. */
    typedef Array<int> List;
   
    std::string                 name;

    bool                        scaleAndCenter;
    
    /**
     All of the triangles, as a long triangle list.
     */
    Array<Vector3>              triList;

    void centerTriList();
    void computeBounds(Vector3& min, Vector3& max);

    bool _twoSided;

    /** Collapse radius */
    double close;

public:

    inline MeshBuilder(bool twoSided = false, bool scaleAndCenter = true) : scaleAndCenter(scaleAndCenter), _twoSided(twoSided), close(AUTO_WELD) {}

    /** Writes the model to the arrays, which can then be used with
        G3D::IFSModel::save and G3D::MeshAlg */
    void commit(std::string& name, Array<int>& indexArray, Array<Vector3>& vertexArray);

    /**
     Adds a new triangle to the model. (Counter clockwise)
     */
    void addTriangle(const Vector3& a, const Vector3& b, const Vector3& c);

    /**
     Adds two new triangles to the model. (Counter clockwise)
     */
    void addQuad(const Vector3& a, const Vector3& b, const Vector3& c, const Vector3& d);

    void addTriangle(const Triangle& t);

    void setName(const std::string& n);

    /** Vertices within this distance are considered identical.  
        Use AUTO_WELD (the default) to have the distance be a function of the model size.*/
    void setWeldRadius(double r) {
        close = r;
    }
};

} // namespace

#endif
