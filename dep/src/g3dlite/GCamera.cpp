/**
  @file GCamera.cpp

  @author Morgan McGuire, http://graphics.cs.williams.edu
  @author Jeff Marsceill, 08jcm@williams.edu
 
  @created 2005-07-20
  @edited  2009-11-24
*/
#include "G3D/GCamera.h"
#include "G3D/platform.h"
#include "G3D/Rect2D.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/Ray.h"
#include "G3D/Matrix4.h"
#include "G3D/Any.h"
#include "G3D/stringutils.h"

namespace G3D {

GCamera::GCamera(const Any& any) {
    any.verifyName("GCamera");
    any.verifyType(Any::TABLE);
    *this = GCamera();

    const Any::AnyTable& table = any.table();
    Any::AnyTable::Iterator it = table.begin();
    while (it.hasMore()) {
        const std::string& k = toUpper(it->key);
        if (k == "FOVDIRECTION") {
            const std::string& v = toUpper(it->value);
            if (v == "HORIZONTAL") {
                m_direction = HORIZONTAL;
            } else if (v == "VERTICAL") {
                m_direction = VERTICAL;
            } else {
                any.verify(false, "fovDirection must be \"HORIZONTAL\" or \"VERTICAL\"");
            }
        } else if (k == "COORDINATEFRAME") {
            m_cframe = it->value;
        } else if (k == "FOVDEGREES") {
            m_fieldOfView = toRadians(it->value.number());
        } else if (k == "NEARPLANEZ") {
            m_nearPlaneZ = it->value;
        } else if (k == "FARPLANEZ") {
            m_farPlaneZ = it->value;
        } else {
            any.verify(false, std::string("Illegal key in table: ") + it->key);
        }
        ++it;
    }
}


GCamera::operator Any() const {
    Any any(Any::TABLE, "GCamera");

    any.set("fovDirection", std::string((m_direction == HORIZONTAL) ? "HORIZONTAL" : "VERTICAL"));
    any.set("fovDegrees", toDegrees(m_fieldOfView));
    any.set("nearPlaneZ", nearPlaneZ());
    any.set("farPlaneZ", farPlaneZ());
    any.set("coordinateFrame", coordinateFrame());

    return any;
}


GCamera::GCamera() {
    setNearPlaneZ(-0.2f);
    setFarPlaneZ(-100.0f);
    setFieldOfView((float)toRadians(90.0f), HORIZONTAL);
}


GCamera::GCamera(const Matrix4& proj, const CFrame& frame) {
    float left, right, bottom, top, nearval, farval;
    proj.getPerspectiveProjectionParameters(left, right, bottom, top, nearval, farval);
    setNearPlaneZ(-nearval);
    setFarPlaneZ(-farval);
    float x = right;

    // Assume horizontal field of view
    setFieldOfView(atan2(x, -m_nearPlaneZ) * 2.0f, HORIZONTAL);
    setCoordinateFrame(frame);
}


GCamera::~GCamera() {
}


void GCamera::getCoordinateFrame(CoordinateFrame& c) const {
    c = m_cframe;
}


void GCamera::setCoordinateFrame(const CoordinateFrame& c) {
    m_cframe = c;
}


void GCamera::setFieldOfView(float angle, FOVDirection dir) {
    debugAssert((angle < pi()) && (angle > 0));
    
    m_fieldOfView = angle;
    m_direction = dir;
}

 
float GCamera::imagePlaneDepth() const{
    return -m_nearPlaneZ;
}

float GCamera::viewportWidth(const Rect2D& viewport) const {
    // Compute the side of a square at the near plane based on our field of view
    float s = 2.0f * -m_nearPlaneZ * tan(m_fieldOfView * 0.5f);

    if (m_direction == VERTICAL) {
        s *= viewport.width() / viewport.height();
    }

    return s;
}


float GCamera::viewportHeight(const Rect2D& viewport) const {
    // Compute the side of a square at the near plane based on our field of view
    float s = 2.0f * -m_nearPlaneZ * tan(m_fieldOfView * 0.5f);

    debugAssert(m_fieldOfView < toRadians(180));
    if (m_direction == HORIZONTAL) {
        s *= viewport.height() / viewport.width();
    }

    return s;
}


Ray GCamera::worldRay(float x, float y, const Rect2D& viewport) const {

    int screenWidth  = iFloor(viewport.width());
    int screenHeight = iFloor(viewport.height());

    Vector3 origin = m_cframe.translation;

    float cx = screenWidth  / 2.0f;
    float cy = screenHeight / 2.0f;

    float vw = viewportWidth(viewport);
    float vh = viewportHeight(viewport);

	Vector3 direction = Vector3( (x - cx) * vw / screenWidth,
                            -(y - cy) * vh / screenHeight,
                             m_nearPlaneZ);

    direction = m_cframe.vectorToWorldSpace(direction);

    // Normalize the direction (we didn't do it before)
    direction = direction.direction();

    return Ray::fromOriginAndDirection(origin, direction);
}


void GCamera::getProjectPixelMatrix(const Rect2D& viewport, Matrix4& P) const {
    getProjectUnitMatrix(viewport, P);
    float screenWidth  = viewport.width();
    float screenHeight = viewport.height();

    float sx = screenWidth / 2.0;
    float sy = screenHeight / 2.0;

    P = Matrix4(sx, 0, 0, sx + viewport.x0(),
                0, -sy, 0, sy + viewport.y0(),
                0, 0,  1, 0,
                0, 0,  0, 1) * P;
}


void GCamera::getProjectUnitMatrix(const Rect2D& viewport, Matrix4& P) const {

    float screenWidth  = viewport.width();
    float screenHeight = viewport.height();

    float r, l, t, b, n, f, x, y;

    if (m_direction == VERTICAL) {
        y = -m_nearPlaneZ * tan(m_fieldOfView / 2);
        x = y * (screenWidth / screenHeight);
    } else { //m_direction == HORIZONTAL
        x = -m_nearPlaneZ * tan(m_fieldOfView / 2);
        y = x * (screenHeight / screenWidth);
    }

    n = -m_nearPlaneZ;
    f = -m_farPlaneZ;
    r = x;
    l = -x;
    t = y;
    b = -y;

    P = Matrix4::perspectiveProjection(l, r, b, t, n, f);
}

Vector3 GCamera::projectUnit(const Vector3& point, const Rect2D& viewport) const {
    Matrix4 M;
    getProjectUnitMatrix(viewport, M);

    Vector4 cameraSpacePoint(coordinateFrame().pointToObjectSpace(point), 1.0f);
    const Vector4& screenSpacePoint = M * cameraSpacePoint;

    return Vector3(screenSpacePoint.xyz() / screenSpacePoint.w);
}

Vector3 GCamera::project(const Vector3& point,
                          const Rect2D&  viewport) const {

    // Find the point in the homogeneous cube
    const Vector3& cube = projectUnit(point, viewport);

    return convertFromUnitToNormal(cube, viewport);
}

Vector3 GCamera::unprojectUnit(const Vector3& v, const Rect2D& viewport) const {

    const Vector3& projectedPoint = convertFromUnitToNormal(v, viewport);

    return unproject(projectedPoint, viewport);
}


Vector3 GCamera::unproject(const Vector3& v, const Rect2D& viewport) const {
    
    const float n = m_nearPlaneZ;
    const float f = m_farPlaneZ;

    float z;

    if (-f >= finf()) {
        // Infinite far plane
        z = 1.0f / (((-1.0f / n) * v.z) + 1.0f / n);
    } else {
        z = 1.0f / ((((1.0f / f) - (1.0f / n)) * v.z) + 1.0f / n);
    }

    const Ray& ray = worldRay(v.x, v.y, viewport);

    // Find out where the ray reaches the specified depth.
    const Vector3& out = ray.origin() + ray.direction() * -z / (ray.direction().dot(m_cframe.lookVector()));

    return out;
}


float GCamera::worldToScreenSpaceArea(float area, float z, const Rect2D& viewport) const {
    (void)viewport;
    if (z >= 0) {
        return finf();
    }
    return area * (float)square(imagePlaneDepth() / z);
}


void GCamera::getClipPlanes(
    const Rect2D&       viewport,
    Array<Plane>&       clip) const {

    Frustum fr;
    frustum(viewport, fr);
    clip.resize(fr.faceArray.size(), DONT_SHRINK_UNDERLYING_ARRAY);
    for (int f = 0; f < clip.size(); ++f) {
        clip[f] = fr.faceArray[f].plane;
    }
}
 

GCamera::Frustum GCamera::frustum(const Rect2D& viewport) const {
    Frustum f;
    frustum(viewport, f);
    return f;
}


void GCamera::frustum(const Rect2D& viewport, Frustum& fr) const {

    // The volume is the convex hull of the vertices definining the view
    // frustum and the light source point at infinity.

    const float x               = viewportWidth(viewport) / 2;
    const float y               = viewportHeight(viewport) / 2;
    const float zn              = m_nearPlaneZ;
    const float zf              = m_farPlaneZ;
    float xx, zz, yy;

    float halfFOV = m_fieldOfView * 0.5f;

    // This computes the normal, which is based on the complement of the 
    // halfFOV angle, so the equations are "backwards"
    if (m_direction == VERTICAL) {
        yy = -cosf(halfFOV);
        xx = yy * viewport.height() / viewport.width();
        zz = -sinf(halfFOV);
    } else {
        xx = -cosf(halfFOV);
        yy = xx * viewport.width() / viewport.height();
        zz = -sinf(halfFOV);
    } 

    // Near face (ccw from UR)
    fr.vertexPos.append(
        Vector4( x,  y, zn, 1),
        Vector4(-x,  y, zn, 1),
        Vector4(-x, -y, zn, 1),
        Vector4( x, -y, zn, 1));

    // Far face (ccw from UR, from origin)
    if (m_farPlaneZ == -finf()) {
        fr.vertexPos.append(Vector4( x,  y, zn, 0),
                            Vector4(-x,  y, zn, 0),
                            Vector4(-x, -y, zn, 0),
                            Vector4( x, -y, zn, 0));
    } else {
        // Finite
        const float s = zf / zn;
        fr.vertexPos.append(Vector4( x * s,  y * s, zf, 1),
                            Vector4(-x * s,  y * s, zf, 1),
                            Vector4(-x * s, -y * s, zf, 1),
                            Vector4( x * s, -y * s, zf, 1));
    }

    Frustum::Face face;

    // Near plane (wind backwards so normal faces into frustum)
    // Recall that nearPlane, farPlane are positive numbers, so
    // we need to negate them to produce actual z values.
    face.plane = Plane(Vector3(0,0,-1), Vector3(0,0,m_nearPlaneZ));
    face.vertexIndex[0] = 3;
    face.vertexIndex[1] = 2;
    face.vertexIndex[2] = 1;
    face.vertexIndex[3] = 0;
    fr.faceArray.append(face);

    // Right plane
    face.plane = Plane(Vector3(xx, 0, zz), Vector3::zero());
    face.vertexIndex[0] = 0;
    face.vertexIndex[1] = 4;
    face.vertexIndex[2] = 7;
    face.vertexIndex[3] = 3;
    fr.faceArray.append(face);

    // Left plane
    face.plane = Plane(Vector3(-fr.faceArray.last().plane.normal().x, 0, fr.faceArray.last().plane.normal().z), Vector3::zero());
    face.vertexIndex[0] = 5;
    face.vertexIndex[1] = 1;
    face.vertexIndex[2] = 2;
    face.vertexIndex[3] = 6;
    fr.faceArray.append(face);

    // Top plane
    face.plane = Plane(Vector3(0, yy, zz), Vector3::zero());
    face.vertexIndex[0] = 1;
    face.vertexIndex[1] = 5;
    face.vertexIndex[2] = 4;
    face.vertexIndex[3] = 0;
    fr.faceArray.append(face);

    // Bottom plane
    face.plane = Plane(Vector3(0, -fr.faceArray.last().plane.normal().y, fr.faceArray.last().plane.normal().z), Vector3::zero());
    face.vertexIndex[0] = 2;
    face.vertexIndex[1] = 3;
    face.vertexIndex[2] = 7;
    face.vertexIndex[3] = 6;
    fr.faceArray.append(face);

    // Far plane
    if (-m_farPlaneZ < finf()) {
    	face.plane = Plane(Vector3(0, 0, 1), Vector3(0, 0, m_farPlaneZ));
        face.vertexIndex[0] = 4;
        face.vertexIndex[1] = 5;
        face.vertexIndex[2] = 6;
        face.vertexIndex[3] = 7;
        fr.faceArray.append(face);
    }

    // Transform vertices to world space
    for (int v = 0; v < fr.vertexPos.size(); ++v) {
        fr.vertexPos[v] = m_cframe.toWorldSpace(fr.vertexPos[v]);
    }

    // Transform planes to world space
    for (int p = 0; p < fr.faceArray.size(); ++p) {
        // Since there is no scale factor, we don't have to 
        // worry about the inverse transpose of the normal.
        Vector3 normal;
        float d;
        
        fr.faceArray[p].plane.getEquation(normal, d);
        
        Vector3 newNormal = m_cframe.rotation * normal;
        
        if (isFinite(d)) {
            d = (newNormal * -d + m_cframe.translation).dot(newNormal);
            fr.faceArray[p].plane = Plane(newNormal, newNormal * d);
        } else {
            // When d is infinite, we can't multiply 0's by it without
            // generating NaNs.
            fr.faceArray[p].plane = Plane::fromEquation(newNormal.x, newNormal.y, newNormal.z, d);
        }
    }
}

void GCamera::getNearViewportCorners
(const Rect2D& viewport,
 Vector3&      outUR,
 Vector3&      outUL,
 Vector3&      outLL,
 Vector3&      outLR) const {
    
    // Must be kept in sync with getFrustum()
    const float w  = viewportWidth(viewport) / 2.0f;
    const float h  = viewportHeight(viewport) / 2.0f;
    const float z  = nearPlaneZ();

    // Compute the points
    outUR = Vector3( w,  h, z);
    outUL = Vector3(-w,  h, z);
    outLL = Vector3(-w, -h, z);
    outLR = Vector3( w, -h, z);

    // Take to world space
    outUR = m_cframe.pointToWorldSpace(outUR);
    outUL = m_cframe.pointToWorldSpace(outUL);
    outLR = m_cframe.pointToWorldSpace(outLR);
    outLL = m_cframe.pointToWorldSpace(outLL);
}

void GCamera::getFarViewportCorners(
    const Rect2D& viewport,
    Vector3& outUR,
    Vector3& outUL,
    Vector3& outLL,
    Vector3& outLR) const {

    // Must be kept in sync with getFrustum()
    const float w = viewportWidth(viewport) * m_farPlaneZ / m_nearPlaneZ;
    const float h = viewportHeight(viewport) * m_farPlaneZ / m_nearPlaneZ;
    const float z = m_farPlaneZ;
    
    // Compute the points
    outUR = Vector3( w/2,  h/2, z);
    outUL = Vector3(-w/2,  h/2, z);
    outLL = Vector3(-w/2, -h/2, z);
    outLR = Vector3( w/2, -h/2, z);

    // Take to world space
    outUR = m_cframe.pointToWorldSpace(outUR);
    outUL = m_cframe.pointToWorldSpace(outUL);
    outLR = m_cframe.pointToWorldSpace(outLR);
    outLL = m_cframe.pointToWorldSpace(outLL);
}



void GCamera::setPosition(const Vector3& t) { 
    m_cframe.translation = t;
}


void GCamera::lookAt(const Vector3& position, const Vector3& up) { 
    m_cframe.lookAt(position, up);
}


void GCamera::serialize(BinaryOutput& bo) const {
    bo.writeFloat32(m_fieldOfView);
    bo.writeFloat32(imagePlaneDepth());
    debugAssert(nearPlaneZ() < 0.0f);
    bo.writeFloat32(nearPlaneZ());
    debugAssert(farPlaneZ() < 0.0f);
    bo.writeFloat32(farPlaneZ());
    m_cframe.serialize(bo);
    bo.writeInt8(m_direction);
}


void GCamera::deserialize(BinaryInput& bi) {
    m_fieldOfView = bi.readFloat32();
    m_nearPlaneZ = bi.readFloat32();
    debugAssert(m_nearPlaneZ < 0.0f);
    m_farPlaneZ = bi.readFloat32();
    debugAssert(m_farPlaneZ < 0.0f);
    m_cframe.deserialize(bi);
    m_direction = (FOVDirection)bi.readInt8();
}


Vector3 GCamera::convertFromUnitToNormal(const Vector3& in, const Rect2D& viewport) const{
    return (in + Vector3(1,1,1)) * 0.5 * Vector3(viewport.width(), -viewport.height(), 1) + 
           Vector3(viewport.x0(), viewport.y1(), 0);
}
} // namespace
