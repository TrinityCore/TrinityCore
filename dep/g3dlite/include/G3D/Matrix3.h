/**
  \file Matrix3.h
 
  3x3 matrix class
 
  \maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
  \cite Portions based on Dave Eberly's Magic Software Library at <A HREF="http://www.magic-software.com">http://www.magic-software.com</A>
 
  \created 2001-06-02
  \edited  2011-05-05
 */

#ifndef G3D_Matrix3_h
#define G3D_Matrix3_h

#include "G3D/platform.h"
#include "G3D/Vector3.h"
#include "G3D/Vector4.h"
#include "G3D/debugAssert.h"

#include <cstring>

namespace G3D {

#ifdef _MSC_VER
// Turn off "conditional expression is constant" warning; MSVC generates this
// for debug assertions in inlined methods.
#   pragma warning (disable : 4127)
#endif

class Any;

/**
  A 3x3 matrix.  Do not subclass.  Data is unitializd when default constructed.
 */
class Matrix3 {
private:

    // Row, column
    float elt[3][3];

    // Hidden operators
    bool operator<(const Matrix3&) const;
    bool operator>(const Matrix3&) const;
    bool operator<=(const Matrix3&) const;
    bool operator>=(const Matrix3&) const;

public:

    /** Must be in one of the following forms:
        - Matrix3(#, #, # .... #)
        - Matrix3::fromAxisAngle(#, #)
        - Matrix3::diagonal(#, #, #)
        - Matrix3::identity()
    */
    Matrix3(const Any& any);

    static Matrix3 fromColumns(const Vector3& c0, const Vector3& c1, const Vector3& c2) {
        Matrix3 m;
        for (int r = 0; r < 3; ++r) {
            m.elt[r][0] = c0[r];
            m.elt[r][1] = c1[r];
            m.elt[r][2] = c2[r];
        }
        return m;
    }

    static Matrix3 fromRows(const Vector3& r0, const Vector3& r1, const Vector3& r2) {
        Matrix3 m;
        for (int c = 0; c < 3; ++c) {
            m.elt[0][c] = r0[c];
            m.elt[1][c] = r1[c];
            m.elt[2][c] = r2[c];
        }
        return m;
    }

    Any toAny() const;

    /** Initial values are undefined for performance. 
        \sa Matrix3::zero, Matrix3::identity, Matrix3::fromAxisAngle, etc.*/
    Matrix3() {}

    Matrix3 (class BinaryInput& b);
    Matrix3 (const float aafEntry[3][3]);
    Matrix3 (const Matrix3& rkMatrix);
    Matrix3 (float fEntry00, float fEntry01, float fEntry02,
             float fEntry10, float fEntry11, float fEntry12,
             float fEntry20, float fEntry21, float fEntry22);

    bool fuzzyEq(const Matrix3& b) const;

    /** Constructs a matrix from a quaternion.
        @cite Graphics Gems II, p. 351--354
         @cite Implementation from Watt and Watt, pg 362*/
    Matrix3(const class Quat& q);

    static Matrix3 diagonal(float e00, float e11, float e22) {
        return Matrix3(e00, 0, 0, 
                       0, e11, 0,
                       0, 0, e22);
    }

    void serialize(class BinaryOutput& b) const;
    void deserialize(class BinaryInput& b);

    /** Returns true if column(0).cross(column(1)).dot(column(2)) > 0. */
    bool isRightHanded() const;

    /**
     Sets all elements.
     */
    void set(float fEntry00, float fEntry01, float fEntry02,
             float fEntry10, float fEntry11, float fEntry12,
             float fEntry20, float fEntry21, float fEntry22);

    /**
     Member access, allows use of construct mat[r][c]
     */
    inline float* operator[] (int iRow) {
        debugAssert(iRow >= 0);
        debugAssert(iRow < 3);
        return (float*)&elt[iRow][0];
    }

    inline const float* operator[] (int iRow) const {
        debugAssert(iRow >= 0);
        debugAssert(iRow < 3);
        return (const float*)&elt[iRow][0];
    }

    inline operator float* () {
        return (float*)&elt[0][0];
    }

    inline operator const float* () const{
        return (const float*)&elt[0][0];
    }
    
    Vector3 column(int c) const;
    const Vector3& row(int r) const;

    void setColumn(int iCol, const Vector3 &vector);
    void setRow(int iRow, const Vector3 &vector);

    // assignment and comparison
    inline Matrix3& operator= (const Matrix3& rkMatrix) {
        memcpy(elt, rkMatrix.elt, 9 * sizeof(float));
        return *this;
    }

    bool operator== (const Matrix3& rkMatrix) const;
    bool operator!= (const Matrix3& rkMatrix) const;

