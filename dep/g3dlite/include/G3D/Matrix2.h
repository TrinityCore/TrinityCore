#ifndef G3D_Matrix2_h
#define G3D_Matrix2_h

#include "G3D/platform.h"
#include "G3D/Vector2.h"

namespace G3D {

/** @beta */
class Matrix2 {
private:
    // Row, column
    float          data[2][2];

public:

    Matrix2() {
        data[0][0] = 1.0f; data[0][1] = 0.0f;
        data[1][0] = 0.0f; data[1][1] = 1.0f;
    }

    Matrix2(float v00, float v01, float v10, float v11) {
        data[0][0] = v00; data[0][1] = v01;
        data[1][0] = v10; data[1][1] = v11;
    }

    static Matrix2 identity() {
        return Matrix2(1.0f, 0.0f, 0.0f, 1.0f);
    }

    Vector2 operator*(const Vector2& v) const {
        return Vector2(data[0][0] * v[0] + data[0][1] * v[1],
                       data[1][0] * v[0] + data[1][1] * v[1]);
    }
    
    Matrix2 inverse() const {
        return Matrix2(data[1][1], -data[0][1],
                       -data[1][0], data[0][0]) * (1.0f / determinant());
    }

    Matrix2 transpose() const {
        return Matrix2(data[0][0], data[1][0],
                       data[0][1], data[1][1]);
    }

    float determinant() const {
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    }

    Matrix2 operator*(float f) const {
        return Matrix2(data[0][0] * f, data[0][1] * f,
                       data[1][0] * f, data[1][1] * f);
    }

    Matrix2 operator/(float f) const {
        return Matrix2(data[0][0] / f, data[0][1] / f,
                       data[1][0] / f, data[1][1] / f);
    }

    inline float* operator[] (int i) {
        debugAssert(i >= 0 && i <= 1);
        return (float*)&data[i][0];
    }

    inline const float* operator[] (int i) const {
        debugAssert(i >= 0 && i <= 1);
        return (const float*)&data[i][0];
    }

    inline operator float* () {
        return (float*)&data[0][0];
    }

    inline operator const float* () const{
        return (const float*)&data[0][0];
    }

};

}

#endif
