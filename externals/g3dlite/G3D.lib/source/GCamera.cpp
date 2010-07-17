/**
  @file GCamera.cpp

  @author Morgan McGuire, matrix@graphics3d.com
  @author Jeff Marsceill, 08jcm@williams.edu
 
  @created 2005-07-20
  @edited  2007-07-24
*/
#include "G3D/GCamera.h"
#include "G3D/platform.h"
#include "G3D/Rect2D.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/Ray.h"
#include "G3D/Matrix4.h"

namespace G3D {

GCamera::GCamera() {
    setNearPlaneZ(-0.1f);
    setFarPlaneZ(-(float)inf());
    setFieldOfView((float)toRadians(55.0f), VERTICAL);
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

    if (m_direction == HORIZONTAL) {
        s *= viewport.height() / viewport.width();
    }

    return s;
}

Ray GCamera::worldRay(float x, float y, const Rect2D& viewport) const {

    int screenWidth  = iFloor(viewport.width());
    int screenHeight = iFloor(viewport.height());

    Ray out;
    out.origin = m_cframe.translation;

    float cx = screenWidth  / 2.0f;
    float cy = screenHeight / 2.0f;

    out.direction = Vector3( (x - cx) * viewportWidth(viewport)  / screenWidth,
                            -(y - cy) * viewportHeight(viewport) / screenHeight,
                             (m_nearPlaneZ) );

    out.direction = m_cframe.vectorToWorldSpace(out.direction);

    // Normalize the direction (we didn't do it before)
    out.direction = out.direction.direction();

    return out;
}

/** 
This is the matrix that a RenderDevice (or OpenGL) uses as the projection matrix.
@sa RenderDevice::setProjectionAndCameraMatrix, RenderDevice::setProjectionMatrix, Matrix4::perspectiveProjection
*/
void GCamera::getProjectUnitMatrix(const Rect2D& viewport, Matrix4& P) const{

    float screenWidth  = viewport.width();
    float screenHeight = viewport.height();

    float r, l, t, b, n, f, x, y;

    if(m_direction == VERTICAL){
        y = -m_nearPlaneZ * tan(m_fieldOfView / 2);
        x = y * (screenWidth / screenHeight);
    }
    else{ //m_direction == HORIZONTAL
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

    if (-f >= inf()) {
        // Infinite far plane
        z = 1.0f / (((-1.0f / n) * v.z) + 1.0f / n);
    } else {
        z = 1.0f / ((((1.0f / f) - (1.0f / n)) * v.z) + 1.0f / n);
    }

    const Ray& ray = worldRay(v.x, v.y, viewport);

    // Find out where the ray reaches the specified depth.
    const Vector3& out = ray.origin + ray.direction * -z / (ray.direction.dot(m_cframe.lookVector()));

    return out;
}

float GCamera::worldToScreenSpaceArea(float area, float z, const Rect2D& viewport) const {
    if (z >= 0) {
        return (float)inf();
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
    const float z               = m_nearPlaneZ;
    const float w               = z / -m_farPlaneZ;
    float fovx;

    fovx = m_fieldOfView;
    if (m_direction == VERTICAL) {
        fovx *= x / y;
    } 

    // Near face (ccw from UR)
    fr.vertexPos.append(
        Vector4( x,  y, z, 1),
        Vector4(-x,  y, z, 1),
        Vector4(-x, -y, z, 1),
        Vector4( x, -y, z, 1));

    // Far face (ccw from UR, from origin)
    fr.vertexPos.append(
        Vector4( x,  y, z, w),
        Vector4(-x,  y, z, w),
        Vector4(-x, -y, z, w),
        Vector4( x, -y, z, w));

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
    face.plane = Plane(Vector3(-cosf(fovx/2), 0, -sinf(fovx/2)), Vector3::zero());
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
    face.plane = Plane(Vector3(0, -cosf(m_fieldOfView/2.0f), -sinf(m_fieldOfView/2.0f)), Vector3::zero());
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
    if (-m_farPlaneZ < inf()) {
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

void GCamera::getNearViewportCorners(
    const Rect2D& viewport,
    Vector3& outUR,
    Vector3& outUL,
    Vector3& outLL,
    Vector3& outLR) const {

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
