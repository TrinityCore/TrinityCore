#ifndef G3D_Welder_h
#define G3D_Welder_h

#include "G3D/platform.h"
#include "G3D/Array.h"
#include "G3D/Vector3.h"
#include "G3D/Vector2.h"

namespace G3D {

class Any;

class Welder {
private:

    Welder() {}

public:

    class Settings {
    public:
        /** Surfaces with normals that are within this angle of each
            other are considered to be curved.  Default value is toRadians(70.0f).*/
        float   normalSmoothingAngle;

        /** Default value is 0 */
        float      vertexWeldRadius;

        float      textureWeldRadius;

        float      normalWeldRadius;

        inline Settings(float normalSmoothAngle = toRadians(70.0f)) : 
            normalSmoothingAngle(normalSmoothAngle),
            vertexWeldRadius(0.001f), 
            textureWeldRadius(0.0001f), 
            normalWeldRadius(0.01f) {}


        Settings(const Any& any);
        
        Any toAny() const;

        void serialize(class BinaryOutput& b) const;

        void deserialize(class BinaryInput& b);
    };

/**
     Mutates geometry, texCoord, and indexArray so that the output has
     collocated vertices collapsed (welded).

     @param vertices Input and output
     @param textureCoords Input and output
     @param normals Output only
     @param indices Input and output. This is an array of trilist indices. 
     */
    static void weld(
        Array<Vector3>&     vertices,
        Array<Vector2>&     textureCoords, 
        Array<Vector3>&     normals,
        Array<Array<int>*>& indices,
        const Settings&     settings);

    /**
     Mutates geometry, texCoord, and indexArray so that the output has collocated vertices collapsed (welded).

     @param vertices Input and output
     @param textureCoords Input and output
     @param normals Output only
     @param indices Input and output. This is an array of trilist indices. 
     */
    inline static void weld(
        Array<Vector3>&     vertices,
        Array<Vector2>&     textureCoords, 
        Array<Vector3>&     normals,
        Array<int>&         indices,        
        const Settings&     settings) {

        Array<Array<int>*> meta;
        meta.append(&indices);
        weld(vertices, textureCoords, normals, meta, settings);
    }
};

}

#endif
