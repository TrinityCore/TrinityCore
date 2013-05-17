/**
  @file GCamera.h

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu

  @created 2005-07-20
  @edited  2009-04-20
*/

#ifndef G3D_GCamera_H
#define G3D_GCamera_H

#include "G3D/platform.h"
#include "G3D/CoordinateFrame.h"
#include "G3D/Vector3.h"
#include "G3D/Plane.h"
#include "G3D/debugAssert.h"

namespace G3D {

class Matrix4;
class Rect2D;
class Any;

/**
  Abstraction of a pinhole camera.

  The area a camera sees is called a frustum.  It is bounded by the
  near plane, the far plane, and the sides of the view frame projected
  into the scene.  It has the shape of a pyramid with the top cut off.

  Cameras can project points from 3D to 2D.  The "unit" projection
  matches OpenGL.  It maps the entire view frustum to a cube of unit
  radius (i.e., edges of length 2) centered at the origin.  The
  non-unit projection then maps that cube to the specified pixel
  viewport in X and Y and the range [0, 1] in Z.  The projection is
  reversable as long as the projected Z value is known.

  All viewport arguments are the pixel bounds of the viewport-- e.g.,
  RenderDevice::viewport().

  See http://bittermanandy.wordpress.com/2009/04/10/a-view-to-a-thrill-part-one-camera-concepts/
  for a nice introduction to camera transformations.
 */
class GCamera  {

public:
    /**
    Stores the direction of the field of view
    */
    enum FOVDirection {HORIZONTAL, VERTICAL};

private:
    
    /** Full field of view (in radians) */
    float                       m_fieldOfView;

    /** Clipping plane, *not* imaging plane.  Negative numbers. */
    float                       m_nearPlaneZ;

    /** Negative */
    float                       m_farPlaneZ;

    /** Stores the camera's location and orientation */
    CoordinateFrame             m_cframe;

    /** Horizontal or Vertical */
    FOVDirection                m_direction;

    Vector2                     m_pixelOffset;

public:

    /** Must be of the format produced by the Any cast, e.g.,

        <pre>
        GCamera {
            coordinateFrame = CFrame::fromXYZYPRDegrees(-13.3f, 8.0f, -1.9f, 246.6f, -3),
            nearPlaneZ = -0.5,
            farPlaneZ = -50,
            fovDirection = "HORIZONTAL",
            fovAngleDegrees = 90
        }</pre>

        Missing fields are filled from the default GCamera constructor.
    */
    GCamera(const Any& any);

    operator Any() const;

    class Frustum {
    public:
        class Face {
        public:
            /** Counter clockwise indices into vertexPos */
            int             vertexIndex[4];

            /** The plane containing the face. */
            Plane           plane;
        };
        
        /** The vertices, in homogeneous space.  If w == 0,
            a vertex is at infinity. */
        Array<Vector4>      vertexPos;

        /** The faces in the frustum.  When the
            far plane is at infinity, there are 5 faces,
            otherwise there are 6.  The faces are in the order
            N,R,L,B,T,[F].
            */
        Array<Face>         faceArray;
    };

    GCamera();

    GCamera(const Matrix4& proj, const CFrame& frame);

    virtual ~GCamera();

    /** Returns the current coordinate frame */
    const CoordinateFrame& coordinateFrame() const {
        return m_cframe;
    }

    /** Displacement from the upper left added in pixels in screen
        space to the projection matrix.  This is useful for shifting
        the sampled location from the pixel center (OpenGL convention)
        to other locations, such as the upper-left.*/
    void setPixelOffset(const Vector2& p) {
        m_pixelOffset = p;
    }

    const Vector2& pixelOffset() const {
        return m_pixelOffset;
    }
    
    /** Sets c to the camera's coordinate frame */
    void getCoordinateFrame(CoordinateFrame& c) const;

    /** Sets a new coordinate frame for the camera */
    void setCoordinateFrame(const CoordinateFrame& c);
           
    /** Sets \a P equal to the camera's projection matrix. This is the
        matrix that maps points to the homogeneous clip cube that
        varies from -1 to 1 on all axes.  The projection matrix does
        not include the camera transform.

        This is the matrix that a RenderDevice (or OpenGL) uses as the projection matrix.
        @sa RenderDevice::setProjectionAndCameraMatrix, RenderDevice::setProjectionMatrix, Matrix4::perspectiveProjection
    */
    void getProjectUnitMatrix(const Rect2D& viewport, Matrix4& P) const;

    /** Sets \a P equal to the matrix that transforms points to pixel
        coordinates on the given viewport.  A point correspoinding to
        the top-left corner of the viewport in camera space will
        transform to viewport.x0y0() and the bottom-right to viewport.x1y1(). */
    void getProjectPixelMatrix(const Rect2D& viewport, Matrix4& P) const;

    /** Converts projected points from OpenGL standards
        (-1, 1) to normal 3D coordinate standards (0, 1) 

        \deprecated
    */ // TODO: Remove
    Vector3 convertFromUnitToNormal(const Vector3& in, const Rect2D& viewport) const;

    /**
       Sets the field of view, in radians.  The 
       initial angle is toRadians(55).  Must specify
       the direction of the angle.

       This is the full angle, i.e., from the left side of the
       viewport to the right side.
    */
    void setFieldOfView(float edgeToEdgeAngleRadians, FOVDirection direction);

    /** Returns the current full field of view angle (from the left side of the
       viewport to the right side) and direction */
    inline void getFieldOfView(float& angle, FOVDirection& direction) const {
        angle = m_fieldOfView;
        direction = m_direction;
    }

