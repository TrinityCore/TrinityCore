/**
  @file Matrix4.cpp
 
 
  @maintainer Morgan McGuire, http://graphics.cs.williams.edu

  @created 2003-10-02
  @edited  2010-01-29
 */

#include "G3D/platform.h"
#include "G3D/Matrix4.h"
#include "G3D/Matrix3.h"
#include "G3D/Vector4.h"
#include "G3D/Vector3.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/CoordinateFrame.h"
#include "G3D/Rect2D.h"
#include "G3D/Any.h"
#include "G3D/stringutils.h"

namespace G3D {

    
Matrix4::Matrix4(const Any& any) {
    any.verifyName("Matrix4");
    any.verifyType(Any::ARRAY);

    const std::string& name = toLower(any.name());
    if (name == "matrix4") {
        any.verifySize(16);

        for (int r = 0; r < 4; ++r) {
            for (int c = 0; c < 4; ++c) {
                elt[r][c] = any[r * 4 + c];
            }
        }
    } else if (name == "matrix4::scale") {
        if (any.size() == 1) {
            *this = scale(any[0].number());
        } else if (any.size() == 3) {
            *this = scale(any[0], any[1], any[2]);
        } else {
            any.verify(false, "Matrix4::scale() takes either 1 or 3 arguments");
        }
    } else if (name == "matrix4::translation") {
        if (any.size() == 3) {
            *this = translation(any[0], any[1], any[2]);
        } else {
            any.verify(false, "Matrix4::translation() takes either 1 or 3 arguments");
        }    } else {
        any.verify(false, "Expected Matrix4 constructor");
    }
}


Matrix4::operator Any() const {
    Any any(Any::ARRAY, "Matrix4");
    any.resize(16);
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            any[r * 4 + c] = elt[r][c];
        }
    }

    return any;
}

const Matrix4& Matrix4::identity() {
    static Matrix4 m(
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1);
    return m;
}


const Matrix4& Matrix4::zero() {
    static Matrix4 m(
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0);
    return m;
}


Matrix4::Matrix4(const class CoordinateFrame& cframe) {
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            elt[r][c] = cframe.rotation[r][c];
        }
        elt[r][3] = cframe.translation[r];
    }
    elt[3][0] = 0.0f;
    elt[3][1] = 0.0f;
    elt[3][2] = 0.0f;
    elt[3][3] = 1.0f;
}

Matrix4::Matrix4(const Matrix3& upper3x3, const Vector3& lastCol) {
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            elt[r][c] = upper3x3[r][c];
        }
        elt[r][3] = lastCol[r];
    }
    elt[3][0] = 0.0f;
    elt[3][1] = 0.0f;
    elt[3][2] = 0.0f;
    elt[3][3] = 1.0f;
}


Matrix3 Matrix4::upper3x3() const {
    return Matrix3(elt[0][0], elt[0][1], elt[0][2],
                   elt[1][0], elt[1][1], elt[1][2],
                   elt[2][0], elt[2][1], elt[2][2]);
}


Matrix4 Matrix4::orthogonalProjection(
    const class Rect2D& rect,
    float            nearval,
    float            farval,
    float            upDirection) {
    return Matrix4::orthogonalProjection(rect.x0(), rect.x1(), rect.y1(), rect.y0(), nearval, farval, upDirection);
}


Matrix4 Matrix4::orthogonalProjection(
    float            left,
    float            right,
    float            bottom,
    float            top,
    float            nearval,
    float            farval,
    float            upDirection) {

    // Adapted from Mesa.  Note that Microsoft (http://msdn.microsoft.com/library/default.asp?url=/library/en-us/opengl/glfunc03_8qnj.asp) 
    // and Linux (http://www.xfree86.org/current/glOrtho.3.html) have different matrices shown in their documentation.

    float x, y, z;
    float tx,  ty, tz;

    x = 2.0f / (right-left);
    y = 2.0f / (top-bottom);
    z = -2.0f / (farval-nearval);
    tx = -(right+left) / (right-left);
    ty = -(top+bottom) / (top-bottom);
    tz = -(farval+nearval) / (farval-nearval);

    y  *= upDirection;
    ty *= upDirection;

    return 
        Matrix4( x , 0.0f, 0.0f,  tx,
                0.0f,  y , 0.0f,  ty,
                0.0f, 0.0f,  z ,  tz,
                0.0f, 0.0f, 0.0f, 1.0f);
}


