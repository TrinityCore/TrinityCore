/**
  \file G3D/constants.h

  \maintainer Morgan McGuire, http://graphics.cs.williams.edu
  \created 2009-05-20
  \edited  2013-09-27
*/
#ifndef G3D_constants_h
#define G3D_constants_h

#include "G3D/platform.h"
#include "G3D/enumclass.h"
#include "G3D/Any.h"

namespace G3D {

/** These are defined to have the same value as the equivalent OpenGL
    constant. */
class PrimitiveType {
public:
    enum Value {
        POINTS         = 0x0000,
        LINES          = 0x0001,
        LINE_STRIP     = 0x0003, 
        TRIANGLES      = 0x0004, 
        TRIANGLE_STRIP = 0x0005,
        TRIANGLE_FAN   = 0x0006,
        QUADS          = 0x0007, 
        QUAD_STRIP     = 0x0008,
        PATCHES        = 0x000E
    };

private:
    
    static const char* toString(int i, Value& v);

    Value value;

public:

    G3D_DECLARE_ENUM_CLASS_METHODS(PrimitiveType);
};


/** Values for UniversalSurface::GPUGeom::refractionHint. */
G3D_DECLARE_ENUM_CLASS(RefractionQuality,
        /** No refraction; a translucent object will appear as if it had the same index of refraction
            as the surrounding medium and objects will be undistorted in the background. */
        NONE, 

        /** Use a static environment map (cube or paraboloid) for computing transmissivity.*/
        STATIC_PROBE, 

        /** Use a dynamically rendered 2D environment map; distort the background.  This looks good for many scenes
            but avoids the cost of rendering a cube map for DYNAMIC_ENV. */
        DYNAMIC_FLAT,

        /** Use a screen-space hack to approximate refraction */
        SCREEN_SPACE,

        /** Use a dynamically rendered 2D environment map that is re-captured per transparent object.  This works well
            for transparent objects that are separated by a significant camera space z distance but overlap in screen space.*/
        DYNAMIC_FLAT_MULTILAYER,

        /** Render a dynamic environment map */
        DYNAMIC_PROBE, 

        /** True ray tracing. */
        RAY_TRACE);


/** Values for UniversalSurface::GPUGeom::mirrorHint. */
G3D_DECLARE_ENUM_CLASS(MirrorQuality,
        /** Reflections are black */
        NONE, 
        
        /** Use a static environment map.  This is what most games use */
        STATIC_PROBE,
        
        /** Use a screen-space hack to approximate reflection */
        SCREEN_SPACE,

        /** Render a dynamic environment map. */
        DYNAMIC_PROBE, 
        
        /** True ray tracing. */
        RAY_TRACE);

} // namespace G3D

G3D_DECLARE_ENUM_CLASS_HASHCODE(G3D::PrimitiveType)
G3D_DECLARE_ENUM_CLASS_HASHCODE(G3D::RefractionQuality)
G3D_DECLARE_ENUM_CLASS_HASHCODE(G3D::MirrorQuality)

#endif

