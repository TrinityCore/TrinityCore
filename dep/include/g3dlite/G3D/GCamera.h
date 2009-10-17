/**
  @file GCamera.h

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2001-06-02
  @edited  2006-02-11
*/

#ifndef G3D_GCAMERA_H
#define G3D_GCAMERA_H

#include "G3D/platform.h"
#include "G3D/CoordinateFrame.h"
#include "G3D/Vector3.h"
#include "G3D/Plane.h"

namespace G3D {

/**
  There is a viewport of width x height size in world space that corresponds to
  a screenWidth x screenHeight pixel grid on a
  renderDevice->getWidth() x renderDevice->getHeight()
  window.

  All viewport arguments are the pixel bounds of the viewport-- e.g.,
  RenderDevice::getViewport().
 */
class GCamera  {
private:

    /**
    Vertical field of view (in radians)
    */
    float                       fieldOfView;

    /**
     The image plane depth corresponding to a vertical field of
     view, where the film size is 1x1.
     */
    float                       imagePlaneDepth;

    /**
     Clipping plane, *not* imaging plane.  Positive numbers.
     */
    float                       nearPlane;

    /**
     Positive
     */
    float                       farPlane;

    CoordinateFrame             cframe;

public:

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

    virtual ~GCamera();

    CoordinateFrame getCoordinateFrame() const;
    void getCoordinateFrame(CoordinateFrame& c) const;
    void setCoordinateFrame(const CoordinateFrame& c);

   /**
     Sets the horizontal field of view, in radians.  The
     initial angle is toRadians(55).
     <UL>
      <LI> toRadians(50) - Telephoto
      <LI> toRadians(110) - Normal
      <LI> toRadians(140) - Wide angle
     </UL>
    */
    void setFieldOfView(float angle);

    /**
    Sets the field of view based on a desired image plane depth
    (<I>s'</I>) and film dimensions in world space.  Depth must be positive.  Width,
    depth, and height are measured in the same units (meters are
    recommended).  The field of view will span the diagonal to the
    image.<P> <I>Note</I>: to simulate a 35mm GCamera, set width =
    0.36 mm and height = 0.24 mm.  The width and height used are
    generally not the pixel dimensions of the image.
    */
    void setImagePlaneDepth(
        float                                   depth,
        const class Rect2D&                     viewport);

    inline double getFieldOfView() const {
        return fieldOfView;
    }

    /**
     Projects a world space point onto a width x height screen.  The
     returned coordinate uses pixmap addressing: x = right and y =
     down.  The resulting z value is <I>rhw</I>.

     If the point is behind the camera, Vector3::inf() is returned.
     */
    G3D::Vector3 project(
        const G3D::Vector3&                     point,
        const class Rect2D&                     viewport) const;

    /**
     Returns the pixel area covered by a shape of the given
     world space area at the given z value (z must be negative).
     */
    float worldToScreenSpaceArea(float area, float z, const class Rect2D& viewport) const;

    /**
     Returns the world space 3D viewport corners.  These
     are at the near clipping plane.  The corners are constructed
     from the nearPlaneZ, getViewportWidth, and getViewportHeight.
     "left" and "right" are from the GCamera's perspective.
     */
    void get3DViewportCorners(
        const class Rect2D&                     viewport,
        Vector3&                                outUR,
        Vector3&                                outUL,
        Vector3&                                outLL,
        Vector3&                                outLR) const;

    /**
     Returns the image plane depth, <I>s'</I>, given the current field
     of view for film of dimensions width x height.  See
     setImagePlaneDepth for a discussion of worldspace values width and height.
    */
    float getImagePlaneDepth(
        const class Rect2D&                     viewport) const;

    /**
      Returns the world space ray passing through the center of pixel
      (x, y) on the image plane.  The pixel x and y axes are opposite
      the 3D object space axes: (0,0) is the upper left corner of the screen.
      They are in viewport coordinates, not screen coordinates.

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
    inline float getNearPlaneZ() const {
        return -nearPlane;
    }

    /**
     Returns a negative z-value.
     */
    inline float getFarPlaneZ() const {
        return -farPlane;
    }

    inline void setFarPlaneZ(float z) {
        debugAssert(z < 0);
        farPlane = -z;
    }

    inline void setNearPlaneZ(float z) {
        debugAssert(z < 0);
        nearPlane = -z;
    }

    /**
     Returns the GCamera space width of the viewport.
     */
    float getViewportWidth(
        const class Rect2D&                     viewport) const;

    /**
     Returns the GCamera space height of the viewport.
     */
    float getViewportHeight(
        const class Rect2D&                     viewport) const;

    /**
     Read back a GCamera space z-value at pixel (x, y) from the depth buffer.
    double getZValue(
        double          x,
        double          y,
        const class Rect2D&                     viewport,
        double          polygonOffset = 0) const;
     */

    void setPosition(const Vector3& t);

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
   void getClipPlanes(
       const Rect2D& viewport,
       Array<Plane>& outClip) const;

   /**
    Returns the world space view frustum, which is a truncated pyramid describing
    the volume of space seen by this camera.
    */
   void getFrustum(const Rect2D& viewport, GCamera::Frustum& f) const;

   GCamera::Frustum frustum(const Rect2D& viewport) const;

};

} // namespace G3D

#endif