Matrix4 Matrix4::perspectiveProjection(
    float left,    
    float right,
    float bottom,  
    float top,
    float nearval, 
    float farval,
    float upDirection) {

    float x, y, a, b, c, d;

    x = (2.0f*nearval) / (right-left);
    y = (2.0f*nearval) / (top-bottom);
    a = (right+left) / (right-left);
    b = (top+bottom) / (top-bottom);

    if (farval >= finf()) {
       // Infinite view frustum
       c = -1.0f;
       d = -2.0f * nearval;
    } else {
       c = -(farval+nearval) / (farval-nearval);
       d = -(2.0f*farval*nearval) / (farval-nearval);
    }

    debugAssertM(abs(upDirection) == 1.0f, "upDirection must be -1 or +1");
    y *= upDirection;
    b *= upDirection;

    return Matrix4(
        x,  0,  a,  0,
        0,  y,  b,  0,
        0,  0,  c,  d,
        0,  0, -1,  0);
}


void Matrix4::getPerspectiveProjectionParameters(
    float& left,    
    float& right,
    float& bottom,  
    float& top,
    float& nearval, 
    float& farval,
    float upDirection) const {

    debugAssertM(abs(upDirection) == 1.0f, "upDirection must be -1 or +1");

    float x = elt[0][0];
    float y = elt[1][1] * upDirection;
    float a = elt[0][2];
    float b = elt[1][2] * upDirection;
    float c = elt[2][2];
    float d = elt[2][3];

    // Verify that this really is a projection matrix
    debugAssertM(elt[3][2] == -1, "Not a projection matrix");
    debugAssertM(elt[0][1] == 0, "Not a projection matrix");
    debugAssertM(elt[0][3] == 0, "Not a projection matrix");
    debugAssertM(elt[1][3] == 0, "Not a projection matrix");
    debugAssertM(elt[3][3] == 0, "Not a projection matrix");
    debugAssertM(elt[1][0] == 0, "Not a projection matrix");
    debugAssertM(elt[2][0] == 0, "Not a projection matrix");
    debugAssertM(elt[2][1] == 0, "Not a projection matrix");
    debugAssertM(elt[3][0] == 0, "Not a projection matrix");
    debugAssertM(elt[3][1] == 0, "Not a projection matrix");

    if (c == -1) {
        farval = finf();
        nearval = -d / 2.0f;
    } else {
        nearval = d * ((c - 1.0f) / (c + 1.0f) - 1.0f) / (-2.0f * (c - 1.0f) / (c + 1.0f));
        farval = nearval * ((c - 1.0f) / (c + 1.0f));
    }


    left = (a - 1.0f) * nearval / x;
    right = 2.0f * nearval / x + left;

    bottom = (b - 1.0f) * nearval / y;
    top = 2.0f * nearval / y + bottom;
}


Matrix4::Matrix4(
    float r1c1, float r1c2, float r1c3, float r1c4,
    float r2c1, float r2c2, float r2c3, float r2c4,
    float r3c1, float r3c2, float r3c3, float r3c4,
    float r4c1, float r4c2, float r4c3, float r4c4) {
    elt[0][0] = r1c1;  elt[0][1] = r1c2;  elt[0][2] = r1c3;  elt[0][3] = r1c4;
    elt[1][0] = r2c1;  elt[1][1] = r2c2;  elt[1][2] = r2c3;  elt[1][3] = r2c4;
    elt[2][0] = r3c1;  elt[2][1] = r3c2;  elt[2][2] = r3c3;  elt[2][3] = r3c4;
    elt[3][0] = r4c1;  elt[3][1] = r4c2;  elt[3][2] = r4c3;  elt[3][3] = r4c4;
}

/**
 init should be <B>row major</B>.
 */
Matrix4::Matrix4(const float* init) {
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            elt[r][c] = init[r * 4 + c];
        }
    }
}


Matrix4::Matrix4(const double* init) {
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            elt[r][c] = (float)init[r * 4 + c];
        }
    }
}


Matrix4::Matrix4() {
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            elt[r][c] = 0;
        }
    }
}


void Matrix4::setRow(int r, const Vector4& v) {
    for (int c = 0; c < 4; ++c) {
        elt[r][c] = v[c];
    }
}


void Matrix4::setColumn(int c, const Vector4& v) {
    for (int r = 0; r < 4; ++r) {
        elt[r][c] = v[r];
    }
}


const Vector4& Matrix4::row(int r) const {
    return reinterpret_cast<const Vector4*>(elt[r])[0];
}


Vector4 Matrix4::column(int c) const {
    Vector4 v;
    for (int r = 0; r < 4; ++r) {
        v[r] = elt[r][c];
    }
    return v;
}


Matrix4 Matrix4::operator*(const Matrix4& other) const {
    Matrix4 result;
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            for (int i = 0; i < 4; ++i) {
                result.elt[r][c] += elt[r][i] * other.elt[i][c];
            }
        }
    }

    return result;
}