    // arithmetic operations
    Matrix3 operator+ (const Matrix3& rkMatrix) const;
    Matrix3 operator- (const Matrix3& rkMatrix) const;
    /** Matrix-matrix multiply */
    Matrix3 operator* (const Matrix3& rkMatrix) const;
    Matrix3 operator- () const;

    Matrix3& operator+= (const Matrix3& rkMatrix);
    Matrix3& operator-= (const Matrix3& rkMatrix);
    Matrix3& operator*= (const Matrix3& rkMatrix);

    /**
     * matrix * vector [3x3 * 3x1 = 3x1]
     */
    inline Vector3 operator* (const Vector3& v) const {
        Vector3 kProd;

        for (int r = 0; r < 3; ++r) {
            kProd[r] =
                elt[r][0] * v[0] +
                elt[r][1] * v[1] +
                elt[r][2] * v[2];
        }

        return kProd;
    }


    /**
     * vector * matrix [1x3 * 3x3 = 1x3]
     */
    friend Vector3 operator* (const Vector3& rkVector,
                              const Matrix3& rkMatrix);

    /**
     * matrix * scalar
     */
    Matrix3 operator* (float fScalar) const;

    /** scalar * matrix */
    friend Matrix3 operator* (double fScalar, const Matrix3& rkMatrix);
    friend Matrix3 operator* (float fScalar, const Matrix3& rkMatrix);
    friend Matrix3 operator* (int fScalar, const Matrix3& rkMatrix);

    Matrix3& operator*= (float k);
    Matrix3& operator/= (float k);


private:
    /** Multiplication where out != A and out != B */
    static void _mul(const Matrix3& A, const Matrix3& B, Matrix3& out);
public:

    /** Optimized implementation of out = A * B.  It is safe (but slow) to call 
        with A, B, and out possibly pointer equal to one another.*/
    // This is a static method so that it is not ambiguous whether "this"
    // is an input or output argument.
    inline static void mul(const Matrix3& A, const Matrix3& B, Matrix3& out) {
        if ((&out == &A) || (&out == &B)) {
            // We need a temporary anyway, so revert to the stack method.
            out = A * B;
        } else {
            // Optimized in-place multiplication.
            _mul(A, B, out);
        }
    }

private:
    static void _transpose(const Matrix3& A, Matrix3& out);
public:

    /** Optimized implementation of out = A.transpose().  It is safe (but slow) to call 
        with A and out possibly pointer equal to one another.
    
        Note that <CODE>A.transpose() * v</CODE> can be computed 
        more efficiently as <CODE>v * A</CODE>.
    */
    inline static void transpose(const Matrix3& A, Matrix3& out) {
        if (&A == &out) {
            out = A.transpose();
        } else {
            _transpose(A, out);
        }
    }

    /** Returns true if the rows and column L2 norms are 1.0 and the rows are orthogonal. */
    bool isOrthonormal() const;

    Matrix3 transpose () const;
    bool inverse (Matrix3& rkInverse, float fTolerance = 1e-06f) const;
    Matrix3 inverse (float fTolerance = 1e-06f) const;
    float determinant () const;

    /** singular value decomposition */
    void singularValueDecomposition (Matrix3& rkL, Vector3& rkS,
                                     Matrix3& rkR) const;
    /** singular value decomposition */
    void singularValueComposition (const Matrix3& rkL,
                                   const Vector3& rkS, const Matrix3& rkR);

    /** Gram-Schmidt orthonormalization (applied to columns of rotation matrix) */
    void orthonormalize();

    /** orthogonal Q, diagonal D, upper triangular U stored as (u01,u02,u12) */
    void qDUDecomposition (Matrix3& rkQ, Vector3& rkD,
                           Vector3& rkU) const;

    /**
       Polar decomposition of a matrix. Based on pseudocode from Nicholas J
       Higham, "Computing the Polar Decomposition -- with Applications Siam
       Journal of Science and Statistical Computing, Vol 7, No. 4, October
       1986.

       Decomposes A into R*S, where R is orthogonal and S is symmetric.

       Ken Shoemake's "Matrix animation and polar decomposition"
       in Proceedings of the conference on Graphics interface '92
       seems to be better known in the world of graphics, but Higham's version
       uses a scaling constant that can lead to faster convergence than
       Shoemake's when the initial matrix is far from orthogonal.
    */
    void polarDecomposition(Matrix3 &R, Matrix3 &S) const;

    /** 
     *  Matrix norms.
     */
    float spectralNorm () const;

    float squaredFrobeniusNorm() const;

    float frobeniusNorm() const;

    float l1Norm() const;

    float lInfNorm() const;

    float diffOneNorm(const Matrix3 &y) const;

