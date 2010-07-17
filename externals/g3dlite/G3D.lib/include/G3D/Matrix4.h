/**
  @file Matrix4.h
 
  4x4 matrix class
 
  @maintainer Morgan McGuire, matrix@graphics3d.com
 
  @created 2003-10-02
  @edited  2007-04-05
 */

#ifndef G3D_MATRIX4_H
#define G3D_MATRIX4_H

#ifdef _MSC_VER
// Disable conditional expression is constant, which occurs incorrectly on inlined functions
#   pragma warning (push)
#   pragma warning( disable : 4127 )
#endif

#include "G3D/platform.h"
#include "G3D/debugAssert.h"
#include "G3D/Matrix3.h"
#include "G3D/Vector3.h"

namespace G3D {

/**
  A 4x4 matrix.

  See also G3D::CoordinateFrame, G3D::Matrix3, G3D::Quat
 */
class Matrix4 {
private:

    float elt[4][4];

    /**
      Computes the determinant of the 3x3 matrix that lacks excludeRow
      and excludeCol. 
    */
    float subDeterminant(int excludeRow, int excludeCol) const;

    // Hidden operators
    bool operator<(const Matrix4&) const;
    bool operator>(const Matrix4&) const;
    bool operator<=(const Matrix4&) const;
    bool operator>=(const Matrix4&) const;

public:
    Matrix4(
        float r1c1, float r1c2, float r1c3, float r1c4,
        float r2c1, float r2c2, float r2c3, float r2c4,
        float r3c1, float r3c2, float r3c3, float r3c4,
        float r4c1, float r4c2, float r4c3, float r4c4);

    /**
     init should be <B>row major</B>.
     */
    Matrix4(const float* init);
    
	/**
		a is the upper left 3x3 submatrix and b is the upper right 3x1 submatrix. The last row of the created matrix is (0,0,0,1).
	*/
    Matrix4(const class Matrix3& upper3x3, const class Vector3& lastCol = Vector3::zero());

    Matrix4(const class CoordinateFrame& c);

    Matrix4(const double* init);

    Matrix4();

    /** Produces an RT transformation that nearly matches this Matrix4.
        Because a Matrix4 may not be precisely a rotation and translation,
        this may introduce error. */
    class CoordinateFrame approxCoordinateFrame() const;

    // Special values.
    // Intentionally not inlined: see Matrix3::identity() for details.
    static const Matrix4& identity();
    static const Matrix4& zero();

    inline float* operator[](int r) {
        debugAssert(r >= 0);
        debugAssert(r < 4);
        return (float*)&elt[r];
    }

    inline const float* operator[](int r) const {
        debugAssert(r >= 0);
        debugAssert(r < 4);
        return (const float*)&elt[r];
    } 

    inline operator float* () {
        return (float*)&elt[0][0];
    }

    inline operator const float* () const {
        return (const float*)&elt[0][0];
    }

    Matrix4 operator*(const Matrix4& other) const;

    class Matrix3 upper3x3() const;

    /** Homogeneous multiplication. Let k = M * [v w]^T.  result = k.xyz() / k.w */
    class Vector3 homoMul(const class Vector3& v, float w) const;

    /**
     Constructs an orthogonal projection matrix from the given parameters.
     Near and far are the <b>NEGATIVE</b> of the near and far plane Z values
     (to follow OpenGL conventions).
     */
    static Matrix4 orthogonalProjection(
        float            left,
        float            right,
        float            bottom,
        float            top,
        float            nearval,
        float            farval);

    static Matrix4 orthogonalProjection(
        const class Rect2D& rect,
        float            nearval,
        float            farval);

    static Matrix4 perspectiveProjection(
        float            left,
        float            right,
        float            bottom,
        float            top,
        float            nearval,
        float            farval);

    void setRow(int r, const class Vector4& v);
    void setColumn(int c, const Vector4& v);

    /** @deprecated */
    Vector4 getRow(int r) const;
    /** @deprecated */
    Vector4 getColumn(int c) const;

    const Vector4& row(int r) const;
    Vector4 column(int c) const;

    Matrix4 operator*(const float s) const;
    Vector4 operator*(const Vector4& vector) const;

    Matrix4 transpose() const;

    bool operator!=(const Matrix4& other) const;
    bool operator==(const Matrix4& other) const;

    float determinant() const;
    Matrix4 inverse() const;

    /** 
     Transpose of the cofactor matrix (used in computing the inverse).
     Note: This is in fact only one type of adjoint. More generally,
     an adjoint of a matrix is any mapping of a matrix which possesses 
     certain properties.  This returns the so-called adjugate
     or classical adjoint.
    */
    Matrix4 adjoint() const;
    Matrix4 cofactor() const;

    /** Serializes row-major */
    void serialize(class BinaryOutput& b) const;
    void deserialize(class BinaryInput& b);

    std::string toString() const;

    /** 3D scale matrix */
    inline static Matrix4 scale(const Vector3& v) {
        return Matrix4(v.x, 0, 0, 0,
                       0, v.y, 0, 0,
                       0, 0, v.z, 0,
                       0, 0, 0, 1);
    }
    
    /** 3D scale matrix */
    inline static Matrix4 scale(float x, float y, float z) {
        return scale(Vector3(x, y, z));
    }

    /** 3D scale matrix */
    inline static Matrix4 scale(float s) {
        return scale(s,s,s);
    }

    /** 3D translation matrix */
    inline static Matrix4 translation(const Vector3& v) {
        return Matrix4(Matrix3::identity(), v);
    }
};



} // namespace

#ifdef _MSC_VER
#   pragma warning (pop)
#endif

#endif