Matrix4 Matrix4::operator*(const float s) const {
    Matrix4 result;
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            result.elt[r][c] = elt[r][c] * s;
        }
    }

    return result;
}


Vector3 Matrix4::homoMul(const class Vector3& v, float w) const {
    Vector4 r = (*this) * Vector4(v, w);
    return r.xyz() * (1.0f / r.w);
}


Vector4 Matrix4::operator*(const Vector4& vector) const {
    Vector4 result(0,0,0,0);
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            result[r] += elt[r][c] * vector[c];
        }
    }

    return result;
}


Matrix4 Matrix4::transpose() const {
    Matrix4 result;
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            result.elt[c][r] = elt[r][c];
        }
    }

    return result;
}


bool Matrix4::operator!=(const Matrix4& other) const {
    return ! (*this == other);
}


bool Matrix4::operator==(const Matrix4& other) const {

    // If the bit patterns are identical, they must be
    // the same matrix.  If not, they *might* still have
    // equal elements due to floating point weirdness.
    if (memcmp(this, &other, sizeof(Matrix4)) == 0) {
        return true;
    } 

    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            if (elt[r][c] != other.elt[r][c]) {
                return false;
            }
        }
    }

    return true;
}


float Matrix4::determinant() const {
    // Determinant is the dot product of the first row and the first row
    // of cofactors (i.e. the first col of the adjoint matrix)
	return cofactor().row(0).dot(row(0));
}


Matrix4 Matrix4::adjoint() const {
    return cofactor().transpose();
}


Matrix4 Matrix4::inverse() const {
    // Inverse = adjoint / determinant

    Matrix4 A = adjoint();

    // Determinant is the dot product of the first row and the first row
    // of cofactors (i.e. the first col of the adjoint matrix)
	float det = A.column(0).dot(row(0));

	return A * (1.0f / det);
}


Matrix4 Matrix4::cofactor() const {
	Matrix4 out;

    // We'll use i to incrementally compute -1 ^ (r+c)
    int i = 1;

    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            // Compute the determinant of the 3x3 submatrix
            float det = subDeterminant(r, c);
            out.elt[r][c] = i * det;
            i = -i;
        }
        i = -i;
    }

    return out;
}


float Matrix4::subDeterminant(int excludeRow, int excludeCol) const {
    // Compute non-excluded row and column indices
    int row[3];
    int col[3];

    for (int i = 0; i < 3; ++i) {
        row[i] = i;
        col[i] = i;

        if (i >= excludeRow) {
            ++row[i];
        }
        if (i >= excludeCol) {
            ++col[i];
        }
    }

    // Compute the first row of cofactors 
    float cofactor00 = 
      elt[row[1]][col[1]] * elt[row[2]][col[2]] -
      elt[row[1]][col[2]] * elt[row[2]][col[1]];

    float cofactor10 = 
      elt[row[1]][col[2]] * elt[row[2]][col[0]] -
      elt[row[1]][col[0]] * elt[row[2]][col[2]];

    float cofactor20 = 
      elt[row[1]][col[0]] * elt[row[2]][col[1]] -
      elt[row[1]][col[1]] * elt[row[2]][col[0]];

    // Product of the first row and the cofactors along the first row
    return
      elt[row[0]][col[0]] * cofactor00 +
      elt[row[0]][col[1]] * cofactor10 +
      elt[row[0]][col[2]] * cofactor20;
}


CoordinateFrame Matrix4::approxCoordinateFrame() const {
	CoordinateFrame cframe;

	for (int r = 0; r < 3; ++r) {
		for (int c = 0; c < 3; ++c) {
			cframe.rotation[r][c] = elt[r][c];
		}
		cframe.translation[r] = elt[r][3];
	}

	// Ensure that the rotation matrix is orthonormal
	cframe.rotation.orthonormalize();

	return cframe;
}


void Matrix4::serialize(class BinaryOutput& b) const {
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            b.writeFloat32(elt[r][c]);
        }
    }
}


void Matrix4::deserialize(class BinaryInput& b) {
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            elt[r][c] = b.readFloat32();
        }
    }
}

std::string Matrix4::toString() const {
    return G3D::format("[%g, %g, %g, %g; %g, %g, %g, %g; %g, %g, %g, %g; %g, %g, %g, %g]", 
			elt[0][0], elt[0][1], elt[0][2], elt[0][3],
			elt[1][0], elt[1][1], elt[1][2], elt[1][3],
			elt[2][0], elt[2][1], elt[2][2], elt[2][3],
			elt[3][0], elt[3][1], elt[3][2], elt[3][3]);
}

} // namespace


