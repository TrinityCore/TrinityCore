/**
  @file GLight.cpp

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2003-11-12
  @edited  2007-10-22
*/

#include "G3D/GLight.h"
#include "G3D/Sphere.h"

namespace G3D {

GLight::GLight() {
    position        = Vector4(0, 0, 0, 0);
    color           = Color3::white();
    spotDirection   = Vector3(0, 0, -1);
    spotCutoff      = 180;
    enabled         = false;
    attenuation[0]  = 1.0;
    attenuation[1]  = 0.0;
    attenuation[2]  = 0.0;
    specular        = true;
    diffuse         = true;
}


GLight GLight::directional(const Vector3& toLight, const Color3& color, bool s, bool d) {
    GLight L;
    L.position = Vector4(toLight.direction(), 0);
    L.color    = color;
    L.specular = s;
    L.diffuse  = d;
    return L;
}


GLight GLight::point(const Vector3& pos, const Color3& color, float constAtt, float linAtt, float quadAtt, bool s, bool d) {
    GLight L;
    L.position = Vector4(pos, 1);
    L.color    = color;
    L.attenuation[0] = constAtt;
    L.attenuation[1] = linAtt;
    L.attenuation[2] = quadAtt;
    L.specular       = s;
    L.diffuse        = d;
    return L;
}


GLight GLight::spot(const Vector3& pos, const Vector3& pointDirection, float cutOffAngleDegrees, const Color3& color, float constAtt, float linAtt, float quadAtt, bool s, bool d) {
    GLight L;
    L.position       = Vector4(pos, 1.0f);
    L.spotDirection  = pointDirection.direction();
    debugAssert(cutOffAngleDegrees <= 90);
    L.spotCutoff     = cutOffAngleDegrees;
    L.color          = color;
    L.attenuation[0] = constAtt;
    L.attenuation[1] = linAtt;
    L.attenuation[2] = quadAtt;
    L.specular       = s;
    L.diffuse        = d;
    return L;
}


bool GLight::operator==(const GLight& other) const {
    return (position == other.position) && 
        (spotDirection == other.spotDirection) &&
        (spotCutoff == other.spotCutoff) &&
        (attenuation[0] == other.attenuation[0]) &&
        (attenuation[1] == other.attenuation[1]) &&
        (attenuation[2] == other.attenuation[2]) &&
        (color == other.color) &&
        (enabled == other.enabled) &&
        (specular == other.specular) &&
        (diffuse == other.diffuse);
}

bool GLight::operator!=(const GLight& other) const {
    return !(*this == other);
}


Sphere GLight::effectSphere(float cutoff) const {
    if (position.w == 0) {
        // Directional light
        return Sphere(Vector3::zero(), (float)inf());
    } else {
        // Avoid divide by zero
        cutoff = max(cutoff, 0.0001f);
        float maxIntensity = max(color.r, max(color.g, color.b));

        float radius = (float)inf();
            
        if (attenuation[2] != 0) {

            // Solve I / attenuation.dot(1, r, r^2) < cutoff for r
            //
            //  a[0] + a[1] r + a[2] r^2 > I/cutoff
            //
            
            float a = attenuation[2];
            float b = attenuation[1];
            float c = attenuation[0] - maxIntensity / cutoff;
            
            float discrim = square(b) - 4 * a * c;
            
            if (discrim >= 0) {
                discrim = sqrt(discrim);
                
                float r1 = (-b + discrim) / (2 * a);
                float r2 = (-b - discrim) / (2 * a);

                if (r1 < 0) {
                    if (r2 > 0) {
                        radius = r2;
                    }
                } else if (r2 > 0) {
                    radius = min(r1, r2);
                } else {
                    radius = r1;
                }
            }
                
        } else if (attenuation[1] != 0) {
            
            // Solve I / attenuation.dot(1, r) < cutoff for r
            //
            // r * a[1] + a[0] = I / cutoff
            // r = (I / cutoff - a[0]) / a[1]

            float radius = (maxIntensity / cutoff - attenuation[0]) / attenuation[1];
            radius = max(radius, 0.0f);
        }

        return Sphere(position.xyz(), radius);

    }
}

}