    /** matrix must be orthonormal */
    void toAxisAngle(Vector3& rkAxis, float& rfRadians) const;

    static Matrix3 fromDiagonal(const Vector3& d) {
        return Matrix3(d.x, 0, 0, 
                       0, d.y, 0,
                       0, 0, d.z);
    }

    /** \sa fromUnitAxisAngle */
    static Matrix3 fromAxisAngle(const Vector3& rkAxis, float fRadians);

    /** Assumes that rkAxis has unit length */
    static Matrix3 fromUnitAxisAngle(const Vector3& rkAxis, float fRadians);

    /**
     * The matrix must be orthonormal.  The decomposition is yaw*pitch*roll
     * where yaw is rotation about the Up vector, pitch is rotation about the
     * right axis, and roll is rotation about the Direction axis.
     */
    bool toEulerAnglesXYZ (float& rfYAngle, float& rfPAngle,
                           float& rfRAngle) const;
    bool toEulerAnglesXZY (float& rfYAngle, float& rfPAngle,
                           float& rfRAngle) const;
    bool toEulerAnglesYXZ (float& rfYAngle, float& rfPAngle,
                           float& rfRAngle) const;
    bool toEulerAnglesYZX (float& rfYAngle, float& rfPAngle,
                           float& rfRAngle) const;
    bool toEulerAnglesZXY (float& rfYAngle, float& rfPAngle,
                           float& rfRAngle) const;
    bool toEulerAnglesZYX (float& rfYAngle, float& rfPAngle,
                           float& rfRAngle) const;
    static Matrix3 fromEulerAnglesXYZ (float fYAngle, float fPAngle, float fRAngle);
    static Matrix3 fromEulerAnglesXZY (float fYAngle, float fPAngle, float fRAngle);
    static Matrix3 fromEulerAnglesYXZ (float fYAngle, float fPAngle, float fRAngle);
    static Matrix3 fromEulerAnglesYZX (float fYAngle, float fPAngle, float fRAngle);
    static Matrix3 fromEulerAnglesZXY (float fYAngle, float fPAngle, float fRAngle);
    static Matrix3 fromEulerAnglesZYX (float fYAngle, float fPAngle, float fRAngle);

    /** eigensolver, matrix must be symmetric */
    void eigenSolveSymmetric (float afEigenvalue[3],
                              Vector3 akEigenvector[3]) const;

    static void tensorProduct (const Vector3& rkU, const Vector3& rkV,
                               Matrix3& rkProduct);
    std::string toString() const;

    static const float EPSILON; 

    // Special values.
    // The unguaranteed order of initialization of static variables across 
    // translation units can be a source of annoying bugs, so now the static
    // special values (like Vector3::ZERO, Color3::WHITE, ...) are wrapped
    // inside static functions that return references to them. 
    // These functions are intentionally not inlined, because: 
    // "You might be tempted to write [...] them as inline functions 
    // inside their respective header files, but this is something you 
    // must definitely not do. An inline function can be duplicated 
    // in every file in which it appears and this duplication 
    // includes the static object definition. Because inline functions 
    // automatically default to internal linkage, this would result in 
    // having multiple static objects across the various translation 
    // units, which would certainly cause problems. So you must 
    // ensure that there is only one definition of each wrapping 
    // function, and this means not making the wrapping functions inline",
    // according to Chapter 10 of "Thinking in C++, 2nd ed. Volume 1" by Bruce Eckel, 
    // http://www.mindview.net/
    static const Matrix3& zero();
    static const Matrix3& identity(); 

protected:

    // support for eigensolver
    void tridiagonal (float afDiag[3], float afSubDiag[3]);
    bool qLAlgorithm (float afDiag[3], float afSubDiag[3]);

    // support for singular value decomposition
    static const float ms_fSvdEpsilon;
    static const int ms_iSvdMaxIterations;
    static void bidiagonalize (Matrix3& kA, Matrix3& kL,
                               Matrix3& kR);
    static void golubKahanStep (Matrix3& kA, Matrix3& kL,
                                Matrix3& kR);

    // support for spectral norm
    static float maxCubicRoot (float afCoeff[3]);

};


//----------------------------------------------------------------------------
/**  <code>v * M == M.transpose() * v</code> */
inline Vector3 operator* (const Vector3& rkPoint, const Matrix3& rkMatrix) {
    Vector3 kProd;

    for (int r = 0; r < 3; ++r) {
        kProd[r] =
            rkPoint[0] * rkMatrix.elt[0][r] +
            rkPoint[1] * rkMatrix.elt[1][r] +
            rkPoint[2] * rkMatrix.elt[2][r];
    }

    return kProd;
}


} // namespace

#endif

