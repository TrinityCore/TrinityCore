/**
  @file GLight.cpp

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu

  @created 2003-11-12
  @edited  2009-11-16
*/
#include "G3D/GLight.h"
#include "G3D/Sphere.h"
#include "G3D/CoordinateFrame.h"
#include "G3D/Any.h"
#include "G3D/stringutils.h"

namespace G3D {

GLight::GLight(const Any& any) {
    any.verifyName("GLight");

    if (any.type() == Any::TABLE) {
        *this = GLight();
        for (Any::AnyTable::Iterator it = any.table().begin(); it.hasMore(); ++it) {
            const std::string& key = toLower(it->key);
            if (key == "position") {
                position = it->value;
            } else if (key == "rightdirection") {
                rightDirection = it->value;
            } else if (key == "spotdirection") {
                spotDirection = it->value;
            } else if (key == "spotcutoff") {
                spotCutoff = it->value.number();
            } else if (key == "spotsquare") {
                spotSquare = it->value.boolean();
            } else if (key == "attenuation") {
                attenuation[0] = it->value[0].number();
                attenuation[1] = it->value[1].number();
                attenuation[2] = it->value[2].number();
            } else if (key == "color") {
                color = it->value;
            } else if (key == "enabled") {
                enabled = it->value.boolean();
            } else if (key == "specular") {
                specular = it->value.boolean();
            } else if (key == "diffuse") {
                diffuse = it->value.boolean();
            } else {
                any.verify(false, "Illegal key: " + it->key);
            }
        }
    } else if (toLower(any.name()) == "glight::directional") {

        *this = directional(any[0], any[1], 
            (any.size() > 2) ? any[2] : Any(true), 
            (any.size() > 3) ? any[3] : Any(true));

    } else if (toLower(any.name()) == "glight::point") {

        *this = point(any[0], any[1], 
            (any.size() > 2) ? any[2] : Any(1), 
            (any.size() > 3) ? any[3] : Any(0), 
            (any.size() > 4) ? any[4] : Any(0.5f), 
            (any.size() > 5) ? any[5] : Any(true), 
            (any.size() > 6) ? any[6] : Any(true));

    } else if (toLower(any.name()) == "glight::spot") {

        *this = spot(any[0], any[1], any[2], any[3],
            (any.size() > 4) ? any[4] : Any(1), 
            (any.size() > 5) ? any[5] : Any(0), 
            (any.size() > 6) ? any[6] : Any(0.5f), 
            (any.size() > 7) ? any[5] : Any(true), 
            (any.size() > 8) ? any[6] : Any(true));
    } else {
        any.verify(false, "Unrecognized name");
    }
}


GLight::operator Any() const {
    Any a(Any::TABLE, "GLight");
    a.set("position", position.operator Any());
    a.set("rightDirection", rightDirection.operator Any());
    a.set("spotDirection", spotDirection.operator Any());
    a.set("spotCutoff", spotCutoff);
    a.set("spotSquare", spotSquare);

    Any att(Any::ARRAY);
    att.append(attenuation[0], attenuation[1], attenuation[2]);
    a.set("attenuation", att);
    a.set("color", color.operator Any());
    a.set("enabled", enabled);
    a.set("specular", specular);
    a.set("diffuse", diffuse);
    return a;
}


GLight::GLight() :
    position(0, 0, 0, 0),
    rightDirection(0,0,0),
    spotDirection(0, 0, -1),
    spotCutoff(180),
    spotSquare(false),
    color(Color3::white()),
    enabled(false),
    specular(true),
    diffuse(true) {

    attenuation[0]  = 1.0;
    attenuation[1]  = 0.0;
    attenuation[2]  = 0.0;
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
        (rightDirection == other.rightDirection) &&
        (spotDirection == other.spotDirection) &&
        (spotCutoff == other.spotCutoff) &&
        (spotSquare == other.spotSquare) &&
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
        return Sphere(Vector3::zero(), finf());
    } else {
        // Avoid divide by zero
        cutoff = max(cutoff, 0.00001f);
        float maxIntensity = max(color.r, max(color.g, color.b));

        float radius = finf();
            
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


CoordinateFrame GLight::frame() const {
    CoordinateFrame f;
    if (rightDirection == Vector3::zero()) {
        // No specified right direction; choose one automatically
        if (position.w == 0) {
            // Directional light
            f.lookAt(-position.xyz());
        } else {
            // Spot light
            f.lookAt(spotDirection);
        }
    } else {
        const Vector3& Z = -spotDirection.direction();
        Vector3 X = rightDirection.direction();

        // Ensure the vectors are not too close together
        while (abs(X.dot(Z)) > 0.9f) {
            X = Vector3::random();
        }

        // Ensure perpendicular
        X -= Z * Z.dot(X);
        const Vector3& Y = Z.cross(X);

        f.rotation.setColumn(Vector3::X_AXIS, X);
        f.rotation.setColumn(Vector3::Y_AXIS, Y);
        f.rotation.setColumn(Vector3::Z_AXIS, Z);
    }
    f.translation = position.xyz();

    return f;
}


} // G3D