    /**
     Projects a world space point onto a width x height screen.  The
     returned coordinate uses pixmap addressing: x = right and y =
     down.  The resulting z value is 0 at the near plane, 1 at the far plane,
     and is a linear compression of unit cube projection.

     If the point is behind the camera, Vector3::inf() is returned.
     */
    Vector3 project(const G3D::Vector3& point,
                    const class Rect2D& viewport) const;

    /**
     Projects a world space point onto a unit cube.  The resulting
     x,y,z values range between -1 and 1, where z is -1
     at the near plane and 1 at the far plane and varies hyperbolically in between.

     If the point is behind the camera, Vector3::inf() is returned.
     */
    Vector3 projectUnit(const G3D::Vector3& point,
                        const class Rect2D& viewport) const;

    /**
       Gives the world-space coordinates of screen space point v, where
       v.x is in pixels from the left, v.y is in pixels from
       the top, and v.z is on the range 0 (near plane) to 1 (far plane).
     */
    Vector3 unproject(const Vector3& v, const Rect2D& viewport) const;

     /**
       Gives the world-space coordinates of unit cube point v, where
       v varies from -1 to 1 on all axes.  The unproject first
       transforms the point into a pixel location for the viewport, then calls unproject
     */
    Vector3 unprojectUnit(const Vector3& v, const Rect2D& viewport) const;

    /**
     Returns the pixel area covered by a shape of the given
     world space area at the given z value (z must be negative).
     */
    float worldToScreenSpaceArea(float area, float z, const class Rect2D& viewport) const;

    /**
     Returns the world space 3D viewport corners.  These
     are at the near clipping plane.  The corners are constructed
     from the nearPlaneZ, viewportWidth, and viewportHeight.
     "left" and "right" are from the GCamera's perspective.
     */
    void getNearViewportCorners(const class Rect2D& viewport,
                                Vector3& outUR, Vector3& outUL,
                                Vector3& outLL, Vector3& outLR) const;

    /**
     Returns the world space 3D viewport corners.  These
     are at the Far clipping plane.  The corners are constructed
     from the nearPlaneZ, farPlaneZ, viewportWidth, and viewportHeight.
     "left" and "right" are from the GCamera's perspective.
     */
    void getFarViewportCorners(const class Rect2D& viewport,
                               Vector3& outUR, Vector3& outUL,
                               Vector3& outLL, Vector3& outLR) const;

    /**
     Returns the image plane depth,  assumes imagePlane
     is the same as the near clipping plane.
     returns a positive number.
     */
    float imagePlaneDepth() const;

    /**
      Returns the world space ray passing through the center of pixel
      (x, y) on the image plane.  The pixel x and y axes are opposite
      the 3D object space axes: (0,0) is the upper left corner of the screen.
      They are in viewport coordinates, not screen coordinates.

      The ray origin is at the origin.  To start it at the image plane,
      move it forward by imagePlaneDepth/ray.direction.z

      Integer (x, y) values correspond to
      the upper left corners of pixels.  If you want to cast rays
      through pixel centers, add 0.5 to x and y.        
      */
    Ray worldRay(
        float                                  x,
        float                                  y,
        const class Rect2D&                     viewport) const;

    /**
      Returns a negative z-value.
     */
    inline float nearPlaneZ() const {
        return m_nearPlaneZ;
    }

    /**
     Returns a negative z-value.
     */
    inline float farPlaneZ() const {
        return m_farPlaneZ;
    }

    /**
     Sets a new value for the far clipping plane
     Expects a negative value
     */
    inline void setFarPlaneZ(float z) {
        debugAssert(z < 0);
        m_farPlaneZ = z;
    }
    
    /**
     Sets a new value for the near clipping plane
     Expects a negative value
     */
    inline void setNearPlaneZ(float z) {
        debugAssert(z < 0);
        m_nearPlaneZ = z;
    }

    /**
     Returns the camera space width of the viewport at the near plane.
     */
    float viewportWidth(const class Rect2D& viewport) const;

    /**
     Returns the camera space height of the viewport at the near plane.
     */
    float viewportHeight(const class Rect2D& viewport) const;

    void setPosition(const Vector3& t);

    /** Rotate the camera in place to look at the target.  Does not
        persistently look at that location when the camera moves;
        i.e., if you move the camera and still want it to look at the
        old target, you must call lookAt again after moving the
        camera.)*/
    void lookAt(const Vector3& position, const Vector3& up = Vector3::unitY());

    /**
       Returns the clipping planes of the frustum, in world space.  
       The planes have normals facing <B>into</B> the view frustum.
       
       The plane order is guaranteed to be:
       Near, Right, Left, Top, Bottom, [Far]
       
       If the far plane is at infinity, the resulting array will have 
       5 planes, otherwise there will be 6.
       
       The viewport is used only to determine the aspect ratio of the screen; the
       absolute dimensions and xy values don't matter.
    */
    void getClipPlanes
    (
     const Rect2D& viewport,
     Array<Plane>& outClip) const;

    /**
      Returns the world space view frustum, which is a truncated pyramid describing
      the volume of space seen by this camera.
    */
    void frustum(const Rect2D& viewport, GCamera::Frustum& f) const;

    GCamera::Frustum frustum(const Rect2D& viewport) const;
    
    /** Read and Write camera parameters */
    void serialize(class BinaryOutput& bo) const;
    void deserialize(class BinaryInput& bi);
   
};

} // namespace G3D

#endif
