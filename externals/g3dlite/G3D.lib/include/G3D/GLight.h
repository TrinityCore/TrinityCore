/**
  @file GLight.h

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2003-11-12
  @edited  2006-02-08
*/

#ifndef G3D_GLIGHT_H
#define G3D_GLIGHT_H

#include "G3D/platform.h"
#include "G3D/Vector4.h"
#include "G3D/Vector3.h"
#include "G3D/Color4.h"

namespace G3D {

/**
 A light representation that closely follows the OpenGL light format.
 */
class GLight  {
public:
    /** World space position (for a directional light, w = 0 */
    Vector4             position;

    /** Direction in which the light faces, if a spot light.  This is the "look vector" of the light source. */
    Vector3             spotDirection;

    /** In <B>degrees</B>.  180 = no cutoff (point/dir) >90 = spot light */
    float               spotCutoff;

    /** Constant, linear, quadratic */
    float               attenuation[3];

    /** May be outside the range [0, 1] */
    Color3              color;

    /** If false, this light is ignored */
    bool                enabled;

    /** If false, this light does not create specular highlights (useful when using negative lights). */
    bool                specular;

    /** If false, this light does not create diffuse illumination (useful when rendering a specular-only pass). */
    bool                diffuse;

    GLight();

    /** @param toLight will be normalized */
    static GLight directional(const Vector3& toLight, const Color3& color, bool specular = true, bool diffuse = true);

    static GLight point(const Vector3& pos, const Color3& color, float constAtt = 1, float linAtt = 0, float quadAtt = 0.5f, bool specular = true, bool diffuse = true);

    /** @param pointDirection Will be normalized.  Points in the direction that light propagates.
        @param cutOffAngleDegrees Must be on the range [0, 90]. This is the angle from the point direction
        to the edge of the light cone.
    */
    static GLight spot(const Vector3& pos, const Vector3& pointDirection, float cutOffAngleDegrees, const Color3& color, float constAtt = 1, float linAtt = 0, float quadAtt = 0, bool specular = true, bool diffuse = true);

    /** Returns the sphere within which this light has some noticable effect.  May be infinite.
        @param cutoff The value at which the light intensity is considered negligible. */
    class Sphere effectSphere(float cutoff = 30.0f / 255) const;

    bool operator==(const GLight& other) const;
    bool operator!=(const GLight& other) const;
};

} // namespace
#endif

